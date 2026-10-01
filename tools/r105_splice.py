#!/usr/bin/env python3
# R105 the crew's nerve: the crew finally has the same
# teeth the hire has (R94/R103 closed the loyalty economy
# for the hire; the crew could grumble forever and never
# leave). Now:
#   - crewMorale (0..100, hired at 60, saved as the crew
#     line's second int - older saves load 0 = unknown,
#     treated as fresh 60 on their next wage payment)
#   - wages paid at the port return: +2 morale
#   - unpaid wages (short purse): -10
#   - a crew share on a rich delve: +3
#   - below 25 at the wages billing: the crew DESERTS -
#     crewHired = false, the ferry service dies with them
#     (rehire at the harbormaster for 200 gp, fresh 60)
#
# Patches (9):
#   game/party.h      - crewMorale + the nerve helpers
#   game/state_town.cpp - wages block, share site, hire
#   game/state_core.cpp - "crew %d %d" + optional second
#   regtest.cpp       - R105 crew nerve audit
#   tools/playverify_r77_r83.md - R105 section
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
# 1) party.h - the crew's morale field
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""    bool crewHired     = false;   // R46: a coaster's company
""",
"""    bool crewHired     = false;   // R46: a coaster's company
    // R105: the crew's nerve - 0..100, hired at 60. Wages
    // mend it, short purses wear it, and below 25 the
    // crew deserts at port. 0 on an older save = unknown,
    // freshened to 60 on its next wage payment.
    int  crewMorale = 0;
""",
'party.h crew morale')

# ---------------------------------------------------------------------------
# 2) party.h - the nerve helpers
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""inline bool spendGold(Party& p, MessageLog& log, int cost,
                      const std::string& refusal) {
    if (p.gold < cost) {
        log.add(refusal);
        return false;
    }
    p.gold -= cost;
    return true;
}
""",
"""inline bool spendGold(Party& p, MessageLog& log, int cost,
                      const std::string& refusal) {
    if (p.gold < cost) {
        log.add(refusal);
        return false;
    }
    p.gold -= cost;
    return true;
}

// R105: the crew's nerve - the drift that moves it (wages
// mend, a short purse wears, a rich delve's share warms)
// and the floor beneath which the crew deserts at port.
inline int clampCrewMorale(int m) {
    if (m < 0)   return 0;
    if (m > 100) return 100;
    return m;
}
inline int crewDriftPaid()   { return  2; }
inline int crewDriftUnpaid() { return -10; }
inline int crewDriftShare()  { return  3; }
inline int crewHireMorale()  { return  60; }
inline int crewDesertBelow() { return 25; }
""",
'party.h nerve helpers')

# ---------------------------------------------------------------------------
# 3) state_town.cpp - the wages block grows teeth
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        if (party.crewHired) {
            if (party.gold >= 40) {
                party.gold -= 40;
                log.add("The crew is paid 40 gp in wages.");
            } else {
                log.add("The crew grumbles over unpaid "
                        "wages.");
            }
        }
""",
"""        if (party.crewHired) {
            // R105: an older save's crew arrives with an
            // unknown nerve - freshen it to the hire's 60
            if (party.crewMorale <= 0)
                party.crewMorale = crewHireMorale();
            if (party.gold >= 40) {
                party.gold -= 40;
                party.crewMorale = clampCrewMorale(
                    party.crewMorale + crewDriftPaid());
                log.add("The crew is paid 40 gp in wages.");
            } else {
                party.crewMorale = clampCrewMorale(
                    party.crewMorale + crewDriftUnpaid());
                log.add("The crew grumbles over unpaid "
                        "wages.");
            }
            // R105: the floor - a worn crew deserts at
            // port, and the ferry dies with them
            if (party.crewMorale < crewDesertBelow()) {
                log.add("The crew slips away by night - "
                        "the coaster sails without you.");
                party.crewHired = false;
                party.crewMorale = 0;
            }
        }
""",
'town.cpp wages teeth')

# ---------------------------------------------------------------------------
# 4) state_town.cpp - the crew share warms the nerve
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""            if (crewCut > 0) {
                char cbuf[96];
                snprintf(cbuf, sizeof cbuf,
                         "The crew's share: %d gp.", crewCut);
                log.add(cbuf);
            }
""",
"""            if (crewCut > 0) {
                // R105: a rich delve's share warms the
                // crew's nerve
                party.crewMorale = clampCrewMorale(
                    party.crewMorale + crewDriftShare());
                char cbuf[96];
                snprintf(cbuf, sizeof cbuf,
                         "The crew's share: %d gp.", crewCut);
                log.add(cbuf);
            }
""",
'town.cpp share warms')

