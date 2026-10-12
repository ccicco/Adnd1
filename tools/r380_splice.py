# R380: the UA new wands prose
# pin round (pp. 96-97): SEVEN
# of the twelve new wand types
# pin - FIVE fully clean
# (anything - the 50 usages,
# the once-per-kind
# duplication, the
# three-demand drain; fireballs
# - the 6th-level caster, the
# two segments, 6-36 save half,
# the MU-8 recharge; flame
# extinguishing - the free
# normal fires, the 1-charge
# large normal, the 6-round
# suppression, the 2-charge
# large magical, the 6-36
# against fire creatures; ice
# storms - the 7th-level
# caster, the two segments, the
# MU-9 recharge; lightning
# bolts - the 6th-level caster,
# forked or single, the two
# segments, the MU-8 recharge)
# plus TWO mechanics-clean with
# flagged holes (defoliation -
# the opening construction
# sentence interleaves, all
# charge mechanics read; metal
# command - the transmutation
# verb drops, all three charge
# functions read); FIVE types
# OCR-scramble (buckler's
# activation sentence, earth
# and stone's charge mapping,
# force's third-function cost,
# size alteration's effect
# magnitude, steam and vapor's
# cone dimensions) - the gap
# item AMENDED, stays OPEN,
# PDF-gated; the R379 seam the
# rods ledger, the R375 seam
# the wand band; the census
# 306 -> 307.
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



# ---- (a) the seed: the R379 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R379 landed 2026-10-12: commit',
    '  1b76292, census 306, the UA',
    '  new rods staves prose pin',
    '  round (rules/uarodstave.h):',
    '  four of the eleven new',
    '  descriptions pin clean',
    '  (the rod of alertness, the',
    '  rod of security, the',
    '  staff-mace, the staff of',
    '  slinging); seven',
    '  descriptions OCR-scramble',
    '  (flailing, passage,',
    '  splendor, staff-spear,',
    '  swarming insects, thunder',
    '  and lightning, woodlands)',
    '  - the item AMENDED, stays',
    '  OPEN, PDF-gated; the R378',
    '  seam the rings ledger,',
    '  the R375 seam the rod',
    '  band; GREEN on the first',
    '  run.'
])
s = rd(SD)
if 'R379 landed 2026-10-12' in s:
    already.append('seed: the R379 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R379 record')
