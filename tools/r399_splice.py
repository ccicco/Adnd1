#!/usr/bin/env python3
# R399: the UA armor swords
# and misc weapons flagged
# holes completion - the
# clean read fills every
# flagged hole the two
# treasure prose headers
# carry.
#
# The clean pp. 104-106 read
# (the same stretch the
# R387/R388 rounds pinned
# from the garbled extract)
# delivers the seven flagged
# seams:
#
# 1. rules/uaarmprose.h
#    (R387): four flags drop -
#    the elfin chain mail's
#    size table (the row-one
#    label gnome/halfling
#    (hairfoot), the 6 and
#    6 1/2' height cells), the
#    plate's conform
#    parenthetical, the sun
#    blade's radiance seam
#    (bright yellow, full
#    daylight), the Final
#    Word broadswords' nine
#    appellations; the part
#    ledger flips 4/4 -> 8/0.
# 2. rules/uamweapprose.h
#    (R388): three flags drop -
#    the axe of hurling's 12
#    1/2% familiarization
#    tail, the dagger of
#    throwing's range cells
#    (short/medium = 2"/4"),
#    the hornblade's handle
#    sentence (a horn of
#    1/2' to 1 1/4'); the
#    part ledger flips 6/3 ->
#    9/0.
# 3. regtest.cpp: the two
#    part ledgers and their
#    seams flip, the seven
#    flag asserts invert, a
#    new R399 audit block
#    lands before the R227
#    anchor; census 325 ->
#    326.
# 4. tools/ua_gap_report.md:
#    both treasure items take
#    an AMENDED R399: closed
#    sub-entry.
# 5. The seed takes the R398
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
        'R399 splice ABORT: ' + msg)


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


def forms(cond):
    return ('if (%s) ++bad;' % cond,
            'if (%s)' % cond + NL
            + '                ++bad;')


def flip1(path, expr, expect, label):
    s = rd(path)
    if ('!' + expr) not in s:
        already.append(label)
        return
    oA, oB = forms('!' + expr)
    n = s.count(oA) + s.count(oB)
    if n != expect:
        die('%s: old text count %d,'
            ' expected %d'
            % (label, n, expect))
    nA, nB = forms(expr)
    s = s.replace(oA, nA)
    s = s.replace(oB, nB)
    wr(path, s)
    applied.append(label)


def flipled(path, expr, oldval,
            newval, expect, label):
    s = rd(path)
    ocond = '%s != %d' % (expr, oldval)
    ncond = '%s != %d' % (expr, newval)
    oA, oB = forms(ocond)
    nA, nB = forms(ncond)
    if s.count(nA) + s.count(nB) \
            == expect:
        already.append(label)
        return
    n = s.count(oA) + s.count(oB)
    if n != expect:
        die('%s: old text count %d,'
            ' expected %d'
            % (label, n, expect))
    s = s.replace(oA, nA)
    s = s.replace(oB, nB)
    wr(path, s)
    applied.append(label)


# ================= (a) the seed =================
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'

