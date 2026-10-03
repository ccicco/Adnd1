#!/usr/bin/env python3
# tools/r137_splice.py - R137 the deliberate-engage hook:
# sight no longer springs a special room's curiosity -
# the company chooses (the X key engages).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/appendixgh.h: trickEngagePrompt() - the pure
#    prompt phrase (the battery pins it exact)
#  - game/appstate.h: engageTrick() declared
#  - game/state_dungeon.cpp: engageTrick() defined (the
#    current room's unfired mechanical feature fires;
#    guidance otherwise)
#  - game/state_town.cpp: describeRoom announces and
#    prompts instead of auto-firing
#  - adnd1.cpp: the dungeon X key calls engageTrick
#  - regtest.cpp: the R137 hook audit (census 55)
#  - tools/dmg_gap_report.md: the R137 box closes the
#    standing deliberate-engage debt
# This file contains ZERO backslash characters - the
# audit printf's escaped newline is assembled from
# chr(92), which nothing can eat (the R133b lesson).
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BS = chr(92)   # one backslash
NL = chr(10)   # one newline
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

patch("dm/appendixgh.h",
"""inline std::string trickSummary(int f, int a) {
    return std::string(trickFeatureName(f)) + " (" +
           trickAttributeName(a) + ")";
}

// R128: the first-effects slice - the five attributes the
""",
"""inline std::string trickSummary(int f, int a) {
    return std::string(trickFeatureName(f)) + " (" +
           trickAttributeName(a) + ")";
}

// R137: the deliberate-engage hook - the prompt phrase
// the dungeon logs when a mechanical curiosity is first
// sighted (the sight alone no longer springs the
// feature; the company chooses: X to engage, or move
// on). Pure data - the battery pins the exact phrase.
inline const char* trickEngagePrompt() {
    return "Press X to engage the feature - or move on.";
}

// R128: the first-effects slice - the five attributes the
""",
      "appendixgh.h: trickEngagePrompt",
      marker="trickEngagePrompt()")

patch("game/appstate.h",
"""    void applyTrick(int roomIndex);
""",
"""    void applyTrick(int roomIndex);

    // R137: the deliberate-engage hook - the company
    // chooses to engage the current room's trick (the
    // X key in the dungeon); the first sight no longer
    // springs the feature.
    void engageTrick();
""",
      "appstate.h: engageTrick declared",
      marker="void engageTrick();")

patch("game/state_dungeon.cpp",
"""// ---- applyTrick ----
void AppState::applyTrick(int roomIndex){
""",
"""// ---- engageTrick ----
// R137: the deliberate-engage hook - the company chooses
// (the X key in the dungeon) to engage the current
// room's curiosity; the first sight no longer springs
// it (describeRoom only announces and prompts).
void AppState::engageTrick(){
        if (!party.alive()) return;
        int roomIndex = roomAt(party.x, party.y);
        if (roomIndex < 0) {
            log.add("There is nothing here to engage - "
                    "step inside a room first.");
            return;
        }
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.trickFeature < 0 ||
            !room.monsterKey.empty() || room.trickDone) {
            log.add("Nothing here begs engaging.");
            return;
        }
        if (!dm::appendixh::trickIsMechanical(
                room.trickAttribute)) {
            log.add("The feature only mutters - it "
                    "ignores the company.");
            return;
        }
        room.trickDone = true;
        applyTrick(roomIndex);
}

// ---- applyTrick ----
void AppState::applyTrick(int roomIndex){
""",
      "state_dungeon.cpp: engageTrick defined",
      marker="void AppState::engageTrick(){")

