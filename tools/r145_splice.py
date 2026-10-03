#!/usr/bin/env python3
# tools/r145_splice.py - R145 the per-weapon PHB p.38 'to
# hit' table: every weapon gains its own armor-class
# adjustment row (AC 0..10, the book's column order),
# replacing the 3-class approximation at the single
# items::attackAdjustment choke point. Both p.38 charts are
# pinned - melee rows from the first chart, the short bow /
# long bow / light crossbow / sling rows from the
# hurled-and-missile chart (the sling is the bullet's row,
# the DMG p.71 example's own weapon). Transcribed from the
# 1eonline.info compilation, the repo-trusted source; the
# PHB re-upload's book-verify debt stands.
#  - items/items.h: WeaponDef gains acAdj[11];
#    weaponAcAdjustment declared; attackAdjustment takes
#    the raw effective AC
#  - items/items.cpp: the 15 rows; weaponAcAdjustment
#    (clamps AC to the table's 0..10 edges); the choke
#    point swaps to the per-weapon row
#  - ai/actor.cpp: both call sites (melee + missile) pass
#    defender.armorClass() - the AcType fold retires there
#  - regtest.cpp: the R145 weapon table audit (census 63)
#  - tools/dmg_gap_report.md: the R145 box (R144's named
#    approximation closes; the new approximations named)
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson).
# This file contains ZERO backslash characters (the
# R133b lesson); the audit printf assembles its escaped
# newline from chr(92).
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BS = chr(92)   # one backslash
NL = chr(10)   # one newline
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

