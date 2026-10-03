#include "appstate.h"

// ---- partyActors ----
std::vector<ai::Actor> AppState::partyActors() const{
        std::vector<ai::Actor> v;
        for (const auto& c : party.members)
            if (c.hp > 0)
                v.push_back(c.toActor());
        // R44: the henchman fights alongside the roster
        if (party.henchmanPresent && party.henchmanHp > 0)
            v.push_back(party.henchmanActor());
        return v;
    }

// ---- beginCombat ----
void AppState::beginCombat(std::vector<ai::Actor> foes, int roomIndex, const std::string& monsterKey){
        // R37: mark missile-armed monsters (MM convention: goblins
        // short bow, kobolds sling). The Lua registry data carries
        // no ranged flag, so the app owns this list - verification
        // debt if the Lua keys ever change.
        // R42: also seed rangedRounds from the weapon's short
        // range band (PHB p.39: short bow 50' = 5 bands, sling
        // 50' = 5 bands) - volley rounds before melee closes.
        for (auto& m : foes) {
            if (!m.isCharacter &&
                (monsterKey == "goblin" ||
                     monsterKey == "kobold" ||
                     monsterKey == "hobgoblin")) {   // R44: MM bows
                m.monsterRanged = true;
                m.rangedRounds = 5;   // 50' short range, 10' bands
            }
            // R46: psionic monsters (the registry schema has no
            // psionics field - the app owns the key list, R37
            // pattern)
            if (!m.isCharacter && monsterKey == "mind_flayer")
                m.psionic = true;
        }
        combat.start(partyActors(), std::move(foes),
                     rng.below(0x7FFFFFFF));
        // R141: the opening range is geometry - a room fight
        // opens at the chamber's longest interior dimension
        // (10' bands, floored at the 50' corridor convention,
        // capped at 120'); wandering and overland fights keep
        // the 50' opening (no room to measure)
        if (roomIndex >= 0 &&
            roomIndex < (int)occupancy.rooms.size()) {
            int grIdx = occupancy.rooms[roomIndex].roomIndex;
            if (grIdx >= 0 &&
                grIdx < (int)dungeon.rooms.size()) {
                const dm::GeneratedRoom& gr =
                    dungeon.rooms[grIdx];
                int bands = rules::engagementBands(gr.w,
                                                   gr.h);
                combat.encounter->setOpeningBands(bands);
                if (bands > 5) {
                    char dbuf[96];
                    snprintf(dbuf, sizeof dbuf,
                             "The chamber yawns - the foes "
                             "wait %d' away.", bands * 10);
                    log.add(dbuf);
                }
            }
        }
        combat.encounter->setQuaffHook(
            [this](ai::Actor& drinker) {
                if (party.potions <= 0) {
                    log.add("The potion satchel is empty!");
                    return;
                }
                int heal = (int)dice.roll(2, 4, 2);
                int before = drinker.hp;
                drinker.hp += heal;
                if (drinker.hp > drinker.maxHp)
                    drinker.hp = drinker.maxHp;   // cap at max HP
                --party.potions;
                char buf[96];
                snprintf(buf, sizeof buf,
                         "%s quaffs a potion (+%d hp, now %d/%d).",
                         drinker.name.c_str(), drinker.hp - before,
                         drinker.hp, drinker.maxHp);
                log.add(buf);
            });
        combatReturnMode = mode;   // R68
        combatRoomIndex = roomIndex;
        combatMonsterKey = monsterKey;
        mode = MODE_COMBAT;
    }

// ---- quaffExplore ----
void AppState::quaffExplore(){
        if (mode != MODE_EXPLORE) return;
        if (party.potions <= 0) {
            log.add("No potions left.");
            return;
        }
        Character* best = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (!best || (c.maxHp - c.hp) > (best->maxHp - best->hp))
                best = &c;
        }
        if (!best) return;
        if (best->hp >= best->maxHp) {
            log.add("No one needs healing.");
            return;
        }
        int heal = (int)dice.roll(2, 4, 2);
        int before = best->hp;
        best->hp += heal;
        if (best->hp > best->maxHp) best->hp = best->maxHp;
        --party.potions;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "%s quaffs a potion (+%d hp, now %d/%d, %d left).",
                 best->name.c_str(), best->hp - before,
                 best->hp, best->maxHp, party.potions);
        log.add(buf);
        // R90: drinking in the halls costs a turn - and the
        // turn can draw a wanderer (search parity)
        turnCount += 1;
        if (dm::wanderCheck(dice, wander))
            spawnWanderingEncounter();
    }

