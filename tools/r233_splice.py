#!/usr/bin/env python3
# R233 splice: the multi-class engine.
#
# The R185 combo table goes live: a character can now BE
# a multi-class combination. The dual-class runtime (the
# human class change) stays the next arc box.
#
# The engine seam in rules/multiclass.h (plain ints - the
# R230 evaluable-subset convention): the combo bit count,
# the ordered bit scan (the fighter bit first - the
# primary-class order), and the bit -> base-class /
# bit -> subclass maps (the illusionist rides the
# magic-user tables, the ranger the fighter tables, the
# assassin the thief tables).
#
# The creation seam: the CR_MULTI stage (the [M] key at
# class choice - the race printed combos, R185), the
# eligibility gates (every class of the combo passes its
# own class minimum on the ADJUSTED prime and Race
# Table I; the subclass bits their R180 minimums and
# player-eligibility; the half-elf multi-class cleric
# WIS 13 - vs the single-class 9), and the member
# factory (every class die rolls with its con
# adjustment, the quotient by the class count - the
# R185 rule; the kit rides the MOST RESTRICTIVE armor
# allowance and the all-allow shield gate - the
# JUDGMENT; the ranger, assassin and illusionist
# primaries ride their R231 subclass ladders).
#
# The member rides the PRIMARY class - the first set
# bit (the fighter bit when the combo carries it - the
# JUDGMENT; every printed combo rides a base-class
# primary); the requisites average (PHB p.20), the
# combo earns no single-class bonus, promotions queue
# on the primary ladder and roll every UNSTALLED class
# die (multiclassHitDieStalled - a class at its name
# cap contributes none), reading the quotient.
#
# The v1-compatible multi save line; the R233 battery
# audit (an engine audit - the R174/R232 convention;
# the C++ battery is the gate).
#
# commit: R233: the multi-class engine - the R185 combos playable, the primary-class convention, the quotient hit dice (census 150)

import sys

MC   = 'rules/multiclass.h'
PAR  = 'game/party.h'
APP  = 'game/appstate.h'
AD   = 'adnd1.cpp'
CORE = 'game/state_core.cpp'
REG  = 'regtest.cpp'
GAP  = 'tools/phb_gap_report.md'

NL = chr(10)
Q  = chr(39)
BS = chr(92)

# ---- pre-assert: the gap report carries the census line once
g = open(GAP).read()
if g.count('Census 148.') != 1:
    print('R233 FAIL: gap report Census 148. count != 1')
    sys.exit(1)

# ---- 0: the MC constants become a named enum (R233) so
# the audit_eval seam can read the same constants (the
# R230 evaluable-subset convention - static const ints
# are invisible to the enum scanner) ----
mc_enum_old = [
    'static const int MC_FIGHTER = 1;',
    'static const int MC_MAGIC_USER = 2;',
    'static const int MC_CLERIC = 4;',
    'static const int MC_THIEF = 8;',
    'static const int MC_ILLUSIONIST = 16;',
    'static const int MC_RANGER = 32;',
    'static const int MC_ASSASSIN = 64;',
]
mc_enum_new = [
    '// R233: a named enum (was static const ints) so',
    '// the audit_eval seam reads the same constants.',
    'enum McBits {',
    '    MC_FIGHTER = 1,',
    '    MC_MAGIC_USER = 2,',
    '    MC_CLERIC = 4,',
    '    MC_THIEF = 8,',
    '    MC_ILLUSIONIST = 16,',
    '    MC_RANGER = 32,',
    '    MC_ASSASSIN = 64,',
    '};',
]

# ---- 1: the multiclass.h engine seam ----
mc_old = [
    '// (Recorded as comments: engine rounds',
    '// consume these mechanics.)',
    '',
    '} // namespace rules',
]
mc_new = [
    '// (Recorded as comments: engine rounds',
    '// consume these mechanics.)',
    '',
    '// ---- the R233 engine seam (plain ints, pure',
    '// expressions - the R230 evaluable-subset',
    '// convention: no while, no mutation, no bitwise',
    '// ops; the modulo ladder reads each bit) ----',
    '',
    '// The combo class count (the set-bit count).',
    'inline int multiClassCount(int mask) {',
    '    return (mask % 2 == 1 ? 1 : 0)',
    '         + (mask % 4 >= 2 ? 1 : 0)',
    '         + (mask % 8 >= 4 ? 1 : 0)',
    '         + (mask % 16 >= 8 ? 1 : 0)',
    '         + (mask % 32 >= 16 ? 1 : 0)',
    '         + (mask % 64 >= 32 ? 1 : 0)',
    '         + (mask % 128 >= 64 ? 1 : 0);',
    '}',
    '',
    '// The i-th set bit of the mask, low to high (the',
    '// fighter bit first - the primary-class order).',
    '// The below-counts c1..c6 say how many set bits',
    '// sit below each bit; a bit fires as the i-th',
    '// when its below-count equals i.',
    'inline int multiClassBitAt(int mask, int i) {',
    '    int c1 = mask % 2;',
    '    int c2 = c1 + (mask % 4 >= 2 ? 1 : 0);',
    '    int c3 = c2 + (mask % 8 >= 4 ? 1 : 0);',
    '    int c4 = c3 + (mask % 16 >= 8 ? 1 : 0);',
    '    int c5 = c4 + (mask % 32 >= 16 ? 1 : 0);',
    '    int c6 = c5 + (mask % 64 >= 32 ? 1 : 0);',
    '    return (mask % 2 == 1 && i == 0 ? 1 : 0)',
    '         + (mask % 4 >= 2 && i == c1 ? 2 : 0)',
    '         + (mask % 8 >= 4 && i == c2 ? 4 : 0)',
    '         + (mask % 16 >= 8 && i == c3 ? 8 : 0)',
    '         + (mask % 32 >= 16 && i == c4 ? 16 : 0)',
    '         + (mask % 64 >= 32 && i == c5 ? 32 : 0)',
    '         + (mask % 128 >= 64 && i == c6 ? 64 : 0);',
    '}',
    '',
    '// The runtime base class (CLASS_*) of a bit: the',
    '// illusionist rides the magic-user tables, the',
    '// ranger the fighter tables, the assassin the',
    '// thief tables (the R230 runtime-base convention).',
    'inline int multiClassBaseOfBit(int bit) {',
    '    return bit == MC_MAGIC_USER ? 1',
    '         : bit == MC_CLERIC ? 2',
    '         : bit == MC_THIEF ? 3',
    '         : bit == MC_ILLUSIONIST ? 1',
    '         : bit == MC_ASSASSIN ? 3',
    '         : 0;',
    '}',
    '',
    '// The registry subclass of a bit (-1 = a plain',
    '// base class; plain ints - the SUB_* values in the',
    '// subclasses.h order).',
    'inline int multiClassSubOfBit(int bit) {',
    '    return bit == MC_ILLUSIONIST ? 3',
    '         : bit == MC_RANGER ? 1',
    '         : bit == MC_ASSASSIN ? 4',
    '         : -1;',
    '}',
    '',
    '} // namespace rules',
]

