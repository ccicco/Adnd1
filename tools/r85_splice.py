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
# R85-CHUNK-4-START

# ---------------------------------------------------------------------------
# 4) state_town.cpp - the two commands
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""// ---- R82: raise a dead member ----""",
"""// ---- R85: equip the best of the pack ----
void AppState::townSwapGear(){
        if (mode != MODE_TOWN) return;
        char buf[96];
        int swaps = 0;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            for (size_t i = 0; i < c.pack.size(); ++i) {
                const PackItem p = c.pack[i];
                if (!packImproves(c, p)) continue;
                // equip it; the old kit returns to the pack as a
                // gp 0 keepsake (kept, never sold)
                if (p.kind == 2) {
                    PackItem old{};
                    old.kind = 2;
                    old.plus = c.shieldPlus;
                    c.shield = true;
                    c.shieldPlus = p.plus;
                    c.pack[i] = old;
                } else if (p.kind == 1) {
                    PackItem old{};
                    old.kind = 1;
                    old.id = (int)c.armor.id;
                    old.plus = c.armor.plus;
                    c.armor.id = (items::ArmorId)p.id;
                    c.armor.plus = p.plus;
                    c.pack[i] = old;
                } else {
                    const items::WeaponDef& w = items::weapon(
                        (items::WeaponId)p.id);
                    PackItem old{};
                    old.kind = 0;
                    if (w.missile) {
                        old.id = (int)c.rangedWeapon.id;
                        old.plus = c.rangedWeapon.plus;
                        c.rangedWeapon.id =
                            (items::WeaponId)p.id;
                        c.rangedWeapon.plus = p.plus;
                        // parity with the MIK_MISSILE claim:
                        // an empty quiver is handed 20 missiles
                        if (c.missileAmmo <= 0)
                            c.missileAmmo = 20;
                    } else {
                        old.id = (int)c.weapon.id;
                        old.plus = c.weapon.plus;
                        c.weapon.id = (items::WeaponId)p.id;
                        c.weapon.plus = p.plus;
                    }
                    c.pack[i] = old;
                }
                snprintf(buf, sizeof buf,
                         "%s equips the %s.",
                         c.name.c_str(),
                         packItemName(p).c_str());
                log.add(buf);
                ++swaps;
            }
        }
        if (swaps == 0)
            log.add("No pack gear improves the company's kit.");
    }

// ---- R85: peddle the pack ----
void AppState::townSellPack(){
        if (mode != MODE_TOWN) return;
        char buf[128];
        int total = 0, sold = 0, kept = 0;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            std::vector<PackItem> keep;
            for (const auto& p : c.pack) {
                if (p.gp > 0) {
                    party.gold += p.gp;
                    total += p.gp;
                    ++sold;
                    snprintf(buf, sizeof buf,
                             "%s sells the %s for %d gp.",
                             c.name.c_str(),
                             packItemName(p).c_str(), p.gp);
                    log.add(buf);
                } else {
                    keep.push_back(p);
                    ++kept;
                }
            }
            c.pack = keep;
        }
        if (sold == 0 && kept == 0) {
            log.add("Nobody carries pack gear.");
        } else {
            snprintf(buf, sizeof buf,
                     "The pack sale nets %d gp.", total);
            log.add(buf);
            if (kept > 0)
                log.add("Keepsakes (swapped-out kit) stay "
                        "unsold.");
        }
    }

// ---- R82: raise a dead member ----""",
'state_town.cpp commands')
# R85-CHUNK-4-END
# R85-CHUNK-5-START

