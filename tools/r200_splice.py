#!/usr/bin/env python3
# R200 splice: the monk falling-while-climbing
# ladder - the print rows right under the
# thief-ability sharing paragraph the engine
# already pins. The print (the monk prose,
# after the six thief abilities):
#   At 4th level (Disciple), a monk can fall
#   up to 20 feet if he or she is within 1
#   foot of a wall.
#   At 6th level (Master), up to 30 feet if
#   within 4 feet of a wall.
#   At 13th level (Master of Winter), any
#   distance if within 8 feet of a wall.
#   The monk must have an opportunity to
#   periodically make contact with the wall
#   during the descent - the wall slows the
#   fall so no hit points of damage are
#   sustained. Any similar surface - tree
#   trunk, cliff face - serves.
# Engine shape: monkWallAssistedFallFeet -
# 0 below 4th, 20 at 4th-5th, 30 at 6th-12th,
# -1 (any distance) at 13th and up, with
# monkWallAssistedFallProximityFeet carrying
# the within-N-feet column (1 / 4 / 8) and
# monkWallAssistedFallRequiresContact the
# wall-contact rule (true - no damage only
# when contact is possible).
# Patches: 2 (subclassspecials.h, regtest.cpp).
# Census 116 -> 117 (one new audit).

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
# Patch 1: rules/subclassspecials.h - the falling-while-climbing ladder
# (anchored between the monkThiefAbilityName close and the surprise
# ladder comment - a comment landmark, never a function opening line)
# ---------------------------------------------------------------------------

old1 = ('    if (i > 5) i = 5;'
        + NL + '    return kNames[i];'
        + NL + '}'
        + NL
        + NL + '// ---- the monk surprise ladder ----')

new1 = ('    if (i > 5) i = 5;'
        + NL + '    return kNames[i];'
        + NL + '}'
        + NL
        + NL + '// ---- R200: the falling-while-climbing ladder ----'
        + NL + '//'
        + NL + '// The print, right under the thief-ability paragraph: a'
        + NL + '// monk can fall while climbing and take no damage when'
        + NL + '// close enough to a wall. The rungs: 4th level (Disciple)'
        + NL + '// - up to 20 feet within 1 foot of a wall; 6th (Master) -'
        + NL + '// up to 30 feet within 4 feet; 13th (Master of Winter) - any'
        + NL + '// distance within 8 feet. The monk must have opportunity to'
        + NL + '// periodically make contact with the wall during the'
        + NL + '// descent; any similar surface - tree trunk, cliff face -'
        + NL + '// serves.'
        + NL + '//'
        + NL + '// The fall distance: 0 below 4th, 20 at 4th-5th, 30 at'
        + NL + '// 6th-12th, -1 (any distance) at 13th and up.'
        + NL + 'inline int monkWallAssistedFallFeet(int level) {'
        + NL + '    if (level < 4)  return 0;'
        + NL + '    if (level < 6)  return 20;   // 4th-5th, within 1'
        + NL + '    if (level < 13) return 30;   // 6th-12th, within 4'
        + NL + '    return -1;   // 13th and up: any distance'
        + NL + '}'
        + NL
        + NL + '// The proximity column: how close to the wall the fall'
        + NL + '// must happen. 1 foot at 4th-5th, 4 feet at 6th-12th,'
        + NL + '// 8 feet at 13th and up; 0 below 4th (no wall assist).'
        + NL + 'inline int monkWallAssistedFallProximityFeet(int level) {'
        + NL + '    if (level < 4)  return 0;'
        + NL + '    if (level < 6)  return 1;'
        + NL + '    if (level < 13) return 4;'
        + NL + '    return 8;'
        + NL + '}'
        + NL
        + NL + '// The wall-contact rule: the descent is damage-free only'
        + NL + '// when the monk can periodically touch the wall - the'
        + NL + '// print pins it as always required for the assist.'
        + NL + 'inline bool monkWallAssistedFallRequiresContact() {'
        + NL + '    return true;'
        + NL + '}'
        + NL
        + NL + '// ---- the monk surprise ladder ----')

patch('rules/subclassspecials.h',
      'R200: the falling-while-climbing ladder',
      old1,
      new1)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the R200 battery audit (census 117)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R200: the falling-while-climbing ladder audit ----')
a('    // The print rungs: 4th = 20 feet within 1 of a wall,')
a('    // 6th = 30 feet within 4, 13th = any distance within 8.')
a('    {')
a('        int bad = 0;')
a('        // the fall distance ladder: 0 below 4th, 20 at 4th-5th,')
a('        // 30 at 6th-12th (seven levels), -1 at 13th and up')
a('        static const int kFall[17] = {')
a('             0,  0,  0, 20, 20, 30, 30, 30, 30, 30,')
a('            30, 30, -1, -1, -1, -1, -1')
a('        };')
a('        for (int lv = 1; lv <= 17; ++lv) {')
a('            if (rules::monkWallAssistedFallFeet(lv)')
a('                != kFall[lv - 1]) ++bad;')
a('        }')
a('        // the clamps')
a('        if (rules::monkWallAssistedFallFeet(0) != 0) ++bad;')
a('        if (rules::monkWallAssistedFallFeet(99) != -1) ++bad;')
a('        // the proximity ladder: 0 below 4th, 1 at 4th-5th,')
a('        // 4 at 6th-12th (seven levels), 8 at 13th and up')
a('        static const int kProx[17] = {')
a('             0,  0,  0,  1,  1,  4,  4,  4,  4,  4,')
a('             4,  4,  8,  8,  8,  8,  8')
a('        };')
a('        for (int lv = 1; lv <= 17; ++lv) {')
a('            if (rules::monkWallAssistedFallProximityFeet(lv)')
a('                != kProx[lv - 1]) ++bad;')
a('        }')
a('        if (rules::monkWallAssistedFallProximityFeet(0) != 0) ++bad;')
a('        if (rules::monkWallAssistedFallProximityFeet(99) != 8)')
a('            ++bad;')
a('        // the wall-contact rule')
a('        if (!rules::monkWallAssistedFallRequiresContact()) ++bad;')
a('        // the rung boundaries: the three print cells')
a('        if (rules::monkWallAssistedFallFeet(4) != 20)')
a('            ++bad;   // 4th: Disciple, 20 within 1')
a('        if (rules::monkWallAssistedFallProximityFeet(4) != 1) ++bad;')
a('        if (rules::monkWallAssistedFallFeet(6) != 30)')
a('            ++bad;   // 6th: Master, 30 within 4')
a('        if (rules::monkWallAssistedFallProximityFeet(6) != 4) ++bad;')
a('        if (rules::monkWallAssistedFallFeet(13) != -1)')
a('            ++bad;   // 13th: Master of Winter, any within 8')
a('        if (rules::monkWallAssistedFallProximityFeet(13) != 8)')
a('            ++bad;')
a('        printf("R200 falling ladder audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R199 oil and poison columns audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R200 falling ladder audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 2, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R200 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R200 note: 2 patches; the falling-while-climbing ladder lands -')
print('the 20/30/any rungs, the 1/4/8 proximity column, the')
print('wall-contact rule; census 117.')
print('commit: R200: the monk falling-while-climbing ladder - the')
print('20/30/any-distance rungs and the wall proximity column (census 117)')

