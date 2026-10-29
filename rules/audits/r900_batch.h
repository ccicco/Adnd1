    // ---- R900 Dragon Creature Features audit ----
    // THE DRAGON ISSUE-4 OPENER ROUND - the Creature Features chain,
    // adjudicated as new variant-layer registry monsters (no 1e defs exist;
    // the Remorhaz lore-against-def precedent does not apply). The Mihalli:
    // number appearing 1-20 (the print's 'l-20' glyph pinned as 1, the
    // OCR-of-font artifact noted), armor class 1, move 15 inches, 3 hit dice,
    // the L 40 lair line with 80-800 gold near own territory, the garbled F:
    // 50 and I: 50 stat lines pinned AS SCANNED with the semantics unpinned,
    // the 20 percent red-eye reveal, the two-to-three-plus bonus spells at
    // levels IV-up, the 40 percent Eyes/amulets/scrolls chance, the four-step
    // Ball of Immediate Eventuation ladder (light purple, bright silver,
    // bright gold, lambent translucent blue) reserved to magic users and
    // priests XIV-up with the brain-scramble below, the 5 percent friendly
    // and 1 percent item-offer chances rolled each turn, the defense if
    // attacked, and the nature doctrines (shape-changer, humanoid,
    // hermaphroditic, seeing in the dark, the gas sparing the Shen and the
    // Ssu). The Vriyagga: number appearing 1-10 (20-200 in its own city),
    // armor class 1, the nil treasure even in lair, the size ladder as a
    // three-row table (move 12/10/8 inches, hit dice 10/15/25, tentacle
    // damage 2/4/6 dice per turn, the dice assumed d6 noted), the four-plus
    // tentacles at armor class 2 to sever, the heat sense, the speechless
    // ambush-thinking mind, the stair-climbing bar and the black-opal dark
    // sight. The Qu'uni: the folio 21 sidebar - 2 hit dice, move 10, 50-100
    // appearing, armor class 3, the automatic attack on water-seeking
    // parties, the no-treasure save the sea grotto, and the pallid
    // semi-transparent shrimp-like nature. THE REGISTRY WORK: three new lua
    // defs (mihalli, vriyagga, qu_uni) carrying the new dragon_print xp
    // source, whitelisted at the R73 audit, the R879 normalizer's book_of
    // extended with the DRG Dragon magazine bucket, cross-checked by the R900
    // live def walk against the live registry census - 1308 loaded base defs
    // + 3 = 1311 (the 1333 base lua files include 25 long-standing load-error
    // defs with broken text lines that never enter the registry, a pre-R900
    // print-fidelity state this round does not touch; the Termux battery line
    // 'loaded 1311, errors 25' is the ground truth). CONVERSIONS, ALL NOTED:
    // the DMG p.85 additive XP formula (the Mihalli 35 + 25 + 55 = 115 base,
    // the Vriyagga 2400 + 1250 + 1600 = 5250 at the 15-dice middle size, the
    // Qu'uni 20 flat at 2 dice), the 4.5-per-die d8 average hit points
    // floored (13, 67, 9), the XP values 154, 6590 and 38. GAP REPORT: the
    // comedy box flipped in tools/dragon_gap_report_003.md -> the issue-3
    // report 5 closed / 0 open, the walk complete; the issue-4 report ships
    // pre-flip with the Creature Features box open.
    {
        using namespace rules;
        int bad = 0;
    if (cfeMihalliNaMin() != 1
            || cfeMihalliNaMax() != 20
            || cfeMihalliAc() != 1
            || cfeMihalliMove() != 15
            || cfeMihalliHd() != 3
            || cfeMihalliLairPct() != 40
            || cfeMihalliLairMin() != 80
            || cfeMihalliLairMax() != 800
            || cfeMihalliF() != 50
            || cfeMihalliI() != 50
            || cfeMihalliRedEyesPct() != 20
            || cfeMihalliBonusSpellsMin() != 2
            || cfeMihalliBonusSpellsHigh() != 3
            || cfeMihalliEyeChancePct() != 40
            || cfeMihalliBallLadderCount() != 4
            || cfeMihalliBallPurple() != 1
            || cfeMihalliBallSilver() != 2
            || cfeMihalliBallGold() != 3
            || cfeMihalliBallBlue() != 4
            || cfeMihalliUseLevelMin() != 14
            || cfeMihalliFriendlyPct() != 5
            || cfeMihalliOfferItemPct() != 1
            || cfeMihalliAvgHp() != 13
            || cfeMihalliXp() != 115
            || cfeMihalliXpPerHp() != 3
            || cfeMihalliXpValue() != 154
            || cfeVriyaggaNaMin() != 1
            || cfeVriyaggaNaMax() != 10
            || cfeVriyaggaAc() != 1
            || cfeVriyaggaLairPct() != 40
            || cfeVriyaggaCityMin() != 20
            || cfeVriyaggaCityMax() != 200
            || cfeVriyaggaTentaclesMin() != 4
            || cfeVriyaggaTentacleAc() != 2
            || cfeVriyaggaAvgHp() != 67
            || cfeVriyaggaXp() != 5250
            || cfeVriyaggaXpPerHp() != 20
            || cfeVriyaggaXpValue() != 6590
            || cfeVriyaggaSizesCount() != 3
            || cfeQuuniHd() != 2
            || cfeQuuniMove() != 10
            || cfeQuuniNaMin() != 50
            || cfeQuuniNaMax() != 100
            || cfeQuuniAc() != 3
            || cfeQuuniAvgHp() != 9
            || cfeQuuniXp() != 20
            || cfeQuuniXpPerHp() != 2
            || cfeQuuniXpValue() != 38
            || cfeRegistryAfter() != 1311
            || !cfeMihalliShapeChanger()
            || !cfeMihalliHumanoid()
            || !cfeMihalliHermaphroditic()
            || !cfeMihalliSeeDark()
            || !cfeMihalliGasSparingShenSsu()
            || !cfeMihalliBallXivUpOnly()
            || !cfeMihalliScrambleBelowXiv()
            || !cfeMihalliDefendsIfAttacked()
            || !cfeMihalliRandomRollEachTurn()
            || !cfeVriyaggaNilTreasure()
            || !cfeVriyaggaNilTreasureInLair()
            || !cfeVriyaggaSensesHeat()
            || !cfeVriyaggaCannotSpeak()
            || !cfeVriyaggaAmbushThinker()
            || !cfeVriyaggaNoStairs()
            || !cfeVriyaggaSeeDark()
            || !cfeQuuniAttacksWaterSeekers()
            || !cfeQuuniSeaGrottoTreasure()
            || !cfeQuuniNoTreasure()
            || !cfeQuuniShrimpLike()
        )
            ++bad;
        // the Vriyagga size ladder - the small, middle and large forms: move
        // 12/10/8 inches, hit dice 10/15/25, tentacle damage 2/4/6 dice per
        // turn (folios 19, 21)
        int CVriSz[3][3] = {
            {12,10,2},
            {10,15,4},
            {8,25,6},
            };
        for (int b = 0;
             b < cfeVriyaggaSizesCount();
             ++b) {
            int vals[3];
            vals[0] = cfeVriSizeMove(b);
            vals[1] = cfeVriSizeHd(b);
            vals[2] = cfeVriSizeDice(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CVriSz[b][c])
                    ++bad;
            }
        }
        // the Vriyagga size ladder, row 0 of 3 - the move, hit dice and
        // tentacle damage dice by size (folios 19, 21)
    if (cfeVriSizeMove(0) != 12
            || cfeVriSizeHd(0) != 10
            || cfeVriSizeDice(0) != 2
            || cfeVriyaggaSizesCount() != 3
        )
            ++bad;
        // the Vriyagga size ladder, row 1 of 3 - the move, hit dice and
        // tentacle damage dice by size (folios 19, 21)
    if (cfeVriSizeMove(1) != 10
            || cfeVriSizeHd(1) != 15
            || cfeVriSizeDice(1) != 4
        )
            ++bad;
        // the Vriyagga size ladder, row 2 of 3 - the move, hit dice and
        // tentacle damage dice by size (folios 19, 21)
    if (cfeVriSizeMove(2) != 8
            || cfeVriSizeHd(2) != 25
            || cfeVriSizeDice(2) != 6
        )
            ++bad;
        // the Mihalli stat block - number appearing 1-20, armor class 1, move
        // 15 inches, 3 hit dice (folio 18)
    if (cfeMihalliNaMin() != 1
            || cfeMihalliNaMax() != 20
            || cfeMihalliAc() != 1
            || cfeMihalliMove() != 15
            || cfeMihalliHd() != 3
        )
            ++bad;
        // the Mihalli lair - 40 percent, 80-800 gold near own territory
        // (folio 18)
    if (cfeMihalliLairPct() != 40
            || cfeMihalliLairMin() != 80
            || cfeMihalliLairMax() != 800
        )
            ++bad;
        // the Mihalli stat-line garbles - F: 50 and I: 50 pinned AS SCANNED,
        // the glyph semantics unpinned (folio 18)
    if (cfeMihalliF() != 50
            || cfeMihalliI() != 50
        )
            ++bad;
        // the Mihalli eyes - the 20 percent reveal, the two-to-three-plus
        // bonus spells and the 40 percent Eyes/amulets/scrolls chance (folios
        // 18-19)
    if (cfeMihalliRedEyesPct() != 20
            || cfeMihalliBonusSpellsMin() != 2
            || cfeMihalliBonusSpellsHigh() != 3
            || cfeMihalliEyeChancePct() != 40
        )
            ++bad;
        // the Ball of Immediate Eventuation - the four-step colour ladder
        // light purple, bright silver, bright gold, lambent translucent blue
        // (folio 19)
    if (cfeMihalliBallLadderCount() != 4
            || cfeMihalliBallPurple() != 1
            || cfeMihalliBallSilver() != 2
            || cfeMihalliBallGold() != 3
            || cfeMihalliBallBlue() != 4
        )
            ++bad;
        // the ball reserved to the fourteenth level and up, and the 5 percent
        // friendly / 1 percent offer chances (folio 19)
    if (cfeMihalliUseLevelMin() != 14
            || cfeMihalliFriendlyPct() != 5
            || cfeMihalliOfferItemPct() != 1
        )
            ++bad;
        // the Mihalli XP conversion - 13 average hp, base 115, 3 per hp,
        // value 154, the DMG p.85 formula, noted never silent (folios 18-19)
    if (cfeMihalliAvgHp() != 13
            || cfeMihalliXp() != 115
            || cfeMihalliXpPerHp() != 3
            || cfeMihalliXpValue() != 154
        )
            ++bad;
        // the Mihalli nature - shape-changers, humanoid, hermaphroditic,
        // seeing in the dark (folio 19)
    if (cfeMihalliShapeChanger() != 1
            || cfeMihalliHumanoid() != 1
            || cfeMihalliHermaphroditic() != 1
            || cfeMihalliSeeDark() != 1
        )
            ++bad;
        // the gas sparing the Shen and the Ssu, and the ball XIV-up-only
        // scrambling brains below (folio 19)
    if (cfeMihalliGasSparingShenSsu() != 1
            || cfeMihalliBallXivUpOnly() != 1
            || cfeMihalliScrambleBelowXiv() != 1
        )
            ++bad;
        // the Mihalli defends if attacked, with the reaction rolled each turn
        // (folio 19)
    if (cfeMihalliDefendsIfAttacked() != 1
            || cfeMihalliRandomRollEachTurn() != 1
        )
            ++bad;
        // the Vriyagga stat block - number appearing 1-10, armor class 1, the
        // L 40 line (folio 19)
    if (cfeVriyaggaNaMin() != 1
            || cfeVriyaggaNaMax() != 10
            || cfeVriyaggaAc() != 1
            || cfeVriyaggaLairPct() != 40
        )
            ++bad;
        // the Vriyagga in its own city - 20-200 appearing (folio 19)
    if (cfeVriyaggaCityMin() != 20
            || cfeVriyaggaCityMax() != 200
        )
            ++bad;
        // the Vriyagga tentacles - four or more, armor class 2 to sever
        // (folio 21)
    if (cfeVriyaggaTentaclesMin() != 4
            || cfeVriyaggaTentacleAc() != 2
        )
            ++bad;
        // the Vriyagga XP conversion at the 15-dice middle size - 67 average
        // hp, base 5250, 20 per hp, value 6590, the DMG p.85 formula, noted
        // never silent (folio 19)
    if (cfeVriyaggaAvgHp() != 67
            || cfeVriyaggaXp() != 5250
            || cfeVriyaggaXpPerHp() != 20
            || cfeVriyaggaXpValue() != 6590
        )
            ++bad;
        // the Vriyagga nil treasure even in lair, and its heat sense (folios
        // 19, 21)
    if (cfeVriyaggaNilTreasure() != 1
            || cfeVriyaggaNilTreasureInLair() != 1
            || cfeVriyaggaSensesHeat() != 1
        )
            ++bad;
        // the Vriyagga mind - cannot speak, thinks and lays ambushes, cannot
        // climb stairs, black-opal eyes in the dark (folio 21)
    if (cfeVriyaggaCannotSpeak() != 1
            || cfeVriyaggaAmbushThinker() != 1
            || cfeVriyaggaNoStairs() != 1
            || cfeVriyaggaSeeDark() != 1
        )
            ++bad;
        // the Qu'uni stat block - 2 hit dice, move 10, 50-100 appearing,
        // armor class 3 (folio 21 sidebar)
    if (cfeQuuniHd() != 2
            || cfeQuuniMove() != 10
            || cfeQuuniNaMin() != 50
            || cfeQuuniNaMax() != 100
            || cfeQuuniAc() != 3
        )
            ++bad;
        // the Qu'uni XP conversion - 9 average hp, base 20, 2 per hp, value
        // 38, the DMG p.85 formula, noted never silent (folio 21 sidebar)
    if (cfeQuuniAvgHp() != 9
            || cfeQuuniXp() != 20
            || cfeQuuniXpPerHp() != 2
            || cfeQuuniXpValue() != 38
        )
            ++bad;
        // the Qu'uni nature - automatically attacking water-seekers, no
        // treasure save the sea grotto, pallid semi-transparent shrimp-like
        // (folio 21 sidebar)
    if (cfeQuuniAttacksWaterSeekers() != 1
            || cfeQuuniSeaGrottoTreasure() != 1
            || cfeQuuniNoTreasure() != 1
            || cfeQuuniShrimpLike() != 1
        )
            ++bad;
        // the live registry census floor - the 1308 loaded base defs plus the
        // three Creature Features promotions = 1311 (the 25 long-broken base
        // text lines stay out of the load, a pre-R900 state not touched)
    if (cfeRegistryAfter() != 1311
        )
            ++bad;
        printf("R900 Dragon Creature Features audit: bad %d\n", bad);
        if (bad) return 1;
    }
