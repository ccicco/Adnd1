-- t24: promoted from tools/spec_r954.json (the The Dragon issue-24 opener part one - the variant triptych);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 954,
  "prefix" = "t24",
  "banner" = {
      "title" = "The Dragon issue-24 opener part one - the variant triptych",
      "provenance" = "The opener of the issue-24 four-round shape - three of the fourteen Curtiss-called chains pinned as the variant triptych, the alignment pantheon riding its own part-two table round, the ten-chain commentary set at part three and the flip to follow. All pinned from The Dragon Vol. III No. 10 (April 1979) print 5-11 at extract/dragon/024, PRINT FOLIO = PDF PAGE this issue, the single-voice transcript of the Curtiss-provided scan - the issue runs 48 pages, the Kask editorial printing the paper-strike economy cut from 56. The intake seats the gap report and all forty-eight transcripts; the two inherited watches - the Sullin levels 7-9 and the brawling long-term-effects sequel - print nowhere in issue 24 and ride to TD 25.",
    },
  "consts" = { {
      "name" = "t24LostCityRollHi",
      "value" = 3,
      "comment" = "the lost-city discovery roll - two dice, a two or three indicates a city has been discovered the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24TyrantBandHi",
      "value" = 3,
      "comment" = "the organization roll - one die, one through three a warrior-king who is always a tyrant the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24TyrantWarriorAdd",
      "value" = 10,
      "comment" = "the tyrant army count - the product of three dice plus ten warriors the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24PriestWarriorAdd",
      "value" = 5,
      "comment" = "the priest city count - four through six rules the evil high priest and the beautiful white goddess, the product of three dice plus five the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24ReactionAdd",
      "value" = 9,
      "comment" = "the reaction modifier - attitude two or three adds nine to the number the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24GoddessReactionBonus",
      "value" = 1,
      "comment" = "the white goddess adds one - white goddesses are always interested in strangers the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24GuideReactionPenalty",
      "value" = 1,
      "comment" = "a guide from a neighboring hex subtracts one - lost civilizations are usually at war with neighboring tribes the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24AskariKill",
      "value" = 1,
      "comment" = "the musket volley - the askaris shoot killing one warrior the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24ExplorerKill",
      "value" = 2,
      "comment" = "the explorer kills two warriors with his musket the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24MissionaryKill",
      "value" = 1,
      "comment" = "the missionary only kills one - the Modified Gygax rule the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24BearersFleeDivisor",
      "value" = 2,
      "comment" = "half the bearers drop their loads and run when the warriors close the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24EscapeGold",
      "value" = 100,
      "comment" = "the prison-break reward - one hundred dollars in gold, five hundred in diamonds for a geologist the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24EscapeDiamonds",
      "value" = 500,
      "comment" = "the duel and flight rewards - five hundred dollars in diamonds or gold and gems at the volcano the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24TriumphDiamonds",
      "value" = 1000,
      "comment" = "the triumph escape - one thousand dollars in diamonds into an adjacent hex of the player choice the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24DesertLootGems",
      "value" = 1000,
      "comment" = "the desert city looted - a bag of gems worth one thousand dollars the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24BearerGold",
      "value" = 200,
      "comment" = "each bearer carries off golden treasure worth two hundred dollars, equal to twenty gifts, discarding all other loads the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24NovelistFee",
      "value" = 500,
      "comment" = "publication as a work of fiction nets the explorer an additional five hundred dollars the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24CurseDiePenalty",
      "value" = 2,
      "comment" = "the desert curse - each turn roll one die and subtract two men dead, drained bloodless with terror frozen on their faces the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24ReenterBonus",
      "value" = 1,
      "comment" = "an explorer re-entering a lost city he previously explored adds one to all his die rolls the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24WifeBonus",
      "value" = 2,
      "comment" = "if his wife the white goddess accompanies him he adds two - she takes all the risks and can count as an askari the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24UnderdogStake",
      "value" = 700,
      "comment" = "the Lord Underdog saga - the zoologist raised seven hundred dollars for the Zambezi expedition the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24UnderdogPoints",
      "value" = 5,
      "comment" = "Underdog earned a grand total of five points - the danger and excitement of nineteenth-century exploration the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24LairPct",
      "value" = 60,
      "comment" = "a sixty percent chance of finding them in their lair - but they never sleep the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24PsionicClass",
      "value" = 6,
      "comment" = "all Chinese dragons are psionic class six the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24EspRadiusMult",
      "value" = 5,
      "comment" = "ESP at a radius of five times the age level of the dragon the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ScalyCommandHoursLo",
      "value" = 2,
      "comment" = "the Scaly Command duration floor - two to twelve hours the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ScalyCommandHoursHi",
      "value" = 12,
      "comment" = "the Scaly Command duration ceiling - the command cannot be dispelled the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24WaterFireRoundsLo",
      "value" = 20,
      "comment" = "Water Fire disappears for twenty rounds after real fire contact the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24WaterFireRoundsHi",
      "value" = 120,
      "comment" = "the Water Fire absence ceiling - one hundred twenty rounds, none recreated until the end of that period the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24TienFirePerDay",
      "value" = 6,
      "comment" = "the Tien Lung breath - fire in a nine-by-three cone six times per day, damage of the hit dice times the age level the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24TienControlMult",
      "value" = 2,
      "comment" = "the Tien Lung throws Control Weather at two times the age level number of times per day the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24TienServantPct",
      "value" = 50,
      "comment" = "old and older Tien Lung - a fifty percent chance of one to six Wind Walkers, Aerial Servants or Spirits of the Air the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ShenSpellPerDay",
      "value" = 3,
      "comment" = "the Shen Lung cast three times a day - Control Weather or Ice Storm in any combination the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ShenBiteHi",
      "value" = 24,
      "comment" = "the Shen Lung ordinary attacks - two claws one to four, one bite two to twenty-four, one tail spike one to eight the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ShenWaterFireHi",
      "value" = 12,
      "comment" = "the Shen Lung Water Fire for two to twelve hits, Scaly Command for two to twenty creatures times the age level the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ShenInsectRadius",
      "value" = 6,
      "comment" = "no insect, arachnid or arthropod may approach a Shen Lung within a radius of six feet the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24LiQuakeMult",
      "value" = 3,
      "comment" = "the Li Lung Earthquake - width and length each three times the age level, once a day without a chance of being dispelled the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24LiBiteHi",
      "value" = 20,
      "comment" = "the Li Lung attacks - two claws one to five and one bite one to twenty the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24PanConstrictHi",
      "value" = 12,
      "comment" = "the Pan Lung grasp - the bite of two to sixteen holds, the automatic bite for one to eight and the tail constricts for two to twelve more the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24PanCharmPerDay",
      "value" = 3,
      "comment" = "the Pan Lung throw Charm Monster three times per day the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24PanScalyHi",
      "value" = 10,
      "comment" = "the Pan Lung Scaly Command for one to ten creatures, Water Fire for one to six points of damage the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24WangSteamPerDay",
      "value" = 3,
      "comment" = "the Lung Wang breathe steam three times per day in a ten-by-five cone the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24WangBiteHi",
      "value" = 36,
      "comment" = "the Lung Wang attacks - two claws one to twelve and one bite six to thirty-six the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24WangScalyHi",
      "value" = 40,
      "comment" = "the Lung Wang Scaly Command at four to forty creatures times the age level the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24YuAdultCap",
      "value" = 5,
      "comment" = "rolling up Yu Lung - bring all age levels of five or above down to adult the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24YuLandHour",
      "value" = 1,
      "comment" = "the Yu Lung emerge awkwardly onto land for up to one hour the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24DragonTypeCount",
      "value" = 6,
      "comment" = "the six Chinese dragon types of the summary roster the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24InfectionThresholdPct",
      "value" = 50,
      "comment" = "any warm-blooded being seriously injured - fifty percent or more of the damage they can take - stands a good chance of infection the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24OnsetAHi",
      "value" = 8,
      "comment" = "the type A onset - the change occurs within one to eight days of being bitten the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24OnsetBHi",
      "value" = 36,
      "comment" = "the type B onset - within three to thirty-six turns the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24OnsetCHi",
      "value" = 24,
      "comment" = "the type C onset - within two to twenty-four turns of being infected the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24OnsetDHi",
      "value" = 12,
      "comment" = "the type D onset - beginning one to twelve turns after infection the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24OnsetEfHi",
      "value" = 16,
      "comment" = "the type E and F onset - beginning two to sixteen turns after infection the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24OnsetGHi",
      "value" = 10,
      "comment" = "the type G onset - beginning one to ten turns after being bitten the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24CureClericCLevel",
      "value" = 7,
      "comment" = "the type C cure - a Cure Disease or Remove Curse from a cleric of at least seventh level the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24CureClericGLevel",
      "value" = 8,
      "comment" = "the type G cure - a cleric of at least eighth level the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24FullMoonPct",
      "value" = 95,
      "comment" = "the full-moon change chance for type G - ninety-five percent the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24StressBasePct",
      "value" = 40,
      "comment" = "the base forty percent chance under great stress, added to or subtracted from according to the type of stress the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24FormDurationHi",
      "value" = 12,
      "comment" = "the changed form holds for two to twelve turns or until the stress or the full moon is gone, whichever comes last the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24HalvedPowersDivisor",
      "value" = 2,
      "comment" = "the G-form split - about one half of the player abilities and one half of the real lycanthrope powers the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24TypeGRatSummonHi",
      "value" = 50,
      "comment" = "the halved rat summon - a Were-Rat of the G type could summon five to fifty rats, not the usual ten to one hundred the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24ShieldKeepPct",
      "value" = 10,
      "comment" = "a ten percent chance the player keeps his shield in lycanthrope form - only were-rats, were-bears and type G lycanthropes can use one the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24WerewolfShieldAc",
      "value" = 4,
      "comment" = "the player creature armor class one lower than usual - a were-wolf with a shield would be armor class four the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24DropSuppliesPct",
      "value" = 65,
      "comment" = "a base sixty-five percent chance the lycanthrope drops all supplies and possessions at the first change the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24DropTypeGPct",
      "value" = 40,
      "comment" = "the type G drop chance - forty percent, and zero for the physical types C and F the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24MaxLevelDivisor",
      "value" = 3,
      "comment" = "past maximum level they gain only one third of the hit point adds per level, rounding off to the next highest whole number the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24PoisonSaveExample",
      "value" = 9,
      "comment" = "the worked save - a player needing twelve against poison needs only nine in were-wolf form, the minus three wolf row the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24LycanBandCount",
      "value" = 7,
      "comment" = "the seven infection bands A through G of the dice-roll table the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24LycanAlignCount",
      "value" = 9,
      "comment" = "the nine rows of the alignment comparison matrix the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24LycanAttrCount",
      "value" = 5,
      "comment" = "the five rows of the attribute modifier table - the printed duplicate Boar row reads the bear line the lycanthropy infection variant (print 10-11)",
    } },
  "bools" = { {
      "name" = "t24SotnFantasySupplement",
      "value" = true,
      "comment" = "the fantasy supplement frame - the encounters Allan Quartermain or Lord Greystoke would have had, Haggard and Burroughs the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24DesertCityUninhabited",
      "value" = true,
      "comment" = "the desert lost city is uninhabited and legendary - the bearers know it as a city of demons and try to desert the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24AtlantisSurvivors",
      "value" = true,
      "comment" = "every other hex holds survivors of lost Atlantis with bronze weapons and ornaments of gold decorated with rubies and diamonds the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24AncientGreekSpeech",
      "value" = true,
      "comment" = "some of the ruling class can speak ancient Greek - the explorer had a classical education himself the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24GuestsOfTheCity",
      "value" = true,
      "comment" = "the accepted expedition draws no disaster card, is fed by the city and the priests cure the sick the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24SurpriseMuskets",
      "value" = true,
      "comment" = "a surprised expedition has no chance to shoot their muskets - the warriors close for hand to hand combat the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24MosasaurusPool",
      "value" = true,
      "comment" = "the sacred pool - a mosasaurus, the gigantic aquatic dinosaur miraculously surviving the eons, devours prisoners the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24RebelAspirant",
      "value" = true,
      "comment" = "the tyrant city holds a young noble aspirant offering help in return for support in a forthcoming rebellion the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24GoddessLovesExplorer",
      "value" = true,
      "comment" = "the white goddess falls in love with the explorer and gets him released from the dungeon under guard the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24DuelOfMagic",
      "value" = true,
      "comment" = "the duel of magic and faith - gunpowder, a magnet and a magnifying lens against the Atlanean science of the high priest the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24DesertCurseRides",
      "value" = true,
      "comment" = "the curse kills guides first, then bearers, then askaris and finally the explorer until a civilized coastal hex the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24ExclusiveReturn",
      "value" = true,
      "comment" = "the city may be re-entered only by the discovering explorer - any other explorer finds merely an uninhabited hex the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "name" = "t24PowersByType",
      "value" = true,
      "comment" = "any alignment and any color - white red yellow blue green or black - the powers vary solely with the type the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24OnlyYuSubduable",
      "value" = true,
      "comment" = "only the Yu Lung can be subdued - age and size rolled as for a normal dragon the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24PolymorphHuman",
      "value" = true,
      "comment" = "all except the Yu Lung polymorph at will into human form and back the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24VisibleWhenAttacking",
      "value" = true,
      "comment" = "an invisible dragon becomes visible when attacking the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ScalyCommandImmune",
      "value" = true,
      "comment" = "no scaly creature of the water willingly attacks a Scaly Command dragon, and all dragons are themselves immune to the power the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ScalyCommandNoSave",
      "value" = true,
      "comment" = "no saving throw against the Scaly Command - creatures already under one dragon cannot fall under another the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24WaterFireImmune",
      "value" = true,
      "comment" = "all Chinese dragons are immune to Water Fire - the unearthly stuff surrounds the body like the flame of a demon the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24TienWinglessFlight",
      "value" = true,
      "comment" = "the Tien Lung are wingless but can still fly - the Imperial Dragons frequent the same haunts as Silver Dragons the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ShenNoBreath",
      "value" = false,
      "comment" = "the Shen Lung have no breath weapon the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ShenLightningImmune",
      "value" = true,
      "comment" = "the Shen Lung take no damage from lightning the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ShenDoubleFire",
      "value" = true,
      "comment" = "the Shen Lung take double damage from fire - they love arsenic, bamboo and swallows the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24ShenPoisonImmune",
      "value" = true,
      "comment" = "the Shen Lung are immune to poison the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24LiQuakeImmune",
      "value" = true,
      "comment" = "the Li Lung are never harmed by any Earthquake though they may be inconvenienced by digging out of the rubble the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24LiHulkTunnel",
      "value" = true,
      "comment" = "the powerful claws of the Li Lung enable them to tunnel like Umber Hulks the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24PanGraspConstrict",
      "value" = true,
      "comment" = "the Pan Lung have no tail spike - the succeeding-turn grasp carries the automatic bite and the constrict the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24WangTribute",
      "value" = true,
      "comment" = "the Lung Wang rule large bodies of water and demand tribute from every passing ship the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24YuNoPolymorph",
      "value" = false,
      "comment" = "the Yu Lung cannot fly, polymorph or turn invisible the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24YuMetamorphosis",
      "value" = true,
      "comment" = "there are no older Yu Lung - they have achieved their hearts desire and metamorphosized into some other kind of Chinese dragon the Chinese dragons variant roster (print 8-9)",
    }, {
      "name" = "t24SevenInfectionTypes",
      "value" = true,
      "comment" = "several varieties of lycanthropy not covered before - the percentage dice rolled when the person is first bitten the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24TypeANewCharacter",
      "value" = true,
      "comment" = "the type A infected turns into the creature which hit him, mentally and physically, even his alignment changing the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24TypeBMentalOnly",
      "value" = true,
      "comment" = "the type B stays in human form with the lycanthrope mentality and lower intelligence - a type of insanity for curses the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24TypeCPhysicalOnly",
      "value" = true,
      "comment" = "the type C keeps his own mentality and gains the physical characteristics of the lycanthrope which bit him the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24MoonStressTypes",
      "value" = true,
      "comment" = "the types D E and F change only under a full moon or under great stress, like the type G the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24PartManPartMonster",
      "value" = true,
      "comment" = "the G change - a sort of part man part monster being, the general idea of the Incredible Hulk the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24AlignmentFixedFirst",
      "value" = true,
      "comment" = "the resulting alignment is discovered the first change and always remains the same unless the player changes his own the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24LawfulGoodChaoticEvil",
      "value" = true,
      "comment" = "if the creature is lawful it will be lawful good - if chaotic, chaotic evil the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24SeparateSheet",
      "value" = true,
      "comment" = "a separate character sheet attached to the regular one for the lycanthrope form the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24GFormAdvantage",
      "value" = true,
      "comment" = "the G type is actually an advantage when the alignments match - the creature is stronger and has more hitpoints the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24WerebearLawfulGood",
      "value" = true,
      "comment" = "the were-bear is the only lycanthrope which is ever lawful good - the servants and companions of good Wizards and patriarchs the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24ArmorSense",
      "value" = true,
      "comment" = "an odd sensation just before turning gives time to take off armor to keep it from getting wrecked the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24LevelStepsUnchanged",
      "value" = true,
      "comment" = "the level and experience of the player creature stay those of the player, going up in the same steps the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24LanguagesAutomatic",
      "value" = true,
      "comment" = "the creature automatically speaks its own language and any others the altered intelligence permits the lycanthropy infection variant (print 10-11)",
    }, {
      "name" = "t24DungeonmasterFinalWord",
      "value" = true,
      "comment" = "the Dungeonmaster can change these charts to fit his game as long as balance is maintained the lycanthropy infection variant (print 10-11)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "t24DragonTypes",
      "tag" = "Dg",
      "count" = "t24DragonTypeCount",
      "sentinel" = -99,
      "audit_comment" = "the Chinese dragon summary roster by print order - the Celestial Tien Lung through the Carp Yu Lung, number appearing, hit dice, armor class and the walk fly swim rates with the no-fly sentinel at the Lung Wang and Yu Lung rows",
      "cols" = { "t24DgAppearLo", "t24DgAppearHi", "t24DgHdLo", "t24DgHdHi", "t24DgAc", "t24DgWalk", "t24DgFly", "t24DgSwim" },
      "col_comments" = { "the appearing floor - solitary Tien Lung and Lung Wang, one to four for the rest", "the appearing ceiling - four for the common sorts", "the hit dice floor - five for the Carp, eleven for the two ruling sorts", "the hit dice ceiling - thirteen at the top, eight for the small Pan Lung", "the armor class - minus two for the Celestial, three for the Carp", "the walk rate - three for the sea brute, twelve for the marsh and river sorts", "the fly rate - forty-eight for the wingless Celestial, the sentinel for the Lung Wang and Yu Lung", "the swim rate - six for the Tien and Li, eighteen for the Carp" },
      "data" = { { 1, 1, 11, 13, -2, 9, 48, 6 }, { 1, 4, 9, 11, 1, 12, 12, 9 }, { 1, 4, 7, 9, 4, 9, 24, 6 }, { 1, 4, 6, 8, 2, 12, 12, 9 }, { 1, 1, 11, 13, 0, 3, -99, 9 }, { 1, 4, 5, 7, 3, 6, -99, 18 } },
    }, {
      "name" = "t24LycanBands",
      "tag" = "Ly",
      "count" = "t24LycanBandCount",
      "sentinel" = -99,
      "audit_comment" = "the infection dice-roll bands - the seven lycanthrope types A through G from the one-to-fifteen band through the seventy-one-to-double-nought read as one hundred",
      "cols" = { "t24LyLo", "t24LyHi" },
      "col_comments" = { "the band floor - one through the type A, twenty-six at the type D", "the band ceiling - fifty at D, sixty at E, seventy at F, one hundred at G" },
      "data" = { { 1, 15 }, { 16, 20 }, { 21, 25 }, { 26, 50 }, { 51, 60 }, { 61, 70 }, { 71, 100 } },
    }, {
      "name" = "t24LycanAlign",
      "tag" = "Al",
      "count" = "t24LycanAlignCount",
      "sentinel" = -99,
      "audit_comment" = "the alignment comparison matrix - the creature alignment against the player alignment, the lawful neutral chaotic percentage chances with the dashes pinned as zero, the lawful-chaotic crosses reading twenty sixty twenty both directions",
      "cols" = { "t24AlLawful", "t24AlNeutral", "t24AlChaotic" },
      "col_comments" = { "the lawful column - one hundred at the matched lawful row, forty-five where a neutral creature bites a lawful player", "the neutral column - one hundred at the matched neutral row, sixty at both lawful-chaotic crosses", "the chaotic column - one hundred at the matched chaotic row, forty-five where a neutral creature bites a chaotic player" },
      "data" = { { 100, 0, 0 }, { 60, 40, 0 }, { 20, 60, 20 }, { 45, 55, 0 }, { 0, 100, 0 }, { 0, 55, 45 }, { 20, 60, 20 }, { 0, 40, 60 }, { 0, 0, 100 } },
    }, {
      "name" = "t24LycanAttrs",
      "tag" = "At",
      "count" = "t24LycanAttrCount",
      "sentinel" = -99,
      "audit_comment" = "the attribute modifier table as printed - rat, wolf, boar, tiger and the duplicate Boar row which reads the bear line, the printed dashes pinned as zero, the conversion noted at the fifth row",
      "cols" = { "t24AtInt", "t24AtStr", "t24AtCon", "t24AtWis", "t24AtCha", "t24AtDex" },
      "col_comments" = { "the intelligence column - minus four for the boar, the rat and bear rows reading zero", "the strength column - plus six at the printed duplicate Boar row, plus five for the tiger", "the constitution column - plus five for the wolf, the bear justification printed at the note", "the wisdom column - minus four for the boar, minus three for the tiger", "the charisma column - minus five for the boar, minus three for the rat", "the dexterity column - plus four for the rat, plus three for the wolf" },
      "data" = { { 0, 0, 1, 0, -3, 4 }, { -1, 2, 5, -2, -3, 3 }, { -4, 4, 3, -4, -5, 1 }, { -3, 5, 4, -3, -4, 2 }, { -1, 6, 4, -1, -2, 0 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['t24LostCityRollHi']() != 3 or m['t24TyrantBandHi']() != 3 or m['t24TyrantWarriorAdd']() != 10 or m['t24PriestWarriorAdd']() != 5 or m['t24AtlantisSurvivors']() != 1",
      "note" = "the lost-city frame - the two-or-three discovery roll and the tyrant and priest organization counts the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "expr" = "m['t24ReactionAdd']() != 9 or m['t24GoddessReactionBonus']() != 1 or m['t24GuideReactionPenalty']() != 1 or m['t24AncientGreekSpeech']() != 1",
      "note" = "the reaction modifiers - the nine add, the goddess bonus one and the neighboring-guide penalty the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "expr" = "m['t24AskariKill']() != 1 or m['t24ExplorerKill']() != 2 or m['t24MissionaryKill']() != 1 or m['t24BearersFleeDivisor']() != 2 or m['t24SurpriseMuskets']() != 1",
      "note" = "the battle math - the musket kills, the Modified Gygax missionary rule and the bearers halved the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "expr" = "m['t24EscapeGold']() != 100 or m['t24EscapeDiamonds']() != 500 or m['t24TriumphDiamonds']() != 1000 or m['t24BearerGold']() != 200 or m['t24NovelistFee']() != 500 or m['t24DesertLootGems']() != 1000",
      "note" = "the treasure ladder - one hundred at the breakout, five hundred through the duel and volcano, one thousand at the triumph the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "expr" = "m['t24CurseDiePenalty']() != 2 or m['t24ReenterBonus']() != 1 or m['t24WifeBonus']() != 2 or m['t24UnderdogPoints']() != 5 or m['t24UnderdogStake']() != 700 or m['t24DesertCurseRides']() != 1",
      "note" = "the curse and return - the two-man penalty, the re-entry and wife bonuses and the Underdog saga the lost civilizations Source of the Nile variant (print 5-6)",
    }, {
      "expr" = "m['t24LairPct']() != 60 or m['t24PsionicClass']() != 6 or m['t24EspRadiusMult']() != 5 or m['t24OnlyYuSubduable']() != 1 or m['t24PowersByType']() != 1",
      "note" = "the general frame - the sixty percent lair, psionic class six and the five-times ESP radius the Chinese dragons variant roster (print 8-9)",
    }, {
      "expr" = "m['t24ScalyCommandHoursHi']() != 12 or m['t24ScalyCommandHoursLo']() != 2 or m['t24WaterFireRoundsHi']() != 120 or m['t24WaterFireRoundsLo']() != 20 or m['t24ScalyCommandImmune']() != 1 or m['t24WaterFireImmune']() != 1",
      "note" = "the shared powers - the Scaly Command duration and the Water Fire real-fire absence the Chinese dragons variant roster (print 8-9)",
    }, {
      "expr" = "m['t24TienFirePerDay']() != 6 or m['t24TienControlMult']() != 2 or m['t24TienServantPct']() != 50 or m['t24TienWinglessFlight']() != 1",
      "note" = "the Celestial sort - six fire cones a day, Control Weather at double the age level and the fifty percent servants the Chinese dragons variant roster (print 8-9)",
    }, {
      "expr" = "m['t24ShenSpellPerDay']() != 3 or m['t24ShenBiteHi']() != 24 or m['t24ShenWaterFireHi']() != 12 or m['t24ShenInsectRadius']() != 6 or m['t24ShenNoBreath']() != 0",
      "note" = "the river sort - the three spells, the two-to-twenty-four bite and the no-breath-weapon pin the Chinese dragons variant roster (print 8-9)",
    }, {
      "expr" = "m['t24LiQuakeMult']() != 3 or m['t24LiBiteHi']() != 20 or m['t24LiQuakeImmune']() != 1 or m['t24LiHulkTunnel']() != 1",
      "note" = "the earth sort - the tripled Earthquake and the Umber Hulk tunneling the Chinese dragons variant roster (print 8-9)",
    }, {
      "expr" = "m['t24PanConstrictHi']() != 12 or m['t24PanCharmPerDay']() != 3 or m['t24PanScalyHi']() != 10 or m['t24WangSteamPerDay']() != 3 or m['t24WangBiteHi']() != 36 or m['t24WangScalyHi']() != 40",
      "note" = "the coiled and sea sorts - the constrict, the Charm Monster and the steam and tribute brute the Chinese dragons variant roster (print 8-9)",
    }, {
      "expr" = "m['t24YuAdultCap']() != 5 or m['t24YuLandHour']() != 1 or m['t24YuMetamorphosis']() != 1 or m['t24YuNoPolymorph']() != 0",
      "note" = "the carp sort - the adult cap at five, the one-hour landfall and the metamorphosis the Chinese dragons variant roster (print 8-9)",
    }, {
      "expr" = "m['t24InfectionThresholdPct']() != 50 or m['t24OnsetAHi']() != 8 or m['t24OnsetBHi']() != 36 or m['t24OnsetCHi']() != 24 or m['t24SevenInfectionTypes']() != 1",
      "note" = "the infection frame - the fifty-percent threshold and the A B C onset bands the lycanthropy infection variant (print 10-11)",
    }, {
      "expr" = "m['t24OnsetDHi']() != 12 or m['t24OnsetEfHi']() != 16 or m['t24OnsetGHi']() != 10 or m['t24FormDurationHi']() != 12 or m['t24MoonStressTypes']() != 1",
      "note" = "the stress types - the D E F G onsets and the two-to-twelve-turn hold the lycanthropy infection variant (print 10-11)",
    }, {
      "expr" = "m['t24FullMoonPct']() != 95 or m['t24StressBasePct']() != 40 or m['t24PartManPartMonster']() != 1 or m['t24HalvedPowersDivisor']() != 2 or m['t24TypeGRatSummonHi']() != 50",
      "note" = "the G sort - the ninety-five percent full moon, the forty-percent stress base and the halved powers the lycanthropy infection variant (print 10-11)",
    }, {
      "expr" = "m['t24CureClericCLevel']() != 7 or m['t24CureClericGLevel']() != 8 or m['t24PoisonSaveExample']() != 9 or m['t24AlignmentFixedFirst']() != 1 or m['t24LawfulGoodChaoticEvil']() != 1",
      "note" = "the cures and the worked save - the seventh and eighth cleric levels and the nine needed in were-wolf form the lycanthropy infection variant (print 10-11)",
    }, {
      "expr" = "m['t24ShieldKeepPct']() != 10 or m['t24WerewolfShieldAc']() != 4 or m['t24DropSuppliesPct']() != 65 or m['t24DropTypeGPct']() != 40 or m['t24MaxLevelDivisor']() != 3 or m['t24WerebearLawfulGood']() != 1",
      "note" = "the equipment bookkeeping - the shield chance, the drop percentages and the max-level third the lycanthropy infection variant (print 10-11)",
    } },
  "audit" = {
      "label" = "R954 issue-24 variant triptych audit",
      "comment" = "the three-chain variant triptych audit - the lost civilizations supplement, the Chinese dragons roster and the lycanthropy infection types",
    },
}
