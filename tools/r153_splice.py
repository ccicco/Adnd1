# tools/r153_splice.py - R153, eight patches: the PHB
# p.9 exceptional strength table pinned - a DIVERGENCE
# FIX round (the gap-report open box said: verify the
# abilities layer first; the verification found the
# ex-band data diverging from the printed table).
#
# (1) rules/character.h - the struct block: press() is
#     retired and the printed Table II columns replace
#     the unsourced carry/press numbers (the divergence
#     named in place); weightAllow becomes weightAllowGp
#     (+1,000..+3,000 as printed). (2) character.h -
#     the four full-table accessors declared. (3)
#     rules/character.cpp - the ex-band block corrected
#     to the printed rows (18/91-99 is +2/+5, not
#     +3/+6; 18/51-75 damage is +3, not +4). (4)
#     character.cpp - the full-table functions: weight
#     allowance (-350..+3,000 g.p.), open doors (1..1-5,
#     the locked parentheticals on 18/91-99 and 18/00
#     alone) and bend bars (0%..40%). (5) character.cpp
#     - the score-3 to-hit fix, found by the first run
#     of this round: strHitAdj banded score 3 with 4-5
#     at -2, but the printed row and the function is
#     own comment both read -3; the R153 audit caught
#     it (bad 1). (6) the regtest.cpp R153 audit block:
#     all 15 printed rows pinned cell for cell, the fold
#     edges both sides, and the replaces-not-adds rule
#     (census goes 71). (7) gap report header note. (8)
#     the exceptional-strength box flips closed.
#
# v2 NOTE: if the first version of this splice already
# ran (7 patches), patches 1-4 and 6-8 report already
# and only patch 5 applies - run it the same way. The
# percentile roll (rollExceptionalStrength) was already
# sound and is untouched. No callers used the retired
# press()/weightAllow() (verified), so the API change
# breaks nothing. The only other strHitAdj audit use is
# STR 17 (R144), unaffected by the score-3 fix.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). This file
# contains ZERO backslash characters and no content
# string embeds a literal apostrophe (the R133b + R147
# lessons - the anchors that need them build theirs
# from chr(92) and AP).
# Commit: "R153: exceptional strength pinned - STR
# Table II all five columns, band cells corrected
# (census 71)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
AP = chr(39)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

# ---- (1) rules/character.h: the struct block ----
h1_old = NL.join([
    '// The to-hit/damage/carry bands (PHB p.9) are indexed by 51/76/91/100.',
    '// ----------------------------------------------------------------------------',
    'struct ExceptionalStrength {',
    '    bool   has = false;     // only true for fighter group at STR 18',
    '    uint8_t pct = 0;        // 1-100; 100 printed as "00"',
    '',
    '    // PHB p.9 table (bands: 01-50, 51-75, 76-90, 91-99, 00)',
    '    int  hitAdj()    const;   // -1..+3 to hit',
    '    int  dmgAdj()    const;   // -1..+6 damage',
    '    int  weightAllow() const; // lbs before minor penalty',
    '    int  press()     const;   // max press lbs (informational)',
    '};',
])
h1_new = NL.join([
    '// The to-hit/damage/carry bands (PHB p.9) are indexed by 51/76/91/100.',
    '// R153 DIVERGENCE FIX: the original transcription carried',
    '// unsourced carry and press columns (35/45/55/70/80 lbs',
    '// and 90/130/160/200/240 press - neither prints on p.9)',
    '// and misread two band cells: the printed 18/91-99 row is',
    '// +2 hit / +5 damage (not +3/+6) and the 18/51-75 damage',
    '// is +3 (not +4). The printed Table II columns - gp weight',
    '// allowance, open doors on a d6 with the locked-door',
    '// parentheticals, bend bars/lift gates - replace them.',
    '// ----------------------------------------------------------------------------',
    'struct ExceptionalStrength {',
    '    bool   has = false;     // only true for fighter group at STR 18',
    '    uint8_t pct = 0;        // 1-100; 100 printed as "00"',
    '',
    '    // PHB p.9 Table II (bands: 01-50, 51-75, 76-90, 91-99, 00)',
    '    int  hitAdj()    const;   // +1..+3 to hit',
    '    int  dmgAdj()    const;   // +3..+6 damage',
    '    int  weightAllowGp() const;      // +1,000..+3,000 g.p.',
    '    int  openDoorsMax() const;       // the best d6 chance (3..5)',
    '    int  openDoorsLockedMax() const; // 18/91-99: 1, 18/00: 2',
    '    int  bendBarsPct() const;        // 20..40 percent',
    '};',
])

