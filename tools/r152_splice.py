# tools/r152_splice.py - R152, four patches: the DMG
# p.49 becoming-lost check pinned (the gap-report open
# box: the overland navigation check for the outdoor
# march).
#
# (1) dm/outdoormove.h - the lost section added to the
#     R123 header (the same 8 route terrains): the
#     chance in 10 per terrain, the direction
#     limitation per terrain (60 degrees on five
#     terrains, 120 on mountains, any on forest and
#     marsh) and the lost-heading mapping read
#     clockwise - no result ever the desired
#     direction, as printed. (2) the regtest.cpp R152
#     audit block (census goes 70). (3) gap report
#     header note. (4) the becoming-lost box flips
#     closed. The caller is the outdoor march (R123
#     movement rates); regtest.cpp already includes
#     outdoormove.h, so no include patch.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). This file
# contains ZERO backslash characters and no content
# string embeds a literal apostrophe (the R133b + R147
# lessons - the anchors that need them build theirs
# from chr(92) and AP).
# Commit: "R152: becoming-lost check pinned - 8 terrain
# chances, direction limits, lost-heading dice
# (census 70)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
AP = chr(39)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

# ---- (1) dm/outdoormove.h: the lost section ----
om_old = NL.join([
    '        { 35,  0, 35, 35,  0 },',
    '        { 50,  0, 40, 50,  0 },',
    '    };',
    '    return k[v][w];',
    '}',
    '',
    '} // namespace dm',
])
om_new = NL.join([
    '        { 35,  0, 35, 35,  0 },',
    '        { 50,  0, 40, 50,  0 },',
    '    };',
    '    return k[v][w];',
    '}',
    '',
    '// ----------------------------------------------------------------------------',
    '// BECOMING LOST (p.49) - the overland navigation check, keyed to',
    '// the same 8 route terrains. The chance is X in 10, rolled prior',
    '// to the commencement of a day of movement; the direction of',
    '// lost travel is read from the dice clockwise, the intended',
    '// direction of travel as 12 o clock - the book prints NO',
    '// chance of the party ever accidentally moving in the desired',
    '// direction when lost, so the mapping never returns 0.',
    '// Deterministic: any dice use is the callers.',
    '// ----------------------------------------------------------------------------',
    '',
    '// the printed direction limitation per terrain',
    'enum DirectionLimit {',
    '    DL_60 = 0,    // 60 degrees left or right',
    '    DL_120,       // 120 degrees left or right (mountains)',
    '    DL_ANY,       // any direction (forest, marsh)',
    '    DL_COUNT',
    '};',
    '',
    'inline DirectionLimit directionLimitFor(OutdoorTerrain t) {',
    '    switch (t) {',
    '        case T_FOREST:',
    '        case T_MARSH:     return DL_ANY;',
    '        case T_MOUNTAINS: return DL_120;',
    '        default:          return DL_60;',
    '    }',
    '}',
    '',
    '// the printed chance in 10 of becoming lost (p.49)',
    'inline int lostChanceIn10(OutdoorTerrain t) {',
    '    switch (t) {',
    '        case T_PLAIN:     return 1;',
    '        case T_SCRUB:     return 3;',
    '        case T_FOREST:    return 7;',
    '        case T_ROUGH:     return 3;',
    '        case T_DESERT:    return 4;',
    '        case T_HILLS:     return 2;',
    '        case T_MOUNTAINS: return 5;',
    '        case T_MARSH:     return 6;',
    '    }',
    '    return 0;',
    '}',
    '',
    '// The heading error in degrees: negative = left of the',
    '// intended direction, positive = right. d6a and d6b are',
    '// d6 rolls, clamped 1-6 (the house fold discipline).',
    '//   - DL_60:  d6a alone, 1-3 = 60 left, 4-6 = 60 right.',
    '//   - DL_120: d6a picks the side, d6b the arc (1-3 = 60,',
    '//     4-6 = 120).',
    '//   - DL_ANY: d6a alone, read clockwise: 1 = right',
    '//     ahead, 2 = right behind, 3-4 = directly behind,',
    '//     5 = left behind, 6 = left ahead.',
    'inline int lostAngleDeg(int d6a, int d6b, DirectionLimit dl) {',
    '    if (d6a < 1) d6a = 1;',
    '    if (d6a > 6) d6a = 6;',
    '    if (d6b < 1) d6b = 1;',
    '    if (d6b > 6) d6b = 6;',
    '    if (dl == DL_60) return (d6a <= 3) ? -60 : 60;',
    '    if (dl == DL_120) {',
    '        int arc = (d6b <= 3) ? 60 : 120;',
    '        return (d6a <= 3) ? -arc : arc;',
    '    }',
    '    if (d6a == 1) return 60;    // right ahead',
    '    if (d6a == 2) return 120;   // right behind',
    '    if (d6a <= 4) return 180;   // directly behind (3-4)',
    '    if (d6a == 5) return -120;  // left behind',
    '    return -60;                 // left ahead',
    '}',
    '',
    '} // namespace dm',
])

