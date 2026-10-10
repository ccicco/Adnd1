#include "appstate.h"
#include "abilities/abilities.h"   // R120: listening (p.60)
#include "rules/thieffunc.h"   // R301: the thief trap rolls
#include "rules/locktime.h"   // R304: the lock time draw
#include "rules/doorforce.h"  // R305: the door force folds
#include "rules/swimcross.h"  // R312: the flooded crossing
#include "rules/underwater.h"  // R311: the drown percent

// ---- restExplore ----
void AppState::restExplore(){
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;

        log.add("The party makes camp...");
        // R90: the interrupted camp still burns watch turns
        turnCount += restTurns(true);
        if (dm::wanderCheck(dice, wander)) {
            log.add("The rest is interrupted!");
            // R94: the frightened watch costs him nerve
            if (party.henchmanPresent && party.henchmanHp > 0)
                party.henchmanLoyalty = loyaltyDrift(
                    party.henchmanLoyalty,
                    loyaltyDriftHardWatch());
            spawnWanderingEncounter();
            return;
        }

        // R119: the completed rest pays the forced-rest
        // debt (DMG p.38); interrupted camps restore
        // nothing, fatigue included (slots precedent)
        turnsSinceRest = 0;
        restOwed = false;
        mustRest = false;
        restoreSlots();
        // R38: a completed rest renews arrows too - fletching and
        // recovery time (interrupted rests restore nothing, as
        // with slots)
        restockAmmo();
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;   // the dead do not heal
            int heal = c.level;
            if (c.hp + heal > c.maxHp) heal = c.maxHp - c.hp;
            if (heal > 0) c.hp += heal;
        }
        // R90: a completed camp costs 48 turns (8 hours) -
        // the clock finally sees sleep (rest is pace-free)
        turnCount += restTurns(false);
        log.add("The company rests. Spells and wounds mend.");
    }

