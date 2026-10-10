#!/usr/bin/env python3
# tools/r314_splice.py - R314: the deep
# crossbow, the aquatic first strike and
# the waterborne wanderers (one splice).
#
# The pin charges: the DMG UNDERWATER
# ADVENTURES combat paragraph (rules/
# underwater.h, R311) - the specially-
# made crossbow (10x price, half the
# dungeon range) and the aquatic first
# strike - plus the DMG p.190 fresh-water
# table (R127, dm::rollWaterborneEncounter)
# now charged at the R312 flood pool.
#
#   (a) items/items.h - the WPN_CROSSBOW_
#       DEEP enum row before WPN_COUNT (no
#       switch rides the enum; the WPN_
#       COUNT uses are bounds checks and
#       arrays, patched here and below).
#   (b) items/items.cpp - the kWeapons
#       row: fights as the light crossbow
#       (the p.38 AC row), half the range
#       (3 tens of feet, the R311 divisor),
#       ten times the price (120 g.p., the
#       R311 multiple), the same 70-lb
#       weight - the JUDGMENT.
#   (c) regtest.cpp - the R189 kRows 16th
#       row (declared-size == initializer,
#       the R171b lesson).
#   (d) game/state_combat.cpp - the
#       combatShoot bar lifts for the deep
#       crossbow alone (the R313 audit
#       scenario 4 - a member with NO
#       ranged weapon - still reads the
#       bar); the throw stays barred.
#   (e) rules/uwfight.h - the R314 seam
#       pins (uwAquaticFirstStrikeSegment,
#       uwCompanyEarliestSegment,
#       uwWaterborneIsAquatic,
#       uwDeepCrossbowAllowed) and the now-
#       stale header comments (the R311
#       uwAquaticFirstStrike gate stays the
#       R311 pin - not redefined here).
#   (f) ai/actor.h - the setAquatic flag
#       and the member.
#   (g) ai/actor.cpp - the stepRound fold:
#       in a water fight with the aquatic
#       flag the monsters floor at segment
#       1 and the company earliest at 2
#       (the print exception - the
#       significantly-longer weapon - reads
#       data; no reach layer exists).
#   (h) game/state_combat.cpp - the
#       waterborne wanderer at the pool:
#       the fresh shallow cool table (the
#       state_sea precedent), the count from
#       the registry noAppearing, the
#       aquatic flag on the encounter.
#   (i) regtest.cpp - the R314a seam audit
#       (audit_eval) and the R314 engine
#       audit (seeded scenarios the replica
#       walked first); the battery census
#       moves 239 -> 241.
#   (j) tools/dmg_gap_report.md - the
#       chronicle paragraph (no box flip).
#
# NOT CHARGED (recorded, the seam header):
# the net throw prose (no net item is
# pinned), the breathing mechanic and the
# vision decay (no engine layers).
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
# Commit: "R314: the deep crossbow and the
# aquatic wanderers (census 241)"
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

    def roll(self, count, sides, bonus):
        t = bonus
        for _ in range(count):
            t += self.below(sides) + 1
        return t

def _surprise_segments(total):
    if total <= 2:
        return 3
    if total <= 5:
        return 2
    if total <= 7:
        return 1
    return 0

def _sanity():
    # W1 (the pool spawn, seed 11): the
    # percentile draws read 50 and 42; 50
    # lands lizard_man (41-60, the fresh
    # shallow cool table), the registry
    # noAppearing 10-40 gives the count
    # 10 + below(31) = 22
    _r = _Rep(11)
    assert _r.roll(1, 100, 0) == 50, 'w1 p1'
    assert _r.roll(1, 100, 0) == 42, 'w1 p2'
    assert 10 + _r.below(31) == 22, 'w1 count'
    # W2 (the first strike, seed 20): the
    # party surprise 2d6 reads 9 (0
    # segments), the monster surprise 8 (0),
    # pIni 5 against mIni 4 - the control
    # company strikes first (segment 2 vs
    # 3); the aquatic fold floors the
    # monster at 1 and the party at 2
    _r = _Rep(20)
    assert _surprise_segments(_r.roll(2, 6, 0)) == 0, 'w2 pSurp'
    assert _surprise_segments(_r.roll(2, 6, 0)) == 0, 'w2 mSurp'
    _p = _r.roll(1, 6, 0)
    _m = _r.roll(1, 6, 0)
    assert _p == 5 and _m == 4, 'w2 initiative'
    assert 7 - _p == 2 and 7 - _m == 3, 'w2 control segs'
    assert 0 + 1 == 1 and 2 >= 2, 'w2 fold segs'
