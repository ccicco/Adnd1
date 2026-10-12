# R379: the UA new rods and
# staves prose pin round
# (pp. 94-96): FOUR of the
# eleven new descriptions pin
# clean - the rod of alertness
# (the +1 surprise and
# initiative, the seven free
# detects, the planted 12"
# sense radius, the eight
# flanges casting light at
# 6" range, the 2" prayer
# radius, the 16-object
# animate, 2 charges all-in,
# the cleric-16 recharge), the
# rod of security (the 200-day
# paradise divided by
# creature count, the 1/4/60
# examples, the 101-200 group
# at one day, healing at
# twice rate, the joint
# cleric-16 and magic-user-18
# recharge), the staff-mace
# (the three forms: the
# quarterstaff +3 iron-shod,
# the footman's mace +1, the
# horseman's mace +2), the
# staff of slinging (the
# druid-only 9-inch 5-pound
# sphere, the 18" range at
# 6/12 short and medium, the
# stone-giant hurl at 30" for
# 3-30, the druid-12
# recharge); SEVEN descriptions
# OCR-scramble (flailing's
# charge tail, passage's
# function list, splendor's
# garble, staff-spear's die
# table, swarming insects'
# activation, thunder and
# lightning's combined tail,
# woodlands' power list) - the
# gap item AMENDED, stays
# OPEN, PDF-gated; the R378
# seam the rings ledger, the
# R375 seam the rod band; the
# census 305 -> 306.
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



# ---- (a) the seed: the R378 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R378 landed 2026-10-12: commit',
    '  a414462, census 305, the UA',
    '  new rings prose pin round',
    '  (rules/uaringprose.h): six',
    '  of the thirteen new-ring',
    '  descriptions pin clean',
    '  (animal friendship,',
    '  anything, blinking,',
    '  jumping, mind shielding,',
    '  truth); seven',
    '  descriptions OCR-scramble',
    '  (boccob, chameleon,',
    '  clumsiness, faerie, ram,',
    '  shocking grasp,',
    '  sustenance) - the item',
    '  AMENDED, stays OPEN,',
    '  PDF-gated; the R377 seam',
    '  the scrolls ledger, the',
    '  R375 seam the ring band;',
    '  GREEN on the first run.'
])
s = rd(SD)
if 'R378 landed 2026-10-12' in s:
    already.append('seed: the R378 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R378 record')
