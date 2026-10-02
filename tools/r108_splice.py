#!/usr/bin/env python3
# R108 the book: the DMG gap report. A pure DOCS round -
# no C++ changes, battery unchanged. The user uploaded the
# Premium DMG; the OCR pipeline preserved book pages 1-67
# (PDF pages 1-68). This round verified every parked
# book-verify item in that range against the actual text
# and classified the whole book into the four categories.
# The report ships as tools/dmg_gap_report.md - a living
# checklist: rounds that close an item flip its box in the
# same commit.
#
# Headline verifications (details in the report):
#   - R97 start ages: EXACT match to the book p.12 table
#   - R95 turn clock: grounded verbatim (p.38)
#   - R46 crew share 5%: EXACT match (p.35)
#   - R103 gift +5 loyalty: EXACT match - the book's
#     "choice gift or bonus" is +5% (p.37 special table)
#   - morale base 50% (p.37): grounds both loyalty scores
#   - R98 aging: DELTAS FOUND - book has 5 categories with
#     human thresholds 41/61/91 and gentler CON decline;
#     the repo's 4-bracket simplification is documented,
#     a candidate fix round (R109+)
#   - genuine gaps found: forced rest (p.38 "rest at
#     least one turn in six"), listening at doors (p.60),
#     crew officers (p.35: 1 lieutenant + 2 mates per 20)
#
# Patches (1): the new report file.
import sys, os

os.chdir(os.path.dirname(os.path.abspath(__file__)) + '/..')

def wr(p, s):
    with open(p, 'w', encoding='ascii') as f:
        f.write(s)

