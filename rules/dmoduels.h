// =========================================================================================
// Adnd1 - rules/dmoduels.h
// MAGICAL DUELS - DMO Chapter 5 closes: the arena protocol (the one-turn
// circling chant, the restart on disturbance, the mediator's protective
// spell, the contributed memorized spells lost as cast, the secret recording,
// the compulsion and threat consent doctrine), the balance-of-power cap at
// the weaker level, the corridor geometry (a 12-to-30-space corridor, ten
// base spaces plus each side's highest contribution, thirty at most between,
// thirty-two at largest), the four-step round with the advantage doctrine
// (the highest single spell, the 1d10 tie, the shift on destruction), the
// five-type doctrine with PR = level + nine, the Table 25 interactions grid
// and Table 26 movement bands, the 1d20-vs-PR combat with the lock rules and
// the Rary-Serten reads, the character power scores of Table 27 with the
// counter-spell doctrine and the 1d6-or-1d4-push personal combat, the item
// rules (the scroll of protection at PR 15 MV 1, the 6d6, 8d6 and 9d6 item
// leech caps, the 14 protection read, the absolute arena blockers), the
// specialist gates with the opposition-school +1, the friendly, death and
// service stakes ladders (the death bands running 2d6 to 10d6 damage with the
// 20 and 40 percent plane blows and the 50 percent disintegration), the
// mediator duties, the special dueling characteristics (the mental,
// summoning, illusion, reversible and teleportation groups, the demishadow
// and shadow magic reads, the earthquake counters, the wish reads), and the
// Calvin-and-Delsenora worked duel at ten spaces.
// census 528 -> 529.
//
// verified against printed pp. 96-117 of the uploaded DMO session capture
// (part 2, printed page N at OCR page N+90); the arena protocol from pp.
// 96-97, the corridor and combat rules from pp. 97-101, Tables 25 and 26 from
// p. 99, Table 27 from p. 101, the character rules from pp. 103-104, the item
// and specialist rules from pp. 104-105, the stakes ladders from pp. 105-107,
// the special characteristics from pp. 108-116, the worked duel from pp.
// 116-117. The death ladder prints an 18-22 band after the 13-18 band,
// overlapping at 18; both bands are pinned verbatim in row order with the
// note here.
//
// the gap census after this round: 69 closed, 27 open - Chapter 5 is DONE in
// one round, seventeen boxes flip (sixteen children and the parent); the DMO
// arc continues with Chapter 6 (True Dweomers, pp. 118-141).
//
namespace rules {

// ---- the DMO arena-creation pins ----

// the arena protocol: the opponents stand at arm's length and circle each
// other chanting and gesturing for a full turn (printed p. 96).
inline int detArenaChantTurns()
    { return 1; }

// the balance example: Calvin the 7th-level wizard dueling Delsenora the
// 12th-level priest (printed p. 97).
inline int detBalanceExampleWizardLevel()
    { return 7; }

// the balance example: the 12th-level priest (printed p. 97).
inline int detBalanceExamplePriestLevel()
    { return 12; }

// the balance example: neither could contribute a spell higher than 7th level
// or spells totaling seven levels (printed p. 97).
inline int detBalanceExampleCapLevel()
    { return 7; }

// the corridor geometry: the arena is a rectangle 12 to 30 spaces long and
// one space wide (printed p. 97).
inline int detArenaCorridorMinSpaces()
    { return 12; }

// the corridor geometry: never more than 30 spaces between the opponents
// (printed p. 97).
inline int detArenaCorridorMaxSpaces()
    { return 30; }

// the distance base: if neither opponent contributed a spell there are 10
// intervening spaces (printed p. 97).
inline int detArenaBaseSpaces()
    { return 10; }

// the distance cap: there are never more than 30 spaces between the opponents
// (printed p. 97).
inline int detArenaMaxIntervening()
    { return 30; }

// the largest arena: 32 spaces total, each combatant occupying one end space,
// 30 between (printed p. 97).
inline int detArenaLargestTotal()
    { return 32; }

// the distance example: a 5th-level plus a 3rd-level contribution makes 18
// spaces (printed p. 97).
inline int detArenaExampleSpaces()
    { return 18; }

// the distance example: the first opponent's highest contributed spell, level
// 5 (printed p. 97).
inline int detArenaExampleSpellA()
    { return 5; }

// the distance example: the second opponent's highest, level 3 (printed p.
// 97).
inline int detArenaExampleSpellB()
    { return 3; }

// the round sequence: the advantaged spells move, the disadvantaged spells
// move, both cast, repeat (printed p. 98).
inline int detRoundSteps()
    { return 4; }

// the advantage tie: with no contributions or an equal highest, each opponent
// rolls 1d10, high roll wins the advantage (printed p. 97).
inline int detTieAdvantageDie()
    { return 10; }

// the restart rule: if the combatants' concentration is disturbed before the
// arena is complete, the preparations begin again (printed p. 96).
inline bool detArenaRestartOnDisturbance()
    { return true; }

// the mediator's spell: the mediator casts a protective spell over the
// combatants, wall of force the usual choice (printed p. 96).
inline bool detMediatorProtectiveRequired()
    { return true; }

// the contribution rule: contributed spells need not be protective but must
// be currently memorized (printed p. 96).
inline bool detContributedMustBeMemorized()
    { return true; }

// the contribution cost: a contributed spell disappears from memory as though
// cast, with no normal effect (printed p. 96).
inline bool detContributedLostAsCast()
    { return true; }

// the secrecy: contributed spells are recorded secretly; the opponent cannot
// tell how many or how long (printed p. 97).
inline bool detContributionSecret()
    { return true; }

// the mediator's sight: the mediator is aware of the spells contributed by
// both sides (printed p. 97).
inline bool detMediatorKnowsAll()
    { return true; }

// the compulsion bar: a character under magical or psionic compulsion such as
// charm person or suggestion cannot be forced to consent (printed p. 97).
inline bool detCharmCannotConsent()
    { return true; }

// the threat read: consent under threat is still consent as long as the
// character is free to think (printed p. 97).
inline bool detThreatConsentValid()
    { return true; }

// the geas read: a geas or quest subject is free to ignore the request and
// face the consequences (printed p. 97).
inline bool detGeasSubjectFreeToRefuse()
    { return true; }

// the balance-of-power cap: when levels differ, the spell levels each side
// contributes cannot exceed the weaker opponent's level (printed p. 97).
inline bool detBalanceCapWeakerLevel()
    { return true; }

// the geometry note: the duelists' own spaces do not count in the corridor
// length (printed p. 97).
inline bool detDuelistSpacesNotCounted()
    { return true; }

// the distance rule: only the single highest-level spell contributed by each
// side is factored (printed p. 97).
inline bool detOnlyHighestFactored()
    { return true; }

// the opening round: no spell movement because there are no spells in the
// arena (printed p. 98).
inline bool detFirstRoundNoMovement()
    { return true; }

// the movement order: all the advantaged caster's spells move first even if
// combat shifts the advantage mid-move (printed p. 100).
inline bool detAdvantageMovesFirst()
    { return true; }

// the advantage rule: the advantage goes to whoever contributed the highest
// single-level spell, not the highest combined (printed p. 97).
inline bool detAdvantageHighestSingleSpell()
    { return true; }

// the shift rule: the advantage shifts when a spell is destroyed in spell
// combat, to the victor's caster (printed p. 97).
inline bool detAdvantageShiftsOnSpellDeath()
    { return true; }

// the shift exception: no shift when a character defeats a spell by power
// rating or saving throw (printed pp. 97-98).
inline bool detNoShiftOnSaveOrPR()
    { return true; }

// ---- the DMO duel-type doctrine pins ----

// the dueling types: attack, defense, attack/defense, leech and missile
// (printed p. 99).
inline int detSpellTypes()
    { return 5; }

// the power rank: a spell's PR is its level plus nine (printed p. 100).
inline int detPRBase()
    { return 9; }

// the PR example: a fireball, 3rd level, PR 12 (printed p. 100).
inline int detFireballPR()
    { return 12; }

// the leech strike: a leech reaching the opponent's square inflicts 1d6
// points of damage per spell level (printed p. 99).
inline int detLeechDmgDie()
    { return 6; }

// the leech strike: one die per spell level (printed p. 99).
inline int detLeechDmgPerLevel()
    { return 1; }

// the AD strike: an attack/defense spell reaching the opponent usually
// inflicts 1d6 points of damage per spell level (printed p. 100).
inline int detADDmgDie()
    { return 6; }

// the AD strike: one die per spell level (printed p. 100).
inline int detADDmgPerLevel()
    { return 1; }

// the movement ladder: touch, zero-range and sub-yard spells move one space
// (printed p. 99).
inline int detMvTouch()
    { return 1; }

// the movement ladder: 1-20 yard ranges move two spaces (printed p. 99).
inline int detMvShort()
    { return 2; }

// the movement ladder: 21-50 yard ranges move three spaces (printed p. 99).
inline int detMvMedium()
    { return 3; }

// the movement ladder: 51-100 yard ranges move four spaces (printed p. 99).
inline int detMvLong()
    { return 4; }

// the movement ladder: 101-plus yard ranges, instantaneous movement and huge
// areas move five spaces (printed p. 99).
inline int detMvVeryLong()
    { return 5; }

// the level-varied range: a 5th-level wizard's fireball at 60 yards moves
// four (printed p. 99).
inline int detFireball5thMv()
    { return 4; }

// the level-varied range: a 15th-level wizard's fireball at 160 yards moves
// five (printed p. 99).
inline int detFireball15thMv()
    { return 5; }

// the defensive exception: only one such spell can remain with the caster at
// a time (printed p. 100).
inline int detOnlyOneDefensiveStay()
    { return 1; }

// the arena seal: a spell never leaves the arena or affects creatures outside
// (printed p. 98).
inline bool detSpellNeverLeavesArena()
    { return true; }

// the no-self rule: combatants are constructs in the arena - no casting on
// oneself; a cure heals nothing, a teleport goes nowhere (printed p. 98).
inline bool detNoSelfCasting()
    { return true; }

// the construct doctrine: spells restrict the opponent's actions until thrown
// off, never controlling or imprisoning him directly (printed p. 98).
inline bool detSpellsAffectConstructs()
    { return true; }

// the identification: spells are not readily identifiable; detect magic and
// the spellcraft proficiency can identify them (printed p. 98).
inline bool detDetectIdentifies()
    { return true; }

// the defensive exception: a defensive spell may remain in the caster's space
// instead of crossing (printed p. 100).
inline bool detDefensiveMayStay()
    { return true; }

// the movement floor: most spells must move at least one space every round
// unless locked in combat (printed p. 100).
inline bool detMustMoveOneSpace()
    { return true; }

// the dueling cast: all spellcasting during a duel is simultaneous (printed
// p. 100).
inline bool detCastingSimultaneous()
    { return true; }

// the dueling cast: spells cannot be disrupted as in a normal encounter
// (printed p. 100).
inline bool detCastingNotDisrupted()
    { return true; }

// the component supply: no additional components required - pyrotechnics
// works in an arena with no fire source (printed p. 100).
inline bool detArenaSuppliesComponents()
    { return true; }

// the cast placement: a spell appears in the space immediately ahead of the
// caster, or in the caster's space if defensive (printed p. 100).
inline bool detSpellAppearsAhead()
    { return true; }

// the cast placement: no spell moves on the round it is cast (printed p.
// 100).
inline bool detNoMoveOnCastRound()
    { return true; }

// the attack doctrine: an attack spell must conduct combat with any opposing
// defensive spell it meets, may fight leeches at the advantaged caster's
// choice, ignores missiles and attacks (printed p. 99).
inline bool detAttackMustFightDefense()
    { return true; }

// the defense doctrine: a defensive spell must fight opposing attacks, may
// fight leeches, generally ignores missiles, always ignores other defenses,
// and vanishes at the opponent's square (printed p. 99).
inline bool detDefenseMustFightAttack()
    { return true; }

// the leech doctrine: a leech must fight opposing leeches, may fight attacks
// or defenses, ignores missiles (printed p. 99).
inline bool detLeechMustFightLeech()
    { return true; }

// the leech strike: saving throw vs. spell reduces the damage by half
// (printed p. 99).
inline bool detLeechSaveHalf()
    { return true; }

// the attack/defense doctrine: an AD spell must fight opposing defensive and
// attack spells, may fight leeches or missiles at the advantaged caster's
// choice (printed p. 100).
inline bool detADMustFightAD()
    { return true; }

// the AD strike: the opponent saves vs. spell or makes a spell combat roll to
// avoid the damage (printed p. 100).
inline bool detADSaveOrCombat()
    { return true; }

// the missile doctrine: a missile may fight attack/defense spells, ignores
// missiles, leeches, attacks and most defenses (printed p. 100).
inline bool detMissileIgnoresMost()
    { return true; }

// ---- the DMO spell-combat pins ----

// the spell combat roll: each player rolls 1d20 against the spell's power
// rank (printed p. 100).
inline int detCombatDie()
    { return 20; }

// the Rary-Serten read: charm person, an attack spell with PR 10 (printed p.
// 101).
inline int detRaryCharmPR()
    { return 10; }

// the Rary-Serten read: cure light wounds, a defense spell with PR 10
// (printed p. 101).
inline int detSertenCurePR()
    { return 10; }

// the Rary-Serten read: Rary rolls 12, Serten 1 - the charm fails, the cure
// succeeds (printed p. 101).
inline int detRaryRoll()
    { return 12; }

// the Rary-Serten read: Serten's 1 (printed p. 101).
inline int detSertenRoll()
    { return 1; }

// the Rary-Serten alternate: with a 9 the charm would destroy the cure,
// succeeding with a higher roll (printed p. 101).
inline int detRaryAltRoll()
    { return 9; }

// the lock read: Serten 20 against Rary 12, or both rolling 10 - a lock
// (printed p. 101).
inline int detLockExampleRaryRoll()
    { return 20; }

// the movement order: the spell closest to the opponent always moves first,
// then the next, and so on (printed p. 100).
inline bool detMoveOrderClosestFirst()
    { return true; }

// the friendly stack: one character's spells freely move through each other
// or share a space; the fastest moves first when stacked (printed p. 100).
inline bool detFriendlyStackingOk()
    { return true; }

// the one-way rule: spells never move backward unless forced by an opposing
// spell's special ability (printed p. 100).
inline bool detNoBackwardMove()
    { return true; }

// the combat read: a roll higher than the power rank fails, equal or less
// succeeds (printed p. 100).
inline bool detFailIfHigher()
    { return true; }

// the lock: both spells failing locks them in place (printed p. 101).
inline bool detLockOnBothFail()
    { return true; }

// the lock: two spells with the same power scores tying each other also locks
// (printed p. 101).
inline bool detLockOnEqualPRTie()
    { return true; }

// the double success: with both succeeding, the higher roll destroys the
// lower (printed p. 101).
inline bool detHigherRollWins()
    { return true; }

// the victory move: a winning spell that was moving may finish its move after
// the battle (printed p. 101).
inline bool detWinningSpellFinishesMove()
    { return true; }

// the combat cap: one spell may fight several battles a round, but any one
// pair only once (printed p. 101).
inline bool detOneCombatPerPairPerRound()
    { return true; }

// the lock: locked spells block all passage, even spells that could normally
// ignore the opposing spell (printed p. 101).
inline bool detLockedBlockPassage()
    { return true; }

// the multi-spell check: with multiple opposing spells and no lock, the
// highest movement rate is checked first (printed p. 101).
inline bool detHighestMVCheckedFirst()
    { return true; }

// the type announcement: the disadvantaged caster must announce his spell's
// type; the advantaged caster need not (printed p. 100).
inline bool detDisadvantagedAnnouncesType()
    { return true; }

// ---- the DMO duelist pins ----

// the duelist move: a character can move one space each round instead of
// casting (printed p. 103).
inline int detCharMoveOneSpace()
    { return 1; }

// the character power rank: 9 plus the bonus for high Intelligence or Wisdom
// (printed p. 103).
inline int detCharPRBase()
    { return 9; }

// the personal combat prize: the winner inflicts 1d6 points of damage or
// (printed p. 104).
inline int detCharVsCharDmgDie()
    { return 6; }

// the personal combat prize: sends the loser 1d4 spaces in either direction,
// never out of the arena (printed p. 104).
inline int detCharVsCharPushDie()
    { return 4; }

// the counter cap: only a single counter spell against each incoming spell
// (printed p. 103).
inline int detOneCounterPerIncoming()
    { return 1; }

// the duelist move: unlike spells, characters move forward or backward
// (printed p. 103).
inline bool detCharMoveBackward()
    { return true; }

// the duel save: the saving-throws-by-caster-level optional rule is always
// used in duels (printed p. 103).
inline bool detSavingThrowsByCasterLevel()
    { return true; }

// the duel save: bonuses for high ability scores never apply during a duel
// (printed p. 103).
inline bool detAbilityBonusesNeverApply()
    { return true; }

// the knockout: characters reduced to zero hit points or less lose the duel
// (printed p. 103).
inline bool detZeroHpLoses()
    { return true; }

// the lingering read: a hindered character cannot move or cast into the arena
// but may cast counter spells (printed p. 103).
inline bool detLingeringBlocksButCounters()
    { return true; }

// the endurance rule: a character with positive hit points can never be
// removed from the arena or forced to end the duel by duel magic (printed p.
// 103).
inline bool detPositiveHpNeverRemoved()
    { return true; }

// the character lock: when a character combats a spell, a lock destroys the
// attacking spell instead (printed p. 103).
inline bool detCharLockDestroysAttacker()
    { return true; }

// the counter spell: if the counter wins or locks, both the attacking and
// counter spells are destroyed; if the counter loses, the attack lands
// (printed p. 103).
inline bool detCounterBothDestroyed()
    { return true; }

// the counter flow: any number of counter spells per round if memorized;
// countering does not prevent a later cast (printed p. 103).
inline bool detUnlimitedCountersPerRound()
    { return true; }

// the defense read: defense spells vanish at the opponent's space; one may be
// cast in the character's own space as a stationary guard (printed p. 103).
inline bool detDefenseVanishesAtOpponent()
    { return true; }

// the push read: forced movement into a space with an opposing spell makes
// the spell take effect (printed p. 104).
inline bool detPushIntoSpellTriggers()
    { return true; }

// the engagement bar: no spellcasting while engaged in character combat, and
// counter spells cannot be used against a character (printed p. 104).
inline bool detNoCastWhileEngaged()
    { return true; }

// the spellcraft read: a character may identify an opposing spell with a
// power check instead of moving or casting (printed p. 104).
inline bool detPowerCheckIdentify()
    { return true; }

// the reveal: opposing spells are revealed when they enter a character's
// square (printed p. 103).
inline bool detSpellRevealedAtSquare()
    { return true; }

// ---- the DMO dueling-item pins ----

// the scroll of protection: creates a defensive effect with power rank 15
// (printed p. 104).
inline int detScrollProtectionPR()
    { return 15; }

// the scroll of protection: movement rate 1 (printed p. 104).
inline int detScrollProtectionMv()
    { return 1; }

// the item cost: an extra turn of preparation for each class of item to be
// allowed (printed p. 104).
inline int detItemClassPrepTurns()
    { return 1; }

// the item cost: one extra turn to allow only one particular item (printed p.
// 104).
inline int detSpecificItemPrepTurns()
    { return 1; }

// the item leech: a spell-like item effect in doubt creates a leech
// inflicting a maximum of 6d6 points of damage (printed p. 104).
inline int detItemLeechMaxDice()
    { return 6; }

// the item leech: a staff leech drains a maximum of 8d6 dice of damage
// (printed p. 104).
inline int detStaffLeechMaxDice()
    { return 8; }

// the item leech: other items inflict a maximum of 9d6 points of damage
// (printed p. 104).
inline int detOtherItemLeechMaxDice()
    { return 9; }

// the protection read: a priest with power score 11 (printed p. 104).
inline int detExamplePowerScore()
    { return 11; }

// the protection read: plate armor +2 (printed p. 104).
inline int detExampleArmorBonus()
    { return 2; }

// the protection read: a ring of protection +1 (printed p. 104).
inline int detExampleRingBonus()
    { return 1; }

// the protection read: 11 + 2 + 1 is an adjusted power score of 14 against
// spells (printed p. 104).
inline int detExampleAdjustedPS()
    { return 14; }

// the preexisting cost: an extra turn of preparation for each preexisting
// effect to be incorporated (printed p. 104).
inline int detPreexistingPrepTurns()
    { return 1; }

// the mind-only rule: no equipment can be carried into the arena; the
// opponents enter only in their minds (printed p. 104).
inline bool detNoEquipmentInArena()
    { return true; }

// the storing items: rings of spell storing, magical scrolls and rods of
// absorption can create spells in a duel (printed p. 104).
inline bool detStoringItemsWork()
    { return true; }

// the item bar: wands, staves, potions and miscellaneous items and most rods
// usually cannot be used unless both agree (printed p. 104).
inline bool detWandsUsuallyBanned()
    { return true; }

// the item save: an effect from a device uses the device level for the saving
// throw, not the wielder's (printed p. 104).
inline bool detDeviceLevelSaves()
    { return true; }

// the protection read: protective bonuses raise the power score against
// spells, not for personal combat (printed p. 104).
inline bool detProtectiveBonusesVsSpellsOnly()
    { return true; }

// the AC bar: armor class has no effect on a duel; bracers of defense do not
// help (printed p. 104).
inline bool detAcNoEffect()
    { return true; }

// the weapon read: attack bonuses from magical weapons raise the power score
// for personal combat only (printed p. 104).
inline bool detAttackBonusPersonalOnly()
    { return true; }

// the arena blockers: antimagic shell, prismatic sphere, the Otiluke spheres,
// wall spells and protection-from-magic scrolls can never be incorporated,
// even by agreement (printed p. 105).
inline bool detArenaBlockersAbsolute()
    { return true; }

// ---- the DMO specialist pins ----

// the specialist read: the extra preparation turn (printed p. 105).
inline int detSpecialistPrepTurns()
    { return 1; }

// the specialist flaw: spells from the opposition school gain an extra power
// rank against the specialist (printed p. 105).
inline int detOppositionSchoolPRBonus()
    { return 1; }

// the specialist example: dispel magic normally PR 12 (printed p. 105).
inline int detDispelBasePR()
    { return 12; }

// the specialist example: PR 13 against illusionists, Abjuration opposed to
// Illusion (printed p. 105).
inline int detDispelVsIllusionistPR()
    { return 13; }

// the Johan read: unseen servant normally PR 10 (printed p. 105).
inline int detUnseenServantPR()
    { return 10; }

// the Johan read: a level variation of -5 drops it to PR 5 (printed p. 105).
inline int detVariedUnseenServantPR()
    { return 5; }

// the Johan read: a 13th-level wild mage's fireball at -5 variation, PR 7
// (printed p. 105).
inline int detVariedFireballPR()
    { return 7; }

// the Johan read: the varied fireball inflicts only 8d6 points of damage
// (printed p. 105).
inline int detVariedFireballDmgDice()
    { return 8; }

// the Johan read: the varied fireball moves four, down from five (printed p.
// 105).
inline int detVariedFireballMv()
    { return 4; }

// the specialist read: saving-throw adjustments from the school of
// specialization apply during duels unless forgone, at an extra turn of
// preparation (printed p. 105).
inline bool detSpecialistSavesApply()
    { return true; }

// the wild read: wild surges never occur in the stable arena environment
// (printed p. 105).
inline bool detWildSurgesNever()
    { return true; }

// the wild read: level variations possible only if both combatants are wild
// mages (printed p. 105).
inline bool detLevelVariationBothWildMages()
    { return true; }

// the elementalist read: the higher-than-normal cast applies only if both
// combatants are elementalists (printed p. 105).
inline bool detElementalistBoostBothElementalists()
    { return true; }

// ---- the DMO spoils-of-victory pins ----

// the extra conditions: an extra turn of preparation for each extra end
// condition (printed p. 105).
inline int detExtraCondPrepTurns()
    { return 1; }

// the extra conditions: two extra turns if the condition does not apply
// equally to both (printed p. 105).
inline int detUnequalCondPrepTurns()
    { return 2; }

// the overdraw: one point of Intelligence or Wisdom lost for each excess
// spell level (printed p. 106).
inline int detExcessAbilityLoss()
    { return 1; }

// the temporary damage: it returns at one hit point per round (printed pp.
// 106-107).
inline int detTempDmgRegenPerRound()
    { return 1; }

// the temporary damage: at -10 or less the character dies; 0 to -9 is
// unconscious until hit points rise to 1 (printed p. 107).
inline int detTempDeathAtMinus()
    { return 10; }

// the knockout length: unconsciousness lasting 2d6 turns (printed pp.
// 106-107).
inline int detUnconsciousTurnsDice()
    { return 2; }

// the knockout length: 2d6 turns (printed pp. 106-107).
inline int detUnconsciousTurnsSize()
    { return 6; }

// the plane blow: a 20 percent chance the loser is blown to another plane on
// the 18-22 death ladder (printed p. 106).
inline int detPlaneBlowBand4()
    { return 20; }

// the plane blow: 40 percent on the 23-plus death ladder (printed p. 106).
inline int detPlaneBlowBand5()
    { return 40; }

// the death read: a 50 percent chance the body disintegrates into dust
// (printed p. 107).
inline int detDisintegrateChance()
    { return 50; }

// the Table 25 grid: five spell types squared (printed p. 99).
inline int detT25RowCount()
    { return 5; }

// the Table 26 grid: five movement bands (printed p. 99).
inline int detT26RowCount()
    { return 5; }

// the Table 27 grid: five ability bands (printed p. 101).
inline int detT27RowCount()
    { return 5; }

// the friendly stakes ladder: four bands, 0-6, 7-12, 13-18 and 19-plus spell
// levels (printed p. 105).
inline int detFriendlyBandCount()
    { return 4; }

// the death stakes ladder: five bands, 0-6, 7-12, 13-18, 18-22 and 23-plus
// spell levels (printed pp. 105-106).
inline int detDeathBandCount()
    { return 5; }

// the end conditions: a duel always ends when a combatant runs out of spells
// or hit points; the combatants choose one or both (printed p. 105).
inline bool detEndOnNoSpellsOrHp()
    { return true; }

// the binding: once set, the duel automatically ends when the condition is
// met, even if minds change (printed p. 105).
inline bool detAutoEndWhenMet()
    { return true; }

// the exit: a character can always end a duel early by surrendering and
// accepting defeat (printed p. 105).
inline bool detSurrenderAlwaysAllowed()
    { return true; }

// the spell loss: spells lost after a duel are gone as though cast, their
// components consumed (printed p. 106).
inline bool detSpellLossAsCast()
    { return true; }

// the spell loss: spells contributed to the arena are always lost (printed p.
// 106).
inline bool detContributedAlwaysLost()
    { return true; }

// the spell loss: the winner cannot lose more spell levels than were cast,
// but the loser can (printed p. 106).
inline bool detWinnerCapAtCast()
    { return true; }

// the overdraw: permanent if fought to the death, else one point restored per
// full day of rest (printed p. 106).
inline bool detExcessPermanentIfDeath()
    { return true; }

// the damage note: the Death From Massive Damage rule does not apply in duels
// (printed p. 107).
inline bool detMassiveDamageNA()
    { return true; }

// the service charm: unaffected by magic resistance, racial charm resistance
// or high ability scores - the winner bores into the psyche (printed p. 107).
inline bool detCharmIgnoresResistances()
    { return true; }

// the unconscious risk: anyone with a weapon can kill an unconscious
// character with a single blow (printed p. 107).
inline bool detUnconsciousKillable()
    { return true; }

// the plane blow: the loser leaves a pile of dust; destroyed equipment
// remains behind and a wish recovers him (printed p. 107).
inline bool detBlownEquipmentStays()
    { return true; }

// the death read: regeneration is ineffective; only a wish restores a
// disintegrated character (printed p. 107).
inline bool detDisintegrateNoRegeneration()
    { return true; }

// the death ladder: failed breath save - equipment saves vs. magical fire on
// the 18-22 band (printed p. 106).
inline bool detBand4EquipmentSaveFire()
    { return true; }

// the death ladder: equipment saves vs. lightning on the 23-plus band
// (printed p. 106).
inline bool detBand5EquipmentSaveLightning()
    { return true; }

// the service read: the 19-plus geas lifts only by a wish, dispel magic or
// remove curse from a higher-level caster (printed p. 106).
inline bool detServiceGeasLiftNeeds()
    { return true; }

// the damage cap: a victor cannot suffer more temporary damage than was
// suffered in the duel; the loser can suffer more normal damage (printed p.
// 107).
inline bool detWinnerTempCappedAtDuel()
    { return true; }

// the interference rule: any attack on a duelist, successful or not, disrupts
// the arena and ends the duel (printed p. 107).
inline bool detInterferenceEndsDuel()
    { return true; }

// the interference rule: both characters count as victor for the
// aftereffects, other terms rendered invalid (printed p. 107).
inline bool detBothVictorsOnInterference()
    { return true; }

// the interference rule: touching the combatants, handing them equipment or
// casting spells on them ends the duel; shouting advice is allowed if the
// protective spell permits (printed p. 107).
inline bool detTouchCombatantsEnds()
    { return true; }

// the interference rule: attacks on the mediator or the protective spell have
// no effect on the duel (printed p. 107).
inline bool detMediatorAttacksNoEffect()
    { return true; }

// the mediator's role: he decides how isolated the combatants are (printed p.
// 107).
inline bool detMediatorChoosesIsolation()
    { return true; }

// the mediator's role: it is traditional to search each combatant for
// contraband, physically, to foil nondetection (printed p. 107).
inline bool detMediatorSearchesContraband()
    { return true; }

// the mediator's role: the mediator can end the construction or the duel just
// by touching a combatant (printed p. 107).
inline bool detMediatorTouchEnds()
    { return true; }

// the mediator's role: under no special compulsion toward fairness unless
// duelists take precautions such as a geas (printed p. 107).
inline bool detMediatorNoCompulsion()
    { return true; }

// the mediator's role: a large protective spell can include the mediator;
// prismatic sphere allows free passage in and out (printed p. 107).
inline bool detMediatorMayIncludeSelf()
    { return true; }

// ---- the DMO special-characteristic pins ----

// the summoning group: a victorious summoning inflicts 1d6 points of damage
// per spell level and remains to fight again (printed p. 108).
inline int detSummoningDmgDie()
    { return 6; }

// the summoning group: one die per spell level (printed p. 108).
inline int detSummoningDmgPerLevel()
    { return 1; }

// the illusion group: a winning illusion inflicts 1d6 points of damage per
// level of the illusion (printed p. 108).
inline int detIllusionDmgDie()
    { return 6; }

// the illusion group: one die per level (printed p. 108).
inline int detIllusionDmgPerLevel()
    { return 1; }

// the demishadow magic read: a failed save inflicts 10d6, a counter or second
// save reduces it to 5d6; a made save gives 4d6, reducible to 2d6 (printed p.
// 110).
inline int detDemishadowFailDmgDice()
    { return 10; }

// the demishadow magic read: the counter-spell reduction, 5d6 (printed p.
// 110).
inline int detDemishadowCounterDmgDice()
    { return 5; }

// the demishadow magic read: the made-save damage, 4d6 (printed p. 110).
inline int detDemishadowSaveDmgDice()
    { return 4; }

// the demishadow magic read: the made-save counter reduction, 2d6 (printed p.
// 110).
inline int detDemishadowSaveCounterDmgDice()
    { return 2; }

// the shadow magic read: a failed save inflicts 10d6, a save or counter
// reduces it to 5d6; a made save allows a second save for 1d6, else 2d6
// (printed p. 115).
inline int detShadowFailDmgDice()
    { return 10; }

// the shadow magic read: the counter reduction, 5d6 (printed p. 115).
inline int detShadowCounterDmgDice()
    { return 5; }

// the shadow magic read: the second-save reduction, 1d6 (printed p. 115).
inline int detShadowSecondSaveDmgDice()
    { return 1; }

// the shadow magic read: the failed-counter damage, 2d6 (printed p. 115).
inline int detShadowFailCounterDmgDice()
    { return 2; }

// the demishadow monsters read: 5d6 points with a successful attack, or
// (printed p. 110).
inline int detDemishadowMonDmgDice()
    { return 5; }

// the demishadow monsters read: 2d6 if the save succeeds (printed p. 110).
inline int detDemishadowMonSaveDmgDice()
    { return 2; }

// the energy drain read: a failed combat roll or counter costs two levels
// until the duel ends (printed p. 111).
inline int detEnergyDrainLevels()
    { return 2; }

// the enervation read: one level lost for every four levels of the caster
// (printed p. 111).
inline int detEnervationDivisor()
    { return 4; }

// the earthquake read: save vs. death magic or die; a successful save still
// suffers 5d10 (printed p. 111).
inline int detEarthquakeDmgDice()
    { return 5; }

// the earthquake read: 5d10 points of damage (printed p. 111).
inline int detEarthquakeDmgSize()
    { return 10; }

// the earthquake read: the only effective counters - antimagic shell,
// disbelief, dispel magic, elemental aura, fly and levitate; character combat
// is ineffective (printed p. 111).
inline int detEarthquakeCounterCount()
    { return 6; }

// the fire seeds read: a winning combat inflicts 8d6; a power-score victory
// still costs a save vs. 4d4 (printed p. 111).
inline int detFireSeedsDmgDice()
    { return 8; }

// the fire seeds read: the 4d4 save-or-suffer (printed p. 111).
inline int detFireSeedsSaveDice()
    { return 4; }

// the magical stone read: a successful character combat roll inflicts 3d4
// (printed p. 113).
inline int detMagicalStoneDmgDice()
    { return 3; }

// the magical stone read: 3d4 points (printed p. 113).
inline int detMagicalStoneDmgSize()
    { return 4; }

// the minute meteors read: five missiles per round; extras follow next round
// or are forgone (printed p. 113).
inline int detMeteorsPerRound()
    { return 5; }

// the minute meteors read: each group inflicts 1d4+1 per missile on a winning
// character combat (printed p. 113).
inline int detMeteorDmgDie()
    { return 4; }

// the minute meteors read: the +1 per missile (printed p. 113).
inline int detMeteorDmgBonus()
    { return 1; }

// the moment read: character combat with a +4 bonus - a 12 from a PR-13
// caster reads as 16 (printed p. 113).
inline int detMomentBonus()
    { return 4; }

// the freezing sphere read: as a missile it conducts character combat for 6d6
// (printed p. 113).
inline int detFreezingSphereMissileDice()
    { return 6; }

// the freezing sphere read: as an attack it inflicts 1d4+2 per caster level,
// save for half (printed p. 113).
inline int detFreezingSpherePerLevelDie()
    { return 4; }

// the freezing sphere read: the +2 per level (printed p. 113).
inline int detFreezingSpherePerLevelBonus()
    { return 2; }

// the freezing sphere read: a maximum of 10d4+20 (printed p. 113).
inline int detFreezingSphereMaxDice()
    { return 10; }

// the rainbow read: the bow version creates four missiles on the cast round
// (printed p. 114).
inline int detRainbowFirstMissiles()
    { return 4; }

// the rainbow read: three more on the second round or forgone (printed p.
// 114).
inline int detRainbowExtraMissiles()
    { return 3; }

// the rainbow read: each group conducts character combat, 1d6+2 per missile
// (printed p. 114).
inline int detRainbowDmgDie()
    { return 6; }

// the rainbow read: the +2 per missile (printed p. 114).
inline int detRainbowDmgBonus()
    { return 2; }

// the heat metal read: the attack version inflicts three points of damage
// each round (printed p. 112).
inline int detHeatMetalDmgPerRound()
    { return 3; }

// the heat metal read: as a missile, one point of damage each round until
// defeated (printed p. 112).
inline int detHeatMetalMissileDmg()
    { return 1; }

// the holy word read: affected characters and spells lose two power scores,
// except against the holy word itself (printed p. 112).
inline int detHolyWordPSReduction()
    { return 2; }

// the chant read: two rounds to cast, unusable as a counter, disruptable in
// the first round - an exception to the general rule (printed p. 109).
inline int detChantCastRounds()
    { return 2; }

// the fire purge and insect plague read: a full turn, ten rounds to cast,
// disrupted in the first nine (printed pp. 111-112).
inline int detFirePurgeCastRounds()
    { return 10; }

// the fire purge and insect plague read: the disruption window (printed pp.
// 111-112).
inline int detFirePurgeDisruptRounds()
    { return 9; }

// the wish and limited wish read: used as attack, AD, missile or leech they
// inflict 10d6, save vs. spells for half (printed pp. 112-113 and 116).
inline int detWishDuelDmgDice()
    { return 10; }

// the limited wish read: as a counter it automatically counters any spell of
// 6th level or lower, and serves as a counter to all others; it cannot be
// locked by spells of 6th or less (printed p. 113).
inline int detLimitedWishCounterMaxLevel()
    { return 6; }

// the globe of invulnerability read: cannot be locked by spells of 4th level
// or less; missiles and leeches of 4th or less must battle it (printed p.
// 112).
inline int detGlobeLockMaxLevel()
    { return 4; }

// the minor globe read: cannot be locked by spells of 3rd level or less;
// missiles and leeches of 3rd or lower must battle it (printed p. 113).
inline int detMinorGlobeLockMaxLevel()
    { return 3; }

// the spiritual hammer read: character combat inflicting 1d6, attacking each
// round until defeated or expired (printed p. 115).
inline int detSpiritualHammerDmgDie()
    { return 6; }

// the shillelagh read: character combat inflicting 1d6, attacking again if
// successful (printed p. 115).
inline int detShillelaghDmgDie()
    { return 6; }

// the watery double read: a successful combat inflicts 3d6 and continues
// attacking each round (printed p. 116).
inline int detWateryDoubleDmgDice()
    { return 3; }

// the telekinesis read: character combat inflicting one point of damage per
// caster level (printed p. 115).
inline int detTelekinesisDmgPerLevel()
    { return 1; }

// the liveoak read: only one liveoak effect active per arena at any time
// (printed p. 113).
inline int detLiveoakOneAtATime()
    { return 1; }

// the elemental aura read: air, earth, fire or water chosen at casting; it
// battles its own element and is destroyed by locks with it (printed p. 111).
inline int detElementalAuraElementCount()
    { return 4; }

// the mental-attack group: charm, command, confusion and their kin have only
// a temporary effect - the victim cannot move or cast but may counter
// (printed p. 108).
inline bool detMentalTemporaryOnly()
    { return true; }

// the mental-attack group: duelists can never be compelled to leave the arena
// or perform unwanted actions (printed p. 108).
inline bool detNeverCompelledToLeave()
    { return true; }

// the summoning group: while a creature summoning occupies his space the
// opponent can cast only counter spells and must fight with his power score
// (printed p. 108).
inline bool detSummoningCounterOnly()
    { return true; }

// the summoning group: a lock does not destroy a summoning spell - it attacks
// again next round, unlike normal character-vs-spell combat (printed p. 108).
inline bool detSummoningLockPersists()
    { return true; }

// the illusion group: phantasmal-force spells can duplicate any type, chosen
// at casting and never changed (printed p. 108).
inline bool detIllusionAnyType()
    { return true; }

// the illusion group: the type is chosen when cast and cannot change (printed
// p. 108).
inline bool detIllusionTypeFixedAtCast()
    { return true; }

// the illusion group: employed as a defense, any lock destroys the illusion
// unless the opponent summons a creature (printed p. 108).
inline bool detIllusionDefenseLockDestroys()
    { return true; }

// the reversible group: reversed forms usually function opposite - a reversed
// defense is an attack; a reversed leech is still a leech (printed p. 108).
inline bool detReversedOpposite()
    { return true; }

// the reversible group: a spell's reverse always counters itself and vice
// versa (printed p. 108).
inline bool detReverseCountersReverse()
    { return true; }

// the teleportation group: instantaneous-travel spells cannot be locked by
// physical barriers - a lock means the spells ignore each other (printed p.
// 108).
inline bool detTeleportIgnoresBarrierLocks()
    { return true; }

// the teleportation group: used as a counter spell, a lock still destroys
// both spells (printed p. 108).
inline bool detTeleportCounterLockDestroys()
    { return true; }

// the haste read: haste automatically destroys and is automatically destroyed
// by slow (printed p. 112).
inline bool detHasteSlowMutual()
    { return true; }

// the shield read: missiles must battle it, and it always defeats magic
// missile (printed p. 115).
inline bool detShieldDefeatsMagicMissile()
    { return true; }

// the transmute rock to mud read: it always defeats wall of stone (printed p.
// 116).
inline bool detTransmuteDefeatsWallOfStone()
    { return true; }

// the fly and levitate read: both always counter transmute rock to mud
// (printed p. 112).
inline bool detFlyLevitateCounterTransmute()
    { return true; }

// the true seeing read: it always defeats illusions (printed p. 116).
inline bool detTrueSeeingDefeatsIllusions()
    { return true; }

// the ineffective trio: stabilize, windwild and wildzone do nothing in a
// dueling arena (printed pp. 115-116).
inline bool detStabilizeIneffective()
    { return true; }

// the mind blank read: cannot be locked by mind attacks; it counters all
// leech spells and mental attacks (printed p. 113).
inline bool detMindBlankCountersLeeches()
    { return true; }

// the permanency read: used in a duel it does not drain Constitution, even if
// lost from memory afterward (printed p. 113).
inline bool detPermanencyNoConLoss()
    { return true; }

// the neutralize poison read: it automatically counters poisonous spells such
// as stinking cloud and cloudkill (printed p. 113).
inline bool detNeutralizePoisonCounters()
    { return true; }

// the remove paralysis read: it automatically counters all hold spells and
// paralysis (printed p. 114).
inline bool detRemoveParalysisCounters()
    { return true; }

// the raise dead and reincarnate read: they counter any spell that inflicts
// damage (printed p. 114).
inline bool detRaiseDeadCountersDamage()
    { return true; }

// the crystalbrittle read: it automatically defeats wall of iron and any
// other metal-mass spell, in combat and as a counter (printed p. 110).
inline bool detCrystalbrittleDefeatsMetal()
    { return true; }

// the disintegrate read: it always defeats solid-barrier spells such as wall
// spells (printed p. 110).
inline bool detDisintegrateDefeatsBarriers()
    { return true; }

// the dispel magic read: if locked or defeated it can still destroy the
// opposing spell with a normal dispel roll; it dissipates at the opponent's
// space (printed pp. 110-111).
inline bool detDispelDestroysOnLoss()
    { return true; }

// the wish and limited wish read: no aging unless actually lost from memory
// in the aftermath (printed pp. 113 and 116).
inline bool detWishNoAgingUnlessLost()
    { return true; }

// ---- the DMO worked-duel pins ----

// the worked duel: neither contributed, both roll 1d10 for the advantage -
// Calvin wins (printed p. 116).
inline int detExampleAdvantageRollDie()
    { return 10; }

// the worked duel: clairvoyance, a leech (printed p. 116).
inline int detExClairvoyanceLevel()
    { return 3; }

// the worked duel: clairvoyance PR 12, MV 5 - the level-plus-nine read
// (printed p. 116).
inline int detExCalvinClairvoyancePR()
    { return 12; }

// the worked duel: clairvoyance moves five (printed p. 116).
inline int detExClairvoyanceMv()
    { return 5; }

// the worked duel: withdraw, a defense cast in Delsenora's own square
// (printed p. 116).
inline int detExWithdrawLevel()
    { return 2; }

// the worked duel: withdraw PR 11, MV 1 (printed p. 116).
inline int detExWithdrawPR()
    { return 11; }

// the worked duel: withdraw moves one (printed p. 116).
inline int detExWithdrawMv()
    { return 1; }

// the worked duel: monster summoning II from Calvin's ring of spell storing,
// an AD spell (printed p. 117).
inline int detExMonsterSumLevel()
    { return 4; }

// the worked duel: monster summoning II PR 13, MV 3 (printed p. 117).
inline int detExMonsterSumPR()
    { return 13; }

// the worked duel: monster summoning II moves three (printed p. 117).
inline int detExMonsterSumMv()
    { return 3; }

// the worked duel: Delsenora's dispel magic, an AD spell, PR 12, MV 4
// (printed p. 117).
inline int detExDispelPR()
    { return 12; }

// the worked duel: dispel magic moves four (printed p. 117).
inline int detExDispelMv()
    { return 4; }

// the worked duel: magic missile, a missile spell, PR 10, MV 5 (printed p.
// 117).
inline int detExMagicMissilePR()
    { return 10; }

// the worked duel: magic missile moves five (printed p. 117).
inline int detExMagicMissileMv()
    { return 5; }

// the worked duel: animate object, an AD spell, PR 15, MV 3 (printed p. 117).
inline int detExAnimatePR()
    { return 15; }

// the worked duel: animate object moves three (printed p. 117).
inline int detExAnimateMv()
    { return 3; }

// the worked duel: Calvin rolls 20, Delsenora 9 - the clairvoyance is
// destroyed and the advantage shifts to Delsenora (printed p. 117).
inline int detExCalvinRoll()
    { return 20; }

// the worked duel: Delsenora's 9 (printed p. 117).
inline int detExDelsenoraRoll()
    { return 9; }

// the worked duel: withdraw's special ability forces leeches and missiles to
// fight it despite the advantage (printed p. 117).
inline bool detExWithdrawForcesCombat()
    { return true; }

// the worked duel: no contributions, so ten spaces between the combatants
// (printed p. 116).
inline bool detExArenaTenSpaces()
    { return true; }

// meeting an attack spell: attacks pass attacks, defenses and attacks fight,
// AD fights, leeches let the advantage decide, missiles pass (printed p. 99).
inline int detT25VsA(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

// meeting a defense spell: attacks must fight, defenses pass each other, AD
// fights, leeches let the advantage decide, missiles generally ignore
// (printed p. 99).
inline int detT25VsD(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        default:
            return -99;
        }
    }

// meeting an attack/defense spell: attacks, defenses and attacks/defenses
// fight; leeches and missiles let the advantage decide (printed p. 99).
inline int detT25VsAD(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        default:
            return -99;
        }
    }

