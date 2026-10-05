#!/usr/bin/env python3
# R197 splice: the per-spell mental-form flag (the R194
# seam named by the gap reports). The printed Wisdom
# Table I note: the magical defense adjustment applies
# only to mental attack forms involving will force -
# beguiling, charming, fear, hypnosis, illusion, magic
# jarring, mass charming, phantasmal forces, possession,
# rulership, suggestion, telepathic attack. R194 repinned
# the ladder but no spell was tagged; the modifier could
# not be assembled. This round lands the per-spell engine
# data: spellIsMentalForm flags the registry's two
# will-force forms (charm person - charming; charm
# monster - mass charming), and spellSaveModWis assembles
# the WIS magical defense adjustment for them (0 on
# everything else). The holds are NOT will-force forms:
# the PHB Serten spell immunity print groups hold with
# command, domination, fear and scare, apart from
# beguiling, charm and suggestion. Fear, hypnosis,
# suggestion, the phantasmal forces ride the flag when
# their registry rows arrive.
#
# Patches: 3 (spells.cpp, spells.h, regtest.cpp).
# Census 113 -> 114 (one new audit).

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
# Patch 1: spells/spells.cpp - spellIsMentalForm + spellSaveModWis
# (anchored AFTER the maxSpellsPerLevel close - never a function
# opening line, the R196b lesson; both land at namespace depth)
# ---------------------------------------------------------------------------

new_impl = ('    return -1;   // 19 and up: All (unlimited)'
            + NL + '}'
            + NL
            + NL + '// ----------------------------------------------------------------------------'
            + NL + '// R197: the printed Wisdom Table I note - the magical defense'
            + NL + '// adjustment applies only to mental attack forms involving'
            + NL + '// will force: beguiling, charming, fear, hypnosis, illusion,'
            + NL + '// magic jarring, mass charming, phantasmal forces, possession,'
            + NL + '// rulership, suggestion, telepathic attack. Per-spell engine'
            + NL + '// data: which registry spells ARE those forms. The 54-spell'
            + NL + '// registry holds two: charm person (charming) and charm'
            + NL + '// monster (mass charming). The holds are NOT will-force'
            + NL + '// forms - the PHB Serten spell immunity print groups hold'
            + NL + '// with command, domination, fear and scare, apart from'
            + NL + '// beguiling, charm and suggestion. Fear, hypnosis,'
            + NL + '// suggestion and the phantasmal forces ride the flag'
            + NL + '// when their registry rows arrive.'
            + NL + '// ----------------------------------------------------------------------------'
            + NL + 'bool spellIsMentalForm(SpellId id) {'
            + NL + '    switch (id) {'
            + NL + '        case MU_CHARM_PERSON:     // charming'
            + NL + '        case MU_CHARM_MONSTER:    // mass charming'
            + NL + '            return true;'
            + NL + '        default:'
            + NL + '            return false;'
            + NL + '    }'
            + NL + '}'
            + NL
            + NL + '// The save-modifier assembly: the WIS magical defense'
            + NL + '// adjustment - the printed Wisdom Table I ladder,'
            + NL + '// wisMagicalAttackAdj, the same one R194 wisMagDefAdj'
            + NL + '// delegates to - on mental-form spells; 0 on everything'
            + NL + '// else. The save rolls stay caller-assembled'
            + NL + '// (rules/saves.h); callers call this.'
            + NL + 'int spellSaveModWis(SpellId id, uint8_t wis) {'
            + NL + '    if (!spellIsMentalForm(id)) return 0;'
            + NL + '    return rules::wisMagicalAttackAdj(wis);'
            + NL + '}'
            + NL
            + NL + '// ----------------------------------------------------------------------------'
            + NL + '// R115: the years magic steals (DMG p.14). Only haste is in')

old_impl = ('    return -1;   // 19 and up: All (unlimited)'
            + NL + '}'
            + NL
            + NL + '// ----------------------------------------------------------------------------'
            + NL + '// R115: the years magic steals (DMG p.14). Only haste is in')

patch('spells/spells.cpp',
      'R197: the printed Wisdom Table I note',
      old_impl,
      new_impl)

# ---------------------------------------------------------------------------
# Patch 2: spells/spells.h - the declarations + the print note
# ---------------------------------------------------------------------------

