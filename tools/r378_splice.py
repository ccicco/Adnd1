# R378: the UA new rings prose
# pin round (pp. 92-94): SIX of
# the thirteen new-ring
# descriptions pin clean -
# animal friendship (12 HD at
# 6th level, 27 charges, druid
# 24 / ranger 18), anything
# (warmth guise, three
# commands, 100-600 gp
# residue), blinking (6 rounds,
# 6-turn recharge, 10-foot
# word), jumping (30 ahead, 10
# back or up, four per day),
# mind shielding (the four
# immunity reads, the psionic
# adjustments), truth (the
# falsetto, the dweomer
# silence); SEVEN descriptions
# OCR-scramble (boccob's save
# list, chameleon's detection
# tail, clumsiness' power
# table, faerie's fraction
# cells, ram's adjustment tail,
# shocking grasp's opening,
# sustenance's reattune) - the
# gap item AMENDED, stays OPEN,
# PDF-gated; the R377 seam the
# scrolls ledger, the R375 seam
# the ring band; the census
# 304 -> 305.
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



# ---- (a) the seed: the R377 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R377 landed 2026-10-12: commit',
    '  fe06b2c, census 304, the UA',
    '  new scrolls protection prose',
    '  pin round (rules/uaprotscr.h):',
    '  eleven of the fifteen',
    '  protection-scroll types pin',
    '  clean (acid, breath weapons,',
    '  fire, gas, illusions,',
    '  paralyzation, plants,',
    '  poison, the traps trio at',
    '  50/30/20, water); four types',
    '  OCR-scramble (cold,',
    '  electricity, the two weapons',
    '  scrolls) - the item',
    '  AMENDED, stays OPEN,',
    '  PDF-gated; the R376 seam the',
    '  potions ledger, the R375',
    '  seam the scroll splits;',
    '  GREEN on the first run.'
])
s = rd(SD)
if 'R377 landed 2026-10-12' in s:
    already.append('seed: the R377 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R377 record')