// meeting a leech spell: attacks and defenses let the advantage decide,
// attack/defenses let the advantage decide, leeches fight leeches, missiles
// pass (printed p. 99).
inline int detT25VsL(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

// meeting a missile spell: attacks pass, defenses generally ignore,
// attack/defenses let the advantage decide, leeches pass, missiles pass
// (printed p. 99).
inline int detT25VsM(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

// the movement rate by range band: touch or zero moves one, 1-20 yards two,
// 21-50 three, 51-100 four, 101-plus and instantaneous-huge effects five
// (printed p. 99).
inline int detT26Mv(int b)
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

// the ability bonus: zero at 14 or less, one at 15, two at 16, three at 17,
// four at 18 or more (printed p. 101).
inline int detT27Bonus(int b)
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
        default:
            return -99;
        }
    }

// the power score: nine at 14 or less, ten at 15, eleven at 16, twelve at 17,
// thirteen at 18 or more (printed p. 101).
inline int detT27PowerScore(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 10;
        case 2:
            return 11;
        case 3:
            return 12;
        case 4:
            return 13;
        default:
            return -99;
        }
    }

// the loser's temporary damage dice: nothing at 0-6, 2d6 at 7-12, 4d6 at
// 13-18, 8d6 at 19-plus (printed p. 105).
inline int detFriendlyLoserDmgDice(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 8;
        default:
            return -99;
        }
    }

