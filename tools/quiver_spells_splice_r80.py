#!/usr/bin/env python3
"""quiver_spells_splice_r80.py -- the R80 tranche, one shot:
 A. real ammo inventory: AmmoBundle bands on Character, per-shot
    enchant queue on Actor, FIFO consumption, bundle-aware claim/
    restock/sync/dump;
 B. spell levels 4-6: 15 rows (9 MU, 6 CL), 8 wired into the effect
    dispatch, ids APPENDED (saved knownSpells indices stay valid);
 C. henchman kit claims (sword/shield plus) + optional save fields;
 D. regtest: R79 audit updated to bundle semantics + R80 quiver
    audit + spell-table audit.
Content-anchored on exact bytes; idempotent (marker: AmmoBundle in
party.h). Run from repo root."""
import sys

def rw(p): return open(p, encoding='utf-8').read()
def wr(p, s): open(p, 'w', encoding='utf-8').write(s)
report = []
def patch(path, pairs, marker_key=None, marker=None):
    """pairs: list of (old, new). Skips file if marker present."""
    if marker is not None and marker in rw(path):
        report.append(path + ': already patched')
        return
    src = rw(path)
    for old, new in pairs:
        n = src.count(old)
        assert n == 1, ('anchor not unique (%d) in ' % n) + path \
            + ' :: ' + old[:60]
        src = src.replace(old, new, 1)
    wr(path, src)
    report.append(path + ': patched (%d edits)' % len(pairs))

# ============ A. party.h: bundle struct + helpers + claim rewrite =====
P = 'game/party.h'
src = rw(P)
if 'struct AmmoBundle' in src:
    report.append(P + ': already patched')