# ---------------------------------------------------------------------------
# 5) state_town.cpp - a fresh signing has a fresh nerve
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        party.crewHired = true;
        log.add("A coaster's company of twenty signs on. "
                "They will ferry your takings to market.");
""",
"""        party.crewHired = true;
        party.crewMorale = crewHireMorale();   // R105
        log.add("A coaster's company of twenty signs on. "
                "They will ferry your takings to market.");
""",
'town.cpp fresh signing')

# ---------------------------------------------------------------------------
# 6) state_core.cpp - the save grows a second int
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        fprintf(f, "crew %d\\n",
                party.crewHired ? 1 : 0);
""",
"""        // R105: the crew's nerve rides as the second int
        fprintf(f, "crew %d %d\\n",
                party.crewHired ? 1 : 0,
                party.crewMorale);
""",
'state_core.cpp crew save')

# ---------------------------------------------------------------------------
# 7) state_core.cpp - the loader reads it (optional)
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""                int cw = 0;
                if (fscanf(f, "%d", &cw) != 1 ||
                    (cw != 0 && cw != 1)) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (crew).");
                    return false;
                }
                p.crewHired = (cw == 1);
""",
"""                int cw = 0;
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
""",
'state_core.cpp crew load')

# ---------------------------------------------------------------------------
# 8) regtest.cpp - the crew nerve audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R104 scales audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
"""        printf("R104 scales audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R105: crew nerve audit ----
    {
        int bad = 0;
        // the drift weights and the floor
        if (crewDriftPaid()   !=  2)   ++bad;
        if (crewDriftUnpaid() != -10)  ++bad;
        if (crewDriftShare()  !=  3)   ++bad;
        if (crewHireMorale()  !=  60)  ++bad;
        if (crewDesertBelow() !=  25)  ++bad;
        // the clamp bounds
        if (clampCrewMorale(-1) != 0)     ++bad;
        if (clampCrewMorale(101) != 100)  ++bad;
        if (clampCrewMorale(60)  != 60)   ++bad;
        // the desertion arithmetic: three unpaid wages
        // from a fresh signing, then the floor
        {
            Party p;
            p.crewHired = true;
            p.crewMorale = crewHireMorale();
            for (int i = 0; i < 3; ++i)
                p.crewMorale = clampCrewMorale(
                    p.crewMorale + crewDriftUnpaid());
            // 60 - 30 = 30, still aboard
            if (p.crewMorale != 30) ++bad;
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftUnpaid());
            // 20, below the 25 floor - desertion
            if (p.crewMorale >= crewDesertBelow()) ++bad;
        }
        // the recovery path: two paid wages + a share
        // from 30
        {
            Party p;
            p.crewMorale = 30;
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftPaid());
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftPaid());
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftShare());
            if (p.crewMorale != 37) ++bad;
        }
        // the crew line contract: flag then morale, and
        // the older one-int form still parses
        {
            int cw = -1, cm = -1;
            char tg[16];
            if (sscanf("crew 1 60", "%15s %d %d",
                       tg, &cw, &cm) != 3) ++bad;
            if (cw != 1 || cm != 60) ++bad;
            cw = -1;
            if (sscanf("crew 1", "%15s %d", tg, &cw) != 2)
                ++bad;
            if (cw != 1) ++bad;
            cw = -1; cm = -1;
            if (sscanf("crew 0 0", "%15s %d %d",
                       tg, &cw, &cm) != 3) ++bad;
            if (cw != 0 || cm != 0) ++bad;
        }
        printf("R105 crew nerve audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
'regtest.cpp crew nerve audit')

# ---------------------------------------------------------------------------
# 9) playverify - the R105 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R103: the carrot
""",
"""## R105: the crew's nerve
- [ ] Hire the crew, save, load - the crew survives with
      its morale (the crew line reads two ints)
- [ ] Return to port with gold short - "grumbles over
      unpaid wages", and repeated short returns wear the
      nerve toward the floor
- [ ] Three+ unpaid returns: the crew deserts ("slips
      away by night"), crewHired is false, [C] rehires
      at 200 gp with a fresh nerve
- [ ] Paid returns and rich delves (crew share) recover
      the nerve
- [ ] A pre-R105 save (crew line with one int) loads with
      unknown morale, freshened to 60 at its next wage
      billing - no desertion on arrival

## R103: the carrot
""",
'playverify crew nerve section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R105 splice: ALL OK')
    sys.exit(0)
else:
    print('R105 splice: FAILED')
    sys.exit(1)
