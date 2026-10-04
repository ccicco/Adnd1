# tools/r161_splice.py - R161, 5 patches: attacks with
# two weapons (DMG p.70) - the two-weapon conventions for
# attack and armor class. rules/twoweapon.h is the
# header-only layer (the grenade.h pattern).
#
# (1) rules/twoweapon.h: the p.70 print - a character
#     normally using a single weapon may use one in each
#     hand, discarding the shield option; the second
#     weapon must be a dagger or hand axe; employment is
#     always at a penalty: primary -2, secondary -4; dex
#     below 6 adds the PHB Reaction/Attacking Adjustment
#     penalties to EACH weapon attack (caller-side
#     addition); dex above 15 eases the penalties (16:
#     -1/-3, 17: 0/-2, 18: 0/-1) and never yields a
#     positive rating; the secondary weapon never acts
#     as a shield or parrying device in any event.
#     (2) the regtest include. (3) the R161 audit: the
#     penalty ladder across dex 3-18, the dagger/hand-axe
#     gate, the no-parry rule - CENSUS 79. (4)-(5) the
#     gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R161: attacks with two weapons pinned - the
# penalty ladder, the dagger/hand-axe gate, no parry
# (census 79)"
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

p1_text = NL.join(['// ====================================================================', '// Adnd1 - rules/twoweapon.h', '// R161: attacks with two weapons (DMG p.70) - the', '// two-weapon conventions for attack and armor class.', '//', '// Header-only (the grenade.h pattern): the caller', '// decides to fight two-handed and carries the flag.', '//', '// The p.70 print:', '//   - A character normally using a single weapon may', '//     choose to use one in each hand, discarding the', '//     option of using a shield.', '//   - The second weapon must be either a dagger or a', '//     hand axe.', '//   - Employment of a second weapon is always at a', '//     penalty: primary weapon -2, secondary -4.', '//   - If the user dexterity is BELOW 6, the PHB', '//     Reaction/Attacking Adjustment penalties are', '//     added to EACH weapon attack (caller-side).', '//   - If the user dexterity is ABOVE 15, the penalties', '//     ease: at 16 the secondary/primary penalty is', '//     -3/-1, at 17 -2/0, at 18 -1/0 - and this never', '//     gives a positive (bonus) rating.', '//   - The secondary weapon does not act as a shield or', '//     parrying device in any event.', '// ====================================================================', '', '#pragma once', '', '#include <cstring>', '', 'namespace rules {', '', '// The second weapon gate: dagger or hand axe only.', 'inline bool twoWeaponSecondaryAllowed(const char* name) {', '    return std::strcmp(name, "dagger") == 0', '        || std::strcmp(name, "hand axe") == 0;', '}', '', '// The penalty ladder. Primary -2, secondary -4; dex', '// above 15 eases both by (dex - 15) points, clamped so', '// the primary never goes positive (the print: 16 gives', '// -1/-3, 17 0/-2, 18 0/-1).', 'inline int twoWeaponPrimaryPenalty(int dex) {', '    int adj = (dex > 15) ? (dex - 15) : 0;', '    int p = -2 + adj;', '    return (p > 0) ? 0 : p;', '}', '', 'inline int twoWeaponSecondaryPenalty(int dex) {', '    int adj = (dex > 15) ? (dex - 15) : 0;', '    return -4 + adj;   // max -1 at dex 18: no clamp', '}', '', '// Dex below 6: the PHB Reaction/Attacking Adjustment', '// penalties are added to EACH weapon attack (the', '// caller adds its table value to both).', 'inline bool twoWeaponLowDexAddsToEach(int dex) {', '    return dex < 6;', '}', '', '// The secondary weapon never shields or parries.', 'inline bool twoWeaponSecondaryParries() {', '    return false;', '}', '', '// Fighting with a weapon in each hand discards the', '// shield option (the off hand holds the second weapon).', 'inline bool twoWeaponAllowsShield() {', '    return false;', '}', '', '} // namespace rules', ''])
create("rules/twoweapon.h", p1_text,
      "twoweapon.h: the two-weapon layer",
      marker='twoWeaponSecondaryPenalty')
assert len(applied) + len(already) == 1

