#!/usr/bin/env python3
# tools/r318_splice.py - R318: the net
# entrap layer (one splice; the R317 seed
# entry rides as the first patch).
#
# The charge: the MM sahuagin entry - the
# hooked nets entrap ("Nets are used to
# entrap victims"; "escape from one
# virtually impossible... for creatures
# not able to grasp and tear with a
# strength of 16 or greater"). The
# waterborne net throwers (R315) now
# ENTRAP on a volley hit instead of
# wounding: a new STATUS_ENTANGLED (the
# held precedent, actor.cpp paralysis)
# rides the missile path; the entrap is
# permanent until torn (the tickStatus
# zero-round convention); a strength of
# 16 or greater tears free at the round
# start (the stepRound fold, BEFORE the
# end conditions - a strong member tears
# before the stalemate read).
#
#   (a) doc/vibe/adnd1_knowledge_seed_v2.md -
#       the R317 round-state entry (commit
#       f98caa7, census 244) and lessons.
#   (b) spelleffects/spelleffects.h - the
#       STATUS_ENTANGLED kind (the MM hooks).
#   (c) ai/actor.h - the netVolley mark
#       (the R315 marks pattern).
#   (d) ai/actor.cpp - the canAct gate
#       (the entrap bars action).
#   (e) ai/actor.cpp - the stepRound tear
#       fold (STR 16+, before the end
#       conditions).
#   (f) ai/actor.cpp - the resolveMissile
#       entrap (a net hit entraps, no wound).
#   (g) rules/uwfight.h - the pin
#       (uwNetEntrapStrTear, the MM print).
#   (h) game/state_combat.cpp - the R315
#       block sets netVolley.
#   (i) regtest.cpp - the R318 audit (the
#       gate, the tear, the hold, the pins,
#       the mark - draw-independent; the
#       volley hit rides the R37 dice, the
#       R315 convention); the battery census
#       moves 244 -> 245.
#   (j) tools/dmg_gap_report.md - the
#       chronicle paragraph (no box flip).
#
# The R318 round-state entry rides the R319
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
# Commit: "R318: the net entrap layer
# (census 245)"
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

# ---- (a) the seed: the R317 round-state entry ----
SEED = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SD_ANCH = NL.join([
    '## Knowledge maintenance',
])
SD_ADD = NL.join([
    '- R317 landed 2026-10-10: commit f98caa7,',
    '  census 244, the infravision fold (see',
    '  Current state above). GREEN on the FIRST',
    '  preflight. Lessons: (1) the survey kill-',
    '  list discipline paid - no STATUS_LIGHT,',
    '  no named pack items, no depth notion,',
    '  so the fold charged only the pins that',
    '  existed (uwInfravisionSameAsDungeon meets',
    '  raceInfravisionFeet); (2) no new state -',
    '  the print rode the R316 site; the round',
    '  stayed small because the data was',
    '  already pinned and regtested.',
    '',
])
clean(SD_ANCH, 78)
clean(SD_ADD, 72)

s = rd(SEED)
if 'R317 landed' in s:
    already.append('the seed: the R317 entry')
else:
    assert s.count(SD_ANCH) == 1, 'seed anchor not unique'
    s = s.replace(SD_ANCH, SD_ADD + NL + SD_ANCH, 1)
    wr(SEED, s)
    applied.append('the seed: the R317 entry')

s = rd(SEED)
assert s.count('R317 landed') == 1, 'a entry'
assert s.count('R316 landed') == 1, 'a r316 intact'
assert s.count(
    'Knowledge maintenance') == 1, 'a doc intact'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) spelleffects.h: the entrap kind ----
SE_OLD = NL.join([
    '    STATUS_POLYMORPHED,  // R82: Polymorph Other - held-like',
])
SE_NEW = NL.join([
    '    STATUS_POLYMORPHED,  // R82: Polymorph Other - held-like',
    '    STATUS_ENTANGLED,   // R318: the hooked-net entrap',
    '                           // (MM sahuagin - torn at STR 16+)',
])
clean(SE_OLD, 78)
clean(SE_NEW, 78)
assert Q not in SE_NEW, 'b apostrophe'

p = 'spelleffects/spelleffects.h'
s = rd(p)
if 'STATUS_ENTANGLED' in s:
    already.append('spelleffects.h: the entrap kind')
else:
    assert s.count(SE_OLD) == 1, 'enum anchor not unique'
    s = s.replace(SE_OLD, SE_NEW, 1)
    wr(p, s)
    applied.append('spelleffects.h: the entrap kind')

