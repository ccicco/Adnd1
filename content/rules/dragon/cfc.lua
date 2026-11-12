-- cfc: promoted from tools/spec_r901.json (the The Creature Features box closing round - the issue-4 walk complete: the pure bookkeeping round, the flip and the registry ground truth);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 901,
  "prefix" = "cfc",
  "banner" = {
      "title" = "The Creature Features box closing round - the issue-4 walk complete: the pure bookkeeping round, the flip and the registry ground truth",
      "provenance" = "The pure box-closing round, no new ink: the Creature Features box in tools/reports/dragon_gap_report_004.md flips closed (1 / 0), completing the issue-4 walk exactly as adjudicated at R900 - the Creature Features chain was the only engine-relevant chain in The Dragon Vol. 1 No. 4 (December 1976); everything else was scoped out (the EPT campaign chains, the Metamorphosis Alpha androids, the Jaquet Oddball parody, the fiction, Finieous Fingers, Wargaming World, the Temple pictorial, Mapping the Dungeons, the ads and the preview). The R900 record seats in the seed this round.",
      "sentinel" = "The pure-round doctrine: a closing round carries no new print ink - only the flip and the walk bookkeeping, every number cited to its standing record; the registry ground truth pins as the R900 lesson taught: 1311 loaded live against 1333 files with 25 never-load errors, the battery line 'loaded N, errors M' the only ground truth for registry floors, never the file count; the 25 broken MM2/FF text lines stay untouched, a pre-R900 print-fidelity state; the variant-layer doctrine holds at the closure - Dragon ink is never core 1e canon.",
    },
  "consts" = { {
      "name" = "cfcReportBoxes",
      "value" = 1,
      "comment" = "the issue-4 report carries a single box - the Creature Features chain at folios 18-19, 21 (tools/reports/dragon_gap_report_004.md); this round flips it closed, 1 closed / 0 open, the walk complete",
    }, {
      "name" = "cfcCreatureFeaturesDefs",
      "value" = 3,
      "comment" = "the three Creature Features lua defs riding the box - the Mihalli, the Vriyagga and the Qu'uni, promoted at R900 (folios 18-19, 21)",
    }, {
      "name" = "cfcIssue3Closed",
      "value" = 5,
      "comment" = "the issue-3 report closed 5 / 0 at the R900 flip - the adjudicated issue-3 walk complete (tools/reports/dragon_gap_report_003.md)",
    }, {
      "name" = "cfcLiveRegistry",
      "value" = 1311,
      "comment" = "the live lua def census the Termux battery prints - 'loaded 1311, errors 25' is the ground truth after the three promotions (the R900 lesson: registry floors pin to the battery line, never to the file count)",
    }, {
      "name" = "cfcBaseLuaFiles",
      "value" = 1333,
      "comment" = "the base lua FILE count under monsters/monsters/ - never the loaded count; 25 files never enter the registry (the R900 lesson)",
    }, {
      "name" = "cfcRegistryLoadErrors",
      "value" = 25,
      "comment" = "the long-broken base defs that never load - unfinished-string lua errors at their text lines, a pre-R900 print-fidelity state this round does not touch",
    } },
  "bools" = { {
      "name" = "cfcIssue3WalkComplete",
      "value" = true,
      "comment" = "the issue-3 walk is complete - 5 boxes closed / 0 open at the R900 flip (tools/reports/dragon_gap_report_003.md)",
    }, {
      "name" = "cfcIssue4WalkComplete",
      "value" = true,
      "comment" = "the issue-4 walk is complete at this round's flip - the Creature Features box closed, 1 / 0 (tools/reports/dragon_gap_report_004.md)",
    }, {
      "name" = "cfcVariantLayerDoctrine",
      "value" = true,
      "comment" = "the standing doctrine rides the closure: the pin IS the conversion, Dragon ink rides a VARIANT layer with provenance, never core 1e canon (the report 004 doctrine line)",
    }, {
      "name" = "cfcPreR900LoadErrorState",
      "value" = true,
      "comment" = "the 25 load errors pre-date R900 entirely - MM2/FF-era text lines, untouched by the walk rounds and left as-is per the print-fidelity doctrine",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['cfcReportBoxes']() != 1 or m['cfcCreatureFeaturesDefs']() != 3 or m['cfcIssue3Closed']() != 5",
      "note" = "the walk bookkeeping - the issue-4 single box closing over its three defs, and the issue-3 report complete at 5 / 0 (gap reports 003 and 004)",
    }, {
      "expr" = "m['cfcLiveRegistry']() != 1311 or m['cfcBaseLuaFiles']() != 1333 or m['cfcRegistryLoadErrors']() != 25",
      "note" = "the registry ground truth - 1311 loaded live, 1333 files on disk, 25 never-load errors: the battery line is the ground truth, never the file count (the R900 lesson)",
    }, {
      "expr" = "m['cfcIssue3WalkComplete']() != 1 or m['cfcIssue4WalkComplete']() != 1 or m['cfcVariantLayerDoctrine']() != 1 or m['cfcPreR900LoadErrorState']() != 1",
      "note" = "the closure doctrines - issue 3 complete, issue 4 complete at this flip, the variant layer standing, the 25 errors a pre-R900 state",
    } },
  "audit" = {
      "label" = "R901 Creature Features closure audit",
      "comment" = "THE CREATURE FEATURES BOX CLOSING ROUND - the pure bookkeeping round, no new print ink. The flip: the Creature Features box in tools/reports/dragon_gap_report_004.md goes [x] - 1 closed / 0 open, the issue-4 walk complete, the chain (the Mihalli, the Vriyagga, the Qu'uni at folios 18-19, 21) having been the only engine-relevant ink in issue #4. The bookkeeping pins: the single box and its three defs, the issue-3 report complete at 5 / 0, and the registry ground truth from the R900 lesson - the live census 1311 against the 1333 base lua files with the 25 never-load errors, the battery line 'loaded 1311, errors 25' the only ground truth for registry floors; the 25 long-broken MM2/FF text lines are a pre-R900 print-fidelity state, untouched. The R900 record seats in the seed via this round's prev_record. No file patches, no data files, no tables - the census rides 823 -> 824.",
    },
}