SEED_ENTRY = E(
    '- R398 landed 2026-10-13:',
    '  commit 2a9f559 (census 325,',
    '  preflight GREEN), the UA',
    '  misc magic flagged holes',
    '  completion: the clean pp.',
    '  98-104 read fills all 33',
    '  flagged holes the six misc',
    '  magic prose parts carry',
    '  (rules/uamiscprose1.h',
    '  through',
    '  rules/uamiscprose6.h) -',
    '  every part ledger runs',
    '  clean, the four',
    '  provisional pins correct',
    '  (the lens diameter, the',
    "  philosopher's stone",
    '  pounds, the prison',
    '  shrink). The ./nn save',
    '  hash diverged for the',
    '  sixth round running yet',
    '  the copy passed the',
    '  battery - stable and',
    '  benign; the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R398 landed 2026-10-13' in s:
    already.append('seed: the R398 record')
else:
    if s.count(ANCH) != 1:
        die('the seed anchor count %d'
            % s.count(ANCH))
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R398 record')
s = rd(SD)
if s.count('R398 landed 2026-10-13') != 1:
    die('the R398 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ============ (b) rules/uaarmprose.h ============
P1 = 'rules/uaarmprose.h'
NS = NL + 'namespace rules {'

pair(P1, E(
    '// fully garbles; the part-6',
    '// and skeleton seams ride in',
    '// the regtest audit, not',
    '// here.') + NS,
    E(
    '// fully garbles; the part-6',
    '// and skeleton seams ride in',
    '// the regtest audit, not',
    '// here.',
    '// The R399 clean read',
    '// filled every flagged hole',
    '// named above.') + NS,
    'armor: the header note')

pair(P1, E(
    '// The size table',
    '// OCR-scrambles (the header',
    '// and row labels',
    '// dislocate); the',
    '// reconstruction: five rows -',
    '// 01-10 hairfoot, 11-15',
    '// dwarf/halfling (stout or',
    '// tallfellow), 16-80',
    '// elf/half-elf, 81-95',
    '// man-sized normal (up to 6',
    '// feet, 200 lbs.), 96-00',
    '// man-sized large (up to 250',
    '// lbs.); flagged.',
    'inline int uaaspEcmSizeTableRows()',
    '    { return 5; }'),
    E(
    '// The R399 clean read',
    '// prints the table: five',
    '// rows - 01-10',
    '// gnome/halfling',
    '// (hairfoot), 11-15',
    '// dwarf/halfling (stout or',
    '// tallfellow), 16-80',
    '// elf/half-elf, 81-95',
    '// man-sized, normal (up to',
    "// 6', 200 lbs.), 96-00",
    '// man-sized, large (up to',
    "// 6 1/2', 250 lbs.).",
    'inline int uaaspEcmSizeTableRows()',
    '    { return 5; }'),
    'armor: the ECM table print')

pair(P1, E(
    'inline int uaaspEcmManLargeLbs()',
    '    { return 250; }',
    '',
    'inline bool uaaspEcmSizeTableGarbles()',
    '    { return true; }'),
    E(
    'inline int uaaspEcmManLargeLbs()',
    '    { return 250; }',
    '',
    '// The R399 clean read fills',
    '// the row-one label and the',
    '// two height cells.',
    'inline int uaaspEcmManNormalHeightIn()',
    '    { return 72; }',
    '',
    'inline int uaaspEcmManLargeHeightIn()',
    '    { return 78; }',
    '',
    'inline bool uaaspEcmRow1GnomeHalfling()',
    '    { return true; }',
    '',
    'inline bool uaaspEcmSizeTableGarbles()',
    '    { return false; }'),
    'armor: the ECM height cells')

pair(P1, E(
    'inline bool uaaspPltSameRaceRequired()',
    '    { return true; }',
    '',
    'inline bool uaaspPltConformSeamGarbles()',
    '    { return true; }'),
    E(
    'inline bool uaaspPltSameRaceRequired()',
    '    { return true; }',
    '',
    '// The R399 clean read fills',
    '// the parenthetical: any',
    '// human wears human-sized,',
    '// any dwarf dwarf-sized,',
    '// etc.',
    'inline bool uaaspPltAnyHumanWearsOwn()',
    '    { return true; }',
    '',
    'inline bool uaaspPltConformSeamGarbles()',
    '    { return false; }'),
    'armor: the plate parenthetical')

pair(P1, E(
    'inline bool uaaspSubRadianceOnCommand()',
    '    { return true; }',
    '',
    'inline bool uaaspSubRadianceSeamGarbles()',
    '    { return true; }'),
    E(
    'inline bool uaaspSubRadianceOnCommand()',
    '    { return true; }',
    '',
    '// The R399 clean read',
    '// confirms the seam: the',
    '// blade sheds a bright',
    '// yellow radiance equaling',
    '// full daylight.',
    'inline bool uaaspSubRadianceBrightYellow()',
    '    { return true; }',
    '',
    'inline bool uaaspSubRadianceEqualsDaylight()',
    '    { return true; }',
    '',
    'inline bool uaaspSubRadianceSeamGarbles()',
    '    { return false; }'),
    'armor: the sun blade seam')

pair(P1, E(
    'inline bool uaaspFwbEachGemDifferent()',
    '    { return true; }',
    '',
    'inline bool uaaspFwbNamesTailGarbles()',
    '    { return true; }'),
    E(
    'inline bool uaaspFwbEachGemDifferent()',
    '    { return true; }',
    '',
    '// The R399 clean read fills',
    '// the nine appellations.',
    'inline const char* uaaspFwbAppellation(int i) {',
    '    static const char* const k[9] = {',
    '        "Answerer",',
    '        "Back-talker",',
    '        "Concluder",',
    '        "Last-quip",',
    '        "Rebutter",',
    '        "Replier",',
    '        "Retorter",',
    '        "Scather",',
    '        "Squelcher"',
    '    };',
    '    if (i < 0 || i >= 9)',
    '        return "";',
    '    return k[i];',
    '}',
    '',
    'inline bool uaaspFwbNamesTailGarbles()',
    '    { return false; }'),
    'armor: the Final Word names')

pair(P1, E(
    '// ---- the part ledger ----',
    '// Eight items: four fully',
    '// clean, four flagged, none',
    '// fully garbled.',
    'inline int uaaspPartItemTotal()',
    '    { return 8; }',
    '',
    'inline int uaaspPartCleanCount()',
    '    { return 4; }',
    '',
    'inline int uaaspPartFlaggedCount()',
    '    { return 4; }'),
    E(
    '// ---- the part ledger ----',
    '// Eight items, all fully',
    '// clean - the R399 clean',
    '// read filled the four',
    '// flagged holes, none fully',
    '// garbled.',
    'inline int uaaspPartItemTotal()',
    '    { return 8; }',
    '',
    'inline int uaaspPartCleanCount()',
    '    { return 8; }',
    '',
    'inline int uaaspPartFlaggedCount()',
    '    { return 0; }'),
    'armor: the part ledger')

# ============ (c) rules/uamweapprose.h ============
P2 = 'rules/uamweapprose.h'

pair(P2, E(
    '// armor and skeleton seams',
    '// ride in the regtest audit,',
    '// not here.') + NS,
    E(
    '// armor and skeleton seams',
    '// ride in the regtest audit,',
    '// not here.',
    '// The R399 clean read',
    '// filled every flagged hole',
    '// named above.') + NS,
    'weapons: the header note')

pair(P2, E(
    '// The familiarization tail',
    '// OCR-scrambles; the',
    '// reconstruction: after each',
    '// week of use, the possessor',
    '// has a 1-in-8 chance (roll',
    '// of 1 on d8) to learn the',
    '// full properties; in any',
    '// event fully known after 8',
    '// full weeks; flagged.',
    'inline int uamwAohFamChanceDie()',
    '    { return 8; }',
    '',
    'inline int uamwAohFamWeeksFull()',
    '    { return 8; }',
    '',
    'inline bool uamwAohFamTailGarbles()',
    '    { return true; }'),
    E(
    '// The R399 clean read fills',
    '// the tail: after each week',
    '// of use the possessor has',
    '// a 12 1/2% chance (roll of',
    '// 1 on d8) to learn the',
    '// full properties; in any',
    '// event fully known after',
    '// 8 full weeks.',
    'inline int uamwAohFamChanceDie()',
    '    { return 8; }',
    '',
    'inline int uamwAohFamWeeksFull()',
    '    { return 8; }',
    '',
    'inline int uamwAohFamChancePctX2()',
    '    { return 25; }',
    '',
    'inline bool uamwAohFamTailGarbles()',
    '    { return false; }'),
    'weapons: the axe fam tail')

pair(P2, E(
    'inline int uamwDthHurledRangeIn()',
    '    { return 6; }',
    '',
    'inline bool uamwDthRangeCellsGarbles()',
    '    { return true; }'),
    E(
    'inline int uamwDthHurledRangeIn()',
    '    { return 6; }',
    '',
    '// The R399 clean read fills',
    '// the cells: short/medium',
    '// range = 2"/4", the full',
    '// hurled distance 6".',
    'inline int uamwDthShortRangeIn()',
    '    { return 2; }',
    '',
    'inline int uamwDthMediumRangeIn()',
    '    { return 4; }',
    '',
    'inline bool uamwDthRangeCellsGarbles()',
    '    { return false; }'),
    'weapons: the dagger cells')

pair(P2, E(
    'inline int uamwHblInspectionUnlikelyPct()',
    '    { return 90; }',
    '',
    'inline bool uamwHblHandleSentenceGarbles()',
    '    { return true; }'),
    E(
    'inline int uamwHblInspectionUnlikelyPct()',
    '    { return 90; }',
    '',
    '// The R399 clean read fills',
    '// the sentence: a piece of',
    "// horn of 1/2' to 1 1/4'",
    '// in length, set in some',
    '// sort of handle or grip.',
    'inline int uamwHblHornLengthLoIn()',
    '    { return 6; }',
    '',
    'inline int uamwHblHornLengthHiIn()',
    '    { return 15; }',
    '',
    'inline bool uamwHblHandleSentenceGarbles()',
    '    { return false; }'),
    'weapons: the hornblade horn')

pair(P2, E(
    '// ---- the part ledger ----',
    '// Nine items: six fully',
    '// clean, three flagged, none',
    '// fully garbled.',
    'inline int uamwPartItemTotal()',
    '    { return 9; }',
    '',
    'inline int uamwPartCleanCount()',
    '    { return 6; }',
    '',
    'inline int uamwPartFlaggedCount()',
    '    { return 3; }'),
    E(
    '// ---- the part ledger ----',
    '// Nine items, all fully',
    '// clean - the R399 clean',
    '// read filled the three',
    '// flagged holes, none fully',
    '// garbled.',
    'inline int uamwPartItemTotal()',
    '    { return 9; }',
    '',
    'inline int uamwPartCleanCount()',
    '    { return 9; }',
    '',
    'inline int uamwPartFlaggedCount()',
    '    { return 0; }'),
    'weapons: the part ledger')

# ============ (d) tools/ua_gap_report.md ============
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '      - AMENDED R387: the UA armor and',
    '        swords prose pin round',
    '        (rules/uaarmprose.h) - the',
    '        pp. 104-105 stretch, EIGHT items',
    '        pin: FOUR fully clean (the',
    '        anything armor, the short sword',
    '        of quickness, the sword of the',
    '        planes, the anything sword) plus',
    '        FOUR mechanics-clean with',
    '        flagged holes (the elfin chain',
    "        mail's size-table garble, the",
    "        plate's conform seam, the sun",
    "        blade's radiance seam, the Final",
    "        Word broadswords' names tail);",
    '        NOTHING fully garbles - the',
    '        item AMENDED, the prose pinned,',
    '        stays PDF-gated only.',
    '- [ ] **The new miscellaneous weapons**'),
    E(
    '      - AMENDED R387: the UA armor and',
    '        swords prose pin round',
    '        (rules/uaarmprose.h) - the',
    '        pp. 104-105 stretch, EIGHT items',
    '        pin: FOUR fully clean (the',
    '        anything armor, the short sword',
    '        of quickness, the sword of the',
    '        planes, the anything sword) plus',
    '        FOUR mechanics-clean with',
    '        flagged holes (the elfin chain',
    "        mail's size-table garble, the",
    "        plate's conform seam, the sun",
    "        blade's radiance seam, the Final",
    "        Word broadswords' names tail);",
    '        NOTHING fully garbles - the',
    '        item AMENDED, the prose pinned,',
    '        stays PDF-gated only.',
    '      - AMENDED R399: closed -',
    '        the clean read fills the',
    '        four flagged seams: the',
    '        elfin chain mail row-one',
    '        label (gnome/halfling,',
    '        hairfoot) and the 6 and',
    "        6 1/2' height cells, the",
    '        plate conform',
    '        parenthetical, the sun',
    '        blade radiance seam',
    '        (bright yellow, full',
    '        daylight), the nine',
    '        Final Word appellations',
    '        (Answerer, Back-talker,',
    '        Concluder, Last-quip,',
    '        Rebutter, Replier,',
    '        Retorter, Scather,',
    '        Squelcher).',
    '- [ ] **The new miscellaneous weapons**'),
    'gap: the armor swords item')

