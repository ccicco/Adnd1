#include "appstate.h"

// ---- enterTown ----
void AppState::enterTown(){
        if (mode != MODE_EXPLORE) return;
        mode = MODE_TOWN;
        log.add("You return to the town above.");
        billTownVisit();   // R70: the shared arrival billing
    }

// ---- billTownVisit ----
void AppState::billTownVisit(){
        // R44: the keep pays its rents on every return (the
        // delve cadence stands in for the month - simplified
        // stronghold economics)
        if (party.strongholdBuilt) {
            party.gold += 200;
            log.add("The keep's steward delivers 200 gp in "
                    "rents.");
        }
        // R44: henchman upkeep - 100 gp/level billed on each
        // return (DMG p.26 monthly support, delve cadence). A
        // short purse dents loyalty; below 25 he walks.
        if (party.henchmanPresent) {
            int upkeep = 100 * party.henchmanLevel;
            if (party.gold >= upkeep) {
                party.gold -= upkeep;
                char buf[96];
                snprintf(buf, sizeof buf,
                         "%s is paid %d gp for his service.",
                         party.henchmanName.c_str(), upkeep);
                log.add(buf);
            } else {
                party.henchmanLoyalty -= 10;
                log.add("The purse is too thin to pay " +
                        party.henchmanName +
                        " - he takes note.");
            }
            if (party.henchmanLoyalty < 25) {
                log.add(party.henchmanName +
                        " packs his kit and quits the company.");
                party.henchmanPresent = false;
            }
        }
        // R45: the hire's THIRD of the take (DMG p.36 - a
        // stated share; this campaign promised a half share
        // = a third of the delve's gold), paid at the exit
        // into his purse
        int crewCut = 0;
        if (party.crewHired && party.delveGold > 0) {
            crewCut = party.delveGold / 20;
            if (crewCut > 0) {
                char cbuf[96];
                snprintf(cbuf, sizeof cbuf,
                         "The crew's share: %d gp.", crewCut);
                log.add(cbuf);
            }
        }
        if (party.henchmanPresent && party.delveGold > 0) {
            int cut = (party.delveGold - crewCut) / 3;
            party.henchmanPurse += cut;
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%s is paid his share: %d gp (purse %d).",
                     party.henchmanName.c_str(), cut,
                     party.henchmanPurse);
            log.add(buf);
        }
        party.delveGold = 0;
        // R46: crew wages - 20 sailors at 2 gp (DMG p.34),
        // billed each return (delve cadence)
        if (party.crewHired) {
            if (party.gold >= 40) {
                party.gold -= 40;
                log.add("The crew is paid 40 gp in wages.");
            } else {
                log.add("The crew grumbles over unpaid "
                        "wages.");
            }
        }
    }

// ---- leaveTown ----
void AppState::leaveTown(){
        if (mode != MODE_TOWN) return;
        // R44: the loyalty check that gates each delve (DMG
        // p.37 - a disloyal hire refuses the descent; the roll
        // simplified to a single d100 vs loyalty)
        if (party.henchmanPresent) {
            int roll = (int)rng.below(100) + 1;
            if (roll > party.henchmanLoyalty) {
                log.add(party.henchmanName +
                        "'s nerve fails; he quits the company.");
                party.henchmanPresent = false;
            } else {
                log.add(party.henchmanName +
                        " shoulders his pack and follows.");
            }
        }
        mode = MODE_EXPLORE;
        log.add("You descend once more.");
    }

// ---- townBuyPotion ----
void AppState::townBuyPotion(){
        if (mode != MODE_TOWN) return;
        if (party.gold < 50) {
            log.add("The priest shakes his head - 50 gp.");
            return;
        }
        party.gold -= 50;
        ++party.potions;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Bought a potion of healing (%d carried, %d gp left).",
                 party.potions, party.gold);
        log.add(buf);
    }

