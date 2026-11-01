-- oa693: promoted from rules/oamethods.h (the OA PRINCIPAL METHODS, printed capture pp. 228-232 - the eight method);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 693,
  "prefix" = "oa693",
  "banner" = {
      "title" = "OA PRINCIPAL METHODS, printed capture pp. 228-232 - the eight method",
      "provenance" = "descriptions round census 615 -> 616.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. KICK: the Circle Kick twice damage on the spin with the next attack lost on a miss; the Flying Kick the triple damage of the five-foot run, the miss dropping the fighter prone unless Prone Fighting or Instant Stand; the Backward Kick behind without facing, its miss harmless. LOCK: the gripping art - the Choke Hold with its -2 escape attempts per attack and the 1-3 round unconsciousness; the Locking Block scissors trap with the feet-only +4 and the weapon-recoil on a miss; the Incapacitator double damage and the 24-hour useless limb before the save vs. paralyzation; the Immobilizing one-hand hold with the -6 escape and the -4 next-attack on a miss. MOVEMENT: the Feint +2 for the next attack; the Prone Fighting constant, Instant Stand alone beside it; the Immovability auto-save; the Missile Deflection save per attack, awareness required; the Leap with its standing 4/3 and running 8/10 springs plus a foot per level, one attack the cost; the Speed doubling attacks and the combat movement alone, once per day, five rounds, then rest; the Slow Resistance automatic. PUSH: the soft protective force - the Concentrated Push a foot per level, the three-foot save threshold, the fall damage into a solid object, the +2 against the character on a miss; the Sticking Touch +2 to hit and AC 2 better; the One Finger push at one foot per level, the only action of the round. STRIKE: the Iron Fist 1d10; the Crushing Blow of the half-foot wood and quarter-foot stone per level, normal damage plus level against the living, the hurt hand on a missed hard object; the Eagle Claw 3d10 - the OCR artifact 3410 resolved - snapping shafts and crushing metal. THROW: the constant Fall at half damage; the Instant Stand in place of an attack; the Hurl 1d4 feet and double damage, the miss costing attacks and initiative; the Great Throw one foot per level standing, six plus a foot per level against a charge, triple damage. VITAL AREA: human and humanoid only - the Pain Touch with its -2/+2 for 1-3 rounds, no damage; the Stunning Touch 1d4 rounds before the save; the Paralyzing Touch 1d6 turns before the save; the Distance Death pool-side mastery, the Pain unsavable and the Stunning saved at -2, or the triple damage, one foot per level. WEAPON: the martial-arts-exclusive weapons only - the Weapon Catch lock and +2 with the disarm on a miss; the Weapon Breaker against melee weapons alone, the save vs. crushing blow, the bo stick vs the sword; the Steel Cloth 6-10 feet rigid as a spear that cannot be thrown, automatic. The grid mechanics codified per the R431 calculus  the gap census after this round: 146 closed, 89 open - the Principal Methods box flips (census 615 -> 616); NEXT - R694: the Mental and Physical Training with Stunning and Incapacitating prose (capture pp. 232-233), prefix djh (verify free at the landing), audit \"R694 OA mental and physical training audit\", include after rules/oamethods.h",
    },
  "consts" = { {
      "name" = "djgCircleKickDmgX",
      "value" = 2,
      "comment" = "the Circle Kick damage multiple - a successful hit does twice normal damage, the failed kick losing the next attack as the character recovers his balance (print capture p. 228)",
    }, {
      "name" = "djgFlyingKickDmgX",
      "value" = 3,
      "comment" = "the Flying Kick damage multiple - a connected kick does triple normal damage (print capture p. 228)",
    }, {
      "name" = "djgFlyingKickRunFt",
      "value" = 5,
      "comment" = "the Flying Kick running space - at least five feet needed to leap high and lead with the kick to the head, a miss dropping the character prone for a round unless he has Prone Fighting or Instant Stand (print capture p. 228)",
    }, {
      "name" = "djgChokeHoldEscapeMod",
      "value" = 2,
      "comment" = "the Choke Hold escape modifier - the victim's to hit roll at -2 on the die, one attempt per attack he has, a failed escape meaning unconsciousness at the end of the round (print capture p. 228)",
    }, {
      "name" = "djgChokeHoldUnconRounds",
      "value" = 3,
      "comment" = "the Choke Hold unconsciousness - 1-3 rounds once the escape attempts fail, the hold applied the round before with no other action (print capture p. 228)",
    }, {
      "name" = "djgLockingBlockHitBonus",
      "value" = 4,
      "comment" = "the Locking Block hit bonus - so long as the victim is trapped the character attacks with the feet only at +4 on his chance to hit, the block itself doing no damage (print capture p. 228)",
    }, {
      "name" = "djgIncapacLimbHours",
      "value" = 24,
      "comment" = "the Incapacitator limb duration - one finger, arm or leg useless for 24 hours, the attack doing double normal damage, the victim allowed a saving throw vs. paralyzation to negate (print capture p. 228)",
    }, {
      "name" = "djgImmobilizingEscapeMod",
      "value" = 6,
      "comment" = "the Immobilizing escape modifier - the victim spends a melee attack to break the hold with a -6 on the die roll, the lock itself doing no damage (print capture p. 229)",
    }, {
      "name" = "djgImmobilizingFailMod",
      "value" = 4,
      "comment" = "the Immobilizing failure penalty - an unsuccessful lock leaving a -4 on the character's next attack (print capture p. 229)",
    }, {
      "name" = "djgFeintHitBonus",
      "value" = 2,
      "comment" = "the Feint hit bonus - the feint costs one melee attack and does no damage, a successful feint giving a +2 on the character's NEXT attack (print capture p. 229)",
    }, {
      "name" = "djgLeapStandUpFt",
      "value" = 4,
      "comment" = "the Leap standing spring - four feet into the air from a standing start (print capture p. 229)",
    }, {
      "name" = "djgLeapStandFwdFt",
      "value" = 3,
      "comment" = "the Leap standing spring - three feet forward from a standing start (print capture p. 229)",
    }, {
      "name" = "djgLeapRunUpFt",
      "value" = 8,
      "comment" = "the Leap running spring - eight feet upward from a running start (print capture p. 229)",
    }, {
      "name" = "djgLeapRunFwdFt",
      "value" = 10,
      "comment" = "the Leap running spring - ten feet forward from a running start (print capture p. 229)",
    }, {
      "name" = "djgLeapPerLevelFt",
      "value" = 1,
      "comment" = "the Leap per-level bonus - one extra foot up and forward per level of the character, both springs (print capture p. 229)",
    }, {
      "name" = "djgLeapRunSpaceFt",
      "value" = 10,
      "comment" = "the Leap running space - at least ten feet needed for the running spring, the leap costing one attack and needing a to hit roll to land safely (print capture p. 229)",
    }, {
      "name" = "djgSpeedMaxRounds",
      "value" = 5,
      "comment" = "the Speed duration - twice the normal melee attacks and double the combat movement rate, maintained at most five rounds, once per day (print capture p. 229)",
    }, {
      "name" = "djgSpeedRestRounds",
      "value" = 3,
      "comment" = "the Speed rest - 1-3 rounds of rest owed at the end of the five rounds, the doubled movement applying to the combat rate only (print capture p. 229)",
    }, {
      "name" = "djgConcPushPerLevelFt",
      "value" = 1,
      "comment" = "the Concentrated Push knockback - one foot per level on a successful hit, a distance past three feet forcing a save vs. paralyzation to stay on foot (print capture p. 230)",
    }, {
      "name" = "djgConcPushSaveFt",
      "value" = 3,
      "comment" = "the Concentrated Push save threshold - only a knockback greater than three feet forces the saving throw vs. paralyzation, a solid object hit causing fall damage for the distance (print capture p. 230)",
    }, {
      "name" = "djgConcPushFailBonus",
      "value" = 2,
      "comment" = "the Concentrated Push failure - all attacks against the character gain +2 for the remainder of the round, Immovability resisting the push (print capture p. 230)",
    }, {
      "name" = "djgStickingTouchHitBonus",
      "value" = 2,
      "comment" = "the Sticking Touch hit bonus - +2 on all subsequent to hit rolls while contact is kept (print capture p. 230)",
    }, {
      "name" = "djgStickingTouchACBonus",
      "value" = 2,
      "comment" = "the Sticking Touch armor class - the AC improves by 2 while contact is kept, the touch itself doing no damage (print capture p. 230)",
    }, {
      "name" = "djgOneFingerPerLevelFt",
      "value" = 1,
      "comment" = "the One Finger range - the Concentrated Push effect without touching, one foot per level, the only action of the melee round (print capture p. 230)",
    }, {
      "name" = "djgIronFistDie",
      "value" = 10,
      "comment" = "the Iron Fist damage - 1d10 per attack when the hands are the principal body part, otherwise 1d10 on one attack per melee round (print capture p. 230)",
    }, {
      "name" = "djgCrushWoodPerLvIn",
      "value" = 6,
      "comment" = "the Crushing Blow wood - half a foot (six inches) of wood broken per level, ceramics and masonry but not metal (print capture p. 230)",
    }, {
      "name" = "djgCrushStonePerLvIn",
      "value" = 3,
      "comment" = "the Crushing Blow brittle stone - a quarter foot (three inches) broken per level, a living target taking normal damage plus points equal to the level (print capture p. 230)",
    }, {
      "name" = "djgEagleClawDice",
      "value" = 3,
      "comment" = "the Eagle Claw damage dice - 3d10 on the attack, the OCR artifact 3410 resolved as 3d10 (the shattering, the crushed metal, the only action of the round) (print capture p. 231)",
    }, {
      "name" = "djgEagleClawDie",
      "value" = 10,
      "comment" = "the Eagle Claw damage die - the d10 of the 3d10, snap spear shafts and crush stones and metal items (print capture p. 231)",
    }, {
      "name" = "djgFallDamageDiv",
      "value" = 2,
      "comment" = "the Fall damage divisor - half the normal damage from any fall, the maneuver constant once learned (print capture p. 231)",
    }, {
      "name" = "djgHurlDistanceDie",
      "value" = 4,
      "comment" = "the Hurl distance - the opponent thrown 1d4 feet away with double damage, Immovability resisting (print capture p. 231)",
    }, {
      "name" = "djgGreatThrowChargeFt",
      "value" = 6,
      "comment" = "the Great Throw vs a charge - six feet plus one per level thrown, a stationary victim but one foot per level (print capture p. 231)",
    }, {
      "name" = "djgGreatThrowDmgX",
      "value" = 3,
      "comment" = "the Great Throw damage - triple normal damage from the throw (print capture p. 231)",
    }, {
      "name" = "djgPainTouchMod",
      "value" = 2,
      "comment" = "the Pain Touch modifiers - the victim at -2 on his chance to hit and +2 on chance of being hit, the touch itself doing no damage (print capture p. 231)",
    }, {
      "name" = "djgPainTouchRounds",
      "value" = 3,
      "comment" = "the Pain Touch duration - the effect lasts 1-3 rounds, no adverse effect on a missed roll (print capture p. 231)",
    }, {
      "name" = "djgStunTouchDie",
      "value" = 4,
      "comment" = "the Stunning Touch duration - a failed save vs. paralyzation stuns the victim for 1d4 rounds, unable to take any action, no damage done (print capture p. 231)",
    }, {
      "name" = "djgParalyzeTouchDie",
      "value" = 6,
      "comment" = "the Paralyzing Touch duration - the victim paralyzed and unable to move for 1d6 turns, the save vs. paralyzation negating, no damage done (print capture p. 231)",
    }, {
      "name" = "djgDistDeathDmgX",
      "value" = 3,
      "comment" = "the Distance Death damage choice - three times the normal damage, or the Pain, Stunning or Paralyzing Touch effect at the range of one foot per level, the only action of the round (print capture p. 232)",
    }, {
      "name" = "djgDistDeathStunSaveMod",
      "value" = 2,
      "comment" = "the Distance Death saving throws - Pain allows NO save, Stunning is saved at -2 on the die, Paralyzing normally (print capture p. 232)",
    }, {
      "name" = "djgWeaponCatchHitBonus",
      "value" = 2,
      "comment" = "the Weapon Catch hit bonus - the further attacks at +2 so long as the caught weapon is locked and the correct principal body part is free (print capture p. 232)",
    }, {
      "name" = "djgSteelClothMinFt",
      "value" = 6,
      "comment" = "the Steel Cloth length minimum - a six foot piece of cloth (print capture p. 232)",
    }, {
      "name" = "djgSteelClothMaxFt",
      "value" = 10,
      "comment" = "the Steel Cloth length maximum - a ten foot piece of cloth, whirled and snapped tight to the rigidity of a spear that cannot be thrown (print capture p. 232)",
    } },
  "bools" = { {
      "name" = "djgCircleKickFailNextLost",
      "value" = true,
      "comment" = "the failed Circle Kick - the character loses the next attack he is normally allowed, recovering his balance (print capture p. 228)",
    }, {
      "name" = "djgFlyingKickMissFall",
      "value" = true,
      "comment" = "the failed Flying Kick - the character falls to the ground adjacent to the target and spends a round regaining his feet unless he also has Prone Fighting or Instant Stand (print capture p. 228)",
    }, {
      "name" = "djgBackwardNoFacing",
      "value" = true,
      "comment" = "the Backward Kick - the attack on a creature directly behind without turning to face it, foot over and behind the head or lashing straight backward (print capture p. 228)",
    }, {
      "name" = "djgBackwardMissSafe",
      "value" = true,
      "comment" = "the Backward Kick failure - a failed attempt has no ill effects, the kick doing normal damage (print capture p. 228)",
    }, {
      "name" = "djgChokeHoldNextRoundGrip",
      "value" = true,
      "comment" = "the Choke Hold application - no attacks the round of gripping and holding, the hold maintained to the end of the next melee round (print capture p. 228)",
    }, {
      "name" = "djgChokeHoldEscapesPerAttacks",
      "value" = true,
      "comment" = "the Choke Hold escape - one attempt per attack the victim has, each a to hit roll at -2 (print capture p. 228)",
    }, {
      "name" = "djgLockingBlockNoDamage",
      "value" = true,
      "comment" = "the Locking Block - traps the weapon, arm or leg in a scissors arm-lock, does no damage, usable against unarmed fighters or melee weapon attacks (print capture p. 228)",
    }, {
      "name" = "djgLockingBlockFailWeaponHurt",
      "value" = true,
      "comment" = "the failed Locking Block vs a weapon - the character takes damage from the weapon he tried to trap; vs an unarmed fighter the loss is only the spent attack (print capture p. 228)",
    }, {
      "name" = "djgIncapacDoubleDamage",
      "value" = true,
      "comment" = "the Incapacitator - double normal damage by gripping and twisting the joints, the limb useless 24 hours (print capture p. 228)",
    }, {
      "name" = "djgIncapacSavePara",
      "value" = true,
      "comment" = "the Incapacitator save - the victim is allowed a saving throw vs. paralyzation, a made save meaning the attack fails (print capture p. 228)",
    }, {
      "name" = "djgImmobilOneHand",
      "value" = true,
      "comment" = "the Immobilizing - one hand holds the victim while the character still attacks with the feet or the other hand, even locking another victim (print capture p. 229)",
    }, {
      "name" = "djgFeintNoDamage",
      "value" = true,
      "comment" = "the Feint - begins the attack one direction, switches at the last minute, the feint itself does no damage, no penalty on a miss beyond the spent attack (print capture p. 229)",
    }, {
      "name" = "djgProneOnlyInstantStand",
      "value" = true,
      "comment" = "the Prone Fighting - constant, effective fighting from the ground, but no other special maneuver (except Instant Stand) when prone (print capture p. 229)",
    }, {
      "name" = "djgImmovabilityAutoSave",
      "value" = true,
      "comment" = "the Immovability - any time a knock, lift or throw would occur an automatic save vs. paralyzation, a success meaning the character stays where he is (print capture p. 229)",
    }, {
      "name" = "djgMissileDeflectNonmagical",
      "value" = true,
      "comment" = "the Missile Deflection - the nonmagical missile attacks (arrows and bolts included) dodged on a save vs. paralyzation per attack (print capture p. 229)",
    }, {
      "name" = "djgMissileDeflectAwareOnly",
      "value" = true,
      "comment" = "the Missile Deflection awareness - the character must be aware of the attack, the ability otherwise constant (print capture p. 229)",
    }, {
      "name" = "djgLeapCostsOneAttack",
      "value" = true,
      "comment" = "the Leap - costs one attack of the round rather than the whole round, a to hit roll to land safely, a failed roll meaning the leap completes but the character falls on landing (print capture p. 229)",
    }, {
      "name" = "djgSpeedDoubleAttacks",
      "value" = true,
      "comment" = "the Speed - twice the normal melee attacks, martial arts and normal combat both (print capture p. 229)",
    }, {
      "name" = "djgSpeedDoubleCombatMove",
      "value" = true,
      "comment" = "the Speed movement - double the combat movement rate only, never normal movement (print capture p. 229)",
    }, {
      "name" = "djgSpeedOncePerDay",
      "value" = true,
      "comment" = "the Speed fatigue - usable once per day, maintained at most five rounds, then 1-3 rounds of rest (print capture p. 229)",
    }, {
      "name" = "djgSlowResistAutoImmune",
      "value" = true,
      "comment" = "the Slow Resistance - automatic immunity to slow effects (print capture p. 230)",
    }, {
      "name" = "djgConcPushImmovResist",
      "value" = true,
      "comment" = "the Concentrated Push resisted - those with Immovability can resist being knocked back (print capture p. 230)",
    }, {
      "name" = "djgConcPushFallDamage",
      "value" = true,
      "comment" = "the Concentrated Push into an object - a victim hitting a solid object suffers damage as if he had fallen the same distance (print capture p. 230)",
    }, {
      "name" = "djgStickingTouchNoDamage",
      "value" = true,
      "comment" = "the Sticking Touch - a to hit roll, no damage, the contact kept until the opponent moves beyond the character's abilities (the Leap example) (print capture p. 230)",
    }, {
      "name" = "djgOneFingerOnlyAction",
      "value" = true,
      "comment" = "the One Finger concentration - the only action the character can take in the melee round regardless of attacks, a miss having no effect (print capture p. 230)",
    }, {
      "name" = "djgIronFistHandsRule",
      "value" = true,
      "comment" = "the Iron Fist rule - 1d10 per attack if the hands are the principal body part, otherwise 1d10 on one attack per melee round (print capture p. 230)",
    }, {
      "name" = "djgCrushBlowOnlyAction",
      "value" = true,
      "comment" = "the Crushing Blow concentration - the only action of the round regardless of attacks normally allowed (print capture p. 230)",
    }, {
      "name" = "djgCrushBlowMissHurtsHand",
      "value" = true,
      "comment" = "the failed Crushing Blow on a hard object - the hand seriously hurt, the character suffers his own normal damage and the hand is unusable for 24 hours (print capture p. 231)",
    }, {
      "name" = "djgEagleClawOnlyAction",
      "value" = true,
      "comment" = "the Eagle Claw concentration - the only action the character can take during the round (print capture p. 231)",
    }, {
      "name" = "djgFallConstant",
      "value" = true,
      "comment" = "the Fall - the first maneuver learned, constant thereafter, the impact taken on the safest areas (print capture p. 231)",
    }, {
      "name" = "djgInstantStandAuto",
      "value" = true,
      "comment" = "the Instant Stand - the feet regained automatically instead of making an attack, other actions allowed if attacks remain (print capture p. 231)",
    }, {
      "name" = "djgHurlDoubleDamage",
      "value" = true,
      "comment" = "the Hurl - strength over leverage, the victim double damaged, thrown 1d4 feet (print capture p. 231)",
    }, {
      "name" = "djgHurlMissCost",
      "value" = true,
      "comment" = "the failed Hurl - all remaining attacks lost for the round and initiative automatically lost the next round (print capture p. 231)",
    }, {
      "name" = "djgGreatThrowMissKnock",
      "value" = true,
      "comment" = "the failed Great Throw - the move countered, the character knocked off his feet and automatically losing initiative the next round (print capture p. 231)",
    }, {
      "name" = "djgVitalHumanoidOnly",
      "value" = true,
      "comment" = "the Vital Area training - anatomy learned, the maneuvers usable only against human and humanoid opponents (print capture p. 231)",
    }, {
      "name" = "djgPainTouchNoDamage",
      "value" = true,
      "comment" = "the Pain Touch - pressed finger points, no damage, done in place of a normal attack (print capture p. 231)",
    }, {
      "name" = "djgStunTouchSavePara",
      "value" = true,
      "comment" = "the Stunning Touch - the victim allowed a save vs. paralyzation, a passed save or missed roll meaning no effect (print capture p. 231)",
    }, {
      "name" = "djgParalyzeTouchSavePara",
      "value" = true,
      "comment" = "the Paralyzing Touch - the nerve junctions pressed, the victim allowed a save vs. paralyzation, a failed attack or made save meaning no damage (print capture p. 231)",
    }, {
      "name" = "djgDistDeathPainNoSave",
      "value" = true,
      "comment" = "the Distance Death - Pain chosen denies the victim any saving throw, Stunning is saved at -2 (print capture p. 232)",
    }, {
      "name" = "djgWeaponCatchLock",
      "value" = true,
      "comment" = "the Weapon Catch - the caught weapon or limb locked and unusable to fight with, the catch made in place of a normal attack (print capture p. 232)",
    }, {
      "name" = "djgWeaponCatchBreakOptions",
      "value" = true,
      "comment" = "the Weapon Catch break - the opponent drops his weapon or spends a melee attack on a to hit roll to break free (print capture p. 232)",
    }, {
      "name" = "djgWeaponCatchMissDisarm",
      "value" = true,
      "comment" = "the failed Weapon Catch - the character's own weapon fouled and pulled from his grasp, leaving him disarmed (print capture p. 232)",
    }, {
      "name" = "djgWeaponBreakerMeleeOnly",
      "value" = true,
      "comment" = "the Weapon Breaker - only against melee weapons, never unarmed fighters, the bo stick vs a sword included (print capture p. 232)",
    }, {
      "name" = "djgWeaponBreakerSaveCrush",
      "value" = true,
      "comment" = "the Weapon Breaker - the opponent's weapon must save vs. crushing blow or be broken, the maneuver doing no damage (print capture p. 232)",
    }, {
      "name" = "djgSteelClothSpearLike",
      "value" = true,
      "comment" = "the Steel Cloth - the cloth treated as a spear except it cannot be thrown (print capture p. 232)",
    }, {
      "name" = "djgSteelClothAutomatic",
      "value" = true,
      "comment" = "the Steel Cloth - automatic, no die roll made for success, the weapon never absent (print capture p. 232)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djgCircleKickDmgX']() != 2  or m['djgFlyingKickDmgX']() != 3  or m['djgFlyingKickRunFt']() != 5  or m['djgChokeHoldEscapeMod']() != 2  or m['djgChokeHoldUnconRounds']() != 3  or m['djgLockingBlockHitBonus']() != 4  or m['djgIncapacLimbHours']() != 24  or m['djgImmobilizingEscapeMod']() != 6  or m['djgImmobilizingFailMod']() != 4  or m['djgFeintHitBonus']() != 2  or m['djgLeapStandUpFt']() != 4  or m['djgLeapStandFwdFt']() != 3  or m['djgLeapRunUpFt']() != 8  or m['djgLeapRunFwdFt']() != 10  or m['djgLeapPerLevelFt']() != 1  or m['djgLeapRunSpaceFt']() != 10  or m['djgSpeedMaxRounds']() != 5  or m['djgSpeedRestRounds']() != 3  or m['djgConcPushPerLevelFt']() != 1  or m['djgConcPushSaveFt']() != 3  or m['djgConcPushFailBonus']() != 2  or m['djgStickingTouchHitBonus']() != 2  or m['djgStickingTouchACBonus']() != 2  or m['djgOneFingerPerLevelFt']() != 1  or m['djgIronFistDie']() != 10  or m['djgCrushWoodPerLvIn']() != 6  or m['djgCrushStonePerLvIn']() != 3  or m['djgEagleClawDice']() != 3  or m['djgEagleClawDie']() != 10  or m['djgFallDamageDiv']() != 2  or m['djgHurlDistanceDie']() != 4  or m['djgGreatThrowChargeFt']() != 6  or m['djgGreatThrowDmgX']() != 3  or m['djgPainTouchMod']() != 2  or m['djgPainTouchRounds']() != 3  or m['djgStunTouchDie']() != 4  or m['djgParalyzeTouchDie']() != 6  or m['djgDistDeathDmgX']() != 3  or m['djgDistDeathStunSaveMod']() != 2  or m['djgWeaponCatchHitBonus']() != 2  or m['djgSteelClothMinFt']() != 6  or m['djgSteelClothMaxFt']() != 10  or  m['djgCircleKickFailNextLost']() != 1  or  m['djgFlyingKickMissFall']() != 1  or  m['djgBackwardNoFacing']() != 1  or  m['djgBackwardMissSafe']() != 1  or  m['djgChokeHoldNextRoundGrip']() != 1  or  m['djgChokeHoldEscapesPerAttacks']() != 1  or  m['djgLockingBlockNoDamage']() != 1  or  m['djgLockingBlockFailWeaponHurt']() != 1  or  m['djgIncapacDoubleDamage']() != 1  or  m['djgIncapacSavePara']() != 1  or  m['djgImmobilOneHand']() != 1  or  m['djgFeintNoDamage']() != 1  or  m['djgProneOnlyInstantStand']() != 1  or  m['djgImmovabilityAutoSave']() != 1  or  m['djgMissileDeflectNonmagical']() != 1  or  m['djgMissileDeflectAwareOnly']() != 1  or  m['djgLeapCostsOneAttack']() != 1  or  m['djgSpeedDoubleAttacks']() != 1  or  m['djgSpeedDoubleCombatMove']() != 1  or  m['djgSpeedOncePerDay']() != 1  or  m['djgSlowResistAutoImmune']() != 1  or  m['djgConcPushImmovResist']() != 1  or  m['djgConcPushFallDamage']() != 1  or  m['djgStickingTouchNoDamage']() != 1  or  m['djgOneFingerOnlyAction']() != 1  or  m['djgIronFistHandsRule']() != 1  or  m['djgCrushBlowOnlyAction']() != 1  or  m['djgCrushBlowMissHurtsHand']() != 1  or  m['djgEagleClawOnlyAction']() != 1  or  m['djgFallConstant']() != 1  or  m['djgInstantStandAuto']() != 1  or  m['djgHurlDoubleDamage']() != 1  or  m['djgHurlMissCost']() != 1  or  m['djgGreatThrowMissKnock']() != 1  or  m['djgVitalHumanoidOnly']() != 1  or  m['djgPainTouchNoDamage']() != 1  or  m['djgStunTouchSavePara']() != 1  or  m['djgParalyzeTouchSavePara']() != 1  or  m['djgDistDeathPainNoSave']() != 1  or  m['djgWeaponCatchLock']() != 1  or  m['djgWeaponCatchBreakOptions']() != 1  or  m['djgWeaponCatchMissDisarm']() != 1  or  m['djgWeaponBreakerMeleeOnly']() != 1  or  m['djgWeaponBreakerSaveCrush']() != 1  or  m['djgSteelClothSpearLike']() != 1  or  m['djgSteelClothAutomatic']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djgCircleKickDmgX']() != 2  or m['djgFlyingKickDmgX']() != 3  or m['djgFlyingKickRunFt']() != 5",
      "note" = "the kick damage - Circle Kick double, Flying Kick triple of the five-foot run",
    }, {
      "expr" = "m['djgChokeHoldEscapeMod']() != 2  or m['djgLockingBlockHitBonus']() != 4  or m['djgImmobilizingEscapeMod']() != 6  or m['djgImmobilizingFailMod']() != 4  or m['djgIncapacLimbHours']() != 24  or m['djgChokeHoldUnconRounds']() != 3",
      "note" = "the lock modifiers - the choke -2 escape, the +4 feet-only block, the -6 immobilizing escape and its -4 miss",
    }, {
      "expr" = "m['djgFeintHitBonus']() != 2  or m['djgLeapStandUpFt']() != 4  or m['djgLeapStandFwdFt']() != 3  or m['djgLeapRunUpFt']() != 8  or m['djgLeapRunFwdFt']() != 10  or m['djgLeapPerLevelFt']() != 1  or m['djgLeapRunSpaceFt']() != 10",
      "note" = "the movement numbers - the feint +2, the standing leap 4 up 3 forward, the running leap 8 up 10 forward",
    }, {
      "expr" = "m['djgSpeedMaxRounds']() != 5  or m['djgSpeedRestRounds']() != 3  or m['djgConcPushPerLevelFt']() != 1  or m['djgConcPushSaveFt']() != 3  or m['djgConcPushFailBonus']() != 2  or m['djgStickingTouchHitBonus']() != 2  or m['djgStickingTouchACBonus']() != 2  or m['djgOneFingerPerLevelFt']() != 1",
      "note" = "the speed and the push - five rounds once a day, the push a foot per level with the three-foot save, the sticking +2 and 2, one finger a foot per level",
    }, {
      "expr" = "m['djgIronFistDie']() != 10  or m['djgCrushWoodPerLvIn']() != 6  or m['djgCrushStonePerLvIn']() != 3  or m['djgEagleClawDice']() != 3  or m['djgEagleClawDie']() != 10",
      "note" = "the strike - the iron fist 1d10, the six-inch wood and three-inch stone per level, the eagle claw 3d10",
    }, {
      "expr" = "m['djgFallDamageDiv']() != 2  or m['djgHurlDistanceDie']() != 4  or m['djgGreatThrowChargeFt']() != 6  or m['djgGreatThrowDmgX']() != 3",
      "note" = "the throw - the fall halved, the hurl 1d4 feet, the great throw six feet on a charge and triple damage",
    }, {
      "expr" = "m['djgPainTouchMod']() != 2  or m['djgPainTouchRounds']() != 3  or m['djgStunTouchDie']() != 4  or m['djgParalyzeTouchDie']() != 6  or m['djgDistDeathDmgX']() != 3  or m['djgDistDeathStunSaveMod']() != 2",
      "note" = "the vital area - the pain -2/+2 for 1-3 rounds, the stun 1d4, the paralyze 1d6, the distance death triple or the -2 stunning save",
    }, {
      "expr" = "m['djgWeaponCatchHitBonus']() != 2  or m['djgSteelClothMinFt']() != 6  or m['djgSteelClothMaxFt']() != 10",
      "note" = "the weapon - the catch +2, the cloth 6 to 10 feet",
    } },
  "audit" = {
      "label" = "R693 OA principal methods audit",
      "comment" = "OA round eighty (capture pp. 228-232): the Principal Methods prose - the eight method descriptions behind the Table 70 grid, the maneuver mechanics across kick, lock, movement, push, strike, throw, vital area and weapon, single-pass pins per the Chapter 9 provenance shift",
    },
}
