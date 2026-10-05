#!/usr/bin/env python3
# R203 splice: the apparent-armor-AC repin - the p.38
# weapon-vs-AC key. The DMG p.38 note: the
# weapon-type adjustments are "for weapons versus
# specific types of armor, not necessarily against
# actual armor class" - the column keys to the
# armor the defender wears, never to the magic/
# DEX-shifted effective AC. The engine folded
# the full effective AC in - a named
# approximation in the gap report since R144.
# This round closes it:
#   - items::apparentArmorAc(armor, shield) -
#     the armor's own printed AC: base + shield
#     one better; plus and DEX do not shift it
#   - attackAdjustment / weaponAcAdjustment
#     repinned to the armor-AC key (the callers
#     pass the defender's apparent armor AC; the
#     to-hit TARGET still reads the full effective
#     AC - only the p.38 row key changes)
#   - the two callers in ai/actor.cpp (melee
#     hitAdjustment, the missile path) pass
#     apparentArmorAc(defender.armor,
#     defender.shield)
# A monster defender wears no armor: its row keys
# the no-armor column 10 - armor-truthful, the
# apply-rows-to-every-defender approximation
# unchanged and still named.
# Patches: 7 (items.h, items.cpp x2, actor.cpp x2,
# regtest.cpp, dmg_gap_report.md). Census 118 -> 119.

BS = chr(92)
NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique
    global applied, already
    t = rd(path)
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: items/items.h - the declaration repin + apparentArmorAc
# ---------------------------------------------------------------------------

old1 = ('// R145: the per-weapon p.38 ' + chr(39) + 'to hit' + chr(39) + ' adjustment vs. the'
        + NL + '// defender' + chr(39) + 's effective AC. The book' + chr(39) + 's table runs AC 0-10;'
        + NL + '// better-than-0 reads column 0, worse-than-10 column 10.'
        + NL + '// The book keys the column to apparent armor AC (magic and'
        + NL + '// DEX do not shift it); the engine folds the full effective'
        + NL + '// AC in - a named approximation (gap report).'
        + NL + 'int weaponAcAdjustment(WeaponId id, int defenderAc);'
        + NL
        + NL + '// Effective to-hit adjustment for an attack: STR adj + weapon plus +'
        + NL + '// the per-weapon p.38 adjustment vs. the defender' + chr(39) + 's AC.'
        + NL + 'int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,'
        + NL + '                     uint8_t str, int defenderAc);')

new1 = ('// R145: the per-weapon p.38 ' + chr(39) + 'to hit' + chr(39) + ' adjustment vs. the'
        + NL + '// defender' + chr(39) + 's APPARENT ARMOR AC. The book' + chr(39) + 's table runs'
        + NL + '// AC 0-10; better-than-0 reads column 0, worse-than-10'
        + NL + '// column 10. R203 closes the named approximation: the'
        + NL + '// column keys to the armor the defender wears - armor'
        + NL + '// base + shield, magic and DEX do not shift it - per the'
        + NL + '// book' + chr(39) + 's own p.38 note: the adjustments are for weapons'
        + NL + '// versus specific types of armor, not necessarily against'
        + NL + '// actual armor class.'
        + NL + 'int weaponAcAdjustment(WeaponId id, int defenderArmorAc);'
        + NL
        + NL + '// R203: the apparent armor AC - the armor' + chr(39) + 's own printed AC,'
        + NL + '// armor base + shield one better. The enchantment plus and'
        + NL + '// the DEX defensive adjustment do NOT shift it - this is'
        + NL + '// the p.38 column key, distinct from effectiveAc.'
        + NL + 'int apparentArmorAc(const ArmorInstance& a, bool shield);'
        + NL
        + NL + '// Effective to-hit adjustment for an attack: STR adj + weapon plus +'
        + NL + '// the per-weapon p.38 adjustment vs. the defender' + chr(39) + 's apparent'
        + NL + '// armor AC.'
        + NL + 'int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,'
        + NL + '                     uint8_t str, int defenderArmorAc);')

patch('items/items.h',
      'R203: the apparent armor AC - the armor',
      old1,
      new1)

# ---------------------------------------------------------------------------
# Patch 2: items/items.cpp - the comment repin
# ---------------------------------------------------------------------------

old2 = ('// R145: the per-weapon p.38 row vs. effective AC. The'
        + NL + '// book' + chr(39) + 's table runs AC 0-10; the clamps read the end'
        + NL + '// columns past the table' + chr(39) + 's edges. NOTE: the book applies'
        + NL + '// these rows to humans, demihumans, and humanoids only -'
        + NL + '// the engine applies them to every defender (monsters'
        + NL + '// included), a named approximation (gap report).'
        + NL + 'int weaponAcAdjustment(WeaponId id, int defenderAc) {'
        + NL + '    if (defenderAc < 0) defenderAc = 0;'
        + NL + '    if (defenderAc > 10) defenderAc = 10;'
        + NL + '    return weapon(id).acAdj[defenderAc];'
        + NL + '}')

