// =========================================================================================
// Adnd1 - rules/psy.h
// The Dragon issue-18 opener part one - the insanity chart and doctrine, the
// laws of magic, the godgame hazard and the NPC pride, greed and work-quality
// tables: the four-chain round
// census 856 -> 857.
//
// Pinned from The Dragon Vol. III No. 4 (September 1978), the
// Curtiss-provided scan voice (single voice: the issue-18 source is the
// uploaded Dm18.pdf with its mistral-ocr transcript; no archive.org djvu
// cross-check exists for issue 18). PRINT FOLIO = PDF PAGE MINUS TWO,
// verified at the page feet (folios 3, 9, 13, 14, 19, 21, 24 and 31 print at
// the PDF pages 5, 11, 15, 16, 21, 23, 26 and 33). The chains of this round:
// Insanity by Kevin Thompson (print 9, PDF 11); Magic: Governed by Laws of
// Theory by Thomas A. McCloud (print 14 + 19, PDF 16 + 21, its continuation
// sharing print 19 with the godgame); The Chamber of the Godgame by Mick
// McAllister (print 19, PDF 21); the unsigned Non-Player Character Statistics
// (print 31-32, PDF 33-34). The pin IS the conversion: OD&D-era ink
// adjudicated to 1e terms, the conversion noted, never silent; Dragon pins
// ride a VARIANT layer with provenance, never core canon.
//
// Print quirks pinned AS SCANNED, noted never silent: the work-quality table
// jumps from the 01-02 band to 21-99 - the 03-20 band never prints, the gap
// flagged as scanned; the greed bands print the odd compound forms (96 - 00 +
// 4, 00 + 5 to + 9 and the rest) - each pins its own row; the pride 00 band
// pins as the 100 percentile cell; the insanity chart carries the odd 12 at
// the wisdom 9-12 by intelligence 9-12 crossing (higher than both neighboring
// columns - pinned as printed, the odd bump noted); no numeric cell garbles
// beyond that, so no table cell rides a sentinel this round.
//
namespace rules {

// ---- the insanity chart and doctrine (print 9) ----

// the insanity saving-throw chart rows - nine wisdom bands from less than 3
// to over 18 (print 9, PDF 11)
inline int psyInsWisBands()
    { return 9; }

// the chart columns - six intelligence bands from less than 3 to over 18
// (print 9)
inline int psyInsIntBands()
    { return 6; }

// the insanity save rolls a twenty-sided die against the chart number plus
// level (print 9)
inline int psyInsSaveDieSides()
    { return 20; }

// a failed save rolls the twelve-entry insanity chart on a twelve-sided die
// (print 9)
inline int psyInsChartDieSides()
    { return 12; }

// the insanity chart carries twelve psychoses, Nutty through Catatonic (print
// 9)
inline int psyInsChartEntries()
    { return 12; }

// the schizoid personality rolls a ten-sided die each turn (print 9)
inline int psyInsSchizoidDieSides()
    { return 10; }

// a 1 on the schizoid die reverts to the other personality (print 9)
inline int psyInsSchizoidRevertRoll()
    { return 1; }

// the suicidal victim rolls a six-sided die at each harrowing or deadly
// problem (print 9)
inline int psyInsSuicideDieSides()
    { return 6; }

// a 1 on the suicide die means he attempts to kill himself (print 9)
inline int psyInsSuicideAttemptRoll()
    { return 1; }

// the psySave table row count (print 9)
inline int psyInsSaveRows()
    { return 9; }

// where intelligence is less than wisdom there is lesser knowledge and more
// vulnerability to insanity (print 9)
inline bool psyInsIntBelowWisVulnerable()
    { return true; }

// a higher intelligence than wisdom carries even greater susceptibility -
// facts understood without the judgment to place them (print 9)
inline bool psyInsIntAboveWisMoreSusceptible()
    { return true; }

// the character level, at least 1, is added to the chart number before the
// save roll (print 9)
inline bool psyInsLevelAddedToSave()
    { return true; }

// a die roll at or under the adjusted number avoids insanity (print 9)
inline bool psyInsSaveRollLowAvoids()
    { return true; }

// none of the psychoses are evident immediately unless otherwise stated
// (print 9)
inline bool psyInsPsychosesNotImmediate()
    { return true; }

// the gibbering state is obvious immediately (print 9)
inline bool psyInsGibberingImmediate()
    { return true; }

// the violent state is obvious immediately (print 9)
inline bool psyInsViolentImmediate()
    { return true; }

// the catatonic state is obvious immediately (print 9)
inline bool psyInsCatatonicImmediate()
    { return true; }

// all magic and clerical abilities stay functional except when gibbering or
// catatonic (print 9)
inline bool psyInsMagicFunctionalExcept()
    { return true; }

// the schizoid split personality has no physical changes - it is all in the
// mind and actions, one personality not remembering the other (print 9)
inline bool psyInsSchizoidNoPhysicalChange()
    { return true; }

// the cause of insanity is the DM call - chests, rings, horns, failed
// responsibility, mindbending creatures like a lich or demon (print 9)
inline bool psyInsCausesDmSet()
    { return true; }

// chart entry 1 - Nutty: slightly silly, eccentric, odd ideas and plans
// (print 9)
inline bool psyInsNutty()
    { return true; }

// chart entry 2 - Kleptomaniac: compulsive thief with no thief abilities,
// sneaks small objects without regard to value (print 9)
inline bool psyInsKleptomaniac()
    { return true; }

// chart entry 3 - Perverse: pleasure in the gruesome, dismemberment a casual
// result, mad laughter (print 9)
inline bool psyInsPerverse()
    { return true; }

// chart entry 4 - Psychotic Hatred: immediate deadly actions against the
// chosen type - magic users, warriors, clerics, thieves, monks, rangers, men,
// women, elves, dwarves, hobbits, giants, royalty, police-types, witches,
// tall, short, bearded, rich, peasants, leaders, opposing alliance (print 9)
inline bool psyInsPsychoticHatred()
    { return true; }

// chart entry 5 - Childlike Trusting: total gullibility, believes anyone
// (print 9)
inline bool psyInsChildlikeTrusting()
    { return true; }

// chart entry 6 - Schizoid: split personality, the young-old, violent-gentle,
// arrogant-shy, confident-unsure, brave-coward, male-female, lawful-chaotic,
// good-evil, generous-greedy, trusting-paranoid, honest-secretive,
// trustworthy-untrustworthy pairs (print 9)
inline bool psyInsSchizoid()
    { return true; }

// chart entry 7 - Severe Paranoia: trusts no one, may kill in self defense on
// sudden moves, every whisper is about him (print 9)
inline bool psyInsSevereParanoia()
    { return true; }

// chart entry 8 - Acute Paranoia: convinced everyone wants to kill him
// immediately, tries to escape or kill (print 9)
inline bool psyInsAcuteParanoia()
    { return true; }

// chart entry 9 - Gibbering: walks, eats and sleeps but is otherwise totally
// useless, cannot find his own food (print 9)
inline bool psyInsGibbering()
    { return true; }

// chart entry 10 - Suicidal: attempts his own life on a 1 of 6 at any
// harrowing problem (print 9)
inline bool psyInsSuicidal()
    { return true; }

// chart entry 11 - Violent: tries to kill as many as he can as fast as he
// can, not clever, just deadly (print 9)
inline bool psyInsViolent()
    { return true; }

// chart entry 12 - Catatonic: sits doing nothing, will not eat, talk or move,
// ignores all outside stimuli including pain (print 9)
inline bool psyInsCatatonic()
    { return true; }

// the intelligence band less than 3: 7, 8, 9, 10, 11, 12, 13, 14 and 15 down
// the nine wisdom bands (print 9)
inline int psySaveIntLt3(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 8;
        case 2:
            return 9;
        case 3:
            return 10;
        case 4:
            return 11;
        case 5:
            return 12;
        case 6:
            return 13;
        case 7:
            return 14;
        case 8:
            return 15;
        default:
            return -99;
        }
    }

