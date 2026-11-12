// ====================================================================
// Adnd1 - rules/dmg/miscmagic_alchemy_jug_to_wings_of_flying.h
// R257-R279: the III.E misc magic explanation prose parts 1-23
// pins - merged from the 23 explanation-prose part files
// (R257 alchemy jug ... R279 wings of flying). Each part's
// original banner is preserved below as its section comment.
// Upload-seam provenance (parts 1-2): part1 ended mid-sentence
// at line 11065; part2 line 3 completed it; global line =
// part1 line or 11065 + part2 line.
// ====================================================================
#pragma once

class Miscmagic_alchemy_jug_to_wings_of_flying {
public:

    // ---- part 1 (R257): miscmagic_alchemy_jug_to_bag_of_devouring ----
    // Adnd1 - rules/dmg/miscmagic_alchemy_jug_to_bag_of_devouring.h
    // R257: the III.E misc magic explanation prose part 1
    // pins - the FIRST TWO-PART-FILE round. The III.E
    // explanation prose spans the upload seam: part1
    // ends mid-sentence (Bag of Devouring: it has a
    // 5%), part2 line 3 completes it. The seam is
    // pinned exactly: part1 has 11067 lines, last
    // content line 11065; global line = part1 line or
    // 11065 + part2 line. Slice: part1 10949-11065
    // plus the stitched completion - the section intro
    // plus Alchemy Jug through Bag of Devouring:
    //   - Intro: a catch-all category, not more than
    //     2 or 3 duplicates; alphabetical; class
    //     letters; books appear normal - a second
    //     wish for exact contents.
    //   - Alchemy Jug: 11 liquids (16 gallons salt
    //     water down to 4 drams cyanide); 1 kind and
    //     7 pourings per day; 2 gallons per round; 8
    //     rounds for one salt water pouring.
    //   - Amulet of Inescapable Location: DOUBLES
    //     likelihood and range of detection.
    //   - Amulet of Life Protection: psyche safe
    //     7 full days; psionic blast and crush immune.
    //   - Amulet of the Planes: d6 (1-3 no add, 4-6
    //     add 12) on d12 = 1-24; the 17-row plane
    //     table; alternates 22/23/24.
    //   - Amulet of Proof: no aura discernible.
    //   - Apparatus of Kwalish: 10 levers; 3 forward,
    //     6 backward; pincers 4 feet, 2-12 damage,
    //     25% hit; 900 feet; 2 occupants; 2-5 hours
    //     air; AC 0; 100 leak, 200 stave.
    //   - Arrow of Direction: once per day, 7 times
    //     in 7 turns, 5 request kinds.
    //   - Bag of Beans: 5-20 explosion in 10 feet;
    //     3-12 optimum, 1-2 beneficial; the 7-row
    //     bean table (5-20 berries of 100/500 gems;
    //     50 feet 5 turn smoke, blind 1-6; 20 feet
    //     1 turn gas).
    //   - Bag of Devouring: 90% ignore, 60% close;
    //     base 75% less 5% per +1 (18 str = 65%, 5
    //     str = 80%); 30 cubic feet; acts as a bag
    //     of holding; 5% cumulative per turn swallow
    //     - THE SEAM FACT; consumed in 7 segments.
    // The nine items are the engine kMisc1 rows 0-6,
    // 8 and 10 (the R225 m1 band pins) - cross-checked
    // in the audit. Pure data + helpers, header-only
    // (the grenade.h pattern).
    int mmpIntroMaxDuplicates();
    int mmpIntroBooksExactWishCount();
    int mmpAlchemyJugRowCount();
    int mmpAlchemyJugKindsPerDay();
    int mmpAlchemyJugPouringsPerDay();
    int mmpAlchemyJugGallonsPerRound();
    int mmpAlchemyJugRoundsPerLargePouring();
    int mmpAlchemyJugRowQty(int i);
    int mmpAlchemyJugRowUnit(int i);
    int mmpAmuletLocationMultiplier();
    int mmpAmuletLifeProtectionDays();
    int mmpAmuletPlanesRowCount();
    int mmpAmuletPlanesLowDieFaces();
    int mmpAmuletPlanesHighDieFaces();
    int mmpAmuletPlanesAddOnHigh();
    int mmpAmuletPlanesResultMax();
    int mmpAmuletPlanesAltRowCount();
    int mmpAmuletPlanesRowLo(int i);
    int mmpAmuletPlanesRowHi(int i);
    int mmpAmuletPlanesAltLo(int i);
    int mmpAmuletProofNoAuraFlag();
    int mmpKwalishLeverCount();
    int mmpKwalishForwardInches();
    int mmpKwalishBackwardInches();
    int mmpKwalishPincerReachFeet();
    int mmpKwalishPincerDamageLo();
    int mmpKwalishPincerDamageHi();
    int mmpKwalishPincerHitPct();
    int mmpKwalishMaxDepthFeet();
    int mmpKwalishOccupants();
    int mmpKwalishAirHoursLo();
    int mmpKwalishAirHoursHi();
    int mmpKwalishArmorClass();
    int mmpKwalishLeakHp();
    int mmpKwalishStaveHp();
    int mmpArrowDirectionUsesPerDay();
    int mmpArrowDirectionRepetitions();
    int mmpArrowDirectionTurns();
    int mmpArrowDirectionRequestKinds();
    int mmpBeanExplodeDamageLo();
    int mmpBeanExplodeDamageHi();
    int mmpBeanExplodeRadiusFeet();
    int mmpBeanOptimumLo();
    int mmpBeanOptimumHi();
    int mmpBeanBeneficialMax();
    int mmpBeanEffectRowCount();
    int mmpBeanBerryCountLo();
    int mmpBeanBerryCountHi();
    int mmpBeanBerryGemLo();
    int mmpBeanBerryGemHi();
    int mmpBeanSmokeRadiusFeet();
    int mmpBeanSmokeTurns();
    int mmpBeanBlindRoundsLo();
    int mmpBeanBlindRoundsHi();
    int mmpBeanGasRadiusFeet();
    int mmpBeanGasTurns();
    int mmpDevouringIgnorePct();
    int mmpDevouringClosePct();
    int mmpDevouringBaseDrawPct();
    int mmpDevouringDrawModPerPlus();
    int mmpDevouringExampleStr18Pct();
    int mmpDevouringExampleStr5Pct();
    int mmpDevouringCapacityCubicFeet();
    int mmpDevouringSwallowPctPerTurn();
    int mmpDevouringConsumeSegments();

    // ---- part 2 (R258): miscmagic_bag_of_holding_to_book_of_exalted_deeds ----
    // Adnd1 - rules/dmg/miscmagic_bag_of_holding_to_book_of_exalted_deeds.h
    // R258: the III.E misc magic explanation prose part 2
    // pins - part2 lines 5-66, Bag of Holding through
    // Book of Exalted Deeds (global line = 11065 +
    // part2 line; no page headers inside the slice).
    //   - Bag of Holding: the 4-row quality table
    //     (01-30: 15/250/30; 31-70: 15/500/70;
    //     71-90: 35/1000/150; 91-00: 60/1500/250);
    //     overload or a sharp pierce ruptures it,
    //     contents lost forever in nilspace.
    //   - Bag of Transmuting: appears as one of
    //     the 4 quality types; 2-5 proper uses;
    //     precious metals and gems to no worth;
    //     magic items (except artifacts and
    //     relics) to lead, glass or wood, no save.
    //   - Bag of Tricks: tossed 1-20 feet; d10
    //     type (1-5 / 6-8 / 9-0), 8 animals each;
    //     the animal stat columns are mangled in
    //     the upload - bands and counts pinned,
    //     stats not (the R256 lesson); 1 drawn at
    //     a time, slain or 1 turn then ordered
    //     back, 10 per week.
    //   - Beaker of Plentiful Potions: 2-5 doses
    //     of 2-5 potions; d4+1 count; 1 round per
    //     pour of 1 dose; delusion and poison
    //     possible; 2 potions: 1/day 3/week,
    //     3: 1/day 2/week, 4-5: 1/week; 1 potion
    //     type lost per month.
    //   - Boat, Folding: box 1 x half x half foot
    //     (12/6/6 inches); boat 10 x 4 x 2, ship
    //     24 x 8 x 6; 1 pair of oars vs 5 sets;
    //     3-4 vs 15 persons; 3 command words.
    //   - Book of Exalted Deeds: 1 week perusal;
    //     good cleric +1 wisdom, halfway XP;
    //     neutral 20,000-80,000; evil -1 level
    //     plus 50% for 2-5 adventures; MU -1 int
    //     or 2,000-20,000; thief 5-30 hp, -1 dex,
    //     10-60% conversion at wisdom 15; assassin
    //     5-40 hp; vanishes after perusal, one
    //     benefit per character.
    // The six items are the engine kMisc1 rows
    // 10-15 (the R225 m1 band pins) - cross-checked
    // in the audit, with the Exalted (C) class mark
    // at row 15. Pure data + helpers, header-only
    // (the grenade.h pattern).
    int mmpHoldingSackShortSideFeet();
    int mmpHoldingSackLongSideFeet();
    int mmpHoldingRowCount();
    int mmpHoldingRuptureCauseCount();
    int mmpHoldingRowLo(int i);
    int mmpHoldingRowHi(int i);
    int mmpHoldingRowWeightPounds(int i);
    int mmpHoldingRowWeightLimitPounds(int i);
    int mmpHoldingRowVolumeLimitCubicFeet(int i);
    int mmpTransmutingDisguiseQualityCount();
    int mmpTransmutingProperUsesMin();
    int mmpTransmutingProperUsesMax();
    int mmpTransmutingTransmuteKindCount();
    int mmpTransmutingItemBaseMaterialCount();
    int mmpTransmutingExemptKindCount();
    int mmpTricksTossMinFeet();
    int mmpTricksTossMaxFeet();
    int mmpTricksTypeDieSides();
    int mmpTricksTypeCount();
    int mmpTricksAnimalsPerType();
    int mmpTricksAnimalDieMin();
    int mmpTricksAnimalDieMax();
    int mmpTricksDrawnAtOnceMax();
    int mmpTricksDurationTurns();
    int mmpTricksEndConditionCount();
    int mmpTricksTypeRollCount();
    int mmpTricksWeeklyDrawMax();
    int mmpTricksTypeLo(int i);
    int mmpTricksTypeHi(int i);
    int mmpBeakerDoseMin();
    int mmpBeakerDoseMax();
    int mmpBeakerPotionCountMin();
    int mmpBeakerPotionCountMax();
    int mmpBeakerCountDieSides();
    int mmpBeakerCountDiePlus();
    int mmpBeakerPourRounds();
    int mmpBeakerPourDoses();
    int mmpBeakerBadTypeCount();
    int mmpBeakerMonthlyTypeLoss();
    int mmpBeakerDispenseRowMin();
    int mmpBeakerDispenseRowMax();
    int mmpBeakerPerDayByCount(int i);
    int mmpBeakerPerWeekByCount(int i);
    int mmpBoatBoxLengthInches();
    int mmpBoatBoxWidthInches();
    int mmpBoatBoxDepthInches();
    int mmpBoatLengthFeet();
    int mmpBoatWidthFeet();
    int mmpBoatDepthFeet();
    int mmpBoatShipLengthFeet();
    int mmpBoatShipWidthFeet();
    int mmpBoatShipDepthFeet();
    int mmpBoatOarPairs();
    int mmpBoatComponentCount();
    int mmpBoatShipOarSets();
    int mmpBoatShipComponentCount();
    int mmpBoatPersonsMin();
    int mmpBoatPersonsMax();
    int mmpBoatShipPersons();
    int mmpBoatCommandWordCount();
    int mmpExaltedReadingWeeks();
    int mmpExaltedWisdomGain();
    int mmpExaltedHalfwayPct();
    int mmpExaltedNeutralXpLossMin();
    int mmpExaltedNeutralXpLossMax();
    int mmpExaltedLevelFloor();
    int mmpExaltedEvilLevelLoss();
    int mmpExaltedAtonementPct();
    int mmpExaltedAtonementAdventuresMin();
    int mmpExaltedAtonementAdventuresMax();
    int mmpExaltedMuIntLoss();
    int mmpExaltedMuSaveXpLossMin();
    int mmpExaltedMuSaveXpLossMax();
    int mmpExaltedThiefHpMin();
    int mmpExaltedThiefHpMax();
    int mmpExaltedThiefDexLoss();
    int mmpExaltedThiefConvertPctMin();
    int mmpExaltedThiefConvertPctMax();
    int mmpExaltedThiefConvertWisReq();
    int mmpExaltedAssassinHpMin();
    int mmpExaltedAssassinHpMax();
    int mmpExaltedVanishesAfterPerusal();
    int mmpExaltedMaxBenefitTimes();

