# tools/r155_splice.py - R155, 20 patches: matrix II.C
# (DMG p.80) - the classed monsters pin, the R147-named
# gap. A monster whose write-up gives it class abilities
# saves on its MOST FAVORABLE matrix (footnotes 1-2).
#
# (1)-(2) rules/saves: the SAVE_AS_* class bits and
#     mostFavorableSaveTarget (the min over the masked
#     class matrices, each at its own level, vs the base
#     II.B fighter target). (3)-(4) spelleffects: the
#     TargetDesc saveAs fields + trySave mins the classed
#     save. (5)-(7) ai: the Actor fields, asTarget and
#     trySaveVs parity. (8) MonsterDef. (9)-(10) the parseSaveAs
#     helper (the Lua saveAs key - "cleric 9" / "magic-user 5,
#     cleric 7") and the magicResistance fix (a save-as note
#     is not a percent; the displacer read as 12% MR before).
#     (11)-(12) the parse + toActor copy. (13)-(17) the five MM1
#     classed write-ups (brownie, dolphin, displacer
#     beast, couatl, ki-rin) gain saveAs in their lua
#     files - NOTE: the files carry the regenerate-
#     instead header; the saveAs lines ride the MM1 data
#     pass, regenerating without them would lose the
#     pin. (18) the R155 audit: hand-computed matrix I
#     min cells (couatl, brownie, the zero-bit skip), the
#     five registry defs, the actor/target carry - CENSUS
#     73. (19)-(20) the gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R155: classed monsters pinned - matrix II.C
# most-favorable saves, the saveAs data pass (census 73)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
AP = chr(39)
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

p1_old = NL.join(['int monsterSaveLevel(float hitDice);'])
p1_new = NL.join(['// ----------------------------------------------------------------------------', '// R155: DMG p.80 matrix II.C - classed monsters. A monster whose', '// write-up gives it class abilities saves on its MOST FAVORABLE', '// matrix (footnotes 1-2: the best class score, or the matrix of', '// its area of ability). The Lua saveAs key parses into these class', '// bits with per-class levels (couatl: MU 5 AND cleric 7).', '// ----------------------------------------------------------------------------', 'const int SAVE_AS_FIGHTER     = 1;', 'const int SAVE_AS_MAGIC_USER  = 2;', 'const int SAVE_AS_CLERIC      = 4;', 'const int SAVE_AS_THIEF       = 8;', '', '// R155: the min target over the classes in the mask (each at its', '// own level, levels[classIndex]) vs the base class/level target -', '// the II.B fighter-matrix convention stays in the min. mask 0 (or', '// no usable bits) returns the plain base target.', 'int mostFavorableSaveTarget(int classMask, const int* levels,', '                            int baseClass, int baseLevel,', '                            SaveCategory cat);', '', 'int monsterSaveLevel(float hitDice);'])
patch("rules/saves.h", p1_old, p1_new,
      "saves.h: II.C class bits + mostFavorableSaveTarget decl",
      marker='SAVE_AS_FIGHTER     = 1')
assert len(applied) + len(already) == 1

p2_old = NL.join(['// Monster HD -> save level (DMG p.80 matrix II.B): hit dice equate to'])
p2_new = NL.join(['// ----------------------------------------------------------------------------', '// R155: matrix II.C most-favorable matrix - a classed monster', '// saves at the BEST score across its class matrices (each class at', '// its own level) vs the base target; the II.B fighter matrix stays', '// in the min (a classed foe never saves WORSE than the matrix II', '// convention).', '// ----------------------------------------------------------------------------', '', 'int mostFavorableSaveTarget(int classMask, const int* levels,', '                            int baseClass, int baseLevel,', '                            SaveCategory cat) {', '    int best = saveTarget(baseClass, baseLevel, cat);', '    for (int ci = 0; ci < 4; ++ci) {', '        if (!(classMask & (1 << ci))) continue;', '        if (!levels || levels[ci] < 1) continue;', '        int t = saveTarget(ci, levels[ci], cat);', '        if (t < best) best = t;', '    }', '    return best;', '}', '', '// ----------------------------------------------------------------------------', '// Monster HD -> save level (DMG p.80 matrix II.B): hit dice equate to'])
patch("rules/saves.cpp", p2_old, p2_new,
      "saves.cpp: mostFavorableSaveTarget impl",
      marker='never saves WORSE')
assert len(applied) + len(already) == 2

