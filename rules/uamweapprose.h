// ===========================================================================
// Adnd1 - rules/uamweapprose.h
// The UA TREASURE
// (MISCELLANEOUS WEAPONS)
// prose pins, R388: the pp.
// 105-106 stretch - nine pins,
// six fully clean (the bullet
// of impact, the dagger
// Longtooth, the darts of
// homing, the knife buckle,
// the magic quarterstaff, the
// scimitar of speed) plus
// three mechanics-clean with
// flagged holes (the axe of
// hurling's familiarization
// tail, the dagger of
// throwing's range cells, the
// hornblade's handle
// sentence). Nothing fully
// garbles; with the misc
// magic and armor swords
// rounds the treasure prose
// sweep stands complete. The
// armor and skeleton seams
// ride in the regtest audit,
// not here.
namespace rules {

// ---- the axe of hurling ----
// Appears a normal hand axe;
// hurled up to 6-inch
// distance, returning to the
// thrower in the same round
// whether or not it scores a
// hit.
inline bool uamwAohNormalHandAxeAppearance()
    { return true; }

inline int uamwAohHurledRangeIn()
    { return 6; }

inline bool uamwAohReturnsSameRound()
    { return true; }

inline bool uamwAohReturnsHitOrMiss()
    { return true; }

// Throwing damage is twice
// normal (2-12 vs. S or M, 2-8
// vs. L), the magic bonus
// added thereafter; the +3
// example does 5-15 vs. S or
// M and 5-11 vs. L; handheld
// use does only normal damage
// plus the bonus.
inline bool uamwAohThrownDamageDoubled()
    { return true; }

inline int uamwAohThrownSmLo()
    { return 2; }

inline int uamwAohThrownSmHi()
    { return 12; }

inline int uamwAohThrownLLo()
    { return 2; }

inline int uamwAohThrownLHi()
    { return 8; }

inline bool uamwAohBonusAddedAfter()
    { return true; }

inline int uamwAohExampleBonus()
    { return 3; }

inline int uamwAohExampleSmLo()
    { return 5; }

inline int uamwAohExampleSmHi()
    { return 15; }

inline int uamwAohExampleLLo()
    { return 5; }

inline int uamwAohExampleLHi()
    { return 11; }

inline bool uamwAohHandheldNormalDamage()
    { return true; }

// The familiarization tail
// OCR-scrambles; the
// reconstruction: after each
// week of use, the possessor
// has a 1-in-8 chance (roll
// of 1 on d8) to learn the
// full properties; in any
// event fully known after 8
// full weeks; flagged.
inline int uamwAohFamChanceDie()
    { return 8; }

inline int uamwAohFamWeeksFull()
    { return 8; }

inline bool uamwAohFamTailGarbles()
    { return true; }

// The bonus rides a d20 roll:
// 1-5 +1, 6-10 +2, 11-15 +3,
// 16-19 +4, 20 +5; the XP
// value 1,500 per bonus point,
// the sale value 15,000 gp
// per point.
inline bool uamwAohBonusOnD20()
    { return true; }

inline int uamwAohBand1Lo()
    { return 1; }

inline int uamwAohBand1Hi()
    { return 5; }

inline int uamwAohBand2Lo()
    { return 6; }

inline int uamwAohBand2Hi()
    { return 10; }

inline int uamwAohBand3Lo()
    { return 11; }

inline int uamwAohBand3Hi()
    { return 15; }

inline int uamwAohBand4Lo()
    { return 16; }

inline int uamwAohBand4Hi()
    { return 19; }

inline int uamwAohBand5Lo()
    { return 20; }

inline int uamwAohBand5Hi()
    { return 20; }

inline int uamwAohXpPerPlus()
    { return 1500; }

inline int uamwAohGpPerPlus()
    { return 15000; }

// ---- the bullet of impact
// ----
// A well-cast sling bullet
// bearing minute engraved
// runes, radiating an
// enchantment aura; composed
// of a mixed iron, silver,
// and lead alloy; equal to a
// +1 missile for to-hit
// determination only -
// damage excludes the bonus,
// and it stacks with the
// sling's own bonus.
inline bool uamwBsiWellCastAppearance()
    { return true; }

inline bool uamwBsiMinuteEngravedRunes()
    { return true; }

inline bool uamwBsiEnchantmentAura()
    { return true; }

inline bool uamwBsiIronSilverLeadAlloy()
    { return true; }

inline int uamwBsiToHitBonusOnly()
    { return 1; }

inline bool uamwBsiDamageExcludesBonus()
    { return true; }

inline bool uamwBsiStacksWithSlingBonus()
    { return true; }

// The unadjusted score to hit
// is the base determinant:
// if the die score (without
// any bonus for sling or
// bullet) exceeds the
// minimum required, the
// missile does 2 additional
// points of damage per point
// of difference - in the
// printed example (minimum
// 12), a 13 adds +2, a 14
// adds +4, a 15 adds +8;
// added to the base sling
// bullet damage 2-5/2-7.
inline int uamwBsiExtraDmgPerDiffPoint()
    { return 2; }

inline int uamwBsiExampleMinToHit()
    { return 12; }

inline int uamwBsiExampleRoll13Dmg()
    { return 2; }

inline int uamwBsiExampleRoll14Dmg()
    { return 4; }

inline int uamwBsiExampleRoll15Dmg()
    { return 8; }

inline int uamwBsiBaseDmgSmLo()
    { return 2; }

inline int uamwBsiBaseDmgSmHi()
    { return 5; }

inline int uamwBsiBaseDmgLLo()
    { return 2; }

inline int uamwBsiBaseDmgLHi()
    { return 7; }

// ---- the dagger Longtooth
// ----
// A broad-bladed weapon
// appearing normal or of the
// standard non-special sort;
// wielded by a small
// demi-human (gnome or
// halfling) it lengthens and
// functions as a short sword
// (retaining its +2 bonus),
// yet remains as light and
// handy as a dagger.
inline bool uamwDlgNormalAppearance()
    { return true; }

inline bool uamwDlgBroadBladed()
    { return true; }

inline int uamwDlgBonus()
    { return 2; }

inline bool uamwDlgSmallDemiHumanLengthens()
    { return true; }

inline bool uamwDlgFunctionsAsShortSword()
    { return true; }

inline bool uamwDlgLightAsDagger()
    { return true; }

// It penetrates wood or stone
// as easily as softer
// material, inflicting
// maximum damage against
// either substance.
inline bool uamwDlgPenetratesWoodStone()
    { return true; }

inline bool uamwDlgMaxDamageVsWoodStone()
    { return true; }

// ---- the dagger of
// throwing ----
// Appears a normal weapon but
// radiates a strong dweomer;
// perfectly balanced, superb
// as a ranged weapon when
// thrown by anyone; hurled up
// to 6-inch distance; the
// range cells
// OCR-scramble (the
// short/medium table tail
// truncates); flagged.
inline bool uamwDthNormalButStrongDweomer()
    { return true; }

inline bool uamwDthPerfectBalance()
    { return true; }

inline bool uamwDthSuperbRangedWeapon()
    { return true; }

inline int uamwDthHurledRangeIn()
    { return 6; }

inline bool uamwDthRangeCellsGarbles()
    { return true; }

// A successful thrown hit
// inflicts twice normal
// dagger damage plus the
// dweomer, +1 to +4 on d100:
// 01-35 +1, 36-65 +2, 66-90
// +3, 91-00 +4; XP value 150
// base plus 100 per plus; GP
// sale value 1,500 plus 1,000
// per plus.
inline bool uamwDthTwiceNormalDamage()
    { return true; }

inline int uamwDthBonusLo()
    { return 1; }

inline int uamwDthBonusHi()
    { return 4; }

inline int uamwDthBand1Lo()
    { return 1; }

inline int uamwDthBand1Hi()
    { return 35; }

inline int uamwDthBand2Lo()
    { return 36; }

inline int uamwDthBand2Hi()
    { return 65; }

inline int uamwDthBand3Lo()
    { return 66; }

inline int uamwDthBand3Hi()
    { return 90; }

inline int uamwDthBand4Lo()
    { return 91; }

inline int uamwDthBand4Hi()
    { return 100; }

inline int uamwDthXpBase()
    { return 150; }

inline int uamwDthXpPerPlus()
    { return 100; }

inline int uamwDthGpBase()
    { return 1500; }

inline int uamwDthGpPerPlus()
    { return 1000; }

// ---- the hornblade ----
// A sickle-like blade
// resembling an animal horn,
// from knife size to
// somewhat less than a short
// sword; a close inspection
// is 90% unlikely to reveal
// anything other than a horn
// grip (the handle sentence
// OCR-scrambles); if magic is
// detected for, it radiates a
// faint enchantment dweomer;
// flagged.
inline bool uamwHblSickleLikeAppearance()
    { return true; }

inline bool uamwHblAnimalHornResemblance()
    { return true; }

inline int uamwHblInspectionUnlikelyPct()
    { return 90; }

inline bool uamwHblHandleSentenceGarbles()
    { return true; }

inline bool uamwHblFaintEnchantmentDweomer()
    { return true; }

// Proper pressure in the
// correct place springs out
// a curved blade of great
// strength and sharpness;
// the small versions (knife-
// and dagger-sized) enchant
// to +1 or +2, the largest
// (scimitar-sized) commonly
// +2 or +3; the small are
// throwable, the bonus
// applying to hit and damage.
inline bool uamwHblBladeSpringsOnPressure()
    { return true; }

inline int uamwHblSmallBonusLo()
    { return 1; }

inline int uamwHblSmallBonusHi()
    { return 2; }

inline int uamwHblScimitarBonusLo()
    { return 2; }

inline int uamwHblScimitarBonusHi()
    { return 3; }

inline bool uamwHblSmallThrowable()
    { return true; }

inline bool uamwHblBonusToHitAndDamage()
    { return true; }

// Any class permitted
// sickle-like weapons may use
// it, provided proficiency in
// the appropriate category
// (knife, dagger, or
// scimitar); retractable
// between uses; the value
// table rides d100 - six
// rows.
inline bool uamwHblSickleClassUsers()
    { return true; }

inline bool uamwHblNeedsCategoryProficiency()
    { return true; }

inline bool uamwHblRetractable()
    { return true; }

inline int uamwHblValueTableRows()
    { return 6; }

// The rows: 01-20 knife-sized
// +1 (500 XP, 1,500 gp);
// 21-35 knife-sized +2
// (1,000, 3,000); 36-50
// dagger-sized +1 (750,
// 2,000); 51-70 dagger-sized
// +2 (1,500, 4,000); 71-90
// scimitar-sized +2 (2,000,
// 6,000); 91-00
// scimitar-sized +3 (3,000,
// 9,000).
inline int uamwHblRow1Lo()
    { return 1; }

inline int uamwHblRow1Hi()
    { return 20; }

inline int uamwHblKnifePlus1Xp()
    { return 500; }

inline int uamwHblKnifePlus1Gp()
    { return 1500; }

inline int uamwHblRow2Lo()
    { return 21; }

inline int uamwHblRow2Hi()
    { return 35; }

inline int uamwHblKnifePlus2Xp()
    { return 1000; }

inline int uamwHblKnifePlus2Gp()
    { return 3000; }

inline int uamwHblRow3Lo()
    { return 36; }

inline int uamwHblRow3Hi()
    { return 50; }

inline int uamwHblDaggerPlus1Xp()
    { return 750; }

inline int uamwHblDaggerPlus1Gp()
    { return 2000; }

inline int uamwHblRow4Lo()
    { return 51; }

inline int uamwHblRow4Hi()
    { return 70; }

inline int uamwHblDaggerPlus2Xp()
    { return 1500; }

inline int uamwHblDaggerPlus2Gp()
    { return 4000; }

inline int uamwHblRow5Lo()
    { return 71; }

inline int uamwHblRow5Hi()
    { return 90; }

inline int uamwHblScimPlus2Xp()
    { return 2000; }

inline int uamwHblScimPlus2Gp()
    { return 6000; }

inline int uamwHblRow6Lo()
    { return 91; }

inline int uamwHblRow6Hi()
    { return 100; }

inline int uamwHblScimPlus3Xp()
    { return 3000; }

inline int uamwHblScimPlus3Gp()
    { return 9000; }

// ---- the darts of homing
// ----
// Appear normal projectiles
// but are +3 magic weapons;
// radiating an alteration and
// enchantment dweomer; a hit
// magically returns the dart
// in the same round for
// reuse.
inline bool uamwDhoNormalProjectileAppearance()
    { return true; }

inline int uamwDhoPlusValue()
    { return 3; }

inline bool uamwDhoAlterationEnchantmentDweomer()
    { return true; }

inline bool uamwDhoReturnsSameRound()
    { return true; }

inline bool uamwDhoReusable()
    { return true; }

// Damage 4-9 versus any size
// - a base of 1-6 plus the
// bonus; a miss loses the
// dweomer; twice the range of
// ordinary darts: 3 inches
// short, 8 medium, 9 long.
inline int uamwDhoDamageLo()
    { return 4; }

inline int uamwDhoDamageHi()
    { return 9; }

inline int uamwDhoBaseLo()
    { return 1; }

inline int uamwDhoBaseHi()
    { return 6; }

inline bool uamwDhoMissLosesDweomer()
    { return true; }

inline bool uamwDhoTwiceOrdinaryRange()
    { return true; }

inline int uamwDhoShortRangeIn()
    { return 3; }

inline int uamwDhoMediumRangeIn()
    { return 8; }

inline int uamwDhoLongRangeIn()
    { return 9; }

// ---- the knife buckle ----
// A magical blade whose hilt
// exactly resembles an
// ornament on a large belt
// buckle (or a complete
// smaller buckle); easily
// grasped and drawn from its
// belt-sheath; short but
// very sharp, inflicting
// damage as a larger knife;
// four varieties on d10.
inline bool uamwKbuBuckleOrnamentHilt()
    { return true; }

inline bool uamwKbuEasilyGraspedDrawn()
    { return true; }

inline bool uamwKbuSharpAsLargerKnife()
    { return true; }

inline int uamwKbuVarieties()
    { return 4; }

// The d10 varieties: 1-4 +1
// (100 XP, 1,000 gp); 5-7 +2
// (200, 2,000); 8-9 +3
// (300, 3,000); 10 +4 (400,
// 4,000).
inline int uamwKbuPlus1Lo()
    { return 1; }

inline int uamwKbuPlus1Hi()
    { return 4; }

inline int uamwKbuPlus2Lo()
    { return 5; }

inline int uamwKbuPlus2Hi()
    { return 7; }

inline int uamwKbuPlus3Lo()
    { return 8; }

inline int uamwKbuPlus3Hi()
    { return 9; }

inline int uamwKbuPlus4Lo()
    { return 10; }

inline int uamwKbuPlus4Hi()
    { return 10; }

inline int uamwKbuXpPerPlus()
    { return 100; }

inline int uamwKbuGpPerPlus()
    { return 1000; }

// ---- the magic
// quarterstaff ----
// Appears a normal bronzewood
// staff shod and banded with
// iron; the shaft as strong
// as steel; upon command its
// length alters from as short
// as 6 feet to as long as 12
// (or any length between);
// damage as a quarterstaff,
// base 1-6, with to-hit and
// damage additions by its
// bonus; five varieties on
// d20.
inline bool uamwQstBronzewoodIronShod()
    { return true; }

inline bool uamwQstStrongAsSteel()
    { return true; }

inline bool uamwQstLengthOnCommand()
    { return true; }

inline int uamwQstLengthLoFt()
    { return 6; }

inline int uamwQstLengthHiFt()
    { return 12; }

inline int uamwQstDamageLo()
    { return 1; }

inline int uamwQstDamageHi()
    { return 6; }

inline int uamwQstVarieties()
    { return 5; }

// The d20 varieties: 1-5 +1
// (XP cell blank in print,
// 1,500 gp); 6-9 +2 (500,
// 3,000); 10-13 +3 (750,
// 4,500); 14-17 +4 (1,000,
// 6,000); 18-20 +5 (1,250,
// 7,500).
inline int uamwQstPlus1Lo()
    { return 1; }

inline int uamwQstPlus1Hi()
    { return 5; }

inline int uamwQstPlus2Lo()
    { return 6; }

inline int uamwQstPlus2Hi()
    { return 9; }

inline int uamwQstPlus3Lo()
    { return 10; }

inline int uamwQstPlus3Hi()
    { return 13; }

inline int uamwQstPlus4Lo()
    { return 14; }

inline int uamwQstPlus4Hi()
    { return 17; }

inline int uamwQstPlus5Lo()
    { return 18; }

inline int uamwQstPlus5Hi()
    { return 20; }

inline int uamwQstXpPerPlus()
    { return 250; }

inline int uamwQstGpPerPlus()
    { return 1500; }

// ---- the scimitar of speed
// ----
// Usually +2; enables the
// wielder to always make the
// first attack in a melee
// round, even if some magic
// would otherwise slow speed
// and reaction; the initial
// attack comes in the first
// segment, ahead of any other
// action there.
inline int uamwSscUsualBonus()
    { return 2; }

inline bool uamwSscFirstAttackAlways()
    { return true; }

inline bool uamwSscWorksDespiteSlowing()
    { return true; }

inline bool uamwSscFirstSegmentStrike()
    { return true; }

// It also allows more than
// one strike in some rounds,
// raising the attacks-per-
// melee figure by one place:
// 1 becomes 3/2, and 3/2
// becomes 2; cumulative with
// any other bonus attacks
// (such as a haste spell);
// the round's remaining order
// resolves normally after the
// first attack.
inline bool uamwSscAttacksUpOnePlace()
    { return true; }

inline bool uamwSscOneToThreeHalves()
    { return true; }

inline bool uamwSscThreeHalvesToTwo()
    { return true; }

inline bool uamwSscCumulativeWithBonusAttacks()
    { return true; }

// Variant forms - cutlass,
// tulwar, yatagan - carry 30%
// overall probability, 10%
// each; a 25% chance the
// bonus is other than +2,
// diced on d100.
inline bool uamwSscVariantForms()
    { return true; }

inline int uamwSscVariantTotalPct()
    { return 30; }

inline int uamwSscEachVariantPct()
    { return 10; }

inline int uamwSscVariantCount()
    { return 3; }

inline int uamwSscAlternateBonusChancePct()
    { return 25; }

// The bonus-value table: the
// normal form +2 (3,000 XP,
// 12,000 gp); the alternate
// rolls 01-50 +1 (2,500,
// 9,000); 51-75 +3 (3,500,
// 15,000); 76-90 +4 (4,000,
// 18,000); 91-00 +5 (4,500,
// 21,000).
inline int uamwSscAltPlus1Lo()
    { return 1; }

inline int uamwSscAltPlus1Hi()
    { return 50; }

inline int uamwSscAltPlus3Lo()
    { return 51; }

inline int uamwSscAltPlus3Hi()
    { return 75; }

inline int uamwSscAltPlus4Lo()
    { return 76; }

inline int uamwSscAltPlus4Hi()
    { return 90; }

inline int uamwSscAltPlus5Lo()
    { return 91; }

inline int uamwSscAltPlus5Hi()
    { return 100; }

inline int uamwSscPlus1Xp()
    { return 2500; }

inline int uamwSscPlus1Gp()
    { return 9000; }

inline int uamwSscPlus2Xp()
    { return 3000; }

inline int uamwSscPlus2Gp()
    { return 12000; }

inline int uamwSscPlus3Xp()
    { return 3500; }

inline int uamwSscPlus3Gp()
    { return 15000; }

inline int uamwSscPlus4Xp()
    { return 4000; }

inline int uamwSscPlus4Gp()
    { return 18000; }

inline int uamwSscPlus5Xp()
    { return 4500; }

inline int uamwSscPlus5Gp()
    { return 21000; }

// ---- the part ledger ----
// Nine items: six fully
// clean, three flagged, none
// fully garbled.
inline int uamwPartItemTotal()
    { return 9; }

inline int uamwPartCleanCount()
    { return 6; }

inline int uamwPartFlaggedCount()
    { return 3; }

inline int uamwPartGarbledCount()
    { return 0; }

}   // namespace rules