// the loser's temporary damage die size: d6 throughout (printed p. 105).
inline int detFriendlyLoserDmgSize(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        default:
            return -99;
        }
    }

// the loser's forfeited spell-level dice: nothing, 2d4, 4d4, 8d4 (printed p.
// 105).
inline int detFriendlyLoserSpellDice(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 8;
        default:
            return -99;
        }
    }

// the loser's forfeited spell-level die size: d4 throughout (printed p. 105).
inline int detFriendlyLoserSpellSize(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        default:
            return -99;
        }
    }

// the winner's lost spell-level dice: nothing until 13-18 where 1d6, 4d6 at
// 19-plus (printed p. 105).
inline int detFriendlyWinnerSpellDice(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -99;
        case 2:
            return 1;
        case 3:
            return 4;
        default:
            return -99;
        }
    }

// the winner's lost spell-level die size: d6 where lost (printed p. 105).
inline int detFriendlyWinnerSpellSize(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -99;
        case 2:
            return 6;
        case 3:
            return 6;
        default:
            return -99;
        }
    }

// the loser's damage dice: 2d6, 4d6, 6d6, 8d6, 10d6 across the five bands
// (printed pp. 105-106).
inline int detDeathLoserDmgDice(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        default:
            return -99;
        }
    }

// the loser's damage die size: d6 throughout (printed pp. 105-106).
inline int detDeathLoserDmgSize(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        default:
            return -99;
        }
    }

