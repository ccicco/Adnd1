-- wam: promoted from tools/spec_r433.json (the The WSG LAND-BASED ANIMALS, R433: Table 13 (the encumbrance limits and movement rates for animals - the 18 rows from the ape to the yak x the normal load, the maximum load and the unencumbered/encumbered movement rates over normal, rugged and very rugged terrain) with the two-designation rules (the normal load is unencumbered, the maximum load still moves), the forced-move stamina rules (the hours equal half the rate, capped at 12; the cumulative fatigue chance 20/35/50 percent by terrain; the book own light and medium warhorse examples) and the accelerated no-rest +1/3 spillover from the Table 12 section (16 + 5 = 21) - the round continues the encumbrance-and-movement chapter. Census 357 -> 358.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 433,
  "prefix" = "wam",
  "banner" = {
      "title" = "The WSG LAND-BASED ANIMALS, R433: Table 13 (the encumbrance limits and movement rates for animals - the 18 rows from the ape to the yak x the normal load, the maximum load and the unencumbered/encumbered movement rates over normal, rugged and very rugged terrain) with the two-designation rules (the normal load is unencumbered, the maximum load still moves), the forced-move stamina rules (the hours equal half the rate, capped at 12; the cumulative fatigue chance 20/35/50 percent by terrain; the book own light and medium warhorse examples) and the accelerated no-rest +1/3 spillover from the Table 12 section (16 + 5 = 21) - the round continues the encumbrance-and-movement chapter. Census 357 -> 358.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 31-32; the user own copy OCR cross-checked against the archive djvu word layer (16 of 18 rows) and the IIIF full-resolution eye-reads (the Sheep and Yak rows and the light-war very-rugged cell, absent from the djvu text layer, read 250/500 9/6 6/3 6/3, 2250/3500 12/6 9/6 6/3 and 6/3 at full resolution); every number matched. The camel footnote markers point forward to the Mounts and Beasts of Burden section (out of this slice).",
      "sentinel" = "The Table 13 movement columns read unencumbered/encumbered: the left figure applies at the normal load or less, the right figure when encumbered (over the normal load up to the maximum); a 0 means the animal cannot move or be moved into that terrain under that encumbrance. The forced-move hours are the current rate over 2, up to 12; past that the fatigue chance is cumulative per hour.",
    },
  "consts" = { {
      "name" = "wamAnimalCount",
      "value" = 18,
      "comment" = "The Table 13 animal-row count.",
    }, {
      "name" = "wamForcedHoursDen",
      "value" = 2,
      "comment" = "An animal can be forced to move for hours equal to half its current movement rate (the denominator).",
    }, {
      "name" = "wamForcedHoursMax",
      "value" = 12,
      "comment" = "The forced-move window caps at 12 hours.",
    }, {
      "name" = "wamFatNormPct",
      "value" = 20,
      "comment" = "The cumulative fatigue chance per hour past the window, normal terrain.",
    }, {
      "name" = "wamFatRugPct",
      "value" = 35,
      "comment" = "The cumulative fatigue chance per hour, rugged terrain.",
    }, {
      "name" = "wamFatVrPct",
      "value" = 50,
      "comment" = "The cumulative fatigue chance per hour, very rugged terrain.",
    }, {
      "name" = "wamAccelNorestNum",
      "value" = 1,
      "comment" = "Keeping the accelerated pace without the rest stops adds 1/3 of the given amount (numerator).",
    }, {
      "name" = "wamAccelNorestDen",
      "value" = 3,
      "comment" = "The accelerated no-rest denominator (rounded to the nearest whole).",
    } },
  "bools" = { {
      "name" = "wamCharCategoriesDontApply",
      "value" = true,
      "comment" = "The character encumbrance categories do not apply to mounts and pack animals.",
    }, {
      "name" = "wamTwoDesignationsOnly",
      "value" = true,
      "comment" = "Only two designations matter for an animal: the normal load and the maximum load.",
    }, {
      "name" = "wamNormalLoadUnencumbered",
      "value" = true,
      "comment" = "The normal load is what an animal carries without being encumbered.",
    }, {
      "name" = "wamMaxLoadStillMoves",
      "value" = true,
      "comment" = "The maximum load is the greatest encumbrance the animal can carry and still be able or willing to move.",
    }, {
      "name" = "wamRateVariesWithTerrain",
      "value" = true,
      "comment" = "An animal's large-scale rate varies with terrain, as a character's does.",
    }, {
      "name" = "wamRateIndicatesStamina",
      "value" = true,
      "comment" = "The rate of a mount or beast of burden also indicates its stamina.",
    }, {
      "name" = "wamFatigueCumulative",
      "value" = true,
      "comment" = "The fatigue chance past the forced-move window is cumulative per hour.",
    }, {
      "name" = "wamLeftIsUnencumbered",
      "value" = true,
      "comment" = "The left figure of a slash pair is the rate at the normal load or less.",
    }, {
      "name" = "wamRightIsEncumbered",
      "value" = true,
      "comment" = "The right figure of a slash pair is the rate when encumbered, over the normal load up to the maximum.",
    }, {
      "name" = "wamZeroCannotMove",
      "value" = true,
      "comment" = "A 0 entry means the animal cannot move or be moved into that terrain under that encumbrance.",
    }, {
      "name" = "wamTableNotExhaustive",
      "value" = true,
      "comment" = "The table does not include every conceivable animal; an animal friendship or charm spell can work wonders.",
    }, {
      "name" = "wamDmComparesSimilarBeast",
      "value" = true,
      "comment" = "For a new animal the DM weighs its size, strength and rate and compares it to a similar listed beast (the tiger vs the yak).",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 13: the encumbrance limits and movement rates for animals",
      "tag" = "13",
      "count" = "wamAnimalCount",
      "cols" = { "wamNormLoad", "wamMaxLoad", "wamMvNormU", "wamMvNormE", "wamMvRugU", "wamMvRugE", "wamMvVrU", "wamMvVrE" },
      "col_default" = 0,
      "col_comments" = { "The normal load in gp by animal row (unencumbered at this or less).", "The maximum load in gp by animal row (the greatest load that still moves).", "The unencumbered rate, normal terrain (rows: ape, bear, bactrian, dromedary, dog sled, donkey, the African and Asiatic elephants, the draft, heavy-war, light-war, medium-war and wild horses, mule, pony, ram, sheep, yak).", "The encumbered rate, normal terrain.", "The unencumbered rate, rugged terrain.", "The encumbered rate, rugged terrain.", "The unencumbered rate, very rugged terrain (0 = cannot move there).", "The encumbered rate, very rugged terrain (0 = cannot move there)." },
      "data" = { { 2000, 4000, 12, 6, 9, 6, 6, 3 }, { 3000, 6000, 12, 6, 9, 6, 3, 0 }, { 4000, 6000, 18, 6, 9, 6, 3, 0 }, { 4000, 6000, 21, 9, 12, 6, 3, 0 }, { 3000, 6000, 12, 9, 6, 3, 0, 0 }, { 1500, 2500, 12, 6, 9, 6, 6, 3 }, { 5000, 10000, 15, 9, 9, 6, 0, 0 }, { 5000, 10000, 12, 9, 6, 6, 0, 0 }, { 4000, 8000, 12, 6, 6, 3, 3, 3 }, { 5000, 7500, 15, 9, 9, 6, 6, 3 }, { 3000, 5000, 24, 12, 12, 6, 6, 3 }, { 4000, 6500, 18, 9, 9, 6, 6, 3 }, { 3000, 6000, 24, 12, 12, 6, 6, 3 }, { 5000, 7500, 12, 6, 9, 6, 6, 3 }, { 2000, 3000, 12, 6, 6, 3, 3, 0 }, { 2500, 4000, 15, 9, 12, 9, 6, 3 }, { 250, 500, 9, 6, 6, 3, 6, 3 }, { 2250, 3500, 12, 6, 9, 6, 6, 3 } },
      "audit_comment" = "the Table 13 grid: the 18 animal rows x the normal and maximum loads and the unencumbered and encumbered rates over the three terrain classes",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wamMvNormU'](10) != 24",
      "note" = "the light warhorse, unencumbered, normal terrain: rate 24",
    }, {
      "expr" = "m['wamMvNormU'](10) / m['wamForcedHoursDen']() != 12",
      "note" = "the forced-move window: 24 over 2 = 12 hours without adverse effects",
    }, {
      "expr" = "m['wamFatNormPct']() * (13 - m['wamMvNormU'](10) / m['wamForcedHoursDen']()) != 20",
      "note" = "at the end of 13 hours: a 20 percent chance of fatigue",
    }, {
      "expr" = "m['wamFatNormPct']() * (14 - m['wamMvNormU'](10) / m['wamForcedHoursDen']()) != 40",
      "note" = "after 14 hours: the chance rises to 40 percent",
    }, {
      "expr" = "m['wamMvRugE'](11) != 6",
      "note" = "the medium warhorse, encumbered, rugged terrain: rate 6",
    }, {
      "expr" = "m['wamMvRugE'](11) / m['wamForcedHoursDen']() != 3",
      "note" = "the forced-move window: 6 over 2 = three consecutive hours without incident",
    }, {
      "expr" = "m['wamFatRugPct']() * (4 - m['wamMvRugE'](11) / m['wamForcedHoursDen']()) != 35",
      "note" = "at the end of four hours: a 35 percent chance of fatigue",
    }, {
      "expr" = "m['wamFatRugPct']() * (5 - m['wamMvRugE'](11) / m['wamForcedHoursDen']()) != 70",
      "note" = "after five hours: the chance rises to 70 percent",
    }, {
      "expr" = "m['wamFatRugPct']() * (6 - m['wamMvRugE'](11) / m['wamForcedHoursDen']()) != 105",
      "note" = "six hours: a 105 percent chance - fatigue is automatic",
    }, {
      "expr" = "2 * 16 * m['wamAccelNorestNum']() - 2 * 5 * m['wamAccelNorestDen']() < -m['wamAccelNorestDen']() or 2 * 16 * m['wamAccelNorestNum']() - 2 * 5 * m['wamAccelNorestDen']() > m['wamAccelNorestDen']()",
      "note" = "the accelerated pace kept up without the rest stops: 16 + 5 = 21 (the +1/3 of 16 rounded to the nearest whole is 5 - written division-free, the rounding inequality)",
    }, {
      "expr" = "m['wamMvNormU'](3) != 21",
      "note" = "the dromedary unencumbered normal rate: 21",
    }, {
      "expr" = "m['wamNormLoad'](17) != 2250",
      "note" = "the tiger comparison: the yak normal load is 2250 gp",
    } },
  "audit" = {
      "label" = "R433 WSG animals pin audit",
      "comment" = "The land-based animals slice pins Table 13 (the 18 mounts and beasts of burden x the normal and maximum loads and the unencumbered/encumbered rates over the three terrain classes), the forced-move stamina rules (the half-rate hour cap, the cumulative fatigue chances) and the accelerated no-rest spillover (rules/wsganimal.h, prefix wam); census 357 -> 358.",
    },
}
