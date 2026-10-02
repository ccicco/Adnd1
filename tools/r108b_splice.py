#!/usr/bin/env python3
# R108b splice: THE BOOK, WHOLE - replaces tools/dmg_gap_report.md
# with the full-book edition (OCR pages 1-242 read end to end).
# Pure docs round: no C++ changes, battery stays byte-identical.

import os

REPORT = r"""
# DMG Gap Report - the book vs the repo

R108b "THE BOOK, WHOLE" (the redo). The first
edition of this report was verified against OCR
book pages 1-67 only. The full Premium DMG OCR
has now been read: 242 pages, end to end. This
edition replaces the first wholesale. It is a
living checklist: when a round closes an item,
it flips the box in the SAME commit. Page cites
are the book's own page numbers.

Categories:
- [x] = verified against the book text
- [~] = verified DIVERGENT: the repo's rule
       differs from the book, and a fix round
       is the candidate (ranked below)
- [ ] = open item (worth having; a round should
       close it)
- OUT = out of scope by design (the repo is a
       tile-based dungeon crawler, not a war
       game or domain simulator)

## Verified exact (the book receipts)

- [x] **Start ages (p.12)** - R97's values are
      EXACT: cleric 18+1d4, fighter 15+1d4,
      magic-user 24+2d8, thief 18+1d4.
- [x] **Turn clock (p.38)** - "ten one-minute
      rounds to the turn, and six turns to the
      hour" - R95's 144-turn day derives
      correctly (6x24).
- [x] **Crew share (p.35)** - "the crewmen
      share between them 5%" - the repo's
      delveGold/20 is EXACT.
- [x] **The gift (p.37)** - "given a choice
      gift or bonus ... +5%" - R103's
      loyaltyGift()=5 is an exact match.
- [x] **Morale base 50% (p.37)** - "Base
      unmodified morale score is 50%".
- [x] **Henchmen come unequipped (p.37)** -
      "no armor or weapons, nothing!".
- [x] **Appendix C, Monster Level I (p.175)** -
      re-verified line for line against
      dm/encounters.cpp kLevel1, including both
      footnoted substitutions (Badger becomes
      Hobgoblin at 29-33; Halfling becomes Giant
      Rat at 27-28 and 71-83). EXACT.
- [x] **XP table (p.85)** - monsters/
      MonsterXp.cpp matches the printed tier
      lists (the repo's array index starts one
      tier below the book's first bracket,
      consistently), and the additive formula
      reproduces the book's owlbear worked
      example (405). R59's alignment holds.
- [x] **Monster saves use character matrices
      (p.79-80, matrix II)** - the book's rule
      that all monsters save as characters, HD
      equating to level with +hp stepping, is
      the repo's approach; the per-class value
      divergence is logged below under saves.

## Verified DIVERGENT (fix-round candidates, ranked)

- [~] 1. **Turning undead (p.75-76, matrix III;
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
      the first fix candidate.
- [~] 2. **Saving throws (p.79-80, matrix I)** -
      the book bands levels per class; the repo
      uses per-level linear rows. Book fighter
      1-2: PPDM 14, Petrify 15, Rod/Wand 16,
      Breath 17, Spell 17 - the repo's level-1
      fighter row is off by one in three
      categories. Book cleric 1-3 PPDM is 10;
      the repo's level-1 cleric death save is
      14, four points harsher - the biggest
      single-value miss. Book MU 1-5 PPDM 14,
      Petrify 13, Rod/Wand 11; thief 1-4
      13/12/14/16/15 - the thief happens to be
      exact, the MU is wrong in two of five.
      Divergence grows with level (book bands
      improve in steps; the repo subtracts one
      per level). Also: book rule "a roll of 1
      is ALWAYS failure". Second fix candidate.
- [~] 3. **Fighter attack matrix (p.75 I.B)** -
      the book is level-BANDED: 0, 1-2, 3-4,
      5-6, 7-8, 9-10, 11-12, 13-14, 15-16,
      17+; the AC-10 row reads 10/8/6/4/2/0/
      -2/-4/-6 continuing to AC -10. The repo
      matches at levels 1-3 but diverges from
      level 4 up (its per-level rows shift one
      column per level; the book shifts per
      two-level band), and the repo clamps at
      20 / floor 2 where the book has genuine
      negative targets down to -6 at AC 10.
- [~] 4. **Class attack matrices (p.75 I.A,
      I.C, I.D)** - the book gives clerics,
      magic-users, and thieves their own
      matrices with their own bands (cleric
      1-3/4-6/7-9/...; MU 1-5/6-10/...; thief
      per I.D). The repo approximates all
      classes with effectiveAttackLevel shifts
      on the fighter matrix (MU -3, cleric -2,
      thief -4), which lands wrong on both
      ends: a book MU level 1 needs 11 to hit
      AC 10, the repo asks 10. The book's
      missile note is on the same page: -5 at
      long, -2 at medium range.
- [~] 5. **Monster attack matrix (p.75-76
      II)** - the book gives monsters their own
      HD-banded matrix (AC-10 row 11/10/9/8/6/
      5/3/2/0/-1/-2/-3 for bands 1/1+1-2/.../
      16+). The repo derives monster attacks by
      mapping HD onto the fighter matrix - a
      close approximation, not the book's
      table.
- [~] 6. **Aging (p.13-14)** - the book has
      FIVE brackets with human thresholds at
      41/61/91, cumulative effects, and a
      gentler CON decline than the repo
      implements. R98's simplification is
      documented but not the book. Accepted
      until a round chooses otherwise.

## Simplified or accepted by design

- [x] **Henchman offer (p.35)** - the repo's
      flat 100 gp hire fee is the book's floor
      for a 1st-level hire; accepted.
- [x] **Crew hired at morale 60** - a house
      value (willing signers) above the book's
      base 50; accepted.
- [x] **Spy cost, loyalty situation tables,
      gift cooldown** - condensed forms of the
      book's material; accepted.
- [x] **Treasure determination (pp.120-125)** -
      dm/treasure.cpp implements the map/
      monetary/magic structure, and the battery
      pins 20k-roll behavior, but a full
      line-by-line table diff against pp.120-125
      has NOT been done. Kept open as an item
      below until diffed.

## Open gaps (worth a round)

- [ ] **Magic-weapon-to-hit gate (p.76)** - the
      book's table: creatures struck only by
      magic weapons need +1 at HD 4+1, +2 at
      6+2, +3 at 8+3, +4 at 10+4 or better. No
      such gate found in the repo.
- [ ] **Encounter reactions (p.63-64)** - the
      two-die reaction table and its
      attitude-by-roll results.
- [ ] **Listening at doors (p.60)** - the
      chance and the elves' bonus.
- [ ] **Forced rest (p.38)** - characters
      forced to rest after extended strain.
- [ ] **Crew officers (p.35)** - officers and
      their shares beyond the crew's 5%.
- [ ] **Missile range modifiers (p.75)** - -5
      long / -2 medium; verify or implement in
      the combat round.
- [ ] **Treasure line-diff (pp.120-125)** - see
      above; diff each table against the book.
- [ ] **Outdoor movement (p.58-59)** - daily
      movement rates by terrain.
- [ ] **Appendix A dungeon dressing details
      (pp.169-172)** - beyond what the generator
      already pins.
- [ ] **Traps and dressing lists (pp.216-217)**
      - full tables vs the repo's trap set.
- [ ] **Wilderness encounter tables
      (pp.182-189)** - the appendix C-style
      tables for outdoor play.
- [ ] **Waterborne/aerial encounter tables
      (p.190)** - alongside the crew economy.

## Out of scope by design

- OUT: Aerial and naval combat systems, siege
  and war-machine rules, stronghold domain
  income beyond the keep's ledger, disease and
  heal-craft subgames, psionic combat (p.77
  IV.A and following), planar travel tables,
  and the full non-standard-procedure magic
  items list beyond what the battery pins.

## How this doc lives

Each fix round flips its box HERE, in the same
commit, and names its book page in the round
message. The ranked divergences above are the
natural next rounds: turning first, saves
second, then the attack matrices.
"""
REPORT = REPORT.lstrip("\n")

def main():
    path = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                        "dmg_gap_report.md")
    if os.path.exists(path):
        with open(path, "r", encoding="ascii") as f:
            old = f.read()
        if old == REPORT:
            print("gap report (whole book): already present")
            print("R108b splice: ALL OK")
            return
    with open(path, "w", encoding="ascii", newline="\n") as f:
        f.write(REPORT)
    print("gap report (whole book): written")
    print("R108b splice: ALL OK")

main()
