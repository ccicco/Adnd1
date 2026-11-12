-- myt: promoted from tools/spec_r920.json (the The Dragon issue-12 opener part two - the Persian Mythos by Jerome Arkenberg (folios 8-11) and the Lovecraftian Mythos by Rob Kuntz with J. Eric Holmes (folios 18-21): the mythos pair, both GD&H-compatible);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 920,
  "prefix" = "myt",
  "banner" = {
      "title" = "The Dragon issue-12 opener part two - the Persian Mythos by Jerome Arkenberg (folios 8-11) and the Lovecraftian Mythos by Rob Kuntz with J. Eric Holmes (folios 18-21): the mythos pair, both GD&H-compatible",
      "provenance" = "Pinned from The Dragon Vol. II No. 6 (February 1978), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 12; the source lives in the archive.org item accessory-dragon-magazine-012, file Accessory - Dragon Magazine #012_djvu.xml). PRINT FOLIO = PDF PAGE, verified at the TOC alignments (5, 6, 8, 12, 13, 18, 28). The transcripts ride extract/dragon/012/p001 through p032, landed at R919; the article CHAIN is the ink unit, not the folio.",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: the Persian grid's Atar armor-class and psionic cells print bar garbles and the Vayu move prints 187/36 for the 18/36 dual rate; the hero strength cells print as fraction garbles - Yima 185 (18/95), Hoshang 189 (18/90), Takhmoruw 1859 (18/59), Faridun 18;;, Keresaspa 18,5 (18/50) - all riding the -1 sentinel with the census, the clean stats pinning clean; the unlimited hit-point and spell cells of Ahura Mazda and Ahriman print words and ride the sentinel; the Lovecraftian grid's see-below magic cells and resistant-to-all-psionic cells ride the sentinel, and the Yig split armor class pins as head-3 chest-5 consts with the grid cell riding the sentinel. The one-visual-check precedent of R919 (the full-res scan plus the djvu word geometry) stands for any future cell dispute.",
    },
  "consts" = { {
      "name" = "mytPersianRows",
      "value" = 13,
      "comment" = "the Persian Mythos stat grid - thirteen rows: Ahura Mazda, Ahriman, the archangel block, the seven yazatas, the hero block, the archdemon block and the demon block (folios 8-11)",
    }, {
      "name" = "mytPersianHeroRows",
      "value" = 6,
      "comment" = "the six Persian heroes on the common block - Yima, Hoshang, Takhmoruw, Thrita, Faridun and Keresaspa (folio 10)",
    }, {
      "name" = "mytPersianArchangels",
      "value" = 7,
      "comment" = "the seven archangels of Ahura Mazda on the common stat block - Vohu Manah, Asha, Kshathra Vairya, Armaiti, Haurvatat and Ameretat, Sraosha and Mithra (folios 8-9)",
    }, {
      "name" = "mytPersianYazatas",
      "value" = 7,
      "comment" = "the seven yazatas - Vayu, Tishtrya, Ardvi Sura Anahita, Verethragna, Rapithwin, Atar and Haoma (folio 9)",
    }, {
      "name" = "mytSraoshaBattleAxePlus",
      "value" = 3,
      "comment" = "Sraosha is a warrior in armor armed with a battle axe +3 (folio 8)",
    }, {
      "name" = "mytMithraPikePlus",
      "value" = 1,
      "comment" = "Mithra wields a pike of silver +1 (folio 9)",
    }, {
      "name" = "mytMithraArmorPlus",
      "value" = 3,
      "comment" = "Mithra wears gold armor +3 (folio 9)",
    }, {
      "name" = "mytVayuSpearPlus",
      "value" = 1,
      "comment" = "Vayu carries a sharp spear +1 (folio 9)",
    }, {
      "name" = "mytVayuGoldWeaponsPlus",
      "value" = 2,
      "comment" = "the rest of Vayu's weapons are gold, all +2 to hit (folio 9)",
    }, {
      "name" = "mytTishtryaForms",
      "value" = 3,
      "comment" = "Tishtrya takes three forms - a boy of fifteen, a bull and a horse (folio 9)",
    }, {
      "name" = "mytVerethragnaForms",
      "value" = 10,
      "comment" = "Verethragna has ten forms, from a strong wind to a man with a golden sword (folio 9)",
    }, {
      "name" = "mytGOORows",
      "value" = 9,
      "comment" = "the Great Old Ones stat grid - nine rows: Azathoth, Cthulhu, Hastur, Nyarlathotep, Shub-Niggurath, Cthuga, Ithaqua, Yig and Yog Sothoth (folios 18-21)",
    }, {
      "name" = "mytRaceRows",
      "value" = 6,
      "comment" = "the inhuman and partly-human races grid - six rows: the Byakhee, the Deep Ones, the Great Race, the Old Ones, the Mi-Go and the Shaggoths (folio 21)",
    }, {
      "name" = "mytCallDestroyedPercent",
      "value" = 25,
      "comment" = "evil callers run a 25 percent chance of being destroyed by the gods they evoke (folio 18)",
    }, {
      "name" = "mytCallServantPercent",
      "value" = 50,
      "comment" = "a 50 percent chance of a servant of the Old Ones appearing to a caller (folio 18)",
    }, {
      "name" = "mytCallGodPercent",
      "value" = 25,
      "comment" = "a 25 percent chance of the god itself appearing and cooperating (folio 18)",
    }, {
      "name" = "mytRavageMinTurns",
      "value" = 1,
      "comment" = "an attacking god ravages the countryside for 1-6 turns, the floor (folio 18)",
    }, {
      "name" = "mytRavageMaxTurns",
      "value" = 6,
      "comment" = "the ravage ceiling, 1-6 turns, then the god disappears (folio 18)",
    }, {
      "name" = "mytAzathothSaveVsMagic",
      "value" = 5,
      "comment" = "Azathoth's saving throw against all forms of magic is 5 (folio 18)",
    }, {
      "name" = "mytCthulhuRegen",
      "value" = 10,
      "comment" = "Cthulhu regenerates 10 hit points per melee round (folio 18)",
    }, {
      "name" = "mytCthulhuInsanityRadiusMiles",
      "value" = 100,
      "comment" = "if the Elder Seal breaks, everyone within 100 miles saves or goes insane (folio 18)",
    }, {
      "name" = "mytCthulhuDeepOnesMin",
      "value" = 10,
      "comment" = "Cthulhu calls up 10-100 Deep Ones from the sea, the floor (folio 18)",
    }, {
      "name" = "mytCthulhuDeepOnesMax",
      "value" = 100,
      "comment" = "the Deep One call ceiling, 10-100 (folio 18)",
    }, {
      "name" = "mytHasturRegen",
      "value" = 5,
      "comment" = "Hastur regenerates 5 hits per melee round (folio 18)",
    }, {
      "name" = "mytHasturFlyInches",
      "value" = 36,
      "comment" = "Hastur moves 12 and flies 36 (folio 18)",
    }, {
      "name" = "mytHasturCallsMin",
      "value" = 1,
      "comment" = "Hastur calls 1-10 Byakhee or Mi-Go from Lost Carcosa and Yuggoth, the floor (folio 18)",
    }, {
      "name" = "mytHasturCallsMax",
      "value" = 10,
      "comment" = "the Byakhee-or-Mi-Go call ceiling, 1-10 (folio 18)",
    }, {
      "name" = "mytNyarlathotepCharmRadiusFeet",
      "value" = 30,
      "comment" = "Nyarlathotep's presence-charm covers a 30-foot radius (folio 18)",
    }, {
      "name" = "mytNyarlathotepCharmSavePenalty",
      "value" = 2,
      "comment" = "the Nyarlathotep charm saves are made at -2 to the die roll (folio 18)",
    }, {
      "name" = "mytNyarlathotepArmyMin",
      "value" = 10,
      "comment" = "Nyarlathotep calls an army of 10-1000 wild beasts or mindless humans, the floor (folio 18)",
    }, {
      "name" = "mytNyarlathotepArmyMax",
      "value" = 1000,
      "comment" = "the army call ceiling, 10-1000 (folio 18)",
    }, {
      "name" = "mytShubPoolDiameterFeet",
      "value" = 100,
      "comment" = "the Shub-Niggurath grey pool is 100 feet across (folio 18)",
    }, {
      "name" = "mytShubSpawnMin",
      "value" = 1,
      "comment" = "the pool puts forth 1-10 small monsters per melee round, the floor (folio 18)",
    }, {
      "name" = "mytShubSpawnMax",
      "value" = 10,
      "comment" = "the spawn ceiling, 1-10 per melee round (folio 18)",
    }, {
      "name" = "mytShubCharmLevel",
      "value" = 15,
      "comment" = "Shub-Niggurath throws charm person or monster spells of the 15th level, once per turn (folio 18)",
    }, {
      "name" = "mytCthugaFireSpellsPerDay",
      "value" = 3,
      "comment" = "Cthuga uses all fire-connected spells three times a day for each spell (folio 20)",
    }, {
      "name" = "mytCthugaFireElementals",
      "value" = 8,
      "comment" = "Cthuga summons up to 8 twelve-hit-die fire elementals, once per week (folio 20)",
    }, {
      "name" = "mytCthugaElementalHD",
      "value" = 12,
      "comment" = "the Cthuga fire elementals are 12-hit-die flame creatures (folio 20)",
    }, {
      "name" = "mytCthugaDamageMin",
      "value" = 3,
      "comment" = "Cthuga strikes once per melee round for 3-30 points of fire damage, the floor (folio 20)",
    }, {
      "name" = "mytCthugaDamageMax",
      "value" = 30,
      "comment" = "the Cthuga strike ceiling, 3-30 (folio 20)",
    }, {
      "name" = "mytCthugaIgnitionRadiusYards",
      "value" = 10,
      "comment" = "Cthuga ignites flammables within a 10-yard radius of his body (folio 20)",
    }, {
      "name" = "mytCthugaWeaponPlusNeeded",
      "value" = 3,
      "comment" = "Cthuga may only be struck effectively by +3 or better weapons (folio 20)",
    }, {
      "name" = "mytIthaquaAirElementalHD",
      "value" = 16,
      "comment" = "Ithaqua summons one 16-die air elemental per day (folio 20)",
    }, {
      "name" = "mytIthaquaDamageMin",
      "value" = 2,
      "comment" = "Ithaqua strikes twice per melee round doing 2-16 points of buffet damage per hit, the floor (folio 20)",
    }, {
      "name" = "mytIthaquaDamageMax",
      "value" = 16,
      "comment" = "the buffet ceiling, 2-16 per hit (folio 20)",
    }, {
      "name" = "mytIthaquaFireExtraPerDie",
      "value" = 2,
      "comment" = "Ithaqua takes 2 hit points extra per die of magical fire damage (folio 20)",
    }, {
      "name" = "mytYigHeadAc",
      "value" = 3,
      "comment" = "Yig's split armor class - 3 for the head (folio 20)",
    }, {
      "name" = "mytYigBodyAc",
      "value" = 5,
      "comment" = "Yig's split armor class - 5 for the chest and underbelly (folio 20)",
    }, {
      "name" = "mytYigSurpriseMin",
      "value" = 1,
      "comment" = "Yig surprises opponents on a six-sided die roll of 1-4, the floor (folio 20)",
    }, {
      "name" = "mytYigSurpriseMax",
      "value" = 4,
      "comment" = "the Yig surprise ceiling, 1-4 (folio 20)",
    }, {
      "name" = "mytYigControlRadiusMiles",
      "value" = 1,
      "comment" = "Yig controls all serpents within a one-square-mile radius of himself (folio 20)",
    }, {
      "name" = "mytYigSnakesMin",
      "value" = 2,
      "comment" = "near his lair Yig is attended by 2-20 giant venomous snakes, the floor (folio 20)",
    }, {
      "name" = "mytYigSnakesMax",
      "value" = 20,
      "comment" = "the attendant-snake ceiling, 2-20 (folio 20)",
    }, {
      "name" = "mytYigSnakeHDMin",
      "value" = 4,
      "comment" = "the attendant giant snakes are 4-6 hit die, the floor (folio 20)",
    }, {
      "name" = "mytYigSnakeHDMax",
      "value" = 6,
      "comment" = "the attendant-snake hit-die ceiling, 4-6 (folio 20)",
    }, {
      "name" = "mytYigFangDamageMin",
      "value" = 2,
      "comment" = "Yig strikes for 2-11 hit points of fang damage, the floor (folio 20)",
    }, {
      "name" = "mytYigFangDamageMax",
      "value" = 11,
      "comment" = "the fang ceiling, 2-11 (folio 20)",
    }, {
      "name" = "mytYigPoisonSavePenalty",
      "value" = 3,
      "comment" = "the Yig poison save rolls at -3 to the die roll, failure dying immediately (folio 20)",
    }, {
      "name" = "mytYogGatesPerMelee",
      "value" = 1,
      "comment" = "Yog Sothoth gates one spawn, subject race or D&D demon in or out per melee round (folio 20)",
    }, {
      "name" = "mytByakheeTalonDamageMin",
      "value" = 2,
      "comment" = "the Byakhee talons do 2-12 points of damage, the floor (folio 21)",
    }, {
      "name" = "mytByakheeTalonDamageMax",
      "value" = 12,
      "comment" = "the talon ceiling, 2-12 (folio 21)",
    }, {
      "name" = "mytByakheeBeakDamageMin",
      "value" = 2,
      "comment" = "the Byakhee beak does 2-9 points of damage, the floor (folio 21)",
    }, {
      "name" = "mytByakheeBeakDamageMax",
      "value" = 9,
      "comment" = "the beak ceiling, 2-9 (folio 21)",
    }, {
      "name" = "mytDeepOnesMin",
      "value" = 1,
      "comment" = "the Deep Ones appear in numbers of 1-100, the floor (folio 21)",
    }, {
      "name" = "mytDeepOnesMax",
      "value" = 100,
      "comment" = "the Deep One appearance ceiling, 1-100 (folio 21)",
    }, {
      "name" = "mytDeepOnesClericMin",
      "value" = 3,
      "comment" = "every large Deep One group has at least one evil cleric of level 3-10, the floor (folio 21)",
    }, {
      "name" = "mytDeepOnesClericMax",
      "value" = 10,
      "comment" = "the Deep One cleric ceiling, level 3-10 (folio 21)",
    }, {
      "name" = "mytMiGoFlyInches",
      "value" = 30,
      "comment" = "the Mi-Go move 15 and fly 30 (folio 21)",
    }, {
      "name" = "mytElderSignAc",
      "value" = -2,
      "comment" = "the Elder Sign grey stone stars are armor class minus 2, broken only by magic or incredible force (folio 20)",
    }, {
      "name" = "mytNecronomiconMadnessPercent",
      "value" = 25,
      "comment" = "characters below level 5 reading the Necronomicon run a 25 percent chance of chaotic-evil alignment change or madness, DM-adjusted (folio 20)",
    }, {
      "name" = "mytNecronomiconLevelCutoff",
      "value" = 5,
      "comment" = "the Necronomicon madness roll applies below level 5 (folio 20)",
    } },
  "bools" = { {
      "name" = "mytPersianDualistSplit",
      "value" = true,
      "comment" = "the Persian gods split dualist - the forces of good are Lawful, the forces of evil Chaotic (folio 8)",
    }, {
      "name" = "mytHaomaPlantAndGod",
      "value" = true,
      "comment" = "Haoma is both plant and god, dying pressed and defeating evil for the faithful (folio 9)",
    }, {
      "name" = "mytTishtryaSustainedBySacrifice",
      "value" = true,
      "comment" = "Tishtrya fights greatly in any form only when animal sacrifices sustain him (folio 9)",
    }, {
      "name" = "mytAzathothMindless",
      "value" = true,
      "comment" = "Azathoth is mindless and totally resistant to mental attack (folio 18)",
    }, {
      "name" = "mytCthulhuResistantWaterColdVacuum",
      "value" = true,
      "comment" = "Cthulhu is totally resistant to water, cold and vacuum (folio 18)",
    }, {
      "name" = "mytCthulhuRetreatsAtElderSign",
      "value" = true,
      "comment" = "Cthulhu retreats when confronted with the intact Elder Sign, another Old One or natural catastrophe (folio 18)",
    }, {
      "name" = "mytHasturImmuneColdVacuum",
      "value" = true,
      "comment" = "Hastur is immune to cold and vacuum (folio 18)",
    }, {
      "name" = "mytHasturFearSaveRequired",
      "value" = true,
      "comment" = "anyone encountering Hastur must save against fear (folio 18)",
    }, {
      "name" = "mytNyarlathotepCharmOneSaveOnly",
      "value" = true,
      "comment" = "the Nyarlathotep charm save, once made, never needs checking again (folio 18)",
    }, {
      "name" = "mytShubMonstersAttackOnCommand",
      "value" = true,
      "comment" = "Shub-Niggurath's spawned monsters ignore strangers but attack on her command (folio 18)",
    }, {
      "name" = "mytCthugaPlusThreeWeaponsOnly",
      "value" = true,
      "comment" = "only +3 or better weapons damage Cthuga, lesser magical weapons forcing saves against disintegration (folio 20)",
    }, {
      "name" = "mytCthugaMetalMelts",
      "value" = true,
      "comment" = "metal non-magical weapons melt upon touching Cthuga (folio 20)",
    }, {
      "name" = "mytIthaquaWindWalkAtWill",
      "value" = true,
      "comment" = "Ithaqua may wind walk as the spell anytime he wishes (folio 20)",
    }, {
      "name" = "mytIthaquaAirElementalRoamsFree",
      "value" = true,
      "comment" = "the Ithaqua air elemental goes beyond controlling range with no concentration required (folio 20)",
    }, {
      "name" = "mytYigRangerSenses",
      "value" = true,
      "comment" = "Yig moves silently, detects enemies and tracks as a ranger, all at 100 percent efficiency (folio 20)",
    }, {
      "name" = "mytYigPoisonSaveFailsDies",
      "value" = true,
      "comment" = "all those failing the Yig poison save die immediately (folio 20)",
    }, {
      "name" = "mytYogNotSubjectToSpaceTime",
      "value" = true,
      "comment" = "Yog Sothoth is not subject to the laws of space and time, appearing at various parts of the universe simultaneously (folio 20)",
    }, {
      "name" = "mytByakheeProtectedColdVacuum",
      "value" = true,
      "comment" = "the Byakhee and those they carry are protected from cold and vacuum (folio 21)",
    }, {
      "name" = "mytByakheeElderSignObeys",
      "value" = true,
      "comment" = "the Byakhee obey those who carry the Elder Sign or appeal successfully to Hastur (folio 21)",
    }, {
      "name" = "mytDeepOnesAmphibious",
      "value" = true,
      "comment" = "the Deep Ones are amphibious, growing more icthytic with age (folio 21)",
    }, {
      "name" = "mytGreatRaceMindSwap",
      "value" = true,
      "comment" = "the Great Race projects minds across time and space, seizing control of any intelligent creature's body (folio 21)",
    }, {
      "name" = "mytGreatRaceLawfulNeutral",
      "value" = true,
      "comment" = "unlike the servants of the Old Ones, the Great Race is lawful and neutral (folio 21)",
    }, {
      "name" = "mytMiGoImmuneColdVacuum",
      "value" = true,
      "comment" = "the Mi-Go are immune to cold, dark and vacuum, flying interstellar space (folio 21)",
    }, {
      "name" = "mytElderSignCharmVsMinions",
      "value" = true,
      "comment" = "the Elder Sign acts on the evil minions of the Old Ones as a powerful charm spell, as a crucifix on a vampire (folio 20)",
    }, {
      "name" = "mytElderSignWeakerVsGOO",
      "value" = true,
      "comment" = "the Elder Sign is less strong against the Great Old Ones themselves (folio 20)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "mytPersianStat",
      "tag" = "PS",
      "count" = "mytPersianRows",
      "sentinel" = -1,
      "sentinel_census" = { 2, 1, 1, 2, 0, 1 },
      "audit_comment" = "the Persian Mythos stat grid - the Atar armor-class and psionic cells print bar garbles, the Vayu move prints the 187/36 fraction garble, and the Ahura Mazda and Ahriman unlimited hit-point and spell cells print words: all ride the -1 sentinel as scanned, the hero block riding As a Normal Man, noted never silent (folios 8-10)",
      "cols" = { "mytPersianAc", "mytPersianMove", "mytPersianHp", "mytPersianMagicLvl", "mytPersianFightLvl", "mytPersianPsiClass" },
      "col_comments" = { "the armor class - Ahura Mazda and Ahriman minus 2, the archangels, yazatas, archdemons and demons 2, Haoma 3; the Atar cell prints a bar garble and the hero block prints As a Normal Man, both riding the sentinel (folios 8-10)", "the move in inches - the supreme pair 20, the archangels and archdemons 18, the yazatas 15 or 18, the heroes 12; the Vayu cell garbles as 187/36 for the 18/36 dual rate and rides the sentinel (folios 8-10)", "the hit points - Ahriman 300, the archangels and archdemons 250, the demons 200, Tishtrya and Rapithwin 225, Anahita and Haoma 175, the heroes 100; the Ahura Mazda cell prints Unlimited and rides the sentinel (folios 8-10)", "the magic-user level - the archangels and archdemons Wizard 20th, the yazatas Wizard 14th except Haoma 12th, the heroes Nil as zero; the supreme pair print Unlimited Spells and ride the sentinel (folios 8-10)", "the fighter level - the supreme pair Lord 40th, the archangels, archdemons and Vayu 15th, the demons and most yazatas 14th, Anahita 11th, Haoma 10th, the heroes Lord 12th; Vayu prints 15th without the Lord prefix, noted as scanned (folios 8-10)", "the psionic class - the supreme pair Class 6, the archangels and archdemons Class 1, the yazatas Class 2 except Haoma Class 3, the heroes Nil as zero; the Atar cell prints a bar garble and rides the sentinel (folios 8-10)" },
      "data" = { { -2, 20, -1, -1, 40, 6 }, { -2, 20, 300, -1, 40, 6 }, { 2, 18, 250, 20, 15, 1 }, { 2, -1, 250, 14, 15, 2 }, { 2, 15, 225, 14, 14, 2 }, { 2, 15, 175, 14, 11, 2 }, { 2, 15, 250, 14, 15, 2 }, { 2, 15, 225, 14, 14, 2 }, { -1, 18, 250, 14, 14, -1 }, { 3, 15, 175, 12, 10, 3 }, { -1, 12, 100, 0, 12, 0 }, { 2, 18, 250, 20, 15, 1 }, { 2, 15, 200, 14, 14, 2 } },
    }, {
      "name" = "mytPersianHeroStat",
      "tag" = "PH",
      "count" = "mytPersianHeroRows",
      "sentinel" = -1,
      "sentinel_census" = { 5, 0, 0, 0, 0, 0 },
      "audit_comment" = "the six Persian hero stat lines - the strength cells print as fraction garbles (185, 189, 1859, 18;;, 18,5), five cells riding the -1 sentinel with the census, Thrita the one clean strength line pinning clean, noted as scanned never silent (folio 10)",
      "cols" = { "mytPersianHeroStr", "mytPersianHeroInt", "mytPersianHeroWis", "mytPersianHeroCon", "mytPersianHeroDex", "mytPersianHeroCha" },
      "col_comments" = { "the strength - Thrita 15 pins clean; Yima prints 185 (18/95), Hoshang 189 (18/90), Takhmoruw 1859 (18/59), Faridun 18;; and Keresaspa 18,5 (18/50), all fraction garbles riding the sentinel as-scanned (folio 10)", "the intelligence - Yima 17, Hoshang 17, Takhmoruw 16, Thrita 17, Faridun 14, Keresaspa 14 (folio 10)", "the wisdom - Yima 9, Hoshang 13, Takhmoruw 12, Thrita 18, Faridun 8, Keresaspa 12 (folio 10)", "the constitution - Yima 17, Hoshang 18, Takhmoruw 16, Thrita 15, Faridun 17, Keresaspa 17 (folio 10)", "the dexterity - Yima 17, Hoshang 17, Takhmoruw 16, Thrita 12, Faridun 17, Keresaspa 17 (folio 10)", "the charisma - Yima 17, Hoshang 16, Takhmoruw 16, Thrita 12, Faridun 15, Keresaspa 17 (folio 10)" },
      "data" = { { -1, 17, 9, 17, 17, 17 }, { -1, 17, 13, 18, 17, 16 }, { -1, 16, 12, 16, 16, 16 }, { 15, 17, 18, 15, 12, 12 }, { -1, 14, 8, 17, 17, 15 }, { -1, 14, 12, 17, 17, 17 } },
    }, {
      "name" = "mytGreatOldOneStat",
      "tag" = "GO",
      "count" = "mytGOORows",
      "sentinel" = -1,
      "sentinel_census" = { 1, 1, 0, 1, 6, 2 },
      "audit_comment" = "the Great Old Ones stat grid - the Yig split armor class pins as the head-3 chest-5 consts with the grid cell riding the -1 sentinel; the Azathoth infinite move, the Shub-Niggurath see-below fighter level, the six see-below magic cells and the Azathoth and Hastur psionic-resistance text cells all ride the sentinel with the census, noted never silent (folios 18-20)",
      "cols" = { "mytGOOAc", "mytGOOMove", "mytGOOHp", "mytGOOFightLvl", "mytGOOMagicLvl", "mytGOOPsiClass" },
      "col_comments" = { "the armor class - Azathoth minus 2, the rest 2 except Shub-Niggurath 4; the Yig cell prints the 3/5 head-and-body split (pinned as consts) and rides the sentinel (folios 18-20)", "the move in inches - Azathoth prints infinite, Cthulhu, Hastur and Nyarlathotep 12, Shub-Niggurath 6, Cthuga 12, Ithaqua 12 plus special, Yig 18, Yog Sothoth 24; the Azathoth cell rides the sentinel (folios 18-20)", "the hit points - Azathoth 300, Cthulhu and Hastur 200, Nyarlathotep 150, Shub-Niggurath and Yog Sothoth 300, Cthuga and Ithaqua 175, Yig 125 (folios 18-20)", "the fighter level - Azathoth and Hastur 20th, Cthulhu and Yig 15th, Nyarlathotep 15th, Cthuga 17th, Ithaqua 16th, Yog Sothoth 20th; the Shub-Niggurath cell prints see below and rides the sentinel (folios 18-20)", "the magic-user level - Nyarlathotep and Yog Sothoth 15th, Azathoth none as zero; the Cthulhu, Hastur, Shub-Niggurath, Cthuga, Ithaqua and Yig cells print see below and ride the sentinel (folios 18-20)", "the psionic class - Cthulhu and Yog Sothoth Class 1, Nyarlathotep and Shub-Niggurath Class 2, Cthuga, Ithaqua and Yig Class 6; the Azathoth and Hastur cells print resistant-to-all-psionic text and ride the sentinel (folios 18-20)" },
      "data" = { { -2, -1, 300, 20, 0, -1 }, { 2, 12, 200, 15, -1, 1 }, { 2, 12, 200, 20, -1, -1 }, { 2, 12, 150, 15, 15, 2 }, { 4, 6, 300, -1, -1, 2 }, { 2, 12, 175, 17, -1, 6 }, { 2, 12, 175, 16, -1, 6 }, { -1, 18, 125, 15, -1, 6 }, { 2, 24, 300, 20, 15, 1 } },
    }, {
      "name" = "mytMythosRaceStat",
      "tag" = "MR",
      "count" = "mytRaceRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0, 0, 0, 2, 1 },
      "audit_comment" = "the inhuman and partly-human races grid - the Byakhee and Mi-Go see-below magic cells and the Shaggoth psionic-resistance cell ride the -1 sentinel with the census, the none cells pinning zero, noted never silent (folio 21)",
      "cols" = { "mytRaceAc", "mytRaceMove", "mytRaceHp", "mytRaceFightLvl", "mytRaceMagicLvl", "mytRacePsiClass" },
      "col_comments" = { "the armor class - the Byakhee and Great Race 5, the Deep Ones and Mi-Go 3, the Old Ones 5, the Shaggoths 4 (folio 21)", "the move in inches - the Byakhee 36, the Deep Ones 12 with the 36 in-water rate, the Great Race and Old Ones 12, the Mi-Go 15 flying 30, the Shaggoths 18 (folio 21)", "the hit points - the Byakhee 100, the Deep Ones 10, the Great Race 30, the Old Ones 50, the Mi-Go 35, the Shaggoths 70 (folio 21)", "the fighter level - the Byakhee 10th, the Deep Ones 3rd, the Great Race 6th, the Old Ones 8th, the Mi-Go 8th, the Shaggoths 8th (folio 21)", "the magic-user level - the Deep Ones, Great Race, Old Ones and Shaggoths print none or no magical powers, pinned as zero; the Byakhee and Mi-Go cells print see below and ride the sentinel (folio 21)", "the psionic class - the Byakhee Class 5, the Great Race Class 1, the Mi-Go Class 5, the Deep Ones and Old Ones none as zero; the Shaggoth cell prints resistant-to-psionic text and rides the sentinel (folio 21)" },
      "data" = { { 5, 36, 100, 10, -1, 5 }, { 3, 12, 10, 3, 0, 0 }, { 5, 12, 30, 6, 0, 1 }, { 5, 12, 50, 8, 0, 0 }, { 3, 15, 35, 8, -1, 5 }, { 4, 18, 70, 8, 0, -1 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['mytPersianAc'](0) != -2 or m['mytPersianMove'](0) != 20 or m['mytPersianFightLvl'](0) != 40 or m['mytPersianPsiClass'](0) != 6",
      "note" = "the Ahura Mazda row - armor class minus 2, move 20, Lord 40th, psionic Class 6, the unlimited hit-point and spell cells riding the sentinel (folio 8)",
    }, {
      "expr" = "m['mytPersianAc'](1) != -2 or m['mytPersianHp'](1) != 300 or m['mytPersianMove'](1) != 20 or m['mytPersianPsiClass'](1) != 6",
      "note" = "the Ahriman row - armor class minus 2, 300 hit points, move 20, Class 6 (folio 10)",
    }, {
      "expr" = "m['mytPersianAc'](2) != 2 or m['mytPersianMove'](2) != 18 or m['mytPersianHp'](2) != 250 or m['mytPersianMagicLvl'](2) != 20 or m['mytPersianFightLvl'](2) != 15 or m['mytPersianPsiClass'](2) != 1",
      "note" = "the archangel common block - armor class 2, move 18, 250 hit points, Wizard 20th, Lord 15th, Class 1 (folios 8-9)",
    }, {
      "expr" = "m['mytPersianAc'](8) != -1 or m['mytPersianPsiClass'](8) != -1 or m['mytPersianHp'](8) != 250 or m['mytPersianMove'](8) != 18",
      "note" = "the Atar row - the armor-class and psionic cells print bar garbles and ride the sentinel, 250 hit points and move 18 pinning clean (folio 9)",
    }, {
      "expr" = "m['mytPersianAc'](9) != 3 or m['mytPersianHp'](9) != 175 or m['mytPersianMagicLvl'](9) != 12 or m['mytPersianFightLvl'](9) != 10 or m['mytPersianPsiClass'](9) != 3",
      "note" = "the Haoma row - armor class 3, 175 hit points, Wizard 12th, Lord 10th, Class 3 (folio 9)",
    }, {
      "expr" = "m['mytPersianMove'](10) != 12 or m['mytPersianHp'](10) != 100 or m['mytPersianMagicLvl'](10) != 0 or m['mytPersianFightLvl'](10) != 12 or m['mytPersianPsiClass'](10) != 0",
      "note" = "the hero common block - move 12, 100 hit points, Lord 12th, the Nil magic and psionic cells pinning zero (folio 10)",
    }, {
      "expr" = "m['mytPersianHeroStr'](3) != 15 or m['mytPersianHeroInt'](3) != 17 or m['mytPersianHeroWis'](3) != 18 or m['mytPersianHeroCon'](3) != 15 or m['mytPersianHeroDex'](3) != 12 or m['mytPersianHeroCha'](3) != 12",
      "note" = "the Thrita line - the one clean hero stat line, 15/17/18/15/12/12 (folio 10)",
    }, {
      "expr" = "m['mytGOOAc'](0) != -2 or m['mytGOOHp'](0) != 300 or m['mytGOOFightLvl'](0) != 20 or m['mytGOOMagicLvl'](0) != 0 or m['mytAzathothSaveVsMagic']() != 5",
      "note" = "the Azathoth row - armor class minus 2, 300 hit points, Fighter 20th, magic none, save 5 versus magic, the infinite move and psionic-resistance cells riding the sentinel (folio 18)",
    }, {
      "expr" = "m['mytGOOAc'](1) != 2 or m['mytGOOMove'](1) != 12 or m['mytGOOHp'](1) != 200 or m['mytGOOFightLvl'](1) != 15 or m['mytGOOPsiClass'](1) != 1 or m['mytCthulhuRegen']() != 10 or m['mytCthulhuInsanityRadiusMiles']() != 100",
      "note" = "the Cthulhu row - armor class 2, move 12, 200 hit points, Fighter 15th, Class 1, regenerating 10 per melee with the 100-mile insanity radius (folio 18)",
    }, {
      "expr" = "m['mytYigHeadAc']() != 3 or m['mytYigBodyAc']() != 5 or m['mytGOOAc'](7) != -1 or m['mytGOOHp'](7) != 125 or m['mytYigFangDamageMin']() != 2 or m['mytYigFangDamageMax']() != 11 or m['mytYigPoisonSavePenalty']() != 3",
      "note" = "the Yig row - the split armor class pinning as the head-3 chest-5 consts with the grid cell riding the sentinel, 125 hit points, the 2-11 fang damage at minus 3 on the poison save (folio 20)",
    }, {
      "expr" = "m['mytCallDestroyedPercent']() != 25 or m['mytCallServantPercent']() != 50 or m['mytCallGodPercent']() != 25 or m['mytRavageMinTurns']() != 1 or m['mytRavageMaxTurns']() != 6",
      "note" = "the calling risks - 25 percent destruction, 50 percent a servant, 25 percent the god, the ravage running 1-6 turns (folio 18)",
    }, {
      "expr" = "m['mytCthugaFireSpellsPerDay']() != 3 or m['mytCthugaFireElementals']() != 8 or m['mytCthugaElementalHD']() != 12 or m['mytCthugaDamageMin']() != 3 or m['mytCthugaDamageMax']() != 30 or m['mytCthugaWeaponPlusNeeded']() != 3 or m['mytCthugaPlusThreeWeaponsOnly']() != 1",
      "note" = "the Cthuga block - fire spells three times a day, the eight 12-hit-die fire elementals once per week, the 3-30 strike, +3-or-better weapons only (folio 20)",
    }, {
      "expr" = "m['mytIthaquaAirElementalHD']() != 16 or m['mytIthaquaDamageMin']() != 2 or m['mytIthaquaDamageMax']() != 16 or m['mytIthaquaFireExtraPerDie']() != 2 or m['mytIthaquaWindWalkAtWill']() != 1",
      "note" = "the Ithaqua block - the 16-die air elemental per day, two 2-16 buffet strikes, plus 2 per die of magical fire, wind walking at will (folio 20)",
    } },
  "audit" = {
      "label" = "R920 issue-12 opener part two audit",
      "comment" = "THE DRAGON ISSUE-12 OPENER ROUND, PART TWO - the mythos pair, both GD&H-compatible D&D-statted chains. The Persian Mythos by Jerome Arkenberg (folios 8-11): the dualist split of the gods, the Ahura Mazda and Ahriman supreme pair, the seven archangels on their common stat block, the seven yazatas with Vayu, Tishtrya, Ardvi Sura Anahita, Verethragna, Rapithwin, Atar and Haoma, the six heroes on the common Lord-12th block with their stat lines, and the archdemons and demons - the Atar armor-class and psionic cells print bar garbles and the hero strength cells print as fraction garbles (185, 189, 1859, 18;;, 18,5), all riding the sentinel as-scanned, never silent. The Lovecraftian Mythos by Rob Kuntz with J. Eric Holmes, the Sorcerer's Scroll (folios 18-21): the calling risks, the five Great Old Ones plus Cthuga, Ithaqua, Yig and Yog Sothoth on the stat grid, the six partly-human races, the Necronomicon madness roll and the Elder Sign - the Yig split armor class (3 head, 5 chest) pins as consts with the grid cell riding the sentinel, and the see-below magic cells and resistant-to-psionics cells ride the sentinel with the census. THE FLIP: the part-one box in tools/reports/dragon_gap_report_012.md went [x] - 1 closed, 1 open, the closing round to follow.",
    },
}
