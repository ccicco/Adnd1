#!/usr/bin/env python3
# R199 splice: the oil and poison columns of the
# CHARACTER CLASSES TABLE II - the two columns
# right of the weapons column R198 pinned. The
# print:
#   Oil     yes for every class but the MONK -
#           the monk cell prints no, and the monk
#           prose confirms: "not even flaming oil
#           is usable by them."
#   Poison  cleric "never" - the footnote: the
#           prohibition is strictly for clerics
#           not of evil alignment; an evil cleric
#           may use poison if the referee permits.
#           Paladin "never", assassin "yes", every
#           other class "?" - the Note Regarding
#           Poison: the question mark means the
#           referee so allows.
# Engine shape: a three-valued allowance, the
# same encoding for both columns:
#   1 = yes, 0 = never, -1 = referee discretion.
# classOilUse(cls), classPoisonUse(cls), and the
# evil-cleric modifier classPoisonUseForAlignment
# (never stays never only for the non-evil
# cleric; evil clerics read the referee
# discretion the footnote grants - the paladin's
# never is unconditional).
# Patches: 2 (weapontables.h, regtest.cpp).
# Census 115 -> 116 (one new audit).

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
# Patch 1: rules/weapontables.h - the oil and poison columns
# ---------------------------------------------------------------------------

comment = ('// ----------------------------------------------------------------------------'
           + NL + '// R199: the oil and poison columns of the CHARACTER CLASSES'
           + NL + '// TABLE II - the two columns right of the weapons column'
           + NL + '// R198 pinned. The allowance encoding, both columns:'
           + NL + '//   1 = yes, 0 = never, -1 = referee discretion.'
           + NL + '// Oil: yes for every class but the monk - the monk cell'
           + NL + '// prints no, and the monk prose confirms: not even'
           + NL + '// flaming oil is usable by them. Poison: cleric never -'
           + NL + '// the footnote: the prohibition is strictly for clerics'
           + NL + '// not of evil alignment; paladin never, assassin yes,'
           + NL + '// every other class the question mark - the Note'
           + NL + '// Regarding Poison: the referee so allows.'
           + NL + '// ----------------------------------------------------------------------------')

body = []
body.append('// The three-valued allowance encoding, both columns:')
body.append('// 1 = yes, 0 = never, -1 = referee discretion.')
body.append('inline int classAllowanceYes() { return 1; }')
body.append('inline int classAllowanceNever() { return 0; }')
body.append('inline int classAllowanceReferee() { return -1; }')
body.append('')
body.append('// The Oil column, cell for cell. The class rows')
body.append('// in the printed order: 0 cleric, 1 druid, 2 fighter,')
body.append('// 3 paladin, 4 ranger, 5 magic-user, 6 illusionist,')
body.append('// 7 thief, 8 assassin, 9 monk. The monk cell prints no.')
body.append('inline int classOilUse(int cls) {')
body.append('    if (cls == 9) return 0;    // the monk: not even')
body.append('                                // flaming oil')
body.append('    return 1;    // yes - every other class row')
body.append('}')
body.append('')
body.append('// The Poison column, cell for cell. The cleric')
body.append('// cell prints never - but the footnote makes it')
body.append('// strictly for clerics not of evil alignment;')
body.append('// see classPoisonUseForAlignment below.')
body.append('inline int classPoisonUse(int cls) {')
body.append('    if (cls == 0) return 0;    // cleric: never')
body.append('    if (cls == 3) return 0;    // paladin: never')
body.append('    if (cls == 8) return 1;    // assassin: yes')
body.append('    return -1;   // the question mark: the referee')
body.append('                 // so allows - druid, fighter,')
body.append('                 // ranger, MU, illusionist, thief,')
body.append('                 // monk')
body.append('}')
body.append('')
body.append('// The cleric footnote, the alignment modifier: the')
body.append('// poison prohibition is strictly for clerics NOT')
body.append('// of evil alignment. An evil cleric reads the')
body.append('// discretion the footnote grants; a non-evil cleric')
body.append('// stays never. The paladin never is unconditional.')
body.append('// isEvil: the caller reads the alignment axis - here')
body.append('// a bool, true = evil.')
body.append('inline int classPoisonUseForAlignment(int cls,')
body.append('                                        bool isEvil) {')
body.append('    if (cls == 0 && isEvil) return -1;   // the footnote')
body.append('    return classPoisonUse(cls);')
body.append('}')

# anchor on the tail: the weaponAllowedForClass close then namespace close

tail = ('    return false;'
        + NL + '}'
        + NL
        + NL + '} // namespace rules')

new_tail = ('    return false;'
            + NL + '}'
            + NL
            + NL + comment
            + NL
            + NL + NL.join(body)
            + NL
            + NL + '} // namespace rules')

patch('rules/weapontables.h',
      'R199: the oil and poison columns',
      tail,
      new_tail)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the R199 battery audit (census 116)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R199: the oil and poison columns audit ----')
a('    // The CHARACTER CLASSES TABLE II oil and poison')
a('    // columns, cell for cell - the three-valued')
a('    // allowance encoding: 1 yes, 0 never, -1 referee.')
a('    {')
a('        int bad = 0;')
a('        // the encoding')
a('        if (rules::classAllowanceYes() != 1) ++bad;')
a('        if (rules::classAllowanceNever() != 0) ++bad;')
a('        if (rules::classAllowanceReferee() != -1) ++bad;')
a('        // the Oil column: yes for every class but the monk')
a('        static const int kOil[10] = {')
a('             1,  1,  1,  1,  1,  1,  1,  1,  1,  0')
a('        };')
a('        for (int c = 0; c < 10; ++c) {')
a('            if (rules::classOilUse(c) != kOil[c]) ++bad;')
a('        }')
a('        // the Poison column: cleric and paladin never,')
a('        // assassin yes, the rest the question mark')
a('        static const int kPoison[10] = {')
a('             0, -1, -1,  0, -1, -1, -1, -1,  1, -1')
a('        };')
a('        for (int c = 0; c < 10; ++c) {')
a('            if (rules::classPoisonUse(c) != kPoison[c]) ++bad;')
a('        }')
a('        // the cleric footnote: the prohibition is strictly')
a('        // for clerics not of evil alignment - an evil cleric')
a('        // reads the referee discretion')
a('        if (rules::classPoisonUseForAlignment(0, false) != 0) ++bad;')
a('        if (rules::classPoisonUseForAlignment(0, true) != -1) ++bad;')
a('        // the paladin never is unconditional - no footnote')
a('        if (rules::classPoisonUseForAlignment(3, true) != 0) ++bad;')
a('        if (rules::classPoisonUseForAlignment(3, false) != 0) ++bad;')
a('        // the other rows pass through untouched')
a('        if (rules::classPoisonUseForAlignment(8, false) != 1) ++bad;')
a('        if (rules::classPoisonUseForAlignment(9, true) != -1) ++bad;')
a('        printf("R199 oil and poison columns audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R198 class weapon allowlists audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R199 oil and poison columns audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 2, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R199 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R199 note: 2 patches; the TABLE II oil and poison columns land -')
print('the monk oil prohibition, the poison never/yes/question-mark')
print('cells, the evil-cleric footnote; census 116.')
print('commit: R199: the oil and poison columns - the TABLE II allowance')
print('columns pinned with the evil-cleric footnote (census 116)')