# ---- 2: party.h include ----
inc_old = [
    '#include "../rules/subclassgates.h"  // R231: the subclass leveling seam',
]
inc_new = [
    '#include "../rules/subclassgates.h"  // R231: the subclass leveling seam',
    '#include "../rules/multiclass.h"  // R233: the multi-class engine',
]

# ---- 3: the Character field ----
field_old = [
    '    // R232: the lay-on-hands career day (-1 = never used;',
    '    // once per career day - the rest/camp day boundary)',
    '    int  layHandsDay = -1;',
]
field_new = [
    '    // R232: the lay-on-hands career day (-1 = never used;',
    '    // once per career day - the rest/camp day boundary)',
    '    int  layHandsDay = -1;',
    '    // R233: the multi-class combo (0 = single-classed;',
    '    // else the R185 combo mask; the member rides the',
    '    // primary class - the first set bit)',
    '    int  multiMask = 0;',
]

# ---- 4: toActor the primary convention ----
toa_old = [
    '        a.classIndex  = classIndex;',
    '        a.subclass    = subclass;   // R232: the specials hooks',
]
toa_new = [
    '        a.classIndex  = classIndex;',
    '        a.subclass    = subclass;   // R232: the specials hooks',
    '        // R233: a multi-class member rides the primary',
    '        // class - the FIRST set bit (the fighter bit',
    '        // when the combo carries it - the best melee',
    '        // class on the swing - the JUDGMENT)',
    '        if (multiMask != 0) {',
    '            int b = rules::multiClassBitAt(multiMask, 0);',
    '            a.classIndex = rules::multiClassBaseOfBit(b);',
    '            a.subclass   = rules::multiClassSubOfBit(b);',
    '        }',
]

# ---- 5: gainXp the averaged requisites ----
prime_old = [
    '            int primeAb = c.abilities.get(',
    '                (rules::Ability)rules::primeRequisite(',
    '                    c.classIndex));',
    '            int pct = rules::primeRequisitePct(',
    '                (uint8_t)primeAb);',
    '            int gained = amount + (amount * pct) / 100;',
]
prime_new = [
    '            int primeAb = c.abilities.get(',
    '                (rules::Ability)rules::primeRequisite(',
    '                    c.classIndex));',
    '            int pct = rules::primeRequisitePct(',
    '                (uint8_t)primeAb);',
    '            // R233: the multi-class requisites average',
    '            // (PHB p.20) - each class of the combo',
    '            // contributes its prime requisite',
    '            if (c.multiMask != 0) {',
    '                int n = rules::multiClassCount(c.multiMask);',
    '                int sum = 0;',
    '                for (int i = 0; i < n; ++i) {',
    '                    int b = rules::multiClassBitAt(',
    '                        c.multiMask, i);',
    '                    sum += c.abilities.get(',
    '                        (rules::Ability)rules::primeRequisite(',
    '                            rules::multiClassBaseOfBit(b)));',
    '                }',
    '                primeAb = sum / n;',
    '                pct = rules::primeRequisitePct(',
    '                    (uint8_t)primeAb);',
    '            }',
    '            int gained = amount + (amount * pct) / 100;',
]

# ---- 6: gainXp no single-class bonus for a combo ----
bonus_old = [
    '            if (c.subclass >= 0 &&',
    '                rules::subclassXpBonusEarned(c.subclass,',
    '                                             c.abilities))',
    '                gained += amount / 10;',
]
bonus_new = [
    '            // R233: the multi-class combo earns no',
    '            // single-class bonus (the JUDGMENT)',
    '            if (c.multiMask == 0 && c.subclass >= 0 &&',
    '                rules::subclassXpBonusEarned(c.subclass,',
    '                                             c.abilities))',
    '                gained += amount / 10;',
]

