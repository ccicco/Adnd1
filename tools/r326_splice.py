#!/usr/bin/env python3
# R326: the UA creation round - the
# sub-race picker, the female field,
# the dark-elf sex split live at the
# fold. Idempotent splice; run twice,
# the second run reads (already 8).

import io

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

# ---- (a) the seed: the R325 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
'',
'- R325 landed 2026-10-11: commit',
'  2592126, census 252, the UA',
'  Race Table II caller round',
'  (rules/subracecap.h): the',
'  uaLevelCap fold at the gainXp',
'  queue and the trainer, the',
'  uaSubrace field with its save',
'  line, the +2 single-class rule',
'  against the R185 combo layer.',
'  GREEN on the second paste (one',
'  fix round, r325b, folded by',
'  amend): the U6 live walks',
'  passed st.rng (a rules::Rng)',
'  where gainXp and trainNext take',
'  a rules::Dice reference - the',
'  AppState dice{rng} member is',
'  the bridge (reseeding rides',
'  the reference). Lessons: (1)',
'  the oracle must type-check',
'  CALL SIGNATURES against the',
'  landed headers, not just',
'  identifier names - the r324b',
'  case-gap twin; (2) a failed',
'  build cascades the whole',
'  census (the battery never',
'  runs) - read the FIRST error,',
'  not the census.',
])
s = rd(SD)
if 'R325 landed 2026-10-11' in s:
    already.append('seed: the R325 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    s = s.replace(ANCH,
        SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R325 record')
s = rd(SD)
assert s.count('R325 landed 2026-10-11') == 1, 'a entry'
assert s.count('R324 landed') == 1, 'a r324 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) rules/subracecap.h: the female leg ----
SC = 'rules/subracecap.h'
s = rd(SC)
if 'int female = 0' in s:
    already.append('subracecap.h: the female leg')
else:
    CMT_OLD = NL.join([
    '// above. The dark-elf sex split rides',
    '// the creation round (the male columns',
    '// here).'])
    CMT_NEW = NL.join([
    '// above. The female flag selects',
    '// the printed female columns (the',
    '// dark-elf split; every other',
    '// sub-race reads the same column).'])
    SIG_OLD = '                      int multiMask) {'
    SIG_NEW = NL.join([
    '                      int multiMask,',
    '                      int female = 0) {'])
    CALL_OLD = '        s, c, uaColumnKey(c, a, ex), 0);'
    CALL_NEW = NL.join([
    '        s, c, uaColumnKey(c, a, ex),',
    '        female);'])
    assert s.count(CMT_OLD) == 1, 'b cmt anchor'
    assert s.count(SIG_OLD) == 1, 'b sig anchor'
    assert s.count(CALL_OLD) == 1, 'b call anchor'
    clean(CMT_NEW, 78); clean(SIG_NEW, 78)
    clean(CALL_NEW, 78)
    s = s.replace(CMT_OLD, CMT_NEW)
    s = s.replace(SIG_OLD, SIG_NEW)
    s = s.replace(CALL_OLD, CALL_NEW)
    wr(SC, s)
    applied.append('subracecap.h: the female leg')
s = rd(SC)
assert s.count('int female = 0') == 1, 'b default'
assert s.count('        female);') == 1, 'b call leg'
assert s.count('namespace rules {') == 1, 'b namespace'
assert 'SUB_COUNT' not in s, 'b no SUB_COUNT'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) game/party.h: the field, the folds ----
PH = 'game/party.h'
s = rd(PH)
if 'bool female = false;' in s:
    already.append('party.h: the field, the folds')
