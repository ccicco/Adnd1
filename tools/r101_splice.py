#!/usr/bin/env python3
# R101 the plate kit: two unpersisted career fields are
# found and fixed - the hire's PLATE (bought from his own
# purse, R46; a reload silently stripped armor he paid 100
# gp for) and the COASTER'S CREW (R46; a reload forgot the
# ship was hired). The plate rides as a SEVENTH trailing
# int on the henchman line (R100's contract grows by one);
# the crew gets its own optional "crew %d" line (absent in
# older saves = not hired). Both v1-compatible.
#
# Patches (8):
#   game/state_core.cpp - plate int + crew line (save),
#                         trailing 7 + crew branch (load)
#   regtest.cpp       - R101 plate kit audit (extended
#                       contract + crew line parse)
#   tools/playverify_r77_r83.md - R101 section
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
# 1) state_core.cpp - the plate rides as trailing int 7
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        if (party.henchmanPresent)
            fprintf(f,
                "henchman 1 %d %d %d %d %s %d %d %d %d %d %d\\n",
                    party.henchmanHp, party.henchmanMaxHp,
                    party.henchmanLevel, party.henchmanLoyalty,
                    party.henchmanName.c_str(),
                    party.henchmanXp, party.henchmanPurse,
                    party.delveGold,
                    party.henchmanWeaponPlus,
                    party.henchmanShieldPlus,
                    party.henchmanStartAge);
""",
"""        // R101: the seventh trailing int is the plate kit
        // (R46 - it was never persisted; a reload stripped
        // armor the hire paid 100 gp for from his purse)
        if (party.henchmanPresent)
            fprintf(f,
                "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d\\n",
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
'state_core.cpp save plate')

# ---------------------------------------------------------------------------
# 2) state_core.cpp - the crew line (save)
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        fprintf(f, "idscrolls %d\\n", party.identifyScrolls);
""",
"""        // R101: the coaster's crew - its own optional line
        // (the crew exists without a hire; it too was never
        // persisted, and a reload forgot the ship sailed)
        fprintf(f, "crew %d\\n",
                party.crewHired ? 1 : 0);
        fprintf(f, "idscrolls %d\\n", party.identifyScrolls);
""",
'state_core.cpp save crew')

# ---------------------------------------------------------------------------
# 3) state_core.cpp - the loader's seventh trailing int
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""                    int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0;
                    int hge = 0;   // R100: the hire's youth
                    int got = fscanf(f, "%d %d %d %d %d %d",
                                     &hxp, &hpu, &dgv, &wpl, &spl,
                                     &hge);
""",
"""                    int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0;
                    int hge = 0;   // R100: the hire's youth
                    int hpl = 0;   // R101: the plate kit
                    int got = fscanf(f, "%d %d %d %d %d %d %d",
                                     &hxp, &hpu, &dgv, &wpl, &spl,
                                     &hge, &hpl);
""",
'state_core.cpp load plate')

OK &= patch('game/state_core.cpp',
"""                    if (got >= 6) p.henchmanStartAge = hge;
""",
"""                    if (got >= 6) p.henchmanStartAge = hge;
                    if (got >= 7) p.henchmanPlate = (hpl != 0);
""",
'state_core.cpp load plate set')

# ---------------------------------------------------------------------------
# 4) state_core.cpp - the crew branch (load)
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""            } else if (strcmp(tag, "caldays") == 0) {
""",
"""            } else if (strcmp(tag, "crew") == 0) {
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
            } else if (strcmp(tag, "caldays") == 0) {
""",
'state_core.cpp load crew')

# ---------------------------------------------------------------------------
# 5) regtest.cpp - the plate kit audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R100 hire's years audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
"""        printf("R100 hire's years audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R101: plate kit audit ----
    {
        int bad = 0;
        // the extended contract, PINNED: seven trailing
        // ints now - the seventh is the plate kit
        {
            char line[128];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 1);
            char tg[16] = "";
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            if (std::string(nm) != "Bors") ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0, hpl = 0;
            int got = sscanf(line + pos, "%d %d %d %d %d %d %d",
                             &hxp, &hpu, &dgv, &wpl, &spl,
                             &hge, &hpl);
            if (got != 7) ++bad;
            if (hpl != 1) ++bad;
        }
        // the plate off - the trailing 0 parses too
        {
            char line[128];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 0);
            char tg[16];
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0, hpl = 1;
            if (sscanf(line + pos, "%d %d %d %d %d %d %d",
                       &hxp, &hpu, &dgv, &wpl, &spl,
                       &hge, &hpl) != 7) ++bad;
            if (hpl != 0) ++bad;
        }
        // the crew line parses both ways
        {
            int cw = -1;
            char tg[16];
            if (sscanf("crew 1", "%15s %d", tg, &cw) != 2)
                ++bad;
            if (cw != 1) ++bad;
            cw = -1;
            if (sscanf("crew 0", "%15s %d", tg, &cw) != 2)
                ++bad;
            if (cw != 0) ++bad;
        }
        // the plate buys plate: the R46 ladder top
        {
            Party p;
            if (p.henchmanPlate) ++bad;
            if (p.party_plate_kit() != items::ARMOR_CHAIN_MAIL)
                ++bad;
            p.henchmanPlate = true;
            if (p.party_plate_kit() != items::ARMOR_PLATE)
                ++bad;
        }
        // a fresh crew is not hired (the save default)
        {
            Party p;
            if (p.crewHired) ++bad;
        }
        printf("R101 plate kit audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
'regtest.cpp plate kit audit')

# ---------------------------------------------------------------------------
# 6) playverify - the R101 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R100: the hire's years
""",
"""## R101: the plate kit
- [ ] Buy the hire's plate ([J], 100 gp from his purse),
      save, load - he still wears plate (pre-R101 the
      reload silently stripped it and the 100 gp with it)
- [ ] Hire the coaster's crew, save, load - the ship
      remembers it sails (pre-R101 a reload forgot)
- [ ] A save made before a hire/crew round-trips clean
      (both lines absent, defaults false)
- [ ] The plate is a fresh hire's ladder bottom again -
      only the bought plate persists

## R100: the hire's years
""",
'playverify plate kit section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R101 splice: ALL OK')
    sys.exit(0)
else:
    print('R101 splice: FAILED')
    sys.exit(1)
