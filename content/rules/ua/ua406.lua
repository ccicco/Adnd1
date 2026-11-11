-- ua: promoted from rules/ua/uaappends.h (the The UA APPENDIX S stat blocks,);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 406,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA APPENDIX S stat blocks,",
      "provenance" = "R406: the 23 non-human deity stat blocks (pp. 110-120) - the ungated data round riding the R405 deity layer seam. The R337/R391 pin-round precedent: the scan-clean stat-line numerics pin; the R783 round pins the messy reads (the class/level lines, the MOVE values, the S/I/W/D/C/CH/CM stat lines) in rules/seams/deitylines.h; the dwarven, elven, halfling, gnomish, and orcish prose pin in rules/uadeityprose1-5.h (R786-R790); the Appendix S description-paragraph close is complete.  The census (live cross-checked against the R405 seam): 23 blocks, 5 pantheons (dwarves 0-4, elves 5-9, halflings 10-13, gnomes 14-17, orcs 18-22); the tiers 5 greater / 16 lesser / 2 demigods; the psionic ratings VI 10, III 5, IV 1, Nil 6, plus Brandobaris unrecorded (no rating line in the print).  The fields per block: tier, armor class, hit points, magic resistance percent, psionic rating code, size, the attacks per round (in HALVES: 4 = 2/round, 3 = 3/2, 8 = 4), the damage range min/max, and the printed alignment and plane strings.  The scan holes record as sentinels, not guesses: - UAS_AC_HOLE (99): the Hanali armor class - the scan garbles the line (one hole); - UAS_ATK_HOLE (-1): the Shargaas attacks line - the scan garbles it (one hole); - UAS_DMG_UNRECORDED (-1): the unprinted damage reads - Labelas and Yurtrus print \"see below\", Cyrrollalee \"by weapon type\", and the Brandobaris range garbles (four unrecorded); Hanali prints Nil - 0/0, clean.  The damage ranges read min-max as printed (Urdlen \"S: 4-16\" pins 4-16; the parenthetical plusses ride the stat lines, unpinned).  The tier codes: 0 greater, 1 lesser, 2 demigod. The rating codes: 0 VI, 1 III, 2 IV, 3 Nil, -1 unrecorded. The size codes: 0 S, 1 M, 2 L.",
    },
  "consts" = { {
      "name" = "uasDeityCount",
      "value" = 23,
      "comment" = "",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = { {
      "name" = "uasStat",
      "comment" = "The 23 stat blocks, in pantheon order (the R405 registry order): dwarves, elves, halflings, gnomes, orcs.",
      "kind" = "header pin",
      "body" = "static const UasStatBlock T[23] = { // ---- the dwarves (pp. 110-111) ---- { \"CLANGGEDIN SILVERBEARD\", 0, -4, 375, 50, 0, 2, 4, 3, 36, \"Lawful neutral\", \"Arcadia\" }, { \"VERGADAIN\", 0, -5, 345, 70, 1, 2, 3, 3, 30, \"Neutral\", \"Concordant Opposition\" }, { \"DUMATHOIN\", 0, -2, 366, 70, 0, 2, 4, 10, 40, \"Neutral\", \"Concordant Opposition\" }, { \"ABBATHOR\", 0, 0, 330, 50, 1, 2, 4, 2, 24, \"Neutral evil\", \"Hades\" }, { \"BERRONAR\", 0, -4, 370, 80, 1, 2, 4, 6, 36, \"Lawful good\", \"Seven Heavens\" }, // ---- the elves (pp. 112-113) ---- { \"AERDRIE FAENYA\", 1, -5, 322, 80, 0, 1, 4, 6, 20, \"Chaotic good\", \"Olympus and Gladsheim\" }, { \"EREVAN ILESERE\", 1, -1, 290, 85, 1, 0, 2, 2, 24, \"Chaotic neutral\", \"Olympus\" }, { \"SOLONOR THELANDIRA\", 1, -2, 308, 85, 0, 1, 8, 2, 16, \"Chaotic good\", \"Olympus\" }, { \"HANALI CELANIL\", 1, 99, 312, 95, 0, 1, 0, 0, 0, \"Chaotic good\", \"Olympus\" }, { \"LABELAS ENORETH\", 1, -3, 310, 93, 0, 1, 2, -1, -1, \"Chaotic good\", \"Olympus\" }, // ---- the halflings (pp. 114-115) ---- { \"SHEELA PERYROYL\", 1, 3, 306, 80, 3, 0, 2, 2, 16, \"Neutral\", \"Concordant Opposition\" }, { \"ARVOREEN\", 1, 1, 298, 65, 3, 1, 3, 2, 20, \"Lawful good\", \"Seven Heavens\" }, { \"CYRROLLALEE\", 1, 3, 260, 75, 3, 0, 3, -1, -1, \"Lawful good\", \"Seven Heavens\" }, { \"BRANDOBARIS\", 2, 0, 185, 60, -1, 0, 2, -1, -1, \"Neutral\", \"Prime Material\" }, // ---- the gnomes (pp. 116-117) ---- { \"BAERVAN WILDWANDERER\", 1, 1, 295, 20, 1, 0, 3, 2, 24, \"Neutral good\", \"Twin Paradises or Prime Material Plane\" }, { \"URDLEN\", 1, 2, 272, 30, 0, 2, 4, 4, 16, \"Chaotic evil\", \"Abyss\" }, { \"SEGOJAN EARTHCALLER\", 1, 0, 285, 20, 0, 1, 2, 3, 30, \"Neutral good\", \"Twin Paradises\" }, { \"FLANDAL STEELSKIN\", 2, 2, 230, 10, 0, 0, 3, 3, 24, \"Neutral good\", \"Twin Paradises\" }, // ---- the orcs (pp. 118-120) ---- { \"BAHGTRU\", 1, 1, 340, 35, 3, 2, 4, 10, 60, \"Lawful evil\", \"Nine Hells\" }, { \"SHARGAAS\", 1, 2, 265, 65, 2, 2, -1, 3, 30, \"Neutral evil\", \"Gehenna\" }, { \"ILNEVAL\", 1, -1, 331, 55, 3, 2, 4, 6, 36, \"Lawful evil\", \"Nine Hells\" }, { \"YURTRUS\", 1, 0, 303, 75, 0, 2, 4, -1, -1, \"Neutral evil\", \"Hades\" }, { \"LUTHIC\", 1, 3, 287, 80, 3, 2, 4, 5, 20, \"Lawful evil\", \"Nine Hells\" }, }; if (i < 0) i = 0; if (i > 22) i = 22; return T[i];",
    }, {
      "name" = "uasTierCount",
      "comment" = "The tier census: 5 greater, 16 lesser, 2 demigods.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) if (uasStat(i).tier == tier) ++n; return n;",
    }, {
      "name" = "uasRatingCount",
      "comment" = "The rating census: VI 10, III 5, IV 1, Nil 6, unrecorded 1 - matching the R405 seam counts for the four printed codes.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) if (uasStat(i).rating == code) ++n; return n;",
    }, {
      "name" = "uasPantheonSize",
      "comment" = "The pantheon slices: dwarves, elves, halflings, gnomes, orcs.",
      "kind" = "header pin",
      "body" = "if (p == 0) return 5; if (p == 1) return 5; if (p == 2) return 4; if (p == 3) return 4; return 5;",
    }, {
      "name" = "uasAcHoleCount",
      "comment" = "The scan holes: one AC garble (Hanali), one attacks garble (Shargaas).",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) if (uasStat(i).ac == UAS_AC_HOLE) ++n; return n;",
    }, {
      "name" = "uasAtkHoleCount",
      "comment" = "",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) if (uasStat(i).atkHalves == UAS_ATK_HOLE) ++n; return n;",
    }, {
      "name" = "uasDamageUnrecordedCount",
      "comment" = "The unprinted damage reads: 4.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) if (uasStat(i).dmgMin == UAS_DMG_UNRECORDED) ++n; return n;",
    }, {
      "name" = "uasTotalHitPoints",
      "comment" = "The total hit points across the 23 blocks - the drift catch: any single cell change moves it.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) n += uasStat(i).hp; return n;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uasDeityCount']() != 23  or m['uasDeityCount']() !=m['nhdDeityCount']()",
      "note" = "---- the census ----",
    }, {
      "expr" = "m['uasTierCount'](UAS_TIER_GREATER) != 5  or m['uasTierCount'](UAS_TIER_LESSER) != 16  or m['uasTierCount'](UAS_TIER_DEMI) != 2  or m['uasTierCount'](UAS_TIER_GREATER) +m['uasTierCount'](UAS_TIER_LESSER) +m['uasTierCount'](UAS_TIER_DEMI) != 23",
      "note" = "the tier census: 5/16/2",
    }, {
      "expr" = "m['uasRatingCount'](UAS_RATING_VI) != 10  or m['uasRatingCount'](UAS_RATING_III) != 5  or m['uasRatingCount'](UAS_RATING_IV) != 1  or m['uasRatingCount'](UAS_RATING_NIL) != 6  or m['uasRatingCount']( UAS_RATING_UNRECORDED) != 1  or m['uasRatingCount'](UAS_RATING_VI) !=m['nhdPsionicRatingCount'](0)  or m['uasRatingCount'](UAS_RATING_III) !=m['nhdPsionicRatingCount'](1)  or m['uasRatingCount'](UAS_RATING_IV) !=m['nhdPsionicRatingCount'](2)  or m['uasRatingCount'](UAS_RATING_NIL) !=m['nhdPsionicRatingCount'](3)",
      "note" = "the rating census: VI 10, III 5, IV 1, Nil 6, unrecorded 1 - and the four printed codes match the R405 seam live",
    }, {
      "expr" = "m['uasPantheonSize'](0) !=m['nhdPantheonSize'](0)  or m['uasPantheonSize'](1) !=m['nhdPantheonSize'](1)  or m['uasPantheonSize'](2) !=m['nhdPantheonSize'](2)  or m['uasPantheonSize'](3) !=m['nhdPantheonSize'](3)  or m['uasPantheonSize'](4) !=m['nhdPantheonSize'](4)",
      "note" = "the pantheon slices ride the R405 registry live",
    }, {
      "expr" = "m['uasTotalHitPoints']() != 6985",
      "note" = "---- the drift catch ----",
    }, {
      "expr" = "m['uasAcHoleCount']() != 1  or m['uasAtkHoleCount']() != 1  or m['uasDamageUnrecordedCount']() != 4  or m['uasStat'](8).ac != UAS_AC_HOLE  or m['uasStat'](19).atkHalves != UAS_ATK_HOLE",
      "note" = "---- the hole sentinels ----",
    }, {
      "expr" = "strcmp(m['uasStat'](0).name, \"CLANGGEDIN SILVERBEARD\") != 0  or m['uasStat'](0).ac != -4  or m['uasStat'](0).hp != 375  or m['uasStat'](0).mr != 50  or m['uasStat'](0).tier != UAS_TIER_GREATER  or m['uasStat'](0).rating != UAS_RATING_VI  or m['uasStat'](0).size != UAS_SIZE_L  or m['uasStat'](0).atkHalves != 4  or m['uasStat'](0).dmgMin != 3  or m['uasStat'](0).dmgMax != 36  or strcmp(m['uasStat'](0).align, \"Lawful neutral\") != 0  or strcmp(m['uasStat'](0).plane, \"Arcadia\") != 0",
      "note" = "---- the spot checks ---- Clanggedin (the first block)",
    }, {
      "expr" = "m['uasStat'](4).hp != 370  or m['uasStat'](4).mr != 80  or m['uasStat'](8).hp != 312  or m['uasStat'](8).mr != 95  or m['uasStat'](8).dmgMin != 0  or m['uasStat'](8).dmgMax != 0  or m['uasStat'](13).hp != 185  or m['uasStat'](13).tier != UAS_TIER_DEMI  or m['uasStat'](13).rating != UAS_RATING_UNRECORDED",
      "note" = "Berronar, Hanali, Brandobaris",
    }, {
      "expr" = "m['uasStat'](18).dmgMin != 10  or m['uasStat'](18).dmgMax != 60  or m['uasStat'](19).rating != UAS_RATING_IV  or m['uasStat'](19).ac != 2  or m['uasStat'](19).dmgMin != 3  or m['uasStat'](19).dmgMax != 30  or m['uasStat'](22).ac != 3  or m['uasStat'](22).hp != 287  or m['uasStat'](22).dmgMin != 5  or m['uasStat'](22).dmgMax != 20  or strcmp(m['uasStat'](22).align, \"Lawful evil\") != 0",
      "note" = "Bahgtru, Shargaas, Luthic",
    }, {
      "expr" = "strcmp(m['uasStat'](15).plane, \"Abyss\") != 0",
      "note" = "Urdlen: the evil gnome",
    } },
  "audit" = {
      "label" = "R406: the UA Appendix S stat blocks pin audit",
      "comment" = "The ungated data round rides the R405 seam: the 23 stat blocks pin their scan-clean numerics (tier, AC, HP, MR, rating, size, the attacks in halves, the damage range, the printed alignment and plane), the tier and rating censuses cross-check the R405 seam live, the hole sentinels record the scan garbles, and the 6985 hit-point sum catches any cell drift; the class lines, the MOVE values and the stat lines stay unpinned; census 332 -> 333.",
    },
}
