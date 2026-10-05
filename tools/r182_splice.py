#!/usr/bin/env python3
# R182 splice: the druid spell layer.
#
# rules/druidspells.h is CREATED: the druid
# spells-usable-by-class-and-level table (14 druid
# levels x 7 spell levels, every printed cell) and
# the full druid spell roster - 77 spells with the
# printed level and the reversible flag (PHB, the
# SPELLS USABLE BY CLASS AND LEVEL - DRUIDS table
# and the DRUID SPELLS section).
#
# regtest.cpp: the include lands WITH the audit (the
# R179 lesson); the R182 battery audit walks every
# slot cell, every roster row, the per-level counts
# and the reversible flags, plus name spot-checks.
# Census 99.
#
# Patches: 5.

import os

BS = chr(92)
NL = chr(10)
Q = chr(39)

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
    wr(path, t)
    applied += 1


def create(path, marker, content):
    # created-file patch; presence of the marker line = already
    global applied, already
    if os.path.exists(path):
        already += 1
        return
    assert marker in content, 'create marker missing'
    wr(path, content)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/druidspells.h CREATED
# ---------------------------------------------------------------------------

# the roster: (level, name, reversible)
roster = [
    (1, 'Animal Friendship', 0),
    (1, 'Detect Magic', 0),
    (1, 'Detect Snares & Pits', 0),
    (1, 'Entangle', 0),
    (1, 'Faerie Fire', 0),
    (1, 'Invisibility To Animals', 0),
    (1, 'Locate Animals', 0),
    (1, 'Pass Without Trace', 0),
    (1, 'Predict Weather', 0),
    (1, 'Purify Water', 1),
    (1, 'Shillelagh', 0),
    (1, 'Speak With Animals', 0),
    (2, 'Barkskin', 0),
    (2, 'Charm Person Or Mammal', 0),
    (2, 'Create Water', 0),
    (2, 'Cure Light Wounds', 1),
    (2, 'Feign Death', 0),
    (2, 'Fire Trap', 0),
    (2, 'Heat Metal', 1),
    (2, 'Locate Plants', 0),
    (2, 'Obscurement', 0),
    (2, 'Produce Flame', 0),
    (2, 'Trip', 0),
    (2, 'Warp Wood', 0),
    (3, 'Call Lightning', 0),
    (3, 'Cure Disease', 1),
    (3, 'Hold Animal', 0),
    (3, 'Neutralize Poison', 1),
    (3, 'Plant Growth', 0),
    (3, 'Protection From Fire', 0),
    (3, 'Pyrotechnics', 0),
    (3, 'Snare', 0),
    (3, 'Stone Shape', 0),
    (3, 'Summon Insects', 0),
    (3, 'Tree', 0),
    (3, 'Water Breathing', 1),
    (4, 'Animal Summoning I', 0),
    (4, 'Call Woodland Beings', 0),
    (4, 'Control Temperature, 10' + Q + ' Radius', 0),
    (4, 'Cure Serious Wounds', 1),
    (4, 'Dispel Magic', 0),
    (4, 'Hallucinatory Forest', 1),
    (4, 'Hold Plant', 0),
    (4, 'Plant Door', 0),
    (4, 'Produce Fire', 1),
    (4, 'Protection From Lightning', 0),
    (4, 'Repel Insects', 0),
    (4, 'Speak With Plants', 0),
    (5, 'Animal Growth', 1),
    (5, 'Animal Summoning II', 0),
    (5, 'Anti-Plant Shell', 0),
    (5, 'Commune With Nature', 0),
    (5, 'Control Winds', 0),
    (5, 'Insect Plague', 0),
    (5, 'Wall of Fire', 0),
    (5, 'Pass Plant', 0),
    (6, 'Animal Summoning III', 0),
    (6, 'Anti-Animal Shell', 0),
    (6, 'Sticks to Snakes', 1),
    (6, 'Conjure Fire Elemental', 1),
    (6, 'Transmute Rock to Mud', 1),
    (6, 'Cure Critical Wounds', 1),
    (6, 'Feeblemind', 0),
    (6, 'Transport Via Plants', 0),
    (6, 'Turn Wood', 0),
    (6, 'Wall of Thorns', 0),
    (6, 'Weather Summoning', 0),
    (6, 'Confusion', 0),
    (7, 'Animate Rock', 0),
    (7, 'Conjure Earth Elemental', 1),
    (7, 'Control Weather', 0),
    (7, 'Chariot Of Sustarre', 0),
    (7, 'Creeping Doom', 0),
    (7, 'Finger Of Death', 0),
    (7, 'Fire Storm', 1),
    (7, 'Reincarnate', 0),
    (7, 'Transmute Metal To Wood', 0),
]