else:
    FLD_ANCH = '    int  uaSubrace = 0;'
    FLD_NEW = NL.join([
    '    int  uaSubrace = 0;',
    '    // R326: the member sex (Table III M/F;',
    '    // the dark-elf Race Table II split reads',
    '    // it; v1 saves carry no line and load as',
    '    // male). Optional "fem" line in the save.',
    '    bool female = false;'])
    CMT_OLD = NL.join([
    '            // The dark-elf sex split rides the',
    '            // creation round (the male columns',
    '            // here).'])
    CMT_NEW = NL.join([
    '            // The dark-elf sex split reads',
    '            // the member sex flag (R326).'])
    ARG_OLD = '                c.multiMask);'
    ARG_NEW = '                c.multiMask, c.female);'
    assert s.count(FLD_ANCH) == 1, 'c field anchor'
    assert s.count(CMT_OLD) == 2, 'c cmt anchors'
    assert s.count(ARG_OLD) == 2, 'c arg anchors'
    clean(FLD_NEW, 78); clean(CMT_NEW, 78)
    clean(ARG_NEW, 78)
    s = s.replace(FLD_ANCH, FLD_NEW)
    s = s.replace(CMT_OLD, CMT_NEW)
    s = s.replace(ARG_OLD, ARG_NEW)
    wr(PH, s)
    applied.append('party.h: the field, the folds')
s = rd(PH)
assert s.count('bool female = false;') == 1, 'c field'
assert s.count('c.female);') == 2, 'c the fold legs'
assert s.count('uaLevelCap') == 2, 'c folds intact'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) game/appstate.h: the stage, the rows ----
AS = 'game/appstate.h'
s = rd(AS)
if 'CR_SUBRACE' in s:
    already.append('appstate.h: the stage, the rows')
else:
    INC_ANCH = ('#include "../rules/races.h"'
                '   // R154: Race Tables I-III')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "../rules/subraces.h"'
    '  // R326: the sub-race picker'])
    ENUM_ANCH = ('    CR_RACE,'
                 '    // R154: the racial stock stage')
    ENUM_NEW = NL.join([
    ENUM_ANCH,
    '    CR_SUBRACE,  // R326: the sub-race offer'])
    FLD_ANCH = ('    bool female = false;'
                '             // R154: Table III M/F'
                ' columns')
    FLD_NEW = NL.join([
    FLD_ANCH,
    '    int  subracePick = 0;'
    '            // R326: picker row (SUB_* value)'])
    RST_ANCH = '        female = false;   // R154'
    RST_NEW = NL.join([
    RST_ANCH,
    '        subracePick = 0;  // R326'])
    HELP_ANCH = NL.join([
    '    bool raceEligible(int raceIdx) const {',
    '        return rules::raceMeetsMinimums('
    'rolled,',
    '            (rules::CharRace)raceIdx,'
    ' female);',
    '    }'])
    HELP_NEW = NL.join([
    HELP_ANCH,
    '',
    '    // R326: the sub-race picker rows -',
    '    // SUB_NONE first, then the sub-races',
    '    // of the chosen stock (SUB_HUMAN',
    '    // stays a matrix id; humans carry',
    '    // the none row only)',
    '    int subraceOptionCount() const {',
    '        int n = 1;',
    '        if (racePick !='
    ' (int)rules::RACE_HUMAN)',
    '            for (int s = 1;',
    '                 s < rules::SUBRACE_COUNT;'
    ' ++s)',
    '                if (rules::subraceParentRace(',
    '                        (rules::CharSubRace)s)',
    '                    == (rules::CharRace)'
    'racePick)',
    '                    ++n;',
    '        return n;',
    '    }',
    '',
    '    // The sub-race of picker row i',
    '    // (off-menu rows read SUB_NONE)',
    '    rules::CharSubRace subraceOption(',
    '            int row) const {',
    '        if (row <= 0',
    '            || racePick =='
    ' (int)rules::RACE_HUMAN)',
    '            return rules::SUB_NONE;',
    '        int n = 1;',
    '        for (int s = 1;',
    '             s < rules::SUBRACE_COUNT; ++s)',
    '            if (rules::subraceParentRace(',
    '                    (rules::CharSubRace)s)',
    '                == (rules::CharRace)racePick) {',
    '                if (n == row)',
    '                    return'
    ' (rules::CharSubRace)s;',
    '                ++n;',
    '            }',
    '        return rules::SUB_NONE;',
    '    }'])
    MAKE_ANCH = ('        c.race = racePick;'
                '              // R154: the chosen stock')
    MAKE_NEW = NL.join([
    MAKE_ANCH,
    '        c.female = female;'
    '              // R326: Table III M/F',
    '        c.uaSubrace = subracePick;'
    '      // R326: the chosen sub-race'])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(ENUM_ANCH) == 1, 'd enum anchor'
    assert s.count(FLD_ANCH) == 1, 'd field anchor'
    assert s.count(RST_ANCH) == 1, 'd reset anchor'
    assert s.count(HELP_ANCH) == 1, 'd helper anchor'
    assert s.count(MAKE_ANCH) == 1, 'd make anchor'
    for b in (INC_NEW, ENUM_NEW, FLD_NEW, RST_NEW,
              HELP_NEW, MAKE_NEW):
        clean(b, 78)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(ENUM_ANCH, ENUM_NEW)
    s = s.replace(FLD_ANCH, FLD_NEW)
    s = s.replace(RST_ANCH, RST_NEW)
    s = s.replace(HELP_ANCH, HELP_NEW)
    s = s.replace(MAKE_ANCH, MAKE_NEW)
    wr(AS, s)
    applied.append('appstate.h: the stage, the rows')
