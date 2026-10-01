#!/usr/bin/env python3
"""logistics_splice_r79.py -- the R79 "logistics tranche", one shot:
 (1) game/party.h: CARRIED_CAP/QUIVER_CAP constants + addCapped() +
     claimAmmoBundle() helpers (appended at EOF, after Character/Party);
 (2) game/appstate.h: declare void dumpEquipment();
 (3) game/state_core.cpp: implement dumpEquipment() (per-member kit
     lines + carried totals) after restockAmmo();
 (4) game/state_dungeon.cpp: MIK_AMMO claim case in the R77 claim
     block + capped potions/scrolls increments;
 (5) game/state_town.cpp: capped potion purchases (4 sites);
 (6) regtest.cpp: include game/party.h + deterministic R79 audit
     (ammo claim routing, specials excluded, cap math).
Content-anchored on exact bytes; idempotent (marker: CARRIED_CAP in
party.h). Run from repo root."""
import sys

def rw(path):
    return open(path, encoding='utf-8').read()

def wr(path, s):
    open(path, 'w', encoding='utf-8').write(s)

report = []

# ---------- (1) party.h helpers ----------
p = 'game/party.h'
src = rw(p)
if 'CARRIED_CAP' not in src:
    APPEND = '''
// ----------------------------------------------------------------------------
// R79: the logistics helpers — ammo bundle claims and carried caps.
// ----------------------------------------------------------------------------
// R79: carried-stack ceilings. Potions/scrolls pool per party; the
// quiver is per member. Caps keep decades of delve counters inside
// sane ranges (nothing can run away toward int overflow).
static const int CARRIED_CAP = 9999;   // party potions/scrolls
static const int QUIVER_CAP  = 999;    // per-member missileAmmo

// add to a capped counter; the counter never exceeds cap and can
// still decrease (spending is uncapped)
inline int addCapped(int& cur, int add, int cap) {
    cur += add;
    if (cur > cap) cur = cap;
    return cur;
}

// R79: claim an arrow/bolt bundle into a member's quiver — true when
// the bundle matched the member's RANGED weapon and was pocketed.
// Only enchanted bundles claim ("Arrow +2", "Bolt +1"): the singular
// specials (Arrow of Slaying, Arrow of Direction) stay appraised —
// they are single shots, not quiver fodder. The quiver counts SHOTS;
// per-arrow enchant tracking awaits the real-inventory tranche.
inline bool claimAmmoBundle(Character& c, const std::string& name,
                            int qty) {
    if (qty <= 0 || c.hp <= 0) return false;
    bool arrow = name.find("Arrow") != std::string::npos;
    bool bolt  = name.find("Bolt")  != std::string::npos;
    if (!arrow && !bolt) return false;
    bool enchanted =
        name.find("Arrow +") != std::string::npos ||
        name.find("Bolt +")  != std::string::npos;
    if (!enchanted) return false;
    items::WeaponId id = c.rangedWeapon.id;
    bool fits = (arrow && (id == items::WPN_SHORT_BOW ||
                           id == items::WPN_LONG_BOW)) ||
                (bolt  && id == items::WPN_CROSSBOW_LIGHT);
    if (!fits) return false;
    addCapped(c.missileAmmo, qty, QUIVER_CAP);
    return true;
}
'''
    src = src.rstrip('\n') + '\n' + APPEND
    wr(p, src)
    report.append('party.h: helpers appended')
else:
    report.append('party.h: already patched')

# ---------- (2) appstate.h declaration ----------
p = 'game/appstate.h'
src = rw(p)
if 'dumpEquipment' not in src:
    OLD = '''    void restockAmmo();
'''
    NEW = '''    void restockAmmo();

    // R79: dump the company's kit to the log — per member weapon/
    // ranged/armor/shield (with enchant plus), then the carried
    // totals (potions, scrolls, gold). Engine-side; the Win32 key
    // binding is a later shell diff.
    void dumpEquipment();
'''
    assert src.count(OLD) == 1, 'restockAmmo decl anchor not unique'
    src = src.replace(OLD, NEW, 1)
    wr(p, src)
    report.append('appstate.h: dumpEquipment declared')
else:
    report.append('appstate.h: already patched')

