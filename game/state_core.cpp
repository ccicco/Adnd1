#include "appstate.h"

// ---- newDungeon ----
void AppState::newDungeon(uint64_t s){
        seed = s;
        dungeon = dm::generateDungeon(s);
        map = dungeon.map;
        occupancy.init(dungeon);
        // R24: no formDefault - the roster comes from creation
        party.x = dungeon.entryX;
        party.y = dungeon.entryY;
        cam.follow(party);
        turnCount = 0;
        moveDebt   = 0;
        turnsSinceRest = 0;   // R119: a fresh delve, fresh legs
        restOwed  = false;
        mustRest  = false;
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
        // R93: a first-level delve is still the deepest for a
        // fresh company
        party.deepestLevel =
            deepestOf(party.deepestLevel, 1);
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
        // reference to creationRng) - reset fields explicitly
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
        // R93: the career ledger (optional line - v1 saves
        // load with a zeroed ledger)
        fprintf(f, "ledger %d %d %ld\n",
                party.delveCount, party.deepestLevel,
                party.totalGold);
        fprintf(f, "caldays %d\n", party.careerDays);
        // R43: the training queue (v1 saves lack this line - the
        // loader treats it as optional)
        fprintf(f, "training %d",
                (int)party.pendingTraining.size());
        for (int i : party.pendingTraining)
            fprintf(f, " %d", i);
        fprintf(f, "\n");
        // R44: career extras (optional lines, v1-compatible -
        // the loader's optional-tag chain treats each as absent
        // in older saves)
        // R106: the keep's ledger rides as three more
        fprintf(f, "stronghold %d %d %d %d %d\n",
                party.strongholdBuilt ? 1 : 0,
                party.strongholdOwner,
                party.strongholdBuiltDay,
                party.strongholdMonthsBilled,
                party.strongholdDebt);
        // R100 repair: the loader reads a present flag,
        // then hp/max/level/loyalty, the NAME, then
        // trailing ints. The old save wrote all nine ints
        // before the name - its first int (the hire's hp,
        // always >= 2) hit the present flag, and every
        // save made with a hired henchman failed to load
        // ("corrupt (hire)"). The name now rides early;
        // six trailing ints follow (the sixth is the
        // hire's startAge, R100).
        // R101: the seventh trailing int is the plate kit
        // (R46 - it was never persisted; a reload stripped
        // armor the hire paid 100 gp for from his purse)
        if (party.henchmanPresent)
            fprintf(f,
                "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d %d\n",
                    party.henchmanHp, party.henchmanMaxHp,
                    party.henchmanLevel, party.henchmanLoyalty,
                    party.henchmanName.c_str(),
                    party.henchmanXp, party.henchmanPurse,
                    party.delveGold,
                    party.henchmanWeaponPlus,
                    party.henchmanShieldPlus,
                    party.henchmanStartAge,
                    party.henchmanPlate ? 1 : 0,
                    party.henchmanRaise ? 1 : 0);
        else
            fprintf(f, "henchman 0\n");
        // R86: the hire's pack (nonempty only - v1 saves load
        // with an empty mule slot)
        if (!party.henchmanPack.empty()) {
            fprintf(f, "hpack %d\n",
                    (int)party.henchmanPack.size());
            for (const auto& pi : party.henchmanPack)
                fprintf(f, "pk %d %d %d %d\n",
                        pi.kind, pi.id, pi.plus, pi.gp);
        }
        // R101: the coaster's crew - its own optional line
        // (the crew exists without a hire; it too was never
        // persisted, and a reload forgot the ship sailed)
        // R105: the crew's nerve rides as the second int
        fprintf(f, "crew %d %d\n",
                party.crewHired ? 1 : 0,
                party.crewMorale);
        // R102: the carried scrolls (R77 finds, R81
        // study) - the sweep found them unsaved; a reload
        // wiped every held scroll
        fprintf(f, "cscrolls %d\n", party.scrolls);
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
            // R56: the magic-shield enchant (nonzero only -
            // v1 saves carry no line and load as 0)
            if (c.shieldPlus > 0)
                fprintf(f, "shieldplus %d\n", c.shieldPlus);
            // R97: the gray beard (optional line - v1 saves
            // load with an unknown youth, startAge 0)
            if (c.startAge > 0)
                fprintf(f, "age %d\n", c.startAge);
            // R115: the years magic stole (optional line -
            // v1 saves load with none stolen)
            if (c.magicAgeYears > 0)
                fprintf(f, "mageage %d\n", c.magicAgeYears);
            // R81: the Ring of Protection bonus (nonzero only)
            if (c.ringPlus > 0)
                fprintf(f, "ringplus %d\n", c.ringPlus);
            // R85: the pack (nonempty members only - v1 saves
            // carry no lines and load with an empty pack)
            if (!c.pack.empty()) {
                fprintf(f, "pack %d\n", (int)c.pack.size());
                for (const auto& pi : c.pack)
                    fprintf(f, "pk %d %d %d %d\n",
                            pi.kind, pi.id, pi.plus, pi.gp);
            }
            // R33: the MU spellbook (one line per MU; other
            // classes write nothing - v1 saves stay readable)
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
        // R33: one-token pushback - holds a tag read past the
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
        // R44: generalized optional-tag chain - any number of
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
                // R106: optional trailing ledger (older
                // saves stop at the owner; -1/0/0 = unknown
                // build day, no months billed, no debt)
                int bd = -1, mb = 0, dt = 0;
                int got3 = fscanf(f, "%d %d %d",
                                  &bd, &mb, &dt);
                if (got3 != 3) {
                    clearerr(f);
                } else if (bd < -1 || mb < 0 || dt < 0) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt "
                            "(keep ledger).");
                    return false;
                } else {
                    p.strongholdBuiltDay = bd;
                    p.strongholdMonthsBilled = mb;
                    p.strongholdDebt = dt;
                }
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
                    // R45: the hire's career records -
                    // OPTIONAL trailing ints (R44 saves lack
                    // them; defaults 0 are fine)
                    int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0;
                    int hge = 0;   // R100: the hire's youth
                    int hpl = 0;   // R101: the plate kit
                    int hrr = 0;   // R103: the raise
                    int got = fscanf(f, "%d %d %d %d %d %d %d %d",
                                     &hxp, &hpu, &dgv, &wpl, &spl,
                                     &hge, &hpl, &hrr);
                    if (got >= 1) p.henchmanXp = hxp;
                    if (got >= 2) p.henchmanPurse = hpu;
                    if (got >= 3) p.delveGold = dgv;
                    // R80: the hire's magic kit (optional trailing)
                    if (got >= 4) p.henchmanWeaponPlus = wpl;
                    if (got >= 5) p.henchmanShieldPlus = spl;
                    if (got >= 6) p.henchmanStartAge = hge;
                    if (got >= 7) p.henchmanPlate = (hpl != 0);
                    if (got >= 8) p.henchmanRaise = (hrr != 0);
                }
            } else if (strcmp(tag, "crew") == 0) {
                // R101: optional line (older saves lack it -
                // the crew is simply not hired)
                int cw = 0;
                if (fscanf(f, "%d", &cw) != 1 ||
                    (cw != 0 && cw != 1)) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (crew).");
                    return false;
                }
                p.crewHired = (cw == 1);
                // R105: optional trailing morale (older
                // saves stop at the flag; 0 = unknown)
                int cm = 0;
                if (fscanf(f, "%d", &cm) != 1) {
                    clearerr(f);
                    p.crewMorale = 0;
                } else if (cm < 0 || cm > 100) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt "
                            "(crew nerve).");
                    return false;
                } else {
                    p.crewMorale = cm;
                }
            } else if (strcmp(tag, "caldays") == 0) {
                int cdays = 0;
                if (fscanf(f, "%d", &cdays) != 1 ||
                    cdays < 0 || cdays > 100000) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (caldays).");
                    return false;
                }
                p.careerDays = cdays;
            } else if (strcmp(tag, "ledger") == 0) {
                // R93: optional line (v1 saves lack it)
                int dcnt = 0, ddep = 0;
                long tgold = 0;
                if (fscanf(f, "%d %d %ld", &dcnt, &ddep,
                           &tgold) != 3 ||
                    dcnt < 0 || dcnt > 99999 ||
                    ddep < 0 || ddep > 50 ||
                    tgold < 0 || tgold > 1000000000L) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (ledger).");
                    return false;
                }
                p.delveCount = dcnt;
                p.deepestLevel = ddep;
                p.totalGold = tgold;
            } else if (strcmp(tag, "hpack") == 0) {
                int nhp = 0;
                if (fscanf(f, "%d", &nhp) != 1 ||
                    nhp < 0 || nhp > PACK_CAP) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (hpack).");
                    return false;
                }
                for (int k = 0; k < nhp; ++k) {
                    char t2[16];
                    int kd = 0, idd = 0, pl = 0, gpv = 0;
                    if (fscanf(f, "%15s %d %d %d %d",
                               t2, &kd, &idd, &pl, &gpv) != 5 ||
                        strcmp(t2, "pk") != 0 ||
                        kd < 0 || kd > 2 ||
                        pl < 0 || pl > 5 ||
                        gpv < 0 || gpv > 100000) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (hpk).");
                        return false;
                    }
                    if (kd == 0 &&
                        (idd < 0 ||
                         idd >= (int)items::WPN_COUNT)) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (hpkw).");
                        return false;
                    }
                    if (kd == 1 &&
                        (idd < 0 ||
                         idd >= (int)items::ARMOR_COUNT)) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (hpka).");
                        return false;
                    }
                    PackItem pi;
                    pi.kind = kd; pi.id = idd;
                    pi.plus = pl; pi.gp = gpv;
                    p.henchmanPack.push_back(pi);
                }
            } else if (strcmp(tag, "cscrolls") == 0) {
                // R102: optional line (older saves lack it
                // - the satchel was empty, matching the
                // pre-fix reload behavior)
                int scr = 0;
                if (fscanf(f, "%d", &scr) != 1 ||
                    scr < 0 || scr > CARRIED_CAP) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt "
                            "(cscrolls).");
                    return false;
                }
                p.scrolls = scr;
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
                if (strcmp(tag, "age") == 0) {
                int ag = 0;
                if (fscanf(f, "%d", &ag) != 1 ||
                    ag < 15 || ag > 100) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (age).");
                    return false;
                }
                c.startAge = ag;
            } else if (strcmp(tag, "mageage") == 0) {
                int mg = 0;
                if (fscanf(f, "%d", &mg) != 1 ||
                    mg < 0 || mg > 200) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (mageage).");
                    return false;
                }
                c.magicAgeYears = mg;
            } else if (strcmp(tag, "ringplus") == 0) {
                    int rg = 0;
                    if (fscanf(f, "%d", &rg) != 1 ||
                        rg < 0 || rg > 5) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (ring).");
                        return false;
                    }
                    c.ringPlus = rg;
                } else if (strcmp(tag, "shieldplus") == 0) {
                    int sp = 0;
                    if (fscanf(f, "%d", &sp) != 1 ||
                        sp < 0 || sp > 5) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (shield).");
                        return false;
                    }
                    c.shieldPlus = sp;
                } else if (strcmp(tag, "pack") == 0) {
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

        // R33: v1 saves predate the spellbook - grant each MU a
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
        restoreSlots();   // R34: slots are not persisted - full pool on load
        // R35: quivers are not persisted either - full 20 on load
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
        // R93: the career ledger tracks the deepest level
        int before = party.deepestLevel;
        party.deepestLevel =
            deepestOf(party.deepestLevel, dungeonLevel);
        // R94: a NEW deepest record wears on the hire (only
        // a record moves him - treading known halls does not)
        if (party.deepestLevel > before &&
            party.henchmanPresent && party.henchmanHp > 0) {
            party.henchmanLoyalty = loyaltyDrift(
                party.henchmanLoyalty,
                loyaltyDriftDeepDescent());
            char lb[96];
            snprintf(lb, sizeof lb,
                     "The unlit deeps weigh on %s.",
                     party.henchmanName.c_str());
            log.add(lb);
        }
        log.add("You descend the worn stairs...");
        newDungeon(seed + 1000 + dungeonLevel);
        // R91: the trek lands on the NEW level's clock (the
        // reset above wiped the old debt - the company
        // arrives 6 hours deeper, not at a fresh zero)
        turnCount += descentTurns();
        // R91: the stairs are the most-wandered ground - one
        // arrival bite (camp parity: hours pass, one check)
        if (dm::wanderCheck(dice, wander)) {
            log.add("Something followed you down!");
            spawnWanderingEncounter();
        }
        // R34: the descent takes hours - slots return with the
        // new level (keeps a descended company from being stuck
        // dry with no rest opportunity)
        restoreSlots();
        // R38: quivers restock on the descent too - the trek to a
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
            quiverRestock(c.quiver, 20);   // R80: bundle-aware
            c.missileAmmo = quiverTotal(c.quiver);
        }
    }

