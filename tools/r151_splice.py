# tools/r151_splice.py - R151, five patches: Appendix O
# encumbrance of standard items (DMG p.225) pinned.
#
# (1) NEW header-only dm/appendixo.h - the appendixa.h
#     pattern (pure data): the 64 printed standard-item
#     weights in gold-piece units, the 57 exact rows and
#     the 7 printed ranges (the four chests, gem, small
#     jewelry, tapestry) both ends, the tapestry open
#     tail, the printed 1500 g.p. (150#) carry max, and
#     the four named exemptions (material components
#     unless bulky, any helm but great helm when armored,
#     one set of clothing, thieves picks and tools).
# (2) regtest.cpp include. (3) the R151 audit block: every
#     row pinned, the ranges both ways, the exemptions
#     wording-pinned (census goes 69). (4) gap report
#     header note. (5) the Appendix O open box flips
#     closed. The caller is items::encumbranceBand
#     (PHB p.38) - its printed per-item source.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). This file
# contains ZERO backslash characters and no content
# string embeds a literal apostrophe (the R133b + R147
# chunk-delivery lessons - the anchors that need them
# build theirs from chr(92) and AP).
# Commit: "R151: Appendix O encumbrance pinned - 64 item
# weights, ranges, exemptions, carry max (census 69)"
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

def patch_new(p, content, tag):
    fp = os.path.join(ROOT, p)
    if os.path.exists(fp):
        with open(fp, encoding="ascii") as f:
            if f.read() == content:
                already.append(tag)
                return
        fails.append(tag + ": file exists but differs")
        return
    wr(p, content)
    applied.append(tag)

