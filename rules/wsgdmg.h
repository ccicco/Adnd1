// =========================================================================================
// Adnd1 - rules/wsgdmg.h
// R477: the WSG DAMAGE FROM FIRE slice, printed p. 68 - the seventh
// camping-arc round, closing the camping-arc FIRE chapter by riding the
// uncontrollable-fires seam unpinned by R476 (whose round stopped at the
// fleeing prose): the advance and firebreak prose (an uncontrollable fire
// advances at one-half of the wind velocity or 5 mph in any case; a trot
// stays ahead in calm air or a light breeze; the firebreak of churned and
// cleared ground with dig and move earth and the 18-strength spade of
// colossal excavation; the cut-the-blaze-in-half ruling; the cleared-area
// refuge with its too-close peril), the engulfment rule (10-15 points of
// damage, 1d6+9, per round, cut in half rounded up on a successful
// Constitution Check with a +4 modifier to the die roll, with burn damage
// equal to one-third of the full normal hit-point total rendering the victim
// unconscious and ending his Constitution Checks), the brief-contact rule
// (1d8 points for leaping through a wall of fire, saves versus normal fire
// for every major item, 1d3 additional points per round per burning item
// until extinguished or discarded, the Wisdom Check to stay calm, hit the
// ground and roll, and the panic run at top speed in a random direction
// taking 1d4 per round until caught), and the extreme-heat rule (closer than
// 5 feet to a large fire or 3 feet to a medium fire counts as 120 degrees or
// higher per the Temperature Damage to Characters Table, with the
// activity-level adjustments waived), printed p. 68.
// census 401 -> 402.
//
// Ground truth two-way clean on every number, no contested cells, no
// physical-page reads: the user-run Termux tesseract text of printed p. 68
// (p68_full.txt, p68_tsv.tsv) vs the pdf embedded text layer (pdftotext
// -layout, pdf page 69, p68_pdfy.txt). The two readers AGREE on all prose
// numbers: the half-wind advance with the 5-mph floor, the 10-15 engulf
// damage as 1d6+9 with the +4 Constitution Check modifier and the
// halved-rounded-up reduction, the one-third unconscious threshold, the 1d8
// brief contact, the 1d3 per burning item, the 1d4 panic damage, the 5-foot
// large and 3-foot medium heat distances at 120 degrees, and the 18-strength
// spade of colossal excavation. The page carries NO table, so no
// vision-on-png settler was needed; the printed-page-68 offset against pdf
// page 69 was confirmed at extraction time per the R476 lesson.
//
// All prose numbers of printed p. 68 pinned (the advance speed, the engulf
// damage range with its check modifier, the unconscious threshold, the
// contact dice, the heat distances and temperature); the firebreak, refuge,
// panic and adjudication prose are audit examples.
//
namespace rules {

// ---- The firebreak and the advance ----

// an uncontrollable fire advances at one-half of the wind velocity
inline int wdmAdvanceWindDiv()
    { return 2; }

// the fire advances at a speed of 5 mph in any case
inline int wdmAdvanceMinMph()
    { return 5; }

// in calm air or a light breeze a man or animal moving at a trot can stay
// safely ahead of the flames
inline bool wdmTrotStaysAhead()
    { return true; }

// a firebreak is an area of ground in the path of the fire churned up and
// cleared to remove most or all of the combustible material
inline bool wdmFirebreakClears()
    { return true; }

// spells such as dig and move earth are helpful in building a firebreak
inline bool wdmDigMoveEarthHelp()
    { return true; }

// a party containing a fighter with 18 strength and a spade of colossal
// excavation may be able to kill a fire with a firebreak
inline bool wdmSpadeCanKillFire()
    { return true; }

// a single firebreak that cannot extinguish a very extensive fire can be used
// to cut the blaze in half, leaving two smaller fires
inline bool wdmFirebreakCutsInHalf()
    { return true; }

// characters without the means to extinguish an uncontrollable blaze may save
// themselves by clearing an area and remaining in that spot while the fire
// burns around them
inline bool wdmClearedAreaRefuge()
    { return true; }

// characters in a cleared area may still suffer damage from heat or flames if
// they do not clear a large enough space and the fire gets too close
inline bool wdmRefugeStillRisky()
    { return true; }

// ---- The engulfment rule ----

// in heroic fantasy direct exposure to fire is not always lethal, but it is
// not to be taken lightly
inline bool wdmFireNotAlwaysLethal()
    { return true; }

// a character engulfed in flames rolls 1d6
inline int wdmEngulfDice()
    { return 1; }

// the engulf damage die is d6
inline int wdmEngulfDieSides()
    { return 6; }

// the engulf damage bonus is +9
inline int wdmEngulfBonus()
    { return 9; }

// engulfment deals 10-15 points of damage per round
inline int wdmEngulfMinDmg()
    { return 10; }

// the top of the 10-15 engulf damage range
inline int wdmEngulfMaxDmg()
    { return 15; }

// the Constitution Check to halve engulf damage takes a +4 modifier to the
// die roll
inline int wdmConCheckMod()
    { return 4; }

// the engulf damage is cut in half, rounded up, on a successful Constitution
// Check
inline int wdmHalveDivisor()
    { return 2; }

// the engulf rule applies only when the victim is fully within a fire or when
// most of the surface of his body, clothing and gear, is actually aflame
inline bool wdmEngulfRequiresImmersion()
    { return true; }

// the successful Constitution Check cuts the engulf damage in half, rounded
// up
inline bool wdmHalvedRoundedUp()
    { return true; }

// burn damage equal to one-third of the full normal hit-point total renders
// the victim unconscious
inline int wdmUnconsciousNum()
    { return 1; }

// the unconscious threshold denominator is one-third
inline int wdmUnconsciousDen()
    { return 3; }

// a character who suffers burn damage equal to one-third of his full normal
// hit points is rendered unconscious and is no longer allowed Constitution
// Checks to offset part of the damage
inline bool wdmUnconsciousLosesChecks()
    { return true; }

// ---- The brief-contact rule ----

// brief contact with a fire, such as leaping through a wall of fire, deals
// 1d8 points of damage
inline int wdmBriefDieSides()
    { return 8; }

// on brief contact with fire every major piece of clothing or equipment
// carried must save versus normal fire to avoid being ignited
inline bool wdmItemsSaveVsFire()
    { return true; }

// every major item that catches fire adds 1d3 points of damage per round
inline int wdmItemBurnDieSides()
    { return 3; }

// for every major item that catches fire the character suffers additional
// damage per round until the flame is extinguished or the item is discarded
inline bool wdmItemBurnPerRound()
    { return true; }

// a character whose gear catches fire can avoid damage with a successful
// Wisdom Check: remaining calm, hitting the ground and rolling
inline bool wdmWisCheckAvoids()
    { return true; }

// an unsuccessful Wisdom Check means the character has panicked: he runs at
// top speed in a random direction, away from the fire if possible
inline bool wdmPanicRuns()
    { return true; }

// a panicked character takes 1d4 points of damage per round until caught and
// helped
inline int wdmPanicDieSides()
    { return 4; }

// the panicked character takes damage per round until another character
// catches him and helps put out the flames
inline bool wdmPanicUntilCaught()
    { return true; }

// ---- The heat rule ----

// a character need not be in direct contact with fire to be hurt by it: at
// short distances extreme heat can be almost as damaging as actual fire
inline bool wdmHeatNeedsNoContact()
    { return true; }

// closer than 5 feet to a large fire exposes the character to extreme heat
inline int wdmHeatLargeFt()
    { return 5; }

// closer than 3 feet to a medium fire exposes the character to extreme heat
inline int wdmHeatMediumFt()
    { return 3; }

// the heat exposure counts as a temperature of 120 degrees or higher
inline int wdmHeatTempDegrees()
    { return 120; }

// near a fire the damage adjustments for level of activity do not apply: the
// inactive take just as much heat damage as the strenuous
inline bool wdmHeatIgnoresActivity()
    { return true; }

// the extreme-heat exposure uses the Temperature Damage to Characters Table
// from the Effects of the Environment section
inline bool wdmHeatTableRef()
    { return true; }

// beyond the given distances the character is relatively safe but may still
// suffer damage from exposure to extremely high temperatures per the table
inline bool wdmBeyondSafeButHot()
    { return true; }

// ---- The adjudication caveat ----

// situations not covered by these rules call for reasonable Dungeon Master
// rulings on the amount of damage and the chance of avoiding it
inline bool wdmDmAdjudicatesUncovered()
    { return true; }

}   // namespace rules