// ---- combatQuaff ----
void AppState::combatQuaff(){
        if (mode != MODE_COMBAT || !combat.encounter || combat.over)
            return;
        if (party.potions <= 0) {
            log.add("No potions left.");
            return;
        }
        combat.encounter->requestDrink(combat.activeMember);
    }

// ---- combatShoot ----
void AppState::combatShoot(){
        if (mode != MODE_COMBAT || !combat.encounter || combat.over)
            return;
        const auto& partyActors = combat.encounter->party();
        if (combat.activeMember < 0 ||
            combat.activeMember >= (int)partyActors.size())
            return;
        if (!partyActors[combat.activeMember].hasRangedWeapon()) {
            log.add("That member has no missile weapon.");
            return;
        }
        // R43: the range must still be open - once the foes have
        // closed, only melee (or a hurled weapon) serves
        if (!combat.encounter->rangeOpen()) {
            log.add("The foes are upon you - no time for "
                    "missiles!");
            return;
        }
        // R35: dry quiver - nothing left to loose
        if (partyActors[combat.activeMember].missileAmmo <= 0) {
            log.add("That member's quiver is empty.");
            return;
        }
        combat.encounter->requestShoot(combat.activeMember);
        log.add("Missiles readied - [space] to resolve the round.");
    }

// ---- combatThrow ----
void AppState::combatThrow(){
        if (mode != MODE_COMBAT || !combat.encounter || combat.over)
            return;
        const auto& partyActors = combat.encounter->party();
        if (combat.activeMember < 0 ||
            combat.activeMember >= (int)partyActors.size())
            return;
        if (!partyActors[combat.activeMember].meleeThrowable()) {
            log.add("That member has nothing to hurl.");
            return;
        }
        combat.encounter->requestThrow(combat.activeMember);
        log.add("Weapon readied to hurl - [space] to resolve the round.");
    }

// ---- rollSpawnContext ----
monsters::xp::SpawnContext AppState::rollSpawnContext(const monsters::MonsterDef* def){
        monsters::xp::SpawnContext ctx;
        if (!def) return ctx;
        int lo = rangeLo(def->hitDiceText);
        int hi = rangeHi(def->hitDiceText);
        if (lo < 1) lo = def->hitDiceNum;
        if (hi < lo) hi = lo;
        const std::string& src = def->xpSource;
        if (src == "age_bracket") {
            ctx.ageBracket = 1 + (int)dice.roll(1, 8, 0);   // age 1-8
            ctx.hd = lo + (int)rng.below((uint32_t)(hi - lo + 1));
        } else if (src == "by_head_count") {
            ctx.heads = 4 + (int)dice.roll(1, 8, 0);         // 5-12
            ctx.hd = ctx.heads;
        } else if (src == "by_hit_dice") {
            ctx.hd = lo + (int)rng.below((uint32_t)(hi - lo + 1));
        }
        // by_level: 0-level default; the dungeon generator assigns
        // class/levels when it starts placing leaders (R51)
        return ctx;
    }

// ---- hpPerDieFor ----
int AppState::hpPerDieFor(const monsters::MonsterDef* def, const monsters::xp::SpawnContext& c){
        if (!def) return 0;
        if (def->xpSource == "age_bracket")  return c.ageBracket;
        if (def->xpSource == "by_head_count") return 8;
        return 0;
    }

// ---- rollDmEncounter ----
dm::DungeonEncounter AppState::rollDmEncounter(){
        return dm::rollDungeonEncounter(registry, dice,
            (int)dice.roll(1, 20, 0),
            (int)dice.roll(1, 100, 0),
            (int)dice.roll(1, 100, 0),
            dungeonLevel);
    }