// ---- tickActivity ----
// R119: forced-rest bookkeeping (DMG p.38): every
// active turn counts toward the one-in-six rest;
// the sixth is owed and the gate closes until a
// completed camp pays it.
void AppState::tickActivity(int turns){
        if (turns <= 0) return;
        turnsSinceRest += turns;
        if (forcedRestDue(turnsSinceRest)) {
            if (!mustRest)
                log.add("The company is worn - a rest is due. [R]");
            mustRest = true;
        }
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
        // R142: the sample dungeon - the DMG's own keyed
        // delve (pp.94-96). The book keys its rooms
        // exactly, so the generated dressing (dart traps,
        // Appendix H curiosities, random lairs) stands down
        // for the whole delve; the entry chamber lairs the
        // book's large spider (the nine young of 1 hp are
        // flavor - one adult is the convention, the book
        // gives no fight mechanics for the brood).
        if (seed == dm::sampledungeon::kSampleSeed) {
            for (auto& room : occupancy.rooms) {
                room.monsterKey.clear();
                room.count = 0;
                room.looted = false;
                room.trap = 0;
                room.trapKind = -1;
                room.trickFeature = -1;
                room.trickAttribute = -1;
                room.trickDone = false;
                room.flavorSeen = false;
                room.parleyed = false;
                room.headsLo = room.headsHi = 0;
                room.ageLo = room.ageHi = 0;
            }
            if (!occupancy.rooms.empty()) {
                occupancy.rooms[0].monsterKey = "large_spider";
                occupancy.rooms[0].count = 1;
            }
            // R143: the crypt wing lairs per the book's own
            // crypt-column area hints - area 24 ghouls,
            // area 27 skeletons, areas 35-37 the cleric's
            // hobgoblins (lair counts are the convention;
            // the book keys no crypt rooms)
            if (occupancy.rooms.size() >= 6) {
                occupancy.rooms[3].monsterKey = "ghoul";
                occupancy.rooms[3].count = 2;
                occupancy.rooms[4].monsterKey = "skeleton";
                occupancy.rooms[4].count = 4;
                occupancy.rooms[5].monsterKey = "hobgoblin";
                occupancy.rooms[5].count = 2;
            }
            return;
        }
        // R52: lairs roll from the DMG Appendix C tables -
        // the Determination Matrix for this depth, then the
        // Monster Level Table row (count, hydra heads, dragon
        // hp/die brackets). The R42 depth cap still bounds lair
        // size.
        for (auto& room : occupancy.rooms) {
            room.monsterKey.clear();
            room.count = 0;
            room.looted = false;
            room.trap = 0;
            room.trapKind = -1;   // R125: re-rolled at arming
            room.trickFeature = -1;   // R128: re-rolled below
            room.trickAttribute = -1;
            room.trickDone = false;
            room.flavorSeen = false;   // R46
            room.headsLo = room.headsHi = 0;
            room.ageLo = room.ageHi = 0;
            if (rng.below(100) >= 50) {
                // R45: an unoccupied room may hide a dart trap
                if (rng.below(100) < 15) {
                    room.trap = 1;   // R45 dart set
                    // R125: Appendix G names the snare (d%);
                    // the book lists names only, so the R45
                    // save/2d6 mechanics stay the effect
                    room.trapKind = (int)dm::appendixg::trapFor(
                        1 + (int)rng.below(100));
                } else if (rng.below(100) < 20) {
                    // R128: Appendix H special rooms - an
                    // unoccupied, untrapped room may hold a
                    // curiosity (20%, the design figure: the
                    // book's H lists are selection lists, not
                    // frequency tables, so no printed weights
                    // exist - the odds ride the design debt).
                    // Uniform picks, the book gives no weights;
                    // a room is a snare OR a curiosity, never
                    // both (documented).
                    room.trickFeature = (int)rng.below(
                        (uint32_t)dm::appendixh::
                        TRICK_FEATURE_COUNT);
                    room.trickAttribute = (int)rng.below(
                        (uint32_t)dm::appendixh::
                        TRICK_ATTRIBUTE_COUNT);
                    room.trickDone = false;
                }
                continue;
            }
            dm::DungeonEncounter e = rollDmEncounter();
            if (e.isParty) {
                // R53: NPC parties wander the halls - they do
                // not lair; the room stays unoccupied (trap chance)
                if (rng.below(100) < 15) {
                    room.trap = 1;   // R45 dart set
                    // R125: Appendix G names the snare (d%);
                    // the book lists names only, so the R45
                    // save/2d6 mechanics stay the effect
                    room.trapKind = (int)dm::appendixg::trapFor(
                        1 + (int)rng.below(100));
                }
                continue;
            }
            if (e.key.empty() || e.count <= 0) {
                // NO ENCOUNTER (or an R53 row re-rolled out):
                // the room stays unoccupied (trap chance as above)
                if (rng.below(100) < 15) {
                    room.trap = 1;   // R45 dart set
                    // R125: Appendix G names the snare (d%);
                    // the book lists names only, so the R45
                    // save/2d6 mechanics stay the effect
                    room.trapKind = (int)dm::appendixg::trapFor(
                        1 + (int)rng.below(100));
                }
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
// R301: the printed thief rolls - the R298
// find/remove traps chances decide the
// disarm (two percentile draws at or below
// the adjusted chance; locate first, remove
// second, one try each). The strike (save
// vs death, 2d6) stays the R45 effect.
void AppState::springTrap(int roomIndex){
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.trap != 1) return;

        for (const auto& c : party.members) {
            if (c.hp <= 0 || c.classIndex != 3) continue;
            // R301: the printed find roll - percentile
            // dice at or below the adjusted find/remove
            // traps chance (the R298 tables; the draw
            // runs in tenths, rules/thieffunc.h)
            int find = (int)rng.below(1000);
            if (!rules::thfAttemptSucceeds(find,
                    rules::THF_TRAPS, c.level,
                    c.race, (int)c.abilities.dex))
                break;   // one thief attempt per trap
            // the printed remove roll: separate, one try
            int remove = (int)rng.below(1000);
            if (rules::thfAttemptSucceeds(remove,
                    rules::THF_TRAPS, c.level,
                    c.race, (int)c.abilities.dex)) {
                room.trap = 2;
                // R125: the book's name for the snare
                log.add(c.name + " spots the trap (" +
                        dm::appendixg::trapName(room.trapKind) +
                        ") and disarms it.");
                return;
            }
            // located but not removed - it fires anyway
            log.add(c.name + " spots the trap (" +
                    dm::appendixg::trapName(room.trapKind) +
                    ") - too late to disarm it!");
            break;   // one try each, the print
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
                     "A trap! %s - %s saved!",
                     dm::appendixg::trapName(room.trapKind),
                     c.name.c_str());
            log.add(buf);
            return;
        }
        int dmg = (int)dice.roll(2, 6, 0);
        c.hp -= dmg;
        char buf[128];   // R125: room for the book's long names
        if (c.hp <= 0) {
            c.hp = 0;
            snprintf(buf, sizeof buf,
                     "A trap! %s strikes %s for %d - %s "
                     "falls!",
                     dm::appendixg::trapName(room.trapKind),
                     c.name.c_str(), dmg, c.name.c_str());
        } else {
            snprintf(buf, sizeof buf,
                     "A trap! %s strikes %s for %d.",
                     dm::appendixg::trapName(room.trapKind),
                     c.name.c_str(), dmg);
        }
        log.add(buf);

        // R306: the pit haul - the first living
        // thief climbs down the wall (the PHB
        // print: climbing assumes a coarse
        // surface with ledges and cracks). A
        // clean climb costs nothing; a missed
        // climb still hauls the victim out but
        // spends the turn (the work draws the
        // wander check, the bump convention)
        if (dm::appendixg::trapIsPit(room.trapKind)) {
            const Character* climber = nullptr;
            for (const auto& t : party.members) {
                if (t.hp <= 0 || t.classIndex != 3)
                    continue;
                climber = &t;
                break;
            }
            if (climber != nullptr) {
                int climb = (int)rng.below(1000);
                char pbuf[128];
                if (rules::thfAttemptSucceeds(climb,
                        rules::THF_CLIMB_WALLS,
                        climber->level, climber->race,
                        (int)climber->abilities.dex)) {
                    snprintf(pbuf, sizeof pbuf,
                             "%s climbs down the pit "
                             "wall and hauls %s out.",
                             climber->name.c_str(),
                             c.name.c_str());
                    log.add(pbuf);
                } else {
                    ++turnCount;
                    tickActivity(1);   // R119: the haul
                    snprintf(pbuf, sizeof pbuf,
                             "%s ropes %s out - the "
                             "haul costs a turn.",
                             climber->name.c_str(),
                             c.name.c_str());
                    log.add(pbuf);
                    // the spent turn draws a wanderer
                    if (dm::wanderCheck(dice, wander))
                        spawnWanderingEncounter();
                }
            }
        }
        if (!party.alive()) {
            log.add("GAME OVER - press N to roll a new party.");
        }
    }

// ---- checkTrapOnEntry ----
// R301: the movement wire - the R45 springTrap
// built the snare but nothing called it. The
// shell step handler calls this on every step;
// an armed trap in the chamber the company
// stands in springs. The mode gate and the
// location read live here so the battery can
// drive the whole path.
void AppState::checkTrapOnEntry(){
        if (mode != MODE_EXPLORE) return;
        int tr = trapRoomNear(party.x, party.y);
        if (tr < 0) return;
        springTrap(tr);
    }

// ---- engageTrick ----
// R137: the deliberate-engage hook - the company chooses
// (the X key in the dungeon) to engage the current
// room's curiosity; the first sight no longer springs
// it (describeRoom only announces and prompts).
void AppState::engageTrick(){
        if (!party.alive()) return;
        int roomIndex = roomAt(party.x, party.y);
        if (roomIndex < 0) {
            log.add("There is nothing here to engage - "
                    "step inside a room first.");
            return;
        }
        RoomOccupant& room = occupancy.rooms[roomIndex];
        // R143: the seventh knob - in the book's own sample
        // dungeon, the ceremonial dome's seventh stone knob
        // opens the south crypt door. The X key turns it
        // (a second turn only says the door stands open).
        if (seed == dm::sampledungeon::kSampleSeed &&
            roomIndex == 2) {
            if (dm::sampledungeon::cryptDoorOpen(map)) {
                log.add("The crypt door already stands "
                        "open to the south.");
            } else {
                dm::sampledungeon::openCryptDoor(map);
                log.add("The SEVENTH KNOB turns - stone "
                        "grinds, and a door swings open "
                        "to the south. The Secret Crypts "
                        "lie beyond.");
            }
            return;
        }
        if (room.trickFeature < 0 ||
            !room.monsterKey.empty() || room.trickDone) {
            log.add("Nothing here begs engaging.");
            return;
        }
        // R138: the talk-flavor parley - a talking
        // feature answers the X key with its line
        // (repeatable; talk never spends the trick).
        if (dm::appendixh::trickIsTalky(
                room.trickAttribute)) {
            log.add(dm::appendixh::trickTalkLine(
                room.trickAttribute));
            return;
        }
        if (!dm::appendixh::trickIsMechanical(
                room.trickAttribute)) {
            log.add("The feature only mutters - it "
                    "ignores the company.");
            return;
        }
        room.trickDone = true;
        applyTrick(roomIndex);
}

// ---- applyTrick ----
void AppState::applyTrick(int roomIndex){
        // R128: the special room's mechanical effect - the
        // first-effects slice. Releases coins/gems/magic item
        // pay out (the R56 strip convention: delveGold rides,
        // no xp - an unguarded dressing find is not a hoard);
        // shoots/poison strike a random living member with
        // the trap shape (save vs death/poison or 2d6).
        // R132: the second-effects slice - ages (10 years),
        // flesh to stone (save vs petrification),
        // electrical shock (5-50 hp, no save printed),
        // releases counterfeit (worthless), takes/steals
        // (10-60 gp). R133: the third-effects slice -
        // attacks (animated strike, 1d8), fruit (heals
        // 2d4+2, the potion shape), greed (10% of the
        // purse), teleports (intra-level, a random room
        // center), collapsing (save or 2d6, everyone).
        // R134: the deep slice - wish (a boon table:
        // heal all, restore one, or gold), gravity
        // greater (1d6 crush, everyone, no save),
        // polymorph (save or 3d4 reshape). R135: the
        // room-geometry slice - one-way (the way
        // seals), pivots/spinning (the room turns),
        // shifting (the walls flex), sliding (the
        // floor tilts). R136: the odds-and-ends slice
        // - rising (the flood), suspends (the float),
        // appearing (the melt-away), invisible (the
        // unseen strike), gaseous (the gas cloud).
        // R139: the engine-deep change-family slice -
        // change align (save or WIS and CHA drop),
        // change attribute (save or two abilities
        // swap), change class (save or training
        // unravels), change minds (save or INT drops),
        // change sex (save or CHA drops), distorted
        // WL (1d6, the bent weapon), distorted HD
        // (save or max hp drops), resisting general
        // (the company is repelled), resisting
        // specific (repelled, and the trick is not
        // spent), geases (save or WIS drops),
        // disintegrates (save or gone). R140: the
        // final sweep - animated (the company is
        // buffeted, 1d4 each), combination (a 1d6
        // strike and a repulse), enlarges (save or
        // STR up DEX down), false (the trick is
        // spent, nothing happens), gravity lesser
        // (a bob and drop, 1d4), gravity nil (the
        // company floats to the room's center),
        // gravity varying (save or 1d6, everyone),
        // moves (carried to a random tile), randomly-
        // acts (a d3: strike, gift, or still), sloping
        // (the low edge takes the company), symbiotic
        // (save or CON drops), wish reversal (the
        // inverted boon: harm, aging, or the purse
        // bleeds).
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.trickFeature < 0) return;
        const std::string name = dm::appendixh::trickSummary(
            room.trickFeature, room.trickAttribute);
        int a = room.trickAttribute;
        // R132: the second-slice victim pick (the same
        // random-living-member selection the trap shape
        // uses, hoisted for the new branches)
        auto victimIndex = [&]() -> int {
            int victims[PARTY_MAX];
            int nv = 0;
            for (int i = 0; i < (int)party.members.size(); ++i)
                if (party.members[i].hp > 0)
                    victims[nv++] = i;
            if (nv == 0) return -1;
            return victims[(size_t)rng.below((uint32_t)nv)];
        };
        if (a == dm::appendixh::TA_REL_COINS) {
            int gp = (int)dice.roll(2, 6, 0) * 10 * dungeonLevel;
            party.gold += gp;
            party.delveGold += gp;   // R45: the take
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s releases %d gp - yours.",
                     name.c_str(), gp);
            log.add(buf);
        } else if (a == dm::appendixh::TA_REL_GEMS) {
            int gems = (int)dice.roll(1, 3, 0);
            long long worth = 0;
            for (int i = 0; i < gems; ++i)
                worth += dm::treasure::rollGemValue(dice);
            party.gold += (int)worth;
            party.delveGold += (int)worth;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s releases %d gems, worth %lld gp.",
                     name.c_str(), gems, worth);
            log.add(buf);
        } else if (a == dm::appendixh::TA_REL_MAGIC_ITEM) {
            // the R44 unidentified-pickup shape
            Party::PendingItem it;
            it.kind = (int)rng.below(2);
            it.plus = 1 + (rng.below(100) < 10 ? 1 : 0);
            party.unidentified.push_back(it);
            log.add("The " + name + " yields an unidentified "
                    "magic item - a scribe's scroll would "
                    "serve.");
        } else if (a == dm::appendixh::TA_AGES) {
            // R132: the print's altar example - age the
            // character 10 years (the R115 shape)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            applyMagicalAging(c, party.careerDays, 10);
            log.add("The " + name + " ages " + c.name +
                    " 10 years!");
        } else if (a == dm::appendixh::TA_FLESH_TO_STONE) {
            // R132: the print's face example - save versus
            // magic or be transformed; the petrification
            // save category, stone on failure
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_PETRIFY_POLY);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " glooms - " +
                        c.name + " saved!");
                return;
            }
            c.hp = 0;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s turns %s to stone - %s falls!",
                     name.c_str(), c.name.c_str(),
                     c.name.c_str());
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_SHOCK_METAL ||
                   a == dm::appendixh::TA_SHOCK_MAGIC) {
            // R132: the print's pedestal example - a
            // magical shock for 5-50 hit points (no save
            // printed)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(5, 10, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s shocks %s for %d - %s falls!",
                         name.c_str(), c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s shocks %s for %d.",
                         name.c_str(), c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_REL_COUNTERFEIT) {
            // R132: releases counterfeit - the shower crumbles
            // worthless (nothing gained)
            log.add("The " + name + " releases a shower of "
                    "coins - counterfeit, crumbling to dust.");
        } else if (a == dm::appendixh::TA_TAKES) {
            // R132: takes/steals - 10-60 gp from the purse
            // (the print gives no figure; a rebuild
            // convention)
            int gp = (int)dice.roll(1, 6, 0) * 10;
            if (party.gold >= gp) {
                party.gold -= gp;
            } else {
                gp = party.gold;
                party.gold = 0;
            }
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s steals %d gp and is gone.",
                     name.c_str(), gp);
            log.add(buf);
        } else if (a == dm::appendixh::TA_ATTACKS) {
            // R133: the animated feature strikes - 1d8,
            // no save (the print gives no figure; the
            // unarmed-strike convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(1, 8, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s strikes %s for %d - %s falls!",
                         name.c_str(), c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s strikes %s for %d.",
                         name.c_str(), c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_FRUIT) {
            // R133: wholesome fruit - a random living
            // member eats and heals 2d4+2, the potion
            // shape, capped at max hp (the print gives no
            // figure; convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int heal = (int)dice.roll(2, 4, 2);
            int before = c.hp;
            c.hp += heal;
            if (c.hp > c.maxHp) c.hp = c.maxHp;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s offers fruit - %s eats and "
                     "heals %d (now %d/%d).",
                     name.c_str(), c.name.c_str(),
                     c.hp - before, c.hp, c.maxHp);
            log.add(buf);
        } else if (a == dm::appendixh::TA_GREED) {
            // R133: the greed aura - a scramble costs 10%
            // of the purse (the print gives no figure;
            // convention)
            int lost = party.gold / 10;
            if (lost > 0) {
                party.gold -= lost;
                char buf[160];
                snprintf(buf, sizeof buf,
                         "The %s glitters - the company "
                         "scrambles and drops %d gp!",
                         name.c_str(), lost);
                log.add(buf);
            } else {
                log.add("The " + name + " glitters - but "
                        "the purse is empty.");
            }
        } else if (a == dm::appendixh::TA_TELEPORTS) {
            // R133: the print's intra-level AREA example -
            // the company is relocated to a random room
            // center on this level
            if (dungeon.rooms.empty()) return;
            int ri = (int)rng.below(
                (uint32_t)dungeon.rooms.size());
            const dm::GeneratedRoom& r = dungeon.rooms[ri];
            party.x = r.x + r.w / 2;
            party.y = r.y + r.h / 2;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s flares - the company blinks "
                     "across the level!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_COLLAPSING) {
            // R133: the ceiling comes down - every living
            // member saves vs death/poison or takes 2d6
            // (the print gives no figure; the trap shape)
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s groans - the ceiling comes "
                     "down!", name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int target = rules::saveTarget(
                    c.classIndex, c.level,
                    rules::SAVE_DEATH_POISON);
                if (rules::attemptSave(dice, target, 0)) {
                    char b2[160];
                    snprintf(b2, sizeof b2,
                             "%s dives clear.", c.name.c_str());
                    log.add(b2);
                    continue;
                }
                int dmg = (int)dice.roll(2, 6, 0);
                c.hp -= dmg;
                char b2[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(b2, sizeof b2,
                             "Rubble buries %s for %d - "
                             "%s falls!",
                             c.name.c_str(), dmg,
                             c.name.c_str());
                } else {
                    snprintf(b2, sizeof b2,
                             "Rubble bruises %s for %d.",
                             c.name.c_str(), dmg);
                }
                log.add(b2);
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_WISH) {
            // R134: the wish-granting echo - a boon table
            // roll (the print gives no table; the rebuild
            // keeps it benevolent)
            int boon = (int)dice.roll(1, 3, 0);
            char buf[192];
            if (boon == 1) {
                for (auto& c : party.members) {
                    if (c.hp > 0) c.hp = c.maxHp;
                }
                snprintf(buf, sizeof buf,
                         "The %s hums - the company's wounds "
                         "close! A wish spent well.",
                         name.c_str());
            } else if (boon == 2) {
                int vi = victimIndex();
                if (vi >= 0) {
                    party.members[vi].hp =
                        party.members[vi].maxHp;
                    snprintf(buf, sizeof buf,
                             "The %s hums - %s is restored!",
                             name.c_str(),
                             party.members[vi].name.c_str());
                } else {
                    snprintf(buf, sizeof buf,
                             "The %s hums - the echo fades.",
                             name.c_str());
                }
            } else {
                int gp = (int)dice.roll(1, 6, 0) * 100;
                party.gold += gp;
                snprintf(buf, sizeof buf,
                         "The %s hums - a shower of %d gp!",
                         name.c_str(), gp);
            }
            log.add(buf);
        } else if (a == dm::appendixh::TA_GRAVITY_GREATER) {
            // R134: the pull doubles - every living member
            // takes 1d6 crushing, no save (the print gives
            // no figure; the convention)
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s drags - the weight doubles!",
                     name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char b2[160];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(b2, sizeof b2,
                             "The crush fells %s (%d)!",
                             c.name.c_str(), dmg);
                } else {
                    snprintf(b2, sizeof b2,
                             "The crush bruises %s for %d.",
                             c.name.c_str(), dmg);
                }
                log.add(b2);
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_POLYMORPH) {
            // R134: the reshaping radiance - a random living
            // member saves vs petrification/polymorph or
            // takes 3d4 reshaping damage (the print gives
            // no figure; the convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_PETRIFY_POLY);
            char buf[192];
            if (rules::attemptSave(dice, target, 0)) {
                snprintf(buf, sizeof buf,
                         "The %s radiates - %s keeps their "
                         "shape.",
                         name.c_str(), c.name.c_str());
            } else {
                int dmg = (int)dice.roll(3, 4, 0);
                c.hp -= dmg;
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(buf, sizeof buf,
                             "The %s reshapes %s - torn "
                             "apart (%d)!",
                             name.c_str(), c.name.c_str(),
                             dmg);
                } else {
                    snprintf(buf, sizeof buf,
                             "The %s reshapes %s for %d - "
                             "they wobble back, changed.",
                             name.c_str(), c.name.c_str(),
                             dmg);
                }
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_RISING) {
            // R136: the water rises - every living
            // member saves vs death/poison or takes 1d6
            // (the print gives no figure; the trap
            // shape)
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s gurgles - water rises fast!",
                     name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int target = rules::saveTarget(
                    c.classIndex, c.level,
                    rules::SAVE_DEATH_POISON);
                if (rules::attemptSave(dice, target, 0)) {
                    char b2[160];
                    snprintf(b2, sizeof b2,
                             "%s keeps their footing.",
                             c.name.c_str());
                    log.add(b2);
                    continue;
                }
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char b2[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(b2, sizeof b2,
                             "The flood drowns %s (%d) - "
                             "%s falls!",
                             c.name.c_str(), dmg,
                             c.name.c_str());
                } else {
                    snprintf(b2, sizeof b2,
                             "The flood batters %s for %d.",
                             c.name.c_str(), dmg);
                }
                log.add(b2);
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_SUSPENDS) {
            // R136: gravity nil - the company floats up
            // and drifts to a random interior tile (the
            // print gives no mechanics; a convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            party.x = gr.x +
                (int)rng.below((uint32_t)gr.w);
            party.y = gr.y +
                (int)rng.below((uint32_t)gr.h);
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s hums - the company floats!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_CHANGE_ALIGN) {
            // R139: alignments are not modeled - the
            // convention: save vs spells or the
            // victim's convictions waver (WIS and CHA
            // each drop 1, floored at 3)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " hums - " +
                        c.name + " stands firm.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_WIS) > 3)
                c.abilities.set(rules::ABILITY_WIS,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_WIS) - 1));
            if (c.abilities.get(rules::ABILITY_CHA) > 3)
                c.abilities.set(rules::ABILITY_CHA,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_CHA) - 1));
            log.add("The " + name + " remakes " + c.name +
                    " - their convictions waver!");
        } else if (a ==
                   dm::appendixh::TA_CHANGE_ATTRIBUTE) {
            // R139: save vs spells or two of the victim's
            // abilities trade places (convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " flickers - " +
                        c.name + " is unchanged.");
                return;
            }
            int a1 = (int)rng.below((uint32_t)
                rules::ABILITY_COUNT);
            int a2 = (int)rng.below((uint32_t)
                (rules::ABILITY_COUNT - 1));
            if (a2 >= a1) ++a2;
            uint8_t tmp = c.abilities.get(
                (rules::Ability)a1);
            c.abilities.set((rules::Ability)a1,
                c.abilities.get((rules::Ability)a2));
            c.abilities.set((rules::Ability)a2, tmp);
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s scrambles %s - %s and %s trade!",
                     name.c_str(), c.name.c_str(),
                     rules::abilityName((rules::Ability)a1),
                     rules::abilityName((rules::Ability)a2));
            log.add(buf);
        } else if (a == dm::appendixh::TA_CHANGE_CLASS) {
            // R139: no class-change engine - convention:
            // save vs spells or the victim's training
            // unravels (xp resets to the level's start)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " gestures - " +
                        c.name + " keeps their trade.");
                return;
            }
            // R231: the subclass drain reads the registry
            // ladder (the level start)
            c.xp = c.subclass >= 0
                ? rules::subclassXpToAttain(c.subclass,
                                            c.level)
                : rules::xpForLevel(c.classIndex,
                                    c.level);
            log.add("The " + name + " remakes " + c.name +
                    " - their training unravels!");
        } else if (a == dm::appendixh::TA_CHANGE_MINDS) {
            // R139: save vs spells or the victim's
            // thoughts scramble (INT drops 1, floored
            // at 3 - convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " whispers - " +
                        c.name + " keeps their wits.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_INT) > 3)
                c.abilities.set(rules::ABILITY_INT,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_INT) - 1));
            log.add("The " + name + " scrambles " +
                    c.name + "'s thoughts!");
        } else if (a == dm::appendixh::TA_CHANGE_SEX) {
            // R139: sex is not modeled - convention:
            // save vs petrification (the transformation
            // category) or the semblance is remade and
            // CHA drops 1, floored at 3
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_PETRIFY_POLY);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " shimmers - " +
                        c.name + " is untouched.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_CHA) > 3)
                c.abilities.set(rules::ABILITY_CHA,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_CHA) - 1));
            log.add("The " + name + " remakes " + c.name +
                    "'s semblance!");
        } else if (a == dm::appendixh::TA_DISTORTED_WL) {
            // R139: distorted weapon lengths - the bent
            // space turns the victim's own blow on them
            // (1d6, no save - the unseen-strike shape)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(1, 6, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s bends %s's weapon awry - "
                         "%d! %s falls!",
                         name.c_str(), c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s bends %s's weapon awry - %d.",
                         name.c_str(), c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_DISTORTED_HD) {
            // R139: distorted hit dice - the victim's
            // vitality is squeezed (save vs death/poison
            // or max hp drops 1d6, floored at 1)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_DEATH_POISON);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " warps - " +
                        c.name + " keeps their vigor.");
                return;
            }
            int loss = (int)dice.roll(1, 6, 0);
            if (c.maxHp - loss < 1) loss = c.maxHp - 1;
            c.maxHp -= loss;
            if (c.hp > c.maxHp) c.hp = c.maxHp;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s squeezes %s - %d vitality!",
                     name.c_str(), c.name.c_str(), loss);
            log.add(buf);
        } else if (a ==
                   dm::appendixh::TA_RESISTING_GENERAL) {
            // R139: the feature resists - it repels the
            // whole company to a random edge tile (the
            // R135 sliding shape; convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            int side = (int)rng.below((uint32_t)4);
            int nx = 0, ny = 0;
            if (side == 0) {
                nx = gr.x;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 1) {
                nx = gr.x + gr.w - 1;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 2) {
                ny = gr.y;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            } else {
                ny = gr.y + gr.h - 1;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            }
            party.x = nx;
            party.y = ny;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s resists - the company is "
                     "repelled!", name.c_str());
            log.add(buf);
        } else if (a ==
                   dm::appendixh::TA_RESISTING_SPECIFIC) {
            // R139: resisting one specific thing - the
            // company is repelled AND the trick is not
            // spent (trickDone unwound - convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            int side = (int)rng.below((uint32_t)4);
            int nx = 0, ny = 0;
            if (side == 0) {
                nx = gr.x;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 1) {
                nx = gr.x + gr.w - 1;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 2) {
                ny = gr.y;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            } else {
                ny = gr.y + gr.h - 1;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            }
            party.x = nx;
            party.y = ny;
            room.trickDone = false;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s shrugs the attempt off - the "
                     "company is repelled!", name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_GEASES) {
            // R139: a quest compulsion - no quest engine,
            // so the convention: save vs spells or a
            // geas settles and WIS drops 1 (floored at 3)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " murmurs - " +
                        c.name + " resists the geas.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_WIS) > 3)
                c.abilities.set(rules::ABILITY_WIS,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_WIS) - 1));
            log.add("A geas settles over " + c.name +
                    " - a duty unspoken rides them!");
        } else if (a == dm::appendixh::TA_DISINTEGRATES) {
            // R139: the hardest bite - save vs spells or
            // the victim is gone (the flesh-to-stone
            // shape, disintegrated instead)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " crackles - " +
                        c.name + " holds fast!");
                return;
            }
            c.hp = 0;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s unmakes %s - only dust "
                     "settles!", name.c_str(),
                     c.name.c_str());
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_ANIMATED) {
            // R140: the furnishings animate and buffet
            // the whole company (1d4 each, no save)
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s animates - the furnishings "
                     "buffet the company!", name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                c.hp -= (int)dice.roll(1, 4, 0);
                if (c.hp <= 0) c.hp = 0;
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_COMBINATION) {
            // R140: the trick does double duty - a strike
            // AND a repulse (convention)
            int vi = victimIndex();
            if (vi >= 0) {
                Character& c = party.members[vi];
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char buf[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(buf, sizeof buf,
                             "The %s strikes %s for %d - "
                             "%s falls!",
                             name.c_str(), c.name.c_str(),
                             dmg, c.name.c_str());
                } else {
                    snprintf(buf, sizeof buf,
                             "The %s strikes %s for %d.",
                             name.c_str(), c.name.c_str(),
                             dmg);
                }
                log.add(buf);
            }
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w > 0 && gr.h > 0) {
                int side = (int)rng.below((uint32_t)4);
                int nx = 0, ny = 0;
                if (side == 0) {
                    nx = gr.x;
                    ny = gr.y +
                         (int)rng.below((uint32_t)gr.h);
                } else if (side == 1) {
                    nx = gr.x + gr.w - 1;
                    ny = gr.y +
                         (int)rng.below((uint32_t)gr.h);
                } else if (side == 2) {
                    ny = gr.y;
                    nx = gr.x +
                         (int)rng.below((uint32_t)gr.w);
                } else {
                    ny = gr.y + gr.h - 1;
                    nx = gr.x +
                         (int)rng.below((uint32_t)gr.w);
                }
                party.x = nx;
                party.y = ny;
                log.add("The " + name + " turns on the "
                        "company - repelled!");
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_ENLARGES) {
            // R140: save vs petrification or the victim
            // grows - STR rises 1 (capped 18), DEX drops
            // 1 (floored 3 - the bulk)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_PETRIFY_POLY);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " swells and "
                        "settles - " + c.name + " is "
                        "unchanged.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_STR) < 18)
                c.abilities.set(rules::ABILITY_STR,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_STR) + 1));
            if (c.abilities.get(rules::ABILITY_DEX) > 3)
                c.abilities.set(rules::ABILITY_DEX,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_DEX) - 1));
            log.add("The " + name + " swells " + c.name +
                    " - strength rises, grace thins!");
        } else if (a == dm::appendixh::TA_FALSE) {
            // R140: the feature is false - only light and
            // shadow; the trick is spent (the appearing
            // shape)
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s wavers - false! Only light "
                     "and shadow. The room falls still.",
                     name.c_str());
            log.add(buf);
            room.trickFeature = -1;
        } else if (a == dm::appendixh::TA_GRAVITY_LESSER) {
            // R140: half gravity - a random member bobs
            // and drops (1d4, no save)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(1, 4, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s lightens - %s bobs, "
                         "drops - %d! %s falls!",
                         name.c_str(), c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s lightens - %s bobs and "
                         "drops - %d.",
                         name.c_str(), c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_GRAVITY_NIL) {
            // R140: no gravity - the company floats to
            // the room's center and hangs there
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            party.x = gr.x + gr.w / 2;
            party.y = gr.y + gr.h / 2;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s stills the air - the company "
                     "floats!", name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_GRAVITY_VARYING) {
            // R140: gravity fluctuates - every living
            // member saves vs death/poison or 1d6 (the
            // crush shape)
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s lurches - gravity wavers!",
                     name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int target = rules::saveTarget(
                    c.classIndex, c.level,
                    rules::SAVE_DEATH_POISON);
                if (rules::attemptSave(dice, target, 0))
                    continue;
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                if (c.hp <= 0) c.hp = 0;
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_MOVES) {
            // R140: the feature moves - the company is
            // carried to a random tile of the room
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            party.x = gr.x + (int)rng.below((uint32_t)gr.w);
            party.y = gr.y + (int)rng.below((uint32_t)gr.h);
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s shifts - the company is "
                     "carried along!", name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_RANDOMLY_ACTS) {
            // R140: the feature acts at random - a d3:
            // a strike, a gift, or stillness
            int what = (int)dice.roll(1, 3, 0);
            if (what == 1) {
                int vi = victimIndex();
                if (vi < 0) return;
                Character& c = party.members[vi];
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char buf[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(buf, sizeof buf,
                             "The %s lashes out at %s - %d! "
                             "%s falls!",
                             name.c_str(), c.name.c_str(),
                             dmg, c.name.c_str());
                } else {
                    snprintf(buf, sizeof buf,
                             "The %s lashes out at %s - %d.",
                             name.c_str(), c.name.c_str(),
                             dmg);
                }
                log.add(buf);
                if (!party.alive()) {
                    log.add("GAME OVER - press N to roll a "
                            "new party.");
                }
            } else if (what == 2) {
                int vi = victimIndex();
                if (vi < 0) return;
                Character& c = party.members[vi];
                int heal = (int)dice.roll(2, 4, 2);
                c.hp += heal;
                if (c.hp > c.maxHp) c.hp = c.maxHp;
                char buf[192];
                snprintf(buf, sizeof buf,
                         "The %s gives freely - %s heals "
                         "%d.", name.c_str(),
                         c.name.c_str(), heal);
                log.add(buf);
            } else {
                log.add("The " + name + " stirs - and "
                        "does nothing.");
            }
        } else if (a == dm::appendixh::TA_SLOPING) {
            // R140: the floor slopes - the company slides
            // to the room's low (south) edge
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            party.x = gr.x + (int)rng.below((uint32_t)gr.w);
            party.y = gr.y + gr.h - 1;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s tilts - the company slides to "
                     "the low edge!", name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SYMBIOTIC) {
            // R140: a symbiote latches on - save vs
            // spells or CON drops 1 (floored 3)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " reaches - " +
                        c.name + " shrugs it off.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_CON) > 3)
                c.abilities.set(rules::ABILITY_CON,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_CON) - 1));
            log.add("A passenger from the " + name +
                    " settles into " + c.name + "!");
        } else if (a == dm::appendixh::TA_WISH_REVERSAL) {
            // R140: the wish fulfilled in reverse - the
            // inverted R134 boon table: harm the company,
            // age a victim, or the purse bleeds
            int what = (int)dice.roll(1, 3, 0);
            if (what == 1) {
                for (auto& c : party.members) {
                    if (c.hp <= 0) continue;
                    c.hp -= (int)dice.roll(1, 6, 0);
                    if (c.hp <= 0) c.hp = 0;
                }
                log.add("The " + name + " twists - the "
                        "company suffers!");
                if (!party.alive()) {
                    log.add("GAME OVER - press N to roll a "
                            "new party.");
                }
            } else if (what == 2) {
                int vi = victimIndex();
                if (vi < 0) return;
                Character& c = party.members[vi];
                applyMagicalAging(c, party.careerDays, 10);
                log.add("The " + name + " twists - " +
                        c.name + " ages 10 years!");
            } else {
                int loss = party.gold / 10;
                if (loss < 1) loss = 1;
                party.gold -= loss;
                char buf[160];
                snprintf(buf, sizeof buf,
                         "The %s twists - %d gp crumbles "
                         "away!", name.c_str(), loss);
                log.add(buf);
            }
        } else if (a == dm::appendixh::TA_APPEARING) {
            // R136: the feature manifests before the
            // company - and melts away; the room's trick
            // is spent (a convention; the print gives no
            // mechanics)
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s appears - and melts away. "
                     "The room falls still.",
                     name.c_str());
            log.add(buf);
            room.trickFeature = -1;
        } else if (a == dm::appendixh::TA_INVISIBLE) {
            // R136: an unseen strike - a random living
            // member takes 1d6, no save (the print gives
            // no figure; the convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(1, 6, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "Something unseen strikes %s for "
                         "%d - %s falls!",
                         c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "Something unseen strikes %s for "
                         "%d.",
                         c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_GASEOUS) {
            // R136: a poison cloud fills the room - every
            // living member saves vs death/poison or
            // takes 1d6 (the print gives no figure; the
            // trap shape)
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s hisses - a sickly cloud "
                     "spreads!",
                     name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int target = rules::saveTarget(
                    c.classIndex, c.level,
                    rules::SAVE_DEATH_POISON);
                if (rules::attemptSave(dice, target, 0)) {
                    char b2[160];
                    snprintf(b2, sizeof b2,
                             "%s breathes through it.",
                             c.name.c_str());
                    log.add(b2);
                    continue;
                }
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char b2[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(b2, sizeof b2,
                             "The cloud chokes %s (%d) - "
                             "%s falls!",
                             c.name.c_str(), dmg,
                             c.name.c_str());
                } else {
                    snprintf(b2, sizeof b2,
                             "The cloud burns %s for %d.",
                             c.name.c_str(), dmg);
                }
                log.add(b2);
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_ONE_WAY) {
            // R135: the way back seals - the company is
            // committed to this room (a convention; the
            // print gives no mechanics)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            party.x = gr.x + gr.w / 2;
            party.y = gr.y + gr.h / 2;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s thuds - the way back seals!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_PIVOTS) {
            // R135: the room turns a quarter - the
            // company's position rotates 90 degrees about
            // the room center, clamped inside (the
            // print gives no mechanics; a convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            int cx = gr.x + gr.w / 2;
            int cy = gr.y + gr.h / 2;
            int nx = cx - (party.y - cy);
            int ny = cy + (party.x - cx);
            if (nx < gr.x) nx = gr.x;
            if (nx > gr.x + gr.w - 1) nx = gr.x + gr.w - 1;
            if (ny < gr.y) ny = gr.y;
            if (ny > gr.y + gr.h - 1) ny = gr.y + gr.h - 1;
            party.x = nx;
            party.y = ny;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s pivots - the walls swing!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SPINNING) {
            // R135: a full half-turn - the company's
            // position rotates 180 degrees about the
            // room center, clamped inside (a convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            int cx = gr.x + gr.w / 2;
            int cy = gr.y + gr.h / 2;
            int nx = 2 * cx - party.x;
            int ny = 2 * cy - party.y;
            if (nx < gr.x) nx = gr.x;
            if (nx > gr.x + gr.w - 1) nx = gr.x + gr.w - 1;
            if (ny < gr.y) ny = gr.y;
            if (ny > gr.y + gr.h - 1) ny = gr.y + gr.h - 1;
            party.x = nx;
            party.y = ny;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s spins - the room whirls!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SHIFTING) {
            // R135: the walls flex - the company's
            // position mirrors across the room's center
            // line (a convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            int cx = gr.x + gr.w / 2;
            party.x = 2 * cx - party.x;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s shifts - the walls flex!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SLIDING) {
            // R135: the floor tilts - the company is
            // shoved to a random edge tile of the room
            // (a convention; the print gives no mechanics)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            int side = (int)rng.below((uint32_t)4);
            int nx = 0, ny = 0;
            if (side == 0) {
                nx = gr.x;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 1) {
                nx = gr.x + gr.w - 1;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 2) {
                ny = gr.y;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            } else {
                ny = gr.y + gr.h - 1;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            }
            party.x = nx;
            party.y = ny;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s tilts - the company slides!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SHOOTS ||
                   a == dm::appendixh::TA_POISON) {
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
                char buf[192];
                snprintf(buf, sizeof buf,
                         "The %s %s - %s saved!",
                         name.c_str(),
                         a == dm::appendixh::TA_POISON
                             ? "belches venom" : "fires",
                         c.name.c_str());
                log.add(buf);
                return;
            }
            int dmg = (int)dice.roll(2, 6, 0);
            c.hp -= dmg;
            char buf[224];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s %s %s for %d - %s falls!",
                         name.c_str(),
                         a == dm::appendixh::TA_POISON
                             ? "envenoms" : "hits",
                         c.name.c_str(), dmg, c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s %s %s for %d.",
                         name.c_str(),
                         a == dm::appendixh::TA_POISON
                             ? "envenoms" : "hits",
                         c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
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

