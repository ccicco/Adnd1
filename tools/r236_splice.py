#!/usr/bin/env python3
# R236 splice: the bard specials.
#
# The Appendix II poetics and item knowledge go
# live now that the bard career (R235) is
# playable. The poetics ferocity rides the
# resolveMelee seam: a living bard in the company
# who has sung past the 2 printed rounds grants
# the party +1 on melee to-hit rolls (morale is
# void - the party is MORALE_FANATIC; the turn
# window is simplified to while the bard lives;
# melee only, the R232 precedent). The item
# knowledge rides the town [X] key: the finest
# living bard studies the front unidentified
# find on a Table II legend lore roll - a miss
# leaves the item in the pack (retryable, no
# cost), a hit resolves like the identify scroll
# (the same taker logic, else sold for 200 gp).
# The studies-begin message names the college.
# The henchmen ladder and the musical item
# bonuses stay data-only (the R186 pins).
#
# commit: R236: the bard specials - the poetics ferocity, the bardic lore, the colleges (census 155)

import sys

BRD  = 'rules/bard.h'
ACT  = 'ai/actor.cpp'
APP  = 'game/appstate.h'
TOWN = 'game/state_town.cpp'
AD   = 'adnd1.cpp'
REG  = 'regtest.cpp'
GAP  = 'tools/phb_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson)
g = open(GAP).read()
if g.count('Census 154.') != 1 and g.count('Census 155.') != 1:
    print('R236 FAIL: gap report census line missing')
    sys.exit(1)
t = open(REG).read()
if t.count('audit: bad ') != 154 and t.count('audit: bad ') != 155:
    print('R236 FAIL: regtest census is neither 154 nor 155')
    sys.exit(1)

# ---- 0: the poetics constants become a named enum
# (the R233 McBits convention - audit_eval reads
# enum constants, not static const ints) plus the
# pure-expression helpers (the evaluable subset:
# nested ternaries, no logical operators) ----
pins_old = [
    'static const int BARD_POETIC_ROUNDS = 2;',
    'static const int BARD_POETIC_TURN = 1;   // lasts 1 complete turn',
    'static const int BARD_MORALE_BONUS = 10; // percent',
    'static const int BARD_HIT_BONUS = 1;     // ferocity in attack',
]
pins_new = [
    '// R236: the poetics seam - the constants ride a',
    '// named enum (the R233 McBits convention) with',
    '// pure-expression helpers (the evaluable subset;',
    '// nested ternaries, no logical operators) so',
    '// audit_eval reads the pins. The enum keeps the',
    '// R186 data-audit references alive.',
    'enum BardPoetics {',
    '    BARD_POETIC_ROUNDS = 2,',
    '    BARD_POETIC_TURN = 1,   // lasts 1 complete turn',
    '    BARD_MORALE_BONUS = 10, // percent',
    '    BARD_HIT_BONUS = 1,     // ferocity in attack',
    '};',
    '',
    '// The +1 ferocity on the party attacks (the',
    '// Appendix II poetics; the morale half is void -',
    '// the party is MORALE_FANATIC and never checks',
    '// morale).',
    'inline int bardPoeticsHitBonus() {',
    '    return BARD_HIT_BONUS;',
    '}',
    '',
    '// The rounds of playing before the poetics takes',
    '// hold (2 as printed).',
    'inline int bardPoeticsRoundsRequired() {',
    '    return BARD_POETIC_ROUNDS;',
    '}',
    '',
    '// The gate: the bard lives and the round has',
    '// passed the required playing. The 1-turn',
    '// duration is simplified to while the bard',
    '// lives - the JUDGMENT.',
    'inline int bardPoeticsActive(int round, int bardAlive) {',
    '    return (bardAlive == 1)',
    '        ? ((round >= 1 + bardPoeticsRoundsRequired())',
    '           ? 1 : 0)',
    '        : 0;',
    '}',
]

# ---- 1: the actor.cpp include ----
inc_old = [
    '#include "../rules/palrangerspells.h"  // R232: the giant-class roster',
]
inc_new = [
    '#include "../rules/palrangerspells.h"  // R232: the giant-class roster',
    '#include "../rules/bard.h"  // R236: the poetics ferocity',
]

