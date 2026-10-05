#!/usr/bin/env python3
# R184 splice: the paladin and ranger spell layers.
#
# rules/palrangerspells.h is CREATED: the SPELLS
# USABLE BY CLASS AND LEVEL - PALADINS table (12
# rows, paladin levels 9-20 x 4 clerical spell
# levels, every printed cell) and the RANGERS
# table (10 rows, ranger levels 8-17 x 5 columns:
# druidic 1-3 and magic-user 1-2, every printed
# cell), the shared-list wiring (the paladin
# casts cleric spells; the ranger casts druid
# spells from the R182 druid roster levels 1-3
# and magic-user spells levels 1-2), and the
# printed specials the R184 box names: lay on
# hands (2 hp per level, once per day), cure
# disease (once per week per five levels), and
# the ranger giant-class damage bonus (+1 hp per
# level vs the 11 listed giant-class creatures).
#
# regtest.cpp: the include lands WITH the audit
# (the R179 lesson); the R184 battery audit walks
# every slot cell of both tables, the specials
# ladders and name spot-checks. Census 101.
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
# Patch 1: rules/palrangerspells.h CREATED
# ---------------------------------------------------------------------------

# the paladin slots: paladin levels 9-20 x clerical
# spell levels 1-4 (the print; dashes pin as 0)
pal_slots = [
    [1, 0, 0, 0],   # 9
    [2, 0, 0, 0],   # 10
    [2, 1, 0, 0],   # 11
    [2, 2, 0, 0],   # 12
    [2, 2, 1, 0],   # 13
    [3, 2, 1, 0],   # 14
    [3, 2, 1, 1],   # 15
    [3, 3, 1, 1],   # 16
    [3, 3, 2, 1],   # 17
    [3, 3, 3, 1],   # 18
    [3, 3, 3, 2],   # 19
    [3, 3, 3, 3],   # 20 (max spell ability)
]

# the ranger slots: ranger levels 8-17 x the five
# printed columns (druidic 1, 2, 3 then MU 1, 2)
rng_slots = [
    [1, 0, 0, 0, 0],   # 8
    [1, 0, 0, 1, 0],   # 9
    [2, 0, 0, 1, 0],   # 10
    [2, 0, 0, 2, 0],   # 11
    [2, 1, 0, 2, 1],   # 12
    [2, 1, 0, 2, 1],   # 13
    [2, 2, 0, 2, 2],   # 14
    [2, 2, 0, 2, 2],   # 15
    [2, 2, 1, 2, 2],   # 16
    [2, 2, 2, 2, 2],   # 17 (max spell ability)
]

# the giant-class roster (the print, 11 creatures)
giant_class = [
    'bugbear', 'ettin', 'giant', 'gnoll', 'goblin',
    'hobgoblin', 'kobold', 'ogre', 'ogre mage', 'orc',
    'troll',
]

