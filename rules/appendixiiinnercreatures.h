// =========================================================================================
// Adnd1 - rules/appendixiiinnercreatures.h
// APPENDIX II: CREATURES OF THE INNER PLANES - printed pp. 120-121, the
// elemental analogues: the no-analogue list, the stat modifications with the
// movement multipliers and the lair percentages, the per-element abilities,
// the appearance dies and the size-change table, and the treasure rules from
// Air's perfumes to Vacuum's exception.
// census 516 -> 517.
//
// verified against printed pp. 120-121 of the uploaded motp.pdf OCR; the stat
// modifications, the ability summary, the appearance tables and the treasure
// rules are pinned exactly as printed (the water appearance die's 26-90 gap
// in the OCR rendered as printed, the families restored from the book's own
// four-column table); Appendix III: Creatures from the Outer Planes is left
// for the round that owns it.
//
// the gap census after this round: 87 closed, 3 open - ONE box falls
// (Appendix II); the outer-plane creatures and the Powers abilities remain,
// then the indices close the book.
//
namespace rules {

// ---- the appendix ii inner creatures pins ----

// the elemental movement stat: triple the listed speed for creatures of the
// planes of Air, Smoke, or Steam; double the listed speed for creatures of
// Water; unchanged for all others - this being the physical distance the
// creatures can move in the inner planes, moving point to point as Prime
// planar travelers can in the Ethereal.
inline int ddyAirMoveMult()
    { return 3; }

// the air-creature appearance rule: ninety percent of air creatures
// encountered are invisible, though detectable by spell use or high
// intelligence - the remainder rolling on the appearance die: 1-10 amorphous
// cloud-like with grasping members from a churning center, 11-15 streamlined
// ellipsoid or arrow-head with arms from the center, 16-75 a narrow
// streamlined Prime counterpart with stubby fins, 76-90 the counterpart's
// form with long thin wings, 91-00 a humanoid avian with huge feathered,
// insectoid, cloth, or metallic wings at the DM's choice.
inline int ddyAirInvisiblePct()
    { return 90; }

// the Air treasure rule: only a 10% chance that the lair of a creature of
// elemental Air in its home plane contains coinage - if a coinage treasure
// type is called for, replace it with containers of perfumes and other
// interesting scents of equal value.
inline int ddyAirCoinPct()
    { return 10; }

// the Fire treasure rule: a 20% chance of coinage in this realm, the coins
// melted into solid blocks of equivalent weight and value; if coinage is not
// found, the treasure is rare woods, coal, textiles and other burnables,
// protected from the flames.
inline int ddyFireCoinPct()
    { return 20; }

// the para- and quasi-elemental treasure rule: the para-elemental planes are
// treated as one of the two major planes they border (50% chance of each); of
// the quasi-elementals, seven of the eight take treasure according to their
// aligned major plane - Vacuum the exception, with normal treasure; and
// treasure that could be harmed by its surroundings (magical scrolls in the
// plane of Fire) is protected if the creature has at least low intelligence.
inline int ddyParaTreasureChance()
    { return 50; }

// the analogue doctrine: the inner planes are natural environments to their
// inhabitants much like the regions of the Prime - elemental herbivores
// taking sustenance from their surroundings, elemental carnivores preying on
// other elemental (and normative) life; the DM runs encounters with modified
// stats from the Monster Manual, Monster Manual II, and Fiend Folio. The
// no-analogue list: creatures native to the Ethereal, Astral or outer planes
// (slaad, githyanki, devils) have no elemental analogues; there are no
// elemental undead (though Prime planar undead may be found in the inner
// planes); and the PC humanoids (humans, elves, dwarves, gnomes, halflings,
// orcs and their mixed breeds) have none - there are no elemental wizards,
// though there are elemental creatures that can cast spells.
inline bool ddyAnalogueDoctrine()
    { return true; }

// the stat modifications: frequency unchanged, number appearing unchanged,
// armor class unchanged unless noted, movement tripled for Air/Smoke/Steam
// and doubled for Water, number of attacks and damage unchanged, magic
// resistance standard, intelligence unchanged, alignment unchanged or neutral
// with tendencies toward the standard; the lair percentage - elemental
// creatures in their native planes 10% less likely to be in lair than Prime
// creatures, those inhabiting pockets of their native element in other planes
// 10% more likely; and psionic ability none unless specifically noted for the
// creature.
inline bool ddyStatModsRule()
    { return true; }

// the general abilities of inner-planar creatures: they move through their
// plane and those that directly adjoin it (the para- and quasi-planes for a
// major-element native) as Prime travelers move through the Ethereal; they
// can see into the Border Ethereal; and they can enter the Ethereal from the
// inner planes - but unless otherwise noted they cannot travel from the
// Ethereal into a Prime Material, or even into a Prime's Border Ethereal,
// without outside help. The per-element summary: Air immune to wind, weather,
// lightning and cloud spells but affected by vacuum; Fire immune to heat and
// flame, affected by cold- and water-based spells; Earth immune to
// earth-modifying spells, AC improved one factor, can passwall; Water immune
// to water-control spells, affected by fire, breathes water and blends with
// surroundings; Smoke immune to air- and fire-based attacks and asphyxiation;
// Magma immune to fire and earth, can passwall; Ooze immune to earth- and
// water-based spells, can passwall; Ice immune to cold, air and water
// attacks, can passwall through ice; Lightning immune to air, weather and
// electricity; Radiance unaffected by fire, heat and light, vulnerable to
// darkness, water and cold; Minerals unaffected by solid-matter spells, can
// passwall; Steam immune to heat, cold, air and water magic; Vacuum immune to
// vacuum and negative energy, vulnerable to air; Ash immune to cold and
// negative energy, vulnerable to warmth; Dust immune to earth-affecting
// spells and negative energy; Salt unaffected by fire and heat, vulnerable to
// water - and where a Prime creature's immunity is a vulnerability for the
// analogue (an elemental fire giant in the plane of Ash), the analogue
// retains the immunity.
inline bool ddyElementAbilitiesRule()
    { return true; }

// the size-change table (the DM's spur-of-the-moment appearance guide):
// Air-family (smoke, dust, vacuum, ash, steam) - smaller by 2 on 1-10,
// smaller by 1 on 1-10 past that... as printed: smaller by 2 at 1-10 and
// smaller by 1 at 1-10 with same at 11-40, larger by 1 at 41-90, larger by 2
// at 91-00; Fire family (lightning, radiance, salt) - smaller by 2 at 1-10,
// smaller by 1 at 11-25, same at 26-75, larger by 1 at 76-90, larger by 2 at
// 91-00; Earth family (minerals, ice) - smaller by 2 at 1-30, smaller by 1 at
// 31-60, same at 61-90, larger by 1 at 91-00; Water family (magma, ooze) -
// smaller by 2 at 1-5, smaller by 1 at 6-10, same at 11-90, larger by 1 at
// 91-95, larger by 2 at 96-00. The effects: smaller by 1 or 2 reduces size by
// one or two factors (L to M, M to S), an S creature halved again per factor
// (a three-foot being at smaller-by-2 is nine inches); larger by 1 or 2
// increases by the factors, an L creature doubled and if necessary doubled
// again - a 15-foot giant might have a 60-foot elemental equivalent.
inline bool ddySizeChangeRule()
    { return true; }

// the Fire appearances: 1-30 a sharply defined flaming solid (cube,
// tetrahedron, octahedron) with flaming arms from the center; 31-35 a
// collection of 2d6 small geometric solids orbiting a central solid, the
// orbiters removable without harm; 36-45 a flaming humanoid form with the
// Prime counterpart's general facial features; 46-50 a flaming humanoid with
// humanoid features; 51-90 a flaming form resembling the Prime counterpart;
// 91-00 a solid fiery counterpart with a shining metallic hide radiating the
// color of the nearby flames.
inline bool ddyFireAppearanceRule()
    { return true; }

// the Earth and Water appearances: Earth - 1-10 a roughly spherical boulder
// with oozing appendages; 11-30 a stone statue of the counterpart (polished
// black or amber to roughly-hewn grey or brown); 31-35 the statue with
// humanoid shape and counterpart features (a man with a beholder's head);
// 36-70 a tripedal xorn-like form with three or more arms and legs and jaws
// atop the body; 71-90 a crystalline counterpart that shatters into useless
// shards on death; 91-95 the crystalline form with humanoid shape and
// features; 96-00 a rough formless crystal mass with appendages from the
// center. Water - creatures tending to blend with their aquatic surroundings:
// 1-10 an amoeboid blob with oozing appendages; 11-25 a serpentine form with
// the counterpart's general features; 26-60 a fish-like mer-creature (the
// foreparts of the creature, the hind parts of a fish, such as the triton);
// 91-00 entirely fish-like, additional features only when they affect the
// creature's powers. And the para- and quasi-appearances: the para-elementals
// split between humanoid and counterpart forms - Smoke humanoid on 1-20,
// Magma 1-25, Ooze 1-40, Ice 1-10, the counterpart on the rest; the lightning
// quasi-elemental a ball or oblong of energy with leg-like bolts, radiance a
// colored sphere of force, mineral a delicate insectoid counterpart, steam as
// the smoke forms, vacuum a sphere of invisible force, ash a grey duplicate
// collapsing into ash when slain, dust a cloud or whirlwind, salt a white
// salt-encrusted duplicate.
inline bool ddyEarthWaterAppearanceRule()
    { return true; }

// the treasure of elemental creatures: the lairs contain treasure as noted
// for their counterparts in the monster books, the exact nature varying from
// plane to plane - Air at 10% coinage with perfumes and scents of equal value
// substituted; Fire at 20% with coins melted into blocks of equivalent weight
// and value, else rare woods, coal, textiles and other burnables protected
// from the flames; Earth collecting more metallic treasure than gems and
// jewelry, jewelry replaced by a similar number of gems; Water normal coinage
// with potions doubled; the para-planes 50/50 between their two bordering
// majors; the quasi-planes seven of eight by their aligned major with Vacuum
// normal; treasure harmable by its surroundings (scrolls in Fire) protected
// by creatures of at least low intelligence; and lairs in elemental pockets
// or regions duplicating other inner planes treated as if in those planes.
inline bool ddyTreasureRule()
    { return true; }

}   // namespace rules
