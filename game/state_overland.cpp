#include "appstate.h"

// ---- enterOverland ----
void AppState::enterOverland(){
        if (mode != MODE_TOWN) return;
        overland = OverlandState{};
        mode = MODE_OVERLAND;
        log.add("The company sets out along the wild roads.");
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Day 1 - the %s, within sight of town.",
                 overlandTerrainName(overland.terrain));
        log.add(buf);
    }

// ---- overlandSetTerrain ----
void AppState::overlandSetTerrain(int t){
        if (mode != MODE_OVERLAND) return;
        if (t < dm::T_PLAIN || t > dm::T_MARSH) return;
        if (overland.castle.pending) {
            log.add("Decide the castle first - [A]pproach or [P]ass.");
            return;
        }
        if (t == overland.terrain) return;
        overland.terrain = t;
        char buf[96];
        snprintf(buf, sizeof buf, "You steer toward the %s.",
                 overlandTerrainName(t));
        log.add(buf);
    }

// ---- overlandInhabited ----
bool AppState::overlandInhabited() const{
        return overland.daysOut < kOverlandInhabitedDays;
    }

// ---- overlandClime ----
dm::OutdoorClime AppState::overlandClime() const{
        return overlandInhabited()
            ? dm::OC_TEMPERATE_INHABITED   // p.182: inhabited set
            : dm::OC_TEMPERATE_WILD;       // p.182: wilderness set
}

// ---- overlandMilesPerDay ----
// R123: the DMG pp.58-59 afoot rate - the company moves at
// the slowest walker's pace (the true loads decide the book's
// burden classes; the terrain class is the route's)
int AppState::overlandMilesPerDay() const{
        if (mode != MODE_OVERLAND) return 0;
        return companyFootMilesPerDay(
            party, dm::terrainClass(
                       (dm::OutdoorTerrain)overland.terrain));
    }

// ---- overlandStep ----
void AppState::overlandStep(){
        if (mode != MODE_OVERLAND || !party.alive()) return;
        if (overland.castle.pending) return;
        int d20 = (int)dice.roll(1, 20, 0);
        if (overlandInhabited()) {
            // p.182: "WHEN AN ENCOUNTER IN SUCH AN AREA IS
            // INDICATED, ROLL d20; 5 IN 20 ARE ENCOUNTERS WITH
            // A PATROL."
            if (d20 <= 5) { overlandPatrol(); return; }
        } else {
            // p.182: "roll d20; 1 in 20 is an encounter which
            // discovers such a stronghold."
            if (d20 == 1) { overlandDiscoverCastle(); return; }
        }
        overlandWildEncounter();
    }

// ---- overlandWildEncounter ----
void AppState::overlandWildEncounter(){
        dm::DungeonEncounter e = dm::rollOutdoorEncounter(
            registry, dice,
            (int)dice.roll(1, 100, 0), (int)dice.roll(1, 100, 0),
            overlandClime(),
            (dm::OutdoorTerrain)overland.terrain);
        if (e.isParty) {
            // the Men Subtable Character row - a wilderness
            // character party of levels 7-10 (R63, p.187 note)
            overlandMeeting(e, "adventurers", true, false);
            return;
        }
        if (e.key.empty() || e.count <= 0) {
            log.add("The way passes without incident.");
            return;
        }
        std::vector<ai::Actor> foes = buildFoesFromDm(e);
        if (foes.empty()) return;
        char buf[96];
        if (e.count == 1)
            snprintf(buf, sizeof buf, "A wild %s attacks!",
                     e.key.c_str());
        else
            snprintf(buf, sizeof buf, "%d wild %ss attack!",
                     e.count, e.key.c_str());
        log.add(buf);
        beginCombat(std::move(foes), -1, e.key);
    }

// ---- overlandPatrol ----
void AppState::overlandPatrol(){
        dm::DungeonEncounter e;
        e.isParty = true;
        e.key = "character_party";
        e.party = dm::rollPatrol(dice, false);
        e.count = (int)e.party.members.size();
        if (e.count <= 0) return;
        log.add("Riders on the road - a patrol!");
        overlandMeeting(e, "patrol", false, false);
    }

