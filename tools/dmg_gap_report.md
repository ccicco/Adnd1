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
R123 CLOSED outdoor movement (pp.58-59)
- the daily rates wired: afoot by
burden and terrain (the company at its
slowest walker's pace, true miles
tracked and logged), the coaster on
the book's sailed sea rate (50/day),
the mounted and afloat tables pinned
as data. Census 41.
R124 CLOSED Appendix A dressing
details (pp.169-172) - every table of
the random dungeon generation appendix
pinned row-by-row in the new
dm/appendixa.h: periodic check, doors,
side passages, widths, special passages
with their bridge/boat/jumping
chances, turns, chamber and room
shapes, unusual shape and size, exits,
contents and the stairway variant,
treasure by level, containers, guards,
hiding, stairs, tricks/traps, gas,
caves, pools, lakes and magic pools.
The walk's four helper rolls (width,
features, room size, contents) are
rewired to the exact tables - the
verification debt paid. Census 42.

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
- [x] **Magical aging causes, remainder
      (p.14)** - CLOSED R129: the six
      caster-aged causes enter the spell
      registry - Limited Wish (MU7, ages the
      caster 1), Alter Reality (MU7, 3),
      Wish (MU9, 3), Gate (MU9, 5),
      Restoration (CL7, 2), Resurrection
      (CL7, 3) - appended ids so saved
      knownSpells indices stay valid. Their
      rows are TARGET_SELF: the R115 aging
      rider ages the rider's target, which
      for these spells IS the caster (the
      book's semantics; the years land at
      the fight-end sync, persisted as
      "mageage"). The rows are "known, cast
      pending" (the R80 utility convention):
      the slot tables encode levels 1-6, so
      spellSlots yields 0 for 7-9 until the
      high-level (name level+) tables arrive
      in a future round - documented; the
      p.14 pins ride magicalAgingYears
      regardless. Two documented engine
      limits remain, named for the record:
      the speed potion's 1 year (found
      potions collapse into the healing
      stack - no identity survives pickup)
      and the hire's stolen years (no hire
      brackets exist). Pinned by the R129
      battery audit; census 47.
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
- [x] **Outdoor movement (p.58-59)** - CLOSED
      R123: the book's daily rates wired -
      the afoot table (light/average/heavy
      burden x normal/rugged/very-rugged
      terrain: 30/20/10, 20/10/5, 10/5/2
      miles/day) with the burden classes
      from the true loads (<=25 / 26-60 /
      61-90 lbs of gear; the strength/race
      adjustment lives in the dungeon bands,
      PHB p.76 - documented), the terrain
      classes mapped to the 8 routes
      (plains/scrub/desert normal,
      forest/rough/hills rugged,
      mountains/marsh very rugged), and the
      company pace = the slowest walker
      (hire included, the fallen skipped);
      each march day logs its true miles and
      tracks milesOut. The coaster sails
      the book's small-merchant sea rate
      (50 miles/day - the 50-60 band is
      the lake column; the roll stays
      generic lo..hi). The mounted
      table (60/25/5, 40/20/5, 30/15/5,
      draft 30/15/5, cart 25/15 and wagon
      25/10 road-only) and both afloat
      tables (oared and sailed, 8 vessels x
      5 waters) are pinned as data - no
      mounts or other vessels are in play
      yet. The d4 long-voyage reduction is
      a weeks-scale rule this day cadence
      does not model - documented. Pinned
      by the R123 battery audit.
- [x] **Appendix A dungeon dressing details
      (pp.169-172)** - CLOSED R124: all tables
      pinned row-by-row in the new
      dm/appendixa.h (Tables I-VIII.C:
      periodic check, doors, side passages,
      passage width, special passages with
      the stream/river/chasm bridge-boat-
      jumping chances, turns, chamber/room
      shape and size, unusual shape and
      size, exits count/location/direction,
      room contents + the stairway variant
      (the book's print skips band 6 - 1-5,
      7-8 - pinned as printed, documented),
      treasure by level, containers,
      guarded-by, hidden-by, stairs with
      their egress doors, trick/trap, gas,
      caves, pools, lakes, magic pools and
      their sub-tables). The walk's four
      helpers (passage width, passage
      features, room size, room contents)
      are rewired to the exact tables -
      R8's stand-in shapes and their
      verification-debt notes are gone
      (rooms use Table V's room column -
      the blank 18-20 rows re-roll; the
      chamber column and all unrendered
      tables are pinned data for the future
      layers). Pinned by the R124 battery
      audit; census 42.
