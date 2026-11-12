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

## R87: the burden (encumbrance wired to the pack)
- [ ] [D] dump kit: every member now prints a burden line,
      e.g. "  Rolf: moderately burdened (920 gp wt, move 60')"
      (worn kit + pack cargo, STR-scaled bands, PHB p.76).
- [ ] A STR 10 member wearing plate armor can carry at most
      ONE spare suit of plate in the pack - a second is
      refused (over-heavy) and left appraised in the hoard.
      A STR 18 member carries three.
- [ ] The henchman shoulders cargo up to his own limit
      (heavy threshold 1260 gp at STR 12, kit already 625);
      past it the item stays appraised ("...shoulders..." only
      while it fits).

## R88: the warning + the hire's dump
- [ ] [D] dump kit now ends with the henchman's block (when
      hired): "Grimnir: Long Sword, Plate Mail, shield",
      his cargo pack line, and his burden line (STR 12).
- [ ] [E] on a member already over the HEAVY band (weak STR
      in plate kit, or a pre-R87 save): the swap happens and
      the log adds "  (now heavily burdened - movement 30')".
      Swaps conserve carried weight (the old kit returns to
      the pack) - the warning is a state echo, not a cause.
- [ ] Dungeon HUD status line now shows "Move N'" (company
      pace: the slowest living member's band; 120' unburdened).

## R89: the scale + the pace
- [ ] [D] dump kit: the "Carried:" line now ends
      "(coin N wt each)" - the purse weighs (10 coins per
      gp unit, split across living members).
- [ ] Burden lines count the coin share: a lone member
      hauling 20,000 gp shows "heavily burdened (2020 gp wt,
      move 30')" and the HUD Move reads 30'.
- [ ] Spend the purse in town and the company springs back to
      120' instantly (coin is liquid).
- [ ] The pace is mechanical: watch Turn on the HUD while
      walking - an unburdened company advances one turn per
      step; a 30' company gains four turns per step (wander
      checks fire only on turns - the laden are interrupted
      far more often; watch "Movement in the distance..." and
      count turns per step).

## R90: the camp clock
- [ ] Rest in the dungeon ([R]): on success the HUD Turn jumps
      by 48 (8 hours of camp - sleep finally costs time); an
      interrupted rest ("The rest is interrupted!") jumps it
      by 4 (the watch before the ambush).
- [ ] Quaff a potion in the dungeon ([P]): Turn advances by
      1 and the quaff can draw "Movement in the distance..."
      (drinking in the halls is not free; combat quaffs are
      unchanged - combat time is the round system).