# ---------- (3) state_core.cpp implementation ----------
p = 'game/state_core.cpp'
src = rw(p)
if 'AppState::dumpEquipment' not in src:
    OLD = '''// ---- restockAmmo ----
void AppState::restockAmmo(){
        for (auto& c : party.members) {
            if (!items::weapon(c.rangedWeapon.id).missile) continue;
            c.missileAmmo = 20;
        }
    }
'''
    NEW = OLD + '''
// ---- R79: dumpEquipment ----
void AppState::dumpEquipment(){
        log.add("--- The company's kit ---");
        char buf[192];
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            char melee[48], ranged[56], arm[48], sh[32];
            if (c.weapon.plus > 0)
                snprintf(melee, sizeof melee, "%s +%d",
                         items::weapon(c.weapon.id).name,
                         c.weapon.plus);
            else
                snprintf(melee, sizeof melee, "%s",
                         items::weapon(c.weapon.id).name);
            if (items::weapon(c.rangedWeapon.id).missile) {
                if (c.rangedWeapon.plus > 0)
                    snprintf(ranged, sizeof ranged, ", %s +%d "
                             "(%d missiles)",
                             items::weapon(c.rangedWeapon.id).name,
                             c.rangedWeapon.plus, c.missileAmmo);
                else
                    snprintf(ranged, sizeof ranged, ", %s "
                             "(%d missiles)",
                             items::weapon(c.rangedWeapon.id).name,
                             c.missileAmmo);
            } else {
                ranged[0] = 0;
            }
            if (c.armor.id != items::ARMOR_NONE_EQUIPPED) {
                if (c.armor.plus > 0)
                    snprintf(arm, sizeof arm, ", %s +%d",
                             items::armor(c.armor.id).name,
                             c.armor.plus);
                else
                    snprintf(arm, sizeof arm, ", %s",
                             items::armor(c.armor.id).name);
            } else {
                arm[0] = 0;
            }
            if (c.shield) {
                if (c.shieldPlus > 0)
                    snprintf(sh, sizeof sh, ", shield +%d",
                             c.shieldPlus);
                else
                    snprintf(sh, sizeof sh, ", shield");
            } else {
                sh[0] = 0;
            }
            snprintf(buf, sizeof buf, "%s: %s%s%s%s",
                     c.name.c_str(), melee, ranged, arm, sh);
            log.add(buf);
        }
        snprintf(buf, sizeof buf,
                 "Carried: %d potions, %d scrolls, %d gp.",
                 party.potions, party.scrolls, party.gold);
        log.add(buf);
    }
'''
    assert src.count(OLD) == 1, 'restockAmmo impl anchor not unique'
    src = src.replace(OLD, NEW, 1)
    wr(p, src)
    report.append('state_core.cpp: dumpEquipment implemented')
else:
    report.append('state_core.cpp: already patched')

# ---------- (4) state_dungeon.cpp: ammo case + caps ----------
p = 'game/state_dungeon.cpp'
src = rw(p)
changed = False
if 'case dm::treasure::MIK_AMMO:' not in src:
    OLD = '''                    default:
                        // MIK_AMMO (real inventory pending) and
                        // MIK_OTHER stay appraised to gold
                        break;
'''
    NEW = '''                    case dm::treasure::MIK_AMMO:
                        // R79: arrow/bolt bundles -> the quiver of
                        // the first living member whose ranged weapon
                        // fires them (count-only; per-arrow enchant
                        // awaits real inventory). Singular specials
                        // (Slaying, Direction) stay appraised — the
                        // helper declines unenchanted names.
                        for (auto& c : party.members) {
                            if (c.hp <= 0) continue;
                            if (claimAmmoBundle(c, mi.name, mi.qty)) {
                                snprintf(buf, sizeof buf,
                                         "%s pockets the %s x%d "
                                         "(%d missiles).",
                                         c.name.c_str(),
                                         mi.name.c_str(), mi.qty,
                                         c.missileAmmo);
                                log.add(buf);
                                take = true;
                                break;
                            }
                        }
                        break;
                    default:
                        // MIK_OTHER (rings/rods/misc) and declined
                        // ammo stay appraised to gold
                        break;
'''
    assert src.count(OLD) == 1, 'default case anchor not unique'
    src = src.replace(OLD, NEW, 1)
    changed = True
    report.append('state_dungeon.cpp: MIK_AMMO case added')
