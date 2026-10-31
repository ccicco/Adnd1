-- dnp: promoted from tools/spec_r913.json (the The Dragon issue-9 box closing round - the two-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 913,
  "prefix" = "dnp",
  "banner" = {
      "title" = "The Dragon issue-9 box closing round - the two-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth",
      "provenance" = "The pure box-closing round, no new ink: the issue-9 box in tools/dragon_gap_report_009.md flips closed (1 / 0), completing the issue-9 walk exactly as adjudicated at R912 - the Gygax alignment article and the Ward Tombs & Crypts article having been the only engine-relevant ink in issue #9 (the Finzer Family fiction, the Barker EPT column, the Blume Boot Hill ratings, the comics, the ads and the editorial all scoped out). The bookkeeping pins: the single box and its two chains, the issue-8 report complete at 1 / 0 since R911, the issue-7 report complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, and the registry ground truth carried forward (the 1311 live census, the 1333 base lua files, the 25 never-load errors - the battery line the only ground truth, a pre-R900 print-fidelity state untouched).",
      "sentinel" = "The variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the pin IS the conversion, and the R912 AS-SCANNED quirks (the gold-piece x2 row and the garbled 100 row, the garbled guardian tail, the modifier grid riding the transcript) stay noted in the opener round, never silent.",
    },
  "consts" = { {
      "name" = "dnpReportBoxes",
      "value" = 1,
      "comment" = "the issue-9 gap report carries one box (report 009)",
    }, {
      "name" = "dnpIssue9Chains",
      "value" = 2,
      "comment" = "the issue-9 opener pinned two chains - the Gygax alignment article and the Ward Tombs & Crypts article (R912)",
    }, {
      "name" = "dnpIssue8Closed",
      "value" = 1,
      "comment" = "the issue-8 report has sat complete at 1 closed / 0 open since R911",
    }, {
      "name" = "dnpIssue7Closed",
      "value" = 1,
      "comment" = "the issue-7 report has sat complete at 1 closed / 0 open since R909",
    }, {
      "name" = "dnpIssue6Closed",
      "value" = 1,
      "comment" = "the issue-6 report has sat complete at 1 closed / 0 open since R907",
    }, {
      "name" = "dnpLiveRegistry",
      "value" = 1311,
      "comment" = "the live registry census floor, carried forward from R900",
    }, {
      "name" = "dnpBaseLuaFiles",
      "value" = 1333,
      "comment" = "the base lua file count the R900 promotion measured against",
    }, {
      "name" = "dnpRegistryLoadErrors",
      "value" = 25,
      "comment" = "the base never-load errors - the battery line is the only ground truth",
    } },
  "bools" = { {
      "name" = "dnpIssue6WalkComplete",
      "value" = true,
      "comment" = "the issue-6 walk completed at R907",
    }, {
      "name" = "dnpIssue7WalkComplete",
      "value" = true,
      "comment" = "the issue-7 walk completed at R909",
    }, {
      "name" = "dnpIssue8WalkComplete",
      "value" = true,
      "comment" = "the issue-8 walk completed at R911",
    }, {
      "name" = "dnpIssue9WalkComplete",
      "value" = true,
      "comment" = "the issue-9 walk completes with this round - the Gygax alignment and Ward tomb chains were the only engine-relevant ink in issue #9",
    }, {
      "name" = "dnpVariantLayerDoctrine",
      "value" = true,
      "comment" = "the variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the conversions noted, never silent",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnpReportBoxes']() != 1 or m['dnpIssue9Chains']() != 2 or m['dnpIssue8Closed']() != 1 or m['dnpIssue7Closed']() != 1 or m['dnpIssue6Closed']() != 1",
      "note" = "the walk bookkeeping - the single issue-9 box and its two chains, the issue-8, issue-7 and issue-6 reports complete at 1 / 0",
    }, {
      "expr" = "m['dnpLiveRegistry']() != 1311 or m['dnpBaseLuaFiles']() != 1333 or m['dnpRegistryLoadErrors']() != 25",
      "note" = "the registry ground truth carried forward - the 1311 live census, the 1333 base lua files, the 25 never-load errors, the battery line the only ground truth",
    }, {
      "expr" = "m['dnpIssue6WalkComplete']() != 1 or m['dnpIssue7WalkComplete']() != 1 or m['dnpIssue8WalkComplete']() != 1 or m['dnpIssue9WalkComplete']() != 1 or m['dnpVariantLayerDoctrine']() != 1",
      "note" = "the four walks complete - issue 6 at R907, issue 7 at R909, issue 8 at R911, issue 9 at this round - and the variant-layer doctrine riding the closure",
    } },
  "audit" = {
      "label" = "R913 Dragon issue-9 closure audit",
      "comment" = "THE DRAGON ISSUE-9 CLOSURE ROUND - the pure flip. The issue-9 box (the Gygax alignment article and the Ward Tombs & Crypts article, folios 5-6 and 25) closes 1 / 0 in tools/dragon_gap_report_009.md; the two-chain walk completes exactly as adjudicated at R912. The bookkeeping pins: the single box and its two chains, the issue-8 report complete at 1 / 0 since R911, the issue-7 report complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, and the registry ground truth carried forward.",
    },
}
