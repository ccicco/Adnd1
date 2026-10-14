// =========================================================================================
// Adnd1 - rules/wsgchasm.h
// The WSG CROSSING A CHASM ON A ROPE, R445: the chasm prose and Table 21 -
// characters can negotiate a chasm or deep canyon by anchoring a rope on the
// far side and moving hand-over-hand across it. Success depends on two
// factors: whether the terrain offers a protrusion to anchor a line, and
// whether the rope can be anchored to hold their weight; a grappling hook
// answers both questions through Table 20. A thrown loop of rope can also
// catch a protrusion if the target is directly across or only slightly above
// or below the thrower (never on a vertical climb), but only a thief or a
// rope-use proficient character can succeed. Table 21 gives the maximum
// ranges by level band: 40 feet at 1-4, 50 at 5-8, 60 at 9-12, 75 at 13-16
// and 90 at 17+. The ranges assume a clear 10-foot radius to whirl the loop;
// without it, half the given figure. The base chance of hitting the target is
// 20%, plus 1% for every foot of distance below the maximum range; moderate
// to heavy precipitation, wind over 20 miles per hour or hampered visibility
// (fog, night) halve the chance - the fog example: a 17th-level character at
// 50 feet has (20 + 40) / 2 = 30%. Before crossing, BOTH ends must be
// anchored, and a suitable protrusion must exist on the near side too (wise
// to check before anchoring the far side). Once anchored, characters move
// hand-over-hand at a maximum 30 feet per round; it is prudent for only one
// to use the rope at a time - if more than one hangs from it, each makes a
// Dexterity Check at +2 on the die, failure meaning a lost grip and a fall.
// Census 369 -> 370.
// census 369 -> 370.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 38-39;
// the user own copy OCR cross-checked against the archive djvu word layer
// (Guide_0038.djvu for the chasm prose and Table 21, the Guide_0039.djvu head
// for the crossing rate) - the section reads CLEAN, every number (the
// 40/50/60/75/90 ranges, the 10-foot radius, the 20% base with the +1% per
// foot, the 20 mph wind, the 17th-level 30% fog example, the
// 30-feet-per-round rate and the +2 Dexterity modifier) matched exactly; no
// eye-reads were needed.
//
// The thrown loop: 40 to 90 feet by level band, base hit chance 20% plus 1%
// per foot below maximum range, halved in bad conditions - and the crossing
// itself runs hand-over-hand at 30 feet per round, one character at a time,
// with a +2 Dexterity Check for each extra hanger on the rope.
//
namespace rules {

// ---- the chasm-crossing prose rules ----

// The chasm tactic depends on two factors: whether the terrain offers a
// protrusion to anchor a line, and whether the rope can be anchored so it
// will hold the characters weight.
inline bool wcxTwoFactorsProtrusionAndHold()
    { return true; }

// A rope attached to a grappling hook answers both factors by using Table 20,
// choosing the terrain line that most closely corresponds to the target area.
inline bool wcxGrapplingHookViaTable20()
    { return true; }

// A thrown loop can catch a protrusion only if the target is located directly
// across from or only slightly above or below the thrower.
inline bool wcxLoopTargetAcrossOrSlightly()
    { return true; }

// The thrown-loop tactic does not work on a vertical climb, which is why it
// was not discussed with the grappling hooks.
inline bool wcxLoopNeverOnVerticalClimb()
    { return true; }

// Only a thief or a character with proficiency in rope use can succeed with a
// thrown loop; no one else can.
inline bool wcxThiefOrRopeUseOnly()
    { return true; }

// The Table 21 ranges assume a clear 10-foot radius of space around the
// character so the loop can be whirled around before it is released.
inline int wcxWhirlRadiusFt()
    { return 10; }

// Without the clear 10-foot whirling radius, the maximum range is half of the
// given Table 21 figure.
inline bool wcxNoWhirlRadiusHalvesRange()
    { return true; }

// The base chance of hitting the target with a thrown loop is 20%.
inline int wcxBaseHitPct()
    { return 20; }

// The hit chance gains a +1% bonus for every foot of distance between thrower
// and target that is LESS than the maximum range - the closer the target, the
// better the chance.
inline int wcxClosenessBonusPerFt()
    { return 1; }

// Wind blowing more than 20 miles per hour halves the chance of hitting the
// target; moderate to heavy precipitation or hampered visibility (fog, night)
// do the same.
inline int wcxWindMphLimit()
    { return 20; }

// Moderate to heavy precipitation, wind over 20 miles per hour, or any
// condition hampering visibility (fog, night) modifies the hit chance
// downward by half.
inline bool wcxBadConditionsHalveHit()
    { return true; }

// Before characters can move across a horizontally anchored rope, both ends
// must be anchored - which means a suitable protrusion must also exist at the
// location the characters are moving FROM (wise to check before anchoring the
// far side).
inline bool wcxBothEndsMustBeAnchored()
    { return true; }

// It is prudent for only one character to use the rope at a time.
inline bool wcxOneAtATimePrudent()
    { return true; }

// Once a rope is securely anchored at both ends, characters move along it
// hand-over-hand at a maximum rate of 30 feet per round.
inline int wcxCrossRateFtPerRound()
    { return 30; }

// If more than one character hangs from the rope at the same time, each of
// them must make a Dexterity Check with a +2 modifier to the die roll;
// failure means a lost grip and a fall.
inline int wcxMultipleHangerDexMod()
    { return 2; }

// If more than one character hangs from the rope at the same time, each must
// make the +2 Dexterity Check; failure means the character loses his grip on
// the rope and falls.
inline bool wcxMultiHangerDexCheck()
    { return true; }

// ---- the Table 21 thrown loop grid ----

// Table 21 has five level bands: 1-4, 5-8, 9-12, 13-16 and 17+.
inline int wcxLoopBandCount()
    { return 5; }

// The maximum distance in feet at which the character can hit a target with a
// thrown loop, by level band: 40 feet at levels 1-4, 50 at 5-8, 60 at 9-12,
// 75 at 13-16 and 90 at 17 and above.
inline int wcxMaxRangeFt(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 50;
        case 2:
            return 60;
        case 3:
            return 75;
        case 4:
            return 90;
        default:
            return 90;
        }
    }

}   // namespace rules