// the intelligence band 3-8: 5, 9, 10, 11, 12, 13, 14, 15 and 16 (print 9)
inline int psySaveInt3to8(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 9;
        case 2:
            return 10;
        case 3:
            return 11;
        case 4:
            return 12;
        case 5:
            return 13;
        case 6:
            return 14;
        case 7:
            return 15;
        case 8:
            return 16;
        default:
            return -99;
        }
    }

// the intelligence band 9-12: 3, 7, 8, the odd 12 at wisdom 9-12, 13, 14, 15,
// 16 and 17 - the bump higher than both neighboring columns, pinned as
// printed (print 9)
inline int psySaveInt9to12(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 7;
        case 2:
            return 8;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 15;
        case 7:
            return 16;
        case 8:
            return 17;
        default:
            return -99;
        }
    }

// the intelligence band 13-15: 1, 5, 6, 10, 14, 15, 16, 17 and 18 (print 9)
inline int psySaveInt13to15(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 10;
        case 4:
            return 14;
        case 5:
            return 15;
        case 6:
            return 16;
        case 7:
            return 17;
        case 8:
            return 18;
        default:
            return -99;
        }
    }

// the intelligence band 16-18: -2, 2, 3, 7, 11, 12, 17, 18 and 19 (print 9)
inline int psySaveInt16to18(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 7;
        case 4:
            return 11;
        case 5:
            return 12;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 19;
        default:
            return -99;
        }
    }