# ---- 7: gainXp the queue ladder ----
gxq_old = [
    '            // R231: the subclass ladder - the registry XP',
    '            // table and the effective level cap (Table II',
    '            // with the footnote-8 gnome conditional); plain',
    '            // members read the base-class table',
    '            int cap = rules::CLASS_LEVEL_CAP[c.classIndex];',
    '            int need = rules::xpForLevel(c.classIndex,',
    '                                        c.level + 1);',
    '            if (c.subclass >= 0) {',
    '                cap = rules::subclassLevelCapTotal(',
    '                    c.subclass, (rules::CharRace)c.race,',
    '                    c.abilities.int_, c.abilities.dex);',
    '                need = rules::subclassXpToAttain(c.subclass,',
    '                                                c.level + 1);',
    '            }',
]
gxq_new = [
    '            // R231: the subclass ladder - the registry XP',
    '            // table and the effective level cap (Table II',
    '            // with the footnote-8 gnome conditional); plain',
    '            // members read the base-class table',
    '            // R233: a multi-class member queues on the',
    '            // primary class ladder (the first set bit)',
    '            int cap = rules::CLASS_LEVEL_CAP[c.classIndex];',
    '            int need = rules::xpForLevel(c.classIndex,',
    '                                        c.level + 1);',
    '            if (c.multiMask != 0) {',
    '                int mb = rules::multiClassBitAt(',
    '                    c.multiMask, 0);',
    '                int msub = rules::multiClassSubOfBit(mb);',
    '                if (msub >= 0) {',
    '                    cap = rules::subclassLevelCapTotal(',
    '                        msub, (rules::CharRace)c.race,',
    '                        c.abilities.int_, c.abilities.dex);',
    '                    need = rules::subclassXpToAttain(',
    '                        msub, c.level + 1);',
    '                } else {',
    '                    cap = rules::CLASS_LEVEL_CAP[',
    '                        rules::multiClassBaseOfBit(mb)];',
    '                    need = rules::xpForLevel(',
    '                        rules::multiClassBaseOfBit(mb),',
    '                        c.level + 1);',
    '                }',
    '            } else if (c.subclass >= 0) {',
    '                cap = rules::subclassLevelCapTotal(',
    '                    c.subclass, (rules::CharRace)c.race,',
    '                    c.abilities.int_, c.abilities.dex);',
    '                need = rules::subclassXpToAttain(c.subclass,',
    '                                                c.level + 1);',
    '            }',
]

# ---- 8: trainNext the stale-check ladder ----
tnq_old = [
    '            // R231: the subclass stale check reads the',
    '            // registry ladder',
    '            int cap = rules::CLASS_LEVEL_CAP[c.classIndex];',
    '            int need = rules::xpForLevel(c.classIndex,',
    '                                        c.level + 1);',
    '            if (c.subclass >= 0) {',
    '                cap = rules::subclassLevelCapTotal(',
    '                    c.subclass, (rules::CharRace)c.race,',
    '                    c.abilities.int_, c.abilities.dex);',
    '                need = rules::subclassXpToAttain(c.subclass,',
    '                                                c.level + 1);',
    '            }',
]
tnq_new = [
    '            // R231: the subclass stale check reads the',
    '            // registry ladder',
    '            // R233: a multi-class member promotes on the',
    '            // primary class ladder (the first set bit)',
    '            int cap = rules::CLASS_LEVEL_CAP[c.classIndex];',
    '            int need = rules::xpForLevel(c.classIndex,',
    '                                        c.level + 1);',
    '            if (c.multiMask != 0) {',
    '                int mb = rules::multiClassBitAt(',
    '                    c.multiMask, 0);',
    '                int msub = rules::multiClassSubOfBit(mb);',
    '                if (msub >= 0) {',
    '                    cap = rules::subclassLevelCapTotal(',
    '                        msub, (rules::CharRace)c.race,',
    '                        c.abilities.int_, c.abilities.dex);',
    '                    need = rules::subclassXpToAttain(',
    '                        msub, c.level + 1);',
    '                } else {',
    '                    cap = rules::CLASS_LEVEL_CAP[',
    '                        rules::multiClassBaseOfBit(mb)];',
    '                    need = rules::xpForLevel(',
    '                        rules::multiClassBaseOfBit(mb),',
    '                        c.level + 1);',
    '                }',
    '            } else if (c.subclass >= 0) {',
    '                cap = rules::subclassLevelCapTotal(',
    '                    c.subclass, (rules::CharRace)c.race,',
    '                    c.abilities.int_, c.abilities.dex);',
    '                need = rules::subclassXpToAttain(c.subclass,',
    '                                                c.level + 1);',
    '            }',
]

