-- rmz: promoted from tools/spec_r890.json (the The Remorhaz lore pin - the issue-2 opener (folio 21): the original 1976 Creature Features appearance, pinned as lore against the existing MM1 def);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 890,
  "prefix" = "rmz",
  "banner" = {
      "title" = "The Remorhaz lore pin - the issue-2 opener (folio 21): the original 1976 Creature Features appearance, pinned as lore against the existing MM1 def",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 2 (August 1976): folio 21, Creature Features - the Remorhaz, the original appearance ahead of the MM1 def. The voice rides extract/dragon/002/ (all 32 issue pages) plus the pre-flip tools/reports/dragon_gap_report_002.md (4 boxes, 0 closed), both shipped as spec data files. OD&D-era ink converted per the walk doctrine: the pin IS the conversion, noted, never silent.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon. The Remorhaz pins are lore/provenance only - the MM1 def monsters/monsters/r/remorhaz.lua is untouched and holds the stem, no competing def ever. The divergences ride noted, never silent: his bite 3-36 vs the def's 6-36, his 6/10/14 hit-dice bands on d8 vs the def's 7-14, his fire-breathing wings (3/5/7 dice) where the MM1 polar worm beats its wings but breathes no fire, his low intelligence vs the def's animal, and his 30-foot length vs the def's 21-42.",
    },
  "consts" = { {
      "name" = "rmzHdSmall",
      "value" = 6,
      "comment" = "the small size - 6 hit dice at 01-40 percent, d8 (folio 21); the def's ladder starts at 7 - the divergence noted",
    }, {
      "name" = "rmzHdMid",
      "value" = 10,
      "comment" = "the middle size - 10 hit dice at 41-75 percent (folio 21)",
    }, {
      "name" = "rmzHdLarge",
      "value" = 14,
      "comment" = "the large size - 14 hit dice at 76-00 percent, d8 (folio 21); the def tops at 14 too",
    }, {
      "name" = "rmzHdDie",
      "value" = 8,
      "comment" = "all sizes roll 8-sided hit dice (folio 21)",
    }, {
      "name" = "rmzSmallPct",
      "value" = 40,
      "comment" = "01-40 percent - the 6-die encounter chance (folio 21)",
    }, {
      "name" = "rmzMidPct",
      "value" = 35,
      "comment" = "41-75 percent - the 10-die encounter chance (folio 21)",
    }, {
      "name" = "rmzLargePct",
      "value" = 25,
      "comment" = "76-00 percent - the 14-die encounter chance (folio 21)",
    }, {
      "name" = "rmzLenFeet",
      "value" = 30,
      "comment" = "30 feet long - blue hued underneath, wings and head backed with red (folio 21); the def reads 21-42 - the divergence noted",
    }, {
      "name" = "rmzMoveInches",
      "value" = 12,
      "comment" = "movement 12 inches (folio 21) - the def agrees",
    }, {
      "name" = "rmzPctInLair",
      "value" = 20,
      "comment" = "20 percent in lair, treasure type F (folio 21) - the def agrees",
    }, {
      "name" = "rmzMagResPct",
      "value" = 75,
      "comment" = "75 percent magic resistance, low intelligence, neutral, 1 appearing (folio 21)",
    }, {
      "name" = "rmzAcUnderside",
      "value" = 4,
      "comment" = "armor class: underside 4 (folio 21) - the def agrees",
    }, {
      "name" = "rmzAcBack",
      "value" = 0,
      "comment" = "armor class: back 0 plus special - the heated protrusions (folio 21)",
    }, {
      "name" = "rmzAcHead",
      "value" = 2,
      "comment" = "armor class: head 2 (folio 21) - the def agrees on all three",
    }, {
      "name" = "rmzBiteMin",
      "value" = 3,
      "comment" = "the bite, 3-36 points (folio 21) - the def reads 6-36, the divergence noted, never silent",
    }, {
      "name" = "rmzBiteMax",
      "value" = 36,
      "comment" = "the bite's top end, 36 points (folio 21)",
    }, {
      "name" = "rmzBreathMinDice",
      "value" = 3,
      "comment" = "the fire breath - 3, 5, or 7 dice of fire damage (folio 21); the MM1 polar worm breathes no fire",
    }, {
      "name" = "rmzBreathMaxDice",
      "value" = 7,
      "comment" = "the fire breath's top end - 7 dice (folio 21)",
    } },
  "bools" = { {
      "name" = "rmzWingsAndBreath",
      "value" = true,
      "comment" = "wings and head backed with red, breathing fire - the Dragon doctrine where the MM1 polar worm beats small wings but breathes none (folio 21)",
    }, {
      "name" = "rmzBackMeltsWeapons",
      "value" = true,
      "comment" = "the reddish rock-like back protrusions are heated to enormous temperatures, melting any non-magical weapon striking the back (folio 21) - the def agrees in its own words",
    }, {
      "name" = "rmzColdDwelling",
      "value" = true,
      "comment" = "the only fire-using creature that prefers the coldness of mountain areas and frozen wastes, stalkable alongside the Silver Dragon on the Eldritch Wizardry matrix (folio 21)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['rmzHdSmall']() != 6 or m['rmzHdDie']() != 8",
      "note" = "the small band - 6 hit dice on the d8 (folio 21)",
    }, {
      "expr" = "m['rmzHdMid']() != 10 or m['rmzHdLarge']() != 14",
      "note" = "the middle and large bands - 10 and 14 hit dice (folio 21)",
    }, {
      "expr" = "m['rmzSmallPct']() + m['rmzMidPct']() + m['rmzLargePct']() != 100",
      "note" = "the three size chances tile the d100 exactly - 40/35/25 (folio 21)",
    }, {
      "expr" = "m['rmzMidPct']() != 35 or m['rmzLargePct']() != 25",
      "note" = "the middle and large encounter chances (folio 21)",
    }, {
      "expr" = "m['rmzBiteMax']() - m['rmzBiteMin']() != 33",
      "note" = "the bite spread, 3-36 - the Dragon read, not the def's 6-36",
    }, {
      "expr" = "m['rmzBreathMinDice']() != 3 or m['rmzBreathMaxDice']() != 7",
      "note" = "the fire breath - 3, 5, or 7 dice (folio 21)",
    }, {
      "expr" = "m['rmzMagResPct']() != 75",
      "note" = "the 75 percent magic resistance (folio 21)",
    }, {
      "expr" = "m['rmzAcUnderside']() != 4 or m['rmzAcBack']() != 0 or m['rmzAcHead']() != 2",
      "note" = "the three armor classes - underside 4, back 0 plus special, head 2 (folio 21)",
    }, {
      "expr" = "m['rmzLenFeet']() != 30 or m['rmzMoveInches']() != 12 or m['rmzPctInLair']() != 20",
      "note" = "the frame - 30 feet, movement 12, 20 percent in lair (folio 21)",
    }, {
      "expr" = "m['rmzWingsAndBreath']() != 1",
      "note" = "the wings-and-breath doctrine - the Dragon divergence from the MM1 polar worm (folio 21)",
    }, {
      "expr" = "m['rmzBackMeltsWeapons']() != 1",
      "note" = "the heated back - non-magical weapons melt on it (folio 21)",
    }, {
      "expr" = "m['rmzColdDwelling']() != 1",
      "note" = "the cold-dwelling fire creature, the Silver Dragon matrix seat (folio 21)",
    } },
  "audit" = {
      "label" = "R890 Remorhaz lore audit",
      "comment" = "THE REMORHAZ LORE PIN - the issue-2 opener (Round A of issue 2), lore on the variant layer per the Bulette pattern. THE INK (folio 21, Creature Features): three sizes on d8 hit dice - 6/10/14 at 40/35/25 percent on the d100; the frame - 30 feet, movement 12, 20 percent in lair, 75 percent magic resistance, low intelligence, neutral; armor class underside 4, back 0 plus special, head 2; the bite at 3-36; the fire breath at 3, 5, or 7 dice; and the doctrines - wings and head backed with red (the MM1 polar worm beats small wings but breathes no fire), the heated back protrusions that melt non-magical weapons, and the cold-dwelling fire creature that stalks alongside the Silver Dragon on the Eldritch Wizardry matrix. HONEST BOUNDARIES: the MM1 def monsters/monsters/r/remorhaz.lua is UNTOUCHED and holds the stem - these pins are lore/provenance only, never a competing def; every divergence from the def (his bite 3-36 vs 6-36, his 6/10/14 bands vs 7-14, his fire breath, his low intelligence vs animal, his 30 feet vs 21-42) rides noted, never silent. THE VOICE: all 32 issue-2 pages at extract/dragon/002/pNNN_full.txt plus the pre-flip tools/reports/dragon_gap_report_002.md (4 boxes, 0 closed - the Remorhaz box flips at the next Dragon round) shipped as spec data files. The Aronson box on the issue-1 report flips this round - the issue-1 report closes out at 3 closed / 0 open.",
    },
}
