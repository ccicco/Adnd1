#!/usr/bin/env python3
# R218 splice: the use of magic items and
# energy draining pins - DMG pp.119-122,
# the USE OF MAGIC ITEMS and ENERGY
# DRAINING seams: drinking potions (one
# segment to open and consume, then a
# delay of d4+1 = 2-5 segments to full
# effect), applying oils (one segment to
# decant, 2-5 segments to spread), command
# words (a rod, staff or wand usually needs
# the proper word - learned from the
# possessor, hidden records, or the three
# informational spells: contact other
# plane, legend lore, speak with dead),
# crystal balls and scrying (detectable by
# the observed; a spell-user target checks
# the DETECTION OF INVISIBILITY table;
# darkness stops the viewing for the spell
# duration, dispel magic for a full day),
# the energy drain level-loss mechanics
# (hit points gained with the level
# including the constitution bonus, all
# abilities of the level, and XP brought
# to the mid-point of the next lower
# level; below 1st is a 0 level person
# never capable of gaining again; a 0
# level individual drained is dead), the
# multiclass drain rules (always the
# highest level; if all equal, the class
# with the greatest XP requirement; a
# two-level drain takes one level from
# each class), the drained-all undead
# fate (same sort as the slayer, lesser
# undead with half the normal hit dice
# controlled by their master; the lesser
# vampire at half the former professional
# level - the print example: an 8th level
# thief returns as a 4th level thief
# vampire), and the full-hit-dice regain
# upon the destruction of the slayer.
# The potion miscibility table is already
# pinned by R165 and stays out. Patches: 4
# (new rules/energydrain.h, regtest
# include, audit block, gap-report log
# entry). Census 133 -> 134.

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
# Patch 1: rules/energydrain.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
'// ====================================================================',
'// Adnd1 - rules/energydrain.h',
'// R218: the use of magic items and',
'// energy draining pins (DMG pp.119-122) -',
'// the potion, oil, command word and',
'// scrying conventions, and the energy',
'// drain level-loss mechanics.',
'//',
'// Pure data + helpers, header-only (the',
'// grenade.h pattern: the caller owns the',
'// dice, the hit die records and the actual',
'// draining; the tables and the numeric',
'// conventions read here).',
'//',
'// Conventions and judgments, named in',
'// place:',
'//   - Drinking potions: it takes but one',
'//     segment (6 seconds) to open and',
'//     consume the typical potion; then a',
'//     delay of d4+1 = 2-5 segments before',
'//     the dose takes full effect. Specific',
'//     per-potion times are possible but',
'//     not recommended.',
'//   - Applying oils: not consumed - one',
'//     segment of normal opening and',
'//     decanting, then 2-5 segments to',
'//     spread over hands and body.',
'//   - Command words: a rod, staff or wand',
'//     usually needs the proper command',
'//     word. It can be learned by noting',
'//     what the possessor says, forcing or',
'//     tricking the possessor into',
'//     divulging it, from hidden records,',
'//     or via the three informational spells',
'//     - contact other plane, legend lore',
'//     and speak with dead.',
'//   - Crystal balls and scrying: scrying',
'//     is detectable. If the observed',
'//     creature is a spell user, consult the',
'//     DETECTION OF INVISIBILITY table by',
'//     level/hit dice and intelligence,',
'//     checking each round. Darkness cast',
'//     upon the viewing spot stops the',
'//     scrying for the duration of the',
'//     darkness spell; dispel magic stops it',
'//     for a full day.',
'//   - Energy drain mechanics: losing an',
'//     energy level loses an experience',
'//     level - the hit points gained with',
'//     it (including the constitution',
'//     bonus), all abilities of that level,',
'//     and XP brought down to the mid-point',
'//     of the next lower level. Below 1st',
'//     level the individual is a 0 level',
'//     person never capable of gaining',
'//     experience again; a 0 level',
'//     individual drained an energy level is',
'//     dead. Players may be required to',
'//     record each hit die score so lost',
'//     points are known immediately.',
'//   - Multiclass drain: a multi-classed or',
'//     two-classed character drained of one',
'//     level always loses the highest level',
'//     gained; if all levels are equal, the',
'//     level of the class requiring the',
'//     greatest amount of experience points',
'//     is lost. A creature draining two',
'//     levels takes one level from each',
'//     class.',
'//   - The drained-all fate: a character',
'//     drained of all energy levels might',
'//     become an undead monster of the same',
'//     sort which killed him or her. These',
'//     lesser undead are controlled by their',
'//     slayer/drainer and have but half the',
'//     hit dice of a normal undead of the',
'//     same type. A lesser vampire has half',
'//     the former professional level - the',
'//     print example: an 8th level thief',
'//     returns as a 4th level thief vampire',
'//     (odd levels round down; the print',
'//     gives only the exact-half example).',
'//     Upon the destruction of the slayer,',
'//     the lesser undead gain levels from',
'//     those they slay/drain until reaching',
'//     full hit dice status, then they can',
'//     themselves control lesser undead.',
'// ====================================================================',
'',
'#pragma once',
'',
'namespace rules {',
'',
'// -----------------------------------------------------------------------',
'// Drinking potions and applying oils.',
'// -----------------------------------------------------------------------',
'inline int potionOpenConsumeSegments() {',
'    // one segment to open and consume the',
'    // typical potion',
'    return 1;',
'}',
'',
'inline int potionDelayMin() {',
'    // the d4 + 1 delay: 2 segments',
'    return 2;',
'}',
'',
'inline int potionDelayMax() {',
'    // the d4 + 1 delay: 5 segments',
'    return 5;',
'}',
'',
'inline int oilDecantSegments() {',
'    // normal opening time and decanting',
'    return 1;',
'}',
'',
'inline int oilSpreadMin() { return 2; }',
'',
'inline int oilSpreadMax() { return 5; }',
'',
'// -----------------------------------------------------------------------',
'// Command words.',
'// -----------------------------------------------------------------------',
'inline int rodStaffWandNeedsCommandWord() {',
'    // usually necessary for a rod, staff or',
'    // wand',
'    return 1;',
'}',
'',
'inline int commandWordInfoSpellCount() {',
'    // contact other plane, legend lore,',
'    // speak with dead',
'    return 3;',
'}',
'',
'// -----------------------------------------------------------------------',
'// Crystal balls and scrying.',
'// -----------------------------------------------------------------------',
'inline int scryingDetectable() {',
'    // scrying devices are detectable by the',
'    // observed',
'    return 1;',
'}',
'',
'inline int scryingDetectionUsesInvisibilityTable() {',
'    // a spell-user target: consult the',
'    // DETECTION OF INVISIBILITY table,',
'    // checking each round',
'    return 1;',
'}',
'',
'inline int scryingDarknessStopsForSpellDuration() {',
'    // darkness on the viewing spot stops the',
'    // scrying for the darkness duration',
'    return 1;',
'}',
'',
'inline int scryingDispelStopsHours() {',
'    // dispel magic stops the scrying for a',
'    // full day',
'    return 24;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The energy drain level-loss mechanics.',
'// -----------------------------------------------------------------------',
'inline int drainLosesLevelHitPointsAndAbilities() {',
'    // the hit points gained with the level',
'    // (including the constitution bonus)',
'    // and all abilities of that level',
'    return 1;',
'}',
'',
'inline int drainXpToMidpointOfNextLower() {',
'    // XP sufficient to bring the total to',
'    // the mid-point of the next lower level',
'    return 1;',
'}',
'',
'inline int drainBelowFirstIsZeroLevel() {',
'    // below 1st level of experience: a 0',
'    // level person',
'    return 1;',
'}',
'',
'inline int zeroLevelNeverGainsAgain() {',
'    // never capable of gaining experience',
'    // again',
'    return 1;',
'}',
'',
'inline int isDeadIfZeroLevelDrained(int level) {',
'    // a 0 level individual drained an energy',
'    // level is dead (possibly to become an',
'    // undead monster)',
'    if (level <= 0) return 1;',
'    return 0;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The multiclass drain rules.',
'// -----------------------------------------------------------------------',
'inline int multiclassLosesHighestLevel() {',
'    // always the highest level gained',
'    return 1;',
'}',
'',
'inline int equalLevelsLoseGreatestXpClass() {',
'    // if all levels are equal, the class',
'    // requiring the greatest amount of',
'    // experience points loses the level',
'    return 1;',
'}',
'',
'inline int twoLevelDrainSplitsAcrossClasses() {',
'    // a two-level drain takes one level',
'    // from each class',
'    return 1;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The drained-all undead fate.',
'// -----------------------------------------------------------------------',
'inline int drainedAllMayBecomeUndead() {',
'    // an undead monster of the same sort',
'    // which killed the character',
'    return 1;',
'}',
'',
'inline int lesserUndeadHalfHitDice() {',
'    // half the hit dice of a normal undead',
'    // of the same type',
'    return 1;',
'}',
'',
'inline int lesserUndeadControlledBySlayer() {',
'    // controlled by their slayer/drainer',
'    return 1;',
'}',
'',
'inline int lesserVampireLevel(int level) {',
'    // half the former professional level; the',
'    // print example: an 8th level thief',
'    // returns as a 4th level thief vampire.',
'    // Odd levels round down (the print gives',
'    // only the exact-half example).',
'    if (level < 0) level = 0;',
'    return level / 2;',
'}',
'',
'inline int fullHdRegainUponSlayerDestruction() {',
'    // the lesser undead gain levels from',
'    // those they slay/drain until full hit',
'    // dice status',
'    return 1;',
'}',
'',
'}  // namespace rules',
]
hdr = NL.join(hdr_lines) + NL

