#!/usr/bin/env python3
# R87-CHUNK-1-START
# R87 "THE BURDEN" splice - wires the long-dormant encumbrance
# API (items::encumbranceBand/movementForBand/equippedWeight,
# built in the items tranche, consumed by NOTHING until now)
# to the R85/R86 pack. Content-anchored, idempotent.
# Patch groups (7 files):
#   items/items.h + items.cpp - shieldWeightGp exposed (the
#                         shield constant was file-static)
#   game/party.h        - packItemWeight, packAdd encumbrance
#                         gate (no HEAVY band on carries),
#                         henchmanCarryWeight/henchmanCanShoulder
#   game/state_dungeon.cpp - mule slot refuses a hire-heavy load
#   game/state_core.cpp - dumpEquipment prints the burden line
#                         (band, weight, movement rate)
#   regtest.cpp         - "R87 burden audit: bad 0"
#   tools/playverify_r77_r83.md - burden walkthrough lines
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
# 1) items.h / items.cpp - expose the shield weight
# ---------------------------------------------------------------------------
OK &= patch('items/items.h',
"""// Total weight of equipped weapon+armor+shield (gp units).
int equippedWeight(const WeaponInstance& w, const ArmorInstance& a,
                   bool shield);""",
"""// Total weight of equipped weapon+armor+shield (gp units).
int equippedWeight(const WeaponInstance& w, const ArmorInstance& a,
                   bool shield);

// R87: the plain-shield weight (gp units) - was a file-static
// in items.cpp; pack weights need it too.
int shieldWeightGp();""",
'items.h shieldWeightGp')

OK &= patch('items/items.cpp',
"""static const int SHIELD_WEIGHT_GP = 100;""",
"""static const int SHIELD_WEIGHT_GP = 100;

int shieldWeightGp() { return SHIELD_WEIGHT_GP; }""",
'items.cpp shieldWeightGp')

# ---------------------------------------------------------------------------
# 2) party.h - pack weights + the encumbrance gate
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""// carry an item; false when the pack is full (the caller appraises)
inline bool packAdd(Character& c, const PackItem& p) {
    if ((int)c.pack.size() >= PACK_CAP) return false;
    c.pack.push_back(p);
    return true;
}""",
"""// R87: the weight of one carried item (gp units, item tables;
// PackItem stores no weight - it is derived, never saved)
inline int packItemWeight(const PackItem& p) {
    if (p.kind == 2) return items::shieldWeightGp();
    if (p.kind == 1) {
        if (p.id < 0 || p.id >= (int)items::ARMOR_COUNT) return 0;
        return items::armor((items::ArmorId)p.id).weightGp;
    }
    if (p.id < 0 || p.id >= (int)items::WPN_COUNT) return 0;
    return items::weapon((items::WeaponId)p.id).weightGp;
}

// R87: total load - worn kit plus pack cargo (gp units)
inline int carriedWeight(const Character& c) {
    int wt = items::equippedWeight(c.weapon, c.armor, c.shield);
    for (const auto& q : c.pack) wt += packItemWeight(q);
    return wt;
}

// carry an item; false when the pack is full (the caller
// appraises) or when the carry would push the member into
// the HEAVY encumbrance band (STR-scaled, PHB p.76 - the
// strong shoulder more; the weak stop sooner)
inline bool packAdd(Character& c, const PackItem& p) {
    if ((int)c.pack.size() >= PACK_CAP) return false;
    if (items::encumbranceBand(carriedWeight(c) +
                                   packItemWeight(p),
                               c.abilities.str) ==
        items::ENC_HEAVY)
        return false;
    c.pack.push_back(p);
    return true;
}

// R87: the hire's load - fixed kit (sword, kit-ladder armor,
// shield) plus his mule cargo
inline int henchmanCarryWeight(const Party& p) {
    int wt = items::weapon(items::WPN_LONG_SWORD).weightGp +
             items::armor(p.party_plate_kit()).weightGp +
             items::shieldWeightGp();
    for (const auto& q : p.henchmanPack) wt += packItemWeight(q);
    return wt;
}

