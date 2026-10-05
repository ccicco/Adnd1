#!/usr/bin/env python3
# R198 splice: the class weapon allowlists - the
# CHARACTER CLASSES TABLE II weapons column (PHB
# p.22 area), the monk weapon list's home. The
# engine holds the weight/damage chart (R189) and
# the speed verify (R158) but NO class-allowance
# data: nothing says a cleric cannot swing a
# sword, or which ten weapons a monk may use.
# This round pins the print cell for cell:
#   cleric    club, flail, hammer, mace, staff
#   druid     club, dagger, dart, hammer, scimitar,
#             sling, spear, staff
#   fighter   any (footnote: size caveats)
#   paladin   any (footnote: never poison)
#   ranger    any
#   MU        dagger, dart, staff
#   illusionist dagger, dart, staff
#   thief     club, dagger, dart, sling, sword -
#             the footnote: short, broad or long
#             sword but NOT bastard or two-handed
#   assassin  any (leather armor, any shield)
#   monk      bo stick, club, crossbow, dagger,
#             hand axe, javelin, jo stick, pole
#             arm, spear, staff
# JUDGMENTs (recorded in the header):
#   - the print's family words expand to the
#     chart variants: flail = footman + horseman
#     flail, mace = footman + horseman mace,
#     staff = quarterstaff, sling = sling bullet
#     + sling stone, hammer = the plain hammer
#     (the lucern hammer is a pole arm, not the
#     cleric print row).
#   - monk pole arm = the chart's 15 pole-arm
#     rows (bardiche through voulge, the forked
#     and glaive families, the halberd, partisan,
#     ranseur, spetum) - the awl pike and the
#     picks are not the print's pole arm family.
#   - crossbow: the chart prints no crossbow row
#     (only its quarrels) - it pins by name for
#     the monk and no one else.
# Patches: 2 (weapontables.h, regtest.cpp).
# Census 114 -> 115 (one new audit).

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
# Patch 1: rules/weapontables.h - the class allowlists (the print cell)
# ---------------------------------------------------------------------------

comment = ('// ----------------------------------------------------------------------------'
           + NL + '// R198: the class weapon allowlists - the CHARACTER CLASSES'
           + NL + '// TABLE II weapons column (the print, cell for cell). The'
           + NL + '// class rows in the printed order:'
           + NL + '//   0 cleric, 1 druid, 2 fighter, 3 paladin, 4 ranger,'
           + NL + '//   5 magic-user, 6 illusionist, 7 thief, 8 assassin,'
           + NL + '//   9 monk.'
           + NL + '// The fighter, paladin, ranger and assassin rows read any'
           + NL + '// - classUsesAnyWeapon; the limited rows name the chart'
           + NL + '// rows they allow. JUDGMENTs: the family words expand to'
           + NL + '// the chart variants - flail = footman and horseman flail,'
           + NL + '// mace = footman and horseman mace, staff = quarterstaff,'
           + NL + '// sling = sling bullet and sling stone, hammer = the plain'
           + NL + '// hammer alone - the lucern hammer is a pole arm, not the'
           + NL + '// cleric print row. The thief footnote: short, broad or'
           + NL + '// long sword but not bastard or two-handed. The monk pole'
           + NL + '// arm = the chart 15 pole-arm rows below; the awl pike and'
           + NL + '// the picks stay out. The crossbow prints no chart row of'
           + NL + '// its own - only its quarrels do - so it pins by name for'
           + NL + '// the monk and no one else.'
           + NL + '// ----------------------------------------------------------------------------')

rows = []
rows.append('    static const char* const kCleric[7] = {')
rows.append('        "club", "footman flail", "horseman flail",')
rows.append('        "hammer", "footman mace", "horseman mace",')
rows.append('        "quarterstaff"')
rows.append('    };')
rows.append('    static const char* const kDruid[9] = {')
rows.append('        "club", "dagger", "dart", "hammer", "scimitar",')
rows.append('        "sling bullet", "sling stone", "spear",')
rows.append('        "quarterstaff"')
rows.append('    };')
rows.append('    static const char* const kMuIll[3] = {')
rows.append('        "dagger", "dart", "quarterstaff"')
rows.append('    };')
rows.append('    static const char* const kThief[8] = {')
rows.append('        "club", "dagger", "dart", "sling bullet",')
rows.append('        "sling stone", "short sword", "broad sword",')
rows.append('        "long sword"')
rows.append('    };')
rows.append('    static const char* const kMonk[24] = {')
rows.append('        "bo stick", "club", "crossbow", "dagger",')
rows.append('        "hand axe", "javelin", "jo stick", "spear",')
rows.append('        "quarterstaff",')
rows.append('        "bardiche", "bec de corbin", "bill-guisarme",')
rows.append('        "fauchard", "fauchard-fork", "military fork",')
rows.append('        "glaive", "glaive-guisarme", "guisarme",')
rows.append('        "guisarme-voulge", "halberd", "partisan",')
rows.append('        "ransseur", "spetum", "voulge"')
rows.append('    };')

