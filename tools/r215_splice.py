#!/usr/bin/env python3
# R215 splice: the conducting the game pins -
# DMG pp.110-112, the CONDUCTING THE GAME
# chapter: the divine intervention procedure
# (the 10 percent creature-sent chance for the
# exemplary first-time asker, the 00 roll with
# the level-equals-chance deity arrival, the
# six modifiers - each previous intervention
# stacking -5, medial alignment -5, borderline
# -10, required direct confrontation -10,
# opposing diametric forces +1, proximate
# service +25), the planes rule (Prime
# Material, Astral and Ethereal yes; Elemental
# DM option; Outer, Positive and Negative no),
# the secret dice-roll list (7 kinds), the
# system shock untouchability, the player
# integration numbers (the d4+1 averaging die
# 2-5, the 8th-level ceiling, the 4th-level
# start above it, the neophyte full-cooperation
# level), the multiple characters rules, and
# the troublesome-player measures. Mostly a
# prose chapter - the pin material is the
# intervention table and the numeric
# conventions. The Boot Hill / Gamma World
# conversion tables (pp.112-114) remain OUT by
# design. Patches: 4 (new rules/conduct.h,
# regtest include, audit block, gap-report log
# entry). Census 130 -> 131.

BS = chr(92)
NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique;
    # old = None means the new-file form
    global applied, already
    try:
        t = rd(path)
    except IOError:
        # the file does not exist: create it
        assert old is None, 'anchor patch on absent file: ' + marker
        assert marker in new, 'marker missing in new file: ' + marker
        wr(path, new)
        applied += 1
        return
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/conduct.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
'// ====================================================================',
'// Adnd1 - rules/conduct.h',
'// R215: the conducting the game pins (DMG',
'// pp.110-112) - the divine intervention',
'// procedure and planes rule, the secret',
'// dice-roll list, the system shock clause,',
'// the player integration numbers, the',
'// multiple characters rules, and the',
'// troublesome-player measures.',
'//',
'// Pure data + helpers, header-only (the',
'// grenade.h pattern: the caller owns the',
'// dice, the actual beseeching and the',
'// campaign milieu; the procedure and the',
'// numeric conventions read here).',
'//',
'// Conventions and judgments, named in',
'// place:',
'//   - Divine intervention: a character',
'//     exemplary in faithfulness asking for',
'//     the FIRST time gets a straight 10',
'//     percent chance that some creature is',
'//     sent to aid. If 00 is rolled, the',
'//     chance that the deity ITSELF comes',
'//     equals the character level of',
'//     experience, modified by the six',
'//     clauses. EACH previous intervention',
'//     on behalf of the character stacks',
'//     -5 percent (a count, not a flag);',
'//     medial alignment behavior -5,',
'//     borderline -10, a situation requiring',
'//     direct confrontation with another',
'//     deity -10, opposing forces of',
'//     diametrically opposed alignment +1,',
'//     serving the deity proximately +25 -',
'//     these five are 0/1 flags, clamped.',
'//     The total may go negative (no',
'//     intervention); the print sets no',
'//     floor, so none is applied.',
'//   - The planes rule: deities will not',
'//     intervene on the Outer Planes (the',
'//     habitation of other deities), nor on',
'//     the Positive or Negative Material',
'//     Planes. Elemental Plane intervention',
'//     is DM option (pinned 2 - and if',
'//     elemental gods are placed there, the',
'//     Outer deities will NOT go).',
'//     Intervention occurs on the Prime',
'//     Material in most cases, with',
'//     occasional intervention in the Astral',
'//     and Ethereal Planes (pinned 1).',
'//   - The secret rolls: listening, hiding',
'//     in shadows, detecting traps, moving',
'//     silently, finding secret doors,',
'//     monster saving throws, and attacks',
'//     made upon the party without their',
'//     possible knowledge - 7 kinds, always',
'//     made secretly.',
'//   - The system shock roll to be raised',
'//     from the dead is the one die roll the',
'//     DM never tampers with; failure is',
'//     FOREVER DEAD (both pinned 1).',
'//   - Player integration: an experienced',
'//     player without a character enters at',
'//     roughly the average level - at an',
'//     average of 4th, an averaging die d4',
'//     + 1 gives 2 to 5. This works up to an',
'//     average of 8th; above that, newcomers',
'//     start at 4th or higher. A neophyte',
'//     gains full co-operation with veterans',
'//     at 3rd or 4th level (3 pinned as the',
'//     low edge).',
'//   - Multiple characters: no absolute',
'//     prohibition (allowed 1), but money',
'//     and valuables cannot be freely',
'//     interchanged (0) and each is played',
'//     as an individual.',
'//   - Troublesome players: strong steps',
'//     short of expulsion include the',
'//     permanent loss of a point of charisma',
'//     (1) and the ethereal mummy which',
'//     always strikes by surprise (1).',
'// ====================================================================',
'',
'#pragma once',
'',
'namespace rules {',
'',
'// -----------------------------------------------------------------------',
'// The divine intervention procedure.',
'// -----------------------------------------------------------------------',
'inline int deityCreatureSentFirstAskPct() {',
'    // exemplary in faithfulness, first ask:',
'    // a straight 10 percent chance some',
'    // creature is sent to aid',
'    return 10;',
'}',
'',
'inline int deityComeChancePct(int level) {',
'    // the 00 roll: the chance the deity',
'    // itself comes equals the character',
'    // level of experience',
'    if (level < 0) level = 0;',
'    return level;',
'}',
'',
'inline int deityModEachPreviousIntervention() { return -5; }',
'',
'inline int deityModAlignmentMedial() { return -5; }',
'',
'inline int deityModAlignmentBorderline() { return -10; }',
'',
'inline int deityModDirectConfrontation() { return -10; }',
'',
'inline int deityModOpposingDiametric() { return 1; }',
'',
'inline int deityModServingProximately() { return 25; }',
'',
'inline int deityInterventionPct(int level,',
'                                 int previousCount,',
'                                 int alignmentMedial,',
'                                 int alignmentBorderline,',
'                                 int directConfrontation,',
'                                 int opposingDiametric,',
'                                 int servingProximately) {',
'    // the full modified chance; each',
'    // previous intervention STACKS -5 (the',
'    // count is taken as-is, floored at 0);',
'    // the five situation clauses are 0/1',
'    // flags, clamped to once each. No',
'    // floor: the print sets none.',
'    if (level < 0) level = 0;',
'    if (previousCount < 0) previousCount = 0;',
'    if (alignmentMedial < 0) alignmentMedial = 0;',
'    if (alignmentMedial > 1) alignmentMedial = 1;',
'    if (alignmentBorderline < 0) alignmentBorderline = 0;',
'    if (alignmentBorderline > 1) alignmentBorderline = 1;',
'    if (directConfrontation < 0) directConfrontation = 0;',
'    if (directConfrontation > 1) directConfrontation = 1;',
'    if (opposingDiametric < 0) opposingDiametric = 0;',
'    if (opposingDiametric > 1) opposingDiametric = 1;',
'    if (servingProximately < 0) servingProximately = 0;',
'    if (servingProximately > 1) servingProximately = 1;',
'    return level',
'        + deityModEachPreviousIntervention() * previousCount',
'        + deityModAlignmentMedial() * alignmentMedial',
'        + deityModAlignmentBorderline() * alignmentBorderline',
'        + deityModDirectConfrontation() * directConfrontation',
'        + deityModOpposingDiametric() * opposingDiametric',
'        + deityModServingProximately() * servingProximately;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The planes rule: 0 no, 1 yes, 2 DM option.',
'// -----------------------------------------------------------------------',
'enum InterventionPlane {',
'    IP_PRIME_MATERIAL = 0,',
'    IP_ASTRAL,',
'    IP_ETHEREAL,',
'    IP_ELEMENTAL,',
'    IP_OUTER,',
'    IP_POSITIVE,',
'    IP_NEGATIVE,',
'    IP_COUNT',
'};',
'',
'inline int interventionPlaneAllowed(int plane) {',
'    // Prime Material, Astral and Ethereal:',
'    // yes; Elemental: DM option; Outer,',
'    // Positive and Negative: no',
'    if (plane < 0) plane = 0;',
'    if (plane > 6) plane = 6;',
'    static const int t[7] = {',
'        1, 1, 1, 2, 0, 0, 0,',
'    };',
'    return t[plane];',
'}',
'',
'inline int elementalGodsBlockOuterDeities() {',
'    // if elemental gods are placed on the',
'    // Elemental Planes, the Outer deities',
'    // will NOT go there',
'    return 1;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The secret dice rolls and the system shock',
'// clause.',
'// -----------------------------------------------------------------------',
'enum SecretRollKind {',
'    SR_LISTENING = 0,',
'    SR_HIDING_IN_SHADOWS,',
'    SR_DETECTING_TRAPS,',
'    SR_MOVING_SILENTLY,',
'    SR_FINDING_SECRET_DOORS,',
'    SR_MONSTER_SAVING_THROWS,',
'    SR_ATTACKS_WITHOUT_KNOWLEDGE,',
'    SR_COUNT',
'};',
'',
'inline int secretRollKindCount() { return 7; }',
'',
'inline int rollIsSecretAlways(int kind) {',
'    // every kind on the list is always made',
'    // secretly',
'    if (kind < 0) kind = 0;',
'    if (kind > 6) kind = 6;',
'    return 1;',
'}',
'',
'inline int systemShockRollNeverTampered() {',
'    // the one die roll never to tamper with',
'    return 1;',
'}',
'',
'inline int systemShockFailureForeverDead() {',
'    // a failed system shock roll to be',
'    // raised is FOREVER DEAD',
'    return 1;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The player integration numbers.',
'// -----------------------------------------------------------------------',
'inline int integrationAveragingDieMin() {',
'    // the d4 + 1 averaging die: 2',
'    return 2;',
'}',
'',
'inline int integrationAveragingDieMax() {',
'    // the d4 + 1 averaging die: 5',
'    return 5;',
'}',
'',
'inline int integrationAverageWorksUpToLevel() {',
'    // the averaging die works up to an',
'    // average of 8th level',
'    return 8;',
'}',
'',
'inline int integrationAboveCeilingStartLevel() {',
'    // above the ceiling, newcomers start at',
'    // 4th or higher',
'    return 4;',
'}',
'',
'inline int neophyteFullCoopLevel() {',
'    // full co-operation at 3rd or 4th level',
'    // (3 pinned as the low edge)',
'    return 3;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The multiple characters rules.',
'// -----------------------------------------------------------------------',
'inline int multipleCharactersProhibited() {',
'    // no absolute prohibition',
'    return 0;',
'}',
'',
'inline int multipleCharactersFreeInterchange() {',
'    // money and valuables cannot be freely',
'    // interchanged',
'    return 0;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The troublesome-player measures.',
'// -----------------------------------------------------------------------',
'inline int troublesomeCharismaLossPoints() {',
'    // the permanent loss of a point of',
'    // charisma',
'    return 1;',
'}',
'',
'inline int etherealMummyAlwaysSurprise() {',
'    // the ethereal mummy always strikes by',
'    // surprise',
'    return 1;',
'}',
'',
'}  // namespace rules',
]
hdr = NL.join(hdr_lines) + NL