// ---- overlandMeeting ----
void AppState::overlandMeeting(dm::DungeonEncounter& e, const char* noun, bool favors, bool shelter){
        std::vector<ai::Actor> foes = buildFoesFromParty(e.party);
        if (foes.empty()) return;
        int chaAdj = 0;
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            int adj = rules::chaReactionAdj(c.abilities.cha);
            if (adj > chaAdj) chaAdj = adj;
        }
        int partyLevels = 0;
        for (const auto& c : party.members)
            if (c.hp > 0) partyLevels += c.level;
        if (party.henchmanPresent)
            partyLevels += party.henchmanLevel;
        int npcLevels = 0;
        for (const auto& m : e.party.members)
            npcLevels += m.level;
        dm::PartyReaction react = dm::rollPartyReaction(
            dice, chaAdj, npcLevels < partyLevels);
        char buf[96];
        switch (react) {
            case dm::PartyReaction::ViolentlyHostile:
                snprintf(buf, sizeof buf,
                         "The %s attacks without a word!", noun);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            case dm::PartyReaction::Hostile:
                snprintf(buf, sizeof buf,
                         "The %s sizes you up and attacks!", noun);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            case dm::PartyReaction::UncertainNegative:
                // p.63: 55% prone toward negative
                if ((int)dice.roll(1, 100, 0) <= 55) {
                    snprintf(buf, sizeof buf,
                             "The %s draws steel!", noun);
                    log.add(buf);
                    beginCombat(std::move(foes), -1, e.key);
                    return;
                }
                snprintf(buf, sizeof buf,
                         "The %s challenges you, then moves along.",
                         noun);
                log.add(buf);
                return;
            case dm::PartyReaction::Neutral:
                snprintf(buf, sizeof buf,
                         "The %s passes by, uninterested.", noun);
                log.add(buf);
                return;
            case dm::PartyReaction::UncertainPositive:
                if ((int)dice.roll(1, 100, 0) <= 55)
                    log.add("They hail you and move on.");
                else
                    log.add("They nod and pass by.");
                if (shelter) overlandSafeCamp(
                    "They point you to shelter by their fire.");
                return;
            case dm::PartyReaction::Friendly:
                snprintf(buf, sizeof buf,
                         "The %s hails you, shares word of the "
                         "trail, and departs.", noun);
                log.add(buf);
                if (shelter) overlandSafeCamp(
                    "You are welcomed to their hall for the night.");
                if (favors) {
                    int favor = (int)dice.roll(1, 6, 0);
                    if (favor == 1) {
                        ++party.potions;
                        log.add("One presses a potion of healing "
                                "on you before going.");
                    } else if (favor == 2) {
                        int gift = (int)dice.roll(2, 6, 0) * 10;
                        party.gold += gift;
                        party.delveGold += gift;
                        snprintf(buf, sizeof buf,
                                 "They toss a pouch of %d gp to "
                                 "your company!", gift);
                        log.add(buf);
                    }
                }
                return;
            case dm::PartyReaction::Enthusiastic:
                snprintf(buf, sizeof buf,
                         "The %s greets you warmly and warns of "
                         "dangers ahead!", noun);
                log.add(buf);
                if (shelter) overlandSafeCamp(
                    "You feast in their hall until morning.");
                if (favors) {
                    int favor = (int)dice.roll(1, 6, 0);
                    if (favor <= 2) {
                        ++party.potions;
                        log.add("One presses a potion of healing "
                                "on you before going.");
                    } else if (favor == 3) {
                        int gift = (int)dice.roll(2, 6, 0) * 10;
                        party.gold += gift;
                        party.delveGold += gift;
                        snprintf(buf, sizeof buf,
                                 "They toss a pouch of %d gp to "
                                 "your company!", gift);
                        log.add(buf);
                    }
                }
                return;
        }
    }

// ---- overlandSafeCamp ----
void AppState::overlandSafeCamp(const char* why){
        restoreSlots();
        restockAmmo();
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            int heal = c.level;
            if (c.hp + heal > c.maxHp) heal = c.maxHp - c.hp;
            if (heal > 0) c.hp += heal;
        }
        log.add(why);
        log.add("The company rests. Spells and wounds mend.");
    }

