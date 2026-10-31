-- k26: promoted from tools/spec_r964.json (the The Dragon issue-26 opener part three - the commentary set);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 964,
  "prefix" = "k26",
  "banner" = {
      "title" = "The Dragon issue-26 opener part three - the commentary set",
      "provenance" = "The part-three round of the issue-26 four-round shape - four of the thirteen Curtiss-called chains pinned as the commentary set: the Blueprint for a Lich recipe (print 36), the Lakofka Bazaar of the Bizarre debut with the jar law, the corpse possession ladder and the nine ingredient potion; the impromptu party system (print 37 + 39), the Gygax convention kit with the 4d4 abilities, the level bands, the per class tables and the robe patches; the Dragon Bestiary barghest (print 44), the Gehenna deodand with the whelp feeding and the fire banishment; and the city thief doctrine (print 46), the Stephens disguise, rooftop and scapegoat method. All pinned from The Dragon Vol. III No. 12 (June 1979) print 36-37 + 39 + 44 + 46 at extract/dragon/026 (landed at R962), the single-voice transcript of the Curtiss-provided scan; the Choate thrice print, the Polymorph Serf potions row, the barghest stat block foot mark and PSONIC prints and the Gygas colophon all pinned as scanned. The watches - the Sullin levels 7-9 and the brawling sequel - ride to TD 27 absent a fifth issue.",
    },
  "consts" = { {
      "name" = "k26LichMinLevel",
      "value" = 14,
      "comment" = "the life minimum - at least 14th level before lichdom, 18th most common the lich blueprint (print 36)",
    }, {
      "name" = "k26LichFloorLevel",
      "value" = 10,
      "comment" = "the undeath floor - no lich below 10th level once created the lich blueprint (print 36)",
    }, {
      "name" = "k26LichJarValue",
      "value" = 2000,
      "comment" = "the jar value - at least 2000 gold pieces, high quality and solid the lich blueprint (print 36)",
    }, {
      "name" = "k26LichEnchantHours",
      "value" = 18,
      "comment" = "the enchant window - the eighteen plus hour Enchant an Item casting the lich blueprint (print 36)",
    }, {
      "name" = "k26LichTrapBase",
      "value" = 50,
      "comment" = "the trap the soul base - fifty percent plus six per level over 11th the lich blueprint (print 36)",
    }, {
      "name" = "k26LichTrapPerLevel",
      "value" = 6,
      "comment" = "the trap the soul climb - six percent per level over 11th, the 00 roll failing always the lich blueprint (print 36)",
    }, {
      "name" = "k26LichSpellsErased",
      "value" = 3,
      "comment" = "the ordeal toll - the top three spell levels erased until the rest ends the lich blueprint (print 36)",
    }, {
      "name" = "k26LichCorpseRangeFeet",
      "value" = 90,
      "comment" = "the corpse range - a recently dead body within ninety feet of the jar the lich blueprint (print 36)",
    }, {
      "name" = "k26LichCorpseMaxDays",
      "value" = 30,
      "comment" = "the corpse age - dead no longer than thirty days the lich blueprint (print 36)",
    }, {
      "name" = "k26LichOwnCorpsePenalty",
      "value" = 10,
      "comment" = "the own corpse penalty - the lich at minus ten to receive himself, once a week the lich blueprint (print 36)",
    }, {
      "name" = "k26LichCorpseMaxHd",
      "value" = 4,
      "comment" = "the possession cap - no more than four hit dice for the corpse the lich blueprint (print 36)",
    }, {
      "name" = "k26LichEvilChoateAdj",
      "value" = 6,
      "comment" = "the evil Choate rung - saving at minus six, the Choate print pinned as scanned thrice the lich blueprint (print 36)",
    }, {
      "name" = "k26LichPotionIngredients",
      "value" = 9,
      "comment" = "the potion recipe - nine ingredients from the arsenic pinches to the moth glands the lich blueprint (print 36)",
    }, {
      "name" = "k26LichFeeblemindKillPct",
      "value" = 10,
      "comment" = "the feeblemind gamble - ten percent that each failed removal kills him the lich blueprint (print 36)",
    }, {
      "name" = "k26LichDexLossPct",
      "value" = 30,
      "comment" = "the paralysis gamble - thirty percent of a permanent 1-6 dexterity loss the lich blueprint (print 36)",
    }, {
      "name" = "k26LichPotionDeathLo",
      "value" = 97,
      "comment" = "the potion death band - 97-00 killing the drinker, the resurrection the only way back the lich blueprint (print 36)",
    }, {
      "name" = "k26PartyAbilityDice",
      "value" = 4,
      "comment" = "the abilities - 4d4 discarding the low die, the scores arranged as desired the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyLowLevelHi",
      "value" = 4,
      "comment" = "the low band ceiling - the 1-2, 1-3 or 2-4 random the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyMidLevelHi",
      "value" = 9,
      "comment" = "the medium band ceiling - the 5-7, 5-8 or 7-9 range the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyHighLevelHi",
      "value" = 12,
      "comment" = "the upper band ceiling - the 8-10, 8-11 or 9-12 range the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartySurplusThreshold",
      "value" = 90,
      "comment" = "the surplus rule - the chance over ninety percent joining the above average odds the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyAboveAvgPct",
      "value" = 1,
      "comment" = "the above average chance - one percent per level for the plus two the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyGonzoLevel",
      "value" = 9,
      "comment" = "the Gonzo example - the ninth level ranger the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyGonzoChainPct",
      "value" = 135,
      "comment" = "the Gonzo chain - a 135 percent sure thing for the magic mail the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyGonzoPlusTwoPct",
      "value" = 54,
      "comment" = "the Gonzo plus two odds - nine plus forty five for fifty four percent, the third roll holding him at plus two the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyMiscItemsHi",
      "value" = 4,
      "comment" = "the miscellaneous award - one to four items above 5th into hazard or above 8th the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyMiscListCount",
      "value" = 16,
      "comment" = "the sixteen item list - the feather falling ring through the wings of flying the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyRobePatchesLo",
      "value" = 7,
      "comment" = "the robe patches - select seven to twelve the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyRobePatchesHi",
      "value" = 12,
      "comment" = "the patch ceiling - twelve at most off the menu the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyRobePatchListCount",
      "value" = 23,
      "comment" = "the patch menu - twenty three patches from the bonfire to the wasp nest the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyPotionTypesCount",
      "value" = 10,
      "comment" = "the potion menu - ten types from climbing to Polymorph Serf, the Serf print pinned as scanned the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26BarghestWhelpDice",
      "value" = 6,
      "comment" = "the whelp dice - six plus six to twelve plus twelve hit dice the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestLitter",
      "value" = 6,
      "comment" = "the litter - six whelps sent to the Prime Material to feed and grow the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestAcLo",
      "value" = 2,
      "comment" = "the armor class band - two at the whelp the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestAcHi",
      "value" = -4,
      "comment" = "the armor class ceiling - minus four at the full growth the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestLevelsPerDie",
      "value" = 8,
      "comment" = "the feeding law - eight energy levels to a hit die, a hit point each the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestMresPerHd",
      "value" = 5,
      "comment" = "the magic resistance - five percent per hit die, ignoring the plusses the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestCanineMove",
      "value" = 30,
      "comment" = "the canine move - the double rate at thirty feet maximum the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestMotionlessUnnoticed",
      "value" = 75,
      "comment" = "the motionless dog - seventy five percent unnoticed the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestSurprisePct",
      "value" = 50,
      "comment" = "the ambush - fifty percent surprise, three in six the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestWhelpXpLo",
      "value" = 1275,
      "comment" = "the whelp value - 1275 plus ten per hit point at level seven the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestAdultXpLo",
      "value" = 7300,
      "comment" = "the adult value - 7300 plus eighteen per hit point at level nine the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestAdultLevel",
      "value" = 9,
      "comment" = "the level ladder - seven through nine across the growth the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestAtWillSpells",
      "value" = 5,
      "comment" = "the at will powers - five operations from the shapechange to the projected image the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestPayment",
      "value" = 20,
      "comment" = "the Bestiary pay - twenty dollars above the usual rate, the Gygas colophon print pinned as scanned the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26ThiefDungeonCeiling",
      "value" = 10,
      "comment" = "the dungeon limit - the ceiling ten feet high, the wall climb pointless the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefVictimTypes",
      "value" = 3,
      "comment" = "the ideal victims - jewelers, coin changers and loan sharks the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefSpiceMerchantLevel",
      "value" = 27,
      "comment" = "the research warning - the rich spice merchant a 27th level magic user in his spare time the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefStashPlaces",
      "value" = 2,
      "comment" = "the stash - loot and disguise in two separate predetermined places the city thief doctrine (print 46)",
    } },
  "bools" = { {
      "name" = "k26LichWoodBanned",
      "value" = true,
      "comment" = "the jar ban - wooden items never acceptable, the prior magics allowed the lich blueprint (print 36)",
    }, {
      "name" = "k26LichJarAllObstacles",
      "value" = true,
      "comment" = "the jar pull - the next death entering the jar past cubes of force, prismatic spheres and lead boxes the lich blueprint (print 36)",
    }, {
      "name" = "k26LichWightishBody",
      "value" = true,
      "comment" = "the wightish body - behaving as a wight with no energy drain, telepathic if the corpse could speak the lich blueprint (print 36)",
    }, {
      "name" = "k26LichRemainsEaten",
      "value" = true,
      "comment" = "the metamorphosis - the wightish body eating the remains, one week to the humanoid regrowth the lich blueprint (print 36)",
    }, {
      "name" = "k26LichOwnBodyDisintegrateOnly",
      "value" = true,
      "comment" = "the body law - destruction only via Disintegrate with a normal save, the pieces radiating an unlimited Locate Object the lich blueprint (print 36)",
    }, {
      "name" = "k26LichNoScrollsTouchItems",
      "value" = true,
      "comment" = "the lich bans - never gaining levels, using scrolls or magic items needing a living touch the lich blueprint (print 36)",
    }, {
      "name" = "k26LichJarReturnCost",
      "value" = true,
      "comment" = "the jar toll - each return costing a level, the tenth level return destroying him the lich blueprint (print 36)",
    }, {
      "name" = "k26LichZeroHpDestroyed",
      "value" = true,
      "comment" = "the final death - zero hit points destroying the lich forever, the teleport the escape the lich blueprint (print 36)",
    }, {
      "name" = "k26LichNoRadiatePrepared",
      "value" = true,
      "comment" = "the secrecy - the prepared figure radiating nothing, Charm never revealing the jar location the lich blueprint (print 36)",
    }, {
      "name" = "k26LichPotionFullMoon",
      "value" = true,
      "comment" = "the brewing - the nine ingredients mixed in order by the light of a full moon the lich blueprint (print 36)",
    }, {
      "name" = "k26PartyAlignmentFilter",
      "value" = true,
      "comment" = "the alignment gate - two or three compatible types to prevent the quarrel breakdown the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyMulticlassRound",
      "value" = true,
      "comment" = "the multi class math - one level per profession, divided by the class count, fractions counting whole the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyEquipmentCheck",
      "value" = true,
      "comment" = "the equipment gate - whatever desired with the sheets checked, the impossible and unlikely refused the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyArmorOneSort",
      "value" = true,
      "comment" = "the armor rule - only one sort gained, the choice made before the odds are rolled the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyPlusThreeCheck",
      "value" = true,
      "comment" = "the plus three check - a straight one percent per level after the plus two the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartySpecialFeatures",
      "value" = true,
      "comment" = "the special features - the Flame Tongue or Giant Slayer instead of the plain plus the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyBoltsDoubling",
      "value" = true,
      "comment" = "the bolt rule - the crossbow of speed with a plus three, otherwise the bolts doubled the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyOwnPotionRule",
      "value" = true,
      "comment" = "the potion license - a 100 percent or better score choosing its own supplies the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyThiefMuScrolls",
      "value" = true,
      "comment" = "the thief scrolls - magic user spells, one scroll type only the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26PartyLowPowerKey",
      "value" = true,
      "comment" = "the low key - the sixteen items chosen to hold the power down, add or delete as desired the impromptu party system (print 37 + 39)",
    }, {
      "name" = "k26BarghestGehennaDeodand",
      "value" = true,
      "comment" = "the origin - the deodands of the Gehenna rifts, each ruling its smoking valley despotically the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestGoblinWorship",
      "value" = true,
      "comment" = "the goblin hosts - recognizing and worshipping them, the sacrifices brought and the powerful enemies slain the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestZeroLevelPrey",
      "value" = true,
      "comment" = "the zero level prey - worth only a half energy level, the exceptional persons preferred the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestAcClimb",
      "value" = true,
      "comment" = "the growth climb - the armor class and intelligence rising a place per die the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestStormGiantPeak",
      "value" = true,
      "comment" = "the strength peak - from 18/00 at the whelp to the storm giant the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestPlusOneRequired",
      "value" = true,
      "comment" = "the steel gate - hit only by plus one or better weapons the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestFireNoDamage",
      "value" = true,
      "comment" = "the fire immunity - no damage ever, but a failed canine save hurling it back to Gehenna the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestWeakReturnDoom",
      "value" = true,
      "comment" = "the return doom - the weak returns slain or enslaved, no return without outside help the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestDogHate",
      "value" = true,
      "comment" = "the tell - other dogs fearing and hating it, attacking at every opportunity, the ninety five percent lookalike the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26BarghestOfficialMonsters",
      "value" = true,
      "comment" = "the official stamp - the column monsters official per the author arrangement, the stat block foot mark and PSONIC prints pinned as scanned the Dragon Bestiary barghest (print 44)",
    }, {
      "name" = "k26ThiefCityDoctrine",
      "value" = true,
      "comment" = "the doctrine - thieves belonging in the city, the most misused class the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefDisguiseRule",
      "value" = true,
      "comment" = "the disguise - the lawful good cleric costume defeating the suspicion the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefRooftopTravel",
      "value" = true,
      "comment" = "the rooftops - rare encounters, no blockage, nothing to fall from above the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefAmbushShadows",
      "value" = true,
      "comment" = "the ambush - hiding in shadows for the rich merchants the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefVictimSelection",
      "value" = true,
      "comment" = "the victim pick - wealthy enough to bother, unimportant enough to stay safe the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefScapegoatPlant",
      "value" = true,
      "comment" = "the scapegoat - smart enough to be believed, dumb enough not to catch, the amateur look avoiding the panic, the group over the one with the orcish sword and foppish hat plants the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefPursuitEscape",
      "value" = true,
      "comment" = "the pursuit breaks - the sewer, the buildings, the crowd the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefAlibiMethod",
      "value" = true,
      "comment" = "the alibi - the tavern or inn after the two stashes the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefPlayerTargets",
      "value" = true,
      "comment" = "the player targets - borrowing the cleric money, the lawful good magic user story holding until the chaotic acts the city thief doctrine (print 46)",
    }, {
      "name" = "k26ThiefRichestFun",
      "value" = true,
      "comment" = "the payoff - never the most powerful, maybe the richest, the suspense the fun the city thief doctrine (print 46)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['k26LichMinLevel']() != 14 or m['k26LichFloorLevel']() != 10 or m['k26LichJarValue']() != 2000 or m['k26LichEnchantHours']() != 18 or m['k26LichTrapBase']() != 50 or m['k26LichTrapPerLevel']() != 6 or m['k26LichWoodBanned']() != 1",
      "note" = "the frame - the 14th level life minimum, the 10th level floor, the 2000 gold piece jar with the eighteen hour enchant and the wood ban, the trap the soul base and climb the lich blueprint (print 36)",
    }, {
      "expr" = "m['k26LichSpellsErased']() != 3 or m['k26LichCorpseRangeFeet']() != 90 or m['k26LichCorpseMaxDays']() != 30 or m['k26LichOwnCorpsePenalty']() != 10 or m['k26LichCorpseMaxHd']() != 4 or m['k26LichEvilChoateAdj']() != 6 or m['k26LichJarAllObstacles']() != 1 or m['k26LichWightishBody']() != 1",
      "note" = "the jar law - the erased top three, the ninety foot corpse range, the thirty day limit, the own corpse minus ten, the four die cap and the wightish body the lich blueprint (print 36)",
    }, {
      "expr" = "m['k26LichRemainsEaten']() != 1 or m['k26LichOwnBodyDisintegrateOnly']() != 1 or m['k26LichNoScrollsTouchItems']() != 1 or m['k26LichJarReturnCost']() != 1 or m['k26LichZeroHpDestroyed']() != 1 or m['k26LichNoRadiatePrepared']() != 1",
      "note" = "the lich fate - the remains eaten, the disintegrate only body, the scroll and touch bans, the level toll with the zero point doom and the secrecy the lich blueprint (print 36)",
    }, {
      "expr" = "m['k26LichPotionIngredients']() != 9 or m['k26LichFeeblemindKillPct']() != 10 or m['k26LichDexLossPct']() != 30 or m['k26LichPotionDeathLo']() != 97 or m['k26LichPotionFullMoon']() != 1",
      "note" = "the nine ingredient potion - the feeblemind ten percent, the paralysis dexterity gamble, the 97-00 death band and the full moon brewing the lich blueprint (print 36)",
    }, {
      "expr" = "m['k26PartyAbilityDice']() != 4 or m['k26PartyLowLevelHi']() != 4 or m['k26PartyMidLevelHi']() != 9 or m['k26PartyHighLevelHi']() != 12 or m['k26PartyAlignmentFilter']() != 1 or m['k26PartyMulticlassRound']() != 1 or m['k26PartyEquipmentCheck']() != 1",
      "note" = "the system frame - the 4d4 abilities with the low die dropped, the three level bands to twelve, the alignment gate, the multi class math and the equipment check the impromptu party system (print 37 + 39)",
    }, {
      "expr" = "m['k26PartySurplusThreshold']() != 90 or m['k26PartyAboveAvgPct']() != 1 or m['k26PartyGonzoLevel']() != 9 or m['k26PartyGonzoChainPct']() != 135 or m['k26PartyGonzoPlusTwoPct']() != 54 or m['k26PartyPlusThreeCheck']() != 1 or m['k26PartyArmorOneSort']() != 1 or m['k26PartySpecialFeatures']() != 1 or m['k26PartyBoltsDoubling']() != 1",
      "note" = "the above average rules - the ninety percent surplus, the one percent per level, the Gonzo ninth level ranger with his 135 percent chain and fifty four percent plus two, the plus three check, the one sort armor, the special features and the bolt doubling the impromptu party system (print 37 + 39)",
    }, {
      "expr" = "m['k26PartyMiscItemsHi']() != 4 or m['k26PartyMiscListCount']() != 16 or m['k26PartyRobePatchesLo']() != 7 or m['k26PartyRobePatchesHi']() != 12 or m['k26PartyRobePatchListCount']() != 23 or m['k26PartyPotionTypesCount']() != 10 or m['k26PartyOwnPotionRule']() != 1 or m['k26PartyThiefMuScrolls']() != 1 or m['k26PartyLowPowerKey']() != 1",
      "note" = "the kits - the one to four award off the sixteen item list, the robe with its seven to twelve patches off the twenty three, the ten potion types with the own choice license, the thief magic user scrolls and the low power key the impromptu party system (print 37 + 39)",
    }, {
      "expr" = "m['k26BarghestWhelpDice']() != 6 or m['k26BarghestLitter']() != 6 or m['k26BarghestAcLo']() != 2 or m['k26BarghestAcHi']() != -4 or m['k26BarghestMresPerHd']() != 5 or m['k26BarghestAtWillSpells']() != 5 or m['k26BarghestGehennaDeodand']() != 1 or m['k26BarghestGoblinWorship']() != 1",
      "note" = "the whelp frame - the six plus six dice, the litter of six, the armor class band, the magic resistance per die, the five at will powers, the Gehenna rift and the goblin worship the Dragon Bestiary barghest (print 44)",
    }, {
      "expr" = "m['k26BarghestLevelsPerDie']() != 8 or m['k26BarghestCanineMove']() != 30 or m['k26BarghestMotionlessUnnoticed']() != 75 or m['k26BarghestSurprisePct']() != 50 or m['k26BarghestZeroLevelPrey']() != 1 or m['k26BarghestAcClimb']() != 1 or m['k26BarghestStormGiantPeak']() != 1",
      "note" = "the feeding law - eight levels a die, the thirty foot canine move with the motionless seventy five and the fifty percent ambush, the zero level prey, the climb and the storm giant peak the Dragon Bestiary barghest (print 44)",
    }, {
      "expr" = "m['k26BarghestPlusOneRequired']() != 1 or m['k26BarghestFireNoDamage']() != 1 or m['k26BarghestWeakReturnDoom']() != 1 or m['k26BarghestDogHate']() != 1 or m['k26BarghestOfficialMonsters']() != 1 or m['k26BarghestWhelpXpLo']() != 1275 or m['k26BarghestAdultXpLo']() != 7300 or m['k26BarghestAdultLevel']() != 9 or m['k26BarghestPayment']() != 20",
      "note" = "the barghest fate - the plus one steel gate, the fire immunity with the return doom, the dog tell, the official stamp, the experience ladder from 1275 to 7300 and the twenty dollar column pay the Dragon Bestiary barghest (print 44)",
    }, {
      "expr" = "m['k26ThiefCityDoctrine']() != 1 or m['k26ThiefDungeonCeiling']() != 10 or m['k26ThiefDisguiseRule']() != 1 or m['k26ThiefRooftopTravel']() != 1 or m['k26ThiefAmbushShadows']() != 1 or m['k26ThiefVictimTypes']() != 3 or m['k26ThiefVictimSelection']() != 1 or m['k26ThiefSpiceMerchantLevel']() != 27",
      "note" = "the city doctrine - the ten foot dungeon ceiling, the disguise, the rooftops and the ambush shadows, the three victim trades with the selection law and the 27th level spice merchant warning the city thief doctrine (print 46)",
    }, {
      "expr" = "m['k26ThiefScapegoatPlant']() != 1 or m['k26ThiefPursuitEscape']() != 1 or m['k26ThiefAlibiMethod']() != 1 or m['k26ThiefStashPlaces']() != 2 or m['k26ThiefPlayerTargets']() != 1 or m['k26ThiefRichestFun']() != 1",
      "note" = "the thief ops - the scapegoat plants, the pursuit breaks, the two stashes with the alibi, the player targets and the richest payoff the city thief doctrine (print 46)",
    } },
  "audit" = {
      "label" = "R964 issue-26 commentary set audit",
      "comment" = "the four-chain commentary set audit - the lich recipe with the jar law and the nine ingredient potion, the impromptu party system with the Gonzo example and the robe patches, the barghest whelp growth and the city thief doctrine",
    },
}
