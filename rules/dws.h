// =========================================================================================
// Adnd1 - rules/dws.h
// The Dragon issue-19 opener part one - the wish-spell doctrine, the mythos
// of Australia and the systematic magic fields: the three-chain round
// census 859 -> 860.
//
// Pinned from The Dragon Vol. III No. 5 (October 1978), the Curtiss-provided
// scan voice (single voice: the issue-19 source is the uploaded Dm19.pdf with
// its mistral-ocr transcript; no archive.org djvu cross-check exists for
// issue 19). PRINT FOLIO = PDF PAGE MINUS TWO, verified at the page feet in
// the R937 intake (folios 12, 18, 21, 24, 26 and 31 print at the PDF pages
// 14, 20, 23, 26, 28 and 33); this round pins print 12-13 (PDF 14-15), print
// 14-15 + 26 (PDF 16-17 + 28) and print 18-19 (PDF 20-21).
//
// Print quirks pinned AS SCANNED, noted never silent: the Ngunung-Ngunnut
// spell list prints Gate twice (Fly, Gate, Polymorph any object, Gate) - the
// count 4 pins the four printed lines with the doubling noted; the Wawalag
// fighter line reads Champion 7th Level, the only non-Lord block, and the
// psionic reads Nil, pinned 0; the Mimi armor class 8 is the lone positive AC
// in the pantheon; Wagtjadbulla and Tcabuinji share one statline; the
// Walangda statline spells the name while the prose reads Walangada; the
// doctrine field list prints Animation while the section header prints
// Animate (25) - pinned together; the Mental section prints its 27 count but
// no prime requisite line; the fields Summoning, Senses, Illusion and Holy
// print no spell count at all - the -99 sentinel pins every one of these, the
// count is the count of ink.
//
namespace rules {

// ---- the wish doctrine (print 12-13, PDF 14-15) ----

// the wish-spell class count - Classes I through IV, the easiest wishes in
// Class I the Thompson wish doctrine (print 12, PDF 14)
inline int dwsWishClasses()
    { return 4; }

// the Class II magic-user spell ceiling - any MU spell up to and including
// level 5 the Thompson wish doctrine (print 12, PDF 14)
inline int dwsClassTwoMuLevel()
    { return 5; }

// the Class III cleric spell ceiling - any cleric spell up to and including
// level 4 (print 13, PDF 15)
inline int dwsClassThreeClericLevel()
    { return 4; }

// the lawful WS full-grant virtue count - leadership, justice, loyalty,
// heroism, generosity, creativity (print 13, PDF 15)
inline int dwsLawfulVirtues()
    { return 6; }

// the chaotic WS full-grant vice count - tyranny, deceit, greed, laziness,
// mercilessness, cleverness (print 13, PDF 15)
inline int dwsChaoticVices()
    { return 6; }

// the artifact side-effect shrink - the possessor shrinks an inch with every
// use (print 12, PDF 14)
inline int dwsArtifactShrinkPerUse()
    { return 1; }

// the lenient-DM example - the keep-things-moving answer to a balrog wish is
// TEN ANGRY balrogs (print 12, PDF 14)
inline int dwsLenientBalrogs()
    { return 10; }

// the fiction example ring - the Elven-inscribed ring holds three wishes
// (print 12, PDF 14)
inline int dwsRingWishes()
    { return 3; }

// Class I grants wishes for purely physical objects - a sword, a tank, any
// non-magical object the Thompson wish doctrine (print 12, PDF 14)
inline bool dwsClassOnePhysicalObjects()
    { return true; }

// Class I also grants occurrences - a roof caving in, a wind, even a
// time-stop, time being purely physical the Thompson wish doctrine (print 12,
// PDF 14)
inline bool dwsClassOneOccurrences()
    { return true; }

// Class II creates living non-magical beings (print 13, PDF 15)
inline bool dwsClassTwoLivingBeings()
    { return true; }

// Class II creates relatively weak magical equipment (print 13, PDF 15)
inline bool dwsClassTwoWeakEquipment()
    { return true; }

// Class II equipment never concerns more wishes (print 13, PDF 15)
inline bool dwsClassTwoNoWishEquipment()
    { return true; }

// Class III creates living magic-oriented beings (print 13, PDF 15)
inline bool dwsClassThreeMagicBeings()
    { return true; }

// Class III enslaves only the weakest of the magic-oriented beings it creates
// (print 13, PDF 15)
inline bool dwsClassThreeWeakestOnlySlaves()
    { return true; }

// Class III creates moderately strong magical equipment (print 13, PDF 15)
inline bool dwsClassThreeModerateEquipment()
    { return true; }

// Class III accomplishes ANY magic-user spell (print 13, PDF 15)
inline bool dwsClassThreeAnyMuSpell()
    { return true; }

// Class IV is rarely found outside an artifact (print 13, PDF 15)
inline bool dwsClassFourRareOutsideArtifact()
    { return true; }

// Class IV never grants more wishes in any way, shape or form (print 13, PDF
// 15)
inline bool dwsClassFourNoMoreWishes()
    { return true; }

// Class IV never accomplishes the actual creation of another artifact (print
// 13, PDF 15)
inline bool dwsClassFourNoArtifactCreation()
    { return true; }

// even a Class I WS could LEAD the wisher to an already existing artifact
// (print 13, PDF 15)
inline bool dwsClassOneCanLeadToArtifact()
    { return true; }

// never tell players outright what class or sub-class the WS is - let them
// find out (print 13, PDF 15)
inline bool dwsNeverTellPlayersClass()
    { return true; }

// a lawful wizard empowers objects with a lawful or neutral WS (print 13, PDF
// 15)
inline bool dwsLawfulGrantsLawfulOrNeutral()
    { return true; }

// a chaotic wizard empowers objects with a neutral or chaotic WS (print 13,
// PDF 15)
inline bool dwsChaoticGrantsNeutralOrChaotic()
    { return true; }

// a neutral wizard empowers objects with a neutral WS only (print 13, PDF 15)
inline bool dwsNeutralGrantsNeutralOnly()
    { return true; }

// the odds stack toward the neutral WS - more versatility than lawful or
// chaotic (print 13, PDF 15)
inline bool dwsNeutralFavoredVersatile()
    { return true; }

// the neutral WS carries no morals - wishes are rarely twisted to harm the
// wisher (print 13, PDF 15)
inline bool dwsNeutralRarelyTwisted()
    { return true; }

// a WS that only and always twists wishes may be included (print 13, PDF 15)
inline bool dwsTwistedOnlyTypePossible()
    { return true; }

// a WS that creates a can of fruit cocktail no matter the wish may be
// included (print 13, PDF 15)
inline bool dwsFruitCocktailTypePossible()
    { return true; }

// the WS cannot possibly be more powerful than the wizard who created it
// (print 12, PDF 14)
inline bool dwsNeverStrongerThanCreator()
    { return true; }

// some power is lost in the transference to the object - less than the
// creator the Thompson wish doctrine (print 12, PDF 14)
inline bool dwsPowerLostInTransfer()
    { return true; }

// a weak wish spell rides a flimsy object - a ring or a piece of apparel
// (print 12, PDF 14)
inline bool dwsWeakWsInFlimsyObjects()
    { return true; }

// the stronger the object - sword, armour, stone orb, staff, drum - the
// stronger the WS (print 12, PDF 14)
inline bool dwsStrongWsInDurableObjects()
    { return true; }

// the strongest WS ride immobile and virtually indestructible objects (print
// 12, PDF 14)
inline bool dwsStrongestWsImmobile()
    { return true; }

// ancient artifacts are more powerful than their modern counterparts (print
// 12, PDF 14)
inline bool dwsArtifactsMorePowerful()
    { return true; }

// artifact problems ride along - alignment change, the shrinking, even dying
// (print 12-13, PDF 14-15)
inline bool dwsArtifactSideEffects()
    { return true; }

// a too long-winded wish is easier to twist or misinterpret (print 13, PDF
// 15)
inline bool dwsLongWishEasierToTwist()
    { return true; }

// a too short wish may not carry enough information (print 13, PDF 15)
inline bool dwsShortWishTooLittleInfo()
    { return true; }

// a relatively simple wish in D&D terms should have few problems (print 13,
// PDF 15)
inline bool dwsSimpleWordingFewProblems()
    { return true; }

// WS have some understanding power, although not too much (print 13, PDF 15)
inline bool dwsWsSomeUnderstandingPower()
    { return true; }

// the Mirror of Life Trapping on a Class I - a little mirror on a sealed
// occupied fishbowl (print 13, PDF 15)
inline bool dwsFishbowlMirrorAdjudication()
    { return true; }

// the balrog slave on a Class II - send him to the Abyss, let him get his own
// (print 13, PDF 15)
inline bool dwsAbyssAdjudication()
    { return true; }

// a dropped wish is still used up - the wish counts regardless (print 13, PDF
// 15)
inline bool dwsDropWishStillUsedUp()
    { return true; }

// the DM decides the motive behind the wish without consulting players (print
// 13, PDF 15)
inline bool dwsDmDecidesMotiveSilently()
    { return true; }

// the DM should break the classes into sub-classes for the campaign (print
// 13, PDF 15)
inline bool dwsSubclassesEncouraged()
    { return true; }

// ---- the mythos of Australia (print 14-15 + 26, PDF 16-17 + 28) ----

// the mythos entity count - twenty beings across the sky-beings, the Wondjina
// and the rest the Arkenberg mythos of Australia (print 14, PDF 16)
inline int dwsMythosEntities()
    { return 20; }

// the statline count - eighteen of the twenty carry the GDH-format block,
// Morkul-Kua-Luan and the Wondjina prose-only the Arkenberg mythos of
// Australia (print 15 + 26, PDF 17 + 28)
inline int dwsMythosStatlines()
    { return 18; }

// the prose-only count - the Long Grass spirit and the Wondjina band print no
// statline the Arkenberg mythos of Australia (print 15 + 26, PDF 17 + 28)
inline int dwsMythosProseOnly()
    { return 2; }

// the flying-move count - Ngunung-Ngunnut, Yalungur, Mamarangan, Wodoi and
// Djunggun print the dual ground and flying move (print 14 + 15, PDF 16 + 17)
inline int dwsMythosFlyingEntities()
    { return 5; }

// the Wondjina height floor - ten feet (print 15, PDF 17)
inline int dwsWondjinaMinFeet()
    { return 10; }

// the Wondjina height ceiling - sixteen feet (print 15, PDF 17)
inline int dwsWondjinaMaxFeet()
    { return 16; }

// the Tcabuinji height - nine feet (print 26, PDF 28)
inline int dwsTcabFeet()
    { return 9; }

// the Wagtjadbulla height - twelve feet, the ceremonial headdress (print 26,
// PDF 28)
inline int dwsWagtjadbullaFeet()
    { return 12; }

// the Tcabuinji boomerang damage floor - 5 (print 26, PDF 28)
inline int dwsTcabBoomMin()
    { return 5; }

// the Tcabuinji boomerang damage ceiling - 30 points (print 26, PDF 28)
inline int dwsTcabBoomMax()
    { return 30; }

// the Tcabuinji boomerang hit bonus - plus 2 (print 26, PDF 28)
inline int dwsTcabBoomPlus()
    { return 2; }

// the Djunggun boomerang damage floor - 10 (print 15, PDF 17)
inline int dwsDjunggunBoomMin()
    { return 10; }

// the Djunggun boomerang damage ceiling - 60 points (print 15, PDF 17)
inline int dwsDjunggunBoomMax()
    { return 60; }

// the Djunggun boomerang hit bonus - plus 3 (print 15, PDF 17)
inline int dwsDjunggunBoomPlus()
    { return 3; }

// the Mamarangan stone axe damage floor - 10 (print 15, PDF 17)
inline int dwsMamaranganAxeMin()
    { return 10; }

// the Mamarangan stone axe damage ceiling - 60 points (print 15, PDF 17)
inline int dwsMamaranganAxeMax()
    { return 60; }

// the Mamarangan stone axe hit bonus - plus 3 (print 15, PDF 17)
inline int dwsMamaranganAxePlus()
    { return 3; }

// the Gidja spell list count - Gate, Light, Clone, Polymorph any Object,
// Strength, Shield, Magic Missile, Time Stop (print 14, PDF 16)
inline int dwsGidjaSpells()
    { return 8; }

// the Kallin-Kallin spell list count - Gate, Fly, Strength, Shield, Magic
// Missile, Time Stop (print 14, PDF 16)
inline int dwsKallinSpells()
    { return 6; }

// the Waramurungundju spell list count - seven from Growth/Plant through
// Teleport (print 26, PDF 28)
inline int dwsWaramurungundjuSpells()
    { return 7; }

// the Mamarangan spell list count - Control Weather, Lower Water, Part Water,
// Lightning Bolt, Teleport (print 15, PDF 17)
inline int dwsMamaranganSpells()
    { return 5; }

// the Morkul-Kua-Luan spell list count - Create Food, Growth/Plant, Speak
// with Plants, Charm Plants, Gate (print 14, PDF 16)
inline int dwsMorkulSpells()
    { return 5; }

// the Mamandabari spell list count - Gate, Fly, Polymorph any Object, Mass
// Charm, Cure Disease (print 15, PDF 17)
inline int dwsMamandabariSpells()
    { return 5; }

// the Wawalag sisters spell list count - Growth/Plants, Growth/Animals, Read
// Languages (print 26, PDF 28)
inline int dwsWawalagSpells()
    { return 3; }

// the Ngunung-Ngunnut spell list count - Fly, Gate, Polymorph any object,
// Gate - the Gate DOUBLED as printed, pinned as scanned (print 14, PDF 16)
inline int dwsNgunungSpells()
    { return 4; }

// the Yalungur spell list count - Fly and Gate (print 14, PDF 16)
inline int dwsYalungurSpells()
    { return 2; }

// the See Below sentinel - the statline prints See Below for the spell-list
// gods, pinned as the -99 magic-level cell (print 14-15 + 26, PDF 16-17 + 28)
inline int dwsSeeBelowSentinel()
    { return -99; }

// the Ngunung-Ngunnut print catch - the spell list prints Gate twice, Fly,
// Gate, Polymorph any object, Gate, pinned as scanned (print 14, PDF 16)
inline bool dwsNgunungGateTwice()
    { return true; }

// Wodoi is a Wondjina and also a masterful Thief (print 15, PDF 17)
inline bool dwsWodoiMasterThief()
    { return true; }

// the Mamarangan stone axe acts as a Lightning Bolt wand - thunder voice,
// tree and people strikes (print 15, PDF 17)
inline bool dwsMamaranganAxeLightningWand()
    { return true; }

// the Mimi are so thin they fear the wind will snap their necks (print 26,
// PDF 28)
inline bool dwsMimiAfraidOfWind()
    { return true; }

// the Mimi are said to eat men (print 26, PDF 28)
inline bool dwsMimiEatMen()
    { return true; }

// the Mimi main food is yams (print 26, PDF 28)
inline bool dwsMimiFoodYams()
    { return true; }

// the Wawalag sisters were eventually swallowed by Yurlunggur (print 26, PDF
// 28)
inline bool dwsWawalagSwallowedByYurlunggur()
    { return true; }

// Yurlunggur the Rainbow Snake is a great Healer and Sorcerer, regenerating
// nature and fertility (print 15, PDF 17)
inline bool dwsYurlunggurGreatHealer()
    { return true; }

// Yurlunggur wrath - disease and flood when the sex-relationship rules are
// broken (print 15, PDF 17)
inline bool dwsYurlunggurWrathFloodDisease()
    { return true; }

// Kallin-Kallin banished Gidja to the Night-Sky and took Yalungur to wife
// (print 14, PDF 16)
inline bool dwsGidjaBanishedToNightSky()
    { return true; }

// Yalungur became the wife of Kallin-Kallin (print 14, PDF 16)
inline bool dwsKallinTookYalungurWife()
    { return true; }

// the Muramura chief is Darand the Rainmaker - his song brings rain, his
// boomerang in the ground ends it (print 15, PDF 17)
inline bool dwsMuramuraDarandRainmaker()
    { return true; }

// Morkul-Kua-Luan the Spirit of the Long Grass - eyes half-closed against the
// prickling grass, beak-like nose (print 14, PDF 16)
inline bool dwsMorkulLongGrassSpirit()
    { return true; }

// Walangda the Wondjina went up to the Sky to become the Milky Way - the
// statline prints Walangda, the prose Walangada, pinned as scanned (print 15,
// PDF 17)
inline bool dwsWalangdaMilkyWay()
    { return true; }

// the two Djanggawul sisters are eternally with child - two sisters and one
// brother (print 26, PDF 28)
inline bool dwsDjanggawulSistersWithChild()
    { return true; }

// the Wondjina halo - red and yellow around the head, eyes and nose linked,
// no mouth (print 15, PDF 17)
inline bool dwsWondjinaHaloNoMouth()
    { return true; }

// the armor class column - Daramulun -3 through the Mimi 8, the lone positive
// AC pinned as scanned (print 14-15 + 26, PDF 16-17 + 28)
inline int dwsMythAc(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return -1;
        case 9:
            return -2;
        case 10:
            return -1;
        case 11:
            return -1;
        case 12:
            return -1;
        case 13:
            return -1;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 8;
        default:
            return -99;
        }
    }