else:
    # A1: Character gains the quiver
    OLD = '    int missileAmmo = 0;   // R35: arrows/bolts/stones on hand\n'
    NEW = '''    int missileAmmo = 0;   // R35: arrows/bolts/stones on hand
    // R80: the quiver's enchant composition — bands of {plus, count},
    // front band fires first (mundane before magic)
    std::vector<AmmoBundle> quiver;
'''
    assert src.count(OLD) == 1
    src = src.replace(OLD, NEW, 1)
    # A2: R80 helpers BEFORE the R79 block (claimAmmoBundle uses them)
    OLD = '''// ----------------------------------------------------------------------------
// R79: the logistics helpers — ammo bundle claims and carried caps.
// ----------------------------------------------------------------------------'''
    NEW = '''// ----------------------------------------------------------------------------
// R80: quiver bundles — per-shot enchant tracking. Bands of {plus,
// count}; the front band fires first (mundane before magic, so
// enchanted shots are spent last), same-plus claims merge, and the
// total stays under QUIVER_CAP.
// ----------------------------------------------------------------------------
struct AmmoBundle {
    int plus  = 0;    // enchant (+1..+3 in III.H bundles)
    int count = 0;    // arrows/bolts in the band
};

inline int quiverTotal(const std::vector<AmmoBundle>& q) {
    int n = 0;
    for (const auto& b : q) n += b.count;
    return n;
}

// the plus of the next shot to fire (front band; 0 = mundane)
inline int quiverNextPlus(const std::vector<AmmoBundle>& q) {
    for (const auto& b : q)
        if (b.count > 0) return b.plus;
    return 0;
}

// add a band (same-plus merge); over-cap trims the TAIL bands first
inline void quiverAdd(std::vector<AmmoBundle>& q, int plus,
                      int count, int cap = QUIVER_CAP) {
    if (count <= 0) return;
    for (auto& b : q)
        if (b.plus == plus) { b.count += count; count = 0; break; }
    if (count > 0) {
        AmmoBundle nb;
        nb.plus = plus;
        nb.count = count;
        q.push_back(nb);
    }
    int over = quiverTotal(q) - cap;
    while (over > 0 && !q.empty()) {
        AmmoBundle& tail = q.back();
        int take = tail.count < over ? tail.count : over;
        tail.count -= take;
        over -= take;
        if (tail.count <= 0) q.pop_back();
    }
}

// consume n shots front-first
inline void quiverConsumeShots(std::vector<AmmoBundle>& q, int n) {
    if (n <= 0) return;
    while (n > 0 && !q.empty()) {
        AmmoBundle& front = q.front();
        int take = front.count < n ? front.count : n;
        front.count -= take;
        n -= take;
        if (front.count <= 0) q.erase(q.begin());
    }
}

// refill the mundane band to n (rest convention: 20 shots)
inline void quiverRestock(std::vector<AmmoBundle>& q, int n) {
    for (auto& b : q)
        if (b.plus == 0) { b.count = n; return; }
    quiverAdd(q, 0, n);
}

// ----------------------------------------------------------------------------
// R79: the logistics helpers — ammo bundle claims and carried caps.
// ----------------------------------------------------------------------------'''
    assert src.count(OLD) == 1
    src = src.replace(OLD, NEW, 1)
    # A3: claimAmmoBundle -> bundle-aware
    OLD = '''    if (!fits) return false;
    addCapped(c.missileAmmo, qty, QUIVER_CAP);
    return true;
}'''
    NEW = '''    if (!fits) return false;
    // R80: bundle-aware — a legacy flat count becomes the mundane
    // band, the enchanted band joins behind it (merged by plus),
    // and the derived total keeps the R79 cap
    if (c.quiver.empty() && c.missileAmmo > 0) {
        AmmoBundle b;
        b.count = c.missileAmmo;
        c.quiver.push_back(b);
    }
    int plus = 0;
    size_t p = name.find('+');
    while (p != std::string::npos) {
        if (p + 1 < name.size() && name[p + 1] >= '0' &&
            name[p + 1] <= '9') {
            plus = name[p + 1] - '0';   // bundles print +1..+3
            break;
        }
        p = name.find('+', p + 1);
    }
    quiverAdd(c.quiver, plus, qty);
    c.missileAmmo = quiverTotal(c.quiver);
    return true;
}'''
    assert src.count(OLD) == 1
    src = src.replace(OLD, NEW, 1)
    # A4: toActor seeds the per-shot queue
    OLD = '''        a.missileAmmo = missileAmmo;     // R35: live quiver count
'''
    NEW = '''        a.missileAmmo = missileAmmo;     // R35: live quiver count
        // R80: per-shot enchant queue — front band first
        a.ammoQueueLen = 0;
        a.ammoQueuePos = 0;
        for (const auto& b : quiver)
            for (int i = 0; i < b.count && a.ammoQueueLen < 64; ++i)
                a.ammoQueue[a.ammoQueueLen++] = b.plus;
'''
    assert src.count(OLD) == 1
    src = src.replace(OLD, NEW, 1)
    wr(P, src)
    report.append(P + ': patched (4 edits)')

# ============ C. party.h: henchman kit fields + actor =================
src = rw(P)
if 'henchmanWeaponPlus' in src:
    report.append(P + ': henchman already patched')
else:
    OLD = '    bool henchmanPlate = false;   // R46: plate kit upgrade\n'
    NEW = '''    bool henchmanPlate = false;   // R46: plate kit upgrade
    // R80: the hire's magic kit — a won sword's enchant and a won
    // magic shield's plus (armor stays the R46 plate ladder)
    int  henchmanWeaponPlus = 0;
    int  henchmanShieldPlus = 0;
'''
    assert src.count(OLD) == 1
    src = src.replace(OLD, NEW, 1)
    OLD = '        a.weapon.id = items::WPN_LONG_SWORD;\n'
    NEW = '''        a.weapon.id = items::WPN_LONG_SWORD;
        a.weapon.plus = henchmanWeaponPlus;   // R80
'''
    assert src.count(OLD) == 1
    src = src.replace(OLD, NEW, 1)
    OLD = '        a.shield = true;\n'
    assert src.count(OLD) == 1
    src = src.replace(OLD,
        '        a.shield = true;\n'
        '        a.shieldPlus = henchmanShieldPlus;   // R80\n', 1)
    wr(P, src)
    report.append(P + ': henchman patched (3 edits)')

