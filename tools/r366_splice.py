# R366: the UA DM-section spells
# pin round - the four items
# (pp. 79-83): the MU spell book rules
# (the capacities, the costs, the
# physical aspects, the values, the
# direct-casting and learning reads),
# the spell explanations commentary
# (the permanency lists and the
# Serten's immunity), the underwater
# spell use lists and the effects of
# darkness; all four flip CLOSED.
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


# ---- (a) the seed: the R365 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R365 landed 2026-10-12: commit',
    '  d7bb603, census 292, the UA new',
    '  illusionist 6th/7th levels,',
    '  acquisition and cost pin round',
    '  (rules/uailspells6.h,',
    '  rules/uailspells7.h,',
    '  rules/uailacquisition.h and',
    '  rules/uaspellcost.h): death fog,',
    '  mislead, phantasmagoria and the',
    '  mirage arcane at the printed 6th',
    '  (the item-list 7th divergence',
    '  flagged pending the PDF), shadow',
    '  walk and weird at 7th; the IL',
    '  spells item CLOSED - all printed',
    '  levels pinned R363-R365; the',
    '  acquisition item stays open (the',
    '  row boundaries garble); GREEN on',
    '  the first run.',
])
s = rd(SD)
if 'R365 landed 2026-10-12' in s:
    already.append('seed: the R365 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R365 record')
s = rd(SD)
assert s.count(
    'R365 landed 2026-10-12'
) == 1, 'a entry'
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