p3_old = NL.join(['    int saveDwarfBonus = 0;'])
p3_new = NL.join(['    // R155: matrix II.C (DMG p.80) - classed monsters save on', '    // their most favorable matrix; saveAsLevels[i] is the level', '    // for class index i (couatl: MU 5, cleric 7).', '    int saveAsMask = 0;', '    int saveAsLevels[4] = {0, 0, 0, 0};', '    int saveDwarfBonus = 0;'])
patch("spelleffects/spelleffects.h", p3_old, p3_new,
      "spelleffects.h: TargetDesc saveAs fields",
      marker='most favorable matrix; saveAsLevels[i]')
assert len(applied) + len(already) == 3

p4_old = NL.join(['    int target = rules::saveTarget(t.saveClass, lvl,', '                                   (rules::SaveCategory)s.saveCategory);'])
p4_new = NL.join(['    int target = rules::saveTarget(t.saveClass, lvl,', '                                   (rules::SaveCategory)s.saveCategory);', '    // R155: matrix II.C - a classed monster saves on its most', '    // favorable matrix; saveBonus carries the monster die bonus', '    // (displacer beast +2).', '    if (t.saveAsMask)', '        target = rules::mostFavorableSaveTarget(', '            t.saveAsMask, t.saveAsLevels, t.saveClass, lvl,', '            (rules::SaveCategory)s.saveCategory);'])
patch("spelleffects/spelleffects.cpp", p4_old, p4_new,
      "spelleffects.cpp: trySave II.C min",
      marker='displacer beast +2')
assert len(applied) + len(already) == 4

p5_old = NL.join(['    int   magicResistPct = 0;'])
p5_new = NL.join(['    int   magicResistPct = 0;', '', '    // R155: matrix II.C (DMG p.80) - classed-monster saves, set', '    // by the registry from the Lua saveAs / saveAsBonus keys.', '    int   saveAsMask = 0;', '    int   saveAsLevels[4] = {0, 0, 0, 0};', '    int   saveAsBonus = 0;'])
patch("ai/actor.h", p5_old, p5_new,
      "actor.h: Actor saveAs fields",
      marker='Lua saveAs / saveAsBonus keys')
assert len(applied) + len(already) == 5

p6_old = NL.join(['    t.saveBonus = 0;'])
p6_new = NL.join(['    // R155: matrix II.C - the registry saveAs fields ride the', '    // target descriptor; the monster die bonus (displacer) rides', '    // saveBonus.', '    t.saveBonus = (!isCharacter) ? saveAsBonus : 0;', '    t.saveAsMask = (!isCharacter) ? saveAsMask : 0;', '    if (!isCharacter) {', '        for (int i = 0; i < 4; ++i)', '            t.saveAsLevels[i] = saveAsLevels[i];', '    }'])
patch("ai/actor.cpp", p6_old, p6_new,
      "actor.cpp: asTarget carries saveAs",
      marker='t.saveBonus = (!isCharacter) ? saveAsBonus : 0;')
assert len(applied) + len(already) == 6

p7_old = NL.join(['        int target = rules::saveTarget(', '            defender.isCharacter ? defender.classIndex : 0,', '            lvl,', '            (rules::SaveCategory)saveCategory);'])
p7_new = NL.join(['        int target = rules::saveTarget(', '            defender.isCharacter ? defender.classIndex : 0,', '            lvl,', '            (rules::SaveCategory)saveCategory);', '        // R155: matrix II.C parity with spelleffects::trySave -', '        // a classed defender saves on its most favorable matrix.', '        if (!defender.isCharacter && defender.saveAsMask)', '            target = rules::mostFavorableSaveTarget(', '                defender.saveAsMask, defender.saveAsLevels,', '                0, lvl, (rules::SaveCategory)saveCategory);'])
patch("ai/actor.cpp", p7_old, p7_new,
      "actor.cpp: trySaveVs II.C min",
      marker='II.C parity with spelleffects::trySave')
assert len(applied) + len(already) == 7

p8_old = NL.join(['    int   magicResist = 0;         // Lua magicResistance "25%" -> 25'])
p8_new = NL.join(['    int   magicResist = 0;         // Lua magicResistance "25%" -> 25', '', '    // R155: matrix II.C (DMG p.80) - classed-monster saves:', '    // saveAs ("cleric 9" / "magic-user 5, cleric 7") parses into', '    // class bits with per-class levels; saveAsBonus is a flat die', '    // bonus (displacer +2).', '    int   saveAsMask = 0;', '    int   saveAsLevels[4] = {0, 0, 0, 0};', '    int   saveAsBonus = 0;'])
patch("monsters/MonsterRegistry.h", p8_old, p8_new,
      "MonsterRegistry.h: MonsterDef saveAs fields",
      marker='class bits with per-class levels; saveAsBonus')