# the printed slots: 14 druid levels x 7 spell levels
slots = [
    [2, 0, 0, 0, 0, 0, 0],
    [2, 1, 0, 0, 0, 0, 0],
    [3, 2, 1, 0, 0, 0, 0],
    [4, 2, 2, 0, 0, 0, 0],
    [4, 3, 2, 0, 0, 0, 0],
    [4, 3, 2, 1, 0, 0, 0],
    [4, 4, 3, 1, 0, 0, 0],
    [4, 4, 3, 2, 0, 0, 0],
    [5, 4, 3, 2, 1, 0, 0],
    [5, 4, 3, 3, 2, 0, 0],
    [5, 5, 3, 3, 2, 1, 0],
    [5, 5, 4, 4, 3, 2, 1],
    [6, 5, 5, 5, 4, 3, 2],
    [6, 6, 6, 6, 5, 4, 3],
]

assert len(roster) == 77, 'roster count drift'
assert sum(1 for r in roster if r[0] == 1) == 12
assert sum(1 for r in roster if r[0] == 2) == 12
assert sum(1 for r in roster if r[0] == 3) == 12
assert sum(1 for r in roster if r[0] == 4) == 12
assert sum(1 for r in roster if r[0] == 5) == 8
assert sum(1 for r in roster if r[0] == 6) == 12
assert sum(1 for r in roster if r[0] == 7) == 9
assert sum(1 for r in roster if r[2] == 1) == 16, 'reversible count drift'
assert len(slots) == 14 and all(len(r) == 7 for r in slots)

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/druidspells.h')
a('// The druid spell layer (R182).')
a('//')
a('// The SPELLS USABLE BY CLASS AND LEVEL - DRUIDS table')
a('// (14 druid levels x 7 spell levels, every printed cell)')
a('// and the full druid spell roster - 77 spells with the')
a('// printed level and the reversible flag. The druid')
a('// spell-sourcing rules (the mistletoe religious symbol,')
a('// the component-reduction percentages for lesser')
a('// mistletoe / borrowed mistletoe / holly / oak leaves)')
a('// are display and flavor; the metal-armor spoilage and')
a('// the no-turn-undead notes are recorded in the R180')
a('// gates round commentary.')
a('//')
a('// JUDGMENTs:')
a('//   - the printed table dashes (no slots) pin as 0.')
a('//   - the druid hierarchy tops at the 14th level; slot')
a('//     queries past it clamp to the 14th-level row.')
a('//   - the roster order is the printed alphabetical')
a('//     order within each level (the DRUID SPELLS')
a('//     section order).')
a('//')
a('// DATA-DRIVEN (the standing scope): a future spell list')
a('// (the illusionist layer, the bard druidical casting)')
a('// lands as its own roster file with the same shape.')
a('// ============================================================================')
a('')
a('#pragma once')
a('')
a('#include <cstdint>')
a('')
a('namespace rules {')
a('')
a('// The number of spell slots of spellLevel (1-7) usable')
a('// by a druid of druidLevel (1-14; past it, the 14th row).')
a('inline int druidSpellSlots(int druidLevel, int spellLevel) {')
a('    static const int kSlots[14][7] = {')
for row in slots:
    a('        { ' + ', '.join(str(x) for x in row) + ' },')
a('    };')
a('    if (druidLevel < 1) druidLevel = 1;')
a('    if (druidLevel > 14) druidLevel = 14;')
a('    if (spellLevel < 1) spellLevel = 1;')
a('    if (spellLevel > 7) spellLevel = 7;')
a('    return kSlots[druidLevel - 1][spellLevel - 1];')
a('}')
a('')
a('// ---- the roster (77 printed spells) ----')
a('')
a('struct DruidSpell {')
a('    int level;        // 1-7')
a('    const char* name; // the printed name')
a('    int reversible;   // the printed Reversible marker')
a('};')
a('')
a('static const DruidSpell kDruidSpells[77] = {')
for lv, name, rev in roster:
    a('    { ' + str(lv) + ', "' + name + '", ' + str(rev) + ' },')
