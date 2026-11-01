-- ua: promoted from rules/uacantrips5.h (the The UA MAGIC-USER CANTRIP);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 416,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA MAGIC-USER CANTRIP",
      "provenance" = "DESCRIPTIONS, part 5 (R416): the PERSONAL category (pp. 49-50), 10 cantrips. The R363/R412/R413/R414/R415 precedents ride: the descriptions pin; the casting-time fraction cells garble in the scan (the whole family) and record as holes pending the PDF read - never guesses.  The school tags print clean: Summoning and Conjuration are NEW school codes this round, pinned AS PRINTED. The census: Summoning 5 (Bee, Bug, Gnats, Mouse, Spider), Conjuration 3 (Bluelight, Tweak, Unlock), Alteration 1 (Firefinger), Evocation 1 (Smokepuff). The scan prints \"Flrefinger\" for the roster's Firefinger - the name resolves via the LIVE R341/R401 roster cross-check (the roster is the independent confirmation).  The area lines: EIGHT print clean - the one-summoned- animal four (Bee, Bug, Mouse, Spider - a NEW area kind), the Gnats 1 cubic foot, the Smokepuff 1-foot cloud (a NEW area kind), the Tweak one creature (the R415 kind), the Unlock one lock (a NEW area kind) - and TWO garble their numbers (the Bluelight sphere diameter and the Firefinger line length): the two record as area holes pending the PDF read.  The range family: the seven ranged blocks (Bee, Bug, Gnats, Mouse, Smokepuff, Spider, Tweak) print the numeral 1 clean but the foot/inch glyphs garble - the numeral pins, the unit family records as holes pending the PDF read.  The mechanics pin clean: the Bee 90% sting, the Bluelight 3-inch sphere + 5-foot illumination, the Firefinger one-half-foot jet + 1 segment persistence, the Gnats 1-4 segment distraction, the Smokepuff six colors, the SPIDER POISON READ (the 5% the 1-2 inch size, the 1-segment bite distraction, the +4 venom save, the 1/2 damage pair, the 1-4 day sickness; the slow-poison defer prints a garbled numeral and records as a hole), the Tweak seven portions + 1-segment distraction + the INT 7 threshold + the 3d6 read.",
    },
  "consts" = { {
      "name" = "ucoPersonalCount",
      "value" = 10,
      "comment" = "The count.",
    }, {
      "name" = "ucoRangeVal",
      "value" = 1,
      "comment" = "The range numeral (the seven ranged blocks all print 1).",
    }, {
      "name" = "ucoBeeStingPct",
      "value" = 90,
      "comment" = "---- the mechanics pins ---- The Bee read: the bee is 90% likely to sting any living creature it finds itself upon.",
    }, {
      "name" = "ucoBluelightSphereInches",
      "value" = 3,
      "comment" = "The Bluelight read: the 3-inch sphere of glowing blue radiance illuminates an area of 5 feet around itself (and casts no reflections beyond that radius; infravision and ultravision unaffected).",
    }, {
      "name" = "ucoBluelightRadiusFeet",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "ucoFirefingerJetInches",
      "value" = 6,
      "comment" = "The Firefinger read: a jet of flame up to one-half foot in length (6 inches) that persists for up to 1 segment.",
    }, {
      "name" = "ucoFirefingerSegments",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "ucoGnatsDistractMinSegments",
      "value" = 1,
      "comment" = "The Gnats read: on a failed save versus poison the cloud distracts for from 1 to 4 segments.",
    }, {
      "name" = "ucoGnatsDistractMaxSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "ucoSmokepuffColors",
      "value" = 6,
      "comment" = "The Smokepuff read: the puff can be white, gray, black, brown, yellow, or green - six colors.",
    }, {
      "name" = "ucoSpiderPoisonPct",
      "value" = 5,
      "comment" = "---- the spider poison read ---- The venom chance: a 5% chance the summoned spider is one with powerful poison (black widow, brown recluse, etc.).",
    }, {
      "name" = "ucoSpiderSizeMaxInches",
      "value" = 2,
      "comment" = "The size: a common garden spider or the like, no larger than an inch or two in diameter.",
    }, {
      "name" = "ucoSpiderBiteDistractSegments",
      "value" = 1,
      "comment" = "The normal bite: a momentary distraction of 1 segment.",
    }, {
      "name" = "ucoSpiderPoisonSaveBonus",
      "value" = 4,
      "comment" = "The venom save: versus poison at +4.",
    }, {
      "name" = "ucoSpiderHitLight",
      "value" = 1,
      "comment" = "The damage pair: success on the save inflicts 1 point, failure 2 points.",
    }, {
      "name" = "ucoSpiderHitHeavy",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "ucoSpiderSickMinDays",
      "value" = 1,
      "comment" = "The sickness: on the failed venom save the victim cannot act normally for from 1 to 4 days unless neutralize poison removes the toxin.",
    }, {
      "name" = "ucoSpiderSickMaxDays",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "ucoSlowPoisonDeferDays",
      "value" = 1,
      "comment" = "The slow poison defer: the PDF read resolves the garble (R419) - a slow poison defers the sickness for 1 day.",
    }, {
      "name" = "ucoTweakPortions",
      "value" = 7,
      "comment" = "---- the tweak read ---- The portions: cheek, nose, ear, beard, moustache, whiskers, or tail - seven.",
    }, {
      "name" = "ucoTweakDistractSegments",
      "value" = 1,
      "comment" = "The distraction: a 1-segment distraction on the failed save/roll.",
    }, {
      "name" = "ucoTweakIntThreshold",
      "value" = 7,
      "comment" = "The INT threshold: creatures with intelligence under 7 save versus spell; creatures with intelligence of 7 or greater must roll greater than intelligence on 3d6.",
    }, {
      "name" = "ucoTweakDice",
      "value" = 3,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "ucoRangeUnitIsInch",
      "value" = true,
      "comment" = "The range units: the PDF read resolves the glyphs (R419) - the seven ranged blocks print the AD&D 1\" notation (one inch of range, the ten-foot indoor scale). The unit pins as inch; the numeral 1 rides the standing ucoRangeVal() pin.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "ucoPersonal",
      "comment" = "The 10 personal cantrips, in the R341/R401 roster order.",
      "kind" = "header pin",
      "body" = "static const UcoCantrip T[10] = { { \"Bee\", 6, 10, 0 }, { \"Bluelight\", 7, UCO_AREA_SPHERE, 3 }, { \"Bug\", 6, 10, 0 }, { \"Firefinger\", 2, UCO_AREA_LINE, 6 }, { \"Gnats\", 6, 1, 1 }, { \"Mouse\", 6, 10, 0 }, { \"Smokepuff\", 0, 11, 1 }, { \"Spider\", 6, 10, 0 }, { \"Tweak\", 7, 9, 0 }, { \"Unlock\", 7, 12, 0 }, }; if (i < 0) i = 0; if (i > 9) i = 9; return T[i];",
    }, {
      "name" = "ucoSchoolCount",
      "comment" = "The school census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 10; ++i) if (ucoPersonal(i).school == s) ++n; return n;",
    }, {
      "name" = "ucoAreaKindCount",
      "comment" = "The area kind census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 10; ++i) if (ucoPersonal(i).areaKind == a) ++n; return n;",
    }, {
      "name" = "ucoCastTimeDen",
      "comment" = "The casting times: the PDF read resolves the whole family (R419) - the real UA PDF prints every cell clean, a unit fraction, one segment over the denominator. The denominators, in roster order: order: Bee, Bluelight, Bug, Gnats, Mouse, Spider and Unlock at 1/2, Firefinger, Smokepuff and Tweak at 1/3.",
      "kind" = "header pin",
      "body" = "static const int D[10] = { 2, 2, 2, 3, 2, 2, 3, 2, 3, 2 }; if (i < 0) i = 0; if (i > 9) i = 9; return D[i];",
    }, {
      "name" = "ucoCastTimeDenCount",
      "comment" = "The casting-time denominator census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 10; ++i) if (ucoCastTimeDen(i) == d) ++n; return n;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['ucoPersonalCount']() != 10  or m['uastCantripCount'](4) != 10",
      "note" = "---- the census ----",
    }, {
      "expr" = "m['ucoSchoolCount'](UCO_EVO) != 1  or m['ucoSchoolCount'](UCO_ABJ) != 0  or m['ucoSchoolCount'](UCO_ALT) != 1  or m['ucoSchoolCount'](UCO_ENCH) != 0  or m['ucoSchoolCount'](UCO_ILL) != 0  or m['ucoSchoolCount'](UCO_CHARM) != 0  or m['ucoSchoolCount'](UCO_SUMM) != 5  or m['ucoSchoolCount'](UCO_CONJ) != 3",
      "note" = "---- the school census ----",
    }, {
      "expr" = "m['ucoAreaKindCount'](UCO_AREA_BEAST) != 4  or m['ucoAreaKindCount'](UCO_AREA_CUBEFoot) != 1  or m['ucoAreaKindCount'](UCO_AREA_CLOUD) != 1  or m['ucoAreaKindCount'](UCO_AREA_CREATURE) != 1  or m['ucoAreaKindCount'](UCO_AREA_LOCK) != 1  or m['ucoAreaKindCount'](UCO_AREA_SPHERE) != 1  or m['ucoAreaKindCount'](UCO_AREA_LINE) != 1  or m['ucoAreaKindCount'](UCO_AREA_HOLE) != 0  or strcmp(m['ucoPersonal'](0).name,m['uastCantripName'](4, 0)) != 0  or m['ucoPersonal'](0) .school != 6  or m['ucoPersonal'](0) .areaKind != 10  or m['ucoPersonal'](0) .areaVal != 0  or strcmp(m['ucoPersonal'](1).name,m['uastCantripName'](4, 1)) != 0  or m['ucoPersonal'](1) .school != 7  or m['ucoPersonal'](1) .areaKind != UCO_AREA_SPHERE  or m['ucoPersonal'](1) .areaVal != 3  or strcmp(m['ucoPersonal'](2).name,m['uastCantripName'](4, 2)) != 0  or m['ucoPersonal'](2) .school != 6  or m['ucoPersonal'](2) .areaKind != 10  or m['ucoPersonal'](2) .areaVal != 0  or strcmp(m['ucoPersonal'](3).name,m['uastCantripName'](4, 3)) != 0  or m['ucoPersonal'](3) .school != 2  or m['ucoPersonal'](3) .areaKind != UCO_AREA_LINE  or m['ucoPersonal'](3) .areaVal != 6  or strcmp(m['ucoPersonal'](4).name,m['uastCantripName'](4, 4)) != 0  or m['ucoPersonal'](4) .school != 6  or m['ucoPersonal'](4) .areaKind != 1  or m['ucoPersonal'](4) .areaVal != 1  or strcmp(m['ucoPersonal'](5).name,m['uastCantripName'](4, 5)) != 0  or m['ucoPersonal'](5) .school != 6  or m['ucoPersonal'](5) .areaKind != 10  or m['ucoPersonal'](5) .areaVal != 0  or strcmp(m['ucoPersonal'](6).name,m['uastCantripName'](4, 6)) != 0  or m['ucoPersonal'](6) .school != 0  or m['ucoPersonal'](6) .areaKind != 11  or m['ucoPersonal'](6) .areaVal != 1  or strcmp(m['ucoPersonal'](7).name,m['uastCantripName'](4, 7)) != 0  or m['ucoPersonal'](7) .school != 6  or m['ucoPersonal'](7) .areaKind != 10  or m['ucoPersonal'](7) .areaVal != 0  or strcmp(m['ucoPersonal'](8).name,m['uastCantripName'](4, 8)) != 0  or m['ucoPersonal'](8) .school != 7  or m['ucoPersonal'](8) .areaKind != 9  or m['ucoPersonal'](8) .areaVal != 0  or strcmp(m['ucoPersonal'](9).name,m['uastCantripName'](4, 9)) != 0  or m['ucoPersonal'](9) .school != 7  or m['ucoPersonal'](9) .areaKind != 12  or m['ucoPersonal'](9) .areaVal != 0",
      "note" = "---- the area census ----",
    }, {
      "expr" = "m['ucoCastTimeDen'](0) != 2  or m['ucoCastTimeDen'](1) != 2  or m['ucoCastTimeDen'](2) != 2  or m['ucoCastTimeDen'](3) != 3  or m['ucoCastTimeDen'](4) != 2  or m['ucoCastTimeDen'](5) != 2  or m['ucoCastTimeDen'](6) != 3  or m['ucoCastTimeDen'](7) != 2  or m['ucoCastTimeDen'](8) != 3  or m['ucoCastTimeDen'](9) != 2",
      "note" = "---- the casting times ---- (the PDF read resolves the family - R419)",
    }, {
      "expr" = "m['ucoRangeUnitIsInch']() != 1  or m['ucoSlowPoisonDeferDays']() != 1",
      "note" = "---- the resolved reads (the PDF read - R419)",
    }, {
      "expr" = "m['ucoRangeVal']() != 1  or m['ucoBeeStingPct']() != 90  or m['ucoSmokepuffColors']() != 6  or m['ucoBluelightSphereInches']() != 3  or m['ucoBluelightRadiusFeet']() != 5  or m['ucoFirefingerJetInches']() != 6  or m['ucoFirefingerSegments']() != 1  or m['ucoGnatsDistractMinSegments']() != 1  or m['ucoGnatsDistractMaxSegments']() != 4  or m['ucoSpiderPoisonPct']() != 5  or m['ucoSpiderSizeMaxInches']() != 2  or m['ucoSpiderBiteDistractSegments']() != 1  or m['ucoSpiderPoisonSaveBonus']() != 4  or m['ucoSpiderHitLight']() != 1  or m['ucoSpiderHitHeavy']() != 2  or m['ucoSpiderSickMinDays']() != 1  or m['ucoSpiderSickMaxDays']() != 4  or m['ucoTweakPortions']() != 7  or m['ucoTweakDistractSegments']() != 1  or m['ucoTweakIntThreshold']() != 7  or m['ucoTweakDice']() != 3",
      "note" = "---- the mechanics ----",
    }, {
      "expr" = "m['ucoGnatsDistractMinSegments']() >=m['ucoGnatsDistractMaxSegments']()  or m['ucoFirefingerJetInches']() * 2 != 12  or m['ucoBluelightSphereInches']() >=m['ucoBluelightRadiusFeet']() * 12  or m['ucoSpiderHitLight']() >=m['ucoSpiderHitHeavy']()  or m['ucoSpiderSickMinDays']() >=m['ucoSpiderSickMaxDays']()",
      "note" = "The band derivations: the gnats distraction opens below its close, the firefinger jet is the one-half foot (twelve halves), the bluelight sphere fits its illumination radius, and the spider damage/sickness bands order themselves.",
    } },
  "audit" = {
      "label" = "R416: the UA personal cantrips pin audit",
      "comment" = "The 10 personal descriptions pin: the names cross-check the R341/R401 roster live (the scan's \"Flrefinger\" resolves as Firefinger via the roster - the independent confirmation), the schools pin per row (Summoning and Conjuration AS PRINTED, NEW codes), the areas pin per row (EIGHT clean - the one summoned animal four, the Gnats cubic foot, the Smokepuff cloud, the Tweak creature, the Unlock lock; the Bluelight sphere and the Firefinger line record as area holes), the censuses count, the mechanics pin with the band derivations cross-checking themselves; census 342 -> 343.",
    },
}
