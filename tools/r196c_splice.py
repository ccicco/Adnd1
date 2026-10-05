#!/usr/bin/env python3
# R196c splice: the band-shape audit guard (the bad 7).
#
# The R196 preflight ran RED with "R196 INT table II
# audit: bad 7" - and the 7 is the tell: the band-shape
# loop walks i = 9..25, and the 19+ row pins 10/All =
# 10/-1, so `lo > hi` fired for exactly the 7 scores 19
# through 25. The comment said "-1 reads as unlimited"
# but the check never special-cased it. Every other cell
# (pct and min/max) is right against the print - the
# PHB INTELLIGENCE TABLE II: 9 35%, 10-12 45%, 13-14
# 55%, 15-16 65%, 17 75%, 18 85%, 19+ 95%, and 4/6,
# 5/7, 6/9, 7/11, 8/14, 9/18, 10/All.
#
# LESSON (carved): pre-asserting the audit ARRAYS is not
# enough - simulate the audit's full LOGIC (loops, probes,
# edge rows) in Python before shipping it. The unlimited
# sentinel (-1) breaks naive range checks; guard it.
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
# Patch 1: regtest.cpp - guard the unlimited sentinel in the band-shape check
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'if (hi >= 0 && lo > hi) ++bad;   // R196c: -1 is unlimited',
      ('            int lo = spells::minSpellsPerLevel((uint8_t)i);'
       + NL + '            int hi = spells::maxSpellsPerLevel((uint8_t)i);'
       + NL + '            if (lo > hi) ++bad;   // -1 reads as unlimited'),
      ('            int lo = spells::minSpellsPerLevel((uint8_t)i);'
       + NL + '            int hi = spells::maxSpellsPerLevel((uint8_t)i);'
       + NL + '            if (hi >= 0 && lo > hi) ++bad;   // R196c: -1 is unlimited'))

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 1, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R196c splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R196c note: 1 patch; the band-shape audit now guards the')
print('unlimited sentinel - the 19+ All row stops counting bad.')
print('census stays 113.')
print('commit: R196: the INT Table II repinned - the chance-to-know')
print('percents and the spells-per-level columns (census 113)')

