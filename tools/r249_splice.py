#!/usr/bin/env python3
# R249 splice: the III.A potions explanation prose pins, part 1.
#
# DMG pp.133-134, upload lines ~9998-10062 - the sixth
# prose arc of the EXPLANATIONS AND DESCRIPTIONS
# section (the first after the III.D arc closed at
# R248): the III.A POTIONS explanation prose, part 1
# of 3 - the general conventions and the FIRST NINE
# potion entries. The conventions: effects last 4
# complete turns plus 1-4 additional turns (d4); half
# doses last half as long in some cases; potions take
# effect 2-5 segments after they are imbibed. The nine
# potions: Animal Control (5-20 giant-rat-size, 3-12
# man-size, 1-4 half-ton-plus animals; save at
# intelligence 5 or better; the 7-row d20 animal type
# sub-table tiling 1-20), Clairaudience (3" range,
# 2 turns), Clairvoyance (3" range, 1 turn), Climbing
# (base 1% slip, 01 falls at the halfway d% check,
# 1 turn + 5-20 rounds, +1% per 1,000 g.p. carried;
# the 7-row armor table: studded leather 1%, ring
# mail 2%, scale mail 4%, chainmail 7%, banded or
# splinted 8%, plate mail 10%, magic armor 1%),
# Delusion (90% likely tasters all agree),
# Diminution (to 5% size, 50% on half dose, 6 turns
# + 2-5 turns d4+1), Dragon Control (charm monster
# within 6", save at -2; the 12-row d20 dragon type
# sub-table tiling 1-20; control lasts 5-20 5d4
# rounds), ESP (5-40 5d8 rounds), Extra-Healing
# (6-27 3d8+3 whole, 1-8 per one-third potion). The
# nine potions are the engine III.A table rows 1-9
# (dm/treasure.cpp kPotions, bands 01-26, fire
# resistance from 27) - cross-checked against the
# R221 potions.h pins in the audit.
# Patches: 4 (new rules/potionsprose.h, the regtest
# include, the audit block, the dmg-gap-report log
# entry). Census 167 -> 168.
#
# commit: R249: the III.A potions explanation prose part 1 pins pinned - DMG pp.133-134, the conventions and the first nine potions (census 168)

import sys