# ---- 2: the resolveMelee poetics hook ----
poetic_old = [
    '    if (backstab) adj += rules::backstabHitBonusDie();',
]
poetic_new = [
    '    if (backstab) adj += rules::backstabHitBonusDie();',
    '    // R236: the poetics ferocity - a living bard in',
    '    // the company has sung past the printed rounds;',
    '    // every party strike carries +1 (Appendix II).',
    '    if (attacker.isCharacter) {',
    '        int bardAlive = 0;',
    '        for (const auto& pa : m_party) {',
    '            if (pa.alive() && pa.bard) bardAlive = 1;',
    '        }',
    '        if (rules::bardPoeticsActive(m_round, bardAlive))',
    '            adj += rules::bardPoeticsHitBonus();',
    '    }',
]

# ---- 3: the townBardicLore command (the taker logic
# mirrors useIdentifyScroll - the R85 identify
# economy; a miss leaves the item queued) ----
lore_old = [
    '// ---- townBuyChain ----',
]
lore_new = [
    '// ---- townBardicLore ----',
    '// R236: the Appendix II item knowledge. The',
    '// finest living bard (highest level) studies the',
    '// front unidentified find: a Table II legend',
    '// lore roll. A miss leaves the item in the pack',
    '// (retryable, no cost); a hit resolves exactly',
    '// like the identify scroll - the same taker',
    '// logic, else sold for 200 gp.',
    'void AppState::townBardicLore(){',
    '        if (mode != MODE_TOWN) return;',
    '        const Character* bard = nullptr;',
    '        for (const auto& c : party.members) {',
    '            if (c.hp <= 0) continue;',
    '            if (!c.bard) continue;',
    '            if (!bard || c.level > bard->level) bard = &c;',
    '        }',
    '        if (!bard) {',
    '            log.add("No bard rides with the company.");',
    '            return;',
    '        }',
    '        if (party.unidentified.empty()) {',
    '            log.add("Nothing in the pack wants "',
    '                    "identifying.");',
    '            return;',
    '        }',
    '        int roll = (int)rng.below(100) + 1;',
    '        int need = rules::bardLegendLorePercent(bard->level);',
    '        if (roll > need) {',
    '            char buf[96];',
    '            snprintf(buf, sizeof buf,',
    '                     "%s cannot place the find - it stays "',
    '                     "in the pack (retryable).",',
    '                     bard->name.c_str());',
    '            log.add(buf);',
    '            return;',
    '        }',
    '        Party::PendingItem it = party.unidentified.front();',
    '        party.unidentified.erase(',
    '            party.unidentified.begin());',
    '        if (it.kind == 0) {',
    '            // magic weapon - the first living fighter',
    '            // (then anyone) whose blade is a lesser enchant',
    '            Character* taker = nullptr;',
    '            for (auto& c : party.members) {',
    '                if (c.hp <= 0) continue;',
    '                if (c.classIndex != rules::CLASS_FIGHTER)',
    '                    continue;',
    '                if (c.weapon.plus < it.plus) { taker = &c; break; }',
    '            }',
    '            if (!taker) {',
    '                for (auto& c : party.members) {',
    '                    if (c.hp <= 0) continue;',
    '                    if (c.weapon.plus < it.plus) {',
    '                        taker = &c;',
    '                        break;',
    '                    }',
    '                }',
    '            }',
    '            if (taker) {',
    '                taker->weapon.id = items::WPN_LONG_SWORD;',
    '                taker->weapon.plus = it.plus;',
    '                char buf[96];',
    '                snprintf(buf, sizeof buf,',
    '                         "%s places the find - a long sword "',
    '                         "+%d! %s claims it.",',
    '                         bard->name.c_str(), it.plus,',
    '                         taker->name.c_str());',
    '                log.add(buf);',
    '            } else {',
    '                log.add("The lore reveals a long sword - "',
    '                        "but no one can better his blade. "',
    '                        "It is sold for 200 gp.");',
    '                party.gold += 200;',
    '            }',
    '        } else {',
    '            // enchanted armor - the first living fighter',
    '            // or cleric whose armor is a lesser enchant',
    '            Character* taker = nullptr;',
    '            for (auto& c : party.members) {',
    '                if (c.hp <= 0) continue;',
    '                if (c.classIndex != rules::CLASS_FIGHTER &&',
    '                    c.classIndex != rules::CLASS_CLERIC)',
    '                    continue;',
    '                if (c.armor.plus < it.plus) { taker = &c; break; }',
    '            }',
    '            if (taker) {',
    '                taker->armor.plus = it.plus;',
    '                char buf[96];',
    '                snprintf(buf, sizeof buf,',
    '                         "%s places the find - enchanted "',
    '                         "armor (+%d)! %s claims it.",',
    '                         bard->name.c_str(), it.plus,',
    '                         taker->name.c_str());',
    '                log.add(buf);',
    '            } else {',
    '                log.add("The lore reveals enchanted armor - "',
    '                        "but no one can better his mail. "',
    '                        "It is sold for 200 gp.");',
    '                party.gold += 200;',
    '            }',
    '        }',
    '}',
    '',
    '// ---- townBuyChain ----',
]