// ---- buildFoesFromDm ----
std::vector<ai::Actor> AppState::buildFoesFromDm(const dm::DungeonEncounter& e){
        std::vector<ai::Actor> foes;
        if (e.key.empty() || e.count <= 0) return foes;
        const monsters::MonsterDef* def = registry.find(e.key);
        if (!def) return foes;
        foeCtxs.clear();
        for (int i = 0; i < e.count; ++i) {
            monsters::xp::SpawnContext ctx = rollSpawnContext(def);
            if (e.headsLo > 0 && e.headsHi >= e.headsLo) {
                ctx.heads = e.headsLo + (int)rng.below(
                    (uint32_t)(e.headsHi - e.headsLo + 1));
                ctx.hd = ctx.heads;   // by_head_count: heads = HD
            }
            if (e.ageLo > 0 && e.ageHi >= e.ageLo) {
                ctx.ageBracket = e.ageLo + (int)rng.below(
                    (uint32_t)(e.ageHi - e.ageLo + 1));
            }
            foeCtxs.push_back(ctx);
            foes.push_back(registry.toActor(e.key, dice, -1,
                                            ctx.hd,
                                            hpPerDieFor(def, ctx)));
        }
        return foes;
    }

// ---- encFromRoom ----
dm::DungeonEncounter AppState::encFromRoom(const RoomOccupant& r){
        dm::DungeonEncounter e;
        e.key = r.monsterKey;
        e.count = r.count;
        e.headsLo = r.headsLo; e.headsHi = r.headsHi;
        e.ageLo = r.ageLo;     e.ageHi = r.ageHi;
        return e;
    }

// ---- kitNpc ----
void AppState::kitNpc(ai::Actor& a, const dm::PartyMember& m){
        using namespace items;
        if (m.manAtArms) {
            a.armor.id = ARMOR_STUDDED_LEATHER;
            a.weapon.id = WPN_SPEAR;
            a.shield = false;
            return;
        }
        switch (m.classIndex) {
            case rules::CLASS_MAGIC_USER:
                a.armor.id = ARMOR_NONE_EQUIPPED;
                a.weapon.id = WPN_QUARTERSTAFF;
                a.shield = false;
                break;
            case rules::CLASS_CLERIC:
                a.armor.id = m.level >= 2 ? ARMOR_PLATE
                                          : ARMOR_CHAIN_MAIL;
                a.weapon.id = WPN_MACE;
                a.shield = true;
                break;
            case rules::CLASS_THIEF:
                a.armor.id = ARMOR_LEATHER;
                a.weapon.id = WPN_SHORT_SWORD;
                a.shield = false;
                break;
            default:   // fighter group
                a.armor.id = m.level >= 2 ? ARMOR_PLATE
                                          : ARMOR_CHAIN_MAIL;
                a.weapon.id = WPN_LONG_SWORD;
                a.shield = true;
                break;
        }
    }

// ---- npcName ----
std::string AppState::npcName(const dm::PartyMember& m, int index){
        const char* base = "Adventurer";
        switch (m.classIndex) {
            case rules::CLASS_MAGIC_USER: base = "Conjurer";   break;
            case rules::CLASS_CLERIC:     base = "Acolyte";    break;
            case rules::CLASS_THIEF:      base = "Cutpurse";   break;
            default:                      base = "Sellsword";  break;
        }
        char buf[32];
        if (m.manAtArms)
            snprintf(buf, sizeof buf, "Man-at-arms %d", index);
        else if (m.henchman)
            snprintf(buf, sizeof buf, "Hireling %d", index);
        else
            snprintf(buf, sizeof buf, "%s %d", base, index);
        return buf;
    }

