#!/usr/bin/env python3
# R109b splice: the R109 FIX-UP. The R109 splice delivered the matrix,
# the API, and the regtest include, but its regtest-audit and gap-report
# anchors REFUSED (the delivered paste carried an escaped newline where
# regtest.cpp has the literal backslash-n text) and the round was
# committed with the audit and the box flip missing. This splice lands
# exactly those two things: the R109 turn audit in the battery, and
# the gap report's turning-undead box flipped CLOSED in the same commit.
# No C++ outside regtest.cpp is touched; the matrix from R109 stands.

import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii",
              newline="\n") as f:
        f.write(text)


def replace_exact(old_text, anchor, replacement, what):
    if replacement in old_text:
        print("already applied: " + what)
        return old_text, False
    if old_text.count(anchor) != 1:
        print("REFUSED " + what + ": anchor not unique or missing")
        sys.exit(1)
    print("patched: " + what)
    return old_text.replace(anchor, replacement), True


def main():
    changed = False

    # ---- 1. regtest.cpp: the R109 turn audit (R109's missing half) ----
    r = read("regtest.cpp")
    old_r = """    return 0;
            }
"""
    new_r = """
    // ---- R109: turning undead audit (DMG p.75-76 matrix III) ----
    {
        int bad = 0;
        // the printed table, spot-checked cell for cell
        {
            struct Cell { int lvl, kind, result, target, count; };
            const Cell cells[] = {
                { 1,  0, rules::TURN_CHANCE,  10, rules::TURN_COUNT_1_12 },
                { 1,  1, rules::TURN_CHANCE,  13, rules::TURN_COUNT_1_12 },
                { 1,  2, rules::TURN_CHANCE,  16, rules::TURN_COUNT_1_12 },
                { 1,  3, rules::TURN_CHANCE,  19, rules::TURN_COUNT_1_12 },
                { 1,  4, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 1,  5, rules::TURN_NONE,     0, rules::TURN_COUNT_1_12 },
                { 2,  5, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 3,  6, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 4,  7, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 5,  8, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 6,  9, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 7, 10, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 8, 11, rules::TURN_CHANCE,  19, rules::TURN_COUNT_1_12 },
                { 8, 12, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_2  },
                { 4,  0, rules::TURN_ALL,      0, rules::TURN_COUNT_1_12 },
                { 6,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_1_12 },
                { 8,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_7_12 },
                { 9, 11, rules::TURN_CHANCE,  16, rules::TURN_COUNT_1_12 },
                {14, 11, rules::TURN_CHANCE,  10, rules::TURN_COUNT_1_12 },
                {14, 12, rules::TURN_CHANCE,  13, rules::TURN_COUNT_1_2  },
                {20,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_7_12 },
                { 0,  0, rules::TURN_NONE,     0, rules::TURN_COUNT_1_12 },
            };
            for (const Cell& c : cells) {
                rules::TurnAttempt t = rules::turnUndead(c.lvl, c.kind);
                if (t.result != c.result || t.target != c.target ||
                    t.countKind != c.count) ++bad;
            }
        }
        // every cell of the table is a legal value
        for (int kind = 0; kind < 13; ++kind) {
            for (int lvl = 1; lvl <= 20; ++lvl) {
                rules::TurnAttempt t = rules::turnUndead(lvl, kind);
                if (t.result == rules::TURN_CHANCE &&
                    (t.target < 4 || t.target > 20)) ++bad;
                if (t.result == rules::TURN_NONE) {
                    // dashes only past skeleton and zombie
                    if (kind == 0 || kind == 1) ++bad;
                }
            }
        }
        // the roll and count mechanics stay in bounds
        {
            rules::Rng rng(109);
            rules::Dice dice(rng);
            int seen1to12 = 0, seen7to12 = 0, seen1to2 = 0;
            int success = 0;
            for (int i = 0; i < 20000; ++i) {
                rules::TurnAttempt t =
                    rules::turnUndead(1, 0);   // skeleton, target 10
                if (rules::rollTurnSuccess(dice, t)) {
                    ++success;
                    int n = rules::rollTurnCount(dice, t);
                    if (n < 1 || n > 12) ++bad;
                    if (n == 12) seen1to12 = 1;
                }
                rules::TurnAttempt s =
                    rules::turnUndead(14, 12); // special, 1-2
                int n = rules::rollTurnCount(dice, s);
                if (n < 1 || n > 2) ++bad;
                if (n == 2) seen1to2 = 1;
                rules::TurnAttempt d =
                    rules::turnUndead(8, 0);   // D* skeleton
                int m = rules::rollTurnCount(dice, d);
                if (m < 7 || m > 12) ++bad;
                if (m == 7) seen7to12 = 1;
            }
            if (seen1to12 == 0 || seen1to2 == 0 ||
                seen7to12 == 0) ++bad;
            if (success == 0 || success == 20000) ++bad;
        }
        printf("R109 turn audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }
"""
    r, did = replace_exact(r, old_r, new_r, "regtest R109 audit")
    if did:
        write("regtest.cpp", r)
    changed = changed or did

    # ---- 2. tools/dmg_gap_report.md: flip the box, same commit ----
    g = read("tools/dmg_gap_report.md")
    old_g = """R108b "THE BOOK, WHOLE" (the redo). The first
edition of this report was verified against OCR
book pages 1-67 only. The full Premium DMG OCR
has now been read: 242 pages, end to end. This
edition replaces the first wholesale. It is a
living checklist: when a round closes an item,
it flips the box in the SAME commit. Page cites
are the book's own page numbers.

Categories:"""
    new_g = """R108b "THE BOOK, WHOLE" (the redo). The first
edition of this report was verified against OCR
book pages 1-67 only. The full Premium DMG OCR
has now been read: 242 pages, end to end. This
edition replaces the first wholesale. It is a
living checklist: when a round closes an item,
it flips the box in the SAME commit. Page cites
are the book's own page numbers.

R109 CLOSED divergence 1 of 6 (turning undead);
the remaining five stay ranked below.

Categories:"""
    g, did = replace_exact(g, old_g, new_g, "gap report header note")
    if did:
        write("tools/dmg_gap_report.md", g)
    changed = changed or did

    g = read("tools/dmg_gap_report.md")
    old_g = """- [~] 1. **Turning undead (p.75-76, matrix III;
      procedure p.77)** - the repo's mechanic is
      not the book's. The book: roll d20, match
      or exceed the cell -> turn 1-12 undead
      (7-12 where starred, 1-2 for Special);
      T = automatic turn, D = automatic destroy,
      dash = no effect ever. The book's Skeleton
      row across cleric levels 1-14+ is
      10/7/4/T/T/D/D/D*/D*/D*; Zombie
      13/10/7/T/T/...; Ghoul 16/13/10/4/T/...;
      Shadow 19/16/13/7/4/...; Wight
      20/19/16/10/7/4/...; Lich row ends
      19/16/10; Special row 20/19/13. The repo
      instead stores a count digit and rolls 2d6
      with entirely different numbers (its
      level-1 row begins {1,-1,...}). Both
      mechanics AND values diverge. Also the
      book's row order includes GHAST at slot 6
      (the OCR reads "Ghost" there; slot 11 is
      the true Ghost - resolve the row names
      against a printed copy in the fix round).
      This is the largest single divergence and
      the first fix candidate."""
    new_g = """- [x] 1. **Turning undead (p.75-76, matrix III;
      procedure p.77)** - CLOSED R109 (the fix-up
      R109b landed the battery audit and this box
      flip in the same commit). The repo now
      carries the book's table cell for cell:
      13 undead rows in the book's own order (the
      OCR's row-6 "Ghost" was GHAST; slot 11 is
      the true Ghost), columns cleric level
      1-8 / 9-13 / 14+, d20 match-or-exceed,
      T / D / D* / dash, counts 1-12 (7-12
      starred, 1-2 Special), paladins two levels
      below. Pinned by the R109 battery audit."""
    g, did = replace_exact(g, old_g, new_g, "gap report turning box")
    if did:
        write("tools/dmg_gap_report.md", g)
    changed = changed or did

    print("R109b splice: " +
          ("ALL OK" if changed else "nothing to do (already applied)"))


main()
