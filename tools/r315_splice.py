#!/usr/bin/env python3
# tools/r315_splice.py - R315: the net throwers
# of the waterborne table.
#
# The charge: the DMG UNDERWATER ADVENTURES
# net paragraph (rules/underwater.h, R311) -
# the underwater races throw nets an average
# of 15 feet, the sahuagin 20 - now folded
# at the R314 waterborne encounter. The MM
# arms rows (the Lua roster is the
# authority): the sahuagin carry trident,
# net and dagger 50 percent; the locathah
# and the merman carry net rows - in the
# water fight these races open with a net
# volley (the R37 monster-missile pattern,
# the R42 band spend), the bands read the
# DMG throw pins (20 feet = 2 bands, 15
# feet = 1). On land the nets stay swapped
# for javelins (MM, the sahuagin entry) -
# the TILE_WATER gate.
#
#   (a) game/state_combat.cpp - the
#       beginCombat foes loop gains the net
#       throwers (the R37 key-list pattern;
#       the water gate mirrors the R312
#       crossing check two lines below).
#   (b) rules/underwater.h - the recorded
#       notes: the net throw is now charged;
#       the untrained -4 and the strength-
#       point range stay recorded (no party
#       net exists - the PHB p.38 table
#       carries no net row).
#   (c) rules/uwfight.h - the NOT CHARGED
#       list updates the same way.
#   (d) regtest.cpp - the R315 engine audit
#       (six scenarios, draw-independent
#       asserts on the volley marks and the
#       round spend; the hit rolls ride the
#       R37 dice); the battery census moves
#       241 -> 242.
#   (e) tools/dmg_gap_report.md - the
#       chronicle paragraph (no box flip).
#
# NOT CHARGED (recorded, the seam headers):
# the untrained -4 net penalty (no party
# net item exists - the PHB p.38 table
# carries no net row), the strength-point
# throw range (no allowance accessor), the
# net entrap prose (no entangle layer).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY
# patch (the R142 lesson). ZERO literal
# backslash bytes in this file except the
# printf continuations, built via chr(92); no
# CONTENT string embeds an apostrophe except
# the pre-existing anchor comment (the R44
# 50-foot line), non-ASCII, or a line past
# its bound (78 the header and the C++
# patches, 76 regtest, 57 the gap report).
# Commit: "R315: the net throwers of the
# waterborne table (census 242)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
DQ = chr(34)
BS = chr(92)
applied, already, fails = [], [], []

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

# ---- (a) game/state_combat.cpp: the net volley fold ----
SC_OLD = NL.join([
    '                (monsterKey == ' + DQ + 'goblin' + DQ + ' ||',
    '                     monsterKey == ' + DQ + 'kobold' + DQ + ' ||',
    '                     monsterKey == ' + DQ + 'hobgoblin' + DQ +
    ')) {   // R44: MM bows',
    '                m.monsterRanged = true;',
    '                m.rangedRounds = 5;   // 50' + Q +
    ' short range, 10' + Q + ' bands',
    '            }',
])
SC_ADD = NL.join([
    '',
    '            // R315: the net throwers of the',
    '            // waterborne table (MM arms rows -',
    '            // sahuagin trident, net and dagger',
    '            // 50 percent; locathah and merman',
    '            // net rows) open the water fight',
    '            // with a net volley (the R37',
    '            // pattern); the bands read the DMG',
    '            // throw pins (uwfight.h - sahuagin',
    '            // 20 feet = 2 bands, the underwater',
    '            // races 15 feet = 1). On land the',
    '            // nets stay swapped for javelins',
    '            // (MM) - the TILE_WATER gate. The',
    '            // untrained -4 stays recorded (no',
    '            // party net exists - the PHB p.38',
    '            // table carries no net row).',
    '            if (!m.isCharacter &&',
    '                map.at(party.x, party.y) ==',
    '                    TILE_WATER &&',
    '                (monsterKey == ' + DQ + 'sahuagin' + DQ + ' ||',
    '                 monsterKey == ' + DQ + 'locathah' + DQ + ' ||',
    '                 monsterKey == ' + DQ + 'merman' + DQ + ')) {',
    '                m.monsterRanged = true;',
    '                m.rangedRounds =',
    '                    monsterKey == ' + DQ + 'sahuagin' + DQ,
    '                        ? rules::uwNetThrowSahuaginFt() / 10',
    '                        : rules::uwNetThrowUnderwaterRaceFt()',
    '                          / 10;',
    '            }',
])
SC_NEW = SC_OLD + SC_ADD
for _t in (SC_OLD, SC_ADD):
    clean(_t, 78)
