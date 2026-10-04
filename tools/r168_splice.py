# tools/r168_splice.py - R168, 5 patches: underwater
# spell use (DMG p.57) - the general limits and the
# two printed spell lists. A new header-only layer,
# rules/uwspells.h (the grenade.h pattern: the caller
# decides casting and tracks the effects; the
# underwater encounter tables stay pinned R60/R127).
#
# (1) rules/uwspells.h: the p.57 print - spell ranges
#     and distances limited to the same as in
#     dungeons; material components altered by water;
#     fire-based spells do not function at all
#     underwater except within an airy water radius;
#     electrical spells conducted to the entire
#     surrounding area (a lightning bolt behaves as a
#     fireball). The cannot-cast lists, 41 entries -
#     cleric 9 (speak with dead*, lower water, speak
#     with plants*, atonement*, flame strike, insect
#     plague, aerial servant, control weather, wind
#     walk), druid 22 (predict weather; fire trap,
#     heat metal - its chill metal reverse works -
#     produce flame*; call lightning, pyrotechnics*;
#     animal summoning I, call woodland beings,
#     produce fire*; animal summoning II, control
#     winds, insect plague, pass plant, wall of fire;
#     animal summoning III, conjure fire elemental,
#     fire seeds, weather summoning; Chariot of
#     Sustarre, control weather, creeping doom, fire
#     storm), magic-user 10 (affect normal fires*,
#     burning hands*, find familiar, pyrotechnics*,
#     fireball, flame arrow*, gust of wind, fire
#     charm, fire shield - the hot flame version*,
#     its cold flame version still functions - and
#     fire trap). The printed asterisk rides as a flag
#     (the re-upload OCR shows no footnote for it).
#     The altered-effects list, 10 entries: cleric
#     part water (a tunnel no wider than 10 feet) and
#     earthquake (shock waves stunning all in range
#     who fail a save vs death magic for 5-20
#     rounds); druid conjure earth elemental (confined
#     to the water floor); magic-user fly (swim
#     easily at any depth even encumbered, maximum
#     speed 9 inches), lightning bolt (a 2 inch
#     radius sphere centered where the stroke would
#     originate, save for half), ice storm (hail
#     1-10 damage then floats to the surface, sleet
#     melts instantly no effect), wall of ice (floats
#     to the surface like an ice floe), conjure
#     elemental (air and fire impossible, earth only
#     as the druid spell, water no problem), freezing
#     sphere - the Otiluke spell - (50 cubic feet of
#     ice per caster level, lasting rounds equal to
#     caster level, suffocation), part water (as the
#     clerical spell). (2) the regtest include.
#     (3) the R168 audit: every printed cell pinned -
#     CENSUS 86. (4)-(5) the gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R168: underwater spell use pinned - the p.57
# cannot-cast and altered spell lists (census 86)"
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

