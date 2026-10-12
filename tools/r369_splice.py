
# R369: the UA cantrip acquisition pin
# round (p. 79): the known-count rules -
# the useful category one per point of
# intelligence by free choice (the read
# decoded from the garbled sentence), the
# five random categories (reversed 2-8,
# legerdemain 2-5, person-affecting 2-8,
# personal 2-8, haunting-sound 2-5), the
# three-developed-cantrips cap with the DM
# review, the read-as-spell and
# recorded-as-spell notes; the item flips
# CLOSED; the R365 seam cross-checks the
# illusionist bands and the R366 seam the
# spell-book counts.
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



# ---- (a) the seed: the R368 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R368 landed 2026-10-12: commit',
    '  37c7f1a, census 295, the UA',
    '  Cavaliers Table I pin round',
    '  (rules/uacavtable.h): the two',
    '  0-level rows, the 1st-level',
    '  footnote, the printed XP bands',
    '  (the level-11 band decoded), the',
    '  cumulative dice column, the level',
    '  titles - the 11th and 12th cells',
    '  newly readable (two of the four',
    '  R328 holes close), the level-5',
    '  grid Knight flagged, the level-6',
    '  cell and the 12-sided header cell',
    '  holes pending the PDF; the item',
    '  CLOSED; the R368b follow-up fixed',
    '  an off-by-one in the audit',
    '  title-loop mapping (bad 12 to 0);',
    '  the R328 seam cross-checks; GREEN',
    '  on the second run, after the fix.'
])
s = rd(SD)
if 'R368 landed 2026-10-12' in s:
    already.append('seed: the R368 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R368 record')
