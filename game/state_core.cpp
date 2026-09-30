#include "appstate.h"

// ---- newDungeon ----
void AppState::newDungeon(uint64_t s){
        seed = s;
        dungeon = dm::generateDungeon(s);
        map = dungeon.map;
        occupancy.init(dungeon);
        // R24: no formDefault â the roster comes from creation
        party.x = dungeon.entryX;
        party.y = dungeon.entryY;
        cam.follow(party);
        turnCount = 0;
        rng.seed(s * 7919 + 13);

        placeStairs();
        populateRooms();
        placeSecretDoors();   // R45

        char buf[96];
        snprintf(buf, sizeof buf,
                 "Level %d: %d rooms, %d occupied.",
                 dungeonLevel, (int)dungeon.rooms.size(),
                 countOccupied());
        log.add(buf);
    }

// ---- beginDelve ----
void AppState::beginDelve(){
        party.formed = true;
        creation.done = true;
        mode = MODE_EXPLORE;
        newDungeon(1);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "The party of %d descends into the dungeon.",
                 (int)party.members.size());
        log.add(buf);
    }

// ---- resetToCreation ----
void AppState::resetToCreation(){
        party = Party{};
        // R69: CreationState is non-copyable (its Dice holds a
        // reference to creationRng) — reset fields explicitly
        // instead of assigning a fresh temporary.
        creation.stage = CR_ROLL;
        creation.classPick = 0;
        creation.nameBuf.clear();
        creation.partySizeCap = PARTY_DEFAULT;
        creation.done = false;
        creation.rollFresh();
        dungeonLevel = 1;
        mode = MODE_CREATE;
        log.add("The party is no more. Roll a new company.");
    }

// ---- saveGame ----
bool AppState::saveGame(){
        if (!party.formed || party.members.empty()) {
            log.add("No company to save yet.");
            return false;
        }
        FILE* f = fopen(SAVE_FILE(), "w");
        if (!f) {
            log.add("Cannot open adnd1.sav for writing!");
            return false;
        }
        fprintf(f, "ADND1 %d\n", 1);   // format version
        fprintf(f, "party %d\n",
                (int)party.members.size());
        fprintf(f, "gold %d kills %d potions %d depth %d\n",
                party.gold, party.kills, party.potions,
                dungeonLevel);
        // R43: the training queue (v1 saves lack this line â the
        // loader treats it as optional)
        fprintf(f, "training %d",
                (int)party.pendingTraining.size());
        for (int i : party.pendingTraining)
            fprintf(f, " %d", i);
        fprintf(f, "\n");
        // R44: career extras (optional lines, v1-compatible â
        // the loader's optional-tag chain treats each as absent
        // in older saves)
        fprintf(f, "stronghold %d %d\n",
                party.strongholdBuilt ? 1 : 0,
                party.strongholdOwner);
        if (party.henchmanPresent)
            fprintf(f, "henchman %d %d %d %d %d %d %d %s\n",
                    party.henchmanHp, party.henchmanMaxHp,
                    party.henchmanLevel, party.henchmanLoyalty,
                    party.henchmanXp, party.henchmanPurse,
                    party.delveGold,
                    party.henchmanName.c_str());
        else
            fprintf(f, "henchman 0\n");
        fprintf(f, "idscrolls %d\n", party.identifyScrolls);
        fprintf(f, "items %d",
                (int)party.unidentified.size());
        for (const auto& it : party.unidentified)
            fprintf(f, " %d %d", it.kind, it.plus);
        fprintf(f, "\n");
        for (const auto& c : party.members) {
            fprintf(f,
                "member %s %d %d %d %d %d\n",
                c.name.c_str(), c.classIndex, c.xp, c.level,
                c.hp, c.maxHp);
            fprintf(f, "abil %d %d %d %d %d %d %d %d\n",
                (int)c.abilities.str, (int)c.abilities.int_,
                (int)c.abilities.wis,  (int)c.abilities.dex,
                (int)c.abilities.con,  (int)c.abilities.cha,
                c.exStr.has ? 1 : 0, c.exStr.pct);
            fprintf(f, "gear %d %d %d %d %d %d %d\n",
                (int)c.weapon.id, c.weapon.plus,
                (int)c.rangedWeapon.id, c.rangedWeapon.plus,
                (int)c.armor.id, c.armor.plus,
                c.shield ? 1 : 0);
            // R56: the magic-shield enchant (nonzero only â
            // v1 saves carry no line and load as 0)
            if (c.shieldPlus > 0)
                fprintf(f, "shieldplus %d\n", c.shieldPlus);
            // R33: the MU spellbook (one line per MU; other
            // classes write nothing â v1 saves stay readable)
            if (c.classIndex == 1) {
                fprintf(f, "spells %d",
                        (int)c.knownSpells.size());
                for (int s : c.knownSpells)
                    fprintf(f, " %d", s);
                fprintf(f, "\n");
            }
        }
        fclose(f);
        log.add("The company is recorded (adnd1.sav).");
        return true;
    }

