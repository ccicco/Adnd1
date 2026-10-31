-- dfp: promoted from tools/spec_r916.json (the The Dragon issue-10 box closing round - the six-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 916,
  "prefix" = "dfp",
  "banner" = {
      "title" = "The Dragon issue-10 box closing round - the six-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth",
      "provenance" = "The pure box-closing round, no new ink: the issue-10 part-two box in tools/dragon_gap_report_010.md flips closed (2 / 0), completing the issue-10 walk exactly as adjudicated at R914 and R915 - the Orgies Inc. article, the Clifton wilderness article, the Random Monsters article, the Gilbert dungeon method article, the Weights & Measures article and the Holsinger level ritual article having been the only engine-relevant ink in issue #10 (the editorial, the GenCon X report, the Snits game, the Stellar Conquest diplomacy article, the poem, the comics and the ads all scoped out). The bookkeeping pins: the two boxes and their six chains across the two opener rounds, the issue-9 report complete at 1 / 0 since R913, the issue-8 report complete at 1 / 0 since R911, the issue-7 report complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, and the registry ground truth carried forward (the 1311 live census, the 1333 base lua files, the 25 never-load errors - the battery line the only ground truth, a pre-R900 print-fidelity state untouched).",
      "sentinel" = "The variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the pin IS the conversion, and the R914 and R915 AS-SCANNED quirks (the Random Monsters garbles, the Clifton band arithmetic, the Weights & Measures sentinel cells and the 185 medium cell, the speed-12 fraction) stay noted in the opener rounds, never silent.",
    },
  "consts" = { {
      "name" = "dfpReportBoxes",
      "value" = 2,
      "comment" = "the issue-10 gap report carries two boxes, one per opener round (report 010)",
    }, {
      "name" = "dfpIssue10Chains",
      "value" = 6,
      "comment" = "the issue-10 walk pinned six chains across two rounds - the Orgies Inc., Clifton wilderness, Random Monsters, Gilbert dungeon method, Weights & Measures and Holsinger level ritual articles (R914, R915)",
    }, {
      "name" = "dfpIssue9Closed",
      "value" = 1,
      "comment" = "the issue-9 report has sat complete at 1 closed / 0 open since R913",
    }, {
      "name" = "dfpIssue8Closed",
      "value" = 1,
      "comment" = "the issue-8 report has sat complete at 1 closed / 0 open since R911",
    }, {
      "name" = "dfpIssue7Closed",
      "value" = 1,
      "comment" = "the issue-7 report has sat complete at 1 closed / 0 open since R909",
    }, {
      "name" = "dfpIssue6Closed",
      "value" = 1,
      "comment" = "the issue-6 report has sat complete at 1 closed / 0 open since R907",
    }, {
      "name" = "dfpLiveRegistry",
      "value" = 1311,
      "comment" = "the live registry census floor, carried forward from R900",
    }, {
      "name" = "dfpBaseLuaFiles",
      "value" = 1333,
      "comment" = "the base lua file count the R900 promotion measured against",
    }, {
      "name" = "dfpRegistryLoadErrors",
      "value" = 25,
      "comment" = "the base never-load errors - the battery line is the only ground truth",
    } },
  "bools" = { {
      "name" = "dfpIssue6WalkComplete",
      "value" = true,
      "comment" = "the issue-6 walk completed at R907",
    }, {
      "name" = "dfpIssue7WalkComplete",
      "value" = true,
      "comment" = "the issue-7 walk completed at R909",
    }, {
      "name" = "dfpIssue8WalkComplete",
      "value" = true,
      "comment" = "the issue-8 walk completed at R911",
    }, {
      "name" = "dfpIssue9WalkComplete",
      "value" = true,
      "comment" = "the issue-9 walk completed at R913",
    }, {
      "name" = "dfpIssue10WalkComplete",
      "value" = true,
      "comment" = "the issue-10 walk completes with this round - the six chains across two opener rounds were the only engine-relevant ink in issue #10",
    }, {
      "name" = "dfpVariantLayerDoctrine",
      "value" = true,
      "comment" = "the variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the conversions noted, never silent",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dfpReportBoxes']() != 2 or m['dfpIssue10Chains']() != 6 or m['dfpIssue9Closed']() != 1 or m['dfpIssue8Closed']() != 1 or m['dfpIssue7Closed']() != 1 or m['dfpIssue6Closed']() != 1",
      "note" = "the walk bookkeeping - the two issue-10 boxes and their six chains, the issue-9, issue-8, issue-7 and issue-6 reports complete at 1 / 0",
    }, {
      "expr" = "m['dfpLiveRegistry']() != 1311 or m['dfpBaseLuaFiles']() != 1333 or m['dfpRegistryLoadErrors']() != 25",
      "note" = "the registry ground truth carried forward - the 1311 live census, the 1333 base lua files, the 25 never-load errors, the battery line the only ground truth",
    }, {
      "expr" = "m['dfpIssue6WalkComplete']() != 1 or m['dfpIssue7WalkComplete']() != 1 or m['dfpIssue8WalkComplete']() != 1 or m['dfpIssue9WalkComplete']() != 1 or m['dfpIssue10WalkComplete']() != 1 or m['dfpVariantLayerDoctrine']() != 1",
      "note" = "the five walks complete - issue 6 at R907, issue 7 at R909, issue 8 at R911, issue 9 at R913, issue 10 at this round - and the variant-layer doctrine riding the closure",
    } },
  "audit" = {
      "label" = "R916 Dragon issue-10 closure audit",
      "comment" = "THE DRAGON ISSUE-10 CLOSURE ROUND - the pure flip. The issue-10 part-two box (the Gilbert dungeon method article, the Weights & Measures article and the Holsinger level ritual article, folios 11-14, 19-21) closes 2 closed / 0 open in tools/dragon_gap_report_010.md; the six-chain walk completes exactly as adjudicated at R914 and R915. The bookkeeping pins: the two boxes and their six chains, the issue-9 report complete at 1 / 0 since R913, the issue-8 report complete at 1 / 0 since R911, the issue-7 report complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, and the registry ground truth carried forward.",
    },
}
