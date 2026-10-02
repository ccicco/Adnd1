#!/usr/bin/env python3
# R119 splice: forced rest (DMG p.38, OCR
# page-039.md, TIME IN THE DUNGEON). The
# book: "A party should be required to
# rest at least one turn in six ...
# in addition, they should rest a turn
# after every time they engage in combat
# or any other strenuous activities."
# The repo had voluntary camp ([R]) but
# no forced-rest rule - a WIRING round,
# the book's requirement made a gate.
# Shape: pure helpers in party.h (the
# one-in-six threshold, the strenuous
# turn) pin-able by the battery; state
# in appstate.h (turnsSinceRest /
# restOwed / mustRest); tickActivity
# counts every active turn (movement
# ticks and the [F] search); endCombat
# owes a turn (the book's after-combat
# rest); when rest is due the explore
# gate closes - too winded to press on -
# until a COMPLETED rest (the camp [R]
# or the inn) pays the debt (interrupted
# camps restore nothing, fatigue
# included - the slots precedent).
# Battery audit pins the threshold edges
# and the strenuous turn; census becomes
# 37. Idempotent (marker checks per
# patch): run twice - the second run must
# print every patch already applied.
# ASCII-only. Refuses non-unique
# anchors, all-or-nothing.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii") as f:
        f.write(text)


def replace_exact(text, old, new, label):
    n = text.count(old)
    if n != 1:
        print("REFUSED " + label + ": anchor not unique or missing (count %d)" % n)
        return text, False
    return text.replace(old, new, 1), True


# ---- patch bodies ----------------------------------------------------------

PH_OLD = """inline int restTurns(bool interrupted) {
    return interrupted ? 4 : 48;
}

// R91: what the stairs cost - 36 turns"""

PH_NEW = """inline int restTurns(bool interrupted) {
    return interrupted ? 4 : 48;
}

// R119: forced rest (DMG p.38, TIME IN THE DUNGEON):
// a party rests at least one turn in six - five
// active turns are allowed, the sixth is owed.
inline bool forcedRestDue(int turnsSinceRest) {
    return turnsSinceRest >= 5;
}

// R119: combat (or any other strenuous activity)
// owes a turn of rest (DMG p.38)
inline int strenuousRestTurns() {
    return 1;
}

// R91: what the stairs cost - 36 turns"""

AP_OLD = """    int           turnCount = 0;
    int           moveDebt   = 0;   // R89: pace tenths owed"""

AP_NEW = """    int           turnCount = 0;
    int           moveDebt   = 0;   // R89: pace tenths owed
    int           turnsSinceRest = 0; // R119: active turns since rest
    bool          restOwed  = false;  // R119: combat owes a turn (p.38)
    bool          mustRest  = false;  // R119: the gate - camp [R] to clear"""

AD_OLD = """    void restExplore();

    int countOccupied() const;"""

AD_NEW = """    void restExplore();

    // R119: forced rest (DMG p.38) - one turn in six,
    // plus a turn after combat; when due, explore
    // movement gates until the company camps ([R];
    // the inn clears it too)
    void tickActivity(int turns);

    int countOccupied() const;"""

SD_OLD = """        restoreSlots();
        // R38: a completed rest renews arrows too - fletching and"""

SD_NEW = """        // R119: the completed rest pays the forced-rest
        // debt (DMG p.38); interrupted camps restore
        // nothing, fatigue included (slots precedent)
        turnsSinceRest = 0;
        restOwed = false;
        mustRest = false;
        restoreSlots();
        // R38: a completed rest renews arrows too - fletching and"""

SC_OLD = """// ---- countOccupied ----"""

SC_NEW = """// ---- tickActivity ----
// R119: forced-rest bookkeeping (DMG p.38): every
// active turn counts toward the one-in-six rest;
// the sixth is owed and the gate closes until a
// completed camp pays it.
void AppState::tickActivity(int turns){
        if (turns <= 0) return;
        turnsSinceRest += turns;
        if (forcedRestDue(turnsSinceRest)) {
            if (!mustRest)
                log.add("The company is worn - a rest is due. [R]");
            mustRest = true;
        }
    }

// ---- countOccupied ----"""

SE_OLD = """        ++turnCount;
        bool hasThief = false;"""

SE_NEW = """        ++turnCount;
        tickActivity(1);   // R119: the search is activity too
        bool hasThief = false;"""

CB_OLD = """        combat.encounter.reset();
        mode = combatReturnMode;   // R68: back to the trail"""

CB_NEW = """        // R119: forced rest (DMG p.38) - the fight spent
        // them; a turn of rest is owed once back on the
        // trail (a wiped company demands nothing)
        if (party.alive()) {
            restOwed = true;
            mustRest = true;
            log.add("The company is winded - a rest is owed. [R]");
        }
        combat.encounter.reset();
        mode = combatReturnMode;   // R68: back to the trail"""

