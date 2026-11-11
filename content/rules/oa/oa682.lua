-- oa682: promoted from rules/oa/oahorsefire.h (the OA COMBAT PROCEDURES, printed capture p. 219 - the mounted bowfire round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 682,
  "prefix" = "oa682",
  "banner" = {
      "title" = "OA COMBAT PROCEDURES, printed capture p. 219 - the mounted bowfire round",
      "provenance" = "census 604 -> 605.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE DOCTRINE FRAME: the mounted bowman is an integral part of the armies and fighting styles of the Oriental lands, the warriors firing great longbows at a full gallop. THE STANDING-HORSE FREEDOM: any character can use a missile weapon from the back of an unmoving horse - no particular skill. THE HORSEMANSHIP GATE: firing from a moving horse requires the horsemanship proficiency, the bow needing two hands so the horse is guided with the knees; the DM can rule extremely rough ground forces the reins, preventing bowfire. THE RATE: horseback fire is half the normal rate - 2/1 becomes 1/1, 3/1 becomes 3/2 - with to-hit penalties based on the speed of the animal, listed on Table 67. The prose codifies per the R431 calculus  the gap census after this round: 135 closed, 100 open - the Combat Procedures box flips (census 604 -> 605); NEXT - R683: Table 67 the horseback bowfire modifiers (capture p. 220), prefix diw (verify free at the landing - diu and div TAKEN by the R681/R682 call families), audit \"R683 OA horseback bowfire modifiers audit\", include after rules/oa/oahorsefire.h",
    },
  "consts" = { {
      "name" = "divOAHorsebackRateDivisor",
      "value" = 2,
      "comment" = "the rate of fire from horseback is half what the character is normally allowed - the halving divisor of the mounted shots (print capture p. 219)",
    }, {
      "name" = "divOAExampleMountedShotsLow",
      "value" = 1,
      "comment" = "the printed rate conversion - the 2/1 rate of fire becoming 1/1 from horseback, the halved shots of the low example (print capture p. 219)",
    }, {
      "name" = "divOAExampleMountedNumHigh",
      "value" = 3,
      "comment" = "the printed rate conversion numerator - the 3/1 rate of fire becoming 3/2 from horseback, the shots of the second example (print capture p. 219)",
    }, {
      "name" = "divOAExampleMountedDenHigh",
      "value" = 2,
      "comment" = "the printed rate conversion denominator - the 3/2 of the halved 3/1 rate, the rounds span of the second example (print capture p. 219)",
    }, {
      "name" = "divOABowfireHandsRequired",
      "value" = 2,
      "comment" = "the two-hands rule - firing the bow requires two hands, the mounted bowman with the horsemanship proficiency guiding the horse with his knees (print capture p. 219)",
    } },
  "bools" = { {
      "name" = "divOAMountedBowmanDoctrine",
      "value" = true,
      "comment" = "the doctrine frame - the mounted bowman is an integral part of the armies and fighting styles of the Oriental lands, the warriors refining the art until they fire great longbows at a full gallop (print capture p. 219)",
    }, {
      "name" = "divOAUnmovingHorseAnyCharacter",
      "value" = true,
      "comment" = "the unmoving-horse freedom - any character can use a missile weapon from the back of an unmoving horse, taking no particular skill (print capture p. 219)",
    }, {
      "name" = "divOAMovingHorseNeedsHorsemanship",
      "value" = true,
      "comment" = "the horsemanship gate - when firing from the back of a moving horse, the character must have the horsemanship proficiency (print capture p. 219)",
    }, {
      "name" = "divOAKneesGuidance",
      "value" = true,
      "comment" = "the knees-guidance clause - the bowfire requiring two hands forces the mounted character to guide the horse with his knees (print capture p. 219)",
    }, {
      "name" = "divOADMRoughGroundBlocksBowfire",
      "value" = true,
      "comment" = "the DM rough-ground clause - the DM can rule that extremely rough areas of ground (rocky slopes, thick underbrush) require the character to handle the reins, preventing bowfire (print capture p. 219)",
    }, {
      "name" = "divOASpeedBasedToHitPenalty",
      "value" = true,
      "comment" = "the speed-based penalties - the mounted character also suffers penalties on his chance to hit, based on the speed of the animal, listed on Table 67 (print capture p. 219)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['divOAHorsebackRateDivisor']() != 2  or m['divOAExampleMountedShotsLow']() != 1  or m['divOAExampleMountedNumHigh']() != 3  or m['divOAExampleMountedDenHigh']() != 2  or m['divOABowfireHandsRequired']() != 2  or  m['divOAMountedBowmanDoctrine']() != 1  or  m['divOAUnmovingHorseAnyCharacter']() != 1  or  m['divOAMovingHorseNeedsHorsemanship']() != 1  or  m['divOAKneesGuidance']() != 1  or  m['divOADMRoughGroundBlocksBowfire']() != 1  or  m['divOASpeedBasedToHitPenalty']() != 1",
      "note" = "",
    }, {
      "expr" = "m['divOAHorsebackRateDivisor']() != 2",
      "note" = "the rate pins - the horseback rate of fire halved",
    }, {
      "expr" = "m['divOAExampleMountedShotsLow']() != 1  or m['divOAExampleMountedNumHigh']() != 3",
      "note" = "the printed rate conversions - 2/1 becomes 1/1, 3/1 becomes 3/2",
    }, {
      "expr" = "m['divOAExampleMountedDenHigh']() != 2",
      "note" = "the 3/2 denominator of the second conversion",
    }, {
      "expr" = "m['divOAHorsebackRateDivisor']() *m['divOAExampleMountedShotsLow']() != 2",
      "note" = "the halving shape - the divisor times the mounted low-rate shots equals the printed 2",
    }, {
      "expr" = "m['divOABowfireHandsRequired']() != 2",
      "note" = "the hands pin - the bowfire requiring two hands, the knees guiding the moving horse",
    } },
  "audit" = {
      "label" = "R682 OA combat procedures audit",
      "comment" = "OA round sixty-nine (capture p. 219): the Combat Procedures - the missile fire from horseback doctrine - the unmoving-horse freedom, the horsemanship proficiency gate, the halved rate of fire with the speed-based to-hit penalties, single-pass pins per the Chapter 9 provenance shift",
    },
}