p1_text = NL.join(['// ====================================================================', '// Adnd1 - rules/uwspells.h', '// R168: underwater spell use (DMG p.57) - the', '// cannot-cast and altered spell lists.', '//', '// Pure data, header-only (the grenade.h pattern:', '// the caller decides casting and tracks the', '// effects; the underwater encounter tables stay', '// pinned R60/R127).', '//', '// The p.57 print:', '//   - Spell ranges and distances are limited to', '//     the same as in dungeons; material', '//     components are altered by water.', '//   - Fire-based spells (such as fireball) will', '//     not function at all underwater, except', '//     within the radius of an airy water spell.', '//   - Electrical spells are conducted to the', '//     entire surrounding area - a lightning', '//     bolt behaves as a fireball.', '//   - The cannot-cast lists (9 cleric, 22 druid,', '//     10 magic-user): every entry, its level', '//     and its printed asterisk mark pinned below.', '//     The re-upload OCR shows no footnote', '//     explaining the asterisk, so it rides as a', '//     flag.', '//   - The altered-effects list (10 entries) with', '//     the printed effect text and numerics.', '// ====================================================================', '', '#pragma once', '', 'namespace rules {', '', '// ----------------------------------------------------------------------------', '// The general paragraph (p.57)', '// ----------------------------------------------------------------------------', '', 'inline bool uwSpellRangesAsDungeons() { return true; }', 'inline bool uwMaterialComponentsAltered() {', '    return true;', '}', 'inline bool uwFireSpellsFailExceptInAiryWater() {', '    return true;', '}', 'inline bool uwElectricalSpellsConductedToArea() {', '    return true;', '}', '', '// ----------------------------------------------------------------------------', '// The cannot-cast lists (p.57)', '// ----------------------------------------------------------------------------', '', 'struct UwCannotCast {', '    const char* cls;', '    int level;', '    const char* name;', '    bool printedMark;  // the printed asterisk', '};', '', 'inline int uwCannotCastCount() { return 41; }', '', '// A tiny string equality (no library includes', '// in the header).', 'inline bool uwStrEq(const char* a, const char* b) {', '    int i = 0;', '    while (a[i] != 0 && b[i] != 0) {', '        if (a[i] != b[i]) return false;', '        ++i;', '    }', '    return a[i] == b[i];', '}', '', 'inline const UwCannotCast& uwCannotCast(int i) {', '    static const UwCannotCast k[41] = {', '        // cleric (9)', '        { "cleric", 3, "speak with dead", true },', '        { "cleric", 4, "lower water", false },', '        { "cleric", 4, "speak with plants", true },', '        { "cleric", 5, "atonement", true },', '        { "cleric", 5, "flame strike", false },', '        { "cleric", 5, "insect plague", false },', '        { "cleric", 6, "aerial servant", false },', '        { "cleric", 7, "control weather", false },', '        { "cleric", 7, "wind walk", false },', '        // druid (22)', '        { "druid", 1, "predict weather", false },', '        { "druid", 2, "fire trap", false },', '        { "druid", 2, "heat metal", false },', '        { "druid", 2, "produce flame", true },', '        { "druid", 3, "call lightning", false },', '        { "druid", 3, "pyrotechnics", true },', '        { "druid", 4, "animal summoning I", false },', '        { "druid", 4, "call woodland beings", false },', '        { "druid", 4, "produce fire", true },', '        { "druid", 5, "animal summoning II", false },', '        { "druid", 5, "control winds", false },', '        { "druid", 5, "insect plague", false },', '        { "druid", 5, "pass plant", false },', '        { "druid", 5, "wall of fire", false },', '        { "druid", 6, "animal summoning III", false },', '        { "druid", 6, "conjure fire elemental", false },', '        { "druid", 6, "fire seeds", false },', '        { "druid", 6, "weather summoning", false },', '        { "druid", 7, "Chariot of Sustarre", false },', '        { "druid", 7, "control weather", false },', '        { "druid", 7, "creeping doom", false },', '        { "druid", 7, "fire storm", false },', '        // magic-user (10)', '        { "magic-user", 1, "affect normal fires", true },', '        { "magic-user", 1, "burning hands", true },', '        { "magic-user", 1, "find familiar", false },', '        { "magic-user", 2, "pyrotechnics", true },', '        { "magic-user", 3, "fireball", false },', '        { "magic-user", 3, "flame arrow", true },', '        { "magic-user", 3, "gust of wind", false },', '        { "magic-user", 4, "fire charm", false },', '        { "magic-user", 4, "fire shield (hot flame)", true },', '        { "magic-user", 4, "fire trap", false }', '    };', '    if (i < 0) i = 0;', '    if (i > 40) i = 40;', '    return k[i];', '}', '', 'inline int uwCannotCastClassCount(const char* cls) {', '    int n = 0;', '    for (int i = 0; i < 41; ++i)', '        if (uwStrEq(uwCannotCast(i).cls, cls)) ++n;', '    return n;', '}', '', 'inline bool uwIsCannotCast(', '        const char* cls, int level, const char* name) {', '    for (int i = 0; i < 41; ++i) {', '        const UwCannotCast& e = uwCannotCast(i);', '        if (e.level == level && uwStrEq(e.cls, cls)', '                && uwStrEq(e.name, name))', '            return true;', '    }', '    return false;', '}', '', '// The printed druid note: heat metal will not', '// function but its reverse, chill metal, will.', 'inline bool uwHeatMetalReverseChillWorks() {', '    return true;', '}', '', '// The printed magic-user note: the cold flame', '// version of fire shield will still function.', 'inline bool uwFireShieldColdFlameWorks() {', '    return true;', '}', '', '// ----------------------------------------------------------------------------', '// The altered-effects list (p.57)', '// ----------------------------------------------------------------------------', '', 'struct UwAltered {', '    const char* cls;', '    int level;', '    const char* name;', '    const char* effect;', '};', '', 'inline int uwAlteredCount() { return 10; }', '', 'inline const UwAltered& uwAltered(int i) {', '    static const UwAltered k[10] = {', '        { "cleric", 6, "part water",', '          "tunnel through deep water, no wider than 10 feet" },', '        { "cleric", 7, "earthquake",', '          "shock waves stun all in range, save vs death magic, 5-20 rounds" },', '        { "druid", 7, "conjure earth elemental",', '          "confined to the water floor, may strike what rests on or in the ground" },', '        { "magic-user", 3, "fly",', '          "swim easily at any depth, even encumbered, speed 9 inches" },', '        { "magic-user", 3, "lightning bolt",', '          "behaves as fireball, 2 inch radius sphere, save for half" },', '        { "magic-user", 3, "ice storm",', '          "hail 1-10 damage then floats, sleet no effect" },', '        { "magic-user", 3, "wall of ice",', '          "floats to the surface like an ice floe" },', '        { "magic-user", 5, "conjure elemental",', '          "air and fire impossible, earth as the druid spell, water fine" },', '        { "magic-user", 6, "freezing sphere (Otiluke)",', '          "50 cubic feet of ice per level, rounds per level, suffocation" },', '        { "magic-user", 6, "part water",', '          "as the 6th level clerical part water" }', '    };', '    if (i < 0) i = 0;', '    if (i > 9) i = 9;', '    return k[i];', '}', '', '// The altered-effect numerics (p.57).', 'inline int uwPartWaterTunnelDiameterFeet() {', '    return 10;', '}', 'inline int uwEarthquakeStunRoundsMin() { return 5; }', 'inline int uwEarthquakeStunRoundsMax() { return 20; }', 'inline bool uwEarthquakeSaveVsDeathMagic() {', '    return true;', '}', 'inline bool uwConjureEarthElementalConfinedToFloor() {', '    return true;', '}', 'inline int uwFlyMaxSpeedInches() { return 9; }', 'inline int uwLightningBoltRadiusInches() { return 2; }', 'inline bool uwLightningBoltSaveForHalf() {', '    return true;', '}', 'inline int uwIceStormHailDamageMin() { return 1; }', 'inline int uwIceStormHailDamageMax() { return 10; }', 'inline bool uwIceStormSleetNoEffect() {', '    return true;', '}', 'inline bool uwWallOfIceFloatsToSurface() {', '    return true;', '}', 'inline bool uwConjureElementalAirOrFireImpossible() {', '    return true;', '}', 'inline bool uwConjureElementalWaterFine() {', '    return true;', '}', 'inline int uwFreezingSphereCubicFeetPerLevel() {', '    return 50;', '}', 'inline int uwFreezingSphereDurationRoundsPerLevel() {', '    return 1;', '}', 'inline bool uwFreezingSphereCasterSuffocates() {', '    return true;', '}', '', '} // namespace rules', ''])
create("rules/uwspells.h", p1_text,
      "uwspells.h: the underwater spell use layer",
      marker="uwCannotCastCount")