# ---- (2) regtest.cpp: the R152 audit block ----
aud_old = NL.join([
    '        printf("R151 Appendix O encumbrance audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
aud_new = NL.join([
    '        printf("R151 Appendix O encumbrance audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R152: becoming-lost check audit -------------------------------',
    '    // The DMG p.49 lost check, pinned in dm/outdoormove.h:',
    '    // the 8 terrain chances in 10, the three direction',
    '    // limitations and the lost-heading dice read clockwise',
    '    // - the book prints NO chance of the party ever',
    '    // accidentally moving in the desired direction when',
    '    // lost, so the mapping never returns 0. The dice are',
    '    // the callers; the accessors are deterministic.',
    '    {',
    '        int bad = 0;',
    '        namespace OM = dm;',
    '        // the 8 printed rows: chance in 10 and limitation',
    '        static const struct { int c; OM::DirectionLimit dl; }',
    '            kLost[] = {',
    '            { 1, OM::DL_60 },   // plain',
    '            { 3, OM::DL_60 },   // scrub',
    '            { 7, OM::DL_ANY },  // forest',
    '            { 3, OM::DL_60 },   // rough',
    '            { 4, OM::DL_60 },   // desert',
    '            { 2, OM::DL_60 },   // hills',
    '            { 5, OM::DL_120 },  // mountains',
    '            { 6, OM::DL_ANY },  // marsh',
    '        };',
    '        for (int i = 0; i < 8; ++i) {',
    '            if (OM::lostChanceIn10((OM::OutdoorTerrain)i)',
    '                != kLost[i].c) ++bad;',
    '            if (OM::directionLimitFor((OM::OutdoorTerrain)i)',
    '                != kLost[i].dl) ++bad;',
    '        }',
    '        // 60 degrees: 1-3 left, 4-6 right, both edges',
    '        if (OM::lostAngleDeg(1, 1, OM::DL_60) != -60) ++bad;',
    '        if (OM::lostAngleDeg(3, 1, OM::DL_60) != -60) ++bad;',
    '        if (OM::lostAngleDeg(4, 1, OM::DL_60) != 60) ++bad;',
    '        if (OM::lostAngleDeg(6, 1, OM::DL_60) != 60) ++bad;',
    '        // 120: the second d6 picks the arc, both edges',
    '        if (OM::lostAngleDeg(1, 3, OM::DL_120) != -60) ++bad;',
    '        if (OM::lostAngleDeg(1, 4, OM::DL_120) != -120) ++bad;',
    '        if (OM::lostAngleDeg(3, 6, OM::DL_120) != -120) ++bad;',
    '        if (OM::lostAngleDeg(4, 3, OM::DL_120) != 60) ++bad;',
    '        if (OM::lostAngleDeg(4, 4, OM::DL_120) != 120) ++bad;',
    '        if (OM::lostAngleDeg(6, 6, OM::DL_120) != 120) ++bad;',
    '        // any: single d6 read clockwise, both edges',
    '        if (OM::lostAngleDeg(1, 1, OM::DL_ANY) != 60) ++bad;',
    '        if (OM::lostAngleDeg(2, 1, OM::DL_ANY) != 120) ++bad;',
    '        if (OM::lostAngleDeg(3, 1, OM::DL_ANY) != 180) ++bad;',
    '        if (OM::lostAngleDeg(4, 1, OM::DL_ANY) != 180) ++bad;',
    '        if (OM::lostAngleDeg(5, 1, OM::DL_ANY) != -120) ++bad;',
    '        if (OM::lostAngleDeg(6, 1, OM::DL_ANY) != -60) ++bad;',
    '        // never the desired direction, every face',
    '        for (int dl = 0; dl < OM::DL_COUNT; ++dl)',
    '            for (int a = 1; a <= 6; ++a)',
    '                for (int b = 1; b <= 6; ++b)',
    '                    if (OM::lostAngleDeg(a, b,',
    '                        (OM::DirectionLimit)dl) == 0)',
    '                        ++bad;',
    '        printf("R152 becoming-lost audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])

# ---- (3) gap report: the R152 round note ----
gap_head_old = NL.join([
    'items::encumbranceBand (PHB p.38). Census 69.',
    '',
    'Categories:',
])
gap_head_new = NL.join([
    'items::encumbranceBand (PHB p.38). Census 69.',
    'R152 PINNED the becoming-lost check (DMG p.49): the',
    'dm/outdoormove.h lost section - the 8 terrain chances',
    'in 10 (plain 1 through forest 7), the three direction',
    'limitations (60 degrees on five terrains, 120 on',
    'mountains, any on forest and marsh) and the',
    'lost-heading dice read clockwise (no result ever the',
    'desired direction, as printed). The lost-party',
    'procedure (back-track, re-roll the next day, describe',
    'terrain as if on course) is judge narration, printed',
    'and named, not engine data. Census 70.',
    '',
    'Categories:',
])

# ---- (4) gap report: the becoming-lost box ----
gap_box_old = NL.join([
    '- [ ] **Chances of becoming lost (p.49)** - the overland',
    '      navigation check for the outdoor march.',
])
gap_box_new = NL.join([
    '- [x] **Chances of becoming lost (p.49)** - PINNED',
    '      R152: the dm/outdoormove.h lost section (the audit',
    '      is the regtest.cpp R152 block): the chance in 10',
    '      per terrain, the direction limitation per terrain',
    '      and the deterministic heading mapping - the dice',
    '      are the callers. The R123 movement rates next to',
    '      it are the same outdoor march this check gates.',
])

# ---- run ----
patch("dm/outdoormove.h", om_old, om_new,
      "dm/outdoormove.h: becoming-lost section",
      marker="BECOMING LOST (p.49)")
assert len(applied) + len(already) == 1
patch("regtest.cpp", aud_old, aud_new,
      "regtest.cpp: R152 becoming-lost audit",
      marker="R152 becoming-lost audit")
assert len(applied) + len(already) == 2
patch("tools/dmg_gap_report.md", gap_head_old, gap_head_new,
      "gap report: R152 header note",
      marker="R152 PINNED the becoming-lost check")
assert len(applied) + len(already) == 3
patch("tools/dmg_gap_report.md", gap_box_old, gap_box_new,
      "gap report: becoming-lost box closed",
      marker="R152: the dm/outdoormove.h lost section")
assert len(applied) + len(already) == 4
# ---- R152 fails/tail ----
if fails:
    print("R152 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 4:
    print("R152 splice: FAIL - expected 4 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R152 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R152 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R152 note: four patches; expect the battery to gain")
print("one audit line - AUDIT CENSUS 70; commit: R152:")
print("becoming-lost check pinned - 8 terrain chances,")
print("direction limits, lost-heading dice (census 70)")