# ---- (1) dm/appendixo.h, the new header ----
appendixo_h = NL.join([
    '// ============================================================================',
    '// Adnd1 - dm/appendixo.h',
    '// R151: DMG p.225 - APPENDIX O, ENCUMBRANCE OF',
    '// STANDARD ITEMS. Pure data, header-only (the',
    '// appendixa.h pattern: the caller decides when to',
    '// weigh; the band thresholds themselves live in',
    '// items::encumbranceBand, PHB p.38 - this header is',
    '// the printed per-item weight list that table feeds',
    '// on). Transcribed from the fresh DMG upload',
    '// (2026-10-04), readable cell for cell.',
    '//',
    '// Conventions, all named in place:',
    '//   - Weights are in gold-piece units (1 g.p. = 1/10',
    '//     pound), the printed encumbrance column - the',
    '//     combined weight and bulkiness of the item, not',
    '//     its scale weight (the book says so in as many',
    '//     words).',
    '//   - The printed sub-rows (an indented "small" under',
    '//     "Belt pouch, large") are carried as their own',
    '//     fully-named entries, printed order kept.',
    '//   - The seven printed ranges (the four chests, gem,',
    '//     small jewelry, tapestry) carry lo and hi; the',
    '//     commas in the printed figures (1,000-5,000) are',
    '//     print formatting only.',
    '//   - The tapestry row is open-ended (50-1,000 +):',
    '//     openEnded is true for it alone.',
    '//   - The printed max a normal-strength person can',
    '//     carry and still move: 1500 g.p. (150#) - pinned',
    '//     as MAX_CARRY_GP.',
    '//   - The printed footnote: the musical-instrument',
    '//     row means only large and bulky instruments such',
    '//     as lutes and drums.',
    '//   - The printed exemption list (items not figured',
    '//     into encumbrance) is pinned as the four',
    '//     EXEMPT_* wordings.',
    '//   - Armor, weapons, and spell-table weights live',
    '//     elsewhere (items.h weightGp); this is the',
    '//     standard gear list the DMG prints.',
    '// ============================================================================',
    '',
    '#pragma once',
    '',
    'namespace dm {',
    'namespace appendixo {',
    '',
    'enum Gear : int {',
    '    GR_BACKPACK,',
    '    GR_BELT,',
    '    GR_BELT_POUCH_LARGE,',
    '    GR_BELT_POUCH_SMALL,',
    '    GR_BOOK_LARGE_METAL_BOUND,',
    '    GR_BOOTS_HARD,',
    '    GR_BOOTS_SOFT,',
    '    GR_BOTTLES_FLAGONS,',
    '    GR_BOW_COMPOSITE_LONG,',
    '    GR_BOW_COMPOSITE_SHORT,',
    '    GR_BOW_LONG,',
    '    GR_BOW_SHORT,',
    '    GR_CALTROP,',
    '    GR_CANDLE,',
    '    GR_CHEST_LARGE_SOLID_IRON,',
    '    GR_CHEST_SMALL_SOLID_IRON,',
    '    GR_CHEST_SMALL_WOODEN,',
    '    GR_CHEST_LARGE_WOODEN,',
    '    GR_CLOTHES_ONE_SET,',
    '    GR_CORD_10FT,',
    '    GR_CROSSBOW_HEAVY,',
    '    GR_CROSSBOW_LIGHT,',
    '    GR_CRYSTAL_BALL,',
    '    GR_FLASK_EMPTY,',
    '    GR_FLASK_FULL,',
    '    GR_GEM,',
    '    GR_GRAPNEL,',
    '    GR_HAND_TOOL,',
    '    GR_HELM,',
    '    GR_HELM_GREAT,',
    '    GR_HOLY_WATER_BOTTLE,',
    '    GR_HORN,',
    '    GR_JEWELRY_LARGE,',
    '    GR_JEWELRY_SMALL,',
    '    GR_LANTERN,',
    '    GR_MIRROR,',
    '    GR_MUSICAL_INSTRUMENT,',
    '    GR_POLE_10FT,',
    '    GR_PURSE,',
    '    GR_QUIVER,',
    '    GR_RATIONS_IRON,',
    '    GR_RATIONS_STANDARD,',
    '    GR_ROBE_FOLDED,',
    '    GR_ROBE_WORN,',
    '    GR_ROD,',
    '    GR_ROPE_50FT,',
    '    GR_SACK_LARGE,',
    '    GR_SACK_SMALL,',
    '    GR_SADDLE_LIGHT_HORSE,',
    '    GR_SADDLE_HEAVY_HORSE,',
    '    GR_SADDLEBAG,',
    '    GR_SADDLE_BLANKET,',
    '    GR_SCROLL_CASE_BONE_IVORY,',
    '    GR_SCROLL_CASE_LEATHER,',
    '    GR_SPIKE,',
    '    GR_STAFF,',
    '    GR_TAPESTRY,',
    '    GR_TINDERBOX,',
    '    GR_TORCH,',
    '    GR_WAND_BONE_IVORY_CASE,',
    '    GR_WAND_BOX,',
    '    GR_WAND_LEATHER_CASE,',
    '    GR_WATERSKIN_EMPTY,',
    '    GR_WATERSKIN_FULL,',
    '    GR_COUNT,',
    '};',
    '',
    '// One printed row. lo and hi are the printed',
    '// encumbrance in g.p.; the 57 exact rows carry',
    '// lo == hi, the 7 printed ranges carry both ends.',
    '// openEnded marks the printed tapestry tail (50-',
    '// 1,000 +) alone. The printed foot marks (10 ft,',
    '// 50 ft) are rendered "ft." here - an apostrophe-',
    '// free spelling of the printed prime.',
    'struct GearEntry {',
    '    const char* name;',
    '    int lo;',
    '    int hi;',
    '    bool openEnded;',
    '};',
    '',
    'inline const GearEntry& entry(Gear g) {',
    '    static const GearEntry kGear[GR_COUNT] = {',
    '        { "Backpack", 20, 20, false },',
    '        { "Belt", 3, 3, false },',
    '        { "Belt pouch, large", 10, 10, false },',
    '        { "Belt pouch, small", 5, 5, false },',
    '        { "Book, large metal-bound", 200, 200, false },',
    '        { "Boots, hard", 60, 60, false },',
    '        { "Boots, soft", 30, 30, false },',
    '        { "Bottles, flagons", 60, 60, false },',
    '        { "Bow, composite long", 80, 80, false },',
    '        { "Bow, composite short", 50, 50, false },',
    '        { "Bow, long", 100, 100, false },',
    '        { "Bow, short", 50, 50, false },',
    '        { "Caltrop", 50, 50, false },',
    '        { "Candle", 5, 5, false },',
    '        { "Chest, large solid iron", 1000, 5000, false },',
    '        { "Chest, small solid iron", 200, 500, false },',
    '        { "Chest, small wooden", 100, 250, false },',
    '        { "Chest, large wooden", 500, 1500, false },',
    '        { "Clothes (1 set)", 30, 30, false },',
    '        { "Cord, 10 ft.", 2, 2, false },',
    '        { "Crossbow, heavy", 80, 80, false },',
    '        { "Crossbow, light", 50, 50, false },',
    '        { "Crystal ball, base and wrapping", 150, 150, false },',
    '        { "Flask, empty", 7, 7, false },',
    '        { "Flask, full", 20, 20, false },',
    '        { "Gem", 1, 5, false },',
    '        { "Grapnel", 100, 100, false },',
    '        { "Hand tool", 10, 10, false },',
    '        { "Helm", 45, 45, false },',
    '        { "Helm, great", 100, 100, false },',
    '        { "Holy water, potion bottles", 25, 25, false },',
    '        { "Horn", 50, 50, false },',
    '        { "Jewelry, large", 50, 50, false },',
    '        { "Jewelry, small", 1, 5, false },',
    '        { "Lantern", 60, 60, false },',
    '        { "Mirror", 5, 5, false },',
    '        { "Musical instrument", 350, 350, false },',
    '        { "Pole, 10 ft.", 100, 100, false },',
    '        { "Purse", 1, 1, false },',
    '        { "Quiver", 30, 30, false },',
    '        { "Rations, iron", 75, 75, false },',
    '        { "Rations, standard", 200, 200, false },',
    '        { "Robe or cloak, folded", 50, 50, false },',
    '        { "Robe or cloak, worn", 25, 25, false },',
    '        { "Rod", 60, 60, false },',
    '        { "Rope, 50 ft.", 75, 75, false },',
    '        { "Sack, large", 20, 20, false },',
    '        { "Sack, small", 5, 5, false },',
    '        { "Saddle, light horse", 250, 250, false },',
    '        { "Saddle, heavy horse", 500, 500, false },',
    '        { "Saddlebag", 150, 150, false },',
    '        { "Saddle blanket (pad)", 20, 20, false },',
    '        { "Scroll case, bone or ivory", 50, 50, false },',
    '        { "Scroll case, leather", 25, 25, false },',
    '        { "Spike", 10, 10, false },',
    '        { "Staff", 100, 100, false },',
    '        { "Tapestry (very small to huge)", 50, 1000, true },',
    '        { "Tinderbox", 2, 2, false },',
    '        { "Torch", 25, 25, false },',
    '        { "Wand, bone or ivory case", 60, 60, false },',
    '        { "Wand, box", 80, 80, false },',
    '        { "Wand, leather case", 30, 30, false },',
    '        { "Waterskin or wineskin, empty", 5, 5, false },',
    '        { "Waterskin or wineskin, full", 50, 50, false },',
    '    };',
    '    return kGear[g];',
    '}',
    '',
    'inline const char* name(Gear g) { return entry(g).name; }',
    'inline int lo(Gear g) { return entry(g).lo; }',
    'inline int hi(Gear g) { return entry(g).hi; }',
    'inline bool openEnded(Gear g) { return entry(g).openEnded; }',
    '',
    '// The printed max a normal-strength person can carry',
    '// and still move: 1500 g.p. (150#).',
    'const int MAX_CARRY_GP = 1500;',
    '',
    '// The printed footnote, named: the musical-instrument',
    '// row means only large and bulky instruments such as',
    '// lutes and drums (the row name stays as printed).',
    '',
    '// The printed exemptions - the items NOT figured into',
    '// encumbrance - four wordings as printed:',
    'enum Exempt : int {',
    '    EX_MATERIAL_COMPONENTS = 0,',
    '    EX_HELM,',
    '    EX_CLOTHING,',
    '    EX_THIEVES_PICKS,',
    '    EX_COUNT,',
    '};',
    '',
    'inline const char* exemptName(Exempt e) {',
    '    switch (e) {',
    '    case EX_MATERIAL_COMPONENTS:',
    '        return "material components (unless large and bulky)";',
    '    case EX_HELM:',
    '        return "any helm but great helm, if the character has any armor";',
    '    case EX_CLOTHING:',
    '        return "one set of clothing";',
    '    case EX_THIEVES_PICKS:',
    '        return "thieves' + AP + ' picks and tools";',
    '    case EX_COUNT: break;',
    '    }',
    '    return "";',
    '}',
    '',
    '} // namespace appendixo',
    '} // namespace dm',
])
appendixo_h += NL