assert len(applied) + len(already) == 8

p9_old = NL.join(['        v = firstIntIn(s, 0);', '    }', '    lua_pop(L, 1);', '    return v;', '}'])
p9_new = NL.join(['        v = firstIntIn(s, 0);', '    }', '    lua_pop(L, 1);', '    return v;', '}', '', '// R155: matrix II.C saveAs - "cleric 9" / "magic-user 5, cleric 7"', '// parses into class bits + per-class levels (class names in the', '// CharClass order: fighter, magic-user, cleric, thief).', 'void parseSaveAs(const std::string& s, int& mask, int* levels) {', '    mask = 0;', '    for (int i = 0; i < 4; ++i) levels[i] = 0;', '    static const char* const kNames[4] = {', '        "fighter", "magic-user", "cleric", "thief"', '    };', '    size_t pos = 0;', '    while (pos <= s.size()) {', '        size_t comma = s.find(",", pos);', '        std::string tok = s.substr(', '            pos, comma == std::string::npos', '                    ? std::string::npos : comma - pos);', '        size_t b = tok.find_first_not_of(" ");', '        if (b == std::string::npos) break;', '        size_t e = tok.find_last_not_of(" ");', '        tok = tok.substr(b, e - b + 1);', '        for (int i = 0; i < 4; ++i) {', '            std::string name = kNames[i];', '            if (tok.compare(0, name.size(), name) != 0) continue;', '            int lvl = firstIntIn(tok.substr(name.size()), 0);', '            if (lvl >= 1) { mask |= (1 << i); levels[i] = lvl; }', '            break;', '        }', '        if (comma == std::string::npos) break;', '        pos = comma + 1;', '    }', '}'])
patch("monsters/MonsterRegistry.cpp", p9_old, p9_new,
      "MonsterRegistry.cpp: parseSaveAs helper",
      marker='parses into class bits + per-class levels')
assert len(applied) + len(already) == 9

p10_old = NL.join(['        // "25%" -> 25; "Standard"/"Nil"/"See below" -> 0 (no innate %)', '        v = firstIntIn(s, 0);'])
p10_new = NL.join(['        // "25%" -> 25; "Standard"/"Nil"/"See below" -> 0 (no', '        // innate %). R155: a matrix II.C "Save as ..." note is', '        // not a percent - the old firstIntIn read the 12th-level', '        // displacer write-up as 12% magic resistance.', '        std::string low;', '        for (size_t i = 0; i < s.size() && i < 7; ++i)', '            low += (char)tolower((unsigned char)s[i]);', '        if (low == "save as")', '            v = 0;', '        else', '            v = firstIntIn(s, 0);'])
patch("monsters/MonsterRegistry.cpp", p10_old, p10_new,
      "MonsterRegistry.cpp: magicResistance save-as fix",
      marker='not a percent - the old firstIntIn')
assert len(applied) + len(already) == 10

p11_old = NL.join(['    else', '        def.magicResist = luaGetInt(L, "magicResist", 0);'])
p11_new = NL.join(['    else', '        def.magicResist = luaGetInt(L, "magicResist", 0);', '', '    // ---- R155: matrix II.C saveAs (DMG p.80; the MM1 save-as', '    // write-ups) + the flat die bonus ----', '    parseSaveAs(luaGetStr(L, "saveAs", ""),', '                def.saveAsMask, def.saveAsLevels);', '    def.saveAsBonus = luaGetInt(L, "saveAsBonus", 0);'])
patch("monsters/MonsterRegistry.cpp", p11_old, p11_new,
      "MonsterRegistry.cpp: parse the saveAs key",
      marker='R155: matrix II.C saveAs (DMG p.80')
assert len(applied) + len(already) == 11

p12_old = NL.join(['    a.magicResistPct = def->magicResist;'])
p12_new = NL.join(['    a.magicResistPct = def->magicResist;', '    // R155: matrix II.C - the saveAs fields ride the actor', '    a.saveAsMask = def->saveAsMask;', '    for (int i = 0; i < 4; ++i)', '        a.saveAsLevels[i] = def->saveAsLevels[i];', '    a.saveAsBonus = def->saveAsBonus;'])
patch("monsters/MonsterRegistry.cpp", p12_old, p12_new,
      "MonsterRegistry.cpp: toActor copies saveAs",
      marker='the saveAs fields ride the actor')
assert len(applied) + len(already) == 12

