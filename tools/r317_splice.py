#!/usr/bin/env python3
# tools/r317_splice.py - R317: the infravision
# fold (one splice; the R316 seed entry rides
# as the first patch - it names the landed
# commit).
#
# The survey: the light-spell and helm
# vision multiples CANNOT charge cleanly -
# no STATUS_LIGHT exists (the light spell
# has no engine site), and the pack carries
# no named items (PackItem is kind/id/plus/
# gp - the Helm of Underwater Action is a
# treasure-table row, not a carried item);
# the depth decay needs a depth notion the
# surface pool has not. The ONE clean
# charge: the R311 print "infravision as
# in dungeons" (uwInfravisionSameAsDungeon,
# regtested) meets the R154 race data
# (raceInfravisionFeet, regtested) at the
# R316 vision site - the company best
# infravision reports its range in the
# water fight. No new pins, no new state -
# the print rides the existing seam.
#
#   (a) doc/vibe/adnd1_knowledge_seed_v2.md -
#       the R316 round-state entry (the
#       r316b fix, commit 9021b2c, census
#       243) and the lessons.
#   (b) game/state_combat.cpp - the
#       infravision print in the water-fight
#       block (the party best, the R154
#       data; the light-spell and helm
#       multiples stay recorded).
#   (c) rules/underwater.h - the recorded
#       notes: the infravision print
#       charges R317.
#   (d) regtest.cpp - the R317 audit (the
#       elf company reads the infravision
#       print, the all-human company does
#       not, the dry fight does not, the
#       pins re-assert - draw-independent);
#       the battery census moves 243 -> 244.
#   (e) tools/dmg_gap_report.md - the
#       chronicle paragraph (no box flip).
#
# The R317 round-state entry rides the R318
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
# the seed, 57 the gap report). The regtest
# asserts read the LOG WINDOW (the R316
# lesson), never the head.
# Commit: "R317: the infravision fold
# (census 244)"
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

# ---- (a) the seed: the R316 round-state entry ----
SEED = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SD_ANCH = NL.join([
    '  fold; (4) no new pins - the R311 uwNet data',
    '  charged via the R37 monster-missile pattern.',
    '',
])
SD_ADD = NL.join([
    '- R316 landed 2026-10-10 (the r316b fix,',
    '  commit 9021b2c), census 243, the',
    '  underwater vision seam (see Current state',
    '  above). RED then GREEN: the sight print',
    '  displaced the R314 W1 line and the older',
    '  audit broke on its get(0); the r316b',
    '  window scan fixed it. Lessons: (1) a NEW',
    '  PRINT RIDES THE SHARED LOG - older audits',
    '  assert the LOG WINDOW, not the head (the',
    '  W1 scan is the pattern); (2) the sandbox',
    '  cannot build the C++ - the Termux',
    '  preflight is the ONLY gate that catches',
    '  print interactions; (3) the naming held -',
    '  the round record and the bug fix both',
    '  committed, initial splices are never',
    '  deleted; (4) the survey kills before the',
    '  fold - no STATUS_LIGHT, no named pack',
    '  items, no depth notion (the light/helm',
    '  multiples and the decay stay recorded).',
    '',
])
clean(SD_ANCH, 78)
clean(SD_ADD, 72)

s = rd(SEED)
if 'R316 landed' in s:
    already.append('the seed: the R316 entry')
else:
    assert s.count(SD_ANCH) == 1, 'seed anchor not unique'
    s = s.replace(SD_ANCH, SD_ANCH + SD_ADD, 1)
    wr(SEED, s)
    applied.append('the seed: the R316 entry')

s = rd(SEED)
assert s.count('R316 landed') == 1, 'a entry'
assert s.count('R315 landed') == 1, 'a r315 intact'
assert s.count(
    'monster-missile pattern.') == 1, 'a anchor tail'
assert s.count('Knowledge maintenance') == 1, 'a doc intact'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) state_combat.cpp: the infravision print ----
SC_OLD = NL.join([
    '                     rules::uwVisionBaseFt(0));',
    '            log.add(vbuf);',
    '        }',
])
SC_NEW = NL.join([
    '                     rules::uwVisionBaseFt(0));',
    '            log.add(vbuf);',
    '            // R317: the infravision print - the',
    '            // R311 pin (infravision as in',
    '            // dungeons) meets the R154 race',
    '            // data: the company best',
    '            // infravision eyes report their',
    '            // range (the light-spell and helm',
    '            // multiples stay recorded - no',
    '            // active-light or carried-item',
    '            // layer exists)',
    '            if (rules::uwInfravisionSameAsDungeon())',
    '            {',
    '                int infra = 0;',
    '                for (const auto& c : party.members)',
    '                    if (c.hp > 0) {',
    '                        int f = rules::',
    '                            raceInfravisionFeet(',
    '                            (rules::CharRace)c.race);',
    '                        if (f > infra) infra = f;',
    '                    }',
    '                if (infra > 0) {',
    '                    char ibuf[64];',
    '                    snprintf(ibuf, sizeof ibuf,',
    '                             ' + DQ +
    'Infravision reaches %d feet' + DQ,
    '                             ' + DQ +
    ' - as in the dungeons.' + DQ + ',',
    '                             infra);',
    '                    log.add(ibuf);',
    '                }',
    '            }',
    '        }',
])
for _t in (SC_OLD, SC_NEW):
    clean(_t, 78)
