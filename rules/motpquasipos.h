// =========================================================================================
// Adnd1 - rules/motpquasipos.h
// THE MotP POSITIVE QUASI-PLANES - printed pp. 55-57, the four in one round:
// Lightning, Radiance, Minerals and Steam - the survival ladder, the energy
// intrusions, the natives, the towers, and the Minerals fossilization with
// the gem economy.
// census 497 -> 498.
//
// verified against printed pp. 55-57 of the uploaded motp.pdf OCR; the
// quasi-planes pin by mapping onto the major-plane frame (Radiance as Fire,
// Minerals as Earth, Steam as Water, Lightning as Air) with the MotP's own
// particular dangers carried explicitly.
//
// the gap census after this round: 39 closed, 51 open - three boxes fall (the
// quasi-group, the encounter table, the Minerals petrification rule); the
// negative quasi-group closes the inner half next.
//
namespace rules {

// ---- the positive quasi-planes pins ----

// the four positive quasi-planes between the Positive Material and the
// majors: Lightning (Air), Radiance (Fire), Minerals (Earth), Steam (Water) -
// the most changing and dynamic of the inner planes, their Positive borders
// ebbing and flowing like tides.
inline int ddcQuasiPlaneCount()
    { return 4; }

// the lightning strike chances per round: 5% size S, 10% size M, 20% size L;
// a bolt deals 1d8 of d10s (1-80) halved by a save vs. spell; protection from
// lightning gives safety.
inline int ddcLightningStrikePctL()
    { return 20; }

// the elemental thunder: normal speech impossible, a turn unprotected deafens
// for 2d4x10 (264) turns, longer stays risk permanent deafness (Con check;
// heal cures) - wax or putty ear plugs negate; the harm stops at the Border
// Ethereal but the noise still drowns speech there.
inline int ddcLightningDeafTurns()
    { return 264; }

// the Minerals movement damage: each round of movement deals 1d4 plus the
// traveler's AC; Earth/Minerals natives and AC below -4 are unharmed; Dex
// bonuses do not count, magic armor is two planes reduced.
inline int ddcMineralsMoveDamageDie()
    { return 4; }

// travelers in the positive quasi-planes have a 1-in-10 chance of an
// encounter (the lightning bolts and crystal cuts excluded); roll: 1-20
// positive energy phenomenon, 21-30 elemental pocket, 31-00 creature
// encounter.
inline int ddcQuasiEncounterDenom()
    { return 10; }

// the positive energy intrusion: a wall of advancing white brilliance moving
// 3d6 inches per round for 2d10 turns - full Positive Material immersion
// effects, the border lost after 1d4 rounds in the wall.
inline int ddcWallAdvanceDieSides()
    { return 6; }

// the only pockets in a quasi-plane are of its related major plane (entering
// = entering that plane, 30% native lair chance); pockets survive energy
// walls by conversion - carried at the front, left behind at the retreat.
inline int ddcPocketConvertPct()
    { return 30; }

// the Minerals gem economy: only one in 100 stones survives return to a
// gravity plane; survivors worth 1,000 gp base; removing more than ~100
// stones alarms the natives - the guides abandon the greedy halfway through
// the plane.
inline int ddcGemSurviveDenom()
    { return 100; }

// the Minerals fossilization: non-inner natives save vs. spell each true turn
// (inner non-natives once per subjective day); failure petrifies instantly -
// 80% stone (stone to flesh reverses), 20% crystal/gold-veined granite (only
// a full wish); petrification protection does not help; brought to gravity,
// 99% crumble to dust.
inline int ddcPetrifyStonePct()
    { return 80; }

// the Radiance survival: Fire's burning and breathing dangers, plus
// unprotected eyes save vs. death or be permanently blinded (infravision -2
// to the save, both visions -4); darkness spells or smoked lenses (fragile,
// 1-in-4 knocked off when hit) permit sight; Border viewers unharmed but
// formless to the eye.
inline bool ddcRadianceBlindRule()
    { return true; }

// the Steam survival: not hot but muggy - movement slowed by water gathering
// in the lungs (water breathing negates), vision limited to 10d6 yards of
// thick fog; the least hostile positive quasi-plane.
inline bool ddcSteamMuggyRule()
    { return true; }

// the native immunities: Lightning natives immune to electrical attacks,
// resisting weather and wind as Air creatures; Radiance natives immune to
// fire, heat and light attacks, vulnerable to water as fire elementals,
// driven off by darkness; Minerals natives pass through earth, immune to
// solid-affecting spells; Steam natives unaffected by air, water and heat
// magic.
inline bool ddcLightningNativeImmunity()
    { return true; }

// quasi-elemental guides: hyperactive and erratic, the first task is slowing
// them to bargain; the same bribes as their elemental cousins but the price
// is ALWAYS at least doubled; no conception of haggling - refuse the terms
// and they leave (or attack if evil and stronger).
inline bool ddcGuidePriceDoubled()
    { return true; }

// no known archoments or true rulers in the positive quasi-planes - the
// inhabitants too frantically busy for hierarchy; the ring of great towers
// (blue flame, lead, solidified clouds, ice) extends into the Positive on
// thin peninsulas, origin unknown, home to exiled Powers and researchers.
inline bool ddcNoQuasiArchoment()
    { return true; }

}   // namespace rules
