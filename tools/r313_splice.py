#!/usr/bin/env python3
# tools/r313_splice.py - R313: the underwater
# fight (every chargeable open thread at
# once).
#
# The pin charge: the DMG UNDERWATER
# ADVENTURES movement and combat paragraphs
# (rules/underwater.h, R311) - the 20-pound
# equipment cap moved 1 pound per 100 g.p.
# of strength weight allowance, only
# thrusting weapons strike underwater
# (crushing and cleaving fail), missile
# weapons impossible except the
# specially-made crossbow - now charged at
# the R312 flooded crossing site.
#
#   (a) rules/uwfight.h - CREATED (the
#       seam, the grenade.h evaluable
#       subset): the strength-fed crossing
#       cap (a cross-call onto the R311
#       uwSwimEncumbranceCapLbs pin), the
#       load gate, the thrusting-only
#       strike, the missile bar.
#   (b) game/state_dungeon.cpp - the
#       enterWater load gate: a living
#       member loaded past the strength-fed
#       cap bars the company (the bump
#       convention; the JUDGMENT - the
#       surface paragraph carries no load
#       bar, the movement paragraph folds
#       onto the crossing). The allowance
#       derives at the site from the R153
#       ladder (rules::strWeightAllowGp) -
#       the R311 cap is un-caller-fed.
#   (c) ai/actor.h - the setWaterFight
#       flag, the waterStrikeAllowed probe
#       declaration, the member.
#   (d) ai/actor.cpp - the uwfight include,
#       the probe (the bare fists of a
#       hurled weapon, the monk open hand
#       and the monsters outside the gate),
#       the resolveMelee gate (the water
#       turns the stroke).
#   (e) game/state_combat.cpp - the uwfight
#       include, the beginCombat water-fight
#       flag (the company stands in the
#       pool), the combatShoot and
#       combatThrow water bars.
#   (f) regtest.cpp - the include line.
#   (g) regtest.cpp - the R313a seam audit
#       (audit_eval) and the R313 engine
#       audit (seeded scenarios the replica
#       walked first); the battery census
#       moves 237 -> 239.
#   (h) tools/dmg_gap_report.md - the
#       chronicle paragraph (no box flip -
#       the dmg ledger holds ZERO open
#       items).
#
# NOT CHARGED (recorded, the seam header):
# the vision decay (no engine vision layer
# exists - a future seam), the breathing
# mechanic (no breathing print pin - the
# aids are recorded notes), the aquatic
# first strike and the net prose (no
# aquatic monster roster is pinned).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY
# patch (the R142 lesson). ZERO literal
# backslash bytes in this file except the
# printf continuations, built via chr(92); no
# CONTENT string embeds an apostrophe,
# non-ASCII, or a line past its bound (78 the
# header, 76 regtest, 57 the gap report).
# Commit: "R313: the underwater fight wired
# (census 239)"
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

def _ctrunc(a, b):
    # C integer division (truncation toward
    # zero) - the audit_eval mirror
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b >= 0) else -q

# ---- the replica (the seeded sequences) ----
UMASK = (1 << 64) - 1

class _Rep:
    def __init__(self, s):
        self.st = s if s != 0 else 0x9E3779B97F4A7C15

    def nxt(self):
        self.st ^= self.st >> 12
        self.st &= UMASK
        self.st ^= (self.st << 25) & UMASK
        self.st &= UMASK
        self.st ^= self.st >> 27
        return (self.st * 0x2545F4914F6CDD1D) & UMASK

    def below(self, n):
        if n <= 1:
            return 0
        lim = UMASK - (UMASK % n)
        while True:
            v = self.nxt()
            if v < lim:
                return v % n

    def rrange(self, lo, hi):
        if hi <= lo:
            return lo
        return lo + self.below(hi - lo + 1)

