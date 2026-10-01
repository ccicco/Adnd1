#!/usr/bin/env python3
# R103 the carrot: morale recovery events (DMG p.35) - the
# counterpart to R94's loyalty-drift stick. Two carrots:
#   [G] the gift - 25 gp from the purse into his purse,
#       +5 loyalty; a content man (loyalty 100+) takes no
#       gifts, so it cannot farm to the cap.
#   [J] the raise (ladder rung two, after plate) - 500 gp
#       once, +100 gp a visit to his upkeep forever
#       (henchmanUpkeep), +10 loyalty once.
# The raise flag rides as the EIGHTH trailing int on the
# henchman line (older saves: absent = false).
#
# Patches (11):
#   game/party.h      - henchmanRaise + the carrot helpers
#   game/state_town.cpp - upkeep formula, the gift (new),
#                         the raise rung on [J]
#   game/appstate.h   - townGiftHire declaration
#   adnd1.cpp         - [G] binding
#   game/state_core.cpp - save/load trailing int 8
#   regtest.cpp       - R103 carrot audit
#   tools/playverify_r77_r83.md - R103 section
import sys, os

os.chdir(os.path.dirname(os.path.abspath(__file__)) + '/..')

def rd(p):
    with open(p, 'r', encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(p, 'w', encoding='ascii') as f:
        f.write(s)

OK = True

def patch(path, anchor, repl, label):
    global OK
    s = rd(path)
    if repl in s:
        print(label + ': already patched')
        return True
    i = s.find(anchor)
    if i < 0:
        print(label + ': ANCHOR MISS')
        OK = False
        return False
    s = s.replace(anchor, repl, 1)
    wr(path, s)
    print(label + ': patched')
    return True

# ---------------------------------------------------------------------------
# 1) party.h - the raise flag
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""    bool henchmanPlate = false;   // R46: plate kit upgrade
""",
"""    bool henchmanPlate = false;   // R46: plate kit upgrade
    // R103: the raise - a one-time 500 gp grant; his
    // upkeep rises by 100 gp a visit forever (the carrot,
    // DMG p.35). Never taken = false.
    bool henchmanRaise = false;
""",
'party.h raise flag')

# ---------------------------------------------------------------------------
# 2) party.h - the carrot helpers
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""inline int loyaltyDriftDeepDescent() { return -2; }
inline int loyaltyDriftDelveDone()   { return  3; }
inline int loyaltyDriftHardWatch()   { return -1; }
""",
"""inline int loyaltyDriftDeepDescent() { return -2; }
inline int loyaltyDriftDelveDone()   { return  3; }
inline int loyaltyDriftHardWatch()   { return -1; }

// R103: the carrot (DMG p.35 - gifts and raises recover
// morale). A gift is 25 gp into his purse for +5 loyalty
// (a content man, loyalty 100+, takes no gifts); a raise
// is 500 gp once for +100 gp a visit of upkeep forever
// and +10 loyalty.
inline int loyaltyGift() { return  5; }
inline int loyaltyRaise() { return 10; }
inline int henchmanUpkeep(int level, bool hasRaise) {
    return 100 * level + (hasRaise ? 100 : 0);
}
""",
'party.h carrot helpers')

# ---------------------------------------------------------------------------
# 3) state_town.cpp - the upkeep formula takes the raise
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""            int upkeep = 100 * party.henchmanLevel;
""",
"""            // R103: the raised hire earns 100 gp a visit
            // more (the raise's price, paid forever)
            int upkeep = henchmanUpkeep(
                party.henchmanLevel, party.henchmanRaise);
""",
'town.cpp upkeep formula')

# ---------------------------------------------------------------------------
# 4) state_town.cpp - the gift (new action, [G])
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""// ---- townUpgradeHire ----
""",
"""// ---- R103: the gift - a carrot to R94's stick ----
void AppState::townGiftHire(){
        if (mode != MODE_TOWN) return;
        if (!party.henchmanPresent) {
            log.add("You have no hire to gift.");
            return;
        }
        if (party.henchmanLoyalty >= 100) {
            log.add(party.henchmanName +
                    " is content - he takes no gifts.");
            return;
        }
        if (party.gold < 25) {
            log.add("A gift wants 25 gp - the purse is "
                    "too thin.");
            return;
        }
        party.gold -= 25;
        party.henchmanPurse += 25;
        party.henchmanLoyalty = loyaltyDrift(
            party.henchmanLoyalty, loyaltyGift());
        char buf[96];
        snprintf(buf, sizeof buf,
                 "You gift %s 25 gp - his eyes warm. "
                 "(loyalty %d%%)",
                 party.henchmanName.c_str(),
                 party.henchmanLoyalty);
        log.add(buf);
    }

// ---- townUpgradeHire ----
""",
'town.cpp the gift')

# ---------------------------------------------------------------------------
# 5) state_town.cpp - the raise rung on [J]
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        if (party.henchmanPlate) {
            log.add(party.henchmanName +
                    " already wears plate.");
            return;
        }
""",
"""        if (party.henchmanPlate) {
            // R103: the ladder's second rung - the raise
            if (party.henchmanRaise) {
                log.add(party.henchmanName +
                        " has plate and a raise - there is "
                        "nothing more to give him.");
                return;
            }
            if (party.gold < 500) {
                char buf[96];
                snprintf(buf, sizeof buf,
                         "A raise costs 500 gp - the purse "
                         "holds %d.", party.gold);
                log.add(buf);
                return;
            }
            party.gold -= 500;
            party.henchmanRaise = true;
            party.henchmanLoyalty = loyaltyDrift(
                party.henchmanLoyalty, loyaltyRaise());
            log.add(party.henchmanName +
                    " takes the raise - his upkeep grows by "
                    "100 gp a visit, and his loyalty with "
                    "it.");
            return;
        }