// ---- buildFoesFromParty ----
std::vector<ai::Actor> AppState::buildFoesFromParty(const dm::CharacterParty& party){
        std::vector<ai::Actor> foes;
        if (party.empty()) return foes;
        foeCtxs.clear();
        int index = 1;
        for (const auto& m : party.members) {
            ai::Actor a;
            a.team = 1;
            a.isCharacter = true;
            a.classIndex = m.classIndex;
            a.level = m.level > 0 ? m.level : 1;   // matrices need 1+
            a.name = npcName(m, index++);
            kitNpc(a, m);
            // R55: DMG p.176-177 magic items - the rolled
            // pluses land on the equipped gear (best-of, per the
            // ladder rolls in dm::rollCharacterParty)
            // DMG p.177: items must be SUITABLE to the individual
            // (the book's own selection rule) - an MU wears
            // no armor/shield, and only shield-allowed classes
            // carry a magic shield (rules::shieldAllowed)
            if (m.wpnPlus > 0) a.weapon.plus = m.wpnPlus;
            if (m.armPlus > 0 &&
                m.classIndex != rules::CLASS_MAGIC_USER)
                a.armor.plus = m.armPlus;
            if (m.shdPlus > 0 &&
                rules::shieldAllowed(m.classIndex)) {
                a.shield = true;      // a +N shield implies a shield
                a.shieldPlus = m.shdPlus;
            }
            // rngPlus: NPC foes carry no ranged slot this round
            // (documented simplification - R28 missile hooks
            // are party-driven); missile pluses re-roll as flavor
            // R57: PERSONAE-grade abilities (DMG p.87 + p.176):
            // 3d6 per score, then race adjustments (race rolled
            // on the p.176 table: 01-25 dwarf, 26-50 elf, 51-60
            // gnome, 61-85 half-elf, 86-95 halfling, 96-00
            // half-orc) and class adjustments per the p.87 table.
            // Multi-class (p.176, ~20% of non-humans) is beyond
            // the engine's four single classes - race
            // adjusts abilities only (documented simplification).
            int ab[6];
            for (int i = 0; i < 6; ++i)
                ab[i] = (int)dice.roll(3, 6, 0);
            enum { S_, I_, W_, D_, C_, H_ };  // str int wis dex con cha
            int raceRoll = (int)dice.roll(1, 100, 0);
            if (raceRoll <= 25) {            // dwarf
                ab[S_] += 1; ab[C_] += 1; ab[H_] -= 1;
            } else if (raceRoll <= 50) {      // elf
                ab[I_] += 1; ab[D_] += 1;
            } else if (raceRoll <= 60) {      // gnome
                ab[W_] += 1; ab[C_] += 1; ab[H_] -= 1;
            } else if (raceRoll <= 95 && raceRoll >= 86) {  // halfling
                ab[D_] += 1; ab[C_] += 1;
            }   // half-elf / half-orc: no printed adjustment
            if (m.level < 1) {
                // p.87 Occupation: Mercenary (level 0) -
                // STR +1, CON +3 (men-at-arms)
                ab[S_] += 1; ab[C_] += 3;
            } else {
                // p.87 Class table (in addition to the PHB note;
                // additive here, the engine has no minimums pass)
                switch (m.classIndex) {
                    case rules::CLASS_CLERIC:
                        ab[W_] += 2; break;
                    case rules::CLASS_MAGIC_USER:
                        ab[I_] += 2; ab[D_] += 1; break;
                    case rules::CLASS_THIEF:
                        ab[D_] += 2; ab[I_] += 1; break;
                    default:   // fighter group (fighter/paladin/
                        ab[S_] += 2; ab[C_] += 1; break;  // ranger)
                }
            }
            for (int i = 0; i < 6; ++i) {
                if (ab[i] > 18) ab[i] = 18;   // normal limits
                if (ab[i] < 3) ab[i] = 3;
            }
            a.str = (uint8_t)ab[S_]; a.intel = (uint8_t)ab[I_];
            a.wis = (uint8_t)ab[W_]; a.dex = (uint8_t)ab[D_];
            a.con = (uint8_t)ab[C_]; a.cha = (uint8_t)ab[H_];
            // exceptional strength: fighter group at STR 18
            if (m.classIndex == rules::CLASS_FIGHTER &&
                a.str == 18) {
                a.exStr.has = true;
                a.exStr.pct = rules::rollExceptionalStrength(dice);
            }
            // hp: the canonical per-level roll (R4b signature)
            // with the PERSONAE Con adjustment per die
            int conAdj = rules::conHPAdjustment(m.classIndex, a.con);
            int hp = 0;
            if (m.level < 1) {
                hp = (int)dice.roll(1, 6, 0);   // 0-level man
            } else {
                for (int lv = 1; lv <= m.level; ++lv)
                    hp += rules::rollHitPoints(m.classIndex, lv,
                                               conAdj, dice);
            }
            if (m.level < 1 && hp < 4) hp = 4;   // p.87: mercenary min
            if (hp < 1) hp = 1;
            a.hp = a.maxHp = hp;
            // DMG p.176: character parties do not check morale -
            // play them as player characters
            a.morale = dm::MORALE_FANATIC;
            // spell slots (R54: the foe AI casts - see
            // ai/actor.cpp foeSpellChoice; slots deplete)
            spells::SpellClass sc = m.classIndex ==
                rules::CLASS_MAGIC_USER ? spells::SPELL_MU
                : m.classIndex == rules::CLASS_CLERIC
                    ? spells::SPELL_CLERIC : spells::SPELL_MU;
            if (m.level > 0 &&
                (m.classIndex == rules::CLASS_MAGIC_USER ||
                 m.classIndex == rules::CLASS_CLERIC)) {
                // R131: all nine columns - a name-level foe
                // caster spawns with 7th-9th circle slots
                for (int lv = 0; lv < 9; ++lv)
                    a.slotsByLevel[lv] = spells::spellSlots(
                        sc, a.level, lv + 1);
                if (m.classIndex == rules::CLASS_MAGIC_USER) {
                    a.knownSpells.push_back(spells::MU_MAGIC_MISSILE);
                    a.knownSpells.push_back(spells::MU_SLEEP);
                    a.knownSpells.push_back(spells::MU_SHIELD);
                    // R54: the deep-dungeon conjurer's heavier
                    // artillery (3rd-level slots at MU 5+)
                    a.knownSpells.push_back(spells::MU_FIREBALL);
                    a.knownSpells.push_back(spells::MU_LIGHTNING_BOLT);
                }
            }
            monsters::xp::SpawnContext ctx;   // R53: by_level context
            ctx.classIndex = m.classIndex;
            ctx.level = m.level;   // 0 = the 0-level man ladder
            ctx.conAdj = conAdj;  // R57: real Con, xp parity
            foeCtxs.push_back(ctx);
            foes.push_back(a);
        }
        return foes;
    }

