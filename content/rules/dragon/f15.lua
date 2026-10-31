-- f15: promoted from tools/spec_r928.json (the The Dragon issue-15 box closing round - the five-chain walk complete, the pure flip);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 928,
  "prefix" = "f15",
  "banner" = {
      "title" = "The Dragon issue-15 box closing round - the five-chain walk complete, the pure flip",
      "provenance" = "Bookkeeping only, no new ink pinned. The issue-15 walk (the R927 opener carrying all five chains, this flip) covered The Dragon Vol. III No. 1 (June 1978), the Curtiss-provided scan voice, single-voice - the mistral transcript of the uploaded Dm15.pdf; no archive.org djvu cross-check exists for issue 15, the accessory items end at issue 14. Print folio = PDF page minus two, verified at the R927 page feet; the TOC prints two swapped folios. Registry ground truth unchanged: 1313 loaded / 1338 base lua / 25 never-load (the R924 re-measure). Watch: the brawling long-term-effects sequel STILL does not print (watch TD 16).",
      "sentinel" = "No print quirks ride this flip - the garbled cells of the opener (the shared-35 occupied-pit bound, the ranger 91-85 upper bound, the non-contiguous seasonal unusual faces) pin sentinel in the R927 layer and ride the transcript, noted never silent; this round flips the five report boxes and touches no ink.",
    },
  "consts" = { {
      "name" = "f15IssueFifteenBoxes",
      "value" = 5,
      "comment" = "the issue-15 gap report - five boxes, all closed at this single flip",
    }, {
      "name" = "f15IssueFifteenChains",
      "value" = 5,
      "comment" = "the issue-15 walk - five engine chains in one opener round",
    }, {
      "name" = "f15IssueFifteenRounds",
      "value" = 2,
      "comment" = "the issue-15 walk completes in two rounds - the R927 opener, this flip",
    }, {
      "name" = "f15IssueFourteenClosed",
      "value" = 1,
      "comment" = "the issue-14 report closed at R926",
    }, {
      "name" = "f15IssueThirteenClosed",
      "value" = 1,
      "comment" = "the issue-13 report closed at R924",
    }, {
      "name" = "f15IssueTwelveClosed",
      "value" = 1,
      "comment" = "the issue-12 report closed at R922",
    }, {
      "name" = "f15IssueElevenClosed",
      "value" = 1,
      "comment" = "the issue-11 report closed at R920",
    }, {
      "name" = "f15IssueTenClosed",
      "value" = 1,
      "comment" = "the issue-10 report closed at R918",
    }, {
      "name" = "f15IssueNineClosed",
      "value" = 1,
      "comment" = "the issue-9 report closed at R916",
    }, {
      "name" = "f15IssueEightClosed",
      "value" = 1,
      "comment" = "the issue-8 report closed at R913",
    }, {
      "name" = "f15IssueSevenClosed",
      "value" = 1,
      "comment" = "the issue-7 report closed at R911",
    }, {
      "name" = "f15IssueSixClosed",
      "value" = 1,
      "comment" = "the issue-6 report closed at R909",
    }, {
      "name" = "f15RegistryLoaded",
      "value" = 1313,
      "comment" = "the registry ground truth carried from the R924 re-measure - 1313 loaded",
    }, {
      "name" = "f15RegistryBaseLua",
      "value" = 1338,
      "comment" = "the registry ground truth - 1338 base lua",
    }, {
      "name" = "f15RegistryNeverLoad",
      "value" = 25,
      "comment" = "the registry ground truth - 25 never-load",
    } },
  "bools" = { {
      "name" = "f15WalkSixComplete",
      "value" = true,
      "comment" = "the issue-6 walk complete",
    }, {
      "name" = "f15WalkSevenComplete",
      "value" = true,
      "comment" = "the issue-7 walk complete",
    }, {
      "name" = "f15WalkEightComplete",
      "value" = true,
      "comment" = "the issue-8 walk complete",
    }, {
      "name" = "f15WalkNineComplete",
      "value" = true,
      "comment" = "the issue-9 walk complete",
    }, {
      "name" = "f15WalkTenComplete",
      "value" = true,
      "comment" = "the issue-10 walk complete",
    }, {
      "name" = "f15WalkElevenComplete",
      "value" = true,
      "comment" = "the issue-11 walk complete",
    }, {
      "name" = "f15WalkTwelveComplete",
      "value" = true,
      "comment" = "the issue-12 walk complete",
    }, {
      "name" = "f15WalkThirteenComplete",
      "value" = true,
      "comment" = "the issue-13 walk complete",
    }, {
      "name" = "f15WalkFourteenComplete",
      "value" = true,
      "comment" = "the issue-14 walk complete",
    }, {
      "name" = "f15WalkFifteenComplete",
      "value" = true,
      "comment" = "the issue-15 walk complete at this flip",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['f15IssueFifteenBoxes']() != 5 or m['f15IssueFifteenChains']() != 5 or m['f15IssueFifteenRounds']() != 2 or m['f15IssueFourteenClosed']() != 1 or m['f15IssueThirteenClosed']() != 1",
      "note" = "the walk census - five issue-15 boxes, five chains across two rounds, the issue-14 and issue-13 reports complete",
    }, {
      "expr" = "m['f15IssueTwelveClosed']() != 1 or m['f15IssueElevenClosed']() != 1 or m['f15IssueTenClosed']() != 1 or m['f15IssueNineClosed']() != 1 or m['f15IssueEightClosed']() != 1 or m['f15IssueSevenClosed']() != 1 or m['f15IssueSixClosed']() != 1 or m['f15WalkFifteenComplete']() != 1 or m['f15WalkFourteenComplete']() != 1",
      "note" = "the earlier reports complete since R918, R916, R913, R911 and R909, the issue-15 and issue-14 walks complete",
    }, {
      "expr" = "m['f15RegistryLoaded']() != 1313 or m['f15RegistryBaseLua']() != 1338 or m['f15RegistryNeverLoad']() != 25 or m['f15WalkSixComplete']() != 1 or m['f15WalkTenComplete']() != 1 or m['f15WalkThirteenComplete']() != 1",
      "note" = "the registry ground truth unchanged from the R924 re-measure - 1313 loaded, 1338 base lua, 25 never-load",
    } },
  "audit" = {
      "label" = "R928 Dragon issue-15 closure audit",
      "comment" = "THE DRAGON ISSUE-15 CLOSURE ROUND - the pure flip, no new ink. ALL FIVE report-015 boxes close at this single flip - Dragon Magic (print 3, cont. 13), the Wandering Monster fourth-level list (print 7), Weather in the Wilderness (print 14-15), the Pits tables (print 5) and the Random Events Table for Settlements (print 5) - 5 closed / 0 open in tools/dragon_gap_report_015.md; the five-chain walk completes in two rounds (the R927 opener carrying all five chains, this flip), the issue-14 two-round pattern. Issues 2-15 all closed.",
    },
}