# ============ A5. ai/actor.h: per-shot queue fields ====================
patch('ai/actor.h', [(
'''    int missileAmmo = 0;
''',
'''    int missileAmmo = 0;
    // R80: per-shot ammunition enchant — filled from the Character's
    // quiver bands at combat start (front band first); each shot
    // pops one entry. 0 = mundane. Monsters never use it.
    int ammoPlus = 0;
    int ammoQueue[64];
    int ammoQueueLen = 0;
    int ammoQueuePos = 0;
    int takeAmmoPlus() {
        if (ammoQueuePos < ammoQueueLen)
            return ammoQueue[ammoQueuePos++];
        return 0;
    }
''')], marker='takeAmmoPlus')

# ============ A6. ai/actor.cpp: resolveMissile pops + applies ==========
patch('ai/actor.cpp', [
(
'''        attacker.throwing = false;
        attacker.weaponThrown = true;   // spent for the encounter
''',
'''        attacker.throwing = false;
        attacker.weaponThrown = true;   // spent for the encounter
        attacker.ammoPlus = 0;   // R80: hurled weapons carry no arrow enchant
'''),
(
'''        // R35: spend the missile whether it hits or misses
        --attacker.missileAmmo;
''',
'''        // R35: spend the missile whether it hits or misses
        --attacker.missileAmmo;
        // R80: the fired shot's enchant (front band first)
        attacker.ammoPlus = attacker.takeAmmoPlus();
'''),
(
'    int wpnPlus = attacker.isCharacter ? fired.plus : 99;',
'    // R80: the arrow\'s enchant counts toward +N-to-hit gating\n'
'    int wpnPlus = attacker.isCharacter ? fired.plus + '
'attacker.ammoPlus : 99;'),
(
'''        adj += rules::dexReactionAdj(attacker.dex);
''',
'''        adj += rules::dexReactionAdj(attacker.dex);
        adj += attacker.ammoPlus;   // R80: the arrow's enchant
'''),
(
'''        dmg += fired.plus;
''',
'''        dmg += fired.plus;
        dmg += attacker.ammoPlus;   // R80: arrow plus
'''),
], marker='takeAmmoPlus();')

# ============ A7. state_combat.cpp: endCombat sync =====================
patch('game/state_combat.cpp', [(
'''                    // R35: spent ammo persists (quiver count)
                    c.missileAmmo = a.missileAmmo;
''',
'''                    // R35: spent ammo persists; R80: the bundle
                    // composition is consumed front-first to match
                    // the shots the actor fired this fight
                    quiverConsumeShots(
                        c.quiver, c.missileAmmo - a.missileAmmo);
                    c.missileAmmo = a.missileAmmo;
''')], marker='quiverConsumeShots(\n                        c.quiver')

