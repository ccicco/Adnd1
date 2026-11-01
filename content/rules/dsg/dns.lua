-- dns: promoted from tools/spec_r516.json (the The DSG STRUCTURAL DECAY, R516: printed p. 43 (pdf 44) - the underground environment inflicting relatively swift decay upon wooden structures, the typical-location assumption of very humid air, the almost-completely-dry areas where wooden objects decay at a mere 2 or 3% of the given rate, the 1d6-year rot onset for anything made of wood and kept underground, the creosote-or-sealant doubling of the onset period, the 5% chance of collapse per multiple of the onset roll that passes with the roll-1 structure at 5% per year and a 20-year maximum (100%) and the roll-6 structure lasting as much as 120 years, the check whenever any activity puts unusual stress upon the structure, and the d100 roll against the percentage chance of collapse);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 516,
  "prefix" = "dns",
  "banner" = {
      "title" = "The DSG STRUCTURAL DECAY, R516: printed p. 43 (pdf 44) - the underground environment inflicting relatively swift decay upon wooden structures, the typical-location assumption of very humid air, the almost-completely-dry areas where wooden objects decay at a mere 2 or 3% of the given rate, the 1d6-year rot onset for anything made of wood and kept underground, the creosote-or-sealant doubling of the onset period, the 5% chance of collapse per multiple of the onset roll that passes with the roll-1 structure at 5% per year and a 20-year maximum (100%) and the roll-6 structure lasting as much as 120 years, the check whenever any activity puts unusual stress upon the structure, and the d100 roll against the percentage chance of collapse",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR (djvu.txt lines ~5500-5525) with the pdf Acrobat-Capture layer as the second read (idx 62 = printed p. 43) - every number dual-confirmed: the 2 or 3% dry band, the 1d6-year rot onset (the djvu garble 146 = 1d6 settled by the Capture read), the creosote doubling, the 5%-per-multiple collapse chance with the roll-1 = 20-year and roll-6 = 120-year worked examples, and the stress check made with a d100 roll (the djvu garble 4100 = d100). The Underground Waterways section starts the NEXT round per the content-density rule.",
      "sentinel" = "No table in this section - the pins are consts and bools only. The 1d6 rot onset pins as dice + sides consts per the R508 convention. The collapse math stays prose: the 20-year and 120-year worked examples pin as consts but the engine multiplies nothing - nothing auto-credits.",
    },
  "consts" = { {
      "name" = "dnsDryRateLowPct",
      "value" = 2,
      "comment" = "in subterranean areas that are almost completely dry, the decay of wooden objects is a mere 2 or 3% of the rate given.",
    }, {
      "name" = "dnsDryRateHighPct",
      "value" = 3,
      "comment" = "the high end of the almost-completely-dry decay band: a mere 2 or 3% of the typical humid rate (the djvu garble class: 2 or 3% reads clean).",
    }, {
      "name" = "dnsRotOnsetYearsDice",
      "value" = 1,
      "comment" = "anything made out of wood and kept underground begins to show signs of rot after 1d6 years - the dice of the onset roll (the djvu garble 146 = 1d6, settled by the Capture read).",
    }, {
      "name" = "dnsRotOnsetYearsSides",
      "value" = 6,
      "comment" = "the sides of the 1d6-year rot-onset roll, pinned as dice + sides consts per the R508 convention.",
    }, {
      "name" = "dnsCreosotePeriodMultiplier",
      "value" = 2,
      "comment" = "if the wood is soaked in creosote or some other sealing substance, this period is doubled.",
    }, {
      "name" = "dnsCollapseChancePerMultiplePct",
      "value" = 5,
      "comment" = "the rot creates a 5% chance of collapse for each multiple of the 1d6 onset roll that passes.",
    }, {
      "name" = "dnsRollOneMaxYears",
      "value" = 20,
      "comment" = "if the first roll was a 1, there is a 5% chance of collapse every year, and the structure would last a maximum of 20 years (at which time the chance of collapse is 100%).",
    }, {
      "name" = "dnsRollSixMaxYears",
      "value" = 120,
      "comment" = "if the original roll was a 6, however, the structure might last as much as 120 years (6 multiples x the 5% ladder).",
    } },
  "bools" = { {
      "name" = "dnsHumidAirAssumed",
      "value" = true,
      "comment" = "the underground environment inflicts relatively swift decay upon wooden structures; the effects assume the presence of very humid air, the typical underground location.",
    }, {
      "name" = "dnsDryAreasMereFractionOfRate",
      "value" = true,
      "comment" = "in almost completely dry subterranean areas the wooden decay runs at a mere 2 or 3% of the given rate.",
    }, {
      "name" = "dnsCreosoteOrSealantDoubles",
      "value" = true,
      "comment" = "creosote or some other sealing substance doubles the rot-onset period.",
    }, {
      "name" = "dnsCollapseChancePerMultipleOfOnset",
      "value" = true,
      "comment" = "the collapse chance accrues per multiple of the 1d6 onset roll that passes - the roll sets both the interval and the lifetime.",
    }, {
      "name" = "dnsCheckOnUnusualStress",
      "value" = true,
      "comment" = "the wooden structure should be checked whenever any activity puts unusual stress upon it.",
    }, {
      "name" = "dnsStressCheckIsD100",
      "value" = true,
      "comment" = "the check is made with a d100 roll (the djvu garble 4100 = d100, settled by the Capture read) against the percentage chance of collapse for the structure.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnsDryRateLowPct']() != 2 or m['dnsDryRateHighPct']() != 3",
      "note" = "the dry-area band: almost completely dry areas decay at a mere 2 or 3% of the typical humid rate.",
    }, {
      "expr" = "m['dnsRotOnsetYearsDice']() != 1 or m['dnsRotOnsetYearsSides']() != 6 or m['dnsCreosotePeriodMultiplier']() != 2",
      "note" = "the rot onset: wooden things underground show rot after 1d6 years, doubled to 2d6 by creosote or another sealing substance (the djvu garble 146 = 1d6).",
    }, {
      "expr" = "m['dnsCollapseChancePerMultiplePct']() != 5 or m['dnsRollOneMaxYears']() != 20 or m['dnsRollSixMaxYears']() != 120",
      "note" = "the collapse ladder: 5% per multiple of the onset roll - the roll-1 structure reaches 100% at 20 years, the roll-6 structure might last 120 years.",
    } },
  "audit" = {
      "label" = "R516 DSG structural decay audit",
      "comment" = "The DSG structural decay pins the wooden-structure aging rules (the relatively swift decay of the underground environment, the very-humid-air assumption of the typical location, the almost-completely-dry areas at a mere 2 or 3% of the given rate, the 1d6-year rot onset for anything made of wood and kept underground, the creosote-or-sealant doubling of the period, the 5% chance of collapse per multiple of the onset roll that passes, the roll-1 example at 5% per year with the 20-year maximum and 100% collapse, the roll-6 example lasting as much as 120 years, the check whenever any activity puts unusual stress upon the structure, and the d100 roll against the percentage chance of collapse).",
    },
}