TW_OLD = """        ++party.careerDays;
        restoreSlots();"""

TW_NEW = """        ++party.careerDays;
        // R119: a night at the inn is a completed rest
        // too - the forced-rest debt clears (DMG p.38)
        turnsSinceRest = 0;
        restOwed = false;
        mustRest = false;
        restoreSlots();"""

SH_OLD = """static void onPartyMove(int dx, int dy) {
    AppState& s = g_app;
    if (s.mode != MODE_EXPLORE) return;
    if (!s.party.alive()) return;"""

SH_NEW = """static void onPartyMove(int dx, int dy) {
    AppState& s = g_app;
    if (s.mode != MODE_EXPLORE) return;
    if (!s.party.alive()) return;
    // R119: forced rest (DMG p.38) - when the one-in-six
    // rest (or the post-combat turn) is owed, the company
    // is too winded to press on; camp with [R]
    if (s.mustRest) {
        s.log.add("Too winded to press on - rest first. [R]");
        return;
    }"""

ST_OLD = """    s.turnCount += ticked;"""

ST_NEW = """    s.turnCount += ticked;
    s.tickActivity(ticked);   // R119: the one-in-six clock"""

NC_OLD = """        turnCount = 0;
        moveDebt   = 0;"""

NC_NEW = """        turnCount = 0;
        moveDebt   = 0;
        turnsSinceRest = 0;   // R119: a fresh delve, fresh legs
        restOwed  = false;
        mustRest  = false;"""

