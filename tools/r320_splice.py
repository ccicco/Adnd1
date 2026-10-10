#!/usr/bin/env python3
# tools/r320_splice.py - R320: the breathing
# aids (one splice; the R319 seed entry
# rides as the first patch).
#
# The charge: the R311 RECORDED-NOTES
# breathing aids meet their layers (the
# R319 seams). The SPELL: the druid Water
# Breathing (registry row - save not, 60
# rounds) gains a STATUS_WATERBREATHING
# at the engine (the resolveStatusSpell
# pattern); a party cast in a water fight
# marks the company and prints (the
# resolveCast light pattern). The POTION:
# the III.A Potion of Water Breathing
# (non-healing potions route MIK_OTHER)
# claims onto a member (the claimUwHelm
# pattern), saves on the uwdraught line
# and prints at the pool fight. No
# drowning site exists - the prints ARE
# the charge (the honest grain; the airy
# water, shape change and wish variants
# stay recorded - not in the registry).
#
# The honest kills, recorded in the gap
# report: the MUD CLOUD (d6+6 rounds
# after the movement stops - no
# movement-stop notion) and the
# SEAWEED/SHOAL reducers (only TILE_WATER
# exists - no seaweed or shoal tile).
#
#   (a) doc/vibe/adnd1_knowledge_seed_v2.md -
#       the R319 round-state entry (commit
#       c98c923, census 246) and lessons.
#   (b) spelleffects/spelleffects.h - the
#       STATUS_WATERBREATHING kind.
#   (c) spelleffects/spelleffects.cpp - the
#       kStatusNames row.
#   (d) spelleffects/spelleffects.cpp - the
#       resolveSpell water breathing case.
#   (e) ai/actor.h - the breath seam (the
#       R319 light pattern).
#   (f) ai/actor.cpp - the resolveCast
#       breath fold.
#   (g) game/party.h - the uwDraught field
#       and the claimUwDraught helper.
#   (h) game/state_core.cpp - the save line
#       and the load branch.
#   (i) game/state_dungeon.cpp - the MIK_OTHER
#       draught claim route.
#   (j) game/state_combat.cpp - the pool
#       fight draught print.
#   (k) rules/underwater.h - the
#       recorded-notes truth-up.
#   (l) regtest.cpp - the R320 audit (the
#       status, the cast fold, the dry gate,
#       the claim, the pool print, the name
#       array - draw-independent: the row
#       saves not, the folds read pins); the
#       battery census moves 246 -> 247.
#   (m) tools/dmg_gap_report.md - the R320
#       chronicle paragraph (the mud and
#       seaweed kills recorded).
#
# The R320 round-state entry rides the R321
# splice (it names this commit).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY
# patch (the R142 lesson). ZERO literal
# backslash bytes in this file - the printf
# continuations are built via chr(92); no
# CONTENT string embeds an apostrophe,
# non-ASCII, or a line past its bound (78
# the header and the C++ patches, 76 regtest,
# 72 the seed, 57 the gap report).
# Commit: "R320: the breathing aids
# (census 247)"
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
    # the anchors that carry a built backslash
    # byte (the printf continuation) - the
    # length and ascii checks without the byte
    # ban
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

def counts(s):
    return (s.count('{'), s.count('}'),
            s.count('('), s.count(')'))

# ---- (a) the seed: the R319 round-state entry ----
SEED = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SD_ANCH = NL.join([
    '## Knowledge maintenance',
])
SD_ADD = NL.join([
    '- R319 landed 2026-10-10: commit',
    '  c98c923, census 246, the underwater',
    '  vision multiples (see Current state',
    '  above). RED then GREEN: the build',
    '  caught the W2/W3 audit calls -',
    '  resolveCast sat private. Lessons: (1)',
    '  a public seam needs a PUBLIC',
    '  declaration - the partyMutable comment',
    '  promised cast access, the declaration',
    '  never moved (the r319b fix); (2) the',
    '  sandbox has no compiler - a C++',
    '  visibility error can only surface at',
    '  the Termux build, and the census',
    '  cascade (every audit appears 0 times)',
    '  means the build died before the',
    '  battery ran; (3) the light rows save',
    '  not, so the W scenarios stayed draw-',
    '  independent through the fix; (4) the',
    '  latent kStatusNames shortfall (10',
    '  names for 14 kinds) was found and',
    '  fixed by the survey, before it bit.',
])
clean(SD_ANCH, 72)
clean(SD_ADD, 72)

