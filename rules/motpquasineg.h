// =========================================================================================
// Adnd1 - rules/motpquasineg.h
// THE MotP NEGATIVE QUASI-PLANES - printed pp. 57-59, the four in one round:
// Vacuum, Ash, Dust and Salt - the increasing-absence doctrine, the per-plane
// survival ladder, the black wall, the level-drain natives, and the Foreword
// doctrines riding the round that closes the inner half.
// census 498 -> 499.
//
// verified against printed pp. 57-59 of the uploaded motp.pdf OCR (and p. 3
// for the Foreword); the quasi-planes pin by mapping onto the major-plane
// frame (Vacuum as Air, Ash as Fire, Dust as Earth, Salt as Water) with the
// MotP's own absence dangers carried explicitly; the encounter frequency
// AMENDED against the source (1 in 10 per 12 hours, not the report's
// 1-in-20).
//
// the gap census after this round: 42 closed, 48 open - three boxes fall (the
// quasi-group, the encounter frequency, the Foreword); the inner half of the
// book closes here, and the Astral chapter (pp. 60-72) opens the second half
// next.
//
namespace rules {

// ---- the negative quasi-planes pins ----

// the four negative quasi-planes between the Negative Material and the
// majors: Vacuum (Air), Ash (Fire), Dust (Earth), Salt (Water) - the
// increasing-absence doctrine: what is missing in the Positive is present
// here, thinning toward the Negative itself.
inline int dddQuasiPlaneCount()
    { return 4; }

// the Vacuum survival: no breathable element exists there, airy element and
// the like are useless, only holding one's breath sustains life; elementals
// and airy creatures lose 1 HD per round.
inline int dddVacuumHdLossPerRound()
    { return 1; }

// the Vacuum vision: 1,000 yards, or double the normal infravision range -
// the plane is dark and empty but transparent.
inline int dddVacuumVisionYards()
    { return 1000; }

// the Ash survival: warmth depletion, a bone-chilling cold; fire creatures
// lose 1 HD or level per round, warm creatures take 2d6 per round halved by
// cold protection; vision 30 yards.
inline int dddAshVisionYards()
    { return 30; }

// the Dust and Salt vision: 10d3 yards of grey half-light - the Dust
// blackness of crumbling matter, the Salt haze of the brine residue.
inline int dddQuasiVisionDieSides()
    { return 3; }

// the 2d6-per-round depletion: Ash warmth-loss in warm creatures (halved by
// cold protection), Dust crumbling in solids (death at 0 hp; gaseous form
// protects; Earth, Ooze and Magma elementals lose 1 HD per round), Salt
// dehydration in non-water creatures.
inline int dddDepletionDamageDieSides()
    { return 6; }

// the Salt rule: water elementals - including Ice, Steam and Ooze but NOT
// Magma - lose 1 HD or level per TURN (not per round); salt is the residue of
// evaporation, and the natives thirst for water.
inline int dddSaltElementalTurnLoss()
    { return 1; }

// the Negative intrusion: a black wall of pure Negative Material advancing
// 3d6 inches per round for 2d10 turns; a traveler caught within loses sight
// of the border after 1d4 rounds - full Negative immersion effects.
inline int dddBlackWallAdvanceDieSides()
    { return 6; }

// the encounter check: 1 in 10 per 12 hours (AMENDED against the source - the
// gap report said 1-in-20, the printed text says 1 in 10); roll 1-20 Negative
// Energy Phenomenon, 21-00 creature; there are NO elemental pockets in the
// negative quasi-planes.
inline int dddEncounterDenom()
    { return 10; }

// 1 in 10 creatures encountered are natives of the quasi-plane, and every
// native drains one life level per touch regardless of form.
inline bool dddNativeLevelDrain()
    { return true; }

// the Ash natives: cold grey forms; bring anything warm (even
// room-temperature) within 20 feet and each must save vs. poison - flee the
// area or explode for 1d4 per hit die; their touch drains 1d6 of body heat;
// invisible-force Vacuum natives hibernate in pockets of air.
inline bool dddAshNativeRule()
    { return true; }

// the Dust natives: 50% chance to split into two smaller forms when struck,
// immune to earth-affecting spells, pass through their plane's matter;
// stepping into their dust inflicts 2d6 per round.
inline bool dddDustNativeRule()
    { return true; }

// the Salt natives: water shatters them into shards; they attack in a 30-foot
// radius at their hit-die level, each shard dealing 1d4 damage.
inline bool dddSaltNativeRule()
    { return true; }

// the magic decay: Vacuum dissipates cloud-type magic the same round it is
// cast; Ash extinguishes long-term flames in 1 round; Dust crumbles objects
// in 1d4 rounds; Salt absorbs watery magic and free water in 1d4 rounds.
inline bool dddMagicDecayRule()
    { return true; }

// the negative quasi-features: slow, plodding natives; guides always cost at
// least double (mists and perfumes for Steam's cousins, burned valuables for
// Ash, ground powders for Dust; Vacuum guides unknown); no archoments rule
// these planes; the elemental-roped citadels reach here from the tower ring.
inline bool dddGuidePriceDoubled()
    { return true; }

// the Foreword (p. 3) riding this round: the Fibber McGee closet frame - the
// planes as the stuff crammed into a closet; what-has-been-written-is-true is
// the ruling doctrine; the sense-of-wonder caveat; and the made-it-up
// admission (Jeff Grubb).
inline bool dddForewordDoctrine()
    { return true; }

}   // namespace rules
