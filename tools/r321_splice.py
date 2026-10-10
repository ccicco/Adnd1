# ============================================================================
# R321 splice: the aerial chapter (census 248)
#
# The OUT reversal (the R172 appendix J precedent).
# The survey verdict:
#   CHARGEABLE - the DMG AERIAL COMBAT section
#   (pp.49-53) table pins: the maneuverability
#   classes A-E (turn degrees per round, the
#   segments/rounds to full airspeed, the hover),
#   the climb/dive/ceiling scalars, the missile
#   -2/-5 penalties, the wing-damage 50/75
#   thresholds. All live engine seams: the MU
#   Fly spell (registered MU_FLY, MU 3, 60
#   rounds, saves not) and the III.A Potion of
#   Flying (dm/treasure.cpp:253; the non-healing
#   potion route MIK_OTHER reaches the claim
#   layer).
#   HONEST KILLS (recorded, not charged) - the
#   hex and written-orders conduct methods and
#   the altitude record: the engine has no
#   position, facing or altitude layer (the R311
#   recorded-notes grain). No aerial fight site
#   exists - the prints ARE the charge (the R320
#   breathing-aids grain).
#
# Patches:
#   (a) doc/vibe/adnd1_knowledge_seed_v2.md -
#       the R320 round-state entry (commit
#       94ca1df, census 247, the guard lessons).
#   (b) rules/aerial.h - NEW FILE: the pp.49-53
#       pins (the OUT reversal header).
#   (c) spelleffects/spelleffects.h -
#       STATUS_FLYING before STATUS_COUNT.
#   (d) spelleffects/spelleffects.cpp - the
#       kStatusNames "Flying" row.
#   (e) spelleffects/spelleffects.cpp - the
#       MU_FLY case to resolveStatusSpell.
#   (f) ai/actor.h - the flyActive getter and
#       the m_flyActive member.
#   (g) ai/actor.cpp - the resolveCast wing
#       fold (the mark and the print).
#   (h) game/party.h - the flyPotion field and
#       the claimFlyPotion helper.
#   (i) game/state_core.cpp - the flypotion
#       save line and the load branch.
#   (j) game/state_dungeon.cpp - the MIK_OTHER
#       fly potion claim route.
#   (k) tools/dmg_gap_report.md - the OUT-list
#       edit (the aerial reversal recorded).
#   (l) tools/dmg_gap_report.md - the R321
#       chronicle paragraph.
#   (m) regtest.cpp - the rules/aerial.h
#       include and the R321 audit (the pins,
#       the status, the wing fold, the dry
#       gate, the claim, the name array -
#       draw-independent: the row saves not,
#       the pins read fixed); the battery
#       census moves 247 -> 248.
#
# The R321 round-state entry rides the R322
# splice (it names this commit).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). Every idempotency guard
# tests the EXACT inserted text (the R320
# lesson - never a cousin phrase). ZERO
# literal backslash bytes in this file - the
# printf and fprintf continuations are built
# via chr(92); no CONTENT string embeds an
# apostrophe, non-ASCII, or a line past its
# bound (78 the header and the C++ patches, 76
# regtest, 72 the seed, 57 the gap report).
# Commit: "R321: the aerial chapter
# (census 248)"
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

def cleanNB(s, limit):
    # the anchors and inserts that carry a
    # built backslash byte (the printf and
    # fprintf continuations) - the length and
    # ascii checks without the byte ban
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

def counts(s):
    return (s.count('{'), s.count('}'),
            s.count('('), s.count(')'))

# ---- (a) the seed: the R320 round-state entry ----
SEED = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SD_ANCH = NL.join([
    '## Knowledge maintenance',
])
SD_ADD = NL.join([
    '- R320 landed 2026-10-10: commit',
    '  94ca1df, census 247, the breathing',
    '  aids (the druid spell and the potion',
    '  claim). GREEN on the first paste.',
    '  Lessons: (1) an idempotency guard',
    '  must test the exact inserted text -',
    '  two R320 guards matched text that',
    '  never exists in the patched source',
    '  (a row with a trailing comma vs the',
    '  bare row; a contiguous phrase vs',
    '  the split string literal), both',
    '  caught by the sandbox double-run',
    '  before delivery; (2) a source scan',
    '  must match the literal split - the',
    '  print rode two string literals, so',
    '  the check scans the shared half;',
    '  (3) a pointer compare against a',
    '  string literal warns (-Wstring-',
    '  compare) - the later audits compare',
    '  through std::string.',
])
clean(SD_ANCH, 72)
clean(SD_ADD, 72)

s = rd(SEED)
if 'R320 landed' in s:
    already.append('the seed: the R320 entry')
else:
    assert s.count(SD_ANCH) == 1, 'seed anchor not unique'
    s = s.replace(SD_ANCH, SD_ADD + NL + NL + SD_ANCH, 1)
    wr(SEED, s)
    applied.append('the seed: the R320 entry')

