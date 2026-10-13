#!/usr/bin/env python3
# R403: the mount layer seam -
# the deferred engine seam
# lands (the user pick). The
# R321 aerial precedent rides:
# the pins charge here, the
# mounted-combat charge (the
# mount actor, the mounted
# resolution) charges the
# engine later:
#
# 1. rules/mountlayer.h (NEW,
#    prefix mml, 10 inline
#    functions): the layer
#    contract (no mount actor
#    site today; the pins
#    precede the site; the
#    seam gates the charge),
#    the six-feeder registry
#    (R123 the mounted movement,
#    R170 the followers mounts,
#    R189 the charge damage,
#    R321 the aerial
#    environment, R328 the
#    cavalier mounted reads,
#    R356 the mount spell), and
#    the flying-steed ladder
#    (7th pegasus, 9th
#    hippogriff, 11th griffon -
#    cross-declared against the
#    cavalier horsemanship
#    tail).
# 2. regtest.cpp: the include
#    rides the R189 block, the
#    new R403 audit block lands
#    before the R227 anchor -
#    every feeder cross-checks
#    live (the lance rows, the
#    saddle percent, the
#    horsemanship agreement, the
#    aerial rates, the movement
#    table, the warhorse, the
#    spell ladder); census
#    329 -> 330.
# 3. tools/ua_gap_report.md:
#    the seam checkbox closes;
#    the DEFERRED block takes
#    an AMENDED R403 note.
# 4. The seed takes the R402
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
        'R403 splice ABORT: ' + msg)


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
    '- R402 landed 2026-10-13:',
    '  commit 99f8bd2 (census 329,',
    '  preflight GREEN), the UA',
    '  treasure system dial - the',
    '  R374 RUN BOTH decision wires:',
    '  the runtime dial layer rides',
    '  rules/uatreasuredial.h (the',
    '  mode static, the',
    '  validity-gated setter, the',
    '  mode names, the dial-landed',
    '  pin; the pending pins flip',
    '  false - the UA pin rounds',
    '  landed) and the mode-aware',
    '  determination dispatch rides',
    '  dm/treasure.cpp (the UA',
    '  category bands, the carrier',
    '  map, the sub-table splits -',
    '  low the new UA table, high',
    '  the DMG original, the misc',
    '  seven sub-bands all UA - the',
    '  row resolution off the R395',
    '  bands, the MERGED union coin',
    '  flip; the TU pulls its own',
    '  rules includes - the R400',
    '  lesson). The DMG default',
    '  keeps the seventy landed',
    '  audits authoritative. The',
    '  ./nn save hash diverged for',
    '  the tenth round running -',
    '  benign; the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R402 landed 2026-10-13' in s:
    already.append('seed: the R402 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R402 record')
