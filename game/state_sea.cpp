#include "appstate.h"

// ---- enterSea ----
void AppState::enterSea(){
        if (mode != MODE_TOWN) return;
        if (!party.alive()) return;
        if (!party.crewHired) {
            log.add("You have no crew - hire them in town "
                    "first ([C] at the wharf).");
            return;
        }
        sea = SeaState{};
        mode = MODE_SEA;
        log.add("The company sets sail aboard the coaster.");
        log.add("Coastal waters - [T] to sail on, [H] for "
                "home.");
    }

// ---- seaDepth ----
dm::WaterDepth AppState::seaDepth() const{
        return (sea.daysOut < kSeaCoastalDays)
            ? dm::WaterDepth::SHALLOW : dm::WaterDepth::DEEP;
    }

// ---- seaStep ----
void AppState::seaStep(){
        if (mode != MODE_SEA || !party.alive()) return;
        dm::DungeonEncounter e = dm::rollWaterEncounter(
            registry, dice,
            (int)dice.roll(1, 100, 0), (int)dice.roll(1, 100, 0),
            dm::WaterBody::SALT, seaDepth(),
            dm::WaterClime::COOL);
        if (e.key.empty() || e.count <= 0) {
            log.add("The sea is calm.");
            return;
        }
        std::vector<ai::Actor> foes = buildFoesFromDm(e);
        if (foes.empty()) return;
        char buf[96];
        if (e.count == 1)
            snprintf(buf, sizeof buf,
                     "It rises from the waves - a wild %s "
                     "attacks the ship!", e.key.c_str());
        else
            snprintf(buf, sizeof buf,
                     "%d wild %ss attack the ship!",
                     e.count, e.key.c_str());
        log.add(buf);
        beginCombat(std::move(foes), -1, e.key);
    }

// ---- seaTravel ----
void AppState::seaTravel(){
        if (mode != MODE_SEA) return;
        if (!party.alive()) return;
        sea.homeward = false;
        ++sea.day;
        ++sea.daysOut;
        ++party.careerDays;   // R95: the sea counts
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d at sea - the %s.",
                 sea.day,
                 sea.daysOut < kSeaCoastalDays
                     ? "coastal waters" : "open sea");
        log.add(buf);
        seaStep();
        checkArrivedSea();
    }

// ---- seaHomeward ----
void AppState::seaHomeward(){
        if (mode != MODE_SEA) return;
        if (!party.alive()) return;
        sea.homeward = true;
        ++sea.day;
        --sea.daysOut;
        ++party.careerDays;   // R95: the sea road counts
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d - the sea road home.",
                 sea.day);
        log.add(buf);
        seaStep();
        checkArrivedSea();
    }

// ---- seaCamp ----
void AppState::seaCamp(){
        if (mode != MODE_SEA) return;
        if (!party.alive()) return;
        log.add("You anchor for the night...");
        seaStep();
        if (mode != MODE_SEA) return;   // interrupted by steel
        overlandSafeCamp("The night passes; the ship rides "
                         "easy.");
    }

// ---- checkArrivedSea ----
void AppState::checkArrivedSea(){
        if (mode != MODE_SEA) return;
        if (sea.daysOut > 0) return;
        if (!party.alive()) return;
        log.add("The coaster makes port - landfall at last.");
        arriveTown();
    }

// ---- enterCity ----
void AppState::enterCity(){
        if (mode != MODE_TOWN) return;
        if (!party.alive()) return;
        mode = MODE_CITY;
        log.add("You walk the streets of the city.");
        log.add("[1] by day  [2] by night  [B] back to town.");
    }

// ---- leaveCity ----
void AppState::leaveCity(){
        if (mode != MODE_CITY) return;
        mode = MODE_TOWN;
        log.add("You return from the streets.");
    }

// ---- cityExcursion ----
void AppState::cityExcursion(dm::CityTime t){
        if (mode != MODE_CITY) return;
        if (!party.alive()) return;
        log.add(t == dm::CITY_DAY
            ? "You stroll out by daylight..."
            : "You slip into the night streets...");
        dm::DungeonEncounter e = dm::rollCityEncounter(
            registry, dice,
            (int)dice.roll(1, 100, 0), (int)dice.roll(1, 100, 0),
            t);
        if (e.isParty) {
            // noun: the matrix key, underscores as spaces
            std::string noun = e.key;
            for (auto& ch : noun)
                if (ch == '_') ch = ' ';
            overlandMeeting(e, noun.c_str(), false, false);
            return;
        }
        if (e.key.empty()) {
            log.add("Nothing comes of it.");
            return;
        }
        if (registry.find(e.key)) {
            std::vector<ai::Actor> foes = buildFoesFromDm(e);
            if (foes.empty()) return;
            char buf[96];
            if (e.count == 1)
                snprintf(buf, sizeof buf,
                         "A wild %s attacks in the alleys!",
                         e.key.c_str());
            else
                snprintf(buf, sizeof buf,
                         "%d wild %ss attack in the alleys!",
                         e.count, e.key.c_str());
            log.add(buf);
            beginCombat(std::move(foes), -1, e.key);
            return;
        }
        // fiction civilians - flavor only
        log.add(cityFlavor(e.key.c_str()));
    }