s = rd(p)
assert s.count('STATUS_ENTANGLED') == 1, 'b kind'
assert s.count('STATUS_COUNT') == 1, 'b count intact'
assert s.count('STATUS_POLYMORPHED,') == 1, 'b prior kind'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) ai/actor.h: the netVolley mark ----
AH_OLD = '    bool  monsterRanged = false;'
AH_NEW = NL.join([
    '    bool  monsterRanged = false;',
    '    // R318: the net-entrap mark - the R315 net',
    '    // throwers entrapt on a volley hit (the MM',
    '    // hooked nets; resolveMissile reads this).',
    '    bool  netVolley = false;',
])
clean(AH_OLD, 78)
clean(AH_NEW, 78)
assert Q not in AH_NEW, 'c apostrophe'

p = 'ai/actor.h'
s = rd(p)
if 'netVolley' in s:
    already.append('actor.h: the netVolley mark')
else:
    assert s.count(AH_OLD) == 1, 'member anchor not unique'
    s = s.replace(AH_OLD, AH_NEW, 1)
    wr(p, s)
    applied.append('actor.h: the netVolley mark')

s = rd(p)
assert s.count('netVolley') == 1, 'c member'
assert s.count('monsterRanged = false') == 1, 'c prior mark'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) ai/actor.cpp: the canAct gate ----
CA_OLD = NL.join([
    '    if (hasStatus(spelleffects::STATUS_POLYMORPHED)) return false;',
])
CA_NEW = NL.join([
    '    if (hasStatus(spelleffects::STATUS_POLYMORPHED)) return false;',
    '    if (hasStatus(spelleffects::STATUS_ENTANGLED)) return false;',
])
clean(CA_OLD, 78)
clean(CA_NEW, 78)

p = 'ai/actor.cpp'
s = rd(p)
if s.count(
    'STATUS_ENTANGLED)) return false') == 1:
    already.append('actor.cpp: the canAct gate')