s = rd(AS)
assert s.count('CR_SUBRACE') == 1, 'd stage row'
assert s.count('subraceOptionCount(') == 1, 'd count fn'
assert s.count('subraceOption(') == 1, 'd option fn'
assert s.count('c.uaSubrace = subracePick;') == 1, 'd wire'
assert s.count('c.female = female;') == 1, 'd sex wire'
assert s.count('subraces.h') == 1, 'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- (e) adnd1.cpp: the stage machine ----
AD = 'adnd1.cpp'
s = rd(AD)
if 'CR_SUBRACE' in s:
    already.append('adnd1.cpp: the stage machine')
else:
    TR_OLD = NL.join([
    '                        cr.racePick = idx;',
    '                        cr.classPick = 0;',
    '                        cr.stage = CR_CLASS;'])
    TR_NEW = NL.join([
    '                        cr.racePick = idx;',
    '                        cr.classPick = 0;',
    '                        cr.subracePick = 0;'
    '   // R326',
    '                        cr.stage ='
    ' CR_SUBRACE;'])
    KEY_ANCH = NL.join([
    '        case CR_CLASS:',
    '            switch (wp) {'])
    KEY_NEW = NL.join([
    '        case CR_SUBRACE:'
    '   // R326: the UA sub-race offer',
    '            switch (wp) {',
    "                case '1': case '2':"
    " case '3':",
    "                case '4': case '5':"
    " case '6':",
    "                case '7': {",
    "                    int row ="
    " (int)(wp - '1');",
    '                    if (row <'
    ' cr.subraceOptionCount()) {',
    '                        cr.subracePick'
    ' = (int)',
    '                            cr.subraceOption'
    '(row);',
    '                        cr.classPick = 0;',
    '                        cr.stage ='
    ' CR_CLASS;',
    '                    }',
    '                    break;',
    '                }',
    '                case VK_ESCAPE:',
    '                    cr.stage = CR_RACE;'
    '   // back to the stock',
    '                    break;',
    '            }',
    '            break;',
    '',
    KEY_ANCH])
    ESC_OLD = ('                    cr.stage ='
               ' CR_RACE;   // back to race choice')
    ESC_NEW = ('                    cr.stage ='
               ' CR_SUBRACE;   // R326: back to'
               ' the sub-race')
    PANEL_ANCH = NL.join([
    '        case CR_SUBCLASS: {'
    '   // R230: the subclass offer'])
    PANEL_NEW = NL.join([
    '        case CR_SUBRACE: {'
    '   // R326: the UA sub-race offer',
    '            TextOutA(dc, 20, py,'
    ' "CHOOSE A SUB-RACE", 13);',
    '            py += 30;',
    '            for (int i = 0;',
    '                 i < cr.subraceOptionCount();'
    ' ++i) {',
    '                rules::CharSubRace s =',
    '                    cr.subraceOption(i);',
    '                char row[96];',
    '                snprintf(row, sizeof row,',
    '                         "  [%d] %s", i + 1,',
    '                         rules::subraceName('
    's));',
    '                SetTextColor(dc,'
    ' RGB(210, 195, 165));',
    '                TextOutA(dc, 40, py, row,',
    '                         (int)strlen(row));',
    '                py += 26;',
    '            }',
    '            SetTextColor(dc,'
    ' RGB(190, 175, 140));',
    '            const char* hint =',
    '                "[1] none   [2+] the sub-races"',
    '                "   [esc] back";',
    '            TextOutA(dc, 20, VIEW_H - 60,'
    ' hint,',
    '                     (int)strlen(hint));',
    '            break;',
    '        }',
    '',
    PANEL_ANCH])
    HINT_OLD = NL.join([
    '                     "[1-4] choose class'
    '   [esc] back to race",',
    '                     39);'])
    HINT_NEW = NL.join([
    '                     "[1-4] choose class'
    '   [esc] sub-race",',
    '                     35);'])
    assert s.count(TR_OLD) == 1, 'e trans anchor'
    assert s.count(KEY_ANCH) == 1, 'e key anchor'
    assert s.count(ESC_OLD) == 1, 'e esc anchor'
    assert s.count(PANEL_ANCH) == 1, 'e panel anchor'
    assert s.count(HINT_OLD) == 1, 'e hint anchor'
    for b in (TR_NEW, KEY_NEW, ESC_NEW, PANEL_NEW,
              HINT_NEW):
        clean(b, 78)
    s = s.replace(TR_OLD, TR_NEW)
    s = s.replace(KEY_ANCH, KEY_NEW)
    s = s.replace(ESC_OLD, ESC_NEW)
    s = s.replace(PANEL_ANCH, PANEL_NEW)
    s = s.replace(HINT_OLD, HINT_NEW)
    wr(AD, s)
    applied.append('adnd1.cpp: the stage machine')
