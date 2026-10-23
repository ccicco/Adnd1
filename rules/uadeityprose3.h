// =========================================================================================
// Adnd1 - rules/uadeityprose3.h
// THE HALFLING DEITY PROSE - part 3 of the Appendix S paragraph close:
// Sheela, Arvoreen, Cyrrollalee, and Brandobaris pin from the clean
// archive.org OCR read
// census 710 -> 711.
//
// Part 3 of the five-part close (R786 the dwarves, R787 the elves). The four
// halfling blocks (pp. 116-118) read scan-clean in the archive.org full-text
// OCR: every pin below is the printed text. The stat-block numerics stay
// R406/R783; the paragraph-level facts pin here - the Sheela entangle craft
// and the quest grant, the Arvoreen reflection and the hero summons, the
// Cyrrollalee furniture gift and the service debt, and the Brandobaris
// dust-ball sleep and the daring reward. Parts 4-5 remain: the gnomes and the
// orcs.
//
namespace rules {

// ---- the prose consts (the R788 wiring) ----

// The prose round: part 3, the halfling paragraphs
inline int udp3ProseRound()
    { return 788; }

// The feeder round: the R406 stat blocks these paragraphs hang under
inline int udp3StatblockFeederRound()
    { return 406; }

// The halfling census: four blocks described (Sheela, Arvoreen, Cyrrollalee,
// Brandobaris)
inline int udp3HalflingDeityCount()
    { return 4; }

// Most communities worship only a few deities, four or five at most: the
// minimum four
inline int udp3PantheonWorshipMin()
    { return 4; }

// and the maximum five
inline int udp3PantheonWorshipMax()
    { return 5; }

// The pantheon has one greater deity only (Yondalla)
inline int udp3GreaterDeityCount()
    { return 1; }

// Two major celebrations are held yearly aside from the regular monthly
// services
inline int udp3SheMajorCelebrations()
    { return 2; }

// The festival length varies by area, averaging about 10 days
inline int udp3SheFestivalAvgDays()
    { return 10; }

// A 1 percent chance that a great quest or sacrifice wins the entangle grant
inline int udp3SheEntangleGrantPct()
    { return 1; }

// The granted entangle casts at the 6th level of ability
inline int udp3SheEntangleLevel()
    { return 6; }

// True neutral halflings cast the granted entangle at 12th level of ability
inline int udp3SheNeutralEntangleLevel()
    { return 12; }

// Her shillelagh-like staff from a blade of grass or twig is +4 to hit
inline int udp3SheStaffBonus()
    { return 4; }

// The staff does 2-16 points of damage plus strength: the minimum 2
inline int udp3SheStaffDamageMin()
    { return 2; }

// and the maximum 16
inline int udp3SheStaffDamageMax()
    { return 16; }

// She creates the staff in one segment
inline int udp3SheStaffCraftSegments()
    { return 1; }

// She can cast entangle once per round as often as she likes
inline int udp3SheEntanglePerRound()
    { return 1; }

// Two failed saves against her entangle slow a troll to one-fourth normal
// speed
inline int udp3SheDoubleCastSpeedDiv()
    { return 4; }

// Each successive entangle after the first inflicts 1-4 points of
// constriction damage: the minimum 1
inline int udp3SheSuccessiveDamageMin()
    { return 1; }

// and the maximum 4
inline int udp3SheSuccessiveDamageMax()
    { return 4; }

// The first attack upon Arvoreen (if it hits) does only half damage,
// regardless of power
inline int udp3ArvFirstAttackDamageDiv()
    { return 2; }

// He can attack unseen for the first 4-16 rounds of combat: the minimum 4
inline int udp3ArvUnseenRoundsMin()
    { return 4; }

// and the maximum 16
inline int udp3ArvUnseenRoundsMax()
    { return 16; }

// He uses a +4 sword that shapechanges into any hand-to-hand weapon he
// desires
inline int udp3ArvSwordBonus()
    { return 4; }

// Once a day Arvoreen may summon halfling fighters
inline int udp3ArvSummonPerDay()
    { return 1; }

// The summon brings 10-40 halfling fighters: the minimum 10
inline int udp3ArvSummonMin()
    { return 10; }

// and the maximum 40
inline int udp3ArvSummonMax()
    { return 40; }

// Each summoned fighter is a 4th-level Hero
inline int udp3ArvSummonHeroLevel()
    { return 4; }

// The summoned heroes are AC 4
inline int udp3ArvSummonAc()
    { return 4; }

// and each has 25 hit points
inline int udp3ArvSummonHp()
    { return 25; }

// She animates all non-living objects within a radius of 6 inches of her
inline int udp3CyrAnimateRadiusInches()
    { return 6; }

// The animation works as if by a 20th-level cleric
inline int udp3CyrAnimateClericLevel()
    { return 20; }

// Up to 20 cubic feet of material
inline int udp3CyrAnimateVolumeMax()
    { return 20; }

// for 20 rounds
inline int udp3CyrAnimateRounds()
    { return 20; }

// She can perform this power up to three times a day
inline int udp3CyrAnimatePerDay()
    { return 3; }

// A 2 percent chance that a faithful follower calling from home gains the
// furniture gift
inline int udp3CyrFurnitureChancePct()
    { return 2; }

// One piece of furniture not larger than 5 cubic feet in volume
inline int udp3CyrFurnitureVolumeMax()
    { return 5; }

// animated for 5 rounds
inline int udp3CyrFurnitureRounds()
    { return 5; }

// attacking all enemies of that halfling once per round
inline int udp3CyrFurnitureAttacksPerRound()
    { return 1; }

// The gift may be given to a halfling character only twice in his or her
// lifetime
inline int udp3CyrGiftLifetimeMax()
    { return 2; }

// Worship services are held on the first day of each month
inline int udp3CyrServiceDayOfMonth()
    { return 1; }

// He carries a dagger +3 he wields when combat cannot be avoided
inline int udp3BraDaggerBonus()
    { return 3; }

// He also uses a +4 sling that hurls a ball of dust
inline int udp3BraSlingBonus()
    { return 4; }

// The dust ball has a maximum range of 48 inches
inline int udp3BraDustRangeMaxInches()
    { return 48; }

// with 24 inches short range
inline int udp3BraDustRangeShortInches()
    { return 24; }

// and 36 inches medium range
inline int udp3BraDustRangeMediumInches()
    { return 36; }

// The victim must save versus spell at -6
inline int udp3BraDustSaveMod()
    { return -6; }

// or fall deeply asleep for 6-36 turns: the minimum 6
inline int udp3BraSleepTurnsMin()
    { return 6; }

// and the maximum 36
inline int udp3BraSleepTurnsMax()
    { return 36; }

// A 5 percent chance his reward goes to any halfling of 10th level or lower
inline int udp3BraRewardChancePct()
    { return 5; }

// The reward-eligible halfling is of 10th level or lower
inline int udp3BraRewardLevelMax()
    { return 10; }

// He rewards such daring only once in that halfling lifetime
inline int udp3BraRewardLifetimeMax()
    { return 1; }

// A 1 percent chance per level that a high-level thief actually meets him
inline int udp3BraMeetChancePctPerLevel()
    { return 1; }

// The meeting chance applies to a halfling thief of 11th level or higher
inline int udp3BraMeetLevelMin()
    { return 11; }

// ---- the prose bools (the R788 wiring) ----

// The halflings have no deities of evil nature, or of war, suffering, fire
// and water, or death
inline bool udp3PantheonOnlyGoodPowers()
    { return true; }

// Yondalla is the top authority among the halfling gods, though her control
// over Brandobaris is minimal at times
inline bool udp3YondallaTopAuthority()
    { return true; }

// Yondalla is usually invoked at funerals as a protector of the departed
// souls of halflings
inline bool udp3YondallaFuneralProtector()
    { return true; }

// The more powerful halfling deities tend to be females, by contrast with the
// dwarven males
inline bool udp3FemaleDeitiesStronger()
    { return true; }

// Most of the pantheon resides on the Seven Heavens in an area known as the
// Green Fields
inline bool udp3GreenFieldsOnSevenHeavens()
    { return true; }

// Sheela Peryroyl and one or two other deities make their homes on the plane
// of Concordant Opposition
inline bool udp3PantheonSheelaConcordant()
    { return true; }

// Brandobaris roams the Prime Material Plane
inline bool udp3PantheonBrandobarisRoams()
    { return true; }

// The neutral-aligned masculine lesser deity Urogalan is primarily an earth
// god
inline bool udp3UrogalanNeutralEarthGod()
    { return true; }

// Urogalan sometimes acts as a judge of and protector of the dead
inline bool udp3UrogalanJudgesDead()
    { return true; }

// Urogalan lives on the plane of Concordant Opposition
inline bool udp3UrogalanOnConcordant()
    { return true; }

// All the halfling deities are pledged to work together against the enemies
// of the halfling people
inline bool udp3PantheonPledgedTogether()
    { return true; }

// Her appearance is that of a halfling female dressed in wildflowers
inline bool udp3SheFlowerDressed()
    { return true; }

// When she sings she causes fields to grow, trees to bud, and seeds to sprout
inline bool udp3SheFieldsGrowWhenSings()
    { return true; }

// She brings good weather to her favored worshipers
inline bool udp3SheWeatherToFaithful()
    { return true; }

// But she can easily send drought or floods to those who worship her poorly
inline bool udp3SheDroughtFloodsToPoorly()
    { return true; }

// Her followers often wear a small flower in her honor
inline bool udp3SheFollowersWearFlower()
    { return true; }

// Her followers strive to work in harmony with nature and the earth
inline bool udp3SheFollowersWorkHarmony()
    { return true; }

// The planting celebration is called The Seeding or New Spring depending on
// the region
inline bool udp3SheSeedingFestival()
    { return true; }

// The harvest celebration is called High Harvest or The Reaping
inline bool udp3SheHighHarvestFestival()
    { return true; }

// Community-wide revelry is common at the celebrations, from evening into
// late night
inline bool udp3SheRevelryAtFestivals()
    { return true; }

// The quests or sacrifices to regain the entangle grant become harder and
// more costly as time goes on
inline bool udp3SheQuestsGrowHarder()
    { return true; }

// Only one such entangle spell may be had at any one time
inline bool udp3SheOneEntangleAtATime()
    { return true; }

// Her entangle effects are cumulative if cast several times over the same
// area
inline bool udp3SheEntangleCumulative()
    { return true; }

// The successive-entangle constriction damage allows no saving throw and hits
// movers and non-movers alike
inline bool udp3SheConstrictionNoSave()
    { return true; }

// Arvoreen never attacks an opponent first
inline bool udp3ArvNeverAttacksFirst()
    { return true; }

// The first magical attack upon him is automatically reflected back upon the
// caster
inline bool udp3ArvFirstMagicReflected()
    { return true; }

// He can go invisible at will
inline bool udp3ArvInvisibleAtWill()
    { return true; }

// He will only engage in combat if he is attacked, though he seeks his
// enemies and actively confronts them
inline bool udp3ArvOnlyFightsIfAttacked()
    { return true; }

// He will not go far out of his way to avoid combat, and will fight to the
// finish
inline bool udp3ArvFightsToFinish()
    { return true; }

// Thieving skills employed against enemies to better later combat are
// permissible to him
inline bool udp3ArvThievingAgainstEnemies()
    { return true; }

// He absolutely forbids stealing from other halflings or allied beings
inline bool udp3ArvNoStealingFromHalflings()
    { return true; }

// The summoned heroes will obey him implicitly
inline bool udp3ArvHeroesObeyImplicitly()
    { return true; }

// Each summoned hero is armed with short sword and short bow
inline bool udp3ArvHeroesSwordAndBow()
    { return true; }

// He is the patron of halfling fighters, the closest thing the halflings have
// to a god of war
inline bool udp3ArvPatronOfFighters()
    { return true; }

// Cyrrollalee is the deity of friendship and trust, and a protector like
// Yondalla
inline bool udp3CyrDeityOfFriendship()
    { return true; }

// She protects the home but keeps the inhabitants from being too defensive
// and closed in
inline bool udp3CyrHomeProtectorOpenDwelling()
    { return true; }

// She appears a normal female halfling with brown hair in simple peasant
// clothing
inline bool udp3CyrPeasantAppearance()
    { return true; }

// Her worst enemies are those who betray the trust of a host, break into
// halfling homes to steal, or break oaths
inline bool udp3CyrEnemyOfTrustBreakers()
    { return true; }

// The animation effects continue even if Cyrrollalee leaves the area
inline bool udp3CyrAnimationPersists()
    { return true; }

// Any halfling receiving the furniture gift is obligated to perform a
// challenging but not exceptionally difficult service afterward
inline bool udp3CyrGiftRequiresService()
    { return true; }

// No particular weapons are associated with her, but she can use any weapon a
// regular fighter could
inline bool udp3CyrAnyFighterWeapon()
    { return true; }

// Her followers are largely regular halflings (0-level characters) and some
// fighter types
inline bool udp3CyrFollowersPlainHomes()
    { return true; }

// He moves so silently that no mortal being or god can hear him if he desires
// concealment
inline bool udp3BraSilenceUnhearable()
    { return true; }

// He can hide so well as to be completely invisible, detectable only with a
// true seeing spell or similar item
inline bool udp3BraHidesExceptTrueSeeing()
    { return true; }

// His dagger magically points out the fastest and safest direction of escape
// from any maze or trap
inline bool udp3BraDaggerPointsEscape()
    { return true; }

// He is immune to maze spells when holding his dagger
inline bool udp3BraMazeImmuneWithDagger()
    { return true; }

// The dust ball does not harm the victim it strikes
inline bool udp3BraDustBallHarmless()
    { return true; }

// He is primarily a clever thief who fools opponents into thinking him
// harmless, then steals them blind and escapes their wrath
inline bool udp3BraTricksterRascal()
    { return true; }

// He meets high-level thieves in the guise of another halfling thief and
// invites them on a thieving adventure
inline bool udp3BraMeetsAsFellowThief()
    { return true; }

// He reveals his identity only after the adventure is over
inline bool udp3BraIdentityOnlyAfter()
    { return true; }

// and only to his followers
inline bool udp3BraIdentityOnlyToFollowers()
    { return true; }

// Non-worshipping companions might find some of their valuables missing when
// the adventure is over
inline bool udp3BraNonWorshippersLoseItems()
    { return true; }

}   // namespace rules