s = rd(SD)
if s.count('R402 landed 2026-10-13') != 1:
    die('the R402 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/mountlayer.h =========
MT = 'rules/mountlayer.h'

MTBODY = E(
    '// ===========================================================================',
    '// Adnd1 - rules/mountlayer.h',
    '// The MOUNT LAYER (R403) - the',
    '// deferred engine seam lands. The',
    '// OUT reversal rides the R321',
    '// aerial precedent: the pins',
    '// charge here, the',
    '// mounted-combat charge (the',
    '// mount actor, the mounted',
    '// resolution) charges the engine',
    '// later; the engine has NO mount',
    '// actor and NO mounted-combat',
    '// site today. The layer',
    '// consolidates the six feeder',
    '// seams the corpus already',
    '// pinned and gates the',
    '// mounted-combat rules:',
    '//   0: R123 the mounted movement',
    '//      (dm/outdoormove.h - the',
    '//      60/25/5 light-horse row,',
    '//      the road-only cart and',
    '//      wagon)',
    '//   1: R170 the followers mounts',
    '//      (rules/followers.h - the',
    '//      animals and mounts tables,',
    '//      the paladin warhorse)',
    '//   2: R189 the charge damage',
    '//      (rules/weapontables.h - the',
    '//      three lances double from a',
    '//      charging mount, the spear',
    '//      set receives)',
    '//   3: R321 the aerial environment',
    '//      (rules/aerial.h - the',
    '//      flying steed climbs at',
    '//      half and dives at double)',
    '//   4: R328 the cavalier mounted',
    '//      reads (rules/cavalier.h -',
    '//      the human +1 level mounted,',
    '//      the 85 percent saddle, the',
    '//      horsemanship ladder, the',
    '//      steed hp and worth)',
    '//   5: R356 the mount spell',
    '//      (rules/uamuspells1.h - the',
    '//      summoned steed ladder)',
    '// The R403 audit cross-checks',
    '// every feeder live; the charge',
    '// stays open.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// ---- the layer contract ----',
    '// The engine has no mount actor',
    '// (the pins precede any site).',
    'inline bool mmlMountActorSiteExists()',
    '    { return false; }',
    '',
    'inline bool mmlPinsPrecedeSite()',
    '    { return true; }',
    '',
    '// The seam gates the',
    '// mounted-combat charge.',
    'inline bool mmlGatesMountedCombatCharge()',
    '    { return true; }',
    '',
    '// The charge (the mount actor,',
    '// the mounted resolution) stays',
    '// open after the seam lands.',
    'inline bool mmlMountedCombatChargeOpen()',
    '    { return true; }',
    '',
    '// The named precedent: the R321',
    '// aerial environment - pins',
    '// first, the site charged later.',
    'inline int mmlAerialPrecedentRound()',
    '    { return 321; }',
    '',
    '// ---- the feeder registry ----',
    'inline int mmlFeederSeamCount()',
    '    { return 6; }',
    '',
    '// The feeder rounds, in registry',
    '// order (0-5 above).',
    'inline int mmlFeederRound(int i) {',
    '    static const int k[6] = {',
    '        123, 170, 189, 321, 328, 356',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return k[i];',
    '}',
    '',
    '// ---- the flying steeds ----',
    '// The cavalier horsemanship',
    '// ladder grants three flying',
    '// steeds: the 7th pegasus, the',
    '// 9th hippogriff, the 11th',
    '// griffon.',
    'inline int mmlFlyingSteedCount()',
    '    { return 3; }',
    '',
    'inline int mmlFlyingSteedGrantLevel(',
    '        int i) {',
    '    static const int k[3] = { 7, 9, 11 };',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    return k[i];',
    '}',
    '',
    '// The flying steed rides the R321',
    '// aerial environment (the climb',
    '// and dive rates, the ceiling).',
    'inline bool mmlFlyingSteedsRideAerialEnv()',
    '    { return true; }',
    '',
    '}   // namespace rules',
    '')
newfile(MT, MTBODY + NL,
        'the mount layer header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/weapontables.h"'
     '  // R189: the weapon weight'
     ' and damage table',
     E(
    '#include "rules/weapontables.h"  '
    '// R189: the weapon weight and'
    ' damage table',
    '#include "rules/mountlayer.h"  '
    '// R403: the mount layer seam'),
     'regtest: the mount layer include')

AUD = E(
    '    // ---- R403: the mount layer',
    '    // seam audit ----',
    '    // The deferred seam lands: the',
    '    // layer contract (no mount',
    '    // actor site; the pins precede',
    '    // the site; the seam gates the',
    '    // mounted-combat charge) and',
    '    // the live cross-checks of the',
    '    // six feeders - R123 the',
    '    // mounted movement, R170 the',
    '    // followers mounts, R189 the',
    '    // charge damage, R321 the',
    '    // aerial environment, R328 the',
    '    // cavalier mounted reads, R356',
    '    // the mount spell. The flying',
    '    // steed ladder cross-declares',
    '    // against the cavalier',
    '    // horsemanship tail; census',
    '    // 329 -> 330.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the layer contract ----',
    '        if (mmlMountActorSiteExists()) ++bad;',
    '        if (!mmlPinsPrecedeSite()) ++bad;',
    '        if (!mmlGatesMountedCombatCharge()) ++bad;',
    '        if (!mmlMountedCombatChargeOpen()) ++bad;',
    '        if (mmlAerialPrecedentRound() != 321) ++bad;',
    '        // ---- the feeder registry ----',
    '        if (mmlFeederSeamCount() != 6) ++bad;',
    '        if (mmlFeederRound(0) != 123',
    '                || mmlFeederRound(1) != 170',
    '                || mmlFeederRound(2) != 189)',
    '            ++bad;',
    '        if (mmlFeederRound(3) != 321',
    '                || mmlFeederRound(4) != 328',
    '                || mmlFeederRound(5) != 356)',
    '            ++bad;',
    '        // ---- the R189 charge seam ----',
    '        if (lanceChargingDouble(23)) ++bad;',
    '        if (!lanceChargingDouble(24)',
    '                || !lanceChargingDouble(25)',
    '                || !lanceChargingDouble(26))',
    '            ++bad;',
    '        if (lanceChargingDouble(27)) ++bad;',
    '        if (!spearSetChargingDouble()) ++bad;',
    '        // ---- the R328 cavalier seam ----',
    '        if (cavalierHumanMountedLevelBonus()',
    '                != 1) ++bad;',
    '        if (cavalierSaddlePercent(1) != 85)',
    '            ++bad;',
    '        if (cavalierSaddlePercent(8) != 92)',
    '            ++bad;',
    '        if (cavalierSteedHpBonusPerDie() != 2)',
    '            ++bad;',
    '        // the flying steed ladder',
    '        // agreement (the mml',
    '        // cross-declaration vs the',
    '        // cavalier horsemanship tail)',
    '        for (int i = 0;',
    '             i < mmlFlyingSteedCount();',
    '             ++i)',
    '            if (mmlFlyingSteedGrantLevel(i)',
    '                    != cavalierHorsemanshipLevel(',
    '                        i + 3))',
    '                ++bad;',
    '        if (mmlFlyingSteedGrantLevel(0) != 7)',
    '            ++bad;',
    '        if (mmlFlyingSteedGrantLevel(2) != 11)',
    '            ++bad;',
    '        if (!mmlFlyingSteedsRideAerialEnv())',
    '            ++bad;',
    '        // ---- the R321 aerial seam ----',
    '        if (aerialClimbRateDivisor() != 2) ++bad;',
    '        if (aerialDiveRateMultiple() != 2) ++bad;',
    '        // ---- the R123 movement seam ----',
    '        if (dm::mountedMilesPerDay(',
    '                dm::MOUNT_LIGHT, dm::TC_NORMAL)',
    '                != 60) ++bad;',
    '        if (dm::mountedMilesPerDay(',
    '                dm::MOUNT_HEAVY,',
    '                dm::TC_VERY_RUGGED) != 5) ++bad;',
    '        if (dm::mountedMilesPerDay(',
    '                dm::MOUNT_WAGON,',
    '                dm::TC_VERY_RUGGED) != 0) ++bad;',
    '        // ---- the R170 followers seam ----',
    '        if (folPaladinWarhorseMinLevel() != 4)',
    '            ++bad;',
    '        if (folPaladinWarhorseServiceYears() != 10)',
    '            ++bad;',
    '        // ---- the R356 spell seam ----',
    '        if (uam1MountLevel() != 1) ++bad;',
    '        if (uam1MountCastingTimeRounds() != 1)',
    '            ++bad;',
    '        if (!uam1MountServesThenReturns()) ++bad;',
    '        if (uam1MountMuleLightHorseMaxLevel()',
    '                != 3) ++bad;',
    '        printf("R403 mount layer seam'
    ' audit: bad %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R403 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '- [ ] The mount layer - gates the',
    '      mounted-combat rules.'),
    E(
    '- [x] The mount layer -',
    '      CLOSED R403 (rules/mountlayer.h;',
    '      the R403 seam audit, census 330):',
    '      the layer contract (no mount',
    '      actor site - the pins precede',
    '      the site, the R321 aerial',
    '      precedent) and the six-feeder',
    '      registry - R123 the mounted',
    '      movement, R170 the followers',
    '      mounts, R189 the charge damage,',
    '      R321 the aerial environment,',
    '      R328 the cavalier mounted reads,',
    '      R356 the mount spell - all',
    '      cross-checked live in the audit,',
    '      with the flying steed ladder',
    '      (7th pegasus, 9th hippogriff,',
    '      11th griffon) cross-declared',
    '      against the cavalier',
    '      horsemanship tail. The',
    '      mounted-combat charge (the',
    '      mount actor, the mounted',
    '      resolution) stays open - a',
    '      new ungated item.'),
    'gap: the seam checkbox')

