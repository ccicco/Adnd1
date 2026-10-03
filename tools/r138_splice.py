#!/usr/bin/env python3
# tools/r138_splice.py - R138 the talk-flavor parley hook:
# the talks-class Appendix H attributes answer the
# deliberate-engage hook - the X key in a talky trick
# room logs the attribute's flavor line (repeatable;
# talk never spends the trick).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/appendixgh.h: trickIsTalky() + trickTalkLine()
#    (the eleven talks-class attributes stay NON-
#    mechanical by design - pure data, battery-pinned)
#  - game/state_dungeon.cpp: engageTrick's talky branch
#  - game/state_town.cpp: describeRoom prompts for a
#    talky feature too (the X key answers)
#  - regtest.cpp: the R138 parley audit (census 56)
#  - tools/dmg_gap_report.md: the R138 box closes the
#    talk-flavor standing debt
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
"""inline bool trickIsMechanical(int a) {
""",
"""// ---- R138: the talk-flavor parley ----
// The talks-class attributes stay NON-mechanical by
// design: they answer the deliberate-engage hook (the
// X key) with the line below - repeatable flavor;
// talk never spends the trick. Pure data - the
// battery pins the eleven-line set.
inline bool trickIsTalky(int a) {
    return a == TA_ASKS || a == TA_DIRECTS ||
           a == TA_POINTS || a == TA_SUGGESTS ||
           a == TA_INTELLIGENT ||
           a == TA_TALKS_SMART ||
           a == TA_TALKS_NONSENSE ||
           a == TA_TALKS_POETRY ||
           a == TA_TALKS_SINGING ||
           a == TA_TALKS_SPELLS ||
           a == TA_TALKS_YELLS;
}

inline const char* trickTalkLine(int a) {
    if (a == TA_ASKS)
        return "The feature asks after your quest - "
               "and waits.";
    if (a == TA_DIRECTS)
        return "The feature directs you down a "
               "corridor to the west.";
    if (a == TA_POINTS)
        return "The feature points the way onward.";
    if (a == TA_SUGGESTS)
        return "The feature suggests a quieter path "
               "below.";
    if (a == TA_INTELLIGENT)
        return "The feature weighs you with quiet, "
               "unblinking intelligence.";
    if (a == TA_TALKS_SMART)
        return "The feature speaks learnedly of the "
               "dungeon's history.";
    if (a == TA_TALKS_NONSENSE)
        return "The feature babbles nonsense and "
               "giggles.";
    if (a == TA_TALKS_POETRY)
        return "The feature recites an ode to fallen "
               "heroes.";
    if (a == TA_TALKS_SINGING)
        return "The feature sings a low, wordless "
               "melody.";
    if (a == TA_TALKS_SPELLS)
        return "The feature mutters syllables of "
               "spellcraft.";
    if (a == TA_TALKS_YELLS)
        return "The feature bellows a warning at the "
               "ceiling.";
    return "";
}

inline bool trickIsMechanical(int a) {
""",
      "appendixgh.h: trickIsTalky + trickTalkLine",
      marker="trickIsTalky(int a)")

patch("game/state_dungeon.cpp",
"""        if (!dm::appendixh::trickIsMechanical(
                room.trickAttribute)) {
            log.add("The feature only mutters - it "
                    "ignores the company.");
            return;
        }
""",
"""        // R138: the talk-flavor parley - a talking
        // feature answers the X key with its line
        // (repeatable; talk never spends the trick).
        if (dm::appendixh::trickIsTalky(
                room.trickAttribute)) {
            log.add(dm::appendixh::trickTalkLine(
                room.trickAttribute));
            return;
        }
        if (!dm::appendixh::trickIsMechanical(
                room.trickAttribute)) {
            log.add("The feature only mutters - it "
                    "ignores the company.");
            return;
        }
""",
      "state_dungeon.cpp: engageTrick talky branch",
      marker="dm::appendixh::trickTalkLine(")