new2 = ('// R145: the per-weapon p.38 row vs. the defender' + chr(39) + 's apparent'
        + NL + '// armor AC (R203 - the effective-AC fold is retired). The'
        + NL + '// book' + chr(39) + 's table runs AC 0-10; the clamps read the end'
        + NL + '// columns past the table' + chr(39) + 's edges. NOTE: the book applies'
        + NL + '// these rows to humans, demihumans, and humanoids only -'
        + NL + '// the engine applies them to every defender (monsters'
        + NL + '// included), a named approximation (gap report).'
        + NL + 'int weaponAcAdjustment(WeaponId id, int defenderArmorAc) {'
        + NL + '    if (defenderArmorAc < 0) defenderArmorAc = 0;'
        + NL + '    if (defenderArmorAc > 10) defenderArmorAc = 10;'
        + NL + '    return weapon(id).acAdj[defenderArmorAc];'
        + NL + '}')

patch('items/items.cpp',
      'the effective-AC fold is retired',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: items/items.cpp - apparentArmorAc + the renamed parameter
# ---------------------------------------------------------------------------

old3 = ('int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,'
        + NL + '                     uint8_t str, int defenderAc) {'
        + NL + '    int adj = rules::strHitAdj(str, ex);'
        + NL + '    adj += w.plus;'
        + NL + '    adj += weaponAcAdjustment(w.id, defenderAc);'
        + NL + '    return adj;'
        + NL + '}')

new3 = ('// R203: the apparent armor AC - the p.38 column key. The'
        + NL + '// armor' + chr(39) + 's own printed AC: base + shield one better;'
        + NL + '// the enchantment plus and the DEX defensive adjustment do'
        + NL + '// NOT shift it (the to-hit target still reads the full'
        + NL + '// effective AC - only the p.38 row key uses this).'
        + NL + 'int apparentArmorAc(const ArmorInstance& a, bool shield) {'
        + NL + '    int ac = armor(a.id).baseAc;'
        + NL + '    if (shield) ac -= 1;'
        + NL + '    return ac;'
        + NL + '}'
        + NL
        + NL + 'int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,'
        + NL + '                     uint8_t str, int defenderArmorAc) {'
        + NL + '    int adj = rules::strHitAdj(str, ex);'
        + NL + '    adj += w.plus;'
        + NL + '    adj += weaponAcAdjustment(w.id, defenderArmorAc);'
        + NL + '    return adj;'
        + NL + '}')

patch('items/items.cpp',
      'R203: the apparent armor AC - the p.38 column key',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: ai/actor.cpp - the melee hitAdjustment caller
# ---------------------------------------------------------------------------

old4 = ('    if (isCharacter) {'
        + NL + '        // R145: the per-weapon p.38 row keys on the full'
        + NL + '        // effective AC (the old AcType fold is retired here)'
        + NL + '        return items::attackAdjustment(weapon, exStr, str,'
        + NL + '                                       defender.armorClass());'
        + NL + '    }')

new4 = ('    if (isCharacter) {'
        + NL + '        // R203: the per-weapon p.38 row keys on the'
        + NL + '        // defender' + chr(39) + 's apparent armor AC - the armor'
        + NL + '        // worn with shield; the magic/DEX-shifted effective'
        + NL + '        // AC stays the to-hit target, not the row key'
        + NL + '        return items::attackAdjustment(weapon, exStr, str,'
        + NL + '                items::apparentArmorAc(defender.armor,'
        + NL + '                                       defender.shield));'
        + NL + '    }')

patch('ai/actor.cpp',
      'R203: the per-weapon p.38 row keys on the',
      old4,
      new4)

# ---------------------------------------------------------------------------
# Patch 5: ai/actor.cpp - the missile path caller
# ---------------------------------------------------------------------------

old5 = ('        // R145: the per-weapon p.38 row keys on the full'
        + NL + '        // effective AC'
        + NL + '        adj = items::attackAdjustment('
        + NL + '            fired, rules::ExceptionalStrength{},'
        + NL + '            10, defender.armorClass());')

new5 = ('        // R203: missiles too - the per-weapon p.38 row keys'
        + NL + '        // on the defender' + chr(39) + 's apparent armor AC'
        + NL + '        adj = items::attackAdjustment('
        + NL + '            fired, rules::ExceptionalStrength{},'
        + NL + '            10, items::apparentArmorAc(defender.armor,'
        + NL + '                                       defender.shield));')

patch('ai/actor.cpp',
      'R203: missiles too - the per-weapon p.38 row keys',
      old5,
      new5)

# ---------------------------------------------------------------------------
# Patch 6: regtest.cpp - the R203 battery audit (census 119)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R203: the apparent armor AC audit ----')
a('    // The p.38 column key repin: the row keys the armor')
a('    // worn - base + shield - never the magic/DEX-shifted')
a('    // effective AC. The book: the adjustments are for')
a('    // weapons versus specific types of armor, not')
a('    // necessarily against actual armor class.')
a('    {')
a('        int bad = 0;')
a('        // the apparent armor AC cells: armor base + shield')
a('        {')
a('            items::ArmorInstance ar;')
a('            ar.id = items::ARMOR_NONE_EQUIPPED;')
a('            if (items::apparentArmorAc(ar, false) != 10) ++bad;')
a('            // the shield column: the book prints shield')
a('            // only as AC 9')
a('            if (items::apparentArmorAc(ar, true) != 9) ++bad;')
a('            ar.id = items::ARMOR_LEATHER;')
a('            if (items::apparentArmorAc(ar, false) != 8) ++bad;')
a('            if (items::apparentArmorAc(ar, true) != 7) ++bad;')
a('            ar.id = items::ARMOR_PLATE;')
a('            if (items::apparentArmorAc(ar, false) != 3) ++bad;')
a('            if (items::apparentArmorAc(ar, true) != 2) ++bad;')
a('        }')
a('        // the enchantment plus does NOT shift the key')
a('        {')
a('            items::ArmorInstance ar;')
a('            ar.id = items::ARMOR_PLATE;')
a('            ar.plus = 5;')
a('            if (items::apparentArmorAc(ar, false) != 3) ++bad;')
a('        }')
a('        // the contrast: DEX and plus shift the effective AC,')
a('        // never the apparent - a plate +2, shield, DEX 18')
a('        // defender reads effective -4, apparent 2')
a('        {')
a('            items::ArmorInstance ar;')
a('            ar.id = items::ARMOR_PLATE;')
a('            ar.plus = 2;')
a('            rules::ExceptionalStrength noEx;')
a('            int eff = items::effectiveAc(ar, true, 0, 18);')
a('            int app = items::apparentArmorAc(ar, true);')
a('            if (eff != -4) ++bad;   // the to-hit target')
a('            if (app != 2) ++bad;    // the p.38 row key')
a('            // the dagger row keyed each way: the old fold')
a('            // read column 0 (-4); the repin reads column 2')
a('            // (-3) - the fix, pinned as two exact values')
a('            if (items::weaponAcAdjustment(')
a('                    items::WPN_DAGGER, eff) != -4) ++bad;')
a('            if (items::weaponAcAdjustment(')
a('                    items::WPN_DAGGER, app) != -3) ++bad;')
a('            // the composition chain: STR 10 neutral, no')
a('            // enchant, dagger vs the plate-and-shield')
a('            // defender - the row reads the armor, -3')
a('            items::WeaponInstance w;')
a('            w.id = items::WPN_DAGGER;')
a('            if (items::attackAdjustment(w, noEx, 10, app) != -3)')
a('                ++bad;')
a('            // and keyed on the effective AC it would read')
a('            // -4 - the retired approximation, pinned')
a('            if (items::attackAdjustment(w, noEx, 10, eff) != -4)')
a('                ++bad;')
a('        }')
a('        // the shield-only column: dagger vs AC 9 reads +1')
a('        {')
a('            items::ArmorInstance ar;')
a('            ar.id = items::ARMOR_NONE_EQUIPPED;')
a('            int app = items::apparentArmorAc(ar, true);')
a('            if (app != 9) ++bad;')
a('            if (items::weaponAcAdjustment(')
a('                    items::WPN_DAGGER, app) != 1) ++bad;')
a('        }')
a('        printf("R203 apparent armor AC audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R201 NPC monk alignment audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R203 apparent armor AC audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# Patch 7: tools/dmg_gap_report.md - the round-log entry (R202 convention:
# the log entry lands in the same commit)
# ---------------------------------------------------------------------------

entry = (
    'R203 landed the apparent-armor-AC repin - the p.38'
    + NL + 'weapon-vs-armor column keys the armor the defender'
    + NL + 'wears, not the magic/DEX-shifted effective AC (the DMG'
    + NL + 'p.38 note: the adjustments are "for weapons versus'
    + NL + 'specific types of armor, not necessarily against'
    + NL + 'actual armor class"). items::apparentArmorAc(armor,'
    + NL + 'shield) - armor base + shield one better, the plus and'
    + NL + 'DEX do not shift it - is the new p.38 row key;'
    + NL + 'weaponAcAdjustment/attackAdjustment read defenderArmorAc;'
    + NL + 'the two ai/actor.cpp callers pass apparentArmorAc. The'
    + NL + 'to-hit target still reads the full effective AC; the'
    + NL + 'monster approximation (rows applied to every defender)'
    + NL + 'stays named. Closes the R144/R145 named approximation.'
    + NL + 'New R203 battery audit; census 119. Next: the DMG-only'
    + NL + 'tables still unpinned.')

log_old = ('Next: the DMG-only tables still unpinned.'
           + NL + NL + 'Categories:')

log_new = ('Next: the DMG-only tables still unpinned.'
           + NL + NL + entry + NL + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R203 landed the apparent-armor-AC repin',
      log_old,
      log_new)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 7, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R203 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R203 note: 7 patches; the p.38 row key repinned - the apparent')
print('armor AC (armor + shield, no plus, no DEX) replaces the effective-')
print('AC fold, the named approximation closed; the log entry rides')
print('this commit; census 119.')
print('commit: R203: the apparent armor AC repin - the p.38 weapon-vs-armor')
print('column keys the armor worn, not the effective AC (census 119)')

