# R367: the UA campaign pin round -
# the social class and rank and the
# circumstances of birth (pp. 82-83):
# the nine-band Social Class Table
# with the occupation rosters, the
# starting-money note, the non-human
# placements and the profession rule;
# the 13-row Birth Table, the marital
# status split and the racial
# modifiers; both items flip CLOSED.
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


# ---- (a) the seed: the R366 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R366 landed 2026-10-12: commit',
    '  3e742b3, census 293, the UA',
    '  DM-section spells pin round',
    '  (rules/uaspellbooks.h,',
    '  rules/uaspellcomment.h,',
    '  rules/uauwspelluse.h and',
    '  rules/uadarkness.h): the MU',
    '  spell book rules (the',
    '  capacities and costs, the',
    '  physical aspects, the values,',
    '  the direct-casting and',
    '  learning reads), the spell',
    '  explanations commentary (the',
    '  permanency lists and the',
    "  Serten's immunity with the",
    '  band assignment flagged), the',
    '  underwater spell use lists',
    '  and the effects of darkness',
    '  ladder - all four items',
    '  CLOSED; GREEN on the first',
    '  run.',
])
s = rd(SD)
if 'R366 landed 2026-10-12' in s:
    already.append('seed: the R366 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R366 record')
s = rd(SD)
assert s.count(
    'R366 landed 2026-10-12'
) == 1, 'a entry'
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