s = rd(SD)
assert s.count(
    'R379 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uawandprose.h ----
P = 'rules/uawandprose.h'
if os.path.exists(P) and 'R380' in rd(P):
    already.append('uawandprose.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uawandprose.h
// The UA TREASURE (WANDS)
// prose pins, R380: the seven
// pinnable new-wand types
// (pp. 96-97) - five fully
// clean (anything, fireballs,
// flame extinguishing, ice
// storms, lightning bolts)
// plus two mechanics-clean
// with flagged holes
// (defoliation's opening
// sentence, metal command's
// dropped verb). The five
// garbled types (buckler,
// earth and stone, force,
// size alteration, steam and
// vapor) await the PDF - the
// gap item stays open. The
// rods and skeleton seams
// ride in the regtest audit,
// not here.
namespace rules {

// ---- the anything wand ----
// Performs as an ordinary
// wand of wonder, with no
// more than 50 usages.
inline bool uawdAnyIsWonderLike()
    { return true; }

inline int uawdAnyMaxUsages()
    { return 50; }

// Upon command it performs as
// any other known wand, but
// each kind only once - a
// repeated command has no
// effect.
inline bool uawdAnyDuplicatesAnyKnownWand()
    { return true; }

inline bool uawdAnyEachKindOnce()
    { return true; }

inline bool uawdAnyRepeatCommandInert()
    { return true; }

// After three such demands,
// successful or not, the wand
// is totally drained and
// useless; it cannot be
// recharged.
inline int uawdAnyDrainDemands()
    { return 3; }

inline bool uawdAnyDrainCountsFailed()
    { return true; }

inline bool uawdAnyRechargeable()
    { return false; }

// ---- the wand of fireballs
// ----
// Casts fireball as a
// magic-user of 6th level; 1
// segment to activate, 1
// segment to loose the
// fireball.
inline int uawdFbCasterLevel()
    { return 6; }

inline int uawdFbActivateSegs()
    { return 1; }

inline int uawdFbDischargeSegs()
    { return 1; }

// Damage 6-36 (6d6), save for
// half; recharge by a
// magic-user of 8th or higher.
inline int uawdFbDmgDice()
    { return 6; }

inline int uawdFbDmgLo()
    { return 6; }

inline int uawdFbDmgHi()
    { return 36; }

inline bool uawdFbSaveForHalf()
    { return true; }

inline int uawdFbRechargeMuLevel()
    { return 8; }

// ---- the wand of flame
// extinguishing ----
// Normal fires: no charges -
// up to a bonfire or hearth
// fire, four to six billets
// burning hotly.
inline bool uawdFxNormalFree()
    { return true; }

inline int uawdFxNormalBilletsLo()
    { return 4; }

inline int uawdFxNormalBilletsHi()
    { return 6; }

// Large normal fires - a
// gallon or more of flaming
// oil, demon or devil fire,
// flame tongue, burning hands
// - cost 1 charge; continual
// magical flames suppress 6
// rounds then flare up again.
inline int uawdFxLargeNormalCharges()
    { return 1; }

inline int uawdFxOilGallonMin()
    { return 1; }

inline int uawdFxSuppressionRounds()
    { return 6; }

// Large magical fires -
// fireball, flame strike,
// wall of fire - cost 2
// charges.
inline int uawdFxLargeMagicalCharges()
    { return 2; }

// One charge against a fire
// creature (a fire elemental)
// inflicts 6-36 (6d6).
inline int uawdFxCreatureCharges()
    { return 1; }

inline int uawdFxCreatureDmgDice()
    { return 6; }

inline int uawdFxCreatureDmgLo()
    { return 6; }

inline int uawdFxCreatureDmgHi()
    { return 36; }

// ---- the wand of ice storms
// ----
// Ice storm as a magic-user
// of 7th level; hail or sleet
// forms; 1 segment to
// activate, 1 segment for the
// dweomer to emerge; recharge
// by a magic-user of 9th or
// higher.
inline int uawdIceCasterLevel()
    { return 7; }

inline int uawdIceFormsCount()
    { return 2; }

inline int uawdIceActivateSegs()
    { return 1; }

inline int uawdIceEmergeSegs()
    { return 1; }

inline int uawdIceRechargeMuLevel()
    { return 9; }

// ---- the wand of lightning
// bolts ----
// Lightning bolt as a
// magic-user of 6th level;
// forked or single stroke;
// 1 segment to activate, 1
// segment to discharge;
// recharge by a magic-user of
// 8th or higher.
inline int uawdLbCasterLevel()
    { return 6; }

inline bool uawdLbForkedOrSingle()
    { return true; }

inline int uawdLbDmgDice()
    { return 6; }

inline int uawdLbDmgLo()
    { return 6; }

inline int uawdLbDmgHi()
    { return 36; }

inline bool uawdLbSaveForHalf()
    { return true; }

inline int uawdLbActivateSegs()
    { return 1; }

inline int uawdLbDischargeSegs()
    { return 1; }

inline int uawdLbRechargeMuLevel()
    { return 8; }

// ---- the wand of
// defoliation ----
// The opening construction
// sentence interleaves in the
// extract - the hole flagged;
// all charge mechanics read
// clean. Never wood - ivory
// or bone.
inline bool uawdDefOpeningHoleFlagged()
    { return true; }

// One charge: all chlorophyll
// in a 3" radius destroyed -
// leaves turn autumnal and
// drop, grass browns.
inline int uawdDefChlorophyllCharges()
    { return 1; }

inline int uawdDefChlorophyllRadiusIn()
    { return 3; }

// Two charges: normal plant
// life in the 3" radius
// withers and dies; sentient
// and non-normal plants
// suffer 1-6 (1d6) instead.
inline int uawdDefWitherCharges()
    { return 2; }

inline int uawdDefWitherRadiusIn()
    { return 3; }

inline int uawdDefSentientDmgLo()
    { return 1; }

inline int uawdDefSentientDmgHi()
    { return 6; }

// The cone option: 3" length,
// 1" diameter at the far
// point; sentient and
// non-normal plants there
// suffer 6-36 (6d6), save
// versus rods staves wands
// for half (3d6).
inline int uawdDefConeLengthIn()
    { return 3; }

inline int uawdDefConeFarDiamIn()
    { return 1; }

inline int uawdDefConeDmgDice()
    { return 6; }

inline int uawdDefConeDmgLo()
    { return 6; }

inline int uawdDefConeDmgHi()
    { return 36; }

inline bool uawdDefConeSaveForHalf()
    { return true; }

inline int uawdDefConeHalfDice()
    { return 3; }

// ---- the wand of metal
// command ----
// The transmutation sentence
// drops its verb in the
// extract - the hole flagged;
// all three charge functions
// read clean. Appears as a
// wand of metal and mineral
// detection; operational only
// in the hands of a dwarf or
// gnome.
inline bool uawdMcVerbHoleFlagged()
    { return true; }

inline bool uawdMcAppearsDetection()
    { return true; }

inline bool uawdMcDwarfGnomeOnly()
    { return true; }

// One charge: gold to lead or
// lead to gold, range 3", 1-6
// pounds (10-60 gp weight).
inline int uawdMcTransmuteCharges()
    { return 1; }

inline int uawdMcTransmuteRangeIn()
    { return 3; }

inline int uawdMcTransmuteLbsLo()
    { return 1; }

inline int uawdMcTransmuteLbsHi()
    { return 6; }

inline int uawdMcTransmuteGpLo()
    { return 10; }

inline int uawdMcTransmuteGpHi()
    { return 60; }

// Two charges: heat metal as
// the druid spell, range 3",
// a single 3-foot diameter
// target area, up to 600 gp
// weight of metal.
inline int uawdMcHeatCharges()
    { return 2; }

inline int uawdMcHeatRangeIn()
    { return 3; }

inline int uawdMcHeatAreaDiamFt()
    { return 3; }

inline int uawdMcHeatMaxGp()
    { return 600; }

// Three charges: crystalbrittle,
// glassee, or glassteel as an
// 18th-level magic-user.
inline int uawdMcSpellCharges()
    { return 3; }

inline int uawdMcSpellCount()
    { return 3; }

inline int uawdMcSpellCasterLevel()
    { return 18; }

// ---- the extract ledger ----
// Five fully clean, two
// mechanics-clean with
// flagged holes, five
// garbled - twelve types.
inline int uawdCleanCount()
    { return 5; }

inline int uawdFlaggedCount()
    { return 2; }

inline int uawdGarbledCount()
    { return 5; }

inline int uawdTotalTypes()
    { return 12; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uawandprose.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 75, 'b inline count'
assert s.count('R380') == 1, 'b round tag'
assert s.count(
    'uawdAnyIsWonderLike'
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
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R380' in s:
    already.append('gap: the amendment')
else:
    OLD = '- [ ] **The new wands** (pp. 96-97).'
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [ ] **The new wands** (pp. 96-97).',
        '      - AMENDED R380: the new',
        '        wands prose pin round',
        '        (rules/uawandprose.h) -',
        '        SEVEN of the twelve new',
        '        wand types pin: FIVE',
        '        fully clean (anything,',
        '        fireballs, flame',
        '        extinguishing, ice',
        '        storms, lightning',
        '        bolts) plus TWO',
        '        mechanics-clean with',
        '        flagged holes',
        '        (defoliation\'s opening',
        '        sentence, metal',
        '        command\'s dropped',
        '        verb); FIVE types',
        '        OCR-scramble (buckler\'s',
        '        activation sentence,',
        '        earth and stone\'s',
        '        charge mapping,',
        '        force\'s third-function',
        '        cost, size alteration\'s',
        '        effect magnitude,',
        '        steam and vapor\'s cone',
        '        dimensions) - the item',
        '        stays OPEN, PDF-gated',
        '        for the garbled',
        '        remainder.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the amendment')
wr(GP, s)

# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [ ] **The new wands**'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R380'
) == 1, 'c amendment'
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
    '(rules/uawandprose.h)'
) == 1, 'c wands note'
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
if 'R380 UA new wands prose pin audit' in s:
    already.append('regtest.cpp: the R380 audit')
else:
    INC_ANCH = ('#include "rules/uarodstave.h"  // '
        'R379: the UA new rods staves prose')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uawandprose.h"  // R380: the UA new wands prose'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R380: the UA new wands
    // prose pin audit ----
    // The seven pinnable wand
    // types (pp. 96-97): five
    // fully clean (anything,
    // fireballs, flame
    // extinguishing, ice
    // storms, lightning bolts)
    // plus two mechanics-clean
    // with flagged holes
    // (defoliation, metal
    // command). The five
    // garbled types stay
    // PDF-gated. The R379 seam
    // cross-checks the rods
    // ledger, the R375 seam the
    // wand band; the census
    // 306 -> 307.
    {
        using namespace rules;
        int bad = 0;
        // ---- the anything wand ----
            if (!uawdAnyIsWonderLike()) ++bad;
            if (uawdAnyMaxUsages() != 50) ++bad;
            if (!uawdAnyDuplicatesAnyKnownWand())
                ++bad;
            if (!uawdAnyEachKindOnce()) ++bad;
            if (!uawdAnyRepeatCommandInert())
                ++bad;
            if (uawdAnyDrainDemands() != 3) ++bad;
            if (!uawdAnyDrainCountsFailed()) ++bad;
            if (uawdAnyRechargeable()) ++bad;
        // ---- the wand of fireballs ----
            if (uawdFbCasterLevel() != 6) ++bad;
            if (uawdFbActivateSegs() != 1) ++bad;
            if (uawdFbDischargeSegs() != 1) ++bad;
            if (uawdFbDmgDice() != 6) ++bad;
            if (uawdFbDmgLo() != 6) ++bad;
            if (uawdFbDmgHi() != 36) ++bad;
            if (!uawdFbSaveForHalf()) ++bad;
            if (uawdFbRechargeMuLevel() != 8) ++bad;
        // ---- the wand of flame
        // extinguishing ----
            if (!uawdFxNormalFree()) ++bad;
            if (uawdFxNormalBilletsLo() != 4)
                ++bad;
            if (uawdFxNormalBilletsHi() != 6)
                ++bad;
            if (uawdFxLargeNormalCharges() != 1)
                ++bad;
            if (uawdFxOilGallonMin() != 1) ++bad;
            if (uawdFxSuppressionRounds() != 6)
                ++bad;
            if (uawdFxLargeMagicalCharges() != 2)
                ++bad;
            if (uawdFxCreatureCharges() != 1)
                ++bad;
            if (uawdFxCreatureDmgDice() != 6)
                ++bad;
            if (uawdFxCreatureDmgLo() != 6) ++bad;
            if (uawdFxCreatureDmgHi() != 36)
                ++bad;
            // the creature blast
            // mirrors the fireball
            // damage band
            if (uawdFxCreatureDmgLo()
                    != uawdFbDmgLo()
                    || uawdFxCreatureDmgHi()
                    != uawdFbDmgHi()) ++bad;
        // ---- the wand of ice storms ----
            if (uawdIceCasterLevel() != 7) ++bad;
            if (uawdIceFormsCount() != 2) ++bad;
            if (uawdIceActivateSegs() != 1) ++bad;
            if (uawdIceEmergeSegs() != 1) ++bad;
            if (uawdIceRechargeMuLevel() != 9)
                ++bad;
        // ---- the wand of lightning bolts ----
            if (uawdLbCasterLevel() != 6) ++bad;
            if (!uawdLbForkedOrSingle()) ++bad;
            if (uawdLbDmgDice() != 6) ++bad;
            if (uawdLbDmgLo() != 6) ++bad;
            if (uawdLbDmgHi() != 36) ++bad;
            if (!uawdLbSaveForHalf()) ++bad;
            if (uawdLbActivateSegs() != 1) ++bad;
            if (uawdLbDischargeSegs() != 1) ++bad;
            if (uawdLbRechargeMuLevel() != 8)
                ++bad;
            // the lightning bolt
            // mirrors the fireball:
            // same caster level,
            // same damage band, the
            // same recharge level
            if (uawdLbCasterLevel()
                    != uawdFbCasterLevel()) ++bad;
            if (uawdLbDmgLo() != uawdFbDmgLo()
                    || uawdLbDmgHi()
                    != uawdFbDmgHi()) ++bad;
            if (uawdLbRechargeMuLevel()
                    != uawdFbRechargeMuLevel())
                ++bad;
        // ---- the wand of defoliation ----
            if (!uawdDefOpeningHoleFlagged())
                ++bad;
            if (uawdDefChlorophyllCharges() != 1)
                ++bad;
            if (uawdDefChlorophyllRadiusIn() != 3)
                ++bad;
            if (uawdDefWitherCharges() != 2) ++bad;
            if (uawdDefWitherRadiusIn() != 3)
                ++bad;
            if (uawdDefSentientDmgLo() != 1)
                ++bad;
            if (uawdDefSentientDmgHi() != 6) ++bad;
            if (uawdDefConeLengthIn() != 3) ++bad;
            if (uawdDefConeFarDiamIn() != 1) ++bad;
            if (uawdDefConeDmgDice() != 6) ++bad;
            if (uawdDefConeDmgLo() != 6) ++bad;
            if (uawdDefConeDmgHi() != 36) ++bad;
            if (!uawdDefConeSaveForHalf()) ++bad;
            if (uawdDefConeHalfDice() != 3) ++bad;
            // the cone's half-damage
            // is half the dice
            if (2 * uawdDefConeHalfDice()
                    != uawdDefConeDmgDice()) ++bad;
        // ---- the wand of metal command ----
            if (!uawdMcVerbHoleFlagged()) ++bad;
            if (!uawdMcAppearsDetection()) ++bad;
            if (!uawdMcDwarfGnomeOnly()) ++bad;
            if (uawdMcTransmuteCharges() != 1)
                ++bad;
            if (uawdMcTransmuteRangeIn() != 3)
                ++bad;
            if (uawdMcTransmuteLbsLo() != 1) ++bad;
            if (uawdMcTransmuteLbsHi() != 6) ++bad;
            if (uawdMcTransmuteGpLo() != 10) ++bad;
            if (uawdMcTransmuteGpHi() != 60) ++bad;
            // ten gp per pound rides
            // the transmutation
            if (uawdMcTransmuteGpLo()
                    != 10 * uawdMcTransmuteLbsLo()
                    || uawdMcTransmuteGpHi()
                    != 10 * uawdMcTransmuteLbsHi())
                ++bad;
            if (uawdMcHeatCharges() != 2) ++bad;
            if (uawdMcHeatRangeIn() != 3) ++bad;
            if (uawdMcHeatAreaDiamFt() != 3) ++bad;
            if (uawdMcHeatMaxGp() != 600) ++bad;
            if (uawdMcSpellCharges() != 3) ++bad;
            if (uawdMcSpellCount() != 3) ++bad;
            if (uawdMcSpellCasterLevel() != 18)
                ++bad;
        // ---- the extract ledger ----
            if (uawdCleanCount() != 5) ++bad;
            if (uawdFlaggedCount() != 2) ++bad;
            if (uawdGarbledCount() != 5) ++bad;
            if (uawdTotalTypes() != 12) ++bad;
            if (uawdCleanCount() + uawdFlaggedCount()
                    + uawdGarbledCount()
                    != uawdTotalTypes()) ++bad;
        // ---- the R379 rods seam ----
            if (uaroCleanCount() != 4) ++bad;
            if (uaroGarbledCount() != 7) ++bad;
        // ---- the R375 skeleton seam ----
            // the wands ride the
            // rods staves wands band
            // as its II.D.2 second
            // table
            if (strcmp(uadsCategoryName(3),
                    "Rods, Staves & Wands") != 0)
                ++bad;
            if (!uadsIsTheRevisedTable()) ++bad;
            if (!uadsRodSecondTableIsIID2())
                ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R380 UA new wands prose pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R380 audit')
s = rd(RT)
assert s.count(
    'R380 UA new wands prose pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 307, 'd census 307'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uawandprose.h"'
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
    'R380 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R380 note: the new wands',
    'prose round - seven of',
    'the twelve new wand types',
    'pin: five fully clean',
    '(anything, fireballs,',
    'flame extinguishing, ice',
    'storms, lightning bolts)',
    'plus two mechanics-clean',
    'with flagged holes',
    '(defoliation, metal',
    'command); five types',
    'OCR-scramble (buckler,',
    'earth and stone, force,',
    'size alteration, steam',
    'and vapor) - the item',
    'AMENDED, stays OPEN,',
    'PDF-gated; the R379 seam',
    'the rods ledger, the',
    'R375 seam the wand band;',
    'the census',
    '306 -> 307'
])
print(NOTE)
print('commit: R380: the UA new')
print('wands prose pin round')
print('(census 307)',)

