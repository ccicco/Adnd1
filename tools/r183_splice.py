#!/usr/bin/env python3
# R183 splice: the illusionist spell layer.
#
# rules/illusionspells.h is CREATED: the
# SPELLS USABLE BY CLASS AND LEVEL - ILLUSIONISTS
# table (26 illusionist levels x 7 spell levels,
# every printed cell) and the full illusionist
# spell roster - 61 spells in the printed book
# order with the level (PHB, the illusionist
# class section table and the ILLUSIONIST SPELLS
# section).
#
# regtest.cpp: the include lands WITH the audit (the
# R179 lesson); the R183 battery audit walks every
# slot cell, every roster row, the per-level counts
# and name spot-checks. Census 100.
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
# Patch 1: rules/illusionspells.h CREATED
# ---------------------------------------------------------------------------

# the roster: (level, name) - the printed book order;
# the illusionist section prints NO Reversible
# markers (Continual Darkness and Continual Light
# are separate listed spells, not reverses)
roster = [
    (1, 'Audible Glamer'),
    (1, 'Detect Invisibility'),
    (1, 'Change Self'),
    (1, 'Gaze Reflection'),
    (1, 'Hypnotism'),
    (1, 'Light'),
    (1, 'Phantasmal Force'),
    (1, 'Wall Of Fog'),
    (2, 'Blindness'),
    (2, 'Blur'),
    (2, 'Deafness'),
    (2, 'Detect Magic'),
    (2, 'Fog Cloud'),
    (2, 'Hypnotic Pattern'),
    (2, 'Improved Phantasmal Force'),
    (2, 'Invisibility'),
    (2, 'Dispel Illusion'),
    (2, 'Magic Mouth'),
    (2, 'Fear'),
    (2, 'Mirror Image'),
    (2, 'Hallucinatory Terrain'),
    (2, 'Misdirection'),
    (2, 'Illusionary Script'),
    (2, 'Ventriloquism'),
    (3, 'Invisibility, 10' + Q + ' Radius'),
    (3, 'Continual Darkness'),
    (3, 'Continual Light'),
    (3, 'Non-detection'),
    (3, 'Emotion'),
    (3, 'Paralyzation'),
    (3, 'Rope Trick'),
    (3, 'Spectral Force'),
    (3, 'Improved Invisibility'),
    (3, 'Suggestion'),
    (3, 'Massmorph'),
    (4, 'Confusion'),
    (4, 'Dispel Exhaustion'),
    (4, 'Minor Creation'),
    (4, 'Phantasmal Killer'),
    (4, 'Shadow Monsters'),
    (5, 'Chaos'),
    (5, 'Demi-Shadow Monsters'),
    (5, 'Major Creation'),
    (5, 'Maze'),
    (5, 'Projected Image'),
    (5, 'Mass Suggestion'),
    (5, 'Shadow Door'),
    (5, 'Permanent Illusion'),
    (5, 'Shadow Magic'),
    (5, 'Programmed Illusion'),
    (5, 'Summon Shadow'),
    (5, 'Shades'),
    (6, 'Conjure Animals'),
    (6, 'True Sight'),
    (6, 'Demi-Shadow Magic'),
    (6, 'Veil'),
    (7, 'Alter Reality'),
    (7, 'Astral Spell'),
    (7, 'Prismatic Spray'),
    (7, 'Prismatic Wall'),
    (7, 'Vision'),
]

# the printed slots: 26 illusionist levels x 7 spell levels
slots = [
    [1, 0, 0, 0, 0, 0, 0],
    [2, 0, 0, 0, 0, 0, 0],
    [2, 1, 0, 0, 0, 0, 0],
    [3, 2, 0, 0, 0, 0, 0],
    [4, 2, 1, 0, 0, 0, 0],
    [4, 3, 1, 0, 0, 0, 0],
    [4, 3, 2, 0, 0, 0, 0],
    [4, 3, 2, 1, 0, 0, 0],
    [5, 3, 3, 2, 0, 0, 0],
    [5, 4, 3, 2, 1, 0, 0],
    [5, 4, 3, 3, 2, 0, 0],
    [5, 5, 4, 3, 2, 1, 0],
    [5, 5, 4, 3, 2, 2, 0],
    [5, 5, 4, 3, 2, 2, 1],
    [5, 5, 4, 4, 2, 2, 2],
    [5, 5, 5, 4, 3, 2, 2],
    [5, 5, 5, 5, 3, 2, 2],
    [5, 5, 5, 5, 3, 3, 2],
    [5, 5, 5, 5, 4, 3, 2],
    [5, 5, 5, 5, 4, 3, 3],
    [5, 5, 5, 5, 5, 4, 3],
    [5, 5, 5, 5, 5, 5, 4],
    [5, 5, 5, 5, 5, 5, 5],
    [6, 6, 6, 6, 5, 5, 5],
    [6, 6, 6, 6, 6, 6, 6],
    [7, 7, 7, 7, 6, 6, 6],
]