// the loser's lost spell-level dice: none on the first band, then 4d4, 8d4,
// 12d4, 18d4 (printed pp. 105-106).
inline int detDeathLoserSpellDice(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 4;
        case 2:
            return 8;
        case 3:
            return 12;
        case 4:
            return 18;
        default:
            return -99;
        }
    }

// the loser's lost spell-level die size: d4 throughout (printed pp. 105-106).
inline int detDeathLoserSpellSize(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        default:
            return -99;
        }
    }

// the winner's lost spell-level dice: none, 1d6, 2d6, 4d6, 2d6 (printed pp.
// 105-106).
inline int detDeathWinnerSpellDice(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 2;
        default:
            return -99;
        }
    }

// the winner's lost spell-level die size: d6 throughout (printed pp.
// 105-106).
inline int detDeathWinnerSpellSize(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        default:
            return -99;
        }
    }

// the winner's temporary damage dice: none on the first two bands, 1d6, 2d6,
// 4d6 (printed pp. 105-106).
inline int detDeathWinnerTempDice(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -99;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 4;
        default:
            return -99;
        }
    }

// the winner's temporary damage die size: d6 throughout (printed pp.
// 105-106).
inline int detDeathWinnerTempSize(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -99;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        default:
            return -99;
        }
    }

// the service stakes ladder (printed p. 106): by contributed spell levels the
// loser is charmed at 0-6, plus a suggestion at 7-12, plus a geas at 13-18,
// and falls under domination at 19-plus; the codes run charm, suggestion,
// geas, domination.
inline int detServiceLadder(int x)
    {
        if (x <= 6) return 0;
        if (x <= 12) return 1;
        if (x <= 18) return 2;
        return 3;
    }

}   // namespace rules