s = rd(AD)
assert s.count('case CR_SUBRACE:') == 2, 'e both cases'
assert s.count('cr.stage = CR_SUBRACE;') == 2, 'e enters'
assert s.count('cr.subraceOptionCount()') == 2, 'e rows'
assert s.count('[esc] sub-race') == 1, 'e hint'
assert len(applied) + len(already) == 5, 'e count'

# ---- (f) game/state_core.cpp: the save/load ----
CO = 'game/state_core.cpp'
s = rd(CO)
if 'strcmp(tag, "fem")' in s:
    already.append('state_core.cpp: the save/load')
else:
    SAVE_ANCH = '                        c.uaSubrace);'
    SAVE_NEW = NL.join([
    SAVE_ANCH,
    '            // R326: the member sex (only',
    '            // when female - v1 saves carry',
    '            // no line and load as male)',
    '            if (c.female)',
    '                fprintf(f, "fem 1\\n");'])
    LOAD_ANCH = NL.join([
    '                    c.uaSubrace = us;',
    '                } else if (strcmp(tag,'
    ' "subclass") == 0) {'])
    LOAD_NEW = NL.join([
    '                    c.uaSubrace = us;',
    '                } else if (strcmp(tag, "fem")'
    ' == 0) {',
    '                    int fm = 0;',
    '                    if (fscanf(f, "%d", &fm)'
    ' != 1 ||',
    '                        fm < 0 || fm > 1) {',
    '                        fclose(f);',
    '                        log.add("adnd1.sav is'
    ' corrupt (fem).");',
    '                        return false;',
    '                    }',
    '                    c.female = (fm != 0);',
    '                } else if (strcmp(tag,'
    ' "subclass") == 0) {'])
    RST_ANCH = '        creation.female = false;' \
               '    // R154'
    RST_NEW = NL.join([
    RST_ANCH,
    '        creation.subracePick = 0;'
    '    // R326'])
    assert s.count(SAVE_ANCH) == 1, 'f save anchor'
    assert s.count(LOAD_ANCH) == 1, 'f load anchor'
    assert s.count(RST_ANCH) == 1, 'f reset anchor'
    for b in (SAVE_NEW, LOAD_NEW, RST_NEW):
        clean(b, 78)
    s = s.replace(SAVE_ANCH, SAVE_NEW)
    s = s.replace(LOAD_ANCH, LOAD_NEW)
    s = s.replace(RST_ANCH, RST_NEW)
    wr(CO, s)
    applied.append('state_core.cpp: the save/load')
