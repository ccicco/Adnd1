// =========================================================================================
// Adnd1 - rules/concordantopposition.h
// CONCORDANT OPPOSITION - printed pp. 114-116, the odd plane at the wheel's
// hub: the ever-changing homeland face, the minimum-damage rule, the
// unclimbable center with its 100-mile spell ladder, the white disks of the
// 1,000-mile ring, the chaotic-destination roll, and the Powers from Dagda's
// Tir na Og to the Modrons' well of souls.
// census 512 -> 513.
//
// verified against printed pp. 114-116 of the uploaded motp.pdf OCR; the
// center table and the chaotic-destination table (the report's last two MotP
// table boxes) are pinned in full, along with the minimum-damage rule, the
// disk ring, and the Powers census exactly as printed (the Modrons restored
// against the OCR's Norris, Eadro of the locathah); the closing essay Beyond
// the outer planes is left for the round that owns it.
//
// the gap census after this round: 81 closed, 9 open - THREE boxes fall (the
// Concordant Opposition, the center table, the chaotic-destination table);
// the plane-by-plane census of the Manual of the Planes is CLOSED, with only
// the closing essay beyond the outer planes left to the MotP chapter.
//
namespace rules {

// ---- the concordant opposition pins ----

// the center table's spell ladder: each 100 miles inward from the ring
// neutralizes one spell level and its spell-like abilities, from the 9th at
// 1,000 miles down through the 1st at 200; spell-like abilities that mimic
// spells of different levels are always treated at the lesser level, and the
// lost levels apply to all casters - clerics, whose spells top at 7th, do not
// begin losing abilities until 800 miles from the center.
inline int ddsCenterSpellStepMiles()
    { return 100; }

// the center's absolute floor: at 100 miles chemical reactions - burning,
// dissolving, and the like - no longer work, and neither man nor god can come
// closer to the center; the center itself appears variously as a great tower,
// column, mountain, waterspout, tornado, or tree, and regardless of form
// cannot be climbed, entered, or damaged by any means, godly or not.
inline int ddsCenterChemicalFloorMiles()
    { return 100; }

// the chaotic-destination table (the report's box): chaotic travelers -
// chaotic good, chaotic evil, or chaotic neutral - or a chaotic-majority
// group sometimes end up in the wrong plane: 1-80 the intended destination.
inline int ddsChaosDestIntendedPct()
    { return 80; }

// the chaotic-destination table, second band: 81-90 one plane away clockwise
// or counterclockwise on the wheel.
inline int ddsChaosDestAdjacentPct()
    { return 90; }

// the chaotic-destination table, final band: 91-00 the opposite location on
// the great wheel (that's odd - do you remember the smell of brimstone the
// last time we were in Olympus?).
inline int ddsChaosDestOppositePct()
    { return 100; }

// the ring of white disks: the portals to every other outer plane exist in a
// great ring at the 1,000-mile mark from the center, always appearing as
// simple white disks laid into the ground regardless of their surroundings,
// in sizes up to a whole adventuring party; color pools land more than 600
// miles out.
inline int ddsPortalRingMiles()
    { return 1000; }

// the Concordant Opposition doctrine: the exception to many of the rules and
// assumptions concerning the outer planes - it does not coincide neatly with
// the great wheel (if it has an alignment, true neutral), yet creatures from
// every outer plane and the Astral are found here, for it connects with all
// of them; whether it is truly an outer plane or an entirely new form of
// plane or demi-plane is unrevealed. It mixes the properties of all the
// planes it touches: limitless yet with a definite center, changing from
// moment to moment like chaos yet always keeping the same sense of order and
// placement, good and evil coexisting in different forms with their ability
// to affect each other reduced. It has either a single layer or a multitude
// of similar layers with similar inhabitants, presenting a different face
// each visit - a gothic city, an aquatic wonderland, a great forest of hollow
// trees - yet the familiar traveler still finds his way (the same special
// locations, however varied); in general the first visit always resembles a
// much-larger version of the traveler's homeland (the farm boy sees acres of
// farms, his scribe companion a massive library, their modern guide more
// interlocking wheels than Nirvana at its busiest). Powers residing here can
// manipulate the appearance to a slight degree, but cannot fully control what
// it shows to others.
inline bool ddsOppositionDoctrine()
    { return true; }

// the minimum-damage neutralization: weapons and spells that hurt (or heal) a
// random amount of damage inflict the minimum possible - a short sword 1
// point, a two-handed broadsword 3, cure light wounds restores 1, cause light
// wounds inflicts 1, and a heal spell returns all but 1 point; poisons and
// other damage not measured by hit points are unaffected, as are strength and
// magical-weapon bonuses - true throughout the plane.
inline bool ddsMinDamageRule()
    { return true; }

// the center neutralization ladder (the table's specials): at 700 miles
// illusion and phantasm spells fail as if all viewers wore gems of seeing
// (without revealing the plane's true nature) and life-draining abilities
// die; at 600 astral viewing portals and artificial poisons die; at 500
// natural internal poisons die and conduits from other planes cannot reach
// beyond; at 400 no conjuration or summoning functions and the powers of
// demi-gods die; at 300 the powers of lesser gods die; at 200 the 1st level
// is gone and the powers of greater gods die; and at 100 chemical reactions
// stop and none - man or god - may come closer. Because powers are lost near
// the center yet regained on moving away, the central region serves as
// meeting place, trade-market, and common ground for the Powers: two hundred
// miles out, Greater Powers of differing alignment confer without fear that
// either side can turn the situation to its advantage.
inline bool ddsCenterRule()
    { return true; }

// the white-disk travel rule: all disks send travelers to any of the outer
// planes merely by concentration, and in groups majority rules - a party of
// three paladins and four imps will likely end up wherever the imps decide to
// go; chaotic alignments sometimes end up in the wrong plane, the chaotic
// traveler or chaotic-majority group rolling on the destination table.
inline bool ddsDiskRule()
    { return true; }

// the inhabitants: Concordant Opposition - sometimes called Goddard or the
// Friendly Opposition - has no native races, but a large number of
// extraplanar beings engage in trading, meetings, and the service of higher
// powers; all intelligent creatures of the outer planes are found here at
// their home-plane frequencies, the plane overrun by demons, devils, warriors
// of Anu, spirit legions seeking weapons, einherjar, planetars, devas, and
// slaadi. The Powers tend to reject the standard aligned-wheel concept: true
// neutrals, Powers removed from or having left their pantheons, and those
// above such petty concerns as alignment - unable to fully control what
// travelers see and hear, they color it to their own sensibilities (the Celts
// toward woodlands, Thoth toward places of learning). Most make their
// permanent domains outside the ring of white disks where their powers
// function as fully as the plane permits, and a Power challenged here seeks
// the areas nearer the center if overmatched, or takes the attacker to
// another plane where the god's full power may make the battle easier.
inline bool ddsOppositionInhabitants()
    { return true; }

// the Powers of the Opposition: Dagda the Dagda King and most of the Celtic
// mythos rule a large swath radiating from the circle of white disks outward
// like a wheel - with Brigit, Diancocht, Dunatis, Lugh, Morrigan, Nuada, and
// Silvanus - the whole realm called Tir na Og, the Land of Youth, and Dagda's
// own domain Mag Mell, the Field of Happiness; Manannan mac Lir, the Celtic
// sea god, in the great ocean Tir fo Thuiran, the Land under the Waves;
// Goibhniu the Celtic blacksmith of the gods, said to craft weapons that
// function normally within the Land of Youth though the power fails outside
// it; Ogma, the Celtic god of knowledge, keeping a small domain closer to the
// center with a prison for extraplanar trouble-makers (usually devils and
// demons) where their powers are negated and they can do no mischief. Of the
// Egyptians, Thoth the god of knowledge and Bes the luck Power keep large
// expanses beyond the circle and lesser estates within, their portfolios
// unoverlapping, with little to do with each other save in times of need
// (usually Bes's). Untamo of the Finns in the Sleeping Lands, the lesser god
// of dreams rarely venturing beyond his borders - adjacent, surprisingly, to
// the noisy clattering realm of Tvashtri the Indian demi-god of artifice and
// science, its pipes, columns, and recently discovered inventions guarded
// jealously, for he believes discovery is the most important factor in
// creation, not gifts from the gods. The Modrons are said to have their well
// of souls at the very edge of the center, identifying it as an unattainable
// part of the Yggdrasil though it behaves unlike any other part of the World
// Ash conduit - here men and Powers alike seek their fortunes from the fates.
// Yen-Wang-Yeh across from Untamo, sorting the spirits of the Chinese mythos
// to their final destinations so they neither tarry on the Prime nor rest in
// the wrong place - a faithful bureaucratic servant answering to Shang-Ti who
// leaves one week a year to present his books to the August Personage of Jade
// in Nirvana, and it is during that week, with his assistant controlling the
// dead, that many spirits wander the earth and are misplaced. And the
// nonhuman escapes from factional politics: Semuanya of the lizard men in a
// great swampy region outside the circle, bordering the great sea of Eadro of
// the locathah and mermen; Sheela Peryroyal of the halflings in a rich
// orchard and farm nearby; Dumathoin of the dwarves in a large underground
// realm extending to very near the center; and Vergadain the dwarven god of
// luck, suspiciously similar to Bes in appearance and portfolio (luck and
// wealth), maintaining a separate household - both deny being one Power, and
// the few times they have been seen in the same plane prove nothing with
// Powers of this caliber.
inline bool ddsOppositionPowers()
    { return true; }

}   // namespace rules
