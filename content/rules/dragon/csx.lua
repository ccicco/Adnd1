-- csx: promoted from tools/spec_r907.json (the The Dragon issue-6 box closing round - the four-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 907,
  "prefix" = "csx",
  "banner" = {
      "title" = "The Dragon issue-6 box closing round - the four-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth",
      "provenance" = "The pure box-closing round, no new ink: the issue-6 box in tools/dragon_gap_report_006.md flips closed (1 / 0), completing the issue-6 walk exactly as adjudicated at R906 - the Sea Trade system, the psionic determination option, the morale system and the Death Angel having been the only engine-relevant ink in issue #6 (the Metamorphosis Alpha chains, the EPT painting guide, the fiction, the Gnome Cache as ideas-usable, the comic, the editorial, the ads, the convention schedule and the preview all scoped out). The bookkeeping pins: the single box and its four chains, the issue-5 report complete at 1 / 0 since R903, the issue-4 report complete at 1 / 0 since R901, and the registry ground truth carried forward (the 1311 live census, the 1333 base lua files, the 25 never-load errors - the battery line the only ground truth, a pre-R900 print-fidelity state untouched).",
      "sentinel" = "The variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the pin IS the conversion, and the R906 print quirks (the profit/loss grid's AS-SCANNED 10 cell, the worked-example discrepancy, the folio-25 15-tenths read) stay noted in the opener round, never silent.",
    },
  "consts" = { {
      "name" = "csxReportBoxes",
      "value" = 1,
      "comment" = "the issue-6 gap report carries one box (report 006)",
    }, {
      "name" = "csxIssue6Chains",
      "value" = 4,
      "comment" = "the issue-6 opener pinned four chains - the Sea Trade system, the psionic option, the morale system, the Death Angel (R906)",
    }, {
      "name" = "csxIssue5Closed",
      "value" = 1,
      "comment" = "the issue-5 report has sat complete at 1 closed / 0 open since R903",
    }, {
      "name" = "csxIssue4Closed",
      "value" = 1,
      "comment" = "the issue-4 report has sat complete at 1 closed / 0 open since R901",
    }, {
      "name" = "csxLiveRegistry",
      "value" = 1311,
      "comment" = "the live registry census floor, carried forward from R900",
    }, {
      "name" = "csxBaseLuaFiles",
      "value" = 1333,
      "comment" = "the base lua file count the R900 promotion measured against",
    }, {
      "name" = "csxRegistryLoadErrors",
      "value" = 25,
      "comment" = "the base never-load errors - the battery line is the only ground truth",
    } },
  "bools" = { {
      "name" = "csxIssue4WalkComplete",
      "value" = true,
      "comment" = "the issue-4 walk completed at R901",
    }, {
      "name" = "csxIssue5WalkComplete",
      "value" = true,
      "comment" = "the issue-5 walk completed at R903",
    }, {
      "name" = "csxIssue6WalkComplete",
      "value" = true,
      "comment" = "the issue-6 walk completes with this round - the four-chain opener was the only engine-relevant ink in issue #6",
    }, {
      "name" = "csxVariantLayerDoctrine",
      "value" = true,
      "comment" = "the variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the conversions noted, never silent",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['csxReportBoxes']() != 1 or m['csxIssue6Chains']() != 4 or m['csxIssue5Closed']() != 1 or m['csxIssue4Closed']() != 1",
      "note" = "the walk bookkeeping - the single issue-6 box and its four chains, the issue-4 and issue-5 reports complete at 1 / 0",
    }, {
      "expr" = "m['csxLiveRegistry']() != 1311 or m['csxBaseLuaFiles']() != 1333 or m['csxRegistryLoadErrors']() != 25",
      "note" = "the registry ground truth carried forward - the 1311 live census, the 1333 base lua files, the 25 never-load errors, the battery line the only ground truth",
    }, {
      "expr" = "m['csxIssue4WalkComplete']() != 1 or m['csxIssue5WalkComplete']() != 1 or m['csxIssue6WalkComplete']() != 1 or m['csxVariantLayerDoctrine']() != 1",
      "note" = "the three walks complete - issue 4 at R901, issue 5 at R903, issue 6 at this round - and the variant-layer doctrine riding the closure",
    } },
  "audit" = {
      "label" = "R907 Dragon issue-6 closure audit",
      "comment" = "THE DRAGON ISSUE-6 BOX CLOSING ROUND - the pure bookkeeping round, no new print ink. The flip: the issue-6 box in tools/dragon_gap_report_006.md goes [x] - 1 closed / 0 open, the issue-6 walk complete, the four chains (the Sea Trade system, the psionic option, the morale system, the Death Angel at folios 6, 25, 26-27, 29) having been the only engine-relevant ink in issue #6. The bookkeeping pins: the single box and its four chains, the issue-5 report complete at 1 / 0 since R903, the issue-4 report complete at 1 / 0 since R901, the registry ground truth carried forward (the 1311 live census against the 1333 base lua files with the 25 never-load errors, a pre-R900 print-fidelity state untouched), and the variant-layer doctrine riding the closure. The R906 record seats in the seed via prev_record.",
    },
}