// ---- townBuyArrows ----
void AppState::townBuyArrows(){
        if (mode != MODE_TOWN) return;
        Character* taker = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (!items::weapon(c.rangedWeapon.id).missile) continue;
            if (!taker || c.missileAmmo < taker->missileAmmo)
                taker = &c;
            if (taker->missileAmmo < 20) break;
        }
        if (!taker) {
            log.add("The fletcher shrugs - no one carries a bow.");
            return;
        }
        if (party.gold < 30) {
            log.add("The fletcher wants 30 gp.");
            return;
        }
        party.gold -= 30;
        taker->missileAmmo += 20;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Bought 20 arrows (%s carries %d, %d gp left).",
                 taker->name.c_str(), taker->missileAmmo, party.gold);
        log.add(buf);
    }

// ---- townInnRest ----
void AppState::townInnRest(){
        if (mode != MODE_TOWN) return;
        if (party.gold < 10) {
            log.add("The innkeeper wants 10 gp for the night.");
            return;
        }
        party.gold -= 10;
        restoreSlots();
        restockAmmo();
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            int heal = c.level;
            if (c.hp + heal > c.maxHp) heal = c.maxHp - c.hp;
            if (heal > 0) c.hp += heal;
        }
        // R44: the henchman bunks with the company - same 1
        // hp/level natural healing
        if (party.henchmanPresent &&
            party.henchmanHp < party.henchmanMaxHp) {
            int heal = party.henchmanLevel;
            if (party.henchmanHp + heal > party.henchmanMaxHp)
                heal = party.henchmanMaxHp - party.henchmanHp;
            party.henchmanHp += heal;
        }
        log.add("A safe night at the inn. Spells, quivers, and "
                "wounds mend.");
    }

// ---- townTempleHeal ----
void AppState::townTempleHeal(){
        if (mode != MODE_TOWN) return;
        Character* best = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (!best || (c.maxHp - c.hp) > (best->maxHp - best->hp))
                best = &c;
        }
        if (!best || best->hp >= best->maxHp) {
            log.add("The priests see no wounds to mend.");
            return;
        }
        if (party.gold < 100) {
            log.add("The high priest asks 100 gp for a cure.");
            return;
        }
        party.gold -= 100;
        best->hp = best->maxHp;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "%s is restored to %d hp.",
                 best->name.c_str(), best->hp);
        log.add(buf);
    }

// ---- townBuySword ----
void AppState::townBuySword(){
        if (mode != MODE_TOWN) return;
        Character* taker = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (c.classIndex != rules::CLASS_FIGHTER) continue;
            if (c.weapon.id == items::WPN_LONG_SWORD &&
                c.weapon.plus >= 1) continue;
            taker = &c;
            break;
        }
        if (!taker) {
            log.add("No fighter needs a blade today.");
            return;
        }
        if (party.gold < 500) {
            log.add("The smith wants 500 gp for the enchanted "
                    "blade.");
            return;
        }
        party.gold -= 500;
        taker->weapon.id = items::WPN_LONG_SWORD;
        taker->weapon.plus = 1;
        log.add(taker->name + " buys a +1 long sword.");
    }

// ---- townTrain ----
void AppState::townTrain(){
        if (mode != MODE_TOWN) return;
        if (party.pendingTraining.empty()) {
            log.add("No one is due a level.");
            return;
        }
        // peek at the first valid queued member for the price
        int idx = -1;
        for (int i : party.pendingTraining) {
            if (i >= 0 && i < (int)party.members.size() &&
                party.members[i].hp > 0) { idx = i; break; }
        }
        if (idx < 0) {
            log.add("No one is due a level.");
            return;
        }
        Character& c = party.members[idx];
        int cost = 1500 * (c.level + 1);
        // R44: the keep's masters-at-arms instruct their lord's
        // company at half fees
        if (party.strongholdBuilt) cost /= 2;
        if (party.gold < cost) {
            char buf[96];
            snprintf(buf, sizeof buf,
                     "The training master wants %d gp.", cost);
            log.add(buf);
            return;
        }
        party.gold -= cost;
        int trained = party.trainNext(dice, log);
        if (trained >= 0) {
            char buf[96];
            snprintf(buf, sizeof buf,
                     "Training paid (%d gp).", cost);
            log.add(buf);
            // R34: a trained caster's slot pool may have grown -
            // restore so the new slots are usable
            restoreSlots();
        }
    }

