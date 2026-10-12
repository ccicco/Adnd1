# R375: the UA determination
# skeleton pin round (pp. 84-89):
# the top-level band structure of
# the MAGIC ITEMS (Revised Table)
# and the sub-table splits pin
# clean - Potions 01-20 (split
# 01-65 the new potions / 66-00
# the original), Scrolls 21-35
# (01-85 / 86-00 the II.B.2),
# Ring 36-40 (01-67 / 68-00),
# Rods Staves & Wands 41-45
# (01-40 / 41-00 the II.D.2),
# Miscellaneous Magic 46-60 with
# SEVEN visible sub-bands (not
# two - six named IILE.1 through
# IILE.6, the seventh's name
# garbles), Armor & Shields 61-75
# (01-50 / 51-00), Sword 76-86
# (01-95 the II.G / 96-00 the
# II.G.2), Miscellaneous Weapons
# 87-00 (01-50 / 51-00); the
# scroll footnotes pin (the 30
# percent clerical, the 25
# percent druidical, the 10
# percent illusionist, the DMG
# p. 121 cross-ref); the row
# bodies of all eight tables
# OCR-scramble (dropped dice
# bands, orphaned value rows,
# merged columns) - the item's
# "all read clean" claim amended,
# the item stays OPEN, PDF-gated;
# the R374 dial seam
# cross-checks the modes; the
# census 301 -> 302.
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



# ---- (a) the seed: the R374 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R374 landed 2026-10-12: commit',
    '  1e9af1d, census 301, the UA',
    '  treasure dial decision round',
    '  (rules/uatreasuredial.h): THE',
    '  DECISION resolved RUN BOTH -',
    '  the DMG and UA tables ride as',
    '  switchable alternatives behind',
    '  a dial (DMG the default, UA,',
    '  MERGED), playtesting picks;',
    '  the per-source precedent',
    '  rides the monster file format;',
    '  the R219 seam the map bands,',
    '  the R220 seam the hoard bands;',
    '  the decision record landed, no',
    '  item flipped; GREEN on the',
    '  first run.'
])
s = rd(SD)
if 'R374 landed 2026-10-12' in s:
    already.append('seed: the R374 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R374 record')
