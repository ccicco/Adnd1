#include "appstate.h"

// ---- restExplore ----
void AppState::restExplore(){
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;

        log.add("The party makes camp...");
        if (dm::wanderCheck(dice, wander)) {
            log.add("The rest is interrupted!");
            spawnWanderingEncounter();
            return;
        }

        restoreSlots();
        // R38: a completed rest renews arrows too â fletching and
        // recovery time (interrupted rests restore nothing, as
        // with slots)
        restockAmmo();
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;   // the dead do not heal
            int heal = c.level;
            if (c.hp + heal > c.maxHp) heal = c.maxHp - c.hp;
            if (heal > 0) c.hp += heal;
        }
        log.add("The company rests. Spells and wounds mend.");
    }

// ---- countOccupied ----
int AppState::countOccupied() const{
        int n = 0;
        for (const auto& r : occupancy.rooms)
            if (!r.monsterKey.empty()) ++n;
        return n;
    }

// ---- populateRooms ----
void AppState::populateRooms(){
        // R52: lairs roll from the DMG Appendix C tables —
        // the Determination Matrix for this depth, then the
        // Monster Level Table row (count, hydra heads, dragon
        // hp/die brackets). The R42 depth cap still bounds lair
        // size.
        for (auto& room : occupancy.rooms) {
            room.monsterKey.clear();
            room.count = 0;
            room.looted = false;
            room.trap = 0;
            room.flavorSeen = false;   // R46
            room.headsLo = room.headsHi = 0;
            room.ageLo = room.ageHi = 0;
            if (rng.below(100) >= 50) {
                // R45: an unoccupied room may hide a dart trap
                if (rng.below(100) < 15) room.trap = 1;
                continue;
            }
            dm::DungeonEncounter e = rollDmEncounter();
            if (e.isParty) {
                // R53: NPC parties wander the halls — they do
                // not lair; the room stays unoccupied (trap chance)
                if (rng.below(100) < 15) room.trap = 1;
                continue;
            }
            if (e.key.empty() || e.count <= 0) {
                // NO ENCOUNTER (or an R53 row re-rolled out):
                // the room stays unoccupied (trap chance as above)
                if (rng.below(100) < 15) room.trap = 1;
                continue;
            }
            room.monsterKey = e.key;
            room.count = e.count > roomCountCap()
                ? roomCountCap() : e.count;
            room.headsLo = e.headsLo; room.headsHi = e.headsHi;
            room.ageLo = e.ageLo;     room.ageHi = e.ageHi;
        }
    }

// ---- roomCountCap ----
int AppState::roomCountCap() const{
        // R42: lairs grow with depth (2 on level 1, +1 per two
        // levels beyond, capped at 5)
        int cap = 2 + (dungeonLevel - 1) / 2;
        return cap > 5 ? 5 : cap;
    }

// ---- roomAt ----
int AppState::roomAt(int x, int y) const{
        for (size_t i = 0; i < dungeon.rooms.size(); ++i) {
            const auto& r = dungeon.rooms[i];
            if (x >= r.x && x < r.x + r.w &&
                y >= r.y && y < r.y + r.h)
                return (int)i;
        }
        return -1;
    }

// ---- occupiedRoomNear ----
int AppState::occupiedRoomNear(int px, int py, int radius) const{
        for (const auto& room : occupancy.rooms) {
            if (room.monsterKey.empty()) continue;
            const auto& r = dungeon.rooms[room.roomIndex];
            if (px >= r.x - radius && px < r.x + r.w + radius &&
                py >= r.y - radius && py < r.y + r.h + radius)
                return room.roomIndex;
        }
        return -1;
    }

// ---- trapRoomNear ----
int AppState::trapRoomNear(int px, int py, int radius) const{
        for (const auto& room : occupancy.rooms) {
            if (room.trap != 1) continue;
            const auto& r = dungeon.rooms[room.roomIndex];
            if (px >= r.x - radius && px < r.x + r.w + radius &&
                py >= r.y - radius && py < r.y + r.h + radius)
                return room.roomIndex;
        }
        return -1;
    }