assert len(pal_slots) == 12 and all(len(r) == 4 for r in pal_slots)
assert len(rng_slots) == 10 and all(len(r) == 5 for r in rng_slots)
assert len(giant_class) == 11

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/palrangerspells.h')
a('// The paladin and ranger spell layers (R184).')
a('//')
a('// The SPELLS USABLE BY CLASS AND LEVEL - PALADINS table')
a('// (paladin levels 9-20 x 4 clerical spell levels) and the')
a('// RANGERS table (ranger levels 8-17 x the five printed')
a('// columns: druidic 1-3 and magic-user 1-2), every printed')
a('// cell; the shared-list wiring; and the printed specials')
a('// the R184 box names - lay on hands, cure disease, the')
a('// ranger giant-class damage bonus.')
a('//')
a('// JUDGMENTs:')
a('//   - the printed table dashes (no slots) pin as 0.')
a('//   - the paladin gains cleric spell ability at 9th level')
a('//     through 20th (the print footnote: maximum spell')
a('//     ability); below 9th, no slots; past 20th, the 20th')
a('//     row clamps. The paladin casts from the CLERIC list')
a('//     (levels 1-4) but never from clerical scrolls.')
a('//   - the ranger gains druidic spell ability at 8th and')
a('//     magic-user spell ability at 9th, additions through')
a('//     the 17th (the print footnote: maximum spell ability);')
a('//     below 8th, no slots; past 17th, the 17th row clamps.')
a('//     The ranger casts druid spells from the R182 druid')
a('//     roster (levels 1-3) and magic-user spells (levels')
a('//     1-2), and must check which spells are learnable just')
a('//     as if a magic-user (the print footnote); rangers')
a('//     cannot read druid or magic-user scrolls in any event.')
a('//   - lay on hands: 2 hit points per paladin level, once')
a('//     per day. Cure disease: once per week per five levels')
a('//     (levels 1-5 one, 6-10 two, 11-15 three, and so on).')
a('//   - the giant-class damage bonus: +1 hit point per ranger')
a('//     experience level vs the 11 listed creatures. The')
a('//     ranger surprise numbers (surprises on d6 1-3, is')
a('//     surprised on 1) and the paladin turn-undead ladder')
a('//     (as a cleric of level-2 from 3rd level) are specials')
a('//     recorded for the R187+ rounds.')
a('//')
a('// DATA-DRIVEN (the standing scope): the same table shape')
a('// as the R182/R183 spell layers.')
a('// ============================================================================')
a('')
a('#pragma once')
a('')
a('#include "classes.h"')
a('')
a('#include <cstdint>')
a('')
a('namespace rules {')
a('')
a('// ---- the paladin progression ----')
a('')
a('// The clerical spell slots of spellLevel (1-4)')
a('// usable by a paladin of paladinLevel. Below')
a('// 9th level: 0 (no spell ability). Past 20th:')
a('// the 20th row (maximum spell ability).')
a('inline int paladinSpellSlots(int paladinLevel,')
a('                        int spellLevel) {')
a('    static const int kSlots[12][4] = {')
for row in pal_slots:
    a('        { ' + ', '.join(str(x) for x in row) + ' },')
a('    };')
a('    if (paladinLevel < 9) return 0;')
a('    if (paladinLevel > 20) paladinLevel = 20;')
a('    if (spellLevel < 1) spellLevel = 1;')
a('    if (spellLevel > 4) spellLevel = 4;')
a('    return kSlots[paladinLevel - 9][spellLevel - 1];')
a('}')
a('')
a('// The shared-list wiring: the paladin casts')
a('// cleric spells (never clerical scrolls).')
a('inline int paladinSpellListClass() {')
a('    return CLASS_CLERIC;')
a('}')
a('')
a('// ---- the ranger progression ----')
a('')
a('// The ranger spell slots. kind 0 = druidic,')
a('// 1 = magic-user; spellLevel 1-3 druidic, 1-2')
a('// magic-user. Below 8th level: 0. Past 17th:')
a('// the 17th row (maximum spell ability).')
a('inline int rangerSpellSlots(int rangerLevel, int kind,')
a('                       int spellLevel) {')
a('    static const int kSlots[10][5] = {')
for row in rng_slots:
    a('        { ' + ', '.join(str(x) for x in row) + ' },')
