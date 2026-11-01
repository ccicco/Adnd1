-- ua374: promoted from rules/uatreasuredial.h (the The UA TREASURE DIAL decision);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 374,
  "prefix" = "ua374",
  "banner" = {
      "title" = "The UA TREASURE DIAL decision",
      "provenance" = "pins, R374: THE DECISION named in the gap report's treasure section (the UA random determination tables III.A through III.H REPLACE the DMG tables) resolves RUN BOTH - the engine carries the DMG and UA tables as switchable alternatives behind a dial and lets playtesting pick. The per-source precedent rides the monster file format. The UA pin rounds follow; the dial lands first, the charge after. The R219 and R220 seams ride the regtest audit, not here.",
    },
  "consts" = { {
      "name" = "uatdModeDmg",
      "value" = 0,
      "comment" = "---- the dial modes ---- DMG: the landed audits stay authoritative (the default until the UA pin rounds land).",
    }, {
      "name" = "uatdModeUa",
      "value" = 1,
      "comment" = "UA: the revised tables.",
    }, {
      "name" = "uatdModeMerged",
      "value" = 2,
      "comment" = "MERGED: both table sets with the union rows.",
    }, {
      "name" = "uatdModeCount",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uatdDmgAuditRoundFirst",
      "value" = 219,
      "comment" = "The audit rounds span R219 through R287.",
    }, {
      "name" = "uatdDmgAuditRoundLast",
      "value" = 287,
      "comment" = "",
    }, {
      "name" = "uatdTableSetCount",
      "value" = 2,
      "comment" = "---- the carrier contract ---- Both table sets ride: DMG and UA.",
    } },
  "bools" = { {
      "name" = "uatdRunBothDecided",
      "value" = true,
      "comment" = "---- the decision ---- RUN BOTH - decided.",
    }, {
      "name" = "uatdUaTablesReplaceDmg",
      "value" = true,
      "comment" = "The printed fact: the UA tables replace the DMG tables.",
    }, {
      "name" = "uatdDmgAuditsAuthoritative",
      "value" = true,
      "comment" = "The seventy landed DMG audits stay authoritative.",
    }, {
      "name" = "uatdMonsterFileTracksSource",
      "value" = true,
      "comment" = "The monster file format already tracks source per record - the per-source precedent.",
    }, {
      "name" = "uatdPlaytestingPicks",
      "value" = true,
      "comment" = "Playtesting picks.",
    }, {
      "name" = "uatdUaPinRoundsPending",
      "value" = false,
      "comment" = "R402: the UA pin rounds HAVE landed (R375, R395, R397) - the dial rides; the charge follows.",
    }, {
      "name" = "uatdMergedCarriesBoth",
      "value" = true,
      "comment" = "The MERGED mode carries both.",
    }, {
      "name" = "uatdDialLanded",
      "value" = true,
      "comment" = "R402: the dial governs the random determination dispatch (the magic item roll); the landed DMG audits stay authoritative under the default mode.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uatdDefaultMode",
      "comment" = "The default mode: DMG.",
      "kind" = "header pin",
      "body" = "return uatdModeDmg();",
    }, {
      "name" = "uatdModeRef",
      "comment" = "---- R402: the runtime dial ---- The mode state rides a static (the DMG default until playtesting picks); the setter gates on the validity.",
      "kind" = "header pin",
      "body" = "static int m = uatdDefaultMode(); return m;",
    }, {
      "name" = "uatdMode",
      "comment" = "The current dial mode.",
      "kind" = "header pin",
      "body" = "return uatdModeRef();",
    }, {
      "name" = "uatdModeValid",
      "comment" = "",
      "kind" = "header pin",
      "body" = "return m >= 0 && m < uatdModeCount();",
    }, {
      "name" = "uatdSetMode",
      "comment" = "Set the dial (an invalid ask falls back to the default).",
      "kind" = "header pin",
      "body" = "if (!uatdModeValid(m)) m = uatdDefaultMode(); uatdModeRef() = m;",
    }, {
      "name" = "uatdModeName",
      "comment" = "",
      "kind" = "string array",
      "count" = 3,
      "values" = { "DMG", "UA", "MERGED" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uatdModeDmg']() != 0  or m['uatdModeUa']() != 1  or m['uatdModeMerged']() != 2  or m['uatdModeCount']() != 3  or m['uatdDefaultMode']() !=m['uatdModeDmg']()  or  m['uatdRunBothDecided']() != 1  or  m['uatdUaTablesReplaceDmg']() != 1  or  m['uatdDmgAuditsAuthoritative']() != 1  or m['uatdDmgAuditRoundFirst']() != 219  or m['uatdDmgAuditRoundLast']() != 287  or  m['uatdMonsterFileTracksSource']() != 1  or  m['uatdPlaytestingPicks']() != 1  or m['uatdUaPinRoundsPending']()  or m['uatdTableSetCount']() != 2  or  m['uatdMergedCarriesBoth']() != 1",
      "note" = "---- the dial pins ----",
    }, {
      "expr" = "m['mapOrMagicIsMap'](1) != 1  or m['mapOrMagicIsMap'](10) != 1  or m['mapOrMagicIsMap'](11) != 0  or m['mapOrMagicIsMap'](100) != 0",
      "note" = "---- the R219 seam ----",
    }, {
      "expr" = "m['hoardBandCount']() != 10  or m['hoardBandOfRoll'](1) != 0  or m['hoardBandOfRoll'](20) != 0  or m['hoardBandOfRoll'](21) != 1  or m['hoardBandOfRoll'](55) != 2  or m['hoardBandOfRoll'](100) != 9  or  m['hoardMustBeHiddenTrappedGuarded']() != 1  or  m['hoardDistantPlaces']() != 1",
      "note" = "---- the R220 seam ----",
    } },
  "audit" = {
      "label" = "R374: the UA treasure dial pin audit",
      "comment" = "THE DECISION round: the UA random determination tables III.A through III.H REPLACE the DMG tables; the engine carries both as switchable alternatives behind a dial (DMG / UA / MERGED) and playtesting picks. The DMG mode stays the default - the seventy landed audits remain authoritative until the UA pin rounds land. The R219 seam cross-checks the map table bands; the R220 seam the hoard bands; no item flips this round - the decision record lands; the census 300 -> 301.",
    },
}