// ---- R79: dumpEquipment ----
void AppState::dumpEquipment(){
        log.add("--- The company's kit ---");
        char buf[192];
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            char melee[48], ranged[56], arm[48], sh[32];
            if (c.weapon.plus > 0)
                snprintf(melee, sizeof melee, "%s +%d",
                         items::weapon(c.weapon.id).name,
                         c.weapon.plus);
            else
                snprintf(melee, sizeof melee, "%s",
                         items::weapon(c.weapon.id).name);
            if (items::weapon(c.rangedWeapon.id).missile) {
                if (c.rangedWeapon.plus > 0)
                    snprintf(ranged, sizeof ranged, ", %s +%d "
                             "(%d missiles)",
                             items::weapon(c.rangedWeapon.id).name,
                             c.rangedWeapon.plus, c.missileAmmo);
                else
                    snprintf(ranged, sizeof ranged, ", %s "
                             "(%d missiles)",
                             items::weapon(c.rangedWeapon.id).name,
                             c.missileAmmo);
            } else {
                ranged[0] = 0;
            }
            if (c.armor.id != items::ARMOR_NONE_EQUIPPED) {
                if (c.armor.plus > 0)
                    snprintf(arm, sizeof arm, ", %s +%d",
                             items::armor(c.armor.id).name,
                             c.armor.plus);
                else
                    snprintf(arm, sizeof arm, ", %s",
                             items::armor(c.armor.id).name);
            } else {
                arm[0] = 0;
            }
            if (c.shield) {
                if (c.shieldPlus > 0)
                    snprintf(sh, sizeof sh, ", shield +%d",
                             c.shieldPlus);
                else
                    snprintf(sh, sizeof sh, ", shield");
            } else {
                sh[0] = 0;
            }
            char rg[16];
            if (c.ringPlus > 0) snprintf(rg, sizeof rg,
                                          ", ring +%d",
                                          c.ringPlus);
            else rg[0] = 0;
            snprintf(buf, sizeof buf, "%s: %s%s%s%s%s",
                     c.name.c_str(), melee, ranged, arm, sh, rg);
            log.add(buf);
            // R80: quiver composition when enchanted bands are held
            bool magicBands = false;
            for (const auto& b : c.quiver)
                if (b.plus > 0) magicBands = true;
            if (magicBands) {
                std::string bands;
                for (const auto& b : c.quiver) {
                    if (b.count <= 0) continue;
                    char bb[32];
                    if (b.plus > 0) snprintf(bb, sizeof bb,
                                             " +%d x%d",
                                             b.plus, b.count);
                    else snprintf(bb, sizeof bb,
                                  " %d mundane", b.count);
                    bands += bb;
                }
                snprintf(buf, sizeof buf, "  %s's quiver:%s",
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
            // R87: the burden - worn kit plus pack cargo vs the
            // STR-scaled bands (PHB p.76); movement per band.
            // The long-dormant items::encumbrance API finally
            // has a consumer.
            {
                // R89: the true load - kit, cargo, and the
                // member's share of the company's coin
                int wt = memberLoad(party, c);
                items::EncumbranceBand b =
                    items::encumbranceBand(wt, c.abilities.str);
                static const char* kBand[items::ENC_BAND_COUNT] = {
                    "unencumbered", "lightly burdened",
                    "moderately burdened", "heavily burdened"
                };
                snprintf(buf, sizeof buf,
                         "  %s: %s (%d gp wt, move %d')",
                         c.name.c_str(), kBand[b], wt,
                         items::movementForBand(b));
                log.add(buf);
            }
        }
        // R88: the hire's kit and cargo (he was absent from
        // the dump entirely; kit is the fixed R80/R46 ladder)
        if (party.henchmanPresent) {
            char kmelee[48], karm[48], ksh[32];
            if (party.henchmanWeaponPlus > 0)
                snprintf(kmelee, sizeof kmelee, "Long Sword +%d",
                         party.henchmanWeaponPlus);
            else
                snprintf(kmelee, sizeof kmelee, "Long Sword");
            snprintf(karm, sizeof karm, ", %s",
                     items::armor(party.party_plate_kit()).name);
            if (party.henchmanShieldPlus > 0)
                snprintf(ksh, sizeof ksh, ", shield +%d",
                         party.henchmanShieldPlus);
            else
                snprintf(ksh, sizeof ksh, ", shield");
            snprintf(buf, sizeof buf, "%s: %s%s%s",
                     party.henchmanName.c_str(), kmelee, karm, ksh);
            log.add(buf);
            if (!party.henchmanPack.empty()) {
                std::string pk;
                for (const auto& pi : party.henchmanPack) {
                    if (!pk.empty()) pk += "; ";
                    pk += packItemName(pi);
                }
                snprintf(buf, sizeof buf,
                         "  %s's pack (%d/%d): %s",
                         party.henchmanName.c_str(),
                         (int)party.henchmanPack.size(),
                         PACK_CAP, pk.c_str());
                log.add(buf);
            }
            // his burden at the fixed STR 12
            int hwt = henchmanCarryWeight(party);
            items::EncumbranceBand hb =
                items::encumbranceBand(hwt, 12);
            static const char* hBand[items::ENC_BAND_COUNT] = {
                "unencumbered", "lightly burdened",
                "moderately burdened", "heavily burdened"
            };
            snprintf(buf, sizeof buf,
                     "  %s: %s (%d gp wt, move %d')",
                     party.henchmanName.c_str(), hBand[hb], hwt,
                     items::movementForBand(hb));
            log.add(buf);
        }
        snprintf(buf, sizeof buf,
                 "Carried: %d potions, %d scrolls, %d gp "
                 "(coin %d wt each).",
                 party.potions, party.scrolls, party.gold,
                 coinWeightShare(party));
        log.add(buf);
    }