// ---- springTrap ----
void AppState::springTrap(int roomIndex){
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.trap != 1) return;

        for (const auto& c : party.members) {
            if (c.hp <= 0 || c.classIndex != 3) continue;
            if (rng.below(3) == 0) {
                room.trap = 2;
                log.add(c.name + " spots a dart trap and "
                        "disarms it.");
                return;
            }
            break;   // one thief attempt per trap
        }

        room.trap = 2;
        // pick the unlucky one who leads into the room
        int victims[PARTY_MAX];
        int nv = 0;
        for (int i = 0; i < (int)party.members.size(); ++i)
            if (party.members[i].hp > 0)
                victims[nv++] = i;
        if (nv == 0) return;
        int vi = victims[(size_t)rng.below((uint32_t)nv)];
        Character& c = party.members[vi];
        int target = rules::saveTarget(
            c.classIndex, c.level, rules::SAVE_DEATH_POISON);
        if (rules::attemptSave(dice, target, 0)) {
            char buf[96];
            snprintf(buf, sizeof buf,
                     "A dart whistles past %s â saved!",
                     c.name.c_str());
            log.add(buf);
            return;
        }
        int dmg = (int)dice.roll(2, 6, 0);
        c.hp -= dmg;
        char buf[96];
        if (c.hp <= 0) {
            c.hp = 0;
            snprintf(buf, sizeof buf,
                     "A trap! Darts strike %s for %d â %s "
                     "falls!",
                     c.name.c_str(), dmg, c.name.c_str());
        } else {
            snprintf(buf, sizeof buf,
                     "A trap! Darts strike %s for %d.",
                     c.name.c_str(), dmg);
        }
        log.add(buf);
        if (!party.alive()) {
            log.add("GAME OVER - press N to roll a new party.");
        }
    }

// ---- placeSecretDoors ----
void AppState::placeSecretDoors(){
        secretDoors.clear();
        int placed = 0;
        int guard = 0;
        while (placed < 3 && ++guard < 500) {
            int x = 1 + (int)rng.below(MAP_TILES_X - 2);
            int y = 1 + (int)rng.below(MAP_TILES_Y - 2);
            if (map.at(x, y) != TILE_WALL) continue;
            bool bordersFloor = false;
            if (map.at(x + 1, y) == TILE_FLOOR ||
                map.at(x - 1, y) == TILE_FLOOR ||
                map.at(x, y + 1) == TILE_FLOOR ||
                map.at(x, y - 1) == TILE_FLOOR)
                bordersFloor = true;
            if (!bordersFloor) continue;
            bool tooClose = false;
            for (const auto& d : secretDoors)
                if (d.x == x && d.y == y) tooClose = true;
            if (tooClose) continue;
            SecretDoor d;
            d.x = x;
            d.y = y;
            secretDoors.push_back(d);
            ++placed;
        }
    }

// ---- searchExplore ----
void AppState::searchExplore(){
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;
        ++turnCount;
        bool hasThief = false;
        for (const auto& c : party.members)
            if (c.hp > 0 && c.classIndex == 3) hasThief = true;
        int chance = hasThief ? 3 : 1;
        bool found = false;
        for (auto& d : secretDoors) {
            if (d.found) continue;
            int dx = d.x - party.x;
            int dy = d.y - party.y;
            if (dx < -1 || dx > 1 || dy < -1 || dy > 1)
                continue;
            if (dx != 0 && dy != 0) continue;   // orthogonal
            if (dx == 0 && dy == 0) continue;
            if ((int)rng.below(6) < chance) {
                d.found = true;
                map.set(d.x, d.y, TILE_DOOR);
                found = true;
            }
        }
        if (found) {
            log.add("Your fingers find the seam of a secret "
                    "door!");
        } else {
            log.add("You search the walls and find nothing.");
        }
        // the turn spent can draw a wanderer
        if (dm::wanderCheck(dice, wander))
            spawnWanderingEncounter();
    }

// ---- rollTreasure ----
Treasure AppState::rollTreasure(int roomIndex){
        Treasure t;
        (void)roomIndex;
        // R42: gold scales up with depth â 25% more per level
        // above the first (the dungeon hoards grow richer)
        int goldMult = 100 + 25 * (dungeonLevel - 1);
        if (goldMult > 200) goldMult = 200;   // cap at +100%
        t.gold = (int)dice.roll(3, 6, 0) * 10 * dungeonLevel;
        t.gold = t.gold * goldMult / 100;
        if (rng.below(100) < 10) t.potionHealing = true;
        if (rng.below(100) < 5) t.magicSword = true;
        if (rng.below(100) < 10) t.missileWeapon = true;   // R28
        if (rng.below(100) < 15) t.ammoBundle = true;      // R39
        if (rng.below(100) < 5) t.thrownDagger = true;     // R40
        if (rng.below(100) < 8) t.identifyScroll = true;   // R44
        if (rng.below(100) < 5) t.unidentifiedItem = true; // R44
        return t;
    }