assert Q not in SC_NEW, 'b apostrophe'

p = 'game/state_combat.cpp'
s = rd(p)
if 'Infravision reaches' in s:
    already.append('state_combat.cpp: the infravision print')
else:
    assert s.count(SC_OLD) == 1, 'infravision anchor not unique'
    s = s.replace(SC_OLD, SC_NEW)
    wr(p, s)
    applied.append('state_combat.cpp: the infravision print')

s = rd(p)
assert s.count('Infravision reaches') == 1, 'b print'
assert s.count(
    'uwInfravisionSameAsDungeon') == 1, 'b pin call'
assert s.count(
    'raceInfravisionFeet') == 1, 'b race call'
assert s.count(
    'clouded fresh water') == 1, 'b sight intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) rules/underwater.h: the recorded notes ----
UW_OLD = NL.join([
    '// depth layer exists); the rest rides no',
    '// engine layer yet (a state seam is the',
    '// future candidate).',
])
UW_NEW = NL.join([
    '// depth layer exists); the infravision',
    '// print charges R317 (the state_combat',
    '// fold - the R154 race data reads the',
    '// party best, the R311 pin gates); the',
    '// rest rides no engine layer yet (a state',
    '// seam is the future candidate).',
])
for _t in (UW_OLD, UW_NEW):
    clean(_t, 78)
assert Q not in UW_NEW, 'c apostrophe'

p = 'rules/underwater.h'
s = rd(p)
if 'print charges R317' in s:
    already.append('underwater.h: the recorded notes')
else:
    assert s.count(UW_OLD) == 1, 'underwater anchor not unique'
    s = s.replace(UW_OLD, UW_NEW)
    wr(p, s)
    applied.append('underwater.h: the recorded notes')

s = rd(p)
assert s.count('print charges R317') == 1, 'c entry'
assert s.count(
    'future candidate).') == 1, 'c tail intact'
assert s.count(
    'Encounter vision state') == 1, 'c r316 note intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) regtest.cpp: the R317 audit ----
RT_ANCH = NL.join([
    '        printf(' + DQ +
    'R316 underwater vision seam audit: bad %d' + BS + 'n' +
    DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])

def rt_state(party_race):
    return NL.join([
        '            AppState st;',
        '            st.mode = MODE_EXPLORE;',
        '            st.party.formed = true;',
        '            Character arc;',
        '            arc.name = ' + DQ + 'Arc' + DQ + ';',
        '            arc.classIndex = 0; arc.level = 1;',
        '            arc.race = ' + party_race + ';',
        '            arc.hp = 30; arc.maxHp = 30;',
        '            st.party.members.push_back(arc);',
        '            st.party.x = 5; st.party.y = 5;',
    ])

def rt_foes():
    return NL.join([
        '            std::vector<ai::Actor> foes;',
        '            ai::Actor m;',
        '            m.team = 1; m.hitDice = 2;',
        '            m.hp = 11; m.maxHp = 11;',
        '            foes.push_back(m);',
    ])