pair(GP, E(
    '      - AMENDED R388: the UA misc',
    '        weapons prose pin round',
    '        (rules/uamweapprose.h) - the',
    '        pp. 105-106 stretch, NINE items',
    '        pin: SIX fully clean (the bullet',
    '        of impact, the dagger Longtooth,',
    '        the darts of homing, the knife',
    '        buckle, the magic quarterstaff,',
    '        the scimitar of speed) plus',
    '        THREE mechanics-clean with',
    '        flagged holes (the axe of',
    "        hurling's familiarization tail,",
    "        the dagger of throwing's range",
    "        cells, the hornblade's handle",
    '        sentence); NOTHING fully garbles',
    '        - the item AMENDED, the prose',
    '        pinned, the treasure prose sweep',
    '        complete, stays PDF-gated only.',
    '',
    '### DM tables and charts'),
    E(
    '      - AMENDED R388: the UA misc',
    '        weapons prose pin round',
    '        (rules/uamweapprose.h) - the',
    '        pp. 105-106 stretch, NINE items',
    '        pin: SIX fully clean (the bullet',
    '        of impact, the dagger Longtooth,',
    '        the darts of homing, the knife',
    '        buckle, the magic quarterstaff,',
    '        the scimitar of speed) plus',
    '        THREE mechanics-clean with',
    '        flagged holes (the axe of',
    "        hurling's familiarization tail,",
    "        the dagger of throwing's range",
    "        cells, the hornblade's handle",
    '        sentence); NOTHING fully garbles',
    '        - the item AMENDED, the prose',
    '        pinned, the treasure prose sweep',
    '        complete, stays PDF-gated only.',
    '      - AMENDED R399: closed -',
    '        the clean read fills the',
    '        three flagged seams: the',
    '        axe of hurling 12 1/2%',
    '        familiarization tail,',
    '        the dagger of throwing',
    "        range cells (2\"/4\"), the",
    "        hornblade's handle",
    "        sentence (a horn of 1/2'",
    "        to 1 1/4' in a grip).",
    '        With the armor and',
    '        swords item above the',
    '        UA treasure prose sweep',
    '        stands fully closed.',
    '',
    '### DM tables and charts'),
    'gap: the misc weapons item')