assert len(roster) == 61, 'roster count drift'
assert sum(1 for r in roster if r[0] == 1) == 8
assert sum(1 for r in roster if r[0] == 2) == 16
assert sum(1 for r in roster if r[0] == 3) == 11
assert sum(1 for r in roster if r[0] == 4) == 5
assert sum(1 for r in roster if r[0] == 5) == 12
assert sum(1 for r in roster if r[0] == 6) == 4
assert sum(1 for r in roster if r[0] == 7) == 5
assert len(slots) == 26 and all(len(r) == 7 for r in slots)

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/illusionspells.h')
a('// The illusionist spell layer (R183).')
a('//')
a('// The SPELLS USABLE BY CLASS AND LEVEL - ILLUSIONISTS table')
a('// (26 illusionist levels x 7 spell levels, every printed')
a('// cell) and the full illusionist spell roster - 61 spells')
a('// in the printed book order (the PHB illusionist section).')
a('//')
a('// JUDGMENTs:')
a('//   - the printed table dashes (no slots) pin as 0.')
a('//   - the illusionist section prints NO Reversible')
a('//     markers (unlike the druid list): Continual Darkness')
a('//     and Continual Light are separate listed spells, not')
a('//     reverses of one another; the roster carries no')
a('//     reversible flag.')
a('//   - the roster order is the printed section order, not')
a('//     alphabetical (the book order within each level).')
a('//   - the printed table runs to illusionist level 26; slot')
a('//     queries past it clamp to the 26th-level row.')
a('//')
a('// DATA-DRIVEN (the standing scope): the same roster shape')
a('// as the druid layer (R182); a future list lands the same')
a('// way.')
a('// ============================================================================')
a('')
a('#pragma once')
a('')
a('#include <cstdint>')
a('')
a('namespace rules {')
a('')
a('// The number of spell slots of spellLevel (1-7) usable')
a('// by an illusionist of illusionistLevel (1-26; past it,')
a('// the 26th row).')
a('inline int illusionistSpellSlots(int illusionistLevel,')
a('                           int spellLevel) {')
a('    static const int kSlots[26][7] = {')
for row in slots:
    a('        { ' + ', '.join(str(x) for x in row) + ' },')
a('    };')
a('    if (illusionistLevel < 1) illusionistLevel = 1;')
a('    if (illusionistLevel > 26) illusionistLevel = 26;')
a('    if (spellLevel < 1) spellLevel = 1;')
a('    if (spellLevel > 7) spellLevel = 7;')
a('    return kSlots[illusionistLevel - 1][spellLevel - 1];')
a('}')
a('')
a('// ---- the roster (61 printed spells) ----')
a('')
a('struct IllusionistSpell {')
a('    int level;        // 1-7')
a('    const char* name; // the printed name')
a('};')
a('')
a('static const IllusionistSpell kIllusionistSpells[61] = {')
for lv, name in roster:
    a('    { ' + str(lv) + ', "' + name + '" },')
a('};')
a('')
a('inline int illusionistSpellTotal() { return 61; }')
a('')
a('inline const IllusionistSpell& illusionistSpell(int i) {')
a('    if (i < 0) i = 0;')
a('    if (i > 60) i = 60;')
a('    return kIllusionistSpells[i];')
a('}')
a('')
a('// The number of roster spells of the given level')
a('// (8/16/11/5/12/4/5).')
a('inline int illusionistSpellCountByLevel(int spellLevel) {')
a('    if (spellLevel < 1) spellLevel = 1;')
a('    if (spellLevel > 7) spellLevel = 7;')
a('    static const int kByLevel[7] =')
a('        { 8, 16, 11, 5, 12, 4, 5 };')
a('    return kByLevel[spellLevel - 1];')
a('}')
a('')
a('} // namespace rules')

