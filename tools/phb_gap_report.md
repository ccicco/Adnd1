# PHB Gap Report - the book vs the repo

R177 CREATION. THE SECOND BOOK, WHOLE. The DMG gap
report (tools/dmg_gap_report.md) covers the Dungeon
Masters Guide; this sibling report inventories the
Players Handbook (the Premium 1e OCR upload)
against the same engine, end to end. Engine scope:
four classes (fighter, magic-user, cleric, thief),
the six ability tables, the weapon, armor and
encumbrance layers, and the 54-spell registry.
Everything else the book carries is out of engine
scope, noted at the foot.

Conventions as the DMG report: [x] verified
against the book text (with the round); [~]
verified DIVERGENT - fix-round candidates, ranked;
[ ] open item (worth having); a round closes an
item by flipping the box in the SAME commit. Page
cites are the book own page numbers where earlier
rounds set them; otherwise sections are cited by
their printed table names.

FOUNDING READ FINDING: the five ability tables
other than STR are transcribed from project notes
and DIVERGE from the print - the same finding
class as the R162 XP rows (repinned R176). Five
divergences are verified below, and the prime
requisite ladder is an open verify item. A report
round adds no audit; the battery census stays 94
until the first PHB fix round lands.

## Verified against the book

- [x] **STR Table II (p.9, ability adjustments)** -
      pinned R153: hit probability, damage, the
      weight allowance, open doors and bend bars or
      lift gates for the whole 3-18/00 run.
- [x] **Race Tables I-III (pp.15-18)** - pinned
      R154: class limitations, the footnoted level
      caps, ability minimums and maximums (male and
      female columns), infravision, the
      sleep-and-charm resistances, the CON
      magic-save bonus (the R147 shape).
- [x] **Racial preferences table (the CHARACTER
      RACES section)** - the acceptability matrix
      pinned R169.
- [x] **Class tables (pp.20-31)** - the level
      title ladders pinned R162 (the cleric level 5
      blank cell carries Curate down); the XP
      boundary columns pinned R176 (band lower
      bound - 1; the printed adders); hit dice and
      the HP_BEYOND_CAP convention print-verified in
      passing (R162).
- [x] **Followers by class (the class description
      sections)** - pinned R170.
- [x] **Weapon data (speed factors, the per-weapon
      charts)** - R158 (speed) and R144 (the to-hit
      adjustment rows, from the repo-trusted
      compilation); the book-verify pass is the
      open item below, now payable.
- [x] **Spells (the SPELL TABLES and the spell
      explanations, engine classes)** - the
      54-spell registry, the by-level slot tables
      and the L4-6 casting gates pinned
      R80/R130/R131; caster aging R129.
- [x] **Death and revival (the CON resurrection
      survival column in use)** - R82; the audit
      range check covers the printed 40-100 column,
      so the coming repin passes it unchanged.

## Verified DIVERGENT (fix-round candidates, ranked)

- [~] 1. **DEX Table I, reaction and attacking
      adjustment (the DEXTERITY TABLE I page)** -
      engine cells diverge at dex 3 (engine -2,
      print -3), dex 4 (engine -1, print -2) and
      dex 18 (engine +2, print +3); 5 through 17
      match. LIVE: the accessor feeds missile
      attacks (ai/actor) and the surprise roll
      (rules/turn). The defensive adjustment ladder
      matches the print (the items.cpp armor class
      wiring).
- [~] 2. **CON table, the system shock and
      resurrection survival columns (the
      CONSTITUTION TABLE page)** - the engine system
      shock reads 25 through 96 against the printed
      35 through 99; the resurrection survival reads
      30 through 98 against the printed 40 through
      100 - every score diverges in both columns.
      The resurrection column is LIVE (the
      raise-dead roll and the R82 audit). The
      character.cpp conHPAdj CON 6 cell reads 0
      against the printed -1 (classes.cpp
      conHPAdjustment already matches the print).
      The poison-save column the engine carries
      (conPoisonSaveAdj) is not in the 1e print at
      all - unsourced, and unused.
- [~] 3. **WIS Table I, magical attack adjustment
      (the WISDOM TABLE I page)** - the engine reads
      -2 through +2; the print reads 3 -3, 4 -2,
      5-7 -1, 8-14 none, 15 +1, 16 +2, 17 +3,
      18 +4. Currently unwired (the saves.h note
      points at it; the save rolls do not call it).
- [~] 4. **INT Table I, additional languages (the
      INTELLIGENCE TABLE I page)** - the engine
      ladder diverges at every score above 3; the
      print reads 3-7 none, 8-9 one, 10-11 two,
      12-13 three, 14-15 four, 16 five, 17 six,
      18 seven. Currently display-only.