// the move column - ground moves 13 through 22, the five dual-move fliers
// pinned at their ground value (print 14-15 + 26, PDF 16-17 + 28)
inline int dwsMythMove(int b)
    {
        switch (b) {
        case 0:
            return 22;
        case 1:
            return 20;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 18;
        case 9:
            return 19;
        case 10:
            return 20;
        case 11:
            return 20;
        case 12:
            return 20;
        case 13:
            return 20;
        case 14:
            return 18;
        case 15:
            return 15;
        case 16:
            return 13;
        case 17:
            return 14;
        default:
            return -99;
        }
    }

// the hit point column - the Mimi 90 floor through the Daramulun 300 ceiling
// (print 14-15 + 26, PDF 16-17 + 28)
inline int dwsMythHp(int b)
    {
        switch (b) {
        case 0:
            return 300;
        case 1:
            return 225;
        case 2:
            return 170;
        case 3:
            return 180;
        case 4:
            return 130;
        case 5:
            return 190;
        case 6:
            return 160;
        case 7:
            return 175;
        case 8:
            return 240;
        case 9:
            return 230;
        case 10:
            return 200;
        case 11:
            return 200;
        case 12:
            return 220;
        case 13:
            return 210;
        case 14:
            return 210;
        case 15:
            return 175;
        case 16:
            return 125;
        case 17:
            return 90;
        default:
            return -99;
        }
    }

