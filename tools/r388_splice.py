

# R388: the UA misc weapons
# prose pin round: the pp.
# 105-106 stretch, NINE items
# pin - SIX fully clean (the
# bullet of impact, the
# dagger Longtooth, the darts
# of homing, the knife
# buckle, the magic
# quarterstaff, the scimitar
# of speed) plus THREE
# mechanics-clean with
# flagged holes (the axe of
# hurling's familiarization
# tail, the dagger of
# throwing's range cells,
# the hornblade's handle
# sentence); NOTHING fully
# garbles - the item AMENDED
# with the R388 note, the
# prose pinned, the treasure
# prose sweep complete,
# stays PDF-gated only; the
# R387 seam the armor
# ledger, the R375 seam the
# misc band; the census
# 314 -> 315.
# Pin-era pattern (R322).
# Idempotent; run twice.
import io
import os


NL = '\n'
applied = []
already = []


def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)


# ---- (a) the seed: the R387 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R387 landed 2026-10-12: commit',
    '  5f9b91e, census 314, the UA',
    '  armor and swords prose pin',
    '  round (rules/uaarmprose.h):',
    '  the pp. 104-105 stretch,',
    '  eight items pin - four fully',
    '  clean (the anything armor,',
    '  the short sword of quickness,',
    '  the sword of the planes, the',
    '  anything sword) plus four',
    '  mechanics-clean with flagged',
    '  holes (the elfin chain',
    "  mail's size-table garble, the",
    "  plate's conform seam, the sun",
    "  blade's radiance seam, the",
    '  Final Word broadswords\' names',
    '  tail), riding the construction',
    '  rule (+3 meteorite iron, +4',
    '  mithral alloyed, +5 adamantite',
    '  alloyed steel); nothing fully',
    '  garbles - the item AMENDED,',
    '  the prose pinned, stays',
    '  PDF-gated only; the R386 seam',
    '  the part-6 ledger, the R375',
    '  seam the misc band; GREEN on',
    '  the first run.'
])
s = rd(SD)
if 'R387 landed 2026-10-12' in s:
    already.append('seed: the R387 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R387 record')
s = rd(SD)
assert s.count(
    'R387 landed 2026-10-12'
) == 1, 'a entry'


s = rd(SD)
assert s.count(
    'R386 landed 2026-10-12'
) == 1, 'a R386 kept'


s = rd(SD)
assert s.count(
    'R385 landed 2026-10-12'
) == 1, 'a R385 kept'


s = rd(SD)
assert s.count(
    'R384 landed 2026-10-12'
) == 1, 'a R384 kept'


s = rd(SD)
assert s.count(
    'R383 landed 2026-10-12'
) == 1, 'a R383 kept'


s = rd(SD)
assert s.count(
    'R382 landed 2026-10-12'
) == 1, 'a R382 kept'
assert s.count(
    'R381 landed 2026-10-12'
) == 1, 'a R381 kept'
assert s.count(
    'R380 landed 2026-10-12'
) == 1, 'a R380 kept'
assert s.count(
    'R379 landed 2026-10-12'
) == 1, 'a R379 kept'
assert s.count(
    'R378 landed 2026-10-12'
) == 1, 'a R378 kept'
assert s.count(
    'R377 landed 2026-10-12'
) == 1, 'a R377 kept'
assert s.count(
    'R376 landed 2026-10-12'
) == 1, 'a R376 kept'
assert s.count(
    'R375 landed 2026-10-12'
) == 1, 'a R375 kept'
assert s.count(
    'R374 landed 2026-10-12'
) == 1, 'a R374 kept'
assert s.count(
    'R373 landed 2026-10-12'
) == 1, 'a R373 kept'
assert s.count(
    'R372 landed 2026-10-12'
) == 1, 'a R372 kept'
assert s.count(
    'R371 landed 2026-10-12'
) == 1, 'a R371 kept'
assert s.count(
    'R370 landed 2026-10-12'
) == 1, 'a R370 kept'
assert s.count(
    'R369 landed 2026-10-12'
) == 1, 'a R369 kept'
assert s.count(
    'R368 landed 2026-10-12'
) == 1, 'a R368 kept'
assert s.count(
    'R367 landed 2026-10-12'
) == 1, 'a R367 kept'
assert s.count(
    'R366 landed 2026-10-12'
) == 1, 'a R366 kept'
assert s.count(
    'R365 landed 2026-10-12'
) == 1, 'a R365 kept'
assert s.count(
    'R364 landed 2026-10-11'
) == 1, 'a R364 kept'
assert s.count(
    'R363 landed 2026-10-11'
) == 1, 'a R363 kept'
assert s.count(
    'R362 landed 2026-10-11'
) == 1, 'a R362 kept'
assert s.count(
    'R361 landed 2026-10-11'
) == 1, 'a R361 kept'
assert s.count(
    'R360 landed 2026-10-11'
) == 1, 'a R360 kept'
assert s.count(
    'R359 landed 2026-10-11'
) == 1, 'a R359 kept'
assert s.count(
    'R358 landed 2026-10-11'
) == 1, 'a R358 kept'
assert s.count(
    'R357 landed 2026-10-11'
) == 1, 'a R357 kept'
assert s.count(
    'R356 landed 2026-10-11'
) == 1, 'a R356 kept'
assert s.count(
    'R355 landed 2026-10-11'
) == 1, 'a R355 kept'
assert s.count(
    'R354 landed 2026-10-11'
) == 1, 'a R354 kept'
assert s.count(
    'R352 landed 2026-10-11'
) == 1, 'a R352 kept'
assert s.count(
    'R351 landed 2026-10-11'
) == 1, 'a R351 kept'
assert s.count(
    'R350 landed 2026-10-11'
) == 1, 'a R350 kept'
assert s.count(
    'R349 landed 2026-10-11'
) == 1, 'a R349 kept'
assert s.count(
    'R347 landed 2026-10-11'
) == 1, 'a R347 kept'
assert s.count(
    'R343 landed 2026-10-11'
) == 1, 'a R343 kept'
assert s.count(
    '## Knowledge maintenance'
) == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'