# ---- (2) rules/character.h: the full-table accessors ----
h2_old = NL.join([
    'int strHitAdj(uint8_t str, const ExceptionalStrength& ex);',
    'int strDmgAdj(uint8_t str, const ExceptionalStrength& ex);',
])
h2_new = NL.join([
    'int strHitAdj(uint8_t str, const ExceptionalStrength& ex);',
    'int strDmgAdj(uint8_t str, const ExceptionalStrength& ex);',
    '',
    '// ----------------------------------------------------------------------------',
    '// STR Table II (PHB p.9), R153: the printed weight-allowance,',
    '// open-doors and bend-bars columns for the whole 3-18/00 table.',
    '// ex carries the five 18/xx rows at STR 18; scores beyond 18',
    '// (gauntlets, giant strength) clamp to the plain 18 row -',
    '// the printed table stops there (documented clamp).',
    '// ----------------------------------------------------------------------------',
    'int strWeightAllowGp(uint8_t str, const ExceptionalStrength& ex);',
    'int strOpenDoorsMax(uint8_t str, const ExceptionalStrength& ex);',
    'int strOpenDoorsLockedMax(uint8_t str, const ExceptionalStrength& ex);',
    'int strBendBarsPct(uint8_t str, const ExceptionalStrength& ex);',
])

# ---- (3) rules/character.cpp: the ex-band block ----
c1_old = NL.join([
    '// ----------------------------------------------------------------------------',
    '// Exceptional strength (PHB p.9)',
    '//   Band          Hit adj  Dmg adj  Weight allow  Max press',
    '//   18/01-50      +1       +3       35            90',
    '//   18/51-75      +2       +4       45            130',
    '//   18/76-90      +2       +5       55            160',
    '//   18/91-99      +3       +6       70            200',
    '//   18/00         +3       +6       80            240',
    '// ----------------------------------------------------------------------------',
    '',
    'static int exBand(const ExceptionalStrength& ex) {',
    '    if (!ex.has) return -1;',
    '    if (ex.pct <= 50)  return 0;',
    '    if (ex.pct <= 75)  return 1;',
    '    if (ex.pct <= 90)  return 2;',
    '    if (ex.pct <= 99)  return 3;',
    '    return 4;   // 100 = "00"',
    '}',
    '',
    'int ExceptionalStrength::hitAdj() const {',
    '    static constexpr int adj[5]  = { 1, 2, 2, 3, 3 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : adj[b];',
    '}',
    '',
    'int ExceptionalStrength::dmgAdj() const {',
    '    static constexpr int adj[5]  = { 3, 4, 5, 6, 6 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : adj[b];',
    '}',
    '',
    'int ExceptionalStrength::weightAllow() const {',
    '    static constexpr int allow[5] = { 35, 45, 55, 70, 80 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : allow[b];',
    '}',
    '',
    'int ExceptionalStrength::press() const {',
    '    static constexpr int press[5] = { 90, 130, 160, 200, 240 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : press[b];',
    '}',
])
c1_new = NL.join([
    '// ----------------------------------------------------------------------------',
    '// Exceptional strength (PHB p.9), STR Table II as printed:',
    '//   Band       Hit adj  Dmg adj  Wt allow   Open doors  Bend bars',
    '//   18/01-50   +1       +3       +1,000     1-3         20%',
    '//   18/51-75   +2       +3       +1,250     1-4         25%',
    '//   18/76-90   +2       +4       +1,500     1-4         30%',
    '//   18/91-99   +2       +5       +2,000     1-4 (1)*    35%',
    '//   18/00      +3       +6       +3,000     1-5 (2)*    40%',
    '// * the parenthetical is the chances in 6 of forcing a',
    '//   locked, barred, magically held or wizard locked',
    '//   door - one attempt ever per door, a failed attempt',
    '//   can never succeed (the printed footnote).',
    '// R153 DIVERGENCE FIX, named in character.h: the original',
    '// transcription carried unsourced carry and press columns',
    '// and misread the 18/91-99 hit/damage and the 18/51-75',
    '// damage cells; the printed row values replace them.',
    '// ----------------------------------------------------------------------------',
    '',
    'static int exBand(const ExceptionalStrength& ex) {',
    '    if (!ex.has) return -1;',
    '    if (ex.pct <= 50)  return 0;',
    '    if (ex.pct <= 75)  return 1;',
    '    if (ex.pct <= 90)  return 2;',
    '    if (ex.pct <= 99)  return 3;',
    '    return 4;   // 100 = "00"',
    '}',
    '',
    'int ExceptionalStrength::hitAdj() const {',
    '    static constexpr int adj[5]  = { 1, 2, 2, 2, 3 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : adj[b];',
    '}',
    '',
    'int ExceptionalStrength::dmgAdj() const {',
    '    static constexpr int adj[5]  = { 3, 3, 4, 5, 6 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : adj[b];',
    '}',
    '',
    'int ExceptionalStrength::weightAllowGp() const {',
    '    static constexpr int allow[5] = { 1000, 1250, 1500, 2000, 3000 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : allow[b];',
    '}',
    '',
    'int ExceptionalStrength::openDoorsMax() const {',
    '    static constexpr int door[5] = { 3, 4, 4, 4, 5 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : door[b];',
    '}',
    '',
    'int ExceptionalStrength::openDoorsLockedMax() const {',
    '    static constexpr int door[5] = { 0, 0, 0, 1, 2 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : door[b];',
    '}',
    '',
    'int ExceptionalStrength::bendBarsPct() const {',
    '    static constexpr int pct[5] = { 20, 25, 30, 35, 40 };',
    '    int b = exBand(*this);',
    '    return b < 0 ? 0 : pct[b];',
    '}',
])

