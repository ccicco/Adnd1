# tools/r156_splice.py - R156, 7 patches: the Appendix P
# caller (DMG pp.225-226) - the convention-party
# generator, the next gap-report box. rollMemberMagic
# (the R147 tables) gains its first engine caller.
#
# (1) dm/appendixp.h: SpurMember + rollSpurMember - the
#     band/option level roll, the six 4d6-best-of scores,
#     the magic kit (multi-class math and alignment stay
#     player-side, per the print). (2) the include. (3)-(4)
#     dm/encounters: rollConventionParty maps the spur member
#     onto the encounter party (combat fields only; the p.176
#     rows keep their own R55 ladder - a different print,
#     not conflated). (5) the R156 audit: band/class sweeps,
#     score and kit bounds, the class clamp, size clamps,
#     the same-seed replay pin, the null-class default -
#     CENSUS 74. (6)-(7) the gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R156: Appendix P caller pinned - the
# convention-party generator (census 74)"
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

p1_old = NL.join(['} // namespace appendixp'])
p1_new = NL.join(['// ----', '// R156: THE SPUR-OF-THE-MOMENT MEMBER (pp.225-226) - the', '// convention character pre-roll: the band/option level', '// roll, the six 4d6-best-of ability scores (the book has', '// the player arrange as desired - the engine just', '// supplies the six), and the magic kit. Multi-class level', '// math and alignment curation are player-side and stay', '// out of the engine.', 'struct SpurMember {', '    int classIndex = 0;          // engine class (caller-chosen)', '    int level = 1;               // rolled in the band', '    int abilities[6] = {0, 0, 0, 0, 0, 0};   // STR INT WIS DEX CON CHA', '    MemberMagic kit;', '};', '', 'inline SpurMember rollSpurMember(rules::Dice& dice, int band,', '                                 int option, int classIndex) {', '    if (classIndex < 0) classIndex = 0;', '    if (classIndex > 3) classIndex = 3;', '    SpurMember m;', '    m.classIndex = classIndex;', '    int lo = bandLevelLo(band, option);', '    int hi = bandLevelHi(band, option);', '    m.level = lo + (int)dice.roll(1, (uint32_t)(hi - lo + 1), 0) - 1;', '    for (int i = 0; i < 6; ++i)', '        m.abilities[i] = abilityRoll(dice);', '    m.kit = rollMemberMagic(dice, classIndex, m.level);', '    return m;', '}', '', '} // namespace appendixp'])
patch("dm/appendixp.h", p1_old, p1_new,
      "appendixp.h: SpurMember + rollSpurMember",
      marker='rollSpurMember(rules::Dice& dice, int band,')
assert len(applied) + len(already) == 1

p2_old = NL.join(['CharacterParty rollCharacterParty(rules::Dice& dice,', '                                  int dungeonLevel, int monsterLevel);', '', '// R62: the p.192 race-check adjective for fiction strings'])
p2_new = NL.join(['CharacterParty rollCharacterParty(rules::Dice& dice,', '                                  int dungeonLevel, int monsterLevel);', '', '// R156: DMG Appendix P (pp.225-226) - a convention party on', '// the spur of the moment: caller-chosen classes (the book', '// has the players select race and class), levels rolled in', '// the band, and the magic kit from rollMemberMagic - the', '// R147 tables, first engine caller. Party shape: 1-9', '// members; the ability scores stay player-side (the', '// encounter party carries only the combat fields).', 'CharacterParty rollConventionParty(rules::Dice& dice, int band,', '                                   int option,', '                                   const int* classIndices,', '                                   int count);', '', '// R62: the p.192 race-check adjective for fiction strings'])
patch("dm/encounters.h", p2_old, p2_new,
      "encounters.h: rollConventionParty decl",
      marker='the spur of the moment: caller-chosen classes')
assert len(applied) + len(already) == 2

p3_old = NL.join(['#include "encounters.h"', '', '#include <algorithm>'])
p3_new = NL.join(['#include "encounters.h"', '#include "appendixp.h"   // R156: Appendix P kits, the convention party', '', '#include <algorithm>'])
patch("dm/encounters.cpp", p3_old, p3_new,
      "encounters.cpp: appendixp include",
      marker='appendixp.h"   // R156')
