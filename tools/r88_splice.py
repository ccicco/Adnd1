#!/usr/bin/env python3
# R88-CHUNK-1-START
# R88 "THE WARNING" splice - allow-with-warning encumbrance at
# equip time, the hire's dump, party move rate. Content-
# anchored, idempotent. Patch groups (6 files):
#   game/party.h        - partyMoveRate (company moves at the
#                         slowest member's band)
#   game/state_town.cpp - [E] warns when a swap goes HEAVY
#                         (the swap PROCEEDS - deliberate
#                         overburden is a player choice)
#   game/state_core.cpp - dumpEquipment gains the hire's kit,
#                         cargo and burden lines
#   adnd1.cpp           - HUD status line shows party Move N'
#   regtest.cpp         - "R88 warning audit: bad 0"
#   tools/playverify_r77_r83.md - the walkthrough lines
# All anchors and inserted text are ASCII-only (protocol rule).

import sys, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REPORT = []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='utf-8') as f:
        f.write(s)

def patch(fname, old, new, tag, count=1):
    s = rd(fname)
    if new in s:
        REPORT.append("%s: already patched" % tag)
        return True
    n = s.count(old)
    if n != count:
        REPORT.append("%s: FAIL (anchor x%d, want %d)" % (tag, n, count))
        return False
    wr(fname, s.replace(old, new, count))
    REPORT.append("%s: patched" % tag)
    return True

OK = True

# ---------------------------------------------------------------------------
# 1) party.h - the company's move rate (slowest member sets pace)
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""// R87: can the hire shoulder one more item without going
// HEAVY? (his STR is the fixed 12 of the henchmanActor kit)
inline bool henchmanCanShoulder(const Party& p, const PackItem& it) {
    return items::encumbranceBand(henchmanCarryWeight(p) +
                                      packItemWeight(it),
                                  12) != items::ENC_HEAVY;
}""",
"""// R87: can the hire shoulder one more item without going
// HEAVY? (his STR is the fixed 12 of the henchmanActor kit)
inline bool henchmanCanShoulder(const Party& p, const PackItem& it) {
    return items::encumbranceBand(henchmanCarryWeight(p) +
                                      packItemWeight(it),
                                  12) != items::ENC_HEAVY;
}

// R88: the company's move rate - the slowest living member's
// band sets the pace (the company moves together); a dead or
// empty party is treated as unencumbered
inline int partyMoveRate(const Party& p) {
    int best = items::movementForBand(items::ENC_UNENCUMBERED);
    for (const auto& c : p.members) {
        if (c.hp <= 0) continue;
        int m = items::movementForBand(
            items::encumbranceBand(carriedWeight(c),
                                   c.abilities.str));
        if (m < best) best = m;
    }
    return best;
}""",
'party.h partyMoveRate')
# R88-CHUNK-1-END
# R88-CHUNK-2-START

# ---------------------------------------------------------------------------
# 2) state_town.cpp - [E] warns on a HEAVY swap (swap proceeds)
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""                snprintf(buf, sizeof buf,
                         "%s equips the %s.",
                         c.name.c_str(),
                         packItemName(p).c_str());
                log.add(buf);
                ++swaps;""",
"""                snprintf(buf, sizeof buf,
                         "%s equips the %s.",
                         c.name.c_str(),
                         packItemName(p).c_str());
                log.add(buf);
                // R88: allow-with-warning - the swap stands, but
                // a HEAVY result is called out (deliberate
                // overburden is a player choice; the R87 packAdd
                // gate still stops pack CARRIES, not equips)
                if (items::encumbranceBand(carriedWeight(c),
                                           c.abilities.str) ==
                    items::ENC_HEAVY)
                    log.add("  (now heavily burdened - "
                            "movement 30')");
                ++swaps;""",
'state_town.cpp equip warning')