    // ---- part 3 (R259): miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing ----
    // Adnd1 - rules/dmg/miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.h
    // R259: the III.E misc magic explanation prose part 3
    // pins - part2 lines 67-108, Book of Infinite Spells
    // through Boots of Striding and Springing (global line
    // = 11065 + part2 line). TWO page headers inside the
    // slice, both stripped (the R249 lesson): line 70 splits
    // the page table from the Book of Infinite Spells intro;
    // line 102 splits the Boots of Levitation paragraph
    // mid-sentence - the seam pinned exactly (line 100 ends
    // the ascent/descent speed mid-phrase, line 104 continues
    // ROUND (MINUTE)).
    //   - Book of Infinite Spells: non-casters 5-20 hp and
    //     5-20 turns stunned on first read; 23-30 (22 + d8)
    //     pages; the 5-row page table; d10 level die (d12 for
    //     magic-user), 8-10 / 10-12 reroll to d6 / d8; cast
    //     the open page 1/day (4/day if already castable);
    //     the page-turn ladder 10/20/25/30%; the last page
    //     turned and the book vanishes.
    //   - Book of Vile Darkness: 1 week, +1 wisdom, halfway
    //     XP; neutral 30,000-120,000 or turn evil, 50% either;
    //     good clerics 2 saves (poison or die, magic or
    //     insane), then 250,000 XP less 10,000 per wisdom;
    //     other good 5-30 hp, 80% night hag if opened;
    //     non-evil neutral 5-20 hp handling.
    //   - Boots of Dancing: masquerade as one of the other 4
    //     useful types until melee or fleeing; AC penalty 4,
    //     no saves, no attacks; remove curse only.
    //   - Boots of Elvenkind: 95% silence worst, 100% best.
    //   - Boots of Levitation: 20 inches per round; d20 in
    //     14 pound increments over a 280 pound base, 294
    //     to 560 pounds.
    //   - Boots of Speed: 24 inch base; 1 inch slower per 10
    //     pounds over 200 (the 180/60 example at 20; the 500
    //     coin sack at 5 more); 1 rest hour per move hour, 8
    //     hours max; AC +2.
    //   - Boots of Striding and Springing: 12 inch base, 12
    //     hours then 12 recharge; 3 foot paces, 30 forward,
    //     9 backward, 15 vertical; 20% stumble less 3% per
    //     dex above 12 (the 17/14/11/8/5/2 ladder); AC +1.
    // The seven items are the engine kMisc1 rows 16-22 (the
    // R225 m1 band pins) - cross-checked in the audit, with
    // the Vile (C) class mark at row 17. Pure data +
    // helpers, header-only (the grenade.h pattern).
    int mmpInfiniteFirstReadHpMin();
    int mmpInfiniteFirstReadHpMax();
    int mmpInfiniteFirstReadStunTurnsMin();
    int mmpInfiniteFirstReadStunTurnsMax();
    int mmpInfinitePageMin();
    int mmpInfinitePageMax();
    int mmpInfinitePageBase();
    int mmpInfinitePageDieSides();
    int mmpInfinitePageRowCount();
    int mmpInfinitePageLo(int i);
    int mmpInfinitePageHi(int i);
    int mmpInfiniteLevelDieSides();
    int mmpInfiniteMuLevelDieSides();
    int mmpInfiniteLevelRerollLo();
    int mmpInfiniteLevelRerollHi();
    int mmpInfiniteMuLevelRerollLo();
    int mmpInfiniteMuLevelRerollHi();
    int mmpInfiniteRerollDieSides();
    int mmpInfiniteMuRerollDieSides();
    int mmpInfiniteVanishesAtLastPage();
    int mmpInfiniteCastPerDay();
    int mmpInfiniteCastPerDayIfKnown();
    int mmpInfiniteTurnPctUsable();
    int mmpInfiniteTurnPctForeign();
    int mmpInfiniteTurnPctNonCasterCleric();
    int mmpInfiniteTurnPctNonCasterMu();
    int mmpVileReadingWeeks();
    int mmpVileWisdomGain();
    int mmpVileHalfwayPct();
    int mmpVileNeutralXpLossMin();
    int mmpVileNeutralXpLossMax();
    int mmpVileNeutralSplitPct();
    int mmpVileGoodSaveCount();
    int mmpVileGoodXpLossBase();
    int mmpVileGoodXpLossPerWis();
    int mmpVileGoodHandlingHpMin();
    int mmpVileGoodHandlingHpMax();
    int mmpVileNightHagPct();
    int mmpVileNeutralHandlingHpMin();
    int mmpVileNeutralHandlingHpMax();
    int mmpDancingDisguisedBootTypeCount();
    int mmpDancingTriggerCaseCount();
    int mmpDancingAcPenalty();
    int mmpDancingRemovalSpellCount();
    int mmpElvenkindSilencePctWorst();
    int mmpElvenkindSilencePctBest();
    int mmpLevitationSpeedInchesPerRound();
    int mmpLevitationWeightIncrementPounds();
    int mmpLevitationWeightDieSides();
    int mmpLevitationWeightBasePounds();
    int mmpLevitationWeightMinPounds();
    int mmpLevitationWeightMaxPounds();
    int mmpSpeedBaseMovementInches();
    int mmpSpeedSlowPoundsPerInch();
    int mmpSpeedFreeWeightPounds();
    int mmpSpeedExampleHumanPounds();
    int mmpSpeedExampleGearPounds();
    int mmpSpeedExampleRateInches();
    int mmpSpeedSackCoins();
    int mmpSpeedSackSlowInches();
    int mmpSpeedRestHoursPerMoveHour();
    int mmpSpeedMaxContinuousHours();
    int mmpSpeedAcBonus();
    int mmpStridingBaseMovementInches();
    int mmpStridingMaxHoursPerDay();
    int mmpStridingRechargeHours();
    int mmpStridingNormalPaceFeet();
    int mmpStridingForwardJumpFeet();
    int mmpStridingBackwardLeapFeet();
    int mmpStridingVerticalSpringFeet();
    int mmpStridingStumbleBasePct();
    int mmpStridingStumbleDexAdjPct();
    int mmpStridingStumbleDexThreshold();
    int mmpStridingStumbleRowCount();
    int mmpStridingStumblePctByDex(int i);
    int mmpStridingAcBonus();

    // ---- part 4 (R260): miscmagic_bowl_commanding_water_elementals_to_bucknards_purse ----
    // Adnd1 - rules/dmg/miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.h
    // R260: the III.E misc magic explanation prose part 4
    // (DMG p.132) - Bowl Commanding Water Elementals
    // through Bucknard Everfull Purse, part2 lines
    // 110-153 (global = 11065 + part2 line). ONE page
    // header inside the slice (line 127, the TREASURE
    // page) splits the Bracers of Defense table from
    // Bracers of Defenselessness - stripped per the
    // R249 lesson; no mid-sentence seam this time.
    // 53 accessors: 48 scalars + 5 array walkers, no
    // name collisions with miscprose1.h through
    // miscprose3.h. The purse type-table coin columns
    // are mangled in the upload - only the band
    // edges and the 26-per-type are pinned (the
    // R256 lesson).
    // Pure data + helpers, header-only (the
    // grenade.h pattern).
    int mmpBowlCmdHd();
    int mmpBowlCmdWordsRounds();
    int mmpBowlCmdSaltBonusPerDie();
    int mmpBowlCmdSaltMaxHpPerDie();
    int mmpBowlCmdDiameterInches();
    int mmpBowlCmdDepthInches();
    int mmpWateryDeathSaltSavePenalty();
    int mmpWateryDeathDrownMinRounds();
    int mmpWateryDeathDrownMaxRounds();
    int mmpWateryDeathFreeSpellCount();
    int mmpWateryDeathDeathPermanent();
    int mmpWateryDeathSweetWaterAnotherSave();
    int mmpBracersDefRowCount();
    int mmpBracersDefAcMin();
    int mmpBracersDefAcMax();
    int mmpDefenselessAc();
    int mmpDefenselessNegatesProtections();
    int mmpDefenselessRemoveCurseOnly();
    int mmpBrazierFireHd();
    int mmpBrazierFireLightRounds();
    int mmpBrazierFireSulphurBonusPerDie();
    int mmpBrazierFireSulphurHpMin();
    int mmpBrazierFireSulphurHpMax();
    int mmpSleepSmokeRadiusInches();
    int mmpSleepSmokeHd();
    int mmpSleepSmokeAwakenSpellCount();
    int mmpBroochPctWithoutGems();
    int mmpBroochAbsorbHp();
    int mmpBroomAttackDumpMinFeet();
    int mmpBroomAttackDumpMaxFeet();
    int mmpBroomAttackAttacksPerRound();
    int mmpBroomAttackAsHd();
    int mmpBroomAttackStrawBlindRounds();
    int mmpBroomAttackHandleDmgMin();
    int mmpBroomAttackHandleDmgMax();
    int mmpBroomAttackAc();
    int mmpBroomAttackHpToDestroy();
    int mmpBroomFlySpeedInches();
    int mmpBroomFlyCapacityPounds();
    int mmpBroomFlyPoundsPerInch();
    int mmpBroomFlyClimbDiveDegrees();
    int mmpBroomFlyFetchSpeedInches();
    int mmpPurseCoinsPerType();
    int mmpPurseTypeRowCount();
    int mmpPurseGemsBaseGp();
    int mmpPurseGemsMaxGp();
    int mmpPurseAbilitiesNeverChange();
    int mmpPurseSpiceNote();
    int mmpBracersDefBandLo(int i);
    int mmpBracersDefBandHi(int i);
    int mmpBracersDefAc(int i);
    int mmpPurseTypeBandLo(int i);
    int mmpPurseTypeBandHi(int i);

    // ---- part 5 (R261): miscmagic_candle_of_invocation_to_cloak_of_protection ----
    // Adnd1 - rules/dmg/miscmagic_candle_of_invocation_to_cloak_of_protection.h
    // R261: the III.E misc magic explanation prose part 5
    // (DMG p.132) - Candle of Invocation through Cloak
    // of Protection, part2 lines 155-220 (global =
    // 11065 + part2 line). THREE page headers strip
    // (155 TABLE (III.E.) 2., 159 and 183 both the
    // TREASURE page); TWO seams pin exactly: the Candle
    // (line 157 ends one of the, line 161 continues
    // nine alignments) and the Cloak of Displacement
    // (line 180 ends with such as spells,, line 185
    // continues gaze weapon attacks). 60 accessors:
    // 50 scalars + 10 array walkers, no name
    // collisions with miscprose1.h through
    // miscprose4.h. The slice completes kMisc2 rows
    // 0-10; the per-plus asterisk sits on row 10
    // (Cloak of Protection 33-55) - the R226 pin is
    // correct, no R260-style off-by-one.
    // Pure data + helpers, header-only (the
    // grenade.h pattern).
    int mmpCandleAlignments();
    int mmpCandleClericLevelBoost();
    int mmpCandleBurnHours();
    int mmpCandleGateSpell();
    int mmpCarpetRowCount();
    int mmpCenserAirHd();
    int mmpCenserAirMedBonusPerDie();
    int mmpCenserAirWidthInches();
    int mmpCenserAirHeightInches();
    int mmpCenserAirTurnsIfExtinguished();
    int mmpCenserHostileMin();
    int mmpCenserHostileMax();
    int mmpCenserHostilePerRound();
    int mmpChimeOpenLengthInches();
    int mmpChimeOpenWizardLockLevel();
    int mmpChimeOpenRoundPerFunction();
    int mmpChimeOpenSoundingsMin();
    int mmpChimeOpenSoundingsMax();
    int mmpChimeOpenChargesMin();
    int mmpChimeOpenChargesMax();
    int mmpChimeOpenChargesDieSides();
    int mmpChimeOpenChargesDieMult();
    int mmpChimeHungerRadiusInches();
    int mmpChimeHungerMinEatRounds();
    int mmpDisplacementMinFeet();
    int mmpDisplacementMaxFeet();
    int mmpDisplacementAcBonus();
    int mmpDisplacementSaveBonus();
    int mmpDisplacementHumanoidPct();
    int mmpDisplacementSmallPct();
    int mmpElvenkindRowCount();
    int mmpElvenkindOutdoorNaturalRows();
    int mmpElvenkindOutdoorOtherRows();
    int mmpElvenkindUndergroundRows();
    int mmpElvenkindHumanoidPct();
    int mmpElvenkindSmallPct();
    int mmpMantaRayLikenessPct();
    int mmpMantaRayMoveInches();
    int mmpMantaRayAc();
    int mmpMantaRayTailDmgMin();
    int mmpMantaRayTailDmgMax();
    int mmpMantaRayTailStun();
    int mmpMantaRaySaltWaterTrigger();
    int mmpPoisonCloakRevivalPctPenalty();
    int mmpPoisonCloakRemoveCurseDestroys();
    int mmpPoisonCloakNeutralizeNoEffect();
    int mmpCloakProtRowCount();
    int mmpCloakProtAcPerPlus();
    int mmpCloakProtSavePerPlus();
    int mmpCloakProtExampleBaseAc();
    int mmpCarpetBandLo(int i);
    int mmpCarpetBandHi(int i);
    int mmpCarpetWidthFeet(int i);
    int mmpCarpetLengthFeet(int i);
    int mmpCarpetPersons(int i);
    int mmpCarpetSpeedInches(int i);
    int mmpElvenkindInvisibilityPct(int i);
    int mmpCloakProtBandLo(int i);
    int mmpCloakProtBandHi(int i);
    int mmpCloakProtPlus(int i);

