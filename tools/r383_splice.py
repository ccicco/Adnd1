
# R383: the UA misc magic prose
# part 3 pin round (the G-H
# stretch): ELEVEN items pin -
# TWO fully clean (the gloves
# of missile snaring, the hat
# of stupidity) plus NINE
# mechanics-clean with flagged
# holes (the gem of insight's
# recall seam, the girdle of
# dwarvenkind's racial block,
# the girdle of many pouches'
# tail, the gloves of
# thievery's level cells, the
# hat of difference's loss
# seam, the hat of disguise's
# removal seam, the haversack's
# quart merge, the horn of
# fog's rounds/minutes seam,
# the horn of goodness' eaten
# header); NOTHING in G-H
# fully garbles - the gap item
# AMENDED with the part-3 note,
# stays OPEN for I-Z,
# PDF-gated; the R382 seam the
# part-2 ledger, the R375 seam
# the misc band; the census
# 309 -> 310.
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



# ---- (a) the seed: the R382 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R382 landed 2026-10-12: commit',
    '  471ff43, census 309, the UA',
    '  misc magic prose part 2 pin',
    '  round (rules/uamiscprose2.h):',
    '  eight D-E items pin - one',
    '  fully clean (the dust of',
    '  tracelessness) plus seven',
    '  mechanics-clean with flagged',
    '  holes (the deck of illusions,',
    '  the dicerion, the dust of',
    '  dryness, the dust of illusion,',
    '  the egg of desire, the egg of',
    '  reason, the egg of shattering);',
    '  nothing in D-E fully garbles',
    '  - the item AMENDED, stays',
    '  OPEN for F-Z, PDF-gated; the',
    '  R381 seam the part-1 ledger,',
    '  the R375 seam the misc band;',
    '  GREEN on the second amend;',
    '  the 382b using line and the',
    '  382c egg-of-reason 66 check',
    '  ride the fixers.'
])
s = rd(SD)
if 'R382 landed 2026-10-12' in s:
    already.append('seed: the R382 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R382 record')
s = rd(SD)
assert s.count(
    'R382 landed 2026-10-12'
) == 1, 'a entry'
assert s.count(
    'R381 landed 2026-10-12'
) == 1, 'a R381 kept'
assert s.count(
    'R380 landed 2026-10-12'
) == 1, 'a R381 kept'
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


