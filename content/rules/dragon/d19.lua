-- d19: promoted from tools/spec_r939.json (the The Dragon issue-19 box closing round - the six-chain walk complete, issues 2 through 19 all closed);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 939,
  "prefix" = "d19",
  "banner" = {
      "title" = "The Dragon issue-19 box closing round - the six-chain walk complete, issues 2 through 19 all closed",
      "provenance" = "The pure flip of the issue-19 three-round shape - no new ink pinned, both report-019 boxes closed. The issue-19 openers stand at R937 (dws: the wish-spell doctrine, the mythos of Australia, the systematic magic fields) and R938 (sdm: the Origins 78 tourney and scoring, the treasure chains, the spell determination grids), all pinned from The Dragon Vol. III No. 5 (October 1978), the Curtiss-provided Dm19.pdf scan voice.",
      "sentinel" = "No new print catches at this flip - the issue-19 print quirks all rode the two opener records: the doubled Gate, the Champion 7th Wawalag line, the Mimi armor class 8, the Smurre continuation stamp, the Kuo-Tao spelling cross, the unassigned 14-15 location bands, the -01-05 leading dash and the dungeons-only asterisks. Both inherited watches - the Sullin levels 7-9 and the brawling sequel - stayed empty through issue 19 and ride to TD 20.",
    },
  "consts" = { {
      "name" = "d19IssueNineteenBoxes",
      "value" = 2,
      "comment" = "both report-019 boxes close at this single flip - the part-one and part-two opener boxes",
    }, {
      "name" = "d19IssueNineteenChains",
      "value" = 6,
      "comment" = "the issue-19 chain count - three part-one chains (wishes, mythos of Australia, systematic magic) and three part-two chains (the Origins 78 tourney and scoring, the treasure chains, the hostile MU spell determination)",
    }, {
      "name" = "d19IssueNineteenRounds",
      "value" = 3,
      "comment" = "the issue-19 round shape - the R937 opener part one, the R938 opener part two and this R939 pure flip, the third three-round issue shape",
    }, {
      "name" = "d19IssueSevenClosed",
      "value" = 1,
      "comment" = "issue 7 stands closed since its own flip",
    }, {
      "name" = "d19IssueEightClosed",
      "value" = 1,
      "comment" = "issue 8 stands closed since its own flip",
    }, {
      "name" = "d19IssueNineClosed",
      "value" = 1,
      "comment" = "issue 9 stands closed since its own flip",
    }, {
      "name" = "d19IssueTenClosed",
      "value" = 1,
      "comment" = "issue 10 stands closed since its own flip",
    }, {
      "name" = "d19IssueElevenClosed",
      "value" = 1,
      "comment" = "issue 11 stands closed since its own flip",
    }, {
      "name" = "d19IssueTwelveClosed",
      "value" = 1,
      "comment" = "issue 12 stands closed since its own flip",
    }, {
      "name" = "d19IssueThirteenClosed",
      "value" = 1,
      "comment" = "issue 13 stands closed since its own flip",
    }, {
      "name" = "d19IssueFourteenClosed",
      "value" = 1,
      "comment" = "issue 14 stands closed since its own flip",
    }, {
      "name" = "d19IssueFifteenClosed",
      "value" = 1,
      "comment" = "issue 15 stands closed since its own flip",
    }, {
      "name" = "d19IssueSixteenClosed",
      "value" = 1,
      "comment" = "issue 16 stands closed since its own flip",
    }, {
      "name" = "d19IssueSeventeenClosed",
      "value" = 1,
      "comment" = "issue 17 stands closed since its own flip",
    }, {
      "name" = "d19IssueEighteenClosed",
      "value" = 1,
      "comment" = "issue 18 stands closed since its own flip",
    }, {
      "name" = "d19RegistryLoaded",
      "value" = 1313,
      "comment" = "the registry ground truth - 1313 loaded defs, unchanged from the R924 re-measure",
    }, {
      "name" = "d19RegistryBaseLua",
      "value" = 1338,
      "comment" = "the registry base lua count, 1338, unchanged",
    }, {
      "name" = "d19RegistryNeverLoad",
      "value" = 25,
      "comment" = "the registry never-load count, 25, unchanged",
    } },
  "bools" = { {
      "name" = "d19WalkSevenComplete",
      "value" = true,
      "comment" = "the Dragon walk holds issues 2 through 7 complete",
    }, {
      "name" = "d19WalkEightComplete",
      "value" = true,
      "comment" = "issue 8 complete",
    }, {
      "name" = "d19WalkNineComplete",
      "value" = true,
      "comment" = "issue 9 complete",
    }, {
      "name" = "d19WalkTenComplete",
      "value" = true,
      "comment" = "issue 10 complete",
    }, {
      "name" = "d19WalkElevenComplete",
      "value" = true,
      "comment" = "issue 11 complete",
    }, {
      "name" = "d19WalkTwelveComplete",
      "value" = true,
      "comment" = "issue 12 complete",
    }, {
      "name" = "d19WalkThirteenComplete",
      "value" = true,
      "comment" = "issue 13 complete",
    }, {
      "name" = "d19WalkFourteenComplete",
      "value" = true,
      "comment" = "issue 14 complete",
    }, {
      "name" = "d19WalkFifteenComplete",
      "value" = true,
      "comment" = "issue 15 complete",
    }, {
      "name" = "d19WalkSixteenComplete",
      "value" = true,
      "comment" = "issue 16 complete",
    }, {
      "name" = "d19WalkSeventeenComplete",
      "value" = true,
      "comment" = "issue 17 complete",
    }, {
      "name" = "d19WalkEighteenComplete",
      "value" = true,
      "comment" = "issue 18 complete",
    }, {
      "name" = "d19WalkNineteenComplete",
      "value" = true,
      "comment" = "ISSUE 19 COMPLETE AT THIS FLIP - the walk now holds issues 2 through 19",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['d19IssueNineteenBoxes']() != 2 or m['d19IssueNineteenChains']() != 6 or m['d19IssueNineteenRounds']() != 3 or m['d19IssueEighteenClosed']() != 1 or m['d19IssueSeventeenClosed']() != 1 or m['d19IssueSevenClosed']() != 1",
      "note" = "the issue-19 census - two boxes, six chains, three rounds, the third three-round shape, issues 7 through 18 standing closed",
    }, {
      "expr" = "m['d19IssueSixteenClosed']() != 1 or m['d19IssueFifteenClosed']() != 1 or m['d19IssueFourteenClosed']() != 1 or m['d19IssueThirteenClosed']() != 1 or m['d19IssueTwelveClosed']() != 1 or m['d19IssueElevenClosed']() != 1 or m['d19IssueTenClosed']() != 1 or m['d19IssueNineClosed']() != 1 or m['d19IssueEightClosed']() != 1",
      "note" = "the mid-walk closed set - issues 8 through 16 all stand closed at this flip",
    }, {
      "expr" = "m['d19RegistryLoaded']() != 1313 or m['d19RegistryBaseLua']() != 1338 or m['d19RegistryNeverLoad']() != 25 or m['d19WalkNineteenComplete']() != 1 or m['d19WalkSevenComplete']() != 1 or m['d19WalkEighteenComplete']() != 1",
      "note" = "the registry ground truth unchanged 1313/1338/25 and the walk complete through issue 19, issues 2 through 7 and 18 included",
    } },
  "audit" = {
      "label" = "R939 Dragon issue-19 closure audit",
      "comment" = "THE DRAGON ISSUE-19 BOX CLOSING ROUND - the pure flip, no new ink. Both report-019 boxes flip at this single round: the issue-19 opener chains part one (the R937 wish-spell doctrine, the mythos of Australia pantheon, the systematic magic fields) and part two (the R938 Origins 78 tourney and victory-point scoring, the creative treasures and location/trap/gas charts, the hostile magic-user spell determination grids). Six chains across three rounds, the third three-round issue shape after 17 and 18. The bookkeeping mirrors the f17 and f18 closers: the boxes, chains and rounds consts, the issue-closed consts 7 through 18, the walk-complete bools and the unchanged registry ground truth.",
    },
}