patch("game/state_town.cpp",
"""        // R128: the special room - an Appendix H curiosity
        // commands the chamber (rolled at populate for an
        // unoccupied, untrapped room). The mechanical slice
        // pays out once per populate (trickDone).
        if (room.trickFeature >= 0 && room.monsterKey.empty()) {
            log.add("Something odd commands the room: " +
                    dm::appendixh::trickSummary(
                        room.trickFeature,
                        room.trickAttribute) + ".");
            if (dm::appendixh::trickIsMechanical(
                    room.trickAttribute) && !room.trickDone) {
                room.trickDone = true;
                applyTrick(roomIndex);
            }
            return;
        }
""",
"""        // R128: the special room - an Appendix H curiosity
        // commands the chamber (rolled at populate for an
        // unoccupied, untrapped room). The mechanical slice
        // pays out once per populate (trickDone). R137: the
        // payout now waits for a deliberate engage (the X
        // key) - the first sight no longer springs it.
        if (room.trickFeature >= 0 && room.monsterKey.empty()) {
            log.add("Something odd commands the room: " +
                    dm::appendixh::trickSummary(
                        room.trickFeature,
                        room.trickAttribute) + ".");
            if (dm::appendixh::trickIsMechanical(
                    room.trickAttribute) && !room.trickDone) {
                log.add(dm::appendixh::trickEngagePrompt());
            }
            return;
        }
""",
      "state_town.cpp: describeRoom prompts",
      marker="log.add(dm::appendixh::trickEngagePrompt());")

patch("adnd1.cpp",
"""                    case 'L':
                    case 'l':
                        g_app.loadGame();
                        break;

                    case VK_ESCAPE:
                        PostQuitMessage(0);
                        return 0;
""",
"""                    case 'L':
                    case 'l':
                        g_app.loadGame();
                        break;

                    // R137: the deliberate-engage hook - the
                    // company chooses to spring the current
                    // room's curiosity
                    case 'X':
                    case 'x':
                        g_app.engageTrick();
                        break;

                    case VK_ESCAPE:
                        PostQuitMessage(0);
                        return 0;
""",
      "adnd1.cpp: the dungeon X key",
      marker="g_app.engageTrick();")

r137_lines = [
"    // ---- R137: deliberate-engage hook audit ----",
"    // The hook's pure surface: the engage prompt the",
"    // dungeon logs on first sight (sight alone no longer",
"    // springs a mechanical curiosity - the company",
"    // chooses; the X key engages).",
"    {",
"        int bad = 0;",
"        const char* p = dm::appendixh::trickEngagePrompt();",
"        if (!p || !*p) ++bad;",
"        if (std::string(p) !=",
"            " + chr(34) + "Press X to engage the feature - or move on." + chr(34) + ")",
"            ++bad;",
"        for (const char* q = p; q && *q; ++q)",
"            if ((unsigned char)*q > 127) ++bad;",
"        printf(" + chr(34) + "R137 deliberate-engage hook audit: bad %d"
        + BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
""]
r137_audit = NL.join(r137_lines)
old_r136_head = "    // ---- R136: odds-and-ends slice audit ----"
patch("regtest.cpp", old_r136_head + NL,
      r137_audit + NL + old_r136_head + NL,
      "regtest.cpp: R137 audit",
      marker="R137 deliberate-engage hook audit")

patch("tools/dmg_gap_report.md",
"""      attributes stay dressing; their effects ride
      future rounds. Pinned by the R136 battery audit;
      census 54.

## Out of scope by design
""",
"""      attributes stay dressing; their effects ride
      future rounds. Pinned by the R136 battery audit;
      census 54.
- [x] **Deliberate-engage hook (the standing debt)** -
      CLOSED R137: the special-rooms layer no longer
      springs a mechanical curiosity on first sight -
      describeRoom announces the feature and prompts;
      the company chooses. The X key (dungeon mode)
      calls engageTrick: inside a trick room with an
      unfired mechanical feature it fires (trickDone
      set, applyTrick); elsewhere it logs guidance.
      The prompt phrase is pure data
      (trickEngagePrompt, dm/appendixgh.h) and the
      battery pins it exact. Pinned by the R137 hook
      audit; census 55.

## Out of scope by design
""",
      "gap report: R137 box",
      marker="CLOSED R137: the")

# ---- R137 fails/tail ----
if fails:
    print("R137 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R137 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R137 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