# ---- (b) NEW rules/uaspellbooks.h ----
P = 'rules/uaspellbooks.h'
if os.path.exists(P) and 'R366' in rd(P):
    already.append('uaspellbooks: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaspellbooks.h
// The UA MAGIC-USER SPELL BOOKS (pp. 79-80 print) pins,
// R366: the book types and capacities, the costs, the
// physical aspects, the values and the direct-casting
// and learning rules.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The section general note applies equally
// to illusionists; the illusionist-side exceptions pin
// in the R365 acquisition header.
//
// JUDGMENTs (the decode method):
//   - the section opening garbles (the one-or-two
//     starting books read survives in the cost
//     paragraph); the readable facts pin, the rest is
//     a hole pending the PDF.
//   - the standard-book encumbrance cell and the
//     travelling-book thickness/weight/encumbrance
//     cells garble - holes, no numeric pin, pending
//     the PDF; the travelling 500 gp cost prints as a
//     fragment ("costs such a 500 gold") and pins
//     flagged.
//   - the direct-casting neighbor-destroy chance
//     prints 1 percent per level of the spell; the
//     whole-book chance prints a flat 1 percent.
// ===========================================================================

#pragma once

namespace rules {

// ---- the standard book capacities ----
inline int uabkStandardCantripsCapacity()
    { return 36; }

inline int uabkStandardLowLevelSpells()
    { return 24; }

inline int uabkStandardMidLevelSpells()
    { return 16; }

inline int uabkStandardHighLevelSpells()
    { return 8; }

// ---- the travelling book (one-fourth) ----
inline bool uabkTravellingIsOneFourth()
    { return true; }

inline int uabkTravellingCantripsCapacity()
    { return 9; }

inline int uabkTravellingLowLevelSpells()
    { return 6; }

inline int uabkTravellingMidLevelSpells()
    { return 4; }

inline int uabkTravellingHighLevelSpells()
    { return 2; }

// ---- the costs ----
// A standard spell book costs 1,000 gp for materials
// plus 100 gp per spell level for each spell contained
// therein; cantrips count as 1st-level spells.
inline int uabkStandardMaterialsCostGp()
    { return 1000; }

inline int uabkPerSpellLevelCostGp()
    { return 100; }

inline bool uabkCantripsCountAsFirstLevel()
    { return true; }

// The new caster's former master bears the cost of
// the initial book or books (one or two, at no cost).
inline bool uabkInitialBooksBorneByMaster()
    { return true; }

inline int uabkInitialBookCountMax()
    { return 2; }

// Later books are composed during the training to rise
// to a higher experience level: 4-7 weeks per new
// standard book.
inline bool uabkLaterBooksSelfComposed()
    { return true; }

inline int uabkCompositionWeeksMin()
    { return 4; }

inline int uabkCompositionWeeksMax()
    { return 7; }

inline bool uabkCompositionRidesLevelTraining()
    { return true; }

// The printed examples: entering a 1st-level spell
// costs 100 gp, a 2nd-level spell 200 gp.
inline int uabkEnterFirstLevelCostGp()
    { return 100; }

inline int uabkEnterSecondLevelCostGp()
    { return 200; }

// The travelling-book cost fragment (the cell garbles
// around a readable "such a 500 gold").
inline int uabkTravellingCostFragmentGp()
    { return 500; }

inline bool uabkTravellingCostIsFragmentRead()
    { return true; }

// ---- the standard book physical aspects ----
inline int uabkStandardHeightInches()
    { return 16; }

inline int uabkStandardWidthInches()
    { return 12; }

inline int uabkStandardThicknessInches()
    { return 6; }

// The DM has leeway to reduce or enlarge this general
// size (nothing smaller than 12x12x6 or larger than
// 18x12x9 is recommended).
inline bool uabkDmMayResizeTheBook()
    { return true; }

inline int uabkMinSizeHeightInches()
    { return 12; }

inline int uabkMinSizeWidthInches()
    { return 12; }

inline int uabkMinSizeThicknessInches()
    { return 6; }

inline int uabkMaxSizeHeightInches()
    { return 18; }

inline int uabkMaxSizeWidthInches()
    { return 12; }

inline int uabkMaxSizeThicknessInches()
    { return 9; }

// The weight of a standard book of median size is 150
// gold pieces (adjusted for varying sizes); the
// encumbrance cell garbles - a hole.
inline int uabkMedianWeightGp()
    { return 150; }

inline bool uabkWeightAdjustedForSize()
    { return true; }

inline bool uabkEncumbranceCellLost()
    { return true; }

inline bool uabkFitsBackpackOrLargeSack()
    { return true; }

// The cover is heavy leather (dragon hide or similar)
// inlaid with metal for durability and closing; vellum
// pages are sewn and secured to a leather spine backing
// with vellum stubs for added pages.
inline bool uabkCoverHeavyLeatherInlaidMetal()
    { return true; }

inline bool uabkVellumPagesSewnToSpine()
    { return true; }

inline bool uabkVellumStubsForAddedPages()
    { return true; }

inline bool uabkStubsDoNotChangeCapacity()
    { return true; }

// A standard spell book has a saving throw equal to
// that of leather or book, with +2 to dice rolls made
// to save against acid, fireball, disintegration and
// lightning attacks.
inline bool uabkSaveAsLeatherOrBook()
    { return true; }

inline int uabkSaveBonusVsAcidFireDisintLightning()
    { return 2; }

// ---- the travelling book physical aspects ----
inline int uabkTravellingTallInches()
    { return 12; }

inline int uabkTravellingWideInches()
    { return 6; }

inline bool uabkTravellingThickCellLost()
    { return true; }

inline bool uabkTravellingWeightCellLost()
    { return true; }

inline bool uabkTravellingEncumbranceCellLost()
    { return true; }

inline int uabkTravellingFitPerLargeSack()
    { return 5; }

// The cover is strong supple leather (giant cobra and
// similar); hand-sewn parchment leaves glued to the
// spine; pages very thin and fragile; a small lock or
// leather ties secure the whole.
inline bool uabkTravellingCoverGiantCobraLeather()
    { return true; }

inline bool uabkTravellingPagesThinFragile()
    { return true; }

inline bool uabkTravellingLockOrLeatherTies()
    { return true; }

// A travelling spell book saves as leather or book
// with no bonuses against certain forms of attack.
inline bool uabkTravellingSaveNoBonus()
    { return true; }

// ---- the values ----
// A standard spell book has an Experience Point Value
// of 500 points per spell level contained therein
// (cantrips as 1st-level spells) and a Gold Piece Sale
// Value of 1,000 gp per spell level (all spells,
// including cantrips).
inline int uabkXpValuePerSpellLevel()
    { return 500; }

inline int uabkSaleValuePerSpellLevelGp()
    { return 1000; }

// Spell books must be sold immediately or else the
// x.p. value taken - a book cannot be kept while
// spells are transcribed and then sold.
inline bool uabkSellImmediatelyOrTakeXp()
    { return true; }

inline bool uabkNoKeepTranscribeThenSell()
    { return true; }

// ---- casting directly from books ----
// In extremis the DM may allow a spell to be cast
// directly from a spell book just as if the book were
// a scroll; the book must match the profession of the
// caster and the caster must be able to know and use
// the spell (reading directly differs from scroll
// use in this regard).
inline bool uabkInExtremisDmMayAllowDirectCast()
    { return true; }

inline bool uabkBookMustMatchCasterProfession()
    { return true; }

inline bool uabkCasterMustKnowAndUseSpell()
    { return true; }

inline bool uabkDirectCastDiffersFromScrolls()
    { return true; }

// Direct casting automatically destroys that spell;
// a 1 percent per level chance destroys the
// immediately preceding and following spells; a flat
// 1 percent chance destroys the entire book.
inline bool uabkDirectCastDestroysTheSpell()
    { return true; }

inline int uabkNeighborDestroyPctPerLevel()
    { return 1; }

inline int uabkWholeBookDestroyPct()
    { return 1; }

// A permanency spell would not prevent the loss (the
// writing might remain on the page but is no longer
// magical); the strictures apply to any book, personal
// or another's.
inline bool uabkPermanencyDoesNotPreventLoss()
    { return true; }

inline bool uabkWritingRemainsButNotMagical()
    { return true; }

inline bool uabkStricturesApplyToAnyBook()
    { return true; }

// ---- learning from another's book ----
inline bool uabkReadMagicNeededForOthersBook()
    { return true; }

inline bool uabkLearnSpellFromAnotherBook()
    { return true; }

inline int uabkStudyHoursPerLevelMin()
    { return 2; }

inline int uabkStudyHoursPerLevelMax()
    { return 8; }

inline bool uabkLearnedSpellImmediatelyUsable()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uaspellbooks: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 71, 'b inline count'
assert s.count('R366') == 1, 'b round tag'
assert s.count('uabkStandardCantripsCapacity') >= 1, 'b fn'
assert 'uapc' not in s, 'b no uapc ref'
assert 'uauw' not in s, 'b no uauw ref'
assert 'uadk' not in s, 'b no uadk ref'
assert 'uail' not in s, 'b no uail ref'
assert 'uam' not in s, 'b no uam ref'
assert 'uasc' not in s, 'b no uasc ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (b2) NEW rules/uaspellcomment.h ----
P = 'rules/uaspellcomment.h'
if os.path.exists(P) and 'R366' in rd(P):
    already.append('uaspellcomment: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaspellcomment.h
// The UA SPELL EXPLANATIONS - the referee commentary
// (pp. 81-82 print) pins, R366: the permanency lists
// and the Serten's spell immunity commentary.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the permanency object/area list interleaves with
//     the constitution-loss note in the print - the 22
//     names pin from the two fragments (the note
//     counted separately).
//   - the Serten's bonus bands detach from their spell
//     groups in the print (a stray +9/+7/+5 column) -
//     the three values and the 24 spell names pin, the
//     band assignment is flagged garbled pending the
//     PDF.
//   - a stray "from normal" fragment rides the
//     personal permanency list - flagged, no decode.
// ===========================================================================

#pragma once

namespace rules {

// ---- the personal permanency list ----
inline int uapcPermPersonalCount()
    { return 6; }

inline bool uapcPermPersonalDetectEvil()
    { return true; }

inline bool uapcPermPersonalDetectIllusion()
    { return true; }

inline bool uapcPermPersonalDetectInvisibility()
    { return true; }

inline bool uapcPermPersonalDetectMagic()
    { return true; }

inline bool uapcPermPersonalInfravision()
    { return true; }

inline bool uapcPermPersonalProtectionFromEvil()
    { return true; }

inline bool uapcPersonalListFromNormalFragment()
    { return true; }

// ---- the object/creature or area permanency list ----
inline int uapcPermObjectCount()
    { return 22; }

inline bool uapcPermObjectAlarm()
    { return true; }

inline bool uapcPermObjectDeeppockets()
    { return true; }

inline bool uapcPermObjectDispelMagic()
    { return true; }

inline bool uapcPermObjectEnlarge()
    { return true; }

inline bool uapcPermObjectFear()
    { return true; }

inline bool uapcPermObjectForcecage()
    { return true; }

inline bool uapcPermObjectGustOfWind()
    { return true; }

inline bool uapcPermObjectInvisibility()
    { return true; }

inline bool uapcPermObjectMagicMouth()
    { return true; }

inline bool uapcPermObjectMissiles()
    { return true; }

inline bool uapcPermObjectPreserve()
    { return true; }

inline bool uapcPermObjectPrismaticSphere()
    { return true; }

inline bool uapcPermObjectReadMagic()
    { return true; }

inline bool uapcPermObjectRun()
    { return true; }

inline bool uapcPermObjectStinkingCloud()
    { return true; }

inline bool uapcPermObjectTongues()
    { return true; }

inline bool uapcPermObjectUltravision()
    { return true; }

inline bool uapcPermObjectUnseenServant()
    { return true; }

inline bool uapcPermObjectWallOfFire()
    { return true; }

inline bool uapcPermObjectWallOfForce()
    { return true; }

inline bool uapcPermObjectWeb()
    { return true; }

inline bool uapcPermObjectWindWall()
    { return true; }

inline bool uapcObjectListInterleavedWithNote()
    { return true; }

// ---- the constitution-loss reads ----
// Only a 5 percent chance of losing a constitution
// point when permanency is cast upon a non-living
// thing; 100 percent when applied as a charge in a
// device (a ring of spell storing, the printed
// example).
inline int uapcConLossPctNonLiving()
    { return 5; }

inline int uapcConLossPctDeviceCharge()
    { return 100; }

inline bool uapcDeviceExampleRingOfSpellStoring()
    { return true; }

// ---- the Serten's spell immunity commentary ----
// The spell grants saving throw bonuses against the
// 24 listed magics, bestows a saving throw against
// all of them even if none is normally allowed, but
// not against the fascination effect of comeliness.
inline int uapcSertenSpellCount()
    { return 24; }

inline const char* uapcSertenName(int i)
{
    static const char* const n[24] = {
        "beguiling", "charm", "suggestion",
        "forget", "hypnotism",
        "ray of enfeeblement",
        "person-affecting cantrips",
        "command", "domination", "fear",
        "hold", "scare", "spook", "eyebite",
        "cloak of fear", "geas", "quest",
        "chaos", "feeblemind",
        "Otto's irresistible dance",
        "dolor", "demand", "torment",
        "Leomund's lamentable"
        " belabourment",
    };
    return (i >= 0 && i < 24) ? n[i] : "";
}

inline int uapcSertenBonusHigh()
    { return 9; }

inline int uapcSertenBonusMid()
    { return 7; }

inline int uapcSertenBonusLow()
    { return 5; }

inline bool uapcSertenBandAssignmentGarbled()
    { return true; }

inline bool uapcSertenSaveEvenIfNoneAllowed()
    { return true; }

inline bool uapcSertenNotVsComelinessFascination()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uaspellcomment: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b2 ns'
assert s.count('inline') == 43, 'b2 inline count'
assert s.count('R366') == 1, 'b2 round tag'
assert s.count('uapcPermPersonalCount') >= 1, 'b2 fn'
assert 'uabk' not in s, 'b2 no uabk ref'
assert 'uauw' not in s, 'b2 no uauw ref'
assert 'uadk' not in s, 'b2 no uadk ref'
assert 'uail' not in s, 'b2 no uail ref'
assert 'uam' not in s, 'b2 no uam ref'
assert 'uasc' not in s, 'b2 no uasc ref'
assert len(applied) + len(already) == 3, 'b2 count'


# ---- (b3) NEW rules/uauwspelluse.h ----
P = 'rules/uauwspelluse.h'
if os.path.exists(P) and 'R366' in rd(P):
    already.append('uauwspelluse: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uauwspelluse.h
// The UA UNDERWATER SPELL USE (pp. 81-83 print) pins,
// R366: the cannot-be-used lists by class, the
// airy-water footnote and the altered-effects reads.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The DMG underwater spells (R168) are a
// separate battery item; this is the UA adventure
// layer.
//
// JUDGMENTs (the decode method):
//   - the magic-user cannot-use list garbles at the
//     cantrip row (dampen reads; the second cantrip
//     cell is lost) - flagged, no name pin.
//   - the list tail interleaves the illusionist
//     column (haze, rainbow, whispering wind, phantom
//     wind, solid fog, death fog) - the fragment pins
//     as the illusionist list, corroborated by the
//     landed UA IL spell levels (R363-R365: rainbow at
//     1st, whispering wind at 2nd, phantom wind at
//     3rd, solid fog at 4th, death fog at 6th).
//   - the chain lightning save tail truncates ("half
//     dama") - decoded as the standard save-for-half
//     per the DMG lightning bolt.
//   - the starred footnote: spells that can be cast
//     and will function within the bounds of an airy
//     water spell.
// ===========================================================================

#pragma once

namespace rules {

// ---- the cleric cannot-use list ----
inline int uauwClericCannotUseCount()
    { return 5; }

inline bool uauwClericPrecipitationFirst()
    { return true; }

inline bool uauwClericDustDevilSecond()
    { return true; }

inline bool uauwClericCloudburstThird()
    { return true; }

inline bool uauwClericAirWalkFifth()
    { return true; }

inline bool uauwClericRainbowFifth()
    { return true; }

inline bool uauwClericAirWalkStarred()
    { return true; }

inline bool uauwClericRainbowStarred()
    { return true; }

// ---- the druid cannot-use list ----
inline int uauwDruidCannotUseCount()
    { return 4; }

inline bool uauwDruidPrecipitationFirst()
    { return true; }

inline bool uauwDruidFlameBladeSecond()
    { return true; }

inline bool uauwDruidCloudburstThird()
    { return true; }

inline bool uauwDruidLiveoakSixth()
    { return true; }

inline bool uauwDruidFlameBladeStarred()
    { return true; }

// ---- the magic-user cannot-use list ----
inline bool uauwMuDampenCantripListed()
    { return true; }

inline bool uauwMuCantripSecondCellLost()
    { return true; }

inline bool uauwMuMountFirst()
    { return true; }

inline bool uauwMuPrecipitationFirst()
    { return true; }

inline bool uauwMuFlamingSphereSecond()
    { return true; }

inline bool uauwMuCloudburstThird()
    { return true; }

inline bool uauwMuMinuteMeteorsThird()
    { return true; }

inline bool uauwMuWindWallThird()
    { return true; }

inline bool uauwMuShoutFourth()
    { return true; }

inline bool uauwMuFlamingSphereStarred()
    { return true; }

inline bool uauwMuWindWallStarred()
    { return true; }

inline bool uauwMuShoutStarred()
    { return true; }

// ---- the illusionist fragment ----
inline bool uauwIlFragmentReadsAsIllusionist()
    { return true; }

inline bool uauwIlHazeCantripListed()
    { return true; }

inline bool uauwIlRainbowFirst()
    { return true; }

inline bool uauwIlWhisperingWindSecond()
    { return true; }

inline bool uauwIlPhantomWindThird()
    { return true; }

inline bool uauwIlSolidFogFourth()
    { return true; }

inline bool uauwIlDeathFogSixth()
    { return true; }

inline bool uauwIlFragmentAllStarred()
    { return true; }

// ---- the airy-water footnote ----
inline bool uauwStarredCastableInAiryWater()
    { return true; }

// ---- the cleric altered effects ----
// Water walk (3rd): the casting causes the recipient
// to immediately bob to the surface. Magic font (5th):
// requires a glass globe of pure water as opposed to
// a font.
inline bool uauwWaterWalkBobsToSurface()
    { return true; }

inline bool uauwMagicFontNeedsGlassGlobe()
    { return true; }

// ---- the druid altered effects ----
inline bool uauwReflectingPoolAnyWaterySpace()
    { return true; }

// Transmute water to dust (6th) underwater opens a
// hole of 10 cubic feet per level of the caster; the
// surrounding water rushes in, inflicting 1-4 points
// of damage per level (no saving throw).
inline int uauwTransmuteHoleCubicFeetPerLevel()
    { return 10; }

inline int uauwTransmuteRushInDamagePerLevelDice()
    { return 4; }

inline bool uauwTransmuteNoSavingThrow()
    { return true; }

// ---- the magic-user altered effects ----
// The salt cantrip produces about 1 pint of salt
// water total; unless contained it quickly disperses
// into the surrounding water.
inline int uauwSaltCantripPints()
    { return 1; }

inline bool uauwSaltWaterDispersesUnlessContained()
    { return true; }

// Firewater (1st) floats to the top of the body of
// water and may not be ignited underwater.
inline bool uauwFirewaterFloatsToTop()
    { return true; }

inline bool uauwFirewaterNotIgnitableUnderwater()
    { return true; }

// Melf's acid arrow (2nd): the acid lasts only a
// single round, then is washed away.
inline int uauwAcidArrowLastsRounds()
    { return 1; }

inline bool uauwAcidArrowWashedAway()
    { return true; }

// Chain lightning (6th) underwater: effects as a
// lightning bolt of double normal radius but inflicts
// only 1d6 of damage per level of the caster (saving
// throw for half).
inline bool uauwChainLightningDoubleRadius()
    { return true; }

inline int uauwChainLightningDamageDicePerLevel()
    { return 6; }

inline bool uauwChainLightningSaveForHalf()
    { return true; }

inline bool uauwMuTransmuteAsDruid()
    { return true; }

// Mordenkainen's magnificent mansion (7th): at the
// caster's option the mansion can be filled with
// water, or the membrane can prevent the influx of
// water, leaving the interior tidy and dry.
inline bool uauwMansionWaterFilledOrDryOption()
    { return true; }

// Sink (8th): places a creature the given number of
// feet below the floor of the river or sea; the
// containment magic radiates through the water to the
// surface.
inline bool uauwSinkRadiatesToSurface()
    { return true; }

// ---- the illusionist altered effect ----
// Phantom steed (3rd) summoned underwater: hippocampi
// with black forebodies and silver-gray scales; no
// traveling or flying specials, but they gain the
// 4"/level movement of the phantom steed.
inline bool uauwPhantomSteedBecomesHippocampus()
    { return true; }

inline bool uauwPhantomSteedBlackForebodySilverScales()
    { return true; }

inline bool uauwPhantomSteedNoTravelOrFlySpecials()
    { return true; }

inline int uauwPhantomSteedMovementPerLevel()
    { return 4; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uauwspelluse: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b3 ns'
assert s.count('inline') == 57, 'b3 inline count'
assert s.count('R366') == 1, 'b3 round tag'
assert s.count('uauwClericCannotUseCount') >= 1, 'b3 fn'
assert 'uabk' not in s, 'b3 no uabk ref'
assert 'uapc' not in s, 'b3 no uapc ref'
assert 'uadk' not in s, 'b3 no uadk ref'
assert 'uail' not in s, 'b3 no uail ref'
assert 'uam' not in s, 'b3 no uam ref'
assert 'uasc' not in s, 'b3 no uasc ref'
assert len(applied) + len(already) == 4, 'b3 count'


# ---- (b4) NEW rules/uadarkness.h ----
P = 'rules/uadarkness.h'
if os.path.exists(P) and 'R366' in rd(P):
    already.append('uadarkness: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uadarkness.h
// The UA EFFECTS OF DARKNESS (p. 82 print) pins,
// R366: the combat to-hit ladder, the illumination
// exception, the converse read, the faerie fire
// conditions and the DM moderation closer.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The section prints clean - no OCR
// holes; the printed list markers garble (numbers 1,
// then bullets) - the four cases pin in the printed
// order.
// ===========================================================================

#pragma once

namespace rules {

// ---- the combat to-hit ladder ----
inline int uadkUnseenTargetToHitPenalty()
    { return 4; }

inline bool uadkUnseenIsAsInvisible()
    { return true; }

// If the opponent is vaguely discernible - a faint
// blur or a darker shape that stands out against the
// background - attacks are at -2 to hit.
inline int uadkVagueBlurToHitPenalty()
    { return 2; }

inline bool uadkVagueMeansDarkerShapeOnBackground()
    { return true; }

// ---- the illumination exception ----
// Combat is not affected by illumination (or lack
// thereof) in daylight or in the light conditions
// produced by most light-giving devices and spells -
// including torches, lanterns, light spells and
// continual light spells.
inline bool uadkDaylightAndDevicesUnaffected()
    { return true; }

inline bool uadkIncludesTorchLanternLightSpells()
    { return true; }

inline bool uadkIncludesContinualLight()
    { return true; }

// ---- the converse read ----
// The converse holds for creatures which function
// normally or at some relative advantage in darkness:
// infravision still sees opponents in the absence of
// visible-spectrum light, and creatures accustomed
// to operating in darkness suffer vision penalties
// when attacking opponents in illuminated conditions.
inline bool uadkConverseHoldsForDarkDwellers()
    { return true; }

inline bool uadkInfravisionWorksInNoVisibleLight()
    { return true; }

inline bool uadkDarkDwellerPenalizedInLight()
    { return true; }

inline bool uadkGrayDwarfCrossRef()
    { return true; }

inline bool uadkDarkElfDarkGnomeCrossRef()
    { return true; }

// ---- the faerie fire conditions ----
// Faerie fire benefits only when outlining opponents
// in poor lighting conditions (a dungeon area lit
// only by softly glowing magic weapons, or total
// darkness); in torch- or light-spell illumination
// (or anything stronger) it functions normally but
// contributes nothing to the visibility of the
// target.
inline bool uadkFaerieFireHelpsOnlyPoorLight()
    { return true; }

inline bool uadkFaerieFireWorksInTotalDarkness()
    { return true; }

inline bool uadkFaerieFireNoBenefitAtTorchLight()
    { return true; }

inline bool uadkFaerieFireFunctionsNormallyAnyway()
    { return true; }

// ---- the DM moderation closer ----
// Common sense must be the final determinant of
// whether an act is possible or whether a bonus or
// penalty applies; a warranted exception is within
// the DM's purview.
inline bool uadkDmCommonSenseFinalDeterminant()
    { return true; }

inline bool uadkDmMayWarrantException()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uadarkness: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b4 ns'
assert s.count('inline') == 18, 'b4 inline count'
assert s.count('R366') == 1, 'b4 round tag'
assert s.count('uadkUnseenTargetToHitPenalty') >= 1, 'b4 fn'
assert 'uabk' not in s, 'b4 no uabk ref'
assert 'uapc' not in s, 'b4 no uapc ref'
assert 'uauw' not in s, 'b4 no uauw ref'
assert 'uail' not in s, 'b4 no uail ref'
assert 'uam' not in s, 'b4 no uam ref'
assert 'uasc' not in s, 'b4 no uasc ref'
assert len(applied) + len(already) == 5, 'b4 count'


# ---- (c1) the gap ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **The spell book rules**' in s:
    already.append('gap report: the books close')
else:
    OLD = NL.join([
        '- [ ] **The spell book rules** (pp.',
        '      79-80) - the standard book',
        '      capacities (36 cantrips, 24 spells',
        '      of 1st-3rd, 16 of 4th-6th, 8 of',
        '      7th-9th), the travelling book',
        '      (9/6/4/2), the costs (1000 gp plus',
        '      100 gp per spell level, cantrips',
        '      as 1st; travelling 500 gp), the',
        '      4-7 week composition, the physical',
        '      aspects (the size, the 150 gp',
        '      weight, the 450 gp encumbrance,',
        '      the leather-book saves with +2).',
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [x] **The spell book rules** (pp.',
        '      79-80) - the standard book',
        '      capacities (36 cantrips, 24 spells',
        '      of 1st-3rd, 16 of 4th-6th, 8 of',
        '      7th-9th), the travelling book',
        '      (9/6/4/2), the costs (1000 gp plus',
        '      100 gp per spell level, cantrips',
        '      as 1st; travelling 500 gp), the',
        '      4-7 week composition, the physical',
        '      aspects (the size, the 150 gp',
        '      weight, the 450 gp encumbrance,',
        '      the leather-book saves with +2).',
        '      - CLOSED R366: the pin round',
        '        (rules/uaspellbooks.h) - the',
        '        capacities with the one-fourth',
        '        travelling read, the costs with',
        '        the master-borne start, the',
        '        composition weeks, the physical',
        '        aspects with the +2 saves, the',
        '        values, the direct-casting',
        '        destroys and the learning',
        '        hours; the section opening, the',
        '        encumbrance cell and the',
        '        travelling thickness/weight',
        '        cells garble - holes',
        '        in-header, revisit with the PDF.',
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    wr(GP, s)
    applied.append('gap report: the books close')

# ---- (c2) the gap ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **The spell explanations - the' in s:
    already.append('gap report: the commentary close')
else:
    OLD = NL.join([
        '- [ ] **The spell explanations - the',
        '      referee commentary** (pp. 81-82) -',
        '      the permanency list and the rest.',
    ])
    assert s.count(OLD) == 1, 'c2 old'
    NEW = NL.join([
        '- [x] **The spell explanations - the',
        '      referee commentary** (pp. 81-82) -',
        '      the permanency list and the rest.',
        '      - CLOSED R366: the pin round',
        '        (rules/uaspellcomment.h) - the',
        '        personal permanency list (the six',
        '        detects and protections), the',
        '        22-name object/area list, the 5',
        '        percent vs 100 percent',
        '        constitution-loss reads, the',
        "        Serten's immunity commentary (the",
        '        24 names with the +9/+7/+5',
        '        bonuses - the band assignment',
        '        detaches in the print, flagged',
        '        pending the PDF); CLOSED.',
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    wr(GP, s)
    applied.append('gap report: the commentary close')

# ---- (c3) the gap ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **Underwater spell use**' in s:
    already.append('gap report: the underwater close')
else:
    OLD = NL.join([
        '- [ ] **Underwater spell use** (pp.',
        '      81-83) - the per-spell underwater',
        '      reads (the salt cantrip, the',
        '      firewater float, the acid arrow',
        '      washout, the chain lightning',
        '      change, the mansion option, the',
        '      sink read, and the rest of the',
        '      list).',
    ])
    assert s.count(OLD) == 1, 'c3 old'
    NEW = NL.join([
        '- [x] **Underwater spell use** (pp.',
        '      81-83) - the per-spell underwater',
        '      reads (the salt cantrip, the',
        '      firewater float, the acid arrow',
        '      washout, the chain lightning',
        '      change, the mansion option, the',
        '      sink read, and the rest of the',
        '      list).',
        '      - CLOSED R366: the pin round',
        '        (rules/uauwspelluse.h) - the',
        '        cannot-use rosters (cleric,',
        '        druid, magic-user, the',
        '        illusionist fragment) with the',
        '        airy-water footnote, the',
        '        altered-effects reads (the water',
        '        walk bob, the magic font globe,',
        '        the transmute hole, the salt,',
        '        firewater, acid arrow, chain',
        '        lightning, mansion and sink, the',
        '        hippocampus steed); the MU',
        '        cantrip row and the MU/IL list',
        '        boundary garble - flagged',
        '        in-header, revisit with the PDF.',
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    wr(GP, s)
    applied.append('gap report: the underwater close')

# ---- (c4) the gap ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **The effects of darkness**' in s:
    already.append('gap report: the darkness close')
else:
    OLD = NL.join([
        '- [ ] **The effects of darkness** (p.',
        '      82) - the combat effects ladder.',
    ])
    assert s.count(OLD) == 1, 'c4 old'
    NEW = NL.join([
        '- [x] **The effects of darkness** (p.',
        '      82) - the combat effects ladder.',
        '      - CLOSED R366: the pin round',
        '        (rules/uadarkness.h) - the -4',
        '        unseen and -2 vague ladder, the',
        '        illumination exception, the',
        '        infravision converse with the',
        '        sub-race cross-refs, the faerie',
        '        fire conditions, the DM',
        '        moderation closer; the section',
        '        prints clean - CLOSED.',
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    wr(GP, s)
    applied.append('gap report: the darkness close')

# ---- (c) the gap kept asserts ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
assert s.count(
    '- [x] **The spell book rules**'
) == 1, 'c1 flip'
assert s.count(
    '- [x] **The spell explanations - the'
) == 1, 'c2 flip'
assert s.count(
    '- [x] **Underwater spell use**'
) == 1, 'c3 flip'
assert s.count(
    '- [x] **The effects of darkness**'
) == 1, 'c4 flip'
assert s.count('(rules/uaspellbooks.h) - the') == 1, 'c1 note'
assert s.count('(rules/uaspellcomment.h) - the') == 1, 'c2 note'
assert s.count('(rules/uauwspelluse.h) - the') == 1, 'c3 note'
assert s.count('(rules/uadarkness.h) - the') == 1, 'c4 note'
assert s.count(
    '- [ ] **Cantrip acquisition, MU**'
) == 1, 'c cantrip kept open'
assert s.count(
    '- [ ] **Illusionist spell acquisition**'
) == 1, 'c acq kept open'
assert s.count(
    '- [x] **The cost of spell casting**'
) == 1, 'c cost kept closed'
assert s.count(
    '- [x] **The new illusionist spells**'
) == 1, 'c il kept closed'
assert s.count(
    'CLOSED R365: the 6th and'
) == 1, 'c r365 kept'
assert s.count(
    'R365: the fragment-verified'
) == 1, 'c r365 acq kept'
assert len(applied) + len(already) == 9, 'c count'


# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R366 UA DM-section spells pin audit' in s:
    already.append('regtest.cpp: the R366 audit')
else:
    INC_ANCH = ('#include "rules/uaspellcost.h"  // '
        'R365: the UA spell casting cost')
    INC_NEW = NL.join([
        '#include "rules/uaspellcost.h"  // R365: the UA spell casting cost',
        '#include "rules/uaspellbooks.h"  // R366: the UA spell books',
        '#include "rules/uaspellcomment.h"  // R366: the UA spell commentary',
        '#include "rules/uauwspelluse.h"  // R366: the UA underwater spells',
        '#include "rules/uadarkness.h"  // R366: the UA effects of darkness',
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R366: the UA DM-section spells
    // pin audit ----
    // The UA DM-section spell block (pp.
    // 79-83): the MAGIC-USER SPELL BOOKS
    // (the capacities 36/24/16/8 with the
    // one-fourth travelling 9/6/4/2, the
    // costs, the physical aspects, the
    // values, the direct-casting and
    // learning reads), the SPELL
    // EXPLANATIONS commentary (the
    // permanency lists, the 5/100 percent
    // constitution-loss reads, the
    // Serten's immunity commentary with
    // the bonus band assignment flagged),
    // the UNDERWATER SPELL USE lists (the
    // cannot-use rosters with the
    // airy-water footnote, the altered
    // effects - the MU cantrip row and the
    // MU/IL list boundary garble, flagged)
    // and the EFFECTS OF DARKNESS ladder.
    // Four items flip CLOSED; the census
    // 292 -> 293.
    {
        using namespace rules;
        int bad = 0;
        // ---- uabk pins ----
            if (uabkStandardCantripsCapacity() != 36) ++bad;
            if (uabkStandardLowLevelSpells() != 24) ++bad;
            if (uabkStandardMidLevelSpells() != 16) ++bad;
            if (uabkStandardHighLevelSpells() != 8) ++bad;
            if (!uabkTravellingIsOneFourth()) ++bad;
            if (uabkTravellingCantripsCapacity() != 9) ++bad;
            if (uabkTravellingLowLevelSpells() != 6) ++bad;
            if (uabkTravellingMidLevelSpells() != 4) ++bad;
            if (uabkTravellingHighLevelSpells() != 2) ++bad;
            if (uabkStandardMaterialsCostGp() != 1000) ++bad;
            if (uabkPerSpellLevelCostGp() != 100) ++bad;
            if (!uabkCantripsCountAsFirstLevel()) ++bad;
            if (!uabkInitialBooksBorneByMaster()) ++bad;
            if (uabkInitialBookCountMax() != 2) ++bad;
            if (!uabkLaterBooksSelfComposed()) ++bad;
            if (uabkCompositionWeeksMin() != 4) ++bad;
            if (uabkCompositionWeeksMax() != 7) ++bad;
            if (!uabkCompositionRidesLevelTraining()) ++bad;
            if (uabkEnterFirstLevelCostGp() != 100) ++bad;
            if (uabkEnterSecondLevelCostGp() != 200) ++bad;
            if (uabkTravellingCostFragmentGp() != 500) ++bad;
            if (!uabkTravellingCostIsFragmentRead()) ++bad;
            if (uabkStandardHeightInches() != 16) ++bad;
            if (uabkStandardWidthInches() != 12) ++bad;
            if (uabkStandardThicknessInches() != 6) ++bad;
            if (!uabkDmMayResizeTheBook()) ++bad;
            if (uabkMinSizeHeightInches() != 12) ++bad;
            if (uabkMinSizeWidthInches() != 12) ++bad;
            if (uabkMinSizeThicknessInches() != 6) ++bad;
            if (uabkMaxSizeHeightInches() != 18) ++bad;
            if (uabkMaxSizeWidthInches() != 12) ++bad;
            if (uabkMaxSizeThicknessInches() != 9) ++bad;
            if (uabkMedianWeightGp() != 150) ++bad;
            if (!uabkWeightAdjustedForSize()) ++bad;
            if (!uabkEncumbranceCellLost()) ++bad;
            if (!uabkFitsBackpackOrLargeSack()) ++bad;
            if (!uabkCoverHeavyLeatherInlaidMetal()) ++bad;
            if (!uabkVellumPagesSewnToSpine()) ++bad;
            if (!uabkVellumStubsForAddedPages()) ++bad;
            if (!uabkStubsDoNotChangeCapacity()) ++bad;
            if (!uabkSaveAsLeatherOrBook()) ++bad;
            if (uabkSaveBonusVsAcidFireDisintLightning() != 2) ++bad;
            if (uabkTravellingTallInches() != 12) ++bad;
            if (uabkTravellingWideInches() != 6) ++bad;
            if (!uabkTravellingThickCellLost()) ++bad;
            if (!uabkTravellingWeightCellLost()) ++bad;
            if (!uabkTravellingEncumbranceCellLost()) ++bad;
            if (uabkTravellingFitPerLargeSack() != 5) ++bad;
            if (!uabkTravellingCoverGiantCobraLeather()) ++bad;
            if (!uabkTravellingPagesThinFragile()) ++bad;
            if (!uabkTravellingLockOrLeatherTies()) ++bad;
            if (!uabkTravellingSaveNoBonus()) ++bad;
            if (uabkXpValuePerSpellLevel() != 500) ++bad;
            if (uabkSaleValuePerSpellLevelGp() != 1000) ++bad;
            if (!uabkSellImmediatelyOrTakeXp()) ++bad;
            if (!uabkNoKeepTranscribeThenSell()) ++bad;
            if (!uabkInExtremisDmMayAllowDirectCast()) ++bad;
            if (!uabkBookMustMatchCasterProfession()) ++bad;
            if (!uabkCasterMustKnowAndUseSpell()) ++bad;
            if (!uabkDirectCastDiffersFromScrolls()) ++bad;
            if (!uabkDirectCastDestroysTheSpell()) ++bad;
            if (uabkNeighborDestroyPctPerLevel() != 1) ++bad;
            if (uabkWholeBookDestroyPct() != 1) ++bad;
            if (!uabkPermanencyDoesNotPreventLoss()) ++bad;
            if (!uabkWritingRemainsButNotMagical()) ++bad;
            if (!uabkStricturesApplyToAnyBook()) ++bad;
            if (!uabkReadMagicNeededForOthersBook()) ++bad;
            if (!uabkLearnSpellFromAnotherBook()) ++bad;
            if (uabkStudyHoursPerLevelMin() != 2) ++bad;
            if (uabkStudyHoursPerLevelMax() != 8) ++bad;
            if (!uabkLearnedSpellImmediatelyUsable()) ++bad;
        // ---- uapc pins ----
            if (uapcPermPersonalCount() != 6) ++bad;
            if (!uapcPermPersonalDetectEvil()) ++bad;
            if (!uapcPermPersonalDetectIllusion()) ++bad;
            if (!uapcPermPersonalDetectInvisibility()) ++bad;
            if (!uapcPermPersonalDetectMagic()) ++bad;
            if (!uapcPermPersonalInfravision()) ++bad;
            if (!uapcPermPersonalProtectionFromEvil()) ++bad;
            if (!uapcPersonalListFromNormalFragment()) ++bad;
            if (uapcPermObjectCount() != 22) ++bad;
            if (!uapcPermObjectAlarm()) ++bad;
            if (!uapcPermObjectDeeppockets()) ++bad;
            if (!uapcPermObjectDispelMagic()) ++bad;
            if (!uapcPermObjectEnlarge()) ++bad;
            if (!uapcPermObjectFear()) ++bad;
            if (!uapcPermObjectForcecage()) ++bad;
            if (!uapcPermObjectGustOfWind()) ++bad;
            if (!uapcPermObjectInvisibility()) ++bad;
            if (!uapcPermObjectMagicMouth()) ++bad;
            if (!uapcPermObjectMissiles()) ++bad;
            if (!uapcPermObjectPreserve()) ++bad;
            if (!uapcPermObjectPrismaticSphere()) ++bad;
            if (!uapcPermObjectReadMagic()) ++bad;
            if (!uapcPermObjectRun()) ++bad;
            if (!uapcPermObjectStinkingCloud()) ++bad;
            if (!uapcPermObjectTongues()) ++bad;
            if (!uapcPermObjectUltravision()) ++bad;
            if (!uapcPermObjectUnseenServant()) ++bad;
            if (!uapcPermObjectWallOfFire()) ++bad;
            if (!uapcPermObjectWallOfForce()) ++bad;
            if (!uapcPermObjectWeb()) ++bad;
            if (!uapcPermObjectWindWall()) ++bad;
            if (!uapcObjectListInterleavedWithNote()) ++bad;
            if (uapcConLossPctNonLiving() != 5) ++bad;
            if (uapcConLossPctDeviceCharge() != 100) ++bad;
            if (!uapcDeviceExampleRingOfSpellStoring()) ++bad;
            if (uapcSertenSpellCount() != 24) ++bad;
            if (uapcSertenBonusHigh() != 9) ++bad;
            if (uapcSertenBonusMid() != 7) ++bad;
            if (uapcSertenBonusLow() != 5) ++bad;
            if (!uapcSertenBandAssignmentGarbled()) ++bad;
            if (!uapcSertenSaveEvenIfNoneAllowed()) ++bad;
            if (!uapcSertenNotVsComelinessFascination()) ++bad;
        // ---- uauw pins ----
            if (uauwClericCannotUseCount() != 5) ++bad;
            if (!uauwClericPrecipitationFirst()) ++bad;
            if (!uauwClericDustDevilSecond()) ++bad;
            if (!uauwClericCloudburstThird()) ++bad;
            if (!uauwClericAirWalkFifth()) ++bad;
            if (!uauwClericRainbowFifth()) ++bad;
            if (!uauwClericAirWalkStarred()) ++bad;
            if (!uauwClericRainbowStarred()) ++bad;
            if (uauwDruidCannotUseCount() != 4) ++bad;
            if (!uauwDruidPrecipitationFirst()) ++bad;
            if (!uauwDruidFlameBladeSecond()) ++bad;
            if (!uauwDruidCloudburstThird()) ++bad;
            if (!uauwDruidLiveoakSixth()) ++bad;
            if (!uauwDruidFlameBladeStarred()) ++bad;
            if (!uauwMuDampenCantripListed()) ++bad;
            if (!uauwMuCantripSecondCellLost()) ++bad;
            if (!uauwMuMountFirst()) ++bad;
            if (!uauwMuPrecipitationFirst()) ++bad;
            if (!uauwMuFlamingSphereSecond()) ++bad;
            if (!uauwMuCloudburstThird()) ++bad;
            if (!uauwMuMinuteMeteorsThird()) ++bad;
            if (!uauwMuWindWallThird()) ++bad;
            if (!uauwMuShoutFourth()) ++bad;
            if (!uauwMuFlamingSphereStarred()) ++bad;
            if (!uauwMuWindWallStarred()) ++bad;
            if (!uauwMuShoutStarred()) ++bad;
            if (!uauwIlFragmentReadsAsIllusionist()) ++bad;
            if (!uauwIlHazeCantripListed()) ++bad;
            if (!uauwIlRainbowFirst()) ++bad;
            if (!uauwIlWhisperingWindSecond()) ++bad;
            if (!uauwIlPhantomWindThird()) ++bad;
            if (!uauwIlSolidFogFourth()) ++bad;
            if (!uauwIlDeathFogSixth()) ++bad;
            if (!uauwIlFragmentAllStarred()) ++bad;
            if (!uauwStarredCastableInAiryWater()) ++bad;
            if (!uauwWaterWalkBobsToSurface()) ++bad;
            if (!uauwMagicFontNeedsGlassGlobe()) ++bad;
            if (!uauwReflectingPoolAnyWaterySpace()) ++bad;
            if (uauwTransmuteHoleCubicFeetPerLevel() != 10) ++bad;
            if (uauwTransmuteRushInDamagePerLevelDice() != 4) ++bad;
            if (!uauwTransmuteNoSavingThrow()) ++bad;
            if (uauwSaltCantripPints() != 1) ++bad;
            if (!uauwSaltWaterDispersesUnlessContained()) ++bad;
            if (!uauwFirewaterFloatsToTop()) ++bad;
            if (!uauwFirewaterNotIgnitableUnderwater()) ++bad;
            if (uauwAcidArrowLastsRounds() != 1) ++bad;
            if (!uauwAcidArrowWashedAway()) ++bad;
            if (!uauwChainLightningDoubleRadius()) ++bad;
            if (uauwChainLightningDamageDicePerLevel() != 6) ++bad;
            if (!uauwChainLightningSaveForHalf()) ++bad;
            if (!uauwMuTransmuteAsDruid()) ++bad;
            if (!uauwMansionWaterFilledOrDryOption()) ++bad;
            if (!uauwSinkRadiatesToSurface()) ++bad;
            if (!uauwPhantomSteedBecomesHippocampus()) ++bad;
            if (!uauwPhantomSteedBlackForebodySilverScales()) ++bad;
            if (!uauwPhantomSteedNoTravelOrFlySpecials()) ++bad;
            if (uauwPhantomSteedMovementPerLevel() != 4) ++bad;
        // ---- uadk pins ----
            if (uadkUnseenTargetToHitPenalty() != 4) ++bad;
            if (!uadkUnseenIsAsInvisible()) ++bad;
            if (uadkVagueBlurToHitPenalty() != 2) ++bad;
            if (!uadkVagueMeansDarkerShapeOnBackground()) ++bad;
            if (!uadkDaylightAndDevicesUnaffected()) ++bad;
            if (!uadkIncludesTorchLanternLightSpells()) ++bad;
            if (!uadkIncludesContinualLight()) ++bad;
            if (!uadkConverseHoldsForDarkDwellers()) ++bad;
            if (!uadkInfravisionWorksInNoVisibleLight()) ++bad;
            if (!uadkDarkDwellerPenalizedInLight()) ++bad;
            if (!uadkGrayDwarfCrossRef()) ++bad;
            if (!uadkDarkElfDarkGnomeCrossRef()) ++bad;
            if (!uadkFaerieFireHelpsOnlyPoorLight()) ++bad;
            if (!uadkFaerieFireWorksInTotalDarkness()) ++bad;
            if (!uadkFaerieFireNoBenefitAtTorchLight()) ++bad;
            if (!uadkFaerieFireFunctionsNormallyAnyway()) ++bad;
            if (!uadkDmCommonSenseFinalDeterminant()) ++bad;
            if (!uadkDmMayWarrantException()) ++bad;
        // the Serten's name table ----
            static const char* const sn[24] = {
                "beguiling", "charm", "suggestion", "forget",
                "hypnotism", "ray of enfeeblement",
                "person-affecting cantrips", "command",
                "domination", "fear", "hold", "scare", "spook",
                "eyebite", "cloak of fear", "geas", "quest",
                "chaos", "feeblemind",
                "Otto's irresistible dance", "dolor", "demand",
                "torment", "Leomund's lamentable belabourment"
            };
            for (int i = 0; i < 24; ++i) {
                if (strcmp(
                        uapcSertenName(i),
                        sn[i]) != 0) ++bad;
            }
            if (uapcSertenName(-1)[0] != 0)
                ++bad;
            if (uapcSertenName(24)[0] != 0)
                ++bad;
        printf("R366 UA DM-section spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R366 audit')
s = rd(RT)
assert s.count(
    'R366 UA DM-section spells pin audit: bad '
) == 1, 'd audit line'
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
assert s.count(
    'R355 UA druid 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R354 UA druid 6th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R353 UA druid 5th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R352 UA druid 3rd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R351 UA druid 2nd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R350 UA druid 1st level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R349 UA cleric 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count('audit: bad ') == 293, 'd census 293'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uaspellbooks.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uaspellcomment.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uauwspelluse.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uadarkness.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uaspellcost.h"'
) == 1, 'd kept include'
assert s.count(
    '#include "rules/uailacquisition.h"'
) == 1, 'd kept include'
assert s.count(
    '#include "rules/uailspells1.h"'
) == 1, 'd kept include'
assert s.count(
    '#include "rules/uailspells2.h"'
) == 1, 'd kept include'
assert s.count(
    '#include "rules/uailspells3.h"'
) == 1, 'd kept include'
assert s.count(
    '#include "rules/uailspells5.h"'
) == 1, 'd kept include'
assert s.count(
    '#include "rules/uailspells6.h"'
) == 1, 'd kept include'
assert s.count(
    '#include "rules/uailspells7.h"'
) == 1, 'd kept include'
assert s.count(
    '#include "rules/uailspells4.h"'
) == 1, 'd kept include'
assert s.count(
    '#include "rules/uailcantrips.h"'
) == 1, 'd il include'
for i in range(1, 10):
    assert s.count(
        '#include "rules/uamuspells%d.h"'
        % i) == 1, 'd mu include'
assert len(applied) + len(already) == 10, 'd count'


# ---- the summary ----
print('R366 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R366 note: the UA DM-section spells')
print('pin round - the MU spell books',)
print('(the capacities and costs, the',)
print('physical aspects, the values, the',)
print('direct-casting and learning reads);',)
print('the spell explanations commentary',)
print('(the permanency lists and the',)
print("Serten's immunity with the band")
print('assignment flagged); the underwater',)
print('spell use lists (the cannot-use',)
print('rosters and the altered effects);',)
print('the effects of darkness ladder;',)
print('all four items flip CLOSED; the',)
print('census 292 -> 293')
print('commit: R366: the UA DM-section',)
print('spells pin round (census 293)',)

