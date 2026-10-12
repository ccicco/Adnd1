# R377: the UA new scrolls
# protection prose pin round
# (pp. 91-93): ELEVEN of the
# fifteen new protection-scroll
# types pin clean - acid, breath
# weapons (dragon and
# non-dragon), fire, gas,
# illusions, paralyzation,
# plants, poison, the traps trio
# (50 percent mechanical, 30
# magical, 20 any), water; FOUR
# types OCR-scramble (cold,
# electricity, the two weapons
# scrolls) - the gap item
# AMENDED, stays OPEN,
# PDF-gated; the R376 seam
# cross-checks the potions
# ledger, the R375 seam the
# scroll splits; the census
# 303 -> 304.
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



# ---- (a) the seed: the R376 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R376 landed 2026-10-12: commit',
    '  be2766f, census 303, the UA',
    '  new potions prose part 1',
    '  round (rules/uapotprose.h):',
    '  twelve of the nineteen',
    '  new-potion descriptions pin',
    '  clean (the four elixirs,',
    '  fire breath, the oils of',
    '  fiery burning, fumbling,',
    '  sharpness, timelessness,',
    '  rainbow hues,',
    '  ventriloquism, vitality);',
    '  seven descriptions',
    '  OCR-scramble - the item',
    '  AMENDED, stays OPEN,',
    '  PDF-gated; the R375 seam',
    '  the skeleton; GREEN on the',
    '  first run.'
])
s = rd(SD)
if 'R376 landed 2026-10-12' in s:
    already.append('seed: the R376 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R376 record')
