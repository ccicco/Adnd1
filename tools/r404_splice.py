#!/usr/bin/env python3
# R404: the psionics seam - the
# deferred engine seam lands
# (user pick). The R403 mount
# precedent rides: pins first,
# the psionic-combat charge
# stays open:
#
# 1. rules/psionics.h (NEW,
#    prefix psx, 15 inline
#    functions): the layer
#    contract (no psionic
#    combat site; the pins
#    precede the site; the
#    seam gates the psionic
#    expansions), the open
#    records (the PHB psionic
#    sections OPEN; the DMG
#    p.77 IV.A combat OUT -
#    the recorded scope
#    decision, reversed when
#    the seam charges), the
#    NEW duergar pin (UA
#    p. 10, the clean scan:
#    not all PC duergar are
#    psionic; twice the usual
#    chance - double all
#    bonuses for INT, WIS and
#    CHA - if psionics are
#    used in the campaign),
#    the svirfneblin PC ban
#    (UA p. 11), the doubled
#    bonus arithmetic, and the
#    three-feeder registry
#    (R166 insanity, R323
#    subraces, R328 cavalier).
# 2. regtest.cpp: the include
#    rides the R166 block, the
#    new R404 audit block lands
#    before the R227 anchor -
#    every feeder cross-checks
#    live (the four mild
#    insanities, the duration
#    classes, the 90 percent
#    and the mind-blast roster
#    entry, the svirfneblin
#    noPsionics trait, the
#    duergar not-all-psionic
#    read); census 330 -> 331.
# 3. tools/ua_gap_report.md:
#    the seam checkbox closes;
#    the DEFERRED block takes
#    an AMENDED R404 note.
# 4. The seed takes the R403
#    record.
import io
import os

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
        'R404 splice ABORT: ' + msg)


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


def newfile(path, body, label):
    if os.path.exists(path):
        already.append(label)
        return
    wr(path, body)
    applied.append(label)


# ========= (a) the seed record =========
SD = 'doc/vibe/' \
     'adnd1_knowledge_seed_v2.md'

