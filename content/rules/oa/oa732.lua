-- oa732: promoted from rules/oa103tengu.h (the OA MONSTERS - THE TENGU, printed capture pp. 284-285 - the mountain spirit);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 732,
  "prefix" = "oa732",
  "banner" = {
      "title" = "OA MONSTERS - THE TENGU, printed capture pp. 284-285 - the mountain spirit",
      "provenance" = "round census 654 -> 655.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 185 closed, 50 open - the tengu box flips (census 654 -> 655); NEXT - R733: the Chapter 13 treasure opener, the Magical Items Usable By Class table (capture p. 285), prefix dku (verify free at the landing), audit \"R733 OA treasure class usage audit\", include after rules/oa103tengu.h",
    },
  "consts" = { {
      "name" = "dktTenguCount",
      "value" = 2,
      "comment" = "the tengu table row count - the crow-headed and the humanoid of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktCrowRare",
      "value" = 1,
      "comment" = "the crow frequency - the rare of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktHumRare",
      "value" = 1,
      "comment" = "the humanoid frequency - the rare of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktMCC",
      "value" = 1,
      "comment" = "the maneuver class - the C of both move lines of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktTreasureC",
      "value" = 1,
      "comment" = "the treasure type - the C of both columns (print capture p. 284)",
    }, {
      "name" = "dktCrowSpecialAttacksSpells",
      "value" = 1,
      "comment" = "the crow special attacks - the spells of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktHumSpecialAttacksSpells",
      "value" = 1,
      "comment" = "the humanoid special attacks - the spells of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktCrowDefensesNil",
      "value" = 1,
      "comment" = "the crow special defenses - the nil of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktHumInvisibility",
      "value" = 1,
      "comment" = "the humanoid special defense - the invisibility of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktMRStandard",
      "value" = 1,
      "comment" = "the magic resistance - the standard of both columns (print capture p. 284)",
    }, {
      "name" = "dktCrowIntLowToAverage",
      "value" = 1,
      "comment" = "the crow intelligence - the low to average of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktHumIntHighToVery",
      "value" = 1,
      "comment" = "the humanoid intelligence - the high to very of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktCrowChaoticEvil",
      "value" = 1,
      "comment" = "the crow alignment - the chaotic evil of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktHumChaoticNeutral",
      "value" = 1,
      "comment" = "the humanoid alignment - the chaotic neutral of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktSizeSmall",
      "value" = 1,
      "comment" = "the size class - the S of both columns (print capture p. 284)",
    }, {
      "name" = "dktPsionicNil",
      "value" = 1,
      "comment" = "the psionic ability - the nil of both columns (print capture p. 284)",
    }, {
      "name" = "dktModesNil",
      "value" = 1,
      "comment" = "the attack and defense modes - the nil of both columns (print capture p. 284)",
    }, {
      "name" = "dktHumDamageByWeapon",
      "value" = 1,
      "comment" = "the humanoid damage clause - the 1-6 or by weapon type of the stat grid (print capture p. 284)",
    }, {
      "name" = "dktHumMoveHalf",
      "value" = 1,
      "comment" = "the half of the humanoid ground move - the print 12 1/2 pinned whole as 12 with the half here, the ints-only splice mirror (print capture p. 284)",
    }, {
      "name" = "dktCrowXPCount",
      "value" = 4,
      "comment" = "the crow xp rung count - the 2 to 5 HD ladder of the crow-headed tengu (print capture p. 284)",
    }, {
      "name" = "dktHumXPCount",
      "value" = 6,
      "comment" = "the humanoid xp rung count - the 5 to 10 HD ladder of the humanoid tengu, the capture misreading 70 for the 10 HD rung (print capture p. 284)",
    }, {
      "name" = "dktBirdlikeHumanoids",
      "value" = 1,
      "comment" = "the nature - a race of birdlike humanoid creatures found in uninhabited mountain areas, though not far from settled lands (print capture p. 284)",
    }, {
      "name" = "dktOriginalInhabitants",
      "value" = 1,
      "comment" = "the lore - many people believe they were the original inhabitants of the land before the arrival of humans (print capture p. 284)",
    }, {
      "name" = "dktPushedIntoMountains",
      "value" = 1,
      "comment" = "the displacement - once the humans arrived with their organization and culture, the tengu were pushed deeper and deeper into the mountains (print capture p. 284)",
    }, {
      "name" = "dktGladesAndBanks",
      "value" = 1,
      "comment" = "the haunts - they now dwell in forest glades, meadows, and on the banks of streams and ponds (print capture p. 284)",
    }, {
      "name" = "dktNoVillages",
      "value" = 1,
      "comment" = "the society - somewhat solitary creatures who do not form villages or permanent communities (print capture p. 284)",
    }, {
      "name" = "dktTwoTypes",
      "value" = 1,
      "comment" = "the split - there are two types of tengu, the crow-headed and the humanoid (print capture p. 284)",
    }, {
      "name" = "dktCrowTwoToThreeFeet",
      "value" = 1,
      "comment" = "the crow build - a humanoid two to three feet tall with the head and beak of a crow (print capture p. 284)",
    }, {
      "name" = "dktCrowFeatheredWings",
      "value" = 1,
      "comment" = "the crow wings - feathered wings sprout from between their shoulder blades (print capture p. 284)",
    }, {
      "name" = "dktCrowEvilMalicious",
      "value" = 1,
      "comment" = "the crow temper - evil and malicious, seeking to cause harm to all humans who stray into their territory (print capture p. 284)",
    }, {
      "name" = "dktCrowKatanaWakizashi",
      "value" = 1,
      "comment" = "the crow weapons - they fight with katana and wakizashi (print capture p. 284)",
    }, {
      "name" = "dktCrowSpeaksThree",
      "value" = 1,
      "comment" = "the crow languages - the language of tengu, that of animals, and the human language of the area (print capture p. 284)",
    }, {
      "name" = "dktCrowPerfectMimicry",
      "value" = 1,
      "comment" = "the crow mimicry - able to perfectly mimic voices of those they have heard (print capture p. 284)",
    }, {
      "name" = "dktCrowPolymorphAndShout",
      "value" = 1,
      "comment" = "the crow spells - able to use polymorph self and shout spells three times per day (print capture p. 284)",
    }, {
      "name" = "dktPolymorphPerDay",
      "value" = 3,
      "comment" = "the polymorph uses - the crow tengu use polymorph self and shout three times per day; the humanoid tengu use polymorph self, shout, and phantasmal force three times per day (print capture p. 284)",
    }, {
      "name" = "dktCrowLowerStatus",
      "value" = 1,
      "comment" = "the crow standing - they have lower status than the humanoid tengu and follow orders from these creatures in deference to their rank (print capture p. 284)",
    }, {
      "name" = "dktHumThreeToFourFeet",
      "value" = 1,
      "comment" = "the humanoid build - stand from three to four feet tall (print capture p. 284)",
    }, {
      "name" = "dktHumLongNoses",
      "value" = 1,
      "comment" = "the humanoid look - normal human faces except that the skin is red or blue and their noses are exceptionally long (print capture p. 284)",
    }, {
      "name" = "dktHumStuntedWings",
      "value" = 1,
      "comment" = "the humanoid wings - they may or may not have stunted feathered wings on their backs, growing between their shoulder blades (print capture p. 284)",
    }, {
      "name" = "dktHumThricePowers",
      "value" = 1,
      "comment" = "the humanoid thrice powers - polymorph self, shout, and phantasmal force three times per day (print capture p. 284)",
    }, {
      "name" = "dktHumInvisibleAtWill",
      "value" = 1,
      "comment" = "the humanoid invisibility - become invisible at will (print capture p. 284)",
    }, {
      "name" = "dktHumWeeklyPowers",
      "value" = 1,
      "comment" = "the humanoid weekly powers - reward or ancient curse once per week (print capture p. 284)",
    }, {
      "name" = "dktHumMisdirectionPerTurn",
      "value" = 1,
      "comment" = "the humanoid misdirection - use misdirection once per turn (print capture p. 284)",
    }, {
      "name" = "dktHumGhostLightPerRound",
      "value" = 1,
      "comment" = "the humanoid ghost light - use ghost light once per round (print capture p. 284)",
    }, {
      "name" = "dktHumPerfectMimicry",
      "value" = 1,
      "comment" = "the humanoid mimicry - they can mimic any human or animal sound perfectly (print capture p. 285)",
    }, {
      "name" = "dktHumSpeaksThree",
      "value" = 1,
      "comment" = "the humanoid languages - the language of their own kind, that of the local human population, and the languages of animals (print capture p. 285)",
    }, {
      "name" = "dktHumShukenjaAndKensai",
      "value" = 1,
      "comment" = "the humanoid dual ability - the spellcasting ability of a shukenja and the combat ability of a kensai, both of the same experience level as their hit dice (print capture p. 285)",
    }, {
      "name" = "dktHumOneMartialStyle",
      "value" = 1,
      "comment" = "the humanoid arts - they know one martial arts style with two to five special maneuvers in that style (print capture p. 285)",
    }, {
      "name" = "dktManeuverCountMin",
      "value" = 2,
      "comment" = "the martial arts minimum - the humanoid tengu know one style with two to five special maneuvers, the 2 of the 2-5 (print capture p. 285)",
    }, {
      "name" = "dktManeuverCountMax",
      "value" = 5,
      "comment" = "the martial arts maximum - the 5 of the 2 to 5 special maneuvers in that style (print capture p. 285)",
    }, {
      "name" = "dktHumFeatherFan",
      "value" = 1,
      "comment" = "the humanoid fan - they always carry a fan made of brightly colored feathers (print capture p. 285)",
    }, {
      "name" = "dktHumFanAsKatana",
      "value" = 1,
      "comment" = "the folded fan - the fan has magical properties, allowing it to be used as a normal katana when folded (print capture p. 285)",
    }, {
      "name" = "dktHumFanWindAndGrowth",
      "value" = 1,
      "comment" = "the fanned fan - when fanned it can create a wind equal to a strong gale as per wind breath, cast a quickgrowth spell, or cause abnormal growth or shrinkage of a facial feature, the nose or ears most common (print capture p. 285)",
    }, {
      "name" = "dktHumCruelTricks",
      "value" = 1,
      "comment" = "the humanoid temper - while not evil, they are not overly fond of humans and often play cruel tricks upon humans (print capture p. 285)",
    }, {
      "name" = "dktHumLikesSwordSpecialists",
      "value" = 1,
      "comment" = "the humanoid liking - they have a liking for shukenja, wu jen, and kensai who specialize in the sword (print capture p. 285)",
    }, {
      "name" = "dktHumTutorsKensai",
      "value" = 1,
      "comment" = "the humanoid tutoring - on rare occasions they tutor a sword kensai, teaching him the secrets of their skill, which takes 1 to 3 months and earns the kensai 1,000 XP (print capture p. 285)",
    }, {
      "name" = "dktKensaiTutorMonthsMin",
      "value" = 1,
      "comment" = "the tutoring minimum - the sword kensai tutoring takes 1 to 3 months, the 1 of the 1-3 (print capture p. 285)",
    }, {
      "name" = "dktKensaiTutorMonthsMax",
      "value" = 3,
      "comment" = "the tutoring maximum - the 3 of the 1 to 3 months (print capture p. 285)",
    }, {
      "name" = "dktKensaiTutorXP",
      "value" = 1000,
      "comment" = "the tutoring reward - such tutoring automatically earns the kensai character 1,000 XP (print capture p. 285)",
    }, {
      "name" = "dktSecretiveCapricious",
      "value" = 1,
      "comment" = "the character - all tengu are extremely secretive and capricious (print capture p. 285)",
    }, {
      "name" = "dktLittleKnown",
      "value" = 1,
      "comment" = "the mystery - little is known about their way of life (print capture p. 285)",
    }, {
      "name" = "dktFondOfSake",
      "value" = 1,
      "comment" = "the bribe - quite fond of strong drink and can be bribed, appeased, or befriended with large offerings of sake (print capture p. 285)",
    }, {
      "name" = "dktTasteForMusic",
      "value" = 1,
      "comment" = "the music - they also have a taste for music, particularly that of the flute and drum (print capture p. 285)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dktTenguAppearMin",
      "values" = { 1, 1 },
      "default" = 0,
      "comment" = "the appearing minimum - the 1 of the 1-4 and the 1-3 (print capture p. 284)",
    }, {
      "name" = "dktTenguAppearMax",
      "values" = { 4, 3 },
      "default" = 0,
      "comment" = "the appearing maximum - the 4 and the 3 of the two columns (print capture p. 284)",
    }, {
      "name" = "dktTenguAC",
      "values" = { 6, 4 },
      "default" = 0,
      "comment" = "the armor class - the 6 of the crow and the 4 of the humanoid (print capture p. 284)",
    }, {
      "name" = "dktTenguMoveGround",
      "values" = { 9, 12 },
      "default" = 0,
      "comment" = "the ground move - the 9 of the crow and the 12 whole of the humanoid, the half pinned as dktHumMoveHalf below, the capture misreading 12 1 for the 12 1/2 (print capture p. 284)",
    }, {
      "name" = "dktTenguMoveFly",
      "values" = { 24, 15 },
      "default" = 0,
      "comment" = "the fly move - the 24 of the crow and the 15 of the humanoid (print capture p. 284)",
    }, {
      "name" = "dktTenguHDMin",
      "values" = { 2, 5 },
      "default" = 0,
      "comment" = "the hit dice minimum - the 2 of the 2 to 5 and the 5 of the 5 to 10 (print capture p. 284)",
    }, {
      "name" = "dktTenguHDMax",
      "values" = { 5, 10 },
      "default" = 0,
      "comment" = "the hit dice maximum - the 5 and the 10 of the two ladders (print capture p. 284)",
    }, {
      "name" = "dktTenguLairPct",
      "values" = { 10, 20 },
      "default" = 0,
      "comment" = "the in-lair percent - the 10% and the 20% (print capture p. 284)",
    }, {
      "name" = "dktTenguAttacks",
      "values" = { 1, 2 },
      "default" = 0,
      "comment" = "the attack count - the 1 of the crow and the 2 of the humanoid (print capture p. 284)",
    }, {
      "name" = "dktTenguDmgMin",
      "values" = { 1, 1 },
      "default" = 0,
      "comment" = "the damage minimum - the 1 of the 1-8 and the 1-6 (print capture p. 284)",
    }, {
      "name" = "dktTenguDmgMax",
      "values" = { 8, 6 },
      "default" = 0,
      "comment" = "the damage maximum - the 8 of the 1-8 and the 6 of the 1-6 (print capture p. 284)",
    }, {
      "name" = "dktXPCrowBase",
      "values" = { 28, 50, 85, 130 },
      "default" = 0,
      "comment" = "the crow xp base - the 28, 50, 85, and 130 of the four rungs, the capture misreading 11 for the II and III rungs (print capture p. 284)",
    }, {
      "name" = "dktXPCrowPerHP",
      "values" = { 2, 3, 4, 5 },
      "default" = 0,
      "comment" = "the crow xp per hit point - the 2, 3, 4, and 5 of the four rungs (print capture p. 284)",
    }, {
      "name" = "dktXPHumBase",
      "values" = { 360, 625, 950, 1450, 2300, 3450 },
      "default" = 0,
      "comment" = "the humanoid xp base - the 360, 625, 950, 1,450, 2,300, and 3,450 of the six rungs (print capture p. 284)",
    }, {
      "name" = "dktXPHumPerHP",
      "values" = { 5, 6, 8, 10, 12, 14 },
      "default" = 0,
      "comment" = "the humanoid xp per hit point - the 5, 6, 8, 10, 12, and 14 of the six rungs (print capture p. 284)",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dktTenguCount']() != 2  or m['dktCrowXPCount']() != 4  or m['dktHumXPCount']() != 6  or m['dktPolymorphPerDay']() != 3  or m['dktManeuverCountMin']() != 2  or m['dktManeuverCountMax']() != 5  or m['dktKensaiTutorMonthsMin']() != 1  or m['dktKensaiTutorMonthsMax']() != 3  or m['dktKensaiTutorXP']() != 1000  or  m['dktCrowRare']() != 1  or  m['dktHumRare']() != 1  or  m['dktMCC']() != 1  or  m['dktTreasureC']() != 1  or  m['dktCrowSpecialAttacksSpells']() != 1  or  m['dktHumSpecialAttacksSpells']() != 1  or  m['dktCrowDefensesNil']() != 1  or  m['dktHumInvisibility']() != 1  or  m['dktMRStandard']() != 1  or  m['dktCrowIntLowToAverage']() != 1  or  m['dktHumIntHighToVery']() != 1  or  m['dktCrowChaoticEvil']() != 1  or  m['dktHumChaoticNeutral']() != 1  or  m['dktSizeSmall']() != 1  or  m['dktPsionicNil']() != 1  or  m['dktModesNil']() != 1  or  m['dktHumMoveHalf']() != 1  or  m['dktHumDamageByWeapon']() != 1  or  m['dktBirdlikeHumanoids']() != 1  or  m['dktOriginalInhabitants']() != 1  or  m['dktPushedIntoMountains']() != 1  or  m['dktGladesAndBanks']() != 1  or  m['dktNoVillages']() != 1  or  m['dktTwoTypes']() != 1  or  m['dktCrowTwoToThreeFeet']() != 1  or  m['dktCrowFeatheredWings']() != 1  or  m['dktCrowEvilMalicious']() != 1  or  m['dktCrowKatanaWakizashi']() != 1  or  m['dktCrowSpeaksThree']() != 1  or  m['dktCrowPerfectMimicry']() != 1  or  m['dktCrowPolymorphAndShout']() != 1  or  m['dktCrowLowerStatus']() != 1  or  m['dktHumThreeToFourFeet']() != 1  or  m['dktHumLongNoses']() != 1  or  m['dktHumStuntedWings']() != 1  or  m['dktHumThricePowers']() != 1  or  m['dktHumInvisibleAtWill']() != 1  or  m['dktHumWeeklyPowers']() != 1  or  m['dktHumMisdirectionPerTurn']() != 1  or  m['dktHumGhostLightPerRound']() != 1  or  m['dktHumPerfectMimicry']() != 1  or  m['dktHumSpeaksThree']() != 1  or  m['dktHumShukenjaAndKensai']() != 1  or  m['dktHumOneMartialStyle']() != 1  or  m['dktHumFeatherFan']() != 1  or  m['dktHumFanAsKatana']() != 1  or  m['dktHumFanWindAndGrowth']() != 1  or  m['dktHumCruelTricks']() != 1  or  m['dktHumLikesSwordSpecialists']() != 1  or  m['dktHumTutorsKensai']() != 1  or  m['dktSecretiveCapricious']() != 1  or  m['dktLittleKnown']() != 1  or  m['dktFondOfSake']() != 1  or  m['dktTasteForMusic']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dktCrowRare']() != 1  or m['dktHumRare']() != 1  or m['dktMCC']() != 1  or m['dktTreasureC']() != 1  or m['dktCrowSpecialAttacksSpells']() != 1  or m['dktHumSpecialAttacksSpells']() != 1  or m['dktCrowDefensesNil']() != 1  or m['dktHumInvisibility']() != 1  or m['dktMRStandard']() != 1  or m['dktCrowIntLowToAverage']() != 1  or m['dktHumIntHighToVery']() != 1  or m['dktCrowChaoticEvil']() != 1  or m['dktHumChaoticNeutral']() != 1  or m['dktSizeSmall']() != 1  or m['dktPsionicNil']() != 1  or m['dktModesNil']() != 1  or m['dktHumMoveHalf']() != 1  or m['dktHumDamageByWeapon']() != 1",
      "note" = "the stat grid - the per-column lines, healthy values, each condition false",
    }, {
      "expr" = "m['dktTenguCount']() != 2  or m['dktCrowXPCount']() != 4  or m['dktHumXPCount']() != 6",
      "note" = "the grids - the paired stat table and the two xp ladders, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dktBirdlikeHumanoids']() != 1  or m['dktOriginalInhabitants']() != 1  or m['dktPushedIntoMountains']() != 1  or m['dktGladesAndBanks']() != 1  or m['dktNoVillages']() != 1  or m['dktTwoTypes']() != 1",
      "note" = "the race - the mountain dwellers, healthy values, each condition false",
    }, {
      "expr" = "m['dktCrowTwoToThreeFeet']() != 1  or m['dktCrowFeatheredWings']() != 1  or m['dktCrowEvilMalicious']() != 1  or m['dktCrowKatanaWakizashi']() != 1  or m['dktCrowSpeaksThree']() != 1  or m['dktCrowPerfectMimicry']() != 1  or m['dktCrowPolymorphAndShout']() != 1  or m['dktPolymorphPerDay']() != 3  or m['dktCrowLowerStatus']() != 1",
      "note" = "the crow-headed tengu - the build, the malice, and the powers, healthy values, each condition false",
    }, {
      "expr" = "m['dktHumThreeToFourFeet']() != 1  or m['dktHumLongNoses']() != 1  or m['dktHumStuntedWings']() != 1  or m['dktHumThricePowers']() != 1  or m['dktHumInvisibleAtWill']() != 1  or m['dktHumWeeklyPowers']() != 1  or m['dktHumMisdirectionPerTurn']() != 1  or m['dktHumGhostLightPerRound']() != 1  or m['dktHumPerfectMimicry']() != 1  or m['dktHumSpeaksThree']() != 1  or m['dktHumShukenjaAndKensai']() != 1  or m['dktHumOneMartialStyle']() != 1  or m['dktManeuverCountMin']() != 2  or m['dktManeuverCountMax']() != 5  or m['dktHumFeatherFan']() != 1  or m['dktHumFanAsKatana']() != 1  or m['dktHumFanWindAndGrowth']() != 1",
      "note" = "the humanoid tengu - the look, the powers, and the fan, healthy values, each condition false",
    }, {
      "expr" = "m['dktHumCruelTricks']() != 1  or m['dktHumLikesSwordSpecialists']() != 1  or m['dktHumTutorsKensai']() != 1  or m['dktKensaiTutorMonthsMin']() != 1  or m['dktKensaiTutorMonthsMax']() != 3  or m['dktKensaiTutorXP']() != 1000  or m['dktSecretiveCapricious']() != 1  or m['dktLittleKnown']() != 1  or m['dktFondOfSake']() != 1  or m['dktTasteForMusic']() != 1",
      "note" = "the tricks and the tutoring - the temper and the kensai lessons, healthy values, each condition false",
    }, {
      "expr" = "m['dktTenguAppearMin'](0) != 1 or m['dktTenguAppearMin'](1) != 1 or m['dktTenguAppearMin'](2) != 0 or m['dktTenguAppearMax'](0) != 4 or m['dktTenguAppearMax'](1) != 3 or m['dktTenguAppearMax'](2) != 0 or m['dktTenguAC'](0) != 6 or m['dktTenguAC'](1) != 4",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dktTenguAC'](2) != 0 or m['dktTenguMoveGround'](0) != 9 or m['dktTenguMoveGround'](1) != 12 or m['dktTenguMoveGround'](2) != 0 or m['dktTenguMoveFly'](0) != 24 or m['dktTenguMoveFly'](1) != 15 or m['dktTenguMoveFly'](2) != 0 or m['dktTenguHDMin'](0) != 2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dktTenguHDMin'](1) != 5 or m['dktTenguHDMin'](2) != 0 or m['dktTenguHDMax'](0) != 5 or m['dktTenguHDMax'](1) != 10 or m['dktTenguHDMax'](2) != 0 or m['dktTenguLairPct'](0) != 10 or m['dktTenguLairPct'](1) != 20 or m['dktTenguLairPct'](2) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dktTenguAttacks'](0) != 1 or m['dktTenguAttacks'](1) != 2 or m['dktTenguAttacks'](2) != 0 or m['dktTenguDmgMin'](0) != 1 or m['dktTenguDmgMin'](1) != 1 or m['dktTenguDmgMin'](2) != 0 or m['dktTenguDmgMax'](0) != 8 or m['dktTenguDmgMax'](1) != 6",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dktTenguDmgMax'](2) != 0 or m['dktXPCrowBase'](0) != 28 or m['dktXPCrowBase'](1) != 50 or m['dktXPCrowBase'](2) != 85 or m['dktXPCrowBase'](3) != 130 or m['dktXPCrowBase'](4) != 0 or m['dktXPCrowPerHP'](0) != 2 or m['dktXPCrowPerHP'](1) != 3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dktXPCrowPerHP'](2) != 4 or m['dktXPCrowPerHP'](3) != 5 or m['dktXPCrowPerHP'](4) != 0 or m['dktXPHumBase'](0) != 360 or m['dktXPHumBase'](1) != 625 or m['dktXPHumBase'](2) != 950 or m['dktXPHumBase'](3) != 1450 or m['dktXPHumBase'](4) != 2300",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dktXPHumBase'](5) != 3450 or m['dktXPHumBase'](6) != 0 or m['dktXPHumPerHP'](0) != 5 or m['dktXPHumPerHP'](1) != 6 or m['dktXPHumPerHP'](2) != 8 or m['dktXPHumPerHP'](3) != 10 or m['dktXPHumPerHP'](4) != 12 or m['dktXPHumPerHP'](5) != 14",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dktXPHumPerHP'](6) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R732 OA monsters Tengu audit",
      "comment" = "OA round one hundred nineteen (capture pp. 284-285): the Chapter 12 monster roster - the tengu, the paired stat grid and the two xp ladders riding together with the crow and humanoid descriptions, the capture misreads pinned against the print, single-pass pins per the Chapter 9 provenance shift",
    },
}