- [x] **Traps and dressing lists (pp.216-217)**
      - CLOSED R125: Appendix G's trap list (the d% TRAP
      LIST, 46 kinds - band weights checked against a scan
      of the printed page) is pinned row-by-row in the new
      dm/appendixgh.h, and the R45 dart-trap set now rolls
      its NAME from the table at arming: spring/disarm/
      sprung-room lines quote the book name verbatim (the
      book lists names only, so the R45 save-or-2d6 set
      stays the effect). Appendix H's dressing lists (37
      features, 65 attributes) are pinned as data for the
      future special-rooms layer (trickSummary helper).
      Pinned by the R125 battery audit; census 43. NOTE:
      name spellings and the H lists are transcribed from
      the 1eonline.info compilation of the pages and ride
      the book-verify debt with the printed table as the
      winner.
- [x] **Wilderness encounter tables
      (pp.182-189)** - CLOSED R126: the R63 climate
      matrices (Arctic, Sub-Arctic, Temperate Wild,
      Temperate Inhabited, Faerie, Pleistocene, Age of
      Dinosaurs, Tropical) and the eleven terrain-column
      subtables (plus the tropical single-column Sphinx
      footnote) are line-diffed against the 1eonline.info
      Appendix C compilation: the five climates it carries
      match band-for-band modulo the documented OCR folds,
      and the two undocumented printed-gap resolutions
      (temperate wild scrub Humanoid 36-32 -> 26-32,
      tropical rough giant scorpion 84-84 -> 84-85) are now
      documented in-row. The compilation omits the Faerie,
      Pleistocene and Age of Dinosaurs tables - those three
      ride the book-verify debt with the printed table as
      the winner, as do the printing-variant readings
      (tropical mountains dervish 29-30; marsh Men
      nomad/tribesman). Pinned by the R126 battery audit;
      census 44.
- [x] **Waterborne/aerial encounter tables
      (p.190)** - CLOSED R127: the four p.190 waterborne
      tables (fresh water small/large body, salt water
      shallow/coastal and deep) are pinned row-by-row,
      line-diffed against the 1eonline.info Appendix C
      compilation, and wired into the sea travel loop
      (R70 had rolled the R60 underwater set; the coaster
      now rolls surface encounters - buccaneers,
      merchants, pirates, mermaids, whales - and the
      underwater set stays pinned data for the future
      diving layer). Dinosaur rows resolve on the shared
      p.190 Dinosaur Subtable; the fresh-water warm gate
      rides the parent row per the R60 convention.
      Aerial: the DMG prints no separate aerial table -
      airborne play resolves on the wilderness tables'
      airborne rows (the ^75^ markers, pinned R63/R126),
      documented. Substitutions pinned in-row (pirate ->
      buccaneer, tribesman small craft -> caveman,
      mermaid -> merman). Pinned by the R127 battery
      audit; census 45.