# ---- 4: the college announcement (the studies-begin
# message names the first college) ----
coll_old = [
    '            snprintf(buf, sizeof buf,',
    '                     "%s begins the druidical studies - "',
    '                     "a bard at 1st level (hit dice kept).",',
    '                     c.name.c_str());',
]
coll_new = [
    '            snprintf(buf, sizeof buf,',
    '                     "%s begins the druidical studies - "',
    '                     "a bard at 1st level (hit dice kept) "',
    '                     "- a %s of the first college.",',
    '                     c.name.c_str(),',
    '                     rules::bardCollege(1));',
]

# ---- 5: the appstate.h declaration ----
decl_old = [
    '    // R235: the bardic studies - the Appendix II career',
    '    void townBeginBardStudies();',
]
decl_new = [
    '    // R235: the bardic studies - the Appendix II career',
    '    void townBeginBardStudies();',
    '',
    '    // R236: the bardic lore - the Appendix II item',
    '    // knowledge (the town [X] key)',
    '    void townBardicLore();',
]

# ---- 6: the town [X] key ----
key_old = [
    '                    // R235: the bardic studies',
    '                    case ' + Q + 'A' + Q + ':',
    '                    case ' + Q + 'a' + Q + ':',
    '                        g_app.townBeginBardStudies();',
    '                        break;',
]
key_new = [
    '                    // R235: the bardic studies',
    '                    case ' + Q + 'A' + Q + ':',
    '                    case ' + Q + 'a' + Q + ':',
    '                        g_app.townBeginBardStudies();',
    '                        break;',
    '',
    '                    // R236: the bardic lore (Appendix II)',
    '                    case ' + Q + 'X' + Q + ':',
    '                    case ' + Q + 'x' + Q + ':',
    '                        g_app.townBardicLore();',
    '                        break;',
]

# ---- 7: the GUILD help line ----
help_old = [
    '             "GUILD: [K] class change  [U] resort  "',
    '             "[A] bardic studies");',
]
help_new = [
    '             "GUILD: [K] class change  [U] resort  "',
    '             "[A] bardic studies  [X] lore");',
]

# ---- 8: the R236 audit (ONE evaluable block; the
# town glue is AppState-level - untestable in the
# battery without the full app, the R235 lesson) ----
audit_old = [
    '    // ---- R181: the attacks per melee round audit ----',
]
audit_new = [
    '    // ---- R236: the bard specials audit ----',
    '    // The poetics seam (the R236 helpers), the',
    '    // Table II lore and charm percents, the',
    '    // language ladder, and the Table I dice.',
    '    {',
    '        int bad = 0;',
    '        // the poetics seam: the +1 ferocity, the',
    '        // 2 rounds required, the round and alive gates',
    '        if (rules::bardPoeticsHitBonus() != 1) ++bad;',
    '        if (rules::bardPoeticsRoundsRequired() != 2) ++bad;',
    '        if (rules::bardPoeticsActive(0, 1) != 0) ++bad;',
    '        if (rules::bardPoeticsActive(1, 1) != 0) ++bad;',
    '        if (rules::bardPoeticsActive(2, 1) != 0) ++bad;',
    '        if (rules::bardPoeticsActive(3, 1) != 1) ++bad;',
    '        if (rules::bardPoeticsActive(9, 1) != 1) ++bad;',
    '        if (rules::bardPoeticsActive(9, 0) != 0) ++bad;',
    '        if (rules::bardPoeticsActive(1, 2) != 0) ++bad;',
    '        // Table II legend lore (the 14th-level 55',
    '        // IS as printed - the R186 pin)',
    '        if (rules::bardLegendLorePercent(0) != 0) ++bad;',
    '        if (rules::bardLegendLorePercent(1) != 0) ++bad;',
    '        if (rules::bardLegendLorePercent(5) != 13) ++bad;',
    '        if (rules::bardLegendLorePercent(13) != 56) ++bad;',
    '        if (rules::bardLegendLorePercent(14) != 55) ++bad;',
    '        if (rules::bardLegendLorePercent(23) != 99) ++bad;',
    '        if (rules::bardLegendLorePercent(99) != 99) ++bad;',
    '        // Table II charm (a miss at 0th - the clamp)',
    '        if (rules::bardCharmPercent(1) != 15) ++bad;',
    '        if (rules::bardCharmPercent(5) != 30) ++bad;',
    '        if (rules::bardCharmPercent(14) != 60) ++bad;',
    '        if (rules::bardCharmPercent(23) != 95) ++bad;',
    '        // the language ladder (a new tongue at the',
    '        // printed levels, none at 1st-3rd)',
    '        if (rules::bardLanguages(1) != 0) ++bad;',
    '        if (rules::bardLanguages(3) != 0) ++bad;',
    '        if (rules::bardLanguages(4) != 1) ++bad;',
    '        if (rules::bardLanguages(23) != 1) ++bad;',
    '        // the Table I dice (d6 through 11, then +1)',
    '        if (rules::bardHitDice(1) != 0) ++bad;',
    '        if (rules::bardHitDice(11) != 10) ++bad;',
    '        if (rules::bardHitDice(12) != 11) ++bad;',
    '        if (rules::bardHitDice(23) != 22) ++bad;',
    '        printf("R236 bard specials audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R181: the attacks per melee round audit ----',
]

