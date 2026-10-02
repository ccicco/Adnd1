#!/usr/bin/env python3
# R121 splice: CREW OFFICERS (DMG p.35).
# The book: "Note that each master or captain
# will have at least one lieutenant and
# several mates ... For every 20 crewmen
# (sailors or oarsmen) there must be 1
# lieutenant and 2 mates." Wages: "Cost
# for masters, captains and lieutenants
# is 100 g.p. per month per level of
# experience" (a level-1 hire, documented
# simplification); mates are serjeants at
# 30 gp/month (p.34). Shares: "The master
# captain gets 25%, each lieutenant gets
# 5%, each mate 1%, and the crewmen share
# between them 5%. The remainder goes to
# the player character."
# R46 shipped 20 sailors at a flat 5%
# (its own comment admits "simplified")
# - this round closes the gap. No new
# save fields: the officers ride the
# existing crewHired flag (a fixed 20-
# sailor company implies 1 captain, 1
# lieutenant, 2 mates). Wages per return
# rise 40 -> 300 gp (crew 40 + captain
# 100 + lieutenant 100 + mates 60); the
# take's cut rises 5% -> 37% (captain 25,
# lieutenant 5, mates 2, crew 5), leaving
# the PC 63%.
# Battery audit pins the officer counts,
# both wage arithmetics, the share
# percentages for 20 and 40 crew, and
# the PC remainder; census becomes 39.
# Idempotent (marker checks per patch):
# run twice - the second run must print
# every patch already applied. ASCII-only.
# Refuses non-unique anchors,
# all-or-nothing.
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

PH_OLD = """inline int crewDriftPaid()   { return  2; }
inline int crewDriftUnpaid() { return -10; }
inline int crewDriftShare()  { return  3; }
inline int crewHireMorale()  { return  60; }
inline int crewDesertBelow() { return 25; }"""

PH_NEW = """inline int crewDriftPaid()   { return  2; }
inline int crewDriftUnpaid() { return -10; }
inline int crewDriftShare()  { return  3; }
inline int crewHireMorale()  { return  60; }
inline int crewDesertBelow() { return 25; }

// R121: SHIP'S OFFICERS (DMG p.35) - for every
// 20 crewmen there must be 1 lieutenant and 2
// mates (a short company still ships one
// lieutenant - ceiling, documented)
inline int crewLieutenantsFor(int crewmen) {
    if (crewmen <= 0) return 0;
    return (crewmen + 19) / 20;
}
inline int crewMatesFor(int crewmen) {
    return 2 * crewLieutenantsFor(crewmen);
}
// officers' wages per month: masters, captains and
// lieutenants 100 gp per level (a level-1 hire,
// documented simplification - the book prices by
// level); mates are serjeants at 30 gp (p.34).
// Billed each return (the delve cadence, R46)
inline int crewOfficerWages(int crewmen) {
    if (crewmen <= 0) return 0;
    return 100 +                                  // the captain
           100 * crewLieutenantsFor(crewmen) +    // lieutenants
           30  * crewMatesFor(crewmen);           // mates
}
// shares of a prize taken at sea or on land in
// their presence (DMG p.35): the captain 25%,
// each lieutenant 5%, each mate 1%, the crewmen
// 5% among themselves; the remainder is the PC's
inline int crewCaptainSharePct()    { return 25; }
inline int crewLieutenantSharePct() { return  5; }
inline int crewMateSharePct()       { return  1; }
inline int crewCrewSharePct()       { return  5; }
inline int crewOfficerSharePct(int crewmen) {
    return crewCaptainSharePct()
         + crewLieutenantSharePct() * crewLieutenantsFor(crewmen)
         + crewMateSharePct()       * crewMatesFor(crewmen);
}
inline int crewTotalSharePct(int crewmen) {
    return crewOfficerSharePct(crewmen) + crewCrewSharePct();
}"""

SC_OLD = """        if (party.crewHired && party.delveGold > 0) {
            crewCut = party.delveGold / 20;
            if (crewCut > 0) {
                // R105: a rich delve's share warms the
                // crew's nerve
                party.crewMorale = clampCrewMorale(
                    party.crewMorale + crewDriftShare());
                char cbuf[96];
                snprintf(cbuf, sizeof cbuf,
                         "The crew's share: %d gp.", crewCut);
                log.add(cbuf);
            }
        }"""