// ---- loadGame ----
bool AppState::loadGame(){
        FILE* f = fopen(SAVE_FILE(), "r");
        if (!f) {
            log.add("No adnd1.sav found.");
            return false;
        }
        char tag[16];
        // R33: one-token pushback â holds a tag read past the
        // optional spells line so the next member parse reuses it
        char pendingTag[16] = "";
        bool hasPending = false;
        int version = 0;
        if (fscanf(f, "%15s %d", tag, &version) != 2 ||
            strcmp(tag, "ADND1") != 0 || version != 1) {
            fclose(f);
            log.add("adnd1.sav is not a valid save (v1).");
            return false;
        }
        int n = 0;
        if (fscanf(f, "%15s %d", tag, &n) != 2 ||
            strcmp(tag, "party") != 0 || n < 1 || n > PARTY_MAX) {
            fclose(f);
            log.add("adnd1.sav is corrupt (party).");
            return false;
        }
        Party p;
        int gold = 0, kills = 0, potions = 0, depth = 1;
        if (fscanf(f, "%15s %d %15s %d %15s %d %15s %d",
                   tag, &gold, tag, &kills, tag, &potions,
                   tag, &depth) != 8 || depth < 1 ||
            depth > 50) {
            fclose(f);
            log.add("adnd1.sav is corrupt (career).");
            return false;
        }
        // R44: generalized optional-tag chain â any number of
        // party-level optional lines may appear between the
        // career line and the member loop (v1 saves have none,
        // R43 saves have "training"); the first unrecognized
        // tag is pushed back for the member loop (R33 pattern)
        for (;;) {
            if (fscanf(f, "%15s", tag) != 1) break;
            if (strcmp(tag, "training") == 0) {
                int nt = 0;
                if (fscanf(f, "%d", &nt) != 1 || nt < 0 ||
                    nt > PARTY_MAX) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (training).");
                    return false;
                }
                for (int k = 0; k < nt; ++k) {
                    int ti = 0;
                    if (fscanf(f, "%d", &ti) != 1 || ti < 0 ||
                        ti >= n) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (tidx).");
                        return false;
                    }
                    p.pendingTraining.push_back(ti);
                }
            } else if (strcmp(tag, "stronghold") == 0) {
                int b = 0, ow = -1;
                if (fscanf(f, "%d %d", &b, &ow) != 2 ||
                    (b != 0 && b != 1) || ow < -1 || ow >= n) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (keep).");
                    return false;
                }
                p.strongholdBuilt = (b == 1);
                p.strongholdOwner = ow;
            } else if (strcmp(tag, "henchman") == 0) {
                int present = 0;
                if (fscanf(f, "%d", &present) != 1 ||
                    (present != 0 && present != 1)) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (hire).");
                    return false;
                }
                if (present == 1) {
                    int hp = 0, mx = 0, lv = 0, loy = 0;
                    char nm[NAME_MAX_CHARS + 1] = "";
                    if (fscanf(f, "%d %d %d %d %16s",
                               &hp, &mx, &lv, &loy, nm) != 5 ||
                        hp < 1 || mx < 1 || lv < 1 ||
                        loy < 0 || loy > 125) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (hire).");
                        return false;
                    }
                    p.henchmanPresent = true;
                    p.henchmanName = nm;
                    p.henchmanHp = hp;
                    p.henchmanMaxHp = mx;
                    p.henchmanLevel = lv;
                    p.henchmanLoyalty = loy;
                    // R45: the hire's career records â
                    // OPTIONAL trailing ints (R44 saves lack
                    // them; defaults 0 are fine)
                    int hxp = 0, hpu = 0, dgv = 0;
                    int got = fscanf(f, "%d %d %d",
                                     &hxp, &hpu, &dgv);
                    if (got >= 1) p.henchmanXp = hxp;
                    if (got >= 2) p.henchmanPurse = hpu;
                    if (got >= 3) p.delveGold = dgv;
                }
            } else if (strcmp(tag, "idscrolls") == 0) {
                int sc = 0;
                if (fscanf(f, "%d", &sc) != 1 || sc < 0 ||
                    sc > 99) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (scrolls).");
                    return false;
                }
                p.identifyScrolls = sc;
            } else if (strcmp(tag, "items") == 0) {
                int ni = 0;
                if (fscanf(f, "%d", &ni) != 1 || ni < 0 ||
                    ni > 99) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (items).");
                    return false;
                }
                for (int k = 0; k < ni; ++k) {
                    int kd = 0, pl = 0;
                    if (fscanf(f, "%d %d", &kd, &pl) != 2 ||
                        (kd != 0 && kd != 1) || pl < 1 ||
                        pl > 3) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (item).");
                        return false;
                    }
                    Party::PendingItem it;
                    it.kind = kd;
                    it.plus = pl;
                    p.unidentified.push_back(it);
                }
            } else {
                strcpy(pendingTag, tag);
                hasPending = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            Character c;
            char name[64];
            int cl = 0;
            // R33: tag comes from the pushback buffer when the
            // optional spells line was absent (v1 saves)
            if (hasPending) {
                strcpy(tag, pendingTag);
                hasPending = false;
            } else if (fscanf(f, "%15s", tag) != 1) {
                fclose(f);
                log.add("adnd1.sav is corrupt (short).");
                return false;
            }
            if (strcmp(tag, "member") != 0 ||
                fscanf(f, "%63s %d %d %d %d %d",
                       name, &cl, &c.xp, &c.level, &c.hp,
                       &c.maxHp) != 6 || cl < 0 ||
                cl > 3 || c.maxHp < 1) {
                fclose(f);
                log.add("adnd1.sav is corrupt (member).");
                return false;
            }
            c.name = name;
            c.classIndex = cl;
            int str, int_, wis, dex, con, cha, exHas, exPct;
            if (fscanf(f, "%15s %d %d %d %d %d %d %d %d", tag,
                       &str, &int_, &wis, &dex, &con, &cha,
                       &exHas, &exPct) != 9 ||
                strcmp(tag, "abil") != 0) {
                fclose(f);
                log.add("adnd1.sav is corrupt (abilities).");
                return false;
            }
            c.abilities.str  = (uint8_t)str;
            c.abilities.int_ = (uint8_t)int_;
            c.abilities.wis  = (uint8_t)wis;
            c.abilities.dex  = (uint8_t)dex;
            c.abilities.con  = (uint8_t)con;
            c.abilities.cha  = (uint8_t)cha;
            c.exStr.has = (exHas != 0);
            c.exStr.pct = exPct;
            int wid, wpl, rid, rpl, aid, apl, sh;
            if (fscanf(f, "%15s %d %d %d %d %d %d %d", tag,
                       &wid, &wpl, &rid, &rpl, &aid, &apl,
                       &sh) != 8 || strcmp(tag, "gear") != 0) {
                fclose(f);
                log.add("adnd1.sav is corrupt (gear).");
                return false;
            }
            if (wid < 0 || wid >= (int)items::WPN_COUNT ||
                rid < 0 || rid >= (int)items::WPN_COUNT ||
                aid < 0 || aid >= (int)items::ARMOR_COUNT) {
                fclose(f);
                log.add("adnd1.sav is corrupt (gear ids).");
                return false;
            }
            c.weapon.id        = (items::WeaponId)wid;
            c.weapon.plus      = wpl;
            c.rangedWeapon.id  = (items::WeaponId)rid;
            c.rangedWeapon.plus = rpl;
            c.armor.id         = (items::ArmorId)aid;
            c.armor.plus       = apl;
            c.shield           = (sh != 0);

            // R33/R56: optional per-member lines (v1 save
            // compat). Consume "spells" and "shieldplus" in any
            // order; any other tag is pushed back for the next
            // member iteration.
            bool optLoop = true;
            while (optLoop) {
                if (fscanf(f, "%15s", tag) != 1) break;
                if (strcmp(tag, "shieldplus") == 0) {
                    int sp = 0;
                    if (fscanf(f, "%d", &sp) != 1 ||
                        sp < 0 || sp > 5) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (shield).");
                        return false;
                    }
                    c.shieldPlus = sp;
                } else if (strcmp(tag, "spells") == 0) {
                    int ns = 0;
                    if (fscanf(f, "%d", &ns) != 1 || ns < 0 ||
                        ns > spells::SPELL_COUNT) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (spells).");
                        return false;
                    }
                    for (int k = 0; k < ns; ++k) {
                        int sid = 0;
                        if (fscanf(f, "%d", &sid) != 1 ||
                            sid < 0 ||
                            sid >= spells::SPELL_COUNT) {
                            fclose(f);
                            log.add("adnd1.sav is corrupt (sid).");
                            return false;
                        }
                        c.knownSpells.push_back(sid);
                    }
                } else {
                    strcpy(pendingTag, tag);
                    hasPending = true;
                    optLoop = false;
                }
            }
            p.members.push_back(c);
        }
        fclose(f);

        // R33: v1 saves predate the spellbook â grant each MU a
        // default book (one random L1 spell, creation convention)
        for (auto& c : p.members) {
            if (c.classIndex == 1 && c.knownSpells.empty()) {
                std::vector<int> l1;
                for (int id = 0; id < spells::SPELL_COUNT;
                     ++id) {
                    const spells::SpellDef& s =
                        spells::spell((spells::SpellId)id);
                    if (s.sclass == spells::SPELL_MU &&
                        s.level == 1)
                        l1.push_back(id);
                }
                if (!l1.empty()) {
                    int pick = (int)dice.roll(
                        1, (uint32_t)l1.size(), 0) - 1;
                    c.knownSpells.push_back(l1[pick]);
                }
            }
        }

        // commit: career restored, fresh dungeon at saved depth
        p.formed = true;
        p.gold = gold;
        p.kills = kills;
        p.potions = potions;
        party = p;
        creation.done = true;
        dungeonLevel = depth;
        mode = MODE_EXPLORE;
        restoreSlots();   // R34: slots are not persisted â full pool on load
        // R35: quivers are not persisted either â full 20 on load
        for (auto& c : party.members)
            if (items::weapon(c.rangedWeapon.id).missile)
                c.missileAmmo = 20;
        newDungeon(seed + 1000 + dungeonLevel);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "The company of %d returns (depth %d).",
                 n, dungeonLevel);
        log.add(buf);
        return true;
    }

