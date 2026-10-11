#!/usr/bin/env python3
# R341: the UA SPELL TABLES (pp.
# 28-31) pin round, part 1 - the
# cleric 1st-3rd table (20 rows,
# seam-verified against the R80
# registry), the cleric 4th-7th
# fragments, the druid tables (the
# four readable rows seam-decoded
# as the 1st-level roster, the
# Insect P| fragment seam-decoded
# as Insect Plague) and the MU
# cantrip table (64 names, the
# Gather/Polish merge decoded);
# the MU spells tables and the
# illusionist spell table are
# OCR-scrambled - the item stays
# open pending the PDF. Pin-era
# pattern (R322). Idempotent; run
# twice.
import io
import os

NL = '\n'
applied = []
already = []

def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)

def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)

# ---- (a) the seed: the R340 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R340 landed 2026-10-11: commit',
    '  1288a5c, census 267, the UA new',
    '  weapons prose pin round',
    '  (rules/uanewweapons.h): the 16',
    '  printed descriptions, every',
    '  readable number pinned, the',
    '  khopesh slash-loss and whip 3d6',
    '  decodes documented; the item',
    '  stayed open (the DM pp. 77-79',
    '  half). GREEN on the first paste.',
    '  No new lessons.',
])
s = rd(SD)
if 'R340 landed 2026-10-11' in s:
    already.append('seed: the R340 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R340 record')
s = rd(SD)
assert s.count('R340 landed 2026-10-11') == 1,     'a entry'
assert s.count('R339 landed 2026-10-11') == 1,     'a r339 kept'
assert s.count('R338 landed 2026-10-11') == 1,     'a r338 kept'
assert s.count('## Knowledge maintenance') == 1,     'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uaspelltables.h ----
US = 'rules/uaspelltables.h'
if os.path.exists(US) and 'R341' in rd(US):
    already.append('uaspelltables.h: the pins')