// the intelligence band over 18: -5, -1, 0, 4, 8, 9, 14, 15 and 20 (print 9)
inline int psySaveIntOver18(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 4;
        case 4:
            return 8;
        case 5:
            return 9;
        case 6:
            return 14;
        case 7:
            return 15;
        case 8:
            return 20;
        default:
            return -99;
        }
    }

// ---- the laws of magic and the contest (print 14 + 19) ----

// the theory of magic runs six laws: Similarity, Contagion, Mana, Artistry,
// Obscurity and Harmony (print 14, PDF 16)
inline int psyLawCount()
    { return 6; }

// every act of magic has three parts: the spell, the rite and the condition
// of the magician (print 14)
inline int psyActParts()
    { return 3; }

// the fatigue-factor cast check rolls a twenty-sided die against the
// fatigue-adjusted intelligence (print 19, PDF 21)
inline int psyLawFatigueDieSides()
    { return 20; }

// the Kemble magic contest scores by three judges (print 19)
inline int psyContestJudges()
    { return 3; }

// each contest judge awards 1-10 points (print 19)
inline int psyContestPointsMin()
    { return 1; }

// each contest judge awards 1-10 points, the ceiling (print 19)
inline int psyContestPointsMax()
    { return 10; }

// the contest runs two categories: Implementation of Standard Spells and
// Original Spells (print 19)
inline int psyContestCategories()
    { return 2; }

// to be effective each contest spell must invoke at least one similarity
// (print 19)
inline int psyContestSimilarityMin()
    { return 1; }

// the Law of Similarity - an effect resembles its cause, the voodoo doll and
// the Hand of Glory (print 14)
inline bool psyLawSimilarity()
    { return true; }

// the Law of Contagion - things once joined, when separated, remember each
// other and remain effectively similar - the hair clippings and the cooled
// weapon (print 14)
inline bool psyLawContagion()
    { return true; }

// the Law of Mana - magic power is based on a mysterious supernatural force,
// with no consensus on how it works (print 14)
inline bool psyLawMana()
    { return true; }

// the Law of Artistry, the McCloud own-dungeon law - mana derives from art,
// good or evil (print 14)
inline bool psyLawArtistry()
    { return true; }

// the Law of Obscurity - potency is proportional to abstrusity, the strange
// ingredients and the arcane languages (print 14)
inline bool psyLawObscurity()
    { return true; }

// the Law of Harmony - the balance of the universe must be maintained, a
// price is paid for the use of magic (print 14)
inline bool psyLawHarmony()
    { return true; }

