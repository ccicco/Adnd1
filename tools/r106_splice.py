#!/usr/bin/env python3
# R106 the keep's ledger: the free-money asymmetry closes.
# Since R44 the keep has paid 200 gp rents on every town
# return and cost NOTHING - a lord who idles in town still
# collects. Now (DMG stronghold economics, simplified to
# the campaign's existing cadences):
#   - upkeep: 200 gp a MONTH on the career clock (30
#     career days), billed at each town return
#   - the keep earns when the company delves (rents bill
#     per visit) and costs when it idles (months accrue)
#   - a purse too thin for the upkeep books the shortfall
#     as DEBT; while debt stands, the steward garnishes
#     the rents against it (no gold until cleared)
#   - three new ints ride the stronghold line: builtDay,
#     monthsBilled, debt (older saves: unknown builtDay =
#     bills start from the arrival day - no retroactive
#     debt, matching a pre-R106 save's behavior)
#
# Patches (8):
#   game/party.h      - 3 fields + the ledger helpers
#   game/state_town.cpp - rents garnish + upkeep billing,
#                         the build site stamps the day
#   game/state_core.cpp - save/load (3 optional ints)
#   regtest.cpp       - R106 keep ledger audit
#   tools/playverify_r77_r83.md - R106 section
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
# 1) party.h - the keep's three ledger fields
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""    bool strongholdBuilt = false;
    int  strongholdOwner = -1;   // member index of the lord
""",
"""    bool strongholdBuilt = false;
    int  strongholdOwner = -1;   // member index of the lord
    // R106: the keep's ledger - the career day it rose,
    // the months of upkeep already billed, and the debt a
    // thin purse booked (garnished from rents until
    // cleared). BuiltDay -1 = an older save's keep: bills
    // start from the arrival day.
    int  strongholdBuiltDay = -1;
    int  strongholdMonthsBilled = 0;
    int  strongholdDebt = 0;
""",
'party.h keep fields')

# ---------------------------------------------------------------------------
# 2) party.h - the ledger helpers
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""inline int crewHireMorale()  { return  60; }
inline int crewDesertBelow() { return 25; }
""",
"""inline int crewHireMorale()  { return  60; }
inline int crewDesertBelow() { return 25; }

// R106: the keep's ledger - a month is 30 career days
// (the calendar's own clock); upkeep bills per month, and
// an unknown build day (an older save's keep) bills from
// the day the ledger was first read.
inline int keepUpkeepPerMonth() { return 200; }
inline int keepMonthsElapsed(int builtDay, int careerDays,
                             int monthsBilled) {
    if (builtDay < 0) return 0;
    int m = (careerDays - builtDay) / 30 - monthsBilled;
    return (m > 0) ? m : 0;
}
""",
'party.h ledger helpers')

# ---------------------------------------------------------------------------
# 3) state_town.cpp - rents garnish + upkeep billing
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        if (party.strongholdBuilt) {
            party.gold += 200;
            log.add("The keep's steward delivers 200 gp in "
                    "rents.");
        }
""",
"""        if (party.strongholdBuilt) {
            // R106: the keep's ledger - while debt stands,
            // the steward garnishes the rents against it
            if (party.strongholdDebt > 0) {
                int g = (party.strongholdDebt < 200)
                            ? party.strongholdDebt : 200;
                party.strongholdDebt -= g;
                char dbuf[96];
                snprintf(dbuf, sizeof dbuf,
                         "The keep's rents go to its debt - "
                         "%d gp of %d stands.",
                         party.strongholdDebt, g);
                log.add(dbuf);
            } else {
                party.gold += 200;
                log.add("The keep's steward delivers 200 gp "
                        "in rents.");
            }
            // R106: upkeep - 200 gp a month on the career
            // clock; an older save's keep bills from today
            if (party.strongholdBuiltDay < 0) {
                party.strongholdBuiltDay = party.careerDays;
                party.strongholdMonthsBilled = 0;
            }
            int months = keepMonthsElapsed(
                party.strongholdBuiltDay, party.careerDays,
                party.strongholdMonthsBilled);
            if (months > 0) {
                int cost = months * keepUpkeepPerMonth();
                if (party.gold >= cost) {
                    party.gold -= cost;
                    char ubuf[96];
                    snprintf(ubuf, sizeof ubuf,
                             "The keep's garrison takes %d gp "
                             "(%d months' upkeep).",
                             cost, months);
                    log.add(ubuf);
                } else {
                    party.strongholdDebt += cost - party.gold;
                    char dbuf[96];
                    snprintf(dbuf, sizeof dbuf,
                             "The purse can't pay %d gp of "
                             "upkeep - the steward books a "
                             "debt of %d gp.",
                             cost, party.strongholdDebt);
                    log.add(dbuf);
                    party.gold = 0;
                }
                party.strongholdMonthsBilled += months;
            }
        }
""",
'town.cpp keep billing')

# ---------------------------------------------------------------------------
# 4) state_town.cpp - the build site stamps the day
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        party.strongholdBuilt = true;
        party.strongholdOwner = owner;
        log.add(party.members[owner].name +
                " raises a keep - rents will follow.");
""",
"""        party.strongholdBuilt = true;
        party.strongholdOwner = owner;
        // R106: the ledger opens on the day the keep rose
        party.strongholdBuiltDay = party.careerDays;
        party.strongholdMonthsBilled = 0;
        party.strongholdDebt = 0;
        log.add(party.members[owner].name +
                " raises a keep - rents will follow.");
""",
'town.cpp build stamp')