else:
    HDR = NL.join([
        '// ===========================================================================',
        '// Adnd1 - rules/uaspelltables.h',
        '// The UA SPELL TABLES (pp. 28-31) pins, part 1 (R341): the cleric',
        '// tables, the druid tables and the magic-user cantrip table.',
        '//',
        '// Pin-era pattern (R322): pinned data only - no engine site exists.',
        '// The R80 spell registry (spells/spells.h) is the class/level seam.',
        '//',
        '// JUDGMENTs:',
        '//   - the scope: part 1 pins the READABLE tables. The magic-user',
        '//     spells tables (1st-5th and 7th-9th) and the illusionist',
        '//     spell table are OCR-scrambled beyond row-aligned decode -',
        '//     their head rows read clean but the column alignment breaks',
        '//     mid-table (the interleaved tail rows) - they stay open',
        '//     pending the PDF, the item stays open.',
        '//   - the druid "2nd Level" fragment: the four readable rows (the',
        '//     merged "Locate Invisibility To Animals Animals" cell plus',
        '//     Shillelagh and Speak With Animals) all seam-verify against',
        '//     the R228 druid roster as FIRST-level spells (Locate Animals,',
        '//     Invisibility To Animals, Shillelagh, Speak With Animals -',
        '//     all druid 1). The merged cell decodes as two interleaved',
        '//     names (Locate/Invisibility + Animals/Animals). The "2nd',
        '//     Level" header reads as a stray fragment: the visible rows',
        '//     are the 1st-level roster; the actual 2nd-level list is',
        '//     OCR-lost.',
        '//   - the druid 5th column "Insect P|" fragment decodes to Insect',
        '//     Plague - the R228 seam (druid 5) confirms both the name and',
        '//     the column. The druid Sticks To Snakes prints in the 5th',
        '//     column where the R228 seam reads druid 6 - pinned as',
        '//     printed, the doubt noted pending the PDF.',
        '//   - the cleric Spike Growth prints in the 5th column',
        '//     (the PHB reads cleric 3rd) - pinned as printed,',
        '//     the doubt noted pending the PDF.',
        '//   - the cleric Cure Critical Wounds prints in the 5th column',
        '//     (the PHB-consistent read); the R80 registry carries it at',
        '//     cleric 4 - a registry quirk, not a print doubt: pinned as',
        '//     printed, no seam assert against the registry for that cell.',
        '//   - the cantrip "Gather Polish" cell is two names merged by the',
        '//     OCR (Gather, Polish); both pin. The "Unlock" cantrip prints',
        '//     in the Personal column - pinned as printed, the likely',
        '//     column-slip noted pending the PDF.',
        '//   - the cleric 2nd column "Silence 15 Radius" prints without the',
        '//     apostrophe (the PHB print "Silence 15\' Radius"); pinned as',
        '//     printed.',
        '//   - the MU useful-cantrip count: the acquisition prose prints',
        '//     scrambled, but the fragments ("has one", "of each point",',
        '//     "For of intelligence") assemble to one useful cantrip per',
        '//     point of intelligence - the illusionist text ("one per point',
        '//     of intelligence, up to intelligence minus 3") parallels it.',
        '//     Pinned as the fragment decode, flagged.',
        '//   - the Number columns prove the loss: the cleric Continued table',
        '//     prints row numbers 15 and 16 (a 16+ row table) but only 7',
        '//     readable rows; the druid 4th-6th table prints 4, 6, 10, 11',
        '//     (garbled "1""), 12 - a 12-row table with 6 readable rows.',
        '//',
        '// OCR holes (the item stays open pending the PDF): the ENTIRE',
        '// magic-user spells tables (1st-9th), the illusionist spell table',
        '// and the illusionist minor-illusion cantrip list; the cleric 1st',
        '// "ct Evil" cell (a garble matching no unique name), the cleric',
        '// 2nd "draw" cell, the empty table cells (hole sentinels: the',
        '// empty string), the cleric 7th column (no readable cell), the',
        '// druid 1st/2nd/3rd lists beyond the four readable rows, and the',
        "// two tables' Number columns.",
        '// ===========================================================================',
        '',
        '#pragma once',
        '',
        'namespace rules {',
        '',
        '// ---- the cleric table (pp. 28-29) ----',
        '// The 1st-3rd level table: 20 printed rows. The empty string is',
        '// the hole sentinel (an OCR-lost cell).',
        'inline int uastClericTableRowCount()',
        '    { return 20; }',
        '',
        'inline const char* uastClericName(int lvl, int row) {',
        '    static const char* const k[3][20] = {',
        '        { "Bless", "Ceremony", "Combine", "Command",',
        '          "Create Water", "Cure Light Wounds", "",',
        '          "Detect Magic", "Endure Cold/Heat",',
        '          "Invisibility to Undead", "Light", "Magic Stone",',
        '          "Penetrate Disguise", "", "Precipitation",',
        '          "Protection From Evil", "Purify Food & Drink",',
        '          "Remove Fear", "Resist Cold", "Sanctuary" },',
        '        { "", "", "", "Detect Charm", "Detect Life",',
        '          "Dust Devil", "Enthrall", "Find Traps",',
        '          "Hold Person", "Holy Symbol", "Know Alignment",',
        '          "Messenger", "Resist Fire", "Silence 15 Radius",',
        '          "Slow Poison", "Snake Charm", "Speak With Animals",',
        '          "Spiritual Hammer", "", "Wyvern Watch" },',
        '        { "Animate Dead", "Cloudburst", "Continual Light",',
        '          "Create Food & Water", "Cure Blindness",',
        '          "Cure Disease", "Death\'s Door", "Dispel Magic",',
        '          "Feign Death", "Flame Walk", "Glyph of Warding",',
        '          "Locate Object", "Magical Vestment",',
        '          "Meld Into Stone", "Negative Plane Protection",',
        '          "Prayer", "Remove Curse", "Remove Paralysis",',
        '          "Speak With Dead", "Water Walk" },',
        '    };',
        '    if (lvl < 1) lvl = 1;',
        '    if (lvl > 3) lvl = 3;',
        '    if (row < 0) row = 0;',
        '    if (row > 19) row = 19;',
        '    return k[lvl - 1][row];',
        '}',
        '',
        '// The readable cells per level column (18, 16, 20).',
        'inline int uastClericReadableCount(int lvl) {',
        '    static const int k[3] = { 18, 16, 20 };',
        '    if (lvl < 1) lvl = 1;',
        '    if (lvl > 3) lvl = 3;',
        '    return k[lvl - 1];',
        '}',
        '',
        '// The Continued table (4th-7th): only fragments readable (the',
        '// row numbers 15 and 16 prove a 16-row print).',
        'inline int uastClericFragCount(int lvl) {',
        '    // 4th, 5th, 6th, 7th',
        '    static const int k[4] = { 2, 7, 4, 0 };',
        '    if (lvl < 4) lvl = 4;',
        '    if (lvl > 7) lvl = 7;',
        '    return k[lvl - 4];',
        '}',
        '',
        'inline const char* uastClericFragName(int lvl, int i) {',
        '    static const char* const k[4][8] = {',
        '        { "Sticks to Snakes", "Tongues", "", "", "", "",',
        '          "", "" },',
        '        { "Commune", "Cure Critical Wounds",',
        '          "Dispel Evil", "Magic Font", "Plane Shift",',
        '          "Spike Growth", "True Seeing", "" },',
        '        { "Conjure Animals", "Find The Path",',
        '          "Speak With Monsters", "Stone Tell", "", "",',
        '          "", "" },',
        '        { "", "", "", "", "", "", "", "" },',
        '    };',
        '    if (lvl < 4) lvl = 4;',
        '    if (lvl > 7) lvl = 7;',
        '    if (i < 0) i = 0;',
        '    if (i > 7) i = 7;',
        '    return k[lvl - 4][i];',
        '}',
        '',
        '// ---- the druid tables (p. 29) ----',
        '// The four readable rows - the 1st-level roster per the R228',
        '// seam (the "2nd Level" header is a stray fragment).',
        'inline int uastDruid1stCount()',
        '    { return 4; }',
        '',
        'inline const char* uastDruid1stName(int i) {',
        '    static const char* const k[4] = {',
        '        "Locate Animals", "Invisibility to Animals",',
        '        "Shillelagh", "Speak With Animals",',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 3) i = 3;',
        '    return k[i];',
        '}',
        '',
        '// The 4th-6th table: 6 readable rows of a 12-row print.',
        'inline int uastDruid4thCount()',
        '    { return 6; }',
        '',
        'inline const char* uastDruid4thName(int i) {',
        '    static const char* const k[6] = {',
        '        "Cure Serious Wounds", "Dispel Magic",',
        '        "Hallucinatory Forest", "Protection From Lightning",',
        '        "Repel Insects", "Speak With Plants",',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 5) i = 5;',
        '    return k[i];',
        '}',
        '',
        'inline int uastDruid5thCount()',
        '    { return 6; }',
        '',
        'inline const char* uastDruid5thName(int i) {',
        '    static const char* const k[6] = {',
        '        "Commune With Nature", "Control Winds",',
        '        "Insect Plague", "Sticks To Snakes",',
        '        "Transmute Rock To Mud", "Wall Of Fire",',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 5) i = 5;',
        '    return k[i];',
        '}',
        '',
        'inline int uastDruid6thCount()',
        '    { return 5; }',
        '',
        'inline const char* uastDruid6thName(int i) {',
        '    static const char* const k[5] = {',
        '        "Cure Critical Wounds", "Fire Seeds", "Turn Wood",',
        '        "Wall Of Thorns", "Weather Summoning",',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 4) i = 4;',
        '    return k[i];',
        '}',
        '',
        '// ---- the magic-user cantrip table (p. 30) ----',
        '// Six categories, 64 names (the Gather/Polish merge decodes to',
        '// two; the Number column is OCR-lost).',
        'inline int uastCantripCategoryCount()',
        '    { return 6; }',
        '',
        'inline const char* uastCantripCategoryName(int cat) {',
        '    static const char* const k[6] = {',
        '        "Useful", "Reversed", "Legerdemain",',
        '        "Person-Affecting", "Personal", "Haunting",',
        '    };',
        '    if (cat < 0) cat = 0;',
        '    if (cat > 5) cat = 5;',
        '    return k[cat];',
        '}',
        '',
        '// The name count per category (20, 11, 6, 10, 9, 8).',
        'inline int uastCantripCount(int cat) {',
        '    static const int k[6] = { 20, 11, 6, 10, 9, 8 };',
        '    if (cat < 0) cat = 0;',
        '    if (cat > 5) cat = 5;',
        '    return k[cat];',
        '}',
        '',
        'inline const char* uastCantripName(int cat, int i) {',
        '    static const char* const k[6][20] = {',
        '        { "Chill", "Clean", "Color", "Dampen", "Dry", "Dust",',
        '          "Exterminate", "Flavor", "Freshen", "Gather",',
        '          "Polish", "Salt", "Shine", "Spice", "Sprout",',
        '          "Stitch", "Sweeten", "Tie", "Warm", "Wrap" },',
        '        { "Curdle", "Dirty", "Dusty", "Hairy", "Knot",',
        '          "Ravel", "Sour", "Spill", "Tarnish", "Untie",',
        '          "Wilt", "", "", "", "", "", "", "", "", "" },',
        '        { "Change", "Distract", "Hide", "Mute", "Palm",',
        '          "Present", "", "", "", "", "", "", "", "", "",',
        '          "", "", "", "", "" },',
        '        { "Belch", "Blink", "Cough", "Giggle", "Nod",',
        '          "Scratch", "Sneeze", "Twitch", "Wink", "Yawn",',
        '          "", "", "", "", "", "", "", "", "", "" },',
        '        { "Bee", "Bluelight", "Bug", "Firefinger", "Gnats",',
        '          "Mouse", "Smokepuff", "Spider", "Unlock", "",',
        '          "", "", "", "", "", "", "", "", "", "" },',
        '        { "Creak", "Footfall", "Groan", "Moan", "Rattle",',
        '          "Tap", "Thump", "Whistle", "", "",',
        '          "", "", "", "", "", "", "", "", "", "" },',
        '    };',
        '    if (cat < 0) cat = 0;',
        '    if (cat > 5) cat = 5;',
        '    if (i < 0) i = 0;',
        '    if (i > 19) i = 19;',
        '    return k[cat][i];',
        '}',
        '',
        '// ---- the cantrip acquisition prose (pp. 28, 31) ----',
        '// The magic-user ranges (the useful count is the fragment',
        '// decode - one per point of intelligence).',
        'inline int uastMuCantripMaxNewCount()',
        '    { return 3; }',
        '',
        'inline bool uastMuUsefulOnePerIntPoint()',
        '    { return true; }',
        '',
        'inline int uastMuReversedMin()',
        '    { return 2; }',
        '',
        'inline int uastMuReversedMax()',
        '    { return 8; }',
        '',
        'inline int uastMuLegerdemainMin()',
        '    { return 2; }',
        '',
        'inline int uastMuLegerdemainMax()',
        '    { return 5; }',
        '',
        'inline int uastMuPersonAffectingMin()',
        '    { return 2; }',
        '',
        'inline int uastMuPersonAffectingMax()',
        '    { return 8; }',
        '',
        'inline int uastMuPersonalMin()',
        '    { return 2; }',
        '',
        'inline int uastMuPersonalMax()',
        '    { return 8; }',
        '',
        'inline int uastMuHauntingMin()',
        '    { return 2; }',
        '',
        'inline int uastMuHauntingMax()',
        '    { return 5; }',
        '',
        '// The illusionist ranges (clean print): the useful count is one',
        '// per point of intelligence up to intelligence minus 3 (an 18',
        '// intelligence chooses 15); 5-8 minor illusion cantrips.',
        'inline int uastIlMinorIllusionMin()',
        '    { return 5; }',
        '',
        'inline int uastIlMinorIllusionMax()',
        '    { return 8; }',
        '',
        'inline int uastIlUsefulIntMinus()',
        '    { return 3; }',
        '',
        'inline int uastIlUsefulAtInt18()',
        '    { return 15; }',
        '',
        'inline int uastIlReversedMin()',
        '    { return 2; }',
        '',
        'inline int uastIlReversedMax()',
        '    { return 5; }',
        '',
        'inline int uastIlLegerdemainMin()',
        '    { return 3; }',
        '',
        'inline int uastIlLegerdemainMax()',
        '    { return 6; }',
        '',
        'inline int uastIlPersonAffectingMin()',
        '    { return 2; }',
        '',
        'inline int uastIlPersonAffectingMax()',
        '    { return 5; }',
        '',
        'inline int uastIlPersonalMin()',
        '    { return 2; }',
        '',
        'inline int uastIlPersonalMax()',
        '    { return 5; }',
        '',
        'inline int uastIlHauntingMin()',
        '    { return 5; }',
        '',
        'inline int uastIlHauntingMax()',
        '    { return 8; }',
        '',
        '// The caption note: all cantrips (plus the italic spells) are',
        '// described in this volume.',
        'inline bool uastNoteAllCantripsDescribedHere()',
        '    { return true; }',
        '',
        '}   // namespace rules',
    ])
    clean(HDR, 78)
    wr(US, HDR)
    applied.append('uaspelltables.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 44, 'b inline count'
assert s.count('R341') == 1, 'b round tag'
assert s.count('uastCantripName(int cat') == 1,     'b cantrip fn'
assert s.count('uastDruid5thName(int') == 1,     'b druid fn'
assert 'uanwAklysThongFeet' not in s,     'b no r340 ref'
assert 'uapfPhbSeamRow' not in s,     'b no r339 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the MU spells tables and
# the illusionist spell table are scrambled) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R341: the readable tables' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = '      is data-driven.'
    assert s.count(TAIL_OLD) == 1, 'c tail'
    FIRST_OLD = ('- [ ] **The spell tables**'
                ' (pp. 28-31)')
    assert s.count(FIRST_OLD) == 1, 'c first'
    NOTE = NL.join([
        '      - R341: the readable tables',
        '        pinned (rules/uaspelltables.h)',
        '        - the cleric 1st-3rd table',
        '        (20 rows, seam-verified against',
        '        the R80 registry), the cleric',
        '        4th-7th fragments, the druid',
        '        tables (the four readable rows',
        '        seam-decoded as the 1st-level',
        '        roster, the Insect P| fragment',
        '        seam-decoded as Insect Plague)',
        '        and the MU cantrip table (64',
        '        names, the Gather/Polish merge',
        '        decoded); the MU spells tables',
        '        and the illusionist spell table',
        '        are OCR-scrambled - stays open',
        '        pending the PDF read.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
FIRST_KEEP = ('- [ ] **The spell tables**'
              ' (pp. 28-31)')
assert s.count('R341: the readable tables')     == 1, 'c note'
assert s.count(FIRST_KEEP) == 1, 'c stays open'
assert s.count('R340: the fragment-verified')     == 1, 'c r340 note kept'
assert s.count('CLOSED R339') == 1, 'c r339 kept'
assert s.count('R338: the fragment-verified')     == 1, 'c r338 note kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R341 UA spell tables pin audit' in s:
    already.append('regtest.cpp: the R341 audit')
else:
    INC_ANCH = ('#include "rules/uanewweapons.h"'
                '  // R340: the UA new weapons'
                ' prose')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/uaspelltables.h"'
    '  // R341: the UA spell tables part 1',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
        '    // ---- R341: the UA spell tables pin audit ----',
        '    // The UA SPELL TABLES (pp. 28-31), part 1 - the',
        '    // cleric 1st-3rd table (20 rows, seam-verified',
        '    // against the R80 registry), the cleric 4th-7th',
        '    // fragments, the druid tables (the four readable',
        '    // rows seam-decoded as the 1st-level roster, the',
        '    // "Insect P|" fragment seam-decoded as Insect',
        '    // Plague) and the MU cantrip table (64 names,',
        '    // the Gather/Polish merge decoded). The MU spells',
        '    // tables and the illusionist spell table are',
        '    // OCR-scrambled - the item stays open pending',
        '    // the PDF.',
        '    {',
        '        using namespace rules;',
        '        int bad = 0;',
        '        // U1: the counts',
        '        {',
        '            if (uastClericTableRowCount() != 20) ++bad;',
        '            if (uastClericReadableCount(1) != 18) ++bad;',
        '            if (uastClericReadableCount(2) != 16) ++bad;',
        '            if (uastClericReadableCount(3) != 20) ++bad;',
        '            if (uastClericFragCount(4) != 2) ++bad;',
        '            if (uastClericFragCount(5) != 7) ++bad;',
        '            if (uastClericFragCount(6) != 4) ++bad;',
        '            if (uastClericFragCount(7) != 0) ++bad;',
        '            if (uastDruid1stCount() != 4) ++bad;',
        '            if (uastDruid4thCount() != 6) ++bad;',
        '            if (uastDruid5thCount() != 6) ++bad;',
        '            if (uastDruid6thCount() != 5) ++bad;',
        '            if (uastCantripCategoryCount() != 6) ++bad;',
        '            int total = 0;',
        '            for (int c = 0; c < 6; ++c)',
        '                total += uastCantripCount(c);',
        '            if (total != 64) ++bad;',
        '            if (!uastNoteAllCantripsDescribedHere()) ++bad;',
        '        }',
        '        // U2: the cleric 1st column (the two holes)',
        '        {',
        '            if (strcmp(uastClericName(1, 0), "Bless")',
        '                != 0) ++bad;',
        '            if (strcmp(uastClericName(1, 5),',
        '                "Cure Light Wounds") != 0) ++bad;',
        '            if (strcmp(uastClericName(1, 14),',
        '                "Precipitation") != 0) ++bad;',
        '            if (strcmp(uastClericName(1, 19),',
        '                "Sanctuary") != 0) ++bad;',
        '            // the "ct Evil" garble cell - a hole',
        '            if (uastClericName(1, 6)[0] != 0) ++bad;',
        '            // the empty cell - a hole',
        '            if (uastClericName(1, 13)[0] != 0) ++bad;',
        '            int n = 0;',
        '            for (int r = 0; r < 20; ++r)',
        '                if (uastClericName(1, r)[0]) ++n;',
        '            if (n != 18) ++bad;',
        '        }',
        '        // U3: the cleric 2nd and 3rd columns',
        '        {',
        '            if (strcmp(uastClericName(2, 5),',
        '                "Dust Devil") != 0) ++bad;',
        '            if (strcmp(uastClericName(2, 13),',
        '                "Silence 15 Radius") != 0) ++bad;',
        '            if (strcmp(uastClericName(2, 19),',
        '                "Wyvern Watch") != 0) ++bad;',
        '            // the three leading empties, the "draw"',
        '            // garble - holes',
        '            if (uastClericName(2, 0)[0] != 0) ++bad;',
        '            if (uastClericName(2, 18)[0] != 0) ++bad;',
        '            int n = 0;',
        '            for (int r = 0; r < 20; ++r)',
        '                if (uastClericName(2, r)[0]) ++n;',
        '            if (n != 16) ++bad;',
        '            // the 3rd column: all 20 readable',
        '            if (strcmp(uastClericName(3, 0),',
        '                "Animate Dead") != 0) ++bad;',
        '            if (strcmp(uastClericName(3, 14),',
        '                "Negative Plane Protection") != 0)',
        '                ++bad;',
        '            if (strcmp(uastClericName(3, 19),',
        '                "Water Walk") != 0) ++bad;',
        '        }',
        '        // U4: the cleric 4th-7th fragments',
        '        {',
        '            if (strcmp(uastClericFragName(4, 0),',
        '                "Sticks to Snakes") != 0) ++bad;',
        '            if (strcmp(uastClericFragName(4, 1),',
        '                "Tongues") != 0) ++bad;',
        '            if (strcmp(uastClericFragName(5, 0),',
        '                "Commune") != 0) ++bad;',
        '            // the Spike Growth print sits in the 5th',
        '            // column (the PHB reads 3rd) - as printed',
        '            if (strcmp(uastClericFragName(5, 5),',
        '                "Spike Growth") != 0) ++bad;',
        '            if (strcmp(uastClericFragName(5, 6),',
        '                "True Seeing") != 0) ++bad;',
        '            if (strcmp(uastClericFragName(6, 3),',
        '                "Stone Tell") != 0) ++bad;',
        '            // the 7th column: wholly lost',
        '            if (uastClericFragCount(7) != 0) ++bad;',
        '        }',
        '        // U5: the druid tables',
        '        {',
        '            if (strcmp(uastDruid1stName(0),',
        '                "Locate Animals") != 0) ++bad;',
        '            if (strcmp(uastDruid1stName(1),',
        '                "Invisibility to Animals") != 0) ++bad;',
        '            if (strcmp(uastDruid1stName(2),',
        '                "Shillelagh") != 0) ++bad;',
        '            if (strcmp(uastDruid1stName(3),',
        '                "Speak With Animals") != 0) ++bad;',
        '            if (strcmp(uastDruid4thName(0),',
        '                "Cure Serious Wounds") != 0) ++bad;',
        '            if (strcmp(uastDruid4thName(5),',
        '                "Speak With Plants") != 0) ++bad;',
        '            if (strcmp(uastDruid5thName(2),',
        '                "Insect Plague") != 0) ++bad;',
        '            // the Sticks To Snakes deviation: printed',
        '            // in the 5th column, the seam reads 6th',
        '            if (strcmp(uastDruid5thName(3),',
        '                "Sticks To Snakes") != 0) ++bad;',
        '            if (strcmp(uastDruid6thName(0),',
        '                "Cure Critical Wounds") != 0) ++bad;',
        '            if (strcmp(uastDruid6thName(4),',
        '                "Weather Summoning") != 0) ++bad;',
        '        }',
        '        // U6: the cantrip table',
        '        {',
        '            if (strcmp(uastCantripCategoryName(0),',
        '                "Useful") != 0) ++bad;',
        '            if (strcmp(uastCantripCategoryName(5),',
        '                "Haunting") != 0) ++bad;',
        '            if (strcmp(uastCantripName(0, 0),',
        '                "Chill") != 0) ++bad;',
        '            // the merged Gather/Polish cell: two names',
        '            if (strcmp(uastCantripName(0, 9),',
        '                "Gather") != 0) ++bad;',
        '            if (strcmp(uastCantripName(0, 10),',
        '                "Polish") != 0) ++bad;',
        '            if (strcmp(uastCantripName(0, 19),',
        '                "Wrap") != 0) ++bad;',
        '            if (strcmp(uastCantripName(1, 10),',
        '                "Wilt") != 0) ++bad;',
        '            if (strcmp(uastCantripName(2, 5),',
        '                "Present") != 0) ++bad;',
        '            if (strcmp(uastCantripName(3, 9),',
        '                "Yawn") != 0) ++bad;',
        '            // the Unlock print in the Personal column',
        '            if (strcmp(uastCantripName(4, 8),',
        '                "Unlock") != 0) ++bad;',
        '            if (strcmp(uastCantripName(5, 7),',
        '                "Whistle") != 0) ++bad;',
        '        }',
        '        // U7: the acquisition prose',
        '        {',
        '            if (uastMuCantripMaxNewCount() != 3) ++bad;',
        '            if (!uastMuUsefulOnePerIntPoint()) ++bad;',
        '            if (uastMuReversedMin() != 2) ++bad;',
        '            if (uastMuReversedMax() != 8) ++bad;',
        '            if (uastMuLegerdemainMin() != 2) ++bad;',
        '            if (uastMuLegerdemainMax() != 5) ++bad;',
        '            if (uastMuPersonAffectingMin() != 2) ++bad;',
        '            if (uastMuPersonAffectingMax() != 8) ++bad;',
        '            if (uastMuPersonalMax() != 8) ++bad;',
        '            if (uastMuHauntingMin() != 2) ++bad;',
        '            if (uastMuHauntingMax() != 5) ++bad;',
        '            if (uastIlMinorIllusionMin() != 5) ++bad;',
        '            if (uastIlMinorIllusionMax() != 8) ++bad;',
        '            if (uastIlUsefulIntMinus() != 3) ++bad;',
        '            if (uastIlUsefulAtInt18() != 15) ++bad;',
        '            if (uastIlLegerdemainMin() != 3) ++bad;',
        '            if (uastIlLegerdemainMax() != 6) ++bad;',
        '            if (uastIlPersonalMax() != 5) ++bad;',
        '            if (uastIlHauntingMin() != 5) ++bad;',
        '            if (uastIlHauntingMax() != 8) ++bad;',
        '        }',
        '        // U8: the R80/R228 registry seam (live)',
        '        {',
        '            auto reglvl = [](const char* n,',
        '                spells::SpellClass c) -> int {',
        '                for (int id = 0;',
        '                     id < spells::SPELL_COUNT; ++id) {',
        '                    const spells::SpellDef& d =',
        '                        spells::spell(',
        '                            (spells::SpellId)id);',
        '                    if (d.sclass == c',
        '                        && strcmp(d.name, n) == 0)',
        '                        return d.level;',
        '                }',
        '                return -1;',
        '            };',
        '            using spells::SPELL_CLERIC;',
        '            using spells::SPELL_DRUID;',
        '            // the cleric 1st-3rd columns verify',
        '            if (reglvl("Cure Light Wounds",',
        '                SPELL_CLERIC) != 1) ++bad;',
        '            if (reglvl("Hold Person",',
        '                SPELL_CLERIC) != 2) ++bad;',
        '            if (reglvl("Slow Poison",',
        '                SPELL_CLERIC) != 2) ++bad;',
        '            if (reglvl("Dispel Magic",',
        '                SPELL_CLERIC) != 3) ++bad;',
        '            if (reglvl("Prayer",',
        '                SPELL_CLERIC) != 3) ++bad;',
        '            // the registry quirk: CCW at cleric 4',
        '            if (reglvl("Cure Critical Wounds",',
        '                SPELL_CLERIC) != 4) ++bad;',
        '            // the druid 1st-level decode seam',
        '            if (reglvl("Locate Animals",',
        '                SPELL_DRUID) != 1) ++bad;',
        '            if (reglvl("Invisibility To Animals",',
        '                SPELL_DRUID) != 1) ++bad;',
        '            if (reglvl("Shillelagh",',
        '                SPELL_DRUID) != 1) ++bad;',
        '            if (reglvl("Speak With Animals",',
        '                SPELL_DRUID) != 1) ++bad;',
        '            // the 4th-6th columns verify',
        '            if (reglvl("Cure Serious Wounds",',
        '                SPELL_DRUID) != 4) ++bad;',
        '            if (reglvl("Dispel Magic",',
        '                SPELL_DRUID) != 4) ++bad;',
        '            if (reglvl("Hallucinatory Forest",',
        '                SPELL_DRUID) != 4) ++bad;',
        '            if (reglvl("Repel Insects",',
        '                SPELL_DRUID) != 4) ++bad;',
        '            if (reglvl("Commune With Nature",',
        '                SPELL_DRUID) != 5) ++bad;',
        '            if (reglvl("Control Winds",',
        '                SPELL_DRUID) != 5) ++bad;',
        '            // the Insect P| fragment decode seam',
        '            if (reglvl("Insect Plague",',
        '                SPELL_DRUID) != 5) ++bad;',
        '            // the Sticks To Snakes deviation: the',
        '            // seam reads 6, the print sits in the 5th',
        '            if (reglvl("Sticks to Snakes",',
        '                SPELL_DRUID) != 6) ++bad;',
        '            if (reglvl("Cure Critical Wounds",',
        '                SPELL_DRUID) != 6) ++bad;',
        '            if (reglvl("Turn Wood",',
        '                SPELL_DRUID) != 6) ++bad;',
        '            if (reglvl("Weather Summoning",',
        '                SPELL_DRUID) != 6) ++bad;',
        '        }',
        '        printf("R341 UA spell tables pin audit: bad %d\\n", bad);',
        '        if (bad) return 1;',
        '    }',
    ])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH, AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R341 audit')
s = rd(RT)
assert s.count(
    'R341 UA spell tables pin audit: bad ')     == 1, 'd audit line'
assert s.count('audit: bad ') == 268, 'd census 268'
assert s.count(
    'R340 UA new weapons prose pin audit: bad ')     == 1, 'd r340 kept'
assert s.count(
    'R339 UA proficiency pin audit: bad ')     == 1, 'd r339 kept'
assert s.count('R227: the wis mental save') == 1,     'd r227 kept'
assert s.count(
    '#include "rules/uaspelltables.h"') == 1,     'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R341 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R341 note: the UA spell tables pin')
print('round, part 1 - the cleric 1st-3rd')
print('table (seam-verified against the R80')
print('registry), the cleric 4th-7th')
print('fragments, the druid tables (the')
print('readable rows seam-decoded as the')
print('1st-level roster) and the MU cantrip')
print('table (64 names); the MU spells')
print('tables and the illusionist spell')
print('table are OCR-scrambled - the item')
print('stays open pending the PDF; the')
print('census 267 -> 268')
print('commit: R341: the UA spell tables pin')
print('round (census 268)')

