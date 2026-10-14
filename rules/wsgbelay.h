// =========================================================================================
// Adnd1 - rules/wsgbelay.h
// The WSG BELAYING, R443: the belay prose (no table this round) - a climbing
// rope is 150 or 200 feet long and half an inch in diameter, with a weight
// limit of 2000 pounds, subject to the weakening and breaking rules; a rope
// can tie a group together so a fall can be arrested, and only a rope-use
// proficient character can knot two ropes at full strength - anyone else
// reduces the held weight by 500 pounds, and two different diameters take the
// smaller limit minus 500. Belaying itself: the belayed character has a rope
// end tied securely around his body, the belayer pays out the rope with just
// a small amount of slack (reversed, pulling in, for an ascent); if the
// climber falls, the belayer halts the fall with a successful Climbing Check
// - failure means the climber falls the full distance, success means no
// farther than the length of the rope. A precarious belayer (handholds and
// footholds only) who halts the fall must make a SECOND check against the
// jolt of the rope going taut - failure drops both; a secure belayer (a
// plateau or wide ledge) needs no second check. A string of pairs can belay
// in sequence - the last character cannot belay, the leader cannot be
// belayed, only one belay at a time, no climbing while belaying - slow but
// safer; a middle faller drags no one below, a failed belayer can be saved by
// the character above belaying him, but nothing can help the first character
// who fell, since only two characters are connected to the same rope. Census
// 367 -> 368.
// census 367 -> 368.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 37; the
// user own copy OCR cross-checked against the archive djvu word layer
// (Guide_0037.djvu, with the paired-belay continuation at the head of
// Guide_0038.djvu) - the section reads CLEAN, every number (the 150/200 feet,
// the half inch, the 2000 pounds, the 500-pound knot penalty, the two checks)
// matched exactly; no eye-reads were needed.
//
// The belayer halts a fall with a successful Climbing Check: failure drops
// the climber the full distance, success bounds the fall by the rope length.
// A precarious belayer who halts the fall makes a second check against the
// jolt - failure drops both; a secure belayer skips it. Only two characters
// share a rope: the first faller cannot be helped, and the climbing rope
// holds 2000 pounds minus 500 for an amateur knot.
//
namespace rules {

// ---- the belaying rules ----

// A climbing rope is 150 or 200 feet long and half an inch in diameter.
inline int wblClimbRopeMinFt()
    { return 150; }

// A climbing rope is 150 or 200 feet long - the 200-foot rope strings the
// five-character roping example.
inline int wblClimbRopeMaxFt()
    { return 200; }

// A climbing rope has a weight limit of 2000 pounds, and is subject to
// weakening or breaking as described for the standard coil.
inline int wblClimbRopeLimitLbs()
    { return 2000; }

// Only a character with proficiency in rope use can make a knot that will
// hold the same amount of weight as the ropes on either side.
inline bool wblProfKnotFullStrength()
    { return true; }

// A knot made by anyone other than a rope-use proficient character reduces
// the weight the rope will hold without weakening or breaking by 500 pounds.
inline int wblKnotPenaltyLbs()
    { return 500; }

// If two ropes of different diameters are tied together, the weight limit of
// the smaller rope (minus 500 pounds, for the knot) applies to the combined
// line.
inline bool wblMixedDiaSmallerMinus500()
    { return true; }

// The character to be belayed must have one end of a rope tied securely
// around his body.
inline bool wblRopeEndTiedAroundBody()
    { return true; }

// The belayer holds the rope and pays it out as the character moves farther
// down or away, always keeping just a small amount of slack in the line; for
// an ascent the process is reversed - he pulls the rope in.
inline bool wblPayOutSmallSlack()
    { return true; }

// Failure on the belayer Climbing Check indicates he has lost his hold on the
// rope, and the climber will fall the full distance possible.
inline bool wblFailMeansFullFall()
    { return true; }

// Success means the belayer has hung onto the rope, and at worst the climber
// will fall no farther than the length of the rope.
inline bool wblSuccessBoundedByRopeLen()
    { return true; }

// A belayer in a precarious position (relying on handholds and footholds) who
// succeeds in halting the fall must make a second successful check against
// the jolt of the rope going taut.
inline bool wblPrecariousNeedsSecondCheck()
    { return true; }

// A precarious belayer who halts his companion fall makes TWO successful
// Climbing Checks: the first to halt the fall, the second to keep from being
// pulled down by the jolt of the rope going taut.
inline int wblChecksPrecarious()
    { return 2; }

// If the precarious belayer fails his second check, both the belayer and his
// companion will fall.
inline int wblFallersOnJoltFailure()
    { return 2; }

// A belayer in a secure position (the top of a plateau or a wide ledge) does
// not need the second check.
inline bool wblSecureSkipsSecondCheck()
    { return true; }

// A secure belayer (a plateau or a wide ledge, where he does not need to hold
// himself onto the slope or cliff) needs only the ONE check - the second
// check is not necessary.
inline int wblChecksSecure()
    { return 1; }

// A string of characters connected in pairs with different ropes can belay
// one another in sequence.
inline bool wblPairsBelayInSequence()
    { return true; }

// The last character in line cannot belay anyone.
inline bool wblLastCannotBelay()
    { return true; }

// The leader cannot be belayed.
inline bool wblLeaderCannotBeBelayed()
    { return true; }

// Only one belay can be performed at any time.
inline bool wblOneBelayAtATime()
    { return true; }

// A character cannot climb while he is belaying someone else - the method is
// relatively slow but safer for the group as a whole.
inline bool wblNoClimbWhileBelaying()
    { return true; }

// A character in the middle of a string of belayers who begins to fall will
// not drag down anyone beneath him, as would be the case if all characters
// were roped together.
inline bool wblMiddleFallerDragsNoneBelow()
    { return true; }

// If the belayer of a falling character fails to arrest the fall, that
// belayer has a chance of being saved by the character above who is belaying
// him.
inline bool wblFailedBelayerSavedAbove()
    { return true; }

// Nothing can help the first character who fell, since only two characters
// are connected to the same rope.
inline bool wblFirstFallerUnhelpable()
    { return true; }

}   // namespace rules