old_struct = NL.join([
    '    int  weightGp;               // weight in gold-piece units (1 gp = 1/10 lb)',
    '    int  costGp;                 // list price',
    '};',
])
new_struct = NL.join([
    '    int  weightGp;               // weight in gold-piece units (1 gp = 1/10 lb)',
    '    int  costGp;                 // list price',
    "    // R145: the PHB p.38 'to hit' adjustment row, columns",
    '    // AC 0..10 (positive = easier to hit that armor)',
    '    int  acAdj[11];',
    '};',
])
old_decl = NL.join([
    '// Effective to-hit adjustment for an attack: STR adj + weapon plus +',
    "// weapon-vs-AC adjustment for the defender's armor.",
    'int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,',
    '                     uint8_t str, rules::AcType defenderAc);',
])
new_decl = NL.join([
    "// R145: the per-weapon p.38 'to hit' adjustment vs. the",
    "// defender's effective AC. The book's table runs AC 0-10;",
    '// better-than-0 reads column 0, worse-than-10 column 10.',
    '// The book keys the column to apparent armor AC (magic and',
    '// DEX do not shift it); the engine folds the full effective',
    '// AC in - a named approximation (gap report).',
    'int weaponAcAdjustment(WeaponId id, int defenderAc);',
    '',
    '// Effective to-hit adjustment for an attack: STR adj + weapon plus +',
    "// the per-weapon p.38 adjustment vs. the defender's AC.",
    'int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,',
    '                     uint8_t str, int defenderAc);',
])
old_array = NL.join([
    '// ----------------------------------------------------------------------------',
    '// Weapons (PHB p.37 table; damage vs S/M and L, missile data)',
    '// Weight in gp units (1 gp = 1/10 lb). Costs from the same table.',
    '// NOTE: values follow the standard 1e table from project notes',
    '// (verification debt - printed table wins).',
    '// ----------------------------------------------------------------------------',
    '',
    'static const WeaponDef kWeapons[WPN_COUNT] = {',
    '    // name             wclass              S/M dmg   L dmg    missile  range  rof  wt    cost',
    '    { "Dagger",         rules::WCLASS_PIERCING,   1,4,0,   1,3,0,   false,   0,  0,   20,     2 },',
    '    { "Hand Axe",       rules::WCLASS_SLASHING,   1,6,0,   1,4,0,   false,   0,  0,   50,     4 },',
    '    { "Short Sword",    rules::WCLASS_PIERCING,   1,6,0,   1,8,0,   false,   0,  0,   50,     8 },',
    '    { "Long Sword",     rules::WCLASS_SLASHING,   1,8,0,  1,12,0,   false,   0,  0,   75,    15 },',
    '    { "Battle Axe",     rules::WCLASS_SLASHING,   1,8,0,  1,8,0,    false,   0,  0,   70,     7 },',
    '    { "Mace",           rules::WCLASS_BLUDGEONING,1,6,0,  1,6,0,    false,   0,  0,   80,     8 },',
    '    { "Flail",          rules::WCLASS_BLUDGEONING,1,6,1,  2,7,1,    false,   0,  0,   80,    15 },',
    '    { "Morning Star",   rules::WCLASS_BLUDGEONING,2,4,0,  1,6,1,    false,   0,  0,  100,    10 },',
    '    { "Spear",          rules::WCLASS_PIERCING,   1,6,0,  1,8,0,    false,   0,  0,   60,     3 },',
    '    { "Quarterstaff",   rules::WCLASS_BLUDGEONING,1,6,0,  1,6,0,    false,   0,  0,   40,     0 },',
    '    { "Club",           rules::WCLASS_BLUDGEONING,1,6,0,  1,3,1,    false,   0,  0,   30,     0 },',
    '    { "Short Bow",      rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    5,  2,   20,    25 },',
    '    { "Long Bow",       rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    7,  2,   30,    40 },',
    '    { "Light Crossbow", rules::WCLASS_PIERCING,   1,4,0,  1,4,0,    true,    6,  1,   70,    10 },',
    '    { "Sling",          rules::WCLASS_BLUDGEONING,1,4,0,  1,4,1,    true,    4,  1,   10,     2 },',
    '};',
])
new_array = NL.join([
    '// ----------------------------------------------------------------------------',
    '// Weapons (PHB p.37 table; damage vs S/M and L, missile data)',
    '// Weight in gp units (1 gp = 1/10 lb). Costs from the same table.',
    '// NOTE: values follow the standard 1e table from project notes',
    '// (verification debt - printed table wins).',
    "// R145: the last member is the PHB p.38 'to hit' adjustment row",
    '// (columns AC 0..10, positive = easier), transcribed from the',
    '// 1eonline.info compilation (both p.38 charts - melee weapons',
    '// from the first, bows/crossbow/sling from the hurled/missile',
    "// chart; the sling row is the bullet's, the DMG p.71 example's",
    "// own weapon). Bow rows show the source's cell gaps (-4 to -1);",
    '// the composite bows on the same page show the same quirk, so',
    '// the rows are pinned as transcribed - the book-verify debt',
    '// stands.',
    '// ----------------------------------------------------------------------------',
    '',
    'static const WeaponDef kWeapons[WPN_COUNT] = {',
    '    // name             wclass              S/M dmg   L dmg    missile  range  rof  wt    cost  p.38 row',
    '    { "Dagger",         rules::WCLASS_PIERCING,   1,4,0,   1,3,0,   false,   0,  0,   20,     2,',
    '      // R145: p.38 row, AC 0..10',
    '      {-4,-4,-3,-3,-2,-2, 0, 0,+1,+1,+3 } },',
    '    { "Hand Axe",       rules::WCLASS_SLASHING,   1,6,0,   1,4,0,   false,   0,  0,   50,     4,',
    '      // R145: p.38 row, AC 0..10',
    '      {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+1 } },',
    '    { "Short Sword",    rules::WCLASS_PIERCING,   1,6,0,   1,8,0,   false,   0,  0,   50,     8,',
    '      // R145: p.38 row, AC 0..10',
    '      {-5,-4,-3,-2,-1, 0, 0, 0,+1, 0,+2 } },',
    '    { "Long Sword",     rules::WCLASS_SLASHING,   1,8,0,  1,12,0,   false,   0,  0,   75,    15,',
    '      // R145: p.38 row, AC 0..10',
    '      {-4,-3,-2,-1, 0, 0, 0, 0, 0,+1,+2 } },',
    '    { "Battle Axe",     rules::WCLASS_SLASHING,   1,8,0,  1,8,0,    false,   0,  0,   70,     7,',
    '      // R145: p.38 row, AC 0..10',
    '      {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+2 } },',
    '    { "Mace",           rules::WCLASS_BLUDGEONING,1,6,0,  1,6,0,    false,   0,  0,   80,     8,',
    '      // R145: p.38 row, AC 0..10',
    '      {+2,+2,+1,+1,+1, 0, 0, 0, 0,+1,-1 } },',
    '    { "Flail",          rules::WCLASS_BLUDGEONING,1,6,1,  2,7,1,    false,   0,  0,   80,    15,',
    '      // R145: p.38 row, AC 0..10',
    '      {+3,+3,+2,+1,+1,+2,+1,+1,+1,+1,-1 } },',
    '    { "Morning Star",   rules::WCLASS_BLUDGEONING,2,4,0,  1,6,1,    false,   0,  0,  100,    10,',
    '      // R145: p.38 row, AC 0..10',
    '      { 0, 0, 0,+1,+1,+1,+1,+1,+1,+2,+2 } },',
    '    { "Spear",          rules::WCLASS_PIERCING,   1,6,0,  1,8,0,    false,   0,  0,   60,     3,',
    '      // R145: p.38 row, AC 0..10',
    '      {-2,-2,-2,-1,-1,-1, 0, 0, 0, 0, 0 } },',
    '    { "Quarterstaff",   rules::WCLASS_BLUDGEONING,1,6,0,  1,6,0,    false,   0,  0,   40,     0,',
    '      // R145: p.38 row, AC 0..10',
    '      {-9,-8,-7,-5,-3,-1, 0, 0,+1,+1,+1 } },',
    '    { "Club",           rules::WCLASS_BLUDGEONING,1,6,0,  1,3,1,    false,   0,  0,   30,     0,',
    '      // R145: p.38 row, AC 0..10',
    '      {-7,-6,-5,-4,-3,-2,-1,-1, 0, 0,+1 } },',
    '    { "Short Bow",      rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    5,  2,   20,    25,',
    '      // R145: p.38 row, AC 0..10',
    '      {-7,-6,-5,-4,-1, 0, 0,+1,+2,+2,+2 } },',
    '    { "Long Bow",       rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    7,  2,   30,    40,',
    '      // R145: p.38 row, AC 0..10',
    '      {-2,-1,-1, 0, 0,+1,+2,+3,+3,+3,+3 } },',
    '    { "Light Crossbow", rules::WCLASS_PIERCING,   1,4,0,  1,4,0,    true,    6,  1,   70,    10,',
    '      // R145: p.38 row, AC 0..10',
    '      {-3,-2,-2,-1, 0, 0,+1,+2,+3,+3,+3 } },',
    '    { "Sling",          rules::WCLASS_BLUDGEONING,1,4,0,  1,4,1,    true,    4,  1,   10,     2,',
    '      // R145: p.38 row, AC 0..10',
    '      {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 } },',
    '};',
])
old_atk = NL.join([
    'int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,',
    '                     uint8_t str, rules::AcType defenderAc) {',
    '    int adj = rules::strHitAdj(str, ex);',
    '    adj += w.plus;',
    '    adj += rules::weaponVsAcAdjustment(weapon(w.id).wclass, defenderAc);',
    '    return adj;',
    '}',
])
new_atk = NL.join([
    '// R145: the per-weapon p.38 row vs. effective AC. The',
    "// book's table runs AC 0-10; the clamps read the end",
    "// columns past the table's edges. NOTE: the book applies",
    '// these rows to humans, demihumans, and humanoids only -',
    '// the engine applies them to every defender (monsters',
    '// included), a named approximation (gap report).',
    'int weaponAcAdjustment(WeaponId id, int defenderAc) {',
    '    if (defenderAc < 0) defenderAc = 0;',
    '    if (defenderAc > 10) defenderAc = 10;',
    '    return weapon(id).acAdj[defenderAc];',
    '}',
    '',
    'int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,',
    '                     uint8_t str, int defenderAc) {',
    '    int adj = rules::strHitAdj(str, ex);',
    '    adj += w.plus;',
    '    adj += weaponAcAdjustment(w.id, defenderAc);',
    '    return adj;',
    '}',
])
old_melee = NL.join([
    '    if (isCharacter) {',
    '        rules::AcType at = rules::acTypeForAc(defender.armorClass());',
    '        return items::attackAdjustment(weapon, exStr, str, at);',
    '    }',
])
new_melee = NL.join([
    '    if (isCharacter) {',
    '        // R145: the per-weapon p.38 row keys on the full',
    '        // effective AC (the old AcType fold is retired here)',
    '        return items::attackAdjustment(weapon, exStr, str,',
    '                                       defender.armorClass());',
    '    }',
])
old_missile = NL.join([
    '    if (attacker.isCharacter) {',
    '        rules::AcType at =',
    '            rules::acTypeForAc(defender.armorClass());',
    '        adj = items::attackAdjustment(',
    '            fired, rules::ExceptionalStrength{},',
    '            10, at);',
])
new_missile = NL.join([
    '    if (attacker.isCharacter) {',
    '        // R145: the per-weapon p.38 row keys on the full',
    '        // effective AC',
    '        adj = items::attackAdjustment(',
    '            fired, rules::ExceptionalStrength{},',
    '            10, defender.armorClass());',
])
old_r144_head = NL.join([
    '    // ---- R144: p.71 golden melee audit ----',
])
r145_audit = NL.join([
    '    // ---- R145: PHB p.38 weapon table audit ----',
    "    // The per-weapon 'to hit' adjustment rows - PHB p.38,",
    '    // both charts (melee weapons from the first, bows,',
    '    // crossbow, and sling from the hurled/missile chart),',
    '    // transcribed from the 1eonline.info compilation,',
    '    // the repo-trusted source; the PHB re-upload still',
    '    // owes the book-verify pass. Column order is the',
    "    // book's: AC 0..10. The 3-class approximation R144",
    '    // named closes here - the engine now carries the real',
    '    // rows; the old rules::weaponVsAcAdjustment class',
    '    // table stays pinned by the R144 audit (fallback).',
    '    {',
    '        int bad = 0;',
    '        // every cell of every row (15 x 11 = 165 pins)',
    '        static const int kRows[items::WPN_COUNT][11] = {',
    '            // Dagger',
    '            {-4,-4,-3,-3,-2,-2, 0, 0,+1,+1,+3 },',
    '            // Hand Axe',
    '            {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+1 },',
    '            // Short Sword',
    '            {-5,-4,-3,-2,-1, 0, 0, 0,+1, 0,+2 },',
    '            // Long Sword',
    '            {-4,-3,-2,-1, 0, 0, 0, 0, 0,+1,+2 },',
    '            // Battle Axe',
    '            {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+2 },',
    '            // Mace',
    '            {+2,+2,+1,+1,+1, 0, 0, 0, 0,+1,-1 },',
    '            // Flail',
    '            {+3,+3,+2,+1,+1,+2,+1,+1,+1,+1,-1 },',
    '            // Morning Star',
    '            { 0, 0, 0,+1,+1,+1,+1,+1,+1,+2,+2 },',
    '            // Spear',
    '            {-2,-2,-2,-1,-1,-1, 0, 0, 0, 0, 0 },',
    '            // Quarterstaff',
    '            {-9,-8,-7,-5,-3,-1, 0, 0,+1,+1,+1 },',
    '            // Club',
    '            {-7,-6,-5,-4,-3,-2,-1,-1, 0, 0,+1 },',
    '            // Short Bow',
    '            {-7,-6,-5,-4,-1, 0, 0,+1,+2,+2,+2 },',
    '            // Long Bow',
    '            {-2,-1,-1, 0, 0,+1,+2,+3,+3,+3,+3 },',
    '            // Light Crossbow',
    '            {-3,-2,-2,-1, 0, 0,+1,+2,+3,+3,+3 },',
    '            // Sling',
    '            {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 },',
    '        };',
    '        for (int i = 0; i < items::WPN_COUNT; ++i) {',
    '            const items::WeaponDef& w =',
    '                items::weapon((items::WeaponId)i);',
    '            for (int ac = 0; ac <= 10; ++ac)',
    '                if (w.acAdj[ac] != kRows[i][ac]) ++bad;',
    '        }',
    '        // the clamps: the table runs AC 0..10',
    '        if (items::weaponAcAdjustment(',
    '                items::WPN_DAGGER, -3) != -4) ++bad;',
    '        if (items::weaponAcAdjustment(',
    '                items::WPN_DAGGER, 12) != 3) ++bad;',
    '        // composition: STR 17 (+1), a +1 dagger, and the',
    '        // p.38 row - vs. AC 10 (+3) that is +5; vs. AC 0',
    '        // (-4) that is -2',
    '        {',
    '            items::WeaponInstance w;',
    '            w.id = items::WPN_DAGGER;',
    '            w.plus = 1;',
    '            rules::ExceptionalStrength noEx;',
    '            if (items::attackAdjustment(w, noEx, 17, 10)',
    '                != 5) ++bad;',
    '            if (items::attackAdjustment(w, noEx, 17, 0)',
    '                != -2) ++bad;',
    '        }',
    "        // the p.71 closure: the sling bullet's +3 vs. no",
    '        // armor - a named R144 approximation - is now the',
    "        // engine's own row",
    '        if (items::weaponAcAdjustment(',
    '                items::WPN_SLING, 10) != 3) ++bad;',
    "        // and the p.71 example's axe '+1 vs. no armor' is",
    "        // one of the book's editorial errors: the p.38",
    '        // battle axe row reads +2, and the engine follows',
    "        // p.38 (Gygax: the example 'slipped past and never",
    "        // got corrected')",
    '        if (items::weaponAcAdjustment(',
    '                items::WPN_BATTLE_AXE, 10) != 2) ++bad;',
    '        printf(' + chr(34) + 'R145 weapon table audit: bad %d' + BS + 'n' + chr(34) + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '',
])
old_gap = NL.join([
    '      R144 golden melee audit; census 62.',
    '',
    '## Out of scope by design',
])
new_gap = NL.join([
    '      R144 golden melee audit; census 62.',
    "- [x] **The per-weapon p.38 'to hit' table (R144's standing",
    '      approximation)** - CLOSED R145: every weapon now',
    '      carries its own PHB p.38 armor-class adjustment row',
    '      (15 weapons x 11 columns, AC 0-10), replacing the',
    '      3-class bludgeon/pierce/slash approximation at the',
    '      items::attackAdjustment choke point (the old class',
    '      table stays as the rules-layer fallback, still pinned',
    '      by the R144 audit). Rows transcribed from the',
    '      1eonline.info compilation - the repo-trusted source -',
    '      both p.38 charts (melee rows from the first, the',
    '      short bow / long bow / light crossbow / sling rows',
    '      from the hurled-and-missile chart; the sling is the',
    "      bullet's row, the DMG p.71 example's own weapon);",
    "      the PHB re-upload's book-verify debt stands (the bow",
    "      rows' cell gaps are pinned as the source prints them -",
    '      the composite bows show the same quirk). Standing',
    '      approximations, named: (1) the column is the',
    "      defender's full effective AC (magic, DEX, and shield",
    '      all shift the column; the book keys apparent armor AC',
    '      and says magic/DEX do not shift it); (2) the rows',
    '      apply to every defender - monsters included - where',
    '      the book limits them to humans, demihumans, and',
    "      humanoids; (3) below AC 0 reads column 0 (the book's",
    '      table stops at AC 0); (4) Gygax himself ignored the',
    "      table (the 1eonline FAQ and Delta's D&D Hotspot both",
    '      note it) - the engine pins it anyway, by design. The',
    "      p.71 example's sling bullet +3 vs. no armor - R144's",
    "      named approximation - is now the engine's own row; the",
    "      example's axe '+1 vs. no armor' remains one of its",
    '      acknowledged editorial errors (the p.38 battle axe row',
    "      reads +2, and the engine follows p.38); the example's",
    '      hammer has no engine weapon (the 15-weapon registry',
    '      carries no war hammer - the R144 pin stands). Pinned by',
    '      the R145',
    '      weapon table audit; census 63.',
    '',
    '## Out of scope by design',
])
old_r144_head = NL.join([
    '    // ---- R144: p.71 golden melee audit ----',
])
r145_audit = NL.join([
    '    // ---- R145: PHB p.38 weapon table audit ----',
    "    // The per-weapon 'to hit' adjustment rows - PHB p.38,",
    '    // both charts (melee weapons from the first, bows,',
    '    // crossbow, and sling from the hurled/missile chart),',
    '    // transcribed from the 1eonline.info compilation,',
    '    // the repo-trusted source; the PHB re-upload still',
    '    // owes the book-verify pass. Column order is the',
    "    // book's: AC 0..10. The 3-class approximation R144",
    '    // named closes here - the engine now carries the real',
    '    // rows; the old rules::weaponVsAcAdjustment class',
    '    // table stays pinned by the R144 audit (fallback).',
    '    {',
    '        int bad = 0;',
    '        // every cell of every row (15 x 11 = 165 pins)',
    '        static const int kRows[items::WPN_COUNT][11] = {',
    '            // Dagger',
    '            {-4,-4,-3,-3,-2,-2, 0, 0,+1,+1,+3 },',
    '            // Hand Axe',
    '            {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+1 },',
    '            // Short Sword',
    '            {-5,-4,-3,-2,-1, 0, 0, 0,+1, 0,+2 },',
    '            // Long Sword',
    '            {-4,-3,-2,-1, 0, 0, 0, 0, 0,+1,+2 },',
    '            // Battle Axe',
    '            {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+2 },',
    '            // Mace',
    '            {+2,+2,+1,+1,+1, 0, 0, 0, 0,+1,-1 },',
    '            // Flail',
    '            {+3,+3,+2,+1,+1,+2,+1,+1,+1,+1,-1 },',
    '            // Morning Star',
    '            { 0, 0, 0,+1,+1,+1,+1,+1,+1,+2,+2 },',
    '            // Spear',
    '            {-2,-2,-2,-1,-1,-1, 0, 0, 0, 0, 0 },',
    '            // Quarterstaff',
    '            {-9,-8,-7,-5,-3,-1, 0, 0,+1,+1,+1 },',
    '            // Club',
    '            {-7,-6,-5,-4,-3,-2,-1,-1, 0, 0,+1 },',
    '            // Short Bow',
    '            {-7,-6,-5,-4,-1, 0, 0,+1,+2,+2,+2 },',
    '            // Long Bow',
    '            {-2,-1,-1, 0, 0,+1,+2,+3,+3,+3,+3 },',
    '            // Light Crossbow',
    '            {-3,-2,-2,-1, 0, 0,+1,+2,+3,+3,+3 },',
    '            // Sling',
    '            {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 },',
    '        };',
    '        for (int i = 0; i < items::WPN_COUNT; ++i) {',
    '            const items::WeaponDef& w =',
    '                items::weapon((items::WeaponId)i);',
    '            for (int ac = 0; ac <= 10; ++ac)',
    '                if (w.acAdj[ac] != kRows[i][ac]) ++bad;',
    '        }',
    '        // the clamps: the table runs AC 0..10',
    '        if (items::weaponAcAdjustment(',
    '                items::WPN_DAGGER, -3) != -4) ++bad;',
    '        if (items::weaponAcAdjustment(',
    '                items::WPN_DAGGER, 12) != 3) ++bad;',
    '        // composition: STR 17 (+1), a +1 dagger, and the',
    '        // p.38 row - vs. AC 10 (+3) that is +5; vs. AC 0',
    '        // (-4) that is -2',
    '        {',
    '            items::WeaponInstance w;',
    '            w.id = items::WPN_DAGGER;',
    '            w.plus = 1;',
    '            rules::ExceptionalStrength noEx;',
    '            if (items::attackAdjustment(w, noEx, 17, 10)',
    '                != 5) ++bad;',
    '            if (items::attackAdjustment(w, noEx, 17, 0)',
    '                != -2) ++bad;',
    '        }',
    "        // the p.71 closure: the sling bullet's +3 vs. no",
    '        // armor - a named R144 approximation - is now the',
    "        // engine's own row",
    '        if (items::weaponAcAdjustment(',
    '                items::WPN_SLING, 10) != 3) ++bad;',
    "        // and the p.71 example's axe '+1 vs. no armor' is",
    "        // one of the book's editorial errors: the p.38",
    '        // battle axe row reads +2, and the engine follows',
    "        // p.38 (Gygax: the example 'slipped past and never",
    "        // got corrected')",
    '        if (items::weaponAcAdjustment(',
    '                items::WPN_BATTLE_AXE, 10) != 2) ++bad;',
    '        printf(' + chr(34) + 'R145 weapon table audit: bad %d' + BS + 'n' + chr(34) + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '',
])
old_gap = NL.join([
    '      R144 golden melee audit; census 62.',
    '',
    '## Out of scope by design',
])
new_gap = NL.join([
    '      R144 golden melee audit; census 62.',
    "- [x] **The per-weapon p.38 'to hit' table (R144's standing",
    '      approximation)** - CLOSED R145: every weapon now',
    '      carries its own PHB p.38 armor-class adjustment row',
    '      (15 weapons x 11 columns, AC 0-10), replacing the',
    '      3-class bludgeon/pierce/slash approximation at the',
    '      items::attackAdjustment choke point (the old class',
    '      table stays as the rules-layer fallback, still pinned',
    '      by the R144 audit). Rows transcribed from the',
    '      1eonline.info compilation - the repo-trusted source -',
    '      both p.38 charts (melee rows from the first, the',
    '      short bow / long bow / light crossbow / sling rows',
    '      from the hurled-and-missile chart; the sling is the',
    "      bullet's row, the DMG p.71 example's own weapon);",
    "      the PHB re-upload's book-verify debt stands (the bow",
    "      rows' cell gaps are pinned as the source prints them -",
    '      the composite bows show the same quirk). Standing',
    '      approximations, named: (1) the column is the',
    "      defender's full effective AC (magic, DEX, and shield",
    '      all shift the column; the book keys apparent armor AC',
    '      and says magic/DEX do not shift it); (2) the rows',
    '      apply to every defender - monsters included - where',
    '      the book limits them to humans, demihumans, and',
    "      humanoids; (3) below AC 0 reads column 0 (the book's",
    '      table stops at AC 0); (4) Gygax himself ignored the',
    "      table (the 1eonline FAQ and Delta's D&D Hotspot both",
    '      note it) - the engine pins it anyway, by design. The',
    "      p.71 example's sling bullet +3 vs. no armor - R144's",
    "      named approximation - is now the engine's own row; the",
    "      example's axe '+1 vs. no armor' remains one of its",
    '      acknowledged editorial errors (the p.38 battle axe row',
    "      reads +2, and the engine follows p.38); the example's",
    '      hammer has no engine weapon (the 15-weapon registry',
    '      carries no war hammer - the R144 pin stands). Pinned by',
    '      the R145',
    '      weapon table audit; census 63.',
    '',
    '## Out of scope by design',
])
patch("items/items.h", old_struct, new_struct,
      "items.h: acAdj member")