# ============ (e) regtest.cpp ============
RT = 'regtest.cpp'

# the two block notes
pair(RT, E(
    '    // ---- R387: the UA armor and',
    '    // swords prose pin audit ----'),
    E(
    '    // ---- R387: the UA armor and',
    '    // swords prose pin audit ----',
    '    // The R399 clean read fills',
    '    // every flagged hole this',
    '    // block names.'),
    'regtest R387: the block note')

pair(RT, E(
    '    // ---- R388: the UA misc',
    '    // weapons prose pin audit ----'),
    E(
    '    // ---- R388: the UA misc',
    '    // weapons prose pin audit ----',
    '    // The R399 clean read fills',
    '    // every flagged hole this',
    '    // block names.'),
    'regtest R388: the block note')

# the part-ledger asserts
flipled(RT, 'uaaspPartCleanCount()',
        4, 8, 2, 'regtest: the armor clean ledger')
flipled(RT, 'uaaspPartFlaggedCount()',
        4, 0, 2, 'regtest: the armor flagged')
flipled(RT, 'uamwPartCleanCount()',
        6, 9, 1, 'regtest: the weapons clean ledger')
flipled(RT, 'uamwPartFlaggedCount()',
        3, 0, 1, 'regtest: the weapons flagged')

# the seven flag asserts invert
FLAGS = [
    'uaaspEcmSizeTableGarbles',
    'uaaspPltConformSeamGarbles',
    'uaaspSubRadianceSeamGarbles',
    'uaaspFwbNamesTailGarbles',
    'uamwAohFamTailGarbles',
    'uamwDthRangeCellsGarbles',
    'uamwHblHandleSentenceGarbles',
]

