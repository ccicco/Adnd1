// =========================================================================================
// Adnd1 - rules/oa72explain.h
// OA EXPLANATION OF MONTHLY EVENTS, printed capture pp. 243-247 - the monthly
// explanations round
// census 622 -> 623.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE EXPLANATIONS: the twenty-eight monthly events of
// Table 72 explained with their durations, chances and effects - the Accident
// of the DM's choice ranging inconvenience to calamity; the Bad Harvest of
// the 25% incomes, the 5% famine and the 50% food blamed on the ruler; the
// Bad Weather halving movement with the 15% desertions; the Bandit Activity
// of the 20-200, the spies and the boast rule; the Birth of the 95/5 and the
// nine months; the Death with the 30% heirless succession and the 2-7-week
// official; the Minor Earthquake of the 5-mile radius and the 20/30 fires;
// the Excessive Taxes of the 30/70; the Famous Person staying his quiet 1d6
// weeks; the Minor Fire of the 10-40/50-70/80-100; the Flooding of the
// 5d4-foot wave; the Haunting real or not; the Horrendous Monster worshipped
// when unbeaten; the Incursions sudden and permanent; the Injustice of the
// 5/20 accusations; the Landslide of the hills and the weeks; the Maiden of
// Virtue of the 50/30/10/10 and the 13s; the Major Battle for the
// BATTLESYSTEM; the Maneater striking 1-2 a week; the Marriage accepted; the
// Notorious Criminal rumored; the Plague seen to the yearly; the Recruiting
// of the 20% sweep; the Troop Movements of the 10/40; the Uprising of the
// 10/60/70/70; the Vengeful Stranger finding 70%; the VIP in disguise. THE
// RIGIDITY: the monthly events rerolled when the player characters change the
// course, the yearly event NEVER rerolled. THE WORKED EXAMPLE: the T'u Lung
// year of the 82 Rebellion, the month 5, the 3-month duration, the 4/3/5
// column split. The prose codifies per the R431 calculus
//
// the gap census after this round: 153 closed, 82 open - the Monthly Events
// prose box flips (census 622 -> 623); NEXT - R701: Table 73 the daily events
// grid (capture p. 247), prefix djo (verify free at the landing), audit "R701
// OA daily events audit", include after rules/oa72explain.h
//
namespace rules {

// ---- the accident, the harvest and the weather ----

// the Accident choice - the DM must decide what accident occurs: a bridge
// collapse, a lightning strike, a runaway cart, a broken levee (print capture
// p. 243)
inline bool djnAccidentDMDecides()
    { return true; }

// the Accident range - at best an inconvenience, at worst substantial loss of
// life, the topic of conversation for some time (print capture p. 243)
inline bool djnAccidentRangedOutcome()
    { return true; }

// the Bad Harvest farm incomes reduced by 25% (print capture p. 243)
inline int djnBadHarvestFarmPct()
    { return 25; }

// the Bad Harvest famine chance - 5% (print capture p. 243)
inline int djnBadHarvestFaminePct()
    { return 5; }

// the Bad Harvest food price increase - 50% (print capture p. 243)
inline int djnBadHarvestFoodPct()
    { return 50; }

// the Bad Harvest blame - the poor harvest blamed on the ruler, the crop
// supposedly punishment for his evil actions (print capture p. 243)
inline bool djnBadHarvestBlameRuler()
    { return true; }

// the Bad Weather movement reduction - all movement reduced by 50% with a
// like effect on trade (print capture p. 243)
inline int djnBadWeatherMovePct()
    { return 50; }

// the Bad Weather desertion - armies in the field suffer a 15% desertion rate
// during the month (print capture p. 243)
inline int djnBadWeatherDesertPct()
    { return 15; }

// the Bad Weather farm income reduction - crops damaged in the farming
// season, income reduced 15% (print capture p. 243)
inline int djnBadWeatherFarmPct()
    { return 15; }

// ---- the bandits, the birth and the death ----

// the Bandit Activity force minimum - 20 bandits moved into the area (print
// capture p. 243)
inline int djnBanditMin()
    { return 20; }

// the Bandit Activity force maximum - up to 200 bandits (print capture p.
// 243)
inline int djnBanditMax()
    { return 200; }

// the Bandit Activity caravan attack chance - a base 50% that any caravan
// moving through is attacked (print capture p. 243)
inline int djnBanditCaravanPct()
    { return 50; }

// the Bandit Activity lone traveler chance - robbed 80% of the time (print
// capture p. 243)
inline int djnBanditLonePct()
    { return 80; }

// the Bandit Activity spies - spies and informers in the towns appraising
// them of caravan and treasury movements (print capture p. 243)
inline bool djnBanditHasSpies()
    { return true; }

// the Bandit Activity boast rule - a merchant publicly letting out a valuable
// cargo sees his caravan automatically attacked (print capture p. 243)
inline bool djnBanditBoastAutoAttack()
    { return true; }

// the Bandit Activity stay - the bandits remain until defeated or the
// pickings too slim to be profitable (print capture p. 243)
inline bool djnBanditStaysUntilSlim()
    { return true; }

// the Birth noble chance - 95% a local noble or government official has a
// child (print capture p. 243)
inline int djnBirthNoblePct()
    { return 95; }

// the Birth miraculous chance - 5% reports of a miraculous birth to a peasant
// family (print capture p. 243)
inline int djnBirthMiraclePct()
    { return 5; }

// the Birth gestation - a married player character learns of the child, the
// actual birth in nine months (print capture p. 243)
inline int djnBirthMonths()
    { return 9; }

// the Birth telling - a married player character learns at this time of the
// coming child (print capture p. 243)
inline bool djnBirthPCTold()
    { return true; }

// the Birth miraculous origins - the child springs from cut bamboo, appears
// from a spring, is found in a shrine, the family honest and pious (print
// capture pp. 243-244)
inline bool djnBirthMiracleOrigins()
    { return true; }

// the Death heirless chance - 30% some other person inherits through adoption
// or assignment of rights, the succession smooth (print capture p. 244)
inline int djnDeathHeirPct()
    { return 30; }

// the Death official arrival minimum - a new government appointee arrives in
// 2-7 weeks (print capture p. 244)
inline int djnDeathWeeksMin()
    { return 2; }

// the Death official arrival maximum - the 2-7 week wait with no duties of
// the post resolved (print capture p. 244)
inline int djnDeathWeeksMax()
    { return 7; }

// the Death succession - a hereditary position filled by his son (print
// capture p. 244)
inline bool djnDeathHereditarySon()
    { return true; }

// the Death weak government - with no strong central government neighboring
// lords seize the fief through force of arms (print capture p. 244)
inline bool djnDeathWeakGovtSeized()
    { return true; }

// the Death suspension - no government duties of the post resolved until the
// new official arrives (print capture p. 244)
inline bool djnDeathDutiesWait()
    { return true; }

// ---- the minor quake, the taxes and the visitor ----

// the Minor Earthquake radius - a 5-mile radius from a DM-chosen center
// (print capture p. 244)
inline int djnQuakeMinorRadiusMi()
    { return 5; }

// the Minor Earthquake damage - 50% of the buildings in the area damaged,
// loss of life minor (print capture p. 244)
inline int djnQuakeMinorBldgPct()
    { return 50; }

// the Minor Earthquake major fire chance - 20% (print capture p. 244)
inline int djnQuakeMinorMajorFirePct()
    { return 20; }

// the Minor Earthquake minor fire chance - 30% (print capture p. 244)
inline int djnQuakeMinorMinorFirePct()
    { return 30; }

// the Minor Earthquake price stretch minimum - building materials double for
// 1-2 months (print capture p. 244)
inline int djnQuakeMinorPriceMonthsMin()
    { return 1; }

// the Minor Earthquake price stretch maximum - the 1-2 month doubled cost
// (print capture p. 244)
inline int djnQuakeMinorPriceMonthsMax()
    { return 2; }

// the Minor Earthquake tremors - preceded by tremors identical to those that
// precede a major quake (print capture p. 244)
inline bool djnQuakeMinorTremorsFirst()
    { return true; }

// the Excessive Taxes uprising chance - 30% (print capture p. 244)
inline int djnTaxesUprisingPct()
    { return 30; }

// the Excessive Taxes bandit increase - 70% chance of increased bandit
// activity as impoverished peasants flee to the hills (print capture p. 244)
inline int djnTaxesBanditPct()
    { return 70; }

// the Excessive Taxes cost - poorer peasants driven into poverty or
// debt-slavery, lands sold at low prices (print capture p. 244)
inline bool djnTaxesDebtSlavery()
    { return true; }

// the Famous Person stay - remains in the area for 1d6 weeks (print capture
// p. 244)
inline int djnFamousWeeksDie()
    { return 6; }

// the Famous Person arrival - attempts to arrive quietly and pass without
// arousing notice (print capture p. 244)
inline bool djnFamousQuietArrival()
    { return true; }

// the Famous Person secrets - may have secret reasons for being in the
// province (print capture p. 244)
inline bool djnFamousSecretReasons()
    { return true; }

// ---- the minor fire, the flooding and the haunting ----

// the Minor Fire city destruction minimum - 10% of the buildings in a city
// (print capture p. 244)
inline int djnFireMinorCityMin()
    { return 10; }

// the Minor Fire city destruction maximum - up to 40% in a city (print
// capture p. 244)
inline int djnFireMinorCityMax()
    { return 40; }

// the Minor Fire town destruction minimum - 50% burned in a town (print
// capture p. 244)
inline int djnFireMinorTownMin()
    { return 50; }

// the Minor Fire town destruction maximum - up to 70% in a town (print
// capture p. 244)
inline int djnFireMinorTownMax()
    { return 70; }

// the Minor Fire village destruction minimum - 80% burned to the ground in a
// village (print capture p. 244)
inline int djnFireMinorVillageMin()
    { return 80; }

// the Minor Fire village destruction maximum - up to 100% in a village (print
// capture p. 244)
inline int djnFireMinorVillageMax()
    { return 100; }

// the Minor Fire mercy - loss of life minor, a useful tool for changing the
// buildings of an established place (print capture p. 244)
inline bool djnFireMinorLifeMinor()
    { return true; }

// the Flooding wave dice - a great wave 5d4 feet high rushing over the
// countryside (print capture p. 244)
inline int djnFloodingWaveDice()
    { return 5; }

// the Flooding wave die size - the 5d4-foot wave (print capture p. 244)
inline int djnFloodingWaveDie()
    { return 4; }

// the Flooding wave width minimum - 101 feet wide (print capture p. 244)
inline int djnFloodingWidthMinFt()
    { return 101; }

// the Flooding wave width maximum - up to 200 feet wide, centered about the
// riverbed (print capture p. 244)
inline int djnFloodingWidthMaxFt()
    { return 200; }

// the Flooding run - the wave rushes downstream 1d6 miles before losing force
// (print capture p. 244)
inline int djnFloodingMilesDie()
    { return 6; }

// the Flooding residual dice - the water level falls to 3d2 inches (print
// capture p. 244)
inline int djnFloodingInchesDice()
    { return 3; }

// the Flooding residual die size - the 3d2-inch height remaining until the
// collapsed construction is rebuilt or the water evaporates (print capture p.
// 244)
inline int djnFloodingInchesDie()
    { return 2; }

// the Flooding nature - sudden and less severe than the yearly Flood, from a
// collapsed levee, dam, dike or upstream cloudburst (print capture p. 244)
inline bool djnFloodingSuddenNotYearly()
    { return true; }

// the Flooding survival - all caught in the wave swept to their deaths unless
// they have a raft or other flotation device (print capture p. 244)
inline bool djnFloodingFlotationSaves()
    { return true; }

// the Haunting reality - the DM decides whether the haunting is real or not
// (print capture pp. 244-245)
inline bool djnHauntingDMDecides()
    { return true; }

// the Haunting use - a ready-made source of adventure, simple or elaborate,
// the spirit completing a task or righting a wrong (print capture p. 245)
inline bool djnHauntingAdventureReady()
    { return true; }

// ---- the monster, the incursions and the injustice ----

// the Horrendous Monster offerings - if not defeated or driven away soon, the
// villagers make offerings to it as an evil god (print capture p. 245)
inline bool djnMonsterWorshippedIfUnbeaten()
    { return true; }

// the Horrendous Monster kin - others of its type or its young appear in the
// same area, the infestation growing (print capture p. 245)
inline bool djnMonsterKinAppear()
    { return true; }

// the Major Incursion arrival - not gradual but a sudden arrival from another
// area, soldiers, refugees, bandits, nomads or prospectors (print capture p.
// 245)
inline bool djnIncursionMajorSudden()
    { return true; }

// the Major Incursion intent - the force intends to establish a permanent
// home, friendly or not (print capture p. 245)
inline bool djnIncursionMajorPermanentIntent()
    { return true; }

// the Minor Incursion - identical to the major except the forces much
// smaller: spying ninjas, bandit reinforcements, a punitive expedition, a
// raiding party (print capture p. 245)
inline bool djnIncursionMinorSameButSmall()
    { return true; }

// the Injustice accusation chance - 5% that a player character is wrongfully
// accused (print capture p. 245)
inline int djnInjusticeAccusePct()
    { return 5; }

// the Injustice enemy accusation chance - 20% if the player character has a
// powerful enemy (print capture p. 245)
inline int djnInjusticeEnemyPct()
    { return 20; }

// the Injustice remedy - stopped by evidence to higher officials or player
// characters acting as protectors of the innocent (print capture p. 245)
inline bool djnInjusticeStoppable()
    { return true; }

// ---- the landslide, the maiden and the battle ----

// the Landslide clearing minimum - mobilized peasants clear the road in 1-2
// weeks (print capture p. 245)
inline int djnLandslideWeeksMin()
    { return 1; }

// the Landslide clearing maximum - the 1-2 week work unless spells speed the
// task (print capture p. 245)
inline int djnLandslideWeeksMax()
    { return 2; }

// the Landslide terrain - only in mountainous or hilly regions, a slide or
// avalanche blocking a main road (print capture p. 245)
inline bool djnLandslideHillsOnly()
    { return true; }

// the Landslide clearing - the peasants mobilized, the work 1-2 weeks unless
// spells speed the task (print capture p. 245)
inline bool djnLandslideSpedBySpells()
    { return true; }

// the Maiden of Virtue noble chance - 50% the daughter of a powerful noble
// (print capture p. 245)
inline int djnMaidenNoblePct()
    { return 50; }

// the Maiden of Virtue magical chance - 30% a maiden of mysterious and
// magical origin (print capture p. 245)
inline int djnMaidenMagicPct()
    { return 30; }

// the Maiden of Virtue princess chance - 10% an exiled princess (print
// capture p. 245)
inline int djnMaidenPrincessPct()
    { return 10; }

// the Maiden of Virtue commoner chance - 10% simply a commoner (print capture
// p. 245)
inline int djnMaidenCommonerPct()
    { return 10; }

// the Maiden of Virtue suitor requirement - a Comeliness and Charisma of at
// least 13 each to even attract her notice (print capture p. 245)
inline int djnMaidenMinStat()
    { return 13; }

// the Maiden of Virtue courtship - the suitor must produce an artistic item
// of quality and possess heroic qualities and skill in the arts (print
// capture p. 245)
inline bool djnMaidenArtRequired()
    { return true; }

// the Maiden of Virtue tasks - maidens of mysterious origin or princesses may
// set impossible tasks for any successful suitor (print capture p. 245)
inline bool djnMaidenImpossibleTasks()
    { return true; }

// the Major Battle resolution - the BATTLESYSTEM Fantasy Combat Supplement
// strongly recommended, otherwise the DM determines the outcome (print
// capture p. 245)
inline bool djnBattleBattlesystem()
    { return true; }

// ---- the maneater, the marriage and the criminal ----

// the Maneater strikes minimum - the animal strikes once or twice a week
// (print capture p. 246)
inline int djnManeaterStrikesMin()
    { return 1; }

// the Maneater strikes maximum - up to twice a week, killing its prey and
// dragging it off (print capture p. 246)
inline int djnManeaterStrikesMax()
    { return 2; }

// the Maneater stay - remains active until captured or killed, striking 1-2
// times a week (print capture p. 246)
inline bool djnManeaterUntilKilled()
    { return true; }

// the Marriage proposal - a courting player character's proposal accepted
// unless the DM rules otherwise (print capture p. 246)
inline bool djnMarriagePCAccepted()
    { return true; }

// the Marriage celebration - the wedding cause for feasting, the player
// characters invited if known (print capture p. 246)
inline bool djnMarriageFeasting()
    { return true; }

// the Notorious Criminal rumor - his presence may only be rumor, a wild goose
// chase (print capture p. 246)
inline bool djnCriminalMaybeRumor()
    { return true; }

// the monthly Plague - see Plague in the yearly events, the R698 pin (print
// capture p. 246)
inline bool djnPlagueSeeYearly()
    { return true; }

// ---- the recruiting, the troops and the uprising ----

// the Recruiting sweep chance - 20% the characters are swept up by the
// recruiting gangs (print capture p. 246)
inline int djnRecruitSweptPct()
    { return 20; }

// the Troop Movements spy arrest chance - 10% any character is arrested as a
// spy (print capture p. 246)
inline int djnTroopsSpyPct()
    { return 10; }

// the Troop Movements ninja orders chance - ninja characters ordered to spy
// on the enemy 40% of the time (print capture p. 246)
inline int djnTroopsNinjaPct()
    { return 40; }

// the Troop Movements cost - looting and collections of rice, grain and
// horses, no repayment expected though notes may be issued (print capture p.
// 246)
inline bool djnTroopsNoRepayment()
    { return true; }

// the Uprising armor chance - only 10% of the peasants have proper armor
// (print capture p. 246)
inline int djnUprisingArmorPct()
    { return 10; }

// the Uprising monastery support chance - 60% a monastery supports them with
// troops, shelter and aid (print capture p. 246)
inline int djnUprisingMonasteryPct()
    { return 60; }

// the Uprising training minimum - a strong leader trains them into an
// effective fighting force in 2-4 months (print capture p. 246)
inline int djnUprisingTrainMin()
    { return 2; }

// the Uprising training maximum - the 2-4 month training stretch (print
// capture p. 246)
inline int djnUprisingTrainMax()
    { return 4; }

// the Uprising government redress chance - 70% the government listens,
// possibly lowering taxes or replacing officials (print capture p. 246)
inline int djnUprisingGovtListensPct()
    { return 70; }

// the Uprising bandit aftermath chance - 70% increased bandit activity
// afterward (print capture p. 246)
inline int djnUprisingBanditAfterPct()
    { return 70; }

// the Uprising bandit aftermath minimum - the increased bandit activity lasts
// 1-3 months (print capture p. 246)
inline int djnUprisingBanditAfterMin()
    { return 1; }

// the Uprising bandit aftermath maximum - the 1-3 month stretch of surviving
// peasants in the hills (print capture p. 246)
inline int djnUprisingBanditAfterMax()
    { return 3; }

// the Uprising spread - spontaneous, beginning in one or two villages and
// spreading quickly, arms from farm implements and hunted-down weapons (print
// capture p. 246)
inline bool djnUprisingSpontaneous()
    { return true; }

// the Uprising severity - no mercy or quarter shown, the peasants fighting to
// the death, all who took part executed if captured (print capture p. 246)
inline bool djnUprisingNoQuarter()
    { return true; }

// the Uprising odds - doomed to failure unless the player characters swing
// the balance of power (print capture p. 246)
inline bool djnUprisingDoomedWithoutPCs()
    { return true; }

// ---- the stranger, the VIP and the rigidity ----

// the Vengeful Stranger finds chance - he learns the player characters'
// whereabouts 70% of the time (print capture pp. 246-247)
inline int djnStrangerFindsPct()
    { return 70; }

// the Vengeful Stranger feud - defeating him brings an ancestral feud between
// the two families (print capture p. 247)
inline bool djnStrangerAncestralFeud()
    { return true; }

// the VIP Visit disguise - an official investigating local misdeeds is
// targeted by them, traveling in disguise (print capture p. 247)
inline bool djnVIPDisguiseWhenInvestigating()
    { return true; }

// the VIP Visit form - official banquets and feasting, the characters hired
// to protect the VIP or do away with him (print capture p. 247)
inline bool djnVIPBanquets()
    { return true; }

// the monthly rigidity - when the player characters change the course,
// monthly events may be rerolled, the yearly event NEVER rerolled (the R698
// pin) (print capture p. 240)
inline bool djnMonthlyRerollable()
    { return true; }

// the known future - knowing the events in advance the DM prepares adventures
// involving them, characters of every level finding a role (print capture p.
// 240)
inline bool djnDMPreparesAdventures()
    { return true; }

// the worked example yearly roll - the 82 Rebellion of the T'u Lung year
// (print capture p. 239)
inline int djnExampleYearlyRoll()
    { return 82; }

// the worked example month roll - the 1d12 outbreak roll of 5, the month Kao
// II (print capture p. 239)
inline int djnExampleMonthRoll()
    { return 5; }

// the worked example duration roll - the 1d6 rebellion duration roll of 3
// (print capture p. 239)
inline int djnExampleDurationRoll()
    { return 3; }

// the worked example opening column - the first four months determined on the
// third column of Table 72 (print capture p. 239)
inline int djnExampleThirdColMonths()
    { return 4; }

// the worked example middle column - the next three months determined on the
// first column, the last months third again (print capture p. 239)
inline int djnExampleFirstColMonths()
    { return 3; }

// the worked example close - the last months use the third column again, the
// 4/3/5 split of the twelve (print capture p. 239)
inline bool djnExampleClosesThirdCol()
    { return true; }

}   // namespace rules