# ---- 9: trainNext the multi-class promotion dice ----
die_old = [
    '            int conAdj;',
    '            int die;',
    '            if (c.subclass >= 0) {',
]
die_new = [
    '            int conAdj;',
    '            int die;',
    '            if (c.multiMask != 0) {',
    '                // R233: the multi-class promotion - every',
    '                // UNSTALLED class rolls its die (each with',
    '                // its con adjustment, the per-die floor 1),',
    '                // the quotient by the class count (the',
    '                // R185 rule); a class stalled at its name',
    '                // cap contributes no die',
    '                // (multiclassHitDieStalled - the R185 pin)',
    '                int n = rules::multiClassCount(c.multiMask);',
    '                int sum = 0;',
    '                for (int i = 0; i < n; ++i) {',
    '                    int b = rules::multiClassBitAt(',
    '                        c.multiMask, i);',
    '                    int base = rules::multiClassBaseOfBit(b);',
    '                    int sub = rules::multiClassSubOfBit(b);',
    '                    int conCls = sub >= 0',
    '                        ? rules::subclassConClass(sub) : base;',
    '                    int cAdj = rules::conHPAdjustment(',
    '                        conCls, c.abilities.con);',
    '                    int stop = sub >= 0',
    '                        ? rules::subclassLevelStop(sub)',
    '                        : rules::CLASS_LEVEL_CAP[base];',
    '                    if (rules::multiclassHitDieStalled(',
    '                            c.level, stop))',
    '                        continue;',
    '                    int d;',
    '                    if (sub >= 0 && c.level >',
    '                            rules::subclassFixedHpLevel(sub))',
    '                        d = rules::subclassHpBeyondFixed(sub)',
    '                            + cAdj;',
    '                    else if (sub >= 0)',
    '                        d = (int)dice.roll(1, (uint32_t)',
    '                            rules::subclassHitDie(sub), 0)',
    '                            + cAdj;',
    '                    else',
    '                        d = (int)dice.roll(1, (uint32_t)',
    '                            rules::CLASS_HIT_DIE[base], 0)',
    '                            + cAdj;',
    '                    if (d < 1) d = 1;',
    '                    sum += d;',
    '                }',
    '                die = rules::multiclassHpQuotient(sum, n);',
    '                if (die < 1) die = 1;',
    '            } else if (c.subclass >= 0) {',
]

# ---- 10: the CR_MULTI stage ----
enum_old = [
    '    CR_SUBCLASS,   // R230: the subclass offer stage',
    '    CR_NAME,',
    '};',
]
enum_new = [
    '    CR_SUBCLASS,   // R230: the subclass offer stage',
    '    CR_MULTI,   // R233: the multi-class offer stage',
    '    CR_NAME,',
    '};',
]

# ---- 11: the CreationState field ----
crf_old = [
    '    CreationStage stage = CR_ROLL;',
    '',
    '    rules::Rng  creationRng{1};',
]
crf_new = [
    '    CreationStage stage = CR_ROLL;',
    '',
    '    // R233: the multi-class combo pick (0 = the',
    '    // single-class path; else the R185 combo mask)',
    '    int multiMask = 0;',
    '',
    '    rules::Rng  creationRng{1};',
]

# ---- 12: the multi-class creation helpers ----
helpers_old = [
    '        if (sub == rules::SUB_MONK) {',
    '            c.weapon.id = items::WPN_QUARTERSTAFF;',
    '            c.armor.id = items::ARMOR_NONE_EQUIPPED;',
    '            c.shield = false;',
    '        }',
    '        return c;',
    '    }',
]
helpers_new = [
    '        if (sub == rules::SUB_MONK) {',
    '            c.weapon.id = items::WPN_QUARTERSTAFF;',
    '            c.armor.id = items::ARMOR_NONE_EQUIPPED;',
    '            c.shield = false;',
    '        }',
    '        return c;',
    '    }',
    '',
    '    // R233: the multi-class offer - the race printed',
    '    // combos (the R185 table)',
    '    int multiOfferCount() const {',
    '        return rules::multiClassComboCount(racePick);',
    '    }',
    '',
    '    int multiOfferAt(int row) const {',
    '        return rules::multiClassCombo(racePick, row);',
    '    }',
    '',
    '    // combo eligibility: every class of the combo',
    '    // passes its own gate (the class minimum on the',
    '    // ADJUSTED prime + Race Table I via classEligible;',
    '    // the subclass bits their R180 minimums and',
    '    // player-eligibility), plus the half-elf',
    '    // multi-class cleric WIS 13 (vs the single 9)',
    '    bool multiEligible(int mask) const {',
    '        if (!rules::multiClassAllowed(racePick, mask))',
    '            return false;',
    '        int n = rules::multiClassCount(mask);',
    '        for (int i = 0; i < n; ++i) {',
    '            int b = rules::multiClassBitAt(mask, i);',
    '            int base = rules::multiClassBaseOfBit(b);',
    '            int sub = rules::multiClassSubOfBit(b);',
    '            if (!classEligible(base)) return false;',
    '            if (sub >= 0 &&',
    '                !rules::subclassMeetsAbilityMin(sub,',
    '                        raceAdjusted()))',
    '                return false;',
    '            if (sub >= 0 &&',
    '                !rules::subclassPlayerAllowed(',
    '                    sub, (rules::CharRace)racePick))',
    '                return false;',
    '        }',
    '        if ((mask & rules::MC_CLERIC) != 0 &&',
    '            racePick == 4 &&',
    '            raceAdjusted().wis <',
    '                rules::halfelfClericWisMin())',
    '            return false;',
    '        return true;',
    '    }',
    '',
    '    // R233: finalize as a multi-class combo. The member',
    '    // rides the PRIMARY class - the first set bit (the',
    '    // fighter bit when the combo carries it - the best',
    '    // melee class on the swing - the JUDGMENT); the',
    '    // hit dice roll',
    '    // every class die, each with its con adjustment,',
    '    // and read the quotient (the R185 rule); the kit',
    '    // rides the MOST RESTRICTIVE armor allowance and',
    '    // the all-allow shield gate (the JUDGMENT)',
    '    Character makeMultiMember(int mask) {',
    '        int b0 = rules::multiClassBitAt(mask, 0);',
    '        int base0 = rules::multiClassBaseOfBit(b0);',
    '        int sub0 = rules::multiClassSubOfBit(b0);',
    '        Character c = sub0 >= 0',
    '            ? makeSubclassMember(sub0)',
    '            : makeMember(base0);',
    '        c.multiMask = mask;',
    '        c.subclass = sub0;   // every printed combo',
    '                             // rides a base-class',
    '                             // primary (the subclass',
    '                             // bits sit high); the',
    '                             // branch keeps a future',
    '                             // combo honest',
    '',
    '        // hit points: every class die, each with its',
    '        // con adjustment, quotient by the class count',
    '        // (the R185 pin); the per-die floor is 1',
    '        int n = rules::multiClassCount(mask);',
    '        int sum = 0;',
    '        for (int i = 0; i < n; ++i) {',
    '            int b = rules::multiClassBitAt(mask, i);',
    '            int base = rules::multiClassBaseOfBit(b);',
    '            int sub = rules::multiClassSubOfBit(b);',
    '            int conCls = sub >= 0',
    '                ? rules::subclassConClass(sub) : base;',
    '            int conAdj = rules::conHPAdjustment(',
    '                conCls, c.abilities.con);',
    '            int die = sub >= 0',
    '                ? rules::subclassHitDie(sub)',
    '                : rules::CLASS_HIT_DIE[base];',
    '            int d = (int)creationDice.roll(',
    '                1, (uint32_t)die, 0) + conAdj;',
    '            if (d < 1) d = 1;',
    '            sum += d;',
    '        }',
    '        int hp = rules::multiclassHpQuotient(sum, n);',
    '        if (hp < 1) hp = 1;',
    '        c.hp = c.maxHp = hp;',
    '',
    '        // the kit: the most restrictive armor among',
    '        // the combo (none < leather < chain < plate),',
    '        // the shield only when every class allows it',
    '        int w = 3;   // start permissive',
    '        bool sh = true;',
    '        for (int i = 0; i < n; ++i) {',
    '            int base = rules::multiClassBaseOfBit(',
    '                rules::multiClassBitAt(mask, i));',
    '            int bw = 3;',
    '            if (!rules::armorAllowed(base,',
    '                                     rules::ARMOR_PLATE)) {',
    '                if (rules::armorAllowed(base,',
    '                                        rules::ARMOR_CHAIN))',
    '                    bw = 2;',
    '                else if (rules::armorAllowed(',
    '                             base, rules::ARMOR_LEATHER))',
    '                    bw = 1;',
    '                else',
    '                    bw = 0;',
    '            }',
    '            if (bw < w) w = bw;',
    '            if (!rules::shieldAllowed(base)) sh = false;',
    '        }',
    '        c.armor.id = w == 3 ? items::ARMOR_PLATE',
    '                    : w == 2 ? items::ARMOR_CHAIN_MAIL',
    '                    : w == 1 ? items::ARMOR_LEATHER',
    '                             : items::ARMOR_NONE_EQUIPPED;',
    '        c.shield = sh;',
    '        return c;',
    '    }',
]

