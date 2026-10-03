#!/usr/bin/python3
# tools/r131_splice.py - R131 per-day slot plumbing 6 -> 9
# (the named R130 debt: the printed tables made levels 7-9
# real, this makes them castable in play).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - game/party.h + ai/actor.h: both slotsByLevel arrays
#    widened to 9 (slots are not saved - restoreSlots
#    rebuilds the pool from the tables on load, so the
#    widen is v1-save-compatible)
#  - every fill/copy/carry loop widened with them: the
#    creation-time pool (appstate.h), restoreSlots and
#    the level-up rest-like refill (state_core.cpp), the
#    encounter spawn fill and the post-combat spent-slot
#    copy-back (state_combat.cpp), toActor's pool carry
#    (party.h), and the foe cleric cast gate (actor.cpp)
#  - regtest.cpp: the R131 slot plumbing audit pins the
#    nine-deep arrays, the zero defaults, and toActor's
#    carry of the 7th-9th columns (census 49)
#  - tools/dmg_gap_report.md: the R131 box closes the debt
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

patch("game/party.h",
"""    // R34: per-day spell slots by level (index 0 = spell level
    // 1). Persisted across encounters; restored by rest.
    // R46: widened to 6 levels (L4+ data pending; the spells::
    // slot tables already carry the columns).
    int  slotsByLevel[6] = {0, 0, 0, 0, 0, 0};
""",
"""    // R34: per-day spell slots by level (index 0 = spell level
    // 1). Persisted across encounters; restored by rest.
    // R131: widened to 9 levels - the R130 printed tables made
    // levels 7-9 real. Slots are NOT saved: restoreSlots
    // rebuilds the full pool from the tables on load, so the
    // widen is v1-save-compatible.
    int  slotsByLevel[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
""",
      "party.h: Character slots 9",
      marker="R131: widened to 9 levels")

patch("game/party.h",
"""        // R34: slots persist - toActor carries the CURRENT pool
        // (the app restores it on rest, not per encounter)
        for (int lv = 0; lv < 6; ++lv)
            a.slotsByLevel[lv] = slotsByLevel[lv];
""",
"""        // R34: slots persist - toActor carries the CURRENT pool
        // (the app restores it on rest, not per encounter)
        // R131: all nine columns (the 7th-9th ride with the
        // printed name-level tables)
        for (int lv = 0; lv < 9; ++lv)
            a.slotsByLevel[lv] = slotsByLevel[lv];
""",
      "party.h: toActor carries nine",
      marker="R131: all nine columns")

patch("ai/actor.h",
"""    int  slotsByLevel[6] = {0, 0, 0, 0, 0, 0};   // R46: 6 levels
""",
"""    int  slotsByLevel[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};   // R131: 9 levels (the R130 tables)
""",
      "actor.h: Actor slots 9",
      marker="R131: 9 levels (the R130 tables)")

patch("ai/actor.cpp",
"""    if (a.classIndex == rules::CLASS_CLERIC) {
        for (int lv = 0; lv < 6; ++lv)
            if (a.slotsByLevel[lv] > 0) return true;
    }
""",
"""    if (a.classIndex == rules::CLASS_CLERIC) {
        // R131: all nine columns - a 7th-circle slot counts
        for (int lv = 0; lv < 9; ++lv)
            if (a.slotsByLevel[lv] > 0) return true;
    }
""",
      "actor.cpp: foe cleric gate nine",
      marker="R131: all nine columns - a 7th-circle slot counts")

patch("game/appstate.h",
"""            for (int lv = 1; lv <= 6; ++lv)   // R46: 6 levels
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(sc, 1, lv);
""",
"""            for (int lv = 1; lv <= 9; ++lv)   // R131: 9 levels
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(sc, 1, lv);
""",
      "appstate.h: creation pool nine",
      marker="R131: 9 levels")

patch("game/state_core.cpp",
"""            for (int lv = 1; lv <= 6; ++lv)   // R46: 6 levels
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(sc, c.level, lv);
""",
"""            for (int lv = 1; lv <= 9; ++lv)   // R131: 9 levels
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(sc, c.level, lv);
""",
      "state_core.cpp: restoreSlots nine",
      marker="R131: 9 levels")