- [ ] Walking behavior is unchanged from R89 (one turn per
      step unburdened, four at 30') - the refactor onto the
      shared tick math must be invisible.

## R91: the stairs
- [ ] Descend the stairs (step onto them): the new level's
      HUD Turn starts at 36 (the 6-hour trek lands on the new
      level's clock - not a fresh zero).
- [ ] Occasionally the arrival line "Something followed you
      down!" appears with the level announcement - the one
      arrival wander check (camp parity: hours pass, one
      bite). The follower fight happens on the new level.

## R92: the road home
- [ ] Retreat to town ([B]): the return is no longer instant -
      rarely "Something follows you to the stairs!" fires and
      the fight happens ON the dungeon level (press [B] again
      after winning to finish the climb; the mode only
      switches on a clean road).
- [ ] A normal return still reads "You return to the town
      above." with the billing lines (rents, henchman pay).

## R93: the ledger
- [ ] Return to town ([B], clean road): after "You return to
      the town above." the report line prints
      "Delve #1 complete - 1200 gp hauled (career: depth 3,
      1200 gp)." - count, gross haul, career depth and
      lifetime gold. The count increments ONLY on the return
      (a bitten retreat retried does not double-count; the
      count closes on the clean road).
- [ ] Descend deeper on a later delve and the career depth
      in the report grows (never shrinks).
- [ ] HUD: when the company is laden (Move under 120') the
      status line shows "Move 60'*" - the asterisk is the
      encumbrance cue (120' shows no star).
- [ ] Save ([K]) and load ([L]): the ledger survives the
      round trip; a pre-R93 save loads with a clean ledger
      (Delve #1 on the next return).

## R106: the keep's ledger
- [ ] Build the keep, idle ~30 career days (inn rests or
      sea days), return - 200 gp upkeep bills ("the
      garrison takes 200 gp (1 months' upkeep)")
- [ ] The rents still deliver while the purse pays; save/
      load round-trips the ledger (the stronghold line
      reads five ints)
- [ ] Delve often, return - months pass slower than
      visits, upkeep bills only when a month truly passed
- [ ] A thin purse at billing books a debt; while debt
      stands the rents are garnished against it until
      cleared
- [ ] A pre-R106 save (two-int stronghold line) loads with
      an unknown build day - the first return stamps it
      and bills from THAT day (no retroactive debt)

## R105: the crew's nerve
- [ ] Hire the crew, save, load - the crew survives with
      its morale (the crew line reads two ints)
- [ ] Return to port with gold short - "grumbles over
      unpaid wages", and repeated short returns wear the
      nerve toward the floor
- [ ] Three+ unpaid returns: the crew deserts ("slips
      away by night"), crewHired is false, [C] rehires
      at 200 gp with a fresh nerve
- [ ] Paid returns and rich delves (crew share) recover
      the nerve
- [ ] A pre-R105 save (crew line with one int) loads with
      unknown morale, freshened to 60 at its next wage
      billing - no desertion on arrival

## R103: the carrot
- [ ] [G] with a hire: 25 gp leaves the purse into his,
      loyalty +5; the message shows the new loyalty
- [ ] [G] at loyalty 100+: "is content - he takes no
      gifts" (no gold moves)
- [ ] [J] after plate: the raise - 500 gp, his upkeep
      message on the next return reads 100/level +100
- [ ] [J] after the raise: "nothing more to give him"
- [ ] Save/load round-trips plate AND raise (eighth
      trailing int); a pre-R103 save loads with no raise

## R102: the ledger of everything
- [ ] Pick up scrolls in the dungeon, save, load - the
      satchel keeps its count (pre-R102 a reload wiped
      every held scroll)
- [ ] Study scrolls in town after a load - the count
      falls as scrolls are studied
- [ ] The status line's scroll count matches after a
      save/load round-trip
- [ ] A pre-R102 save (no cscrolls line) loads with an
      empty satchel, as before

## R101: the plate kit
- [ ] Buy the hire's plate ([J], 100 gp from his purse),
      save, load - he still wears plate (pre-R101 the
      reload silently stripped it and the 100 gp with it)
- [ ] Hire the coaster's crew, save, load - the ship
      remembers it sails (pre-R101 a reload forgot)
- [ ] A save made before a hire/crew round-trips clean
      (both lines absent, defaults false)
- [ ] The plate is a fresh hire's ladder bottom again -
      only the bought plate persists

## R100: the hire's years
- [ ] The hire's answer line reads "answers the offer at
      N years!" (16..19)
- [ ] The inn birthday that crosses a 365-day mark logs
      the hire's birthday too
- [ ] CRITICAL (R100 repair): save with a hired henchman,
      then load - it must load clean, and the hire's name,
      loyalty, xp, purse, kit pluses and age all survive
      (pre-R100 such saves failed "corrupt (hire)")
- [ ] An absent-hire save still writes "henchman 0" and
      loads clean

## R98: the years tell
- [ ] A member crossing 45/60/90 at an inn birthday logs
      "The years tell on him - the bend of the age."
- [ ] The bend: STR/CON/DEX -1/-2/-3, INT/WIS +1/+2/+3,
      CHA untouched, scores clamp 3..18
- [ ] The bend applies once per bracket (a save made
      after the birthday round-trips the bent scores)
- [ ] Members under 45 see no change at their birthdays

## R97: the gray beard
- [ ] A new member's join line reads "joins the party at
      N years" (fighter 16-19, cleric/thief 19-22, MU 26-40)
- [ ] The inn night that crosses a 365-day career mark
      logs "N turns M years old." for each living member
- [ ] A save round-trips the age; a v1 save loads with
      startAge 0 and no birthday lines
- [ ] The delve report and training days are unaffected

## R96: the town clock
- [ ] An inn night (10 gp) advances the career day count
      by one and the message says "a career day spent"
- [ ] Training adds days equal to the new level; the
      receipt reads "Training paid (N gp, D days)."
- [ ] Temple healing changes no days (same-day service)
- [ ] A save round-trips the grown career day count

## R95: the calendar
- [ ] Each overland march ([T]/[H]) and sea sailing day
      increments the career day count
- [ ] The delve report line ends with the career day total
- [ ] A save round-trips the caldays value; a v1 save loads
      with 0 career days
- [ ] The town arrival string reads "The walls of town rise
      ahead - the journey is over." (no mangled text)

## R94: the nerve
- [ ] With the henchman hired, descend DEEPER than ever
      before: the log shows "The unlit deeps weigh on
      <name>." (only a new record moves him - known halls
      do not).
- [ ] An interrupted camp or a bitten retreat road shows no
      line but quietly costs him 1 nerve (watch the loyalty
      figure on the town screen roster if displayed).
- [ ] A clean return shows "<name> is flush with the
      success." (+3) after the Delve #N report line.
- [ ] The existing quit checks are unchanged: loyalty below
      25 in town billing, or a failed d100 at the descent
      gate, still loses him - but the stat now moves with
      the career instead of only dunning.

## Sign-off
- [ ] No mojibake anywhere on screen (every string is pure ASCII
      since R84 - report ANY stray glyph, it is a bug).