SEED_ENTRY = E(
    '- R403 landed 2026-10-13:',
    '  commit feddba6 (census 330,',
    '  preflight GREEN), the mount',
    '  layer seam - the deferred',
    '  engine seam lands on the R321',
    '  aerial precedent: rules/',
    '  mountlayer.h (prefix mml, 10',
    '  inline functions) - the',
    '  layer contract (no mount',
    '  actor site; pins precede',
    '  site; the charge stays',
    '  open) and the six-feeder',
    '  registry (R123 movement,',
    '  R170 followers, R189 charge',
    '  damage, R321 aerial, R328',
    '  cavalier, R356 the mount',
    '  spell), with the flying',
    '  steed ladder cross-declared',
    '  against the cavalier',
    '  horsemanship tail. The',
    '  mounted-combat charge stays',
    '  open as its own ungated',
    '  item. The ./nn save hash',
    '  diverged for the eleventh',
    '  round running - benign; the',
    '  md5 stays advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R403 landed 2026-10-13' in s:
    already.append('seed: the R403 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R403 record')
s = rd(SD)
if s.count('R403 landed 2026-10-13') != 1:
    die('the R403 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/psionics.h =========
PS = 'rules/psionics.h'

PSBODY = E(
    '// ===========================================================================',
    '// Adnd1 - rules/psionics.h',
    '// The PSIONICS SEAM (R404) - the',
    '// deferred engine seam lands. The',
    '// R403 mount precedent rides: the',
    '// pins charge here, the',
    '// psionic-combat charge (the',
    '// psionic potential roll, the',
    '// attack and defense modes, the',
    '// point economy) charges the',
    '// engine later; the engine has NO',
    '// psionic site today.',
    '//',
    '// The gated reads: the PHB psionic',
    '// sections stay OPEN (the',
    '// phb_gap report carries them);',
    '// the DMG p.77 PSIONIC COMBAT',
    '// (IV.A and following) stays OUT',
    '// - the recorded R104-era scope',
    '// decision - until the seam',
    '// charges.',
    '//',
    '// The UA expansion pins (pp. 10-11,',
    '// the clean djvu scan):',
    '//   - the duergar: not all player',
    '//     character duergar have psionic',
    '//     ability; they have TWICE the',
    '//     usual chance of being psionic',
    '//     (double all bonuses for',
    '//     intelligence, wisdom and',
    '//     charisma) if psionics are',
    '//     used in the campaign;',
    '//   - the svirfneblin: player',
    '//     character deep gnomes do NOT',
    '//     have psionic abilities.',
    '// The feeders the corpus already',
    '// pinned:',
    '//   0: R166 the insanity seam',
    '//      (rules/insanity.h - the four',
    '//      MILD forms subject to psionic',
    '//      attack, the duration classes)',
    '//   1: R323 the subrace layer',
    '//      (rules/subraces.h - the',
    '//      svirfneblin noPsionics trait)',
    '//   2: R328 the cavalier mind',
    '//      powers (rules/cavalier.h - the',
    '//      90 percent resistance, the',
    '//      psionic mind blast roster',
    '//      entry)',
    '// The R404 audit cross-checks every',
    '// feeder live; the charge stays',
    '// open.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// ---- the layer contract ----',
    '// The engine has no psionic site',
    '// (the pins precede any charge).',
    'inline bool psxPsionicSiteExists()',
    '    { return false; }',
    '',
    'inline bool psxPinsPrecedeCharge()',
    '    { return true; }',
    '',
    '// The seam gates the psionic',
    '// expansions.',
    'inline bool psxGatesPsionicExpansions()',
    '    { return true; }',
    '',
    '// The psionic-combat charge (the',
    '// potential roll, the modes, the',
    '// point economy) stays open after',
    '// the seam lands.',
    'inline bool psxPsionicChargeOpen()',
    '    { return true; }',
    '',
    '// ---- the open and OUT records ----',
    '// The PHB psionic sections stay',
    '// OPEN (the phb_gap report).',
    'inline bool psxPhbSectionsOpen()',
    '    { return true; }',
    '',
    '// The DMG psionic combat rides p.',
    '// 77 (IV.A and following) and stays',
    '// OUT - the recorded scope decision.',
    'inline int psxDmgPsionicCombatPage()',
    '    { return 77; }',
    '',
    'inline bool psxDmgCombatOutOfScope()',
    '    { return true; }',
    '',
    '// ---- the duergar pin (UA p. 10) ----',
    '// Not all player character duergar',
    '// have psionic ability.',
    'inline bool psxDuergarNotAllPsionic()',
    '    { return true; }',
    '',
    '// Twice the usual chance of being',
    '// psionic - if psionics are used in',
    '// the campaign.',
    'inline int psxDuergarChanceMultiple()',
    '    { return 2; }',
    '',
    '// The doubling reads all three',
    '// bonuses: intelligence, wisdom and',
    '// charisma.',
    'inline bool psxDuergarDoublesIntWisCha()',
    '    { return true; }',
    '',
    'inline bool psxDuergarDoubledOnlyIfUsed()',
    '    { return true; }',
    '',
    '// The doubled bonus arithmetic: the',
    '// usual psionic bonus doubles.',
    'inline int psxDuergarDoubledBonus(',
    '        int bonus) {',
    '    return psxDuergarChanceMultiple()',
    '           * bonus;',
    '}',
    '',
    '// ---- the svirfneblin pin (UA p. 11) ----',
    'inline bool psxSvirfneblinPcNoPsionics()',
    '    { return true; }',
    '',
    '// ---- the feeder registry ----',
    'inline int psxFeederSeamCount()',
    '    { return 3; }',
    '',
    '// The feeder rounds, in registry',
    '// order (0-2 above).',
    'inline int psxFeederRound(int i) {',
    '    static const int k[3] = {',
    '        166, 323, 328',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    return k[i];',
    '}',
    '',
    '}   // namespace rules',
    '')
newfile(PS, PSBODY + NL,
        'the psionics seam header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/insanity.h"  '
     '// R166: pp.82-83 intoxication'
     ' and insanity',
     E(
    '#include "rules/insanity.h"  // R166:'
    ' pp.82-83 intoxication and insanity',
    '#include "rules/psionics.h"  '
    '// R404: the psionics seam'),
     'regtest: the psionics include')

AUD = E(
    '    // ---- R404: the psionics seam',
    '    // audit ----',
    '    // The deferred seam lands: the',
    '    // layer contract (no psionic site;',
    '    // the pins precede the charge; the',
    '    // seam gates the psionic',
    '    // expansions), the open and OUT',
    '    // records (the PHB sections OPEN;',
    '    // the DMG p.77 combat OUT), the',
    '    // UA pp. 10-11 pins (the duergar',
    '    // doubled chance, the svirfneblin',
    '    // PC ban) and the live',
    '    // cross-checks of the three',
    '    // feeders - R166 the insanity seam,',
    '    // R323 the subrace layer, R328 the',
    '    // cavalier mind powers; census',
    '    // 330 -> 331.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the layer contract ----',
    '        if (psxPsionicSiteExists()) ++bad;',
    '        if (!psxPinsPrecedeCharge()) ++bad;',
    '        if (!psxGatesPsionicExpansions()) ++bad;',
    '        if (!psxPsionicChargeOpen()) ++bad;',
    '        // ---- the open and OUT records ----',
    '        if (!psxPhbSectionsOpen()) ++bad;',
    '        if (psxDmgPsionicCombatPage() != 77)',
    '            ++bad;',
    '        if (!psxDmgCombatOutOfScope()) ++bad;',
    '        // ---- the duergar pin ----',
    '        if (!psxDuergarNotAllPsionic()) ++bad;',
    '        if (psxDuergarChanceMultiple() != 2)',
    '            ++bad;',
    '        if (!psxDuergarDoublesIntWisCha()) ++bad;',
    '        if (!psxDuergarDoubledOnlyIfUsed()) ++bad;',
    '        // the doubled bonus arithmetic:',
    '        // every usual bonus doubles',
    '        if (psxDuergarDoubledBonus(1) != 2',
    '                || psxDuergarDoubledBonus(',
    '                    5) != 10',
    '                || psxDuergarDoubledBonus(',
    '                    10) != 20)',
    '            ++bad;',
    '        if (psxDuergarDoubledBonus(0) != 0) ++bad;',
    '        // ---- the svirfneblin pin ----',
    '        if (!psxSvirfneblinPcNoPsionics()) ++bad;',
    '        // ---- the feeder registry ----',
    '        if (psxFeederSeamCount() != 3) ++bad;',
    '        if (psxFeederRound(0) != 166',
    '                || psxFeederRound(1) != 323',
    '                || psxFeederRound(2) != 328)',
    '            ++bad;',
    '        // ---- the R166 insanity seam ----',
    '        // the four MILD forms (1-4) are',
    '        // subject to psionic attack;',
    '        // 5+ are not',
    '        for (int i = 1; i <= 4; ++i)',
    '            if (!insanityIsMild(i)) ++bad;',
    '        if (insanityIsMild(0)',
    '                || insanityIsMild(5)',
    '                || insanityIsMild(20)) ++bad;',
    '        // the duration classes ride the',
    '        // psionic section (2-12 temporary,',
    '        // 1-4 mild)',
    '        if (insanityTemporaryWeeksMin() != 2',
    '                || insanityTemporaryWeeksMax()',
    '                    != 12)',
    '            ++bad;',
    '        if (insanityMildWeeksMin() != 1',
    '                || insanityMildWeeksMax() != 4)',
    '            ++bad;',
    '        // ---- the R323 subrace seam ----',
    '        // the svirfneblin PC ban rides the',
    '        // trait table; the duergar row',
    '        // carries no ban (the not-all',
    '        // read)',
    '        if (subraceTraits(SUB_GNOME_DEEP)',
    '                .noPsionics != 1) ++bad;',
    '        if (subraceTraits(SUB_DWARF_GRAY)',
    '                .noPsionics != 0) ++bad;',
    '        // ---- the R328 cavalier seam ----',
    '        if (cavalierMindAffectResistPercent()',
    '                != 90) ++bad;',
    '        if (strcmp(cavalierMindPowerName(9),',
    '                   "psionic mind blast") != 0)',
    '            ++bad;',
    '        printf("R404 psionics seam'
    ' audit: bad %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R404 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '- [ ] The psionics seam - gates the',
    '      psionic expansions.'),
    E(
    '- [x] The psionics seam -',
    '      CLOSED R404 (rules/psionics.h;',
    '      the R404 seam audit, census 331):',
    '      the layer contract (no psionic',
    '      site - the pins precede the',
    '      charge, the R403 mount',
    '      precedent), the open and OUT',
    '      records (the PHB sections OPEN;',
    '      the DMG p.77 combat OUT), and',
    '      the UA pp. 10-11 pins - the',
    '      duergar doubled chance (twice',
    '      the usual, double all',
    '      INT/WIS/CHA bonuses, only if',
    '      psionics are used) and the',
    '      svirfneblin PC ban - live',
    '      cross-checked against the three',
    '      feeders (R166 insanity, R323',
    '      subraces, R328 cavalier). The',
    '      psionic-combat charge stays',
    '      open - a new ungated item.'),
    'gap: the seam checkbox')

pair(GP, E(
    '- DEFERRED: the psionic expansions (a',
    '  psionics seam; the duergar doubled',
    '  chance rides it).'),
    E(
    '- DEFERRED: the psionic expansions (a',
    '  psionics seam; the duergar doubled',
    '  chance rides it).',
    '  - AMENDED R404: the seam lands -',
    '    rules/psionics.h pins the duergar',
    '    doubled chance and the',
    '    svirfneblin PC ban (the clean',
    '    UA pp. 10-11 scan); the psionic',
    '    expansions (the PHB sections,',
    '    the DMG p.77 combat) stay open',
    '    on their own reads.'),
    'gap: the DEFERRED amendment')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 331:
    die('the census %d' % s.count('audit: bad'))
if s.count('R404 psionics seam'
           ' audit') != 1:
    die('the R404 audit label')
if s.count('psxFeederRound(') != 3:
    die('the feeder call count %d'
        % s.count('psxFeederRound('))
if s.count('psxDuergarDoubledBonus(') != 4:
    die('the doubled bonus call count %d'
        % s.count('psxDuergarDoubledBonus('))
if s.count('psxPsionicSiteExists()') != 1:
    die('the site count')

p = rd(PS)
if p.count('inline') != 15:
    die('the psionics inline count %d'
        % p.count('inline'))
if 'psxDuergarChanceMultiple' not in p:
    die('the duergar pin')
if not p.endswith(NL):
    die('the psionics trailing newline')

g = rd(GP)
if g.count('AMENDED R404') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R404'))
if g.count('CLOSED R404') != 1:
    die('the gap closed count %d'
        % g.count('CLOSED R404'))

for path, mark in ((PS, 'psxDuergarChanceMultiple'),
                   (RT, 'psxPsionicSiteExists'),
                   (SD, 'R403 landed')):
    if mark not in rd(path):
        die('%s carries no R404 seam' % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if 'psx' in rd(path):
        die('%s calls the seam early'
            % path)

print('R404 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the psionics seam lands - the')
print('  duergar doubled chance and the')
print('  svirfneblin PC ban pin; the')
print('  psionic-combat charge stays open;')
print('  census 330 -> 331')
print('commit: R404: the psionics seam'
      ' (census 331)')