// ---- townBuyChain ----
void AppState::townBuyChain(){
        if (mode != MODE_TOWN) return;
        Character* taker = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (c.classIndex != rules::CLASS_FIGHTER &&
                c.classIndex != rules::CLASS_CLERIC)
                continue;
            if ((int)c.armor.id >=
                (int)items::ARMOR_CHAIN_MAIL)
                continue;   // already chain or better
            taker = &c;
            break;
        }
        if (!taker) {
            log.add("No one needs chain mail today.");
            return;
        }
        if (party.gold < 75) {
            log.add("The armorer wants 75 gp.");
            return;
        }
        party.gold -= 75;
        taker->armor.id = items::ARMOR_CHAIN_MAIL;
        log.add(taker->name + " buys chain mail.");
    }

// ---- townBuyScroll ----
void AppState::townBuyScroll(){
        if (mode != MODE_TOWN) return;
        // gather unknown L1 MU spells
        std::vector<int> unknown;
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)id);
            if (s.sclass != spells::SPELL_MU || s.level != 1)
                continue;
            bool knownByAll = true;
            for (auto& c : party.members)
                if (c.classIndex == 1 && !c.knowsSpell(id))
                    knownByAll = false;
            if (!knownByAll) unknown.push_back(id);
        }
        if (unknown.empty()) {
            log.add("The scribe has no scrolls you need.");
            return;
        }
        Character* taker = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0 || c.classIndex != 1) continue;
            for (int id : unknown) {
                if (!c.knowsSpell(id)) { taker = &c; break; }
            }
            if (taker) break;
        }
        if (!taker) {
            log.add("No magic-user can study the scroll.");
            return;
        }
        if (party.gold < 200) {
            log.add("The scribe wants 200 gp.");
            return;
        }
        party.gold -= 200;
        // pick a spell this taker does not know
        std::vector<int> forHim;
        for (int id : unknown)
            if (!taker->knowsSpell(id)) forHim.push_back(id);
        int pick = forHim.empty()
            ? unknown[0]
            : forHim[(size_t)dice.roll(
                  1, (uint32_t)forHim.size(), 0) - 1];
        taker->knownSpells.push_back(pick);
        const spells::SpellDef& s = spells::spell(
            (spells::SpellId)pick);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "%s copies %s into his spellbook.",
                 taker->name.c_str(), s.name);
        log.add(buf);
    }

// ---- townBuildStronghold ----
void AppState::townBuildStronghold(){
        if (mode != MODE_TOWN) return;
        if (party.strongholdBuilt) {
            log.add("The keep already flies your banner.");
            return;
        }
        int owner = -1;
        for (int i = 0; i < (int)party.members.size(); ++i) {
            const Character& c = party.members[i];
            if (c.hp <= 0) continue;
            if (c.level >=
                rules::CLASS_LEVEL_CAP[c.classIndex]) {
                owner = i;
                break;
            }
        }
        if (owner < 0) {
            log.add("Only a member at name level may hold "
                    "land.");
            return;
        }
        if (party.gold < 10000) {
            log.add("The masons want 10,000 gp for the keep.");
            return;
        }
        party.gold -= 10000;
        party.strongholdBuilt = true;
        party.strongholdOwner = owner;
        log.add(party.members[owner].name +
                " raises a keep - rents will follow.");
    }

// ---- townBuyIdentify ----
void AppState::townBuyIdentify(){
        if (mode != MODE_TOWN) return;
        if (party.gold < 100) {
            log.add("The scribe wants 100 gp for the scroll.");
            return;
        }
        party.gold -= 100;
        ++party.identifyScrolls;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Bought an identify scroll (%d carried, "
                 "%d gp left).",
                 party.identifyScrolls, party.gold);
        log.add(buf);
    }