RT_I1 = NL.join(rt_state('2').split(NL) + [
    '            st.map.set(5, 5, world::TILE_WATER);',
] + rt_foes().split(NL) + [
    '            st.beginCombat(std::move(foes), -1,',
    '                           ' + DQ + 'giant_rat' + DQ + ');',
    '            if (!st.combat.encounter) ++bad;',
    '            bool i1 = false;',
    '            for (int i = 0; i < 4; ++i)',
    '                if (st.log.get(i).find(' + DQ +
    'Infravision reaches 60 feet' + DQ + ')',
    '                    != std::string::npos)',
    '                    i1 = true;',
    '            if (!i1) ++bad;',
])
RT_I2 = NL.join(rt_state('0').split(NL) + [
    '            st.map.set(5, 5, world::TILE_WATER);',
] + rt_foes().split(NL) + [
    '            st.beginCombat(std::move(foes), -1,',
    '                           ' + DQ + 'giant_rat' + DQ + ');',
    '            if (!st.combat.encounter) ++bad;',
    '            for (int i = 0; i < 4; ++i)',
    '                if (st.log.get(i).find(' + DQ +
    'Infravision reaches' + DQ + ')',
    '                    != std::string::npos)',
    '                    ++bad;',
])
RT_I3 = NL.join(rt_state('2').split(NL) + [
    '            st.map.set(5, 5, world::TILE_FLOOR);',
] + rt_foes().split(NL) + [
    '            st.beginCombat(std::move(foes), -1,',
    '                           ' + DQ + 'giant_rat' + DQ + ');',
    '            if (!st.combat.encounter) ++bad;',
    '            for (int i = 0; i < 4; ++i)',
    '                if (st.log.get(i).find(' + DQ +
    'Infravision reaches' + DQ + ')',
    '                    != std::string::npos)',
    '                    ++bad;',
])
RT_I4 = NL.join([
    '            // I4: the pins (the R311 data,',
    '            // the R154 data)',
    '            {',
    '                if (rules::uwInfravisionSameAsDungeon()',
    '                    != 1)',
    '                    ++bad;',
    '                if (rules::raceInfravisionFeet(',
    '                        rules::RACE_ELF) != 60 ||',
    '                    rules::raceInfravisionFeet(',
    '                        rules::RACE_HUMAN) != 0)',
    '                    ++bad;',
    '            }',
])
RT_HEAD = NL.join([
    '    // ---- R317: the infravision fold audit',
    '    // ----',
    '    // The R311 print (infravision as in',
    '    // dungeons) meets the R154 race data',
    '    // at the R316 vision site: the company',
    '    // best infravision reports its range',
    '    // in the water fight (an elf 60 feet,',
    '    // the all-human company reads no',
    '    // print, the dry fight reads none).',
    '    // Draw-independent: no dice.',
    '    {',
    '        int bad = 0;',
    '        // I1: the elf company - the print',
    '        {',
])
RT_MID = NL.join([
    '        // I2: the all-human company - no print',
    '        {',
])
RT_MID2 = NL.join([
    '        // I3: the dry fight - no print',
    '        {',
])
RT_TAIL = NL.join([
    '        printf(' + DQ +
    'R317 infravision fold audit: bad %d' + BS + 'n' +
    DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_BLOCK = NL.join(RT_HEAD.split(NL) + RT_I1.split(NL) + [
    '        }',
] + RT_MID.split(NL) + RT_I2.split(NL) + [
    '        }',
] + RT_MID2.split(NL) + RT_I3.split(NL) + [
    '        }',
] + RT_I4.split(NL) + RT_TAIL.split(NL))
RT_NEW = NL.join(RT_ANCH.split(NL)[:3] +
                RT_BLOCK.split(NL) +
                RT_ANCH.split(NL)[3:])
for _t in (RT_HEAD, RT_I1, RT_I2, RT_I3, RT_I4,
           RT_MID, RT_MID2):
    clean(_t, 76)
for _ln in RT_TAIL.split(NL):
    assert len(_ln) <= 76, 'rt tail line too long'
    assert all(ord(c) < 128 for c in _ln), 'non-ascii tail'
assert Q not in RT_BLOCK.replace(DQ, ''), 'f apostrophe'

p = 'regtest.cpp'
s = rd(p)
if 'R317 infravision fold audit' in s:
    already.append('regtest.cpp: the R317 audit')
else:
    assert s.count(RT_ANCH) == 1, 'rt anchor not unique'
    assert s.count('audit: bad') == 243, 'rt census not 243'
    s = s.replace(RT_ANCH, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the R317 audit')

s = rd(p)
assert s.count('R317 infravision fold audit') == 1, 'd entry'
assert s.count('audit: bad') == 244, 'patch d census wrong'
assert s.count(
    'R316 underwater vision seam audit') == 1, 'd r316 intact'
assert s.count(
    'R227: the wis mental save wiring audit') == 1, 'd r227 intact'
assert s.count('Infravision reaches 60 feet') == 1, 'd phrase'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) tools/dmg_gap_report.md: the chronicle ----
GP_OLD = NL.join([
    'with the R316 seam audit.',
    '',
    'Categories:',
])
GP_NEW = NL.join([
    'with the R316 seam audit.',
    '',
    'R317 the infravision fold: the survey',
    'killed the light-spell and helm multiples',
    '(no STATUS_LIGHT, no named pack items)',
    'and the depth decay (no depth notion) -',
    'the one clean charge is the R311 print',
    '(infravision as in dungeons) meeting',
    'the R154 race data at the vision site:',
    'the company best infravision reports',
    'its range in the water fight (state_',
    'combat.cpp, uwInfravisionSameAsDungeon',
    'gates, raceInfravisionFeet reads). The',
    'census moves 243 -> 244 with the R317',
    'audit.',
    '',
    'Categories:',
])
clean(GP_OLD, 57, gap=True)
clean(GP_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R317 the infravision fold' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(GP_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(GP_OLD, GP_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R317 the infravision fold') == 1, 'e entry'
assert s.count('Categories:') == 1, 'e legend head'
assert s.count('moves 243 -> 244') == 1, 'e census'
assert s.count('moves 242 -> 243') == 1, 'e r316 intact'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- R317 tail ----
if len(applied) + len(already) != 5:
    print('R317 splice: FAIL - expected 5 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R317 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R317 note: 5 patches; the infravision')
print('fold rides the R316 vision site (the')
print('R316 seed entry rides as the first')
print('patch); the battery census moves')
print('243 -> 244')
print('commit: R317: the infravision fold')
print('(census 244)')

