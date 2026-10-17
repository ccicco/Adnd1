// =========================================================================================
// Adnd1 - rules/appendixiprimes.h
// APPENDIX I: THE PRIME MATERIAL PLANES - printed pp. 117-119, the Alternate
// Primes doctrine: the Polyverse and its three factors, the 1d10-and-1d4
// physical roll, the magical and temporal ladders, the survival and class
// rules, and the encounter adaptation - the whole appendix in one round.
// census 515 -> 516.
//
// verified against printed pp. 117-119 of the uploaded motp.pdf OCR; the
// three factor ladders are pinned rung by rung exactly as printed (the sign
// roll restored to the printed 1d4 odd-negative/even-positive against the OCR
// slip, the well of many worlds restored, and the -6-save being the printed
// pooka); Appendix II: Creatures of the Inner Planes is left for the round
// that owns it.
//
// the gap census after this round: 86 closed, 4 open - THREE boxes fall
// (Appendix I, the physical-factor table, the encounter rules); the
// appendices II through IV and the indices remain, and the arc nears its
// close.
//
namespace rules {

// ---- the appendix i primes pins ----

// the Prime physical-factor table (the report's box): the factor is chosen by
// the DM or rolled randomly - 1d10 for the value of the factor, with the
// printed ladder from +10 (sentience impossible, all matter reacting
// explosively) through +5 (bipedals over 10 feet unlikely, firearms
// combustion possible), +3, +1, 0 (the standard: language, animation of
// inanimates, no size limits on flight or intelligence), -1 (flight by
// thought, flammables inert), -3 (giant white rabbits), -5 (local gravity,
// fire without fuel), -7 (aware chairs and trees, humanoid form no longer the
// norm), to -10 (the entire plane aware, movement by thought, the elements in
// their pure states, further shifts sending the component parts home).
inline int ddxPfValueDie()
    { return 10; }

// the sign roll: 1d4 for whether the physical factor is negative or positive
// - an odd roll negative, an even roll positive; positive factors mean the
// laws of science hold a firmer grip than home (chemical reactions behave,
// dragons cannot lift, giants cannot stand), negative factors a lower level
// of reality (talking animals, self-moving objects, wingless flight,
// subjective chemistry and gravity).
inline int ddxPfSignDie()
    { return 4; }

// the physical survival range: a Prime native is comfortable in alternate
// Primes within a factor of 5 in either direction on the physical chart -
// beyond that the world's alien nature is insufficient to maintain the
// character's life (though beings retain abilities allowed by their home
// plane's factor even in planes that forbid them: a giant white rabbit
// survives a +3 plane).
inline int ddxPfComfortRange()
    { return 5; }

// the class ranges: druids use their druidical special abilities in planes
// whose physical factors are within 2 of home, and rangers retain tracking
// within the same 2 - while barbarians retain their skills only within 1;
// fighters, cavaliers, monks and thieves function normally.
inline int ddxDruidPhysRange()
    { return 2; }

// the barbarian range: barbarians retain their barbarian skills only in
// planes whose physical factors are within 1 of that of their home plane -
// the most homesick of the classes.
inline int ddxBarbarianPhysRange()
    { return 1; }

// the cleric deity rule: the inner, Astral, and outer planes are the same for
// all alternate Primes, so a cleric whose deity is in an accessible plane
// regains spells normally - but a cleric whose deity resides in another Prime
// Material or Ethereal plane can regain only 1st- and 2nd-level spells;
// undead are turned normally everywhere.
inline int ddxClericLowSpellCap()
    { return 2; }

// the Primes doctrine: the Prime Material planes are the universes most
// familiar to players - almost all campaigns begin on one; each plane's
// inhabitants call theirs the Prime and all others alternate Primes, though
// in reality all are similar and equally valid, and the majority of the
// game's rules are designed for them. Reaching them: travelers usually begin
// in their own Prime; each Prime is bordered on all sides by its own Ethereal
// plane (so the Ethereal cannot carry you between Primes), but the various
// Ethereals contact the same single inner planes - Prime to Ethereal to inner
// plane to alternate Ethereal to alternate Prime - while the Astral reaches
// all Primes directly; openings to the Astral can be created at any Prime
// location; no spell takes the caster directly Prime-to-Prime, though some
// reach eventually via other planes; the plane shift spell moves targets to
// another Prime with the precise length and material of the required tuning
// fork known (experimentation often hazardous to the experimenter's life);
// magical items such as the amulet of the planes or the well of many worlds
// open ducts between Primes; free-standing gates of unknown origin, often
// guarded by powerful beings and hidden from common knowledge; and the
// psionic probability travel renders the traveler physically immaterial for
// travel to other Primes, entering Ethereal planes to become physically
// ethereal.
inline bool ddxPrimesDoctrine()
    { return true; }

// the Polyverse and the three factors: conceivably an infinite number of
// Prime Material universes compose an all-encompassing Polyverse whose
// discovery and cataloguing would defy even the Powers; the differences
// between alternates are measured by three factors - the physical factor (the
// level of scientific reality), the magical factor (the degree of magical
// permeation), and the temporal factor (the closeness of the link to the
// traveler's Prime); every plane's inhabitants consider themselves the
// center, and the traveler's home Prime is rated (0,0,0), all others relative
// to it - a standard AD&D campaign (0,0,0).
inline bool ddxPolyverseRule()
    { return true; }

// the magical factor ladder: the degree to which the plane is permeated by
// magical energy - the higher the factor the more of the population can cast
// and the stronger and longer the abilities; the rungs as printed: +10
// universal casting among all sentient races, the planes soon dissolving into
// demi-planes ruled by individuals; +6 all spell effects visible, 11th-level
// magic possible, no saving throws against magic; +5 10th-level spells,
// unlimited casts per day; +3 9th-level spells, no spell books or prayers
// needed, all sentients cast; +1 most sentients cast; 0 the standard with
// training, study and prayer; -1 8th-level cap, rare casters of one or two
// races; -3 6th-level cap, clerics only 1st and 2nd; -5 no Power-derived
// spells, 3rd-level cap; -7 no spells at all, creativity and imagination
// uncommon, songs disappear; -10 no magic, creativity or imagination - beyond
// it sentient life impossible.
inline bool ddxMagicalFactorRule()
    { return true; }

// the temporal factor ladder and the time-travel digression: a high factor
// means the planes diverged widely in the far past (evolution, continents), a
// negative factor a close similarity - perhaps the home Prime's own past or
// future; the rungs: +10 wildly different planetary situation and planar
// connections (differently colored suns, no atmosphere); +6 alien life
// (methane-breathing, not carbon-based) in possibly hostile environment; +5
// Earth-like with alien-but-familiar types, most life missing; +4 Earth-like
// with familiar sentients, continents in different patterns; +1 familiar
// continents and creatures, different society and individuals; 0 similar
// continents, life and society with counterpart individuals whose actions,
// attitudes and alignments vary; -1 up to a week in past or future; -3 up to
// a year; -5 up to a century; -7 up to a millennium; -10 millions of years;
// and the digression: in the AD&D universe one cannot travel into one's own
// past (at least unproven), but a traveler can effectively accomplish it by
// finding an alternate Prime with zeroes for physical and magical factors and
// a low negative temporal factor.
inline bool ddxTemporalFactorRule()
    { return true; }

// the survival doctrine: beings retain the abilities their home plane's
// physical factor allows even in planes that forbid them; but the magical
// factor seriously affects the abilities of beings from very different planes
// - spells and spell-like abilities limited by the plane entered (a
// high-level wizard powerless in a -6 plane), and an innately very magical
// being (the printed pooka) brought into a -6 magical factor plane must save
// vs. death or die of the sudden deprivation; in general physical laws and
// processes proceed similarly in all Primes - time, gravity, the limits of
// vision, bodily requirements - with the same high-risk areas (volcanoes,
// storms, deserts) and no general hostility toward travelers; the most easily
// reached alternates have low factors, and moving between AD&D campaigns
// might mean no physical or magical change and a temporal shift of 3 or 4.
inline bool ddxSurvivalRule()
    { return true; }

// the class rules in alternate Primes: magic-users and illusionists relearn
// spells limited by the current plane's magical factor, and on moving planes
// limited by the lesser of the two factors (home and current); clerics under
// the magical factor with the deity rule (accessible plane - full spells;
// another Prime's or Ethereal deity - only 1st and 2nd) and normal undead
// turning; druids within 2 physical factors; thieves, fighters and cavaliers
// normal; rangers tracking within 2; barbarians within 1; paladins' magical
// abilities limited by the plane's magical factor, the mount retaining its
// sentience; monks normal; and the examples - an alternate campaign under the
// same rules shares the physical factor, varies the magical by 1 or 2 and the
// temporal by at most 5, while a typical 20th-century world rates (5,-4,5),
// the magical rating varying with the campaign's nature.
inline bool ddxClassRule()
    { return true; }

// the encounter and combat rules (the report's box): encounters vary from
// Prime to Prime as these are complete worlds in themselves - adapt the
// standard encounter tables according to the physical, magical and temporal
// conditions of each plane; combat functions normally in most alternate
// Primes, but at higher physical factors the conditions allow unusual weapons
// while other weapons become useless; and magic in alternate Primes is
// limited by the plane's magical factor - all spell casting limited
// regardless of type, abilities that are not restricted usable in full.
inline bool ddxEncounterRule()
    { return true; }

}   // namespace rules