p13_old = NL.join(['  magicResistance = "As above",'])
p13_new = NL.join(['  magicResistance = "As above",', '  saveAs = "cleric 9",'])
patch("monsters/monsters/b/brownie.lua", p13_old, p13_new,
      "brownie.lua: saveAs cleric 9",
      marker='saveAs = "cleric 9"')
assert len(applied) + len(already) == 13

p14_old = NL.join(['  magicResistance = "standard",'])
p14_new = NL.join(['  magicResistance = "standard",', '  saveAs = "fighter 4",'])
patch("monsters/monsters/d/dolphin.lua", p14_old, p14_new,
      "dolphin.lua: saveAs fighter 4",
      marker='saveAs = "fighter 4"')
assert len(applied) + len(already) == 14

p15_old = NL.join(['  magicResistance = "Save as 12th level fighter +2 on die",'])
p15_new = NL.join(['  magicResistance = "Save as 12th level fighter +2 on die",', '  saveAs = "fighter 12",', '  saveAsBonus = 2,'])
patch("monsters/monsters/d/displacer_beast.lua", p15_old, p15_new,
      "displacer_beast.lua: saveAs fighter 12 +2",
      marker='saveAs = "fighter 12"')
assert len(applied) + len(already) == 15

p16_old = NL.join(['  specialDefenses = "become ethereal",'])
p16_new = NL.join(['  specialDefenses = "become ethereal",', '  saveAs = "magic-user 5, cleric 7",'])
patch("monsters/monsters/c/couatl.lua", p16_old, p16_new,
      "couatl.lua: saveAs MU 5, cleric 7",
      marker='saveAs = "magic-user 5, cleric 7"')
assert len(applied) + len(already) == 16

p17_old = NL.join(['  magicResistance = "90%",'])
p17_new = NL.join(['  magicResistance = "90%",', '  saveAs = "magic-user 18",'])
patch("monsters/monsters/k/ki_rin.lua", p17_old, p17_new,
      "ki_rin.lua: saveAs magic-user 18",
      marker='saveAs = "magic-user 18"')
assert len(applied) + len(already) == 17

