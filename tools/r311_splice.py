#!/usr/bin/env python3
# tools/r311_splice.py - R311: the underwater
# environment pinned (the first round past the
# closed dmg ledger).
#
# The pin (rules/underwater.h, the grenade.h
# pattern): the DMG UNDERWATER ADVENTURES
# section minus the spell lists (those ride
# R168, rules/uwspells.h) - the surface
# SWIMMING paragraph (metal armor impossible
# except magic armor - the dog paddle only;
# leather and padded at 5 percent drown per
# hour, +2 per 5 pounds beyond the armor;
# winds above 35 mph at 75 percent); the
# MOVEMENT paragraph (swim impossible in armor
# heavier than leather or above 20 pounds of
# equipment, the cap moving 1 pound per 100
# g.p. of strength bonus or penalty; dungeon
# speeds and encumbrance ratios; free action
# at 3x the dungeon rate; the vertical at the
# same rate); the VISION paragraph (50 feet
# fresh, 100 salt, the depth limit the
# distance limit; the optional decay to 0 at
# 60 fresh and 110 salt; the light spell 30
# feet or +10 under 60, whichever greater;
# the helm quintuples both; infravision as
# dungeons; ultravision halved at 100, zero
# below 200; seaweed and grass to 10 feet or
# nil, the shoals total, the mud d6+6
# rounds); the COMBAT paragraph (thrusting
# only; the aquatic first strike; free action
# any weapon with no penalty; nets 1 foot per
# strength point, the races 15, sahuagin 20,
# untrained -4; missiles out except the
# special crossbow at 10x price and half
# range).
#
#   (a) rules/underwater.h - CREATED.
#   (b) regtest.cpp - the include line.
#   (c) regtest.cpp - the R311 battery audit
#       (the battery census 234 -> 235): the
#       constants asserted, the drown, cap,
#       decay, light and ultravision walks,
#       and the print identities.
#   (d) tools/dmg_gap_report.md - the
#       chronicle paragraph (no box flip -
#       the dmg ledger holds ZERO open
#       items).
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
# Commit: "R311: the underwater environment
# pinned (census 235)"
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

# ---- the pin data (single source) ----
# the vision bases: [fresh, salt]
VISION_BASE = [50, 100]
# the optional decay walk: distance at depth
# 10, 20, ... (fresh to 60, salt to 110)
FRESH_DECAY = [50, 40, 30, 20, 10, 0]
SALT_DECAY = [100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0]
# the light spell walk: distance in, vision
# out (the greater of 30 and dist + 10 under
# the 60 threshold)
LIGHT_DIST = [0, 10, 20, 25, 30, 50, 55, 59, 60, 70, 100]
LIGHT_VIS = [30, 30, 30, 35, 40, 60, 65, 69, 60, 70, 100]
# the ultravision walk: depth in, rate out
# (2 full, 1 half, 0 zero)
ULTRA_DEPTH = [0, 50, 99, 100, 150, 200, 201, 300]
ULTRA_RATE = [2, 2, 2, 1, 1, 1, 0, 0]
# the swim cap walk: the strength weight
# allowance in g.p. in, the cap in pounds out
CAP_GP = [0, 100, 250, 999, -50, -100, -250, -999]
CAP_LBS = [20, 21, 22, 29, 20, 19, 18, 11]
# the surface drown walk: pounds of
# possessions beyond the armor in, the drown
# percent per hour out
DROWN_LBS = [0, 4, 5, 14, 15, 25, 50, -5]
DROWN_PCT = [5, 5, 7, 9, 11, 15, 25, 5]

def _ctrunc(a, b):
    # C integer division (truncation toward
    # zero) - the audit_eval mirror
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b >= 0) else -q

