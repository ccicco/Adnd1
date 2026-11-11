-- ua: promoted from rules/ua/uacantrips3.h (the The UA MAGIC-USER CANTRIP);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 414,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA MAGIC-USER CANTRIP",
      "provenance" = "DESCRIPTIONS, part 3 (R414): the LEGERDEMAIN category (pp. 48-49), 6 cantrips. The R363/R412/R413 precedents ride: the descriptions pin; the casting-time fraction cells garble in the scan (the whole family) and record as holes pending the PDF read - never guesses.  The school tags print clean: Alteration 3 (Change, Mute, Present), Enchantment 1 (Distract), Illusion 2 (Hide, Palm), Evocation 0, Abjuration 0 - Illusion a NEW school code this round.  The area lines print clean for ALL 6 blocks - ZERO area holes: the one-object three (Change, Hide, Mute), the Distract Special, the Palm/ Present one small item pair (a NEW area kind code).  The mechanics pin clean: the Change 50% size band with the base 1 turn, the radical 1 round and the slight 1+ day durations, the Distract 10-foot range + 1 segment duration, the Hide duration ladder (the base 1 turn at 2 cubic yards or less, minus 1 round per additional 2 cubic yards to the 1-round floor at 20, then minus 1 segment per 2 additional cubic yards from the 9 segments at 22 down to 1 segment at 38, over 38 momentary - the ladder cross-checks by derivation: 22 + 2*8 = 38 and 9 - 8 = 1), the Mute 1 round, the Palm 1 segment, the Present 2-foot radius + the dozen-coin capacity + the tankard exhaustion.",
    },
  "consts" = { {
      "name" = "uclLegerdemainCount",
      "value" = 6,
      "comment" = "The count.",
    }, {
      "name" = "uclChangeSizePctMax",
      "value" = 50,
      "comment" = "---- the mechanics pins ---- The Change size band: no more than a 50% increase or decrease in size/volume.",
    }, {
      "name" = "uclChangeBaseTurns",
      "value" = 1,
      "comment" = "The Change base duration: 1 turn.",
    }, {
      "name" = "uclChangeRadicalRounds",
      "value" = 1,
      "comment" = "The Change radical duration: a radical change lasts only 1 round.",
    }, {
      "name" = "uclChangeSlightDays",
      "value" = 1,
      "comment" = "The Change slight duration: a very slight alteration lasts 1 or more days.",
    }, {
      "name" = "uclDistractRangeFt",
      "value" = 10,
      "comment" = "The Distract range: the distraction must be within 10 feet of the caster.",
    }, {
      "name" = "uclDistractDurationSegments",
      "value" = 1,
      "comment" = "The Distract duration: only 1 segment.",
    }, {
      "name" = "uclHideBaseCubicYds",
      "value" = 2,
      "comment" = "The Hide ladder base: 1 turn on an object of 2 cubic yards or less in volume.",
    }, {
      "name" = "uclHideBaseTurns",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uclHideRoundCubicYds",
      "value" = 20,
      "comment" = "The Hide ladder round floor: reduced by 1 round per additional 2 cubic yards until, at 20 cubic yards, the duration is 1 round.",
    }, {
      "name" = "uclHideSegStartCubicYds",
      "value" = 22,
      "comment" = "The Hide ladder segment tail: over 20 cubic yards the duration drops 1 segment per 2 additional cubic yards - 9 segments at 22 cubic yards.",
    }, {
      "name" = "uclHideSegStartSegments",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uclHideSegStepCubicYds",
      "value" = 2,
      "comment" = "The Hide ladder segment step: 2 cubic yards per segment.",
    }, {
      "name" = "uclHideMinCubicYds",
      "value" = 38,
      "comment" = "The Hide ladder floor: 1 segment at 38 cubic yards; anything over 38 at best momentarily disappears.",
    }, {
      "name" = "uclHideMinSegments",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uclMuteDurationRounds",
      "value" = 1,
      "comment" = "The Mute duration: but 1 round.",
    }, {
      "name" = "uclPalmDurationSegments",
      "value" = 1,
      "comment" = "The Palm duration: the illusory duplicate lasts but 1 segment.",
    }, {
      "name" = "uclPresentRadiusFt",
      "value" = 2,
      "comment" = "The Present radius: within 2 feet of the caster.",
    }, {
      "name" = "uclPresentMaxCoins",
      "value" = 12,
      "comment" = "The Present capacity: as many as a dozen coins before the dweomer fails (a tankard exhausts it).",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = { {
      "name" = "uclLegerdemain",
      "comment" = "The 6 legerdemain cantrips, in the R341/R401 roster order.",
      "kind" = "header pin",
      "body" = "static const UclCantrip T[6] = { { \"Change\", 2, 0, 0 }, { \"Distract\", 3, 3, 0 }, { \"Hide\", 4, 0, 0 }, { \"Mute\", 2, 0, 0 }, { \"Palm\", 4, 7, 0 }, { \"Present\", 2, 7, 0 }, }; if (i < 0) i = 0; if (i > 5) i = 5; return T[i];",
    }, {
      "name" = "uclSchoolCount",
      "comment" = "The school census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 6; ++i) if (uclLegerdemain(i).school == s) ++n; return n;",
    }, {
      "name" = "uclAreaKindCount",
      "comment" = "The area kind census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 6; ++i) if (uclLegerdemain(i).areaKind == a) ++n; return n;",
    }, {
      "name" = "uclCastTimeDen",
      "comment" = "The casting times: the PDF read resolves the whole family (R418) - the real UA PDF prints every cell clean, a unit fraction, one segment over the denominator. The denominators, in roster order: Change, Hide, Mute and Palm at 1/10, Distract at 1/3, Present at 1/8.",
      "kind" = "header pin",
      "body" = "static const int D[6] = { 10, 3, 10, 10, 10, 8 }; if (i < 0) i = 0; if (i > 5) i = 5; return D[i];",
    }, {
      "name" = "uclCastTimeDenCount",
      "comment" = "The casting-time denominator census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 6; ++i) if (uclCastTimeDen(i) == d) ++n; return n;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uclLegerdemainCount']() != 6  or m['uastCantripCount'](2) != 6",
      "note" = "---- the census ----",
    }, {
      "expr" = "m['uclSchoolCount'](UCL_ALT) != 3  or m['uclSchoolCount'](UCL_ENCH) != 1  or m['uclSchoolCount'](UCL_ILL) != 2  or m['uclSchoolCount'](UCL_EVO) != 0  or m['uclSchoolCount'](UCL_ABJ) != 0",
      "note" = "---- the school census ----",
    }, {
      "expr" = "m['uclAreaKindCount'](UCL_AREA_OBJECT) != 3  or m['uclAreaKindCount'](UCL_AREA_SPECIAL) != 1  or m['uclAreaKindCount'](UCL_AREA_SMALLITEM) != 2  or m['uclAreaKindCount'](UCL_AREA_HOLE) != 0  or strcmp(m['uclLegerdemain'](0).name,m['uastCantripName'](2, 0)) != 0  or m['uclLegerdemain'](0) .school != 2  or m['uclLegerdemain'](0) .areaKind != 0  or m['uclLegerdemain'](0) .areaVal != 0  or strcmp(m['uclLegerdemain'](1).name,m['uastCantripName'](2, 1)) != 0  or m['uclLegerdemain'](1) .school != 3  or m['uclLegerdemain'](1) .areaKind != 3  or m['uclLegerdemain'](1) .areaVal != 0  or strcmp(m['uclLegerdemain'](2).name,m['uastCantripName'](2, 2)) != 0  or m['uclLegerdemain'](2) .school != 4  or m['uclLegerdemain'](2) .areaKind != 0  or m['uclLegerdemain'](2) .areaVal != 0  or strcmp(m['uclLegerdemain'](3).name,m['uastCantripName'](2, 3)) != 0  or m['uclLegerdemain'](3) .school != 2  or m['uclLegerdemain'](3) .areaKind != 0  or m['uclLegerdemain'](3) .areaVal != 0  or strcmp(m['uclLegerdemain'](4).name,m['uastCantripName'](2, 4)) != 0  or m['uclLegerdemain'](4) .school != 4  or m['uclLegerdemain'](4) .areaKind != 7  or m['uclLegerdemain'](4) .areaVal != 0  or strcmp(m['uclLegerdemain'](5).name,m['uastCantripName'](2, 5)) != 0  or m['uclLegerdemain'](5) .school != 2  or m['uclLegerdemain'](5) .areaKind != 7  or m['uclLegerdemain'](5) .areaVal != 0",
      "note" = "---- the area census ----",
    }, {
      "expr" = "m['uclCastTimeDen'](0) != 10  or m['uclCastTimeDen'](1) != 3  or m['uclCastTimeDen'](2) != 10  or m['uclCastTimeDen'](3) != 10  or m['uclCastTimeDen'](4) != 10  or m['uclCastTimeDen'](5) != 8",
      "note" = "---- the casting times ---- (the PDF read resolves the family - R418)",
    }, {
      "expr" = "m['uclChangeSizePctMax']() != 50  or m['uclChangeBaseTurns']() != 1  or m['uclChangeRadicalRounds']() != 1  or m['uclChangeSlightDays']() != 1  or m['uclDistractRangeFt']() != 10  or m['uclDistractDurationSegments']() != 1",
      "note" = "---- the mechanics ----",
    }, {
      "expr" = "m['uclHideBaseCubicYds']() != 2  or m['uclHideBaseTurns']() != 1  or m['uclHideRoundCubicYds']() != 20",
      "note" = "---- the hide ladder ----",
    }, {
      "expr" = "m['uclHideSegStartCubicYds']() != 22  or m['uclHideSegStartSegments']() != 9  or m['uclHideSegStepCubicYds']() != 2  or m['uclHideMinCubicYds']() != 38  or m['uclHideMinSegments']() != 1  or (m['uclHideMinCubicYds']() -m['uclHideSegStartCubicYds']()) /m['uclHideSegStepCubicYds']() !=m['uclHideSegStartSegments']() -m['uclHideMinSegments']()  or (m['uclHideMinCubicYds']() -m['uclHideSegStartCubicYds']()) %m['uclHideSegStepCubicYds']() != 0  or m['uclMuteDurationRounds']() != 1  or m['uclPalmDurationSegments']() != 1  or m['uclPresentRadiusFt']() != 2  or m['uclPresentMaxCoins']() != 12",
      "note" = "The derivation: the segment span (38-22)/2 = 8 equals 9 - 1, and the span divides the step.",
    } },
  "audit" = {
      "label" = "R414: the UA legerdemain cantrips pin audit",
      "comment" = "The 6 legerdemain descriptions pin: the names cross-check the R341/R401 roster live, the schools and areas pin per row (ZERO area holes; Illusion a NEW school code, one small item a NEW area kind), the school census counts (0/0/3/1/2), the casting-time family stays the hole family, the mechanics pin with the hide ladder cross-checking itself by derivation; census 340 -> 341.",
    },
}
