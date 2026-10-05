#!/usr/bin/env python3
# R193 splice: the CHA table repin (PHB
# divergence 5 of the R177 founding read -
# the LIVE divergence).
#
# rules/character.cpp: all three accessors
# repinned to the printed CHARISMA TABLE,
# cell for cell:
# - chaReactionAdj: the flat -4..+4 ladder
#   becomes the printed PERCENT ladder
#   (3 -25, 4 -20, 5 -15, 6 -10, 7 -5,
#   8-12 0, 13 +5, 14 +10, 15 +15, 16 +25,
#   17 +30, 18 +35) - the d100 reaction
#   bands (dm.cpp rollReaction) now read
#   the printed percents directly;
# - chaHenchmenMax: the two divergent cells
#   repinned (cha 4 = 1, cha 12 = 5; the
#   rest already matched: 3 1, 5-6 2, 7-8 3,
#   9-11 4, 13 5, 14 6, 15 7, 16 8, 17 10,
#   18 15);
# - chaLoyaltyBase: the 1..15 ladder becomes
#   the printed PERCENT ladder (3 -30, 4
#   -25, 5 -20, 6 -15, 7 -10, 8 -5, 9-13 0,
#   14 +5, 15 +15, 16 +20, 17 +30, 18 +40).
# The character.h range comments repin with
# them. The five party-reaction call sites
# pass the adj into rollReaction unchanged -
# the percent scale is what d100 banding
# wants.
#
# regtest.cpp: the R193 battery audit walks
# the printed table cell for cell (all three
# columns, all 16 scores) plus the clamps.
# Census 110.
#
# Patches: 8.

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
# Patch 1: rules/character.cpp - chaReactionAdj repin (the percent ladder)
# ---------------------------------------------------------------------------

patch('rules/character.cpp',
      'if (cha == 16)  return 25;',
      'int chaReactionAdj(uint8_t cha) {'
      + NL + '    if (cha <= 3)   return -4;'
      + NL + '    if (cha == 4)   return -3;'
      + NL + '    if (cha == 5)   return -2;'
      + NL + '    if (cha <= 8)   return -1;'
      + NL + '    if (cha <= 12)  return 0;'
      + NL + '    if (cha <= 14)  return 1;'
      + NL + '    if (cha <= 16)  return 2;'
      + NL + '    if (cha == 17)  return 3;'
      + NL + '    return 4;   // 18'
      + NL + '}',
      'int chaReactionAdj(uint8_t cha) {'
      + NL + '    // R193: the printed CHARISMA TABLE reaction'
      + NL + '    // adjustment, in PERCENT - the d100 reaction bands'
      + NL + '    // (dm.cpp rollReaction) read it directly'
      + NL + '    if (cha <= 3)  return -25;'
      + NL + '    if (cha == 4)  return -20;'
      + NL + '    if (cha == 5)  return -15;'
      + NL + '    if (cha == 6)  return -10;'
      + NL + '    if (cha == 7)  return -5;'
      + NL + '    if (cha <= 12) return  0;   // 8 through 12'
      + NL + '    if (cha == 13) return  5;'
      + NL + '    if (cha == 14) return 10;'
      + NL + '    if (cha == 15) return 15;'
      + NL + '    if (cha == 16)  return 25;'
      + NL + '    if (cha == 17)  return 30;'
      + NL + '    return 35;   // 18'
      + NL + '}')

# ---------------------------------------------------------------------------
# Patch 2: rules/character.cpp - chaHenchmenMax repin (cha 4 = 1, cha 12 = 5)
# ---------------------------------------------------------------------------

