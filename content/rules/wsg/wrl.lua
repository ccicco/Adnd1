-- wrl: promoted from tools/spec_r442.json (the The WSG RAPPELLING, R442: the descent prose (no table this round) - by securing a rope at the top of a slope or cliff and then winding it around his body, a character can descend a non-horizontal surface quite rapidly by the process known as rappelling; applying sideways pressure against the surface and using the friction of the rope around his body, the climber comes down under control at a base speed of 120 feet per round (encumbrance and other penalties apply just as for an ascent). To successfully rappel the character must make a Climbing Check with a +50% modifier to his current Climbing Rating for every round or part of a round spent descending; failure on any check means he has lost his grip and hangs upside down, spinning while suspended by the rope, until rescued or until he makes a successful Dexterity Check (regained bearings, new hold) - allowed once per round. Rappelling down a free-hanging rope (no surface to brace against) can be done, but the modifier is only +30% instead of +50%; a failed check while free-hanging means his Dexterity Checks take a +2 modifier to the die roll. Census 366 -> 367.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 442,
  "prefix" = "wrl",
  "banner" = {
      "title" = "The WSG RAPPELLING, R442: the descent prose (no table this round) - by securing a rope at the top of a slope or cliff and then winding it around his body, a character can descend a non-horizontal surface quite rapidly by the process known as rappelling; applying sideways pressure against the surface and using the friction of the rope around his body, the climber comes down under control at a base speed of 120 feet per round (encumbrance and other penalties apply just as for an ascent). To successfully rappel the character must make a Climbing Check with a +50% modifier to his current Climbing Rating for every round or part of a round spent descending; failure on any check means he has lost his grip and hangs upside down, spinning while suspended by the rope, until rescued or until he makes a successful Dexterity Check (regained bearings, new hold) - allowed once per round. Rappelling down a free-hanging rope (no surface to brace against) can be done, but the modifier is only +30% instead of +50%; a failed check while free-hanging means his Dexterity Checks take a +2 modifier to the die roll. Census 366 -> 367.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 37; the user own copy OCR cross-checked against the archive djvu word layer (Guide_0037.djvu) - the section reads CLEAN in the djvu, every number (the 120 feet per round, the +50% modifier, the +30% free-hanging modifier and the +2 Dexterity modifier) matched exactly; no eye-reads were needed.",
      "sentinel" = "The climber comes down under control at a base speed of 120 feet per round. Each round or part of a round of rappelling takes a Climbing Check at +50%; on a free-hanging rope the modifier is only +30%, and a failed check there puts a +2 on the Dexterity Checks - allowed once per round - that end the upside-down spin.",
    },
  "consts" = { {
      "name" = "wrlBaseSpeedFtPerRound",
      "value" = 120,
      "comment" = "Winding the rope around his body and using its friction, the climber comes down under control at a base speed of 120 feet per round.",
    }, {
      "name" = "wrlSlopeCheckModPct",
      "value" = 50,
      "comment" = "To successfully rappel down a slope or cliff, the character must make a Climbing Check with a +50% modifier to his current Climbing Rating for every round or part of a round spent descending in this fashion.",
    }, {
      "name" = "wrlFreeHangCheckModPct",
      "value" = 30,
      "comment" = "Rappelling down a free-hanging rope, where the character has no surface to brace against, can be done, but the modifier to the Climbing Rating is only +30% instead of +50%.",
    }, {
      "name" = "wrlFreeHangDexMod",
      "value" = 2,
      "comment" = "If the character fails a Climbing Check while rappelling down a free-hanging rope, his Dexterity Checks are made with a +2 modifier to the die roll.",
    } },
  "bools" = { {
      "name" = "wrlEncumbrancePenaltiesApply",
      "value" = true,
      "comment" = "Penalties to the 120-feet movement rate, for encumbrance and other factors, apply just as they do for an ascent.",
    }, {
      "name" = "wrlCheckPerRoundOrPart",
      "value" = true,
      "comment" = "The Climbing Check at +50% is made for every round OR PART of a round spent rappelling.",
    }, {
      "name" = "wrlFailureHangsUpsideDown",
      "value" = true,
      "comment" = "Failure on any check indicates the character has lost his grip on the rope: he hangs upside down, spinning while suspended by the rope, until he is rescued or makes a successful Dexterity Check.",
    }, {
      "name" = "wrlDexCheckOncePerRound",
      "value" = true,
      "comment" = "The recovery Dexterity Checks (regained bearings, a new hold on the rope) are allowed once per round.",
    }, {
      "name" = "wrlFreeHangNoSurfaceToBrace",
      "value" = true,
      "comment" = "The free-hanging variant applies where the character has no surface to brace against.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wrlBaseSpeedFtPerRound']() != 120",
      "note" = "the controlled descent: 120 feet per round at base speed",
    }, {
      "expr" = "m['wrlSlopeCheckModPct']() != 50 or m['wrlFreeHangCheckModPct']() != 30",
      "note" = "the two rappel modifiers: +50% against a surface, +30% on a free-hanging rope",
    }, {
      "expr" = "m['wrlSlopeCheckModPct']() - m['wrlFreeHangCheckModPct']() != 20",
      "note" = "the free-hanging rope costs 20 points of the Climbing Rating modifier (50 - 30)",
    }, {
      "expr" = "m['wrlFreeHangDexMod']() != 2 or m['wrlBaseSpeedFtPerRound']() != m['wrlSlopeCheckModPct']() + 70",
      "note" = "the failed free-hanging check: Dexterity Checks at +2 on the die roll; the speed and slope modifier together anchor the section (120 = 50 + 70)",
    } },
  "audit" = {
      "label" = "R442 WSG rappelling pin audit",
      "comment" = "The rappelling slice pins the rope-secured descent of a non-horizontal surface - the 120-feet-per-round base speed (encumbrance and other penalties apply as for an ascent), the +50% Climbing Check modifier per round or part of a round, the lost-grip failure state (hanging upside down, spinning, until rescued or a successful Dexterity Check - allowed once per round), and the free-hanging-rope variant (no surface to brace against: +30% instead of +50%, Dex checks at +2) (rules/wsg/wsgrapp.h, prefix wrl); census 366 -> 367.",
    },
}