s = rd(CO)
assert s.count('"fem 1\\n"') == 1, 'f save line'
assert s.count('strcmp(tag, "fem")') == 1, 'f load tag'
assert s.count('corrupt (fem).') == 1, 'f gate log'
assert s.count('c.uaSubrace = us;') == 1, 'f uasub kept'
assert s.count('c.race = rc;') == 1, 'f race kept'
assert s.count('creation.subracePick = 0;') == 1, 'f reset'
assert len(applied) + len(already) == 6, 'f count'

# ---- (g) the gap report: the close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'CLOSED R326' in s:
    already.append('gap report: the close')
else:
    ANCH = 'census 252).'
    NEW = NL.join([
    'census 252).',
    ' The creation round CLOSED R326:',
    'the sub-race picker stage (the',
    'CR_SUBRACE offer), the female',
    'field with its save line, the',
    'dark-elf sex split live at the',
    'fold; the R326 audit, census 253.'])
    assert s.count(ANCH) == 1, 'g anchor'
    clean(NEW, 57)
    s = s.replace(ANCH, NEW)
    wr(GP, s)
    applied.append('gap report: the close')
s = rd(GP)
assert s.count('CLOSED R326') == 1, 'g close'
assert s.count('CLOSED R325') == 1, 'g r325 kept'
assert s.count('CLOSED R324') == 1, 'g r324 kept'
assert len(applied) + len(already) == 7, 'g count'

# ---- (h) regtest.cpp: the R326 audit ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R326 subrace creation audit' in s:
    already.append('regtest.cpp: the R326 audit')
