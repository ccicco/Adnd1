#!/usr/bin/env python3
# tools/r316_splice.py - R316: the underwater
# vision seam (one splice; the R315 seed entry
# rides as the first patch - the entry names
# the landed code commit, so it lands after
# it; the letter suffix is only for errors).
#
# The charge: the DMG UNDERWATER ADVENTURES
# vision paragraph (rules/underwater.h,
# R311) - the base distance, fresh 50 feet -
# now folds at the R313 water fight as the
# first ENGINE vision state (the seam the
# R311 header predicted). The survey note:
# the surface drown percentages ALREADY
# charge at the R312 crossing
# (state_dungeon.cpp, uwSurfaceDrownPct) -
# the breathing thread is stale; and the
# upload carries no hold-breath duration to
# pin (the breathing aids ride as recorded
# notes) - a breath timer would invent
# data, so the vision seam is the charge.
#
#   (a) doc/vibe/adnd1_knowledge_seed_v2.md -
#       the R315 round-state entry (commit
#       7c3801b, census 242) and the lessons.
#   (b) ai/actor.h - the Encounter vision
#       state: setVisionFt/visionFt and the
#       m_visionFt member (zero default).
#   (c) game/state_combat.cpp - the water
#       fight sets the vision from the R311
#       pin (fresh, surface depth - the
#       shallow JUDGMENT, the R312 crossing
#       grain) and prints it; the light-spell
#       and helm multiples stay recorded (no
#       active-light or carried-item layer
#       exists), the depth decay stays data
#       (no depth layer).
#   (d) rules/swimcross.h - the seam note:
#       MOVEMENT and COMBAT charged R313,
#       VISION charges R316.
#   (e) rules/underwater.h - the recorded
#       notes: the vision distances now
#       charge the seam.
#   (f) regtest.cpp - the R316 seam audit
#       (the water fight reads 50 feet and
#       prints it, the dry fight keeps the
#       zero default, the setter seam holds
#       what the app feeds, the pin bases
#       re-assert - all draw-independent);
#       the battery census moves 242 -> 243.
#   (g) tools/dmg_gap_report.md - the
#       chronicle paragraph (no box flip).
#
# The R316 round-state entry rides the R317
# splice (it names this commit).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY
# patch (the R142 lesson). ZERO literal
# backslash bytes in this file except the
# printf continuation, built via chr(92); no
# CONTENT string embeds an apostrophe,
# non-ASCII, or a line past its bound (78 the
# header and the C++ patches, 76 regtest, 72
# the seed, 57 the gap report).
# Commit: "R316: the underwater vision seam
# (census 243)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
DQ = chr(34)
BS = chr(92)
applied, already = [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit, gap=False):
    if gap:
        assert Q not in s, 'apostrophe in gap content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

def counts(s):
    return (s.count('{'), s.count('}'),
            s.count('('), s.count(')'))

# ---- (a) the seed: the R315 round-state entry ----
SEED = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SD_ANCH = NL.join([
    '  (2) the wrapped-fragment lesson rides EVERY gap-report',
    '  assert (the R314 census assert read the unwrapped',
    '  phrase and failed in the sandbox - assert what the',
    '  57-col wrap actually printed).',
    '',
])
SD_ADD = NL.join([
    '- R315 landed 2026-10-10: commit 7c3801b, census',
    '  242, the net throwers of the waterborne table',
    '  (see Current state above). GREEN on the FIRST',
    '  preflight (no follow-up). Lessons: (1) PREFLIGHT',
    '  RIDES EVERY SPLICE - a seed or doc splice is not',
    '  exempt (the R314 convention note was wrong); (2)',
    '  ONE SPLICE PER ROUND - the seed round-state entry',
    '  rides the NEXT round splice as a patch (the entry',
    '  names the landed code commit, so it lands after',
    '  it); the letter suffix is ONLY for errors or bugs',
    '  (r312b the precedent - the R313/R314 seed rounds',
    '  broke the shape); (3) the MM arms rows read the',
    '  Lua roster - grep the monster text before any',
    '  fold; (4) no new pins - the R311 uwNet data',
    '  charged via the R37 monster-missile pattern.',
    '',
])
clean(SD_ANCH, 78)
clean(SD_ADD, 72)

s = rd(SEED)
if 'R315 landed' in s:
    already.append('the seed: the R315 entry')
else:
    assert s.count(SD_ANCH) == 1, 'seed anchor not unique'
    s = s.replace(SD_ANCH, SD_ANCH + SD_ADD, 1)
    wr(SEED, s)
    applied.append('the seed: the R315 entry')