// ---- spawnWanderingEncounter ----
void AppState::spawnWanderingEncounter(){        if (mode == MODE_COMBAT) return;
        if (!party.alive()) return;

        // R52: the real DMG Appendix C roll - Determination
        // Matrix, level table, subtables (Human/Dragon/etc.).
        // An empty key is NO ENCOUNTER (or an R53 re-roll row).
        // R142: the sample dungeon - the book's own wandering
        // table (p.96): a d4 pick from the right column -
        // the monastery halls, or the crypts when the
        // company walks the crypt wing - count rolled
        // inside the printed range. R143: crypt row two is
        // the book's evil 3rd-level cleric and his 2
        // hobgoblins: the cleric is built as a Character
        // foe (the engine's NPC kit) beside them; the book
        // gives the crypt column as straight encounters,
        // so no reaction gate on this row (documented).
        dm::DungeonEncounter e;
        if (seed == dm::sampledungeon::kSampleSeed) {
            bool crypt = dm::sampledungeon::inCrypts(
                party.x, party.y);
            int roll = 1 + (int)rng.below(4);
            if (crypt && roll == 2) {
                dm::CharacterParty cp;
                dm::PartyMember cm;
                cm.classIndex = rules::CLASS_CLERIC;
                cm.level = 3;
                cp.members.push_back(cm);
                std::vector<ai::Actor> foes =
                    buildFoesFromParty(cp);
                dm::DungeonEncounter hg;
                hg.key = "hobgoblin";
                hg.count = 2;
                std::vector<ai::Actor> guards =
                    buildFoesFromDm(hg);
                foes.insert(foes.end(),
                            guards.begin(), guards.end());
                if (foes.empty()) return;
                log.add("An evil cleric and 2 hobgoblins "
                        "stalk the crypts!");
                beginCombat(std::move(foes), -1,
                           "hobgoblin");
                return;
            }
            dm::sampledungeon::SampleWanderingRow w =
                dm::sampledungeon::sampleWandering(
                    crypt, roll);
            e.key = w.key;
            e.count = w.lo + (int)rng.below(
                (uint32_t)(w.hi - w.lo + 1));
        } else {
            e = rollDmEncounter();
        }
        if (e.isParty) {
            // R53: a Character Subtable party (DMG p.176)
            std::vector<ai::Actor> foes = buildFoesFromParty(e.party);
            if (foes.empty()) return;
            // R58: DMG p.63 Encounter Reactions + p.176
            // Confrontation - the strangers react before steel
            // is drawn. Charisma adjustment follows the engine's
            // best-living-Cha spokesman convention (henchman
            // hire, R44); the p.63 loyalty adjustment is not
            // modeled (documented simplification). The p.176
            // "never join with adventurers" rule keeps friendly
            // outcomes pass-by; R62 adds small favors - friendly
            // parties sometimes part with a potion or a coin
            // pouch (no printed table: fiction extension). Gift
            // gold earns NO xp - p.86 awards xp for treasure
            // taken from a challenge; a gift is freely given.
            // R62 also colors the meeting with the NPC party's
            // race (DMG p.192 race check, fiction-only).
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
            // R62: the NPC party's racial makeup colors the
            // meeting - a wholly single-race party of dwarves
            // reads as "dwarven adventurers" (p.192 fiction)
            const char* racePrefix = "";
            {
                int byRace[7] = {0};
                int total = 0;
                for (const auto& m : e.party.members) {
                    if (m.manAtArms) continue;
                    ++byRace[m.race];
                    ++total;
                }
                for (int r = 1; r < 7; ++r)
                    if (total > 0 && byRace[r] == total) {
                        racePrefix = dm::npcRaceAdjective(r);
                        break;
                    }
            }
            switch (react) {
            case dm::PartyReaction::ViolentlyHostile:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers attack without a "
                         "word!", racePrefix, e.count);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            case dm::PartyReaction::Hostile:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers size you up and "
                         "attack!", racePrefix, e.count);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            case dm::PartyReaction::UncertainNegative:
                // p.63: 55% prone toward negative - they may
                // still strike, or let the party pass
                if ((int)dice.roll(1, 100, 0) <= 55) {
                    snprintf(buf, sizeof buf,
                             "%s%d wary adventurers draw "
                             "steel!", racePrefix, e.count);
                    log.add(buf);
                    beginCombat(std::move(foes), -1, e.key);
                    return;
                }
                log.add("The adventurers eye you warily, "
                        "then let you pass.");
                return;
            case dm::PartyReaction::Neutral:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers pass by, "
                         "uninterested.", racePrefix, e.count);
                log.add(buf);
                return;
            case dm::PartyReaction::UncertainPositive:
                // p.63: 55% prone toward positive - a hail
                // instead of silence
                if ((int)dice.roll(1, 100, 0) <= 55)
                    log.add("The adventurers hail you "
                            "and move on.");
                else
                    log.add("The adventurers nod and pass by.");
                return;
            case dm::PartyReaction::Friendly:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers hail you, share "
                         "word of the dungeon, and depart.",
                         racePrefix, e.count);
                log.add(buf);
                // R62: a friendly party may part with a small
                // favor (d6: 1 potion, 2 coin pouch, else words)
                {
                    int favor = (int)dice.roll(1, 6, 0);
                    if (favor == 1) {
                        ++party.potions;
                        log.add("One presses a potion of "
                                "healing on you before going.");
                    } else if (favor == 2) {
                        int gift = (int)dice.roll(2, 6, 0) * 10
                                 * dungeonLevel;
                        party.gold += gift;
                        party.delveGold += gift;
                        snprintf(buf, sizeof buf,
                                 "They toss a pouch of %d gp "
                                 "to your company!", gift);
                        log.add(buf);
                    }
                }
                return;
            case dm::PartyReaction::Enthusiastic:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers greet you warmly "
                         "and warn of dangers ahead!",
                         racePrefix, e.count);
                log.add(buf);
                // R62: enthusiastic parties favor more often
                // (d6: 1-2 potion, 3 coin pouch, else words)
                {
                    int favor = (int)dice.roll(1, 6, 0);
                    if (favor <= 2) {
                        ++party.potions;
                        log.add("One presses a potion of "
                                "healing on you before going.");
                    } else if (favor == 3) {
                        int gift = (int)dice.roll(2, 6, 0) * 10
                                 * dungeonLevel;
                        party.gold += gift;
                        party.delveGold += gift;
                        snprintf(buf, sizeof buf,
                                 "They toss a pouch of %d gp "
                                 "to your company!", gift);
                        log.add(buf);
                    }
                }
                return;
            }
            return;
        }
        if (e.key.empty() || e.count <= 0) return;
        std::vector<ai::Actor> foes = buildFoesFromDm(e);
        if (foes.empty()) return;

        // R120: the parley gate rides the wandering roll
        // too (DMG p.63-64) - non-hostile bands pass by
        int chaAdj = 0;
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            int adj = rules::chaReactionAdj(c.abilities.cha);
            if (adj > chaAdj) chaAdj = adj;
        }
        dm::Reaction react = dm::rollReaction(dice, chaAdj);
        if (!dm::reactionAttacks(react)) {
            char pbuf[96];
            if (e.count == 1)
                snprintf(pbuf, sizeof pbuf,
                         "A wandering %s eyes the company "
                         "and moves on.", e.key.c_str());
            else
                snprintf(pbuf, sizeof pbuf,
                         "%d wandering %ss eye the company "
                         "and move on.", e.count, e.key.c_str());
            log.add(pbuf);
            return;
        }

        char buf[96];
        if (e.count == 1)
            snprintf(buf, sizeof buf, "A wandering %s attacks!",
                     e.key.c_str());
        else
            snprintf(buf, sizeof buf, "%d wandering %ss attack!",
                     e.count, e.key.c_str());
        log.add(buf);

        beginCombat(std::move(foes), -1, e.key);
    }

