// ====================================================================
// Adnd1 - rules/dmg/specart_axe_of_the_dwarvish_lords_to_codex.h
// R281: the III.E Special artifacts explanation
// prose part 2 (DMG p.159-160) - the Axe of the
// Dwarvish Lords, the Baba Yaga Hut and the Codex
// of the Infinite Planes, part2 lines 1184-1235
// (global = 11065 + part2 line), the first three
// of the 29 artifact descriptions. The Axe pins:
// the blade equals a sword of sharpness; the head
// equals a +3 hammer; the handle extends or
// contracts on command to equal a battle or hand
// axe for throwing; the Axe returns 30 feet to its
// thrower; the possessor has dwarven abilities,
// doubled for a dwarf; the life span is 50 percent
// longer; the Axe supposedly bears a curse and was
// lost in the Invoked Devastation; powers 2 of
// table I and 1 each of tables II through VI. The
// Hut pins: 15 feet diameter, 10 feet high; two
// fowl legs 12 feet long; infravision 120 feet;
// 30 rooms on 3 floors; movement 48 inches over
// swamp, 36 over rough or normal terrain and 12
// over hills; obeys commands from 1 key-phrase
// commander; comes to a call from 1 league; the
// legs strike as a hill giant, 2 attacks per
// round, armor class 2, 48 hit points each,
// regenerating 1 per round; 5 foot granite walls;
// powers 4 of table I, 2 of table II, 1 each of
// III through VI. The Codex pins: 99 damned
// pages; 99 percent certain doom at 1 percent
// cumulative per page; keys to instant
// transference to any plane; destroys any
// character under 11th level on touch; 11th or
// higher save versus magic to command; powers 4
// each of tables I and II, 2 each of III through
// VI; the powers activate per the progress of the
// perusal. This round has one seam restored: the
// p.159-160 page break splits the Codex paragraph
// between the 1216 tail (the work will destroy
// instantly any) and the 1221 head (character
// under 11th level) across the blank pair at
// 1217-1218, the TREASURE (ARTIFACTS & RELICS)
// running head at 1219 and the 1220 post-head
// blank. The upload quirks this round: the power
// lines print the counts as N x table with the
// true multiplication sign, 18 of them; the feet
// primes print as the curly right single quote
// and the inch primes as the curly right double
// quote; the Tzunk fragment prints curly quotes;
// the hit point/ melee round slash split carries
// a space - all pinned as plain digits and words,
// apostrophe-free here. 37 accessors: 33 scalars
// + 4 walkers (the three power-count walkers -
// 2,1,1,1,1,1 for the Axe, 4,2,1,1,1,1 for the
// Hut, 4,4,2,2,2,2 for the Codex - and the hut
// move walker 48, 36, 12), no name collisions
// with the miscprose and specart headers. The
// audit cross-pins the R240 sale table rows: the
// Axe band 01 at 55000, the Hut band 02 at
// 90000, the Codex band 03-04 at 62500. Pure
// data + helpers, header-only (the grenade.h
// pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Specart_axe_of_the_dwarvish_lords_to_codex (instance methods)
class Specart_axe_of_the_dwarvish_lords_to_codex {
public:
    int sapAxeBladeSharpness();
    int sapAxeHammerBonus();
    int sapAxeHandleForms();
    int sapAxeReturnFeet();
    int sapAxeDwarfAbilityMultiplier();
    int sapAxeLifespanBonusPct();
    int sapAxeBearsCurse();
    int sapAxeInvokedDevastationLost();
    int sapAxePowerTotal();
    int sapAxePowerCount(int i);
    int sapHutDiameterFeet();
    int sapHutHeightFeet();
    int sapHutLegCount();
    int sapHutLegLengthFeet();
    int sapHutInfravisionFeet();
    int sapHutRoomCount();
    int sapHutFloorCount();
    int sapHutMoveTerrainCount();
    int sapHutMoveInches(int i);
    int sapHutCommanderCount();
    int sapHutCallRangeLeagues();
    int sapHutLegAttacksPerRound();
    int sapHutLegArmorClass();
    int sapHutLegHpEach();
    int sapHutLegRegenPerRound();
    int sapHutWallGraniteFeet();
    int sapHutLegsHillGiantBlows();
    int sapHutPowerTotal();
    int sapHutPowerCount(int i);
    int sapCodexDamnedPages();
    int sapCodexDoomChancePct();
    int sapCodexPerilPerPagePct();
    int sapCodexTouchKillBelowLevel();
    int sapCodexCommandMinLevel();
    int sapCodexPerusalActivation();
    int sapCodexPowerTotal();
    int sapCodexPowerCount(int i);
    int sapCrownRegaliaSetCount();
    int sapCrownItemsPerSet();
    int sapCrownChampionEthosCount();
    int sapCrownPossessionBenefits();
    int sapCrownWrongEthosDamageMin();
    int sapCrownWrongEthosDamageMax();
    int sapCrownWrongEthosSaveOrDeath();
    int sapCrownWearerLevelBonus();
    int sapCrownWornPowerTotal();
    int sapCrownOffEthosMalevolentCount();
    int sapCrownOffEthosMalevolentTable();
    int sapCrownSet2ndPowerTotal();
    int sapCrownSet3rdPowerTotal();
    int sapCrownDetectionRevealsAlignment();
    int sapCrownGemCount();
    int sapCrownSaleGpMin();
    int sapCrownAlignBandLo(int i);
    int sapCrownAlignBandHi(int i);
    int sapCrownWornPowerCount(int i);
    int sapCrownSet2ndPowerCount(int i);
    int sapCrownSet3rdPowerCount(int i);
    int sapCrystalOriginUnknown();
    int sapCrystalDiamondHard();
    int sapCrystalTouchRaysBlackFlame();
    int sapCrystalCharmRadiusFeet();
    int sapCrystalCharmIsFireCharm();
    int sapCrystalPowersByGazing();
    int sapCrystalPowerTotal();
    int sapCrystalPowerCount(int i);
    int sapCupTalismanRelicCount();
    int sapCupTalismanPaynimGift();
    int sapCupTalismanInvokedDevastationEra();
    int sapCupTalismanLostToRaiders();
    int sapCupTalismanPotionClassCount();
    int sapCupTalismanPotionPerWeek();
    int sapCupGemCount();
    int sapCupJewelryGpMin();
    int sapCupRadiatesMagic();
    int sapCupPowerTotal();
    int sapCupPowerCount(int i);
    int sapTalismanPointCount();
    int sapTalismanPointGemCount();
    int sapTalismanBeadSetCount();
    int sapTalismanBeadsPerSet();
    int sapTalismanJewelryGpMin();
    int sapTalismanRadiatesMagic();
    int sapTalismanPowerTotal();
    int sapTalismanPowerCount(int i);
    int sapCupTalismanBothPowerTotal();
    int sapCupTalismanBothPowerCount(int i);
    int sapCupTalismanPotionBandCount();
    int sapCupTalismanPotionBandLo(int i);
    int sapCupTalismanPotionBandHi(int i);
    int sapEyeVecnaPhantomRoams();
    int sapEyeDoomSurvivors();
    int sapEyeFeralGlow();
    int sapEyeAppearsAgate();
    int sapEyeGraftIrrevocable();
    int sapEyeHostNeutralEvil();
    int sapEyeGrantsInfravision();
    int sapEyeGrantsUltravision();
    int sapEyePowerTotal();
    int sapEyePowerCount(int i);
    int sapEyePrimaryPowerMalevolent();
    int sapHandVecnaLeftHand();
    int sapHandMummifiedExtremity();
    int sapHandGripStrength();
    int sapHandGripStrengthRating();
    int sapHandGripHitOrDamageBonus();
    int sapHandHostTurnsNeutralEvil();
    int sapHandMajorPowerWakesSpirit();
    int sapHandPrimaryPowerInstantEvil();
    int sapHandSeverBaseChancePct();
    int sapHandSeverMajorPenaltyPct();
    int sapHandSeverPrimaryPenaltyPct();
    int sapHandNoRemovalAtLimit();
    int sapHandFingerCombinations();
    int sapHandPowerTotal();
    int sapHandPowerCount(int i);
    int sapHandGodsOnlyAlteration();
    int sapHandRecordCombinations();
    int sapOrganPipeCount();
    int sapOrganStopCount();
    int sapOrganPedalCount();
    int sapOrganBellowsElemental();
    int sapOrganStopsVaryVoice();
    int sapOrganKeysVaryNotes();
    int sapOrganPedalPurposeUnknown();
    int sapOrganStillWorksDespiteTime();
    int sapOrganWrongStopsSummon();
    int sapOrganWrongKeysBackfire();
    int sapOrganMisplayAlignment();
    int sapOrganDmAssignsStopsKeys();
    int sapOrganPowerTotal();
    int sapOrganMisplayNegates();
    int sapHornResemblesCommonHorns();
    int sapHornSuggestedPowerPct();
    int sapHornSuggestedEffectPct();
    int sapHornIgnoresInappropriate();
    int sapCoatArndOfTdon();
    int sapCoatChainLinksWeightless();
    int sapCoatCoveredAreaCount();
    int sapCoatMinWearerHeightFt();
    int sapCoatMaxWearerHeightFt();
    int sapCoatInvulnerableCovered();
    int sapCoatUncoveredAc();
    int sapCoatSaveBonus();
    int sapCoatFireResistance();
    int sapCoatElementalImmunityCount();
    int sapCoatPowerTotal();
    int sapOrganPowerCount(int i);
    int sapHornBlastPowerTable(int i);
    int sapHornBlastEffectTable(int i);
    int sapCoatPowerCount(int i);
    int sapFlaskHeavyUrn();
    int sapFlaskTurnipPlug();
    int sapFlaskSigilRunes();
    int sapFlaskWordCount();
    int sapFlaskPrisonerCount();
    int sapFlaskServantEvilOnly();
    int sapFlaskKillBeforeReturn();
    int sapFlaskPowerTotal();
    int sapJacinthGodFashioned();
    int sapJacinthMountainHeart();
    int sapJacinthFacetedBeams();
    int sapJacinthCharmRangeFt();
    int sapJacinthSultanPossessed();
    int sapJacinthKeolandTrailLost();
    int sapJacinthGraspPowers();
    int sapJacinthPowerTotal();
    int sapMaskJohydeeTrickedEvil();
    int sapMaskOverthrewNation();
    int sapMaskCoversFace();
    int sapMaskAssumeLikeness();
    int sapMaskBlocksMindContact();
    int sapMaskGazeImmunity();
    int sapMaskGazeCreatureCount();
    int sapMaskPowerTotal();
    int sapFlaskPowerCount(int i);
    int sapJacinthPowerCount(int i);
    int sapMaskPowerCount(int i);
    int sapQuillMasterThiefBest();
    int sapQuillUnknownAntiquity();
    int sapQuillBearsKurothName();
    int sapQuillInfallibleScribe();
    int sapQuillDepictsSeenSpoken();
    int sapQuillPotionTreasureFinding();
    int sapQuillTreasureFindPerMonth();
    int sapQuillPowerTotal();
    int sapQuillPowerCount(int i);
    int sapMaceSaintCuthbertWeapon();
    int sapMaceFollyOfError();
    int sapMaceRelicsEncased();
    int sapMaceHitDamageBonus();
    int sapMaceDisruptionEffects();
    int sapMaceClericStrReq();
    int sapMaceLawfulGoodOnly();
    int sapMacePowerTotal();
    int sapMacePowerCount(int i);
    int sapMachineGodsForgotten();
    int sapMachineWorkmanshipUnknown();
    int sapMachineBaronLumEmpire();
    int sapMachineLeverCount();
    int sapMachineDialCount();
    int sapMachineSwitchCount();
    int sapMachineControlsTotal();
    int sapMachineHalfFunction();
    int sapMachineWeightLb();
    int sapMachineJoltDestroyMax();
    int sapMachineBoothCreatures();
    int sapMachinePowerTotal();
    int sapMachinePowerCount(int i);
    int sapServantLumSameMake();
    int sapServantAutomatonHeightFt();
    int sapServantDepthFt();
    int sapServantWidthFt();
    int sapServantInsideRiders();
    int sapServantOutsideSittersMin();
    int sapServantCommandPhrases();
    int sapServantUseCount();
    int sapServantArmorClass();
    int sapServantHitPoints();
    int sapServantWeaponDamagePct();
    int sapServantRegenPerRound();
    int sapServantMagicResistPct();
    int sapServantElementImmuneCount();
    int sapServantElectricalDamagePct();
    int sapServantSpeedInches();
    int sapServantOperationHours();
    int sapServantRestHours();
    int sapServantPanicRangeInches();
    int sapServantPanicSaveBonus();
    int sapServantAttacksPerRound();
    int sapServantBaseHitPct();
    int sapServantDexReduceFloor();
    int sapServantDexReducePct();
    int sapServantDamageLowHp();
    int sapServantDamageHighHp();
    int sapServantObeysSecretLearners();
    int sapServantPowerTotal();
    int sapServantPowerCount(int i);
    int sapOrbGoodDeitiesOrigin();
    int sapOrbDemonsCorrupted();
    int sapOrbGlobeCount();
    int sapOrbOnePerAge();
    int sapOrbSmallestInches();
    int sapOrbLargestInches();
    int sapOrbBasReliefCovered();
    int sapOrbDragonEssence();
    int sapOrbHatchlingIntelligence();
    int sapOrbHatchlingEgo();
    int sapOrbHatchlingPowerTotal();
    int sapOrbHatchlingPowerCount(int i);
    int sapOrbWyrmkinIntelligence();
    int sapOrbWyrmkinEgo();
    int sapOrbWyrmkinPowerTotal();
    int sapOrbWyrmkinPowerCount(int i);
    int sapOrbDragonetteIntelligence();
    int sapOrbDragonetteEgo();
    int sapOrbDragonettePowerTotal();
    int sapOrbDragonettePowerCount(int i);
    int sapOrbDragonIntelligence();
    int sapOrbDragonEgo();
    int sapOrbDragonPowerTotal();
    int sapOrbDragonPowerCount(int i);
    int sapOrbGreatSerpentIntelligence();
    int sapOrbGreatSerpentEgo();
    int sapOrbGreatSerpentPowerTotal();
    int sapOrbGreatSerpentPowerCount(int i);
    int sapOrbFiredrakeOldDragon();
    int sapOrbFiredrakeIntelligence();
    int sapOrbFiredrakeEgo();
    int sapOrbFiredrakePowerTotal();
    int sapOrbFiredrakePowerCount(int i);
    int sapOrbElderWyrmVeryOldDragon();
    int sapOrbElderWyrmIntelligence();
    int sapOrbElderWyrmEgo();
    int sapOrbElderWyrmPowerTotal();
    int sapOrbElderWyrmPowerCount(int i);
    int sapOrbEternalAncientDragon();
    int sapOrbEternalTiamatBahamutBonus();
    int sapOrbEternalIntelligence();
    int sapOrbEternalEgo();
    int sapOrbEternalPowerTotal();
    int sapOrbEternalPowerCount(int i);
    int sapOrbNotesEvilComponent();
    int sapOrbNotesNeutralGoodResist();
    int sapOrbNotesCharmRangeInches();
    int sapOrbNotesCharmRounds();
    int sapOrbNotesAwakeAndAware();
    int sapOrbNotesEvilAutoCharmed();
    int sapOrbNotesNeutralSavePenalty();
    int sapOrbNotesGoodSavePenalty();
    int sapOrbNotesCharmedWisdomPercent();
    int sapOrbNotesFeeblemindIntelligence();
    int sapOrbNotesInsanePercent();
    int sapOrbNotesAwakeMindOnly();
    int sapOrbNotesSacrificeDestruction();
    int sapOrbMightOrbCount();
    int sapOrbMightCrownSource();
    int sapOrbMightEvilDieLo();
    int sapOrbMightEvilDieHi();
    int sapOrbMightGoodDieLo();
    int sapOrbMightGoodDieHi();
    int sapOrbMightNeutralDieLo();
    int sapOrbMightNeutralDieHi();
    int sapOrbMightTouchDeathSave();
    int sapOrbMightTouchDamageLo();
    int sapOrbMightTouchDamageHi();
    int sapOrbMightRegaliaTableFour();
    int sapOrbMightPlatinumGems();
    int sapOrbMightValueGp();
    int sapOrbMightGemOfBrightness();
    int sapOrbMightPowerEthosCount();
    int sapOrbMightPowerTotal();
    int sapOrbMightPowerCount(int i);
    int sapOrbMightRegaliaPowers();
    int sapNightingaleMadeByXagy();
    int sapNightingaleJoramyCoMaker();
    int sapNightingaleMadeCenturiesAgo();
    int sapNightingaleEhlissaBentAll();
    int sapNightingaleNeverEscaped();
    int sapNightingaleGoldenWireCage();
    int sapNightingaleWingsPerchPerform();
    int sapNightingaleEyeRays();
    int sapNightingaleSongWonders();
    int sapNightingaleRaySongSpells();
    int sapNightingaleSphereRadiusFeet();
    int sapNightingaleSphereBlocksScrying();
    int sapNightingaleNoHungerThirst();
    int sapNightingalePowerTotal();
    int sapNightingalePowerCount(int i);
    int sapRecorderNeedsNoMusician();
    int sapRecorderPlaysOnCommand();
    int sapRecorderAlarmRadiusFeet();
    int sapRecorderAlarmIncludesSelf();
    int sapRecorderClueWordSongs();
    int sapRecorderRumoredSpells();
    int sapRecorderPowerTotal();
    int sapRecorderPowerCount(int i);
    int sapGaxxAlienOrigin();
    int sapGaxxPlatinumLoopSpinel();
    int sapGaxxUnknownGemType();
    int sapGaxxFingerDiscovery();
    int sapGaxxFacetCount();
    int sapGaxxFacingToTop();
    int sapGaxxTurnsItself();
    int sapGaxxDailyRandomFacet();
    int sapGaxxFacetOrderKnown();
    int sapGaxxCannotBeMarked();
    int sapGaxxPowerTotal();
    int sapGaxxPowerCount(int i);
    int sapRodWindDukesMadeIt();
    int sapRodMadeForBattleOfPesh();
    int sapRodPeshChaosVersusLaw();
    int sapRodShatteredAtPesh();
    int sapRodNothingDestroysIt();
    int sapRodCorrectOrderSurpassingPower();
    int sapRodPartCount();
    int sapRodPartsSlightlyDifferent();
    int sapRodFirstLargestLengthDiameter();
    int sapRodSeventhSmallest();
    int sapRodNoAlonePower();
    int sapRodPartsLookLikeBatons();
    int sapRodSeventhLooksLikeWand();
    int sapRodFirstSensesSecond();
    int sapRodSensingNeedsWholeThought();
    int sapRodLeadsOnlyUpward();
    int sapRodOutOfOrderTouchTeleports();
    int sapRodTeleportMinMiles();
    int sapRodTeleportMaxMiles();
    int sapRodAssembledLengthFeet();
    int sapRodThreeSectionsGripLock();
    int sapRodPartPowersCumulative();
    int sapRodFullPowersNeedAllParts();
    int sapRodCannotBeDisassembled();
    int sapRodPrimeRiskDenominator();
    int sapRodPrimeRiskPercent();
    int sapRodBreakupTeleportMinMiles();
    int sapRodBreakupTeleportMaxMiles();
    int sapRodOutOfOrderNotCumulative();
    int sapRodLastPieceJoinedActive();
    int sapRodInOrderCumulative();
    int sapRodAssemblyRowCount();
    int sapRodAssemblyUseTotal();
    int sapRodCompleteUseTotal();
    int sapRodCompleteOrderQuirk();
    int sapRodCompleteLacksTableVI();
    int sapRodBlankSlotCount();
    int sapRodBlankSlotUnderscores();
    int sapRodJointTable(int i);
    int sapRodJointUseCount(int i);
    int sapRodCompleteTableUse(int i);
    int sapSceptreCount();
    int sapSceptreSourceCrownOfMight();
    int sapSceptreEvilBandLo();
    int sapSceptreEvilBandHi();
    int sapSceptreGoodBandLo();
    int sapSceptreGoodBandHi();
    int sapSceptreNeutralBandLo();
    int sapSceptreNeutralBandHi();
    int sapSceptreForeignEthosCrownEffects();
    int sapSceptreBronzeInlaidSilver();
    int sapSceptreHugeStoneTipping();
    int sapSceptreLengthFeet();
    int sapSceptreValueGp();
    int sapSceptreRodOfBeguiling();
    int sapSceptreUseTotal();
    int sapSceptreCrownOrbComboNote();
    int sapSceptreBlankSlotCount();
    int sapSceptreTableUse(int i);
    int sapKasOfVecnaTheLich();
    int sapKasBodyguardRightHand();
    int sapKasFlatchetDullGrayMetal();
    int sapKasSharpPointKeenEdges();
    int sapKasServedFaithfully();
    int sapKasHubrisGrew();
    int sapKasSwordUrgedHimOn();
    int sapKasGreaterThanVecna();
    int sapKasCouldRuleInVecnaStead();
    int sapKasDestroyedVecna();
    int sapKasDoomWroughtTogether();
    int sapKasWorldBrighter();
    int sapKasPowersOnlyHinted();
    int sapKasRenownedSwordsman();
    int sapKasPlusBonus();
    int sapKasDefender();
    int sapKasDoubleDamageOffPlane();
    int sapKasNormalDamageOnOtherPlanes();
    int sapKasShortSword();
    int sapKasEvilChaoticAlignment();
    int sapKasIntelligence();
    int sapKasEgo();
    int sapKasTriesToControl();
    int sapKasUseTotal();
    int sapKasBlankSlotCount();
    int sapKasPrintsInOrder();
    int sapKasTableUse(int i);
    int sapToothHistoriesSilent();
    int sapToothGodsGavePowers();
    int sapToothRelicsAreTeeth();
    int sapToothEachToothHasPower();
    int sapToothCount();
    int sapToothBenefitLevels();
    int sapToothQuarterCount();
    int sapToothHalfCount();
    int sapToothGraftsInMouth();
    int sapToothLikeMissingTooth();
    int sapToothNeverRemoved();
    int sapToothRemovalOnlyByDemise();
    int sapToothPowersCumulative();
    int sapToothUseTotal();
    int sapToothTableOneCount();
    int sapToothTableTwoCount();
    int sapToothTableThreeCount();
    int sapToothTableFourCount();
    int sapToothTableFiveCount();
    int sapToothTableSixCount();
    int sapToothLoneFourTooth();
    int sapToothFirstSixTooth();
    int sapToothSecondSixTooth();
    int sapToothUnderscoreRunLen();
    int sapToothBlankSlotCount();
    int sapToothXSignCount();
    int sapToothSetPairRows();
    int sapToothSetQuarterRows();
    int sapToothSetHalfRepeatQuarters();
    int sapToothSetFiveRows();
    int sapToothSetLeftTwoCount();
    int sapToothSetLeftFiveCount();
    int sapToothSetRightThreeCount();
    int sapToothSetRightFourCount();
    int sapToothSetRightSixCount();
    int sapToothTableUse(int i);
    int sapToothSetRightUse(int i);
    int sapThroneCarvenMountainHeart();
    int sapThroneMassiveStoneChair();
    int sapThroneMosaicsIvoryMetals();
    int sapThroneSetAboutGems();
    int sapThroneGodsActuallySat();
    int sapThroneWithinGreatCavern();
    int sapThroneImmobileImmovable();
    int sapThroneAffectsAnyoneSeated();
    int sapThroneCertainMagicItem();
    int sapThroneMalevolentEffectToo();
    int sapThroneItemGainOnlyOnce();
    int sapThroneProperWordsGestures();
    int sapThroneGraspOptions();
    int sapThroneUseTotal();
    int sapThroneTableOneCount();
    int sapThroneTableTwoCount();
    int sapThroneTableThreeCount();
    int sapThroneTableFourCount();
    int sapThroneTableFiveCount();
    int sapThroneTableSixCount();
    int sapThroneBlankSlotCount();
    int sapThroneXSignCount();
    int sapThroneBulletLineCount();
    int sapThroneTableUse(int i);
    int sapWandDemonPrinceProperty();
    int sapWandPassesToPrimeMaterial();
    int sapWandWreakChaosEvil();
    int sapWandMonsterManualRef();
    int sapWandSavingThrowVersusMagic();
    int sapWandAvoidsDeathAnnihilation();
    int sapWandImmuneCount();
    int sapWandUseTotal();
    int sapWandTableOneCount();
    int sapWandTableTwoCount();
    int sapWandTableThreeCount();
    int sapWandTableFourCount();
    int sapWandTableFiveCount();
    int sapWandTableSixCount();
    int sapWandBlankSlotCount();
    int sapWandXSignCount();
    int sapWandBulletLineCount();
    int sapWandFourOneSpaceSeparator();
    int sapWandFourOneCommaCount();
    int sapWandTableUse(int i);
    int sapFinalXSignCount();
    int sapFinalBlankRunCount();
    int sapFinalUnderscoreRunLen();
    int sapFinalCurlyApostropheCount();
    int sapFinalEmDashCount();
    int sapFinalPageSeamLine();
    int sapFinalSpecialDescriptionCount();
};