# ---- (2) regtest.cpp: the include ----
inc_old = NL.join([
    '#include "dm/appendixi.h"  // R150: pp.217-220 Appendix I dressing',
])
inc_new = NL.join([
    '#include "dm/appendixi.h"  // R150: pp.217-220 Appendix I dressing',
    '#include "dm/appendixo.h"  // R151: p.225 Appendix O item weights',
])

# ---- (3) regtest.cpp: the R151 audit block ----
aud_old = NL.join([
    '        printf("R150 appendix I dressing audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
aud_new = NL.join([
    '        printf("R150 appendix I dressing audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R151: Appendix O encumbrance audit -----------------------------',
    '    // The DMG p.225 Appendix O weight list, pinned row by',
    '    // row in dm/appendixo.h: the 64 printed items - 57',
    '    // exact rows, the 7 printed ranges (the four chests,',
    '    // gem, small jewelry, tapestry) both ends, the',
    '    // tapestry open tail, the 1500 g.p. (150#) carry max',
    '    // and the four exemption wordings. Seven',
    '    // representative name wordings are pinned too. The',
    '    // caller is items::encumbranceBand (PHB p.38); this',
    '    // is its printed per-item source.',
    '    {',
    '        int bad = 0;',
    '        namespace AO = dm::appendixo;',
    '        if (AO::GR_COUNT != 64 || AO::EX_COUNT != 4 ||',
    '            AO::MAX_CARRY_GP != 1500) ++bad;',
    '        // all 64 rows: lo and hi pinned, the name',
    '        // non-empty, printed order kept',
    '        static const struct { int lo, hi; AO::Gear g; }',
    '            kGR[] = {',
    '            {   20,   20, AO::GR_BACKPACK },',
    '            {    3,    3, AO::GR_BELT },',
    '            {   10,   10, AO::GR_BELT_POUCH_LARGE },',
    '            {    5,    5, AO::GR_BELT_POUCH_SMALL },',
    '            {  200,  200, AO::GR_BOOK_LARGE_METAL_BOUND },',
    '            {   60,   60, AO::GR_BOOTS_HARD },',
    '            {   30,   30, AO::GR_BOOTS_SOFT },',
    '            {   60,   60, AO::GR_BOTTLES_FLAGONS },',
    '            {   80,   80, AO::GR_BOW_COMPOSITE_LONG },',
    '            {   50,   50, AO::GR_BOW_COMPOSITE_SHORT },',
    '            {  100,  100, AO::GR_BOW_LONG },',
    '            {   50,   50, AO::GR_BOW_SHORT },',
    '            {   50,   50, AO::GR_CALTROP },',
    '            {    5,    5, AO::GR_CANDLE },',
    '            { 1000, 5000, AO::GR_CHEST_LARGE_SOLID_IRON },',
    '            {  200,  500, AO::GR_CHEST_SMALL_SOLID_IRON },',
    '            {  100,  250, AO::GR_CHEST_SMALL_WOODEN },',
    '            {  500, 1500, AO::GR_CHEST_LARGE_WOODEN },',
    '            {   30,   30, AO::GR_CLOTHES_ONE_SET },',
    '            {    2,    2, AO::GR_CORD_10FT },',
    '            {   80,   80, AO::GR_CROSSBOW_HEAVY },',
    '            {   50,   50, AO::GR_CROSSBOW_LIGHT },',
    '            {  150,  150, AO::GR_CRYSTAL_BALL },',
    '            {    7,    7, AO::GR_FLASK_EMPTY },',
    '            {   20,   20, AO::GR_FLASK_FULL },',
    '            {    1,    5, AO::GR_GEM },',
    '            {  100,  100, AO::GR_GRAPNEL },',
    '            {   10,   10, AO::GR_HAND_TOOL },',
    '            {   45,   45, AO::GR_HELM },',
    '            {  100,  100, AO::GR_HELM_GREAT },',
    '            {   25,   25, AO::GR_HOLY_WATER_BOTTLE },',
    '            {   50,   50, AO::GR_HORN },',
    '            {   50,   50, AO::GR_JEWELRY_LARGE },',
    '            {    1,    5, AO::GR_JEWELRY_SMALL },',
    '            {   60,   60, AO::GR_LANTERN },',
    '            {    5,    5, AO::GR_MIRROR },',
    '            {  350,  350, AO::GR_MUSICAL_INSTRUMENT },',
    '            {  100,  100, AO::GR_POLE_10FT },',
    '            {    1,    1, AO::GR_PURSE },',
    '            {   30,   30, AO::GR_QUIVER },',
    '            {   75,   75, AO::GR_RATIONS_IRON },',
    '            {  200,  200, AO::GR_RATIONS_STANDARD },',
    '            {   50,   50, AO::GR_ROBE_FOLDED },',
    '            {   25,   25, AO::GR_ROBE_WORN },',
    '            {   60,   60, AO::GR_ROD },',
    '            {   75,   75, AO::GR_ROPE_50FT },',
    '            {   20,   20, AO::GR_SACK_LARGE },',
    '            {    5,    5, AO::GR_SACK_SMALL },',
    '            {  250,  250, AO::GR_SADDLE_LIGHT_HORSE },',
    '            {  500,  500, AO::GR_SADDLE_HEAVY_HORSE },',
    '            {  150,  150, AO::GR_SADDLEBAG },',
    '            {   20,   20, AO::GR_SADDLE_BLANKET },',
    '            {   50,   50, AO::GR_SCROLL_CASE_BONE_IVORY },',
    '            {   25,   25, AO::GR_SCROLL_CASE_LEATHER },',
    '            {   10,   10, AO::GR_SPIKE },',
    '            {  100,  100, AO::GR_STAFF },',
    '            {   50, 1000, AO::GR_TAPESTRY },',
    '            {    2,    2, AO::GR_TINDERBOX },',
    '            {   25,   25, AO::GR_TORCH },',
    '            {   60,   60, AO::GR_WAND_BONE_IVORY_CASE },',
    '            {   80,   80, AO::GR_WAND_BOX },',
    '            {   30,   30, AO::GR_WAND_LEATHER_CASE },',
    '            {    5,    5, AO::GR_WATERSKIN_EMPTY },',
    '            {   50,   50, AO::GR_WATERSKIN_FULL },',
    '        };',
    '        for (size_t i = 0; i < sizeof(kGR)/sizeof(kGR[0]); ++i) {',
    '            if (AO::lo(kGR[i].g) != kGR[i].lo) ++bad;',
    '            if (AO::hi(kGR[i].g) != kGR[i].hi) ++bad;',
    '            if (std::string(AO::name(kGR[i].g)).empty()) ++bad;',
    '        }',
    '        // the open tail: tapestry alone',
    '        for (int g = 0; g < AO::GR_COUNT; ++g) {',
    '            if (AO::openEnded((AO::Gear)g) !=',
    '                (g == (int)AO::GR_TAPESTRY)) ++bad;',
    '        }',
    '        // 7 representative name wordings (the',
    '        // sub-row, footnote, wrapping, pad and ft',
    '        // spellings pinned as printed)',
    '        if (std::string(AO::name(AO::GR_BELT_POUCH_SMALL)) !=',
    '            "Belt pouch, small") ++bad;',
    '        if (std::string(AO::name(AO::GR_BOOK_LARGE_METAL_BOUND)) !=',
    '            "Book, large metal-bound") ++bad;',
    '        if (std::string(AO::name(AO::GR_CRYSTAL_BALL)) !=',
    '            "Crystal ball, base and wrapping") ++bad;',
    '        if (std::string(AO::name(AO::GR_MUSICAL_INSTRUMENT)) !=',
    '            "Musical instrument") ++bad;',
    '        if (std::string(AO::name(AO::GR_SADDLE_BLANKET)) !=',
    '            "Saddle blanket (pad)") ++bad;',
    '        if (std::string(AO::name(AO::GR_CORD_10FT)) !=',
    '            "Cord, 10 ft.") ++bad;',
    '        if (std::string(AO::name(AO::GR_ROPE_50FT)) !=',
    '            "Rope, 50 ft.") ++bad;',
    '        // the four exemption wordings, as printed',
    '        if (std::string(AO::exemptName(',
    '            AO::EX_MATERIAL_COMPONENTS)) !=',
    '            "material components (unless large and bulky)") ++bad;',
    '        if (std::string(AO::exemptName(AO::EX_HELM)) !=',
    '            "any helm but great helm, if the character has any armor")',
    '            ++bad;',
    '        if (std::string(AO::exemptName(AO::EX_CLOTHING)) !=',
    '            "one set of clothing") ++bad;',
    '        if (std::string(AO::exemptName(AO::EX_THIEVES_PICKS)) !=',
    '            "thieves' + AP + ' picks and tools") ++bad;',
    '        printf("R151 Appendix O encumbrance audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])

# ---- (4) gap report: the R151 round note ----
gap_head_old = NL.join([
    'band content was right). Census 68.',
    '',
    'Categories:',
])
gap_head_new = NL.join([
    'band content was right). Census 68.',
    'R151 PINNED the Appendix O encumbrance table (DMG',
    'p.225): dm/appendixo.h, the appendixa.h pattern -',
    'the 64 standard-item weights in g.p. units (57',
    'exact rows; the four chests, gem, small jewelry',
    'and tapestry ranges both ends; the tapestry open',
    'tail), the 1500 g.p. (150#) carry max and the',
    'four exemption wordings. The caller is',
    'items::encumbranceBand (PHB p.38). Census 69.',
    '',
    'Categories:',
])

# ---- (5) gap report: the Appendix O box ----
gap_box_old = NL.join([
    '- [ ] **Appendix O, encumbrance of standard items',
    '      (p.225)** - items::encumbrance exists; the printed',
    '      weight table itself is unpinned.',
])
gap_box_new = NL.join([
    '- [x] **Appendix O, encumbrance of standard items',
    '      (p.225)** - PINNED R151: dm/appendixo.h, the',
    '      appendixa.h pattern (pure data, header-only; the',
    '      audit is the regtest.cpp R151 block): the 64',
    '      printed weights in g.p. units, the 57 exact rows',
    '      and the 7 printed ranges (the four chests, gem,',
    '      small jewelry, tapestry) both ends, the tapestry',
    '      open tail, the 1500 g.p. (150#) carry max and',
    '      the four exemption wordings. The caller is',
    '      items::encumbranceBand (PHB p.38) - this is its',
    '      printed per-item source.',
])

# ---- run ----
patch_new("dm/appendixo.h", appendixo_h, "NEW dm/appendixo.h")
assert len(applied) + len(already) == 1
patch("regtest.cpp", inc_old, inc_new,
      "regtest.cpp: appendixo include",
      marker='#include "dm/appendixo.h"')
assert len(applied) + len(already) == 2
patch("regtest.cpp", aud_old, aud_new,
      "regtest.cpp: R151 Appendix O encumbrance audit",
      marker="R151 Appendix O encumbrance audit")
assert len(applied) + len(already) == 3
patch("tools/dmg_gap_report.md", gap_head_old, gap_head_new,
      "gap report: R151 header note",
      marker="R151 PINNED the Appendix O encumbrance table")
assert len(applied) + len(already) == 4
patch("tools/dmg_gap_report.md", gap_box_old, gap_box_new,
      "gap report: Appendix O box closed",
      marker="PINNED R151: dm/appendixo.h")
assert len(applied) + len(already) == 5
# ---- R151 fails/tail ----
if fails:
    print("R151 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R151 splice: FAIL - expected 5 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R151 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R151 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R151 note: five patches; expect the battery to gain")
print("one audit line - AUDIT CENSUS 69; commit: R151:")
print("Appendix O encumbrance pinned - 64 item weights,")
print("ranges, exemptions, carry max (census 69)")