// ---- placeLockedDoors ----
// R304: the DMG doors prose - metal doors
// are usually locked. One locked door per
// delve (the count judgment; the print
// carries no count): a TILE_WALL slot with
// open tiles on both sides of one axis (a
// real passage to bar - the R45 secret-door
// scan pattern). The door prints as a
// TILE_DOOR the company sees but cannot
// pass until a thief works it.
void AppState::placeLockedDoors(){
        lockedDoors.clear();
        int placed = 0;
        int guard = 0;
        while (placed < rules::doorLockedPerDelveCount() &&
               ++guard < 500) {
            int x = 1 + (int)rng.below(MAP_TILES_X - 2);
            int y = 1 + (int)rng.below(MAP_TILES_Y - 2);
            if (map.at(x, y) != TILE_WALL) continue;
            bool openAbove = map.at(x, y - 1) == TILE_FLOOR ||
                             map.at(x, y - 1) == TILE_CORR;
            bool openBelow = map.at(x, y + 1) == TILE_FLOOR ||
                             map.at(x, y + 1) == TILE_CORR;
            bool openLeft  = map.at(x - 1, y) == TILE_FLOOR ||
                             map.at(x - 1, y) == TILE_CORR;
            bool openRight = map.at(x + 1, y) == TILE_FLOOR ||
                             map.at(x + 1, y) == TILE_CORR;
            if (!((openAbove && openBelow) ||
                  (openLeft && openRight))) continue;
            map.set(x, y, TILE_DOOR);
            LockedDoor d;
            d.x = x;
            d.y = y;
            lockedDoors.push_back(d);
            ++placed;
        }
    }