p2_old = NL.join(['#include "rules/weaponless.h"  // R160: pp.72-73 weaponless combat'])
p2_new = NL.join(['#include "rules/weaponless.h"  // R160: pp.72-73 weaponless combat', '#include "rules/twoweapon.h"  // R161: p.70 attacks with two weapons'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: twoweapon include",
      marker='rules/twoweapon.h"  // R161')
assert len(applied) + len(already) == 2

p3_old = NL.join(['        printf("R160 weaponless combat audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join(['        printf("R160 weaponless combat audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R161: attacks with two weapons audit --------', '    // DMG p.70: the penalty ladder (primary -2, secondary', '    // -4, eased above dex 15, never positive), the', '    // dagger/hand-axe second-weapon gate, the no-parry', '    // rule, the low-dex add-to-each rule, the discarded', '    // shield.', '    {', '        int bad = 0;', '        // the second-weapon gate', '        if (!rules::twoWeaponSecondaryAllowed("dagger") ||', '            !rules::twoWeaponSecondaryAllowed(', '                "hand axe") ||', '            rules::twoWeaponSecondaryAllowed("long sword")', '            || rules::twoWeaponSecondaryAllowed("club") ||', '            rules::twoWeaponSecondaryAllowed("spear") ||', '            rules::twoWeaponSecondaryAllowed("")) ++bad;', '        // the penalty ladder: dex 3 through 18', '        static const int kDex[8] = { 3, 5, 6, 9, 15, 16, 17, 18 };', '        static const int kPri[8] = { -2, -2, -2, -2, -2, -1, 0, 0 };', '        static const int kSec[8] = { -4, -4, -4, -4, -4, -3, -2, -1 };', '        for (int i = 0; i < 8; ++i) {', '            if (rules::twoWeaponPrimaryPenalty(', '                    kDex[i]) != kPri[i]) ++bad;', '            if (rules::twoWeaponSecondaryPenalty(', '                    kDex[i]) != kSec[i]) ++bad;', '        }', '        // never a positive rating, even at absurd dex', '        if (rules::twoWeaponPrimaryPenalty(20) != 0 ||', '            rules::twoWeaponPrimaryPenalty(25) != 0) ++bad;', '        // the low-dex rule: dex below 6 adds to EACH', '        if (!rules::twoWeaponLowDexAddsToEach(3) ||', '            !rules::twoWeaponLowDexAddsToEach(5) ||', '            rules::twoWeaponLowDexAddsToEach(6) ||', '            rules::twoWeaponLowDexAddsToEach(9)) ++bad;', '        // the secondary weapon never shields or parries', '        if (rules::twoWeaponSecondaryParries()) ++bad;', '        // fighting two-handed discards the shield', '        if (rules::twoWeaponAllowsShield()) ++bad;', '        printf("R161 two weapons audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R161 audit block",
      marker='R161 two weapons audit')
assert len(applied) + len(already) == 3

p4_old = NL.join(['mode selection, bears grapple, monks unimpeded).', 'Census 78.', '', 'Categories:'])
p4_new = NL.join(['mode selection, bears grapple, monks unimpeded).', 'R161 PINNED attacks with two weapons (DMG p.70) -', 'rules/twoweapon.h: one weapon in each hand (the shield', 'option discarded), the second weapon a dagger or hand', 'axe only, the penalty ladder (primary -2, secondary', '-4; eased above dex 15 - 16: -1/-3, 17: 0/-2, 18:', '0/-1 - never a positive rating), dex below 6 adding', 'the PHB Reaction/Attacking Adjustment to EACH attack', '(caller-side), and the secondary weapon never acting', 'as a shield or parrying device. Census 79.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R161 header note",
      marker='R161 PINNED attacks with two weapons')
assert len(applied) + len(already) == 4

p5_old = NL.join(['- [ ] **Attacks with two weapons (p.70)** - the R7', '      double-attack named leader: the two-weapon', '      conventions for attack and armor class.'])
p5_new = NL.join(['- [x] **Attacks with two weapons (p.70)** - pinned by', '      R161: rules/twoweapon.h (the dagger/hand-axe', '      gate, the penalty ladder with the dex easing,', '      the low-dex add-to-each rule, no shield or', '      parry from the second weapon).'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: two weapons box closed",
      marker='Attacks with two weapons (p.70)** - pinned by')
assert len(applied) + len(already) == 5

# ---- R161 fails/tail ----
if fails:
    print("R161 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R161 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R161 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R161 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R161 note: 5 patches; census 79; commit: R161: attacks with two weapons pinned - the penalty ladder, the dagger/hand-axe gate, no parry (census 79)")