a('    };')
a('    if (rangerLevel < 8) return 0;')
a('    if (rangerLevel > 17) rangerLevel = 17;')
a('    int col;')
a('    if (kind == 0) {')
a('        if (spellLevel < 1) spellLevel = 1;')
a('        if (spellLevel > 3) spellLevel = 3;')
a('        col = spellLevel;')
a('    } else {')
a('        if (spellLevel < 1) spellLevel = 1;')
a('        if (spellLevel > 2) spellLevel = 2;')
a('        col = spellLevel + 3;')
a('    }')
a('    return kSlots[rangerLevel - 8][col - 1];')
a('}')
a('')
a('// The shared-list wiring: the ranger casts')
a('// druid spells (the R182 roster, levels 1-3)')
a('// and magic-user spells (levels 1-2).')
a('inline int rangerDruidicSpellListClass() {')
a('    return CLASS_CLERIC;   // the druid roster rides the cleric base (R179)')
a('}')
a('')
a('inline int rangerMagicSpellListClass() {')
a('    return CLASS_MAGIC_USER;')
a('}')
a('')
a('// ---- the printed specials (the R184 box) ----')
a('')
a('// Lay on hands: heals 2 hit points per paladin')
a('// level of experience, once per day.')
a('inline int paladinLayOnHandsHp(int paladinLevel) {')
a('    if (paladinLevel < 1) return 0;')
a('    return 2 * paladinLevel;')
a('}')
a('')
a('// Cure disease: once per week for each five')
a('// levels of experience (1 through 5: one,')
a('// 6 through 10: two, 11 through 15: three...).')
a('inline int paladinCureDiseasePerWeek(int paladinLevel) {')
a('    if (paladinLevel < 1) return 0;')
a('    return (paladinLevel + 4) / 5;')
a('}')
a('')
a('// The giant-class roster: the 11 listed')
a('// creatures (the print). Matching is by')
a('// lowercase name equality.')
a('inline int rangerGiantClassCount() { return 11; }')
a('')
a('inline const char* rangerGiantClassName(int i) {')
a('    static const char* const kNames[11] = {')
for n in giant_class:
    a('        "' + n + '",')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 10) i = 10;')
a('    return kNames[i];')
a('}')
a('')
a('// True when the lowercase monster name is one')
a('// of the 11 giant-class creatures.')
a('inline bool rangerIsGiantClass(const char* name) {')
a('    if (!name) return false;')
a('    for (int i = 0; i < 11; ++i)')
a('        if (std::string(name) == rangerGiantClassName(i))')
a('            return true;')
a('    return false;')
a('}')
a('')
a('// The giant-class damage bonus: +1 hit point')
a('// per ranger experience level on a melee hit.')
a('inline int rangerGiantClassBonus(int rangerLevel) {')
a('    if (rangerLevel < 1) return 0;')
a('    return rangerLevel;')
a('}')
a('')
a('} // namespace rules')

# rangerIsGiantClass uses std::string - the include
# must be present in the header
if '#include <string>' not in NL.join(hdr):
    hdr.insert(hdr.index('#include <cstdint>') + 1,
               '#include <string>')

create('rules/palrangerspells.h',
       'The paladin and ranger spell layers (R184)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/palrangerspells.h',
      '#include "rules/illusionspells.h"  // R183: the illusionist spell layer',
      '#include "rules/illusionspells.h"  // R183: the illusionist spell layer'
      + NL + '#include "rules/palrangerspells.h"  // R184: the paladin and ranger spell layers')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R184 battery audit (census 101)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R184: the paladin and ranger spell layers audit ----')
a('    // Every printed slot cell of both progressions,')
a('    // the specials ladders and the giant-class roster.')
a('    {')
a('        int bad = 0;')
a('        // the paladin table, cell by cell (levels 9-20)')
a('        static const int kPal[12][4] = {')
for row in pal_slots:
    a('            { ' + ', '.join(str(x) for x in row) + ' },')
a('        };')
a('        for (int pl = 9; pl <= 20; ++pl)')
a('            for (int sl = 1; sl <= 4; ++sl)')
a('                if (rules::paladinSpellSlots(pl, sl)')
a('                    != kPal[pl-9][sl-1]) ++bad;')
a('        // the ranger table, cell by cell (levels 8-17,')
a('        // druidic 1-3 and MU 1-2)')
a('        static const int kRng[10][5] = {')
for row in rng_slots:
    a('            { ' + ', '.join(str(x) for x in row) + ' },')