// ---- playerFlee ----
void AppState::playerFlee(){
        if (mode != MODE_COMBAT || !combat.encounter || combat.over)
            return;
        combat.requestFlee();
        combat.step();
        if (combat.over) endCombat();
    }

// ---- endCombat ----
void AppState::endCombat(){
        // R83: a teleport escape - no spoils, and the company
        // lands in town (read before the encounter resets)
        bool teleported = combat.encounter &&
                          combat.encounter->teleported();
        if (combat.encounter) {
            // R24: sync fight results back to the roster BY NAME
            // (hp, level - energy drain can strip levels)
            for (const auto& a : combat.encounter->party()) {
                for (auto& c : party.members) {
                    if (c.name != a.name) continue;
                    c.hp = a.hp;
                    c.maxHp = a.maxHp;
                    c.level = a.level;
                    // R34: spent slots persist (per-day tracking)
                    // R131: all nine columns ride home spent
                    for (int lv = 0; lv < 9; ++lv)   // R131
                        c.slotsByLevel[lv] = a.slotsByLevel[lv];
                    // R35: spent ammo persists; R80: the bundle
                    // composition is consumed front-first to match
                    // the shots the actor fired this fight
                    quiverConsumeShots(
                        c.quiver, c.missileAmmo - a.missileAmmo);
                    c.missileAmmo = a.missileAmmo;
                    // R115: the stolen years land on the
                    // roster (DMG p.14 - a member hasted in
                    // the fight aged in it)
                    if (a.magicAgingYears > 0) {
                        applyMagicalAging(c, party.careerDays,
                                          a.magicAgingYears);
                        log.add(c.name + " feels the stolen " +
                                "years - magic's price.");
                    }
                    break;
                }
                // R44: the henchman syncs back too (hp and any
                // energy-drained levels)
                if (party.henchmanPresent &&
                    a.name == party.henchmanName) {
                    party.henchmanHp = a.hp;
                    party.henchmanMaxHp = a.maxHp;
                    party.henchmanLevel = a.level;
                    if (party.henchmanHp <= 0) {
                        log.add(party.henchmanName +
                                " has fallen in the fight.");
                        party.henchmanPresent = false;
                    }
                }
            }

            if (!teleported)   // R83: no spoils from an escape
                awardVictory();

            const char* outcome = "?";
            switch (combat.lastResult) {
                case 0: outcome = "Victory!"; break;
                case 1: outcome = "The party has fallen..."; break;
                case 2: outcome = "You fled."; break;
                case 3: outcome = "The monsters fled."; break;
                case 4: outcome = "The company teleports away!"; break;
                default: outcome = "The fight ends."; break;
            }
            log.add(outcome);

            if (combat.lastResult == 1) {
                log.add("GAME OVER - press N to roll a new party.");
            } else if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new party.");
            }
        }
        // R119: forced rest (DMG p.38) - the fight spent
        // them; a turn of rest is owed once back on the
        // trail (a wiped company demands nothing)
        if (party.alive()) {
            restOwed = true;
            mustRest = true;
            log.add("The company is winded - a rest is owed. [R]");
        }
        combat.encounter.reset();
        mode = combatReturnMode;   // R68: back to the trail
        if (teleported) {   // R83: the spell lands the company
            mode = MODE_TOWN;   // in town, not back on the trail
            billTownVisit();
        }
        if (mode == MODE_OVERLAND) checkArrivedHome();
    }