// the magic level column - the Wizard Nth level pinned as N, the eight See
// Below spell-list gods as the -99 sentinel (print 14-15 + 26, PDF 16-17 +
// 28)
inline int dwsMythMagicLevel(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 20;
        case 2:
            return -99;
        case 3:
            return -99;
        case 4:
            return -99;
        case 5:
            return -99;
        case 6:
            return 15;
        case 7:
            return -99;
        case 8:
            return 25;
        case 9:
            return -99;
        case 10:
            return 20;
        case 11:
            return 20;
        case 12:
            return 24;
        case 13:
            return 19;
        case 14:
            return -99;
        case 15:
            return 18;
        case 16:
            return -99;
        case 17:
            return 10;
        default:
            return -99;
        }
    }

// the fighter level column - Lord Nth level pinned as N, the Wawalag Champion
// 7th as printed (print 14-15 + 26, PDF 16-17 + 28)
inline int dwsMythFighterLevel(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 18;
        case 2:
            return 13;
        case 3:
            return 14;
        case 4:
            return 10;
        case 5:
            return 15;
        case 6:
            return 13;
        case 7:
            return 17;
        case 8:
            return 20;
        case 9:
            return 19;
        case 10:
            return 15;
        case 11:
            return 15;
        case 12:
            return 20;
        case 13:
            return 18;
        case 14:
            return 14;
        case 15:
            return 15;
        case 16:
            return 7;
        case 17:
            return 10;
        default:
            return -99;
        }
    }

