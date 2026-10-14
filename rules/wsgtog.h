// =========================================================================================
// Adnd1 - rules/wsgtog.h
// The WSG ROPING TOGETHER, R441: the cascade prose (no table this round) - if
// two or more characters are roped together on a climb and one fails a
// Climbing Check, the character or characters adjacent to the one who fell
// must make additional successful Climbing Checks (even if they had just made
// a successful check earlier in the same round) to keep from being pulled off
// the slope or cliff face and also falling; a fallen end character forces a
// check only on his one neighbor, a fallen middle character forces checks on
// both sides; for each character who fails beyond the first the adjacent
// checks take a -10% penalty to their Climbing Ratings per extra fallen
// character, until characters on either side succeed or the entire group has
// fallen; if the last two characters both check at the same time and only one
// succeeds, that character makes one more check to keep the entire group from
// falling. The example: five characters on a 200-foot rope (a 50-foot rope
// ties two together, one more per additional 50 feet) - the cascade reaches
// -10, -20 and -30 percent. Census 365 -> 366.
// census 365 -> 366.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 37; the
// user own copy OCR cross-checked against the archive djvu word layer
// (Guide_0037.djvu) - the section reads CLEAN in the djvu, every number (the
// 50-foot tie capacity, the 200-foot rope, the five characters, the
// -10/-20/-30 cascade) matched exactly; no eye-reads were needed. Scope note:
// the tie-capacity rule sits in the USING ROPE: BELAYING intro but is the
// roping-together enabler, so it lands here; the climbing-rope stats and the
// knot rules stay for the belaying round.
//
// A 50-foot rope will suffice to tie two characters together, and another
// character can be added to the string for every additional 50 feet of rope.
// For each character who fails his Climbing Check beyond the first, the
// adjacent characters check at a -10% penalty per extra fallen character -
// the five-character example on a 200-foot rope cascades through -10, -20 and
// -30 percent.
//
namespace rules {

// ---- the roping-together rules ----

// The characters adjacent to the one who fell must make additional successful
// Climbing Checks even if they had just made a successful check earlier in
// the same round.
inline bool wrpAdjacentMustRecheck()
    { return true; }

// If a character on either end of the rope falls, only the character adjacent
// to him needs to make a Climbing Check.
inline bool wrpEndFallerOneAdjacent()
    { return true; }

// If a character in the middle of the group falls, the climbers on both sides
// must make successful checks to halt his fall.
inline bool wrpMiddleFallerBothSides()
    { return true; }

// For each character who fails his Climbing Check beyond the first, the
// adjacent character(s) must make Climbing Checks with a -10% penalty to
// their Climbing Ratings.
inline int wrpCascadeStepPct()
    { return 10; }

// The penalty to the adjacent climbers Climbing Ratings, by the number of
// fallen characters BEYOND the first: 0 with only one fallen, and -10% more
// for each extra fallen character - -10% with two fallen, -20% with three,
// -30% with four, -40% beyond five.
inline int wrpCascadePenaltyPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 40;
        default:
            return 40;
        }
    }

// The process continues until characters on either side make successful
// Climbing Checks, or until everyone in the group fails a Climbing Check -
// which means the entire group has fallen.
inline bool wrpCascadeUntilHaltOrAll()
    { return true; }

// If the last two characters in a group are both required to make checks at
// the same time and only one of them succeeds, the successful character must
// make one more check to keep the entire group from falling.
inline bool wrpLastPairSingleSuccessExtra()
    { return true; }

// A 50-foot rope will suffice to tie two characters together.
inline int wrpTieTwoCharFt()
    { return 50; }

// Another character can be added to the string for every additional 50 feet
// of rope in the coil.
inline int wrpExtraCharPerFt()
    { return 50; }

// Five characters are strung together on the example rope, attempting to
// scale a cliff face.
inline int wrpExamplePartySize()
    { return 5; }

// The example rope is 200 feet long - exactly what five roped characters
// need: 50 feet for two, plus 50 more for each additional character.
inline int wrpExampleRopeFt()
    { return 200; }

}   // namespace rules