a('};')
a('')
a('inline int druidSpellTotal() { return 77; }')
a('')
a('inline const DruidSpell& druidSpell(int i) {')
a('    if (i < 0) i = 0;')
a('    if (i > 76) i = 76;')
a('    return kDruidSpells[i];')
a('}')
a('')
a('// The number of roster spells of the given level')
a('// (12/12/12/12/8/12/9).')
a('inline int druidSpellCountByLevel(int spellLevel) {')
a('    if (spellLevel < 1) spellLevel = 1;')
a('    if (spellLevel > 7) spellLevel = 7;')
a('    static const int kByLevel[7] =')
a('        { 12, 12, 12, 12, 8, 12, 9 };')
a('    return kByLevel[spellLevel - 1];')
a('}')
a('')
a('} // namespace rules')

create('rules/druidspells.h',
       'The druid spell layer (R182)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/druidspells.h',
      '#include "rules/attacksround.h"  // R181: attacks per melee round',
      '#include "rules/attacksround.h"  // R181: attacks per melee round'
      + NL + '#include "rules/druidspells.h"  // R182: the druid spell layer')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R182 battery audit (census 99)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R182: the druid spell layer audit ----')
a('    // Every printed slot cell of the 14x7 table, every')
a('    // roster row, the per-level counts, the reversible')
a('    // flags and name spot-checks from the print.')
a('    {')
a('        int bad = 0;')
a('        // the full slots table, cell by cell')
a('        static const int kSlots[14][7] = {')
for row in slots:
    a('            { ' + ', '.join(str(x) for x in row) + ' },')
