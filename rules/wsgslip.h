// =========================================================================================
// Adnd1 - rules/wsgslip.h
// The WSG MOVEMENT ON SLIPPERY HORIZONTAL SURFACES, R447: the slippery prose
// (no table this round) - a character who does not exercise caution when
// traveling across a slippery horizontal surface risks slipping and falling
// down, which does not directly cause him to suffer damage but could be an
// indirect cause of greater problems to come. He can move at his full normal
// movement rate without risking a fall IF he travels in a straight line;
// anything other than a very gradual turn, or an abrupt stop or speed-up,
// demands a successful Dexterity Check to avoid slipping and falling down. A
// character attempting to RUN must make a Dexterity Check after every five
// segments of such movement to stay on his feet, even in a straight line. At
// only HALF his full normal movement rate he can turn with no check; and
// taking a full round to slow down or speed up (full normal movement to a
// standstill, or vice versa) needs no check. Census 371 -> 372.
// census 371 -> 372.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 39; the
// user own copy OCR cross-checked against the archive djvu word layer
// (Guide_0039.djvu) - the section reads CLEAN, every number (the five-segment
// running check cadence, the half-rate cautious turn, the full-round speed
// change) matched exactly; no eye-reads were needed.
//
// Straight-line travel at the full rate is free; every other movement choice
// costs a Dexterity check - a turn, an abrupt stop or speed-up, or a run with
// its check every five segments - unless the character drops to half rate for
// the turn or spends a full round on the speed change, and the fall itself
// does no direct damage.
//
namespace rules {

// ---- the slippery surface movement rules ----

// If a character attempts to run on a slippery surface, he must make a
// Dexterity Check after every five segments of this sort of movement to stay
// on his feet, even if he is traveling in a straight line.
inline int wslRunCheckSegs()
    { return 5; }

// By moving at only half of his full normal movement rate (the rate divided
// by 2), a character can turn without needing to make a Dexterity Check.
inline int wslCautiousRateDiv()
    { return 2; }

// A character who does not exercise caution when traveling across a slippery
// horizontal surface risks slipping and falling down.
inline bool wslCautionRisksFall()
    { return true; }

// A character can move at his full normal movement rate across a slippery
// surface without risking a fall, if he travels in a straight line.
inline bool wslStraightFullRateSafe()
    { return true; }

// If he attempts anything other than a very gradual turn, or if he tries to
// stop or speed up abruptly, he must make a successful Dexterity Check to
// avoid slipping and falling down.
inline bool wslAbruptChangeNeedsDexCheck()
    { return true; }

// A character attempting to run on a slippery surface makes the
// every-five-segments Dexterity Check even if he is traveling in a straight
// line.
inline bool wslRunCheckEvenStraight()
    { return true; }

// If he takes a full round to slow down or speed up - from full normal
// movement to a standstill, or vice versa - then no Dexterity Check is
// required.
inline bool wslFullRoundSpeedChangeFree()
    { return true; }

// Slipping and falling down does not directly cause the character to suffer
// damage, but could be an indirect cause of greater problems to come.
inline bool wslFallNoDirectDamage()
    { return true; }

}   // namespace rules
