-- pwl: promoted from tools/spec_r908.json (the The Dragon issue-7 opener - the Prowler (folio 24): the single engine-relevant chain in a thin harvest issue, pinned as a new variant-layer registry monster);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 908,
  "prefix" = "pwl",
  "banner" = {
      "title" = "The Dragon issue-7 opener - the Prowler (folio 24): the single engine-relevant chain in a thin harvest issue, pinned as a new variant-layer registry monster",
      "provenance" = "Pinned from The Dragon Vol. I No. 7 (June 1977), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 7; the issue-7 source lives in the archive.org item accessory-dragon-magazine-012, which holds issues 7-14). The folio: 24, the Prowler - 14 hit dice, armor class 1, move 12, number appearing 1, Evil and highly intelligent, 50 percent magic resistant, the constriction at 4-48 hit points per turn and the bite at 1-8, the mind-blank gaze with its save vs. magic and zombei control, the tentacle egg-injection at 1-8 damage with the 2-8 day hatch and the hatched brood's first meal, the exceptional hatcheries in abandoned caves or underground, and the three Patriarchs' simultaneous dispel evil restoration. The transcripts ride extract/dragon/007/ (all 32 issue pages); the issue-7 gap report ships pre-flip. PRINT FOLIO = PDF PAGE, verified at the printed 12, 16 and 28 footers.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon, and with no 1e def existing the Prowler pins as a NEW registry monster - the R900 Creature Features precedent, the Remorhaz lore-against-def shape not applying - carrying the dragon_print xp source in its lua. The XP conversion rides the DMG p.85 additive formula - 1800 base + 3 specials x 950 + 1 exceptional x 1200 at the 13 to 14+ dice category, plus 18 per hit point at the 63 average - the special/exceptional count a noted judgment (the gaze, the constriction, the magic resistance special; the hatchery lifecycle exceptional), never silent. The print's zombei spelling rides AS SCANNED; the statblock prints no treasure or size line and those ride 'not printed' in the lua, never invented. The Fineous Fingers comic sharing folio 24 drops as comic ink per the standing precedent. The editor's standing caution rides: none of this is official.",
    },
  "consts" = { {
      "name" = "pwlHd",
      "value" = 14,
      "comment" = "the Prowler hit dice - 14 (folio 24)",
    }, {
      "name" = "pwlMove",
      "value" = 12,
      "comment" = "the Prowler movement - 12 (folio 24)",
    }, {
      "name" = "pwlAc",
      "value" = 1,
      "comment" = "the Prowler armor class - 1 (folio 24)",
    }, {
      "name" = "pwlNumAppearing",
      "value" = 1,
      "comment" = "the Prowler number appearing - 1 (folio 24)",
    }, {
      "name" = "pwlConstrictMin",
      "value" = 4,
      "comment" = "the constriction attack damage minimum - 4 hit points per turn (folio 24)",
    }, {
      "name" = "pwlConstrictMax",
      "value" = 48,
      "comment" = "the constriction attack damage maximum - 48 hit points per turn (folio 24)",
    }, {
      "name" = "pwlBiteMin",
      "value" = 1,
      "comment" = "the bite damage minimum - 1 (folio 24)",
    }, {
      "name" = "pwlBiteMax",
      "value" = 8,
      "comment" = "the bite damage maximum - 8 (folio 24)",
    }, {
      "name" = "pwlMagicResistPct",
      "value" = 50,
      "comment" = "the Prowler magic resistance - 50 percent (folio 24)",
    }, {
      "name" = "pwlEggDamageMin",
      "value" = 1,
      "comment" = "the egg-injection damage under the skin minimum - 1, however tenderly done (folio 24)",
    }, {
      "name" = "pwlEggDamageMax",
      "value" = 8,
      "comment" = "the egg-injection damage under the skin maximum - 8, however tenderly done (folio 24)",
    }, {
      "name" = "pwlHatchDaysMin",
      "value" = 2,
      "comment" = "the zombei wanders aimlessly 2-8 days until the eggs hatch - the minimum (folio 24)",
    }, {
      "name" = "pwlHatchDaysMax",
      "value" = 8,
      "comment" = "the zombei wanders aimlessly 2-8 days until the eggs hatch - the maximum (folio 24)",
    }, {
      "name" = "pwlRestorePatriarchs",
      "value" = 3,
      "comment" = "three Patriarchs must simultaneously cast dispel evil upon the zombei to restore his mind (folio 24)",
    }, {
      "name" = "pwlAvgHp",
      "value" = 63,
      "comment" = "the average hit points - 14 dice at 4.5 per die (folio 24)",
    }, {
      "name" = "pwlXp",
      "value" = 5850,
      "comment" = "the base XP - the DMG p.85 formula at 14 dice: 1800 base + 3 specials x 950 + 1 exceptional x 1200; the conversion noted (folio 24)",
    }, {
      "name" = "pwlXpPerHp",
      "value" = 18,
      "comment" = "the XP per hit point - the DMG p.85 per-hit-die value at the 13 to 14+ category (folio 24)",
    }, {
      "name" = "pwlXpValue",
      "value" = 6984,
      "comment" = "the XP value - 5850 + 18 x 63, the DMG p.85 additive formula (folio 24)",
    } },
  "bools" = { {
      "name" = "pwlEvil",
      "value" = true,
      "comment" = "the Prowler alignment - Evil, highly intelligent (folio 24)",
    }, {
      "name" = "pwlGazeSaveVsMagic",
      "value" = true,
      "comment" = "looking into the Prowler's eyes forces a save vs. magic or the victim is irrevocably mind blanked (folio 24)",
    }, {
      "name" = "pwlZombeiUnderControl",
      "value" = true,
      "comment" = "the mind-blanked victim becomes a zombei under the control of the Prowler (folio 24)",
    }, {
      "name" = "pwlConstrictOnSave",
      "value" = true,
      "comment" = "those who save against the gaze the Prowler attempts to crush within its powerful coils (folio 24)",
    }, {
      "name" = "pwlEggsViaTentacles",
      "value" = true,
      "comment" = "the zombeis become the recipient of the monster's eggs, injected under the skin with the brown tentacles that line her mouth (folio 24)",
    }, {
      "name" = "pwlHatchedFirstMeal",
      "value" = true,
      "comment" = "when the eggs hatch the baby prowlers make the zombei their first meal - he lays down calmly as they pick his bones clean (folio 24)",
    }, {
      "name" = "pwlExceptionalFormHatcheries",
      "value" = true,
      "comment" = "some exceptionally intelligent prowlers form hatcheries - charming large numbers as guards and egg hosts in abandoned caves or underground (folio 24)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['pwlHd']() != 14 or m['pwlMove']() != 12 or m['pwlAc']() != 1 or m['pwlNumAppearing']() != 1",
      "note" = "the Prowler stat line - 14 hit dice, move 12, armor class 1, number appearing 1 (folio 24)",
    }, {
      "expr" = "m['pwlConstrictMin']() != 4 or m['pwlConstrictMax']() != 48 or m['pwlBiteMin']() != 1 or m['pwlBiteMax']() != 8 or m['pwlMagicResistPct']() != 50",
      "note" = "the Prowler attacks - constriction 4-48 hit points per turn, bite 1-8, 50 percent magic resistant (folio 24)",
    }, {
      "expr" = "m['pwlEggDamageMin']() != 1 or m['pwlEggDamageMax']() != 8 or m['pwlHatchDaysMin']() != 2 or m['pwlHatchDaysMax']() != 8 or m['pwlRestorePatriarchs']() != 3",
      "note" = "the Prowler lifecycle - the 1-8 injection damage, the 2-8 day hatch, the three Patriarchs' simultaneous dispel evil (folio 24)",
    }, {
      "expr" = "m['pwlAvgHp']() != 63 or m['pwlXp']() != 5850 or m['pwlXpPerHp']() != 18 or m['pwlXpValue']() != 6984",
      "note" = "the Prowler XP conversion - the DMG p.85 additive formula: 1800 base + 3 x 950 specials + 1200 exceptional, plus 18 per hit point at the 63 average; the conversion noted, never silent (folio 24)",
    }, {
      "expr" = "m['pwlEvil']() != 1 or m['pwlGazeSaveVsMagic']() != 1 or m['pwlZombeiUnderControl']() != 1 or m['pwlConstrictOnSave']() != 1 or m['pwlEggsViaTentacles']() != 1 or m['pwlHatchedFirstMeal']() != 1 or m['pwlExceptionalFormHatcheries']() != 1",
      "note" = "the Prowler doctrines - the gaze save vs. magic, the zombei control, the constriction on a save, the tentacle eggs, the hatched first meal, the exceptional hatcheries (folio 24)",
    } },
  "audit" = {
      "label" = "R908 Prowler opener audit",
      "comment" = "THE DRAGON ISSUE-7 OPENER ROUND - the thin single-chain harvest. The Prowler (folio 24): the stat pin - 14 hit dice, armor class 1, move 12, number appearing 1, the constriction 4-48 and bite 1-8 attacks, the 50 percent magic resistance; the lifecycle pin - the mind-blank gaze with its save vs. magic and zombei control, the 1-8 tentacle egg-injection, the 2-8 day hatch, the hatched brood's first meal, the exceptional hatcheries and the three-Patriarch dispel evil restoration; and the DMG p.85 XP conversion at the 13 to 14+ dice category, the special/exceptional count a noted judgment.",
    },
}
