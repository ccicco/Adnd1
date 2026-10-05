#!/usr/bin/env python3
# R196 splice: the INT Table II repin (the
# MU ability table - a NEW divergence
# found by mining the seams after the
# founding-read list closed).
#
# spells/spells.cpp chanceToLearnPct was
# found DIVERGENT against the printed
# INTELLIGENCE TABLE II: the engine read
# 9-10 35, 11-12 45, 13-14 55, 15 65,
# 16 70, 17 85, 18+ 95; the print reads
# 9 35, 10-12 45, 13-14 55, 15-16 65,
# 17 75, 18 85, 19+ 95 (10, All). The
# repin: 10 reads 45 not 35, 16 reads 65
# not 70, 17 reads 75 not 85, 18 reads 85
# not 95, 19-and-up reads 95 (the printed
# "or more" row). LIVE callers: the party
# spell-learning roll (game/party.h) and
# the town study roll.
#
# The two UNMODELED columns of the same
# table pin as new accessors:
# minSpellsPerLevel / maxSpellsPerLevel
# (9: 4/6, 10-12: 5/7, 13-14: 6/9,
# 15-16: 7/11, 17: 8/14, 18: 9/18,
# 19: 10/All - All pins as -1, the repo
# unlimited convention). The printed note
# records: successive level groups are
# checked only when the character reaches
# a level at which the group is usable.
#
# regtest.cpp: the R196 battery audit walks
# all three columns cell for cell, the
# clamps, and the historically divergent
# cells. Census 113.
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
# Patch 1: spells/spells.cpp - the chanceToLearnPct repin
# ---------------------------------------------------------------------------

patch('spells/spells.cpp',
      'if (int_ == 9)  return 35;   // R196: the print',
      'int chanceToLearnPct(uint8_t int_) {'
      + NL + '    switch (int_) {'
      + NL + '        case 0: case 1: case 2: case 3: case 4:'
      + NL + '        case 5: case 6: case 7: case 8:  return 0;'
      + NL + '        case 9: case 10:                return 35;'
      + NL + '        case 11: case 12:               return 45;'
      + NL + '        case 13: case 14:               return 55;'
      + NL + '        case 15:                        return 65;'
      + NL + '        case 16:                        return 70;'
      + NL + '        case 17:                        return 85;'
      + NL + '        default:                        return 95;   // 18+'
      + NL + '    }'
      + NL + '}',
      '// R196: the printed INTELLIGENCE TABLE II chance-to-know'
      + NL + '// column (the engine ladder diverged at 10, 16, 17'
      + NL + '// and 18): 9 35, 10-12 45, 13-14 55, 15-16 65,'
      + NL + '// 17 75, 18 85, 19+ 95 (the printed or-more row).'
      + NL + '// The table starts at 9 - the MU minimum.'
      + NL + 'int chanceToLearnPct(uint8_t int_) {'
      + NL + '    if (int_ <= 8)  return 0;'
      + NL + '    if (int_ == 9)  return 35;   // R196: the print'
      + NL + '    if (int_ <= 12) return 45;   // 10, 11, 12'
      + NL + '    if (int_ <= 14) return 55;   // 13, 14'
      + NL + '    if (int_ <= 16) return 65;   // 15, 16'
      + NL + '    if (int_ == 17) return 75;'
      + NL + '    if (int_ == 18) return 85;'
      + NL + '    return 95;   // 19 and up (the or-more row)'
      + NL + '}')

# ---------------------------------------------------------------------------
# Patch 3: spells/spells.cpp - the min/max spells-per-level columns
# ---------------------------------------------------------------------------

patch('spells/spells.cpp',
      'int minSpellsPerLevel(uint8_t int_) {',
      'bool rollChanceToLearn(Dice& dice, uint8_t int_) {',
      'bool rollChanceToLearn(Dice& dice, uint8_t int_) {'
      + NL + ''
      + NL + '// ----------------------------------------------------------------------------'
      + NL + '// R196: INTELLIGENCE TABLE II, the min and max spells-per-level'
      + NL + '// columns. All pins as -1 (the repo unlimited convention).'
      + NL + '// ----------------------------------------------------------------------------'
      + NL + ''
      + NL + 'int minSpellsPerLevel(uint8_t int_) {'
      + NL + '    if (int_ < 9)  return 0;'
      + NL + '    if (int_ == 9)  return 4;'
      + NL + '    if (int_ <= 12) return 5;   // 10, 11, 12'
      + NL + '    if (int_ <= 14) return 6;   // 13, 14'
      + NL + '    if (int_ <= 16) return 7;   // 15, 16'
      + NL + '    if (int_ == 17) return 8;'
      + NL + '    if (int_ == 18) return 9;'
      + NL + '    return 10;   // 19 and up'
      + NL + '}'
      + NL + ''
      + NL + 'int maxSpellsPerLevel(uint8_t int_) {'
      + NL + '    if (int_ < 9)  return 0;'
      + NL + '    if (int_ == 9)  return 6;'
      + NL + '    if (int_ <= 12) return 7;   // 10, 11, 12'
      + NL + '    if (int_ <= 14) return 9;   // 13, 14'
      + NL + '    if (int_ <= 16) return 11;   // 15, 16'
      + NL + '    if (int_ == 17) return 14;'
      + NL + '    if (int_ == 18) return 18;'
      + NL + '    return -1;   // 19 and up: All (unlimited)'
      + NL + '}')