# ============ A8. state_core.cpp: restock + dump bands + save/load =====
patch('game/state_core.cpp', [
(
'''            if (!items::weapon(c.rangedWeapon.id).missile) continue;
            c.missileAmmo = 20;
''',
'''            if (!items::weapon(c.rangedWeapon.id).missile) continue;
            quiverRestock(c.quiver, 20);   // R80: bundle-aware
            c.missileAmmo = quiverTotal(c.quiver);
'''),
(
'''            snprintf(buf, sizeof buf, "%s: %s%s%s%s",
                     c.name.c_str(), melee, ranged, arm, sh);
            log.add(buf);
''',
'''            snprintf(buf, sizeof buf, "%s: %s%s%s%s",
                     c.name.c_str(), melee, ranged, arm, sh);
            log.add(buf);
            // R80: quiver composition when enchanted bands are held
            bool magicBands = false;
            for (const auto& b : c.quiver)
                if (b.plus > 0) magicBands = true;
            if (magicBands) {
                std::string bands;
                for (const auto& b : c.quiver) {
                    if (b.count <= 0) continue;
                    char bb[32];
                    if (b.plus > 0) snprintf(bb, sizeof bb,
                                             " +%d x%d",
                                             b.plus, b.count);
                    else snprintf(bb, sizeof bb,
                                  " %d mundane", b.count);
                    bands += bb;
                }
                snprintf(buf, sizeof buf, "  %s's quiver:%s",
                         c.name.c_str(), bands.c_str());
                log.add(buf);
            }
'''),
(
'''            fprintf(f, "henchman %d %d %d %d %d %d %d %s\\n",
                    party.henchmanHp, party.henchmanMaxHp,
                    party.henchmanLevel, party.henchmanLoyalty,
                    party.henchmanXp, party.henchmanPurse,
                    party.delveGold,
                    party.henchmanName.c_str());''',
'''            fprintf(f, "henchman %d %d %d %d %d %d %d %d %d %s\\n",
                    party.henchmanHp, party.henchmanMaxHp,
                    party.henchmanLevel, party.henchmanLoyalty,
                    party.henchmanXp, party.henchmanPurse,
                    party.delveGold,
                    party.henchmanWeaponPlus,
                    party.henchmanShieldPlus,
                    party.henchmanName.c_str());'''),
(
'''                    int hxp = 0, hpu = 0, dgv = 0;
                    int got = fscanf(f, "%d %d %d",
                                     &hxp, &hpu, &dgv);
                    if (got >= 1) p.henchmanXp = hxp;
                    if (got >= 2) p.henchmanPurse = hpu;
                    if (got >= 3) p.delveGold = dgv;''',
'''                    int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0;
                    int got = fscanf(f, "%d %d %d %d %d",
                                     &hxp, &hpu, &dgv, &wpl, &spl);
                    if (got >= 1) p.henchmanXp = hxp;
                    if (got >= 2) p.henchmanPurse = hpu;
                    if (got >= 3) p.delveGold = dgv;
                    // R80: the hire's magic kit (optional trailing)
                    if (got >= 4) p.henchmanWeaponPlus = wpl;
                    if (got >= 5) p.henchmanShieldPlus = spl;'''),
], marker='quiverRestock(c.quiver, 20)')

# ============ C2. state_dungeon.cpp: the hire's claim ===================
patch('game/state_dungeon.cpp', [(
'''                }
                if (take) {
                    carriedOff.push_back(mi);''',
'''                }
                // R80: the hire's claim — when no member took the
                // item, the henchman upgrades his kit (sword plus,
                // shield plus; the plate ladder is unchanged, and
                // only III.G swords arm him — his kit is fixed)
                if (!take && !mi.cursed() &&
                    party.henchmanPresent && party.henchmanHp > 0 &&
                    mi.qty == 1) {
                    if (mi.kind() == dm::treasure::MIK_SWORD &&
                        party.henchmanWeaponPlus < mi.weaponPlus()) {
                        party.henchmanWeaponPlus = mi.weaponPlus();
                        snprintf(buf, sizeof buf,
                                 "%s takes the %s!",
                                 party.henchmanName.c_str(),
                                 mi.name.c_str());
                        log.add(buf);
                        take = true;
                    } else if (mi.kind() == dm::treasure::MIK_SHIELD &&
                               party.henchmanShieldPlus <
                                   mi.weaponPlus()) {
                        party.henchmanShieldPlus = mi.weaponPlus();
                        snprintf(buf, sizeof buf,
                                 "%s takes the %s.",
                                 party.henchmanName.c_str(),
                                 mi.name.c_str());
                        log.add(buf);
                        take = true;
                    }
                }
                if (take) {
                    carriedOff.push_back(mi);''')],
    marker="the hire's claim")

# ============ B. spells.h enum + spells.cpp rows ========================
patch('spells/spells.h', [(
'''    CL_PRAYER,
    SPELL_COUNT
};''',
'''    CL_PRAYER,
    // --- R80: levels 4-6 (appended AFTER the legacy ids so saved
    //     knownSpells indices stay valid) ---
    MU_POLYMORPH_OTHER,
    MU_ICE_STORM,
    MU_FIRE_SHIELD,
    MU_CHARM_MONSTER,
    MU_CONE_OF_COLD,
    MU_TELEPORT,
    MU_HOLD_MONSTER,
    MU_DEATH_SPELL,
    MU_DISINTEGRATE,
    CL_CURE_CRITICAL_WOUNDS,
    CL_CAUSE_CRITICAL_WOUNDS,
    CL_NEUTRALIZE_POISON,
    CL_RAISE_DEAD,
    CL_INSECT_PLAGUE,
    CL_HEAL,
    SPELL_COUNT
};''')], marker='MU_ICE_STORM')

