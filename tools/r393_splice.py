
#!/usr/bin/env python3
# R393: the PDF-read completion sweep
#
# The clean PDF extract (the R392
# OCR pass, 130 pages) fills the
# holes the three fragment rounds
# flagged "stays open pending the
# PDF read":
#
# 1. rules/weaponspec.h (R331): the
#    Weapon Specialization Table - all
#    24 cells now read (the six
#    fragment cells seam-agree row for
#    row); the superseding note pins.
# 2. rules/thiefarmor.h (R334): the
#    Thieves Table II holes (the Open
#    Locks cells, the no-armor dashes)
#    fill; the attacks band-2 rate
#    reads 2/1; the footnote-1 tail
#    prints in full; the Hide in
#    Shadows footnote-4 marker prints
#    orphaned (no text anywhere) -
#    flagged as the print anomaly.
# 3. rules/uailacquisition.h (R365):
#    the illusionist starting list
#    reads column-wise in full; the
#    R365 interleave decode corrected
#    (Darkness defensive row 2, Phantom
#    Armor defensive row 5, Chromatic
#    Orb plain, Spook offensive row 6).
#
# The regtest R331/R334/R365 audit
# blocks amend to the filled reads
# (the R391b precedent); a new R393
# audit block lands before the R227
# anchor; the census 319 -> 320. The
# gap report flips close; the seed
# takes the R392 record (and repairs
# the R392 seed-insert glue).
import io

NL = '\n'

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def B(*lines):
    return NL.join(lines) + NL


def die(msg):
    raise SystemExit('R393 splice ABORT: ' + msg)


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
s = rd(SD)

GLUE_OLD = ('  the first run.- R391 landed'
            ' 2026-10-12: commit')
GLUE_NEW = ('  the first run.' + NL +
            '- R391 landed 2026-10-12: commit')
if GLUE_NEW in s:
    already.append('seed: the R391 glue repair')
elif GLUE_OLD in s:
    if s.count(GLUE_OLD) != 1:
        die('the R391 glue appears %d times'
            % s.count(GLUE_OLD))
    s = s.replace(GLUE_OLD, GLUE_NEW)
    wr(SD, s)
    applied.append('seed: the R391 glue repair')
else:
    die('the R391 glue not found and not '
        'repaired - inspect the seed')

s = rd(SD)
SEED_ENTRY = B(
    '- R392 landed 2026-10-12: 6cfd9c2',
    '  committed RED plus the R392b',
    '  repair a4bef30 (pushed',
    '  together, b23846f..a4bef30),',
    '  census 319, the UA players',
    '  tables manifest sweep (pp.',
    '  26-28, 20 manifest items): the',
    '  equipment costs and hand-held',
    '  tables pin NEW (uaequip26.h,',
    '  uahandheld.h), the',
    '  weight/damage, missile and',
    '  proficiency tables amend; the',
    '  clean PDF read fills every hole',
    '  (the garrot L 1-6, the 68th',
    '  row, the rate/range columns,',
    '  the AC 7-10 ladders, the',
    '  facing-page notes); the',
    '  manifest closes; the R392',
    '  lesson: the sim pass validates',
    '  semantics, not emitted C - four',
    '  C defects (a [1:-1] opener',
    '  strip, an unescaped inches',
    '  quote, two flipped return',
    '  types) shipped past it; every',
    '  round now gets the static',
    '  header check; commit only on',
    '  GREEN.').rstrip(NL)
ANCH = NL + '## Knowledge maintenance'
if 'R392 landed 2026-10-12' in s:
    already.append('seed: the R392 record')