// ---- lockedDoorAt ----
// R304: the unopened lock at a tile (null
// when the tile is free) - the movement
// gate reads it
const LockedDoor* AppState::lockedDoorAt(int x, int y) const{
        for (const auto& d : lockedDoors)
            if (!d.opened && d.x == x && d.y == y)
                return &d;
        return nullptr;
    }

// ---- bumpLockedDoor ----
// R304: the company walks into the locked
// door. The bump spends the turn (the
// searchExplore convention) and the first
// living thief works the lock for the DMG
// time draw against the printed open locks
// percentile (the R298 seam). One try per
// lock (the printed note): a retry waits for
// a higher level thief.
void AppState::bumpLockedDoor(int x, int y){
        LockedDoor* door = nullptr;
        for (auto& d : lockedDoors)
            if (!d.opened && d.x == x && d.y == y)
                door = &d;
        if (door == nullptr) return;

        ++turnCount;
        tickActivity(1);   // R119: the lock is work too

        const Character* thief = nullptr;
        for (const auto& c : party.members) {
            if (c.hp <= 0 || c.classIndex != 3) continue;
            thief = &c;
            break;
        }
        if (thief == nullptr) {
            log.add("The iron-bound door is locked - no "
                    "thief walks with you.");
        } else if (door->tryLevel >= thief->level) {
            log.add("The lock resists - a higher level "
                    "thief must try it.");
        } else {
            door->tryLevel = thief->level;
            int rounds = rules::thfLocksPickRoundsMin() +
                (int)rng.below(
                    rules::thfLocksPickRoundsMax() -
                    rules::thfLocksPickRoundsMin() + 1);
            int roll = (int)rng.below(1000);
            char buf[96];
            if (rules::thfAttemptSucceeds(roll,
                    rules::THF_OPEN_LOCKS, thief->level,
                    thief->race,
                    (int)thief->abilities.dex)) {
                door->opened = true;
                snprintf(buf, sizeof buf,
                         "%s works the lock for %d "
                         "rounds - it opens!",
                         thief->name.c_str(), rounds);
            } else {
                snprintf(buf, sizeof buf,
                         "%s works the lock for %d "
                         "rounds - it resists.",
                         thief->name.c_str(), rounds);
            }
            log.add(buf);
        }

        // the turn spent can draw a wanderer
        if (dm::wanderCheck(dice, wander))
            spawnWanderingEncounter();
    }

