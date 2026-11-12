-- cgx: promoted from tools/spec_r911.json (the The Dragon issue-8 box closing round - the three-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 911,
  "prefix" = "cgx",
  "banner" = {
      "title" = "The Dragon issue-8 box closing round - the three-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth",
      "provenance" = "The pure box-closing round, no new ink: the issue-8 box in tools/reports/dragon_gap_report_008.md flips closed (1 / 0), completing the issue-8 walk exactly as adjudicated at R910 - the Gygax Planes article, the Watson towns article and the Kuntz gems re-evaluation having been the only engine-relevant ink in issue #8 (the Finzer Family fiction, the Gamma World preview, the Featured Creature contest, the MA chains, the figure reviews, the editorial, the ads and the Fenn Manor ad all scoped out). The bookkeeping pins: the single box and its three chains, the issue-7 report complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, and the registry ground truth carried forward (the 1311 live census, the 1333 base lua files, the 25 never-load errors - the battery line the only ground truth, a pre-R900 print-fidelity state untouched).",
      "sentinel" = "The variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the pin IS the conversion, and the R910 AS-SCANNED garbles (the swapped worked-example labels, the starred carat rows, the Table C lists riding the transcript) stay noted in the opener round, never silent.",
    },
  "consts" = { {
      "name" = "cgxReportBoxes",
      "value" = 1,
      "comment" = "the issue-8 gap report carries one box (report 008)",
    }, {
      "name" = "cgxIssue8Chains",
      "value" = 3,
      "comment" = "the issue-8 opener pinned three chains - the Gygax Planes article, the Watson towns article, the Kuntz gems re-evaluation (R910)",
    }, {
      "name" = "cgxIssue7Closed",
      "value" = 1,
      "comment" = "the issue-7 report has sat complete at 1 closed / 0 open since R909",
    }, {
      "name" = "cgxIssue6Closed",
      "value" = 1,
      "comment" = "the issue-6 report has sat complete at 1 closed / 0 open since R907",
    }, {
      "name" = "cgxLiveRegistry",
      "value" = 1311,
      "comment" = "the live registry census floor, carried forward from R900",
    }, {
      "name" = "cgxBaseLuaFiles",
      "value" = 1333,
      "comment" = "the base lua file count the R900 promotion measured against",
    }, {
      "name" = "cgxRegistryLoadErrors",
      "value" = 25,
      "comment" = "the base never-load errors - the battery line is the only ground truth",
    } },
  "bools" = { {
      "name" = "cgxIssue6WalkComplete",
      "value" = true,
      "comment" = "the issue-6 walk completed at R907",
    }, {
      "name" = "cgxIssue7WalkComplete",
      "value" = true,
      "comment" = "the issue-7 walk completed at R909",
    }, {
      "name" = "cgxIssue8WalkComplete",
      "value" = true,
      "comment" = "the issue-8 walk completes with this round - the Planes, towns and gems chains were the only engine-relevant ink in issue #8",
    }, {
      "name" = "cgxVariantLayerDoctrine",
      "value" = true,
      "comment" = "the variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the conversions noted, never silent",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['cgxReportBoxes']() != 1 or m['cgxIssue8Chains']() != 3 or m['cgxIssue7Closed']() != 1 or m['cgxIssue6Closed']() != 1",
      "note" = "the walk bookkeeping - the single issue-8 box and its three chains, the issue-7 and issue-6 reports complete at 1 / 0",
    }, {
      "expr" = "m['cgxLiveRegistry']() != 1311 or m['cgxBaseLuaFiles']() != 1333 or m['cgxRegistryLoadErrors']() != 25",
      "note" = "the registry ground truth carried forward - the 1311 live census, the 1333 base lua files, the 25 never-load errors, the battery line the only ground truth",
    }, {
      "expr" = "m['cgxIssue6WalkComplete']() != 1 or m['cgxIssue7WalkComplete']() != 1 or m['cgxIssue8WalkComplete']() != 1 or m['cgxVariantLayerDoctrine']() != 1",
      "note" = "the three walks complete - issue 6 at R907, issue 7 at R909, issue 8 at this round - and the variant-layer doctrine riding the closure",
    } },
  "audit" = {
      "label" = "R911 Dragon issue-8 closure audit",
      "comment" = "THE DRAGON ISSUE-8 BOX CLOSING ROUND - the pure bookkeeping round, no new print ink. The flip: the issue-8 box in tools/reports/dragon_gap_report_008.md goes [x] - 1 closed / 0 open, the issue-8 walk complete, the three chains (the Gygax Planes article, the Watson towns article, the Kuntz gems re-evaluation at folios 4-5, 5-7, 22-23) having been the only engine-relevant ink in issue #8. The bookkeeping pins: the single box and its three chains, the issue-7 report complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, the registry ground truth carried forward (the 1311 live census against the 1333 base lua files with the 25 never-load errors, a pre-R900 print-fidelity state untouched), and the variant-layer doctrine riding the closure. The R910 record seats in the seed via prev_record.",
    },
}