s = rd(SD)
assert s.count(
    'R368 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uacantacq.h ----
P = 'rules/uacantacq.h'
if os.path.exists(P) and 'R369' in rd(P):
    already.append('uacantacq.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uacantacq.h
// The UA ACQUISITION OF CANTRIPS,
// MAGIC-USERS (p. 79) pins, R369: the
// known-count rules - the useful category
// one known per point of intelligence by
// free choice, the five random categories
// (reversed 2-8, legerdemain 2-5,
// person-affecting 2-8, personal 2-8,
// haunting-sound 2-5), the three developed
// cantrips cap with the DM review, and the
// read-as-spell / recorded-as-spell notes.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. Cross-checks the landed R365 seam
// (rules/uailacquisition.h - the illusionist bands
// deliberately differ, the documented divergence)
// and the R366 spell-book seam (cantrips count as
// 1st-level spells).
//
// JUDGMENTs (the decode method):
//   - the useful-per-intelligence sentence garbles
//     in the extract; the read - one known per point
//     of intelligence, free choice - is decoded from
//     the surviving fragments and matches the gap
//     report standing reading; flagged pending the
//     PDF.
//   - the five random bands and the developed-cap
//     sentence print clean.
//   - the 0-level per-day tier (p. 45) rides its own
//     item (the cantrips category); no pin here.

namespace rules {

// ---- the useful category ----
// One known per point of intelligence, free
// choice - the decode flagged above.
inline int uacaqUsefulPerIntelligencePoint()
    { return 1; }

inline bool uacaqUsefulFreeChoice()
    { return true; }

inline bool uacaqUsefulReadDecoded()
    { return true; }

// ---- the category count ----
// Six MU categories; the illusionist seventh
// (minor illusion) is R365 territory.
inline int uacaqCategoryCount()
    { return 6; }

// ---- the five random categories ----
inline int uacaqReversedKnownMin()
    { return 2; }

inline int uacaqReversedKnownMax()
    { return 8; }

inline int uacaqLegerdemainKnownMin()
    { return 2; }

inline int uacaqLegerdemainKnownMax()
    { return 5; }

inline int uacaqPersonAffectingKnownMin()
    { return 2; }

inline int uacaqPersonAffectingKnownMax()
    { return 8; }

inline int uacaqPersonalKnownMin()
    { return 2; }

inline int uacaqPersonalKnownMax()
    { return 8; }

inline int uacaqHauntingSoundKnownMin()
    { return 2; }

inline int uacaqHauntingSoundKnownMax()
    { return 5; }

// ---- the developed-cantrips cap ----
inline int uacaqMaxDevelopedCantrips()
    { return 3; }

inline bool uacaqDevelopedRequiresDmReview()
    { return true; }

// ---- the spell-procedure notes ----
// Cantrips are read as spells and recorded
// in books or scrolls by the spell procedure.
inline bool uacaqReadAsSpell()
    { return true; }

inline bool uacaqRecordedAsSpell()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uacantacq.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 18, 'b inline count'
assert s.count('R369') == 1, 'b round tag'
assert s.count(
    'uacaqUsefulPerIntelligencePoint'
    ) >= 1, 'b fn'
assert 'uacavt' not in s, 'b no uacavt ref'
assert 'uabk' not in s, 'b no uabk ref'
assert 'uailc' not in s, 'b no uailc ref'
assert 'uasoc' not in s, 'b no uasoc ref'
assert 'uabirth' not in s, 'b no uabirth ref'
assert 'uasp' not in s, 'b no uasp ref'
assert 'uaila' not in s.replace(
    'uailacquisition.h', ''), 'b no uaila call'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the item close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **Cantrip acquisition, MU**' in s:
    already.append('gap report: the item close')
else:
    OLD = NL.join([
        '- [ ] **Cantrip acquisition, MU** (p.',
        '      79) - the known-count rules (the',
        '      useful-per-intelligence read; the',
        '      2-8/2-5 random counts; the 3',
        '      developed cantrips cap).'
    ])
    assert s.count(OLD) == 1, 'c old'
    NEW = NL.join([
        '- [x] **Cantrip acquisition, MU** (p.',
        '      79) - the known-count rules (the',
        '      useful-per-intelligence read; the',
        '      2-8/2-5 random counts; the 3',
        '      developed cantrips cap).',
        '      - CLOSED R369: the pin round',
        '        (rules/uacantacq.h) - the five',
        '        random bands (reversed 2-8,',
        '        legerdemain 2-5, person-',
        '        affecting 2-8, personal 2-8,',
        '        haunting-sound 2-5) and the 3',
        '        developed cap with the DM',
        '        review and the spell-procedure',
        '        notes pin clean; the useful one',
        '        per point of intelligence by',
        '        free choice is decoded from the',
        '        garbled sentence (flagged',
        '        pending the PDF); the R365 seam',
        '        cross-checks the illusionist',
        '        bands (the documented',
        '        divergence), the R366 seam the',
        '        book counts; CLOSED.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    wr(GP, s)
    applied.append('gap report: the item close')

# ---- (c) the gap kept asserts ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
assert s.count(
    '- [x] **Cantrip acquisition, MU**'
) == 1, 'c flip'
assert s.count(
    '(rules/uacantacq.h) - the five'
) == 1, 'c note'
assert s.count(
    '- [ ] **Illusionist spell acquisition**'
) == 1, 'c il kept open'
assert s.count(
    '- [ ] **The magic-user cantrips**'
) == 1, 'c mu cantrips kept open'
assert s.count(
    '- [x] **Cavaliers Table I**'
) == 1, 'c r368 kept closed'
assert s.count(
    '- [x] **Social class and rank**'
) == 1, 'c r367 kept closed'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c armor kept open'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert len(applied) + len(already) == 3, 'c count'



# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R369 UA cantrip acquisition pin audit' in s:
    already.append('regtest.cpp: the R369 audit')
else:
    INC_ANCH = ('#include "rules/uacavtable.h"  // '
        'R368: the UA Cavaliers Table I')
    INC_NEW = NL.join([
        '#include "rules/uacavtable.h"  // R368: the UA Cavaliers Table I',
        '#include "rules/uacantacq.h"  // R369: the UA cantrip acquisition'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R369: the UA cantrip
    // acquisition pin audit ----
    // The UA ACQUISITION OF CANTRIPS,
    // MAGIC-USERS (p. 79): the known-count
    // rules pinned - the useful category
    // one per point of intelligence by free
    // choice (the decode flagged), the five
    // random bands (reversed 2-8, legerdemain
    // 2-5, person-affecting 2-8, personal
    // 2-8, haunting-sound 2-5), the 3
    // developed cap with the DM review, the
    // read-as-spell and recorded-as-spell
    // notes. The R365 seam cross-checks the
    // illusionist bands (the documented
    // divergence); the R366 seam the book
    // counts. The item flips CLOSED; the
    // census 295 -> 296.
    {
        using namespace rules;
        int bad = 0;
        // ---- the pinned cells ----
            if (uacaqUsefulPerIntelligencePoint()
                    != 1) ++bad;
            if (!uacaqUsefulFreeChoice()) ++bad;
            if (!uacaqUsefulReadDecoded()) ++bad;
            if (uacaqCategoryCount() != 6) ++bad;
            if (uacaqReversedKnownMin() != 2)
                ++bad;
            if (uacaqReversedKnownMax() != 8)
                ++bad;
            if (uacaqLegerdemainKnownMin() != 2)
                ++bad;
            if (uacaqLegerdemainKnownMax() != 5)
                ++bad;
            if (uacaqPersonAffectingKnownMin() != 2)
                ++bad;
            if (uacaqPersonAffectingKnownMax() != 8)
                ++bad;
            if (uacaqPersonalKnownMin() != 2)
                ++bad;
            if (uacaqPersonalKnownMax() != 8)
                ++bad;
            if (uacaqHauntingSoundKnownMin() != 2)
                ++bad;
            if (uacaqHauntingSoundKnownMax() != 5)
                ++bad;
            if (uacaqMaxDevelopedCantrips() != 3)
                ++bad;
            if (!uacaqDevelopedRequiresDmReview())
                ++bad;
            if (!uacaqReadAsSpell()) ++bad;
            if (!uacaqRecordedAsSpell()) ++bad;
        // ---- the R365 illusionist seam ----
            // The documented MU-vs-illusionist
            // divergences (the bands differ by
            // design; the illusionist useful cap
            // is intelligence minus 3):
            if (uacaqReversedKnownMax()
                    == uailaReversedKnownMax())
                ++bad;
            if (uacaqLegerdemainKnownMin()
                    == uailaLegerdemainKnownMin())
                ++bad;
            if (uacaqPersonAffectingKnownMax()
                    == uailaPersonAffectingKnownMax())
                ++bad;
            if (uacaqPersonalKnownMax()
                    == uailaPersonalKnownMax())
                ++bad;
            if (uacaqHauntingSoundKnownMax()
                    == uailaHauntingSoundKnownMax())
                ++bad;
            if (uacaqUsefulPerIntelligencePoint()
                    * 18 - uailaUsefulCapAtInt18()
                    != uailaUsefulCapIntMinus())
                ++bad;
            if (!uailaHasAllMuCantrips()) ++bad;
            if (!uailaMuCantripPropertiesOtherwiseApply())
                ++bad;
            // The seven-category read: the six
            // MU categories plus the
            // illusionist-only minor illusion.
            if (uacaqCategoryCount() + 1 != 7)
                ++bad;
        // ---- the R366 spell-book seam ----
            if (!uabkCantripsCountAsFirstLevel())
                ++bad;
            if (uabkStandardCantripsCapacity()
                    != 36) ++bad;
        printf("R369 UA cantrip acquisition pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R369 audit')
s = rd(RT)
assert s.count(
    'R369 UA cantrip acquisition pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 296, 'd census 296'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uacantacq.h"'
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
assert len(applied) + len(already) == 4, 'd count'


# ---- the summary ----
print(
    'R369 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R369 note: the cantrip acquisition',
    'round - the useful one-per-INT read',
    '(decoded, flagged), the five random',
    'bands, the 3 developed cap, the',
    'spell-procedure notes; the R365 seam',
    'cross-checks the illusionist bands',
    'and the R366 seam the book counts;',
    'the item flips CLOSED; the census',
    '295 -> 296'
])
print(NOTE)
print('commit: R369: the UA cantrip')
print('acquisition pin round (census 296)',)

