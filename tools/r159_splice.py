# tools/r159_splice.py - R159, 5 patches: striking to
# subdue (DMG p.67) - the knockout procedure and subdual
# damage accounting, plus the MM dragon-subdual capture
# mechanics. rules/subdue.h is the header-only subdual
# layer (the grenade.h pattern).
#
# (1) rules/subdue.h: the DMG p.67 rules - subdual
#     strikes use the flat, butt, haft or pommel but are
#     otherwise the same as other attacks; effective
#     against MM-stated monsters and creatures of
#     humanoid size and type; NOT against player
#     characters; 75% of subduing damage is temporary,
#     25% real (the print example: 40 subdual = 10
#     real). JUDGMENT: the knockout - cumulative subdual
#     damage meets or exceeds the creature remaining hit
#     points. Plus the MM dragon rules: announce intent
#     before combat (killing form otherwise, no change
#     once chosen); silver, gold, chromatic and platinum
#     dragons cannot be subdued (brass, bronze and copper
#     can); attackers of less than average intelligence
#     cannot strike to subdue; the percent ratio (cum
#     subdual over dragon hit points, half rounds up),
#     percentile <= percent subdues, 100% automatic; the
#     sale price 100-800 gp per hit point by d8. (2) the
#     regtest include. (3) the R159 audit: the 75/25
#     pins, the MM example rounds (44/88 = 50%, 67/88 =
#     76%, 77/88 = 88%, 88/88 automatic), the dragon kind
#     truth table, the int gate, the price sweep - CENSUS
#     77. (4)-(5) the gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R159: striking to subdue pinned - the 75/25
# accounting, the knockout threshold, dragon subdual
# (census 77)"
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

