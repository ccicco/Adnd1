-- oa618: promoted from rules/oaraces.h (the THE ORIENTAL RACES, printed capture pp. 17-22 - the OA races round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 618,
  "prefix" = "oa618",
  "banner" = {
      "title" = "THE ORIENTAL RACES, printed capture pp. 17-22 - the OA races round",
      "provenance" = "census 540 -> 541.  verified against capture pp. 17-22 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). OCR NORMALIZATIONS: the capture prints infraction for infravision - the physical copy confirms the clean infravision (a pure OCR garble); the korobokuru save ladder - the physical-copy capture (the 2018 print) reads 4 1/2 CLEAN, the 41h was a transcription artifact of the first capture; pinned as the divisor 2, the flag RESOLVED; the percent signs garble as 7596, 5094 and -2096 - read clean as 75, 50 and -20; the hare prints as here. BOOK QUIRK: the prose cites a badger hengeyokai though badger is not among the twelve Table 11 forms (the evil forms are fox, raccoon dog and rat) - pinned as printed, flagged. The Table 11 modifications pin as four columns: the plus, its ability code (ST 0, DE 1, CO 2, IN 3, WI 4, CH 5), the minus and its code.  the gap census after this round: 27 closed, 208 open - the three races and Table 11 flip; the races run of Chapter 2 is done, the ten classes begin next (census 540 -> 541); NEXT - R619: the Oriental Barbarian and Bushi - the class doctrines, Tables 14, 15, 16 and 17, prefix dgf (verify free), audit \"R619 OA barbarian bushi audit\", include after rules/oaraces.h",
    },
  "consts" = { {
      "name" = "dgeKoroClasses",
      "value" = 4,
      "comment" = "Korobokuru prose (capture p. 17): four permitted classes - barbarian, bushi, samurai, wu jen",
    }, {
      "name" = "dgeKoroSaveDivisor",
      "value" = 2,
      "comment" = "Korobokuru prose (capture p. 17): the saving-throw bonus - +1 for every 4 1/2 points of Constitution vs. rods, staves, wands and spells, and the same vs. poison - the physical-copy capture (the 2018 print) reads 4 1/2 CLEAN - the 41h was a transcription artifact of the first capture; the divisor pins as 2 (half the Con score per +1), the flag resolved",
    }, {
      "name" = "dgeKoroInfravision",
      "value" = 120,
      "comment" = "Korobokuru prose (capture p. 17): infravision range in feet - the OCR prints infraction",
    }, {
      "name" = "dgeKoroPlantIdPct",
      "value" = 66,
      "comment" = "Korobokuru prose (capture p. 17): the chance to recognize and identify normal plants and animals",
    }, {
      "name" = "dgeKoroStrAdj",
      "value" = 1,
      "comment" = "Korobokuru prose (capture p. 18): +1 initial Strength",
    }, {
      "name" = "dgeKoroConAdj",
      "value" = 1,
      "comment" = "Korobokuru prose (capture p. 18): +1 initial Constitution",
    }, {
      "name" = "dgeKoroIntAdj",
      "value" = -2,
      "comment" = "Korobokuru prose (capture p. 18): -2 initial Intelligence",
    }, {
      "name" = "dgeHengeClasses",
      "value" = 4,
      "comment" = "Hengeyokai prose (capture p. 18): four permitted classes - shukenja, kensai, bushi, wu jen; never samurai or ninja (not human)",
    }, {
      "name" = "dgeHengeFormCount",
      "value" = 12,
      "comment" = "Table 11 (capture p. 18): twelve traditional animal forms",
    }, {
      "name" = "dgeHengeFormsPerDay",
      "value" = 1,
      "comment" = "Hengeyokai prose (capture p. 19): form changes per day equal the character level - the 1st-level one-change example, the 3rd-level three",
    }, {
      "name" = "dgeHengeAnimalHpHalved",
      "value" = 2,
      "comment" = "Hengeyokai prose (capture p. 19): animal form carries one-half the hit points, rounded up - the 23-to-12 printed example; wounds carry over point-for-point; no change that would reach 0 or fewer; 0 hit points in any form is death",
    }, {
      "name" = "dgeT11RowCount",
      "value" = 12,
      "comment" = "Table 11 (capture p. 18): twelve creature rows - carp, cat, crab, crane, dog, drake, fox, hare, monkey, raccoon dog, rat, sparrow",
    }, {
      "name" = "dgeT11NoDamage",
      "value" = 0,
      "comment" = "Table 11 (capture p. 18): the dash sentinel - no natural damage",
    }, {
      "name" = "dgeT11NoMove",
      "value" = 0,
      "comment" = "Table 11 (capture p. 18): the dash sentinel - no land, fly or swim movement",
    }, {
      "name" = "dgeT11AlignGood",
      "value" = 1,
      "comment" = "Table 11 (capture p. 18): the any-good alignment tier",
    }, {
      "name" = "dgeT11AlignChaotic",
      "value" = 2,
      "comment" = "Table 11 (capture p. 18): the any-chaotic alignment tier",
    }, {
      "name" = "dgeT11AlignAny",
      "value" = 3,
      "comment" = "Table 11 (capture p. 18): the any alignment tier (crab)",
    }, {
      "name" = "dgeT11AlignEvil",
      "value" = 4,
      "comment" = "Table 11 (capture p. 18): the any-evil alignment tier",
    }, {
      "name" = "dgeSpiritClasses",
      "value" = 3,
      "comment" = "Spirit Folk prose (capture p. 20): three permitted classes - samurai, kensai, bushi",
    }, {
      "name" = "dgeBambooPlantPct",
      "value" = 75,
      "comment" = "Bamboo spirit folk prose (capture p. 21): the chance to identify normal plants",
    }, {
      "name" = "dgeBambooAnimalPct",
      "value" = 50,
      "comment" = "Bamboo spirit folk prose (capture p. 21): the chance to identify normal animals",
    }, {
      "name" = "dgeBambooHidePct",
      "value" = 75,
      "comment" = "Bamboo spirit folk prose (capture p. 21): the chance to hide in shadows in woods or forest",
    }, {
      "name" = "dgeRiverLowerWaterFeet",
      "value" = 10,
      "comment" = "River spirit folk prose (capture p. 21): once per day lower a river or stream 10 feet for five rounds",
    }, {
      "name" = "dgeRiverLowerWaterRounds",
      "value" = 5,
      "comment" = "River spirit folk prose (capture p. 21): the lower-water duration in rounds",
    }, {
      "name" = "dgeSeaWeatherPct",
      "value" = 75,
      "comment" = "Sea spirit folk prose (capture p. 21): once per day predict the next 24 hours of weather at 75 percent (the OCR prints 7596)",
    }, {
      "name" = "dgeSeaWeatherHours",
      "value" = 24,
      "comment" = "Sea spirit folk prose (capture p. 21): the weather prediction window in hours",
    }, {
      "name" = "dgeSeaFavorsPerYear",
      "value" = 1,
      "comment" = "Sea spirit folk prose (capture p. 22): one favor from the sea per year - a specific request; two opposing requests cancel and both lose the favor",
    }, {
      "name" = "dgeSeaGiftHonor",
      "value" = 85,
      "comment" = "Sea spirit folk prose (capture p. 22): at honor 85 the Lord of the Sea bestows a gift - treasure, a service or a magic item (the pearl of rising tide named), no conditions",
    } },
  "bools" = { {
      "name" = "dgeKoroBarbarianCommon",
      "value" = true,
      "comment" = "Korobokuru prose (capture p. 17): barbarians are the most common korobokuru class",
    }, {
      "name" = "dgeKoroSamuraiSponsored",
      "value" = true,
      "comment" = "Korobokuru prose (capture p. 17): korobokuru samurai are rare - they must be sponsored by a human clan",
    }, {
      "name" = "dgeKoroSavePoisonToo",
      "value" = true,
      "comment" = "Korobokuru prose (capture p. 17): the same +1 ladder applies against poison saves",
    }, {
      "name" = "dgeKoroGoblinBonus",
      "value" = true,
      "comment" = "Korobokuru prose (capture p. 17): the +1 to hit bakemono, goblins, goblin rats and hobgoblins",
    }, {
      "name" = "dgeKoroGiantPenalty",
      "value" = true,
      "comment" = "Korobokuru prose (capture p. 17): giants, oni, ogres, ogre magi and titans suffer -4 to hit korobokuru",
    }, {
      "name" = "dgeKoroSizeLimits",
      "value" = true,
      "comment" = "Korobokuru prose (capture p. 17): cannot use the go-daichi, any polearm but the naginata, or any bow but the horsebow",
    }, {
      "name" = "dgeKoroLanguages",
      "value" = true,
      "comment" = "Korobokuru prose (capture p. 18): speak the tribal, trade, spirit-folk and hengeyokai languages; no alignment languages and none learnable",
    }, {
      "name" = "dgeKoroScoreBounds",
      "value" = true,
      "comment" = "Korobokuru prose (capture p. 18): the modified scores cannot exceed 19 nor fall below 8, 12 or 3 respectively - the pre-eligibility modifications",
    }, {
      "name" = "dgeKoroFamilyRequired",
      "value" = true,
      "comment" = "Korobokuru prose (capture p. 18): player characters must belong to a family",
    }, {
      "name" = "dgeHengeNotLycanthrope",
      "value" = true,
      "comment" = "Hengeyokai prose (capture p. 18): shapechange is natural - no moon cycles, no silver susceptibility, no wound transmission, no change-shape healing",
    }, {
      "name" = "dgeHengeChangeRound",
      "value" = true,
      "comment" = "Hengeyokai prose (capture p. 19): changing form takes one complete round; armor and equipment do not change with the body",
    }, {
      "name" = "dgeHengeScoresUnchanged",
      "value" = true,
      "comment" = "Hengeyokai prose (capture p. 19): level and ability scores are unchanged in all forms; the hengeyokai language is speakable in all forms",
    }, {
      "name" = "dgeHengeAnimalReal",
      "value" = true,
      "comment" = "Hengeyokai prose (capture p. 19): the animal form is real, not illusory - undetectable by illusion-revealing spells",
    }, {
      "name" = "dgeHengeAnimalInfravision",
      "value" = true,
      "comment" = "Hengeyokai prose (capture p. 19): infravision 120 feet and speak-with-normal-animals in animal form",
    }, {
      "name" = "dgeHengeAnimalNoGear",
      "value" = true,
      "comment" = "Hengeyokai prose (capture p. 19): no weapons, armor, equipment or spells in animal form; only hengeyokai and animal speech",
    }, {
      "name" = "dgeHengeBipedalFull",
      "value" = true,
      "comment" = "Hengeyokai prose (capture pp. 19-20): bipedal form - full hit points, all languages, infravision 120, all class gear; movement rate 12; no animal movement powers; easily identified",
    }, {
      "name" = "dgeHengeHumanFull",
      "value" = true,
      "comment" = "Hengeyokai prose (capture p. 20): human form - full hit points, all class gear and spells, indistinguishable but for one retained animal feature; no infravision, no animal speech (understanding only), 12 movement",
    }, {
      "name" = "dgeHengeNoClan",
      "value" = true,
      "comment" = "Hengeyokai prose (capture p. 20): hengeyokai belong to no clan - no kinship benefits or penalties; never establish families or strongholds",
    }, {
      "name" = "dgeHengeProtector",
      "value" = true,
      "comment" = "Hengeyokai prose (capture p. 20): good-aligned hengeyokai may become protectors of a family or village at the family-establishing level - offerings of food, gifts and service in return",
    }, {
      "name" = "dgeSpiritFamilyRequired",
      "value" = true,
      "comment" = "Spirit Folk prose (capture p. 20): all spirit folk must belong to a family or clan; they hold land and establish families when class and level allow",
    }, {
      "name" = "dgeSpiritLordSummon",
      "value" = true,
      "comment" = "Spirit Folk prose (capture pp. 20-21): the spirit lord summons must be answered and obeyed - failure or dishonor brings natural disasters on the spirit folk and its human family; the spirit lord wins any conflict of interests",
    }, {
      "name" = "dgeBambooTrail",
      "value" = true,
      "comment" = "Bamboo spirit folk prose (capture p. 21): alone on foot through woodland, forest or grassland - no trail; with others a -20 percent (-4 on 1d20) to track the group",
    }, {
      "name" = "dgeBambooLanguagePerLevel",
      "value" = true,
      "comment" = "Bamboo spirit folk prose (capture p. 21): one forest-animal language learned per experience level, player-chosen",
    }, {
      "name" = "dgeBambooSaveBonus",
      "value" = true,
      "comment" = "Bamboo spirit folk prose (capture p. 21): +1 saves vs. spells, rods, staves, wands and misc. magic of earth and wood",
    }, {
      "name" = "dgeBambooGrove",
      "value" = true,
      "comment" = "Bamboo spirit folk prose (capture p. 21): the life force tied to a bamboo grove - grove damage suffers equal damage, grove destruction is instant death, entering the grove cures all wounds and diseases; the grove never moves, its shoots carry no power",
    }, {
      "name" = "dgeRiverBreatheSwim",
      "value" = true,
      "comment" = "River spirit folk prose (capture p. 21): breathe in any fresh water, swim at normal rate, carried items stay perfectly dry",
    }, {
      "name" = "dgeRiverSaveBonus",
      "value" = true,
      "comment" = "River spirit folk prose (capture p. 21): +1 saves vs. water-elemental magic; -1 vs. fire attacks",
    }, {
      "name" = "dgeRiverLanguages",
      "value" = true,
      "comment" = "River spirit folk prose (capture p. 21): speak the fish language, the court language and the trade language",
    }, {
      "name" = "dgeRiverLifeForce",
      "value" = true,
      "comment" = "River spirit folk prose (capture p. 21): the life force tied to one river in its natural banks - bathing cures all; drought weakens, flooding maddens, damming kills; drawn-off water is no longer the river",
    }, {
      "name" = "dgeSeaBreatheSwim",
      "value" = true,
      "comment" = "Sea spirit folk prose (capture p. 21): breathe any salt water, swim at normal rate, gear never wets",
    }, {
      "name" = "dgeSeaSaveBonus",
      "value" = true,
      "comment" = "Sea spirit folk prose (capture p. 21): +1 saves vs. fire-based attacks",
    }, {
      "name" = "dgeSeaNoSeaTie",
      "value" = true,
      "comment" = "Sea spirit folk prose (capture p. 22): unaffected by changes in the sea and gain no healing from it",
    } },
  "switches" = { {
      "name" = "dgeT11Align",
      "values" = { 1, 2, 3, 1, 1, 1, 4, 1, 2, 4, 4, 1 },
      "default" = -99,
      "comment" = "the alignment tier column: good (carp, crane, dog, drake, hare, sparrow), chaotic (cat, monkey), any (crab), evil (fox, raccoon dog, rat) (capture p. 18).",
    }, {
      "name" = "dgeT11DmgDie",
      "values" = { 0, 3, 3, 2, 6, 0, 3, 0, 0, 6, 3, 0 },
      "default" = -99,
      "comment" = "the damage-die column: the natural-weapon die - 0 for the dash (carp, drake, hare, monkey, sparrow), 2 for the crane 1-2, 3 for the cat-crab-fox-rat 1-3, 6 for the dog and raccoon dog 1-6 (capture p. 18).",
    }, {
      "name" = "dgeT11Ac",
      "values" = { 7, 9, 8, 9, 9, 7, 6, 5, 6, 9, 5, 3 },
      "default" = -99,
      "comment" = "the animal-form AC column: sparrow 3, hare 5, rat 5, fox 6, monkey 6, carp 7, drake 7, crab 8, cat 9, crane 9, dog 9, raccoon dog 9 (capture p. 18).",
    }, {
      "name" = "dgeT11Move",
      "values" = { 0, 12, 3, 6, 12, 6, 15, 18, 12, 9, 9, 3 },
      "default" = -99,
      "comment" = "the land movement column: crab and sparrow 3, crane and drake 6, cat-dog-monkey 12, raccoon dog and rat 9, fox 15, hare 18, carp 0 - the carp cannot cross land (capture p. 18).",
    }, {
      "name" = "dgeT11Fly",
      "values" = { 0, 0, 0, 12, 0, 12, 0, 0, 0, 0, 0, 15 },
      "default" = -99,
      "comment" = "the fly column: crane, drake and sparrow 12, 12 and 15; zero elsewhere (capture p. 18).",
    }, {
      "name" = "dgeT11Swim",
      "values" = { 12, 0, 6, 0, 0, 9, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the swim column: carp 12, crab 6, drake 9; zero elsewhere (capture p. 18).",
    }, {
      "name" = "dgeT11Plus",
      "values" = { 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2 },
      "default" = -99,
      "comment" = "the ability plus column: the +1 or +2 of the modifications (capture p. 18).",
    }, {
      "name" = "dgeT11PlusAb",
      "values" = { 2, 1, 0, 2, 3, 4, 3, 2, 1, 0, 3, 4 },
      "default" = -99,
      "comment" = "the ability code column: ST 0, DE 1, CO 2, IN 3, WI 4, CH 5 - the plus-ability of the modifications (capture p. 18).",
    }, {
      "name" = "dgeT11Minus",
      "values" = { -1, -1, -2, -1, -1, -1, -1, -1, -2, -2, -2, -2 },
      "default" = -99,
      "comment" = "the ability minus column: the -1 or -2 of the modifications (capture p. 18).",
    }, {
      "name" = "dgeT11MinusAb",
      "values" = { 0, 2, 4, 1, 3, 1, 2, 0, 2, 2, 4, 3 },
      "default" = -99,
      "comment" = "the minus-ability code column: the minus-ability of the modifications (capture p. 18).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgeKoroClasses']() != 4  or m['dgeKoroSaveDivisor']() != 2  or m['dgeKoroInfravision']() != 120  or m['dgeKoroPlantIdPct']() != 66  or m['dgeKoroStrAdj']() != 1  or m['dgeKoroConAdj']() != 1  or m['dgeKoroIntAdj']() != -2  or m['dgeHengeClasses']() != 4  or m['dgeHengeFormCount']() != 12  or m['dgeHengeFormsPerDay']() != 1  or m['dgeHengeAnimalHpHalved']() != 2  or m['dgeT11RowCount']() != 12  or m['dgeT11NoDamage']() != 0  or m['dgeT11NoMove']() != 0  or m['dgeT11AlignGood']() != 1  or m['dgeT11AlignChaotic']() != 2  or m['dgeT11AlignAny']() != 3  or m['dgeT11AlignEvil']() != 4  or m['dgeSpiritClasses']() != 3  or m['dgeBambooPlantPct']() != 75  or m['dgeBambooAnimalPct']() != 50  or m['dgeBambooHidePct']() != 75  or m['dgeRiverLowerWaterFeet']() != 10  or m['dgeRiverLowerWaterRounds']() != 5  or m['dgeSeaWeatherPct']() != 75  or m['dgeSeaWeatherHours']() != 24  or m['dgeSeaFavorsPerYear']() != 1  or m['dgeSeaGiftHonor']() != 85  or  m['dgeKoroBarbarianCommon']() != 1  or  m['dgeKoroSamuraiSponsored']() != 1  or  m['dgeKoroSavePoisonToo']() != 1  or  m['dgeKoroGoblinBonus']() != 1  or  m['dgeKoroGiantPenalty']() != 1  or  m['dgeKoroSizeLimits']() != 1  or  m['dgeKoroLanguages']() != 1  or  m['dgeKoroScoreBounds']() != 1  or  m['dgeKoroFamilyRequired']() != 1  or  m['dgeHengeNotLycanthrope']() != 1  or  m['dgeHengeChangeRound']() != 1  or  m['dgeHengeScoresUnchanged']() != 1  or  m['dgeHengeAnimalReal']() != 1  or  m['dgeHengeAnimalInfravision']() != 1  or  m['dgeHengeAnimalNoGear']() != 1  or  m['dgeHengeBipedalFull']() != 1  or  m['dgeHengeHumanFull']() != 1  or  m['dgeHengeNoClan']() != 1  or  m['dgeHengeProtector']() != 1  or  m['dgeSpiritFamilyRequired']() != 1  or  m['dgeSpiritLordSummon']() != 1  or  m['dgeBambooTrail']() != 1  or  m['dgeBambooLanguagePerLevel']() != 1  or  m['dgeBambooSaveBonus']() != 1  or  m['dgeBambooGrove']() != 1  or  m['dgeRiverBreatheSwim']() != 1  or  m['dgeRiverSaveBonus']() != 1  or  m['dgeRiverLanguages']() != 1  or  m['dgeRiverLifeForce']() != 1  or  m['dgeSeaBreatheSwim']() != 1  or  m['dgeSeaSaveBonus']() != 1  or  m['dgeSeaNoSeaTie']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgeKoroClasses']() != 4",
      "note" = "the dgeKoroClasses pin",
    }, {
      "expr" = "m['dgeKoroBarbarianCommon']() != 1",
      "note" = "the dgeKoroBarbarianCommon pin",
    }, {
      "expr" = "m['dgeKoroSamuraiSponsored']() != 1",
      "note" = "the dgeKoroSamuraiSponsored pin",
    }, {
      "expr" = "m['dgeKoroSaveDivisor']() != 2",
      "note" = "the dgeKoroSaveDivisor pin",
    }, {
      "expr" = "m['dgeKoroSavePoisonToo']() != 1",
      "note" = "the dgeKoroSavePoisonToo pin",
    }, {
      "expr" = "m['dgeKoroInfravision']() != 120",
      "note" = "the dgeKoroInfravision pin",
    }, {
      "expr" = "m['dgeKoroPlantIdPct']() != 66",
      "note" = "the dgeKoroPlantIdPct pin",
    }, {
      "expr" = "m['dgeKoroGoblinBonus']() != 1",
      "note" = "the dgeKoroGoblinBonus pin",
    }, {
      "expr" = "m['dgeKoroGiantPenalty']() != 1",
      "note" = "the dgeKoroGiantPenalty pin",
    }, {
      "expr" = "m['dgeKoroSizeLimits']() != 1",
      "note" = "the dgeKoroSizeLimits pin",
    }, {
      "expr" = "m['dgeKoroLanguages']() != 1",
      "note" = "the dgeKoroLanguages pin",
    }, {
      "expr" = "m['dgeKoroStrAdj']() != 1",
      "note" = "the dgeKoroStrAdj pin",
    }, {
      "expr" = "m['dgeKoroConAdj']() != 1",
      "note" = "the dgeKoroConAdj pin",
    }, {
      "expr" = "m['dgeKoroIntAdj']() != -2",
      "note" = "the dgeKoroIntAdj pin",
    }, {
      "expr" = "m['dgeKoroScoreBounds']() != 1",
      "note" = "the dgeKoroScoreBounds pin",
    }, {
      "expr" = "m['dgeKoroFamilyRequired']() != 1",
      "note" = "the dgeKoroFamilyRequired pin",
    }, {
      "expr" = "m['dgeHengeNotLycanthrope']() != 1",
      "note" = "the dgeHengeNotLycanthrope pin",
    }, {
      "expr" = "m['dgeHengeClasses']() != 4",
      "note" = "the dgeHengeClasses pin",
    }, {
      "expr" = "m['dgeHengeFormCount']() != 12",
      "note" = "the dgeHengeFormCount pin",
    }, {
      "expr" = "m['dgeHengeFormsPerDay']() != 1",
      "note" = "the dgeHengeFormsPerDay pin",
    }, {
      "expr" = "m['dgeHengeChangeRound']() != 1",
      "note" = "the dgeHengeChangeRound pin",
    }, {
      "expr" = "m['dgeHengeScoresUnchanged']() != 1",
      "note" = "the dgeHengeScoresUnchanged pin",
    }, {
      "expr" = "m['dgeHengeAnimalReal']() != 1",
      "note" = "the dgeHengeAnimalReal pin",
    }, {
      "expr" = "m['dgeHengeAnimalInfravision']() != 1",
      "note" = "the dgeHengeAnimalInfravision pin",
    }, {
      "expr" = "m['dgeHengeAnimalNoGear']() != 1",
      "note" = "the dgeHengeAnimalNoGear pin",
    }, {
      "expr" = "m['dgeHengeAnimalHpHalved']() != 2",
      "note" = "the dgeHengeAnimalHpHalved pin",
    }, {
      "expr" = "m['dgeHengeBipedalFull']() != 1",
      "note" = "the dgeHengeBipedalFull pin",
    }, {
      "expr" = "m['dgeHengeHumanFull']() != 1",
      "note" = "the dgeHengeHumanFull pin",
    }, {
      "expr" = "m['dgeHengeNoClan']() != 1",
      "note" = "the dgeHengeNoClan pin",
    }, {
      "expr" = "m['dgeHengeProtector']() != 1",
      "note" = "the dgeHengeProtector pin",
    }, {
      "expr" = "m['dgeT11RowCount']() != 12",
      "note" = "the dgeT11RowCount pin",
    }, {
      "expr" = "m['dgeT11NoDamage']() != 0",
      "note" = "the dgeT11NoDamage pin",
    }, {
      "expr" = "m['dgeT11NoMove']() != 0",
      "note" = "the dgeT11NoMove pin",
    }, {
      "expr" = "m['dgeT11AlignGood']() != 1",
      "note" = "the dgeT11AlignGood pin",
    }, {
      "expr" = "m['dgeT11AlignChaotic']() != 2",
      "note" = "the dgeT11AlignChaotic pin",
    }, {
      "expr" = "m['dgeT11AlignAny']() != 3",
      "note" = "the dgeT11AlignAny pin",
    }, {
      "expr" = "m['dgeT11AlignEvil']() != 4",
      "note" = "the dgeT11AlignEvil pin",
    }, {
      "expr" = "m['dgeSpiritClasses']() != 3",
      "note" = "the dgeSpiritClasses pin",
    }, {
      "expr" = "m['dgeSpiritFamilyRequired']() != 1",
      "note" = "the dgeSpiritFamilyRequired pin",
    }, {
      "expr" = "m['dgeSpiritLordSummon']() != 1",
      "note" = "the dgeSpiritLordSummon pin",
    }, {
      "expr" = "m['dgeBambooPlantPct']() != 75",
      "note" = "the dgeBambooPlantPct pin",
    }, {
      "expr" = "m['dgeBambooAnimalPct']() != 50",
      "note" = "the dgeBambooAnimalPct pin",
    }, {
      "expr" = "m['dgeBambooTrail']() != 1",
      "note" = "the dgeBambooTrail pin",
    }, {
      "expr" = "m['dgeBambooHidePct']() != 75",
      "note" = "the dgeBambooHidePct pin",
    }, {
      "expr" = "m['dgeBambooLanguagePerLevel']() != 1",
      "note" = "the dgeBambooLanguagePerLevel pin",
    }, {
      "expr" = "m['dgeBambooSaveBonus']() != 1",
      "note" = "the dgeBambooSaveBonus pin",
    }, {
      "expr" = "m['dgeBambooGrove']() != 1",
      "note" = "the dgeBambooGrove pin",
    }, {
      "expr" = "m['dgeRiverBreatheSwim']() != 1",
      "note" = "the dgeRiverBreatheSwim pin",
    }, {
      "expr" = "m['dgeRiverLowerWaterFeet']() != 10",
      "note" = "the dgeRiverLowerWaterFeet pin",
    }, {
      "expr" = "m['dgeRiverLowerWaterRounds']() != 5",
      "note" = "the dgeRiverLowerWaterRounds pin",
    }, {
      "expr" = "m['dgeRiverSaveBonus']() != 1",
      "note" = "the dgeRiverSaveBonus pin",
    }, {
      "expr" = "m['dgeRiverLanguages']() != 1",
      "note" = "the dgeRiverLanguages pin",
    }, {
      "expr" = "m['dgeRiverLifeForce']() != 1",
      "note" = "the dgeRiverLifeForce pin",
    }, {
      "expr" = "m['dgeSeaBreatheSwim']() != 1",
      "note" = "the dgeSeaBreatheSwim pin",
    }, {
      "expr" = "m['dgeSeaWeatherPct']() != 75",
      "note" = "the dgeSeaWeatherPct pin",
    }, {
      "expr" = "m['dgeSeaWeatherHours']() != 24",
      "note" = "the dgeSeaWeatherHours pin",
    }, {
      "expr" = "m['dgeSeaSaveBonus']() != 1",
      "note" = "the dgeSeaSaveBonus pin",
    }, {
      "expr" = "m['dgeSeaNoSeaTie']() != 1",
      "note" = "the dgeSeaNoSeaTie pin",
    }, {
      "expr" = "m['dgeSeaFavorsPerYear']() != 1",
      "note" = "the dgeSeaFavorsPerYear pin",
    }, {
      "expr" = "m['dgeSeaGiftHonor']() != 85",
      "note" = "the dgeSeaGiftHonor pin",
    }, {
      "expr" = "m['dgeT11Move'](0) != 0  or m['dgeT11Swim'](0) != 12",
      "note" = "the carp cannot cross land but swims 12 (capture p. 18)",
    }, {
      "expr" = "m['dgeT11Move'](7) != 18",
      "note" = "the hare is the fastest land form at 18 (capture p. 18)",
    }, {
      "expr" = "m['dgeT11Fly'](11) != 15  or m['dgeT11Ac'](11) != 3",
      "note" = "the sparrow flies 15 and has AC 3 (capture p. 18)",
    }, {
      "expr" = "m['dgeT11Align'](2) != 3",
      "note" = "the crab takes any alignment (capture p. 18)",
    }, {
      "expr" = "m['dgeT11DmgDie'](4) != 6",
      "note" = "the dog damage is 1-6 (capture p. 18)",
    }, {
      "expr" = "m['dgeKoroStrAdj']() +m['dgeKoroConAdj']() +m['dgeKoroIntAdj']() != 0",
      "note" = "the korobokuru ability adjustments sum (capture p. 18)",
    }, {
      "expr" = "m['dgeHengeFormsPerDay']() != 1",
      "note" = "the hengeyokai change count equals the level (capture p. 19)",
    }, {
      "expr" = "m['dgeRiverLowerWaterFeet']() != 10  or m['dgeRiverLowerWaterRounds']() != 5",
      "note" = "the river lower-water pair (capture p. 21)",
    }, {
      "expr" = "m['dgeBambooPlantPct']() !=m['dgeBambooHidePct']()",
      "note" = "the bamboo plant and hide chances both print 75 (capture p. 21)",
    }, {
      "expr" = "m['dgeSeaWeatherHours']() != 24",
      "note" = "the sea weather prediction window (capture p. 21)",
    }, {
      "expr" = "m['dgeT11Plus'](0) != 1 or m['dgeT11Plus'](1) != 1 or m['dgeT11Plus'](2) != 2 or m['dgeT11Plus'](3) != 1 or m['dgeT11Plus'](4) != 1 or m['dgeT11Plus'](5) != 1 or m['dgeT11Plus'](6) != 1 or m['dgeT11Plus'](7) != 1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgeT11Plus'](8) != 2 or m['dgeT11Plus'](9) != 2 or m['dgeT11Plus'](10) != 2 or m['dgeT11Plus'](11) != 2 or m['dgeT11Plus'](12) != -99 or m['dgeT11PlusAb'](0) != 2 or m['dgeT11PlusAb'](1) != 1 or m['dgeT11PlusAb'](2) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgeT11PlusAb'](3) != 2 or m['dgeT11PlusAb'](4) != 3 or m['dgeT11PlusAb'](5) != 4 or m['dgeT11PlusAb'](6) != 3 or m['dgeT11PlusAb'](7) != 2 or m['dgeT11PlusAb'](8) != 1 or m['dgeT11PlusAb'](9) != 0 or m['dgeT11PlusAb'](10) != 3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgeT11PlusAb'](11) != 4 or m['dgeT11PlusAb'](12) != -99 or m['dgeT11Minus'](0) != -1 or m['dgeT11Minus'](1) != -1 or m['dgeT11Minus'](2) != -2 or m['dgeT11Minus'](3) != -1 or m['dgeT11Minus'](4) != -1 or m['dgeT11Minus'](5) != -1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgeT11Minus'](6) != -1 or m['dgeT11Minus'](7) != -1 or m['dgeT11Minus'](8) != -2 or m['dgeT11Minus'](9) != -2 or m['dgeT11Minus'](10) != -2 or m['dgeT11Minus'](11) != -2 or m['dgeT11Minus'](12) != -99 or m['dgeT11MinusAb'](0) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgeT11MinusAb'](1) != 2 or m['dgeT11MinusAb'](2) != 4 or m['dgeT11MinusAb'](3) != 1 or m['dgeT11MinusAb'](4) != 3 or m['dgeT11MinusAb'](5) != 1 or m['dgeT11MinusAb'](6) != 2 or m['dgeT11MinusAb'](7) != 0 or m['dgeT11MinusAb'](8) != 2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgeT11MinusAb'](9) != 2 or m['dgeT11MinusAb'](10) != 4 or m['dgeT11MinusAb'](11) != 3 or m['dgeT11MinusAb'](12) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R618 OA races audit",
      "comment" = "OA round five (capture pp. 17-22): the three nonhuman races - the korobokuru save ladders and ability modifications, the hengeyokai form doctrine with the Table 11 twelve-creature grid, and the three spirit folk powers with their life-force ties.",
    },
}