// ---- placeFlood ----
// R312: the flooded crossing - one water
// pool per delve (the R304 one-per-delve
// convention; the count judgment): a 2-3
// by 2-3 tile sheet of open floor clear
// of the stairs and the entry (the way
// down stays dry). The surface SWIMMING
// paragraph (R311) governs the crossing.
void AppState::placeFlood(){
        int placed = 0;
        int guard = 0;
        while (placed < rules::floodPerDelveCount() &&
               ++guard < 500) {
            int x = 1 + (int)rng.below(MAP_TILES_X - 2);
            int y = 1 + (int)rng.below(MAP_TILES_Y - 2);
            int w = (int)rng.range(
                rules::floodSideMin(),
                rules::floodSideMax());
            int h = (int)rng.range(
                rules::floodSideMin(),
                rules::floodSideMax());
            bool allFloor = true;
            for (int yy = y; yy < y + h; ++yy)
                for (int xx = x; xx < x + w; ++xx)
                    if (map.at(xx, yy) != TILE_FLOOR)
                        allFloor = false;
            if (!allFloor) continue;
            bool onStairs =
                stairsX >= x && stairsX < x + w &&
                stairsY >= y && stairsY < y + h;
            bool onEntry =
                dungeon.entryX >= x &&
                dungeon.entryX < x + w &&
                dungeon.entryY >= y &&
                dungeon.entryY < y + h;
            if (onStairs || onEntry) continue;
            for (int yy = y; yy < y + h; ++yy)
                for (int xx = x; xx < x + w; ++xx)
                    map.set(xx, yy, TILE_WATER);
            ++placed;
        }
    }