# ---- (b) NEW rules/uamiscprose3.h ----
P = 'rules/uamiscprose3.h'
if os.path.exists(P) and 'R383' in rd(P):
    already.append('uamiscprose3.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uamiscprose3.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 3, R383: the
// G-H stretch - eleven pins,
// two fully clean (the gloves
// of missile snaring, the hat
// of stupidity) plus nine
// mechanics-clean with flagged
// holes (the gem of insight's
// recall seam, the girdle of
// dwarvenkind's racial block,
// the girdle of many pouches'
// tail, the gloves of
// thievery's level cells, the
// hat of difference's loss
// seam, the hat of disguise's
// removal seam, the haversack's
// quart merge, the horn of
// fog's rounds/minutes seam,
// the horn of goodness' eaten
// header). Nothing in G-H
// fully garbles; I-Z rides
// the later parts. The
// part-2 and skeleton seams
// ride in the regtest audit,
// not here.
namespace rules {

// ---- the gem of insight ----
// A well-cut stone of not
// less than 5,000 gp value;
// a faint enchantment aura
// under detection.
inline int uamm3GemMinValueGp()
    { return 5000; }

inline bool uamm3GemFaintEnchantmentAura()
    { return true; }

// The possessor begins to
// feel its power after one
// week; after two weeks the
// understanding arrives.
inline int uamm3GemFeelPowerWeeks()
    { return 1; }

inline int uamm3GemUnderstandAfterWeeks()
    { return 2; }

// While kept: recall, better
// memory, insight - one point
// of intelligence and one of
// wisdom. The recall
// sentences OCR-scramble; the
// mechanics read; flagged.
inline int uamm3GemIntGain()
    { return 1; }

inline int uamm3GemWisGain()
    { return 1; }

inline bool uamm3GemRecallSeamGarbles()
    { return true; }

// Keep it three months: past
// the period the intelligence
// point remains but the
// wisdom point is lost.
inline int uamm3GemKeepMonths()
    { return 3; }

inline bool uamm3GemIntStaysBeyondPeriod()
    { return true; }

inline bool uamm3GemWisLostBeyondPeriod()
    { return true; }

// A second gem never increases
// either score, even if the
// first left no permanent
// gain.
inline bool uamm3GemSecondGemInert()
    { return true; }

// ---- the girdle of
// dwarvenkind ----
// Charisma by audience: -1
// with non-dwarves and their
// ilk, +1 with stout
// halflings and all gnomes,
// +2 as regarded by dwarves.
inline int uamm3GdkChaNonDwarvesAdj()
    { return -1; }

inline int uamm3GdkChaStoutHalflingsAdj()
    { return 1; }

inline int uamm3GdkChaGnomesAdj()
    { return 1; }

inline int uamm3GdkChaDwarvesAdj()
    { return 2; }

// The dweomer grants the
// dwarvish language -
// understand, speak, read.
inline bool uamm3GdkSpeaksDwarvish()
    { return true; }

// The racial-benefits block
// OCR-scrambles; the
// reconstruction: the dwarf
// saving-throw bonuses apply
// underground; all benefits
// last only while the girdle
// is worn; the extra-language
// and giant-type armor class
// benefits never apply;
// flagged.
inline bool uamm3GdkUndergroundSaveBonusesApply()
    { return true; }

inline bool uamm3GdkBenefitsOnlyWhileWorn()
    { return true; }

inline bool uamm3GdkNoGiantTypeAcBenefit()
    { return true; }

inline bool uamm3GdkNoExtraLanguages()
    { return true; }

inline bool uamm3GdkRacialBlockGarbles()
    { return true; }

// ---- the girdle of many
// pouches ----
// A broad waist-belt that
// radiates a strong
// enchantment dweomer with a
// fainter alteration aura.
inline bool uamm3GmpStrongEnchantmentAura()
    { return true; }

inline bool uamm3GmpFainterAlterationAura()
    { return true; }

// Eight apparent pouches on
// the inner front, seven
// more behind each - 64
// magical pouches in all.
inline int uamm3GmpApparentPouches()
    { return 8; }

inline int uamm3GmpTotalPouches()
    { return 64; }

inline int uamm3GmpBehindEach()
    { return 7; }

// Each pouch is a miniature
// bag of holding: one cubic
// foot, up to 10 pounds.
inline int uamm3GmpPouchCuFt()
    { return 1; }

inline int uamm3GmpPouchLbs()
    { return 10; }

// Responds to the wearer's
// thoughts, providing a full
// pouch or an empty one as
// desired; prized by spell
// casters for components.
inline bool uamm3GmpRespondsToThoughts()
    { return true; }

inline bool uamm3GmpFullOrEmptyAsDesired()
    { return true; }

inline bool uamm3GmpPrizedBySpellcasters()
    { return true; }

// A garbled tail sentence (a
// 50-years fragment) rides
// the extract; flagged.
inline bool uamm3GmpTailSeamGarbles()
    { return true; }

// ---- the gloves of missile
// snaring ----
// A slight enchantment and
// alteration dweomer; once
// snugly worn they meld with
// the hands, nearly
// invisible - undetectable
// beyond 5 feet.
inline bool uamm3GmsSlightEnchantmentAura()
    { return true; }

inline bool uamm3GmsMeldWithHands()
    { return true; }

inline int uamm3GmsUndetectableBeyondFt()
    { return 5; }

// Either or both hands, if
// not already holding
// something, pick missiles
// out of the air - small,
// hand-hurled or
// weapon-propelled.
inline bool uamm3GmsNeedEmptyHands()
    { return true; }

inline bool uamm3GmsCatchHandHurled()
    { return true; }

inline bool uamm3GmsCatchWeaponPropelled()
    { return true; }

// The caught missile can be
// returned to the sender as
// an attack; a weapon that
// magically returns is
// merely stopped - no attack
// from returning it.
inline bool uamm3GmsCanReturnMissile()
    { return true; }

inline bool uamm3GmsMagicReturnPreventsOnly()
    { return true; }

inline bool uamm3GmsMagicReturnNoAttack()
    { return true; }

// ---- the gloves of
// thievery ----
// Normal-seeming handwear
// with a faint enchantment
// and alteration aura;
// invisible on the hands
// except to magical sight.
inline bool uamm3GthFaintEnchantmentAura()
    { return true; }

inline bool uamm3GthInvisibleExceptMagic()
    { return true; }

// Opens locks and picks
// pockets as a thief of the
// stated levels - the level
// cells OCR-scramble ("Sth",
// the 7th); a further +5% in
// both categories if the
// wearer is already at or
// above the stated levels;
// flagged.
inline bool uamm3GthLevelCellsGarble()
    { return true; }

inline int uamm3GthBonusPctIfAdvanced()
    { return 5; }

inline bool uamm3GthBonusNeedsStatedLevels()
    { return true; }

// ---- the hat of difference
// ----
// Donned, the wearer assumes
// the role of a character of
// any different profession -
// but only at 1st-level
// ability.
inline bool uamm3HdfAssumesOtherProfession()
    { return true; }

inline bool uamm3HdfFirstLevelAbilityOnly()
    { return true; }

// Experience gained is in the
// assumed role only, and
// cumulative: a level reached
// is retained on later
// wearings.
inline bool uamm3HdfXpInAssumedRole()
    { return true; }

inline bool uamm3HdfXpCumulative()
    { return true; }

inline bool uamm3HdfLevelRetainedOnRewearing()
    { return true; }

// Progress continues
// indefinitely while worn;
// the loss conditions (the
// discarded-or-stolen seam)
// OCR-scramble - flagged.
inline bool uamm3HdfProgressIndefinite()
    { return true; }

inline bool uamm3HdfLostIfDiscarded()
    { return true; }

inline bool uamm3HdfLossSeamGarbles()
    { return true; }

// Hit points and ability
// scores are always the
// actual character's.
inline bool uamm3HdfHitPointsStayActual()
    { return true; }

inline bool uamm3HdfAbilityScoresStayActual()
    { return true; }

// ---- the hat of disguise
// ----
// A powerful enchantment that
// alters the appearance:
// hair, eyes, complexion any
// color; sex male or female;
// facial features highly
// mutable.
inline bool uamm3HdgHairAnyColor()
    { return true; }

inline bool uamm3HdgEyesAnyColor()
    { return true; }

inline bool uamm3HdgComplexionAnyColor()
    { return true; }

inline bool uamm3HdgSexChange()
    { return true; }

inline bool uamm3HdgFacialMutable()
    { return true; }

// Height varies plus or minus
// 25%, weight plus or minus
// 50% of actual.
inline int uamm3HdgHeightPct()
    { return 25; }

inline int uamm3HdgWeightPct()
    { return 50; }

// Removing the hat dispels
// the dweomer instantly, but
// it can be used over and
// over; the removal sentence
// OCR-scrambles - flagged.
inline bool uamm3HdgRemovalDispelsInstantly()
    { return true; }

inline bool uamm3HdgReusableOverAndOver()
    { return true; }

inline bool uamm3HdgRemovalSeamGarbles()
    { return true; }

// The hat itself can appear
// as a comb, ribbon, head
// band, fillet, cap, coif,
// hood, helmet, etc.
inline bool uamm3HdgAppearsAsAccessories()
    { return true; }

// ---- the hat of stupidity
// ----
// Totally indistinguishable
// from other magical
// headgear, even under
// detection; only placing it
// on the head reveals its
// powers.
inline bool uamm3HdsIndistinguishableByDetection()
    { return true; }

inline bool uamm3HdsOnlyWearingReveals()
    { return true; }

// The wearer believes the hat
// beneficial and always wants
// it on, especially for
// thinking and spell casting.
inline bool uamm3HdsWearerBelievesBeneficial()
    { return true; }

inline bool uamm3HdsWearerWantsHatOn()
    { return true; }

// Intelligence lowers to 7,
// or by 1 if already 7 or
// lower; only remove curse or
// similar magic frees the
// wearer. Fully clean in the
// extract.
inline int uamm3HdsIntLoweredTo()
    { return 7; }

inline int uamm3HdsIntLoweredByIfAlreadyLow()
    { return 1; }

inline bool uamm3HdsOnlyRemoveCurseFrees()
    { return true; }

// ---- Heward's handy
// haversack ----
// An ordinary-seeming
// well-made backpack, finely
// tanned leather with brass
// hardware and buckles.
inline bool uamm3HavOrdinaryAppearance()
    { return true; }

// Two side pouches, each
// appearing to hold about a
// quart (the "aquart" merge
// OCR-artifacts) but each a
// bag of holding for 2 cubic
// feet or 20 pounds; flagged.
inline int uamm3HavSidePouches()
    { return 2; }

inline int uamm3HavSidePouchCuFt()
    { return 2; }

inline int uamm3HavSidePouchLbs()
    { return 20; }

inline bool uamm3HavQuartMergeGarbles()
    { return true; }

// The large central portion:
// 8 cubic feet, 80 pounds.
inline int uamm3HavCentralCuFt()
    { return 8; }

inline int uamm3HavCentralLbs()
    { return 80; }

// The greater dweomer: the
// item reached for is on top
// of whatever else is in that
// part - no digging.
inline bool uamm3HavSoughtItemOnTop()
    { return true; }

// The haversack and its
// contents gain +2 on all
// saving throws.
inline int uamm3HavSaveBonus()
    { return 2; }

// ---- the horn of fog ----
// A small buglelike device
// that blows a thick cloud of
// heavy fog equal to an
// illusionist's fog cloud
// spell; each round of
// blowing creates a 10-foot
// cubic cloud.
inline bool uamm3HfgSmallBuglelike()
    { return true; }

inline bool uamm3HfgFogCloudEquivalent()
    { return true; }

inline int uamm3HfgCubePerRoundFt()
    { return 10; }

// The vapors last 2-8 rounds
// after the last round of
// winding; a round's pause
// begins a new cloud.
inline int uamm3HfgCloudLastsLoRounds()
    { return 2; }

inline int uamm3HfgCloudLastsHiRounds()
    { return 8; }

inline bool uamm3HfgPauseStartsNewCloud()
    { return true; }

// The note drops abruptly at
// the end (the OOO0O00-UMP!
// artifact), and the duration
// prose mixes rounds and
// minutes - the book's own
// seam; flagged.
inline bool uamm3HfgRoundsMinutesSeamGarbles()
    { return true; }

// ---- the horn of goodness
// ----
// The second horn's header is
// eaten by the fog merge; the
// mechanics read. It adapts
// to the ethical disposition
// of its possessor - good or
// evil effect by alignment;
// flagged.
inline bool uamm3HgdAdaptsToEthicalDisposition()
    { return true; }

inline bool uamm3HgdHeaderSeamGarbles()
    { return true; }

// Absolutely neutral ethical
// alignment: no power
// whatsoever.
inline bool uamm3HgdNeutralNoPower()
    { return true; }

// A good owner winds a
// protection from evil in a
// 10-foot radius for 10
// rounds; each friendly or
// allied creature in the area
// is affected as if granted
// the spell.
inline bool uamm3HgdGoodProtectionFromEvil()
    { return true; }

inline int uamm3HgdRadiusFt()
    { return 10; }

inline int uamm3HgdDurationRounds()
    { return 10; }

inline bool uamm3HgdAlliesAffectedToo()
    { return true; }

// An evil horn works the
// reverse of the noted spell
// within the area; the horn
// is blown but once per day.
inline bool uamm3HgdEvilReversesSpell()
    { return true; }

inline bool uamm3HgdOncePerDay()
    { return true; }

// ---- the part ledger ----
// Eleven G-H items: two fully
// clean, nine flagged, none
// fully garbled.
inline int uamm3PartItemTotal()
    { return 11; }

inline int uamm3PartCleanCount()
    { return 2; }

inline int uamm3PartFlaggedCount()
    { return 9; }

inline int uamm3PartGarbledCount()
    { return 0; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uamiscprose3.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 103, 'b inline count'
assert s.count('R383') == 1, 'b round tag'
assert s.count(
    'uamm3GemMinValueGp'
    ) >= 1, 'b fn'
assert 'uafol' not in s, 'b no uafol ref'
assert 'uanw' not in s, 'b no uanw ref'
assert 'uacm' not in s, 'b no uacm ref'
assert 'uaarm' not in s, 'b no uaarm ref'
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
assert s.count('uamm') == s.count(
    'uamm3'), 'b no R381/R382 uamm ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R383' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **The new miscellaneous magic',
        '      items** (pp. 97-104) - the named',
        '      additions: the Egg of Reason, the',
        '      Girdle of Many Pouches, the',
        '      Gloves of Missile Snaring, the',
        '      Hat of Difference, the Heward',
        '      haversack, the Horn of Fog, the',
        '      Prison of Zagyg, the Quiver of',
        '      Ehlonna, the Robe of Stars, the',
        '      Scarab versus Golems, the Shadow',
        '      Lanthorn, the Sheet of Smallness.',
        '      - AMENDED R381: the misc magic',
        '        prose part 1 pin round',
        '        (rules/uamiscprose1.h) - the',
        '        A-C stretch, THIRTEEN items',
        '        pin: EIGHT fully clean (the',
        '        beads of force, the boots of',
        '        the north, the boots winged,',
        '        the bracers of archery, the',
        '        bracers of brachiation, the',
        '        cloak of arachnidia, the',
        '        cloak of the bat, the',
        '        cyclocone) plus FIVE',
        '        mechanics-clean with flagged',
        '        holes (the amulet versus',
        "        undead's 9th-level cell, the",
        "        anything item's tail, the",
        "        boccob book's save cell and",
        '        scribing tail, the boots of',
        "        varied tracks' row-one",
        '        print, the chime of',
        "        interruption's opening);",
        '        NOTHING in A-C fully garbles',
        '        - the item stays OPEN for',
        '        D-Z and the PDF.',
        '      - AMENDED R382: the misc magic',
        '        prose part 2 pin round',
        '        (rules/uamiscprose2.h) - the',
        '        D-E stretch, EIGHT items pin:',
        '        ONE fully clean (the dust of',
        '        tracelessness) plus SEVEN',
        '        mechanics-clean with flagged',
        "        holes (the deck of illusions'",
        "        card list, the dicerion's",
        '        description seam, the dust of',
        "        dryness' elemental-save cell,",
        "        the dust of illusion's intro,",
        "        the egg of desire's int seam,",
        "        the egg of reason's 18+ cell,",
        "        the egg of shattering's attack",
        '        seam); NOTHING in D-E fully',
        '        garbles - the item stays OPEN',
        '        for F-Z and the PDF.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = OLD + NL + NL.join([
        '      - AMENDED R383: the misc magic',
        '        prose part 3 pin round',
        '        (rules/uamiscprose3.h) - the',
        '        G-H stretch, ELEVEN items pin:',
        '        TWO fully clean (the gloves of',
        '        missile snaring, the hat of',
        '        stupidity) plus NINE',
        '        mechanics-clean with flagged',
        "        holes (the gem of insight's",
        '        recall seam, the girdle of',
        "        dwarvenkind's racial block, the",
        "        girdle of many pouches' tail,",
        "        the gloves of thievery's level",
        "        cells, the hat of difference's",
        '        loss seam, the hat of',
        "        disguise's removal seam, the",
        "        haversack's quart merge, the",
        "        horn of fog's rounds/minutes",
        "        seam, the horn of goodness'",
        '        eaten header); NOTHING in G-H',
        '        fully garbles - the item stays',
        '        OPEN for I-Z and the PDF.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the amendment')
wr(GP, s)
# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [ ] **The new miscellaneous magic'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R383'
) == 1, 'c amendment'
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
    '(rules/uamiscprose3.h)'
) == 1, 'c misc3 note'
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


# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R383 UA misc magic prose part 3 pin audit' in s:
    already.append('regtest.cpp: the R383 audit')
else:
    INC_ANCH = ('#include "rules/uamiscprose2.h"  // '
        'R382: the UA misc magic prose 2')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamiscprose3.h"  // R383: the UA misc magic prose 3'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R383: the UA misc magic
    // prose part 3 pin audit ----
    // The G-H stretch: eleven pins -
    // two fully clean (the gloves of
    // missile snaring, the hat of
    // stupidity) plus nine
    // mechanics-clean with flagged
    // holes (the gem of insight's
    // recall seam, the girdle of
    // dwarvenkind's racial block, the
    // girdle of many pouches' tail,
    // the gloves of thievery's level
    // cells, the hat of difference's
    // loss seam, the hat of disguise's
    // removal seam, the haversack's
    // quart merge, the horn of fog's
    // rounds/minutes seam, the horn of
    // goodness' eaten header); the
    // R382 seam the part-2 ledger,
    // the R375 seam the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the gem of insight ----
            if (uamm3GemMinValueGp() != 5000) ++bad;
            if (!uamm3GemFaintEnchantmentAura()) ++bad;
            if (uamm3GemFeelPowerWeeks() != 1) ++bad;
            if (uamm3GemUnderstandAfterWeeks()
                    != 2) ++bad;
            if (uamm3GemIntGain() != 1) ++bad;
            if (uamm3GemWisGain() != 1) ++bad;
            if (uamm3GemKeepMonths() != 3) ++bad;
            if (!uamm3GemIntStaysBeyondPeriod())
                ++bad;
            if (!uamm3GemWisLostBeyondPeriod())
                ++bad;
            if (!uamm3GemSecondGemInert()) ++bad;
            if (!uamm3GemRecallSeamGarbles())
                ++bad;
            // the understanding arrives
            // at twice the feel-power week
            if (2 * uamm3GemFeelPowerWeeks()
                    != uamm3GemUnderstandAfterWeeks())
                ++bad;
        // ---- the girdle of
        // dwarvenkind ----
            if (uamm3GdkChaNonDwarvesAdj()
                    != -1) ++bad;
            if (uamm3GdkChaStoutHalflingsAdj()
                    != 1) ++bad;
            if (uamm3GdkChaGnomesAdj() != 1)
                ++bad;
            if (uamm3GdkChaDwarvesAdj() != 2)
                ++bad;
            if (!uamm3GdkSpeaksDwarvish()) ++bad;
            if (!uamm3GdkUndergroundSaveBonusesApply())
                ++bad;
            if (!uamm3GdkBenefitsOnlyWhileWorn())
                ++bad;
            if (!uamm3GdkNoGiantTypeAcBenefit())
                ++bad;
            if (!uamm3GdkNoExtraLanguages()) ++bad;
            if (!uamm3GdkRacialBlockGarbles())
                ++bad;
            // dwarves regard at twice
            // the stout-halfling gain
            if (2 * uamm3GdkChaStoutHalflingsAdj()
                    != uamm3GdkChaDwarvesAdj())
                ++bad;
        // ---- the girdle of many
        // pouches ----
            if (!uamm3GmpStrongEnchantmentAura())
                ++bad;
            if (!uamm3GmpFainterAlterationAura())
                ++bad;
            if (uamm3GmpApparentPouches() != 8)
                ++bad;
            if (uamm3GmpTotalPouches() != 64)
                ++bad;
            if (uamm3GmpBehindEach() != 7) ++bad;
            if (uamm3GmpPouchCuFt() != 1) ++bad;
            if (uamm3GmpPouchLbs() != 10) ++bad;
            if (!uamm3GmpRespondsToThoughts())
                ++bad;
            if (!uamm3GmpFullOrEmptyAsDesired())
                ++bad;
            if (!uamm3GmpPrizedBySpellcasters())
                ++bad;
            if (!uamm3GmpTailSeamGarbles()) ++bad;
            // the 64 total = the eight
            // apparent x (the seven
            // behind + the one seen)
            if (uamm3GmpApparentPouches()
                    * (uamm3GmpBehindEach() + 1)
                    != uamm3GmpTotalPouches()) ++bad;
        // ---- the gloves of
        // missile snaring ----
            if (!uamm3GmsSlightEnchantmentAura())
                ++bad;
            if (!uamm3GmsMeldWithHands()) ++bad;
            if (uamm3GmsUndetectableBeyondFt()
                    != 5) ++bad;
            if (!uamm3GmsNeedEmptyHands()) ++bad;
            if (!uamm3GmsCatchHandHurled()) ++bad;
            if (!uamm3GmsCatchWeaponPropelled())
                ++bad;
            if (!uamm3GmsCanReturnMissile()) ++bad;
            if (!uamm3GmsMagicReturnPreventsOnly())
                ++bad;
            if (!uamm3GmsMagicReturnNoAttack())
                ++bad;
        // ---- the gloves of
        // thievery ----
            if (!uamm3GthFaintEnchantmentAura())
                ++bad;
            if (!uamm3GthInvisibleExceptMagic())
                ++bad;
            if (!uamm3GthLevelCellsGarble()) ++bad;
            if (uamm3GthBonusPctIfAdvanced() != 5)
                ++bad;
            if (!uamm3GthBonusNeedsStatedLevels())
                ++bad;
        // ---- the hat of
        // difference ----
            if (!uamm3HdfAssumesOtherProfession())
                ++bad;
            if (!uamm3HdfFirstLevelAbilityOnly())
                ++bad;
            if (!uamm3HdfXpInAssumedRole()) ++bad;
            if (!uamm3HdfXpCumulative()) ++bad;
            if (!uamm3HdfLevelRetainedOnRewearing())
                ++bad;
            if (!uamm3HdfProgressIndefinite())
                ++bad;
            if (!uamm3HdfLostIfDiscarded()) ++bad;
            if (!uamm3HdfLossSeamGarbles()) ++bad;
            if (!uamm3HdfHitPointsStayActual())
                ++bad;
            if (!uamm3HdfAbilityScoresStayActual())
                ++bad;
        // ---- the hat of disguise ----
            if (!uamm3HdgHairAnyColor()) ++bad;
            if (!uamm3HdgEyesAnyColor()) ++bad;
            if (!uamm3HdgComplexionAnyColor())
                ++bad;
            if (!uamm3HdgSexChange()) ++bad;
            if (!uamm3HdgFacialMutable()) ++bad;
            if (uamm3HdgHeightPct() != 25) ++bad;
            if (uamm3HdgWeightPct() != 50) ++bad;
            if (!uamm3HdgRemovalDispelsInstantly())
                ++bad;
            if (!uamm3HdgReusableOverAndOver())
                ++bad;
            if (!uamm3HdgRemovalSeamGarbles())
                ++bad;
            if (!uamm3HdgAppearsAsAccessories())
                ++bad;
            // the weight swing is
            // twice the height swing
            if (2 * uamm3HdgHeightPct()
                    != uamm3HdgWeightPct()) ++bad;
        // ---- the hat of
        // stupidity ----
            if (!uamm3HdsIndistinguishableByDetection())
                ++bad;
            if (!uamm3HdsOnlyWearingReveals())
                ++bad;
            if (!uamm3HdsWearerBelievesBeneficial())
                ++bad;
            if (!uamm3HdsWearerWantsHatOn()) ++bad;
            if (uamm3HdsIntLoweredTo() != 7) ++bad;
            if (uamm3HdsIntLoweredByIfAlreadyLow()
                    != 1) ++bad;
            if (!uamm3HdsOnlyRemoveCurseFrees())
                ++bad;
        // ---- the haversack ----
            if (!uamm3HavOrdinaryAppearance())
                ++bad;
            if (uamm3HavSidePouches() != 2) ++bad;
            if (uamm3HavSidePouchCuFt() != 2) ++bad;
            if (uamm3HavSidePouchLbs() != 20)
                ++bad;
            if (!uamm3HavQuartMergeGarbles())
                ++bad;
            if (uamm3HavCentralCuFt() != 8) ++bad;
            if (uamm3HavCentralLbs() != 80) ++bad;
            if (!uamm3HavSoughtItemOnTop()) ++bad;
            if (uamm3HavSaveBonus() != 2) ++bad;
            // the central portion is
            // four times a side pouch,
            // in both volume and
            // weight; the save bonus
            // matches the side-pouch
            // count
            if (4 * uamm3HavSidePouchCuFt()
                    != uamm3HavCentralCuFt()) ++bad;
            if (4 * uamm3HavSidePouchLbs()
                    != uamm3HavCentralLbs()) ++bad;
            if (uamm3HavSaveBonus()
                    != uamm3HavSidePouches()) ++bad;
        // ---- the horn of fog ----
            if (!uamm3HfgSmallBuglelike()) ++bad;
            if (!uamm3HfgFogCloudEquivalent())
                ++bad;
            if (uamm3HfgCubePerRoundFt() != 10)
                ++bad;
            if (uamm3HfgCloudLastsLoRounds()
                    != 2) ++bad;
            if (uamm3HfgCloudLastsHiRounds()
                    != 8) ++bad;
            if (!uamm3HfgPauseStartsNewCloud())
                ++bad;
            if (!uamm3HfgRoundsMinutesSeamGarbles())
                ++bad;
        // ---- the horn of
        // goodness ----
            if (!uamm3HgdAdaptsToEthicalDisposition())
                ++bad;
            if (!uamm3HgdHeaderSeamGarbles()) ++bad;
            if (!uamm3HgdNeutralNoPower()) ++bad;
            if (!uamm3HgdGoodProtectionFromEvil())
                ++bad;
            if (uamm3HgdRadiusFt() != 10) ++bad;
            if (uamm3HgdDurationRounds() != 10)
                ++bad;
            if (!uamm3HgdAlliesAffectedToo())
                ++bad;
            if (!uamm3HgdEvilReversesSpell()) ++bad;
            if (!uamm3HgdOncePerDay()) ++bad;
            // the protection radius
            // matches the duration,
            // both 10
            if (uamm3HgdRadiusFt()
                    != uamm3HgdDurationRounds()) ++bad;
        // ---- the part ledger ----
            if (uamm3PartItemTotal() != 11) ++bad;
            if (uamm3PartCleanCount() != 2) ++bad;
            if (uamm3PartFlaggedCount() != 9)
                ++bad;
            if (uamm3PartGarbledCount() != 0)
                ++bad;
            if (uamm3PartCleanCount()
                    + uamm3PartFlaggedCount()
                    + uamm3PartGarbledCount()
                    != uamm3PartItemTotal()) ++bad;
        // ---- the R382 part-2 seam ----
            if (uamm2PartItemTotal() != 8) ++bad;
            if (uamm2PartCleanCount() != 1) ++bad;
            if (uamm2PartFlaggedCount() != 7)
                ++bad;
            if (uamm2PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R383 UA misc magic prose part 3 pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R383 audit')
s = rd(RT)
assert s.count(
    'R383 UA misc magic prose part 3 pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 310, 'd census 310'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uamiscprose3.h"'
) == 1, 'd new include'
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
    'R383 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R383 note: the misc magic',
    'prose part 3 round - the',
    'G-H stretch, eleven items',
    'pin: two fully clean (the',
    'gloves of missile snaring,',
    'the hat of stupidity) plus',
    'nine mechanics-clean with',
    'flagged holes (the gem of',
    'insight, the girdle of',
    'dwarvenkind, the girdle of',
    'many pouches, the gloves of',
    'thievery, the hat of',
    'difference, the hat of',
    'disguise, the haversack,',
    'the horn of fog, the horn',
    'of goodness); nothing in',
    'G-H fully garbles - the',
    'item AMENDED, stays OPEN',
    'for I-Z, PDF-gated; the',
    'R382 seam the part-2',
    'ledger, the R375 seam the',
    'misc band; the census',
    '309 -> 310'
])
print(NOTE)
print('commit: R383: the UA misc')
print('magic prose part 3 pin round')
print('(census 310)')