def _sanity():
    assert VISION_BASE == [50, 100], 'vision base'
    assert FRESH_DECAY == [50 - 10 * i for i in range(6)], 'fresh decay'
    assert SALT_DECAY == [100 - 10 * i for i in range(11)], 'salt decay'
    assert FRESH_DECAY[0] == VISION_BASE[0], 'fresh decay base'
    assert SALT_DECAY[0] == VISION_BASE[1], 'salt decay base'
    assert FRESH_DECAY[5] == 0 and SALT_DECAY[10] == 0, 'decay floors'
    assert len(LIGHT_DIST) == len(LIGHT_VIS) == 11, 'light walk len'
    for _i in range(11):
        _d = LIGHT_DIST[_i]
        _v = _d + 10 if _d < 60 else _d
        if _v < 30:
            _v = 30
        assert LIGHT_VIS[_i] == _v, 'light walk row'
    assert 59 in LIGHT_DIST and 60 in LIGHT_DIST, 'light threshold edge'
    assert len(ULTRA_DEPTH) == len(ULTRA_RATE) == 8, 'ultra walk len'
    for _i in range(8):
        _d = ULTRA_DEPTH[_i]
        _r = 2 if _d < 100 else (1 if _d <= 200 else 0)
        assert ULTRA_RATE[_i] == _r, 'ultra walk row'
    assert 100 in ULTRA_DEPTH and 201 in ULTRA_DEPTH, 'ultra edges'
    assert len(CAP_GP) == len(CAP_LBS) == 8, 'cap walk len'
    assert CAP_LBS == [20, 21, 22, 29, 20, 19, 18, 11], 'cap walk'
    for _i in range(8):
        assert CAP_LBS[_i] == 20 + _ctrunc(CAP_GP[_i], 100), 'cap row'
    assert len(DROWN_LBS) == len(DROWN_PCT) == 8, 'drown walk len'
    assert DROWN_PCT == [5, 5, 7, 9, 11, 15, 25, 5], 'drown walk'
    for _i in range(8):
        _l = max(0, DROWN_LBS[_i])
        assert DROWN_PCT[_i] == 5 + 2 * (_l // 5), 'drown row'
_sanity()

def arrlines(vals, indent, per=10):
    out = []
    i = 0
    while i < len(vals):
        chunk = vals[i:i + per]
        out.append(indent + ', '.join('%4d' % v for v in chunk) + ',')
        i += per
    return out

def _accs(text):
    # the accessor names, extracted from the text
    # itself (the R309 lesson: never count from
    # the design sketch)
    out = []
    for _ln in text.split(NL):
        _n = None
        if _ln.startswith('inline int uw') and _ln.endswith(' {'):
            _n = _ln[len('inline int '):_ln.rindex('(')]
        if _n is not None:
            out.append(_n)
    return out

def _calls_in(text):
    out = set()
    _rest = text
    while True:
        _i = _rest.find('rules::')
        if _i < 0:
            break
        _rest = _rest[_i + 7:]
        _j = _rest.find('(')
        if _j < 0:
            break
        out.add(_rest[:_j])
    return out

# ---- (a) rules/underwater.h CREATED ----
SB = NL.join(
    ['// ===========================================================================',
     '// Adnd1 - rules/underwater.h',
     '// The underwater environment (R311).',
     '//',
     '// The DMG UNDERWATER ADVENTURES section (upload',
     '// lines 4055-4130) with the surface SWIMMING',
     '// paragraph (upload line 4017): the swim',
     '// terms, the underwater movement, vision and',
     '// combat. The underwater spell use lists and',
     '// the fire and electrical facts ride R168',
     '// (rules/uwspells.h) - this header does not',
     '// re-pin them.',
     '//',
     '// The surface swim: swimming impossible in any',
     '// metal armor except magic armor (the dog',
     '// paddle the only stroke possible); leather',
     '// and padded armor swim at 5 percent drown per',
     '// hour, the chance +2 percent per 5 pounds of',
     '// possessions beyond the armor; winds above',
     '// 35 miles per hour swim at 75 percent drown.',
     '//',
     '// The underwater movement: swimming impossible',
     '// in armor heavier than leather (magic armor',
     '// excepted) or above 20 pounds of equipment -',
     '// the cap moves 1 pound per 100 g.p. of',
     '// strength bonus or penalty (the caller feeds',
     '// the strength weight allowance in g.p.; the',
     '// engine has no allowance accessor); movement',
     '// reads the dungeon speeds with the dungeon',
     '// encumbrance ratios; free action moves at 3x',
     '// the dungeon rate (the wilderness rate);',
     '// swimmers move vertically at the same rate.',
     '//',
     '// The vision: 50 feet fresh water, 100 salt;',
     '// the depth limit the distance limit; the',
     '// optional decay - 10 feet of distance per 10',
     '// feet of depth, fresh 0 at 60, salt 0 at 110;',
     '// the light spell 30 feet regardless of depth',
     '// or +10 feet to any distance under 60,',
     '// whichever greater; the helm of underwater',
     '// action quintuples distance AND depth;',
     '// infravision as in dungeons; ultravision',
     '// halved at 100 feet of depth, zero below 200;',
     '// seaweed and sea grass reduce vision to 10',
     '// feet or nil (the grass 3-30 feet tall);',
     '// shoals totally obstruct; mud clouds block',
     '// vision d6+6 rounds after the movement stops.',
     '//',
     '// The combat: only thrusting weapons (crushing',
     '// and cleaving fail); aquatic creatures always',
     '// strike first unless the human weapon is',
     '// significantly longer; free action allows any',
     '// weapon with no reaction penalty; nets thrown',
     '// 1 foot per strength point (the underwater',
     '// races 15, the sahuagin 20), the untrained at',
     '// -4; missile weapons impossible except the',
     '// special crossbow at 10x price and half the',
     '// dungeon range.',
     '//',
     '// RECORDED NOTES (ride the pin, not data): the',
     '// breathing aids (the water breathing, airy',
     '// water, shape change and wish spells; the',
     '// potion; the helm of underwater action and',
     '// the cloak of the manta ray), the one',
     '// unsheathed dagger carried between the teeth,',
     '// the swimmer vulnerable from every direction,',
     '// the infravision temperature-layer confusion,',
     '// the schools of fish, the mud even light',
     '// cannot penetrate, the stretched, weighted',
     '// and barbed net prose, and the keep-dry rule',
     '// for bows, scrolls and books. No engine site',
     '// charges any of this yet (no underwater game',
     '// layer exists - a state seam is the future',
     '// candidate).',
     '//',
     '// DATA-DRIVEN (the standing scope).',
     '// ===========================================================================',
     '',
     '#pragma once',
     '',
     'namespace rules {',
     '',
     '// ---- the surface swim ----',
     '',
     '// Metal armor: swimming impossible (the flag).',
     'inline int uwSurfaceMetalArmorImpossible() {',
     '    return 1;',
     '}',
     '',
     '// Magic armor excepts the metal ban.',
     'inline int uwSurfaceMagicArmorExcepted() {',
     '    return 1;',
     '}',
     '',
     '// In magic armor the dog paddle is the only',
     '// stroke possible.',
     'inline int uwSurfaceMagicArmorDogPaddleOnly() {',
     '    return 1;',
     '}',
     '',
     '// Leather and padded armor swim.',
     'inline int uwSurfaceLeatherPaddedPossible() {',
     '    return 1;',
     '}',
     '',
     '// The leather-or-padded drown chance per',
     '// hour (percent).',
     'inline int uwSurfaceLeatherDrownPctPerHour() {',
     '    return 5;',
     '}',
     '',
     '// The drown step: pounds per step.',
     'inline int uwSurfaceDrownStepLbs() {',
     '    return 5;',
     '}',
     '',
     '// The drown step: percent per step.',
     'inline int uwSurfaceDrownStepPct() {',
     '    return 2;',
     '}',
     '',
     '// The leather-or-padded drown percent per',
     '// hour with lbs of possessions beyond the',
     '// armor: 5 + 2 per full 5 pounds (the',
     '// negatives clamped to the base).',
     'inline int uwSurfaceDrownPct(int carriedLbs) {',
     '    if (carriedLbs < 0) carriedLbs = 0;',
     '    return 5 + 2 * (carriedLbs / 5);',
     '}',
     '',
     '// Winds above this speed: almost impossible.',
     'inline int uwSurfaceHighWindMph() {',
     '    return 35;',
     '}',
     '',
     '// The high-wind drown chance (percent).',
     'inline int uwSurfaceHighWindDrownPct() {',
     '    return 75;',
     '}',
     '',
     '// ---- the underwater movement ----',
     '',
     '// Swimming impossible in armor heavier than',
     '// leather (the flag).',
     'inline int uwSwimArmorHeavierThanLeatherBlocked() {',
     '    return 1;',
     '}',
     '',
     '// Magic armor excepts the armor ban.',
     'inline int uwSwimMagicArmorExcepted() {',
     '    return 1;',
     '}',
     '',
     '// The equipment cap: 20 pounds of any type.',
     'inline int uwSwimEquipmentCapLbs() {',
     '    return 20;',
     '}',
     '',
     '// The cap moves 1 pound per 100 g.p. of',
     '// strength bonus or penalty.',
     'inline int uwSwimCapAdjLbsPer100gp() {',
     '    return 1;',
     '}',
     '',
     '// The swim encumbrance cap in pounds; the',
     '// caller feeds the strength weight allowance',
     '// adjustment in g.p. (C truncation: each',
     '// full 100 g.p. one pound).',
     'inline int uwSwimEncumbranceCapLbs(int strBonusGp) {',
     '    return 20 + strBonusGp / 100;',
     '}',
     '',
     '// Movement (swimming or walking) reads the',
     '// dungeon speeds with the dungeon encumbrance',
     '// ratios.',
     'inline int uwMoveSameAsDungeon() {',
     '    return 1;',
     '}',
     '',
     '// Free action moves at 3x the dungeon rate',
     '// (the wilderness rate).',
     'inline int uwFreeActionRateMultiple() {',
     '    return 3;',
     '}',
     '',
     '// Swimmers move vertically at the same rate.',
     'inline int uwSwimVerticalSameRate() {',
     '    return 1;',
     '}',
     '',
     '// ---- the underwater vision ----',
     '',
     '// The base distance of vision: fresh 50,',
     '// salt 100 (salt nonzero).',
     'inline int uwVisionBaseFt(int salt) {',
     '    return salt ? 100 : 50;',
     '}',
     '',
     '// The depth limit of vision is the distance',
     '// limit (obscured below the base).',
     'inline int uwVisionDepthLimitSameAsDistance() {',
     '    return 1;',
     '}',
     '',
     '// The optional decay segment: 10 feet of',
     '// depth and 10 feet of distance per step.',
     'inline int uwVisionDecaySegmentFt() {',
     '    return 10;',
     '}',
     '',
     '// The optional decay distance at depth',
     '// (salt nonzero; clamped to the base and to',
     '// zero): fresh 50 at 10 feet to 0 at 60;',
     '// salt 100 at 10 feet to 0 at 110.',
     'inline int uwVisionDecayFt(int salt, int depthFt) {',
     '    int base = salt ? 100 : 50;',
     '    int v = (salt ? 110 : 60) - 10 * (depthFt / 10);',
     '    if (v < 0) v = 0;',
     '    if (v > base) v = base;',
     '    return v;',
     '}',
     '',
     '// The light spell: 30 feet regardless of',
     '// depth.',
     'inline int uwLightSpellMinFt() {',
     '    return 30;',
     '}',
     '',
     '// ...or +10 feet of vision to any distance',
     '// shorter than 60 feet.',
     'inline int uwLightSpellBonusFt() {',
     '    return 10;',
     '}',
     '',
     'inline int uwLightSpellBonusThresholdFt() {',
     '    return 60;',
     '}',
     '',
     '// The light spell vision at distance: the',
     '// greater of 30 feet and dist + 10 when',
     '// dist is under 60.',
     'inline int uwLightSpellVisionFt(int distFt) {',
     '    int v = distFt < 60 ? distFt + 10 : distFt;',
     '    if (v < 30) v = 30;',
     '    return v;',
     '}',
     '',
     '// The helm of underwater action quintuples',
     '// normal vision - distance AND depth.',
     'inline int uwHelmVisionMultiple() {',
     '    return 5;',
     '}',
     '',
     '// Infravision: the dungeon distance limits.',
     'inline int uwInfravisionSameAsDungeon() {',
     '    return 1;',
     '}',
     '',
     '// Ultravision: halved at this depth.',
     'inline int uwUltravisionHalvedAtDepthFt() {',
     '    return 100;',
     '}',
     '',
     '// Ultravision: zero below this depth.',
     'inline int uwUltravisionZeroBelowDepthFt() {',
     '    return 200;',
     '}',
     '',
     '// The ultravision rate at depth: 2 full',
     '// above 100 feet, 1 (half) from 100 to 200,',
     '// 0 below 200.',
     'inline int uwUltravisionRate(int depthFt) {',
     '    return depthFt <= 200 ?',
     '        (depthFt >= 100 ? 1 : 2) : 0;',
     '}',
     '',
     '// Seaweed or sea grass reduces vision to 10',
     '// feet.',
     'inline int uwSeaweedVisionFt() {',
     '    return 10;',
     '}',
     '',
     '// ...or perhaps nil, on the density.',
     'inline int uwSeaweedVisionMayBeNil() {',
     '    return 1;',
     '}',
     '',
     '// The sea grass height band (feet).',
     'inline int uwSeaGrassHeightLoFt() {',
     '    return 3;',
     '}',
     '',
     'inline int uwSeaGrassHeightHiFt() {',
     '    return 30;',
     '}',
     '',
     '// Shoals of either totally obstruct vision.',
     'inline int uwShoalTotallyObstructs() {',
     '    return 1;',
     '}',
     '',
     '// Mud clouds totally block vision while the',
     '// violent movement lasts and d6 + 6 rounds',
     '// after it stops (the 7-12 band).',
     'inline int uwMudCloudRoundsDie() {',
     '    return 6;',
     '}',
     '',
     'inline int uwMudCloudRoundsPlus() {',
     '    return 6;',
     '}',
     '',
     '// ---- the underwater combat ----',
     '',
     '// Only thrusting weapons (crushing and',
     '// cleaving fail).',
     'inline int uwCombatThrustingOnly() {',
     '    return 1;',
     '}',
     '',
     '// Aquatic creatures always strike first',
     '// unless the human weapon is significantly',
     '// longer.',
     'inline int uwAquaticFirstStrike() {',
     '    return 1;',
     '}',
     '',
     '// Free action: any normal weapon.',
     'inline int uwFreeActionAnyWeapon() {',
     '    return 1;',
     '}',
     '',
     '// Free action: no reaction penalty.',
     'inline int uwFreeActionNoReactionPenalty() {',
     '    return 1;',
     '}',
     '',
     '// A net throws 1 foot per strength point.',
     'inline int uwNetThrowFtPerStrPoint() {',
     '    return 1;',
     '}',
     '',
     '// The underwater races throw nets an average',
     '// of 15 feet; the sahuagin 20.',
     'inline int uwNetThrowUnderwaterRaceFt() {',
     '    return 15;',
     '}',
     '',
     'inline int uwNetThrowSahuaginFt() {',
     '    return 20;',
     '}',
     '',
     '// The untrained underwater net: -4 to hit.',
     'inline int uwNetUntrainedPenalty() {',
     '    return 4;',
     '}',
     '',
     '// Missile weapons impossible except the',
     '// specially-made crossbow.',
     'inline int uwMissileExceptCrossbowImpossible() {',
     '    return 1;',
     '}',
     '',
     '// The special crossbow: 10x the normal',
     '// price.',
     'inline int uwSpecialCrossbowPriceMultiple() {',
     '    return 10;',
     '}',
     '',
     '// ...and half the normal (dungeon) range.',
     'inline int uwSpecialCrossbowRangeDivisor() {',
     '    return 2;',
     '}',
     '',
     '}  // namespace rules',
     '',
     ])
clean(SB, 78)
assert Q not in SB, 'apostrophe in header'

p = 'rules/underwater.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'inline int uwSurfaceHighWindMph() {' in s:
        already.append('underwater.h created')
    else:
        fails.append('underwater.h exists without the R311 marker')
else:
    wr(p, SB)
    applied.append('underwater.h created')

s = rd(p)
assert Q not in s, 'sb apostrophes'
assert s.count('namespace rules') == 2, 'sb namespace pair'
assert s.count('}  // namespace rules') == 1, 'sb namespace close'
assert s.count('{') == s.count('}'), 'sb brace balance'
assert s.count('(') == s.count(')'), 'sb paren balance'
_found = _accs(s)
assert len(_found) == 49, 'sb accessor count'
assert len(set(_found)) == 49, 'sb accessor dups'
assert s.count('inline int uw') == 49, 'sb int accessor count'
assert s.count('return 20 + strBonusGp / 100;') == 1, 'sb cap pin'
assert s.count('int v = (salt ? 110 : 60)'
               ' - 10 * (depthFt / 10);') == 1, 'sb decay pin'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) regtest.cpp: the include line ----
INC_OLD = NL.join([
    '#include "rules/sage.h"  // R310: the sage subsection',
])
INC_NEW = NL.join([
    '#include "rules/sage.h"  // R310: the sage subsection',
    '#include "rules/underwater.h"  // R311: the underwater environment',
])
clean(INC_OLD, 76)
clean(INC_NEW, 76)

p = 'regtest.cpp'
s = rd(p)
if '#include "rules/underwater.h"' in s:
    already.append('regtest.cpp: the include line')
else:
    assert s.count(INC_OLD) == 1, 'include anchor not unique'
    assert 'underwater.h' not in s, 'include marker collision'
    assert 'uwVisionBaseFt' not in s, 'include accessor collision'
    s = s.replace(INC_OLD, INC_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the include line')

s = rd(p)
assert s.count('#include "rules/underwater.h"') == 1, 'patch b include'
assert s.count('#include "rules/sage.h"') == 1, 'patch b anchor'
assert s.count('#include "rules/uwspells.h"') == 1, 'patch b r168 intact'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) regtest.cpp: the audit block ----
RT_TAIL = NL.join([
    '        printf("R310 sage subsection audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_AUD = NL.join(
    ['    // ---- R311: the underwater environment audit ----',
     '    // The DMG UNDERWATER ADVENTURES section',
     '    // (rules/underwater.h) walked cell for cell',
     '    // against this local ground truth: the',
     '    // surface swim constants with the drown walk,',
     '    // the movement pins with the cap walk, the',
     '    // vision bases with the fresh and salt decay',
     '    // walks, the light spell and ultravision',
     '    // tables, the seaweed, grass and mud pins,',
     '    // and the combat constants with the print',
     '    // identities.',
     '    {',
     '        int bad = 0;',
     '        static const int kVisionBase[2] = {',
     ] + arrlines(VISION_BASE, '            ', 2) + [
     '        };',
     '        static const int kFreshDecay[6] = {',
     ] + arrlines(FRESH_DECAY, '            ', 6) + [
     '        };',
     '        static const int kSaltDecay[11] = {',
     ] + arrlines(SALT_DECAY, '            ', 6) + [
     '        };',
     '        static const int kLightDist[11] = {',
     ] + arrlines(LIGHT_DIST, '            ', 6) + [
     '        };',
     '        static const int kLightVis[11] = {',
     ] + arrlines(LIGHT_VIS, '            ', 6) + [
     '        };',
     '        static const int kUltraDepth[8] = {',
     ] + arrlines(ULTRA_DEPTH, '            ', 8) + [
     '        };',
     '        static const int kUltraRate[8] = {',
     ] + arrlines(ULTRA_RATE, '            ', 8) + [
     '        };',
     '        static const int kCapGp[8] = {',
     ] + arrlines(CAP_GP, '            ', 8) + [
     '        };',
     '        static const int kCapLbs[8] = {',
     ] + arrlines(CAP_LBS, '            ', 8) + [
     '        };',
     '        static const int kDrownLbs[8] = {',
     ] + arrlines(DROWN_LBS, '            ', 8) + [
     '        };',
     '        static const int kDrownPct[8] = {',
     ] + arrlines(DROWN_PCT, '            ', 8) + [
     '        };',
     '        // the surface swim constants',
     '        if (rules::uwSurfaceMetalArmorImpossible() != 1 ||',
     '            rules::uwSurfaceMagicArmorExcepted() != 1 ||',
     '            rules::uwSurfaceMagicArmorDogPaddleOnly()',
     '                != 1 ||',
     '            rules::uwSurfaceLeatherPaddedPossible()',
     '                != 1 ||',
     '            rules::uwSurfaceLeatherDrownPctPerHour()',
     '                != 5 ||',
     '            rules::uwSurfaceDrownStepLbs() != 5 ||',
     '            rules::uwSurfaceDrownStepPct() != 2 ||',
     '            rules::uwSurfaceHighWindMph() != 35 ||',
     '            rules::uwSurfaceHighWindDrownPct() != 75)',
     '            ++bad;',
     '        // the drown walk: 5 percent plus 2 per',
     '        // full 5 pounds, the negatives clamped',
     '        for (int i = 0; i < 8; ++i)',
     '            if (rules::uwSurfaceDrownPct(kDrownLbs[i]) !=',
     '                kDrownPct[i]) ++bad;',
     '        // the step identity: the first step lands',
     '        // 5 + 2',
     '        if (rules::uwSurfaceDrownPct(',
     '                rules::uwSurfaceDrownStepLbs()) !=',
     '            rules::uwSurfaceLeatherDrownPctPerHour() +',
     '                rules::uwSurfaceDrownStepPct()) ++bad;',
     '        // the movement pins',
     '        if (rules::uwSwimArmorHeavierThanLeatherBlocked()',
     '                != 1 ||',
     '            rules::uwSwimMagicArmorExcepted() != 1 ||',
     '            rules::uwSwimEquipmentCapLbs() != 20 ||',
     '            rules::uwSwimCapAdjLbsPer100gp() != 1 ||',
     '            rules::uwMoveSameAsDungeon() != 1 ||',
     '            rules::uwFreeActionRateMultiple() != 3 ||',
     '            rules::uwSwimVerticalSameRate() != 1) ++bad;',
     '        // the cap walk: 20 pounds plus one per',
     '        // full 100 g.p. of strength adjustment',
     '        // (C truncation, both signs)',
     '        for (int i = 0; i < 8; ++i)',
     '            if (rules::uwSwimEncumbranceCapLbs(kCapGp[i])',
     '                != kCapLbs[i]) ++bad;',
     '        // the cap identity at zero adjustment',
     '        if (rules::uwSwimEncumbranceCapLbs(0) !=',
     '            rules::uwSwimEquipmentCapLbs()) ++bad;',
     '        // the vision bases (0 fresh, 1 salt)',
     '        for (int i = 0; i < 2; ++i)',
     '            if (rules::uwVisionBaseFt(i) !=',
     '                kVisionBase[i]) ++bad;',
     '        if (rules::uwVisionDepthLimitSameAsDistance()',
     '                != 1 ||',
     '            rules::uwVisionDecaySegmentFt() != 10) ++bad;',
     '        // the fresh decay walk (depth 10 to 60)',
     '        for (int i = 0; i < 6; ++i)',
     '            if (rules::uwVisionDecayFt(0, 10 * (i + 1))',
     '                != kFreshDecay[i]) ++bad;',
     '        // the salt decay walk (depth 10 to 110)',
     '        for (int i = 0; i < 11; ++i)',
     '            if (rules::uwVisionDecayFt(1, 10 * (i + 1))',
     '                != kSaltDecay[i]) ++bad;',
     '        // the decay clamps: the shallow depth',
     '        // reads the base; the deep reads zero',
     '        if (rules::uwVisionDecayFt(0, 0) != 50 ||',
     '            rules::uwVisionDecayFt(0, 5) != 50 ||',
     '            rules::uwVisionDecayFt(1, 0) != 100 ||',
     '            rules::uwVisionDecayFt(0, 55) != 10 ||',
     '            rules::uwVisionDecayFt(1, 105) != 10 ||',
     '            rules::uwVisionDecayFt(0, 60) != 0 ||',
     '            rules::uwVisionDecayFt(1, 110) != 0 ||',
     '            rules::uwVisionDecayFt(0, 500) != 0 ||',
     '            rules::uwVisionDecayFt(1, 500) != 0) ++bad;',
     '        // the light spell constants',
     '        if (rules::uwLightSpellMinFt() != 30 ||',
     '            rules::uwLightSpellBonusFt() != 10 ||',
     '            rules::uwLightSpellBonusThresholdFt() != 60)',
     '            ++bad;',
     '        // the light spell walk',
     '        for (int i = 0; i < 11; ++i)',
     '            if (rules::uwLightSpellVisionFt(',
     '                    kLightDist[i]) != kLightVis[i]) ++bad;',
     '        // the light spell identities: the floor',
     '        // and the threshold edge',
     '        if (rules::uwLightSpellVisionFt(0) !=',
     '            rules::uwLightSpellMinFt() ||',
     '            rules::uwLightSpellVisionFt(59) != 69 ||',
     '            rules::uwLightSpellVisionFt(60) != 60 ||',
     '            rules::uwLightSpellVisionFt(-10) != 30) ++bad;',
     '        // the helm quintuples both waters, and',
     '        // the infravision pin',
     '        if (rules::uwHelmVisionMultiple() != 5 ||',
     '            rules::uwVisionBaseFt(0) *',
     '                rules::uwHelmVisionMultiple() != 250 ||',
     '            rules::uwVisionBaseFt(1) *',
     '                rules::uwHelmVisionMultiple() != 500 ||',
     '            rules::uwInfravisionSameAsDungeon() != 1)',
     '            ++bad;',
     '        // the ultravision pins and walk',
     '        if (rules::uwUltravisionHalvedAtDepthFt() != 100',
     '            ||',
     '            rules::uwUltravisionZeroBelowDepthFt()',
     '                != 200) ++bad;',
     '        for (int i = 0; i < 8; ++i)',
     '            if (rules::uwUltravisionRate(kUltraDepth[i])',
     '                != kUltraRate[i]) ++bad;',
     '        // the seaweed, grass and shoal pins',
     '        if (rules::uwSeaweedVisionFt() != 10 ||',
     '            rules::uwSeaweedVisionMayBeNil() != 1 ||',
     '            rules::uwSeaGrassHeightLoFt() != 3 ||',
     '            rules::uwSeaGrassHeightHiFt() != 30 ||',
     '            rules::uwSeaGrassHeightHiFt() -',
     '                rules::uwSeaGrassHeightLoFt() != 27 ||',
     '            rules::uwShoalTotallyObstructs() != 1) ++bad;',
     '        // the mud identity: the 7-12 band',
     '        if (rules::uwMudCloudRoundsPlus() + 1 != 7 ||',
     '            rules::uwMudCloudRoundsDie() +',
     '                rules::uwMudCloudRoundsPlus() != 12) ++bad;',
     '        // the combat constants',
     '        if (rules::uwCombatThrustingOnly() != 1 ||',
     '            rules::uwAquaticFirstStrike() != 1 ||',
     '            rules::uwFreeActionAnyWeapon() != 1 ||',
     '            rules::uwFreeActionNoReactionPenalty() != 1',
     '            ||',
     '            rules::uwMissileExceptCrossbowImpossible()',
     '                != 1) ++bad;',
     '        // the net throw bands and the special',
     '        // crossbow economics',
     '        if (rules::uwNetThrowFtPerStrPoint() != 1 ||',
     '            rules::uwNetThrowUnderwaterRaceFt() != 15 ||',
     '            rules::uwNetThrowSahuaginFt() != 20 ||',
     '            rules::uwNetUntrainedPenalty() != 4 ||',
     '            rules::uwSpecialCrossbowPriceMultiple()',
     '                != 10 ||',
     '            rules::uwSpecialCrossbowRangeDivisor()',
     '                != 2) ++bad;',
     '        printf("R311 underwater environment audit: bad %d'
     + BS + 'n", bad);',
     '        if (bad) return 1;',
     '    }',
     ])
RT_OLD = NL.join([
    RT_TAIL,
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_NEW = NL.join([
    RT_TAIL,
    RT_AUD,
    '    // ---- R227: the wis mental save wiring audit ----',
])
# the audit block carries the printf newline (BS) - the
# R300 check: BS lives ONLY on the printf lines, one
# per line, and nothing else carries a backslash
for _t in (RT_OLD, RT_NEW, RT_AUD):
    for _ln in _t.split(NL):
        assert all(ord(_c) < 128 for _c in _ln), 'non-ascii in audit'
        assert len(_ln) <= 76, 'audit line too long: ' + _ln
        assert Q not in _ln, 'apostrophe in audit'
        if 'printf("' in _ln:
            assert _ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in _ln, 'stray backslash in audit'
_calls = _calls_in(RT_AUD)
assert len(_calls) == 49, 'audit call coverage'
_hx = _accs(rd('rules/underwater.h'))
assert _calls <= set(_hx), 'audit calls unknown accessor'

p = 'regtest.cpp'
s = rd(p)
if 'R311 underwater environment audit' in s:
    already.append('regtest.cpp: the audit block')
else:
    assert s.count('audit: bad') == 234, 'rt census not 234'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    assert 'uwSurfaceDrownPct' not in s, 'rt collision'
    assert 'uwVisionDecayFt' not in s, 'rt collision'
    assert 'uwNetThrowSahuaginFt' not in s, 'rt collision'
    assert 'uwLightSpellVisionFt' not in s, 'rt collision'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit block')

s = rd(p)
assert s.count('audit: bad') == 235, 'patch c census wrong'
assert s.count('R311 underwater environment audit') == 1, 'c label'
assert s.count('R310 sage subsection audit') == 1, 'c r310 tail'
assert s.count('R227: the wis mental save wiring audit') == 1, 'c head'
assert s.count('rules/underwater.h') == 2, 'c references'
assert s.count('{') == s.count('}'), 'rt brace balance'
assert s.count('(') == s.count(')'), 'rt paren balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) tools/dmg_gap_report.md: the chronicle ----
CH_OLD = NL.join([
    '234 with the R310 audit.',
    '',
    'Categories:',
])
CH_NEW = NL.join([
    '234 with the R310 audit.',
    '',
    'R311 the underwater environment pin',
    '(the first round past the closed dmg',
    'ledger): rules/underwater.h (the',
    'grenade.h pattern): the surface',
    'swimming paragraph (metal armor',
    'impossible except magic armor - the',
    'dog paddle only; leather and padded',
    'at 5 percent drown per hour, +2 per 5',
    'pounds beyond the armor; winds above',
    '35 mph at 75 percent); the movement',
    'paragraph (swim impossible in armor',
    'heavier than leather or above 20',
    'pounds of equipment, the cap moving',
    '1 pound per 100 g.p. of strength',
    'bonus or penalty; the dungeon speeds',
    'and encumbrance ratios; free action',
    'at 3x the dungeon rate; the vertical',
    'at the same rate); the vision',
    'paragraph (50 feet fresh, 100 salt,',
    'the depth limit the distance limit;',
    'the decay -10 feet per 10 feet to 0',
    'at 60 fresh and 110 salt; the light',
    'spell 30 feet or +10 under 60,',
    'whichever greater; the helm',
    'quintuples both; infravision as',
    'dungeons; ultravision halved at 100,',
    'zero below 200; seaweed and grass to',
    '10 feet or nil, the shoals total, the',
    'mud d6+6 rounds); the combat',
    'paragraph (thrusting only; the',
    'aquatic first strike; free action any',
    'weapon with no penalty; nets 1 foot',
    'per strength point, the races 15,',
    'sahuagin 20, untrained -4; missiles',
    'out except the special crossbow at',
    '10x price and half range). The spell',
    'lists ride R168 (rules/uwspells.h).',
    'No engine site charges any of this',
    'yet; the battery census moves 234 ->',
    '235 with the R311 audit.',
    '',
    'Categories:',
])
clean(CH_OLD, 57, gap=True)
clean(CH_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R311 the underwater environment pin' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(CH_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(CH_OLD, CH_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R311 the underwater environment pin') == 1, 'd entry'
assert s.count('Categories:') == 1, 'd legend head'
assert s.count('moves 234 ->' + NL +
               '235 with the R311 audit.') == 1, 'd census note'
assert s.count('Census 234') == 1, 'd r310 census intact'
assert s.count('- [ ]') == 1, 'd open residue (the legend only)'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- R311 fails/tail ----
if fails:
    print('R311 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 4:
    print('R311 splice: FAIL - expected 4 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R311 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R311 note: 4 patches; the')
print('underwater environment pinned -')
print('the battery census moves 234 ->')
print('235; the spell lists ride R168')
print('commit: R311: the underwater')
print('environment pinned (census 235)')

