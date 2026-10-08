#!/usr/bin/env python3
# R264 splice: the III.E misc magic explanation prose
# part 8 pins - Deck of Many Things, part2 lines
# 324-400 (DMG p.133-134) - the slice pinning kMisc2
# row 18 (73-76). ONE page header strips (360, the
# TREASURE page); ZERO mid-sentence seams (a first).
# 4 patches, marker-based idempotence, assert after
# every patch. ZERO apostrophes and ZERO literal
# backslashes in the content below (the printf
# newline is built via BS = chr(92)).

import os
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

# ---- patch 1: rules/miscprose8.h ----
HDR = [
    '// ====================================================================',
    '// Adnd1 - rules/miscprose8.h',
    '// R264: the III.E misc magic explanation prose part 8',
    '// (DMG p.133-134) - Deck of Many Things, part2',
    '// lines 324-400 (global = 11065 + part2 line). ONE',
    '// page header strips (360, the TREASURE page);',
    '// ZERO mid-sentence seams (a first). The 22-plaque',
    '// table pins: 9 asterisk plaques, 2 bold-face stop',
    '// plaques (The Void, Donjon), 2 discarded plaques',
    '// (Jester, Fool). 48 accessors: 45 scalars + 3',
    '// array walkers, no name collisions with',
    '// miscprose1.h through miscprose7.h. The slice',
    '// pins kMisc2 row 18 (Deck of Many Things, 73-76).',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int mmpDeckPlaqueMaterialCount() {',
    '    // plaques of ivory or vellum',
    '    return 2;',
    '}',
    '',
    'inline int mmpDeckMinDraws() {',
    '    // announce only 1 draw, or',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckMaxDraws() {',
    '    // opt for 2, 3, or even 4',
    '    return 4;',
    '}',
    '',
    'inline int mmpDeckJesterBonusDraws() {',
    '    // the jester: 2 additional cards',
    '    return 2;',
    '}',
    '',
    'inline int mmpDeckBasePlaqueCount() {',
    '    // the 13-plaque pack',
    '    return 13;',
    '}',
    '',
    'inline int mmpDeckFullPlaqueCount() {',
    '    // the 22-plaque pack',
    '    return 22;',
    '}',
    '',
    'inline int mmpDeckBaseChancePct() {',
    '    // 13 plaques at 75 percent',
    '    return 75;',
    '}',
    '',
    'inline int mmpDeckFullChancePct() {',
    '    // 22 plaques at 25 percent',
    '    return 25;',
    '}',
    '',
    'inline int mmpDeckAsteriskPlaqueCount() {',
    '    // the 22-pack extras, asterisk-marked',
    '    return 9;',
    '}',
    '',
    'inline int mmpDeckDiscardPlaqueCount() {',
    '    // jester and fool are discarded',
    '    return 2;',
    '}',
    '',
    'inline int mmpDeckBoldFaceStopCount() {',
    '    // The Void and Donjon stop the deck',
    '    return 2;',
    '}',
    '',
    'inline int mmpDeckTablePlaqueCount() {',
    '    // the printed plaque table rows',
    '    return 22;',
    '}',
    '',
    'inline int mmpDeckSunXp() {',
    '    // the Sun: beneficial item and',
    '    return 50000;',
    '}',
    '',
    'inline int mmpDeckMoonWishesMin() {',
    '    // Moon grants 1-4 wishes',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckMoonWishesMax() {',
    '    // Moon grants 1-4 wishes',
    '    return 4;',
    '}',
    '',
    'inline int mmpDeckMoonSpellLevel() {',
    '    // same as the ninth level spell',
    '    return 9;',
    '}',
    '',
    'inline int mmpDeckStarPoints() {',
    '    // Star: 2 points on the major ability',
    '    return 2;',
    '}',
    '',
    'inline int mmpDeckStarMaxScore() {',
    '    // if the 2 points would place the score at',
    '    return 19;',
    '}',
    '',
    'inline int mmpDeckStarFallbackOrderCount() {',
    '    // con, cha, wis, dex, int, str',
    '    return 6;',
    '}',
    '',
    'inline int mmpDeckCometMidpointProgress() {',
    '    // success: mid-point of the next level',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckThroneCharisma() {',
    '    // Throne: charisma of',
    '    return 18;',
    '}',
    '',
    'inline int mmpDeckThroneReactionBonusPct() {',
    '    // already-18: still +25 percent reactions',
    '    return 25;',
    '}',
    '',
    'inline int mmpDeckKeyMapBonusPct() {',
    '    // Key: treasure map at +20 percent',
    '    return 20;',
    '}',
    '',
    'inline int mmpDeckKeyWeaponCount() {',
    '    // Key: a treasure map plus',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckKnightLevel() {',
    '    // Knight: a 4th level fighter',
    '    return 4;',
    '}',
    '',
    'inline int mmpDeckKnightBonusPerDie() {',
    '    // the hero: +1 per die',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckKnightAbilityMax() {',
    '    // the hero ability roll caps at',
    '    return 18;',
    '}',
    '',
    'inline int mmpDeckGemJewelryCount() {',
    '    // Gem: your choice of 20 jewelry',
    '    return 20;',
    '}',
    '',
    'inline int mmpDeckGemGemCount() {',
    '    // Gem: or 50 gems',
    '    return 50;',
    '}',
    '',
    'inline int mmpDeckGemGemBaseGp() {',
    '    // the gems: base value',
    '    return 1000;',
    '}',
    '',
    'inline int mmpDeckGemXpLevelCap() {',
    '    // never more than 1 level rise',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckEuryaleSavePenalty() {',
    '    // Euryale: minus 3 on petrification saves',
    '    return 3;',
    '}',
    '',
    'inline int mmpDeckRogueHenchmenAlienated() {',
    '    // Rogue: 1 henchman alienated',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckJesterXp() {',
    '    // Jester: gain 10,000 xp instead',
    '    return 10000;',
    '}',
    '',
    'inline int mmpDeckJesterExtraDraws() {',
    '    // Jester: or 2 more draws',
    '    return 2;',
    '}',
    '',
    'inline int mmpDeckFoolXp() {',
    '    // Fool: lose 10,000 xp',
    '    return 10000;',
    '}',
    '',
    'inline int mmpDeckIdiotIntLossMin() {',
    '    // Idiot: lose 1-4 int',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckIdiotIntLossMax() {',
    '    // Idiot: lose 1-4 int',
    '    return 4;',
    '}',
    '',
    'inline int mmpDeckSkullDeathAc() {',
    '    // the minor Death AC (negative)',
    '    return -4;',
    '}',
    '',
    'inline int mmpDeckSkullDeathHp() {',
    '    // the minor Death hit points',
    '    return 33;',
    '}',
    '',
    'inline int mmpDeckSkullScytheDmgMin() {',
    '    // the scythe: 2-16 hit points',
    '    return 2;',
    '}',
    '',
    'inline int mmpDeckSkullScytheDmgMax() {',
    '    // the scythe: 2-16 hit points',
    '    return 16;',
    '}',
    '',
    'inline int mmpDeckSkullUndeadForSpells() {',
    '    // treat the Death as undead',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckFatesPartyEndures() {',
    '    // the party must still endure it',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckDonjonGearStripped() {',
    '    // Donjon: all gear and spells stripped',
    '    return 1;',
    '}',
    '',
    'inline int mmpDeckPlaqueAsterisk(int i) {',
    '    // the 22-pack extras by row; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 21) i = 21;',
    '    static const int t[22] = {',
    '        0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,',
    '        0, 0, 0, 1, 0, 1, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpDeckPlaqueBoldFace(int i) {',
    '    // The Void (8) and Donjon (21); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 21) i = 21;',
    '    static const int t[22] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpDeckPlaqueDiscarded(int i) {',
    '    // Jester (16) and Fool (17); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 21) i = 21;',
    '    static const int t[22] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    '} // namespace rules',
]
P1 = 'rules/miscprose8.h'
if os.path.exists(os.path.join(ROOT, P1)):
    already += 1
    assert rd(P1) == NL.join(HDR), P1 + ' exists but differs'
else:
    wr(P1, NL.join(HDR))
    applied += 1
    assert rd(P1) == NL.join(HDR), P1 + ' write mismatch'
assert rd(P1).count(
    'R264: the III.E misc magic explanation prose part 8') == 1

# ---- patch 2: the regtest include ----
INC_OLD = ('#include "rules/miscprose7.h"  // R263: the III.E misc'
           ' magic explanation prose part 7 pins')
INC_NEW = ('#include "rules/miscprose8.h"  // R264: the III.E misc'
           ' magic explanation prose part 8 pins')
RG = rd('regtest.cpp')
if INC_NEW in RG:
    already += 1
    assert RG.count(INC_NEW) == 1, 'include not unique'
else:
    assert RG.count(INC_OLD) == 1, 'R263 include anchor missing'
    RG = RG.replace(INC_OLD, INC_OLD + NL + INC_NEW)
    applied += 1
    assert RG.count(INC_NEW) == 1, 'include insert failed'
wr('regtest.cpp', RG)

# ---- patch 3: the R264 audit block ----
AUDIT = [
    '    // ---- R264: the III.E misc magic explanation',
    '    // prose part 8 ----',
    '    // Deck of Many Things, part2 lines 324-400 -',
    '    // the 22-plaque table and the per-plaque',
    '    // explanations, pinning the kMisc2 row 18.',
    '    {',
    '        int bad = 0;',
    '        if (rules::mmpDeckPlaqueMaterialCount() != 2 ||',
    '            rules::mmpDeckMinDraws() != 1 ||',
    '            rules::mmpDeckMaxDraws() != 4 ||',
    '            rules::mmpDeckJesterBonusDraws() != 2 ||',
    '            rules::mmpDeckBasePlaqueCount() != 13 ||',
    '            rules::mmpDeckFullPlaqueCount() != 22 ||',
    '            rules::mmpDeckBaseChancePct() != 75 ||',
    '            rules::mmpDeckFullChancePct() != 25 ||',
    '            rules::mmpDeckAsteriskPlaqueCount() != 9 ||',
    '            rules::mmpDeckDiscardPlaqueCount() != 2 ||',
    '            rules::mmpDeckBoldFaceStopCount() != 2 ||',
    '            rules::mmpDeckTablePlaqueCount() != 22) ++bad;',
    '        if (rules::mmpDeckSunXp() != 50000 ||',
    '            rules::mmpDeckMoonWishesMin() != 1 ||',
    '            rules::mmpDeckMoonWishesMax() != 4 ||',
    '            rules::mmpDeckMoonSpellLevel() != 9 ||',
    '            rules::mmpDeckStarPoints() != 2 ||',
    '            rules::mmpDeckStarMaxScore() != 19 ||',
    '            rules::mmpDeckStarFallbackOrderCount() != 6 ||',
    '            rules::mmpDeckCometMidpointProgress() != 1) ++bad;',
    '        if (rules::mmpDeckThroneCharisma() != 18 ||',
    '            rules::mmpDeckThroneReactionBonusPct() != 25 ||',
    '            rules::mmpDeckKeyMapBonusPct() != 20 ||',
    '            rules::mmpDeckKeyWeaponCount() != 1 ||',
    '            rules::mmpDeckKnightLevel() != 4 ||',
    '            rules::mmpDeckKnightBonusPerDie() != 1 ||',
    '            rules::mmpDeckKnightAbilityMax() != 18 ||',
    '            rules::mmpDeckGemJewelryCount() != 20 ||',
    '            rules::mmpDeckGemGemCount() != 50 ||',
    '            rules::mmpDeckGemGemBaseGp() != 1000 ||',
    '            rules::mmpDeckGemXpLevelCap() != 1) ++bad;',
    '        if (rules::mmpDeckEuryaleSavePenalty() != 3 ||',
    '            rules::mmpDeckRogueHenchmenAlienated() != 1 ||',
    '            rules::mmpDeckJesterXp() != 10000 ||',
    '            rules::mmpDeckJesterExtraDraws() != 2 ||',
    '            rules::mmpDeckFoolXp() != 10000 ||',
    '            rules::mmpDeckIdiotIntLossMin() != 1 ||',
    '            rules::mmpDeckIdiotIntLossMax() != 4) ++bad;',
    '        if (rules::mmpDeckSkullDeathAc() != -4 ||',
    '            rules::mmpDeckSkullDeathHp() != 33 ||',
    '            rules::mmpDeckSkullScytheDmgMin() != 2 ||',
    '            rules::mmpDeckSkullScytheDmgMax() != 16 ||',
    '            rules::mmpDeckSkullUndeadForSpells() != 1 ||',
    '            rules::mmpDeckFatesPartyEndures() != 1 ||',
    '            rules::mmpDeckDonjonGearStripped() != 1) ++bad;',
    '        static const int kAsterisk[22] = {',
    '            0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,',
    '            0, 0, 0, 1, 0, 1, 1, 1, 1, 1,',
    '        };',
    '        static const int kBoldFace[22] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '        };',
    '        static const int kDiscard[22] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 22; ++i)',
    '            if (rules::mmpDeckPlaqueAsterisk(i) !=',
    '                kAsterisk[i] ||',
    '                rules::mmpDeckPlaqueBoldFace(i) !=',
    '                kBoldFace[i] ||',
    '                rules::mmpDeckPlaqueDiscarded(i) !=',
    '                kDiscard[i]) ++bad;',
    '        if (rules::mmpDeckBasePlaqueCount() +',
    '            rules::mmpDeckAsteriskPlaqueCount() !=',
    '            rules::mmpDeckFullPlaqueCount()) ++bad;',
    '        // the kMisc2 row this slice pins: the Deck',
    '        // of Many Things, 73-76, no class marks',
    '        if (rules::m2RowLo(18) != 73 ||',
    '            rules::m2RowHi(18) != 76 ||',
    '            rules::m2UsableByCleric(18) ||',
    '            rules::m2UsableByMagicUser(18) ||',
    '            rules::m2IsPerPlusValued(18) ||',
    '            rules::m2HasFeatureAsterisk(18) ||',
    '            rules::m2IsTripleStar(18)) ++bad;',
    '        // the row 26 (M) positive control',
    '        if (!rules::m2UsableByMagicUser(26)) ++bad;',
    '        printf("R264 misc magic prose part 8 pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]
RG = rd('regtest.cpp')
ANCHOR = ('    // ---- R227: the wis mental save wiring audit ----')
AUDIT_STR = NL.join(AUDIT)
if ('printf("R264 misc magic prose part 8 pins audit:') in RG:
    already += 1
    assert RG.count(ANCHOR) == 1, 'R227 anchor not unique'
else:
    assert RG.count(ANCHOR) == 1, 'R227 anchor not unique'
    RG = RG.replace(ANCHOR, AUDIT_STR + NL + ANCHOR)
    applied += 1
    assert RG.count(
        'printf("R264 misc magic prose part 8 pins audit:') == 1, \
        'audit printf not unique'
wr('regtest.cpp', RG)

# ---- patch 4: the gap entry ----
GAP = [
    'R264 landed the III.E misc',
    'magic explanation prose part',
    '8 (part2 lines 324-400;',
    'global = 11065 + part2',
    'line), the Deck of Many',
    'Things - pinning the kMisc2',
    'row 18 (73-76). ONE page',
    'header inside the slice',
    'strips (the 360 TREASURE',
    'page); ZERO mid-sentence',
    'seams (a first). The deck:',
    '13 or 22 plaques at 75/25',
    'percent; draws announced',
    'beforehand (1, or 2, 3,',
    'even 4); the jester gives 2',
    'more draws; plaques replaced',
    'unless jester or fool;',
    'asterisk marks the 9 extras',
    'of the 22-pack; The Void',
    'and Donjon in bold face',
    'make the deck disappear.',
    'Per-plaque: Sun (item plus',
    '50000 xp), Moon (1-4',
    'wishes, ninth level spell,',
    'used in that many turns),',
    'Star (2 points, 19 cap, the',
    '6-ability fallback order),',
    'Comet (solo the next',
    'monster: mid-point of next',
    'level), Throne (charisma 18',
    'and a keep; already-18',
    'still +25 percent',
    'reactions), Key (map +20',
    'percent, 1 usable weapon),',
    'Knight (4th level fighter,',
    '+1 per die, 18 max), Gem',
    '(20 jewelry or 50 gems at',
    '1000 gp base, xp capped at',
    '1 level), The Void (soul',
    'trapped, wish fails),',
    'Flames (Greater devil,',
    'enmity until death), Skull',
    '(minor Death AC -4, 33 hp,',
    'scythe 2-16 never missing',
    'and first; helpers summon',
    'their own Deaths; undead',
    'for spells; ignores cold,',
    'fire, electrical), Talons',
    '(all magic items instantly',
    'gone), Ruin (all wealth and',
    'property lost forever),',
    'Euryale (minus 3 saves,',
    'Fates or gods only), Rogue',
    '(1 henchman forever',
    'hostile), Balance (change',
    'alignment or be judged),',
    'Jester (10000 xp or 2 draws,',
    'discarded), Fool (mandatory',
    'payment and draw, 10000 xp),',
    'Vizier (one full answer),',
    'Idiot (1-4 int lost, redraw',
    'optional), Fates (cancel',
    'one event, party endures),',
    'Donjon (imprisoned, gear',
    'and spells stripped). The',
    'battery caught an assistant',
    'index error pre-splice (the',
    'fifth M mark sits on engine',
    'row 26, Eyes of Charming,',
    'not 25) - the print was',
    'clean. New R264 battery',
    'audit; census 182. Next:',
    'part 9 - Drums of Deafening',
    'onward in part2 from line',
    '402 (global 11467; the two',
    'drums, the four dusts, the',
    'bottles and the eyes follow;',
    'rows 19+).',
]
GP = rd('tools/dmg_gap_report.md')
if GP.count('R264 landed the III.E misc') == 1:
    already += 1
else:
    TAIL = ('deck sits on kMisc2 row 18,' + NL + '73-76).' + NL +
            NL + 'Categories:')
    assert GP.count(TAIL) == 1, 'R263 gap tail anchor not unique'
    NEWTAIL = ('deck sits on kMisc2 row 18,' + NL + '73-76).' +
               NL + NL + NL.join(GAP) + NL + NL + 'Categories:')
    GP = GP.replace(TAIL, NEWTAIL)
    applied += 1
    assert GP.count('R264 landed the III.E misc') == 1, \
        'gap entry insert failed'
wr('tools/dmg_gap_report.md', GP)

# ---- report ----
assert applied + already == 4, 'patch count wrong'
print('R264 splice: ALL OK (applied %d, already %d)'
      % (applied, already))
print('R264 note: 4 patches; the III.E misc magic')
print('explanation prose part 8 - Deck of Many Things,')
print('part2 lines 324-400; census 182.')
COMMIT = ('R264: the III.E misc magic explanation prose part 8'
          ' pinned - Deck of Many Things in part2 lines 324-400'
          ' (census 182)')
print('commit: ' + COMMIT)

