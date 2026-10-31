-- dgn: promoted from tools/spec_r912.json (the The Dragon issue-9 opener - the Gygax alignment article (folios 5-6) and the Ward Tombs & Crypts article (folio 25): two adjudicated chains in one round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 912,
  "prefix" = "dgn",
  "banner" = {
      "title" = "The Dragon issue-9 opener - the Gygax alignment article (folios 5-6) and the Ward Tombs & Crypts article (folio 25): two adjudicated chains in one round",
      "provenance" = "Pinned from The Dragon Vol. II No. 3 (September 1977), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 9; the source lives in the archive.org item accessory-dragon-magazine-012). The folios: 5-6, the Gygax Designers Forum alignment article - player characters not knowing encountered alignments in the normal course, the new character dissembled as neutral or agreeable until strong enough to survive the block, the abrupt concealed change, the Greyhawk precept that good is the end sought by the majority of humanity and its allied races, the lawful-good-vs-chaotic-good war not precluded with either or both allied with evil beings, most places a mixture of alignments, the Free City's neutral-in-outlook oligarchs with free commerce and carefully thwarted preeminence, the cleric's shrine cutting expenses to zero then the temple escalation arousing rival-cleric enmity, government suspicion, levied taxes and survival bribes that skyrocket in open conflict, influence proportionate to power in the own area and relative to its importance, influence allowable but dictation not, the uncoerced alignment choice, and all campaign events subject to DM intervention; 25, the Ward Tombs & Crypts article - the d12 occupant roll across soldier, hero, priest, pair, mated pair, lord, king, patriarch, EHP, magic user, wizard and being, the nine item rolls per tomb, the over-100 assume-100-and-reroll-without-bonus and under-0 assume-01 rules, the maps band (1-80 none, 81-100 the judge's option), the special-item band (1-85 none, 86-100 the judge's own manufacture), the guardian chain (none, the magic spell, the 1-4 invisible stalkers, the 6th-level-chart creature, the stronger monster), the tomb-structure chain from the 1-room mound through the 2-6 room complex, the 1-10 rooms with 1-10 traps, the 1-10 rooms with 1-20 corridors and 2-20 traps, the connecting rooms with magical guards, to the 1-20 room special-word tomb whose word is not found inside, and the gold-piece, gems, jewelry and misc-magic tables. The transcripts ride extract/dragon/009/ (all 32 issue pages); the issue-9 gap report ships pre-flip. PRINT FOLIO = PDF PAGE, verified at the printed 4, 7, 8, 9, 10, 11, 12, 14, 20, 21, 22 and 23 footers.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon, and the Gygax alignment article - though it prefigures the later print - pins as a variant layer with provenance, never core canon. The Ward print quirks ride AS SCANNED, noted, never silent: the gold-piece table's 51-60 x2 row and its garbled 100 row (the '100,00 Thousand' OCR) never guessed - only the five clean bands pin; the guardian 100-band's tail text garbled - the band index pins, the prose rides; the per-occupant modifier grid garbled whole in the OCR and riding the transcript; the Barker EPT column and the Blume Boot Hill ratings scoped out per the standing other-system precedent (R904, R906, R907). The editor's standing caution rides: none of this is official.",
    },
  "consts" = { {
      "name" = "dgnTombOccupantTypes",
      "value" = 12,
      "comment" = "the d12 occupant roll - soldier, hero, priest, pair, mated pair, lord, king, patriarch, EHP, magic user, wizard, being (folio 25)",
    }, {
      "name" = "dgnTombItemRolls",
      "value" = 9,
      "comment" = "roll for each of the 9 items per tomb (folio 25)",
    }, {
      "name" = "dgnTombOverflowCeiling",
      "value" = 100,
      "comment" = "an over-100 total assumes a 100 roll and rolls again without the occupant bonus (folio 25)",
    }, {
      "name" = "dgnTombFloorRoll",
      "value" = 1,
      "comment" = "a total under 0 assumes an 01 roll (folio 25)",
    }, {
      "name" = "dgnTombGoldBands",
      "value" = 5,
      "comment" = "the five clean gold-piece bands pinned - the 51-60 x2 row and the garbled 100 row ride the transcript as scanned (folio 25)",
    }, {
      "name" = "dgnTombGemsBands",
      "value" = 7,
      "comment" = "the gems table bands - 1-50 through the 100 row (folio 25)",
    }, {
      "name" = "dgnTombJewelryBands",
      "value" = 7,
      "comment" = "the jewelry table bands - 1-50 through the 100 row (folio 25)",
    }, {
      "name" = "dgnTombMiscMagicBands",
      "value" = 6,
      "comment" = "the misc-magic bands - none plus the five Greyhawk tables (folio 25)",
    }, {
      "name" = "dgnTombItselfBands",
      "value" = 7,
      "comment" = "the tomb-structure bands - the 1-room mound through the special-word tomb (folio 25)",
    }, {
      "name" = "dgnGuardianStalkerMin",
      "value" = 1,
      "comment" = "the guardian band 51-80 - invisible stalker(s), 1-4 (folio 25)",
    }, {
      "name" = "dgnGuardianStalkerMax",
      "value" = 4,
      "comment" = "the guardian band 51-80 stalker maximum (folio 25)",
    }, {
      "name" = "dgnTombCorridorsMin",
      "value" = 1,
      "comment" = "the 81-90 tomb-structure band - 1-20 corridors (folio 25)",
    }, {
      "name" = "dgnTombCorridorsMax",
      "value" = 20,
      "comment" = "the 81-90 tomb-structure band corridor maximum (folio 25)",
    } },
  "bools" = { {
      "name" = "dgnAlignmentUnknownByDefault",
      "value" = true,
      "comment" = "player characters will not know the alignment of persons they encounter in the normal course of affairs (folio 5)",
    }, {
      "name" = "dgnDissemblingAlignmentAllowed",
      "value" = true,
      "comment" = "the new character may be listed as neutral or agreeable and carefully played concealed (folio 5)",
    }, {
      "name" = "dgnConcealedChangeAtStrength",
      "value" = true,
      "comment" = "the abrupt alignment change comes when the character can survive in opposition to the block (folio 5)",
    }, {
      "name" = "dgnGreyhawkGoodMajorityPrecept",
      "value" = true,
      "comment" = "the Greyhawk precept - good is the end sought by the majority of humanity and its allied races (folio 5)",
    }, {
      "name" = "dgnGoodVsGoodWarPossible",
      "value" = true,
      "comment" = "a war of lawful good against chaotic good is not precluded, either or both allied with evil beings (folio 5)",
    }, {
      "name" = "dgnMixedAlignmentsUsual",
      "value" = true,
      "comment" = "most places contain a mixture of alignments (folio 5)",
    }, {
      "name" = "dgnGreyhawkOligarchsNeutralOutlook",
      "value" = true,
      "comment" = "the Free City oligarchs are neutral in outlook if not in alignment (folio 5)",
    }, {
      "name" = "dgnGreyhawkCommerceFree",
      "value" = true,
      "comment" = "commerce is free and all alignments co-exist on equitable terms in the Free City (folio 5)",
    }, {
      "name" = "dgnGreyhawkPreeminenceThwarted",
      "value" = true,
      "comment" = "any preeminence of alignment is carefully thwarted by the rulers of the Free City (folio 5)",
    }, {
      "name" = "dgnClericShrineSelfSupporting",
      "value" = true,
      "comment" = "the shrine-level establishment cuts expenses to zero if not a small profit (folio 5)",
    }, {
      "name" = "dgnTempleEscalationArousesEnmity",
      "value" = true,
      "comment" = "the temple or patriarchate proclamation arouses the enmity of rival clerics and the government (folio 6)",
    }, {
      "name" = "dgnTaxesLeviedBribesPaid",
      "value" = true,
      "comment" = "taxes are levied and bribes paid to survive, skyrocketing in open conflict (folio 6)",
    }, {
      "name" = "dgnInfluenceProportionateToPower",
      "value" = true,
      "comment" = "influence is proportionate to power in the own area, relative to the area importance (folio 6)",
    }, {
      "name" = "dgnInfluenceAllowedDictationNot",
      "value" = true,
      "comment" = "influence upon alignment is quite allowable, dictation is not (folio 6)",
    }, {
      "name" = "dgnUncoercedAlignmentChoice",
      "value" = true,
      "comment" = "participants have the right of uncoerced alignment choice (folio 6)",
    }, {
      "name" = "dgnDmInterventionDoctrine",
      "value" = true,
      "comment" = "all that takes place in the campaign is subject to DM intervention (folio 6)",
    }, {
      "name" = "dgnTombPairIsTwoBuried",
      "value" = true,
      "comment" = "the pair factor is more than one being buried in the tomb (folio 25)",
    }, {
      "name" = "dgnTombMatedPairShared",
      "value" = true,
      "comment" = "the mated pair is a husband-and-wife type tomb, not necessarily human (folio 25)",
    }, {
      "name" = "dgnTombBeingCryptOfHonor",
      "value" = true,
      "comment" = "the 12th factor is an intelligent creature honored by followers with a special crypt (folio 25)",
    }, {
      "name" = "dgnTombOverflowDropsBonus",
      "value" = true,
      "comment" = "the over-100 re-roll rolls again without the occupant bonus (folio 25)",
    }, {
      "name" = "dgnTombFinalWordNotInside",
      "value" = true,
      "comment" = "the special word opening the final door should not be found in the tomb (folio 25)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "dgnTombGold",
      "tag" = "Gd",
      "count" = "dgnTombGoldBands",
      "sentinel" = -1,
      "cols" = { "dgnTombGoldPiecesMin", "dgnTombGoldPiecesMax" },
      "col_comments" = { "the gold-piece band minimum in pieces - the 1-100 piece row through the 2-40 thousand row, the 51-60 x2 and garbled 100 rows riding the transcript (folio 25)", "the gold-piece band maximum in pieces - as scanned (folio 25)" },
      "data" = { { 1, 100 }, { 1000, 6000 }, { 1000, 12000 }, { 1000, 20000 }, { 2000, 40000 } },
      "audit_comment" = "the Ward gold-piece table - the five clean bands: 1-100 pieces at 1-50, 1-6 thousand at 61-70, 1-12 thousand at 71-80, 1-20 thousand at 81-90, 2-40 thousand at 91-99; the 51-60 x2 row and the garbled 100 row ride the transcript as scanned (folio 25)",
    }, {
      "name" = "dgnTombGems",
      "tag" = "Gm",
      "count" = "dgnTombGemsBands",
      "sentinel" = -1,
      "cols" = { "dgnTombGemCountMin", "dgnTombGemCountMax", "dgnTombGemBaseValue" },
      "col_comments" = { "the gems band count minimum, 1-6 through the 1-20 base row (folio 25)", "the gems band count maximum (folio 25)", "the gems band base value - 100 through 10,000 (folio 25)" },
      "data" = { { 1, 6, 100 }, { 1, 6, 500 }, { 1, 8, 500 }, { 1, 12, 500 }, { 1, 12, 1000 }, { 1, 6, 5000 }, { 1, 20, 10000 } },
      "audit_comment" = "the Ward gems table - seven bands: 1-6 base 100 at 1-50, 1-6 base 500 at 51-60, 1-8 base 500 at 61-70, 1-12 base 500 at 71-80, 1-12 base 1,000 at 81-90, 1-6 base 5,000 at 91-99, 1-20 base 10,000 at 100 with the re-roll (folio 25)",
    }, {
      "name" = "dgnTombJewelry",
      "tag" = "Jw",
      "count" = "dgnTombJewelryBands",
      "sentinel" = -1,
      "cols" = { "dgnTombJewelryCountMin", "dgnTombJewelryCountMax", "dgnTombJewelryBaseValue" },
      "col_comments" = { "the jewelry band count minimum (folio 25)", "the jewelry band count maximum, 1-20 at the 100 row (folio 25)", "the jewelry band base value - 500 through 50,000 (folio 25)" },
      "data" = { { 1, 6, 500 }, { 1, 6, 1000 }, { 1, 6, 5000 }, { 1, 6, 10000 }, { 1, 6, 20000 }, { 1, 6, 30000 }, { 1, 20, 50000 } },
      "audit_comment" = "the Ward jewelry table - seven bands: 1-6 base 500 through 1-6 base 30,000, the 1-20 base 50,000 row at 100 with the re-roll (folio 25)",
    }, {
      "name" = "dgnTombMiscMagic",
      "tag" = "Mm",
      "count" = "dgnTombMiscMagicBands",
      "sentinel" = 0,
      "sentinel_census" = { 1 },
      "cols" = { "dgnTombMiscMagicTable" },
      "col_comments" = { "the misc-magic band Greyhawk table - 0 none, 1 through 5 the Greyhawk tables I to V (folio 25)" },
      "data" = { { 0 }, { 1 }, { 2 }, { 3 }, { 4 }, { 5 } },
      "audit_comment" = "the Ward misc-magic table - none at 1-60, the Greyhawk tables I through V at 61-70, 71-80, 81-90, 91-99 and 100 with the re-roll (folio 25)",
    }, {
      "name" = "dgnTombItselfRooms",
      "tag" = "Ti",
      "count" = "dgnTombItselfBands",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0, 4, 4 },
      "cols" = { "dgnTombItselfRoomsMin", "dgnTombItselfRoomsMax", "dgnTombItselfTrapsMin", "dgnTombItselfTrapsMax" },
      "col_comments" = { "the tomb-structure band rooms minimum - the hall band and the unstated-count bands sentinel -1 (folio 25)", "the tomb-structure band rooms maximum (folio 25)", "the tomb-structure band traps minimum - the unstated-count bands sentinel -1 (folio 25)", "the tomb-structure band traps maximum (folio 25)" },
      "data" = { { 1, 1, -1, -1 }, { 1, 1, 1, 1 }, { 2, 6, -1, -1 }, { 1, 10, 1, 10 }, { 1, 10, 2, 20 }, { 1, 10, -1, -1 }, { 1, 20, -1, -1 } },
      "audit_comment" = "the Ward tomb-structure grid - seven bands: the 1 room/cave/mound, the hall with its spring trap, the 2-6 room complex, the 1-10 rooms with 1-10 traps, the 1-10 rooms with 2-20 traps, the connecting rooms with magical guards, the 1-20 room special-word tomb; the unstated trap counts ride prose, sentinel -1 (folio 25)",
    } },
  "chains" = { {
      "name" = "dgnTombMapBand",
      "limits" = { 80 },
      "tail" = 1,
      "comment" = "the maps band - 1-80 none, 81-100 the judge option (folio 25)",
    }, {
      "name" = "dgnTombSpecialBand",
      "limits" = { 85 },
      "tail" = 1,
      "comment" = "the special-item band - 1-85 none, 86-100 the judge own manufacture (folio 25)",
    }, {
      "name" = "dgnTombGuardianBand",
      "limits" = { 30, 50, 80, 99 },
      "tail" = 4,
      "comment" = "the guardian chain - none, the magic spell, the 1-4 invisible stalkers, the 6th-level-chart creature, the stronger monster (folio 25)",
    }, {
      "name" = "dgnTombItselfBand",
      "limits" = { 40, 50, 60, 80, 90, 99 },
      "tail" = 6,
      "comment" = "the tomb-structure chain - the seven bands from the 1-room mound to the special-word tomb (folio 25)",
    } },
  "examples" = { {
      "expr" = "m['dgnTombOccupantTypes']() != 12 or m['dgnTombItemRolls']() != 9 or m['dgnTombOverflowCeiling']() != 100 or m['dgnTombFloorRoll']() != 1",
      "note" = "the tomb census - the d12 occupant, the nine item rolls, the overflow 100 and the floor 01 (folio 25)",
    }, {
      "expr" = "m['dgnTombGoldBands']() != 5 or m['dgnTombGemsBands']() != 7 or m['dgnTombJewelryBands']() != 7 or m['dgnTombMiscMagicBands']() != 6 or m['dgnTombItselfBands']() != 7",
      "note" = "the table band census - five gold, seven gems, seven jewelry, six misc-magic, seven structure bands (folio 25)",
    }, {
      "expr" = "m['dgnGuardianStalkerMin']() != 1 or m['dgnGuardianStalkerMax']() != 4 or m['dgnTombCorridorsMin']() != 1 or m['dgnTombCorridorsMax']() != 20",
      "note" = "the guardian stalkers 1-4 and the 1-20 corridor band (folio 25)",
    }, {
      "expr" = "m['dgnTombMapBand'](80) != 0 or m['dgnTombMapBand'](81) != 1 or m['dgnTombSpecialBand'](85) != 0 or m['dgnTombSpecialBand'](86) != 1",
      "note" = "the maps and special-item band boundaries (folio 25)",
    } },
  "audit" = {
      "label" = "R912 issue-9 opener audit",
      "comment" = "THE DRAGON ISSUE-9 OPENER ROUND - two adjudicated chains. The Gygax alignment article (folios 5-6): the alignment-unknown default, the concealed-alignment doctrine with its survival trigger, the Greyhawk good-majority precept, the good-vs-good war possibility, the mixed-alignment census of places, the Free City's neutral oligarchs with free commerce and thwarted preeminence, the cleric's shrine-to-temple escalation with its enmity, taxes and bribes, the influence-proportionate-to-power doctrine with influence-allowed-dictation-not, the uncoerced choice and the DM intervention law. The Ward Tombs & Crypts article (folio 25): the twelve-occupant d12 with its nine item rolls, the overflow 100 and floor 01 rules, the map and special-item bands, the five-band guardian chain with the 1-4 invisible stalkers, the seven-band tomb structure with the 1-20 corridor band, and the gold, gems, jewelry and misc-magic tables - the five clean gold bands to the 2-40 thousand row, the gems at base 100 to 10,000, the jewelry at base 500 to 50,000, the misc-magic none plus the five Greyhawk tables.",
    },
}
