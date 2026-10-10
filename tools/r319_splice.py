#!/usr/bin/env python3
# tools/r319_splice.py - R319: the underwater
# vision multiples (one splice; the R318 seed
# entry rides as the first patch).
#
# The charge: the R311 vision paragraph closes
# - the three recorded kills each meet their
# layer this round. The DEPTH SEAM: the
# Encounter gains depthFt (the R316 setVisionFt
# pattern); setDepthFt re-folds the water sight
# from the decay pin (uwVisionDecayFt, fresh -
# 50 at the surface to 0 at 60; the pool site
# stays the surface, no dive site exists, the
# R312a seam precedent). The LIGHT FOLD: a new
# STATUS_LIGHT (the resolveStatusSpell pattern,
# no save on the spell rows) rides the MU/CL/IL
# Light cases; a party light cast in a water
# fight lifts the sight (uwLightSpellVisionFt
# - 30 feet or +10 under 60, whichever
# greater) and prints; continual light stays
# recorded (a permanent mark dies at the
# round-end tick - the R318b lesson). The HELM
# LAYER: the Helm of Underwater Action (the
# III.C table row) claims onto a member (the
# claimRing pattern), saves on the ringplus
# line pattern and quintuples the pool sight
# (uwHelmVisionMultiple, the beginCombat
# site). The latent kStatusNames shortfall (10
# names for 14 kinds - the R81/R82/R318 rows
# read null) is fixed alongside.
#
#   (a) doc/vibe/adnd1_knowledge_seed_v2.md -
#       the R318 round-state entry (commit
#       70216d6, census 245) and lessons.
#   (b) spelleffects/spelleffects.h - the
#       STATUS_LIGHT kind.
#   (c) spelleffects/spelleffects.cpp - the
#       kStatusNames array carries every kind.
#   (d) spelleffects/spelleffects.cpp - the
#       resolveSpell light cases.
#   (e) ai/actor.h - partyMutable (the
#       monstersMutable pattern).
#   (f) ai/actor.h - the depth and light seam
#       declarations (the R316 comment
#       refresh).
#   (g) ai/actor.h - the seam members.
#   (h) ai/actor.cpp - the setDepthFt fold.
#   (i) ai/actor.cpp - the resolveCast light
#       fold.
#   (j) game/party.h - the uwHelm field and
#       the claimUwHelm helper.
#   (k) game/state_core.cpp - the save line
#       and the load branch.
#   (l) game/state_dungeon.cpp - the MIK_OTHER
#       helm claim route.
#   (m) game/state_combat.cpp - the helm fold
#       at the pool sight (the print reads the
#       folded sight; the stale comments
#       refresh).
#   (n) regtest.cpp - the R319 audit (the
#       light status, the light fold and its
#       dry gate, the depth seam, the helm
#       claim, the helm fold - draw-
#       independent: the light rows save not,
#       the folds read the pins); the battery
#       census moves 245 -> 246.
#   (o) tools/dmg_gap_report.md - the R318
#       truth-up (the r318b hooks) and the
#       R319 chronicle paragraph.
#
# The R319 round-state entry rides the R320
# splice (it names this commit).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY
# patch (the R142 lesson). ZERO literal
# backslash bytes in this file - the anchors
# and prints that carry one are built via
# chr(92); no CONTENT string embeds an
# apostrophe, non-ASCII, or a line past its
# bound (78 the header and the C++ patches,
# 76 regtest, 72 the seed, 57 the gap report).
# The regtest asserts read the LOG WINDOW
# (the R316 lesson), never the head.
# Commit: "R319: the underwater vision
# multiples (census 246)"
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
    # the anchors that carry a built backslash byte
    # (the printf continuation, the string
    # terminator) - the length and ascii checks
    # without the byte ban
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

def counts(s):
    return (s.count('{'), s.count('}'),
            s.count('('), s.count(')'))

# ---- (a) the seed: the R318 round-state entry ----
SEED = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SD_ANCH = NL.join([
    '## Knowledge maintenance',
])
SD_ADD = NL.join([
    '- R318 landed 2026-10-10: commit 70216d6,',
    '  census 245, the net entrap layer (see',
    '  Current state above). RED then GREEN:',
    '  the preflight caught bad 1 - the N3',
    '  hold check. Lessons: (1) read the',
    '  ENGINE CODE, not the comment - the',
    '  tickStatus prose says permanent, the',
    '  code kills the zero-round mark at the',
    '  round-end tick, so the entrap',
    '  evaporated and the r318b fix re-asserts',
    '  the hooks each round (only the tear',
    '  frees); (2) the round-end status tick',
    '  is the interaction the sandbox cannot',
    '  trace - the preflight stays the only',
    '  gate that catches tick lifetimes; (3)',
    '  the letter rule held - the initial',
    '  splice committed alongside the fix,',
    '  history intact; (4) the fix splice kept',
    '  the audit as the gate and added a',
    '  second-round regression check (the',
    '  hold must survive two ticks).',
])
clean(SD_ANCH, 72)
clean(SD_ADD, 72)

s = rd(SEED)
if 'R318 landed' in s:
    already.append('the seed: the R318 entry')
