#!/usr/bin/env python3
"""claim_splice_r77.py -- splice the R77 claim layer into
game/state_dungeon.cpp, replacing the R76 carriedOff block inside
AppState::awardVictory. Content-anchored (no line numbers), idempotent
(marker: MIK_SWORD already present = skip). Run from repo root."""
import sys

path = 'game/state_dungeon.cpp'
for a in sys.argv[1:]:
    if not a.startswith('--'):
        path = a

src = open(path, encoding='utf-8').read()

if 'MIK_SWORD' in src:
    print('R77 claim block already present — nothing to do.')
    sys.exit(0)

OLD = '''            // R76: healing draughts are CARRIED, not sold — the
            // party already stacks potions (quaff hook). Everything
            // else stays appraised to gold (the R71 simplification,
            // now one item narrower). Carried items leave the hoard
            // before the take is appraised.
            std::vector<dm::treasure::MagicItem> carriedOff;
            for (auto it = hoard.magic.begin();
                 it != hoard.magic.end(); ) {
                if (it->isHealingPotion()) {
                    carriedOff.push_back(*it);
                    it = hoard.magic.erase(it);
                } else {
                    ++it;
                }
            }
            for (const auto& mi : carriedOff) {
                party.potions += mi.qty;
                snprintf(buf, sizeof buf,
                         "You find: %s x%d — carried (%d held).",
                         mi.name.c_str(), mi.qty, party.potions);
                log.add(buf);
                if (!mi.note.empty())
                    log.add(mi.note);
            }
'''