a('        };')
a('        for (int dl = 1; dl <= 14; ++dl)')
a('            for (int sl = 1; sl <= 7; ++sl)')
a('                if (rules::druidSpellSlots(dl, sl)')
a('                    != kSlots[dl-1][sl-1]) ++bad;')
a('        // the clamps: level 0 and 99 read level 1 and 14;')
a('        // spell level 0 and 99 read 1 and 7')
a('        if (rules::druidSpellSlots(0, 1) != 2) ++bad;')
a('        if (rules::druidSpellSlots(99, 7) != 3) ++bad;')
a('        if (rules::druidSpellSlots(14, 8) != 3) ++bad;')
a('        if (rules::druidSpellSlots(1, 0) != 2) ++bad;')
a('        // the roster: 77 rows, every level and flag')
a('        if (rules::druidSpellTotal() != 77) ++bad;')
a('        int byLevel[8] = { 0, 0, 0, 0,  0, 0, 0, 0 };')
a('        int revCount = 0;')
a('        for (int i = 0; i < 77; ++i) {')
a('            const rules::DruidSpell& s =')
a('                rules::druidSpell(i);')
a('            if (s.level < 1 || s.level > 7) ++bad;')
a('            if (s.reversible != 0 && s.reversible != 1) ++bad;')
a('            byLevel[s.level] += 1;')
a('            revCount += s.reversible;')
a('        }')
a('        // the printed per-level counts 12/12/12/12/8/12/9')
a('        if (byLevel[1] != 12 || byLevel[2] != 12')
a('            || byLevel[3] != 12 || byLevel[4] != 12) ++bad;')
a('        if (byLevel[5] != 8 || byLevel[6] != 12')
a('            || byLevel[7] != 9) ++bad;')
a('        // 16 printed reversible spells')
a('        if (revCount != 16) ++bad;')
a('        for (int sl = 1; sl <= 7; ++sl) {')
a('            int want = (sl == 5) ? 8')
a('                : ((sl == 7) ? 9 : 12);')
a('            if (rules::druidSpellCountByLevel(sl)')
a('                != want) ++bad;')
a('        }')
a('        // name and flag spot-checks (the print)')
a('        if (std::string(rules::druidSpell(0).name)')
a('            != "Animal Friendship") ++bad;')
a('        if (std::string(rules::druidSpell(9).name)')
a('            != "Purify Water") ++bad;')
a('        if (rules::druidSpell(9).reversible != 1) ++bad;')
a('        if (std::string(rules::druidSpell(38).name)')
a('            != "Control Temperature, 10' + Q + ' Radius") ++bad;')
a('        if (std::string(rules::druidSpell(34).name)')
a('            != "Tree") ++bad;')
a('        if (std::string(rules::druidSpell(71).name)')
a('            != "Chariot Of Sustarre") ++bad;')
a('        if (std::string(rules::druidSpell(76).name)')
a('            != "Transmute Metal To Wood") ++bad;')
a('        if (rules::druidSpell(76).level != 7) ++bad;')
a('        if (rules::druidSpell(69).reversible != 1) ++bad;')
a('        // roster index spot-probes: level-1 rows 0-11,')
a('        // level-2 rows 12-23, level-3 24-35, level-4')
a('        // 36-47, level-5 48-55, level-6 56-67, level-7 68-76')
a('        if (rules::druidSpell(12).level != 2) ++bad;')
a('        if (rules::druidSpell(36).level != 4) ++bad;')
a('        if (rules::druidSpell(48).level != 5) ++bad;')
a('        if (rules::druidSpell(56).level != 6) ++bad;')
a('        if (rules::druidSpell(68).level != 7) ++bad;')
a('        printf("R182 druid spell layer audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# roster index checks in the audit source: verify the
# spot-check indices against the roster before landing
assert roster[0][1] == 'Animal Friendship'
assert roster[9][1] == 'Purify Water' and roster[9][2] == 1
assert roster[38][1] == 'Control Temperature, 10' + Q + ' Radius'
assert roster[34][1] == 'Tree'
assert roster[71][1] == 'Chariot Of Sustarre'
assert roster[76][1] == 'Transmute Metal To Wood' and roster[76][0] == 7
assert roster[69][2] == 1, 'roster 69 reversible drift: ' + roster[69][1]
assert roster[12][0] == 2 and roster[36][0] == 4
assert roster[48][0] == 5 and roster[56][0] == 6 and roster[68][0] == 7

patch('regtest.cpp',
      'R182 druid spell layer audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the R182 box flipped
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'R182 the druid spell layer - PINNED',
      '- R182 the druid spell layer - the druid list'
      + NL + '      joins the registry with its own'
      + NL + '      spells-usable-by-level table.',
      '- [x] R182 the druid spell layer - PINNED:'
      + NL + '      rules/druidspells.h CREATED: the SPELLS'
      + NL + '      USABLE BY CLASS AND LEVEL - DRUIDS table'
      + NL + '      (14 druid levels x 7 spell levels, every'
      + NL + '      printed cell: level 1 reads two first-'
      + NL + '      level slots, the 14th reads 6/6/6/6/5/4/3,'
      + NL + '      the dashes pin as 0, past-14th queries clamp'
      + NL + '      to the 14th row) and the full roster - 77'
      + NL + '      spells with the printed level and the 16'
      + NL + '      reversible flags (per-level counts'
      + NL + '      12/12/12/12/8/12/9; Animal Friendship'
      + NL + '      through Transmute Metal To Wood, the'
      + NL + '      printed alphabetical order within each'
      + NL + '      level). The mistletoe component rules are'
      + NL + '      flavor (display concern). The R182 battery'
      + NL + '      audit walks every slot cell, every roster'
      + NL + '      row and name spot-checks. Census 99.')

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R182 landed the druid spell layer',
      'census 98. Next: R182 the druid spell layer.',
      'census 98. Next: R182 the druid spell layer.'
      + NL + 'R182 landed the druid spell layer:'
      + NL + 'rules/druidspells.h CREATED (the 14x7'
      + NL + 'spells-usable table cell by cell, the 77-'
      + NL + 'spell roster with the reversible flags;'
      + NL + 'the printed dash pins as 0, past-14th'
      + NL + 'clamps to the 14th row). New R182 battery'
      + NL + 'audit; census 99. Next: R183 the illusionist'
      + NL + 'spell layer.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R182 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R182 note: 5 patches; census 99 (one new audit);')
print('real gate: md5sum rules/druidspells.h')
print('commit: R182: the druid spell layer pinned - the slots')
print('table and the 77-spell roster (census 99)')