- [x] **Special rooms (Appendix H tricks,
      pp.216-217)** - CLOSED R128: the R125-pinned dressing
      lists are wired: an unoccupied, untrapped room has a
      20% chance (the design figure - the book's H lists
      are selection lists, not frequency tables, so no
      printed weights exist; the odds ride the design debt)
      to hold a curiosity - a uniform feature (of 37) +
      attribute (of 65) rolled at populate, announced on
      first entry via trickSummary ("Something odd commands
      the room: Fountain (Talks singing)."). A room is a
      snare OR a curiosity, never both (documented). The
      first-effects slice pays out once (trickDone):
      releases coins (2d6 x 10 x level, the delve take),
      releases gems (1d3 at the DMG gem appraisal),
      releases magic item (the R44 unidentified-pickup
      shape), and shoots / poison strike a random living
      member with the trap shape (save vs death/poison or
      2d6). R132's second-effects slice wires six more
      (the R132 box), R133's five more (the R133 box),
      R134's three deep (the R134 box), R135's five
      geometry (the R135 box), R136's five
      odds-and-ends (the R136 box). The other 36
      attributes stay dressing - documented; their
      effects ride future rounds.
      Transient like trapKind: rooms re-populate on load.
      Pinned by the R128 battery audit; census 46.
- [x] **High-level spell slot tables (PHB
      class tables)** - CLOSED R130: the slot tables
      themselves were the last print-omission in the
      spell pipeline - line-diffed against the
      1eonline.info PHB compilation (class Table I +
      the SPELLS USABLE appendix): 9 spell levels
      encoded, MU printed rows to L20, cleric to L29,
      final row holds beyond the print; the R80
      project-notes rows 7-12 corrected to print; the
      cleric 7th gate lands at 17 (the printed Wis-18
      footnote at 16 not modeled - engine limit); the
      INT gate extends 17 -> 7th, 18 -> 8th/9th (the
      "highest intelligence" note - a convention
      extension riding the standing verification
      debt). The tables and gates now encode levels
      7-9 (the R129 caster-aging spells resolve at
      name level); the per-day slotsByLevel plumbing
      still tracks 6 - named debt, rides future
      rounds. Pinned by the R130 battery audit;
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
- [x] **Appendix H second-effects slice (the R128
      dressing debt, first six)** - CLOSED R132: the
      mechanical set grows 5 -> 11. Ages: 10 years on
      a random living member (the print's altar
      example, via the R115 magical-aging shape).
      Flesh to stone: save vs petrification or turned
      to stone (the print's face example - save
      versus magic or be transformed). Electrical
      shock, metallic or magical: 5-50 hp on a
      random living member, no save (the print's
      pedestal example prints none). Releases
      counterfeit: a shower of coins that crumbles
      worthless - nothing gained. Takes/steals:
      10-60 gp from the purse (the print gives no
      figure - a rebuild convention, documented).
      The R133 slice wires five more (the R133 box),
      R134's three deep waters (the R134 box), R135's
      five geometry (the R135 box). The
      remaining 41 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
- [x] **Appendix H third-effects slice (the R128
      dressing debt, second five)** - CLOSED R133: the
      mechanical set grows 11 -> 16. Attacks:
      the animated feature strikes a random living
      member for 1d8, no save. Fruit: a random
      living member eats and heals 2d4+2 (the
      potion shape, capped at max hp). Greed: a
      scramble costs 10% of the purse. Teleports:
      the company blinks to a random room center
      on this level (the print's intra-level AREA
      example). Collapsing: the ceiling comes down
      - every living member saves vs death/poison
      or takes 2d6. All five are rebuild
      conventions (the print gives no figures);
      documented. The R134 slice wires the three deep
      waters (the R134 box), R135's five geometry
      (the R135 box), R136's five odds-and-ends
      (the R136 box). The remaining 36
      attributes stay dressing; their effects ride
      future rounds.
      Pinned by the R133 battery audit; census 51.
- [x] **Appendix H deep-effects slice (the deep
      waters)** - CLOSED R134: the mechanical set
      grows 16 -> 19. Wish: a boon table roll - the
      whole company healed, or a random living member
      restored, or a gold shower (1d6 x 100 gp).
      Gravity greater: the pull doubles - every living
      member takes 1d6 crushing, no save. Polymorph:
      a random living member saves vs
      petrification/polymorph or takes 3d4 reshaping
      damage. All three are rebuild conventions (the
      print gives no figures); documented. The
      remaining 46 attributes stay dressing; their
      effects ride future rounds. Pinned by the R134
      battery audit; census 52.
- [x] **Appendix H room-geometry slice (the
      positional five)** - CLOSED R135: the mechanical
      set grows 19 -> 24. One-way: the way back seals
      - the company is committed to the room's center.
      Pivots: the room turns a quarter - the company's
      position rotates 90 degrees about the room
      center, clamped inside. Spinning: a full
      half-turn - the position rotates 180 degrees.
      Shifting: the walls flex - the position mirrors
      across the room's center line. Sliding: the floor
      tilts - the company is shoved to a random room
      edge. All five are positional conventions (the
      print gives no mechanics); documented. The
      remaining 41 attributes stay dressing; their
      effects ride future rounds. Pinned by the R135
      battery audit; census 53.
- [x] **Appendix H odds-and-ends slice (the
      stragglers)** - CLOSED R136: the mechanical set
      grows 24 -> 29. Rising: water floods the room -
      every living member saves vs death/poison or
      takes 1d6. Suspends: gravity nil - the company
      floats and drifts to a random interior tile.
      Appearing: the feature manifests, startles, and
      melts away - the room's trick is spent.
      Invisible: an unseen strike - 1d6 on a random
      living member, no save. Gaseous: a poison cloud -
      every living member saves vs death/poison or
      takes 1d6. Anti-magic STAYS dressing (an honest
      suppression zone needs a magic-use hook the
      engine does not expose yet); documented. All five
      wired effects are rebuild conventions (the
      print gives no figures). The remaining 36
      attributes stay dressing; their effects ride
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
- [x] **Engine-deep change-family slice (the hardest
      mapping left)** - CLOSED R139: eleven Appendix H
      attributes wired, mechanical set 29 -> 40, all
      conventions (the print gives names only). Change
      align (save or WIS and CHA drop), change
      attribute (save or two abilities swap), change
      class (save or training unravels - xp resets),
      change minds (save or INT drops), change sex
      (save or CHA drops), distorted WL (the bent
      weapon, 1d6), distorted HD (save or max hp
      drops), resisting general (the company is
      repelled), resisting specific (repelled, and the
      trick is not spent), geases (save or WIS drops),
      disintegrates (save or gone). The battery pins
      the set at forty, the eleven mechanical, the
      honest deeps (anti-magic, enrages) dressing, and
      the eleven never talky. Pinned by the R139
      change-family audit; census 57.
- [x] **The final Appendix H sweep (closing the
      list)** - CLOSED R140: twelve odds-ends wired -
      animated (the company is buffeted, 1d4 each),
      combination (a 1d6 strike and a repulse),
      enlarges (save or STR rises, DEX thins), false
      (only light and shadow - the trick is spent),
      gravity lesser (a bob and drop), gravity nil
      (the company floats to the room's center),
      gravity varying (save or 1d6, everyone), moves
      (carried to a random tile), randomly-acts (a
      d3: strike, gift, or still), sloping (the low
      edge takes the company), symbiotic (save or a
      passenger settles - CON drops), wish reversal
      (the inverted boon table: harm, aging, or the
      purse bleeds). THE 65-ATTRIBUTE LIST IS CLOSED:
      52 mechanical, 11 talky, and 2 dressing by
      design (anti-magic needs a magic-use hook,
      enrages needs a berserk hook - neither engine
      exists; documented and pinned). Pinned by the
      R140 final sweep audit; census 58.
- [x] **Engagement geometry (the R43 50' standing
      debt)** - CLOSED R141: a room fight now OPENS at
      the chamber's own geometry - the longest interior
      dimension in 10' bands (rules::engagementBands,
      floored at the 50' corridor convention, capped at
      120') - and the range closes one band per round as
      before. A wide chamber therefore opens wide, and
      the R116 long-range band (-5, DMG p.75) is finally
      reachable in play: a 12-tile chamber opens at
      120', where a sling's long shot (40' short range)
      is exactly possible at -5. Wandering and overland
      engagements keep the 50' convention (no room to
      measure). The battery pins the helper's floor,
      cap, and longest-dimension rule, and the
      long-band-in-play scenario. Pinned by the R141
      engagement geometry audit; census 59.
- [x] **The sample dungeon (DMG pp.94-96)** - CLOSED R142:
      the MONASTERY CELLARS & SECRET CRYPTS, the book's own
      teaching delve, walk as pure data
      (dm/sampledungeon.h): the three keyed rooms - the 30
      foot square entry chamber (exactly 3x3 tiles at 10
      feet; the large spider lairs per the text, and the
      goblin skull holds 19 sp and a 50 gp garnet, with
      the book's 25 percent yellow-mold sack: save vs
      poison or die), the water room (the stream, the
      ivory tube with its water-ruined vellum map, the
      abbot's curious key), and the ceremonial dome (the 9
      foot platform, the seven stone knobs over empty
      socket holes) - plus the book's two d4 wandering
      tables (the halls column wired to the wander roll;
      the crypt column is data for the future crypts, as
      are the crypt-cleric row and the crypts behind the
      seventh knob). The M key in the delve summons the
      keyed map at kSampleSeed; every other seed walks the
      generated dungeon exactly as before. Pinned by the
      R142 sample dungeon audit; census 60.
- [x] **The sample dungeon's crypts (the future-crypts
      debt)** - CLOSED R143: the SECRET CRYPTS are delved.
      Three crypt chambers (the book's own crypt wandering
      column names their lairs - area 24 ghouls, area 27
      skeletons, areas 35-37 the cleric's hobgoblins; the
      book itself keys no crypt rooms, so the chambers and
      lair counts are conventions) hang off a spine south
      of the ceremonial dome, SEALED behind the seventh
      knob's door - rock until the X key turns the knob in
      the dome. South of that door the wander roll switches
      to the book's crypt column, and its second row walks
      at last: the evil 3rd-level cleric, built as a
      Character foe beside his 2 hobgoblins (the book
      gives the crypt column as straight encounters - no
      reaction gate on that row, documented). The crypt
      texts speak on first sight; the abbot's key is
      flavor (the book's secret door 28-29 is a crypt
      lock here by convention). Pinned by the R143 crypt
      wing audit; census 61.
- [x] **The p.71 Example of Melee golden test (the old
      rules-core debt, never scheduled)** - CLOSED R144:
      the book's own worked fight (Aggro the Axe's party
      vs. Gutboy Barrelhouse's, transcribed from the
      1eonline.info compilation - the DMG re-upload's OCR
      died in the preface) is pinned against the engine's
      combat core. The engine matches every printed
      number it models: the seven matrix cells (F4/AC 10
      = 8, T2/AC 10 = 11, F6/AC 5 = 11, F4/AC 5 = 13,
      C4/AC 1 = 17, and the monk Balto's base 18 - via the
      fighter approximation, the engine having no monk
      class), STR 17 = +1 to hit/+1 damage, the 6th-level
      fighter spell save of 14, and the mace-vs-plate +1
      (17 - 1 = 16). The example's other numbers are the
      book's OWN errors (Gygax: the example 'was added by
      the editors, thus slipped past and never got
      corrected' - Balto's staff '-7', the magic missile
      '4-10') or per-weapon rows beyond the engine's
      3-class p.38 approximation (the sling's +3 vs. no
      armor, the axe's +1, the hammer's +1 vs. scale):
      the engine deliberately does not copy the errors,
      and the approximation rows are now STANDING
      APPROXIMATIONS (a per-weapon p.38 table is a future
      lane), as was the dwarf CON magic-save bonus until
      R147 closed it (PHB p.16 - rules::dwarfConSaveBonus;
      see the R147 boxes). Pinned by the
      R144 golden melee audit; census 62.
