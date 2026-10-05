#!/usr/bin/env python3
# R195 splice: the INT Table I repin (PHB
# divergence 4 of the R177 founding read -
# the LAST founding-read divergence).
#
# rules/character.cpp: intExtraLanguages
# repinned to the printed INTELLIGENCE
# TABLE I additional-languages column (3-7
# none, 8-9 one, 10-11 two, 12-13 three,
# 14-15 four, 16 five, 17 six, 18 seven).
# The engine convention diverged at every
# score above 3 (it read 4-5 one, 6-8
# two, 9-12 three, 13-15 four, 16-17 five,
# 18 six). Display-only accessor - no
# callers beyond the declaration.
#
# regtest.cpp: the R195 battery audit walks
# the printed column cell for cell (all 16
# scores) plus the clamps. Census 112.
#
# Patches: 6.

BS = chr(92)
NL = chr(10)
Q = chr(39)
DQ = chr(34)

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
# Patch 1: rules/character.cpp - the intExtraLanguages repin
# ---------------------------------------------------------------------------

patch('rules/character.cpp',
      'if (int_ <= 7)  return 0;   // R195: was 2 at 6-8',
      '// INT (PHB p.10): number of additional languages beyond native tongue'
      + NL + '//   3: none; 4-5: +1; 6-8: +2; 9-12: +3 (bonus language allowed);'
      + NL + '//   13-15: +4; 16-17: +5; 18: +6 (literacy per INT table is a display'
      + NL + '//   concern, not encoded here)'
      + NL + '// ----------------------------------------------------------------------------'
      + NL
      + NL + 'int intExtraLanguages(uint8_t int_) {'
      + NL + '    if (int_ <= 3)   return 0;'
      + NL + '    if (int_ <= 5)   return 1;'
      + NL + '    if (int_ <= 8)   return 2;'
      + NL + '    if (int_ <= 12)  return 3;'
      + NL + '    if (int_ <= 15)  return 4;'
      + NL + '    if (int_ <= 17)  return 5;'
      + NL + '    return 6;   // 18'
      + NL + '}',
      '// INT: the INTELLIGENCE TABLE I additional-languages'
      + NL + '// column - REPINNED R195 to the print (3-7 none,'
      + NL + '// 8-9 one, 10-11 two, 12-13 three, 14-15 four,'
      + NL + '// 16 five, 17 six, 18 seven). The engine'
      + NL + '// convention diverged at every score above 3.'
      + NL + '// Display-only (literacy is a display concern,'
      + NL + '// not encoded).'
      + NL + '// ----------------------------------------------------------------------------'
      + NL
      + NL + 'int intExtraLanguages(uint8_t int_) {'
      + NL + '    if (int_ <= 7)  return 0;   // R195: was 2 at 6-8'
      + NL + '    if (int_ <= 9)  return 1;   // 8, 9'
      + NL + '    if (int_ <= 11) return 2;   // 10, 11'
      + NL + '    if (int_ <= 13) return 3;   // 12, 13'
      + NL + '    if (int_ <= 15) return 4;   // 14, 15'
      + NL + '    if (int_ == 16) return 5;'
      + NL + '    if (int_ == 17) return 6;'
      + NL + '    return 7;   // 18'
      + NL + '}')

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the R195 battery audit (census 112)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R195: the INT languages repin audit ----')
a('    // The printed INTELLIGENCE TABLE I additional-')
a('    // languages column, cell for cell.')
a('    {')
a('        int bad = 0;')
a('        // the printed column (3 through 18):')
a('        // none through 7, then one per two scores')
a('        // up to seven at 18')
a('        static const int kLang[16] = {')
a('            0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3,')
a('            4, 4, 5, 6, 7')
a('        };')
a('        for (int i = 3; i <= 18; ++i) {')
a('            if (rules::intExtraLanguages((uint8_t)i)')
a('                != kLang[i - 3]) ++bad;')
a('        }')
a('        // the clamps read the edge rows')
a('        if (rules::intExtraLanguages(0) != 0) ++bad;')
a('        if (rules::intExtraLanguages(99) != 7) ++bad;')
a('        // the historically divergent cells, the R177 read:')
a('        // the engine convention gave a language at 4-5')
a('        if (rules::intExtraLanguages(4) != 0) ++bad;')
a('        if (rules::intExtraLanguages(6) != 0) ++bad;')
a('        if (rules::intExtraLanguages(9) != 1) ++bad;')
a('        if (rules::intExtraLanguages(17) != 6) ++bad;')
a('        if (rules::intExtraLanguages(18) != 7) ++bad;')
a('        printf("R195 INT languages repin audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert the audit array against the print
kLang = [0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 7]
assert len(kLang) == 16
assert kLang[3 - 3] == 0 and kLang[7 - 3] == 0
assert kLang[8 - 3] == 1 and kLang[9 - 3] == 1
assert kLang[10 - 3] == 2 and kLang[11 - 3] == 2
assert kLang[12 - 3] == 3 and kLang[13 - 3] == 3
assert kLang[14 - 3] == 4 and kLang[15 - 3] == 4
assert kLang[16 - 3] == 5 and kLang[17 - 3] == 6 and kLang[18 - 3] == 7

patch('regtest.cpp',
      'R195 INT languages repin audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 3: tools/phb_gap_report.md - the divergence 4 box flipped
# ---------------------------------------------------------------------------

box_old = ('- [~] 4. **INT Table I, additional languages (the'
           + NL + '      INTELLIGENCE TABLE I page)** - the engine'
           + NL + '      ladder diverges at every score above 3; the'
           + NL + '      print reads 3-7 none, 8-9 one, 10-11 two,'
           + NL + '      12-13 three, 14-15 four, 16 five, 17 six,'
           + NL + '      18 seven. Currently display-only.')

box_new = ('- [x] 4. **INT Table I, additional languages (the'
           + NL + '      INTELLIGENCE TABLE I page)** -'
           + NL + '      CLOSED R195: rules/character.cpp'
           + NL + '      intExtraLanguages repinned to the print (3-7'
           + NL + '      none, 8-9 one, 10-11 two, 12-13 three, 14-15'
           + NL + '      four, 16 five, 17 six, 18 seven). The engine'
           + NL + '      convention diverged at every score above 3'
           + NL + '      (4-5 one, 6-8 two, 9-12 three, 13-15 four,'
           + NL + '      16-17 five, 18 six). Display-only accessor,'
           + NL + '      no other callers. The R195 battery audit'
           + NL + '      walks the column cell for cell. Census 112.'
           + NL + '      THE FOUNDING-READ DIVERGENCE LIST IS NOW'
           + NL + '      EMPTY - every PHB ability table is pinned to'
           + NL + '      the print (STR R153, DEX R178c, CON R178c,'
           + NL + '      INT R195, WIS R194, CHA R193).')

t2 = rd('tools/phb_gap_report.md')
if 'CLOSED R195: rules/character.cpp' not in t2:
    assert t2.count(box_old) == 1, 'R195 box anchor not unique'
else:
    assert t2.count(box_old) == 0, 'R195 box old text lingers'

patch('tools/phb_gap_report.md',
      'CLOSED R195: rules/character.cpp',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the intro line repin
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'every founding-read divergence is closed (R178c',
      'divergence 4 (INT) remains the last ranked fix round;'
      + NL + '3 (WIS) CLOSED R194, 5 (CHA) CLOSED R193.',
      'every founding-read divergence is closed (R178c 1-2,'
      + NL + 'R193 5, R194 3, R195 4) - all six PHB ability'
      + NL + 'tables now read the print.')

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R195 landed the INT languages repin',
      'assembles). New R194 battery audit; census 111. Next:'
      + NL + 'the last PHB divergence, 4 (INT languages).',
      'assembles). New R194 battery audit; census 111. Next:'
      + NL + 'the last PHB divergence, 4 (INT languages).'
      + NL + 'R195 landed the INT languages repin (the LAST'
      + NL + 'founding-read divergence, 4): rules/character.cpp'
      + NL + 'intExtraLanguages repinned to the printed'
      + NL + 'INTELLIGENCE TABLE I column (3-7 none through 18'
      + NL + 'seven); the engine convention diverged at every'
      + NL + 'score above 3. New R195 battery audit; census 112.'
      + NL + 'THE FOUNDING-READ LIST IS EMPTY - all six PHB'
      + NL + 'ability tables print-pinned (STR R153, DEX R178c,'
      + NL + 'CON R178c, INT R195, WIS R194, CHA R193). Next:'
      + NL + 'the gap report names the next round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R195 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R195 note: 5 patches; census 112 (one new audit);')
print('commit: R195: the INT languages ladder repinned - the last')
print('founding-read divergence closed (census 112)')

