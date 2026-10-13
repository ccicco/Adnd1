#!/usr/bin/env python3
# R400: the UA comeliness site -
# the deferred seam closes. The
# gap report's comeliness item (a
# Character field, the reaction
# callers) wires the R322 and
# R117 pins:
#
# 1. rules/comeliness.h: the
#    site layer - the score
#    helper (the raw 3d6 base
#    roll + the charisma ladder;
#    the point-for-point coupling
#    rides the CURRENT cha), the
#    viewed-score helper (the
#    same-race pairs read 0), the
#    monster-viewer read (the
#    parley gate has no CharRace
#    for the viewer - the
#    viewed-race adjustment always
#    rides), and the
#    initial-contact reaction
#    adjustment (the percent of
#    the VIEWED score: 100/150/
#    200 - the print's "22
#    comeliness equals +44%").
# 2. game/party.h: the Character
#    field - the raw 3d6 base
#    roll, 0 = unknown (the
#    v1-save read), the optional
#    "uacom" save line.
# 3. game/state_core.cpp: the
#    save writer (only when
#    known) and the load tag
#    (3-18, corrupt otherwise).
# 4. game/appstate.h: the
#    creation roll - 3d6 after
#    the six attributes
#    (rollFresh), riding the
#    member (makeMember).
# 5. game/state_dungeon.cpp +
#    game/state_combat.cpp: the
#    two parley-gate reaction
#    callers - the best-living
#    spokesman (R58) now reads
#    the combined charisma +
#    comeliness initial-contact
#    adjustment. The
#    party-meeting and hire
#    loops stay charisma-only
#    (they read the R62 engines,
#    not the R117 table). The
#    fascinate power, the order
#    roll and the illusion cap
#    stay pinned data (they gate
#    on a fascinate site).
# 6. regtest.cpp: a new R400
#    audit block before the R227
#    anchor; census 326 -> 327.
# 7. tools/ua_gap_report.md: the
#    comeliness seam checkbox and
#    the DEFERRED item close.
# 8. The seed takes the R399
#    record.
import io

NL = chr(10)

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def E(*lines):
    return NL.join(lines)