assert len(applied) + len(already) == 1

p2_old = NL.join(['#include "rules/disease.h"  // R167: pp.13-14 disease and parasitic infestation'])
p2_new = NL.join(['#include "rules/disease.h"  // R167: pp.13-14 disease and parasitic infestation', '#include "rules/uwspells.h"  // R168: p.57 underwater spell use'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: uwspells include",
      marker='rules/uwspells.h"  // R168')
assert len(applied) + len(already) == 2

p3_old = NL.join(['        printf("R167 disease and infestation audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join(['        printf("R167 disease and infestation audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R168: underwater spell use audit ------------', '    // DMG p.57: the general limits, the two printed', '    // spell lists (cannot-cast by class and level,', '    // altered effects) and the altered numerics.', '    {', '        int bad = 0;', '        // the general paragraph', '        if (!rules::uwSpellRangesAsDungeons() ||', '            !rules::uwFireSpellsFailExceptInAiryWater() ||', '            !rules::uwElectricalSpellsConductedToArea() ||', '            !rules::uwMaterialComponentsAltered())', '            ++bad;', '        // the cannot-cast list: 41 entries', '        // (9 cleric, 22 druid, 10 magic-user)', '        if (rules::uwCannotCastCount() != 41) ++bad;', '        if (rules::uwCannotCastClassCount("cleric") != 9 ||', '            rules::uwCannotCastClassCount("druid") != 22 ||', '            rules::uwCannotCastClassCount("magic-user") != 10)', '            ++bad;', '        // 11 entries carry the printed asterisk mark', '        {', '            int marks = 0;', '            for (int i = 0; i < rules::uwCannotCastCount();', '                 ++i)', '                if (rules::uwCannotCast(i).printedMark) ++marks;', '            if (marks != 11) ++bad;', '        }', '        // spot the rows: first and last of each class', '        if (std::string(rules::uwCannotCast(0).cls) != "cleric" ||', '            rules::uwCannotCast(0).level != 3 ||', '            std::string(rules::uwCannotCast(0).name)', '                != "speak with dead" ||', '            !rules::uwCannotCast(0).printedMark)', '            ++bad;', '        if (std::string(rules::uwCannotCast(8).cls) != "cleric" ||', '            rules::uwCannotCast(8).level != 7 ||', '            std::string(rules::uwCannotCast(8).name)', '                != "wind walk")', '            ++bad;', '        if (std::string(rules::uwCannotCast(9).cls) != "druid" ||', '            rules::uwCannotCast(9).level != 1 ||', '            std::string(rules::uwCannotCast(9).name)', '                != "predict weather")', '            ++bad;', '        if (std::string(rules::uwCannotCast(30).cls) != "druid" ||', '            rules::uwCannotCast(30).level != 7 ||', '            std::string(rules::uwCannotCast(30).name)', '                != "fire storm")', '            ++bad;', '        if (std::string(rules::uwCannotCast(31).cls)', '                != "magic-user" ||', '            rules::uwCannotCast(31).level != 1 ||', '            std::string(rules::uwCannotCast(31).name)', '                != "affect normal fires" ||', '            !rules::uwCannotCast(31).printedMark)', '            ++bad;', '        if (std::string(rules::uwCannotCast(40).cls)', '                != "magic-user" ||', '            rules::uwCannotCast(40).level != 4 ||', '            std::string(rules::uwCannotCast(40).name)', '                != "fire trap")', '            ++bad;', '        // the middle rows: cleric atonement and', '        // flame strike, druid produce fire', '        if (std::string(rules::uwCannotCast(3).name)', '                != "atonement" ||', '            std::string(rules::uwCannotCast(4).name)', '                != "flame strike" ||', '            std::string(rules::uwCannotCast(17).name)', '                != "produce fire" ||', '            rules::uwCannotCast(17).level != 4)', '            ++bad;', '        // the membership probe, both ways', '        if (!rules::uwIsCannotCast("cleric", 5, "flame strike") ||', '            !rules::uwIsCannotCast("druid", 2, "produce flame") ||', '            !rules::uwIsCannotCast("magic-user", 3, "fireball"))', '            ++bad;', '        if (rules::uwIsCannotCast("cleric", 1, "cure light wounds") ||', '            rules::uwIsCannotCast("magic-user", 3, "fly") ||', '            rules::uwIsCannotCast("druid", 4, "plant growth"))', '            ++bad;', '        // the printed reverse/shield notes', '        if (!rules::uwHeatMetalReverseChillWorks() ||', '            !rules::uwFireShieldColdFlameWorks())', '            ++bad;', '        // the altered-effects list: 10 entries', '        // (2 cleric, 1 druid, 7 magic-user)', '        if (rules::uwAlteredCount() != 10) ++bad;', '        {', '            int cl = 0, dr = 0, mu = 0;', '            for (int i = 0; i < 10; ++i) {', '                std::string c = rules::uwAltered(i).cls;', '                if (c == "cleric") ++cl;', '                else if (c == "druid") ++dr;', '                else ++mu;', '            }', '            if (cl != 2 || dr != 1 || mu != 7) ++bad;', '        }', '        static const int kAltLevel[10] = {', '            6, 7, 7, 3, 3, 3, 3, 5, 6, 6', '        };', '        for (int i = 0; i < 10; ++i)', '            if (rules::uwAltered(i).level != kAltLevel[i])', '                ++bad;', '        if (std::string(rules::uwAltered(0).name) != "part water" ||', '            std::string(rules::uwAltered(0).cls) != "cleric" ||', '            std::string(rules::uwAltered(2).name)', '                != "conjure earth elemental" ||', '            std::string(rules::uwAltered(4).name)', '                != "lightning bolt" ||', '            std::string(rules::uwAltered(7).name)', '                != "conjure elemental" ||', '            std::string(rules::uwAltered(8).name)', '                != "freezing sphere (Otiluke)" ||', '            std::string(rules::uwAltered(9).name) != "part water")', '            ++bad;', '        // the altered-effect text, spot pinned', '        if (std::string(rules::uwAltered(0).effect)', '                != "tunnel through deep water, no wider than 10 feet" ||', '            std::string(rules::uwAltered(3).effect)', '                != "swim easily at any depth, even encumbered, speed 9 inches")', '            ++bad;', '        // the altered-effect numerics', '        if (rules::uwPartWaterTunnelDiameterFeet() != 10)', '            ++bad;', '        if (rules::uwEarthquakeStunRoundsMin() != 5 ||', '            rules::uwEarthquakeStunRoundsMax() != 20 ||', '            !rules::uwEarthquakeSaveVsDeathMagic())', '            ++bad;', '        if (!rules::uwConjureEarthElementalConfinedToFloor())', '            ++bad;', '        if (rules::uwFlyMaxSpeedInches() != 9 ||', '            rules::uwLightningBoltRadiusInches() != 2 ||', '            !rules::uwLightningBoltSaveForHalf())', '            ++bad;', '        if (rules::uwIceStormHailDamageMin() != 1 ||', '            rules::uwIceStormHailDamageMax() != 10 ||', '            !rules::uwIceStormSleetNoEffect() ||', '            !rules::uwWallOfIceFloatsToSurface())', '            ++bad;', '        if (!rules::uwConjureElementalAirOrFireImpossible() ||', '            !rules::uwConjureElementalWaterFine())', '            ++bad;', '        if (rules::uwFreezingSphereCubicFeetPerLevel() != 50 ||', '            rules::uwFreezingSphereDurationRoundsPerLevel() != 1 ||', '            !rules::uwFreezingSphereCasterSuffocates())', '            ++bad;', '        printf("R168 underwater spell use audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R168 audit block",
      marker="R168 underwater spell use audit")
assert len(applied) + len(already) == 3

p4_old = NL.join(['the dice and tracks the disability. Census 85.', '', 'Categories:'])
p4_new = NL.join(['the dice and tracks the disability. Census 85.', 'R168 PINNED underwater spell use (DMG p.57) -', 'rules/uwspells.h: the general limits (spell', 'ranges and distances as in dungeons, material', 'components altered by water, fire-based spells do', 'not function except within an airy water radius,', 'electrical spells conducted to the entire', 'surrounding area); the cannot-cast lists cell', 'by cell - cleric 9 (speak with dead, lower', 'water, speak with plants, atonement, flame', 'strike, insect plague, aerial servant, control', 'weather, wind walk), druid 22 (predict', 'weather; fire trap, heat metal - its chill', 'metal reverse works - produce flame; call', 'lightning, pyrotechnics; animal summoning I,', 'call woodland beings, produce fire; animal', 'summoning II, control winds, insect plague,', 'pass plant, wall of fire; animal summoning', 'III, conjure fire elemental, fire seeds,', 'weather summoning; Chariot of Sustarre,', 'control weather, creeping doom, fire storm),', 'magic-user 10 (affect normal fires, burning', 'hands, find familiar, pyrotechnics, fireball,', 'flame arrow, gust of wind, fire charm, fire', 'shield - the hot flame version, its cold flame', 'version still functions - and fire trap); the', '11 asterisked entries pinned as the printed', 'mark (the re-upload OCR shows no footnote for', 'it, so it rides as a flag); the altered-effects', 'list: cleric part water (a tunnel no wider', 'than 10 feet) and earthquake (shock waves', 'stunning all in range who fail a save vs', 'death magic for 5-20 rounds), druid conjure', 'earth elemental (confined to the water floor),', 'magic-user fly (swim at any depth even', 'encumbered, maximum speed 9 inches),', 'lightning bolt (a 2 inch radius sphere, save', 'for half), ice storm (hail 1-10 damage, sleet', 'no effect), wall of ice (floats to the', 'surface), conjure elemental (air and fire', 'impossible, earth as the druid spell, water', 'fine), Otiluke freezing sphere (50 cubic', 'feet per level, rounds per level, suffocation', 'unless immediate aid), part water (as the', 'clerical spell). The caller decides casting;', 'the encounter tables stay pinned R60/R127.', 'Census 86.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R168 header note",
      marker="R168 PINNED underwater spell use")
assert len(applied) + len(already) == 4

p5_old = NL.join(['- [ ] **Underwater spell use (p.57)** - the modifier', '      table; the underwater encounter tables are pinned', '      (R60/R127) but the spell columns are not.'])
p5_new = NL.join(['- [x] **Underwater spell use (p.57)** - PINNED', '      R168: rules/uwspells.h (the cannot-cast and', '      altered spell lists cell by cell, the general', '      limits, the altered-effect numerics).'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: underwater spell use box closed",
      marker="R168: rules/uwspells.h (the cannot-cast and")
assert len(applied) + len(already) == 5

# ---- R168 fails/tail ----
if fails:
    print("R168 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R168 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R168 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R168 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R168 note: 5 patches; census 86; commit: R168: underwater spell use pinned - the p.57 cannot-cast and altered spell lists (census 86)")