// the psionic class column - Class 1 through 6, the Wawalag Nil pinned 0
// (print 14-15 + 26, PDF 16-17 + 28)
inline int dwsMythPsionicClass(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 4;
        case 8:
            return 6;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 6;
        case 15:
            return 5;
        case 16:
            return 0;
        case 17:
            return 4;
        default:
            return -99;
        }
    }

// ---- the systematic magic fields (print 18-19, PDF 20-21) ----

// the field count - Control, Summoning, Mental, Time/Space, Attack, Senses,
// Animation, Illusion, Knowledge, Transmutation, Defence, Nature and Holy the
// Rhodes systematic magic fields (print 18, PDF 20)
inline int dwsMagicFields()
    { return 13; }

// the Control field count - 26 spells, prime requisite Charisma the Rhodes
// systematic magic fields (print 19, PDF 21)
inline int dwsControlSpells()
    { return 26; }

// the Mental field count - 27 spells (print 19, PDF 21)
inline int dwsMentalSpells()
    { return 27; }

// the Time/Space field count - 27 spells, prime requisite Wisdom the Rhodes
// systematic magic fields (print 19, PDF 21)
inline int dwsTimeSpaceSpells()
    { return 27; }

// the Attack field count - 20 spells, prime requisite Strength the Rhodes
// systematic magic fields (print 19, PDF 21)
inline int dwsAttackSpells()
    { return 20; }