- [x] **The per-weapon p.38 'to hit' table (R144's standing
      approximation)** - CLOSED R145: every weapon now
      carries its own PHB p.38 armor-class adjustment row
      (15 weapons x 11 columns, AC 0-10), replacing the
      3-class bludgeon/pierce/slash approximation at the
      items::attackAdjustment choke point (the old class
      table stays as the rules-layer fallback, still pinned
      by the R144 audit). Rows transcribed from the
      1eonline.info compilation - the repo-trusted source -
      both p.38 charts (melee rows from the first, the
      short bow / long bow / light crossbow / sling rows
      from the hurled-and-missile chart; the sling is the
      bullet's row, the DMG p.71 example's own weapon);
      the PHB re-upload's book-verify debt stands (the bow
      rows' cell gaps are pinned as the source prints them -
      the composite bows show the same quirk). Standing
      approximations, named: (1) the column is the
      defender's full effective AC (magic, DEX, and shield
      all shift the column; the book keys apparent armor AC
      and says magic/DEX do not shift it); (2) the rows
      apply to every defender - monsters included - where
      the book limits them to humans, demihumans, and
      humanoids; (3) below AC 0 reads column 0 (the book's
      table stops at AC 0); (4) Gygax himself ignored the
      table (the 1eonline FAQ and Delta's D&D Hotspot both
      note it) - the engine pins it anyway, by design. The
      p.71 example's sling bullet +3 vs. no armor - R144's
      named approximation - is now the engine's own row; the
      example's axe '+1 vs. no armor' remains one of its
      acknowledged editorial errors (the p.38 battle axe row
      reads +2, and the engine follows p.38); the example's
      hammer has no engine weapon (the 15-weapon registry
      carries no war hammer - the R144 pin stands). Pinned by
      the R145
      weapon table audit; census 63.