s = rd(SD)
assert s.count(
    'R378 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uarodstave.h ----
P = 'rules/uarodstave.h'
if os.path.exists(P) and 'R379' in rd(P):
    already.append('uarodstave.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uarodstave.h
// The UA TREASURE (RODS and
// STAVES) prose pins, R379:
// the four clean descriptions
// (pp. 94-96) - the rod of
// alertness, the rod of
// security, the staff-mace,
// the staff of slinging. The
// seven garbled descriptions
// (flailing, passage,
// splendor, staff-spear,
// swarming insects, thunder
// and lightning, woodlands)
// await the PDF - the gap
// item stays open. The rings
// and skeleton seams ride in
// the regtest audit, not
// here.
namespace rules {

// ---- the rod of alertness ----
// Indistinguishable from a
// footman's mace +1; upon
// usage the true powers
// reveal themselves.
inline bool uaroAlLooksFootmanMacePlusOne()
    { return true; }

// The possessor gains +1 on
// surprise die rolls and +1
// on initiative in combat.
inline int uaroAlSurpriseBonus()
    { return 1; }

inline int uaroAlInitiativeBonus()
    { return 1; }

// Grasped firmly, the
// concentrating possessor
// detects alignment, evil,
// good, illusion,
// invisibility, lie, or
// magic - none expend
// charges.
inline int uaroAlDetectCount()
    { return 7; }

inline bool uaroAlDetectsExpendNoCharge()
    { return true; }

// Planted and willed to
// alertness: senses any
// creature with intent to
// harm within a 12" radius.
inline int uaroAlSenseRadiusIn()
    { return 12; }

inline bool uaroAlSenseNeedsHarmfulIntent()
    { return true; }

// The eight flanges of the
// macelike head each cast a
// light spell along one
// cardinal direction at 6"
// range; a prayer effect
// covers friendlies in a 2"
// radius; then the mental
// alert warns them.
inline int uaroAlFlangeCount()
    { return 8; }

inline int uaroAlFlangeLightRangeIn()
    { return 6; }

inline int uaroAlPrayerRadiusIn()
    { return 2; }

inline bool uaroAlMentalAlertSent()
    { return true; }

// The animate object uses up
// to 16 objects placed
// around the perimeter of a
// 6"-radius circle centered
// on the rod.
inline int uaroAlAnimateMaxObjects()
    { return 16; }

inline int uaroAlAnimateCircleRadiusIn()
    { return 6; }

// Functions cost 1 charge,
// the animation 1 charge -
// all protective devices at
// once spend 2.
inline int uaroAlFunctionChargeCost()
    { return 1; }

inline int uaroAlAnimateChargeCost()
    { return 1; }

inline int uaroAlAllAtOnceCharges()
    { return 2; }

// Recharge by a cleric of
// 16th or higher level, so
// long as at least 1 charge
// remains.
inline int uaroAlRechargeClericLevel()
    { return 16; }

inline bool uaroAlRechargeNeedsChargeLeft()
    { return true; }

// ---- the rod of security ----
// Each charge creates the
// pocket paradise: the
// possessor plus up to 199
// others stay in safety,
// the maximum 200 days
// divided by the number of
// creatures.
inline int uaroSeDaysBase()
    { return 200; }

inline int uaroSeMaxCreatures()
    { return 200; }

inline int uaroSeOtherCreaturesMax()
    { return 199; }

// One creature stays 200
// days; four stay 50; sixty
// stay 3; a group of 101 to
// 200 stays one day only.
inline int uaroSeExampleOneDays()
    { return 200; }

inline int uaroSeExampleFourDays()
    { return 50; }

inline int uaroSeExampleSixtyDays()
    { return 3; }

inline int uaroSeGroup101to200Days()
    { return 1; }

// Within the paradise: no
// aging (except from
// magical causes such as a
// wish), healing and curing
// at twice the normal rate,
// fresh water and food
// (fruits and vegetables
// only), comfortable
// climate.
inline bool uaroSeNoAging()
    { return true; }

inline int uaroSeHealingRateMult()
    { return 2; }

inline bool uaroSeFoodFruitsVegetables()
    { return true; }

// On expiry all instantly
// reappear where they were;
// occupied space displaces
// the traveller enough for
// re-entry.
inline bool uaroSeReappearOnExpiry()
    { return true; }

// Recharge demands a cleric
// of 16th or higher AND a
// magic-user of 18th or
// higher, jointly.
inline int uaroSeRechargeClericLevel()
    { return 16; }

inline int uaroSeRechargeMuLevel()
    { return 18; }

// ---- the staff-mace ----
// A clerical weapon that
// appears a normal wooden
// trekking staff; a very
// faint alteration dweomer.
inline bool uaroSmClericalWeapon()
    { return true; }

inline bool uaroSmFaintAlterationDweomer()
    { return true; }

// Upon command, one of three
// forms: the quarterstaff +3
// iron-shod, the great mace
// (footman's mace +1, iron),
// the mace (horseman's mace
// +2, iron) - bronzewood
// with iron bands and tips.
inline int uaroSmFormCount()
    { return 3; }

inline int uaroSmQuarterstaffBonus()
    { return 3; }

inline bool uaroSmQuarterstaffIronShod()
    { return true; }

inline int uaroSmGreatMaceBonus()
    { return 1; }

inline int uaroSmMaceBonus()
    { return 2; }

inline bool uaroSmBronzewoodIronBound()
    { return true; }

// ---- the staff of
// slinging ----
// Appears nothing more than
// a +1 quarterstaff; the
// slinging power shows only
// to a druid and only a
// druid may employ it.
inline bool uaroSlAppearsPlusOne()
    { return true; }

inline bool uaroSlDruidOnly()
    { return true; }

// A heavy roughly spherical
// object up to nine inches
// in diameter and five
// pounds adheres to the
// staff end; the overhand
// swing releases the
// missile.
inline int uaroSlMaxObjectDiamInches()
    { return 9; }

inline int uaroSlMaxObjectPounds()
    { return 5; }

inline bool uaroSlReleaseIsOverhandArc()
    { return true; }

// The missile rises 1 foot
// per 1" traveled - or
// nearly vertical, 1 foot
// lateral per 1" of rise.
// Max range 18", short 6",
// medium 12".
inline int uaroSlRiseFeetPerInchRange()
    { return 1; }

inline int uaroSlMaxRangeIn()
    { return 18; }

inline int uaroSlShortRangeIn()
    { return 6; }

inline int uaroSlMediumRangeIn()
    { return 12; }

// One charge hurls a
// man-sized missile as a
// stone giant: range 30",
// 3-30 points per hit.
inline int uaroSlGiantHurlChargeCost()
    { return 1; }

inline int uaroSlGiantHurlRangeIn()
    { return 30; }

inline int uaroSlGiantHurlDmgLo()
    { return 3; }

inline int uaroSlGiantHurlDmgHi()
    { return 30; }

// Either mode bestows +1
// to hit and +1 per die to
// damage; recharge by a
// druid of 12th or higher.
inline int uaroSlHitBonus()
    { return 1; }

inline int uaroSlDmgPerDieBonus()
    { return 1; }

inline int uaroSlRechargeDruidLevel()
    { return 12; }

// ---- the extract ledger ----
// Four of the eleven
// descriptions pin; the
// seven garbled ones stay
// PDF-gated.
inline int uaroCleanCount()
    { return 4; }

inline int uaroGarbledCount()
    { return 7; }

inline int uaroTotalTypes()
    { return 11; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uarodstave.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 58, 'b inline count'
assert s.count('R379') == 1, 'b round tag'
assert s.count(
    'uaroAlLooksFootmanMacePlusOne'
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
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R379' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **The new rods and staves** (pp.',
        '      94-96).'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [ ] **The new rods and staves** (pp.',
        '      94-96).',
        '      - AMENDED R379: the new',
        '        rods and staves prose pin',
        '        round (rules/uarodstave.h)',
        '        - FOUR of the eleven',
        '        new descriptions pin',
        '        clean (the rod of',
        '        alertness, the rod of',
        '        security, the',
        '        staff-mace, the staff',
        '        of slinging); SEVEN',
        '        descriptions',
        '        OCR-scramble (flailing,',
        '        passage, splendor,',
        '        staff-spear, swarming',
        '        insects, thunder and',
        '        lightning, woodlands) -',
        '        the item stays OPEN,',
        '        PDF-gated for the',
        '        garbled remainder.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the amendment')
wr(GP, s)

# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [ ] **The new rods and staves**'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R379'
) == 1, 'c amendment'
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
    '(rules/uarodstave.h)'
) == 1, 'c rods note'
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
    '- [ ] **The new wands**'
) == 1, 'c wands kept open'
assert s.count(
    '- [ ] **The new miscellaneous magic'
) == 1, 'c misc magic kept open'
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
if 'R379 UA new rods staves prose pin audit' in s:
    already.append('regtest.cpp: the R379 audit')
else:
    INC_ANCH = ('#include "rules/uaringprose.h"  // '
        'R378: the UA new rings prose')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uarodstave.h"  // R379: the UA new rods staves prose'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R379: the UA new rods
    // staves prose pin audit ----
    // The four clean
    // descriptions (pp. 94-96):
    // the rod of alertness, the
    // rod of security, the
    // staff-mace, the staff of
    // slinging. The seven
    // garbled descriptions stay
    // PDF-gated. The R378 seam
    // cross-checks the rings
    // ledger, the R375 seam the
    // rod band; the census
    // 305 -> 306.
    {
        using namespace rules;
        int bad = 0;
        // ---- the rod of alertness ----
            if (!uaroAlLooksFootmanMacePlusOne())
                ++bad;
            if (uaroAlSurpriseBonus() != 1) ++bad;
            if (uaroAlInitiativeBonus() != 1) ++bad;
            if (uaroAlDetectCount() != 7) ++bad;
            if (!uaroAlDetectsExpendNoCharge())
                ++bad;
            if (uaroAlSenseRadiusIn() != 12) ++bad;
            if (!uaroAlSenseNeedsHarmfulIntent())
                ++bad;
            if (uaroAlFlangeCount() != 8) ++bad;
            if (uaroAlFlangeLightRangeIn() != 6)
                ++bad;
            if (uaroAlPrayerRadiusIn() != 2) ++bad;
            if (!uaroAlMentalAlertSent()) ++bad;
            if (uaroAlAnimateMaxObjects() != 16)
                ++bad;
            if (uaroAlAnimateCircleRadiusIn() != 6)
                ++bad;
            if (uaroAlFunctionChargeCost() != 1)
                ++bad;
            if (uaroAlAnimateChargeCost() != 1)
                ++bad;
            if (uaroAlAllAtOnceCharges() != 2)
                ++bad;
            // functions + animation =
            // the all-at-once cost
            if (uaroAlFunctionChargeCost()
                    + uaroAlAnimateChargeCost()
                    != uaroAlAllAtOnceCharges())
                ++bad;
            if (uaroAlRechargeClericLevel() != 16)
                ++bad;
            if (!uaroAlRechargeNeedsChargeLeft())
                ++bad;
        // ---- the rod of security ----
            if (uaroSeDaysBase() != 200) ++bad;
            if (uaroSeMaxCreatures() != 200) ++bad;
            if (uaroSeOtherCreaturesMax() != 199)
                ++bad;
            // the possessor plus the
            // 199 others fill the cap
            if (uaroSeOtherCreaturesMax() + 1
                    != uaroSeMaxCreatures()) ++bad;
            if (uaroSeExampleOneDays() != 200)
                ++bad;
            if (uaroSeExampleFourDays() != 50)
                ++bad;
            if (uaroSeExampleSixtyDays() != 3)
                ++bad;
            if (uaroSeGroup101to200Days() != 1)
                ++bad;
            // the days divide by the
            // creature count
            if (uaroSeDaysBase()
                    / 4 != uaroSeExampleFourDays())
                ++bad;
            if (uaroSeDaysBase()
                    / 60 != uaroSeExampleSixtyDays())
                ++bad;
            if (!uaroSeNoAging()) ++bad;
            if (uaroSeHealingRateMult() != 2) ++bad;
            if (!uaroSeFoodFruitsVegetables())
                ++bad;
            if (!uaroSeReappearOnExpiry()) ++bad;
            if (uaroSeRechargeClericLevel() != 16)
                ++bad;
            if (uaroSeRechargeMuLevel() != 18)
                ++bad;
            // security's recharge is
            // the stricter cousin of
            // alertness's cleric-16
            if (uaroSeRechargeClericLevel()
                    != uaroAlRechargeClericLevel())
                ++bad;
        // ---- the staff-mace ----
            if (!uaroSmClericalWeapon()) ++bad;
            if (!uaroSmFaintAlterationDweomer())
                ++bad;
            if (uaroSmFormCount() != 3) ++bad;
            if (uaroSmQuarterstaffBonus() != 3)
                ++bad;
            if (!uaroSmQuarterstaffIronShod())
                ++bad;
            if (uaroSmGreatMaceBonus() != 1) ++bad;
            if (uaroSmMaceBonus() != 2) ++bad;
            if (!uaroSmBronzewoodIronBound()) ++bad;
            // the form bonuses run
            // 3, 1, 2 and sum to the
            // form count
            if (uaroSmQuarterstaffBonus()
                    + uaroSmGreatMaceBonus()
                    + uaroSmMaceBonus()
                    != 2 * uaroSmFormCount()) ++bad;
        // ---- the staff of slinging ----
            if (!uaroSlAppearsPlusOne()) ++bad;
            if (!uaroSlDruidOnly()) ++bad;
            if (uaroSlMaxObjectDiamInches() != 9)
                ++bad;
            if (uaroSlMaxObjectPounds() != 5) ++bad;
            if (!uaroSlReleaseIsOverhandArc())
                ++bad;
            if (uaroSlRiseFeetPerInchRange() != 1)
                ++bad;
            if (uaroSlMaxRangeIn() != 18) ++bad;
            if (uaroSlShortRangeIn() != 6) ++bad;
            if (uaroSlMediumRangeIn() != 12) ++bad;
            // short + medium bound
            // the maximum range
            if (uaroSlShortRangeIn()
                    + uaroSlMediumRangeIn()
                    != uaroSlMaxRangeIn()) ++bad;
            if (uaroSlGiantHurlChargeCost() != 1)
                ++bad;
            if (uaroSlGiantHurlRangeIn() != 30)
                ++bad;
            if (uaroSlGiantHurlDmgLo() != 3) ++bad;
            if (uaroSlGiantHurlDmgHi() != 30) ++bad;
            if (uaroSlHitBonus() != 1) ++bad;
            if (uaroSlDmgPerDieBonus() != 1) ++bad;
            if (uaroSlRechargeDruidLevel() != 12)
                ++bad;
        // ---- the extract ledger ----
            if (uaroCleanCount() != 4) ++bad;
            if (uaroGarbledCount() != 7) ++bad;
            if (uaroTotalTypes() != 11) ++bad;
            if (uaroCleanCount() + uaroGarbledCount()
                    != uaroTotalTypes()) ++bad;
        // ---- the R378 rings seam ----
            if (uarpCleanCount() != 6) ++bad;
            if (uarpGarbledCount() != 7) ++bad;
        // ---- the R375 skeleton seam ----
            // the rods staves and
            // wands ride the 41-45
            // band, split 01-40 new
            // / 41-00 the II.D.2
            if (uadsCategoryLo(3) != 41) ++bad;
            if (uadsCategoryHi(3) != 45) ++bad;
            if (uadsRodSplitLo() != 40) ++bad;
            if (!uadsRodSecondTableIsIID2())
                ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R379 UA new rods staves prose pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R379 audit')
s = rd(RT)
assert s.count(
    'R379 UA new rods staves prose pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 306, 'd census 306'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uarodstave.h"'
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
    'R379 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R379 note: the new rods and',
    'staves prose round - four',
    'of the eleven new',
    'descriptions pin clean',
    '(the rod of alertness,',
    'the rod of security, the',
    'staff-mace, the staff of',
    'slinging); seven',
    'descriptions',
    'OCR-scramble (flailing,',
    'passage, splendor,',
    'staff-spear, swarming',
    'insects, thunder and',
    'lightning, woodlands) -',
    'the item AMENDED, stays',
    'OPEN, PDF-gated; the R378',
    'seam the rings ledger,',
    'the R375 seam the rod',
    'band; the census',
    '305 -> 306'
])
print(NOTE)
print('commit: R379: the UA new')
print('rods staves prose pin round')
print('(census 306)',)