    // ---- part 6 (R262): miscmagic_crystal_balls ----
    // Adnd1 - rules/dmg/miscmagic_crystal_balls.h
    // R262: the III.E misc magic explanation prose part 6
    // (DMG p.132) - Crystal Ball and Crystal Hypnosis
    // Ball, part2 lines 222-283 (global = 11065 + part2
    // line). ONE page header strips (279, the TREASURE
    // page). The slice is table-dense: the locating
    // chance table, the viewing period table, the
    // additional powers table and the notice-by-class
    // table all pin. 45 accessors: 36 scalars + 9
    // array walkers, no name collisions with
    // miscprose1.h through miscprose5.h. The slice
    // completes kMisc2 rows 11-12; the double
    // asterisk sits on row 11 (Crystal Ball 56-60) -
    // the R226 pin is correct. The Crystal Hypnosis
    // Ball is prose-only: three influencer kinds,
    // three fates, referee picks the pace.
    // Pure data + helpers, header-only (the
    // grenade.h pattern).
    int mmpCrystalBallDiameterInches();
    int mmpCrystalBallLocatingRowCount();
    int mmpCrystalBallLocatingWellKnownPct();
    int mmpCrystalBallLocatingKnownSlightlyPct();
    int mmpCrystalBallLocatingPicturedPct();
    int mmpCrystalBallLocatingPartPct();
    int mmpCrystalBallLocatingGarmentPct();
    int mmpCrystalBallLocatingWellInformedPct();
    int mmpCrystalBallLocatingSlightlyInformedPct();
    int mmpCrystalBallLocatingOtherPlanePct();
    int mmpCrystalBallViewingRowCount();
    int mmpCrystalBallOverrunIntLoss();
    int mmpCrystalBallOverrunInsaneUntilHealed();
    int mmpCrystalBallImprovingSpellCount();
    int mmpCrystalBallCastThroughSpellCount();
    int mmpCrystalBallCastThroughChancePerLevelPct();
    int mmpCrystalBallFeatureRowCount();
    int mmpCrystalBallSpellFunctionLevel();
    int mmpCrystalBallNoticeMinInt();
    int mmpCrystalBallDetectClassCount();
    int mmpCrystalBallIntFactorCount();
    int mmpCrystalBallDetectPerLevelPct();
    int mmpCrystalBallDetectionTablePage();
    int mmpCrystalBallDispelDownDays();
    int mmpCrystalBallCheckPerRound();
    int mmpCrystalBallSpellUserClassCount();
    int mmpCrystalBallClericDevicesAllowed();
    int mmpCrystalBallKnowledgeNotDistance();
    int mmpCrystalBallTelepathyCommunicationOnly();
    int mmpHypnosisBallCursed();
    int mmpHypnosisBallRadiatesEvil();
    int mmpHypnosisBallSuggestionImplanted();
    int mmpHypnosisBallIndistinguishable();
    int mmpHypnosisBallInfluencerKindCount();
    int mmpHypnosisBallFateCount();
    int mmpHypnosisBallRefereePace();
    int mmpCrystalBallLocatingPct(int i);
    int mmpCrystalBallViewingMinutes(int i);
    int mmpCrystalBallViewingTimesPerDay(int i);
    int mmpCrystalBallViewingBandHiPct(int i);
    int mmpCrystalBallFeatureBandLo(int i);
    int mmpCrystalBallFeatureBandHi(int i);
    int mmpCrystalBallFeatureCountAt(int i);
    int mmpCrystalBallDetectBasePct(int i);
    int mmpCrystalBallIntFactorPct(int i);

    // ---- part 7 (R263): miscmagic_cube_of_force_to_decanter_of_endless_water ----
    // Adnd1 - rules/dmg/miscmagic_cube_of_force_to_decanter_of_endless_water.h
    // R263: the III.E misc magic explanation prose part 7
    // (DMG p.132-133) - Cube of Force through Decanter
    // of Endless Water, part2 lines 285-322 (global =
    // 11065 + part2 line). ZERO page headers inside the
    // slice (a first); ONE seam pins exactly: the Daern
    // (line 314 ends but the person or, line 316
    // continues persons nearby). 45 accessors: 42
    // scalars + 3 array walkers, no name collisions
    // with miscprose1.h through miscprose6.h. The slice
    // completes kMisc2 rows 13-17; this stretch carries
    // no class marks and no asterisk rows (the negative
    // control slice). Pure data + helpers, header-only
    // (the grenade.h pattern).
    int mmpCubeForceWallInches();
    int mmpCubeForceCharges();
    int mmpCubeForceRestoreDays();
    int mmpCubeForceFaceCount();
    int mmpCubeForceSurchargeFormCount();
    int mmpCubeForceSpellsInOutBlocked();
    int mmpCubeForceMaterialCount();
    int mmpCubeFrostSideInches();
    int mmpCubeFrostTempF();
    int mmpCubeFrostColdAttackCount();
    int mmpCubeFrostCollapseHp();
    int mmpCubeFrostTurnRounds();
    int mmpCubeFrostRenewHours();
    int mmpCubeFrostDestroyHp();
    int mmpCubeFrostColdPer10BelowF();
    int mmpCubeFrostAt40BelowHp();
    int mmpCubicGateSideCount();
    int mmpCubicGatePrimeSides();
    int mmpCubicGateChosenSides();
    int mmpCubicGateNexusChancePct();
    int mmpCubicGateDrawRadiusFeet();
    int mmpCubicGateMaxLinks();
    int mmpDaernSquareFeet();
    int mmpDaernHeightFeet();
    int mmpDaernGroundDepthFeet();
    int mmpDaernCollapseHp();
    int mmpDaernWishRepairHp();
    int mmpDaernSpringRounds();
    int mmpDaernGrowthDamageMin();
    int mmpDaernGrowthDamageMax();
    int mmpDaernDoorOwnerOnly();
    int mmpDaernNormalWeaponsAffect();
    int mmpDaernDamageCumulative();
    int mmpDecanterModeCount();
    int mmpDecanterStreamGallonsPerRound();
    int mmpDecanterFountainLengthFeet();
    int mmpDecanterFountainGallonsPerRound();
    int mmpDecanterGeyserLengthFeet();
    int mmpDecanterGeyserGallonsPerRound();
    int mmpDecanterWaterTypeCount();
    int mmpDecanterGeyserKnockover();
    int mmpDecanterStopsOnCommand();
    int mmpCubeForceCostPerTurn(int i);
    int mmpCubeForceMoveInches(int i);
    int mmpCubeForceSurchargeAt(int i);

    // ---- part 8 (R264): miscmagic_deck_of_many_things ----
    // Adnd1 - rules/dmg/miscmagic_deck_of_many_things.h
    // R264: the III.E misc magic explanation prose part 8
    // (DMG p.133-134) - Deck of Many Things, part2
    // lines 324-400 (global = 11065 + part2 line). ONE
    // page header strips (360, the TREASURE page);
    // ZERO mid-sentence seams (a first). The 22-plaque
    // table pins: 9 asterisk plaques, 2 bold-face stop
    // plaques (The Void, Donjon), 2 discarded plaques
    // (Jester, Fool). 48 accessors: 45 scalars + 3
    // array walkers, no name collisions with
    // miscprose1.h through miscprose7.h. The slice
    // pins kMisc2 row 18 (Deck of Many Things, 73-76).
    // Pure data + helpers, header-only (the
    // grenade.h pattern).
    int mmpDeckPlaqueMaterialCount();
    int mmpDeckMinDraws();
    int mmpDeckMaxDraws();
    int mmpDeckJesterBonusDraws();
    int mmpDeckBasePlaqueCount();
    int mmpDeckFullPlaqueCount();
    int mmpDeckBaseChancePct();
    int mmpDeckFullChancePct();
    int mmpDeckAsteriskPlaqueCount();
    int mmpDeckDiscardPlaqueCount();
    int mmpDeckBoldFaceStopCount();
    int mmpDeckTablePlaqueCount();
    int mmpDeckSunXp();
    int mmpDeckMoonWishesMin();
    int mmpDeckMoonWishesMax();
    int mmpDeckMoonSpellLevel();
    int mmpDeckStarPoints();
    int mmpDeckStarMaxScore();
    int mmpDeckStarFallbackOrderCount();
    int mmpDeckCometMidpointProgress();
    int mmpDeckThroneCharisma();
    int mmpDeckThroneReactionBonusPct();
    int mmpDeckKeyMapBonusPct();
    int mmpDeckKeyWeaponCount();
    int mmpDeckKnightLevel();
    int mmpDeckKnightBonusPerDie();
    int mmpDeckKnightAbilityMax();
    int mmpDeckGemJewelryCount();
    int mmpDeckGemGemCount();
    int mmpDeckGemGemBaseGp();
    int mmpDeckGemXpLevelCap();
    int mmpDeckEuryaleSavePenalty();
    int mmpDeckRogueHenchmenAlienated();
    int mmpDeckJesterXp();
    int mmpDeckJesterExtraDraws();
    int mmpDeckFoolXp();
    int mmpDeckIdiotIntLossMin();
    int mmpDeckIdiotIntLossMax();
    int mmpDeckSkullDeathAc();
    int mmpDeckSkullDeathHp();
    int mmpDeckSkullScytheDmgMin();
    int mmpDeckSkullScytheDmgMax();
    int mmpDeckSkullUndeadForSpells();
    int mmpDeckFatesPartyEndures();
    int mmpDeckDonjonGearStripped();
    int mmpDeckPlaqueAsterisk(int i);
    int mmpDeckPlaqueBoldFace(int i);
    int mmpDeckPlaqueDiscarded(int i);

    // ---- part 9 (R265): miscmagic_drums_of_deafening_to_eyes_of_petrification ----
    // Adnd1 - rules/dmg/miscmagic_drums_of_deafening_to_eyes_of_petrification.h
    // R265: the III.E misc magic explanation prose part 9
    // (DMG p.134-135) - Drums of Deafening through Eyes
    // of Petrification plus the eye-mix note, part2
    // lines 402-429 (global = 11065 + part2 line). ONE
    // page header strips (417, the TREASURE page) cutting
    // the Eversmoking Bottle paragraph mid-sentence (one
    // seam, restored). The R264 pointer said four dusts;
    // the print shows three. 50 scalar accessors, no
    // name collisions with miscprose1.h through
    // miscprose8.h. The slice pins kMisc2 rows 19-29 -
    // completing the 30-row table (Candle of Invocation
    // through Eyes of Petrification). Pure data +
    // helpers, header-only (the grenade.h pattern).
    int mmpDrumDeafDeafRangeInches();
    int mmpDrumDeafStunRangeInches();
    int mmpDrumDeafStunMinRounds();
    int mmpDrumDeafStunMaxRounds();
    int mmpDrumDeafHemisphereHalfFeet();
    int mmpDrumPanicRangeInches();
    int mmpDrumPanicSafeZoneInches();
    int mmpDrumPanicFleeTurns();
    int mmpDrumPanicRestRoundsPerTurn();
    int mmpDrumPanicInt2SaveMod();
    int mmpDrumPanicInt1SaveMod();
    int mmpDrumPanicHemisphereHalfFeet();
    int mmpDustAppearDurationMinTurns();
    int mmpDustAppearDurationMaxTurns();
    int mmpDustAppearPacketRadiusFeet();
    int mmpDustAppearTubeStartFeet();
    int mmpDustAppearTubeEndFeet();
    int mmpDustAppearTubeLengthFeet();
    int mmpDustAppearContainerMin();
    int mmpDustAppearContainerMax();
    int mmpDustGoneDurationMinTurns();
    int mmpDustGoneDurationMaxTurns();
    int mmpDustGoneSprinkleMinTurns();
    int mmpDustGoneSprinkleMaxTurns();
    int mmpDustGoneAcBonusPlaces();
    int mmpDustChokeRadiusFeet();
    int mmpDustChokeDisabledMinRounds();
    int mmpDustChokeDisabledMaxRounds();
    int mmpEfreetiInsanePct();
    int mmpEfreetiWishesPct();
    int mmpEfreetiServePct();
    int mmpEfreetiWishCount();
    int mmpEfreetiReleaseSegments();
    int mmpEversmokeFirstRoundCubicFeet();
    int mmpEversmokePerRoundCubicFeet();
    int mmpEversmokeMaxCubicFeet();
    int mmpEyesCharmTargetsPerRound();
    int mmpEyesCharmBothSaveMod();
    int mmpEyesCharmOneSaveMod();
    int mmpEyesEagleVisionFactor();
    int mmpEyesEagleMinDistanceFeet();
    int mmpEyesEagleSeeAtFeet();
    int mmpEyesEagleNormalSeeFeet();
    int mmpEyesEagleSingleStunRounds();
    int mmpEyesMinuteVisionFactor();
    int mmpEyesMinuteMaxDistanceFeet();
    int mmpEyesPetrifyBasiliskGazePct();
    int mmpEyesMixInsanityMinTurns();
    int mmpEyesMixInsanityMaxTurns();
    int mmpEyesMixInsanityDice();