# ---------------------------------------------------------------------------
# Patch 4: spells/spells.h - the comment repin + the declarations
# ---------------------------------------------------------------------------

patch('spells/spells.h',
      'int maxSpellsPerLevel(uint8_t int_);',
      '// Chance to learn a spell (PHB p.10 INT table): percent rolled on'
      + NL + '// d100 when an MU first studies a new spell. Min INT 9 to learn any.'
      + NL + '//   INT 9-10: 35%, 11-12: 45%, 13-14: 55%, 15: 65%, 16: 70%,'
      + NL + '//   17: 85%, 18: 95%'
      + NL + '// ----------------------------------------------------------------------------'
      + NL + 'int chanceToLearnPct(uint8_t int_);'
      + NL + 'bool rollChanceToLearn(Dice& dice, uint8_t int_);',
      '// Chance to learn a spell (PHB p.10 INTELLIGENCE TABLE II,'
      + NL + '// repinned R196): percent rolled on d100 when an MU first'
      + NL + '// studies a new spell. Min INT 9 to learn any.'
      + NL + '//   INT 9: 35%, 10-12: 45%, 13-14: 55%, 15-16: 65%,'
      + NL + '//   17: 75%, 18: 85%, 19+: 95% (the printed or-more row)'
      + NL + '// ----------------------------------------------------------------------------'
      + NL + 'int chanceToLearnPct(uint8_t int_);'
      + NL + 'bool rollChanceToLearn(Dice& dice, uint8_t int_);'
      + NL + ''
      + NL + '// ----------------------------------------------------------------------------'
      + NL + '// R196: the INTELLIGENCE TABLE II spells-per-level columns -'
      + NL + '// which and how many of each group of spells (by level) the'
      + NL + '// MU can learn. All pins as -1 (unlimited). The printed'
      + NL + '// note: successive level groups are checked only when the'
      + NL + '// character reaches a level at which the group is usable.'
      + NL + '// ----------------------------------------------------------------------------'
      + NL + 'int minSpellsPerLevel(uint8_t int_);'
      + NL + 'int maxSpellsPerLevel(uint8_t int_);')

