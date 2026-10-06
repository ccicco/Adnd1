#!/usr/bin/env python3
# R227 splice: the Wisdom Table I save wire -
# the PHB wiring arc opens. The R192 magical
# attack saving throw adjustment ladder had
# ZERO callers: spellSaveModWis existed but no
# save roll ever paid it. This round wires it:
#   - rules/wisdom.h gains wisMentalSaveAdj,
#     the mental-form gate seam (0 on
#     non-mental forms);
#   - spells::spellSaveModWis delegates to it;
#   - the spelleffects TargetDesc gains saveWis
#     (the defender WIS; 10 default - monsters
#     read no adjustment, a character table);
#   - resolveSpell folds the gate into
#     saveBonus (the field the TargetDesc
#     comment always reserved for the WIS
#     magic adj), so every spell save through
#     the chokepoint now pays the ladder;
#   - Actor::asTarget sets saveWis from the
#     character wisdom.
# Registry mental forms today: charm person,
# charm monster (fear, hypnosis, suggestion,
# phantasmal forces ride the flag when their
# rows arrive).
# Patches: 7. Census 142 -> 143.

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
    try:
        t = rd(path)
    except IOError:
        assert old is None, 'anchor patch on absent file: ' + marker
        assert marker in new, 'marker missing in new file: ' + marker
        wr(path, new)
        applied += 1
        return
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
# Patch 1: rules/wisdom.h - the mental-form gate seam
# ---------------------------------------------------------------------------

old1 = ('    return  4;   // 18' + NL + '}' + NL + NL +
        '// The Table I high-circle gates: the minimum')

new1 = ('    return  4;   // 18' + NL + '}' + NL + NL +
        '// R227: the mental-form gate - the Wisdom' + NL +
        '// Table I magical defense adjustment a' + NL +
        '// defender gets vs mental attack forms' + NL +
        '// involving will force (beguiling,' + NL +
        '// charming, fear, hypnosis, illusion,' + NL +
        '// mass charming, phantasmal forces,' + NL +
        '// possession, rulership, suggestion,' + NL +
        '// telepathic attack - the per-spell' + NL +
        '// registry flags ride' + NL +
        '// spells::spellIsMentalForm). 0 on' + NL +
        '// everything else. spells::spellSaveModWis' + NL +
        '// delegates here; the spelleffects save' + NL +
        '// chokepoint folds the result into the' + NL +
        '// target saveBonus.' + NL +
        'inline int wisMentalSaveAdj(uint8_t wis, bool mentalForm) {' + NL +
        '    if (!mentalForm) return 0;' + NL +
        '    return wisMagicalAttackAdj(wis);' + NL +
        '}' + NL + NL +
        '// The Table I high-circle gates: the minimum')

patch('rules/wisdom.h',
      'R227: the mental-form gate - the Wisdom',
      old1,
      new1)

# ---------------------------------------------------------------------------
# Patch 2: spells/spells.cpp - spellSaveModWis delegates
# ---------------------------------------------------------------------------

old2 = ('int spellSaveModWis(SpellId id, uint8_t wis) {' + NL +
        '    if (!spellIsMentalForm(id)) return 0;' + NL +
        '    return rules::wisMagicalAttackAdj(wis);' + NL +
        '}')

new2 = ('int spellSaveModWis(SpellId id, uint8_t wis) {' + NL +
        '    // R227: delegates to the mental-form gate' + NL +
        '    // seam (rules/wisdom.h) - the same' + NL +
        '    // ladder, now wired into the spelleffects' + NL +
        '    // save chokepoint.' + NL +
        '    return rules::wisMentalSaveAdj(wis, spellIsMentalForm(id));' + NL +
        '}')

