-- wwt: promoted from tools/spec_r904.json (the The witchcraft wilderness encounter table round - the folio-4 grid, resolved legible by the chat-side upload cross-check: armor class 8, the 9/24 move, hit dice 4-7, the 30/45 lair lines and the number-appearing terrain bands);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 904,
  "prefix" = "wwt",
  "banner" = {
      "title" = "The witchcraft wilderness encounter table round - the folio-4 grid, resolved legible by the chat-side upload cross-check: armor class 8, the 9/24 move, hit dice 4-7, the 30/45 lair lines and the number-appearing terrain bands",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 5 (March 1977), folio 4, the Witchcraft Supplement's wilderness encounter table - the grid the archive.org DjVu OCR garbled and R902 scoped out per the standing OCR-table caution. The chat-side upload cross-check (Curtiss's Dragon_Magazine_005.pdf, October 29) made the grid fully legible: number appearing by terrain (Mts/Desert none, Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13), armor class 8, movement 9 on foot and 24 on broom, hit dice 4-7, and the lair lines - Lawful Witch 30 percent, Chaotic Witch 45 percent, the Secret Order witches excepted at their own 75 percent any-terrain one-only line already pinned at R902. The same cross-check confirmed every pages-1-5 pin of R902 against the upload's voice - the encounter doctrine, the Order ladder, the quotas, the immunities and the spell matrix through Curse - with one voice quirk noted below. The upload's extraction capped at page 5, so pages 6-32 remain single-voice archive.org; the provenance recorded at R902 stands for those pages.",
      "sentinel" = "The cross-check doctrine rides: the pin IS the conversion, and the second voice settles the garbled cell - the wilderness table pins exactly as the upload reads it, the terrain none band as the 0 sentinel, and the scoped-out sentence in tools/dragon_gap_report_005.md updates by file patch to record the resolution, never silently. The Comfort spell's duration quirk is noted and settled by arithmetic: the upload reads 'D = 3b (6 hours)' where the archive.org scan reads 'D = 36', and 6 hours at 10 minutes per turn is 36 turns - the R902 pin of 36 stands. No new registry ink: this is a pure variant-layer const round against the R902 Witchcraft Supplement chain, no lua defs, no transcripts, no gap flips.",
    },
  "consts" = { {
      "name" = "wwtWitchAc",
      "value" = 8,
      "comment" = "the witch armor class - 8 on the wilderness encounter table (folio 4)",
    }, {
      "name" = "wwtWitchMoveFoot",
      "value" = 9,
      "comment" = "the witch movement - 9 inches on foot (folio 4)",
    }, {
      "name" = "wwtWitchMoveBroom",
      "value" = 24,
      "comment" = "the witch movement - 24 inches on broom (folio 4)",
    }, {
      "name" = "wwtWitchHdMin",
      "value" = 4,
      "comment" = "the witch hit dice, minimum - 4 (folio 4)",
    }, {
      "name" = "wwtWitchHdMax",
      "value" = 7,
      "comment" = "the witch hit dice, maximum - 7 (folio 4)",
    }, {
      "name" = "wwtLawfulWitchLairPct",
      "value" = 30,
      "comment" = "the Lawful witch percent in lair - 30 (folio 4)",
    }, {
      "name" = "wwtChaoticWitchLairPct",
      "value" = 45,
      "comment" = "the Chaotic witch percent in lair - 45 (folio 4)",
    }, {
      "name" = "wwtTerrainNaCount",
      "value" = 4,
      "comment" = "the terrain band count - 4 rows as scanned: Mts/Desert, Riv/Swamps, Clear, Towns/Woods (folio 4)",
    } },
  "bools" = { {
      "name" = "wwtTableAppliesToAll",
      "value" = true,
      "comment" = "all other evil witches and the Lawful witches comply with this table - the Secret Order witches excepted at their own 75 percent any-terrain one-only line, already pinned at R902 (folio 4)",
    }, {
      "name" = "wwtTerrainFactor",
      "value" = true,
      "comment" = "the number of witches encountered is a factor of terrain - best suited to certain environments, the woodlands and orchards favored most of all (folio 4)",
    }, {
      "name" = "wwtLairDeviceAccess",
      "value" = true,
      "comment" = "a witch in her lair has the use of every portable magic device in her hoard - the GM must determine the items, as they may affect the battle when the lair is invaded (folio 4)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wwtTerrainNa",
      "tag" = "NaTr",
      "count" = "wwtTerrainNaCount",
      "sentinel" = 0,
      "cols" = { "wwtTerrainNaMin", "wwtTerrainNaMax" },
      "col_comments" = { "the number appearing minimum by terrain - 0 the sentinel for the Mts/Desert none (folio 4)", "the number appearing maximum by terrain - 0 the sentinel for the Mts/Desert none (folio 4)" },
      "data" = { { 0, 0 }, { 2, 4 }, { 1, 3 }, { 2, 13 } },
      "audit_comment" = "the number-appearing band by terrain - Mts/Desert none, Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wwtWitchAc']() != 8 or m['wwtWitchMoveFoot']() != 9 or m['wwtWitchMoveBroom']() != 24",
      "note" = "the witch armor class 8, the 9 on foot and 24 on broom movement (folio 4)",
    }, {
      "expr" = "m['wwtWitchHdMin']() != 4 or m['wwtWitchHdMax']() != 7 or m['wwtLawfulWitchLairPct']() != 30 or m['wwtChaoticWitchLairPct']() != 45",
      "note" = "the witch hit dice 4-7, the 30 percent Lawful and 45 percent Chaotic lair lines (folio 4)",
    }, {
      "expr" = "m['wwtTableAppliesToAll']() != 1 or m['wwtTerrainFactor']() != 1 or m['wwtLairDeviceAccess']() != 1",
      "note" = "the encounter table doctrines - all non-Secret witches comply, terrain factors the numbers, the lair device access (folio 4)",
    }, {
      "expr" = "m['wwtTerrainNaMin'](0) != 0 or m['wwtTerrainNaMax'](0) != 0 or m['wwtTerrainNaCount']() != 4",
      "note" = "the number-appearing band, row %d of 4 - Mts/Desert none, Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)",
    }, {
      "expr" = "m['wwtTerrainNaMin'](1) != 2 or m['wwtTerrainNaMax'](1) != 4",
      "note" = "the number-appearing band, row %d of 4 - Mts/Desert none, Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)",
    }, {
      "expr" = "m['wwtTerrainNaMin'](2) != 1 or m['wwtTerrainNaMax'](2) != 3",
      "note" = "the number-appearing band, row %d of 4 - Mts/Desert none, Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)",
    }, {
      "expr" = "m['wwtTerrainNaMin'](3) != 2 or m['wwtTerrainNaMax'](3) != 13",
      "note" = "the number-appearing band, row %d of 4 - Mts/Desert none, Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)",
    } },
  "audit" = {
      "label" = "R904 wilderness encounter table audit",
      "comment" = "THE WITCHCRAFT WILDERNESS ENCOUNTER TABLE ROUND - the folio-4 grid the DjVu OCR garbled, made legible by the chat-side upload cross-check and pinned as scanned: the number-appearing terrain bands as a 4-row table (Mts/Desert none at the 0 sentinel, Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13), armor class 8, movement 9 on foot and 24 on broom, hit dice 4-7, the Lawful 30 percent and Chaotic 45 percent lair lines, the terrain factor doctrine (the woodlands and orchards favored), and the lair device access (every portable magic device in the hoard). The Secret Order exception stays pinned at R902 - no duplicate ink. The cross-check also confirmed every R902 pages-1-5 pin against the upload: the rolls 5 or 7 encounter doctrine, the 35/65 split, the 12-sided Order ladder, the spell quotas, the immunities, and the spell matrix rows Pit, Fire Box, Diminish, Plant Entrapment, Paralyzing Pit, Undead Control, Aging, Circle of Blindness, Curse, Calm, Rejuvenation, Dissipation and Comfort. The Comfort quirk is noted and settled: the upload reads D = 3b (6 hours), the archive.org scan reads D = 36, and 6 hours at 10 minutes per turn is 36 turns - the pin stands. The scoped-out sentence in tools/dragon_gap_report_005.md updates by file patch to record the resolution. The R903 record seats in the seed via prev_record.",
    },
}