else:
    assert s.count(SD_ANCH) == 1, 'seed anchor not unique'
    s = s.replace(SD_ANCH, SD_ADD + NL + NL + SD_ANCH, 1)
    wr(SEED, s)
    applied.append('the seed: the R318 entry')

s = rd(SEED)
assert s.count('R318 landed') == 1, 'a entry'
assert s.count('R317 landed') == 1, 'a r317 intact'
assert s.count(
    'Knowledge maintenance') == 1, 'a doc intact'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) spelleffects.h: the light kind ----
SE_OLD = NL.join([
    '    STATUS_ENTANGLED,   // R318: the hooked-net entrap',
    '                           // (MM sahuagin - torn at STR 16+)',
])
SE_NEW = NL.join([
    '    STATUS_ENTANGLED,   // R318: the hooked-net entrap',
    '                           // (MM sahuagin - torn at STR 16+)',
    '    STATUS_LIGHT,       // R319: the light spell mark',
    '                        // (the vision fold - resolveCast)',
])
clean(SE_OLD, 78)
clean(SE_NEW, 78)

p = 'spelleffects/spelleffects.h'
s = rd(p)
if 'STATUS_LIGHT,' in s:
    already.append('spelleffects.h: the light kind')
else:
    assert s.count(SE_OLD) == 1, 'enum anchor not unique'
    s = s.replace(SE_OLD, SE_NEW, 1)
    wr(p, s)
    applied.append('spelleffects.h: the light kind')

s = rd(p)
assert s.count('STATUS_LIGHT,') == 1, 'b kind'
assert s.count('STATUS_ENTANGLED,') == 1, 'b r318 intact'
assert s.count('STATUS_COUNT') == 1, 'b count intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) spelleffects.cpp: the status names ----
SN_OLD = NL.join([
    'static const char* const kStatusNames[STATUS_COUNT] = {',
    '    ' + DQ + 'None' + DQ + ', ' + DQ + 'Asleep' + DQ + ', ' +
    DQ + 'Charmed' + DQ + ', ' + DQ + 'Hasted' + DQ + ', ' +
    DQ + 'Slowed' + DQ + ',',
    '    ' + DQ + 'Silenced' + DQ + ', ' + DQ + 'Held' + DQ + ', ' +
    DQ + 'Invisible' + DQ + ', ' + DQ + 'Protected' + DQ + ', ' +
    DQ + 'Shielded' + DQ,
    '};',
])
SN_NEW = NL.join([
    'static const char* const kStatusNames[STATUS_COUNT] = {',
    '    ' + DQ + 'None' + DQ + ', ' + DQ + 'Asleep' + DQ + ', ' +
    DQ + 'Charmed' + DQ + ', ' + DQ + 'Hasted' + DQ + ', ' +
    DQ + 'Slowed' + DQ + ',',
    '    ' + DQ + 'Silenced' + DQ + ', ' + DQ + 'Held' + DQ + ', ' +
    DQ + 'Invisible' + DQ + ', ' + DQ + 'Protected' + DQ + ', ' +
    DQ + 'Shielded' + DQ + ',',
    '    // R319: the array fell four names short',
    '    // of the enum (the R81/R82/R318 kinds read',
    '    // a null name); the light name rides the',
    '    // fold below.',
    '    ' + DQ + 'Fire Shield' + DQ + ', ' + DQ + 'Antivenom' +
    DQ + ', ' + DQ + 'Polymorphed' + DQ + ', ' +
    DQ + 'Entrapped' + DQ + ',',
    '    ' + DQ + 'Lit' + DQ,
    '};',
])
clean(SN_OLD, 78)
clean(SN_NEW, 78)
assert Q not in SN_NEW, 'c apostrophe'

p = 'spelleffects/spelleffects.cpp'
s = rd(p)
if s.count(DQ + 'Entrapped' + DQ) == 1:
    already.append('spelleffects.cpp: the status names')
else:
    assert s.count(SN_OLD) == 1, 'names anchor not unique'
    s = s.replace(SN_OLD, SN_NEW, 1)
    wr(p, s)
    applied.append('spelleffects.cpp: the status names')

s = rd(p)
assert s.count(DQ + 'Entrapped' + DQ) == 1, 'c names'
assert s.count(DQ + 'Lit' + DQ) == 1, 'c light name'
assert s.count('kStatusNames') == 2, 'c array intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) spelleffects.cpp: the light cases ----
LC_OLD = NL.join([
    '            case spells::MU_FIRE_SHIELD:   // R81',
    '                r = resolveStatusSpell(dice, s, STATUS_FIRESHIELD,',
    '                                       s.durationRounds, t, false);',
    '                break;',
])
LC_NEW = NL.join([
    '            case spells::MU_FIRE_SHIELD:   // R81',
    '                r = resolveStatusSpell(dice, s, STATUS_FIRESHIELD,',
    '                                       s.durationRounds, t, false);',
    '                break;',
    '            // R319: the light spell - the status',
    '            // mark (the rows save not); the vision',
    '            // fold rides resolveCast. The',
    '            // reversible darkness and the',
    '            // continual light stay recorded (no',
    '            // darkness notion; a permanent mark',
    '            // dies at the round-end tick - the',
    '            // R318b lesson).',
    '            case spells::MU_LIGHT:   // R319',
    '            case spells::CL_LIGHT:',
    '            case spells::IL_LIGHT:',
    '                r = resolveStatusSpell(dice, s, STATUS_LIGHT,',
    '                                       s.durationRounds, t, false);',
    '                break;',
])
clean(LC_OLD, 78)
clean(LC_NEW, 78)
assert Q not in LC_NEW, 'd apostrophe'