    // ---- part 10 (R266): miscmagic_figurines_of_wondrous_power ----
    // Adnd1 - rules/dmg/miscmagic_figurines_of_wondrous_power.h
    // R266: the III.E misc magic explanation prose part 10
    // (DMG p.135-136) - Figurines of Wondrous Power, part2
    // lines 433-479 (global = 11065 + part2 line). ONE page
    // header strips (477, the TREASURE page) cutting the
    // Serpentine Owl paragraph mid-sentence (one seam,
    // restored); the compilation also wraps the Goat of
    // Travelling paragraph at a bare blank line (450/452,
    // no page header) - one wrap artifact, restored. 90
    // accessors: 86 scalars + 4 array walkers (the figurine
    // type and marble elephant type tables), no name
    // collisions with miscprose1.h through miscprose9.h.
    // The slice pins kMisc3 row 0 (the Figurine band
    // 01-15, the single asterisk, per hit die values).
    // Pure data + helpers, header-only (the grenade.h
    // pattern).
    int mmpFigTypeCount();
    int mmpFigStatuetteInchesHigh();
    int mmpFigTypeLo(int i);
    int mmpFigTypeHi(int i);
    int mmpFlyAc();
    int mmpFlyHitDiceBase();
    int mmpFlyHitDiceExtra();
    int mmpFlyAirManeuverClass();
    int mmpFlySpeedUnladenInches();
    int mmpFlySpeedLadenInches();
    int mmpFlySpeedMaxLoadInches();
    int mmpFlyLadenMaxPounds();
    int mmpFlyMaxLoadPounds();
    int mmpFlyUsesPerWeek();
    int mmpFlyHoursPerDay();
    int mmpLionCount();
    int mmpLionAcFront();
    int mmpLionAcRear();
    int mmpLionHitDiceBase();
    int mmpLionHitDiceExtra();
    int mmpLionSlainReturnWeeks();
    int mmpLionUseDays();
    int mmpGoatCount();
    int mmpGoatUsesBeforeBurnout();
    int mmpGoatTravelAc();
    int mmpGoatTravelHp();
    int mmpGoatTravelAttacks();
    int mmpGoatTravelHornDmgMin();
    int mmpGoatTravelHornDmgMax();
    int mmpGoatTravelHitDice();
    int mmpGoatTravelMoveInches();
    int mmpGoatTravelMaxLoadPounds();
    int mmpGoatTravelPoundsPerMoveLoss();
    int mmpGoatTravelHoursPerWeek();
    int mmpGoatTravelRestDays();
    int mmpGoatTravailHoofDmgMin();
    int mmpGoatTravailHoofDmgMax();
    int mmpGoatTravailBiteDmgMin();
    int mmpGoatTravailBiteDmgMax();
    int mmpGoatTravailHornDmgMin();
    int mmpGoatTravailHornDmgMax();
    int mmpGoatTravailChargeBonus();
    int mmpGoatTravailChargeHornMin();
    int mmpGoatTravailChargeHornMax();
    int mmpGoatTravailAc();
    int mmpGoatTravailHp();
    int mmpGoatTravailHitDice();
    int mmpGoatTravailUsesPerMonth();
    int mmpGoatTravailMoveInches();
    int mmpGoatTerrorMoveInches();
    int mmpGoatTerrorAc();
    int mmpGoatTerrorHp();
    int mmpGoatTerrorHornSpearBonus();
    int mmpGoatTerrorHornSwordBonus();
    int mmpGoatTerrorRadiusInches();
    int mmpGoatTerrorStrengthLossPct();
    int mmpGoatTerrorHitPenalty();
    int mmpGoatTerrorIntervalWeeks();
    int mmpElephantTypeLo(int i);
    int mmpElephantTypeHi(int i);
    int mmpElephantHoursPerUse();
    int mmpElephantUsesPerMonth();
    int mmpSteadGoodRiderPct();
    int mmpSteadHoursPerUse();
    int mmpSteadUsesPerWeek();
    int mmpDogIntMin();
    int mmpDogIntMax();
    int mmpDogScentFreshPct();
    int mmpDogScentFreshHours();
    int mmpDogScentDecayPctPerHour();
    int mmpDogInfravisionFeet();
    int mmpDogSpotHiddenPct();
    int mmpDogSpotInvisiblePct();
    int mmpDogSpotPhasedPct();
    int mmpDogHoursPerUse();
    int mmpDogUsesPerWeek();
    int mmpOwlAc();
    int mmpOwlMoveInches();
    int mmpOwlHpMin();
    int mmpOwlHpMax();
    int mmpOwlDmgMin();
    int mmpOwlDmgMax();
    int mmpOwlGiantUses();
    int mmpOwlSilencePct();
    int mmpOwlInfravisionFeet();
    int mmpOwlDarkVisionFactor();
    int mmpOwlHearMouseFeet();
    int mmpOwlCounterStealthPct();
    int mmpOwlIntMin();
    int mmpOwlIntMax();

    // ---- part 11 (R267): miscmagic_flask_of_curses_to_girdle_of_giant_strength ----
    // Adnd1 - rules/dmg/miscmagic_flask_of_curses_to_girdle_of_giant_strength.h
    // R267: the III.E misc magic explanation prose part 11
    // (DMG p.136-137) - Flask of Curses through the Girdle
    // of Giant Strength, part2 lines 481-530 (global =
    // 11065 + part2 line). ONE page header strips (493,
    // the TREASURE page) cutting the Gem of Brightness
    // paragraph mid-sentence (one seam, restored). 63
    // accessors: 49 scalars + 14 array walkers (the giant
    // strength and rock hurling tables), no name
    // collisions with miscprose1.h through miscprose10.h.
    // The slice pins kMisc3 rows 1-9, the (C, F, T) marks
    // riding rows 4, 5, 8 and 9. Pure data + helpers,
    // header-only (the grenade.h pattern).
    int mmpFlaskCurseOnFirstOpen();
    int mmpFlaskHarmlessAfterUse();
    int mmpGauntDexBoostLow();
    int mmpGauntDexBoostMid();
    int mmpGauntDexBoostHigh();
    int mmpGauntDexThiefLevel();
    int mmpGauntDexThiefBonusPct();
    int mmpGauntFumbDropPct();
    int mmpGauntFumbDexPenalty();
    int mmpGauntFumbRemoveCurseOnly();
    int mmpGauntOgreStrength();
    int mmpGauntOgreStrengthPercentile();
    int mmpGauntOgreHitBonus();
    int mmpGauntOgreDmgBonus();
    int mmpGauntSwimUnderwaterInches();
    int mmpGauntSwimSurfaceInches();
    int mmpGauntSwimClimbSuccessPct();
    int mmpGauntSwimThiefSuccessTenthPct();
    int mmpGemBrightLightSorts();
    int mmpGemBrightConeLengthFeet();
    int mmpGemBrightConeRadiusHalfFeet();
    int mmpGemBrightRayDiameterFeet();
    int mmpGemBrightRayLengthFeet();
    int mmpGemBrightDazzleMinRounds();
    int mmpGemBrightDazzleMaxRounds();
    int mmpGemBrightRayCharges();
    int mmpGemBrightFlashLengthFeet();
    int mmpGemBrightFlashRadiusFeet();
    int mmpGemBrightBlindMinRounds();
    int mmpGemBrightBlindMaxRounds();
    int mmpGemBrightEyePenaltyMin();
    int mmpGemBrightEyePenaltyMax();
    int mmpGemBrightFlashCharges();
    int mmpGemBrightTotalCharges();
    int mmpGemBrightDarknessDrainCharges();
    int mmpGemBrightDarknessRoundUseless();
    int mmpGemBrightDarknessDayUseless();
    int mmpGemBrightDarknessExpelCharges();
    int mmpGemSeeCursoryRangeInches();
    int mmpGemSeeCarefulRangeInches();
    int mmpGemSeeCursoryAreaFeet();
    int mmpGemSeeCursoryRounds();
    int mmpGemSeeCarefulAreaFeet();
    int mmpGemSeeCarefulRounds();
    int mmpGemSeeHallucinationPct();
    int mmpGirdleSexWishRestorePct();
    int mmpGirdleSexSexlessPct();
    int mmpGirdleGiantTypeCount();
    int mmpGirdleGiantRockDmgMin();
    int mmpGirdleGiantDiceLo(int i);
    int mmpGirdleGiantDiceHi(int i);
    int mmpGirdleGiantStrength(int i);
    int mmpGirdleGiantHitBonus(int i);
    int mmpGirdleGiantDmgBonus(int i);
    int mmpGirdleGiantOpenDoorsTop(int i);
    int mmpGirdleGiantOpenDoorsBottom(int i);
    int mmpGirdleGiantOpenChances(int i);
    int mmpGirdleGiantOpenOutOf(int i);
    int mmpGirdleGiantWeightAllowance(int i);
    int mmpGirdleGiantRangeInches(int i);
    int mmpGirdleGiantRockDmgMax(int i);
    int mmpGirdleGiantRockWeight(int i);
    int mmpGirdleGiantBendBarsPct(int i);

    // ---- part 12 (R268): miscmagic_helm_of_brilliance_to_horn_of_bubbles ----
    // Adnd1 - rules/dmg/miscmagic_helm_of_brilliance_to_horn_of_bubbles.h
    // R268: the III.E misc magic explanation prose part 12
    // (DMG p.137-139) - Helm of Brilliance through the Horn
    // of Bubbles, part2 lines 532-579 (global =
    // 11065 + part2 line). ONE page header inside the slice
    // (541, the TREASURE page) falls between the jewel
    // functions table and the Each gem paragraph of the
    // Brilliance item. The jewel functions table: the book
    // upload flattens the four gem rows into the Diamond
    // cell (the Ruby, Fire Opal and Opal cells empty) -
    // the four-row table restored from the compilation
    // (the R175 precedent): Diamond prismatic spray (7th
    // illusionist), Ruby wall of fire (5th druid), Fire
    // Opal fireball (3rd magic-user), Opal light (1st
    // cleric). 91 accessors: 87 scalars + 4 array walkers
    // (the jewel functions table), no name collisions with
    // miscprose1.h through miscprose11.h.
    // The slice pins kMisc3 rows 10-17, no class marks and
    // no asterisks ride these rows. Pure data + helpers,
    // header-only (the grenade.h pattern).
    int mmpHelmBrilCommandWordOnly();
    int mmpHelmBrilTrueNatureVisible();
    int mmpHelmBrilArmorPlus();
    int mmpHelmBrilDiamondCount();
    int mmpHelmBrilRubyCount();
    int mmpHelmBrilFireOpalCount();
    int mmpHelmBrilOpalCount();
    int mmpHelmBrilScintillatesInBrightLight();
    int mmpHelmBrilJewelUseSegments();
    int mmpHelmBrilJewelUsableOnce();
    int mmpHelmBrilUsesPerRound();
    int mmpHelmBrilSpellLevelDoublingFactor();
    int mmpHelmBrilUndeadGlowRangeFeet();
    int mmpHelmBrilUndeadPainDmgMin();
    int mmpHelmBrilUndeadPainDmgMax();
    int mmpHelmBrilUndeadExemptKinds();
    int mmpHelmBrilFlameSwordEffectRounds();
    int mmpHelmBrilFlameSwordAdditional();
    int mmpHelmBrilProduceFlameDruidLevel();
    int mmpHelmBrilFireResistRingStrength();
    int mmpHelmBrilFireResistAugmentable();
    int mmpHelmBrilPowderOnExpenditure();
    int mmpHelmBrilJewelRemovalDestroys();
    int mmpHelmBrilJewelRemagickable();
    int mmpHelmBrilRetrySaveWithoutMagic();
    int mmpHelmBrilOverloadDetonatesRemaining();
    int mmpHelmBrilOverloadEffectsInMultiple();
    int mmpHelmBrilJewelRowCount();
    int mmpHelmBrilJewelGemCount(int i);
    int mmpHelmBrilJewelSpellLevel(int i);
    int mmpHelmBrilJewelCasterKind(int i);
    int mmpHelmBrilJewelFunctionKind(int i);
    int mmpHelmComprStrangeTonguesPct();
    int mmpHelmComprMagicalWritingsPct();
    int mmpHelmComprAllOrNone();
    int mmpHelmComprImpliesSpellUse();
    int mmpHelmComprHelmetOfAcValue();
    int mmpHelmOppAlignIndeterminateDweomer();
    int mmpHelmOppAlignCurseOnDonning();
    int mmpHelmOppAlignAbsoluteKinds();
    int mmpHelmOppAlignAlterationDesired();
    int mmpHelmOppAlignRestoreSpellKinds();
    int mmpHelmOppAlignSelfRestoreAttempts();
    int mmpHelmOppAlignPaladinQuestAndAtone();
    int mmpHelmOppAlignPowersAfterFunctioning();
    int mmpHelmTelepathyRangeInches();
    int mmpHelmTelepathyStoneBarrierFeet();
    int mmpHelmTelepathyIronBarrierQuarterFeet();
    int mmpHelmTelepathyLeadGoldSheetBlocks();
    int mmpHelmTelepathyDirectional();
    int mmpHelmTelepathyConsciousEffort();
    int mmpHelmTelepathySuggestPctPer2IntAbove();
    int mmpHelmTelepathySuggestPctPer1IntBelow();
    int mmpHelmTelepathySavePenaltyPer2IntBelow();
    int mmpHelmTelepathySaveBonusPer1IntAbove();
    int mmpHelmTelepathyEqualIntSaveAdjustment();
    int mmpHelmTelepathyPsionicAttackBonus();
    int mmpHelmTelepathyPsionicStrengthBonus();
    int mmpHelmTeleportPerDay();
    int mmpHelmTeleportMuRefreshRepeats();
    int mmpHelmTeleportMuStillPersonalAfterRefresh();
    int mmpHelmTeleportMuUncastPersonalCount();
    int mmpHelmTeleportUsageAfterMemoryLost();
    int mmpHelmUnderwaterSeeAndBreathe();
    int mmpHelmUnderwaterLensCompartments();
    int mmpHelmUnderwaterVisionFactor();
    int mmpHelmUnderwaterObstructionsBlock();
    int mmpHelmUnderwaterAirGlobeUntilRepeat();
    int mmpHornBlastingConeLengthInches();
    int mmpHornBlastingConeBaseWidthInches();
    int mmpHornBlastingSaveStunRounds();
    int mmpHornBlastingSaveDeafRounds();
    int mmpHornBlastingFailDmgMin();
    int mmpHornBlastingFailDmgMax();
    int mmpHornBlastingFailStunRounds();
    int mmpHornBlastingFailDeafRounds();
    int mmpHornBlastingPulseWidthFeet();
    int mmpHornBlastingPulseLengthInches();
    int mmpHornBlastingCatapultMultiplier();
    int mmpHornBlastingCatapultHitDamage();
    int mmpHornBlastingStructuralPoints();
    int mmpHornBlastingExplodePctPerExtraUse();
    int mmpHornBlastingExplodeDmgMin();
    int mmpHornBlastingExplodeDmgMax();
    int mmpHornBlastingCharges();
    int mmpHornBlastingShiverPctPerUse();
    int mmpHornBlastingShiverWielderDamage();
    int mmpHornBubblesBlindRoundsMin();
    int mmpHornBubblesBlindRoundsMax();
    int mmpHornBubblesOnlyWhenSlayerSeeks();
    int mmpHornBubblesAppearanceMayDelay();

