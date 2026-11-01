-- oa728: promoted from rules/oa99oni.h (the OA MONSTERS - THE ONI, printed capture pp. 280-281 - the fearsome spirit);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 728,
  "prefix" = "oa728",
  "banner" = {
      "title" = "OA MONSTERS - THE ONI, printed capture pp. 280-281 - the fearsome spirit",
      "provenance" = "round census 650 -> 651.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 181 closed, 54 open - the oni box flips (census 650 -> 651); NEXT - R729: the P oh, the Lesser Spirit (capture pp. 281-282), prefix dkq (verify free at the landing), audit \"R729 OA monsters P oh audit\", include after rules/oa99oni.h",
    },
  "consts" = { {
      "name" = "dkpOniCount",
      "value" = 3,
      "comment" = "the oni table row count - the common, the go-zu, and the me-zu of the stat grid (print capture p. 280)",
    }, {
      "name" = "dkpCommonOniCommon",
      "value" = 1,
      "comment" = "the common oni frequency - the common of the stat grid header (print capture p. 280)",
    }, {
      "name" = "dkpGoZuVeryRare",
      "value" = 1,
      "comment" = "the go-zu frequency - the very rare of the stat grid header (print capture p. 280)",
    }, {
      "name" = "dkpMeZuVeryRare",
      "value" = 1,
      "comment" = "the me-zu frequency - the very rare of the stat grid header (print capture p. 280)",
    }, {
      "name" = "dkpCommonChaoticEvil",
      "value" = 1,
      "comment" = "the common oni alignment - the lawful evil of the stat grid, the capture row reading Lawful evil (print capture p. 280)",
    }, {
      "name" = "dkpGoZuMeZuLawfulNeutral",
      "value" = 1,
      "comment" = "the go-zu and me-zu alignment - the lawful neutral of both columns of the stat grid (print capture p. 280)",
    }, {
      "name" = "dkpCommonIntAverage",
      "value" = 1,
      "comment" = "the common oni intelligence - the average of the stat grid (print capture p. 280)",
    }, {
      "name" = "dkpGoZuMeZuIntHigh",
      "value" = 1,
      "comment" = "the go-zu and me-zu intelligence - the high of both columns (print capture p. 280)",
    }, {
      "name" = "dkpSizeLarge",
      "value" = 1,
      "comment" = "the size class - the L of all three columns of the stat grid (print capture p. 280)",
    }, {
      "name" = "dkpPsionicNil",
      "value" = 1,
      "comment" = "the psionic ability - the nil of all three columns (print capture p. 280)",
    }, {
      "name" = "dkpModesNil",
      "value" = 1,
      "comment" = "the attack and defense modes - the nil of all three columns (print capture p. 280)",
    }, {
      "name" = "dkpCommonSpecialAttacksSpells",
      "value" = 1,
      "comment" = "the common oni special attacks - the spells of the stat grid (print capture p. 280)",
    }, {
      "name" = "dkpGoZuMeZuSpecialSeeBelow",
      "value" = 1,
      "comment" = "the go-zu and me-zu special attacks - the see below of both columns (print capture p. 280)",
    }, {
      "name" = "dkpCommonDefensesNil",
      "value" = 1,
      "comment" = "the common oni special defenses - the nil of the stat grid (print capture p. 280)",
    }, {
      "name" = "dkpGoZuMeZuRegeneration",
      "value" = 1,
      "comment" = "the go-zu and me-zu special defenses - the regeneration of both columns (print capture p. 280)",
    }, {
      "name" = "dkpCommonMRStandard",
      "value" = 1,
      "comment" = "the common oni magic resistance - the standard of the stat grid (print capture p. 280)",
    }, {
      "name" = "dkpFearsomeSpirits",
      "value" = 1,
      "comment" = "the nature - the oni are fearsome spirits who dwell in desolate and forbidding places (print capture p. 280)",
    }, {
      "name" = "dkpSevenToEightFeet",
      "value" = 1,
      "comment" = "the common height - stand seven to eight feet tall (print capture p. 280)",
    }, {
      "name" = "dkpOneToThreeEyes",
      "value" = 1,
      "comment" = "the eyes - have one to three eyes (print capture p. 280)",
    }, {
      "name" = "dkpOneOrTwoHorns",
      "value" = 1,
      "comment" = "the horns - one or two horns on their head (print capture p. 280)",
    }, {
      "name" = "dkpCoarseHairLimbs",
      "value" = 1,
      "comment" = "the limbs - arms and legs covered with coarse hair (print capture p. 280)",
    }, {
      "name" = "dkpDirtyThickTalons",
      "value" = 1,
      "comment" = "the hands - they end in dirty, thick talons (print capture p. 280)",
    }, {
      "name" = "dkpSkinNormallyRed",
      "value" = 1,
      "comment" = "the skin - normally red, but other colors including green, black, orange, and purple have been seen (print capture p. 280)",
    }, {
      "name" = "dkpBlueSkinnedOgreMagi",
      "value" = 1,
      "comment" = "the blue skins - there are also blue-skinned oni, although these are more commonly known as ogre magi (print capture p. 280)",
    }, {
      "name" = "dkpDressImitatesHumans",
      "value" = 1,
      "comment" = "the dress - imitates that of the local human population, although more ragged and dirty than their human counterparts (print capture p. 280)",
    }, {
      "name" = "dkpCommonHaunts",
      "value" = 1,
      "comment" = "the common haunts - found living in rocky mountain regions, deserted ruins, graveyards, and other sites commonly considered haunted (print capture p. 280)",
    }, {
      "name" = "dkpHighwayShrineTerror",
      "value" = 1,
      "comment" = "the highway clause - occasionally they take up residence along a lonely highway at a shrine or gate, terrorizing all who go by (print capture p. 280)",
    }, {
      "name" = "dkpBloodthirstyCruel",
      "value" = 1,
      "comment" = "the temper - bloodthirsty and cruel, attacking for food and the sheer delight of cruelty (print capture p. 280)",
    }, {
      "name" = "dkpTwoHandedSwordOrClaws",
      "value" = 1,
      "comment" = "the common weapons - they commonly fight with two-handed swords wielded in one hand or their powerful claws (print capture p. 280)",
    }, {
      "name" = "dkpPolymorphSelfPerDay",
      "value" = 3,
      "comment" = "the common oni polymorph uses - polymorph self three times per day (print capture p. 280)",
    }, {
      "name" = "dkpFlyPerDay",
      "value" = 3,
      "comment" = "the common oni fly uses - fly as per the spell three times per day (print capture p. 280)",
    }, {
      "name" = "dkpInvisiblePerDay",
      "value" = 2,
      "comment" = "the common oni invisible uses - become invisible two times per day (print capture p. 280)",
    }, {
      "name" = "dkpCloudTrapezePerDay",
      "value" = 1,
      "comment" = "the common oni cloud trapeze uses - for themselves only once per day (print capture p. 280)",
    }, {
      "name" = "dkpCauseFearAtWill",
      "value" = 1,
      "comment" = "the fear power - cause fear at will (print capture p. 280)",
    }, {
      "name" = "dkpCommandsLesserCreatures",
      "value" = 1,
      "comment" = "the command - frequently found in command of lesser creatures such as bakemono, goblin rats, and gaki (print capture p. 280)",
    }, {
      "name" = "dkpCommonSummonChancePct",
      "value" = 10,
      "comment" = "the summon chance - the 10% chance the common oni commands lesser creatures (print capture p. 280)",
    }, {
      "name" = "dkpCommonSummonDice",
      "value" = 10,
      "comment" = "the summon die - when encountered there is a 10% chance the oni is accompanied by 2d10 of these creatures, the die of the 2d10 (print capture p. 280)",
    }, {
      "name" = "dkpLairCourt",
      "value" = 1,
      "comment" = "the lair court - encountered in their lair there are always 4d10 bakemono or goblin rats present, attending the court of the more powerful oni (print capture p. 281)",
    }, {
      "name" = "dkpLairGuardDice",
      "value" = 10,
      "comment" = "the lair guard die - in their lair there are always 4d10 bakemono or goblin rats present, the die of the 4d10 (print capture p. 281)",
    }, {
      "name" = "dkpCommonSpeaksFive",
      "value" = 1,
      "comment" = "the common languages - able to speak the language of their kind and the languages of tengu, bakemono, hengeyokai, and the local human population (print capture p. 281)",
    }, {
      "name" = "dkpGoZuBullHeads",
      "value" = 1,
      "comment" = "the go-zu heads - stand eight to nine feet tall with a hulking body and the heads of bulls (print capture p. 281)",
    }, {
      "name" = "dkpGoZuHeightMinFt",
      "value" = 8,
      "comment" = "the go-zu height minimum - the eight of the eight to nine feet tall (print capture p. 281)",
    }, {
      "name" = "dkpGoZuHeightMaxFt",
      "value" = 9,
      "comment" = "the go-zu height maximum - the nine of the eight to nine feet tall (print capture p. 281)",
    }, {
      "name" = "dkpGoZuCelestialSoldiers",
      "value" = 1,
      "comment" = "the go-zu standing - unlike the common oni, servants and soldiers of the Celestial Empire (print capture p. 281)",
    }, {
      "name" = "dkpGoZuMeZuEmperorsArmy",
      "value" = 1,
      "comment" = "the army clause - the go-zu and the me-zu form the bulk of the Celestial Emperor army in times of trouble and insurrection (print capture p. 281)",
    }, {
      "name" = "dkpGoZuOverseeLandsOfDead",
      "value" = 1,
      "comment" = "the dead lands - they also oversee the lands of the dead and escort the reluctant departed there (print capture p. 281)",
    }, {
      "name" = "dkpGoZuSoldierDress",
      "value" = 1,
      "comment" = "the go-zu dress - they dress in armor and robes appropriate to their position as soldiers of the Celestial Emperor (print capture p. 281)",
    }, {
      "name" = "dkpGoZuWeaponRoster",
      "value" = 1,
      "comment" = "the go-zu weapons - they fight with two-handed swords, spears, naginata, halberds, and tridents (print capture p. 281)",
    }, {
      "name" = "dkpGoZuTwoAttacksAndGore",
      "value" = 1,
      "comment" = "the go-zu combat - able to make two attacks with a weapon or their hands per round and gore with their horns (print capture p. 281)",
    }, {
      "name" = "dkpGoZuAtWillPowers",
      "value" = 1,
      "comment" = "the go-zu at-will powers - polymorph self, cause fear, become invisible, fly, and cast fire shuriken (print capture p. 281)",
    }, {
      "name" = "dkpGoZuCloudTrapezeTwicePerDay",
      "value" = 1,
      "comment" = "the go-zu cloud trapeze - twice per day (print capture p. 281)",
    }, {
      "name" = "dkpGoZuAutoDetectInvisible",
      "value" = 1,
      "comment" = "the go-zu detection - they can automatically detect invisible creatures and objects (print capture p. 281)",
    }, {
      "name" = "dkpCommonRegenPerRound",
      "value" = 3,
      "comment" = "the regeneration rate - the go-zu and me-zu regenerate 3 hit points per round (print capture p. 281)",
    }, {
      "name" = "dkpGoZuHillGiantStrength",
      "value" = 1,
      "comment" = "the go-zu strength - equal to that of a hill giant (print capture p. 281)",
    }, {
      "name" = "dkpGoZuLanguages",
      "value" = 1,
      "comment" = "the go-zu languages - all human languages and those of tengu, oni, bakemono, animals, and the Celestial Court (print capture p. 281)",
    }, {
      "name" = "dkpMeZuMostImportant",
      "value" = 1,
      "comment" = "the me-zu standing - the most important of all oni (print capture p. 281)",
    }, {
      "name" = "dkpMeZuHorseHeads",
      "value" = 1,
      "comment" = "the me-zu look - ogre sized with the heads of horses (print capture p. 281)",
    }, {
      "name" = "dkpMeZuHigherRank",
      "value" = 1,
      "comment" = "the me-zu rank - like the go-zu, servants and soldiers of the Celestial Emperor, although generally holding positions of higher rank within his army (print capture p. 281)",
    }, {
      "name" = "dkpMeZuWhipsAndLassos",
      "value" = 1,
      "comment" = "the me-zu extra tools - in addition to the weapons used by the go-zu oni, they are also known to use whips and lassos to deal with their victims (print capture p. 281)",
    }, {
      "name" = "dkpMeZuAtWillPowers",
      "value" = 1,
      "comment" = "the me-zu at-will powers - polymorph self, become invisible, cause fear, and fly (print capture p. 281)",
    }, {
      "name" = "dkpMeZuEtherealAstralTwicePerDay",
      "value" = 1,
      "comment" = "the me-zu plane shifts - become ethereal or astral two times per day (print capture p. 281)",
    }, {
      "name" = "dkpMeZuCloudTrapezeThricePerDay",
      "value" = 1,
      "comment" = "the me-zu cloud trapeze - three times per day (print capture p. 281)",
    }, {
      "name" = "dkpMeZuWuJenSpellcasting",
      "value" = 1,
      "comment" = "the me-zu spellcasting - the spell casting ability of a wu jen of the same experience level as their hit dice (print capture p. 281)",
    }, {
      "name" = "dkpMeZuTrueSeeingAlways",
      "value" = 1,
      "comment" = "the me-zu sight - the sight abilities as per the true seeing spell in effect at all times (print capture p. 281)",
    }, {
      "name" = "dkpMeZuAnyLanguage",
      "value" = 1,
      "comment" = "the me-zu languages - able to speak and understand any language (print capture p. 281)",
    }, {
      "name" = "dkpMeZuStoneGiantStrength",
      "value" = 1,
      "comment" = "the me-zu strength - equal to that of a stone giant (print capture p. 281)",
    }, {
      "name" = "dkpMeZuOnCelestialMission",
      "value" = 1,
      "comment" = "the me-zu errand - when encountered they are on some mission assigned by the Celestial Empire and do not brook any interference or delay to this mission (print capture p. 281)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dkpOniAppearMin",
      "values" = { 1, 1, 1 },
      "default" = 0,
      "comment" = "the appearing minimum - the 1 of the 1-100, 1-20, and 1-20; the capture misreads i-100 for the 1-100 of the common (print capture p. 280)",
    }, {
      "name" = "dkpOniAppearMax",
      "values" = { 100, 20, 20 },
      "default" = 0,
      "comment" = "the appearing maximum - the 100 and the 20 and the 20 of the three columns (print capture p. 280)",
    }, {
      "name" = "dkpOniAC",
      "values" = { 4, 0, 2 },
      "default" = 0,
      "comment" = "the armor class - the 4, the 0, and the 2 of the three columns (print capture p. 280)",
    }, {
      "name" = "dkpOniMove",
      "values" = { 9, 9, 12 },
      "default" = 0,
      "comment" = "the move - the 9, the 9, and the 12 (print capture p. 280)",
    }, {
      "name" = "dkpOniHD",
      "values" = { 8, 12, 10 },
      "default" = 0,
      "comment" = "the hit dice - the 8, the 12, and the 10 of the three columns (print capture p. 280)",
    }, {
      "name" = "dkpOniHDBonus",
      "values" = { 0, 8, 5 },
      "default" = 0,
      "comment" = "the hit dice bonus - the 0 of the common, the 8 of the 12 + 8, and the 5 of the 10 + 5 (print capture p. 280)",
    }, {
      "name" = "dkpOniAttacks",
      "values" = { 2, 3, 2 },
      "default" = 0,
      "comment" = "the attack count - the 2, the 3, and the 2 (print capture p. 280)",
    }, {
      "name" = "dkpOniMRPct",
      "values" = { 0, 20, 40 },
      "default" = 0,
      "comment" = "the magic resistance - the 0 of the common standard, the 20%, and the 40% (print capture p. 280)",
    }, {
      "name" = "dkpOniXPBase",
      "values" = { 650, 5250, 3150 },
      "default" = 0,
      "comment" = "the xp base - the 650 of the VI/650 + 10, the 5,250 of the VIII/5,250 + 16, and the 3,150 of the VIII/3,150 + 14 (print capture p. 280)",
    }, {
      "name" = "dkpOniXPPerHP",
      "values" = { 10, 16, 14 },
      "default" = 0,
      "comment" = "the xp per hit point - the 10, the 16, and the 14 of the three xp lines (print capture p. 280)",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dkpOniCount']() != 3  or m['dkpCommonRegenPerRound']() != 3  or m['dkpCommonSummonDice']() != 10  or m['dkpCommonSummonChancePct']() != 10  or m['dkpLairGuardDice']() != 10  or m['dkpGoZuHeightMinFt']() != 8  or m['dkpGoZuHeightMaxFt']() != 9  or m['dkpPolymorphSelfPerDay']() != 3  or m['dkpFlyPerDay']() != 3  or m['dkpInvisiblePerDay']() != 2  or m['dkpCloudTrapezePerDay']() != 1  or  m['dkpCommonOniCommon']() != 1  or  m['dkpGoZuVeryRare']() != 1  or  m['dkpMeZuVeryRare']() != 1  or  m['dkpCommonChaoticEvil']() != 1  or  m['dkpGoZuMeZuLawfulNeutral']() != 1  or  m['dkpCommonIntAverage']() != 1  or  m['dkpGoZuMeZuIntHigh']() != 1  or  m['dkpSizeLarge']() != 1  or  m['dkpPsionicNil']() != 1  or  m['dkpModesNil']() != 1  or  m['dkpCommonSpecialAttacksSpells']() != 1  or  m['dkpGoZuMeZuSpecialSeeBelow']() != 1  or  m['dkpCommonDefensesNil']() != 1  or  m['dkpGoZuMeZuRegeneration']() != 1  or  m['dkpCommonMRStandard']() != 1  or  m['dkpFearsomeSpirits']() != 1  or  m['dkpSevenToEightFeet']() != 1  or  m['dkpOneToThreeEyes']() != 1  or  m['dkpOneOrTwoHorns']() != 1  or  m['dkpCoarseHairLimbs']() != 1  or  m['dkpDirtyThickTalons']() != 1  or  m['dkpSkinNormallyRed']() != 1  or  m['dkpBlueSkinnedOgreMagi']() != 1  or  m['dkpDressImitatesHumans']() != 1  or  m['dkpCommonHaunts']() != 1  or  m['dkpHighwayShrineTerror']() != 1  or  m['dkpBloodthirstyCruel']() != 1  or  m['dkpTwoHandedSwordOrClaws']() != 1  or  m['dkpCauseFearAtWill']() != 1  or  m['dkpCommandsLesserCreatures']() != 1  or  m['dkpLairCourt']() != 1  or  m['dkpCommonSpeaksFive']() != 1  or  m['dkpGoZuBullHeads']() != 1  or  m['dkpGoZuCelestialSoldiers']() != 1  or  m['dkpGoZuMeZuEmperorsArmy']() != 1  or  m['dkpGoZuOverseeLandsOfDead']() != 1  or  m['dkpGoZuSoldierDress']() != 1  or  m['dkpGoZuWeaponRoster']() != 1  or  m['dkpGoZuTwoAttacksAndGore']() != 1  or  m['dkpGoZuAtWillPowers']() != 1  or  m['dkpGoZuCloudTrapezeTwicePerDay']() != 1  or  m['dkpGoZuAutoDetectInvisible']() != 1  or  m['dkpGoZuHillGiantStrength']() != 1  or  m['dkpGoZuLanguages']() != 1  or  m['dkpMeZuMostImportant']() != 1  or  m['dkpMeZuHorseHeads']() != 1  or  m['dkpMeZuHigherRank']() != 1  or  m['dkpMeZuWhipsAndLassos']() != 1  or  m['dkpMeZuAtWillPowers']() != 1  or  m['dkpMeZuEtherealAstralTwicePerDay']() != 1  or  m['dkpMeZuCloudTrapezeThricePerDay']() != 1  or  m['dkpMeZuWuJenSpellcasting']() != 1  or  m['dkpMeZuTrueSeeingAlways']() != 1  or  m['dkpMeZuAnyLanguage']() != 1  or  m['dkpMeZuStoneGiantStrength']() != 1  or  m['dkpMeZuOnCelestialMission']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dkpCommonOniCommon']() != 1  or m['dkpGoZuVeryRare']() != 1  or m['dkpMeZuVeryRare']() != 1  or m['dkpCommonChaoticEvil']() != 1  or m['dkpGoZuMeZuLawfulNeutral']() != 1  or m['dkpCommonIntAverage']() != 1  or m['dkpGoZuMeZuIntHigh']() != 1  or m['dkpSizeLarge']() != 1  or m['dkpPsionicNil']() != 1  or m['dkpModesNil']() != 1  or m['dkpCommonSpecialAttacksSpells']() != 1  or m['dkpGoZuMeZuSpecialSeeBelow']() != 1  or m['dkpCommonDefensesNil']() != 1  or m['dkpGoZuMeZuRegeneration']() != 1  or m['dkpCommonMRStandard']() != 1",
      "note" = "the stat grid - the per-type lines, healthy values, each condition false",
    }, {
      "expr" = "m['dkpOniCount']() != 3",
      "note" = "the oni grid - the three-column stat table, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dkpFearsomeSpirits']() != 1  or m['dkpSevenToEightFeet']() != 1  or m['dkpOneToThreeEyes']() != 1  or m['dkpOneOrTwoHorns']() != 1  or m['dkpCoarseHairLimbs']() != 1  or m['dkpDirtyThickTalons']() != 1  or m['dkpSkinNormallyRed']() != 1  or m['dkpBlueSkinnedOgreMagi']() != 1  or m['dkpDressImitatesHumans']() != 1",
      "note" = "the fearsome spirit - the look and the dress, healthy values, each condition false",
    }, {
      "expr" = "m['dkpCommonHaunts']() != 1  or m['dkpHighwayShrineTerror']() != 1  or m['dkpBloodthirstyCruel']() != 1  or m['dkpTwoHandedSwordOrClaws']() != 1  or m['dkpPolymorphSelfPerDay']() != 3  or m['dkpFlyPerDay']() != 3  or m['dkpInvisiblePerDay']() != 2  or m['dkpCloudTrapezePerDay']() != 1  or m['dkpCauseFearAtWill']() != 1  or m['dkpCommandsLesserCreatures']() != 1  or m['dkpCommonSummonChancePct']() != 10  or m['dkpCommonSummonDice']() != 10  or m['dkpLairCourt']() != 1  or m['dkpLairGuardDice']() != 10  or m['dkpCommonSpeaksFive']() != 1",
      "note" = "the common oni - the haunts, the powers, and the court, healthy values, each condition false",
    }, {
      "expr" = "m['dkpGoZuBullHeads']() != 1  or m['dkpGoZuHeightMinFt']() != 8  or m['dkpGoZuHeightMaxFt']() != 9  or m['dkpGoZuCelestialSoldiers']() != 1  or m['dkpGoZuMeZuEmperorsArmy']() != 1  or m['dkpGoZuOverseeLandsOfDead']() != 1  or m['dkpGoZuSoldierDress']() != 1  or m['dkpGoZuWeaponRoster']() != 1  or m['dkpGoZuTwoAttacksAndGore']() != 1  or m['dkpGoZuAtWillPowers']() != 1  or m['dkpGoZuCloudTrapezeTwicePerDay']() != 1  or m['dkpGoZuAutoDetectInvisible']() != 1  or m['dkpCommonRegenPerRound']() != 3  or m['dkpGoZuHillGiantStrength']() != 1  or m['dkpGoZuLanguages']() != 1",
      "note" = "the go-zu oni - the bull-headed soldiers of the Celestial Empire, healthy values, each condition false",
    }, {
      "expr" = "m['dkpMeZuMostImportant']() != 1  or m['dkpMeZuHorseHeads']() != 1  or m['dkpMeZuHigherRank']() != 1  or m['dkpMeZuWhipsAndLassos']() != 1  or m['dkpMeZuAtWillPowers']() != 1  or m['dkpMeZuEtherealAstralTwicePerDay']() != 1  or m['dkpMeZuCloudTrapezeThricePerDay']() != 1  or m['dkpMeZuWuJenSpellcasting']() != 1  or m['dkpMeZuTrueSeeingAlways']() != 1  or m['dkpMeZuAnyLanguage']() != 1  or m['dkpMeZuStoneGiantStrength']() != 1  or m['dkpMeZuOnCelestialMission']() != 1",
      "note" = "the me-zu oni - the horse-headed officers, healthy values, each condition false",
    }, {
      "expr" = "m['dkpOniAppearMin'](0) != 1 or m['dkpOniAppearMin'](1) != 1 or m['dkpOniAppearMin'](2) != 1 or m['dkpOniAppearMin'](3) != 0 or m['dkpOniAppearMax'](0) != 100 or m['dkpOniAppearMax'](1) != 20 or m['dkpOniAppearMax'](2) != 20 or m['dkpOniAppearMax'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkpOniAC'](0) != 4 or m['dkpOniAC'](1) != 0 or m['dkpOniAC'](2) != 2 or m['dkpOniAC'](3) != 0 or m['dkpOniMove'](0) != 9 or m['dkpOniMove'](1) != 9 or m['dkpOniMove'](2) != 12 or m['dkpOniMove'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkpOniHD'](0) != 8 or m['dkpOniHD'](1) != 12 or m['dkpOniHD'](2) != 10 or m['dkpOniHD'](3) != 0 or m['dkpOniHDBonus'](0) != 0 or m['dkpOniHDBonus'](1) != 8 or m['dkpOniHDBonus'](2) != 5 or m['dkpOniHDBonus'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkpOniAttacks'](0) != 2 or m['dkpOniAttacks'](1) != 3 or m['dkpOniAttacks'](2) != 2 or m['dkpOniAttacks'](3) != 0 or m['dkpOniMRPct'](0) != 0 or m['dkpOniMRPct'](1) != 20 or m['dkpOniMRPct'](2) != 40 or m['dkpOniMRPct'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkpOniXPBase'](0) != 650 or m['dkpOniXPBase'](1) != 5250 or m['dkpOniXPBase'](2) != 3150 or m['dkpOniXPBase'](3) != 0 or m['dkpOniXPPerHP'](0) != 10 or m['dkpOniXPPerHP'](1) != 16 or m['dkpOniXPPerHP'](2) != 14 or m['dkpOniXPPerHP'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R728 OA monsters Oni audit",
      "comment" = "OA round one hundred fifteen (capture pp. 280-281): the Chapter 12 monster roster - the oni, the three-column stat grid of the common, the go-zu, and the me-zu riding together with the fearsome spirit descriptions, the capture misreads pinned against the print, single-pass pins per the Chapter 9 provenance shift",
    },
}