# ---------------------------------------------------------------------------
# 5) state_core.cpp - the save grows three ints
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        fprintf(f, "stronghold %d %d\\n",
                party.strongholdBuilt ? 1 : 0,
                party.strongholdOwner);
""",
"""        // R106: the keep's ledger rides as three more
        fprintf(f, "stronghold %d %d %d %d %d\\n",
                party.strongholdBuilt ? 1 : 0,
                party.strongholdOwner,
                party.strongholdBuiltDay,
                party.strongholdMonthsBilled,
                party.strongholdDebt);
""",
'state_core.cpp keep save')

# ---------------------------------------------------------------------------
# 6) state_core.cpp - the loader reads them (optional)
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""                p.strongholdBuilt = (b == 1);
                p.strongholdOwner = ow;
""",
"""                p.strongholdBuilt = (b == 1);
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
""",
'state_core.cpp keep load')

# ---------------------------------------------------------------------------
# 7) regtest.cpp - the keep ledger audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R105 crew nerve audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
"""        printf("R105 crew nerve audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R106: keep ledger audit ----
    {
        int bad = 0;
        // the month clock: 30 career days to the month
        if (keepUpkeepPerMonth() != 200) ++bad;
        if (keepMonthsElapsed(0, 90, 0) != 3)  ++bad;
        if (keepMonthsElapsed(0, 90, 3) != 0)  ++bad;
        if (keepMonthsElapsed(0, 90, 4) != 0)  ++bad;
        if (keepMonthsElapsed(0, 29, 0) != 0)  ++bad;
        if (keepMonthsElapsed(40, 100, 0) != 2) ++bad;
        // an unknown build day bills nothing (the billing
        // site stamps it first)
        if (keepMonthsElapsed(-1, 500, 0) != 0) ++bad;
        // a fresh party owes the keep nothing
        {
            Party p;
            if (p.strongholdBuilt) ++bad;
            if (p.strongholdBuiltDay != -1) ++bad;
            if (p.strongholdMonthsBilled != 0) ++bad;
            if (p.strongholdDebt != 0) ++bad;
        }
        // the garnish arithmetic: rents vs a standing debt
        {
            Party p;
            p.strongholdDebt = 500;
            int g = (p.strongholdDebt < 200)
                        ? p.strongholdDebt : 200;
            p.strongholdDebt -= g;
            if (g != 200 || p.strongholdDebt != 300) ++bad;
            g = (p.strongholdDebt < 200)
                    ? p.strongholdDebt : 200;
            p.strongholdDebt -= g;
            if (g != 200 || p.strongholdDebt != 100) ++bad;
            g = (p.strongholdDebt < 200)
                    ? p.strongholdDebt : 200;
            p.strongholdDebt -= g;
            if (g != 100 || p.strongholdDebt != 0) ++bad;
        }
        // a half-year idle keep bills six months
        {
            Party p;
            p.strongholdBuilt = true;
            p.strongholdBuiltDay = 0;
            p.careerDays = 185;
            int months = keepMonthsElapsed(
                p.strongholdBuiltDay, p.careerDays,
                p.strongholdMonthsBilled);
            if (months != 6) ++bad;
            if (months * keepUpkeepPerMonth() != 1200)
                ++bad;
        }
        // the stronghold line contract: the legacy two-int
        // form and the five-int form both parse
        {
            char tg[16];
            int b = -1, ow = -1, bd = -9, mb = -9, dt = -9;
            if (sscanf("stronghold 1 0 40 2 150",
                       "%15s %d %d %d %d %d",
                       tg, &b, &ow, &bd, &mb, &dt) != 6)
                ++bad;
            if (b != 1 || ow != 0 || bd != 40 ||
                mb != 2 || dt != 150) ++bad;
            b = -1; ow = -1;
            if (sscanf("stronghold 1 0", "%15s %d %d",
                       tg, &b, &ow) != 3) ++bad;
            if (b != 1 || ow != 0) ++bad;
        }
        printf("R106 keep ledger audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
'regtest.cpp keep ledger audit')

# ---------------------------------------------------------------------------
# 8) playverify - the R106 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R105: the crew's nerve
""",
"""## R106: the keep's ledger
- [ ] Build the keep, idle ~30 career days (inn rests or
      sea days), return - 200 gp upkeep bills ("the
      garrison takes 200 gp (1 months' upkeep)")
- [ ] The rents still deliver while the purse pays; save/
      load round-trips the ledger (the stronghold line
      reads five ints)
- [ ] Delve often, return - months pass slower than
      visits, upkeep bills only when a month truly passed
- [ ] A thin purse at billing books a debt; while debt
      stands the rents are garnished against it until
      cleared
- [ ] A pre-R106 save (two-int stronghold line) loads with
      an unknown build day - the first return stamps it
      and bills from THAT day (no retroactive debt)

## R105: the crew's nerve
""",
'playverify keep ledger section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R106 splice: ALL OK')
    sys.exit(0)
else:
    print('R106 splice: FAILED')
    sys.exit(1)