patch("game/state_town.cpp",
"""            if (dm::appendixh::trickIsMechanical(
                    room.trickAttribute) && !room.trickDone) {
                log.add(dm::appendixh::trickEngagePrompt());
            }
""",
"""            // R138: a talky feature also answers the X
            // key - the first sight prompts as well.
            if ((dm::appendixh::trickIsMechanical(
                    room.trickAttribute) && !room.trickDone)
                || dm::appendixh::trickIsTalky(
                    room.trickAttribute)) {
                log.add(dm::appendixh::trickEngagePrompt());
            }
""",
      "state_town.cpp: describeRoom prompts talky too",
      marker="dm::appendixh::trickIsTalky(")

r138_lines = [
"    // ---- R138: talk-flavor parley audit ----",
"    // The talks-class attributes stay non-mechanical -",
"    // they answer the X key instead: the engage hook",
"    // logs each one's flavor line (repeatable; talk",
"    // never spends the trick).",
"    {",
"        int bad = 0;",
"        {",
"            int talky = 0;",
"            for (int a = 0;",
"                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)",
"                if (dm::appendixh::trickIsTalky(a)) ++talky;",
"            if (talky != 11) ++bad;",
"        }",
"        // every talky line: nonempty, ASCII, distinct,",
"        // and never mechanical",
"        for (int a = 0;",
"             a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a) {",
"            if (!dm::appendixh::trickIsTalky(a)) continue;",
"            const char* la =",
"                dm::appendixh::trickTalkLine(a);",
"            if (!la || !*la) ++bad;",
"            for (const char* q = la; q && *q; ++q)",
"                if ((unsigned char)*q > 127) ++bad;",
"            if (dm::appendixh::trickIsMechanical(a)) ++bad;",
"            for (int b = a + 1;",
"                 b < dm::appendixh::TRICK_ATTRIBUTE_COUNT;",
"                 ++b) {",
"                if (!dm::appendixh::trickIsTalky(b)) continue;",
"                if (std::string(la) ==",
"                        std::string(",
"                            dm::appendixh::trickTalkLine(b)))",
"                    ++bad;",
"            }",
"        }",
"        // the smart line pinned exact",
"        if (std::string(dm::appendixh::trickTalkLine(",
"                dm::appendixh::TA_TALKS_SMART)) !=",
"            " + chr(34) + "The feature speaks learnedly of the dungeon's history." + chr(34) + ")",
"            ++bad;",
"        printf(" + chr(34) + "R138 talk-flavor parley audit: bad %d"
        + BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
""]
r138_audit = NL.join(r138_lines)
old_r137_head = "    // ---- R137: deliberate-engage hook audit ----"
patch("regtest.cpp", old_r137_head + NL,
      r138_audit + NL + old_r137_head + NL,
      "regtest.cpp: R138 audit",
      marker="R138 talk-flavor parley audit")

patch("tools/dmg_gap_report.md",
"""      battery pins it exact. Pinned by the R137 hook
      audit; census 55.

## Out of scope by design
""",
"""      battery pins it exact. Pinned by the R137 hook
      audit; census 55.
- [x] **Talk-flavor parley hook (the standing debt)** -
      CLOSED R138: the talks-class Appendix H
      attributes (asks, directs, points, suggests,
      intelligent, and the six talks variants) stay
      non-mechanical by design - they answer the
      deliberate-engage hook instead. The X key in a
      talky trick room logs the attribute's flavor
      line (trickTalkLine, dm/appendixgh.h;
      repeatable - talk never spends the trick), and
      first sight shows the engage prompt. The battery
      pins the eleven-line set: count, non-mechanical,
      ASCII, pairwise distinct, and the smart line
      exact. Pinned by the R138 parley audit; census 56.

## Out of scope by design
""",
      "gap report: R138 box",
      marker="CLOSED R138:")

# ---- R138 fails/tail ----
if fails:
    print("R138 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R138 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R138 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