patch('spells/spells.cpp', [(
'''    { "Prayer",            SPELL_CLERIC,  3,  4,  0, 60,  -1, TARGET_AREA,       3, 0, 0, false },
};''',
'''    { "Prayer",            SPELL_CLERIC,  3,  4,  0, 60,  -1, TARGET_AREA,       3, 0, 0, false },
    // ---- R80: levels 4-6 (PHB premium reprint; values carry the
    // file's standing verification debt — printed tables win).
    // Utility rows land "known, cast pending" (resolveSpell
    // default); combat rows are wired in spelleffects.cpp.
    { "Polymorph Other",     SPELL_MU,     4,  4,  6,  0,   2, TARGET_CREATURE,   0, 0, 0, false },
    { "Ice Storm",           SPELL_MU,     4,  4, 10,  4,  -1, TARGET_AREA,       3, 2, 8, false },
    { "Fire Shield",         SPELL_MU,     4,  4,  0, 60,  -1, TARGET_SELF,       0, 0, 0, false },
    { "Charm Monster",       SPELL_MU,     4,  4, 12,  0,   4, TARGET_CREATURES,  0, 0, 0, false },
    { "Cone of Cold",        SPELL_MU,     5,  5,  0,  0,   3, TARGET_AREA,       2, 1, 6, false },
    { "Teleport",            SPELL_MU,     5,  2,  0,  0,  -1, TARGET_SPECIAL,    0, 0, 0, false },
    { "Hold Monster",        SPELL_MU,     5,  5, 12,  6,   4, TARGET_CREATURES,  0, 0, 0, false },
    { "Death Spell",         SPELL_MU,     6,  6,  6,  0,  -1, TARGET_AREA,       4, 0, 0, false },
    { "Disintegrate",        SPELL_MU,     6,  6,  6,  0,   4, TARGET_CREATURE,   0, 0, 0, false },
    { "Cure Critical Wounds",SPELL_CLERIC, 4,  4,  0,  0,  -1, TARGET_CREATURE,   0, 3, 8, true  },
    { "Cause Critical Wounds",SPELL_CLERIC, 4,  4,  0,  0,  -1, TARGET_CREATURE,   0, 3, 8, true  },
    { "Neutralize Poison",   SPELL_CLERIC, 4,  4,  0,  0,  -1, TARGET_CREATURE,   0, 0, 0, true  },
    { "Raise Dead",          SPELL_CLERIC, 5,  5,  0,  0,  -1, TARGET_CREATURE,   0, 0, 0, true  },
    { "Insect Plague",       SPELL_CLERIC, 5,  5,  3, 12,  -1, TARGET_AREA,       3, 2, 8, true  },
    { "Heal",                SPELL_CLERIC, 6,  6,  0,  0,  -1, TARGET_CREATURE,   0, 8, 8, true  },
};''')], marker='R80: levels 4-6')