// ---- enterWater ----
// R312: the company steps from dry land
// into the water tile. The surface
// SWIMMING paragraph (R311) gates the
// crossing: the first living member in
// metal armor bars the whole company
// (magic armor dog paddles - the
// exception) and the blocked step spends
// a bump turn (the R304 convention),
// wanderer and all; a passing gate logs
// the plunge, and each living swimmer
// rolls the drown percent ONCE (the
// judgment - the per-hour print condensed
// to the crossing). The step itself is
// the normal pace cost (the caller moves
// the company).
bool AppState::enterWater(int nx, int ny){
        (void)nx; (void)ny;
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (!rules::swimCanSwim((int)c.armor.id,
                                    c.armor.plus)) {
                ++turnCount;
                tickActivity(1);   // R119: the refusal
                char buf[96];
                snprintf(buf, sizeof buf,
                         "%s cannot swim in %s - the "
                         "flood bars the way.",
                         c.name.c_str(),
                         items::armor(c.armor.id).name);
                log.add(buf);
                // the turn spent can draw a wanderer
                if (dm::wanderCheck(dice, wander))
                    spawnWanderingEncounter();
                return false;
            }
        }
        log.add("The company takes to the water.");
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            int loadLbs = rules::swimLoadBeyondArmorLbs(
                carriedWeight(c),
                items::armor(c.armor.id).weightGp);
            int rolls = rules::swimDrownRollPerCrossing();
            for (int r = 0; r < rolls; ++r) {
                int roll = (int)rng.below(100);
                if (roll < rules::uwSurfaceDrownPct(
                        loadLbs)) {
                    c.hp = 0;
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "%s goes under - drowned.",
                             c.name.c_str());
                    log.add(buf);
                    break;
                }
            }
        }
        return true;
    }

