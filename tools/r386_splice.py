

# R386: the UA misc magic
# prose part 6 pin round (the
# S-Z close-out): FIVE items
# pin - TWO fully clean (the
# wind fan, Zagyg's flowing
# flagon) plus THREE
# mechanics-clean with flagged
# holes (the stone horse's
# activation word seam, the
# ultimate solution's
# transmutation seam, Zagyg's
# spell component case's gp
# tail); NOTHING in S-Z fully
# garbles - the gap item
# AMENDED with the part-6
# note, the prose pinned A-Z,
# stays PDF-gated only; the
# R385 seam the part-5
# ledger, the R375 seam the
# misc band; the census
# 312 -> 313.
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


# ---- (a) the seed: the R385 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R385 landed 2026-10-12: commit',
    '  cc5a2bc, census 312, the UA',
    '  misc magic prose part 5 pin',
    '  round (rules/uamiscprose5.h):',
    '  eleven Q-S items pin - seven',
    '  fully clean (the robe of',
    '  stars, the scarab versus',
    '  golems, the shadow lanthorn,',
    '  the shoes of Fharlanghn, the',
    '  slippers of kicking, the',
    '  slippers of spider climbing,',
    '  the sovereign glue) plus four',
    '  mechanics-clean with flagged',
    '  holes (the quiver of',
    "  Ehlonna's command sentence,",
    '  the robe of vermin\'s removal',
    '  tail, the sheet of smallness\'',
    '  intro seam, the spoon of',
    "  stirring's table cell);",
    '  nothing in Q-S fully garbles -',
    '  the item AMENDED, stays OPEN',
    '  for S-Z, PDF-gated; the R384',
    '  seam the part-4 ledger, the',
    '  R375 seam the misc band;',
    '  GREEN on the first run.'
])
s = rd(SD)
if 'R385 landed 2026-10-12' in s:
    already.append('seed: the R385 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R385 record')
s = rd(SD)
assert s.count(
    'R385 landed 2026-10-12'
) == 1, 'a entry'


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