// ---- placeStairs ----
void AppState::placeStairs(){
        long bestDist = -1;
        int  bx = -1, by = -1;
        for (const auto& room : occupancy.rooms) {
            long dx = room.denX - dungeon.entryX;
            long dy = room.denY - dungeon.entryY;
            long dist = dx * dx + dy * dy;
            if (dist > bestDist) {
                bestDist = dist;
                bx = room.denX;
                by = room.denY;
            }
        }
        // keep the stairs clear of a monster den: nudge to the
        // room's corner if the den is occupied
        for (auto& room : occupancy.rooms) {
            if (room.denX == bx && room.denY == by) {
                const auto& r = dungeon.rooms[room.roomIndex];
                if (!room.monsterKey.empty() && r.w >= 3 && r.h >= 3) {
                    bx = r.x;      // top-left corner tile
                    by = r.y;
                }
                break;
            }
        }
        stairsX = bx;
        stairsY = by;
    }

// ---- descend ----
void AppState::descend(){
        ++dungeonLevel;
        log.add("You descend the worn stairs...");
        newDungeon(seed + 1000 + dungeonLevel);
        // R34: the descent takes hours â slots return with the
        // new level (keeps a descended company from being stuck
        // dry with no rest opportunity)
        restoreSlots();
        // R38: quivers restock on the descent too â the trek to a
        // new level is rest-like (slots precedent, R34)
        restockAmmo();
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Dungeon level %d. The air grows colder.",
                 dungeonLevel);
        log.add(buf);
    }

// ---- restoreSlots ----
void AppState::restoreSlots(){
        for (auto& c : party.members) {
            if (c.classIndex != 1 && c.classIndex != 2) continue;
            spells::SpellClass sc = c.classIndex == 1
                ? spells::SPELL_MU : spells::SPELL_CLERIC;
            for (int lv = 1; lv <= 6; ++lv)   // R46: 6 levels
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(sc, c.level, lv);
        }
    }

// ---- restockAmmo ----
void AppState::restockAmmo(){
        for (auto& c : party.members) {
            if (!items::weapon(c.rangedWeapon.id).missile) continue;
            c.missileAmmo = 20;
        }
    }