pair(GP, E(
    '- DEFERRED: the mounted-combat rules (a',
    '  mount layer; the R321 aerial precedent',
    '  - the pins would precede any site).'),
    E(
    '- DEFERRED: the mounted-combat rules (a',
    '  mount layer; the R321 aerial precedent',
    '  - the pins would precede any site).',
    '  - AMENDED R403: the layer lands -',
    '    rules/mountlayer.h carries the',
    '    contract and the six-feeder',
    '    registry; the mounted-combat',
    '    charge stays open as its own',
    '    ungated item.'),
    'gap: the DEFERRED amendment')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 330:
    die('the census %d' % s.count('audit: bad'))
if s.count('R403 mount layer seam'
           ' audit') != 1:
    die('the R403 audit label')
if s.count('mmlFeederRound(') != 6:
    die('the feeder call count %d'
        % s.count('mmlFeederRound('))
if s.count('mmlFlyingSteedGrantLevel(') != 3:
    die('the grant call count %d'
        % s.count('mmlFlyingSteedGrantLevel('))
if s.count('mmlMountActorSiteExists()') != 1:
    die('the actor site count')

p = rd(MT)
if p.count('inline') != 10:
    die('the mount layer inline count %d'
        % p.count('inline'))
if 'mmlFeederSeamCount' not in p:
    die('the feeder registry pin')
if not p.endswith(NL):
    die('the mount layer trailing newline')

g = rd(GP)
if g.count('AMENDED R403') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R403'))
if g.count('CLOSED R403') != 1:
    die('the gap closed count %d'
        % g.count('CLOSED R403'))

for path, mark in ((MT, 'mmlFeederRound'),
                   (RT, 'mmlMountActorSiteExists'),
                   (SD, 'R402 landed')):
    if mark not in rd(path):
        die('%s carries no R403 seam' % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if 'mml' in rd(path):
        die('%s calls the layer early'
            % path)

print('R403 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the mount layer seam lands -')
print('  the contract and the six-feeder')
print('  registry pin; the mounted-combat')
print('  charge stays open; census'
      ' 329 -> 330')
print('commit: R403: the mount layer'
      ' seam (census 330)')