    // ---- part 13 (R269): miscmagic_horn_of_collapsing_to_incense_of_meditation ----
    // Adnd1 - rules/dmg/miscmagic_horn_of_collapsing_to_incense_of_meditation.h
    // R269: the III.E misc magic explanation prose part 13
    // (DMG p.139-140) - Horn of Collapsing through the
    // Incense of Meditation, part2 lines 581-626 (global =
    // 11065 + part2 line). ONE page header inside the slice
    // (592, the TREASURE page) cuts the Collapsing proper
    // use paragraph mid-sentence (one seam, restored). ONE
    // OCR artifact restored from the compilation (the R175
    // precedent): the meditation survival clause reads
    // (rounded down), the upload prints grounded down).
    // 73 accessors: 60 scalars + 13 array walkers (the
    // triton summon and the Valhalla variety tables), no
    // name collisions with miscprose1.h through
    // miscprose12.h. The slice pins kMisc3 rows 18-23: the
    // (C, F) mark on the Horn of the Tritons (row 19), the
    // (C) mark on the Incense of Meditation (row 23), the
    // Valhalla double asterisk (row 20). Pure data +
    // helpers, header-only (the grenade.h pattern).
    int mmpHornCollapseMisfirePct();
    int mmpHornCollapseOutRocksMin();
    int mmpHornCollapseOutRocksMax();
    int mmpHornCollapseOutRockDmgMin();
    int mmpHornCollapseOutRockDmgMax();
    int mmpHornCollapseIndoorDmgMin();
    int mmpHornCollapseIndoorDmgMax();
    int mmpHornCollapseUnderDmgMin();
    int mmpHornCollapseUnderDmgMax();
    int mmpHornCollapseUnderHeightFactorFeet();
    int mmpHornCollapseAimRangeMinFeet();
    int mmpHornCollapseAimRangeMaxFeet();
    int mmpHornCollapseRoofWidthFeet();
    int mmpHornCollapseRoofLengthFeet();
    int mmpHornCollapseRoofRadiusFeet();
    int mmpHornCollapseIndoorsOrUndergroundOnly();
    int mmpHornTritonPerDay();
    int mmpHornTritonTritonPerDay();
    int mmpHornTritonFunctionCount();
    int mmpHornTritonCalmRadiusMiles();
    int mmpHornTritonCalmDispelKinds();
    int mmpHornTritonSummonKindCount();
    int mmpHornTritonSummonDieLo(int i);
    int mmpHornTritonSummonDieHi(int i);
    int mmpHornTritonSummonCountMin(int i);
    int mmpHornTritonSummonCountMax(int i);
    int mmpHornTritonPanicAnimalOrLower();
    int mmpHornTritonPanicToHitPenalty();
    int mmpHornTritonPanicTurnsMin();
    int mmpHornTritonPanicTurnsMax();
    int mmpHornTritonPanicRoundsPerTurn();
    int mmpHornTritonPanicRoundsMin();
    int mmpHornTritonPanicRoundsMax();
    int mmpHornTritonHearRadiusLeagues();
    int mmpHornValhallaVarietyCount();
    int mmpHornValhallaBlowIntervalDays();
    int mmpHornValhallaSummonedAc();
    int mmpHornValhallaSummonedHpPerDie();
    int mmpHornValhallaSwordSpearPct();
    int mmpHornValhallaAxeSpearPct();
    int mmpHornValhallaServiceTurns();
    int mmpHornValhallaAlignedPct();
    int mmpHornValhallaBronzeXpMultiplier();
    int mmpHornValhallaIronXpMultiplier();
    int mmpHornValhallaDiceLo(int i);
    int mmpHornValhallaDiceHi(int i);
    int mmpHornValhallaCountMin(int i);
    int mmpHornValhallaCountMax(int i);
    int mmpHornValhallaLevel(int i);
    int mmpHornValhallaUsableAny(int i);
    int mmpHornValhallaUsableCleric(int i);
    int mmpHornValhallaUsableFighter(int i);
    int mmpHornValhallaUsableThief(int i);
    int mmpHorseshoesSpeedShoeCount();
    int mmpHorseshoesSpeedFullPct();
    int mmpHorseshoesSpeedDropPct();
    int mmpHorseshoesSpeedDropLeagues();
    int mmpHorseshoesSpeedOneLostPct();
    int mmpHorseshoesSpeedTwoLostPct();
    int mmpHorseshoesZephyrGroundless();
    int mmpHorseshoesZephyrNoTracks();
    int mmpHorseshoesZephyrNoTireHours();
    int mmpHorseshoesZephyrPerDay();
    int mmpIncenseMedRecognizeClericLevel();
    int mmpIncenseMedPrayHours();
    int mmpIncenseMedCureAlwaysMax();
    int mmpIncenseMedBroadestArea();
    int mmpIncenseMedSavePenalty();
    int mmpIncenseMedNotSurvivingDivisor();
    int mmpIncenseMedPieceCountMin();
    int mmpIncenseMedPieceCountMax();
    int mmpIncenseMedBurnHours();
    int mmpIncenseMedEffectHours();

    // ---- part 14 (R270): miscmagic_incense_of_obsession_to_fochlucan_bandore ----
    // Adnd1 - rules/dmg/miscmagic_incense_of_obsession_to_fochlucan_bandore.h
    // R270: the III.E misc magic explanation prose part 14
    // (DMG p.141-142) - Incense of Obsession through the
    // Fochlucan Bandore, part2 lines 630-684 (global =
    // 11065 + part2 line). ONE page header inside the slice
    // (674, the TREASURE page) falls between the bandore
    // paragraph and its song list (one seam, restored). The
    // ioun stone property table: the upload mangles rows 3,
    // 5 and 12 (the shape cells folded into the roll and
    // color cells, the missing space in 5pink) and wraps the
    // regeneration cell across rows - the 15-row table
    // restored from the 1eonline.info compilation (the R175
    // precedent).
    // 47 accessors: 41 scalars + 6 array walkers (the stone
    // property table), no name collisions with miscprose1.h
    // through miscprose13.h. The slice pins kMisc3 rows
    // 24-26: the (C) mark on the Incense of Obsession (row
    // 24), the triple asterisk on the Ioun Stones (row 25,
    // per stone), the quadruple asterisk on the Instrument of
    // the Bards (rows 73-78, per level of instrument). Pure
    // data + helpers, header-only (the grenade.h pattern).
    int mmpObsessionDurationHours();
    int mmpObsessionPiecesMin();
    int mmpObsessionPiecesMax();
    int mmpObsessionBurnHours();
    int mmpIounSortCount();
    int mmpIounOwnerRadiusFeet();
    int mmpIounOrbitMinFeet();
    int mmpIounOrbitMaxFeet();
    int mmpIounFoundMin();
    int mmpIounFoundMax();
    int mmpIounTableRowCount();
    int mmpIounDeadRowLo();
    int mmpIounDeadRowHi();
    int mmpIounStatBonusPoints();
    int mmpIounStatCap();
    int mmpIounStatBonusRowCount();
    int mmpIounLevelGainLevels();
    int mmpIounRegenHpPerTurn();
    int mmpIounPurpleStoreMin();
    int mmpIounPurpleStoreMax();
    int mmpIounRoseProtectionBonus();
    int mmpIounGrayPsionicBonus();
    int mmpIounGrayPsionicCap();
    int mmpIounHpToDestroy();
    int mmpIounSaveBonus();
    int mmpIounAttackAc();
    int mmpIounRowRollLo(int i);
    int mmpIounRowRollHi(int i);
    int mmpIounRowAddsStat(int i);
    int mmpIounRowAbsorbMaxLevel(int i);
    int mmpIounRowBurnoutMin(int i);
    int mmpIounRowBurnoutMax(int i);
    int mmpBardInstrumentCount();
    int mmpFochlucanStringCount();
    int mmpFochlucanLowestFaeriePct();
    int mmpFochlucanLowestReversePct();
    int mmpFochlucanFaerieBasePct();
    int mmpFochlucanReverseReductionPerLevelPct();
    int mmpFochlucanSongCount();
    int mmpFochlucanCharmBonusPct();
    int mmpFochlucanEntanglePerDay();
    int mmpFochlucanShillelaghPerDay();
    int mmpFochlucanSpeakAnimalsPerDay();
    int mmpFochlucanLowestSongWorkPct();
    int mmpFochlucanLowestSongFailPct();
    int mmpFochlucanLowestFailDamageMin();
    int mmpFochlucanLowestFailDamageMax();

    // ---- part 15 (R271): miscmagic_mac_fuirmidh_cittern_to_instrument_type_table ----
    // Adnd1 - rules/dmg/miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.h
    // R271: the III.E misc magic explanation prose part 15
    // (DMG p.142-148) - Mac-Fuirmidh Cittern through the
    // general properties and the type table,
    // part2 lines 686-764 (global = 11065 + part2
    // line). The slice closes the Instrument of the
    // Bards item (the kMisc3 row 26 quadruple
    // quadruple asterisk, 1,000 xp / 5,000 gp per level of
    // instrument). The upload DROPS the TREASURE page headers
    // across the instruments run (none between 674 and 792) -
    // the page attribution rides the compilation TOC anchor
    // (the instruments at pp.147-148); NO seam restored this
    // round, the slice carries no page header. The instrument
    // facts verified against the 1eonline.info compilation page
    // instrumentofthebards.htm (the R175 precedent source);
    // the level gates (5th, 8th, 11th, 14th, 17th, 20th) match
    // the bard.h Table II college ladder.
    // 51 accessors: 49 scalars + 2 array walkers (the type
    // die table), no name collisions with miscprose1.h
    // through miscprose14.h. Pure data + helpers,
    // header-only (the grenade.h pattern).
    int mmpCitternMisusePct();
    int mmpCitternDamageMin();
    int mmpCitternDamageMax();
    int mmpCitternLevelGate();
    int mmpCitternCharmBonusPct();
    int mmpCitternSongCount();
    int mmpDossMisusePct();
    int mmpDossDamageMin();
    int mmpDossDamageMax();
    int mmpDossLevelGate();
    int mmpDossCharmBonusPct();
    int mmpDossSongCount();
    int mmpDossProtFireRadiusFeet();
    int mmpCanaithMisusePct();
    int mmpCanaithDamageMin();
    int mmpCanaithDamageMax();
    int mmpCanaithLevelGate();
    int mmpCanaithCharmBonusPct();
    int mmpCanaithSongCount();
    int mmpCanaithProtLightningRadiusFeet();
    int mmpCliMisusePct();
    int mmpCliDamageMin();
    int mmpCliDamageMax();
    int mmpCliLevelGate();
    int mmpCliCharmBonusPct();
    int mmpCliSongCount();
    int mmpAnstruthMisusePct();
    int mmpAnstruthDamageMin();
    int mmpAnstruthDamageMax();
    int mmpAnstruthLevelGate();
    int mmpAnstruthCharmBonusPct();
    int mmpAnstruthSongCount();
    int mmpOllamhDamageMin();
    int mmpOllamhDamageMax();
    int mmpOllamhLevelGate();
    int mmpOllamhCharmBonusPct();
    int mmpOllamhSongCount();
    int mmpInstrumentAbilityCount();
    int mmpInstrumentAbilityRadiusFeet();
    int mmpInstrumentAbilityPerDay();
    int mmpInstrumentActivateSegments();
    int mmpInstrumentCompleteRounds();
    int mmpInstrumentCollegeTurnsMin();
    int mmpInstrumentCollegeTurnsMax();
    int mmpInstrumentMagnusTurns();
    int mmpInstrumentCharmExcessThresholdPct();
    int mmpInstrumentCharmExcessStepPct();
    int mmpInstrumentCharmExcessPenaltyPerStep();
    int mmpInstrumentKindRowCount();
    int mmpInstrumentDieLo(int i);
    int mmpInstrumentDieHi(int i);