assert len(applied) + len(already) == 3

p4_old = NL.join(['        p.members.push_back(m);', '    }', '    return p;', '}', '', '// R62: the p.192 race-check adjective for fiction strings.'])
p4_new = NL.join(['        p.members.push_back(m);', '    }', '    return p;', '}', '', '// ----------------------------------------------------------------------------', '// R156: DMG Appendix P (pp.225-226) - the convention party on the', '// spur of the moment. rollCharacterParty rolls the p.176 subtable', '// with the R55 magic ladder; THIS generator uses the Appendix P', '// tables: caller-chosen classes (the players select in the book),', '// the band/option level roll, and the kit from rollMemberMagic -', '// the R147 tables, first engine caller. The ability scores stay', '// player-side (the encounter party carries combat fields only);', '// multi-class level math and alignment curation are player-side.', '// ----------------------------------------------------------------------------', '', 'CharacterParty rollConventionParty(rules::Dice& dice, int band,', '                                   int option,', '                                   const int* classIndices,', '                                   int count) {', '    CharacterParty p;', '    if (count < 1) count = 1;', '    if (count > 9) count = 9;   // the p.176 nine-member cap', '    for (int i = 0; i < count; ++i) {', '        appendixp::SpurMember s = appendixp::rollSpurMember(', '            dice, band, option, classIndices ? classIndices[i] : 0);', '        PartyMember m;', '        m.classIndex = s.classIndex;', '        m.level = s.level;', '        m.armPlus = s.kit.armorPlus;', '        m.wpnPlus = s.kit.weaponPlus;', '        m.shdPlus = s.kit.shieldPlus;', '        m.race = RACE_HUMAN;   // convention default (fiction-only)', '        p.members.push_back(m);', '    }', '    return p;', '}', '', '// R62: the p.192 race-check adjective for fiction strings.'])
patch("dm/encounters.cpp", p4_old, p4_new,
      "encounters.cpp: rollConventionParty impl",
      marker='the R147 tables, first engine caller')
assert len(applied) + len(already) == 4