# ---- 13: creationKeyDown CR_CLASS gains the M key ----
cls_old = [
    '                        cr.classPick = idx;',
    '                        cr.subPick = -1;   // plain until chosen',
    '                        cr.stage = CR_SUBCLASS;   // R230',
    '                    }',
    '                    break;',
    '                }',
]
cls_new = [
    '                        cr.classPick = idx;',
    '                        cr.subPick = -1;   // plain until chosen',
    '                        cr.multiMask = 0;  // R233: single path',
    '                        cr.stage = CR_SUBCLASS;   // R230',
    '                    }',
    '                    break;',
    '                }',
    '                case ' + Q + 'M' + Q + ':   // R233: the combos',
    '                    if (rules::multiClassPossible(cr.racePick)) {',
    '                        cr.multiMask = 0;',
    '                        cr.stage = CR_MULTI;',
    '                    }',
    '                    break;',
]

# ---- 14: creationKeyDown CR_MULTI ----
multi_old = [
    '                case VK_ESCAPE:',
    '                    cr.stage = CR_CLASS;  // back to the class',
    '                    break;',
    '            }',
    '            break;',
    '',
    '        case CR_NAME:',
]
multi_new = [
    '                case VK_ESCAPE:',
    '                    cr.stage = CR_CLASS;  // back to the class',
    '                    break;',
    '            }',
    '            break;',
    '',
    '        case CR_MULTI:   // R233: the multi-class offer',
    '            switch (wp) {',
    '                case ' + Q + '1' + Q + ': case ' + Q + '2' + Q + ': case ' + Q + '3' + Q + ':',
    '                case ' + Q + '4' + Q + ': case ' + Q + '5' + Q + ': case ' + Q + '6' + Q + ':',
    '                case ' + Q + '7' + Q + ': case ' + Q + '8' + Q + ': {',
    '                    int row = (int)(wp - ' + Q + '1' + Q + ');',
    '                    if (row < cr.multiOfferCount()) {',
    '                        int mask = cr.multiOfferAt(row);',
    '                        if (cr.multiEligible(mask)) {',
    '                            cr.multiMask = mask;',
    '                            cr.stage = CR_NAME;',
    '                        }',
    '                    }',
    '                    break;',
    '                }',
    '                case VK_ESCAPE:',
    '                    cr.multiMask = 0;',
    '                    cr.stage = CR_CLASS;  // back to the class',
    '                    break;',
    '            }',
    '            break;',
    '',
    '        case CR_NAME:',
]

