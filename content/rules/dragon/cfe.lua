-- cfe: promoted from tools/spec_r900.json (the The Dragon issue-4 opener - the Creature Features chain: the Mihalli (folios 18-19), the Vriyagga (folios 19, 21) and the Qu'uni (folio 21), pinned as new variant-layer registry monsters);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 900,
  "prefix" = "cfe",
  "banner" = {
      "title" = "The Dragon issue-4 opener - the Creature Features chain: the Mihalli (folios 18-19), the Vriyagga (folios 19, 21) and the Qu'uni (folio 21), pinned as new variant-layer registry monsters",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 4 (December 1976), the archive.org scan: folios 18-19, the Mihalli - the humanoid hermaphroditic shape-changers with the 20 percent red-eye reveal, the two-to-three-plus bonus spells, the 40 percent Eyes/amulets/scrolls lair chance and the four-step Ball of Immediate Eventuation colour ladder reserved to the fourteenth level and up; folios 19 and 21, the Vriyagga - the tentacled city creature with the 12/10/8 move, the 10/15/25 hit-dice ladder, the four-plus armor-class-2 tentacles and the 2/4/6 dice per turn; folio 21, the Qu'uni sidebar - the pallid semi-transparent shrimp-like water-grotto swarm. The voice rides extract/dragon/004/ (all 36 issue pages, the chat-side DjVu OCR transcript cross-checked against the archive.org PDF text layer); the issue-4 gap report ships pre-flip. The editor's standing caution rides: none of this is official.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon, and with no 1e defs existing the Creature Features chain pins as NEW registry monsters - the Remorhaz lore-against-def precedent does not apply. The XP conversions ride the DMG p.85 additive formula (the Mihalli 115 base + 3 per hp at 13 average, the Vriyagga 5250 + 20 per hp at 67, the Qu'uni 20 + 2 per hp at 9), the averages at the 4.5-per-die d8 convention floored, every conversion noted, never silent; the print's 'l-20' glyph pins as 1, the garbled F: 50 and I: 50 stat lines ride AS SCANNED with the semantics unpinned, the tentacle damage dice assume d6 noted, and the Vriyagga XP pins the 15-dice middle size with the full size ladder in the pin header; the three lua defs carry the new dragon_print xp source, whitelisted at the R73 audit.",
    },
  "consts" = { {
      "name" = "cfeMihalliNaMin",
      "value" = 1,
      "comment" = "the number appearing minimum - NA 1-20 (folio 18); the print's 'l-20' glyph pins as 1, the OCR-of-font artifact noted",
    }, {
      "name" = "cfeMihalliNaMax",
      "value" = 20,
      "comment" = "the number appearing maximum - NA 1-20 (folio 18)",
    }, {
      "name" = "cfeMihalliAc",
      "value" = 1,
      "comment" = "the armor class - AC 1 (folio 18)",
    }, {
      "name" = "cfeMihalliMove",
      "value" = 15,
      "comment" = "the movement rate - M 15 inches per turn (folio 18)",
    }, {
      "name" = "cfeMihalliHd",
      "value" = 3,
      "comment" = "the hit dice - HD 3 (folio 18)",
    }, {
      "name" = "cfeMihalliLairPct",
      "value" = 40,
      "comment" = "the chance of treasure in lair - L 40 percent (folio 18)",
    }, {
      "name" = "cfeMihalliLairMin",
      "value" = 80,
      "comment" = "the lair gold minimum - 80-800 only near own territory (folio 18)",
    }, {
      "name" = "cfeMihalliLairMax",
      "value" = 800,
      "comment" = "the lair gold maximum - 80-800 only near own territory (folio 18)",
    }, {
      "name" = "cfeMihalliF",
      "value" = 50,
      "comment" = "the print stat line F: 50 - the glyph garbles in both the PDF layer and the OCR (folio 18); pinned AS SCANNED, semantics unpinned",
    }, {
      "name" = "cfeMihalliI",
      "value" = 50,
      "comment" = "the print stat line I: 50 - the glyph garbles in both the PDF layer and the OCR (folio 18); pinned AS SCANNED, semantics unpinned",
    }, {
      "name" = "cfeMihalliRedEyesPct",
      "value" = 20,
      "comment" = "the glowing red eyes reveal the Mihalli 20 percent of the turns they are looked at (folio 18)",
    }, {
      "name" = "cfeMihalliBonusSpellsMin",
      "value" = 2,
      "comment" = "the minimum two bonus spells of the higher Mihalli (folios 18-19)",
    }, {
      "name" = "cfeMihalliBonusSpellsHigh",
      "value" = 3,
      "comment" = "the three-plus bonus spells at levels IV and up (folios 18-19)",
    }, {
      "name" = "cfeMihalliEyeChancePct",
      "value" = 40,
      "comment" = "the 40 percent chance of Eyes, amulets or scrolls (folios 18-19)",
    }, {
      "name" = "cfeMihalliBallLadderCount",
      "value" = 4,
      "comment" = "the Ball of Immediate Eventuation climbs a four-step colour ladder (folio 19)",
    }, {
      "name" = "cfeMihalliBallPurple",
      "value" = 1,
      "comment" = "the ball ladder step 1 - light purple (folio 19)",
    }, {
      "name" = "cfeMihalliBallSilver",
      "value" = 2,
      "comment" = "the ball ladder step 2 - bright silver (folio 19)",
    }, {
      "name" = "cfeMihalliBallGold",
      "value" = 3,
      "comment" = "the ball ladder step 3 - bright gold (folio 19)",
    }, {
      "name" = "cfeMihalliBallBlue",
      "value" = 4,
      "comment" = "the ball ladder step 4 - lambent translucent blue (folio 19)",
    }, {
      "name" = "cfeMihalliUseLevelMin",
      "value" = 14,
      "comment" = "the ball is usable only by magic users and priests of the fourteenth level and up - below that it scrambles brains (folio 19)",
    }, {
      "name" = "cfeMihalliFriendlyPct",
      "value" = 5,
      "comment" = "the 5 percent chance a Mihalli is friendly - rolled each turn (folio 19)",
    }, {
      "name" = "cfeMihalliOfferItemPct",
      "value" = 1,
      "comment" = "the 1 percent chance a friendly Mihalli offers a magical item (folio 19)",
    }, {
      "name" = "cfeMihalliAvgHp",
      "value" = 13,
      "comment" = "the average hit points - 3 dice at the 4.5-per-die d8 convention, floored; the conversion noted, never silent",
    }, {
      "name" = "cfeMihalliXp",
      "value" = 115,
      "comment" = "the base XP - DMG p.85 formula: 35 base + 25 one special + 55 one exceptional (folios 18-19); the conversion noted",
    }, {
      "name" = "cfeMihalliXpPerHp",
      "value" = 3,
      "comment" = "the XP per hit point - the DMG p.85 per-hit-die value at 3 dice (folios 18-19)",
    }, {
      "name" = "cfeMihalliXpValue",
      "value" = 154,
      "comment" = "the XP value - 115 + 3 x 13, the DMG p.85 additive formula (folios 18-19)",
    }, {
      "name" = "cfeVriyaggaNaMin",
      "value" = 1,
      "comment" = "the number appearing minimum - NA 1-10 (folio 19)",
    }, {
      "name" = "cfeVriyaggaNaMax",
      "value" = 10,
      "comment" = "the number appearing maximum - NA 1-10 (folio 19)",
    }, {
      "name" = "cfeVriyaggaAc",
      "value" = 1,
      "comment" = "the armor class - AC 1 (folio 19)",
    }, {
      "name" = "cfeVriyaggaLairPct",
      "value" = 40,
      "comment" = "the L 40 percent stat line (folio 19) - the treasure itself is nil, the nil-in-lair bool carries the print",
    }, {
      "name" = "cfeVriyaggaCityMin",
      "value" = 20,
      "comment" = "the in-own-city number minimum - 20-200 (folio 19)",
    }, {
      "name" = "cfeVriyaggaCityMax",
      "value" = 200,
      "comment" = "the in-own-city number maximum - 20-200 (folio 19)",
    }, {
      "name" = "cfeVriyaggaTentaclesMin",
      "value" = 4,
      "comment" = "the minimum four tentacles, more in the larger forms (folio 21)",
    }, {
      "name" = "cfeVriyaggaTentacleAc",
      "value" = 2,
      "comment" = "it takes armor class 2 to sever a tentacle (folio 21)",
    }, {
      "name" = "cfeVriyaggaAvgHp",
      "value" = 67,
      "comment" = "the average hit points - the 15-dice middle size at the 4.5-per-die d8 convention, floored; the conversion noted, never silent",
    }, {
      "name" = "cfeVriyaggaXp",
      "value" = 5250,
      "comment" = "the base XP - the DMG p.85 formula at the 15-dice middle size: 2400 + 1250 + 1600 (folio 19); the conversion noted",
    }, {
      "name" = "cfeVriyaggaXpPerHp",
      "value" = 20,
      "comment" = "the XP per hit point - the DMG p.85 per-hit-die value at 15 dice (folio 19)",
    }, {
      "name" = "cfeVriyaggaXpValue",
      "value" = 6590,
      "comment" = "the XP value - 5250 + 20 x 67, the DMG p.85 additive formula (folio 19)",
    }, {
      "name" = "cfeVriyaggaSizesCount",
      "value" = 3,
      "comment" = "the cfeVriyaggaSizes table runs 3 rows (folios 19, 21)",
    }, {
      "name" = "cfeQuuniHd",
      "value" = 2,
      "comment" = "the hit dice - 2 (folio 21 sidebar)",
    }, {
      "name" = "cfeQuuniMove",
      "value" = 10,
      "comment" = "the movement rate - 10 inches per turn (folio 21 sidebar)",
    }, {
      "name" = "cfeQuuniNaMin",
      "value" = 50,
      "comment" = "the number appearing minimum - 50-100 (folio 21 sidebar)",
    }, {
      "name" = "cfeQuuniNaMax",
      "value" = 100,
      "comment" = "the number appearing maximum - 50-100 (folio 21 sidebar)",
    }, {
      "name" = "cfeQuuniAc",
      "value" = 3,
      "comment" = "the armor class - AC 3 (folio 21 sidebar)",
    }, {
      "name" = "cfeQuuniAvgHp",
      "value" = 9,
      "comment" = "the average hit points - 2 dice at the 4.5-per-die d8 convention, floored; the conversion noted, never silent",
    }, {
      "name" = "cfeQuuniXp",
      "value" = 20,
      "comment" = "the base XP - the DMG p.85 formula at 2 dice, no specials (folio 21 sidebar); the conversion noted",
    }, {
      "name" = "cfeQuuniXpPerHp",
      "value" = 2,
      "comment" = "the XP per hit point - the DMG p.85 per-hit-die value at 2 dice (folio 21 sidebar)",
    }, {
      "name" = "cfeQuuniXpValue",
      "value" = 38,
      "comment" = "the XP value - 20 + 2 x 9, the DMG p.85 additive formula (folio 21 sidebar)",
    }, {
      "name" = "cfeRegistryAfter",
      "value" = 1311,
      "comment" = "the live lua def census after the three promotions - the 1308 loaded base defs plus the Mihalli, the Vriyagga and the Qu'uni; the 1333 base lua files include 25 long-standing load-error defs (broken text lines) that never enter the registry, a pre-R900 print-fidelity state this round does not touch (the Termux battery line 'loaded 1311, errors 25' is the ground truth)",
    } },
  "bools" = { {
      "name" = "cfeMihalliShapeChanger",
      "value" = true,
      "comment" = "the Mihalli are shape-changers (folio 19)",
    }, {
      "name" = "cfeMihalliHumanoid",
      "value" = true,
      "comment" = "the Mihalli are humanoid (folio 19)",
    }, {
      "name" = "cfeMihalliHermaphroditic",
      "value" = true,
      "comment" = "the Mihalli are hermaphroditic (folio 19)",
    }, {
      "name" = "cfeMihalliSeeDark",
      "value" = true,
      "comment" = "the Mihalli see in the dark (folio 19)",
    }, {
      "name" = "cfeMihalliGasSparingShenSsu",
      "value" = true,
      "comment" = "the Mihalli gas spares the Shen and the Ssu (folio 19)",
    }, {
      "name" = "cfeMihalliBallXivUpOnly",
      "value" = true,
      "comment" = "the Ball of Immediate Eventuation is usable only by magic users and priests XIV-up (folio 19)",
    }, {
      "name" = "cfeMihalliScrambleBelowXiv",
      "value" = true,
      "comment" = "below the fourteenth level the ball scrambles brains (folio 19)",
    }, {
      "name" = "cfeMihalliDefendsIfAttacked",
      "value" = true,
      "comment" = "the Mihalli defends itself if attacked (folio 19)",
    }, {
      "name" = "cfeMihalliRandomRollEachTurn",
      "value" = true,
      "comment" = "the reaction is rolled at random each turn (folio 19)",
    }, {
      "name" = "cfeVriyaggaNilTreasure",
      "value" = true,
      "comment" = "the treasure is nil (folio 19)",
    }, {
      "name" = "cfeVriyaggaNilTreasureInLair",
      "value" = true,
      "comment" = "the treasure is nil in lair too - T in L nil (folio 19)",
    }, {
      "name" = "cfeVriyaggaSensesHeat",
      "value" = true,
      "comment" = "the Vriyagga senses heat (folio 21)",
    }, {
      "name" = "cfeVriyaggaCannotSpeak",
      "value" = true,
      "comment" = "the Vriyagga cannot speak (folio 21)",
    }, {
      "name" = "cfeVriyaggaAmbushThinker",
      "value" = true,
      "comment" = "the Vriyagga thinks, organizes and lays ambushes (folio 21)",
    }, {
      "name" = "cfeVriyaggaNoStairs",
      "value" = true,
      "comment" = "the Vriyagga cannot climb stairs (folio 21)",
    }, {
      "name" = "cfeVriyaggaSeeDark",
      "value" = true,
      "comment" = "the black-opal eyes see in the dark (folio 21)",
    }, {
      "name" = "cfeQuuniAttacksWaterSeekers",
      "value" = true,
      "comment" = "the Qu'uni automatically attack human parties seeking water (folio 21 sidebar)",
    }, {
      "name" = "cfeQuuniSeaGrottoTreasure",
      "value" = true,
      "comment" = "no treasure except under the water in its sea-grotto home (folio 21 sidebar)",
    }, {
      "name" = "cfeQuuniNoTreasure",
      "value" = true,
      "comment" = "the Qu'uni carry no treasure (folio 21 sidebar)",
    }, {
      "name" = "cfeQuuniShrimpLike",
      "value" = true,
      "comment" = "the Qu'uni are pallid, semi-transparent, shrimp-like creatures (folio 21 sidebar)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "cfeVriyaggaSizes",
      "tag" = "VriSz",
      "count" = "cfeVriyaggaSizesCount",
      "sentinel" = 30,
      "cols" = { "cfeVriSizeMove", "cfeVriSizeHd", "cfeVriSizeDice" },
      "col_comments" = { "the movement rate by size - 12, 10 and 8 inches per turn (folios 19, 21)", "the hit dice by size - 10, 15 and 25 (folios 19, 21)", "the tentacle damage dice per turn by size - 2, 4 and 6, assumed d6 (folios 19, 21)" },
      "data" = { { 12, 10, 2 }, { 10, 15, 4 }, { 8, 25, 6 } },
      "audit_comment" = "the Vriyagga size ladder - the small, middle and large forms: move 12/10/8 inches, hit dice 10/15/25, tentacle damage 2/4/6 dice per turn (folios 19, 21)",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['cfeVriSizeMove'](0) != 12 or m['cfeVriSizeHd'](0) != 10 or m['cfeVriSizeDice'](0) != 2 or m['cfeVriyaggaSizesCount']() != 3",
      "note" = "the Vriyagga size ladder, row 0 of 3 - the move, hit dice and tentacle damage dice by size (folios 19, 21)",
    }, {
      "expr" = "m['cfeVriSizeMove'](1) != 10 or m['cfeVriSizeHd'](1) != 15 or m['cfeVriSizeDice'](1) != 4",
      "note" = "the Vriyagga size ladder, row 1 of 3 - the move, hit dice and tentacle damage dice by size (folios 19, 21)",
    }, {
      "expr" = "m['cfeVriSizeMove'](2) != 8 or m['cfeVriSizeHd'](2) != 25 or m['cfeVriSizeDice'](2) != 6",
      "note" = "the Vriyagga size ladder, row 2 of 3 - the move, hit dice and tentacle damage dice by size (folios 19, 21)",
    }, {
      "expr" = "m['cfeMihalliNaMin']() != 1 or m['cfeMihalliNaMax']() != 20 or m['cfeMihalliAc']() != 1 or m['cfeMihalliMove']() != 15 or m['cfeMihalliHd']() != 3",
      "note" = "the Mihalli stat block - number appearing 1-20, armor class 1, move 15 inches, 3 hit dice (folio 18)",
    }, {
      "expr" = "m['cfeMihalliLairPct']() != 40 or m['cfeMihalliLairMin']() != 80 or m['cfeMihalliLairMax']() != 800",
      "note" = "the Mihalli lair - 40 percent, 80-800 gold near own territory (folio 18)",
    }, {
      "expr" = "m['cfeMihalliF']() != 50 or m['cfeMihalliI']() != 50",
      "note" = "the Mihalli stat-line garbles - F: 50 and I: 50 pinned AS SCANNED, the glyph semantics unpinned (folio 18)",
    }, {
      "expr" = "m['cfeMihalliRedEyesPct']() != 20 or m['cfeMihalliBonusSpellsMin']() != 2 or m['cfeMihalliBonusSpellsHigh']() != 3 or m['cfeMihalliEyeChancePct']() != 40",
      "note" = "the Mihalli eyes - the 20 percent reveal, the two-to-three-plus bonus spells and the 40 percent Eyes/amulets/scrolls chance (folios 18-19)",
    }, {
      "expr" = "m['cfeMihalliBallLadderCount']() != 4 or m['cfeMihalliBallPurple']() != 1 or m['cfeMihalliBallSilver']() != 2 or m['cfeMihalliBallGold']() != 3 or m['cfeMihalliBallBlue']() != 4",
      "note" = "the Ball of Immediate Eventuation - the four-step colour ladder light purple, bright silver, bright gold, lambent translucent blue (folio 19)",
    }, {
      "expr" = "m['cfeMihalliUseLevelMin']() != 14 or m['cfeMihalliFriendlyPct']() != 5 or m['cfeMihalliOfferItemPct']() != 1",
      "note" = "the ball reserved to the fourteenth level and up, and the 5 percent friendly / 1 percent offer chances (folio 19)",
    }, {
      "expr" = "m['cfeMihalliAvgHp']() != 13 or m['cfeMihalliXp']() != 115 or m['cfeMihalliXpPerHp']() != 3 or m['cfeMihalliXpValue']() != 154",
      "note" = "the Mihalli XP conversion - 13 average hp, base 115, 3 per hp, value 154, the DMG p.85 formula, noted never silent (folios 18-19)",
    }, {
      "expr" = "m['cfeMihalliShapeChanger']() != 1 or m['cfeMihalliHumanoid']() != 1 or m['cfeMihalliHermaphroditic']() != 1 or m['cfeMihalliSeeDark']() != 1",
      "note" = "the Mihalli nature - shape-changers, humanoid, hermaphroditic, seeing in the dark (folio 19)",
    }, {
      "expr" = "m['cfeMihalliGasSparingShenSsu']() != 1 or m['cfeMihalliBallXivUpOnly']() != 1 or m['cfeMihalliScrambleBelowXiv']() != 1",
      "note" = "the gas sparing the Shen and the Ssu, and the ball XIV-up-only scrambling brains below (folio 19)",
    }, {
      "expr" = "m['cfeMihalliDefendsIfAttacked']() != 1 or m['cfeMihalliRandomRollEachTurn']() != 1",
      "note" = "the Mihalli defends if attacked, with the reaction rolled each turn (folio 19)",
    }, {
      "expr" = "m['cfeVriyaggaNaMin']() != 1 or m['cfeVriyaggaNaMax']() != 10 or m['cfeVriyaggaAc']() != 1 or m['cfeVriyaggaLairPct']() != 40",
      "note" = "the Vriyagga stat block - number appearing 1-10, armor class 1, the L 40 line (folio 19)",
    }, {
      "expr" = "m['cfeVriyaggaCityMin']() != 20 or m['cfeVriyaggaCityMax']() != 200",
      "note" = "the Vriyagga in its own city - 20-200 appearing (folio 19)",
    }, {
      "expr" = "m['cfeVriyaggaTentaclesMin']() != 4 or m['cfeVriyaggaTentacleAc']() != 2",
      "note" = "the Vriyagga tentacles - four or more, armor class 2 to sever (folio 21)",
    }, {
      "expr" = "m['cfeVriyaggaAvgHp']() != 67 or m['cfeVriyaggaXp']() != 5250 or m['cfeVriyaggaXpPerHp']() != 20 or m['cfeVriyaggaXpValue']() != 6590",
      "note" = "the Vriyagga XP conversion at the 15-dice middle size - 67 average hp, base 5250, 20 per hp, value 6590, the DMG p.85 formula, noted never silent (folio 19)",
    }, {
      "expr" = "m['cfeVriyaggaNilTreasure']() != 1 or m['cfeVriyaggaNilTreasureInLair']() != 1 or m['cfeVriyaggaSensesHeat']() != 1",
      "note" = "the Vriyagga nil treasure even in lair, and its heat sense (folios 19, 21)",
    }, {
      "expr" = "m['cfeVriyaggaCannotSpeak']() != 1 or m['cfeVriyaggaAmbushThinker']() != 1 or m['cfeVriyaggaNoStairs']() != 1 or m['cfeVriyaggaSeeDark']() != 1",
      "note" = "the Vriyagga mind - cannot speak, thinks and lays ambushes, cannot climb stairs, black-opal eyes in the dark (folio 21)",
    }, {
      "expr" = "m['cfeQuuniHd']() != 2 or m['cfeQuuniMove']() != 10 or m['cfeQuuniNaMin']() != 50 or m['cfeQuuniNaMax']() != 100 or m['cfeQuuniAc']() != 3",
      "note" = "the Qu'uni stat block - 2 hit dice, move 10, 50-100 appearing, armor class 3 (folio 21 sidebar)",
    }, {
      "expr" = "m['cfeQuuniAvgHp']() != 9 or m['cfeQuuniXp']() != 20 or m['cfeQuuniXpPerHp']() != 2 or m['cfeQuuniXpValue']() != 38",
      "note" = "the Qu'uni XP conversion - 9 average hp, base 20, 2 per hp, value 38, the DMG p.85 formula, noted never silent (folio 21 sidebar)",
    }, {
      "expr" = "m['cfeQuuniAttacksWaterSeekers']() != 1 or m['cfeQuuniSeaGrottoTreasure']() != 1 or m['cfeQuuniNoTreasure']() != 1 or m['cfeQuuniShrimpLike']() != 1",
      "note" = "the Qu'uni nature - automatically attacking water-seekers, no treasure save the sea grotto, pallid semi-transparent shrimp-like (folio 21 sidebar)",
    }, {
      "expr" = "m['cfeRegistryAfter']() != 1311",
      "note" = "the live registry census floor - the 1308 loaded base defs plus the three Creature Features promotions = 1311 (the 25 long-broken base text lines stay out of the load, a pre-R900 state not touched)",
    } },
  "audit" = {
      "label" = "R900 Dragon Creature Features audit",
      "comment" = "THE DRAGON ISSUE-4 OPENER ROUND - the Creature Features chain, adjudicated as new variant-layer registry monsters (no 1e defs exist; the Remorhaz lore-against-def precedent does not apply). The Mihalli: number appearing 1-20 (the print's 'l-20' glyph pinned as 1, the OCR-of-font artifact noted), armor class 1, move 15 inches, 3 hit dice, the L 40 lair line with 80-800 gold near own territory, the garbled F: 50 and I: 50 stat lines pinned AS SCANNED with the semantics unpinned, the 20 percent red-eye reveal, the two-to-three-plus bonus spells at levels IV-up, the 40 percent Eyes/amulets/scrolls chance, the four-step Ball of Immediate Eventuation ladder (light purple, bright silver, bright gold, lambent translucent blue) reserved to magic users and priests XIV-up with the brain-scramble below, the 5 percent friendly and 1 percent item-offer chances rolled each turn, the defense if attacked, and the nature doctrines (shape-changer, humanoid, hermaphroditic, seeing in the dark, the gas sparing the Shen and the Ssu). The Vriyagga: number appearing 1-10 (20-200 in its own city), armor class 1, the nil treasure even in lair, the size ladder as a three-row table (move 12/10/8 inches, hit dice 10/15/25, tentacle damage 2/4/6 dice per turn, the dice assumed d6 noted), the four-plus tentacles at armor class 2 to sever, the heat sense, the speechless ambush-thinking mind, the stair-climbing bar and the black-opal dark sight. The Qu'uni: the folio 21 sidebar - 2 hit dice, move 10, 50-100 appearing, armor class 3, the automatic attack on water-seeking parties, the no-treasure save the sea grotto, and the pallid semi-transparent shrimp-like nature. THE REGISTRY WORK: three new lua defs (mihalli, vriyagga, qu_uni) carrying the new dragon_print xp source, whitelisted at the R73 audit, the R879 normalizer's book_of extended with the DRG Dragon magazine bucket, cross-checked by the R900 live def walk against the live registry census - 1308 loaded base defs + 3 = 1311 (the 1333 base lua files include 25 long-standing load-error defs with broken text lines that never enter the registry, a pre-R900 print-fidelity state this round does not touch; the Termux battery line 'loaded 1311, errors 25' is the ground truth). CONVERSIONS, ALL NOTED: the DMG p.85 additive XP formula (the Mihalli 35 + 25 + 55 = 115 base, the Vriyagga 2400 + 1250 + 1600 = 5250 at the 15-dice middle size, the Qu'uni 20 flat at 2 dice), the 4.5-per-die d8 average hit points floored (13, 67, 9), the XP values 154, 6590 and 38. GAP REPORT: the comedy box flipped in tools/dragon_gap_report_003.md -> the issue-3 report 5 closed / 0 open, the walk complete; the issue-4 report ships pre-flip with the Creature Features box open.",
    },
}
