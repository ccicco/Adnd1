# tools/r165_splice.py - R165, 5 patches: potion
# miscibility (DMG p.119) - the interactions table for
# intermingled or stacked potions. A new header-only
# layer, rules/miscibility.h (the grenade.h pattern:
# the caller rolls the d100 secretly and owns the
# damage, saves and duration bookkeeping).
#
# (1) rules/miscibility.h: the p.119 print - test
#     whenever two potions are intermingled or a
#     potion is consumed while another is still in
#     effect; the d100 table: 01 explosion (6-60
#     internal, external mix blast 1-10 in a 5 foot
#     radius, 4-24 in a 10 foot radius, no save),
#     02-03 lethal poison (imbiber dead; external mix
#     a 10 foot poison gas cloud, save vs poison or
#     die), 04-08 mild poison (nausea, 1 point each
#     strength and dexterity lost for 5-20 rounds, no
#     save; one potion cancelled, the other at half
#     strength and duration, random which),
#     09-15 both destroyed, 16-25 one cancelled the
#     other normal, 26-35 both at half efficacy,
#     36-90 miscible (contradictory effects cancel),
#     91-99 one potion at 150 percent efficacy
#     (random which), 00 discovery (one potion only
#     functions but permanent on the imbiber, with
#     possible harmful side effects). The print
#     suggests campaign-fixed certain results (a
#     delusion potion mixes with anything, treasure
#     finding mixed with any potion is a lethal
#     poison, oil of slipperiness with etherealness
#     raises the lost-in-the-Ethereal chance to 50
#     percent for 5-30 days) - the print marks those
#     as the DM's own decisions, so they ride here
#     as named options, not data.
#     (2) the regtest include. (3) the R165 audit:
#     every band boundary pinned - CENSUS 83.
#     (4)-(5) the gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R165: potion miscibility pinned - the p.119
# interactions table (census 83)"
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

