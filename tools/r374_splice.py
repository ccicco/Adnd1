
# R374: the UA treasure dial
# decision round: THE DECISION
# named in the gap report's
# treasure section resolves RUN
# BOTH - the engine carries the
# DMG and UA tables as switchable
# alternatives behind a dial:
# DMG (the default - the seventy
# landed audits stay
# authoritative), UA, MERGED;
# playtesting picks. The
# per-source precedent rides the
# monster file format. The UA pin
# rounds follow - the dial lands
# first, the charge after. The
# R219 seam cross-checks the map
# table bands, the R220 seam the
# hoard bands; no item flips this
# round - the decision record
# lands; the census 300 -> 301.
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



# ---- (a) the seed: the R373 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R373 landed 2026-10-12: commit',
    '  7893f9c, census 300, the UA',
    '  comeliness note pin round',
    '  (rules/uacomnote.h): the DM',
    '  pointer to pages 6 and 7, the',
    '  characteristic read, the',
    '  effects on viewers and',
    '  reactors, the trailing sentence',
    '  hole flagged; the weapon',
    '  descriptions item closed',
    '  riding the R340 pins (the',
    '  16-entry roster with the 14',
    '  item-list types, the residual',
    '  OCR holes flagged); the R322',
    '  seam the creation roll and',
    '  charisma ladder, the R340',
    '  seam the roster, the R337',
    '  seam the pole-arm rows; two',
    '  items CLOSED; GREEN on the',
    '  first run.'
])
s = rd(SD)
if 'R373 landed 2026-10-12' in s:
    already.append('seed: the R373 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R373 record')