patch('rules/energydrain.h',
      'R218: the use of magic items and',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/scrollfab.h"  // R217: pp.118-121 scroll manufacture and fabrication pins'

new2 = ('#include "rules/scrollfab.h"  // R217: pp.118-121 scroll manufacture and fabrication pins'
        + NL + '#include "rules/energydrain.h"  // R218: pp.119-122 use of magic items and energy draining pins')

patch('regtest.cpp',
      'R218: pp.119-122 use of magic items and energy draining pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R218 audit block
# ---------------------------------------------------------------------------

audit_lines = [
'    // ---- R218: the use of magic items and energy draining pins audit ----',
'    // DMG pp.119-122: the potion, oil,',
'    // command word and scrying conventions,',
'    // and the energy drain level-loss',
'    // mechanics.',
'    {',
'        int bad = 0;',
'        // drinking potions and applying oils',
'        if (rules::potionOpenConsumeSegments() != 1 ||',
'            rules::potionDelayMin() != 2 ||',
'            rules::potionDelayMax() != 5) ++bad;',
'        if (rules::oilDecantSegments() != 1 ||',
'            rules::oilSpreadMin() != 2 ||',
'            rules::oilSpreadMax() != 5) ++bad;',
'        // command words',
'        if (rules::rodStaffWandNeedsCommandWord() != 1 ||',
'            rules::commandWordInfoSpellCount() != 3) ++bad;',
'        // crystal balls and scrying',
'        if (rules::scryingDetectable() != 1 ||',
'            rules::scryingDetectionUsesInvisibilityTable() != 1 ||',
'            rules::scryingDarknessStopsForSpellDuration() != 1 ||',
'            rules::scryingDispelStopsHours() != 24) ++bad;',
'        // the energy drain level-loss mechanics',
'        if (rules::drainLosesLevelHitPointsAndAbilities() != 1 ||',
'            rules::drainXpToMidpointOfNextLower() != 1) ++bad;',
'        if (rules::drainBelowFirstIsZeroLevel() != 1 ||',
'            rules::zeroLevelNeverGainsAgain() != 1) ++bad;',
'        if (rules::isDeadIfZeroLevelDrained(0) != 1 ||',
'            rules::isDeadIfZeroLevelDrained(-2) != 1 ||',
'            rules::isDeadIfZeroLevelDrained(1) != 0 ||',
'            rules::isDeadIfZeroLevelDrained(5) != 0) ++bad;',
'        // the multiclass drain rules',
'        if (rules::multiclassLosesHighestLevel() != 1 ||',
'            rules::equalLevelsLoseGreatestXpClass() != 1 ||',
'            rules::twoLevelDrainSplitsAcrossClasses() != 1) ++bad;',
'        // the drained-all undead fate',
'        if (rules::drainedAllMayBecomeUndead() != 1 ||',
'            rules::lesserUndeadHalfHitDice() != 1 ||',
'            rules::lesserUndeadControlledBySlayer() != 1 ||',
'            rules::fullHdRegainUponSlayerDestruction() != 1) ++bad;',
'        if (rules::lesserVampireLevel(8) != 4 ||',
'            rules::lesserVampireLevel(0) != 0 ||',
'            rules::lesserVampireLevel(-3) != 0 ||',
'            rules::lesserVampireLevel(3) != 1) ++bad;',
'        printf("R218 use of magic items and energy draining pins audit: bad %d' + BS + 'n", bad);',
'        if (bad) return 1;',
'    }',
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R218: the use of magic items and energy draining pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
'R218 landed the use of magic items and',
'energy draining pins (DMG pp.119-122) -',
'the USE OF MAGIC ITEMS seam and the',
'ENERGY DRAINING BY UNDEAD OR DEVICE',
'section that follows it (the potion',
'miscibility table between them is already',
'pinned by R165 and stays out).',
'rules/energydrain.h (the grenade.h pattern):',
'drinking potions (one segment to open and',
'consume, then a d4+1 = 2-5 segment delay',
'to full effect), applying oils (one segment',
'to decant, 2-5 segments to spread),',
'command words (a rod, staff or wand usually',
'needs the proper word - learned from the',
'possessor, hidden records, or the three',
'informational spells: contact other plane,',
'legend lore, speak with dead), crystal',
'balls and scrying (detectable; a spell-user',
'target checks the DETECTION OF INVISIBILITY',
'table each round; darkness stops the viewing',
'for the spell duration, dispel magic for a',
'full day), the energy drain mechanics (the',
'hit points gained with the level including',
'the constitution bonus, all abilities of',
'the level, XP to the mid-point of the next',
'lower level; below 1st is a 0 level person',
'never capable of gaining again; a 0 level',
'individual drained is dead), the multiclass',
'drain rules (always the highest level, ties',
'to the greatest-XP class, a two-level drain',
'splits one level per class), and the',
'drained-all fate (an undead of the same',
'sort as the slayer, lesser undead at half',
'hit dice controlled by their master, the',
'lesser vampire at half the former',
'professional level - the print example: an',
'8th level thief returns as a 4th level',
'thief vampire, odd levels round down - and',
'the full-hit-dice regain upon the',
'destruction of the slayer). The treasure',
'random determination tables (upload lines',
'~9330+, the map/monetary/magic/combined',
'hoard tables) are the natural next seam.',
'New R218 battery audit; census 134. Next:',
'R219 - the TREASURE RANDOM DETERMINATION',
'tables (I. map or magic, II. the map table',
'and its outdoor distance/containment',
'sub-tables, II.A monetary, II.B magic,',
'II.C combined hoard, upload lines ~9330+,',
'pp.122-125).',
]
log_entry = NL.join(log_lines)

old4 = ('pp.121+).' + NL + NL + 'Categories:')

new4 = ('pp.121+).' + NL + NL + log_entry + NL
        + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R218 landed the use of magic items and',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R218 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R218 note: 4 patches; the use of magic items and energy draining pins')
print('landed - the potion and oil timings, the command words, the scrying')
print('rules, and the energy drain mechanics; census 134.')
print('commit: R218: the use of magic items and energy draining pins pinned - DMG')
print('pp.119-122, potion and oil timings, scrying, energy drain mechanics (census 134)')