for nm in FLAGS:
    flip1(RT, nm + '()', 1,
          'regtest: the %s assert'
          % nm)

# the new R399 audit block
NEWPINS = [
    ('uaaspEcmManNormalHeightIn', 72),
    ('uaaspEcmManLargeHeightIn', 78),
    ('uaaspEcmRow1GnomeHalfling', True),
    ('uaaspPltAnyHumanWearsOwn', True),
    ('uaaspSubRadianceBrightYellow', True),
    ('uaaspSubRadianceEqualsDaylight', True),
    ('uamwAohFamChancePctX2', 25),
    ('uamwDthShortRangeIn', 2),
    ('uamwDthMediumRangeIn', 4),
    ('uamwHblHornLengthLoIn', 6),
    ('uamwHblHornLengthHiIn', 15),
]


def pin_lines(pins):
    out = []
    for nm, val in pins:
        if val is True:
            cond = '!' + nm + '()'
        else:
            cond = '%s() != %d' % (nm, val)
        stmt = 'if (%s) ++bad;' % cond
        if 12 + len(stmt) <= 78:
            out.append('            ' + stmt)
        else:
            out.append('            if (%s)' % cond)
            out.append('                ++bad;')
    return out


NAMES = [
    ('0', 'Answerer'),
    ('1', 'Back-talker'),
    ('2', 'Concluder'),
    ('3', 'Last-quip'),
    ('4', 'Rebutter'),
    ('5', 'Replier'),
    ('6', 'Retorter'),
    ('7', 'Scather'),
    ('8', 'Squelcher'),
]