body = []
body.append('inline bool classUsesAnyWeapon(int cls) {')
body.append('    return cls == 2 || cls == 3 || cls == 4 || cls == 8;')
body.append('}')
body.append('')
body.append('// The allowed weapon count, -1 on the any-weapon rows.')
body.append('inline int classAllowedWeaponCount(int cls) {')
body.append('    if (classUsesAnyWeapon(cls)) return -1;')
body.append('    if (cls == 0) return 7;    // cleric')
body.append('    if (cls == 1) return 9;    // druid')
body.append('    if (cls == 5 || cls == 6) return 3;    // MU, illusionist')
body.append('    if (cls == 7) return 8;    // thief')
body.append('    if (cls == 9) return 24;   // monk')
body.append('    return 0;')
body.append('}')
body.append('')
body.append('// The allowed chart name at index i (clamped).')
body.append('inline const char* classAllowedWeaponName(int cls, int i) {')
body.append('    if (i < 0) i = 0;')

def rowFn(enumname, arrname, cnt, rowcomment):
    out = []
    out.append('    if (cls == ' + enumname + ') {')
    out.append('        if (i > ' + str(cnt - 1) + ') i = ' + str(cnt - 1) + ';')
    out.append('        return ' + arrname + '[i];   // ' + rowcomment)
    out.append('    }')
    return out

for enumname, arrname, cnt, rowcomment in [
        ('0', 'kCleric', 7, 'cleric'),
        ('1', 'kDruid', 9, 'druid'),
        ('5', 'kMuIll', 3, 'MU and illusionist'),
        ('6', 'kMuIll', 3, 'illusionist, the same list'),
        ('7', 'kThief', 8, 'thief'),
        ('9', 'kMonk', 24, 'monk')]:
    body.extend(rowFn(enumname, arrname, cnt, rowcomment))

body.append('    return "club";   // out-of-range clamps')
body.append('}')
body.append('')
body.append('// The engine question: can class cls use the named')
body.append('// weapon? The any-weapon rows take everything.')
body.append('inline bool weaponAllowedForClass(int cls,')
body.append('                                   const char* weaponName) {')
body.append('    if (weaponName == 0) return false;')
body.append('    if (classUsesAnyWeapon(cls)) return true;')
body.append('    int n = classAllowedWeaponCount(cls);')
body.append('    if (n <= 0) return false;')
body.append('    for (int i = 0; i < n; ++i) {')
body.append('        const char* a = classAllowedWeaponName(cls, i);')
body.append('        const char* b = weaponName;')
body.append('        while (*a && *b && *a == *b) { ++a; ++b; }')
body.append('        if (*a == 0 && *b == 0) return true;   // exact match')
body.append('    }')
body.append('    return false;')
body.append('}')

new_hdr = ('inline int weaponStunnedProneMotionlessBonus() {'
           + NL + '    return 4;'
           + NL + '}'
           + NL
           + NL + comment
           + NL
           + NL + NL.join(rows)
           + NL
           + NL + NL.join(body)
           + NL
           + NL + '} // namespace rules')

old_hdr = ('inline int weaponStunnedProneMotionlessBonus() {'
           + NL + '    return 4;'
           + NL + '}'
           + NL
           + NL + '} // namespace rules')

patch('rules/weapontables.h',
      'R198: the class weapon allowlists',
      old_hdr,
      new_hdr)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the R198 battery audit (census 115)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R198: the class weapon allowlists audit ----')
