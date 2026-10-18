// =========================================================================================
// Adnd1 - rules/dmodweomers.h
// TRUE DWEOMERS - DMO Chapter 6 closes: the requirement gates (wizards and
// priests of 20th level with ability 18, at most four dweomers a day, never
// scrollable or storable), the difficulty calculus (the combined
// type-plus-area-plus-range-plus-duration total less the caster level, less
// five for a specialist, less ten when practiced, then the component and
// condition reductions - three rares at minus ten each within a 30-point
// limit, an exotic at half or minus 20), the eight grids (the Table 28
// 29-type ladder from charm 20 through slay 50 with the variable shadow
// shape, the Table 29 areas from five feet to a whole plane at difficulty
// 160, the Table 30 animated objects, the Table 31 ranges touch through
// trans-planar, the Table 32 durations instantaneous through permanent at
// 100, the Table 33 prep-and-cast bands - a year of preparation and a week of
// casting at 151-plus - and the Table 35 duel-type mirror), the school
// effects (the dispel 50-percent read at 11-plus on 1d20, the ward ladder to
// the 210-point full resistance, the reflect, fortify, transform, afflict,
// conjure, summon, imbue, reveal and tap ladders in their doubling and
// tripling steps, the strike capped at 30d8), the preparation doctrine (the
// eight-hour day, the restart and backtrack rules, the 1d100 final check, the
// halve-or-minus-10 extension trade), the Pharjis worked creation computing
// 110 down to a final 10 with the 02-fail and 81-success rolls, the in-play
// doctrine (the duel PR 19, the wish auto-dispel, the quest-spell ward floor
// of 18), and the thirteen known dweomers from Hurd's Obligation to Yunni's
// Herald with their difficulty pairs.
// census 529 -> 530.
//
// verified against printed pp. 118-141 of the uploaded DMO session capture
// (part 2, printed page N at OCR page N+90); the requirements and calculus
// from pp. 118-120, the Table 28 grid and school effects from pp. 120-130,
// the Tables 29 through 33 from pp. 130-133, the preparation and final-check
// rules from pp. 133-134, the worked creation from p. 134, the in-play and
// duel and quest doctrines from pp. 134-136, the thirteen known dweomers from
// pp. 136-141. The worked-example region watch reads a half-day duration at
// +10; Table 32 prints six hours at 7 and 12 hours at 10 - the example's own
// arithmetic (+10) is pinned verbatim with the note here.
//
// the gap census after this round: 79 closed, 17 open - Chapter 6 is DONE in
// one round, ten boxes flip (nine children and the parent); the DMO arc
// continues with Chapter 7 (High-Level Characters, pp. 142-164).
//
namespace rules {

// ---- the DMO dweomer-requirement pins ----

// the knowledge gate: wizards and priests must be at least 20th level to cast
// true dweomers (printed p. 119).
inline int devMinCasterLevel()
    { return 20; }

// the knowledge gate: Intelligence 18 or higher for wizards, Wisdom 18 or
// higher for priests (printed p. 119).
inline int devMinAbilityScore()
    { return 18; }

// the daily cap: no mortal can prepare, cast or hold ready more than four
// true dweomers in a single day (printed p. 119).
inline int devMaxPerDay()
    { return 4; }

// the unrecordable rule: a true dweomer can never be written onto a scroll,
// recorded in a spellbook or stored in a magical device (printed p. 119).
inline bool devNoScrollOrDevice()
    { return true; }

// the flux rule: every true dweomer is a little different each time it is
// cast - the energies constantly change (printed p. 119).
inline bool devNeverSameTwice()
    { return true; }

// the approval gate: the DM must approve a true dweomer before it is used;
// there is no cost beyond materials (printed p. 119).
inline bool devDmApprovalRequired()
    { return true; }

// the school rule: wizards cast dweomers using their available schools;
// priests use any school but must reflect their deity's portfolio (printed p.
// 119).
inline bool devWizardsAnySchool()
    { return true; }

// the component floor: every true dweomer requires at least one common
// material component, with no difficulty reduction for multiples (printed p.
// 131).
inline bool devCommonComponentRequired()
    { return true; }

// the priest read: priest dweomers require holy symbols, not consumed; other
// components are (printed p. 119).
inline bool devPriestHolySymbolNeeded()
    { return true; }

// the wizard read: no spellbook needed, though written notes help (printed p.
// 119).
inline bool devWizardsNeedNoSpellbook()
    { return true; }

// the symbolism rule: a component must be symbolic of what the spell does - a
// diamond for earth or value, not mere cost (printed p. 119).
inline bool devComponentsSymbolic()
    { return true; }

// ---- the DMO difficulty-calculus pins ----

// the difficulty calculus: the caster's level is subtracted from the combined
// difficulty total (printed p. 120).
inline int devCasterLevelStep()
    { return -1; }

// the specialist read: a specialist wizard subtracts an extra five points
// when using a type from the school of specialization (printed p. 120).
inline int devSpecialistBonus()
    { return -5; }

// the practiced read: casting the same spell before, or holding notes from
// one who has, subtracts 10 more points (printed p. 120).
inline int devPrevCastBonus()
    { return -10; }

// the rare component: each rare component reduces the adjusted or final
// difficulty by 10, at most three per spell, a 30-point limit (printed p.
// 131).
inline int devRareComponentAdjust()
    { return -10; }

// the rare component: at most three per spell (printed p. 131).
inline int devRareComponentMax()
    { return 3; }

// the rare component: the total limit once per spell (printed p. 131).
inline int devRareComponentLimit()
    { return -30; }

// the exotic component: reduces the adjusted or final difficulty by half or
// by 20 points, whichever is greater (printed p. 131).
inline int devExoticComponentAdjust()
    { return -20; }

// the rare condition: an extra-effort or extraordinary-expense condition
// reduces the difficulty by 10, only one per spell (printed p. 132).
inline int devRareConditionAdjust()
    { return -10; }

// the exotic condition: an adventure-borne condition reduces by half or 20,
// only one per spell, either difficulty but not both (printed p. 133).
inline int devExoticConditionAdjust()
    { return -20; }

// the save trade: each +5 added to the difficulty imposes a -1 saving throw
// modifier on the target; each -5 gives +1 (printed p. 132).
inline int devSaveModPerFive()
    { return 5; }

// the save trade: a difficulty modifier of 100 eliminates any saving throw
// (printed p. 132).
inline int devNoSaveDifficulty()
    { return 100; }

// the resistance trade: each +1 of difficulty reduces the target's magic
// resistance by 1 percent; resistance can never be raised to buy ease
// (printed p. 132).
inline int devMrModPerPoint()
    { return 1; }

// the exotic component: a single exotic component reduces either the adjusted
// or the final difficulty, never both (printed p. 131).
inline bool devExoticEitherNotBoth()
    { return true; }

// ---- the DMO abjuration-effect pins ----

// the dispel read: at base difficulty 30 the chance to destroy an opposing
// spell is 50 percent, a roll of 11 or higher on 1d20 (printed p. 122).
inline int devDispelBasePct()
    { return 50; }

// the dispel read: 11 or higher on 1d20 indicates success (printed p. 122).
inline int devDispelSuccessRollMin()
    { return 11; }

// the dispel read: against spells of 9th level or lower the base chance is
// 100 percent and the area is irrelevant (printed p. 122).
inline int devDispelLowMagicPct()
    { return 100; }

// the dispel read: a lower-level dispel renders a permanent effect or item
// nonoperational for 1d4 rounds (printed p. 122).
inline int devDispelItemSuppressRounds()
    { return 4; }

// the dispel read: the 1d4-round suppression (printed p. 122).
inline int devDispelItemDieSize()
    { return 4; }

// the dispel read: +1 to the die roll for every five points of added
// difficulty; an extended dispel creates a zone of antimagic (printed p.
// 122).
inline int devDispelAugmentPerFive()
    { return 5; }

// the ward read: at base 35 the ward grants +4 against magical attacks, or a
// -4 attack penalty when no save applies (printed p. 122).
inline int devWardSaveBonus()
    { return 4; }

// the ward read: added difficulty negates one point of damage for every two
// points of difficulty, computed after saves (printed p. 122).
inline int devWardDamagePerTwo()
    { return 2; }

// the ward read: at difficulty 105 the ward grants 50 percent resistance to
// the attack form (printed p. 122).
inline int devWardPctResistDifficulty()
    { return 105; }

// the ward read: at difficulty 210 the ward provides 100 percent resistance
// (printed p. 122).
inline int devWardFullResistDifficulty()
    { return 210; }

// the ward hedge: hedging out a type of creature doubles the difficulty to 70
// (printed p. 122).
inline int devWardHedgeTypeDifficulty()
    { return 70; }

// the ward hedge: a general class of creature triples it to 105 (printed p.
// 122).
inline int devWardHedgeClassDifficulty()
    { return 105; }

// the reflect ladder: one specific action by one creature reverses at base 25
// (printed p. 122).
inline int devReflectSingleDifficulty()
    { return 25; }

// the reflect ladder: a limited class of actions doubles the difficulty to 50
// (printed p. 122).
inline int devReflectLimitedDifficulty()
    { return 50; }

// the reflect ladder: a general class of actions triples it to 75 (printed p.
// 122).
inline int devReflectGeneralDifficulty()
    { return 75; }

// the ward read: even if the save fails, damage from the warded attack is
// reduced by half (printed p. 122).
inline bool devWardHalfEvenOnFail()
    { return true; }

// the ward read: a warded creature with magic resistance gets two separate
// resistance rolls, never added (printed p. 122).
inline bool devWardTwoResistRolls()
    { return true; }

// ---- the DMO alteration-effect pins ----

// the animate read: at base 25 an object of 50 pounds or less moves at speed
// 12 (printed p. 123).
inline int devAnimateObjWeight()
    { return 50; }

// the animate read: the base movement rate 12 (printed p. 123).
inline int devAnimateObjSpeed()
    { return 12; }

// the destroy read: a smashed object can be remade at 1d6 x 10 percent of its
// original cost (printed p. 123).
inline int devDestroyRemakeDie()
    { return 6; }

// the destroy read: the 10-percent multiplier (printed p. 123).
inline int devDestroyRemakePctMult()
    { return 10; }

// the destroy read: doubling to 90 shatters or disintegrates utterly (printed
// p. 123).
inline int devDestroyDisintegrateDifficulty()
    { return 90; }

// the fortify ladder: base 30 gains 10 percent; 60 gains 1d4x10; 90 gains
// 2d3x10; 120 gains 3d4x10; each further multiple adds 1d4x10 (printed p.
// 124).
inline int devFortifyBasePct()
    { return 10; }

// the fortify ladder: the doubled difficulty (printed p. 124).
inline int devFortifyDoubleDifficulty()
    { return 60; }

// the fortify ladder: the tripled difficulty (printed p. 124).
inline int devFortifyTripleDifficulty()
    { return 90; }

// the fortify ladder: the quadrupled difficulty (printed p. 124).
inline int devFortifyQuadDifficulty()
    { return 120; }

// the fortify ability read: each 10 percent gain is +1 if the enhanced score
// is 15 or less (printed p. 124).
inline int devFortifyAbilityLowBonus()
    { return 1; }

// the fortify ability read: each 100 percent gain is +1 if the score is 16 or
// higher (printed p. 124).
inline int devFortifyAbilityHighBonus()
    { return 1; }

// the transform read: no single object over 50 tons (printed p. 124).
inline int devTransformMaxTons()
    { return 50; }

// the transform ladder: doubling to 70 transforms a living creature or one
// material to a similar one (printed p. 124).
inline int devTransformCreatureDifficulty()
    { return 70; }

// the transform ladder: tripling to 105 transforms a creature into an object
// or material to a wholly different type (printed p. 124).
inline int devTransformObjectDifficulty()
    { return 105; }

// the transport ladder: base 35 adds 12 to movement or grants a new mode -
// fly or swim 12, burrow or jump 3, difficult terrain 6 (printed p. 124).
inline int devTransportBaseBonusMv()
    { return 12; }

// the transport ladder: the burrow or jump rate (printed p. 124).
inline int devTransportBurrowMv()
    { return 3; }

// the transport ladder: the difficult-terrain rate (printed p. 124).
inline int devTransportDifficultMv()
    { return 6; }

// the transport ladder: doubling to 70 doubles the speed or grants
// extraordinary movement at 3 (printed p. 124).
inline int devTransportDoubleDifficulty()
    { return 70; }

// the transport ladder: tripling to 105 allows error-free teleportation,
// range factored from Table 31 (printed p. 124).
inline int devTransportTeleportDifficulty()
    { return 105; }

// the afflict ladder: base 40 a minor affliction; 80 major; 120 life-ruining;
// 160 life-imperiling (printed p. 124).
inline int devAfflictBaseDifficulty()
    { return 40; }

// the afflict ladder: a harmless affliction at half difficulty 20, duration
// modifiers halved too (printed p. 124).
inline int devAfflictHarmlessDifficulty()
    { return 20; }

// the afflict ladder: the doubled difficulty (printed p. 124).
inline int devAfflictDoubleDifficulty()
    { return 80; }

// the afflict ladder: the tripled difficulty (printed p. 124).
inline int devAfflictTripleDifficulty()
    { return 120; }

// the afflict ladder: the quadrupled difficulty (printed p. 124).
inline int devAfflictQuadDifficulty()
    { return 160; }

// the transform read: a simple transformation of nonmagical material can be
// made permanent without a Constitution loss (printed p. 124).
inline bool devTransformSimplePermanentFree()
    { return true; }

// the afflict read: a harmless affliction can be made permanent without a
// Constitution loss, as can a condition the victim can end (printed p. 124).
inline bool devAfflictHarmlessPermanentFree()
    { return true; }

// ---- the DMO conjuration-effect pins ----

// the bind read: base 35 imposes one agreement while the target keeps its
// will; even charm-immune creatures can be bound (printed p. 125).
inline int devBindBaseDifficulty()
    { return 35; }

// the conjure ladder: base 40 a block of simple elemental material; 80 simple
// objects; 120 complex objects (printed p. 125).
inline int devConjureBaseDifficulty()
    { return 40; }

// the conjure ladder: the doubled difficulty, permanent without Constitution
// loss at 80 or less (printed p. 125).
inline int devConjureDoubleDifficulty()
    { return 80; }

// the conjure ladder: the tripled difficulty (printed p. 125).
inline int devConjureTripleDifficulty()
    { return 120; }

// the summon read: base 50 summons a single creature whose Hit Dice do not
// exceed the caster's level (printed p. 125).
inline int devSummonBaseDifficulty()
    { return 50; }

// the summon read: doubling to 100 doubles the total Hit Dice; tripling to
// 150 triples them (printed p. 125).
inline int devSummonDoubleDifficulty()
    { return 100; }

// the summon read: the tripled difficulty (printed p. 125).
inline int devSummonTripleDifficulty()
    { return 150; }

// the bind read: a binding of a year or more allows a yearly saving throw to
// break it (printed p. 125).
inline bool devBindYearlySave()
    { return true; }

// the bind read: no binding is effective if impossible to honor or suicidal
// (printed p. 125).
inline bool devBindNoSuicide()
    { return true; }

// the summon read: a creature over the caster's level, or specifically named,
// is beyond control though it can be bound, charmed or compelled (printed p.
// 125).
inline bool devSummonNoControlOvernamed()
    { return true; }

// ---- the DMO enchantment-effect pins ----

// the charm read: base 20 inspires a pure emotional state; casting on undead
// triples the difficulty (printed p. 125).
inline int devCharmBaseDifficulty()
    { return 20; }

// the charm read: the tripled undead difficulty (printed p. 125).
inline int devCharmUndeadDifficulty()
    { return 60; }

// the compel read: base 30 forces a single immediate, non-suicidal action of
// one round (printed p. 125).
inline int devCompelBaseDifficulty()
    { return 30; }

// the imbue ladder: base 45 a common non-offensive ability within touch
// (printed p. 126).
inline int devImbueBaseDifficulty()
    { return 45; }

// the imbue ladder: doubling to 90 grants unusual abilities within 30 feet
// (printed p. 126).
inline int devImbueDoubleDifficulty()
    { return 90; }

// the imbue ladder: the 30-foot reach of the doubled form (printed p. 126).
inline int devImbueReachFt()
    { return 30; }

// the imbue transmutation read: lead to copper at base plus a transform, 45 +
// 105 (printed p. 126).
inline int devImbueLeadCopperDifficulty()
    { return 150; }

// the imbue transmutation read: lead into silver doubles the imbue difficulty
// (printed p. 126).
inline int devImbueLeadSilverDifficulty()
    { return 90; }

// the imbue transmutation read: lead into gold triples it (printed p. 126).
inline int devImbueLeadGoldDifficulty()
    { return 135; }

// the imbue transmutation read: wood into gold, a nonmetallic source, costs
// an extra multiple - 285 (printed p. 126).
inline int devImbueWoodGoldDifficulty()
    { return 285; }

// the charm read: golems, automatons and animated objects cannot be charmed
// (printed p. 125).
inline bool devGolemsNeverCharmed()
    { return true; }

// ---- the DMO divination-effect pins ----

// the foresee read: base 25 poses one question; tripling to 75 extends one
// sense into the future (printed p. 126).
inline int devForeseeBaseDifficulty()
    { return 25; }

// the foresee read: the fate-of-a-king example, base 25 plus 100 for an
// unspecified time frame (printed p. 126).
inline int devForeseeKingDifficulty()
    { return 125; }

// the foresee read: the unspecified-time-frame difficulty cost (printed p.
// 126).
inline int devForeseeUnspecifiedCost()
    { return 100; }

// the foresee read: the tripled sense-extension difficulty (printed p. 126).
inline int devForeseeSenseDifficulty()
    { return 75; }

// the reveal ladder: base 20 projects one sense or reads one aura by touch
// (printed p. 126).
inline int devRevealBaseDifficulty()
    { return 20; }

// the reveal ladder: doubling to 40 doubles penetration and analyzes what is
// detected (printed p. 126).
inline int devRevealDoubleDifficulty()
    { return 40; }

// the reveal ladder: tripling to 60 triples penetration and gives complete
// analysis (printed p. 126).
inline int devRevealTripleDifficulty()
    { return 60; }

// the reveal ladder: quintuple difficulty 100 bestows true seeing (printed p.
// 127).
inline int devRevealTrueSeeingDifficulty()
    { return 100; }

// the reveal past read: the past is easier - divide the Table 32 time periods
// by 10; ten years back adds 70 (printed p. 127).
inline int devRevealPastDivisor()
    { return 10; }

// the reveal past read: the ten-year example cost (printed p. 127).
inline int devRevealPastTenYears()
    { return 70; }

// the reveal read: no saving throw unless examining an unwilling creature's
// alignment, thoughts or mental state (printed p. 127).
inline bool devRevealNoSaveUnlessUnwilling()
    { return true; }

// ---- the DMO illusion-effect pins ----

// the conceal read: base 20 hides from one ordinary sense; magical senses
// double the difficulty (printed p. 127).
inline int devConcealBaseDifficulty()
    { return 20; }

// the conceal read: the doubled magical-sense difficulty (printed p. 127).
inline int devConcealMagicalDifficulty()
    { return 40; }

// the delude read: base 30 changes one sensory aspect; doubling to 60
// deceives extraordinary senses such as ESP (printed p. 127).
inline int devDeludeBaseDifficulty()
    { return 30; }

// the delude read: the doubled ESP-deception difficulty (printed p. 127).
inline int devDeludeEspDifficulty()
    { return 60; }

// the delude read: a storm giant seeming a mindless halfling, size change
// plus ESP, a minimum of 150 (printed p. 127).
inline int devDeludeGiantExampleDifficulty()
    { return 150; }

// the phantom read: base 40 impacts one sense; each multiple adds a sense; a
// specific thought or emotion adds 40 (printed p. 127).
inline int devPhantomBaseDifficulty()
    { return 40; }

// the phantom read: the added-thought cost (printed p. 127).
inline int devPhantomMentalCost()
    { return 40; }

// the shadow shape read: disbelieved shapes keep Armor Class 4 and 80 percent
// of hit points and damage (printed p. 127).
inline int devShadowDisbelievedAc()
    { return 4; }

// the shadow shape read: the 80-percent retention (printed p. 127).
inline int devShadowDisbelievedPct()
    { return 80; }

// the shadow shape read: a 50 percent chance special attacks persist after
// the spell fades (printed p. 127).
inline int devShadowSpecialPersistPct()
    { return 50; }

// the conceal read: an attack breaks the concealment unless combined with an
// imbue of the same duration (printed p. 127).
inline bool devConcealBrokenByAttack()
    { return true; }

// the conceal read: true seeing always defeats a conceal spell (printed p.
// 127).
inline bool devTrueSeeingDefeatsConceal()
    { return true; }

// the phantom read: an image cannot inflict real damage even if believed -
// but a mental fear image can kill like a slay spell (printed p. 127).
inline bool devPhantomNoRealDamage()
    { return true; }

// ---- the DMO evocation-effect pins ----

// the create read: base 25 makes a five-foot energy wall, 2d8 damage plus one
// per caster level, 1d8 within 10 feet save for half (printed p. 128).
inline int devEnergyWallDifficulty()
    { return 25; }

// the create read: the 2d8 wall damage (printed p. 128).
inline int devEnergyWallDmgDice()
    { return 2; }

// the create read: the d8 wall die (printed p. 128).
inline int devEnergyWallDmgSize()
    { return 8; }

// the create read: the 1d8 nearby damage, save vs. spells for half (printed
// p. 128).
inline int devEnergyWallNearbyDmg()
    { return 8; }

// the create read: the 10-foot splash radius (printed p. 128).
inline int devEnergyWallNearbyFt()
    { return 10; }

// the create ladder: doubling to 50 makes a soft wall of wood, clay or ice,
// six inches thick (printed p. 128).
inline int devSoftWallDifficulty()
    { return 50; }

// the create ladder: tripling to 75 makes a hard granite or iron wall; a fall
// kills outright (printed p. 129).
inline int devHardWallDifficulty()
    { return 75; }

// the create ladder: quadrupling to 100 duplicates wall of force (printed p.
// 129).
inline int devForceWallDifficulty()
    { return 100; }

// the create read: a soft wall falling inflicts 3d10, save vs. death magic
// (printed p. 129).
inline int devFallingWallDmgDice()
    { return 3; }

// the create read: the 3d10 fall damage (printed p. 129).
inline int devFallingWallDmgSize()
    { return 10; }

// the create ladder: matter at base 35, a 50-pound block; 70 soft compound;
// 105 common pure metal (printed p. 129).
inline int devMatterBlockDifficulty()
    { return 35; }

// the create ladder: the doubled soft-material difficulty (printed p. 129).
inline int devMatterSoftDifficulty()
    { return 70; }

// the create ladder: the tripled pure-metal difficulty (printed p. 129).
inline int devMatterMetalDifficulty()
    { return 105; }

// the strike read: base 25 inflicts 2d8 plus one per caster level by touch or
// burst, save vs. spell for half (printed p. 129).
inline int devStrikeBaseDifficulty()
    { return 25; }

// the strike read: the 2d8 base damage (printed p. 129).
inline int devStrikeDmgDice()
    { return 2; }

// the strike read: +1d8 per five added difficulty, to a maximum of 30d8
// (printed p. 129).
inline int devStrikeMaxDice()
    { return 30; }

// the strike read: the five-point step per extra die (printed p. 129).
inline int devStrikeStepPerFive()
    { return 5; }

// the strike read: an animated strike-wall effect has Armor Class 0 and the
// caster's hit points (printed p. 129).
inline int devMobileSpellAc()
    { return 0; }

// the strike read: the crushing-hand combination has Armor Class -2 and twice
// the caster's hit points (printed p. 129).
inline int devCrushingSpellAc()
    { return -2; }

// the strike read: the doubled hit points (printed p. 129).
inline int devCrushingSpellHpMult()
    { return 2; }

// the create read: matter-producing creation can be made permanent without a
// Constitution loss (printed p. 129).
inline bool devMatterPermanentFree()
    { return true; }

// the strike read: the mobile effect is harmed only by magic and is immune to
// its own form of energy (printed p. 129).
inline bool devForceImmuneToOwnEnergy()
    { return true; }

// ---- the DMO necromancy-effect pins ----

// the animate dead read: base 25 animates one Hit Die of skeletons or zombies
// per caster level (printed p. 129).
inline int devAnimateDeadBaseDifficulty()
    { return 25; }

// the animate dead read: doubling to 50 doubles the Hit Dice, tripling to 75
// triples them (printed p. 129).
inline int devAnimateDeadDoubleDifficulty()
    { return 50; }

// the animate dead read: the tripled difficulty (printed p. 129).
inline int devAnimateDeadTripleDifficulty()
    { return 75; }

// the animate dead read: scattered remains add 25; scattered and ancient add
// 75 (printed p. 129).
inline int devAnimateScatteredAdj()
    { return 25; }

// the animate dead read: the scattered-and-ancient adjustment (printed p.
// 129).
inline int devAnimateScatteredAncientAdj()
    { return 75; }

// the slay read: base 50 slays one creature of the caster's Hit Dice or less;
// +5 difficulty per extra Hit Die, no maximum (printed p. 129).
inline int devSlayBaseDifficulty()
    { return 50; }

// the slay read: one Hit Die per five points of added difficulty (printed p.
// 129).
inline int devSlayHdPerFive()
    { return 1; }

// the slay read: targets of 9 Hit Dice or more save vs. death to negate
// (printed p. 129).
inline int devSlaySaveHdMin()
    { return 9; }

// the tap read: base 40 drains 1d8 hit points by touch, save vs. spells at 9
// Hit Dice or more; +5 per extra die, max 30d8 (printed p. 129).
inline int devTapBaseDifficulty()
    { return 40; }

// the tap read: the d8 tap die (printed p. 129).
inline int devTapDmgDie()
    { return 8; }

// the tap read: the 30d8 maximum (printed p. 129).
inline int devTapMaxDice()
    { return 30; }

// the tap read: doubling to 80 transfers drained hit points - or one ability
// score point - to the caster for the duration (printed p. 130).
inline int devTapTransferDifficulty()
    { return 80; }

// the tap read: at 160 the stolen ability score transfers to the caster
// (printed p. 130).
inline int devTapAbilityTransferDifficulty()
    { return 160; }

// the tap read: tripling to 120 drains one energy level for the duration; at
// 240 it transfers (printed p. 130).
inline int devTapLevelDifficulty()
    { return 120; }

// the tap read: the level-transfer difficulty (printed p. 130).
inline int devTapLevelTransferDifficulty()
    { return 240; }

// the tap read: priests, and only priests, use the tap spell to heal injuries
// (printed p. 129).
inline bool devOnlyPriestsHealWithTap()
    { return true; }

// the tap read: a damage-inflicting tap is always instantaneous and cannot be
// extended (printed p. 129).
inline bool devTapDamageInstantOnly()
    { return true; }

// ---- the DMO preparation-and-casting pins ----

// the preparation day: preparations of a day or more require eight hours of
// effort per day, the remaining 16 free (printed p. 133).
inline int devPrepHoursPerDay()
    { return 8; }

// the Pharjis read: a 25th-level diviner throughout (printed pp. 133-134).
inline int devPharjisLevel()
    { return 25; }

// the Pharjis read: difficulty 15 requires a week of preparation (printed p.
// 133).
inline int devPharjisDiff15PrepWeeks()
    { return 1; }

// the Pharjis read: the day-four explosion loses that day plus a backtrack
// day - five more days to cast (printed p. 133).
inline int devPharjisExplosionLostDays()
    { return 2; }

// the Pharjis read: difficulty 55 requires two months of preparation (printed
// p. 133).
inline int devPharjisDiff55PrepMonths()
    { return 2; }

// the final check: roll 1d20 - no, 1d100; equal or higher than the final
// difficulty completes the preparations (printed p. 133).
inline int devFinalCheckDie()
    { return 100; }

// the Pharjis read: six months of preparation reduce difficulty 55 to 28,
// fractions rounded up (printed p. 133).
inline int devPharjisDiff55Final()
    { return 28; }

// the Pharjis read: one day of preparation raises difficulty 15 to 30
// (printed p. 133).
inline int devPharjisDiff15Shortened()
    { return 30; }

// the Pharjis read: difficulty 160 halved by two years of preparation to 80
// (printed p. 134).
inline int devPharjisDiff160Final()
    { return 80; }

// the hold rule: a prepared spell can be held only as long as its minimum
// preparation time - Pharjis waits up to a year (printed p. 134).
inline int devHoldTimeCap()
    { return 1; }

// the disruption rule: preparations of a day or less are completely disrupted
// and restart (printed p. 133).
inline bool devPrepDayRestart()
    { return true; }

// the disruption rule: week-or-longer preparations lose the current day plus
// another day of backtracking (printed p. 133).
inline bool devPrepWeekBacktrack()
    { return true; }

// the time trade: raising preparation one category halves the final
// difficulty or takes -10, whichever is greater; shortening doubles it
// (printed p. 133).
inline bool devPrepExtensionHalves()
    { return true; }

// the casting read: day-or-longer casting needs eight hours daily,
// consecutive; a missed day loses the spell (printed p. 134).
inline bool devCastDailyNoBreaks()
    { return true; }

// the casting read: broken concentration during casting ruins the spell and
// consumes the components in a fizzle (printed p. 133).
inline bool devCastBrokenRuinsSpell()
    { return true; }

// ---- the DMO worked-creation pins ----

// the Pharjis example: the reveal type at base 20, region area +80, half-day
// duration +10 - a combined 110 (printed p. 134).
inline int devExRevealBase()
    { return 20; }

// the Pharjis example: the 100-mile region area modifier (printed p. 134).
inline int devExRegionAdj()
    { return 80; }

// the Pharjis example: the half-day duration modifier, six hours on Table 32
// (printed p. 134).
inline int devExHalfDayAdj()
    { return 10; }

// the Pharjis example: 20 + 80 + 10 = 110 (printed p. 134).
inline int devExCombinedDifficulty()
    { return 110; }

// the Pharjis example: 110 - 25 level - 5 diviner - 10 practiced = 70
// (printed p. 134).
inline int devExAdjustedDifficulty()
    { return 70; }

// the Pharjis example: the giant-eagle feather halves 70 to 35 (printed p.
// 134).
inline int devExExoticHalved()
    { return 35; }

// the Pharjis example: three rare components - spyglass, spectacles, map -
// reduce 35 to 5 (printed p. 134).
inline int devExRareReduced()
    { return 5; }

// the Pharjis example: halving the preparation to a round doubles the final
// difficulty to 10 (printed p. 134).
inline int devExDoubledFinal()
    { return 10; }

// the Pharjis example: the first final check rolls 02, a failure (printed p.
// 134).
inline int devExFailRoll()
    { return 2; }

// the Pharjis example: the second check rolls 81, a success (printed p. 134).
inline int devExSuccessRoll()
    { return 81; }

// the Pharjis example: he searches the region for 12 hours (printed p. 134).
inline int devExWatchHours()
    { return 12; }

// ---- the DMO dweomers-in-play pins ----

// the in-play read: a 3rd-level dispel magic directed solely at the dweomer
// suppresses it for 1d4 rounds (printed p. 134).
inline int devDispelMagicSuppressRounds()
    { return 4; }

// the in-play read: Mordenkainen's disjunction has a 1-percent chance per
// caster level of disjoining a true dweomer, wholly if any portion (printed
// p. 135).
inline int devDisjunctionPctPerLevel()
    { return 1; }

// the in-play read: the 1d8-hour negation (printed p. 135).
inline int devLimitedWishHours()
    { return 8; }

// the duel read: all true dweomers have power ranks of 19 and move by range;
// each preparation or casting round costs a duel round (printed p. 135).
inline int devDuelPR()
    { return 19; }

// the quest read: a ward grants a saving throw of 18 against a quest spell
// that allows none; a ward's magic resistance is halved (printed p. 136).
inline int devQuestWardSaveFloor()
    { return 18; }

// the in-play read: the saving-throws-by-character-level optional rule is
// always used, and high-ability bonuses apply normally (printed p. 134).
inline bool devPlayCasterLevelSaves()
    { return true; }

// the in-play read: pale lavender and lavender-and-green ioun stones, rods of
// absorption and staffs of the magi absorption are ineffective against true
// dweomers (printed p. 134).
inline bool devIounStonesIneffective()
    { return true; }

// the in-play read: dispel magic cannot disrupt a dweomer whose area exceeds
// its own (printed p. 134).
inline bool devDispelMagicAreaCapped()
    { return true; }

// the in-play read: a wish automatically dispels a true dweomer, its only
// effect; a limited wish negates for 1d8 hours (printed p. 135).
inline bool devWishAutoDispels()
    { return true; }

// the barrier read: a dispel true dweomer instantly destroys any wall or
// barrier from a 1st-9th level spell or device - wall of force, prismatic
// wall and sphere, antimagic shell, cube of force (printed p. 135).
inline bool devDispelDestroysBarriers()
    { return true; }

// the barrier read: flat barriers are circumvented by a big enough area,
// spherical ones cannot be (printed p. 135).
inline bool devSphericalBarriersHold()
    { return true; }

// the duel read: any dweomer with a casting time over one round is useless as
// a counter spell (printed p. 135).
inline bool devDuelCountersUseless()
    { return true; }

// the quest read: quest-spell effects generally cannot be countered; a dispel
// dweomer is ineffective, though creatures and wardable effects can be
// attacked (printed p. 135).
inline bool devQuestSpellsUncounterable()
    { return true; }

// the quest read: the halved magic resistance (printed p. 136).
inline bool devQuestWardMrHalved()
    { return true; }

// ---- the DMO known-dweomer pins ----

// the canonical list: thirteen documented true dweomers from Hurd's
// Obligation through Yunni's Herald (printed pp. 136-141).
inline int devKnownDweomerCount()
    { return 13; }

// Hurd's Obligation: a bind of conditional duration, saving throw negates at
// an -8 penalty; only a 10th-level dispel removes it (printed p. 136).
inline int devHurdSavePenalty()
    { return -8; }

// Kolin's Undead Legion: animates 200 Hit Dice of skeletons or zombies
// anywhere on the plane, 5,000 feet square (printed p. 136).
inline int devKolinUndeadHd()
    { return 200; }

// Kreb's Flaming Dragon: a disbelieved shadow dragon keeps Armor Class 4 and
// 80 percent, and its non-damaging powers have a 20 percent chance to fail
// (printed p. 137).
inline int devKrebDragonFailPct()
    { return 20; }

// Nazzer's Nullification: the 10th-level dispel magic, difficulty 55 with a
// final of -5; the cloak version runs 90 to 13 (printed p. 137).
inline int devNazzerBaseDiff()
    { return 55; }

// Nazzer's Nullification cloak: the second version, difficulty 90, final 13
// (printed p. 137).
inline int devNazzerCloakDiff()
    { return 90; }

// Nazzer's Nullification cloak: the final difficulty 13 (printed p. 137).
inline int devNazzerCloakFinal()
    { return 13; }

// Nazzer's Nullification: most standard items resist at an effective 12th
// level; artifacts are immune (printed p. 138).
inline int devNazzerItemLevel()
    { return 12; }

// Nazzer's Nullification cloak: operates one full turn - ten rounds -
// disrupting all entering magic; a resisting spell is immune for the
// remainder (printed p. 138).
inline int devNazzerCloakRounds()
    { return 10; }

// Neja's Irresistible Plea: compels a task of 12 hours or less, saving throw
// negates at -3 (printed p. 138).
inline int devNejaPleaHours()
    { return 12; }

// Neja's Irresistible Plea: the -3 saving throw modifier (printed p. 138).
inline int devNejaPleaSaveBonus()
    { return -3; }

// Ratecliffe's Deadly Finger: slays 40 Hit Dice of creatures in a 50-foot
// square; those under 9 Hit Dice get no save (printed p. 140).
inline int devRatecliffeHd()
    { return 40; }

// Ratecliffe's Deadly Finger: the 50-foot square (printed p. 140).
inline int devRatecliffeAreaFt()
    { return 50; }

// Tenser's Telling Blow: a force blast of 20d8 + 20 points of damage, save
// for half; only against creatures already engaged in combat (printed p.
// 140).
inline int devTenserDmgDice()
    { return 20; }

// Tenser's Telling Blow: the +20 bonus damage (printed p. 140).
inline int devTenserDmgBonus()
    { return 20; }

// Wulf's Rectification: banishes 1d4+1 extra-planar usurpers in a 50-foot
// diameter, magic resistance at -20 percent (printed p. 141).
inline int devWulfRectAreaDia()
    { return 50; }

// Wulf's Rectification: the -20 percent magic resistance penalty (printed p.
// 141).
inline int devWulfRectMrPenalty()
    { return -20; }

// Yunni's Herald: animates objects of 50 pounds or less, moving at speed 12
// to deliver a spoken message for up to a week (printed p. 141).
inline int devYunniWeightLbs()
    { return 50; }

// the Table 28 grid: 29 spell types across the eight schools, abjuration
// through necromancy (printed p. 120).
inline int devT28RowCount()
    { return 29; }

// the Table 29 grid: ten area-of-effect rows from a single creature to a
// whole plane (printed p. 130).
inline int devT29RowCount()
    { return 10; }

// the Table 30 grid: six animated-object size rows, tiny through gargantuan
// (printed p. 130).
inline int devT30RowCount()
    { return 6; }

// the Table 31 grid: ten range rows, touch through trans-planar (printed p.
// 131).
inline int devT31RowCount()
    { return 10; }

// the Table 32 grid: eleven duration rows, instantaneous through permanent
// (printed p. 131).
inline int devT32RowCount()
    { return 11; }

// the Table 33 grid: ten adjusted-difficulty bands from -1-or-less through
// 151-plus (printed p. 132).
inline int devT33RowCount()
    { return 10; }

// the Table 35 grid: the 29 dweomer types mapped to their dueling types
// (printed p. 135).
inline int devT35RowCount()
    { return 29; }

// the area codes: a province is 20 miles square, a region 100 miles square, a
// plane fills the plane (printed p. 130).
inline int devProvinceMiles()
    { return 20; }

// the area codes: the region dimension (printed p. 130).
inline int devRegionMiles()
    { return 100; }

// the area read: affecting all creatures in a designated area multiplies the
// difficulty modifier by 10 (printed p. 130).
inline int devAreaAllCreaturesMult()
    { return 10; }

// Nazzer's Nullification: a roll of 1 always fails and a 20 always succeeds
// (printed p. 138).
inline bool devNazzerAutoFailOne()
    { return true; }

// Neja's Toadstool: Nazzer's nullification can reverse the transform, but a
// system shock roll is required with failure meaning death (printed p. 138).
inline bool devNejaToadstoolSystemShock()
    { return true; }

// Ratecliffe's Deadly Finger: the slain revive only by a wish, another true
// dweomer or a deity (printed p. 140).
inline bool devRatecliffeWishOnlyRevival()
    { return true; }

// the base difficulty by type: banish 30, dispel 30, reflect 25, ward 35; the
// alteration ladder 25 through 45; the conjuration 35 through 50; enchantment
// 20 through 45; divination 20 and 25; illusion 20 through 40; evocation 25
// through 45; necromancy 25 through 50; the shadow shape is variable (printed
// p. 120).
inline int devT28BaseDiff(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 30;
        case 2:
            return 25;
        case 3:
            return 35;
        case 4:
            return 25;
        case 5:
            return 45;
        case 6:
            return 30;
        case 7:
            return 35;
        case 8:
            return 35;
        case 9:
            return 40;
        case 10:
            return 35;
        case 11:
            return 40;
        case 12:
            return 50;
        case 13:
            return 20;
        case 14:
            return 30;
        case 15:
            return 30;
        case 16:
            return 45;
        case 17:
            return 25;
        case 18:
            return 20;
        case 19:
            return 20;
        case 20:
            return 30;
        case 21:
            return -99;
        case 22:
            return 40;
        case 23:
            return 35;
        case 24:
            return 45;
        case 25:
            return 25;
        case 26:
            return 25;
        case 27:
            return 50;
        case 28:
            return 40;
        default:
            return -99;
        }
    }