else:
    ANCH = NL.join([
    '        printf("R325 subrace level cap'
    ' audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    '',
    '    // ---- R227: the wis mental save'
    ' wiring audit ----'])
    AUDIT = NL.join([
    '        printf("R325 subrace level cap'
    ' audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R326: the creation round'
    ' audit ----',
    '    // The sub-race picker rows (the',
    '    // CR_SUBRACE stage), the makeMember',
    '    // wiring (the uaSubrace and female',
    '    // fields), and the dark-elf sex',
    '    // split live at the fold (the',
    '    // female columns of Race Table II',
    '    // read through uaLevelCap). The',
    '    // save line and the load tag are',
    '    // splice-assert verified only (the',
    '    // battery never writes adnd1.sav).',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the picker rows (SUB_NONE',
    '        // first; SUB_HUMAN stays a',
    '        // matrix id)',
    '        {',
    '            CreationState cr;',
    '            cr.racePick = 0;',
    '            if (cr.subraceOptionCount()'
    ' != 1)',
    '                ++bad;',
    '            if (cr.subraceOption(0)'
    ' != SUB_NONE)',
    '                ++bad;',
    '            cr.racePick = 1;',
    '            if (cr.subraceOptionCount()'
    ' != 4)',
    '                ++bad;',
    '            if (cr.subraceOption(1)',
    '                != SUB_DWARF_GRAY) ++bad;',
    '            if (cr.subraceOption(2)',
    '                != SUB_DWARF_HILL) ++bad;',
    '            if (cr.subraceOption(3)',
    '                != SUB_DWARF_MOUNTAIN) ++bad;',
    '            cr.racePick = 2;',
    '            if (cr.subraceOptionCount()'
    ' != 7)',
    '                ++bad;',
    '            if (cr.subraceOption(1)',
    '                != SUB_ELF_DARK) ++bad;',
    '            if (cr.subraceOption(6)',
    '                != SUB_ELF_WOOD) ++bad;',
    '            cr.racePick = 3;',
    '            if (cr.subraceOptionCount()'
    ' != 3)',
    '                ++bad;',
    '            cr.racePick = 4;',
    '            if (cr.subraceOptionCount()'
    ' != 2)',
    '                ++bad;',
    '            cr.racePick = 5;',
    '            if (cr.subraceOptionCount()'
    ' != 4)',
    '                ++bad;',
    '            cr.racePick = 6;',
    '            if (cr.subraceOptionCount()'
    ' != 2)',
    '                ++bad;',
    '            // off-menu rows read none',
    '            if (cr.subraceOption(-1)',
    '                != SUB_NONE) ++bad;',
    '            if (cr.subraceOption(9)',
    '                != SUB_NONE) ++bad;',
    '        }',
    '        // U2: the makeMember wiring',
    '        {',
    '            CreationState cr;',
    '            cr.rollFresh();',
    '            cr.racePick = 2;',
    '            cr.female = true;',
    '            cr.subracePick ='
    ' (int)SUB_ELF_DARK;',
    '            Character c = cr.makeMember(1);',
    '            if (c.race != 2) ++bad;',
    '            if (c.uaSubrace !='
    ' (int)SUB_ELF_DARK)',
    '                ++bad;',
    '            if (!c.female) ++bad;',
    '            // the default path: a fresh',
    '            // state carries none and male',
    '            CreationState d;',
    '            d.rollFresh();',
    '            Character e = d.makeMember(0);',
    '            if (e.uaSubrace != 0) ++bad;',
    '            if (e.female) ++bad;',
    '        }',
    '        // U3: the dark-elf sex split at',
    '        // the fold (engine caps F 9,',
    '        // MU 11, C 9)',
    '        {',
    '            AbilityScores a;',
    '            ExceptionalStrength ex;',
    '            a.str = 14; a.int_ = 17;',
    '            a.wis = 15; a.dex = 14;',
    '            // drow MU INT 17: male 12+2',
    '            // -> 11; female 5+2 -> 7',
    '            if (uaLevelCap(11, SUB_ELF_DARK,',
    '                UACLASS_MAGIC_USER, a, ex,'
    ' 0, 0)',
    '                != 11) ++bad;',
    '            if (uaLevelCap(11, SUB_ELF_DARK,',
    '                UACLASS_MAGIC_USER, a, ex,'
    ' 0, 1)',
    '                != 7) ++bad;',
    '            // drow cleric WIS 17: male 7',
    '            // (no +2 - no elven cleric',
    '            // combo); female U -> 9',
    '            if (uaLevelCap(9, SUB_ELF_DARK,',
    '                UACLASS_CLERIC, a, ex, 0, 0)',
    '                != 7) ++bad;',
    '            if (uaLevelCap(9, SUB_ELF_DARK,',
    '                UACLASS_CLERIC, a, ex, 0, 1)',
    '                != 9) ++bad;',
    '            // the female fighter columns',
    '            // sit above the engine cap -',
    '            // both 9',
    '            if (uaLevelCap(9, SUB_ELF_DARK,',
    '                UACLASS_FIGHTER, a, ex,'
    ' 0, 0)',
    '                != 9) ++bad;',
    '            if (uaLevelCap(9, SUB_ELF_DARK,',
    '                UACLASS_FIGHTER, a, ex,'
    ' 0, 1)',
    '                != 9) ++bad;',
    '            // invariance: the female flag',
    '            // moves no non-dark column',
    '            if (uaLevelCap(9, SUB_DWARF_HILL,',
    '                UACLASS_FIGHTER, a, ex, 0, 0)',
    '                != uaLevelCap(9,'
    ' SUB_DWARF_HILL,',
    '                UACLASS_FIGHTER, a, ex,'
    ' 0, 1))',
    '                ++bad;',
    '            // the split holds on the',
    '            // multi path (no +2): female',
    '            // 5, male 12+2 -> 11',
    '            if (uaLevelCap(11,'
    ' SUB_ELF_DARK,',
    '                UACLASS_MAGIC_USER, a, ex,'
    ' 9, 1)',
    '                != 5) ++bad;',
    '            if (uaLevelCap(11,'
    ' SUB_ELF_DARK,',
    '                UACLASS_MAGIC_USER, a, ex,'
    ' 9, 0)',
    '                != 11) ++bad;',
    '        }',
    '        // U4: the live fold - the female',
    '        // drow MU stops at 7, the male at',
    '        // 11; the female flag moves no',
    '        // non-dark walk (hairfoot cleric',
    '        // pins 4 both)',
    '        {',
    '            // A: the female drow MU',
    '            {',
    '                AppState st;',
    '                st.party.formed = true;',
    '                Character c;',
    '                c.name = "Liriel";',
    '                c.race = 2;',
    '                c.uaSubrace = SUB_ELF_DARK;',
    '                c.female = true;',
    '                c.classIndex = 1;',
    '                c.abilities.int_ = 17;',
    '                c.level = 1;',
    '                c.hp = 30; c.maxHp = 30;',
    '                st.party.members.push_back(c);',
    '                st.rng.seed(7);',
    '                for (int i = 0; i < 30; ++i) {',
    '                    st.party.gainXp('
    '1000000,',
    '                        st.dice, st.log);',
    '                    st.party.trainNext(',
    '                        st.dice, st.log);',
    '                }',
    '                if (st.party.members[0]'
    '.level',
    '                    != 7) ++bad;',
    '            }',
    '            // B: the male drow MU (the',
    '            // R325 male read through the',
    '            // flag)',
    '            {',
    '                AppState st;',
    '                st.party.formed = true;',
    '                Character c;',
    '                c.name = "Jarlaxle";',
    '                c.race = 2;',
    '                c.uaSubrace = SUB_ELF_DARK;',
    '                c.female = false;',
    '                c.classIndex = 1;',
    '                c.abilities.int_ = 17;',
    '                c.level = 1;',
    '                c.hp = 30; c.maxHp = 30;',
    '                st.party.members.push_back(c);',
    '                st.rng.seed(7);',
    '                for (int i = 0; i < 30; ++i) {',
    '                    st.party.gainXp('
    '1000000,',
    '                        st.dice, st.log);',
    '                    st.party.trainNext(',
    '                        st.dice, st.log);',
    '                }',
    '                if (st.party.members[0]'
    '.level',
    '                    != 11) ++bad;',
    '            }',
    '            // C: the female hairfoot',
    '            // cleric - the flag must not',
    '            // move the walk',
    '            {',
    '                AppState st;',
    '                st.party.formed = true;',
    '                Character c;',
    '                c.name = "Pippa";',
    '                c.race = 5;',
    '                c.uaSubrace =',
    '                    SUB_HALFLING_HAIRFOOT;',
    '                c.female = true;',
    '                c.classIndex = 2;',
    '                c.abilities.wis = 15;',
    '                c.level = 1;',
    '                c.hp = 30; c.maxHp = 30;',
    '                st.party.members.push_back(c);',
    '                st.rng.seed(7);',
    '                for (int i = 0; i < 30; ++i) {',
    '                    st.party.gainXp('
    '1000000,',
    '                        st.dice, st.log);',
    '                    st.party.trainNext(',
    '                        st.dice, st.log);',
    '                }',
    '                if (st.party.members[0]'
    '.level',
    '                    != 4) ++bad;',
    '            }',
    '        }',
    '        printf("R326 subrace creation'
    ' audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    '',
    '    // ---- R227: the wis mental save'
    ' wiring audit ----'])
    assert s.count(ANCH) == 1, 'h anchor'
    clean(AUDIT, 76)
    s = s.replace(ANCH, AUDIT)
    wr(RT, s)
    applied.append('regtest.cpp: the R326 audit')
s = rd(RT)
assert s.count('R326 subrace creation audit: bad ') \
    == 1, 'h audit line'
assert s.count('audit: bad ') == 253, 'h census 253'
assert s.count('R325 subrace level cap audit') \
    == 1, 'h r325 kept'
assert s.count('st.dice, st.log);') >= 8, 'h dice legs'
assert s.count(
    'R227: the wis mental save'
    ' wiring audit ----') == 1, 'h r227 kept'
assert len(applied) + len(already) == 8, 'h count'

# ---- the summary ----
print('R326 splice: ALL OK (applied %d,'
      ' already %d)'
      % (len(applied), len(already)))
print('R326 note: the UA creation round -')
print('the CR_SUBRACE picker stage (rows')
print('from subraceParentRace), the female')
print('field with its save line, the')
print('dark-elf sex split live at the fold')
print('(uaLevelCap female leg); the battery')
print('census 252 -> 253')
print('commit: R326: the UA creation round')
print('- the sub-race picker and the')
print('dark-elf sex split (census 253)')

