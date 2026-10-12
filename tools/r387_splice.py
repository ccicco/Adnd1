

# R387: the UA armor and
# swords prose pin round: the
# pp. 104-105 stretch, EIGHT
# items pin - FOUR fully clean
# (the anything armor, the
# short sword of quickness,
# the sword of the planes,
# the anything sword) plus
# FOUR mechanics-clean with
# flagged holes (the elfin
# chain mail's size-table
# garble, the plate's
# conform seam, the sun
# blade's radiance seam, the
# Final Word broadswords'
# names tail); NOTHING fully
# garbles - the item AMENDED
# with the R387 note, the
# prose pinned, stays
# PDF-gated only; the R386
# seam the part-6 ledger, the
# R375 seam the misc band;
# the census 313 -> 314.
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


# ---- (a) the seed: the R386 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R386 landed 2026-10-12: commit',
    '  e84e770, census 313, the UA',
    '  misc magic prose part 6 pin',
    '  round (rules/uamiscprose6.h):',
    '  five S-Z items pin - two',
    '  fully clean (the wind fan,',
    "  Zagyg's flowing flagon) plus",
    '  three mechanics-clean with',
    '  flagged holes (the stone',
    "  horse's activation word seam,",
    "  the ultimate solution's",
    '  transmutation seam,',
    "  Zagyg's spell component case's",
    '  gp tail); nothing in S-Z',
    '  fully garbles - the item',
    '  AMENDED, the prose pinned',
    '  A-Z, stays PDF-gated only;',
    '  the R385 seam the part-5',
    '  ledger, the R375 seam the',
    '  misc band; GREEN on the',
    '  first run.'
])
s = rd(SD)
if 'R386 landed 2026-10-12' in s:
    already.append('seed: the R386 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R386 record')
s = rd(SD)
assert s.count(
    'R386 landed 2026-10-12'
) == 1, 'a entry'


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