// ---- overlandDiscoverCastle ----
void AppState::overlandDiscoverCastle(){
        overland.castle.pending = true;
        overland.castle.type =
            dm::rollCastleType((int)dice.roll(1, 100, 0));
        overland.castle.aware =
            dm::castleAwareness((int)dice.roll(1, 6, 0));
        overland.castle.pctile = (int)dice.roll(1, 100, 0);
        dm::CastleArtillery art =
            dm::castleArtillery(overland.castle.type);
        char buf[160];
        snprintf(buf, sizeof buf, "A %s rises in the distance!",
                 overland.castle.type.type);
        log.add(buf);
        snprintf(buf, sizeof buf,
                 "Its walls mount %d ballistae, %d catapults, "
                 "%d cauldrons of oil.",
                 art.ballistae, art.lightCatapults, art.oilCauldrons);
        log.add(buf);
        switch (overland.castle.aware) {
            case dm::CASTLE_OCCUPANTS_AWARE:
                // p.183: surprised on 1 - "the fortress occupants
                // know they are there"
                log.add("Watch fires flare - the occupants know "
                        "you are there!");
                overlandApproach();
                return;
            case dm::CASTLE_OCCUPANTS_OUTSIDE:
                // p.183: surprise 2+ - the occupants are "actually
                // outside the place and within normal surprise
                // distance"
                log.add("Riders from the castle are already "
                        "outside the walls!");
                overlandApproach();
                return;
            default:
                log.add("Its occupants have not marked you - "
                        "[A]pproach or [P]ass by.");
                return;
        }
    }

// ---- overlandApproach ----
void AppState::overlandApproach(){
        if (mode != MODE_OVERLAND) return;
        if (!overland.castle.pending) return;
        overland.castle.pending = false;
        dm::CastleType t = overland.castle.type;
        dm::CastleInhabitants inh = dm::castleInhabitants(
            overland.castle.pctile, t.size);
        int pctile2 = (int)dice.roll(1, 100, 0);
        char buf[160];
        switch (inh) {
            case dm::CASTLE_TOTALLY_DESERTED:
                // p.183: "in disrepair and upon close inspection
                // appears empty" - the ruin shelters the company
                // (fiction: a safe night's rest)
                snprintf(buf, sizeof buf,
                         "The %s is long deserted - empty halls "
                         "and rotted gates.", t.type);
                log.add(buf);
                overlandSafeCamp("You shelter in the ruin; the "
                                 "night passes undisturbed.");
                return;
            case dm::CASTLE_DESERTED_MONSTER: {
                // p.183: "appears as totally deserted... but entry
                // into the construction will discover the monster"
                // - the OUTDOOR tables, ignoring men
                snprintf(buf, sizeof buf,
                         "The %s looks deserted - but something "
                         "lairs within!", t.type);
                log.add(buf);
                dm::DungeonEncounter e;
                int guard = 0;
                do {
                    e = dm::rollOutdoorEncounter(
                        registry, dice,
                        (int)dice.roll(1, 100, 0),
                        (int)dice.roll(1, 100, 0),
                        dm::OC_TEMPERATE_WILD,
                        (dm::OutdoorTerrain)overland.terrain);
                } while (guard++ < 24 &&
                         (e.key.empty() || overlandIndicatesMen(e)));
                if (e.key.empty() || e.count <= 0) {
                    log.add("The halls stand silent.");
                    return;
                }
                std::vector<ai::Actor> foes = buildFoesFromDm(e);
                if (foes.empty()) return;
                if (e.count == 1)
                    snprintf(buf, sizeof buf,
                             "The lair's tenant - a wild %s - "
                             "springs its ambush!", e.key.c_str());
                else
                    snprintf(buf, sizeof buf,
                             "The lair's tenants - %d wild %ss - "
                             "spring their ambush!",
                             e.count, e.key.c_str());
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            }
            case dm::CASTLE_HUMANS: {
                // Sub-Table II.A: bandits/berserkers/dervishes;
                // "numbers... are given in the MONSTER MANUAL
                // under the heading of MEN" - the registry
                const char* key =
                    dm::castleHumansType(pctile2);
                int count =
                    dm::castleHumansCount(registry, dice, key);
                if (count <= 0) count = 1;
                dm::DungeonEncounter e;
                e.key = key;
                e.count = count;
                std::vector<ai::Actor> foes = buildFoesFromDm(e);
                if (foes.empty()) {
                    log.add("The brutes are gone into the hills.");
                    return;
                }
                const monsters::MonsterDef* def = registry.find(key);
                snprintf(buf, sizeof buf,
                         "The %s is a den of %ss - %d attack!",
                         t.type,
                         def ? def->name.c_str() : key,
                         count);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            }
            case dm::CASTLE_CHARACTER_TYPES: {
                // Sub-Table II.B: the master and 2-5 henchmen
                // (R67 builders), met by the R58 reaction
                dm::PartyMember master =
                    dm::rollCastleMaster(dice, pctile2);
                dm::CharacterParty hench =
                    dm::rollCastleHenchmen(dice, master);
                dm::DungeonEncounter e;
                e.isParty = true;
                e.key = "character_party";
                e.party.members.push_back(master);
                for (const auto& m : hench.members)
                    e.party.members.push_back(m);
                e.count = (int)e.party.members.size();
                if (e.count <= 0) return;
                snprintf(buf, sizeof buf,
                         "A banner flies over the %s - its master "
                         "rides out to meet you.", t.type);
                log.add(buf);
                overlandMeeting(e, "garrison", false, true);
                // falls through to the arrival check (combat
                // started by a hostile meeting is mode-guarded)
            }
        }
        // peaceful resolutions complete a homeward last league
        // (combat paths arrive via endCombat instead)
        checkArrivedHome();
    }