s = rd(SEED)
assert s.count('R315 landed') == 1, 'a entry'
assert s.count('57-col wrap actually printed') == 1, 'a anchor'
assert s.count('Knowledge maintenance') == 1, 'a doc intact'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) ai/actor.h: the vision state ----
AH_ANCH = NL.join([
    '    void setAquatic() { m_aquatic = true; }',
    '',
])
AH_ADD = NL.join([
    '    void setAquatic() { m_aquatic = true; }',
    '',
    '    // R316: the underwater vision seam - the',
    '    // R311 distance pins charge this state at',
    '    // the water fight (the fresh pool surface',
    '    // reads 50 feet; the depth decay and the',
    '    // light/helm multiples stay data - no depth',
    '    // or active-light layer exists).',
    '    void setVisionFt(int ft) { m_visionFt = ft; }',
    '    int  visionFt() const { return m_visionFt; }',
    '',
])
AH_MEM_OLD = ('    bool m_aquatic = false;   '
              '// R314: the aquatic fold')
AH_MEM_NEW = NL.join([
    '    bool m_aquatic = false;   // R314: the aquatic fold',
    '    int  m_visionFt = 0;   // R316: the vision seam',
])
for _t in (AH_ANCH, AH_ADD, AH_MEM_NEW):
    clean(_t, 78)
assert Q not in AH_ADD and Q not in AH_MEM_NEW, 'b apostrophe'

p = 'ai/actor.h'
s = rd(p)
if 'setVisionFt' in s:
    already.append('actor.h: the vision state')
else:
    assert s.count(AH_ANCH) == 1, 'actor anchor not unique'
    assert s.count(AH_MEM_OLD) == 1, 'member anchor not unique'
    s = s.replace(AH_ANCH, AH_ADD, 1)
    s = s.replace(AH_MEM_OLD, AH_MEM_NEW, 1)
    wr(p, s)
    applied.append('actor.h: the vision state')

s = rd(p)
assert s.count('setVisionFt') == 1, 'b setter'
assert s.count('visionFt() const') == 1, 'b accessor'
assert s.count('m_visionFt') == 3, 'b member'
assert s.count('m_aquatic = false') == 1, 'b aquatic intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) game/state_combat.cpp: the water-fight fold ----
SC_OLD = NL.join([
    '        if (map.at(party.x, party.y) == TILE_WATER)',
    '            combat.encounter->setWaterFight();',
])
SC_NEW = NL.join([
    '        if (map.at(party.x, party.y) == TILE_WATER) {',
    '            combat.encounter->setWaterFight();',
    '            // R316: the vision seam - the R311',
    '            // distance pin charges the Encounter',
    '            // state (fresh, surface depth - the',
    '            // shallow JUDGMENT, the R312 crossing',
    '            // grain); the light-spell and helm',
    '            // multiples stay recorded (no',
    '            // active-light or carried-item layer',
    '            // exists)',
    '            combat.encounter->setVisionFt(',
    '                rules::uwVisionBaseFt(0));',
    '            char vbuf[64];',
    '            snprintf(vbuf, sizeof vbuf,',
    '                     ' + DQ + 'Sight runs %d feet in the "',
    '                     ' + DQ + 'clouded fresh water.' + DQ +
    ',',
    '                     rules::uwVisionBaseFt(0));',
    '            log.add(vbuf);',
    '        }',
])
for _t in (SC_OLD, SC_NEW):
    clean(_t, 78)
assert Q not in SC_NEW, 'c apostrophe'

p = 'game/state_combat.cpp'
s = rd(p)
if 'setVisionFt' in s:
    already.append('state_combat.cpp: the vision fold')
else:
    assert s.count(SC_OLD) == 1, 'vision fold anchor not unique'
    s = s.replace(SC_OLD, SC_NEW)
    wr(p, s)
    applied.append('state_combat.cpp: the vision fold')

s = rd(p)
assert s.count('setVisionFt') == 1, 'c setter call'
assert s.count('uwVisionBaseFt') == 2, 'c pin calls'
assert s.count('clouded fresh water') == 1, 'c print'
assert s.count('setWaterFight') == 1, 'c water fight intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) rules/swimcross.h: the seam note ----
SW_OLD = NL.join([
    '// stairs and the entry. The underwater',
    '// MOVEMENT, VISION and COMBAT paragraphs',
    '// stay data (no underwater combat layer',
    '// exists - a future seam); the spell',
    '// lists ride R168 (rules/uwspells.h).',
])
SW_NEW = NL.join([
    '// stairs and the entry. The underwater',
    '// MOVEMENT and COMBAT paragraphs charged',
    '// R313 (the crossing cap and the water',
    '// fight); VISION charges R316 (the',
    '// Encounter vision state - the',
    '// uwVisionBaseFt fold); the spell',
    '// lists ride R168 (rules/uwspells.h).',
])
for _t in (SW_OLD, SW_NEW):
    clean(_t, 78)
assert Q not in SW_NEW, 'd apostrophe'