def _sanity():
    # the crossing cap: the R311 pin fold, 20
    # lbs + 1 per full 100 g.p. of allowance
    # (C truncation, the negatives move down)
    assert 20 + _ctrunc(0, 100) == 20, 'cap 0'
    assert 20 + _ctrunc(-350, 100) == 17, 'cap str 3'
    assert 20 + _ctrunc(250, 100) == 22, 'cap 250'
    assert 20 + _ctrunc(750, 100) == 27, 'cap str 18'
    assert 20 + _ctrunc(5000, 100) == 70, 'cap 5000'
    # the load beyond the armor: 1 pound = 10
    # g.p., C truncation, the clamp
    assert _ctrunc(230, 10) == 23, 'load 23'
    assert _ctrunc(240, 10) == 24, 'load 24'
    # the drown band probes (the R311 pin)
    assert 5 + 2 * (24 // 5) == 13, 'drown 13'
    # scenario 1: the barred bump draws the
    # wander d12 only - seed 1 reads 2 (quiet)
    _r = _Rep(1)
    assert 1 + _r.below(12) == 2, 'wander d12 seed 1'
    # scenario 2: the strong member passes the
    # cap and rolls the drown percent 13:
    # seed 26 rolls 12 (goes under), seed 2
    # rolls 30 (the water holds)
    assert _Rep(26).below(100) == 12, 'drown seed 26'
    assert _Rep(2).below(100) == 30, 'hold seed 2'
_sanity()

# ---- (a) rules/uwfight.h CREATED ----
UF = NL.join(
    ['// ====================================================================',
     '// Adnd1 - rules/uwfight.h',
     '// R313: the DMG UNDERWATER ADVENTURES',
     '// movement and combat pins (R311,',
     '// rules/underwater.h) folded for the',
     '// flooded crossing (R312,',
     '// rules/swimcross.h) - the seam the',
     '// crossing site charges.',
     '//',
     '// The print (the MOVEMENT paragraph):',
     '// swimming is impossible in armor',
     '// heavier than leather (magic armor',
     '// excepted) or above 20 pounds of',
     '// equipment - the cap moves 1 pound',
     '// per 100 g.p. of strength bonus or',
     '// penalty. The weight allowance derives',
     '// at the site from the R153 ladder',
     '// (rules/strWeightAllowGp, PHB STR',
     '// Table II) - the R311 cap is',
     '// un-caller-fed: the caller feeds the',
     '// raw strength, the seam folds the pin.',
     '// The JUDGMENT: the surface SWIMMING',
     '// paragraph carries no load bar; the',
     '// movement paragraph folds onto the',
     '// crossing (the R312 one-roll precedent,',
     '// the print condensed to the site).',
     '//',
     '// The print (the COMBAT paragraph):',
     '// only thrusting weapons strike',
     '// underwater - the crushing and cleaving',
     '// swings fail; missile weapons are',
     '// impossible except the specially-made',
     '// crossbow (10x price, half the dungeon',
     '// range - the R311 data). No such item',
     '// is pinned in the engine, so the bar',
     '// reads total; the fold opens when the',
     '// crossbow is pinned.',
     '//',
     '// NOT CHARGED (recorded, ride the R311',
     '// pin, not data): the aquatic first',
     '// strike (no aquatic monster roster is',
     '// pinned), the net throw prose, the free',
     '// action weapon exception (no free action',
     '// effect exists), the vision decay (no',
     '// engine vision layer - a future seam)',
     '// and the breathing aids (recorded notes',
     '// only - no breathing print pin).',
     '//',
     '// The wclass reads the plain',
     '// rules::WeaponClass ints (rules/combat.h',
     '// order): 0 bludgeoning, 1 piercing,',
     '// 2 slashing - dagger, short sword and',
     '// spear thrust; the swords, axes, maces',
     '// and staves fail.',
     '// ====================================================================',
     '',
     '#pragma once',
     '',
     '#include "rules/underwater.h"  // R311: the cap pin',
     '',
     'namespace rules {',
     '',
     '// The crossing equipment cap in pounds:',
     '// the R311 movement pin (20 + 1 per full',
     '// 100 g.p. of the strength weight',
     '// allowance, C truncation - the negatives',
     '// move the cap down).',
     'inline int uwCrossCapLbs(int allowanceGp) {',
     '    return uwSwimEncumbranceCapLbs(allowanceGp);',
     '}',
     '',
     '// The crossing load gate: the load beyond',
     '// the worn armor bars the crossing past',
     '// the strength-fed cap (1 = barred).',
     'inline int uwCrossLoadBars(int loadLbs,',
     '                           int capLbs) {',
     '    return loadLbs > capLbs ? 1 : 0;',
     '}',
     '',
     '// The underwater strike: only the',
     '// thrusting weapons connect underwater',
     '// (the crushing and cleaving swings fail',
     '// - the print); wclass reads the plain',
     '// rules::WeaponClass ints: 0 bludgeoning,',
     '// 1 piercing, 2 slashing.',
     'inline int uwStrikeAllowed(int wclass) {',
     '    return wclass == 1 ? 1 : 0;',
     '}',
     '',
     '// Missile fire underwater is impossible',
     '// except the specially-made crossbow (no',
     '// such item is pinned - the bar reads',
     '// total until the crossbow lands).',
     'inline int uwMissileBarred() {',
     '    return 1;',
     '}',
     '',
     '}  // namespace rules',
     '',
     ])
clean(UF, 78)
assert Q not in UF, 'apostrophe in header'

p = 'rules/uwfight.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'inline int uwMissileBarred() {' in s:
        already.append('uwfight.h created')
    else:
        fails.append('uwfight.h exists without the R313 marker')
else:
    wr(p, UF)
    applied.append('uwfight.h created')

s = rd(p)
assert Q not in s, 'uf apostrophes'
assert s.count('namespace rules') == 2, 'uf namespace pair'
assert s.count('}  // namespace rules') == 1, 'uf namespace close'
assert s.count('{') == s.count('}'), 'uf brace balance'
assert s.count('(') == s.count(')'), 'uf paren balance'
assert s.count('inline int uwCrossCapLbs') == 1, 'uf cap accessor'
assert s.count('inline int uwCrossLoadBars') == 1, 'uf load gate'
assert s.count('inline int uwStrikeAllowed') == 1, 'uf strike gate'
assert s.count('inline int uwMissileBarred') == 1, 'uf missile bar'
assert s.count('return uwSwimEncumbranceCapLbs(allowanceGp);') == 1, 'uf cross-call'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) game/state_dungeon.cpp: the include, the load gate ----
SD_I_OLD = NL.join([
    '#include "rules/underwater.h"  // R311: the drown percent',
])
SD_I_NEW = NL.join([
    '#include "rules/underwater.h"  // R311: the drown percent',
    '#include "rules/uwfight.h"  // R313: the crossing cap',
])
SD_OLD = NL.join([
    '                return false;',
    '            }',
    '        }',
    '        log.add("The company takes to the water.");',
])
SD_NEW = NL.join([
    '                return false;',
    '            }',
    '            // R313: the strength-fed equipment cap',
    '            // (the R311 underwater movement pin,',
    '            // un-caller-fed by the R153 allowance',
    '            // ladder): a living member loaded past',
    '            // the 20-pound cap moved by the',
    '            // strength weight allowance bars the',
    '            // company - the bump convention (the',
    '            // JUDGMENT: the surface paragraph',
    '            // carries no load bar, the movement',
    '            // paragraph folds onto the crossing)',
    '            if (rules::uwCrossLoadBars(',
    '                    rules::swimLoadBeyondArmorLbs(',
    '                        carriedWeight(c),',
    '                        items::armor(c.armor.id).weightGp),',
    '                    rules::uwCrossCapLbs(',
    '                        rules::strWeightAllowGp(',
    '                            c.abilities.str, c.exStr)))) {',
    '                ++turnCount;',
    '                tickActivity(1);   // R119: the refusal',
    '                char buf[96];',
    '                snprintf(buf, sizeof buf,',
    '                         "%s is too laden to swim - the "',
    '                         "flood bars the way.",',
    '                         c.name.c_str());',
    '                log.add(buf);',
    '                // the turn spent can draw a wanderer',
    '                if (dm::wanderCheck(dice, wander))',
    '                    spawnWanderingEncounter();',
    '                return false;',
    '            }',
    '        }',
    '        log.add("The company takes to the water.");',
])
for _t in (SD_I_OLD, SD_I_NEW, SD_OLD, SD_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in dungeon content'

p = 'game/state_dungeon.cpp'
s = rd(p)
if 'uwCrossLoadBars' in s:
    already.append('state_dungeon.cpp: the load gate')
else:
    assert 'too laden to swim' not in s, 'dungeon marker collision'
    assert 'strWeightAllowGp' not in s, 'dungeon marker collision'
    assert 'uwfight' not in s, 'dungeon include collision'
    assert s.count(SD_I_OLD) == 1, 'dungeon include anchor'
    assert s.count(SD_OLD) == 1, 'dungeon gate anchor not unique'
    s = s.replace(SD_I_OLD, SD_I_NEW)
    s = s.replace(SD_OLD, SD_NEW)
    wr(p, s)
    applied.append('state_dungeon.cpp: the load gate')

s = rd(p)
assert s.count('#include "rules/uwfight.h"') == 1, 'b include'
assert s.count('uwCrossLoadBars') == 1, 'b gate call'
assert s.count('too laden to swim') == 1, 'b laden print'
assert s.count('rules::strWeightAllowGp(') == 1, 'b ladder feed'
assert s.count('takes to the water') == 1, 'b plunge intact'
assert s.count('goes under - drowned.') == 1, 'b drown intact'
assert s.count('cannot swim in') == 1, 'b armor gate intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) ai/actor.h: the flag, the probe, the member ----
AH_S_OLD = NL.join([
    '    void setOpeningBands(int bands) {',
    '        if (bands < 1) bands = 1;',
    '        if (bands > 12) bands = 12;',
    '        m_distance = bands;',
    '    }',
])
AH_S_NEW = NL.join([
    '    void setOpeningBands(int bands) {',
    '        if (bands < 1) bands = 1;',
    '        if (bands > 12) bands = 12;',
    '        m_distance = bands;',
    '    }',
    '',
    '    // R313: the water fight - the company',
    '    // stands in the flood pool (the app sets',
    '    // this at combat start); the R311',
    '    // underwater combat pins then gate the',
    '    // party strikes (waterStrikeAllowed).',
    '    void setWaterFight() { m_waterFight = true; }',
    '',
    '    // R313: the underwater strike probe (the',
    '    // R311 combat pin): in a water fight a',
    '    // party member strikes only with a',
    '    // thrusting weapon - the print: the',
    '    // crushing and cleaving swings fail. The',
    '    // bare fists of a hurled weapon and the',
    '    // monk open hand are not wielded weapons,',
    '    // and monsters are outside the gate.',
    '    bool waterStrikeAllowed(const Actor& a) const;',
])
AH_M_OLD = NL.join([
    '    bool m_teleported = false;              // R83: Teleport escape',
])
AH_M_NEW = NL.join([
    '    bool m_teleported = false;              // R83: Teleport escape',
    '',
    '    bool m_waterFight = false;   // R313: the water fight',
])
for _t in (AH_S_OLD, AH_S_NEW, AH_M_OLD, AH_M_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in actor header content'

p = 'ai/actor.h'
s = rd(p)
if 'setWaterFight' in s:
    already.append('actor.h: the flag and the probe')
else:
    assert 'waterStrikeAllowed' not in s, 'actor header collision'
    assert 'm_waterFight' not in s, 'actor header collision'
    assert s.count(AH_S_OLD) == 1, 'actor setter anchor not unique'
    assert s.count(AH_M_OLD) == 1, 'actor member anchor not unique'
    s = s.replace(AH_S_OLD, AH_S_NEW)
    s = s.replace(AH_M_OLD, AH_M_NEW)
    wr(p, s)
    applied.append('actor.h: the flag and the probe')

s = rd(p)
assert s.count('void setWaterFight()') == 1, 'c setter'
assert s.count('bool waterStrikeAllowed(const Actor& a) const;') == 1, 'c probe decl'
assert s.count('bool m_waterFight = false;') == 1, 'c member'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) ai/actor.cpp: the include, the probe, the gate ----
AC_I_OLD = NL.join([
    '#include "../rules/thieffunc.h"  // R302: the silence percentile',
])
AC_I_NEW = NL.join([
    '#include "../rules/thieffunc.h"  // R302: the silence percentile',
    '#include "../rules/uwfight.h"  // R313: the underwater strike gate',
])
AC_P_OLD = NL.join([
    'int Encounter::resolveMelee(Actor& attacker, Actor& defender) {',
])
AC_P_NEW = NL.join([
    '// ---- waterStrikeAllowed ----',
    '// R313: the R311 underwater strike pin',
    '// probe (the seam, rules/uwfight.h) - the',
    '// gate decision for one attacker (see',
    '// actor.h).',
    'bool Encounter::waterStrikeAllowed(const Actor& a) const{',
    '        if (!a.isCharacter || !m_waterFight) return true;',
    '        if (a.weaponThrown) return true;',
    '        if (a.subclass == rules::SUB_MONK) return true;',
    '        return rules::uwStrikeAllowed(',
    '            (int)items::weapon(a.weapon.id).wclass) != 0;',
    '    }',
    '',
    'int Encounter::resolveMelee(Actor& attacker, Actor& defender) {',
])
AC_G_OLD = NL.join([
    '    // R232: backstab - a thief-group character striking a',
])
AC_G_NEW = NL.join([
    '    // R313: the underwater combat pin (R311) at',
    '    // the water fight: only the thrusting',
    '    // weapons strike underwater - the crushing',
    '    // and cleaving swings fail (the print; the',
    '    // aquatic first strike, the nets and the',
    '    // free-action notes stay data). The gate',
    '    // rides the public waterStrikeAllowed probe.',
    '    if (!waterStrikeAllowed(attacker)) {',
    '        const items::WeaponDef& w =',
    '            items::weapon(attacker.weapon.id);',
    '        logLine(attacker.name + " swings " + w.name +',
    '                 " - the water turns the stroke.");',
    '        return 0;',
    '    }',
    '',
    '    // R232: backstab - a thief-group character striking a',
])
for _t in (AC_I_OLD, AC_I_NEW, AC_P_OLD, AC_P_NEW,
           AC_G_OLD, AC_G_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in actor content'

p = 'ai/actor.cpp'
s = rd(p)
if 'Encounter::waterStrikeAllowed' in s:
    already.append('actor.cpp: the probe and the gate')
else:
    assert 'uwStrikeAllowed' not in s, 'actor cpp collision'
    assert 'the water turns the stroke' not in s, 'actor cpp collision'
    assert 'uwfight' not in s, 'actor cpp include collision'
    assert s.count(AC_I_OLD) == 1, 'actor include anchor'
    assert s.count(AC_P_OLD) == 1, 'actor probe anchor'
    assert s.count(AC_G_OLD) == 1, 'actor gate anchor'
    s = s.replace(AC_I_OLD, AC_I_NEW)
    s = s.replace(AC_P_OLD, AC_P_NEW)
    s = s.replace(AC_G_OLD, AC_G_NEW)
    wr(p, s)
    applied.append('actor.cpp: the probe and the gate')

s = rd(p)
assert s.count('#include "../rules/uwfight.h"') == 1, 'd include'
assert s.count('Encounter::waterStrikeAllowed') == 1, 'd probe def'
assert s.count('if (!waterStrikeAllowed(attacker))') == 1, 'd gate call'
assert s.count('the water turns the stroke') == 1, 'd stroke print'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) game/state_combat.cpp: the flag and the bars ----
SC_I_OLD = NL.join([
    '#include "appstate.h"',
    '',
    '// ---- partyActors ----',
])
SC_I_NEW = NL.join([
    '#include "appstate.h"',
    '#include "../rules/uwfight.h"  // R313: the underwater bars',
    '',
    '// ---- partyActors ----',
])
SC_F_OLD = NL.join([
    '        combat.start(partyActors(), std::move(foes),',
    '                     rng.below(0x7FFFFFFF));',
])
SC_F_NEW = NL.join([
    '        combat.start(partyActors(), std::move(foes),',
    '                     rng.below(0x7FFFFFFF));',
    '        // R313: the water fight - the company',
    '        // standing in the flood pool fights under',
    '        // the R311 underwater combat pins',
    '        if (map.at(party.x, party.y) == TILE_WATER)',
    '            combat.encounter->setWaterFight();',
])
SC_SH_OLD = NL.join([
    'void AppState::combatShoot(){',
    '        if (mode != MODE_COMBAT || !combat.encounter || combat.over)',
    '            return;',
])
SC_SH_NEW = NL.join([
    'void AppState::combatShoot(){',
    '        if (mode != MODE_COMBAT || !combat.encounter || combat.over)',
    '            return;',
    '        // R313: the underwater combat pin (R311) -',
    '        // missile fire is impossible underwater',
    '        // except the specially-made crossbow (no',
    '        // such item is pinned; the bar is total)',
    '        if (rules::uwMissileBarred() &&',
    '            map.at(party.x, party.y) == TILE_WATER) {',
    '            log.add("The water bars missile fire - no "',
    '                    "crossbow of the deep.");',
    '            return;',
    '        }',
])
SC_TH_OLD = NL.join([
    'void AppState::combatThrow(){',
    '        if (mode != MODE_COMBAT || !combat.encounter || combat.over)',
    '            return;',
])
SC_TH_NEW = NL.join([
    'void AppState::combatThrow(){',
    '        if (mode != MODE_COMBAT || !combat.encounter || combat.over)',
    '            return;',
    '        // R313: the hurled weapon is a missile too -',
    '        // the underwater bar rides the throw',
    '        if (rules::uwMissileBarred() &&',
    '            map.at(party.x, party.y) == TILE_WATER) {',
    '            log.add("The water bars the hurl - no "',
    '                    "crossbow of the deep.");',
    '            return;',
    '        }',
])
for _t in (SC_I_OLD, SC_I_NEW, SC_F_OLD, SC_F_NEW,
           SC_SH_OLD, SC_SH_NEW, SC_TH_OLD, SC_TH_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in combat content'

p = 'game/state_combat.cpp'
s = rd(p)
if 'setWaterFight' in s:
    already.append('state_combat.cpp: the flag and the bars')
else:
    assert 'uwMissileBarred' not in s, 'combat collision'
    assert 'bars missile fire' not in s, 'combat collision'
    assert 'bars the hurl' not in s, 'combat collision'
    assert s.count(SC_I_OLD) == 1, 'combat include anchor'
    assert s.count(SC_F_OLD) == 1, 'combat flag anchor'
    assert s.count(SC_SH_OLD) == 1, 'combat shoot anchor'
    assert s.count(SC_TH_OLD) == 1, 'combat throw anchor'
    s = s.replace(SC_I_OLD, SC_I_NEW)
    s = s.replace(SC_F_OLD, SC_F_NEW)
    s = s.replace(SC_SH_OLD, SC_SH_NEW)
    s = s.replace(SC_TH_OLD, SC_TH_NEW)
    wr(p, s)
    applied.append('state_combat.cpp: the flag and the bars')

s = rd(p)
assert s.count('combat.encounter->setWaterFight();') == 1, 'e flag'
assert s.count('rules::uwMissileBarred()') == 2, 'e bars'
assert s.count('bars missile fire') == 1, 'e shoot bar'
assert s.count('bars the hurl') == 1, 'e throw bar'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch e balance'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) regtest.cpp: the include line ----
RG_I_OLD = NL.join([
    '#include "rules/swimcross.h"  // R312: the flooded crossing',
])
RG_I_NEW = NL.join([
    '#include "rules/swimcross.h"  // R312: the flooded crossing',
    '#include "rules/uwfight.h"  // R313: the underwater fight',
])
for _t in (RG_I_OLD, RG_I_NEW):
    clean(_t, 76)
    assert Q not in _t, 'apostrophe in include content'

p = 'regtest.cpp'
s = rd(p)
if '#include "rules/uwfight.h"' in s:
    already.append('regtest.cpp: the include line')
else:
    assert 'uwfight' not in s, 'include marker collision'
    assert s.count(RG_I_OLD) == 1, 'include anchor not unique'
    s = s.replace(RG_I_OLD, RG_I_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the include line')

s = rd(p)
assert s.count('#include "rules/uwfight.h"') == 1, 'f include'
assert s.count('#include "rules/swimcross.h"') == 1, 'f anchor'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) regtest.cpp: the audit blocks ----
RT_TAIL = NL.join([
    '        printf("R312 flooded crossing engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_NEXT = NL.join([
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_AUD_A = NL.join(
    ['    // ---- R313a: the underwater fight seam audit ----',
     '    // The DMG UNDERWATER ADVENTURES movement and',
     '    // combat pins folded for the crossing (rules/',
     '    // uwfight.h, the grenade.h pattern): the',
     '    // strength-fed equipment cap (the R311 20-lb',
     '    // pin, +1 lb per full 100 g.p. of the R153',
     '    // weight allowance), the thrusting-only',
     '    // strike and the missile bar - verified by',
     '    // audit_eval. The wclass reads the plain',
     '    // rules::WeaponClass ints (0 bludgeoning, 1',
     '    // piercing, 2 slashing).',
     '    {',
     '        int bad = 0;',
     '        // the crossing cap: 20 lbs plus the strength',
     '        // allowance (C truncation; the negatives',
     '        // move the cap down)',
     '        if (rules::uwCrossCapLbs(0) != 20 ||',
     '            rules::uwCrossCapLbs(-350) != 17 ||',
     '            rules::uwCrossCapLbs(250) != 22 ||',
     '            rules::uwCrossCapLbs(5000) != 70) ++bad;',
     '        // the cap cross-call identity: the seam fold',
     '        // equals the R311 pin everywhere probed',
     '        for (int i = 0; i <= 100; ++i)',
     '            if (rules::uwCrossCapLbs(i * 50) !=',
     '                rules::uwSwimEncumbranceCapLbs(',
     '                    i * 50)) ++bad;',
     '        // the load gate: the load beyond the armor',
     '        // bars past the cap, the cap itself passes',
     '        if (rules::uwCrossLoadBars(17, 17) != 0 ||',
     '            rules::uwCrossLoadBars(18, 17) != 1 ||',
     '            rules::uwCrossLoadBars(20, 17) != 1 ||',
     '            rules::uwCrossLoadBars(23, 27) != 0) ++bad;',
     '        // the thrusting-only strike: the bludgeon and',
     '        // the slash fail, the thrust connects',
     '        if (rules::uwStrikeAllowed(0) != 0 ||',
     '            rules::uwStrikeAllowed(1) != 1 ||',
     '            rules::uwStrikeAllowed(2) != 0) ++bad;',
     '        // the missile bar (the special crossbow is',
     '        // unpinned data - the bar is total)',
     '        if (rules::uwMissileBarred() != 1) ++bad;',
     '        printf("R313a underwater fight seam audit: bad %d'
     + BS + 'n", bad);',
     '        if (bad) return 1;',
     '    }',
     ])
RT_AUD_E = NL.join(
    ['    // ---- R313: the underwater fight engine audit ----',
     '    // The strength-fed cap and the combat pins',
     '    // charge the R312 crossing site: the laden weak',
     '    // member bars the company (the bump',
     '    // convention), the strong member passes the',
     '    // cap and rolls the drown percent (the replica',
     '    // walked every seed first), the water fight',
     '    // gates the mace swing (the water turns the',
     '    // stroke, the monster hp untouched; the spear',
     '    // strikes, the dry fight swings free) and the',
     '    // missile and hurl commands bar in the pool.',
     '    // The gate scenarios assert only the',
     '    // roll-independent facts (the gate fires before',
     '    // any die; the party of 30 hp outlives the one',
     '    // monster swing of a 1-HD foe).',
     '    {',
     '        int bad = 0;',
     '        // scenario 1: the str 3 member (allowance',
     '        // -350, cap 17) carries 23 lbs beyond the',
     '        // bare armor - barred (seed 1: the wander',
     '        // d12 reads 2, quiet)',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            Character wea;',
     '            wea.name = "Wea";',
     '            wea.classIndex = 0; wea.level = 1;',
     '            wea.race = 0;',
     '            wea.hp = 30; wea.maxHp = 30;',
     '            wea.abilities.str = 3;',
     '            wea.armor.id = items::ARMOR_NONE_EQUIPPED;',
     '            PackItem axe;',
     '            axe.kind = 0;',
     '            axe.id = items::WPN_BATTLE_AXE;',
     '            for (int i = 0; i < 3; ++i)',
     '                wea.pack.push_back(axe);',
     '            st.party.members.push_back(wea);',
     '            st.rng.seed(1);',
     '            if (st.enterWater(5, 7)) ++bad;',
     '            if (st.turnCount != 1) ++bad;',
     '            if (st.party.members[0].hp != 30) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "Wea is too laden to swim")',
     '                == std::string::npos) ++bad;',
     '        }',
     '        // scenario 2: the str 18 member (allowance',
     '        // 750, cap 27) carries 24 lbs - passes the',
     '        // cap; the drown percent reads 13: seed 26',
     '        // rolls 12 (goes under), seed 2 rolls 30',
     '        // (the water holds)',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            Character str;',
     '            str.name = "Str";',
     '            str.classIndex = 0; str.level = 1;',
     '            str.race = 0;',
     '            str.hp = 30; str.maxHp = 30;',
     '            str.abilities.str = 18;',
     '            str.armor.id = items::ARMOR_NONE_EQUIPPED;',
     '            PackItem axe;',
     '            axe.kind = 0;',
     '            axe.id = items::WPN_BATTLE_AXE;',
     '            str.pack.push_back(axe);',
     '            str.pack.push_back(axe);',
     '            PackItem mace;',
     '            mace.kind = 0;',
     '            mace.id = items::WPN_MACE;',
     '            str.pack.push_back(mace);',
     '            st.party.members.push_back(str);',
     '            st.rng.seed(26);',
     '            if (!st.enterWater(5, 7)) ++bad;',
     '            if (st.party.members[0].hp != 0) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "Str goes under - drowned.")',
     '                == std::string::npos) ++bad;',
     '        }',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            Character str;',
     '            str.name = "Str";',
     '            str.classIndex = 0; str.level = 1;',
     '            str.race = 0;',
     '            str.hp = 30; str.maxHp = 30;',
     '            str.abilities.str = 18;',
     '            str.armor.id = items::ARMOR_NONE_EQUIPPED;',
     '            PackItem axe;',
     '            axe.kind = 0;',
     '            axe.id = items::WPN_BATTLE_AXE;',
     '            str.pack.push_back(axe);',
     '            str.pack.push_back(axe);',
     '            PackItem mace;',
     '            mace.kind = 0;',
     '            mace.id = items::WPN_MACE;',
     '            str.pack.push_back(mace);',
     '            st.party.members.push_back(str);',
     '            st.rng.seed(2);',
     '            if (!st.enterWater(5, 7)) ++bad;',
     '            if (st.party.members[0].hp != 30) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "takes to the water")',
     '                == std::string::npos) ++bad;',
     '        }',
     '        // scenario 3: the water fight - the mace',
     '        // swing fails (the water turns the stroke,',
     '        // the monster hp untouched); the spear',
     '        // strikes; the dry fight swings free',
     '        {',
     '            std::vector<ai::Actor> pt;',
     '            ai::Actor a;',
     '            a.isCharacter = true;',
     '            a.classIndex = 0; a.level = 1;',
     '            a.hp = 30; a.maxHp = 30;',
     '            a.weapon.id = items::WPN_MACE;',
     '            pt.push_back(a);',
     '            std::vector<ai::Actor> mons;',
     '            ai::Actor m;',
     '            m.team = 1; m.hitDice = 1;',
     '            m.hp = 6; m.maxHp = 6;',
     '            mons.push_back(m);',
     '            ai::Encounter enc(pt, mons, 7);',
     '            enc.setWaterFight();',
     '            enc.setOpeningBands(1);',
     '            enc.stepRound();',
     '            bool turned = false;',
     '            for (const auto& ln : enc.log())',
     '                if (ln.text.find(',
     '                        "the water turns the stroke")',
     '                    != std::string::npos) turned = true;',
     '            if (!turned) ++bad;',
     '            if (enc.monsters()[0].hp != 6) ++bad;',
     '        }',
     '        {',
     '            std::vector<ai::Actor> pt;',
     '            ai::Actor a;',
     '            a.isCharacter = true;',
     '            a.classIndex = 0; a.level = 1;',
     '            a.hp = 30; a.maxHp = 30;',
     '            a.weapon.id = items::WPN_MACE;',
     '            pt.push_back(a);',
     '            std::vector<ai::Actor> mons;',
     '            ai::Actor m;',
     '            m.team = 1; m.hitDice = 1;',
     '            m.hp = 6; m.maxHp = 6;',
     '            mons.push_back(m);',
     '            ai::Encounter enc(pt, mons, 7);',
     '            enc.setOpeningBands(1);',
     '            enc.stepRound();',
     '            bool turned = false;',
     '            for (const auto& ln : enc.log())',
     '                if (ln.text.find(',
     '                        "the water turns the stroke")',
     '                    != std::string::npos) turned = true;',
     '            if (turned) ++bad;',
     '        }',
     '        {',
     '            std::vector<ai::Actor> pt;',
     '            ai::Actor a;',
     '            a.isCharacter = true;',
     '            a.classIndex = 0; a.level = 1;',
     '            a.hp = 30; a.maxHp = 30;',
     '            a.weapon.id = items::WPN_SPEAR;',
     '            pt.push_back(a);',
     '            std::vector<ai::Actor> mons;',
     '            ai::Actor m;',
     '            m.team = 1; m.hitDice = 1;',
     '            m.hp = 6; m.maxHp = 6;',
     '            mons.push_back(m);',
     '            ai::Encounter enc(pt, mons, 7);',
     '            enc.setWaterFight();',
     '            enc.setOpeningBands(1);',
     '            enc.stepRound();',
     '            bool turned = false;',
     '            for (const auto& ln : enc.log())',
     '                if (ln.text.find(',
     '                        "the water turns the stroke")',
     '                    != std::string::npos) turned = true;',
     '            if (turned) ++bad;',
     '        }',
     '        // scenario 4: the missile and hurl bars -',
     '        // the company in the pool cannot shoot or',
     '        // hurl (beginCombat sets the water fight,',
     '        // the commands bar at the tile)',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            Character arc;',
     '            arc.name = "Arc";',
     '            arc.classIndex = 0; arc.level = 1;',
     '            arc.race = 0;',
     '            arc.hp = 30; arc.maxHp = 30;',
     '            st.party.members.push_back(arc);',
     '            st.party.x = 5; st.party.y = 5;',
     '            st.map.set(5, 5, world::TILE_WATER);',
     '            std::vector<ai::Actor> foes;',
     '            ai::Actor m;',
     '            m.team = 1; m.hitDice = 1;',
     '            m.hp = 6; m.maxHp = 6;',
     '            foes.push_back(m);',
     '            st.beginCombat(std::move(foes), -1,',
     '                            "giant_rat");',
     '            st.combatShoot();',
     '            if (st.log.get(0).find(',
     '                    "bars missile fire")',
     '                == std::string::npos) ++bad;',
     '            st.combatThrow();',
     '            if (st.log.get(0).find(',
     '                    "bars the hurl")',
     '                == std::string::npos) ++bad;',
     '        }',
     '        printf("R313 underwater fight engine audit: bad %d'
     + BS + 'n", bad);',
     '        if (bad) return 1;',
     '    }',
     ])
RT_OLD = RT_TAIL + NL + RT_NEXT
RT_NEW = (RT_TAIL + NL + RT_AUD_A + NL + RT_AUD_E + NL +
          RT_NEXT)
# the audit blocks carry the printf newline (BS) -
# BS lives ONLY on the printf lines, one per line
for _t in (RT_OLD, RT_NEW, RT_AUD_A, RT_AUD_E):
    for _ln in _t.split(NL):
        assert all(ord(_c) < 128 for _c in _ln), 'nonascii'
        assert len(_ln) <= 76, 'audit line too long: ' + _ln
        assert Q not in _ln, 'apostrophe in audit'
        if 'printf("' in _ln:
            assert _ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in _ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R313a underwater fight seam audit' in s:
    already.append('regtest.cpp: the audit blocks')
else:
    assert s.count('audit: bad') == 237, 'rt census not 237'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    assert 'uwCrossCapLbs' not in s, 'rt collision'
    assert 'setWaterFight' not in s, 'rt collision'
    assert 'R313a' not in s, 'rt collision'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit blocks')

s = rd(p)
assert s.count('audit: bad') == 239, 'patch g census wrong'
assert s.count('R313a underwater fight seam audit') == 1, 'g a'
assert s.count('R313 underwater fight engine audit') == 1, 'g e'
assert s.count('R312 flooded crossing engine audit') == 1, 'g r312'
assert s.count(
    'R227: the wis mental save wiring audit') == 1, 'g head'
assert s.count('{') == s.count('}'), 'rt brace balance'
assert s.count('(') == s.count(')'), 'rt paren balance'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- (h) tools/dmg_gap_report.md: the chronicle ----
CH_OLD = NL.join([
    'moves 235 -> 237 with',
    'the R312a seam and R312 engine audits.',
    '',
    'Categories:',
])
CH_NEW = NL.join([
    'moves 235 -> 237 with',
    'the R312a seam and R312 engine audits.',
    '',
    'R313 the underwater fight (every',
    'chargeable open thread at once): rules/',
    'uwfight.h (the seam - the strength-fed',
    'crossing cap uwCrossCapLbs, the R311',
    '20-lb equipment pin fed by the R153',
    'weight-allowance ladder, with the load',
    'gate; the thrusting-only strike',
    'uwStrikeAllowed; the missile bar - no',
    'special crossbow is pinned, the bar is',
    'total) wired at the R312 crossing: the',
    'laden member past the cap bars the',
    'company (the bump convention; the',
    'judgment - the surface paragraph carries',
    'no load bar, the movement paragraph',
    'folds onto the crossing), the water',
    'fight (ai/actor.cpp setWaterFight plus',
    'the waterStrikeAllowed probe - the',
    'crushing and cleaving swings fail, the',
    'bare fists, the monk open hand and the',
    'monsters outside the gate) and the',
    'missile and hurl bars in the pool',
    '(state_combat.cpp). The vision decay',
    'and the breathing pins stay data (no',
    'engine vision layer, no breathing print',
    'pin); the aquatic first strike and the',
    'nets stay data (no aquatic monster',
    'roster). The census moves 237 -> 239',
    'with the R313a seam and R313 engine',
    'audits.',
    '',
    'Categories:',
])
clean(CH_OLD, 57, gap=True)
clean(CH_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R313 the underwater fight' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(CH_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(CH_OLD, CH_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R313 the underwater fight') == 1, 'h entry'
assert s.count('Categories:') == 1, 'h legend head'
assert s.count('census moves 237 -> 239') == 1, 'h census'
assert s.count('moves 235 -> 237 with') == 1, 'h r312 intact'
assert s.count('- [ ]') == 1, 'h open residue (the legend)'
assert len(applied) + len(already) == 8, 'patch h count wrong'

# ---- R313 fails/tail ----
if fails:
    print('R313 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 8:
    print('R313 splice: FAIL - expected 8 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R313 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R313 note: 8 patches; the underwater')
print('fight wired - the strength-fed cap,')
print('the thrusting-only strike and the')
print('missile bars charge the crossing; the')
print('battery census moves 237 -> 239')
print('commit: R313: the underwater fight')
print('wired (census 239)')