_sanity()

# ---- (a) items/items.h: the enum row ----
IH_OLD = NL.join([
    '    WPN_SLING,',
    '    WPN_COUNT',
    '};',
])
IH_NEW = NL.join([
    '    WPN_SLING,',
    '    WPN_CROSSBOW_DEEP,   // R314: the specially-made',
    '                           // underwater crossbow',
    '    WPN_COUNT',
    '};',
])
for _t in (IH_OLD, IH_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in items header'

p = 'items/items.h'
s = rd(p)
if 'WPN_CROSSBOW_DEEP' in s:
    already.append('items.h: the enum row')
else:
    assert s.count(IH_OLD) == 1, 'items enum anchor not unique'
    s = s.replace(IH_OLD, IH_NEW)
    wr(p, s)
    applied.append('items.h: the enum row')

s = rd(p)
assert s.count('WPN_CROSSBOW_DEEP') == 1, 'a enum row'
assert s.count('WPN_COUNT') == 1, 'a count intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch a balance'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) items/items.cpp: the kWeapons row ----
IC_OLD = NL.join([
    '      {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 } },',
    '};',
])
IC_NEW = NL.join([
    '      {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 } },',
    '    { "Deep Crossbow",  rules::WCLASS_PIERCING,',
    '      1,4,0,  1,4,0,    true,    3,  1,   70,   120,',
    '      // R314: the specially-made underwater crossbow',
    '      // (the R311 print) - fights as the light crossbow',
    '      // (the p.38 row, AC 0..10), half the range (3',
    '      // tens of feet, the R311 divisor), ten times the',
    '      // price (120 g.p., the R311 multiple), the same',
    '      // 70-lb weight - the JUDGMENT',
    '      {-3,-2,-2,-1, 0, 0,+1,+2,+3,+3,+3 } },',
    '};',
])
for _t in (IC_OLD, IC_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in items content'

p = 'items/items.cpp'
s = rd(p)
if 'WPN_CROSSBOW_DEEP' in s or 'Deep Crossbow' in s:
    already.append('items.cpp: the kWeapons row')
else:
    assert s.count(IC_OLD) == 1, 'items row anchor not unique'
    s = s.replace(IC_OLD, IC_NEW)
    wr(p, s)
    applied.append('items.cpp: the kWeapons row')

s = rd(p)
assert s.count('Deep Crossbow') == 1, 'b table row'
assert s.count('WPN_CROSSBOW_DEEP') == 0, 'b no enum leak'
assert s.count('kWeapons[WPN_COUNT]') == 1, 'b array size'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) regtest.cpp: the R189 kRows row ----
KR_OLD = NL.join([
    '            // Sling',
    '            {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 },',
    '        };',
])
KR_NEW = NL.join([
    '            // Sling',
    '            {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 },',
    '            // Deep Crossbow (fights as the light',
    '            // crossbow - the R314 special)',
    '            {-3,-2,-2,-1, 0, 0,+1,+2,+3,+3,+3 },',
    '        };',
])
for _t in (KR_OLD, KR_NEW):
    clean(_t, 76)
    assert Q not in _t, 'apostrophe in kRows content'

p = 'regtest.cpp'
s = rd(p)
if 'Deep Crossbow' in s:
    already.append('regtest.cpp: the kRows row')
else:
    assert s.count(KR_OLD) == 1, 'kRows anchor not unique'
    s = s.replace(KR_OLD, KR_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the kRows row')

s = rd(p)
assert s.count('Deep Crossbow') == 1, 'c kRows row'
assert s.count(
    'kRows[items::WPN_COUNT][11]') == 1, 'c array decl'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) game/state_combat.cpp: the combatShoot lift ----
