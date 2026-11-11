-- oa717: promoted from rules/oa/oa88goblinspider.h (the OA MONSTERS - THE GOBLIN SPIDER, printed capture p. 267 - the trapdoor);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 717,
  "prefix" = "oa717",
  "banner" = {
      "title" = "OA MONSTERS - THE GOBLIN SPIDER, printed capture p. 267 - the trapdoor",
      "provenance" = "ambush round census 639 -> 640.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 170 closed, 65 open - the goblin spider box flips (census 639 -> 640); NEXT - R718: the Hai Nu (capture p. 268), prefix dkf (verify free at the landing), audit \"R718 OA monsters Hai Nu audit\", include after rules/oa/oa88goblinspider.h",
    },
  "consts" = { {
      "name" = "dkeAppearMin",
      "value" = 1,
      "comment" = "the appearing minimum - the 1 of the 1-4 appearing (print capture p. 267)",
    }, {
      "name" = "dkeAppearMax",
      "value" = 4,
      "comment" = "the appearing maximum - the 4 of the 1-4 appearing (print capture p. 267)",
    }, {
      "name" = "dkeAC",
      "value" = 4,
      "comment" = "the goblin spider armor class - the AC 4 of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeMove",
      "value" = 18,
      "comment" = "the goblin spider move - the 18 of the move 18 (print capture p. 267)",
    }, {
      "name" = "dkeHDMin",
      "value" = 6,
      "comment" = "the hit dice minimum - the 6 of the 6 to 9 (print capture p. 267)",
    }, {
      "name" = "dkeHDMax",
      "value" = 9,
      "comment" = "the hit dice maximum - the 9 of the 6 to 9 (print capture p. 267)",
    }, {
      "name" = "dkeLairPct",
      "value" = 80,
      "comment" = "the in-lair percentage - the 80% of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeFrequencyRare",
      "value" = 1,
      "comment" = "the frequency - the rare of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeTreasureTypeC",
      "value" = 1,
      "comment" = "the treasure type - the C of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeAttackCount",
      "value" = 2,
      "comment" = "the attack count - the 2 of the number of attacks (print capture p. 267)",
    }, {
      "name" = "dkeDmgMin",
      "value" = 1,
      "comment" = "the damage minimum - the 1 of the 1-8 per attack (print capture p. 267)",
    }, {
      "name" = "dkeDmgMax",
      "value" = 8,
      "comment" = "the damage maximum - the 8 of the 1-8 per attack (print capture p. 267)",
    }, {
      "name" = "dkeSpecialAttackSurprise",
      "value" = 1,
      "comment" = "the first special attack - the surprise of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeSpecialAttackGrasp",
      "value" = 1,
      "comment" = "the second special attack - the grasp of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeWeaponPlusRequired",
      "value" = 1,
      "comment" = "the weapon requirement - the +1 or better weapons to hit (print capture p. 267)",
    }, {
      "name" = "dkeMagicResistPct",
      "value" = 20,
      "comment" = "the magic resistance - the 20% of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeIntelligenceLow",
      "value" = 1,
      "comment" = "the intelligence - the low of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeAlignmentNeutralEvil",
      "value" = 1,
      "comment" = "the alignment - the neutral evil of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeSizeLarge",
      "value" = 1,
      "comment" = "the size class - the L of the L 8-10 (print capture p. 267)",
    }, {
      "name" = "dkeSizeMinFeet",
      "value" = 8,
      "comment" = "the size minimum - the 8 of the L 8-10 (print capture p. 267)",
    }, {
      "name" = "dkeSizeMaxFeet",
      "value" = 10,
      "comment" = "the size maximum - the 10 of the L 8-10 (print capture p. 267)",
    }, {
      "name" = "dkePsionicNil",
      "value" = 1,
      "comment" = "the psionic ability - the nil of the stat block (print capture p. 267)",
    }, {
      "name" = "dkePsionicModesNil",
      "value" = 1,
      "comment" = "the attack and defense modes - the nil of the stat block (print capture p. 267)",
    }, {
      "name" = "dkeXP6Base",
      "value" = 575,
      "comment" = "the 6 HD xp base - the 575 of the VI/575 + 6 per hp (print capture p. 267)",
    }, {
      "name" = "dkeXP6PerHP",
      "value" = 6,
      "comment" = "the 6 HD xp per hit point - the 6 of the VI/575 + 6/hp (print capture p. 267)",
    }, {
      "name" = "dkeXP6LevelVI",
      "value" = 1,
      "comment" = "the 6 HD xp level - the VI of the VI/575 + 6/hp (print capture p. 267)",
    }, {
      "name" = "dkeXP7Base",
      "value" = 900,
      "comment" = "the 7 HD xp base - the 900 of the VI/900 + 8 per hp (print capture p. 267)",
    }, {
      "name" = "dkeXP7PerHP",
      "value" = 8,
      "comment" = "the 7 HD xp per hit point - the 8 of the VI/900 + 8/hp (print capture p. 267)",
    }, {
      "name" = "dkeXP7LevelVI",
      "value" = 1,
      "comment" = "the 7 HD xp level - the VI of the VI/900 + 8/hp (print capture p. 267)",
    }, {
      "name" = "dkeXP8Base",
      "value" = 1350,
      "comment" = "the 8 HD xp base - the 1,350 of the VII/1,350 + 10 per hp (print capture p. 267)",
    }, {
      "name" = "dkeXP8PerHP",
      "value" = 10,
      "comment" = "the 8 HD xp per hit point - the 10 of the VII/1,350 + 10/hp (print capture p. 267)",
    }, {
      "name" = "dkeXP8LevelVII",
      "value" = 1,
      "comment" = "the 8 HD xp level - the VII of the VII/1,350 + 10/hp (print capture p. 267)",
    }, {
      "name" = "dkeXP9Base",
      "value" = 2200,
      "comment" = "the 9 HD xp base - the 2,200 of the VII/2,200 + 12 per hp (print capture p. 267)",
    }, {
      "name" = "dkeXP9PerHP",
      "value" = 12,
      "comment" = "the 9 HD xp per hit point - the 12 of the VII/2,200 + 12/hp (print capture p. 267)",
    }, {
      "name" = "dkeXP9LevelVII",
      "value" = 1,
      "comment" = "the 9 HD xp level - the VII of the VII/2,200 + 12/hp (print capture p. 267)",
    }, {
      "name" = "dkeEarthSpiderName",
      "value" = 1,
      "comment" = "the name - the goblin spider or earth spider (print capture p. 267)",
    }, {
      "name" = "dkeHugeFurryEvilCast",
      "value" = 1,
      "comment" = "the look - a huge furry spider of particularly evil cast (print capture p. 267)",
    }, {
      "name" = "dkeDwellFarFromHumans",
      "value" = 1,
      "comment" = "the habitat - dwell far from human habitations (print capture p. 267)",
    }, {
      "name" = "dkeWoodedMountains",
      "value" = 1,
      "comment" = "the range - the rough wooded mountains common to Kara-Tur (print capture p. 267)",
    }, {
      "name" = "dkeFormerDominion",
      "value" = 1,
      "comment" = "the history - once dominated large sections of the land now controlled by humans (print capture p. 267)",
    }, {
      "name" = "dkeViewHumansAsInvaders",
      "value" = 1,
      "comment" = "the grudge - view humans and their allies as invaders to their homelands (print capture p. 267)",
    }, {
      "name" = "dkeHarmTravelersAndSettlers",
      "value" = 1,
      "comment" = "the malice - take every opportunity to cause harm to human travelers and settlers on the edges of their territories (print capture p. 267)",
    }, {
      "name" = "dkeNoWebs",
      "value" = 1,
      "comment" = "the web clause - goblin spiders do not spin webs (print capture p. 267)",
    }, {
      "name" = "dkeLairInTunnels",
      "value" = 1,
      "comment" = "the lair - making their lairs in tunnels underground (print capture p. 267)",
    }, {
      "name" = "dkeTrapdoorEntrances",
      "value" = 1,
      "comment" = "the door - the entrances carefully concealed by trapdoor openings (print capture p. 267)",
    }, {
      "name" = "dkeDetectVibrationsOverhead",
      "value" = 1,
      "comment" = "the trigger - able to detect the vibrations of creatures passing overhead (print capture p. 267)",
    }, {
      "name" = "dkeSurpriseDieMax",
      "value" = 4,
      "comment" = "the ambush surprise - springing suddenly from the lair, surprising on a 1-4 (print capture p. 267)",
    }, {
      "name" = "dkeDragIntoLair",
      "value" = 1,
      "comment" = "the abduction - attempt to grab their victim and drag him back into the lair, closing the door behind them (print capture p. 267)",
    }, {
      "name" = "dkeBothHitsGrasp",
      "value" = 1,
      "comment" = "the grasp - in any melee round with both attacks hitting, the victim has been grasped and held (print capture p. 267)",
    }, {
      "name" = "dkeHeldToHitPenalty",
      "value" = 4,
      "comment" = "the held victim penalty - held victims fight with a -4 on their chances to hit (print capture p. 267)",
    }, {
      "name" = "dkeBendBarsFrees",
      "value" = 1,
      "comment" = "the escape - a successful bend bars/lift gates roll frees the victim from the grip (print capture p. 267)",
    }, {
      "name" = "dkeHelpersWrenchLoose",
      "value" = 1,
      "comment" = "the rescue - those not held can help free the victim (print capture p. 267)",
    }, {
      "name" = "dkeFreeStrengthPoints",
      "value" = 20,
      "comment" = "the rescue strength - 20 or more points of Strength to wrench the victim loose (print capture p. 267)",
    }, {
      "name" = "dkeFreeMinCharacters",
      "value" = 2,
      "comment" = "the rescue party - at least two characters to wrench the victim loose (print capture p. 267)",
    }, {
      "name" = "dkeGrippingBlocksAttacks",
      "value" = 1,
      "comment" = "the grip cost - while gripping a victim, it cannot make any other attacks (print capture p. 267)",
    }, {
      "name" = "dkeExcellentMimic",
      "value" = 1,
      "comment" = "the mimicry - excellent mimics, able to imitate any voice or animal sound they hear (print capture p. 267)",
    }, {
      "name" = "dkeUnknownTonguesRepeatOnly",
      "value" = 1,
      "comment" = "the parrot clause - when imitating languages they do not understand they can only repeat words they have heard spoken (print capture p. 267)",
    }, {
      "name" = "dkeCleverAndDevious",
      "value" = 1,
      "comment" = "the mind - not exceptionally intelligent, but clever and devious (print capture p. 267)",
    }, {
      "name" = "dkeMimicryLuresVictims",
      "value" = 1,
      "comment" = "the lure - often using their mimicry to lure victims to their doom (print capture p. 267)",
    }, {
      "name" = "dkeSpeaksOwnLanguage",
      "value" = 1,
      "comment" = "the first tongue - their own language (print capture p. 267)",
    }, {
      "name" = "dkeSpeaksSpiderLanguage",
      "value" = 1,
      "comment" = "the second tongue - the language of spiders (print capture p. 267)",
    }, {
      "name" = "dkeSpeaksTradeLanguage",
      "value" = 1,
      "comment" = "the third tongue - the trade language (print capture p. 267)",
    }, {
      "name" = "dkeSpeaksLocalHuman",
      "value" = 1,
      "comment" = "the fourth tongue - the language common to the human inhabitants near their lair (print capture p. 267)",
    }, {
      "name" = "dkeGuardsPct",
      "value" = 30,
      "comment" = "the guard chance - the 30% chance of 2d4 giant spiders near any lair (print capture p. 268)",
    }, {
      "name" = "dkeGuardsDice",
      "value" = 2,
      "comment" = "the guard dice - the 2d4 giant spiders in the immediate vicinity (print capture p. 268)",
    }, {
      "name" = "dkeGuardsSides",
      "value" = 4,
      "comment" = "the guard dice sides - the 2d4 giant spiders in the immediate vicinity (print capture p. 268)",
    }, {
      "name" = "dkeGiantSpiderGuards",
      "value" = 1,
      "comment" = "the retinue - 2d4 giant spiders in the immediate vicinity serve as guards and assist them in any battle (print capture p. 268)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dkeAppearMin']() != 1  or m['dkeAppearMax']() != 4  or m['dkeAC']() != 4  or m['dkeMove']() != 18  or m['dkeHDMin']() != 6  or m['dkeHDMax']() != 9  or m['dkeLairPct']() != 80  or m['dkeAttackCount']() != 2  or m['dkeDmgMin']() != 1  or m['dkeDmgMax']() != 8  or m['dkeWeaponPlusRequired']() != 1  or m['dkeMagicResistPct']() != 20  or m['dkeSizeMinFeet']() != 8  or m['dkeSizeMaxFeet']() != 10  or m['dkeXP6Base']() != 575  or m['dkeXP6PerHP']() != 6  or m['dkeXP7Base']() != 900  or m['dkeXP7PerHP']() != 8  or m['dkeXP8Base']() != 1350  or m['dkeXP8PerHP']() != 10  or m['dkeXP9Base']() != 2200  or m['dkeXP9PerHP']() != 12  or m['dkeSurpriseDieMax']() != 4  or m['dkeHeldToHitPenalty']() != 4  or m['dkeFreeStrengthPoints']() != 20  or m['dkeFreeMinCharacters']() != 2  or m['dkeGuardsPct']() != 30  or m['dkeGuardsDice']() != 2  or m['dkeGuardsSides']() != 4  or  m['dkeFrequencyRare']() != 1  or  m['dkeTreasureTypeC']() != 1  or  m['dkeSpecialAttackSurprise']() != 1  or  m['dkeSpecialAttackGrasp']() != 1  or  m['dkeIntelligenceLow']() != 1  or  m['dkeAlignmentNeutralEvil']() != 1  or  m['dkeSizeLarge']() != 1  or  m['dkePsionicNil']() != 1  or  m['dkePsionicModesNil']() != 1  or  m['dkeXP6LevelVI']() != 1  or  m['dkeXP7LevelVI']() != 1  or  m['dkeXP8LevelVII']() != 1  or  m['dkeXP9LevelVII']() != 1  or  m['dkeEarthSpiderName']() != 1  or  m['dkeHugeFurryEvilCast']() != 1  or  m['dkeDwellFarFromHumans']() != 1  or  m['dkeWoodedMountains']() != 1  or  m['dkeFormerDominion']() != 1  or  m['dkeViewHumansAsInvaders']() != 1  or  m['dkeHarmTravelersAndSettlers']() != 1  or  m['dkeNoWebs']() != 1  or  m['dkeLairInTunnels']() != 1  or  m['dkeTrapdoorEntrances']() != 1  or  m['dkeDetectVibrationsOverhead']() != 1  or  m['dkeDragIntoLair']() != 1  or  m['dkeBothHitsGrasp']() != 1  or  m['dkeBendBarsFrees']() != 1  or  m['dkeHelpersWrenchLoose']() != 1  or  m['dkeGrippingBlocksAttacks']() != 1  or  m['dkeExcellentMimic']() != 1  or  m['dkeUnknownTonguesRepeatOnly']() != 1  or  m['dkeCleverAndDevious']() != 1  or  m['dkeMimicryLuresVictims']() != 1  or  m['dkeSpeaksOwnLanguage']() != 1  or  m['dkeSpeaksSpiderLanguage']() != 1  or  m['dkeSpeaksTradeLanguage']() != 1  or  m['dkeSpeaksLocalHuman']() != 1  or  m['dkeGiantSpiderGuards']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dkeAppearMin']() != 1  or m['dkeAppearMax']() != 4  or m['dkeAC']() != 4  or m['dkeMove']() != 18  or m['dkeHDMin']() != 6  or m['dkeHDMax']() != 9  or m['dkeLairPct']() != 80  or m['dkeFrequencyRare']() != 1  or m['dkeTreasureTypeC']() != 1  or m['dkeAttackCount']() != 2  or m['dkeDmgMin']() != 1  or m['dkeDmgMax']() != 8  or m['dkeSpecialAttackSurprise']() != 1  or m['dkeSpecialAttackGrasp']() != 1  or m['dkeWeaponPlusRequired']() != 1  or m['dkeMagicResistPct']() != 20  or m['dkeIntelligenceLow']() != 1  or m['dkeAlignmentNeutralEvil']() != 1  or m['dkeSizeLarge']() != 1  or m['dkeSizeMinFeet']() != 8  or m['dkeSizeMaxFeet']() != 10  or m['dkePsionicNil']() != 1  or m['dkePsionicModesNil']() != 1",
      "note" = "the stat block - the stat block pins, healthy values, each condition false",
    }, {
      "expr" = "m['dkeXP6Base']() != 575  or m['dkeXP6PerHP']() != 6  or m['dkeXP6LevelVI']() != 1  or m['dkeXP7Base']() != 900  or m['dkeXP7PerHP']() != 8  or m['dkeXP7LevelVI']() != 1  or m['dkeXP8Base']() != 1350  or m['dkeXP8PerHP']() != 10  or m['dkeXP8LevelVII']() != 1  or m['dkeXP9Base']() != 2200  or m['dkeXP9PerHP']() != 12  or m['dkeXP9LevelVII']() != 1",
      "note" = "the xp ladder - the four-step xp ladder, healthy values, each condition false",
    }, {
      "expr" = "m['dkeEarthSpiderName']() != 1  or m['dkeHugeFurryEvilCast']() != 1  or m['dkeDwellFarFromHumans']() != 1  or m['dkeWoodedMountains']() != 1  or m['dkeFormerDominion']() != 1  or m['dkeViewHumansAsInvaders']() != 1  or m['dkeHarmTravelersAndSettlers']() != 1",
      "note" = "the earth spider - the name and the grudge, healthy values, each condition false",
    }, {
      "expr" = "m['dkeNoWebs']() != 1  or m['dkeLairInTunnels']() != 1  or m['dkeTrapdoorEntrances']() != 1  or m['dkeDetectVibrationsOverhead']() != 1  or m['dkeSurpriseDieMax']() != 4  or m['dkeDragIntoLair']() != 1",
      "note" = "the trapdoor ambush - the tunnel lair and the spring, healthy values, each condition false",
    }, {
      "expr" = "m['dkeBothHitsGrasp']() != 1  or m['dkeHeldToHitPenalty']() != 4  or m['dkeBendBarsFrees']() != 1  or m['dkeHelpersWrenchLoose']() != 1  or m['dkeFreeStrengthPoints']() != 20  or m['dkeFreeMinCharacters']() != 2  or m['dkeGrippingBlocksAttacks']() != 1",
      "note" = "the grasp - the hold and the rescue, healthy values, each condition false",
    }, {
      "expr" = "m['dkeExcellentMimic']() != 1  or m['dkeUnknownTonguesRepeatOnly']() != 1  or m['dkeCleverAndDevious']() != 1  or m['dkeMimicryLuresVictims']() != 1  or m['dkeSpeaksOwnLanguage']() != 1  or m['dkeSpeaksSpiderLanguage']() != 1  or m['dkeSpeaksTradeLanguage']() != 1  or m['dkeSpeaksLocalHuman']() != 1",
      "note" = "the mimicry and the tongues - the mimic and the four tongues, healthy values, each condition false",
    }, {
      "expr" = "m['dkeGuardsPct']() != 30  or m['dkeGuardsDice']() != 2  or m['dkeGuardsSides']() != 4  or m['dkeGiantSpiderGuards']() != 1",
      "note" = "the giant spider guards - the lair retinue, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R717 OA monsters Goblin Spider audit",
      "comment" = "OA round one hundred four (capture pp. 267-268): the Chapter 12 monster roster - the goblin spider, the stat block and the description riding together, single-pass pins per the Chapter 9 provenance shift",
    },
}