def die(msg):
    raise SystemExit(
        'R400 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


# ================= (a) the seed =================
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'

SEED_ENTRY = E(
    '- R399 landed 2026-10-13:',
    '  commit 5433fe5 (census 326,',
    '  preflight GREEN), the UA',
    '  armor swords misc weapons',
    '  flagged holes completion:',
    '  the clean pp. 104-106 read',
    '  fills the last seven flagged',
    '  holes (uaasp 4/4 -> 8/0,',
    '  uamw 6/3 -> 9/0) - the ECM',
    '  size table row-one label and',
    '  height cells, the plate',
    '  conform parenthetical, the',
    '  sun blade radiance, the Final',
    '  Word nine appellations, the',
    '  axe of hurling tail, the',
    '  dagger of throwing ranges and',
    '  the hornblade handle. All',
    '  PDF-gated prose now stands',
    '  closed; the deferred seams',
    '  remain.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R399 landed 2026-10-13' in s:
    already.append('seed: the R399 record')
else:
    if s.count(ANCH) != 1:
        die('the seed anchor count %d'
            % s.count(ANCH))
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R399 record')
s = rd(SD)
if s.count('R399 landed 2026-10-13') != 1:
    die('the R399 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/comeliness.h =========
CM = 'rules/comeliness.h'

pair(CM, E(
    '// Pinned data only - no engine site exists',
    '// (no comeliness field; the reaction layer',
    '// itself has no callers) - the R311 pin-era',
    '// pattern: pin now, wire when a site exists.'),
    E(
    '// Pinned data only - no engine site exists',
    '// (no comeliness field; the reaction layer',
    '// itself has no callers) - the R311 pin-era',
    '// pattern: pin now, wire when a site exists.',
    '// R400: the site exists now - the',
    '// Character field, the creation roll',
    '// and the parley-gate reaction',
    '// callers read these pins. The',
    '// fascinate power, the order roll and',
    '// the illusion cap stay pinned data',
    '// (they gate on a fascinate site).'),
    'comeliness: the header note')

pair(CM, E(
    'inline int uaComelinessOrderDieCount()',
    '    { return 3; }',
    'inline int uaComelinessOrderDieSides()',
    '    { return 6; }',
    '',
    '}'),
    E(
    'inline int uaComelinessOrderDieCount()',
    '    { return 3; }',
    'inline int uaComelinessOrderDieSides()',
    '    { return 6; }',
    '',
    '// ---- R400: the site layer ----',
    '//',
    '// The score: the raw 3d6 base roll',
    '// (0 = unknown, the v1-save read)',
    '// plus the charisma ladder. The',
    '// point-for-point coupling rides the',
    '// CURRENT charisma - a cha change',
    '// moves the score the same distance.',
    'inline int uaComelinessScore(',
    '    int baseRoll, int cha) {',
    '    if (baseRoll <= 0) return 0;',
    '    return baseRoll',
    '        + uaComelinessChaAdj(cha);',
    '}',
    '',
    '// The viewed score for a viewer race:',
    '// the same-race pairs read 0 (the',
    "// print's halfling/human and",
    '// sylvan-elf/half-elf pairs), every',
    "// other viewer reads the viewed race's",
    '// cell. (The print\'s dwarf example -',
    '// base 9, cha 16 - reads 11; its own',
    '// "at 8" cell is loose arithmetic.)',
    'inline int uaComelinessEffective(',
    '    int score, CharRace viewed,',
    '    CharRace viewer) {',
    '    if (score <= 0) return 0;',
    '    if (viewed == viewer) return score;',
    '    if ((viewed == RACE_HUMAN',
    '         && viewer == RACE_HALFLING)',
    '        || (viewed == RACE_HALFLING',
    '            && viewer == RACE_HUMAN)',
    '        || (viewed == RACE_HALF_ELF',
    '            && viewer == RACE_ELF)',
    '        || (viewed == RACE_ELF',
    '            && viewer == RACE_HALF_ELF))',
    '        return score;',
    '    return score',
    '        + uaComelinessRacialAdj(viewed);',
    '}',
    '',
    '// The monster-viewer read: the parley',
    '// gate has no CharRace for the viewer,',
    '// so the viewed-race adjustment always',
    '// rides (a monster is of another race',
    '// by the site convention).',
    'inline int uaComelinessScoreOtherRace(',
    '    int baseRoll, int cha,',
    '    CharRace viewed) {',
    '    int s = uaComelinessScore(baseRoll, cha);',
    '    if (s <= 0) return 0;',
    '    return s',
    '        + uaComelinessRacialAdj(viewed);',
    '}',
    '',
    '// The initial-contact reaction',
    '// adjustment: the percent of the',
    '// VIEWED comeliness score - 100 at',
    '// +14 to +17, 150 at +18 to +21, 200',
    '// at +22 and up (the print: "22',
    '// comeliness equals +44%"). The bands',
    '// below interest carry no percentile -',
    '// the band text carries the effect.',
    'inline int uaComelinessReactionAdj(',
    '    int viewedScore) {',
    '    if (viewedScore <= 13) return 0;',
    '    return viewedScore',
    '        * uaComelinessReactionPct(',
    '              viewedScore) / 100;',
    '}',
    '',
    '}'),
    'comeliness: the site layer')

# ========= (c) game/party.h =========
PY = 'game/party.h'

pair(PY, E(
    '    bool female = false;',
    '    int  classIndex = 0;'),
    E(
    '    bool female = false;',
    '    // R400: the UA comeliness base roll',
    '    // (the R322 pins wired - the seventh',
    '    // attribute, 3d6 after the six). 0 =',
    '    // unknown (v1 saves carry no line and',
    '    // load as 0). Optional "uacom" line in',
    '    // the save. The effective score',
    '    // computes on demand: base + the',
    '    // charisma ladder (the point-for-point',
    '    // coupling rides the current cha) +',
    '    // the viewed-race adjustment (the',
    '    // reaction caller passes the viewer).',
    '    int  uaComBase = 0;',
    '    int  classIndex = 0;'),
    'party: the uaComBase field')

# ======== (d) game/state_core.cpp ========
SC = 'game/state_core.cpp'

pair(SC, E(
    '            // R325: the UA sub-race (only when set -',
    '            // v1 saves carry no line and load as none)',
    '            if (c.uaSubrace != 0)',
    '                fprintf(f, "uasub %d' + chr(92) + 'n",',
    '                        c.uaSubrace);'),
    E(
    '            // R325: the UA sub-race (only when set -',
    '            // v1 saves carry no line and load as none)',
    '            if (c.uaSubrace != 0)',
    '                fprintf(f, "uasub %d' + chr(92) + 'n",',
    '                        c.uaSubrace);',
    '            // R400: the comeliness base roll',
    '            // (only when known - v1 saves',
    '            // carry no line and load as 0)',
    '            if (c.uaComBase != 0)',
    '                fprintf(f, "uacom %d' + chr(92) + 'n",',
    '                        c.uaComBase);'),
    'save: the uacom line')

pair(SC, E(
    '                    c.uaSubrace = us;',
    '                } else if (strcmp(tag, "fem") == 0) {'),
    E(
    '                    c.uaSubrace = us;',
    '                } else if (strcmp(tag, "uacom") == 0) {',
    '                    int cb = 0;',
    '                    if (fscanf(f, "%d", &cb) != 1 ||',
    '                        cb < 3 || cb > 18) {',
    '                        fclose(f);',
    '                        log.add("adnd1.sav is corrupt (uacom).");',
    '                        return false;',
    '                    }',
    '                    c.uaComBase = cb;',
    '                } else if (strcmp(tag, "fem") == 0) {'),
    'load: the uacom tag')

# ========= (e) game/appstate.h =========
AS = 'game/appstate.h'

pair(AS, '    std::string nameBuf;',
    E('    int  uaComRoll = 0;              // R400: the comeliness base',
      '    std::string nameBuf;'),
    'appstate: the uaComRoll field')

pair(AS, E(
    '        rolled = rules::rollAbilities(creationDice,',
    '                                      rules::GEN_4D6_DROP);',
    '        stage = CR_ROLL;'),
    E(
    '        rolled = rules::rollAbilities(creationDice,',
    '                                      rules::GEN_4D6_DROP);',
    '        // R400: the UA comeliness base',
    '        // roll - 3d6 after the six',
    '        // attributes (the R322 pin)',
    '        uaComRoll = (int)creationDice.roll(',
    '            3, 6, 0);',
    '        stage = CR_ROLL;'),
    'appstate: the rollFresh roll')

pair(AS, E(
    '        c.abilities = raceAdjusted();   // R154: adjusted is actual',
    '        c.classIndex = classIndex;'),
    E(
    '        c.abilities = raceAdjusted();   // R154: adjusted is actual',
    '        // R400: the UA comeliness base',
    '        // roll rides the member (the raw',
    '        // 3d6; the effective score computes',
    '        // at the reaction callers)',
    '        c.uaComBase = uaComRoll;',
    '        c.classIndex = classIndex;'),
    'appstate: the makeMember wiring')

# ===== (f) the parley-gate reaction callers =====
CALLER_OLD = E(
    '        int chaAdj = 0;',
    '        for (const auto& c : party.members) {',
    '            if (c.hp <= 0) continue;',
    '            int adj = rules::chaReactionAdj(c.abilities.cha);',
    '            if (adj > chaAdj) chaAdj = adj;',
    '        }',
    '        dm::Reaction react = dm::rollReaction(dice, chaAdj);')

CALLER_NEW = E(
    '        // R400: the comeliness site rides the',
    '        // spokesman - the initial-contact',
    '        // adjustment is the charisma ladder',
    '        // PLUS the comeliness percentile (the',
    '        // 100/150/200 read of the viewed',
    '        // score, the monster viewer of',
    '        // another race); the fascinate power',
    '        // and the order roll stay pinned',
    '        // data (no fascinate site)',
    '        int chaAdj = 0;',
    '        for (const auto& c : party.members) {',
    '            if (c.hp <= 0) continue;',
    '            int adj =',
    '                rules::chaReactionAdj(',
    '                    c.abilities.cha)',
    '                + rules::uaComelinessReactionAdj(',
    '                      rules::uaComelinessScoreOtherRace(',
    '                          c.uaComBase,',
    '                          c.abilities.cha,',
    '                          (rules::CharRace)c.race));',
    '            if (adj > chaAdj) chaAdj = adj;',
    '        }',
    '        dm::Reaction react = dm::rollReaction(dice, chaAdj);')

pair('game/state_dungeon.cpp', CALLER_OLD,
     CALLER_NEW,
     'state_dungeon: the parley gate')

pair('game/state_combat.cpp', CALLER_OLD,
     CALLER_NEW,
     'state_combat: the wandering gate')

# ========= (g) regtest.cpp =========
RT = 'regtest.cpp'

AUD = E(
    '    // ---- R400: the UA comeliness',
    '    // site audit ----',
    '    // The deferred seam closes: the',
    '    // Character field, the creation roll',
    '    // and the parley-gate reaction',
    '    // callers read the R322 pins. The',
    '    // save line and the load tag are',
    '    // splice-assert verified (the',
    '    // battery never writes adnd1.sav).',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // the score helper: the raw 3d6',
    '        // plus the charisma ladder; 0 =',
    '        // unknown reads 0 (the v1-save',
    '        // read); cha below 3 reads -8',
    '        if (uaComelinessScore(0, 12) != 0)',
    '            ++bad;',
    '        if (uaComelinessScore(3, 12) != 3)',
    '            ++bad;',
    '        if (uaComelinessScore(3, 3) != -2)',
    '            ++bad;',
    '        if (uaComelinessScore(3, 2) != -5)',
    '            ++bad;',
    '        if (uaComelinessScore(18, 18) != 21)',
    '            ++bad;',
    '        if (uaComelinessScore(18, 19) != 23)',
    '            ++bad;',
    '        // the print dwarf example (base',
    '        // 9, cha 16): the score reads 11',
    '        // (the print own at-8 cell is the',
    '        // loose arithmetic)',
    '        if (uaComelinessScore(9, 16) != 11)',
    '            ++bad;',
    '        // the viewed score: the same-race',
    '        // pairs read 0 (the print',
    '        // halfling/human and the',
    '        // sylvan-elf/half-elf pairs)',
    '        if (uaComelinessEffective(11, RACE_DWARF,',
    '                                 RACE_DWARF) != 11)',
    '            ++bad;',
    '        if (uaComelinessEffective(11, RACE_DWARF,',
    '                                 RACE_HUMAN) != 10)',
    '            ++bad;',
    '        if (uaComelinessEffective(11, RACE_HUMAN,',
    '                                 RACE_HALFLING) != 11)',
    '            ++bad;',
    '        if (uaComelinessEffective(11, RACE_HALFLING,',
    '                                 RACE_HUMAN) != 11)',
    '            ++bad;',
    '        if (uaComelinessEffective(11, RACE_HALF_ELF,',
    '                                 RACE_ELF) != 11)',
    '            ++bad;',
    '        if (uaComelinessEffective(11, RACE_ELF,',
    '                                 RACE_HALF_ELF) != 11)',
    '            ++bad;',
    '        if (uaComelinessEffective(11, RACE_HALF_ORC,',
    '                                 RACE_HUMAN) != 8)',
    '            ++bad;',
    '        // the unknown member views 0 (the',
    '        // v1-save read)',
    '        if (uaComelinessEffective(0, RACE_DWARF,',
    '                                 RACE_HUMAN) != 0)',
    '            ++bad;',
    '        // the monster-viewer read: the',
    '        // viewed-race adjustment always',
    '        // rides (the site convention)',
    '        if (uaComelinessScoreOtherRace(9, 16,',
    '                                      RACE_DWARF) != 10)',
    '            ++bad;',
    '        if (uaComelinessScoreOtherRace(9, 16,',
    '                                      RACE_HUMAN) != 11)',
    '            ++bad;',
    '        if (uaComelinessScoreOtherRace(0, 12,',
    '                                      RACE_ELF) != 0)',
    '            ++bad;',
    '        // the initial-contact percentile:',
    '        // 100 at 14-17, 150 at 18-21, 200',
    '        // at 22 and up (the print 22',
    '        // comeliness equals +44%); the',
    '        // bands below interest carry no',
    '        // percentile',
    '        if (uaComelinessReactionAdj(-5) != 0)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(10) != 0)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(13) != 0)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(14) != 14)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(16) != 16)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(17) != 17)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(18) != 27)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(21) != 31)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(22) != 44)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(25) != 50)',
    '            ++bad;',
    '        if (uaComelinessReactionAdj(26) != 52)',
    '            ++bad;',
    '        // ---- the cross-checks ----',
    '        // the stunning and unearthly',
    '        // ladders double the score',
    '        if (2 * 22 != uaComelinessReactionAdj(22))',
    '            ++bad;',
    '        if (2 * 26 != uaComelinessReactionAdj(26))',
    '            ++bad;',
    '        // the unknown member never moves',
    '        // a reaction',
    '        if (uaComelinessReactionAdj(',
    '                uaComelinessScore(0, 12)) != 0)',
    '            ++bad;',
    '        // ---- the wiring ----',
    '        // the creation roll rides the',
    '        // member; a fresh Character reads',
    '        // unknown (the v1-save read)',
    '        {',
    '            CreationState cr;',
    '            cr.rollFresh();',
    '            if (cr.uaComRoll < 3',
    '                || cr.uaComRoll > 18) ++bad;',
    '            Character c = cr.makeMember(0);',
    '            if (c.uaComBase != cr.uaComRoll)',
    '                ++bad;',
    '            Character d;',
    '            if (d.uaComBase != 0) ++bad;',
    '        }',
    '        printf("R400 UA comeliness site'
    ' audit: bad %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R400 audit block')

# ======== (h) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '- [ ] The comeliness site (a Character',
    '      field, the reaction callers) -',
    '      wires the R322 and R117 pins.'),
    E(
    '- [x] The comeliness site -',
    '      CLOSED R400: the Character field (the',
    '      raw 3d6 base roll, the optional',
    '      "uacom" save line, the v1-save 0',
    '      default), the creation roll',
    '      (rollFresh/makeMember), and the two',
    '      parley-gate reaction callers',
    '      (state_dungeon, state_combat - the',
    '      spokesman reads the combined',
    '      charisma + comeliness',
    '      initial-contact adjustment, the',
    '      100/150/200 percentile of the',
    '      viewed score, the monster viewer',
    '      of another race). The fascinate',
    '      power, the order roll and the',
    '      illusion cap stay pinned data',
    '      (they gate on a fascinate site).'),
    'gap: the comeliness seam')

pair(GP, E(
    '- DEFERRED: the comeliness ENGINE site',
    '  (no comeliness field on Character -',
    '  the R322 pins charge when the site',
    '  exists).'),
    E(
    '- CLOSED R400: the comeliness ENGINE',
    '  site - the Character field and the',
    '  reaction callers exist; the R322',
    '  pins are wired.'),
    'gap: the DEFERRED item')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 327:
    die('the census %d' % s.count('audit: bad'))
if s.count('R400 UA comeliness site'
           ' audit') != 1:
    die('the R400 audit label')
if s.count('uaComelinessScoreOtherRace') != 3:
    die('the other-race count %d'
        % s.count('uaComelinessScoreOtherRace'))
if s.count('uaComelinessReactionAdj') != 14:
    die('the reaction-adj count %d'
        % s.count('uaComelinessReactionAdj'))
if s.count('uaComelinessEffective') != 8:
    die('the effective count %d'
        % s.count('uaComelinessEffective'))

p = rd(CM)
if p.count('inline') != 16:
    die('the comeliness inline count %d'
        % p.count('inline'))
if not p.endswith(NL):
    die('the comeliness trailing newline')

for path, mark in ((PY, 'uaComBase'),
                   (AS, 'uaComRoll'),
                   (SC, 'uacom'),
                   ('game/state_dungeon.cpp',
                    'uaComeliness'),
                   ('game/state_combat.cpp',
                    'uaComeliness')):
    t = rd(path)
    if mark not in t:
        die('%s carries no R400 seam' % path)

g = rd(GP)
if g.count('CLOSED R400') != 2:
    die('the gap closed count %d'
        % g.count('CLOSED R400'))

print('R400 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the deferred seam closes - the')
print('  comeliness Character field, the')
print('  creation roll and the parley-gate')
print('  reaction callers wire the R322')
print('  pins; census 326 -> 327')
print('commit: R400: the UA comeliness site'
      ' (census 327)')

