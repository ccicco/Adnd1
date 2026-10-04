# tools/r158_splice.py - R158, 5 patches: weapon speed
# factors in initiative (DMG p.66, PHB p.38), the next
# gap-report box. rules/weaponspeed.h is the header-only
# speed-factor layer (the grenade.h pattern).
#
# (1) rules/weaponspeed.h: the PHB p.38 speed-factor
#     table (named melee weapons), the DMG p.66 rules -
#     the simultaneous-initiative tie order (lower
#     factor strikes first), the extra-attacks rule
#     (difference at least twice the lower factor or 5+,
#     10+ adds a third simultaneous attack; never when
#     closing or charging), and the weapon-vs-activity
#     segment (factor minus the losing initiative die,
#     negatives read as positive). (2) the regtest
#     include. (3) the R158 audit: the named table, the
#     DMG example chain (fist 1, dagger 2, short sword 3,
#     hammer 4; broad/long 5, two-handed 10, pike 13),
#     the extra-attack windows, the fireball example
#     (sword 5 vs casting 3, rolls 1-5; dagger 2, rolls
#     1-5; the two-handed no-chance) - CENSUS 76.
#     (4)-(5) the gap report.
#
# rules/turn verified first: the scheduler has NO
# speed-factor logic (ACTION_MELEE resolves at the
# initiative segment), and that is correct as printed -
# the DMG limits factor use to three caller-detected
# cases (tied armed opponents, factor-determinant rounds
# after the first, weapon vs spellcasting), so the box
# flips [x] with the scheduler untouched.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An
# assert follows EVERY patch (the R142 lesson). ZERO
# backslash characters in this file; no content string
# embeds a literal apostrophe (the R133b + R147 lessons).
# Commit: "R158: weapon speed factors pinned - the
# initiative tie order, extra attacks, weapon-vs-spell
# segments (census 76)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="latin-1") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="latin-1") as f:
        f.write(s)

def patch(p, old, new, tag, marker):
    s = rd(p)
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != 1:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected 1)")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

def create(p, text, tag, marker):
    fp = os.path.join(ROOT, p)
    if os.path.exists(fp):
        s = rd(p)
        if marker in s:
            already.append(tag)
            return
        fails.append(tag + ": exists without the marker")
        return
    wr(p, text)
    applied.append(tag)