s = rd(SEED)
assert s.count('R320 landed') == 1, 'a entry'
assert s.count('R319 landed') == 1, 'a r319 intact'
assert s.count(
    'Knowledge maintenance') == 1, 'a doc intact'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) rules/aerial.h: the pp.49-53 pins ----
AR_HEAD = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/aerial.h',
    '// The aerial environment (R321).',
    '//',
    '// The DMG AERIAL COMBAT section (pp.49-53)',
    '// - the OUT reversal (the R172 appendix J',
    '// precedent): the pins charge here, the',
    '// fly seams charge the engine (the spell',
    '// status and the potion claim), and the',
    '// hex and written-orders methods stay OUT',
    '// - the engine has no position, facing or',
    '// altitude layer (the R311 recorded-notes',
    '// grain); an airborne fight resolves on',
    '// the flat geometry.',
    '//',
    '// The flight facts: every flyer climbs at',
    '// one half and dives at twice the stated',
    '// movement rate; a climb gains 1 foot per',
    '// 3 feet forward, a dive 1 foot per foot',
    '// (the 45 degree angle); class A is',
    '// outside the climb and dive rules (any',
    '// direction). A diving attack doubles the',
    '// physical damage against any target not',
    '// itself diving, including earthbound',
    '// targets attacked from 30 feet up or',
    '// more. No flyer climbs above 5000 feet.',
    '',
    '#pragma once',
    '',
])
AR_FUNCS = NL.join([
    'inline int aerialClimbRateDivisor() { return 2; }',
    'inline int aerialDiveRateMultiple() { return 2; }',
    'inline int aerialClimbFeetPerFootUp() { return 3; }',
    'inline int aerialDiveFeetPerFootDown()',
    '    { return 1; }',
    'inline int aerialDiveEarthboundHeightFt()',
    '    { return 30; }',
    'inline int aerialCeilingFeet() { return 5000; }',
    '',
    '// The maneuverability: five classes, A the',
    '// best through E the worst. The turn per',
    '// round assumes full speed - a flyer at',
    '// half speed turns as one class better;',
    '// winged flyers cannot move below half',
    '// speed and stay aloft (class B excepted).',
    '// The time to full airspeed reads segments',
    '// for A and B, rounds for C, D and E; only',
    '// A and B hover. The examples: the fly',
    '// spell class B; the carpet and the wings',
    '// of flying class C (the misc magic pins);',
    '// dragons, rocs and wyverns class E.',
    'inline int aerialTurnDegreesPerRound(int cls) {',
    '    // A 180, B 120, C 90, D 60, E 30',
    '    return cls == 1 ? 180 : cls == 2 ? 120 :',
    '           cls == 3 ? 90 : cls == 4 ? 60 :',
    '           cls == 5 ? 30 : 0;',
    '}',
    'inline int aerialSegmentsToFullSpeed(int cls) {',
    '    // A 1 segment, B 6; the C, D and E rows',
    '    // read rounds (the unit grain)',
    '    return cls == 1 ? 1 : cls == 2 ? 6 : -1;',
    '}',
    'inline int aerialRoundsToFullSpeed(int cls) {',
    '    // C 1, D 2, E 4 rounds; the A and B rows',
    '    // read segments (the unit grain)',
    '    return cls == 3 ? 1 : cls == 4 ? 2 :',
    '           cls == 5 ? 4 : -1;',
    '}',
    'inline bool aerialHover(int cls) {',
    '    // only A and B hold their place',
    '    return cls == 1 || cls == 2;',
    '}',
    'inline int aerialFlySpellManeuverClass() {',
    '    // the fly spell is a class B flyer',
    '    return 2;',
    '}',
    '',
    '// The missile fire: a moving flyer treats',
    '// short range as medium (-2 to hit) and',
    '// medium as long (-5); long range always',
    '// misses. A hovering flyer - the fly spell',
    '// or the carpet - takes no penalty. A',
    '// flying dragon and its kin add +2 to the',
    '// saves of their flying breath targets.',
    'inline int aerialMissileShortPenalty()',
    '    { return -2; }',
    'inline int aerialMissileMediumPenalty()',
    '    { return -5; }',
    'inline int aerialDragonBreathSaveBonus()',
    '    { return 2; }',
    '',
    '// The wing damage: a winged flyer past',
    '// half its hit points in damage must land;',
    '// past three quarters it plummets.',
    '// Feathered wings add half the creature',
    '// hit points to the flight-damage total (a',
    '// 30 hit point griffon lands at 23 damage;',
    '// a 30 hit point membrane wing falls at',
    '// 15) - the extra points never absorb',
    '// real damage.',
    'inline int aerialWingDamageLandPct()',
    '    { return 50; }',
    'inline int aerialWingDamagePlummetPct()',
    '    { return 75; }',
    'inline int aerialFeatheredWingBonusPct()',
    '    { return 50; }',
])
AR_FILE = (AR_HEAD + 'namespace rules {' + NL + NL +
           AR_FUNCS + NL + '}' + NL)
