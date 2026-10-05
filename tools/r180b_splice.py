#!/usr/bin/env python3
# R180b splice: the R180 build fix (the R179b pattern).
#
# The R180 audit probed rules::RACE_HALFELF but the enum
# in rules/races.h is RACE_HALF_ELF - one identifier, one
# line, preflight RED with a single compile error. The
# census failures were all downstream of the missing
# binary. This splice renames the probe to the real enum
# name. No new audit; census stays 97.
#
# Patches: 1.

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


# Patch 1: regtest.cpp - the probe identifier fix

path = 'regtest.cpp'
old_id = 'RACE_HALFELF'
new_id = 'RACE_HALF_ELF'

t = rd(path)
if old_id not in t:
    already += 1
else:
    assert t.count(old_id) == 1, 'anchor not unique: ' + old_id
    t = t.replace(old_id, new_id)
    assert old_id not in t, 'old id remains post-patch'
    assert '1, rules::' + new_id + ')) ++bad;' in t, 'fixed probe line missing'
    wr(path, t)
    applied += 1

# the tail (always prints)

assert applied + already == 1, 'patch count drift'
print('R180b splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R180b note: 1 patch; the RACE_HALF_ELF probe rename;')
print('census stays 97 (no new audit)')
print('commit: R180b: the R180 audit probe RACE_HALF_ELF fix (census 97)')