RT_OLD = """        printf("R118 listening at doors audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

RT_NEW = """        printf("R118 listening at doors audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R119: forced rest audit ----
    {
        int bad = 0;
        // the book (DMG p.38): rest at least one turn
        // in six - turns 1-5 may be activity, the
        // sixth is owed
        if (forcedRestDue(0)) ++bad;
        if (forcedRestDue(1)) ++bad;
        if (forcedRestDue(4)) ++bad;
        if (!forcedRestDue(5)) ++bad;
        if (!forcedRestDue(6)) ++bad;
        if (!forcedRestDue(30)) ++bad;
        // combat or any other strenuous activity owes
        // a turn of rest (DMG p.38)
        if (strenuousRestTurns() != 1) ++bad;
        printf("R119 forced rest audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

GH_OLD = """R118 CLOSED listening at doors (p.60) -
the book's racial d20 table replaces R11's
d6 bands; abilities.cpp joins the battery
build (it was compiled by nothing).

Categories:"""

GH_NEW = """R118 CLOSED listening at doors (p.60) -
the book's racial d20 table replaces R11's
d6 bands; abilities.cpp joins the battery
build (it was compiled by nothing).
R119 CLOSED forced rest (p.38) - one turn
in six plus a turn after combat, gated.

Categories:"""

GB_OLD = """- [ ] **Forced rest (p.38)** - characters
      forced to rest after extended strain."""

GB_NEW = """- [x] **Forced rest (p.38)** - CLOSED
      R119: the book requires rest at
      least one turn in six, plus a turn
      after every combat or other
      strenuous activity. Pure helpers
      (forcedRestDue: five active turns,
      the sixth owed; strenuousRestTurns:
      one) pin-able by the battery;
      tickActivity counts every active
      turn (movement ticks and the [F]
      search); endCombat owes the turn
      for a living company; when rest is
      due the explore gate closes (too
      winded to press on) until a
      COMPLETED rest pays it - the camp
      [R] or the inn (interrupted camps
      restore nothing, fatigue included;
      the slots precedent). A fresh
      delve starts fresh-legged. Pinned
      by the R119 battery audit."""


# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("game/party.h", "inline bool forcedRestDue(int turnsSinceRest) {",
     PH_OLD, PH_NEW, "party.h forced-rest helpers"),
    ("game/appstate.h", "int           turnsSinceRest = 0;",
     AP_OLD, AP_NEW, "appstate.h fatigue fields"),
    ("game/appstate.h", "void tickActivity(int turns);",
     AD_OLD, AD_NEW, "appstate.h tickActivity decl"),
    ("game/state_dungeon.cpp", "turnsSinceRest = 0;\n        restOwed = false;\n        mustRest = false;\n        restoreSlots();",
     SD_OLD, SD_NEW, "state_dungeon camp clears fatigue"),
    ("game/state_dungeon.cpp", "void AppState::tickActivity(int turns){",
     SC_OLD, SC_NEW, "state_dungeon tickActivity impl"),
    ("game/state_dungeon.cpp", "tickActivity(1);   // R119: the search is activity too",
     SE_OLD, SE_NEW, "state_dungeon search ticks"),
    ("game/state_combat.cpp", "restOwed = true;\n            mustRest = true;",
     CB_OLD, CB_NEW, "state_combat owes the turn"),
    ("game/state_town.cpp", "turnsSinceRest = 0;\n        restOwed = false;\n        mustRest = false;\n        restoreSlots();",
     TW_OLD, TW_NEW, "state_town inn clears fatigue"),
    ("adnd1.cpp", "if (s.mustRest) {",
     SH_OLD, SH_NEW, "adnd1 movement gate"),
    ("adnd1.cpp", "s.tickActivity(ticked);",
     ST_OLD, ST_NEW, "adnd1 movement ticks activity"),
    ("game/state_core.cpp", "turnsSinceRest = 0;   // R119: a fresh delve, fresh legs",
     NC_OLD, NC_NEW, "state_core new-dungeon reset"),
    ("regtest.cpp", "R119 forced rest audit",
     RT_OLD, RT_NEW, "regtest R119 audit"),
    ("tools/dmg_gap_report.md", "R119 CLOSED forced rest",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "R119: the book requires rest",
     GB_OLD, GB_NEW, "gap report forced rest box"),
]


def main():
    # all-or-nothing: compute every patch, write only if
    # every patch applied or was already applied
    texts = {}
    applied = 0
    already = 0
    failed = []
    for rel, marker, old, new, label in PATCHES:
        if rel not in texts:
            texts[rel] = read(rel)
        t = texts[rel]
        if marker in t:
            print("already applied: " + label)
            already += 1
        else:
            t2, did = replace_exact(t, old, new, label)
            if not did:
                failed.append(label)
            else:
                texts[rel] = t2
                applied += 1
    if failed:
        print("R119 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R119 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R119 splice: nothing to do (already applied)")
    else:
        print("R119 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()

# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("game/party.h", "inline bool forcedRestDue(int turnsSinceRest) {",
     PH_OLD, PH_NEW, "party.h forced-rest helpers"),
    ("game/appstate.h", "int           turnsSinceRest = 0;",
     AP_OLD, AP_NEW, "appstate.h fatigue fields"),
    ("game/appstate.h", "void tickActivity(int turns);",
     AD_OLD, AD_NEW, "appstate.h tickActivity decl"),
    ("game/state_dungeon.cpp", "turnsSinceRest = 0;\n        restOwed = false;\n        mustRest = false;\n        restoreSlots();",
     SD_OLD, SD_NEW, "state_dungeon camp clears fatigue"),
    ("game/state_dungeon.cpp", "void AppState::tickActivity(int turns){",
     SC_OLD, SC_NEW, "state_dungeon tickActivity impl"),
    ("game/state_dungeon.cpp", "tickActivity(1);   // R119: the search is activity too",
     SE_OLD, SE_NEW, "state_dungeon search ticks"),
    ("game/state_combat.cpp", "restOwed = true;\n            mustRest = true;",
     CB_OLD, CB_NEW, "state_combat owes the turn"),
    ("game/state_town.cpp", "turnsSinceRest = 0;\n        restOwed = false;\n        mustRest = false;\n        restoreSlots();",
     TW_OLD, TW_NEW, "state_town inn clears fatigue"),
    ("adnd1.cpp", "if (s.mustRest) {",
     SH_OLD, SH_NEW, "adnd1 movement gate"),
    ("adnd1.cpp", "s.tickActivity(ticked);",
     ST_OLD, ST_NEW, "adnd1 movement ticks activity"),
    ("game/state_core.cpp", "turnsSinceRest = 0;   // R119: a fresh delve, fresh legs",
     NC_OLD, NC_NEW, "state_core new-dungeon reset"),
    ("regtest.cpp", "R119 forced rest audit",
     RT_OLD, RT_NEW, "regtest R119 audit"),
    ("tools/dmg_gap_report.md", "R119 CLOSED forced rest",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "R119: the book requires rest",
     GB_OLD, GB_NEW, "gap report forced rest box"),
]


def main():
    # all-or-nothing: compute every patch, write only if
    # every patch applied or was already applied
    texts = {}
    applied = 0
    already = 0
    failed = []
    for rel, marker, old, new, label in PATCHES:
        if rel not in texts:
            texts[rel] = read(rel)
        t = texts[rel]
        if marker in t:
            print("already applied: " + label)
            already += 1
        else:
            t2, did = replace_exact(t, old, new, label)
            if not did:
                failed.append(label)
            else:
                texts[rel] = t2
                applied += 1
    if failed:
        print("R119 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R119 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R119 splice: nothing to do (already applied)")
    else:
        print("R119 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