WD   = 'rules/potionsprose.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 167 and t.count('audit: bad ') != 168:
    print('R249 FAIL: regtest census is neither 167 nor 168')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/potionsprose.h',
    '// R249: the III.A potions explanation prose',
    '// pins, part 1 (DMG pp.133-134) - the general',
    '// conventions and the FIRST NINE potion',
    '// explanations (upload lines ~9998-10062):',
    '//   - the conventions: effects last 4',
    '//     complete turns plus 1-4 additional',
    '//     turns (d4); half doses last half as',
    '//     long in some cases; potions take',
    '//     effect 2-5 segments after they are',
    '//     imbibed.',
    '//   - Animal Control: 5-20 giant-rat-size,',
    '//     3-12 man-size, or 1-4 half-ton-plus',
    '//     animals; save at intelligence 5+; the',
    '//     7-row d20 animal type sub-table.',
    '//   - Clairaudience: 3" range, 2 turns.',
    '//   - Clairvoyance: 3" range, 1 turn.',
    '//   - Climbing: base 1% slip, 01 falls at',
    '//     the halfway d% check, 1 turn + 5-20',
    '//     rounds, +1% per 1,000 g.p. carried;',
    '//     the 7-row armor table (studded',
    '//     leather 1%, ring mail 2%, scale mail',
    '//     4%, chainmail 7%, banded or',
    '//     splinted 8%, plate mail 10%, magic',
    '//     armor any type 1%).',
    '//   - Delusion: 90% likely tasters agree.',
    '//   - Diminution: to 5% size (50% on half',
    '//     dose), 6 turns + 2-5 turns (d4+1).',
    '//   - Dragon Control: charm monster within',
    '//     6", save at -2; the 12-row d20',
    '//     dragon type sub-table; control lasts',
    '//     5-20 (5d4) rounds.',
    '//   - ESP: 5-40 (5d8) rounds.',
    '//   - Extra-Healing: 6-27 (3d8+3) whole,',
    '//     1-8 per one-third potion.',
    '// The nine potions are the engine III.A',
    '// table rows 1-9 (dm/treasure.cpp kPotions,',
    '// bands 01-26, fire resistance from 27) -',
    '// cross-checked against the R221 potions.h',
    '// pins in the audit.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int potDurationTurnsBase() {',
    '    // the conventions: effects last 4',
    '    // complete turns',
    '    return 4;',
    '}',
    '',
    'inline int potDurationExtraLo() {',
    '    // plus 1-4 additional turns (d4)',
    '    return 1;',
    '}',
    '',
    'inline int potDurationExtraHi() {',
    '    return 4;',
    '}',
    '',
    'inline int potOnsetLo() {',
    '    // potions take effect 2-5 segments',
    '    // after they are imbibed',
    '    return 2;',
    '}',
    '',
    'inline int potOnsetHi() {',
    '    return 5;',
    '}',
    '',
    'inline int potAnimalSmallLo() {',
    '    // Animal Control: 5-20 animals of',
    '    // the size of giant rats',
    '    return 5;',
    '}',
    '',
    'inline int potAnimalSmallHi() {',
    '    return 20;',
    '}',
    '',
    'inline int potAnimalManLo() {',
    '    // 3-12 animals of about man-size',
    '    return 3;',
    '}',
    '',
    'inline int potAnimalManHi() {',
    '    return 12;',
    '}',
    '',
    'inline int potAnimalLargeLo() {',
    '    // 1-4 animals of about half a ton',
    '    // or more in weight',
    '    return 1;',
    '}',
    '',
    'inline int potAnimalLargeHi() {',
    '    return 4;',
    '}',
    '',
    'inline int potAnimalSaveInt() {',
    '    // animals with intelligence of 5',
    '    // or better get a save versus magic',
    '    return 5;',
    '}',
    '',
    'inline int potAnimalTypeRowCount() {',
    '    // the animal type sub-table: 7 rows',
    '    return 7;',
    '}',
    '',
    'inline int potAnimalTypeLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 6) i = 6;',
    '    static const int t[7] = {',
    '        1, 5, 9, 13, 16, 18, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int potAnimalTypeHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 6) i = 6;',
    '    static const int t[7] = {',
    '        4, 8, 12, 15, 17, 19, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int potAnimalTypeFaces() {',
    '    // the animal type roll is on d20',
    '    return 20;',
    '}',
    '',
    'inline int potClairaudRangeInches() {',
    '    // Clairaudience: clairaudit unknown',
    '    // areas within 3"',
    '    return 3;',
    '}',
    '',
    'inline int potClairaudTurns() {',
    '    // the effects last for 2 turns only',
    '    return 2;',
    '}',
    '',
    'inline int potClairvoyRangeInches() {',
    '    // Clairvoyance: unknown areas up to',
    '    // 3" distant can be seen',
    '    return 3;',
    '}',
    '',
    'inline int potClairvoyTurns() {',
    '    // the effects last for 1 turn only',
    '    return 1;',
    '}',
    '',
    'inline int potClimbBasePercent() {',
    '    // Climbing: a base 1% chance of',
    '    // slipping and falling',
    '    return 1;',
    '}',
    '',
    'inline int potClimbFallRoll() {',
    '    // check at the halfway point, d%;',
    '    // 01 equals a fall',
    '    return 1;',
    '}',
    '',
    'inline int potClimbTurns() {',
    '    // effective for 1 turn',
    '    return 1;',
    '}',
    '',
    'inline int potClimbExtraRoundsLo() {',
    '    // plus 5 to 20 rounds',
    '    return 5;',
    '}',
    '',
    'inline int potClimbExtraRoundsHi() {',
    '    return 20;',
    '}',
    '',
    'inline int potClimbLoadIncrementGp() {',
    '    // for every 1,000 g.p. weight',
    '    // equivalent carried',
    '    return 1000;',
    '}',
    '',
    'inline int potClimbLoadPercent() {',
    '    // an additional 1% chance of slipping',
    '    return 1;',
    '}',
    '',
    'inline int potClimbArmorRowCount() {',
    '    // the climbing armor table: 7 rows',
    '    return 7;',
    '}',
    '',
    'inline int potClimbArmorPercent(int i) {',
    '    // the armor slip additions; i clamps:',
    '    // studded leather, ring mail, scale',
    '    // mail, chainmail, banded or',
    '    // splinted, plate mail, magic armor',
    '    if (i < 0) i = 0;',
    '    if (i > 6) i = 6;',
    '    static const int t[7] = {',
    '        1, 2, 4, 7, 8, 10, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int potDeludeAgreePercent() {',
    '    // Delusion: 90% probable that tasters',
    '    // will all agree it is the same potion',
    '    return 90;',
    '}',
    '',
    'inline int potDiminishMinPercent() {',
    '    // Diminution: diminish to as small as',
    '    // 5% of normal size',
    '    return 5;',
    '}',
    '',
    'inline int potDiminishHalfPercent() {',
    '    // half the contents: shrinks to 50%',
    '    return 50;',
    '}',
    '',
    'inline int potDiminishTurnsBase() {',
    '    // the effects last for 6 turns',
    '    return 6;',
    '}',
    '',
    'inline int potDiminishExtraLo() {',
    '    // plus 2-5 turns (d4 + 1)',
    '    return 2;',
    '}',
    '',
    'inline int potDiminishExtraHi() {',
    '    return 5;',
    '}',
    '',
    'inline int potDragonRangeInches() {',
    '    // Dragon Control: a charm monster',
    '    // effect upon any dragon within 6"',
    '    return 6;',
    '}',
    '',
    'inline int potDragonSaveMod() {',
    '    // the dragon save versus magic is',
    '    // made at -2 on the die',
    '    return -2;',
    '}',
    '',
    'inline int potDragonTypeRowCount() {',
    '    // the dragon type sub-table: 12 rows',
    '    return 12;',
    '}',
    '',
    'inline int potDragonTypeLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 11) i = 11;',
    '    static const int t[12] = {',
    '        1, 3, 5, 8, 10, 11, 13, 15, 16, 17, 18, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int potDragonTypeHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 11) i = 11;',
    '    static const int t[12] = {',
    '        2, 4, 7, 9, 10, 12, 14, 15, 16, 17, 19, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int potDragonTypeFaces() {',
    '    // the dragon type roll is on d20',
    '    return 20;',
    '}',
    '',
    'inline int potDragonLo() {',
    '    // control lasts for from 5-20',
    '    // (5d4) rounds',
    '    return 5;',
    '}',
    '',
    'inline int potDragonHi() {',
    '    return 20;',
    '}',
    '',
    'inline int potDragonDice() {',
    '    return 5;',
    '}',
    '',
    'inline int potDragonFaces() {',
    '    return 4;',
    '}',
    '',
    'inline int potEspLo() {',
    '    // ESP: the effects last for 5-40',
    '    // (5d8) rounds',
    '    return 5;',
    '}',
    '',
    'inline int potEspHi() {',
    '    return 40;',
    '}',
    '',
    'inline int potEspDice() {',
    '    return 5;',
    '}',
    '',
    'inline int potEspFaces() {',
    '    return 8;',
    '}',
    '',
    'inline int potXHealLo() {',
    '    // Extra-Healing: restores 6-27',
    '    // (3d8 + 3) hit points when wholly',
    '    // consumed',
    '    return 6;',
    '}',
    '',
    'inline int potXHealHi() {',
    '    return 27;',
    '}',
    '',
    'inline int potXHealDice() {',
    '    return 3;',
    '}',
    '',
    'inline int potXHealFaces() {',
    '    return 8;',
    '}',
    '',
    'inline int potXHealBonus() {',
    '    return 3;',
    '}',
    '',
    'inline int potXHealThirdLo() {',
    '    // or 1-8 hit points of damage for each',
    '    // one-third potion',
    '    return 1;',
    '}',
    '',
    'inline int potXHealThirdHi() {',
    '    return 8;',
    '}',
    '',
    '}  // namespace rules',
    '',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/wonder.h"  // R248: p.145 the III.D wand of wonder effect table pins',
]
inc_new = [
    '#include "rules/wonder.h"  // R248: p.145 the III.D wand of wonder effect table pins',
    '#include "rules/potionsprose.h"  // R249: pp.133-134 the III.A potions prose part 1 pins',
]