// the spell - the words recited - is by far the most important part, the
// spoken word is always used (print 14)
inline bool psyActPartSpell()
    { return true; }

// the rite - the actions and gestures - gives the magic direction, the wand
// is a pointer (print 14)
inline bool psyActPartRite()
    { return true; }

// the condition of the performer - taboos avoided, emotions raised, and the
// level appropriate for the magic (print 14)
inline bool psyActPartCondition()
    { return true; }

// the spell must above all describe the similarities invoked (print 14)
inline bool psyLawSpellMustDescribeSimilarity()
    { return true; }

// the fatigue factor is subtracted from all characteristics, including
// intelligence (print 19)
inline bool psyLawFatigueSubtractsAll()
    { return true; }

// a fatigue roll higher than the adjusted intelligence means the spell was
// done wrong and may backfire (print 19)
inline bool psyLawFatigueBackfire()
    { return true; }

// the dungeon spell should be poetic, use archaic language and refer to the
// mana sources - assists but not necessary (print 14)
inline bool psyLawSpellPoetic()
    { return true; }

// the contest entrant gives the DM a written copy of the spell with the exact
// words and the rite gestures (print 19)
inline bool psyContestWrittenSpellRequired()
    { return true; }

// flesh golems are provided as lawful targets for combat magic (print 19)
inline bool psyContestFleshGolems()
    { return true; }

// no purely black magic is allowed at the contest (print 19)
inline bool psyContestNoBlackMagic()
    { return true; }

// anyone killed at the contest will be resurrected if possible (print 19)
inline bool psyContestResurrected()
    { return true; }

// all spectators view the proceedings at their own hazard (print 19)
inline bool psyContestSpectatorsOwnHazard()
    { return true; }

// ---- the chamber of the godgame (print 19) ----

// the chamber table carries a set of 4 DG - four dice (print 19, PDF 21)
inline int psyGodDiceCount()
    { return 4; }

// rolling a one on the selected die fulfills the Hazard - the die goes in the
// mouth (print 19)
inline int psyGodLosingRoll()
    { return 1; }

// the self-sacrifice recompense: a treasure equal to 2x a share of what the
// party brings out (print 19)
inline int psyGodTreasureShareX()
    { return 2; }

// the experience recompense runs 2 or 3x those accumulated by the others
// (print 19)
inline int psyGodXpShareXLow()
    { return 2; }

// the experience recompense ceiling, 3x (print 19)
inline int psyGodXpShareXHigh()
    { return 3; }

// the worked example: the four come out with 4,000 GP (print 19)
inline int psyGodExPartyGold()
    { return 4000; }

// the worked example: 1,500 experience points each (print 19)
inline int psyGodExPartyXp()
    { return 1500; }

// the example party share: 1,000 GP each (print 19)
inline int psyGodExShareGold()
    { return 1000; }

// the example party share: 375 EP each (print 19)
inline int psyGodExShareXp()
    { return 375; }

// the example recompense: Malcolm is given 2,000 GP by the Godgame Master
// (print 19)
inline int psyGodExRewardGold()
    { return 2000; }

// the example recompense: 1,125 EP - the 3x share (print 19)
inline int psyGodExRewardXp()
    { return 1125; }

// the solitary variant: four dice on the table (print 19)
inline int psyGodSoloDiceCount()
    { return 4; }

// each die contains a cyanide syrup which kills painlessly and
// instantaneously when bitten (print 19)
inline bool psyGodCyanideDie()
    { return true; }

// the door opens the moment the terms of the Hazard are fulfilled (print 19)
inline bool psyGodDoorOpensOnFulfillment()
    { return true; }

// the chamber defeats Knock, Dispel Magic, Dimension Door, Pass-Wall and
// Teleport - there is only one way out (print 19)
inline bool psyGodEscapeProof()
    { return true; }

// the variants are posited on the probability that the scroll contains one or
// more falsehoods (print 19)
inline bool psyGodScrollMayLie()
    { return true; }

// the benign variant puts the volunteer in suspended animation and teleports
// him outside to wait (print 19)
inline bool psyGodBenignSuspension()
    { return true; }

