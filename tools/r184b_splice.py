#!/usr/bin/env python3
# R184b splice: the R184 audit probe fix (the R180b
# pattern - the preflight caught a bad audit line
# BEFORE the push).
#
# The R184 audit used a WRONG negative probe:
# rangerIsGiantClass("ogre") was expected to return
# false, but "ogre" IS one of the 11 printed
# giant-class creatures - the exact-match predicate
# is correct, the probe is not. The census failures
# were all downstream of the audit early return.
# This splice replaces the bad probe with a
# genuinely non-listed creature ("lizard man").
# The header is untouched; census stays 101.
#
# Runs against the UNCOMMITTED R184 state (the
# R184 splice is applied but not pushed).
#
# Patches: 1.

NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


# Patch 1: regtest.cpp - the bad negative probe

path = 'regtest.cpp'
old_probe = 'if (rules::rangerIsGiantClass("ogre")) ++bad;'
new_probe = 'if (rules::rangerIsGiantClass("lizard man")) ++bad;'
marker = 'R184b: the ogre probe fix'

t = rd(path)
if marker in t:
    already += 1
else:
    assert t.count(old_probe) == 1, 'the ogre probe line not found or not unique'
    # sanity: the fix must not collide with the positive probes
    assert 'rangerIsGiantClass("ogre mage")' in t, 'positive ogre mage probe missing'
    assert 'rangerIsGiantClass("lizard man")' not in t, 'fix already half-present'
    t = t.replace(old_probe, new_probe)
    assert old_probe not in t, 'old probe remains post-patch'
    assert t.count(new_probe) == 1, 'fixed probe not unique'
    # the round marker rides in a comment beside the fix
    t = t.replace(new_probe,
                  new_probe[:-len(' ++bad;')]
                  + ' ++bad;  // ' + marker)
    assert marker in t, 'marker missing post-patch'
    wr(path, t)
    applied += 1

# the tail (always prints)

assert applied + already == 1, 'patch count drift'
print('R184b splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R184b note: 1 patch; the lizard-man probe rename;')
print('the header is untouched (md5 unchanged); census 101')
print('commit: R184: the paladin and ranger spell layers pinned -')
print('the progressions, the wiring and the specials (census 101)')

