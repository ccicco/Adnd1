-- oa716: promoted from rules/oa87goblinrat.h (the OA MONSTERS - THE GOBLIN RAT, printed capture p. 266 - the shapechanger);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 716,
  "prefix" = "oa716",
  "banner" = {
      "title" = "OA MONSTERS - THE GOBLIN RAT, printed capture p. 266 - the shapechanger",
      "provenance" = "round census 638 -> 639.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 169 closed, 66 open - the goblin rat box flips (census 638 -> 639); NEXT - R717: the Goblin Spider (capture p. 267), prefix dke (verify free at the landing), audit \"R717 OA monsters Goblin Spider audit\", include after rules/oa87goblinrat.h",
    },
  "consts" = { {
      "name" = "dkdAppearMin",
      "value" = 1,
      "comment" = "the appearing minimum - the 1 of the 1-20 appearing (print capture p. 266)",
    }, {
      "name" = "dkdAppearMax",
      "value" = 20,
      "comment" = "the appearing maximum - the 20 of the 1-20 appearing (print capture p. 266)",
    }, {
      "name" = "dkdAC",
      "value" = 7,
      "comment" = "the goblin rat armor class - the AC 7 of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdMove",
      "value" = 9,
      "comment" = "the goblin rat move - the 9 of the move 9 (print capture p. 266)",
    }, {
      "name" = "dkdHD",
      "value" = 3,
      "comment" = "the goblin rat hit dice - the 3 of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdLairPct",
      "value" = 20,
      "comment" = "the in-lair percentage - the 20% of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdFrequencyRare",
      "value" = 1,
      "comment" = "the frequency - the rare of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdTreasureTypeB",
      "value" = 1,
      "comment" = "the treasure type - the B of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdAttackCount",
      "value" = 1,
      "comment" = "the attack count - the 1 of the number of attacks (print capture p. 266)",
    }, {
      "name" = "dkdBiteDmgMin",
      "value" = 1,
      "comment" = "the bite damage minimum - the 1 of the 1-8 or by weapon type (print capture p. 266)",
    }, {
      "name" = "dkdBiteDmgMax",
      "value" = 8,
      "comment" = "the bite damage maximum - the 8 of the 1-8 or by weapon type (print capture p. 266)",
    }, {
      "name" = "dkdDamageByWeaponType",
      "value" = 1,
      "comment" = "the damage clause - the 1-8 or by weapon type of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdSpecialAttacksNil",
      "value" = 1,
      "comment" = "the special attacks - the nil of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdSpecialDefenseShapechange",
      "value" = 1,
      "comment" = "the special defense - the shapechange of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdMagicResistPct",
      "value" = 10,
      "comment" = "the magic resistance - the 10% of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdIntelligenceLowToStandard",
      "value" = 1,
      "comment" = "the intelligence - the low to standard of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdAlignmentLawfulEvil",
      "value" = 1,
      "comment" = "the alignment - the lawful evil of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdSizeSmall",
      "value" = 1,
      "comment" = "the size class - the S of the S 3-4 (print capture p. 266)",
    }, {
      "name" = "dkdSizeMinFeet",
      "value" = 3,
      "comment" = "the size minimum - the 3 of the S 3-4 (print capture p. 266)",
    }, {
      "name" = "dkdSizeMaxFeet",
      "value" = 4,
      "comment" = "the size maximum - the 4 of the S 3-4 (print capture p. 266)",
    }, {
      "name" = "dkdPsionicNil",
      "value" = 1,
      "comment" = "the psionic ability - the nil of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdPsionicModesNil",
      "value" = 1,
      "comment" = "the attack and defense modes - the nil of the stat block (print capture p. 266)",
    }, {
      "name" = "dkdLevelVI",
      "value" = 1,
      "comment" = "the level value - the VI of the VI/1,000 + 10/hp (print capture p. 266)",
    }, {
      "name" = "dkdXPBase",
      "value" = 1000,
      "comment" = "the xp base - the 1,000 of the VI/1,000 + 10 per hp (print capture p. 266)",
    }, {
      "name" = "dkdXPPerHP",
      "value" = 10,
      "comment" = "the xp per hit point - the 10 of the VI/1,000 + 10/hp (print capture p. 266)",
    }, {
      "name" = "dkdHengeyokaiKin",
      "value" = 1,
      "comment" = "the nature - an intelligent shapechanging animal, similar to a hengeyokai (print capture p. 266)",
    }, {
      "name" = "dkdFormsCount",
      "value" = 2,
      "comment" = "the form count - the two forms of the shapechange, the giant rat and the ratman (print capture p. 266)",
    }, {
      "name" = "dkdGiantRatForm",
      "value" = 1,
      "comment" = "the first form - a particularly foul and ugly giant rat (print capture p. 266)",
    }, {
      "name" = "dkdRatmanForm",
      "value" = 1,
      "comment" = "the second form - the ratman of the shapechange (print capture p. 266)",
    }, {
      "name" = "dkdFullHpEitherForm",
      "value" = 1,
      "comment" = "the either-form clause - the full hit points and abilities in either form (print capture p. 266)",
    }, {
      "name" = "dkdAnimalFormBite",
      "value" = 1,
      "comment" = "the animal form attack - while in animal form, the creature attacks with its bite (print capture p. 266)",
    }, {
      "name" = "dkdDiseasePct",
      "value" = 5,
      "comment" = "the bite disease chance - the 5% per successful hit of the animal form (print capture p. 266)",
    }, {
      "name" = "dkdBiteTransmitsDisease",
      "value" = 1,
      "comment" = "the bite disease - each successful hit carries the chance of transmitting a disease to the victim (print capture p. 266)",
    }, {
      "name" = "dkdCommonDiseaseCount",
      "value" = 3,
      "comment" = "the common disease count - the cholera, plague, and fevers (print capture p. 266)",
    }, {
      "name" = "dkdDiseasesCholeraPlagueFever",
      "value" = 1,
      "comment" = "the disease roster - the cholera, plague, and fevers as the most common (print capture p. 266)",
    }, {
      "name" = "dkdRatmanFightsWithWeapons",
      "value" = 1,
      "comment" = "the ratman arms - in its ratman form the goblin rat fights with weapons (print capture p. 266)",
    }, {
      "name" = "dkdRatmanWearsArmor",
      "value" = 1,
      "comment" = "the ratman armor - in its ratman form the goblin rat can wear armor (print capture p. 266)",
    }, {
      "name" = "dkdPreferredWeaponCount",
      "value" = 3,
      "comment" = "the preferred weapon count - the spears, naginatas, and two-handed swords (print capture p. 266)",
    }, {
      "name" = "dkdPrefersSpears",
      "value" = 1,
      "comment" = "the first preferred weapon - the spear (print capture p. 266)",
    }, {
      "name" = "dkdPrefersNaginatas",
      "value" = 1,
      "comment" = "the second preferred weapon - the naginata (print capture p. 266)",
    }, {
      "name" = "dkdPrefersTwoHandedSwords",
      "value" = 1,
      "comment" = "the third preferred weapon - the two-handed sword (print capture p. 266)",
    }, {
      "name" = "dkdKingGroupThreshold",
      "value" = 10,
      "comment" = "the king threshold - the group of 10 or more that has a king (print capture p. 266)",
    }, {
      "name" = "dkdKingCountPerGroup",
      "value" = 1,
      "comment" = "the kings per group - the one king of the 10-plus group (print capture p. 266)",
    }, {
      "name" = "dkdKingHD",
      "value" = 5,
      "comment" = "the king hit dice - the 5 HD of the group king (print capture p. 266)",
    }, {
      "name" = "dkdKingAC",
      "value" = 4,
      "comment" = "the king armor class - the AC 4 of the group king (print capture p. 266)",
    }, {
      "name" = "dkdKingBiteDmgBonus",
      "value" = 2,
      "comment" = "the king bite bonus - the +2 points of damage with the bite (print capture p. 266)",
    }, {
      "name" = "dkdKingOfTheGroup",
      "value" = 1,
      "comment" = "the king - when 10 or more are encountered, one of the creatures is the king of the group (print capture p. 266)",
    }, {
      "name" = "dkdFearsAllFelines",
      "value" = 1,
      "comment" = "the feline fear - the great fear of all types of feline creatures (print capture p. 266)",
    }, {
      "name" = "dkdFelineSaveVsParalyzation",
      "value" = 1,
      "comment" = "the feline save - must make a saving throw vs. paralyzation when faced by a feline (print capture p. 266)",
    }, {
      "name" = "dkdFailedSaveFleesInPanic",
      "value" = 1,
      "comment" = "the failed save - those which fail flee in panic (print capture p. 266)",
    }, {
      "name" = "dkdSuccessfulSaveUnaffected",
      "value" = 1,
      "comment" = "the made save - a successful saving throw leaves the goblin rat unaffected (print capture p. 266)",
    }, {
      "name" = "dkdCatLikeToHitBonus",
      "value" = 1,
      "comment" = "the feline to-hit edge - the +1 on all hit rolls for cat-like creatures (print capture p. 266)",
    }, {
      "name" = "dkdAntipathyAndSuperstition",
      "value" = 1,
      "comment" = "the cat edge source - the antipathy between the two and the superstitious fear of the goblin rats (print capture p. 266)",
    }, {
      "name" = "dkdCatPaintingsWardHousehold",
      "value" = 1,
      "comment" = "the painted ward - even life-like paintings of cats protect a household from goblin rats (print capture p. 266)",
    }, {
      "name" = "dkdWardPaintingOfQuality",
      "value" = 1,
      "comment" = "the ward standard - a life-like painting equals a painting of quality if painted for this express purpose (print capture p. 266)",
    }, {
      "name" = "dkdFringeOfSettlements",
      "value" = 1,
      "comment" = "the habitat - lives on the fringes of human settlements (print capture p. 267)",
    }, {
      "name" = "dkdStealsFoodAndLivestock",
      "value" = 1,
      "comment" = "the raiding - steals food and livestock (print capture p. 267)",
    }, {
      "name" = "dkdPreysOnLoneTravelers",
      "value" = 1,
      "comment" = "the hunting - occasionally preys on lone travelers (print capture p. 267)",
    }, {
      "name" = "dkdLairDesertedTempleOrHut",
      "value" = 1,
      "comment" = "the lair - typically a deserted temple or an abandoned forest hut, the inhabitants slain or driven off (print capture p. 267)",
    }, {
      "name" = "dkdNoLanguageOfOwn",
      "value" = 1,
      "comment" = "the tongue - does not have a language of its own (print capture p. 267)",
    }, {
      "name" = "dkdSpeaksTradeAndHuman",
      "value" = 1,
      "comment" = "the borrowed tongue - speaks the trade language and the local human language (print capture p. 267)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dkdAppearMin']() != 1  or m['dkdAppearMax']() != 20  or m['dkdAC']() != 7  or m['dkdMove']() != 9  or m['dkdHD']() != 3  or m['dkdLairPct']() != 20  or m['dkdAttackCount']() != 1  or m['dkdBiteDmgMin']() != 1  or m['dkdBiteDmgMax']() != 8  or m['dkdMagicResistPct']() != 10  or m['dkdXPBase']() != 1000  or m['dkdXPPerHP']() != 10  or m['dkdDiseasePct']() != 5  or m['dkdKingGroupThreshold']() != 10  or m['dkdKingCountPerGroup']() != 1  or m['dkdKingHD']() != 5  or m['dkdKingAC']() != 4  or m['dkdKingBiteDmgBonus']() != 2  or m['dkdCatLikeToHitBonus']() != 1  or m['dkdFormsCount']() != 2  or m['dkdCommonDiseaseCount']() != 3  or m['dkdPreferredWeaponCount']() != 3  or m['dkdSizeMinFeet']() != 3  or m['dkdSizeMaxFeet']() != 4  or  m['dkdFrequencyRare']() != 1  or  m['dkdTreasureTypeB']() != 1  or  m['dkdDamageByWeaponType']() != 1  or  m['dkdSpecialAttacksNil']() != 1  or  m['dkdSpecialDefenseShapechange']() != 1  or  m['dkdIntelligenceLowToStandard']() != 1  or  m['dkdAlignmentLawfulEvil']() != 1  or  m['dkdSizeSmall']() != 1  or  m['dkdPsionicNil']() != 1  or  m['dkdPsionicModesNil']() != 1  or  m['dkdLevelVI']() != 1  or  m['dkdHengeyokaiKin']() != 1  or  m['dkdGiantRatForm']() != 1  or  m['dkdRatmanForm']() != 1  or  m['dkdFullHpEitherForm']() != 1  or  m['dkdAnimalFormBite']() != 1  or  m['dkdBiteTransmitsDisease']() != 1  or  m['dkdDiseasesCholeraPlagueFever']() != 1  or  m['dkdRatmanFightsWithWeapons']() != 1  or  m['dkdRatmanWearsArmor']() != 1  or  m['dkdPrefersSpears']() != 1  or  m['dkdPrefersNaginatas']() != 1  or  m['dkdPrefersTwoHandedSwords']() != 1  or  m['dkdKingOfTheGroup']() != 1  or  m['dkdFearsAllFelines']() != 1  or  m['dkdFelineSaveVsParalyzation']() != 1  or  m['dkdFailedSaveFleesInPanic']() != 1  or  m['dkdSuccessfulSaveUnaffected']() != 1  or  m['dkdAntipathyAndSuperstition']() != 1  or  m['dkdCatPaintingsWardHousehold']() != 1  or  m['dkdWardPaintingOfQuality']() != 1  or  m['dkdFringeOfSettlements']() != 1  or  m['dkdStealsFoodAndLivestock']() != 1  or  m['dkdPreysOnLoneTravelers']() != 1  or  m['dkdLairDesertedTempleOrHut']() != 1  or  m['dkdNoLanguageOfOwn']() != 1  or  m['dkdSpeaksTradeAndHuman']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dkdAppearMin']() != 1  or m['dkdAppearMax']() != 20  or m['dkdAC']() != 7  or m['dkdMove']() != 9  or m['dkdHD']() != 3  or m['dkdLairPct']() != 20  or m['dkdFrequencyRare']() != 1  or m['dkdTreasureTypeB']() != 1  or m['dkdAttackCount']() != 1  or m['dkdBiteDmgMin']() != 1  or m['dkdBiteDmgMax']() != 8  or m['dkdDamageByWeaponType']() != 1  or m['dkdSpecialAttacksNil']() != 1  or m['dkdSpecialDefenseShapechange']() != 1  or m['dkdMagicResistPct']() != 10  or m['dkdIntelligenceLowToStandard']() != 1  or m['dkdAlignmentLawfulEvil']() != 1  or m['dkdSizeSmall']() != 1  or m['dkdSizeMinFeet']() != 3  or m['dkdSizeMaxFeet']() != 4  or m['dkdPsionicNil']() != 1  or m['dkdPsionicModesNil']() != 1  or m['dkdLevelVI']() != 1  or m['dkdXPBase']() != 1000  or m['dkdXPPerHP']() != 10",
      "note" = "the stat block - the stat block pins, healthy values, each condition false",
    }, {
      "expr" = "m['dkdHengeyokaiKin']() != 1  or m['dkdFormsCount']() != 2  or m['dkdGiantRatForm']() != 1  or m['dkdRatmanForm']() != 1  or m['dkdFullHpEitherForm']() != 1",
      "note" = "the shapechanger - the two-form shapechange, healthy values, each condition false",
    }, {
      "expr" = "m['dkdAnimalFormBite']() != 1  or m['dkdDiseasePct']() != 5  or m['dkdBiteTransmitsDisease']() != 1  or m['dkdCommonDiseaseCount']() != 3  or m['dkdDiseasesCholeraPlagueFever']() != 1  or m['dkdRatmanFightsWithWeapons']() != 1  or m['dkdRatmanWearsArmor']() != 1  or m['dkdPreferredWeaponCount']() != 3  or m['dkdPrefersSpears']() != 1  or m['dkdPrefersNaginatas']() != 1  or m['dkdPrefersTwoHandedSwords']() != 1",
      "note" = "the bite and the ratman arms - the disease bite and the ratman weapons, healthy values, each condition false",
    }, {
      "expr" = "m['dkdKingGroupThreshold']() != 10  or m['dkdKingCountPerGroup']() != 1  or m['dkdKingHD']() != 5  or m['dkdKingAC']() != 4  or m['dkdKingBiteDmgBonus']() != 2  or m['dkdKingOfTheGroup']() != 1",
      "note" = "the king of the group - the 10-plus group king, healthy values, each condition false",
    }, {
      "expr" = "m['dkdFearsAllFelines']() != 1  or m['dkdFelineSaveVsParalyzation']() != 1  or m['dkdFailedSaveFleesInPanic']() != 1  or m['dkdSuccessfulSaveUnaffected']() != 1  or m['dkdCatLikeToHitBonus']() != 1  or m['dkdAntipathyAndSuperstition']() != 1  or m['dkdCatPaintingsWardHousehold']() != 1  or m['dkdWardPaintingOfQuality']() != 1",
      "note" = "the feline antipathy - the feline fear and the cat ward, healthy values, each condition false",
    }, {
      "expr" = "m['dkdFringeOfSettlements']() != 1  or m['dkdStealsFoodAndLivestock']() != 1  or m['dkdPreysOnLoneTravelers']() != 1  or m['dkdLairDesertedTempleOrHut']() != 1  or m['dkdNoLanguageOfOwn']() != 1  or m['dkdSpeaksTradeAndHuman']() != 1",
      "note" = "the lair and the tongue - the fringe habitat and the borrowed tongue, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R716 OA monsters Goblin Rat audit",
      "comment" = "OA round one hundred three (capture p. 266): the Chapter 12 monster roster - the goblin rat, the stat block and the description riding together, single-pass pins per the Chapter 9 provenance shift",
    },
}
