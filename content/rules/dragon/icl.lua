-- icl: promoted from tools/spec_r924.json (the The Dragon issue-13 box closing round - the three-chain walk complete, the pure flip);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 924,
  "prefix" = "icl",
  "banner" = {
      "title" = "The Dragon issue-13 box closing round - the three-chain walk complete, the pure flip",
      "provenance" = "Bookkeeping only, no new ink pinned. The issue-13 walk (R922 opener part one, R923 opener part two, this flip) covered The Dragon Vol. II No. 7 (April 1978), the archive.org scan voice, single-voice - no chat-side upload cross-check exists for issue 13; the source lives in the archive.org item accessory-dragon-magazine-012, which holds issues 7-14. The transcripts ride extract/dragon/013/p001 through p032, landed at R922.",
      "sentinel" = "The R922 and R923 sentinel pins ride unchanged - the giant grid pounds and torso vision-resolved ladders, the quarter-ton tons and tenths materials conversions, the demon power grid, the sixteen see-below magic cells, the Aizen-Myoo and Light/Shade bar-garble armor classes, the seven hero strength fraction garbles and the two Sth-noted fighter cells all ride the -1 sentinel as-scanned, never silent. The registry ground truth re-measured at the R922 battery: 1313 loaded / 1338 base / 25 never-load, superseding the R900-era snapshot, the growth noted.",
    },
  "consts" = { {
      "name" = "iclIssueThirteenBoxes",
      "value" = 2,
      "comment" = "the issue-13 gap report carries two boxes (report 013)",
    }, {
      "name" = "iclIssueThirteenChains",
      "value" = 3,
      "comment" = "the issue-13 walk pinned three chains - the Shlump da Orc giant physics article, the Jon Pickens demon generation article and the Arkenberg Japanese Mythos",
    }, {
      "name" = "iclIssueThirteenRounds",
      "value" = 3,
      "comment" = "the issue-13 walk ran three rounds - the R922 opener part one, the R923 opener part two and this R924 flip",
    }, {
      "name" = "iclIssueTwelveClosed",
      "value" = 1,
      "comment" = "the issue-12 report complete at 2 closed / 0 open since R921",
    }, {
      "name" = "iclIssueElevenClosed",
      "value" = 1,
      "comment" = "the issue-11 report complete at 1 closed / 0 open since R918",
    }, {
      "name" = "iclIssueTenClosed",
      "value" = 1,
      "comment" = "the issue-10 report complete at 2 closed / 0 open since R916",
    }, {
      "name" = "iclIssueNineClosed",
      "value" = 1,
      "comment" = "the issue-9 report complete at 1 closed / 0 open since R913",
    }, {
      "name" = "iclIssueEightClosed",
      "value" = 1,
      "comment" = "the issue-8 report complete at 1 closed / 0 open since R911",
    }, {
      "name" = "iclIssueSevenClosed",
      "value" = 1,
      "comment" = "the issue-7 report complete at 1 closed / 0 open since R909",
    }, {
      "name" = "iclIssueSixClosed",
      "value" = 1,
      "comment" = "the issue-6 report complete at 1 closed / 0 open since R907",
    }, {
      "name" = "iclRegistryLoaded",
      "value" = 1313,
      "comment" = "the registry ground truth re-measured at the R922 battery line - 1313 defs loaded, the battery line the only ground truth, superseding the R900-era 1308-loaded snapshot the R921 closer carried forward",
    }, {
      "name" = "iclRegistryBaseLua",
      "value" = 1338,
      "comment" = "the registry ground truth - 1338 base lua files at the R922 battery, five more than the R900-era 1333 snapshot, the growth noted never silent",
    }, {
      "name" = "iclRegistryNeverLoad",
      "value" = 25,
      "comment" = "the registry ground truth - 25 long-standing never-load errors, unchanged since the R900 snapshot (1313 loaded + 25 never-load = 1338 base)",
    } },
  "bools" = { {
      "name" = "iclWalkSixComplete",
      "value" = true,
      "comment" = "the Dragon issue-6 walk complete since R907",
    }, {
      "name" = "iclWalkSevenComplete",
      "value" = true,
      "comment" = "the Dragon issue-7 walk complete since R909",
    }, {
      "name" = "iclWalkEightComplete",
      "value" = true,
      "comment" = "the Dragon issue-8 walk complete since R911",
    }, {
      "name" = "iclWalkNineComplete",
      "value" = true,
      "comment" = "the Dragon issue-9 walk complete since R913",
    }, {
      "name" = "iclWalkTenComplete",
      "value" = true,
      "comment" = "the Dragon issue-10 walk complete since R916",
    }, {
      "name" = "iclWalkElevenComplete",
      "value" = true,
      "comment" = "the Dragon issue-11 walk complete since R918",
    }, {
      "name" = "iclWalkTwelveComplete",
      "value" = true,
      "comment" = "the Dragon issue-12 walk complete since R921",
    }, {
      "name" = "iclWalkThirteenComplete",
      "value" = true,
      "comment" = "the Dragon issue-13 walk complete at this flip - the giant physics, demon generation and Japanese Mythos chains were the engine-relevant ink, the Tolkien Scroll, Bionic Supplement, WARLORD, songs, fiction, comics, contest rules and Notes column scoped out per the ALL-USABLE adjudication",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['iclIssueThirteenBoxes']() != 2 or m['iclIssueThirteenChains']() != 3 or m['iclIssueThirteenRounds']() != 3 or m['iclIssueTwelveClosed']() != 1 or m['iclIssueElevenClosed']() != 1",
      "note" = "the walk census - two issue-13 boxes, three chains across three rounds, the issue-12 and issue-11 reports complete",
    }, {
      "expr" = "m['iclIssueTenClosed']() != 1 or m['iclIssueNineClosed']() != 1 or m['iclIssueEightClosed']() != 1 or m['iclIssueSevenClosed']() != 1 or m['iclIssueSixClosed']() != 1 or m['iclWalkThirteenComplete']() != 1 or m['iclWalkTwelveComplete']() != 1",
      "note" = "the earlier reports complete at one closed box each since R916, R913, R911, R909 and R907, the issue-13 and issue-12 walks complete",
    }, {
      "expr" = "m['iclRegistryLoaded']() != 1313 or m['iclRegistryBaseLua']() != 1338 or m['iclRegistryNeverLoad']() != 25 or m['iclWalkSixComplete']() != 1 or m['iclWalkElevenComplete']() != 1",
      "note" = "the registry ground truth re-measured - 1313 loaded / 1338 base / 25 never-load at the R922 battery, the issue-6 and issue-11 walks complete",
    } },
  "audit" = {
      "label" = "R924 Dragon issue-13 closure audit",
      "comment" = "THE DRAGON ISSUE-13 CLOSURE ROUND - the pure flip, no new ink. The issue-13 part-two box (the Arkenberg Japanese Mythos, folios 11-15) closes 2 closed / 0 open in tools/dragon_gap_report_013.md; the three-chain walk completes exactly as adjudicated - the R922 part-one pair (the Shlump da Orc giant physics article and the Jon Pickens demon generation article) and the R923 part-two chain (the Japanese Mythos). The bookkeeping pins: the two boxes and their three chains, the issue-12 report complete at 2 / 0 since R921, the issue-11 report complete at 1 / 0 since R918, the issue-10 report complete at 2 / 0 since R916, the issue-9 report complete at 1 / 0 since R913, the issue-8 report complete at 1 / 0 since R911, the issue-7 report complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, and the registry ground truth RE-MEASURED at the R922 battery line - 1313 defs loaded, 1338 base lua files, 25 never-load errors - superseding the R900-era 1311-live / 1333-base snapshot the R921 closer carried forward, the five-file growth noted never silent; the R921 fcl pins stay as landed, the historical snapshot they are. Per the Curtiss ALL-USABLE call the scoped-out ink stays scoped - the Tolkien Sorcerer Scroll commentary, the Bionic Supplement, the WARLORD corrections, the silly songs, the Stolen Sacrifice fiction, the comics, the contest rules and the Notes column - and the two slipped teasers harvest at issue 14: the Creature Contest #1 winner stats (the Jarnkung, the Cursed Crimson Crawler, the Ulik) print in TD 14.",
    },
}