// the Animate field count - 25 spells, prime requisite Dexterity - the
// doctrine list prints Animation, the section header Animate, pinned together
// as scanned (print 18-19, PDF 20-21)
inline int dwsAnimateSpells()
    { return 25; }

// the Knowledge field count - 23 spells (print 19, PDF 21)
inline int dwsKnowledgeSpells()
    { return 23; }

// the Transmutation field count - 18 spells, prime requisite Intelligence
// (print 19, PDF 21)
inline int dwsTransmutationSpells()
    { return 18; }

// the Defence field count - 18 spells (print 19, PDF 21)
inline int dwsDefenceSpells()
    { return 18; }

// the Nature field count - 31 spells, the largest field (print 19, PDF 21)
inline int dwsNatureSpells()
    { return 31; }

// the unprinted field counts - Summoning, Senses, Illusion and Holy print no
// spell count, the -99 sentinel (print 18-19, PDF 20-21)
inline int dwsUnprintedFieldCounts()
    { return 4; }

// the unprinted prime requisites - eight of the thirteen fields print no
// requisite line: Summoning, Mental, Senses, Illusion, Knowledge, Defence,
// Nature and Holy (print 18-19, PDF 20-21)
inline int dwsUnprintedRequisites()
    { return 8; }

// the prime requisite code 1 - Charisma, printed for Control the Rhodes
// systematic magic fields (print 19, PDF 21)
inline int dwsReqCharisma()
    { return 1; }