// the volunteer is rewarded with both experience and treasure - he believed
// he had given up both (print 19)
inline bool psyGodRewardXpAndTreasure()
    { return true; }

// an evil magician honors the agreement, accepting one life as ransom of the
// others (print 19)
inline bool psyGodEvilRansom()
    { return true; }

// the more evil variant lets the party select the victim themselves, without
// the voluntary agreement (print 19)
inline bool psyGodEvilPartySelect()
    { return true; }

// a benign or neutral Power punishes a party coercing a weaker member into
// submitting (print 19)
inline bool psyGodNeutralPunishesCoercers()
    { return true; }

// the Neutral Godgame Master slays the coercer in the victim place at the
// fulfillment of Hazard (print 19)
inline bool psyGodNeutralCoercerDies()
    { return true; }

// the Neutral GM might slay them all - or set them all free, the die not
// poisoned, to finish in mutual distrust (print 19)
inline bool psyGodNeutralSlayOrFree()
    { return true; }

// the benign possibilities: the die not poisoned after all, a secret door
// revealing treasure, or the shortest path cleared and lighted (print 19)
inline bool psyGodUnpoisonedVariant()
    { return true; }

// the solitary variant: a device crushes one die releasing the odor of bitter
// almonds, the scroll claims only one other die is poisoned (print 19)
inline bool psyGodSoloCrushedDie()
    { return true; }

// the loaded-dice option: the DM rolls secretly for the character or buys
// loaded dice at a novelty shop (print 19)
inline bool psyGodLoadedDiceOption()
    { return true; }

// ---- the NPC pride, greed and work quality (print 31-32) ----

// the base percentage method: roll greed as normal, then subtract ten and
// note the result (print 32, PDF 34)
inline int psyNpcGreedBaseMethodSubtract()
    { return 10; }

// the base percentage method rolls a twenty-sided die and adds it to the base
// (print 32)
inline int psyNpcGreedDieSides()
    { return 20; }

// greed never exceeds 00 + 20 (print 32)
inline int psyNpcGreedCapPlus()
    { return 20; }

// shop-owners never have a greed below 20 (print 32)
inline int psyNpcShopkeeperGreedFloor()
    { return 20; }

// spies never have a pride factor below 08 (print 32)
inline int psyNpcSpyPrideFloor()
    { return 8; }

// hired thieves tend to be greedy, with a greed factor above 21 (print 32)
inline int psyNpcThiefGreedFloor()
    { return 21; }

// armorers have a pride factor above 13 (print 32)
inline int psyNpcArmorerPrideFloor()
    { return 13; }

// the greed column doubles as interest demanded per game year: normal greed 5
// percent (print 32)
inline int psyNpcInterestNormalPercent()
    { return 5; }

// a double-price greed demands 100 percent interest, the printed
// correspondence (print 32)
inline int psyNpcInterestDoublePercent()
    { return 100; }

// fraction greed demands 0 percent interest (print 32)
inline int psyNpcInterestZeroPercent()
    { return 0; }

// the below-01 work quality: trash falls apart in 1-6 uses (print 32)
inline int psyWorkTrashUsesDieMax()
    { return 6; }

// the trash work is worth about 1/10 price (print 32)
inline int psyWorkTrashPricePercent()
    { return 10; }

// the 01-02 cheap work is worth 1/5 to 1/2 price - the floor 20 percent
// (print 32)
inline int psyWorkCheapPriceMinPercent()
    { return 20; }

// the cheap work price ceiling, 50 percent (print 32)
inline int psyWorkCheapPriceMaxPercent()
    { return 50; }

// the cheap work wears out in half the normal time, 50 percent (print 32)
inline int psyWorkCheapLifespanPercent()
    { return 50; }

// the 21-99 band is normal work, 100 percent (print 32)
inline int psyWorkNormalPricePercent()
    { return 100; }

// the 00-00+5 sturdy work lasts twice as long as normal (print 32)
inline int psyWorkSturdyLifespanPercent()
    { return 200; }

