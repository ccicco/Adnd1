-- wse: promoted from rules/wsg/wsgenvfx.h (the The WSG ENVIRONMENT EFFECTS, R427:);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 427,
  "prefix" = "wse",
  "banner" = {
      "title" = "The WSG ENVIRONMENT EFFECTS, R427:",
      "provenance" = "the data slice of the effects-of-the- environment chapter - Table 4 (the 13 temperature bands: the Str/Dex/Con reductions nonstrenuous and strenuous, the Land Move fraction, the Attack Rolls penalty) and Table 5 (the 6 wind bands: the missile adjustments at point blank/short/medium/long, the melee penalty, the move-against-wind fraction) with the how-to-use prose and the precipitation rules; census 352 -> 353.  Provenance: the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 21-22; the grids read from the IIIF page image (the text layer mangles the fractions and drops the 120-or-higher row); the prose verified whole against the text layer.  Sentinel: 99 = no effect (a dash cell) and xx = impossible (the missile columns); the Land Move fraction pins as num/den, 99 = none.",
    },
  "consts" = { {
      "name" = "wseTempBandCount",
      "value" = 13,
      "comment" = "The census: 13 bands, -40 or lower up to 120 or higher.",
    }, {
      "name" = "wseStrenuousWindowTurns",
      "value" = 2,
      "comment" = "The strenuous side of a slash applies also when strenuous activity was performed within this many turns.",
    }, {
      "name" = "wseExStrCapNonstren",
      "value" = 18,
      "comment" = "An exceptional Strength score reduces to 18 for a nonstrenuous check.",
    }, {
      "name" = "wseExStrCapStren",
      "value" = 17,
      "comment" = "... and to 17 for a strenuous one.",
    }, {
      "name" = "wseDamageFloor",
      "value" = 1,
      "comment" = "A damage roll can never be reduced below this by these penalties.",
    }, {
      "name" = "wseWindBandCount",
      "value" = 6,
      "comment" = "The census: 6 bands, 0-10 up to 80+.",
    }, {
      "name" = "wsePrecipModerateShift",
      "value" = 1,
      "comment" = "Moderate precipitation: use the next higher wind line (0-10 behaves as 11-20).",
    }, {
      "name" = "wsePrecipHeavyShift",
      "value" = 2,
      "comment" = "Heavy precipitation: two lines down (11-20 behaves as 31-45).",
    }, {
      "name" = "wseXxCensus",
      "value" = 9,
      "comment" = "The census of the xx cells in the Table 5 missile columns.",
    } },
  "bools" = { {
      "name" = "wsePercentileDisregarded",
      "value" = true,
      "comment" = "The cavalier and paladin percentile Dex/Con scores are disregarded - only the whole number counts.",
    }, {
      "name" = "wseFractionRoundUp",
      "value" = true,
      "comment" = "Fractional movement results round up: half of 9 is 5.",
    }, {
      "name" = "wseAttackCumulative",
      "value" = true,
      "comment" = "The Attack Rolls penalty is cumulative with any penalties from the Strength reduction.",
    }, {
      "name" = "wseAssumesAttire",
      "value" = true,
      "comment" = "The table entries assume the character is appropriately attired.",
    }, {
      "name" = "wseWindIsMaximum",
      "value" = true,
      "comment" = "The wind velocity is the maximum the wind can reach, not a constant.",
    }, {
      "name" = "wseMissileDirNoDiff",
      "value" = true,
      "comment" = "The direction a missile is fired in makes no difference.",
    }, {
      "name" = "wseXxIsImpossible",
      "value" = true,
      "comment" = "xx = impossible: under normal circumstances the target cannot be hit.",
    }, {
      "name" = "wseMeleeCumulative",
      "value" = true,
      "comment" = "The melee penalty is cumulative with the Table 4 attack penalty.",
    }, {
      "name" = "wsePerpNextLower",
      "value" = true,
      "comment" = "Moving perpendicular to the wind uses the next lower velocity line.",
    }, {
      "name" = "wseGreaterOfReductions",
      "value" = true,
      "comment" = "When both tables reduce movement, use the greater reduction.",
    }, {
      "name" = "wsePrecipCapAtBottom",
      "value" = true,
      "comment" = "Conditions can never become worse than the bottom (80+) line.",
    } },
  "switches" = { {
      "name" = "wseTempStrNonstren",
      "values" = { -1, -1, 0, 0, 99, 99, 99, 99, 99, 0, -1, -1, -2 },
      "default" = 0,
      "comment" = "The Strength reduction, nonstrenuous (the left of the slash).",
    }, {
      "name" = "wseTempStrStren",
      "values" = { -2, -2, -1, -1, 99, 99, 99, 99, 99, -1, -2, -3, -4 },
      "default" = 0,
      "comment" = "The Strength reduction, strenuous (the right of the slash).",
    }, {
      "name" = "wseTempDexNonstren",
      "values" = { -4, -3, -2, -1, -1, 0, 0, 99, 99, 99, 0, -1, -1 },
      "default" = 0,
      "comment" = "The Dexterity reduction, nonstrenuous.",
    }, {
      "name" = "wseTempDexStren",
      "values" = { -5, -4, -3, -2, -2, -1, -1, 99, 99, 99, -1, -2, -3 },
      "default" = 0,
      "comment" = "The Dexterity reduction, strenuous.",
    }, {
      "name" = "wseTempConNonstren",
      "values" = { -1, -1, 0, 0, 99, 99, 99, 99, 0, -1, -2, -3, -4 },
      "default" = 0,
      "comment" = "The Constitution reduction, nonstrenuous.",
    }, {
      "name" = "wseTempConStren",
      "values" = { -2, -2, -1, -1, 99, 99, 99, 99, -1, -2, -3, -4, -5 },
      "default" = 0,
      "comment" = "The Constitution reduction, strenuous.",
    }, {
      "name" = "wseTempLandMoveNum",
      "values" = { 1, 1, 2, 2, 3, 3, 99, 99, 3, 3, 2, 1, 1 },
      "default" = 0,
      "comment" = "The Land Move fraction, numerator; 99 = no reduction.",
    }, {
      "name" = "wseTempLandMoveDen",
      "values" = { 2, 2, 3, 3, 4, 4, 99, 99, 4, 4, 3, 2, 2 },
      "default" = 0,
      "comment" = "The Land Move fraction, denominator; 99 = no reduction.",
    }, {
      "name" = "wseTempAttack",
      "values" = { -4, -3, -2, -1, -1, 99, 99, 99, 99, -1, -2, -3, -4 },
      "default" = 0,
      "comment" = "The Attack Rolls penalty on to-hit and damage; 99 = no effect.",
    }, {
      "name" = "wseWindMissilePb",
      "values" = { 0, 0, -1, -2, -4, 99 },
      "default" = 0,
      "comment" = "The missile adjustment, point blank; 99 = xx = impossible.",
    }, {
      "name" = "wseWindMissileShort",
      "values" = { 0, -1, -2, -4, -6, 99 },
      "default" = 0,
      "comment" = "The missile adjustment, short range.",
    }, {
      "name" = "wseWindMissileMed",
      "values" = { 0, -2, -3, 99, 99, 99 },
      "default" = 0,
      "comment" = "The missile adjustment, medium range.",
    }, {
      "name" = "wseWindMissileLong",
      "values" = { 0, -3, 99, 99, 99, 99 },
      "default" = 0,
      "comment" = "The missile adjustment, long range.",
    }, {
      "name" = "wseWindMelee",
      "values" = { 0, 0, -1, -2, -4, -8 },
      "default" = 0,
      "comment" = "The melee combat penalty on to-hit and damage.",
    }, {
      "name" = "wseWindMoveNum",
      "values" = { 99, 99, 3, 2, 1, 1 },
      "default" = 0,
      "comment" = "The move-against-wind fraction, numerator; 99 = no reduction.",
    }, {
      "name" = "wseWindMoveDen",
      "values" = { 99, 99, 4, 3, 2, 4 },
      "default" = 0,
      "comment" = "The move-against-wind fraction, denominator.",
    } },
  "tables" = {},
  "chains" = { {
      "name" = "wseTempBandFor",
      "arg" = "t",
      "limits" = { -40, -30, -20, -10, 0, 10, 20, 79, 89, 99, 109, 119 },
      "tail" = 12,
      "comment" = "The band for a personal temperature: 0 = -40 or lower ... 12 = 120 or higher; 7 = the tolerable 21-79 range.",
    }, {
      "name" = "wseWindBandFor",
      "arg" = "m",
      "limits" = { 10, 20, 30, 45, 79 },
      "tail" = 5,
      "comment" = "The band for a wind velocity in miles per hour: 0 = 0-10 ... 5 = 80+.",
    } },
  "examples" = { {
      "expr" = "m['wseTempBandCount']() != 13  or m['wseWindBandCount']() != 6  or m['wseStrenuousWindowTurns']() != 2  or m['wseExStrCapNonstren']() != 18  or m['wseExStrCapStren']() != 17  or  m['wsePercentileDisregarded']() != 1  or  m['wseFractionRoundUp']() != 1  or  m['wseAttackCumulative']() != 1  or m['wseDamageFloor']() != 1  or  m['wseAssumesAttire']() != 1  or  m['wseWindIsMaximum']() != 1  or  m['wseMissileDirNoDiff']() != 1  or  m['wseXxIsImpossible']() != 1  or  m['wseMeleeCumulative']() != 1  or  m['wsePerpNextLower']() != 1  or  m['wseGreaterOfReductions']() != 1  or m['wsePrecipModerateShift']() != 1  or m['wsePrecipHeavyShift']() != 2  or  m['wsePrecipCapAtBottom']() != 1  or m['wseXxCensus']() != 9",
      "note" = "",
    }, {
      "expr" = "m['wseTempBandFor'](105) != 10  or m['wseTempStrNonstren'](10) != -1  or m['wseTempStrStren'](10) != -2",
      "note" = "the book own 105-degree strength example",
    }, {
      "expr" = "m['wseWindBandFor'](0) != 0  or m['wseWindBandFor'](10) != 0  or m['wseWindBandFor'](11) != 1  or m['wseWindBandFor'](45) != 3  or m['wseWindBandFor'](46) != 4  or m['wseWindBandFor'](79) != 4  or m['wseWindBandFor'](80) != 5  or m['wseWindBandFor'](200) != 5",
      "note" = "the wind band-for boundaries",
    }, {
      "expr" = "m['wseWindBandFor'](35) != 3  or m['wseWindMelee'](3) != -2  or (12 *m['wseWindMoveNum'](3)) /m['wseWindMoveDen'](3) != 8  or (12 *m['wseWindMoveNum'](2)) /m['wseWindMoveDen'](2) != 9",
      "note" = "the book own 35-mph example: melee -2, 12 -> 8 against the wind, 9 perpendicular",
    }, {
      "expr" = "m['wseTempBandFor'](85) != 8  or m['wseWindBandFor'](40) != 3  or not (m['wseWindMoveNum'](3) *m['wseTempLandMoveDen'](8) <m['wseTempLandMoveNum'](8) *m['wseWindMoveDen'](3))",
      "note" = "the 85/40 example: the greater reduction is 2/3 (temperature 3/4 vs wind 2/3)",
    }, {
      "expr" = "m['wseWindBandFor'](5) +m['wsePrecipModerateShift']() != 1  or m['wseWindMissileShort'](1) != -1  or m['wseWindBandFor'](15) +m['wsePrecipHeavyShift']() != 3  or m['wseWindMelee'](3) != -2  or m['wseWindBandFor'](90) != 5  or (m['wseWindBandFor'](90) +m['wsePrecipHeavyShift']() != 7)",
      "note" = "the precipitation examples: moderate rain with 0-10 wind behaves as 11-20; heavy snow with 11-20 behaves as 31-45; the raw shift 5 + 2 = 7 overshoots the bottom, so the wsePrecipCapAt Bottom pin caps it",
    }, {
      "expr" = "m['wseTempDexNonstren'](0) != -4 or m['wseTempDexNonstren'](1) != -3 or m['wseTempDexNonstren'](2) != -2 or m['wseTempDexNonstren'](3) != -1 or m['wseTempDexNonstren'](4) != -1 or m['wseTempDexNonstren'](5) != 0 or m['wseTempDexNonstren'](6) != 0 or m['wseTempDexNonstren'](7) != 99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseTempDexNonstren'](8) != 99 or m['wseTempDexNonstren'](9) != 99 or m['wseTempDexNonstren'](10) != 0 or m['wseTempDexNonstren'](11) != -1 or m['wseTempDexNonstren'](12) != -1 or m['wseTempDexNonstren'](13) != 0 or m['wseTempDexStren'](0) != -5 or m['wseTempDexStren'](1) != -4",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseTempDexStren'](2) != -3 or m['wseTempDexStren'](3) != -2 or m['wseTempDexStren'](4) != -2 or m['wseTempDexStren'](5) != -1 or m['wseTempDexStren'](6) != -1 or m['wseTempDexStren'](7) != 99 or m['wseTempDexStren'](8) != 99 or m['wseTempDexStren'](9) != 99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseTempDexStren'](10) != -1 or m['wseTempDexStren'](11) != -2 or m['wseTempDexStren'](12) != -3 or m['wseTempDexStren'](13) != 0 or m['wseTempConNonstren'](0) != -1 or m['wseTempConNonstren'](1) != -1 or m['wseTempConNonstren'](2) != 0 or m['wseTempConNonstren'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseTempConNonstren'](4) != 99 or m['wseTempConNonstren'](5) != 99 or m['wseTempConNonstren'](6) != 99 or m['wseTempConNonstren'](7) != 99 or m['wseTempConNonstren'](8) != 0 or m['wseTempConNonstren'](9) != -1 or m['wseTempConNonstren'](10) != -2 or m['wseTempConNonstren'](11) != -3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseTempConNonstren'](12) != -4 or m['wseTempConNonstren'](13) != 0 or m['wseTempConStren'](0) != -2 or m['wseTempConStren'](1) != -2 or m['wseTempConStren'](2) != -1 or m['wseTempConStren'](3) != -1 or m['wseTempConStren'](4) != 99 or m['wseTempConStren'](5) != 99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseTempConStren'](6) != 99 or m['wseTempConStren'](7) != 99 or m['wseTempConStren'](8) != -1 or m['wseTempConStren'](9) != -2 or m['wseTempConStren'](10) != -3 or m['wseTempConStren'](11) != -4 or m['wseTempConStren'](12) != -5 or m['wseTempConStren'](13) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseTempAttack'](0) != -4 or m['wseTempAttack'](1) != -3 or m['wseTempAttack'](2) != -2 or m['wseTempAttack'](3) != -1 or m['wseTempAttack'](4) != -1 or m['wseTempAttack'](5) != 99 or m['wseTempAttack'](6) != 99 or m['wseTempAttack'](7) != 99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseTempAttack'](8) != 99 or m['wseTempAttack'](9) != -1 or m['wseTempAttack'](10) != -2 or m['wseTempAttack'](11) != -3 or m['wseTempAttack'](12) != -4 or m['wseTempAttack'](13) != 0 or m['wseWindMissilePb'](0) != 0 or m['wseWindMissilePb'](1) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseWindMissilePb'](2) != -1 or m['wseWindMissilePb'](3) != -2 or m['wseWindMissilePb'](4) != -4 or m['wseWindMissilePb'](5) != 99 or m['wseWindMissilePb'](6) != 0 or m['wseWindMissileMed'](0) != 0 or m['wseWindMissileMed'](1) != -2 or m['wseWindMissileMed'](2) != -3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseWindMissileMed'](3) != 99 or m['wseWindMissileMed'](4) != 99 or m['wseWindMissileMed'](5) != 99 or m['wseWindMissileMed'](6) != 0 or m['wseWindMissileLong'](0) != 0 or m['wseWindMissileLong'](1) != -3 or m['wseWindMissileLong'](2) != 99 or m['wseWindMissileLong'](3) != 99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wseWindMissileLong'](4) != 99 or m['wseWindMissileLong'](5) != 99 or m['wseWindMissileLong'](6) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R427: the WSG environment pin audit",
      "comment" = "The environment data slice pins Tables 4 and 5 (rules/wsg/wsgenvfx.h, prefix wse): Table 4 (the 13 temperature bands, the Str/Dex/Con reductions nonstrenuous/strenuous, the Land Move fractions, the Attack Rolls penalty) and Table 5 (the 6 wind bands, the missile adjustments with the xx impossible cells, the melee penalty, the move-against-wind fractions) verified cell for cell with the 99 censuses, the book own examples (the 105-degree strength, the -30 move, the 35-mph wind, the 85/40 greater reduction) and the precipitation shifts; census 352 -> 353.",
    },
}
