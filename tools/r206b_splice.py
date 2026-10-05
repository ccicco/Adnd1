#!/usr/bin/env python3
# R206b splice: the R206 audit fix - two bad
# assertions in the pursuit and evasion audit
# block, both found by the Termux preflight
# (bad 2):
#   1. the food confirm polarity: at 100
#     percent the print says the distraction
#     is automatic - NO second d10 - so
#     foodDistractionSucceeds(100, 1) rightly
#     returns true; the audit read true as
#     bad. The header is correct; the
#     assertion lacked its bang.
#   2. the third assembly cell: 80 + 0 - 50 -
#     20 + 10 - 10 = 10 (the +10 is the
#     over-24-pursuers band; the R206 comment
#     arithmetic dropped it), so the pinned
#     value is 10, not 0.
# The header (rules/pursuit.h) is unchanged -
# both bugs lived in the audit block only.
# Patches: 1 (regtest.cpp, the two assertions
# and the assembly comment). Census stays 122.

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
# Patch 1: regtest.cpp - the food confirm polarity
# (at 100 percent the distraction is automatic:
# the function returning true is CORRECT - the
# assertion lacked its bang)
# ---------------------------------------------------------------------------

old1 = ('        if (rules::foodDistractionSucceeds(100, 1) ||'
        + NL + '            !rules::foodDistractionSucceeds(80, 8) ||')

new1 = ('        // at 100 percent the distraction is automatic -'
        + NL + '        // the print spares the second d10 - so the'
        + NL + '        // function returns true: pinned as correct'
        + NL + '        if (!rules::foodDistractionSucceeds(100, 1) ||'
        + NL + '            !rules::foodDistractionSucceeds(80, 8) ||')

patch('regtest.cpp',
      'the print spares the second d10',
      old1,
      new1)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the third assembly cell
# (the +10 of the over-24-pursuers band was
# dropped in the comment arithmetic; the true
# pinned value is 10)
# ---------------------------------------------------------------------------

old2 = ('        // 30 = 80; and a 12-member party, equal'
        + NL + '        // speed, plain, twilight, 30 pursuers -'
        + NL + '        // 80 - 50 - 20 - 10 = 0, the immediate-'
        + NL + '        // confrontation edge'
        + NL + '        if (rules::evadeOutdoorChance(')

new2 = ('        // 30 = 80; and a 12-member party, equal'
        + NL + '        // speed, plain, twilight, 30 pursuers -'
        + NL + '        // 80 - 50 - 20 + 10 - 10 = 10 (the +10'
        + NL + '        // is the over-24-pursuers band)'
        + NL + '        if (rules::evadeOutdoorChance(')

patch('regtest.cpp',
      'is the over-24-pursuers band',
      old2,
      new2)

old3 = ('                12, 30, rules::EVL_TWILIGHT) != 0)')

new3 = ('                12, 30, rules::EVL_TWILIGHT) != 10)')

patch('regtest.cpp',
      'EVL_TWILIGHT) != 10',
      old3,
      new3)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 3, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R206b splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R206b note: 3 patches; both bads were audit-block bugs - the food')
print('confirm polarity (100 percent is automatic, no second d10) and the')
print('third assembly cell (10, the +10 pursuer band); pursuit.h unchanged.')
print('commit: R206b: the R206 audit fix - the food confirm polarity and the')
print('third assembly cell (census 122)')