# ---- (4) rules/character.cpp: the full-table functions ----
c2_old = NL.join([
    'int strDmgAdj(uint8_t str, const ExceptionalStrength& ex) {',
    '    if (str < 3)  return -1;',
    '    if (str <= 5) return -1;',
    '    if (str <= 15) return 0;',
    '    if (str == 16) return 1;',
    '    if (str == 17) return 1;',
    '    if (str == 18) return ex.has ? ex.dmgAdj() : 2;',
    '    if (str == 19) return 3;',
    '    if (str == 20) return 4;',
    '    if (str <= 22) return 5;',
    '    if (str <= 24) return 6;',
    '    return 7;   // 25',
    '}',
])
c2_new = NL.join([
    'int strDmgAdj(uint8_t str, const ExceptionalStrength& ex) {',
    '    if (str < 3)  return -1;',
    '    if (str <= 5) return -1;',
    '    if (str <= 15) return 0;',
    '    if (str == 16) return 1;',
    '    if (str == 17) return 1;',
    '    if (str == 18) return ex.has ? ex.dmgAdj() : 2;',
    '    if (str == 19) return 3;',
    '    if (str == 20) return 4;',
    '    if (str <= 22) return 5;',
    '    if (str <= 24) return 6;',
    '    return 7;   // 25',
    '}',
    '',
    '// ----------------------------------------------------------------------------',
    '// STR Table II, the printed carry / door / bend columns (R153)',
    '//   Score  Wt allow (g.p.)  Open doors  Bend bars',
    '//   3      -350             1           0%',
    '//   4-5    -250             1           0%',
    '//   6-7    -150             1           0%',
    '//   8-9    normal (0)       1-2         1%',
    '//   10-11  normal (0)       1-2         2%',
    '//   12-13  +100             1-2         4%',
    '//   14-15  +200             1-2         7%',
    '//   16     +350             1-3         10%',
    '//   17     +500             1-3         13%',
    '//   18     +750             1-3         16%',
    '//   18/xx  +1,000..+3,000   1-3..1-5    20%..40%',
    '// ----------------------------------------------------------------------------',
    '',
    'int strWeightAllowGp(uint8_t str, const ExceptionalStrength& ex) {',
    '    if (str < 4)  return -350;',
    '    if (str <= 5) return -250;',
    '    if (str <= 7) return -150;',
    '    if (str <= 11) return 0;',
    '    if (str <= 13) return 100;',
    '    if (str <= 15) return 200;',
    '    if (str == 16) return 350;',
    '    if (str == 17) return 500;',
    '    return ex.has ? ex.weightAllowGp() : 750;   // 18 and beyond',
    '}',
    '',
    'int strOpenDoorsMax(uint8_t str, const ExceptionalStrength& ex) {',
    '    if (str < 8)  return 1;',
    '    if (str <= 15) return 2;',
    '    if (str == 18 && ex.has) return ex.openDoorsMax();',
    '    return 3;   // 16, 17, plain 18 and beyond',
    '}',
    '',
    'int strOpenDoorsLockedMax(uint8_t str, const ExceptionalStrength& ex) {',
    '    if (str == 18 && ex.has) return ex.openDoorsLockedMax();',
    '    return 0;   // the parentheticals ride the 18/91-99 and',
    '                // 18/00 rows alone (the printed footnote)',
    '}',
    '',
    'int strBendBarsPct(uint8_t str, const ExceptionalStrength& ex) {',
    '    if (str < 8)  return 0;',
    '    if (str <= 9) return 1;',
    '    if (str <= 11) return 2;',
    '    if (str <= 13) return 4;',
    '    if (str <= 15) return 7;',
    '    if (str == 16) return 10;',
    '    if (str == 17) return 13;',
    '    if (str == 18 && ex.has) return ex.bendBarsPct();',
    '    return 16;   // plain 18 and beyond',
    '}',
])