    // ---- part 16 (R272): miscmagic_iron_flask_to_keoghtoms_ointment ----
    // Adnd1 - rules/dmg/miscmagic_iron_flask_to_keoghtoms_ointment.h
    // R272: the III.E misc magic explanation prose part 16
    // (DMG p.148-149) - Iron Flask through Keoghtom
    // ointment, part2 lines 766-802 (global = 11065 +
    // part2 line). The slice completes the kMisc3 rows
    // 27-32, the 33-row III.E.3 table. ONE page header
    // inside the slice (792, the TREASURE page) falls
    // inside the javelin of lightning paragraph between
    // 1-6 hit and points of damage - ONE seam restored
    // this round; the page attribution rides the
    // 1eonline.info compilation TOC (the jewels,
    // magical at p.149). The flask contents table: the
    // upload drops the pipe in three rows (82-83
    // mezzodaemon, 94-97 water elemental, 98-99 wind
    // walker) - the 19-row d100 table pinned with the
    // printed 00 row as the d100 100 (the engine kMisc3
    // 93-00 precedent). 43 accessors: 41 scalars + 2
    // walkers (the flask contents die table), no name
    // collisions with miscprose1.h through
    // miscprose15.h. Pure data + helpers, header-only
    // (the grenade.h pattern).
    int mmpFlaskRangeInches();
    int mmpFlaskMaxCreatures();
    int mmpFlaskServiceTurns();
    int mmpFlaskServiceHours();
    int mmpFlaskRepeatSaveBonus();
    int mmpFlaskContentsRowCount();
    int mmpFlaskContentsLo(int i);
    int mmpFlaskContentsHi(int i);
    int mmpJavelinLightningPlus();
    int mmpJavelinLightningRangeInches();
    int mmpJavelinLightningStrokeWidthHalfInches();
    int mmpJavelinLightningStrokeLengthInches();
    int mmpJavelinLightningDamageMin();
    int mmpJavelinLightningDamageMax();
    int mmpJavelinLightningElectricalDamage();
    int mmpJavelinLightningBackstrokeMin();
    int mmpJavelinLightningBackstrokeMax();
    int mmpJavelinLightningBackstrokeInches();
    int mmpJavelinLightningFoundMin();
    int mmpJavelinLightningFoundMax();
    int mmpJavelinPiercingRangeInches();
    int mmpJavelinPiercingToHitBonus();
    int mmpJavelinPiercingDamageMin();
    int mmpJavelinPiercingDamageMax();
    int mmpJavelinPiercingFoundMin();
    int mmpJavelinPiercingFoundMax();
    int mmpJavelinPiercingThrows();
    int mmpJewelAttacksWanderingPct();
    int mmpJewelAttacksPursuitPct();
    int mmpJewelFlawlessBoostPct();
    int mmpJewelFlawlessBaseTenths();
    int mmpJewelFlawlessBoostedTenths();
    int mmpJewelFlawlessFacetMin();
    int mmpJewelFlawlessFacetMax();
    int mmpJewelFlawlessTriggerD10();
    int mmpJewelFlawlessFacetsLostPerBoost();
    int mmpOintmentJarDiameterInches();
    int mmpOintmentJarDepthInches();
    int mmpOintmentApplications();
    int mmpOintmentHealMin();
    int mmpOintmentHealMax();
    int mmpOintmentFoundMin();
    int mmpOintmentFoundMax();

    // ---- part 17 (R273): miscmagic_librams_lyre_and_manuals ----
    // Adnd1 - rules/dmg/miscmagic_librams_lyre_and_manuals.h
    // R273: the III.E misc magic explanation prose part 17
    // (DMG p.149-150) - the three Librams, the Lyre of
    // Building and the manuals of Bodily Health, Gainful
    // Exercise, Golems, Puissant Skill at Arms and
    // Quickness of Action, part2 lines 806-841 (global =
    // 11065 + part2 line), pinning the kMisc4 rows 0-8 of
    // the 36-row III.E.4 table. ONE page header inside
    // the slice (839, the TREASURE page) falls inside the
    // manual of quickness paragraph between Only after
    // and the month of training - ONE seam restored this
    // round; the page attribution rides the compilation
    // TOC index (the books and manuals at pp.149-150) on
    // the R272-established p.149 base. The upload drops
    // the pipe in two part1 rows (02 the Ineffable
    // Damnation, 08 the Puissant Skill at Arms); the
    // bodily health paragraph carries a stray apostrophe
    // artifact after the word manual (pinned as the
    // upload prints it, apostrophe-free here). 47
    // accessors: 43 scalars + 4 walkers (the golem table
    // die bands, months and costs), no name collisions
    // with miscprose1.h through miscprose16.h. Pure data
    // + helpers, header-only (the grenade.h pattern).
    int mmpLibramStudyWeeks();
    int mmpLibramMisuseDamageMin();
    int mmpLibramMisuseDamageMax();
    int mmpLibramUnconsciousTurnsMin();
    int mmpLibramUnconsciousTurnsMax();
    int mmpLibramInsanityRestMonths();
    int mmpLibramDamnationLevelLoss();
    int mmpLyreNegateKindCount();
    int mmpLyreNegateRounds();
    int mmpLyreNegatePerDay();
    int mmpLyreBuildPerWeek();
    int mmpLyreBuildTurns();
    int mmpLyreBuildMen();
    int mmpLyreBuildDays();
    int mmpLyreFalseChordPct();
    int mmpLyreFalseChordKnownPct();
    int mmpLyreFalseChordDisturbedPct();
    int mmpHealthReadHours();
    int mmpHealthReadDaysMin();
    int mmpHealthReadDaysMax();
    int mmpHealthConGain();
    int mmpHealthRegimenMonths();
    int mmpHealthForgetMonths();
    int mmpExerciseStrGain();
    int mmpGolemKindCount();
    int mmpGolemMinUserLevel();
    int mmpGolemFailurePctPerLevel();
    int mmpGolemFailureWindowTurns();
    int mmpGolemClericXpLossMin();
    int mmpGolemClericXpLossMax();
    int mmpGolemMuLevelLoss();
    int mmpGolemOtherDamageMin();
    int mmpGolemOtherDamageMax();
    int mmpGolemDieLo(int i);
    int mmpGolemDieHi(int i);
    int mmpGolemMonths(int i);
    int mmpGolemCostGp(int i);
    int mmpPuissantPracticeMonths();
    int mmpPuissantForgetMonths();
    int mmpPuissantStunTurnsMin();
    int mmpPuissantStunTurnsMax();
    int mmpPuissantXpLossMin();
    int mmpPuissantXpLossMax();
    int mmpQuicknessStudyDays();
    int mmpQuicknessPracticeMonths();
    int mmpQuicknessDexGain();
    int mmpQuicknessRememberMonths();

    // ---- part 18 (R274): miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles ----
    // Adnd1 - rules/dmg/miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.h
    // R274: the III.E misc magic explanation prose part 18
    // (DMG p.150-151) - the Manual of Stealthy Pilfering, the
    // Mattock and Maul of the Titans, the Medallions of ESP
    // and Thought Projection, the Mirrors of Life Trapping,
    // Mental Prowess and Opposition and the Necklaces of
    // Adaptation and Missiles, part2 lines 843-900 (global
    // = 11065 + part2 line), pinning the kMisc4 rows 9-18 of
    // the 36-row III.E.4 table. ONE mid-sentence break inside
    // the slice: the mirror of life trapping paragraph splits
    // between not a (863) and factor (865), the upload
    // prints no running head at the break - ONE
    // seam restored this round; the slice rides the
    // pp.150-151 attribution on the R273-established p.150
    // base. The upload quirks this round: the necklace of
    // missiles table is badly mangled (pipes misplaced,
    // fragments pushed into the wrong cells) - the
    // dash-separated count ladders reconstruct it exactly
    // and cross-check against the printed example:
    // one 7-dice, two 5-dice, four 3-dice (the 9-12 row);
    // the stray apostrophe artifact after the word manual
    // recurs in the pilfering paragraph (a like manual)
    // beside a printed magic- users with a space (both
    // pinned as the upload prints them,
    // apostrophe-free here); the medallion table prints
    // clean. 67
    // accessors: 59 scalars + 8 walkers (the medallion die
    // bands, ranges and empathy marks; the necklace die
    // bands, hit dice columns and the flattened 70-cell
    // count table), no name collisions with miscprose1.h
    // through miscprose17.h. Pure data + helpers,
    // header-only (the grenade.h pattern).
    int mmpStealthyPracticeMonths();
    int mmpStealthyKnowledgeMonths();
    int mmpStealthyAssassinXp();
    int mmpStealthyAssassinWeeks();
    int mmpStealthyWrongDamageMin();
    int mmpStealthyWrongDamageMax();
    int mmpStealthyStunRoundsMin();
    int mmpStealthyStunRoundsMax();
    int mmpStealthyXpLossMin();
    int mmpStealthyXpLossMax();
    int mmpStealthyAtoneDays();
    int mmpStealthyWisdomLoss();
    int mmpMattockLengthFeet();
    int mmpMattockWeightLb();
    int mmpMattockMinStrength();
    int mmpMattockEarthCubicFeet();
    int mmpMattockRockCubicFeet();
    int mmpMattockAreaTurns();
    int mmpMattockHitBonus();
    int mmpMattockDamageMin();
    int mmpMattockDamageMax();
    int mmpMaulLengthFeet();
    int mmpMaulWeightLb();
    int mmpMaulMinStrength();
    int mmpMaulPileDiameterFeet();
    int mmpMaulPileDepthFeet();
    int mmpMaulBlowsPerRound();
    int mmpMaulDoorHeightFeet();
    int mmpMaulDoorWidthFeet();
    int mmpMaulDoorThicknessInches();
    int mmpMaulDoorBlows();
    int mmpMaulDoorIronBlows();
    int mmpMaulHitBonus();
    int mmpMaulDamageMin();
    int mmpMaulDamageMax();
    int mmpEspPathWidthFeet();
    int mmpEspBroadenFeet();
    int mmpEspBroadenPerFeet();
    int mmpEspMaxWidthFeet();
    int mmpEspMaxWidthAtFeet();
    int mmpEspUseRounds();
    int mmpEspStoneBlockFeet();
    int mmpEspMetalBlockSixthsFeet();
    int mmpEspMalfunctionRoll();
    int mmpEspMalfunctionDieSides();
    int mmpEspRowLo(int i);
    int mmpEspRowHi(int i);
    int mmpEspRangeFeet(int i);
    int mmpEspEmpathy(int i);
    int mmpProjectionWorksRoll();
    int mmpTrapAreaSquareFeet();
    int mmpTrapCellMin();
    int mmpTrapCellMax();
    int mmpTrapTriggerFeet();
    int mmpTrapSeePctUnaware();
    int mmpTrapSeePctAvoiding();
    int mmpTrapSeePctAware();
    int mmpTrapOverflowFreed();
    int mmpProwessQuestionsPerWeek();
    int mmpProwessWidthFeet();
    int mmpProwessHeightFeet();
    int mmpAdaptationAirlessDays();
    int mmpMissileRangeInches();
    int mmpNeckRowLo(int i);
    int mmpNeckRowHi(int i);
    int mmpNeckDieOf(int i);
    int mmpNeckCell(int i);