p1_text = NL.join(['// ====================================================================', '// Adnd1 - rules/subdue.h', '// R159: striking to subdue - the knockout procedure and', '// subdual damage accounting (DMG p.67), plus the MM', '// dragon-subdual capture mechanics.', '//', '// Header-only (the grenade.h pattern): the caller', '// announces intent and carries the cumulative tally.', '//', '// DMG p.67 print:', '//   - Subdual strikes use the flat, butt, haft, pommel or', '//     other non-lethal parts of the weapon concerned, but', '//     are otherwise the same as other attacks.', '//   - Effective against monsters the MONSTER MANUAL states', '//     (under DRAGONS) or herein, and creatures of humanoid', '//     size and type.', '//   - NOT against player characters (unless expressly', '//     stated otherwise).', '//   - 75% of subduing damage is temporary; 25% is real', '//     damage. The print example: 40 hit points of subduing', '//     damage = 10 hit points actually suffered.', '//   JUDGMENT: the knockout - the creature is subdued when', '//   cumulative subduing damage meets or exceeds its', '//   remaining hit points (the standard reading; the print', '//   implies but does not state the threshold).', '//', '// MM dragon subdual:', '//   - The attack form (kill or subdue) is announced before', '//     combat; unannounced reads as killing, and the choice', '//     cannot change for a given dragon.', '//   - Silver, gold, chromatic and platinum dragons cannot', '//     be subdued (the MM names them; brass, bronze and', '//     copper dragons can).', '//   - Creatures of less than average intelligence cannot', '//     attack to subdue. JUDGMENT: average = 9 (the MM', '//     ability score spread).', '//   - Each melee round the cumulative subduing damage is', '//     ratioed over the dragon hit points as a percentage;', '//     percentile dice equal or under subdue. 100% (the', '//     ratio at or past 1:1) is automatic. The MM example', '//     rounds: 44/88 = 50%, 67/88 = 76%, 77/88 = 87.5', '//     treated as 88% - halves round up, otherwise nearest.', '//   - Sale price of a subdued dragon: 100-800 gold pieces', '//     per hit point, offers typically by d8 (JUDGMENT:', '//     100 x d8). Subdued dragons can be ridden; the length', '//     of subdual and loyalty factors are caller-side.', '// ====================================================================', '', '#pragma once', '', '#include "dice.h"', '', 'namespace rules {', '', '// ----------------------------------------------------------------------------', '// The DMG p.67 accounting', '// ----------------------------------------------------------------------------', 'inline int subdualTemporaryPct() { return 75; }', 'inline int subdualRealPct()     { return 25; }', '', '// Real damage actually suffered from CUMULATIVE subdual', '// damage: the quarter, floored (per-hit minimums would', '// over-penalize small strikes; the print ratios the total).', 'inline int subdualRealDamage(int cumulativeSubdualHp) {', '    if (cumulativeSubdualHp <= 0) return 0;', '    return cumulativeSubdualHp / 4;', '}', '', '// Applicability: an MM-stated monster, or a creature of', '// humanoid size and type. Player characters are excluded', '// unless a rule expressly states otherwise.', 'inline bool subdualEffectiveAgainst(bool mmStatedOrHumanoid,', '                                   bool isPlayerCharacter) {', '    if (isPlayerCharacter) return false;', '    return mmStatedOrHumanoid;', '}', '', '// JUDGMENT: the knockout - cumulative subduing damage at', '// or past the remaining hit points subdues the creature.', 'inline bool subdualKnockout(int cumulativeSubdualHp,', '                            int remainingHp) {', '    if (remainingHp <= 0) return true;', '    return cumulativeSubdualHp >= remainingHp;', '}', '', '// ----------------------------------------------------------------------------', '// The MM dragon rules', '// ----------------------------------------------------------------------------', 'enum DragonSubdualKind {', '    DRAGON_BRASS = 0,', '    DRAGON_BRONZE,', '    DRAGON_COPPER,', '    DRAGON_WHITE,', '    DRAGON_BLACK,', '    DRAGON_GREEN,', '    DRAGON_BLUE,', '    DRAGON_RED,', '    DRAGON_SILVER,', '    DRAGON_GOLD,', '    DRAGON_PLATINUM,', '    DRAGON_KIND_COUNT', '};', '', '// Silver, gold, chromatic (white/black/green/blue/red) and', '// platinum cannot be subdued - the MM print; brass,', '// bronze and copper can.', 'inline bool dragonSubduable(DragonSubdualKind k) {', '    switch (k) {', '        case DRAGON_BRASS:', '        case DRAGON_BRONZE:', '        case DRAGON_COPPER:', '            return true;', '        default:', '            return false;', '    }', '}', '', '// Attackers of less than average intelligence cannot', '// strike to subdue. JUDGMENT: average = 9.', 'inline bool subduableByAttackerInt(int intelligence) {', '    return intelligence >= 9;', '}', '', '// The attack form must be announced before combat;', '// unannounced reads as killing, and the form cannot change', '// for a given target. The caller carries the flag.', 'inline bool subdualFormIsKilling(bool announcedBeforeCombat) {', '    return !announcedBeforeCombat;', '}', '', '// The percent chance: cumulative subduing damage over', '// the dragon hit points, as a percentage rounded to', '// nearest with halves up (the MM example: 67/88 = 76,', '// 77/88 = 88, 44/88 = 50).', 'inline int dragonSubdualPercent(int cumulativeSubdualHp,', '                                int dragonHp) {', '    if (dragonHp <= 0) return 100;', '    return (100 * cumulativeSubdualHp + dragonHp / 2)', '           / dragonHp;', '}', '', '// The percentile roll: equal or under the percent', '// subdues; 100% (cumulative >= hit points) is automatic.', 'inline bool dragonSubdued(Dice& dice, int cumulativeSubdualHp,', '                           int dragonHp) {', '    if (dragonHp > 0 && cumulativeSubdualHp >= dragonHp)', '        return true;', '    int pct = dragonSubdualPercent(cumulativeSubdualHp,', '                                   dragonHp);', '    int roll = (int)dice.roll(1, 100, 0);', '    return roll <= pct;', '}', '', '// The sale price per hit point: 100-800 gp by d8.', 'inline int subduedDragonPricePerHp(Dice& dice) {', '    return 100 * (int)dice.d8();', '}', '', '// Subdued dragons can be ridden.', 'inline bool subduedDragonRideable() { return true; }', '', '} // namespace rules', ''])
create("rules/subdue.h", p1_text,
      "subdue.h: the subdual layer",
      marker='DRAGON_KIND_COUNT')
