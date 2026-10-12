# R376: the UA new potions prose
# part 1 pin round (pp. 90-92):
# TWELVE of the nineteen new
# potion descriptions pin clean -
# the four elixirs (health, life,
# madness, youth), the potion of
# fire breath, the oils of fiery
# burning, fumbling, sharpness,
# timelessness, and the potions
# of rainbow hues, ventriloquism,
# vitality; SEVEN descriptions
# OCR-scramble (acid resistance,
# disenchantment, elemental,
# impact, the philters of beauty
# and glibness, stammering) - the
# gap item AMENDED, stays OPEN,
# PDF-gated; the R375 seam
# cross-checks the skeleton; the
# census 302 -> 303.
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



# ---- (a) the seed: the R375 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R375 landed 2026-10-12: commit',
    '  23efe0c, census 302, the UA',
    '  determination skeleton pin',
    '  round (rules/uadetskel.h): the',
    '  eight category bands and the',
    '  sub-table splits pin clean (the',
    '  misc magic carries SEVEN',
    '  sub-bands, not two), the scroll',
    '  footnotes pin (30 percent',
    '  clerical, 25 druidical, 10',
    '  illusionist, the DMG p. 121',
    '  cross-ref); the row bodies of',
    '  all eight tables OCR-scramble -',
    '  the all-read-clean claim',
    '  corrected, the item stays OPEN,',
    '  PDF-gated; the R374 dial seam',
    '  the modes; GREEN on the first',
    '  run.'
])
s = rd(SD)
if 'R375 landed 2026-10-12' in s:
    already.append('seed: the R375 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R375 record')
