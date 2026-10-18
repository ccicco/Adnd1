// =========================================================================================
// Adnd1 - rules/dmospells.h
// SPELLS AND MAGICAL ITEMS - DMO Chapter 3 closes: the daily recovery
// doctrine (the good night's sleep and the eight-hour minimum, the ten
// minutes a level, the distraction restart, the eight-hour study cap), the
// wizard and priest per-spell clarifications (the antimagic-shell scope, the
// ESP save ladder, the haste aging, the identify cost, the wish framework
// with its race aging grids, the teleport and astral economics, the
// plane-shift rods with the research grid), and the item doctrines (the
// amulet window, the bag grid, the extradimensional seam with the
// portable-hole gate, the potion bar, the sphere cap, the withering ladders).
// census 526 -> 527.
//
// verified against printed pp. 68-85 of the uploaded DMO session capture
// (part 1, printed page N at OCR page N+1); the Rozmare examples from pp. 69,
// 72 and 74, the permanency rosters from p. 73, the planar-research table
// from p. 79, the bag-of-holding table from p. 80, the item doctrines from
// pp. 79-85. The horrid-wilting die prints 16d8; the OCR B is a misread and
// the pin carries the note.
//
// the gap census after this round: 42 closed, 54 open - Chapter 3 is DONE in
// one round per the advisory-prose scope ruling; the DMO arc continues with
// Chapter 4 (Creating Magical Items, pp. 86-95).
//
namespace rules {

// ---- the DMO spells-and-items pins ----

// the aging-ladder race count: five races, the human, the halfling and
// half-elf band, the dwarf, the gnome, the elf (printed pp. 72 and 76).
inline int deqRaceCount()
    { return 5; }

// the planar-research plane-type count: the inner, outer, demiplane and
// prime-material rows of the research table (printed p. 79).
inline int deqPlaneTypeCount()
    { return 4; }

// the bag-of-holding size count: the 250, 500, 1,000 and 1,500-pound bags
// (printed p. 80).
inline int deqBagTypeCount()
    { return 4; }

// the memorization effort: 10 minutes of study per level of the spell
// (printed p. 68; the Rozmare fly spell at 3rd level takes 30 minutes).
inline int deqMemorizeMinutesPerLevel()
    { return 10; }

// the rest requirement: about eight hours spent in reasonable comfort - never
// a night in a saddle - is the minimum to regain spells (printed p. 68).
inline int deqRestHoursMin()
    { return 8; }

// the limited-study cap: a spellcaster can spend a maximum of eight hours a
// day acquiring spells; past that no concentration remains, with no other
// disadvantage (printed p. 69).
inline int deqStudyHoursMax()
    { return 8; }

// the horrid-wilting cap, the die count: the maximum damage is 16 dice
// (printed p. 69; the OCR renders the die as 16dB, read as 16d8).
inline int deqHorridWiltingDice()
    { return 16; }

// the horrid-wilting cap, the die: d8 (printed p. 69, the OCR B misread).
inline int deqHorridWiltingDieSize()
    { return 8; }

// the cone-of-cold maximum damage, the die count: 10d4+10 points (printed p.
// 70).
inline int deqConeOfColdDice()
    { return 10; }

// the cone-of-cold die: d4, plus the flat 10 (printed p. 70).
inline int deqConeOfColdDieSize()
    { return 4; }

// the cone-of-cold flat bonus: +10 on top of the dice (printed p. 70).
inline int deqConeOfColdBonus()
    { return 10; }

// the delayed-blast-fireball maximum damage, the die count: 15d6+15 points
// (printed p. 70).
inline int deqDelayedBlastDice()
    { return 15; }

// the delayed-blast-fireball die: d6, plus the flat 15 (printed p. 70).
inline int deqDelayedBlastDieSize()
    { return 6; }

// the delayed-blast-fireball flat bonus: +15 on top of the dice (printed p.
// 70).
inline int deqDelayedBlastBonus()
    { return 15; }

// the color-spray geometry, at the hand: a plane five feet wide (printed p.
// 70).
inline int deqColorSprayHandWidthFt()
    { return 5; }

// the color-spray geometry, the length: 20 feet (printed p. 70).
inline int deqColorSprayLengthFt()
    { return 20; }

// the color-spray geometry, at the far end: 20 feet wide (printed p. 70).
inline int deqColorSprayFarWidthFt()
    { return 20; }

// the dispel-magic item rule: an unattended magical item is rendered
// inoperable for 1d4 rounds, the die (printed p. 70).
inline int deqDispelItemInertDie()
    { return 4; }

// the potion dispelling level: all potion effects are treated as magic cast
// at 12th level for purposes of dispelling (printed p. 82).
inline int deqPotionDispelLevel()
    { return 12; }

// the ESP save ladder, the minor tier: +1 when the subject dislikes the
// interrogator or faces embarrassing requests (printed p. 71).
inline int deqEspBonusMinor()
    { return 1; }

// the ESP save ladder, the damaging tier: +2 for a hostile interrogator or
// damaging questions - hidden treasure, betrayed trusts (printed p. 72).
inline int deqEspBonusDamaging()
    { return 2; }

// the ESP save ladder, the serious tier: +3 when the interrogator has
// attacked the subject or asks seriously damaging questions - military plans,
// trade secrets (printed p. 72).
inline int deqEspBonusSerious()
    { return 3; }

// the ESP save ladder, the deep tier: +4 when the interrogator has killed one
// of the subject's companions or probes deeply personal ground - a family
// heirloom, a guarded password (printed p. 72).
inline int deqEspBonusDeep()
    { return 4; }

// the feather-fall auto-cast: at the beginning of any fall of 10 feet or
// more, provided the caster is not prevented from casting (printed p. 72).
inline int deqFeatherFallAutoFt()
    { return 10; }

// the feather-fall extreme band: beyond 120 feet per level the caster can opt
// to delay the spell so the duration does not expire before landing (printed
// p. 72).
inline int deqFeatherFallFtPerLevel()
    { return 120; }

// the feather-fall initiative: the caster adds +1 for the casting time, the
// fall +1 for each 120 feet of free fall (printed p. 72).
inline int deqFeatherFallInitPerBand()
    { return 1; }

// the fly maneuverability: class B on the A=1..E=5 scale, limiting the user
// to turns totaling 180 degrees or less per round (printed p. 72).
inline int deqFlyManeuverClass()
    { return 2; }

// the fly turning budget: 180 degrees per round; past it the flier finishes
// the round straight or stops (printed p. 72).
inline int deqFlyTurnDegrees()
    { return 180; }

// the permanent-fear attack: the recipient radiates a cone once per round as
// a wand of fear - no casting time or command word, but an action with a +3
// initiative modifier (printed p. 72).
inline int deqFearConeInitMod()
    { return 3; }

// the haste aging: one year of magical aging requiring a system shock roll,
// failure meaning death - the aging lands only on the first round, and only
// when a fresh haste's effect overlaps the old (printed p. 72).
inline int deqHasteAgingYears()
    { return 1; }

// the identify ritual: the caster spends the eight hours preceding the
// casting purifying the items to be identified (printed p. 72).
inline int deqIdentifyPurifyHours()
    { return 8; }

// the identify cost: an eight-point temporary Constitution loss inflicted by
// the spell - the moment enemies love (printed p. 72).
inline int deqIdentifyConLoss()
    { return 8; }

// the permanent-invisibility return: any attack breaks it, but the recipient
// can become invisible again the next round at a +3 initiative modifier with
// no other action (printed p. 72).
inline int deqReinvisibilityInitMod()
    { return 3; }

// the limited-wish scope: it can mimic most other spells of 7th level or
// less, but never produce wealth or magical items (printed p. 72).
inline int deqLimitedWishMimicMax()
    { return 7; }

// the wish scope: a wish can always duplicate any spell of 9th level or less
// (printed p. 75).
inline int deqWishDuplicateMax()
    { return 9; }

// the wish cost: most uses lower the caster's Strength/Stamina by three
// points and force 2d4 days of bed rest, the Strength returning at the end of
// the rest (printed p. 75).
inline int deqWishStrLoss()
    { return 3; }

// the wish bed-rest die: 2d4 days (printed p. 75).
inline int deqWishBedRestDie()
    { return 4; }

// the wish bed-rest die count: two dice of the d4 (printed p. 75).
inline int deqWishBedRestCount()
    { return 2; }

// the wish-wealth roll, the count: a random 5,000 to 40,000 gold pieces - 5d8
// x 1,000 (printed p. 76).
inline int deqWishWealthDiceCount()
    { return 5; }

// the wish-wealth roll, the die: d8, multiplied by 1,000 (printed p. 76).
inline int deqWishWealthDieSize()
    { return 8; }

// the wish-wealth multiplier: the 5d8 read in thousands of gold pieces
// (printed p. 76).
inline int deqWishWealthMult()
    { return 1000; }

// the wish-borrowed item: a wish can produce a magical item but not an
// artifact, typically borrowed for about an hour before it goes back where it
// came from (printed p. 76).
inline int deqWishItemLoanHours()
    { return 1; }

// the wish level-advance: an elf can wish to advance in level like a human,
// at most one level per wish, each advance needing its own wish (printed p.
// 76).
inline int deqWishLevelPerWish()
    { return 1; }

// the magic-staff bar: spells stored in the staff are unusable on worlds
// rated M4 or less - the staff of the magi springboard (printed p. 72).
inline int deqMagicStaffMinRating()
    { return 4; }

// the power-word-stun movement cap, the divisor: movement is limited to one
// third the creature's current rate (printed p. 74).
inline int deqPwsMoveDivisor()
    { return 3; }

// the power-word-stun movement cap, the floor: one third the rate or a rate
// of 3, whichever is less (printed p. 74).
inline int deqPwsMoveMax()
    { return 3; }

// the power-word-stun attack bonus: attacks against stunned creatures gain +4
// (printed p. 74).
inline int deqPwsAttackBonus()
    { return 4; }

// the rope-trick limit: the space supports about 1,000 pounds, the DM free to
// adjust - and placing another extradimensional space inside is catastrophic
// (printed p. 74).
inline int deqRopeTrickLbs()
    { return 1000; }

// the stoneskin duration: 24 hours or until the spell absorbs its allotment
// of attacks (printed p. 74).
inline int deqStoneskinHours()
    { return 24; }

// the permanent-teleport object: a single object of no more than 1,000 cubic
// feet - a 10-foot cube (printed p. 75).
inline int deqTeleportPermanentCuFt()
    { return 1000; }

// the permanent-teleport area: an area no larger than 400 square feet - 20
// feet square (printed p. 75).
inline int deqTeleportPermanentSqFt()
    { return 400; }

// the teleport-low arrival: roll 1d100 to see how many yards below the
// surface the caster lands; low into any solid object is always fatal,
// feathers as deadly as rock (printed p. 74).
inline int deqTeleportLowYardsDie()
    { return 100; }

// the permanent unseen servant: it always hovers within 30 feet of the caster
// (printed p. 75).
inline int deqUnseenServantHoverFt()
    { return 30; }

// the permanent unseen servant reform: destroyed, it reforms in 2d10 rounds -
// the die (printed p. 75).
inline int deqUnseenServantReformDie()
    { return 10; }

// the permanent unseen servant reform: two dice of the d10, in rounds
// (printed p. 75).
inline int deqUnseenServantReformCount()
    { return 2; }

// the astral movement rate: 30 times the character's Intelligence/Reason
// score, by pure thought (printed p. 70).
inline int deqAstralMovePerInt()
    { return 30; }

// the astral-death return: a successful system shock draws the traveler back
// to the original body, waking with one hit point (printed p. 70).
inline int deqAstralReturnHp()
    { return 1; }

// the astral-return debilitation: a -4 penalty to dice rolls, moving at half
// speed, no casting or memorizing, until the character regains at least half
// his hit points (printed p. 70).
inline int deqAstralPenalty()
    { return 4; }

// the draw-upon-holy-might cap: the spell cannot increase an ability score
// beyond 25 (printed p. 76).
inline int deqHolyMightCap()
    { return 25; }

// the know-time estimate: on a world with a different time flow, a 2 percent
// chance per caster level of learning the difference - great, moderate or
// minor by the Table 2 bands (printed p. 77).
inline int deqKnowTimePctPerLevel()
    { return 2; }

// the plane-shift load: the caster and up to seven other creatures on a
// one-way trip, a unique forked rod per plane or sphere (printed p. 77).
inline int deqPlaneShiftCompanions()
    { return 7; }

// the pocket-dimension research modifier, cost: add 2,000 gold pieces to the
// attached plane's research cost (printed p. 79; the Ethereal-attached
// example totals 2,500).
inline int deqPocketDimExtraCost()
    { return 2000; }

// the pocket-dimension research modifier, time: add one month - pinned as
// four weeks - to the research time (printed p. 79; the example runs five
// weeks).
inline int deqPocketDimExtraWeeks()
    { return 4; }

// the nap limit: no effect if the recipient is unwilling or has received a
// nap in the previous 18 hours - and it never reduces the
// 10-minutes-per-level study time (printed p. 77).
inline int deqNapWindowHours()
    { return 18; }

// the holy-sentinel rest: a nap spell grants the recovering priest 48 turns
// of rest (printed p. 79).
inline int deqSentinelRestTurns()
    { return 48; }

// the speak-with-dead range: one yard - and the dead do not lie, though they
// can be evasive, misleading or obtusely literal (printed p. 79).
inline int deqSpeakWithDeadRangeYds()
    { return 1; }

// the amulet of life protection: a character whose psyche is held in the
// amulet does not truly die until seven days have passed, any sufficient
// healing reviving him to a positive hit point total (printed p. 79).
inline int deqAmuletPsycheDays()
    { return 7; }

// the Daern's instant-fortress wall rule: a magical weapon inflicts one point
// of damage for every three rounds spent attacking the walls (printed p. 80).
inline int deqFortressDamageRounds()
    { return 3; }

// the portable-hole gate: a hole placed within another extradimensional space
// opens a gate to a random plane, drawing all creatures within a 10-foot
// radius through, no saving throw (printed p. 81).
inline int deqExtradimensionalGateFt()
    { return 10; }

// the flight-item daily rate: miles per day equal to twice the item's flight
// speed - the 4-person carpet at speed 24 covers 48 miles (printed p. 81).
inline int deqFlightDailyMult()
    { return 2; }

// the flight-item day: the rate assumes 10 hours of flying with ample rest
// stops (printed p. 81).
inline int deqFlightNormalHours()
    { return 10; }

// the hurried flight, minimum: 18-20 hours aloft doubles the daily rate at
// forced-march cost (printed p. 81).
inline int deqFlightHurriedMinHours()
    { return 18; }

// the hurried flight, maximum: 20 hours aloft (printed p. 81).
inline int deqFlightHurriedMaxHours()
    { return 20; }

// the round-the-clock flight: 24 hours a day moves at 2.5 times the normal
// daily rate - pinned in half-units as 5 - at double forced march penalties
// (printed p. 81).
inline int deqFlightAllDayMultHalf()
    { return 5; }

// the girdle of many pouches: each small pouch holds about one gallon of
// water or a single tiny creature, four minutes of air when belted and sealed
// (printed p. 82).
inline int deqGirdlePouchGallons()
    { return 1; }

// the girdle of many pouches sealed air: about four minutes (printed p. 82).
inline int deqGirdlePouchAirMin()
    { return 4; }

// the Heward's handy haversack side pouches: two gallons of water or one tiny
// creature each (printed p. 82).
inline int deqHaversackSideGallons()
    { return 2; }

// the Heward's handy haversack central compartment: eight gallons of water or
// a single small creature (printed p. 82).
inline int deqHaversackCentralGallons()
    { return 8; }

// the haversack sealed air: about four minutes (printed p. 82).
inline int deqHaversackAirMin()
    { return 4; }

// the pouch of accessibility: about one gallon of water or a single tiny
// creature per internal pouch (printed p. 83).
inline int deqPouchGallons()
    { return 1; }

// the pouch of accessibility sealed air: about four minutes (printed p. 83).
inline int deqPouchAirMin()
    { return 4; }

// the flatbox capacity: 60 gallons of water, six minutes of air with the lid
// closed - and notoriously unstable (printed p. 81).
inline int deqFlatboxGallons()
    { return 60; }

// the flatbox sealed air: six minutes (printed p. 81).
inline int deqFlatboxAirMin()
    { return 6; }

// the javelin of lightning maximum range: 90 yards, the bolt extending from
// the target back toward the thrower (printed p. 82).
inline int deqJavelinRangeYds()
    { return 90; }

// the javelin of lightning safety margin: never use it against a target
// within 30 feet (printed p. 82).
inline int deqJavelinMinTargetFt()
    { return 30; }

// the portable-hole capacity: about 280 cubic feet (printed p. 82).
inline int deqPortableHoleCuFt()
    { return 280; }

// the portable-hole water load: about 2,100 gallons, or 100,000 standard
// coins, with no weight limit (printed p. 82).
inline int deqPortableHoleGallons()
    { return 2100; }

// the portable-hole coin load: 100,000 standard coins (printed p. 82).
inline int deqPortableHoleCoins()
    { return 100000; }

// the portable-hole air: 10 minutes for a creature inside (printed p. 82).
inline int deqPortableHoleAirMin()
    { return 10; }

// the potion of vitality: natural healing rises to one hit point every four
// hours, restoring even magic-proof damage - but not damage that only magic
// can heal (printed p. 83).
inline int deqVitalityHealHours()
    { return 4; }

// the rod of beguiling radius: 20 feet, no saving throw, magic and mental
// resistance applying, the beguile lasting the full turn even out of the
// radius (printed p. 84).
inline int deqBeguilingRadiusFt()
    { return 20; }

// the rod of beguiling duration: the full one-turn effect (printed p. 84).
inline int deqBeguilingDurationTurns()
    { return 1; }

// the rod of rulership radius: 150 feet - the ruled need not stay inside once
// affected (printed p. 84).
inline int deqRulershipRadiusFt()
    { return 150; }

// the rod of resurrection specialty-priest cost: two charges instead of the
// usual one - healing, protection, warfare and endurance priests still pay
// one (printed p. 84).
inline int deqResurrectionSpecialtyCharges()
    { return 2; }

// the rope of entanglement area: all targets must fit within 200 square feet
// - eight 5-foot squares in any contiguous shape (printed p. 84).
inline int deqEntangleAreaSqFt()
    { return 200; }

// the rope of entanglement escape: successful savers can move 10 feet each
// round and attack nearby creatures, but not the rope (printed p. 84).
inline int deqEntangleSaveMoveFt()
    { return 10; }

// the rope of entanglement penalty: entwined creatures suffer a +2 initiative
// penalty and attacks against them gain +2 (printed p. 84).
inline int deqEntangleInitPenalty()
    { return 2; }

// the rope of entanglement immobile bonus: failed savers are held completely
// immobile, attacks against them at +4 (printed p. 84).
inline int deqEntangleImmobileBonus()
    { return 4; }

// the sphere-of-annihilation control cap: 92 percent for a 21st-level wizard
// of 18 Intelligence/Reason, no bonuses beyond (printed p. 85).
inline int deqSphereControlMax()
    { return 92; }

// the sphere-of-annihilation cap level: 21st (printed p. 85).
inline int deqSphereControlLevel()
    { return 21; }

// the sphere-of-annihilation cap Intelligence/Reason: 18 (printed p. 85).
inline int deqSphereControlInt()
    { return 18; }

// the talisman of the sphere: it doubles the wizard's Intelligence bonus for
// controlling the sphere (printed p. 85).
inline int deqTalismanIntMult()
    { return 2; }

// the staff of withering cost: three charges per withered limb, announced at
// the beginning of the round (printed p. 85).
inline int deqWitherCharges()
    { return 3; }

// the staff of withering humanoid roll: 1d4 - the right arm, the left arm,
// the right leg, the left leg (printed p. 85).
inline int deqWitherLimbDie()
    { return 4; }

// the withered-arm penalty: -2 Dexterity per shriveled arm, the arm useless
// for weapons, shields or unarmed attacks (printed p. 85).
inline int deqWitherArmDexPenalty()
    { return 2; }

// the withered-leg penalty: -6 Dexterity, reduced to a crawl, no physical
// attacks, a crutch needed to walk (printed p. 85).
inline int deqWitherLegDexPenalty()
    { return 6; }

// the withered quadruped movement, the numerator: a one-leg-shriveled
// quadruped moves at 2/3 its normal rate (printed p. 85).
inline int deqWitherQuadMoveNum()
    { return 2; }

// the withered quadruped movement, the denominator: 2/3 rate, no attacks with
// the shriveled limb, two limbs meaning no movement or physical attack
// (printed p. 85).
inline int deqWitherQuadMoveDen()
    { return 3; }

// the staff of withering quadruped roll: 1d6, 1-3 the right and 4-6 the left
// - the flying-humanoid roll riding the same die with the wings at 5 and 6
// (printed p. 85).
inline int deqWitherQuadLimbDie()
    { return 6; }

// the withered-limb regeneration: regenerators recover the limb after
// regenerating the equivalent of 20 points of damage - the ring wearer in 20
// turns, the troll in seven rounds (printed p. 85).
inline int deqWitherRegenPoints()
    { return 20; }

// the wand of negation initiative: +1 - it suppresses a device's spell-like
// function, expending its charges, but never cast spells or innate abilities
// (printed p. 85).
inline int deqNegationInitMod()
    { return 1; }

// the scroll bar: spell scrolls go inert on worlds rated M2 or lower - and
// the plane of Elemental Water turns a fireball scroll into harmless vapor
// (printed p. 84).
inline int deqScrollMinMagicRating()
    { return 2; }

// the stone of good luck bonus: +1 - or +5 percent - whenever dice decide
// whether the character, not the equipment, avoids an adverse happening:
// saves, system shock, resurrection survival (printed p. 85).
inline int deqStoneLuckBonus()
    { return 1; }

// the stone of good luck percentage form: +5 percent (printed p. 85).
inline int deqStoneLuckPctBonus()
    { return 5; }

// the no-sleep rule: characters who do not require sleep acquire spells only
// once each day and only after eight hours of restful calm, never immediately
// after movement, combat or spellcasting (printed p. 69).
inline bool deqNoSleepOnceDaily()
    { return true; }

// the distraction doctrine: a disturbed caster must begin the spell again,
// all time already spent lost - the pixie-prank Rozmare restarts her
// 30-minute fly (printed p. 69).
inline bool deqDistractionRestarts()
    { return true; }

// the antimagic-shell doctrine: the shell suppresses magic within the area
// but destroys or dispels nothing and kills no magical creatures - the golem,
// simulacrum, clone and most undead pass unaffected, conjured and
// extra-planar creatures hedged out (printed p. 69).
inline bool deqShellNoDestroy()
    { return true; }

// the antimagic-shell scope: special attacks working over a distance -
// breath, gaze, sonic, psionics - are suppressed, but touch-delivered attacks
// like energy draining stay effective; holy water is not magical and works
// fully (printed p. 69).
inline bool deqShellBlocksRangedOnly()
    { return true; }

// the astral-projection rule: the character dies immediately if the physical
// body is killed; dispel magic on the body recalls the traveler unharmed;
// projected items go inert on the Prime (printed pp. 69-70).
inline bool deqAstralDiesWithBody()
    { return true; }

// the haste stacking rule: two or more haste-type effects grant only the
// best, and haste never magnifies magical items - boots or potions of speed
// (printed p. 71).
inline bool deqHasteNeverStacks()
    { return true; }

// the stoneskin rule: multiple stoneskins on one creature are not cumulative
// - the better protection wins, and the caster does not know the count;
// stoneskin blocks only blows, cuts, pokes and slashes, never falls, magic,
// touch attacks or non-blow poisons (printed p. 74).
inline bool deqStoneskinNonCumulative()
    { return true; }

// the permanency doctrine: a permanent spell on a creature is dispelled only
// by a caster of greater level than the permanency caster at casting time,
// the dispel targeted solely on the creature; object and area permanencies
// can be dispelled by any caster, one effect per casting (printed p. 73).
inline bool deqPermanentDispelledOnlyByGreater()
    { return true; }

// the identify handling rule: the caster must handle the item - wear or wield
// it as intended - so cursed items can bite, and no charges or pluses are
// ever revealed (printed p. 72).
inline bool deqIdentifyWearItem()
    { return true; }

// the wish adjudication: an errant wish follows the player's wording to the
// letter and the result follows the path of least resistance - the greedy
// staff-wisher standing naked before the former owner (printed p. 76).
inline bool deqWishLetterAndLeastResistance()
    { return true; }

// the wish exemption: a change that leaves the caster no better off than
// before the wished-for events skips the Strength loss and the bed rest - the
// never-met-monster wish; any created advantage pays the full cost (printed
// p. 76).
inline bool deqWishNoGainNoRest()
    { return true; }

// the teleport destination rule: a firm surface is required - never open air
// or a water pool chosen to dodge the low arrival (printed p. 74).
inline bool deqTeleportNeedsFirmSurface()
    { return true; }

// the polymorph doctrine: the survivor gains purely physical abilities only -
// never magic, agility or intelligence based ones unless the mentality
// changes too; polymorph self grants movement and breathing only (printed p.
// 73).
inline bool deqPolymorphNoMagicAbilities()
    { return true; }

// the polymorph-self limit: the caster can assume only forms he has
// personally seen - never the unseen ochre jelly (printed p. 74).
inline bool deqPolymorphSeenFormsOnly()
    { return true; }

// the shape-change doctrine: any non-magical, non-mental ability of the
// assumed form is gained - the owl's night vision yes, the cockatrice's
// petrifying touch no, never magic resistance (printed p. 74).
inline bool deqShapeChangeNonmagicalOnly()
    { return true; }

// the permanent stinking cloud: it stays and returns one round after any
// wind, hurricane force included, dispersing it; fire burns it away for one
// round after the flames die (printed p. 74).
inline bool deqStinkingCloudPermanent()
    { return true; }

// the permanent web doctrine: torn or burned-away webbing springs back - new
// webs replacing the old one round after the flames die, chunks carried out
// dissolving in seconds (printed p. 75).
inline bool deqPermanentWebReforms()
    { return true; }

// the restore-youth doctrine: it negates aging that is the magic's primary
// effect - age creature, the withering staff, the ghost - but never
// incidental aging from a wish or haste (printed p. 76).
inline bool deqAgeCreatureNegatesMagicalAging()
    { return true; }

// the extradimensional-seam doctrine: one such space placed inside another
// opens an Astral rift scattering both - the rope-trick rest camp - with the
// portable hole's inside-out gate and the flatbox's explosion the exceptions
// (printed p. 81).
inline bool deqExtradimensionalRift()
    { return true; }

// the potion-dispelling rule: an imbiber-only effect cannot be removed unless
// the dispel targets the creature directly; control-potion effects reaching
// others dispel normally, all at the 12th-level bar (printed p. 82).
inline bool deqPotionsSelfOnlyDispelled()
    { return true; }

// the potion-in-shell rule: a potion consumed inside an antimagic shell
// activates only on leaving; a consumed one is suppressed unless permanent -
// healing potions riding through (printed p. 82).
inline bool deqPotionShellDelayed()
    { return true; }

// the ring-of-regeneration rule: it repairs only damage inflicted after the
// ring goes on - never reviving the dead or unconscious - and removes no need
// to eat, sleep or breathe (printed p. 83).
inline bool deqRingRegenOnlyPostDonning()
    { return true; }

// the rod-of-absorption doctrine: only spells targeted specifically at the
// wielder can be absorbed - never the fireball burst centered elsewhere - an
// absorbed multi-target spell is negated for everyone, and 10th-level spells
// can never be absorbed (printed p. 83).
inline bool deqRodAbsorbTargetOnly()
    { return true; }

// the deck-of-many-things rule: its banes cannot be removed by wishes or
// lesser means - a wish only helps indirectly, and 10th-level wards cannot
// shield the harm while keeping the benefit (printed p. 81).
inline bool deqDeckWishProof()
    { return true; }

// the gem-of-insight rule: a character benefits only once in a lifetime, no
// matter how many gems are found or kept (printed p. 82).
inline bool deqGemInsightOnce()
    { return true; }

// the quiver-of-Ehlonna limit: only long, thin objects fit - no creatures, no
// water (printed p. 83).
inline bool deqQuiverNoCreatures()
    { return true; }

// the iron-bands-of-Bilarro rule: no saving throw but a successful attack
// roll required, a miss never entrapping; free action, wraithform, antimagic
// shell and duo-dimension all free the victim - teleportation merely moves
// the bands along (printed p. 82).
inline bool deqIronBandsEscapable()
    { return true; }

// the weighty-chest rule: the weight increase triggers only when another
// creature tries to move or lift the chest - it can never be used as a
// weapon, though a foe can be tricked into lifting it (printed p. 79).
inline bool deqWeightyChestNoWeapon()
    { return true; }

// the book doctrine: baneful and beneficial effects alike trigger on perusing
// even a small passage; magical books vanish after helping and stay after
// harming, and the multi-classed character takes only the best result
// (printed p. 80).
inline bool deqBooksTriggerOnPerusal()
    { return true; }

// the cloak-of-displacement doctrine: the first melee or missile attack
// automatically misses and only that one, observers adjusting after; unaimed
// and area attacks ignore displacement, spells without attack rolls never
// miss but grant the +2 save (printed p. 80).
inline bool deqDisplacementFirstAttackOnly()
    { return true; }

// the flight-item endurance rule: staying aloft 18-20 hours doubles the daily
// rate at forced-march cost, and 24-hour flying suffers double forced-march
// penalties (printed p. 81).
inline bool deqFlightForcedMarch()
    { return true; }

// the scroll rule: priests cannot read wizard scrolls nor wizards priest
// scrolls - but any reader of the right type reads past his normal
// restrictions, the illusionist reading dispel magic, the priest reading
// closed spheres (printed p. 84).
inline bool deqScrollsCrossClass()
    { return true; }

// the sphere-of-annihilation rule: an adjusted control score of 100 percent
// or more means automatic success, other wizards able to contest the control
// (printed p. 85).
inline bool deqSphereAutoAbove100()
    { return true; }

// the limited-wish aging in years for the race - one year for a human, two
// for a halfling or half-elf, three for a dwarf, four for a gnome, five for
// an elf (printed p. 72).
inline int deqLimitedWishAgingYears(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return -99;
        }
    }