// the base duration code: 0 instantaneous, 1 one round, 2 round or
// instantaneous by use, -99 the variable shadow shape (printed p. 120).
inline int devT28BaseDuration(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return -99;
        case 22:
            return 1;
        case 23:
            return 2;
        case 24:
            return 1;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        default:
            return -99;
        }
    }

// the effect code: 0 area, 1 creature or object, 2 object, 3 creature or
// area, 4 creature, -99 variable (printed p. 120).
inline int devT28EffectCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 2;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return -99;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 4;
        case 28:
            return 4;
        default:
            return -99;
        }
    }

// the creature count: 1, 3, 6, 9, 12, 15, 18, 21, 24, 27 - the fixed
// parenthetical numbers of the dice entries (printed p. 130).
inline int devT29Creatures(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 9;
        case 4:
            return 12;
        case 5:
            return 15;
        case 6:
            return 18;
        case 7:
            return 21;
        case 8:
            return 24;
        case 9:
            return 27;
        default:
            return -99;
        }
    }

// the area in feet: 5, 50, 500, 5,000, 10,000, 25,000, 50,000, then province,
// region and plane - a province 20 miles square, a region 100 (printed p.
// 130).
inline int devT29AreaFt(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 50;
        case 2:
            return 500;
        case 3:
            return 5000;
        case 4:
            return 10000;
        case 5:
            return 25000;
        case 6:
            return 50000;
        case 7:
            return -99;
        case 8:
            return -99;
        case 9:
            return -99;
        default:
            return -99;
        }
    }