NAME_LINES = []
for i, nm in NAMES:
    NAME_LINES.extend([
        '            if (std::string(',
        '                    uaaspFwb'
        'Appellation(%s))' % i,
        '                    != "%s")'
        ' ++bad;' % nm])


def cross(txt):
    out = []
    for ln in txt.split(NL):
        out.append('            ' + ln)
    return out


AUD = ['    // ---- R399: the UA armor',
       '    // swords misc weapons holes',
       '    // pin audit ----',
       '    // The clean read (pp.',
       '    // 104-106) fills every',
       '    // flagged hole the two',
       '    // treasure prose headers',
       '    // carry - all seven flags',
       '    // drop and both part',
       '    // ledgers run clean/0.',
       '    {',
       '        using namespace rules;',
       '        int bad = 0;']
AUD.extend(pin_lines(NEWPINS))
AUD.extend(NAME_LINES)
AUD.extend([
    '        // ---- the cross-checks',
    '        // ----',
    '            // the large suit stands',
    '            // six inches taller than',
    '            // the normal, and carries',
    '            // fifty more pounds',
    '            if (uaaspEcmManLargeHeight'
    'In()',
    '                    - uaaspEcmManNormal'
    'HeightIn()',
    '                    != 6) ++bad;',
    '            if (uaaspEcmManNormalHeight'
    'In()',
    '                    != 12 * 6) ++bad;',
    '            // the thrown-dagger range',
    '            // ladder steps two inches',
    '            // at a time, 2, 4, 6',
    '            if (uamwDthShortRangeIn()',
    '                    + 2 != uamwDth'
    'MediumRangeIn())',
    '                ++bad;',
    '            if (uamwDthMediumRangeIn()',
    '                    + 2 != uamwDth'
    'HurledRangeIn())',
    '                ++bad;',
    '            // the eight weekly 12',
    '            // 1/2% chances sum to a',
    '            // full 100% expectation',
    '            if (uamwAohFamWeeksFull()',
    '                    * uamwAohFamChance'
    'PctX2()',
    '                    != 200) ++bad;',
    '            // the horn band runs a',
    "            // half foot to one and",
    '            // a quarter feet, 6 and',
    '            // 15 inches',
    '            if (5 * uamwHblHornLength'
    'LoIn()',
    '                    != 2 * uamwHbl'
    'HornLengthHiIn())',
    '                ++bad;',
    '        // ---- the ledger seam ----',
    '            // both part ledgers run',
    '            // clean, no flags',
    '            if (uaaspPartCleanCount()',
    '                    != uaaspPart'
    'ItemTotal())',
    '                ++bad;',
    '            if (uaaspPartFlagged'
    'Count()',
    '                    != 0) ++bad;',
    '            if (uamwPartCleanCount()',
    '                    != uamwPart'
    'ItemTotal())',
    '                ++bad;',
    '            if (uamwPartFlagged'
    'Count()',
    '                    != 0) ++bad;',
    '        printf("R399 UA armor weapons'
    ' holes pin audit: bad %d' + chr(92)
    + 'n", bad);',
    '        if (bad) return 1;',
    '    }'])

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, NL.join(AUD) + NL + R227,
     'regtest: the R399 audit block')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 326:
    die('the census %d' % s.count('audit: bad'))
