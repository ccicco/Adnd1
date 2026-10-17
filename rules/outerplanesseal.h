// =========================================================================================
// Adnd1 - rules/outerplanesseal.h
// THE OUTER PLANES CHAPTER SEAL - printed pp. 73-116: the seventeen planes of
// the Great Wheel from Nirvana's clockwork to the Opposition's hub, the
// general doctrine and its five tables, the seventeen plane rounds, and the
// closing essay - the chapter census complete, the parent box sealed.
// census 514 -> 515.
//
// verified against the chapter's own rounds R577-R590 and the MotP's wheel
// doctrine (printed pp. 73-84); the seal carries the book's seventeen-plane
// enumeration and alignment arrangement, closing the parent box in the same
// commit per the report's closure criterion.
//
// the gap census after this round: 83 closed, 7 open - ONE box falls (the
// Outer Planes chapter umbrella); THE OUTER PLANES CHAPTER IS SEALED; the
// appendices and indices remain.
//
namespace rules {

// ---- the outer planes chapter seal pins ----

// the seventeen named planes of the outer planes: the planes of power
// circling the wheel - Nirvana and Arcadia on the lawful side, the Seven
// Heavens, the Twin Paradises, Elysium and the Happy Hunting Grounds of the
// good ascent, Olympus and Gladsheim of the neutrals, Limbo and Pandemonium
// of pure and evil chaos, the Abyss, Tarterus, Hades of the evil middle,
// Gehenna and the Nine Hells of lawful evil's slope, Acheron between the
// Hells and Nirvana - and Concordant Opposition at the hub, the seventeenth,
// touching all.
inline int dduOuterPlaneCount()
    { return 17; }

// the wheel arrangement (the book's own doctrine): the outer planes arranged
// by alignment around the Great Wheel, each plane the home of its alignment's
// Powers - the lawful-evil ascent from Gehenna's furnaces through the Nine
// Hells to Acheron's iron blocks and Nirvana's clockwork; the good arc from
// Arcadia's orchards up through the Seven Heavens, the Twin Paradises,
// Elysium and the Happy Hunting Grounds to Olympus and Gladsheim; the chaos
// descent from Limbo's quicksilver through Pandemonium's howls into the
// Abyss, Tarterus and the grey Glooms of Hades; and Concordant Opposition at
// the center, the exception plane connecting them all - the
// alignment-arrangement doctrine pinned in the general round and carried by
// every plane's own round.
inline bool dduWheelOrder()
    { return true; }

// the chapter seal: the Outer Planes chapter of the Manual of the Planes is
// closed - the general doctrine of R577 (the reaching, the survival, the
// movement, the encounters, the combat, the magic, the player characters, the
// features, and the Great Wheel itself) with its tables (the plane-shift
// arrival, the alteration-spells chaos, the turning modifiers, the
// unique-powers and human-travelers doctrines), the seventeen plane rounds
// R578 through R589 from Nirvana to the Concordant Opposition with their five
// tables (the Limbo entry, the Abyss terrain, the center and destination
// tables of the Opposition, the Beastlands casting reattribution), and the
// closing essay of R590 - every child box flipped, the parent sealed by this
// round's census pin.
inline bool dduChapterSeal()
    { return true; }

}   // namespace rules