# ---------------------------------------------------------------------------
# 3) state_core.cpp - the hire's dump lines
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        snprintf(buf, sizeof buf,
                 "Carried: %d potions, %d scrolls, %d gp.",
                 party.potions, party.scrolls, party.gold);
        log.add(buf);
    }""",
"""        // R88: the hire's kit and cargo (he was absent from
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
                 "Carried: %d potions, %d scrolls, %d gp.",
                 party.potions, party.scrolls, party.gold);
        log.add(buf);
    }""",
'state_core.cpp hire dump')

# ---------------------------------------------------------------------------
# 4) adnd1.cpp - HUD shows the company's move rate
# ---------------------------------------------------------------------------
OK &= patch('adnd1.cpp',
"""             "Dungeon Lvl %d  Rooms: %d (%d lairs)  %d gp  Potions %d  "
             "Kills %d  Turn %d  Seed %llu  [P] quaff  "
             "[K] save  [L] load  [R] rest  [B] town",
             s.dungeonLevel, (int)s.dungeon.rooms.size(),
             s.countOccupied(), party.gold, party.potions,
             party.kills, s.turnCount, (unsigned long long)s.seed);""",
"""             "Dungeon Lvl %d  Rooms: %d (%d lairs)  %d gp  Potions %d  "
             "Kills %d  Turn %d  Move %d'  Seed %llu  [P] quaff  "
             "[K] save  [L] load  [R] rest  [B] town",
             s.dungeonLevel, (int)s.dungeon.rooms.size(),
             s.countOccupied(), party.gold, party.potions,
             party.kills, s.turnCount, partyMoveRate(party),
             (unsigned long long)s.seed);""",
'adnd1.cpp HUD move')
# R88-CHUNK-2-END
# R88-CHUNK-3-START

# ---------------------------------------------------------------------------
# 5) regtest.cpp - the R88 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R87 burden audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R87 burden audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R88: warning audit ----
    {
        int bad = 0;
        // the company moves at the slowest living member's
        // band; dead members and empty packs do not slow it
        {
            Party p;
            // default kit: dagger + no armor = 20 gp
            if (partyMoveRate(p) != 120) ++bad;   // nobody: base
            Character a;
            a.hp = 10;                            // STR 10, kit
            if (carriedWeight(a) != 20) ++bad;
            p.members.push_back(a);
            int wa = carriedWeight(a);
            int ma = partyMoveRate(p);
            if (ma != items::movementForBand(
                    items::encumbranceBand(wa, 10))) ++bad;
            // a HEAVY companion drags the whole company to 30
            Character h;
            h.hp = 10;
            h.abilities.str = 10;
            h.armor.id = items::ARMOR_PLATE;      // 470 worn
            PackItem a1{};
            a1.kind = 1;
            a1.id = (int)items::ARMOR_PLATE;
            if (!packAdd(h, a1)) ++bad;            // 920: moderate
            if (packAdd(h, a1)) ++bad;             // 1370: refused
            // push the weight over heavy via direct pack
            // push (bypasses the R87 gate on purpose)
            PackItem big{};
            big.kind = 1;
            big.id = (int)items::ARMOR_PLATE;
            h.pack.push_back(big);                // 1370: heavy
            if (items::encumbranceBand(carriedWeight(h), 10) !=
                items::ENC_HEAVY) ++bad;
            p.members.push_back(h);
            if (partyMoveRate(p) != 30) ++bad;
            // the dead do not slow the company
            Character d;
            d.hp = 0;
            d.armor.id = items::ARMOR_PLATE;
            PackItem many{};
            many.kind = 1;
            many.id = (int)items::ARMOR_PLATE;
            for (int i = 0; i < 6; ++i) d.pack.push_back(many);
            p.members.push_back(d);
            if (partyMoveRate(p) != 30) ++bad;    // h still slow
            p.members.pop_back();
            p.members.pop_back();                 // drop h
            if (partyMoveRate(p) !=
                items::movementForBand(
                    items::encumbranceBand(wa, 10))) ++bad;
        }
        // the [E] swap weight pin: equipping plate from the
        // pack CONSERVES carriedWeight (the old leather kit
        // returns to the pack as the keepsake) - the swap
        // can never create a HEAVY load by itself; the [E]
        // warning is a state echo, not a cause
        {
            Character c;
            c.hp = 10;
            c.armor.id = items::ARMOR_LEATHER;
            PackItem a1{};
            a1.kind = 1;
            a1.id = (int)items::ARMOR_PLATE;
            c.pack.push_back(a1);
            int before = carriedWeight(c);        // 20+150+450
            if (before != 620) ++bad;
            // simulate the townSwapGear armor branch
            PackItem old{};
            old.kind = 1;
            old.id = (int)c.armor.id;
            old.plus = c.armor.plus;
            c.armor.id = (items::ArmorId)a1.id;
            c.armor.plus = a1.plus;
            c.pack[0] = old;
            int after = carriedWeight(c);
            if (after != before) ++bad;            // conserved
        }
        printf("R88 warning audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp warning audit')

# ---------------------------------------------------------------------------
# 6) playverify checklist - the R88 lines
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## Sign-off""",
"""## R88: the warning + the hire's dump
- [ ] [D] dump kit now ends with the henchman's block (when
      hired): "Grimnir: Long Sword, Plate Mail, shield",
      his cargo pack line, and his burden line (STR 12).
- [ ] [E] on a member already over the HEAVY band (weak STR
      in plate kit, or a pre-R87 save): the swap happens and
      the log adds "  (now heavily burdened - movement 30')".
      Swaps conserve carried weight (the old kit returns to
      the pack) - the warning is a state echo, not a cause.
- [ ] Dungeon HUD status line now shows "Move N'" (company
      pace: the slowest living member's band; 120' unburdened).

## Sign-off""",
'playverify warning section')

# ---------------------------------------------------------------------------
print("\\n".join(REPORT))
print("R88 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R88-CHUNK-3-END