clean(AR_FILE, 78)

p = 'rules/aerial.h'
if os.path.exists(os.path.join(ROOT, p)):
    already.append('aerial.h: the pp.49-53 pins')
else:
    wr(p, AR_FILE)
    applied.append('aerial.h: the pp.49-53 pins')

s = rd(p)
assert s.count('aerialTurnDegreesPerRound') == 1, 'b turn pin'
assert s.count('namespace rules') == 1, 'b namespace'
assert s.count('#pragma once') == 1, 'b guard'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) spelleffects.h: the fly kind ----
SE_OLD = NL.join([
    '    STATUS_WATERBREATHING,   // R320: the druid spell mark',
    '                             // (the breath fold)',
    '    STATUS_COUNT',
])
SE_NEW = NL.join([
    '    STATUS_WATERBREATHING,   // R320: the druid spell mark',
    '                             // (the breath fold)',
    '    STATUS_FLYING,       // R321: the fly spell mark',
    '                        // (the wing fold)',
    '    STATUS_COUNT',
])
clean(SE_OLD, 78)
clean(SE_NEW, 78)

p = 'spelleffects/spelleffects.h'
s = rd(p)
if 'STATUS_FLYING,' in s:
    already.append('spelleffects.h: the fly kind')
else:
    assert s.count(SE_OLD) == 1, 'enum anchor not unique'
    s = s.replace(SE_OLD, SE_NEW, 1)
    wr(p, s)
    applied.append('spelleffects.h: the fly kind')

s = rd(p)
assert s.count('STATUS_FLYING,') == 1, 'c kind'
assert s.count('STATUS_WATERBREATHING,') == 1, 'c breath intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) spelleffects.cpp: the name row ----
SN_OLD = NL.join([
    '    ' + DQ + 'Lit' + DQ + ',',
    '    ' + DQ + 'Breathing' + DQ,
    '};',
])
SN_NEW = NL.join([
    '    ' + DQ + 'Lit' + DQ + ',',
    '    ' + DQ + 'Breathing' + DQ + ',',
    '    ' + DQ + 'Flying' + DQ,
    '};',
])
clean(SN_OLD, 78)
clean(SN_NEW, 78)

p = 'spelleffects/spelleffects.cpp'
s = rd(p)
if s.count(SN_NEW) == 1:
    already.append('spelleffects.cpp: the name row')
else:
    assert s.count(SN_OLD) == 1, 'name anchor not unique'
    s = s.replace(SN_OLD, SN_NEW, 1)
    wr(p, s)
    applied.append('spelleffects.cpp: the name row')

s = rd(p)
assert s.count(DQ + 'Flying' + DQ) == 1, 'd name'
assert s.count(DQ + 'Breathing' + DQ + ',') == 1, 'd breath intact'
assert s.count('kStatusNames') == 2, 'd array intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) spelleffects.cpp: the fly case ----
CS_OLD = NL.join([
    '            case spells::DR_WATER_BREATHING:   // R320',
    '                r = resolveStatusSpell(',
    '                    dice, s, STATUS_WATERBREATHING,',
    '                    s.durationRounds, t, false);',
    '                break;',
    '            case spells::MU_CHARM_PERSON:',
])
CS_NEW = NL.join([
    '            case spells::DR_WATER_BREATHING:   // R320',
    '                r = resolveStatusSpell(',
    '                    dice, s, STATUS_WATERBREATHING,',
    '                    s.durationRounds, t, false);',
    '                break;',
    '            // R321: the MU fly - the status',
    '            // mark (the row saves not, 60',
    '            // rounds); the wing fold rides',
    '            // resolveCast. The levitate and',
    '            // the flight items stay pins (the',
    '            // aerial.h scalars).',
    '            case spells::MU_FLY:   // R321',
    '                r = resolveStatusSpell(',
    '                    dice, s, STATUS_FLYING,',
    '                    s.durationRounds, t, false);',
    '                break;',
    '            case spells::MU_CHARM_PERSON:',
])
clean(CS_OLD, 78)
clean(CS_NEW, 78)

p = 'spelleffects/spelleffects.cpp'
s = rd(p)
if s.count('case spells::MU_FLY:') == 1:
    already.append('spelleffects.cpp: the fly case')
else:
    assert s.count(CS_OLD) == 1, 'case anchor not unique'
    s = s.replace(CS_OLD, CS_NEW, 1)
    wr(p, s)
    applied.append('spelleffects.cpp: the fly case')

s = rd(p)
assert s.count('case spells::MU_FLY:') == 1, 'e case'
assert s.count('STATUS_FLYING,') == 1, 'e kind ref'
assert s.count(
    'case spells::DR_WATER_BREATHING:') == 1, 'e breath intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch e balance'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) actor.h: the fly seam ----
