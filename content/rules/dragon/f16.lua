-- f16: promoted from tools/spec_r930.json (the The Dragon issue-16 box closing round - the two-chain walk complete, the pure flip);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 930,
  "prefix" = "f16",
  "banner" = {
      "title" = "The Dragon issue-16 box closing round - the two-chain walk complete, the pure flip",
      "provenance" = "Bookkeeping only, no new ink pinned. The issue-16 walk (the R929 opener carrying both chains, this flip) covered The Dragon Vol. III No. 2 (July 1978), the Curtiss-provided scan voice, single-voice - the mistral transcript of the uploaded Dm16.pdf; no archive.org djvu cross-check exists for issue 16. Print folio = PDF page minus two, verified at the R929 page feet. Registry ground truth unchanged: 1313 loaded / 1338 base lua / 25 never-load (the R924 re-measure). Watch: the brawling long-term-effects sequel STILL does not print (watch TD 17); NO TD-17 teaser prints on the back cover.",
      "sentinel" = "No print quirks ride this flip - the garbled cells of the opener (the Enkidu 1895 and Aqht 1875 strength prints, the as-a-normal-man armor classes, the assassination cost 1006/1518/2012 K prints against the doubling pattern, the eleven-band header vs ten-value rows, the thieving hide 70/60 drift) pin sentinel or as-scanned in the R929 layer and ride the transcript, noted never silent; this round flips the two report boxes and touches no ink.",
    },
  "consts" = { {
      "name" = "f16IssueSixteenBoxes",
      "value" = 2,
      "comment" = "the issue-16 gap report - two boxes, both closed at this single flip",
    }, {
      "name" = "f16IssueSixteenChains",
      "value" = 2,
      "comment" = "the issue-16 walk - two engine chains in one opener round",
    }, {
      "name" = "f16IssueSixteenRounds",
      "value" = 2,
      "comment" = "the issue-16 walk completes in two rounds - the R929 opener, this flip",
    }, {
      "name" = "f16IssueFifteenClosed",
      "value" = 1,
      "comment" = "the issue-15 report closed at R928",
    }, {
      "name" = "f16IssueFourteenClosed",
      "value" = 1,
      "comment" = "the issue-14 report closed at R926",
    }, {
      "name" = "f16IssueThirteenClosed",
      "value" = 1,
      "comment" = "the issue-13 report closed at R924",
    }, {
      "name" = "f16IssueTwelveClosed",
      "value" = 1,
      "comment" = "the issue-12 report closed at R922",
    }, {
      "name" = "f16IssueElevenClosed",
      "value" = 1,
      "comment" = "the issue-11 report closed at R920",
    }, {
      "name" = "f16IssueTenClosed",
      "value" = 1,
      "comment" = "the issue-10 report closed at R918",
    }, {
      "name" = "f16IssueNineClosed",
      "value" = 1,
      "comment" = "the issue-9 report closed at R916",
    }, {
      "name" = "f16IssueEightClosed",
      "value" = 1,
      "comment" = "the issue-8 report closed at R913",
    }, {
      "name" = "f16IssueSevenClosed",
      "value" = 1,
      "comment" = "the issue-7 report closed at R911",
    }, {
      "name" = "f16IssueSixClosed",
      "value" = 1,
      "comment" = "the issue-6 report closed at R909",
    }, {
      "name" = "f16RegistryLoaded",
      "value" = 1313,
      "comment" = "the registry ground truth carried from the R924 re-measure - 1313 loaded",
    }, {
      "name" = "f16RegistryBaseLua",
      "value" = 1338,
      "comment" = "the registry ground truth - 1338 base lua",
    }, {
      "name" = "f16RegistryNeverLoad",
      "value" = 25,
      "comment" = "the registry ground truth - 25 never-load",
    } },
  "bools" = { {
      "name" = "f16WalkSixComplete",
      "value" = true,
      "comment" = "the issue-6 walk complete",
    }, {
      "name" = "f16WalkSevenComplete",
      "value" = true,
      "comment" = "the issue-7 walk complete",
    }, {
      "name" = "f16WalkEightComplete",
      "value" = true,
      "comment" = "the issue-8 walk complete",
    }, {
      "name" = "f16WalkNineComplete",
      "value" = true,
      "comment" = "the issue-9 walk complete",
    }, {
      "name" = "f16WalkTenComplete",
      "value" = true,
      "comment" = "the issue-10 walk complete",
    }, {
      "name" = "f16WalkElevenComplete",
      "value" = true,
      "comment" = "the issue-11 walk complete",
    }, {
      "name" = "f16WalkTwelveComplete",
      "value" = true,
      "comment" = "the issue-12 walk complete",
    }, {
      "name" = "f16WalkThirteenComplete",
      "value" = true,
      "comment" = "the issue-13 walk complete",
    }, {
      "name" = "f16WalkFourteenComplete",
      "value" = true,
      "comment" = "the issue-14 walk complete",
    }, {
      "name" = "f16WalkFifteenComplete",
      "value" = true,
      "comment" = "the issue-15 walk complete",
    }, {
      "name" = "f16WalkSixteenComplete",
      "value" = true,
      "comment" = "the issue-16 walk complete at this flip",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['f16IssueSixteenBoxes']() != 2 or m['f16IssueSixteenChains']() != 2 or m['f16IssueSixteenRounds']() != 2 or m['f16IssueFifteenClosed']() != 1 or m['f16IssueFourteenClosed']() != 1",
      "note" = "the walk census - two issue-16 boxes, two chains across two rounds, the issue-15 and issue-14 reports complete",
    }, {
      "expr" = "m['f16IssueThirteenClosed']() != 1 or m['f16IssueTwelveClosed']() != 1 or m['f16IssueElevenClosed']() != 1 or m['f16IssueTenClosed']() != 1 or m['f16IssueNineClosed']() != 1 or m['f16IssueEightClosed']() != 1 or m['f16IssueSevenClosed']() != 1 or m['f16IssueSixClosed']() != 1 or m['f16WalkSixteenComplete']() != 1 or m['f16WalkFifteenComplete']() != 1",
      "note" = "the earlier reports complete since R909, R911, R913, R916, R918, R920, R922 and R924, the issue-16 and issue-15 walks complete",
    }, {
      "expr" = "m['f16RegistryLoaded']() != 1313 or m['f16RegistryBaseLua']() != 1338 or m['f16RegistryNeverLoad']() != 25 or m['f16WalkSixComplete']() != 1 or m['f16WalkTenComplete']() != 1 or m['f16WalkThirteenComplete']() != 1",
      "note" = "the registry ground truth unchanged from the R924 re-measure - 1313 loaded, 1338 base lua, 25 never-load",
    } },
  "audit" = {
      "label" = "R930 Dragon issue-16 closure audit",
      "comment" = "THE DRAGON ISSUE-16 CLOSURE ROUND - the pure flip, no new ink. BOTH report-016 boxes close at this single flip - the Near Eastern Mythos (print 4-6) and The Ultimate NPC: Ninja (print 7-10) - 2 closed / 0 open in tools/dragon_gap_report_016.md; the two-chain walk completes in two rounds (the R929 opener carrying both chains, this flip), the issue-14 and issue-15 two-round pattern. Issues 2-16 all closed.",
    },
}