    // ---- part 19 (R275): miscmagic_necklace_of_prayer_beads_to_periapts ----
    // Adnd1 - rules/dmg/miscmagic_necklace_of_prayer_beads_to_periapts.h
    // R275: the III.E misc magic explanation prose part 19
    // (DMG p.152-153) - the Necklace of Prayer Beads, the
    // Necklace of Strangulation, the Nets of Entrapment and
    // Snaring, Nolzurs Marvelous Pigments, the Pearls of
    // Power and Wisdom and the Periapts of Foul Rotting,
    // Health, Proof Against Poison and Wound Closure,
    // part2 lines 905-969 (global = 11065 + part2 line),
    // pinning the kMisc4 rows 19-29 of the 36-row III.E.4
    // table. ONE mid-sentence break inside the slice: the
    // pearl of power paragraph splits between a pearl of
    // power (933) and enables the possessor (935), the
    // upload prints no running head at the break - ONE
    // seam restored this round; the slice rides the
    // pp.152-153 attribution on the R274-established p.152
    // base (the TREASURE running head at 903). The upload
    // quirks this round: the bead table rows are split
    // across multiple table lines (the karma and summons
    // beads span three each); the part1 pigments row
    // misplaces the apostrophe after the s; the net of
    // entrapment prints the one-quarter character (mesh)
    // and an en-dash (AC -10) - pinned as plain digits,
    // apostrophe-free here. 49 accessors: 41 scalars + 8
    // walkers (the bead die bands; the pearl die bands
    // and spell levels; the periapt plus ladder), no name
    // collisions with miscprose1.h through miscprose18.h.
    // Pure data + helpers, header-only (the grenade.h
    // pattern).
    int mmpBeadStoneMin();
    int mmpBeadStoneMax();
    int mmpBeadSemiPreciousPct();
    int mmpBeadFancyPct();
    int mmpBeadPetitionBonusPct();
    int mmpBeadSpecialMin();
    int mmpBeadSpecialMax();
    int mmpBeadGemBaseGp();
    int mmpBeadUsesPerDay();
    int mmpBeadKarmaLevels();
    int mmpBeadSummonsPct();
    int mmpBeadRowLo(int i);
    int mmpBeadRowHi(int i);
    int mmpStrangleDamagePerRound();
    int mmpEntrapMinStrength();
    int mmpEntrapCutAc();
    int mmpEntrapSizeFeet();
    int mmpEntrapMeshQuarterFeet();
    int mmpEntrapThrowFeet();
    int mmpEntrapCloseCubeFeet();
    int mmpSnareRangeInches();
    int mmpPigPotCubicFeet();
    int mmpPigDepictSquareFeet();
    int mmpPigContainersMin();
    int mmpPigContainersMax();
    int mmpPigInstrumentFeet();
    int mmpPigDepictTurns();
    int mmpPowerRecallPerDay();
    int mmpPowerSpellsRecalled();
    int mmpPowerReverseOneIn();
    int mmpPowerDoubleMin();
    int mmpPowerDoubleMaxLevel();
    int mmpPowerDoubleDieSides();
    int mmpPowerRowLo(int i);
    int mmpPowerRowHi(int i);
    int mmpPowerSpellLevel(int i);
    int mmpWisdomGain();
    int mmpWisdomMonths();
    int mmpWisdomDays();
    int mmpWisdomReverseOneIn();
    int mmpRotAbilityLossPerWeek();
    int mmpRotStartWeek();
    int mmpRotAbilityCount();
    int mmpRotDeathScore();
    int mmpPoisonSavePctPerPlus();
    int mmpPoisonRowLo(int i);
    int mmpPoisonRowHi(int i);
    int mmpPoisonPlus(int i);
    int mmpWoundHealRateMult();

    // ---- part 20 (R276): miscmagic_phylactery_of_faithfulness_to_feather_token ----
    // Adnd1 - rules/dmg/miscmagic_phylactery_of_faithfulness_to_feather_token.h
    // R276: the III.E misc magic explanation prose part 20
    // (DMG p.153-154) - the Phylactery of Faithfulness, the
    // Phylactery of Long Years, the Phylactery of Monstrous
    // Attention, the Pipes of the Sewers, the Portable Hole
    // and Quaals Feather Token, part2 lines 971-998 (global
    // = 11065 + part2 line), pinning the kMisc4 rows 30-35 of
    // the 36-row III.E.4 table - the slice that closes the
    // table. This round has no seam: the slice starts at the
    // Faithfulness paragraph head (971 after the 970 blank)
    // and ends at the token tail (998 before the 999 blank),
    // every paragraph complete. The upload quirks this round:
    // the OCR splits three hyphenated words with a space (one-
    // quarter, re- establish and non- dimensional); the curly
    // apostrophes print in deitys, pipers, tokens and the
    // Quaals item name (the engine spells the item with the
    // straight mark); curly quotes wrap picked up, hole and to
    // hit; the foot and inch primes print as curly marks; two
    // multiplication signs ride the rat dice; the token rows
    // separate with em-dashes - all pinned as plain digits and
    // words, apostrophe-free here. The part1 quirks: the
    // Monstrous Attention row splits across two table lines
    // (part1 9851-9852, with --- in the x.p. column); the
    // Feather Token row prints both dual value pairs in the
    // x.p. column. The Phylactery of Faithfulness carries no
    // accessor (numberless prose, like the Periapt of Health
    // in part 19). 44 accessors: 42 scalars + 2 walkers (the
    // token die bands), no name collisions with miscprose1.h
    // through miscprose19.h. Pure data + helpers, header-only
    // (the grenade.h pattern).
    int mmpLongYearsSlowPct();
    int mmpLongYearsDonAge();
    int mmpLongYearsMonthsPerYear();
    int mmpLongYearsPhysicalAge();
    int mmpLongYearsChronAge();
    int mmpLongYearsReverseOneIn();
    int mmpAttentionMinLevel();
    int mmpPipeGiantRatMin();
    int mmpPipeGiantRatMax();
    int mmpPipeGiantRatPct();
    int mmpPipeNormalRatMin();
    int mmpPipeNormalRatMax();
    int mmpPipeNormalRatPct();
    int mmpPipeCallRangeInches();
    int mmpPipeDelayPerInches();
    int mmpPipeObeyPct();
    int mmpPipeReplayObeyPct();
    int mmpPipeReplayTurnPct();
    int mmpPipeTakeoverPctPerRound();
    int mmpPipeKeepPct();
    int mmpHoleDiameterFeet();
    int mmpHoleDepthFeet();
    int mmpHoleBreathTurns();
    int mmpHoleGateRadiusFeet();
    int mmpTokenUses();
    int mmpTokenRowLo(int i);
    int mmpTokenRowHi(int i);
    int mmpTokenAnchorDays();
    int mmpTokenBirdDays();
    int mmpTokenFanHours();
    int mmpTokenSwanSpeedInches();
    int mmpTokenSwanHorses();
    int mmpTokenSwanMen();
    int mmpTokenSwanDays();
    int mmpTokenTreeTrunkFeet();
    int mmpTokenTreeHeightFeet();
    int mmpTokenTreeTopFeet();
    int mmpTokenWhipPlus();
    int mmpTokenWhipLevel();
    int mmpTokenWhipDmgMin();
    int mmpTokenWhipDmgMax();
    int mmpTokenWhipBindMin();
    int mmpTokenWhipBindMax();
    int mmpTokenWhipTurns();

    // ---- part 21 (R277): miscmagic_robes ----
    // Adnd1 - rules/dmg/miscmagic_robes.h
    // R277: the III.E misc magic explanation prose part 21
    // (DMG p.153-154) - the Robe of the Archmagi, the Robe
    // of Blending, the Robe of Eyes, the Robe of Powerlessness,
    // the Robe of Scintillating Colors and the Robe of Useful
    // Items, part2 lines 1002-1052 (global = 11065 + part2
    // line), pinning the kMisc5 rows 0-5 of the 35-row III.E.5
    // table - the slice that opens the table. This round has
    // one seam: the Powerlessness paragraph splits between the
    // 1018 tail (and becomes) and the 1021 head (weak as well),
    // with the 1019-1020 pair of blanks - the p.153-154 page
    // break with no running head - seam restored here. The
    // upload quirks this round: the OCR splits two words with
    // a space (magic- user and language/ noise); the curly
    // apostrophes print in the robe and wearer possessives;
    // curly quotes wrap see, eyes and flowing; the foot and
    // inch primes print as curly marks; the 20%/minus 4
    // reduction prints the true minus sign; the coffer and
    // window rows carry one-half and multiplication signs;
    // the door and window rows separate with em-dashes - all
    // pinned as plain digits and words, apostrophe-free here.
    // The part1 quirks: the six robe rows print side-by-side
    // with armor-table columns (part1 9875-9880); the
    // Powerlessness row prints --- in the x.p. column; the
    // Scintillating row misplaces 2,750 after the (C, M)
    // marks. The useful items table flattens its two header
    // rows (Dice and Roll Result each on an own line) and
    // prints 13 die bands, pinned as the twin walkers.
    // 67 accessors: 65 scalars + 2 walkers (the useful item
    // die bands), no name collisions with miscprose1.h
    // through miscprose20.h. Pure data + helpers, header-only
    // (the grenade.h pattern).
    int mmpArchmagiWhitePct();
    int mmpArchmagiGrayPct();
    int mmpArchmagiBlackPct();
    int mmpArchmagiAcClass();
    int mmpArchmagiMagicResistPct();
    int mmpArchmagiSaveBonus();
    int mmpArchmagiPenaltyPct();
    int mmpArchmagiPenaltyMinus();
    int mmpArchmagiCharmFamilyCount();
    int mmpArchmagiClashDmgMin();
    int mmpArchmagiClashDmgMax();
    int mmpArchmagiClashDiceCount();
    int mmpArchmagiClashDiceBonus();
    int mmpArchmagiClashXpMin();
    int mmpArchmagiClashXpMax();
    int mmpArchmagiGrayDmgMin();
    int mmpArchmagiGrayDmgMax();
    int mmpArchmagiGrayXpMin();
    int mmpArchmagiGrayXpMax();
    int mmpBlendDetectRangeInches();
    int mmpBlendDetectPerIntPct();
    int mmpBlendDetectIntMin();
    int mmpBlendLevelDetectIntMin();
    int mmpBlendLevelDetectLevelMin();
    int mmpBlendDetectPerLevelPct();
    int mmpBlendExamplePct();
    int mmpEyesInfravisionInches();
    int mmpEyesSeeInvisibleInches();
    int mmpEyesSeeInfraredInches();
    int mmpEyesTrackRangerLevel();
    int mmpEyesBlindLightMin();
    int mmpEyesBlindLightMax();
    int mmpEyesBlindContinualMin();
    int mmpEyesBlindContinualMax();
    int mmpPowerlessIntelligence();
    int mmpPowerlessStrength();
    int mmpScintIntMin();
    int mmpScintWisMin();
    int mmpScintLightFeet();
    int mmpScintStartRounds();
    int mmpScintTransfixMin();
    int mmpScintTransfixMax();
    int mmpScintHitPctPerRound();
    int mmpScintHitPctMax();
    int mmpScintHitMaxRounds();
    int mmpScintCastRangeInches();
    int mmpScintHypnotizeMin();
    int mmpScintHypnotizeMax();
    int mmpUsefulDetachRounds();
    int mmpUsefulBaseEach();
    int mmpUsefulBaseCount();
    int mmpUsefulExtraMin();
    int mmpUsefulExtraMax();
    int mmpUsefulGpBag();
    int mmpUsefulCofferGp();
    int mmpUsefulGemsCount();
    int mmpUsefulGemValueGp();
    int mmpUsefulLadderFeet();
    int mmpUsefulPitCubicFeet();
    int mmpUsefulRowboatFeet();
    int mmpUsefulWindowWidthFeet();
    int mmpUsefulWindowHeightFeet();
    int mmpUsefulWindowDepthFeet();
    int mmpUsefulScrollSpells();
    int mmpUsefulWarDogsPair();
    int mmpUsefulRowLo(int i);
    int mmpUsefulRowHi(int i);