a('    // The CHARACTER CLASSES TABLE II weapons column, cell')
a('    // for cell: the any-weapon rows, the limited lists, the')
a('    // family expansions, the thief sword footnote, the monk')
a('    // pole-arm family and the crossbow.')
a('    {')
a('        int bad = 0;')
a('        // the any-weapon rows')
a('        if (!rules::classUsesAnyWeapon(2)) ++bad;   // fighter')
a('        if (!rules::classUsesAnyWeapon(3)) ++bad;   // paladin')
a('        if (!rules::classUsesAnyWeapon(4)) ++bad;   // ranger')
a('        if (!rules::classUsesAnyWeapon(8)) ++bad;   // assassin')
a('        if (rules::classUsesAnyWeapon(0)) ++bad;    // cleric')
a('        if (rules::classUsesAnyWeapon(1)) ++bad;    // druid')
a('        if (rules::classUsesAnyWeapon(5)) ++bad;    // MU')
a('        if (rules::classUsesAnyWeapon(6)) ++bad;    // illusionist')
a('        if (rules::classUsesAnyWeapon(7)) ++bad;    // thief')
a('        if (rules::classUsesAnyWeapon(9)) ++bad;    // monk')
a('        // the counts')
a('        static const int kCount[10] = {')
a('             7,  9, -1, -1, -1,  3,  3,  8, -1, 24')
a('        };')
a('        for (int c = 0; c < 10; ++c) {')
a('            if (rules::classAllowedWeaponCount(c)')
a('                != kCount[c]) ++bad;')
a('        }')
a('        // the monk list, the ten printed weapons')
a('        if (!rules::weaponAllowedForClass(9, "bo stick")) ++bad;')
a('        if (!rules::weaponAllowedForClass(9, "club")) ++bad;')
a('        if (!rules::weaponAllowedForClass(9, "crossbow")) ++bad;')
a('        if (!rules::weaponAllowedForClass(9, "dagger")) ++bad;')
a('        if (!rules::weaponAllowedForClass(9, "hand axe")) ++bad;')
a('        if (!rules::weaponAllowedForClass(9, "javelin")) ++bad;')
a('        if (!rules::weaponAllowedForClass(9, "jo stick")) ++bad;')
a('        if (!rules::weaponAllowedForClass(9, "spear")) ++bad;')
a('        if (!rules::weaponAllowedForClass(9, "quarterstaff"))')
a('            ++bad;')
a('        // the monk pole-arm family, all 15 rows')
a('        static const char* const kPoleArm[15] = {')
a('            "bardiche", "bec de corbin", "bill-guisarme",')
a('            "fauchard", "fauchard-fork", "military fork",')
a('            "glaive", "glaive-guisarme", "guisarme",')
a('            "guisarme-voulge", "halberd", "partisan",')
a('            "ransseur", "spetum", "voulge"')
a('        };')
a('        for (int i = 0; i < 15; ++i) {')
a('            if (!rules::weaponAllowedForClass(9, kPoleArm[i]))')
a('                ++bad;')
a('            // the family is the monk print - not the MU or thief')
a('            if (rules::weaponAllowedForClass(5, kPoleArm[i]))')
a('                ++bad;')
a('            if (rules::weaponAllowedForClass(7, kPoleArm[i]))')
a('                ++bad;')
a('        }')
a('        // what the monk denies')
a('        if (rules::weaponAllowedForClass(9, "battle axe")) ++bad;')
a('        if (rules::weaponAllowedForClass(9, "long sword")) ++bad;')
a('        if (rules::weaponAllowedForClass(9, "morning star")) ++bad;')
a('        // the cleric list, the family expansions')
a('        if (!rules::weaponAllowedForClass(0, "club")) ++bad;')
a('        if (!rules::weaponAllowedForClass(0, "footman flail"))')
a('            ++bad;')
a('        if (!rules::weaponAllowedForClass(0, "horseman flail"))')
a('            ++bad;')
a('        if (!rules::weaponAllowedForClass(0, "hammer")) ++bad;')
a('        if (!rules::weaponAllowedForClass(0, "footman mace"))')
a('            ++bad;')
a('        if (!rules::weaponAllowedForClass(0, "horseman mace"))')
a('            ++bad;')
a('        if (!rules::weaponAllowedForClass(0, "quarterstaff")) ++bad;')
a('        // the cleric denies')
a('        if (rules::weaponAllowedForClass(0, "dagger")) ++bad;')
a('        if (rules::weaponAllowedForClass(0, "short sword")) ++bad;')
a('        if (rules::weaponAllowedForClass(0, "scimitar")) ++bad;')
a('        if (rules::weaponAllowedForClass(0, "lucern hammer")) ++bad;')
a('        // the druid list')
a('        if (!rules::weaponAllowedForClass(1, "scimitar")) ++bad;')
a('        if (!rules::weaponAllowedForClass(1, "spear")) ++bad;')
a('        if (!rules::weaponAllowedForClass(1, "hammer")) ++bad;')
a('        if (!rules::weaponAllowedForClass(1, "sling bullet"))')
a('            ++bad;')
a('        if (!rules::weaponAllowedForClass(1, "sling stone")) ++bad;')
a('        if (!rules::weaponAllowedForClass(1, "quarterstaff")) ++bad;')
a('        if (rules::weaponAllowedForClass(1, "footman mace")) ++bad;')
a('        if (rules::weaponAllowedForClass(1, "long sword")) ++bad;')
a('        // the MU and illusionist lists')
a('        if (!rules::weaponAllowedForClass(5, "dagger")) ++bad;')
a('        if (!rules::weaponAllowedForClass(5, "dart")) ++bad;')
a('        if (!rules::weaponAllowedForClass(5, "quarterstaff"))')
a('            ++bad;')
a('        if (rules::weaponAllowedForClass(5, "club")) ++bad;')
a('        if (rules::weaponAllowedForClass(5, "long sword")) ++bad;')
a('        if (!rules::weaponAllowedForClass(6, "dagger")) ++bad;')
a('        if (rules::weaponAllowedForClass(6, "battle axe")) ++bad;')
a('        // the thief list and the sword footnote')
a('        if (!rules::weaponAllowedForClass(7, "club")) ++bad;')
a('        if (!rules::weaponAllowedForClass(7, "dagger")) ++bad;')
a('        if (!rules::weaponAllowedForClass(7, "dart")) ++bad;')
a('        if (!rules::weaponAllowedForClass(7, "sling stone")) ++bad;')
a('        if (!rules::weaponAllowedForClass(7, "short sword")) ++bad;')
a('        if (!rules::weaponAllowedForClass(7, "broad sword")) ++bad;')
a('        if (!rules::weaponAllowedForClass(7, "long sword")) ++bad;')
a('        if (rules::weaponAllowedForClass(7, "bastard sword"))')
a('            ++bad;')
a('        if (rules::weaponAllowedForClass(7, "two-handed sword"))')
a('            ++bad;')
a('        if (rules::weaponAllowedForClass(7, "spear")) ++bad;')
a('        // the crossbow is the monk print alone')
a('        if (rules::weaponAllowedForClass(7, "crossbow")) ++bad;')
a('        if (rules::weaponAllowedForClass(5, "crossbow")) ++bad;')
a('        if (rules::weaponAllowedForClass(0, "crossbow")) ++bad;')
a('        // the any-weapon rows take everything asked')
a('        if (!rules::weaponAllowedForClass(2, "two-handed sword"))')
a('            ++bad;')
a('        if (!rules::weaponAllowedForClass(3, "bastard sword"))')
a('            ++bad;')
a('        if (!rules::weaponAllowedForClass(4, "halberd")) ++bad;')
a('        if (!rules::weaponAllowedForClass(8, "morning star")) ++bad;')
a('        // the list walk agrees with the membership test')
a('        for (int c = 0; c < 10; ++c) {')
a('            int n = rules::classAllowedWeaponCount(c);')
a('            if (n <= 0) continue;')
a('            for (int i = 0; i < n; ++i) {')
a('                if (!rules::weaponAllowedForClass(')
a('                        c, rules::classAllowedWeaponName(c, i)))')
a('                    ++bad;')
a('            }')
a('        }')
a('        printf("R198 class weapon allowlists audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R197 mental-form flag audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R198 class weapon allowlists audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 2, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R198 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R198 note: 2 patches; the class weapon allowlists land - the')
print('CHARACTER CLASSES TABLE II weapons column, the monk list home;')
print('census 115.')
print('commit: R198: the class weapon allowlists - the TABLE II weapons')
print('column pinned, the monk list its home (census 115)')