s = rd(SD)
assert s.count(
    'R377 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uaringprose.h ----
P = 'rules/uaringprose.h'
if os.path.exists(P) and 'R378' in rd(P):
    already.append('uaringprose.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaringprose.h
// The UA TREASURE (RINGS) prose
// pins, R378: the six clean
// new-ring descriptions
// (pp. 92-94) - animal
// friendship, anything,
// blinking, jumping, mind
// shielding, truth. The seven
// garbled descriptions
// (boccob's save list,
// chameleon's detection tail,
// clumsiness' power table,
// faerie's fraction cells,
// ram's adjustment tail,
// shocking grasp's opening,
// sustenance's reattune) await
// the PDF - the gap item
// stays open. The scrolls and
// skeleton seams ride in the
// regtest audit, not here.
namespace rules {

// ---- the ring of animal
// friendship ----
// Within 1" of neutral
// animals of animal
// intelligence: save versus
// spell - success flees,
// failure goes docile and
// follows.
inline int uarpAfRadiusIn()
    { return 1; }

inline bool uarpAfSaveIsVsSpell()
    { return true; }

inline bool uarpAfSaveSuccessFlees()
    { return true; }

inline bool uarpAfSaveFailDocile()
    { return true; }

// The dweomer functions at
// 6th level: 12 hit dice of
// animals; a charge buys
// guard-and-protect.
inline int uarpAfDweomerLevel()
    { return 6; }

inline int uarpAfMaxHd()
    { return 12; }

inline int uarpAfGuardCostCharges()
    { return 1; }

inline int uarpAfChargesTypical()
    { return 27; }

inline bool uarpAfRechargeable()
    { return false; }

// A druid influences twice
// the hit dice; a ranger
// eighteen.
inline int uarpAfDruidMaxHd()
    { return 24; }

inline int uarpAfRangerMaxHd()
    { return 18; }

// ---- the anything ring ----
// Initially appears as a
// standard ring of warmth;
// three commanded functions
// from among the other
// standard sorts.
inline bool uarpAnyAppearsWarmth()
    { return true; }

inline int uarpAnyCommands()
    { return 3; }

// Operation-type functions
// give one operation; the
// rest last one day (24
// hours). Any commanded
// function never comes
// again.
inline bool uarpAnyOpTypeIsOneOperation()
    { return true; }

inline int uarpAnyEffectHours()
    { return 24; }

inline bool uarpAnyNeverReusable()
    { return true; }

// After three singular uses
// the ring turns to
// non-magical jewelry worth
// 100 to 600 gp.
inline bool uarpAnyBecomesJewelry()
    { return true; }

inline int uarpAnyJewelryLoGp()
    { return 100; }

inline int uarpAnyJewelryHiGp()
    { return 600; }

// ---- the ring of blinking ----
// The proper verbal command
// activates a blink spell
// effect for 6 rounds; the
// ring then rests 6 turns
// (1 hour) replenishing.
inline bool uarpBlinkIsBlinkSpell()
    { return true; }

inline int uarpBlinkActiveRounds()
    { return 6; }

inline int uarpBlinkRechargeTurns()
    { return 6; }

inline int uarpBlinkRechargeHours()
    { return 1; }

// The command word is
// usually engraved on the
// ring; anyone may speak it
// within 10 feet.
inline bool uarpBlinkWordEngraved()
    { return true; }

inline bool uarpBlinkAnyoneMaySpeak()
    { return true; }

inline int uarpBlinkActivationFeet()
    { return 10; }

// ---- the ring of jumping ----
// One segment to call forth:
// leap 30 feet ahead, or 10
// feet backwards or straight
// up, an arc of 2 feet per
// 10 feet traveled; four
// times per day.
inline int uarpJumpActivationSegs()
    { return 1; }

inline int uarpJumpAheadFeet()
    { return 30; }

inline int uarpJumpBackFeet()
    { return 10; }

inline int uarpJumpArcFeetPerTen()
    { return 2; }

inline int uarpJumpUsesPerDay()
    { return 4; }

// ---- the ring of mind
// shielding ----
// Fine gold workmanship; the
// wearer is immune to ESP,
// detect lie, know
// alignment, and telepathic
// reading of the mind.
inline int uarpMsImmuneCount()
    { return 4; }

inline bool uarpMsBlocksEsp()
    { return true; }

inline bool uarpMsBlocksDetectLie()
    { return true; }

inline bool uarpMsBlocksKnowAlignment()
    { return true; }

inline bool uarpMsBlocksTelepathy()
    { return true; }

// A psionic wearer gains a
// thought shield at no point
// cost; psionic attack damage
// at -2.
inline bool uarpMsThoughtShieldFree()
    { return true; }

inline int uarpMsPsionicAttackDmgAdj()
    { return -2; }

// Versus a psionic blast: +1
// on saves if not psionically
// endowed, -3 on damage if
// psionic.
inline int uarpMsBlastSaveNonPsionic()
    { return 1; }

inline int uarpMsBlastDmgPsionic()
    { return -3; }

// ---- the ring of truth ----
// Any lie told to the wearer
// is detectable; the wearer
// cannot lie - any attempt
// speaks the literal truth -
// and discerns the last
// prevarication; the liar's
// voice rises to falsetto.
inline bool uarpTruthLiesDetectable()
    { return true; }

inline bool uarpTruthWearerCannotLie()
    { return true; }

inline bool uarpTruthSpeaksLiteralTruth()
    { return true; }

inline bool uarpTruthDiscernsLastLie()
    { return true; }

inline bool uarpTruthFalsettoVoice()
    { return true; }

// Against falsehood-masking
// dweomers (undetectable lie,
// philter of glibness): no
// lie is noticed, and the
// wearer does not hear the
// dweomered person's voice.
inline bool uarpTruthDweomerBlocksNotice()
    { return true; }

inline bool uarpTruthDweomerSilencesVoice()
    { return true; }

// ---- the extract ledger ----
// Six of the thirteen
// descriptions pin; the
// seven garbled ones stay
// PDF-gated.
inline int uarpCleanCount()
    { return 6; }

inline int uarpGarbledCount()
    { return 7; }

inline int uarpTotalTypes()
    { return 13; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uaringprose.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 50, 'b inline count'
assert s.count('R378') == 1, 'b round tag'
assert s.count(
    'uarpAfRadiusIn'
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
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R378' in s:
    already.append('gap: the amendment')
else:
    OLD = '- [ ] **The new rings** (pp. 92-94).'
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [ ] **The new rings** (pp. 92-94).',
        '      - AMENDED R378: the new',
        '        rings prose pin round',
        '        (rules/uaringprose.h) -',
        '        SIX of the thirteen',
        '        new-ring descriptions',
        '        pin clean (animal',
        '        friendship, anything,',
        '        blinking, jumping,',
        '        mind shielding,',
        '        truth); SEVEN',
        '        descriptions',
        '        OCR-scramble (boccob\'s',
        '        save list, chameleon\'s',
        '        detection tail,',
        '        clumsiness\' power',
        '        table, faerie\'s',
        '        fraction cells, ram\'s',
        '        adjustment tail,',
        '        shocking grasp\'s',
        '        opening, sustenance\'s',
        '        reattune) - the item',
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
    '- [ ] **The new rings**'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R378'
) == 1, 'c amendment'
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
    '(rules/uaringprose.h)'
) == 1, 'c rings note'
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
    '- [ ] **The new rods and staves**'
) == 1, 'c rods staves kept open'
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
if 'R378 UA new rings prose pin audit' in s:
    already.append('regtest.cpp: the R378 audit')
else:
    INC_ANCH = ('#include "rules/uaprotscr.h"  // '
        'R377: the UA new scrolls prose')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaringprose.h"  // R378: the UA new rings prose'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R378: the UA new rings
    // prose pin audit ----
    // The six clean new-ring
    // descriptions (pp. 92-94):
    // animal friendship,
    // anything, blinking,
    // jumping, mind shielding,
    // truth. The seven garbled
    // descriptions stay
    // PDF-gated. The R377 seam
    // cross-checks the scrolls
    // ledger, the R375 seam the
    // ring band; the census
    // 304 -> 305.
    {
        using namespace rules;
        int bad = 0;
        // ---- the animal friendship ring ----
            if (uarpAfRadiusIn() != 1) ++bad;
            if (!uarpAfSaveIsVsSpell()) ++bad;
            if (!uarpAfSaveSuccessFlees()) ++bad;
            if (!uarpAfSaveFailDocile()) ++bad;
            if (uarpAfDweomerLevel() != 6) ++bad;
            if (uarpAfMaxHd() != 12) ++bad;
            if (uarpAfGuardCostCharges() != 1) ++bad;
            if (uarpAfChargesTypical() != 27) ++bad;
            if (uarpAfRechargeable()) ++bad;
            if (uarpAfDruidMaxHd() != 24) ++bad;
            if (uarpAfRangerMaxHd() != 18) ++bad;
            // the druid doubles the
            // base dice; the ranger
            // rides the middle
            if (uarpAfDruidMaxHd()
                    != 2 * uarpAfMaxHd()) ++bad;
            if (uarpAfRangerMaxHd()
                    <= uarpAfMaxHd()) ++bad;
        // ---- the anything ring ----
            if (!uarpAnyAppearsWarmth()) ++bad;
            if (uarpAnyCommands() != 3) ++bad;
            if (!uarpAnyOpTypeIsOneOperation())
                ++bad;
            if (uarpAnyEffectHours() != 24) ++bad;
            if (!uarpAnyNeverReusable()) ++bad;
            if (!uarpAnyBecomesJewelry()) ++bad;
            if (uarpAnyJewelryLoGp() != 100) ++bad;
            if (uarpAnyJewelryHiGp() != 600) ++bad;
            if (uarpAnyJewelryLoGp()
                    >= uarpAnyJewelryHiGp()) ++bad;
        // ---- the blinking ring ----
            if (!uarpBlinkIsBlinkSpell()) ++bad;
            if (uarpBlinkActiveRounds() != 6) ++bad;
            if (uarpBlinkRechargeTurns() != 6) ++bad;
            if (uarpBlinkRechargeHours() != 1) ++bad;
            if (!uarpBlinkWordEngraved()) ++bad;
            if (!uarpBlinkAnyoneMaySpeak()) ++bad;
            if (uarpBlinkActivationFeet() != 10)
                ++bad;
        // ---- the jumping ring ----
            if (uarpJumpActivationSegs() != 1)
                ++bad;
            if (uarpJumpAheadFeet() != 30) ++bad;
            if (uarpJumpBackFeet() != 10) ++bad;
            if (uarpJumpArcFeetPerTen() != 2) ++bad;
            if (uarpJumpUsesPerDay() != 4) ++bad;
            if (uarpJumpAheadFeet()
                    != 3 * uarpJumpBackFeet()) ++bad;
        // ---- the mind shielding ring ----
            if (uarpMsImmuneCount() != 4) ++bad;
            if (!uarpMsBlocksEsp()) ++bad;
            if (!uarpMsBlocksDetectLie()) ++bad;
            if (!uarpMsBlocksKnowAlignment()) ++bad;
            if (!uarpMsBlocksTelepathy()) ++bad;
            if (!uarpMsThoughtShieldFree()) ++bad;
            if (uarpMsPsionicAttackDmgAdj() != -2)
                ++bad;
            if (uarpMsBlastSaveNonPsionic() != 1)
                ++bad;
            if (uarpMsBlastDmgPsionic() != -3) ++bad;
        // ---- the truth ring ----
            if (!uarpTruthLiesDetectable()) ++bad;
            if (!uarpTruthWearerCannotLie()) ++bad;
            if (!uarpTruthSpeaksLiteralTruth())
                ++bad;
            if (!uarpTruthDiscernsLastLie()) ++bad;
            if (!uarpTruthFalsettoVoice()) ++bad;
            if (!uarpTruthDweomerBlocksNotice())
                ++bad;
            if (!uarpTruthDweomerSilencesVoice())
                ++bad;
        // ---- the extract ledger ----
            if (uarpCleanCount() != 6) ++bad;
            if (uarpGarbledCount() != 7) ++bad;
            if (uarpTotalTypes() != 13) ++bad;
            if (uarpCleanCount() + uarpGarbledCount()
                    != uarpTotalTypes()) ++bad;
        // ---- the R377 scrolls seam ----
            if (uapsCleanCount() != 11) ++bad;
            if (uapsGarbledCount() != 4) ++bad;
        // ---- the R375 skeleton seam ----
            // the rings ride the
            // 36-40 band, split 01-67
            // new / 68-00 original
            if (uadsCategoryLo(2) != 36) ++bad;
            if (uadsCategoryHi(2) != 40) ++bad;
            if (uadsRingSplitLo() != 67) ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R378 UA new rings prose pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R378 audit')
s = rd(RT)
assert s.count(
    'R378 UA new rings prose pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 305, 'd census 305'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uaringprose.h"'
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
    'R378 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R378 note: the new rings',
    'prose round - six of the',
    'thirteen new-ring',
    'descriptions pin clean',
    '(animal friendship,',
    'anything, blinking,',
    'jumping, mind shielding,',
    'truth); seven',
    'descriptions',
    'OCR-scramble (boccob,',
    'chameleon, clumsiness,',
    'faerie, ram, shocking',
    'grasp, sustenance) - the',
    'item AMENDED, stays OPEN,',
    'PDF-gated; the R377 seam',
    'the scrolls ledger, the',
    'R375 seam the ring band;',
    'the census',
    '304 -> 305'
])
print(NOTE)
print('commit: R378: the UA new')
print('rings prose pin round')
print('(census 305)',)

