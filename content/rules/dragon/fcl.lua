-- fcl: promoted from tools/spec_r921.json (the The Dragon issue-12 box closing round - the four-chain walk complete, the pure flip);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 921,
  "prefix" = "fcl",
  "banner" = {
      "title" = "The Dragon issue-12 box closing round - the four-chain walk complete, the pure flip",
      "provenance" = "Bookkeeping only, no new ink pinned. The issue-12 walk (R919 opener part one, R920 opener part two, this flip) covered The Dragon Vol. II No. 6 (February 1978), the archive.org scan voice, single-voice - no chat-side upload cross-check exists for issue 12; the source lives in the archive.org item accessory-dragon-magazine-012. Per the Curtiss call: no issue-13 opener follows - the walk ends here, the Name That Monster winners and the brawling long-term-effects sequel left unharvested for now.",
      "sentinel" = "The R919 and R920 sentinel pins ride unchanged - the cargo grid’s three blank/count cells, the illusionist ladder garbles, the Atar bar garbles, the Vayu move fraction, the five hero strength fraction garbles and the god-grid see-below and resistance cells all ride the -1 sentinel as pinned - this round touches no ink.",
    },
  "consts" = { {
      "name" = "fclIssueTwelveBoxes",
      "value" = 2,
      "comment" = "the issue-12 gap report carries two boxes (report 012)",
    }, {
      "name" = "fclIssueTwelveChains",
      "value" = 4,
      "comment" = "the issue-12 walk pinned four chains - the Ovalle illusionist article, the Endersby and Carroll ship cargo article, the Persian Mythos and the Lovecraftian Mythos",
    }, {
      "name" = "fclIssueTwelveRounds",
      "value" = 3,
      "comment" = "the issue-12 walk ran three rounds - the R919 opener part one, the R920 opener part two and this R921 flip",
    }, {
      "name" = "fclIssueElevenClosed",
      "value" = 1,
      "comment" = "the issue-11 report complete at 1 closed / 0 open since R918",
    }, {
      "name" = "fclIssueTenClosed",
      "value" = 1,
      "comment" = "the issue-10 report complete at 2 closed / 0 open since R916",
    }, {
      "name" = "fclIssueNineClosed",
      "value" = 1,
      "comment" = "the issue-9 report complete at 1 closed / 0 open since R913",
    }, {
      "name" = "fclIssueEightClosed",
      "value" = 1,
      "comment" = "the issue-8 report complete at 1 closed / 0 open since R911",
    }, {
      "name" = "fclIssueSevenClosed",
      "value" = 1,
      "comment" = "the issue-7 report complete at 1 closed / 0 open since R909",
    }, {
      "name" = "fclIssueSixClosed",
      "value" = 1,
      "comment" = "the issue-6 report complete at 1 closed / 0 open since R907",
    }, {
      "name" = "fclRegistryLive",
      "value" = 1311,
      "comment" = "the registry ground truth - live lua files, the battery line the only ground truth",
    }, {
      "name" = "fclRegistryBaseLua",
      "value" = 1333,
      "comment" = "the registry ground truth - base lua files",
    }, {
      "name" = "fclRegistryNeverLoad",
      "value" = 25,
      "comment" = "the registry ground truth - never-load errors",
    } },
  "bools" = { {
      "name" = "fclWalkSixComplete",
      "value" = true,
      "comment" = "the Dragon issue-6 walk complete since R907",
    }, {
      "name" = "fclWalkSevenComplete",
      "value" = true,
      "comment" = "the Dragon issue-7 walk complete since R909",
    }, {
      "name" = "fclWalkEightComplete",
      "value" = true,
      "comment" = "the Dragon issue-8 walk complete since R911",
    }, {
      "name" = "fclWalkNineComplete",
      "value" = true,
      "comment" = "the Dragon issue-9 walk complete since R913",
    }, {
      "name" = "fclWalkTenComplete",
      "value" = true,
      "comment" = "the Dragon issue-10 walk complete since R916",
    }, {
      "name" = "fclWalkElevenComplete",
      "value" = true,
      "comment" = "the Dragon issue-11 walk complete since R918",
    }, {
      "name" = "fclWalkTwelveComplete",
      "value" = true,
      "comment" = "the Dragon issue-12 walk complete at this flip - the illusionist, cargo, Persian and Lovecraftian chains were the engine-relevant ink of issue 12",
    }, {
      "name" = "fclVariantLayerDoctrine",
      "value" = true,
      "comment" = "Dragon pins ride a VARIANT layer with provenance, never core canon",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['fclIssueTwelveBoxes']() != 2 or m['fclIssueTwelveChains']() != 4 or m['fclIssueTwelveRounds']() != 3 or m['fclIssueElevenClosed']() != 1 or m['fclIssueTenClosed']() != 1",
      "note" = "the walk census - two issue-12 boxes, four chains across three rounds, the issue-11 and issue-10 reports complete",
    }, {
      "expr" = "m['fclIssueNineClosed']() != 1 or m['fclIssueEightClosed']() != 1 or m['fclIssueSevenClosed']() != 1 or m['fclIssueSixClosed']() != 1",
      "note" = "the earlier reports complete at one closed box each since R913, R911, R909 and R907",
    }, {
      "expr" = "m['fclRegistryLive']() != 1311 or m['fclRegistryBaseLua']() != 1333 or m['fclRegistryNeverLoad']() != 25",
      "note" = "the registry ground truth carried forward - 1311 live / 1333 base / 25 never-load",
    } },
  "audit" = {
      "label" = "R921 Dragon issue-12 closure audit",
      "comment" = "THE DRAGON ISSUE-12 CLOSURE ROUND - the pure flip, no new ink. The issue-12 part-two box (the Persian Mythos and the Lovecraftian Mythos, folios 8-11 and 18-21) closes 2 closed / 0 open in tools/reports/dragon_gap_report_012.md; the four-chain walk completes exactly as adjudicated - the R919 part-one pair (the Ovalle illusionist article and the Endersby and Carroll ship cargo article) and the R920 part-two pair (the Arkenberg Persian Mythos and the Kuntz/Holmes Lovecraftian Mythos). The bookkeeping pins: the two boxes and their four chains, the issue-11 report complete at 1 / 0 since R918, the issue-10 report complete at 2 / 0 since R916, the issue-9 report complete at 1 / 0 since R913, the issue-8 report complete at 1 / 0 since R911, the issue-7 report complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, and the registry ground truth carried forward. Per the Curtiss call this round ends the issue-12 walk with NO issue-13 opener to follow.",
    },
}
