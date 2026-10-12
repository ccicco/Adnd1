
# R373: the UA comeliness note pin
# round (p. 74) plus the weapon
# descriptions close: the DM
# pointer - the attribute fully
# described on pages 6 and 7 of
# this volume, while it might
# more properly be called a
# characteristic, it does have
# effects (in game terms) upon
# those viewing or reacting to
# the character; the new weapon
# descriptions item rides the
# R340 pins (the 16-entry
# roster with the 14 item-list
# types); the R322 seam
# cross-checks the creation
# roll and the charisma ladder,
# the R340 seam the roster, the
# R337 seam the pole-arm rows;
# two items flip CLOSED; the
# census 299 -> 300.
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



# ---- (a) the seed: the R372 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R372 landed 2026-10-12: commit',
    '  25881ba, census 299, the UA',
    '  cavalier followers pin round',
    '  (rules/uafollowers.h): the',
    '  men-at-arms dice ladder (all d4,',
    '  non-cumulative, the no-gain',
    '  rule), the four equipment',
    '  percentile rows with both',
    '  outfits each and the medium',
    '  warhorses at 91-00, the leader',
    '  rules, the neutral-cause and',
    '  evil-bandit reads with the 1',
    '  and 5 percent monster chances,',
    '  the henchman bonus and type',
    '  table, the retainer ladder',
    '  (the Knight prose conflict',
    '  flagged), the paladin',
    '  retainers; the R368 seam the',
    '  title cells, the R371 seam the',
    '  armor costs; two items CLOSED;',
    '  GREEN on the first run.'
])
s = rd(SD)
if 'R372 landed 2026-10-12' in s:
    already.append('seed: the R372 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R372 record')
s = rd(SD)
assert s.count(
    'R372 landed 2026-10-12'
) == 1, 'a entry'
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



