-- dck: promoted from tools/spec_r558.json (the THE DSG COMPILED TABLES, R558: printed pp. 121-123 - the book's own reprint spread, a verification-and-flip round: the thirty-four numbered tables reprinted from the chapters, each verified const-for-const against the pins its chapter already landed - Tables 1-9 the movement block (the swimming encumbrance effects with the sink footnote, the climbing rates with the thieves-only footnote, the broad jumping bands, the grapple crossing, the thrown loop ranges, the passageway sizes, the armor width increases, the darkness course changes) against the R504/R505 pins; Tables 15-16 the odor detection and wind effects against the odor pins; Tables 17-18 the cave-in location and chain reaction against the cave-in pins; Table 19 the underground structure defensive point values against the DPV pins; Table 20 the unsteady NPC reactions - the screaming flight to the endurance limit, the nearby-PC attack, the quiet sneak away, the freeze - against the landed pins; Tables 21-26 the boats (the movement rates, the standstill acceleration, the draught and ceilings, the nonproficiency penalties, the collision probability with the proficiency slash, the damage bands) against the boat pins; and Tables 27-34 the mining (the rates grid, the vein direction, the path alterations, the products with the mithril check and the gemstones, the ore and gemstone quality with the pure-vein footnote) against the mining pins. ONE GENUINE DELTA pinned this round: the compiled Table 3 carries five grapple rows where the chapter original carried two - the stone parapet (01-72/73-78/79-00), the stone wall top (01-83/84-89/90-00), and the tree branches (01-66/67-70/71-00) now sit beside the landed rocky ledge and wooden wall rows. The spread skips tables 10-14 - the in-chapter proficiency and combat tables are not reprinted.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 558,
  "prefix" = "dck",
  "banner" = {
      "title" = "THE DSG COMPILED TABLES, R558: printed pp. 121-123 - the book's own reprint spread, a verification-and-flip round: the thirty-four numbered tables reprinted from the chapters, each verified const-for-const against the pins its chapter already landed - Tables 1-9 the movement block (the swimming encumbrance effects with the sink footnote, the climbing rates with the thieves-only footnote, the broad jumping bands, the grapple crossing, the thrown loop ranges, the passageway sizes, the armor width increases, the darkness course changes) against the R504/R505 pins; Tables 15-16 the odor detection and wind effects against the odor pins; Tables 17-18 the cave-in location and chain reaction against the cave-in pins; Table 19 the underground structure defensive point values against the DPV pins; Table 20 the unsteady NPC reactions - the screaming flight to the endurance limit, the nearby-PC attack, the quiet sneak away, the freeze - against the landed pins; Tables 21-26 the boats (the movement rates, the standstill acceleration, the draught and ceilings, the nonproficiency penalties, the collision probability with the proficiency slash, the damage bands) against the boat pins; and Tables 27-34 the mining (the rates grid, the vein direction, the path alterations, the products with the mithril check and the gemstones, the ore and gemstone quality with the pure-vein footnote) against the mining pins. ONE GENUINE DELTA pinned this round: the compiled Table 3 carries five grapple rows where the chapter original carried two - the stone parapet (01-72/73-78/79-00), the stone wall top (01-83/84-89/90-00), and the tree branches (01-66/67-70/71-00) now sit beside the landed rocky ledge and wooden wall rows. The spread skips tables 10-14 - the in-chapter proficiency and combat tables are not reprinted.",
      "provenance" = "djvu lines 15340-15800 with the Capture-layer pdf 121-123 cross-read (the pure-python extractor, parser page = printed page). The two reads agree across the round; the djvu table OCR is heavily garbled (the Cyrillic headers, the lost cells) but every load-bearing value matched against both the capture read and the landed chapter pins - the compiled reprints are the book's own second printing of values already verified in their chapter rounds, and this round verifies the reprints rather than re-deriving them. A CLEAN-READ ROUND. The Compiled tables child flips [x] in the same commit: the gap census moves 142/13 -> 143/12.",
      "sentinel" = "The arc tail: R557 the mapping chapter closed, R558 the compiled tables closed; next the perspective map plates pp. 124-127 (graphics - a verify-only round), the index p. 128 (a roster round), then the DM-section parent, the front-matter chapter p. 6, and the arc's final census.",
    },
  "consts" = { {
      "comment" = "the compiled spread reprints the book's thirty-four numbered tables",
      "name" = "dckCompiledTableCount",
      "value" = 34,
    }, {
      "comment" = "the compiled Table 3 carries five grapple target rows - the chapter original carried two",
      "name" = "dckT3RowCount",
      "value" = 5,
    }, {
      "comment" = "the stone parapet row: 01-72 miss",
      "name" = "dckT3ParapetMiss",
      "value" = 72,
    }, {
      "comment" = "the stone parapet row: 73-78 catch and slip",
      "name" = "dckT3ParapetSlip",
      "value" = 78,
    }, {
      "comment" = "the stone wall top row: 01-83 miss",
      "name" = "dckT3WallTopMiss",
      "value" = 83,
    }, {
      "comment" = "the stone wall top row: 84-89 catch and slip",
      "name" = "dckT3WallTopSlip",
      "value" = 89,
    }, {
      "comment" = "the tree branches row: 01-66 miss",
      "name" = "dckT3BranchesMiss",
      "value" = 66,
    }, {
      "comment" = "the tree branches row: 67-70 catch and slip",
      "name" = "dckT3BranchesSlip",
      "value" = 70,
    }, {
      "comment" = "the catch maximum on every grapple row: 00 - 79-00, 90-00, 71-00 beside 94-00 and 75-00",
      "name" = "dckT3CatchMax",
      "value" = 100,
    } },
  "bools" = { {
      "comment" = "the compiled spread pp. 121-123: the book's own table reprints, numbered per the in-book table numbers",
      "name" = "dckSpreadDefines",
      "value" = true,
    }, {
      "comment" = "Tables 1-9, the movement reprints - swimming encumbrance, climbing rates, broad jumping, the grapple crossing, the thrown loop ranges, passageway sizes, armor width, darkness course changes - verified const-for-const against the landed R504/R505 movement pins",
      "name" = "dckMovementReprints",
      "value" = true,
    }, {
      "comment" = "the Table 1 footnote: an encumbered character cannot move through the water under his own power - if he enters the water, he will sink",
      "name" = "dckT1Footnote",
      "value" = true,
    }, {
      "comment" = "the Table 2 footnote: the very-smooth and smooth-cracked surfaces can be climbed only by thieves",
      "name" = "dckT2Footnote",
      "value" = true,
    }, {
      "comment" = "the Table 3 delta: the compiled reprint carries five grapple rows where the chapter original carried two - the stone parapet, stone wall top, and tree branches rows pinned this round beside the landed rocky ledge and wooden wall",
      "name" = "dckT3Richer",
      "value" = true,
    }, {
      "comment" = "Tables 15-16, the odor reprints - detection by distance band and wind effects - verified against the landed odor pins",
      "name" = "dckOdorReprints",
      "value" = true,
    }, {
      "comment" = "Tables 17-18, the cave-in reprints - location and chain reaction - verified against the landed cave-in pins",
      "name" = "dckCaveInReprints",
      "value" = true,
    }, {
      "comment" = "Table 19, the underground structure defensive point value reprint - verified against the landed DPV pins",
      "name" = "dckDpvReprints",
      "value" = true,
    }, {
      "comment" = "Table 20, the unsteady NPC reactions reprint - the screaming flight, the nearby-PC attack, the quiet sneak away, the freeze - verified against the landed pins",
      "name" = "dckUnsteadyReprints",
      "value" = true,
    }, {
      "comment" = "Tables 21-26, the boat reprints - movement rates, standstill acceleration, draught and ceilings, nonproficiency penalties, collision probability, damage - verified against the landed boat pins",
      "name" = "dckBoatReprints",
      "value" = true,
    }, {
      "comment" = "the Table 25 footnote: the number before the slash is for a character with boating proficiency, the number after for one without",
      "name" = "dckT25Footnote",
      "value" = true,
    }, {
      "comment" = "Tables 27-34, the mining reprints - rates, vein direction, path alterations, products, the mithril check, gemstones, ore and gemstone quality - verified against the landed mining pins",
      "name" = "dckMiningReprints",
      "value" = true,
    }, {
      "comment" = "the Table 33 footnote: a 10 on the quality roll rerolled - another 10 means a pure vein of metal requiring no smelting, a 1-9 the normal smelting",
      "name" = "dckT33Footnote",
      "value" = true,
    }, {
      "comment" = "the compiled spread skips tables 10-14 - the in-chapter proficiency and combat tables are not reprinted",
      "name" = "dckT1014Absent",
      "value" = true,
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dckCompiledTableCount']() != 34",
      "note" = "the spread: thirty-four reprinted tables.",
    }, {
      "expr" = "m['dckT3RowCount']() != 5",
      "note" = "the grapple grid: five rows in the compiled reprint.",
    }, {
      "expr" = "m['dckT3ParapetMiss']() != 72 or m['dckT3ParapetSlip']() != 78",
      "note" = "the stone parapet: 01-72 miss, 73-78 slip.",
    }, {
      "expr" = "m['dckT3WallTopMiss']() != 83 or m['dckT3WallTopSlip']() != 89",
      "note" = "the stone wall top: 01-83 miss, 84-89 slip.",
    }, {
      "expr" = "m['dckT3BranchesMiss']() != 66 or m['dckT3BranchesSlip']() != 70",
      "note" = "the tree branches: 01-66 miss, 67-70 slip.",
    }, {
      "expr" = "m['dckT3CatchMax']() != 100",
      "note" = "the catch maximum: 00 on every grapple row.",
    }, {
      "expr" = "m['dckMovementReprints']() != 1 or m['dckOdorReprints']() != 1",
      "note" = "the reprints verified: the movement and odor tables.",
    }, {
      "expr" = "m['dckBoatReprints']() != 1 or m['dckMiningReprints']() != 1",
      "note" = "the reprints verified: the boat and mining tables.",
    } },
  "audit" = {
      "label" = "R558 DSG compiled tables audit",
      "comment" = "The compiled tables pins printed pp. 121-123: the book's own reprint spread, verified const-for-const against the landed pins - Tables 1-9 the movement reprints (R504/R505), 15-16 the odor, 17-18 the cave-ins, 19 the DPV, 20 the unsteady reactions, 21-26 the boats, and 27-34 the mining - with the Table 3 five-row grapple delta pinned this round (the stone parapet, stone wall top, and tree branches rows the chapter original lacked), the Table 1 and Table 2 footnotes, the Table 25 proficiency slash split, and the Table 33 pure-vein footnote. The Compiled tables child flips [x] in the same commit.",
    },
}