else:
    if s.count(ANCH) != 1:
        die('the seed anchor count %d'
            % s.count(ANCH))
    s = s.replace(ANCH, NL + SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R392 record')
s = rd(SD)
if s.count('R392 landed 2026-10-12') != 1:
    die('the R392 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ============ (b) rules/weaponspec.h ============
WS = 'rules/weaponspec.h'

pair(WS,
     B('// The Weapon Specialization Table: the',
       '// column titles, the three level bands',
       '// and six cleanly readable cells are',
       '// pinned (weaponSpecTableCellKnown).',
       '// The other eighteen cells are',
       '// OCR-mangled in the extract (the',
       '// fractions lost their slashes and',
       '// digits: "21", "mn", "3n", "an",',
       '// "4an", "51", "2n", "312", "81") with',
       '// no consistent decode - they read',
       '// empty, documented here and in the gap',
       '// report item, which stays OPEN until',
       "// the PDF read. The 1-6 row's light-",
       '// crossbow cell is blank in the',
       '// extract. The crossbow medium-range',
       '// read (+1 hit, no damage bonus) is',
       '// fragment-verified in the scrambled',
       '// tail (the R329 discipline).').rstrip(NL),
     B('// The Weapon Specialization Table: the',
       '// R393 clean PDF read pins all 24',
       '// cells (weaponSpecTableCellKnown) -',
       '// the six R331 fragment cells seam-',
       '// agree row for row (melee and other',
       '// missiles 3/2 at 1-6 and 5/2 at 13+,',
       '// light crossbow and lasso/staff',
       '// sling 3/2 at 7-12). The 1-6 row',
       '// reads 3/2, 2/1, 1/1, 1/2, 1/1,',
       '// 3/1, 4/1, 3/2; the 7-12 row 2/1,',
       '// 3/1, 3/2, 1/1, 3/2, 4/1, 5/1, 2/1;',
       '// the 13+ row 5/2, 4/1, 2/1, 3/2,',
       '// 2/1, 5/1, 6/1, 5/2. The printed',
       '// note: the table supersedes the',
       '// Attacks Per Melee Round Table for',
       '// specialists. The crossbow medium-',
       '// range read (+1 hit, no damage',
       '// bonus) is fragment-verified in the',
       '// scrambled tail (the R329'
       ' discipline).').rstrip(NL),
     'weaponspec.h: the header comment')

pair(WS,
     B('// The cleanly readable cells: melee and',
       '// other-missiles 3/2 at 1-6 and 5/2 at',
       '// 13+; light crossbow and lasso/staff',
       '// sling 3/2 at 7-12. Every other cell',
       '// (and the 1-6 light-crossbow cell,',
       '// blank in the extract) reads empty -',
       '// the OCR-lost fraction cells',
       '// (documented in the header comment).',
       'inline const char*'
       ' weaponSpecTableCellKnown(',
       '        int band, int col) {',
       '    if (band == 0 && col == 0)'
       ' return "3/2";',
       '    if (band == 0 && col == 7)'
       ' return "3/2";',
       '    if (band == 1 && col == 2)'
       ' return "3/2";',
       '    if (band == 1 && col == 4)'
       ' return "3/2";',
       '    if (band == 2 && col == 0)'
       ' return "5/2";',
       '    if (band == 2 && col == 7)'
       ' return "5/2";',
       '    return "";',
       '}').rstrip(NL),
     B('// The R393 clean read: all 24 cells.',
       'inline const char*'
       ' weaponSpecTableCellKnown(',
       '        int band, int col) {',
       '    static const char* const k[3][8]'
       ' = {',
       '        {"3/2", "2/1", "1/1", "1/2",',
       '         "1/1", "3/1", "4/1", "3/2"},',
       '        {"2/1", "3/1", "3/2", "1/1",',
       '         "3/2", "4/1", "5/1", "2/1"},',
       '        {"5/2", "4/1", "2/1", "3/2",',
       '         "2/1", "5/1", "6/1", "5/2"}',
       '    };',
       '    if (band < 0) band = 0;',
       '    if (band > 2) band = 2;',
       '    if (col < 0) col = 0;',
       '    if (col > 7) col = 7;',
       '    return k[band][col];',
       '}',
       '',
       '// The printed note under the table:',
       '// the figures supersede the Attacks',
       '// Per Melee Round Table whenever the',
       '// specialist wields the special',
       '// weapon.',
       'inline bool'
       ' weaponSpecTableSupersedes()',
       '    { return true; }').rstrip(NL),
     'weaponspec.h: the 24-cell table')

# ============ (c) rules/thiefarmor.h ============
TA = 'rules/thiefarmor.h'

pair(TA,
     B('//   - the attacks table: the band row'
       ' labels read clean for all',
       '//     five classes; the band-0 rate'
       ' (1/1 round) is verified twice,',
       '//     the band-1 rate (3/2 rounds)'
       ' once, the band-3 rate (5/2',
       '//     rounds) twice (cavalier 16th'
       ' and paladin 19th). The band-2',
       '//     rate cells (fighter 13th up'
       ' through paladin 12-18) print',
       '//     empty in the extract - a'
       ' documented hole, 0/0, pending the',
       '//     PDF. The paladin band edges'
       ' print 7-12 then 12-18 - the',
       '//     printed overlap at 12th'
       ' pinned as printed.',
       '//',
       '// OCR holes (the item stays open'
       ' pending the PDF read): the Open',
       "// Locks row's \"5% / -\" tokens"
       ' (sign and column assignment lost),',
       '// the no-armor cells that print no'
       ' token (Open Locks, Find/Remove',
       '// Traps, Hear Noise), the attacks'
       ' band-2 rate, and the footnote-1',
       '// tail (the bracers/cloak clause'
       ' survives only as fragments).').rstrip(NL),
     B('//   - the attacks table: the band row'
       ' labels read clean for all',
       '//     five classes; the R393 clean'
       ' print fills the band-2 rate',
       '//     (2/1 round) - the band-0'
       ' (1/1), band-1 (3/2) and',
       '//     band-3 (5/2) fragment reads'
       ' seam-agree. The paladin band',
       '//     edges print 7-12 then 12-18 -'
       ' the printed overlap at 12th',
       '//     pinned as printed.',
       '//',
       '// R393 (the clean PDF read): every'
       ' OCR hole fills. The Open Locks',
       '// row reads dash / -5% / -10%; the'
       ' no-armor cells that printed no',
       '// token read as printed dashes'
       ' (Find/Remove Traps, Hear Noise -',
       '// the R184 dash convention, 0); the'
       ' attacks band-2 rate reads 2/1'
       ' round;',
       '// the footnote-1 tail prints in'
       ' full (bracers of defense and/or a'
       ' cloak,',
       '// but no large protective devices).'
       ' One print anomaly stays',
       '// flagged: the Hide in Shadows row'
       ' carries a footnote-4 marker',
       '// whose text prints nowhere on the clean',
       '// page - pinned as the orphaned marker.'
       ).rstrip(NL),
     'thiefarmor.h: the header comment')

pair(TA,
     B('// ---- the cells (p. 22) ----',
       '// function 0-7, category 0-2 (0 = no',
       '// armor, 1 = elfin chain, 2 = studded',
       '// or padded). The lost cells read as',
       '// holes below; the printed dashes read',
       '// as 0.',
       'inline bool thiefArmorCellIsHole(',
       '        int function, int category) {',
       '    switch (function) {',
       '        case 1:     // Open Locks',
       '            return category <= 1;',
       '        case 2:     // Find/Remove'
       ' Traps',
       '        case 5:     // Hear Noise',
       '            return category == 0;',
       '        default:',
       '            return false;',
       '    }',
       '}').rstrip(NL),
     B('// ---- the cells (p. 22, the R393',
       '// clean read) ----',
       '// function 0-7, category 0-2 (0 = no',
       '// armor, 1 = elfin chain, 2 = studded',
       '// or padded). Every cell reads; the',
       '// printed dashes read as 0 (the R184',
       '// dash convention).',
       'inline bool thiefArmorCellIsHole(',
       '        int function, int category) {',
       '    // R393: every hole fills - no',
       '    // cell is a hole any longer',
       '    (void) function;',
       '    (void) category;',
       '    return false;',
       '}').rstrip(NL),
     'thiefarmor.h: the hole map')

pair(TA,
     '        {0, 0, -10},     // Open Locks',
     '        {0, -5, -10},    // Open Locks',
     'thiefarmor.h: the Open Locks row')

pair(TA,
     B('// ---- the footnotes (p. 22) ----',
       '// Footnote 2: no dexterity bonuses',
       '// apply to thief functions (though',
       '// penalties do) in armor other than',
       '// simple leather. Footnote 3: the',
       '// armor is assumed covered by another',
       '// garment - elfin chain under normal',
       '// clothing, studded leather only by a',
       "// full body cloak. Footnote 1's tail",
       '// is OCR-lost; the surviving fragments',
       '// (cloak but no large protective',
       '// devices; of defense and/or a) fix',
       '// the no-armor clause as bracers',
       "// and/or cloak - pinned as the",
       "// clause's existence only."
       ).rstrip(NL),
     B('// ---- the footnotes (p. 22, the',
       '// R393 clean read) ----',
       '// Footnote 1 prints in full: the',
       '// no-armor category applies when',
       '// wearing bracers of defense',
       '// and/or a cloak, but no large',
       '// protective devices. Footnote 2: no',
       '// dexterity bonuses apply to thief',
       '// functions (though penalties do) in',
       '// armor other than simple leather.',
       '// Footnote 3: the armor is assumed',
       '// covered by another garment - elfin',
       '// chain under normal clothing,',
       '// studded leather only by a full',
       '// body cloak. The Hide in Shadows',
       '// row carries a footnote-4 marker',
       '// whose text prints nowhere - the',
       '// orphaned marker pinned as such.'
       ).rstrip(NL),
     'thiefarmor.h: the footnote comment')

pair(TA,
     B('inline bool'
       ' thiefArmorNoArmorBracersOrCloak()',
       '    { return true; }').rstrip(NL),
     B('inline bool'
       ' thiefArmorNoArmorBracersOrCloak()',
       '    { return true; }',
       '',
       '// R393: the footnote-1 tail prints',
       '// in full; the footnote-4 marker',
       '// prints with no text anywhere.',
       'inline bool'
       ' thiefArmorFootnoteOnePrintsInFull()',
       '    { return true; }',
       '',
       'inline bool'
       ' thiefArmorNoArmorLargeDevicesBarred()',
       '    { return true; }',
       '',
       'inline bool'
       ' thiefArmorFootnoteFourOrphaned()',
       '    { return true; }').rstrip(NL),
     'thiefarmor.h: the footnote pins')

pair(TA,
     B('// ---- the bands (p. 22) ----',
       '// Four bands: 1/1 round, 3/2 rounds,',
       '// the OCR-lost high band, 5/2 rounds',
       '// (cavalier 16th up, paladin 19th',
       '// up). Fighter, barbarian and ranger',
       '// print three bands; cavalier and',
       '// paladin four.').rstrip(NL),
     B('// ---- the bands (p. 22, the R393',
       '// clean read) ----',
       '// Four bands: 1/1 round, 3/2',
       '// rounds, 2/1 round (the clean',
       '// read fills the lost rate), 5/2',
       '// rounds (cavalier 16th up,',
       '// paladin 19th up). Fighter,',
       '// barbarian and ranger print',
       '// three bands; cavalier and',
       '// paladin four.').rstrip(NL),
     'thiefarmor.h: the bands comment')

pair(TA,
     '    static const int k[4] = {1, 3, 0, 5};',
     '    static const int k[4] = {1, 3, 2, 5};',
     'thiefarmor.h: the band attacks')

pair(TA,
     '    static const int k[4] = {1, 2, 0, 2};',
     '    static const int k[4] = {1, 2, 1, 2};',
     'thiefarmor.h: the band rounds')

# ========== (d) rules/uailacquisition.h ==========
UA = 'rules/uailacquisition.h'

pair(UA,
     B('// JUDGMENTs (the decode method):',
       '//   - the starting-list table'
       ' interleaves: the',
       '//     defensive rows print legibly'
       ' (the five',
       '//     numbered rows with the'
       ' multi-name cells);',
       '//     the offensive and misc columns'
       ' merge into',
       '//     one garbled block (Change Self'
       ' through',
       '//     Phantom Armor with two choose'
       ' markers) -',
       '//     the row boundaries are lost,'
       ' holes pending',
       '//     the PDF; the fragment names'
       ' pin.').rstrip(NL),
     B('// JUDGMENTs (the decode method):',
       '//   - R393 (the clean PDF read,'
       ' p. 80): the',
       '//     starting-list table decodes'
       ' column-wise',
       '//     in full - three columns, six'
       ' rows each;',
       '//     the R365 interleave decode'
       ' corrects',
       '//     (Darkness defensive row 2,'
       ' Phantom',
       '//     Armor defensive row 5,'
       ' Chromatic Orb',
       '//     plain, Spook offensive row 6);'
       ' the',
       '//     (choose) markers read as the'
       ' defensive',
       '//     row 6 and the misc rows 5-6,'
       ' the',
       '//     asterisk on the misc row 6.').rstrip(NL),
     'uailacquisition.h: the interleave'
     ' judgment')

pair(UA,
     B('//   - the chromatic orb row prints'
       ' with the',
       '//     (choose) marker and the'
       ' UA-addition note',
       '//     prints clean (spells from this'
       ' work were',
       '//     added to the initial lists for'
       ' illusionists',
       '//     only, not for magic-users).').rstrip(NL),
     B('//   - the chromatic orb row prints'
       ' plain (the',
       '//     R365 (choose) read corrects)'
       ' and the',
       '//     UA-addition note prints clean'
       ' (spells from this'
       ' work were',
       '//     added to the initial lists for'
       ' illusionists',
       '//     only, not for'
       ' magic-users).').rstrip(NL),
     'uailacquisition.h: the chromatic'
     ' orb judgment')

pair(UA,
     B('// The defensive rows: 1 - color spray,'
       ' audible',
       '// glamer, darkness; 2 - hypnotism;'
       ' 3 - light,',
       '// gaze reflection; 4 - phantasmal'
       ' force, wall of',
       '// fog; 5 - chromatic orb (choose).',
       'inline int uailaDefensiveRowCount()',
       '    { return 5; }',
       '',
       'inline bool uailaRow1ColorSpray()',
       '    { return true; }',
       '',
       'inline bool uailaRow1AudibleGlamer()',
       '    { return true; }',
       '',
       'inline bool uailaRow1Darkness()',
       '    { return true; }',
       '',
       'inline bool uailaRow2Hypnotism()',
       '    { return true; }',
       '',
       'inline bool uailaRow3Light()',
       '    { return true; }',
       '',
       'inline bool uailaRow3GazeReflection()',
       '    { return true; }',
       '',
       'inline bool uailaRow4PhantasmalForce()',
       '    { return true; }',
       '',
       'inline bool uailaRow4WallOfFog()',
       '    { return true; }',
       '',
       'inline bool uailaRow5ChromaticOrb()',
       '    { return true; }',
       '',
       'inline bool uailaRow5ChromaticOrbIsChoose()',
       '    { return true; }',
       '',
       'inline bool uailaOffensiveMiscColumnsMerged()',
       '    { return true; }',
       '',
       'inline bool uailaMiscChangeSelf()',
       '    { return true; }',
       '',
       'inline bool uailaMiscDancingLights()',
       '    { return true; }',
       '',
       'inline bool uailaMiscDetect()',
       '    { return true; }',
       '',
       'inline bool uailaMiscDetectInvisibility()',
       '    { return true; }',
       '',
       'inline bool uailaMiscPhantomArmor()',
       '    { return true; }',
       '',
       'inline bool uailaRowBoundariesLost()',
       '    { return true; }').rstrip(NL),
     B('// The R393 clean read (p. 80): the',
       '// starting list decodes column-wise,',
       '// three columns with six rows each.',
       '// Offensive: 1 - color spray; 2 -',
       '// hypnotism; 3 - light; 4 - phantasmal',
       '// force; 5 - chromatic orb (plain);',
       '// 6 - spook. Defensive: 1 - audible',
       '// glamer; 2 - darkness; 3 - gaze',
       '// reflection; 4 - wall of fog; 5 -',
       '// phantom armor; 6 - (choose).',
       '// Misc: 1 - change self; 2 - dancing',
       '// lights; 3 - detect illusion; 4 -',
       '// detect invisibility; 5 - (choose);',
       '// 6 - (choose)*.',
       'inline int uailaOffensiveRowCount()',
       '    { return 6; }',
       '',
       'inline int uailaDefensiveRowCount()',
       '    { return 6; }',
       '',
       'inline int uailaMiscRowCount()',
       '    { return 6; }',
       '',
       'inline bool uailaOffRow1ColorSpray()',
       '    { return true; }',
       '',
       'inline bool uailaOffRow2Hypnotism()',
       '    { return true; }',
       '',
       'inline bool uailaOffRow3Light()',
       '    { return true; }',
       '',
       'inline bool uailaOffRow4PhantasmalForce()',
       '    { return true; }',
       '',
       'inline bool uailaOffRow5ChromaticOrb()',
       '    { return true; }',
       '',
       'inline bool uailaChromaticOrbPrintsPlain()',
       '    { return true; }',
       '',
       'inline bool uailaOffRow6Spook()',
       '    { return true; }',
       '',
       'inline bool uailaDefRow1AudibleGlamer()',
       '    { return true; }',
       '',
       'inline bool uailaDefRow2Darkness()',
       '    { return true; }',
       '',
       'inline bool uailaDefRow3GazeReflection()',
       '    { return true; }',
       '',
       'inline bool uailaDefRow4WallOfFog()',
       '    { return true; }',
       '',
       'inline bool uailaDefRow5PhantomArmor()',
       '    { return true; }',
       '',
       'inline bool uailaDefRow6IsChoose()',
       '    { return true; }',
       '',
       'inline bool uailaMiscRow1ChangeSelf()',
       '    { return true; }',
       '',
       'inline bool uailaMiscRow2DancingLights()',
       '    { return true; }',
       '',
       'inline bool uailaMiscRow3DetectIllusion()',
       '    { return true; }',
       '',
       'inline bool uailaMiscRow4DetectInvisibility()',
       '    { return true; }',
       '',
       'inline bool uailaMiscRow5IsChoose()',
       '    { return true; }',
       '',
       'inline bool uailaMiscRow6IsChooseAsterisk()',
       '    { return true; }',
       '',
       'inline bool uailaColumnsDecodeColumnWise()',
       '    { return true; }').rstrip(NL),
     'uailacquisition.h: the column-wise'
     ' decode')

# ============ (e) regtest.cpp ============
RT = 'regtest.cpp'

pair(RT,
     B('        // U8: the table structure - the',
       '        // columns, the bands, the clean',
       '        // cells, the empty holes'
     ).rstrip(NL),
     B('        // U8: the table structure - the',
       '        // columns, the bands, all 24',
       '        // cells read (the R393 clean',
       '        // read; the superseding note',
       '        // pins)'
     ).rstrip(NL),
     'regtest.cpp: the R331 U8 comment')

pair(RT,
     B('            // the OCR-lost cells read empty',
       '            if (weaponSpecTableCellKnown(0, 1)[0]',
       '                != 0) ++bad;',
       '            if (weaponSpecTableCellKnown(0, 2)[0]',
       '                != 0) ++bad;',
       '            if (weaponSpecTableCellKnown(0, 3)[0]',
       '                != 0) ++bad;',
       '            if (weaponSpecTableCellKnown(1, 5)[0]',
       '                != 0) ++bad;',
       '            if (weaponSpecTableCellKnown(2, 3)[0]',
       '                != 0) ++bad;'
     ).rstrip(NL),
     B('            // the R393 clean read fills',
       '            // the lost cells',
       '            if (strcmp(weaponSpecTableCellKnown(',
       '                0, 1), "2/1") != 0) ++bad;',
       '            if (strcmp(weaponSpecTableCellKnown(',
       '                0, 2), "1/1") != 0) ++bad;',
       '            if (strcmp(weaponSpecTableCellKnown(',
       '                0, 3), "1/2") != 0) ++bad;',
       '            if (strcmp(weaponSpecTableCellKnown(',
       '                1, 5), "4/1") != 0) ++bad;',
       '            if (strcmp(weaponSpecTableCellKnown(',
       '                2, 3), "3/2") != 0) ++bad;'
     ).rstrip(NL),
     'regtest.cpp: the R331 U8 cells')

pair(RT,
     B('        // U3: the OCR holes',
       '        {',
       '            if (!thiefArmorCellIsHole(1, 0))',
       '                ++bad;',
       '            if (!thiefArmorCellIsHole(1, 1))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(1, 2))',
       '                ++bad;',
       '            if (!thiefArmorCellIsHole(2, 0))',
       '                ++bad;',
       '            if (!thiefArmorCellIsHole(5, 0))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(0, 0)) ++bad;',
       '            if (thiefArmorCellIsHole(4, 1)) ++bad;',
       '        }'
     ).rstrip(NL),
     B('        // U3: the R393 clean read -',
       '        // every hole fills',
       '        {',
       '            if (thiefArmorCellIsHole(1, 0))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(1, 1))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(1, 2))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(2, 0))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(5, 0))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(0, 0)) ++bad;',
       '            if (thiefArmorCellIsHole(4, 1)) ++bad;',
       '            // Open Locks reads 0/-5/-10;',
       '            // the no-armor dashes read 0',
       '            if (thiefArmorModifierKnown(1, 0)',
       '                != 0) ++bad;',
       '            if (thiefArmorModifierKnown(1, 1)',
       '                != -5) ++bad;',
       '            if (thiefArmorModifierKnown(1, 2)',
       '                != -10) ++bad;',
       '            if (thiefArmorModifierKnown(2, 0)',
       '                != 0) ++bad;',
       '            if (thiefArmorModifierKnown(5, 0)',
       '                != 0) ++bad;',
       '        }'
     ).rstrip(NL),
     'regtest.cpp: the R334 U3 fills')

pair(RT,
     B('            if (!thiefArmorNoArmorBracersOrCloak())',
       '                ++bad;',
       '        }'
     ).rstrip(NL),
     B('            if (!thiefArmorNoArmorBracersOrCloak())',
       '                ++bad;',
       '            if (!thiefArmorFootnoteOnePrintsInFull())',
       '                ++bad;',
       '            if (!thiefArmorNoArmorLargeDevicesBarred())',
       '                ++bad;',
       '            if (!thiefArmorFootnoteFourOrphaned())',
       '                ++bad;',
       '        }'
     ).rstrip(NL),
     'regtest.cpp: the R334 U4 footnotes')

pair(RT,
     B('        // U6: the band routing and the',
       '        // verified rates (the high band',
       '        // is a documented 0/0 hole)'
     ).rstrip(NL),
     B('        // U6: the band routing and the',
       '        // verified rates (the R393 clean',
       '        // read: the high band is 2/1)'
     ).rstrip(NL),
     'regtest.cpp: the R334 U6 comment')

pair(RT,
     B('            if (uaAttacksBandAttacks(2) != 0)',
       '                ++bad;',
       '            if (uaAttacksBandRounds(2) != 0)',
       '                ++bad;'
     ).rstrip(NL),
     B('            if (uaAttacksBandAttacks(2) != 2)',
       '                ++bad;',
       '            if (uaAttacksBandRounds(2) != 1)',
       '                ++bad;'
     ).rstrip(NL),
     'regtest.cpp: the R334 U6 band rates')

pair(RT,
     B('            if (uailaDefensiveRowCount() != 5) ++bad;',
       '            if (!uailaRow1ColorSpray()) ++bad;',
       '            if (!uailaRow1AudibleGlamer()) ++bad;',
       '            if (!uailaRow1Darkness()) ++bad;',
       '            if (!uailaRow2Hypnotism()) ++bad;',
       '            if (!uailaRow3Light()) ++bad;',
       '            if (!uailaRow3GazeReflection()) ++bad;',
       '            if (!uailaRow4PhantasmalForce()) ++bad;',
       '            if (!uailaRow4WallOfFog()) ++bad;',
       '            if (!uailaRow5ChromaticOrb()) ++bad;',
       '            if (!uailaRow5ChromaticOrbIsChoose()) ++bad;',
       '            if (!uailaOffensiveMiscColumnsMerged()) ++bad;',
       '            if (!uailaMiscChangeSelf()) ++bad;',
       '            if (!uailaMiscDancingLights()) ++bad;',
       '            if (!uailaMiscDetect()) ++bad;',
       '            if (!uailaMiscDetectInvisibility()) ++bad;',
       '            if (!uailaMiscPhantomArmor()) ++bad;',
       '            if (!uailaRowBoundariesLost()) ++bad;'
     ).rstrip(NL),
     B('            if (uailaOffensiveRowCount() != 6)',
       '                ++bad;',
       '            if (uailaDefensiveRowCount() != 6)',
       '                ++bad;',
       '            if (uailaMiscRowCount() != 6) ++bad;',
       '            if (!uailaOffRow1ColorSpray()) ++bad;',
       '            if (!uailaOffRow2Hypnotism()) ++bad;',
       '            if (!uailaOffRow3Light()) ++bad;',
       '            if (!uailaOffRow4PhantasmalForce())',
       '                ++bad;',
       '            if (!uailaOffRow5ChromaticOrb())',
       '                ++bad;',
       '            if (!uailaChromaticOrbPrintsPlain())',
       '                ++bad;',
       '            if (!uailaOffRow6Spook()) ++bad;',
       '            if (!uailaDefRow1AudibleGlamer())',
       '                ++bad;',
       '            if (!uailaDefRow2Darkness()) ++bad;',
       '            if (!uailaDefRow3GazeReflection())',
       '                ++bad;',
       '            if (!uailaDefRow4WallOfFog()) ++bad;',
       '            if (!uailaDefRow5PhantomArmor())',
       '                ++bad;',
       '            if (!uailaDefRow6IsChoose()) ++bad;',
       '            if (!uailaMiscRow1ChangeSelf())',
       '                ++bad;',
       '            if (!uailaMiscRow2DancingLights())',
       '                ++bad;',
       '            if (!uailaMiscRow3DetectIllusion())',
       '                ++bad;',
       '            if (!uailaMiscRow4DetectInvisibility())',
       '                ++bad;',
       '            if (!uailaMiscRow5IsChoose()) ++bad;',
       '            if (!uailaMiscRow6IsChooseAsterisk())',
       '                ++bad;',
       '            if (!uailaColumnsDecodeColumnWise())',
       '                ++bad;'
     ).rstrip(NL),
     'regtest.cpp: the R365 start list')

pair(RT,
     B('    // ---- R227: the wis mental save wiring audit ----'
     ).rstrip(NL),
     B('    // ---- R393: the PDF-read completion sweep',
       '    // pin audit ----',
       '    // The clean PDF read fills the three',
       '    // fragment-round holes; the amended',
       '    // R331/R334/R365 blocks cross-check',
       '    // here at the seams.',
       '    {',
       '        using namespace rules;',
       '        int bad = 0;',
       '        // U1: the spec-table corners',
       '        {',
       '            if (strcmp(',
       '                weaponSpecTableCellKnown(0, 3),',
       '                "1/2") != 0) ++bad;',
       '            if (strcmp(',
       '                weaponSpecTableCellKnown(1, 6),',
       '                "5/1") != 0) ++bad;',
       '            if (strcmp(',
       '                weaponSpecTableCellKnown(2, 4),',
       '                "2/1") != 0) ++bad;',
       '            if (!weaponSpecTableSupersedes())',
       '                ++bad;',
       '        }',
       '        // U2: the seam - the lasso/staff',
       '        // sling 13+ cell equals the',
       '        // attacks band-2 rate',
       '        {',
       '            if (strcmp(',
       '                weaponSpecTableCellKnown(2, 4),',
       '                "2/1") != 0) ++bad;',
       '            if (uaAttacksBandAttacks(2) != 2)',
       '                ++bad;',
       '            if (uaAttacksBandRounds(2) != 1)',
       '                ++bad;',
       '        }',
       '        // U3: the thief fills',
       '        {',
       '            if (thiefArmorCellIsHole(1, 0))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(1, 1))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(2, 0))',
       '                ++bad;',
       '            if (thiefArmorCellIsHole(5, 0))',
       '                ++bad;',
       '            if (thiefArmorModifierKnown(1, 0)',
       '                != 0) ++bad;',
       '            if (thiefArmorModifierKnown(1, 1)',
       '                != -5) ++bad;',
       '            if (thiefArmorModifierKnown(1, 2)',
       '                != -10) ++bad;',
       '            if (!thiefArmorFootnoteOnePrintsInFull())',
       '                ++bad;',
       '            if (!thiefArmorNoArmorLargeDevicesBarred())',
       '                ++bad;',
       '            if (!thiefArmorFootnoteFourOrphaned())',
       '                ++bad;',
       '        }',
       '        // U4: the IL column-wise decode',
       '        {',
       '            if (uailaOffensiveRowCount() != 6)',
       '                ++bad;',
       '            if (uailaDefensiveRowCount() != 6)',
       '                ++bad;',
       '            if (uailaMiscRowCount() != 6) ++bad;',
       '            if (!uailaOffRow6Spook()) ++bad;',
       '            if (!uailaDefRow2Darkness()) ++bad;',
       '            if (!uailaDefRow5PhantomArmor())',
       '                ++bad;',
       '            if (!uailaChromaticOrbPrintsPlain())',
       '                ++bad;',
       '            if (!uailaMiscRow6IsChooseAsterisk())',
       '                ++bad;',
       '            if (!uailaColumnsDecodeColumnWise())',
       '                ++bad;',
       '        }',
       '        printf("R393 PDF-read completion'
       ' pin audit: bad %d\\n", bad);',
       '        if (bad) return 1;',
       '    }',
       '    // ---- R227: the wis mental save wiring audit ----'
     ).rstrip(NL),
     'regtest.cpp: the R393 audit block')

# ===== (f) tools/ua_gap_report.md =====
GP = 'tools/ua_gap_report.md'

pair(GP,
     B('- [ ] **Weapon specialization** (pp.',
       '      18-19) - fighter and ranger only,',
       '      chosen at creation; the slot costs',
       '      (2 slots melee; a bow costs a',
       '      third); melee +1 to hit/+2 damage;',
       '      **the Weapon Specialization Table**',
       '      (the attacks per round by level',
       '      band for melee, bow, light and',
       '      heavy crossbow, lasso and staff',
       '      sling, thrown dagger and dart,',
       '      other missiles); the bow point',
       '      blank (6-30, +2 and double damage,',
       '      the nocked-arrow pre-initiative',
       '      shot, short range +1); the',
       '      crossbow point blank (6-60, the',
       '      aimed shot); the double',
       '      specialization (+3/+3, melee only,',
       '      no pole arms or two-handed sword);',
       '      the bonuses are not magical.',
       '      - R331: the prose pinned',
       '      (rules/weaponspec.h) - the',
       '      class gate, the slot costs,',
       '      the melee/bow/crossbow',
       '      reads, the double, the table',
       '      structure with the cleanly',
       '      readable cells; the',
       "      table's fraction cells are",
       '      OCR-mangled (no consistent',
       '      decode) - stays open pending',
       '      the PDF read.'
     ).rstrip(NL),
     B('- [x] **Weapon specialization** (pp.',
       '      18-19) - fighter and ranger only,',
       '      chosen at creation; the slot costs',
       '      (2 slots melee; a bow costs a',
       '      third); melee +1 to hit/+2 damage;',
       '      **the Weapon Specialization Table**',
       '      (the attacks per round by level',
       '      band for melee, bow, light and',
       '      heavy crossbow, lasso and staff',
       '      sling, thrown dagger and dart,',
       '      other missiles); the bow point',
       '      blank (6-30, +2 and double damage,',
       '      the nocked-arrow pre-initiative',
       '      shot, short range +1); the',
       '      crossbow point blank (6-60, the',
       '      aimed shot); the double',
       '      specialization (+3/+3, melee only,',
       '      no pole arms or two-handed sword);',
       '      the bonuses are not magical.',
       '      - AMENDED R393: closed - the R331',
       '      pin (rules/weaponspec.h); the R393',
       '      clean PDF read fills all 24 table',
       '      cells (the six fragment cells',
       '      seam-agree row for row) and pins',
       '      the superseding note.'
     ).rstrip(NL),
     'gap report: the weapon spec item')

pair(GP,
     B('- [ ] **Thieves Table II** (p. 22) -',
       '      the armor-effects penalties on',
       '      thieving functions (non-leather',
       '      armor, the elfin chain read); the',
       '      **Attacks Per Melee Round Table**',
       '      (p. 22) pairs with it.',
       '      - R334: the fragment-verified',
       '      cells pinned (rules/thiefarmor.h)',
       '      - the armor columns, the eight',
       '      functions, the sign-carries-',
       '      column decode, the footnotes,',
       '      the attacks classes, band edges',
       '      and verified rates; the Open',
       '      Locks cells, the missing',
       '      no-armor cells, the attacks',
       '      high-band rate and the',
       '      footnote-1 tail are OCR-lost -',
       '      stays open pending the PDF read.'
     ).rstrip(NL),
     B('- [x] **Thieves Table II** (p. 22) -',
       '      the armor-effects penalties on',
       '      thieving functions (non-leather',
       '      armor, the elfin chain read); the',
       '      **Attacks Per Melee Round Table**',
       '      (p. 22) pairs with it.',
       '      - AMENDED R393: closed - the R334',
       '      pin (rules/thiefarmor.h); the R393',
       '      clean PDF read fills the Open Locks',
       '      cells (0/-5/-10), the no-armor',
       '      dashes, the attacks high-band rate',
       '      (2/1) and the footnote-1 tail; the',
       '      footnote-4 marker prints orphaned -',
       '      the print anomaly, documented.'
     ).rstrip(NL),
     'gap report: the thieves item')

pair(GP,
     B('- [ ] **Illusionist spell acquisition**',
       '      (p. 80) - the starting list table;',
       '      the illusionist book differences.',
       '      - R365: the fragment-verified',
       '        cells pinned',
       '        (rules/uailacquisition.h) -',
       '        the three-group start, the',
       '        five defensive rows, the',
       '        misc fragments, the DM',
       '        three-option note, the book',
       '        differences (24/16/8 and 6/4/2',
       '        with the MU first-level',
       '        book), the illusionist cantrip',
       '        counts; the offensive/misc row',
       '        boundaries garble - stays',
       '        open pending the PDF read.'
     ).rstrip(NL),
     B('- [x] **Illusionist spell acquisition**',
       '      (p. 80) - the starting list table;',
       '      the illusionist book differences.',
       '      - AMENDED R393: closed - the R365',
       '        pin (rules/uailacquisition.h);',
       '        the R393 clean PDF read decodes',
       '        the starting list column-wise in',
       '        full (the R365 interleave',
       '        corrected: Darkness defensive row',
       '        2, Phantom Armor row 5, Chromatic',
       '        Orb plain offensive row 5, Spook',
       '        row 6).'
     ).rstrip(NL),
     'gap report: the IL acquisition item')

# ===== (g) the census and sanity asserts =====
s = rd(RT)
if s.count('audit: bad ') != 320:
    die('the regtest census %d (want 320)'
        % s.count('audit: bad '))
if s.count(
    'R393 PDF-read completion pin audit:'
    ' bad ') != 1:
    die('the R393 audit count %d'
        % s.count(
        'R393 PDF-read completion pin'
        ' audit: bad '))
if s.count(
    'R392 UA players tables pin audit:'
    ' bad ') != 1:
    die('the kept R392 label')
if s.count(
    'R227: the wis mental save wiring'
    ' audit') != 1:
    die('the kept R227 anchor')
s = rd(GP)
if s.count('AMENDED R393') != 3:
    die('the gap report amended count %d'
        % s.count('AMENDED R393'))

print('R393 splice: ALL OK (applied %d,'
      ' already %d)'
      % (len(applied), len(already)))
print('NOTE: the clean print fills the'
      ' three-round holes')
print('  weaponspec.h: all 24 cells plus'
      ' the superseding note')
print('  thiefarmor.h: Open Locks'
      ' 0/-5/-10, no-armor dashes,'
      ' band-2 2/1, footnote-1 tail,'
      ' orphaned footnote-4 marker')
print('  uailacquisition.h: the IL'
      ' 18-cell column-wise decode')
print('  regtest census 319 -> 320')
print('commit: R393: the PDF-read'
      ' completion sweep (census 320)')