s = rd(SD)
assert s.count(
    'R376 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uaprotscr.h ----
P = 'rules/uaprotscr.h'
if os.path.exists(P) and 'R377' in rd(P):
    already.append('uaprotscr.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaprotscr.h
// The UA TREASURE (SCROLLS)
// protection prose pins, R377:
// the eleven clean
// protection-scroll types
// (pp. 91-93) - acid, breath
// weapons (dragon and
// non-dragon), fire, gas,
// illusions, paralyzation,
// plants, poison, the traps
// trio (50 mechanical, 30
// magical, 20 any), water. The
// four garbled types (cold,
// electricity, the two weapons
// scrolls) await the PDF - the
// gap item stays open. The
// potions and skeleton seams
// ride in the regtest audit,
// not here.
namespace rules {

// ---- the acid scroll ----
// Reading 5 segments; the
// damage limit 20 hit dice or
// the time limit 9-12 turns
// (d4 + 8), whichever comes
// first - three 6-HD black
// dragon breaths ride inside
// the limit.
inline int uapsAcidReadingSegs()
    { return 5; }

inline int uapsAcidDamageLimitHd()
    { return 20; }

inline int uapsAcidDurationLoTurns()
    { return 9; }

inline int uapsAcidDurationHiTurns()
    { return 12; }

inline int uapsAcidExampleBreaths()
    { return 3; }

inline int uapsAcidExampleHdPerBreath()
    { return 6; }

// ---- the breath weapon
// scrolls ----
// Dragon: reading 1 round, the
// individual only, all forms of
// dragon breath, 6-12 rounds
// (2d4 + 4).
inline int uapsBwDragonReadingRounds()
    { return 1; }

inline int uapsBwDragonDurationLoRounds()
    { return 6; }

inline int uapsBwDragonDurationHiRounds()
    { return 12; }

inline bool uapsBwDragonIndividualOnly()
    { return true; }

// Non-dragon: reading 1
// segment, the individual only,
// 5-8 rounds (d4 + 4).
inline int uapsBwNonDragonReadingSegs()
    { return 1; }

inline int uapsBwNonDragonDurationLoRounds()
    { return 5; }

inline int uapsBwNonDragonDurationHiRounds()
    { return 8; }

inline bool uapsBwNonDragonIndividualOnly()
    { return true; }

// ---- the fire scroll ----
// Reading 8 segments; a 3"
// sphere; flame and heat of
// the hottest sort, even
// magical or elemental; 5-8
// turns (d4 + 4).
inline int uapsFireReadingSegs()
    { return 8; }

inline int uapsFireSphereDiamIn()
    { return 3; }

inline int uapsFireDurationLoTurns()
    { return 5; }

inline int uapsFireDurationHiTurns()
    { return 8; }

// ---- the gas scroll ----
// Reading 3 segments; a 1"
// sphere; immune to any form
// of gas; 5-8 rounds
// (d4 + 4).
inline int uapsGasReadingSegs()
    { return 3; }

inline int uapsGasSphereDiamIn()
    { return 1; }

inline int uapsGasDurationLoRounds()
    { return 5; }

inline int uapsGasDurationHiRounds()
    { return 8; }

// ---- the illusions scroll ----
// Reading 7 segments; the
// individual only; any
// illusion/phantasm magic
// witnessed; 5-30 rounds
// (5d6).
inline int uapsIllusionsReadingSegs()
    { return 7; }

inline int uapsIllusionsDurationLoRounds()
    { return 5; }

inline int uapsIllusionsDurationHiRounds()
    { return 30; }

inline bool uapsIllusionsIndividualOnly()
    { return true; }

// ---- the paralyzation scroll
// ----
// Reading 1 round; the reader
// only; all forms of
// paralyzation, a hold spell
// will not work, nor gas
// paralysis; 2-5 turns
// (d4 + 1).
inline int uapsParalReadingRounds()
    { return 1; }

inline int uapsParalDurationLoTurns()
    { return 2; }

inline int uapsParalDurationHiTurns()
    { return 5; }

inline bool uapsParalBlocksHold()
    { return true; }

inline bool uapsParalBlocksGas()
    { return true; }

inline bool uapsParalReaderOnly()
    { return true; }

// ---- the plants scroll ----
// Reading 1 round; a 1"
// sphere; vegetable life,
// fungi, slimes, molds cannot
// penetrate; 5-8 turns
// (d4 + 4).
inline int uapsPlantsReadingRounds()
    { return 1; }

inline int uapsPlantsSphereDiamIn()
    { return 1; }

inline int uapsPlantsDurationLoTurns()
    { return 5; }

inline int uapsPlantsDurationHiTurns()
    { return 8; }

// ---- the poison scroll ----
// Reading 3 segments; the
// reader only; no form of
// poison affects, and any
// poison in the system is
// permanently neutralized;
// 3-12 rounds (d10 + 2).
inline int uapsPoisonReadingSegs()
    { return 3; }

inline int uapsPoisonDurationLoRounds()
    { return 3; }

inline int uapsPoisonDurationHiRounds()
    { return 12; }

inline bool uapsPoisonReaderOnly()
    { return true; }

inline bool uapsPoisonNeutralizesInSystem()
    { return true; }

// ---- the traps scrolls ----
// Three forms: mechanical
// 50%, magical 30%, any form
// 20%. None reveal the traps
// they defeat.
inline int uapsTrapMechanicalPct()
    { return 50; }

inline int uapsTrapMagicalPct()
    { return 30; }

inline int uapsTrapAnyPct()
    { return 20; }

// Mechanical: reading 4
// segments; the reader only;
// 5-20 rounds (5d4).
inline int uapsTrapMechReadingSegs()
    { return 4; }

inline int uapsTrapMechDurationLoRounds()
    { return 5; }

inline int uapsTrapMechDurationHiRounds()
    { return 20; }

inline bool uapsTrapMechReaderOnly()
    { return true; }

inline bool uapsTrapMechNotRevealed()
    { return true; }

// Magical: reading 8
// segments; a 1" sphere;
// 3-12 rounds (d10 + 2).
inline int uapsTrapMagReadingSegs()
    { return 8; }

inline int uapsTrapMagSphereDiamIn()
    { return 1; }

inline int uapsTrapMagDurationLoRounds()
    { return 3; }

inline int uapsTrapMagDurationHiRounds()
    { return 12; }

inline bool uapsTrapMagNotRevealed()
    { return true; }

// Any trap: reading 1 round;
// a 1" sphere; 2-8 rounds
// (2d4).
inline int uapsTrapAnyReadingRounds()
    { return 1; }

inline int uapsTrapAnySphereDiamIn()
    { return 1; }

inline int uapsTrapAnyDurationLoRounds()
    { return 2; }

inline int uapsTrapAnyDurationHiRounds()
    { return 8; }

inline bool uapsTrapAnyNotRevealed()
    { return true; }

// ---- the water scroll ----
// Reading 6 segments; a 1"
// sphere; liquid, solid, and
// vapor water cannot touch
// the protected; 5-8 turns
// (d4 + 4).
inline int uapsWaterReadingSegs()
    { return 6; }

inline int uapsWaterSphereDiamIn()
    { return 1; }

inline int uapsWaterDurationLoTurns()
    { return 5; }

inline int uapsWaterDurationHiTurns()
    { return 8; }

// ---- the extract ledger ----
// Eleven of the fifteen types
// pin clean; the four garbled
// types (cold, electricity,
// the two weapons scrolls)
// stay PDF-gated.
inline int uapsCleanCount()
    { return 11; }

inline int uapsGarbledCount()
    { return 4; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uaprotscr.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 65, 'b inline count'
assert s.count('R377') == 1, 'b round tag'
assert s.count(
    'uapsAcidReadingSegs'
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
assert 'uasc' not in s, 'b no uasc ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R377' in s:
    already.append('gap: the amendment')
else:
    OLD = '- [ ] **The new scrolls** (pp. 91-93).'
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [ ] **The new scrolls** (pp. 91-93).',
        '      - AMENDED R377: the new',
        '        scrolls protection prose',
        '        pin round',
        '        (rules/uaprotscr.h) -',
        '        ELEVEN of the fifteen',
        '        protection-scroll types',
        '        pin clean (acid, breath',
        '        weapons dragon and',
        '        non-dragon, fire, gas,',
        '        illusions,',
        '        paralyzation, plants,',
        '        poison, the traps trio',
        '        at 50 percent mechanical',
        '        / 30 magical / 20 any,',
        '        water); FOUR types',
        '        OCR-scramble (cold,',
        '        electricity, the two',
        '        weapons scrolls) - the',
        '        item stays OPEN,',
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
    '- [ ] **The new scrolls**'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R377'
) == 1, 'c amendment'
assert s.count(
    'AMENDED R376'
) == 1, 'c r376 amendment kept'
assert s.count(
    'AMENDED R375'
) == 1, 'c r375 amendment kept'
assert s.count(
    '(rules/uaprotscr.h)'
) == 1, 'c scrolls note'
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
    '- [ ] **The new rings**'
) == 1, 'c rings kept open'
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
if 'R377 UA new scrolls protection pin audit' in s:
    already.append('regtest.cpp: the R377 audit')
else:
    INC_ANCH = ('#include "rules/uapotprose.h"  // '
        'R376: the UA new potions prose')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaprotscr.h"  // R377: the UA new scrolls prose'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R377: the UA new scrolls
    // protection prose pin audit ----
    // The eleven clean
    // protection-scroll types
    // (pp. 91-93): acid, breath
    // weapons (dragon and
    // non-dragon), fire, gas,
    // illusions,
    // paralyzation, plants,
    // poison, the traps trio
    // (50 mechanical, 30
    // magical, 20 any), water.
    // The four garbled types
    // (cold, electricity, the
    // two weapons scrolls) stay
    // PDF-gated. The R376 seam
    // cross-checks the potions
    // ledger, the R375 seam the
    // scroll splits; the census
    // 303 -> 304.
    {
        using namespace rules;
        int bad = 0;
        // ---- the acid scroll ----
            if (uapsAcidReadingSegs() != 5)
                ++bad;
            if (uapsAcidDamageLimitHd() != 20)
                ++bad;
            if (uapsAcidDurationLoTurns() != 9)
                ++bad;
            if (uapsAcidDurationHiTurns() != 12)
                ++bad;
            if (uapsAcidExampleBreaths() != 3)
                ++bad;
            if (uapsAcidExampleHdPerBreath() != 6)
                ++bad;
            if (uapsAcidDurationLoTurns()
                    + uapsAcidDurationHiTurns()
                    != 21) ++bad;
        // ---- the breath weapon scrolls ----
            if (uapsBwDragonReadingRounds() != 1)
                ++bad;
            if (uapsBwDragonDurationLoRounds() != 6)
                ++bad;
            if (uapsBwDragonDurationHiRounds() != 12)
                ++bad;
            if (!uapsBwDragonIndividualOnly())
                ++bad;
            if (uapsBwNonDragonReadingSegs() != 1)
                ++bad;
            if (uapsBwNonDragonDurationLoRounds() != 5)
                ++bad;
            if (uapsBwNonDragonDurationHiRounds() != 8)
                ++bad;
            if (!uapsBwNonDragonIndividualOnly())
                ++bad;
        // ---- the fire scroll ----
            if (uapsFireReadingSegs() != 8)
                ++bad;
            if (uapsFireSphereDiamIn() != 3)
                ++bad;
            if (uapsFireDurationLoTurns() != 5)
                ++bad;
            if (uapsFireDurationHiTurns() != 8)
                ++bad;
        // ---- the gas scroll ----
            if (uapsGasReadingSegs() != 3) ++bad;
            if (uapsGasSphereDiamIn() != 1) ++bad;
            if (uapsGasDurationLoRounds() != 5)
                ++bad;
            if (uapsGasDurationHiRounds() != 8)
                ++bad;
        // ---- the illusions scroll ----
            if (uapsIllusionsReadingSegs() != 7)
                ++bad;
            if (uapsIllusionsDurationLoRounds() != 5)
                ++bad;
            if (uapsIllusionsDurationHiRounds() != 30)
                ++bad;
            if (!uapsIllusionsIndividualOnly())
                ++bad;
        // ---- the paralyzation scroll ----
            if (uapsParalReadingRounds() != 1)
                ++bad;
            if (uapsParalDurationLoTurns() != 2)
                ++bad;
            if (uapsParalDurationHiTurns() != 5)
                ++bad;
            if (!uapsParalBlocksHold()) ++bad;
            if (!uapsParalBlocksGas()) ++bad;
            if (!uapsParalReaderOnly()) ++bad;
        // ---- the plants scroll ----
            if (uapsPlantsReadingRounds() != 1)
                ++bad;
            if (uapsPlantsSphereDiamIn() != 1)
                ++bad;
            if (uapsPlantsDurationLoTurns() != 5)
                ++bad;
            if (uapsPlantsDurationHiTurns() != 8)
                ++bad;
        // ---- the poison scroll ----
            if (uapsPoisonReadingSegs() != 3)
                ++bad;
            if (uapsPoisonDurationLoRounds() != 3)
                ++bad;
            if (uapsPoisonDurationHiRounds() != 12)
                ++bad;
            if (!uapsPoisonReaderOnly()) ++bad;
            if (!uapsPoisonNeutralizesInSystem())
                ++bad;
        // ---- the traps scrolls ----
            static const int kTrap[3] = {
                50, 30, 20};
            if (uapsTrapMechanicalPct() != kTrap[0])
                ++bad;
            if (uapsTrapMagicalPct() != kTrap[1])
                ++bad;
            if (uapsTrapAnyPct() != kTrap[2]) ++bad;
            if (kTrap[0] + kTrap[1] + kTrap[2]
                    != 100) ++bad;
            if (uapsTrapMechReadingSegs() != 4)
                ++bad;
            if (uapsTrapMechDurationLoRounds() != 5)
                ++bad;
            if (uapsTrapMechDurationHiRounds() != 20)
                ++bad;
            if (!uapsTrapMechReaderOnly()) ++bad;
            if (!uapsTrapMechNotRevealed()) ++bad;
            if (uapsTrapMagReadingSegs() != 8)
                ++bad;
            if (uapsTrapMagSphereDiamIn() != 1)
                ++bad;
            if (uapsTrapMagDurationLoRounds() != 3)
                ++bad;
            if (uapsTrapMagDurationHiRounds() != 12)
                ++bad;
            if (!uapsTrapMagNotRevealed()) ++bad;
            if (uapsTrapAnyReadingRounds() != 1)
                ++bad;
            if (uapsTrapAnySphereDiamIn() != 1)
                ++bad;
            if (uapsTrapAnyDurationLoRounds() != 2)
                ++bad;
            if (uapsTrapAnyDurationHiRounds() != 8)
                ++bad;
            if (!uapsTrapAnyNotRevealed()) ++bad;
        // ---- the water scroll ----
            if (uapsWaterReadingSegs() != 6)
                ++bad;
            if (uapsWaterSphereDiamIn() != 1)
                ++bad;
            if (uapsWaterDurationLoTurns() != 5)
                ++bad;
            if (uapsWaterDurationHiTurns() != 8)
                ++bad;
        // ---- the extract ledger ----
            if (uapsCleanCount() != 11) ++bad;
            if (uapsGarbledCount() != 4) ++bad;
            if (uapsCleanCount() + uapsGarbledCount()
                    != 15) ++bad;
        // ---- the R376 potions seam ----
            if (uappPartCleanCount() != 12) ++bad;
            if (uappPartGarbledCount() != 7) ++bad;
        // ---- the R375 skeleton seam ----
            // the protection scrolls
            // ride the scrolls band and
            // its II.B.2 second table
            if (uadsScrollSplitLo() != 85) ++bad;
            if (!uadsScrollSecondTableIsIIB2())
                ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R377 UA new scrolls protection pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R377 audit')
s = rd(RT)
assert s.count(
    'R377 UA new scrolls protection pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 304, 'd census 304'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uaprotscr.h"'
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
    'R377 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R377 note: the new scrolls',
    'protection prose round -',
    'eleven of the fifteen',
    'protection-scroll types',
    'pin clean (acid, breath',
    'weapons dragon and',
    'non-dragon, fire, gas,',
    'illusions, paralyzation,',
    'plants, poison, the',
    'traps trio at 50/30/20,',
    'water); four types',
    'OCR-scramble (cold,',
    'electricity, the two',
    'weapons scrolls) - the',
    'item AMENDED, stays OPEN,',
    'PDF-gated; the R376 seam',
    'the potions ledger, the',
    'R375 seam the scroll',
    'splits; the census',
    '303 -> 304'
])
print(NOTE)
print('commit: R377: the UA new')
print('scrolls protection prose')
print('pin round (census 304)',)