// the object weight cap in pounds: 200 through one million, a 500-ton plane
// row (printed p. 130).
inline int devT29ObjectLbs(int b)
    {
        switch (b) {
        case 0:
            return 200;
        case 1:
            return 500;
        case 2:
            return 1000;
        case 3:
            return 2000;
        case 4:
            return 10000;
        case 5:
            return 20000;
        case 6:
            return 100000;
        case 7:
            return 200000;
        case 8:
            return 400000;
        case 9:
            return 1000000;
        default:
            return -99;
        }
    }

// the difficulty modifier: 0, 5, 10, 15, 20, 25, 30, 40, 80, 160 (printed p.
// 130).
inline int devT29Difficulty(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 20;
        case 5:
            return 25;
        case 6:
            return 30;
        case 7:
            return 40;
        case 8:
            return 80;
        case 9:
            return 160;
        default:
            return -99;
        }
    }

// the weight cap in pounds: 50, 100, 200, 500, 1,000 and a one-ton gargantuan
// row (printed p. 130).
inline int devT30WeightLbs(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 100;
        case 2:
            return 200;
        case 3:
            return 500;
        case 4:
            return 1000;
        case 5:
            return 2000;
        default:
            return -99;
        }
    }

// the average damage per blow: 2, 5, 10, 15, 20, 25 (printed p. 130).
inline int devT30Damage(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 20;
        case 5:
            return 25;
        default:
            return -99;
        }
    }

