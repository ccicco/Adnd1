#!/usr/bin/env python3
# R85-CHUNK-1-START
# R85 "THE PACK" splice - the multi-slot carried inventory.
# Content-anchored, idempotent. Patch groups (9 files):
#   game/party.h        - PackItem + PACK_CAP + pack field +
#                         packAdd/packItemName/packImproves helpers
#   game/appstate.h     - townSwapGear/townSellPack decls
#   game/state_dungeon.cpp - gear claims fall through to the pack
#                         (unclaimed uncursed gear is carried)
#   game/state_town.cpp - townSwapGear ([E] equip best of pack) +
#                         townSellPack ([P] peddle the pack)
#   game/state_core.cpp - save/load pack lines (v1-compatible) +
#                         dumpEquipment pack print
#   adnd1.cpp           - town keys D/E/P + drawTown: pack line,
#                         quiver summary relocated to the right
#                         column (was colliding with the R83 lines)
#   regtest.cpp         - "R85 pack audit: bad 0"
#   tools/preflight.sh  - items/items.cpp joins the regtest build
# All anchors and inserted text are ASCII-only (protocol rule).

import sys, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REPORT = []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='utf-8') as f:
        f.write(s)

def patch(fname, old, new, tag, count=1):
    s = rd(fname)
    if new in s:
        REPORT.append("%s: already patched" % tag)
        return True
    n = s.count(old)
    if n != count:
        REPORT.append("%s: FAIL (anchor x%d, want %d)" % (tag, n, count))
        return False
    wr(fname, s.replace(old, new, count))
    REPORT.append("%s: patched" % tag)
    return True

OK = True