# ---- 15: creationConfirmName the three-way ----
conf_old = [
    '    Character c = cr.subPick >= 0',
    '        ? cr.makeSubclassMember(cr.subPick)',
    '        : cr.makeMember(cr.classPick);',
]
conf_new = [
    '    Character c = cr.multiMask != 0',
    '        ? cr.makeMultiMember(cr.multiMask)',
    '        : cr.subPick >= 0',
    '        ? cr.makeSubclassMember(cr.subPick)',
    '        : cr.makeMember(cr.classPick);',
]

# ---- 16: drawCreate the CR_MULTI panel ----
dmul_old = [
    '                     "[1-4] choose   [esc] back to class",',
    '                     35);',
    '            break;',
    '        }',
    '',
    '        case CR_NAME: {',
]
dmul_new = [
    '                     "[1-4] choose   [esc] back to class",',
    '                     35);',
    '            break;',
    '        }',
    '',
    '        case CR_MULTI: {   // R233: the combo offer',
    '            TextOutA(dc, 20, py, "CHOOSE A COMBINATION",',
    '                     20);',
    '            py += 30;',
    '            for (int r = 0;',
    '                 r < cr.multiOfferCount(); ++r) {',
    '                int mask = cr.multiOfferAt(r);',
    '                bool ok = cr.multiEligible(mask);',
    '                char mrow[96];',
    '                int n = rules::multiClassCount(mask);',
    '                std::string cn;',
    '                for (int i = 0; i < n; ++i) {',
    '                    int b = rules::multiClassBitAt(mask, i);',
    '                    int sub = rules::multiClassSubOfBit(b);',
    '                    if (i > 0) cn += "/";',
    '                    cn += sub >= 0',
    '                        ? rules::subclassDef(sub).name',
    '                        : CLASS_NAMES[',
    '                            rules::multiClassBaseOfBit(b)];',
    '                }',
    '                snprintf(mrow, sizeof mrow,',
    '                         "  [%d] %-18s  %s",',
    '                         r + 1, cn.c_str(),',
    '                         ok ? "" : "- not qualified");',
    '                SetTextColor(dc, ok ? RGB(210, 195, 165)',
    '                                    : RGB(110, 105, 95));',
    '                TextOutA(dc, 40, py, mrow,',
    '                         (int)strlen(mrow));',
    '                py += 26;',
    '            }',
    '            SetTextColor(dc, RGB(190, 175, 140));',
    '            TextOutA(dc, 20, VIEW_H - 60,',
    '                     "[1-8] choose   [esc] back to class",',
    '                     35);',
    '            break;',
    '        }',
    '',
    '        case CR_NAME: {',
]

# ---- 17: drawCreate the CR_CLASS hint ----
hint_old = [
    '                     "[1-4] choose class   [esc] back to race",',
    '                     39);',
    '            break;',
    '        }',
]
hint_new = [
    '                     "[1-4] choose class   [esc] back to race",',
    '                     39);',
    '            if (rules::multiClassPossible(cr.racePick))',
    '                TextOutA(dc, 20, VIEW_H - 38,',
    '                         "[M] the multi-class combinations",',
    '                         32);',
    '            break;',
    '        }',
]

# ---- 18: the save line ----
save_old = [
    '            if (c.layHandsDay >= 0)',
    '                fprintf(f, "layhands %d' + BS + 'n", c.layHandsDay);',
]
save_new = [
    '            if (c.layHandsDay >= 0)',
    '                fprintf(f, "layhands %d' + BS + 'n", c.layHandsDay);',
    '            // R233: the multi-class combo (only when set -',
    '            // v1 saves carry no line and load as single)',
    '            if (c.multiMask != 0)',
    '                fprintf(f, "multi %d' + BS + 'n", c.multiMask);',
]

# ---- 19: the load branch ----
load_old = [
    '                    c.layHandsDay = lh;',
    '                }',
]
load_new = [
    '                    c.layHandsDay = lh;',
    '                } else if (strcmp(tag, "multi") == 0) {',
    '                    int mm = 0;',
    '                    if (fscanf(f, "%d", &mm) != 1 ||',
    '                        mm < 0 || mm > 127) {',
    '                        fclose(f);',
    '                        log.add("adnd1.sav is corrupt (multi).");',
    '                        return false;',
    '                    }',
    '                    c.multiMask = mm;',
    '                }',
]

# ---- 20: regtest gains the appstate include ----
reginc_old = [
    '#include "game/party.h"',
]
reginc_new = [
    '#include "game/party.h"',
    '#include "game/appstate.h"  // R233: the multi-class audit',
]

