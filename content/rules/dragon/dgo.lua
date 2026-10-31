-- dgo: promoted from tools/spec_r910.json (the The Dragon issue-8 opener - the Gygax Planes article (folios 4-5), the Watson towns article (folios 5-7) and the Kuntz gems re-evaluation (folios 22-23): three adjudicated chains in one round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 910,
  "prefix" = "dgo",
  "banner" = {
      "title" = "The Dragon issue-8 opener - the Gygax Planes article (folios 4-5), the Watson towns article (folios 5-7) and the Kuntz gems re-evaluation (folios 22-23): three adjudicated chains in one round",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 8 (July 1977), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 8; the source lives in the archive.org item accessory-dragon-magazine-012). The folios: 4-5, the Gygax Designers Forum Planes article - the seven inner planes (Prime Material, Positive, Negative, the four Elemental) and sixteen outer, the ethereal-to-inner and astral-to-outer split, the astral restrictions (Prime Material only, never from the inner planes, first level only), one-plane walking, and the planar-existence law - special-metal creatures dual-planar, +1-only creatures in two planes, +2 in three, weapons removed one plane per plus with the sharpness and vorpal special cases; 5-7, the Watson Development of Towns in D&D article - the pawnshop's 1-in-6 defective stock, the 1-in-4 foreign merchants, the 1-in-8 thieves' quarter encounter per turn, the cartographer's 100-600 gp maps, the barber's 1 gp, the stable's 2-3 gp weekly board, the 20 gp soothsayer, the 50 gp-per-level magician, the brothel's 20/35 gp fees with the 10-100 gp information bribes, the surgeon's 25 gp wound cure at 50 percent and 35 gp poison cure at 1-in-6, the library's 100 gp base, Falgrave's 3-18 patrons two thirds non-human, and the three-floor limit; 22-23, the Kuntz A Re-evaluation of Gems and Jewelry in D&D article - the carat table, the basic-values table, the jewelry metal table, the gem-count table and the jewelry-type table, the description lists riding the transcript. The transcripts ride extract/dragon/008/ (all 32 issue pages); the issue-8 gap report ships pre-flip. PRINT FOLIO = PDF PAGE, verified at the printed 3, 12, 21, 22, 23 and 24 footers.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon, and the Gygax Planes article - though it prefigures the later print - pins as a variant layer with provenance, never core canon. The Kuntz garbles ride AS SCANNED, noted, never silent: the worked example's table labels read swapped against the printed tables' own bands (the 75 x 5 x 3 = 1,125 arithmetic is the anchor), and the carat table's starred rows overlap by the print's own arithmetic with the re-roll footnote noted. The gem-type description lists (Table C) ride the transcript, garbled in the OCR and never guessed. The editor's standing caution rides: none of this is official.",
    },
  "consts" = { {
      "name" = "dgoInnerPlanesCount",
      "value" = 7,
      "comment" = "the inner planes - the Prime Material, Positive and Negative Material, and the four Elemental (folios 4-5)",
    }, {
      "name" = "dgoOuterPlanesCount",
      "value" = 16,
      "comment" = "the outer planes - sixteen, the religious and philosophical goals of mankind and the other intellectual species (folio 5)",
    }, {
      "name" = "dgoSevenHeavensLevels",
      "value" = 7,
      "comment" = "the Seven Heavens run seven levels in Heaven (folio 5)",
    }, {
      "name" = "dgoNineHellsLayers",
      "value" = 9,
      "comment" = "the Nine Hells run nine layers - the Nine Hells of the print (folios 4-5)",
    }, {
      "name" = "dgoAbyssLayers",
      "value" = 666,
      "comment" = "the Abyss runs the 666 layers of the print (folios 4-5)",
    }, {
      "name" = "dgoCreaturePlanesAtPlus1",
      "value" = 2,
      "comment" = "creatures struck only with +1 or greater magical weapons exist wholly and simultaneously in two planes (folio 4)",
    }, {
      "name" = "dgoCreaturePlanesAtPlus2",
      "value" = 3,
      "comment" = "creatures requiring +2 or better exist in three planes simultaneously (folio 4)",
    }, {
      "name" = "dgoWeaponPlanesPerPlus",
      "value" = 1,
      "comment" = "a magic weapon can be removed no further than one plane per point of its best to-hit bonus - a +2 retains its magic two planes from the Prime Material (folio 4)",
    }, {
      "name" = "dgoWalkAdjacentPlanes",
      "value" = 1,
      "comment" = "walking on the Outer Planes is limited to one plane to either side of the starting plane (folio 5)",
    }, {
      "name" = "dgoPawnshopDefectiveChance",
      "value" = 6,
      "comment" = "pawnshop armor and weapons have a 1-in-6 chance of being defective in some manner (folio 6)",
    }, {
      "name" = "dgoCartographerMapMin",
      "value" = 100,
      "comment" = "the cartographer's wilderness and dungeon maps - 100-600 gp by remoteness, the minimum (folio 5)",
    }, {
      "name" = "dgoCartographerMapMax",
      "value" = 600,
      "comment" = "the cartographer's maps by remoteness - the maximum (folio 5)",
    }, {
      "name" = "dgoBarberFeeGp",
      "value" = 1,
      "comment" = "the barber's haircut and shave - one gp (folio 5)",
    }, {
      "name" = "dgoStableBoardMin",
      "value" = 2,
      "comment" = "horses boarded at the stable 2-3 gp per week - the minimum (folio 6)",
    }, {
      "name" = "dgoStableBoardMax",
      "value" = 3,
      "comment" = "horses boarded 2-3 gp per week - the maximum (folio 6)",
    }, {
      "name" = "dgoForeignMerchantChance",
      "value" = 4,
      "comment" = "the town square market - a 1-in-4 chance a foreign merchant or two is in attendance (folio 6)",
    }, {
      "name" = "dgoThievesQuarterEncounter",
      "value" = 8,
      "comment" = "the dark side of town - a 1-in-8 chance per turn of encountering a thief or being attacked by brigands (folio 6)",
    }, {
      "name" = "dgoSoothsayerFeeGp",
      "value" = 20,
      "comment" = "the soothsayer predicts an expedition's outcome for 20 gp, drawing on the DM's knowledge and an accuracy dieroll (folio 6)",
    }, {
      "name" = "dgoMagicianFeePerLevel",
      "value" = 50,
      "comment" = "the town magician casts spells for a fee of 50 gp times spell level (folio 6)",
    }, {
      "name" = "dgoBrothelFeeGp",
      "value" = 20,
      "comment" = "the brothel fee about 20 gp, 35 for the special (folio 6)",
    }, {
      "name" = "dgoBrothelInfoBribeMin",
      "value" = 10,
      "comment" = "the brothel brims with privy information for bribes of 10-100 gp - the minimum (folio 6)",
    }, {
      "name" = "dgoBrothelInfoBribeMax",
      "value" = 100,
      "comment" = "the brothel information bribes 10-100 gp - the maximum (folio 6)",
    }, {
      "name" = "dgoBrothelPatronsMin",
      "value" = 1,
      "comment" = "one to six male patrons in the brothel waiting area - the minimum (folio 6)",
    }, {
      "name" = "dgoBrothelPatronsMax",
      "value" = 6,
      "comment" = "one to six male patrons - the maximum (folio 6)",
    }, {
      "name" = "dgoSurgeonWoundFeeGp",
      "value" = 25,
      "comment" = "the surgeon attempts to cure 1-6 wound points for 25 gp at a 50 percent chance of success (folio 7)",
    }, {
      "name" = "dgoSurgeonWoundCureMin",
      "value" = 1,
      "comment" = "the surgeon's wound-point cure 1-6 - the minimum (folio 7)",
    }, {
      "name" = "dgoSurgeonWoundCureMax",
      "value" = 6,
      "comment" = "the surgeon's wound-point cure 1-6 - the maximum (folio 7)",
    }, {
      "name" = "dgoSurgeonPoisonFeeGp",
      "value" = 35,
      "comment" = "the surgeon attempts to cure poison for 35 gp at a one-in-six chance (folio 7)",
    }, {
      "name" = "dgoSurgeonPoisonChance",
      "value" = 6,
      "comment" = "the poison cure's one-in-six chance (folio 7)",
    }, {
      "name" = "dgoSurgeonWoundSuccessPct",
      "value" = 50,
      "comment" = "the wound cure's 50 percent chance of success (folio 7)",
    }, {
      "name" = "dgoLibraryBaseFeeGp",
      "value" = 100,
      "comment" = "the library's base value of general information about 100 gp, specific facts increasingly more expensive (folio 7)",
    }, {
      "name" = "dgoFalgravePatronsMin",
      "value" = 3,
      "comment" = "Falgrave's inn - 3-18 patrons, the minimum (folio 7)",
    }, {
      "name" = "dgoFalgravePatronsMax",
      "value" = 18,
      "comment" = "Falgrave's inn - 3-18 patrons, the maximum (folio 7)",
    }, {
      "name" = "dgoFalgraveWayfarersMin",
      "value" = 1,
      "comment" = "one to four non-human wayfarers or merchants at Falgrave's - the minimum (folio 7)",
    }, {
      "name" = "dgoFalgraveWayfarersMax",
      "value" = 4,
      "comment" = "one to four non-human wayfarers - the maximum (folio 7)",
    }, {
      "name" = "dgoMaxFloors",
      "value" = 3,
      "comment" = "generally no more than three floors save for a special tower or temple (folio 5)",
    }, {
      "name" = "dgoGemACaratCount",
      "value" = 11,
      "comment" = "the dgoGemACarat table runs 11 rows - the Kuntz substitution tables (folios 22-23)",
    }, {
      "name" = "dgoGemBValueCount",
      "value" = 10,
      "comment" = "the dgoGemBValue table runs 10 rows - the Kuntz substitution tables (folios 22-23)",
    }, {
      "name" = "dgoGemDMetalCount",
      "value" = 10,
      "comment" = "the dgoGemDMetal table runs 10 rows - the Kuntz substitution tables (folios 22-23)",
    }, {
      "name" = "dgoGemECountCount",
      "value" = 7,
      "comment" = "the dgoGemECount table runs 7 rows - the Kuntz substitution tables (folios 22-23)",
    }, {
      "name" = "dgoGemFTypeCount",
      "value" = 15,
      "comment" = "the dgoGemFType table runs 15 rows - the Kuntz substitution tables (folios 22-23)",
    } },
  "bools" = { {
      "name" = "dgoEtherealReachesInner",
      "value" = true,
      "comment" = "the Ethereal reaches any of the inner planes (folio 4)",
    }, {
      "name" = "dgoAstralReachesOuter",
      "value" = true,
      "comment" = "the Astral reaches the outer planes (folio 4)",
    }, {
      "name" = "dgoAstralFromPrimeOnly",
      "value" = true,
      "comment" = "the traveler must be in the Prime Material to enter the Astral (folio 5)",
    }, {
      "name" = "dgoAstralNotFromInner",
      "value" = true,
      "comment" = "the Astral cannot be reached from the Elemental, Positive or Negative Planes (folio 5)",
    }, {
      "name" = "dgoAstralFirstLevelOnly",
      "value" = true,
      "comment" = "the Astral takes a traveler to the first level of the Outer Planes - physical travel must be used to proceed to the other levels (folio 5)",
    }, {
      "name" = "dgoSpecialMetalCreaturesDualPlanar",
      "value" = true,
      "comment" = "creatures harmed only by special metals (silver, cold iron) gain the invulnerability from partial existence in the Positive or Negative Material Plane (folio 4)",
    }, {
      "name" = "dgoMagicWeaponAttacksAcrossPlanes",
      "value" = true,
      "comment" = "any person armed with a magic weapon can attack into the Astral or Ethereal Plane if aware of the opponent operating there (folio 4)",
    }, {
      "name" = "dgoWeaponLosesMagicBeyondLimit",
      "value" = true,
      "comment" = "weapons removed beyond their plane limit lose all magic, becoming normal weapons (folio 4)",
    }, {
      "name" = "dgoSwordOfSharpnessSpecialCase",
      "value" = true,
      "comment" = "the sword of sharpness and the vorpal blade get special treatment under the plane-removal law; a life-draining sword operates primarily on the Negative Material Plane and gains no such consideration (folio 4)",
    }, {
      "name" = "dgoTownLayoutSharesDungeonScale",
      "value" = true,
      "comment" = "the town is laid out like the dungeon, using the same graphic and scale system (folio 5)",
    }, {
      "name" = "dgoTownWalledOnBorder",
      "value" = true,
      "comment" = "a large town on a hostile border or astride a trade route or waterway is most likely walled (folio 5)",
    }, {
      "name" = "dgoKeepHousesTheLord",
      "value" = true,
      "comment" = "a keep nearby or inside houses the ruling lord and his retainers, the local law and order (folio 5)",
    }, {
      "name" = "dgoFalgraveNonhumanThirds",
      "value" = true,
      "comment" = "at Falgrave's two thirds of the patrons shall be non-human and half of those warriors (folio 7)",
    }, {
      "name" = "dgoSurgeonOneAttemptPerDay",
      "value" = true,
      "comment" = "the surgeon's maximum of one attempt per day and one successful healing or cure per week, paid regardless of success (folio 7)",
    }, {
      "name" = "dgoMarketRumorMill",
      "value" = true,
      "comment" = "the marketplace is a hot bed of rumor and local gossip, a good percentage false (folio 6)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "dgoGemACarat",
      "tag" = "GmA",
      "count" = "dgoGemACaratCount",
      "sentinel" = 0,
      "cols" = { "dgoGemACaratMin", "dgoGemACaratMax" },
      "col_comments" = { "the carat band minimum per percentile row of the Kuntz carat table - 01-30 through 00, the starred rows re-rolled per the print's footnote (folio 22)", "the carat band maximum per percentile row, the print's starred rows overlapping by its own arithmetic - as scanned (folio 22)" },
      "data" = { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }, { 5, 5 }, { 6, 9 }, { 10, 10 }, { 20, 50 }, { 20, 70 }, { 30, 80 }, { 100, 100 } },
      "audit_comment" = "the Kuntz carat determination table - eleven percentile bands from 1 carat to the 100-carat 00 row, the asterisked rows re-rolled 86-98 as 100-300, 99 as 200-500, 00 as 500-1,000 carats (folio 22)",
    }, {
      "name" = "dgoGemBValue",
      "tag" = "GmB",
      "count" = "dgoGemBValueCount",
      "sentinel" = 0,
      "cols" = { "dgoGemBValueGp" },
      "col_comments" = { "the gem basic value in gold pieces per carat by percentile band - 10 gp at 01-10 through 200 gp at 96-00 (folio 22)" },
      "data" = { { 10 }, { 20 }, { 25 }, { 50 }, { 75 }, { 100 }, { 125 }, { 150 }, { 175 }, { 200 } },
      "audit_comment" = "the Kuntz gems basic values table - ten percentile bands at 10 to 200 gold pieces per carat (folio 22)",
    }, {
      "name" = "dgoGemDMetal",
      "tag" = "GmD",
      "count" = "dgoGemDMetalCount",
      "sentinel" = 0,
      "cols" = { "dgoGemDMetalMin", "dgoGemDMetalMax" },
      "col_comments" = { "the jewelry metal band value minimum in gold pieces - bronze at 01-20 through the mithril-plus-platinum 96-00 row (folio 23)", "the jewelry metal band value maximum in gold pieces (folio 23)" },
      "data" = { { 10, 40 }, { 20, 80 }, { 100, 400 }, { 500, 1000 }, { 500, 1500 }, { 1000, 2000 }, { 1000, 3000 }, { 1000, 4000 }, { 1500, 4500 }, { 2000, 5000 } },
      "audit_comment" = "the Kuntz jewelry composition metal table - bronze through mithril plus platinum filigree, ten bands from 10-40 to 2,000-5,000 gold pieces (folio 23)",
    }, {
      "name" = "dgoGemECount",
      "tag" = "GmE",
      "count" = "dgoGemECountCount",
      "sentinel" = 0,
      "cols" = { "dgoGemEGemsMin", "dgoGemEGemsMax", "dgoGemECaratCap" },
      "col_comments" = { "the gem count band minimum per percentile row of the jewelry composition table - 2-12 gems at 01-25 through 10-40 at 00 (folio 23)", "the gem count band maximum per percentile row (folio 23)", "the carat cap per row as printed - 5 at 01-25, 10 at 26-50, 20 at 51-75, 0 the no-limitations row, and the at-least minimums of 5, 10 and 20 carats riding positive with the band semantics in the print (folio 23)" },
      "data" = { { 2, 12, 5 }, { 3, 18, 10 }, { 3, 36, 20 }, { 2, 20, 0 }, { 3, 24, 5 }, { 3, 30, 10 }, { 10, 40, 20 } },
      "audit_comment" = "the Kuntz jewelry composition table - seven percentile bands of gem counts with the carat caps and at-least minimums as printed (folio 23)",
    }, {
      "name" = "dgoGemFType",
      "tag" = "GmF",
      "count" = "dgoGemFTypeCount",
      "sentinel" = 0,
      "cols" = { "dgoGemFBandMin", "dgoGemFBandMax" },
      "col_comments" = { "the jewelry type die band minimum - rings at 01-10, bracers 11-20, bracelets 21-25, chalices 26-30, cups 31-35, tankards 36-40, earrings 41-50, necklaces 51-60, tableware 61-70, candelabra 71-75, anklets 76-80, neckbands 81-85, mirrors 86-90, snuff boxes 91-95, statuettes 96-00 (folio 23)", "the jewelry type die band maximum (folio 23)" },
      "data" = { { 1, 10 }, { 11, 20 }, { 21, 25 }, { 26, 30 }, { 31, 35 }, { 36, 40 }, { 41, 50 }, { 51, 60 }, { 61, 70 }, { 71, 75 }, { 76, 80 }, { 81, 85 }, { 86, 90 }, { 91, 95 }, { 96, 100 } },
      "audit_comment" = "the Kuntz jewelry types table - fifteen die bands, the type names riding the transcript and this comment: rings, bracers, bracelets, chalices, cups, tankards, earrings, necklaces, tableware, candelabra, anklets, neckbands, mirrors, snuff boxes, statuettes (folio 23)",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgoInnerPlanesCount']() != 7 or m['dgoOuterPlanesCount']() != 16 or m['dgoSevenHeavensLevels']() != 7 or m['dgoNineHellsLayers']() != 9 or m['dgoAbyssLayers']() != 666",
      "note" = "the planar census - seven inner, sixteen outer, seven levels in the Seven Heavens, nine layers of the Hells, the 666 layers of the Abyss (folios 4-5)",
    }, {
      "expr" = "m['dgoCreaturePlanesAtPlus1']() != 2 or m['dgoCreaturePlanesAtPlus2']() != 3 or m['dgoWeaponPlanesPerPlus']() != 1 or m['dgoWalkAdjacentPlanes']() != 1",
      "note" = "the planar-existence law - a +1-only creature in two planes, a +2 in three, weapons removed one plane per plus, walking one plane to either side (folios 4-5)",
    }, {
      "expr" = "m['dgoEtherealReachesInner']() != 1 or m['dgoAstralReachesOuter']() != 1 or m['dgoAstralFromPrimeOnly']() != 1 or m['dgoAstralNotFromInner']() != 1 or m['dgoAstralFirstLevelOnly']() != 1 or m['dgoSpecialMetalCreaturesDualPlanar']() != 1 or m['dgoMagicWeaponAttacksAcrossPlanes']() != 1 or m['dgoWeaponLosesMagicBeyondLimit']() != 1 or m['dgoSwordOfSharpnessSpecialCase']() != 1",
      "note" = "the planar doctrines - the ethereal/astral split, the astral restrictions, the dual-planar special-metal creatures, the cross-plane weapon attacks, the plane-removal law, the sharpness and vorpal special cases (folios 4-5)",
    }, {
      "expr" = "m['dgoPawnshopDefectiveChance']() != 6 or m['dgoForeignMerchantChance']() != 4 or m['dgoThievesQuarterEncounter']() != 8",
      "note" = "the town chances - the 1-in-6 defective pawnshop, the 1-in-4 foreign merchants, the 1-in-8 thieves' quarter encounter per turn (folios 5-6)",
    }, {
      "expr" = "m['dgoCartographerMapMin']() != 100 or m['dgoCartographerMapMax']() != 600 or m['dgoBarberFeeGp']() != 1 or m['dgoStableBoardMin']() != 2 or m['dgoStableBoardMax']() != 3",
      "note" = "the town services - the 100-600 gp maps, the 1 gp barber, the 2-3 gp weekly stable (folios 5-6)",
    }, {
      "expr" = "m['dgoSoothsayerFeeGp']() != 20 or m['dgoMagicianFeePerLevel']() != 50 or m['dgoBrothelFeeGp']() != 20 or m['dgoBrothelInfoBribeMin']() != 10 or m['dgoBrothelInfoBribeMax']() != 100 or m['dgoBrothelPatronsMin']() != 1 or m['dgoBrothelPatronsMax']() != 6",
      "note" = "the dark side of town - the 20 gp soothsayer, the 50 gp per level magician, the 20 gp brothel with its 10-100 gp information bribes and 1-6 patrons (folio 6)",
    }, {
      "expr" = "m['dgoSurgeonWoundFeeGp']() != 25 or m['dgoSurgeonWoundCureMin']() != 1 or m['dgoSurgeonWoundCureMax']() != 6 or m['dgoSurgeonPoisonFeeGp']() != 35 or m['dgoSurgeonPoisonChance']() != 6 or m['dgoSurgeonWoundSuccessPct']() != 50 or m['dgoSurgeonOneAttemptPerDay']() != 1",
      "note" = "the surgeon - 25 gp for the 1-6 wound-point cure at 50 percent, 35 gp for the 1-in-6 poison cure, one attempt per day and one success per week (folio 7)",
    }, {
      "expr" = "m['dgoLibraryBaseFeeGp']() != 100 or m['dgoFalgravePatronsMin']() != 3 or m['dgoFalgravePatronsMax']() != 18 or m['dgoFalgraveWayfarersMin']() != 1 or m['dgoFalgraveWayfarersMax']() != 4 or m['dgoFalgraveNonhumanThirds']() != 1",
      "note" = "the library at 100 gp base and Falgrave's - 3-18 patrons, two thirds non-human, half of those warriors, 1-4 wayfarers (folio 7)",
    }, {
      "expr" = "m['dgoMaxFloors']() != 3 or m['dgoTownLayoutSharesDungeonScale']() != 1 or m['dgoTownWalledOnBorder']() != 1 or m['dgoKeepHousesTheLord']() != 1 or m['dgoMarketRumorMill']() != 1",
      "note" = "the town doctrines - the three-floor limit, the shared dungeon scale, the border walls, the keep, the rumor mill (folios 5-6)",
    } },
  "audit" = {
      "label" = "R910 issue-8 opener audit",
      "comment" = "THE DRAGON ISSUE-8 OPENER ROUND - three adjudicated chains. The Gygax Planes article (folios 4-5): the planar census, the travel split and restrictions, and the planar-existence law for weapons and special-metal creatures. The Watson towns article (folios 5-7): the town chances, services and fees, Falgrave's and the three-floor doctrine. The Kuntz gems re-evaluation (folios 22-23): the carat, basic-value, metal, gem-count and jewelry-type substitution tables with the AS-SCANNED garbles noted.",
    },
}