# ---- (b) NEW rules/uamiscprose6.h ----
P = 'rules/uamiscprose6.h'
if os.path.exists(P) and 'R386' in rd(P):
    already.append('uamiscprose6.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uamiscprose6.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 6, R386: the
// S-Z close-out - five pins,
// two fully clean (the wind
// fan, Zagyg's flowing
// flagon) plus three
// mechanics-clean with
// flagged holes (the stone
// horse's activation word
// seam, the ultimate
// solution's transmutation
// seam, Zagyg's spell
// component case's gp tail).
// Nothing in S-Z fully
// garbles; with parts 1-5
// the prose stands pinned
// A-Z. The part-5 and
// skeleton seams ride in
// the regtest audit, not
// here.
namespace rules {

// ---- the stone horse ----
// A full-sized, roughly-hewn
// statue of a horse carved
// from some type of hard
// stone; two sorts exist.
inline bool uamm6ShStatueAppearance()
    { return true; }

inline bool uamm6ShCarvedFromHardStone()
    { return true; }

inline int uamm6ShTwoSorts()
    { return 2; }

// The activation-word
// sentence OCR-scrambles;
// the reconstruction: the
// dweomer activates on a
// spoken word, bringing the
// steed to animation,
// enabling it to carry a
// burden and attack as a
// warhorse; flagged.
inline bool uamm6ShActivationWord()
    { return true; }

inline bool uamm6ShAnimateCarryAttack()
    { return true; }

inline bool uamm6ShActivationSeamGarbles()
    { return true; }

// A stone horse carries
// 1,000 pounds tirelessly
// and never needs to rest
// or feed.
inline int uamm6ShCarriesLbs()
    { return 1000; }

inline bool uamm6ShTirelessNoFeeding()
    { return true; }

// Damage repaired by first
// using a stone to flesh
// spell, turning it into a
// normal horse; grazing and
// resting, it heals 1 point
// per day and automatically
// reverts to magical form
// when fully healed.
inline bool uamm6ShRepairByStoneToFlesh()
    { return true; }

inline int uamm6ShHealPerDay()
    { return 1; }

inline bool uamm6ShRevertsWhenHealed()
    { return true; }

// ---- the courser ----
// The courser travels at
// the light-horse movement
// rate and attacks as a
// medium warhorse: three
// attacks for 1-6/1-6/1-3.
inline bool uamm6CrsLightHorseRate()
    { return true; }

inline bool uamm6CrsMediumWarhorseAttacks()
    { return true; }

inline int uamm6CrsAttacksPerRound()
    { return 3; }

inline int uamm6CrsHoofDamageLo()
    { return 1; }

inline int uamm6CrsHoofDamageHi()
    { return 6; }

inline int uamm6CrsThirdAttackDamageLo()
    { return 1; }

inline int uamm6CrsThirdAttackDamageHi()
    { return 3; }

inline int uamm6CrsArmorClass()
    { return 3; }

inline int uamm6CrsHitPoints()
    { return 18; }

inline bool uamm6CrsSavesAsHardMetal()
    { return true; }

// ---- the destrier ----
// The destrier travels at
// the medium-horse movement
// rate and attacks as a
// heavy warhorse: three
// attacks for 1-8/1-8/1-3.
inline bool uamm6DstMediumHorseRate()
    { return true; }

inline bool uamm6DstHeavyWarhorseAttacks()
    { return true; }

inline int uamm6DstAttacksPerRound()
    { return 3; }

inline int uamm6DstHoofDamageLo()
    { return 1; }

inline int uamm6DstHoofDamageHi()
    { return 8; }

inline int uamm6DstThirdAttackDamageLo()
    { return 1; }

inline int uamm6DstThirdAttackDamageHi()
    { return 3; }

inline int uamm6DstArmorClass()
    { return 1; }

inline int uamm6DstHitPoints()
    { return 26; }

inline bool uamm6DstSavesAsHardMetal()
    { return true; }

// ---- the ultimate
// solution ----
// A strange magical liquid
// appearing nothing more
// remarkable than some
// minor oil or potion; upon
// first examination it
// seems to have the
// properties of both oil of
// slipperiness and a potion
// of delusion.
inline bool uamm6UsoMinorOilAppearance()
    { return true; }

inline bool uamm6UsoSeemsSlipperinessAndDelusion()
    { return true; }

// Applied to any form of
// adhesive or sticky
// material, the solution
// immediately dissolves
// it - the effect of
// sovereign glue is
// immediately negated, as
// is any other cement,
// glue, or adhesive.
inline bool uamm6UsoDissolvesAdhesives()
    { return true; }

inline bool uamm6UsoNegatesSovereignGlue()
    { return true; }

// The area of effect is 1
// cubic foot per ounce; a
// typical container holds
// 27 ounces.
inline int uamm6UsoCuFtPerOunce()
    { return 1; }

inline int uamm6UsoContainerOunces()
    { return 27; }

// The concentrated
// transmutation sentence
// OCR-scrambles; the
// reconstruction: distilled
// down to one-third of its
// original volume, each
// ounce dissolves 1 cubic
// foot of material, organic
// or inorganic, as the
// transmutation spell;
// flagged.
inline bool uamm6UsoDistillToThird()
    { return true; }

inline int uamm6UsoDistilledOunces()
    { return 9; }

inline int uamm6UsoDistilledCuFtPerOunce()
    { return 1; }

inline bool uamm6UsoTransmutationSeamGarbles()
    { return true; }

// A living target requires a
// successful roll to hit and
// is entitled to a saving
// throw versus spell;
// inanimate objects are
// automatically affected,
// but magic items gain a
// saving throw versus
// disintegrate.
inline bool uamm6UsoLivingNeedsToHit()
    { return true; }

inline bool uamm6UsoLivingSaveVsSpell()
    { return true; }

inline bool uamm6UsoInanimateAutomatic()
    { return true; }

inline bool uamm6UsoMagicItemsSaveVsDisintegrate()
    { return true; }

// ---- the wind fan ----
// A magical apparatus
// appearing nothing more
// than a wood and papyrus
// or cloth instrument for
// creating a cooling breeze.
inline bool uamm6WfaCoolingBreezeAppearance()
    { return true; }

// Uttering the correct word
// generates air exactly
// duplicating a gust of wind
// spell as if cast by a
// 5th-level magic-user.
inline bool uamm6WfaWordTriggersGust()
    { return true; }

inline int uamm6WfaCasterLevel()
    { return 5; }

// The fan is usable once per
// day with no risk; more
// frequent use carries a
// cumulative 20% chance per
// usage of tearing into
// useless, non-magical
// tatters.
inline bool uamm6WfaOncePerDaySafe()
    { return true; }

inline int uamm6WfaTearChancePctPerUse()
    { return 20; }

inline bool uamm6WfaTearsNonMagical()
    { return true; }

// ---- Zagyg's flowing
// flagon ----
// A well-made vessel,
// usually of nickel-silver,
// engraved and sculpted with
// grapes, vines, wine
// cellars, and drinking
// scenes; somewhere on it a
// line of magical writing -
// the words of a toast.
inline bool uamm6ZffNickelSilverVessel()
    { return true; }

inline bool uamm6ZffEngravedDrinkingScenes()
    { return true; }

inline bool uamm6ZffToastLineOnVessel()
    { return true; }

// The first individual to
// pick up the flagon reads
// the toast; no other can,
// normally or magically,
// until becoming the owner.
inline bool uamm6ZffFirstPickerReadsOnly()
    { return true; }

inline bool uamm6ZffOwnerOnlyUntilOwned()
    { return true; }

// The phrase is read to
// activate; each activation
// changes the phrase.
inline bool uamm6ZffReadToActivate()
    { return true; }

inline bool uamm6ZffPhraseChangesEachUse()
    { return true; }

// The six-draught ladder:
// the weak wine about 7%
// alcohol, then 10%, 13%,
// port-like 20%, the
// near-liquor 40%, and the
// sixth and last draught a
// brandy-like 80%.
inline int uamm6ZffDraughtCount()
    { return 6; }

inline int uamm6ZffFirstAlcoholPct()
    { return 7; }

inline int uamm6ZffSecondAlcoholPct()
    { return 10; }

inline int uamm6ZffThirdAlcoholPct()
    { return 13; }

inline int uamm6ZffFourthAlcoholPct()
    { return 20; }

inline int uamm6ZffFifthAlcoholPct()
    { return 40; }

inline int uamm6ZffSixthAlcoholPct()
    { return 80; }

// The typical flagon holds
// about 1 pint (16 ounces);
// it is 90% unlikely that
// any partaker of the first
// draught notices the
// increase in alcohol; the
// flagon is usable a
// maximum of three times
// per day.
inline int uamm6ZffPintOunces()
    { return 16; }

inline int uamm6ZffNoticeUnlikelyPct()
    { return 90; }

inline int uamm6ZffUsesPerDay()
    { return 3; }

// ---- Zagyg's spell
// component case ----
// A normal belt pouch of
// unremarkable sort
// radiating a faint magic
// aura if detected for.
inline bool uamm6ZscBeltPouchAppearance()
    { return true; }

inline bool uamm6ZscFaintMagicAura()
    { return true; }

// A magic-user thinking of
// the material components
// desired for a spell finds
// them appearing in the
// pouch; unused within 1
// round they immediately
// disappear and the usage
// is wasted; employed in
// casting, they likewise
// disappear as soon as the
// spell is cast.
inline bool uamm6ZscComponentsOnThought()
    { return true; }

inline int uamm6ZscVanishAfterRounds()
    { return 1; }

inline bool uamm6ZscWastedIfUnused()
    { return true; }

inline bool uamm6ZscVanishOnCasting()
    { return true; }

// The uses-per-day table:
// six rows, from 2 times per
// day to 7; the XP value is
// 100 times the uses (200
// to 700); the sale value
// is 1,000 times (2,000 to
// 7,000) - the printed gp
// tail truncates ("7,00");
// flagged.
inline int uamm6ZscTableRows()
    { return 6; }

inline int uamm6ZscUsesLo()
    { return 2; }

inline int uamm6ZscUsesHi()
    { return 7; }

inline int uamm6ZscXpPerUse()
    { return 100; }

inline int uamm6ZscGpPerUse()
    { return 1000; }

inline bool uamm6ZscGpTailGarbles()
    { return true; }

// ---- the part ledger ----
// Five S-Z items: two fully
// clean, three flagged, none
// fully garbled.
inline int uamm6PartItemTotal()
    { return 5; }

inline int uamm6PartCleanCount()
    { return 2; }

inline int uamm6PartFlaggedCount()
    { return 3; }

inline int uamm6PartGarbledCount()
    { return 0; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uamiscprose6.h: the pins')


s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 84, 'b inline count'
assert s.count('R386') == 1, 'b round tag'
assert s.count(
    'uamm6ShStatueAppearance'
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
assert 'uamm5' not in s, 'b no uamm5 ref'
assert s.count('uamm') == s.count(
    'uamm6'), 'b no R381-R385 uamm ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap report: the
# amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R386' in s:
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
        '        for F-Z and the PDF.',
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
        '        OPEN for I-Z and the PDF.',
        '      - AMENDED R384: the misc magic',
        '        prose part 4 pin round',
        '        (rules/uamiscprose4.h) - the',
        '        I-P stretch, NINE items pin:',
        '        FIVE fully clean (the iron',
        '        bands of Bilarro, the lens of',
        '        detection, the mantle of',
        '        Celestian, the pearl of the',
        '        sirines, the pouch of',
        '        accessibility) plus FOUR',
        '        mechanics-clean with flagged',
        '        holes (the lens of',
        "        ultravision's diameter cell,",
        "        Murlynd's spoon's gruel tail,",
        "        the philosopher's stone's",
        '        transmutation cells, the',
        "        prison of Zagyg's attunement",
        '        seam); NOTHING in I-P fully',
        '        garbles - the item stays OPEN',
        '        for Q-Z and the PDF.',
        '      - AMENDED R385: the misc magic',
        '        prose part 5 pin round',
        '        (rules/uamiscprose5.h) - the',
        '        Q-S stretch, ELEVEN items pin:',
        '        SEVEN fully clean (the robe of',
        '        stars, the scarab versus',
        '        golems, the shadow lanthorn,',
        '        the shoes of Fharlanghn, the',
        '        slippers of kicking, the',
        '        slippers of spider climbing,',
        '        the sovereign glue) plus FOUR',
        '        mechanics-clean with flagged',
        "        holes (the quiver of Ehlonna's",
        '        command sentence, the robe of',
        "        vermin's removal tail, the",
        "        sheet of smallness' intro",
        "        seam, the spoon of stirring's",
        '        table cell); NOTHING in Q-S',
        '        fully garbles - the item stays',
        '        OPEN for S-Z and the PDF.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = OLD + NL + NL.join([
        '      - AMENDED R386: the misc magic',
        '        prose part 6 pin round',
        '        (rules/uamiscprose6.h) - the',
        '        S-Z close-out, FIVE items pin:',
        '        TWO fully clean (the wind fan,',
        "        Zagyg's flowing flagon) plus",
        '        THREE mechanics-clean with',
        '        flagged holes (the stone',
        "        horse's activation word seam,",
        "        the ultimate solution's",
        '        transmutation seam,',
        "        Zagyg's spell component case's",
        '        gp tail); NOTHING in S-Z fully',
        '        garbles - the item AMENDED,',
        '        the prose pinned A-Z, stays',
        '        PDF-gated only.'
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
    'AMENDED R386'
) == 1, 'c amendment'
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
    '(rules/uamiscprose6.h)'
) == 1, 'c misc6 note'
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
if 'R386 UA misc magic prose part 6 pin audit' in s:
    already.append('regtest.cpp: the R386 audit')
else:
    INC_ANCH = ('#include "rules/uamiscprose5.h"  // '
        'R385: the UA misc magic prose 5')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamiscprose6.h"  // R386: the UA misc magic prose 6'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R386: the UA misc magic
    // prose part 6 pin audit ----
    // The S-Z close-out: five pins -
    // two fully clean (the wind fan,
    // Zagyg's flowing flagon) plus
    // three mechanics-clean with
    // flagged holes (the stone
    // horse's activation word seam,
    // the ultimate solution's
    // transmutation seam, Zagyg's
    // spell component case's gp
    // tail); the R385 seam the
    // part-5 ledger, the R375 seam
    // the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the stone horse ----
            if (!uamm6ShStatueAppearance()) ++bad;
            if (!uamm6ShCarvedFromHardStone())
                ++bad;
            if (uamm6ShTwoSorts() != 2) ++bad;
            if (!uamm6ShActivationWord()) ++bad;
            if (!uamm6ShAnimateCarryAttack())
                ++bad;
            if (!uamm6ShActivationSeamGarbles())
                ++bad;
            if (uamm6ShCarriesLbs() != 1000)
                ++bad;
            if (!uamm6ShTirelessNoFeeding())
                ++bad;
            if (!uamm6ShRepairByStoneToFlesh())
                ++bad;
            if (uamm6ShHealPerDay() != 1) ++bad;
            if (!uamm6ShRevertsWhenHealed())
                ++bad;
        // ---- the courser ----
            if (!uamm6CrsLightHorseRate()) ++bad;
            if (!uamm6CrsMediumWarhorseAttacks())
                ++bad;
            if (uamm6CrsAttacksPerRound() != 3)
                ++bad;
            if (uamm6CrsHoofDamageLo() != 1)
                ++bad;
            if (uamm6CrsHoofDamageHi() != 6)
                ++bad;
            if (uamm6CrsThirdAttackDamageLo()
                    != 1) ++bad;
            if (uamm6CrsThirdAttackDamageHi()
                    != 3) ++bad;
            if (uamm6CrsArmorClass() != 3) ++bad;
            if (uamm6CrsHitPoints() != 18) ++bad;
            if (!uamm6CrsSavesAsHardMetal())
                ++bad;
        // ---- the destrier ----
            if (!uamm6DstMediumHorseRate())
                ++bad;
            if (!uamm6DstHeavyWarhorseAttacks())
                ++bad;
            if (uamm6DstAttacksPerRound() != 3)
                ++bad;
            if (uamm6DstHoofDamageLo() != 1)
                ++bad;
            if (uamm6DstHoofDamageHi() != 8)
                ++bad;
            if (uamm6DstThirdAttackDamageLo()
                    != 1) ++bad;
            if (uamm6DstThirdAttackDamageHi()
                    != 3) ++bad;
            if (uamm6DstArmorClass() != 1) ++bad;
            if (uamm6DstHitPoints() != 26) ++bad;
            if (!uamm6DstSavesAsHardMetal())
                ++bad;
            // both steeds attack
            // three times with the
            // same rear-attack die
            if (uamm6CrsAttacksPerRound()
                    != uamm6DstAttacksPerRound())
                ++bad;
            if (uamm6CrsThirdAttackDamageLo()
                    != uamm6DstThirdAttackDamageLo())
                ++bad;
            if (uamm6CrsThirdAttackDamageHi()
                    != uamm6DstThirdAttackDamageHi())
                ++bad;
            // the destrier bests the
            // courser by two armor
            // classes and eight hit
            // points, with hoof dice
            // 8 over 6
            if (uamm6CrsArmorClass()
                    - uamm6DstArmorClass() != 2)
                ++bad;
            if (uamm6DstHitPoints()
                    - uamm6CrsHitPoints() != 8)
                ++bad;
            if (uamm6DstHoofDamageHi()
                    - uamm6CrsHoofDamageHi()
                    != 2) ++bad;
        // ---- the ultimate
        // solution ----
            if (!uamm6UsoMinorOilAppearance())
                ++bad;
            if (!uamm6UsoSeemsSlipperinessAndDelusion())
                ++bad;
            if (!uamm6UsoDissolvesAdhesives())
                ++bad;
            if (!uamm6UsoNegatesSovereignGlue())
                ++bad;
            if (uamm6UsoCuFtPerOunce() != 1)
                ++bad;
            if (uamm6UsoContainerOunces() != 27)
                ++bad;
            if (!uamm6UsoDistillToThird()) ++bad;
            if (uamm6UsoDistilledOunces() != 9)
                ++bad;
            if (uamm6UsoDistilledCuFtPerOunce()
                    != 1) ++bad;
            if (!uamm6UsoTransmutationSeamGarbles())
                ++bad;
            if (!uamm6UsoLivingNeedsToHit())
                ++bad;
            if (!uamm6UsoLivingSaveVsSpell())
                ++bad;
            if (!uamm6UsoInanimateAutomatic())
                ++bad;
            if (!uamm6UsoMagicItemsSaveVsDisintegrate())
                ++bad;
            // the distillation to a
            // third: 27 ounces down
            // to 9
            if (3 * uamm6UsoDistilledOunces()
                    != uamm6UsoContainerOunces())
                ++bad;
        // ---- the wind fan ----
            if (!uamm6WfaCoolingBreezeAppearance())
                ++bad;
            if (!uamm6WfaWordTriggersGust())
                ++bad;
            if (uamm6WfaCasterLevel() != 5) ++bad;
            if (!uamm6WfaOncePerDaySafe()) ++bad;
            if (uamm6WfaTearChancePctPerUse()
                    != 20) ++bad;
            if (!uamm6WfaTearsNonMagical())
                ++bad;
            // the cumulative 20%
            // reaches certainty at
            // the fifth extra usage
            if (5 * uamm6WfaTearChancePctPerUse()
                    != 100) ++bad;
        // ---- Zagyg's flowing
        // flagon ----
            if (!uamm6ZffNickelSilverVessel())
                ++bad;
            if (!uamm6ZffEngravedDrinkingScenes())
                ++bad;
            if (!uamm6ZffToastLineOnVessel())
                ++bad;
            if (!uamm6ZffFirstPickerReadsOnly())
                ++bad;
            if (!uamm6ZffOwnerOnlyUntilOwned())
                ++bad;
            if (!uamm6ZffReadToActivate()) ++bad;
            if (!uamm6ZffPhraseChangesEachUse())
                ++bad;
            if (uamm6ZffDraughtCount() != 6) ++bad;
            if (uamm6ZffFirstAlcoholPct() != 7)
                ++bad;
            if (uamm6ZffSecondAlcoholPct() != 10)
                ++bad;
            if (uamm6ZffThirdAlcoholPct() != 13)
                ++bad;
            if (uamm6ZffFourthAlcoholPct() != 20)
                ++bad;
            if (uamm6ZffFifthAlcoholPct() != 40)
                ++bad;
            if (uamm6ZffSixthAlcoholPct() != 80)
                ++bad;
            if (uamm6ZffPintOunces() != 16) ++bad;
            if (uamm6ZffNoticeUnlikelyPct() != 90)
                ++bad;
            if (uamm6ZffUsesPerDay() != 3) ++bad;
            // the wine ladder: two
            // steps of three, then
            // doubling to the top
            if (uamm6ZffSecondAlcoholPct()
                    - uamm6ZffFirstAlcoholPct()
                    != 3) ++bad;
            if (uamm6ZffThirdAlcoholPct()
                    - uamm6ZffSecondAlcoholPct()
                    != 3) ++bad;
            if (2 * uamm6ZffFourthAlcoholPct()
                    != uamm6ZffFifthAlcoholPct())
                ++bad;
            if (2 * uamm6ZffFifthAlcoholPct()
                    != uamm6ZffSixthAlcoholPct())
                ++bad;
            // the noticing chance is
            // the certain remainder
            if (100 - uamm6ZffNoticeUnlikelyPct()
                    != 10) ++bad;
        // ---- Zagyg's spell
        // component case ----
            if (!uamm6ZscBeltPouchAppearance())
                ++bad;
            if (!uamm6ZscFaintMagicAura()) ++bad;
            if (!uamm6ZscComponentsOnThought())
                ++bad;
            if (uamm6ZscVanishAfterRounds() != 1)
                ++bad;
            if (!uamm6ZscWastedIfUnused()) ++bad;
            if (!uamm6ZscVanishOnCasting()) ++bad;
            if (uamm6ZscTableRows() != 6) ++bad;
            if (uamm6ZscUsesLo() != 2) ++bad;
            if (uamm6ZscUsesHi() != 7) ++bad;
            if (uamm6ZscXpPerUse() != 100) ++bad;
            if (uamm6ZscGpPerUse() != 1000) ++bad;
            if (!uamm6ZscGpTailGarbles()) ++bad;
            // the xp and gp values
            // ride the uses band:
            // 200 to 700 XP, 2,000
            // to 7,000 gp
            if (uamm6ZscXpPerUse()
                    * uamm6ZscUsesLo() != 200)
                ++bad;
            if (uamm6ZscXpPerUse()
                    * uamm6ZscUsesHi() != 700)
                ++bad;
            if (uamm6ZscGpPerUse()
                    * uamm6ZscUsesLo() != 2000)
                ++bad;
            if (uamm6ZscGpPerUse()
                    * uamm6ZscUsesHi() != 7000)
                ++bad;
            // the gp rate is ten
            // times the xp rate
            if (10 * uamm6ZscXpPerUse()
                    != uamm6ZscGpPerUse()) ++bad;
        // ---- the part ledger ----
            if (uamm6PartItemTotal() != 5) ++bad;
            if (uamm6PartCleanCount() != 2) ++bad;
            if (uamm6PartFlaggedCount() != 3)
                ++bad;
            if (uamm6PartGarbledCount() != 0)
                ++bad;
            if (uamm6PartCleanCount()
                    + uamm6PartFlaggedCount()
                    + uamm6PartGarbledCount()
                    != uamm6PartItemTotal()) ++bad;
        // ---- the R385 part-5 seam ----
            if (uamm5PartItemTotal() != 11) ++bad;
            if (uamm5PartCleanCount() != 7) ++bad;
            if (uamm5PartFlaggedCount() != 4)
                ++bad;
            if (uamm5PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R386 UA misc magic prose part 6 pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R386 audit')


s = rd(RT)
assert s.count(
    'R386 UA misc magic prose part 6 pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 313, 'd census 313'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uamiscprose6.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uamiscprose5.h"'
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
    'R386 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R386 note: the misc magic',
    'prose part 6 round - the',
    'S-Z close-out, five items',
    'pin: two fully clean (the',
    "wind fan, Zagyg's flowing",
    'flagon) plus three',
    'mechanics-clean with',
    'flagged holes (the stone',
    'horse, the ultimate',
    'solution, the spell',
    'component case); nothing',
    'in S-Z fully garbles - the',
    'item AMENDED, the prose',
    'pinned A-Z, stays',
    'PDF-gated only; the R385',
    'seam the part-5 ledger, the',
    'R375 seam the misc band;',
    'the census 312 -> 313'
])
print(NOTE)
print('commit: R386: the UA misc')
print('magic prose part 6 pin round')
print('(census 313)')