    // ---- part 22 (R278): miscmagic_rope_of_climbing_to_spade_of_colossal_excavation ----
    // Adnd1 - rules/dmg/miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.h
    // R278: the III.E misc magic explanation prose part 22
    // (DMG p.154-156) - the Rope of Climbing, the Rope of
    // Constriction, the Rope of Entanglement, the rope note,
    // the Rug of Smothering, the Rug of Welcome, the Saw of
    // Mighty Cutting, the Scarab of Death, the Scarab of
    // Enraging Enemies, the Scarab of Insanity, the Scarab of
    // Protection and the Spade of Colossal Excavation, part2
    // lines 1054-1081 (global = 11065 + part2 line), pinning
    // the kMisc5 rows 6-16 of the 35-row III.E.5 table - the
    // eleven consecutive rows opening with the Rope of
    // Climbing. This round has two seams restored: seam A
    // splits the Constriction paragraph between the 1056 tail
    // (delivers 2-12 hit) and the 1058 head (points of damage)
    // across the single 1057 blank - the p.154-155 page break,
    // no running head captured; seam B is the p.155-156 page
    // break between the Insanity tail (1074) and the Protection
    // head (1079) with the blank pair at 1075-1076, the
    // TREASURE (MISCELLANEOUS MAGIC) running head at 1077 and
    // the 1078 post-head blank. The upload quirks this round:
    // the OCR splits spade- like with a space; the curly
    // apostrophe prints in the victim possessive of the Scarab
    // of Death; curly quotes wrap to hit in the enraging mods;
    // the minus signs print true (minus 2, minus 3, minus 10
    // percent, minus 2 saves); the foot and inch primes print
    // as curly marks; the welcome rug carries a multiplication
    // sign on its 6 x 9 flying size and the 1/12 shrink
    // fraction; the rope note prints as a heading line - all
    // pinned as plain digits and words, apostrophe-free here.
    // The part1 quirks: the eleven slice rows print
    // side-by-side with armor-table columns (part1 9881-9891);
    // the Constriction, Smothering and Death rows print --- in
    // the x.p. column; the Welcome, Saw and Spade rows carry
    // the (M)/(F) marks. The Entanglement man-sized
    // equivalence chain is pinned as the lone walker.
    // 85 accessors: 84 scalars + 1 walker, no name collisions
    // with miscprose1.h through miscprose21.h. Pure data +
    // helpers, header-only (the grenade.h pattern).
    int mmpClimbLengthFeet();
    int mmpClimbWeightPounds();
    int mmpClimbSupportPounds();
    int mmpClimbSpeedFeetPerRound();
    int mmpClimbKnotIntervalFeet();
    int mmpClimbKnottedLengthFeet();
    int mmpConstrictExtraVictimsMin();
    int mmpConstrictExtraVictimsMax();
    int mmpConstrictVictimRangeFeet();
    int mmpConstrictDmgMin();
    int mmpConstrictDmgMax();
    int mmpConstrictAcClass();
    int mmpConstrictCutHitPoints();
    int mmpEntangleLashFeet();
    int mmpEntangleUpwardFeet();
    int mmpEntangleManSizedMax();
    int mmpEntangleStrikeSegments();
    int mmpEntangleEntwineSegments();
    int mmpEntangleCommandSegments();
    int mmpEntangleWholeSegments();
    int mmpEntangleAcClass();
    int mmpEntangleCutHitPoints();
    int mmpEntangleRepairTurns();
    int mmpSmotherRoundsMin();
    int mmpSmotherRoundsMax();
    int mmpSmotherBlockingSpells();
    int mmpWelcomeFlyWidthFeet();
    int mmpWelcomeFlyLengthFeet();
    int mmpWelcomeBridgeFeet();
    int mmpWelcomeBridgeWidthFeet();
    int mmpWelcomeAcClass();
    int mmpWelcomeDestroyHitPoints();
    int mmpWelcomeShrinkDivisor();
    int mmpSawLengthFeet();
    int mmpSawWidthFeet();
    int mmpSawSoloStrength();
    int mmpSawTandemStrength();
    int mmpSawTandemPersons();
    int mmpSawHardwoodFeet();
    int mmpSawHardwoodTurns();
    int mmpSawTrunkFeet();
    int mmpSawTrunkTurns();
    int mmpSawSmallDiameterFeet();
    int mmpSawSmallRounds();
    int mmpSawWorkTurns();
    int mmpSawRestTurns();
    int mmpDeathHoldRounds();
    int mmpDeathContainerFeet();
    int mmpDeathContainerTurns();
    int mmpDeathHeartRounds();
    int mmpEnrageRadiusInches();
    int mmpEnrageToHitBonus();
    int mmpEnrageDamageBonus();
    int mmpEnrageAcPenalty();
    int mmpEnrageRageMin();
    int mmpEnrageRageMax();
    int mmpEnrageChargesMin();
    int mmpEnrageChargesMax();
    int mmpInsanityRadiusInches();
    int mmpInsanitySavePenalty();
    int mmpInsanityMagicResistPenaltyPct();
    int mmpInsanityRoundsMin();
    int mmpInsanityRoundsMax();
    int mmpInsanityChargesMin();
    int mmpInsanityChargesMax();
    int mmpProtectSaveBonus();
    int mmpProtectNoSaveBase();
    int mmpProtectAbsorbCount();
    int mmpProtectReversedOneIn();
    int mmpProtectReversedPenalty();
    int mmpProtectFixedOneIn();
    int mmpProtectFixedBonus();
    int mmpProtectRemoveClericLevel();
    int mmpProtectRemovedAbsorbCount();
    int mmpSpadeLengthFeet();
    int mmpSpadeBladeWidthFeet();
    int mmpSpadeBladeLengthFeet();
    int mmpSpadeUserStrength();
    int mmpSpadeDigYardsPerRound();
    int mmpSpadeWorkRounds();
    int mmpSpadeRestRounds();
    int mmpSpadeHardPanFactor();
    int mmpSpadeGravelFactor();
    int mmpSpadeLooseSoilDivisor();
    int mmpEntangleManUnits(int i);

    // ---- part 23 (R279): miscmagic_sphere_of_annihilation_to_wings_of_flying ----
    // Adnd1 - rules/dmg/miscmagic_sphere_of_annihilation_to_wings_of_flying.h
    // R279: the III.E misc magic explanation prose part 23
    // (DMG p.156-158) - the Sphere of Annihilation, the Stone
    // of Controlling Earth Elementals, the Stone of Good Luck,
    // the Stone of Weight, the Talisman of Pure Good, the
    // Talisman of the Sphere, the Talisman of Ultimate Evil,
    // the Talisman of Zagy, the Tome of Clear Thought, the
    // Tome of Leadership and Influence, the Tome of
    // Understanding, the Trident of Fish Command, the Trident
    // of Submission, the Trident of Warning, the Trident of
    // Yearning, the Vacuous Grimoire, the Well of Many Worlds
    // and the Wings of Flying, part2 lines 1083-1149
    // (global = 11065 + part2 line), pinning the kMisc5 rows
    // 17-34 of the 35-row III.E.5 table - the closing slice:
    // rows 0-5 landed with part 21, rows 6-16 with part 22
    // and rows 17-34 here, the table complete. This round has
    // two seams restored: seam A is the p.156-157 page break
    // between the Stone of Weight tail (1108) and the
    // Talisman of Pure Good head (1113) with the blank pair
    // at 1109-1110, the TREASURE (MISCELLANEOUS MAGIC) running
    // head at 1111 and the 1112 post-head blank; seam B
    // splits the Fish Command paragraph between the 1127 tail
    // (but they will not) and the 1129 head (approach closer
    // than 10 feet of the trident) across the single 1128
    // blank - the p.157-158 page break, no running head
    // captured. The upload quirks this round: the foot and
    // inch primes print as curly marks; curly quotes wrap to
    // hit on the luckstone; curly apostrophes print
    // throughout; the minus sign prints true on the Yearning
    // cursed weapon; the plus-minus sign prints on the
    // luckstone 1 to 10 percent range; a multiplication sign
    // prints in the cancellation 3d4 x 10 damage; the OCR
    // splits Non- clerics and largest/ deepest with spaces;
    // the sphere control table prints as a nine-row level
    // grid; the wings durations print as a bare three-line
    // list - all pinned as plain digits and words,
    // apostrophe-free here. The part1 quirks: the eighteen
    // slice rows print side-by-side with armor-table columns
    // (part1 9892-9910); the Earth Elementals row wraps its
    // name across two lines; the Loadstone, Yearning and
    // Vacuous rows print --- in the x.p. column; the Sphere
    // and its Talisman carry the (M) marks, the Pure Good
    // and Ultimate Evil the (C) marks, the command/warning
    // Tridents the (C, F, T) marks and the Submission the
    // lone (F). The sphere control grid and the wings
    // duration list are pinned as the walkers.
    // 110 accessors: 104 scalars + 6 walkers, no name
    // collisions with miscprose1.h through miscprose22.h.
    // Pure data + helpers, header-only (the grenade.h
    // pattern).
    int mmpSphereDiameterFeet();
    int mmpSphereControlRangeFeet();
    int mmpSphereControlPerLevelInches();
    int mmpSphereBaseMoveFeetPerRound();
    int mmpSphereIntBonusLowPct();
    int mmpSphereIntBonusHighPct();
    int mmpSphereIntBonusMaxPct();
    int mmpSphereIntBonusLowStat();
    int mmpSphereIntBonusHighStat();
    int mmpSphereIntBonusMaxStat();
    int mmpSphereDriftRoundsMin();
    int mmpSphereDriftRoundsMax();
    int mmpSphereDriftRangeFeet();
    int mmpSphereMultiUserPenaltyPct();
    int mmpSphereGateDestroyPct();
    int mmpSphereGateNothingPct();
    int mmpSphereGateTearPct();
    int mmpSphereGateTearRadiusInches();
    int mmpSphereCancelRadiusInches();
    int mmpSphereCancelDmgMin();
    int mmpSphereCancelDmgMax();
    int mmpSphereCtlRows();
    int mmpSphereCtlLevelLo(int i);
    int mmpSphereCtlLevelHi(int i);
    int mmpSphereCtlMoveFeet(int i);
    int mmpSphereCtlProbPct(int i);
    int mmpEarthStoneEarthDice();
    int mmpEarthStoneRoughDice();
    int mmpEarthStoneWorkedStoneDice();
    int mmpEarthStoneAreaFeet();
    int mmpEarthStoneVolumeYards();
    int mmpEarthStoneRoundsMin();
    int mmpEarthStoneRoundsMax();
    int mmpEarthStonePerDay();
    int mmpLuckSaveBonus();
    int mmpLuckSavePctBonus();
    int mmpLuckItemPctMin();
    int mmpLuckItemPctMax();
    int mmpLoadMoveReductionPct();
    int mmpLoadAttackReductionPct();
    int mmpLoadDispelClears();
    int mmpPureGoodCharges();
    int mmpPureGoodRechargeable();
    int mmpPureGoodNeutralDmgMin();
    int mmpPureGoodNeutralDmgMax();
    int mmpPureGoodEvilDmgMin();
    int mmpPureGoodEvilDmgMax();
    int mmpPureGoodNonClericDmg();
    int mmpSphereTaliNonMuDmgMin();
    int mmpSphereTaliNonMuDmgMax();
    int mmpSphereTaliLowPctPerPoint();
    int mmpSphereTaliHighPctPerPoint();
    int mmpSphereTaliCheckIntervalRounds();
    int mmpSphereTaliMaxMoveFeet();
    int mmpSphereWandNegationOnTalisman();
    int mmpSphereWandNegationOnSphere();
    int mmpUltimateEvilCharges();
    int mmpZagyHostileDmgMin();
    int mmpZagyHostileDmgMax();
    int mmpZagyNeutralHoursMin();
    int mmpZagyNeutralHoursMax();
    int mmpZagyFriendlyMonthsPerChaPoint();
    int mmpZagyWishChaDivisor();
    int mmpZagyTrapRangeFeet();
    int mmpZagyDiamondGp();
    int mmpClearThoughtIntGain();
    int mmpClearThoughtReadHours();
    int mmpClearThoughtReadDays();
    int mmpClearThoughtStartWeeks();
    int mmpClearThoughtGainMonths();
    int mmpClearThoughtRereadGain();
    int mmpLeadershipChaGain();
    int mmpUnderstandingWisGain();
    int mmpFishCmdRadiusInches();
    int mmpFishCmdChargeCost();
    int mmpFishCmdProtectFeet();
    int mmpFishCmdApproachFeet();
    int mmpFishCmdSchoolsAsOne();
    int mmpFishCmdChargesMin();
    int mmpFishCmdChargesMax();
    int mmpFishCmdMagicBonus();
    int mmpSubmitMoraleDelayRounds();
    int mmpSubmitHopelessRoundsMin();
    int mmpSubmitHopelessRoundsMax();
    int mmpSubmitChargesMin();
    int mmpSubmitChargesMax();
    int mmpSubmitMagicBonus();
    int mmpWarningRadiusInches();
    int mmpWarningScanRounds();
    int mmpWarningChargesMin();
    int mmpWarningChargesMax();
    int mmpWarningChargeRounds();
    int mmpWarningMagicBonus();
    int mmpYearningMagicPenalty();
    int mmpYearningFreeingSpells();
    int mmpYearningGrantsWaterBreathing();
    int mmpVacuousSaveCount();
    int mmpVacuousIntLoss();
    int mmpVacuousWisLoss();
    int mmpVacuousBurnAfterRemoveCurse();
    int mmpWellTwoWay();
    int mmpWingsSpanFeet();
    int mmpWingsRestHours();
    int mmpWingsQuietHours();
    int mmpWingsNoRestTurns();
    int mmpWingsUsesPerDay();
    int mmpWingsSupportPounds();
    int mmpWingsSpeedRows();
    int mmpWingsSpeedTurns(int i);
    int mmpWingsSpeedInches(int i);
};