# ---- (b) NEW rules/uaarmprose.h ----
P = 'rules/uaarmprose.h'
if os.path.exists(P) and 'R387' in rd(P):
    already.append('uaarmprose.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaarmprose.h
// The UA TREASURE (ARMOR AND
// SHIELD / SWORDS) prose pins,
// R387: the pp. 104-105
// stretch - eight pins, four
// fully clean (the anything
// armor, the short sword of
// quickness, the sword of the
// planes, the anything sword)
// plus four mechanics-clean
// with flagged holes (the
// elfin chain mail's
// size-table garble, the
// plate's conform seam, the
// sun blade's radiance seam,
// the Final Word broadswords'
// names tail), riding the
// construction rule (+3
// meteorite iron, +4 mithral
// alloyed, +5 adamantite
// alloyed steel). Nothing
// fully garbles; the part-6
// and skeleton seams ride in
// the regtest audit, not
// here.
namespace rules {

// ---- the construction rule
// ----
// Except where this obviously
// does not apply (such as for
// leather armor +3), armor of
// +3 bonus is of special
// meteorite iron steel, +4 is
// mithral alloyed steel, and
// +5 is adamantite alloyed
// steel.
inline int uaaspCnsBonus3Material()
    { return 3; }

inline bool uaaspCnsBonus3MeteoriteIron()
    { return true; }

inline int uaaspCnsBonus4Material()
    { return 4; }

inline bool uaaspCnsBonus4MithralAlloyed()
    { return true; }

inline int uaaspCnsBonus5Material()
    { return 5; }

inline bool uaaspCnsBonus5AdamantiteAlloyed()
    { return true; }

// ---- the anything armor
// ----
// Any construction, leather to
// plate; originally appears
// with a +1 dweomer.
inline bool uaaspAamAnyConstruction()
    { return true; }

inline int uaaspAamOriginalBonus()
    { return 1; }

// Upon command it becomes any
// sort of other normal
// magical armor - one of the
// types listed on the tables,
// not necessarily of the same
// construction; each such
// change is singular, a
// specific type never formed
// more than once.
inline bool uaaspAamChangesOnCommand()
    { return true; }

inline bool uaaspAamTypeNeedNotMatchConstruction()
    { return true; }

inline bool uaaspAamEachChangeSingular()
    { return true; }

inline bool uaaspAamNoTypeTwice()
    { return true; }

// A change into a non-special
// sort of armor lasts 1 day
// (24 hours) before reverting
// to the usual +1 status; a
// change into a
// special-function type (such
// as plate mail of
// etherealness) lasts but 1
// hour.
inline int uaaspAamNonSpecialChangeHours()
    { return 24; }

inline bool uaaspAamNonSpecialLastsOneDay()
    { return true; }

inline bool uaaspAamRevertsToPlusOne()
    { return true; }

inline int uaaspAamSpecialChangeHours()
    { return 1; }

// After the possessor has
// commanded three different
// changes, the armor loses
// all of its magical
// properties.
inline int uaaspAamChangesAllowed()
    { return 3; }

inline bool uaaspAamLosesAllMagicAfter()
    { return true; }

// ---- the elfin chain mail
// ----
// So fine and light it can be
// worn under normal clothing
// without revealing it;
// thieves can utilize it,
// though it may slightly
// hinder their activities;
// rarely sized for anyone
// other than an elf or a
// half-elf.
inline bool uaaspEcmWornUnderClothing()
    { return true; }

inline bool uaaspEcmThievesCanUtilize()
    { return true; }

inline bool uaaspEcmMaySlightlyHinder()
    { return true; }

inline bool uaaspEcmRareForNonElves()
    { return true; }

// The size table
// OCR-scrambles (the header
// and row labels
// dislocate); the
// reconstruction: five rows -
// 01-10 hairfoot, 11-15
// dwarf/halfling (stout or
// tallfellow), 16-80
// elf/half-elf, 81-95
// man-sized normal (up to 6
// feet, 200 lbs.), 96-00
// man-sized large (up to 250
// lbs.); flagged.
inline int uaaspEcmSizeTableRows()
    { return 5; }

inline int uaaspEcmHairfootLo()
    { return 1; }

inline int uaaspEcmHairfootHi()
    { return 10; }

inline int uaaspEcmDwarfHalflingLo()
    { return 11; }

inline int uaaspEcmDwarfHalflingHi()
    { return 15; }

inline int uaaspEcmElfHalfElfLo()
    { return 16; }

inline int uaaspEcmElfHalfElfHi()
    { return 80; }

inline int uaaspEcmManNormalLo()
    { return 81; }

inline int uaaspEcmManNormalHi()
    { return 95; }

inline int uaaspEcmManLargeLo()
    { return 96; }

inline int uaaspEcmManLargeHi()
    { return 100; }

inline int uaaspEcmManNormalLbs()
    { return 200; }

inline int uaaspEcmManLargeLbs()
    { return 250; }

inline bool uaaspEcmSizeTableGarbles()
    { return true; }

// ---- the plate ----
// Field plate or full plate,
// as shown on Armor Table
// III.F.2; the dweomer
// perfectly conforms to the
// wearer's physical
// dimensions, so long as the
// wearer is of the race the
// armor was manufactured
// for; the conform sentence
// OCR-scrambles; flagged.
inline bool uaaspPltFieldOrFullPlate()
    { return true; }

inline bool uaaspPltConformsToWearer()
    { return true; }

inline bool uaaspPltSameRaceRequired()
    { return true; }

inline bool uaaspPltConformSeamGarbles()
    { return true; }

// Magical plate absorbs more
// damage than non-magical of
// the same sort: field plate
// an additional 10 points of
// damage per plus, full plate
// an additional 16 per plus.
inline int uaaspPltFieldAbsorbPerPlus()
    { return 10; }

inline int uaaspPltFullAbsorbPerPlus()
    { return 16; }

// Repairs after absorbing
// the limit, at non-magical
// costs: field plate 1 day
// and 100 gp per point of
// damage absorption, full
// plate 2 days and 200 gp per
// point; only an armorer
// well versed in the
// creation and repair of
// magical protection can
// make them.
inline int uaaspPltFieldRepairDays()
    { return 1; }

inline int uaaspPltFieldRepairGp()
    { return 100; }

inline int uaaspPltFullRepairDays()
    { return 2; }

inline int uaaspPltFullRepairGp()
    { return 200; }

inline bool uaaspPltRepairsNeedMagicArmorer()
    { return true; }

// ---- the short sword of
// quickness ----
// A specially dweomered blade
// enabling the wielder to
// strike first in every
// combat round; also a +2
// magic weapon, the bonus
// applicable to both hitting
// and damage.
inline bool uaaspQswStrikesFirstEveryRound()
    { return true; }

inline int uaaspQswBonus()
    { return 2; }

inline bool uaaspQswBonusToHitAndDamage()
    { return true; }

// ---- the sword of the
// planes ----
// Forged only as a
// broadsword; +1 on the
// Prime Material Plane; +2
// on any Inner Plane, and
// also on the Prime against
// opponents from the Inner
// Planes; +3 on an Outer
// Plane or against creatures
// from the Outer Planes; +4
// on the Astral or Ethereal
// Plane or against
// opponents from either.
inline bool uaaspPlnBroadswordOnly()
    { return true; }

inline int uaaspPlnPrimeBonus()
    { return 1; }

inline int uaaspPlnInnerPlanesBonus()
    { return 2; }

inline bool uaaspPlnInnerAppliesVsOpponents()
    { return true; }

inline int uaaspPlnOuterPlanesBonus()
    { return 3; }

inline bool uaaspPlnOuterAppliesVsOpponents()
    { return true; }

inline int uaaspPlnAstralEtherealBonus()
    { return 4; }

inline bool uaaspPlnAstralAppliesVsOpponents()
    { return true; }

// ---- the sun blade ----
// All of great size, treated
// as bastard swords; wielded
// as if short swords with
// respect to encumbrance,
// weight, speed factor, and
// ease of use; anyone able to
// use either a bastard sword
// or a short sword with
// proficiency or expertise can
// use one.
inline bool uaaspSubTreatedAsBastard()
    { return true; }

inline bool uaaspSubWieldedAsShortSword()
    { return true; }

inline bool uaaspSubEitherProficiencyServes()
    { return true; }

// In normal combat the
// glowing golden blade equals
// a +2 magic sword; against
// evil creatures the bonus
// doubles to +4; against
// creatures from the Negative
// Material Plane or those
// drawing power from it (many
// of the undead), double
// normal damage regardless of
// the +2 or +4 bonus.
inline int uaaspSubNormalBonus()
    { return 2; }

inline int uaaspSubEvilBonus()
    { return 4; }

inline bool uaaspSubDoubleDamageVsNegative()
    { return true; }

// The radiance sentence
// OCR-scrambles; the
// reconstruction: upon
// command the blade is swung
// through the air, shedding a
// bright yellow radiance
// equaling full daylight;
// flagged.
inline bool uaaspSubRadianceOnCommand()
    { return true; }

inline bool uaaspSubRadianceSeamGarbles()
    { return true; }

// The radiance begins within
// a 10-foot radius, spreads
// outward at 5 feet per round
// for 10 rounds - engulfing a
// 60-foot radius - then fades
// to a dim glow persisting
// another 10 rounds before
// disappearing; once per day;
// all sun blades are of good
// alignment.
inline int uaaspSubRadianceStartFt()
    { return 10; }

inline int uaaspSubRadianceSpreadPerRoundFt()
    { return 5; }

inline int uaaspSubRadianceSpreadRounds()
    { return 10; }

inline int uaaspSubRadianceFullRadiusFt()
    { return 60; }

inline int uaaspSubDimGlowRounds()
    { return 10; }

inline bool uaaspSubOncePerDay()
    { return true; }

inline bool uaaspSubGoodAlignment()
    { return true; }

// ---- the anything sword
// ----
// Originally appears a sword
// +1 of any type - short,
// long, etc.; upon command
// changes into any desired
// type of magic sword of any
// power (for instance, from a
// short sword +1 to a holy
// avenger +5 of long,
// bastard, or even
// two-handed sort).
inline int uaaspAswOriginalBonus()
    { return 1; }

inline bool uaaspAswAnyOriginalType()
    { return true; }

inline bool uaaspAswChangesOnCommand()
    { return true; }

inline bool uaaspAswAnyPower()
    { return true; }

inline int uaaspAswExampleAvengerBonus()
    { return 5; }

// The commanded form remains
// 1 day (24 hours) or until
// it performs a special,
// highly powerful function
// such as draining a level or
// severing some body part.
inline int uaaspAswFormHours()
    { return 24; }

inline bool uaaspAswEndsOnSpecialFunction()
    { return true; }

// Commanded to assume another
// form no more than three
// times; each form is
// singular and may not be
// repeated - a dancing sword
// but once, a frost brand but
// once, a vorpal blade but
// once; after the third change
// and reverting, an ordinary
// blade; never has
// intelligence, ego,
// communication power, or any
// other special ability.
inline int uaaspAswChangesAllowed()
    { return 3; }

inline bool uaaspAswEachFormSingular()
    { return true; }

inline bool uaaspAswNoFormRepeated()
    { return true; }

inline bool uaaspAswOrdinaryAfterThird()
    { return true; }

inline bool uaaspAswNeverIntelligent()
    { return true; }

// ---- the Final Word
// broadswords ----
// Very rare - only nine known
// to exist; each patterned
// after the legendary
// broadsword Fragarach,
// which means "final word" in
// the tongue of the ancient
// Oeridians; each thought to
// have a differing alignment,
// but in all other respects
// alike.
inline int uaaspFwbKnownCount()
    { return 9; }

inline bool uaaspFwbPatternedAfterFragarach()
    { return true; }

inline bool uaaspFwbFragarachMeansFinalWord()
    { return true; }

inline bool uaaspFwbDifferingAlignments()
    { return true; }

// A creature of an alignment
// different from the sword's
// attempting to wield it in
// battle gets no bonuses; in
// the hands of a like-aligned
// creature it becomes a +3
// blade which always strikes
// last in any round.
inline bool uaaspFwbUnlikeAlignmentNoBonuses()
    { return true; }

inline int uaaspFwbLikeAlignmentBonus()
    { return 3; }

inline bool uaaspFwbAlwaysStrikesLast()
    { return true; }

// It strikes unerringly and
// does damage to any opponent
// that struck at the wielder
// earlier in the same round,
// regardless of whether the
// opponent successfully hit,
// up to the wielder's
// allowable number of attacks
// per round; opponents immune
// to weapons of less than +4
// value are not harmed.
inline bool uaaspFwbUnerringCounterstrike()
    { return true; }

inline bool uaaspFwbCounterstrikesHitOrMiss()
    { return true; }

inline bool uaaspFwbUpToWielderAttacks()
    { return true; }

inline bool uaaspFwbPlus3Only()
    { return true; }

// Each has a gem of 10,000 gp
// value set in its pommel,
// each gem different in type
// from all the others; each
// bears an identifying name -
// the nine-appellations list
// OCR-scrambles; flagged.
inline int uaaspFwbPommelGemGp()
    { return 10000; }

inline bool uaaspFwbEachGemDifferent()
    { return true; }

inline bool uaaspFwbNamesTailGarbles()
    { return true; }

// ---- the part ledger ----
// Eight items: four fully
// clean, four flagged, none
// fully garbled.
inline int uaaspPartItemTotal()
    { return 8; }

inline int uaaspPartCleanCount()
    { return 4; }

inline int uaaspPartFlaggedCount()
    { return 4; }

inline int uaaspPartGarbledCount()
    { return 0; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uaarmprose.h: the pins')


s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 103, 'b inline count'
assert s.count('R387') == 1, 'b round tag'
assert s.count(
    'uaaspAamChangesAllowed'
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
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap report: the
# amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R387' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **The new armor and shields and',
        '      swords** (pp. 104-105) - the',
        '      anything sword (the 3-form limit',
        '      and the dweomer loss), the Final',
        '      Word broadswords (the nine named,',
        '      the +3 strikes-last read).'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = OLD + NL + NL.join([
        '      - AMENDED R387: the UA armor and',
        '        swords prose pin round',
        '        (rules/uaarmprose.h) - the',
        '        pp. 104-105 stretch, EIGHT items',
        '        pin: FOUR fully clean (the',
        '        anything armor, the short sword',
        '        of quickness, the sword of the',
        '        planes, the anything sword) plus',
        '        FOUR mechanics-clean with',
        "        flagged holes (the elfin chain",
        "        mail's size-table garble, the",
        "        plate's conform seam, the sun",
        "        blade's radiance seam, the Final",
        "        Word broadswords' names tail);",
        '        NOTHING fully garbles - the',
        '        item AMENDED, the prose pinned,',
        '        stays PDF-gated only.'
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
    'AMENDED R387'
) == 1, 'c amendment'
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
    '(rules/uaarmprose.h)'
) == 1, 'c armprose note'
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
if 'R387 UA armor and swords prose pin audit' in s:
    already.append('regtest.cpp: the R387 audit')
else:
    INC_ANCH = ('#include "rules/uamiscprose6.h"  // '
        'R386: the UA misc magic prose 6')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaarmprose.h"  // R387: the UA armor prose'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R387: the UA armor and
    // swords prose pin audit ----
    // The pp. 104-105 stretch:
    // eight pins - four fully
    // clean (the anything armor,
    // the short sword of
    // quickness, the sword of
    // the planes, the anything
    // sword) plus four
    // mechanics-clean with
    // flagged holes (the elfin
    // chain mail's size-table
    // garble, the plate's
    // conform seam, the sun
    // blade's radiance seam, the
    // Final Word broadswords'
    // names tail); the R386 seam
    // the part-6 ledger, the
    // R375 seam the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the construction
        // rule ----
            if (uaaspCnsBonus3Material() != 3)
                ++bad;
            if (!uaaspCnsBonus3MeteoriteIron())
                ++bad;
            if (uaaspCnsBonus4Material() != 4)
                ++bad;
            if (!uaaspCnsBonus4MithralAlloyed())
                ++bad;
            if (uaaspCnsBonus5Material() != 5)
                ++bad;
            if (!uaaspCnsBonus5AdamantiteAlloyed())
                ++bad;
            // the material ladder
            // steps one bonus at a
            // time, 3, 4, 5
            if (uaaspCnsBonus3Material() + 1
                    != uaaspCnsBonus4Material()) ++bad;
            if (uaaspCnsBonus4Material() + 1
                    != uaaspCnsBonus5Material()) ++bad;
        // ---- the anything armor
        // ----
            if (!uaaspAamAnyConstruction()) ++bad;
            if (uaaspAamOriginalBonus() != 1) ++bad;
            if (!uaaspAamChangesOnCommand()) ++bad;
            if (!uaaspAamTypeNeedNotMatchConstruction())
                ++bad;
            if (!uaaspAamEachChangeSingular()) ++bad;
            if (!uaaspAamNoTypeTwice()) ++bad;
            if (uaaspAamNonSpecialChangeHours()
                    != 24) ++bad;
            if (!uaaspAamNonSpecialLastsOneDay())
                ++bad;
            if (!uaaspAamRevertsToPlusOne()) ++bad;
            if (uaaspAamSpecialChangeHours() != 1)
                ++bad;
            if (uaaspAamChangesAllowed() != 3) ++bad;
            if (!uaaspAamLosesAllMagicAfter()) ++bad;
            // the non-special change
            // is a full day of 24
            // hours, twenty-four
            // times the special one
            if (24 * uaaspAamSpecialChangeHours()
                    != uaaspAamNonSpecialChangeHours())
                ++bad;
        // ---- the elfin chain
        // mail ----
            if (!uaaspEcmWornUnderClothing()) ++bad;
            if (!uaaspEcmThievesCanUtilize()) ++bad;
            if (!uaaspEcmMaySlightlyHinder()) ++bad;
            if (!uaaspEcmRareForNonElves()) ++bad;
            if (uaaspEcmSizeTableRows() != 5) ++bad;
            if (uaaspEcmHairfootLo() != 1) ++bad;
            if (uaaspEcmHairfootHi() != 10) ++bad;
            if (uaaspEcmDwarfHalflingLo() != 11)
                ++bad;
            if (uaaspEcmDwarfHalflingHi() != 15)
                ++bad;
            if (uaaspEcmElfHalfElfLo() != 16) ++bad;
            if (uaaspEcmElfHalfElfHi() != 80) ++bad;
            if (uaaspEcmManNormalLo() != 81) ++bad;
            if (uaaspEcmManNormalHi() != 95) ++bad;
            if (uaaspEcmManLargeLo() != 96) ++bad;
            if (uaaspEcmManLargeHi() != 100) ++bad;
            if (uaaspEcmManNormalLbs() != 200) ++bad;
            if (uaaspEcmManLargeLbs() != 250) ++bad;
            if (!uaaspEcmSizeTableGarbles()) ++bad;
            // the five size bands
            // tile the d100 exactly,
            // 10+5+65+15+5 = 100
            if (uaaspEcmHairfootHi()
                    - uaaspEcmHairfootLo() + 1
                    + uaaspEcmDwarfHalflingHi()
                    - uaaspEcmDwarfHalflingLo() + 1
                    + uaaspEcmElfHalfElfHi()
                    - uaaspEcmElfHalfElfLo() + 1
                    + uaaspEcmManNormalHi()
                    - uaaspEcmManNormalLo() + 1
                    + uaaspEcmManLargeHi()
                    - uaaspEcmManLargeLo() + 1
                    != 100) ++bad;
            // the bands chain
            // head to tail, 1
            // through 100
            if (uaaspEcmHairfootHi() + 1
                    != uaaspEcmDwarfHalflingLo()) ++bad;
            if (uaaspEcmDwarfHalflingHi() + 1
                    != uaaspEcmElfHalfElfLo()) ++bad;
            if (uaaspEcmElfHalfElfHi() + 1
                    != uaaspEcmManNormalLo()) ++bad;
            if (uaaspEcmManNormalHi() + 1
                    != uaaspEcmManLargeLo()) ++bad;
            // the large man-sized
            // suit carries fifty
            // more pounds
            if (uaaspEcmManLargeLbs()
                    - uaaspEcmManNormalLbs() != 50)
                ++bad;
        // ---- the plate ----
            if (!uaaspPltFieldOrFullPlate()) ++bad;
            if (!uaaspPltConformsToWearer()) ++bad;
            if (!uaaspPltSameRaceRequired()) ++bad;
            if (!uaaspPltConformSeamGarbles()) ++bad;
            if (uaaspPltFieldAbsorbPerPlus() != 10)
                ++bad;
            if (uaaspPltFullAbsorbPerPlus() != 16)
                ++bad;
            if (uaaspPltFieldRepairDays() != 1) ++bad;
            if (uaaspPltFieldRepairGp() != 100) ++bad;
            if (uaaspPltFullRepairDays() != 2) ++bad;
            if (uaaspPltFullRepairGp() != 200) ++bad;
            if (!uaaspPltRepairsNeedMagicArmorer())
                ++bad;
            // the full plate repair
            // doubles the field
            // plate, in days and gp
            if (2 * uaaspPltFieldRepairDays()
                    != uaaspPltFullRepairDays()) ++bad;
            if (2 * uaaspPltFieldRepairGp()
                    != uaaspPltFullRepairGp()) ++bad;
            // the full plate absorbs
            // six more points per
            // plus than the field
            if (uaaspPltFullAbsorbPerPlus()
                    - uaaspPltFieldAbsorbPerPlus()
                    != 6) ++bad;
        // ---- the short sword
        // of quickness ----
            if (!uaaspQswStrikesFirstEveryRound())
                ++bad;
            if (uaaspQswBonus() != 2) ++bad;
            if (!uaaspQswBonusToHitAndDamage())
                ++bad;
        // ---- the sword of the
        // planes ----
            if (!uaaspPlnBroadswordOnly()) ++bad;
            if (uaaspPlnPrimeBonus() != 1) ++bad;
            if (uaaspPlnInnerPlanesBonus() != 2)
                ++bad;
            if (!uaaspPlnInnerAppliesVsOpponents())
                ++bad;
            if (uaaspPlnOuterPlanesBonus() != 3)
                ++bad;
            if (!uaaspPlnOuterAppliesVsOpponents())
                ++bad;
            if (uaaspPlnAstralEtherealBonus() != 4)
                ++bad;
            if (!uaaspPlnAstralAppliesVsOpponents())
                ++bad;
            // the planar bonus
            // ladder steps one at a
            // time, 1 through 4
            if (uaaspPlnPrimeBonus() + 1
                    != uaaspPlnInnerPlanesBonus())
                ++bad;
            if (uaaspPlnInnerPlanesBonus() + 1
                    != uaaspPlnOuterPlanesBonus())
                ++bad;
            if (uaaspPlnOuterPlanesBonus() + 1
                    != uaaspPlnAstralEtherealBonus())
                ++bad;
        // ---- the sun blade ----
            if (!uaaspSubTreatedAsBastard()) ++bad;
            if (!uaaspSubWieldedAsShortSword())
                ++bad;
            if (!uaaspSubEitherProficiencyServes())
                ++bad;
            if (uaaspSubNormalBonus() != 2) ++bad;
            if (uaaspSubEvilBonus() != 4) ++bad;
            if (!uaaspSubDoubleDamageVsNegative())
                ++bad;
            if (!uaaspSubRadianceOnCommand()) ++bad;
            if (!uaaspSubRadianceSeamGarbles())
                ++bad;
            if (uaaspSubRadianceStartFt() != 10)
                ++bad;
            if (uaaspSubRadianceSpreadPerRoundFt()
                    != 5) ++bad;
            if (uaaspSubRadianceSpreadRounds()
                    != 10) ++bad;
            if (uaaspSubRadianceFullRadiusFt()
                    != 60) ++bad;
            if (uaaspSubDimGlowRounds() != 10)
                ++bad;
            if (!uaaspSubOncePerDay()) ++bad;
            if (!uaaspSubGoodAlignment()) ++bad;
            // the evil bonus doubles
            // the normal one
            if (2 * uaaspSubNormalBonus()
                    != uaaspSubEvilBonus()) ++bad;
            // the radiance starts at
            // 10 feet and spreads 5
            // per round for 10
            // rounds: 10 + 50 = 60
            if (uaaspSubRadianceStartFt()
                    + uaaspSubRadianceSpreadPerRoundFt()
                    * uaaspSubRadianceSpreadRounds()
                    != uaaspSubRadianceFullRadiusFt())
                ++bad;
            // the dim glow persists
            // as long as the spread
            if (uaaspSubDimGlowRounds()
                    != uaaspSubRadianceSpreadRounds())
                ++bad;
        // ---- the anything sword
        // ----
            if (uaaspAswOriginalBonus() != 1) ++bad;
            if (!uaaspAswAnyOriginalType()) ++bad;
            if (!uaaspAswChangesOnCommand()) ++bad;
            if (!uaaspAswAnyPower()) ++bad;
            if (uaaspAswExampleAvengerBonus() != 5)
                ++bad;
            if (uaaspAswFormHours() != 24) ++bad;
            if (!uaaspAswEndsOnSpecialFunction())
                ++bad;
            if (uaaspAswChangesAllowed() != 3) ++bad;
            if (!uaaspAswEachFormSingular()) ++bad;
            if (!uaaspAswNoFormRepeated()) ++bad;
            if (!uaaspAswOrdinaryAfterThird()) ++bad;
            if (!uaaspAswNeverIntelligent()) ++bad;
            // the commanded form
            // lasts a full day of 24
            // hours
            if (uaaspAswFormHours() != 24) ++bad;
            // the example avenger
            // rides the +5 cap of
            // the bonus ladder
            if (uaaspAswExampleAvengerBonus()
                    != uaaspCnsBonus5Material()) ++bad;
        // ---- the Final Word
        // broadswords ----
            if (uaaspFwbKnownCount() != 9) ++bad;
            if (!uaaspFwbPatternedAfterFragarach())
                ++bad;
            if (!uaaspFwbFragarachMeansFinalWord())
                ++bad;
            if (!uaaspFwbDifferingAlignments())
                ++bad;
            if (!uaaspFwbUnlikeAlignmentNoBonuses())
                ++bad;
            if (uaaspFwbLikeAlignmentBonus() != 3)
                ++bad;
            if (!uaaspFwbAlwaysStrikesLast()) ++bad;
            if (!uaaspFwbUnerringCounterstrike())
                ++bad;
            if (!uaaspFwbCounterstrikesHitOrMiss())
                ++bad;
            if (!uaaspFwbUpToWielderAttacks()) ++bad;
            if (!uaaspFwbPlus3Only()) ++bad;
            if (uaaspFwbPommelGemGp() != 10000)
                ++bad;
            if (!uaaspFwbEachGemDifferent()) ++bad;
            if (!uaaspFwbNamesTailGarbles()) ++bad;
            // the nine blades with
            // differing alignments
            // still share the one
            // +3 counterstrike bonus
            if (uaaspFwbKnownCount() != 9) ++bad;
        // ---- the part ledger ----
            if (uaaspPartItemTotal() != 8) ++bad;
            if (uaaspPartCleanCount() != 4) ++bad;
            if (uaaspPartFlaggedCount() != 4) ++bad;
            if (uaaspPartGarbledCount() != 0) ++bad;
            if (uaaspPartCleanCount()
                    + uaaspPartFlaggedCount()
                    + uaaspPartGarbledCount()
                    != uaaspPartItemTotal()) ++bad;
        // ---- the R386 part-6 seam ----
            if (uamm6PartItemTotal() != 5) ++bad;
            if (uamm6PartCleanCount() != 2) ++bad;
            if (uamm6PartFlaggedCount() != 3)
                ++bad;
            if (uamm6PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R387 UA armor and swords prose pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R387 audit')


s = rd(RT)
assert s.count(
    'R387 UA armor and swords prose pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 314, 'd census 314'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uaarmprose.h"'
) == 1, 'd new include'
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
    'R387 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R387 note: the UA armor and',
    'swords prose round - the',
    'pp. 104-105 stretch, eight',
    'items pin: four fully clean',
    '(the anything armor, the',
    'short sword of quickness,',
    'the sword of the planes,',
    'the anything sword) plus',
    'four mechanics-clean with',
    'flagged holes (the elfin',
    'chain mail, the plate, the',
    'sun blade, the Final Word',
    'broadswords); nothing fully',
    'garbles - the item AMENDED,',
    'the prose pinned, stays',
    'PDF-gated only; the R386',
    'seam the part-6 ledger, the',
    'R375 seam the misc band;',
    'the census 313 -> 314'
])
print(NOTE)
print('commit: R387: the UA armor')
print('and swords prose pin round')
print('(census 314)')

