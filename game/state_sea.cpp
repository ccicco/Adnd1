#include "appstate.h"
#include "rules/startmoney.h"   // R303: the passerby purse
#include "rules/thieffunc.h"    // R303: the pockets roll

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

// ---- seaMilesPerDay ----
// R123: the DMG pp.58-59 sailed table - the coaster is a
// small merchant; her sea column prints one number, 50
// miles/day (the 50-60 band is the lake column). The roll
// stays generic lo..hi so a banded vessel would work too;
// the book's d4 long-voyage reduction applies to voyages
// of weeks, which this day cadence does not model -
// documented
int AppState::seaMilesPerDay(){
        int lo = dm::sailedMilesLo(dm::VESSEL_MERCHANT_SMALL,
                                   dm::WATER_SEA);
        int hi = dm::sailedMilesHi(dm::VESSEL_MERCHANT_SMALL,
                                   dm::WATER_SEA);
        return (int)dice.roll(1, hi - lo + 1, lo - 1);
    }

// ---- seaStep ----
void AppState::seaStep(){
        if (mode != MODE_SEA || !party.alive()) return;
        // R127: the p.190 waterborne tables - a surface
        // voyage rolls waterborne encounters (R70 had wired
        // the R60 underwater set; the coaster sails the top)
        dm::DungeonEncounter e = dm::rollWaterborneEncounter(
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
        if (e.key == "buccaneer" || e.key == "merchant"
            || e.key == "caveman") {
            // R127: the waterborne Men rows - sails on the
            // horizon, not fins below the keel
            snprintf(buf, sizeof buf,
                     "Sail ho! %d %ss close on the coaster - "
                     "steel follows!", e.count, e.key.c_str());
        } else if (e.count == 1) {
            snprintf(buf, sizeof buf,
                     "It rises from the waves - a wild %s "
                     "attacks the ship!", e.key.c_str());
        } else {
            snprintf(buf, sizeof buf,
                     "%d wild %ss attack the ship!",
                     e.count, e.key.c_str());
        }
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
        int miles = seaMilesPerDay();   // R123: 50
        sea.milesOut += miles;
        char buf[112];
        snprintf(buf, sizeof buf,
                 "Day %d at sea - the %s. The coaster runs "
                 "%d miles (%d from port).",
                 sea.day,
                 sea.daysOut < kSeaCoastalDays
                     ? "coastal waters" : "open sea",
                 miles, sea.milesOut);
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
        int miles = seaMilesPerDay();   // R123: 50
        sea.milesOut -= miles;
        if (sea.milesOut < 0) sea.milesOut = 0;
        char buf[112];
        snprintf(buf, sizeof buf,
                 "Day %d - the sea road home. The coaster "
                 "logs %d miles (%d from port).",
                 sea.day, miles, sea.milesOut);
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
        log.add("[1] by day  [2] by night  [P] pick "
                "pockets  [B] back to town.");
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
        // fiction civilians - flavor only; R146: the
        // p.191 drunk identity and p.192 harlot type
        // subtables dress the two keyed rows
        std::string line = cityFlavor(e.key.c_str());
        if (e.key == "drunk") {
            line = std::string("A drunk ") +
                dm::cityDrunkKind(
                    (int)dice.roll(1, 100, 0)) +
                " sings loud in a doorway.";
        } else if (e.key == "harlot") {
            line = std::string("A ") +
                dm::cityHarlotKind(
                    (int)dice.roll(1, 100, 0)) +
                " waves from a doorway.";
        } else if (e.key == "noble") {
            // R174: the noble gender coin and the
            // noblewoman sedan-chair detail
            std::string gender = dm::cityNobleKind(
                (int)dice.roll(1, 100, 0));
            if (gender == "noblewoman") {
                std::string ride = dm::cityNoblewomanSedan(
                    (int)dice.roll(1, 100, 0));
                if (ride == "sedan chair") {
                    line = "A noblewoman passes in a sedan "
                        "chair, her carriers and guards "
                        "about her.";
                } else {
                    line = "A noblewoman passes on foot "
                        "with servants and guards.";
                }
            } else {
                line = "A nobleman passes with his "
                    "retainers and guards.";
            }
        } else if (e.key == "ruffian") {
            // R174: the 1-in-4 half-orc/humanoid note
            std::string kind = dm::cityRuffianKind(
                (int)dice.roll(1, 100, 0));
            if (kind != "human") {
                line = std::string("Ruffians melt into an "
                    "alley - one in four is ") + kind +
                    " stock.";
            }
        }
        log.add(line);
    }

// ---- cityPickPockets ----
// R303: the printed pick pockets roll (the
// PHB Notes Regarding Thief Functions): one
// percentile at or below the chance CUT 5
// percent per victim level above the 3rd; a
// fail 21 percent or more above the chance
// means the passerby notices. JUDGMENTS (the
// print leaves them open): the passerby
// reads a d4 trade and a d6 level; the
// purse reads the R190 starting money dice
// of that trade (the engine only prints
// money by class - the printed random item
// has no stranger inventory); a noticed
// attempt draws the watch - a fine of a
// tenth of the company purse (the R133
// greed convention).
void AppState::cityPickPockets(){
        if (mode != MODE_CITY) return;
        if (!party.alive()) return;
        const Character* thief = nullptr;
        for (const auto& c : party.members)
            if (c.hp > 0 && c.classIndex == 3) {
                thief = &c;
                break;
            }
        if (!thief) {
            log.add("No thief walks the streets "
                    "with you.");
            return;
        }
        // the passerby: trade and level
        int vcls = (int)dice.roll(1, 4, 0) - 1;
        int vlevel = (int)dice.roll(1, 6, 0);
        // the printed percentile draw (tenths)
        int roll = (int)rng.below(1000);
        int chance = rules::thfPocketsChanceTenths(
            thief->level, thief->race,
            (int)thief->abilities.dex, vlevel);
        if (rules::thfPercentileSucceeds(roll, chance)) {
            // success: the purse lift (the R190
            // starting money roll of the trade)
            int purse = (int)dice.roll(
                rules::startingMoneyDiceCount(vcls),
                rules::startingMoneyDieFaces(vcls), 0)
                * rules::startingMoneyMultiplier(vcls);
            party.gold += purse;
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%s lifts %d gp from a passerby.",
                     thief->name.c_str(), purse);
            log.add(buf);
            return;
        }
        if (rules::thfPocketsVictimNotices(roll, chance)) {
            // noticed: the watch fine (a tenth)
            int fine = party.gold / 10;
            party.gold -= fine;
            char buf[96];
            snprintf(buf, sizeof buf,
                     "A passerby notices the attempt - "
                     "the watch takes %d gp.", fine);
            log.add(buf);
            return;
        }
        log.add("The lift fails, but nobody notices.");
    }