// ---- forceLockedDoor ----
// R305: [O] - the company puts its shoulders
// to the adjacent locked door. The shove
// spends the turn (the searchExplore
// convention) and up to
// doorWidthStandardAttempts living members
// each roll the d6 against the R153
// open-doors-locked parentheticals (the
// exceptional wrench is once ever per door),
// while doorLockedSimultaneousOnes
// simultaneous 1s tear the lock out of the
// frame (the DMG doors prose; the wander
// check rides, the bump convention).
void AppState::forceLockedDoor(){
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;

        ++turnCount;
        tickActivity(1);   // R119: the shove is work too

        LockedDoor* door = nullptr;
        for (auto& d : lockedDoors) {
            if (d.opened) continue;
            int dx = d.x - party.x;
            int dy = d.y - party.y;
            bool hits = (dx == 1 || dx == -1) && dy == 0;
            hits = hits ||
                   (dx == 0 && (dy == 1 || dy == -1));
            if (hits) {
                door = &d;
                break;
            }
        }
        if (door == nullptr) {
            log.add("There is no locked door to force "
                    "here.");
        } else {
            int ones = 0;
            int attempts = 0;
            bool opened = false;
            for (const auto& c : party.members) {
                if (attempts >=
                        rules::doorWidthStandardAttempts())
                    break;
                if (c.hp <= 0) continue;
                ++attempts;
                int roll = 1 + (int)rng.below(6);
                int lmax = rules::strOpenDoorsLockedMax(
                    c.abilities.str, c.exStr);
                if (lmax > 0 && !door->exTried) {
                    door->exTried = true;
                    if (roll <= lmax) {
                        door->opened = true;
                        opened = true;
                        char buf[96];
                        snprintf(buf, sizeof buf,
                                 "%s wrenches the locked "
                                 "door open!",
                                 c.name.c_str());
                        log.add(buf);
                        break;
                    }
                }
                if (roll == 1) ++ones;
            }
            if (!opened && ones >=
                    rules::doorLockedSimultaneousOnes()) {
                door->opened = true;
                opened = true;
                log.add("The shoulders slam home - the "
                        "lock gives!");
            }
            if (!opened)
                log.add("The door will not budge.");
        }

        // the turn spent can draw a wanderer
        if (dm::wanderCheck(dice, wander))
            spawnWanderingEncounter();
    }

// ---- hideExplore ----
// R306: [I] - the first living thief blends
// into the shadows (the R298 percentile).
// The DMG commentary print: hiding is never
// possible under observation, and the
// unobserved attempt still stands the dice -
// the engine site runs unobserved. The
// success folds at the wander site: one
// wanderer passes the company unseen. The
// turn spends (the bump convention).
void AppState::hideExplore(){
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;

        ++turnCount;
        tickActivity(1);   // R119: the wait is work too

        const Character* thief = nullptr;
        for (const auto& t : party.members) {
            if (t.hp <= 0 || t.classIndex != 3) continue;
            thief = &t;
            break;
        }
        if (thief == nullptr) {
            log.add("No thief walks with you - the "
                    "shadows stay empty.");
        } else {
            int roll = (int)rng.below(1000);
            char buf[96];
            if (rules::thfAttemptSucceeds(roll,
                    rules::THF_HIDE_SHADOWS,
                    thief->level, thief->race,
                    (int)thief->abilities.dex)) {
                hiddenThief = true;
                snprintf(buf, sizeof buf,
                         "%s melts into the shadows.",
                         thief->name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "%s presses into the shadows - "
                         "they betray the attempt.",
                         thief->name.c_str());
            }
            log.add(buf);
        }

        // the turn spent can draw a wanderer
        if (dm::wanderCheck(dice, wander))
            spawnWanderingEncounter();
    }

// ---- readScript ----
// R306: the lair script - the monster hoard
// holds a treasure map (the PHB print: the
// read languages chance enables the reading
// of instructions and treasure maps). The
// first living thief reads it once per
// delve (the JUDGMENT); success pays the
// coins cache (the 2d6 shape scaled by the
// level).
void AppState::readScript(){
        if (scriptTried) return;
        scriptTried = true;

        const Character* thief = nullptr;
        for (const auto& t : party.members) {
            if (t.hp <= 0 || t.classIndex != 3) continue;
            thief = &t;
            break;
        }
        if (thief == nullptr) {
            log.add("The script waits for a thief.");
            return;
        }
        int roll = (int)rng.below(1000);
        char buf[96];
        if (rules::thfAttemptSucceeds(roll,
                rules::THF_READ_LANGUAGES,
                thief->level, thief->race,
                (int)thief->abilities.dex)) {
            int gp = (int)dice.roll(2, 6, 0) * 10 *
                     dungeonLevel;
            party.gold += gp;
            party.delveGold += gp;
            snprintf(buf, sizeof buf,
                     "%s reads the script - a cache "
                     "holds %d gp.",
                     thief->name.c_str(), gp);
        } else {
            snprintf(buf, sizeof buf,
                     "%s squints at the script - it "
                     "stays cryptic.",
                     thief->name.c_str());
        }
        log.add(buf);
    }