HF_OLD = NL.join([
    '    bool breathActive() const { return m_breathActive; }',
])
HF_NEW = NL.join([
    '    bool breathActive() const { return m_breathActive; }',
    '    // R321: the company wings - a party fly',
    '    // spell marks the company (the',
    '    // resolveCast wing fold; no aerial',
    '    // fight site exists - the print is the',
    '    // charge).',
    '    bool flyActive() const { return m_flyActive; }',
])
HM_OLD = NL.join([
    '    bool m_breathActive = false;   // R320: the breath',
])
HM_NEW = NL.join([
    '    bool m_breathActive = false;   // R320: the breath',
    '    bool m_flyActive = false;   // R321: the fly spell',
])
clean(HF_OLD, 78)
clean(HF_NEW, 78)
clean(HM_OLD, 78)
clean(HM_NEW, 78)

p = 'ai/actor.h'
s = rd(p)
if 'flyActive() const' in s:
    already.append('actor.h: the fly seam')
else:
    assert s.count(HF_OLD) == 1, 'getter anchor not unique'
    assert s.count(HM_OLD) == 1, 'member anchor not unique'
    s = s.replace(HF_OLD, HF_NEW, 1)
    s = s.replace(HM_OLD, HM_NEW, 1)
    wr(p, s)
    applied.append('actor.h: the fly seam')

s = rd(p)
assert s.count('flyActive() const') == 1, 'f getter'
assert s.count('m_flyActive = false;') == 1, 'f member'
assert s.count('m_flyActive;') == 1, 'f ref'
assert s.count('breathActive() const') == 1, 'f breath intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch f balance'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) actor.cpp: the resolveCast wing fold ----
RC_OLD = NL.join([
    '        m_breathActive = true;',
    '        logLine(' + DQ + 'The company breathes water' + DQ,
    '                ' + DQ + ' freely!' + DQ + ');',
    '    }',
    '}',
])
RC_NEW = NL.join([
    '        m_breathActive = true;',
    '        logLine(' + DQ + 'The company breathes water' + DQ,
    '                ' + DQ + ' freely!' + DQ + ');',
    '    }',
    '',
    '    // R321: the wing fold - the MU fly',
    '    // spell marks the company (the DMG',
    '    // aerial chapter OUT reversal; no',
    '    // aerial fight site exists - the',
    '    // print IS the charge, the R320',
    '    // breath pattern).',
    '    if (id == spells::MU_FLY &&',
    '        caster.team == 0 && !m_flyActive) {',
    '        m_flyActive = true;',
    '        logLine(' + DQ + 'The company takes wing!' + DQ +
    ');',
    '    }',
    '}',
])
cleanNB(RC_OLD, 78)
cleanNB(RC_NEW, 78)

p = 'ai/actor.cpp'
s = rd(p)
if s.count(DQ + 'The company takes wing!' + DQ) == 1:
    already.append('actor.cpp: the wing fold')
