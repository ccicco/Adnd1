// =========================================================================================
// Adnd1 - rules/wsgtread.h
// The WSG TREADING WATER, R453: a character with swimming proficiency who is
// afloat in calm water can remain in one place, by treading water, for a
// number of turns equal to TWICE his endurance score - in other words, he
// uses up one endurance point for every two turns spent treading water. A
// character WITHOUT proficiency in swimming can safely tread water for a
// number of rounds equal to his STRENGTH score; this time limit is modified
// for encumbrance in the same way that a swimmer's endurance is modified.
// When the time limit expires, and at the expiration of every round
// thereafter, the character must make a Strength Check to remain afloat, and
// every check after the first one is made with a CUMULATIVE +1 modifier to
// the die roll. The printed example: a character with a strength of 6 who is
// not encumbered can tread water for at least 12 rounds - the strength limit
// doubled by the unencumbered endurance multiplier - with the unmodified
// check at the end of the 12th round, +1 at the end of the 13th, +2 at the
// end of the 14th, and so on. A character treading water in a current has no
// control over his movement: he is carried in the direction of the current at
// a rate equal to the speed of the current, modified for his encumbrance just
// as for swimming movement. A proficient swimmer can prevent himself from
// moving with the current and maintain the same position in the water - but
// then he is effectively SWIMMING, not treading water, and endurance is
// assessed accordingly. A nonproficient character cannot prevent himself from
// being carried along by the current; if he attempts to do so, he will begin
// to SINK immediately. Census 377 -> 378.
// census 377 -> 378.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 43; the
// user own copy OCR (page 44) cross-checked against the archive djvu word
// layer (Guide_0043) - the section reads CLEAN two-way, every number (the
// twice-endurance turns, the one-point-per-two-turns rate, the strength-score
// limit, the cumulative +1 check modifier, the 6-strength/12-round example
// with the +1/+2 follow-on checks, and the sink-immediately rule) matched
// exactly; the only djvu garbles are the section header and word breaks - no
// eye-reads needed.
//
// Tread calm water twice your endurance in turns, a point every two turns -
// or, without the skill, hold your head up for your strength in rounds,
// modified by encumbrance like endurance, then roll Strength every round at
// +1 a check while the current carries you off. Fight the current and swim,
// if you can - if you cannot, you sink.
//
namespace rules {

// ---- the proficient calm-water hold ----

// A character with swimming proficiency who is afloat in calm water can
// remain in one place by treading water.
inline bool wtwProfCalmWaterHold()
    { return true; }

// The proficient treading limit is a number of turns equal to twice the
// endurance score - one endurance point spent per two turns.
inline bool wtwProfLimitTwiceEndurance()
    { return true; }

// A character with swimming proficiency who is afloat in calm water can
// remain in one place, by treading water, for a number of turns equal to
// twice his endurance score - one endurance point for every two turns spent
// treading water.
inline int wtwProfTurnsPerEndPt()
    { return 2; }

// ---- the nonproficient strength limit ----

// The nonproficient treading limit is a number of rounds equal to the
// strength score.
inline bool wtwNonprofLimitIsStrength()
    { return true; }

// A character without proficiency in swimming can safely tread water for a
// number of rounds equal to his strength score.
inline int wtwNonprofRoundsPerStrPt()
    { return 1; }

// The nonproficient time limit is modified for encumbrance in the same way
// that a swimmer's endurance is modified.
inline bool wtwNonprofLimitEncModified()
    { return true; }

// When the time limit expires, and at the expiration of every round
// thereafter, the character must make a Strength Check to remain afloat.
inline bool wtwStrengthCheckAtExpiry()
    { return true; }

// Every check after the first one is made with a cumulative +1 modifier to
// the die roll.
inline bool wtwChecksCumulativePlusOne()
    { return true; }

// Every Strength Check after the first one is made with a cumulative +1
// modifier to the die roll.
inline int wtwCumCheckStep()
    { return 1; }

// The printed example: a character with a strength of 6 who is not encumbered
// can tread water for at least 12 rounds.
inline int wtwExampleStr()
    { return 6; }

// The example limit: 12 rounds for the strength-6 unencumbered character -
// the strength limit doubled by the unencumbered endurance modifier.
inline int wtwExampleRounds()
    { return 12; }

// At the end of the 12th round the example character makes an unmodified
// Strength Check; at the end of the 13th round the check is made with a +1
// modifier, at the end of the 14th with +2, and so on.
inline int wtwExampleFirstModRound()
    { return 13; }

// ---- the treader in a current ----

// A character treading water in a current has no control over his movement;
// he is carried in the direction of the current at a rate equal to the speed
// of the current, modified for his encumbrance just as for swimming movement.
inline bool wtwCurrentCarriesTreader()
    { return true; }

// A character with swimming proficiency can prevent himself from moving with
// the current and maintain the same position in the water - but then he is
// effectively swimming, not treading water, and endurance is assessed
// accordingly.
inline bool wtwProfHoldsPositionButSwims()
    { return true; }

// A character without swimming proficiency cannot prevent himself from being
// carried along by the current; if he attempts to do so, he will begin to
// sink immediately.
inline bool wtwNonprofResistingSinks()
    { return true; }

}   // namespace rules