s = rd(SEED)
if 'R319 landed' in s:
    already.append('the seed: the R319 entry')
else:
    assert s.count(SD_ANCH) == 1, 'seed anchor not unique'
    s = s.replace(SD_ANCH, SD_ADD + NL + NL + SD_ANCH, 1)
    wr(SEED, s)
    applied.append('the seed: the R319 entry')

s = rd(SEED)
assert s.count('R319 landed') == 1, 'a entry'
assert s.count('R318 landed') == 1, 'a r318 intact'
assert s.count(
    'Knowledge maintenance') == 1, 'a doc intact'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) spelleffects.h: the breath kind ----
SE_OLD = NL.join([
    '    STATUS_LIGHT,       // R319: the light spell mark',
    '                        // (the vision fold - resolveCast)',
    '    STATUS_COUNT',
])
SE_NEW = NL.join([
    '    STATUS_LIGHT,       // R319: the light spell mark',
    '                        // (the vision fold - resolveCast)',
    '    STATUS_WATERBREATHING,   // R320: the druid spell mark',
    '                             // (the breath fold)',
    '    STATUS_COUNT',
])
clean(SE_OLD, 78)
clean(SE_NEW, 78)

p = 'spelleffects/spelleffects.h'
s = rd(p)
if 'STATUS_WATERBREATHING,' in s:
    already.append('spelleffects.h: the breath kind')
else:
    assert s.count(SE_OLD) == 1, 'enum anchor not unique'
    s = s.replace(SE_OLD, SE_NEW, 1)
    wr(p, s)
    applied.append('spelleffects.h: the breath kind')