p = 'spelleffects/spelleffects.cpp'
s = rd(p)
if s.count('case spells::MU_LIGHT:') == 1:
    already.append('spelleffects.cpp: the light cases')
else:
    assert s.count(LC_OLD) == 1, 'cases anchor not unique'
    s = s.replace(LC_OLD, LC_NEW, 1)
    wr(p, s)
    applied.append('spelleffects.cpp: the light cases')

s = rd(p)
assert s.count('case spells::MU_LIGHT:') == 1, 'd case'
assert s.count('STATUS_LIGHT,') == 1, 'd status'
assert s.count('case spells::MU_FIRE_SHIELD:') == 1, 'd r81 intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) actor.h: partyMutable ----
PM_OLD = NL.join([
    '    std::vector<Actor>& monstersMutable() { return m_monsters; }',
])
PM_NEW = NL.join([
    '    std::vector<Actor>& monstersMutable() { return m_monsters; }',
    '    // R319: the party-side mirror (the cast',
    '    // commands and the audits reach the live',
    '    // company actors; the monstersMutable',
    '    // pattern)',
    '    std::vector<Actor>& partyMutable() { return m_party; }',
])
clean(PM_OLD, 78)
clean(PM_NEW, 78)

p = 'ai/actor.h'
s = rd(p)
if 'partyMutable' in s:
    already.append('actor.h: partyMutable')
else:
    assert s.count(PM_OLD) == 1, 'party anchor not unique'
    s = s.replace(PM_OLD, PM_NEW, 1)
    wr(p, s)
    applied.append('actor.h: partyMutable')

s = rd(p)
assert s.count('partyMutable() { return m_party; }') == 1, (
    'e accessor')
assert s.count('monstersMutable() { return m_monsters; }') == 1, (
    'e prior intact')
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch e balance'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) actor.h: the seam declarations ----
FD_OLD = NL.join([
    '    // the water fight (the fresh pool surface',
    '    // reads 50 feet; the depth decay and the',
    '    // light/helm multiples stay data - no depth',
    '    // or active-light layer exists).',
    '    void setVisionFt(int ft) { m_visionFt = ft; }',
    '    int  visionFt() const { return m_visionFt; }',
])
FD_NEW = NL.join([
    '    // the water fight (the fresh pool surface',
    '    // reads 50 feet; the R319 seams fold the',
    '    // sight - the depth decay pin at',
    '    // setDepthFt, the light pin at',
    '    // resolveCast, the helm pin at the app',
    '    // site).',
    '    void setVisionFt(int ft) { m_visionFt = ft; }',
    '    int  visionFt() const { return m_visionFt; }',
    '    // R319: the depth seam - setDepthFt',
    '    // re-folds the water sight from the R311',
    '    // decay pin (the pool site stays the',
    '    // surface - no dive site exists, the R312a',
    '    // seam precedent).',
    '    void setDepthFt(int ft);',
    '    int  depthFt() const { return m_depthFt; }',
    '    // R319: the company light - a party light',
    '    // spell in the water fight lifts the sight',
    '    // (the resolveCast fold).',
    '    bool lightActive() const { return m_lightActive; }',
])
clean(FD_OLD, 78)
clean(FD_NEW, 78)

p = 'ai/actor.h'
s = rd(p)
if 'void setDepthFt(int ft);' in s:
    already.append('actor.h: the seam declarations')
else:
    assert s.count(FD_OLD) == 1, 'seam anchor not unique'
    s = s.replace(FD_OLD, FD_NEW, 1)
    wr(p, s)
    applied.append('actor.h: the seam declarations')

s = rd(p)
assert s.count('void setDepthFt(int ft);') == 1, 'f depth decl'
assert s.count('depthFt() const') == 1, 'f depth getter'
assert s.count('lightActive() const') == 1, 'f light getter'
assert s.count(
    'void setVisionFt(int ft)') == 1, 'f r316 intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch f balance'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) actor.h: the seam members ----
MM_OLD = NL.join([
    '    int  m_visionFt = 0;   // R316: the vision seam',
])
MM_NEW = NL.join([
    '    int  m_visionFt = 0;   // R316: the vision seam',
    '    int  m_depthFt = 0;   // R319: the depth seam',
    '    bool m_lightActive = false;   // R319: the light',
])
clean(MM_OLD, 78)
clean(MM_NEW, 78)

p = 'ai/actor.h'
s = rd(p)
if 'm_depthFt = 0;' in s:
    already.append('actor.h: the seam members')
else:
    assert s.count(MM_OLD) == 1, 'member anchor not unique'
    s = s.replace(MM_OLD, MM_NEW, 1)
    wr(p, s)
    applied.append('actor.h: the seam members')

