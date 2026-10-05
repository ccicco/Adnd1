#!/usr/bin/env python3
# R192b splice: the R192 audit Dice fix (the
# preflight caught 4 compile errors in the
# R192 battery audit - the R180b lesson
# again: identifiers must be copied from the
# actual header, never from memory).
#
# rules::Dice has NO default constructor and
# NO seed() - it wraps a rules::Rng& (the
# Rng owns the seed). The established regtest
# idiom: rules::Rng rngN(seed); rules::Dice
# d(rngN). The R192 failure-roll block is
# rewritten with three seeded Rng locals
# (first d100 capture, the wis-12 failure
# roll, the wis-13 never-fail probe).
#
# The census FAILs are all downstream of the
# missing binary (the R180b wall - fix the
# compile, not the census).
#
# Patches: 1.

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
# Patch 1: regtest.cpp - the Dice fix (the Rng owns the seed)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules::Rng r192(2026);',
      '            rules::Dice d;'
      + NL + '            d.seed(2026);'
      + NL + '            int first = (int)d.d100();'
      + NL + '            d.seed(2026);'
      + NL + '            bool failed = spells::rollClericSpellFailure(d, 12);'
      + NL + '            if (failed != (first <= 5)) ++bad;'
      + NL + '            // wis 13+: pct 0, never fails, no roll'
      + NL + '            d.seed(2026);'
      + NL + '            if (spells::rollClericSpellFailure(d, 13)) ++bad;',
      '            rules::Rng r192(2026);'
      + NL + '            rules::Dice d(r192);'
      + NL + '            int first = (int)d.d100();'
      + NL + '            rules::Rng r192b(2026);'
      + NL + '            rules::Dice db(r192b);'
      + NL + '            bool failed = spells::rollClericSpellFailure(db, 12);'
      + NL + '            if (failed != (first <= 5)) ++bad;'
      + NL + '            // wis 13+: pct 0, never fails, no roll'
      + NL + '            rules::Rng r192c(2026);'
      + NL + '            rules::Dice dc(r192c);'
      + NL + '            if (spells::rollClericSpellFailure(dc, 13)) ++bad;')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 1, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R192b splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R192b note: 1 patch; the Dice fix - the Rng owns the seed;')
print('census stays 109 (the audit printf is unchanged).')
print('commit: R192: the wisdom tables pinned - the bonus spells,')
print('the spell failure and the high-circle gates wired (census 109)')

