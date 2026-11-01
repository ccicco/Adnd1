-- wdm: promoted from tools/spec_r477.json (the R477: the WSG DAMAGE FROM FIRE slice, printed p. 68 - the seventh camping-arc round, closing the camping-arc FIRE chapter by riding the uncontrollable-fires seam unpinned by R476 (whose round stopped at the fleeing prose): the advance and firebreak prose (an uncontrollable fire advances at one-half of the wind velocity or 5 mph in any case; a trot stays ahead in calm air or a light breeze; the firebreak of churned and cleared ground with dig and move earth and the 18-strength spade of colossal excavation; the cut-the-blaze-in-half ruling; the cleared-area refuge with its too-close peril), the engulfment rule (10-15 points of damage, 1d6+9, per round, cut in half rounded up on a successful Constitution Check with a +4 modifier to the die roll, with burn damage equal to one-third of the full normal hit-point total rendering the victim unconscious and ending his Constitution Checks), the brief-contact rule (1d8 points for leaping through a wall of fire, saves versus normal fire for every major item, 1d3 additional points per round per burning item until extinguished or discarded, the Wisdom Check to stay calm, hit the ground and roll, and the panic run at top speed in a random direction taking 1d4 per round until caught), and the extreme-heat rule (closer than 5 feet to a large fire or 3 feet to a medium fire counts as 120 degrees or higher per the Temperature Damage to Characters Table, with the activity-level adjustments waived), printed p. 68.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 477,
  "prefix" = "wdm",
  "banner" = {
      "title" = "R477: the WSG DAMAGE FROM FIRE slice, printed p. 68 - the seventh camping-arc round, closing the camping-arc FIRE chapter by riding the uncontrollable-fires seam unpinned by R476 (whose round stopped at the fleeing prose): the advance and firebreak prose (an uncontrollable fire advances at one-half of the wind velocity or 5 mph in any case; a trot stays ahead in calm air or a light breeze; the firebreak of churned and cleared ground with dig and move earth and the 18-strength spade of colossal excavation; the cut-the-blaze-in-half ruling; the cleared-area refuge with its too-close peril), the engulfment rule (10-15 points of damage, 1d6+9, per round, cut in half rounded up on a successful Constitution Check with a +4 modifier to the die roll, with burn damage equal to one-third of the full normal hit-point total rendering the victim unconscious and ending his Constitution Checks), the brief-contact rule (1d8 points for leaping through a wall of fire, saves versus normal fire for every major item, 1d3 additional points per round per burning item until extinguished or discarded, the Wisdom Check to stay calm, hit the ground and roll, and the panic run at top speed in a random direction taking 1d4 per round until caught), and the extreme-heat rule (closer than 5 feet to a large fire or 3 feet to a medium fire counts as 120 degrees or higher per the Temperature Damage to Characters Table, with the activity-level adjustments waived), printed p. 68.",
      "provenance" = "Ground truth two-way clean on every number, no contested cells, no physical-page reads: the user-run Termux tesseract text of printed p. 68 (p68_full.txt, p68_tsv.tsv) vs the pdf embedded text layer (pdftotext -layout, pdf page 69, p68_pdfy.txt). The two readers AGREE on all prose numbers: the half-wind advance with the 5-mph floor, the 10-15 engulf damage as 1d6+9 with the +4 Constitution Check modifier and the halved-rounded-up reduction, the one-third unconscious threshold, the 1d8 brief contact, the 1d3 per burning item, the 1d4 panic damage, the 5-foot large and 3-foot medium heat distances at 120 degrees, and the 18-strength spade of colossal excavation. The page carries NO table, so no vision-on-png settler was needed; the printed-page-68 offset against pdf page 69 was confirmed at extraction time per the R476 lesson.",
      "sentinel" = "All prose numbers of printed p. 68 pinned (the advance speed, the engulf damage range with its check modifier, the unconscious threshold, the contact dice, the heat distances and temperature); the firebreak, refuge, panic and adjudication prose are audit examples.",
    },
  "consts" = { {
      "name" = "wdmAdvanceWindDiv",
      "value" = 2,
      "comment" = "an uncontrollable fire advances at one-half of the wind velocity",
    }, {
      "name" = "wdmAdvanceMinMph",
      "value" = 5,
      "comment" = "the fire advances at a speed of 5 mph in any case",
    }, {
      "name" = "wdmEngulfDice",
      "value" = 1,
      "comment" = "a character engulfed in flames rolls 1d6",
    }, {
      "name" = "wdmEngulfDieSides",
      "value" = 6,
      "comment" = "the engulf damage die is d6",
    }, {
      "name" = "wdmEngulfBonus",
      "value" = 9,
      "comment" = "the engulf damage bonus is +9",
    }, {
      "name" = "wdmEngulfMinDmg",
      "value" = 10,
      "comment" = "engulfment deals 10-15 points of damage per round",
    }, {
      "name" = "wdmEngulfMaxDmg",
      "value" = 15,
      "comment" = "the top of the 10-15 engulf damage range",
    }, {
      "name" = "wdmConCheckMod",
      "value" = 4,
      "comment" = "the Constitution Check to halve engulf damage takes a +4 modifier to the die roll",
    }, {
      "name" = "wdmHalveDivisor",
      "value" = 2,
      "comment" = "the engulf damage is cut in half, rounded up, on a successful Constitution Check",
    }, {
      "name" = "wdmUnconsciousNum",
      "value" = 1,
      "comment" = "burn damage equal to one-third of the full normal hit-point total renders the victim unconscious",
    }, {
      "name" = "wdmUnconsciousDen",
      "value" = 3,
      "comment" = "the unconscious threshold denominator is one-third",
    }, {
      "name" = "wdmBriefDieSides",
      "value" = 8,
      "comment" = "brief contact with a fire, such as leaping through a wall of fire, deals 1d8 points of damage",
    }, {
      "name" = "wdmItemBurnDieSides",
      "value" = 3,
      "comment" = "every major item that catches fire adds 1d3 points of damage per round",
    }, {
      "name" = "wdmPanicDieSides",
      "value" = 4,
      "comment" = "a panicked character takes 1d4 points of damage per round until caught and helped",
    }, {
      "name" = "wdmHeatLargeFt",
      "value" = 5,
      "comment" = "closer than 5 feet to a large fire exposes the character to extreme heat",
    }, {
      "name" = "wdmHeatMediumFt",
      "value" = 3,
      "comment" = "closer than 3 feet to a medium fire exposes the character to extreme heat",
    }, {
      "name" = "wdmHeatTempDegrees",
      "value" = 120,
      "comment" = "the heat exposure counts as a temperature of 120 degrees or higher",
    } },
  "bools" = { {
      "name" = "wdmTrotStaysAhead",
      "value" = true,
      "comment" = "in calm air or a light breeze a man or animal moving at a trot can stay safely ahead of the flames",
    }, {
      "name" = "wdmFirebreakClears",
      "value" = true,
      "comment" = "a firebreak is an area of ground in the path of the fire churned up and cleared to remove most or all of the combustible material",
    }, {
      "name" = "wdmDigMoveEarthHelp",
      "value" = true,
      "comment" = "spells such as dig and move earth are helpful in building a firebreak",
    }, {
      "name" = "wdmSpadeCanKillFire",
      "value" = true,
      "comment" = "a party containing a fighter with 18 strength and a spade of colossal excavation may be able to kill a fire with a firebreak",
    }, {
      "name" = "wdmFirebreakCutsInHalf",
      "value" = true,
      "comment" = "a single firebreak that cannot extinguish a very extensive fire can be used to cut the blaze in half, leaving two smaller fires",
    }, {
      "name" = "wdmClearedAreaRefuge",
      "value" = true,
      "comment" = "characters without the means to extinguish an uncontrollable blaze may save themselves by clearing an area and remaining in that spot while the fire burns around them",
    }, {
      "name" = "wdmRefugeStillRisky",
      "value" = true,
      "comment" = "characters in a cleared area may still suffer damage from heat or flames if they do not clear a large enough space and the fire gets too close",
    }, {
      "name" = "wdmFireNotAlwaysLethal",
      "value" = true,
      "comment" = "in heroic fantasy direct exposure to fire is not always lethal, but it is not to be taken lightly",
    }, {
      "name" = "wdmEngulfRequiresImmersion",
      "value" = true,
      "comment" = "the engulf rule applies only when the victim is fully within a fire or when most of the surface of his body, clothing and gear, is actually aflame",
    }, {
      "name" = "wdmHalvedRoundedUp",
      "value" = true,
      "comment" = "the successful Constitution Check cuts the engulf damage in half, rounded up",
    }, {
      "name" = "wdmUnconsciousLosesChecks",
      "value" = true,
      "comment" = "a character who suffers burn damage equal to one-third of his full normal hit points is rendered unconscious and is no longer allowed Constitution Checks to offset part of the damage",
    }, {
      "name" = "wdmItemsSaveVsFire",
      "value" = true,
      "comment" = "on brief contact with fire every major piece of clothing or equipment carried must save versus normal fire to avoid being ignited",
    }, {
      "name" = "wdmItemBurnPerRound",
      "value" = true,
      "comment" = "for every major item that catches fire the character suffers additional damage per round until the flame is extinguished or the item is discarded",
    }, {
      "name" = "wdmWisCheckAvoids",
      "value" = true,
      "comment" = "a character whose gear catches fire can avoid damage with a successful Wisdom Check: remaining calm, hitting the ground and rolling",
    }, {
      "name" = "wdmPanicRuns",
      "value" = true,
      "comment" = "an unsuccessful Wisdom Check means the character has panicked: he runs at top speed in a random direction, away from the fire if possible",
    }, {
      "name" = "wdmPanicUntilCaught",
      "value" = true,
      "comment" = "the panicked character takes damage per round until another character catches him and helps put out the flames",
    }, {
      "name" = "wdmHeatNeedsNoContact",
      "value" = true,
      "comment" = "a character need not be in direct contact with fire to be hurt by it: at short distances extreme heat can be almost as damaging as actual fire",
    }, {
      "name" = "wdmHeatIgnoresActivity",
      "value" = true,
      "comment" = "near a fire the damage adjustments for level of activity do not apply: the inactive take just as much heat damage as the strenuous",
    }, {
      "name" = "wdmHeatTableRef",
      "value" = true,
      "comment" = "the extreme-heat exposure uses the Temperature Damage to Characters Table from the Effects of the Environment section",
    }, {
      "name" = "wdmBeyondSafeButHot",
      "value" = true,
      "comment" = "beyond the given distances the character is relatively safe but may still suffer damage from exposure to extremely high temperatures per the table",
    }, {
      "name" = "wdmDmAdjudicatesUncovered",
      "value" = true,
      "comment" = "situations not covered by these rules call for reasonable Dungeon Master rulings on the amount of damage and the chance of avoiding it",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the advance speed: one-half of the wind velocity, or 5 mph in any case",
      "expr" = "m['wdmAdvanceWindDiv']() != 2 or m['wdmAdvanceMinMph']() != 5 or m['wdmAdvanceWindDiv']() < 1",
    }, {
      "note" = "the engulf damage is 10-15 points of 1d6 + 9 per round",
      "expr" = "m['wdmEngulfDice']() != 1 or m['wdmEngulfDieSides']() != 6 or m['wdmEngulfBonus']() != 9 or m['wdmEngulfMinDmg']() != m['wdmEngulfDice']() + m['wdmEngulfBonus']() or m['wdmEngulfMaxDmg']() != m['wdmEngulfDieSides']() + m['wdmEngulfBonus']() or m['wdmEngulfMinDmg']() != 10 or m['wdmEngulfMaxDmg']() != 15",
    }, {
      "note" = "the halving rule: cut in half rounded up on a successful Constitution Check with a +4 modifier",
      "expr" = "m['wdmConCheckMod']() != 4 or m['wdmHalveDivisor']() != 2",
    }, {
      "note" = "the unconscious threshold is exactly one-third of the full normal hit points",
      "expr" = "m['wdmUnconsciousNum']() != 1 or m['wdmUnconsciousDen']() != 3 or m['wdmUnconsciousNum']() >= m['wdmUnconsciousDen']()",
    }, {
      "note" = "the contact damage dice: 1d8 brief contact, 1d3 per burning item, 1d4 while panicked",
      "expr" = "m['wdmBriefDieSides']() != 8 or m['wdmItemBurnDieSides']() != 3 or m['wdmPanicDieSides']() != 4",
    }, {
      "note" = "the heat distances: 5 feet for a large fire, 3 feet for a medium fire, at a temperature of 120 degrees or higher",
      "expr" = "m['wdmHeatLargeFt']() != 5 or m['wdmHeatMediumFt']() != 3 or m['wdmHeatTempDegrees']() != 120 or m['wdmHeatMediumFt']() >= m['wdmHeatLargeFt']()",
    } },
  "audit" = {
      "label" = "R477 WSG damage from fire pin audit",
      "comment" = "The firebreak and advance prose (the half-wind or 5-mph advance, the trot escape, the firebreak with dig and move earth, the cut-in-half ruling, the cleared-area refuge), the engulfment rule (the 1d6+9 10-15 damage with the halved-rounded-up +4 Constitution Check and the one-third unconscious bar), the brief-contact rule (the 1d8 contact damage, the versus-normal-fire item saves, the 1d3 per burning item, the Wisdom Check calm-and-roll against the panic run with 1d4 per round), and the extreme-heat rule (5 feet large, 3 feet medium, 120 degrees, no activity adjustments) are audit examples.",
    },
}