s = rd(SD)
assert s.count(
    'R374 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uadetskel.h ----
P = 'rules/uadetskel.h'
if os.path.exists(P) and 'R375' in rd(P):
    already.append('uadetskel.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uadetskel.h
// The UA RANDOM TREASURE
// DETERMINATION - MAGIC ITEMS
// (Revised Table) skeleton pins
// (pp. 84-89), R375: the
// top-level category bands and
// the sub-table splits. The row
// bodies of the eight tables
// OCR-scramble in the extract -
// flagged; the item stays open,
// PDF-gated. The dial ride: the
// R374 seam (checked in the
// regtest audit, not here).
namespace rules {

// ---- the top-level categories ----
// The printed order, eight
// categories.
inline int uadsCategoryCount()
    { return 8; }

inline const char* uadsCategoryName(int i) {
    static const char* const k[8] = {
        "Potions", "Scrolls", "Ring",
        "Rods, Staves & Wands",
        "Miscellaneous Magic",
        "Armor & Shields", "Sword",
        "Miscellaneous Weapons",
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

inline int uadsCategoryLo(int i) {
    static const int k[8] = {
        1, 21, 36, 41, 46, 61, 76, 87
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

inline int uadsCategoryHi(int i) {
    static const int k[8] = {
        20, 35, 40, 45, 60, 75, 86, 100
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

// The printed heading: MAGIC
// ITEMS (Revised Table).
inline bool uadsIsTheRevisedTable()
    { return true; }

// ---- the sub-table splits ----
// Each category's second roll
// splits low/high; the low band
// is the new UA table, the high
// band the original DMG table
// (the potions low band carries
// the new potions - the elixirs
// and oils).
inline int uadsPotionSplitLo()
    { return 65; }

inline bool uadsPotionLowBandIsNewPotions()
    { return true; }

inline int uadsScrollSplitLo()
    { return 85; }

inline int uadsRingSplitLo()
    { return 67; }

inline int uadsRodSplitLo()
    { return 40; }

inline int uadsArmorSplitLo()
    { return 50; }

inline int uadsSwordSplitLo()
    { return 95; }

inline int uadsWeaponSplitLo()
    { return 50; }

// The named second tables the
// print carries: the scroll
// II.B.2, the rod II.D.2, the
// sword II.G and II.G.2.
inline bool uadsScrollSecondTableIsIIB2()
    { return true; }

inline bool uadsRodSecondTableIsIID2()
    { return true; }

inline bool uadsSwordFirstTableIsIIG()
    { return true; }

inline bool uadsSwordSecondTableIsIIG2()
    { return true; }

// ---- the miscellaneous magic
// sub-tables ----
// SEVEN visible sub-bands (not
// two): six named IILE.1 through
// IILE.6, the seventh's name
// garbles in the extract.
inline int uadsMiscSubCount()
    { return 7; }

inline int uadsMiscSubNamedCount()
    { return 6; }

inline bool uadsMiscSubSeventhNameGarbles()
    { return true; }

inline int uadsMiscSubLo(int i) {
    static const int k[7] = {
        1, 15, 29, 43, 57, 71, 86
    };
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    return k[i];
}

inline int uadsMiscSubHi(int i) {
    static const int k[7] = {
        14, 28, 42, 56, 70, 85, 100
    };
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    return k[i];
}

// ---- the scroll footnotes ----
// 30% of all spell scrolls are
// clerical (the dice 71-00 band);
// 25% of clerical scrolls are
// druidical; 10% of MU spell
// scrolls are illusionist - the
// applies-only-to-01-60 clause.
inline int uadsScrollClericalPct()
    { return 30; }

inline int uadsScrollClericalDruidPct()
    { return 25; }

inline int uadsScrollMuIllusionistPct()
    { return 10; }

inline bool uadsScrollFootnoteBandIs71To00()
    { return true; }

// The cursed-scroll footnote
// points at the DMG, p. 121.
inline int uadsScrollCurseDmgPage()
    { return 121; }

// ---- the extract read ----
// The row bodies of all eight
// tables OCR-scramble: dropped
// dice bands, orphaned value
// rows, merged columns - the
// bodies await the PDF.
inline bool uadsRowBodiesGarble()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uadetskel.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 28, 'b inline count'
assert s.count('R375') == 1, 'b round tag'
assert s.count(
    'uadsCategoryCount'
    ) >= 1, 'b fn'
assert 'uafol' not in s, 'b no uafol ref'
assert 'uanw' not in s, 'b no uanw ref'
assert 'uacm' not in s, 'b no uacm ref'
assert 'uaarm' not in s, 'b no uaarm ref'
assert 'uacavt' not in s, 'b no uacavt ref'
assert 'uawt' not in s, 'b no uawt ref'
assert 'uamt' not in s, 'b no uamt ref'
assert 'uatd' not in s, 'b no uatd ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R375' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **The random determination',
        '      tables** (pp. 84-89) - the',
        '      revised III.A (potions), III.B',
        '      (scrolls), III.C (rings), III.D',
        '      (rods/staves/wands), III.E',
        '      (miscellaneous magic, two',
        '      sub-tables), III.F (armor and',
        '      shield), III.G (swords), III.H',
        '      (miscellaneous weapons); all read',
        '      clean.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [ ] **The random determination',
        '      tables** (pp. 84-89) - the',
        '      revised III.A (potions), III.B',
        '      (scrolls), III.C (rings), III.D',
        '      (rods/staves/wands), III.E',
        '      (miscellaneous magic, two',
        '      sub-tables), III.F (armor and',
        '      shield), III.G (swords), III.H',
        '      (miscellaneous weapons); all read',
        '      clean.',
        '      - AMENDED R375: the skeleton',
        '        pin round (rules/uadetskel.h)',
        '        - the top-level bands and',
        '        sub-table splits pin clean;',
        '        the misc magic carries SEVEN',
        '        visible sub-bands (not two -',
        '        six named, the seventh',
        '        garbles); the scroll',
        '        footnotes pin (the 30 and 25',
        '        and 10 percents, the DMG p.',
        '        121 cross-ref); the row',
        '        bodies of all eight tables',
        '        OCR-scramble (dropped dice',
        '        bands, orphaned value rows,',
        '        merged columns) - the "all',
        '        read clean" claim corrected;',
        '        the item stays OPEN,',
        '        PDF-gated.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the amendment')
wr(GP, s)

# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [ ] **The random determination'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R375'
) == 1, 'c amendment'
assert s.count(
    '(rules/uadetskel.h)'
) == 1, 'c skeleton note'
assert s.count(
    'DECIDED R374'
) == 1, 'c r374 decision kept'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
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
if 'R375 UA determination skeleton pin audit' in s:
    already.append('regtest.cpp: the R375 audit')
else:
    INC_ANCH = ('#include "rules/uatreasuredial.h"  // '
        'R374: the UA treasure dial')
    INC_NEW = NL.join([
        '#include "rules/uatreasuredial.h"  // R374: the UA treasure dial',
        '#include "rules/uadetskel.h"  // R375: the UA determination skeleton'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R375: the UA determination
    // skeleton pin audit ----
    // The MAGIC ITEMS (Revised
    // Table) skeleton (pp. 84-89):
    // the top-level category bands,
    // the sub-table splits, the
    // seven misc-magic sub-bands,
    // the scroll footnotes. The row
    // bodies of the eight tables
    // OCR-scramble - flagged; the
    // item stays open, PDF-gated.
    // The R374 dial seam
    // cross-checks the modes; the
    // census 301 -> 302.
    {
        using namespace rules;
        int bad = 0;
        // ---- the top-level bands ----
            static const int kLo[8] = {
                1, 21, 36, 41, 46, 61, 76, 87};
            static const int kHi[8] = {
                20, 35, 40, 45, 60, 75, 86,
                100};
            if (uadsCategoryCount() != 8) ++bad;
            if (uadsCategoryLo(0) != 1) ++bad;
            if (uadsCategoryHi(7) != 100) ++bad;
            if (strcmp(uadsCategoryName(0),
                    "Potions") != 0) ++bad;
            if (strcmp(uadsCategoryName(3),
                    "Rods, Staves & Wands") != 0)
                ++bad;
            if (strcmp(uadsCategoryName(7),
                    "Miscellaneous Weapons")
                    != 0) ++bad;
            for (int i = 0; i < 8; ++i) {
                if (uadsCategoryLo(i) != kLo[i])
                    ++bad;
                if (uadsCategoryHi(i) != kHi[i])
                    ++bad;
                if (i < 7 && kHi[i] + 1
                        != kLo[i + 1]) ++bad;
            }
            if (!uadsIsTheRevisedTable()) ++bad;
        // ---- the splits ----
            if (uadsPotionSplitLo() != 65) ++bad;
            if (!uadsPotionLowBandIsNewPotions())
                ++bad;
            if (uadsScrollSplitLo() != 85) ++bad;
            if (uadsRingSplitLo() != 67) ++bad;
            if (uadsRodSplitLo() != 40) ++bad;
            if (uadsArmorSplitLo() != 50) ++bad;
            if (uadsSwordSplitLo() != 95) ++bad;
            if (uadsWeaponSplitLo() != 50) ++bad;
            if (!uadsScrollSecondTableIsIIB2())
                ++bad;
            if (!uadsRodSecondTableIsIID2())
                ++bad;
            if (!uadsSwordFirstTableIsIIG()) ++bad;
            if (!uadsSwordSecondTableIsIIG2())
                ++bad;
        // ---- the misc sub-bands ----
            static const int mLo[7] = {
                1, 15, 29, 43, 57, 71, 86};
            static const int mHi[7] = {
                14, 28, 42, 56, 70, 85, 100};
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsMiscSubNamedCount() != 6) ++bad;
            if (!uadsMiscSubSeventhNameGarbles())
                ++bad;
            for (int i = 0; i < 7; ++i) {
                if (uadsMiscSubLo(i) != mLo[i])
                    ++bad;
                if (uadsMiscSubHi(i) != mHi[i])
                    ++bad;
                if (i < 6 && mHi[i] + 1
                        != mLo[i + 1]) ++bad;
            }
        // ---- the scroll footnotes ----
            if (uadsScrollClericalPct() != 30)
                ++bad;
            if (uadsScrollClericalDruidPct() != 25)
                ++bad;
            if (uadsScrollMuIllusionistPct()
                    != 10) ++bad;
            if (!uadsScrollFootnoteBandIs71To00())
                ++bad;
            if (uadsScrollCurseDmgPage() != 121)
                ++bad;
        // ---- the extract read ----
            if (!uadsRowBodiesGarble()) ++bad;
        // ---- the R374 dial seam ----
            // the skeleton rides the
            // dial's UA mode when the
            // bodies land; DMG stays
            // the default
            if (uatdModeDmg() != 0) ++bad;
            if (uatdModeUa() != 1) ++bad;
            if (uatdModeMerged() != 2) ++bad;
            if (uatdDefaultMode()
                    != uatdModeDmg()) ++bad;
            if (!uatdRunBothDecided()) ++bad;
            if (!uatdUaPinRoundsPending()) ++bad;
        printf("R375 UA determination skeleton pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R375 audit')
s = rd(RT)
assert s.count(
    'R375 UA determination skeleton pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 302, 'd census 302'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uadetskel.h"'
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
    'R375 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R375 note: the determination',
    'skeleton round - the',
    'top-level bands and sub-table',
    'splits pin clean (the misc',
    'magic carries seven visible',
    'sub-bands, not two), the',
    'scroll footnotes pin; the',
    'row bodies of all eight',
    'tables OCR-scramble - the',
    '"all read clean" claim',
    'amended, the item stays OPEN,',
    'PDF-gated; the R374 dial seam',
    'the modes; the census',
    '301 -> 302'
])
print(NOTE)
print('commit: R375: the UA')
print('determination skeleton pin')
print('round (census 302)',)