SC_NEW = """        if (party.crewHired && party.delveGold > 0) {
            // R121: the officers take their shares first
            // (DMG p.35) - the captain 25%, the lieutenant
            // 5%, the mates 1% each; then the crew's 5%
            crewCut = party.delveGold
                    * crewTotalSharePct(20) / 100;
            if (crewCut > 0) {
                // R105: a rich delve's share warms the
                // crew's nerve
                party.crewMorale = clampCrewMorale(
                    party.crewMorale + crewDriftShare());
                char cbuf[96];
                snprintf(cbuf, sizeof cbuf,
                         "Shares paid out: %d gp - captain "
                         "%d, lieutenant %d, mates %d, crew "
                         "%d.",
                         crewCut,
                         party.delveGold
                             * crewCaptainSharePct() / 100,
                         party.delveGold
                             * crewLieutenantSharePct() / 100,
                         party.delveGold
                             * crewMateSharePct()
                             * crewMatesFor(20) / 100,
                         party.delveGold
                             * crewCrewSharePct() / 100);
                log.add(cbuf);
            }
        }"""

SW_OLD = """        // R46: crew wages - 20 sailors at 2 gp (DMG p.34),
        // billed each return (delve cadence)
        if (party.crewHired) {
            // R105: an older save's crew arrives with an
            // unknown nerve - freshen it to the hire's 60
            if (party.crewMorale <= 0)
                party.crewMorale = crewHireMorale();
            if (party.gold >= 40) {
                party.gold -= 40;
                party.crewMorale = clampCrewMorale(
                    party.crewMorale + crewDriftPaid());
                log.add("The crew is paid 40 gp in wages.");"""

SW_NEW = """        // R46: crew wages - 20 sailors at 2 gp (DMG p.34),
        // billed each return (delve cadence); R121: plus the
        // officers (a captain, a lieutenant and two mates,
        // DMG p.35) - 40 + 260 = 300 gp
        if (party.crewHired) {
            // R105: an older save's crew arrives with an
            // unknown nerve - freshen it to the hire's 60
            if (party.crewMorale <= 0)
                party.crewMorale = crewHireMorale();
            int wages = 20 * 2 + crewOfficerWages(20);
            if (party.gold >= wages) {
                party.gold -= wages;
                party.crewMorale = clampCrewMorale(
                    party.crewMorale + crewDriftPaid());
                char wbuf[96];
                snprintf(wbuf, sizeof wbuf,
                         "The company is paid %d gp in "
                         "wages (crew 40, officers %d).",
                         wages, crewOfficerWages(20));
                log.add(wbuf);"""

SH_OLD = """        party.crewHired = true;
        party.crewMorale = crewHireMorale();   // R105
        log.add("A coaster's company of twenty signs on. "
                "They will ferry your takings to market.");"""

SH_NEW = """        party.crewHired = true;
        party.crewMorale = crewHireMorale();   // R105
        log.add("A coaster's company signs on - twenty "
                "sailors, a captain, a lieutenant and two "
                "mates (DMG p.35). They will ferry your "
                "takings to market.");"""

AC1_OLD = """// ship crew - [C] hires a 20-sailor coaster's company
// (200 gp down); upkeep 40 gp each return, and the crew
// takes 5% of every delve's take at the exit; (5) room"""

AC1_NEW = """// ship crew - [C] hires a 20-sailor coaster's company
// (200 gp down); upkeep 300 gp each return (20 sailors plus
// a captain, a lieutenant and two mates, DMG p.35), and the
// company takes 37% of every delve's take at the exit
// (captain 25, lieutenant 5, mates 2, crew 5); (5) room"""

AC2_OLD = """    // R46: [C] hire a ship's crew - a 20-sailor coaster's
    // company (DMG p.34-35 simplified: 200 gp down, 40 gp
    // wages each return, 5% of every take at the exit)
    void townHireCrew();"""

AC2_NEW = """    // R46: [C] hire a ship's crew - a 20-sailor coaster's
    // company; R121: with officers (DMG p.35) - 200 gp down,
    // 300 gp wages each return, 37% of every take at the
    // exit (captain 25, lieutenant 5, mates 2, crew 5)
    void townHireCrew();"""