# ---------------------------------------------------------------------------
# 5) state_core.cpp - save, load, dump
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""            // R81: the Ring of Protection bonus (nonzero only)
            if (c.ringPlus > 0)
                fprintf(f, "ringplus %d\\n", c.ringPlus);""",
"""            // R81: the Ring of Protection bonus (nonzero only)
            if (c.ringPlus > 0)
                fprintf(f, "ringplus %d\\n", c.ringPlus);
            // R85: the pack (nonempty members only - v1 saves
            // carry no lines and load with an empty pack)
            if (!c.pack.empty()) {
                fprintf(f, "pack %d\\n", (int)c.pack.size());
                for (const auto& pi : c.pack)
                    fprintf(f, "pk %d %d %d %d\\n",
                            pi.kind, pi.id, pi.plus, pi.gp);
            }""",
'state_core.cpp save pack')

OK &= patch('game/state_core.cpp',
"""                } else if (strcmp(tag, "spells") == 0) {""",
"""                } else if (strcmp(tag, "pack") == 0) {
                    int npk = 0;
                    if (fscanf(f, "%d", &npk) != 1 ||
                        npk < 0 || npk > PACK_CAP) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (pack).");
                        return false;
                    }
                    for (int k = 0; k < npk; ++k) {
                        char t2[16];
                        int kd = 0, idd = 0, pl = 0, gpv = 0;
                        if (fscanf(f, "%15s %d %d %d %d",
                                   t2, &kd, &idd, &pl, &gpv)
                                != 5 ||
                            strcmp(t2, "pk") != 0 ||
                            kd < 0 || kd > 2 ||
                            pl < 0 || pl > 5 ||
                            gpv < 0 || gpv > 100000) {
                            fclose(f);
                            log.add("adnd1.sav is corrupt (pk).");
                            return false;
                        }
                        if (kd == 0 &&
                            (idd < 0 ||
                             idd >= (int)items::WPN_COUNT)) {
                            fclose(f);
                            log.add("adnd1.sav is corrupt (pkw).");
                            return false;
                        }
                        if (kd == 1 &&
                            (idd < 0 ||
                             idd >= (int)items::ARMOR_COUNT)) {
                            fclose(f);
                            log.add("adnd1.sav is corrupt (pka).");
                            return false;
                        }
                        PackItem pi;
                        pi.kind = kd; pi.id = idd;
                        pi.plus = pl; pi.gp = gpv;
                        c.pack.push_back(pi);
                    }
                } else if (strcmp(tag, "spells") == 0) {""",
'state_core.cpp load pack')

OK &= patch('game/state_core.cpp',
"""                snprintf(buf, sizeof buf, "  %s's quiver:%s",
                         c.name.c_str(), bands.c_str());
                log.add(buf);
            }
""",
"""                snprintf(buf, sizeof buf, "  %s's quiver:%s",
                         c.name.c_str(), bands.c_str());
                log.add(buf);
            }
            // R85: the pack
            if (!c.pack.empty()) {
                std::string pk;
                for (const auto& pi : c.pack) {
                    if (!pk.empty()) pk += "; ";
                    pk += packItemName(pi);
                }
                snprintf(buf, sizeof buf,
                         "  %s's pack (%d/%d): %s",
                         c.name.c_str(), (int)c.pack.size(),
                         PACK_CAP, pk.c_str());
                log.add(buf);
            }
""",
'state_core.cpp dump pack')
# R85-CHUNK-5-END
# R85-CHUNK-6-START

# ---------------------------------------------------------------------------
# 6) adnd1.cpp - keys + drawTown
# ---------------------------------------------------------------------------
OK &= patch('adnd1.cpp',
"""                    case 'R':
                    case 'r':
                        g_app.townRaiseDead();
                        break;
""",
"""                    case 'R':
                    case 'r':
                        g_app.townRaiseDead();
                        break;

                    // R85: the pack commands
                    case 'E':
                    case 'e':
                        g_app.townSwapGear();
                        break;

                    case 'P':
                    case 'p':
                        g_app.townSellPack();
                        break;

                    case 'D':
                    case 'd':
                        g_app.dumpEquipment();
                        break;