// ---- awardVictory ----
void AppState::awardVictory(){
        if (!combat.encounter || combat.lastResult != 0) return;

        const monsters::MonsterDef* def = registry.find(combatMonsterKey);
        int survivors = 0;
        for (const auto& a : combat.encounter->party())
            if (a.alive()) ++survivors;
        if (survivors < 1) survivors = 1;

        int slain = 0;
        int totalXp = 0;
        int idx = 0;
        for (const auto& m : combat.encounter->monsters()) {
            monsters::xp::SpawnContext ctx =   // R51: per-foe context
                (idx < (int)foeCtxs.size()) ? foeCtxs[idx]
                                            : monsters::xp::SpawnContext();
            ++idx;
            if (m.alive()) continue;
            ++slain;
            ctx.actualHp = m.maxHp;      // the specimen actually fought
            if (def)
                totalXp += monsters::xp::xpForKill(*def, ctx);
            else if (ctx.level > 0 || ctx.classIndex >= 0)
                // R53: a Character Subtable party member (no lua
                // record) — the def-free by_level ladder
                totalXp += monsters::xp::xpForNpc(ctx);
            else
                totalXp += 10;
        }

        if (slain > 0) {
            int share = totalXp / survivors;
            party.kills += slain;
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%d slain, %d xp each.", slain, share);
            log.add(buf);
            party.gainXp(share, dice, log);
            // R45: the hire earns a half share (DMG p.86 â
            // henchmen take half a member's share)
            if (party.henchmanPresent) {
                party.henchmanXp += share / 2;
                while (party.henchmanLevel <
                           rules::CLASS_LEVEL_CAP[0] &&
                       party.henchmanXp >=
                           rules::xpForLevel(
                               0, party.henchmanLevel + 1)) {
                    ++party.henchmanLevel;
                    int die =
                        (int)dice.roll(1, 10, 0) + 1;
                    party.henchmanMaxHp += die;
                    party.henchmanHp += die;
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "%s attains level %d! (+%d hp, "
                             "now %d/%d)",
                             party.henchmanName.c_str(),
                             party.henchmanLevel, die,
                             party.henchmanHp,
                             party.henchmanMaxHp);
                    log.add(buf);
                }
            }
        }

        // ---- R71: MM Treasure Types (verified p.105 table) ----
        // A monster carrying lair letters yields its hoard when the
        // party wins a lair fight (combatRoomIndex >= 0); individual
        // letters are looted from the slain on any victory (MM:
        // "pieces per individual"). The legacy room hoard still
        // applies to lair monsters without MM letters.
        const bool mmLair = def && !def->treasure.lair.empty() &&
                           combatRoomIndex >= 0;
        dm::treasure::Hoard hoard;
        if (def) {
            if (mmLair)
                for (const auto& e : def->treasure.lair)
                    for (int t = 0; t < e.times; ++t)
                        hoard.absorb(dm::treasure::rollTreasureType(
                            dice, e.letter, 1, e.magicOnly));
            for (const auto& e : def->treasure.individual)
                for (int t = 0; t < e.times; ++t)
                    hoard.absorb(dm::treasure::rollTreasureType(
                        dice, e.letter, slain, e.magicOnly));
        }
        if (!hoard.empty()) {
            char buf[192];
            if (hoard.cp || hoard.sp || hoard.ep ||
                hoard.gp || hoard.pp) {
                snprintf(buf, sizeof buf,
                         "The hoard holds %lld cp, %lld sp, "
                         "%lld ep, %lld gp, %lld pp.",
                         hoard.cp, hoard.sp, hoard.ep,
                         hoard.gp, hoard.pp);
                log.add(buf);
            }
            if (hoard.gemCount > 0) {
                snprintf(buf, sizeof buf,
                         "%d gems, worth %lld gp in all.",
                         hoard.gemCount, hoard.gemValue);
                log.add(buf);
            }
            if (hoard.jewelryCount > 0) {
                snprintf(buf, sizeof buf,
                         "%d pieces of jewelry, worth %lld gp.",
                         hoard.jewelryCount, hoard.jewelryValue);
                log.add(buf);
            }
            // R76: healing draughts are CARRIED, not sold — the
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
            for (const auto& mi : hoard.magic) {
                if (mi.qty > 1)
                    snprintf(buf, sizeof buf,
                             "You find: %s x%d "
                             "(sale value %d gp each).",
                             mi.name.c_str(), mi.qty, mi.gp);
                else
                    snprintf(buf, sizeof buf,
                             "You find: %s (sale value %d gp).",
                             mi.name.c_str(), mi.gp);
                log.add(buf);
                if (!mi.note.empty())
                    log.add(mi.note);
            }
            for (const auto& n : hoard.notes)
                log.add("You find " + n + ".");

            // The take, appraised and carried (no item inventory);
            // coins converted at the 1e exchange rates.
            long long gpv = hoard.goldValue();
            if (gpv > 0) {
                party.gold += (int)gpv;
                party.delveGold += (int)gpv;
                snprintf(buf, sizeof buf,
                         "The take is worth %lld gp.", gpv);
                log.add(buf);
                // R26 treasure XP, R61: the same DMG p.86 guard
                // rule as the legacy hoard path
                double partyAvgLvl = 0.0;
                for (const auto& c : party.members)
                    if (c.hp > 0) partyAvgLvl += c.level;
                partyAvgLvl /= (survivors > 0) ? survivors : 1;
                double guardLvl = 0.0;
                if (mmLair && def)
                    guardLvl = rules::monsterEffectiveLevel(
                        def->hitDice);
                int goldShare = treasureXpForGold(
                    (int)gpv, partyAvgLvl, guardLvl) / survivors;
                if (goldShare > 0) {
                    snprintf(buf, sizeof buf,
                             "Treasure worth %d xp each.",
                             goldShare);
                    log.add(buf);
                    party.gainXp(goldShare, dice, log);
                }
            }
        }

        if (combatRoomIndex >= 0 && !mmLair) {
            RoomOccupant& room = occupancy.rooms[combatRoomIndex];
            if (!room.monsterKey.empty()) {
                Treasure t = rollTreasure(combatRoomIndex);
                if (t.gold > 0) {
                    party.gold += t.gold;
                    party.delveGold += t.gold;   // R45: the take
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You loot %d gp.", t.gold);
                    log.add(buf);
                    // R26 treasure XP, R61: DMG p.86 guard rule.
                    // 1 gp = 1 xp only when the guardian's
                    // relative value equals or exceeds the
                    // party's; weaker guardians award on the
                    // printed sliding scale. Proxy: average
                    // party level vs the hoard monster's
                    // effective level (no key = unguarded
                    // delve, 1:1). Split among living members
                    // like combat XP (victory only; fleeing
                    // leaves loot AND xp behind).
                    double partyAvgLvl = 0.0;
                    for (const auto& c : party.members)
                        if (c.hp > 0) partyAvgLvl += c.level;
                    partyAvgLvl /= (survivors > 0) ? survivors : 1;
                    double guardLvl = 0.0;
                    if (!room.monsterKey.empty()) {
                        const monsters::MonsterDef* gd =
                            registry.find(room.monsterKey);
                        if (gd)
                            guardLvl = rules::monsterEffectiveLevel(
                                gd->hitDice);
                    }
                    int goldShare = treasureXpForGold(
                        t.gold, partyAvgLvl, guardLvl) / survivors;
                    if (goldShare > 0) {
                        snprintf(buf, sizeof buf,
                                 "Treasure worth %d xp each.",
                                 goldShare);
                        log.add(buf);
                        party.gainXp(goldShare, dice, log);
                    }
                }
                if (t.potionHealing) {
                    ++party.potions;
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You find a potion of healing! (%d carried)",
                             party.potions);
                    log.add(buf);
                }
                if (t.magicSword) {
                    log.add("You find a +1 long sword!");
                    // R24: claimed by the first living fighter
                    for (auto& c : party.members) {
                        if (c.hp > 0 &&
                            c.classIndex == rules::CLASS_FIGHTER) {
                            c.weapon.id = items::WPN_LONG_SWORD;
                            c.weapon.plus = 1;
                            log.add(c.name + " claims it.");
                            break;
                        }
                    }
                }
                // R40: +1 dagger â throwable loot. Claimed by the
                // first living member whose melee weapon is either
                // already throwable (an upgrade in plus â dagger
                // over axe/spear swaps hurlability for enchantment)
                // or non-throwable and weaker-armed (dagger damage
                // beats bare fists, matches the 1d4 starter)
                if (t.thrownDagger) {
                    log.add("You find a +1 dagger!");
                    Character* taker = nullptr;
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        bool throwable = (c.weapon.id ==
                                          items::WPN_DAGGER ||
                                          c.weapon.id ==
                                          items::WPN_HAND_AXE ||
                                          c.weapon.id ==
                                          items::WPN_SPEAR);
                        bool upgrade = throwable
                            ? c.weapon.plus < 1
                            : (c.weapon.id == items::WPN_DAGGER ||
                               c.weapon.plus < 1);
                        if (upgrade) { taker = &c; break; }
                    }
                    if (taker) {
                        taker->weapon.id = items::WPN_DAGGER;
                        taker->weapon.plus = 1;
                        log.add(taker->name + " claims it.");
                    } else {
                        log.add("No one can use it; it is left "
                                "behind.");
                    }
                }
                // R28: short bow â claimed by the first living
                // member with an empty ranged slot
                if (t.missileWeapon) {
                    log.add("You find a short bow!");
                    for (auto& c : party.members) {
                        if (c.hp > 0 &&
                            !items::weapon(
                                c.rangedWeapon.id).missile) {
                            c.rangedWeapon.id = items::WPN_SHORT_BOW;
                            // R35: the find includes a quiver
                            c.missileAmmo = 20;
                            log.add(c.name + " takes it.");
                            break;
                        }
                    }
                }
                // R39: a bundle of arrows â given to the first
                // living missile-armed member BELOW the 20 cap,
                // else the least-supplied one (stacking quivers is
                // a simplification: no encumbrance, no cap split)
                if (t.ammoBundle) {
                    Character* taker = nullptr;
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        if (!items::weapon(
                                c.rangedWeapon.id).missile) continue;
                        if (!taker || c.missileAmmo < taker->missileAmmo)
                            taker = &c;
                        if (taker->missileAmmo < 20) break;
                    }
                    if (taker) {
                        taker->missileAmmo += 20;
                        char buf[96];
                        snprintf(buf, sizeof buf,
                                 "You find a bundle of arrows! "
                                 "%s now carries %d.",
                                 taker->name.c_str(),
                                 taker->missileAmmo);
                        log.add(buf);
                    } else {
                        log.add("You find a bundle of arrows, but "
                                "no one can carry more.");
                    }
                }
                // R44: an identify scroll joins the satchel
                if (t.identifyScroll) {
                    ++party.identifyScrolls;
                    log.add("You find a scroll of identify!");
                }
                // R44: an unidentified magic item â the enchant
                // is rolled now but hidden until a scroll is
                // read over it ([I] in town)
                if (t.unidentifiedItem) {
                    Party::PendingItem it;
                    it.kind = (int)rng.below(2);
                    it.plus = 1 +
                        (rng.below(100) < 10 ? 1 : 0);
                    party.unidentified.push_back(it);
                    log.add("You find an unidentified magic "
                            "item â a scribe's scroll would "
                            "serve.");
                }
                room.monsterKey.clear();
                room.count = 0;
                room.looted = true;
            }
        }

        // R56: defeated NPC parties drop their gear. A wandering
        // Character Subtable party (DMG p.176) fights with book-
        // rolled magic items (R55) â the winners strip the
        // fallen: the best enchanted weapon/armor/shield among the
        // SLAIN (survivors keep theirs), plus a coin purse
        // (adventurers carry walking money, not hoards â
        // 2d6 x 10 x dungeon level, the design figure; same
        // 1-gp-1-xp treasure convention as room hoards).
        if (combatRoomIndex < 0 && combat.encounter) {
            int bestWpn = 0, bestArm = 0, bestShd = 0;
            items::WeaponId wpnId = items::WPN_LONG_SWORD;
            items::ArmorId   armId = items::ARMOR_PLATE;
            bool anyFoe = false;
            for (const auto& m : combat.encounter->monsters()) {
                if (!m.isCharacter) continue;
                anyFoe = true;
                if (m.alive()) continue;   // survivors keep gear
                if (m.weapon.plus > bestWpn) {
                    bestWpn = m.weapon.plus;
                    wpnId = m.weapon.id;
                }
                if (m.armor.plus > bestArm) {
                    bestArm = m.armor.plus;
                    armId = m.armor.id;
                }
                if (m.shieldPlus > bestShd)
                    bestShd = m.shieldPlus;
            }
            if (anyFoe) {
                int gp = (int)dice.roll(2, 6, 0) * 10 * dungeonLevel;
                if (gp > 0) {
                    party.gold += gp;
                    party.delveGold += gp;   // R45: the crew's cut
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You strip %d gp from the fallen.",
                             gp);
                    log.add(buf);
                    // R61: DMG p.86 guard rule here too
                    // (the guardian is the NPC party itself;
                    // proxy: average level of the character
                    // foes faced).
                    double partyAvgLvl = 0.0;
                    for (const auto& c : party.members)
                        if (c.hp > 0) partyAvgLvl += c.level;
                    partyAvgLvl /= (survivors > 0) ? survivors : 1;
                    double guardLvl = 0.0;
                    int guardN = 0;
                    for (const auto& m :
                         combat.encounter->monsters()) {
                        if (!m.isCharacter) continue;
                        guardLvl += m.level;
                        ++guardN;
                    }
                    if (guardN > 0) guardLvl /= guardN;
                    int goldShare = treasureXpForGold(
                        gp, partyAvgLvl, guardLvl) / survivors;
                    if (goldShare > 0) {
                        snprintf(buf, sizeof buf,
                                 "Worth %d xp each.", goldShare);
                        log.add(buf);
                        party.gainXp(goldShare, dice, log);
                    }
                }
                if (bestWpn > 0) {
                    const items::WeaponDef& w =
                        items::weapon(wpnId);
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You take a +%d %s from the fallen!",
                             bestWpn, w.name);
                    log.add(buf);
                    int wpnMax = w.smCount * w.smSides + w.smBonus;
                    Character* taker = nullptr;
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        if (c.weapon.plus >= bestWpn) continue;
                        if (c.weapon.id == wpnId) {
                            taker = &c;   // same steel, better steel
                            break;
                        }
                    }
                    if (!taker) {
                        for (auto& c : party.members) {
                            if (c.hp <= 0) continue;
                            if (c.weapon.plus >= bestWpn) continue;
                            const items::WeaponDef& cw =
                                items::weapon(c.weapon.id);
                            if (wpnMax >=
                                cw.smCount * cw.smSides + cw.smBonus)
                                { taker = &c; break; }
                        }
                    }
                    if (taker) {
                        taker->weapon.id = wpnId;
                        taker->weapon.plus = bestWpn;
                        log.add(taker->name + " claims it.");
                    } else {
                        log.add("No one can wield it; it is "
                                "left behind.");
                    }
                }
                if (bestArm > 0) {
                    const items::ArmorDef& a =
                        items::armor(armId);
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You take %s +%d from the fallen!",
                             a.name, bestArm);
                    log.add(buf);
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        if (c.armor.plus >= bestArm) continue;
                        if (!rules::armorAllowed(c.classIndex,
                                                 a.weight))
                            continue;
                        c.armor.id = armId;
                        c.armor.plus = bestArm;
                        log.add(c.name + " claims it.");
                        break;
                    }
                }
                if (bestShd > 0) {
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You take a +%d shield from the "
                             "fallen!", bestShd);
                    log.add(buf);
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        if (!rules::shieldAllowed(c.classIndex))
                            continue;
                        if (c.shield && c.shieldPlus >= bestShd)
                            continue;
                        c.shield = true;
                        c.shieldPlus = bestShd;
                        log.add(c.name + " claims it.");
                        break;
                    }
                }
            }
        }
    }

// ---- spawnRoomEncounter ----
void AppState::spawnRoomEncounter(int roomIndex){
        if (mode == MODE_COMBAT) return;
        if (!party.alive()) return;
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.monsterKey.empty()) return;

        const monsters::MonsterDef* def = registry.find(room.monsterKey);
        // R52: foes build through the DMG-range path (hydra
        // heads / dragon age brackets, stored at population)
        std::vector<ai::Actor> foes =
            buildFoesFromDm(encFromRoom(room));
        if (foes.empty()) return;
        const char* mname = def ? def->name.c_str() : "monster";
        char buf[96];
        if (room.count == 1)
            snprintf(buf, sizeof buf, "A %s leaps at you!", mname);
        else
            snprintf(buf, sizeof buf, "%d %ss leap at you!",
                     room.count, mname);
        log.add(buf);

        beginCombat(std::move(foes), roomIndex, room.monsterKey);
    }