assert len(applied) + len(already) == 1

p2_old = NL.join(['#include "rules/weaponspeed.h"  // R158: p.66 weapon speed factors'])
p2_new = NL.join(['#include "rules/weaponspeed.h"  // R158: p.66 weapon speed factors', '#include "rules/subdue.h"  // R159: p.67 striking to subdue'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: subdue include",
      marker='rules/subdue.h"  // R159')
assert len(applied) + len(already) == 2

p3_old = NL.join(['        printf("R158 weapon speed factors audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join(['        printf("R158 weapon speed factors audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R159: striking to subdue audit ---------------', '    // DMG p.67: the 75/25 accounting, applicability, the', '    // knockout threshold; the MM dragon capture: the kind', '    // table, the int gate, the percent ratio (the example', '    // rounds), the automatic subdual, the sale price.', '    {', '        int bad = 0;', '        // the 75/25 accounting', '        if (rules::subdualTemporaryPct() != 75 ||', '            rules::subdualRealPct() != 25) ++bad;', '        if (rules::subdualRealDamage(40) != 10) ++bad;', '        if (rules::subdualRealDamage(8) != 2 ||', '            rules::subdualRealDamage(4) != 1 ||', '            rules::subdualRealDamage(1) != 0 ||', '            rules::subdualRealDamage(0) != 0 ||', '            rules::subdualRealDamage(-5) != 0) ++bad;', '        // applicability: MM-stated or humanoid, never PCs', '        if (!rules::subdualEffectiveAgainst(true, false) ||', '            rules::subdualEffectiveAgainst(false, false) ||', '            rules::subdualEffectiveAgainst(true, true))', '            ++bad;', '        // the knockout threshold', '        if (!rules::subdualKnockout(10, 10) ||', '            !rules::subdualKnockout(11, 10) ||', '            rules::subdualKnockout(9, 10) ||', '            !rules::subdualKnockout(3, 0)) ++bad;', '        // the dragon kind table', '        if (!rules::dragonSubduable(rules::DRAGON_BRASS) ||', '            !rules::dragonSubduable(rules::DRAGON_BRONZE) ||', '            !rules::dragonSubduable(rules::DRAGON_COPPER) ||', '            rules::dragonSubduable(rules::DRAGON_WHITE) ||', '            rules::dragonSubduable(rules::DRAGON_BLACK) ||', '            rules::dragonSubduable(rules::DRAGON_GREEN) ||', '            rules::dragonSubduable(rules::DRAGON_BLUE) ||', '            rules::dragonSubduable(rules::DRAGON_RED) ||', '            rules::dragonSubduable(rules::DRAGON_SILVER) ||', '            rules::dragonSubduable(rules::DRAGON_GOLD) ||', '            rules::dragonSubduable(rules::DRAGON_PLATINUM))', '            ++bad;', '        // the attacker int gate (average = 9)', '        if (rules::subduableByAttackerInt(8) ||', '            !rules::subduableByAttackerInt(9) ||', '            !rules::subduableByAttackerInt(12)) ++bad;', '        // the announce-before-combat convention', '        if (!rules::subdualFormIsKilling(false) ||', '            rules::subdualFormIsKilling(true)) ++bad;', '        // the percent ratio: the MM example rounds', '        if (rules::dragonSubdualPercent(44, 88) != 50 ||', '            rules::dragonSubdualPercent(67, 88) != 76 ||', '            rules::dragonSubdualPercent(77, 88) != 88 ||', '            rules::dragonSubdualPercent(0, 88) != 0 ||', '            rules::dragonSubdualPercent(1, 8) != 13 ||', '            rules::dragonSubdualPercent(88, 88) != 100 ||', '            rules::dragonSubdualPercent(176, 88) != 200) ++bad;', '        // percentile sweep + the automatic subdual', '        {', '            rules::Rng rngS(20261006);', '            rules::Dice diceS(rngS);', '            int hi = 0, loSeen = false, hiSeen = false;', '            for (int t = 0; t < 600; ++t) {', '                int roll = (int)diceS.roll(1, 100, 0);', '                if (roll < 1 || roll > 100) ++bad;', '                if (roll > hi) hi = roll;', '            }', '            // a 100% ratio: every roll subdues', '            for (int t = 0; t < 50; ++t)', '                if (!rules::dragonSubdued(diceS, 88, 88)) ++bad;', '            // the MM example states: automatic at 1:1', '            if (!rules::dragonSubdued(diceS, 88, 88)) ++bad;', '            // a 0% ratio: only a rolled 1 edge (roll 1 <= 0', '            // is false; nothing subdues)', '            for (int t = 0; t < 50; ++t)', '                if (rules::dragonSubdued(diceS, 0, 88)) ++bad;', '            // price sweep: 100-800 gp per hit point', '            for (int t = 0; t < 200; ++t) {', '                int p = rules::subduedDragonPricePerHp(diceS);', '                if (p < 100 || p > 800 || p % 100 != 0) ++bad;', '            }', '            (void)hi; (void)loSeen; (void)hiSeen;', '        }', '        if (!rules::subduedDragonRideable()) ++bad;', '        printf("R159 striking to subdue audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R159 audit block",
      marker='R159 striking to subdue audit')
assert len(applied) + len(already) == 3

p4_old = NL.join(['Census 76.', '', 'Categories:'])
p4_new = NL.join(['Census 76.', 'R159 PINNED striking to subdue (DMG p.67 + the MM', 'dragon rules) - rules/subdue.h: the flat/butt/haft/', 'pommel strike (otherwise a normal attack), the 75/25', 'accounting (the print example 40 subdual = 10 real,', 'cumulative, floored), applicability (MM-stated or', 'humanoid size and type, never player characters), and', 'the knockout JUDGMENT (cumulative subdual meets or', 'exceeds remaining hit points). Dragon capture: announce', 'intent before combat (killing form otherwise, fixed', 'per dragon), silver/gold/chromatic/platinum unsubduable', '(brass, bronze, copper can be), the average-or-better', 'attacker intelligence gate (JUDGMENT: 9), the percent', 'ratio with halves up (the MM example 44/88 = 50, 67/88', '= 76, 77/88 = 88), the automatic 1:1 subdual, the', '100-800 gp per hit point d8 sale price, and the ridden', 'convention. Census 77.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R159 header note",
      marker='R159 PINNED striking to subdue')
assert len(applied) + len(already) == 4

p5_old = NL.join(['- [ ] **Striking to subdue (p.67)** - the knockout', '      procedure and subdual damage accounting.'])
p5_new = NL.join(['- [x] **Striking to subdue (p.67)** - pinned by R159:', '      rules/subdue.h (the 75/25 accounting, applicability,', '      the knockout threshold, and the MM dragon capture:', '      the kind table, the int gate, the percent ratio,', '      the automatic subdual, the sale price).'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: subdue box closed",
      marker='**Striking to subdue (p.67)** - pinned by R159')
assert len(applied) + len(already) == 5

# ---- R159 fails/tail ----
if fails:
    print("R159 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R159 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R159 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R159 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R159 note: 5 patches; census 77; commit: R159: striking to subdue pinned - the 75/25 accounting, the knockout threshold, dragon subdual (census 77)")