# ---- the regtest audit block ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R249: the III.A potions explanation prose part 1 pins audit ----',
    '    // DMG pp.133-134: the conventions and',
    '    // the first nine potions.',
    '    {',
    '        int bad = 0;',
    '        // the nine potions are the engine III.A',
    '        // table rows 1-9 - bands 01-26, fire',
    '        // resistance from 27 (the R221 pins)',
    '        if (rules::potionRowLo(0) != 1 ||',
    '            rules::potionRowHi(8) != 26 ||',
    '            rules::potionRowLo(9) != 27) ++bad;',
    '        // the general conventions',
    '        if (rules::potDurationTurnsBase() != 4 ||',
    '            rules::potDurationExtraLo() != 1 ||',
    '            rules::potDurationExtraHi() != 4 ||',
    '            rules::potOnsetLo() != 2 ||',
    '            rules::potOnsetHi() != 5) ++bad;',
    '        // Animal Control - the sizes and the save',
    '        if (rules::potAnimalSmallLo() != 5 ||',
    '            rules::potAnimalSmallHi() != 20 ||',
    '            rules::potAnimalManLo() != 3 ||',
    '            rules::potAnimalManHi() != 12 ||',
    '            rules::potAnimalLargeLo() != 1 ||',
    '            rules::potAnimalLargeHi() != 4 ||',
    '            rules::potAnimalSaveInt() != 5) ++bad;',
    '        // the animal type sub-table: 7 rows on d20',
    '        if (rules::potAnimalTypeRowCount() != 7 ||',
    '            rules::potAnimalTypeFaces() != 20) ++bad;',
    '        static const int kALo[7] = {',
    '            1, 5, 9, 13, 16, 18, 20,',
    '        };',
    '        static const int kAHi[7] = {',
    '            4, 8, 12, 15, 17, 19, 20,',
    '        };',
    '        for (int i = 0; i < 7; ++i)',
    '            if (rules::potAnimalTypeLo(i) != kALo[i] ||',
    '                rules::potAnimalTypeHi(i) != kAHi[i]) ++bad;',
    '        for (int i = 1; i < 7; ++i)',
    '            if (rules::potAnimalTypeLo(i) !=',
    '                rules::potAnimalTypeHi(i - 1) + 1) ++bad;',
    '        if (rules::potAnimalTypeLo(-5) != 1 ||',
    '            rules::potAnimalTypeHi(99) != 20) ++bad;',
    '        // Clairaudience / Clairvoyance',
    '        if (rules::potClairaudRangeInches() != 3 ||',
    '            rules::potClairaudTurns() != 2 ||',
    '            rules::potClairvoyRangeInches() != 3 ||',
    '            rules::potClairvoyTurns() != 1) ++bad;',
    '        // Climbing - the slip chance and the armor table',
    '        if (rules::potClimbBasePercent() != 1 ||',
    '            rules::potClimbFallRoll() != 1 ||',
    '            rules::potClimbTurns() != 1 ||',
    '            rules::potClimbExtraRoundsLo() != 5 ||',
    '            rules::potClimbExtraRoundsHi() != 20 ||',
    '            rules::potClimbLoadIncrementGp() != 1000 ||',
    '            rules::potClimbLoadPercent() != 1 ||',
    '            rules::potClimbArmorRowCount() != 7) ++bad;',
    '        static const int kArmor[7] = {',
    '            1, 2, 4, 7, 8, 10, 1,',
    '        };',
    '        for (int i = 0; i < 7; ++i)',
    '            if (rules::potClimbArmorPercent(i) != kArmor[i]) ++bad;',
    '        // Delusion / Diminution',
    '        if (rules::potDeludeAgreePercent() != 90 ||',
    '            rules::potDiminishMinPercent() != 5 ||',
    '            rules::potDiminishHalfPercent() != 50 ||',
    '            rules::potDiminishTurnsBase() != 6 ||',
    '            rules::potDiminishExtraLo() != 2 ||',
    '            rules::potDiminishExtraHi() != 5) ++bad;',
    '        // Dragon Control - the charm and the save',
    '        if (rules::potDragonRangeInches() != 6 ||',
    '            rules::potDragonSaveMod() != -2 ||',
    '            rules::potDragonLo() != 5 ||',
    '            rules::potDragonHi() != 20 ||',
    '            rules::potDragonDice() != 5 ||',
    '            rules::potDragonFaces() != 4) ++bad;',
    '        // the dragon type sub-table: 12 rows on d20',
    '        if (rules::potDragonTypeRowCount() != 12 ||',
    '            rules::potDragonTypeFaces() != 20) ++bad;',
    '        static const int kDLo[12] = {',
    '            1, 3, 5, 8, 10, 11, 13, 15, 16, 17, 18, 20,',
    '        };',
    '        static const int kDHi[12] = {',
    '            2, 4, 7, 9, 10, 12, 14, 15, 16, 17, 19, 20,',
    '        };',
    '        for (int i = 0; i < 12; ++i)',
    '            if (rules::potDragonTypeLo(i) != kDLo[i] ||',
    '                rules::potDragonTypeHi(i) != kDHi[i]) ++bad;',
    '        for (int i = 1; i < 12; ++i)',
    '            if (rules::potDragonTypeLo(i) !=',
    '                rules::potDragonTypeHi(i - 1) + 1) ++bad;',
    '        if (rules::potDragonTypeLo(-5) != 1 ||',
    '            rules::potDragonTypeHi(99) != 20) ++bad;',
    '        // ESP / Extra-Healing',
    '        if (rules::potEspLo() != 5 ||',
    '            rules::potEspHi() != 40 ||',
    '            rules::potEspDice() != 5 ||',
    '            rules::potEspFaces() != 8 ||',
    '            rules::potXHealLo() != 6 ||',
    '            rules::potXHealHi() != 27 ||',
    '            rules::potXHealDice() != 3 ||',
    '            rules::potXHealFaces() != 8 ||',
    '            rules::potXHealBonus() != 3 ||',
    '            rules::potXHealThirdLo() != 1 ||',
    '            rules::potXHealThirdHi() != 8) ++bad;',
    '        printf("R249 potions prose part 1 pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'the potions/scrolls/rings explanation',
    'prose (upload ~9998-10561) and the',
    'misc magic item explanations',
    '(~10949+).',
]
gap_new = [
    'the potions/scrolls/rings explanation',
    'prose (upload ~9998-10561) and the',
    'misc magic item explanations',
    '(~10949+).',
    '',
    'R249 landed the III.A potions',
    'explanation prose pins, part 1 of 3',
    '(DMG pp.133-134, upload lines',
    '~9998-10062) - the sixth prose arc',
    'of the EXPLANATIONS section, the',
    'first after the III.D arc closed at',
    'R248. The TREASURE (POTIONS) etc.',
    'headings inside this seam are the',
    'book running page headers, not',
    'tables - the III.A/B/C tables were',
    'pinned by R122/R221-R224 long ago.',
    'rules/potionsprose.h (the grenade.h',
    'pattern, pot prefix - distinct from',
    'the R221 potion prefix - 56',
    'accessors, of which 5 are array',
    'walkers for the animal/dragon type',
    'sub-tables and the climbing armor',
    'table): the conventions (duration 4',
    'turns plus 1-4 more on d4; onset',
    '2-5 segments) and the first NINE',
    'potions - Animal Control (5-20',
    'rat-size, 3-12 man-size, 1-4',
    'half-ton-plus; save at intelligence',
    '5+; the 7-row d20 type sub-table',
    'tiling 1-20), Clairaudience (3", 2',
    'turns), Clairvoyance (3", 1 turn),',
    'Climbing (base 1% slip, 01 falls at',
    'the halfway d% check, 1 turn +',
    '5-20 rounds, +1% per 1,000 g.p.;',
    'armor rows studded leather 1, ring',
    'mail 2, scale mail 4, chainmail 7,',
    'banded/splinted 8, plate 10, magic',
    'armor 1), Delusion (90% tasters',
    'agree), Diminution (5% size, 50% on',
    'half dose, 6 turns + 2-5 d4+1),',
    'Dragon Control (charm within 6",',
    'save -2; the 12-row d20 type',
    'sub-table white 1-2 through good',
    '20, tiling 1-20; 5-20 5d4 rounds),',
    'ESP (5-40 5d8 rounds), and',
    'Extra-Healing (6-27 3d8+3 whole,',
    '1-8 per third). The nine potions',
    'are the engine kPotions rows 1-9,',
    'bands 01-26, fire resistance from',
    '27 (cross-checked against the R221',
    'potions.h pins in the audit). New',
    'R249 battery audit; census 168.',
    'Next: R250 - potions part 2 (Fire',
    'Resistance through Invisibility,',
    'upload ~10063-10128), R251 -',
    'potions part 3 (Invulnerability',
    'through Water Breathing, upload',
    '~10129-10189), then the scrolls',
    'explanations (upload ~10191-10280)',
    'and the rings explanations (upload',
    '~10282-10561), then the misc magic',
    'item explanations (~10949+).',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson; the marker MUST be contiguous in
# the header text - the R247 lesson)
marker = 'R249: the III.A potions explanation prose'
try:
    t = open(WD).read()
    if marker in t:
        already += 1
    else:
        print('R249 FAIL: rules/potionsprose.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(WD, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R249 audit', audit_old, audit_new),
    (GAP, 'the R249 log entry', gap_old, gap_new),
]:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    # the idempotence signal is the NEW text (the R233
    # lesson: append-style patches leave the old text
    # inside the new)
    if new_s in text:
        already += 1
        continue
    if text.count(old_s) == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    else:
        print('R249 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 168:
        print('R249 FAIL: census is not 168')
        sys.exit(1)
    if t.count('R249 potions prose part 1 pins audit') != 1:
        print('R249 FAIL: the R249 audit line must appear once')
        sys.exit(1)
    if t.count('rules/potionsprose.h') != 1:
        print('R249 FAIL: the potionsprose include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R249 landed the III.A potions') != 1:
        print('R249 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(WD).read()
    if 'namespace rules' not in h or h.count('inline int pot') != 56:
        print('R249 FAIL: the header shape is wrong')
        sys.exit(1)

print('R249 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R249 note: 4 patches; the III.A potions explanation prose part 1 -')
print('the conventions and the first nine potions; census 168.')
print('commit: R249: the III.A potions explanation prose part 1 pins pinned - DMG pp.133-134, the conventions and the first nine potions (census 168)')

