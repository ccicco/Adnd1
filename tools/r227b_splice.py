#!/usr/bin/env python3
# R227b splice: the printf fix - ONE patch.
# R227 landed with the BS variable (a PYTHON-side
# chr(92) constant) leaked into the GENERATED
# C++ audit line:
#   printf("..." + BS + "n", bad);
# which is invalid C++ (undeclared identifier
# BS) - the ONE compile error; the census wall
# was downstream of the missing binary (the
# R179b/R180b pattern). The hygiene rule (zero
# backslash chars in the SPLICE) is met by
# PYTHON-SIDE concatenation: the fixed C++ line
# is built as '...%d' + BS + 'n", bad);' so the
# OUTPUT regtest.cpp carries the real backslash
# escape while this splice stays backslash-free.
# Marker = the fixed C++ line (absent pre-patch,
# present post-patch; single line).

NL = chr(10)
BS = chr(92)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
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
# Patch 1: regtest.cpp - the R227 audit printf line
# ---------------------------------------------------------------------------

# the broken C++ the R227 splice wrote (BS is a
# python constant; the C++ never declared it):
old1 = ('        printf("R227 wis mental save wiring audit: bad %d" + BS + "n", bad);')

# the fixed C++ line, built python-side so this
# splice itself carries no backslash character:
new1 = ('        printf("R227 wis mental save wiring audit: bad %d' + BS +
        'n", bad);')

patch('regtest.cpp',
      'R227 wis mental save wiring audit: bad %d' + BS + 'n',
      old1,
      new1)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 1, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R227b splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R227b note: 1 patch; the BS leak in the R227 audit printf fixed -')
print('python-side concatenation, the C++ line now carries the real escape.')
print('commit: R227+R227b: the Wisdom Table I save wire wired - PHB p.11,')
print('the magical defense adjustment on mental-form spell saves (census 143)')