patch('rules/conduct.h',
      'R215: the conducting the game pins',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/siegefire.h"  // R214: pp.108-110 war machine fire, siege attack, defensive values'

new2 = ('#include "rules/siegefire.h"  // R214: pp.108-110 war machine fire, siege attack, defensive values'
        + NL + '#include "rules/conduct.h"  // R215: pp.110-112 conducting the game pins')

patch('regtest.cpp',
      'R215: pp.110-112 conducting the game pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R215 audit block
# ---------------------------------------------------------------------------

audit_lines = [
'    // ---- R215: the conducting the game pins audit ----',
'    // DMG pp.110-112: the divine intervention',
'    // procedure, the planes rule, the secret',
'    // rolls, the system shock clause, the',
'    // integration numbers, the multiple',
'    // characters rules, the troublesome',
'    // measures.',
'    {',
'        int bad = 0;',
'        // the divine intervention procedure',
'        if (rules::deityCreatureSentFirstAskPct() != 10 ||',
'            rules::deityComeChancePct(12) != 12 ||',
'            rules::deityComeChancePct(0) != 0 ||',
'            rules::deityComeChancePct(-5) != 0) ++bad;',
'        if (rules::deityModEachPreviousIntervention() != -5 ||',
'            rules::deityModAlignmentMedial() != -5 ||',
'            rules::deityModAlignmentBorderline() != -10 ||',
'            rules::deityModDirectConfrontation() != -10 ||',
'            rules::deityModOpposingDiametric() != 1 ||',
'            rules::deityModServingProximately() != 25) ++bad;',
'        if (rules::deityInterventionPct(10, 0, 0, 0, 0, 0, 0)',
'                != 10 ||',
'            rules::deityInterventionPct(10, 1, 0, 0, 0, 0, 0)',
'                != 5 ||',
'            rules::deityInterventionPct(10, 2, 0, 0, 0, 0, 0)',
'                != 0 ||',
'            rules::deityInterventionPct(',
'                10, 1, 1, 1, 1, 0, 0) != -20 ||',
'            rules::deityInterventionPct(',
'                10, 0, 0, 0, 0, 1, 1) != 36 ||',
'            rules::deityInterventionPct('
                '20, 1, 1, 1, 1, 1, 1) != 16 ||',
'            rules::deityInterventionPct(',
'                5, 9, 9, 9, 9, 9, 9) != -39 ||',
'            rules::deityInterventionPct(',
'                -3, 0, 0, 0, 0, 0, 0) != 0) ++bad;',
'        // the planes rule',
'        if (rules::IP_COUNT != 7',
'            || rules::IP_PRIME_MATERIAL != 0',
'            || rules::IP_ELEMENTAL != 3',
'            || rules::IP_OUTER != 4',
'            || rules::IP_POSITIVE != 5',
'            || rules::IP_NEGATIVE != 6) ++bad;',
'        static const int kPlane[7] = { 1, 1, 1, 2, 0, 0, 0 };',
'        for (int p = 0; p < 7; ++p)',
'            if (rules::interventionPlaneAllowed(p)',
'                    != kPlane[p]) ++bad;',
'        if (rules::interventionPlaneAllowed(-3) != 1 ||',
'            rules::interventionPlaneAllowed(9) != 0 ||',
'            rules::elementalGodsBlockOuterDeities() != 1) ++bad;',
'        // the secret rolls and the system shock clause',
'        if (rules::secretRollKindCount() != 7',
'            || rules::SR_COUNT != 7',
'            || rules::SR_LISTENING != 0',
'            || rules::SR_ATTACKS_WITHOUT_KNOWLEDGE != 6) ++bad;',
'        for (int k = -1; k < 8; ++k)',
'            if (rules::rollIsSecretAlways(k) != 1) ++bad;',
'        if (rules::systemShockRollNeverTampered() != 1 ||',
'            rules::systemShockFailureForeverDead() != 1) ++bad;',
'        // the integration numbers',
'        if (rules::integrationAveragingDieMin() != 2 ||',
'            rules::integrationAveragingDieMax() != 5 ||',
'            rules::integrationAverageWorksUpToLevel() != 8 ||',
'            rules::integrationAboveCeilingStartLevel() != 4 ||',
'            rules::neophyteFullCoopLevel() != 3) ++bad;',
'        // the multiple characters rules',
'        if (rules::multipleCharactersProhibited() != 0 ||',
'            rules::multipleCharactersFreeInterchange()',
'                != 0) ++bad;',
'        // the troublesome-player measures',
'        if (rules::troublesomeCharismaLossPoints() != 1 ||',
'            rules::etherealMummyAlwaysSurprise() != 1) ++bad;',
'        printf("R215 conducting the game pins audit: bad %d' + BS + 'n", bad);',
'        if (bad) return 1;',
'    }',
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R215: the conducting the game pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
'R215 landed the conducting the game pins',
'(DMG pp.110-112) - a prose-heavy chapter',
'whose numeric bones are now pinned.',
'rules/conduct.h (the grenade.h pattern):',
'the divine intervention procedure (the',
'exemplary first-time asker 10 percent',
'creature-sent chance; the 00 roll with the',
'chance the deity itself comes equal to the',
'character level; the six modifiers - each',
'previous intervention STACKS -5 as a count,',
'medial alignment -5, borderline -10,',
'required direct confrontation -10,',
'opposing diametric forces +1, proximate',
'service +25, the five flags clamped to',
'once each and no floor, the print sets',
'none), the planes rule (Prime Material,',
'Astral and Ethereal yes, Elemental DM',
'option, Outer and Positive/Negative no,',
'the elemental-gods block), the 7 secret',
'dice-roll kinds, the system shock',
'untouchability (never tampered, failure is',
'forever dead), the player integration',
'numbers (the d4+1 averaging die 2-5, the',
'8th-level ceiling, the 4th-level start',
'above it, the neophyte full-cooperation',
'level 3), the multiple characters rules',
'(no prohibition, no free interchange), and',
'the troublesome-player measures (the',
'charisma point, the always-surprising',
'ethereal mummy). The Boot Hill / Gamma',
'World conversion tables (pp.112-114) stay',
'OUT by design. Compilation cross-check',
'(the DDG divine intervention page) matches',
'the upload, adding only the asked-for-not-',
'received clarifying note. New R215 battery',
'audit; census 131. Next: the DMG-only',
'sweep continues - the ongoing campaign',
'chapter and its seams (the campaign',
'economics and time pins already landed; the',
'likely next pin material is the tables of',
'the AD&D campaign milieu sections, upload',
'lines ~8720+).',
]
log_entry = NL.join(log_lines)

old4 = ('campaign integration seams, DMG pp.110-112' + NL
        + 'area, upload lines ~8560+).' + NL + NL + 'Categories:')

new4 = ('campaign integration seams, DMG pp.110-112' + NL
        + 'area, upload lines ~8560+).' + NL + NL + log_entry + NL
        + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R215 landed the conducting the game pins',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R215 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R215 note: 4 patches; the conducting the game pins landed -')
print('the divine intervention procedure, the planes rule, the')
print('secret rolls, the integration numbers; census 131.')
print('commit: R215: the conducting the game pins pinned - DMG')
print('pp.110-112, divine intervention, secret rolls, integration numbers (census 131)')

