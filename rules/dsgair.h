// =========================================================================================
// Adnd1 - rules/dsgair.h
// The DSG UNDERGROUND ENVIRONMENT OPENER, R509: the printed pp. 36-37 (pdf
// 37-38) - the chapter opener (life underground shaped by the limits of
// sunlight and fresh air), the air supply duration (10 cubic feet per 24-hour
// rest, 12 moderate, 6 strenuous, the 2x/4x rates, the 3+4x5=23 example, the
// creature ratios, the post-exhaustion Con Check ladder with the -10 hp death
// floor and the 3-per-turn recovery), fire and oxygen (the small-fire 10-foot
// cube in 2 hours, torch 8 hours, the 4x scaling, the oil 3-rounds-as-turns
// rule), the smoke system (the 1-foot layer per turn per 10x10, ceiling
// stacking, the Con Check with 1d6 damage and 1d6 recovery, the cumulative
// rule and the 33-28-5 orc death example), the poisonous and noxious gases
// (save vs. poison vs. the -3/-3 Con Check economy, the natural-gas 20%
// explosion ladder with its Wisdom Check, the small-bird early warning) and
// the five-rung ventilation ladder
// census 433 -> 434.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR with the pdf
// Acrobat-Capture layer as the second read - every numeric cell
// dual-confirmed; the garble classes settled: djvu "213 as much oxygen" = 2/3
// (Acrobat "consumes 2/3 as much"), the percent-glyph garbles
// (1096/496-class) = 10% and +4%-style, Acrobat "112" = 1/2 (the halved
// rates), Acrobat "ld6/ld4" = 1d6/1d4. Odor detection (pp. 37-38) and its
// Tables 15-16 begin the NEXT round - this slice ends at the sealed-rung
// ladder.
//
// Pure prose round - no printed grid, no tables, no sentinels. The
// ventilation pins are the ENVIRONMENTAL-scale ladder; the R508 dnrVent pins
// are the Battlesystem-scale modifiers - related seams, nothing auto-credited
// either way. The breath-holding scope note pins as a bool with the WSG R454
// cross-reference in its comment.
//
namespace rules {

// ---- the air supply duration ----

// a human-sized creature at complete rest depletes the oxygen in 10 cubic
// feet of air.
inline int dnaAirRestCubicFeet()
    { return 10; }

// the same 10 cubic feet lasts 24 hours at complete rest.
inline int dnaAirRestHours()
    { return 24; }

// even moderate physical activity halves the air supply to 12 hours.
inline int dnaAirModerateHours()
    { return 12; }

// strenuous exertion cuts the air supply to a mere 6 hours.
inline int dnaAirStrenuousHours()
    { return 6; }

// a moderately exercising character uses oxygen twice as fast as one at rest.
inline int dnaAirModerateRateMult()
    { return 2; }

// a character working strenuously uses oxygen four times faster than a
// resting one.
inline int dnaAirStrenuousRateMult()
    { return 4; }

// the worked example: the character rests for 3 hours.
inline int dnaAirExampleRestHours()
    { return 3; }

// the worked example: then works hard for 5 hours.
inline int dnaAirExampleWorkHours()
    { return 5; }

// the worked example total: 3 hours of rest plus 4 times 5 hours of work
// equals 23 hours of resting-rate oxygen.
inline int dnaAirExampleTotalRestHours()
    { return 23; }

// a dwarf or elf consumes oxygen at two-thirds the human rate: the numerator.
inline int dnaAirDwarfElfNum()
    { return 2; }

// a dwarf or elf consumes oxygen at two-thirds the human rate: the
// denominator.
inline int dnaAirDwarfElfDen()
    { return 3; }

// a halfling or a dog uses only half as much oxygen as a human.
inline int dnaAirHalflingDogDen()
    { return 2; }

// a mule or an ogre consumes oxygen at twice the human rate.
inline int dnaAirMuleOgreMult()
    { return 2; }

// the DM applies the oxygen ratio to all characters and to any creatures,
// such as mules or dogs, that accompany them.
inline bool dnaAirDmAppliesToCreatures()
    { return true; }

// each turn after the oxygen is exhausted, the character must make a
// Constitution Check.
inline bool dnaAirConCheckEachTurnAfterExhaust()
    { return true; }

// every failed post-exhaustion check reduces each ability score by 1.
inline int dnaAirFailAbilityLoss()
    { return 1; }

// every failed post-exhaustion check also reduces the hit point total by 1.
inline int dnaAirFailHpLoss()
    { return 1; }

// each additional Constitution Check is made against the reduced Constitution
// score - the character grows more feeble as he gulps the last oxygen.
inline bool dnaAirCheckAgainstReducedCon()
    { return true; }

// when all ability scores have dropped to 0, the character is unconscious.
inline bool dnaAirUnconsciousAtZeroAbilities()
    { return true; }

// when the hit point total reaches -10, the character is dead.
inline int dnaAirDeathHpFloor()
    { return -10; }

// death becomes automatic once the Constitution score reaches 0, since all
// further Constitution Checks automatically fail.
inline bool dnaAirAutoDeathAtConZero()
    { return true; }

// if fresh air is introduced before death, the character begins to recover
// immediately.
inline bool dnaAirRecoveryImmediateOnFreshAir()
    { return true; }

// on recovery, hit points and ability scores all climb at 3 points per turn
// until original levels.
inline int dnaAirRecoverPerTurn()
    { return 3; }

// this system is used only for characters in an area with air - it cannot be
// used for characters holding their breath (the WSG breath-holding pins are a
// separate system; nothing auto-credited).
inline bool dnaAirOnlyInAirNotBreathHolding()
    { return true; }

// if a cave-in occurs, ventilation sources may be cut off - the potential for
// air supply problems should not be overlooked.
inline bool dnaAirCaveInCutsVentilation()
    { return true; }

// a chamber may be so crowded that a meager ventilation system cannot replace
// oxygen as fast as it is depleted.
inline bool dnaAirCrowdingOutpacesVentilation()
    { return true; }

// ---- fire and oxygen ----

// a small fire is one foot or less in diameter.
inline int dnaFireSmallMaxDiameterFeet()
    { return 1; }

// a small fire consumes all of the oxygen in a ten-foot cubic space.
inline int dnaFireSmallCubeFeet()
    { return 10; }

// the small fire exhausts that ten-foot cube of oxygen in 2 hours.
inline int dnaFireSmallHours()
    { return 2; }

// the same consumption expressed in turns: 12 turns.
inline int dnaFireSmallTurns()
    { return 12; }

// a flaming torch consumes all of the oxygen in the same ten-foot cube in 8
// hours.
inline int dnaFireTorchHours()
    { return 8; }

// the oxygen consumption of larger fires is based on the number of small
// fires they equal.
inline bool dnaFireScalesBySmallFireEquivalents()
    { return true; }

// a fire four times larger than a small fire consumes oxygen four times as
// fast.
inline int dnaFireScaleExampleMult()
    { return 4; }

// when all of the oxygen is consumed, the fire goes out.
inline bool dnaFireGoesOutWithoutOxygen()
    { return true; }

// oil in a flask or similar small container burns for 3 rounds.
inline int dnaOilBurnRounds()
    { return 3; }

// for oxygen consumption, burning oil is treated as a small fire and each
// round of burning counts as a full turn - 3 rounds use the oxygen of 3 turns
// of wood fire.
inline bool dnaOilRoundCountsAsTurn()
    { return true; }

// ---- smoke ----

// if any of the fuel is wet, or if green or living branches, twigs or leaves
// are used, smoke is produced.
inline bool dnaSmokeFromWetOrGreenFuel()
    { return true; }

// any kind of burning fabric creates smoke, as does burning oil.
inline bool dnaSmokeFromFabricAndOil()
    { return true; }

// a small fire produces enough smoke in one turn to create a one-foot-thick
// smoke layer.
inline int dnaSmokeLayerFeet()
    { return 1; }

// that smoke layer covers a 10-foot by 10-foot square area.
inline int dnaSmokeAreaFeet()
    { return 10; }

// the smoke rises and collects against the ceiling; each next turn of smoke
// collects below the previous layer until the breathable air is concentrated
// near the floor.
inline bool dnaSmokeLayersStackFromCeiling()
    { return true; }

// finally the entire room fills with smoke and even characters lying on the
// floor are affected.
inline bool dnaSmokeFillsRoomAffectsFloor()
    { return true; }

// an oil fire creates the same amount of smoke as an average fire, except
// that the rate is calculated by round instead of by turn.
inline bool dnaOilSmokeRateByRound()
    { return true; }

// a fire three times as big as a one-foot-diameter fire creates smoke three
// times as fast.
inline bool dnaSmokeScalesWithFireSize()
    { return true; }

// the smoke example multiplier: 3 times the fire, 3 times the smoke rate.
inline int dnaSmokeScaleExampleMult()
    { return 3; }

// a character forced to breathe smoke must make a Constitution Check each
// round that the smoke is inhaled.
inline bool dnaSmokeConCheckEachRound()
    { return true; }

// a failed smoke check means the character suffers 1d6 hit points of smoke
// damage.
inline int dnaSmokeDamageDie()
    { return 6; }

// smoke damage is temporary - with a chance to breathe fresh air the
// character makes a Constitution Check every round, regaining 1d6 points on a
// success.
inline bool dnaSmokeDamageTemporary()
    { return true; }

// the smoke-damage recovery die: 1d6 points per successful fresh-air round.
inline int dnaSmokeRecoverDie()
    { return 6; }

// smoke damage is real: any other damage taken while a character suffers from
// smoke damage must be considered cumulative with it.
inline bool dnaSmokeDamageCumulative()
    { return true; }

// the smoke example character has 33 hit points.
inline int dnaSmokeExampleCharHp()
    { return 33; }

// he loses 28 of them to smoke inhalation.
inline int dnaSmokeExampleLoss()
    { return 28; }

// an orc strikes him for 5 points of damage before he regains any smoke
// losses - the 5 remaining points mean he is killed.
inline int dnaSmokeExampleOrcHit()
    { return 5; }

// ---- poisonous and noxious gases ----

// poisonous gases generally require characters to make saving throws vs.
// poison.
inline bool dnaGasPoisonSaveVsPoison()
    { return true; }

// any gas - poisonous, noxious, or harmless - can replace the oxygen in an
// area; the effects are treated as the air-supply exhaustion explained
// earlier.
inline bool dnaGasOxygenReplacementTreatedAsExhaustion()
    { return true; }

// noxious gases force characters to make Constitution Checks every round.
inline bool dnaNoxiousConCheckEachRound()
    { return true; }

// a failed noxious-gas check results in a general lowering of ability scores
// by 3.
inline int dnaNoxiousAbilityLoss()
    { return 3; }

// the same 3-point penalty is applied to attack rolls (the modern example:
// tear gas).
inline int dnaNoxiousAttackPenalty()
    { return 3; }

// characters can be rendered quite helpless by noxious gases when all ability
// scores are reduced to 0.
inline bool dnaNoxiousHelplessAtZeroAbilities()
    { return true; }

// but they are not killed - noxious gases cause no loss of hit points.
inline bool dnaNoxiousNoHpLoss()
    { return true; }

// ability scores are raised at 3 per turn once the character can breathe
// fresh air again.
inline int dnaNoxiousRecoverPerTurn()
    { return 3; }

// modifiers to the saving throw or Constitution Check can be applied as the
// DM sees fit, for exceptionally lethal or mild poisons or degrees of
// noxiousness.
inline bool dnaGasDmAdjustmentsAllowed()
    { return true; }

// if a gas is completely odor-free, no Wisdom Check should be allowed - the
// check represents awareness of the odor.
inline bool dnaOdorlessGasNoWisCheck()
    { return true; }

// strong-odor gases such as sulphur give the characters a chance to hold
// their breath before the full force of the gas takes effect.
inline bool dnaStrongOdorAllowsBreathHold()
    { return true; }

// natural gas with a torch, candle, lantern or any other open flame has a
// chance per round of exploding.
inline bool dnaNatGasExplodesWithOpenFlame()
    { return true; }

// the base chance of a natural-gas explosion is 20 percent per round.
inline int dnaNatGasExplodePct()
    { return 20; }

// the explosion causes 1d6 points of damage to all characters and creatures
// in the area with the gas.
inline int dnaNatGasDamageDie()
    { return 6; }

// the potency step: each 10 percent increase in the chance of explosion.
inline int dnaNatGasPotencyStepPct()
    { return 10; }

// each potency step adds another 1d6 to the damage inflicted.
inline int dnaNatGasPotencyDieStep()
    { return 1; }

// higher concentrations add 1 to the characters' Wisdom scores per potency
// step, for purposes of this Wisdom Check only.
inline int dnaNatGasWisBonusPerStep()
    { return 1; }

// characters entering natural gas might be allowed Wisdom Checks only if they
// are moving slowly and investigating their surroundings carefully.
inline bool dnaNatGasWisCheckOnlyIfCareful()
    { return true; }

// a small bird with the party gives early warning of gradually increasing
// poisonous gas: the bird's save comes one turn before the characters must
// save.
inline bool dnaBirdWarnsOneTurnEarly()
    { return true; }

// the DM should make a secret saving throw vs. poison for the bird.
inline bool dnaBirdSaveSecret()
    { return true; }

// the bird saves as a 0th-level human.
inline int dnaBirdSaveLevel()
    { return 0; }

// if the bird's saving throw fails, the bird dies.
inline bool dnaBirdDiesOnFailedSave()
    { return true; }

// the bird warning is of little help if gas is suddenly introduced in high
// concentration - only a gradually increasing amount gives any early warning.
inline bool dnaBirdOnlyGradualGas()
    { return true; }

// ---- the ventilation ladder ----

// in a well-ventilated area (a noticeable airflow), smoke does not
// accumulate.
inline bool dnaVentWellNoSmokeAccumulation()
    { return true; }

// nor is the oxygen exhausted by characters breathing or by fire in a
// well-ventilated area.
inline bool dnaVentWellNoOxygenExhaustion()
    { return true; }

// the duration of all gas-based spells is halved in a well-ventilated area.
inline bool dnaVentWellGasSpellsHalved()
    { return true; }

// poisonous or noxious gases remain in a well-ventilated area for 2 turns
// unless more gas is introduced.
inline int dnaVentWellGasTurns()
    { return 2; }

// with subtle air movement (detected by the flickering of a torch or candle),
// gas-based spells linger for their normal durations and fresh air is not a
// problem.
inline bool dnaVentSubtleSpellsNormal()
    { return true; }

// in a subtly ventilated area, poisonous or noxious gases remain effective
// for 1 hour.
inline int dnaVentSubtleGasHours()
    { return 1; }

// smoke from small fires or torches does not accumulate in a subtly
// ventilated area.
inline bool dnaVentSubtleSmallSmokeNoAccumulation()
    { return true; }

// smoke from large fires or burning oil accumulates at half the rate listed
// for enclosed areas in a subtly ventilated area.
inline int dnaVentSubtleLargeSmokeDiv()
    { return 2; }

// an area with no visible ventilation but connected to ventilated areas or
// the surface collects small-fire smoke at half the rate.
inline int dnaVentConnectedSmallSmokeDiv()
    { return 2; }

// large or oil fires fill such a connected area with smoke at the usual rate.
inline bool dnaVentConnectedLargeSmokeNormal()
    { return true; }

// characters do not use up all the air through breathing in a connected area
// - even minimal ventilation allows enough air movement for respiration.
inline bool dnaVentConnectedBreathNeverExhausts()
    { return true; }

// poisonous or noxious gases remain in a connected area for 2-5 hours
// (1d4+1): the minimum.
inline int dnaVentConnectedGasMinHours()
    { return 2; }

// the 2-5 hour connected-area gas duration: the maximum.
inline int dnaVentConnectedGasMaxHours()
    { return 5; }

// the duration of all gas-based spells is normal in a connected area.
inline bool dnaVentConnectedSpellsNormal()
    { return true; }

// an area with no noticeable ventilation and no outflow captures smoke at the
// normal rate, even from small fires.
inline bool dnaVentNoneSmallSmokeNormal()
    { return true; }

// poisonous or noxious gases remain in an unventilated area for a full 24
// hours.
inline int dnaVentNoneGasHours()
    { return 24; }

// the 24-hour figure holds unless the gas is specifically noted as heavier
// than air.
inline bool dnaVentNoneHeavierThanAirException()
    { return true; }

// an area completely sealed off (by cave-ins, mortared stone walls, or walls
// of force) has a finite air supply that once used up can only be replaced by
// introduced fresh air.
inline bool dnaSealedAirFinite()
    { return true; }

// in a sealed area all of the effects apply at their normal rates of
// accumulation and effect.
inline bool dnaSealedEffectsNormalRates()
    { return true; }

// smoke that collects in a sealed room lingers for 1d6 hours after the fire
// that created it goes out.
inline int dnaSealedSmokeLingerDie()
    { return 6; }

// poisonous or noxious gases remain in a sealed area until vented out by the
// admission of fresh air.
inline bool dnaSealedGasUntilVented()
    { return true; }

// the duration of all gas-based spells is normal in a sealed area.
inline bool dnaSealedSpellsNormal()
    { return true; }

}   // namespace rules
