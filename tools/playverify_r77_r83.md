# Play-Verify Checklist: R77-R83 features (run on a PC build)
# Build first (MSVC or mingw): adnd1.exe. Then walk these in order.
# Every line has the keys to press and the exact text to look for.

## Setup
- [ ] New party ([N] at the title). Note one member's name.
- [ ] Delve ([B] leaves town when you want; return with stairs).

## R77-R78: gear and quiver basics
- [ ] Buy arrows at the fletcher ([2], 30 gp). Enter a fight,
      fire missiles ([X]). Arrows deplete; dry quiver falls back
      to melee.
- [ ] Rest at the inn ([3], 10 gp). Slots and quiver return.

## R79: per-member gear caps
- [ ] Smith ([5]): buy a +1 sword; a second sword for the same
      slot is refused (cap). Temple identify ([9]) shows it.

## R80: quiver bundles (the big visible one)
- [ ] Peddler ([M], 500 gp) until you get magic arrows, or win
      them from a lair. dumpEquipment (see R79 key) prints a
      band line like: "  Rolf's quiver: 8 mundane +2 x12".
- [ ] In a fight, fire missiles ([X]): magic shots land before
      mundane ones (front-first FIFO) and the +N applies to-hit
      and damage vs foes needing a plus.

## R81: ring + scroll study
- [ ] Peddler until a Ring of Protection; claim it from the
      treasure screen - the member's AC improves (dumpEquipment
      shows ", ring +1"). A second ring for the same member is
      refused.
- [ ] Buy a spell scroll ([8], 200 gp), return to town, press
      [L] (study desk, new R83 key). Expect one line per scroll:
      "... masters <Spell> from a scroll!" or "... fails to
      master ... the scroll crumbles." Summary: "Studied N
      scroll(s); M spell(s) learned."

## R82: raise dead
- [ ] Let a member die (or load a save with a casualty). With a
      living 7th+ cleric and 1000+ gp in town, press [R].
      Expect the survival line: "... returns to life at
      <cleric>'s word!" (or "... spirit cannot return; the
      offering is spent."). Raised member at 1 hp.

## R83: teleport escape (the finale)
- [ ] MU with INT 15+, level 9+, Teleport known (study scrolls
      or scribe stock), at least one L5 slot. Enter a fight,
      press [C] for the spell menu. NOTE: menu keys are now
      [1-9] then [A-G]; [Esc] closes (C is a cast key now!).
- [ ] Cast Teleport, then [space] to resolve. Expect:
      "The air folds around the company!" then
      "The company teleports away!" - and the company lands in
      TOWN (no spoils, town billing runs: rents/upkeep lines if
      applicable).

## Town screen (R83 layout fix)
- [ ] On the town screen, confirm the overland line is VISIBLE:
      "[O] overland  [V] sea  [W] city - set out" (it was
      overdrawn and invisible since R68), plus the new
      "[L] Study the carried scrolls" and
      "[R] Raise a fallen member - 1,000 gp" lines.

## R85: the pack (+ R86 hire's pack)
- [ ] Win magic gear nobody equips (hoard rolls a weapon no
      member improves with): the log shows
      "Rolf carries the Long Sword +2 (pack 1/6)." - first
      living member with a free slot, 6 slots each.
- [ ] With every member's pack full, the next unclaimed gear
      goes to the henchman instead:
      "Grimnir shoulders the Chain Mail (hire's pack 1/6)."
      (R86; no henchman = appraised as before.)
- [ ] In town press [D] (dump kit): each carrier prints
      "  Rolf's pack (1/6): Long Sword +2".
- [ ] Press [E] (equip best): a member with a mundane sword and
      a +2 in the pack shows "Rolf equips the Long Sword +2."
      and the old kit returns as a keepsake (pack count stays;
      the keepsake never sells).
- [ ] Press [P] (peddle): sale-value items sell, ending with
      "The pack sale nets N gp."; the henchman's cargo sells
      too ("Grimnir sells the Chain Mail for 300 gp.");
      keepsakes stay ("Keepsakes (swapped-out kit) stay
      unsold.").
- [ ] Dungeon HUD roster line: carriers show " pN" after hp
      (R86, at-a-glance pack count).
- [ ] Save ([K]) and load ([L]): packs (member and hire)
      survive the round trip; a pre-R85 save loads clean with
      empty packs.
- [ ] Town screen right column: "PACK: [E] equip best  [P]
      peddle  [D] dump kit" above the quiver list (the quiver
      moved right - it used to collide with the [L]/[R] lines).

## Sign-off
- [ ] No mojibake anywhere on screen (every string is pure ASCII
      since R84 - report ANY stray glyph, it is a bug).
