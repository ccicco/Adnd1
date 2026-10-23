// =========================================================================================
// Adnd1 - rules/uadeityprose2.h
// THE ELVEN DEITY PROSE - part 2 of the Appendix S paragraph close: Aerdrie,
// Erevan, Solonor, Hanali, and Labelas pin from the clean archive.org OCR
// read
// census 709 -> 710.
//
// Part 2 of the five-part close (R786 opened it with the dwarves). The five
// elven blocks (pp. 113-116) read scan-clean in the archive.org full-text
// OCR: every pin below is the printed text. The stat-block numerics stay
// R406/R783; the paragraph-level facts pin here - the combat abilities (wind
// blasts, elementals, the +5 longbow), the special powers (stasis, the
// Evergold, the charm aura), and the worship customs (the feather-fall quest,
// the slaying-arrow gift, the charisma gift). Parts 3-5 remain: the
// halflings, gnomes, and orcs.
//
namespace rules {

// ---- the prose consts (the R787 wiring) ----

// The prose round: part 2, the elven paragraphs
inline int udp2ProseRound()
    { return 787; }

// The feeder round: the R406 stat blocks these paragraphs hang under
inline int udp2StatblockFeederRound()
    { return 406; }

// The elven census: five blocks described (Aerdrie, Erevan, Solonor, Hanali,
// Labelas)
inline int udp2ElvenDeityCount()
    { return 5; }

// If aroused for battle she casts two great blasts of wind per round
inline int udp2AerWindBlastsPerRound()
    { return 2; }

// Each blast causes 5-20 points of damage: the minimum 5
inline int udp2AerWindBlastDamageMin()
    { return 5; }

// and the maximum 20
inline int udp2AerWindBlastDamageMax()
    { return 20; }

// against any opponent within 96 inches of her
inline int udp2AerWindBlastRangeInches()
    { return 96; }

// She may summon air elementals once per day
inline int udp2AerElementalsPerDay()
    { return 1; }

// at least 2 elementals
inline int udp2AerElementalsMin()
    { return 2; }

// and at most 12
inline int udp2AerElementalsMax()
    { return 12; }

// each with 16 hit dice
inline int udp2AerElementalHitDice()
    { return 16; }

// She may summon giant eagles or rocs twice per day
inline int udp2AerEaglesPerDay()
    { return 2; }

// 3-18 giant eagles: the minimum 3
inline int udp2AerEaglesMin()
    { return 3; }

// and the maximum 18
inline int udp2AerEaglesMax()
    { return 18; }

// or 1-2 rocs: the minimum 1
inline int udp2AerRocsMin()
    { return 1; }

// and the maximum 2
inline int udp2AerRocsMax()
    { return 2; }

// She uses all air, weather, flight, electricity, and gas magic-user spells
// at the 25th level of ability
inline int udp2AerAirSpellLevel()
    { return 25; }

// She can negate at will the flying or levitating abilities of any creature
// within 12 inches
inline int udp2AerNegateFlightRadiusInches()
    { return 12; }

// A falling elf who calls her name aloud has a 2 percent chance of a feather
// fall just before striking the ground
inline int udp2AerFeatherFallChancePct()
    { return 2; }

// The beneficiary is quested and geased within the next 2-7 days: the minimum
// 2
inline int udp2AerQuestGeasDaysMin()
    { return 2; }

// and the maximum 7
inline int udp2AerQuestGeasDaysMax()
    { return 7; }

// His favorite tactic: changing his height to any size between one inch
inline int udp2EreHeightMinInches()
    { return 1; }

// and six feet
inline int udp2EreHeightMaxFeet()
    { return 6; }

// He carries a +4 longsword
inline int udp2EreSwordBonus()
    { return 4; }

// He may summon up to twenty leprechauns, sprites, pixies, or other small
// mischievous elf-like beings
inline int udp2EreSummonMax()
    { return 20; }

// He can cast the spells chaos and polymorph any object once per round at
// will
inline int udp2EreChaosCastsPerRound()
    { return 1; }

// His only weapon is a +5 longbow with a range as far as the horizon
inline int udp2SolLongbowBonus()
    { return 5; }

// He cannot be surprised by any being within 48 inches of him
inline int udp2SolSurpriseRadiusInches()
    { return 48; }

// It takes one day to make one of his special arrows of slaying
inline int udp2SolArrowCraftDays()
    { return 1; }

// The special arrow of slaying is +3
inline int udp2SolArrowBonus()
    { return 3; }

// An extraordinary worshiper has a 2 percent chance of being given an arrow
// of slaying of the normal sort
inline int udp2SolSlayingArrowChancePct()
    { return 2; }

// Bathing in the Evergold enhances her charisma score for one day
inline int udp2HanBathEnhanceDays()
    { return 1; }

// During that day she receives a +75 percent reaction bonus
inline int udp2HanReactionBonusPct()
    { return 75; }

// and inspires awe in characters of up to 14th level
inline int udp2HanAweMaxLevel()
    { return 14; }

// She has a magical aura of 6 inches radius
inline int udp2HanAuraRadiusInches()
    { return 6; }

// Beings within the aura must save versus spell at -4 each round or be
// permanently charmed by her beauty
inline int udp2HanAuraSaveMod()
    { return -4; }

// She may only be attacked by beings with a +2 or better weapon
inline int udp2HanAttackWeaponMin()
    { return 2; }

// and a negative charisma, from -1
inline int udp2HanAttackChaMin()
    { return -1; }

// to -7
inline int udp2HanAttackChaMax()
    { return -7; }

// An elven worshiper may once in a lifetime be granted a two-charisma-point
// increase with respect to the opposite sex
inline int udp2HanChaGift()
    { return 2; }

// There is a 5 percent chance of the charisma gift following a great quest
inline int udp2HanChaGiftChancePct()
    { return 5; }

// He wears pale-colored robes of green, blue, white, and gray - four colors
inline int udp2LabRobeColorCount()
    { return 4; }

// Once per round his gaze can place a being within 12 inches in temporal
// stasis, no saving throw, for as long as desired
inline int udp2LabStasisPerRound()
    { return 1; }

// The temporal stasis gaze reaches 12 inches
inline int udp2LabStasisRadiusInches()
    { return 12; }

// At a touch he can restore youth to or prematurely age any being by up to
// 100 years in either direction, save versus spell applicable
inline int udp2LabAgeYearsMax()
    { return 100; }

// All mortal enemies within 18 inches are slowed automatically, and mortal
// allies in the same radius are hastened if he chooses; no saving throw,
// though magic resistance could help
inline int udp2LabSlowHasteRadiusInches()
    { return 18; }

// Worshipers may appeal to undo the effects of age, but this is a 1 percent
// chance, only after an outstanding quest in his name
inline int udp2LabAgeUndoChancePct()
    { return 1; }

// ---- the prose bools (the R787 wiring) ----

// A tall elf-like woman with feathered hair and eyebrows, a pair of large
// bird-like wings springing from her back
inline bool udp2AerFeatheredAppearance()
    { return true; }

// Her feathers are of constantly changing color
inline bool udp2AerFeathersChangeColor()
    { return true; }

// The lower half of her body vanishes into a misty whirlwind, so she appears
// to never touch the ground
inline bool udp2AerNeverTouchesGround()
    { return true; }

// She wanders the winds of the planes of Olympus and Gladsheim in the company
// of a large number of winged creatures of many types
inline bool udp2AerWandersWithWinged()
    { return true; }

// Her summoned creatures will obey her unto death
inline bool udp2AerSummonsObeyUntoDeath()
    { return true; }

// Her air and weather spells may be used as often as desired, one spell per
// round
inline bool udp2AerAirSpellsAtWill()
    { return true; }

// Any elves of non-lawful and non-evil alignment may worship her
inline bool udp2AerWorshipAlignments()
    { return true; }

// Elves desiring certain weather conditions make the most frequent sacrifices
// to her, and her cult is popular with flying-mount owners (griffons,
// hippogriffs, pegasi)
inline bool udp2AerWeatherCult()
    { return true; }

// The feather fall beneficiaries need not be her worshipers, but should be of
// the same alignment
inline bool udp2AerGiftNeedsNoWorship()
    { return true; }

// The quest and geas come with no saving throws allowed, within the stated
// days, commensurate with the character's level, and comparatively
// challenging
inline bool udp2AerGiftGeasesNoSave()
    { return true; }

// His following is not as large as those of the other elven deities, though
// thieves give him attention
inline bool udp2EreSmallFollowing()
    { return true; }

// A fickle, utterly unpredictable deity who can change his appearance at will
inline bool udp2EreFickleUnpredictable()
    { return true; }

// He enjoys causing trouble for its own sake, but his pranks are rarely
// either helpful or deadly
inline bool udp2ErePranksRarelyHarmful()
    { return true; }

// Regardless of how he appears, he will always wear green somewhere upon his
// person
inline bool udp2EreAlwaysWearsGreen()
    { return true; }

// His longsword knocks open all barriers, doors, and locks with but a touch
inline bool udp2EreSwordOpensAll()
    { return true; }

// His summoned small beings each have maximum hit points
inline bool udp2EreSummonsMaxHitPoints()
    { return true; }

// He will rarely fight another being directly, preferring to escape and catch
// his opponent off guard later
inline bool udp2ErePrefersEscape()
    { return true; }

// Prior to entering combat it is very likely he makes extensive use of his
// chaos and polymorph spells
inline bool udp2EreCastsBeforeCombat()
    { return true; }

// His followers are quite unpredictable themselves and very independent, many
// of them thieves
inline bool udp2EreFollowersIndependent()
    { return true; }

// Elven cleric/thieves and fighter/cleric/thieves are known among his
// worshipers, class combinations not normally possible to elvenkind
inline bool udp2EreAllowsOddCombos()
    { return true; }

// These multi-classed characters are always non-player characters
inline bool udp2EreCombosAlwaysNpcs()
    { return true; }

// Clad in a great cloak of living leaves
inline bool udp2SolCloakOfLeaves()
    { return true; }

// He strides through the forests in search of game and to seek out and
// destroy evil
inline bool udp2SolHuntsEvil()
    { return true; }

// He will not close to do battle with an enemy, but will track and pursue
// instead
inline bool udp2SolNeverCloses()
    { return true; }

// firing arrows from a never-empty quiver
inline bool udp2SolNeverEmptyQuiver()
    { return true; }

// His favorite tactic against a dangerous foe: physically touch the being and
// then retreat, then manufacture a special arrow of slaying designed to kill
// that one opponent
inline bool udp2SolTouchAndRetreat()
    { return true; }

// The special arrow can kill any intended target of up to, but not including,
// demigod status
inline bool udp2SolArrowKillsToDemigod()
    { return true; }

// Demons, devils, and other lower-planar monsters have felt these missiles;
// not even their magic resistance protects them from certain death
inline bool udp2SolArrowBeatsMagicRes()
    { return true; }

// Traveling through forests he becomes automatically invisible, as in
// improved invisibility (the 4th-level illusionist spell), and completely
// silent
inline bool udp2SolForestInvisible()
    { return true; }

// He taught the first elves the art of hiding in and moving through natural
// foliage undetected
inline bool udp2SolTaughtHiding()
    { return true; }

// The slaying-arrow gift can be received only once in an elf's lifetime,
// designed to slay the creature that is the elf's greatest enemy at the time
inline bool udp2SolGiftOncePerLife()
    { return true; }

// Predominantly depicted as feminine, though on rare occasions said to have
// appeared as a male
inline bool udp2HanMostlyFeminine()
    { return true; }

// She influences the spheres of love and beauty and is widely revered by many
// of the elves
inline bool udp2HanSpheresLoveBeauty()
    { return true; }

// She owns an immense crystal fountain and pool with which she keeps watch
// over her followers, as if using a crystal ball
inline bool udp2HanEvergoldPool()
    { return true; }

// Her bath bonuses are only effective against elves and half-elves
inline bool udp2HanBonusElvesOnly()
    { return true; }

// Aphrodite is the only other being who shares the waters of Evergold,
// gaining the same bonuses against humans
inline bool udp2HanAphroditeShares()
    { return true; }

// The two goddesses rarely find themselves at odds; their cults rarely assist
// one another but do not object to each other's presence
inline bool udp2HanCultsCoexist()
    { return true; }

// She has no physical attack mode as such
inline bool udp2HanNoPhysicalAttack()
    { return true; }

// Beings within her aura who fail the save are permanently charmed by her
// beauty
inline bool udp2HanAuraCharms()
    { return true; }

// All other attackers are so distracted by her presence as to miss her with
// every hit
inline bool udp2HanOthersAlwaysMiss()
    { return true; }

// The charisma increase with respect to the opposite sex is permanent,
// granted once during the worshiper's lifetime
inline bool udp2HanChaGiftPermanent()
    { return true; }

// The quest might involve the creation or preservation of a beautiful object,
// or mighty deeds done in the name of a loved one for the loved one's benefit
inline bool udp2HanQuestShape()
    { return true; }

// Like Corellon Larethian, he variously appears as both male or female, and
// sometimes both or neither
inline bool udp2LabBothGenders()
    { return true; }

// Regardless of gender, he always has silvery hair and misty gray eyes
inline bool udp2LabSilveryHair()
    { return true; }

// At the creation of the elven races he blessed them with longevity and
// pronounced that the passage of time would do little to alter their
// appearances as it did the other races
inline bool udp2LabBlessedLongevity()
    { return true; }

// He knows the future and past of every elf and all elven-related creatures
inline bool udp2LabKnowsEveryElf()
    { return true; }

// He is acknowledged by the elves to be the master of time and aging
inline bool udp2LabMasterOfTime()
    { return true; }

// The temporal stasis gaze carries no saving throw and lasts as long as
// desired
inline bool udp2LabStasisNoSave()
    { return true; }

// The youth or aging power is used only once, one form or the other, on a
// creature during its lifetime
inline bool udp2LabAgeOncePerCreature()
    { return true; }

// The slow and haste effects carry no saving throw, though magic resistance
// could help
inline bool udp2LabSlowHasteNoSave()
    { return true; }

// He is immune to any spell or effect that involves time or would inhibit his
// movement (time stop, temporal stasis, slow, paralysis, hold)
inline bool udp2LabTimeImmune()
    { return true; }

// The age-undoing appeal is granted only to those who have done an
// outstanding quest in his name
inline bool udp2LabUndoAgeRare()
    { return true; }

// Such quests usually involve the recovery of artifacts and relics lost for
// hundreds or thousands of years
inline bool udp2LabQuestArtifacts()
    { return true; }

// His followers are usually historians or others who collect information on
// the past history of elvenkind
inline bool udp2LabFollowersHistorians()
    { return true; }

}   // namespace rules
