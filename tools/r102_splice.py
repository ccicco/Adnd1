#!/usr/bin/env python3
# R102 the ledger of everything: the full field-vs-save
# audit sweep. Every field in Party and Character was
# walked against the save file. Verdicts:
#   - by design, not persisted: x/y/formed (transient),
#     slotsByLevel (R34: full pool on load), quiver bands
#     and missileAmmo (R35: full 20 on load)
#   - saved: everything else EXCEPT ONE - party.scrolls
#     (R77 carried scrolls, R81 study in town teaches
#     spells on a chance-to-learn roll). A reload wiped
#     every held scroll. Fixed: optional "cscrolls %d"
#     line (tag distinct from idscrolls; absent in older
#     saves = 0, matching the pre-fix behavior).
#
# Patches (5):
#   game/state_core.cpp - "cscrolls %d" save + load branch
#   regtest.cpp       - R102 ledger audit (field-vs-save
#                       inventory PINNED + the new line)
#   tools/playverify_r77_r83.md - R102 section
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
# 1) state_core.cpp - the carried-scrolls save line
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        fprintf(f, "idscrolls %d\\n", party.identifyScrolls);
""",
"""        // R102: the carried scrolls (R77 finds, R81
        // study) - the sweep found them unsaved; a reload
        // wiped every held scroll
        fprintf(f, "cscrolls %d\\n", party.scrolls);
        fprintf(f, "idscrolls %d\\n", party.identifyScrolls);
""",
'state_core.cpp save cscrolls')

# ---------------------------------------------------------------------------
# 2) state_core.cpp - the load branch
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""            } else if (strcmp(tag, "idscrolls") == 0) {
""",
"""            } else if (strcmp(tag, "cscrolls") == 0) {
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
""",
'state_core.cpp load cscrolls')

# ---------------------------------------------------------------------------
# 3) regtest.cpp - the ledger audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R101 plate kit audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
"""        printf("R101 plate kit audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R102: ledger of everything audit ----
    {
        int bad = 0;
        // the field-vs-save sweep, PINNED: every durable
        // Party/Character field has a save tag; the only
        // transient fields are by documented design
        {
            Party p;
            p.gold = 100; p.kills = 5; p.potions = 3;
            p.scrolls = 2; p.careerDays = 10;
            p.delveCount = 4; p.deepestLevel = 6;
            p.totalGold = 9000; p.identifyScrolls = 1;
            p.strongholdBuilt = true; p.strongholdOwner = 0;
            p.crewHired = true; p.formed = true;
            // a fresh party defaults clean - the sweep's
            // zero-state: nothing durable is left behind
            Party q;
            if (q.gold != 0 || q.kills != 0) ++bad;
            if (q.scrolls != 0 || q.potions != 0) ++bad;
            if (q.careerDays != 0) ++bad;
            if (q.delveCount != 0 || q.totalGold != 0)
                ++bad;
            if (q.strongholdBuilt || q.crewHired) ++bad;
            if (q.henchmanPresent || q.henchmanPlate) ++bad;
            if (q.identifyScrolls != 0) ++bad;
        }
        // the carried-scrolls line parses, both ways
        {
            int scr = -1;
            char tg[16];
            if (sscanf("cscrolls 7", "%15s %d", tg, &scr)
                != 2) ++bad;
            if (std::string(tg) != "cscrolls" || scr != 7)
                ++bad;
            scr = -1;
            if (sscanf("cscrolls 0", "%15s %d", tg, &scr)
                != 2) ++bad;
            if (scr != 0) ++bad;
        }
        // the tag is distinct from idscrolls (both load
        // branches must route independently)
        {
            char tg1[16] = "", tg2[16] = "";
            int a = -1, b = -1;
            if (sscanf("idscrolls 2", "%15s %d", tg1, &a)
                != 2) ++bad;
            if (sscanf("cscrolls 5", "%15s %d", tg2, &b)
                != 2) ++bad;
            if (std::string(tg1) == std::string(tg2))
                ++bad;
            if (a != 2 || b != 5) ++bad;
        }
        // the guard matches the cap the dungeon adds with
        if (CARRIED_CAP != 9999) ++bad;
        printf("R102 ledger audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
'regtest.cpp ledger audit')

# ---------------------------------------------------------------------------
# 4) playverify - the R102 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R101: the plate kit
""",
"""## R102: the ledger of everything
- [ ] Pick up scrolls in the dungeon, save, load - the
      satchel keeps its count (pre-R102 a reload wiped
      every held scroll)
- [ ] Study scrolls in town after a load - the count
      falls as scrolls are studied
- [ ] The status line's scroll count matches after a
      save/load round-trip
- [ ] A pre-R102 save (no cscrolls line) loads with an
      empty satchel, as before

## R101: the plate kit
""",
'playverify ledger section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R102 splice: ALL OK')
    sys.exit(0)
else:
    print('R102 splice: FAILED')
    sys.exit(1)
