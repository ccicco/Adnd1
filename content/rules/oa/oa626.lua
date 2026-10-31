-- oa626: promoted from rules/oawujen.h (the THE WU JEN, printed capture pp. 47-51 - the OA wu jen round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 626,
  "prefix" = "oa626",
  "banner" = {
      "title" = "THE WU JEN, printed capture pp. 47-51 - the OA wu jen round",
      "provenance" = "census 548 -> 549.  verified against capture pp. 47-51 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). Three cells settled against the 2018 print BEFORE pinning, per the settling doctrine: the T31 row-2 bound (the capture lost the comma - 4,000); the T33 row-5 first-spell cell (the capture prints 4, the 2018 prints 3, the ladder-consistent reading stands); the T33 row-22 ninth-spell cell (the capture prints 2, the 2018 prints 1, the ladder-consistent reading stands). The T32 All maximum pins as the -1 code; the T33 dashes pin as zeros. OCR normalization: konobokuru reads as korobokuru; in hit, spell book reads as in his spell book; cloud/adder reads as cloud ladder (prose only)  the gap census after this round: 56 closed, 179 open - the wu jen boxes with Tables 31, 32 and 33 flip (census 548 -> 549); NEXT - R627: the Yakuza, capture pp. 51-54, Tables 34 and 35, prefix dgn (verify free), audit \"R627 OA yakuza audit\", include after rules/oawujen.h",
    },
  "consts" = { {
      "name" = "dgmWuJenMinInt",
      "value" = 13,
      "comment" = "Wu jen prose (capture p. 48): the Intelligence minimum",
    }, {
      "name" = "dgmWuJenBonusInt",
      "value" = 15,
      "comment" = "Wu jen prose (capture p. 48): Intelligence 15 or greater earns the 10 percent experience bonus",
    }, {
      "name" = "dgmWuJenBonusPct",
      "value" = 10,
      "comment" = "Wu jen prose (capture p. 48): the bonus value",
    }, {
      "name" = "dgmWuJenHitDie",
      "value" = 4,
      "comment" = "Wu jen prose (capture p. 48): the 4-sided hit die, one per level",
    }, {
      "name" = "dgmWuJenHpBonusPerDie",
      "value" = 1,
      "comment" = "Wu jen prose (capture p. 48): the automatic +1 hit point bonus per die, 2-5 per level",
    }, {
      "name" = "dgmWuJenHpPerLevelMin",
      "value" = 2,
      "comment" = "Wu jen prose (capture p. 48): the 2-5 hit points per level lower bound",
    }, {
      "name" = "dgmWuJenHpPerLevelMax",
      "value" = 5,
      "comment" = "Wu jen prose (capture p. 48): the 2-5 upper bound",
    }, {
      "name" = "dgmWuJenFavoredBonus",
      "value" = 1,
      "comment" = "Wu jen prose (capture p. 48): the favored weapon earns +1 to hit",
    }, {
      "name" = "dgmWuJenSlots",
      "value" = 6,
      "comment" = "Wu jen prose (capture p. 48): six proficiency slots at the beginning",
    }, {
      "name" = "dgmWuJenKiInitBonus",
      "value" = 3,
      "comment" = "Wu jen prose (capture p. 50): the ki burst gives +3 on the initiative roll",
    }, {
      "name" = "dgmWuJenKiInitRounds",
      "value" = 1,
      "comment" = "Wu jen prose (capture p. 50): the ki burst lasts one round",
    }, {
      "name" = "dgmWuJenKiInitPerDay",
      "value" = 1,
      "comment" = "Wu jen prose (capture p. 50): the ki burst once per day",
    }, {
      "name" = "dgmWuJenKiMaxEffectLevel",
      "value" = 4,
      "comment" = "Wu jen prose (capture p. 50): the second ki power at 4th level - maximum effect",
    }, {
      "name" = "dgmWuJenKiMaxEffectGap",
      "value" = 3,
      "comment" = "Wu jen prose (capture p. 50): any one spell three or more levels lower than the wu jen level, at maximum effect",
    }, {
      "name" = "dgmWuJenElementCount",
      "value" = 5,
      "comment" = "Wu jen prose (capture p. 50): five elemental groups - earth/metal, water, fire, wind and wood/nature",
    }, {
      "name" = "dgmWuJenMasterEnemySaveMod",
      "value" = -1,
      "comment" = "Wu jen prose (capture p. 50): the element master casts with a -1 saving throw modifier against the enemies",
    }, {
      "name" = "dgmWuJenMasterDamageBonus",
      "value" = 1,
      "comment" = "Wu jen prose (capture p. 50): the element master gains +1 to all damage of that element",
    }, {
      "name" = "dgmWuJenMasterSaveBonus",
      "value" = 1,
      "comment" = "Wu jen prose (capture p. 50): the element master gains +1 on saves versus spells of that element",
    }, {
      "name" = "dgmWuJenPupilLevel",
      "value" = 10,
      "comment" = "Wu jen prose (capture p. 50): the 1d4 pupils attracted at 10th level",
    }, {
      "name" = "dgmWuJenPupilDice",
      "value" = 4,
      "comment" = "Wu jen prose (capture p. 50): the pupil die",
    }, {
      "name" = "dgmWuJenPupilLeaveDiv",
      "value" = 2,
      "comment" = "Wu jen prose (capture p. 50): the pupils leave at a level equal to one-half their master level, each replaced by a new 1st-level seeker",
    }, {
      "name" = "dgmWuJenTenguOniReaction",
      "value" = 20,
      "comment" = "Wu jen prose (capture p. 51): the +20 percent reaction modifier with tengu and oni",
    }, {
      "name" = "dgmWuJenTabooFirstLevel",
      "value" = 1,
      "comment" = "Wu jen prose (capture p. 51): one taboo at 1st level",
    }, {
      "name" = "dgmWuJenTabooStepLevels",
      "value" = 5,
      "comment" = "Wu jen prose (capture p. 51): an additional taboo upon gaining every five levels",
    }, {
      "name" = "dgmT31RowCount",
      "value" = 11,
      "comment" = "Table 31 (capture pp. 47-48): eleven rows, levels 1-11",
    }, {
      "name" = "dgmT31XpBeyond",
      "value" = 300000,
      "comment" = "Table 31 note (capture p. 48): 300,000 experience points are required for each level beyond 11th",
    }, {
      "name" = "dgmT31HpBeyond",
      "value" = 1,
      "comment" = "Table 31 note (capture p. 48): wu jen gain 1 hp per level beyond 9th",
    }, {
      "name" = "dgmT32RowCount",
      "value" = 7,
      "comment" = "Table 32 (capture p. 48): seven tier rows, Intelligence 9 through 19 or more",
    }, {
      "name" = "dgmT32MaxAll",
      "value" = -1,
      "comment" = "Table 32 (capture p. 48): the 19-or-more maximum reads All - pinned as the -1 code",
    }, {
      "name" = "dgmT33RowCount",
      "value" = 29,
      "comment" = "Table 33 (capture p. 49): twenty-nine rows, levels 1-29",
    }, {
      "name" = "dgmT33SpellLevels",
      "value" = 9,
      "comment" = "Table 33 (capture p. 49): nine spell-level columns, 1st through 9th",
    } },
  "bools" = { {
      "name" = "dgmWuJenNeverLawful",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 48): wu jen cannot be lawful",
    }, {
      "name" = "dgmWuJenRaces",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 48): human, korobokuru and hengeyokai can be wu jen",
    }, {
      "name" = "dgmWuJenMagicUserTables",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 48): the magic-user combat and saving throw tables",
    }, {
      "name" = "dgmWuJenNoArmor",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 48): cannot wear armor or use shields, limited to the Table 13 weapons",
    }, {
      "name" = "dgmWuJenUnderstandKnowMemorize",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 50): understanding, knowing and remembering are three different things - only study of the spell book lets him cast from memory",
    }, {
      "name" = "dgmWuJenIntLossRecheck",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 50): a lasting Intelligence loss forces a recheck of every understood spell against the new maximum; a gain allows new learning",
    }, {
      "name" = "dgmWuJenScrollDestroyed",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 50): new spells come from a teacher, another wu jen book or a scroll - the scroll is destroyed in learning",
    }, {
      "name" = "dgmWuJenMeditates",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 50): learns to meditate like a shukenja as part of the mental regimen",
    }, {
      "name" = "dgmWuJenMasterLostOnNewLevel",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 50): the element mastery is lost when a higher spell level becomes castable until all its spells are learned",
    }, {
      "name" = "dgmWuJenStrongholdWithLieutenant",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 50): no fighting men attracted - he hires them and must employ a lieutenant to command them",
    }, {
      "name" = "dgmWuJenTenguOniLanguage",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 51): wu jen speak the language of tengu and oni",
    }, {
      "name" = "dgmWuJenNoFamily",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 51): no Table 38 roll, no family bonuses or penalties",
    }, {
      "name" = "dgmWuJenLightHonor",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 51): integrity without the honor codes - bonuses and penalties of honor are much smaller",
    }, {
      "name" = "dgmWuJenTabooConsequences",
      "value" = true,
      "comment" = "Wu jen prose (capture p. 51): violating a taboo brings loss of spells, illness or other evil events; the DM may add similar taboos",
    } },
  "switches" = { {
      "name" = "dgmT31XpMax",
      "values" = { 2000, 4000, 8000, 18000, 36000, 65000, 100000, 140000, 280000, 600000, 800000 },
      "default" = -99,
      "comment" = "the experience column: the upper xp bound of each level, 2,000 at 1st to 800,000 at 11th - the row-2 bound OCR-mangled in the capture (4000 without the comma) and settled against the 2018 print (capture pp. 47-48).",
    }, {
      "name" = "dgmT31Dice",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9 },
      "default" = -99,
      "comment" = "the accumulated d4 dice column: one per level through 9th, then held at 9 (capture pp. 47-48).",
    }, {
      "name" = "dgmT31HpBonus",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2 },
      "default" = -99,
      "comment" = "the hit-point bonus column: the printed 9-plus-N cells - 1 hp per level beyond 9th: 0 through 9th, then 1, 2 (capture pp. 47-48).",
    }, {
      "name" = "dgmT32KnowPct",
      "values" = { 35, 45, 55, 65, 75, 85, 95 },
      "default" = -99,
      "comment" = "the chance to know each listed spell column: 35 percent at Int 9 climbing 10 per tier to 95 at 19 or more (capture p. 48).",
    }, {
      "name" = "dgmT32MinSpells",
      "values" = { 4, 5, 6, 7, 8, 9, 10 },
      "default" = -99,
      "comment" = "the minimum number of spells per level column: 4 at Int 9 to 10 at 19 or more (capture p. 48).",
    }, {
      "name" = "dgmT32MaxSpells",
      "values" = { 6, 7, 9, 11, 14, 18, -1 },
      "default" = -99,
      "comment" = "the maximum number of spells per level column: 6 at Int 9 to 18 at Int 18, then the printed All at 19 or more pinned as the -1 code (capture p. 48).",
    }, {
      "name" = "dgmT33S1",
      "values" = { 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9 },
      "default" = -99,
      "comment" = "the 1st-level spells column: 1 at 1st to 9 at 28th - the row-5 cell (level 5) is contested, the capture prints 4 and the 2018 print 3; the 2018 ladder-consistent reading stands (capture p. 49).",
    }, {
      "name" = "dgmT33S2",
      "values" = { 0, 0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9 },
      "default" = -99,
      "comment" = "the 2nd-level spells column: none until 3rd, then 1 to 9 at 29th (capture p. 49).",
    }, {
      "name" = "dgmT33S3",
      "values" = { 0, 0, 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8 },
      "default" = -99,
      "comment" = "the 3rd-level spells column: none until 5th, then 1 to 8 at 29th (capture p. 49).",
    }, {
      "name" = "dgmT33S4",
      "values" = { 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 8 },
      "default" = -99,
      "comment" = "the 4th-level spells column: none until 7th, then 1 to 8 at 29th (capture p. 49).",
    }, {
      "name" = "dgmT33S5",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7 },
      "default" = -99,
      "comment" = "the 5th-level spells column: none until 9th, then 1 to 7 at 29th (capture p. 49).",
    }, {
      "name" = "dgmT33S6",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7 },
      "default" = -99,
      "comment" = "the 6th-level spells column: none until 11th, then 1 to 7 at 29th (capture p. 49).",
    }, {
      "name" = "dgmT33S7",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5, 6 },
      "default" = -99,
      "comment" = "the 7th-level spells column: none until 13th, then 1 to 6 at 29th (capture p. 49).",
    }, {
      "name" = "dgmT33S8",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5 },
      "default" = -99,
      "comment" = "the 8th-level spells column: none until 17th, then 1 to 5 at 29th (capture p. 49).",
    }, {
      "name" = "dgmT33S9",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4 },
      "default" = -99,
      "comment" = "the 9th-level spells column: none until 21st, then 1 to 4 at 29th - the row-22 cell (level 22) is contested, the capture prints 2 and the 2018 print 1; the 2018 ladder-consistent reading stands (capture p. 49).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgmWuJenMinInt']() != 13  or m['dgmWuJenBonusInt']() != 15  or m['dgmWuJenBonusPct']() != 10  or m['dgmWuJenHitDie']() != 4  or m['dgmWuJenHpBonusPerDie']() != 1  or m['dgmWuJenHpPerLevelMin']() != 2  or m['dgmWuJenHpPerLevelMax']() != 5  or m['dgmWuJenSlots']() != 6  or m['dgmWuJenFavoredBonus']() != 1  or m['dgmWuJenKiInitBonus']() != 3  or m['dgmWuJenKiInitRounds']() != 1  or m['dgmWuJenKiInitPerDay']() != 1  or m['dgmWuJenKiMaxEffectLevel']() != 4  or m['dgmWuJenKiMaxEffectGap']() != 3  or m['dgmWuJenElementCount']() != 5  or m['dgmWuJenMasterEnemySaveMod']() != -1  or m['dgmWuJenMasterDamageBonus']() != 1  or m['dgmWuJenMasterSaveBonus']() != 1  or m['dgmWuJenPupilLevel']() != 10  or m['dgmWuJenPupilDice']() != 4  or m['dgmWuJenPupilLeaveDiv']() != 2  or m['dgmWuJenTenguOniReaction']() != 20  or m['dgmWuJenTabooFirstLevel']() != 1  or m['dgmWuJenTabooStepLevels']() != 5  or m['dgmT31RowCount']() != 11  or m['dgmT31XpBeyond']() != 300000  or m['dgmT31HpBeyond']() != 1  or m['dgmT32RowCount']() != 7  or m['dgmT32MaxAll']() != -1  or m['dgmT33RowCount']() != 29  or m['dgmT33SpellLevels']() != 9  or  m['dgmWuJenNeverLawful']() != 1  or  m['dgmWuJenRaces']() != 1  or  m['dgmWuJenMagicUserTables']() != 1  or  m['dgmWuJenNoArmor']() != 1  or  m['dgmWuJenMeditates']() != 1  or  m['dgmWuJenUnderstandKnowMemorize']() != 1  or  m['dgmWuJenIntLossRecheck']() != 1  or  m['dgmWuJenScrollDestroyed']() != 1  or  m['dgmWuJenMasterLostOnNewLevel']() != 1  or  m['dgmWuJenStrongholdWithLieutenant']() != 1  or  m['dgmWuJenTenguOniLanguage']() != 1  or  m['dgmWuJenNoFamily']() != 1  or  m['dgmWuJenLightHonor']() != 1  or  m['dgmWuJenTabooConsequences']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgmWuJenMinInt']() != 13",
      "note" = "the dgmWuJenMinInt pin",
    }, {
      "expr" = "m['dgmWuJenBonusInt']() != 15",
      "note" = "the dgmWuJenBonusInt pin",
    }, {
      "expr" = "m['dgmWuJenBonusPct']() != 10",
      "note" = "the dgmWuJenBonusPct pin",
    }, {
      "expr" = "m['dgmWuJenHitDie']() != 4",
      "note" = "the dgmWuJenHitDie pin",
    }, {
      "expr" = "m['dgmWuJenHpBonusPerDie']() != 1",
      "note" = "the dgmWuJenHpBonusPerDie pin",
    }, {
      "expr" = "m['dgmWuJenHpPerLevelMin']() != 2",
      "note" = "the dgmWuJenHpPerLevelMin pin",
    }, {
      "expr" = "m['dgmWuJenHpPerLevelMax']() != 5",
      "note" = "the dgmWuJenHpPerLevelMax pin",
    }, {
      "expr" = "m['dgmWuJenSlots']() != 6",
      "note" = "the dgmWuJenSlots pin",
    }, {
      "expr" = "m['dgmWuJenFavoredBonus']() != 1",
      "note" = "the dgmWuJenFavoredBonus pin",
    }, {
      "expr" = "m['dgmWuJenKiInitBonus']() != 3",
      "note" = "the dgmWuJenKiInitBonus pin",
    }, {
      "expr" = "m['dgmWuJenKiInitRounds']() != 1",
      "note" = "the dgmWuJenKiInitRounds pin",
    }, {
      "expr" = "m['dgmWuJenKiInitPerDay']() != 1",
      "note" = "the dgmWuJenKiInitPerDay pin",
    }, {
      "expr" = "m['dgmWuJenKiMaxEffectLevel']() != 4",
      "note" = "the dgmWuJenKiMaxEffectLevel pin",
    }, {
      "expr" = "m['dgmWuJenKiMaxEffectGap']() != 3",
      "note" = "the dgmWuJenKiMaxEffectGap pin",
    }, {
      "expr" = "m['dgmWuJenElementCount']() != 5",
      "note" = "the dgmWuJenElementCount pin",
    }, {
      "expr" = "m['dgmWuJenMasterEnemySaveMod']() != -1",
      "note" = "the dgmWuJenMasterEnemySaveMod pin",
    }, {
      "expr" = "m['dgmWuJenMasterDamageBonus']() != 1",
      "note" = "the dgmWuJenMasterDamageBonus pin",
    }, {
      "expr" = "m['dgmWuJenMasterSaveBonus']() != 1",
      "note" = "the dgmWuJenMasterSaveBonus pin",
    }, {
      "expr" = "m['dgmWuJenPupilLevel']() != 10",
      "note" = "the dgmWuJenPupilLevel pin",
    }, {
      "expr" = "m['dgmWuJenPupilDice']() != 4",
      "note" = "the dgmWuJenPupilDice pin",
    }, {
      "expr" = "m['dgmWuJenPupilLeaveDiv']() != 2",
      "note" = "the dgmWuJenPupilLeaveDiv pin",
    }, {
      "expr" = "m['dgmWuJenTenguOniReaction']() != 20",
      "note" = "the dgmWuJenTenguOniReaction pin",
    }, {
      "expr" = "m['dgmWuJenTabooFirstLevel']() != 1",
      "note" = "the dgmWuJenTabooFirstLevel pin",
    }, {
      "expr" = "m['dgmWuJenTabooStepLevels']() != 5",
      "note" = "the dgmWuJenTabooStepLevels pin",
    }, {
      "expr" = "m['dgmT31RowCount']() != 11",
      "note" = "the dgmT31RowCount pin",
    }, {
      "expr" = "m['dgmT31XpBeyond']() != 300000",
      "note" = "the dgmT31XpBeyond pin",
    }, {
      "expr" = "m['dgmT31HpBeyond']() != 1",
      "note" = "the dgmT31HpBeyond pin",
    }, {
      "expr" = "m['dgmT32RowCount']() != 7",
      "note" = "the dgmT32RowCount pin",
    }, {
      "expr" = "m['dgmT32MaxAll']() != -1",
      "note" = "the dgmT32MaxAll pin",
    }, {
      "expr" = "m['dgmT33RowCount']() != 29",
      "note" = "the dgmT33RowCount pin",
    }, {
      "expr" = "m['dgmT33SpellLevels']() != 9",
      "note" = "the dgmT33SpellLevels pin",
    }, {
      "expr" = "m['dgmWuJenNeverLawful']() != 1",
      "note" = "the dgmWuJenNeverLawful pin",
    }, {
      "expr" = "m['dgmWuJenRaces']() != 1",
      "note" = "the dgmWuJenRaces pin",
    }, {
      "expr" = "m['dgmWuJenMagicUserTables']() != 1",
      "note" = "the dgmWuJenMagicUserTables pin",
    }, {
      "expr" = "m['dgmWuJenNoArmor']() != 1",
      "note" = "the dgmWuJenNoArmor pin",
    }, {
      "expr" = "m['dgmWuJenMeditates']() != 1",
      "note" = "the dgmWuJenMeditates pin",
    }, {
      "expr" = "m['dgmWuJenUnderstandKnowMemorize']() != 1",
      "note" = "the dgmWuJenUnderstandKnowMemorize pin",
    }, {
      "expr" = "m['dgmWuJenIntLossRecheck']() != 1",
      "note" = "the dgmWuJenIntLossRecheck pin",
    }, {
      "expr" = "m['dgmWuJenScrollDestroyed']() != 1",
      "note" = "the dgmWuJenScrollDestroyed pin",
    }, {
      "expr" = "m['dgmWuJenMasterLostOnNewLevel']() != 1",
      "note" = "the dgmWuJenMasterLostOnNewLevel pin",
    }, {
      "expr" = "m['dgmWuJenStrongholdWithLieutenant']() != 1",
      "note" = "the dgmWuJenStrongholdWithLieutenant pin",
    }, {
      "expr" = "m['dgmWuJenTenguOniLanguage']() != 1",
      "note" = "the dgmWuJenTenguOniLanguage pin",
    }, {
      "expr" = "m['dgmWuJenNoFamily']() != 1",
      "note" = "the dgmWuJenNoFamily pin",
    }, {
      "expr" = "m['dgmWuJenLightHonor']() != 1",
      "note" = "the dgmWuJenLightHonor pin",
    }, {
      "expr" = "m['dgmWuJenTabooConsequences']() != 1",
      "note" = "the dgmWuJenTabooConsequences pin",
    }, {
      "expr" = "m['dgmT31XpMax'](0) != 2000  or m['dgmT31Dice'](0) != 1  or m['dgmT31HpBonus'](0) != 0",
      "note" = "the T31 first row - 2,000 xp, one die (capture p. 47)",
    }, {
      "expr" = "m['dgmT31XpMax'](1) != 4000  or m['dgmT31XpMax'](2) != 8000",
      "note" = "the T31 row-2 bound settled at 4,000 - the capture lost the comma (capture pp. 47-48)",
    }, {
      "expr" = "m['dgmT31XpMax'](10) != 800000  or m['dgmT31Dice'](10) != 9  or m['dgmT31HpBonus'](10) != 2",
      "note" = "the T31 capstone - 800,000 xp, nine dice plus two, eleven rows only (capture p. 48)",
    }, {
      "expr" = "m['dgmT32KnowPct'](0) != 35  or m['dgmT32KnowPct'](3) != 65  or m['dgmT32MinSpells'](3) != 7  or m['dgmT32MaxSpells'](3) != 11",
      "note" = "the T32 ladder - 35 percent at Int 9, the 7-and-11 Hideyori tier (capture pp. 48, 50)",
    }, {
      "expr" = "m['dgmT32KnowPct'](6) != 95  or m['dgmT32MaxSpells'](6) !=m['dgmT32MaxAll']()",
      "note" = "the T32 All maximum - the 19-or-more row pins as the -1 code (capture p. 48)",
    }, {
      "expr" = "m['dgmT33S1'](4) != 3  or m['dgmT33S1'](5) != 4",
      "note" = "the T33 row-5 cell settled - three 1st-level spells at 5th, the capture printed 4 (capture p. 49)",
    }, {
      "expr" = "m['dgmT33S9'](20) != 1  or m['dgmT33S9'](21) != 1  or m['dgmT33S9'](22) != 2",
      "note" = "the T33 row-22 cell settled - one 9th-level spell at 22nd, the capture printed 2 (capture p. 49)",
    }, {
      "expr" = "m['dgmT33S3'](4) != 1  or m['dgmT33S5'](8) != 1  or m['dgmT33S9'](20) != 1",
      "note" = "the T33 openings - the 3rd at 5th, the 5th at 9th, the 9th at 21st (capture p. 49)",
    }, {
      "expr" = "m['dgmT33S1'](28) != 9  or m['dgmT33S6'](28) != 7  or m['dgmT33S9'](28) != 4",
      "note" = "the T33 capstone - the 29th-level row (capture p. 49)",
    }, {
      "expr" = "m['dgmWuJenKiMaxEffectLevel']() -m['dgmWuJenKiMaxEffectGap']() != 1",
      "note" = "the maximum-effect ki - a 4th-level wu jen casts a 1st-level spell at maximum effect, the gap is three levels (capture p. 50)",
    }, {
      "expr" = "m['dgmWuJenTabooFirstLevel']() != 1  or m['dgmWuJenTabooStepLevels']() != 5",
      "note" = "the taboo ladder - one at 1st, another per five levels (capture p. 51)",
    }, {
      "expr" = "m['dgmT33S2'](0) != 0 or m['dgmT33S2'](1) != 0 or m['dgmT33S2'](2) != 1 or m['dgmT33S2'](3) != 2 or m['dgmT33S2'](4) != 2 or m['dgmT33S2'](5) != 2 or m['dgmT33S2'](6) != 3 or m['dgmT33S2'](7) != 3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S2'](8) != 3 or m['dgmT33S2'](9) != 4 or m['dgmT33S2'](10) != 4 or m['dgmT33S2'](11) != 5 or m['dgmT33S2'](12) != 5 or m['dgmT33S2'](13) != 5 or m['dgmT33S2'](14) != 5 or m['dgmT33S2'](15) != 6",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S2'](16) != 6 or m['dgmT33S2'](17) != 6 or m['dgmT33S2'](18) != 6 or m['dgmT33S2'](19) != 6 or m['dgmT33S2'](20) != 6 or m['dgmT33S2'](21) != 7 or m['dgmT33S2'](22) != 7 or m['dgmT33S2'](23) != 7",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S2'](24) != 7 or m['dgmT33S2'](25) != 8 or m['dgmT33S2'](26) != 8 or m['dgmT33S2'](27) != 8 or m['dgmT33S2'](28) != 9 or m['dgmT33S2'](29) != -99 or m['dgmT33S4'](0) != 0 or m['dgmT33S4'](1) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S4'](2) != 0 or m['dgmT33S4'](3) != 0 or m['dgmT33S4'](4) != 0 or m['dgmT33S4'](5) != 0 or m['dgmT33S4'](6) != 1 or m['dgmT33S4'](7) != 2 or m['dgmT33S4'](8) != 2 or m['dgmT33S4'](9) != 2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S4'](10) != 2 or m['dgmT33S4'](11) != 2 or m['dgmT33S4'](12) != 4 or m['dgmT33S4'](13) != 4 or m['dgmT33S4'](14) != 4 or m['dgmT33S4'](15) != 4 or m['dgmT33S4'](16) != 5 or m['dgmT33S4'](17) != 5",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S4'](18) != 5 or m['dgmT33S4'](19) != 5 or m['dgmT33S4'](20) != 6 or m['dgmT33S4'](21) != 6 or m['dgmT33S4'](22) != 6 or m['dgmT33S4'](23) != 6 or m['dgmT33S4'](24) != 6 or m['dgmT33S4'](25) != 7",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S4'](26) != 7 or m['dgmT33S4'](27) != 7 or m['dgmT33S4'](28) != 8 or m['dgmT33S4'](29) != -99 or m['dgmT33S7'](0) != 0 or m['dgmT33S7'](1) != 0 or m['dgmT33S7'](2) != 0 or m['dgmT33S7'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S7'](4) != 0 or m['dgmT33S7'](5) != 0 or m['dgmT33S7'](6) != 0 or m['dgmT33S7'](7) != 0 or m['dgmT33S7'](8) != 0 or m['dgmT33S7'](9) != 0 or m['dgmT33S7'](10) != 0 or m['dgmT33S7'](11) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S7'](12) != 1 or m['dgmT33S7'](13) != 2 or m['dgmT33S7'](14) != 2 or m['dgmT33S7'](15) != 2 or m['dgmT33S7'](16) != 2 or m['dgmT33S7'](17) != 2 or m['dgmT33S7'](18) != 2 or m['dgmT33S7'](19) != 3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S7'](20) != 3 or m['dgmT33S7'](21) != 3 or m['dgmT33S7'](22) != 3 or m['dgmT33S7'](23) != 4 or m['dgmT33S7'](24) != 4 or m['dgmT33S7'](25) != 5 or m['dgmT33S7'](26) != 5 or m['dgmT33S7'](27) != 5",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S7'](28) != 6 or m['dgmT33S7'](29) != -99 or m['dgmT33S8'](0) != 0 or m['dgmT33S8'](1) != 0 or m['dgmT33S8'](2) != 0 or m['dgmT33S8'](3) != 0 or m['dgmT33S8'](4) != 0 or m['dgmT33S8'](5) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S8'](6) != 0 or m['dgmT33S8'](7) != 0 or m['dgmT33S8'](8) != 0 or m['dgmT33S8'](9) != 0 or m['dgmT33S8'](10) != 0 or m['dgmT33S8'](11) != 0 or m['dgmT33S8'](12) != 0 or m['dgmT33S8'](13) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S8'](14) != 0 or m['dgmT33S8'](15) != 0 or m['dgmT33S8'](16) != 1 or m['dgmT33S8'](17) != 2 or m['dgmT33S8'](18) != 2 or m['dgmT33S8'](19) != 3 or m['dgmT33S8'](20) != 3 or m['dgmT33S8'](21) != 3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgmT33S8'](22) != 3 or m['dgmT33S8'](23) != 4 or m['dgmT33S8'](24) != 4 or m['dgmT33S8'](25) != 4 or m['dgmT33S8'](26) != 4 or m['dgmT33S8'](27) != 5 or m['dgmT33S8'](28) != 5 or m['dgmT33S8'](29) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R626 OA wu jen audit",
      "comment" = "OA round thirteen (capture pp. 47-51): the wu jen - the minima, the spell-learning doctrine, the ki powers, the elemental mastery and the taboo ladder",
    },
}