else:
    report.append('state_dungeon.cpp: ammo case already present')
if 'addCapped(party.potions' not in src:
    OLD = 'party.potions += mi.qty;'
    assert src.count(OLD) == 1, 'potions increment anchor not unique'
    src = src.replace(OLD,
        'addCapped(party.potions, mi.qty, CARRIED_CAP);', 1)
    OLD = 'party.scrolls += mi.qty;'
    assert src.count(OLD) == 1, 'scrolls increment anchor not unique'
    src = src.replace(OLD,
        'addCapped(party.scrolls, mi.qty, CARRIED_CAP);', 1)
    changed = True
    report.append('state_dungeon.cpp: potions/scrolls capped')
else:
    report.append('state_dungeon.cpp: caps already present')
if changed:
    wr(p, src)

# ---------- (5) state_town.cpp: capped purchases ----------
p = 'game/state_town.cpp'
src = rw(p)
OLD = 'party.potions += 3;'
if src.count(OLD) > 0 and 'addCapped' not in src:
    src = src.replace(OLD,
        'addCapped(party.potions, 3, CARRIED_CAP);')
    wr(p, src)
    report.append('state_town.cpp: %d potion purchases capped'
                  % src.count('addCapped(party.potions, 3'))
else:
    report.append('state_town.cpp: nothing to do')

# ---------- (6) regtest.cpp: include + R79 audit ----------
p = 'regtest.cpp'
src = rw(p)
if 'game/party.h' not in src:
    OLD = '#include "dm/encounters.h"'
    assert src.count(OLD) == 1, 'include anchor not unique'
    src = src.replace(OLD, OLD + '\n#include "game/party.h"', 1)
if 'R79 claim/caps audit' not in src:
    OLD = '''    return 0;
            }
'''
    assert src.count(OLD) == 1, 'regtest tail anchor not unique'
    NEW = '''
    // ---- R79: ammo bundle claims + carried caps -----------------------
    {
        int bad = 0;
        Character c;
        c.name = "Rolf";
        c.hp = 10;
        c.rangedWeapon.id = items::WPN_SHORT_BOW;
        c.missileAmmo = 4;
        // enchanted arrows fit the bow
        if (!claimAmmoBundle(c, "Arrow +2", 12)) ++bad;
        if (c.missileAmmo != 16) ++bad;
        // bolts do not fit a bow
        if (claimAmmoBundle(c, "Bolt +2", 10)) ++bad;
        // a crossbow takes bolts
        c.rangedWeapon.id = items::WPN_CROSSBOW_LIGHT;
        if (!claimAmmoBundle(c, "Bolt +2", 10)) ++bad;
        // the singular specials never claim
        if (claimAmmoBundle(c, "Arrow of Slaying", 1)) ++bad;
        if (claimAmmoBundle(c, "Arrow of Direction", 1)) ++bad;
        // a long bow takes arrows too
        c.rangedWeapon.id = items::WPN_LONG_BOW;
        if (!claimAmmoBundle(c, "Arrow +1", 20)) ++bad;
        // the dead claim nothing
        c.hp = 0;
        if (claimAmmoBundle(c, "Arrow +1", 20)) ++bad;
        c.hp = 10;
        // quiver cap
        c.missileAmmo = QUIVER_CAP;
        if (claimAmmoBundle(c, "Arrow +1", 20)) ++bad;
        if (c.missileAmmo != QUIVER_CAP) ++bad;
        // carried-stack cap: clamps up, never down
        int stack = CARRIED_CAP - 4;
        addCapped(stack, 100, CARRIED_CAP);
        if (stack != CARRIED_CAP) ++bad;
        addCapped(stack, -50, CARRIED_CAP);
        if (stack != CARRIED_CAP - 50) ++bad;
        printf("R79 claim/caps audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }
'''
    src = src.replace(OLD, NEW, 1)
    wr(p, src)
    report.append('regtest.cpp: include + R79 audit added')
else:
    report.append('regtest.cpp: already patched')

print('; '.join(report))
