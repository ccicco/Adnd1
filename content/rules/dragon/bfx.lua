-- bfx: promoted from tools/spec_r918.json (the The Dragon issue-11 box closing round - the two-chain walk complete, the pure flip);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 918,
  "prefix" = "bfx",
  "banner" = {
      "title" = "The Dragon issue-11 box closing round - the two-chain walk complete, the pure flip",
      "provenance" = "Bookkeeping only, no new ink pinned. The issue-11 walk (R917 opener, this flip) covered The Dragon Vol. II No. 5 (December 1977), the archive.org scan voice, single-voice - no chat-side upload cross-check exists for issue 11; the source lives in the archive.org item accessory-dragon-magazine-012.",
      "sentinel" = "The brawling punch-grid sentinel cell and the quarterstaff worked-example discrepancy were pinned at R917 and ride unchanged - this round touches no ink.",
    },
  "consts" = { {
      "name" = "bfxIssueElevenBoxes",
      "value" = 1,
      "comment" = "the issue-11 gap report carries a single box (report 011)",
    }, {
      "name" = "bfxIssueElevenChains",
      "value" = 2,
      "comment" = "the issue-11 walk pinned two chains - the Kuntz brawling article and the Ward quarterstaff article",
    }, {
      "name" = "bfxIssueTenClosed",
      "value" = 1,
      "comment" = "the issue-10 report complete at 2 closed / 0 open since R916",
    }, {
      "name" = "bfxIssueNineClosed",
      "value" = 1,
      "comment" = "the issue-9 report complete at 1 closed / 0 open since R913",
    }, {
      "name" = "bfxIssueEightClosed",
      "value" = 1,
      "comment" = "the issue-8 report complete at 1 closed / 0 open since R911",
    }, {
      "name" = "bfxIssueSevenClosed",
      "value" = 1,
      "comment" = "the issue-7 report complete at 1 closed / 0 open since R909",
    }, {
      "name" = "bfxIssueSixClosed",
      "value" = 1,
      "comment" = "the issue-6 report complete at 1 closed / 0 open since R907",
    }, {
      "name" = "bfxRegistryLive",
      "value" = 1311,
      "comment" = "the registry ground truth - live lua files, the battery line the only ground truth",
    }, {
      "name" = "bfxRegistryBaseLua",
      "value" = 1333,
      "comment" = "the registry ground truth - base lua files",
    }, {
      "name" = "bfxRegistryNeverLoad",
      "value" = 25,
      "comment" = "the registry ground truth - never-load errors",
    } },
  "bools" = { {
      "name" = "bfxWalkSixComplete",
      "value" = true,
      "comment" = "the Dragon issue-6 walk complete since R907",
    }, {
      "name" = "bfxWalkSevenComplete",
      "value" = true,
      "comment" = "the Dragon issue-7 walk complete since R909",
    }, {
      "name" = "bfxWalkEightComplete",
      "value" = true,
      "comment" = "the Dragon issue-8 walk complete since R911",
    }, {
      "name" = "bfxWalkNineComplete",
      "value" = true,
      "comment" = "the Dragon issue-9 walk complete since R913",
    }, {
      "name" = "bfxWalkTenComplete",
      "value" = true,
      "comment" = "the Dragon issue-10 walk complete since R916",
    }, {
      "name" = "bfxWalkElevenComplete",
      "value" = true,
      "comment" = "the Dragon issue-11 walk complete at this flip - the brawling and quarterstaff chains were the only engine-relevant ink",
    }, {
      "name" = "bfxVariantLayerDoctrine",
      "value" = true,
      "comment" = "Dragon pins ride a VARIANT layer with provenance, never core canon",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['bfxIssueElevenBoxes']() != 1 or m['bfxIssueElevenChains']() != 2 or m['bfxIssueTenClosed']() != 1 or m['bfxIssueNineClosed']() != 1",
      "note" = "the walk census - one issue-11 box, two chains, the issue-10 and issue-9 reports complete",
    }, {
      "expr" = "m['bfxIssueEightClosed']() != 1 or m['bfxIssueSevenClosed']() != 1 or m['bfxIssueSixClosed']() != 1",
      "note" = "the earlier reports complete at one closed box each since R911, R909 and R907",
    }, {
      "expr" = "m['bfxRegistryLive']() != 1311 or m['bfxRegistryBaseLua']() != 1333 or m['bfxRegistryNeverLoad']() != 25",
      "note" = "the registry ground truth carried forward - 1311 live / 1333 base / 25 never-load, the battery line the only ground truth",
    } },
  "audit" = {
      "label" = "R918 Dragon issue-11 closure audit",
      "comment" = "THE DRAGON ISSUE-11 CLOSURE ROUND - the pure flip, no new ink. The issue-11 box (the Kuntz brawling article and the Ward quarterstaff article, folios 7 and 26-27) closes 1 closed / 0 open in tools/reports/dragon_gap_report_011.md; the two-chain walk completes exactly as adjudicated at R917. The bookkeeping pins: the single box and its two chains, the issue-10 report complete at 2 / 0 since R916, the issue-9 report complete at 1 / 0 since R913, the issue-8 report complete at 1 / 0 since R911, the issue-7 report complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, and the registry ground truth carried forward.",
    },
}
