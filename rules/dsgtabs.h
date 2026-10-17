// =========================================================================================
// Adnd1 - rules/dsgtabs.h
// THE DSG COMPILED TABLES, R558: printed pp. 121-123 - the book's own reprint
// spread, a verification-and-flip round: the thirty-four numbered tables
// reprinted from the chapters, each verified const-for-const against the pins
// its chapter already landed - Tables 1-9 the movement block (the swimming
// encumbrance effects with the sink footnote, the climbing rates with the
// thieves-only footnote, the broad jumping bands, the grapple crossing, the
// thrown loop ranges, the passageway sizes, the armor width increases, the
// darkness course changes) against the R504/R505 pins; Tables 15-16 the odor
// detection and wind effects against the odor pins; Tables 17-18 the cave-in
// location and chain reaction against the cave-in pins; Table 19 the
// underground structure defensive point values against the DPV pins; Table 20
// the unsteady NPC reactions - the screaming flight to the endurance limit,
// the nearby-PC attack, the quiet sneak away, the freeze - against the landed
// pins; Tables 21-26 the boats (the movement rates, the standstill
// acceleration, the draught and ceilings, the nonproficiency penalties, the
// collision probability with the proficiency slash, the damage bands) against
// the boat pins; and Tables 27-34 the mining (the rates grid, the vein
// direction, the path alterations, the products with the mithril check and
// the gemstones, the ore and gemstone quality with the pure-vein footnote)
// against the mining pins. ONE GENUINE DELTA pinned this round: the compiled
// Table 3 carries five grapple rows where the chapter original carried two -
// the stone parapet (01-72/73-78/79-00), the stone wall top
// (01-83/84-89/90-00), and the tree branches (01-66/67-70/71-00) now sit
// beside the landed rocky ledge and wooden wall rows. The spread skips tables
// 10-14 - the in-chapter proficiency and combat tables are not reprinted.
// census 481 -> 482.
//
// djvu lines 15340-15800 with the Capture-layer pdf 121-123 cross-read (the
// pure-python extractor, parser page = printed page). The two reads agree
// across the round; the djvu table OCR is heavily garbled (the Cyrillic
// headers, the lost cells) but every load-bearing value matched against both
// the capture read and the landed chapter pins - the compiled reprints are
// the book's own second printing of values already verified in their chapter
// rounds, and this round verifies the reprints rather than re-deriving them.
// A CLEAN-READ ROUND. The Compiled tables child flips [x] in the same commit:
// the gap census moves 142/13 -> 143/12.
//
// The arc tail: R557 the mapping chapter closed, R558 the compiled tables
// closed; next the perspective map plates pp. 124-127 (graphics - a
// verify-only round), the index p. 128 (a roster round), then the DM-section
// parent, the front-matter chapter p. 6, and the arc's final census.
//
namespace rules {

// ---- the spread head section ----

// the compiled spread reprints the book's thirty-four numbered tables
inline int dckCompiledTableCount()
    { return 34; }

// the compiled spread pp. 121-123: the book's own table reprints, numbered
// per the in-book table numbers
inline bool dckSpreadDefines()
    { return true; }

// the compiled spread skips tables 10-14 - the in-chapter proficiency and
// combat tables are not reprinted
inline bool dckT1014Absent()
    { return true; }

// ---- the movement reprints section ----

// Tables 1-9, the movement reprints - swimming encumbrance, climbing rates,
// broad jumping, the grapple crossing, the thrown loop ranges, passageway
// sizes, armor width, darkness course changes - verified const-for-const
// against the landed R504/R505 movement pins
inline bool dckMovementReprints()
    { return true; }

// the Table 1 footnote: an encumbered character cannot move through the water
// under his own power - if he enters the water, he will sink
inline bool dckT1Footnote()
    { return true; }

// the Table 2 footnote: the very-smooth and smooth-cracked surfaces can be
// climbed only by thieves
inline bool dckT2Footnote()
    { return true; }

// ---- the grapple delta section ----

// the compiled Table 3 carries five grapple target rows - the chapter
// original carried two
inline int dckT3RowCount()
    { return 5; }

// the stone parapet row: 01-72 miss
inline int dckT3ParapetMiss()
    { return 72; }

// the stone parapet row: 73-78 catch and slip
inline int dckT3ParapetSlip()
    { return 78; }

// the stone wall top row: 01-83 miss
inline int dckT3WallTopMiss()
    { return 83; }

// the stone wall top row: 84-89 catch and slip
inline int dckT3WallTopSlip()
    { return 89; }

// the tree branches row: 01-66 miss
inline int dckT3BranchesMiss()
    { return 66; }

// the tree branches row: 67-70 catch and slip
inline int dckT3BranchesSlip()
    { return 70; }

// the catch maximum on every grapple row: 00 - 79-00, 90-00, 71-00 beside
// 94-00 and 75-00
inline int dckT3CatchMax()
    { return 100; }

// the Table 3 delta: the compiled reprint carries five grapple rows where the
// chapter original carried two - the stone parapet, stone wall top, and tree
// branches rows pinned this round beside the landed rocky ledge and wooden
// wall
inline bool dckT3Richer()
    { return true; }

// ---- the environment reprints section ----

// Tables 15-16, the odor reprints - detection by distance band and wind
// effects - verified against the landed odor pins
inline bool dckOdorReprints()
    { return true; }

// Tables 17-18, the cave-in reprints - location and chain reaction - verified
// against the landed cave-in pins
inline bool dckCaveInReprints()
    { return true; }

// Table 19, the underground structure defensive point value reprint -
// verified against the landed DPV pins
inline bool dckDpvReprints()
    { return true; }

// Table 20, the unsteady NPC reactions reprint - the screaming flight, the
// nearby-PC attack, the quiet sneak away, the freeze - verified against the
// landed pins
inline bool dckUnsteadyReprints()
    { return true; }

// ---- the boat reprints section ----

// Tables 21-26, the boat reprints - movement rates, standstill acceleration,
// draught and ceilings, nonproficiency penalties, collision probability,
// damage - verified against the landed boat pins
inline bool dckBoatReprints()
    { return true; }

// the Table 25 footnote: the number before the slash is for a character with
// boating proficiency, the number after for one without
inline bool dckT25Footnote()
    { return true; }

// ---- the mining reprints section ----

// Tables 27-34, the mining reprints - rates, vein direction, path
// alterations, products, the mithril check, gemstones, ore and gemstone
// quality - verified against the landed mining pins
inline bool dckMiningReprints()
    { return true; }

// the Table 33 footnote: a 10 on the quality roll rerolled - another 10 means
// a pure vein of metal requiring no smelting, a 1-9 the normal smelting
inline bool dckT33Footnote()
    { return true; }

}   // namespace rules
