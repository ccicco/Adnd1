-- cwx: promoted from tools/spec_r903.json (the The Dragon issue-5 box closing round - the three-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 903,
  "prefix" = "cwx",
  "banner" = {
      "title" = "The Dragon issue-5 box closing round - the three-chain walk complete: the pure bookkeeping round, the flip and the registry ground truth",
      "provenance" = "The pure box-closing round, no new ink: the issue-5 box in tools/reports/dragon_gap_report_005.md flips closed (1 / 0), completing the issue-5 walk exactly as adjudicated at R902 - the Witchcraft Supplement variant layer, the Anhkheg lore-against-def pin and the Wizard Research Rules having been the only engine-relevant ink in issue #5 (the Metamorphosis Alpha chains, the fiction, the Tolkien lore chain, the Gandalf analysis, the letters, the ads and the preview all scoped out). The bookkeeping pins: the single box and its three chains, the issue-4 report already complete at 1 / 0, and the registry ground truth carried forward (the 1311 live census, the 1333 base lua files, the 25 never-load errors - the battery line the only ground truth).",
      "sentinel" = "The pure flip round: no new print ink, no file patches, no data files - only the box closing, the walk bookkeeping consts and the variant-layer doctrine riding the closure. A report cannot flip in the round that creates it; the R902 opener shipped report 005 pre-flip, and this round is the flip the pre-flip rule promised. The registry ground truth stays pinned as consts so the closure carries the same live-census discipline as the rounds that created it.",
    },
  "consts" = { {
      "name" = "cwxReportBoxes",
      "value" = 1,
      "comment" = "the issue-5 report carries a single box - the three-chain opener at folios 4-9, 12+28, 24-26+28 (tools/reports/dragon_gap_report_005.md); this round flips it closed, 1 closed / 0 open, the walk complete",
    }, {
      "name" = "cwxIssue5Chains",
      "value" = 3,
      "comment" = "the three adjudicated chains riding the box - the Witchcraft Supplement (the variant layer), the Anhkheg (the lore-against-def pin vs the merged MM1 ankheg def) and the Wizard Research Rules (folios 4-9, 12+28, 24-26+28)",
    }, {
      "name" = "cwxIssue4Closed",
      "value" = 1,
      "comment" = "the issue-4 report sits complete at 1 closed / 0 open since the R901 flip (tools/reports/dragon_gap_report_004.md)",
    }, {
      "name" = "cwxLiveRegistry",
      "value" = 1311,
      "comment" = "the live registry ground truth - 1308 loaded base defs + the three R900 promotions = 1311; the battery line loaded N, errors M is the only ground truth for registry floors (the R900 lesson, pinned as cfc consts at R901)",
    }, {
      "name" = "cwxBaseLuaFiles",
      "value" = 1333,
      "comment" = "the base lua file count - 1333 files against the 1311 live census, the difference the 25 long-broken MM2/FF text lines that never load",
    }, {
      "name" = "cwxRegistryLoadErrors",
      "value" = 25,
      "comment" = "the 25 long-standing load-error defs, a pre-R900 print-fidelity state untouched",
    } },
  "bools" = { {
      "name" = "cwxIssue4WalkComplete",
      "value" = true,
      "comment" = "the issue-4 walk is complete - 1 closed / 0 open since R901 (tools/reports/dragon_gap_report_004.md)",
    }, {
      "name" = "cwxIssue5WalkComplete",
      "value" = true,
      "comment" = "the issue-5 walk is complete at this round's flip - the three-chain box closed, 1 / 0 (tools/reports/dragon_gap_report_005.md)",
    }, {
      "name" = "cwxVariantLayerDoctrine",
      "value" = true,
      "comment" = "the variant-layer doctrine rides the closure - Dragon ink is never core 1e canon; the Witchcraft Supplement and the Wizard Research Rules pin as variant layers, the Anhkheg as lore-against-def provenance, never a competing def",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['cwxReportBoxes']() != 1 or m['cwxIssue5Chains']() != 3 or m['cwxIssue4Closed']() != 1",
      "note" = "the walk bookkeeping - the issue-5 single box closing over its three chains, and the issue-4 report complete at 1 / 0 (gap reports 004 and 005)",
    }, {
      "expr" = "m['cwxLiveRegistry']() != 1311 or m['cwxBaseLuaFiles']() != 1333 or m['cwxRegistryLoadErrors']() != 25",
      "note" = "the registry ground truth - 1311 live defs against the 1333 base files with the 25 never-load errors (the R900 lesson)",
    }, {
      "expr" = "m['cwxIssue4WalkComplete']() != 1 or m['cwxIssue5WalkComplete']() != 1 or m['cwxVariantLayerDoctrine']() != 1",
      "note" = "the walk-complete bools for issues 4 and 5, and the variant-layer doctrine riding the closure",
    } },
  "audit" = {
      "label" = "R903 Dragon issue-5 closure audit",
      "comment" = "THE DRAGON ISSUE-5 BOX CLOSING ROUND - the pure bookkeeping round, no new print ink. The flip: the issue-5 box in tools/reports/dragon_gap_report_005.md goes [x] - 1 closed / 0 open, the issue-5 walk complete, the three chains (the Witchcraft Supplement, the Anhkheg lore-against-def pin, the Wizard Research Rules at folios 4-9, 12+28, 24-26+28) having been the only engine-relevant ink in issue #5. The bookkeeping pins: the single box and its three chains, the issue-4 report complete at 1 / 0 since R901, the registry ground truth carried forward (the 1311 live census against the 1333 base lua files with the 25 never-load errors, a pre-R900 print-fidelity state untouched), and the variant-layer doctrine riding the closure. The R902 record seats in the seed via prev_record.",
    },
}