p5_old = NL.join(['        printf("R155 classed monsters audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p5_new = NL.join(['        printf("R155 classed monsters audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R156: convention party audit --------------------', '    // DMG pp.225-226 Appendix P: rollMemberMagic gains its', '    // first engine caller - rollConventionParty builds the', '    // encounter-shaped party from caller-chosen classes, the', '    // band/option level roll, and the R147 kit tables; the', '    // member roller also lands the six 4d6-best-of scores.', '    {', '        int bad = 0;', '        // the member roller: the level stays in the band,', '        // the six scores stay in 3-18, the kit in 0-3, and', '        // the class clamps', '        {', '            rules::Rng rngC(20261004);', '            rules::Dice diceC(rngC);', '            for (int b = 0; b < 3; ++b)', '                for (int o = 0; o < 3; ++o)', '                    for (int c = 0; c < 4; ++c)', '                        for (int t = 0; t < 40; ++t) {', '                            dm::appendixp::SpurMember m =', '                                dm::appendixp::rollSpurMember(', '                                    diceC, b, o, c);', '                            if (m.classIndex != c) ++bad;', '                            if (m.level <', '                                    dm::appendixp::bandLevelLo(b, o)', '                                || m.level >', '                                    dm::appendixp::bandLevelHi(b, o))', '                                ++bad;', '                            for (int a = 0; a < 6; ++a)', '                                if (m.abilities[a] < 3 ||', '                                    m.abilities[a] > 18) ++bad;', '                            if (m.kit.armorPlus < 0 ||', '                                m.kit.armorPlus > 3 ||', '                                m.kit.weaponPlus < 0 ||', '                                m.kit.weaponPlus > 3 ||', '                                m.kit.shieldPlus < 0 ||', '                                m.kit.shieldPlus > 3) ++bad;', '                        }', '            dm::appendixp::SpurMember m9 =', '                dm::appendixp::rollSpurMember(diceC, 0, 0, 9);', '            if (m9.classIndex != 3) ++bad;', '        }', '        // the party generator: sizes clamp 1-9, each member', '        // maps its replayed spur member (same seed = the', '        // same dice stream), levels stay in the band, and a', '        // null class list lands fighters', '        {', '            rules::Rng rngA(424242);', '            rules::Dice diceA(rngA);', '            int cls[5] = {0, 1, 2, 3, 1};', '            dm::CharacterParty p =', '                dm::rollConventionParty(diceA, 1, 1, cls, 5);', '            if (p.size() != 5) ++bad;', '            rules::Rng rngB(424242);', '            rules::Dice diceB(rngB);', '            for (int i = 0; i < 5; ++i) {', '                dm::appendixp::SpurMember s =', '                    dm::appendixp::rollSpurMember(', '                        diceB, 1, 1, cls[i]);', '                const dm::PartyMember& pm = p.members[i];', '                if (pm.classIndex != s.classIndex ||', '                    pm.level != s.level ||', '                    pm.armPlus != s.kit.armorPlus ||', '                    pm.wpnPlus != s.kit.weaponPlus ||', '                    pm.shdPlus != s.kit.shieldPlus) ++bad;', '                if (pm.level < 5 || pm.level > 8) ++bad;', '            }', '            dm::CharacterParty tiny =', '                dm::rollConventionParty(diceA, 2, 2, nullptr, -3);', '            if (tiny.size() != 1) ++bad;', '            int cls9[12];', '            for (int i = 0; i < 12; ++i) cls9[i] = i % 4;', '            dm::CharacterParty big =', '                dm::rollConventionParty(diceA, 0, 0, cls9, 12);', '            if (big.size() != 9) ++bad;', '            dm::CharacterParty nul =', '                dm::rollConventionParty(diceA, 0, 2, nullptr, 3);', '            for (int i = 0; i < 3; ++i)', '                if (nul.members[i].classIndex != 0) ++bad;', '        }', '        printf("R156 convention party audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p5_old, p5_new,
      "regtest.cpp: R156 audit block",
      marker='R156 convention party audit')
assert len(applied) + len(already) == 5

p6_old = NL.join(['extras, not base-monster data. Census 73.', '', 'Categories:'])
p6_new = NL.join(['extras, not base-monster data. Census 73.', 'R156 PINNED the Appendix P caller (DMG pp.225-226) -', 'the convention-party generator: rollSpurMember rolls', 'the band/option level, the six 4d6-best-of scores and', 'the magic kit, and rollConventionParty (dm/encounters)', 'maps it onto the encounter party - rollMemberMagic,', 'the R147 tables, gain their first engine caller. The', 'multi-class level math and the alignment curation are', 'player-side (the print hands them to the table); the', 'ability scores stay player-side too - the encounter', 'party carries combat fields only. Census 74.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p6_old, p6_new,
      "gap report: R156 header note",
      marker='R156 PINNED the Appendix P caller')
assert len(applied) + len(already) == 6

p7_old = NL.join(['- [ ] **Appendix P caller (the convention-party', '      generator)** - rollMemberMagic has no caller; wire', '      it into the p.176 party rows or a dm/encounters', '      generator.'])
p7_new = NL.join(['- [x] **Appendix P caller (the convention-party', '      generator)** - pinned by R156: rollSpurMember', '      (level, the six 4d6-best-of scores, the kit) and', '      rollConventionParty in dm/encounters - the R147', '      tables, first engine caller. The p.176 subtable', '      rows keep their own R55 magic ladder (a different', '      print; not conflated).'])
patch("tools/dmg_gap_report.md", p7_old, p7_new,
      "gap report: Appendix P caller box closed",
      marker='pinned by R156: rollSpurMember')
assert len(applied) + len(already) == 7
# ---- R156 fails/tail ----
if fails:
    print("R156 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 7:
    print("R156 splice: FAIL - expected 7 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R156 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R156 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R156 note: 7 patches; the battery gains one audit")
print("line - AUDIT CENSUS 74; commit: R156: Appendix P caller")
print("pinned - the convention-party generator (census 74)")