# ---- (b) NEW rules/uacomnote.h ----
P = 'rules/uacomnote.h'
if os.path.exists(P) and 'R373' in rd(P):
    already.append('uacomnote.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uacomnote.h
// The UA COMELINESS CREATION NOTE
// (p. 74) pins, R373: the DM
// pointer in the DM section's
// CHARACTER ABILITIES - the
// attribute fully described on
// pages 6 and 7 of this volume,
// while it might more properly be
// called a characteristic, it
// does have effects (in game
// terms) upon those viewing or
// reacting to the character. The
// creation ride: the R322 pins
// carry the roll and the
// adjustments - checked in the
// regtest audit, not here. The
// trailing sentence of the
// printed note garbles in the
// extract - flagged.
namespace rules {

// The pointer pages of this
// volume.
inline int uacmPointerFirstPage()
    { return 6; }

inline int uacmPointerSecondPage()
    { return 7; }

// The attribute is fully
// described on the pointer
// pages.
inline bool uacmFullyDescribedOnPointerPages()
    { return true; }

// While it might more properly
// be called a characteristic.
inline bool uacmMoreProperlyCharacteristic()
    { return true; }

// It does have effects in game
// terms upon those viewing the
// character.
inline bool uacmAffectsViewers()
    { return true; }

// ... upon those reacting to the
// character.
inline bool uacmAffectsReactors()
    { return true; }

// "As shown above, human player"
// - the human example opens
// before the extract garbles.
inline bool uacmShownAboveForHumans()
    { return true; }

// The trailing sentence garbles
// beyond decode - a hole
// awaiting the PDF.
inline bool uacmTrailingSentenceGarbles()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uacomnote.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 8, 'b inline count'
assert s.count('R373') == 1, 'b round tag'
assert s.count(
    'uacmPointerFirstPage'
    ) >= 1, 'b fn'
assert 'uafol' not in s, 'b no uafol ref'
assert 'uanw' not in s, 'b no uanw ref'
assert 'uawt' not in s, 'b no uawt ref'
assert 'uamt' not in s, 'b no uamt ref'
assert 'uaarm' not in s, 'b no uaarm ref'
assert 'uacavt' not in s, 'b no uacavt ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the two closes ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **The comeliness creation note**' in s:
    already.append('gap: the comeliness note close')
else:
    OLD = NL.join([
        '- [ ] **The comeliness creation note**',
        '      (p. 74) - the DM pointer; rides',
        '      the R322 pins.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [x] **The comeliness creation note**',
        '      (p. 74) - the DM pointer; rides',
        '      the R322 pins.',
        '      - CLOSED R373: the pin round',
        '        (rules/uacomnote.h) - the DM',
        '        pointer to pages 6 and 7, the',
        '        characteristic read, the',
        '        effects on viewers and',
        '        reactors; the R322 seam',
        '        cross-checks the creation',
        '        roll and the charisma',
        '        ladder; the trailing',
        '        sentence garbles - flagged;',
        '        CLOSED.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the comeliness note close')
if '- [x] **The new weapon descriptions**' in s:
    already.append('gap: the weapon descriptions close')
else:
    OLD = NL.join([
        '- [ ] **The new weapon descriptions**',
        '      (pp. 77-79) - the 14 named types',
        '      (see the players section item);',
        '      the pole-arm cross-refs point to',
        '      Appendix T.'
    ])
    assert s.count(OLD) == 1, 'c2 old'
    NEW = NL.join([
        '- [x] **The new weapon descriptions**',
        '      (pp. 77-79) - the 14 named types',
        '      (see the players section item);',
        '      the pole-arm cross-refs point to',
        '      Appendix T.',
        '      - CLOSED R373: rides the R340',
        '        pins (rules/uanewweapons.h) -',
        '        the 16-entry roster with the',
        '        14 item-list types marked; the',
        '        R337 seam cross-checks the',
        '        pole-arm rows (the hook',
        '        fauchard, the man catcher,',
        '        the lasso, the harpoon); the',
        '        residual OCR holes (the',
        '        harpoon failure-damage cell,',
        '        the khopesh leverage',
        '        sentence, the lasso severing',
        '        mechanics) await the PDF -',
        '        flagged; CLOSED.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the weapon descriptions close')
wr(GP, s)

# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [x] **The comeliness creation note**'
) == 1, 'c1 flip'
assert s.count(
    '- [x] **The new weapon descriptions**'
) == 1, 'c2 flip'
assert s.count(
    '(rules/uacomnote.h) - the'
) == 1, 'c uacomnote note'
assert s.count(
    '(rules/uanewweapons.h) -'
) == 2, 'c uanewweapons notes'
assert s.count(
    '- [ ] **The new weapons**'
) == 1, 'c players weapons kept open'
assert s.count(
    '- [x] **The cavalier follower tables**'
) == 1, 'c r372 followers kept closed'
assert s.count(
    '- [x] **The henchman rules**'
) == 1, 'c r372 henchman kept closed'
assert s.count(
    '- [x] **The expanded armor table**'
) == 1, 'c r371 table kept closed'
assert s.count(
    '- [x] **Warhorses and barding**'
) == 1, 'c r370 kept closed'
assert s.count(
    '- [x] **Cavaliers Table I**'
) == 1, 'c r368 kept closed'
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
if 'R373 UA comeliness note pin audit' in s:
    already.append('regtest.cpp: the R373 audit')
else:
    INC_ANCH = ('#include "rules/uafollowers.h"  // '
        'R372: the UA cavalier followers')
    INC_NEW = NL.join([
        '#include "rules/uafollowers.h"  // R372: the UA cavalier followers',
        '#include "rules/uacomnote.h"  // R373: the UA comeliness note'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R373: the UA comeliness
    // note pin audit ----
    // The UA comeliness creation
    // note (p. 74): the DM
    // pointer - the attribute fully
    // described on pages 6 and 7
    // of this volume, while it
    // might more properly be
    // called a characteristic, it
    // does have effects in game
    // terms upon those viewing or
    // reacting to the character.
    // The item rides the R322
    // pins; the weapon descriptions
    // item rides the R340 pins. The
    // R322 seam cross-checks the
    // creation roll and the charisma
    // ladder; the R340 seam the
    // 16-entry roster with the 14
    // item-list types; the R337
    // seam the pole-arm rows; two
    // items flip CLOSED; the census
    // 299 -> 300.
    {
        using namespace rules;
        int bad = 0;
        // ---- the note pins ----
            if (uacmPointerFirstPage() != 6)
                ++bad;
            if (uacmPointerSecondPage() != 7)
                ++bad;
            if (!uacmFullyDescribedOnPointerPages())
                ++bad;
            if (!uacmMoreProperlyCharacteristic())
                ++bad;
            if (!uacmAffectsViewers()) ++bad;
            if (!uacmAffectsReactors()) ++bad;
            if (!uacmShownAboveForHumans())
                ++bad;
            if (!uacmTrailingSentenceGarbles())
                ++bad;
        // ---- the R322 seam ----
            // the creation roll and the
            // charisma ladder the note
            // rides
            if (uaComelinessBaseDieCount() != 3)
                ++bad;
            if (uaComelinessBaseDieSides() != 6)
                ++bad;
            if (uaComelinessChaAdj(2) != -8)
                ++bad;
            if (uaComelinessChaAdj(3) != -5)
                ++bad;
            if (uaComelinessChaAdj(4) != -3)
                ++bad;
            if (uaComelinessChaAdj(8) != -1)
                ++bad;
            if (uaComelinessChaAdj(9) != 0)
                ++bad;
            if (uaComelinessChaAdj(15) != 1)
                ++bad;
            if (uaComelinessChaAdj(16) != 2)
                ++bad;
            if (uaComelinessChaAdj(17) != 2)
                ++bad;
            if (uaComelinessChaAdj(18) != 3)
                ++bad;
            if (uaComelinessChaAdj(19) != 5)
                ++bad;
            if (uaComelinessBand(-16) != 0)
                ++bad;
            if (uaComelinessBand(-9) != 1)
                ++bad;
            if (uaComelinessBand(0) != 2)
                ++bad;
            if (uaComelinessBand(30) != 9)
                ++bad;
        // ---- the R340 seam ----
            // the 16-entry roster with
            // the 14 item-list types
            if (uanwCount() != 16) ++bad;
            int inList = 0;
            for (int i = 0; i < 16; ++i)
                if (uanwInGapItemList(i))
                    ++inList;
            if (inList != 14) ++bad;
            if (strcmp(uanwName(0), "Aklys") != 0)
                ++bad;
            if (strcmp(uanwName(4),
                    "Crossbow, Hand-held") != 0)
                ++bad;
            if (strcmp(uanwName(13),
                    "Sword, Falchion") != 0) ++bad;
            if (strcmp(uanwName(15), "Whip") != 0)
                ++bad;
            if (uanwHookFauchardDismountPct()
                    != 20) ++bad;
            if (uanwManCatcherPoleCuttingDmg()
                    != 6) ++bad;
            if (!uanwStaffSlingMediumOrLongOnly())
                ++bad;
        // ---- the R337 seam ----
            // the pole-arm cross-refs
            // ride the data rows
            {
                bool hook = false, mc = false,
                     lasso = false, harp = false;
                int n = uawtRowCount();
                for (int i = 0; i < n; ++i) {
                    const char* w = uawtName(i);
                    if (strcmp(w,
                            "Hook Fauchard") == 0)
                        hook = true;
                    if (strcmp(w,
                            "Man Catcher") == 0)
                        mc = true;
                    if (strcmp(w, "Lasso") == 0)
                        lasso = true;
                    if (strcmp(w, "Harpoon") == 0)
                        harp = true;
                }
                if (!hook || !mc || !lasso || !harp)
                    ++bad;
            }
        printf("R373 UA comeliness note pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R373 audit')
s = rd(RT)
assert s.count(
    'R373 UA comeliness note pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 300, 'd census 300'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uacomnote.h"'
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
        'rules/uafollowers.h'):
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
assert len(applied) + len(already) == 5, 'd count'


# ---- the summary ----
print(
    'R373 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R373 note: the comeliness note',
    'and weapon descriptions round -',
    'the DM pointer pins (the pages',
    '6 and 7, the characteristic',
    'read, the viewers and',
    'reactors), the weapon item',
    'rides the R340 pins; the R322',
    'seam the creation roll and',
    'charisma ladder, the R340 seam',
    'the roster with the 14 types,',
    'the R337 seam the pole-arm',
    'rows; two items flip CLOSED;',
    'the census 299 -> 300'
])
print(NOTE)
print('commit: R373: the UA comeliness')
print('note pin round (census 300)',)