// the sturdy work is worth up to 2-1/2 times normal price, 250 percent (print
// 32)
inline int psyWorkSturdyPricePercent()
    { return 250; }

// the pride table row count - nine bands from 01 to 00 (print 31)
inline int psyPrideRows()
    { return 9; }

// the greed table row count - eleven bands from any negative to 00 + 20
// (print 31)
inline int psyGreedRows()
    { return 11; }

// the pride ego factor is rolled once and left unaltered (print 32)
inline bool psyPrideRolledOnce()
    { return true; }

// greed can be rolled like pride, or by the referee base percentage method
// (print 32)
inline bool psyGreedBaseMethodOption()
    { return true; }

// the quality of work is rolled once per item (print 32)
inline bool psyWorkRolledPerItem()
    { return true; }

// with these statistics bartering becomes part of the game, especially with
// hirelings wages (print 32)
inline bool psyNpcBarteringHirelingWages()
    { return true; }

// the work quality table jumps from the 01-02 band to 21-99 - the 03-20 band
// never prints, noted as scanned (print 32)
inline bool psyWorkCheapBandGap()
    { return true; }

// the greed percentage is the share of due treasure a hireling will accept or
// demand - the -15 example takes 5 GP of 50, the 00+20 demands 150 GP of a 50
// GP share (print 31-32)
inline bool psyNpcGreedShareDoctrine()
    { return true; }

// the band floor on the percentile dice (print 31)
inline int psyPrideLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 8;
        case 3:
            return 14;
        case 4:
            return 90;
        case 5:
            return 92;
        case 6:
            return 94;
        case 7:
            return 99;
        case 8:
            return 100;
        default:
            return -99;
        }
    }

// the band ceiling - 100 carries the 00 print (print 31)
inline int psyPrideHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 7;
        case 2:
            return 13;
        case 3:
            return 89;
        case 4:
            return 91;
        case 5:
            return 93;
        case 6:
            return 98;
        case 7:
            return 99;
        case 8:
            return 100;
        default:
            return -99;
        }
    }

// the charisma modifier - vain -1, egotist -2, egomaniac -3, the 90-91
// well-being +1 (print 31)
inline int psyPrideChr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return -1;
        case 7:
            return -2;
        case 8:
            return -3;
        default:
            return -99;
        }
    }

// the constitution modifier - the 01 band -1, the well-being and vain and
// egotist and egomaniac bands +1 (print 31)
inline int psyPrideCons(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return -99;
        }
    }

// the greed percent adjustment, -15 at 01 up to +20 at 00 (print 31)
inline int psyPrideGreedPct(int b)
    {
        switch (b) {
        case 0:
            return -15;
        case 1:
            return -10;
        case 2:
            return -5;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 5;
        case 6:
            return 10;
        case 7:
            return 15;
        case 8:
            return 20;
        default:
            return -99;
        }
    }

// the work quality percent adjustment, -5 at 01 to +5 at 92-93 (print 31)
inline int psyPrideWorkPct(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 5;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the loan chance numerator - 0 with den 0 gives things away, 0 with den 1
// never loans (print 31)
inline int psyGreedLoanNum(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        default:
            return -99;
        }
    }

// the loan chance denominator - 3, 6, 12 and 20 for the may-loan bands (print
// 31)
inline int psyGreedLoanDen(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 6;
        case 7:
            return 12;
        case 8:
            return 20;
        case 9:
            return 1;
        case 10:
            return 1;
        default:
            return -99;
        }
    }

// the selling price in percent of normal - 1/10 at negative, 1/5 at zero, 1/2
// at 01-20, normal, +10, +20, +50, double, 2-1/2 and triple at 00 + 20 (print
// 31)
inline int psyGreedPricePercent(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 50;
        case 3:
            return 100;
        case 4:
            return 100;
        case 5:
            return 110;
        case 6:
            return 120;
        case 7:
            return 150;
        case 8:
            return 200;
        case 9:
            return 250;
        case 10:
            return 300;
        default:
            return -99;
        }
    }

}   // namespace rules
