# DMG Gap Report - the book vs the repo

R108b "THE BOOK, WHOLE" (the redo). The first
edition of this report was verified against OCR
book pages 1-67 only. The full Premium DMG OCR
has now been read: 242 pages, end to end. This
edition replaces the first wholesale. It is a
living checklist: when a round closes an item,
it flips the box in the SAME commit. Page cites
are the book's own page numbers.

R109 CLOSED divergence 1 of 6 (turning undead).
R110 CLOSED divergence 2 of 6 (saving throws).
R111 CLOSED divergence 3 of 6 (fighter attack
matrix).
R112 CLOSED divergence 5 of 6 (monster attack
matrix).
R113 CLOSED divergence 4 of 6 (class attack
matrices).
R114 CLOSED divergence 6 of 6 (aging) - all
six of the original divergences are closed.
R115 verified the magic-weapon-to-hit gate
(p.76 - already the book's) and wired the
first magical aging cause (haste, p.14).
R116 CLOSED the missile range modifiers
(p.75) - -2 medium, -5 long, on the
engagement distance.
R117 CLOSED encounter reactions (p.64) -
the book's percentile seven-band table
replaces R8's 2d6 stand-in.
R118 CLOSED listening at doors (p.60) -
the book's racial d20 table replaces R11's
d6 bands; abilities.cpp joins the battery
build (it was compiled by nothing).
R119 CLOSED forced rest (p.38) - one turn
in six plus a turn after combat, gated.
R120 WIRED parley (R117's reaction roll
gates room and wandering encounters;
only the starred bands attack) and
listening at doors ([H], R118's table) -
first callers for both.
R121 CLOSED crew officers (p.35) - a
captain, a lieutenant and two mates
join the crew: wages 40 -> 300 gp, the
take's cut 5% -> 37% (PC keeps 63%).
R122 CLOSED the treasure line-diff
(pp.120-125) - every implemented table
diffed row-by-row against the book:
383 rows, dice bands, xp and gp values,
bundle quantities, no divergence. The
tables are now pinned, not just rolled.

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
      that all monsters save as characters, with
      HD equating to level and +hp stepping by
      4, is the repo's approach; R110 aligned
      the character matrices and added the
      book's own HD-to-level stepping
      (monsterSaveLevel).

## Verified DIVERGENT (fix-round candidates, ranked)

- [x] 1. **Turning undead (p.75-76, matrix III;
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
      below. Pinned by the R109 battery audit.
- [x] 2. **Saving throws (p.79-80, matrix I)** -
      CLOSED R110. The repo now carries the
      book's BANDED matrices per class
      (fighter 0/1-2/.../17+ incl. the 0-level
      row; cleric 1-3/.../19+; MU 1-5/.../21+;
      thief 1-4/.../21+), replacing the
      per-level linear rows. The headline fix:
      the cleric level-1 death save is now the
      book's 10 (was 14). Also landed: the
      book's rule that a natural 1 is ALWAYS
      failure, and the monster matrix II rule -
      HD equates to level with +hp stepping by
      4 (monsterSaveLevel). Pinned by the R110
      battery audit.
- [x] 3. **Fighter attack matrix (p.75 I.B)** -
      CLOSED R111. The repo now carries the
      book's own banded table: level bands
      0, 1-2, 3-4, 5-6, 7-8, 9-10, 11-12,
      13-14, 15-16, 17+ vs AC 10 down to
      AC -10, transcribed cell for cell with
      the book's negative targets intact (the
      17+ band hits AC 10 on any roll; the
      0-level human needs 11). The per-level
      approximation and its floor-2 clamp are
      gone. The book's optional 5%-per-level
      variant is not adopted. Pinned by the
      R111 battery audit.
- [x] 4. **Class attack matrices (p.75 I.A,
      I.C, I.D)** - CLOSED R113. The repo now
      carries the book's own tables for
      clerics (I.A, 7 level bands), magic-
      users (I.C, 5 bands) and thieves
      (I.D, 6 bands), each 21 AC rows
      transcribed cell for cell; fighters
      keep matrix I.B (R111). The
      effectiveAttackLevel row-shift
      approximation is gone: a book MU
      level 1 needs 11 to hit AC 10 (the
      shifts asked 10). The book's thief
      superscripts are backstab damage
      multipliers, not attack numbers.
      The book's missile note (-5 long,
      -2 medium) is still an open item.
      Pinned by the R113 battery audit.
- [x] 5. **Monster attack matrix (p.75-76
      II)** - CLOSED R112. The repo now carries
      the book's own HD-banded monster table:
      12 hit-dice bands (up to 1-1 through
      16+) vs AC 10 down to AC -10, transcribed
      cell for cell (monsters do NOT attack as
      fighters; a 16+ HD monster hits AC 10 on
      any roll, target -3). The repo's float HD
      cannot split the book's 1-1 vs 1 columns
      (both store 1.0; goblin, the battery's
      1.0 monster, is book 1-1 - documented
      interpretation). Monster saves also now
      step by monsterSaveLevel (matrix II.B,
      from R110). Pinned by the R112 battery
      audit.
- [x] 6. **Aging (p.13-14)** - CLOSED R114.
      The book's five human brackets (young
      adult 14-20, mature 21-40, middle aged
      41-60, old 61-90, venerable 91+) with
      its per-bracket cumulative adjustments
      (p.14) replace R98's symmetric bend.
      Humans only (no race field; documented),
      young adult is the as-rolled baseline,
      WIS clipped at 18 (documented). Magical
      aging causes are an open item below
      (haste wired R115).

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
      pins 20k-roll behavior; the line-by-line
      table diff was done R122 - no divergence
      (the item below is closed).

