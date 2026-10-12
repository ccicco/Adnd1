
# R371: the UA expanded armor pin
# round (pp. 75-76): the armor and
# encumbrance table rows and the four
# new armor descriptions - bronze
# plate (AC 4, the +2 rear exposure,
# the rust immunity), elfin chain
# (thief-wearable, never sold), field
# plate (the absorption, the cap, the
# repairs), full plate; the R191 seam
# cross-checks the plate AC ladder, the
# R334 seam the thief elfin rows, the
# R370 seam the barding weight read;
# two items flip CLOSED; the census
# 297 -> 298.
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



# ---- (a) the seed: the R370 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R370 landed 2026-10-12: commit',
    '  4571cf3, census 297, the UA',
    '  DM-section smalls part 1 pin',
    '  round (rules/uasmalls1.h):',
    '  Method V (the class-first prose',
    '  clean, the dice table cells a',
    '  flagged hole), the 12 starting',
    '  hit-point minimums with the',
    '  multi-class and con examples,',
    '  the barding movement table (two',
    '  lost cells flagged), the',
    '  endurance, magical-barding and',
    '  steeds rules; three items',
    '  CLOSED; the R368 seam',
    '  cross-checks the cavalier d10',
    '  floor; GREEN on the first run.'
])
s = rd(SD)
if 'R370 landed 2026-10-12' in s:
    already.append('seed: the R370 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R370 record')
