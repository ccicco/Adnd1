#!/usr/bin/env python3
# R290 splice: the III.E Special artifacts
# explanation prose part 11 pins -
# the Orb of Dragonkind globes 6
# through 8 (the Firedrake, the
# Elder Wyrm, the Eternal Grand
# Dragon), the notes, and the Orb
# of Might, part2 lines 1557-1624,
# the second half of the 19th and
# the 20th of the 29 artifact
# descriptions. Globe 6 charms any
# old dragon, intelligence and ego
# 14 each, powers 3,3,2,0,0,1
# (9); globe 7 any very old, 16
# and 16, powers 4,3,2,1,1,1 (12);
# globe 8 any ancient, 18 and 18,
# +8 saves, attacks and damage vs
# Tiamat or Bahamut, powers
# 4,3,2,1,2,1 (13). The notes: a
# strong evil component; a neutral
# or good possessor saves vs magic
# to resist charming; range 5
# inches, 1 full round, awake and
# aware; evil charms automatic,
# neutral saves at -4, good at -2;
# 50 percent wisdom when charmed;
# feeblemind 3 intelligence,
# insanity 50 percent; only an
# active and awake mind; sacrifice
# destruction. The Orb of Might:
# source the foregoing Crown of
# Might; 3 Orbs; ethos 01-06 evil,
# 07-14 good, 15-20 neutrality;
# another ethos touching saves vs
# magic or dies, 4-24 on success;
# Crown and/or Sceptre invokes a
# malevolent Table IV effect;
# platinum, gem-encrusted, 100000
# or more gold pieces; equal to a
# Gem of Brightness; powers
# 2,0,1,0,0,0 (3) per ethos over
# 3 columns; regalia powers under
# the Crown. No break absorbed -
# the round closes on the standard
# blank at 1624; no page seam
# claimed (no running heads
# between upload lines 1450 and
# 1797). 48 accessors: 44 scalars
# + 4 walkers. The audit
# cross-pins the R240 sale row: the
# Might band 48-63 at 100000, a
# fixed row.
# 3 patches, marker-based idempotence,
# assert after every patch. ZERO
# apostrophes and ZERO literal backslashes
# in the content below (the printf
# newline is built via BS = chr(92)).

import os
import re
import sys

HERE = os.path.abspath(os.path.dirname(sys.argv[0]))
ROOT = os.path.abspath(HERE + '/..')
NL = chr(10)
BS = chr(92)

applied = 0
already = 0

def rd(p):
    f = open(os.path.join(ROOT, p), encoding='utf-8')
    s = f.read()
    f.close()
    return s

def wr(p, s):
    f = open(os.path.join(ROOT, p), 'w', encoding='utf-8')
    f.write(s)
    f.close()


