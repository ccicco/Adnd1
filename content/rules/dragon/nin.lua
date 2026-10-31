-- nin: promoted from tools/spec_r929.json (the The Dragon issue-16 opener - the Near Eastern Mythos (print 4-6) and the Ninja, the ultimate NPC (print 7-10): the two-chain round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 929,
  "prefix" = "nin",
  "banner" = {
      "title" = "The Dragon issue-16 opener - the Near Eastern Mythos (print 4-6) and the Ninja, the ultimate NPC (print 7-10): the two-chain round",
      "provenance" = "Pinned from The Dragon Vol. III No. 2 (July 1978), the Curtiss-provided scan voice (single-voice: the issue-16 source is the uploaded Dm16.pdf with its mistral-ocr transcript; no archive.org djvu cross-check exists for issue 16). PRINT FOLIO = PDF PAGE MINUS TWO in this issue, verified at the page feet (folios 4, 7, 10, 16, 18, 22 and 36 print at the PDF pages 6, 9, 12, 18, 20, 24 and 38) plus the TOC alignments (the Ninja at print 7 = PDF 9, the Green Magician part two at print 25 = PDF 27, Game Balance at print 36 = PDF 38). The transcripts ride extract/dragon/016/p001 through p040, landed this round; the article CHAIN is the ink unit, not the folio.",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: no full-res visual check exists for this issue (the scan is a text-side transcript, no page renders), so garbled cells pin sentinel, never guessed - the Enkidu strength prints 1895 and the Aqht strength 1875, the 18-slash-percentile garble class, both pin sentinel; the as-a-normal-man armor classes (Enkidu, King Krt, King Dn-il, Aqht, the Maiden) pin sentinel; the see-below deity magic cells pin sentinel with the spell lists riding the transcript; the assassination hiring column prints 1006, 1518 and 2012 K at levels 14-16 against the 1, 2, 4 ... 512 doubling pattern, pinned as scanned, never corrected to the doubling; the assassination grid header prints eleven victim bands but each row prints ten percent values, the columns pin in PRINTED ORDER with the band alignment riding the transcript, the bullet cells pin sentinel; the thieving hide-in-shadows column prints 70 at level 4 and 60 at level 5 against the +5 drift, as scanned; the row-12 sixth-column 99, the row-13 sixth-column 110 and the row-15 eighth-column 99 prints pin as scanned; the hit-dice column (1D4 through 8D12+2D4), the disguise-class weapon rosters and the weapons-effects damage grid ride the transcript, the table pinning the uniform columns.",
    },
  "consts" = { {
      "name" = "ninGodRows",
      "value" = 16,
      "comment" = "the sixteen full stat-block deities of the pantheon (folio 4-5, PDF 6-7)",
    }, {
      "name" = "ninEnlilChariotHorsesMoveFeet",
      "value" = 36,
      "comment" = "the Enlil-Marduk-Baal chariot horses move 36 feet (folio 4, PDF 6)",
    }, {
      "name" = "ninEnlilArrowsOfSlaying",
      "value" = 30,
      "comment" = "Enlil carries 30 arrows of slaying plus the magic bow (folio 4, PDF 6)",
    }, {
      "name" = "ninEnlilDaggerPlus",
      "value" = 3,
      "comment" = "the Enlil dagger +3, effective vs chaotic creatures only (folio 4, PDF 6)",
    }, {
      "name" = "ninHeroRows",
      "value" = 8,
      "comment" = "the eight heroes and kings with full stat blocks (folio 5, PDF 7)",
    }, {
      "name" = "ninCreatureRows",
      "value" = 2,
      "comment" = "the two full stat-block monsters, Humbaba and the scorpion men (folios 5-6, PDF 7-8)",
    }, {
      "name" = "ninOtherDeities",
      "value" = 20,
      "comment" = "the twenty one-line other deities listed at folio 6 (PDF 8)",
    }, {
      "name" = "ninAxeMightPlus",
      "value" = 3,
      "comment" = "the Axe Might of Heroes: +3 hit probability (folio 6, PDF 8)",
    }, {
      "name" = "ninAxeMightDamageMin",
      "value" = 2,
      "comment" = "the Axe Might of Heroes does 2-16 damage (folio 6, PDF 8)",
    }, {
      "name" = "ninAxeMightDamageMax",
      "value" = 16,
      "comment" = "the Axe Might of Heroes damage upper bound (folio 6, PDF 8)",
    }, {
      "name" = "ninBowOfAnshanPlus",
      "value" = 3,
      "comment" = "the Bow of Anshan: all arrows +3 to hit (folio 6, PDF 8)",
    }, {
      "name" = "ninBreastplateArmorBonus",
      "value" = 5,
      "comment" = "the Breastplate Voice of Heroes acts as armor +5 (folio 6, PDF 8)",
    }, {
      "name" = "ninBreastplateShekels",
      "value" = 30,
      "comment" = "the Breastplate Voice of Heroes weighs 30 shekels (folio 6, PDF 8)",
    }, {
      "name" = "ninMaceDriverPlus",
      "value" = 3,
      "comment" = "the Mace Driver: +3 hit vs Lotan only (folio 6, PDF 8)",
    }, {
      "name" = "ninMaceDriverDamageMin",
      "value" = 3,
      "comment" = "the Mace Driver does 3-18 damage (folio 6, PDF 8)",
    }, {
      "name" = "ninMaceDriverDamageMax",
      "value" = 18,
      "comment" = "the Mace Driver damage upper bound (folio 6, PDF 8)",
    }, {
      "name" = "ninMaceExpellerPlus",
      "value" = 3,
      "comment" = "the Mace Expeller: +3 hit vs Yamm only (folio 6, PDF 8)",
    }, {
      "name" = "ninMaceExpellerDamageMin",
      "value" = 3,
      "comment" = "the Mace Expeller does 3-18 damage (folio 6, PDF 8)",
    }, {
      "name" = "ninMaceExpellerDamageMax",
      "value" = 18,
      "comment" = "the Mace Expeller damage upper bound (folio 6, PDF 8)",
    }, {
      "name" = "ninLevelCap",
      "value" = 16,
      "comment" = "no ninja may be higher than 16th level, any ninja may advance to that level (folio 7, PDF 9)",
    }, {
      "name" = "ninSameAlignmentPercent",
      "value" = 20,
      "comment" = "the automatic 20 percent chance the encountered being considers the ninja of its own alignment (folio 7, PDF 9)",
    }, {
      "name" = "ninLanguageBase",
      "value" = 6,
      "comment" = "languages known equal to intelligence minus six (folio 7, PDF 9)",
    }, {
      "name" = "ninNightVisionFeetLevel1",
      "value" = 30,
      "comment" = "night vision: see clearly to 30 feet at first level (folio 7, PDF 9)",
    }, {
      "name" = "ninNightVisionFeetLevel6",
      "value" = 60,
      "comment" = "night vision: see clearly to 60 feet at sixth level (folio 7, PDF 9)",
    }, {
      "name" = "ninTrackingPenaltyPercent",
      "value" = 20,
      "comment" = "a ninja tracks as a ranger with a 20 percent penalty (folio 7, PDF 9)",
    }, {
      "name" = "ninSimulateDeathDiceSides",
      "value" = 6,
      "comment" = "simulated death lasts (1-6) x level + 1 turns (folio 7, PDF 9)",
    }, {
      "name" = "ninSimulateDeathTurnsBonus",
      "value" = 1,
      "comment" = "the simulated-death turn bonus (folio 7, PDF 9)",
    }, {
      "name" = "ninTravelMilesLevel2",
      "value" = 50,
      "comment" = "a ninja above second level travels up to 50 miles a day (folio 7, PDF 9)",
    }, {
      "name" = "ninTravelMilesLevel6",
      "value" = 75,
      "comment" = "a ninja above sixth level travels up to 75 miles a day (folio 7, PDF 9)",
    }, {
      "name" = "ninTravelMilesLevel10",
      "value" = 100,
      "comment" = "a ninja above tenth level travels up to 100 miles a day (folio 7, PDF 9)",
    }, {
      "name" = "ninPoisonTypes",
      "value" = 6,
      "comment" = "the six ninja poison types (folio 8, PDF 10)",
    }, {
      "name" = "ninKillPoisonDamageMax",
      "value" = 5,
      "comment" = "kill poisons do 0-5 damage per level of strength (folio 8, PDF 10)",
    }, {
      "name" = "ninInstantPoisonMaxRounds",
      "value" = 2,
      "comment" = "instant poison takes effect in 1-2 melee rounds (folio 8, PDF 10)",
    }, {
      "name" = "ninSlowPoisonMinRounds",
      "value" = 10,
      "comment" = "slow poison takes effect in 10-60 melee rounds (folio 8, PDF 10)",
    }, {
      "name" = "ninSlowPoisonMaxRounds",
      "value" = 60,
      "comment" = "slow poison upper bound (folio 8, PDF 10)",
    }, {
      "name" = "ninDelayedPoisonMinRounds",
      "value" = 90,
      "comment" = "delayed poison takes effect in 90-140 melee rounds (folio 8, PDF 10)",
    }, {
      "name" = "ninDelayedPoisonMaxRounds",
      "value" = 140,
      "comment" = "delayed poison upper bound (folio 8, PDF 10)",
    }, {
      "name" = "ninLevel6PoisonTypes",
      "value" = 3,
      "comment" = "at level six the ninja must make three different poison types (folio 8, PDF 10)",
    }, {
      "name" = "ninLevel6PoisonStrengthMin",
      "value" = 2,
      "comment" = "the three level-six poison types must be at least strength two (folio 8, PDF 10)",
    }, {
      "name" = "ninLevel12PoisonStrengthMin",
      "value" = 1,
      "comment" = "at level 12 the ninja must make all six types of at least strength one (folio 8, PDF 10)",
    }, {
      "name" = "ninViscousLifeHours",
      "value" = 12,
      "comment" = "viscous poison evaporates in about 12 hours after application (folio 8, PDF 10)",
    }, {
      "name" = "ninPoisonNoticedPercent",
      "value" = 20,
      "comment" = "a 20 percent chance the poison use is noticed (folio 8, PDF 10)",
    }, {
      "name" = "ninAlchemistLevelsBelow",
      "value" = 3,
      "comment" = "a ninja brews poisons and broths as an alchemist three levels lower (folio 7, PDF 9)",
    }, {
      "name" = "ninUnmasteredAttackPenalty",
      "value" = 3,
      "comment" = "the -3 attack penalty with unmastered weapons, removed per weapon by mastery or disguise class (folio 8, PDF 10)",
    }, {
      "name" = "ninDisguiseAdvantagePercent",
      "value" = 4,
      "comment" = "a 4 percent advantage over an assassin in disguise recognition (folio 8, PDF 10)",
    }, {
      "name" = "ninNonNinjaAttackPenalty",
      "value" = 3,
      "comment" = "non-ninja using ninja gear: -3 on attack rolls (folio 9, PDF 11)",
    }, {
      "name" = "ninNonNinjaDamagePenalty",
      "value" = 2,
      "comment" = "non-ninja using ninja gear: -2 on damage rolls (folio 9, PDF 11)",
    }, {
      "name" = "ninDisguiseClasses",
      "value" = 10,
      "comment" = "the ten-entry disguise list (folio 8, PDF 10)",
    }, {
      "name" = "ninSpecialDisguiseRequires",
      "value" = 3,
      "comment" = "the special disguise needs at least three choices from 1-8 (folio 8, PDF 10)",
    }, {
      "name" = "ninNobilityDisguiseRequires",
      "value" = 5,
      "comment" = "the nobility disguise needs at least five choices from 1-9 (folio 8, PDF 10)",
    }, {
      "name" = "ninTeachMonthsMin",
      "value" = 1,
      "comment" = "teaching any ninja skill takes at least one month per item (folio 8, PDF 10)",
    }, {
      "name" = "ninProgressionRows",
      "value" = 17,
      "comment" = "the seventeen progression rows, chigo through 16th level (folio 8, PDF 10)",
    }, {
      "name" = "ninBasicKitItems",
      "value" = 5,
      "comment" = "the basic kit: ninja-to, sageo, saya, tetsu-bishi, osaku - plus one disguise and one equipment choice (folio 9, PDF 11)",
    }, {
      "name" = "ninThieveryLevelsBelow",
      "value" = 3,
      "comment" = "a ninja acts as a thief three levels below him (folio 9, PDF 11)",
    }, {
      "name" = "ninMultipleDamageLevelsAbove",
      "value" = 1,
      "comment" = "a ninja scores the multiple damage of a thief one level higher (folio 9, PDF 11)",
    }, {
      "name" = "ninAssassinationLevelsAbove",
      "value" = 2,
      "comment" = "a ninja operates as an assassin two levels higher (folio 9, PDF 11)",
    }, {
      "name" = "ninFeeJoninPercent",
      "value" = 15,
      "comment" = "a ninja pays 15 percent of his fee to the jonin of his family, a chigo pays nothing (folio 9, PDF 11)",
    }, {
      "name" = "ninRaceRows",
      "value" = 5,
      "comment" = "the five race and sex rows of the thieving bonus table (folio 9, PDF 11)",
    }, {
      "name" = "ninThievingRows",
      "value" = 17,
      "comment" = "the seventeen rows of the ninja thieving table, levels 0-16 (folio 9, PDF 11)",
    }, {
      "name" = "ninAssassinationRows",
      "value" = 17,
      "comment" = "the seventeen rows of the assassination probability and hire table (folio 9, PDF 11)",
    }, {
      "name" = "ninAssassinationKGold",
      "value" = 1000,
      "comment" = "the K price unit equals 1000 gold pieces (folio 9, PDF 11)",
    }, {
      "name" = "ninShurikenCarried",
      "value" = 9,
      "comment" = "nine shuriken normally carried, nine the lucky number (folio 10, PDF 12)",
    }, {
      "name" = "ninShurikenCostGold",
      "value" = 3,
      "comment" = "one shuriken costs 3 gold (folio 10, PDF 12)",
    }, {
      "name" = "ninShurikenDays",
      "value" = 3,
      "comment" = "one shuriken takes 3 days to make (folio 10, PDF 12)",
    }, {
      "name" = "ninShurikenKinds",
      "value" = 3,
      "comment" = "the three kinds: dart, star and whistler, each a separate weapon choice (folio 10, PDF 12)",
    }, {
      "name" = "ninShurikenPerLevels",
      "value" = 2,
      "comment" = "one shuriken thrown per melee round for every two levels (folio 10, PDF 12)",
    }, {
      "name" = "ninShurikenShieldPenalty",
      "value" = 1,
      "comment" = "shuriken take an extra -1 on attack vs shields (folio 10, PDF 12)",
    }, {
      "name" = "ninShurikenRangeFeet",
      "value" = 30,
      "comment" = "shuriken maximum range 30 feet (folio 10, PDF 12)",
    }, {
      "name" = "ninDartShurikenPlus",
      "value" = 2,
      "comment" = "dart shuriken attack as a +2 dagger (folio 10, PDF 12)",
    }, {
      "name" = "ninDartShurikenDamageMax",
      "value" = 6,
      "comment" = "dart shuriken do a basic 1-6 vs a man-sized target (folio 10, PDF 12)",
    }, {
      "name" = "ninFukumiNeedlesPerRound",
      "value" = 2,
      "comment" = "two fukumi-bari needles spat per melee round (folio 10, PDF 12)",
    }, {
      "name" = "ninFukumiMouthMax",
      "value" = 5,
      "comment" = "at most five needles held in the mouth (folio 10, PDF 12)",
    }, {
      "name" = "ninFukumiRangeFeet",
      "value" = 15,
      "comment" = "fukumi-bari spit up to 15 feet (folio 10, PDF 12)",
    }, {
      "name" = "ninFukumiPoisonPercent",
      "value" = 50,
      "comment" = "a hit has a 50 percent chance the needle poisoned the target (folio 10, PDF 12)",
    }, {
      "name" = "ninFukumiCostSilver",
      "value" = 1,
      "comment" = "fukumi-bari cost 1 silver, no time (folio 10, PDF 12)",
    }, {
      "name" = "ninBoStaffCostGold",
      "value" = 0,
      "comment" = "the bo staff, the basic quarterstaff, costs nothing (folio 10, PDF 12)",
    }, {
      "name" = "ninNinjaToCostGold",
      "value" = 10,
      "comment" = "the ninja-to costs 10 gold, the price of a basic short sword (folio 10, PDF 12)",
    }, {
      "name" = "ninSageoCostGold",
      "value" = 1,
      "comment" = "the sageo cord costs 1 gold (folio 10, PDF 12)",
    }, {
      "name" = "ninNageTeppoCostGold",
      "value" = 20,
      "comment" = "nage teppo eggshell grenades: 20 gold, one week (folio 10, PDF 11 tail)",
    }, {
      "name" = "ninNageTeppoDamageMin",
      "value" = 2,
      "comment" = "the nage teppo make 2-8, treated as alchemist flash pellets (folio 11, PDF 12 tail)",
    }, {
      "name" = "ninNageTeppoDamageMax",
      "value" = 8,
      "comment" = "the nage teppo damage upper bound (folio 11)",
    }, {
      "name" = "ninSodeTsutsuCostGold",
      "value" = 50,
      "comment" = "the sode tsutsu one-shot shotgun: 50 gold, one week (folio 11, PDF 12 tail)",
    }, {
      "name" = "ninSodeTsutsuRangeFeet",
      "value" = 30,
      "comment" = "the sode tsutsu fires its cone up to 30 feet away (folio 11)",
    }, {
      "name" = "ninSodeTsutsuConeFeet",
      "value" = 10,
      "comment" = "the sode tsutsu cone is 10 feet across at the base (folio 11)",
    }, {
      "name" = "ninSodeTsutsuDamageMax",
      "value" = 24,
      "comment" = "the sode tsutsu does 3-24, save vs death for half (folio 11)",
    }, {
      "name" = "ninKakaeOzutsuCostGold",
      "value" = 50,
      "comment" = "the kakae ozutsu one-shot mortar: 50 gold, one week (folio 11)",
    }, {
      "name" = "ninKakaeMinRangeFeet",
      "value" = 30,
      "comment" = "the kakae ozutsu minimum range 30 feet (folio 11)",
    }, {
      "name" = "ninKakaeMaxRangeFeet",
      "value" = 90,
      "comment" = "the kakae ozutsu maximum range 90 feet (folio 11)",
    }, {
      "name" = "ninKakaeBlastRadiusFeet",
      "value" = 10,
      "comment" = "the kakae ozutsu projectile bursts in a 10-foot blast radius (folio 11)",
    }, {
      "name" = "ninKakaeDamageMax",
      "value" = 20,
      "comment" = "the kakae ozutsu does 1-20 within the blast, save vs death for half (folio 11)",
    }, {
      "name" = "ninUzumeBiCostGold",
      "value" = 20,
      "comment" = "the uzume-bi: 20 gold and 3 days to make one (folio 11-12)",
    }, {
      "name" = "ninUzumeBiDays",
      "value" = 3,
      "comment" = "the uzume-bi manufacture time in days (folio 11-12)",
    }, {
      "name" = "ninUzumeBiDamageMax",
      "value" = 10,
      "comment" = "the uzume-bi does 1-10, save vs damage (folio 12, PDF 12 tail)",
    }, {
      "name" = "ninKyoketsuShogeCostGold",
      "value" = 4,
      "comment" = "the kyoketsu shoge: 4 gold, one week (folio 10, PDF 12)",
    }, {
      "name" = "ninKyoketsuShogeDays",
      "value" = 7,
      "comment" = "the kyoketsu shoge manufacture time (folio 10)",
    }, {
      "name" = "ninShinobiZueCostGold",
      "value" = 6,
      "comment" = "the shinobi zue staff: 6 gold and 4 days (folio 10, PDF 12)",
    }, {
      "name" = "ninShinobiZueDays",
      "value" = 4,
      "comment" = "the shinobi zue manufacture time (folio 10)",
    }, {
      "name" = "ninMetsubushiDamageMax",
      "value" = 2,
      "comment" = "metsubushi do 1-2 plus poison (folio 12, PDF 12 tail)",
    }, {
      "name" = "ninTetsuBishiDamageMaxMan",
      "value" = 4,
      "comment" = "tetsu-bishi do 1-4 vs man-sized (folio 12)",
    }, {
      "name" = "ninTetsuBishiDamageMaxLarger",
      "value" = 6,
      "comment" = "tetsu-bishi do 1-6 vs larger than man-sized (folio 12)",
    }, {
      "name" = "ninHankyuDamageMax",
      "value" = 6,
      "comment" = "the hankyu bow does 1-6 (folio 12)",
    } },
  "bools" = { {
      "name" = "ninEnlilDaggerVsChaoticOnly",
      "value" = true,
      "comment" = "the Enlil dagger bonus applies only against chaotic creatures (folio 4, PDF 6)",
    }, {
      "name" = "ninMaceDriverLotanOnly",
      "value" = true,
      "comment" = "the Mace Driver is only effective against Lotan (folio 6, PDF 8)",
    }, {
      "name" = "ninMaceExpellerYammOnly",
      "value" = true,
      "comment" = "the Mace Expeller is only effective against Yamm (folio 6, PDF 8)",
    }, {
      "name" = "ninStrictNeutrality",
      "value" = true,
      "comment" = "the alignment of a ninja is strict neutrality (folio 7, PDF 9)",
    }, {
      "name" = "ninAlignmentIncorruptible",
      "value" = true,
      "comment" = "a ninja is incorruptible in matters of alignment, virtually impossible to change (folio 7, PDF 9)",
    }, {
      "name" = "ninSameAlignmentRolledOnce",
      "value" = true,
      "comment" = "the same-alignment probability is generated only once per encounter, permanent, never re-rolled (folio 7, PDF 9)",
    }, {
      "name" = "ninSurprisedAsMonk",
      "value" = true,
      "comment" = "a ninja is surprised as are monks (folio 7, PDF 9)",
    }, {
      "name" = "ninNonpsychic",
      "value" = true,
      "comment" = "ninja are nonpsychic (folio 7, PDF 9)",
    }, {
      "name" = "ninDieBeforeRevealingSecrets",
      "value" = true,
      "comment" = "ninja are conditioned to die before revealing secrets, even when charmed (folio 9, PDF 11)",
    }, {
      "name" = "ninDoNotTalkInSleep",
      "value" = true,
      "comment" = "ninja do not talk in their sleep (folio 9, PDF 11)",
    }, {
      "name" = "ninPoisonStrengthCappedByLevels",
      "value" = true,
      "comment" = "the poison strength made may not be larger than the number of levels selected for that poison (folio 8, PDF 10)",
    }, {
      "name" = "ninKillPoisonHalfDamageOnSave",
      "value" = true,
      "comment" = "a kill poison produces only half damage if the saving throw is made (folio 8, PDF 10)",
    }, {
      "name" = "ninParalyzeDoubleLevelSuffocation",
      "value" = true,
      "comment" = "a character hit by an accumulation of double his level in paralyze poisons dies through suffocation (folio 8, PDF 10)",
    }, {
      "name" = "ninPoisonFluidOrViscous",
      "value" = true,
      "comment" = "ninja poison may be made either fluid or viscous at the ninja discretion (folio 8, PDF 10)",
    }, {
      "name" = "ninViscousAsBladeVenom",
      "value" = true,
      "comment" = "viscous poison is used on weapons as per blade venom for coverage (folio 8, PDF 10)",
    }, {
      "name" = "ninNeutralizeNoSavingThrow",
      "value" = true,
      "comment" = "no saving throw is needed against neutralization brews (folio 8, PDF 10)",
    }, {
      "name" = "ninCureHalfEffectOffDesign",
      "value" = true,
      "comment" = "a cure brew is of half effect against the other two rates of onset poisons and alchemist poisons (folio 8, PDF 10)",
    }, {
      "name" = "ninParalyzeKillCuresDoNotCross",
      "value" = true,
      "comment" = "paralization and kill cures do not affect each other (folio 8, PDF 10)",
    }, {
      "name" = "ninRefusesPlate",
      "value" = true,
      "comment" = "ninja will refuse to wear plate armor; chain or leather only in emergencies, chain disliked as noisy (folio 8, PDF 10)",
    }, {
      "name" = "ninAdvancesInCombatAsFighter",
      "value" = true,
      "comment" = "a ninja advances in combat steps as a fighter and has the combat adds of a fighter (folio 8, PDF 10)",
    }, {
      "name" = "ninOpenHandedAsMonk",
      "value" = true,
      "comment" = "a ninja may attack open-handed as a monk (folio 8, PDF 10)",
    }, {
      "name" = "ninJudoAsSamurai",
      "value" = true,
      "comment" = "a ninja may use judo as a samurai (folio 8, PDF 10)",
    }, {
      "name" = "ninSpecialSaveVsDamage",
      "value" = true,
      "comment" = "a ninja gets a saving throw against all missile, melee and directed spell damage (folio 8, PDF 10)",
    }, {
      "name" = "ninSavesAsMagicianOneHigherVsSpells",
      "value" = true,
      "comment" = "the ninja saves as a magician of one level higher versus spells (folio 8, PDF 10)",
    }, {
      "name" = "ninHobbitsDwarvesNoFourLevelsVsSpells",
      "value" = true,
      "comment" = "hobbits and dwarves do not add four levels for the ninja spell saves (folio 8, PDF 10)",
    }, {
      "name" = "ninSavesAsFighter",
      "value" = true,
      "comment" = "a ninja saves as a fighter (folio 8, PDF 10)",
    }, {
      "name" = "ninPenaltyRemovedOncePerWeapon",
      "value" = true,
      "comment" = "the unmastered-weapon penalty is removed only once per weapon even if used by several groups (folio 8, PDF 10)",
    }, {
      "name" = "ninSkillsGainedImmediatelyOnLevel",
      "value" = true,
      "comment" = "the W D T E draws are gained immediately upon advancing a level (folio 8, PDF 10)",
    }, {
      "name" = "ninNonNinjaMasteryNeverRemovesPenalty",
      "value" = true,
      "comment" = "the non-ninja gear penalty applies no matter how much time is spent attempting mastery (folio 9, PDF 11)",
    }, {
      "name" = "ninFallsAsMonk",
      "value" = true,
      "comment" = "a ninja falls from walls as a monk, climbing the sheerest walls with his tools (folio 9, PDF 11)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "ninGodStat",
      "tag" = "NG",
      "count" = "ninGodRows",
      "sentinel" = -1,
      "sentinel_census" = { 4, 0, 0, 12, 0, 0 },
      "audit_comment" = "the near eastern pantheon grid - sixteen full stat-block deities in printed order, the see-below magic cells riding the transcript at the sentinel, the dual move entries (Namtar 18/36, Nebo 15/25) pinned at the first figure with the second riding the transcript (folios 4-5, PDF 6-7)",
      "cols" = { "ninGodAc", "ninGodMove", "ninGodHp", "ninGodMagicLvl", "ninGodFightLvl", "ninGodPsiClass" },
      "col_comments" = { "the deity armor classes - the four genuine minus-one prints (Enki-Ea, Ninhursag-Asherah, Ereshkigal-Mot, Nergal-Mekal) count in the sentinel census as the minus-one class (folios 4-5, PDF 6-7)", "the deity move in feet - the dual entries pin the first figure, the second rides the transcript (folios 4-5)", "the deity hit points (folios 4-5)", "the wizard level - sentinel for the see-below spell lists, never guessed (folios 4-5)", "the fighter ability, the Lord level (folios 4-5)", "the psionic ability class (folios 4-5)" },
      "data" = { { -2, 18, 300, -1, 15, 6 }, { -2, 18, 290, -1, 18, 6 }, { -1, 18, 250, 35, 15, 1 }, { 0, 20, 200, -1, 14, 6 }, { -1, 18, 275, -1, 15, 6 }, { 0, 20, 200, -1, 16, 6 }, { 0, 18, 200, -1, 15, 6 }, { 2, 15, 150, -1, 13, 5 }, { -1, 18, 200, -1, 14, 6 }, { -1, 18, 175, -1, 16, 6 }, { 2, 18, 150, -1, 12, 4 }, { -3, 20, 300, 20, 16, 6 }, { -3, 20, 300, 18, 15, 6 }, { -2, 18, 200, -1, 14, 6 }, { 2, 15, 150, -1, 10, 6 }, { 2, 15, 150, 14, 11, 6 } },
    }, {
      "name" = "ninCreatureStat",
      "tag" = "NC",
      "count" = "ninCreatureRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0, 0, 1, 0, 1 },
      "audit_comment" = "the two monsters - Humbaba the cedar forest guardian, the scorpion men of the Dilmun gate (folios 5-6, PDF 7-8)",
      "cols" = { "ninCreatureAc", "ninCreatureMove", "ninCreatureHp", "ninCreatureMagicLvl", "ninCreatureFightLvl", "ninCreaturePsiClass" },
      "col_comments" = { "the monster armor classes (folios 5-6, PDF 7-8)", "the monster move in feet (folios 5-6)", "the monster hit points (folios 5-6)", "the magic level - nil pins sentinel (folios 5-6)", "the fighter ability, the Lord level (folios 5-6)", "the psionic ability class - nil pins sentinel (folios 5-6)" },
      "data" = { { 1, 25, 230, -1, 13, -1 }, { 1, 20, 240, 15, 15, 1 } },
    }, {
      "name" = "ninHeroStat",
      "tag" = "NH",
      "count" = "ninHeroRows",
      "sentinel" = -1,
      "sentinel_census" = { 5, 0, 0, 6, 0, 6 },
      "audit_comment" = "the hero and king stat grid - eight full stat blocks in printed order, the as-a-normal-man armor classes pinning sentinel, the nil magic and psionic cells pinning sentinel (folio 5, PDF 7)",
      "cols" = { "ninHeroAc", "ninHeroMove", "ninHeroHp", "ninHeroMagicLvl", "ninHeroFightLvl", "ninHeroPsiClass" },
      "col_comments" = { "the hero armor classes - the as-a-normal-man prints pin sentinel, never guessed (folio 5, PDF 7)", "the hero move in feet (folio 5)", "the hero hit points (folio 5)", "the magic level - nil pins sentinel (folio 5)", "the fighter ability, the Lord level (folio 5)", "the psionic ability class - nil pins sentinel (folio 5)" },
      "data" = { { 2, 12, 120, -1, 15, -1 }, { -1, 12, 100, -1, 13, -1 }, { 1, 13, 140, 11, 15, 6 }, { 2, 13, 140, 15, 11, 5 }, { -1, 12, 80, -1, 10, -1 }, { -1, 12, 88, -1, 11, -1 }, { -1, 12, 100, -1, 13, -1 }, { -1, 12, 70, -1, 9, -1 } },
    }, {
      "name" = "ninHeroAbility",
      "tag" = "NA",
      "count" = "ninHeroRows",
      "sentinel" = -1,
      "sentinel_census" = { 2, 0, 0, 0, 0, 0 },
      "audit_comment" = "the hero ability grid - the Enkidu strength printing 1895 and the Aqht strength printing 1875 are the 18-slash-percentile garble class, pinned sentinel, never guessed; every other stat line prints clean (folio 5, PDF 7)",
      "cols" = { "ninHeroStr", "ninHeroInt", "ninHeroWis", "ninHeroCon", "ninHeroDex", "ninHeroCha" },
      "col_comments" = { "the hero strength - the garbled 1895 (Enkidu) and 1875 (Aqht) prints pin sentinel, the 18-slash-percentile reading rides the transcript (folio 5, PDF 7)", "the hero intelligence (folio 5)", "the hero wisdom (folio 5)", "the hero constitution (folio 5)", "the hero dexterity (folio 5)", "the hero charisma (folio 5)" },
      "data" = { { 20, 15, 10, 18, 17, 20 }, { -1, 12, 15, 17, 18, 15 }, { 20, 20, 20, 20, 20, 20 }, { 16, 19, 20, 18, 17, 15 }, { 15, 17, 12, 13, 16, 16 }, { 16, 13, 18, 14, 14, 15 }, { -1, 16, 10, 13, 17, 17 }, { 14, 14, 13, 15, 17, 18 } },
    }, {
      "name" = "ninProgression",
      "tag" = "NP",
      "count" = "ninProgressionRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 2, 2, 2, 2 },
      "audit_comment" = "the progression grid - the save-vs-damage bands 15, 12, 8 and 3 plus the weapons, disguises, tools and equipment draws per level; the chigo and bushi rows print no draws, pinned sentinel; the hit-dice column (1D4 through 8D12+2D4) rides the transcript (folio 8, PDF 10)",
      "cols" = { "ninSaveVsDamage", "ninDrawWeapons", "ninDrawDisguises", "ninDrawTools", "ninDrawEquipment" },
      "col_comments" = { "the save vs damage by level - 15 through level 4, 12 through 9, 8 through 14, 3 at 15-16 (folio 8, PDF 10)", "the weapons draws gained on reaching the level - the blank chigo and bushi cells pin sentinel (folio 8)", "the disguises draws gained on reaching the level - blanks pin sentinel (folio 8)", "the ninja tools draws gained on reaching the level - blanks pin sentinel (folio 8)", "the equipment draws gained on reaching the level - blanks pin sentinel (folio 8)" },
      "data" = { { 15, -1, -1, -1, -1 }, { 15, -1, -1, -1, -1 }, { 15, 1, 0, 1, 1 }, { 15, 0, 0, 0, 1 }, { 15, 1, 1, 0, 1 }, { 12, 0, 1, 1, 1 }, { 12, 1, 0, 1, 1 }, { 12, 1, 1, 0, 1 }, { 12, 1, 0, 1, 1 }, { 12, 1, 1, 0, 1 }, { 8, 1, 1, 1, 1 }, { 8, 1, 1, 0, 0 }, { 8, 1, 1, 0, 0 }, { 8, 1, 1, 0, 0 }, { 8, 1, 1, 0, 0 }, { 3, 1, 1, 0, 0 }, { 3, 0, 1, 0, 0 } },
    }, {
      "name" = "ninThievingRace",
      "tag" = "NR",
      "count" = "ninRaceRows",
      "sentinel" = -999,
      "audit_comment" = "the race and sex thieving bonus grid - human, elf, dwarf, hobbit, female, all bonuses additive (folio 9, PDF 11)",
      "cols" = { "ninRacePickLock", "ninRaceRemoveTrap", "ninRacePickPocket", "ninRaceMoveSilent", "ninRaceHideShadows", "ninRaceHearNoise" },
      "col_comments" = { "the racial pick lock bonus (folio 9, PDF 11)", "the racial remove trap bonus (folio 9)", "the racial pick pocket bonus (folio 9)", "the racial move silent bonus (folio 9)", "the racial hide in shadows bonus (folio 9)", "the racial hear noise bonus (folio 9)" },
      "data" = { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 5, 10, 15, 0 }, { 5, 15, 0, 5, 5, 0 }, { 10, 5, 5, 10, 10, 15 }, { 5, 5, 5, 5, 5, 5 } },
    }, {
      "name" = "ninThieving",
      "tag" = "NT",
      "count" = "ninThievingRows",
      "sentinel" = -999,
      "audit_comment" = "the ninja thieving grid - levels 0-16 x pick lock, remove trap, pick pocket, move silent, hide in shadows, hear noise, fall off walls; the level-4 hide cell prints 70 and the level-5 cell 60 against the +5 drift, pinned as scanned; the 100+ rule (subtract 100 and repeat) rides the transcript (folio 9, PDF 11)",
      "cols" = { "ninPickLock", "ninRemoveTrap", "ninPickPocket", "ninMoveSilent", "ninHideShadows", "ninHearNoise", "ninFallOffWalls" },
      "col_comments" = { "the pick lock percentages, -5 at chigo to 105 at 16th (folio 9, PDF 11)", "the remove trap percentages, -10 at chigo to 100 at 16th (folio 9)", "the pick pocket percentages (folio 9)", "the move silent percentages (folio 9)", "the hide in shadows percentages - the 70 and 60 prints at levels 4 and 5 pin as scanned (folio 9)", "the hear noise percentages (folio 9)", "the fall off walls percentages, 15 at chigo down to -1 at 16th, the genuine -1 print (folio 9)" },
      "data" = { { -5, -10, 0, 20, 30, 20, 15 }, { 0, -5, 5, 40, 40, 50, 14 }, { 5, 0, 10, 45, 45, 58, 13 }, { 10, 5, 15, 50, 50, 67, 12 }, { 15, 10, 20, 55, 70, 70, 11 }, { 20, 15, 25, 60, 60, 73, 10 }, { 25, 20, 30, 65, 65, 77, 9 }, { 35, 30, 35, 70, 70, 80, 8 }, { 40, 35, 45, 75, 75, 83, 7 }, { 45, 40, 55, 80, 80, 88, 6 }, { 55, 50, 60, 90, 90, 94, 5 }, { 65, 60, 65, 95, 95, 100, 4 }, { 75, 70, 75, 100, 100, 104, 3 }, { 85, 80, 85, 105, 105, 108, 2 }, { 95, 90, 95, 110, 110, 112, 1 }, { 100, 95, 100, 115, 115, 117, 0 }, { 105, 100, 105, 120, 120, 121, -1 } },
    }, {
      "name" = "ninAssassination",
      "tag" = "NK",
      "count" = "ninAssassinationRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4 },
      "audit_comment" = "the assassination probability and hiring grid - seventeen levels, the cost column in half-K units (K = 1000 gold), the ten percent columns in printed order; the bullet cells pin sentinel; the row-12 99, row-13 sixth-column 110 and row-15 eighth-column 99 prints pin as scanned (folio 9, PDF 11)",
      "cols" = { "ninAssassCostHalfK", "ninAssassBand1", "ninAssassBand2", "ninAssassBand3", "ninAssassBand4", "ninAssassBand5", "ninAssassBand6", "ninAssassBand7", "ninAssassBand8", "ninAssassBand9", "ninAssassBand10" },
      "col_comments" = { "the hiring cost in half-K units, 1 K at chigo doubling to 512 K at 13th, then the as-scanned 1006, 1518 and 2012 K prints at 14th-16th (folio 9, PDF 11)", "the first printed percent column, in printed order - the header prints eleven victim bands, the rows ten values, the alignment riding the transcript (folio 9)", "the second printed percent column (folio 9)", "the third printed percent column (folio 9)", "the fourth printed percent column (folio 9)", "the fifth printed percent column (folio 9)", "the sixth printed percent column - the 99 print at level 12 pins as scanned (folio 9)", "the seventh printed percent column - the chigo bullet pins sentinel (folio 9)", "the eighth printed percent column - the 99 print at level 15 pins as scanned (folio 9)", "the ninth printed percent column (folio 9)", "the tenth printed percent column - the four bullets pin sentinel (folio 9)" },
      "data" = { { 2, 50, 45, 40, 30, 20, 5, -1, 1, 1, -1 }, { 3, 85, 80, 75, 65, 55, 40, 25, 10, 1, -1 }, { 4, 90, 85, 80, 70, 60, 45, 30, 15, 1, -1 }, { 5, 95, 90, 85, 75, 65, 50, 35, 20, 5, -1 }, { 6, 100, 95, 90, 80, 70, 55, 40, 25, 10, 1 }, { 7, 100, 100, 95, 85, 75, 60, 45, 30, 15, 1 }, { 8, 105, 100, 100, 90, 80, 65, 50, 35, 20, 5 }, { 16, 105, 105, 100, 95, 85, 70, 55, 45, 25, 10 }, { 32, 105, 105, 105, 100, 90, 75, 60, 45, 30, 15 }, { 64, 110, 105, 105, 100, 95, 80, 65, 50, 35, 20 }, { 128, 110, 110, 105, 105, 100, 85, 70, 55, 40, 25 }, { 256, 110, 110, 110, 105, 100, 90, 75, 60, 45, 30 }, { 512, 115, 110, 110, 105, 105, 99, 95, 80, 65, 50 }, { 1024, 115, 115, 110, 110, 105, 110, 100, 90, 75, 60 }, { 2012, 115, 115, 115, 110, 105, 100, 100, 95, 85, 80 }, { 3036, 120, 115, 115, 110, 110, 100, 100, 99, 95, 85 }, { 4024, 120, 120, 115, 115, 110, 105, 105, 100, 100, 90 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['ninAxeMightPlus']() != 3 or m['ninAxeMightDamageMin']() != 2 or m['ninAxeMightDamageMax']() != 16 or m['ninBowOfAnshanPlus']() != 3 or m['ninBreastplateArmorBonus']() != 5 or m['ninBreastplateShekels']() != 30 or m['ninMaceDriverPlus']() != 3 or m['ninMaceDriverDamageMax']() != 18 or m['ninMaceExpellerPlus']() != 3 or m['ninEnlilChariotHorsesMoveFeet']() != 36 or m['ninEnlilArrowsOfSlaying']() != 30 or m['ninOtherDeities']() != 20",
      "note" = "the mythos artifacts and god gear - the axe +3 for 2-16, the bow +3 to arrows, the breastplate +5 at 30 shekels, both maces +3 for 3-18, the Enlil chariot horses at 36 feet, 30 arrows of slaying, twenty other deities (folio 6, PDF 8)",
    }, {
      "expr" = "m['ninLevelCap']() != 16 or m['ninSameAlignmentPercent']() != 20 or m['ninLanguageBase']() != 6 or m['ninNightVisionFeetLevel1']() != 30 or m['ninNightVisionFeetLevel6']() != 60 or m['ninTravelMilesLevel2']() != 50 or m['ninTravelMilesLevel6']() != 75 or m['ninTravelMilesLevel10']() != 100 or m['ninTrackingPenaltyPercent']() != 20 or m['ninSimulateDeathDiceSides']() != 6 or m['ninSimulateDeathTurnsBonus']() != 1",
      "note" = "the ninja headline - the 16th-level cap, the 20 percent same-alignment chance rolled once per encounter, languages at intelligence minus six, night vision 30 then 60 feet, travel 50, 75 and 100 miles, tracking at a 20 percent penalty, simulated death at (1-6) x level + 1 turns (folio 7, PDF 9)",
    }, {
      "expr" = "m['ninPoisonTypes']() != 6 or m['ninKillPoisonDamageMax']() != 5 or m['ninInstantPoisonMaxRounds']() != 2 or m['ninSlowPoisonMinRounds']() != 10 or m['ninSlowPoisonMaxRounds']() != 60 or m['ninDelayedPoisonMinRounds']() != 90 or m['ninDelayedPoisonMaxRounds']() != 140 or m['ninLevel6PoisonTypes']() != 3 or m['ninLevel6PoisonStrengthMin']() != 2 or m['ninLevel12PoisonStrengthMin']() != 1 or m['ninViscousLifeHours']() != 12 or m['ninPoisonNoticedPercent']() != 20 or m['ninAlchemistLevelsBelow']() != 3",
      "note" = "the ninja poison system - six types, kill poison 0-5 per strength level and half damage on save, instant 1-2, slow 10-60, delayed 90-120 rounds, level 6 at three types of strength 2, level 12 at six types of strength 1, viscous gone in 12 hours, 20 percent noticed, alchemist three levels lower (folio 8, PDF 10)",
    }, {
      "expr" = "m['ninFukumiNeedlesPerRound']() != 2 or m['ninFukumiMouthMax']() != 5 or m['ninFukumiRangeFeet']() != 15 or m['ninFukumiPoisonPercent']() != 50 or m['ninShurikenCarried']() != 9 or m['ninShurikenPerLevels']() != 2 or m['ninShurikenRangeFeet']() != 30 or m['ninDartShurikenPlus']() != 2 or m['ninSodeTsutsuDamageMax']() != 24 or m['ninKakaeBlastRadiusFeet']() != 10 or m['ninKakaeDamageMax']() != 20 or m['ninBasicKitItems']() != 5 or m['ninFeeJoninPercent']() != 15",
      "note" = "the ninja gear - fukumi-bari two needles a round, five in the mouth, 15 feet, 50 percent poison; nine shuriken, one per two levels, 30 feet, the dart as a +2 dagger; the sode tsutsu 3-24, the kakae ozutsu 1-20 in a 10-foot blast; the five-item basic kit; the 15 percent fee to the jonin (folios 9-10, PDF 11-12)",
    } },
  "audit" = {
      "label" = "R929 issue-16 opener audit",
      "comment" = "THE DRAGON ISSUE-16 OPENER ROUND - both engine-relevant chains in one round. CHAIN ONE, the Near Eastern Mythos by Jerome Arkenberg (print 4-6, PDF 6-8), the direct sibling of the R920 Persian and R923 Japanese Mythos chains: the Sumerian-Babylonian-Canaanite pantheon - An-Anu-El armor class minus 2 at 300 hit points Lord 15th psionic class 6, Enlil-Marduk-Baal Lord 18th with the chariot horses at 36 feet the dagger +3 vs chaotic and 30 arrows of slaying, Enki-Ea the Wizard 35th at psionic class 1, Nanna-Sin-Yerah, Ninhursag-Asherah, Utu-Shamash Lord 16th, Inanna-Ishtar, Dumuzi-Tammuz, Ereshkigal-Mot, Nergal-Mekal, Namtar, Tiamat-Lotan armor class minus 3 at Wizard 20th, Apsu-Yamm armor class minus 3 at Wizard 18th, Kingsu with the Sword of Cold, Nebo, the Skilful and Percipient One Wizard 14th Lord 11th; the heroes - Gilgamesh strength and charisma 20, Enkidu the wild man, Lugulbanda all stats 20, Ziusudra-Utnapishtim the Wizard 15th at class 5, King Krt, King Dn-il, Aqht, the Maiden; the monsters Humbaba and the scorpion men; the artifacts - the Axe Might of Heroes +3 for 2-16, the Bow of Anshan +3 to arrows, the Breastplate Voice of Heroes armor +5 at 30 shekels, the Mace Driver +3 for 3-18 vs Lotan only, the Mace Expeller +3 for 3-18 vs Yamm only; twenty one-line other deities. CHAIN TWO, The Ultimate NPC: Ninja by Sheldon Price (print 7-10, PDF 9-12), the DM hit-man class: strict neutrality with the 20 percent same-alignment chance rolled once per encounter, languages at intelligence minus six, night vision 30 then 60 feet, the level cap at 16, the six-type poison system with the kill poison 0-5 per strength level half damage on save the paralyze double-level suffocation the instant 1-2 slow 10-60 delayed 90-140 onset and the viscous life of 12 hours, the -3 unmastered-weapon penalty removed per weapon, the thievery of a thief three levels below with the race and sex bonuses, the multiple damage of a thief one level higher, the assassination of an assassin two levels higher at 15 percent of the fee to the jonin, the seventeen-row progression grid with the save bands 15, 12, 8 and 3 and the W D T E draws, the seventeen-row thieving grid, the seventeen-row assassination probability and hiring grid with the K price unit at 1000 gold, and the special-device gear from the bo staff to the kakae ozutsu.",
    },
}