NEW = '''            // R77: the claim layer — magic finds go to living party
            // members when they improve the member's gear; carried
            // stacks (potions, scrolls) pool. Cursed items (III.F/G/H
            // rows) are never claimed — the party does not knowingly
            // take up a Sword +1, Cursed. Ammo bundles await real
            // inventory (per-arrow tracking). Claimed and carried
            // items leave the hoard BEFORE the take is appraised:
            // nothing is both wielded and sold.
            std::vector<dm::treasure::MagicItem> carriedOff;
            for (auto it = hoard.magic.begin();
                 it != hoard.magic.end(); ) {
                const dm::treasure::MagicItem& mi = *it;
                bool take = false;
                if (mi.cursed()) {
                    // never claimed — stays appraised below
                } else if (mi.isHealingPotion()) {
                    party.potions += mi.qty;
                    snprintf(buf, sizeof buf,
                             "You find: %s x%d — carried (%d held).",
                             mi.name.c_str(), mi.qty, party.potions);
                    log.add(buf);
                    if (!mi.note.empty()) log.add(mi.note);
                    take = true;
                } else {
                    switch (mi.kind()) {
                    case dm::treasure::MIK_SWORD:
                        // III.G blade -> first living member whose
                        // melee slot is not a better-enchanted sword
                        for (auto& c : party.members) {
                            if (c.hp <= 0) continue;
                            if (c.weapon.plus < mi.weaponPlus()) {
                                c.weapon.id = items::WPN_LONG_SWORD;
                                c.weapon.plus = mi.weaponPlus();
                                snprintf(buf, sizeof buf,
                                         "%s claims the %s!",
                                         c.name.c_str(),
                                         mi.name.c_str());
                                log.add(buf);
                                take = true;
                                break;
                            }
                        }
                        break;
                    case dm::treasure::MIK_MELEE: {
                        // III.H melee weapons -> the melee slot, by
                        // printed name. Unmapped exotics (Hammer of
                        // Thunderbolts &c) stay appraised.
                        items::WeaponId id = items::WPN_COUNT;
                        const std::string& n = mi.name;
                        if (n.find("Dagger") != std::string::npos)
                            id = items::WPN_DAGGER;
                        else if (n.find("Battle Axe") !=
                                 std::string::npos)
                            id = items::WPN_BATTLE_AXE;
                        else if (n.find("Axe") != std::string::npos)
                            id = items::WPN_HAND_AXE;
                        else if (n.find("Mace") != std::string::npos)
                            id = items::WPN_MACE;
                        else if (n.find("Flail") != std::string::npos)
                            id = items::WPN_FLAIL;
                        else if (n.find("Morning Star") !=
                                 std::string::npos)
                            id = items::WPN_MORNING_STAR;
                        else if (n.find("Spear") != std::string::npos ||
                                 n.find("Javelin") !=
                                     std::string::npos)
                            id = items::WPN_SPEAR;
                        else if (n.find("Scimitar") !=
                                 std::string::npos)
                            id = items::WPN_SHORT_SWORD;
                        if (id != items::WPN_COUNT)
                            for (auto& c : party.members) {
                                if (c.hp <= 0) continue;
                                if (c.weapon.plus < mi.weaponPlus()) {
                                    c.weapon.id = id;
                                    c.weapon.plus = mi.weaponPlus();
                                    snprintf(buf, sizeof buf,
                                             "%s claims the %s!",
                                             c.name.c_str(),
                                             mi.name.c_str());
                                    log.add(buf);
                                    take = true;
                                    break;
                                }
                            }
                        break;
                    }
                    case dm::treasure::MIK_MISSILE: {
                        // III.H bow/crossbow/sling -> the ranged slot;
                        // a claimant with an empty quiver is handed
                        // 20 missiles (DMG p.27 bundle convention)
                        items::WeaponId id = items::WPN_COUNT;
                        const std::string& n = mi.name;
                        if (n.find("Crossbow") != std::string::npos)
                            id = items::WPN_CROSSBOW_LIGHT;
                        else if (n.find("Bow") != std::string::npos)
                            id = items::WPN_SHORT_BOW;
                        else if (n.find("Sling") != std::string::npos)
                            id = items::WPN_SLING;
                        if (id != items::WPN_COUNT)
                            for (auto& c : party.members) {
                                if (c.hp <= 0) continue;
                                if (c.rangedWeapon.plus <
                                        mi.weaponPlus()) {
                                    c.rangedWeapon.id = id;
                                    c.rangedWeapon.plus =
                                        mi.weaponPlus();
                                    if (c.missileAmmo <= 0)
                                        c.missileAmmo = 20;
                                    snprintf(buf, sizeof buf,
                                             "%s claims the %s!",
                                             c.name.c_str(),
                                             mi.name.c_str());
                                    log.add(buf);
                                    take = true;
                                    break;
                                }
                            }
                        break;
                    }
                    case dm::treasure::MIK_SHIELD:
                        // III.F shield rows -> the shield slot (or the
                        // existing shield's enchant, if better)
                        for (auto& c : party.members) {
                            if (c.hp <= 0) continue;
                            if (!c.shield ||
                                c.shieldPlus < mi.weaponPlus()) {
                                c.shield = true;
                                c.shieldPlus = mi.weaponPlus();
                                snprintf(buf, sizeof buf,
                                         "%s takes the %s.",
                                         c.name.c_str(),
                                         mi.name.c_str());
                                log.add(buf);
                                take = true;
                                break;
                            }
                        }
                        break;
                    case dm::treasure::MIK_ARMOR: {
                        // III.F armor rows -> the armor slot, but ONLY
                        // when the effective AC improves for that
                        // member (plus, DEX and shield all weighed)
                        items::ArmorId id = items::ARMOR_COUNT;
                        const std::string& n = mi.name;
                        if (n.find("Padded") != std::string::npos)
                            id = items::ARMOR_PADDED;
                        else if (n.find("Studded") != std::string::npos)
                            id = items::ARMOR_STUDDED_LEATHER;
                        else if (n.find("Leather") != std::string::npos)
                            id = items::ARMOR_LEATHER;
                        else if (n.find("Ring") != std::string::npos)
                            id = items::ARMOR_RING_MAIL;
                        else if (n.find("Scale") != std::string::npos)
                            id = items::ARMOR_SCALE_MAIL;
                        else if (n.find("Chain") != std::string::npos)
                            id = items::ARMOR_CHAIN_MAIL;
                        else if (n.find("Splint") != std::string::npos)
                            id = items::ARMOR_SPLINTED;
                        else if (n.find("Banded") != std::string::npos)
                            id = items::ARMOR_BANDED;
                        else if (n.find("Plate") != std::string::npos)
                            id = items::ARMOR_PLATE;
                        if (id != items::ARMOR_COUNT)
                            for (auto& c : party.members) {
                                if (c.hp <= 0) continue;
                                items::ArmorInstance cand;
                                cand.id = id;
                                cand.plus = mi.weaponPlus();
                                int oldAc = items::effectiveAc(
                                    c.armor, c.shield, c.shieldPlus,
                                    c.abilities.dex);
                                int newAc = items::effectiveAc(
                                    cand, c.shield, c.shieldPlus,
                                    c.abilities.dex);
                                if (newAc < oldAc) {   // lower = better
                                    c.armor = cand;
                                    snprintf(buf, sizeof buf,
                                             "%s dons the %s.",
                                             c.name.c_str(),
                                             mi.name.c_str());
                                    log.add(buf);
                                    take = true;
                                    break;
                                }
                            }
                        break;
                    }
                    case dm::treasure::MIK_SCROLL:
                        // III.B scrolls — carried, studied later
                        party.scrolls += mi.qty;
                        snprintf(buf, sizeof buf,
                                 "You find: %s x%d — carried (%d held).",
                                 mi.name.c_str(), mi.qty,
                                 party.scrolls);
                        log.add(buf);
                        if (!mi.note.empty()) log.add(mi.note);
                        take = true;
                        break;
                    default:
                        // MIK_AMMO (real inventory pending) and
                        // MIK_OTHER stay appraised to gold
                        break;
                    }
                }
                if (take) {
                    carriedOff.push_back(mi);
                    it = hoard.magic.erase(it);
                } else {
                    ++it;
                }
            }
'''

if OLD not in src:
    print('ERROR: R76 carriedOff block not found verbatim — '
          'state_dungeon.cpp differs from the expected bytes. '
          'Aborting without changes.')
    sys.exit(1)

src = src.replace(OLD, NEW, 1)
open(path, 'w', encoding='utf-8').write(src)
print('R77 claim block spliced into', path)