// ---- useIdentifyScroll ----
void AppState::useIdentifyScroll(){
        if (mode != MODE_TOWN) return;
        if (party.identifyScrolls <= 0) {
            log.add("You carry no identify scroll.");
            return;
        }
        if (party.unidentified.empty()) {
            log.add("Nothing in the pack wants identifying.");
            return;
        }
        Party::PendingItem it = party.unidentified.front();
        party.unidentified.erase(
            party.unidentified.begin());
        --party.identifyScrolls;
        if (it.kind == 0) {
            // magic weapon - the first living fighter (then
            // anyone) whose blade is a lesser enchant
            Character* taker = nullptr;
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                if (c.classIndex != rules::CLASS_FIGHTER)
                    continue;
                if (c.weapon.plus < it.plus) { taker = &c; break; }
            }
            if (!taker) {
                for (auto& c : party.members) {
                    if (c.hp <= 0) continue;
                    if (c.weapon.plus < it.plus) {
                        taker = &c;
                        break;
                    }
                }
            }
            if (taker) {
                taker->weapon.id = items::WPN_LONG_SWORD;
                taker->weapon.plus = it.plus;
                char buf[96];
                snprintf(buf, sizeof buf,
                         "The scroll reveals a long sword +%d! "
                         "%s claims it.",
                         it.plus, taker->name.c_str());
                log.add(buf);
            } else {
                log.add("The scroll reveals a long sword - "
                        "but no one can better his blade. It "
                        "is sold for 200 gp.");
                party.gold += 200;
            }
        } else {
            // enchanted armor - the first living fighter or
            // cleric whose armor is a lesser enchant
            Character* taker = nullptr;
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                if (c.classIndex != rules::CLASS_FIGHTER &&
                    c.classIndex != rules::CLASS_CLERIC)
                    continue;
                if (c.armor.plus < it.plus) { taker = &c; break; }
            }
            if (taker) {
                taker->armor.plus = it.plus;
                char buf[96];
                snprintf(buf, sizeof buf,
                         "The scroll reveals enchanted armor "
                         "(+%d)! %s claims it.",
                         it.plus, taker->name.c_str());
                log.add(buf);
            } else {
                log.add("The scroll reveals enchanted armor - "
                        "but no one can better his mail. It "
                        "is sold for 200 gp.");
                party.gold += 200;
            }
        }
    }

// ---- townHireHenchman ----
void AppState::townHireHenchman(){
        if (mode != MODE_TOWN) return;
        if (party.henchmanPresent) {
            log.add(party.henchmanName +
                    " already rides with the company.");
            return;
        }
        if (party.gold < 100) {
            log.add("The crier wants 100 gp to post the "
                    "offer.");
            return;
        }
        party.gold -= 100;
        int chaAdj = 0;
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            int adj = rules::chaReactionAdj(c.abilities.cha);
            if (adj > chaAdj) chaAdj = adj;
        }
        int interest = 25 + chaAdj;
        int roll = (int)rng.below(100) + 1;
        if (roll > interest) {
            log.add("No one answers the company's offer.");
            return;
        }
        // a level-1 fighter answers (stats averaged for the
        // hire - a simplification vs the book's rolled men)
        static const char* NAMES[] = {
            "Bors", "Gareth", "Hult", "Marda",
            "Oswin", "Pell", "Roderic", "Sela"
        };
        std::string name;
        for (const char* cand : NAMES) {
            bool taken = false;
            for (const auto& c : party.members)
                if (c.name == cand) taken = true;
            if (!taken) { name = cand; break; }
        }
        if (name.empty()) {
            log.add("A sellsword answers, but the company is "
                    "too well known - he declines.");
            return;
        }
        party.henchmanPresent = true;
        party.henchmanName = name;
        party.henchmanLevel = 1;
        party.henchmanMaxHp =
            (int)dice.roll(1, 10, 0) + 1;   // CON-ish adj
        if (party.henchmanMaxHp < 2) party.henchmanMaxHp = 2;
        party.henchmanHp = party.henchmanMaxHp;
        party.henchmanLoyalty = 50 + chaAdj;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "%s the fighter answers the offer! (loyalty "
                 "%d%%)",
                 party.henchmanName.c_str(),
                 party.henchmanLoyalty);
        log.add(buf);
    }