""",
'adnd1.cpp pack keys')

OK &= patch('adnd1.cpp',
"""    // quiver summary so arrow buys are informed
    SetTextColor(dc, RGB(200, 190, 160));
    int y = 564;""",
"""    // R85: the pack commands + quiver summary, right column -
    // the menu column is full to y=600, and the quiver at 564
    // collided with the R83 study/raise lines (never seen: no
    // PC build has run since R68; fixed here)
    SetTextColor(dc, RGB(200, 190, 160));
    snprintf(line, sizeof line,
             "PACK: [E] equip best  [P] peddle  [D] dump kit");
    TextOutA(dc, 430, 340, line, (int)strlen(line));
    int y = 368;""",
'adnd1.cpp pack header')

OK &= patch('adnd1.cpp',
"""        snprintf(line, sizeof line, "%s - quiver %d",
                 nm, c.missileAmmo);
        TextOutA(dc, 20, y, line, (int)strlen(line));""",
"""        snprintf(line, sizeof line, "%s - quiver %d",
                 nm, c.missileAmmo);
        TextOutA(dc, 430, y, line, (int)strlen(line));""",
'adnd1.cpp quiver x')

# ---------------------------------------------------------------------------
# 7) preflight.sh - items.cpp joins the regtest build
# ---------------------------------------------------------------------------
OK &= patch('tools/preflight.sh',
"""  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp regtest.cpp \\""",
"""  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \\
  items/items.cpp regtest.cpp \\""",
'preflight.sh build line')
# R85-CHUNK-6-END
# R85-CHUNK-7-START

# ---------------------------------------------------------------------------
# 8) regtest.cpp - the R85 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R83 teleport audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R83 teleport audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R85: the pack audit ----
    {
        int bad = 0;
        // packAdd honors the cap
        Character c;
        c.hp = 10;
        PackItem p0{};
        p0.kind = 0;
        p0.id = (int)items::WPN_LONG_SWORD;
        p0.plus = 1;
        p0.gp = 100;
        int added = 0;
        while (packAdd(c, p0) && added < 99) ++added;
        if (added != PACK_CAP) ++bad;
        if (packAdd(c, p0)) ++bad;   // full pack refuses
        // names reconstruct from the tables
        PackItem w{};
        w.kind = 0;
        w.id = (int)items::WPN_LONG_SWORD;
        w.plus = 2;
        w.gp = 500;
        if (packItemName(w) != "Long Sword +2") ++bad;
        PackItem a{};
        a.kind = 1;
        a.id = (int)items::ARMOR_CHAIN_MAIL;
        a.plus = 0;
        a.gp = 75;
        if (packItemName(a) != "Chain Mail") ++bad;
        PackItem s{};
        s.kind = 2;
        s.id = 0;
        s.plus = 1;
        s.gp = 50;
        if (packItemName(s) != "Shield +1") ++bad;
        PackItem sb{};
        sb.kind = 2;
        sb.id = 0;
        sb.plus = 0;
        sb.gp = 10;
        if (packItemName(sb) != "Shield") ++bad;
        // improves routing
        c.pack.clear();
        c.weapon.id = items::WPN_LONG_SWORD;
        c.weapon.plus = 0;
        if (!packImproves(c, w)) ++bad;   // +2 over mundane
        c.weapon.plus = 2;
        if (packImproves(c, w)) ++bad;    // equal plus: no swap
        c.shield = false;
        c.shieldPlus = 0;
        if (!packImproves(c, s)) ++bad;   // no shield: wear it
        c.shield = true;
        c.shieldPlus = 3;
        if (packImproves(c, s)) ++bad;    // worse plus: no
        // armor routing via effectiveAc
        c.armor.id = items::ARMOR_LEATHER;
        c.armor.plus = 0;
        PackItem a2{};
        a2.kind = 1;
        a2.id = (int)items::ARMOR_CHAIN_MAIL;
        a2.plus = 0;
        a2.gp = 75;
        if (!packImproves(c, a2)) ++bad;  // chain beats leather
        c.armor.id = items::ARMOR_PLATE;
        if (packImproves(c, a2)) ++bad;   // plate wins: no
        // ranged routing: missile weapons look at the RANGED slot
        PackItem b{};
        b.kind = 0;
        b.id = (int)items::WPN_SHORT_BOW;
        b.plus = 1;
        b.gp = 100;
        c.rangedWeapon.id = items::WPN_SHORT_BOW;
        c.rangedWeapon.plus = 0;
        c.weapon.plus = 5;   // melee far better - must not matter
        if (!packImproves(c, b)) ++bad;
        c.rangedWeapon.plus = 3;
        if (packImproves(c, b)) ++bad;
        // dead members never improve
        c.hp = 0;
        if (packImproves(c, w)) ++bad;
        printf("R85 pack audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp audit')

# ---------------------------------------------------------------------------
print("\\n".join(REPORT))
print("R85 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R85-CHUNK-7-END
