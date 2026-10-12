
# R370: the UA DM-section smalls part 1
# pin round: three items - Method V
# (p. 74, the prose clean, the dice table
# cells a hole), the starting hit-point
# minimums (p. 74, the 12 class floors with
# the multi-class and con examples), the
# warhorses and barding movement rate table
# (p. 76, two lost cells flagged); the R368
# seam cross-checks the cavalier d10 floor;
# the census 296 -> 297.
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



# ---- (a) the seed: the R369 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R369 landed 2026-10-12: commit',
    '  41ca7f2, census 296, the UA',
    '  cantrip acquisition pin round',
    '  (rules/uacantacq.h): the five',
    '  random known-count bands',
    '  (reversed 2-8, legerdemain 2-5,',
    '  person-affecting 2-8, personal',
    '  2-8, haunting-sound 2-5), the 3',
    '  developed cantrips cap with the',
    '  DM review, the read-as-spell and',
    '  recorded-as-spell notes; the',
    '  useful one per point of',
    '  intelligence free-choice read',
    '  decoded from the garbled sentence',
    '  (flagged pending the PDF); the',
    '  item CLOSED; the R365 seam',
    '  cross-checks the illusionist',
    '  bands (the documented',
    '  divergence) and the R366 seam',
    '  the book counts; GREEN on the',
    '  first run.'
])
s = rd(SD)
if 'R369 landed 2026-10-12' in s:
    already.append('seed: the R369 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R369 record')
