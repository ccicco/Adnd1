-- cpx: promoted from tools/spec_r909.json (the The Dragon issue-7 box closing round - the thin walk complete: the pure bookkeeping round, the flip and the registry ground truth);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 909,
  "prefix" = "cpx",
  "banner" = {
      "title" = "The Dragon issue-7 box closing round - the thin walk complete: the pure bookkeeping round, the flip and the registry ground truth",
      "provenance" = "The pure box-closing round, no new ink: the issue-7 box in tools/dragon_gap_report_007.md flips closed (1 / 0), completing the issue-7 walk exactly as adjudicated at R908 - the Prowler having been the only engine-relevant ink in issue #7 (the Gygax origins history, the awards ballot, the diceless-play piece, Mystery Hill, the fiction, the Space Marines feature, the EPT military formations, the figure painting, the comic, the Gnome Cache as ideas-usable, the Editor's Library, the editorial, the ads and the mapping registry all scoped out). The bookkeeping pins: the single box and its single chain, the issue-6 report complete at 1 / 0 since R907, the issue-5 report complete at 1 / 0 since R903, and the registry ground truth carried forward (the 1311 live census, the 1333 base lua files, the 25 never-load errors - the battery line the only ground truth, a pre-R900 print-fidelity state untouched).",
      "sentinel" = "The variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the pin IS the conversion, and the R908 judgments (the DMG p.85 special/exceptional count, the AS-SCANNED zombei spelling, the not-printed treasure and size lines) stay noted in the opener round, never silent.",
    },
  "consts" = { {
      "name" = "cpxReportBoxes",
      "value" = 1,
      "comment" = "the issue-7 gap report carries one box (report 007)",
    }, {
      "name" = "cpxIssue7Chains",
      "value" = 1,
      "comment" = "the issue-7 opener pinned one chain - the Prowler, the thin single-chain harvest (R908)",
    }, {
      "name" = "cpxIssue6Closed",
      "value" = 1,
      "comment" = "the issue-6 report has sat complete at 1 closed / 0 open since R907",
    }, {
      "name" = "cpxIssue5Closed",
      "value" = 1,
      "comment" = "the issue-5 report has sat complete at 1 closed / 0 open since R903",
    }, {
      "name" = "cpxLiveRegistry",
      "value" = 1311,
      "comment" = "the live registry census floor, carried forward from R900",
    }, {
      "name" = "cpxBaseLuaFiles",
      "value" = 1333,
      "comment" = "the base lua file count the R900 promotion measured against",
    }, {
      "name" = "cpxRegistryLoadErrors",
      "value" = 25,
      "comment" = "the base never-load errors - the battery line is the only ground truth",
    } },
  "bools" = { {
      "name" = "cpxIssue5WalkComplete",
      "value" = true,
      "comment" = "the issue-5 walk completed at R903",
    }, {
      "name" = "cpxIssue6WalkComplete",
      "value" = true,
      "comment" = "the issue-6 walk completed at R907",
    }, {
      "name" = "cpxIssue7WalkComplete",
      "value" = true,
      "comment" = "the issue-7 walk completes with this round - the Prowler was the only engine-relevant ink in issue #7",
    }, {
      "name" = "cpxVariantLayerDoctrine",
      "value" = true,
      "comment" = "the variant-layer doctrine rides the closure: Dragon ink is never core 1e canon, the conversions noted, never silent",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['cpxReportBoxes']() != 1 or m['cpxIssue7Chains']() != 1 or m['cpxIssue6Closed']() != 1 or m['cpxIssue5Closed']() != 1",
      "note" = "the walk bookkeeping - the single issue-7 box and its single chain, the issue-6 and issue-5 reports complete at 1 / 0",
    }, {
      "expr" = "m['cpxLiveRegistry']() != 1311 or m['cpxBaseLuaFiles']() != 1333 or m['cpxRegistryLoadErrors']() != 25",
      "note" = "the registry ground truth carried forward - the 1311 live census, the 1333 base lua files, the 25 never-load errors, the battery line the only ground truth",
    }, {
      "expr" = "m['cpxIssue5WalkComplete']() != 1 or m['cpxIssue6WalkComplete']() != 1 or m['cpxIssue7WalkComplete']() != 1 or m['cpxVariantLayerDoctrine']() != 1",
      "note" = "the three walks complete - issue 5 at R903, issue 6 at R907, issue 7 at this round - and the variant-layer doctrine riding the closure",
    } },
  "audit" = {
      "label" = "R909 Dragon issue-7 closure audit",
      "comment" = "THE DRAGON ISSUE-7 BOX CLOSING ROUND - the pure bookkeeping round, no new print ink. The flip: the issue-7 box in tools/dragon_gap_report_007.md goes [x] - 1 closed / 0 open, the issue-7 walk complete, the Prowler (folio 24) having been the only engine-relevant ink in issue #7. The bookkeeping pins: the single box and its single chain, the issue-6 report complete at 1 / 0 since R907, the issue-5 report complete at 1 / 0 since R903, the registry ground truth carried forward (the 1311 live census against the 1333 base lua files with the 25 never-load errors, a pre-R900 print-fidelity state untouched), and the variant-layer doctrine riding the closure. The R908 record seats in the seed via prev_record.",
    },
}