p1_text = NL.join(['// ====================================================================', '// Adnd1 - rules/weaponspeed.h', '// R158: weapon speed factors in initiative (DMG p.66,', '// the PHB p.38 Combined Weapons Table column).', '//', '// Pure data + decision logic, header-only (the grenade.h', '// pattern). rules/turn verified first: the segment', '// scheduler needs NO change - the DMG applies the speed', '// factor only in three caller-detected cases:', '//   1. Simultaneous initiative, both opponents armed:', '//      the lower factor strikes first.', '//   2. A factor-determinant round (after an initial', '//      round, or when closing/charging was not needed):', '//      a big factor gap earns attacks before the slower', '//      weapon acts. NOT applicable when closing or', '//      charging.', '//   3. Weapon vs an opponent mid-activity (a spell in', '//      progress): strike segment = factor minus the', '//      LOSING initiative die roll, negatives read as', '//      positive; compare against the casting segments.', '//      If initiative is tied there is no modification.', '// ====================================================================', '', '#pragma once', '', '#include <cstring>', '', 'namespace rules {', '', '// ----------------------------------------------------------------------------', '// The PHB p.38 speed-factor column (melee weapons, named;', '// missile weapons carry no factor). JUDGMENTS: the spear', '// prints 6-8 (length 5 feet to 13+ feet, grip-dependent) -', '// the engine default is 7, the range rides its own helper;', '// footman/horseman mace and flail are named per the print', '// (the engine items Mace/Flail read the footman rows).', '// ----------------------------------------------------------------------------', 'inline int weaponSpeedFactor(const char* name) {', '    static const struct { const char* n; int sf; } t[] = {', '        { "fist",             1 },   // DMG p.66 example', '        { "dagger",           2 },', '        { "short sword",      3 },', '        { "hammer",           4 },   // DMG p.66 example', '        { "club",             4 },', '        { "hand axe",         4 },', '        { "quarterstaff",     4 },', '        { "scimitar",         4 },', '        { "long sword",       5 },   // DMG: broad or long', '        { "broad sword",      5 },', '        { "horseman mace",    6 },', '        { "horseman flail",   6 },', '        { "spear",            7 },   // print 6-8, default 7', '        { "footman mace",     7 },', '        { "footman flail",    7 },', '        { "morning star",     7 },', '        { "battle axe",       7 },', '        { "two-handed sword", 10 },  // DMG p.64/p.66', '        { "pike",             13 },  // the DMG p.66 example', '    };', '    for (int i = 0; i < (int)(sizeof(t) / sizeof(t[0])); ++i)', '        if (std::strcmp(name, t[i].n) == 0) return t[i].sf;', '    return 0;   // unknown: caller decides', '}', '', 'inline void spearSpeedFactorRange(int& lo, int& hi) {', '    lo = 6; hi = 8;   // the printed 5-13+ foot length spread', '}', '', '// ----------------------------------------------------------------------------', '// Case 1 (DMG p.66 Simultaneous Initiative): tied rolls,', '// blows otherwise simultaneous - the lower factor', '// strikes first. Returns -1 if A first, 1 if B first,', '// 0 if equal (truly simultaneous).', '// ----------------------------------------------------------------------------', 'inline int speedFactorFirst(int sfA, int sfB) {', '    if (sfA < sfB) return -1;', '    if (sfB < sfA) return 1;', '    return 0;', '}', '', '// ----------------------------------------------------------------------------', '// Case 2 (DMG p.66): the attacks the lower-factored', '// wielder is entitled to BEFORE the higher acts.', '//   difference >= 10             -> 3 (two before, one', '//                                   simultaneous with the', '//                                   slower first attack)', '//   difference >= 2 x lower      -> 2 (two before any),', '//   or difference >= 5 in any case', '//   otherwise                    -> 1 (the normal one).', '// Never when closing or charging (speedFactorApplies).', '// ----------------------------------------------------------------------------', 'inline int speedFactorAttacksBefore(int sfLow, int sfHigh) {', '    int diff = sfHigh - sfLow;', '    if (diff <= 0) return 1;', '    if (diff >= 10) return 3;', '    if (diff >= 2 * sfLow || diff >= 5) return 2;', '    return 1;', '}', '', 'inline bool speedFactorApplies(bool closingOrCharging) {', '    return !closingOrCharging;   // the print exempts both', '}', '', '// ----------------------------------------------------------------------------', '// Case 3 (DMG p.66 Other Weapon Factor Determinants):', '// the weapon strike segment when the wielder LOST', '// initiative to an opponent mid-activity: factor minus', '// the losing die roll, NEGATIVES READ AS POSITIVE.', '// ----------------------------------------------------------------------------', 'inline int weaponVsActivitySegment(int speedFactor,', '                                   int losingInitiativeRoll) {', '    int v = speedFactor - losingInitiativeRoll;', '    if (v < 0) v = -v;', '    return v;', '}', '', '// Order vs the activity (a spell, casting segments):', '// returns -1 if the weapon strikes first, 0 if', '// simultaneous, 1 if the activity completes first.', 'inline int weaponVsActivityOrder(int strikeSegment,', '                                 int activitySegments) {', '    if (strikeSegment < activitySegments) return -1;', '    if (strikeSegment > activitySegments) return 1;', '    return 0;', '}', '', '// The print: if combat is simultaneous, there is no', '// modification of the weapon speed factor (case 3 never', '// subtracts a die roll the tied round does not have).', 'inline bool speedFactorModifiedWhenSimultaneous() {', '    return false;', '}', '', '} // namespace rules', ''])
create("rules/weaponspeed.h", p1_text,
      "weaponspeed.h: the speed-factor layer",
      marker='spearSpeedFactorRange')
assert len(applied) + len(already) == 1