SH_OLD = NL.join([
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
SH_NEW = NL.join([
    '        // R313: the underwater combat pin (R311) -',
    '        // missile fire is impossible underwater',
    '        // except the specially-made crossbow -',
    '        // R314: the deep crossbow is pinned (the',
    '        // seam fold uwDeepCrossbowAllowed); the bar',
    '        // lifts for it alone, and a member with no',
    '        // ranged weapon still reads the bar',
    '        if (rules::uwMissileBarred() &&',
    '            map.at(party.x, party.y) == TILE_WATER) {',
    '            const auto& pa =',
    '                combat.encounter->party();',
    '            bool deep =',
    '                combat.activeMember >= 0 &&',
    '                combat.activeMember <',
    '                    (int)pa.size() &&',
    '                pa[combat.activeMember]',
    '                    .rangedWeapon.id ==',
    '                    items::WPN_CROSSBOW_DEEP &&',
    '                rules::uwDeepCrossbowAllowed() != 0;',
    '            if (!deep) {',
    '                log.add("The water bars missile fire - no "',
    '                        "crossbow of the deep.");',
    '                return;',
    '            }',
    '        }',
])
for _t in (SH_OLD, SH_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in shoot content'

p = 'game/state_combat.cpp'
s = rd(p)
if 'WPN_CROSSBOW_DEEP' in s:
    already.append('state_combat.cpp: the shoot lift')
else:
    assert 'uwDeepCrossbowAllowed' not in s, 'shoot collision'
    assert s.count(SH_OLD) == 1, 'shoot anchor not unique'
    s = s.replace(SH_OLD, SH_NEW)
    wr(p, s)
    applied.append('state_combat.cpp: the shoot lift')

s = rd(p)
assert s.count('WPN_CROSSBOW_DEEP') == 1, 'd deep check'
assert s.count('uwDeepCrossbowAllowed() != 0') == 1, 'd fold'
assert s.count('bars missile fire') == 1, 'd bar intact'
assert s.count('bars the hurl') == 1, 'd hurl intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) rules/uwfight.h: the R314 pins ----
UF_C1_OLD = NL.join([
    '// impossible except the specially-made',
    '// crossbow (10x price, half the dungeon',
    '// range - the R311 data). No such item',
    '// is pinned in the engine, so the bar',
    '// reads total; the fold opens when the',
    '// crossbow is pinned.',
])
UF_C1_NEW = NL.join([
    '// impossible except the specially-made',
    '// crossbow (10x price, half the dungeon',
    '// range - the R311 data). R314: the deep',
    '// crossbow is pinned (items/items.h) - the',
    '// missile bar lifts for it alone (the',
    '// combatShoot fold in state_combat.cpp).',
])
UF_C2_OLD = NL.join([
    '// NOT CHARGED (recorded, ride the R311',
    '// pin, not data): the aquatic first',
    '// strike (no aquatic monster roster is',
    '// pinned), the net throw prose, the free',
])
UF_C2_NEW = NL.join([
    '// NOT CHARGED (recorded, ride the R311',
    '// pin, not data): the net throw prose,',
    '// the free',
])
UF_C3_OLD = NL.join([
    '// Missile fire underwater is impossible',
    '// except the specially-made crossbow (no',
    '// such item is pinned - the bar reads',
    '// total until the crossbow lands).',
])
UF_C3_NEW = NL.join([
    '// Missile fire underwater is impossible',
    '// except the specially-made crossbow',
    '// (R314: the deep crossbow is pinned in',
    '// items - the bar lifts for it alone at',
    '// the combatShoot fold).',
])
UF_P_OLD = NL.join([
    'inline int uwMissileBarred() {',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
])
UF_P_NEW = NL.join([
    'inline int uwMissileBarred() {',
    '    return 1;',
    '}',
    '',
    '// The aquatic first strike (the R311 pin',
    '// uwAquaticFirstStrike, above): the fold',
    '// floors the aquatic monsters at the',
    '// first segment and the company no',
    '// earlier than the second - the print',
    '// exception (the significantly-longer',
    '// company weapon) reads data, no reach',
    '// layer exists (the JUDGMENT: no aquatic',
    '// monster roster is pinned - aquatic',
    '// means the encounter arrived via the',
    '// waterborne table, the R127 fold).',
    'inline int uwAquaticFirstStrikeSegment() {',
    '    return 1;',
    '}',
    '',
    '// The company (the land-side weapons)',
    '// acts no earlier than this segment in',
    '// the aquatic first-strike fold.',
    'inline int uwCompanyEarliestSegment() {',
    '    return 2;',
    '}',
    '',
    '// The waterborne wanderer is the aquatic',
    '// monster (the R127 fresh-water table',
    '// feeds the flood pool).',
    'inline int uwWaterborneIsAquatic() {',
    '    return 1;',
    '}',
    '',
    '// The deep crossbow (the specially-made',
    '// underwater crossbow, R314, items) lifts',
    '// the underwater missile bar.',
    'inline int uwDeepCrossbowAllowed() {',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
])
for _t in (UF_C1_OLD, UF_C1_NEW, UF_C2_OLD, UF_C2_NEW,
           UF_C3_OLD, UF_C3_NEW, UF_P_OLD, UF_P_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in uwfight content'

p = 'rules/uwfight.h'
s = rd(p)
if 'uwAquaticFirstStrikeSegment' in s:
    already.append('uwfight.h: the R314 pins')
else:
    assert 'uwWaterborneIsAquatic' not in s, 'uwfight collision'
    assert 'uwDeepCrossbowAllowed' not in s, 'uwfight collision'
    assert s.count(UF_C1_OLD) == 1, 'uwfight c1 anchor'
    assert s.count(UF_C2_OLD) == 1, 'uwfight c2 anchor'
    assert s.count(UF_C3_OLD) == 1, 'uwfight c3 anchor'
    assert s.count(UF_P_OLD) == 1, 'uwfight pin anchor'
    s = s.replace(UF_C1_OLD, UF_C1_NEW)
    s = s.replace(UF_C2_OLD, UF_C2_NEW)
    s = s.replace(UF_C3_OLD, UF_C3_NEW)
    s = s.replace(UF_P_OLD, UF_P_NEW)
    wr(p, s)
    applied.append('uwfight.h: the R314 pins')

s = rd(p)
assert s.count('}  // namespace rules') == 1, 'e namespace close'
assert s.count(
    'inline int uwAquaticFirstStrikeSegment') == 1, 'e seg pin'
assert s.count(
    'inline int uwCompanyEarliestSegment') == 1, 'e floor pin'
assert s.count(
    'inline int uwWaterborneIsAquatic') == 1, 'e gate pin'
assert s.count(
    'inline int uwDeepCrossbowAllowed') == 1, 'e crossbow pin'
assert s.count('inline int uwAquaticFirstStrike()') == 0, (
    'e no R311 redefinition')
assert 'No such item' not in s, 'e stale comment gone'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch e balance'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) ai/actor.h: the aquatic flag ----
AH_S_OLD = NL.join([
    '    void setWaterFight() { m_waterFight = true; }',
])
AH_S_NEW = NL.join([
    '    void setWaterFight() { m_waterFight = true; }',
    '',
    '    // R314: the aquatic first strike - the',
    '    // encounter arrived via the waterborne',
    '    // table (the flood pool spawn); the R311',
    '    // print: the aquatic monsters strike',
    '    // first (the stepRound fold, uwfight.h).',
    '    void setAquatic() { m_aquatic = true; }',
])
AH_M_OLD = NL.join([
    '    bool m_waterFight = false;   // R313: the water fight',
])
AH_M_NEW = NL.join([
    '    bool m_waterFight = false;   // R313: the water fight',
    '    bool m_aquatic = false;   // R314: the aquatic fold',
])
for _t in (AH_S_OLD, AH_S_NEW, AH_M_OLD, AH_M_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in actor header content'

p = 'ai/actor.h'
s = rd(p)
if 'setAquatic' in s:
    already.append('actor.h: the aquatic flag')
else:
    assert 'm_aquatic' not in s, 'actor header collision'
    assert s.count(AH_S_OLD) == 1, 'actor setter anchor'
    assert s.count(AH_M_OLD) == 1, 'actor member anchor'
    s = s.replace(AH_S_OLD, AH_S_NEW)
    s = s.replace(AH_M_OLD, AH_M_NEW)
    wr(p, s)
    applied.append('actor.h: the aquatic flag')

s = rd(p)
assert s.count('void setAquatic()') == 1, 'f setter'
assert s.count('bool m_aquatic = false;') == 1, 'f member'
assert s.count('void setWaterFight()') == 1, 'f r313 intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch f balance'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) ai/actor.cpp: the first-strike fold ----
AC_OLD = NL.join([
    '    int baseSegP = rules::initiativeToSegment(pIni) + pSurp;',
    '    int baseSegM = rules::initiativeToSegment(mIni) + mSurp;',
])
AC_NEW = NL.join([
    '    int baseSegP = rules::initiativeToSegment(pIni) + pSurp;',
    '    int baseSegM = rules::initiativeToSegment(mIni) + mSurp;',
    '',
    '    // R314: the aquatic first strike (the',
    '    // R311 print and pin) - the waterborne',
    '    // monsters strike first in the water',
    '    // fight unless the company weapon is',
    '    // significantly longer; no reach layer',
    '    // exists, so the exception reads data',
    '    // and the fold floors the segments',
    '    // (rules/uwfight.h).',
    '    if (m_waterFight && m_aquatic &&',
    '        rules::uwAquaticFirstStrike()) {',
    '        baseSegM = mSurp +',
    '            rules::uwAquaticFirstStrikeSegment();',
    '        if (baseSegP <',
    '            rules::uwCompanyEarliestSegment())',
    '            baseSegP =',
    '                rules::uwCompanyEarliestSegment();',
    '    }',
])
for _t in (AC_OLD, AC_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in actor content'

p = 'ai/actor.cpp'
s = rd(p)
if 'uwAquaticFirstStrikeSegment' in s:
    already.append('actor.cpp: the first-strike fold')
else:
    assert 'm_aquatic' not in s, 'actor cpp collision'
    assert s.count(AC_OLD) == 1, 'actor fold anchor'
    s = s.replace(AC_OLD, AC_NEW)
    wr(p, s)
    applied.append('actor.cpp: the first-strike fold')

s = rd(p)
assert s.count(
    'rules::uwAquaticFirstStrike()') == 1, 'g gate call'
assert s.count(
    'rules::uwAquaticFirstStrikeSegment();') == 1, 'g seg pin'
assert s.count(
    'rules::uwCompanyEarliestSegment()') == 2, 'g floor pins'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch g balance'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- (h) game/state_combat.cpp: the pool spawn ----
SP_OLD = NL.join([
    '        if (hiddenThief) {',
    '            hiddenThief = false;',
    '            log.add("The hidden company holds its "',
    '                    "breath - the wanderer passes.");',
    '            return;',
    '        }',
])
SP_NEW = NL.join([
    '        if (hiddenThief) {',
    '            hiddenThief = false;',
    '            log.add("The hidden company holds its "',
    '                    "breath - the wanderer passes.");',
    '            return;',
    '        }',
    '',
    '        // R314: the waterborne wanderer - the',
    '        // company standing in the flood pool',
    '        // rolls the DMG fresh-water table',
    '        // (R127, dm::rollWaterborneEncounter)',
    '        // instead of the dungeon matrix. The',
    '        // JUDGMENT: fresh, shallow, cool - the',
    '        // pool site (the state_sea precedent);',
    '        // the count rides the registry',
    '        // noAppearing. The waterborne monsters',
    '        // are the aquatic first strike (the',
    '        // R311 print) - the flag rides the',
    '        // encounter; the substituted keys',
    '        // stay land monsters.',
    '        if (map.at(party.x, party.y) == TILE_WATER) {',
    '            dm::DungeonEncounter e =',
    '                dm::rollWaterborneEncounter(',
    '                    registry, dice,',
    '                    (int)dice.roll(1, 100, 0),',
    '                    (int)dice.roll(1, 100, 0),',
    '                    dm::WaterBody::FRESH,',
    '                    dm::WaterDepth::SHALLOW,',
    '                    dm::WaterClime::COOL);',
    '            if (e.key.empty() || e.count <= 0) {',
    '                log.add("The pool stirs - nothing "',
    '                        "surfaces.");',
    '                return;',
    '            }',
    '            std::vector<ai::Actor> foes =',
    '                buildFoesFromDm(e);',
    '            if (foes.empty()) return;',
    '            char buf[96];',
    '            snprintf(buf, sizeof buf,',
    '                     "%d %s surface in the pool!",',
    '                     e.count, e.key.c_str());',
    '            log.add(buf);',
    '            beginCombat(std::move(foes), -1,',
    '                       e.key);',
    '            if (combat.encounter &&',
    '                rules::uwWaterborneIsAquatic())',
    '                combat.encounter->setAquatic();',
    '            return;',
    '        }',
])
for _t in (SP_OLD, SP_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in spawn content'

p = 'game/state_combat.cpp'
s = rd(p)
if 'surface in the pool' in s:
    already.append('state_combat.cpp: the pool spawn')
else:
    assert 'rollWaterborneEncounter' not in s, 'spawn collision'
    assert 'uwWaterborneIsAquatic' not in s, 'spawn collision'
    assert s.count(SP_OLD) == 1, 'spawn anchor not unique'
    s = s.replace(SP_OLD, SP_NEW)
    wr(p, s)
    applied.append('state_combat.cpp: the pool spawn')

s = rd(p)
assert s.count('surface in the pool') == 1, 'h print'
assert s.count(
    'rules::uwWaterborneIsAquatic()') == 1, 'h gate call'
assert s.count(
    'combat.encounter->setAquatic();') == 1, 'h flag set'
assert s.count('hidden company holds its') == 1, 'h anchor intact'
assert s.count('WPN_CROSSBOW_DEEP') == 1, 'h shoot intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch h balance'
assert len(applied) + len(already) == 8, 'patch h count wrong'

# ---- (i) regtest.cpp: the audit blocks ----
RT_TAIL = NL.join([
    '        printf("R313 underwater fight engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_NEXT = NL.join([
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_AUD_A = NL.join(
    ['    // ---- R314a: the crossbow and the aquatic',
     '    // first strike seam audit ----',
     '    // The R314 pins (rules/uwfight.h, the',
     '    // grenade.h pattern): the deep crossbow',
     '    // (the R311 specially-made crossbow -',
     '    // the missile bar lifts for it alone),',
     '    // the aquatic first-strike floors and',
     '    // the waterborne gate; the R311 net and',
     '    // crossbow data and the R313 regression',
     '    // probes ride the same block - verified',
     '    // by audit_eval.',
     '    {',
     '        int bad = 0;',
     '        // the R314 pins',
     '        if (rules::uwDeepCrossbowAllowed() != 1 ||',
     '            rules::uwWaterborneIsAquatic() != 1 ||',
     '            rules::uwAquaticFirstStrike() != 1 ||',
     '            rules::uwAquaticFirstStrikeSegment()',
     '                != 1 ||',
     '            rules::uwCompanyEarliestSegment()',
     '                != 2) ++bad;',
     '        // the R311 crossbow and net data',
     '        if (rules::uwSpecialCrossbowPriceMultiple()',
     '                != 10 ||',
     '            rules::uwSpecialCrossbowRangeDivisor()',
     '                != 2 ||',
     '            rules::uwNetThrowFtPerStrPoint() != 1 ||',
     '            rules::uwNetThrowUnderwaterRaceFt()',
     '                != 15 ||',
     '            rules::uwNetThrowSahuaginFt() != 20 ||',
     '            rules::uwNetUntrainedPenalty() != 4)',
     '            ++bad;',
     '        // the R313 regression probes',
     '        if (rules::uwStrikeAllowed(0) != 0 ||',
     '            rules::uwStrikeAllowed(1) != 1 ||',
     '            rules::uwStrikeAllowed(2) != 0 ||',
     '            rules::uwMissileBarred() != 1 ||',
     '            rules::uwCrossCapLbs(0) != 20 ||',
     '            rules::uwCrossCapLbs(5000) != 70)',
     '            ++bad;',
     '        printf("R314a crossbow and aquatic seam audit: bad %d'
     + BS + 'n", bad);',
     '        if (bad) return 1;',
     '    }',
     ])
RT_AUD_E = NL.join(
    ['    // ---- R314: the crossbow and the',
     '    // aquatic wanderers engine audit ----',
     '    // The replica walked every seed first: the',
     '    // pool spawn (seed 11) rolls the fresh',
     '    // shallow cool waterborne table - the',
     '    // percentile draws read 50 (lizard man,',
     '    // 41-60) and 42, the registry count 10 +',
     '    // below(31) reads 22; the first strike',
     '    // (seed 20) reads party surprise 9 and',
     '    // monster 8 (no segments), pIni 5 against',
     '    // mIni 4 - the control company strikes',
     '    // first, the aquatic fold floors the',
     '    // monster at segment 1 and the company',
     '    // at 2. The deep crossbow lifts the',
     '    // missile bar; the short bow keeps it.',
     '    {',
     '        int bad = 0;',
     '        // W1: the waterborne wanderer at the',
     '        // pool - 22 lizard men surface and the',
     '        // encounter begins (the waterborne',
     '        // table owns the pool, the census',
     '        // stays draw-independent)',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            st.party.formed = true;',
     '            Character arc;',
     '            arc.name = "Arc";',
     '            arc.classIndex = 0; arc.level = 1;',
     '            arc.race = 0;',
     '            arc.hp = 30; arc.maxHp = 30;',
     '            st.party.members.push_back(arc);',
     '            st.party.x = 5; st.party.y = 5;',
     '            st.map.set(5, 5, world::TILE_WATER);',
     '            st.registry.loadDirectory(',
     '                "monsters/monsters/l");',
     '            st.rng.seed(11);',
     '            st.spawnWanderingEncounter();',
     '            if (st.mode != MODE_COMBAT) ++bad;',
     '            if (!st.combat.encounter) ++bad;',
     '            if (st.combat.encounter &&',
     '                st.combat.encounter->monsters()',
     '                    .size() != 22) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "22 lizard_man surface in the "',
     '                    "pool!")',
     '                == std::string::npos) ++bad;',
     '        }',
     '        // W2: the aquatic first strike - the',
     '        // waterborne monsters strike first',
     '        // (seed 20: no surprise segments,',
     '        // pIni 5 against mIni 4); the control',
     '        // reads the company first',
     '        {',
     '            std::vector<ai::Actor> pt;',
     '            ai::Actor a;',
     '            a.isCharacter = true;',
     '            a.name = "Heroa";',
     '            a.classIndex = 0; a.level = 1;',
     '            a.dex = 10;',
     '            a.hp = 30; a.maxHp = 30;',
     '            a.weapon.id = items::WPN_SPEAR;',
     '            pt.push_back(a);',
     '            std::vector<ai::Actor> mons;',
     '            ai::Actor m;',
     '            m.team = 1; m.hitDice = 1;',
     '            m.name = "Monst";',
     '            m.hp = 6; m.maxHp = 6;',
     '            mons.push_back(m);',
     '            ai::Encounter enc(pt, mons, 20);',
     '            enc.setWaterFight();',
     '            enc.setAquatic();',
     '            enc.setOpeningBands(1);',
     '            enc.stepRound();',
     '            int first = -1;   // 0 Heroa, 1 Monst',
     '            for (const auto& ln : enc.log()) {',
     '                if (ln.text.find("Heroa") == 0)',
     '                    { first = 0; break; }',
     '                if (ln.text.find("Monst") == 0)',
     '                    { first = 1; break; }',
     '            }',
     '            if (first != 1) ++bad;',
     '        }',
     '        {',
     '            std::vector<ai::Actor> pt;',
     '            ai::Actor a;',
     '            a.isCharacter = true;',
     '            a.name = "Heroa";',
     '            a.classIndex = 0; a.level = 1;',
     '            a.dex = 10;',
     '            a.hp = 30; a.maxHp = 30;',
     '            a.weapon.id = items::WPN_SPEAR;',
     '            pt.push_back(a);',
     '            std::vector<ai::Actor> mons;',
     '            ai::Actor m;',
     '            m.team = 1; m.hitDice = 1;',
     '            m.name = "Monst";',
     '            m.hp = 6; m.maxHp = 6;',
     '            mons.push_back(m);',
     '            ai::Encounter enc(pt, mons, 20);',
     '            enc.setWaterFight();',
     '            enc.setOpeningBands(1);',
     '            enc.stepRound();',
     '            int first = -1;   // 0 Heroa, 1 Monst',
     '            for (const auto& ln : enc.log()) {',
     '                if (ln.text.find("Heroa") == 0)',
     '                    { first = 0; break; }',
     '                if (ln.text.find("Monst") == 0)',
     '                    { first = 1; break; }',
     '            }',
     '            if (first != 0) ++bad;',
     '        }',
     '        // C1: the deep crossbow lifts the',
     '        // underwater missile bar - the member',
     '        // readies the shot in the pool',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            st.party.formed = true;',
     '            Character arc;',
     '            arc.name = "Arc";',
     '            arc.classIndex = 0; arc.level = 1;',
     '            arc.race = 0;',
     '            arc.hp = 30; arc.maxHp = 30;',
     '            arc.rangedWeapon.id =',
     '                items::WPN_CROSSBOW_DEEP;',
     '            arc.missileAmmo = 5;',
     '            st.party.members.push_back(arc);',
     '            st.party.x = 5; st.party.y = 5;',
     '            st.map.set(5, 5, world::TILE_WATER);',
     '            std::vector<ai::Actor> foes;',
     '            ai::Actor m;',
     '            m.team = 1; m.hitDice = 1;',
     '            m.hp = 6; m.maxHp = 6;',
     '            foes.push_back(m);',
     '            st.beginCombat(std::move(foes), -1,',
     '                           "giant_rat");',
     '            st.combatShoot();',
     '            if (st.log.get(0).find(',
     '                    "Missiles readied")',
     '                == std::string::npos) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "bars missile fire")',
     '                != std::string::npos) ++bad;',
     '        }',
     '        // C2: the short bow keeps the bar -',
     '        // the lift is the deep crossbow alone',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            st.party.formed = true;',
     '            Character arc;',
     '            arc.name = "Arc";',
     '            arc.classIndex = 0; arc.level = 1;',
     '            arc.race = 0;',
     '            arc.hp = 30; arc.maxHp = 30;',
     '            arc.rangedWeapon.id =',
     '                items::WPN_SHORT_BOW;',
     '            arc.missileAmmo = 5;',
     '            st.party.members.push_back(arc);',
     '            st.party.x = 5; st.party.y = 5;',
     '            st.map.set(5, 5, world::TILE_WATER);',
     '            std::vector<ai::Actor> foes;',
     '            ai::Actor m;',
     '            m.team = 1; m.hitDice = 1;',
     '            m.hp = 6; m.maxHp = 6;',
     '            foes.push_back(m);',
     '            st.beginCombat(std::move(foes), -1,',
     '                           "giant_rat");',
     '            st.combatShoot();',
     '            if (st.log.get(0).find(',
     '                    "bars missile fire")',
     '                == std::string::npos) ++bad;',
     '        }',
     '        printf("R314 crossbow and aquatic engine audit: bad %d'
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
if 'R314a crossbow and aquatic seam audit' in s:
    already.append('regtest.cpp: the audit blocks')
else:
    assert s.count('audit: bad') == 239, 'rt census not 239'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    assert 'R314a' not in s, 'rt collision'
    assert 'setAquatic' not in s, 'rt collision'
    assert 'WPN_CROSSBOW_DEEP' not in s or True, 'rt kRows row'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit blocks')

s = rd(p)
assert s.count('audit: bad') == 241, 'patch i census wrong'
assert s.count(
    'R314a crossbow and aquatic seam audit') == 1, 'i a'
assert s.count(
    'R314 crossbow and aquatic engine audit') == 1, 'i e'
assert s.count('R313 underwater fight engine audit') == 1, (
    'i r313')
assert s.count(
    'R227: the wis mental save wiring audit') == 1, 'i head'
assert s.count('Deep Crossbow') == 1, 'i kRows row'
assert s.count('{') == s.count('}'), 'rt brace balance'
assert s.count('(') == s.count(')'), 'rt paren balance'
assert len(applied) + len(already) == 9, 'patch i count wrong'

# ---- (j) tools/dmg_gap_report.md: the chronicle ----
CH_OLD = NL.join([
    'roster). The census moves 237 -> 239',
    'with the R313a seam and R313 engine',
    'audits.',
    '',
    'Categories:',
])
CH_NEW = NL.join([
    'roster). The census moves 237 -> 239',
    'with the R313a seam and R313 engine',
    'audits.',
    '',
    'R314 the deep crossbow and the aquatic',
    'wanderers (one splice): the specially-',
    'made underwater crossbow pinned (items',
    'WPN_CROSSBOW_DEEP - fights as the light',
    'crossbow, half the range, ten times the',
    'price, the R311 data) and the R313',
    'missile bar lifted for it alone',
    '(state_combat.cpp combatShoot, the seam',
    'fold uwDeepCrossbowAllowed; the throw',
    'stays barred); the aquatic first strike',
    '(the R311 print and pin) folded at',
    'ai/actor.cpp stepRound - the waterborne',
    'monsters floor at segment 1, the company',
    'earliest at 2 (the significantly-longer',
    'weapon exception reads data, no reach',
    'layer; the JUDGMENT: no roster is',
    'pinned - aquatic means the encounter',
    'arrived via the waterborne table), with',
    'the waterborne wanderers at the flood',
    'pool (the R127 fresh shallow cool table,',
    'the state_sea precedent; the count rides',
    'the registry noAppearing). The net',
    'prose, the breathing mechanic and the',
    'vision decay stay data. The census',
    'moves 239 -> 241 with the R314a seam',
    'and R314 engine audits.',
    '',
    'Categories:',
])
clean(CH_OLD, 57, gap=True)
clean(CH_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R314 the deep crossbow' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(CH_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(CH_OLD, CH_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R314 the deep crossbow') == 1, 'j entry'
assert s.count('Categories:') == 1, 'j legend head'
assert s.count(
    'moves 239 -> 241 with the R314a seam') == 1, 'j census'
assert s.count('moves 237 -> 239') == 1, 'j r313 intact'
assert s.count('- [ ]') == 1, 'j open residue (the legend)'
assert len(applied) + len(already) == 10, 'patch j count wrong'

# ---- R314 fails/tail ----
if fails:
    print('R314 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 10:
    print('R314 splice: FAIL - expected 10 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R314 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R314 note: 10 patches; the deep')
print('crossbow, the aquatic first strike')
print('and the waterborne wanderers charge')
print('the flood pool; the battery census')
print('moves 239 -> 241')
print('commit: R314: the deep crossbow and')
print('the aquatic wanderers (census 241)')

