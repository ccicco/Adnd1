// =========================================================================================
// Adnd1 - rules/k26.h
// The Dragon issue-26 opener part three - the commentary set
// census 886 -> 887.
//
// The part-three round of the issue-26 four-round shape - four of the
// thirteen Curtiss-called chains pinned as the commentary set: the Blueprint
// for a Lich recipe (print 36), the Lakofka Bazaar of the Bizarre debut with
// the jar law, the corpse possession ladder and the nine ingredient potion;
// the impromptu party system (print 37 + 39), the Gygax convention kit with
// the 4d4 abilities, the level bands, the per class tables and the robe
// patches; the Dragon Bestiary barghest (print 44), the Gehenna deodand with
// the whelp feeding and the fire banishment; and the city thief doctrine
// (print 46), the Stephens disguise, rooftop and scapegoat method. All pinned
// from The Dragon Vol. III No. 12 (June 1979) print 36-37 + 39 + 44 + 46 at
// extract/dragon/026 (landed at R962), the single-voice transcript of the
// Curtiss-provided scan; the Choate thrice print, the Polymorph Serf potions
// row, the barghest stat block foot mark and PSONIC prints and the Gygas
// colophon all pinned as scanned. The watches - the Sullin levels 7-9 and the
// brawling sequel - ride to TD 27 absent a fifth issue.
//
namespace rules {

// ---- the lich blueprint (print 36) ----

// the life minimum - at least 14th level before lichdom, 18th most common the
// lich blueprint (print 36)
inline int k26LichMinLevel()
    { return 14; }

// the undeath floor - no lich below 10th level once created the lich
// blueprint (print 36)
inline int k26LichFloorLevel()
    { return 10; }

// the jar value - at least 2000 gold pieces, high quality and solid the lich
// blueprint (print 36)
inline int k26LichJarValue()
    { return 2000; }

// the enchant window - the eighteen plus hour Enchant an Item casting the
// lich blueprint (print 36)
inline int k26LichEnchantHours()
    { return 18; }

// the trap the soul base - fifty percent plus six per level over 11th the
// lich blueprint (print 36)
inline int k26LichTrapBase()
    { return 50; }

// the trap the soul climb - six percent per level over 11th, the 00 roll
// failing always the lich blueprint (print 36)
inline int k26LichTrapPerLevel()
    { return 6; }

// the ordeal toll - the top three spell levels erased until the rest ends the
// lich blueprint (print 36)
inline int k26LichSpellsErased()
    { return 3; }

// the corpse range - a recently dead body within ninety feet of the jar the
// lich blueprint (print 36)
inline int k26LichCorpseRangeFeet()
    { return 90; }

// the corpse age - dead no longer than thirty days the lich blueprint (print
// 36)
inline int k26LichCorpseMaxDays()
    { return 30; }

// the own corpse penalty - the lich at minus ten to receive himself, once a
// week the lich blueprint (print 36)
inline int k26LichOwnCorpsePenalty()
    { return 10; }

// the possession cap - no more than four hit dice for the corpse the lich
// blueprint (print 36)
inline int k26LichCorpseMaxHd()
    { return 4; }

// the evil Choate rung - saving at minus six, the Choate print pinned as
// scanned thrice the lich blueprint (print 36)
inline int k26LichEvilChoateAdj()
    { return 6; }

// the potion recipe - nine ingredients from the arsenic pinches to the moth
// glands the lich blueprint (print 36)
inline int k26LichPotionIngredients()
    { return 9; }

// the feeblemind gamble - ten percent that each failed removal kills him the
// lich blueprint (print 36)
inline int k26LichFeeblemindKillPct()
    { return 10; }

// the paralysis gamble - thirty percent of a permanent 1-6 dexterity loss the
// lich blueprint (print 36)
inline int k26LichDexLossPct()
    { return 30; }

// the potion death band - 97-00 killing the drinker, the resurrection the
// only way back the lich blueprint (print 36)
inline int k26LichPotionDeathLo()
    { return 97; }

// the jar ban - wooden items never acceptable, the prior magics allowed the
// lich blueprint (print 36)
inline bool k26LichWoodBanned()
    { return true; }

// the jar pull - the next death entering the jar past cubes of force,
// prismatic spheres and lead boxes the lich blueprint (print 36)
inline bool k26LichJarAllObstacles()
    { return true; }

// the wightish body - behaving as a wight with no energy drain, telepathic if
// the corpse could speak the lich blueprint (print 36)
inline bool k26LichWightishBody()
    { return true; }

// the metamorphosis - the wightish body eating the remains, one week to the
// humanoid regrowth the lich blueprint (print 36)
inline bool k26LichRemainsEaten()
    { return true; }

// the body law - destruction only via Disintegrate with a normal save, the
// pieces radiating an unlimited Locate Object the lich blueprint (print 36)
inline bool k26LichOwnBodyDisintegrateOnly()
    { return true; }

// the lich bans - never gaining levels, using scrolls or magic items needing
// a living touch the lich blueprint (print 36)
inline bool k26LichNoScrollsTouchItems()
    { return true; }

// the jar toll - each return costing a level, the tenth level return
// destroying him the lich blueprint (print 36)
inline bool k26LichJarReturnCost()
    { return true; }

// the final death - zero hit points destroying the lich forever, the teleport
// the escape the lich blueprint (print 36)
inline bool k26LichZeroHpDestroyed()
    { return true; }

// the secrecy - the prepared figure radiating nothing, Charm never revealing
// the jar location the lich blueprint (print 36)
inline bool k26LichNoRadiatePrepared()
    { return true; }

// the brewing - the nine ingredients mixed in order by the light of a full
// moon the lich blueprint (print 36)
inline bool k26LichPotionFullMoon()
    { return true; }

// ---- the impromptu party system (print 37 + 39) ----

// the abilities - 4d4 discarding the low die, the scores arranged as desired
// the impromptu party system (print 37 + 39)
inline int k26PartyAbilityDice()
    { return 4; }

// the low band ceiling - the 1-2, 1-3 or 2-4 random the impromptu party
// system (print 37 + 39)
inline int k26PartyLowLevelHi()
    { return 4; }

// the medium band ceiling - the 5-7, 5-8 or 7-9 range the impromptu party
// system (print 37 + 39)
inline int k26PartyMidLevelHi()
    { return 9; }

// the upper band ceiling - the 8-10, 8-11 or 9-12 range the impromptu party
// system (print 37 + 39)
inline int k26PartyHighLevelHi()
    { return 12; }

// the surplus rule - the chance over ninety percent joining the above average
// odds the impromptu party system (print 37 + 39)
inline int k26PartySurplusThreshold()
    { return 90; }

// the above average chance - one percent per level for the plus two the
// impromptu party system (print 37 + 39)
inline int k26PartyAboveAvgPct()
    { return 1; }

// the Gonzo example - the ninth level ranger the impromptu party system
// (print 37 + 39)
inline int k26PartyGonzoLevel()
    { return 9; }

// the Gonzo chain - a 135 percent sure thing for the magic mail the impromptu
// party system (print 37 + 39)
inline int k26PartyGonzoChainPct()
    { return 135; }

// the Gonzo plus two odds - nine plus forty five for fifty four percent, the
// third roll holding him at plus two the impromptu party system (print 37 +
// 39)
inline int k26PartyGonzoPlusTwoPct()
    { return 54; }

// the miscellaneous award - one to four items above 5th into hazard or above
// 8th the impromptu party system (print 37 + 39)
inline int k26PartyMiscItemsHi()
    { return 4; }

// the sixteen item list - the feather falling ring through the wings of
// flying the impromptu party system (print 37 + 39)
inline int k26PartyMiscListCount()
    { return 16; }

// the robe patches - select seven to twelve the impromptu party system (print
// 37 + 39)
inline int k26PartyRobePatchesLo()
    { return 7; }

// the patch ceiling - twelve at most off the menu the impromptu party system
// (print 37 + 39)
inline int k26PartyRobePatchesHi()
    { return 12; }

// the patch menu - twenty three patches from the bonfire to the wasp nest the
// impromptu party system (print 37 + 39)
inline int k26PartyRobePatchListCount()
    { return 23; }

// the potion menu - ten types from climbing to Polymorph Serf, the Serf print
// pinned as scanned the impromptu party system (print 37 + 39)
inline int k26PartyPotionTypesCount()
    { return 10; }

// the alignment gate - two or three compatible types to prevent the quarrel
// breakdown the impromptu party system (print 37 + 39)
inline bool k26PartyAlignmentFilter()
    { return true; }

// the multi class math - one level per profession, divided by the class
// count, fractions counting whole the impromptu party system (print 37 + 39)
inline bool k26PartyMulticlassRound()
    { return true; }

// the equipment gate - whatever desired with the sheets checked, the
// impossible and unlikely refused the impromptu party system (print 37 + 39)
inline bool k26PartyEquipmentCheck()
    { return true; }

// the armor rule - only one sort gained, the choice made before the odds are
// rolled the impromptu party system (print 37 + 39)
inline bool k26PartyArmorOneSort()
    { return true; }

// the plus three check - a straight one percent per level after the plus two
// the impromptu party system (print 37 + 39)
inline bool k26PartyPlusThreeCheck()
    { return true; }

// the special features - the Flame Tongue or Giant Slayer instead of the
// plain plus the impromptu party system (print 37 + 39)
inline bool k26PartySpecialFeatures()
    { return true; }

// the bolt rule - the crossbow of speed with a plus three, otherwise the
// bolts doubled the impromptu party system (print 37 + 39)
inline bool k26PartyBoltsDoubling()
    { return true; }

// the potion license - a 100 percent or better score choosing its own
// supplies the impromptu party system (print 37 + 39)
inline bool k26PartyOwnPotionRule()
    { return true; }

// the thief scrolls - magic user spells, one scroll type only the impromptu
// party system (print 37 + 39)
inline bool k26PartyThiefMuScrolls()
    { return true; }

// the low key - the sixteen items chosen to hold the power down, add or
// delete as desired the impromptu party system (print 37 + 39)
inline bool k26PartyLowPowerKey()
    { return true; }

// ---- the Dragon Bestiary barghest (print 44) ----

// the whelp dice - six plus six to twelve plus twelve hit dice the Dragon
// Bestiary barghest (print 44)
inline int k26BarghestWhelpDice()
    { return 6; }

// the litter - six whelps sent to the Prime Material to feed and grow the
// Dragon Bestiary barghest (print 44)
inline int k26BarghestLitter()
    { return 6; }

// the armor class band - two at the whelp the Dragon Bestiary barghest (print
// 44)
inline int k26BarghestAcLo()
    { return 2; }

// the armor class ceiling - minus four at the full growth the Dragon Bestiary
// barghest (print 44)
inline int k26BarghestAcHi()
    { return -4; }

// the feeding law - eight energy levels to a hit die, a hit point each the
// Dragon Bestiary barghest (print 44)
inline int k26BarghestLevelsPerDie()
    { return 8; }

// the magic resistance - five percent per hit die, ignoring the plusses the
// Dragon Bestiary barghest (print 44)
inline int k26BarghestMresPerHd()
    { return 5; }

// the canine move - the double rate at thirty feet maximum the Dragon
// Bestiary barghest (print 44)
inline int k26BarghestCanineMove()
    { return 30; }

// the motionless dog - seventy five percent unnoticed the Dragon Bestiary
// barghest (print 44)
inline int k26BarghestMotionlessUnnoticed()
    { return 75; }

// the ambush - fifty percent surprise, three in six the Dragon Bestiary
// barghest (print 44)
inline int k26BarghestSurprisePct()
    { return 50; }

// the whelp value - 1275 plus ten per hit point at level seven the Dragon
// Bestiary barghest (print 44)
inline int k26BarghestWhelpXpLo()
    { return 1275; }

// the adult value - 7300 plus eighteen per hit point at level nine the Dragon
// Bestiary barghest (print 44)
inline int k26BarghestAdultXpLo()
    { return 7300; }

// the level ladder - seven through nine across the growth the Dragon Bestiary
// barghest (print 44)
inline int k26BarghestAdultLevel()
    { return 9; }

// the at will powers - five operations from the shapechange to the projected
// image the Dragon Bestiary barghest (print 44)
inline int k26BarghestAtWillSpells()
    { return 5; }

// the Bestiary pay - twenty dollars above the usual rate, the Gygas colophon
// print pinned as scanned the Dragon Bestiary barghest (print 44)
inline int k26BarghestPayment()
    { return 20; }

// the origin - the deodands of the Gehenna rifts, each ruling its smoking
// valley despotically the Dragon Bestiary barghest (print 44)
inline bool k26BarghestGehennaDeodand()
    { return true; }

// the goblin hosts - recognizing and worshipping them, the sacrifices brought
// and the powerful enemies slain the Dragon Bestiary barghest (print 44)
inline bool k26BarghestGoblinWorship()
    { return true; }

// the zero level prey - worth only a half energy level, the exceptional
// persons preferred the Dragon Bestiary barghest (print 44)
inline bool k26BarghestZeroLevelPrey()
    { return true; }

// the growth climb - the armor class and intelligence rising a place per die
// the Dragon Bestiary barghest (print 44)
inline bool k26BarghestAcClimb()
    { return true; }

// the strength peak - from 18/00 at the whelp to the storm giant the Dragon
// Bestiary barghest (print 44)
inline bool k26BarghestStormGiantPeak()
    { return true; }

// the steel gate - hit only by plus one or better weapons the Dragon Bestiary
// barghest (print 44)
inline bool k26BarghestPlusOneRequired()
    { return true; }

// the fire immunity - no damage ever, but a failed canine save hurling it
// back to Gehenna the Dragon Bestiary barghest (print 44)
inline bool k26BarghestFireNoDamage()
    { return true; }

// the return doom - the weak returns slain or enslaved, no return without
// outside help the Dragon Bestiary barghest (print 44)
inline bool k26BarghestWeakReturnDoom()
    { return true; }

// the tell - other dogs fearing and hating it, attacking at every
// opportunity, the ninety five percent lookalike the Dragon Bestiary barghest
// (print 44)
inline bool k26BarghestDogHate()
    { return true; }

// the official stamp - the column monsters official per the author
// arrangement, the stat block foot mark and PSONIC prints pinned as scanned
// the Dragon Bestiary barghest (print 44)
inline bool k26BarghestOfficialMonsters()
    { return true; }

// ---- the city thief doctrine (print 46) ----

// the dungeon limit - the ceiling ten feet high, the wall climb pointless the
// city thief doctrine (print 46)
inline int k26ThiefDungeonCeiling()
    { return 10; }

// the ideal victims - jewelers, coin changers and loan sharks the city thief
// doctrine (print 46)
inline int k26ThiefVictimTypes()
    { return 3; }

// the research warning - the rich spice merchant a 27th level magic user in
// his spare time the city thief doctrine (print 46)
inline int k26ThiefSpiceMerchantLevel()
    { return 27; }

// the stash - loot and disguise in two separate predetermined places the city
// thief doctrine (print 46)
inline int k26ThiefStashPlaces()
    { return 2; }

// the doctrine - thieves belonging in the city, the most misused class the
// city thief doctrine (print 46)
inline bool k26ThiefCityDoctrine()
    { return true; }

// the disguise - the lawful good cleric costume defeating the suspicion the
// city thief doctrine (print 46)
inline bool k26ThiefDisguiseRule()
    { return true; }

// the rooftops - rare encounters, no blockage, nothing to fall from above the
// city thief doctrine (print 46)
inline bool k26ThiefRooftopTravel()
    { return true; }

// the ambush - hiding in shadows for the rich merchants the city thief
// doctrine (print 46)
inline bool k26ThiefAmbushShadows()
    { return true; }

// the victim pick - wealthy enough to bother, unimportant enough to stay safe
// the city thief doctrine (print 46)
inline bool k26ThiefVictimSelection()
    { return true; }

// the scapegoat - smart enough to be believed, dumb enough not to catch, the
// amateur look avoiding the panic, the group over the one with the orcish
// sword and foppish hat plants the city thief doctrine (print 46)
inline bool k26ThiefScapegoatPlant()
    { return true; }

// the pursuit breaks - the sewer, the buildings, the crowd the city thief
// doctrine (print 46)
inline bool k26ThiefPursuitEscape()
    { return true; }

// the alibi - the tavern or inn after the two stashes the city thief doctrine
// (print 46)
inline bool k26ThiefAlibiMethod()
    { return true; }

// the player targets - borrowing the cleric money, the lawful good magic user
// story holding until the chaotic acts the city thief doctrine (print 46)
inline bool k26ThiefPlayerTargets()
    { return true; }

// the payoff - never the most powerful, maybe the richest, the suspense the
// fun the city thief doctrine (print 46)
inline bool k26ThiefRichestFun()
    { return true; }

}   // namespace rules