p2_old = NL.join(['#include "rules/grenade.h"  // R157: pp.64-65 grenade-like missiles'])
p2_new = NL.join(['#include "rules/grenade.h"  // R157: pp.64-65 grenade-like missiles', '#include "rules/weaponspeed.h"  // R158: p.66 weapon speed factors'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: weaponspeed include",
      marker='rules/weaponspeed.h"  // R158')
assert len(applied) + len(already) == 2

p3_old = NL.join(['        printf("R157 grenade missiles audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join(['        printf("R157 grenade missiles audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R158: weapon speed factors audit ---------------', '    // DMG p.66 + the PHB p.38 factor column: the tie order', '    // (lower factor first), the extra-attacks windows, and', '    // the weapon-vs-spell strike segment (factor minus the', '    // losing initiative die, negatives as positive).', '    {', '        int bad = 0;', '        // the named factor table (PHB p.38 + the DMG examples)', '        static const char* const kN[9] = {', '            "fist", "dagger", "short sword", "hammer",', '            "long sword", "broad sword", "two-handed sword",', '            "pike", "quarterstaff"', '        };', '        static const int kSf[9] = { 1, 2, 3, 4, 5, 5, 10, 13, 4 };', '        for (int i = 0; i < 9; ++i) {', '            if (rules::weaponSpeedFactor(kN[i]) != kSf[i])', '                ++bad;', '        }', '        static const char* const kN2[8] = {', '            "club", "hand axe", "scimitar", "horseman mace",', '            "horseman flail", "footman mace", "footman flail",', '            "morning star"', '        };', '        static const int kSf2[8] = { 4, 4, 4, 6, 6, 7, 7, 7 };', '        for (int i = 0; i < 8; ++i) {', '            if (rules::weaponSpeedFactor(kN2[i]) != kSf2[i])', '                ++bad;', '        }', '        if (rules::weaponSpeedFactor("spear") != 7) ++bad;', '        if (rules::weaponSpeedFactor("no such weapon") != 0)', '            ++bad;', '        // the spear 6-8 print range', '        int rlo, rhi;', '        rules::spearSpeedFactorRange(rlo, rhi);', '        if (rlo != 6 || rhi != 8) ++bad;', '        // case 1: the DMG example chain (lower strikes first)', '        if (rules::speedFactorFirst(1, 2) != -1 ||', '            rules::speedFactorFirst(2, 3) != -1 ||', '            rules::speedFactorFirst(3, 4) != -1 ||', '            rules::speedFactorFirst(4, 1) != 1 ||', '            rules::speedFactorFirst(5, 5) != 0) ++bad;', '        // case 2: the extra-attack windows', '        if (rules::speedFactorAttacksBefore(1, 2) != 1 ||', '            rules::speedFactorAttacksBefore(2, 4) != 1 ||', '            rules::speedFactorAttacksBefore(1, 4) != 2 ||', '            rules::speedFactorAttacksBefore(3, 10) != 2 ||', '            rules::speedFactorAttacksBefore(5, 10) != 2 ||', '            rules::speedFactorAttacksBefore(2, 13) != 3 ||', '            rules::speedFactorAttacksBefore(2, 12) != 3 ||', '            rules::speedFactorAttacksBefore(5, 5) != 1) ++bad;', '        // case 2: closing/charging exemption', '        if (rules::speedFactorApplies(true) ||', '            !rules::speedFactorApplies(false)) ++bad;', '        // case 3: the strike segment (negatives as positive)', '        if (rules::weaponVsActivitySegment(5, 1) != 4 ||', '            rules::weaponVsActivitySegment(5, 2) != 3 ||', '            rules::weaponVsActivitySegment(5, 3) != 2 ||', '            rules::weaponVsActivitySegment(5, 5) != 0 ||', '            rules::weaponVsActivitySegment(2, 3) != 1 ||', '            rules::weaponVsActivitySegment(2, 4) != 2 ||', '            rules::weaponVsActivitySegment(2, 5) != 3 ||', '            rules::weaponVsActivitySegment(10, 1) != 9 ||', '            rules::weaponVsActivitySegment(10, 6) != 4) ++bad;', '        // case 3: the fireball example (casting 3 segments)', '        if (rules::weaponVsActivityOrder(4, 3) != 1 ||', '            rules::weaponVsActivityOrder(3, 3) != 0 ||', '            rules::weaponVsActivityOrder(2, 3) != -1 ||', '            rules::weaponVsActivityOrder(1, 3) != -1 ||', '            rules::weaponVsActivityOrder(0, 3) != -1 ||', '            rules::weaponVsActivityOrder(9, 3) != 1) ++bad;', '        // simultaneous: no factor modification', '        if (rules::speedFactorModifiedWhenSimultaneous())', '            ++bad;', '        printf("R158 weapon speed factors audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R158 audit block",
      marker='R158 weapon speed factors audit')
assert len(applied) + len(already) == 3

p4_old = NL.join(['lane). Census 75.', '', 'Categories:'])
p4_new = NL.join(['lane). Census 75.', 'R158 PINNED weapon speed factors in initiative (DMG', 'p.66 + the PHB p.38 factor column) - rules/weaponspeed.h:', 'the named factor table (fist 1 through pike 13; the spear', 'prints 6-8 and defaults 7, footman/horseman mace and', 'flail named per the print), the simultaneous-initiative', 'tie order (lower factor strikes first), the extra-attacks', 'rule (difference at least twice the lower factor or 5+ =', 'two attacks before the slower acts; 10+ adds a third', 'simultaneous; never when closing or charging), and the', 'weapon-vs-activity strike segment (factor minus the', 'losing initiative die, negatives as positive, no', 'modification on a tied round). rules/turn verified first:', 'the scheduler carries NO factor logic and needs none - the', 'DMG limits factor use to these caller-detected cases. The', 'fireball example (sword 5 vs casting 3, dagger 2 vs 3,', 'the two-handed no-chance) is pinned in the audit.', 'Census 76.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R158 header note",
      marker='R158 PINNED weapon speed factors')
assert len(applied) + len(already) == 4

p5_old = NL.join(['- [ ] **Weapon speed factors in initiative (p.66)** - the', '      segment scheduler exists; the speed-factor table', '      and its melee-initiative adjustments are unpinned', '      (verify against rules/turn first).'])
p5_new = NL.join(['- [x] **Weapon speed factors in initiative (p.66)** - pinned', '      by R158: rules/weaponspeed.h (the p.38 factor table,', '      the tie order, the extra-attack windows, the', '      weapon-vs-spell strike segment); rules/turn verified', '      first and deliberately untouched - the print applies', '      factors only in caller-detected cases.'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: speed factor box closed",
      marker='by R158: rules/weaponspeed.h')
assert len(applied) + len(already) == 5

# ---- R158 fails/tail ----
if fails:
    print("R158 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R158 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R158 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R158 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R158 note: 5 patches; census 76; commit: R158: weapon speed factors pinned - the initiative tie order, extra attacks, weapon-vs-spell segments (census 76)")