// ---- searchExplore ----
void AppState::searchExplore(){
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;
        ++turnCount;
        tickActivity(1);   // R119: the search is activity too
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
        // R42: gold scales up with depth - 25% more per level
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
                // record) - the def-free by_level ladder
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
            // R45: the hire earns a half share (DMG p.86 -
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
        // R306: the lair script - the hoard map
        if (mmLair) readScript();
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
            // R77: the claim layer - magic finds go to living party
            // members when they improve the member's gear; carried
            // stacks (potions, scrolls) pool. Cursed items (III.F/G/H
            // rows) are never claimed - the party does not knowingly
            // take up a Sword +1, Cursed. Ammo bundles await real
            // inventory (per-arrow tracking). Claimed and carried
            // items leave the hoard BEFORE the take is appraised:
            // nothing is both wielded and sold.
            std::vector<dm::treasure::MagicItem> carriedOff;
            for (auto it = hoard.magic.begin();
                 it != hoard.magic.end(); ) {
                const dm::treasure::MagicItem& mi = *it;
                bool take = false;
                // R85: the pack-carry candidate - the gear cases
                // set it when nobody equipped the item
                PackItem cand{};
                bool carryable = false;
                if (mi.cursed()) {
                    // never claimed - stays appraised below
                } else if (mi.isHealingPotion()) {
                    addCapped(party.potions, mi.qty, CARRIED_CAP);
                    snprintf(buf, sizeof buf,
                             "You find: %s x%d - carried (%d held).",
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
                        if (!take) {   // R85: nobody wielded it
                            cand.kind = 0;
                            cand.id = (int)items::WPN_LONG_SWORD;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
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
                        if (!take && id != items::WPN_COUNT) {
                            cand.kind = 0;
                            cand.id = (int)id;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
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
                        if (!take && id != items::WPN_COUNT) {
                            cand.kind = 0;
                            cand.id = (int)id;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
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
                        if (!take) {
                            cand.kind = 2;
                            cand.id = 0;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
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
                        if (!take && id != items::ARMOR_COUNT) {
                            cand.kind = 1;
                            cand.id = (int)id;
                            cand.plus = mi.weaponPlus();
                            cand.gp = mi.gp;
                            carryable = true;
                        }
                        break;
                    }
                    case dm::treasure::MIK_SCROLL:
                        // III.B scrolls - carried, studied later
                        addCapped(party.scrolls, mi.qty, CARRIED_CAP);
                        snprintf(buf, sizeof buf,
                                 "You find: %s x%d - carried (%d held).",
                                 mi.name.c_str(), mi.qty,
                                 party.scrolls);
                        log.add(buf);
                        if (!mi.note.empty()) log.add(mi.note);
                        take = true;
                        break;
                    case dm::treasure::MIK_AMMO:
                        // R79: arrow/bolt bundles -> the quiver of
                        // the first living member whose ranged weapon
                        // fires them (count-only; per-arrow enchant
                        // awaits real inventory). Singular specials
                        // (Slaying, Direction) stay appraised - the
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
                    case dm::treasure::MIK_OTHER:
                        // R81: a Ring of Protection goes to the
                        // first living member without one; every
                        // other ring/rod/misc stays appraised
                        for (auto& c : party.members) {
                            if (c.hp <= 0) continue;
                            if (claimRing(c, mi.name, mi.qty)) {
                                snprintf(buf, sizeof buf,
                                         "%s wears the %s.",
                                         c.name.c_str(),
                                         mi.name.c_str());
                                log.add(buf);
                                take = true;
                                break;
                            }
                        }
                        break;
                    default:
                        // declined ammo and unclaimed rings/rods/
                        // misc stay appraised to gold
                        break;
                    }
                }
                // R80: the hire's claim - when no member took the
                // item, the henchman upgrades his kit (sword plus,
                // shield plus; the plate ladder is unchanged, and
                // only III.G swords arm him - his kit is fixed)
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
                // R85: the pack - unclaimed uncursed gear is
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
                    // R86: the mule slot - the hire shoulders
                    // what the members could not (same cap; his
                    // pack is cargo only, the kit stays R80)
                    if (!take && party.henchmanPresent &&
                        party.henchmanHp > 0 &&
                        (int)party.henchmanPack.size() < PACK_CAP &&
                        henchmanCanShoulder(party, cand)) {
                        party.henchmanPack.push_back(cand);
                        snprintf(buf, sizeof buf,
                                 "%s shoulders the %s "
                                 "(hire's pack %d/%d).",
                                 party.henchmanName.c_str(),
                                 mi.name.c_str(),
                                 (int)party.henchmanPack.size(),
                                 PACK_CAP);
                        log.add(buf);
                        take = true;
                    }
                }
                if (take) {
                    carriedOff.push_back(mi);
                    it = hoard.magic.erase(it);
                } else {
                    ++it;
                }
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
            // R142: the sample dungeon - the book's own
            // hoards ride the keyed rooms; the generated
            // treasure roll stands down for them (the take
            // earns no gold xp - a museum piece, not a
            // guarded hoard; documented convention)
            if (seed == dm::sampledungeon::kSampleSeed &&
                combatRoomIndex < 6) {
                if (combatRoomIndex == 0 && !room.looted) {
                    // the goblin skull: 19 sp folded at 10:1
                    // (2 gp, rounded) plus a 50 gp garnet
                    int take = 52;
                    party.gold += take;
                    party.delveGold += take;
                    log.add("In the goblin skull: 19 silver "
                            "pieces and a garnet - 52 gp "
                            "all told.");
                    // a quarter of the ten rotting sacks
                    // hide yellow mold (the book: save vs
                    // poison or die)
                    if ((int)rng.below(100) < 25) {
                        log.add("One of the rotting sacks "
                                "puffs YELLOW MOLD!");
                        for (auto& c : party.members) {
                            if (c.hp <= 0) continue;
                            int target = rules::saveTarget(
                                c.classIndex, c.level,
                                rules::SAVE_DEATH_POISON);
                            if (rules::attemptSave(
                                    dice, target, 0)) {
                                log.add(c.name + " breathes "
                                        "shallow - safe.");
                            } else {
                                c.hp = 0;
                                log.add(c.name + " inhales "
                                        "the spores and "
                                        "dies.");
                            }
                        }
                        if (!party.alive())
                            log.add("GAME OVER - press N to "
                                    "roll a new party.");
                    }
                } else if (combatRoomIndex == 1 &&
                           !room.looted) {
                    log.add("The ivory tube holds a vellum "
                            "map, water-ruined - only the "
                            "first few chambers stay "
                            "legible. The abbot's key is "
                            "the crypts' own: beyond the "
                            "seventh knob.");
                } else if (combatRoomIndex == 2 &&
                           !room.looted) {
                    log.add("Seven stone knobs over empty "
                            "socket holes - the seventh "
                            "opens the south crypt door. "
                            "Turn it with the X key.");
                } else if (combatRoomIndex == 3 &&
                           !room.looted) {
                    log.add("Gnawed bones stack the crypt's "
                            "niches - ghouls kept this "
                            "larder (area 24). The abbot's "
                            "key fits the old crypt locks.");
                } else if (combatRoomIndex == 4 &&
                           !room.looted) {
                    log.add("Rows of sunken biers - the "
                            "faithful of the monastery "
                            "rested here (area 27). The "
                            "abbot's key fits the old "
                            "crypt locks.");
                } else if (combatRoomIndex == 5 &&
                           !room.looted) {
                    log.add("A defaced altar and torn "
                            "vestments - the evil cleric "
                            "kept this crypt (areas "
                            "35-37).");
                }
                room.monsterKey.clear();
                room.count = 0;
                room.looted = true;
            }
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
                // R40: +1 dagger - throwable loot. Claimed by the
                // first living member whose melee weapon is either
                // already throwable (an upgrade in plus - dagger
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
                // R28: short bow - claimed by the first living
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
                // R39: a bundle of arrows - given to the first
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
                // R44: an unidentified magic item - the enchant
                // is rolled now but hidden until a scroll is
                // read over it ([I] in town)
                if (t.unidentifiedItem) {
                    Party::PendingItem it;
                    it.kind = (int)rng.below(2);
                    it.plus = 1 +
                        (rng.below(100) < 10 ? 1 : 0);
                    party.unidentified.push_back(it);
                    log.add("You find an unidentified magic "
                            "item - a scribe's scroll would "
                            "serve.");
                }
                room.monsterKey.clear();
                room.count = 0;
                room.looted = true;
            }
        }

        // R56: defeated NPC parties drop their gear. A wandering
        // Character Subtable party (DMG p.176) fights with book-
        // rolled magic items (R55) - the winners strip the
        // fallen: the best enchanted weapon/armor/shield among the
        // SLAIN (survivors keep theirs), plus a coin purse
        // (adventurers carry walking money, not hoards -
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

// ---- listenExplore ----
// R120: listening at doors (DMG p.60) - R118's first
// caller. [H] - ear to the nearest portal. The best
// listener leads (a thief's hear-noise skill, else the
// human band); the die ALWAYS rolls (the book's DM
// discipline - appear disinterested); silent creatures
// (undead - the registry's flag) are never heard; the
// hint is imprecise per the book: "never say 'You hear
// ogres'".
void AppState::listenExplore(){
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;
        ++turnCount;
        tickActivity(1);   // R119: the ear costs strain too
        int thiefLevel = 0;
        for (const auto& c : party.members)
            if (c.hp > 0 && c.classIndex == 3 &&
                c.level > thiefLevel)
                thiefLevel = c.level;
        int chance = abilities::bestListenIn20(
            thiefLevel > 0, thiefLevel);
        int roomIdx = occupiedRoomNear(party.x, party.y, 3);
        bool heard = abilities::listenAtDoor(dice, chance);
        if (roomIdx >= 0) {
            const auto& room = occupancy.rooms[roomIdx];
            const monsters::MonsterDef* def =
                registry.find(room.monsterKey);
            if (def && def->undead) heard = false;
        }
        if (roomIdx < 0 || !heard) {
            log.add("You hear nothing.");
            return;
        }
        log.add("You hear rumbling, voice-like sounds.");
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
        // R120: a parleyed room no longer leaps at the
        // company (the parley gate rolled non-hostile)
        if (room.parleyed) return;

        const monsters::MonsterDef* def = registry.find(room.monsterKey);
        // R52: foes build through the DMG-range path (hydra
        // heads / dragon age brackets, stored at population)
        std::vector<ai::Actor> foes =
            buildFoesFromDm(encFromRoom(room));
        if (foes.empty()) return;
        // R120: THE PARLEY GATE (DMG p.63-64, R117's first
        // caller) - the monsters react before steel is drawn;
        // only the book's two starred bands mean immediate
        // attack. Charisma follows the engine's best-living-
        // Cha spokesman convention (R58).
        int chaAdj = 0;
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            int adj = rules::chaReactionAdj(c.abilities.cha);
            if (adj > chaAdj) chaAdj = adj;
        }
        dm::Reaction react = dm::rollReaction(dice, chaAdj);
        if (!dm::reactionAttacks(react)) {
            room.parleyed = true;
            const char* mname2 = def ? def->name.c_str() : "monster";
            const char* calm =
                react == dm::REACTION_NEUTRAL
                    ? " ignores you." :
                react == dm::REACTION_UNCERTAIN_NEG
                    ? " grumbles and watches warily." :
                react == dm::REACTION_UNCERTAIN_POS
                    ? " seems curious about you." :
                react == dm::REACTION_FRIENDLY
                    ? " greets you warmly." :
                    " hails you joyfully!";
            char pbuf[96];
            if (room.count == 1)
                snprintf(pbuf, sizeof pbuf, "The %s%s",
                         mname2, calm);
            else
                snprintf(pbuf, sizeof pbuf, "The %ss%s",
                         mname2, calm);
            log.add(pbuf);
            return;
        }
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