// the prime requisite code 2 - Wisdom, printed for Time/Space the Rhodes
// systematic magic fields (print 19, PDF 21)
inline int dwsReqWisdom()
    { return 2; }

// the prime requisite code 3 - Strength, printed for Attack the Rhodes
// systematic magic fields (print 19, PDF 21)
inline int dwsReqStrength()
    { return 3; }

// the prime requisite code 4 - Dexterity, printed for Animate the Rhodes
// systematic magic fields (print 19, PDF 21)
inline int dwsReqDexterity()
    { return 4; }

// the prime requisite code 5 - Intelligence, printed for Transmutation (print
// 19, PDF 21)
inline int dwsReqIntelligence()
    { return 5; }

// the first-level Defence spells with no second-level counterpart -
// Protection/Evil and Shield (print 18, PDF 20)
inline int dwsFirstLevelDefenceSpells()
    { return 2; }

// the last five second-level spells belong to fields unavailable at first
// level (print 18, PDF 20)
inline int dwsSecondLevelTailNewFields()
    { return 5; }

// the Mental print catch - the 27 count prints but no prime requisite line
// rides the Mental section, pinned as scanned (print 18-19, PDF 20-21)
inline bool dwsMentalRequisiteUnprinted()
    { return true; }

// spells belonging to more than one field are cross-referenced, Reverse
// Gravity nature and time/space (print 18, PDF 20)
inline bool dwsCrossReferencedSpells()
    { return true; }