// R87: can the hire shoulder one more item without going
// HEAVY? (his STR is the fixed 12 of the henchmanActor kit)
inline bool henchmanCanShoulder(const Party& p, const PackItem& it) {
    return items::encumbranceBand(henchmanCarryWeight(p) +
                                      packItemWeight(it),
                                  12) != items::ENC_HEAVY;
}""",
'party.h burden helpers')
# R87-CHUNK-1-END
# R87-CHUNK-2-START

# ---------------------------------------------------------------------------
# 3) state_dungeon.cpp - the mule slot respects the burden
# ---------------------------------------------------------------------------
OK &= patch('game/state_dungeon.cpp',
"""                    if (!take && party.henchmanPresent &&
                        party.henchmanHp > 0 &&
                        (int)party.henchmanPack.size() < PACK_CAP) {""",
"""                    if (!take && party.henchmanPresent &&
                        party.henchmanHp > 0 &&
                        (int)party.henchmanPack.size() < PACK_CAP &&
                        henchmanCanShoulder(party, cand)) {""",
'state_dungeon.cpp mule gate')

# ---------------------------------------------------------------------------
# 4) state_core.cpp - dumpEquipment prints the burden
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""                snprintf(buf, sizeof buf,
                         "  %s's pack (%d/%d): %s",
                         c.name.c_str(), (int)c.pack.size(),
                         PACK_CAP, pk.c_str());
                log.add(buf);
            }
""",
"""                snprintf(buf, sizeof buf,
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
                int wt = carriedWeight(c);
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
""",
'state_core.cpp burden dump')

# ---------------------------------------------------------------------------
# 5) regtest.cpp - the R87 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R86 cursed/hire audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R86 cursed/hire audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R87: burden audit ----
    {
        int bad = 0;
        // item weights come from the tables (gp units)
        PackItem w1{};
        w1.kind = 0;
        w1.id = (int)items::WPN_LONG_SWORD;
        if (packItemWeight(w1) != 75) ++bad;    // PHB p.37
        PackItem a1{};
        a1.kind = 1;
        a1.id = (int)items::ARMOR_PLATE;
        if (packItemWeight(a1) != 450) ++bad;   // PHB p.36
        PackItem s1{};
        s1.kind = 2;
        if (packItemWeight(s1) != 100) ++bad;
        PackItem badId{};
        badId.kind = 0;
        badId.id = 999;
        if (packItemWeight(badId) != 0) ++bad;  // out of range
        // band + movement sanity (STR 10 scale = 350/700/1050)
        if (items::encumbranceBand(0, 10) !=
            items::ENC_UNENCUMBERED) ++bad;
        if (items::encumbranceBand(700, 10) != items::ENC_LIGHT)
            ++bad;
        if (items::encumbranceBand(1050, 10) !=
            items::ENC_MODERATE) ++bad;
        if (items::encumbranceBand(1051, 10) !=
            items::ENC_HEAVY) ++bad;
        if (items::movementForBand(items::ENC_UNENCUMBERED) != 120)
            ++bad;
        if (items::movementForBand(items::ENC_HEAVY) != 30) ++bad;
        // STR 18 scales the bands up (heavy 1050 -> 1890)
        if (items::encumbranceBand(1890, 18) !=
            items::ENC_MODERATE) ++bad;
        // the packAdd encumbrance gate: a STR 10 member in
        // plate kit (dagger 20 + plate 450 = 470 worn) can
        // carry ONE spare plate (920, moderate) - the second
        // would go heavy (1370 > 1050) and is refused
        {
            Character c;
            c.hp = 10;
            c.armor.id = items::ARMOR_PLATE;
            if (carriedWeight(c) != 470) ++bad;
            if (!packAdd(c, a1)) ++bad;    // 920: moderate, ok
            if (packAdd(c, a1)) ++bad;     // 1370: heavy, no
            if (c.pack.size() != 1) ++bad;
        }
        // STR 18 shoulders more before the gate trips
        {
            Character c;
            c.hp = 10;
            c.abilities.str = 18;
            c.armor.id = items::ARMOR_PLATE;
            if (!packAdd(c, a1)) ++bad;    // 920
            if (!packAdd(c, a1)) ++bad;    // 1370
            if (!packAdd(c, a1)) ++bad;    // 1820 <= 1890
            if (packAdd(c, a1)) ++bad;     // 2270: heavy, no
            if (c.pack.size() != 3) ++bad;
        }
        // the R85 cap still binds first for mundane loot
        {
            Character c;
            c.hp = 10;
            PackItem sw{};
            sw.kind = 0;
            sw.id = (int)items::WPN_LONG_SWORD;
            int added = 0;
            while (packAdd(c, sw) && added < 99) ++added;
            if (added != PACK_CAP) ++bad;  // 470 gp: cap, not wt
        }
        // the hire's load: sword 75 + plate 450 + shield 100
        // = 625 worn; STR 12 heavy threshold is 1260
        {
            Party p;
            p.henchmanPresent = true;
            p.henchmanPlate = true;   // plate kit (R46 ladder top)
            if (henchmanCarryWeight(p) != 625) ++bad;
            if (!henchmanCanShoulder(p, a1)) ++bad;   // 1075
            p.henchmanPack.push_back(a1);
            if (henchmanCanShoulder(p, a1)) ++bad;    // 1525
        }
        printf("R87 burden audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp burden audit')
# R87-CHUNK-2-END
# R87-CHUNK-3-START

# ---------------------------------------------------------------------------
# 6) playverify checklist - the burden lines
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## Sign-off""",
"""## R87: the burden (encumbrance wired to the pack)
- [ ] [D] dump kit: every member now prints a burden line,
      e.g. "  Rolf: moderately burdened (920 gp wt, move 60')"
      (worn kit + pack cargo, STR-scaled bands, PHB p.76).
- [ ] A STR 10 member wearing plate armor can carry at most
      ONE spare suit of plate in the pack - a second is
      refused (over-heavy) and left appraised in the hoard.
      A STR 18 member carries three.
- [ ] The henchman shoulders cargo up to his own limit
      (heavy threshold 1260 gp at STR 12, kit already 625);
      past it the item stays appraised ("...shoulders..." only
      while it fits).

## Sign-off""",
'playverify burden section')

# ---------------------------------------------------------------------------
print("\\n".join(REPORT))
print("R87 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R87-CHUNK-3-END