p = 'rules/swimcross.h'
s = rd(p)
if 'VISION charges R316' in s:
    already.append('swimcross.h: the seam note')
else:
    assert s.count(SW_OLD) == 1, 'swimcross anchor not unique'
    s = s.replace(SW_OLD, SW_NEW)
    wr(p, s)
    applied.append('swimcross.h: the seam note')

s = rd(p)
assert s.count('VISION charges R316') == 1, 'd entry'
assert s.count('uwVisionBaseFt') == 1, 'd pin note'
assert s.count('lists ride R168') == 1, 'd spell line intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) rules/underwater.h: the recorded notes ----
UW_OLD = NL.join([
    '// allowance accessor exists); the rest rides',
    '// no engine layer yet (a state seam is the',
    '// future candidate).',
])
UW_NEW = NL.join([
    '// allowance accessor exists); the vision',
    '// distances now charge the seam (R316 - the',
    '// Encounter vision state, the fresh-surface',
    '// fold; the depth decay stays data - no',
    '// depth layer exists); the rest rides no',
    '// engine layer yet (a state seam is the',
    '// future candidate).',
])
for _t in (UW_OLD, UW_NEW):
    clean(_t, 78)
assert Q not in UW_NEW, 'e apostrophe'

p = 'rules/underwater.h'
s = rd(p)
if 'Encounter vision state' in s:
    already.append('underwater.h: the recorded notes')
else:
    assert s.count(UW_OLD) == 1, 'underwater anchor not unique'
    s = s.replace(UW_OLD, UW_NEW)
    wr(p, s)
    applied.append('underwater.h: the recorded notes')

s = rd(p)
assert s.count('Encounter vision state') == 1, 'e entry'
assert s.count('The net throw') == 1, 'e r315 note intact'
assert s.count('future candidate).') == 1, 'e tail intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch e balance'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) regtest.cpp: the R316 seam audit ----
RT_ANCH = NL.join([
    '        printf(' + DQ +
    'R315 net throwers engine audit: bad %d' + BS + 'n' +
    DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])

RT_V1 = NL.join([
    '        // V1: the water fight - the seam',
    '        // reads 50 feet and prints it',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            st.party.formed = true;',
    '            Character arc;',
    '            arc.name = ' + DQ + 'Arc' + DQ + ';',
    '            arc.classIndex = 0; arc.level = 1;',
    '            arc.race = 0;',
    '            arc.hp = 30; arc.maxHp = 30;',
    '            st.party.members.push_back(arc);',
    '            st.party.x = 5; st.party.y = 5;',
    '            st.map.set(5, 5, world::TILE_WATER);',
    '            std::vector<ai::Actor> foes;',
    '            ai::Actor m;',
    '            m.team = 1; m.hitDice = 2;',
    '            m.hp = 11; m.maxHp = 11;',
    '            foes.push_back(m);',
    '            st.beginCombat(std::move(foes), -1,',
    '                           ' + DQ + 'giant_rat' + DQ + ');',
    '            if (!st.combat.encounter) ++bad;',
    '            if (st.combat.encounter &&',
    '                st.combat.encounter->visionFt()',
    '                    != rules::uwVisionBaseFt(0)) ++bad;',
    '            bool seen = false;',
    '            for (int i = 0; i < 4; ++i)',
    '                if (st.log.get(i).find(' + DQ +
    'Sight runs 50 feet' + DQ + ')',
    '                    != std::string::npos)',
    '                    seen = true;',
    '            if (!seen) ++bad;',
    '        }',
])
RT_V2 = NL.join([
    '        // V2: the dry fight - the zero default',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            st.party.formed = true;',
    '            Character arc;',
    '            arc.name = ' + DQ + 'Arc' + DQ + ';',
    '            arc.classIndex = 0; arc.level = 1;',
    '            arc.race = 0;',
    '            arc.hp = 30; arc.maxHp = 30;',
    '            st.party.members.push_back(arc);',
    '            st.party.x = 5; st.party.y = 5;',
    '            st.map.set(5, 5, world::TILE_FLOOR);',
    '            std::vector<ai::Actor> foes;',
    '            ai::Actor m;',
    '            m.team = 1; m.hitDice = 2;',
    '            m.hp = 11; m.maxHp = 11;',
    '            foes.push_back(m);',
    '            st.beginCombat(std::move(foes), -1,',
    '                           ' + DQ + 'giant_rat' + DQ + ');',
    '            if (st.combat.encounter &&',
    '                st.combat.encounter->visionFt()',
    '                    != 0) ++bad;',
    '            for (int i = 0; i < 4; ++i)',
    '                if (st.log.get(i).find(' + DQ +
    'Sight runs' + DQ + ')',
    '                    != std::string::npos)',
    '                    ++bad;',
    '        }',
])
RT_V3 = NL.join([
    '        // V3: the setter seam - the state',
    '        // holds what the app feeds',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.classIndex = 0; a.level = 1;',
    '            a.dex = 10;',
    '            a.hp = 30; a.maxHp = 30;',
    '            a.weapon.id = items::WPN_SPEAR;',
    '            pt.push_back(a);',
    '            std::vector<ai::Actor> mons;',
    '            ai::Actor m;',
    '            m.team = 1; m.hitDice = 1;',
    '            m.name = ' + DQ + 'Monst' + DQ + ';',
    '            m.hp = 6; m.maxHp = 6;',
    '            mons.push_back(m);',
    '            ai::Encounter enc(pt, mons, 20);',
    '            enc.setVisionFt(75);',
    '            if (enc.visionFt() != 75) ++bad;',
    '            enc.setVisionFt(120);',
    '            if (enc.visionFt() != 120) ++bad;',
    '        }',
])
RT_V4 = NL.join([
    '        // V4: the pin bases - fresh 50,',
    '        // salt 100 (the R311 data)',
    '        {',
    '            if (rules::uwVisionBaseFt(0) != 50 ||',
    '                rules::uwVisionBaseFt(1) != 100)',
    '                ++bad;',
    '        }',
])
RT_HEAD = NL.join([
    '    // ---- R316: the underwater vision seam',
    '    // audit ----',
    '    // The R311 distance pins charge the',
    '    // Encounter vision state at the water',
    '    // fight (the fresh pool surface - 50',
    '    // feet, uwVisionBaseFt); the dry fight',
    '    // keeps the zero default. Draw-',
    '    // independent: the fold reads the pin,',
    '    // no dice.',
    '    {',
    '        int bad = 0;',
])
RT_TAIL = NL.join([
    '        printf(' + DQ +
    'R316 underwater vision seam audit: bad %d' + BS + 'n' +
    DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
])