p1_text = NL.join(['// ====================================================================', '// Adnd1 - rules/miscibility.h', '// R165: potion miscibility (DMG p.119) - the', '// interactions table for intermingled or stacked', '// potions.', '//', '// Pure data, header-only (the grenade.h pattern: the', '// caller rolls the d100 secretly and owns the', '// damage, saves and duration bookkeeping).', '//', '// The p.119 print:', '//   - Test miscibility whenever (1) two potions are', '//     actually intermingled, or (2) a potion is', '//     consumed while another consumed potion is', '//     still in effect. The roll is made secretly.', '//   - The d100 bands: 01 explosion, 02-03 lethal', '//     poison, 04-08 mild poison (nausea, -1', '//     strength and -1 dexterity for 5-20 rounds,', '//     no save; one potion cancelled, the other at', '//     half strength and duration, randomly', '//     determined which), 09-15 both destroyed,', '//     16-25 one cancelled the other normal,', '//     26-35 both at half efficacy, 36-90 miscible', '//     (contradictory effects simply cancel), 91-99', '//     one potion at 150 percent efficacy,', '//     00 discovery (one potion only functions,', '//     its effect permanent on the imbiber, with', '//     possible harmful side effects).', '//   - The explosion: internal damage 6-60 hp; an', '//     external mix blasts all within a 5 foot', '//     radius for 1-10 hp and all in a 10 foot', '//     radius for 4-24 hp, no save. (The print', '//     renders the small radius as 5 double-prime', '//     feet - read as 5 feet.)', '//   - The lethal poison band: the imbiber is', '//     dead; an external mix makes a 10 foot poison', '//     gas cloud, all within saving versus poison', '//     or dying.', '//   - The print suggests campaign-fixed certain', '//     results (delusion mixes with anything,', '//     treasure finding plus any potion is lethal', '//     poison, oil of slipperiness plus oil of', '//     etherealness raising the lost-in-the-', '//     Ethereal chance to 50 percent for 5-30', '//     days) but marks them as the DMs own', '//     decisions - named options below, not table', '//     data.', '// ====================================================================', '', '#pragma once', '', 'namespace rules {', '', 'enum MiscibilityResult {', '    MISC_EXPLOSION = 0,', '    MISC_LETHAL_POISON,', '    MISC_MILD_POISON,', '    MISC_BOTH_DESTROYED,', '    MISC_ONE_CANCELLED,', '    MISC_BOTH_HALF,', '    MISC_COMPATIBLE,', '    MISC_ONE_BOOSTED,', '    MISC_DISCOVERY', '};', '', '// The p.119 d100 bands (a roll of 100 reads 00).', 'inline MiscibilityResult miscibilityRoll(int d100) {', '    if (d100 < 1) d100 = 1;', '    if (d100 > 100) d100 = 100;', '    if (d100 == 1) return MISC_EXPLOSION;', '    if (d100 <= 3) return MISC_LETHAL_POISON;', '    if (d100 <= 8) return MISC_MILD_POISON;', '    if (d100 <= 15) return MISC_BOTH_DESTROYED;', '    if (d100 <= 25) return MISC_ONE_CANCELLED;', '    if (d100 <= 35) return MISC_BOTH_HALF;', '    if (d100 <= 90) return MISC_COMPATIBLE;', '    if (d100 <= 99) return MISC_ONE_BOOSTED;', '    return MISC_DISCOVERY;', '}', '', '// The two trigger conditions: intermingled', '// potions, or a potion consumed while another is', '// still in effect.', 'inline bool miscibilityTestNeeded(', '        bool intermingled, bool otherStillInEffect) {', '    return intermingled || otherStillInEffect;', '}', '', '// The explosion damage dice (the caller rolls):', '// internal 6-60; an external mix 1-10 within a', '// 5 foot radius, 4-24 in a 10 foot radius, no', '// save for either.', 'inline int miscibilityExplosionInternalMin() { return 6; }', 'inline int miscibilityExplosionInternalMax() { return 60; }', 'inline int miscibilityExplosionBlastNearMin() { return 1; }', 'inline int miscibilityExplosionBlastNearMax() { return 10; }', 'inline int miscibilityExplosionBlastNearRadius() { return 5; }', 'inline int miscibilityExplosionBlastFarMin() { return 4; }', 'inline int miscibilityExplosionBlastFarMax() { return 24; }', 'inline int miscibilityExplosionBlastFarRadius() { return 10; }', '', '// The mild poison band: 1 point each of strength', '// and dexterity lost for 5-20 rounds, no saving', '// throw possible; one potion cancelled, the other', '// at half strength and duration (random which).', 'inline int miscibilityMildPoisonDurationMin() { return 5; }', 'inline int miscibilityMildPoisonDurationMax() { return 20; }', '', '// The lethal poison band: the imbiber dead; an', '// external mix a 10 foot poison gas cloud, save', '// versus poison or die.', 'inline int miscibilityGasCloudRadius() { return 10; }', '', '// The one-boosted band: 150 percent normal', '// efficacy on the randomly determined potion.', 'inline int miscibilityBoostPercent() { return 150; }', '', '// The named campaign options the print suggests', '// (DM decisions, not table data): delusion mixes', '// with anything; treasure finding plus any other', '// potion is lethal poison; oil of slipperiness plus', '// oil of etherealness raises the lost-in-the-', '// Ethereal chance to 50 percent for 5-30 days.', 'inline bool miscibilityOptionDelusionMixes() {', '    return true;', '}', 'inline bool miscibilityOptionTreasureFindingLethal() {', '    return true;', '}', 'inline int miscibilityOptionEtherealLostPercent() {', '    return 50;', '}', 'inline int miscibilityOptionEtherealLostMinDays() {', '    return 5;', '}', 'inline int miscibilityOptionEtherealLostMaxDays() {', '    return 30;', '}', '', '} // namespace rules', ''])
create("rules/miscibility.h", p1_text,
      "miscibility.h: the potion miscibility layer",
      marker='miscibilityRoll')
assert len(applied) + len(already) == 1

