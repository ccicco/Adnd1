// =========================================================================================
// Adnd1 - rules/uadeityprose1.h
// THE DWARVEN DEITY PROSE - the Appendix S description paragraphs open:
// Clanggedin, Vergadain, Dumathoin, Abbathor, and Berronar pin from the clean
// archive.org OCR read
// census 708 -> 709.
//
// The R784 worship-sites round left the per-deity description prose open
// ("the prose alone stays open"); this is part 1 of the five-part close. The
// five dwarven blocks (pp. 110-113) read scan-clean in the archive.org
// full-text OCR: no flagged holes, every pin below is the printed text. The
// stat-block numerics stay R406/R783; the paragraph-level facts pin here -
// the combat gear bonuses, the special abilities, the worship customs, and
// the pantheon relationships. The dvpProseStaysOpen pin keeps true (18
// paragraphs remain); parts 2-5 cover the elves, halflings, gnomes, and orcs.
//
namespace rules {

// ---- the prose consts (the R786 wiring) ----

// The prose round: the Appendix S description paragraphs open here (part 1,
// the dwarves)
inline int udpProseRound()
    { return 786; }

// The feeder round: the R406 stat blocks these paragraphs hang under
inline int udpStatblockFeederRound()
    { return 406; }

// The dwarven census: five blocks described (Clanggedin, Vergadain,
// Dumathoin, Abbathor, Berronar)
inline int udpDwarvenDeityCount()
    { return 5; }

// Giant-type creatures attack Clanggedin at a -4 penalty to hit, the same as
// for mortal dwarves
inline int udpClnGiantAttackToHitMod()
    { return -4; }

// Clanggedin wields a mithral battle axe +4 in each hand
inline int udpClnAxeBonus()
    { return 4; }

// He can throw the axes with either hand up to 100 yards
inline int udpClnAxeThrowYards()
    { return 100; }

// His armor is steel chain mail +5
inline int udpClnChainMailBonus()
    { return 5; }

// Underneath his suit is a set of golden mail +5
inline int udpVgdMailBonus()
    { return 5; }

// His necklace changes his height at will, between one foot
inline int udpVgdHeightMinFeet()
    { return 1; }

// and 15 feet
inline int udpVgdHeightMaxFeet()
    { return 15; }

// At his side is a sword +4
inline int udpVgdSwordBonus()
    { return 4; }

// The sword detects all treasures within 2 inches when the hilt is grasped
inline int udpVgdSwordDetectInches()
    { return 2; }

// He lays veins of iron, copper, gold, silver, and mithral - five metals
inline int udpDumVeinMetalCount()
    { return 5; }

// Miners carry a small diamond or gemstone (10 gp value) to attract his favor
inline int udpDumMinerGemGpValue()
    { return 10; }

// He owns a great two-handed mattock +5 of solidified magma
inline int udpDumMattockBonus()
    { return 5; }

// Once per day he may summon earth elementals
inline int udpDumElementalsPerDay()
    { return 1; }

// The summoning brings at least 3 elementals
inline int udpDumElementalsMin()
    { return 3; }

// and at most 18
inline int udpDumElementalsMax()
    { return 18; }

// Each elemental has 16 hit dice
inline int udpDumElementalHitDice()
    { return 16; }

// He uses metal-, earth-, or stone-related magic-user spells at the 30th
// level of ability
inline int udpDumEarthSpellLevel()
    { return 30; }

// He steals any magical item, or treasure worth more than 1,000 gp
inline int udpAbbStealTreasureGpLimit()
    { return 1000; }

// A 50 percent chance of either stealing outright or slaying the owner then
// taking it
inline int udpAbbStealOrSlayPct()
    { return 50; }

// He uses a dagger +5 with a diamond blade and jeweled hilt
inline int udpAbbDaggerBonus()
    { return 5; }

// The dagger does a base of 2-24 points of damage: the minimum 2
inline int udpAbbDaggerDamageMin()
    { return 2; }

// and the maximum 24
inline int udpAbbDaggerDamageMax()
    { return 24; }

// It detects precious metals (type and amount) in a 2-inch radius
inline int udpAbbDaggerDetectInches()
    { return 2; }

// Anyone but Abbathor who grasps it loses one experience level at once
inline int udpAbbDaggerLevelLossOnGrasp()
    { return 1; }

// and another level each round it is held
inline int udpAbbDaggerLevelLossPerRound()
    { return 1; }

// His shield casts one cause blindness spell per round, save at -6
inline int udpAbbShieldBlindSaveMod()
    { return -6; }

// at any single target within 3 inches
inline int udpAbbShieldBlindRangeInches()
    { return 3; }

// She appears a huge dwarf wearing +5 chainmail of bright silver
inline int udpBerChainMailBonus()
    { return 5; }

// Her brown beard is braided into four rows
inline int udpBerBraidRowCount()
    { return 4; }

// A cut braid regrows in a single day
inline int udpBerBraidRegrowDays()
    { return 1; }

// The cut lock turns to gold worth 10,000 gp at minimum
inline int udpBerLockGoldMinGp()
    { return 10000; }

// and at most 40,000 gp
inline int udpBerLockGoldMaxGp()
    { return 40000; }

// She wields a +4 mace of gold and steel
inline int udpBerMaceBonus()
    { return 4; }

// It slays evil thieves and all assassins on contact, save versus death magic
// at -4
inline int udpBerMaceSaveMod()
    { return -4; }

// One silver ring prevents anyone knowingly telling a falsehood within 10
// inches of her
inline int udpBerTruthRingRadiusInches()
    { return 10; }

// The other prevents thieving in the same area unless its user saves versus
// spell at -2 each round
inline int udpBerTheftRingSaveMod()
    { return -2; }

// A lawful good dwarven fighter appeal with a large sacrifice: a 5 percent
// chance of paladin powers of equal level
inline int udpBerPaladinChancePct()
    { return 5; }

// The powers last 3-6 days: the minimum 3
inline int udpBerPaladinDaysMin()
    { return 3; }

// and the maximum 6
inline int udpBerPaladinDaysMax()
    { return 6; }

// The grant may come only once every 10 years to any individual
inline int udpBerPaladinOncePerYears()
    { return 10; }

// ---- the prose bools (the R786 wiring) ----

// Bald and silver-bearded, he lives in a vast mountain fortress manned by the
// souls of the finest dwarven warriors
inline bool udpClnFortressSouls()
    { return true; }

// He taught the dwarves many special methods of combating giant-types
inline bool udpClnTaughtGiantMethods()
    { return true; }

// and passed his knowledge and skills on to the gnomish gods as well
inline bool udpClnPassedSkillsToGnomes()
    { return true; }

// His most hated enemies are Grolantor the hill giant god and that deity's
// followers
inline bool udpClnHatesGrolantor()
    { return true; }

// In the heat of battle he is fond of singing, unnerving opponents and
// increasing his followers' morale
inline bool udpClnSingsInBattle()
    { return true; }

// His thrown axes do damage as if he had struck the target by hand, with all
// appropriate bonuses
inline bool udpClnThrownAxesStrikeAsHand()
    { return true; }

// He usually uses his magical spell ability only to indirectly affect the
// course of events
inline bool udpClnSpellsIndirectOnly()
    { return true; }

// He resorts to spells or spell devices in close combat only when his Prime
// Material existence is at stake
inline bool udpClnAvoidsSpellsInMelee()
    { return true; }

// The patron god of dwarven merchants
inline bool udpVgdMerchantsPatron()
    { return true; }

// and of most non-evil dwarven thieves is the scheming Vergadain
inline bool udpVgdNonevilThievesPatron()
    { return true; }

// A great poet, he dispenses treasure-location clues hidden in a verse or
// rhyme
inline bool udpVgdPoetClueVerses()
    { return true; }

// His bard-like talents give him the ability to carefully evaluate treasures
// as to their true nature and worth
inline bool udpVgdEvaluatesTreasure()
    { return true; }

// He appears a huge dwarf wearing brown and yellow clothing
inline bool udpVgdBrownAndYellow()
    { return true; }

// His adventures concern elaborate con games played on human, demi-human,
// humanoid, and giant victims
inline bool udpVgdConGames()
    { return true; }

// His followers are usually seen as suspicious characters; few dwarves will
// willingly admit worshiping him
inline bool udpVgdSuspiciousFollowers()
    { return true; }

// A follower's denial of the deity does not offend him, so long as the proper
// sacrifices are made
inline bool udpVgdDenialNotOffensive()
    { return true; }

// He hides the secrets of the earth until they are ready to be uncovered by
// the diligent and the deserving
inline bool udpDumHidesSecrets()
    { return true; }

// He is the protector of the mountain dwarves
inline bool udpDumProtectorOfMountainDwarves()
    { return true; }

// the keeper of all metals
inline bool udpDumKeeperOfMetals()
    { return true; }

// He has never been known to speak, keeping his wisdom to himself, though he
// may send subtle clues to keen observers
inline bool udpDumNeverSpeaks()
    { return true; }

// Moradin named him protector of the mountain dwarves
inline bool udpDumMoradinNamed()
    { return true; }

// He created a paradise for the mountain dwarves to enjoy
inline bool udpDumParadiseForDwarves()
    { return true; }

// Angered when the dwarves destroyed the mountains, his anger turned to
// pleasure at the finely crafted metal items they produced
inline bool udpDumPleasedByCraftsmanship()
    { return true; }

// His enemies are those who plunder the earth's riches for unfair or selfish
// purposes
inline bool udpDumHatesPlunderers()
    { return true; }

// He does not object to tunneling, mining, or the keeping of treasures
// underground
inline bool udpDumAllowsMining()
    { return true; }

// He appears a gigantic dwarven figure with hair and beard of gray stone
inline bool udpDumGrayStoneHair()
    { return true; }

// earth-brown skin
inline bool udpDumEarthBrownSkin()
    { return true; }

// and eyes of silver fire
inline bool udpDumSilverFireEyes()
    { return true; }

// The summoned elementals fight for him to the death, instantly, at will
inline bool udpDumElementalsFightToDeath()
    { return true; }

// He may use only metal-, earth-, or stone-related magic-user spells, no
// others
inline bool udpDumEarthSpellsOnly()
    { return true; }

// Unlike most dwarven deities he maintains friendly relations with
// non-dwarven deities, though only a few
inline bool udpDumFriendlyToNonDwarves()
    { return true; }

// One of his closest allies is Hephaestus, whom he supplies with adamantite
// ore
inline bool udpDumHephaestusAlly()
    { return true; }

// At times an ally of the other dwarven gods, his treachery and lust for
// treasure make him a dangerous associate
inline bool udpAbbTreacherousAlly()
    { return true; }

// He will never help any non-dwarven deity or creature
inline bool udpAbbNeverHelpsNonDwarves()
    { return true; }

// Originally his sphere was the appreciation of valuable gems and metals, not
// necessarily at others' expense
inline bool udpAbbOriginallyAppreciation()
    { return true; }

// He became embittered when Moradin appointed Dumathoin protector of the
// mountain dwarves instead of him
inline bool udpAbbEmbitteredByChoice()
    { return true; }

// His home caverns are said to be made of purest gold - fact or legend
inline bool udpAbbGoldenCaverns()
    { return true; }

// On seeing any magical item or treasure over the limit he attempts to steal
// it outright or slay the owner and take it
inline bool udpAbbSlayOrSteal()
    { return true; }

// He wears leather armor and furs made from the skins of beings who opposed
// him
inline bool udpAbbWearsFurs()
    { return true; }

// His dagger has a diamond blade and jewels set into the hilt
inline bool udpAbbDaggerDiamondBlade()
    { return true; }

// The dagger detects the presence of precious metals, type and amount
inline bool udpAbbDaggerDetectsMetals()
    { return true; }

// Anyone but Abbathor who grasps the weapon suffers experience-level loss
inline bool udpAbbDaggerDrainsGraspers()
    { return true; }

// His shield casts one cause blindness spell per round at a single target at
// a time
inline bool udpAbbShieldBlinds()
    { return true; }

// He maintains an uneasy truce with Vergadain, with whom he sometimes roams
// the Prime Material for treasure
inline bool udpAbbTruceWithVergadain()
    { return true; }

// If frustrated when attempting to steal an item he will try to destroy it
inline bool udpAbbDestroysIfFrustrated()
    { return true; }

// The greatest of all dwarven goddesses is usually held to be Berronar
inline bool udpBerGreatestGoddess()
    { return true; }

// She lives with Moradin in the Seven Heavens at the Soul Forge beneath the
// mountains
inline bool udpBerLivesAtSoulForge()
    { return true; }

// She is the patroness of marriage and love, but not necessarily romance
inline bool udpBerPatronessOfMarriage()
    { return true; }

// Her name is invoked in small home rituals for protection from thieves and
// duplicity
inline bool udpBerInvokedAgainstThieves()
    { return true; }

// At the end of the day a cut lock of her hair turns to gold
inline bool udpBerLockTurnsToGold()
    { return true; }

// She sometimes gives locks of her hair to dwarven communities that are
// exceptionally poor or hard-pressed
inline bool udpBerGivesLocksToPoor()
    { return true; }

// The gift must be invoked by a lawful good dwarven cleric of the highest
// level in the colony, and is extremely rare
inline bool udpBerLockNeedsTopCleric()
    { return true; }

// If this gold or any part of it is used for other than good purposes it will
// all disappear
inline bool udpBerGoldVanishesIfMisused()
    { return true; }

// Her mace slays evil thieves and all assassins on contact
inline bool udpBerMaceSlaysEvilThieves()
    { return true; }

// One of her two silver rings of great power prevents anyone from knowingly
// telling a falsehood within its radius
inline bool udpBerRingTruth()
    { return true; }

// The other prevents the use of thieving abilities by mortals in the same
// area, unless they save versus spell each round of use
inline bool udpBerRingTheft()
    { return true; }

// She is said to have inspired the dwarven custom of exchanging rings for
// exceptional mutual trust and love
inline bool udpBerInspiredRingCustom()
    { return true; }

// The ceremony is almost never undertaken with a non-dwarf, and both
// participants must be lawful good
inline bool udpBerRingCustomLawfulGood()
    { return true; }

// She may bestow the powers of a paladin of equal level upon a lawful good
// dwarven fighter who appeals with an appropriately large sacrifice
inline bool udpBerGrantsPaladinPowers()
    { return true; }

// Only dwarves of exceptionally pure heart are considered for the paladin
// grant
inline bool udpBerPureHeartOnly()
    { return true; }

}   // namespace rules