else:
    assert s.count(CA_OLD) == 1, 'canAct anchor not unique'
    assert 'STATUS_ENTANGLED' not in s, 'canAct collision'
    s = s.replace(CA_OLD, CA_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the canAct gate')

s = rd(p)
assert s.count(
    'STATUS_ENTANGLED)) return false') == 1, 'd gate'
assert s.count('bool Actor::canAct') == 1, 'd canAct intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) ai/actor.cpp: the stepRound tear fold ----
ST_OLD = NL.join([
    '    if (m_distance > 0) --m_distance;',
    '',
    '    // end conditions',
])
ST_NEW = NL.join([
    '    if (m_distance > 0) --m_distance;',
    '',
    '    // R318: the net-entrap tear (the MM print)',
    '    // - a strength of 16 or greater grasps and',
    '    // tears the hooked net at the round start,',
    '    // BEFORE the end conditions (a strong member',
    '    // tears before the stalemate read); the',
    '    // weaker victims stay held (the hooks - no',
    '    // escape roll exists, the print bars it)',
    '    for (int t = 0; t < 2; ++t) {',
    '        auto& team = t == 0 ? m_party : m_monsters;',
    '        for (auto& a : team) {',
    '            if (!a.alive()) continue;',
    '            if (!a.hasStatus(',
    '                    spelleffects::STATUS_ENTANGLED))',
    '                continue;',
    '            if ((int)a.str >=',
    '                    rules::uwNetEntrapStrTear()) {',
    '                for (auto& st : a.statuses)',
    '                    if (st.kind ==',
    '                        spelleffects::',
    '                        STATUS_ENTANGLED)',
    '                        st.kind =',
    '                            spelleffects::',
    '                            STATUS_NONE;',
    '                a.tickStatuses();',
    '                logLine(a.name +',
    '                        ' + DQ + ' tears free of the net!' + DQ +
    ');',
    '            }',
    '        }',
    '    }',
    '',
    '    // end conditions',
])
for _t in (ST_OLD, ST_NEW):
    clean(_t, 78)
assert Q not in ST_NEW, 'e apostrophe'

p = 'ai/actor.cpp'
s = rd(p)
if 'tears free of the net' in s:
    already.append('actor.cpp: the tear fold')
else:
    assert s.count(ST_OLD) == 1, 'tear anchor not unique'
    s = s.replace(ST_OLD, ST_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the tear fold')

s = rd(p)
assert s.count('tears free of the net') == 1, 'e print'
assert s.count(
    'uwNetEntrapStrTear') == 1, 'e pin call'
assert s.count('// end conditions') == 1, 'e tail intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch e balance'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) ai/actor.cpp: the resolveMissile entrap ----
RM_OLD = NL.join([
    '    if (!rules::attackRollHits(m_dice, toHit, adj)) {',
    '        logLine(attacker.name + ' + DQ + ' misses ' + DQ +
    ' + defender.name +',
    '                (hurled ? ' + DQ + ' with a hurled weapon' + DQ,
    '                        : ' + DQ + ' with a missile' + DQ +
    '));',
    '        return;',
    '    }',
    '',
    '    int dmg;',
])
RM_NEW = NL.join([
    '    if (!rules::attackRollHits(m_dice, toHit, adj)) {',
    '        logLine(attacker.name + ' + DQ + ' misses ' + DQ +
    ' + defender.name +',
    '                (hurled ? ' + DQ + ' with a hurled weapon' + DQ,
    '                        : ' + DQ + ' with a missile' + DQ +
    '));',
    '        return;',
    '    }',
    '',
    '    // R318: the net volley entrap (the MM',
    '    // print) - a net hit entraps the victim,',
    '    // no wound (nets are used to entrap); the',
    '    // hooks hold until torn (the zero-round',
    '    // permanence, the stepRound tear fold)',
    '    if (attacker.netVolley && defender.alive()) {',
    '        spelleffects::StatusEffect st;',
    '        st.kind = spelleffects::STATUS_ENTANGLED;',
    '        st.roundsRemaining = 0;   // until torn',
    '        defender.addStatus(st);',
    '        logLine(defender.name +',
    '                ' + DQ + ' is entrapped in the hooked' + DQ,
    '                ' + DQ + ' net!' + DQ + ');',
    '        return;',
    '    }',
    '',
    '    int dmg;',
])
for _t in (RM_OLD, RM_NEW):
    clean(_t, 78)
assert Q not in RM_NEW, 'f apostrophe'

p = 'ai/actor.cpp'
s = rd(p)
if 'entrapped in the hooked' in s:
    already.append('actor.cpp: the missile entrap')
else:
    assert s.count(RM_OLD) == 1, 'missile anchor not unique'
    s = s.replace(RM_OLD, RM_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the missile entrap')

s = rd(p)
assert s.count('entrapped in the hooked') == 1, 'f print'
assert s.count('netVolley') == 1, 'f mark read'
assert s.count('int dmg;') == 2, 'f dmg intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch f balance'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) rules/uwfight.h: the entrap pin ----
UF_OLD = NL.join([
    'inline int uwDeepCrossbowAllowed() {',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
])
UF_NEW = NL.join([
    'inline int uwDeepCrossbowAllowed() {',
    '    return 1;',
    '}',
    '',
    '// The net entrap: the MM grasp-and-tear',
    '// strength (the sahuagin hooked nets -',
    '// escape virtually impossible for victims',
    '// not able to grasp and tear with a',
    '// strength of 16 or greater; the R318',
    '// stepRound tear fold reads this pin).',
    'inline int uwNetEntrapStrTear() {',
    '    return 16;',
    '}',
    '',
    '}  // namespace rules',
])
for _t in (UF_OLD, UF_NEW):
    clean(_t, 78)
assert Q not in UF_NEW, 'g apostrophe'

p = 'rules/uwfight.h'
s = rd(p)
if 'uwNetEntrapStrTear' in s:
    already.append('uwfight.h: the entrap pin')
else:
    assert s.count(UF_OLD) == 1, 'uwfight anchor not unique'
    s = s.replace(UF_OLD, UF_NEW, 1)
    wr(p, s)
    applied.append('uwfight.h: the entrap pin')

s = rd(p)
assert s.count('uwNetEntrapStrTear') == 1, 'g pin'
assert s.count(
    'uwDeepCrossbowAllowed') == 1, 'g prior pin'
assert s.count('}  // namespace rules') == 1, 'g ns intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch g balance'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- (h) state_combat.cpp: the netVolley set ----
NV_OLD = NL.join([
    '                m.monsterRanged = true;',
    '                m.rangedRounds =',
    '                    monsterKey == ' + DQ + 'sahuagin' + DQ,
])
NV_NEW = NL.join([
    '                m.monsterRanged = true;',
    '                m.netVolley = true;   // R318: the',
    '                                // entrap mark (actor.cpp)',
    '                m.rangedRounds =',
    '                    monsterKey == ' + DQ + 'sahuagin' + DQ,
])
for _t in (NV_OLD, NV_NEW):
    clean(_t, 78)
assert Q not in NV_NEW, 'h apostrophe'

p = 'game/state_combat.cpp'
s = rd(p)
if 'm.netVolley = true' in s:
    already.append('state_combat.cpp: the mark set')
else:
    assert s.count(NV_OLD) == 1, 'mark anchor not unique'
    s = s.replace(NV_OLD, NV_NEW, 1)
    wr(p, s)
    applied.append('state_combat.cpp: the mark set')

s = rd(p)
assert s.count('m.netVolley = true') == 1, 'h set'
assert s.count('m.monsterRanged = true') == 2, (
    'h ranged intact')
assert s.count('uwNetThrowSahuaginFt') == 1, 'h r315 intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch h balance'
assert len(applied) + len(already) == 8, 'patch h count wrong'

# ---- (i) regtest.cpp: the R318 audit ----
RT_ANCH = NL.join([
    '        printf(' + DQ +
    'R317 infravision fold audit: bad %d' + BS + 'n' +
    DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])

def rt_hero(strv):
    return NL.join([
        '            ai::Actor a;',
        '            a.isCharacter = true;',
        '            a.name = ' + DQ + 'Heroa' + DQ + ';',
        '            a.classIndex = 0; a.level = 1;',
        '            a.dex = 10;',
        '            a.str = ' + strv + ';',
        '            a.hp = 30; a.maxHp = 30;',
        '            a.weapon.id = items::WPN_SPEAR;',
        '            spelleffects::StatusEffect st;',
        '            st.kind =',
        '                spelleffects::STATUS_ENTANGLED;',
        '            st.roundsRemaining = 0;   // until torn',
        '            a.addStatus(st);',
        '            pt.push_back(a);',
    ])

def rt_mon():
    return NL.join([
        '            std::vector<ai::Actor> mons;',
        '            ai::Actor m;',
        '            m.team = 1; m.hitDice = 1;',
        '            m.name = ' + DQ + 'Monst' + DQ + ';',
        '            m.hp = 6; m.maxHp = 6;',
        '            mons.push_back(m);',
    ])

RT_N1 = NL.join([
    '        // N1: the gate - an entrapped actor',
    '        // cannot act (Actor-level, no dice)',
    '        {',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.hp = 10; a.maxHp = 10;',
    '            a.str = 10;',
    '            if (!a.canAct()) ++bad;',
    '            spelleffects::StatusEffect st;',
    '            st.kind =',
    '                spelleffects::STATUS_ENTANGLED;',
    '            a.addStatus(st);',
    '            if (a.canAct()) ++bad;',
    '        }',
])
RT_N2_HEAD = NL.join([
    '        // N2: the tear - STR 17 tears free at',
    '        // the round start (no dice: the fold',
    '        // reads the pin)',
    '        {',
    '            std::vector<ai::Actor> pt;',
])
RT_N2 = NL.join(RT_N2_HEAD.split(NL) +
    rt_hero('17').split(NL) + rt_mon().split(NL) + [
    '            ai::Encounter enc(pt, mons, 20);',
    '            enc.stepRound();',
    '            bool torn = false;',
    '            for (const auto& ln : enc.log())',
    '                if (ln.text.find(' + DQ +
    'tears free of the net' + DQ + ')',
    '                    != std::string::npos)',
    '                    torn = true;',
    '            if (!torn) ++bad;',
    '            if (enc.party().empty() ||',
    '                enc.party()[0].hasStatus(',
    '                    spelleffects::STATUS_ENTANGLED))',
    '                ++bad;',
    '        }',
])
RT_N3_HEAD = NL.join([
    '        // N3: the hold - STR 10 stays',
    '        // entrapped (the hooks, no escape',
    '        // roll exists)',
    '        {',
    '            std::vector<ai::Actor> pt;',
])
RT_N3 = NL.join(RT_N3_HEAD.split(NL) +
    rt_hero('10').split(NL) + rt_mon().split(NL) + [
    '            ai::Encounter enc(pt, mons, 20);',
    '            enc.stepRound();',
    '            for (const auto& ln : enc.log())',
    '                if (ln.text.find(' + DQ +
    'tears free of the net' + DQ + ')',
    '                    != std::string::npos)',
    '                    ++bad;',
    '            if (enc.party().empty() ||',
    '                !enc.party()[0].hasStatus(',
    '                    spelleffects::STATUS_ENTANGLED))',
    '                ++bad;',
    '        }',
])
RT_N4 = NL.join([
    '        // N4: the pins (the MM data)',
    '        {',
    '            if (rules::uwNetEntrapStrTear() != 16)',
    '                ++bad;',
    '        }',
])
RT_N5 = NL.join([
    '        // N5: the mark - the sahuagin net',
    '        // thrower carries the entrap flag in',
    '        // the water fight, not on land',
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
    '                           ' + DQ + 'sahuagin' + DQ + ');',
    '            if (!st.combat.encounter) ++bad;',
    '            if (st.combat.encounter &&',
    '                !st.combat.encounter->monsters()[0]',
    '                    .netVolley) ++bad;',
    '        }',
])
RT_HEAD = NL.join([
    '    // ---- R318: the net entrap layer audit',
    '    // ----',
    '    // The MM hooked nets: the R315 net',
    '    // throwers entrapt on a volley hit',
    '    // (resolveMissile, no wound - nets are',
    '    // used to entrap); STATUS_ENTANGLED',
    '    // bars action (the held precedent); a',
    '    // strength of 16 or greater tears free',
    '    // at the round start (uwNetEntrapStrTear,',
    '    // the stepRound fold BEFORE the end',
    '    // conditions); weaker victims stay held',
    '    // (no escape roll - the print bars it).',
    '    // The volley hit rides the R37 dice (the',
    '    // R315 convention).',
    '    {',
    '        int bad = 0;',
])
RT_TAIL = NL.join([
    '        printf(' + DQ +
    'R318 net entrap layer audit: bad %d' + BS + 'n' +
    DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_BLOCK = NL.join(RT_HEAD.split(NL) +
                  RT_N1.split(NL) + RT_N2.split(NL) +
                  RT_N3.split(NL) + RT_N4.split(NL) +
                  RT_N5.split(NL) + RT_TAIL.split(NL))
RT_NEW = NL.join(RT_ANCH.split(NL)[:3] +
                RT_BLOCK.split(NL) +
                RT_ANCH.split(NL)[3:])
for _t in (RT_HEAD, RT_N1, RT_N2, RT_N3, RT_N4, RT_N5):
    clean(_t, 76)
for _ln in RT_TAIL.split(NL):
    assert len(_ln) <= 76, 'rt tail line too long'
    assert all(ord(c) < 128 for c in _ln), 'non-ascii tail'
assert Q not in RT_BLOCK.replace(DQ, ''), 'i apostrophe'

p = 'regtest.cpp'
s = rd(p)
if 'R318 net entrap layer audit' in s:
    already.append('regtest.cpp: the R318 audit')
else:
    assert s.count(RT_ANCH) == 1, 'rt anchor not unique'
    assert s.count('audit: bad') == 244, 'rt census not 244'
    s = s.replace(RT_ANCH, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the R318 audit')

s = rd(p)
assert s.count('R318 net entrap layer audit') == 1, 'i entry'
assert s.count('audit: bad') == 245, 'patch i census wrong'
assert s.count(
    'R317 infravision fold audit') == 1, 'i r317 intact'
assert s.count(
    'R227: the wis mental save wiring audit') == 1, 'i r227 intact'
assert s.count('tears free of the net') == 2, 'i tear phrase'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch i balance'
assert len(applied) + len(already) == 9, 'patch i count wrong'

# ---- (j) tools/dmg_gap_report.md: the chronicle ----
GP_OLD = NL.join([
    'census moves 243 -> 244 with the R317',
    'audit.',
    '',
    'Categories:',
])
GP_NEW = NL.join([
    'census moves 243 -> 244 with the R317',
    'audit.',
    '',
    'R318 the net entrap layer: the MM',
    'sahuagin hooked nets charge the',
    'R315 throwers - a new STATUS_ENTANGLED',
    '(the held precedent) bars action; a',
    'volley hit entraps instead of wounding',
    '(resolveMissile, nets are used to',
    'entrap); the entrap is permanent until',
    'torn (the zero-round convention) and a',
    'strength of 16 or greater tears free',
    'at the round start (uwNetEntrapStrTear,',
    'the stepRound fold before the end',
    'conditions); weaker victims stay held -',
    'no escape roll exists, the print bars',
    'it. The census moves 244 -> 245 with',
    'the R318 audit.',
    '',
    'Categories:',
])
clean(GP_OLD, 57, gap=True)
clean(GP_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R318 the net entrap layer' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(GP_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(GP_OLD, GP_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R318 the net entrap layer') == 1, 'j entry'
assert s.count('Categories:') == 1, 'j legend head'
assert s.count('moves 244 -> 245') == 1, 'j census'
assert s.count('moves 243 -> 244') == 1, 'j r317 intact'
assert len(applied) + len(already) == 10, 'patch j count wrong'

# ---- R318 tail ----
if len(applied) + len(already) != 10:
    print('R318 splice: FAIL - expected 10 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R318 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R318 note: 10 patches; the net entrap')
print('layer charges the MM hooked nets (the')
print('R317 seed entry rides as the first')
print('patch); the battery census moves')
print('244 -> 245')
print('commit: R318: the net entrap layer')
print('(census 245)')