PINS = [
    'inline int sapOrbFiredrakeOldDragon() {',
    '    // the possessor charms any old dragon',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbFiredrakeIntelligence() {',
    '    // the intelligence of the Firedrake',
    '    return 14;',
    '}',
    '',
    'inline int sapOrbFiredrakeEgo() {',
    '    // the ego of the Firedrake',
    '    return 14;',
    '}',
    '',
    'inline int sapOrbFiredrakePowerTotal() {',
    '    // 3+3+2+0+0+1 - the total power count',
    '    return 9;',
    '}',
    '',
    'inline int sapOrbFiredrakePowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 3, 2, 0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapOrbElderWyrmVeryOldDragon() {',
    '    // the possessor charms any very old dragon',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbElderWyrmIntelligence() {',
    '    // the intelligence of the Elder Wyrm',
    '    return 16;',
    '}',
    '',
    'inline int sapOrbElderWyrmEgo() {',
    '    // the ego of the Elder Wyrm',
    '    return 16;',
    '}',
    '',
    'inline int sapOrbElderWyrmPowerTotal() {',
    '    // 4+3+2+1+1+1 - the total power count',
    '    return 12;',
    '}',
    '',
    'inline int sapOrbElderWyrmPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        4, 3, 2, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapOrbEternalAncientDragon() {',
    '    // the possessor charms any ancient dragon',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbEternalTiamatBahamutBonus() {',
    '    // saves, attacks and damage vs Tiamat or Bahamut',
    '    return 8;',
    '}',
    '',
    'inline int sapOrbEternalIntelligence() {',
    '    // the intelligence of the Eternal Grand Dragon',
    '    return 18;',
    '}',
    '',
    'inline int sapOrbEternalEgo() {',
    '    // the ego of the Eternal Grand Dragon',
    '    return 18;',
    '}',
    '',
    'inline int sapOrbEternalPowerTotal() {',
    '    // 4+3+2+1+2+1 - the total power count',
    '    return 13;',
    '}',
    '',
    'inline int sapOrbEternalPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        4, 3, 2, 1, 2, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapOrbNotesEvilComponent() {',
    '    // all of these Orbs have a strong evil component',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbNotesNeutralGoodResist() {',
    '    // a neutral or good character saves vs magic to resist',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbNotesCharmRangeInches() {',
    '    // the charm range, in inches',
    '    return 5;',
    '}',
    '',
    'inline int sapOrbNotesCharmRounds() {',
    '    // the charm requires this many full rounds',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbNotesAwakeAndAware() {',
    '    // the subject must be fully awake and aware',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbNotesEvilAutoCharmed() {',
    '    // only evil dragons are automatically charmed',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbNotesNeutralSavePenalty() {',
    '    // the neutral dragon save penalty, as a magnitude',
    '    return 4;',
    '}',
    '',
    'inline int sapOrbNotesGoodSavePenalty() {',
    '    // the good dragon save penalty, as a magnitude',
    '    return 2;',
    '}',
    '',
    'inline int sapOrbNotesCharmedWisdomPercent() {',
    '    // charmed characters keep this percent of wisdom',
    '    return 50;',
    '}',
    '',
    'inline int sapOrbNotesFeeblemindIntelligence() {',
    '    // feeblemind leaves this intelligence',
    '    return 3;',
    '}',
    '',
    'inline int sapOrbNotesInsanePercent() {',
    '    // insanity leaves this percent of normal',
    '    return 50;',
    '}',
    '',
    'inline int sapOrbNotesAwakeMindOnly() {',
    '    // the Orb controls only an active and awake mind',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbNotesSacrificeDestruction() {',
    '    // destruction by sacrifice to a dragon at hand',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbMightOrbCount() {',
    '    // the 3 Orbs of Might',
    '    return 3;',
    '}',
    '',
    'inline int sapOrbMightCrownSource() {',
    '    // the legendary source - the foregoing Crown of Might',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbMightEvilDieLo() {',
    '    // the evil ethos die band low edge',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbMightEvilDieHi() {',
    '    // the evil ethos die band high edge',
    '    return 6;',
    '}',
    '',
    'inline int sapOrbMightGoodDieLo() {',
    '    // the good ethos die band low edge',
    '    return 7;',
    '}',
    '',
    'inline int sapOrbMightGoodDieHi() {',
    '    // the good ethos die band high edge',
    '    return 14;',
    '}',
    '',
    'inline int sapOrbMightNeutralDieLo() {',
    '    // the neutrality ethos die band low edge',
    '    return 15;',
    '}',
    '',
    'inline int sapOrbMightNeutralDieHi() {',
    '    // the neutrality ethos die band high edge',
    '    return 20;',
    '}',
    '',
    'inline int sapOrbMightTouchDeathSave() {',
    '    // another ethos touching one saves vs magic or dies',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbMightTouchDamageLo() {',
    '    // the damage on a successful save, low edge',
    '    return 4;',
    '}',
    '',
    'inline int sapOrbMightTouchDamageHi() {',
    '    // the damage on a successful save, high edge',
    '    return 24;',
    '}',
    '',
    'inline int sapOrbMightRegaliaTableFour() {',
    '    // with Crown and/or Sceptre, a Table IV malevolence',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbMightPlatinumGems() {',
    '    // platinum, gem-encrusted, precious device atop',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbMightValueGp() {',
    '    // the open market worth, in gold pieces',
    '    return 100000;',
    '}',
    '',
    'inline int sapOrbMightGemOfBrightness() {',
    '    // each Orb equals a Gem of Brightness',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbMightPowerEthosCount() {',
    '    // the power table ethos columns - evil, good, neutrality',
    '    return 3;',
    '}',
    '',
    'inline int sapOrbMightPowerTotal() {',
    '    // 2+0+1+0+0+0 - the total power count per ethos',
    '    return 3;',
    '}',
    '',
    'inline int sapOrbMightPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        2, 0, 1, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapOrbMightRegaliaPowers() {',
    '    // additional regalia powers - see the Crown of Might',
    '    return 1;',
    '}',
    '',
]

AUDIT = [
    '    // ---- R290: the III.E Special artifacts',
    '    // explanation prose part 11 ----',
    '    // The Orb of Dragonkind globes 6-8, the',
    '    // notes and the Orb of Might, part2 lines',
    '    // 1557-1624. No break absorbed - the',
    '    // round closes on the standard blank at',
    '    // 1624; no page seam claimed (no running',
    '    // heads between lines 1450 and 1797).',
    '    {',
    '        int bad = 0;',
    '        // the Firedrake scalars and powers',
    '        if (rules::sapOrbFiredrakeOldDragon() != 1 ||',
    '            rules::sapOrbFiredrakeIntelligence() != 14 ||',
    '            rules::sapOrbFiredrakeEgo() != 14 ||',
    '            rules::sapOrbFiredrakePowerTotal() != 9) ++bad;',
    '        static const int kO6[6] = {',
    '            3, 3, 2, 0, 0, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrbFiredrakePowerCount(i) != kO6[i]) ++bad;',
    '        if (rules::sapOrbFiredrakePowerCount(0) +',
    '            rules::sapOrbFiredrakePowerCount(1) +',
    '            rules::sapOrbFiredrakePowerCount(2) +',
    '            rules::sapOrbFiredrakePowerCount(3) +',
    '            rules::sapOrbFiredrakePowerCount(4) +',
    '            rules::sapOrbFiredrakePowerCount(5) !=',
    '            rules::sapOrbFiredrakePowerTotal()) ++bad;',
    '        // the Elder Wyrm scalars and powers',
    '        if (rules::sapOrbElderWyrmVeryOldDragon() != 1 ||',
    '            rules::sapOrbElderWyrmIntelligence() != 16 ||',
    '            rules::sapOrbElderWyrmEgo() != 16 ||',
    '            rules::sapOrbElderWyrmPowerTotal() != 12) ++bad;',
    '        static const int kO7[6] = {',
    '            4, 3, 2, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrbElderWyrmPowerCount(i) != kO7[i]) ++bad;',
    '        if (rules::sapOrbElderWyrmPowerCount(0) +',
    '            rules::sapOrbElderWyrmPowerCount(1) +',
    '            rules::sapOrbElderWyrmPowerCount(2) +',
    '            rules::sapOrbElderWyrmPowerCount(3) +',
    '            rules::sapOrbElderWyrmPowerCount(4) +',
    '            rules::sapOrbElderWyrmPowerCount(5) !=',
    '            rules::sapOrbElderWyrmPowerTotal()) ++bad;',
    '        // the Eternal Grand Dragon scalars and powers',
    '        if (rules::sapOrbEternalAncientDragon() != 1 ||',
    '            rules::sapOrbEternalTiamatBahamutBonus() != 8 ||',
    '            rules::sapOrbEternalIntelligence() != 18 ||',
    '            rules::sapOrbEternalEgo() != 18 ||',
    '            rules::sapOrbEternalPowerTotal() != 13) ++bad;',
    '        static const int kO8[6] = {',
    '            4, 3, 2, 1, 2, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrbEternalPowerCount(i) != kO8[i]) ++bad;',
    '        if (rules::sapOrbEternalPowerCount(0) +',
    '            rules::sapOrbEternalPowerCount(1) +',
    '            rules::sapOrbEternalPowerCount(2) +',
    '            rules::sapOrbEternalPowerCount(3) +',
    '            rules::sapOrbEternalPowerCount(4) +',
    '            rules::sapOrbEternalPowerCount(5) !=',
    '            rules::sapOrbEternalPowerTotal()) ++bad;',
    '        // the notes scalars',
    '        if (rules::sapOrbNotesEvilComponent() != 1 ||',
    '            rules::sapOrbNotesNeutralGoodResist() != 1 ||',
    '            rules::sapOrbNotesCharmRangeInches() != 5 ||',
    '            rules::sapOrbNotesCharmRounds() != 1 ||',
    '            rules::sapOrbNotesAwakeAndAware() != 1 ||',
    '            rules::sapOrbNotesEvilAutoCharmed() != 1 ||',
    '            rules::sapOrbNotesNeutralSavePenalty() != 4 ||',
    '            rules::sapOrbNotesGoodSavePenalty() != 2 ||',
    '            rules::sapOrbNotesCharmedWisdomPercent() != 50 ||',
    '            rules::sapOrbNotesFeeblemindIntelligence() != 3 ||',
    '            rules::sapOrbNotesInsanePercent() != 50 ||',
    '            rules::sapOrbNotesAwakeMindOnly() != 1 ||',
    '            rules::sapOrbNotesSacrificeDestruction() != 1) ++bad;',
    '        // the Orb of Might scalars',
    '        if (rules::sapOrbMightOrbCount() != 3 ||',
    '            rules::sapOrbMightCrownSource() != 1 ||',
    '            rules::sapOrbMightEvilDieLo() != 1 ||',
    '            rules::sapOrbMightEvilDieHi() != 6 ||',
    '            rules::sapOrbMightGoodDieLo() != 7 ||',
    '            rules::sapOrbMightGoodDieHi() != 14 ||',
    '            rules::sapOrbMightNeutralDieLo() != 15 ||',
    '            rules::sapOrbMightNeutralDieHi() != 20 ||',
    '            rules::sapOrbMightTouchDeathSave() != 1 ||',
    '            rules::sapOrbMightTouchDamageLo() != 4 ||',
    '            rules::sapOrbMightTouchDamageHi() != 24 ||',
    '            rules::sapOrbMightRegaliaTableFour() != 1 ||',
    '            rules::sapOrbMightPlatinumGems() != 1 ||',
    '            rules::sapOrbMightValueGp() != 100000 ||',
    '            rules::sapOrbMightGemOfBrightness() != 1 ||',
    '            rules::sapOrbMightPowerEthosCount() != 3 ||',
    '            rules::sapOrbMightRegaliaPowers() != 1) ++bad;',
    '        static const int kOM[6] = {',
    '            2, 0, 1, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrbMightPowerCount(i) != kOM[i]) ++bad;',
    '        if (rules::sapOrbMightPowerCount(0) +',
    '            rules::sapOrbMightPowerCount(1) +',
    '            rules::sapOrbMightPowerCount(2) +',
    '            rules::sapOrbMightPowerCount(3) +',
    '            rules::sapOrbMightPowerCount(4) +',
    '            rules::sapOrbMightPowerCount(5) !=',
    '            rules::sapOrbMightPowerTotal()) ++bad;',
    '        // the within-round intelligence ladder rises by two',
    '        if (rules::sapOrbElderWyrmIntelligence() !=',
    '            rules::sapOrbFiredrakeIntelligence() + 2) ++bad;',
    '        if (rules::sapOrbEternalIntelligence() !=',
    '            rules::sapOrbElderWyrmIntelligence() + 2) ++bad;',
    '        // the ethos die bands partition 1 through 20',
    '        if (rules::sapOrbMightGoodDieLo() !=',
    '            rules::sapOrbMightEvilDieHi() + 1) ++bad;',
    '        if (rules::sapOrbMightNeutralDieLo() !=',
    '            rules::sapOrbMightGoodDieHi() + 1) ++bad;',
    '        // the cross-pin: the R240 sale table row',
    '        // (a fixed row, unlike the Dragonkind band)',
    '        if (rules::saRowLo(19) != 48 ||',
    '            rules::saRowHi(19) != 63 ||',
    '            rules::saSaleGp(19) != 100000 ||',
    '            rules::saSaleGpHi(19) != 0) ++bad;',
    '        printf("R290 special artifacts prose part 11 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R290 landed the III.E Special',
    'artifacts explanation prose',
    'part 11 (part2 lines 1557-1624;',
    'global = 11065 + part2 line),',
    'the Orb of Dragonkind globes 6',
    'through 8, the notes and the',
    'Orb of Might - the second half',
    'of the 19th and the 20th of',
    'the 29 artifact descriptions.',
    'Globe 6, the Firedrake: charms',
    'any old dragon, intelligence',
    '14, ego 14; powers 3,3,2,0,0,1',
    'total 9. Globe 7, the Elder',
    'Wyrm: very old dragons, 16 and',
    '16; powers 4,3,2,1,1,1 total',
    '12. Globe 8, the Eternal Grand',
    'Dragon: ancient dragons, 18 and',
    '18, +8 saves, attacks and',
    'damage vs Tiamat or Bahamut;',
    'powers 4,3,2,1,2,1 total 13.',
    'The intelligence ladder rises',
    'by two, 14 through 18. The',
    'notes: all of these Orbs have',
    'a strong component of evil; a',
    'neutral or good character saves',
    'versus magic to resist',
    'charming a neutral or good',
    'dragon; charm range 5 inches,',
    '1 full round, the subject',
    'fully awake and aware; only',
    'evil dragons charm',
    'automatically, neutral dragons',
    'save at -4, good dragons -2;',
    'charmed characters keep 50',
    'percent of normal wisdom;',
    'feeblemind leaves 3',
    'intelligence, insanity 50',
    'percent; the Orb controls only',
    'an active and awake mind;',
    'destruction typically by',
    'sacrifice to a dragon at hand,',
    'else the most sure and',
    'expeditious method. The Orb of',
    'Might: the legendary source is',
    'the foregoing Crown of Might; 3',
    'Orbs; the ethos bands 01-06',
    'evil, 07-14 good, 15-20',
    'neutrality; another ethos',
    'touching one saves versus magic',
    'or dies, 4-24 hit points on a',
    'successful save; with a Crown',
    'and/or Sceptre the survivor',
    'invokes a malevolent Table IV',
    'effect; platinum, gem-encrusted,',
    'worth 100000 or more gold',
    'pieces; equal to a Gem of',
    'Brightness; powers 2,0,1,0,0,0',
    'total 3 per ethos over 3',
    'columns; further regalia powers',
    'under the Crown of Might.',
    'No break absorbed - the round',
    'closes on the standard blank at',
    '1624; no page seam claimed',
    '(no running heads between',
    'lines 1450 and 1797). The',
    'upload quirks: the globe heads',
    'print Orb of the Firedrake,',
    'Orb of the Elder Wyrm and Orb',
    'of the Eternal Grand Dragon',
    'with the, while the Orb of',
    'Might head drops it; 18 power',
    'lines print N x table with the',
    'true multiplication sign; the',
    'charm range mark prints as the',
    'curly right double quote; the',
    'neutral and good save',
    'modifiers print with the true',
    'minus sign; the Might power',
    'table prints its good and',
    'neutrality table III slots as',
    'backslash continuation rows -',
    'all pinned as plain digits and',
    'words, apostrophe-free and',
    'backslash-free here. 48',
    'accessors: 44 scalars + 4',
    'walkers (the firedrake walker',
    '3,3,2,0,0,1, the elder wyrm',
    'walker 4,3,2,1,1,1, the eternal',
    'walker 4,3,2,1,2,1, the might',
    'walker 2,0,1,0,0,0), no name',
    'collisions with the miscprose',
    'and specart headers; the audit',
    'cross-pins the R240 sale row -',
    'the Might band 48-63 at 100000,',
    'a fixed row, its zero high',
    'bound carried by saSaleGpHi',
    '(census 208). Next: R291',
    'III.E Special part 12 -',
    'Queen Ehlissas Marvelous',
    'Nightingale in part2 from',
    'line 1625 (global 12690; the',
    'Recorder of YeCind and the',
    'other descriptions follow; the',
    'III.E Special prose continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 48, 'accessor count is not 48'
assert len(set(defs)) == 48, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 44, 'scalar count is not 44'
walk = [d for d in defs if d not in scal]
assert len(walk) == 4, 'walker count is not 4'
assert set(walk) == {'sapOrbFiredrakePowerCount',
    'sapOrbElderWyrmPowerCount',
    'sapOrbEternalPowerCount',
    'sapOrbMightPowerCount',
    }, 'wrong walkers'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(sap[A-Za-z0-9]+)[(]', ATEXT))
assert audited == set(defs), 'audit does not probe every accessor'
for fn in sorted(os.listdir(os.path.join(ROOT, 'rules'))):
    if not fn.endswith('.h') or fn == 'specartprose2.h':
        continue
    pt = open(os.path.join(ROOT, 'rules', fn), encoding='utf-8').read()
    for n in defs:
        assert n not in pt, 'name collision with ' + fn
s0 = rd('rules/specartprose2.h')
assert 'sapOrbGreatSerpentPowerCount' in s0, 'specartprose2.h missing the R289 accessors'
assert 'sapServantLumSameMake' in s0, 'specartprose2.h missing the R288 accessors'
assert 'sapQuillMasterThiefBest' in s0, 'specartprose2.h missing the R287 accessors'
assert s0.count('}  // namespace rules') == 1, 'namespace close not unique'
for grp in (PINS, AUDIT, GAP):
    for el in grp:
        assert chr(39) not in el, 'apostrophe in content'
        probe = el.replace(chr(92) + 'n', '')
        assert chr(92) not in probe, 'backslash in content'
        assert NL not in el, 'list element spans lines'
for el in GAP:
    assert len(el) <= 34, 'gap line too long: ' + el
assert ATEXT.count('{') == ATEXT.count('}'), 'audit braces unbalanced'
assert ATEXT.count('(') == ATEXT.count(')'), 'audit parens unbalanced'
assert AUDIT[-1] == '    }', 'audit block does not close'
assert PINS[-1] == '', 'pins block must end with a blank line'
assert PTEXT.count('{') == PTEXT.count('}'), 'pins braces unbalanced'
assert ATEXT.count('R290 special artifacts prose part 11 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 11', 'the Orb of Dragonkind', 'Orb of Might',
             '1557-1624', 'No break absorbed',
             'census 208', 'R291', 'line 1625', '12690',
             'saSaleGpHi'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 11', 'The Orb of Dragonkind', 'Orb of Might',
             '1557-1624', 'No break absorbed'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapOrbFiredrakeOldDragon() {'
if mark in s:
    already += 1
else:
    anchor = '}  // namespace rules'
    assert s.count(anchor) == 1, 'namespace anchor not unique'
    s = s.replace(anchor, PTEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 1 failed'
assert s.count('}  // namespace rules') == 1, 'patch 1 broke the close'
assert s.endswith('}  // namespace rules'), 'patch 1 broke the tail'
alldefs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', s)
assert len(alldefs) == 314, 'accessor count is not 314'
assert len(set(alldefs)) == 314, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R290: the III.E Special artifacts'
if mark in s:
    already += 1
else:
    anchor = '    // ---- R227: the wis mental save wiring audit ----'
    assert s.count(anchor) == 1, 'audit anchor not unique'
    s = s.replace(anchor, ATEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 2 failed'
assert s.count('R290 special artifacts prose part 11 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R290 landed the III.E Special'
if mark in s:
    already += 1
else:
    anchor = 'continue).' + NL + NL + 'Categories:'
    assert s.count(anchor) == 1, 'gap anchor not unique'
    s = s.replace(anchor, 'continue).' + NL + NL + NL.join(GAP) + NL + NL + 'Categories:', 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 3 failed'

print('R290 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R290 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 11 - the Orb of Dragonkind globes')
print('6-8, the notes and the Orb of Might,')
print('part2 lines 1557-1624; census 208.')
print('commit: R290: the III.E Special artifacts explanation prose part 11 pinned - the Orb of Dragonkind globes 6-8, the notes and the Orb of Might in part2 lines 1557-1624 (census 208)')

