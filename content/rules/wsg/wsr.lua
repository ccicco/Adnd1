-- wsr: promoted from tools/spec_r440.json (the The WSG USING ROPE FOR MOVEMENT AND CLIMBING, R440: the rope prose (no table this round) - characters are not expected to climb slopes or cliff faces relying only on the strength and dexterity of their hands and feet; certain equipment is available and often necessary for a severe slope or a cliff face, and the single most important equipment any climber can have is a coil of rope. The standard 50-foot coil is assumed somewhat smaller than half an inch in diameter and supports up to 1500 pounds without danger of fraying or breaking; if the limit is exceeded there is a 20 percent chance per turn (non-cumulative, while the strain remains) that it breaks; if it does not break, the cumulative chance it has become weakened from the stress is 10 percent after one turn, 30 after two, 60 after three and 100 after four; a weakened rope breaks the next time it supports more than its limit at 40 percent per turn (non-cumulative) - the round continues the movement-across-special-terrain section. Census 364 -> 365.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 440,
  "prefix" = "wsr",
  "banner" = {
      "title" = "The WSG USING ROPE FOR MOVEMENT AND CLIMBING, R440: the rope prose (no table this round) - characters are not expected to climb slopes or cliff faces relying only on the strength and dexterity of their hands and feet; certain equipment is available and often necessary for a severe slope or a cliff face, and the single most important equipment any climber can have is a coil of rope. The standard 50-foot coil is assumed somewhat smaller than half an inch in diameter and supports up to 1500 pounds without danger of fraying or breaking; if the limit is exceeded there is a 20 percent chance per turn (non-cumulative, while the strain remains) that it breaks; if it does not break, the cumulative chance it has become weakened from the stress is 10 percent after one turn, 30 after two, 60 after three and 100 after four; a weakened rope breaks the next time it supports more than its limit at 40 percent per turn (non-cumulative) - the round continues the movement-across-special-terrain section. Census 364 -> 365.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 36; the user own copy OCR cross-checked against the archive djvu word layer - the section reads CLEAN in the djvu, every number (the 50-foot coil, the 1500 pounds, the 20 percent, the 10/30/60/100 ladder and the 40 percent) matched exactly; no eye-reads were needed.",
      "sentinel" = "The standard 50-foot coil supports up to 1500 pounds without danger of fraying or breaking. Past the limit the break chance is 20 percent per turn non-cumulative; the weakening chance is cumulative - 10/30/60/100 percent by the turn of strain - and a weakened rope breaks at 40 percent per turn non-cumulative.",
    },
  "consts" = { {
      "name" = "wsrCoilLengthFt",
      "value" = 50,
      "comment" = "The standard coil of rope is 50 feet long - the single most important equipment any climber can have.",
    }, {
      "name" = "wsrMaxLoadLbs",
      "value" = 1500,
      "comment" = "A rope of the standard diameter can support up to 1500 pounds without being in danger of fraying or breaking.",
    }, {
      "name" = "wsrOverloadBreakPct",
      "value" = 20,
      "comment" = "If the weight limit is exceeded, there is a 20 percent chance per turn (non-cumulative), while the strain remains on the rope, that it will break.",
    }, {
      "name" = "wsrWeakenedBreakPct",
      "value" = 40,
      "comment" = "The chance of a weakened rope breaking the next time it is used to support more than its weight limit is 40 percent per turn (non-cumulative).",
    } },
  "bools" = { {
      "name" = "wsrNotHandsAndFeetAlone",
      "value" = true,
      "comment" = "Characters are not expected to climb slopes or cliff faces while relying only on the strength and dexterity of their hands and feet.",
    }, {
      "name" = "wsrEquipmentOftenNecessary",
      "value" = true,
      "comment" = "Certain equipment is available (and often necessary) to assist a character in climbing a severe slope or a cliff face.",
    }, {
      "name" = "wsrRopeMostImportant",
      "value" = true,
      "comment" = "The single most important equipment any climber can have is a coil of rope.",
    }, {
      "name" = "wsrCoilUnderHalfInch",
      "value" = true,
      "comment" = "The standard 50-foot coil of rope is assumed to be somewhat smaller than half an inch in diameter.",
    }, {
      "name" = "wsrOverloadBreakNonCumulative",
      "value" = true,
      "comment" = "The overload break chance is per turn and non-cumulative, applying while the strain remains on the rope.",
    }, {
      "name" = "wsrWeakenCumulativePerTurn",
      "value" = true,
      "comment" = "If the overloaded rope does not break, there is a 10 percent chance, cumulative per turn, that it has become weakened from the stress.",
    }, {
      "name" = "wsrWeakenedBreakNonCumulative",
      "value" = true,
      "comment" = "The weakened-rope break chance is per turn and non-cumulative, applying the next time the rope is used to support more than its weight limit.",
    } },
  "switches" = { {
      "name" = "wsrWeakenPct",
      "values" = { 0, 10, 30, 60, 100 },
      "default" = 100,
      "comment" = "The cumulative chance a rope strained past its weight limit has become weakened, by turns of strain: 0 at the start, 10 percent after one turn, 30 after two, 60 after three, 100 after four - and it stays 100 beyond that.",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wsrCoilLengthFt']() != 50 or m['wsrMaxLoadLbs']() != 1500",
      "note" = "the standard coil: 50 feet of rope supporting up to 1500 pounds without fraying or breaking",
    }, {
      "expr" = "m['wsrWeakenPct'](1) != 10 or m['wsrWeakenPct'](2) != 30 or m['wsrWeakenPct'](3) != 60 or m['wsrWeakenPct'](4) != 100",
      "note" = "the cumulative weakening ladder: 10 percent after one turn of strain, 30 after two, 60 after three, 100 after four",
    }, {
      "expr" = "m['wsrOverloadBreakPct']() * 2 != m['wsrWeakenedBreakPct']()",
      "note" = "the two break chances: the weakened rope breaks at 40 percent per turn - twice the 20 percent overload break chance of a healthy rope",
    } },
  "audit" = {
      "label" = "R440 WSG rope use pin audit",
      "comment" = "The rope-use slice pins the standard 50-foot coil (the most important climbing equipment), the 1500-pound support limit, the 20 percent per-turn non-cumulative overload break chance, the cumulative 10/30/60/100 weakening ladder and the 40 percent weakened-rope break chance (rules/wsg/wsgrope.h, prefix wsr); census 364 -> 365.",
    },
}