s = rd(SD)
assert s.count(
    'R370 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uaarmor.h ----
P = 'rules/uaarmor.h'
if os.path.exists(P) and 'R371' in rd(P):
    already.append('uaarmor.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaarmor.h
// The UA EXPANDED ARMOR (pp. 75-76)
// pins, R371: the armor and
// encumbrance table rows (the
// costs, the weights, the base
// movement, the bulk column, the
// shield rows) and the four new
// armor descriptions - bronze
// plate (the AC 4 with the +2
// rear-attack exposure and the
// rust immunity), elfin chain
// (the thief-wearable read), field
// plate (the 1 point per die
// absorption, the 12 point cap,
// the repair costs), full plate.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. Cross-checks the landed R191 seam
// (rules/armorratings.h - the plate mail AC 3 the
// bronze plate reads one worse than), the R334 seam
// (rules/thiefarmor.h - the elfin chain rows) and the
// R370 seam (the elfin-chain barding weight read).
//
// JUDGMENTs (the decode method):
//   - the table rows print clean for banded, bronze
//     plate, field plate, full plate, ring, scale,
//     splint and studded leather; the elfin chain
//     cost cell garbles - which confirms the clean
//     footnote (never on the open market) rather
//     than contradicting it; some weight cells carry
//     the OCR crosshatch - the weights pinned where
//     clean, flagged where not.
//   - the four descriptions print clean throughout.

namespace rules {

// ---- the expanded armor table (p. 75) ----
// Banded: bulky, 35 pounds, 9 inches, 90 gp.
inline int uaarmBandedWeight()
    { return 35; }

inline int uaarmBandedMove()
    { return 9; }

inline int uaarmBandedCost()
    { return 90; }

inline bool uaarmBandedBulky()
    { return true; }

// Bronze plate: bulky, 45 pounds, 6 inches, 100 gp.
inline int uaarmBronzePlateWeight()
    { return 45; }

inline int uaarmBronzePlateMove()
    { return 6; }

inline int uaarmBronzePlateCost()
    { return 100; }

inline bool uaarmBronzePlateBulky()
    { return true; }

// Field plate: fairly bulky, 55 pounds, 6 inches,
// 2000 gp.
inline int uaarmFieldPlateWeight()
    { return 55; }

inline int uaarmFieldPlateMove()
    { return 6; }

inline int uaarmFieldPlateCost()
    { return 2000; }

inline bool uaarmFieldPlateFairlyBulky()
    { return true; }

// Full plate: fairly bulky, 65 pounds, 6 inches,
// 4000 gp.
inline int uaarmFullPlateWeight()
    { return 65; }

inline int uaarmFullPlateMove()
    { return 6; }

inline int uaarmFullPlateCost()
    { return 4000; }

inline bool uaarmFullPlateFairlyBulky()
    { return true; }

// Ring mail: fairly bulky, 25 pounds, 9 inches,
// 30 gp.
inline int uaarmRingMailWeight()
    { return 25; }

inline int uaarmRingMailMove()
    { return 9; }

inline int uaarmRingMailCost()
    { return 30; }

// Scale mail: fairly bulky, 40 pounds, 6 inches,
// 45 gp.
inline int uaarmScaleMailWeight()
    { return 40; }

inline int uaarmScaleMailMove()
    { return 6; }

inline int uaarmScaleMailCost()
    { return 45; }

// Splint mail: fairly bulky, 40 pounds, 6 inches,
// 80 gp.
inline int uaarmSplintMailWeight()
    { return 40; }

inline int uaarmSplintMailMove()
    { return 6; }

inline int uaarmSplintMailCost()
    { return 80; }

// Studded leather: fairly bulky, 20 pounds,
// 9 inches, 15 gp.
inline int uaarmStuddedLeatherWeight()
    { return 20; }

inline int uaarmStuddedLeatherMove()
    { return 9; }

inline int uaarmStuddedLeatherCost()
    { return 15; }

// ---- the elfin chain footnote ----
// The clean footnote: never available on the
// open market (the cost cell garbles, which
// confirms the read).
inline bool uaarmElfinNeverOnOpenMarket()
    { return true; }

// ---- the shield rows ----
inline int uaarmShieldBucklerWeight()
    { return 3; }

inline int uaarmShieldBucklerCost()
    { return 5; }

inline int uaarmShieldLargeWeight()
    { return 10; }

inline int uaarmShieldLargeCost()
    { return 15; }

inline int uaarmShieldSmallWeight()
    { return 5; }

inline int uaarmShieldSmallCost()
    { return 10; }

// ---- the bronze plate description ----
// AC 4 (the regular plate mail AC 3), the
// rear attacks at +2, the rust-monster
// immunity.
inline int uaarmBronzeAc()
    { return 4; }

inline int uaarmBronzeRearAttackBonus()
    { return 2; }

inline bool uaarmBronzeRustImmune()
    { return true; }

inline bool uaarmBronzeEarlierCheaperVersion()
    { return true; }

// ---- the elfin chain description ----
inline bool uaarmElfinElvenMade()
    { return true; }

inline bool uaarmElfinExtremelyRare()
    { return true; }

inline bool uaarmElfinThiefWearable()
    { return true; }

inline bool uaarmElfinSomewhatImpairsThiefAbilities()
    { return true; }

// ---- the field plate description ----
// Absorbs 1 point per die of damage (a die
// roll of 1 takes no damage); after 12
// absorbed points the armor is damaged.
inline int uaarmFieldPlateAbsorbPerDie()
    { return 1; }

inline int uaarmFieldPlateAbsorbCap()
    { return 12; }

inline int uaarmFieldPlateRepairCostPerPoint()
    { return 100; }

inline int uaarmFieldPlateRepairDaysPerPoint()
    { return 1; }

inline bool uaarmFieldPlateFittedToWearer()
    { return true; }

inline bool uaarmFieldPlateBulkyAsChain()
    { return true; }

// ---- the full plate description ----
inline bool uaarmFullPlateInterlockedBackedWithChain()
    { return true; }

inline bool uaarmFullPlateBulkyAsChain()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uaarmor.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 51, 'b inline count'
assert s.count('R371') == 1, 'b round tag'
assert s.count(
    'uaarmFieldPlateAbsorbPerDie'
    ) >= 1, 'b fn'
assert 'uacaq' not in s, 'b no uacaq ref'
assert 'uaila' not in s, 'b no uaila ref'
assert 'uabk' not in s, 'b no uabk ref'
assert 'uailc' not in s, 'b no uailc ref'
assert 'uasoc' not in s, 'b no uasoc ref'
assert 'uabirth' not in s, 'b no uabirth ref'
assert 'uasp' not in s, 'b no uasp ref'
assert 'uasm1' not in s, 'b no uasm1 ref'
assert 'armorRating' not in s, 'b no armorRating ref'
assert 'thiefArmor' not in s, 'b no thiefArmor ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the two closes ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **The expanded armor table**' in s:
    already.append('gap: the table close')
else:
    OLD = NL.join([
        '- [ ] **The expanded armor table** (p.',
        '      75) - reads clean: banded 90 gp,',
        '      bronze plate 100 gp, field plate',
        '      2000 gp, full plate 4000 gp, the',
        '      bulk and movement columns, the',
        '      shield rows, elfin chain never',
        '      sold.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [x] **The expanded armor table** (p.',
        '      75) - reads clean: banded 90 gp,',
        '      bronze plate 100 gp, field plate',
        '      2000 gp, full plate 4000 gp, the',
        '      bulk and movement columns, the',
        '      shield rows, elfin chain never',
        '      sold.',
        '      - CLOSED R371: the pin round',
        '        (rules/uaarmor.h) - the',
        '        banded, bronze plate, field',
        '        plate, full plate, ring,',
        '        scale, splint and studded',
        '        leather rows (the costs,',
        '        weights, movements and bulk',
        '        flags) and the three shield',
        '        rows pin clean; the elfin',
        '        chain cost cell garbles -',
        '        which confirms the clean',
        '        never-sold footnote; the',
        '        R191 seam cross-checks the',
        '        plate AC ladder; CLOSED.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the table close')
if '- [x] **The new armor descriptions**' in s:
    already.append('gap: the descriptions close')
else:
    OLD = NL.join([
        '- [ ] **The new armor descriptions**',
        '      (pp. 75-76) - bronze plate (AC 4,',
        '      +2 rear-attack exposure, rust',
        '      immunity), elfin chain (thief-',
        '      wearable), field plate (the 1',
        '      point per die absorption, the 12',
        '      point cap, the repair costs),',
        '      full plate.'
    ])
    assert s.count(OLD) == 1, 'c2 old'
    NEW = NL.join([
        '- [x] **The new armor descriptions**',
        '      (pp. 75-76) - bronze plate (AC 4,',
        '      +2 rear-attack exposure, rust',
        '      immunity), elfin chain (thief-',
        '      wearable), field plate (the 1',
        '      point per die absorption, the 12',
        '      point cap, the repair costs),',
        '      full plate.',
        '      - CLOSED R371: the pin round',
        '        (rules/uaarmor.h) - the four',
        '        descriptions pin clean: the',
        '        bronze plate AC 4 with the',
        '        +2 rear bonus and the rust',
        '        immunity, the elfin chain',
        '        thief-wearable read, the',
        '        field plate absorption with',
        '        the cap and the repair',
        '        costs, the full plate',
        '        construction; the R334 seam',
        '        cross-checks the elfin',
        '        chain thief rows and the',
        '        R370 seam the barding',
        '        weight read; CLOSED.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the descriptions close')
wr(GP, s)

# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [x] **The expanded armor table**'
) == 1, 'c1 flip'
assert s.count(
    '- [x] **The new armor descriptions**'
) == 1, 'c2 flip'
assert s.count(
    '(rules/uaarmor.h) - the'
) == 2, 'c notes'
assert s.count(
    '- [ ] Armor, Types and Encumbrance (p.'
) == 1, 'c manifest kept'
assert s.count(
    '- [ ] **The new weapon descriptions**'
) == 1, 'c weapons kept open'
assert s.count(
    '- [x] **Warhorses and barding**'
) == 1, 'c r370 kept closed'
assert s.count(
    '- [ ] **The cavalier follower tables**'
) == 1, 'c followers kept open'
assert s.count(
    '- [x] **Cantrip acquisition, MU**'
) == 1, 'c r369 kept closed'
assert s.count(
    '- [x] **Method V**'
) == 1, 'c r370 method kept closed'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c armor class table kept open'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert len(applied) + len(already) == 4, 'c count'



# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R371 UA expanded armor pin audit' in s:
    already.append('regtest.cpp: the R371 audit')
else:
    INC_ANCH = ('#include "rules/uasmalls1.h"  // '
        'R370: the UA DM-section smalls')
    INC_NEW = NL.join([
        '#include "rules/uasmalls1.h"  // R370: the UA DM-section smalls',
        '#include "rules/uaarmor.h"  // R371: the UA expanded armor'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R371: the UA expanded armor
    // pin audit ----
    // The UA expanded armor (pp. 75-76):
    // the armor and encumbrance table
    // rows (banded through studded
    // leather, the shield rows, the
    // never-sold elfin chain footnote)
    // and the four descriptions - the
    // bronze plate (the AC 4, the +2
    // rear-attack exposure, the rust
    // immunity), the elfin chain (the
    // thief-wearable read), the field
    // plate (the 1 point per die
    // absorption, the 12 point cap, the
    // 100 gp per point repair), the full
    // plate. The R191 seam cross-checks
    // the plate AC ladder, the R334 seam
    // the thief elfin rows, the R370 seam
    // the barding weight read. Two items
    // flip CLOSED; the census 297 -> 298.
    {
        using namespace rules;
        int bad = 0;
        // ---- the table rows ----
            if (uaarmBandedWeight() != 35) ++bad;
            if (uaarmBandedMove() != 9) ++bad;
            if (uaarmBandedCost() != 90) ++bad;
            if (!uaarmBandedBulky()) ++bad;
            if (uaarmBronzePlateWeight() != 45)
                ++bad;
            if (uaarmBronzePlateMove() != 6)
                ++bad;
            if (uaarmBronzePlateCost() != 100)
                ++bad;
            if (!uaarmBronzePlateBulky()) ++bad;
            if (uaarmFieldPlateWeight() != 55)
                ++bad;
            if (uaarmFieldPlateMove() != 6)
                ++bad;
            if (uaarmFieldPlateCost() != 2000)
                ++bad;
            if (!uaarmFieldPlateFairlyBulky())
                ++bad;
            if (uaarmFullPlateWeight() != 65)
                ++bad;
            if (uaarmFullPlateMove() != 6) ++bad;
            if (uaarmFullPlateCost() != 4000)
                ++bad;
            if (!uaarmFullPlateFairlyBulky())
                ++bad;
            if (uaarmRingMailWeight() != 25) ++bad;
            if (uaarmRingMailMove() != 9) ++bad;
            if (uaarmRingMailCost() != 30) ++bad;
            if (uaarmScaleMailWeight() != 40) ++bad;
            if (uaarmScaleMailMove() != 6) ++bad;
            if (uaarmScaleMailCost() != 45) ++bad;
            if (uaarmSplintMailWeight() != 40) ++bad;
            if (uaarmSplintMailMove() != 6) ++bad;
            if (uaarmSplintMailCost() != 80) ++bad;
            if (uaarmStuddedLeatherWeight() != 20)
                ++bad;
            if (uaarmStuddedLeatherMove() != 9)
                ++bad;
            if (uaarmStuddedLeatherCost() != 15)
                ++bad;
            if (!uaarmElfinNeverOnOpenMarket())
                ++bad;
            if (uaarmShieldBucklerWeight() != 3)
                ++bad;
            if (uaarmShieldBucklerCost() != 5)
                ++bad;
            if (uaarmShieldLargeWeight() != 10)
                ++bad;
            if (uaarmShieldLargeCost() != 15) ++bad;
            if (uaarmShieldSmallWeight() != 5) ++bad;
            if (uaarmShieldSmallCost() != 10) ++bad;
            // the cost ladder: field plate
            // is half the full plate cost
            if (2 * uaarmFieldPlateCost()
                    != uaarmFullPlateCost()) ++bad;
            // the heavy armors share the
            // 6 inch move; the light the 9
            if (uaarmBronzePlateMove()
                    != uaarmFieldPlateMove()) ++bad;
            if (uaarmBandedMove()
                    != uaarmRingMailMove()) ++bad;
        // ---- the descriptions ----
            if (uaarmBronzeAc() != 4) ++bad;
            if (uaarmBronzeRearAttackBonus() != 2)
                ++bad;
            if (!uaarmBronzeRustImmune()) ++bad;
            if (!uaarmBronzeEarlierCheaperVersion())
                ++bad;
            if (!uaarmElfinElvenMade()) ++bad;
            if (!uaarmElfinExtremelyRare()) ++bad;
            if (!uaarmElfinThiefWearable()) ++bad;
            if (!uaarmElfinSomewhatImpairsThiefAbilities())
                ++bad;
            if (uaarmFieldPlateAbsorbPerDie() != 1)
                ++bad;
            if (uaarmFieldPlateAbsorbCap() != 12)
                ++bad;
            if (uaarmFieldPlateRepairCostPerPoint()
                    != 100) ++bad;
            if (uaarmFieldPlateRepairDaysPerPoint()
                    != 1) ++bad;
            if (!uaarmFieldPlateFittedToWearer())
                ++bad;
            if (!uaarmFieldPlateBulkyAsChain())
                ++bad;
            if (!uaarmFullPlateInterlockedBackedWithChain())
                ++bad;
            if (!uaarmFullPlateBulkyAsChain()) ++bad;
            // the field plate repair: the
            // full cap costs 1200 gp and
            // 12 days
            if (uaarmFieldPlateRepairCostPerPoint()
                    * uaarmFieldPlateAbsorbCap()
                    != 1200) ++bad;
            // the full plate outweighs
            // the field plate
            if (uaarmFullPlateWeight()
                    <= uaarmFieldPlateWeight())
                ++bad;
        // ---- the R191 seam ----
            // the plate mail AC 3 sits at
            // the ladder top; the bronze
            // plate reads one worse (4)
            if (armorRatingAc(10) != 3) ++bad;
            if (armorRatingAc(10) + 1
                    != uaarmBronzeAc()) ++bad;
            if (strcmp(armorRatingName(10),
                    "plate mail") != 0) ++bad;
        // ---- the R334 seam ----
            if (!thiefArmorElfinUnderNormalClothing())
                ++bad;
        // ---- the R370 seam ----
            // the elfin chain barding
            // weighs as leather
            if (!uasm1UnicornGriffonElfinWeightAsLeather())
                ++bad;
        printf("R371 UA expanded armor pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R371 audit')
s = rd(RT)
assert s.count(
    'R371 UA expanded armor pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 298, 'd census 298'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uaarmor.h"'
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
        'rules/armorratings.h'):
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
assert len(applied) + len(already) == 5,'d count'


# ---- the summary ----
print(
    'R371 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R371 note: the expanded armor',
    'round - the table rows (the',
    'costs, weights, movements, bulk',
    'flags, the shield rows) and the',
    'four descriptions (bronze plate',
    'AC 4, elfin chain, field plate',
    'absorption, full plate); the',
    'R191 seam cross-checks the plate',
    'AC ladder, the R334 seam the',
    'thief elfin rows, the R370 seam',
    'the barding weight read; two',
    'items flip CLOSED; the census',
    '297 -> 298'
])
print(NOTE)
print('commit: R371: the UA expanded')
print('armor pin round (census 298)',)