# ============ B2. spelleffects.cpp: wire the combat rows ================
patch('spelleffects/spelleffects.cpp', [
(
'''            case spells::MU_FIREBALL:
            case spells::MU_LIGHTNING_BOLT:
''',
'''            case spells::MU_FIREBALL:
            case spells::MU_LIGHTNING_BOLT:
            case spells::MU_ICE_STORM:      // R80
            case spells::MU_CONE_OF_COLD:   // R80
'''),
(
'''            case spells::CL_CURE_LIGHT_WOUNDS:
            case spells::CL_CURE_SERIOUS_WOUNDS:
''',
'''            case spells::CL_CURE_LIGHT_WOUNDS:
            case spells::CL_CURE_SERIOUS_WOUNDS:
            case spells::CL_CURE_CRITICAL_WOUNDS:   // R80
            case spells::CL_HEAL:                   // R80
'''),
(
'''            case spells::CL_CAUSE_LIGHT_WOUNDS:
            case spells::CL_CAUSE_SERIOUS_WOUNDS:
''',
'''            case spells::CL_CAUSE_LIGHT_WOUNDS:
            case spells::CL_CAUSE_SERIOUS_WOUNDS:
            case spells::CL_CAUSE_CRITICAL_WOUNDS:  // R80
'''),
(
'''            case spells::MU_CHARM_PERSON:
''',
'''            case spells::MU_CHARM_PERSON:
            case spells::MU_CHARM_MONSTER:   // R80
'''),
(
'''            case spells::CL_HOLD_PERSON:
''',
'''            case spells::MU_HOLD_MONSTER:   // R80
            case spells::CL_HOLD_PERSON:
'''),
], marker='MU_HOLD_MONSTER')

# ============ D. regtest.cpp: audits ====================================
patch('regtest.cpp', [
(
'''        // quiver cap: the bundle still pockets (true), the count
        // just stops at the cap
        c.missileAmmo = QUIVER_CAP;''',
'''        // quiver cap: the bundle still pockets (true), the count
        // just stops at the cap
        c.quiver.clear();   // R80: bundle semantics
        c.missileAmmo = QUIVER_CAP;'''),
(
'''        printf("R79 claim/caps audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }''',
'''        printf("R79 claim/caps audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R80: quiver bundle math --------------------------------------
    {
        int bad = 0;
        Character c;
        c.hp = 10;
        // same-plus merge + tail-trim cap
        quiverAdd(c.quiver, 0, 4);
        quiverAdd(c.quiver, 2, 3);
        quiverAdd(c.quiver, 0, 2);      // merges into the 0-band
        if (quiverTotal(c.quiver) != 9) ++bad;
        if (quiverNextPlus(c.quiver) != 0) ++bad;
        quiverAdd(c.quiver, 5, 1000);   // over the cap: tail trims
        if (quiverTotal(c.quiver) != QUIVER_CAP) ++bad;
        // front-first consumption: mundane before magic
        c.quiver.clear();
        quiverAdd(c.quiver, 0, 4);
        quiverAdd(c.quiver, 2, 3);
        quiverConsumeShots(c.quiver, 5);
        if (quiverTotal(c.quiver) != 2) ++bad;
        if (quiverNextPlus(c.quiver) != 2) ++bad;
        quiverConsumeShots(c.quiver, 99);   // drains
        if (quiverTotal(c.quiver) != 0) ++bad;
        // restock refills the mundane band only
        quiverRestock(c.quiver, 20);
        if (quiverTotal(c.quiver) != 20) ++bad;
        quiverAdd(c.quiver, 2, 3);
        quiverRestock(c.quiver, 20);   // leaves the +2 band alone
        if (quiverTotal(c.quiver) != 23) ++bad;
        if (quiverNextPlus(c.quiver) != 0) ++bad;
        printf("R80 quiver audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R80: spell table L4-6 -----------------------------------------
    {
        int bad = 0, mu = 0, cl = 0, l46 = 0;
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)id);
            if (s.level < 1 || s.level > 6) ++bad;
            if (s.sclass != spells::SPELL_MU &&
                s.sclass != spells::SPELL_CLERIC) ++bad;
            if (s.sclass == spells::SPELL_MU) ++mu; else ++cl;
            if (s.level >= 4) {
                ++l46;
                // a slot row exists that can cast it
                if (spells::spellSlots(s.sclass, 12, s.level) < 1)
                    ++bad;
            }
        }
        if (l46 < 12) ++bad;   // the R80 roster landed
        printf("R80 spells audit: %d spells (MU %d, CL %d), "
               "L4-6 %d, bad %d\\n",
               spells::SPELL_COUNT, mu, cl, l46, bad);
        if (bad) return 1;
    }
    return 0;
            }'''),
(
'#include "game/party.h"',
'#include "game/party.h"\n#include "spells/spells.h"'),
], marker='R80 quiver audit')

print('; '.join(report))