p2_old = NL.join(['#include "rules/assassinate.h"  // R164: p.75 the assassination table'])
p2_new = NL.join(['#include "rules/assassinate.h"  // R164: p.75 the assassination table', '#include "rules/miscibility.h"  // R165: p.119 potion miscibility'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: miscibility include",
      marker='rules/miscibility.h"  // R165')
assert len(applied) + len(already) == 2

p3_old = NL.join(['        printf("R164 assassination table audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join(['        printf("R164 assassination table audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R165: potion miscibility audit ------------', '    // DMG p.119: the miscibility d100 bands, the', '    // trigger conditions, the explosion and poison', '    // numbers, the boost, and the named campaign', '    // options.', '    {', '        int bad = 0;', '        // the band boundaries: probe every d100 face', '        for (int r = 1; r <= 100; ++r) {', '            rules::MiscibilityResult want;', '            if (r == 1) want = rules::MISC_EXPLOSION;', '            else if (r <= 3) want = rules::MISC_LETHAL_POISON;', '            else if (r <= 8) want = rules::MISC_MILD_POISON;', '            else if (r <= 15) want = rules::MISC_BOTH_DESTROYED;', '            else if (r <= 25) want = rules::MISC_ONE_CANCELLED;', '            else if (r <= 35) want = rules::MISC_BOTH_HALF;', '            else if (r <= 90) want = rules::MISC_COMPATIBLE;', '            else if (r <= 99) want = rules::MISC_ONE_BOOSTED;', '            else want = rules::MISC_DISCOVERY;', '            if (rules::miscibilityRoll(r) != want) ++bad;', '        }', '        // the clamps', '        if (rules::miscibilityRoll(0) != rules::MISC_EXPLOSION ||', '            rules::miscibilityRoll(-7) != rules::MISC_EXPLOSION ||', '            rules::miscibilityRoll(101) != rules::MISC_DISCOVERY ||', '            rules::miscibilityRoll(999) != rules::MISC_DISCOVERY)', '            ++bad;', '        // the trigger conditions', '        if (!rules::miscibilityTestNeeded(true, false) ||', '            !rules::miscibilityTestNeeded(false, true) ||', '            rules::miscibilityTestNeeded(false, false)) ++bad;', '        // the explosion numbers', '        if (rules::miscibilityExplosionInternalMin() != 6 ||', '            rules::miscibilityExplosionInternalMax() != 60 ||', '            rules::miscibilityExplosionBlastNearMin() != 1 ||', '            rules::miscibilityExplosionBlastNearMax() != 10 ||', '            rules::miscibilityExplosionBlastNearRadius() != 5 ||', '            rules::miscibilityExplosionBlastFarMin() != 4 ||', '            rules::miscibilityExplosionBlastFarMax() != 24 ||', '            rules::miscibilityExplosionBlastFarRadius() != 10)', '            ++bad;', '        // the mild poison duration and the gas cloud', '        if (rules::miscibilityMildPoisonDurationMin() != 5 ||', '            rules::miscibilityMildPoisonDurationMax() != 20 ||', '            rules::miscibilityGasCloudRadius() != 10) ++bad;', '        // the boost', '        if (rules::miscibilityBoostPercent() != 150) ++bad;', '        // the named campaign options', '        if (!rules::miscibilityOptionDelusionMixes() ||', '            !rules::miscibilityOptionTreasureFindingLethal() ||', '            rules::miscibilityOptionEtherealLostPercent() != 50 ||', '            rules::miscibilityOptionEtherealLostMinDays() != 5 ||', '            rules::miscibilityOptionEtherealLostMaxDays() != 30)', '            ++bad;', '        printf("R165 potion miscibility audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R165 audit block",
      marker='R165 potion miscibility audit')
assert len(applied) + len(already) == 3

p4_old = NL.join(['pattern). Census 82.', '', 'Categories:'])
p4_new = NL.join(['pattern). Census 82.', 'R165 PINNED potion miscibility (DMG p.119) -', 'rules/miscibility.h: test whenever two potions are', 'intermingled or one is consumed while another is', 'still in effect (the roll made secretly). The d100', 'bands: 01 explosion (internal 6-60 hp; an', 'external mix blasts 1-10 hp within a 5 foot', 'radius and 4-24 hp in a 10 foot radius, no save -', 'the print renders the near radius as 5 double-', 'prime feet, read as 5 feet); 02-03 lethal poison', '(the imbiber dead; an external mix a 10 foot gas', 'cloud, save versus poison or die); 04-08 mild', 'poison (nausea, -1 strength and -1 dexterity for', '5-20 rounds, no save; one potion cancelled, the', 'other at half strength and duration, random', 'which); 09-15 both destroyed; 16-25 one', 'cancelled, the other normal; 26-35 both at half', 'efficacy; 36-90 miscible (contradictory effects', 'simply cancel); 91-99 one potion at 150 percent', 'efficacy; 00 discovery (one potion only functions,', 'its effect permanent, possible harmful side', 'effects). The campaign-fixed certain results the', 'print suggests (delusion mixes with anything,', 'treasure finding plus any potion is lethal poison,', 'oil of slipperiness plus etherealness: 50 percent', 'lost in the Ethereal for 5-30 days) are named', 'options, the print marking them as the DMs own', 'decisions. The d100 roll and all damage and', 'duration bookkeeping are caller-side. Census 83.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R165 header note",
      marker='R165 PINNED potion miscibility')
assert len(applied) + len(already) == 4

p5_old = NL.join(['- [ ] **Potion miscibility (p.119)** - the interactions', '      table for drinking incompatible potions.'])
p5_new = NL.join(['- [x] **Potion miscibility (p.119)** - pinned by R165:', '      rules/miscibility.h (the d100 band table with the', '      explosion, poison and boost numbers; the trigger', '      conditions; the named campaign options).'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: miscibility box closed",
      marker='Potion miscibility (p.119)** - pinned by R165')
assert len(applied) + len(already) == 5

# ---- R165 fails/tail ----
if fails:
    print("R165 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R165 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R165 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R165 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R165 note: 5 patches; census 83; commit: R165: potion miscibility pinned - the p.119 interactions table (census 83)")
