-- jou: promoted from tools/spec_r931.json (the The Dragon issue-17 opener part one - the jousting matrix, the vampire doctrine, the dressing tables, the joke monsters, the tesseract, the adamanite price grid and the angels: the seven-chain round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 931,
  "prefix" = "jou",
  "banner" = {
      "title" = "The Dragon issue-17 opener part one - the jousting matrix, the vampire doctrine, the dressing tables, the joke monsters, the tesseract, the adamanite price grid and the angels: the seven-chain round",
      "provenance" = "Pinned from The Dragon Vol. III No. 3 (August 1978), the Curtiss-provided scan voice (single-voice: the issue-17 source is the uploaded Dm17.pdf with its mistral-ocr transcript; no archive.org djvu cross-check exists for issue 17). PRINT FOLIO = PDF PAGE MINUS TWO in this issue, verified at the page feet (folios 3, 5, 10, 15, 16, 17, 20, 31, 32 and 33 print at the PDF pages 5, 7, 12, 17, 18, 19, 22, 33, 34 and 35) plus the TOC alignments (Jousting at print 4 = PDF 6, A Wizard With A Difference at print 10 = PDF 12, the Tesseracts at print 20 = PDF 22 continued at print 22 = PDF 24, the Angels at print 32 = PDF 34). The transcripts ride extract/dragon/017/p001 through p040, landed this round; the article CHAIN is the ink unit, not the folio. The Ward wizard chain (print 10-13) rides the part-two round - the issue-10, issue-12 and issue-13 split pattern.",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: no full-res visual check exists for this issue (the scan is a text-side transcript, no page renders), so garbled cells pin the sentinel, never guessed - the vampire minimum-strength cell prints 8:69 (the OD&D 18/69 percentile form misread, single voice) and pins the sentinel with the prose riding the transcript; the Healing angel secondary move prints the garbled 15/24 quarter and pins the sentinel; only the Angel of Wrath prints its hit-dice sides (eight-sided) - the other three types print bare dice counts and ride the sentinel; the adamanite arrow-points weight prints nil and pins the sentinel, the price printing 400@ per arrow; the sounds table prints TWENTY-ONE rows as scanned - the die-roll column runs 1 through 21, row 21 the joke row (the dungeon master screams of anguish), pinned as scanned with the count const, never corrected to 20; the joust matrix prints 0* at HELM versus Steady Seat - pinned 0 with the flag; the Crs'tchen prints AC 12 and HD 1/2 in the EPT convention - the pin IS the conversion, noted; the sounds and sights rows themselves ride the transcript, the pinning carrying the counts, the chance and the interval.",
    },
  "consts" = { {
      "name" = "jouMatrixDieSides",
      "value" = 20,
      "comment" = "the joust matrix base numbers add to a twenty-sided die roll (folio 4, PDF 6)",
    }, {
      "name" = "jouResolutionSteps",
      "value" = 6,
      "comment" = "the six-step ride resolution - both select secretly, A resolves versus B defense, magical adjustments, level comparison, the roll, the reverse pass (folio 4)",
    }, {
      "name" = "jouUnhorsedInjuryPercent",
      "value" = 10,
      "comment" = "an unhorsed knight takes a 10 percent chance of injury (folio 4)",
    }, {
      "name" = "jouHelmKnockoffInjuryBonusPercent",
      "value" = 20,
      "comment" = "a HELM hit that unhorses adds 20 to the injury percentile roll; a helmetless knight takes maximum lance damage (folio 4)",
    }, {
      "name" = "jouMatrixRows",
      "value" = 8,
      "comment" = "the joust matrix - eight aiming points: HELM, DC dexter calf, CP center plate, SC sinister calf, DF dexter forearm, FP front plate, SF sinister forearm, BASE (folio 4)",
    }, {
      "name" = "jouResultsRows",
      "value" = 4,
      "comment" = "the joust results - four result rows: U unhorsed, U/B unhorsed with broken lance, B broken lance, G glancing blow (folio 4)",
    }, {
      "name" = "jouInjuryRows",
      "value" = 6,
      "comment" = "the injury table - six percentile bands from 01-60 to the 00 kill (folio 4)",
    }, {
      "name" = "jouVmpGaseousSpeedMph",
      "value" = 50,
      "comment" = "the gaseous form rushes the party at up to 50 mph, buffeting as a high wind - the print cites some sources (folio 3, PDF 5)",
    }, {
      "name" = "jouVmpStakeStrokesMax",
      "value" = 4,
      "comment" = "the stake must impale the heart in one stroke or in a number not to exceed four - the final determination is the judge call (folio 3)",
    }, {
      "name" = "jouVmpCrumbleDustAgeYears",
      "value" = 100,
      "comment" = "a vampire over one hundred years old crumbles to dust - both the dust and the coffin must then be burned (folio 3)",
    }, {
      "name" = "jouVmpMinStrength",
      "value" = -1,
      "comment" = "the printed minimum-strength cell garbles as 8:69 in the single voice - the OD&D 18/69 percentile form misread; pinned sentinel, never guessed, the prose rides the transcript (folio 3)",
    }, {
      "name" = "jouSsgSoundChancePercent",
      "value" = 25,
      "comment" = "every 30 minutes there is a 25 percent chance of hearing a random noise (folio 15, PDF 17)",
    }, {
      "name" = "jouSsgSoundIntervalMinutes",
      "value" = 30,
      "comment" = "the noise check interval - every 30 minutes (folio 15)",
    }, {
      "name" = "jouSsgSoundRows",
      "value" = 21,
      "comment" = "the sounds table prints TWENTY-ONE rows as scanned - the die-roll column runs 1 through 21, row 21 the joke row (dungeon master screams of anguish); pinned as scanned, never corrected to 20, the rows ride the transcript (folio 15)",
    }, {
      "name" = "jouSsgSightRows",
      "value" = 20,
      "comment" = "the sights table prints twenty rows, from blasted stone to corpses shackled to the wall; the rows ride the transcript (folio 15)",
    }, {
      "name" = "jouMjkClanMin",
      "value" = 3,
      "comment" = "the munchkin clans range from 3 to 12 (folio 16, PDF 18)",
    }, {
      "name" = "jouMjkClanMax",
      "value" = 12,
      "comment" = "the clan maximum, 12 (folio 16)",
    }, {
      "name" = "jouMjkMotherHeightInches",
      "value" = 48,
      "comment" = "the Munchkin Mother stands about four feet - 48 inches (folio 16)",
    }, {
      "name" = "jouMjkOffspringMinInches",
      "value" = 36,
      "comment" = "the offspring range from three to four feet - 36 inches at the low end (folio 16)",
    }, {
      "name" = "jouMjkOffspringMaxInches",
      "value" = 48,
      "comment" = "the offspring upper bound, four feet - 48 inches (folio 16)",
    }, {
      "name" = "jouMjkMaleParentPercent",
      "value" = 5,
      "comment" = "there is rarely a male parent to be found - a 5 percent chance, the male leaving soon after mating (folio 16)",
    }, {
      "name" = "jouMjkOffspringMalePercent",
      "value" = 75,
      "comment" = "the offspring are predominately male - a 75 percent chance each (folio 16)",
    }, {
      "name" = "jouMjkMagicChancePercent",
      "value" = 10,
      "comment" = "the Magic Munchkin - a 10 percent chance of one per 25 (folio 16)",
    }, {
      "name" = "jouMjkMagicPerGroup",
      "value" = 25,
      "comment" = "the magic variety frequency denominator - one per 25 (folio 16)",
    }, {
      "name" = "jouMjkMagicSpellsPerDay",
      "value" = 1,
      "comment" = "a Magic Munchkin can use one magic spell per day (folio 16)",
    }, {
      "name" = "jouMjkMagicSpellLevelMax",
      "value" = 9,
      "comment" = "the munchkin spell use runs up to and including 9th level (folio 16)",
    }, {
      "name" = "jouMjkMagicCasterLevel",
      "value" = 18,
      "comment" = "the munchkin casts as an eighteenth level Wizard (folio 16)",
    }, {
      "name" = "jouMjkMotherSpellsPerDay",
      "value" = 3,
      "comment" = "the Munchkin Mother can do three spells per day (folio 16)",
    }, {
      "name" = "jouMjkLeaveChancePercent",
      "value" = 5,
      "comment" = "a 5 percent chance per week, cumulative, that ignored munchkins leave out of boredom (folio 16)",
    }, {
      "name" = "jouSchNumberMin",
      "value" = 1,
      "comment" = "the Scholar number appearing, 1-4; in the special case of a symposium, 10-20 (folios 16-17, PDF 18-19)",
    }, {
      "name" = "jouSchNumberMax",
      "value" = 4,
      "comment" = "the number appearing upper bound, 4 (folio 16)",
    }, {
      "name" = "jouSchSymposiumMin",
      "value" = 10,
      "comment" = "the symposium special case, 10 at the low end (folio 16)",
    }, {
      "name" = "jouSchSymposiumMax",
      "value" = 20,
      "comment" = "the symposium upper bound, 20 (folio 16)",
    }, {
      "name" = "jouSchArmorClass",
      "value" = 9,
      "comment" = "the Scholar armor class, 9 (folio 16)",
    }, {
      "name" = "jouSchHdMin",
      "value" = 1,
      "comment" = "the Scholar hit dice, 1-3 on six-sided dice (folio 16)",
    }, {
      "name" = "jouSchHdMax",
      "value" = 3,
      "comment" = "the hit dice upper bound, 3 (folio 16)",
    }, {
      "name" = "jouSchHdSides",
      "value" = 6,
      "comment" = "the hit dice sides, six-sided (folio 16)",
    }, {
      "name" = "jouSchLairPercent",
      "value" = 30,
      "comment" = "the Scholar lair chance, 30 percent (folio 16)",
    }, {
      "name" = "jouSchTreasureCopper",
      "value" = 5,
      "comment" = "the Scholar treasure, 5 copper pieces - scholars are notoriously poor (folio 16)",
    }, {
      "name" = "jouSchInstructorSpells",
      "value" = 2,
      "comment" = "the Instructor spells - Confusion and Read Obscure Languages (folio 16)",
    }, {
      "name" = "jouSchAssociateSpells",
      "value" = 3,
      "comment" = "the Associate Professor spells - Fear, Time Stop and Book Missiles (folio 17)",
    }, {
      "name" = "jouSchFoolSpells",
      "value" = 3,
      "comment" = "the Fool Professor spells - Power Word Stun, Academic Dust and Cause Boredom (folio 17)",
    }, {
      "name" = "jouSchBookMissileMin",
      "value" = 1,
      "comment" = "the Book Missiles inflict 1-8 points of damage (folio 17)",
    }, {
      "name" = "jouSchBookMissileMax",
      "value" = 8,
      "comment" = "the Book Missiles upper bound, 8 (folio 17)",
    }, {
      "name" = "jouSchDustMin",
      "value" = 3,
      "comment" = "the Academic Dust does 3-18 points of damage (folio 17)",
    }, {
      "name" = "jouSchDustMax",
      "value" = 18,
      "comment" = "the Academic Dust upper bound, 18 (folio 17)",
    }, {
      "name" = "jouSchParalyzeMinTurns",
      "value" = 2,
      "comment" = "the Academic Dust paralyzes the mind for 2-4 turns (folio 17)",
    }, {
      "name" = "jouSchParalyzeMaxTurns",
      "value" = 4,
      "comment" = "the paralysis upper bound, 4 turns (folio 17)",
    }, {
      "name" = "jouCrsNumberMin",
      "value" = 1,
      "comment" = "the Crs'tchen number appearing, 1-12 (folio 17, PDF 19)",
    }, {
      "name" = "jouCrsNumberMax",
      "value" = 12,
      "comment" = "the number appearing upper bound, 12 (folio 17)",
    }, {
      "name" = "jouCrsArmorClass",
      "value" = 12,
      "comment" = "the Crs'tchen armor class, 12 - the EPT-style descending print, the pin IS the conversion, noted (folio 17)",
    }, {
      "name" = "jouCrsMoveFeet",
      "value" = 15,
      "comment" = "the Crs'tchen move, 15 (folio 17)",
    }, {
      "name" = "jouCrsLairPercent",
      "value" = 80,
      "comment" = "the lair line prints 80/1-100 - the lair percent 80, the 1-100 range riding the transcript (folio 17)",
    }, {
      "name" = "jouCrsLairGoldPercent",
      "value" = 30,
      "comment" = "the treasure-in-lair line prints G:30 - gold at 30 percent (folio 17)",
    }, {
      "name" = "jouCrsAlignmentChangePercent",
      "value" = 33,
      "comment" = "a 33 percent chance the victim alignment is changed without his knowledge when the Crs'tchen speaks (folio 17)",
    }, {
      "name" = "jouCrsTransfix3Percent",
      "value" = 30,
      "comment" = "the transfix table - 30 percent for 3 turns (folio 17)",
    }, {
      "name" = "jouCrsTransfix4Percent",
      "value" = 30,
      "comment" = "the transfix table - 30 percent for 4 turns (folio 17)",
    }, {
      "name" = "jouCrsTransfix5Percent",
      "value" = 30,
      "comment" = "the transfix table - 30 percent for 5 turns (folio 17)",
    }, {
      "name" = "jouCrsTransfixHalfDayPercent",
      "value" = 5,
      "comment" = "the transfix table - 5 percent for a half day (folio 17)",
    }, {
      "name" = "jouCrsTransfixFullDayPercent",
      "value" = 5,
      "comment" = "the transfix table - 5 percent for a full day (folio 17)",
    }, {
      "name" = "jouCrsBegMoneyPercent",
      "value" = 20,
      "comment" = "the begging - a 20 percent chance the Crs'tchen has taken 100-600 K (folio 17)",
    }, {
      "name" = "jouCrsBegMoneyMinK",
      "value" = 100,
      "comment" = "the taken money low bound, 100 K (folio 17)",
    }, {
      "name" = "jouCrsBegMoneyMaxK",
      "value" = 600,
      "comment" = "the taken money upper bound, 600 K (folio 17)",
    }, {
      "name" = "jouCrsBegServicePercent",
      "value" = 10,
      "comment" = "a 10 percent chance the Crs'tchen has your services for 1-12 days (folio 17)",
    }, {
      "name" = "jouCrsBegServiceMinDays",
      "value" = 1,
      "comment" = "the conscripted service low bound, 1 day (folio 17)",
    }, {
      "name" = "jouCrsBegServiceMaxDays",
      "value" = 12,
      "comment" = "the conscripted service upper bound, 12 days (folio 17)",
    }, {
      "name" = "jouCrsBurnWithinTurns",
      "value" = 3,
      "comment" = "the dead body must be burned within three turns or it regenerates and seeks out the player ceaselessly (folio 17)",
    }, {
      "name" = "jouCrsEyeOne",
      "value" = 1,
      "comment" = "the Eyes that save a caught victim - Eye No. 1 (folio 17)",
    }, {
      "name" = "jouCrsEyeSixteen",
      "value" = 16,
      "comment" = "Eye No. 16 (folio 17)",
    }, {
      "name" = "jouCrsEyeNineteen",
      "value" = 19,
      "comment" = "Eye No. 19 (folio 17)",
    }, {
      "name" = "jouTsvRooms",
      "value" = 8,
      "comment" = "the tesseract dungeon holds eight cubical rooms - the central C, the E S W N ring, the frame F, the upper U and lower L (folios 20+22, PDF 22+24)",
    }, {
      "name" = "jouTsvCentralDoors",
      "value" = 4,
      "comment" = "the central room C has four doors - the tesseract is not activated so long as any door remains open (folio 20)",
    }, {
      "name" = "jouTsvCommonSides",
      "value" = 1,
      "comment" = "each cube of a tesseract shares one common side with each cube adjacent to it (folio 20)",
    }, {
      "name" = "jouTsvCommonEdges",
      "value" = 4,
      "comment" = "each cube shares four common edges with each cube adjacent to it and with each cube immediately adjacent to the adjacent cube (folio 20)",
    }, {
      "name" = "jouAdmRows",
      "value" = 10,
      "comment" = "the adamanite base price grid - ten equipment rows, plate armor through arrow points (folios 31-32, PDF 33-34)",
    }, {
      "name" = "jouAdmCharmCostPlatePerLevel",
      "value" = 8000,
      "comment" = "charming adamanite beyond the original +2 costs about 8000 GP per level for full plate armor (folio 32)",
    }, {
      "name" = "jouAdmCharmCostSwordShieldPerLevel",
      "value" = 4000,
      "comment" = "the charm cost is about 4000 GP per level for a sword or shield (folio 32)",
    }, {
      "name" = "jouAdmCharmBasePlus",
      "value" = 2,
      "comment" = "the handcrafted uncharmed equipment carries an original +2 (folio 32)",
    }, {
      "name" = "jouAdmCharmMaxYears",
      "value" = 1,
      "comment" = "any charm after the initial plus two lasts at maximum one year and usually less (folio 31)",
    }, {
      "name" = "jouAdmHardenedPriceMin",
      "value" = 20,
      "comment" = "hardened plate adamanite sells for 20-40 times its weight in gold (folio 32)",
    }, {
      "name" = "jouAdmHardenedPriceMax",
      "value" = 40,
      "comment" = "the hardened plate multiplier upper bound, 40 (folio 32)",
    }, {
      "name" = "jouAdmTemperablePriceMin",
      "value" = 25,
      "comment" = "temperable adamanite capable of holding an edge sells for 25-60 times its weight in gold (folio 32)",
    }, {
      "name" = "jouAdmTemperablePriceMax",
      "value" = 60,
      "comment" = "the temperable multiplier upper bound, 60 (folio 32)",
    }, {
      "name" = "jouAdmImitationHitProbPenalty",
      "value" = 1,
      "comment" = "the imitation alloys range from no effect to reduced effectiveness - a minus 1 to Hit Prob. or AC (folio 32)",
    }, {
      "name" = "jouAdmImitationPlusFirst",
      "value" = 2,
      "comment" = "the best unstable imitation - a plus 2 the first melee round (folio 32)",
    }, {
      "name" = "jouAdmImitationPlusSecond",
      "value" = 1,
      "comment" = "the unstable imitation decays to a plus 1 the second melee round (folio 32)",
    }, {
      "name" = "jouAdmMuProfitPercent",
      "value" = 100,
      "comment" = "the charmer MU makes at least 100 percent profit - the cost to the MU approximately half the listed price (folio 32)",
    }, {
      "name" = "jouAdmDiscoveryToInvasionMonths",
      "value" = 14,
      "comment" = "about fourteen months after the accidental discovery, the goblin trouble struck the Valley of the Iron Pits (folio 32)",
    }, {
      "name" = "jouAdmResearchYears",
      "value" = 5,
      "comment" = "after about five years of research Aolor realized he could not perfect the alloy alone (folio 32)",
    }, {
      "name" = "jouAdmFormulaReturnYears",
      "value" = 2,
      "comment" = "two years after the bargain with Dealanan the Mixer, the perfected formula arrived (folio 32)",
    }, {
      "name" = "jouAdmSnogFighterLevel",
      "value" = 8,
      "comment" = "Snog of the Scarred Jaw, the goblin leader - an 8th level fighter (folio 32)",
    }, {
      "name" = "jouAdmSnogGuardsLevel",
      "value" = 2,
      "comment" = "the Snog bodyguards are 2nd level fighters (folio 32)",
    }, {
      "name" = "jouAdmTributeKingPercent",
      "value" = 50,
      "comment" = "the forfeited goblin money - one half to the king (folio 32)",
    }, {
      "name" = "jouAdmTributeChurchPercent",
      "value" = 25,
      "comment" = "one quarter to the church that claimed the Blue Saint (folio 32)",
    }, {
      "name" = "jouAdmTributeSoldiersPercent",
      "value" = 25,
      "comment" = "one quarter to the soldiers who took part in the clean up (folio 32)",
    }, {
      "name" = "jouAngRows",
      "value" = 4,
      "comment" = "the angel stat grid - the four types recorded by the Chronicle of Bishop Matthews in Rudigore (folios 32-33, PDF 34-35)",
    }, {
      "name" = "jouAngResponseBasePercent",
      "value" = 1,
      "comment" = "the prayer response base - a 1 percent chance per cleric level (folio 33)",
    }, {
      "name" = "jouAngHierarchyTypes",
      "value" = 9,
      "comment" = "the classical celestial hierarchy has nine members (folio 33)",
    }, {
      "name" = "jouAngRecordedTypes",
      "value" = 4,
      "comment" = "only four types of angels are recorded as appearing on Earth (folio 33)",
    }, {
      "name" = "jouAngWrathSwordPlus",
      "value" = 5,
      "comment" = "the Angel of Wrath wields a +5 Holy Sword - it vanishes with the golden armor and shield if the angel is vanquished (folio 33)",
    }, {
      "name" = "jouAngWrathWallPerDay",
      "value" = 3,
      "comment" = "the Angel of Wrath creates a double-strength Wall of Fire three times per day (folio 33)",
    }, {
      "name" = "jouAngWrathWallMultiplier",
      "value" = 2,
      "comment" = "the Wrath wall of fire is double strength (folio 33)",
    }, {
      "name" = "jouAngWrathHolyWordPerDay",
      "value" = 1,
      "comment" = "the Angel of Wrath pronounces a Holy Word once per day (folio 33)",
    }, {
      "name" = "jouAngSeraphWallMultiplier",
      "value" = 3,
      "comment" = "the Seraphim generates a triple-strength Wall of Fire (folio 33)",
    }, {
      "name" = "jouAngSeraphHolyWordPerDay",
      "value" = 1,
      "comment" = "the Seraphim uses a Holy Word once per day (folio 33)",
    }, {
      "name" = "jouAngSeraphSymbolPerDay",
      "value" = 1,
      "comment" = "the Seraphim uses any Symbol once per day (folio 33)",
    }, {
      "name" = "jouAngSeraphWrathOfGodMultiplier",
      "value" = 2,
      "comment" = "once a day the Seraphim calls down the Wrath of God - a double-strength Meteor Swarm (folio 33)",
    }, {
      "name" = "jouAngSummonOneMin",
      "value" = 2,
      "comment" = "the Seraphim can call to its aid 2-16 Type I angels (folio 33)",
    }, {
      "name" = "jouAngSummonOneMax",
      "value" = 16,
      "comment" = "the Type I summon upper bound, 16 (folio 33)",
    }, {
      "name" = "jouAngSummonTwoMin",
      "value" = 1,
      "comment" = "the Seraphim summons 1-4 Type II angels (folio 33)",
    }, {
      "name" = "jouAngSummonTwoMax",
      "value" = 4,
      "comment" = "the Type II summon upper bound, 4 (folio 33)",
    }, {
      "name" = "jouAngSummonThreeMin",
      "value" = 1,
      "comment" = "the Seraphim summons 1-6 Type III angels (folio 33)",
    }, {
      "name" = "jouAngSummonThreeMax",
      "value" = 6,
      "comment" = "the Type III summon upper bound, 6 (folio 33)",
    } },
  "bools" = { {
      "name" = "jouNoStrengthDexBonuses",
      "value" = true,
      "comment" = "the joust system grants no bonuses for exceptional strength or dexterity (folio 4)",
    }, {
      "name" = "jouShieldBonusHelmOnlyShieldHigh",
      "value" = true,
      "comment" = "the defender receives the shield bonus against a HELM aim only when he played position 5, Shield High (folio 4)",
    }, {
      "name" = "jouHelmSteadySeatZeroSpecial",
      "value" = true,
      "comment" = "the matrix prints 0* at HELM versus Steady Seat - the glancing blow G on the helm knocks it off, shattering if non-protective (folio 4)",
    }, {
      "name" = "jouGlancingBlowMissExceptHelm",
      "value" = true,
      "comment" = "a G glancing blow is effectively a miss unless scored on the HELM (folio 4)",
    }, {
      "name" = "jouMagicalLanceBreaksIfShieldHigher",
      "value" = true,
      "comment" = "a magical lance breaks only if the defender shield is rated higher than the lance; a non-magical lance breaks on U/B and B (folio 4)",
    }, {
      "name" = "jouInjuryConCheckVsResurrection",
      "value" = true,
      "comment" = "an injured knight must pass a constitution check versus resurrection or be rendered temporarily unconscious (folio 4)",
    }, {
      "name" = "jouContinueRidesUntilUnhorsed",
      "value" = true,
      "comment" = "rides continue until one knight is unhorsed (folio 4)",
    }, {
      "name" = "jouVmpCharmManyThenBanquet",
      "value" = true,
      "comment" = "the intelligent vampire charms as many as possible, tells them to wait, and retrieves the rest of the party (folio 3)",
    }, {
      "name" = "jouVmpRatSpyNetwork",
      "value" = true,
      "comment" = "the thinking vampire whips rats, mice and charmed creatures into a spy network across the dungeon (folio 3)",
    }, {
      "name" = "jouVmpGaseousOffensiveAssault",
      "value" = true,
      "comment" = "the gaseous form is offensive as well as defensive - rushing past at speed, retracing its path, wearing the party down (folio 3)",
    }, {
      "name" = "jouVmpGarlicProtection",
      "value" = true,
      "comment" = "garlic is an inexpensive protection, at the cost of friends (folio 3)",
    }, {
      "name" = "jouVmpHostCircleProtection",
      "value" = true,
      "comment" = "a properly made circle in the ground with host fragments may prevent a charmed victim from leaving (folio 3)",
    }, {
      "name" = "jouVmpMirrorTwoViews",
      "value" = true,
      "comment" = "the mirror doctrine prints two views - the vampire runs from it, or the secondary more realistic view, stays at bay waiting (folio 3)",
    }, {
      "name" = "jouVmpStakeHawthornBlackthorn",
      "value" = true,
      "comment" = "the stake works only of hawthorn or blackthorn and only when correctly installed (folio 3)",
    }, {
      "name" = "jouVmpStakeTemporaryMeasure",
      "value" = true,
      "comment" = "stakes are a temporary measure - they rot, burn away, are pulled out or jarred loose (folio 3)",
    }, {
      "name" = "jouVmpCoffinHolyWaterBoobyTrap",
      "value" = true,
      "comment" = "holy water poured into the coffin makes it a booby trap (folio 3)",
    }, {
      "name" = "jouVmpCoffinHostDenial",
      "value" = true,
      "comment" = "a broken host or crucifix left in the coffin denies the vampire rest until kobolds fetch a dirt-filled replacement (folio 3)",
    }, {
      "name" = "jouVmpDirtStealing",
      "value" = true,
      "comment" = "stealing the coffin dirt is a trick worthy of the most lawful cleric (folio 3)",
    }, {
      "name" = "jouVmpVictimInfectsNearDeathOrBlood",
      "value" = true,
      "comment" = "a victim develops vampire characteristics only near death or when forced to drink the vampire blood (folio 3)",
    }, {
      "name" = "jouVmpSatedVampireLethargic",
      "value" = true,
      "comment" = "a sated vampire found in his coffin is lethargic and easier to handle (folio 3)",
    }, {
      "name" = "jouSsgSoundsCeaseOrLeadAway",
      "value" = true,
      "comment" = "the noises either cease if investigated or lead investigators away, possibly to a trap (folio 15)",
    }, {
      "name" = "jouSsgSoundsSeldomRevealCause",
      "value" = true,
      "comment" = "the noises seldom lead into a position where their cause could be seen (folio 15)",
    }, {
      "name" = "jouSsgNoiseRoomsDoctrine",
      "value" = true,
      "comment" = "the sounds are also good for noise rooms (folio 15)",
    }, {
      "name" = "jouSsgAcousticsDistort",
      "value" = true,
      "comment" = "the noises may be distorted or sound more distant due to the acoustical qualities of dungeons (folio 15)",
    }, {
      "name" = "jouSsgSightsRealToAllSenses",
      "value" = true,
      "comment" = "the apparitions are real to all senses, including touch (folio 15)",
    }, {
      "name" = "jouSsgSightsVanishAfterLeaving",
      "value" = true,
      "comment" = "the apparitions vanish immediately after the party has left (folio 15)",
    }, {
      "name" = "jouSsgSightsMisleadLandmarks",
      "value" = true,
      "comment" = "the apparitions are great for misleading players who use them as landmarks (folio 15)",
    }, {
      "name" = "jouSsgRustFlakesCrumbleOnTouch",
      "value" = true,
      "comment" = "the rusted useless armor or weapons flake away to piles of rust if picked up or touched (folio 15)",
    }, {
      "name" = "jouSsgSlimeNotGreenSlime",
      "value" = true,
      "comment" = "the slime sight prints NOT Green Slime - the distinction noted (folio 15)",
    }, {
      "name" = "jouMjkMatriarchalClans",
      "value" = true,
      "comment" = "the munchkins live in a matriarchal society, one Munchkin Mother per clan (folio 16)",
    }, {
      "name" = "jouMjkImmuneMostMagic",
      "value" = true,
      "comment" = "munchkins are immune to most magic (folio 16)",
    }, {
      "name" = "jouMjkRegenerative",
      "value" = true,
      "comment" = "munchkins are regenerative (folio 16)",
    }, {
      "name" = "jouMjkPermanentPests",
      "value" = true,
      "comment" = "munchkins are permanent pests - the one thing you can count on is that they stay and bring more (folio 16)",
    }, {
      "name" = "jouMjkBoredTroublesome",
      "value" = true,
      "comment" = "bored munchkins can be quite troublesome - they have set fire to thieves and banged on fighters helms (folio 16)",
    }, {
      "name" = "jouMjkLeaveChanceCumulative",
      "value" = true,
      "comment" = "the leave chance is cumulative per week (folio 16)",
    }, {
      "name" = "jouMjkEscapeFlyingTeleport",
      "value" = true,
      "comment" = "normal munchkins can be escaped by flying or teleporting (folio 16)",
    }, {
      "name" = "jouMjkMagicEscapePrevented",
      "value" = true,
      "comment" = "the escape does not work against the magic variety (folio 16)",
    }, {
      "name" = "jouMjkSlayingWeaponAutoKill",
      "value" = true,
      "comment" = "the only way to kill a munchkin is a special weapon such as a Sword of Munchkin Slaying - it kills automatically upon scoring a hit (folio 16)",
    }, {
      "name" = "jouMjkAncientItemsDetect",
      "value" = true,
      "comment" = "some magic items can detect approaching munchkins - even the most ancient sometimes can (folio 16)",
    }, {
      "name" = "jouMjkNotForNormalExpeditions",
      "value" = true,
      "comment" = "the munchkins should not be employed in normal dungeon expeditions - high-level bored parties and hot-shots only (folio 16)",
    }, {
      "name" = "jouSchPipeSmokeInvisibility",
      "value" = true,
      "comment" = "the foul pipe smoke can be generated in sufficient volume to produce Invisibility (folio 16)",
    }, {
      "name" = "jouSchTenureDeniedNoSave",
      "value" = true,
      "comment" = "the one powerful spell that seizes Scholars with immediate cardiac arrest, no saving throw - the incantation is Tenure denied (folio 17)",
    }, {
      "name" = "jouSchCauseBoredomSleep",
      "value" = true,
      "comment" = "Cause Boredom speedily induces gentle and peaceful sleep and the clock finally begins to move (folio 17)",
    }, {
      "name" = "jouSchThreeRanks",
      "value" = true,
      "comment" = "three levels of Scholars exist - Instructors, Associate Professors and Fool Professors (folio 16)",
    }, {
      "name" = "jouCrsHdHalf",
      "value" = true,
      "comment" = "the hit dice print 1/2 - half a hit die, pinned as the half marker (folio 17)",
    }, {
      "name" = "jouCrsAlwaysSmilingWellDressed",
      "value" = true,
      "comment" = "the Crs'tchen are never seen without their assumed human form, always smiling and well-dressed (folio 17)",
    }, {
      "name" = "jouCrsBookOfEternalExistence",
      "value" = true,
      "comment" = "the Book of Eternal Existence - never without it, may attempt to read from it as an offensive action (folio 17)",
    }, {
      "name" = "jouCrsBookSelfTranslating",
      "value" = true,
      "comment" = "the Book senses whatever language the character knows and becomes translated to that language (folio 17)",
    }, {
      "name" = "jouCrsBookAcHigherThanOwner",
      "value" = true,
      "comment" = "the Book is usually covered in leather and its armour class is higher than that of its owner (folio 17)",
    }, {
      "name" = "jouCrsSaveLevelThreePlus",
      "value" = true,
      "comment" = "levels III and higher are permitted a saving throw against the discourse (folio 17)",
    }, {
      "name" = "jouCrsMagicUserControlOfSelf",
      "value" = true,
      "comment" = "Magic Users are allowed to use control of self (folio 17)",
    }, {
      "name" = "jouCrsRegeneratesUnlessBurned",
      "value" = true,
      "comment" = "the relentless attack - it never rests and hounds the victim until killed or lost (folio 17)",
    }, {
      "name" = "jouCrsRelentless",
      "value" = true,
      "comment" = "the Crs'tchen attacks relentlessly and from so many angles (folio 17)",
    }, {
      "name" = "jouCrsLairCaptureLost",
      "value" = true,
      "comment" = "taken to one of their lairs, the forces there are too powerful - you are lost (folio 17)",
    }, {
      "name" = "jouCrsDivineInterventionSaves",
      "value" = true,
      "comment" = "a victim once caught may be saved by Divine Intervention or Eyes No. 1, 16 and 19 (folio 17)",
    }, {
      "name" = "jouTsvAnyDoorOpenNotActivated",
      "value" = true,
      "comment" = "so long as any door remains open, the tesseract is not activated - the party passes through room C as though the others did not exist (folio 20)",
    }, {
      "name" = "jouTsvAllClosedActivates",
      "value" = true,
      "comment" = "if all four doors are closed at the same time, no matter how briefly, thereafter all doors lead to the next room of the tesseract (folio 20)",
    }, {
      "name" = "jouTsvEscapeItemDoctrine",
      "value" = true,
      "comment" = "some escape method should be provided - a magical item such as a ring or bracelet, usable only in this tesseract (folio 20)",
    }, {
      "name" = "jouTsvDispelVanishesAllButCentral",
      "value" = true,
      "comment" = "a dispell magic spell would cause every room except C to instantly disappear, along with anyone in them (folio 20)",
    }, {
      "name" = "jouTsvUpDownUpsideDownAnomaly",
      "value" = true,
      "comment" = "entering F by climbing through the ceiling of U, one finds oneself climbing through the ceiling of F upside down - the corollary holds for L (folios 20+22)",
    }, {
      "name" = "jouTsvNoUpDownAccessRecommended",
      "value" = true,
      "comment" = "unless the DM delights in people falling on their heads, no access between L or U and F should be designed in (folio 22 cont.)",
    }, {
      "name" = "jouTsvUpperLowerAccessPlanned",
      "value" = true,
      "comment" = "some access should be planned for the U and L rooms directly above and below the central room (folio 20)",
    }, {
      "name" = "jouAdmDiamondScratchesImitations",
      "value" = true,
      "comment" = "the best way to test for true adamanite is with a diamond - it scratches all imitations but not the real thing (folio 32)",
    }, {
      "name" = "jouAdmCharmTwiceCostTwiceTime",
      "value" = true,
      "comment" = "adamanite costs twice as much and twice as long as iron to charm for the first three levels (folio 31)",
    }, {
      "name" = "jouAdmCharmZoomAfterThree",
      "value" = true,
      "comment" = "after the first three levels both price and time zoom way out of proportion (folio 31)",
    }, {
      "name" = "jouAdmUnstableImitations",
      "value" = true,
      "comment" = "the imitation leaning heavily on mithril can increase HP and AC but is unstable (folio 32)",
    }, {
      "name" = "jouAdmMuCostHalfListed",
      "value" = true,
      "comment" = "the MU cost is approximately half the listed price - purchase direct from a MU assumed (folio 32)",
    }, {
      "name" = "jouAdmReluctantMuMarket",
      "value" = true,
      "comment" = "because of the MU reluctance, a person with +5 armor or shield can just about name his price (folio 32)",
    }, {
      "name" = "jouAdmArrowPointsPerArrowAt",
      "value" = true,
      "comment" = "the arrow points price prints 400@ - per arrow at 400 GP, the at-sign riding the transcript (folio 32)",
    }, {
      "name" = "jouAngTeleportNoError",
      "value" = true,
      "comment" = "all angels teleport with no chance of error (folio 33)",
    }, {
      "name" = "jouAngContinualLightCommon",
      "value" = true,
      "comment" = "the Continual Light of varying degree is common to all angels (folio 33)",
    }, {
      "name" = "jouAngBlessCommon",
      "value" = true,
      "comment" = "the Bless is common to all angels (folio 33)",
    }, {
      "name" = "jouAngFearCommon",
      "value" = true,
      "comment" = "the Fear is common to all angels (folio 33)",
    }, {
      "name" = "jouAngDetectEvilCommon",
      "value" = true,
      "comment" = "the Detect Evil is common to all angels (folio 33)",
    }, {
      "name" = "jouAngSpeakHumanTongues",
      "value" = true,
      "comment" = "all angels can speak any human tongue (folio 33)",
    }, {
      "name" = "jouAngSpeakWithDead",
      "value" = true,
      "comment" = "all angels can Speak With Dead (folio 33)",
    }, {
      "name" = "jouAngTurnUndeadAsPatriarch",
      "value" = true,
      "comment" = "the very presence of an angel turns undead as a Patriarch (folio 33)",
    }, {
      "name" = "jouAngImmunePsionic",
      "value" = true,
      "comment" = "angels are immune to psionic attack (folio 33)",
    }, {
      "name" = "jouAngImmuneFingerOfDeath",
      "value" = true,
      "comment" = "angels are immune to the Finger of Death (folio 33)",
    }, {
      "name" = "jouAngWrathArmorVanishes",
      "value" = true,
      "comment" = "the Wrath golden armor, shield and sword disappear if the angel is vanquished (folio 33)",
    }, {
      "name" = "jouAngHealingRegenerationTouch",
      "value" = true,
      "comment" = "the Angel of Healing touch has the ability of Regeneration (folio 33)",
    }, {
      "name" = "jouAngHealingFlamingSword",
      "value" = true,
      "comment" = "if necessary the Angel of Healing fights with a Flaming Sword (folio 33)",
    }, {
      "name" = "jouAngMercySwordOfSharpness",
      "value" = true,
      "comment" = "the Archangel of Mercy fights with a Sword of Sharpness (folio 33)",
    }, {
      "name" = "jouAngMercyNoTimeStop",
      "value" = true,
      "comment" = "the Archangel of Mercy is not affected by a Time Stop (folio 33)",
    }, {
      "name" = "jouAngSeraphVorpalBlade",
      "value" = true,
      "comment" = "the Seraphim fights with a Vorpal Blade (folio 33)",
    }, {
      "name" = "jouAngSeraphUnstunnable",
      "value" = true,
      "comment" = "a Seraphim cannot be Time Stopped, Charmed, Held, or rendered stunned or unconscious by any means (folio 33)",
    }, {
      "name" = "jouAngNoLairUnlessRelic",
      "value" = true,
      "comment" = "angels have no earthly lair or treasure unless guarding some Holy Relic (folio 33)",
    }, {
      "name" = "jouAngNoRandomEncounters",
      "value" = true,
      "comment" = "there should be no random encounters with angels (folio 33)",
    }, {
      "name" = "jouAngMissionManifestationOnly",
      "value" = true,
      "comment" = "angels should only appear on Earth with a particular mission, a manifestation of a god will (folio 33)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "jouMatrix",
      "tag" = "Jm",
      "count" = "jouMatrixRows",
      "sentinel" = -1,
      "audit_comment" = "the joust matrix - eight aiming points over six defensive positions, the printed base numbers added to the d20 roll; the HELM row Steady Seat cell prints 0* (the glancing-blow helm knock-off), pinned 0 with the flag (folio 4, PDF 6)",
      "cols" = { "jouLowerHelm", "jouLeanRight", "jouLeanLeft", "jouSteadySeat", "jouShieldHigh", "jouShieldLow" },
      "col_comments" = { "versus Lower Helm - the aiming point 1 column (folio 4)", "versus Lean Right - the position 2 column (folio 4)", "versus Lean Left - the position 3 column (folio 4)", "versus Steady Seat - the position 4 column, the HELM 0* cell (folio 4)", "versus Shield High - the position 5 column (folio 4)", "versus Shield Low - the position 6 column (folio 4)" },
      "data" = { { 0, 0, 0, 0, 12, 0 }, { 12, 4, 0, 4, 4, 0 }, { 9, 12, 2, 4, 9, 12 }, { 2, 0, 4, 2, 2, 12 }, { 4, 9, 0, 4, 0, 4 }, { 9, 2, 4, 9, 9, 4 }, { 2, 0, 9, 2, 2, 2 }, { 4, 2, 12, 4, 9, 4 } },
    }, {
      "name" = "jouAttacker",
      "tag" = "Ja",
      "count" = "jouMatrixRows",
      "sentinel" = -1,
      "audit_comment" = "the attacker position grid - which defensive positions an attacker may take, considering his own aiming point: the 4-6, 3-6, Any, 2,4-6 and 1,4-6 prints encoded as one-allowed, zero-not-allowed per column (folio 4, PDF 6)",
      "cols" = { "jouAttLowerHelm", "jouAttLeanRight", "jouAttLeanLeft", "jouAttSteadySeat", "jouAttShieldHigh", "jouAttShieldLow" },
      "col_comments" = { "may take Lower Helm - position 1 allowed: only BASE among the aiming points (folio 4)", "may take Lean Right - position 2 allowed: SC among them (folio 4)", "may take Lean Left - position 3 allowed: DC and SC (folio 4)", "may take Steady Seat - position 4 allowed (folio 4)", "may take Shield High - position 5 allowed (folio 4)", "may take Shield Low - position 6 allowed (folio 4)" },
      "data" = { { 0, 0, 0, 1, 1, 1 }, { 0, 0, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 0, 1, 0, 1, 1, 1 }, { 0, 0, 0, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 0, 0, 0, 1, 1, 1 }, { 1, 0, 0, 1, 1, 1 } },
    }, {
      "name" = "jouResults",
      "tag" = "Jr",
      "count" = "jouResultsRows",
      "sentinel" = -1,
      "audit_comment" = "the joust results table - the minimum adjusted score per result row across the seven knight level comparison bands, from -12 or more through 12-up (folio 4, PDF 6)",
      "cols" = { "jouResMinus12", "jouResMinus8", "jouResMinus4", "jouResMinus3to3", "jouResPlus4", "jouResPlus8", "jouResPlus12" },
      "col_comments" = { "the -12 or more band column (folio 4)", "the -11 to -8 band column (folio 4)", "the -7 to -4 band column (folio 4)", "the -3 to 3 band column (folio 4)", "the 4-7 band column (folio 4)", "the 8-11 band column (folio 4)", "the 12-up band column (folio 4)" },
      "data" = { { 25, 23, 21, 20, 19, 17, 15 }, { 23, 21, 19, 18, 17, 15, 13 }, { 21, 19, 17, 16, 15, 13, 11 }, { 17, 15, 13, 12, 11, 9, 7 } },
    }, {
      "name" = "jouInjury",
      "tag" = "Ji",
      "count" = "jouInjuryRows",
      "sentinel" = -1,
      "audit_comment" = "the joust injury percentile table - six bands, hit points lost as a percentage of total, from 01-60 at 10 percent to the 00 kill; the 00 row pins the percent 100 with the hp column 0 - the knight is KILLED, the 0 is the kill marker not a zero loss (folio 4, PDF 6)",
      "cols" = { "jouInjuryUpper", "jouInjuryHpPct" },
      "col_comments" = { "the percentile band upper bound - 60, 75, 85, 95, 99 and the 00 roll pinned as 100 (folio 4)", "the hit points lost - 10, 25, 33, 50 and 80 percent; the 00 row 0 is the kill marker (folio 4)" },
      "data" = { { 60, 10 }, { 75, 25 }, { 85, 33 }, { 95, 50 }, { 99, 80 }, { 100, 0 } },
    }, {
      "name" = "jouAdmPrice",
      "tag" = "Jd",
      "count" = "jouAdmRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 1 },
      "audit_comment" = "the adamanite base price grid - ten rows of handcrafted uncharmed +2 equipment, price in GP and weight in GP; the arrow points weight prints nil and rides the sentinel, the price printing 400@ per arrow (folios 31-32, PDF 33-34)",
      "cols" = { "jouAdmPriceGold", "jouAdmWeightGold" },
      "col_comments" = { "the equipment price in GP - plate 20000, chain 14000, helm 4000, shield 4000, broad sword 4000, two-handed sword 5000, battle-axe 3000, mace and flail 2000, dagger 1500, arrow points 400 at (folios 31-32)", "the equipment weight in GP - the arrow points weight prints nil and pins the sentinel (folios 31-32)" },
      "data" = { { 20000, 600 }, { 14000, 400 }, { 4000, 40 }, { 4000, 120 }, { 4000, 40 }, { 5000, 120 }, { 3000, 80 }, { 2000, 80 }, { 1500, 16 }, { 400, -1 } },
    }, {
      "name" = "jouAngStat",
      "tag" = "Jg",
      "count" = "jouAngRows",
      "sentinel" = -1,
      "sentinel_census" = { 1, 0, 3, 0, 0, 1, 0 },
      "audit_comment" = "the four angel types in printed order - the Angel of Wrath, the Angel of Healing, the Archangel of Mercy, the Seraphim; only the Wrath prints its hit-dice sides (eight-sided), the other three ride the sentinel; the Healing secondary move prints the garbled quarter and rides the sentinel; the weapon floor is the magic-plus needed to hit, 0 where none prints; the Mercy AC minus 1 is genuine ink that shares the sentinel value - the AC census of 1 locks it, the pin IS the value (folios 32-33, PDF 34-35)",
      "cols" = { "jouAngAc", "jouAngHitDice", "jouAngDiceSides", "jouAngMagicResist", "jouAngMovePrimary", "jouAngMoveSecondary", "jouAngWeaponFloor" },
      "col_comments" = { "the armor class - 0, 9, minus 1 and minus 3 (folios 32-33)", "the hit dice - 10, 6, 12 and 16 (folios 32-33)", "the hit-dice sides - only the Wrath prints eight-sided; the three unspecified prints ride the sentinel (folios 32-33)", "the magic resistance - 65 without the Holy Sword, 75, 85 without the sword, 95 base (folios 32-33)", "the primary move in feet - 12, 15, 15 and 24 (folios 32-33)", "the secondary move in feet - the Healing 15/24 quarter-garble rides the sentinel, never guessed; 24, 30 and 48 pin clean (folios 32-33)", "the weapon floor - any magic weapon for the Wrath, none printed for the Healing at 0, plus 2 or better for the Mercy, plus 3 for the Seraphim (folios 32-33)" },
      "data" = { { 0, 10, 8, 65, 12, 24, 1 }, { 9, 6, -1, 75, 15, -1, 0 }, { -1, 12, -1, 85, 15, 30, 2 }, { -3, 16, -1, 95, 24, 48, 3 } },
    } },
  "chains" = { {
      "name" = "jouLevelBand",
      "limits" = { -12, -8, -4, 3, 7, 11 },
      "tail" = 6,
      "comment" = "the knight level comparison band - A level minus B level: minus 12 or more lands band 0, minus 11 to minus 8 band 1, minus 7 to minus 4 band 2, minus 3 to 3 band 3, 4-7 band 4, 8-11 band 5, 12-up band 6 (folio 4, PDF 6)",
    } },
  "examples" = { {
      "expr" = "m['jouUnhorsedInjuryPercent']() != 10 or m['jouHelmKnockoffInjuryBonusPercent']() != 20 or m['jouMatrixDieSides']() != 20 or m['jouResolutionSteps']() != 6 or m['jouLevelBand'](-12) != 0 or m['jouLevelBand'](-11) != 1 or m['jouLevelBand'](3) != 3 or m['jouLevelBand'](12) != 6",
      "note" = "the jousting doctrine - a 10 percent injury chance on unhorsing, 20 added on the helm knock-off, the d20 matrix, the six resolution steps, the level-comparison bands at their edges (folio 4)",
    }, {
      "expr" = "m['jouVmpGaseousSpeedMph']() != 50 or m['jouVmpStakeStrokesMax']() != 4 or m['jouVmpCrumbleDustAgeYears']() != 100 or m['jouVmpMinStrength']() != -1 or m['jouSsgSoundChancePercent']() != 25 or m['jouSsgSoundIntervalMinutes']() != 30 or m['jouSsgSoundRows']() != 21 or m['jouSsgSightRows']() != 20",
      "note" = "the vampire and dressing doctrine - the 50 mph gaseous rush, the four-stroke stake maximum, the century crumble, the garbled strength cell at the sentinel, the 25 percent noise chance every 30 minutes, the 21-row sounds print and the 20 sights (folios 3, 15)",
    }, {
      "expr" = "m['jouMjkClanMax']() != 12 or m['jouMjkMotherHeightInches']() != 48 or m['jouMjkMagicChancePercent']() != 10 or m['jouMjkMagicPerGroup']() != 25 or m['jouMjkMagicCasterLevel']() != 18 or m['jouMjkMotherSpellsPerDay']() != 3 or m['jouSchArmorClass']() != 9 or m['jouSchLairPercent']() != 30 or m['jouSchTreasureCopper']() != 5 or m['jouSchDustMax']() != 18",
      "note" = "the joke monsters - munchkin clans to 12, the four-foot mother, one magic munchkin in ten per 25 casting at eighteenth level, the mother at three spells a day, the Scholar AC 9, 30 percent lair, 5 cp and the 3-18 Academic Dust (folios 16-17)",
    }, {
      "expr" = "m['jouCrsArmorClass']() != 12 or m['jouCrsMoveFeet']() != 15 or m['jouCrsAlignmentChangePercent']() != 33 or m['jouCrsBegMoneyMaxK']() != 600 or m['jouCrsBurnWithinTurns']() != 3 or m['jouCrsEyeSixteen']() != 16 or m['jouTsvRooms']() != 8 or m['jouTsvCentralDoors']() != 4 or m['jouTsvCommonEdges']() != 4",
      "note" = "the Crs'tchen and the tesseract - AC 12 in the EPT print, move 15, the 33 percent alignment change, the 100-600 K beg, burn within three turns, Eye 16, eight tesseract rooms with four central doors and four common edges (folios 17, 20+22)",
    }, {
      "expr" = "m['jouAdmCharmCostPlatePerLevel']() != 8000 or m['jouAdmCharmCostSwordShieldPerLevel']() != 4000 or m['jouAdmHardenedPriceMin']() != 20 or m['jouAdmTemperablePriceMax']() != 60 or m['jouAdmSnogFighterLevel']() != 8 or m['jouAdmTributeKingPercent']() != 50 or m['jouAdmTributeChurchPercent']() != 25 or m['jouAdmImitationPlusFirst']() != 2",
      "note" = "the adamanite economics - 8000 GP per level to charm plate, 4000 for sword or shield, the 20-40 hardened and 25-60 temperable multipliers, Snog the 8th level goblin, the 50-25-25 tribute split, the unstable +2 imitation (folio 32)",
    }, {
      "expr" = "m['jouAngResponseBasePercent']() != 1 or m['jouAngRecordedTypes']() != 4 or m['jouAngHierarchyTypes']() != 9 or m['jouAngWrathSwordPlus']() != 5 or m['jouAngWrathWallPerDay']() != 3 or m['jouAngSeraphWallMultiplier']() != 3 or m['jouAngSeraphHolyWordPerDay']() != 1 or m['jouAngSummonOneMin']() != 2 or m['jouAngSummonOneMax']() != 16",
      "note" = "the angels - the 1 percent per level prayer response, nine classical types with four recorded, the Wrath +5 Holy Sword and three double-strength walls a day, the Seraphim triple-strength wall, Holy Word and the 2-16 Type I summons (folios 32-33)",
    } },
  "audit" = {
      "label" = "R931 issue-17 opener part one audit",
      "comment" = "THE DRAGON ISSUE-17 OPENER PART ONE - the seven engine-relevant chains of the potpourri issue, the Ward wizard article riding the part-two round. CHAIN ONE, Jousting in D&D by Jon Pickens (print 4, PDF 6), the Chainmail system rebuilt for D&D levels and magical equipment: the eight-by-six joust matrix (HELM, DC, CP, SC, DF, FP, SF, BASE over Lower Helm, Lean Right, Lean Left, Steady Seat, Shield High, Shield Low), the attacker position grid (the 4-6, 3-6, Any, 2,4-6, 1,4-6 prints as allowed flags), the four-row results table across seven knight level comparison bands (U at 25-15, U/B at 23-13, B at 21-11, G at 17-7), the six-band injury percentile table from 10 percent to the 00 kill, the level-comparison chain, the 10 percent unhorsed injury with 20 added on the helm knock-off, the no-strength-dex-bonus doctrine. CHAIN TWO, Vampires in the Dungeon by Clayton Miner (print 3, PDF 5), the tactics doctrine: the charm-many-then-banquet, the rat spy network, the 50 mph gaseous offensive, the stake doctrine at four strokes maximum of hawthorn or blackthorn, the century crumble, the coffin booby traps, the 8:69 strength garble at the sentinel. CHAIN THREE, Sights and Sounds in D&D by Dushay and Weisberg (print 15, PDF 17): the 25 percent noise chance every 30 minutes, the 21-row sounds table as scanned with the joke row 21, the 20-row sights table, the real-to-all-senses apparitions that vanish after the party leaves. CHAIN FOUR, the joke monsters (print 16-17, PDF 18-19), pinned with their printed stat ink - the Magic Munchkin (clans 3-12, the four-foot mother, one magic munchkin in ten per 25 casting at eighteenth level, the 5 percent weekly cumulative leave chance, the Munchkin Slaying auto-kill), the Scholar (AC 9, HD 1-3, lair 30, 5 cp, the three ranks with their spell counts, the 3-18 Academic Dust, the Tenure denied cardiac arrest), the Crs'tchen (NA 1-12, AC 12, HD 1/2, move 15, the 33 percent alignment change, the 30-30-30-5-5 transfix table, the 100-600 K beg, burn within three turns, Eyes 1, 16 and 19). CHAIN FIVE, the Tesseracts by Gary Jordan (print 20 + 22, PDF 22 + 24), the hypercube dungeon: eight rooms, four central doors, the all-doors-closed activation, the U/L upside-down anomaly, the dispel collapse. CHAIN SIX, A Short History of Adamanite (print 31-32, PDF 33-34): the ten-row base price grid from plate 20000 to arrow points 400@ with the nil weight at the sentinel, the charm costs 8000 per level plate and 4000 sword or shield beyond the +2, the 20-40 and 25-60 market multipliers, the Snog 8th level goblin tale with the 50-25-25 tribute split, the diamond test. CHAIN SEVEN, Messengers of God: Angels in D&D by Stephen Dorneman (print 32-33, PDF 34-35): the four-type stat grid (Wrath AC 0, 10d8, MR 65, 12/24; Healing AC 9, 6 dice, MR 75; Mercy AC -1, 12 dice, MR 85, 15/30; Seraphim AC -3, 16 dice, MR 95, 24/48), the weapon floors 1, 0, 2, 3, the common abilities doctrine (teleport no error, turn undead as Patriarch, immune to psionic and Finger of Death), the 1 percent per cleric level prayer response, the Wrath +5 Holy Sword and three double-strength walls, the Seraphim triple-strength wall, Holy Word and Symbol once a day, the Wrath of God double-strength Meteor Swarm, the 2-16, 1-4, 1-6 summons.",
    },
}