patch("game/state_combat.cpp",
"""                for (int lv = 0; lv < 6; ++lv)
                    a.slotsByLevel[lv] = spells::spellSlots(
                        sc, a.level, lv + 1);
""",
"""                // R131: all nine columns - a name-level foe
                // caster spawns with 7th-9th circle slots
                for (int lv = 0; lv < 9; ++lv)
                    a.slotsByLevel[lv] = spells::spellSlots(
                        sc, a.level, lv + 1);
""",
      "state_combat.cpp: spawn fill nine",
      marker="R131: all nine columns - a name-level foe")

patch("game/state_combat.cpp",
"""                    // R34: spent slots persist (per-day tracking)
                    for (int lv = 0; lv < 6; ++lv)   // R46
                        c.slotsByLevel[lv] = a.slotsByLevel[lv];
""",
"""                    // R34: spent slots persist (per-day tracking)
                    // R131: all nine columns ride home spent
                    for (int lv = 0; lv < 9; ++lv)   // R131
                        c.slotsByLevel[lv] = a.slotsByLevel[lv];
""",
      "state_combat.cpp: spent-copy nine",
      marker="R131: all nine columns ride home spent")

# R131-CHUNK-1-END

patch("regtest.cpp",
"""    // ---- R129: caster aging audit ----
""",
"""    // ---- R131: slot plumbing audit ----
    // The R130 tables made levels 7-9 real; this pins the
    // per-day plumbing that carries them (the named R130
    // debt): both arrays nine deep and zero-defaulted,
    // and toActor carries the 7th-9th columns to the
    // encounter party (the fill/copy loops are app-side -
    // pinned by the R130 table values they draw from).
    {
        int bad = 0;
        Character c;
        // the Character pool is nine deep and zeroed
        if (sizeof(c.slotsByLevel) != 9 * sizeof(int)) ++bad;
        for (int lv = 0; lv < 9; ++lv)
            if (c.slotsByLevel[lv] != 0) ++bad;
        // the Actor pool likewise
        ai::Actor a0;
        if (sizeof(a0.slotsByLevel) != 9 * sizeof(int)) ++bad;
        for (int lv = 0; lv < 9; ++lv)
            if (a0.slotsByLevel[lv] != 0) ++bad;
        // toActor carries the high columns (index 6-8 =
        // spell levels 7-9)
        c.classIndex = 1;   // MU
        c.level = 18;
        c.slotsByLevel[6] = 1;   // a 7th-circle slot
        c.slotsByLevel[7] = 2;   // 8th
        c.slotsByLevel[8] = 1;   // 9th (the Wish circle)
        ai::Actor a = c.toActor();
        if (a.slotsByLevel[6] != 1) ++bad;
        if (a.slotsByLevel[7] != 2) ++bad;
        if (a.slotsByLevel[8] != 1) ++bad;
        printf("R131 slot plumbing audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R129: caster aging audit ----
""",
      "regtest.cpp: R131 slot plumbing audit",
      marker="R131 slot plumbing audit")

patch("tools/dmg_gap_report.md",
"""      rounds. Pinned by the R130 battery audit;
      census 48.

## Out of scope by design
""",
"""      rounds. Pinned by the R130 battery audit;
      census 48.
- [x] **Per-day slot plumbing 6 -> 9 (the R130
      named debt)** - CLOSED R131: both
      slotsByLevel arrays (Character and the
      combat Actor) widened to nine, and every
      loop that touches them widened with them:
      the creation-time pool, restoreSlots (the
      load-time rebuild - slots are not saved,
      so the widen is v1-save-compatible), the
      level-up rest-like refill, the encounter
      spawn fill, the post-combat spent-slot
      copy-back, toActor's pool carry, and the
      foe cleric cast gate. Levels 7-9 are now
      castable in play at name level (the R129
      caster-aging spells resolve end to end).
      The wisdom footnotes stay engine limits;
      the printed tables still ride the
      verification debt. Pinned by the R131
      battery audit; census 49.

## Out of scope by design
""",
      "gap report: R131 box",
      marker="CLOSED R131: both")

# ---- R131 fails/tail ----
if fails:
    print("R131 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R131 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R131 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
