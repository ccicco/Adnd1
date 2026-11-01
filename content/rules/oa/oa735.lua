-- oa735: promoted from rules/oa106table74.h (the OA TREASURE - TABLE 74, MONETARY TREASURE AND MAGICAL ITEMS, printed);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 735,
  "prefix" = "oa735",
  "banner" = {
      "title" = "OA TREASURE - TABLE 74, MONETARY TREASURE AND MAGICAL ITEMS, printed",
      "provenance" = "capture p. 286 - the treasure type grid round census 657 -> 658.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 188 closed, 47 open - the Table 74 box flips (census 657 -> 658); NEXT - R736: Table II.A. (Orient): Monetary Treasure (capture p. 286), prefix dkx (verify free at the landing), audit \"R736 OA Table II.A. Orient monetary treasure audit\", include after rules/oa106table74.h",
    },
  "consts" = { {
      "name" = "dkwTypeCount",
      "value" = 26,
      "comment" = "the treasure type row count - the A through Z of the Table 74 grid (print capture p. 286)",
    }, {
      "name" = "dkwMapsPlusPotion",
      "value" = 1,
      "comment" = "the plus-potion clause - the D, H, and X rows of the maps and magic column (print capture p. 286)",
    }, {
      "name" = "dkwMapsPlusScroll",
      "value" = 1,
      "comment" = "the plus-scroll clause - the E, F, G, and H rows of the maps and magic column, the capture misreading 1- for the 1 scroll of H (print capture p. 286)",
    }, {
      "name" = "dkwMapsExceptSwordsMisc",
      "value" = 1,
      "comment" = "the except clause - the F row: any 3 except swords or misc. weapons plus potion and 1 scroll, the capture capitalizing Weapons (print capture p. 286)",
    }, {
      "name" = "dkwMapsExceptPotionsScrolls",
      "value" = 1,
      "comment" = "the except clause - the U and V rows: 1 and 2 of each magic except potions and scrolls (print capture p. 286)",
    }, {
      "name" = "dkwMapsSwordArmorWeapon",
      "value" = 1,
      "comment" = "the B row clause - the sword, armor, or misc. weapon of the maps and magic column (print capture p. 286)",
    }, {
      "name" = "dkwMapsOneMap",
      "value" = 1,
      "comment" = "the W row clause - the 1 map of the maps and magic column (print capture p. 286)",
    }, {
      "name" = "dkwMapsMiscMagicAndPotion",
      "value" = 1,
      "comment" = "the X row clause - the 1 misc. magic and 1 potion, the capture misreading mist. for misc. (print capture p. 286)",
    }, {
      "name" = "dkwPiecesGuaranteed",
      "value" = 1,
      "comment" = "the pieces rows - the J, K, L, M, and N rows carry no percent chance, the fixed pieces pinned with the 100 percent (print capture p. 286)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dkwFenMin",
      "values" = { 1, 1, 1, 1, 1, 0, 0, 5, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      "default" = 0,
      "comment" = "the fen minimum - the low die of the rolled range (the thousand fen - the copper penny column of the A through Z rows, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwFenMax",
      "values" = { 6, 8, 12, 8, 10, 0, 0, 30, 0, 24, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
      "default" = 0,
      "comment" = "the fen maximum - the high die of the rolled range (the thousand fen - the copper penny column of the A through Z rows, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwFenPct",
      "values" = { 25, 50, 20, 10, 5, 0, 0, 25, 0, 100, 0, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20 },
      "default" = 0,
      "comment" = "the fen percent - the chance of the roll, the 100 the guaranteed pieces rows (the thousand fen - the copper penny column of the A through Z rows, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwYuanMin",
      "values" = { 1, 1, 1, 1, 1, 3, 0, 1, 0, 0, 4, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
      "default" = 0,
      "comment" = "the yuan minimum - the low die of the rolled range (the thousand yuan - the silver dime column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwYuanMax",
      "values" = { 3, 6, 6, 10, 10, 18, 0, 100, 0, 0, 24, 0, 0, 0, 6, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8 },
      "default" = 0,
      "comment" = "the yuan maximum - the high die of the rolled range (the thousand yuan - the silver dime column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwYuanPct",
      "values" = { 30, 25, 30, 15, 25, 10, 0, 40, 0, 0, 100, 0, 0, 0, 20, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25 },
      "default" = 0,
      "comment" = "the yuan percent - the chance of the roll, the 100 the guaranteed pieces rows (the thousand yuan - the silver dime column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwTaelMin",
      "values" = { 2, 10, 1, 10, 10, 20, 10, 20, 0, 0, 0, 2, 4, 0, 0, 1, 0, 10, 0, 0, 0, 0, 10, 0, 10, 20 },
      "default" = 0,
      "comment" = "the tael minimum - the low die of the rolled range (the hundred tael - the silver dollar column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwTaelMax",
      "values" = { 20, 40, 10, 60, 60, 80, 40, 80, 0, 0, 0, 12, 24, 0, 0, 10, 0, 40, 0, 0, 0, 0, 100, 0, 60, 60 },
      "default" = 0,
      "comment" = "the tael maximum - the high die of the rolled range (the hundred tael - the silver dollar column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwTaelPct",
      "values" = { 35, 25, 10, 35, 25, 30, 50, 45, 0, 0, 0, 100, 100, 0, 0, 25, 0, 40, 0, 0, 0, 0, 60, 0, 70, 25 },
      "default" = 0,
      "comment" = "the tael percent - the chance of the roll, the 100 the guaranteed pieces rows (the hundred tael - the silver dollar column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwChienMin",
      "values" = { 1, 0, 0, 0, 0, 1, 2, 4, 2, 0, 0, 0, 0, 1, 0, 0, 0, 10, 0, 0, 0, 0, 1, 0, 0, 1 },
      "default" = 0,
      "comment" = "the chien minimum - the low die of the rolled range (the hundred ch'ien - the gold coin column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwChienMax",
      "values" = { 3, 0, 0, 0, 0, 8, 16, 40, 12, 0, 0, 0, 0, 6, 0, 0, 0, 30, 0, 0, 0, 0, 8, 0, 0, 3 },
      "default" = 0,
      "comment" = "the chien maximum - the high die of the rolled range (the hundred ch'ien - the gold coin column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwChienPct",
      "values" = { 40, 0, 0, 0, 0, 35, 50, 25, 30, 0, 0, 0, 0, 100, 0, 0, 0, 50, 0, 0, 0, 0, 15, 0, 0, 30 },
      "default" = 0,
      "comment" = "the chien percent - the chance of the roll, the 100 the guaranteed pieces rows (the hundred ch'ien - the gold coin column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwGemsMin",
      "values" = { 4, 1, 1, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 10, 0, 10, 0, 0, 5 },
      "default" = 0,
      "comment" = "the gems minimum - the low die of the rolled range (the gems - the gem count column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwGemsMax",
      "values" = { 40, 8, 6, 6, 8, 20, 12, 100, 10, 0, 0, 0, 0, 0, 0, 0, 4, 24, 0, 0, 40, 0, 40, 0, 0, 30 },
      "default" = 0,
      "comment" = "the gems maximum - the high die of the rolled range (the gems - the gem count column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwGemsPct",
      "values" = { 60, 30, 25, 30, 15, 20, 30, 50, 55, 0, 0, 0, 0, 0, 0, 0, 50, 55, 0, 0, 90, 0, 60, 0, 0, 55 },
      "default" = 0,
      "comment" = "the gems percent - the chance of the roll, the 100 the guaranteed pieces rows (the gems - the gem count column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwArtMin",
      "values" = { 1, 1, 1, 1, 1, 1, 1, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 3, 0, 0, 3 },
      "default" = 0,
      "comment" = "the art minimum - the low die of the rolled range (the art objects - the art count column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwArtMax",
      "values" = { 6, 2, 1, 3, 4, 6, 6, 30, 6, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 20, 0, 30, 0, 0, 18 },
      "default" = 0,
      "comment" = "the art maximum - the high die of the rolled range (the art objects - the art count column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwArtPct",
      "values" = { 50, 20, 20, 25, 10, 10, 25, 50, 50, 0, 0, 0, 0, 0, 0, 0, 0, 45, 0, 0, 80, 0, 50, 0, 0, 50 },
      "default" = 0,
      "comment" = "the art percent - the chance of the roll, the 100 the guaranteed pieces rows (the art objects - the art count column, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwMapsMin",
      "values" = { 3, 1, 2, 2, 3, 3, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 1, 1, 0, 3 },
      "default" = 0,
      "comment" = "the maps minimum - the low die of the rolled range (the maps and magic - the item count column of the any-N and range rows, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwMapsMax",
      "values" = { 3, 1, 2, 2, 3, 3, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 4, 1, 2, 1, 1, 0, 3 },
      "default" = 0,
      "comment" = "the maps maximum - the high die of the rolled range (the maps and magic - the item count column of the any-N and range rows, the 0 the nil; print capture p. 286)",
    }, {
      "name" = "dkwMapsPct",
      "values" = { 30, 10, 10, 15, 25, 30, 35, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 50, 70, 85, 55, 60, 0, 50 },
      "default" = 0,
      "comment" = "the maps percent - the chance of the roll, the 100 the guaranteed pieces rows (the maps and magic - the item count column of the any-N and range rows, the 0 the nil; print capture p. 286)",
    } },
  "tables" = { {
      "name" = "dkwFen",
      "tag" = "Fen",
      "count" = "dkwTypeCount",
      "comment" = "the fen column of Table 74 - the twenty-six treasure types as the min, max, and percent triples, the Nil cells the 0 sentinel, the guaranteed pieces rows the 100 (the thousand fen - the copper penny column of the A through Z rows, the 0 the nil; print capture p. 286)",
      "cols" = { "dkwFenMin", "dkwFenMax", "dkwFenPct" },
      "col_comments" = { "the fen minimum - the low die of the rolled range (the thousand fen - the copper penny column of the A through Z rows, the 0 the nil; print capture p. 286)", "the fen maximum - the high die of the rolled range (the thousand fen - the copper penny column of the A through Z rows, the 0 the nil; print capture p. 286)", "the fen percent - the chance of the roll, the 100 the guaranteed pieces rows (the thousand fen - the copper penny column of the A through Z rows, the 0 the nil; print capture p. 286)" },
      "data" = { { 1, 6, 25 }, { 1, 8, 50 }, { 1, 12, 20 }, { 1, 8, 10 }, { 1, 10, 5 }, { 0, 0, 0 }, { 0, 0, 0 }, { 5, 30, 25 }, { 0, 0, 0 }, { 3, 24, 100 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 4, 25 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 3, 20 } },
      "sentinel" = 0,
      "sentinel_census" = { 17, 17, 17 },
    }, {
      "name" = "dkwYuan",
      "tag" = "Yuan",
      "count" = "dkwTypeCount",
      "comment" = "the yuan column of Table 74 - the twenty-six treasure types as the min, max, and percent triples, the Nil cells the 0 sentinel, the guaranteed pieces rows the 100 (the thousand yuan - the silver dime column, the 0 the nil; print capture p. 286)",
      "cols" = { "dkwYuanMin", "dkwYuanMax", "dkwYuanPct" },
      "col_comments" = { "the yuan minimum - the low die of the rolled range (the thousand yuan - the silver dime column, the 0 the nil; print capture p. 286)", "the yuan maximum - the high die of the rolled range (the thousand yuan - the silver dime column, the 0 the nil; print capture p. 286)", "the yuan percent - the chance of the roll, the 100 the guaranteed pieces rows (the thousand yuan - the silver dime column, the 0 the nil; print capture p. 286)" },
      "data" = { { 1, 3, 30 }, { 1, 6, 25 }, { 1, 6, 30 }, { 1, 10, 15 }, { 1, 10, 25 }, { 3, 18, 10 }, { 0, 0, 0 }, { 1, 100, 40 }, { 0, 0, 0 }, { 0, 0, 0 }, { 4, 24, 100 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 6, 20 }, { 2, 8, 30 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 2, 8, 25 } },
      "sentinel" = 0,
      "sentinel_census" = { 15, 15, 15 },
    }, {
      "name" = "dkwTael",
      "tag" = "Tael",
      "count" = "dkwTypeCount",
      "comment" = "the tael column of Table 74 - the twenty-six treasure types as the min, max, and percent triples, the Nil cells the 0 sentinel, the guaranteed pieces rows the 100 (the hundred tael - the silver dollar column, the 0 the nil; print capture p. 286)",
      "cols" = { "dkwTaelMin", "dkwTaelMax", "dkwTaelPct" },
      "col_comments" = { "the tael minimum - the low die of the rolled range (the hundred tael - the silver dollar column, the 0 the nil; print capture p. 286)", "the tael maximum - the high die of the rolled range (the hundred tael - the silver dollar column, the 0 the nil; print capture p. 286)", "the tael percent - the chance of the roll, the 100 the guaranteed pieces rows (the hundred tael - the silver dollar column, the 0 the nil; print capture p. 286)" },
      "data" = { { 2, 20, 35 }, { 10, 40, 25 }, { 1, 10, 10 }, { 10, 60, 35 }, { 10, 60, 25 }, { 20, 80, 30 }, { 10, 40, 50 }, { 20, 80, 45 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 2, 12, 100 }, { 4, 24, 100 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 10, 25 }, { 0, 0, 0 }, { 10, 40, 40 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 10, 100, 60 }, { 0, 0, 0 }, { 10, 60, 70 }, { 20, 60, 25 } },
      "sentinel" = 0,
      "sentinel_census" = { 11, 11, 11 },
    }, {
      "name" = "dkwChien",
      "tag" = "Chien",
      "count" = "dkwTypeCount",
      "comment" = "the chien column of Table 74 - the twenty-six treasure types as the min, max, and percent triples, the Nil cells the 0 sentinel, the guaranteed pieces rows the 100 (the hundred ch'ien - the gold coin column, the 0 the nil; print capture p. 286)",
      "cols" = { "dkwChienMin", "dkwChienMax", "dkwChienPct" },
      "col_comments" = { "the chien minimum - the low die of the rolled range (the hundred ch'ien - the gold coin column, the 0 the nil; print capture p. 286)", "the chien maximum - the high die of the rolled range (the hundred ch'ien - the gold coin column, the 0 the nil; print capture p. 286)", "the chien percent - the chance of the roll, the 100 the guaranteed pieces rows (the hundred ch'ien - the gold coin column, the 0 the nil; print capture p. 286)" },
      "data" = { { 1, 3, 40 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 8, 35 }, { 2, 16, 50 }, { 4, 40, 25 }, { 2, 12, 30 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 6, 100 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 10, 30, 50 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 8, 15 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 3, 30 } },
      "sentinel" = 0,
      "sentinel_census" = { 17, 17, 17 },
    }, {
      "name" = "dkwGems",
      "tag" = "Gems",
      "count" = "dkwTypeCount",
      "comment" = "the gems column of Table 74 - the twenty-six treasure types as the min, max, and percent triples, the Nil cells the 0 sentinel, the guaranteed pieces rows the 100 (the gems - the gem count column, the 0 the nil; print capture p. 286)",
      "cols" = { "dkwGemsMin", "dkwGemsMax", "dkwGemsPct" },
      "col_comments" = { "the gems minimum - the low die of the rolled range (the gems - the gem count column, the 0 the nil; print capture p. 286)", "the gems maximum - the high die of the rolled range (the gems - the gem count column, the 0 the nil; print capture p. 286)", "the gems percent - the chance of the roll, the 100 the guaranteed pieces rows (the gems - the gem count column, the 0 the nil; print capture p. 286)" },
      "data" = { { 4, 40, 60 }, { 1, 8, 30 }, { 1, 6, 25 }, { 1, 6, 30 }, { 1, 8, 15 }, { 2, 20, 20 }, { 2, 12, 30 }, { 1, 100, 50 }, { 1, 10, 55 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 4, 50 }, { 3, 24, 55 }, { 0, 0, 0 }, { 0, 0, 0 }, { 10, 40, 90 }, { 0, 0, 0 }, { 10, 40, 60 }, { 0, 0, 0 }, { 0, 0, 0 }, { 5, 30, 55 } },
      "sentinel" = 0,
      "sentinel_census" = { 12, 12, 12 },
    }, {
      "name" = "dkwArt",
      "tag" = "Art",
      "count" = "dkwTypeCount",
      "comment" = "the art column of Table 74 - the twenty-six treasure types as the min, max, and percent triples, the Nil cells the 0 sentinel, the guaranteed pieces rows the 100 (the art objects - the art count column, the 0 the nil; print capture p. 286)",
      "cols" = { "dkwArtMin", "dkwArtMax", "dkwArtPct" },
      "col_comments" = { "the art minimum - the low die of the rolled range (the art objects - the art count column, the 0 the nil; print capture p. 286)", "the art maximum - the high die of the rolled range (the art objects - the art count column, the 0 the nil; print capture p. 286)", "the art percent - the chance of the roll, the 100 the guaranteed pieces rows (the art objects - the art count column, the 0 the nil; print capture p. 286)" },
      "data" = { { 1, 6, 50 }, { 1, 2, 20 }, { 1, 1, 20 }, { 1, 3, 25 }, { 1, 4, 10 }, { 1, 6, 10 }, { 1, 6, 25 }, { 10, 30, 50 }, { 1, 6, 50 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 1, 8, 45 }, { 0, 0, 0 }, { 0, 0, 0 }, { 2, 20, 80 }, { 0, 0, 0 }, { 3, 30, 50 }, { 0, 0, 0 }, { 0, 0, 0 }, { 3, 18, 50 } },
      "sentinel" = 0,
      "sentinel_census" = { 13, 13, 13 },
    }, {
      "name" = "dkwMaps",
      "tag" = "Maps",
      "count" = "dkwTypeCount",
      "comment" = "the maps column of Table 74 - the twenty-six treasure types as the min, max, and percent triples, the Nil cells the 0 sentinel, the guaranteed pieces rows the 100 (the maps and magic - the item count column of the any-N and range rows, the 0 the nil; print capture p. 286)",
      "cols" = { "dkwMapsMin", "dkwMapsMax", "dkwMapsPct" },
      "col_comments" = { "the maps minimum - the low die of the rolled range (the maps and magic - the item count column of the any-N and range rows, the 0 the nil; print capture p. 286)", "the maps maximum - the high die of the rolled range (the maps and magic - the item count column of the any-N and range rows, the 0 the nil; print capture p. 286)", "the maps percent - the chance of the roll, the 100 the guaranteed pieces rows (the maps and magic - the item count column of the any-N and range rows, the 0 the nil; print capture p. 286)" },
      "data" = { { 3, 3, 30 }, { 1, 1, 10 }, { 2, 2, 10 }, { 2, 2, 15 }, { 3, 3, 25 }, { 3, 3, 30 }, { 4, 4, 35 }, { 4, 4, 15 }, { 1, 1, 15 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 2, 8, 40 }, { 1, 4, 50 }, { 1, 1, 70 }, { 2, 2, 85 }, { 1, 1, 55 }, { 1, 1, 60 }, { 0, 0, 0 }, { 3, 3, 50 } },
      "sentinel" = 0,
      "sentinel_census" = { 10, 10, 10 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dkwTypeCount']() != 26  or  m['dkwMapsPlusPotion']() != 1  or  m['dkwMapsPlusScroll']() != 1  or  m['dkwMapsExceptSwordsMisc']() != 1  or  m['dkwMapsExceptPotionsScrolls']() != 1  or  m['dkwMapsSwordArmorWeapon']() != 1  or  m['dkwMapsOneMap']() != 1  or  m['dkwMapsMiscMagicAndPotion']() != 1  or  m['dkwPiecesGuaranteed']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dkwMapsPlusPotion']() != 1  or m['dkwMapsPlusScroll']() != 1  or m['dkwMapsExceptSwordsMisc']() != 1  or m['dkwMapsExceptPotionsScrolls']() != 1  or m['dkwMapsSwordArmorWeapon']() != 1  or m['dkwMapsOneMap']() != 1  or m['dkwMapsMiscMagicAndPotion']() != 1  or m['dkwPiecesGuaranteed']() != 1",
      "note" = "the clause bools - the maps and magic specials, healthy values, each condition false",
    }, {
      "expr" = "m['dkwTypeCount']() != 26",
      "note" = "the grid - the twenty-six-row Table 74, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dkwChienMin'](1) != 0  or m['dkwChienMax'](1) != 0  or m['dkwChienPct'](1) != 0  or m['dkwMapsMin'](16) != 0  or m['dkwMapsMax'](16) != 0  or m['dkwMapsPct'](16) != 0",
      "note" = "the nil law - the min, max, and percent of a cell nil together, the A row ch'ien and the Q row maps spot checks, healthy values, each condition false",
    }, {
      "expr" = "m['dkwGemsPct'](20) != 90  or m['dkwYuanMax'](7) != 100",
      "note" = "the extremes - the U row gems percent the 90 high of the rolled cells and the H row yuan the 100 range top, healthy values, each condition false",
    }, {
      "expr" = "m['dkwFenMin'](0) != 1 or m['dkwFenMin'](1) != 1 or m['dkwFenMin'](2) != 1 or m['dkwFenMin'](3) != 1 or m['dkwFenMin'](4) != 1 or m['dkwFenMin'](5) != 0 or m['dkwFenMin'](6) != 0 or m['dkwFenMin'](7) != 5",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenMin'](8) != 0 or m['dkwFenMin'](9) != 3 or m['dkwFenMin'](10) != 0 or m['dkwFenMin'](11) != 0 or m['dkwFenMin'](12) != 0 or m['dkwFenMin'](13) != 0 or m['dkwFenMin'](14) != 1 or m['dkwFenMin'](15) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenMin'](16) != 0 or m['dkwFenMin'](17) != 0 or m['dkwFenMin'](18) != 0 or m['dkwFenMin'](19) != 0 or m['dkwFenMin'](20) != 0 or m['dkwFenMin'](21) != 0 or m['dkwFenMin'](22) != 0 or m['dkwFenMin'](23) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenMin'](24) != 0 or m['dkwFenMin'](25) != 1 or m['dkwFenMin'](26) != 0 or m['dkwFenMax'](0) != 6 or m['dkwFenMax'](1) != 8 or m['dkwFenMax'](2) != 12 or m['dkwFenMax'](3) != 8 or m['dkwFenMax'](4) != 10",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenMax'](5) != 0 or m['dkwFenMax'](6) != 0 or m['dkwFenMax'](7) != 30 or m['dkwFenMax'](8) != 0 or m['dkwFenMax'](9) != 24 or m['dkwFenMax'](10) != 0 or m['dkwFenMax'](11) != 0 or m['dkwFenMax'](12) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenMax'](13) != 0 or m['dkwFenMax'](14) != 4 or m['dkwFenMax'](15) != 0 or m['dkwFenMax'](16) != 0 or m['dkwFenMax'](17) != 0 or m['dkwFenMax'](18) != 0 or m['dkwFenMax'](19) != 0 or m['dkwFenMax'](20) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenMax'](21) != 0 or m['dkwFenMax'](22) != 0 or m['dkwFenMax'](23) != 0 or m['dkwFenMax'](24) != 0 or m['dkwFenMax'](25) != 3 or m['dkwFenMax'](26) != 0 or m['dkwFenPct'](0) != 25 or m['dkwFenPct'](1) != 50",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenPct'](2) != 20 or m['dkwFenPct'](3) != 10 or m['dkwFenPct'](4) != 5 or m['dkwFenPct'](5) != 0 or m['dkwFenPct'](6) != 0 or m['dkwFenPct'](7) != 25 or m['dkwFenPct'](8) != 0 or m['dkwFenPct'](9) != 100",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenPct'](10) != 0 or m['dkwFenPct'](11) != 0 or m['dkwFenPct'](12) != 0 or m['dkwFenPct'](13) != 0 or m['dkwFenPct'](14) != 25 or m['dkwFenPct'](15) != 0 or m['dkwFenPct'](16) != 0 or m['dkwFenPct'](17) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenPct'](18) != 0 or m['dkwFenPct'](19) != 0 or m['dkwFenPct'](20) != 0 or m['dkwFenPct'](21) != 0 or m['dkwFenPct'](22) != 0 or m['dkwFenPct'](23) != 0 or m['dkwFenPct'](24) != 0 or m['dkwFenPct'](25) != 20",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwFenPct'](26) != 0 or m['dkwYuanMin'](0) != 1 or m['dkwYuanMin'](1) != 1 or m['dkwYuanMin'](2) != 1 or m['dkwYuanMin'](3) != 1 or m['dkwYuanMin'](4) != 1 or m['dkwYuanMin'](5) != 3 or m['dkwYuanMin'](6) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwYuanMin'](7) != 1 or m['dkwYuanMin'](8) != 0 or m['dkwYuanMin'](9) != 0 or m['dkwYuanMin'](10) != 4 or m['dkwYuanMin'](11) != 0 or m['dkwYuanMin'](12) != 0 or m['dkwYuanMin'](13) != 0 or m['dkwYuanMin'](14) != 1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwYuanMin'](15) != 2 or m['dkwYuanMin'](16) != 0 or m['dkwYuanMin'](17) != 0 or m['dkwYuanMin'](18) != 0 or m['dkwYuanMin'](19) != 0 or m['dkwYuanMin'](20) != 0 or m['dkwYuanMin'](21) != 0 or m['dkwYuanMin'](22) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwYuanMin'](23) != 0 or m['dkwYuanMin'](24) != 0 or m['dkwYuanMin'](25) != 2 or m['dkwYuanMin'](26) != 0 or m['dkwYuanPct'](0) != 30 or m['dkwYuanPct'](1) != 25 or m['dkwYuanPct'](2) != 30 or m['dkwYuanPct'](3) != 15",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwYuanPct'](4) != 25 or m['dkwYuanPct'](5) != 10 or m['dkwYuanPct'](6) != 0 or m['dkwYuanPct'](7) != 40 or m['dkwYuanPct'](8) != 0 or m['dkwYuanPct'](9) != 0 or m['dkwYuanPct'](10) != 100 or m['dkwYuanPct'](11) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwYuanPct'](12) != 0 or m['dkwYuanPct'](13) != 0 or m['dkwYuanPct'](14) != 20 or m['dkwYuanPct'](15) != 30 or m['dkwYuanPct'](16) != 0 or m['dkwYuanPct'](17) != 0 or m['dkwYuanPct'](18) != 0 or m['dkwYuanPct'](19) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwYuanPct'](20) != 0 or m['dkwYuanPct'](21) != 0 or m['dkwYuanPct'](22) != 0 or m['dkwYuanPct'](23) != 0 or m['dkwYuanPct'](24) != 0 or m['dkwYuanPct'](25) != 25 or m['dkwYuanPct'](26) != 0 or m['dkwTaelMin'](0) != 2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelMin'](1) != 10 or m['dkwTaelMin'](2) != 1 or m['dkwTaelMin'](3) != 10 or m['dkwTaelMin'](4) != 10 or m['dkwTaelMin'](5) != 20 or m['dkwTaelMin'](6) != 10 or m['dkwTaelMin'](7) != 20 or m['dkwTaelMin'](8) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelMin'](9) != 0 or m['dkwTaelMin'](10) != 0 or m['dkwTaelMin'](11) != 2 or m['dkwTaelMin'](12) != 4 or m['dkwTaelMin'](13) != 0 or m['dkwTaelMin'](14) != 0 or m['dkwTaelMin'](15) != 1 or m['dkwTaelMin'](16) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelMin'](17) != 10 or m['dkwTaelMin'](18) != 0 or m['dkwTaelMin'](19) != 0 or m['dkwTaelMin'](20) != 0 or m['dkwTaelMin'](21) != 0 or m['dkwTaelMin'](22) != 10 or m['dkwTaelMin'](23) != 0 or m['dkwTaelMin'](24) != 10",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelMin'](25) != 20 or m['dkwTaelMin'](26) != 0 or m['dkwTaelMax'](0) != 20 or m['dkwTaelMax'](1) != 40 or m['dkwTaelMax'](2) != 10 or m['dkwTaelMax'](3) != 60 or m['dkwTaelMax'](4) != 60 or m['dkwTaelMax'](5) != 80",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelMax'](6) != 40 or m['dkwTaelMax'](7) != 80 or m['dkwTaelMax'](8) != 0 or m['dkwTaelMax'](9) != 0 or m['dkwTaelMax'](10) != 0 or m['dkwTaelMax'](11) != 12 or m['dkwTaelMax'](12) != 24 or m['dkwTaelMax'](13) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelMax'](14) != 0 or m['dkwTaelMax'](15) != 10 or m['dkwTaelMax'](16) != 0 or m['dkwTaelMax'](17) != 40 or m['dkwTaelMax'](18) != 0 or m['dkwTaelMax'](19) != 0 or m['dkwTaelMax'](20) != 0 or m['dkwTaelMax'](21) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelMax'](22) != 100 or m['dkwTaelMax'](23) != 0 or m['dkwTaelMax'](24) != 60 or m['dkwTaelMax'](25) != 60 or m['dkwTaelMax'](26) != 0 or m['dkwTaelPct'](0) != 35 or m['dkwTaelPct'](1) != 25 or m['dkwTaelPct'](2) != 10",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelPct'](3) != 35 or m['dkwTaelPct'](4) != 25 or m['dkwTaelPct'](5) != 30 or m['dkwTaelPct'](6) != 50 or m['dkwTaelPct'](7) != 45 or m['dkwTaelPct'](8) != 0 or m['dkwTaelPct'](9) != 0 or m['dkwTaelPct'](10) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelPct'](11) != 100 or m['dkwTaelPct'](12) != 100 or m['dkwTaelPct'](13) != 0 or m['dkwTaelPct'](14) != 0 or m['dkwTaelPct'](15) != 25 or m['dkwTaelPct'](16) != 0 or m['dkwTaelPct'](17) != 40 or m['dkwTaelPct'](18) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwTaelPct'](19) != 0 or m['dkwTaelPct'](20) != 0 or m['dkwTaelPct'](21) != 0 or m['dkwTaelPct'](22) != 60 or m['dkwTaelPct'](23) != 0 or m['dkwTaelPct'](24) != 70 or m['dkwTaelPct'](25) != 25 or m['dkwTaelPct'](26) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwGemsMin'](0) != 4 or m['dkwGemsMin'](1) != 1 or m['dkwGemsMin'](2) != 1 or m['dkwGemsMin'](3) != 1 or m['dkwGemsMin'](4) != 1 or m['dkwGemsMin'](5) != 2 or m['dkwGemsMin'](6) != 2 or m['dkwGemsMin'](7) != 1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwGemsMin'](8) != 1 or m['dkwGemsMin'](9) != 0 or m['dkwGemsMin'](10) != 0 or m['dkwGemsMin'](11) != 0 or m['dkwGemsMin'](12) != 0 or m['dkwGemsMin'](13) != 0 or m['dkwGemsMin'](14) != 0 or m['dkwGemsMin'](15) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwGemsMin'](16) != 1 or m['dkwGemsMin'](17) != 3 or m['dkwGemsMin'](18) != 0 or m['dkwGemsMin'](19) != 0 or m['dkwGemsMin'](20) != 10 or m['dkwGemsMin'](21) != 0 or m['dkwGemsMin'](22) != 10 or m['dkwGemsMin'](23) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwGemsMin'](24) != 0 or m['dkwGemsMin'](25) != 5 or m['dkwGemsMin'](26) != 0 or m['dkwGemsMax'](0) != 40 or m['dkwGemsMax'](1) != 8 or m['dkwGemsMax'](2) != 6 or m['dkwGemsMax'](3) != 6 or m['dkwGemsMax'](4) != 8",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwGemsMax'](5) != 20 or m['dkwGemsMax'](6) != 12 or m['dkwGemsMax'](7) != 100 or m['dkwGemsMax'](8) != 10 or m['dkwGemsMax'](9) != 0 or m['dkwGemsMax'](10) != 0 or m['dkwGemsMax'](11) != 0 or m['dkwGemsMax'](12) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwGemsMax'](13) != 0 or m['dkwGemsMax'](14) != 0 or m['dkwGemsMax'](15) != 0 or m['dkwGemsMax'](16) != 4 or m['dkwGemsMax'](17) != 24 or m['dkwGemsMax'](18) != 0 or m['dkwGemsMax'](19) != 0 or m['dkwGemsMax'](20) != 40",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwGemsMax'](21) != 0 or m['dkwGemsMax'](22) != 40 or m['dkwGemsMax'](23) != 0 or m['dkwGemsMax'](24) != 0 or m['dkwGemsMax'](25) != 30 or m['dkwGemsMax'](26) != 0 or m['dkwArtMin'](0) != 1 or m['dkwArtMin'](1) != 1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtMin'](2) != 1 or m['dkwArtMin'](3) != 1 or m['dkwArtMin'](4) != 1 or m['dkwArtMin'](5) != 1 or m['dkwArtMin'](6) != 1 or m['dkwArtMin'](7) != 10 or m['dkwArtMin'](8) != 1 or m['dkwArtMin'](9) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtMin'](10) != 0 or m['dkwArtMin'](11) != 0 or m['dkwArtMin'](12) != 0 or m['dkwArtMin'](13) != 0 or m['dkwArtMin'](14) != 0 or m['dkwArtMin'](15) != 0 or m['dkwArtMin'](16) != 0 or m['dkwArtMin'](17) != 1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtMin'](18) != 0 or m['dkwArtMin'](19) != 0 or m['dkwArtMin'](20) != 2 or m['dkwArtMin'](21) != 0 or m['dkwArtMin'](22) != 3 or m['dkwArtMin'](23) != 0 or m['dkwArtMin'](24) != 0 or m['dkwArtMin'](25) != 3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtMin'](26) != 0 or m['dkwArtMax'](0) != 6 or m['dkwArtMax'](1) != 2 or m['dkwArtMax'](2) != 1 or m['dkwArtMax'](3) != 3 or m['dkwArtMax'](4) != 4 or m['dkwArtMax'](5) != 6 or m['dkwArtMax'](6) != 6",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtMax'](7) != 30 or m['dkwArtMax'](8) != 6 or m['dkwArtMax'](9) != 0 or m['dkwArtMax'](10) != 0 or m['dkwArtMax'](11) != 0 or m['dkwArtMax'](12) != 0 or m['dkwArtMax'](13) != 0 or m['dkwArtMax'](14) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtMax'](15) != 0 or m['dkwArtMax'](16) != 0 or m['dkwArtMax'](17) != 8 or m['dkwArtMax'](18) != 0 or m['dkwArtMax'](19) != 0 or m['dkwArtMax'](20) != 20 or m['dkwArtMax'](21) != 0 or m['dkwArtMax'](22) != 30",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtMax'](23) != 0 or m['dkwArtMax'](24) != 0 or m['dkwArtMax'](25) != 18 or m['dkwArtMax'](26) != 0 or m['dkwArtPct'](0) != 50 or m['dkwArtPct'](1) != 20 or m['dkwArtPct'](2) != 20 or m['dkwArtPct'](3) != 25",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtPct'](4) != 10 or m['dkwArtPct'](5) != 10 or m['dkwArtPct'](6) != 25 or m['dkwArtPct'](7) != 50 or m['dkwArtPct'](8) != 50 or m['dkwArtPct'](9) != 0 or m['dkwArtPct'](10) != 0 or m['dkwArtPct'](11) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtPct'](12) != 0 or m['dkwArtPct'](13) != 0 or m['dkwArtPct'](14) != 0 or m['dkwArtPct'](15) != 0 or m['dkwArtPct'](16) != 0 or m['dkwArtPct'](17) != 45 or m['dkwArtPct'](18) != 0 or m['dkwArtPct'](19) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkwArtPct'](20) != 80 or m['dkwArtPct'](21) != 0 or m['dkwArtPct'](22) != 50 or m['dkwArtPct'](23) != 0 or m['dkwArtPct'](24) != 0 or m['dkwArtPct'](25) != 50 or m['dkwArtPct'](26) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R735 OA Table 74 monetary treasure audit",
      "comment" = "OA round one hundred twenty-two (capture p. 286): the Table 74 Monetary Treasure And Magical Items - the twenty-six treasure types by the seven categories, each cell the min, max, and percent triple with the Nil the 0 sentinel, the guaranteed pieces rows the 100, the maps and magic clauses riding as bools, single-pass pins per the Chapter 9 provenance shift",
    },
}