assert Q in SC_OLD and Q not in SC_ADD, 'apostrophe placement'

p = 'game/state_combat.cpp'
s = rd(p)
if 'uwNetThrowSahuaginFt' in s:
    already.append('state_combat.cpp: the net fold')
else:
    assert s.count(SC_OLD) == 1, 'net fold anchor not unique'
    s = s.replace(SC_OLD, SC_NEW)
    wr(p, s)
    applied.append('state_combat.cpp: the net fold')

s = rd(p)
assert s.count('uwNetThrowSahuaginFt') == 1, 'a pin call'
assert s.count('uwNetThrowUnderwaterRaceFt') == 1, 'a race pin'
assert s.count('R44: MM bows') == 1, 'a anchor intact'
assert s.count('TILE_WATER') == 6, 'a water gates'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch a balance'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) rules/underwater.h: the recorded notes ----
UW_OLD = NL.join([
    '// for bows, scrolls and books. No engine site',
    '// charges any of this yet (no underwater game',
    '// layer exists - a state seam is the future',
    '// candidate).',
])
UW_NEW = NL.join([
    '// for bows, scrolls and books. The net throw',
    '// is now charged (R315 - the state_combat',
    '// volley fold; sahuagin and the underwater',
    '// races throw at the DMG distances); the',
    '// untrained -4 and the strength-point range',
    '// stay recorded (no party net exists - the',
    '// PHB p.38 table carries no net row; no',
    '// allowance accessor exists); the rest rides',
    '// no engine layer yet (a state seam is the',
    '// future candidate).',
])
for _t in (UW_OLD, UW_NEW):
    clean(_t, 78)
assert Q not in UW_NEW, 'apostrophe in uw header'

p = 'rules/underwater.h'
s = rd(p)
if 'R315 - the state_combat' in s:
    already.append('underwater.h: the recorded notes')
else:
    assert s.count(UW_OLD) == 1, 'uw notes anchor not unique'
    s = s.replace(UW_OLD, UW_NEW)
    wr(p, s)
    applied.append('underwater.h: the recorded notes')

s = rd(p)
assert s.count('R315 - the state_combat') == 1, 'b entry'
assert s.count(
    'No engine site charges any of this yet') == 0, (
    'b stale gone')
assert s.count('the keep-dry rule') == 1, 'b anchor intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) rules/uwfight.h: the NOT CHARGED list ----
UF_OLD = NL.join([
    '// pin, not data): the net throw prose,',
    '// the free',
])
UF_NEW = NL.join([
    '// pin, not data): the net throw',
    '// untrained -4 and the strength-point',
    '// range (the throw itself is charged',
    '// R315 - the state_combat volley fold),',
    '// the free',
])
for _t in (UF_OLD, UF_NEW):
    clean(_t, 78)
assert Q not in UF_NEW, 'apostrophe in uwfight header'

p = 'rules/uwfight.h'
s = rd(p)
if 'R315 - the state_combat volley fold' in s:
    already.append('uwfight.h: the not-charged list')
else:
    assert s.count(UF_OLD) == 1, 'uwfight anchor not unique'
    s = s.replace(UF_OLD, UF_NEW)
    wr(p, s)
    applied.append('uwfight.h: the not-charged list')

s = rd(p)
assert s.count(
    'R315 - the state_combat volley fold') == 1, (
    'c entry')
assert s.count('the net throw prose,') == 0, 'c stale gone'
assert s.count('// the free') == 1, 'c free line intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) regtest.cpp: the R315 engine audit ----
RT_ANCH = NL.join([
    '        printf(' + DQ +
    'R314 crossbow and aquatic engine audit: bad %d' +
    BS + 'n' + DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])

def sc_party():
    return NL.join([
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
    ])

def sc_foe():
    return NL.join([
        '            std::vector<ai::Actor> foes;',
        '            ai::Actor m;',
        '            m.team = 1; m.hitDice = 2;',
        '            m.hp = 11; m.maxHp = 11;',
        '            foes.push_back(m);',
    ])

def sc_tile(tile):
    return ('            st.map.set(5, 5, world::' +
            tile + ');')

def sc_begin(key):
    return NL.join([
        '            st.beginCombat(std::move(foes), -1,',
        '                           ' + DQ + key + DQ + ');',
    ])