else:
    assert s.count(RC_OLD) == 1, 'fold anchor not unique'
    s = s.replace(RC_OLD, RC_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the wing fold')

s = rd(p)
assert s.count('The company takes wing!') == 1, 'g print'
assert s.count('m_flyActive = true;') == 1, 'g mark'
assert s.count('breathes water') == 1, 'g breath intact'
assert s.count('MU_FLY &&') == 1, 'g gate'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch g balance'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- (h) party.h: the fly potion field and claim ----
HF2_OLD = NL.join([
    '    // R320: the Potion of Water Breathing held',
    '    // (the claim layer; the pool fight print)',
    '    bool uwDraught = false;',
])
HF2_NEW = NL.join([
    '    // R320: the Potion of Water Breathing held',
    '    // (the claim layer; the pool fight print)',
    '    bool uwDraught = false;',
    '    // R321: the Potion of Flying held',
    '    // (the claim layer; the wing fold',
    '    // rides resolveCast)',
    '    bool flyPotion = false;',
])
CH_OLD = NL.join([
    '    c.uwDraught = true;',
    '    return true;',
    '}',
])
CH_NEW = NL.join([
    '    c.uwDraught = true;',
    '    return true;',
    '}',
    '',
    '// R321: the Potion of Flying - one dose',
    '// held by one member (the claimUwDraught',
    '// pattern)',
    'inline bool claimFlyPotion(Character& c,',
    '                           const std::string& name,',
    '                           int qty) {',
    '    if (c.hp <= 0 || qty != 1 || c.flyPotion)',
    '        return false;',
    '    if (name.find(' + DQ + 'Potion of Flying' + DQ + ') ==',
    '        std::string::npos)',
    '        return false;',
    '    c.flyPotion = true;',
    '    return true;',
    '}',
])
clean(HF2_OLD, 78)
clean(HF2_NEW, 78)
cleanNB(CH_OLD, 78)
cleanNB(CH_NEW, 78)

p = 'game/party.h'
s = rd(p)
if 'claimFlyPotion' in s:
    already.append('party.h: the fly potion field and claim')
else:
    assert s.count(HF2_OLD) == 1, 'field anchor not unique'
    assert s.count(CH_OLD) == 1, 'claim anchor not unique'
    s = s.replace(HF2_OLD, HF2_NEW, 1)
    s = s.replace(CH_OLD, CH_NEW, 1)
    wr(p, s)
    applied.append('party.h: the fly potion field and claim')

s = rd(p)
assert s.count('bool flyPotion = false;') == 1, 'h field'
assert s.count('claimFlyPotion') == 1, 'h helper'
assert s.count(DQ + 'Potion of Flying' + DQ) == 1, 'h name gate'
assert s.count('inline bool claimUwDraught') == 1, 'h draught intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch h balance'
assert len(applied) + len(already) == 8, 'patch h count wrong'

# ---- (i) state_core.cpp: the save and load ----
BSN = BS + 'n'
SV_OLD = NL.join([
    '            // R320: the draught (held only - v1',
    '            // saves carry no line and load',
    '            // without it)',
    '            if (c.uwDraught)',
    '                fprintf(f, ' + DQ + 'uwdraught 1' + BSN +
    DQ + ');',
])
SV_NEW = NL.join([
    '            // R320: the draught (held only - v1',
    '            // saves carry no line and load',
    '            // without it)',
    '            if (c.uwDraught)',
    '                fprintf(f, ' + DQ + 'uwdraught 1' + BSN +
    DQ + ');',
    '            // R321: the fly potion (held only',
    '            // - v1 saves carry no line and load',
    '            // without it)',
    '            if (c.flyPotion)',
    '                fprintf(f, ' + DQ + 'flypotion 1' + BSN +
    DQ + ');',
])
LD_OLD = NL.join([
    '                    c.uwDraught = ud != 0;',
    '                } else if (strcmp(tag, ' + DQ +
    'shieldplus' + DQ + ') == 0) {',
])
LD_NEW = NL.join([
    '                    c.uwDraught = ud != 0;',
    '                } else if (strcmp(tag, ' + DQ +
    'flypotion' + DQ + ') == 0) {',
    '                    int fp = 0;',
    '                    if (fscanf(f, ' + DQ + '%d' + DQ +
    ', &fp) != 1 ||',
    '                        fp < 0 || fp > 1) {',
    '                        fclose(f);',
    '                        log.add(' + DQ +
    'adnd1.sav is corrupt (flypotion).' + DQ + ');',
    '                        return false;',
    '                    }',
    '                    c.flyPotion = fp != 0;',
    '                } else if (strcmp(tag, ' + DQ +
    'shieldplus' + DQ + ') == 0) {',
])
cleanNB(SV_OLD, 78)
cleanNB(SV_NEW, 78)
clean(LD_OLD, 78)
cleanNB(LD_NEW, 78)

p = 'game/state_core.cpp'
s = rd(p)
if 'flypotion' in s:
    already.append('state_core.cpp: the save and load')
else:
    assert s.count(SV_OLD) == 1, 'save anchor not unique'
    assert s.count(LD_OLD) == 1, 'load anchor not unique'
    s = s.replace(SV_OLD, SV_NEW, 1)
    s = s.replace(LD_OLD, LD_NEW, 1)
    wr(p, s)
    applied.append('state_core.cpp: the save and load')

s = rd(p)
assert s.count('flypotion') == 3, 'i save and load'
assert s.count('c.flyPotion = fp != 0;') == 1, 'i load set'
assert s.count('uwdraught 1') == 1, 'i draught intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch i balance'
assert len(applied) + len(already) == 9, 'patch i count wrong'

# ---- (j) state_dungeon.cpp: the claim route ----
CR_OLD = NL.join([
    '                        for (auto& c : party.members) {',
    '                            if (c.hp <= 0) continue;',
    '                            // R320: the Potion of Water',
])
CR_NEW = NL.join([
    '                        for (auto& c : party.members) {',
    '                            if (c.hp <= 0) continue;',
    '                            // R321: the Potion of Flying',
    '                            // - the carried dose (the',
    '                            // claimUwDraught pattern);',
    '                            // the wing fold charges the',
    '                            // spell side',
    '                            if (claimFlyPotion(c, mi.name,',
    '                                              mi.qty)) {',
    '                                snprintf(buf, sizeof buf,',
    '                                         ' + DQ + '%s pockets the %s!' + DQ + ',',
    '                                         c.name.c_str(),',
    '                                         mi.name.c_str());',
    '                                log.add(buf);',
    '                                take = true;',
    '                                break;',
    '                            }',
    '                            // R320: the Potion of Water',
])
cleanNB(CR_OLD, 78)
cleanNB(CR_NEW, 78)

p = 'game/state_dungeon.cpp'
s = rd(p)
if 'claimFlyPotion(c, mi.name,' in s:
    already.append('state_dungeon.cpp: the claim route')
else:
    assert s.count(CR_OLD) == 1, 'route anchor not unique'
    s = s.replace(CR_OLD, CR_NEW, 1)
    wr(p, s)
    applied.append('state_dungeon.cpp: the claim route')

s = rd(p)
assert s.count('claimFlyPotion(c, mi.name,') == 1, 'j route'
assert s.count('claimUwDraught(c, mi.name,') == 1, 'j draught intact'
assert s.count('pockets the') == 3, 'j prints'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch j balance'
assert len(applied) + len(already) == 10, 'patch j count wrong'

# ---- (k) dmg_gap_report.md: the OUT-list edit ----
GP = 'tools/dmg_gap_report.md'
GO_OLD = NL.join([
    '- OUT: Aerial and naval combat systems, siege',
    '  and war-machine rules, stronghold domain',
])
GO_NEW = NL.join([
    '- OUT: naval combat systems, siege and',
    '  war-machine rules (the aerial chapter',
    '  reversed R321 - the rules/aerial.h pins',
    '  and the fly seams; the hex and',
    '  written-orders methods stay OUT - no',
    '  position or altitude layer), stronghold',
    '  domain',
])
clean(GO_OLD, 57, gap=True)
clean(GO_NEW, 57, gap=True)

s = rd(GP)
if 'reversed R321' in s:
    already.append('dmg report: the OUT-list edit')
else:
    assert s.count(GO_OLD) == 1, 'OUT anchor not unique'
    s = s.replace(GO_OLD, GO_NEW, 1)
    wr(GP, s)
    applied.append('dmg report: the OUT-list edit')

s = rd(GP)
assert s.count('reversed R321') == 1, 'k reversal'
assert s.count('Aerial and naval combat') == 0, 'k old gone'
assert s.count('war-machine rules') == 1, 'k siege intact'
assert len(applied) + len(already) == 11, 'patch k count wrong'

# ---- (l) dmg_gap_report.md: the chronicle ----
GC_OLD = NL.join([
    'census moves 246 -> 247 with the',
    'R320 audit.',
    '',
    'Categories:',
])
GC_NEW = NL.join([
    'census moves 246 -> 247 with the',
    'R320 audit.',
    '',
    'R321 the aerial chapter: the OUT',
    'reversal (the R172 appendix J',
    'precedent) - the DMG pp.49-53 pins',
    '(rules/aerial.h: the maneuver classes',
    'A-E with the turn degrees, the',
    'full-speed times and the hover; the',
    'climb-dive-ceiling, missile and',
    'wing-damage scalars) and the fly',
    'seams (the STATUS_FLYING mark, the',
    'resolveCast wing fold - the R320',
    'breath pattern; the Potion of Flying',
    'claim layer with the save line; no',
    'aerial fight site exists - the',
    'prints are the charge). The hex and',
    'written-orders methods stay OUT (no',
    'position or altitude layer). The',
    'census moves 247 -> 248 with the',
    'R321 audit.',
    '',
    'Categories:',
])
clean(GC_OLD, 57, gap=True)
clean(GC_NEW, 57, gap=True)

s = rd(GP)
if 'R321 the aerial chapter' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(GC_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(GC_OLD, GC_NEW, 1)
    wr(GP, s)
    applied.append('dmg report: the chronicle')

s = rd(GP)
assert s.count('R321 the aerial chapter') == 1, 'l entry'
assert s.count('Categories:') == 1, 'l legend head'
assert s.count('moves 247 -> 248') == 1, 'l census'
assert s.count('moves 246 -> 247') == 1, 'l r320 intact'
assert len(applied) + len(already) == 12, 'patch l count wrong'

# ---- (m) regtest.cpp: the include and the R321 audit ----
IN_OLD = NL.join([
    '#include ' + DQ + 'rules/uwspells.h' + DQ +
    '  // R168: p.57 underwater spell use',
])
IN_NEW = NL.join([
    '#include ' + DQ + 'rules/uwspells.h' + DQ +
    '  // R168: p.57 underwater spell use',
    '#include ' + DQ + 'rules/aerial.h' + DQ +
    '  // R321: pp.49-53 aerial combat',
])
RT_OLD = NL.join([
    '        printf(' + DQ +
    'R320 breathing aids audit: bad %d' + BSN + DQ +
    ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_NEW = NL.join([
    '        printf(' + DQ +
    'R320 breathing aids audit: bad %d' + BSN + DQ +
    ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R321: the aerial chapter audit ----',
    '    // The OUT reversal (the R172 appendix',
    '    // J precedent): the DMG pp.49-53 pins',
    '    // (rules/aerial.h) and the fly seams -',
    '    // the STATUS_FLYING mark, the wing',
    '    // fold, the potion claim. No aerial',
    '    // fight site exists - the prints are',
    '    // the charge. Draw-independent: the',
    '    // row saves not, the pins read fixed.',
    '    {',
    '        int bad = 0;',
    '        // A1: the maneuver table - the turn',
    '        // degrees, the full-speed times,',
    '        // the hover, the fly spell class',
    '        {',
    '            if (rules::aerialTurnDegreesPerRound(1)',
    '                != 180) ++bad;',
    '            if (rules::aerialTurnDegreesPerRound(2)',
    '                != 120) ++bad;',
    '            if (rules::aerialTurnDegreesPerRound(3)',
    '                != 90) ++bad;',
    '            if (rules::aerialTurnDegreesPerRound(4)',
    '                != 60) ++bad;',
    '            if (rules::aerialTurnDegreesPerRound(5)',
    '                != 30) ++bad;',
    '            if (rules::aerialTurnDegreesPerRound(0)',
    '                != 0) ++bad;',
    '            if (rules::aerialSegmentsToFullSpeed(1)',
    '                != 1) ++bad;',
    '            if (rules::aerialSegmentsToFullSpeed(2)',
    '                != 6) ++bad;',
    '            if (rules::aerialSegmentsToFullSpeed(3)',
    '                != -1) ++bad;',
    '            if (rules::aerialRoundsToFullSpeed(3)',
    '                != 1) ++bad;',
    '            if (rules::aerialRoundsToFullSpeed(4)',
    '                != 2) ++bad;',
    '            if (rules::aerialRoundsToFullSpeed(5)',
    '                != 4) ++bad;',
    '            if (rules::aerialRoundsToFullSpeed(1)',
    '                != -1) ++bad;',
    '            if (!rules::aerialHover(1)) ++bad;',
    '            if (!rules::aerialHover(2)) ++bad;',
    '            if (rules::aerialHover(3)) ++bad;',
    '            if (rules::aerialHover(5)) ++bad;',
    '            if (rules::aerialFlySpellManeuverClass()',
    '                != 2) ++bad;',
    '        }',
    '        // A2: the flight, missile and wing',
    '        // scalars',
    '        {',
    '            if (rules::aerialClimbRateDivisor()',
    '                != 2) ++bad;',
    '            if (rules::aerialDiveRateMultiple()',
    '                != 2) ++bad;',
    '            if (rules::aerialClimbFeetPerFootUp()',
    '                != 3) ++bad;',
    '            if (rules::aerialDiveFeetPerFootDown()',
    '                != 1) ++bad;',
    '            if (rules::aerialDiveEarthboundHeightFt()',
    '                != 30) ++bad;',
    '            if (rules::aerialCeilingFeet()',
    '                != 5000) ++bad;',
    '            if (rules::aerialMissileShortPenalty()',
    '                != -2) ++bad;',
    '            if (rules::aerialMissileMediumPenalty()',
    '                != -5) ++bad;',
    '            if (rules::aerialDragonBreathSaveBonus()',
    '                != 2) ++bad;',
    '            if (rules::aerialWingDamageLandPct()',
    '                != 50) ++bad;',
    '            if (rules::aerialWingDamagePlummetPct()',
    '                != 75) ++bad;',
    '            if (rules::aerialFeatheredWingBonusPct()',
    '                != 50) ++bad;',
    '        }',
    '        // A3: the status - the spell engine',
    '        // level (no save on the row)',
    '        {',
    '            rules::Rng r(11);',
    '            rules::Dice d(r);',
    '            ai::Actor t;',
    '            t.team = 1; t.hitDice = 1;',
    '            t.hp = 6; t.maxHp = 6;',
    '            std::vector<spelleffects::TargetDesc>',
    '                ds;',
    '            ds.push_back(t.asTarget());',
    '            spelleffects::SpellCastResult r1 =',
    '                spelleffects::resolveSpell(',
    '                    d, spells::MU_FLY, 5, ds);',
    '            if (r1.perTarget.size() != 1) ++bad;',
    '            if (!r1.perTarget.empty() &&',
    '                r1.perTarget[0].status.kind !=',
    '                    spelleffects::STATUS_FLYING)',
    '                ++bad;',
    '        }',
    '        // A4: the wing fold - a party fly',
    '        // cast marks the company',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.team = 0;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.classIndex = 1; a.level = 5;',
    '            a.slotsByLevel[2] = 1;',
    '            a.hp = 30; a.maxHp = 30;',
    '            pt.push_back(a);',
    '            std::vector<ai::Actor> mons;',
    '            ai::Actor m;',
    '            m.team = 1; m.hitDice = 1;',
    '            m.name = ' + DQ + 'Monst' + DQ + ';',
    '            m.hp = 6; m.maxHp = 6;',
    '            mons.push_back(m);',
    '            ai::Encounter enc(pt, mons, 20);',
    '            enc.resolveCast(',
    '                enc.partyMutable()[0],',
    '                spells::MU_FLY);',
    '            if (!enc.flyActive()) ++bad;',
    '            bool wg = false;',
    '            for (const auto& ln : enc.log())',
    '                if (ln.text.find(' + DQ +
    'takes wing' + DQ + ') !=',
    '                    std::string::npos)',
    '                    wg = true;',
    '            if (!wg) ++bad;',
    '            // the slot spent',
    '            if (enc.partyMutable()[0]',
    '                    .slotsByLevel[2] != 0) ++bad;',
    '        }',
    '        // A5: the dry gate - a non-fly',
    '        // cast never marks',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.team = 0;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.classIndex = 1; a.level = 5;',
    '            a.slotsByLevel[0] = 1;',
    '            a.hp = 30; a.maxHp = 30;',
    '            pt.push_back(a);',
    '            std::vector<ai::Actor> mons;',
    '            ai::Actor m;',
    '            m.team = 1; m.hitDice = 1;',
    '            m.name = ' + DQ + 'Monst' + DQ + ';',
    '            m.hp = 6; m.maxHp = 6;',
    '            mons.push_back(m);',
    '            ai::Encounter enc(pt, mons, 20);',
    '            enc.resolveCast(',
    '                enc.partyMutable()[0],',
    '                spells::MU_LIGHT);',
    '            if (enc.flyActive()) ++bad;',
    '            bool wg = false;',
    '            for (const auto& ln : enc.log())',
    '                if (ln.text.find(' + DQ +
    'takes wing' + DQ + ') !=',
    '                    std::string::npos)',
    '                    wg = true;',
    '            if (wg) ++bad;',
    '        }',
    '        // A6: the claim (the claimUwDraught',
    '        // pattern)',
    '        {',
    '            Character c;',
    '            c.hp = 10;',
    '            if (!claimFlyPotion(',
    '                    c, ' + DQ + 'Potion of Flying' + DQ + ',',
    '                    1)) ++bad;',
    '            if (!c.flyPotion) ++bad;',
    '            // one dose per member',
    '            if (claimFlyPotion(',
    '                    c, ' + DQ + 'Potion of Flying' + DQ + ',',
    '                    1)) ++bad;',
    '            c.flyPotion = false;',
    '            // other potions never claim',
    '            if (claimFlyPotion(',
    '                    c, ' + DQ + 'Potion of Healing' + DQ + ',',
    '                    1)) ++bad;',
    '            // bundles never claim',
    '            if (claimFlyPotion(',
    '                    c, ' + DQ + 'Potion of Flying' + DQ + ',',
    '                    2)) ++bad;',
    '            // the dead claim nothing',
    '            c.hp = 0;',
    '            if (claimFlyPotion(',
    '                    c, ' + DQ + 'Potion of Flying' + DQ + ',',
    '                    1)) ++bad;',
    '        }',
    '        // A7: the name array - every kind',
    '        // names (the std::string compare -',
    '        // the R320 pointer-compare warning)',
    '        {',
    '            for (int k = 0;',
    '                 k < (int)spelleffects::STATUS_COUNT;',
    '                 ++k)',
    '                if (spelleffects::statusName(',
    '                        (spelleffects::StatusKind)k)',
    '                    == nullptr) ++bad;',
    '            if (std::string(spelleffects::statusName(',
    '                    spelleffects::STATUS_FLYING))',
    '                != ' + DQ + 'Flying' + DQ + ') ++bad;',
    '        }',
    '        printf(' + DQ +
    'R321 aerial chapter audit: bad %d' + BSN + DQ +
    ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
clean(IN_OLD, 76)
clean(IN_NEW, 76)
cleanNB(RT_OLD, 76)
cleanNB(RT_NEW, 76)

p = 'regtest.cpp'
s = rd(p)
if 'R321 aerial chapter audit' in s:
    already.append('regtest.cpp: the include and the R321 audit')
else:
    assert s.count(IN_OLD) == 1, 'include anchor not unique'
    assert s.count(RT_OLD) == 1, 'audit anchor not unique'
    s = s.replace(IN_OLD, IN_NEW, 1)
    s = s.replace(RT_OLD, RT_NEW, 1)
    wr(p, s)
    applied.append('regtest.cpp: the include and the R321 audit')

s = rd(p)
assert s.count('#include ' + DQ + 'rules/aerial.h' + DQ) == 1, 'm include'
assert s.count('R321 aerial chapter audit') == 1, 'm audit'
assert s.count('STATUS_FLYING)') == 2, 'm kind refs'
assert s.count('R320 breathing aids audit') == 1, 'm r320 intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch m balance'
assert len(applied) + len(already) == 13, 'patch m count wrong'

# ---- R321 tail ----
if len(applied) + len(already) != 13:
    print('R321 splice: FAIL - expected 13 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R321 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R321 note: 13 patches; the aerial')
print('chapter OUT reversal (the pp.49-53')
print('pins in rules/aerial.h; the fly spell')
print('and the potion seams; the R320 seed')
print('entry rides as the first patch); the')
print('battery census moves 247 -> 248')
print('commit: R321: the aerial chapter')
print('(census 248)')

