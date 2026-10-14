// =========================================================================================
// Adnd1 - rules/wsgrapp.h
// The WSG RAPPELLING, R442: the descent prose (no table this round) - by
// securing a rope at the top of a slope or cliff and then winding it around
// his body, a character can descend a non-horizontal surface quite rapidly by
// the process known as rappelling; applying sideways pressure against the
// surface and using the friction of the rope around his body, the climber
// comes down under control at a base speed of 120 feet per round (encumbrance
// and other penalties apply just as for an ascent). To successfully rappel
// the character must make a Climbing Check with a +50% modifier to his
// current Climbing Rating for every round or part of a round spent
// descending; failure on any check means he has lost his grip and hangs
// upside down, spinning while suspended by the rope, until rescued or until
// he makes a successful Dexterity Check (regained bearings, new hold) -
// allowed once per round. Rappelling down a free-hanging rope (no surface to
// brace against) can be done, but the modifier is only +30% instead of +50%;
// a failed check while free-hanging means his Dexterity Checks take a +2
// modifier to the die roll. Census 366 -> 367.
// census 366 -> 367.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 37; the
// user own copy OCR cross-checked against the archive djvu word layer
// (Guide_0037.djvu) - the section reads CLEAN in the djvu, every number (the
// 120 feet per round, the +50% modifier, the +30% free-hanging modifier and
// the +2 Dexterity modifier) matched exactly; no eye-reads were needed.
//
// The climber comes down under control at a base speed of 120 feet per round.
// Each round or part of a round of rappelling takes a Climbing Check at +50%;
// on a free-hanging rope the modifier is only +30%, and a failed check there
// puts a +2 on the Dexterity Checks - allowed once per round - that end the
// upside-down spin.
//
namespace rules {

// ---- the rappelling rules ----

// Penalties to the 120-feet movement rate, for encumbrance and other factors,
// apply just as they do for an ascent.
inline bool wrlEncumbrancePenaltiesApply()
    { return true; }

// Winding the rope around his body and using its friction, the climber comes
// down under control at a base speed of 120 feet per round.
inline int wrlBaseSpeedFtPerRound()
    { return 120; }

// The Climbing Check at +50% is made for every round OR PART of a round spent
// rappelling.
inline bool wrlCheckPerRoundOrPart()
    { return true; }

// To successfully rappel down a slope or cliff, the character must make a
// Climbing Check with a +50% modifier to his current Climbing Rating for
// every round or part of a round spent descending in this fashion.
inline int wrlSlopeCheckModPct()
    { return 50; }

// Failure on any check indicates the character has lost his grip on the rope:
// he hangs upside down, spinning while suspended by the rope, until he is
// rescued or makes a successful Dexterity Check.
inline bool wrlFailureHangsUpsideDown()
    { return true; }

// The recovery Dexterity Checks (regained bearings, a new hold on the rope)
// are allowed once per round.
inline bool wrlDexCheckOncePerRound()
    { return true; }

// The free-hanging variant applies where the character has no surface to
// brace against.
inline bool wrlFreeHangNoSurfaceToBrace()
    { return true; }

// Rappelling down a free-hanging rope, where the character has no surface to
// brace against, can be done, but the modifier to the Climbing Rating is only
// +30% instead of +50%.
inline int wrlFreeHangCheckModPct()
    { return 30; }

// If the character fails a Climbing Check while rappelling down a
// free-hanging rope, his Dexterity Checks are made with a +2 modifier to the
// die roll.
inline int wrlFreeHangDexMod()
    { return 2; }

}   // namespace rules
