-- dws: promoted from tools/spec_r937.json (the The Dragon issue-19 opener part one - the wish-spell doctrine, the mythos of Australia and the systematic magic fields: the three-chain round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 937,
  "prefix" = "dws",
  "banner" = {
      "title" = "The Dragon issue-19 opener part one - the wish-spell doctrine, the mythos of Australia and the systematic magic fields: the three-chain round",
      "provenance" = "Pinned from The Dragon Vol. III No. 5 (October 1978), the Curtiss-provided scan voice (single voice: the issue-19 source is the uploaded Dm19.pdf with its mistral-ocr transcript; no archive.org djvu cross-check exists for issue 19). PRINT FOLIO = PDF PAGE MINUS TWO, verified at the page feet in the R937 intake (folios 12, 18, 21, 24, 26 and 31 print at the PDF pages 14, 20, 23, 26, 28 and 33); this round pins print 12-13 (PDF 14-15), print 14-15 + 26 (PDF 16-17 + 28) and print 18-19 (PDF 20-21).",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: the Ngunung-Ngunnut spell list prints Gate twice (Fly, Gate, Polymorph any object, Gate) - the count 4 pins the four printed lines with the doubling noted; the Wawalag fighter line reads Champion 7th Level, the only non-Lord block, and the psionic reads Nil, pinned 0; the Mimi armor class 8 is the lone positive AC in the pantheon; Wagtjadbulla and Tcabuinji share one statline; the Walangda statline spells the name while the prose reads Walangada; the doctrine field list prints Animation while the section header prints Animate (25) - pinned together; the Mental section prints its 27 count but no prime requisite line; the fields Summoning, Senses, Illusion and Holy print no spell count at all - the -99 sentinel pins every one of these, the count is the count of ink.",
    },
  "consts" = { {
      "name" = "dwsWishClasses",
      "value" = 4,
      "comment" = "the wish-spell class count - Classes I through IV, the easiest wishes in Class I the Thompson wish doctrine (print 12, PDF 14)",
    }, {
      "name" = "dwsClassTwoMuLevel",
      "value" = 5,
      "comment" = "the Class II magic-user spell ceiling - any MU spell up to and including level 5 the Thompson wish doctrine (print 12, PDF 14)",
    }, {
      "name" = "dwsClassThreeClericLevel",
      "value" = 4,
      "comment" = "the Class III cleric spell ceiling - any cleric spell up to and including level 4 (print 13, PDF 15)",
    }, {
      "name" = "dwsLawfulVirtues",
      "value" = 6,
      "comment" = "the lawful WS full-grant virtue count - leadership, justice, loyalty, heroism, generosity, creativity (print 13, PDF 15)",
    }, {
      "name" = "dwsChaoticVices",
      "value" = 6,
      "comment" = "the chaotic WS full-grant vice count - tyranny, deceit, greed, laziness, mercilessness, cleverness (print 13, PDF 15)",
    }, {
      "name" = "dwsArtifactShrinkPerUse",
      "value" = 1,
      "comment" = "the artifact side-effect shrink - the possessor shrinks an inch with every use (print 12, PDF 14)",
    }, {
      "name" = "dwsLenientBalrogs",
      "value" = 10,
      "comment" = "the lenient-DM example - the keep-things-moving answer to a balrog wish is TEN ANGRY balrogs (print 12, PDF 14)",
    }, {
      "name" = "dwsRingWishes",
      "value" = 3,
      "comment" = "the fiction example ring - the Elven-inscribed ring holds three wishes (print 12, PDF 14)",
    }, {
      "name" = "dwsMythosEntities",
      "value" = 20,
      "comment" = "the mythos entity count - twenty beings across the sky-beings, the Wondjina and the rest the Arkenberg mythos of Australia (print 14, PDF 16)",
    }, {
      "name" = "dwsMythosStatlines",
      "value" = 18,
      "comment" = "the statline count - eighteen of the twenty carry the GDH-format block, Morkul-Kua-Luan and the Wondjina prose-only the Arkenberg mythos of Australia (print 15 + 26, PDF 17 + 28)",
    }, {
      "name" = "dwsMythosProseOnly",
      "value" = 2,
      "comment" = "the prose-only count - the Long Grass spirit and the Wondjina band print no statline the Arkenberg mythos of Australia (print 15 + 26, PDF 17 + 28)",
    }, {
      "name" = "dwsMythosFlyingEntities",
      "value" = 5,
      "comment" = "the flying-move count - Ngunung-Ngunnut, Yalungur, Mamarangan, Wodoi and Djunggun print the dual ground and flying move (print 14 + 15, PDF 16 + 17)",
    }, {
      "name" = "dwsWondjinaMinFeet",
      "value" = 10,
      "comment" = "the Wondjina height floor - ten feet (print 15, PDF 17)",
    }, {
      "name" = "dwsWondjinaMaxFeet",
      "value" = 16,
      "comment" = "the Wondjina height ceiling - sixteen feet (print 15, PDF 17)",
    }, {
      "name" = "dwsTcabFeet",
      "value" = 9,
      "comment" = "the Tcabuinji height - nine feet (print 26, PDF 28)",
    }, {
      "name" = "dwsWagtjadbullaFeet",
      "value" = 12,
      "comment" = "the Wagtjadbulla height - twelve feet, the ceremonial headdress (print 26, PDF 28)",
    }, {
      "name" = "dwsTcabBoomMin",
      "value" = 5,
      "comment" = "the Tcabuinji boomerang damage floor - 5 (print 26, PDF 28)",
    }, {
      "name" = "dwsTcabBoomMax",
      "value" = 30,
      "comment" = "the Tcabuinji boomerang damage ceiling - 30 points (print 26, PDF 28)",
    }, {
      "name" = "dwsTcabBoomPlus",
      "value" = 2,
      "comment" = "the Tcabuinji boomerang hit bonus - plus 2 (print 26, PDF 28)",
    }, {
      "name" = "dwsDjunggunBoomMin",
      "value" = 10,
      "comment" = "the Djunggun boomerang damage floor - 10 (print 15, PDF 17)",
    }, {
      "name" = "dwsDjunggunBoomMax",
      "value" = 60,
      "comment" = "the Djunggun boomerang damage ceiling - 60 points (print 15, PDF 17)",
    }, {
      "name" = "dwsDjunggunBoomPlus",
      "value" = 3,
      "comment" = "the Djunggun boomerang hit bonus - plus 3 (print 15, PDF 17)",
    }, {
      "name" = "dwsMamaranganAxeMin",
      "value" = 10,
      "comment" = "the Mamarangan stone axe damage floor - 10 (print 15, PDF 17)",
    }, {
      "name" = "dwsMamaranganAxeMax",
      "value" = 60,
      "comment" = "the Mamarangan stone axe damage ceiling - 60 points (print 15, PDF 17)",
    }, {
      "name" = "dwsMamaranganAxePlus",
      "value" = 3,
      "comment" = "the Mamarangan stone axe hit bonus - plus 3 (print 15, PDF 17)",
    }, {
      "name" = "dwsGidjaSpells",
      "value" = 8,
      "comment" = "the Gidja spell list count - Gate, Light, Clone, Polymorph any Object, Strength, Shield, Magic Missile, Time Stop (print 14, PDF 16)",
    }, {
      "name" = "dwsKallinSpells",
      "value" = 6,
      "comment" = "the Kallin-Kallin spell list count - Gate, Fly, Strength, Shield, Magic Missile, Time Stop (print 14, PDF 16)",
    }, {
      "name" = "dwsWaramurungundjuSpells",
      "value" = 7,
      "comment" = "the Waramurungundju spell list count - seven from Growth/Plant through Teleport (print 26, PDF 28)",
    }, {
      "name" = "dwsMamaranganSpells",
      "value" = 5,
      "comment" = "the Mamarangan spell list count - Control Weather, Lower Water, Part Water, Lightning Bolt, Teleport (print 15, PDF 17)",
    }, {
      "name" = "dwsMorkulSpells",
      "value" = 5,
      "comment" = "the Morkul-Kua-Luan spell list count - Create Food, Growth/Plant, Speak with Plants, Charm Plants, Gate (print 14, PDF 16)",
    }, {
      "name" = "dwsMamandabariSpells",
      "value" = 5,
      "comment" = "the Mamandabari spell list count - Gate, Fly, Polymorph any Object, Mass Charm, Cure Disease (print 15, PDF 17)",
    }, {
      "name" = "dwsWawalagSpells",
      "value" = 3,
      "comment" = "the Wawalag sisters spell list count - Growth/Plants, Growth/Animals, Read Languages (print 26, PDF 28)",
    }, {
      "name" = "dwsNgunungSpells",
      "value" = 4,
      "comment" = "the Ngunung-Ngunnut spell list count - Fly, Gate, Polymorph any object, Gate - the Gate DOUBLED as printed, pinned as scanned (print 14, PDF 16)",
    }, {
      "name" = "dwsYalungurSpells",
      "value" = 2,
      "comment" = "the Yalungur spell list count - Fly and Gate (print 14, PDF 16)",
    }, {
      "name" = "dwsSeeBelowSentinel",
      "value" = -99,
      "comment" = "the See Below sentinel - the statline prints See Below for the spell-list gods, pinned as the -99 magic-level cell (print 14-15 + 26, PDF 16-17 + 28)",
    }, {
      "name" = "dwsMagicFields",
      "value" = 13,
      "comment" = "the field count - Control, Summoning, Mental, Time/Space, Attack, Senses, Animation, Illusion, Knowledge, Transmutation, Defence, Nature and Holy the Rhodes systematic magic fields (print 18, PDF 20)",
    }, {
      "name" = "dwsControlSpells",
      "value" = 26,
      "comment" = "the Control field count - 26 spells, prime requisite Charisma the Rhodes systematic magic fields (print 19, PDF 21)",
    }, {
      "name" = "dwsMentalSpells",
      "value" = 27,
      "comment" = "the Mental field count - 27 spells (print 19, PDF 21)",
    }, {
      "name" = "dwsTimeSpaceSpells",
      "value" = 27,
      "comment" = "the Time/Space field count - 27 spells, prime requisite Wisdom the Rhodes systematic magic fields (print 19, PDF 21)",
    }, {
      "name" = "dwsAttackSpells",
      "value" = 20,
      "comment" = "the Attack field count - 20 spells, prime requisite Strength the Rhodes systematic magic fields (print 19, PDF 21)",
    }, {
      "name" = "dwsAnimateSpells",
      "value" = 25,
      "comment" = "the Animate field count - 25 spells, prime requisite Dexterity - the doctrine list prints Animation, the section header Animate, pinned together as scanned (print 18-19, PDF 20-21)",
    }, {
      "name" = "dwsKnowledgeSpells",
      "value" = 23,
      "comment" = "the Knowledge field count - 23 spells (print 19, PDF 21)",
    }, {
      "name" = "dwsTransmutationSpells",
      "value" = 18,
      "comment" = "the Transmutation field count - 18 spells, prime requisite Intelligence (print 19, PDF 21)",
    }, {
      "name" = "dwsDefenceSpells",
      "value" = 18,
      "comment" = "the Defence field count - 18 spells (print 19, PDF 21)",
    }, {
      "name" = "dwsNatureSpells",
      "value" = 31,
      "comment" = "the Nature field count - 31 spells, the largest field (print 19, PDF 21)",
    }, {
      "name" = "dwsUnprintedFieldCounts",
      "value" = 4,
      "comment" = "the unprinted field counts - Summoning, Senses, Illusion and Holy print no spell count, the -99 sentinel (print 18-19, PDF 20-21)",
    }, {
      "name" = "dwsUnprintedRequisites",
      "value" = 8,
      "comment" = "the unprinted prime requisites - eight of the thirteen fields print no requisite line: Summoning, Mental, Senses, Illusion, Knowledge, Defence, Nature and Holy (print 18-19, PDF 20-21)",
    }, {
      "name" = "dwsReqCharisma",
      "value" = 1,
      "comment" = "the prime requisite code 1 - Charisma, printed for Control the Rhodes systematic magic fields (print 19, PDF 21)",
    }, {
      "name" = "dwsReqWisdom",
      "value" = 2,
      "comment" = "the prime requisite code 2 - Wisdom, printed for Time/Space the Rhodes systematic magic fields (print 19, PDF 21)",
    }, {
      "name" = "dwsReqStrength",
      "value" = 3,
      "comment" = "the prime requisite code 3 - Strength, printed for Attack the Rhodes systematic magic fields (print 19, PDF 21)",
    }, {
      "name" = "dwsReqDexterity",
      "value" = 4,
      "comment" = "the prime requisite code 4 - Dexterity, printed for Animate the Rhodes systematic magic fields (print 19, PDF 21)",
    }, {
      "name" = "dwsReqIntelligence",
      "value" = 5,
      "comment" = "the prime requisite code 5 - Intelligence, printed for Transmutation (print 19, PDF 21)",
    }, {
      "name" = "dwsFirstLevelDefenceSpells",
      "value" = 2,
      "comment" = "the first-level Defence spells with no second-level counterpart - Protection/Evil and Shield (print 18, PDF 20)",
    }, {
      "name" = "dwsSecondLevelTailNewFields",
      "value" = 5,
      "comment" = "the last five second-level spells belong to fields unavailable at first level (print 18, PDF 20)",
    } },
  "bools" = { {
      "name" = "dwsClassOnePhysicalObjects",
      "value" = true,
      "comment" = "Class I grants wishes for purely physical objects - a sword, a tank, any non-magical object the Thompson wish doctrine (print 12, PDF 14)",
    }, {
      "name" = "dwsClassOneOccurrences",
      "value" = true,
      "comment" = "Class I also grants occurrences - a roof caving in, a wind, even a time-stop, time being purely physical the Thompson wish doctrine (print 12, PDF 14)",
    }, {
      "name" = "dwsClassTwoLivingBeings",
      "value" = true,
      "comment" = "Class II creates living non-magical beings (print 13, PDF 15)",
    }, {
      "name" = "dwsClassTwoWeakEquipment",
      "value" = true,
      "comment" = "Class II creates relatively weak magical equipment (print 13, PDF 15)",
    }, {
      "name" = "dwsClassTwoNoWishEquipment",
      "value" = true,
      "comment" = "Class II equipment never concerns more wishes (print 13, PDF 15)",
    }, {
      "name" = "dwsClassThreeMagicBeings",
      "value" = true,
      "comment" = "Class III creates living magic-oriented beings (print 13, PDF 15)",
    }, {
      "name" = "dwsClassThreeWeakestOnlySlaves",
      "value" = true,
      "comment" = "Class III enslaves only the weakest of the magic-oriented beings it creates (print 13, PDF 15)",
    }, {
      "name" = "dwsClassThreeModerateEquipment",
      "value" = true,
      "comment" = "Class III creates moderately strong magical equipment (print 13, PDF 15)",
    }, {
      "name" = "dwsClassThreeAnyMuSpell",
      "value" = true,
      "comment" = "Class III accomplishes ANY magic-user spell (print 13, PDF 15)",
    }, {
      "name" = "dwsClassFourRareOutsideArtifact",
      "value" = true,
      "comment" = "Class IV is rarely found outside an artifact (print 13, PDF 15)",
    }, {
      "name" = "dwsClassFourNoMoreWishes",
      "value" = true,
      "comment" = "Class IV never grants more wishes in any way, shape or form (print 13, PDF 15)",
    }, {
      "name" = "dwsClassFourNoArtifactCreation",
      "value" = true,
      "comment" = "Class IV never accomplishes the actual creation of another artifact (print 13, PDF 15)",
    }, {
      "name" = "dwsClassOneCanLeadToArtifact",
      "value" = true,
      "comment" = "even a Class I WS could LEAD the wisher to an already existing artifact (print 13, PDF 15)",
    }, {
      "name" = "dwsNeverTellPlayersClass",
      "value" = true,
      "comment" = "never tell players outright what class or sub-class the WS is - let them find out (print 13, PDF 15)",
    }, {
      "name" = "dwsLawfulGrantsLawfulOrNeutral",
      "value" = true,
      "comment" = "a lawful wizard empowers objects with a lawful or neutral WS (print 13, PDF 15)",
    }, {
      "name" = "dwsChaoticGrantsNeutralOrChaotic",
      "value" = true,
      "comment" = "a chaotic wizard empowers objects with a neutral or chaotic WS (print 13, PDF 15)",
    }, {
      "name" = "dwsNeutralGrantsNeutralOnly",
      "value" = true,
      "comment" = "a neutral wizard empowers objects with a neutral WS only (print 13, PDF 15)",
    }, {
      "name" = "dwsNeutralFavoredVersatile",
      "value" = true,
      "comment" = "the odds stack toward the neutral WS - more versatility than lawful or chaotic (print 13, PDF 15)",
    }, {
      "name" = "dwsNeutralRarelyTwisted",
      "value" = true,
      "comment" = "the neutral WS carries no morals - wishes are rarely twisted to harm the wisher (print 13, PDF 15)",
    }, {
      "name" = "dwsTwistedOnlyTypePossible",
      "value" = true,
      "comment" = "a WS that only and always twists wishes may be included (print 13, PDF 15)",
    }, {
      "name" = "dwsFruitCocktailTypePossible",
      "value" = true,
      "comment" = "a WS that creates a can of fruit cocktail no matter the wish may be included (print 13, PDF 15)",
    }, {
      "name" = "dwsNeverStrongerThanCreator",
      "value" = true,
      "comment" = "the WS cannot possibly be more powerful than the wizard who created it (print 12, PDF 14)",
    }, {
      "name" = "dwsPowerLostInTransfer",
      "value" = true,
      "comment" = "some power is lost in the transference to the object - less than the creator the Thompson wish doctrine (print 12, PDF 14)",
    }, {
      "name" = "dwsWeakWsInFlimsyObjects",
      "value" = true,
      "comment" = "a weak wish spell rides a flimsy object - a ring or a piece of apparel (print 12, PDF 14)",
    }, {
      "name" = "dwsStrongWsInDurableObjects",
      "value" = true,
      "comment" = "the stronger the object - sword, armour, stone orb, staff, drum - the stronger the WS (print 12, PDF 14)",
    }, {
      "name" = "dwsStrongestWsImmobile",
      "value" = true,
      "comment" = "the strongest WS ride immobile and virtually indestructible objects (print 12, PDF 14)",
    }, {
      "name" = "dwsArtifactsMorePowerful",
      "value" = true,
      "comment" = "ancient artifacts are more powerful than their modern counterparts (print 12, PDF 14)",
    }, {
      "name" = "dwsArtifactSideEffects",
      "value" = true,
      "comment" = "artifact problems ride along - alignment change, the shrinking, even dying (print 12-13, PDF 14-15)",
    }, {
      "name" = "dwsLongWishEasierToTwist",
      "value" = true,
      "comment" = "a too long-winded wish is easier to twist or misinterpret (print 13, PDF 15)",
    }, {
      "name" = "dwsShortWishTooLittleInfo",
      "value" = true,
      "comment" = "a too short wish may not carry enough information (print 13, PDF 15)",
    }, {
      "name" = "dwsSimpleWordingFewProblems",
      "value" = true,
      "comment" = "a relatively simple wish in D&D terms should have few problems (print 13, PDF 15)",
    }, {
      "name" = "dwsWsSomeUnderstandingPower",
      "value" = true,
      "comment" = "WS have some understanding power, although not too much (print 13, PDF 15)",
    }, {
      "name" = "dwsFishbowlMirrorAdjudication",
      "value" = true,
      "comment" = "the Mirror of Life Trapping on a Class I - a little mirror on a sealed occupied fishbowl (print 13, PDF 15)",
    }, {
      "name" = "dwsAbyssAdjudication",
      "value" = true,
      "comment" = "the balrog slave on a Class II - send him to the Abyss, let him get his own (print 13, PDF 15)",
    }, {
      "name" = "dwsDropWishStillUsedUp",
      "value" = true,
      "comment" = "a dropped wish is still used up - the wish counts regardless (print 13, PDF 15)",
    }, {
      "name" = "dwsDmDecidesMotiveSilently",
      "value" = true,
      "comment" = "the DM decides the motive behind the wish without consulting players (print 13, PDF 15)",
    }, {
      "name" = "dwsSubclassesEncouraged",
      "value" = true,
      "comment" = "the DM should break the classes into sub-classes for the campaign (print 13, PDF 15)",
    }, {
      "name" = "dwsNgunungGateTwice",
      "value" = true,
      "comment" = "the Ngunung-Ngunnut print catch - the spell list prints Gate twice, Fly, Gate, Polymorph any object, Gate, pinned as scanned (print 14, PDF 16)",
    }, {
      "name" = "dwsWodoiMasterThief",
      "value" = true,
      "comment" = "Wodoi is a Wondjina and also a masterful Thief (print 15, PDF 17)",
    }, {
      "name" = "dwsMamaranganAxeLightningWand",
      "value" = true,
      "comment" = "the Mamarangan stone axe acts as a Lightning Bolt wand - thunder voice, tree and people strikes (print 15, PDF 17)",
    }, {
      "name" = "dwsMimiAfraidOfWind",
      "value" = true,
      "comment" = "the Mimi are so thin they fear the wind will snap their necks (print 26, PDF 28)",
    }, {
      "name" = "dwsMimiEatMen",
      "value" = true,
      "comment" = "the Mimi are said to eat men (print 26, PDF 28)",
    }, {
      "name" = "dwsMimiFoodYams",
      "value" = true,
      "comment" = "the Mimi main food is yams (print 26, PDF 28)",
    }, {
      "name" = "dwsWawalagSwallowedByYurlunggur",
      "value" = true,
      "comment" = "the Wawalag sisters were eventually swallowed by Yurlunggur (print 26, PDF 28)",
    }, {
      "name" = "dwsYurlunggurGreatHealer",
      "value" = true,
      "comment" = "Yurlunggur the Rainbow Snake is a great Healer and Sorcerer, regenerating nature and fertility (print 15, PDF 17)",
    }, {
      "name" = "dwsYurlunggurWrathFloodDisease",
      "value" = true,
      "comment" = "Yurlunggur wrath - disease and flood when the sex-relationship rules are broken (print 15, PDF 17)",
    }, {
      "name" = "dwsGidjaBanishedToNightSky",
      "value" = true,
      "comment" = "Kallin-Kallin banished Gidja to the Night-Sky and took Yalungur to wife (print 14, PDF 16)",
    }, {
      "name" = "dwsKallinTookYalungurWife",
      "value" = true,
      "comment" = "Yalungur became the wife of Kallin-Kallin (print 14, PDF 16)",
    }, {
      "name" = "dwsMuramuraDarandRainmaker",
      "value" = true,
      "comment" = "the Muramura chief is Darand the Rainmaker - his song brings rain, his boomerang in the ground ends it (print 15, PDF 17)",
    }, {
      "name" = "dwsMorkulLongGrassSpirit",
      "value" = true,
      "comment" = "Morkul-Kua-Luan the Spirit of the Long Grass - eyes half-closed against the prickling grass, beak-like nose (print 14, PDF 16)",
    }, {
      "name" = "dwsWalangdaMilkyWay",
      "value" = true,
      "comment" = "Walangda the Wondjina went up to the Sky to become the Milky Way - the statline prints Walangda, the prose Walangada, pinned as scanned (print 15, PDF 17)",
    }, {
      "name" = "dwsDjanggawulSistersWithChild",
      "value" = true,
      "comment" = "the two Djanggawul sisters are eternally with child - two sisters and one brother (print 26, PDF 28)",
    }, {
      "name" = "dwsWondjinaHaloNoMouth",
      "value" = true,
      "comment" = "the Wondjina halo - red and yellow around the head, eyes and nose linked, no mouth (print 15, PDF 17)",
    }, {
      "name" = "dwsMentalRequisiteUnprinted",
      "value" = true,
      "comment" = "the Mental print catch - the 27 count prints but no prime requisite line rides the Mental section, pinned as scanned (print 18-19, PDF 20-21)",
    }, {
      "name" = "dwsCrossReferencedSpells",
      "value" = true,
      "comment" = "spells belonging to more than one field are cross-referenced, Reverse Gravity nature and time/space (print 18, PDF 20)",
    }, {
      "name" = "dwsReverseGravityNatureTimeSpace",
      "value" = true,
      "comment" = "Reverse Gravity cross-references nature and time/space the Rhodes systematic magic fields (print 18, PDF 20)",
    }, {
      "name" = "dwsLightSensesSummoning",
      "value" = true,
      "comment" = "the Light example - senses and summoning together the Rhodes systematic magic fields (print 18, PDF 20)",
    }, {
      "name" = "dwsRopeTrickFlyProgression",
      "value" = true,
      "comment" = "the progression doctrine - Rope Trick then Levitation then Fly, a real sense of progression (print 18, PDF 20)",
    }, {
      "name" = "dwsFirstLevelDefenceNoCounterpart",
      "value" = true,
      "comment" = "the two first-level Defence spells have no second-level counterpart (print 18, PDF 20)",
    }, {
      "name" = "dwsSecondLevelTailFieldsUnavailable",
      "value" = true,
      "comment" = "the old system cannot base the second-level tail acquisition on related spells - the fields are absent at first level (print 18, PDF 20)",
    }, {
      "name" = "dwsSpecializationDoctrine",
      "value" = true,
      "comment" = "the new fields allow a degree of specialization - the Gandalf and Merlin argument the Rhodes systematic magic fields (print 18, PDF 20)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "dwsMythos",
      "tag" = "My",
      "count" = "dwsMythosStatlines",
      "sentinel" = -99,
      "audit_comment" = "the mythos statline grid - eighteen entities down, the six statline fields across, armor class, move, hit points, the magic level with the See Below -99 sentinel, the fighter level and the psionic class; the print catches pinned as scanned: the Wawalag fighter line reads Champion 7th not Lord, the Wawalag psionic reads Nil pinned 0, the Mimi armor class 8 is the lone positive AC, and Wagtjadbulla and Tcabuinji share one statline (print 14-15 + 26, PDF 16-17 + 28)",
      "cols" = { "dwsMythAc", "dwsMythMove", "dwsMythHp", "dwsMythMagicLevel", "dwsMythFighterLevel", "dwsMythPsionicClass" },
      "col_comments" = { "the armor class column - Daramulun -3 through the Mimi 8, the lone positive AC pinned as scanned (print 14-15 + 26, PDF 16-17 + 28)", "the move column - ground moves 13 through 22, the five dual-move fliers pinned at their ground value (print 14-15 + 26, PDF 16-17 + 28)", "the hit point column - the Mimi 90 floor through the Daramulun 300 ceiling (print 14-15 + 26, PDF 16-17 + 28)", "the magic level column - the Wizard Nth level pinned as N, the eight See Below spell-list gods as the -99 sentinel (print 14-15 + 26, PDF 16-17 + 28)", "the fighter level column - Lord Nth level pinned as N, the Wawalag Champion 7th as printed (print 14-15 + 26, PDF 16-17 + 28)", "the psionic class column - Class 1 through 6, the Wawalag Nil pinned 0 (print 14-15 + 26, PDF 16-17 + 28)" },
      "data" = { { -3, 22, 300, 35, 30, 6 }, { -1, 20, 225, 20, 18, 3 }, { 0, 18, 170, -99, 13, 5 }, { 0, 18, 180, -99, 14, 5 }, { 0, 18, 130, -99, 10, 5 }, { 0, 18, 190, -99, 15, 4 }, { 0, 17, 160, 15, 13, 5 }, { 0, 18, 175, -99, 17, 4 }, { -1, 18, 240, 25, 20, 6 }, { -2, 19, 230, -99, 19, 4 }, { -1, 20, 200, 20, 15, 4 }, { -1, 20, 200, 20, 15, 3 }, { -1, 20, 220, 24, 20, 1 }, { -1, 20, 210, 19, 18, 3 }, { 0, 18, 210, -99, 14, 6 }, { 1, 15, 175, 18, 15, 5 }, { 2, 13, 125, -99, 7, 0 }, { 8, 14, 90, 10, 10, 4 } },
      "sentinel_census" = { 0, 0, 0, 8, 0, 0 },
    }, {
      "name" = "dwsFields",
      "tag" = "Mf",
      "count" = "dwsMagicFields",
      "sentinel" = -99,
      "audit_comment" = "the magic field grid - thirteen fields down, the printed spell count and the prime requisite code across; the -99 sentinel pins the four unprinted counts - Summoning, Senses, Illusion, Holy - and the eight unprinted requisites, the Animation row carrying the Animate header count pinned together (print 18-19, PDF 20-21)",
      "cols" = { "dwsFieldSpells", "dwsFieldRequisite" },
      "col_comments" = { "the field spell-count column - Control 26, Mental 27, Time/Space 27, Attack 20, Animate 25, Knowledge 23, Transmutation 18, Defence 18, Nature 31, the four unprinted counts as -99 (print 18-19, PDF 20-21)", "the field requisite column - the printed codes Charisma 1 for Control, Wisdom 2 for Time/Space, Strength 3 for Attack, Dexterity 4 for Animate, Intelligence 5 for Transmutation, the eight unprinted lines as -99 (print 18-19, PDF 20-21)" },
      "data" = { { 26, 1 }, { -99, -99 }, { 27, -99 }, { 27, 2 }, { 20, 3 }, { -99, -99 }, { 25, 4 }, { -99, -99 }, { 23, -99 }, { 18, 5 }, { 18, -99 }, { 31, -99 }, { -99, -99 } },
      "sentinel_census" = { 4, 8 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dwsWishClasses']() != 4 or m['dwsClassTwoMuLevel']() != 5 or m['dwsClassThreeClericLevel']() != 4 or m['dwsLawfulVirtues']() != 6 or m['dwsChaoticVices']() != 6 or m['dwsArtifactShrinkPerUse']() != 1 or m['dwsLenientBalrogs']() != 10 or m['dwsRingWishes']() != 3",
      "note" = "the wish census - four classes, the Class II level-5 MU ceiling, the Class III level-4 cleric ceiling, the six lawful virtues and six chaotic vices, the artifact shrink, the ten angry balrogs and the three-wish ring (print 12-13, PDF 14-15)",
    }, {
      "expr" = "m['dwsLawfulGrantsLawfulOrNeutral']() != 1 or m['dwsChaoticGrantsNeutralOrChaotic']() != 1 or m['dwsNeutralGrantsNeutralOnly']() != 1 or m['dwsNeutralFavoredVersatile']() != 1 or m['dwsNeutralRarelyTwisted']() != 1 or m['dwsTwistedOnlyTypePossible']() != 1 or m['dwsFruitCocktailTypePossible']() != 1",
      "note" = "the wish alignment doctrine - the lawful, chaotic and neutral grant matrices, the neutral versatility, the rarely-twisted neutral and the twisted-only and fruit-cocktail oddball types (print 13, PDF 15)",
    }, {
      "expr" = "m['dwsNeverStrongerThanCreator']() != 1 or m['dwsPowerLostInTransfer']() != 1 or m['dwsWeakWsInFlimsyObjects']() != 1 or m['dwsStrongWsInDurableObjects']() != 1 or m['dwsStrongestWsImmobile']() != 1 or m['dwsArtifactsMorePowerful']() != 1 or m['dwsArtifactSideEffects']() != 1",
      "note" = "the object-strength doctrine - never stronger than the creator, power lost in transfer, weak WS in flimsy objects, strong in durable, strongest in the immobile, the artifact exceptions (print 12, PDF 14)",
    }, {
      "expr" = "m['dwsMythosEntities']() != 20 or m['dwsMythosStatlines']() != 18 or m['dwsMythosProseOnly']() != 2 or m['dwsMythosFlyingEntities']() != 5 or m['dwsSeeBelowSentinel']() != -99 or m['dwsWondjinaMinFeet']() != 10 or m['dwsWondjinaMaxFeet']() != 16",
      "note" = "the mythos census - twenty entities, eighteen statlines, two prose-only, five fliers, the See Below sentinel, the Wondjina ten-to-sixteen-foot band (print 14-15 + 26, PDF 16-17 + 28)",
    }, {
      "expr" = "m['dwsTcabFeet']() != 9 or m['dwsWagtjadbullaFeet']() != 12 or m['dwsTcabBoomMin']() != 5 or m['dwsTcabBoomMax']() != 30 or m['dwsTcabBoomPlus']() != 2 or m['dwsDjunggunBoomMin']() != 10 or m['dwsDjunggunBoomMax']() != 60 or m['dwsDjunggunBoomPlus']() != 3 or m['dwsMamaranganAxeMin']() != 10 or m['dwsMamaranganAxeMax']() != 60 or m['dwsMamaranganAxePlus']() != 3 or m['dwsMamaranganAxeLightningWand']() != 1",
      "note" = "the mythos weapons and statures - Tcabuinji nine feet and Wagtjadbulla twelve, the 5-30 plus 2 and 10-60 plus 3 boomerangs, the Mamarangan 10-60 plus 3 lightning-wand axe (print 15 + 26, PDF 17 + 28)",
    }, {
      "expr" = "m['dwsGidjaSpells']() != 8 or m['dwsKallinSpells']() != 6 or m['dwsWaramurungundjuSpells']() != 7 or m['dwsMamaranganSpells']() != 5 or m['dwsMorkulSpells']() != 5 or m['dwsMamandabariSpells']() != 5 or m['dwsWawalagSpells']() != 3 or m['dwsNgunungSpells']() != 4 or m['dwsYalungurSpells']() != 2 or m['dwsNgunungGateTwice']() != 1",
      "note" = "the mythos spell-list census - Gidja 8, Kallin-Kallin 6, Waramurungundju 7, Mamarangan 5, Morkul 5, Mamandabari 5, Wawalag 3, Ngunung 4 with the doubled Gate, Yalungur 2 (print 14-15 + 26, PDF 16-17 + 28)",
    }, {
      "expr" = "m['dwsMagicFields']() != 13 or m['dwsControlSpells']() != 26 or m['dwsMentalSpells']() != 27 or m['dwsTimeSpaceSpells']() != 27 or m['dwsAttackSpells']() != 20 or m['dwsAnimateSpells']() != 25 or m['dwsKnowledgeSpells']() != 23 or m['dwsTransmutationSpells']() != 18 or m['dwsDefenceSpells']() != 18 or m['dwsNatureSpells']() != 31 or m['dwsUnprintedFieldCounts']() != 4 or m['dwsUnprintedRequisites']() != 8",
      "note" = "the field census - thirteen fields, the printed counts 26, 27, 27, 20, 25, 23, 18, 18 and 31, the four unprinted counts and eight unprinted requisites (print 18-19, PDF 20-21)",
    }, {
      "expr" = "m['dwsReqCharisma']() != 1 or m['dwsReqWisdom']() != 2 or m['dwsReqStrength']() != 3 or m['dwsReqDexterity']() != 4 or m['dwsReqIntelligence']() != 5 or m['dwsMentalRequisiteUnprinted']() != 1 or m['dwsReverseGravityNatureTimeSpace']() != 1 or m['dwsLightSensesSummoning']() != 1 or m['dwsRopeTrickFlyProgression']() != 1",
      "note" = "the requisite codes and doctrine - Charisma, Wisdom, Strength, Dexterity and Intelligence for Control, Time/Space, Attack, Animate and Transmutation, the Mental requisite unprinted, the cross-references and the Rope Trick progression (print 18-19, PDF 20-21)",
    }, {
      "expr" = "m['dwsFirstLevelDefenceSpells']() != 2 or m['dwsSecondLevelTailNewFields']() != 5 or m['dwsFirstLevelDefenceNoCounterpart']() != 1 or m['dwsSecondLevelTailFieldsUnavailable']() != 1 or m['dwsSpecializationDoctrine']() != 1 or m['dwsCrossReferencedSpells']() != 1",
      "note" = "the level-shape doctrine - the two counterpartless first-level Defence spells, the five-spell second-level tail in first-level-absent fields, the specialization argument (print 18, PDF 20)",
    } },
  "audit" = {
      "label" = "R937 issue-19 opener part one audit",
      "comment" = "THE DRAGON ISSUE-19 OPENER PART ONE - the three doctrine chains of the issue. CHAIN ONE, The Lowdown on Wishes by Kevin Thompson (print 12-13, PDF 14-15): the wish-spell Class I-IV ladder - Class I the purely physical objects and occurrences including the time-stop, Class II the living non-magical beings and weak equipment with the level-5 magic-user ceiling, Class III the magic-oriented beings and moderate equipment with any MU spell and the level-4 cleric ceiling, Class IV the artifact-rare top with the no-more-wishes and no-artifact-creation walls; the alignment grant matrices - lawful into lawful or neutral, chaotic into neutral or chaotic, neutral into neutral only, the neutral versatility and rarely-twisted doctrine; the object-strength logic - never stronger than the creator, power lost in transfer, weak spells in flimsy objects, the strongest in the immobile, the artifact exceptions with the shrink-an-inch side effect; the wording doctrine and the fishbowl, Abyss and drop-still-used-up adjudications. CHAIN TWO, The Mythos of Australia by Jerome Arkenberg (print 14-15 + 26, PDF 16-17 + 28): the GDH-format pantheon - twenty entities, eighteen statlines in the dwsMythos grid with the armor class, move, hit points, magic level, fighter level and psionic class columns, the eight See Below spell-list gods at the -99 sentinel; Daramulun the All-Father at AC -3 and 300 hit points through the stick-thin Mimi at AC 8; the Wondjina band, the boomerang damage and the lightning-wand axe. CHAIN THREE, Systematic Magic by Robin W. Rhodes (print 18-19, PDF 20-21): the thirteen-field spell redivision - the dwsFields grid with the printed spell counts and the five prime requisite codes, the cross-reference doctrine, the first-level Defence counterpart gap and the five-spell second-level tail.",
    },
}