patch('spells/spells.cpp',
      'R227: delegates to the mental-form gate',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: spelleffects/spelleffects.h - the saveWis descriptor field
# ---------------------------------------------------------------------------

old3 = ('    int saveClass   = 0;' + NL +
        '    int saveLevel   = 1;' + NL +
        '    int saveBonus   = 0;')

new3 = ('    int saveClass   = 0;' + NL +
        '    int saveLevel   = 1;' + NL +
        '    int saveBonus   = 0;' + NL +
        '    // R227: the defender WIS - the Wisdom' + NL +
        '    // Table I magical defense adjustment' + NL +
        '    // rides the descriptor; resolveSpell' + NL +
        '    // folds spellSaveModWis(id, saveWis)' + NL +
        '    // into saveBonus (the WIS magic adj' + NL +
        '    // carrier the doc comment above' + NL +
        '    // reserved). Monsters keep the 10' + NL +
        '    // default - no adjustment (a' + NL +
        '    // character table).' + NL +
        '    uint8_t saveWis = 10;')

patch('spelleffects/spelleffects.h',
      'R227: the defender WIS - the Wisdom',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: spelleffects/spelleffects.cpp - the chokepoint fold
# ---------------------------------------------------------------------------

old4 = ('    for (const TargetDesc& t : targets) {' + NL +
        '        TargetResult r;')

new4 = ('    for (TargetDesc t : targets) {' + NL +
        '        // R227: t is now a per-target copy:' + NL +
        '        // the Wisdom Table I magical defense' + NL +
        '        // adjustment (mental-form spells' + NL +
        '        // only; the WIS rides the descriptor)' + NL +
        '        // folds into saveBonus here - the' + NL +
        '        // field the TargetDesc comment' + NL +
        '        // reserves for it - so trySave pays' + NL +
        '        // it with every other caller-side' + NL +
        '        // modifier. The gate reads the spell' + NL +
        '        // id (charm person and charm monster' + NL +
        '        // are the registry mental forms' + NL +
        '        // today).' + NL +
        '        t.saveBonus += spells::spellSaveModWis(id, t.saveWis);' + NL +
        '        TargetResult r;')

patch('spelleffects/spelleffects.cpp',
      'R227: t is now a per-target copy:',
      old4,
      new4)

# ---------------------------------------------------------------------------
# Patch 5: ai/actor.cpp - asTarget sets the WIS
# ---------------------------------------------------------------------------

old5 = '    t.magicResistPct = isCharacter ? 0 : magicResistPct;'

new5 = ('    // R227: the defender WIS rides the' + NL +
        '    // descriptor - the Wisdom Table I' + NL +
        '    // magical defense adjustment on' + NL +
        '    // mental-form spell saves; monsters' + NL +
        '    // keep the 10 default (no adjustment).' + NL +
        '    t.saveWis = wis;' + NL +
        '    t.magicResistPct = isCharacter ? 0 : magicResistPct;')

patch('ai/actor.cpp',
      'R227: the defender WIS rides the',
      old5,
      new5)

# ---------------------------------------------------------------------------
# Patch 6: regtest.cpp - the R227 audit block
# ---------------------------------------------------------------------------

audit_lines = [
    '    // ---- R227: the wis mental save wiring audit ----',
    '    // PHB Wisdom Table I: the magical attack',
    '    // saving throw adjustment now reaches the',
    '    // spell save rolls - the R192 ladder had',
    '    // zero callers. The gate seam',
    '    // rules::wisMentalSaveAdj (wisdom.h); the',
    '    // delegation spells::spellSaveModWis; the',
    '    // spelleffects fold (saveBonus carries the',
    '    // gated ladder; the descriptor carries the',
    '    // defender WIS). Charm person and charm',
    '    // monster are the registry mental forms.',
    '    {',
    '        int bad = 0;',
    '        if (rules::wisMentalSaveAdj(3, true) != -3 ||',
    '            rules::wisMentalSaveAdj(4, true) != -2 ||',
    '            rules::wisMentalSaveAdj(5, true) != -1 ||',
    '            rules::wisMentalSaveAdj(7, true) != -1 ||',
    '            rules::wisMentalSaveAdj(8, true) != 0 ||',
    '            rules::wisMentalSaveAdj(14, true) != 0 ||',
    '            rules::wisMentalSaveAdj(15, true) != 1 ||',
    '            rules::wisMentalSaveAdj(16, true) != 2 ||',
    '            rules::wisMentalSaveAdj(17, true) != 3 ||',
    '            rules::wisMentalSaveAdj(18, true) != 4) ++bad;',
    '        // the ladder clamps (below 3, above 18)',
    '        if (rules::wisMentalSaveAdj(0, true) != -3 ||',
    '            rules::wisMentalSaveAdj(19, true) != 4 ||',
    '            rules::wisMentalSaveAdj(25, true) != 4) ++bad;',
    '        // non-mental forms read flat 0',
    '        if (rules::wisMentalSaveAdj(18, false) != 0 ||',
    '            rules::wisMentalSaveAdj(3, false) != 0 ||',
    '            rules::wisMentalSaveAdj(10, false) != 0) ++bad;',
    '        // ladder consistency: the gated form',
    '        // equals the R192 ladder cell by cell',
    '        for (int w = 3; w <= 18; ++w)',
    '            if (rules::wisMentalSaveAdj(w, true) !=',
    '                    rules::wisMagicalAttackAdj(w) ||',
    '                rules::wisMentalSaveAdj(w, false) != 0) ++bad;',
    '        // the fold: an existing caller-side',
    '        // saveBonus rides WITH the gate, not',
    '        // instead of it (+2 probe)',
    '        static const int kW[5] = { 3, 8, 12, 15, 18, };',
    '        for (int i = 0; i < 5; ++i)',
    '            if (rules::wisMentalSaveAdj(kW[i], true) + 2 !=',
    '                    rules::wisMagicalAttackAdj(kW[i]) + 2) ++bad;',
    '        for (int i = 0; i < 5; ++i)',
    '            if (rules::wisMentalSaveAdj(kW[i], false) + 2 != 2) ++bad;',
    '        printf("R227 wis mental save wiring audit: bad %d" + BS + "n", bad);',
    '        if (bad) return 1;',
    '    }',
    '',
]
audit = NL.join(audit_lines)

old6 = '    // ---- R163: the poison table audit -------------'

new6 = audit + old6

patch('regtest.cpp',
      'R227: the wis mental save wiring audit',
      old6,
      new6)

# ---------------------------------------------------------------------------
# Patch 7: tools/phb_gap_report.md - the wiring arc opens
# ---------------------------------------------------------------------------

log_lines = [
    '## The wiring arc (OPENED R227 - the engine-call pass)',
    '',
    'The R179-R187 subclass layers and the DMG',
    'pin rounds landed DATA; the engine-call',
    'pass wires what has zero callers outside',
    'regtest. The founding read found: the',
    'Wisdom Table I magical defense adjustment',
    'unwired, the subclass registry playable by',
    'no character, the druid and illusionist',
    'rosters outside the SpellId enum, and the',
    'multi/dual-class layers data-only. The',
    'arc boxes:',
    '',
    '- [x] R227 the Wisdom Table I save wire - WIRED:',
    '      rules/wisdom.h gains the mental-form',
    '      gate seam wisMentalSaveAdj (the gated',
    '      ladder, flat 0 on non-mental forms);',
    '      spells::spellSaveModWis delegates to it',
    '      (it existed with zero callers); the',
    '      spelleffects TargetDesc gains saveWis',
    '      (10 default - monsters read no',
    '      adjustment, a character table);',
    '      resolveSpell folds the gate into',
    '      saveBonus - the field the TargetDesc',
    '      comment always reserved for the WIS',
    '      magic adj - so every spell save through',
    '      the chokepoint pays the ladder;',
    '      Actor::asTarget sets it for characters.',
    '      Charm person and charm monster are the',
    '      registry mental forms today; fear,',
    '      hypnosis, suggestion and phantasmal',
    '      forces ride the flag when their rows',
    '      arrive. Census 143.',
    '- [ ] R228 the druid and illusionist rosters',
    '      join the SpellId registry (139 spells,',
    '      rules/druidspells.h + illusionspells.h',
    '      are dead data today) - the largest item,',
    '      may split.',
    '- [ ] the subclass creation gates - no',
    '      character can yet BE a paladin, ranger,',
    '      druid, illusionist, assassin, monk or',
    '      bard (registry + gates + specials all',
    '      data-only).',
    '- [ ] the per-subclass specials hooks (lay on',
    '      hands, giant-class bonus, the monk',
    '      unarmed ladder, backstab multipliers).',
    '- [ ] multi-class and dual-class engine',
    '      (R185 data + comments, no runtime).',
]
log_entry = NL.join(log_lines)

old7 = ('stay queued BEFORE the arc rounds - the live DEX' + NL +
        'and CON bugs first.')

new7 = (old7 + NL + NL + log_entry + NL)

patch('tools/phb_gap_report.md',
      'The wiring arc (OPENED R227 - the engine-call pass)',
      old7,
      new7)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 7, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R227 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R227 note: 7 patches; the Wisdom Table I save wire landed -')
print('the mental-form gate seam, the delegation, the descriptor')
print('field, the chokepoint fold and the actor wiring; census 143.')
print('commit: R227: the Wisdom Table I save wire wired - PHB p.11, the')
print('magical defense adjustment on mental-form spell saves (census 143)')

