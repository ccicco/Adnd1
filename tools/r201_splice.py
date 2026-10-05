#!/usr/bin/env python3
# R201 splice: the NPC monk alignment split - the
# monk prose pin: "Non-player character monks
# will be aligned as follows: 50% lawful good,
# 35% lawful neutral, 15% lawful evil." The
# engine pins the subclass alignment gates
# (subclassgates.h: monk LAWFUL_ONLY) but not
# the NPC generation split. Engine shape in
# rules/subclassspecials.h: three percent
# accessors plus the cumulative dice-range
# helpers for a d100 roll - monkNpcAlignLawful-
# GoodPercent 50, monkNpcAlignLawfulNeutral-
# Percent 35, monkNpcAlignLawfulEvilPercent 15,
# and monkNpcAlignRollRange(lo, hi) giving the
# d100 band for each alignment (LG 1-50, LN
# 51-85, LE 86-100) - the census splits sum to
# 100, the bands are contiguous and cover the
# die. The PC alignment stays gated by
# SUB_ALIGN_LAWFUL_ONLY - this split is NPC
# generation data.
# Patches: 2 (subclassspecials.h, regtest.cpp).
# Census 117 -> 118 (one new audit).

BS = chr(92)
NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique
    global applied, already
    t = rd(path)
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/subclassspecials.h - the NPC alignment split
# (anchored between the falling-ladder close and the surprise
# ladder comment - a comment landmark, never an opening line)
# ---------------------------------------------------------------------------

old1 = ('inline bool monkWallAssistedFallRequiresContact() {'
        + NL + '    return true;'
        + NL + '}'
        + NL
        + NL + '// ---- the monk surprise ladder ----')

new1 = ('inline bool monkWallAssistedFallRequiresContact() {'
        + NL + '    return true;'
        + NL + '}'
        + NL
        + NL + '// ---- R201: the NPC monk alignment split ----'
        + NL + '//'
        + NL + '// The monk prose pin: non-player character monks'
        + NL + '// align 50% lawful good, 35% lawful neutral, 15%'
        + NL + '// lawful evil. The PC gate stays SUB_ALIGN_LAWFUL_'
        + NL + '// ONLY (rules/subclassgates.h); this split is NPC'
        + NL + '// generation data.'
        + NL + 'inline int monkNpcAlignLawfulGoodPercent() { return 50; }'
        + NL
        + NL + 'inline int monkNpcAlignLawfulNeutralPercent() { return 35; }'
        + NL
        + NL + 'inline int monkNpcAlignLawfulEvilPercent() { return 15; }'
        + NL
        + NL + '// The cumulative d100 band for each NPC alignment'
        + NL + '// index - 0 lawful good, 1 lawful neutral, 2 lawful'
        + NL + '// evil. The bands are contiguous and cover the die:'
        + NL + '// LG 1-50, LN 51-85, LE 86-100. Index out of range'
        + NL + '// returns the whole die (0-100 miss band).'
        + NL + 'inline void monkNpcAlignRollRange(int index,'
        + NL + '                                    int& lo, int& hi) {'
        + NL + '    if (index == 0) { lo = 1;   hi = 50;  return; }'
        + NL + '    if (index == 1) { lo = 51;  hi = 85;  return; }'
        + NL + '    if (index == 2) { lo = 86;  hi = 100; return; }'
        + NL + '    lo = 0; hi = 100;'
        + NL + '}'
        + NL
        + NL + '// ---- the monk surprise ladder ----')

patch('rules/subclassspecials.h',
      'R201: the NPC monk alignment split',
      old1,
      new1)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the R201 battery audit (census 118)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R201: the NPC monk alignment split audit ----')
a('    // The monk prose: NPC monks align 50% lawful good,')
a('    // 35% lawful neutral, 15% lawful evil - the split sums')
a('    // to 100 and the d100 bands tile the die.')
a('    {')
a('        int bad = 0;')
a('        // the three percents')
a('        if (rules::monkNpcAlignLawfulGoodPercent() != 50) ++bad;')
a('        if (rules::monkNpcAlignLawfulNeutralPercent() != 35) ++bad;')
a('        if (rules::monkNpcAlignLawfulEvilPercent() != 15) ++bad;')
a('        // the census sums to 100')
a('        int sum = rules::monkNpcAlignLawfulGoodPercent()')
a('                  + rules::monkNpcAlignLawfulNeutralPercent()')
a('                  + rules::monkNpcAlignLawfulEvilPercent();')
a('        if (sum != 100) ++bad;')
a('        // the d100 bands: contiguous, in order, cover the die')
a('        static const int kLo[3]  = { 1, 51, 86 };')
a('        static const int kHi[3]  = { 50, 85, 100 };')
a('        for (int i = 0; i < 3; ++i) {')
a('            int lo, hi;')
a('            rules::monkNpcAlignRollRange(i, lo, hi);')
a('            if (lo != kLo[i]) ++bad;')
a('            if (hi != kHi[i]) ++bad;')
a('        }')
a('        // the contiguity: each band starts at the prior plus one')
a('        for (int i = 1; i < 3; ++i) {')
a('            int lo, hi, plo, phi;')
a('            rules::monkNpcAlignRollRange(i, lo, hi);')
a('            rules::monkNpcAlignRollRange(i - 1, plo, phi);')
a('            if (lo != phi + 1) ++bad;')
a('            if (lo > hi) ++bad;')
a('        }')
a('        // the bands match the percents: LG 50 wide, LN 35, LE 15')
a('        int lo, hi;')
a('        rules::monkNpcAlignRollRange(0, lo, hi);')
a('        if (hi - lo + 1')
a('            != rules::monkNpcAlignLawfulGoodPercent()) ++bad;')
a('        rules::monkNpcAlignRollRange(1, lo, hi);')
a('        if (hi - lo + 1')
a('            != rules::monkNpcAlignLawfulNeutralPercent()) ++bad;')
a('        rules::monkNpcAlignRollRange(2, lo, hi);')
a('        if (hi - lo + 1')
a('            != rules::monkNpcAlignLawfulEvilPercent()) ++bad;')
a('        // the out-of-range miss band')
a('        rules::monkNpcAlignRollRange(3, lo, hi);')
a('        if (lo != 0 || hi != 100) ++bad;')
a('        printf("R201 NPC monk alignment audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R200 falling ladder audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R201 NPC monk alignment audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 2, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R201 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R201 note: 2 patches; the NPC monk alignment split lands - 50/35/15')
print('lawful good/neutral/evil with the d100 bands; census 118.')
print('commit: R201: the NPC monk alignment split - the 50/35/15 lawful')
print('good/neutral/evil census with the d100 bands (census 118)')

