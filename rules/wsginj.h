// =========================================================================================
// Adnd1 - rules/wsginj.h
// R480: the WSG INJURIES AND TREATMENT slice, printed p. 70 - the tenth
// camping-arc round, a pure prose round with NO table: the five specific
// injuries and their treatments - broken bone, minor burn, major burn, major
// wound and minor wound - with the general first-aid frame (the skills are
// common knowledge, useful only when the DM rules with proper reason that a
// specific injury was suffered).
// census 404 -> 405.
//
// The settle: the injuries section lives on the same printed p. 70 already
// settled for R479 - the tesseract full-text read and the pdfy layout read
// agree on every number of the section (the tesseract tsv even confirms the
// dice formulas and ranges cell by cell), so no contested cells and no vision
// reads were needed. The dice formulas are pinned as dice-plus-modifier
// consts with the printed ranges as cross-checks: 2-4 as 1d3+1, 2-7 as 1d6+1,
// the immediate 1d6 and the 1d4 per round.
//
// Bounds held: the major burn pain penalty is exactly three times the minor
// one; both the bleeding and the pressure ranges match their
// dice-plus-modifier formulas; the artery trigger sits at an unmodified
// damage roll of 6 or higher with a 25% chance.
//
namespace rules {

// ---- The general first-aid frame ----

// the general first-aid skills are common knowledge among most adventurers,
// usable by anyone with the time and materials
inline bool wtrFirstAidCommonKnowledge()
    { return true; }

// the skills are only useful if the DM rules with proper reason that a
// specific injury was suffered
inline bool wtrDmRulesSpecificInjury()
    { return true; }

// five specific injuries: broken bone, minor burn, major burn, major wound,
// minor wound
inline int wtrInjuryTypeCount()
    { return 5; }

// ---- The broken bone ----

// putting a splint on the injury keeps the ends of the broken bone properly
// aligned and makes healing possible
inline bool wtrSplintAlignsBone()
    { return true; }

// no hit points lost to a broken bone in an extremity are regained until the
// character is fitted with a splint
inline bool wtrSplintRequiredToHeal()
    { return true; }

// attempting to use the injured extremity even while splinted immediately
// costs the extra damage
inline bool wtrSplintUseExtraDamage()
    { return true; }

// using the splinted injured extremity costs an immediate 1d6
inline int wtrSplintUseDice()
    { return 1; }

// the immediate extra damage for using the injured extremity
inline int wtrSplintUseSides()
    { return 6; }

// the use also neutralizes any healing of the bone up to that time
inline bool wtrSplintUseNeutralizesHealing()
    { return true; }

// for a character with several injuries the broken bone is the last injury
// for which hit points are regained
inline bool wtrBrokenBoneHealsLast()
    { return true; }

// ---- The minor burn ----

// immerse the burned area in water for at least two turns
inline int wtrBurnImmerseMinTurns()
    { return 2; }

// depriving the burned area of air - immersion in water or a tight
// clean-cloth wrapping - lets the burn heal at the normal rate
inline bool wtrBurnAirDeprivedHeals()
    { return true; }

// a protected burn heals at the normal rate of 1 hit point per day
inline int wtrHealPerDay()
    { return 1; }

// an unprotected minor burn: a -1 penalty on all attack rolls and saving
// throws
inline int wtrMinorPainPenalty()
    { return 1; }

// an unprotected minor burn heals only half as fast as normal
inline bool wtrMinorBurnHalfHealUnprotected()
    { return true; }

// ---- The major burn ----

// the half fraction: one-half of the body, of the lost points
inline int wtrHalfNum()
    { return 1; }

// both the major-burn body bar and the rest bar use one-half
inline int wtrHalfDen()
    { return 2; }

// a major burn victim must rest until he has regained at least half of the
// hit points lost due to the burn
inline bool wtrMajorBurnRestRequired()
    { return true; }

// voluntary activity before recovery forfeits every hit point regained up to
// that point
inline bool wtrMajorBurnForfeitRegained()
    { return true; }

// a major burn victim active before recovery takes 1d4 per round
inline int wtrMajorActivityDice()
    { return 1; }

// the additional damage per round of voluntary activity is 1d4
inline int wtrMajorActivitySides()
    { return 4; }

// a major burn: the pain penalty is -3 instead of -1 on all attack rolls and
// saving throws
inline int wtrMajorPainPenalty()
    { return 3; }

// a major burn victim can usually still ride a mount or be carried by a
// comrade or on a stretcher
inline bool wtrMajorBurnCanBeCarried()
    { return true; }

// ---- The major wound ----

// the major wound comes only from an edged melee weapon
inline bool wtrMajorWoundEdgedOnly()
    { return true; }

// the major wound trigger: an unmodified damage roll of 6 or higher from an
// edged melee weapon
inline int wtrArteryMinDamage()
    { return 6; }

// the DM may rule the artery strike on a 25% chance
inline int wtrArteryChance()
    { return 25; }

// the artery strike is ruled at the DM discretion or on the 25% chance
inline bool wtrMajorWoundDmDiscretion()
    { return true; }

// the severe bleeding loses an additional 2-4 hit points per round
inline int wtrBleedMin()
    { return 2; }

// the top of the severe bleeding range
inline int wtrBleedMax()
    { return 4; }

// the severe bleeding is 1d3 + 1 hit points per round
inline int wtrBleedDice()
    { return 1; }

// the die of the severe bleeding formula
inline int wtrBleedSides()
    { return 3; }

// the modifier of the severe bleeding formula
inline int wtrBleedPlus()
    { return 1; }

// a comrade or the victim himself - if the wound is in an accessible place -
// stems the bleeding by applying pressure directly to the wound
inline bool wtrBleedingStemmedByPressure()
    { return true; }

// direct pressure must be applied for 2-7 consecutive rounds
inline int wtrPressureMin()
    { return 2; }

// the top of the pressure duration range
inline int wtrPressureMax()
    { return 7; }

// the pressure duration is 1d6 + 1 rounds
inline int wtrPressureDice()
    { return 1; }

// the die of the pressure duration formula
inline int wtrPressureSides()
    { return 6; }

// the modifier of the pressure duration formula
inline int wtrPressurePlus()
    { return 1; }

// while the pressure is applied the victim loses 1 hit point per round until
// the time has passed
inline int wtrPressureHpLoss()
    { return 1; }

// wrapping the wound tightly halts the bleeding, but recovering the lost hit
// points needs the pressure procedure performed by a character with
// proficiency in healing
inline bool wtrWrappingHaltsButNeedsHealer()
    { return true; }

// releasing the pressure before the required time negates the first aid and
// the bleeding begins again
inline bool wtrPressureReleaseNegates()
    { return true; }

// for the renewed pressure the DM can use the original result or roll again
// for added randomness
inline bool wtrDmMayRerollPressure()
    { return true; }

// ---- The minor wound ----

// any wound that breaks the skin is assumed bandaged at the first available
// opportunity
inline bool wtrMinorWoundBandageAssumed()
    { return true; }

}   // namespace rules
