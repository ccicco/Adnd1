-- lyc: promoted from tools/spec_r925.json (the The Dragon issue-14 opener - the Name That Monster Contest #1 winners (folio 3) and the Gregory Rihn lycanthropy variant (folios 29-32): the two-chain issue-11 walk pattern);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 925,
  "prefix" = "lyc",
  "banner" = {
      "title" = "The Dragon issue-14 opener - the Name That Monster Contest #1 winners (folio 3) and the Gregory Rihn lycanthropy variant (folios 29-32): the two-chain issue-11 walk pattern",
      "provenance" = "Pinned from The Dragon Vol. II No. 8 (May 1978), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 14; the source lives in the archive.org item accessory-dragon-magazine-012, file Accessory - Dragon Magazine #014_djvu.xml). PRINT FOLIO = PDF PAGE MINUS TWO in this issue, verified at the TOC alignments (the Rust Monster interview at print 14 = PDF 16, the Monty Haul piece at print 21 = PDF 23, the Total Person charts at print 24 = PDF 26, Wormy at print 26 = PDF 28, Finieous Fingers at print 27 = PDF 29). The transcripts ride extract/dragon/014/p001 through p036, landed this round; the article CHAIN is the ink unit, not the folio.",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: the Jarnkung hit-dice cell prints the =) bar garble in the djvu OCR and resolves at the full-res scan to 5 per the R919 one-visual-check precedent; the Crawler hit-dice line prints the prose \"3 eight sided + 1 four sided = 3 1/2\", the fraction garbled to 3 percent in the OCR and resolved at the full-res scan, pinned as the 3-and-1 dice with the 7-halves total, the scaled-int conversion noted; the experience-grid row-4 cell prints 1000 where the article own worked example gives 10,000 for the werebear of the fourth - pinned as-scanned, the dropped zero noted; the grid change-time pins in halves (6 rds = 12, 1/2 rd = 1) and the predominance ladder pins its printed leading zeros as 10 through 01; the Crawler move pins in feet-per-turn as printed, the unit noted. The one-visual-check precedent of R919 (the full-res scan plus the djvu word geometry) stands for any future cell dispute.",
    },
  "consts" = { {
      "name" = "lycProgressRows",
      "value" = 10,
      "comment" = "the lycanthrope experience grid - ten levels (folio 32, PDF 34)",
    }, {
      "name" = "lycBiteCatchPercent",
      "value" = 50,
      "comment" = "characters bitten by lycanthropes have a 50 percent chance of catching the condition (folio 29)",
    }, {
      "name" = "lycOnsetMinDays",
      "value" = 30,
      "comment" = "the first shape-change occurs in 30-60 days, the floor (folio 29)",
    }, {
      "name" = "lycOnsetMaxDays",
      "value" = 60,
      "comment" = "the onset ceiling, 30-60 days (folio 29)",
    }, {
      "name" = "lycFirstChangePanicPercent",
      "value" = 95,
      "comment" = "at the first transformation the animal nature predominates on a 95 percent chance, resulting in blind panic (folio 29)",
    }, {
      "name" = "lycSubjugationPercent",
      "value" = 10,
      "comment" = "a 10 percent chance the shock causes insane subjugation of the human persona to the animal nature, persisting until cured as an insanity (folio 29)",
    }, {
      "name" = "lycSleepRevertPercent",
      "value" = 5,
      "comment" = "an exhausted lycanthrope sleeping has about a 5 percent chance of reverting to human form, undependable, higher under extreme exhaustion or severe wounds (folio 30)",
    }, {
      "name" = "lycRevertWillXp",
      "value" = 2500,
      "comment" = "a new lycanthrope cannot revert to human form at will until 2500 experience points gained beyond the pre-infection total, the grid level-2 figure (folio 30)",
    }, {
      "name" = "lycVoluntaryChangesPerDay",
      "value" = 1,
      "comment" = "a lycanthrope may transform only once per day on his own (folio 30)",
    }, {
      "name" = "lycInducedChangeRestDays",
      "value" = 1,
      "comment" = "a more experienced lycanthrope may induce a second shapechange in another, requiring a full day of rest and no more than once per day (folio 30)",
    }, {
      "name" = "lycFighterExampleLevel",
      "value" = 4,
      "comment" = "the article worked example - a fourth-level fighter contracting lycanthropy (folio 30)",
    }, {
      "name" = "lycFighterExampleHitDice",
      "value" = 4,
      "comment" = "the worked-example lycanthrope initially fights as a monster of four hit dice in wereshape, unless the Blackmoor modifications are in effect (folio 30)",
    }, {
      "name" = "lycExampleChangeRounds",
      "value" = 6,
      "comment" = "the worked example - a low-level werebear taking six rounds to change fully (folio 32)",
    }, {
      "name" = "lycRoundTwoPenalty",
      "value" = 2,
      "comment" = "the worked example combat ladder - round two at level minus two (folio 32)",
    }, {
      "name" = "lycRoundThreePenalty",
      "value" = 4,
      "comment" = "the ladder - rounds three and four at minus four (man and bear respectively), recovering to minus two at round five and full bear at round six, half damage from normal weapons at the halfway point (folio 32)",
    }, {
      "name" = "lycCuredXpPercent",
      "value" = 50,
      "comment" = "magic-users, clergy or psychics cured after some time as a lycanthrope apply only 50 percent of the experience earned during that period (folio 32)",
    }, {
      "name" = "lycHereditaryChanceMin",
      "value" = 1,
      "comment" = "the further option - new characters a 1-5 percent chance of beginning as a hereditary lycanthrope, humans only, the floor (folio 32)",
    }, {
      "name" = "lycHereditaryChanceMax",
      "value" = 5,
      "comment" = "the hereditary-chance ceiling, 1-5 percent (folio 32)",
    }, {
      "name" = "lycJarnkungAc",
      "value" = 3,
      "comment" = "the Jarnkung armor class 3 (folio 3)",
    }, {
      "name" = "lycJarnkungMoveInches",
      "value" = 9,
      "comment" = "the Jarnkung move 9 inches (folio 3)",
    }, {
      "name" = "lycJarnkungHitDice",
      "value" = 5,
      "comment" = "the Jarnkung hit dice 5 - the cell prints the =) bar garble in the djvu OCR and resolves at the full-res scan to 5, the R919 one-visual-check precedent, noted never silent (folio 3)",
    }, {
      "name" = "lycJarnkungLairPercent",
      "value" = 15,
      "comment" = "the Jarnkung 15 percent in lair (folio 3)",
    }, {
      "name" = "lycJarnkungMagicResistance",
      "value" = 20,
      "comment" = "the Jarnkung magic resistance 20 percent (folio 3)",
    }, {
      "name" = "lycJarnkungAppearingMin",
      "value" = 1,
      "comment" = "the Jarnkung number appearing 1-6, the floor (folio 3)",
    }, {
      "name" = "lycJarnkungAppearingMax",
      "value" = 6,
      "comment" = "the appearance ceiling, 1-6, or 2-12 in lair (folio 3)",
    }, {
      "name" = "lycJarnkungLairAppearingMin",
      "value" = 2,
      "comment" = "the in-lair number appearing 2-12, the floor (folio 3)",
    }, {
      "name" = "lycJarnkungLairAppearingMax",
      "value" = 12,
      "comment" = "the in-lair ceiling, 2-12 (folio 3)",
    }, {
      "name" = "lycJarnkungTailDamageMin",
      "value" = 2,
      "comment" = "the Jarnkung tail does 2-12 points, the floor (folio 3)",
    }, {
      "name" = "lycJarnkungTailDamageMax",
      "value" = 12,
      "comment" = "the tail ceiling, 2-12, or two weapons by weapon type (folio 3)",
    }, {
      "name" = "lycJarnkungWizardYearsAgo",
      "value" = 250,
      "comment" = "the Jarnkung origin - a lonely wizard created them about 250 years ago to watch his keep (folio 3)",
    }, {
      "name" = "lycCrawlerMoveFeetPerTurn",
      "value" = 60,
      "comment" = "the Cursed Crimson Crawler move 60 feet per turn, the unit as printed, noted (folio 3)",
    }, {
      "name" = "lycCrawlerHdEights",
      "value" = 3,
      "comment" = "the Crawler hit dice print the prose \"3 eight sided + 1 four sided = 3 1/2\" - three d8, the fraction garbled to 3% in the djvu OCR and resolved at the full-res scan (folio 3)",
    }, {
      "name" = "lycCrawlerHdFours",
      "value" = 1,
      "comment" = "the Crawler hit dice - one d4 (folio 3)",
    }, {
      "name" = "lycCrawlerHdHalves",
      "value" = 7,
      "comment" = "the Crawler hit-dice total 3 1/2 pinned in halves as 7, the conversion noted (folio 3)",
    }, {
      "name" = "lycCrawlerAc",
      "value" = 7,
      "comment" = "the Cursed Crimson Crawler armor class 7 (folio 3)",
    }, {
      "name" = "lycCrawlerAttacks",
      "value" = 2,
      "comment" = "the Crawler makes 2 attacks (folio 3)",
    }, {
      "name" = "lycCrawlerDamageMin",
      "value" = 1,
      "comment" = "the Crawler close combat does 1-6 points per attack, the floor (folio 3)",
    }, {
      "name" = "lycCrawlerDamageMax",
      "value" = 6,
      "comment" = "the Crawler damage ceiling, 1-6 (folio 3)",
    }, {
      "name" = "lycCrawlerRockDamageMin",
      "value" = 1,
      "comment" = "the Crawler throws heavy rocks doing 1-12 points, the floor (folio 3)",
    }, {
      "name" = "lycCrawlerRockDamageMax",
      "value" = 12,
      "comment" = "the rock ceiling, 1-12 (folio 3)",
    }, {
      "name" = "lycCrawlerRockRangeFeetPerHp",
      "value" = 10,
      "comment" = "the rock range is 10 feet per hit point of the Crawler (folio 3)",
    }, {
      "name" = "lycCrawlerRageRadiusFeet",
      "value" = 30,
      "comment" = "the Crawler death-burst - all within 30 feet become enraged at each other (folio 3)",
    }, {
      "name" = "lycCrawlerRageMinRounds",
      "value" = 1,
      "comment" = "the rage lasts 1-4 melee rounds, the floor (folio 3)",
    }, {
      "name" = "lycCrawlerRageMaxRounds",
      "value" = 4,
      "comment" = "the rage ceiling, 1-4 melee rounds (folio 3)",
    }, {
      "name" = "lycUlikAc",
      "value" = 4,
      "comment" = "the Ulik armor class 4 (folio 3)",
    }, {
      "name" = "lycUlikMoveInches",
      "value" = 14,
      "comment" = "the Ulik movement 14 (folio 3)",
    }, {
      "name" = "lycUlikHitDice",
      "value" = 4,
      "comment" = "the Ulik hit dice 4 plus 2 (folio 3)",
    }, {
      "name" = "lycUlikHitDicePlus",
      "value" = 2,
      "comment" = "the Ulik hit-dice plus, 4+2 (folio 3)",
    }, {
      "name" = "lycUlikLairPercent",
      "value" = 20,
      "comment" = "the Ulik 20 percent in lair, treasure type I (folio 3)",
    }, {
      "name" = "lycUlikAppearingMin",
      "value" = 1,
      "comment" = "the Ulik number appearing 1-6, the floor (folio 3)",
    }, {
      "name" = "lycUlikAppearingMax",
      "value" = 6,
      "comment" = "the appearance ceiling, 1-6 (folio 3)",
    }, {
      "name" = "lycUlikHypnotizeSurprisedPercent",
      "value" = 90,
      "comment" = "the Ulik pupiless white eyes hypnotize a surprised victim on 90 percent (folio 3)",
    }, {
      "name" = "lycUlikHypnotizeAwarePercent",
      "value" = 50,
      "comment" = "the hypnotize chance against a non-surprised victim, 50 percent (folio 3)",
    }, {
      "name" = "lycUlikTailBlowMin",
      "value" = 10,
      "comment" = "the tender tail growth serves as a mace for 10-40 blows before falling off, the floor (folio 3)",
    }, {
      "name" = "lycUlikTailBlowMax",
      "value" = 40,
      "comment" = "the tail-mace ceiling, 10-40 blows (folio 3)",
    }, {
      "name" = "lycUlikTailRegrowMinMonths",
      "value" = 6,
      "comment" = "the fallen growth regenerates after 6-8 months, the floor (folio 3)",
    }, {
      "name" = "lycUlikTailRegrowMaxMonths",
      "value" = 8,
      "comment" = "the regeneration ceiling, 6-8 months (folio 3)",
    } },
  "bools" = { {
      "name" = "lycAbilityLossProgressive",
      "value" = true,
      "comment" = "over the incubation the victim suffers a proportional loss of all magical, clerical or psychic ability, complete at the first transformation (folio 29)",
    }, {
      "name" = "lycChildrenInheritCondition",
      "value" = true,
      "comment" = "children of uncured lycanthropes inherit the condition, transmitted only via the bloodstream and not via intercourse (folio 30)",
    }, {
      "name" = "lycFirstTransformationAtPuberty",
      "value" = true,
      "comment" = "hereditary werebears not raised among their own kind have their first transformation at the onset of puberty (folio 30)",
    }, {
      "name" = "lycAnimalShapeSterile",
      "value" = true,
      "comment" = "lycanthropes in animal shape are sterile as regards normal animals of the same type (folio 30)",
    }, {
      "name" = "lycNoHumanSpeechInAnimalShape",
      "value" = true,
      "comment" = "lycanthropes may not speak human languages in animal shape, though they understand those they know (folio 30)",
    }, {
      "name" = "lycNoHumanWeaponsInAnimalShape",
      "value" = true,
      "comment" = "the wereshape cannot use standard weapons or human equipment including rods; passive magic items work if retained, most potions fail, poison works (folio 30)",
    }, {
      "name" = "lycWereratPoisonSaveReduced",
      "value" = true,
      "comment" = "rats lack a vomit reflex, so the wereshaped wererat saving throw against ingested poisons should be reduced (folio 30)",
    }, {
      "name" = "lycCureDiseaseOrCureLycanthropyPermanent",
      "value" = true,
      "comment" = "a clerical cure disease or a healing cure lycanthropy cast upon the subject in animal form results in permanent loss of the disease and reversion to human form (folio 30)",
    }, {
      "name" = "lycCuredRecoveryTimeEqualsLossTime",
      "value" = true,
      "comment" = "cured magic-users, clergy or psychics need the same amount of time to recover lost abilities as the disease took to lose them (folio 32)",
    }, {
      "name" = "lycWerebearMostUsableForPCs",
      "value" = true,
      "comment" = "werebears are the most usable type for player characters, the others less able to control their beastly natures (folio 30)",
    }, {
      "name" = "lycNpcWerebearsUsuallyLawful",
      "value" = true,
      "comment" = "non-player werebears are usually lawful and extremely reluctant to contribute to the spread of the disease (folio 30)",
    }, {
      "name" = "lycArmorDoesNotVanish",
      "value" = true,
      "comment" = "clothing and armor do not disappear and reappear at a shapechange - it must be shed, loose fabrics advised over metal (folio 30)",
    }, {
      "name" = "lycTransformationNotInstantaneous",
      "value" = true,
      "comment" = "the change from man to beast is not instantaneous, the time reducing with experience (folio 32)",
    }, {
      "name" = "lycThievesMayBenefit",
      "value" = true,
      "comment" = "thieves function as fighters in this regard and are the only other class where lycanthropy may prove a positive asset (folio 32)",
    }, {
      "name" = "lycRangersFunctionAsFighters",
      "value" = true,
      "comment" = "rangers function as fighters but cannot gain any holy or magic powers while the disease persists (folio 32)",
    }, {
      "name" = "lycBardsLoseCharisma",
      "value" = true,
      "comment" = "bards suffer a loss of charisma over the long haul - hairiness, pointed teeth, animal odor, raw meat, the shape changes - the charm chances somewhat reduced (folio 32)",
    }, {
      "name" = "lycClericTurnUndeadMayHalve",
      "value" = true,
      "comment" = "the cleric's ability to turn undead may at the DM option be reduced by half, as with psionics, or retained fully (folio 32)",
    }, {
      "name" = "lycJarnkungMagicWeaponsOnly",
      "value" = true,
      "comment" = "the Jarnkung are only affected by magic weapons, highly intelligent (folio 3)",
    }, {
      "name" = "lycJarnkungEspRumoredPsionics",
      "value" = true,
      "comment" = "the Jarnkung have ESP, the older ones rumored to use psionic powers (folio 3)",
    }, {
      "name" = "lycCrawlerHatredBurstOnDeath",
      "value" = true,
      "comment" = "the Crawler spiked tail knob bursts its pent-up hatred if the monster is killed, saving throws as against poison, those saved still attackable by the cursed (folio 3)",
    }, {
      "name" = "lycUlikHypnoticEyes",
      "value" = true,
      "comment" = "the Ulik rear up from hiding, the hypnotic eyes working on the surprised (folio 3)",
    }, {
      "name" = "lycUlikTailGrowthFallsOff",
      "value" = true,
      "comment" = "the Ulik tail growth is very tender and after 10-40 blows falls off, regenerating after 6-8 months (folio 3)",
    }, {
      "name" = "lycContestWinnersThree",
      "value" = true,
      "comment" = "the Name That Monster Contest #1 winners printing in full - the Jarnkung the winner, the Cursed Crimson Crawler the first runner-up, the Ulik the second runner-up, the stats deferred from the issue-13 names-only list (folio 3)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "lycProgress",
      "tag" = "LP",
      "count" = "lycProgressRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0, 0 },
      "audit_comment" = "the lycanthrope experience grid - ten levels of the Rihn progression, every cell resolved clean at the full-res scan cross-validated against the djvu OCR; the row-4 experience cell prints 1000 where the article worked example gives 10,000 for the werebear of the fourth - pinned as-scanned, the dropped zero noted never silent (folio 32)",
      "cols" = { "lycExperience", "lycChangesPerDay", "lycInvoluntaryCombPercent", "lycInvoluntarySleepPercent", "lycChangeBackPercent", "lycBeastPredominancePercent", "lycSpeakLanguagePercent", "lycChangeTimeHalves" },
      "col_comments" = { "the experience ladder - 0, 2500, 5000, the row-4 cell printing 1000 (the article own worked example: 10,000 for the werebear of the fourth, the dropped zero noted as-scanned), 20000, 35000, 50000, 100000, 150000, 200000 (folio 32)", "the changes per day - one at levels 1-2, two at 3-4, three at 5-6, four at 7-8, five at 9-10 (folio 32)", "the chance of involuntary changes in combat - 50 at levels 1-2, 25 at 3-4, 10 at 5, 5 at 6-7, 0 from level 8 (folio 32)", "the chance of involuntary changes in sleep - the levels 1-3 cells print the single combat-or-sleep value pinned to both columns, noted; 50 at 1-2, 25 at 3, 10 at 4, 5 at 5-8, 2 at 9, 1 at 10 (folio 32)", "the chance of changing back voluntarily - 0 at level 1 rising through 50, 60, 75, 80, 85, 90, 95 to 99 at levels 9-10 (folio 32)", "the chance of beast-nature predominance DECREASING with control, printed with leading zeros - 10, 09, 08, 07, 06, 05, 04, 03, 02, 01 percent (folio 32)", "the speak-language-of-species comprehension - 0 at level 1 rising 10, 20, 30, 50, 75, 90, 95, 99 to 100 percent at level 10 (folio 32)", "the time required for change pinned in HALVES - 6 melee rounds at levels 1-2 (12 halves), 4 rounds at 3-4 (8), 2 rounds at 5-6 (4), 1 round at 7-8 (2), the half-round at 9-10 (1), the scaled-int conversion noted (folio 32)" },
      "data" = { { 0, 1, 50, 50, 0, 10, 0, 12 }, { 2500, 1, 50, 50, 50, 9, 10, 12 }, { 5000, 2, 25, 25, 60, 8, 20, 8 }, { 1000, 2, 25, 10, 75, 7, 30, 8 }, { 20000, 3, 10, 10, 80, 6, 50, 4 }, { 35000, 3, 5, 5, 85, 5, 75, 4 }, { 50000, 4, 5, 5, 90, 4, 90, 2 }, { 100000, 4, 0, 5, 95, 3, 95, 2 }, { 150000, 5, 0, 2, 99, 2, 99, 1 }, { 200000, 5, 0, 1, 99, 1, 100, 1 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['lycJarnkungAc']() != 3 or m['lycJarnkungMoveInches']() != 9 or m['lycJarnkungHitDice']() != 5 or m['lycJarnkungLairPercent']() != 15 or m['lycJarnkungMagicResistance']() != 20 or m['lycJarnkungMagicWeaponsOnly']() != 1",
      "note" = "the Jarnkung block - armor class 3, move 9, hit dice 5 (the =) bar garble resolved at the full-res scan), 15 percent lair, 20 percent magic resistance, magic weapons only (folio 3)",
    }, {
      "expr" = "m['lycJarnkungAppearingMin']() != 1 or m['lycJarnkungAppearingMax']() != 6 or m['lycJarnkungLairAppearingMin']() != 2 or m['lycJarnkungLairAppearingMax']() != 12 or m['lycJarnkungTailDamageMin']() != 2 or m['lycJarnkungTailDamageMax']() != 12 or m['lycJarnkungWizardYearsAgo']() != 250",
      "note" = "the Jarnkung numbers - 1-6 appearing, 2-12 in lair, the 2-12 tail, the 250-years-ago wizard origin (folio 3)",
    }, {
      "expr" = "m['lycCrawlerAc']() != 7 or m['lycCrawlerMoveFeetPerTurn']() != 60 or m['lycCrawlerHdEights']() != 3 or m['lycCrawlerHdFours']() != 1 or m['lycCrawlerHdHalves']() != 7 or m['lycCrawlerAttacks']() != 2",
      "note" = "the Cursed Crimson Crawler block - armor class 7, move 60 feet per turn as printed, the hit-dice prose 3d8 + 1d4 = 3 1/2 pinned as the dice and the 7-halves total, 2 attacks (folio 3)",
    }, {
      "expr" = "m['lycCrawlerDamageMin']() != 1 or m['lycCrawlerDamageMax']() != 6 or m['lycCrawlerRockDamageMin']() != 1 or m['lycCrawlerRockDamageMax']() != 12 or m['lycCrawlerRockRangeFeetPerHp']() != 10 or m['lycCrawlerRageRadiusFeet']() != 30 or m['lycCrawlerRageMinRounds']() != 1 or m['lycCrawlerRageMaxRounds']() != 4 or m['lycCrawlerHatredBurstOnDeath']() != 1",
      "note" = "the Crawler attacks - 1-6 per attack, the 1-12 rocks at 10 feet per hit point, the 30-foot hatred burst raging 1-4 melee rounds with saves as poison (folio 3)",
    }, {
      "expr" = "m['lycUlikAc']() != 4 or m['lycUlikMoveInches']() != 14 or m['lycUlikHitDice']() != 4 or m['lycUlikHitDicePlus']() != 2 or m['lycUlikLairPercent']() != 20 or m['lycUlikAppearingMin']() != 1 or m['lycUlikAppearingMax']() != 6",
      "note" = "the Ulik block - armor class 4, move 14, hit dice 4+2, 20 percent lair, 1-6 appearing, treasure type I (folio 3)",
    }, {
      "expr" = "m['lycUlikHypnotizeSurprisedPercent']() != 90 or m['lycUlikHypnotizeAwarePercent']() != 50 or m['lycUlikTailBlowMin']() != 10 or m['lycUlikTailBlowMax']() != 40 or m['lycUlikTailRegrowMinMonths']() != 6 or m['lycUlikTailRegrowMaxMonths']() != 8 or m['lycUlikHypnoticEyes']() != 1 or m['lycUlikTailGrowthFallsOff']() != 1",
      "note" = "the Ulik ways - the hypnotic eyes at 90 surprised / 50 aware, the tender tail mace lasting 10-40 blows and regrowing in 6-8 months (folio 3)",
    }, {
      "expr" = "m['lycBiteCatchPercent']() != 50 or m['lycOnsetMinDays']() != 30 or m['lycOnsetMaxDays']() != 60 or m['lycFirstChangePanicPercent']() != 95 or m['lycSubjugationPercent']() != 10",
      "note" = "the onset - the 50 percent bite catch, the 30-60 day incubation, the 95 percent first-change animal panic, the 10 percent insane subjugation (folio 29)",
    }, {
      "expr" = "m['lycSleepRevertPercent']() != 5 or m['lycRevertWillXp']() != 2500 or m['lycVoluntaryChangesPerDay']() != 1 or m['lycInducedChangeRestDays']() != 1 or m['lycAbilityLossProgressive']() != 1",
      "note" = "the reversion rules - the 5 percent sleep revert, the 2500-point will-revert threshold, one voluntary change per day, the induced change needing a full day of rest, the progressive ability loss (folios 29-30)",
    }, {
      "expr" = "m['lycExperience'](0) != 0 or m['lycChangesPerDay'](0) != 1 or m['lycInvoluntaryCombPercent'](0) != 50 or m['lycInvoluntarySleepPercent'](0) != 50 or m['lycChangeBackPercent'](0) != 0 or m['lycBeastPredominancePercent'](0) != 10 or m['lycSpeakLanguagePercent'](0) != 0 or m['lycChangeTimeHalves'](0) != 12",
      "note" = "the grid level 1 - 0 experience, one change, 50 percent involuntary in combat or sleep, no voluntary reversion, 10 percent predominance, no species speech, 6 melee rounds to change (folio 32)",
    }, {
      "expr" = "m['lycExperience'](3) != 1000 or m['lycInvoluntaryCombPercent'](3) != 25 or m['lycInvoluntarySleepPercent'](3) != 10 or m['lycChangeBackPercent'](3) != 75 or m['lycSpeakLanguagePercent'](3) != 30",
      "note" = "the grid level 4 - the experience cell printing 1000 as-scanned (the worked example giving 10,000, the dropped zero noted), 25 combat / 10 sleep involuntary, 75 reversion, 30 percent speech (folio 32)",
    }, {
      "expr" = "m['lycExperience'](9) != 200000 or m['lycChangesPerDay'](9) != 5 or m['lycInvoluntaryCombPercent'](9) != 0 or m['lycInvoluntarySleepPercent'](9) != 1 or m['lycChangeBackPercent'](9) != 99 or m['lycBeastPredominancePercent'](9) != 1 or m['lycSpeakLanguagePercent'](9) != 100 or m['lycChangeTimeHalves'](9) != 1",
      "note" = "the grid level 10 - 200000 experience, five changes, no combat involuntary, 1 percent sleep, 99 reversion, 1 percent predominance, 100 percent speech, the half-round change (folio 32)",
    }, {
      "expr" = "m['lycFighterExampleLevel']() != 4 or m['lycFighterExampleHitDice']() != 4 or m['lycCuredXpPercent']() != 50 or m['lycThievesMayBenefit']() != 1 or m['lycRangersFunctionAsFighters']() != 1 or m['lycBardsLoseCharisma']() != 1",
      "note" = "the class rulings - the 4th-level fighter example fighting as a 4-hit-dice monster, the cured 50 percent experience, the thief benefit, the ranger-as-fighter, the bard charisma loss (folios 30-32)",
    }, {
      "expr" = "m['lycExampleChangeRounds']() != 6 or m['lycRoundTwoPenalty']() != 2 or m['lycRoundThreePenalty']() != 4 or m['lycTransformationNotInstantaneous']() != 1 or m['lycArmorDoesNotVanish']() != 1",
      "note" = "the transformation combat - the 6-round worked example at minus 2 then minus 4, the non-instantaneous change, the armor that does not vanish (folio 32)",
    }, {
      "expr" = "m['lycCureDiseaseOrCureLycanthropyPermanent']() != 1 or m['lycCuredRecoveryTimeEqualsLossTime']() != 1 or m['lycClericTurnUndeadMayHalve']() != 1 or m['lycWereratPoisonSaveReduced']() != 1 or m['lycNoHumanSpeechInAnimalShape']() != 1 or m['lycNoHumanWeaponsInAnimalShape']() != 1",
      "note" = "the cure and the wereshape - the permanent cure in animal form, the recovery time equaling the loss time, the halved turn undead option, the wererat poison save, the no-speech no-weapons wereshape (folios 30-32)",
    }, {
      "expr" = "m['lycContestWinnersThree']() != 1 or m['lycHereditaryChanceMin']() != 1 or m['lycHereditaryChanceMax']() != 5 or m['lycChildrenInheritCondition']() != 1 or m['lycFirstTransformationAtPuberty']() != 1 or m['lycAnimalShapeSterile']() != 1 or m['lycNpcWerebearsUsuallyLawful']() != 1 or m['lycWerebearMostUsableForPCs']() != 1",
      "note" = "the contest harvest landed - three winners in full, the 1-5 percent hereditary option, the bloodline rules, the lawful NPC werebears the most usable player chain (folios 3, 30-32)",
    } },
  "audit" = {
      "label" = "R925 issue-14 opener audit",
      "comment" = "THE DRAGON ISSUE-14 OPENER ROUND - both engine-relevant chains in one round, the two-chain issue-11 walk pattern. CHAIN ONE, the Name That Monster Contest #1 winners (folio 3, PDF 5), the harvest that slipped from issue 13 - the Jarnkung (armor class 3, move 9, the hit-dice cell printing the =) bar garble in the djvu OCR and resolving at the full-res scan to 5, 15 percent lair, 20 percent magic resistance, magic weapons only, the 2-12 tail, the 250-years-ago wizard origin), the Cursed Crimson Crawler (armor class 7, move 60 feet per turn as printed, the hit-dice prose 3d8 + 1d4 = 3 1/2 with the fraction garbled to 3 percent in the OCR and resolved at the full-res scan, pinned as the dice and the 7-halves total, the 1-6 attacks, the 1-12 rocks at 10 feet per hit point, the 30-foot hatred death-burst raging 1-4 melee rounds with saves as poison) and the Ulik (armor class 4, move 14, hit dice 4+2, the hypnotic eyes at 90 surprised / 50 aware, the tender tail mace lasting 10-40 blows and regrowing in 6-8 months). CHAIN TWO, the Gregory Rihn lycanthropy variant The Progress of the Disease (folios 29-32, PDF 31, 33-34): the 50 percent bite catch, the 30-60 day onset, the 95 percent first-change panic, the 10 percent insane subjugation, the 5 percent sleep reversion, the 2500-point will-revert threshold, the ten-level experience grid with the row-4 cell printing 1000 where the worked example gives 10,000 - pinned as-scanned, the dropped zero noted never silent - the predominance ladder DECREASING 10 through 01 with control, the species-speech ladder 0 through 100, the change-time pinned in halves, the wereshape limits (no human speech, no human weapons, passive items retained, poison working, the wererat poison save reduced), the class rulings (the 4th-level fighter example fighting as a 4-hit-dice monster, the cured 50 percent experience, the thief benefit, the ranger-as-fighter, the bard charisma loss, the halved turn-undead option) and the cures. The folio offset noted: PRINT FOLIO = PDF PAGE MINUS TWO in issue 14, verified at the TOC alignments. Scoped out per the adjudication: the SPACE MARINES article, the M-A Variant and the Total Person charts (another systems), the reviews, the Rust Monster interview (humor, IDEAS USABLE), the Monty Haul satire, the editorial, the comics and the ads; report 014 ships pre-flip with both boxes open, the closing round to flip them.",
    },
}