## Open gaps (worth a round)

- [x] **Magic-weapon-to-hit gate (p.76)** -
      VERIFIED R115: already implemented -
      monsters' requiredPlus comes from the
      Lua specials text (MonsterRegistry),
      and rules::weaponSufficient gates both
      the melee and missile paths
      (ai/actor.cpp; the quiver's ammo
      enchant counts toward it, R80).
      Attacking monsters are always
      sufficient: the book's attacker HD
      column (+1 at HD 4+1...) governs
      monsters hitting gated creatures,
      which this repo's encounters (monsters
      vs characters) never do - documented.
      Pinned by the R115 battery audit.
- [ ] **Magical aging causes, remainder
      (p.14)** - haste is wired (R115:
      spells::magicalAgingYears +
      applyMagicalAging, landed at the
      fight-end sync, persisted as
      "mageage"). The caster-aged causes -
      limited wish 1, restoration 2,
      resurrection 3, wish 3, alter reality
      3, gate 5 - await those spells
      entering the registry; the speed
      potion's 1 year awaits a potion
      identity surviving pickup (found
      potions collapse into the healing
      stack today). The hire's stolen years
      land nowhere (no hire brackets).
- [x] **Encounter reactions (p.64)** -
      CLOSED R117: the book's percentile
      table (seven bands, 01-05 violently
      hostile through 96-00
      enthusiastically friendly) replaces
      R8's 2d6 stand-in, which carried a
      verification-debt NOTE. d100 +
      chaReactionAdj (the hireling reaction
      adjustment - the book's "as if the
      creature were a henchman" charisma
      machinery); the loyalty adjustment
      applies only where a loyalty score
      exists, which an encountered
      creature has none (documented -
      a caller with a real score
      pre-adjusts). The starred bands read
      "or morale check if appropriate" -
      the caller's call, noted in the
      enum. Pinned by the R117 battery
      audit (all 13 band edges, both
      clamps, enum order, 200-roll smoke).
      No callers yet - the parley hook is
      a future round (dead code until
      then, but the book's own shape).
- [x] **Listening at doors (p.60)** -
      CLOSED R118: the book's table is
      racial d20 chances - dwarf 2, elf 3,
      gnome 4, half-elf 2, halfling 3,
      half-orc 3, human 2 in 20 (all seven
      pinned) - replacing R11's d6-band
      approximation. No race field, so
      callers use the human band
      (documented, R114 convention). The
      keen-eared bonus (1 or 2 in 20) is
      per-character state the repo does
      not track - the caller passes it
      (the DM notes it on the first
      listen, per the book). Thieves ride
      their hear-noise skill as pct/5
      in-20 bands (documented derivation;
      the PHB table's verification-debt
      NOTE rides). Silent creatures,
      sleeping/resting/alerted creatures:
      the caller's gate (the book's own
      rule). No callers yet - a door-
      listening hook is a future round.
      Pinned by the R118 battery audit;
      abilities.cpp now in the battery
      build (it was compiled by nothing
      on Termux before).
- [x] **Forced rest (p.38)** - CLOSED
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
      by the R119 battery audit.
- [x] **Crew officers (p.35)** - CLOSED R121:
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
      Pinned by the R121 battery audit.
- [x] **Missile range modifiers (p.75)** -
      CLOSED R116: rules::missileRangeMod (-5
      long, -2 medium, the book's own note)
      rides the engagement distance in
      resolveMissile - fired missile weapons
      only. Medium is 2x and long 3x the
      registry's short range (documented
      derivation - the M/L columns are not in
      the registry); hurled weapons are
      exempt (no thrown ranges in the
      registry - documented); the monsters'
      volley is the 50' short convention
      (R37, mod 0). Beyond long range no
      shot is possible (nothing spent).
      Under R43's 50' engagement geometry the
      long band is unreachable in play (it
      activates if the geometry ever opens);
      the sling's opening volley is medium,
      -2. Pinned by the R116 battery audit.
- [x] **Treasure line-diff (pp.120-125)** -
      VERIFIED R122: every implemented table
      diffed line-by-line against the book -
      383 rows across III.A/C-H plus the
      Special artifact table (35+24+30+33+30+
      33+36+35+29+26+26+36), dice bands, xp
      and gp values, bundle quantities: no
      divergence. The repo's name corrections
      are the treasure.h print-errata list.
      The III dispatch bands, the Map table
      and the scroll structure (16 spell
      bands, 8 protection scrolls, the 5x/3x
      sale rules) verified with it. The book's
      II.A/II.B/II.C hoard-construction
      tables are DM tools the repo replaces
      with MM Treasure Types (p.105, R71) -
      documented, not a divergence. Pinned by
      the R122 battery audit.
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