// ---- townSage ----
void AppState::townSage(){
        if (mode != MODE_TOWN) return;
        if (party.gold < 200) {
            log.add("The sage wants 200 gp for his lore.");
            return;
        }
        auto keys = dm::encounterKeys(registry, dungeonLevel);
        if (keys.empty()) {
            log.add("The sage knows nothing of this depth.");
            return;
        }
        party.gold -= 200;
        std::string lore = "The sage speaks of: ";
        int shown = 0;
        for (const auto& k : keys) {
            if (shown >= 8) { lore += "..."; break; }
            if (shown > 0) lore += ", ";
            lore += k;
            ++shown;
        }
        log.add(lore);
        // one bestiary stat line for flavor (a random entry)
        const monsters::MonsterDef* def =
            registry.find(keys[(size_t)rng.below(
                (uint32_t)keys.size())]);
        if (def) {
            char buf[96];
            // R69: the R49 Lua schema carries hitDiceText (the
            // printed "4 + 3" form) and armorClass - the old
            // hd/ac field names no longer exist
            if (!def->hitDiceText.empty())
                snprintf(buf, sizeof buf,
                         "Of %s: HD %s, AC %d, worth %d xp.",
                         def->name.c_str(),
                         def->hitDiceText.c_str(),
                         def->armorClass, def->xpValue);
            else
                snprintf(buf, sizeof buf,
                         "Of %s: HD %d, AC %d, worth %d xp.",
                         def->name.c_str(), def->hitDiceNum,
                         def->armorClass, def->xpValue);
            log.add(buf);
        }
    }

// ---- townSpy ----
void AppState::townSpy(){
        if (mode != MODE_TOWN) return;
        int occupied = 0;
        for (const auto& room : occupancy.rooms)
            if (!room.monsterKey.empty()) ++occupied;
        if (occupied == 0) {
            log.add("The spy reports the level is swept "
                    "clean.");
            return;
        }
        if (party.gold < 500) {
            log.add("The spy wants 500 gp for the mission.");
            return;
        }
        party.gold -= 500;
        std::string report = "The spy reports: ";
        int shown = 0;
        for (const auto& room : occupancy.rooms) {
            if (room.monsterKey.empty()) continue;
            if (shown >= 6) { report += "..."; break; }
            if (shown > 0) report += ", ";
            char tok[48];
            snprintf(tok, sizeof tok, "%s x%d",
                     room.monsterKey.c_str(), room.count);
            report += tok;
            ++shown;
        }
        log.add(report);
    }