s = rd(SD)
assert s.count(
    'R373 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uatreasuredial.h ----
P = 'rules/uatreasuredial.h'
if os.path.exists(P) and 'R374' in rd(P):
    already.append('uatreasuredial.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uatreasuredial.h
// The UA TREASURE DIAL decision
// pins, R374: THE DECISION named
// in the gap report's treasure
// section (the UA random
// determination tables III.A
// through III.H REPLACE the DMG
// tables) resolves RUN BOTH - the
// engine carries the DMG and UA
// tables as switchable
// alternatives behind a dial and
// lets playtesting pick. The
// per-source precedent rides the
// monster file format. The UA pin
// rounds follow; the dial lands
// first, the charge after. The
// R219 and R220 seams ride the
// regtest audit, not here.
namespace rules {

// ---- the dial modes ----
// DMG: the landed audits stay
// authoritative (the default
// until the UA pin rounds land).
inline int uatdModeDmg() { return 0; }

// UA: the revised tables.
inline int uatdModeUa() { return 1; }

// MERGED: both table sets with
// the union rows.
inline int uatdModeMerged() { return 2; }

inline int uatdModeCount() { return 3; }

// The default mode: DMG.
inline int uatdDefaultMode()
    { return uatdModeDmg(); }

// ---- the decision ----
// RUN BOTH - decided.
inline bool uatdRunBothDecided()
    { return true; }

// The printed fact: the UA
// tables replace the DMG tables.
inline bool uatdUaTablesReplaceDmg()
    { return true; }

// The seventy landed DMG audits
// stay authoritative.
inline bool uatdDmgAuditsAuthoritative()
    { return true; }

// The audit rounds span R219
// through R287.
inline int uatdDmgAuditRoundFirst()
    { return 219; }

inline int uatdDmgAuditRoundLast()
    { return 287; }

// The monster file format
// already tracks source per
// record - the per-source
// precedent.
inline bool uatdMonsterFileTracksSource()
    { return true; }

// Playtesting picks.
inline bool uatdPlaytestingPicks()
    { return true; }

// The UA pin rounds have not
// landed yet - the dial lands
// first.
inline bool uatdUaPinRoundsPending()
    { return true; }

// ---- the carrier contract ----
// Both table sets ride: DMG and
// UA.
inline int uatdTableSetCount()
    { return 2; }

// The MERGED mode carries both.
inline bool uatdMergedCarriesBoth()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uatreasuredial.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 15, 'b inline count'
assert s.count('R374') == 1, 'b round tag'
assert s.count(
    'uatdRunBothDecided'
    ) >= 1, 'b fn'
assert 'uafol' not in s, 'b no uafol ref'
assert 'uanw' not in s, 'b no uanw ref'
assert 'uacm' not in s, 'b no uacm ref'
assert 'uaarm' not in s, 'b no uaarm ref'
assert 'uacavt' not in s, 'b no uacavt ref'
assert 'uawt' not in s, 'b no uawt ref'
assert 'uamt' not in s, 'b no uamt ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the decision
# record lands (no item flips) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'DECIDED R374' in s:
    already.append('gap: the decision record')
else:
    OLD = NL.join([
        'precedent. The decision needs its own',
        'round before any treasure charge lands.',
        ''
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        'precedent. The decision needs its own',
        'round before any treasure charge lands.',
        '',
        'DECIDED R374: RUN BOTH - the engine',
        '      carries the DMG and UA tables as',
        '      switchable alternatives behind a',
        '      dial (rules/uatreasuredial.h):',
        '      DMG (the default - the landed',
        '      audits stay authoritative), UA,',
        '      MERGED; playtesting picks; the',
        '      per-source precedent rides the',
        '      monster file format. The UA pin',
        '      rounds follow - the dial lands',
        '      first, the charge after.',
        ''
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the decision record')
wr(GP, s)

# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    'DECIDED R374'
) == 1, 'c decision record'
assert s.count(
    '(rules/uatreasuredial.h):'
) == 1, 'c dial note'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert s.count(
    '- [ ] **The random determination'
) == 1, 'c determination kept open'
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
    '- [x] **The new weapon descriptions**'
) == 1, 'c r373 weapons kept closed'
assert s.count(
    '- [x] **The cavalier follower tables**'
) == 1, 'c r372 followers kept closed'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c armor class table kept open'
assert len(applied) + len(already) == 3, 'c count'



# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R374 UA treasure dial pin audit' in s:
    already.append('regtest.cpp: the R374 audit')
else:
    INC_ANCH = ('#include "rules/uacomnote.h"  // '
        'R373: the UA comeliness note')
    INC_NEW = NL.join([
        '#include "rules/uacomnote.h"  // R373: the UA comeliness note',
        '#include "rules/uatreasuredial.h"  // R374: the UA treasure dial'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R374: the UA treasure
    // dial pin audit ----
    // THE DECISION round: the UA
    // random determination tables
    // III.A through III.H REPLACE
    // the DMG tables; the engine
    // carries both as switchable
    // alternatives behind a dial
    // (DMG / UA / MERGED) and
    // playtesting picks. The DMG
    // mode stays the default - the
    // seventy landed audits remain
    // authoritative until the UA
    // pin rounds land. The R219
    // seam cross-checks the map
    // table bands; the R220 seam
    // the hoard bands; no item
    // flips this round - the
    // decision record lands; the
    // census 300 -> 301.
    {
        using namespace rules;
        int bad = 0;
        // ---- the dial pins ----
            if (uatdModeDmg() != 0) ++bad;
            if (uatdModeUa() != 1) ++bad;
            if (uatdModeMerged() != 2) ++bad;
            if (uatdModeCount() != 3) ++bad;
            if (uatdDefaultMode()
                    != uatdModeDmg()) ++bad;
            if (!uatdRunBothDecided()) ++bad;
            if (!uatdUaTablesReplaceDmg())
                ++bad;
            if (!uatdDmgAuditsAuthoritative())
                ++bad;
            if (uatdDmgAuditRoundFirst()
                    != 219) ++bad;
            if (uatdDmgAuditRoundLast()
                    != 287) ++bad;
            if (!uatdMonsterFileTracksSource())
                ++bad;
            if (!uatdPlaytestingPicks()) ++bad;
            if (!uatdUaPinRoundsPending())
                ++bad;
            if (uatdTableSetCount() != 2) ++bad;
            if (!uatdMergedCarriesBoth()) ++bad;
        // ---- the R219 seam ----
            // the map-or-magic roll:
            // 01-10 the Map Table,
            // 11-00 the Magic Items
            // Table
            if (mapOrMagicIsMap(1) != 1) ++bad;
            if (mapOrMagicIsMap(10) != 1) ++bad;
            if (mapOrMagicIsMap(11) != 0) ++bad;
            if (mapOrMagicIsMap(100) != 0)
                ++bad;
        // ---- the R220 seam ----
            // the combined hoard: ten
            // bands, 01-20 b0 through
            // 97-00 b9; the hoard must
            // be hidden, trapped and
            // guarded, in distant
            // places
            if (hoardBandCount() != 10) ++bad;
            if (hoardBandOfRoll(1) != 0) ++bad;
            if (hoardBandOfRoll(20) != 0) ++bad;
            if (hoardBandOfRoll(21) != 1) ++bad;
            if (hoardBandOfRoll(55) != 2) ++bad;
            if (hoardBandOfRoll(100) != 9)
                ++bad;
            if (!hoardMustBeHiddenTrappedGuarded())
                ++bad;
            if (!hoardDistantPlaces()) ++bad;
        printf("R374 UA treasure dial pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R374 audit')
s = rd(RT)
assert s.count(
    'R374 UA treasure dial pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 301, 'd census 301'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uatreasuredial.h"'
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
    'R374 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R374 note: the treasure dial',
    'decision round - RUN BOTH:',
    'the DMG and UA tables ride as',
    'switchable alternatives behind',
    'a dial (DMG the default, UA,',
    'MERGED), playtesting picks;',
    'the R219 seam the map bands,',
    'the R220 seam the hoard',
    'bands; the decision record',
    'lands, no item flips; the',
    'census 300 -> 301'
])
print(NOTE)
print('commit: R374: the UA treasure')
print('dial decision round (census 301)',)