s = rd(SD)
assert s.count(
    'R369 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uasmalls1.h ----
P = 'rules/uasmalls1.h'
if os.path.exists(P) and 'R370' in rd(P):
    already.append('uasmalls1.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uasmalls1.h
// The UA DM-SECTION SMALLS, part 1,
// R370: three items - Method V
// (p. 74), the starting hit-point
// minimums (p. 74), the warhorses
// and barding movement rate table
// (p. 76).
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The R368 seam cross-checks the cavalier
// starting floor against the level-1 d10 pin
// (rules/uacavtable.h).
//
// JUDGMENTs (the decode method):
//   - the Method V prose prints clean (the humans-only
//     class-first read, the best-three-of-N roll, the
//     minimum and maximum clamps, the 9d6 fighter
//     strength example); the dice-count table body
//     extracts EMPTY - every cell a hole, flagged
//     pending the PDF.
//   - the starting hit-point minimums print clean -
//     the 12 class floors, the multi-class average
//     rounded up with the fighter/magic-user 5
//     example, the constitution adjustment with the
//     con-17 fighter 9 example.
//   - the barding table: light 21/15 with scale and
//     plate not allowed, medium 17/15 with the scale
//     cell garbled and plate not allowed, heavy
//     14/13/12 with the leather cell lost - the two
//     lost cells flagged pending the PDF; the
//     endurance, magical-barding and other-steeds
//     prose prints clean.

namespace rules {

// ---- Method V (p. 74) ----
// The class-first generation: the player picks
// the class (subject to DM approval), rolls N
// dice per ability, keeps the best three.
inline bool uasm1MethodVHumansOnly()
    { return true; }

inline bool uasm1MethodVClassFirst()
    { return true; }

inline bool uasm1MethodVRequiresDmApproval()
    { return true; }

inline bool uasm1MethodVBestThreeOfN()
    { return true; }

// If the best-three total is below the class
// minimum the minimum applies; if above the
// maximum allowable (the barbarian wisdom) the
// maximum applies.
inline bool uasm1MethodVMinClampApplies()
    { return true; }

inline bool uasm1MethodVMaxClampApplies()
    { return true; }

// The worked example: the fighter strength
// rolls 9d6, keep the three highest.
inline int uasm1MethodVFighterStrengthDice()
    { return 9; }

// The dice-count table body extracts empty -
// every cell a hole pending the PDF.
inline bool uasm1MethodVTableCellsLost()
    { return true; }

// ---- the starting hit-point minimums (p. 74) ----
// Slots: 0 Cavalier, 1 Paladin, 2 Cleric,
// 3 Druid, 4 Fighter, 5 Barbarian, 6 Ranger,
// 7 Magic-user, 8 Illusionist, 9 Thief,
// 10 Assassin, 11 Monk.
inline int uasm1StartHpClassCount()
    { return 12; }

inline int uasm1StartHpMin(int slot) {
    static const int k[12] = {
        6, 6, 5, 5, 6, 7, 9, 3, 3, 4, 4, 5,
    };
    if (slot < 0) slot = 0;
    if (slot > 11) slot = 11;
    return k[slot];
}

// A multi-class character uses the average of
// the applicable minimums, rounded up.
inline bool uasm1StartHpMultiClassAverageRoundedUp()
    { return true; }

// The worked example: (6 + 3) / 2 = 5.
inline int uasm1StartHpExampleFighterMage()
    { return 5; }

inline bool uasm1StartHpConAdjustApplies()
    { return true; }

// The worked example: a 1st-level fighter with
// a 17 constitution has at least 9.
inline int uasm1StartHpExampleCon17Fighter()
    { return 9; }

// ---- the barding movement table (p. 76) ----
// Base movement rates in inches; NA = the
// heavier barding is not allowed on the
// lighter horse.
inline int uasm1BardLightLeather()
    { return 21; }

inline int uasm1BardLightChain()
    { return 15; }

inline bool uasm1BardLightScaleNa()
    { return true; }

inline bool uasm1BardLightPlateNa()
    { return true; }

inline int uasm1BardMediumLeather()
    { return 17; }

inline int uasm1BardMediumChain()
    { return 15; }

// The medium scale cell garbles in the
// extract - a hole pending the PDF.
inline bool uasm1BardMediumScaleCellLost()
    { return true; }

inline bool uasm1BardMediumPlateNa()
    { return true; }

// The heavy leather cell is lost - a hole
// pending the PDF.
inline bool uasm1BardHeavyLeatherCellLost()
    { return true; }

inline int uasm1BardHeavyChain()
    { return 14; }

inline int uasm1BardHeavyScale()
    { return 13; }

inline int uasm1BardHeavyPlate()
    { return 12; }

// The endurance rule: the base movement rate
// gives the miles per day.
inline bool uasm1BardEnduranceFromBaseRate()
    { return true; }

// ---- the magical barding ----
// Worth five times the cost of comparable
// armor; the plus can never exceed +3.
inline int uasm1MagBardingCostMultiple()
    { return 5; }

inline int uasm1MagBardingPlusCap()
    { return 3; }

inline int uasm1MagBardingPlus1Pct()
    { return 65; }

inline int uasm1MagBardingPlus2Pct()
    { return 25; }

inline int uasm1MagBardingPlus3Pct()
    { return 10; }

inline int uasm1MagBardingLeatherPct()
    { return 10; }

inline int uasm1MagBardingScalePct()
    { return 15; }

inline int uasm1MagBardingChainPct()
    { return 25; }

inline int uasm1MagBardingPlatePct()
    { return 50; }

// ---- the other steeds ----
// Flying steeds wear only leather (or elfin
// chain) barding, with the movement reduced
// by one-eighth; aquatic steeds cannot be
// barded.
inline bool uasm1FlyingSteedsLeatherOrElfinOnly()
    { return true; }

inline bool uasm1FlyingSteedsReductionEighth()
    { return true; }

inline bool uasm1AquaticSteedsNotBarded()
    { return true; }

// A very strong mount in plate barding loses
// from one-fifth to one-eighth of its
// movement; an elephant the least (the
// one-eighth).
inline int uasm1StrongMountPlateReductionMin()
    { return 5; }

inline int uasm1StrongMountPlateReductionMax()
    { return 8; }

// Elfin chain for unicorns or griffons: the
// weight and movement effect equal leather
// barding; the protection equal chain.
inline bool uasm1UnicornGriffonElfinWeightAsLeather()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uasmalls1.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 42, 'b inline count'
assert s.count('R370') == 1, 'b round tag'
assert s.count(
    'uasm1StartHpMin'
    ) >= 1, 'b fn'
assert 'uacaq' not in s, 'b no uacaq ref'
assert 'uaila' not in s, 'b no uaila ref'
assert 'uabk' not in s, 'b no uabk ref'
assert 'uailc' not in s, 'b no uailc ref'
assert 'uasoc' not in s, 'b no uasoc ref'
assert 'uabirth' not in s, 'b no uabirth ref'
assert 'uasp' not in s, 'b no uasp ref'
assert 'uacavt' not in s.replace(
    'uacavtable.h', ''), 'b no uacavt call'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the three closes ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **Method V**' in s:
    already.append('gap: the Method V close')
else:
    OLD = NL.join([
        '- [ ] **Method V** (p. 74) - the',
        '      class-first generation, humans',
        '      only; the dice-count table (the',
        '      9d6 fighter strength, the Com',
        '      column) reads clean; the minimum',
        '      and maximum clamps.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [x] **Method V** (p. 74) - the',
        '      class-first generation, humans',
        '      only; the dice-count table (the',
        '      9d6 fighter strength, the Com',
        '      column) reads clean; the minimum',
        '      and maximum clamps.',
        '      - CLOSED R370: the pin round',
        '        (rules/uasmalls1.h) - the',
        '        class-first humans-only',
        '        prose, the best-three-of-N',
        '        roll with the DM approval,',
        '        the minimum and maximum',
        '        clamps and the 9d6 fighter',
        '        strength example pin clean;',
        '        the dice-count table cells',
        '        extract empty - the cell',
        '        body a hole in-header',
        '        pending the PDF; CLOSED.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the Method V close')
if '- [x] **Starting hit-point minimums**' in s:
    already.append('gap: the hit-point close')
else:
    OLD = NL.join([
        '- [ ] **Starting hit-point minimums**',
        '      (p. 74) - cavalier 6, paladin 6,',
        '      cleric 5, druid 5, fighter 6,',
        '      barbarian 7, ranger 9, magic-user',
        '      3, illusionist 3, thief 4,',
        '      assassin 4, monk 5.'
    ])
    assert s.count(OLD) == 1, 'c2 old'
    NEW = NL.join([
        '- [x] **Starting hit-point minimums**',
        '      (p. 74) - cavalier 6, paladin 6,',
        '      cleric 5, druid 5, fighter 6,',
        '      barbarian 7, ranger 9, magic-user',
        '      3, illusionist 3, thief 4,',
        '      assassin 4, monk 5.',
        '      - CLOSED R370: the pin round',
        '        (rules/uasmalls1.h) - the 12',
        '        class minimums (cavalier 6',
        '        to ranger 9), the',
        '        multi-class average rounded',
        '        up with the fighter/magic-',
        '        user 5 example, the',
        '        constitution adjustment',
        '        with the con-17 fighter 9',
        '        example; the R368 seam',
        '        cross-checks the cavalier',
        '        d10 floor; CLOSED.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the hit-point close')
if '- [x] **Warhorses and barding**' in s:
    already.append('gap: the barding close')
else:
    OLD = NL.join([
        '- [ ] **Warhorses and barding** (p. 76)',
        '      - the barded movement rate table.'
    ])
    assert s.count(OLD) == 1, 'c3 old'
    NEW = NL.join([
        '- [x] **Warhorses and barding** (p. 76)',
        '      - the barded movement rate table.',
        '      - CLOSED R370: the pin round',
        '        (rules/uasmalls1.h) - the',
        '        movement rate table (light',
        '        21/15, medium 17/15, heavy',
        '        14/13/12) with the medium',
        '        scale and heavy leather',
        '        cells lost (flagged), the',
        '        endurance rule, the',
        '        magical barding costs and',
        '        percentages, the flying and',
        '        aquatic steeds rules; the',
        '        percentage sums',
        '        cross-check; CLOSED.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the barding close')
wr(GP, s)

# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [x] **Method V**'
) == 1, 'c1 flip'
assert s.count(
    '- [x] **Starting hit-point minimums**'
) == 1, 'c2 flip'
assert s.count(
    '- [x] **Warhorses and barding**'
) == 1, 'c3 flip'
assert s.count(
    '(rules/uasmalls1.h) - the'
) == 3, 'c notes'
assert s.count(
    '- [ ] Barded Warhorse Movement Rate (p.'
) == 1, 'c manifest barding kept'
assert s.count(
    '- [ ] Character Generation Method V (p.'
) == 1, 'c manifest method kept'
assert s.count(
    '- [ ] Hit Points, Starting (p. 74).'
) == 1, 'c manifest hp kept'
assert s.count(
    '- [ ] **The comeliness creation note**'
) == 1, 'c comeliness kept open'
assert s.count(
    '- [ ] **The cavalier follower tables**'
) == 1, 'c followers kept open'
assert s.count(
    '- [x] **Cantrip acquisition, MU**'
) == 1, 'c r369 kept closed'
assert s.count(
    '- [x] **Cavaliers Table I**'
) == 1, 'c r368 kept closed'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c armor kept open'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert len(applied) + len(already) == 5, 'c count'



# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R370 UA DM-section smalls pin audit' in s:
    already.append('regtest.cpp: the R370 audit')
else:
    INC_ANCH = ('#include "rules/uacantacq.h"  // '
        'R369: the UA cantrip acquisition')
    INC_NEW = NL.join([
        '#include "rules/uacantacq.h"  // R369: the UA cantrip acquisition',
        '#include "rules/uasmalls1.h"  // R370: the UA DM-section smalls'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R370: the UA DM-section
    // smalls pin audit ----
    // The UA DM-section smalls, part 1:
    // Method V (p. 74) - the class-first
    // humans-only generation, the
    // best-three-of-N roll with the DM
    // approval, the minimum and maximum
    // clamps, the 9d6 fighter strength
    // example (the dice table cells lost,
    // flagged); the starting hit-point
    // minimums (p. 74) - the 12 class
    // floors, the multi-class average
    // rounded up, the constitution
    // adjustment; the warhorses and
    // barding (p. 76) - the movement rate
    // table (the medium scale and heavy
    // leather cells lost, flagged), the
    // endurance rule, the magical barding
    // costs and percentages, the flying
    // and aquatic steeds rules. The R368
    // seam cross-checks the cavalier d10
    // floor. Three items flip CLOSED; the
    // census 296 -> 297.
    {
        using namespace rules;
        int bad = 0;
        // ---- Method V ----
            if (!uasm1MethodVHumansOnly()) ++bad;
            if (!uasm1MethodVClassFirst()) ++bad;
            if (!uasm1MethodVRequiresDmApproval())
                ++bad;
            if (!uasm1MethodVBestThreeOfN()) ++bad;
            if (!uasm1MethodVMinClampApplies())
                ++bad;
            if (!uasm1MethodVMaxClampApplies())
                ++bad;
            if (uasm1MethodVFighterStrengthDice()
                    != 9) ++bad;
            if (!uasm1MethodVTableCellsLost())
                ++bad;
        // ---- the starting hit points ----
            if (uasm1StartHpClassCount() != 12)
                ++bad;
            static const int hp[12] = {6, 6,
                5, 5, 6, 7, 9, 3, 3, 4, 4, 5};
            for (int i = 0; i < 12; ++i) {
                if (uasm1StartHpMin(i) != hp[i])
                    ++bad;
            }
            if (!uasm1StartHpMultiClassAverageRoundedUp())
                ++bad;
            if (uasm1StartHpExampleFighterMage()
                    != 5) ++bad;
            if (!uasm1StartHpConAdjustApplies())
                ++bad;
            if (uasm1StartHpExampleCon17Fighter()
                    != 9) ++bad;
            // the multi-class read: the
            // average of the minimums,
            // rounded up
            if ((6 + 3 + 1) / 2
                    != uasm1StartHpExampleFighterMage())
                ++bad;
            // the con-17 example: the
            // fighter floor plus the +3
            if (uasm1StartHpMin(4) + 3
                    != uasm1StartHpExampleCon17Fighter())
                ++bad;
        // ---- the barding table ----
            if (uasm1BardLightLeather() != 21)
                ++bad;
            if (uasm1BardLightChain() != 15)
                ++bad;
            if (!uasm1BardLightScaleNa()) ++bad;
            if (!uasm1BardLightPlateNa()) ++bad;
            if (uasm1BardMediumLeather() != 17)
                ++bad;
            if (uasm1BardMediumChain() != 15)
                ++bad;
            if (!uasm1BardMediumScaleCellLost())
                ++bad;
            if (!uasm1BardMediumPlateNa()) ++bad;
            if (!uasm1BardHeavyLeatherCellLost())
                ++bad;
            if (uasm1BardHeavyChain() != 14)
                ++bad;
            if (uasm1BardHeavyScale() != 13)
                ++bad;
            if (uasm1BardHeavyPlate() != 12)
                ++bad;
            // the movement monotonicity:
            // heavier barding, slower
            if (uasm1BardHeavyChain()
                    <= uasm1BardHeavyScale()) ++bad;
            if (uasm1BardHeavyScale()
                    <= uasm1BardHeavyPlate()) ++bad;
            if (uasm1BardLightLeather()
                    <= uasm1BardMediumLeather())
                ++bad;
            if (!uasm1BardEnduranceFromBaseRate())
                ++bad;
        // ---- the magical barding ----
            if (uasm1MagBardingCostMultiple()
                    != 5) ++bad;
            if (uasm1MagBardingPlusCap() != 3)
                ++bad;
            if (uasm1MagBardingPlus1Pct()
                    + uasm1MagBardingPlus2Pct()
                    + uasm1MagBardingPlus3Pct()
                    != 100) ++bad;
            if (uasm1MagBardingLeatherPct()
                    + uasm1MagBardingScalePct()
                    + uasm1MagBardingChainPct()
                    + uasm1MagBardingPlatePct()
                    != 100) ++bad;
            if (uasm1MagBardingPlus1Pct()
                    != 65) ++bad;
            if (uasm1MagBardingPlus2Pct()
                    != 25) ++bad;
            if (uasm1MagBardingPlus3Pct()
                    != 10) ++bad;
            if (uasm1MagBardingLeatherPct()
                    != 10) ++bad;
            if (uasm1MagBardingScalePct()
                    != 15) ++bad;
            if (uasm1MagBardingChainPct()
                    != 25) ++bad;
            if (uasm1MagBardingPlatePct()
                    != 50) ++bad;
        // ---- the other steeds ----
            if (!uasm1FlyingSteedsLeatherOrElfinOnly())
                ++bad;
            if (!uasm1FlyingSteedsReductionEighth())
                ++bad;
            if (!uasm1AquaticSteedsNotBarded())
                ++bad;
            if (uasm1StrongMountPlateReductionMin()
                    != 5) ++bad;
            if (uasm1StrongMountPlateReductionMax()
                    != 8) ++bad;
            if (!uasm1UnicornGriffonElfinWeightAsLeather())
                ++bad;
        // ---- the R368 seam ----
            // the cavalier starting floor
            // (6) cannot exceed the d10
            // level-1 hit die the R368 pin
            // carries
            if (uasm1StartHpMin(0)
                    > uacavtDirectFirstSides())
                ++bad;
        printf("R370 UA DM-section smalls pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R370 audit')
s = rd(RT)
assert s.count(
    'R370 UA DM-section smalls pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 297, 'd census 297'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uasmalls1.h"'
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
        'rules/uailacquisition.h'):
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
assert len(applied) + len(already) == 6,'d count'


# ---- the summary ----
print(
    'R370 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R370 note: the DM-section smalls',
    'part 1 - Method V (the prose clean,',
    'the dice table cells a hole), the',
    'starting hit-point minimums with',
    'the multi-class and con examples,',
    'the barding movement table with two',
    'lost cells flagged, the magical',
    'barding and steeds rules; the R368',
    'seam cross-checks the cavalier d10',
    'floor; three items flip CLOSED;',
    'the census 296 -> 297'
])
print(NOTE)
print('commit: R370: the UA DM-section')
print('smalls part 1 pin round (census 297)',)