- [~] 5. **CHA table (reaction adjustment, loyalty
      base, henchmen - the CHARISMA TABLE page)** -
      the engine reaction adjustment is a flat -4
      through +4 ladder against the printed percent
      ladder (-25 at 3 through +35 at 18); the
      loyalty base reads 1 through 15 against the
      printed -30 through +40 percent; the henchmen
      count diverges at cha 4 (engine 2, print 1)
      and cha 12 (engine 4, print 5). The reaction
      accessor is LIVE and feeds the d100 reaction
      bands (dm.cpp rollReaction) - the fix round
      must re-scale to the printed percents.

## Open items (worth having)

- [ ] **Prime requisite XP adjustment (the class
      sections)** - the engine ladder reads +10, +5,
      0, -10, -20 percent by prime requisite score;
      the print carries the +10 percent
      high-prime-requisite notes in the class
      sections. The remaining rungs are unsourced
      against the 1e print - verify, then repin or
      record as convention.
- [ ] **The PHB book-verify pass for the weapon
      tables** - R144/R158 pinned from the
      1eonline.info compilation; the PHB upload now
      supplies the print charts (WEIGHT AND DAMAGE
      BY WEAPON TYPE; WEAPON TYPES, GENERAL DATA AND
      TO HIT ADJUSTMENTS) - a verify round can close
      the standing compile-vs-print note.
- [ ] **Starting money by class (the EQUIPPING THE
      CHARACTER section)** - the print: cleric 3d6
      (30-180 gp), fighter 5d4 (50-200), magic-user
      2d4 (20-80), thief 2d6 (20-120). The engine
      party-creation convention is unverified
      against the print.
- [ ] **Armor Class table (the ARMOR section)** -
      the printed AC ratings (none 10 through plate
      and shield 2, magic pluses lowering AC)
      deserve a cell-by-cell verify against the
      items armor rows (R101 pinned the plate kit).
- [ ] **Fighter attacks per melee round (the class
      tables section)** - 1 per round at levels 1-6,
      3 per 2 rounds at 7-12, 2 per round at 13 and
      up (one per level against creatures under one
      hit die); the engine convention is unverified.
- [ ] **Wisdom Table II, cleric bonus spells and
      spell failure** - unwired; a wiring candidate
      if engine scope wants it.

## Out of engine scope (recorded, not defects)

- The subclasses (paladin, ranger, druid,
  illusionist, assassin, monk) and the multi-class
  and two-class rules - OPENED R178: the subclass
  arc (the scope decisions and round queue below).
- Alignment machinery (the ALIGNMENT section) -
  player-side.
- Language lists (the CHARACTER LANGUAGES section) -
  display only.
- The psionic sections.
- The druid and illusionist spell lists - OPENED
  R178: the subclass arc (they join the spell
  registry in the arc spell layers).
- Stronghold and tower construction economics (the
  class description sections) - the engine
  stronghold machinery is DMG-side (R106 and kin).

## The subclass arc (OPENED R178 - the scope round)

SCOPE DECISIONS (the user, 2026-10-05): the engine
grows full subclass support - all six subclasses
(paladin, ranger, druid, illusionist, assassin,
monk), multi-class and dual-class (two-class)
characters, and the full spell lists. The druid
and illusionist lists bring spells beyond the
current 54-spell registry; paladin and ranger
progress through the existing cleric and
magic-user lists.

The arc plan (each round flips its box HERE in the
same commit, and adds its battery audit - the
census grows with the arc):

- R179 the six subclass foundations - the class
      registry grows (new indices past the four
      base classes), per-class level caps, hit
      dice, the HP-beyond-cap convention, the XP
      rows and the title ladders from the printed
      subclass tables (PALADINS, RANGERS, DRUIDS,
      ILLUSIONISTS, ASSASSINS, MONKS tables).
- R180 qualification and race gates - the ability
      minimums and the alignment requirements;
      Race Table I class limitations and the Race
      Table II level caps for the new classes.
- R181 attacks per melee round - the
      fighter-group table (also closes the open
      item above); the monk unarmed ladder and the
      under-one-hit-die note.
- R182 the druid spell layer - the druid list
      joins the registry with its own
      spells-usable-by-level table.
- R183 the illusionist spell layer - the
      illusionist list likewise.
- R184 the paladin and ranger spell layers - the
      spell progressions and the shared-list
      wiring (lay on hands, curing, the ranger
      giant-kind bonuses follow here).
- R185 multi-class and dual-class - the split
      experience machinery, the hit-dice and
      hit-point conventions, and the two-class
      rules.
- R186+ the per-subclass specials that remain -
      the assassin fees and disguise layer, the
      monk special abilities, backstab for the
      assassin, thief-skill sharing.

Until a round lands, each subclass stays out of
engine scope; the boxes flip per round. The
ability-table divergences (the ranked list above)
stay queued BEFORE the arc rounds - the live DEX
and CON bugs first.