patch('rules/character.cpp',
      'if (cha == 12)  return 5;   // R193: was 4',
      'int chaHenchmenMax(uint8_t cha) {'
      + NL + '    if (cha <= 3)   return 1;'
      + NL + '    if (cha <= 5)   return 2;'
      + NL + '    if (cha <= 8)   return 3;'
      + NL + '    if (cha <= 12)  return 4;'
      + NL + '    if (cha == 13)  return 5;'
      + NL + '    if (cha == 14)  return 6;'
      + NL + '    if (cha == 15)  return 7;'
      + NL + '    if (cha == 16)  return 8;'
      + NL + '    if (cha == 17)  return 10;'
      + NL + '    return 15;  // 18'
      + NL + '}',
      'int chaHenchmenMax(uint8_t cha) {'
      + NL + '    // R193: the printed maximum henchmen column -'
      + NL + '    // the two divergent cells repinned (cha 4 = 1,'
      + NL + '    // cha 12 = 5); the rest already matched'
      + NL + '    if (cha <= 4)  return 1;   // 3, 4'
      + NL + '    if (cha <= 6)  return 2;   // 5, 6'
      + NL + '    if (cha <= 8)  return 3;   // 7, 8'
      + NL + '    if (cha <= 11) return 4;   // 9 through 11'
      + NL + '    if (cha == 12)  return 5;   // R193: was 4'
      + NL + '    if (cha == 13)  return 5;'
      + NL + '    if (cha == 14)  return 6;'
      + NL + '    if (cha == 15)  return 7;'
      + NL + '    if (cha == 16)  return 8;'
      + NL + '    if (cha == 17)  return 10;'
      + NL + '    return 15;  // 18'
      + NL + '}')

# ---------------------------------------------------------------------------
# Patch 3: rules/character.cpp - chaLoyaltyBase repin (the percent ladder)
# ---------------------------------------------------------------------------

patch('rules/character.cpp',
      'if (cha == 14)  return 5;   // R193: percent',
      'int chaLoyaltyBase(uint8_t cha) {'
      + NL + '    if (cha <= 3)  return 1;'
      + NL + '    if (cha == 4)  return 2;'
      + NL + '    if (cha == 5)  return 3;'
      + NL + '    if (cha <= 7)  return 4;'
      + NL + '    if (cha == 8)  return 5;'
      + NL + '    if (cha <= 11) return 6;'
      + NL + '    if (cha == 12) return 7;'
      + NL + '    if (cha == 13) return 8;'
      + NL + '    if (cha == 14) return 9;'
      + NL + '    if (cha == 15) return 10;'
      + NL + '    if (cha == 16) return 11;'
      + NL + '    if (cha == 17) return 12;'
      + NL + '    return 15;  // 18'
      + NL + '}',
      'int chaLoyaltyBase(uint8_t cha) {'
      + NL + '    // R193: the printed loyalty base column, in'
      + NL + '    // PERCENT - the subtraction from or addition'
      + NL + '    // to the henchmen loyalty scores'
      + NL + '    if (cha <= 3)  return -30;'
      + NL + '    if (cha == 4)  return -25;'
      + NL + '    if (cha == 5)  return -20;'
      + NL + '    if (cha == 6)  return -15;'
      + NL + '    if (cha == 7)  return -10;'
      + NL + '    if (cha == 8)  return -5;'
      + NL + '    if (cha <= 13) return 0;    // 9 through 13'
      + NL + '    if (cha == 14)  return 5;   // R193: percent'
      + NL + '    if (cha == 15)  return 15;'
      + NL + '    if (cha == 16)  return 20;'
      + NL + '    if (cha == 17)  return 30;'
      + NL + '    return 40;  // 18'
      + NL + '}')

# ---------------------------------------------------------------------------
# Patch 4: rules/character.h - the range comments repin
# ---------------------------------------------------------------------------

patch('rules/character.h',
      'the printed percent ladder -25..+35 (R193)',
      'int  chaReactionAdj(uint8_t cha);       // -4..+4 (hireling reaction roll)'
      + NL + 'int  chaHenchmenMax(uint8_t cha);       // 0..15 (max henchmen, morale-linked)'
      + NL + 'int  chaLoyaltyBase(uint8_t cha);       // 1..12 base loyalty',
      'int  chaReactionAdj(uint8_t cha);       // the printed percent ladder -25..+35 (R193)'
      + NL + 'int  chaHenchmenMax(uint8_t cha);       // 1..15 (the printed table, R193)'
      + NL + 'int  chaLoyaltyBase(uint8_t cha);       // the printed percent ladder -30..+40 (R193)')