# ---- (b) NEW rules/uasocialclass.h ----
P = 'rules/uasocialclass.h'
if os.path.exists(P) and 'R367' in rd(P):
    already.append('uasocialclass: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uasocialclass.h
// The UA SOCIAL CLASS AND RANK (p. 82 print) pins,
// R367: the Social Class Table (the nine-band dice
// ladder), the occupation rosters, the starting-money
// note, the non-human placements and the profession
// rule. Extends the landed R208 DMG structure header
// (rules/socialrank.h), which pins the government
// forms and the town structure but no random class
// table - the UA print adds the dice table.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the LLC roster label cell garbles ("Typloat
//     LLC: members Freed of...") - the roster list
//     itself reads; the label cell is flagged, the
//     names pin.
//   - the halfling placement prints "ULC (they are
//     small and rustic)" - the parenthetical reads
//     against the printed band; the print wins, the
//     divergence flagged pending the PDF.
//   - the R336 seam: the cavalier money stations name
//     the LMC/MMC/UMC/LUC/MUC/UUC bands exactly - the
//     band names pin to the R336 spellings.
// ===========================================================================

#pragma once

namespace rules {

// ---- the nine bands, in social-ladder order ----
inline int uasocBandCount()
    { return 9; }

inline int uasocBandLow(int i) {
    static const int k[9] = {
        1, 5, 11, 21, 36, 56, 88, 97, 100,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline int uasocBandHigh(int i) {
    static const int k[9] = {
        4, 10, 20, 35, 55, 87, 96, 99, 100,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline const char* uasocBandFullName(int i) {
    static const char* const k[9] = {
        "Lower Lower Class",
        "Middle Lower Class",
        "Upper Lower Class",
        "Lower Middle Class",
        "Middle Middle Class",
        "Upper Middle Class",
        "Lower Upper Class",
        "Middle Upper Class",
        "Upper Upper Class",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline const char* uasocBandAbbr(int i) {
    static const char* const k[9] = {
        "LLC", "MLC", "ULC", "LMC", "MMC",
        "UMC", "LUC", "MUC", "UUC",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

// ---- the occupation rosters, per band ----
inline int uasocRosterCount(int i) {
    static const int k[9] = {
        8, 10, 7, 8, 8, 9, 9, 6, 3,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline const char* uasocRosterName(int i, int j) {
    static const char* const r0[8] = {
        "slaves", "peasants", "tinkers",
        "vagabonds", "beggars", "criminals",
        "low-level thieves",
        "low-level and mid-level assassins",
    };
    static const char* const r1[10] = {
        "herdsmen", "laborers", "peddlers",
        "actors", "jugglers", "men-at-arms",
        "low-level barbarians",
        "mid-level thieves",
        "high-level assassins",
        "low-level bards",
    };
    static const char* const r2[7] = {
        "freemen", "tradesmen", "petty officers",
        "money-changers", "fences",
        "low-level fighters", "high-level thieves",
    };
    static const char* const r3[8] = {
        "artisans", "craftsmen", "petty merchants",
        "junior officers", "bankers",
        "landless knights", "druids", "rangers",
    };
    static const char* const r4[8] = {
        "landed gentry", "merchants",
        "petty officials", "senior officers",
        "landless petty nobles",
        "mid-level fighters",
        "low-level magic-users",
        "low-level illusionists",
    };
    static const char* const r5[9] = {
        "guild masters", "great merchants",
        "military commanders", "officials",
        "landless nobles", "lesser clerics",
        "high-level fighters",
        "mid-level magic-users",
        "mid-level illusionists",
    };
    static const char* const r6[9] = {
        "great landed gentry",
        "generals and marshals",
        "greater officials", "knights",
        "mid-level clerics", "cavaliers",
        "paladins", "high-level magic-users",
        "high-level illusionists",
    };
    static const char* const r7[6] = {
        "knights", "commanders", "great clerics",
        "nobles", "high-level paladins",
        "very high-level magic-users and"
        " illusionists",
    };
    static const char* const r8[3] = {
        "great nobles", "sovereign nobility",
        "royalty",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    if (j < 0) j = 0;
    switch (i) {
        case 0:
            if (j > 7) j = 7;
            return r0[j];
        case 1:
            if (j > 9) j = 9;
            return r1[j];
        case 2:
            if (j > 6) j = 6;
            return r2[j];
        case 3:
            if (j > 7) j = 7;
            return r3[j];
        case 4:
            if (j > 7) j = 7;
            return r4[j];
        case 5:
            if (j > 8) j = 8;
            return r5[j];
        case 6:
            if (j > 8) j = 8;
            return r6[j];
        case 7:
            if (j > 5) j = 5;
            return r7[j];
        default:
            if (j > 2) j = 2;
            return r8[j];
    }
}

inline bool uasocLlcLabelCellGarbled()
    { return true; }

// ---- the intro reads ----
// The table does not include any social or political
// information; guidelines follow the table so the DM
// can model the class distinctions to the tenor of
// the individual milieu.
inline bool uasocTableExcludesPoliticalInfo()
    { return true; }

inline bool uasocGuidelinesFollowTheTable()
    { return true; }

inline bool uasocDmModelsToMilieu()
    { return true; }

// ---- the starting-money note ----
// For player characters, initial social status has
// no effect on starting money and equipment, with
// the exception of cavaliers and paladins (the Money
// heading cross-reference, the landed R336 seam).
inline bool uasocPcStartMoneyUnaffected()
    { return true; }

inline bool uasocExceptCavaliersAndPaladins()
    { return true; }

inline bool uasocCavPaladinSeeMoneyHeading()
    { return true; }

// ---- the non-human placements ----
inline bool uasocDwarvesMMC()
    { return true; }

inline bool uasocDwarvesGoldGemsReputation()
    { return true; }

inline bool uasocWoodElfULC()
    { return true; }

inline bool uasocGrayElfLUC()
    { return true; }

inline bool uasocGnomeULCToLMC()
    { return true; }

inline bool uasocHalflingULC()
    { return true; }

inline bool uasocHalflingParentheticalDivergence()
    { return true; }

inline bool uasocHalfElfSlightlyAboveHuman()
    { return true; }

inline bool uasocHalfOrcLLC()
    { return true; }

inline bool uasocNonHumanPlacementMilieuDependent()
    { return true; }

// ---- the profession rule ----
// A character must have a social status of, at the
// lowest, one rank below that specified for the
// profession in the milieu; the printed example: a
// fighter needs Middle Lower Class or higher, so a
// Lower Lower Class character can be only a thief
// or assassin.
inline bool uasocProfessionOneRankBelowMinimum()
    { return true; }

inline bool uasocFighterRequiresMlcMinimum()
    { return true; }

inline bool uasocLlcBornOnlyThiefOrAssassin()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uasocialclass: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 27, 'b inline count'
assert s.count('R367') == 1, 'b round tag'
assert s.count('uasocBandCount') >= 1, 'b fn'
assert 'uabirth' not in s, 'b no uabirth ref'
assert 'uail' not in s, 'b no uail ref'
assert 'uam' not in s, 'b no uam ref'
assert 'uasc' not in s, 'b no uasc ref'
assert 'uasp' not in s, 'b no uasp ref'
assert 'uauw' not in s, 'b no uauw ref'
assert 'uadk' not in s, 'b no uadk ref'
assert 'uapc' not in s, 'b no uapc ref'
assert 'uabk' not in s, 'b no uabk ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (b2) NEW rules/uabirth.h ----
P = 'rules/uabirth.h'
if os.path.exists(P) and 'R367' in rd(P):
    already.append('uabirth: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uabirth.h
// The UA CIRCUMSTANCES OF BIRTH (p. 83 print) pins,
// R367: the Birth Table (the 12-child ladder with
// the only-child row), the Parents' Marital Status
// Table and the racial modifiers.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the section intro garbles ("By the nature for
//     of the topic...") - the readable tail pins (the
//     DM decides, the tables are a starting point),
//     the rest is a hole pending the PDF.
//   - the high-elf modifier cell prints a bare "20"
//     with the sign lost (every other cell carries
//     an explicit sign) - the magnitude pins, the
//     sign is a hole pending the PDF.
//   - the marital-status print interleaves the
//     married/unmarried labels across the dice
//     columns (01-80 / 81-00) - the split pins from
//     the readable dice cells.
// ===========================================================================

#pragma once

namespace rules {

// ---- the birth table, 13 rows ----
inline int uabirthRowCount()
    { return 13; }

inline int uabirthRowLow(int i) {
    static const int k[13] = {
        1, 6, 11, 21, 36, 51, 66, 81, 86,
        91, 95, 98, 100,
    };
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    return k[i];
}

inline int uabirthRowHigh(int i) {
    static const int k[13] = {
        5, 10, 20, 35, 50, 65, 80, 85, 90,
        94, 97, 99, 100,
    };
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    return k[i];
}

inline const char* uabirthOrderLabel(int i) {
    static const char* const k[13] = {
        "Only child", "1st child", "2nd child",
        "3rd child", "4th child", "5th child",
        "6th child", "7th child", "8th child",
        "9th child", "10th child", "11th child",
        "12th child",
    };
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    return k[i];
}

// ---- the parents' marital status table ----
inline int uabirthMarriedLow()
    { return 1; }

inline int uabirthMarriedHigh()
    { return 80; }

inline int uabirthUnmarriedLow()
    { return 81; }

inline int uabirthUnmarriedHigh()
    { return 100; }

// The child of unmarried parents is typically one
// social class lower than the social class of the
// father.
inline bool uabirthUnmarriedOneClassBelowFather()
    { return true; }

// ---- the racial modifiers (both tables) ----
inline int uabirthDwarfMod()
    { return -15; }

inline int uabirthElfDrowMod()
    { return -15; }

inline int uabirthElfGrayMod()
    { return -30; }

// The high-elf cell prints a bare 20 - the sign is
// lost in the print; the magnitude pins.
inline int uabirthElfHighModMagnitude()
    { return 20; }

inline bool uabirthElfHighModSignLost()
    { return true; }

inline int uabirthElfWoodMod()
    { return -10; }

inline int uabirthElfOtherMod()
    { return -15; }

inline int uabirthGnomeMod()
    { return -20; }

inline int uabirthHalfElfMod()
    { return -10; }

inline int uabirthHalflingMod()
    { return -10; }

// The half-orc split: +10 on the Birth Table, +75 on
// the Marital Status Table.
inline int uabirthHalfOrcBirthMod()
    { return 10; }

inline int uabirthHalfOrcMaritalMod()
    { return 75; }

inline bool uabirthHumanNoMods()
    { return true; }

// ---- the intro reads ----
inline bool uabirthIntroGarbled()
    { return true; }

inline bool uabirthDmDecidesToMilieu()
    { return true; }

inline bool uabirthTablesAStartingPoint()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uabirth: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b2 ns'
assert s.count('inline') == 25, 'b2 inline count'
assert s.count('R367') == 1, 'b2 round tag'
assert s.count('uabirthRowCount') >= 1, 'b2 fn'
assert 'uasoc' not in s, 'b2 no uasoc ref'
assert 'uail' not in s, 'b2 no uail ref'
assert 'uam' not in s, 'b2 no uam ref'
assert 'uasc' not in s, 'b2 no uasc ref'
assert 'uasp' not in s, 'b2 no uasp ref'
assert 'uauw' not in s, 'b2 no uauw ref'
assert 'uadk' not in s, 'b2 no uadk ref'
assert 'uapc' not in s, 'b2 no uapc ref'
assert 'uabk' not in s, 'b2 no uabk ref'
assert len(applied) + len(already) == 3, 'b2 count'


# ---- (c1) the gap ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **Social class and rank**' in s:
    already.append('gap report: the social class close')
else:
    OLD = NL.join([
        '- [ ] **Social class and rank** (p. 82)',
        '      - the Social Class Table; extends',
        '      the R208 tables.',
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [x] **Social class and rank** (p. 82)',
        '      - the Social Class Table; extends',
        '      the R208 tables.',
        '      - CLOSED R367: the pin round',
        '        (rules/uasocialclass.h) - the',
        '        nine-band dice ladder with the',
        '        occupation rosters per band, the',
        '        no-effect-on-starting-money note',
        '        with the cavalier/paladin',
        '        exception, the non-human',
        '        placements, the one-rank-below',
        '        profession rule; the LLC label',
        '        cell garbles and the halfling',
        '        ULC parenthetical divergence',
        '        flagged pending the PDF; the',
        '        R336 seam cross-checks the',
        '        cavalier money stations.',
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    wr(GP, s)
    applied.append('gap report: the social class close')

# ---- (c2) the gap ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **Circumstances of birth**' in s:
    already.append('gap report: the birth close')
else:
    OLD = NL.join([
        '- [ ] **Circumstances of birth** (p.',
        '      83) - the Birth Table (the',
        '      12-child ladder), the Parents',
        '      Marital Status Table (the',
        '      one-class-lower read for the',
        '      unmarried).',
    ])
    assert s.count(OLD) == 1, 'c2 old'
    NEW = NL.join([
        '- [x] **Circumstances of birth** (p.',
        '      83) - the Birth Table (the',
        '      12-child ladder), the Parents',
        '      Marital Status Table (the',
        '      one-class-lower read for the',
        '      unmarried).',
        '      - CLOSED R367: the pin round',
        '        (rules/uabirth.h) - the 13-row',
        '        birth ladder, the marital',
        '        status split with the',
        '        one-class-below-the-father',
        '        read, the racial modifiers',
        '        (the half-orc +10/+75 split);',
        '        the section intro garbles and',
        '        the high-elf sign cell lost -',
        '        flagged in-header pending the',
        '        PDF.',
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    wr(GP, s)
    applied.append('gap report: the birth close')

# ---- (c) the gap kept asserts ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
assert s.count(
    '- [x] **Social class and rank**'
) == 1, 'c1 flip'
assert s.count(
    '- [x] **Circumstances of birth**'
) == 1, 'c2 flip'
assert s.count('(rules/uasocialclass.h) - the') == 1, 'c1 note'
assert s.count('(rules/uabirth.h) - the') == 1, 'c2 note'
assert s.count(
    '- [x] **The effects of darkness**'
) == 1, 'c r366 kept'
assert s.count(
    '- [x] **Underwater spell use**'
) == 1, 'c r366 kept'
assert s.count(
    '- [ ] **Cantrip acquisition, MU**'
) == 1, 'c cantrip kept open'
assert s.count(
    '- [ ] **Illusionist spell acquisition**'
) == 1, 'c acq kept open'
assert s.count(
    '- [ ] **Cavaliers Table I**'
) == 1, 'c cav table kept open'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert len(applied) + len(already) == 5, 'c count'


# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R367 UA social/birth pin audit' in s:
    already.append('regtest.cpp: the R367 audit')
else:
    INC_ANCH = ('#include "rules/uadarkness.h"  // '
        'R366: the UA effects of darkness')
    INC_NEW = NL.join([
        '#include "rules/uadarkness.h"  // R366: the UA effects of darkness',
        '#include "rules/uasocialclass.h"  // R367: the UA social class',
        '#include "rules/uabirth.h"  // R367: the UA circumstances of birth',
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R367: the UA campaign social
    // class and birth pin audit ----
    // The UA CAMPAIGN section (pp.
    // 82-83): the SOCIAL CLASS AND RANK
    // - the nine-band dice ladder (LLC
    // 01-04 through UUC 00), the
    // occupation rosters per band (the
    // LLC label cell garbles, flagged),
    // the no-effect-on-starting-money
    // note with the cavalier/paladin
    // exception, the non-human
    // placements (the halfling ULC
    // parenthetical divergence flagged),
    // the one-rank-below profession
    // rule; the CIRCUMSTANCES OF BIRTH -
    // the 13-row birth ladder, the
    // marital status split 01-80/81-00
    // with the one-class-below-the-
    // father read, the racial modifiers
    // (the high-elf sign cell lost,
    // the half-orc +10/+75 split). The
    // R336 seam cross-checks the cavalier
    // money stations against the band
    // names. Both items flip CLOSED; the
    // census 293 -> 294.
    {
        using namespace rules;
        int bad = 0;
        // ---- the uasoc pins ----
            if (uasocBandCount() != 9) ++bad;
            if (!uasocLlcLabelCellGarbled()) ++bad;
            if (!uasocTableExcludesPoliticalInfo()) ++bad;
            if (!uasocGuidelinesFollowTheTable()) ++bad;
            if (!uasocDmModelsToMilieu()) ++bad;
            if (!uasocPcStartMoneyUnaffected()) ++bad;
            if (!uasocExceptCavaliersAndPaladins()) ++bad;
            if (!uasocCavPaladinSeeMoneyHeading()) ++bad;
            if (!uasocDwarvesMMC()) ++bad;
            if (!uasocDwarvesGoldGemsReputation()) ++bad;
            if (!uasocWoodElfULC()) ++bad;
            if (!uasocGrayElfLUC()) ++bad;
            if (!uasocGnomeULCToLMC()) ++bad;
            if (!uasocHalflingULC()) ++bad;
            if (!uasocHalflingParentheticalDivergence()) ++bad;
            if (!uasocHalfElfSlightlyAboveHuman()) ++bad;
            if (!uasocHalfOrcLLC()) ++bad;
            if (!uasocNonHumanPlacementMilieuDependent()) ++bad;
            if (!uasocProfessionOneRankBelowMinimum()) ++bad;
            if (!uasocFighterRequiresMlcMinimum()) ++bad;
            if (!uasocLlcBornOnlyThiefOrAssassin()) ++bad;
        // ---- the uabirth pins ----
            if (uabirthRowCount() != 13) ++bad;
            if (uabirthMarriedLow() != 1) ++bad;
            if (uabirthMarriedHigh() != 80) ++bad;
            if (uabirthUnmarriedLow() != 81) ++bad;
            if (uabirthUnmarriedHigh() != 100) ++bad;
            if (!uabirthUnmarriedOneClassBelowFather()) ++bad;
            if (uabirthDwarfMod() != -15) ++bad;
            if (uabirthElfDrowMod() != -15) ++bad;
            if (uabirthElfGrayMod() != -30) ++bad;
            if (uabirthElfHighModMagnitude() != 20) ++bad;
            if (!uabirthElfHighModSignLost()) ++bad;
            if (uabirthElfWoodMod() != -10) ++bad;
            if (uabirthElfOtherMod() != -15) ++bad;
            if (uabirthGnomeMod() != -20) ++bad;
            if (uabirthHalfElfMod() != -10) ++bad;
            if (uabirthHalflingMod() != -10) ++bad;
            if (uabirthHalfOrcBirthMod() != 10) ++bad;
            if (uabirthHalfOrcMaritalMod() != 75) ++bad;
            if (!uabirthHumanNoMods()) ++bad;
            if (!uabirthIntroGarbled()) ++bad;
            if (!uabirthDmDecidesToMilieu()) ++bad;
            if (!uabirthTablesAStartingPoint()) ++bad;
        // ---- the band table ----
            static const int bl[9] = {1, 5, 11, 21,
                36, 56, 88, 97, 100};
            static const int bh[9] = {4, 10, 20, 35,
                55, 87, 96, 99, 100};
            for (int i = 0; i < 9; ++i) {
                if (uasocBandLow(i) != bl[i]) ++bad;
                if (uasocBandHigh(i) != bh[i]) ++bad;
                if (i < 8 && bh[i] + 1 != bl[i + 1])
                    ++bad;
            }
            if (uasocBandCount() != 9) ++bad;
            if (strcmp(uasocBandAbbr(0), "LLC") != 0)
                ++bad;
            if (strcmp(uasocBandAbbr(8), "UUC") != 0)
                ++bad;
            if (strcmp(uasocBandFullName(4),
                    "Middle Middle Class") != 0)
                ++bad;
        // ---- the rosters ----
            static const int rc[9] = {8, 10, 7, 8, 8,
                9, 9, 6, 3};
            int rsum = 0;
            for (int i = 0; i < 9; ++i) {
                if (uasocRosterCount(i) != rc[i])
                    ++bad;
                rsum += uasocRosterCount(i);
                for (int j = 0; j < rc[i]; ++j) {
                    if (uasocRosterName(i, j)[0] == 0)
                        ++bad;
                }
            }
            if (rsum != 68) ++bad;
            if (strcmp(uasocRosterName(0, 5),
                "criminals") != 0) ++bad;
            if (strcmp(uasocRosterName(6, 5),
                "cavaliers") != 0) ++bad;
            if (strcmp(uasocRosterName(6, 6),
                "paladins") != 0) ++bad;
            if (strcmp(uasocRosterName(8, 0),
                "great nobles") != 0) ++bad;
        // ---- the R336 seam ----
            if (cavMoneyStationCount() != 6)
                ++bad;
            if (strcmp(cavMoneyStationName(3),
                    uasocBandFullName(6)) != 0)
                ++bad;
            if (strcmp(cavMoneyStationName(4),
                    uasocBandFullName(7)) != 0)
                ++bad;
            if (strcmp(cavMoneyStationName(5),
                    uasocBandFullName(8)) != 0)
                ++bad;
            if (strncmp(cavMoneyStationName(0),
                    uasocBandFullName(3), 18) != 0)
                ++bad;
            if (!cavMoneyPaladinExceptionNoted())
                ++bad;
        // ---- the birth table ----
            static const int wl[13] = {1, 6, 11, 21,
                36, 51, 66, 81, 86, 91, 95, 98, 100};
            static const int wh[13] = {5, 10, 20, 35,
                50, 65, 80, 85, 90, 94, 97, 99, 100};
            for (int i = 0; i < 13; ++i) {
                if (uabirthRowLow(i) != wl[i]) ++bad;
                if (uabirthRowHigh(i) != wh[i]) ++bad;
                if (i < 12 && wh[i] + 1 != wl[i + 1])
                    ++bad;
            }
            if (uabirthRowCount() != 13)
                ++bad;
            if (strcmp(uabirthOrderLabel(0),
                "Only child") != 0) ++bad;
            if (strcmp(uabirthOrderLabel(12),
                "12th child") != 0) ++bad;
        printf("R367 UA social/birth pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R367 audit')
s = rd(RT)
assert s.count(
    'R367 UA social/birth pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 294, 'd census 294'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uasocialclass.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uabirth.h"'
) == 1, 'd new include'
for h in ('rules/uaspellbooks.h',
        'rules/uaspellcomment.h',
        'rules/uauwspelluse.h',
        'rules/uadarkness.h',
        'rules/cavmoney.h',
        'rules/socialrank.h'):
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
assert len(applied) + len(already) == 6, 'd count'


# ---- the summary ----
print('R367 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R367 note: the UA campaign pin round -')
print('the nine-band social class ladder',)
print('with the rosters, the money note,',)
print('the non-human placements and the',)
print('profession rule; the 13-row birth',)
print('ladder, the marital split and the',)
print('racial modifiers; both items flip',)
print('CLOSED; the R336 seam cross-checks',)
print('the cavalier stations; the census',)
print('293 -> 294')
print('commit: R367: the UA campaign social',)
print('class and birth pin round (census 294)',)