// ---- overlandPass ----
void AppState::overlandPass(){
        if (mode != MODE_OVERLAND) return;
        if (!overland.castle.pending) return;
        overland.castle.pending = false;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "You give the %s a wide berth and press on.",
                 overland.castle.type.type);
        log.add(buf);
        checkArrivedHome();   // a bypassed castle on the last league
    }

// ---- overlandTravel ----
void AppState::overlandTravel(){
        if (mode != MODE_OVERLAND) return;
        if (overland.castle.pending) {
            log.add("Decide the castle first - [A]pproach or [P]ass.");
            return;
        }
        if (!party.alive()) return;
        overland.homeward = false;
        ++overland.day;
        ++overland.daysOut;
        ++party.careerDays;   // R95: the trail counts
        int miles = overlandMilesPerDay();   // R123: p.58-59
        overland.milesOut += miles;
        char buf[112];
        snprintf(buf, sizeof buf,
                 "Day %d - the %s. The company covers %d "
                 "miles (%d from town).",
                 overland.day,
                 overlandTerrainName(overland.terrain),
                 miles, overland.milesOut);
        log.add(buf);
        overlandStep();
        checkArrivedHome();   // defensive no-op when daysOut > 0
    }

// ---- overlandHomeward ----
void AppState::overlandHomeward(){
        if (mode != MODE_OVERLAND) return;
        if (overland.castle.pending) {
            log.add("Decide the castle first - [A]pproach or [P]ass.");
            return;
        }
        if (!party.alive()) return;
        overland.homeward = true;
        ++overland.day;
        --overland.daysOut;
        ++party.careerDays;   // R95: the trail counts
        int miles = overlandMilesPerDay();   // R123: p.58-59
        overland.milesOut -= miles;
        if (overland.milesOut < 0) overland.milesOut = 0;
        char buf[112];
        snprintf(buf, sizeof buf,
                 "Day %d - the road home, the %s. The company "
                 "covers %d miles (%d from town).",
                 overland.day,
                 overlandTerrainName(overland.terrain),
                 miles, overland.milesOut);
        log.add(buf);
        overlandStep();
        checkArrivedHome();
    }

// ---- overlandCamp ----
void AppState::overlandCamp(){
        if (mode != MODE_OVERLAND) return;
        if (overland.castle.pending) {
            log.add("Decide the castle first - [A]pproach or [P]ass.");
            return;
        }
        if (!party.alive()) return;
        log.add("You make camp for the night...");
        overlandStep();
        if (mode != MODE_OVERLAND) return;   // interrupted by steel
        if (overland.castle.pending) {
            // a discovery in the night abandons the camp
            log.add("The camp is abandoned.");
            return;
        }
        overlandSafeCamp("The night passes undisturbed.");
    }

// ---- checkArrivedHome ----
void AppState::checkArrivedHome(){
        if (mode != MODE_OVERLAND) return;
        if (overland.daysOut > 0) return;
        if (overland.castle.pending) return;
        if (!party.alive()) return;
        overland.daysOut = 0;
        arriveTown();   // R70: arrival billing too
        // R95 repair: this string was mangled by a past
        // round (two fragments collided) - "rise ahead" +
        // "the journey is over"
        log.add("The walls of town rise ahead - "
                "the journey is over.");
    }