// the range difficulty: touch 0, 20 yards 5, 50 yards 10, 100 yards 15, 500
// yards 20, 1,000 yards 25, 1,500 yards 30, line of sight 40, plane 60,
// trans-planar 100 (printed p. 131).
inline int devT31Difficulty(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 20;
        case 5:
            return 25;
        case 6:
            return 30;
        case 7:
            return 40;
        case 8:
            return 60;
        case 9:
            return 100;
        default:
            return -99;
        }
    }

// the duration difficulty: instantaneous 0, one round 1, one turn 3, one hour
// 5, six hours 7, 12 hours 10, one day 15, one week 30, one month 50, one
// year 70, permanent 100 (printed p. 131).
inline int devT32Difficulty(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 7;
        case 5:
            return 10;
        case 6:
            return 15;
        case 7:
            return 30;
        case 8:
            return 50;
        case 9:
            return 70;
        case 10:
            return 100;
        default:
            return -99;
        }
    }

// the preparation time code: none at -1 or less, round at 0, turn through 5,
// day 6-10, week 11-20, two weeks 21-30, month 31-50, two months 51-100, six
// months 101-150, year at 151-plus (printed p. 132).
inline int devT33PrepCode(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        default:
            return -99;
        }
    }

// the casting time code: round through 10, turn 11-20, hour 21-50, day
// 51-150, week at 151-plus (printed p. 132).
inline int devT33CastCode(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        default:
            return -99;
        }
    }