s = rd(p)
assert s.count('STATUS_WATERBREATHING,') == 1, 'b kind'
assert s.count('STATUS_LIGHT,') == 1, 'b light intact'
assert s.count('STATUS_COUNT') == 1, 'b count intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) spelleffects.cpp: the name row ----
SN_OLD = NL.join([
    '    ' + DQ + 'Fire Shield' + DQ + ', ' + DQ +
    'Antivenom' + DQ + ', ' + DQ + 'Polymorphed' + DQ + ', ' +
    DQ + 'Entrapped' + DQ + ',',
    '    ' + DQ + 'Lit' + DQ,
    '};',
])
SN_NEW = NL.join([
    '    ' + DQ + 'Fire Shield' + DQ + ', ' + DQ +
    'Antivenom' + DQ + ', ' + DQ + 'Polymorphed' + DQ + ', ' +
    DQ + 'Entrapped' + DQ + ',',
    '    ' + DQ + 'Lit' + DQ + ',',
    '    ' + DQ + 'Breathing' + DQ,
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
assert s.count(DQ + 'Breathing' + DQ) == 1, 'c name'
assert s.count(DQ + 'Lit' + DQ + ',') == 1, 'c lit intact'
assert s.count('kStatusNames') == 2, 'c array intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) spelleffects.cpp: the spell case ----
LC_OLD = NL.join([
    '            case spells::IL_LIGHT:',
    '                r = resolveStatusSpell(dice, s, STATUS_LIGHT,',
    '                                       s.durationRounds, t, false);',
    '                break;',
])
LC_NEW = NL.join([
    '            case spells::IL_LIGHT:',
    '                r = resolveStatusSpell(dice, s, STATUS_LIGHT,',
    '                                       s.durationRounds, t, false);',
    '                break;',
    '            // R320: the druid water breathing -',
    '            // the status mark (the row saves not,',
    '            // 60 rounds); the breath fold rides',
    '            // resolveCast. The airy water, shape',
    '            // change and wish variants stay',
    '            // recorded (not in the registry).',
    '            case spells::DR_WATER_BREATHING:   // R320',
    '                r = resolveStatusSpell(',
    '                    dice, s, STATUS_WATERBREATHING,',
    '                    s.durationRounds, t, false);',
    '                break;',
])
clean(LC_OLD, 78)
clean(LC_NEW, 78)

p = 'spelleffects/spelleffects.cpp'
s = rd(p)
if s.count('case spells::DR_WATER_BREATHING:') == 1:
    already.append('spelleffects.cpp: the spell case')
else:
    assert s.count(LC_OLD) == 1, 'case anchor not unique'
    s = s.replace(LC_OLD, LC_NEW, 1)
    wr(p, s)
    applied.append('spelleffects.cpp: the spell case')

s = rd(p)
assert s.count(
    'case spells::DR_WATER_BREATHING:') == 1, 'd case'
assert s.count('case spells::IL_LIGHT:') == 1, 'd light intact'
assert s.count('STATUS_WATERBREATHING,') == 1, 'd status'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) actor.h: the breath seam ----
BG_OLD = NL.join([
    '    // R319: the company light - a party light',
    '    // spell in the water fight lifts the sight',
    '    // (the resolveCast fold).',
    '    bool lightActive() const { return m_lightActive; }',
])
BG_NEW = NL.join([
    '    // R319: the company light - a party light',
    '    // spell in the water fight lifts the sight',
    '    // (the resolveCast fold).',
    '    bool lightActive() const { return m_lightActive; }',
    '    // R320: the company breath - a party water',
    '    // breathing spell in the water fight marks',
    '    // the company (the resolveCast fold; no',
    '    // drowning site exists - the print is the',
    '    // charge).',
    '    bool breathActive() const { return m_breathActive; }',
])
clean(BG_OLD, 78)
clean(BG_NEW, 78)

BM_OLD = NL.join([
    '    bool m_lightActive = false;   // R319: the light',
])
BM_NEW = NL.join([
    '    bool m_lightActive = false;   // R319: the light',
    '    bool m_breathActive = false;   // R320: the breath',
])
clean(BM_OLD, 78)
clean(BM_NEW, 78)

p = 'ai/actor.h'
s = rd(p)
if 'breathActive() const' in s:
    already.append('actor.h: the breath seam')
else:
    assert s.count(BG_OLD) == 1, 'getter anchor not unique'
    s = s.replace(BG_OLD, BG_NEW, 1)
    assert s.count(BM_OLD) == 1, 'member anchor not unique'
    s = s.replace(BM_OLD, BM_NEW, 1)
    wr(p, s)
    applied.append('actor.h: the breath seam')

s = rd(p)
assert s.count(
    'breathActive() const { return m_breathActive; }') == 1, (
    'e getter')
assert s.count('m_breathActive = false;') == 1, 'e member'
assert s.count('lightActive() const') == 1, 'e light intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch e balance'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) actor.cpp: the resolveCast breath fold ----
RC_OLD = NL.join([
    '                std::to_string(m_visionFt) +',
    '                ' + DQ + ' feet.' + DQ + ');',
    '    }',
    '}',
])
RC_NEW = NL.join([
    '                std::to_string(m_visionFt) +',
    '                ' + DQ + ' feet.' + DQ + ');',
    '    }',
    '',
    '    // R320: the breath fold - the druid water',
    '    // breathing spell in a water fight marks',
    '    // the company (the R311 recorded-notes',
    '    // charge; no drowning site exists - the',
    '    // print IS the charge, the R319 light',
    '    // pattern).',
    '    if (id == spells::DR_WATER_BREATHING &&',
    '        caster.team == 0 && m_waterFight &&',
    '        !m_breathActive) {',
    '        m_breathActive = true;',
    '        logLine(' + DQ + 'The company breathes water' + DQ,
    '                ' + DQ + ' freely!' + DQ + ');',
    '    }',
    '}',
])
cleanNB(RC_OLD, 78)
cleanNB(RC_NEW, 78)

p = 'ai/actor.cpp'
s = rd(p)
if s.count('breathes water') == 1:
    already.append('actor.cpp: the breath fold')