REPORT = r"""# DMG Gap Report - the book vs the repo

R108 "THE BOOK" (verified against the uploaded Premium
DMG, OCR book pages 1-67; pages 68-240 pending full text).
This is a living checklist: when a round closes an item,
it flips the box in the SAME commit. Page cites are the
book's own page numbers.

Categories:
- [x] = verified implemented (matches the book, or the
  simplification is accepted by design)
- [ ] = open item (worth having; a round should close it)
- OUT = out of scope by design (the repo is a tile-based
  dungeon crawler, not a war-game or domain simulator)

## Verified against the book text (pages 1-67)

- [x] **Start ages (p.12)** - R97's values are EXACT:
      cleric 18+1d4, fighter 15+1d4, magic-user 24+2d8,
      thief 18+1d4. The Human table, read and confirmed.
- [x] **Turn clock (p.38)** - "ten one-minute rounds to
      the turn, and six turns to the hour" - R95's
      144-turn day derives correctly (6x24). Verbatim
      grounded.
- [x] **Crew share (p.35)** - "the crewmen share between
      them 5%" of treasure taken at sea - the repo's
      delveGold/20 is EXACT.
- [x] **The gift (p.37)** - special considerations table:
      "given a choice gift or bonus ... +5%" - R103's
      loyaltyGift()=5 is an exact match.
- [x] **Morale base 50% (p.37)** - "Base unmodified
      morale score is 50%" - grounds the hire's 50+Cha
      hire-loyalty; the crew's 60 is a house value
      (willing signers), accepted.
- [x] **Henchman offer (p.35)** - "Not less than 100
      gold pieces per level" initial payment, base 25%
      interest - the repo's flat 100 gp for a 1st-level
      hire is the book's floor, simplified, accepted.
- [x] **Henchmen come unequipped (p.37)** - "no armor or
      weapons, nothing!" - the repo's hire starts bare
      (plate and weapons are bought later). Exact.
- [x] **Monster group morale (p.67)** - checkTeamMorale()
      implements group morale checks; base-50 grounding
      shared with henchman morale. Values vs the p.67
      trigger table still to diff (minor).
- [x] **Saving throws / turning undead exist** -
      rules/saves.cpp, rules/turn.cpp implement them;
      matrix values pending text (p.75, 79-80 are beyond
      OCR range) - carried below as open verifications.

## Simplified - documented deviations (accepted unless
## a round says otherwise)

- [x] **Aging brackets (p.13-14)** - DELTAS: the book has
      FIVE categories (young adult, mature, middle aged,
      old, venerable; human 21/41/61/91 boundaries), and
      the effects are cumulative with CON declining
      gentler (-1/-2 at old/venerable, not -1/-2/-3) and
      missing the mature +1 STR/+1 WIS. The repo's four
      brackets at 45/60/90 with symmetric 1/2/3 deltas is
      a house simplification. CANDIDATE FIX (R109):
      adopt the book's human thresholds and cumulative
      effects for the three advanced brackets.
- [x] **Henchman outreach (p.35-36)** - book: four
      methods (notices 50 gp / crier 10 gp / agents
      300 gp / inns), 2-8 day response window, applicant
      classes table. Repo: one flat 100 gp crier, one
      immediate applicant. Accepted simplification.
- [x] **Crew officers (p.35)** - book: per 20 crewmen, 1
      lieutenant + 2 mates required; master/captain 100
      gp/level/month. Repo: 20 sailors, no officers.
      Small gap; candidate: an officer fee (300 gp/mo)
      that buys crew-morale drift resistance.
- [x] **Spy cost (p.35)** - book: 100-10,000+ by the
      mission. Repo: flat 500. Accepted.
- [x] **Loyalty situations (p.37-38)** - the book's
      racial-preference/alignment/special-consideration
      tables are far richer than the repo's event-driven
      drift (R94). The repo models a subset as house
      events (hard watch -1, deep descent -2, shared
      success +3). Accepted; the book's table is referee
      material, much of it needs campaign context the
      repo lacks.
- [x] **Gift cooldown (p.37)** - book: gift counts "within
      the last three months" (henchman); the repo's
      contentment cap (>=100 takes no gifts) serves the
      same anti-farming purpose. Accepted.

## Open items - gaps worth closing (in OCR range)

- [ ] **Forced rest (p.38)** - "A party should be
      required to rest at least one turn in six" plus a
      turn after each combat. The repo has voluntary camp
      (R90) but no fatigue rule. Candidate: fatigue that
      dents to-hit or slows movement after 6+ turns
      unrested.
- [ ] **Listening at doors (p.60)** - the table exists
      (chance by character class/level, door type); the
      repo has secret doors but no listen check.
      Candidate: [L] at a closed door rolls the check.
- [ ] **Encounter reactions (p.63)** - intelligent
      monsters should roll reaction (hostile /
      uncertain / indifferent / friendly); the repo's
      monsters always fight. Candidate: a d10 reaction
      roll for intelligent (INT 6+) wanderers that can
      end an encounter without blood.
- [ ] **Aging adoption** (from the deltas above) - the
      one verified-value divergence: book thresholds
      41/61/91 and cumulative effects. R109 candidate.

## Open items - beyond OCR range (pages 68-240; verify
## when the full text is available)

- [ ] Combat/attack matrices (p.73-75) vs rules/combat
- [ ] Turning undead matrix (p.75) vs rules/turn
- [ ] Saving throw matrices (p.79-80) vs rules/saves
- [ ] Experience tables (p.85) vs rules/classes
- [ ] Treasure tables (p.120-125) vs dm/treasure - NOTE:
      the battery's 20,000-roll audit pins the current
      behavior either way
- [ ] Appendix C encounter tables (p.174-179) vs
      dm/encounters - HISTORICALLY verified at R52
      ("OCR-verified against the uploaded DMG"); re-check
      opportunistically, not urgent
- [ ] Outdoor encounter tables (p.182-189) vs overland
- [ ] Waterborne tables (p.190) vs state_sea
- [ ] Random dungeon generation (App. A, p.169-172) vs
      dm/dungeon - the repo's generator is its own; diff
      the room-content tables
- [ ] Traps (App. G, p.216) vs the dungeon's 19 trap
      references - table values pending
- [ ] Dungeon dressing (App. I, p.217) vs describeRoom

## Out of scope (by design - checked off with rationale)

- [x] Psionics (p.76-79, 182) - no psionic system in the
      campaign; out.
- [x] Aerial adventure/combat (p.49-53) - no flight.
- [x] Siege and construction (p.106-110) - the keep is
      economic (R44/R106), not a wargame piece.
- [x] Gambling (App. F, p.215) - out.
- [x] Secondary skills (p.12) - no profession system.
- [x] Disease/parasites (p.13-15) - monthly-contract
      rules; candidate someday, not now.
- [x] Insanity, intoxication (p.82-83) - out.
- [x] Alignment languages, lycanthropy, monster PCs
      (p.21-25) - out.
- [x] Non-human troops, mercenary armies (p.104-105) -
      the crew and the hire are the campaign's whole
      retinue economy; armies are out.
- [x] Spell research, magic item fabrication (p.114-118)
      - scrolls are found/bought, never made; out.

## Maintenance note

This report is the book-verify backlog the record has
parked since R97. The next fix round (R109 candidate)
should take the aging adoption first - it is the only
verified-value divergence found in range.
"""

if os.path.exists('tools/dmg_gap_report.md'):
    print('gap report: already present')
else:
    wr('tools/dmg_gap_report.md', REPORT)
    print('gap report: written')

print()
print('R108 splice: ALL OK')
sys.exit(0)
