-- ua333: promoted from rules/ua/uaranger.h (the The UA ranger expansion (pp. 21-22) pins (R333).);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 333,
  "prefix" = "ua333",
  "banner" = {
      "title" = "The UA ranger expansion (pp. 21-22) pins (R333).",
      "provenance" = "Pin-era pattern (R322): pinned data only - no engine site exists. The registry rows and the creation-flow gates ride their own rounds.  Scope = the gap-report item: the tracking rules, the giant-class combat bonus, the spell progression. The spell bands (druidic from the 8th up to 3rd, magic-user from the 9th up to 2nd) already ride the R327 pins and the R184 spell layers - cross-checked in the audit, not re-pinned here (the UA prose restating them is OCR-lost from the extract). The ranger weapons rules (the bow-or-crossbow requirement, the four required types by 4th level) are NOT in the gap item - they ride a later round.  OCR holes documented in-header: the per-creature-beyond-first and per-hour-of-precipitation modifier values are lost; the indoor surface-condition table cells are lost (the prose fixes the same four-category ladder via the next-lower-category and -50% references); the movement-rate-while-tracking table's six rows survive but every rate cell is lost; the identification table's level column is empty (the ladder is fixed by the internal \"As Nth level\" references); the roster's \"anoll\" cell decodes as gnoll (the g->a OCR slip; the alphabetical column confirms).",
    },
  "consts" = { {
      "name" = "uaRangerTrackBasePerLevel",
      "value" = 10,
      "comment" = "---- the outdoor tracking base (p. 21) ---- 10% per level plus an additional 10% (20% at 1st, 70% at 6th); the base rises as high as 110% (10th level or higher) and never more; an adjusted chance over 100% is treated as 100%.",
    }, {
      "name" = "uaRangerTrackBaseBonus",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackBaseCap",
      "value" = 110,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackAdjustedCap",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackTerrainCategoryCount",
      "value" = 4,
      "comment" = "---- the terrain modifiers (p. 21) ---- Four categories: soft +20%, occasional marks +10%, infrequent 0%, minutest-traces -50%. Intelligent hiding drops one category; at the -50% category tracking is impossible.",
    }, {
      "name" = "uaRangerTrackPer12Hours",
      "value" = 5,
      "comment" = "---- the other modifiers (p. 21) ---- -5% per 12 hours elapsed since the trail was made. The per-creature-beyond-first and per-hour-of-precipitation values are OCR-lost (documented above) - not pinned.",
    }, {
      "name" = "uaRangerTrackFollowWindowLow",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackFollowWindowHigh",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackMoveRowCount",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackObviousMin",
      "value" = 71,
      "comment" = "---- the tracking-quality definitions (p. 21) ---- Obvious 71% or better; occasional 31-70%; faint 30% or less; poor illumination is anything under daylight over total darkness.",
    }, {
      "name" = "uaRangerTrackOccasionalLow",
      "value" = 31,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackOccasionalHigh",
      "value" = 70,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackFaintMax",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackIdentifyRowCount",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uaRangerGiantDamagePerLevel",
      "value" = 1,
      "comment" = "---- the giant class (p. 22) ---- The damage bonus: +1 point per ranger level when a giant-class creature is engaged. The expanded roster: the 11 Players Handbook creatures (the R184 pins) plus the Fiend Folio and Monster Manual II additions, 22 in all, stored lowercase and sorted (the R184 matching convention); the garbled \"anoll\" cell decodes as gnoll.",
    }, {
      "name" = "uaRangerGiantRosterCount",
      "value" = 22,
      "comment" = "",
    }, {
      "name" = "uaRangerGiantRosterPhbCount",
      "value" = 11,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uaRangerTrackHideDropsCategory",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackHideAtRockBottomImpossible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackIndoorBaseSame",
      "value" = true,
      "comment" = "---- the indoor tracking (p. 21) ---- Same base chance; the surface-condition ladder runs the same four categories (prose-verified); intelligent hiding (even through a secret door) drops one category, impossible at the bottom; indoors is impossible without an observed distinguishing feature and a follow-up within 10-30 minutes of the quarry making the trail.",
    }, {
      "name" = "uaRangerTrackIndoorObservationRequired",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackGoodLightAssumed",
      "value" = true,
      "comment" = "---- the light and movement reads (p. 21) ---- Good illumination assumed; total darkness is impossible without non-visual evidence; the tracking movement rate is slowed even at best (the six-row rate table's cells are OCR-lost).",
    }, {
      "name" = "uaRangerTrackTotalDarknessImpossible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaRangerTrackIdentifySecondRoll",
      "value" = true,
      "comment" = "---- the identification ladder (p. 21) ---- Identification needs a second roll at the same chance; the abilities are cumulative by level. The level cells are OCR-empty; the ladder is fixed by the internal \"As Nth level\" references.",
    }, {
      "name" = "uaRangerTrackIdentifyCumulative",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uaRangerTrackBaseAt",
      "comment" = "",
      "kind" = "header pin",
      "body" = "if (level < 1) return 0; int p = 10 * level + 10; return p > 110 ? 110 : p;",
    }, {
      "name" = "uaRangerTrackTerrainModifier",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = {20, 10, 0, -50}; if (category < 0) category = 0; if (category > 3) category = 3; return k[category];",
    }, {
      "name" = "uaRangerTrackIdentifyAbility",
      "comment" = "",
      "kind" = "string array",
      "count" = 10,
      "values" = { "Common woodland creatures' tracks and direction of travel", "Common woodland creatures' number and pace", "Common woodland creatures' time of passage (outdoors only)", "As 3rd level with respect to uncommon woodland creatures", "As 3rd level with respect to rare woodland creatures", "As 3rd level with respect to very rare woodland creatures", "As 3rd level with respect to all sorts of creatures (woodland and otherwise) within a 100-mile radius", "As 7th level, plus the ability to determine the general size and weight of humans", "As 8th level, plus the ability to determine the size and numbers of mounted creatures", "As 9th level with respect to all creatures ever observed, prior to attaining 10th level or subsequently" },
    }, {
      "name" = "uaRangerGiantRosterName",
      "comment" = "",
      "kind" = "string array",
      "count" = 22,
      "values" = { "bugbear", "cyclopskin", "dune stalker", "ettin", "flind", "gibberling", "giant", "gnoll", "goblin", "grimlock", "hobgoblin", "kobold", "meazel", "norker", "ogre", "ogre mage", "ogrillon", "orc", "quaggoth", "tasloi", "troll", "xvart" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uaRangerTrackBasePerLevel']() != 10  or m['uaRangerTrackBaseBonus']() != 10  or m['uaRangerTrackBaseCap']() != 110  or m['uaRangerTrackAdjustedCap']() != 100  or m['uaRangerTrackBaseAt'](1) != 20  or m['uaRangerTrackBaseAt'](6) != 70  or m['uaRangerTrackBaseAt'](10) != 110  or m['uaRangerTrackBaseAt'](20) != 110  or m['uaRangerTrackBaseAt'](0) != 0",
      "note" = "U1: the outdoor tracking base",
    }, {
      "expr" = "m['uaRangerTrackTerrainCategoryCount']() != 4  or m['uaRangerTrackTerrainModifier'](c) != k[c]  or  m['uaRangerTrackHideDropsCategory']() != 1  or  m['uaRangerTrackHideAtRockBottomImpossible']() != 1",
      "note" = "U2: the terrain ladder and the hide rule",
    }, {
      "expr" = "m['uaRangerTrackPer12Hours']() != 5",
      "note" = "U3: the elapsed-time modifier",
    }, {
      "expr" = "m['uaRangerTrackIndoorBaseSame']() != 1  or  m['uaRangerTrackIndoorObservationRequired']() != 1  or m['uaRangerTrackFollowWindowLow']() != 10  or m['uaRangerTrackFollowWindowHigh']() != 30",
      "note" = "U4: the indoor reads",
    }, {
      "expr" = "m['uaRangerTrackGoodLightAssumed']() != 1  or  m['uaRangerTrackTotalDarknessImpossible']() != 1  or m['uaRangerTrackMoveRowCount']() != 6",
      "note" = "U5: the light and movement reads",
    }, {
      "expr" = "m['uaRangerTrackObviousMin']() != 71  or m['uaRangerTrackOccasionalLow']() != 31  or m['uaRangerTrackOccasionalHigh']() != 70  or m['uaRangerTrackFaintMax']() != 30",
      "note" = "U6: the quality definitions",
    }, {
      "expr" = "m['uaRangerTrackIdentifySecondRoll']() != 1  or  m['uaRangerTrackIdentifyCumulative']() != 1  or m['uaRangerTrackIdentifyRowCount']() != 10  or strcmp(m['uaRangerTrackIdentifyAbility']( 1), \"Common woodland creatures'\" \" tracks and direction of travel\") != 0  or strcmp(m['uaRangerTrackIdentifyAbility']( 3), \"Common woodland creatures'\" \" time of passage (outdoors\" \" only)\") != 0  or strcmp(m['uaRangerTrackIdentifyAbility']( 4), \"As 3rd level with respect\" \" to uncommon woodland\" \" creatures\") != 0  or strcmp(m['uaRangerTrackIdentifyAbility']( 7), \"As 3rd level with respect\" \" to all sorts of creatures\" \" (woodland and otherwise)\" \" within a 100-mile radius\") != 0  or strcmp(m['uaRangerTrackIdentifyAbility']( 9), \"As 8th level, plus the\" \" ability to determine the\" \" size and numbers of mounted\" \" creatures\") != 0  or strcmp(m['uaRangerTrackIdentifyAbility']( 10), \"As 9th level with respect\" \" to all creatures ever\" \" observed, prior to attaining\" \" 10th level or subsequently\") != 0",
      "note" = "U7: the identification ladder",
    }, {
      "expr" = "m['uaRangerGiantDamagePerLevel']() != 1  or m['uaRangerGiantRosterCount']() != 22  or m['uaRangerGiantRosterPhbCount']() != 11  or strcmp(m['uaRangerGiantRosterName'](7), \"gnoll\") != 0  or strcmp(m['uaRangerGiantRosterName'](1), \"cyclopskin\") != 0  or strcmp(m['uaRangerGiantRosterName'](21), \"xvart\") != 0  or  !found",
      "note" = "U8: the giant class - the damage bonus, the roster, the superset",
    }, {
      "expr" = "m['rangerDruidicFromLevel']() != 8  or m['rangerDruidicMaxSpellLevel']() != 3  or m['rangerMuFromLevel']() != 9  or m['rangerMuMaxSpellLevel']() != 2  or m['rangerGiantClassBonus'](7) != 7  or  !m['weaponSpecClassAllowed']( UACLASS_RANGER)  or  m['barbarianTracksAsRanger']() != 1",
      "note" = "U9: the seams - the spell bands (R327), the R184 bonus, the R331 spec gate, the R332 tracking read",
    } },
  "audit" = {
      "label" = "R333: the ranger expansion pin audit",
      "comment" = "The UA ranger expansion (pp. 21-22) - the pin-era pattern: the tracking base and terrain ladders, the indoor reads, the identification ladder, the giant-class roster expansion 11 -> 22 (the per-creature and precipitation values, the surface cells and the rate cells are OCR holes - documented in the header). The spell-progression component and the R184/R327/R331/R332 seams cross-checked.",
    },
}
