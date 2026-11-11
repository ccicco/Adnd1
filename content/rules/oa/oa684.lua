-- oa684: promoted from rules/oa/oaunhorsing.h (the OA UNHORSING, printed capture pp. 220-221 - the dismount doctrine round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 684,
  "prefix" = "oa684",
  "banner" = {
      "title" = "OA UNHORSING, printed capture pp. 220-221 - the dismount doctrine round",
      "provenance" = "census 606 -> 607.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE DOCTRINE: the horseman important and formidable, the foot soldier's goal to get him off his horse - once downed the lone warrior outnumbered and overpowered. THE SLAIN MOUNT: the rider automatically on foot, the horse lost as a prize, the kill a last resort. THE MOUNTED UNHORSING: a natural 20 on 1d20 from a 3-or-more-feet melee weapon of another mounted character - without horsemanship the automatic fall with the extra 1d3, with it the proficiency check. THE FOOT SOLDIER: the 5-to-9-feet band the same chance as mounted, the 10-or-more-feet the 25 percent 16-20 on 1d20. THE GRAPPLE: the dive-on with the to hit roll, the failed check dropping both for the 1d6 each, the hang-on state with the every-turn re-roll and the -2 rider penalty. THE FOOTMAN PULL: the man-sized gate, the -2/-4/-6 speed ladder of the grab, the -1 per extra footman to 4, the eight-men surround, the free attacks above 12 feet. THE SET DEFENSES: the stake line - the 2d6 per stake, the 1d4-1 per 10 feet of depth, the barding reductions, the jump check. The prose codifies per the R431 calculus  the gap census after this round: 137 closed, 98 open - the Unhorsing box flips (census 606 -> 607); NEXT - R685: the Disarming doctrine (capture p. 221), prefix diy (verify free at the landing - diu, div, diw and dix TAKEN by the R681-R684 call families), audit \"R685 OA disarming audit\", include after rules/oa/oaunhorsing.h",
    },
  "consts" = { {
      "name" = "dixOAUnhorseMountedWeaponMinFeet",
      "value" = 3,
      "comment" = "the mounted unhorsing weapon floor - anytime a rider is struck by a melee weapon of 3 feet or greater length wielded by another mounted character with a natural 20 on 1d20, there is a chance the struck rider is knocked from his mount (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseFallDamageDice",
      "value" = 3,
      "comment" = "the unhorsed fall damage - the rider without horsemanship proficiency automatically falling to the ground suffering an additional 1d3 of damage; a failed proficiency check carrying the same (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseFootShortMinFeet",
      "value" = 5,
      "comment" = "the foot-soldier short band floor - foot soldiers using melee weapons of 5 to 9 feet in length having the same chance as a mounted attacker of unhorsing a rider (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseFootShortMaxFeet",
      "value" = 9,
      "comment" = "the foot-soldier short band ceiling - the 5 to 9 feet weapon band with the same unhorsing chance as a mounted attacker (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseFootLongMinFeet",
      "value" = 10,
      "comment" = "the foot-soldier long band floor - foot soldiers using weapons of 10 feet or greater length having a 25 percent chance of dismounting the rider (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseLongChancePercent",
      "value" = 25,
      "comment" = "the long-weapon dismount chance - the 25 percent of the 10-or-more-feet foot-soldier unhorsing, the 16-20 on 1d20 (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseLongRollMin",
      "value" = 16,
      "comment" = "the long-weapon dismount roll floor - the 16 of the 16-20 on 1d20 unhorsing roll of the 10-or-more-feet foot-soldier band (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseGrappleFallDamageDice",
      "value" = 6,
      "comment" = "the grapple fall damage - the failed grapple-check rider and the diving grappler both falling to the ground, each suffering 1d6 points of damage (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseGrappleRiderHitPenalty",
      "value" = -2,
      "comment" = "the grappled rider penalty - the rider using a weapon to strike at his grappling opponent is -2 on his chance to hit (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorsePullSpeed6Penalty",
      "value" = -2,
      "comment" = "the footman pull penalty at the slowest band - the horse moving 6 feet or less, the footman's grab chance reduced by -2 (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorsePullSpeed7Penalty",
      "value" = -4,
      "comment" = "the footman pull penalty at the middle band - the horse moving 7 to 12 feet, the footman's grab chance reduced by -4 (print capture p. 221)",
    }, {
      "name" = "dixOAUnhorsePullSpeed13Penalty",
      "value" = -6,
      "comment" = "the footman pull penalty at the fastest band - the horse moving greater than 12 feet, the footman's grab chance reduced by -6 (print capture p. 221)",
    }, {
      "name" = "dixOAUnhorsePullExtraFootmanPenalty",
      "value" = -1,
      "comment" = "the multi-footman pull penalty - for each additional footman grappling up to 4, -1 applied to the proficiency check (print capture p. 221)",
    }, {
      "name" = "dixOAUnhorsePullMaxFootmen",
      "value" = 4,
      "comment" = "the multi-footman pull cap - the additional footmen grappling up to 4, each applying -1 to the proficiency check (print capture p. 221)",
    }, {
      "name" = "dixOAUnhorseSurroundMen",
      "value" = 8,
      "comment" = "the surround rule - if a horse can be surrounded by eight men, they can pull both the horse and rider down (print capture p. 221)",
    }, {
      "name" = "dixOAStakesPrepMen",
      "value" = 2,
      "comment" = "the stake defense preparation - it takes two men an hour to prepare a 10-foot-square area with stakes of about 4 to 5 feet of length, given a supply of bamboo or light wood (print capture p. 221)",
    }, {
      "name" = "dixOAStakesPrepAreaFeet",
      "value" = 10,
      "comment" = "the stake defense area - the 10-foot-square prepared area of sharpened stakes set against horse attack (print capture p. 221)",
    }, {
      "name" = "dixOAStakesLengthMinFeet",
      "value" = 4,
      "comment" = "the stake length floor - the stakes of about 4 to 5 feet of length set against horse attack (print capture p. 221)",
    }, {
      "name" = "dixOAStakesLengthMaxFeet",
      "value" = 5,
      "comment" = "the stake length ceiling - the stakes of about 4 to 5 feet of length set against horse attack (print capture p. 221)",
    }, {
      "name" = "dixOAStakesDamageDice",
      "value" = 6,
      "comment" = "the stake damage - each stake causing 2d6 points of damage to the horse, the number hit rolling 1d4-1 per 10 feet of barrier depth (print capture p. 221)",
    }, {
      "name" = "dixOAStakesChainReduction",
      "value" = 1,
      "comment" = "the barding stake reduction - chain barding reducing the number of stakes which hit by -1 (print capture p. 221)",
    }, {
      "name" = "dixOAStakesPlateReduction",
      "value" = 2,
      "comment" = "the plate barding stake reduction - plate barding reducing the number of stakes which hit by -2 (print capture p. 221)",
    } },
  "bools" = { {
      "name" = "dixOAUnhorseDoctrine",
      "value" = true,
      "comment" = "the doctrine frame - in a world where the horseman is an important and formidable warrior, defending against him and defeating him are important goals of the foot soldier, the simplest and most direct method to get him off his horse (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseSlainMountAuto",
      "value" = true,
      "comment" = "the slain-mount rule - once the horse is slain the rider is automatically on foot, by missile or melee attack; the considerable disadvantage being the horse cannot be claimed as a prize, killing the mount somewhat a last resort tactic (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseProficiencyCheck",
      "value" = true,
      "comment" = "the proficiency check - the struck rider WITH horsemanship proficiency allowed a check against it, success retaining his seating with no ill effect beyond the damage, failure falling with the 1d3 (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseGrappleEveryTurn",
      "value" = true,
      "comment" = "the grapple persistence - the grappling rider making a to hit roll thereafter every turn, success forcing the proficiency re-roll, failure dropping him to the ground (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorseGrappleHangOn",
      "value" = true,
      "comment" = "the hang-on state - the successful grapple-check rider remains in the saddle with the other rider hanging from his side (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorsePullManSizedOnly",
      "value" = true,
      "comment" = "the pull size gate - man on foot can attempt to pull a rider from his horse, only man-sized creatures or larger, those larger than man sized counting as two men (print capture p. 220)",
    }, {
      "name" = "dixOAUnhorsePullNoDamage",
      "value" = true,
      "comment" = "the multi-pull damage rule - if the rider is pulled from his horse by more than one person he suffers no damage, likely landing on someone on the way down (print capture p. 221)",
    }, {
      "name" = "dixOAUnhorsePullFreeAttacks",
      "value" = true,
      "comment" = "the free-attacks clause - if the pull attempt fails and the horse is moving faster than 12 feet, the animal allowed a free set of attacks against the footman; all during this the horse and rider allowed their normal attacks (print capture p. 221)",
    }, {
      "name" = "dixOAUnhorseNormalAttacks",
      "value" = true,
      "comment" = "the normal-attacks clause - all during the pull the horse and rider are allowed their normal attacks (print capture p. 221)",
    }, {
      "name" = "dixOAUnhorseSetDefenses",
      "value" = true,
      "comment" = "the set-defenses doctrine - given time and materials set defenses can be prepared to dismount riders and stop horses, ropes hung between trees at the rider's height, tripwires, etc., the DM determining success (print capture p. 221)",
    }, {
      "name" = "dixOAStakesJumpCheck",
      "value" = true,
      "comment" = "the stake-jump check - the rider can attempt to urge his horse through the staked area, requiring a proficiency check just as if a jump or leap were being attempted; the stakes easily spotted and avoided by turning aside (print capture p. 221)",
    }, {
      "name" = "dixOAUnhorseOtherCreaturesApply",
      "value" = true,
      "comment" = "the other-creatures clause - the rules for dismounting a horse rider also apply to other riding creatures that a character may encounter (print capture p. 221)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dixOAUnhorseMountedWeaponMinFeet']() != 3  or m['dixOAUnhorseFallDamageDice']() != 3  or m['dixOAUnhorseFootShortMinFeet']() != 5  or m['dixOAUnhorseFootShortMaxFeet']() != 9  or m['dixOAUnhorseFootLongMinFeet']() != 10  or m['dixOAUnhorseLongChancePercent']() != 25  or m['dixOAUnhorseLongRollMin']() != 16  or m['dixOAUnhorseGrappleFallDamageDice']() != 6  or m['dixOAUnhorseGrappleRiderHitPenalty']() != -2  or m['dixOAUnhorsePullSpeed6Penalty']() != -2  or m['dixOAUnhorsePullSpeed7Penalty']() != -4  or m['dixOAUnhorsePullSpeed13Penalty']() != -6  or m['dixOAUnhorsePullExtraFootmanPenalty']() != -1  or m['dixOAUnhorsePullMaxFootmen']() != 4  or m['dixOAUnhorseSurroundMen']() != 8  or m['dixOAStakesPrepMen']() != 2  or m['dixOAStakesPrepAreaFeet']() != 10  or m['dixOAStakesLengthMinFeet']() != 4  or m['dixOAStakesLengthMaxFeet']() != 5  or m['dixOAStakesDamageDice']() != 6  or m['dixOAStakesChainReduction']() != 1  or m['dixOAStakesPlateReduction']() != 2  or  m['dixOAUnhorseDoctrine']() != 1  or  m['dixOAUnhorseSlainMountAuto']() != 1  or  m['dixOAUnhorseProficiencyCheck']() != 1  or  m['dixOAUnhorseGrappleEveryTurn']() != 1  or  m['dixOAUnhorseGrappleHangOn']() != 1  or  m['dixOAUnhorsePullManSizedOnly']() != 1  or  m['dixOAUnhorsePullNoDamage']() != 1  or  m['dixOAUnhorsePullFreeAttacks']() != 1  or  m['dixOAUnhorseNormalAttacks']() != 1  or  m['dixOAUnhorseSetDefenses']() != 1  or  m['dixOAStakesJumpCheck']() != 1  or  m['dixOAUnhorseOtherCreaturesApply']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dixOAUnhorseMountedWeaponMinFeet']() != 3  or m['dixOAUnhorseFallDamageDice']() != 3",
      "note" = "the mounted unhorsing pins - the 3-feet weapon floor with the 1d3 fall damage",
    }, {
      "expr" = "m['dixOAUnhorseFootShortMinFeet']() != 5  or m['dixOAUnhorseFootShortMaxFeet']() != 9  or m['dixOAUnhorseFootLongMinFeet']() != 10",
      "note" = "the foot-soldier bands - the 5-to-9 short band and the 10-feet long band",
    }, {
      "expr" = "m['dixOAUnhorseLongChancePercent']() != 25  or m['dixOAUnhorseLongRollMin']() != 16",
      "note" = "the long-band chance - the 25 percent riding the 16-20 of 1d20",
    }, {
      "expr" = "m['dixOAUnhorseGrappleFallDamageDice']() != 6  or m['dixOAUnhorseGrappleRiderHitPenalty']() != -2",
      "note" = "the grapple pins - the 1d6 fall damage and the -2 rider penalty",
    }, {
      "expr" = "m['dixOAUnhorsePullSpeed6Penalty']() != -2  or m['dixOAUnhorsePullSpeed7Penalty']() != -4  or m['dixOAUnhorsePullSpeed13Penalty']() != -6",
      "note" = "the footman pull ladder - the -2, -4 and -6 of the three speed bands",
    }, {
      "expr" = "m['dixOAUnhorsePullExtraFootmanPenalty']() != -1  or m['dixOAUnhorsePullMaxFootmen']() != 4",
      "note" = "the multi-footman pull - the -1 per extra man up to the 4 cap",
    }, {
      "expr" = "m['dixOAUnhorseSurroundMen']() != 8",
      "note" = "the surround rule - the eight men pulling both horse and rider down",
    }, {
      "expr" = "m['dixOAStakesPrepMen']() != 2  or m['dixOAStakesPrepAreaFeet']() != 10  or m['dixOAStakesLengthMinFeet']() != 4",
      "note" = "the stake defense - the two men, the 10-foot square, the 4-to-5 stakes",
    }, {
      "expr" = "m['dixOAStakesDamageDice']() != 6  or m['dixOAStakesChainReduction']() != 1  or m['dixOAStakesPlateReduction']() != 2",
      "note" = "the stake damage pins - the 2d6 per stake with the barding reductions",
    } },
  "audit" = {
      "label" = "R684 OA unhorsing audit",
      "comment" = "OA round seventy-one (capture pp. 220-221): the Unhorsing doctrine - the slain-mount rule, the mounted natural-20 unhorsing with the horsemanship proficiency check, the foot-soldier weapon bands, the grapple doctrine, the footman pull ladder and the set defenses with the stake line, single-pass pins per the Chapter 9 provenance shift",
    },
}