s = rd(SD)
assert s.count(
    'R375 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uapotprose.h ----
P = 'rules/uapotprose.h'
if os.path.exists(P) and 'R376' in rd(P):
    already.append('uapotprose.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uapotprose.h
// The UA TREASURE (POTIONS) prose
// pins, part 1, R376: the twelve
// clean new-potion descriptions
// (pp. 90-92) - the four elixirs,
// the potion of fire breath, the
// oils of fiery burning,
// fumbling, sharpness,
// timelessness, and the potions
// of rainbow hues,
// ventriloquism, vitality. The
// seven garbled descriptions
// (acid resistance,
// disenchantment, elemental,
// impact, the philters of
// beauty and glibness,
// stammering) await the PDF -
// the gap item stays open. The
// skeleton seam rides in the
// regtest audit, not here.
namespace rules {

// ---- the elixir of health ----
// Half a flask cures any one or
// two of the nine listed
// problems; the whole flask
// cures them all. It will not
// heal wounds or restore hit
// points lost through the
// listed causes.
inline int uappHealthCuresCount()
    { return 9; }

inline bool uappHealthHealsWounds()
    { return false; }

inline int uappHealthHalfFlaskCuresMax()
    { return 2; }

inline bool uappHealthWholeFlaskCuresAll()
    { return true; }

// ---- the elixir of life ----
// Restores life at a negative
// hit point level up to 20% of
// the total; administered
// within 5 rounds of death; one
// turn later the recipient sits
// unconscious at 1 hit point.
inline int uappLifeNegativeHpPct()
    { return 20; }

// A creature at -10 benefits
// only with a full-strength
// total of 50 or more.
inline int uappLifeMinus10NeedsFullHp()
    { return 50; }

inline int uappLifeWindowRounds()
    { return 5; }

inline int uappLifeAfterOneTurnHp()
    { return 1; }

// Each neutralized negative hit
// point costs a day of rest or
// a cure light wounds; the
// stronger spells buy more days.
inline int uappLifeRestDaysPerNegHp()
    { return 1; }

inline int uappLifeCureSeriousDays()
    { return 2; }

inline int uappLifeCureCriticalDays()
    { return 3; }

inline int uappLifeHealSpellDays()
    { return 7; }

inline bool uappLifeDemihumansAffected()
    { return true; }

// ---- the elixir of madness ----
inline const char* uappMadnessEquivalentSpell()
    { return "symbol of insanity"; }

inline int uappMadnessSipsToAffect()
    { return 1; }

// Once any creature is
// affected, the dweomer of the
// ENTIRE flask vanishes.
inline bool uappMadnessFlaskDweomerVanishes()
    { return true; }

// ---- the elixir of youth ----
inline int uappYouthFullDoseYearsLo()
    { return 2; }

inline int uappYouthFullDoseYearsHi()
    { return 5; }

inline int uappYouthLowPotencyYearsLo()
    { return 1; }

inline int uappYouthLowPotencyYearsHi()
    { return 3; }

// Sipping first reduces the
// potency of the whole flask.
inline bool uappYouthSippingReducesPotency()
    { return true; }

// ---- the potion of fire breath ----
// The dweomer holds up to six
// turns before belching; after
// expiry a 10% backfire erupts
// in the imbiber, double
// damage, NO save.
inline int uappFireBreathRetainTurns()
    { return 6; }

inline int uappFireBreathBackfirePct()
    { return 10; }

inline int uappFireBreathBackfireDmgMult()
    { return 2; }

inline bool uappFireBreathBackfireNoSave()
    { return true; }

inline int uappFireBreathDraughtsPerFlask()
    { return 4; }

inline int uappFireBreathSmallWidthIn()
    { return 1; }

inline int uappFireBreathSmallLenIn()
    { return 2; }

inline int uappFireBreathSmallDmgLo()
    { return 3; }

inline int uappFireBreathSmallDmgHi()
    { return 12; }

inline int uappFireBreathFullWidthIn()
    { return 2; }

inline int uappFireBreathFullLenIn()
    { return 8; }

inline int uappFireBreathFullDmgLo()
    { return 5; }

inline int uappFireBreathFullDmgHi()
    { return 50; }

// Save vs. breath weapon for
// half, in all cases.
inline bool uappFireBreathSaveForHalf()
    { return true; }

// ---- the oil of fiery burning ----
// 5d6 to the coated creature,
// save vs. spell for half; a
// hurled flask always breaks.
inline int uappFieryDmgDice()
    { return 5; }

inline int uappFieryDmgSides()
    { return 6; }

inline bool uappFierySaveForHalf()
    { return true; }

inline bool uappFieryHurlAlwaysBreaks()
    { return true; }

inline int uappFieryBlastRadiusIn()
    { return 1; }

inline int uappFieryMaxCreatures()
    { return 6; }

// Opening the flask: the holder
// takes 1-4 at once, and
// re-stoppering needs a roll of
// dexterity or less on 2d10.
inline int uappFieryOpenDmgLo()
    { return 1; }

inline int uappFieryOpenDmgHi()
    { return 4; }

inline int uappFieryRestopperDice()
    { return 2; }

inline int uappFieryRestopperSides()
    { return 10; }

// ---- the oil of fumbling ----
// Under melee stress: a 50%
// chance each round of
// fumbling; only a thorough
// solvent bath removes it early.
inline int uappFumblingPctPerRound()
    { return 50; }

inline bool uappFumblingSolventBathRemoves()
    { return true; }

// ---- the oil of sharpness ----
inline int uappSharpnessDurationLo()
    { return 8; }

inline int uappSharpnessDurationHi()
    { return 12; }

inline int uappSharpnessAppsLo()
    { return 3; }

inline int uappSharpnessAppsHi()
    { return 5; }

inline int uappSharpnessMaxBonus()
    { return 6; }

// The dweomer by die roll:
// 1-2 +1, 3-5 +2, 6-11 +3,
// 12-16 +4, 17-19 +5, 20 +6.
inline int uappSharpnessBonusForRoll(int r) {
    static const int k[20] = {
        1, 1, 2, 2, 2, 3, 3, 3, 3, 3,
        3, 4, 4, 4, 4, 4, 5, 5, 5, 6
    };
    if (r < 1) return 0;
    if (r > 20) return 0;
    return k[r - 1];
}

// ---- the oil of timelessness ----
// Each real year acts as a day
// on formerly-alive matter; the
// coating never wears off but
// can be magically removed.
inline int uappTimelessYearActsAsDays()
    { return 1; }

inline bool uappTimelessNeverWearsOff()
    { return true; }

inline int uappTimelessSaveBonus()
    { return 1; }

inline int uappTimelessHorsesPerFlask()
    { return 1; }

inline int uappTimelessHumansPerFlask()
    { return 8; }

// ---- the potion of rainbow hues ----
// Must be stored in a metallic
// container; a full flask holds
// seven hours of effect; the
// hue lands in under a segment.
inline bool uappRainbowMetallicContainer()
    { return true; }

inline int uappRainbowHoursPerFlask()
    { return 7; }

inline int uappRainbowSegmentMax()
    { return 1; }

inline int uappRainbowSparingDraughts()
    { return 7; }

inline int uappRainbowDraughtHours()
    { return 1; }

// ---- the potion of ventriloquism ----
inline int uappVentriloquismUses()
    { return 6; }

inline const char* uappVentriloquismAsClass()
    { return "magic-user"; }

inline bool uappVentriloquismFadesOnTime()
    { return true; }

// ---- the potion of vitality ----
// Seven days of exertion-proof
// vigor; proof against poisons
// and diseases the while; lost
// hit points return at 1 per 4
// hours.
inline int uappVitalityMaxDays()
    { return 7; }

inline bool uappVitalityPoisonDiseaseProof()
    { return true; }

inline int uappVitalityHpPerRecovery()
    { return 1; }

inline int uappVitalityRecoveryHours()
    { return 4; }

// Taken after deprivation, it
// nullifies the adverse effects
// and rides the remaining days.
inline bool uappVitalityRidesRemaining()
    { return true; }

// ---- the part ledger ----
// Twelve of the nineteen
// descriptions pin; the seven
// garbled ones stay PDF-gated.
inline int uappPartCleanCount()
    { return 12; }

inline int uappPartGarbledCount()
    { return 7; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uapotprose.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 73, 'b inline count'
assert s.count('R376') == 1, 'b round tag'
assert s.count(
    'uappHealthCuresCount'
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
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R376' in s:
    already.append('gap: the amendment')
else:
    OLD = '- [ ] **The new potions** (p. 90).'
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [ ] **The new potions** (p. 90).',
        '      - AMENDED R376: the new',
        '        potions prose part 1 pin',
        '        round (rules/uapotprose.h)',
        '        - TWELVE of the nineteen',
        '        descriptions pin clean',
        '        (the four elixirs of',
        '        health, life, madness,',
        '        youth; the potion of',
        '        fire breath; the oils of',
        '        fiery burning,',
        '        fumbling, sharpness,',
        '        timelessness; the',
        '        potions of rainbow',
        '        hues, ventriloquism,',
        '        vitality); SEVEN',
        '        descriptions',
        '        OCR-scramble (acid',
        '        resistance,',
        '        disenchantment,',
        '        elemental, impact,',
        '        the philters of beauty',
        '        and glibness,',
        '        stammering) - the item',
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
    '- [ ] **The new potions**'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R376'
) == 1, 'c amendment'
assert s.count(
    'AMENDED R375'
) == 1, 'c r375 amendment kept'
assert s.count(
    '(rules/uapotprose.h)'
) == 1, 'c potions note'
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
if 'R376 UA new potions prose part 1 pin audit' in s:
    already.append('regtest.cpp: the R376 audit')
else:
    INC_ANCH = ('#include "rules/uadetskel.h"  // '
        'R375: the UA determination skeleton')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uapotprose.h"  // R376: the UA new potions prose'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R376: the UA new potions
    // prose part 1 pin audit ----
    // The twelve clean
    // descriptions (pp. 90-92):
    // the four elixirs, fire
    // breath, the oils of fiery
    // burning, fumbling,
    // sharpness, timelessness,
    // rainbow hues,
    // ventriloquism, vitality. The
    // seven garbled descriptions
    // stay PDF-gated. The R375
    // seam cross-checks the
    // skeleton; the census
    // 302 -> 303.
    {
        using namespace rules;
        int bad = 0;
        // ---- the elixir of health ----
            if (uappHealthCuresCount() != 9)
                ++bad;
            if (uappHealthHealsWounds()) ++bad;
            if (uappHealthHalfFlaskCuresMax() != 2)
                ++bad;
            if (!uappHealthWholeFlaskCuresAll())
                ++bad;
        // ---- the elixir of life ----
            if (uappLifeNegativeHpPct() != 20)
                ++bad;
            if (uappLifeMinus10NeedsFullHp() != 50)
                ++bad;
            if (uappLifeWindowRounds() != 5) ++bad;
            if (uappLifeAfterOneTurnHp() != 1) ++bad;
            if (uappLifeRestDaysPerNegHp() != 1)
                ++bad;
            if (uappLifeCureSeriousDays() != 2)
                ++bad;
            if (uappLifeCureCriticalDays() != 3)
                ++bad;
            if (uappLifeHealSpellDays() != 7) ++bad;
            if (!uappLifeDemihumansAffected())
                ++bad;
        // ---- the elixir of madness ----
            if (strcmp(uappMadnessEquivalentSpell(),
                    "symbol of insanity") != 0)
                ++bad;
            if (uappMadnessSipsToAffect() != 1)
                ++bad;
            if (!uappMadnessFlaskDweomerVanishes())
                ++bad;
        // ---- the elixir of youth ----
            if (uappYouthFullDoseYearsLo() != 2)
                ++bad;
            if (uappYouthFullDoseYearsHi() != 5)
                ++bad;
            if (uappYouthLowPotencyYearsLo() != 1)
                ++bad;
            if (uappYouthLowPotencyYearsHi() != 3)
                ++bad;
            if (!uappYouthSippingReducesPotency())
                ++bad;
        // ---- the potion of fire breath ----
            if (uappFireBreathRetainTurns() != 6)
                ++bad;
            if (uappFireBreathBackfirePct() != 10)
                ++bad;
            if (uappFireBreathBackfireDmgMult() != 2)
                ++bad;
            if (!uappFireBreathBackfireNoSave())
                ++bad;
            if (uappFireBreathDraughtsPerFlask() != 4)
                ++bad;
            if (uappFireBreathSmallWidthIn() != 1)
                ++bad;
            if (uappFireBreathSmallLenIn() != 2)
                ++bad;
            if (uappFireBreathSmallDmgLo() != 3)
                ++bad;
            if (uappFireBreathSmallDmgHi() != 12)
                ++bad;
            if (uappFireBreathFullWidthIn() != 2)
                ++bad;
            if (uappFireBreathFullLenIn() != 8)
                ++bad;
            if (uappFireBreathFullDmgLo() != 5)
                ++bad;
            if (uappFireBreathFullDmgHi() != 50)
                ++bad;
            if (!uappFireBreathSaveForHalf())
                ++bad;
        // ---- the oil of fiery burning ----
            if (uappFieryDmgDice() != 5) ++bad;
            if (uappFieryDmgSides() != 6) ++bad;
            if (!uappFierySaveForHalf()) ++bad;
            if (!uappFieryHurlAlwaysBreaks()) ++bad;
            if (uappFieryBlastRadiusIn() != 1)
                ++bad;
            if (uappFieryMaxCreatures() != 6) ++bad;
            if (uappFieryOpenDmgLo() != 1) ++bad;
            if (uappFieryOpenDmgHi() != 4) ++bad;
            if (uappFieryRestopperDice() != 2) ++bad;
            if (uappFieryRestopperSides() != 10)
                ++bad;
        // ---- the oil of fumbling ----
            if (uappFumblingPctPerRound() != 50)
                ++bad;
            if (!uappFumblingSolventBathRemoves())
                ++bad;
        // ---- the oil of sharpness ----
            static const int kBonus[20] = {
                1, 1, 2, 2, 2, 3, 3, 3, 3, 3,
                3, 4, 4, 4, 4, 4, 5, 5, 5, 6};
            if (uappSharpnessDurationLo() != 8)
                ++bad;
            if (uappSharpnessDurationHi() != 12)
                ++bad;
            if (uappSharpnessAppsLo() != 3) ++bad;
            if (uappSharpnessAppsHi() != 5) ++bad;
            if (uappSharpnessMaxBonus() != 6) ++bad;
            for (int i = 0; i < 20; ++i) {
                if (uappSharpnessBonusForRoll(i + 1)
                        != kBonus[i]) ++bad;
            }
            if (uappSharpnessBonusForRoll(0) != 0)
                ++bad;
            if (uappSharpnessBonusForRoll(21) != 0)
                ++bad;
        // ---- the oil of timelessness ----
            if (uappTimelessYearActsAsDays() != 1)
                ++bad;
            if (!uappTimelessNeverWearsOff()) ++bad;
            if (uappTimelessSaveBonus() != 1) ++bad;
            if (uappTimelessHorsesPerFlask() != 1)
                ++bad;
            if (uappTimelessHumansPerFlask() != 8)
                ++bad;
        // ---- rainbow hues ----
            if (!uappRainbowMetallicContainer())
                ++bad;
            if (uappRainbowHoursPerFlask() != 7)
                ++bad;
            if (uappRainbowSegmentMax() != 1)
                ++bad;
            if (uappRainbowSparingDraughts() != 7)
                ++bad;
            if (uappRainbowDraughtHours() != 1)
                ++bad;
        // ---- ventriloquism ----
            if (uappVentriloquismUses() != 6) ++bad;
            if (strcmp(uappVentriloquismAsClass(),
                    "magic-user") != 0)
                ++bad;
            if (!uappVentriloquismFadesOnTime())
                ++bad;
        // ---- vitality ----
            if (uappVitalityMaxDays() != 7) ++bad;
            if (!uappVitalityPoisonDiseaseProof())
                ++bad;
            if (uappVitalityHpPerRecovery() != 1)
                ++bad;
            if (uappVitalityRecoveryHours() != 4)
                ++bad;
            if (!uappVitalityRidesRemaining())
                ++bad;
        // ---- the part ledger ----
            if (uappPartCleanCount() != 12) ++bad;
            if (uappPartGarbledCount() != 7) ++bad;
        // ---- the R375 skeleton seam ----
            // the twelve ride the
            // potions low band of the
            // revised table
            if (uadsCategoryCount() != 8) ++bad;
            if (uadsPotionSplitLo() != 65) ++bad;
            if (!uadsPotionLowBandIsNewPotions())
                ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R376 UA new potions prose part 1 pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R376 audit')
s = rd(RT)
assert s.count(
    'R376 UA new potions prose part 1 pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 303, 'd census 303'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uapotprose.h"'
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
    'R376 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R376 note: the new potions',
    'prose part 1 round - twelve',
    'of the nineteen new-potion',
    'descriptions pin clean (the',
    'four elixirs, fire breath,',
    'the oils of fiery burning,',
    'fumbling, sharpness,',
    'timelessness, rainbow hues,',
    'ventriloquism, vitality);',
    'seven descriptions',
    'OCR-scramble (acid',
    'resistance, disenchantment,',
    'elemental, impact, the two',
    'philters, stammering) - the',
    'item AMENDED, stays OPEN,',
    'PDF-gated; the R375 seam the',
    'skeleton; the census',
    '302 -> 303'
])
print(NOTE)
print('commit: R376: the UA')
print('new potions prose part 1')
print('pin round (census 303)',)