- [x] **The city flavor subtables (R64's named omissions)**
      - CLOSED R146: the p.191 drunk identity table ("the
      character(s) found drunk should be diced for" - 20
      bands, assassin 01-02 through tradesman 98-00) and
      the famous p.192 harlot type table (12 bands, the
      slovenly trull 01-10 through the rich panderer
      99-00 - Gygax, on why the table exists: built from
      boredom with the genre's continual 'whores'
      references, included in a spirit of
      vocabulary-building, "no particular regrets") are
      pinned as fiction-only descriptors and wired into
      the city streets flavor strings (the book's MU /
      Merc print in full; the compilation's 'Haughy
      courtesan' is the printed 'haughty', corrected and
      documented). Cell-verified at the raw-HTML level of
      the 1eonline.info compilation - the repo-trusted
      source; the DMG re-upload's OCR debt stands. Still
      unmodeled fiction, named: noble gender (the book
      prints nobleman-with-retainers 70% / noblewoman 25%
      and no last 5%) and the ruffian 1-in-4
      half-orc/humanoid note. Pinned by the R146 city
      flavor audit; census 64.
- [x] **The dwarf CON magic-save bonus + matrix II
      footnote D (R144's named standing approximation
      + the p.80 footnote)** - CLOSED R147: dwarves add
      their constitution to saves vs. wands/staves/rods,
      spells, and poison "in the same manner" (PHB
      p.16) - pinned as rules::dwarfConSaveBonus (con*2/7
      clamped 0..5, matching every printed band 4-6 +1
      through 18 +5); NPC foes carry the rolled p.176
      race on the Actor (the half-elf and half-orc
      race-only bands now mark the race where they
      previously fell through), and asTarget / trySaveVs
      apply the bonus to wands, spells, and death-poison
      saves (the party is human - only NPC-foe dwarves
      benefit). Footnote D: non-intelligence saves at
      half hit dice rounded up except vs. death/poison -
      pinned as spelleffects::effectiveSaveLevel, consumed
      by both trySave and the ai trySaveVs; toActor maps
      MM intelligence "non" (containsCI, no dash -
      "non-" wordings excluded; exactly 90 of the 408,
      census-pinned; "animal" keeps the II.B step, a
      named judgment call). Matrix II.C (classed monsters
      saving on their most favorable matrix) stays a
      named gap - the per-monster class pass is a future
      lane. Pinned by the R147 dwarf CON + II.D audits;
      census 67.
- [x] **Appendix P: creating a party on the spur of the
      moment (DMG pp.225-226)** - CLOSED R147: pinned as
      the header-only dm/appendixp.h (the appendixa.h
      pattern - data + rollers, the caller decides when).
      The three level-band options per range (low 1-2 /
      1-3 / 2-4, medium 5-7 / 5-8 / 7-9, upper 8-10 /
      8-11 / 9-12), the 4d6-drop-lowest ability rolls,
      the protective and weapons per-level percentage
      tables (the four primary classes; the book's
      subclass and UA/OA rows are its own variants, out
      of scope), the potion rows (per-level chance, max
      carried, the 10 printed types - the book's "0."
      prints as type 10), the item/+2/+3 chance chain
      (item = level x pct; above-90 excess folds into the
      +2 chance; +3 is a straight 1% per level), and the
      rollMemberMagic kit builder (one armor sort
      chain/ring/chain/leather by class, one weapon sort
      sword/dagger/mace/sword, a shield try for the
      armored classes). Gonzo's worked example pinned:
      15%/level chain at 9th = 135%, +2 chance 9 + 45 =
      54 (rolled 51 - at least +2), +3 check 9 (rolled
      99 - just +2). No caller yet - data + rollers
      only (the p.176 convention-party generator is a
      future lane). Pinned by the R147 Appendix P audit;
      census 67.
- [ ] **The book-verify pass (the standing debt)** - the
      fresh DMG/PHB uploads (2026-10-04) make the whole
      verification debt payable. The riders name their
      winners: Appendix G/H spellings (R125), the Faerie
      / Pleistocene / Age of Dinosaurs wilderness tables
      and printing-variant readings (R126), the p.38
      weapon rows (R145), the city flavor cells (R146),
      and the p.71 example numbers (R144).
- [ ] **PC races layer (PHB pp.15-18, Race Tables I-III)**
      - the races half of the authored-but-unlanded R148
      combined splice: gnome and halfling CON magic-save
      and poison-save bonuses (con*2/7, the R147 dwarf
      shape), elven 90% / half-elven 30% sleep-and-charm
      resistance, infravision, the racial detection
      lists, ability adjustments with min/max, footnoted
      level caps, race to-hit adjustments vs. goblin-kind
      and giant-kind, and the creation-stage
      ROLL->RACE->CLASS->NAME flow. Must be re-authored
      against current main - the combined splice is
      stale (its 18 R147 patches already landed).
- [ ] **Matrix II.C (classed monsters, most favorable
      matrix)** - the R147 named gap: the per-monster
      class pass, so a classed foe saves on its own
      class matrix when that beats matrix II.
- [ ] **Appendix P caller (the convention-party
      generator)** - rollMemberMagic has no caller; wire
      it into the p.176 party rows or a dm/encounters
      generator.
- [ ] **Grenade-like missiles + holy/unholy water
      (pp.64-65)** - thrown flasks: the break and splash
      rules, the cone tables, vial costs and effects.
- [ ] **Weapon speed factors in initiative (p.66)** - the
      segment scheduler exists; the speed-factor table
      and its melee-initiative adjustments are unpinned
      (verify against rules/turn first).
- [ ] **Striking to subdue (p.67)** - the knockout
      procedure and subdual damage accounting.
- [ ] **Weaponless combat (pp.72-73)** - pummeling,
      wrestling, overbearing: the three procedures and
      their tables.
- [ ] **Attacks with two weapons (p.70)** - the R7
      double-attack named leader: the two-weapon
      conventions for attack and armor class.
- [ ] **Level title ladders (PHB class tables)** - the R4
      named leader: the printed per-level titles for the
      four engine classes.
- [ ] **The poison table (p.20)** - the printed types:
      ingest/injury, onset times, damage and effect
      classes. The monster venom layer rolls per-monster
      saves; the type table itself is unpinned.
- [ ] **The assassination table (p.75)** - the odds table
      proper; the p.19-20 spying rules are already wired
      (the spy).
- [ ] **Potion miscibility (p.119)** - the interactions
      table for drinking incompatible potions.
- [ ] **Intoxication and insanity (pp.82-83)** - the
      alcohol and drugs effects with recovery tables;
      the types of insanity.
- [ ] **PC disease + parasitic infestation (pp.13-14)**
      - contraction chance, occurrence and severity
      tables. The monster-borne disease layer exists
      (mummy rot); PC-side contraction does not.
- [ ] **Underwater spell use (p.57)** - the modifier
      table; the underwater encounter tables are pinned
      (R60/R127) but the spell columns are not.
- [ ] **Chances of becoming lost (p.49)** - the overland
      navigation check for the outdoor march.
- [ ] **Humanoid racial preferences (p.106)** - the
      association matrix for lair and population
      placement passes.
- [ ] **Appendices K + L + M (pp.221-224)** - describing
      magical substances; conjured animals; summoned
      monsters - support tables for the conjure and
      summon spell effects.
- [ ] **Appendix O, encumbrance of standard items
      (p.225)** - items::encumbrance exists; the printed
      weight table itself is unpinned.
- [ ] **Exceptional strength (PHB p.9)** - the fighter 18
      percentile roll (18/01 through 18/00) and the STR
      Table II bend-bars / open-doors columns; verify
      the abilities layer first.
- [ ] **Followers by class (pp.16-18)** - the name-level
      follower tables (cleric, fighter, ranger, thief,
      assassin) for stronghold recruitment.
- [ ] **Secondary skills (p.12)** - the table and the
      when-to-use guidance for PC backgrounds.
- [ ] **R146 fiction (the named omissions)** - noble
      gender (the book prints nobleman 70% / noblewoman
      25% and no last 5%) and the ruffian 1-in-4
      half-orc/humanoid note - city flavor follow-ups.

## Out of scope by design

- OUT: Aerial and naval combat systems, siege
  and war-machine rules, stronghold domain
  income beyond the keep's ledger, disease and
  heal-craft subgames, psionic combat (p.77
  IV.A and following), planar travel tables,
  and the full non-standard-procedure magic
  items list beyond what the battery pins, the Boot
  Hill / Gamma World / Metamorphosis Alpha
  conversion tables (pp.112-114), and Appendix J
  herbs, spices, and medicinal vegetation (p.220).

## How this doc lives

Each fix round flips its box HERE, in the same
commit, and names its book page in the round
message. The ranked divergences above are the
natural next rounds: turning first, saves
second, then the attack matrices.