assert len(applied) + len(already) == 1

patch("items/items.h", old_decl, new_decl,
      "items.h: decls", marker="weaponAcAdjustment")
assert len(applied) + len(already) == 2

patch("items/items.cpp", old_array, new_array,
      "items.cpp: kWeapons rows", marker="acAdj")
assert len(applied) + len(already) == 3

patch("items/items.cpp", old_atk, new_atk,
      "items.cpp: the choke point swap")
assert len(applied) + len(already) == 4

patch("ai/actor.cpp", old_melee, new_melee,
      "actor.cpp: melee site")
assert len(applied) + len(already) == 5

patch("ai/actor.cpp", old_missile, new_missile,
      "actor.cpp: missile site")
assert len(applied) + len(already) == 6

patch("regtest.cpp", old_r144_head + NL,
      r145_audit + old_r144_head + NL,
      "regtest.cpp: R145 audit",
      marker="R145 weapon table audit")
assert len(applied) + len(already) == 7

patch("tools/dmg_gap_report.md", old_gap, new_gap,
      "gap report: R145 box", marker="CLOSED R145:")
assert len(applied) + len(already) == 8

# ---- R145 fails/tail ----
if fails:
    print("R145 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 8:
    print("R145 splice: FAIL - expected 8 patches, "
          "counted " + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R145 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R145 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