s = rd(p)
assert s.count('m_depthFt') == 2, 'g depth member'
assert s.count('m_lightActive') == 2, 'g light member'
assert s.count(
    'm_visionFt = 0;   // R316') == 1, 'g r316 intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch g balance'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- (h) actor.cpp: the setDepthFt fold ----
CT_OLD = NL.join([
    '      m_rng(seed), m_dice(m_rng) {}',
    '',
    'void Encounter::logLine(const std::string& s) {',
])
CT_NEW = NL.join([
    '      m_rng(seed), m_dice(m_rng) {}',
    '',
    '// R319: the depth fold - the R311 decay',
    '// pin re-folds the water sight (fresh; the',
    '// pool site stays the surface); the dry',
    '// fight keeps the R316 zero (the seam',
    '// never charges a sight there).',
    'void Encounter::setDepthFt(int ft) {',
    '    m_depthFt = ft;',
    '    if (m_waterFight)',
    '        m_visionFt =',
    '            rules::uwVisionDecayFt(0, ft);',
    '}',
    '',
    'void Encounter::logLine(const std::string& s) {',
])
clean(CT_OLD, 78)
clean(CT_NEW, 78)

p = 'ai/actor.cpp'
s = rd(p)
if 'void Encounter::setDepthFt(int ft) {' in s:
    already.append('actor.cpp: the setDepthFt fold')
