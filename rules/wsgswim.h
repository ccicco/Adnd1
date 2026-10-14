// =========================================================================================
// Adnd1 - rules/wsgswim.h
// The WSG SWIMMING, R450: the swimming intro, TABLE 24 EFFECTS OF ENCUMBRANCE
// ON SWIMMING, and the Endurance and Speed subsections - only characters with
// proficiency in swimming can propel themselves through the water without
// magic or a flotation device, but nonproficient characters do not simply
// sink like a stone (the section covers swimming and treading water). The
// three sub-skills are endurance, speed and diving; the most important factor
// for ANY swimmer is his degree of encumbrance. Table 24: the five
// encumbrance rows (none, light, moderate, heavy, severe) x the four
// functions (endurance, speed, diving, surfacing) - none doubles everything
// but diving; light is the unmodified baseline; moderate halves endurance,
// speed and surfacing while doubling diving; heavy quarters them while
// tripling diving; severe is the dash - impossible - except diving, which
// stays tripled: a severely encumbered character cannot swim, sinks in water
// deeper than his height and cannot surface without dropping encumbrance.
// Endurance: the base, in turns, is the total of experience levels plus the
// constitution score; at the limit he must rest out of the water or standing
// in calm water, regaining three turns per turn of rest; high speed doubles
// the movement rate but cuts endurance to 1/10 (rounded up), and high-speed
// losses are regained only one-for-one. Speed: humans swim 4 inches (40 feet
// per round), other PC races and land-based humanoids 3 inches; beneath the
// surface the rate is 2/3 (rounded up); strength and current modifiers run
// +1/+2/+3 for strength 16-17/18/18-01+ and plus-or-minus 1-3 light, 4-6
// strong; a modified rate of 0 means holding position at endurance cost, less
// than 0 means the mercy of the current (drifting backward 1-3 inches); high
// speed is surface-only and is halved where the normal rate would be 0 or
// less. Census 374 -> 375.
// census 374 -> 375.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 41; the
// user own copy OCR (page 42) cross-checked against the archive djvu word
// layer (Guide_0041.djvu) - the intro, Endurance and Speed prose reads CLEAN
// two-way, every number (the 3-turn rest rate, the 1/10 high-speed cut, the
// 18-turn example, the 40/30 base rates, the 2/3 subsurface rate, the
// modifier table and the 0-inch rules) matched exactly; the Table 24 grid and
// the strength/current modifier table are GARBLED in the djvu word layer, so
// every cell was confirmed by TWO independent IIIF eye-reads of leaf 41 - the
// OCR and both eye-reads agree on all 20 Table 24 cells and all seven
// modifier rows.
//
// Encumbrance rules the water: none doubles, light is the baseline, moderate
// halves (but doubles the dive), heavy quarters (but triples the dive), and
// severe cannot swim at all - only the dive keeps working, straight down.
//
namespace rules {

// ---- the swimming prose rules ----

// The skill of swimming is composed of three sub-skills: endurance (how long
// a character can keep swimming), speed (how fast he can move through the
// water), and diving (how rapidly he can move downward through the water).
inline int wsmSubSkillCount()
    { return 3; }

// Only characters with proficiency in swimming have the ability to propel
// themselves through the water without the aid of magic or some sort of
// flotation device.
inline bool wsmOnlyProficientSwim()
    { return true; }

// Nonproficient characters do not simply sink like a stone if they find
// themselves immersed in a deep body of water - the section covers swimming
// for those who can swim and treading water for swimmers and non-swimmers
// alike.
inline bool wsmNonproficientNotSink()
    { return true; }

// The physical attributes of a swimmer may affect how well he performs the
// three functions, but the most important factor - and one that applies to
// any swimmer - is his degree of encumbrance.
inline bool wsmEncumbranceKeyFactor()
    { return true; }

// A dash entry on Table 24 means it is impossible for the character to
// perform the function under that degree of encumbrance.
inline bool wsmDashMeansImpossible()
    { return true; }

// A severely encumbered character cannot swim - he will sink in any body of
// water deeper than his height, and will not be able to surface under his own
// power unless he gets rid of at least some of his encumbrance before he
// drowns.
inline bool wsmSevereSinksCannotSurface()
    { return true; }

// A character base swimming endurance, in turns, equals his total of
// experience levels (counting all classes for a multiclassed or two-class
// character) plus his constitution score.
inline bool wsmEnduranceLevelsPlusCon()
    { return true; }

// A resting swimmer regains three turns of endurance for every turn spent
// resting - out of the water or standing in calm water that is not over his
// head; the same rate applies if he stops before using up all his endurance.
inline int wsmRestRegainPerTurn()
    { return 3; }

// A character can swim at high speed, doubling his normal movement rate.
inline int wsmHighSpeedMult()
    { return 2; }

// Swimming at high speed reduces his endurance to 1/10 of its normal amount,
// rounded up.
inline int wsmHighSpeedEndDiv()
    { return 10; }

// High-speed swimming reduces the endurance to 1/10 of its normal amount,
// rounded up - the example: a 6th-level thief with constitution 12 has 18
// turns lightly encumbered; after 8 normal turns, his remaining 10 turns buy
// exactly 1 more high-speed turn.
inline bool wsmHighSpeedEndTenthRoundUp()
    { return true; }

// After a high-speed swim the character must get out of the water to rest,
// and the endurance lost to high speed is regained only on a one-for-one
// basis - one turn of endurance for one turn of rest.
inline bool wsmHighSpeedRestOneForOne()
    { return true; }

// The base swimming movement rate for humans is 4 inches (40 feet per round).
inline int wsmHumanSwimRateFt()
    { return 40; }

// For other player-character races and land-based humanoids, the base
// swimming movement rate is 3 inches (30 feet per round).
inline int wsmOtherSwimRateFt()
    { return 30; }

// A specific swimming rate listed in the statistics for any monster or
// humanoid supersedes the base rate given here.
inline bool wsmMonsterRateSupersedes()
    { return true; }

// For a swimmer moving beneath the surface of the water, the rate is reduced
// to 2/3 of the given amount, rounded up.
inline int wsmSubsurfaceNum()
    { return 2; }

// The denominator of the subsurface reduction: 2/3 of the surface rate,
// rounded up.
inline int wsmSubsurfaceDen()
    { return 3; }

// Swimming movement rate modifier: Strength 16 or 17, +1 inch.
inline int wsmStr1617BonusIn()
    { return 1; }

// Swimming movement rate modifier: Strength 18, +2 inches.
inline int wsmStr18BonusIn()
    { return 2; }

// Swimming movement rate modifier: Strength 18/01 or higher, +3 inches.
inline int wsmStr1801BonusIn()
    { return 3; }

// Swimming with or against a light current modifies the rate by 1 to 3
// inches, with or against the flow.
inline int wsmLightCurMaxIn()
    { return 3; }

// Swimming with or against a strong current modifies the rate by 4 to 6
// inches, with or against the flow.
inline int wsmStrongCurMinIn()
    { return 4; }

// The top of the strong-current modifier range: 4 to 6 inches.
inline int wsmStrongCurMaxIn()
    { return 6; }

// A modified movement rate of 0 means the character cannot move forward and
// must exert himself, using up endurance, simply to maintain his present
// location.
inline bool wsmZeroRateHoldPosition()
    { return true; }

// A modified rate of less than 0 means the character is at the mercy of the
// current - the example: a 4-inch base against a 4-inch current is 0, and
// even at high speed he manages only 2 inches (half the normal bonus).
inline bool wsmNegativeRateMercy()
    { return true; }

// A modified rate of less than 0 means the character is at the mercy of the
// current - even swimming against it he is propelled in the opposite
// direction at 1 to 3 inches, depending on the strength of the current.
inline int wsmMercyDriftMaxIn()
    { return 3; }

// The strength of the current is determinable only by the Dungeon Master - a
// gently flowing river is probably no more than 1 or 2 inches, a rushing
// mountain stream certainly in the 5 to 6 inch range.
inline bool wsmCurrentDmDetermined()
    { return true; }

// It is not possible to swim at high speed beneath the surface; the doubling
// option applies only to characters swimming on the surface.
inline bool wsmNoHighSpeedSubsurface()
    { return true; }

// The high-speed increase is halved in any water conditions where the
// character would have a movement rate of 0 or less at normal speed.
inline bool wsmHighSpeedHalvedAtZero()
    { return true; }

// ---- the Table 24 swimming grid ----

// Table 24 has five encumbrance rows: none, light, moderate, heavy and
// severe.
inline int wsmEncRowCount()
    { return 5; }

// The numerator of the endurance multiplier by encumbrance row (0 = the dash,
// impossible).
inline int wsmEndNum(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        default:
            return 1;
        }
    }

// The denominator of the endurance multiplier: x2 none, x1 light, x1/2
// moderate, x1/4 heavy, dash severe.
inline int wsmEndDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 1;
        default:
            return 1;
        }
    }

// The numerator of the speed multiplier (0 = the dash).
inline int wsmSpdNum(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        default:
            return 1;
        }
    }

// The denominator of the speed multiplier: x2, x1, x1/2, x1/4, dash.
inline int wsmSpdDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 1;
        default:
            return 1;
        }
    }

// The numerator of the diving multiplier - the one function that never
// dashes: x1, x1, x2, x3, x3.
inline int wsmDiveNum(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 3;
        default:
            return 1;
        }
    }

// The denominator of the diving multiplier (always 1).
inline int wsmDiveDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        default:
            return 1;
        }
    }

// The numerator of the surfacing multiplier (0 = the dash).
inline int wsmSurfNum(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        default:
            return 1;
        }
    }

// The denominator of the surfacing multiplier: x2, x1, x1/2, x1/4, dash.
inline int wsmSurfDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 1;
        default:
            return 1;
        }
    }

}   // namespace rules