// ---- townPeddler ----
void AppState::townPeddler(){
        if (mode != MODE_TOWN) return;
        if (party.gold < 500) {
            log.add("The peddler wants 500 gp for the item.");
            return;
        }
        party.gold -= 500;
        int pick = 1 + (int)rng.below(5);
        switch (pick) {
            case 1: {
                // a +1 weapon for the first living member
                // whose blade is a lesser enchant
                Character* taker = nullptr;
                for (auto& c : party.members) {
                    if (c.hp <= 0) continue;
                    if (c.weapon.plus < 1) { taker = &c; break; }
                }
                if (taker) {
                    taker->weapon.id = items::WPN_LONG_SWORD;
                    taker->weapon.plus = 1;
                    log.add("A long sword +1! " +
                            taker->name + " claims it.");
                } else {
                    addCapped(party.potions, 3, CARRIED_CAP);
                    log.add("The peddler is out of swords - "
                            "three potions instead.");
                }
                break;
            }
            case 2: {
                Character* taker = nullptr;
                for (auto& c : party.members) {
                    if (c.hp <= 0) continue;
                    if (c.classIndex != rules::CLASS_FIGHTER &&
                        c.classIndex != rules::CLASS_CLERIC)
                        continue;
                    if (c.armor.plus < 1) { taker = &c; break; }
                }
                if (taker) {
                    taker->armor.plus = 1;
                    log.add("Enchanted armor (+1)! " +
                            taker->name + " claims it.");
                } else {
                    addCapped(party.potions, 3, CARRIED_CAP);
                    log.add("The peddler is out of armor - "
                            "three potions instead.");
                }
                break;
            }
            case 3:
                addCapped(party.potions, 3, CARRIED_CAP);
                log.add("Three potions of healing, wrapped "
                        "in straw.");
                break;
            case 4:
                party.identifyScrolls += 2;
                log.add("Two identify scrolls, freshly "
                        "inked.");
                break;
            default: {
                // a spell scroll - one random unknown L1 MU
                // spell to the first MU who lacks it (the
                // peddler's stock is identified)
                std::vector<int> cands;
                for (int id = 0; id < spells::SPELL_COUNT;
                     ++id) {
                    const spells::SpellDef& s =
                        spells::spell((spells::SpellId)id);
                    if (s.sclass != spells::SPELL_MU ||
                        s.level != 1)
                        continue;
                    for (auto& c : party.members) {
                        if (c.hp <= 0 || c.classIndex != 1)
                            continue;
                        if (!c.knowsSpell(id)) {
                            cands.push_back(id);
                            break;
                        }
                    }
                }
                if (cands.empty()) {
                    addCapped(party.potions, 3, CARRIED_CAP);
                    log.add("No scrolls your sages can use - "
                            "three potions instead.");
                } else {
                    int sid = cands[(size_t)rng.below(
                        (uint32_t)cands.size())];
                    for (auto& c : party.members) {
                        if (c.hp <= 0 || c.classIndex != 1)
                            continue;
                        if (!c.knowsSpell(sid)) {
                            c.knownSpells.push_back(sid);
                            const spells::SpellDef& s =
                                spells::spell(
                                    (spells::SpellId)sid);
                            char buf[96];
                            snprintf(buf, sizeof buf,
                                     "A scroll of %s! %s "
                                     "copies it into his "
                                     "book.",
                                     s.name, c.name.c_str());
                            log.add(buf);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

// ---- describeRoom ----
void AppState::describeRoom(int roomIndex){
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.flavorSeen) return;
        room.flavorSeen = true;
        const char* line = nullptr;
        if (!room.monsterKey.empty())
            line = "Furs and cracked bones litter the floor - "
                   "something lives here.";
        else if (room.trap == 1)
            line = "The dust lies thick and undisturbed "
                   "here.";
        else if (room.looted)
            line = "Spent torch stubs and old scorch marks - "
                   "someone camped here before you.";
        else if (room.trap == 2)
            line = "Darts jut from the wall at knee height.";
        else
            line = "A cold draft moves through the chamber.";
        log.add(line);
    }

// ---- townTalk ----
void AppState::townTalk(){
        if (mode != MODE_TOWN) return;
        std::vector<std::string> lines;
        if (!party.pendingTraining.empty())
            lines.push_back("The training master asks after "
                            "your company, he says.");
        if (!party.unidentified.empty())
            lines.push_back("A scribe's eye could tell you "
                            "what that odd gear of yours "
                            "truly is.");
        if (party.henchmanPresent)
            lines.push_back(party.henchmanName +
                            " nods from his table by the "
                            "fire.");
        if (party.strongholdBuilt)
            lines.push_back("They say the keep up the road "
                            "pays fair rents.");
        if (party.crewHired)
            lines.push_back("Your coaster's crew drinks at "
                            "the harbor inn, loud as gulls.");
        if (dungeonLevel >= 3)
            lines.push_back("The deep levels? Mad, all of "
                            "it. Mind the flayers, they "
                            "say.");
        else
            lines.push_back("Goblins in the cellar, kobolds "
                            "in the sewers same as ever.");
        if (party.gold >= 10000)
            lines.push_back("Masons would raise you a fine "
                            "keep for that purse of yours.");
        if (party.potions == 0)
            lines.push_back("Dungeon-diving without potions? "
                            "Bold. Or foolish.");
        log.add(lines[(size_t)rng.below(
            (uint32_t)lines.size())]);
    }

// ---- townUpgradeHire ----
void AppState::townUpgradeHire(){
        if (mode != MODE_TOWN) return;
        if (!party.henchmanPresent) {
            log.add("You have no hire to equip.");
            return;
        }
        if (party.henchmanPlate) {
            log.add(party.henchmanName +
                    " already wears plate.");
            return;
        }
        if (party.henchmanPurse < 100) {
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%s's purse holds only %d gp - the "
                     "armorers want 100.",
                     party.henchmanName.c_str(),
                     party.henchmanPurse);
            log.add(buf);
            return;
        }
        party.henchmanPurse -= 100;
        party.henchmanPlate = true;
        log.add(party.henchmanName +
                " buys plate from his own purse!");
    }

// ---- townHireCrew ----
void AppState::townHireCrew(){
        if (mode != MODE_TOWN) return;
        if (party.crewHired) {
            log.add("The coaster's company already sails "
                    "with you.");
            return;
        }
        if (party.gold < 200) {
            log.add("The harbormaster wants 200 gp to sign "
                    "a crew.");
            return;
        }
        party.gold -= 200;
        party.crewHired = true;
        log.add("A coaster's company of twenty signs on. "
                "They will ferry your takings to market.");
    }

// ---- arriveTown ----
void AppState::arriveTown(){
        mode = MODE_TOWN;
        billTownVisit();
        if (mode == MODE_OVERLAND) checkArrivedHome();
        if (mode == MODE_SEA) checkArrivedSea();   // R70
    }

// ---- R85: equip the best of the pack ----
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
        // R86: the hire's pack goes under the same hammer - he
        // carried it for the company, the gold is company gold
        if (!party.henchmanPack.empty()) {
            std::vector<PackItem> keep;
            for (const auto& p : party.henchmanPack) {
                if (p.gp > 0) {
                    party.gold += p.gp;
                    total += p.gp;
                    ++sold;
                    snprintf(buf, sizeof buf,
                             "%s sells the %s for %d gp.",
                             party.henchmanName.c_str(),
                             packItemName(p).c_str(), p.gp);
                    log.add(buf);
                } else {
                    keep.push_back(p);
                    ++kept;
                }
            }
            party.henchmanPack = keep;
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

// ---- R82: raise a dead member ----
void AppState::townRaiseDead(){
        if (mode != MODE_TOWN) return;
        // the rite needs a living 7th+ level cleric
        const Character* cleric = nullptr;
        for (const auto& c : party.members) {
            if (canRaiseDead(c)) { cleric = &c; break; }
        }
        if (!cleric) {
            log.add("No cleric of 7th level or better is "
                    "able to raise the dead.");
            return;
        }
        // the first dead member (hp 0 in the roster)
        Character* dead = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) { dead = &c; break; }
        }
        if (!dead) {
            log.add("No member of the company is dead.");
            return;
        }
        if (party.gold < 1000) {
            log.add("The temple demands a 1,000 gp offering "
                    "for the rite.");
            return;
        }
        party.gold -= 1000;
        char buf[96];
        int survival = rules::conResSurvival(dead->abilities.con);
        if ((int)dice.roll(1, 100, 0) <= survival) {
            dead->hp = 1;
            snprintf(buf, sizeof buf,
                     "%s returns to life at %s's word!",
                     dead->name.c_str(), cleric->name.c_str());
            log.add(buf);
        } else {
            snprintf(buf, sizeof buf,
                     "%s's spirit cannot return; the offering "
                     "is spent.",
                     dead->name.c_str());
            log.add(buf);
        }
    }

// ---- R81: study the carried scrolls ----
void AppState::townStudyScrolls(){
        if (mode != MODE_TOWN) return;
        if (party.scrolls <= 0) {
            log.add("You carry no scrolls to study.");
            return;
        }
        int studied = 0, learned = 0;
        char buf[96];
        while (party.scrolls > 0) {
            // the scroll goes to the first living MU with an
            // unknown spell (III.B scrolls are MU spell scrolls;
            // clerics pray, they do not study - PHB convention)
            Character* taker = nullptr;
            int sid = -1;
            for (auto& c : party.members) {
                if (c.hp <= 0 || c.classIndex != 1) continue;
                int pick = pickStudySpell(c);
                if (pick >= 0) { taker = &c; sid = pick; break; }
            }
            if (!taker) break;   // every book is complete
            --party.scrolls;
            ++studied;
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)sid);
            if (spells::rollChanceToLearn(dice,
                    taker->abilities.int_)) {
                taker->knownSpells.push_back(sid);
                snprintf(buf, sizeof buf,
                         "%s masters %s from a scroll!",
                         taker->name.c_str(), s.name);
                log.add(buf);
                ++learned;
            } else {
                snprintf(buf, sizeof buf,
                         "%s fails to master %s; the scroll "
                         "crumbles.",
                         taker->name.c_str(), s.name);
                log.add(buf);
            }
        }
        snprintf(buf, sizeof buf,
                 "Studied %d scroll%s; %d spell%s learned.",
                 studied, studied == 1 ? "" : "s",
                 learned, learned == 1 ? "" : "s");
        log.add(buf);
    }