else:
    assert s.count(RC_OLD) == 1, 'fold anchor not unique'
    s = s.replace(RC_OLD, RC_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the breath fold')

s = rd(p)
assert s.count('breathes water') == 1, 'f print'
assert s.count('m_breathActive = true;') == 1, 'f mark'
assert s.count('The light carries') == 1, 'f light intact'
assert s.count('DR_WATER_BREATHING &&') == 1, 'f gate'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch f balance'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) party.h: the draught field and claim ----
HF_OLD = NL.join([
    '    bool uwHelm = false;',
])
HF_NEW = NL.join([
    '    bool uwHelm = false;',
    '    // R320: the Potion of Water Breathing held',
    '    // (the claim layer; the pool fight print)',
    '    bool uwDraught = false;',
])
clean(HF_OLD, 78)
clean(HF_NEW, 78)

CH_OLD = NL.join([
    '    c.uwHelm = true;',
    '    return true;',
    '}',
])
CH_NEW = NL.join([
    '    c.uwHelm = true;',
    '    return true;',
    '}',
    '',
    '// --------------------------------------------------------------------------',
    '// R320: claim a Potion of Water Breathing for a',
    '// member (the claimUwHelm pattern) - one draught',
    '// per member, the first living taker wins; every',
    '// other misc stays appraised.',
    '// --------------------------------------------------------------------------',
    'inline bool claimUwDraught(Character& c,',
    '                           const std::string& name,',
    '                           int qty) {',
    '    if (c.hp <= 0 || qty != 1 || c.uwDraught)',
    '        return false;',
    '    if (name.find(' + DQ + 'Potion of Water Breathing' + DQ +
    ') ==',
    '        std::string::npos)',
    '        return false;',
    '    c.uwDraught = true;',
    '    return true;',
    '}',
])
clean(CH_OLD, 78)
clean(CH_NEW, 78)
assert Q not in CH_NEW, 'g apostrophe'

p = 'game/party.h'
s = rd(p)
if 'claimUwDraught' in s:
    already.append('party.h: the draught field and claim')
else:
    assert s.count(HF_OLD) == 1, 'field anchor not unique'
    s = s.replace(HF_OLD, HF_NEW, 1)
    assert s.count(CH_OLD) == 1, 'claim anchor not unique'
    s = s.replace(CH_OLD, CH_NEW, 1)
    wr(p, s)
    applied.append('party.h: the draught field and claim')

s = rd(p)
assert s.count(
    'inline bool claimUwDraught(') == 1, 'g helper'
assert s.count('bool uwDraught = false;') == 1, 'g field'
assert s.count('c.uwHelm = true;') == 1, 'g helm intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch g balance'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- (h) state_core.cpp: the save and load ----
SV_OLD = NL.join([
    '            if (c.uwHelm)',
    '                fprintf(f, ' + DQ + 'uwhelm 1' + BS + 'n' + DQ + ');',
])
SV_NEW = NL.join([
    '            if (c.uwHelm)',
    '                fprintf(f, ' + DQ + 'uwhelm 1' + BS + 'n' + DQ + ');',
    '            // R320: the draught (held only - v1',
    '            // saves carry no line and load',
    '            // without it)',
    '            if (c.uwDraught)',
    '                fprintf(f, ' + DQ + 'uwdraught 1' + BS + 'n' +
    DQ + ');',
])
cleanNB(SV_OLD, 78)
cleanNB(SV_NEW, 78)

LD_OLD = NL.join([
    '                    c.uwHelm = uh != 0;',
    '                } else if',
])
LD_NEW = NL.join([
    '                    c.uwHelm = uh != 0;',
    '                } else if (strcmp(tag, ' + DQ +
    'uwdraught' + DQ + ') == 0) {',
    '                    int ud = 0;',
    '                    if (fscanf(f, ' + DQ + '%d' + DQ +
    ', &ud) != 1 ||',
    '                        ud < 0 || ud > 1) {',
    '                        fclose(f);',
    '                        log.add(' + DQ +
    'adnd1.sav is corrupt (draught).' + DQ + ');',
    '                        return false;',
    '                    }',
    '                    c.uwDraught = ud != 0;',
    '                } else if',
])
cleanNB(LD_OLD, 78)
cleanNB(LD_NEW, 78)

p = 'game/state_core.cpp'
s = rd(p)
if 'uwdraught' in s:
    already.append('state_core.cpp: the save and load')
else:
    assert s.count(SV_OLD) == 1, 'save anchor not unique'
    s = s.replace(SV_OLD, SV_NEW, 1)
    assert s.count(LD_OLD) == 1, 'load anchor not unique'
    s = s.replace(LD_OLD, LD_NEW, 1)
    wr(p, s)
    applied.append('state_core.cpp: the save and load')

s = rd(p)
assert s.count('uwdraught') == 2, 'h lines'
assert s.count('c.uwDraught') == 2, 'h flags'
assert s.count('c.uwHelm = uh != 0;') == 1, 'h helm intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch h balance'
assert len(applied) + len(already) == 8, 'patch h count wrong'

# ---- (i) state_dungeon.cpp: the claim route ----
DR_OLD = NL.join([
    '                            // R319: the Helm of Underwater',
    '                            // Action - the carried light for',
    '                            // the deep (the claimRing',
])
DR_NEW = NL.join([
    '                            // R320: the Potion of Water',
    '                            // Breathing - the carried',
    '                            // draught (the claimUwHelm',
    '                            // pattern); the pool fight',
    '                            // print charges it',
    '                            if (claimUwDraught(c, mi.name,',
    '                                              mi.qty)) {',
    '                                snprintf(buf, sizeof buf,',
    '                                         ' + DQ +
    '%s pockets the %s!' + DQ + ',',
    '                                         c.name.c_str(),',
    '                                         mi.name.c_str());',
    '                                log.add(buf);',
    '                                take = true;',
    '                                break;',
    '                            }',
    '                            // R319: the Helm of Underwater',
    '                            // Action - the carried light for',
    '                            // the deep (the claimRing',
])
clean(DR_OLD, 78)
clean(DR_NEW, 78)
assert Q not in DR_NEW, 'i apostrophe'

p = 'game/state_dungeon.cpp'
s = rd(p)
if 'claimUwDraught(c, mi.name,' in s:
    already.append('state_dungeon.cpp: the claim route')
else:
    assert s.count(DR_OLD) == 1, 'route anchor not unique'
    s = s.replace(DR_OLD, DR_NEW, 1)
    wr(p, s)
    applied.append('state_dungeon.cpp: the claim route')

s = rd(p)
assert s.count(
    'claimUwDraught(c, mi.name,') == 1, 'i route'
assert s.count('pockets the %s!') == 1, 'i print'
assert s.count(
    'claimUwHelm(c, mi.name,') == 1, 'i helm intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch i balance'
assert len(applied) + len(already) == 9, 'patch i count wrong'

# ---- (j) state_combat.cpp: the pool print ----
CB_OLD = NL.join([
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
])
CB_NEW = NL.join([
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
    '            // R320: the breathing aids - the',
    '            // carried draught holds (the claim',
    '            // layer); the spell fold rides',
    '            // resolveCast (the R319 light',
    '            // pattern); no drowning site',
    '            // exists - the print is the charge',
    '            for (const auto& c : party.members)',
    '                if (c.hp > 0 && c.uwDraught) {',
    '                    log.add(' + DQ +
    'The draught of water breathing' + DQ,
    '                            ' + DQ + ' holds.' + DQ + ');',
    '                    break;',
    '                }',
])
clean(CB_OLD, 78)
clean(CB_NEW, 78)
assert Q not in CB_NEW, 'j apostrophe'

p = 'game/state_combat.cpp'
s = rd(p)
if 'draught of water breathing' in s:
    already.append('state_combat.cpp: the pool print')
else:
    assert s.count(CB_OLD) == 1, 'print anchor not unique'
    s = s.replace(CB_OLD, CB_NEW, 1)
    wr(p, s)
    applied.append('state_combat.cpp: the pool print')

s = rd(p)
assert s.count(
    'draught of water breathing') == 1, 'j print'
assert s.count(
    'Infravision reaches %d feet') == 1, 'j infra intact'
assert s.count('c.uwHelm) {') == 1, 'j helm fold intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch j balance'
assert len(applied) + len(already) == 10, 'patch j count wrong'

# ---- (k) underwater.h: the recorded-notes truth-up ----
UN_OLD = NL.join([
    '// RECORDED NOTES (ride the pin, not data): the',
    '// breathing aids (the water breathing, airy',
    '// water, shape change and wish spells; the',
    '// potion; the helm of underwater action and',
    '// the cloak of the manta ray), the one',
])
UN_NEW = NL.join([
    '// RECORDED NOTES (ride the pin, not data): the',
    '// breathing aids (the airy water, shape',
    '// change and wish spells; the cloak of the',
    '// manta ray - the water breathing spell, the',
    '// potion and the helm now charge the R319/',
    '// R320 seams), the one',
])
clean(UN_OLD, 78)
clean(UN_NEW, 78)

p = 'rules/underwater.h'
s = rd(p)
if 'R319/' + NL + '// R320 seams' in s:
    already.append('underwater.h: the truth-up')
else:
    assert s.count(UN_OLD) == 1, 'notes anchor not unique'
    s = s.replace(UN_OLD, UN_NEW, 1)
    wr(p, s)
    applied.append('underwater.h: the truth-up')

s = rd(p)
assert s.count('R320 seams') == 1, 'k truth'
assert s.count('manta ray - the water') == 1, (
    'k charge note')
assert s.count('RECORDED NOTES') == 1, 'k notes intact'
assert len(applied) + len(already) == 11, 'patch k count wrong'

# ---- (l) regtest.cpp: the R320 audit ----
BSN = BS + 'n'
RT_OLD = NL.join([
    '        printf(' + DQ +
    'R319 underwater vision multiples audit: bad %d' + BSN + DQ +
    ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_NEW = NL.join([
    '        printf(' + DQ +
    'R319 underwater vision multiples audit: bad %d' + BSN + DQ +
    ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R320: the breathing aids audit ----',
    '    // The R311 recorded-notes charge: the',
    '    // druid Water Breathing (the status at',
    '    // the engine, the row saves not) and',
    '    // the III.A potion (the claim layer).',
    '    // No drowning site exists - the prints',
    '    // are the charge. Draw-independent: the',
    '    // row saves not, the folds read pins.',
    '    {',
    '        int bad = 0;',
    '        // B1: the status - the spell engine',
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
    '                    d, spells::DR_WATER_BREATHING,',
    '                    5, ds);',
    '            if (r1.perTarget.size() != 1) ++bad;',
    '            if (!r1.perTarget.empty() &&',
    '                r1.perTarget[0].status.kind !=',
    '                    spelleffects::',
    '                    STATUS_WATERBREATHING)',
    '                ++bad;',
    '        }',
    '        // B2: the cast fold - a party cast in',
    '        // the water fight marks the company',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.team = 0;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.classIndex = 4; a.level = 5;',
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
    '            enc.setWaterFight();',
    '            enc.resolveCast(',
    '                enc.partyMutable()[0],',
    '                spells::DR_WATER_BREATHING);',
    '            if (!enc.breathActive()) ++bad;',
    '            bool br = false;',
    '            for (const auto& ln : enc.log())',
    '                if (ln.text.find(' + DQ +
    'breathes water freely' + DQ + ') !=',
    '                    std::string::npos)',
    '                    br = true;',
    '            if (!br) ++bad;',
    '            // the slot spent',
    '            if (enc.partyMutable()[0]',
    '                    .slotsByLevel[2] != 0) ++bad;',
    '        }',
    '        // B3: the dry gate - no water fight,',
    '        // no mark, no print',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.team = 0;',
    '            a.name = ' + DQ + 'Heroa' + DQ + ';',
    '            a.classIndex = 4; a.level = 5;',
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
    '                spells::DR_WATER_BREATHING);',
    '            if (enc.breathActive()) ++bad;',
    '            bool br = false;',
    '            for (const auto& ln : enc.log())',
    '                if (ln.text.find(' + DQ +
    'breathes water freely' + DQ + ') !=',
    '                    std::string::npos)',
    '                    br = true;',
    '            if (br) ++bad;',
    '        }',
    '        // B4: the claim (the claimUwHelm',
    '        // pattern)',
    '        {',
    '            Character c;',
    '            c.hp = 10;',
    '            if (!claimUwDraught(',
    '                    c, ' + DQ + 'Potion of Water Breathing' + DQ +
    ',',
    '                    1)) ++bad;',
    '            if (!c.uwDraught) ++bad;',
    '            // one draught per member',
    '            if (claimUwDraught(',
    '                    c, ' + DQ + 'Potion of Water Breathing' + DQ +
    ',',
    '                    1)) ++bad;',
    '            c.uwDraught = false;',
    '            // other potions never claim',
    '            if (claimUwDraught(',
    '                    c, ' + DQ + 'Potion of Healing' + DQ + ',',
    '                    1)) ++bad;',
    '            // bundles never claim',
    '            if (claimUwDraught(',
    '                    c, ' + DQ + 'Potion of Water Breathing' + DQ +
    ',',
    '                    2)) ++bad;',
    '            // the dead claim nothing',
    '            c.hp = 0;',
    '            if (claimUwDraught(',
    '                    c, ' + DQ + 'Potion of Water Breathing' + DQ +
    ',',
    '                    1)) ++bad;',
    '        }',
    '        // B5: the pool print - the carried',
    '        // draught holds at the water fight',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            st.party.formed = true;',
    '            Character arc;',
    '            arc.name = ' + DQ + 'Arc' + DQ + ';',
    '            arc.classIndex = 0; arc.level = 1;',
    '            arc.race = 0;',
    '            arc.hp = 30; arc.maxHp = 30;',
    '            arc.uwDraught = true;',
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
    '            bool dp = false;',
    '            for (int i = 0; i < 5; ++i)',
    '                if (st.log.get(i).find(' + DQ +
    'draught of water breathing' + DQ + ') !=',
    '                    std::string::npos)',
    '                    dp = true;',
    '            if (!dp) ++bad;',
    '        }',
    '        // B6: the name array - every kind',
    '        // names (the R319 shortfall pinned)',
    '        {',
    '            for (int k = 0;',
    '                 k < (int)spelleffects::STATUS_COUNT;',
    '                 ++k)',
    '                if (spelleffects::statusName(',
    '                        (spelleffects::StatusKind)k)',
    '                    == nullptr) ++bad;',
    '            if (spelleffects::statusName(',
    '                    spelleffects::STATUS_WATERBREATHING)',
    '                != ' + DQ + 'Breathing' + DQ + ') ++bad;',
    '        }',
    '        printf(' + DQ +
    'R320 breathing aids audit: bad %d' + BSN + DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
cleanNB(RT_OLD, 76)
cleanNB(RT_NEW, 76)

p = 'regtest.cpp'
s = rd(p)
if 'R320 breathing aids audit' in s:
    already.append('regtest.cpp: the R320 audit')
else:
    assert s.count(RT_OLD) == 1, 'audit anchor not unique'
    s = s.replace(RT_OLD, RT_NEW, 1)
    wr(p, s)
    applied.append('regtest.cpp: the R320 audit')

s = rd(p)
assert s.count('R320 breathing aids audit') == 1, 'l audit'
assert s.count('audit: bad') == 247, 'l census'
assert s.count(
    'R319 underwater vision multiples audit') == 1, (
    'l r319 intact')
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch l balance'
assert len(applied) + len(already) == 12, 'patch l count wrong'

# ---- (m) dmg_gap_report.md: the chronicle ----
GP = 'tools/dmg_gap_report.md'
GC_OLD = NL.join([
    'moves 245 -> 246 with the R319',
    'audit.',
    '',
    'Categories:',
])
GC_NEW = NL.join([
    'moves 245 -> 246 with the R319',
    'audit.',
    '',
    'R320 the breathing aids: the R311',
    'recorded-notes charge - the druid',
    'water breathing spell (a new',
    'STATUS_WATERBREATHING at the',
    'engine, the resolveCast fold in',
    'the water fight - the R319 light',
    'pattern) and the III.A potion (the',
    'claim layer, the R319 helm',
    'pattern, the uwdraught save line;',
    'no drowning site exists - the',
    'prints are the charge). The mud',
    'cloud (d6+6 rounds after the',
    'movement stops - no movement-',
    'stop notion) and the seaweed/',
    'shoal reducers (no seaweed or',
    'shoal tile) stay recorded. The',
    'census moves 246 -> 247 with the',
    'R320 audit.',
    '',
    'Categories:',
])
clean(GC_OLD, 57, gap=True)
clean(GC_NEW, 57, gap=True)

s = rd(GP)
if 'R320 the breathing aids' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(GC_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(GC_OLD, GC_NEW, 1)
    wr(GP, s)
    applied.append('dmg report: the chronicle')

s = rd(GP)
assert s.count('R320 the breathing aids') == 1, 'm entry'
assert s.count('Categories:') == 1, 'm legend head'
assert s.count('moves 246 -> 247') == 1, 'm census'
assert s.count('moves 245 -> 246') == 1, 'm r319 intact'
assert len(applied) + len(already) == 13, 'patch m count wrong'

# ---- R320 tail ----
if len(applied) + len(already) != 13:
    print('R320 splice: FAIL - expected 13 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R320 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R320 note: 13 patches; the breathing')
print('aids charge (the druid spell and the')
print('potion; the R319 seed entry rides as')
print('the first patch); the battery census')
print('moves 246 -> 247')
print('commit: R320: the breathing aids')
print('(census 247)')