# ---- 9: the gap report box (after the R235 box) ----
gap_old = [
    '      combat layer. Census 154.',
]
gap_new = [
    '      combat layer. Census 154.',
    '',
    '- [x] R236 the bard specials - WIRED: the',
    '      Appendix II poetics and lore go live -',
    '      the ferocity (a living bard in the',
    '      company who has sung past the 2 printed',
    '      rounds grants the party +1 on melee',
    '      to-hit rolls in resolveMelee; the morale',
    '      half is void - the party is',
    '      MORALE_FANATIC; the 1-turn duration is',
    '      simplified to while the bard lives; melee',
    '      only - the R232 precedent), the item',
    '      knowledge (the [X] town key - the finest',
    '      living bard studies the front',
    '      unidentified find on a Table II legend',
    '      lore roll; a miss leaves the item queued,',
    '      retryable, no cost; a hit resolves like',
    '      the identify scroll - the same taker',
    '      logic, else sold for 200 gp), and the',
    '      college announcement (the studies-begin',
    '      message names the first college).',
    '      Simplifications recorded: the henchmen',
    '      ladder and the musical item bonuses stay',
    '      data-only (the R186 pins; no',
    '      bard-henchmen concept, no musical items',
    '      in the registry), and the song never',
    '      negates (no harpies or shriekers in the',
    '      monster special set). Census 155.',
]

PATCHES = [
    (BRD,  'the poetics constants', pins_old, pins_new),
    (ACT,  'the actor.cpp include', inc_old, inc_new),
    (ACT,  'the resolveMelee poetics hook', poetic_old, poetic_new),
    (TOWN, 'townBardicLore', lore_old, lore_new),
    (TOWN, 'the college announcement', coll_old, coll_new),
    (APP,  'the townBardicLore declaration', decl_old, decl_new),
    (AD,   'the town [X] key', key_old, key_new),
    (AD,   'the GUILD help line', help_old, help_new),
    (REG,  'the R236 audit', audit_old, audit_new),
    (GAP,  'R236 the bard specials - WIRED', gap_old, gap_new),
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
    # the idempotence signal is the NEW text (the R233
    # lesson: append-style patches leave the old text
    # inside the new)
    if count_new >= 1:
        already += 1
        continue
    if count_old == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    elif count_old == 0:
        print('R236 FAIL: marker missing post-patch: ' + marker)
        sys.exit(1)
    else:
        print('R236 FAIL: marker appears ' + str(count_old) +
              ' times: ' + marker)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied == len(PATCHES):
    t = open(REG).read()
    if t.count('audit: bad ') != 155:
        print('R236 FAIL: census is not 155')
        sys.exit(1)
    if t.count('R236 bard specials audit') != 1:
        print('R236 FAIL: the R236 audit line must appear once')
        sys.exit(1)
    t = open(GAP).read()
    if t.count('Census 155.') != 1:
        print('R236 FAIL: gap census line missing')
        sys.exit(1)
    if 'R236 the bard specials - WIRED' not in t:
        print('R236 FAIL: the bard specials box is not flipped')
        sys.exit(1)

print('R236 splice: ALL OK (applied ' + str(applied) + ', already ' + str(already) + ')')
print('R236 note: 10 patches - the poetics ferocity rides the')
print('resolveMelee seam; the [X] town key studies the front')
print('unidentified find on a Table II legend lore roll.')
print('commit: R236: the bard specials - the poetics ferocity, the bardic lore, the colleges (census 155)')