# ---------------------------------------------------------------------------
# Patch 5: regtest.cpp - the R193 battery audit (census 110)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R193: the charisma table audit ----')
a('    // The printed CHARISMA TABLE, all three columns,')
a('    // all 16 scores - the reaction percent ladder,')
a('    // the henchmen column, the loyalty percents.')
a('    {')
a('        int bad = 0;')
a('        // the reaction adjustment: the printed percent')
a('        // ladder (-25 at 3 through +35 at 18)')
a('        static const int kReact[16] = {')
a('            -25, -20, -15, -10, -5,')
a('              0,   0,   0,   0,   0,')
a('              5,  10,  15,  25,  30,  35')
a('        };')
a('        static const int kHench[16] = {')
a('             1,  1,  2,  2,  3,  3,  4,  4,')
a('             4,  5,  5,  6,  7,  8, 10, 15')
a('        };')
a('        static const int kLoyal[16] = {')
a('            -30, -25, -20, -15, -10, -5,')
a('             0,   0,   0,   0,   0,')
a('             5,  15,  20,  30,  40')
a('        };')
a('        for (int c = 3; c <= 18; ++c) {')
a('            if (rules::chaReactionAdj((uint8_t)c)')
a('                != kReact[c - 3]) ++bad;')
a('            if (rules::chaHenchmenMax((uint8_t)c)')
a('                != kHench[c - 3]) ++bad;')
a('            if (rules::chaLoyaltyBase((uint8_t)c)')
a('                != kLoyal[c - 3]) ++bad;')
a('        }')
a('        // the cha 18 tail cells')
a('        if (rules::chaReactionAdj(18) != 35) ++bad;')
a('        if (rules::chaHenchmenMax(18) != 15) ++bad;')
a('        if (rules::chaLoyaltyBase(18) != 40) ++bad;')
a('        // the two historically divergent henchmen cells:')
a('        // cha 4 reads 1, cha 12 reads 5 (the R177 founding read)')
a('        if (rules::chaHenchmenMax(4) != 1) ++bad;')
a('        if (rules::chaHenchmenMax(12) != 5) ++bad;')
a('        // the clamps read the edge rows')
a('        if (rules::chaReactionAdj(0) != -25) ++bad;')
a('        if (rules::chaReactionAdj(99) != 35) ++bad;')
a('        if (rules::chaHenchmenMax(0) != 1) ++bad;')
a('        if (rules::chaHenchmenMax(99) != 15) ++bad;')
a('        if (rules::chaLoyaltyBase(0) != -30) ++bad;')
a('        if (rules::chaLoyaltyBase(99) != 40) ++bad;')
a('        // the reaction bands consume the percent scale:')
a('        // a cha-18 leader adds +35 to the d100 reaction')
a('        // roll, a cha-3 leader -25')
a('        if (rules::chaReactionAdj(18) + 50 != 85) ++bad;')
a('        if (rules::chaReactionAdj(3) + 50 != 25) ++bad;')
a('        printf("R193 charisma table audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert the audit arrays against the print
# (the R184b lesson - this round's own arrays)
kReact = [-25, -20, -15, -10, -5, 0, 0, 0, 0, 0,
          5, 10, 15, 25, 30, 35]
kHench = [1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 7, 8, 10, 15]
kLoyal = [-30, -25, -20, -15, -10, -5, 0, 0, 0, 0, 0,
          5, 15, 20, 30, 40]
assert len(kReact) == 16 and len(kHench) == 16 and len(kLoyal) == 16
# the printed spot cells (the CHARISMA TABLE page)
assert kReact[3 - 3] == -25 and kReact[18 - 3] == 35
assert kReact[13 - 3] == 5 and kReact[16 - 3] == 25
assert kHench[4 - 3] == 1 and kHench[12 - 3] == 5
assert kHench[17 - 3] == 10 and kHench[18 - 3] == 15
assert kLoyal[3 - 3] == -30 and kLoyal[18 - 3] == 40
assert kLoyal[14 - 3] == 5 and kLoyal[15 - 3] == 15
# the band composites
assert kReact[18 - 3] + 50 == 85 and kReact[3 - 3] + 50 == 25

patch('regtest.cpp',
      'R193 charisma table audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 6: tools/phb_gap_report.md - the divergence 5 box flipped
# ---------------------------------------------------------------------------

box_old = ('- [~] 5. **CHA table (reaction adjustment, loyalty'
           + NL + '      base, henchmen - the CHARISMA TABLE page)** -'
           + NL + '      the engine reaction adjustment is a flat -4'
           + NL + '      through +4 ladder against the printed percent'
           + NL + '      ladder (-25 at 3 through +35 at 18); the'
           + NL + '      loyalty base reads 1 through 15 against the'
           + NL + '      printed -30 through +40 percent; the henchmen'
           + NL + '      count diverges at cha 4 (engine 2, print 1)'
           + NL + '      and cha 12 (engine 4, print 5). The reaction'
           + NL + '      accessor is LIVE and feeds the d100 reaction'
           + NL + '      bands (dm.cpp rollReaction) - the fix round'
           + NL + '      must re-scale to the printed percents.')

box_new = ('- [x] 5. **CHA table (reaction adjustment, loyalty'
           + NL + '      base, henchmen - the CHARISMA TABLE page)** -'
           + NL + '      CLOSED R193: all three accessors repinned'
           + NL + '      cell for cell. chaReactionAdj is now the'
           + NL + '      printed PERCENT ladder (-25 at 3 through'
           + NL + '      +35 at 18; 13 +5, 14 +10, 15 +15, 16 +25,'
           + NL + '      17 +30) - the live d100 reaction bands'
           + NL + '      (dm.cpp rollReaction, five party call sites)'
           + NL + '      read the printed percents directly, no band'
           + NL + '      re-carving needed. chaLoyaltyBase is the'
           + NL + '      printed percent ladder (-30 through +40;'
           + NL + '      14 +5, 15 +15, 16 +20, 17 +30). The henchmen'
           + NL + '      column repinned at its two divergent cells'
           + NL + '      (cha 4 = 1, cha 12 = 5) - the rest already'
           + NL + '      matched the print. The character.h range'
           + NL + '      comments repinned with them. The R193'
           + NL + '      battery audit walks all three columns, all'
           + NL + '      16 scores. Census 110.')

t2 = rd('tools/phb_gap_report.md')
if 'CLOSED R193: all three accessors repinned' not in t2:
    assert t2.count(box_old) == 1, 'R193 box anchor not unique'
else:
    assert t2.count(box_old) == 0, 'R193 box old text lingers'

patch('tools/phb_gap_report.md',
      'CLOSED R193: all three accessors repinned',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 7: tools/phb_gap_report.md - the intro line repin
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'divergences 3 (WIS) and 4 (INT) remain ranked fix rounds',
      'retired. Census 95. The WIS, INT and CHA'
      + NL + 'divergences (3, 4, 5) remain ranked fix rounds.',
      'retired. Census 95. The WIS, INT and CHA'
      + NL + 'divergences 3 (WIS) and 4 (INT) remain ranked fix rounds;'
      + NL + '5 (CHA, the live reaction feed) CLOSED R193.')

# ---------------------------------------------------------------------------
# Patch 8: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R193 landed the charisma repin',
      'engine limit closes. New R192 battery audit; census'
      + NL + '109. Next: the gap report names the next round.',
      'engine limit closes. New R192 battery audit; census'
      + NL + '109. Next: the gap report names the next round.'
      + NL + 'R193 landed the charisma repin (PHB divergence 5,'
      + NL + 'the live one): rules/character.cpp chaReactionAdj,'
      + NL + 'chaLoyaltyBase and chaHenchmenMax repinned cell for'
      + NL + 'cell to the printed CHARISMA TABLE - the reaction'
      + NL + 'and loyalty ladders are now the printed PERCENT'
      + NL + 'ladders (-25..+35, -30..+40); the d100 reaction'
      + NL + 'bands read the percents directly; the two divergent'
      + NL + 'henchmen cells repinned (cha 4 = 1, cha 12 = 5).'
      + NL + 'New R193 battery audit; census 110. Next: the PHB'
      + NL + 'divergences 3 (WIS) and 4 (INT).')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 8, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R193 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R193 note: 8 patches; census 110 (one new audit);')
print('commit: R193: the charisma table repinned - the percent ladders')
print('and the henchmen cells (census 110)')