// the dueling type code: banish attack, dispel attack/defense, reflect and
// ward defense; alteration animate attack/defense, destroy fortify transport
// leeches, transform attack; conjures attack or leech, summon attack/defense;
// the enchantments attack or leech; divinations leech; conceal delude leech,
// phantom any, shadow shape attack/defense-or-missile; create attack/defense,
// strike missile; necromancy animate attack/defense, tap and slay attack
// (printed p. 135).
inline int devT35DuelType(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 5;
        case 22:
            return 6;
        case 23:
            return 2;
        case 24:
            return 3;
        case 25:
            return 4;
        case 26:
            return 2;
        case 27:
            return 0;
        case 28:
            return 0;
        default:
            return -99;
        }
    }

// the difficulty before reductions: 180, 325, 65, 120, 55, 60, 120, 220, 190,
// 160, 85, 155, 140 (printed pp. 136-141).
inline int devKnownDifficulty(int b)
    {
        switch (b) {
        case 0:
            return 180;
        case 1:
            return 325;
        case 2:
            return 65;
        case 3:
            return 120;
        case 4:
            return 55;
        case 5:
            return 60;
        case 6:
            return 120;
        case 7:
            return 220;
        case 8:
            return 190;
        case 9:
            return 160;
        case 10:
            return 85;
        case 11:
            return 155;
        case 12:
            return 140;
        default:
            return -99;
        }
    }

// the final difficulty: 45, 45, 5, 5, -5, 0, 3, 3, 0, -7, 8, 2, -2 - Nazzer's
// base version; the cloak runs 13 (printed pp. 136-141).
inline int devKnownFinal(int b)
    {
        switch (b) {
        case 0:
            return 45;
        case 1:
            return 45;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return -5;
        case 5:
            return 0;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return -7;
        case 10:
            return 8;
        case 11:
            return 2;
        case 12:
            return -2;
        default:
            return -99;
        }
    }

}   // namespace rules