// Reverse Gravity cross-references nature and time/space the Rhodes
// systematic magic fields (print 18, PDF 20)
inline bool dwsReverseGravityNatureTimeSpace()
    { return true; }

// the Light example - senses and summoning together the Rhodes systematic
// magic fields (print 18, PDF 20)
inline bool dwsLightSensesSummoning()
    { return true; }

// the progression doctrine - Rope Trick then Levitation then Fly, a real
// sense of progression (print 18, PDF 20)
inline bool dwsRopeTrickFlyProgression()
    { return true; }

// the two first-level Defence spells have no second-level counterpart (print
// 18, PDF 20)
inline bool dwsFirstLevelDefenceNoCounterpart()
    { return true; }

// the old system cannot base the second-level tail acquisition on related
// spells - the fields are absent at first level (print 18, PDF 20)
inline bool dwsSecondLevelTailFieldsUnavailable()
    { return true; }

// the new fields allow a degree of specialization - the Gandalf and Merlin
// argument the Rhodes systematic magic fields (print 18, PDF 20)
inline bool dwsSpecializationDoctrine()
    { return true; }

// the field spell-count column - Control 26, Mental 27, Time/Space 27, Attack
// 20, Animate 25, Knowledge 23, Transmutation 18, Defence 18, Nature 31, the
// four unprinted counts as -99 (print 18-19, PDF 20-21)
inline int dwsFieldSpells(int b)
    {
        switch (b) {
        case 0:
            return 26;
        case 1:
            return -99;
        case 2:
            return 27;
        case 3:
            return 27;
        case 4:
            return 20;
        case 5:
            return -99;
        case 6:
            return 25;
        case 7:
            return -99;
        case 8:
            return 23;
        case 9:
            return 18;
        case 10:
            return 18;
        case 11:
            return 31;
        case 12:
            return -99;
        default:
            return -99;
        }
    }

// the field requisite column - the printed codes Charisma 1 for Control,
// Wisdom 2 for Time/Space, Strength 3 for Attack, Dexterity 4 for Animate,
// Intelligence 5 for Transmutation, the eight unprinted lines as -99 (print
// 18-19, PDF 20-21)
inline int dwsFieldRequisite(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return -99;
        case 2:
            return -99;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return -99;
        case 6:
            return 4;
        case 7:
            return -99;
        case 8:
            return -99;
        case 9:
            return 5;
        case 10:
            return -99;
        case 11:
            return -99;
        case 12:
            return -99;
        default:
            return -99;
        }
    }

}   // namespace rules
