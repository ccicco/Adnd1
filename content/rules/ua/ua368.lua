-- ua368: promoted from rules/ua/uacavtable.h (the The UA CAVALIERS TABLE I (p. 15 print) pins,);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 368,
  "prefix" = "ua368",
  "banner" = {
      "title" = "The UA CAVALIERS TABLE I (p. 15 print) pins,",
      "provenance" = "R368: the full table - the two 0-level track rows (Horseman 1d4+1, Lancer 2d4+1), the 1st-level footnote (1d10+3 vs the track 3d4+1), the XP bands, the level titles, the cumulative dice column (2-10 dice at levels 2-10, 10+3 and 10+6 at 11th and 12th), the 3 hp per level after the 10th and the 300,000 xp per level past the 12th.  Pin-era pattern (R322): pinned data only - no engine site exists. Cross-checks the landed R328 seam (rules/ua/cavalier.h - the XP ladder and the known title cells) and the R327 d10 hit die.  JUDGMENTs (the decode method): - the level-5 title cell prints Knight in the grid; the retainer prose elsewhere reads becoming a Knight at 6th - the R328 conflict. The grid print wins (the standing print-wins convention), the divergence flagged pending the PDF. - the level-6 title cell is OCR-lost in the extract - a hole, no pin, pending the PDF. - the level-11 and level-12 title cells print cleanly (\"Cavalier, 11th\", \"Cavalier, 12th\") - two of the four R328 holes close here. - the level-11 XP band cell garbles; the band is decoded from its neighbors (the 10th band ends 600,000; the 12th band prints 900,001) - the forced decode, corroborated by the R328 ladder. - the table header cell prints \"12-Sided Dice\" against the R327 cavalier d10 - a suspected column scramble; not pinned, flagged pending the PDF.",
    },
  "consts" = { {
      "name" = "uacavtHorsemanXpLow",
      "value" = -1500,
      "comment" = "---- the 0-level track rows ---- Horseman: -1,500 to -501 xp, 1d4+1 hp.",
    }, {
      "name" = "uacavtHorsemanXpHigh",
      "value" = -501,
      "comment" = "",
    }, {
      "name" = "uacavtHorsemanHpDice",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uacavtHorsemanHpDiceSides",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uacavtHorsemanHpBonus",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uacavtLancerXpLow",
      "value" = -500,
      "comment" = "Lancer: -500 to -1 xp, 2d4+1 hp.",
    }, {
      "name" = "uacavtLancerXpHigh",
      "value" = -1,
      "comment" = "",
    }, {
      "name" = "uacavtLancerHpDice",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uacavtLancerHpDiceSides",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uacavtLancerHpBonus",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uacavtTrackFirstDice",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uacavtTrackFirstSides",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uacavtTrackFirstBonus",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uacavtDirectFirstDice",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uacavtDirectFirstSides",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uacavtDirectFirstBonus",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uacavtLevel11FlatHp",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uacavtLevel12FlatHp",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uacavtHpPerLevelPast10",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uacavtXpPerLevelPast12",
      "value" = 300000,
      "comment" = "---- the past-12th reads ----",
    }, {
      "name" = "uacavtCommanderLevel",
      "value" = 13,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uacavtFirstLevelTrackFootnote",
      "value" = true,
      "comment" = "---- the 1st-level footnote ---- If qualification required the two 0-level grades, the 1st-level hit dice are 3d4+1; in all other cases 1d10+3 applies (the Upper Class direct entry).",
    }, {
      "name" = "uacavtLevel12XpUnbounded",
      "value" = true,
      "comment" = "The 12th band is unbounded (300,000 xp per level past the 12th); the level-11 band garbles and is decoded from its neighbors.",
    }, {
      "name" = "uacavtLevel11BandDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uacavtDiceColumnCumulative",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uacavtTwelveSidedHeaderSuspect",
      "value" = true,
      "comment" = "The header cell prints 12-sided against the landed R327 d10 - a suspected scramble, no pin.",
    }, {
      "name" = "uacavtLevel6TitleCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uacavtLevel5GridVsProseConflict",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uacavtLevelXpLow",
      "comment" = "---- the XP bands, levels 1-12 ---- The printed band bounds; level 12 is unbounded (300,000 xp per level past the 12th). The R328 attain ladder reads attain(level) = high(level-1).",
      "kind" = "header pin",
      "body" = "static const int k[12] = { 0, 2501, 5001, 10001, 18501, 37001, 85001, 140001, 220001, 300001, 600001, 900001, }; if (level < 1) level = 1; if (level > 12) level = 12; return k[level - 1];",
    }, {
      "name" = "uacavtLevelXpHigh",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[12] = { 2500, 5000, 10000, 18500, 37000, 85000, 140000, 220000, 300000, 600000, 900000, 0, }; if (level < 1) level = 1; if (level > 12) level = 12; return k[level - 1];",
    }, {
      "name" = "uacavtLevelDiceCount",
      "comment" = "---- the cumulative dice column ---- Levels 2-10: the dice count equals the level; the 11th and 12th rows print 10+3 and 10+6 (the 3 hp per level after the 10th).",
      "kind" = "header pin",
      "body" = "if (level < 2) return 1; if (level > 10) return 10; return level;",
    }, {
      "name" = "uacavtTitle",
      "comment" = "---- the level titles ---- 0 = Horseman, -1 = Lancer, 1-12 the levels, 13+ Cavalier Commander. Level 6 is the lost cell (the empty string); level 5 is the grid print (the prose conflict flagged below).",
      "kind" = "header pin",
      "body" = "switch (level) { case 0: return \"Horseman\"; case -1: return \"Lancer\"; case 1: return \"Armiger\"; case 2: return \"Scutifer\"; case 3: return \"Esquire\"; case 4: return \"Knight Errant\"; case 5: return \"Knight\"; case 7: return \"Grand Knight\"; case 8: return \"Banneret\"; case 9: return \"Chevalier\"; case 10: return \"Cavalier\"; case 11: return \"Cavalier, 11th\"; case 12: return \"Cavalier, 12th\"; default: if (level >= 13) return \"Cavalier Commander\"; return \"\"; }",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uacavtHorsemanXpLow']() != -1500  or m['uacavtHorsemanXpHigh']() != -501  or m['uacavtHorsemanHpDice']() != 1  or m['uacavtHorsemanHpDiceSides']() != 4  or m['uacavtHorsemanHpBonus']() != 1  or m['uacavtLancerXpLow']() != -500  or m['uacavtLancerXpHigh']() != -1  or m['uacavtLancerHpDice']() != 2  or m['uacavtLancerHpDiceSides']() != 4  or m['uacavtLancerHpBonus']() != 1  or  m['uacavtFirstLevelTrackFootnote']() != 1  or m['uacavtTrackFirstDice']() != 3  or m['uacavtTrackFirstSides']() != 4  or m['uacavtTrackFirstBonus']() != 1  or m['uacavtDirectFirstDice']() != 1  or m['uacavtDirectFirstSides']() != 10  or m['uacavtDirectFirstBonus']() != 3  or  m['uacavtLevel12XpUnbounded']() != 1  or  m['uacavtLevel11BandDecoded']() != 1  or m['uacavtLevel11FlatHp']() != 3  or m['uacavtLevel12FlatHp']() != 6  or m['uacavtHpPerLevelPast10']() != 3  or  m['uacavtDiceColumnCumulative']() != 1  or  m['uacavtTwelveSidedHeaderSuspect']() != 1  or  m['uacavtLevel6TitleCellLost']() != 1  or  m['uacavtLevel5GridVsProseConflict']() != 1  or m['uacavtXpPerLevelPast12']() != 300000  or m['uacavtCommanderLevel']() != 13",
      "note" = "---- the pinned cells ----",
    }, {
      "expr" = "m['uacavtLevelXpLow'](l) != xl[l - 1]  or m['uacavtLevelXpHigh'](l) != xh[l - 1]  or l < 12 && xh[l - 1] + 1 != xl[l]  or l == 1) { if (att != 0  or m['uacavtHorsemanXpLow']() !=m['cavalierHorsemanXp']()  or m['uacavtLancerXpLow']() !=m['cavalierLancerXp']()",
      "note" = "---- the XP band loops ----",
    }, {
      "expr" = "m['uacavtLevelDiceCount'](l) != l  or m['uacavtLevelDiceCount'](11) != 10  or m['uacavtLevelDiceCount'](12) != 10  or m['uacavtLevel11FlatHp']() !=m['uacavtHpPerLevelPast10']()  or m['uacavtLevel12FlatHp']() != 2 *m['uacavtHpPerLevelPast10']()  or m['uacavtHpPerLevelPast10']() !=m['cavalierHpPerLevelPast10']()",
      "note" = "---- the dice column ----",
    }, {
      "expr" = "strcmp(m['uacavtTitle'](l), tn[i]) != 0  or strcmp(m['uacavtTitle'](13), \"Cavalier Commander\") != 0  or m['uacavtCommanderLevel']() !=m['cavalierCommanderLevel']()  or m['uacavtXpPerLevelPast12']() !=m['cavalierXpPerLevelPast12']()  or l == 5  or l == 6) continue; if (strcmp(m['uacavtTitle'](l),m['cavalierTitleKnown'](l)) != 0  or m['uacavtTitle'](11)[0] == 0  or m['uacavtTitle'](12)[0] == 0",
      "note" = "---- the titles ----",
    } },
  "audit" = {
      "label" = "R368: the UA Cavaliers Table I pin audit",
      "comment" = "The UA CAVALIERS TABLE I (p. 15): the full table pinned - the two 0-level rows (Horseman 1d4+1 at -1,500 to -501, Lancer 2d4+1 at -500 to -1), the 1st-level footnote (the track 3d4+1 vs the direct 1d10+3), the printed XP bands with the level-11 band decoded from its neighbors, the cumulative dice column (the level count at 2nd-10th, 10+3 and 10+6 at 11th and 12th), the level titles (the 11th and 12th cells newly readable - two of the four R328 holes close; the level-5 grid Knight with the prose conflict flagged; the level-6 cell lost, a hole; the 12-sided header cell suspect against the R327 d10), the 3 hp per level past 10th, the 300,000 xp per level past 12th and Cavalier Commander at 13th+. The R328 seam cross-checks the XP ladder and the known titles. The item flips CLOSED; the census 294 -> 295.",
    },
}