def sc_check(cond):
    return NL.join([
        '            if (st.combat.encounter &&',
        '                ' + cond + ') ++bad;',
    ])

RT_BLOCK_HEAD = NL.join([
    '    // ---- R315: the net throwers engine',
    '    // audit ----',
    '    // The MM arms rows (the Lua roster):',
    '    // sahuagin trident, net and dagger 50',
    '    // percent; locathah and merman net rows',
    '    // - the waterborne races open the water',
    '    // fight with a net volley (the R37',
    '    // pattern), the bands read the DMG throw',
    '    // pins (sahuagin 20 feet = 2 bands, the',
    '    // underwater races 15 feet = 1). The',
    '    // asserts read the volley marks and the',
    '    // round spend, draw-independent (the hit',
    '    // rolls ride the R37 dice); on land the',
    '    // nets stay swapped for javelins (MM).',
    '    {',
    '        int bad = 0;',
])

RT_N1 = NL.join(sc_party().split(NL) + [sc_tile('TILE_WATER')] +
    sc_foe().split(NL) + sc_begin('sahuagin').split(NL) + [
    '            if (!st.combat.encounter) ++bad;',
    ] + sc_check(
    '!st.combat.encounter->monsters()[0]'
    '.monsterRanged').split(NL) + sc_check(
    'st.combat.encounter->monsters()[0]'
    '.rangedRounds != 2').split(NL) + [
    '        }',
])
RT_N1_HEAD = NL.join([
    '        // N1: the sahuagin net volley - 2',
    '        // bands (uwNetThrowSahuaginFt)',
    '        {',
])

RT_N2 = NL.join(sc_party().split(NL) + [sc_tile('TILE_WATER')] +
    sc_foe().split(NL) + sc_begin('locathah').split(NL) + [
    '            if (!st.combat.encounter) ++bad;',
    ] + sc_check(
    'st.combat.encounter->monsters()[0]'
    '.rangedRounds != 1').split(NL) + [
    '        }',
])
RT_N2_HEAD = NL.join([
    '        // N2: the locathah net - 1 band',
    '        // (uwNetThrowUnderwaterRaceFt)',
    '        {',
])

RT_N3 = NL.join(sc_party().split(NL) + [sc_tile('TILE_WATER')] +
    sc_foe().split(NL) + sc_begin('merman').split(NL) + [
    '            if (!st.combat.encounter) ++bad;',
    ] + sc_check(
    'st.combat.encounter->monsters()[0]'
    '.rangedRounds != 1').split(NL) + [
    '        }',
])
RT_N3_HEAD = NL.join([
    '        // N3: the merman net - 1 band',
    '        {',
])

RT_N4 = NL.join(sc_party().split(NL) + [sc_tile('TILE_FLOOR')] +
    sc_foe().split(NL) + sc_begin('sahuagin').split(NL) + [
    '            if (!st.combat.encounter) ++bad;',
    ] + sc_check(
    'st.combat.encounter->monsters()[0]'
    '.monsterRanged').split(NL) + [
    '        }',
])
RT_N4_HEAD = NL.join([
    '        // N4: on land the nets stay swapped',
    '        // for javelins (MM) - no volley',
    '        {',
])

RT_N5 = NL.join(sc_party().split(NL) + [sc_tile('TILE_WATER')] +
    sc_foe().split(NL) + sc_begin('giant_rat').split(NL) + [
    '            if (!st.combat.encounter) ++bad;',
    ] + sc_check(
    'st.combat.encounter->monsters()[0]'
    '.monsterRanged').split(NL) + [
    '        }',
])
RT_N5_HEAD = NL.join([
    '        // N5: the giant rat keeps no net',
    '        // (the R313 audit scenario 4',
    '        // regression)',
    '        {',
])

RT_N6 = NL.join(sc_party().split(NL) + [sc_tile('TILE_WATER')] +
    sc_foe().split(NL) + sc_begin('sahuagin').split(NL) + [
    '            if (!st.combat.encounter) ++bad;',
    '            if (st.combat.encounter)',
    '                st.combat.encounter->stepRound();',
    ] + sc_check(
    'st.combat.encounter->monsters()[0]'
    '.rangedRounds != 1').split(NL) + [
    '            if (st.combat.encounter)',
    '                st.combat.encounter->stepRound();',
    ] + sc_check(
    'st.combat.encounter->monsters()[0]'
    '.rangedRounds != 0').split(NL) + [
    '            if (st.combat.encounter)',
    '                st.combat.encounter->stepRound();',
    ] + sc_check(
    'st.combat.encounter->monsters()[0]'
    '.rangedRounds != 0').split(NL) + [
    '        }',
])
RT_N6_HEAD = NL.join([
    '        // N6: the volley spend - one band',
    '        // per round (the R42 convention),',
    '        // the third round adds no volley',
    '        {',
])