# ---- 21: the R233 audit ----
audit_old = [
    '        printf("R232 subclass specials hooks audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]
audit_new = [
    '        printf("R232 subclass specials hooks audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R233a: the multi-class seam audit ----',
    '    // The combo bit helpers (the pure-expression',
    '    // seam), the R185 quotient/stalled machinery,',
    '    // and the combo table joins the engine reads',
    '    // (an evaluable block - verified by audit_eval).',
    '    {',
    '        int bad = 0;',
    '        // the bit helpers: count, ordered bits, the',
    '        // base-class and subclass maps',
    '        if (rules::multiClassCount(0) != 0) ++bad;',
    '        if (rules::multiClassCount(3) != 2) ++bad;',
    '        if (rules::multiClassCount(11) != 3) ++bad;',
    '        if (rules::multiClassCount(127) != 7) ++bad;',
    '        if (rules::multiClassCount(6) != 2) ++bad;',
    '        if (rules::multiClassCount(48) != 2) ++bad;',
    '        if (rules::multiClassBitAt(11, 0) != 1) ++bad;',
    '        if (rules::multiClassBitAt(11, 1) != 2) ++bad;',
    '        if (rules::multiClassBitAt(11, 2) != 8) ++bad;',
    '        if (rules::multiClassBitAt(5, 1) != 4) ++bad;',
    '        if (rules::multiClassBitAt(36, 1) != 32) ++bad;',
    '        if (rules::multiClassBitAt(6, 0) != 2) ++bad;',
    '        if (rules::multiClassBitAt(6, 1) != 4) ++bad;',
    '        if (rules::multiClassBitAt(48, 0) != 16) ++bad;',
    '        if (rules::multiClassBitAt(48, 1) != 32) ++bad;',
    '        if (rules::multiClassBitAt(36, 0) != 4) ++bad;',
    '        if (rules::multiClassBitAt(24, 0) != 8) ++bad;',
    '        if (rules::multiClassBitAt(24, 1) != 16) ++bad;',
    '        if (rules::multiClassBitAt(68, 0) != 4) ++bad;',
    '        if (rules::multiClassBitAt(68, 1) != 64) ++bad;',
    '        if (rules::multiClassBaseOfBit(1) != 0) ++bad;',
    '        if (rules::multiClassBaseOfBit(16) != 1) ++bad;',
    '        if (rules::multiClassBaseOfBit(32) != 0) ++bad;',
    '        if (rules::multiClassBaseOfBit(64) != 3) ++bad;',
    '        if (rules::multiClassSubOfBit(1) != -1) ++bad;',
    '        if (rules::multiClassSubOfBit(16) != 3) ++bad;',
    '        if (rules::multiClassSubOfBit(32) != 1) ++bad;',
    '        if (rules::multiClassSubOfBit(64) != 4) ++bad;',
    '        // the quotient and stalled rules (R185)',
    '        if (rules::multiclassHpQuotient(5, 2) != 3) ++bad;',
    '        if (rules::multiclassHpQuotient(3, 2) != 2) ++bad;',
    '        if (rules::multiclassHpQuotient(1, 2) != 1) ++bad;',
    '        if (!rules::multiclassHitDieStalled(9, 9)) ++bad;',
    '        if (rules::multiclassHitDieStalled(8, 9)) ++bad;',
    '        // the combo table joins (the R185 rows the',
    '        // engine reads)',
    '        if (rules::multiClassComboCount(4) != 8) ++bad;',
    '        if (rules::multiClassCombo(4, 0) != 5) ++bad;',
    '        if (rules::multiClassCombo(6, 2) != 68) ++bad;',
    '        printf("R233a multi-class seam audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R233: the multi-class engine audit ----',
    '    // The toActor primary convention, the creation',
    '    // gates and the member factory (an engine audit -',
    '    // the R174/R232 convention; the C++ battery is',
    '    // the gate).',
    '    {',
    '        int bad = 0;',
    '        // the Character + toActor primary convention',
    '        {',
    '            Character c;',
    '            if (c.multiMask != 0) ++bad;',
    '            c.multiMask = 11;   // F/MU/T',
    '            ai::Actor a = c.toActor();',
    '            if (a.classIndex != 0) ++bad;',
    '            if (a.subclass != -1) ++bad;',
    '            c.multiMask = 24;   // I/T: thief primary',
    '            a = c.toActor();',
    '            if (a.classIndex != 3) ++bad;',
    '            if (a.subclass != -1) ++bad;',
    '            c.multiMask = 68;   // C/A: cleric primary',
    '            a = c.toActor();',
    '            if (a.classIndex != 2) ++bad;',
    '            if (a.subclass != -1) ++bad;',
    '        }',
    '        // the creation gates + the member factory',
    '        {',
    '            CreationState cr;',
    '            cr.racePick = 4;   // half-elf',
    '            cr.rolled.str = 12; cr.rolled.int_ = 12;',
    '            cr.rolled.wis = 12; cr.rolled.dex = 12;',
    '            cr.rolled.con = 12; cr.rolled.cha = 12;',
    '            // the half-elf multi-class cleric WIS 13',
    '            if (cr.multiEligible(5)) ++bad;   // WIS 12',
    '            cr.rolled.wis = 13;',
    '            if (!cr.multiEligible(5)) ++bad;   // C/F',
    '            if (!cr.multiEligible(3)) ++bad;   // F/MU',
    '            if (cr.multiEligible(24)) ++bad;   // I/T: no elf bit here',
    '            // the factory: F/MU - the fighter primary,',
    '            // the hp quotient bounds (d10 + d4 at',
    '            // CON 12, quotients 1..7), the MU kit',
    '            Character mc = cr.makeMultiMember(3);',
    '            if (mc.multiMask != 3) ++bad;',
    '            if (mc.classIndex != 0) ++bad;',
    '            if (mc.subclass != -1) ++bad;',
    '            if (mc.hp < 1 || mc.hp > 7) ++bad;',
    '            if (mc.armor.id != items::ARMOR_NONE_EQUIPPED)',
    '                ++bad;',
    '            if (mc.shield) ++bad;',
    '            // the dwarf F/T - the thief kit',
    '            cr.racePick = 1;',
    '            cr.rolled.str = 12; cr.rolled.dex = 12;',
    '            Character dt = cr.makeMultiMember(9);',
    '            if (dt.multiMask != 9) ++bad;',
    '            if (dt.armor.id != items::ARMOR_LEATHER) ++bad;',
    '            if (dt.shield) ++bad;',
    '            // the half-orc C/A - the assassin primary',
    '            cr.racePick = 6;',
    '            cr.rolled.wis = 13;',
    '            Character ca = cr.makeMultiMember(68);',
    '            if (ca.subclass != -1) ++bad;',
    '            if (ca.classIndex != 2) ++bad;',
    '        }',
    '        printf("R233 multi-class engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]

# ---- 22: the gap-report box ----
gap_old = [
    '- [ ] multi-class and dual-class engine',
    '      (R185 data + comments, no runtime).',
]
gap_new = [
    '- [x] R233 the multi-class engine - WIRED: the',
    '      R185 combo table is playable - the [M]',
    '      creation stage (the race printed combos,',
    '      the eligibility gates: every class passes',
    '      its own minimum on the ADJUSTED prime and',
    '      Race Table I, the subclass bits their R180',
    '      minimums and player-eligibility, the',
    '      half-elf multi-class cleric WIS 13), the',
    '      member factory (every class die rolls with',
    '      its con adjustment and reads the quotient',
    '      - the R185 rule; the kit rides the most',
    '      restrictive armor allowance and the',
    '      all-allow shield gate - the JUDGMENT); the',
    '      member rides the PRIMARY class - the first',
    '      set bit (the fighter bit when the combo',
    '      carries it - the best melee class on the',
    '      swing - the JUDGMENT; every printed combo',
    '      rides a base-class primary); the ranger,',
    '      assassin and illusionist bits roll their',
    '      R231 subclass dice on promotion; the',
    '      requisites average',
    '      (PHB p.20), the combo earns no',
    '      single-class bonus, the promotions queue',
    '      on the primary ladder and roll every',
    '      UNSTALLED class die (a class at its name',
    '      cap contributes none - the R185 stalled',
    '      pin), reading the quotient; the',
    '      v1-compatible multi save line; the R233',
    '      battery audit. Simplifications recorded:',
    '      the roster display shows the primary class',
    '      name; the caster slots fill from the',
    '      primary caster (no slot-summing).',
    '      Census 150.',
    '- [ ] dual-class engine (the human class-change',
    '      runtime; R185 comments, no engine yet).',
]

PATCHES = [
    (MC,   'enum McBits', mc_enum_old, mc_enum_new),
    (MC,   'multiClassBitAt(int mask, int i)', mc_old, mc_new),
    (PAR,  'multiclass.h"  // R233', inc_old, inc_new),
    (PAR,  'the R185 combo mask; the member rides', field_old, field_new),
    (PAR,  'a.subclass   = rules::multiClassSubOfBit(b);', toa_old, toa_new),
    (PAR,  'the multi-class requisites average', prime_old, prime_new),
    (PAR,  'the multi-class combo earns no', bonus_old, bonus_new),
    (PAR,  'member queues on the', gxq_old, gxq_new),
    (PAR,  'member promotes on the', tnq_old, tnq_new),
    (PAR,  'the multi-class promotion - every', die_old, die_new),
    (APP,  'CR_MULTI,   // R233', enum_old, enum_new),
    (APP,  'single-class path; else the R185 combo mask', crf_old, crf_new),
    (APP,  'Character makeMultiMember(int mask)', helpers_old, helpers_new),
    (AD,   'cr.multiMask = 0;  // R233: single path', cls_old, cls_new),
    (AD,   'case CR_MULTI:   // R233: the multi-class offer', multi_old, multi_new),
    (AD,   'cr.makeMultiMember(cr.multiMask)', conf_old, conf_new),
    (AD,   'CHOOSE A COMBINATION', dmul_old, dmul_new),
    (AD,   'the multi-class combinations', hint_old, hint_new),
    (CORE, 'multi %d', save_old, save_new),
    (CORE, 'strcmp(tag, "multi") == 0', load_old, load_new),
    (REG,  'game/appstate.h"  // R233', reginc_old, reginc_new),
    (REG,  'R233 multi-class engine audit', audit_old, audit_new),
    (GAP,  'R233 the multi-class engine - WIRED', gap_old, gap_new),
]

applied = 0
already = 0
for path, marker, old, new in PATCHES:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    count_new = text.count(new_s)
    count_old = text.count(old_s)
    # the idempotence signal is the NEW text: a patch whose
    # old block survives inside the new block (the append
    # style) still finds its old text on rerun, so the new
    # text decides
    if count_new >= 1:
        already += 1
        continue
    if count_old == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    elif count_old == 0:
        print('R233 FAIL: marker missing post-patch: ' + marker)
        sys.exit(1)
    else:
        print('R233 FAIL: marker appears ' + str(count_old) +
              ' times: ' + marker)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied == len(PATCHES):
    t = open(REG).read()
    if t.count('R233 multi-class engine audit') != 1:
        print('R233 FAIL: the audit line must appear exactly once')
        sys.exit(1)
    if t.count('audit: bad ') > 150:
        print('R233 FAIL: census over 149')
        sys.exit(1)
    t = open(GAP).read()
    if t.count('Census 150.') != 1:
        print('R233 FAIL: gap census line missing')
        sys.exit(1)
    if '- [ ] multi-class and dual-class engine' in t:
        print('R233 FAIL: the old box still open')
        sys.exit(1)

print('R233 splice: ALL OK (applied ' + str(applied) + ', already ' + str(already) + ')')
print('R233 note: 22 patches - the R185 combos playable; the member')
print('rides the primary class (the first set bit); the dual-class')
print('runtime stays the next arc box.')
print('commit: R233: the multi-class engine - the R185 combos playable, the primary-class convention, the quotient hit dice (census 150)')