RT_OLD = """        printf("R120 parley and listening audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

RT_NEW = """        printf("R120 parley and listening audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R121: crew officers audit ----
    {
        int bad = 0;
        // the book (DMG p.35): for every 20 crewmen,
        // 1 lieutenant and 2 mates
        if (crewLieutenantsFor(20) != 1) ++bad;
        if (crewMatesFor(20) != 2)       ++bad;
        if (crewLieutenantsFor(40) != 2) ++bad;
        if (crewMatesFor(40) != 4)       ++bad;
        // a short company still ships one lieutenant
        if (crewLieutenantsFor(19) != 1) ++bad;
        if (crewMatesFor(19) != 2)       ++bad;
        // no crew, no officers
        if (crewLieutenantsFor(0) != 0)  ++bad;
        if (crewMatesFor(0) != 0)        ++bad;
        if (crewOfficerWages(0) != 0)   ++bad;
        // wages: captain 100 + lieutenant 100 + mates 60
        // (100 gp/level, L1 hires - documented; mates are
        // serjeants at 30 gp, p.34)
        if (crewOfficerWages(20) != 260) ++bad;
        if (crewOfficerWages(40) != 420) ++bad;
        // shares (DMG p.35): captain 25, each lieutenant 5,
        // each mate 1, crew 5 - and the PC keeps the rest
        if (crewCaptainSharePct()    != 25) ++bad;
        if (crewLieutenantSharePct() !=  5) ++bad;
        if (crewMateSharePct()       !=  1) ++bad;
        if (crewCrewSharePct()       !=  5) ++bad;
        if (crewOfficerSharePct(20)  != 32) ++bad;
        if (crewTotalSharePct(20)    != 37) ++bad;
        if (crewOfficerSharePct(40)  != 39) ++bad;
        if (crewTotalSharePct(40)    != 44) ++bad;
        if (100 - crewTotalSharePct(20) != 63) ++bad;
        printf("R121 crew officers audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

GH_OLD = """R120 WIRED parley (R117's reaction roll
gates room and wandering encounters;
only the starred bands attack) and
listening at doors ([H], R118's table) -
first callers for both.

Categories:"""

GH_NEW = """R120 WIRED parley (R117's reaction roll
gates room and wandering encounters;
only the starred bands attack) and
listening at doors ([H], R118's table) -
first callers for both.
R121 CLOSED crew officers (p.35) - a
captain, a lieutenant and two mates
join the crew: wages 40 -> 300 gp, the
take's cut 5% -> 37% (PC keeps 63%).

Categories:"""

GB_OLD = """- [ ] **Crew officers (p.35)** - officers and
      their shares beyond the crew's 5%."""

GB_NEW = """- [x] **Crew officers (p.35)** - CLOSED R121:
      for every 20 crewmen the book requires
      1 lieutenant and 2 mates; the coaster's
      company (R46, which admitted its
      simplification) now ships a captain,
      a lieutenant and two mates. Wages:
      masters/captains/lieutenants 100 gp per
      level per month (L1 hires - documented
      simplification; the book prices by
      level), mates are serjeants at 30 gp
      (p.34) - 40 gp becomes 300 gp per
      return. Shares: the captain 25%, the
      lieutenant 5%, the mates 1% each, the
      crew 5% among themselves (37% total;
      the PC keeps 63%). No new save fields -
      the officers ride the crewHired flag.
      Pinned by the R121 battery audit."""


# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("game/party.h", "inline int crewLieutenantsFor(int crewmen) {",
     PH_OLD, PH_NEW, "party.h crew-officer helpers"),
    ("game/state_town.cpp", "crewTotalSharePct(20) / 100;",
     SC_OLD, SC_NEW, "state_town officer shares"),
    ("game/state_town.cpp", "The company is paid %d gp in ",
     SW_OLD, SW_NEW, "state_town officer wages"),
    ("game/state_town.cpp", "mates (DMG p.35). They will ferry",
     SH_OLD, SH_NEW, "state_town hire log"),
    ("game/appstate.h", "37% of every delve's take at the exit",
     AC1_OLD, AC1_NEW, "appstate.h crew comment"),
    ("game/appstate.h", "300 gp wages each return",
     AC2_OLD, AC2_NEW, "appstate.h hire decl comment"),
    ("regtest.cpp", "R121 crew officers audit",
     RT_OLD, RT_NEW, "regtest R121 audit"),
    ("tools/dmg_gap_report.md", "R121 CLOSED crew officers",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "for every 20 crewmen the book",
     GB_OLD, GB_NEW, "gap report crew officers box"),
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
        print("R121 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R121 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R121 splice: nothing to do (already applied)")
    else:
        print("R121 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