RT_BLOCK = NL.join(RT_HEAD.split(NL) +
                  RT_V1.split(NL) + RT_V2.split(NL) +
                  RT_V3.split(NL) + RT_V4.split(NL) +
                  RT_TAIL.split(NL))
RT_NEW = NL.join(RT_ANCH.split(NL)[:3] +
                RT_BLOCK.split(NL) +
                RT_ANCH.split(NL)[3:])
for _t in (RT_HEAD, RT_V1, RT_V2, RT_V3, RT_V4):
    clean(_t, 76)
for _ln in RT_TAIL.split(NL):
    assert len(_ln) <= 76, 'rt tail line too long'
    assert all(ord(c) < 128 for c in _ln), 'non-ascii tail'
assert Q not in RT_BLOCK, 'f apostrophe in block'

p = 'regtest.cpp'
s = rd(p)
if 'R316 underwater vision seam audit' in s:
    already.append('regtest.cpp: the seam audit')
else:
    assert s.count(RT_ANCH) == 1, 'rt anchor not unique'
    assert s.count('audit: bad') == 242, 'rt census not 242'
    s = s.replace(RT_ANCH, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the seam audit')

s = rd(p)
assert s.count('R316 underwater vision seam audit') == 1, 'f entry'
assert s.count('audit: bad') == 243, 'patch f census wrong'
assert s.count(
    'R315 net throwers engine audit') == 1, 'f r315 intact'
assert s.count(
    'R227: the wis mental save wiring audit') == 1, 'f r227 intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch f balance'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) tools/dmg_gap_report.md: the chronicle ----
GP_OLD = NL.join([
    'with the R315 engine audit.',
    '',
    'Categories:',
])
GP_NEW = NL.join([
    'with the R315 engine audit.',
    '',
    'R316 the underwater vision seam: the R311',
    'distance pins charge the new Encounter',
    'vision state (actor.h setVisionFt) at',
    'the water fight - the fresh pool surface',
    'reads uwVisionBaseFt (50 feet), printed',
    'when the company takes to the water; the',
    'dry fight keeps the zero default. The',
    'depth decay and the light/helm multiples',
    'stay data (no depth or active-light',
    'layer). The census moves 242 -> 243',
    'with the R316 seam audit.',
    '',
    'Categories:',
])
clean(GP_OLD, 57, gap=True)
clean(GP_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R316 the underwater vision seam' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(GP_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(GP_OLD, GP_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R316 the underwater vision seam') == 1, 'g entry'
assert s.count('Categories:') == 1, 'g legend head'
assert s.count('moves 242 -> 243') == 1, 'g census'
assert s.count('moves 241 -> 242') == 1, 'g r315 intact'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- R316 tail ----
if len(applied) + len(already) != 7:
    print('R316 splice: FAIL - expected 7 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R316 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R316 note: 7 patches; the vision seam')
print('charges the water fight (the R315 seed')
print('entry rides as the first patch); the')
print('battery census moves 242 -> 243')
print('commit: R316: the underwater vision seam')
print('(census 243)')