# ---- (b) NEW rules/uamweapprose.h ----
P = 'rules/uamweapprose.h'
if os.path.exists(P) and 'R388' in rd(P):
    already.append('uamweapprose.h: the pins')
else:
    HDR = r"""// ===========================================================================
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
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uamweapprose.h: the pins')


s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 199, 'b inline count'
assert s.count('R388') == 1, 'b round tag'
assert s.count(
    'uamwAohHurledRangeIn'
    ) >= 1, 'b fn'
assert 'uafol' not in s, 'b no uafol ref'
assert 'uanw' not in s, 'b no uanw ref'
assert 'uacm' not in s, 'b no uacm ref'
assert 'uacavt' not in s, 'b no uacavt ref'
assert 'uawt' not in s, 'b no uawt ref'
assert 'uamt' not in s, 'b no uamt ref'
assert 'uatd' not in s, 'b no uatd ref'
assert 'uads' not in s, 'b no uads ref'
assert 'uapp' not in s, 'b no uapp ref'
assert 'uaps' not in s, 'b no uaps ref'
assert 'uarp' not in s, 'b no uarp ref'
assert 'uaro' not in s, 'b no uaro ref'
assert 'uawd' not in s, 'b no uawd ref'
assert 'uam2' not in s, 'b no uam2 ref'
assert 'uamm' not in s, 'b no uamm ref'
assert 'uaasp' not in s, 'b no uaasp ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap report: the
# amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R388' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **The new miscellaneous weapons**',
        '      (pp. 105-106) - the Axe of',
        '      Hurling (the return, the double',
        '      hurled damage, the d20 bonus',
        '      table, the 1500 XP and 15000 gp',
        '      per plus) and the rest; the XP and',
        '      GP value tables read clean.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = OLD + NL + NL.join([
        '      - AMENDED R388: the UA misc',
        '        weapons prose pin round',
        '        (rules/uamweapprose.h) - the',
        '        pp. 105-106 stretch, NINE items',
        '        pin: SIX fully clean (the bullet',
        '        of impact, the dagger Longtooth,',
        '        the darts of homing, the knife',
        '        buckle, the magic quarterstaff,',
        '        the scimitar of speed) plus',
        '        THREE mechanics-clean with',
        '        flagged holes (the axe of',
        "        hurling's familiarization tail,",
        '        the dagger of throwing\'s range',
        '        cells, the hornblade\'s handle',
        '        sentence); NOTHING fully garbles',
        '        - the item AMENDED, the prose',
        '        pinned, the treasure prose sweep',
        '        complete, stays PDF-gated only.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the amendment')
wr(GP, s)


s = rd(GP)
assert s.count(
    '- [ ] **The new miscellaneous magic'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R388'
) == 1, 'c amendment'
assert s.count(
    'AMENDED R387'
) == 1, 'c r387 amendment kept'
assert s.count(
    'AMENDED R386'
) == 1, 'c r386 amendment kept'
assert s.count(
    'AMENDED R385'
) == 1, 'c r385 amendment kept'
assert s.count(
    'AMENDED R384'
) == 1, 'c r384 amendment kept'
assert s.count(
    'AMENDED R383'
) == 1, 'c r383 amendment kept'
assert s.count(
    'AMENDED R382'
) == 1, 'c r382 amendment kept'
assert s.count(
    'AMENDED R381'
) == 1, 'c r381 amendment kept'
assert s.count(
    'AMENDED R380'
) == 1, 'c r380 amendment kept'
assert s.count(
    'AMENDED R379'
) == 1, 'c r379 amendment kept'
assert s.count(
    'AMENDED R378'
) == 1, 'c r378 amendment kept'
assert s.count(
    'AMENDED R377'
) == 1, 'c r377 amendment kept'
assert s.count(
    'AMENDED R376'
) == 1, 'c r376 amendment kept'
assert s.count(
    'AMENDED R375'
) == 1, 'c r375 amendment kept'
assert s.count(
    '(rules/uamiscprose2.h)'
) == 1, 'c misc2 note kept'
assert s.count(
    '(rules/uamweapprose.h)'
) == 1, 'c mweapprose note'
assert s.count(
    '(rules/uaarmprose.h)'
) == 1, 'c armprose note kept'
assert s.count(
    '(rules/uamiscprose6.h)'
) == 1, 'c misc6 note kept'
assert s.count(
    '(rules/uamiscprose5.h)'
) == 1, 'c misc5 note kept'
assert s.count(
    '(rules/uamiscprose4.h)'
) == 1, 'c misc4 note kept'
assert s.count(
    '(rules/uamiscprose3.h)'
) == 1, 'c misc3 note kept'
assert s.count(
    '(rules/uamiscprose1.h)'
) == 1, 'c misc note kept'
assert s.count(
    '(rules/uawandprose.h)'
) == 1, 'c wands note kept'
assert s.count(
    '(rules/uarodstave.h)'
) == 1, 'c rods note kept'
assert s.count(
    '(rules/uaringprose.h)'
) == 1, 'c rings note kept'
assert s.count(
    '(rules/uaprotscr.h)'
) == 1, 'c scrolls note kept'
assert s.count(
    '(rules/uapotprose.h)'
) == 1, 'c potions note kept'
assert s.count(
    '(rules/uadetskel.h)'
) == 1, 'c skeleton note kept'
assert s.count(
    'DECIDED R374'
) == 1, 'c r374 decision kept'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert s.count(
    '- [ ] **The random determination'
) == 1, 'c det tables kept open'
assert s.count(
    '- [ ] **The new potions**'
) == 1, 'c potions kept open'
assert s.count(
    '- [ ] **The new scrolls**'
) == 1, 'c scrolls kept open'
assert s.count(
    '- [ ] **The new rings**'
) == 1, 'c rings kept open'
assert s.count(
    '- [ ] **The new rods and staves**'
) == 1, 'c rods staves kept open'
assert s.count(
    '- [ ] **The new wands**'
) == 1, 'c wands kept open'
assert s.count(
    '- [ ] **The new armor and shields and'
) == 1, 'c armor shields kept open'
assert s.count(
    '- [ ] **The new miscellaneous weapons**'
) == 1, 'c misc weapons kept open'
assert s.count(
    '- [x] **The comeliness creation note**'
) == 1, 'c r373 note kept closed'
assert s.count(
    '- [x] **The cavalier follower tables**'
) == 1, 'c r372 kept closed'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c armor class table kept open'
assert len(applied) + len(already) == 3, 'c count'


# ---- (d) regtest.cpp: the
# includes, the audit, the
# census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R388 UA misc weapons prose pin audit' in s:
    already.append('regtest.cpp: the R388 audit')
else:
    INC_ANCH = ('#include "rules/uaarmprose.h"  // '
        'R387: the UA armor prose')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamweapprose.h"  // R388: the UA misc weapons prose'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R388: the UA misc
    // weapons prose pin audit ----
    // The pp. 105-106 stretch:
    // nine pins - six fully
    // clean (the bullet of
    // impact, the dagger
    // Longtooth, the darts of
    // homing, the knife buckle,
    // the magic quarterstaff,
    // the scimitar of speed)
    // plus three
    // mechanics-clean with
    // flagged holes (the axe
    // of hurling's
    // familiarization tail, the
    // dagger of throwing's
    // range cells, the
    // hornblade's handle
    // sentence); the R387 seam
    // the armor ledger, the
    // R375 seam the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the axe of hurling
        // ----
            if (!uamwAohNormalHandAxeAppearance())
                ++bad;
            if (uamwAohHurledRangeIn() != 6) ++bad;
            if (!uamwAohReturnsSameRound()) ++bad;
            if (!uamwAohReturnsHitOrMiss()) ++bad;
            if (!uamwAohThrownDamageDoubled())
                ++bad;
            if (uamwAohThrownSmLo() != 2) ++bad;
            if (uamwAohThrownSmHi() != 12) ++bad;
            if (uamwAohThrownLLo() != 2) ++bad;
            if (uamwAohThrownLHi() != 8) ++bad;
            if (!uamwAohBonusAddedAfter()) ++bad;
            if (uamwAohExampleBonus() != 3) ++bad;
            if (uamwAohExampleSmLo() != 5) ++bad;
            if (uamwAohExampleSmHi() != 15) ++bad;
            if (uamwAohExampleLLo() != 5) ++bad;
            if (uamwAohExampleLHi() != 11) ++bad;
            if (!uamwAohHandheldNormalDamage())
                ++bad;
            if (uamwAohFamChanceDie() != 8) ++bad;
            if (uamwAohFamWeeksFull() != 8) ++bad;
            if (!uamwAohFamTailGarbles()) ++bad;
            if (!uamwAohBonusOnD20()) ++bad;
            if (uamwAohBand1Lo() != 1) ++bad;
            if (uamwAohBand1Hi() != 5) ++bad;
            if (uamwAohBand2Lo() != 6) ++bad;
            if (uamwAohBand2Hi() != 10) ++bad;
            if (uamwAohBand3Lo() != 11) ++bad;
            if (uamwAohBand3Hi() != 15) ++bad;
            if (uamwAohBand4Lo() != 16) ++bad;
            if (uamwAohBand4Hi() != 19) ++bad;
            if (uamwAohBand5Lo() != 20) ++bad;
            if (uamwAohBand5Hi() != 20) ++bad;
            if (uamwAohXpPerPlus() != 1500) ++bad;
            if (uamwAohGpPerPlus() != 15000) ++bad;
            // the d20 bands tile the
            // die exactly, 5+5+5+4+1
            if (uamwAohBand1Hi() - uamwAohBand1Lo()
                    + 1 + uamwAohBand2Hi()
                    - uamwAohBand2Lo() + 1
                    + uamwAohBand3Hi()
                    - uamwAohBand3Lo() + 1
                    + uamwAohBand4Hi()
                    - uamwAohBand4Lo() + 1
                    + uamwAohBand5Hi()
                    - uamwAohBand5Lo() + 1
                    != 20) ++bad;
            // the +3 example adds
            // the bonus over the
            // doubled dice, 2+3 to
            // 12+3 and 2+3 to 8+3
            if (uamwAohThrownSmLo()
                    + uamwAohExampleBonus()
                    != uamwAohExampleSmLo()) ++bad;
            if (uamwAohThrownSmHi()
                    + uamwAohExampleBonus()
                    != uamwAohExampleSmHi()) ++bad;
            if (uamwAohThrownLLo()
                    + uamwAohExampleBonus()
                    != uamwAohExampleLLo()) ++bad;
            if (uamwAohThrownLHi()
                    + uamwAohExampleBonus()
                    != uamwAohExampleLHi()) ++bad;
            // the sale value is
            // ten times the XP per
            // plus
            if (10 * uamwAohXpPerPlus()
                    != uamwAohGpPerPlus()) ++bad;
        // ---- the bullet of
        // impact ----
            if (!uamwBsiWellCastAppearance())
                ++bad;
            if (!uamwBsiMinuteEngravedRunes())
                ++bad;
            if (!uamwBsiEnchantmentAura()) ++bad;
            if (!uamwBsiIronSilverLeadAlloy())
                ++bad;
            if (uamwBsiToHitBonusOnly() != 1)
                ++bad;
            if (!uamwBsiDamageExcludesBonus())
                ++bad;
            if (!uamwBsiStacksWithSlingBonus())
                ++bad;
            if (uamwBsiExtraDmgPerDiffPoint()
                    != 2) ++bad;
            if (uamwBsiExampleMinToHit() != 12)
                ++bad;
            if (uamwBsiExampleRoll13Dmg() != 2)
                ++bad;
            if (uamwBsiExampleRoll14Dmg() != 4)
                ++bad;
            if (uamwBsiExampleRoll15Dmg() != 8)
                ++bad;
            if (uamwBsiBaseDmgSmLo() != 2) ++bad;
            if (uamwBsiBaseDmgSmHi() != 5) ++bad;
            if (uamwBsiBaseDmgLLo() != 2) ++bad;
            if (uamwBsiBaseDmgLHi() != 7) ++bad;
            // the example ladder:
            // each point of die
            // difference doubles
            // through the extras,
            // 2, 4, 8
            if (2 * uamwBsiExampleRoll13Dmg()
                    != uamwBsiExampleRoll14Dmg())
                ++bad;
            if (2 * uamwBsiExampleRoll14Dmg()
                    != uamwBsiExampleRoll15Dmg())
                ++bad;
            // the base damage bands
            // ride 2-5 and 2-7
            if (uamwBsiBaseDmgSmLo()
                    >= uamwBsiBaseDmgSmHi()) ++bad;
            if (uamwBsiBaseDmgLLo()
                    >= uamwBsiBaseDmgLHi()) ++bad;
        // ---- the dagger
        // Longtooth ----
            if (!uamwDlgNormalAppearance()) ++bad;
            if (!uamwDlgBroadBladed()) ++bad;
            if (uamwDlgBonus() != 2) ++bad;
            if (!uamwDlgSmallDemiHumanLengthens())
                ++bad;
            if (!uamwDlgFunctionsAsShortSword())
                ++bad;
            if (!uamwDlgLightAsDagger()) ++bad;
            if (!uamwDlgPenetratesWoodStone())
                ++bad;
            if (!uamwDlgMaxDamageVsWoodStone())
                ++bad;
        // ---- the dagger of
        // throwing ----
            if (!uamwDthNormalButStrongDweomer())
                ++bad;
            if (!uamwDthPerfectBalance()) ++bad;
            if (!uamwDthSuperbRangedWeapon()) ++bad;
            if (uamwDthHurledRangeIn() != 6) ++bad;
            if (!uamwDthRangeCellsGarbles()) ++bad;
            if (!uamwDthTwiceNormalDamage())
                ++bad;
            if (uamwDthBonusLo() != 1) ++bad;
            if (uamwDthBonusHi() != 4) ++bad;
            if (uamwDthBand1Lo() != 1) ++bad;
            if (uamwDthBand1Hi() != 35) ++bad;
            if (uamwDthBand2Lo() != 36) ++bad;
            if (uamwDthBand2Hi() != 65) ++bad;
            if (uamwDthBand3Lo() != 66) ++bad;
            if (uamwDthBand3Hi() != 90) ++bad;
            if (uamwDthBand4Lo() != 91) ++bad;
            if (uamwDthBand4Hi() != 100) ++bad;
            if (uamwDthXpBase() != 150) ++bad;
            if (uamwDthXpPerPlus() != 100) ++bad;
            if (uamwDthGpBase() != 1500) ++bad;
            if (uamwDthGpPerPlus() != 1000) ++bad;
            // the d100 bands tile
            // exactly, 35+30+25+10
            if (uamwDthBand1Hi() - uamwDthBand1Lo()
                    + 1 + uamwDthBand2Hi()
                    - uamwDthBand2Lo() + 1
                    + uamwDthBand3Hi()
                    - uamwDthBand3Lo() + 1
                    + uamwDthBand4Hi()
                    - uamwDthBand4Lo() + 1
                    != 100) ++bad;
            // the gp rate is ten
            // times the xp rate,
            // base and per plus
            if (10 * uamwDthXpBase()
                    != uamwDthGpBase()) ++bad;
            if (10 * uamwDthXpPerPlus()
                    != uamwDthGpPerPlus()) ++bad;
        // ---- the hornblade ----
            if (!uamwHblSickleLikeAppearance())
                ++bad;
            if (!uamwHblAnimalHornResemblance())
                ++bad;
            if (uamwHblInspectionUnlikelyPct()
                    != 90) ++bad;
            if (!uamwHblHandleSentenceGarbles())
                ++bad;
            if (!uamwHblFaintEnchantmentDweomer())
                ++bad;
            if (!uamwHblBladeSpringsOnPressure())
                ++bad;
            if (uamwHblSmallBonusLo() != 1) ++bad;
            if (uamwHblSmallBonusHi() != 2) ++bad;
            if (uamwHblScimitarBonusLo() != 2)
                ++bad;
            if (uamwHblScimitarBonusHi() != 3)
                ++bad;
            if (!uamwHblSmallThrowable()) ++bad;
            if (!uamwHblBonusToHitAndDamage())
                ++bad;
            if (!uamwHblSickleClassUsers()) ++bad;
            if (!uamwHblNeedsCategoryProficiency())
                ++bad;
            if (!uamwHblRetractable()) ++bad;
            if (uamwHblValueTableRows() != 6)
                ++bad;
            if (uamwHblRow1Lo() != 1) ++bad;
            if (uamwHblRow1Hi() != 20) ++bad;
            if (uamwHblKnifePlus1Xp() != 500) ++bad;
            if (uamwHblKnifePlus1Gp() != 1500)
                ++bad;
            if (uamwHblRow2Lo() != 21) ++bad;
            if (uamwHblRow2Hi() != 35) ++bad;
            if (uamwHblKnifePlus2Xp() != 1000)
                ++bad;
            if (uamwHblKnifePlus2Gp() != 3000)
                ++bad;
            if (uamwHblRow3Lo() != 36) ++bad;
            if (uamwHblRow3Hi() != 50) ++bad;
            if (uamwHblDaggerPlus1Xp() != 750) ++bad;
            if (uamwHblDaggerPlus1Gp() != 2000)
                ++bad;
            if (uamwHblRow4Lo() != 51) ++bad;
            if (uamwHblRow4Hi() != 70) ++bad;
            if (uamwHblDaggerPlus2Xp() != 1500)
                ++bad;
            if (uamwHblDaggerPlus2Gp() != 4000)
                ++bad;
            if (uamwHblRow5Lo() != 71) ++bad;
            if (uamwHblRow5Hi() != 90) ++bad;
            if (uamwHblScimPlus2Xp() != 2000) ++bad;
            if (uamwHblScimPlus2Gp() != 6000)
                ++bad;
            if (uamwHblRow6Lo() != 91) ++bad;
            if (uamwHblRow6Hi() != 100) ++bad;
            if (uamwHblScimPlus3Xp() != 3000) ++bad;
            if (uamwHblScimPlus3Gp() != 9000)
                ++bad;
            // the six rows tile the
            // d100, 20+15+15+20+20+10
            if (uamwHblRow1Hi() - uamwHblRow1Lo()
                    + 1 + uamwHblRow2Hi()
                    - uamwHblRow2Lo() + 1
                    + uamwHblRow3Hi()
                    - uamwHblRow3Lo() + 1
                    + uamwHblRow4Hi()
                    - uamwHblRow4Lo() + 1
                    + uamwHblRow5Hi()
                    - uamwHblRow5Lo() + 1
                    + uamwHblRow6Hi()
                    - uamwHblRow6Lo() + 1
                    != 100) ++bad;
            // the knife and scimitar
            // rows sell at thrice
            // their XP
            if (3 * uamwHblKnifePlus1Xp()
                    != uamwHblKnifePlus1Gp()) ++bad;
            if (3 * uamwHblScimPlus3Xp()
                    != uamwHblScimPlus3Gp()) ++bad;
        // ---- the darts of
        // homing ----
            if (!uamwDhoNormalProjectileAppearance())
                ++bad;
            if (uamwDhoPlusValue() != 3) ++bad;
            if (!uamwDhoAlterationEnchantmentDweomer())
                ++bad;
            if (!uamwDhoReturnsSameRound()) ++bad;
            if (!uamwDhoReusable()) ++bad;
            if (uamwDhoDamageLo() != 4) ++bad;
            if (uamwDhoDamageHi() != 9) ++bad;
            if (uamwDhoBaseLo() != 1) ++bad;
            if (uamwDhoBaseHi() != 6) ++bad;
            if (!uamwDhoMissLosesDweomer()) ++bad;
            if (!uamwDhoTwiceOrdinaryRange())
                ++bad;
            if (uamwDhoShortRangeIn() != 3) ++bad;
            if (uamwDhoMediumRangeIn() != 8) ++bad;
            if (uamwDhoLongRangeIn() != 9) ++bad;
            // the damage band is
            // the base plus the
            // bonus, 1+3 to 6+3
            if (uamwDhoBaseLo() + uamwDhoPlusValue()
                    != uamwDhoDamageLo()) ++bad;
            if (uamwDhoBaseHi() + uamwDhoPlusValue()
                    != uamwDhoDamageHi()) ++bad;
        // ---- the knife buckle
        // ----
            if (!uamwKbuBuckleOrnamentHilt())
                ++bad;
            if (!uamwKbuEasilyGraspedDrawn())
                ++bad;
            if (!uamwKbuSharpAsLargerKnife())
                ++bad;
            if (uamwKbuVarieties() != 4) ++bad;
            if (uamwKbuPlus1Lo() != 1) ++bad;
            if (uamwKbuPlus1Hi() != 4) ++bad;
            if (uamwKbuPlus2Lo() != 5) ++bad;
            if (uamwKbuPlus2Hi() != 7) ++bad;
            if (uamwKbuPlus3Lo() != 8) ++bad;
            if (uamwKbuPlus3Hi() != 9) ++bad;
            if (uamwKbuPlus4Lo() != 10) ++bad;
            if (uamwKbuPlus4Hi() != 10) ++bad;
            if (uamwKbuXpPerPlus() != 100) ++bad;
            if (uamwKbuGpPerPlus() != 1000) ++bad;
            // the d10 bands tile,
            // 4+3+2+1
            if (uamwKbuPlus1Hi() - uamwKbuPlus1Lo()
                    + 1 + uamwKbuPlus2Hi()
                    - uamwKbuPlus2Lo() + 1
                    + uamwKbuPlus3Hi()
                    - uamwKbuPlus3Lo() + 1
                    + uamwKbuPlus4Hi()
                    - uamwKbuPlus4Lo() + 1
                    != 10) ++bad;
            // the sale value is ten
            // times the XP per plus
            if (10 * uamwKbuXpPerPlus()
                    != uamwKbuGpPerPlus()) ++bad;
        // ---- the magic
        // quarterstaff ----
            if (!uamwQstBronzewoodIronShod())
                ++bad;
            if (!uamwQstStrongAsSteel()) ++bad;
            if (!uamwQstLengthOnCommand()) ++bad;
            if (uamwQstLengthLoFt() != 6) ++bad;
            if (uamwQstLengthHiFt() != 12) ++bad;
            if (uamwQstDamageLo() != 1) ++bad;
            if (uamwQstDamageHi() != 6) ++bad;
            if (uamwQstVarieties() != 5) ++bad;
            if (uamwQstPlus1Lo() != 1) ++bad;
            if (uamwQstPlus1Hi() != 5) ++bad;
            if (uamwQstPlus2Lo() != 6) ++bad;
            if (uamwQstPlus2Hi() != 9) ++bad;
            if (uamwQstPlus3Lo() != 10) ++bad;
            if (uamwQstPlus3Hi() != 13) ++bad;
            if (uamwQstPlus4Lo() != 14) ++bad;
            if (uamwQstPlus4Hi() != 17) ++bad;
            if (uamwQstPlus5Lo() != 18) ++bad;
            if (uamwQstPlus5Hi() != 20) ++bad;
            if (uamwQstXpPerPlus() != 250) ++bad;
            if (uamwQstGpPerPlus() != 1500) ++bad;
            // the d20 bands tile,
            // 5+4+4+4+3
            if (uamwQstPlus1Hi() - uamwQstPlus1Lo()
                    + 1 + uamwQstPlus2Hi()
                    - uamwQstPlus2Lo() + 1
                    + uamwQstPlus3Hi()
                    - uamwQstPlus3Lo() + 1
                    + uamwQstPlus4Hi()
                    - uamwQstPlus4Lo() + 1
                    + uamwQstPlus5Hi()
                    - uamwQstPlus5Lo() + 1
                    != 20) ++bad;
            // the commanded length
            // doubles, 6 to 12
            if (2 * uamwQstLengthLoFt()
                    != uamwQstLengthHiFt()) ++bad;
            // the gp rate is six
            // times the xp rate
            if (6 * uamwQstXpPerPlus()
                    != uamwQstGpPerPlus()) ++bad;
        // ---- the scimitar of
        // speed ----
            if (uamwSscUsualBonus() != 2) ++bad;
            if (!uamwSscFirstAttackAlways()) ++bad;
            if (!uamwSscWorksDespiteSlowing())
                ++bad;
            if (!uamwSscFirstSegmentStrike()) ++bad;
            if (!uamwSscAttacksUpOnePlace()) ++bad;
            if (!uamwSscOneToThreeHalves()) ++bad;
            if (!uamwSscThreeHalvesToTwo()) ++bad;
            if (!uamwSscCumulativeWithBonusAttacks())
                ++bad;
            if (!uamwSscVariantForms()) ++bad;
            if (uamwSscVariantTotalPct() != 30)
                ++bad;
            if (uamwSscEachVariantPct() != 10) ++bad;
            if (uamwSscVariantCount() != 3) ++bad;
            if (uamwSscAlternateBonusChancePct()
                    != 25) ++bad;
            if (uamwSscAltPlus1Lo() != 1) ++bad;
            if (uamwSscAltPlus1Hi() != 50) ++bad;
            if (uamwSscAltPlus3Lo() != 51) ++bad;
            if (uamwSscAltPlus3Hi() != 75) ++bad;
            if (uamwSscAltPlus4Lo() != 76) ++bad;
            if (uamwSscAltPlus4Hi() != 90) ++bad;
            if (uamwSscAltPlus5Lo() != 91) ++bad;
            if (uamwSscAltPlus5Hi() != 100) ++bad;
            if (uamwSscPlus1Xp() != 2500) ++bad;
            if (uamwSscPlus1Gp() != 9000) ++bad;
            if (uamwSscPlus2Xp() != 3000) ++bad;
            if (uamwSscPlus2Gp() != 12000) ++bad;
            if (uamwSscPlus3Xp() != 3500) ++bad;
            if (uamwSscPlus3Gp() != 15000) ++bad;
            if (uamwSscPlus4Xp() != 4000) ++bad;
            if (uamwSscPlus4Gp() != 18000) ++bad;
            if (uamwSscPlus5Xp() != 4500) ++bad;
            if (uamwSscPlus5Gp() != 21000) ++bad;
            // the three variant
            // forms at 10% each sum
            // to the 30% overall
            if (uamwSscVariantCount()
                    * uamwSscEachVariantPct()
                    != uamwSscVariantTotalPct()) ++bad;
            // the alternate bonus
            // bands tile the d100,
            // 50+25+15+10
            if (uamwSscAltPlus1Hi()
                    - uamwSscAltPlus1Lo() + 1
                    + uamwSscAltPlus3Hi()
                    - uamwSscAltPlus3Lo() + 1
                    + uamwSscAltPlus4Hi()
                    - uamwSscAltPlus4Lo() + 1
                    + uamwSscAltPlus5Hi()
                    - uamwSscAltPlus5Lo() + 1
                    != 100) ++bad;
            // the xp and gp ladders
            // climb in even steps,
            // 500 and 3,000, from
            // the +1 to the +5 row
            if (uamwSscPlus2Xp() - uamwSscPlus1Xp()
                    != 500) ++bad;
            if (uamwSscPlus3Xp() - uamwSscPlus2Xp()
                    != 500) ++bad;
            if (uamwSscPlus4Xp() - uamwSscPlus3Xp()
                    != 500) ++bad;
            if (uamwSscPlus5Xp() - uamwSscPlus4Xp()
                    != 500) ++bad;
            if (uamwSscPlus2Gp() - uamwSscPlus1Gp()
                    != 3000) ++bad;
            if (uamwSscPlus3Gp() - uamwSscPlus2Gp()
                    != 3000) ++bad;
            if (uamwSscPlus4Gp() - uamwSscPlus3Gp()
                    != 3000) ++bad;
            if (uamwSscPlus5Gp() - uamwSscPlus4Gp()
                    != 3000) ++bad;
        // ---- the part ledger ----
            if (uamwPartItemTotal() != 9) ++bad;
            if (uamwPartCleanCount() != 6) ++bad;
            if (uamwPartFlaggedCount() != 3) ++bad;
            if (uamwPartGarbledCount() != 0) ++bad;
            if (uamwPartCleanCount()
                    + uamwPartFlaggedCount()
                    + uamwPartGarbledCount()
                    != uamwPartItemTotal()) ++bad;
        // ---- the R387 armor seam ----
            if (uaaspPartItemTotal() != 8) ++bad;
            if (uaaspPartCleanCount() != 4) ++bad;
            if (uaaspPartFlaggedCount() != 4)
                ++bad;
            if (uaaspPartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R388 UA misc weapons prose pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R388 audit')


s = rd(RT)
assert s.count(
    'R388 UA misc weapons prose pin audit: bad '
) == 1, 'd audit line'
assert s.count(
    'R387 UA armor and swords prose pin audit: bad '
) == 1, 'd r387 kept'
assert s.count(
    'R386 UA misc magic prose part 6 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R385 UA misc magic prose part 5 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R384 UA misc magic prose part 4 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R383 UA misc magic prose part 3 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R382 UA misc magic prose part 2 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R381 UA misc magic prose part 1 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R380 UA new wands prose pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R379 UA new rods staves prose pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R378 UA new rings prose pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R377 UA new scrolls protection pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R376 UA new potions prose part 1 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R375 UA determination skeleton pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R374 UA treasure dial pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R373 UA comeliness note pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R372 UA cavalier followers pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R371 UA expanded armor pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R370 UA DM-section smalls pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R369 UA cantrip acquisition pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R368 UA Cavaliers Table I pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R367 UA social/birth pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R366 UA DM-section spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R365 UA IL 6th/7th and DM pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R364 UA IL 3rd/4th/5th spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R363 UA IL cantrips/1st/2nd pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R362 UA MU 8th/9th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R361 UA MU 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R360 UA MU 5th/6th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R359 UA MU 4th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R358 UA MU 3rd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R357 UA MU 2nd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R356 UA MU 1st level spells pin audit: bad '
) == 1, 'd kept'
assert s.count('audit: bad ') == 315, 'd census 315'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uamweapprose.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uaarmprose.h"'
) == 1, 'd r387 include kept'
assert s.count(
    '#include "rules/uamiscprose6.h"'
) == 1, 'd kept include'
for h in (
        'rules/cavalier.h',
        'rules/classtables.h',
        'rules/uabirth.h',
        'rules/uasocialclass.h',
        'rules/uaspellbooks.h',
        'rules/uaspellcomment.h',
        'rules/uauwspelluse.h',
        'rules/uadarkness.h',
        'rules/uacavtable.h',
        'rules/uacantacq.h',
        'rules/uasmalls1.h',
        'rules/uailacquisition.h',
        'rules/thiefarmor.h',
        'rules/armorratings.h',
        'rules/comeliness.h',
        'rules/uaweapontable.h',
        'rules/uamissile.h',
        'rules/uanewweapons.h',
        'rules/uafollowers.h',
        'rules/uacomnote.h',
        'rules/uatreasuredial.h',
        'rules/uadetskel.h',
        'rules/uapotprose.h',
        'rules/uaprotscr.h',
        'rules/uaringprose.h',
        'rules/uarodstave.h',
        'rules/uawandprose.h',
        'rules/uamiscprose1.h',
        'rules/uamiscprose2.h',
        'rules/uamiscprose3.h',
        'rules/uamiscprose4.h',
        'rules/uamiscprose5.h',
        'rules/uamiscprose6.h',
        'rules/uaarmprose.h',
        'rules/treasdet.h',
        'rules/hoard.h'):
    assert s.count(
        '#include "' + h + '"'
        ) == 1, 'd kept include'
for i in range(1, 8):
    assert s.count(
        '#include "rules/uailspells%d.h"'
        % i) == 1, 'd il include'
for i in range(1, 10):
    assert s.count(
        '#include "rules/uamuspells%d.h"'
        % i) == 1, 'd mu include'
assert len(applied) + len(already) == 4, 'd count'


# ---- the summary ----
print(
    'R388 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R388 note: the UA misc',
    'weapons prose round - the',
    'pp. 105-106 stretch, nine',
    'items pin: six fully clean',
    '(the bullet of impact, the',
    'dagger Longtooth, the darts',
    'of homing, the knife buckle,',
    'the magic quarterstaff, the',
    'scimitar of speed) plus',
    'three mechanics-clean with',
    'flagged holes (the axe of',
    'hurling, the dagger of',
    'throwing, the hornblade);',
    'nothing fully garbles - the',
    'item AMENDED, the prose',
    'pinned, the treasure prose',
    'sweep complete, stays',
    'PDF-gated only; the R387',
    'seam the armor ledger, the',
    'R375 seam the misc band;',
    'the census 314 -> 315'
])
print(NOTE)
print('commit: R388: the UA misc')
print('weapons prose pin round')
print('(census 315)')