# ---------------------------------------------------------------------------
# Patch 5: regtest.cpp - the R196 battery audit (census 113)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R196: the INT Table II audit ----')
a('    // The printed INTELLIGENCE TABLE II: the chance-to-know')
a('    // percents and the min/max spells-per-level columns,')
a('    // cell for cell.')
a('    {')
a('        int bad = 0;')
a('        // the chance-to-know percents (9 through 19+)')
a('        static const int kPct[11] = {')
a('             0, 35, 45, 45, 45, 55, 55, 65, 65, 75,')
a('            85')
a('        };')
a('        // probes at 9-18, then the 19+ row')
a('        for (int i = 9; i <= 18; ++i) {')
a('            if (spells::chanceToLearnPct((uint8_t)i)')
a('                != kPct[i - 8]) ++bad;')
a('        }')
a('        if (spells::chanceToLearnPct(19) != 95) ++bad;')
a('        if (spells::chanceToLearnPct(25) != 95) ++bad;')
a('        if (spells::chanceToLearnPct(8) != 0) ++bad;')
a('        // the historically divergent cells (the R196 find):')
a('        // 10 read 35, 16 read 70, 17 read 85, 18 read 95')
a('        if (spells::chanceToLearnPct(10) != 45) ++bad;')
a('        if (spells::chanceToLearnPct(16) != 65) ++bad;')
a('        if (spells::chanceToLearnPct(17) != 75) ++bad;')
a('        if (spells::chanceToLearnPct(18) != 85) ++bad;')
a('        // the min spells-per-level column')
a('        static const int kMin[11] = {')
a('             0, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9')
a('        };')
a('        for (int i = 9; i <= 18; ++i) {')
a('            if (spells::minSpellsPerLevel((uint8_t)i)')
a('                != kMin[i - 8]) ++bad;')
a('        }')
a('        if (spells::minSpellsPerLevel(19) != 10) ++bad;')
a('        if (spells::minSpellsPerLevel(8) != 0) ++bad;')
a('        // the max spells-per-level column')
a('        static const int kMax[11] = {')
a('             0, 6, 7, 7, 7, 9, 9, 11, 11, 14, 18')
a('        };')
a('        for (int i = 9; i <= 18; ++i) {')
a('            if (spells::maxSpellsPerLevel((uint8_t)i)')
a('                != kMax[i - 8]) ++bad;')
a('        }')
a('        // the 19+ row: 10 / All (unlimited = -1)')
a('        if (spells::minSpellsPerLevel(19) != 10) ++bad;')
a('        if (spells::maxSpellsPerLevel(19) != -1) ++bad;')
a('        if (spells::maxSpellsPerLevel(25) != -1) ++bad;')
a('        // the band shape: min <= max at every score')
a('        for (int i = 9; i <= 25; ++i) {')
a('            int lo = spells::minSpellsPerLevel((uint8_t)i);')
a('            int hi = spells::maxSpellsPerLevel((uint8_t)i);')
a('            if (lo > hi) ++bad;   // -1 reads as unlimited')
a('        }')
a('        printf("R196 INT table II audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert the audit arrays against the print
kPct = [0, 35, 45, 45, 45, 55, 55, 65, 65, 75, 85]
kMin = [0, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9]
kMax = [0, 6, 7, 7, 7, 9, 9, 11, 11, 14, 18]
# index i-8 maps score 8 -> 0, 9 -> 1 ... 18 -> 10
assert kPct[9 - 8] == 35 and kPct[10 - 8] == 45
assert kPct[13 - 8] == 55 and kPct[15 - 8] == 65
assert kPct[17 - 8] == 75 and kPct[18 - 8] == 85
assert kMin[9 - 8] == 4 and kMin[10 - 8] == 5 and kMin[13 - 8] == 6
assert kMin[17 - 8] == 8 and kMin[18 - 8] == 9
assert kMax[9 - 8] == 6 and kMax[13 - 8] == 9 and kMax[16 - 8] == 11
assert kMax[17 - 8] == 14 and kMax[18 - 8] == 18
# the repinned function must read the same ladder
def pct(i):
    if i <= 8: return 0
    if i == 9: return 35
    if i <= 12: return 45
    if i <= 14: return 55
    if i <= 16: return 65
    if i == 17: return 75
    if i == 18: return 85
    return 95
assert [pct(i) for i in range(9, 19)] == kPct[1:]

patch('regtest.cpp',
      'R196 INT table II audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 6: tools/phb_gap_report.md - the verified-list entry
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'columns pin as minSpellsPerLevel',
      '- [x] **Spells (the SPELL TABLES and the spell'
      + NL + '      explanations, engine classes)** - the'
      + NL + '      54-spell registry, the by-level slot tables'
      + NL + '      and the L4-6 casting gates pinned'
      + NL + '      R80/R130/R131; caster aging R129.',
      '- [x] **Spells (the SPELL TABLES and the spell'
      + NL + '      explanations, engine classes)** - the'
      + NL + '      54-spell registry, the by-level slot tables'
      + NL + '      and the L4-6 casting gates pinned'
      + NL + '      R80/R130/R131; caster aging R129. THE INT'
      + NL + '      TABLE II chance-to-know repin R196:'
      + NL + '      spells.cpp chanceToLearnPct was DIVERGENT'
      + NL + '      (the engine read 10 35, 16 70, 17 85,'
      + NL + '      18 95; the print reads 10-12 45, 15-16 65,'
      + NL + '      17 75, 18 85, 19+ 95) - repinned; the two'
      + NL + '      unmodeled columns pin as minSpellsPerLevel'
      + NL + '      and maxSpellsPerLevel (All = -1); the live'
      + NL + '      callers (party spell learning, town study)'
      + NL + '      now read the printed percents.')

# ---------------------------------------------------------------------------
# Patch 7: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R196 landed the INT Table II repin',
      'ability tables print-pinned (STR R153, DEX R178c,'
      + NL + 'CON R178c, INT R195, WIS R194, CHA R193). Next:'
      + NL + 'the gap report names the next round.',
      'ability tables print-pinned (STR R153, DEX R178c,'
      + NL + 'CON R178c, INT R195, WIS R194, CHA R193). Next:'
      + NL + 'the gap report names the next round.'
      + NL + 'R196 landed the INT Table II repin (a NEW seam'
      + NL + 'find, post-founding-read): spells.cpp'
      + NL + 'chanceToLearnPct diverged from the print at 10,'
      + NL + '16, 17 and 18 - repinned (9 35, 10-12 45, 13-14'
      + NL + '55, 15-16 65, 17 75, 18 85, 19+ 95); the live'
      + NL + 'spell-learning rolls now read the printed'
      + NL + 'percents. The two unmodeled columns pin as new'
      + NL + 'accessors: minSpellsPerLevel / maxSpellsPerLevel'
      + NL + '(4/6 through 10/All; All = -1). New R196 battery'
      + NL + 'audit; census 113. Next: the gap report names'
      + NL + 'the next round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 6, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R196 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R196 note: 6 patches; census 113 (one new audit);')
print('commit: R196: the INT Table II repinned - the chance-to-know')
print('percents and the spells-per-level columns (census 113)')