# ---------------------------------------------------------------------------
# 1) party.h - the pack model
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""struct Character {""",
"""// ----------------------------------------------------------------------------
// R85: the pack - each member's carried gear slots. Found magic
// gear that nobody equips on the spot is carried here (cap 6);
// the town [E] command equips the best of it, [P] peddles it.
// kind: 0 = weapon (id = items::WeaponId), 1 = armor
// (id = items::ArmorId), 2 = shield (id unused). gp is the sale
// value from the hoard's appraisal; swapped-out kit comes back
// into the pack as a gp 0 keepsake (kept, never sold).
// ----------------------------------------------------------------------------
struct PackItem {
    int kind = 0;
    int id   = 0;
    int plus = 0;
    int gp   = 0;
};

static const int PACK_CAP = 6;

struct Character {""",
'party.h PackItem')

OK &= patch('game/party.h',
"""    // R81: Ring of Protection AC bonus (0 = none worn)
    int ringPlus = 0;
""",
"""    // R81: Ring of Protection AC bonus (0 = none worn)
    int ringPlus = 0;

    // R85: the pack - carried gear awaiting equip or sale
    std::vector<PackItem> pack;
""",
'party.h pack field')
# R85-CHUNK-1-END
# R85-CHUNK-2-START

OK &= patch('game/party.h',
"""// ----------------------------------------------------------------------------
// R81: the ring + scroll-study helpers
// ----------------------------------------------------------------------------""",
"""// ----------------------------------------------------------------------------
// R85: the pack helpers
// ----------------------------------------------------------------------------
// carry an item; false when the pack is full (the caller appraises)
inline bool packAdd(Character& c, const PackItem& p) {
    if ((int)c.pack.size() >= PACK_CAP) return false;
    c.pack.push_back(p);
    return true;
}

// the item's display name, reconstructed from the item tables
// (the save stores only kind/id/plus/gp - names are never saved)
inline std::string packItemName(const PackItem& p) {
    char buf[48];
    if (p.kind == 2) {
        if (p.plus > 0) snprintf(buf, sizeof buf,
                                 "Shield +%d", p.plus);
        else snprintf(buf, sizeof buf, "Shield");
    } else if (p.kind == 1) {
        const char* n = items::armor(
            (items::ArmorId)p.id).name;
        if (p.plus > 0) snprintf(buf, sizeof buf,
                                 "%s +%d", n, p.plus);
        else snprintf(buf, sizeof buf, "%s", n);
    } else {
        const char* n = items::weapon(
            (items::WeaponId)p.id).name;
        if (p.plus > 0) snprintf(buf, sizeof buf,
                                 "%s +%d", n, p.plus);
        else snprintf(buf, sizeof buf, "%s", n);
    }
    return buf;
}

// would the pack item improve the member's kit? Weapons compare
// enchant plus in their own slot (missile weapons look at the
// RANGED slot), armor compares effective AC (plus, DEX and
// shield weighed), shields compare enchant. Strict improvement
// only - equals never swap (no loops).
inline bool packImproves(const Character& c, const PackItem& p) {
    if (c.hp <= 0) return false;
    if (p.kind == 2)
        return !c.shield || c.shieldPlus < p.plus;
    if (p.kind == 1) {
        if (p.id < 0 || p.id >= (int)items::ARMOR_COUNT)
            return false;
        items::ArmorInstance cand;
        cand.id = (items::ArmorId)p.id;
        cand.plus = p.plus;
        int oldAc = items::effectiveAc(
            c.armor, c.shield, c.shieldPlus, c.abilities.dex);
        int newAc = items::effectiveAc(
            cand, c.shield, c.shieldPlus, c.abilities.dex);
        return newAc < oldAc;   // lower = better
    }
    if (p.id < 0 || p.id >= (int)items::WPN_COUNT)
        return false;
    const items::WeaponDef& w =
        items::weapon((items::WeaponId)p.id);
    if (w.missile) return c.rangedWeapon.plus < p.plus;
    return c.weapon.plus < p.plus;
}

// ----------------------------------------------------------------------------
// R81: the ring + scroll-study helpers
// ----------------------------------------------------------------------------""",
'party.h pack helpers')

# ---------------------------------------------------------------------------
# 2) appstate.h - the two town commands
# ---------------------------------------------------------------------------
OK &= patch('game/appstate.h',
"""    // R82: a 7th+ level cleric raises one dead member (1000 gp
    // offering, survival vs CON per PHB, raised at 1 hp).
    // R83: bound to the [R] town key.
    void townRaiseDead();""",
"""    // R82: a 7th+ level cleric raises one dead member (1000 gp
    // offering, survival vs CON per PHB, raised at 1 hp).
    // R83: bound to the [R] town key.
    void townRaiseDead();

    // R85: the pack commands - [E] equips the best of every
    // member's pack (old kit returns to the pack as a keepsake),
    // [P] peddles the pack (sale-value items only; keepsakes
    // stay). [D] dumps the kit (the R79 engine method, now
    // key-bound - a standing backlog item).
    void townSwapGear();
    void townSellPack();""",
'appstate.h decls')
# R85-CHUNK-2-END
# R85-CHUNK-3-START

# ---------------------------------------------------------------------------
# 3) state_dungeon.cpp - claims fall through to the pack
# ---------------------------------------------------------------------------
OK &= patch('game/state_dungeon.cpp',
"""                const dm::treasure::MagicItem& mi = *it;
                bool take = false;""",
"""                const dm::treasure::MagicItem& mi = *it;
                bool take = false;
                // R85: the pack-carry candidate - the gear cases
                // set it when nobody equipped the item
                PackItem cand{};
                bool carryable = false;""",
'state_dungeon.cpp decls')

OK &= patch('game/state_dungeon.cpp',
"""                            }
                        }
                        break;
                    case dm::treasure::MIK_MELEE: {""",
"""                            }
                        }
                        if (!take) {   // R85: nobody wielded it
                            cand.kind = 0;
                            cand.id = (int)items::WPN_LONG_SWORD;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
                        }
                        break;
                    case dm::treasure::MIK_MELEE: {""",
'state_dungeon.cpp sword pack')

OK &= patch('game/state_dungeon.cpp',
"""                            }
                        break;
                    }
                    case dm::treasure::MIK_MISSILE: {""",
"""                            }
                        if (!take && id != items::WPN_COUNT) {
                            cand.kind = 0;
                            cand.id = (int)id;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
                        }
                        break;
                    }
                    case dm::treasure::MIK_MISSILE: {""",
'state_dungeon.cpp melee pack')

OK &= patch('game/state_dungeon.cpp',
"""                            }
                        break;
                    }
                    case dm::treasure::MIK_SHIELD:""",
"""                            }
                        if (!take && id != items::WPN_COUNT) {
                            cand.kind = 0;
                            cand.id = (int)id;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
                        }
                        break;
                    }
                    case dm::treasure::MIK_SHIELD:""",
'state_dungeon.cpp missile pack')

OK &= patch('game/state_dungeon.cpp',
"""                        }
                        break;
                    case dm::treasure::MIK_ARMOR: {""",
"""                        }
                        if (!take) {
                            cand.kind = 2;
                            cand.id = 0;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
                        }
                        break;
                    case dm::treasure::MIK_ARMOR: {""",
'state_dungeon.cpp shield pack')

OK &= patch('game/state_dungeon.cpp',
"""                            }
                        break;
                    }
                    case dm::treasure::MIK_SCROLL:""",
"""                            }
                        if (!take && id != items::ARMOR_COUNT) {
                            cand.kind = 1;
                            cand.id = (int)id;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
                        }
                        break;
                    }
                    case dm::treasure::MIK_SCROLL:""",
'state_dungeon.cpp armor pack')

OK &= patch('game/state_dungeon.cpp',
"""                if (take) {
                    carriedOff.push_back(mi);
                    it = hoard.magic.erase(it);""",
"""                // R85: the pack - unclaimed uncursed gear is
                // carried by the first living member with a free
                // slot; full packs leave it appraised (as before)
                if (!take && carryable && mi.qty == 1) {
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        if (packAdd(c, cand)) {
                            snprintf(buf, sizeof buf,
                                     "%s carries the %s "
                                     "(pack %d/%d).",
                                     c.name.c_str(),
                                     mi.name.c_str(),
                                     (int)c.pack.size(),
                                     PACK_CAP);
                            log.add(buf);
                            take = true;
                            break;
                        }
                    }
                }
                if (take) {
                    carriedOff.push_back(mi);
                    it = hoard.magic.erase(it);""",
'state_dungeon.cpp carry block')
# R85-CHUNK-3-END
