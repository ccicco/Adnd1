#!/usr/bin/env python3
# R207b splice: the R207 audit fix - one bad
# assertion in the town taxation audit, found
# by the Termux preflight (bad 1):
#   the entry fee polarity: the print says 1
#     copper a citizen, 5 a non-citizen, and
#     the audit - matching the foreigner-param
#     convention of taxImportDutyPercent -
#     reads the flag as nonCitizen (false = 1,
#     true = 5). The helper declared the flag
#     the other way round (citizen, true = 1),
#     so taxEntryFeeCopper(false) returned 5
#     and the assertion fired. The header is
#     repinned: the flag is nonCitizen, true
#     pays the 5. The audit is correct and
#     unchanged; every other assertion in the
#     block checks against the print.
# Patches: 1 (rules/taxation.h, the entry fee
# helper). Census stays 123.

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
# Patch 1: rules/taxation.h - the entry fee
# polarity repin (the flag is nonCitizen: the
# convention of the duty helper, true pays 5)
# ---------------------------------------------------------------------------

old1 = ('inline int taxEntryFeeCopper(bool citizen) {'
        + NL + '    return citizen ? 1 : 5;'
        + NL + '}')

new1 = ('inline int taxEntryFeeCopper(bool nonCitizen) {'
        + NL + '    // R207b: true = the 5 cp non-citizen fee'
        + NL + '    return nonCitizen ? 5 : 1;'
        + NL + '}')

patch('rules/taxation.h',
      'R207b: true = the 5 cp non-citizen fee',
      old1,
      new1)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 1, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R207b splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R207b note: 1 patch; the bad was the entry fee polarity - the')
print('flag is nonCitizen (the duty-helper convention), true pays the')
print('5; the audit block is correct and unchanged; census stays 123.')
print('commit: rides the R207 commit - R207: the town taxation system')
print('pinned - DMG p.90, the worked example town (census 123)')