""",
'town.cpp the raise')

# ---------------------------------------------------------------------------
# 6) appstate.h - the declaration
# ---------------------------------------------------------------------------
OK &= patch('game/appstate.h',
"""    void townUpgradeHire();
""",
"""    void townGiftHire();      // R103: [G] the 25 gp gift
    void townUpgradeHire();
""",
'appstate.h declaration')

# ---------------------------------------------------------------------------
# 7) adnd1.cpp - the [G] binding
# ---------------------------------------------------------------------------
OK &= patch('adnd1.cpp',
"""                    case 'J':
                    case 'j':
                        g_app.townUpgradeHire();
                        break;
""",
"""                    case 'J':
                    case 'j':
                        g_app.townUpgradeHire();
                        break;

                    // R103: the gift - DMG p.35 morale
                    case 'G':
                    case 'g':
                        g_app.townGiftHire();
                        break;
""",
'adnd1.cpp G binding')

# ---------------------------------------------------------------------------
# 8) state_core.cpp - the save's eighth trailing int
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""                "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d\\n",
                    party.henchmanHp, party.henchmanMaxHp,
                    party.henchmanLevel, party.henchmanLoyalty,
                    party.henchmanName.c_str(),
                    party.henchmanXp, party.henchmanPurse,
                    party.delveGold,
                    party.henchmanWeaponPlus,
                    party.henchmanShieldPlus,
                    party.henchmanStartAge,
                    party.henchmanPlate ? 1 : 0);
""",
"""                "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d %d\\n",
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
""",
'state_core.cpp save raise')

# ---------------------------------------------------------------------------
# 9) state_core.cpp - the loader's eighth trailing int
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""                    int got = fscanf(f, "%d %d %d %d %d %d %d",
                                     &hxp, &hpu, &dgv, &wpl, &spl,
                                     &hge, &hpl);
""",
"""                    int hrr = 0;   // R103: the raise
                    int got = fscanf(f, "%d %d %d %d %d %d %d %d",
                                     &hxp, &hpu, &dgv, &wpl, &spl,
                                     &hge, &hpl, &hrr);
""",
'state_core.cpp load raise')

OK &= patch('game/state_core.cpp',
"""                    if (got >= 7) p.henchmanPlate = (hpl != 0);
""",
"""                    if (got >= 7) p.henchmanPlate = (hpl != 0);
                    if (got >= 8) p.henchmanRaise = (hrr != 0);
""",
'state_core.cpp load raise set')

# ---------------------------------------------------------------------------
# 10) regtest.cpp - the carrot audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R102 ledger audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
"""        printf("R102 ledger audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R103: carrot audit ----
    {
        int bad = 0;
        // the upkeep ladder: 100/level, +100 for the raise
        if (henchmanUpkeep(1, false) != 100) ++bad;
        if (henchmanUpkeep(1, true)  != 200) ++bad;
        if (henchmanUpkeep(3, false) != 300) ++bad;
        if (henchmanUpkeep(3, true)  != 400) ++bad;
        // the carrot weights
        if (loyaltyGift() != 5)  ++bad;
        if (loyaltyRaise() != 10) ++bad;
        // the gift cannot farm past contentment: the gate
        // is the PRE-gift loyalty, the drift clamps at 125
        if (loyaltyDrift(99, loyaltyGift()) != 104) ++bad;
        if (loyaltyDrift(125, loyaltyGift()) != 125) ++bad;
        // a fresh hire has taken no raise
        {
            Party p;
            if (p.henchmanRaise) ++bad;
            if (henchmanUpkeep(p.henchmanLevel,
                               p.henchmanRaise) != 100) ++bad;
        }
        // the contract, PINNED at eight trailing ints (the
        // eighth is the raise; older saves stop at seven)
        {
            char line[144];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 1, 1);
            char tg[16];
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            if (std::string(nm) != "Bors") ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0, hpl = 0, hrr = 0;
            int got = sscanf(line + pos,
                             "%d %d %d %d %d %d %d %d",
                             &hxp, &hpu, &dgv, &wpl, &spl,
                             &hge, &hpl, &hrr);
            if (got != 8) ++bad;
            if (hpl != 1 || hrr != 1) ++bad;
        }
        // raise off parses too
        {
            char line[144];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 0, 0);
            int pos = 0;
            char tg[16];
            int present, hp, mx, lv, loy;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            int hxp, hpu, dgv, wpl, spl, hge, hpl = 1, hrr = 1;
            hxp = hpu = dgv = wpl = spl = hge = 0;
            if (sscanf(line + pos, "%d %d %d %d %d %d %d %d",
                       &hxp, &hpu, &dgv, &wpl, &spl,
                       &hge, &hpl, &hrr) != 8) ++bad;
            if (hpl != 0 || hrr != 0) ++bad;
        }
        printf("R103 carrot audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
'regtest.cpp carrot audit')

# ---------------------------------------------------------------------------
# 11) playverify - the R103 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R102: the ledger of everything
""",
"""## R103: the carrot
- [ ] [G] with a hire: 25 gp leaves the purse into his,
      loyalty +5; the message shows the new loyalty
- [ ] [G] at loyalty 100+: "is content - he takes no
      gifts" (no gold moves)
- [ ] [J] after plate: the raise - 500 gp, his upkeep
      message on the next return reads 100/level +100
- [ ] [J] after the raise: "nothing more to give him"
- [ ] Save/load round-trips plate AND raise (eighth
      trailing int); a pre-R103 save loads with no raise

## R102: the ledger of everything
""",
'playverify carrot section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R103 splice: ALL OK')
    sys.exit(0)
else:
    print('R103 splice: FAILED')
    sys.exit(1)