create('rules/illusionspells.h',
       'The illusionist spell layer (R183)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/illusionspells.h',
      '#include "rules/druidspells.h"  // R182: the druid spell layer',
      '#include "rules/druidspells.h"  // R182: the druid spell layer'
      + NL + '#include "rules/illusionspells.h"  // R183: the illusionist spell layer')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R183 battery audit (census 100)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R183: the illusionist spell layer audit ----')
a('    // Every printed slot cell of the 26x7 table, every')
a('    // roster row, the per-level counts and name spot-')
a('    // checks from the print.')
a('    {')
a('        int bad = 0;')
a('        // the full slots table, cell by cell')
a('        static const int kSlots[26][7] = {')
for row in slots:
    a('            { ' + ', '.join(str(x) for x in row) + ' },')
a('        };')
a('        for (int il = 1; il <= 26; ++il)')
a('            for (int sl = 1; sl <= 7; ++sl)')
a('                if (rules::illusionistSpellSlots(il, sl)')
a('                    != kSlots[il-1][sl-1]) ++bad;')
a('        // the clamps: level 0 and 99 read level 1 and 26;')
a('        // spell level 0 and 99 read 1 and 7')
a('        if (rules::illusionistSpellSlots(0, 1) != 1) ++bad;')
a('        if (rules::illusionistSpellSlots(99, 7) != 6) ++bad;')
a('        if (rules::illusionistSpellSlots(26, 8) != 6) ++bad;')
a('        if (rules::illusionistSpellSlots(1, 0) != 1) ++bad;')
a('        // the roster: 61 rows, every level')
a('        if (rules::illusionistSpellTotal() != 61) ++bad;')
a('        int byLevel[8] = { 0, 0, 0, 0,  0, 0, 0, 0 };')
a('        for (int i = 0; i < 61; ++i) {')
a('            const rules::IllusionistSpell& s =')
a('                rules::illusionistSpell(i);')
a('            if (s.level < 1 || s.level > 7) ++bad;')
a('            byLevel[s.level] += 1;')
a('        }')
a('        // the printed per-level counts 8/16/11/5/12/4/5')
a('        if (byLevel[1] != 8 || byLevel[2] != 16')
a('            || byLevel[3] != 11 || byLevel[4] != 5) ++bad;')
a('        if (byLevel[5] != 12 || byLevel[6] != 4')
a('            || byLevel[7] != 5) ++bad;')
a('        for (int sl = 1; sl <= 7; ++sl) {')
a('            int want = (sl == 1) ? 8')
a('                : ((sl == 2) ? 16 : ((sl == 3) ? 11')
a('                : ((sl == 4) ? 5 : ((sl == 5) ? 12')
a('                : ((sl == 6) ? 4 : 5)))));')
a('            if (rules::illusionistSpellCountByLevel(sl)')
a('                != want) ++bad;')
a('        }')
a('        // name spot-checks (the print, the book order)')
a('        if (std::string(rules::illusionistSpell(0).name)')
a('            != "Audible Glamer") ++bad;')
a('        if (std::string(rules::illusionistSpell(7).name)')
a('            != "Wall Of Fog") ++bad;')
a('        if (std::string(rules::illusionistSpell(8).name)')
a('            != "Blindness") ++bad;')
a('        if (std::string(rules::illusionistSpell(23).name)')
a('            != "Ventriloquism") ++bad;')
a('        if (std::string(rules::illusionistSpell(24).name)')
a('            != "Invisibility, 10' + Q + ' Radius") ++bad;')
a('        if (std::string(rules::illusionistSpell(34).name)')
a('            != "Massmorph") ++bad;')
a('        if (std::string(rules::illusionistSpell(39).name)')
a('            != "Shadow Monsters") ++bad;')
a('        if (std::string(rules::illusionistSpell(51).name)')
a('            != "Shades") ++bad;')
a('        if (std::string(rules::illusionistSpell(55).name)')
a('            != "Veil") ++bad;')
a('        if (std::string(rules::illusionistSpell(60).name)')
a('            != "Vision") ++bad;')
a('        // roster index spot-probes: level-1 rows 0-7,')
a('        // level-2 8-23, level-3 24-34, level-4 35-39,')
a('        // level-5 40-51, level-6 52-55, level-7 56-60')
a('        if (rules::illusionistSpell(8).level != 2) ++bad;')
a('        if (rules::illusionistSpell(24).level != 3) ++bad;')
a('        if (rules::illusionistSpell(35).level != 4) ++bad;')
a('        if (rules::illusionistSpell(40).level != 5) ++bad;')
a('        if (rules::illusionistSpell(52).level != 6) ++bad;')
a('        if (rules::illusionistSpell(56).level != 7) ++bad;')
a('        printf("R183 illusionist spell layer audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# roster index pre-asserts (the R182 lesson): every
# spot-check index verified against the roster
assert roster[0][1] == 'Audible Glamer'
assert roster[7][1] == 'Wall Of Fog'
assert roster[8][1] == 'Blindness'
assert roster[23][1] == 'Ventriloquism'
assert roster[24][1] == 'Invisibility, 10' + Q + ' Radius'
assert roster[34][1] == 'Massmorph'
assert roster[39][1] == 'Shadow Monsters'
assert roster[51][1] == 'Shades'
assert roster[55][1] == 'Veil'
assert roster[60][1] == 'Vision'
assert roster[8][0] == 2 and roster[24][0] == 3
assert roster[35][0] == 4 and roster[40][0] == 5
assert roster[52][0] == 6 and roster[56][0] == 7

# clamp probe pre-asserts against the clamped table
assert slots[min(max(0, 1), 26) - 1][min(max(1, 1), 7) - 1] == 1
assert slots[min(max(99, 1), 26) - 1][min(max(7, 1), 7) - 1] == 6
assert slots[min(max(26, 1), 26) - 1][min(max(8, 1), 7) - 1] == 6
assert slots[min(max(1, 1), 26) - 1][min(max(0, 1), 7) - 1] == 1

patch('regtest.cpp',
      'R183 illusionist spell layer audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the R183 box flipped
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'R183 the illusionist spell layer - PINNED',
      '- R183 the illusionist spell layer - the'
      + NL + '      illusionist list likewise.',
      '- [x] R183 the illusionist spell layer - PINNED:'
      + NL + '      rules/illusionspells.h CREATED: the SPELLS'
      + NL + '      USABLE BY CLASS AND LEVEL - ILLUSIONISTS'
      + NL + '      table (26 illusionist levels x 7 spell'
      + NL + '      levels, every printed cell: level 1 reads'
      + NL + '      one first-level slot, the 26th reads'
      + NL + '      7/7/7/7/6/6/6, the dashes pin as 0,'
      + NL + '      past-26th queries clamp to the 26th row)'
      + NL + '      and the full roster - 61 spells in the'
      + NL + '      printed book order (per-level counts'
      + NL + '      8/16/11/5/12/4/5; Audible Glamer through'
      + NL + '      Vision). JUDGMENT: the illusionist section'
      + NL + '      prints NO Reversible markers (Continual'
      + NL + '      Darkness and Continual Light are separate'
      + NL + '      listed spells), so the roster carries no'
      + NL + '      reversible flag. The R183 battery audit'
      + NL + '      walks every slot cell, every roster row and'
      + NL + '      name spot-checks. Census 100.')

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R183 landed the illusionist spell layer',
      'audit; census 99. Next: R183 the illusionist'
      + NL + 'spell layer.',
      'audit; census 99. Next: R183 the illusionist'
      + NL + 'spell layer.'
      + NL + 'R183 landed the illusionist spell layer:'
      + NL + 'rules/illusionspells.h CREATED (the 26x7'
      + NL + 'spells-usable table cell by cell, the 61-'
      + NL + 'spell roster in the printed book order; no'
      + NL + 'reversible flags - the section prints none).'
      + NL + 'New R183 battery audit; census 100. Next:'
      + NL + 'R184 the paladin and ranger spell layers.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R183 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R183 note: 5 patches; census 100 (one new audit);')
print('real gate: md5sum rules/illusionspells.h')
print('commit: R183: the illusionist spell layer pinned - the')
print('slots table and the 61-spell roster (census 100)')