a('        };')
a('        for (int rl = 8; rl <= 17; ++rl) {')
a('            for (int sl = 1; sl <= 3; ++sl)')
a('                if (rules::rangerSpellSlots(rl, 0, sl)')
a('                    != kRng[rl-8][sl-1]) ++bad;')
a('            for (int sl = 1; sl <= 2; ++sl)')
a('                if (rules::rangerSpellSlots(rl, 1, sl)')
a('                    != kRng[rl-8][sl+2]) ++bad;')
a('        }')
a('        // below the spell bands: 0 slots')
a('        if (rules::paladinSpellSlots(8, 1) != 0) ++bad;')
a('        if (rules::paladinSpellSlots(1, 1) != 0) ++bad;')
a('        if (rules::rangerSpellSlots(7, 0, 1) != 0) ++bad;')
a('        if (rules::rangerSpellSlots(9, 1, 1) != 1) ++bad;')
a('        // the clamps: past the max-ability rows')
a('        if (rules::paladinSpellSlots(21, 1) != 3) ++bad;')
a('        if (rules::paladinSpellSlots(99, 4) != 3) ++bad;')
a('        if (rules::rangerSpellSlots(18, 0, 3) != 2) ++bad;')
a('        if (rules::rangerSpellSlots(99, 1, 2) != 2) ++bad;')
a('        // the clamps: spell level out of range reads')
a('        // the band edges (druidic 4 pins as level 3, MU 3')
a('        // as level 2)')
a('        if (rules::rangerSpellSlots(17, 0, 4) != 2) ++bad;')
a('        if (rules::rangerSpellSlots(17, 1, 3) != 2) ++bad;')
a('        // the shared-list wiring')
a('        if (rules::paladinSpellListClass()')
a('            != rules::CLASS_CLERIC) ++bad;')
a('        if (rules::rangerDruidicSpellListClass()')
a('            != rules::CLASS_CLERIC) ++bad;')
a('        if (rules::rangerMagicSpellListClass()')
a('            != rules::CLASS_MAGIC_USER) ++bad;')
a('        // lay on hands: 2 hp per level, once per day')
a('        if (rules::paladinLayOnHandsHp(1) != 2) ++bad;')
a('        if (rules::paladinLayOnHandsHp(9) != 18) ++bad;')
a('        if (rules::paladinLayOnHandsHp(20) != 40) ++bad;')
a('        if (rules::paladinLayOnHandsHp(0) != 0) ++bad;')
a('        // cure disease: one per week per five levels')
a('        if (rules::paladinCureDiseasePerWeek(1) != 1) ++bad;')
a('        if (rules::paladinCureDiseasePerWeek(5) != 1) ++bad;')
a('        if (rules::paladinCureDiseasePerWeek(6) != 2) ++bad;')
a('        if (rules::paladinCureDiseasePerWeek(10) != 2) ++bad;')
a('        if (rules::paladinCureDiseasePerWeek(11) != 3) ++bad;')
a('        if (rules::paladinCureDiseasePerWeek(15) != 3) ++bad;')
a('        if (rules::paladinCureDiseasePerWeek(16) != 4) ++bad;')
a('        // the giant-class roster: 11 creatures')
a('        if (rules::rangerGiantClassCount() != 11) ++bad;')
a('        if (std::string(rules::rangerGiantClassName(0))')
a('            != "bugbear") ++bad;')
a('        if (std::string(rules::rangerGiantClassName(10))')
a('            != "troll") ++bad;')
a('        if (!rules::rangerIsGiantClass("ogre mage")) ++bad;')
a('        if (!rules::rangerIsGiantClass("kobold")) ++bad;')
a('        if (rules::rangerIsGiantClass("ogre")) ++bad;')
a('        if (rules::rangerIsGiantClass("giant frog")) ++bad;')
a('        if (rules::rangerIsGiantClass("")) ++bad;')
a('        // the bonus: +1 per ranger level')
a('        if (rules::rangerGiantClassBonus(5) != 5) ++bad;')
a('        if (rules::rangerGiantClassBonus(17) != 17) ++bad;')
a('        if (rules::rangerGiantClassBonus(0) != 0) ++bad;')
a('        printf("R184 paladin and ranger spell layers audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# clamp probe pre-asserts against the clamped tables
def pal(pl, sl):
    if pl < 9: return 0
    pl = min(pl, 20); sl = min(max(sl, 1), 4)
    return pal_slots[pl - 9][sl - 1]

def rng(rl, kind, sl):
    if rl < 8: return 0
    rl = min(rl, 17)
    if kind == 0:
        sl = min(max(sl, 1), 3); col = sl
    else:
        sl = min(max(sl, 1), 2); col = sl + 3
    return rng_slots[rl - 8][col - 1]

for args, e in [((8,1),0),((1,1),0),((21,1),3),((99,4),3)]:
    assert pal(*args) == e, ('pal clamp', args, pal(*args), e)
for args, e in [((7,0,1),0),((9,1,1),1),((18,0,3),2),((99,1,2),2),
                ((17,0,4),2),((17,1,3),2)]:
    assert rng(*args) == e, ('rng clamp', args, rng(*args), e)
# the cure disease ladder
for lv, e in [(1,1),(5,1),(6,2),(10,2),(11,3),(15,3),(16,4)]:
    assert (lv + 4) // 5 == e, ('cure', lv)

patch('regtest.cpp',
      'R184 paladin and ranger spell layers audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the R184 box flipped
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'R184 the paladin and ranger spell layers - PINNED',
      '- R184 the paladin and ranger spell layers - the'
      + NL + '      spell progressions and the shared-list'
      + NL + '      wiring (lay on hands, curing, the ranger'
      + NL + '      giant-kind bonuses follow here).',
      '- [x] R184 the paladin and ranger spell layers - PINNED:'
      + NL + '      rules/palrangerspells.h CREATED: the'
      + NL + '      SPELLS USABLE BY CLASS AND LEVEL - PALADINS'
      + NL + '      table (levels 9-20 x 4 clerical spell'
      + NL + '      levels, every cell: 9th 1/1st, the 20th'
      + NL + '      3/3/3/3 max ability; below 9th no slots,'
      + NL + '      past 20th clamps) and the RANGERS table'
      + NL + '      (levels 8-17 x druidic 1-3 + MU 1-2,'
      + NL + '      every cell: 8th one druidic 1st, 9th adds'
      + NL + '      MU 1st, the 17th 2/2/2/2/2 max ability;'
      + NL + '      below 8th no slots, past 17th clamps),'
      + NL + '      the shared-list wiring (paladin: the cleric'
      + NL + '      list, never clerical scrolls; ranger: the'
      + NL + '      R182 druid roster levels 1-3 and the'
      + NL + '      magic-user list levels 1-2, learn-checked'
      + NL + '      as if a magic-user, no scrolls), and the'
      + NL + '      printed specials: lay on hands (2 hp per'
      + NL + '      level, once per day), cure disease (once'
      + NL + '      per week per five levels), the giant-class'
      + NL + '      damage bonus (+1 hp per ranger level vs'
      + NL + '      the 11 listed creatures: bugbear through'
      + NL + '      troll). The ranger surprise numbers and'
      + NL + '      the paladin turn-undead ladder are'
      + NL + '      recorded for R187+. The R184 battery audit'
      + NL + '      walks every cell and ladder. Census 101.')

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R184 landed the paladin and ranger spell',
      'New R183 battery audit; census 100. Next:'
      + NL + 'R184 the paladin and ranger spell layers.',
      'New R183 battery audit; census 100. Next:'
      + NL + 'R184 the paladin and ranger spell layers.'
      + NL + 'R184 landed the paladin and ranger spell'
      + NL + 'layers: rules/palrangerspells.h CREATED (the'
      + NL + 'paladin 9-20 x 4 progression, the ranger 8-17'
      + NL + 'x 5 progression, the shared-list wiring, lay'
      + NL + 'on hands, cure disease, the giant-class'
      + NL + 'roster and bonus). New R184 battery audit;'
      + NL + 'census 101. Next: R185 multi-class and'
      + NL + 'dual-class.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R184 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R184 note: 5 patches; census 101 (one new audit);')
print('real gate: md5sum rules/palrangerspells.h')
print('commit: R184: the paladin and ranger spell layers pinned -')
print('the progressions, the wiring and the specials (census 101)')