else:
    assert s.count(CT_OLD) == 1, 'ctor anchor not unique'
    s = s.replace(CT_OLD, CT_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the setDepthFt fold')

s = rd(p)
assert s.count(
    'void Encounter::setDepthFt(int ft) {') == 1, 'h fold'
assert s.count('uwVisionDecayFt(0, ft)') == 1, 'h pin read'
assert s.count('m_rng(seed), m_dice(m_rng) {}') == 1, 'h ctor'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch h balance'
assert len(applied) + len(already) == 8, 'patch h count wrong'

# ---- (i) actor.cpp: the resolveCast light fold ----
RC_OLD = NL.join([
    '        if (tr.note[0] != ' + Q + BS + '0' + Q + ')',
    '            logLine(std::string(tr.note));',
    '    }',
    '}',
])
RC_NEW = NL.join([
    '        if (tr.note[0] != ' + Q + BS + '0' + Q + ')',
    '            logLine(std::string(tr.note));',
    '    }',
    '',
    '    // R319: the light fold - a party light',
    '    // spell in a water fight lifts the',
    '    // sight (the R311 light pin - 30 feet',
    '    // or +10 under 60, whichever greater);',
    '    // the dry fight keeps the R316 zero (no',
    '    // vision state). Continual light stays',
    '    // recorded (a permanent mark dies at',
    '    // the round-end tick - the R318b',
    '    // lesson).',
    '    if ((id == spells::MU_LIGHT ||',
    '         id == spells::CL_LIGHT ||',
    '         id == spells::IL_LIGHT) &&',
    '        caster.team == 0 && m_waterFight &&',
    '        !m_lightActive) {',
    '        m_lightActive = true;',
    '        m_visionFt =',
    '            rules::uwLightSpellVisionFt(',
    '                m_visionFt);',
    '        logLine(' + DQ + 'The light carries - ' + DQ,
    '                ' + DQ + 'sight runs ' + DQ +
    ' +',
    '                std::to_string(m_visionFt) +',
    '                ' + DQ + ' feet.' + DQ + ');',
    '    }',
    '}',
])
cleanNB(RC_OLD, 78)
cleanNB(RC_NEW, 78)
# the apostrophe here rides the C string-terminator
# literal (the existing source carries it) - the
# prose blocks stay apostrophe-free

p = 'ai/actor.cpp'
s = rd(p)
if 'The light carries' in s:
    already.append('actor.cpp: the resolveCast light fold')
else:
    assert s.count(RC_OLD) == 1, 'cast anchor not unique'
    s = s.replace(RC_OLD, RC_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the resolveCast light fold')

s = rd(p)
assert s.count('The light carries') == 1, 'i print'
assert s.count('uwLightSpellVisionFt(') == 1, 'i pin read'
assert s.count('m_lightActive = true;') == 1, 'i mark'
assert s.count(
    'logLine(std::string(tr.note));') == 1, 'i loop intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch i balance'
assert len(applied) + len(already) == 9, 'patch i count wrong'

# ---- (j) party.h: the helm field and claim ----
HH_OLD = NL.join([
    '    // R81: Ring of Protection AC bonus (0 = none worn)',
    '    int ringPlus = 0;',
])
HH_NEW = NL.join([
    '    // R81: Ring of Protection AC bonus (0 = none worn)',
    '    int ringPlus = 0;',
    '    // R319: the Helm of Underwater Action worn',
    '    // (the claim layer; quintuples the water',
    '    // sight - the R311 helm pin)',
    '    bool uwHelm = false;',
])
clean(HH_OLD, 78)
clean(HH_NEW, 78)

CR_OLD = NL.join([
    '    c.ringPlus = 1;',
    '    return true;',
    '}',
])
CR_NEW = NL.join([
    '    c.ringPlus = 1;',
    '    return true;',
    '}',
    '',
    '// --------------------------------------------------------------------------',
    '// R319: claim a Helm of Underwater Action for a',
    '// member (the claimRing pattern) - one helm per',
    '// member, the first living taker wins; every other',
    '// ring/rod/misc stays appraised.',
    '// --------------------------------------------------------------------------',
    'inline bool claimUwHelm(Character& c, const std::string& name,',
    '                        int qty) {',
    '    if (c.hp <= 0 || qty != 1 || c.uwHelm) return false;',
    '    if (name.find(' + DQ + 'Helm of Underwater Action' + DQ +
    ') ==',
    '        std::string::npos)',
    '        return false;',
    '    c.uwHelm = true;',
    '    return true;',
    '}',
])
clean(CR_OLD, 78)
clean(CR_NEW, 78)
assert Q not in CR_NEW, 'j apostrophe'

p = 'game/party.h'
s = rd(p)
if 'claimUwHelm' in s:
    already.append('party.h: the helm field and claim')
else:
    assert s.count(HH_OLD) == 1, 'field anchor not unique'
    s = s.replace(HH_OLD, HH_NEW, 1)
    assert s.count(CR_OLD) == 1, 'claim anchor not unique'
    s = s.replace(CR_OLD, CR_NEW, 1)
    wr(p, s)
    applied.append('party.h: the helm field and claim')

s = rd(p)
assert s.count('inline bool claimUwHelm(') == 1, 'j helper'
assert s.count('bool uwHelm = false;') == 1, 'j field'
assert s.count('c.ringPlus = 1;') == 1, 'j ring intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch j balance'
assert len(applied) + len(already) == 10, 'patch j count wrong'

# ---- (k) state_core.cpp: the save and load ----
SV_OLD = NL.join([
    '            if (c.ringPlus > 0)',
    '                fprintf(f, ' + DQ + 'ringplus %d' + BS +
    'n' + DQ + ', c.ringPlus);',
])
SV_NEW = NL.join([
    '            if (c.ringPlus > 0)',
    '                fprintf(f, ' + DQ + 'ringplus %d' + BS +
    'n' + DQ + ', c.ringPlus);',
    '            // R319: the helm (worn only - v1 saves',
    '            // carry no line and load without it)',
    '            if (c.uwHelm)',
    '                fprintf(f, ' + DQ + 'uwhelm 1' + BS +
    'n' + DQ + ');',
])
cleanNB(SV_OLD, 78)
cleanNB(SV_NEW, 78)
assert Q not in SV_NEW, 'k save apostrophe'

LD_OLD = NL.join([
    '                    c.ringPlus = rg;',
    '                } else if',
])
LD_NEW = NL.join([
    '                    c.ringPlus = rg;',
    '                } else if (strcmp(tag, ' + DQ +
    'uwhelm' + DQ + ') == 0) {',
    '                    int uh = 0;',
    '                    if (fscanf(f, ' + DQ + '%d' + DQ +
    ', &uh) != 1 ||',
    '                        uh < 0 || uh > 1) {',
    '                        fclose(f);',
    '                        log.add(' + DQ +
    'adnd1.sav is corrupt (helm).' + DQ + ');',
    '                        return false;',
    '                    }',
    '                    c.uwHelm = uh != 0;',
    '                } else if',
])
cleanNB(LD_OLD, 78)
cleanNB(LD_NEW, 78)
assert Q not in LD_NEW, 'k load apostrophe'

p = 'game/state_core.cpp'
s = rd(p)
if 'uwhelm' in s:
    already.append('state_core.cpp: the save and load')
else:
    assert s.count(SV_OLD) == 1, 'save anchor not unique'
    s = s.replace(SV_OLD, SV_NEW, 1)
    assert s.count(LD_OLD) == 1, 'load anchor not unique'
    s = s.replace(LD_OLD, LD_NEW, 1)
    wr(p, s)
    applied.append('state_core.cpp: the save and load')

s = rd(p)
assert s.count('uwhelm') == 2, 'k lines'
assert s.count('c.uwHelm') == 2, 'k flags'
assert s.count('c.ringPlus = rg;') == 1, 'k ring intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch k balance'
assert len(applied) + len(already) == 11, 'patch k count wrong'

# ---- (l) state_dungeon.cpp: the claim route ----
DR_OLD = NL.join([
    '                        for (auto& c : party.members) {',
    '                            if (c.hp <= 0) continue;',
    '                            if (claimRing(c, mi.name, mi.qty)) {',
])
DR_NEW = NL.join([
    '                        for (auto& c : party.members) {',
    '                            if (c.hp <= 0) continue;',
    '                            // R319: the Helm of Underwater',
    '                            // Action - the carried light for',
    '                            // the deep (the claimRing',
    '                            // pattern); the water sight',
    '                            // quintuples at the pool fight',
    '                            if (claimUwHelm(c, mi.name,',
    '                                            mi.qty)) {',
    '                                snprintf(buf, sizeof buf,',
    '                                         ' + DQ + '%s dons the %s!' +
    DQ + ',',
    '                                         c.name.c_str(),',
    '                                         mi.name.c_str());',
    '                                log.add(buf);',
    '                                take = true;',
    '                                break;',
    '                            }',
    '                            if (claimRing(c, mi.name, mi.qty)) {',
])
clean(DR_OLD, 78)
clean(DR_NEW, 78)
assert Q not in DR_NEW, 'l apostrophe'

p = 'game/state_dungeon.cpp'
s = rd(p)
if 'claimUwHelm(c, mi.name,' in s:
    already.append('state_dungeon.cpp: the claim route')
else:
    assert s.count(DR_OLD) == 1, 'route anchor not unique'
    s = s.replace(DR_OLD, DR_NEW, 1)
    wr(p, s)
    applied.append('state_dungeon.cpp: the claim route')

s = rd(p)
assert s.count(
    'claimUwHelm(c, mi.name,') == 1, 'l route'
assert s.count('claimRing(c, mi.name, mi.qty)) {') == 1, (
    'l ring intact')
assert s.count('dons the %s!') == 1, 'l print'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch l balance'
assert len(applied) + len(already) == 12, 'patch l count wrong'

# ---- (m) state_combat.cpp: the helm fold ----
CB_OLD = NL.join([
    '            // grain); the light-spell and helm',
    '            // multiples stay recorded (no',
    '            // active-light or carried-item layer',
    '            // exists)',
    '            combat.encounter->setVisionFt(',
    '                rules::uwVisionBaseFt(0));',
    '            char vbuf[64];',
    '            snprintf(vbuf, sizeof vbuf,',
    '                     ' + DQ + 'Sight runs %d feet in the ' + DQ,
    '                     ' + DQ + 'clouded fresh water.' + DQ + ',',
    '                     rules::uwVisionBaseFt(0));',
])
CB_NEW = NL.join([
    '            // grain); the R319 helm multiple',
    '            // folds here (the claim layer); the',
    '            // light fold rides resolveCast',
    '            combat.encounter->setVisionFt(',
    '                rules::uwVisionBaseFt(0));',
    '            // R319: the helm of underwater action',
    '            // quintuples the sight (the carried',
    '            // light - the first living member',
    '            // wearing one)',
    '            for (const auto& c : party.members)',
    '                if (c.hp > 0 && c.uwHelm) {',
    '                    combat.encounter->setVisionFt(',
    '                        combat.encounter->visionFt() *',
    '                        rules::uwHelmVisionMultiple());',
    '                    break;',
    '                }',
    '            char vbuf[64];',
    '            snprintf(vbuf, sizeof vbuf,',
    '                     ' + DQ + 'Sight runs %d feet in the ' + DQ,
    '                     ' + DQ + 'clouded fresh water.' + DQ + ',',
    '                     combat.encounter->visionFt());',
])
clean(CB_OLD, 78)
clean(CB_NEW, 78)
assert Q not in CB_NEW, 'm fold apostrophe'

C2_OLD = NL.join([
    '            // range (the light-spell and helm',
    '            // multiples stay recorded - no',
    '            // active-light or carried-item',
    '            // layer exists)',
])
C2_NEW = NL.join([
    '            // range (the R319 light and helm',
    '            // folds charge the sight seam -',
    '            // resolveCast and the claim layer)',
])
clean(C2_OLD, 78)
clean(C2_NEW, 78)

p = 'game/state_combat.cpp'
s = rd(p)
if 'uwHelmVisionMultiple())' in s:
    already.append('state_combat.cpp: the helm fold')
else:
    assert s.count(CB_OLD) == 1, 'fold anchor not unique'
    s = s.replace(CB_OLD, CB_NEW, 1)
    assert s.count(C2_OLD) == 1, 'comment anchor not unique'
    s = s.replace(C2_OLD, C2_NEW, 1)
    wr(p, s)
    applied.append('state_combat.cpp: the helm fold')

s = rd(p)
assert s.count('uwHelmVisionMultiple())') == 1, 'm fold'
assert s.count(
    'combat.encounter->visionFt());') == 1, 'm print'
assert s.count(
    'the light-spell and helm') == 0, 'm stale gone'
assert s.count('rules::uwVisionBaseFt(0));') == 1, (
    'm base intact')
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch m balance'
assert len(applied) + len(already) == 13, 'patch m count wrong'

# ---- (n) regtest.cpp: the R319 audit ----
BSN = BS + 'n'
RT_OLD = NL.join([
    '        printf(' + DQ +
    'R318 net entrap layer audit: bad %d' + BSN + DQ +
    ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_NEW = NL.join([
    '        printf(' + DQ +
    'R318 net entrap layer audit: bad %d' + BSN + DQ +
    ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R319: the underwater vision',
    '    // multiples audit ----',
    '    // The R311 vision paragraph closes: the',
    '    // depth seam re-folds the water sight',
    '    // (the decay pin, fresh), a party light',
    '    // spell lifts the water sight',
    '    // (resolveCast - the rows save not) and',
    '    // the claimed Helm of Underwater Action',
    '    // quintuples the pool sight (the claim',
    '    // layer, the carried-item seam).',
    '    // Continual light stays recorded (a',
    '    // permanent mark dies at the round-end',
    '    // tick - the R318b lesson). Draw-',
    '    // independent: the light rows save not,',
    '    // the folds read the pins.',
    '    {',
    '        int bad = 0;',
    '        // W1: the light status - the spell',
    '        // engine level (no save on the row)',
    '        {',
    '            rules::Rng r(7);',
    '            rules::Dice d(r);',
    '            ai::Actor t;',
    '            t.team = 1; t.hitDice = 1;',
    '            t.hp = 6; t.maxHp = 6;',
    '            std::vector<spelleffects::TargetDesc>',
    '                ds;',
    '            ds.push_back(t.asTarget());',
    '            spelleffects::SpellCastResult r1 =',
    '                spelleffects::resolveSpell(',
    '                    d, spells::MU_LIGHT, 1, ds);',
    '            if (r1.perTarget.size() != 1) ++bad;',
    '            if (!r1.perTarget.empty() &&',
    '                r1.perTarget[0].status.kind !=',
    '                    spelleffects::STATUS_LIGHT)',
    '                ++bad;',
    '        }',
    '        // W2: the light fold - a party cast in',
    '        // the water fight lifts the sight',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.team = 0;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.classIndex = 1; a.level = 1;',
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
    '            enc.setWaterFight();',
    '            enc.setVisionFt(',
    '                rules::uwVisionBaseFt(0));',
    '            enc.resolveCast(',
    '                enc.partyMutable()[0],',
    '                spells::MU_LIGHT);',
    '            if (enc.visionFt() !=',
    '                rules::uwLightSpellVisionFt(',
    '                    rules::uwVisionBaseFt(0)))',
    '                ++bad;',
    '            bool lit = false;',
    '            for (const auto& ln : enc.log())',
    '                if (ln.text.find(' + DQ +
    'The light carries' + DQ + ') !=',
    '                    std::string::npos)',
    '                    lit = true;',
    '            if (!lit) ++bad;',
    '            // the slot spent',
    '            if (enc.partyMutable()[0]',
    '                    .slotsByLevel[0] != 0) ++bad;',
    '        }',
    '        // W3: the dry gate - no water fight,',
    '        // no sight state, no fold',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.team = 0;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.classIndex = 1; a.level = 1;',
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
    '            if (enc.visionFt() != 0) ++bad;',
    '            bool lit = false;',
    '            for (const auto& ln : enc.log())',
    '                if (ln.text.find(' + DQ +
    'The light carries' + DQ + ') !=',
    '                    std::string::npos)',
    '                    lit = true;',
    '            if (lit) ++bad;',
    '        }',
    '        // W4: the depth seam - the decay pin',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.team = 0;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.hp = 30; a.maxHp = 30;',
    '            pt.push_back(a);',
    '            std::vector<ai::Actor> mons;',
    '            ai::Actor m;',
    '            m.team = 1; m.hitDice = 1;',
    '            m.name = ' + DQ + 'Monst' + DQ + ';',
    '            m.hp = 6; m.maxHp = 6;',
    '            mons.push_back(m);',
    '            ai::Encounter enc(pt, mons, 20);',
    '            enc.setWaterFight();',
    '            enc.setVisionFt(',
    '                rules::uwVisionBaseFt(0));',
    '            enc.setDepthFt(30);',
    '            if (enc.visionFt() !=',
    '                rules::uwVisionDecayFt(0, 30))',
    '                ++bad;',
    '            enc.setDepthFt(70);',
    '            if (enc.visionFt() != 0) ++bad;',
    '            if (enc.depthFt() != 70) ++bad;',
    '        }',
    '        // W5: the dry depth - the R316 zero',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.team = 0;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.hp = 30; a.maxHp = 30;',
    '            pt.push_back(a);',
    '            std::vector<ai::Actor> mons;',
    '            ai::Actor m;',
    '            m.team = 1; m.hitDice = 1;',
    '            m.name = ' + DQ + 'Monst' + DQ + ';',
    '            m.hp = 6; m.maxHp = 6;',
    '            mons.push_back(m);',
    '            ai::Encounter enc(pt, mons, 20);',
    '            enc.setDepthFt(30);',
    '            if (enc.visionFt() != 0) ++bad;',
    '        }',
    '        // W6: the helm claim (the claimRing',
    '        // pattern)',
    '        {',
    '            Character c;',
    '            c.hp = 10;',
    '            if (!claimUwHelm(',
    '                    c, ' + DQ + 'Helm of Underwater Action' + DQ +
    ',',
    '                    1)) ++bad;',
    '            if (!c.uwHelm) ++bad;',
    '            // one helm per member',
    '            if (claimUwHelm(',
    '                    c, ' + DQ + 'Helm of Underwater Action' + DQ +
    ',',
    '                    1)) ++bad;',
    '            c.uwHelm = false;',
    '            // other misc never claims',
    '            if (claimUwHelm(c, ' + DQ + 'Helm of Brilliance' +
    DQ + ',',
    '                            1)) ++bad;',
    '            // bundles never claim',
    '            if (claimUwHelm(',
    '                    c, ' + DQ + 'Helm of Underwater Action' + DQ +
    ',',
    '                    2)) ++bad;',
    '            // the dead claim nothing',
    '            c.hp = 0;',
    '            if (claimUwHelm(',
    '                    c, ' + DQ + 'Helm of Underwater Action' + DQ +
    ',',
    '                    1)) ++bad;',
    '        }',
    '        // W7: the helm fold - the pool sight',
    '        // quintuples (the beginCombat site)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            st.party.formed = true;',
    '            Character arc;',
    '            arc.name = ' + DQ + 'Arc' + DQ + ';',
    '            arc.classIndex = 0; arc.level = 1;',
    '            arc.race = 0;',
    '            arc.hp = 30; arc.maxHp = 30;',
    '            arc.uwHelm = true;',
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
    '                st.combat.encounter->visionFt() !=',
    '                    rules::uwVisionBaseFt(0) *',
    '                        rules::uwHelmVisionMultiple())',
    '                ++bad;',
    '            bool h = false;',
    '            for (int i = 0; i < 4; ++i)',
    '                if (st.log.get(i).find(' + DQ +
    'Sight runs 250 feet' + DQ + ') !=',
    '                    std::string::npos)',
    '                    h = true;',
    '            if (!h) ++bad;',
    '        }',
    '        printf(' + DQ +
    'R319 underwater vision multiples audit: bad %d' + BSN +
    DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
cleanNB(RT_OLD, 76)
cleanNB(RT_NEW, 76)
assert Q not in RT_NEW, 'n apostrophe'

p = 'regtest.cpp'
s = rd(p)
if 'R319 underwater vision multiples audit' in s:
    already.append('regtest.cpp: the R319 audit')
else:
    assert s.count(RT_OLD) == 1, 'audit anchor not unique'
    s = s.replace(RT_OLD, RT_NEW, 1)
    wr(p, s)
    applied.append('regtest.cpp: the R319 audit')

s = rd(p)
assert s.count(
    'R319 underwater vision multiples audit') == 1, (
    'n audit')
assert s.count('audit: bad') == 246, 'n census'
assert s.count(
    'R318 net entrap layer audit') == 1, 'n r318 intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch n balance'
assert len(applied) + len(already) == 14, 'patch n count wrong'

# ---- (o) dmg_gap_report.md: the truth-up and chronicle ----
GP = 'tools/dmg_gap_report.md'
TU_OLD = NL.join([
    'entrap); the entrap is permanent until',
    'torn (the zero-round convention) and a',
])
TU_NEW = NL.join([
    'entrap); the entrap holds until torn',
    '(the r318b hooks re-assert each round;',
    'a zero-round mark dies at the round-end',
    'tick) and a',
])
clean(TU_OLD, 57, gap=True)
clean(TU_NEW, 57, gap=True)

GC_OLD = NL.join([
    'it. The census moves 244 -> 245 with',
    'the R318 audit.',
    '',
    'Categories:',
])
GC_NEW = NL.join([
    'it. The census moves 244 -> 245 with',
    'the R318 audit.',
    '',
    'R319 the underwater vision',
    'multiples: the R311 vision paragraph',
    'closes - the depth seam (setDepthFt',
    're-folds the water sight from the',
    'decay pin, fresh; the pool site stays',
    'the surface), a party light spell',
    'lifts the water sight (STATUS_LIGHT',
    'at the spell engine, the resolveCast',
    'fold; continual light stays recorded',
    '- a permanent mark dies at the',
    'round-end tick, the R318b lesson)',
    'and the claimed Helm of Underwater',
    'Action quintuples the pool sight',
    '(uwHelm on the claim layer, the',
    'claimRing pattern; the status-name',
    'array carried only 10 of the 14',
    'kinds - fixed alongside). The census',
    'moves 245 -> 246 with the R319',
    'audit.',
    '',
    'Categories:',
])
clean(GC_OLD, 57, gap=True)
clean(GC_NEW, 57, gap=True)

s = rd(GP)
if 'R319 the underwater vision' in s:
    already.append('dmg report: the truth-up and chronicle')
else:
    assert s.count(TU_OLD) == 1, 'truth anchor not unique'
    s = s.replace(TU_OLD, TU_NEW, 1)
    assert s.count(GC_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(GC_OLD, GC_NEW, 1)
    wr(GP, s)
    applied.append('dmg report: the truth-up and chronicle')

s = rd(GP)
assert s.count('R319 the underwater vision') == 1, 'o entry'
assert s.count('r318b hooks re-assert each round;') == 1, (
    'o truth')
assert s.count('Categories:') == 1, 'o legend head'
assert s.count('moves 245 -> 246') == 1, 'o census'
assert s.count('moves 244 -> 245') == 1, 'o r318 intact'
assert len(applied) + len(already) == 15, 'patch o count wrong'

# ---- R319 tail ----
if len(applied) + len(already) != 15:
    print('R319 splice: FAIL - expected 15 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R319 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R319 note: 15 patches; the underwater')
print('vision multiples close the R311')
print('paragraph (the depth seam, the light')
print('fold, the helm claim layer; the R318')
print('seed entry rides as the first patch);')
print('the battery census moves 245 -> 246')
print('commit: R319: the underwater vision')
print('multiples (census 246)')