if s.count('R399 UA armor weapons'
           ' holes pin audit') != 1:
    die('the R399 audit label')

for nm in FLAGS:
    if ('!' + nm + '()') in s:
        die('the %s old assert' % nm)
    if s.count('%s()' % nm) != 1:
        die('the %s assert count' % nm)

for expr, val, cnt in (
        ('uaaspPartCleanCount()', 8, 2),
        ('uaaspPartFlaggedCount()', 0, 2),
        ('uamwPartCleanCount()', 9, 1),
        ('uamwPartFlaggedCount()', 0, 1)):
    oA, oB = forms('%s != %d'
                   % (expr, val))
    n = s.count(oA) + s.count(oB)
    if n != cnt:
        die('the flipped %s count %d'
            % (expr, n))

if s.count('uaaspFwbAppellation') != 9:
    die('the appellation count %d'
        % s.count('uaaspFwbAppellation'))
if s.count('uamwDthShortRangeIn()') != 2:
    die('the dagger short count')
if s.count('uamwHblHornLengthLoIn()') != 2:
    die('the horn lo count')

WANT_INLINE = {P1: 110, P2: 204}
WANT_FALSE = {P1: 4, P2: 3}

for path in (P1, P2):
    p = rd(path)
    if p.count('inline') \
            != WANT_INLINE[path]:
        die('%s inline count %d,'
            ' expected %d'
            % (path, p.count('inline'),
               WANT_INLINE[path]))
    if p.count('return false;') \
            != WANT_FALSE[path]:
        die('%s false count %d,'
            ' expected %d'
            % (path, p.count('return false;'),
               WANT_FALSE[path]))
    if not p.endswith(NL):
        die('%s trailing newline' % path)

g = rd(GP)
if g.count('AMENDED R399') != 2:
    die('the gap amended count %d'
        % g.count('AMENDED R399'))

print('R399 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the clean read fills every'
      ' flagged hole')
print('  the two treasure prose headers'
      ' carry - all seven')
print('  flags drop, the Final Word nine'
      ' appellations pin,')
print('  and both part ledgers run clean;'
      ' census 325 -> 326')
print('commit: R399: the UA armor swords'
      ' misc weapons flagged holes'
      ' completion (census 326)')