RT_TAIL = NL.join([
    '        printf(' + DQ +
    'R315 net throwers engine audit: bad %d' +
    BS + 'n' + DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
])

RT_NEW = NL.join(RT_ANCH.split(NL)[:3] +
    [NL.join(RT_BLOCK_HEAD.split(NL) +
             RT_N1_HEAD.split(NL) + RT_N1.split(NL) +
             RT_N2_HEAD.split(NL) + RT_N2.split(NL) +
             RT_N3_HEAD.split(NL) + RT_N3.split(NL) +
             RT_N4_HEAD.split(NL) + RT_N4.split(NL) +
             RT_N5_HEAD.split(NL) + RT_N5.split(NL) +
             RT_N6_HEAD.split(NL) + RT_N6.split(NL) +
             RT_TAIL.split(NL))] +
    RT_ANCH.split(NL)[3:])

for _t in (RT_BLOCK_HEAD, RT_N1, RT_N2, RT_N3, RT_N4,
           RT_N5, RT_N6):
    clean(_t, 76)
# RT_TAIL carries the one BS-built printf line - the
# clean() backslash ban excepts it; lengths still check
for _ln in RT_TAIL.split(NL):
    assert all(ord(c) < 128 for c in _ln), 'non-ascii tail'
    assert len(_ln) <= 76, 'rt tail line too long: ' + _ln
assert Q not in RT_BLOCK_HEAD + RT_TAIL, (
    'apostrophe in rt head')

p = 'regtest.cpp'
s = rd(p)
if 'R315 net throwers engine audit' in s:
    already.append('regtest.cpp: the engine audit')
else:
    assert s.count(RT_ANCH) == 1, 'rt anchor not unique'
    assert s.count('audit: bad') == 241, 'rt census not 241'
    s = s.replace(RT_ANCH, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the engine audit')

s = rd(p)
assert s.count('R315 net throwers engine audit') == 1, 'd entry'
assert s.count('audit: bad') == 242, 'patch d census wrong'
assert s.count(
    'R314 crossbow and aquatic engine audit') == 1, (
    'd r314 intact')
assert s.count(
    'R227: the wis mental save wiring audit') == 1, (
    'd r227 intact')
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) tools/dmg_gap_report.md: the chronicle ----
CH_OLD = NL.join([
    'and R314 engine audits.',
    '',
    'Categories:',
])
CH_NEW = NL.join([
    'and R314 engine audits.',
    '',
    'R315 the net throwers of the waterborne',
    'table: the MM arms rows (sahuagin',
    'trident, net and dagger 50 percent;',
    'locathah and merman net rows) charge',
    'the DMG net throw pins at the',
    'state_combat beginCombat foes loop -',
    'the waterborne races open the water',
    'fight with a net volley (the R37',
    'monster-missile pattern, the R42 band',
    'spend), the bands read',
    'uwNetThrowSahuaginFt (20 feet = 2',
    'bands) and uwNetThrowUnderwaterRaceFt',
    '(15 feet = 1); on land the nets stay',
    'swapped for javelins (MM). The',
    'untrained -4 and the strength-point',
    'range stay recorded (no party net',
    'exists). The census moves 241 -> 242',
    'with the R315 engine audit.',
    '',
    'Categories:',
])
clean(CH_OLD, 57, gap=True)
clean(CH_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R315 the net throwers' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(CH_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(CH_OLD, CH_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R315 the net throwers') == 1, 'e entry'
assert s.count('Categories:') == 1, 'e legend head'
assert s.count('moves 241 -> 242') == 1, 'e census'
assert s.count('moves 239 -> 241') == 1, 'e r314 intact'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- R315 fails/tail ----
if fails:
    print('R315 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print('R315 splice: FAIL - expected 5 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R315 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R315 note: 5 patches; the net throwers')
print('charge the waterborne encounter; the')
print('battery census moves 241 -> 242')
print('commit: R315: the net throwers of the')
print('waterborne table (census 242)')

