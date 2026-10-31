-- oa628: promoted from rules/oacharab.h (the THE CHARACTER ABILITIES, printed capture pp. 55-59 - the OA chapter opener);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 628,
  "prefix" = "oa628",
  "banner" = {
      "title" = "THE CHARACTER ABILITIES, printed capture pp. 55-59 - the OA chapter opener",
      "provenance" = "round census 550 -> 551.  verified against capture pp. 55-59 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). No contested cells this round - both captures agree on every pinned value. The T36 class column pins as the 1-6 code (bushi, kensai, ninja, barbarian, samurai, sohei); the printed \"and up\" bands pin as the -1 code; the attack rates pin as the numerator and denominator of the printed N/D notation. OCR normalization: \"lying and yang\" reads as yin and yang (prose only); \"human (or human)\" reads as the printed text (prose only); the ninja asterisk footnote appears twice in the second capture (the printed footnote stands)  the gap census after this round: 64 closed, 171 open - the Character Abilities, Multi-Class and Dual-Class, Alignment, Languages and Table 36 boxes flip (census 550 -> 551); NEXT - R629: the Chapter 3 opener, the birth rank prose and the caste doctrine, capture pp. 60-62, Table 37 (Birth Requirements by Class) and Table 38 (Character Birth), prefix dgp (verify free), audit \"R629 OA families audit\", include after rules/oacharab.h",
    },
  "consts" = { {
      "name" = "dgoT36RowCount",
      "value" = 19,
      "comment" = "Table 36 (capture p. 55): nineteen level-band rows",
    }, {
      "name" = "dgoDualOldClassReqMin",
      "value" = 15,
      "comment" = "Dual-class prose (capture p. 56): 15 or more in the prime requisites of the original class",
    }, {
      "name" = "dgoDualNewClassReqMin",
      "value" = 17,
      "comment" = "Dual-class prose (capture p. 56): 17 or 18 in the prime requisites of the new class",
    }, {
      "name" = "dgoAlignCount",
      "value" = 9,
      "comment" = "Alignment prose (capture p. 56): nine different alignments",
    }, {
      "name" = "dgoLangSlotHome",
      "value" = 1,
      "comment" = "Language prose (capture p. 59): the first slot is the home country language",
    }, {
      "name" = "dgoLangSlotTrade",
      "value" = 2,
      "comment" = "Language prose (capture p. 59): the second tongue is the trade language",
    }, {
      "name" = "dgoLangSlotAlignment",
      "value" = 3,
      "comment" = "Language prose (capture p. 59): the third slot is the alignment language",
    }, {
      "name" = "dgoLangDialectComprehension",
      "value" = 75,
      "comment" = "Language prose (capture p. 59): dialect speakers understand each other 75 percent of the time",
    }, {
      "name" = "dgoLangWildComprehension",
      "value" = 50,
      "comment" = "Language prose (capture p. 59): barbarian and wild-land dialect comprehension limited to 50 percent",
    }, {
      "name" = "dgoLangStudyMonthsBase",
      "value" = 20,
      "comment" = "Language prose (capture p. 59): study months with daily contact, 20 minus the Intelligence",
    } },
  "bools" = { {
      "name" = "dgoT36ExtendsBeyondFighters",
      "value" = true,
      "comment" = "Multiple attacks prose (capture p. 55): the ability extends beyond fighters and fighter sub-classes",
    }, {
      "name" = "dgoT36NinjaNinjaWeaponsOnly",
      "value" = true,
      "comment" = "Table 36 footnote (capture p. 55): ninja multiple attacks only with ninja weapons",
    }, {
      "name" = "dgoT36NinjaOtherClassNoCarry",
      "value" = true,
      "comment" = "Table 36 footnote (capture p. 55): the other class attack rate never applies to ninja weapons",
    }, {
      "name" = "dgoT36MeleeOnly",
      "value" = true,
      "comment" = "Multiple attacks prose (capture p. 55): the rates apply only to melee weapons, never missile",
    }, {
      "name" = "dgoT36ProficiencyIncreases",
      "value" = true,
      "comment" = "Multiple attacks prose (capture p. 55): proficiencies increase attacks with both melee and missile weapons",
    }, {
      "name" = "dgoT36OnePerLevelVsWeak",
      "value" = true,
      "comment" = "Multiple attacks prose (capture p. 55): versus monsters under 1 hit die, one melee attack per level",
    }, {
      "name" = "dgoT36SplitBetweenTargets",
      "value" = true,
      "comment" = "Multiple attacks prose (capture p. 55): multiple attacks divide between targets as the player sees fit",
    }, {
      "name" = "dgoDualHumanOnly",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): no non-human character can have more than one class",
    }, {
      "name" = "dgoDualAnyLevel",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): a character can become dual-class at any level",
    }, {
      "name" = "dgoDualKeepsOldAbilities",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): the old-class abilities are never lost",
    }, {
      "name" = "dgoDualNewClassFirstLevel",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): considered a 1st-level character in the new class",
    }, {
      "name" = "dgoDualXpToNewClass",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): all later experience applies to the new class",
    }, {
      "name" = "dgoDualNeverAdvanceOld",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): the old profession can never be advanced again",
    }, {
      "name" = "dgoDualNoHpUntilSurpass",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): no new hit points until the old-class level is surpassed",
    }, {
      "name" = "dgoDualRestrictionsUntilSurpass",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): the new-class restrictions bind until the old level is surpassed",
    }, {
      "name" = "dgoDualOldUseForfeitsXp",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): using an old-class ability forfeits the adventure experience",
    }, {
      "name" = "dgoDualBestTables",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): always the most advantageous combat and saving throw tables",
    }, {
      "name" = "dgoDualFreeMixAfterSurpass",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): the two classes mix freely after surpassing the old level",
    }, {
      "name" = "dgoDualWeaponsException",
      "value" = true,
      "comment" = "Dual-class prose (capture p. 56): any weapon of either class without restriction",
    }, {
      "name" = "dgoAlignNotReligion",
      "value" = true,
      "comment" = "Alignment prose (capture p. 56): alignment is not religion; differing alignments share one religion",
    }, {
      "name" = "dgoAlignLawMostCommon",
      "value" = true,
      "comment" = "Alignment prose (capture p. 57): law is by far the most common alignment in Kara-Tur",
    }, {
      "name" = "dgoAlignEncourageComplement",
      "value" = true,
      "comment" = "Alignment prose (capture p. 58): players encouraged to select complementary alignments",
    }, {
      "name" = "dgoLangPotentialOnly",
      "value" = true,
      "comment" = "Language prose (capture p. 58): the Table 5 count is the learnable potential, not the starting knowledge",
    }, {
      "name" = "dgoLangHomeCounts",
      "value" = true,
      "comment" = "Language prose (capture p. 59): the home language counts as one of the learnable languages",
    }, {
      "name" = "dgoLangSecondIsTrade",
      "value" = true,
      "comment" = "Language prose (capture p. 59): the second tongue is the trade language unless wholly isolated",
    }, {
      "name" = "dgoLangThirdIsAlignment",
      "value" = true,
      "comment" = "Language prose (capture p. 59): the third slot is the alignment language",
    }, {
      "name" = "dgoLangTradeBusinessOnly",
      "value" = true,
      "comment" = "Language prose (capture p. 59): the trade language suits business and common needs, few abstractions",
    }, {
      "name" = "dgoLangNonHumanSpecial",
      "value" = true,
      "comment" = "Language prose (capture p. 59): non-humans often speak additional specialized racial languages",
    }, {
      "name" = "dgoLangEveryOtherDayDoubles",
      "value" = true,
      "comment" = "Language prose (capture p. 59): seeing the teacher every other day doubles the study time",
    }, {
      "name" = "dgoLangNativeSpeakersHalve",
      "value" = true,
      "comment" = "Language prose (capture p. 59): living among native speakers halves the learning time",
    }, {
      "name" = "dgoLangAlwaysAccent",
      "value" = true,
      "comment" = "Language prose (capture p. 59): the student always retains a foreigner accent",
    }, {
      "name" = "dgoLangNuancesNativeOnly",
      "value" = true,
      "comment" = "Language prose (capture p. 59): only native speakers or the early-trained grasp every nuance",
    } },
  "switches" = { {
      "name" = "dgoT36Class",
      "values" = { 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6 },
      "default" = -99,
      "comment" = "the class column, pinned as the 1-6 code: bushi 1, kensai 2, ninja 3, barbarian 4, samurai 5, sohei 6 (capture p. 55).",
    }, {
      "name" = "dgoT36LevelLo",
      "values" = { 1, 6, 11, 1, 4, 8, 15, 1, 7, 15, 1, 7, 13, 1, 5, 9, 1, 7, 13 },
      "default" = -99,
      "comment" = "the level-band lower bound column (capture p. 55).",
    }, {
      "name" = "dgoT36LevelHi",
      "values" = { 5, 10, -1, 3, 7, 14, -1, 6, 14, -1, 6, 12, -1, 4, 8, -1, 6, 12, -1 },
      "default" = -99,
      "comment" = "the level-band upper bound column: the printed \"and up\" bands pin as the -1 code - bushi 11, kensai 15, ninja 15, barbarian 13, samurai 9, sohei 13 (capture p. 55).",
    }, {
      "name" = "dgoT36AtkNum",
      "values" = { 1, 3, 2, 1, 3, 2, 5, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2 },
      "default" = -99,
      "comment" = "the attacks numerator column: the first number of the printed N/D rate (capture p. 55).",
    }, {
      "name" = "dgoT36AtkDen",
      "values" = { 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1 },
      "default" = -99,
      "comment" = "the attacks denominator column: the melee rounds of the printed N/D rate - 1/1, 3/2, 2/1, kensai 5/2 (capture p. 55).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgoT36RowCount']() != 19  or m['dgoDualOldClassReqMin']() != 15  or m['dgoDualNewClassReqMin']() != 17  or m['dgoAlignCount']() != 9  or m['dgoLangSlotHome']() != 1  or m['dgoLangSlotTrade']() != 2  or m['dgoLangSlotAlignment']() != 3  or m['dgoLangDialectComprehension']() != 75  or m['dgoLangWildComprehension']() != 50  or m['dgoLangStudyMonthsBase']() != 20  or  m['dgoT36ExtendsBeyondFighters']() != 1  or  m['dgoT36NinjaNinjaWeaponsOnly']() != 1  or  m['dgoT36NinjaOtherClassNoCarry']() != 1  or  m['dgoT36MeleeOnly']() != 1  or  m['dgoT36ProficiencyIncreases']() != 1  or  m['dgoT36OnePerLevelVsWeak']() != 1  or  m['dgoT36SplitBetweenTargets']() != 1  or  m['dgoDualHumanOnly']() != 1  or  m['dgoDualAnyLevel']() != 1  or  m['dgoDualKeepsOldAbilities']() != 1  or  m['dgoDualNewClassFirstLevel']() != 1  or  m['dgoDualXpToNewClass']() != 1  or  m['dgoDualNeverAdvanceOld']() != 1  or  m['dgoDualNoHpUntilSurpass']() != 1  or  m['dgoDualRestrictionsUntilSurpass']() != 1  or  m['dgoDualOldUseForfeitsXp']() != 1  or  m['dgoDualBestTables']() != 1  or  m['dgoDualFreeMixAfterSurpass']() != 1  or  m['dgoDualWeaponsException']() != 1  or  m['dgoAlignNotReligion']() != 1  or  m['dgoAlignLawMostCommon']() != 1  or  m['dgoAlignEncourageComplement']() != 1  or  m['dgoLangPotentialOnly']() != 1  or  m['dgoLangHomeCounts']() != 1  or  m['dgoLangSecondIsTrade']() != 1  or  m['dgoLangThirdIsAlignment']() != 1  or  m['dgoLangTradeBusinessOnly']() != 1  or  m['dgoLangNonHumanSpecial']() != 1  or  m['dgoLangEveryOtherDayDoubles']() != 1  or  m['dgoLangNativeSpeakersHalve']() != 1  or  m['dgoLangAlwaysAccent']() != 1  or  m['dgoLangNuancesNativeOnly']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgoT36RowCount']() != 19",
      "note" = "the dgoT36RowCount pin",
    }, {
      "expr" = "m['dgoDualOldClassReqMin']() != 15",
      "note" = "the dgoDualOldClassReqMin pin",
    }, {
      "expr" = "m['dgoDualNewClassReqMin']() != 17",
      "note" = "the dgoDualNewClassReqMin pin",
    }, {
      "expr" = "m['dgoAlignCount']() != 9",
      "note" = "the dgoAlignCount pin",
    }, {
      "expr" = "m['dgoLangSlotHome']() != 1",
      "note" = "the dgoLangSlotHome pin",
    }, {
      "expr" = "m['dgoLangSlotTrade']() != 2",
      "note" = "the dgoLangSlotTrade pin",
    }, {
      "expr" = "m['dgoLangSlotAlignment']() != 3",
      "note" = "the dgoLangSlotAlignment pin",
    }, {
      "expr" = "m['dgoLangDialectComprehension']() != 75",
      "note" = "the dgoLangDialectComprehension pin",
    }, {
      "expr" = "m['dgoLangWildComprehension']() != 50",
      "note" = "the dgoLangWildComprehension pin",
    }, {
      "expr" = "m['dgoLangStudyMonthsBase']() != 20",
      "note" = "the dgoLangStudyMonthsBase pin",
    }, {
      "expr" = "m['dgoT36ExtendsBeyondFighters']() != 1",
      "note" = "the dgoT36ExtendsBeyondFighters pin",
    }, {
      "expr" = "m['dgoT36NinjaNinjaWeaponsOnly']() != 1",
      "note" = "the dgoT36NinjaNinjaWeaponsOnly pin",
    }, {
      "expr" = "m['dgoT36NinjaOtherClassNoCarry']() != 1",
      "note" = "the dgoT36NinjaOtherClassNoCarry pin",
    }, {
      "expr" = "m['dgoT36MeleeOnly']() != 1",
      "note" = "the dgoT36MeleeOnly pin",
    }, {
      "expr" = "m['dgoT36ProficiencyIncreases']() != 1",
      "note" = "the dgoT36ProficiencyIncreases pin",
    }, {
      "expr" = "m['dgoT36OnePerLevelVsWeak']() != 1",
      "note" = "the dgoT36OnePerLevelVsWeak pin",
    }, {
      "expr" = "m['dgoT36SplitBetweenTargets']() != 1",
      "note" = "the dgoT36SplitBetweenTargets pin",
    }, {
      "expr" = "m['dgoDualHumanOnly']() != 1",
      "note" = "the dgoDualHumanOnly pin",
    }, {
      "expr" = "m['dgoDualAnyLevel']() != 1",
      "note" = "the dgoDualAnyLevel pin",
    }, {
      "expr" = "m['dgoDualKeepsOldAbilities']() != 1",
      "note" = "the dgoDualKeepsOldAbilities pin",
    }, {
      "expr" = "m['dgoDualNewClassFirstLevel']() != 1",
      "note" = "the dgoDualNewClassFirstLevel pin",
    }, {
      "expr" = "m['dgoDualXpToNewClass']() != 1",
      "note" = "the dgoDualXpToNewClass pin",
    }, {
      "expr" = "m['dgoDualNeverAdvanceOld']() != 1",
      "note" = "the dgoDualNeverAdvanceOld pin",
    }, {
      "expr" = "m['dgoDualNoHpUntilSurpass']() != 1",
      "note" = "the dgoDualNoHpUntilSurpass pin",
    }, {
      "expr" = "m['dgoDualRestrictionsUntilSurpass']() != 1",
      "note" = "the dgoDualRestrictionsUntilSurpass pin",
    }, {
      "expr" = "m['dgoDualOldUseForfeitsXp']() != 1",
      "note" = "the dgoDualOldUseForfeitsXp pin",
    }, {
      "expr" = "m['dgoDualBestTables']() != 1",
      "note" = "the dgoDualBestTables pin",
    }, {
      "expr" = "m['dgoDualFreeMixAfterSurpass']() != 1",
      "note" = "the dgoDualFreeMixAfterSurpass pin",
    }, {
      "expr" = "m['dgoDualWeaponsException']() != 1",
      "note" = "the dgoDualWeaponsException pin",
    }, {
      "expr" = "m['dgoAlignNotReligion']() != 1",
      "note" = "the dgoAlignNotReligion pin",
    }, {
      "expr" = "m['dgoAlignLawMostCommon']() != 1",
      "note" = "the dgoAlignLawMostCommon pin",
    }, {
      "expr" = "m['dgoAlignEncourageComplement']() != 1",
      "note" = "the dgoAlignEncourageComplement pin",
    }, {
      "expr" = "m['dgoLangPotentialOnly']() != 1",
      "note" = "the dgoLangPotentialOnly pin",
    }, {
      "expr" = "m['dgoLangHomeCounts']() != 1",
      "note" = "the dgoLangHomeCounts pin",
    }, {
      "expr" = "m['dgoLangSecondIsTrade']() != 1",
      "note" = "the dgoLangSecondIsTrade pin",
    }, {
      "expr" = "m['dgoLangThirdIsAlignment']() != 1",
      "note" = "the dgoLangThirdIsAlignment pin",
    }, {
      "expr" = "m['dgoLangTradeBusinessOnly']() != 1",
      "note" = "the dgoLangTradeBusinessOnly pin",
    }, {
      "expr" = "m['dgoLangNonHumanSpecial']() != 1",
      "note" = "the dgoLangNonHumanSpecial pin",
    }, {
      "expr" = "m['dgoLangEveryOtherDayDoubles']() != 1",
      "note" = "the dgoLangEveryOtherDayDoubles pin",
    }, {
      "expr" = "m['dgoLangNativeSpeakersHalve']() != 1",
      "note" = "the dgoLangNativeSpeakersHalve pin",
    }, {
      "expr" = "m['dgoLangAlwaysAccent']() != 1",
      "note" = "the dgoLangAlwaysAccent pin",
    }, {
      "expr" = "m['dgoLangNuancesNativeOnly']() != 1",
      "note" = "the dgoLangNuancesNativeOnly pin",
    }, {
      "expr" = "m['dgoT36Class'](0) != 1  or m['dgoT36LevelLo'](0) != 1  or m['dgoT36LevelHi'](0) != 5  or m['dgoT36AtkNum'](0) != 1  or m['dgoT36AtkDen'](0) != 1",
      "note" = "the T36 first row - bushi 1-5, one attack per round (capture p. 55)",
    }, {
      "expr" = "m['dgoT36Class'](2) != 1  or m['dgoT36LevelHi'](2) != -1  or m['dgoT36AtkNum'](2) != 2  or m['dgoT36AtkDen'](2) != 1",
      "note" = "the T36 bushi capstone - 11 and up, 2/1, the -1 unbounded code (capture p. 55)",
    }, {
      "expr" = "m['dgoT36AtkNum'](3) != 1  or m['dgoT36AtkNum'](4) != 3  or m['dgoT36AtkDen'](4) != 2  or m['dgoT36AtkNum'](5) != 2",
      "note" = "the T36 kensai ladder - 1-3 at 1/1, 4-7 at 3/2, 8-14 at 2/1 (capture p. 55)",
    }, {
      "expr" = "m['dgoT36Class'](6) != 2  or m['dgoT36LevelHi'](6) != -1  or m['dgoT36AtkNum'](6) != 5  or m['dgoT36AtkDen'](6) != 2",
      "note" = "the T36 kensai capstone - 15 and up, the printed 5/2 (capture p. 55)",
    }, {
      "expr" = "m['dgoT36Class'](7) != 3  or m['dgoT36LevelHi'](7) != 6  or m['dgoT36AtkNum'](8) != 3  or m['dgoT36LevelLo'](9) != 15  or m['dgoT36AtkDen'](9) != 1",
      "note" = "the T36 ninja bands - 1-6 at 1/1, 7-14 at 3/2, 15 and up at 2/1 (capture p. 55)",
    }, {
      "expr" = "m['dgoT36Class'](10) != 4  or m['dgoT36LevelHi'](11) != 12  or m['dgoT36LevelLo'](12) != 13  or m['dgoT36AtkNum'](12) != 2",
      "note" = "the T36 barbarian bands - 1-6, 7-12, 13 and up (capture p. 55)",
    }, {
      "expr" = "m['dgoT36Class'](13) != 5  or m['dgoT36LevelHi'](13) != 4  or m['dgoT36LevelLo'](14) != 5  or m['dgoT36LevelHi'](15) != -1",
      "note" = "the T36 samurai bands - 1-4, 5-8, 9 and up (capture p. 55)",
    }, {
      "expr" = "m['dgoT36Class'](16) != 6  or m['dgoT36LevelHi'](17) != 12  or m['dgoT36LevelHi'](18) != -1  or m['dgoT36AtkNum'](18) != 2  or m['dgoT36RowCount']() != 19",
      "note" = "the T36 sohei bands - 1-6, 7-12, 13 and up, nineteen rows only (capture p. 55)",
    }, {
      "expr" = "m['dgoDualOldClassReqMin']() != 15  or m['dgoDualNewClassReqMin']() != 17",
      "note" = "the dual-class minima pair - 15 in the old requisites, 17 or 18 in the new (capture p. 56)",
    }, {
      "expr" = "m['dgoAlignCount']() != 9",
      "note" = "the alignment count - nine alignments (capture p. 56)",
    }, {
      "expr" = "m['dgoLangSlotHome']() != 1  or m['dgoLangSlotTrade']() != 2  or m['dgoLangSlotAlignment']() != 3",
      "note" = "the language slot ladder - home, trade, alignment (capture p. 59)",
    }, {
      "expr" = "m['dgoLangDialectComprehension']() != 75  or m['dgoLangWildComprehension']() != 50",
      "note" = "the comprehension pair - 75 percent between dialects, 50 in the wild lands (capture p. 59)",
    }, {
      "expr" = "m['dgoLangStudyMonthsBase']() != 20  or m['dgoLangStudyMonthsBase']() - 15 != 5",
      "note" = "the study doctrine - 20 minus Intelligence months, Int 15 means five months (capture p. 59)",
    } },
  "audit" = {
      "label" = "R628 OA character abilities audit",
      "comment" = "OA round fifteen (capture pp. 55-59): the character abilities chapter opener - the multiple attacks, the dual-class doctrine, the alignment doctrine and the languages",
    },
}