// the wish aging in years for the race - five for a human, 10 for a halfling
// or half-elf, 15 for a dwarf, 20 for a gnome, 25 for an elf (printed p. 76).
inline int deqWishAgingYears(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 25;
        default:
            return -99;
        }
    }

// the research cost in gold pieces for a generally-known plane of this type
// (printed p. 79).
inline int deqResearchKnownCost(int b)
    {
        switch (b) {
        case 0:
            return 500;
        case 1:
            return 1000;
        case 2:
            return 5000;
        case 3:
            return 750;
        default:
            return -99;
        }
    }

// the research cost in gold pieces for a little-known plane of this type
// (printed p. 79).
inline int deqResearchUnknownCost(int b)
    {
        switch (b) {
        case 0:
            return 1500;
        case 1:
            return 3000;
        case 2:
            return 15000;
        case 3:
            return 3000;
        default:
            return -99;
        }
    }

// the research time in weeks for a generally-known plane of this type - a
// month pins as four weeks, a year as 52 (printed p. 79).
inline int deqResearchKnownWeeks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 8;
        case 3:
            return 3;
        default:
            return -99;
        }
    }

// the research time in weeks for a little-known plane of this type (printed
// p. 79).
inline int deqResearchUnknownWeeks(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 12;
        case 2:
            return 52;
        case 3:
            return 9;
        default:
            return -99;
        }
    }

// the rod construction cost in gold pieces for the plane type, rare materials
// costing more (printed p. 79).
inline int deqRodCost(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 300;
        case 2:
            return 400;
        case 3:
            return 250;
        default:
            return -99;
        }
    }

// the capacity in pounds of the bag - 250, 500, 1,000, 1,500 (printed p. 80).
inline int deqBagCapacityLbs(int b)
    {
        switch (b) {
        case 0:
            return 250;
        case 1:
            return 500;
        case 2:
            return 1000;
        case 3:
            return 1500;
        default:
            return -99;
        }
    }

// the minutes of air for a single creature in the sealed bag; at twice the
// listed time the gasping saves begin (printed p. 80).
inline int deqBagAirMinutes(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 10;
        default:
            return -99;
        }
    }

// the water capacity in gallons of the bag - 30, 60, 120, 180, a full load
// reading ten percent (printed p. 80).
inline int deqBagWaterGallons(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 60;
        case 2:
            return 120;
        case 3:
            return 180;
        default:
            return -99;
        }
    }

}   // namespace rules