p18_old = NL.join(['        printf("R154 PC races audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p18_new = NL.join(['        printf("R154 PC races audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R155: classed monsters audit ------------------------', '    // DMG p.80 matrix II.C: a monster with class abilities', '    // saves on its MOST FAVORABLE matrix (footnotes 1-2). The', '    // five MM1 classed write-ups (brownie, dolphin, displacer', '    // beast, couatl, ki-rin) pin the saveAs data pass: the Lua', '    // key parses into class bits + per-class levels, the +2', '    // displacer die bonus rides the actor saveBonus, and the', '    // displacer magicResistance no longer misreads as 12% MR.', '    // Judgment left for a later lane: ixitxachitl (clerical,', '    // per-leader) and the humanoid classed LEADERS are', '    // per-encounter extras, not base-monster data.', '    {', '        int bad = 0;', '        // the couatl cell: MU 5 AND cleric 7 vs a fighter-6', '        // base - matrix I rows: F6 {11,13,12,13,14}, MU5', '        // {14,11,13,15,12}, C7 {7,11,10,13,12}; min', '        // {7,11,10,13,12}', '        int lvls[4] = {0, 5, 7, 0};', '        static const int kCouatl[5] = { 7, 11, 10, 13, 12 };', '        for (int c = 0; c < 5; ++c)', '            if (rules::mostFavorableSaveTarget(', '                    rules::SAVE_AS_MAGIC_USER | rules::SAVE_AS_CLERIC,', '                    lvls, 0, 6,', '                    (rules::SaveCategory)c) != kCouatl[c])', '                ++bad;', '        // the brownie cell: cleric 9 beats a fighter-3 base', '        // (F3 = the 1-2 band row {13,15,14,16,16})', '        int bl[4] = {0, 0, 9, 0};', '        static const int kBrownie[5] = { 7, 11, 10, 13, 12 };', '        for (int c = 0; c < 5; ++c) {', '            if (rules::mostFavorableSaveTarget(', '                    rules::SAVE_AS_CLERIC, bl, 0, 3,', '                    (rules::SaveCategory)c) != kBrownie[c])', '                ++bad;', '            if (rules::mostFavorableSaveTarget(0, bl, 0, 3,', '                    (rules::SaveCategory)c) !=', '                    rules::saveTarget(0, 3, (rules::SaveCategory)c))', '                ++bad;', '        }', '        // the zero-bit skip: a set bit with level 0 must not', '        // tighten the fighter 0-level row (spells 19)', '        int z[4] = {0, 0, 0, 0};', '        if (rules::mostFavorableSaveTarget(', '                rules::SAVE_AS_THIEF, z, 0, 0,', '                rules::SAVE_SPELLS) != 19)', '            ++bad;', '        // the five MM1 write-ups, via the registry', '        const monsters::MonsterDef* d = reg.find("brownie");', '        if (!d || d->saveAsMask != rules::SAVE_AS_CLERIC ||', '                d->saveAsLevels[2] != 9 || d->saveAsBonus != 0)', '            ++bad;', '        d = reg.find("dolphin");', '        if (!d || d->saveAsMask != rules::SAVE_AS_FIGHTER ||', '                d->saveAsLevels[0] != 4)', '            ++bad;', '        d = reg.find("displacer_beast");', '        if (!d || d->saveAsMask != rules::SAVE_AS_FIGHTER ||', '                d->saveAsLevels[0] != 12 || d->saveAsBonus != 2 ||', '                d->magicResist != 0)', '            ++bad;', '        d = reg.find("couatl");', '        if (!d || d->saveAsMask !=', '                (rules::SAVE_AS_MAGIC_USER | rules::SAVE_AS_CLERIC)', '            || d->saveAsLevels[1] != 5 || d->saveAsLevels[2] != 7)', '            ++bad;', '        d = reg.find("ki_rin");', '        if (!d || d->saveAsMask != rules::SAVE_AS_MAGIC_USER ||', '                d->saveAsLevels[1] != 18)', '            ++bad;', '        // and the actor/target carry: the displacer holds the', '        // +2 die bonus and the fighter-12 bits', '        {', '            rules::Rng rngX(1);', '            rules::Dice diceX(rngX);', '            ai::Actor a = reg.toActor("displacer_beast", diceX);', '            spelleffects::TargetDesc t = a.asTarget();', '            if (t.saveAsMask != rules::SAVE_AS_FIGHTER ||', '                    t.saveAsBonus != 2 || t.saveAsLevels[0] != 12)', '                ++bad;', '        }', '        printf("R155 classed monsters audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p18_old, p18_new,
      "regtest.cpp: R155 audit block",
      marker='R155 classed monsters audit')
assert len(applied) + len(already) == 18

p19_old = NL.join(['print wins. Census 72.', '', 'Categories:'])
p19_new = NL.join(['print wins. Census 72.', 'R155 PINNED matrix II.C (DMG p.80) - the classed', 'monsters: a classed foe saves on its MOST FAVORABLE', 'matrix (footnotes 1-2). The five MM1 write-ups that', 'print class abilities (brownie, dolphin, displacer', 'beast, couatl, ki-rin) gain the Lua saveAs key (class', 'bits + per-class levels; the couatl carries MU 5 AND', 'cleric 7), mostFavorableSaveTarget mins the save in', 'spelleffects and the ai save helper, and the displacer', '+2 save die rides the actor saveBonus. FINDING: the', 'displacer magicResistance write-up (a save-as note)', 'misparsed as 12% MR - fixed to read 0. Judgment left', 'for a later lane: ixitxachitl (clerical, per-leader)', 'and the humanoid classed leaders are per-encounter', 'extras, not base-monster data. Census 73.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p19_old, p19_new,
      "gap report: R155 header note",
      marker='R155 PINNED matrix II.C')
assert len(applied) + len(already) == 19

p20_old = NL.join(['- [ ] **Matrix II.C (classed monsters, most favorable', '      matrix)** - the R147 named gap: the per-monster', '      class pass, so a classed foe saves on its own', '      class matrix when that beats matrix II.'])
p20_new = NL.join(['- [x] **Matrix II.C (classed monsters, most favorable', '      matrix)** - pinned by R155: the saveAs data pass', '      (class bits + per-class levels, the Lua key) and', '      mostFavorableSaveTarget min the save in', '      spelleffects/trySave and the ai save helper; the', '      five MM1 classed write-ups carry the data.'])
patch("tools/dmg_gap_report.md", p20_old, p20_new,
      "gap report: matrix II.C box closed",
      marker='pinned by R155: the saveAs data pass')
assert len(applied) + len(already) == 20
# ---- R155 fails/tail ----
if fails:
    print("R155 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 20:
    print("R155 splice: FAIL - expected 20 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R155 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R155 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R155 note: 20 patches; the battery gains one audit")
print("line - AUDIT CENSUS 73; commit: R155: classed monsters")
print("pinned - matrix II.C most-favorable saves, the saveAs")
print("data pass (census 73)")
