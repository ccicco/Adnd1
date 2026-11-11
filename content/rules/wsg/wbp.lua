-- wbp: promoted from tools/spec_r457.json (the The WSG THE BOATING PROFICIENCY, R457: this section deals primarily with the effects of not having a character with boating proficiency aboard. In a vessel containing no proficient characters, or one in which at least one non-proficient character is doing some of the work of rowing or sailing, the penalties apply: the movement rates of a kayak, a small canoe and a coracle are reduced to one-half of normal; a small rowboat, a large canoe, a large rowboat and a small barge to two-thirds of normal; and a large barge to three-quarters of normal - the reduction applied before any other alterations (wind speed and current speed) are taken into account. The chance of capsizing is increased by 25% in any situation where the chance is normally greater than 0%, to a maximum of 100%. With more than one proficient character aboard: the chance of capsizing is reduced by 20% for each proficient character after the first one; the chance of damage to the mast or sails is reduced by 20%, assuming the proficient characters have some means of making the rigging secure or bracing the mast so that it will better withstand the stress. If ALL of the characters helping to row or sail a vessel have proficiency in boating, the movement penalties do not apply and the movement rates are as given on the table at the beginning of this section. Two characters are required to sail a large rowboat, a small barge or a large barge; all other vessels can be sailed by one character.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 457,
  "prefix" = "wbp",
  "banner" = {
      "title" = "The WSG THE BOATING PROFICIENCY, R457: this section deals primarily with the effects of not having a character with boating proficiency aboard. In a vessel containing no proficient characters, or one in which at least one non-proficient character is doing some of the work of rowing or sailing, the penalties apply: the movement rates of a kayak, a small canoe and a coracle are reduced to one-half of normal; a small rowboat, a large canoe, a large rowboat and a small barge to two-thirds of normal; and a large barge to three-quarters of normal - the reduction applied before any other alterations (wind speed and current speed) are taken into account. The chance of capsizing is increased by 25% in any situation where the chance is normally greater than 0%, to a maximum of 100%. With more than one proficient character aboard: the chance of capsizing is reduced by 20% for each proficient character after the first one; the chance of damage to the mast or sails is reduced by 20%, assuming the proficient characters have some means of making the rigging secure or bracing the mast so that it will better withstand the stress. If ALL of the characters helping to row or sail a vessel have proficiency in boating, the movement penalties do not apply and the movement rates are as given on the table at the beginning of this section. Two characters are required to sail a large rowboat, a small barge or a large barge; all other vessels can be sailed by one character.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 45; the user own copy OCR (page 46) cross-checked against the archive djvu word layer (Guide_0045) - the prose reads clean two-way and NO eye-reads were needed for this round (a pure-prose section, no printed grid).",
    },
  "consts" = { {
      "name" = "wbpVesselCount",
      "value" = 8,
      "comment" = "The same eight vessels as Tables 25 and 26: kayak, small canoe, small rowboat, coracle, large canoe, large rowboat, small barge and large barge.",
    }, {
      "name" = "wbpCapsizeNonprofAdd",
      "value" = 25,
      "comment" = "With no proficient character aboard, the chance of capsizing is increased by 25% in any situation where the chance is normally greater than 0%.",
    }, {
      "name" = "wbpCapsizeCeiling",
      "value" = 100,
      "comment" = "The increased capsize chance can never exceed 100%.",
    }, {
      "name" = "wbpCapsizeExtraProfCut",
      "value" = 20,
      "comment" = "The chance of capsizing is reduced by 20% for each proficient character after the first one.",
    }, {
      "name" = "wbpMastDamageProfCut",
      "value" = 20,
      "comment" = "The chance of damage to the mast or sails is reduced by 20% when more than one proficient character is aboard, assuming they can secure the rigging or brace the mast.",
    }, {
      "name" = "wbpTwoHandedSailCrew",
      "value" = 2,
      "comment" = "Two characters are required to sail a large rowboat, a small barge or a large barge; all other vessels can be sailed by one.",
    } },
  "bools" = { {
      "name" = "wbpPenaltyIfNoneProficient",
      "value" = true,
      "comment" = "The penalties apply in a vessel containing no proficient characters.",
    }, {
      "name" = "wbpPenaltyIfAnyNonprofWorking",
      "value" = true,
      "comment" = "The penalties also apply when at least one non-proficient character is doing some of the work of rowing or sailing.",
    }, {
      "name" = "wbpReductionBeforeWindCurrent",
      "value" = true,
      "comment" = "The movement-rate reduction is applied before any other alterations - wind speed and current speed - are taken into account.",
    }, {
      "name" = "wbpCapsizeAddOnlyIfBasePositive",
      "value" = true,
      "comment" = "The +25% capsize penalty applies only in situations where the chance is normally greater than 0%.",
    }, {
      "name" = "wbpCapsizeCappedAtCeiling",
      "value" = true,
      "comment" = "The capsize chance after the penalty is capped at the 100% ceiling.",
    }, {
      "name" = "wbpExtraProfsReduceCapsize",
      "value" = true,
      "comment" = "Each proficient character after the first reduces the chance of capsizing.",
    }, {
      "name" = "wbpMastCutNeedsRiggingBrace",
      "value" = true,
      "comment" = "The mast/sail damage reduction assumes the proficient characters can make the rigging secure or brace the mast against the stress.",
    }, {
      "name" = "wbpAllProficientWaivesMovePenalty",
      "value" = true,
      "comment" = "If all of the characters helping to row or sail the vessel have proficiency, the movement penalties do not apply and the rates are as given on the movement table.",
    }, {
      "name" = "wbpSailCrewIsTwoHanded",
      "value" = true,
      "comment" = "The two-handed sail-crew minimum holds for the large rowboat, the small barge and the large barge; every other vessel sails with one.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "the nonproficient movement and sail-crew grid",
      "tag" = "27",
      "count" = "wbpVesselCount",
      "col_default" = 0,
      "audit_comment" = "the movement-and-crew grid: the eight vessels (kayak, small canoe, small rowboat, coracle, large canoe, large rowboat, small barge, large barge) with the movement-fraction numerator and denominator of the nonproficient penalty and the minimum sail crew",
      "cols" = { "wbpMoveNum", "wbpMoveDen", "wbpSailCrew" },
      "col_comments" = { "the movement-fraction numerator - the reduced rate is num/den of normal", "the movement-fraction denominator - one-half, two-thirds or three-quarters", "the minimum sail crew - one, or two for the large rowboat, small barge and large barge" },
      "data" = { { 1, 2, 1 }, { 1, 2, 1 }, { 2, 3, 1 }, { 1, 2, 1 }, { 2, 3, 1 }, { 2, 3, 2 }, { 2, 3, 2 }, { 3, 4, 2 } },
      "row_labels" = { "kayak", "small canoe", "small rowboat", "coracle", "large canoe", "large rowboat", "small barge", "large barge" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wbpMoveNum'](0) != 1 or m['wbpMoveDen'](0) != 2 or m['wbpMoveNum'](1) != 1 or m['wbpMoveDen'](1) != 2 or m['wbpMoveNum'](3) != 1 or m['wbpMoveDen'](3) != 2",
      "note" = "the half-rate group: the kayak, the small canoe and the coracle all move at one-half of normal when no proficient character is aboard",
    }, {
      "expr" = "m['wbpMoveNum'](2) != 2 or m['wbpMoveDen'](2) != 3 or m['wbpMoveNum'](4) != 2 or m['wbpMoveDen'](4) != 3 or m['wbpMoveNum'](5) != 2 or m['wbpMoveDen'](5) != 3 or m['wbpMoveNum'](6) != 2 or m['wbpMoveDen'](6) != 3",
      "note" = "the two-thirds group: the small rowboat, the large canoe, the large rowboat and the small barge all move at two-thirds of normal",
    }, {
      "expr" = "m['wbpMoveNum'](7) != 3 or m['wbpMoveDen'](7) != 4",
      "note" = "the large barge alone moves at three-quarters of normal under the penalty - the sturdiest vessel takes the smallest cut",
    }, {
      "expr" = "m['wbpCapsizeNonprofAdd']() != 25 or m['wbpCapsizeCeiling']() != 100 or m['wbpCapsizeExtraProfCut']() != 20 or m['wbpMastDamageProfCut']() != 20",
      "note" = "the four percentage pins: the +25% nonproficient capsize penalty with its 100% ceiling, the -20% per extra proficient character, and the -20% mast/sail damage reduction",
    }, {
      "expr" = "m['wbpSailCrew'](0) != 1 or m['wbpSailCrew'](1) != 1 or m['wbpSailCrew'](2) != 1 or m['wbpSailCrew'](3) != 1 or m['wbpSailCrew'](4) != 1",
      "note" = "the one-handed vessels: the kayak, the small canoe, the small rowboat, the coracle and the large canoe each sail with a single character",
    }, {
      "expr" = "m['wbpSailCrew'](5) != 2 or m['wbpSailCrew'](6) != 2 or m['wbpSailCrew'](7) != 2 or m['wbpSailCrew'](5) + m['wbpSailCrew'](6) + m['wbpSailCrew'](7) != 6 or m['wbpTwoHandedSailCrew']() != 2",
      "note" = "the two-handed vessels: the large rowboat, the small barge and the large barge each need a sail crew of two, three vessels summing to six crew",
    }, {
      "expr" = "m['wbpMoveDen'](7) != 4 or m['wbpMoveNum'](7) != 3 or m['wbpMoveDen'](2) != 3 or m['wbpMoveDen'](0) != 2 or m['wbpMoveNum'](0) != 1",
      "note" = "the fraction sanity: the denominators carry the names - halves on a 2, thirds on a 3, quarters on a 4",
    } },
  "audit" = {
      "label" = "R457 WSG boating pin audit",
      "comment" = "The boating-proficiency slice pins the nonproficient penalties - the movement-rate reductions (kayak, small canoe and coracle at one-half, small rowboat, large canoe, large rowboat and small barge at two-thirds, large barge at three-quarters, applied before the wind and current alterations), the +25% capsize penalty where the base chance exceeds zero, capped at 100%; the proficient-crew benefits - the -20% capsize reduction per proficient character after the first, the -20% mast/sail damage reduction with the rigging-brace assumption, the all-proficient waiver of the movement penalties, and the two-character sail crews for the large rowboat, the small barge and the large barge (rules/wsg/wsgboat.h, prefix wbp); census 381 -> 382.",
    },
}
