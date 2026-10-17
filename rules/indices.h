// =========================================================================================
// Adnd1 - rules/indices.h
// INDICES - printed pp. 127-128, the closing pair: the 132-entry subject
// index of the wheel and the 89-spell index of unusual notes and type
// exceptions, from the airy variants to plane shift, the wish, and the
// protections of the energy planes.
// census 519 -> 520.
//
// verified against printed pp. 127-128 of the uploaded motp.pdf OCR (OCR
// pages 128-129); the entry counts are pinned from the OCR text as counted,
// with the obvious slips restored (Cerberus, efreet, Mnemosyne, Sustarre,
// stone tell, necromancies); this is the LAST box of the MotP gap report -
// the census closes at 90/0.
//
// the gap census after this round: 90 closed, 0 open - the final box falls
// (Indices); the Manual of the Planes gap report is CLOSED, every box of the
// 90-box census accounted for.
//
namespace rules {

// ---- the Indices closing pins ----

// the two closing indices: the subject index on p. 127 and the spell index on
// p. 128, the last pages of the book before the covers.
inline int decIndexPages()
    { return 2; }

// the subject index entry count: 132 entries as printed on p. 127, from
// abjurations and alterations through the Yggdrasil - the planes, rivers,
// landmarks, creatures and mechanics of the whole book in one column.
inline int decSubjectIndexEntries()
    { return 132; }

// the spell index entry count: 89 spells as printed on p. 128, from aerial
// servant through wish - each with the pages of its unusual or important
// notes.
inline int decSpellIndexEntries()
    { return 89; }

// the airy series of the spell index: airy earth 41, airy element 41, 58,
// airy fire 37, airy smoke 51 and airy water 23, 47 - the elemental
// survivability quintet, one entry apiece.
inline int decAiryVariants()
    { return 5; }

// the plane shift references: pp. 11, 22, 61, 74 and 117 - the spell's own
// page in the Ethereal chapter, the inner-plane statement, the Astral, the
// outer planes, and the Prime appendix.
inline int decPlaneShiftRefs()
    { return 5; }

// the subject index roster: the five planes families each with their opening
// pages (Astral 5, 60-72; Ethereal 5-21; inner 5, 22-59; outer 5, 73-116;
// Prime 5, 117-119); the rivers - Oceanus 84, 90, the Styx 83, 100-101, 103,
// 105, and Mnemosyne 101 (the OCR Manale restored); Mount Olympus 72, 92, 105
// and the Yggdrasil 72, 95, 105; Bahamut and the archons 88, Charon and the
// charonadaemons 83, the dao and djian, the efreet (the OCR Efreel restored)
// and marids, the githyanki silver swords 61, 72 and the githzerai 98-99, the
// modrons 85, Nidhogg 106, the norns 116, Cerberus 106 (the OCR Corberus
// restored), the trillochs 54, the xag-ya and xeg-yi 54, the einheriar 122;
// the para-elementals and quasi-elementals; the mechanics - color pools 80,
// 82-84, conduits 66, 74, the ether cyclone 17, the psychic wind 64, 67, the
// silver cord 60-61, wormholes 66, fixed portals 72, spell-crystals 83,
// subjective and true time 5-6, the power compass 75, and the three borders -
// intercalm, interlayer, interplanar - all at 76.
inline bool decSubjectIndex()
    { return true; }

// the spell index roster: astral projection across 60, 62, 63, 66, 67, 71, 72
// and 75; plane shift 11, 22, 61, 74, 117; teleport without error 75; the
// wish 79, alter reality 79 and limited wish 79; negative plane protection 54
// and positive plane protection 54; the two transform-element spells at 28;
// contact other plane 35, 45, 49, 80; the chariot of Sustarre 29 (the real
// name restored from the OCR Susterre); stone tell 28 (restored from the OCR
// stone tail); the necromancies at 10, 19, 29, 70, 81 (restored from the OCR
// neoromantics); airy earth, element, fire, smoke and water; and the famous
// exceptions - fireball 25, 49, 59 across the inner planes, cloudkill 25,
// magic jar 7, 80, dispel magic 11, 63, 68, 78, shadow walk 21 into the
// Demiplane of Shadow, and Mordenkainen's faithful hound 12.
inline bool decSpellIndexRoster()
    { return true; }

// the spell index preamble: this index does not list every place a spell
// appears in the Manual of the Planes - given are the pages with unusual or
// important notes on specific spells, and the spells that are exceptions to
// the general rules governing their spell types.
inline bool decSpellIndexNote()
    { return true; }

}   // namespace rules
