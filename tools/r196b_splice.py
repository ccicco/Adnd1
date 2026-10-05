#!/usr/bin/env python3
# R196b splice: the R196 nested-function fix
# (the preflight caught 2 compile errors -
# function definition not allowed here).
#
# ROOT CAUSE: the R196 patch anchored the
# new minSpellsPerLevel / maxSpellsPerLevel
# block on rollChanceToLearn OPENING line,
# so the two accessors landed INSIDE its
# body (nested definitions - braces stayed
# balanced, which is why the hygiene sweep
# passed). The fix: move the accessor
# block OUT, after rollChanceToLearn
# closes. LESSON (carved): a patch that
# inserts after a function must anchor on
# the function CLOSING line or a following
# landmark, never the opening line; and
# brace balance does not catch nesting -
# the acid test needs a syntax check of the
# touched TU when the sandbox has no
# compiler... the Termux preflight is the
# gate that caught it.
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
# Patch 1: spells/spells.cpp - move the accessor block out of the body
# ---------------------------------------------------------------------------

broken = ('bool rollChanceToLearn(Dice& dice, uint8_t int_) {'
          + NL
          + NL + '// ----------------------------------------------------------------------------'
          + NL + '// R196: INTELLIGENCE TABLE II, the min and max spells-per-level'
          + NL + '// columns. All pins as -1 (the repo unlimited convention).'
          + NL + '// ----------------------------------------------------------------------------'
          + NL
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
          + NL
          + NL + 'int maxSpellsPerLevel(uint8_t int_) {'
          + NL + '    if (int_ < 9)  return 0;'
          + NL + '    if (int_ == 9)  return 6;'
          + NL + '    if (int_ <= 12) return 7;   // 10, 11, 12'
          + NL + '    if (int_ <= 14) return 9;   // 13, 14'
          + NL + '    if (int_ <= 16) return 11;   // 15, 16'
          + NL + '    if (int_ == 17) return 14;'
          + NL + '    if (int_ == 18) return 18;'
          + NL + '    return -1;   // 19 and up: All (unlimited)'
          + NL + '}'
          + NL + '    int pct = chanceToLearnPct(int_);'
          + NL + '    if (pct <= 0) return false;'
          + NL + '    return (int)dice.d100() <= pct;'
          + NL + '}')

fixed = ('bool rollChanceToLearn(Dice& dice, uint8_t int_) {'
         + NL + '    int pct = chanceToLearnPct(int_);'
         + NL + '    if (pct <= 0) return false;'
         + NL + '    return (int)dice.d100() <= pct;'
         + NL + '}'
         + NL
         + NL + '// ----------------------------------------------------------------------------'
         + NL + '// R196: INTELLIGENCE TABLE II, the min and max spells-per-level'
         + NL + '// columns. All pins as -1 (the repo unlimited convention).'
         + NL + '// R196b: the accessors live at file scope - the nested-function fix.'
         + NL + '// ----------------------------------------------------------------------------'
         + NL
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
         + NL
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

patch('spells/spells.cpp',
      'R196b: the accessors live at file scope',
      broken,
      fixed)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 1, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R196b splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R196b note: 1 patch; the nested-function fix - the accessors')
print('moved out of rollChanceToLearn; census stays 113.')
print('commit: R196: the INT Table II repinned - the chance-to-know')
print('percents and the spells-per-level columns (census 113)')