# ---- (5) rules/character.cpp: the score-3 to-hit fix ----
c3_old = NL.join([
    'int strHitAdj(uint8_t str, const ExceptionalStrength& ex) {',
    '    if (str < 3)  return -3;',
    '    if (str <= 5) return -2;',
    '    if (str <= 7) return -1;',
])
c3_new = NL.join([
    'int strHitAdj(uint8_t str, const ExceptionalStrength& ex) {',
    '    if (str <= 3) return -3;   // the printed score-3 row',
    '    if (str <= 5) return -2;',
    '    if (str <= 7) return -1;',
])

# ---- (6) regtest.cpp: the R153 audit block ----
aud_old = NL.join([
    '        printf("R152 becoming-lost audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
aud_new = NL.join([
    '        printf("R152 becoming-lost audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R153: exceptional strength audit -------------------------------',
    '    // The PHB p.9 STR Table II, all five printed columns',
    '    // pinned for the full 3-18/00 table: hit probability,',
    '    // damage adjustment, weight allowance in g.p., open',
    '    // doors on a d6 (with the locked/barred/held',
    '    // parentheticals on 18/91-99 and 18/00) and bend',
    '    // bars/lift gates. This is the DIVERGENCE FIX round:',
    '    // the original ex bands carried unsourced carry and',
    '    // press numbers and misread the 18/91-99 hit/damage',
    '    // and 18/51-75 damage cells - the printed values',
    '    // replace them, named in character.h and the gap',
    '    // report. The score-3 to-hit row is pinned too: the',
    '    // printed -3, which the original strHitAdj banded',
    '    // with 4-5 (-2) - found by this audit on its first',
    '    // run (bad 1), fixed in the same round.',
    '    {',
    '        int bad = 0;',
    '        namespace RS = rules;',
    '        // the 15 printed rows: score, ex flag, pct, hit,',
    '        // dmg, weight g.p., open doors, locked doors,',
    '        // bend bars percent',
    '        static const struct {',
    '            int str; bool ex; int pct;',
    '            int hit, dmg, wt, door, locked, bend;',
    '        } kT2[] = {',
    '            {  3, false,   0, -3, -1, -350, 1, 0,  0 },',
    '            {  5, false,   0, -2, -1, -250, 1, 0,  0 },',
    '            {  7, false,   0, -1,  0, -150, 1, 0,  0 },',
    '            {  9, false,   0,  0,  0,    0, 2, 0,  1 },',
    '            { 11, false,   0,  0,  0,    0, 2, 0,  2 },',
    '            { 13, false,   0,  0,  0,  100, 2, 0,  4 },',
    '            { 15, false,   0,  0,  0,  200, 2, 0,  7 },',
    '            { 16, false,   0,  0,  1,  350, 3, 0, 10 },',
    '            { 17, false,   0,  1,  1,  500, 3, 0, 13 },',
    '            { 18, false,   0,  1,  2,  750, 3, 0, 16 },',
    '            { 18, true,  25,  1,  3, 1000, 3, 0, 20 },',
    '            { 18, true,  60,  2,  3, 1250, 4, 0, 25 },',
    '            { 18, true,  85,  2,  4, 1500, 4, 0, 30 },',
    '            { 18, true,  95,  2,  5, 2000, 4, 1, 35 },',
    '            { 18, true, 100,  3,  6, 3000, 5, 2, 40 },',
    '        };',
    '        for (size_t i = 0; i < sizeof(kT2)/sizeof(kT2[0]); ++i) {',
    '            RS::ExceptionalStrength ex;',
    '            ex.has = kT2[i].ex; ex.pct = kT2[i].pct;',
    '            if (RS::strHitAdj(kT2[i].str, ex) != kT2[i].hit)',
    '                ++bad;',
    '            if (RS::strDmgAdj(kT2[i].str, ex) != kT2[i].dmg)',
    '                ++bad;',
    '            if (RS::strWeightAllowGp(kT2[i].str, ex)',
    '                != kT2[i].wt) ++bad;',
    '            if (RS::strOpenDoorsMax(kT2[i].str, ex)',
    '                != kT2[i].door) ++bad;',
    '            if (RS::strOpenDoorsLockedMax(kT2[i].str, ex)',
    '                != kT2[i].locked) ++bad;',
    '            if (RS::strBendBarsPct(kT2[i].str, ex)',
    '                != kT2[i].bend) ++bad;',
    '        }',
    '        // the percentile fold edges, both sides of each',
    '        RS::ExceptionalStrength ex; ex.has = true;',
    '        ex.pct = 50;',
    '        if (ex.hitAdj() != 1 || ex.dmgAdj() != 3',
    '            || ex.weightAllowGp() != 1000',
    '            || ex.openDoorsMax() != 3',
    '            || ex.bendBarsPct() != 20) ++bad;',
    '        ex.pct = 51;  if (ex.hitAdj() != 2) ++bad;',
    '        ex.pct = 75;  if (ex.dmgAdj() != 3',
    '            || ex.weightAllowGp() != 1250',
    '            || ex.bendBarsPct() != 25) ++bad;',
    '        ex.pct = 76;  if (ex.dmgAdj() != 4',
    '            || ex.weightAllowGp() != 1500',
    '            || ex.openDoorsMax() != 4',
    '            || ex.bendBarsPct() != 30) ++bad;',
    '        ex.pct = 90;  if (ex.hitAdj() != 2',
    '            || ex.dmgAdj() != 4) ++bad;',
    '        ex.pct = 91;  if (ex.dmgAdj() != 5',
    '            || ex.weightAllowGp() != 2000',
    '            || ex.bendBarsPct() != 35',
    '            || ex.openDoorsLockedMax() != 1) ++bad;',
    '        ex.pct = 99;  if (ex.hitAdj() != 2',
    '            || ex.openDoorsLockedMax() != 1) ++bad;',
    '        ex.pct = 100; if (ex.hitAdj() != 3 || ex.dmgAdj() != 6',
    '            || ex.weightAllowGp() != 3000',
    '            || ex.openDoorsMax() != 5',
    '            || ex.openDoorsLockedMax() != 2',
    '            || ex.bendBarsPct() != 40) ++bad;',
    '        // exceptional strength replaces the plain 18 row,',
    '        // it does not add to it (PHB p.9)',
    '        if (RS::strHitAdj(18, ex) != 3',
    '            || RS::strDmgAdj(18, ex) != 6',
    '            || RS::strBendBarsPct(18, ex) != 40) ++bad;',
    '        printf("R153 exceptional strength audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])

# ---- (7) gap report: the R153 round note ----
gap_head_old = NL.join([
    'terrain as if on course) is judge narration, printed',
    'and named, not engine data. Census 70.',
    '',
    'Categories:',
])
gap_head_new = NL.join([
    'terrain as if on course) is judge narration, printed',
    'and named, not engine data. Census 70.',
    'R153 PINNED the exceptional strength table (PHB p.9),',
    'a DIVERGENCE FIX round: the original transcription',
    'carried unsourced carry and press numbers and misread',
    'two band cells - the printed 18/91-99 row is +2 hit /',
    '+5 damage (not +3/+6) and the 18/51-75 damage is +3',
    '(not +4). The full STR Table II now pins all five',
    'columns for the whole 3-18/00 table: hit probability',
    '(the score-3 to-hit row included - it was banded',
    'with 4-5 at -2; the print and the function is own',
    'comment both read -3), damage, the g.p. weight',
    'allowance (-350 through',
    '+3,000), open doors on a d6 with the locked-door',
    'parentheticals (18/91-99: 1, 18/00: 2, one attempt',
    'ever) and bend bars/lift gates (0% through 40%).',
    'Census 71.',
    '',
    'Categories:',
])

# ---- (8) gap report: the exceptional-strength box ----
gap_box_old = NL.join([
    '- [ ] **Exceptional strength (PHB p.9)** - the fighter 18',
    '      percentile roll (18/01 through 18/00) and the STR',
    '      Table II bend-bars / open-doors columns; verify',
    '      the abilities layer first.',
])
gap_box_new = NL.join([
    '- [x] **Exceptional strength (PHB p.9)** - PINNED R153,',
    '      a divergence fix: the percentile roll itself was',
    '      already sound (rollExceptionalStrength, R120s),',
    '      but the band data misread two cells and carried',
    '      unsourced carry/press numbers - corrected to the',
    '      printed Table II, all five columns, 3-18/00 (the',
    '      audit is the regtest.cpp R153 block). The',
    '      locked-door parentheticals and the',
    '      one-attempt-ever footnote are pinned with it.',
])

# ---- run ----
patch("rules/character.h", h1_old, h1_new,
      "rules/character.h: struct block fixed",
      marker="R153 DIVERGENCE FIX")
assert len(applied) + len(already) == 1
patch("rules/character.h", h2_old, h2_new,
      "rules/character.h: full-table accessors",
      marker="int strWeightAllowGp")
assert len(applied) + len(already) == 2
patch("rules/character.cpp", c1_old, c1_new,
      "rules/character.cpp: ex-band block fixed",
      marker="R153 DIVERGENCE FIX, named in character.h")
assert len(applied) + len(already) == 3
patch("rules/character.cpp", c2_old, c2_new,
      "rules/character.cpp: full-table functions",
      marker="int strWeightAllowGp(uint8_t str")
assert len(applied) + len(already) == 4
patch("rules/character.cpp", c3_old, c3_new,
      "rules/character.cpp: score-3 to-hit fix",
      marker="the printed score-3 row")
assert len(applied) + len(already) == 5
patch("regtest.cpp", aud_old, aud_new,
      "regtest.cpp: R153 exceptional strength audit",
      marker="R153 exceptional strength audit")
assert len(applied) + len(already) == 6
patch("tools/dmg_gap_report.md", gap_head_old, gap_head_new,
      "gap report: R153 header note",
      marker="R153 PINNED the exceptional strength table")
assert len(applied) + len(already) == 7
patch("tools/dmg_gap_report.md", gap_box_old, gap_box_new,
      "gap report: exceptional-strength box closed",
      marker="PINNED R153,")
assert len(applied) + len(already) == 8
# ---- R153 fails/tail ----
if fails:
    print("R153 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 8:
    print("R153 splice: FAIL - expected 8 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R153 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R153 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R153 note: eight patches; expect the battery to gain")
print("one audit line - AUDIT CENSUS 71; commit: R153:")
print("exceptional strength pinned - STR Table II all five")
print("columns, band cells corrected (census 71)")