new_hdr = ('int minSpellsPerLevel(uint8_t int_);'
           + NL + 'int maxSpellsPerLevel(uint8_t int_);'
           + NL
           + NL + '// ----------------------------------------------------------------------------'
           + NL + '// R197: the per-spell mental-form flag. The printed Wisdom'
           + NL + '// Table I note: the magical defense adjustment applies'
           + NL + '// only to mental attack forms involving will force -'
           + NL + '// beguiling, charming, fear, hypnosis, illusion, magic'
           + NL + '// jarring, mass charming, phantasmal forces, possession,'
           + NL + '// rulership, suggestion, telepathic attack.'
           + NL + '// spellIsMentalForm is the per-spell engine data;'
           + NL + '// spellSaveModWis assembles the WIS magical defense'
           + NL + '// adjustment for those spells, 0 on everything else -'
           + NL + '// the save rolls stay caller-assembled (rules/saves.h).'
           + NL + '// Registry rows flagged: charm person, charm monster.'
           + NL + '// ----------------------------------------------------------------------------'
           + NL + 'bool spellIsMentalForm(SpellId id);'
           + NL + 'int  spellSaveModWis(SpellId id, uint8_t wis);')

old_hdr = ('int minSpellsPerLevel(uint8_t int_);'
           + NL + 'int maxSpellsPerLevel(uint8_t int_);')

patch('spells/spells.h',
      'R197: the per-spell mental-form flag',
      old_hdr,
      new_hdr)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R197 battery audit (census 114)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R197: the mental-form flag audit ----')
a('    // The printed Wisdom Table I note: the magical defense')
a('    // adjustment rides only will-force forms. The registry')
a('    // holds two: charm person (charming) and charm monster')
a('    // (mass charming). The holds are not will-force forms.')
a('    {')
a('        int bad = 0;')
a('        // the flagged rows')
a('        if (!spells::spellIsMentalForm(spells::MU_CHARM_PERSON))')
a('            ++bad;')
a('        if (!spells::spellIsMentalForm(spells::MU_CHARM_MONSTER))')
a('            ++bad;')
a('        // the unflagged rows: holds are not will-force forms,')
a('        // and the physical/utility spells are not either')
a('        if (spells::spellIsMentalForm(spells::MU_HOLD_MONSTER)) ++bad;')
a('        if (spells::spellIsMentalForm(spells::CL_HOLD_PERSON)) ++bad;')
a('        if (spells::spellIsMentalForm(spells::MU_SLEEP)) ++bad;')
a('        if (spells::spellIsMentalForm(spells::MU_FIREBALL)) ++bad;')
a('        if (spells::spellIsMentalForm(spells::MU_MAGIC_MISSILE)) ++bad;')
a('        if (spells::spellIsMentalForm(spells::MU_POLYMORPH_OTHER))')
a('            ++bad;')
a('        if (spells::spellIsMentalForm(spells::CL_SILENCE_15)) ++bad;')
a('        // the assembly: the ladder on mental forms')
a('        if (spells::spellSaveModWis(spells::MU_CHARM_PERSON, 18) != 4)')
a('            ++bad;')
a('        if (spells::spellSaveModWis(spells::MU_CHARM_PERSON, 3) != -3)')
a('            ++bad;')
a('        if (spells::spellSaveModWis(spells::MU_CHARM_PERSON, 10) != 0)')
a('            ++bad;')
a('        if (spells::spellSaveModWis(spells::MU_CHARM_MONSTER, 17) != 3)')
a('            ++bad;')
a('        // and 0 off them, whatever the wisdom')
a('        if (spells::spellSaveModWis(spells::MU_FIREBALL, 3) != 0)')
a('            ++bad;')
a('        if (spells::spellSaveModWis(spells::MU_MAGIC_MISSILE, 18) != 0)')
a('            ++bad;')
a('        // the ladder handoff: the helper IS wisMagicalAttackAdj')
a('        for (int w = 3; w <= 18; ++w) {')
a('            if (spells::spellSaveModWis(')
a('                    spells::MU_CHARM_PERSON, (uint8_t)w)')
a('                != rules::wisMagicalAttackAdj((uint8_t)w)) ++bad;')
a('        }')
a('        printf("R197 mental-form flag audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R196 INT table II audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R197 mental-form flag audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 3, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R197 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R197 note: 3 patches; the per-spell mental-form flag lands -')
print('charm person and charm monster flagged, spellSaveModWis assembles')
print('the WIS magical defense adjustment; census 114.')
print('commit: R197: the per-spell mental-form flag - the WIS magical')
print('defense adjustment assembled for the will-force forms (census 114)')

