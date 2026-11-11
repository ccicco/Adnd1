-- oa700: promoted from rules/oa/oa72explain.h (the OA EXPLANATION OF MONTHLY EVENTS, printed capture pp. 243-247 - the monthly);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 700,
  "prefix" = "oa700",
  "banner" = {
      "title" = "OA EXPLANATION OF MONTHLY EVENTS, printed capture pp. 243-247 - the monthly",
      "provenance" = "explanations round census 622 -> 623.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE EXPLANATIONS: the twenty-eight monthly events of Table 72 explained with their durations, chances and effects - the Accident of the DM's choice ranging inconvenience to calamity; the Bad Harvest of the 25% incomes, the 5% famine and the 50% food blamed on the ruler; the Bad Weather halving movement with the 15% desertions; the Bandit Activity of the 20-200, the spies and the boast rule; the Birth of the 95/5 and the nine months; the Death with the 30% heirless succession and the 2-7-week official; the Minor Earthquake of the 5-mile radius and the 20/30 fires; the Excessive Taxes of the 30/70; the Famous Person staying his quiet 1d6 weeks; the Minor Fire of the 10-40/50-70/80-100; the Flooding of the 5d4-foot wave; the Haunting real or not; the Horrendous Monster worshipped when unbeaten; the Incursions sudden and permanent; the Injustice of the 5/20 accusations; the Landslide of the hills and the weeks; the Maiden of Virtue of the 50/30/10/10 and the 13s; the Major Battle for the BATTLESYSTEM; the Maneater striking 1-2 a week; the Marriage accepted; the Notorious Criminal rumored; the Plague seen to the yearly; the Recruiting of the 20% sweep; the Troop Movements of the 10/40; the Uprising of the 10/60/70/70; the Vengeful Stranger finding 70%; the VIP in disguise. THE RIGIDITY: the monthly events rerolled when the player characters change the course, the yearly event NEVER rerolled. THE WORKED EXAMPLE: the T'u Lung year of the 82 Rebellion, the month 5, the 3-month duration, the 4/3/5 column split. The prose codifies per the R431 calculus  the gap census after this round: 153 closed, 82 open - the Monthly Events prose box flips (census 622 -> 623); NEXT - R701: Table 73 the daily events grid (capture p. 247), prefix djo (verify free at the landing), audit \"R701 OA daily events audit\", include after rules/oa/oa72explain.h",
    },
  "consts" = { {
      "name" = "djnBadHarvestFarmPct",
      "value" = 25,
      "comment" = "the Bad Harvest farm incomes reduced by 25% (print capture p. 243)",
    }, {
      "name" = "djnBadHarvestFaminePct",
      "value" = 5,
      "comment" = "the Bad Harvest famine chance - 5% (print capture p. 243)",
    }, {
      "name" = "djnBadHarvestFoodPct",
      "value" = 50,
      "comment" = "the Bad Harvest food price increase - 50% (print capture p. 243)",
    }, {
      "name" = "djnBadWeatherMovePct",
      "value" = 50,
      "comment" = "the Bad Weather movement reduction - all movement reduced by 50% with a like effect on trade (print capture p. 243)",
    }, {
      "name" = "djnBadWeatherDesertPct",
      "value" = 15,
      "comment" = "the Bad Weather desertion - armies in the field suffer a 15% desertion rate during the month (print capture p. 243)",
    }, {
      "name" = "djnBadWeatherFarmPct",
      "value" = 15,
      "comment" = "the Bad Weather farm income reduction - crops damaged in the farming season, income reduced 15% (print capture p. 243)",
    }, {
      "name" = "djnBanditMin",
      "value" = 20,
      "comment" = "the Bandit Activity force minimum - 20 bandits moved into the area (print capture p. 243)",
    }, {
      "name" = "djnBanditMax",
      "value" = 200,
      "comment" = "the Bandit Activity force maximum - up to 200 bandits (print capture p. 243)",
    }, {
      "name" = "djnBanditCaravanPct",
      "value" = 50,
      "comment" = "the Bandit Activity caravan attack chance - a base 50% that any caravan moving through is attacked (print capture p. 243)",
    }, {
      "name" = "djnBanditLonePct",
      "value" = 80,
      "comment" = "the Bandit Activity lone traveler chance - robbed 80% of the time (print capture p. 243)",
    }, {
      "name" = "djnBirthNoblePct",
      "value" = 95,
      "comment" = "the Birth noble chance - 95% a local noble or government official has a child (print capture p. 243)",
    }, {
      "name" = "djnBirthMiraclePct",
      "value" = 5,
      "comment" = "the Birth miraculous chance - 5% reports of a miraculous birth to a peasant family (print capture p. 243)",
    }, {
      "name" = "djnBirthMonths",
      "value" = 9,
      "comment" = "the Birth gestation - a married player character learns of the child, the actual birth in nine months (print capture p. 243)",
    }, {
      "name" = "djnDeathHeirPct",
      "value" = 30,
      "comment" = "the Death heirless chance - 30% some other person inherits through adoption or assignment of rights, the succession smooth (print capture p. 244)",
    }, {
      "name" = "djnDeathWeeksMin",
      "value" = 2,
      "comment" = "the Death official arrival minimum - a new government appointee arrives in 2-7 weeks (print capture p. 244)",
    }, {
      "name" = "djnDeathWeeksMax",
      "value" = 7,
      "comment" = "the Death official arrival maximum - the 2-7 week wait with no duties of the post resolved (print capture p. 244)",
    }, {
      "name" = "djnQuakeMinorRadiusMi",
      "value" = 5,
      "comment" = "the Minor Earthquake radius - a 5-mile radius from a DM-chosen center (print capture p. 244)",
    }, {
      "name" = "djnQuakeMinorBldgPct",
      "value" = 50,
      "comment" = "the Minor Earthquake damage - 50% of the buildings in the area damaged, loss of life minor (print capture p. 244)",
    }, {
      "name" = "djnQuakeMinorMajorFirePct",
      "value" = 20,
      "comment" = "the Minor Earthquake major fire chance - 20% (print capture p. 244)",
    }, {
      "name" = "djnQuakeMinorMinorFirePct",
      "value" = 30,
      "comment" = "the Minor Earthquake minor fire chance - 30% (print capture p. 244)",
    }, {
      "name" = "djnQuakeMinorPriceMonthsMin",
      "value" = 1,
      "comment" = "the Minor Earthquake price stretch minimum - building materials double for 1-2 months (print capture p. 244)",
    }, {
      "name" = "djnQuakeMinorPriceMonthsMax",
      "value" = 2,
      "comment" = "the Minor Earthquake price stretch maximum - the 1-2 month doubled cost (print capture p. 244)",
    }, {
      "name" = "djnTaxesUprisingPct",
      "value" = 30,
      "comment" = "the Excessive Taxes uprising chance - 30% (print capture p. 244)",
    }, {
      "name" = "djnTaxesBanditPct",
      "value" = 70,
      "comment" = "the Excessive Taxes bandit increase - 70% chance of increased bandit activity as impoverished peasants flee to the hills (print capture p. 244)",
    }, {
      "name" = "djnFamousWeeksDie",
      "value" = 6,
      "comment" = "the Famous Person stay - remains in the area for 1d6 weeks (print capture p. 244)",
    }, {
      "name" = "djnFireMinorCityMin",
      "value" = 10,
      "comment" = "the Minor Fire city destruction minimum - 10% of the buildings in a city (print capture p. 244)",
    }, {
      "name" = "djnFireMinorCityMax",
      "value" = 40,
      "comment" = "the Minor Fire city destruction maximum - up to 40% in a city (print capture p. 244)",
    }, {
      "name" = "djnFireMinorTownMin",
      "value" = 50,
      "comment" = "the Minor Fire town destruction minimum - 50% burned in a town (print capture p. 244)",
    }, {
      "name" = "djnFireMinorTownMax",
      "value" = 70,
      "comment" = "the Minor Fire town destruction maximum - up to 70% in a town (print capture p. 244)",
    }, {
      "name" = "djnFireMinorVillageMin",
      "value" = 80,
      "comment" = "the Minor Fire village destruction minimum - 80% burned to the ground in a village (print capture p. 244)",
    }, {
      "name" = "djnFireMinorVillageMax",
      "value" = 100,
      "comment" = "the Minor Fire village destruction maximum - up to 100% in a village (print capture p. 244)",
    }, {
      "name" = "djnFloodingWaveDice",
      "value" = 5,
      "comment" = "the Flooding wave dice - a great wave 5d4 feet high rushing over the countryside (print capture p. 244)",
    }, {
      "name" = "djnFloodingWaveDie",
      "value" = 4,
      "comment" = "the Flooding wave die size - the 5d4-foot wave (print capture p. 244)",
    }, {
      "name" = "djnFloodingWidthMinFt",
      "value" = 101,
      "comment" = "the Flooding wave width minimum - 101 feet wide (print capture p. 244)",
    }, {
      "name" = "djnFloodingWidthMaxFt",
      "value" = 200,
      "comment" = "the Flooding wave width maximum - up to 200 feet wide, centered about the riverbed (print capture p. 244)",
    }, {
      "name" = "djnFloodingMilesDie",
      "value" = 6,
      "comment" = "the Flooding run - the wave rushes downstream 1d6 miles before losing force (print capture p. 244)",
    }, {
      "name" = "djnFloodingInchesDice",
      "value" = 3,
      "comment" = "the Flooding residual dice - the water level falls to 3d2 inches (print capture p. 244)",
    }, {
      "name" = "djnFloodingInchesDie",
      "value" = 2,
      "comment" = "the Flooding residual die size - the 3d2-inch height remaining until the collapsed construction is rebuilt or the water evaporates (print capture p. 244)",
    }, {
      "name" = "djnInjusticeAccusePct",
      "value" = 5,
      "comment" = "the Injustice accusation chance - 5% that a player character is wrongfully accused (print capture p. 245)",
    }, {
      "name" = "djnInjusticeEnemyPct",
      "value" = 20,
      "comment" = "the Injustice enemy accusation chance - 20% if the player character has a powerful enemy (print capture p. 245)",
    }, {
      "name" = "djnLandslideWeeksMin",
      "value" = 1,
      "comment" = "the Landslide clearing minimum - mobilized peasants clear the road in 1-2 weeks (print capture p. 245)",
    }, {
      "name" = "djnLandslideWeeksMax",
      "value" = 2,
      "comment" = "the Landslide clearing maximum - the 1-2 week work unless spells speed the task (print capture p. 245)",
    }, {
      "name" = "djnMaidenNoblePct",
      "value" = 50,
      "comment" = "the Maiden of Virtue noble chance - 50% the daughter of a powerful noble (print capture p. 245)",
    }, {
      "name" = "djnMaidenMagicPct",
      "value" = 30,
      "comment" = "the Maiden of Virtue magical chance - 30% a maiden of mysterious and magical origin (print capture p. 245)",
    }, {
      "name" = "djnMaidenPrincessPct",
      "value" = 10,
      "comment" = "the Maiden of Virtue princess chance - 10% an exiled princess (print capture p. 245)",
    }, {
      "name" = "djnMaidenCommonerPct",
      "value" = 10,
      "comment" = "the Maiden of Virtue commoner chance - 10% simply a commoner (print capture p. 245)",
    }, {
      "name" = "djnMaidenMinStat",
      "value" = 13,
      "comment" = "the Maiden of Virtue suitor requirement - a Comeliness and Charisma of at least 13 each to even attract her notice (print capture p. 245)",
    }, {
      "name" = "djnManeaterStrikesMin",
      "value" = 1,
      "comment" = "the Maneater strikes minimum - the animal strikes once or twice a week (print capture p. 246)",
    }, {
      "name" = "djnManeaterStrikesMax",
      "value" = 2,
      "comment" = "the Maneater strikes maximum - up to twice a week, killing its prey and dragging it off (print capture p. 246)",
    }, {
      "name" = "djnRecruitSweptPct",
      "value" = 20,
      "comment" = "the Recruiting sweep chance - 20% the characters are swept up by the recruiting gangs (print capture p. 246)",
    }, {
      "name" = "djnTroopsSpyPct",
      "value" = 10,
      "comment" = "the Troop Movements spy arrest chance - 10% any character is arrested as a spy (print capture p. 246)",
    }, {
      "name" = "djnTroopsNinjaPct",
      "value" = 40,
      "comment" = "the Troop Movements ninja orders chance - ninja characters ordered to spy on the enemy 40% of the time (print capture p. 246)",
    }, {
      "name" = "djnUprisingArmorPct",
      "value" = 10,
      "comment" = "the Uprising armor chance - only 10% of the peasants have proper armor (print capture p. 246)",
    }, {
      "name" = "djnUprisingMonasteryPct",
      "value" = 60,
      "comment" = "the Uprising monastery support chance - 60% a monastery supports them with troops, shelter and aid (print capture p. 246)",
    }, {
      "name" = "djnUprisingTrainMin",
      "value" = 2,
      "comment" = "the Uprising training minimum - a strong leader trains them into an effective fighting force in 2-4 months (print capture p. 246)",
    }, {
      "name" = "djnUprisingTrainMax",
      "value" = 4,
      "comment" = "the Uprising training maximum - the 2-4 month training stretch (print capture p. 246)",
    }, {
      "name" = "djnUprisingGovtListensPct",
      "value" = 70,
      "comment" = "the Uprising government redress chance - 70% the government listens, possibly lowering taxes or replacing officials (print capture p. 246)",
    }, {
      "name" = "djnUprisingBanditAfterPct",
      "value" = 70,
      "comment" = "the Uprising bandit aftermath chance - 70% increased bandit activity afterward (print capture p. 246)",
    }, {
      "name" = "djnUprisingBanditAfterMin",
      "value" = 1,
      "comment" = "the Uprising bandit aftermath minimum - the increased bandit activity lasts 1-3 months (print capture p. 246)",
    }, {
      "name" = "djnUprisingBanditAfterMax",
      "value" = 3,
      "comment" = "the Uprising bandit aftermath maximum - the 1-3 month stretch of surviving peasants in the hills (print capture p. 246)",
    }, {
      "name" = "djnStrangerFindsPct",
      "value" = 70,
      "comment" = "the Vengeful Stranger finds chance - he learns the player characters' whereabouts 70% of the time (print capture pp. 246-247)",
    }, {
      "name" = "djnExampleYearlyRoll",
      "value" = 82,
      "comment" = "the worked example yearly roll - the 82 Rebellion of the T'u Lung year (print capture p. 239)",
    }, {
      "name" = "djnExampleMonthRoll",
      "value" = 5,
      "comment" = "the worked example month roll - the 1d12 outbreak roll of 5, the month Kao II (print capture p. 239)",
    }, {
      "name" = "djnExampleDurationRoll",
      "value" = 3,
      "comment" = "the worked example duration roll - the 1d6 rebellion duration roll of 3 (print capture p. 239)",
    }, {
      "name" = "djnExampleThirdColMonths",
      "value" = 4,
      "comment" = "the worked example opening column - the first four months determined on the third column of Table 72 (print capture p. 239)",
    }, {
      "name" = "djnExampleFirstColMonths",
      "value" = 3,
      "comment" = "the worked example middle column - the next three months determined on the first column, the last months third again (print capture p. 239)",
    } },
  "bools" = { {
      "name" = "djnAccidentDMDecides",
      "value" = true,
      "comment" = "the Accident choice - the DM must decide what accident occurs: a bridge collapse, a lightning strike, a runaway cart, a broken levee (print capture p. 243)",
    }, {
      "name" = "djnAccidentRangedOutcome",
      "value" = true,
      "comment" = "the Accident range - at best an inconvenience, at worst substantial loss of life, the topic of conversation for some time (print capture p. 243)",
    }, {
      "name" = "djnBadHarvestBlameRuler",
      "value" = true,
      "comment" = "the Bad Harvest blame - the poor harvest blamed on the ruler, the crop supposedly punishment for his evil actions (print capture p. 243)",
    }, {
      "name" = "djnBanditHasSpies",
      "value" = true,
      "comment" = "the Bandit Activity spies - spies and informers in the towns appraising them of caravan and treasury movements (print capture p. 243)",
    }, {
      "name" = "djnBanditBoastAutoAttack",
      "value" = true,
      "comment" = "the Bandit Activity boast rule - a merchant publicly letting out a valuable cargo sees his caravan automatically attacked (print capture p. 243)",
    }, {
      "name" = "djnBanditStaysUntilSlim",
      "value" = true,
      "comment" = "the Bandit Activity stay - the bandits remain until defeated or the pickings too slim to be profitable (print capture p. 243)",
    }, {
      "name" = "djnBirthPCTold",
      "value" = true,
      "comment" = "the Birth telling - a married player character learns at this time of the coming child (print capture p. 243)",
    }, {
      "name" = "djnBirthMiracleOrigins",
      "value" = true,
      "comment" = "the Birth miraculous origins - the child springs from cut bamboo, appears from a spring, is found in a shrine, the family honest and pious (print capture pp. 243-244)",
    }, {
      "name" = "djnDeathHereditarySon",
      "value" = true,
      "comment" = "the Death succession - a hereditary position filled by his son (print capture p. 244)",
    }, {
      "name" = "djnDeathWeakGovtSeized",
      "value" = true,
      "comment" = "the Death weak government - with no strong central government neighboring lords seize the fief through force of arms (print capture p. 244)",
    }, {
      "name" = "djnDeathDutiesWait",
      "value" = true,
      "comment" = "the Death suspension - no government duties of the post resolved until the new official arrives (print capture p. 244)",
    }, {
      "name" = "djnQuakeMinorTremorsFirst",
      "value" = true,
      "comment" = "the Minor Earthquake tremors - preceded by tremors identical to those that precede a major quake (print capture p. 244)",
    }, {
      "name" = "djnTaxesDebtSlavery",
      "value" = true,
      "comment" = "the Excessive Taxes cost - poorer peasants driven into poverty or debt-slavery, lands sold at low prices (print capture p. 244)",
    }, {
      "name" = "djnFamousQuietArrival",
      "value" = true,
      "comment" = "the Famous Person arrival - attempts to arrive quietly and pass without arousing notice (print capture p. 244)",
    }, {
      "name" = "djnFamousSecretReasons",
      "value" = true,
      "comment" = "the Famous Person secrets - may have secret reasons for being in the province (print capture p. 244)",
    }, {
      "name" = "djnFireMinorLifeMinor",
      "value" = true,
      "comment" = "the Minor Fire mercy - loss of life minor, a useful tool for changing the buildings of an established place (print capture p. 244)",
    }, {
      "name" = "djnFloodingSuddenNotYearly",
      "value" = true,
      "comment" = "the Flooding nature - sudden and less severe than the yearly Flood, from a collapsed levee, dam, dike or upstream cloudburst (print capture p. 244)",
    }, {
      "name" = "djnFloodingFlotationSaves",
      "value" = true,
      "comment" = "the Flooding survival - all caught in the wave swept to their deaths unless they have a raft or other flotation device (print capture p. 244)",
    }, {
      "name" = "djnHauntingDMDecides",
      "value" = true,
      "comment" = "the Haunting reality - the DM decides whether the haunting is real or not (print capture pp. 244-245)",
    }, {
      "name" = "djnHauntingAdventureReady",
      "value" = true,
      "comment" = "the Haunting use - a ready-made source of adventure, simple or elaborate, the spirit completing a task or righting a wrong (print capture p. 245)",
    }, {
      "name" = "djnMonsterWorshippedIfUnbeaten",
      "value" = true,
      "comment" = "the Horrendous Monster offerings - if not defeated or driven away soon, the villagers make offerings to it as an evil god (print capture p. 245)",
    }, {
      "name" = "djnMonsterKinAppear",
      "value" = true,
      "comment" = "the Horrendous Monster kin - others of its type or its young appear in the same area, the infestation growing (print capture p. 245)",
    }, {
      "name" = "djnIncursionMajorSudden",
      "value" = true,
      "comment" = "the Major Incursion arrival - not gradual but a sudden arrival from another area, soldiers, refugees, bandits, nomads or prospectors (print capture p. 245)",
    }, {
      "name" = "djnIncursionMajorPermanentIntent",
      "value" = true,
      "comment" = "the Major Incursion intent - the force intends to establish a permanent home, friendly or not (print capture p. 245)",
    }, {
      "name" = "djnIncursionMinorSameButSmall",
      "value" = true,
      "comment" = "the Minor Incursion - identical to the major except the forces much smaller: spying ninjas, bandit reinforcements, a punitive expedition, a raiding party (print capture p. 245)",
    }, {
      "name" = "djnInjusticeStoppable",
      "value" = true,
      "comment" = "the Injustice remedy - stopped by evidence to higher officials or player characters acting as protectors of the innocent (print capture p. 245)",
    }, {
      "name" = "djnLandslideHillsOnly",
      "value" = true,
      "comment" = "the Landslide terrain - only in mountainous or hilly regions, a slide or avalanche blocking a main road (print capture p. 245)",
    }, {
      "name" = "djnLandslideSpedBySpells",
      "value" = true,
      "comment" = "the Landslide clearing - the peasants mobilized, the work 1-2 weeks unless spells speed the task (print capture p. 245)",
    }, {
      "name" = "djnMaidenArtRequired",
      "value" = true,
      "comment" = "the Maiden of Virtue courtship - the suitor must produce an artistic item of quality and possess heroic qualities and skill in the arts (print capture p. 245)",
    }, {
      "name" = "djnMaidenImpossibleTasks",
      "value" = true,
      "comment" = "the Maiden of Virtue tasks - maidens of mysterious origin or princesses may set impossible tasks for any successful suitor (print capture p. 245)",
    }, {
      "name" = "djnBattleBattlesystem",
      "value" = true,
      "comment" = "the Major Battle resolution - the BATTLESYSTEM Fantasy Combat Supplement strongly recommended, otherwise the DM determines the outcome (print capture p. 245)",
    }, {
      "name" = "djnManeaterUntilKilled",
      "value" = true,
      "comment" = "the Maneater stay - remains active until captured or killed, striking 1-2 times a week (print capture p. 246)",
    }, {
      "name" = "djnMarriagePCAccepted",
      "value" = true,
      "comment" = "the Marriage proposal - a courting player character's proposal accepted unless the DM rules otherwise (print capture p. 246)",
    }, {
      "name" = "djnMarriageFeasting",
      "value" = true,
      "comment" = "the Marriage celebration - the wedding cause for feasting, the player characters invited if known (print capture p. 246)",
    }, {
      "name" = "djnCriminalMaybeRumor",
      "value" = true,
      "comment" = "the Notorious Criminal rumor - his presence may only be rumor, a wild goose chase (print capture p. 246)",
    }, {
      "name" = "djnPlagueSeeYearly",
      "value" = true,
      "comment" = "the monthly Plague - see Plague in the yearly events, the R698 pin (print capture p. 246)",
    }, {
      "name" = "djnTroopsNoRepayment",
      "value" = true,
      "comment" = "the Troop Movements cost - looting and collections of rice, grain and horses, no repayment expected though notes may be issued (print capture p. 246)",
    }, {
      "name" = "djnUprisingSpontaneous",
      "value" = true,
      "comment" = "the Uprising spread - spontaneous, beginning in one or two villages and spreading quickly, arms from farm implements and hunted-down weapons (print capture p. 246)",
    }, {
      "name" = "djnUprisingNoQuarter",
      "value" = true,
      "comment" = "the Uprising severity - no mercy or quarter shown, the peasants fighting to the death, all who took part executed if captured (print capture p. 246)",
    }, {
      "name" = "djnUprisingDoomedWithoutPCs",
      "value" = true,
      "comment" = "the Uprising odds - doomed to failure unless the player characters swing the balance of power (print capture p. 246)",
    }, {
      "name" = "djnStrangerAncestralFeud",
      "value" = true,
      "comment" = "the Vengeful Stranger feud - defeating him brings an ancestral feud between the two families (print capture p. 247)",
    }, {
      "name" = "djnVIPDisguiseWhenInvestigating",
      "value" = true,
      "comment" = "the VIP Visit disguise - an official investigating local misdeeds is targeted by them, traveling in disguise (print capture p. 247)",
    }, {
      "name" = "djnVIPBanquets",
      "value" = true,
      "comment" = "the VIP Visit form - official banquets and feasting, the characters hired to protect the VIP or do away with him (print capture p. 247)",
    }, {
      "name" = "djnMonthlyRerollable",
      "value" = true,
      "comment" = "the monthly rigidity - when the player characters change the course, monthly events may be rerolled, the yearly event NEVER rerolled (the R698 pin) (print capture p. 240)",
    }, {
      "name" = "djnDMPreparesAdventures",
      "value" = true,
      "comment" = "the known future - knowing the events in advance the DM prepares adventures involving them, characters of every level finding a role (print capture p. 240)",
    }, {
      "name" = "djnExampleClosesThirdCol",
      "value" = true,
      "comment" = "the worked example close - the last months use the third column again, the 4/3/5 split of the twelve (print capture p. 239)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djnBadHarvestFarmPct']() != 25  or m['djnBadHarvestFaminePct']() != 5  or m['djnBadHarvestFoodPct']() != 50  or m['djnBadWeatherMovePct']() != 50  or m['djnBadWeatherDesertPct']() != 15  or m['djnBadWeatherFarmPct']() != 15  or m['djnBanditMin']() != 20  or m['djnBanditMax']() != 200  or m['djnBanditCaravanPct']() != 50  or m['djnBanditLonePct']() != 80  or m['djnBirthNoblePct']() != 95  or m['djnBirthMiraclePct']() != 5  or m['djnBirthMonths']() != 9  or m['djnDeathHeirPct']() != 30  or m['djnDeathWeeksMin']() != 2  or m['djnDeathWeeksMax']() != 7  or m['djnQuakeMinorRadiusMi']() != 5  or m['djnQuakeMinorBldgPct']() != 50  or m['djnQuakeMinorMajorFirePct']() != 20  or m['djnQuakeMinorMinorFirePct']() != 30  or m['djnQuakeMinorPriceMonthsMin']() != 1  or m['djnQuakeMinorPriceMonthsMax']() != 2  or m['djnTaxesUprisingPct']() != 30  or m['djnTaxesBanditPct']() != 70  or m['djnFamousWeeksDie']() != 6  or m['djnFireMinorCityMin']() != 10  or m['djnFireMinorCityMax']() != 40  or m['djnFireMinorTownMin']() != 50  or m['djnFireMinorTownMax']() != 70  or m['djnFireMinorVillageMin']() != 80  or m['djnFireMinorVillageMax']() != 100  or m['djnFloodingWaveDice']() != 5  or m['djnFloodingWaveDie']() != 4  or m['djnFloodingWidthMinFt']() != 101  or m['djnFloodingWidthMaxFt']() != 200  or m['djnFloodingMilesDie']() != 6  or m['djnFloodingInchesDice']() != 3  or m['djnFloodingInchesDie']() != 2  or m['djnInjusticeAccusePct']() != 5  or m['djnInjusticeEnemyPct']() != 20  or m['djnLandslideWeeksMin']() != 1  or m['djnLandslideWeeksMax']() != 2  or m['djnMaidenNoblePct']() != 50  or m['djnMaidenMagicPct']() != 30  or m['djnMaidenPrincessPct']() != 10  or m['djnMaidenCommonerPct']() != 10  or m['djnMaidenMinStat']() != 13  or m['djnManeaterStrikesMin']() != 1  or m['djnManeaterStrikesMax']() != 2  or m['djnRecruitSweptPct']() != 20  or m['djnTroopsSpyPct']() != 10  or m['djnTroopsNinjaPct']() != 40  or m['djnUprisingArmorPct']() != 10  or m['djnUprisingMonasteryPct']() != 60  or m['djnUprisingTrainMin']() != 2  or m['djnUprisingTrainMax']() != 4  or m['djnUprisingGovtListensPct']() != 70  or m['djnUprisingBanditAfterPct']() != 70  or m['djnUprisingBanditAfterMin']() != 1  or m['djnUprisingBanditAfterMax']() != 3  or m['djnStrangerFindsPct']() != 70  or m['djnExampleYearlyRoll']() != 82  or m['djnExampleMonthRoll']() != 5  or m['djnExampleDurationRoll']() != 3  or m['djnExampleThirdColMonths']() != 4  or m['djnExampleFirstColMonths']() != 3  or  m['djnAccidentDMDecides']() != 1  or  m['djnAccidentRangedOutcome']() != 1  or  m['djnBadHarvestBlameRuler']() != 1  or  m['djnBanditHasSpies']() != 1  or  m['djnBanditBoastAutoAttack']() != 1  or  m['djnBanditStaysUntilSlim']() != 1  or  m['djnBirthPCTold']() != 1  or  m['djnBirthMiracleOrigins']() != 1  or  m['djnDeathHereditarySon']() != 1  or  m['djnDeathWeakGovtSeized']() != 1  or  m['djnDeathDutiesWait']() != 1  or  m['djnQuakeMinorTremorsFirst']() != 1  or  m['djnTaxesDebtSlavery']() != 1  or  m['djnFamousQuietArrival']() != 1  or  m['djnFamousSecretReasons']() != 1  or  m['djnFireMinorLifeMinor']() != 1  or  m['djnFloodingSuddenNotYearly']() != 1  or  m['djnFloodingFlotationSaves']() != 1  or  m['djnHauntingDMDecides']() != 1  or  m['djnHauntingAdventureReady']() != 1  or  m['djnMonsterWorshippedIfUnbeaten']() != 1  or  m['djnMonsterKinAppear']() != 1  or  m['djnIncursionMajorSudden']() != 1  or  m['djnIncursionMajorPermanentIntent']() != 1  or  m['djnIncursionMinorSameButSmall']() != 1  or  m['djnInjusticeStoppable']() != 1  or  m['djnLandslideHillsOnly']() != 1  or  m['djnLandslideSpedBySpells']() != 1  or  m['djnMaidenArtRequired']() != 1  or  m['djnMaidenImpossibleTasks']() != 1  or  m['djnBattleBattlesystem']() != 1  or  m['djnManeaterUntilKilled']() != 1  or  m['djnMarriagePCAccepted']() != 1  or  m['djnMarriageFeasting']() != 1  or  m['djnCriminalMaybeRumor']() != 1  or  m['djnPlagueSeeYearly']() != 1  or  m['djnTroopsNoRepayment']() != 1  or  m['djnUprisingSpontaneous']() != 1  or  m['djnUprisingNoQuarter']() != 1  or  m['djnUprisingDoomedWithoutPCs']() != 1  or  m['djnStrangerAncestralFeud']() != 1  or  m['djnVIPDisguiseWhenInvestigating']() != 1  or  m['djnVIPBanquets']() != 1  or  m['djnMonthlyRerollable']() != 1  or  m['djnDMPreparesAdventures']() != 1  or  m['djnExampleClosesThirdCol']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djnBadHarvestFarmPct']() != 25  or m['djnBadHarvestFaminePct']() != 5  or m['djnBadHarvestFoodPct']() != 50  or m['djnBadWeatherMovePct']() != 50  or m['djnBadWeatherDesertPct']() != 15  or m['djnBadWeatherFarmPct']() != 15  or m['djnBanditMin']() != 20  or m['djnBanditMax']() != 200  or m['djnBanditCaravanPct']() != 50  or m['djnBanditLonePct']() != 80",
      "note" = "the harvest, the weather and the bandits - the 25/5/50 harvest, the 50/15/15 weather, the 20-200 bandits, the 50/80 attacks",
    }, {
      "expr" = "m['djnBirthNoblePct']() != 95  or m['djnBirthMiraclePct']() != 5  or m['djnBirthMonths']() != 9  or m['djnDeathHeirPct']() != 30  or m['djnDeathWeeksMin']() != 2  or m['djnDeathWeeksMax']() != 7",
      "note" = "the birth and the death - the 95/5 birth, the nine months, the 30% heir, the 2-7 weeks",
    }, {
      "expr" = "m['djnQuakeMinorRadiusMi']() != 5  or m['djnQuakeMinorBldgPct']() != 50  or m['djnQuakeMinorMajorFirePct']() != 20  or m['djnQuakeMinorMinorFirePct']() != 30  or m['djnQuakeMinorPriceMonthsMin']() != 1  or m['djnQuakeMinorPriceMonthsMax']() != 2  or m['djnTaxesUprisingPct']() != 30  or m['djnTaxesBanditPct']() != 70",
      "note" = "the minor quake and the taxes - the 5-mile radius, the 50/20/30 damage and fires, the 1-2 months, the 30/70 taxes",
    }, {
      "expr" = "m['djnFireMinorCityMin']() != 10  or m['djnFireMinorCityMax']() != 40  or m['djnFireMinorTownMin']() != 50  or m['djnFireMinorTownMax']() != 70  or m['djnFireMinorVillageMin']() != 80  or m['djnFireMinorVillageMax']() != 100  or m['djnFloodingWaveDice']() != 5  or m['djnFloodingWaveDie']() != 4  or m['djnFloodingWidthMinFt']() != 101  or m['djnFloodingWidthMaxFt']() != 200  or m['djnFloodingMilesDie']() != 6  or m['djnFloodingInchesDice']() != 3  or m['djnFloodingInchesDie']() != 2",
      "note" = "the minor fire and the flooding - the 10-40/50-70/80-100 burns, the 5d4 wave, the 101-200 feet, the 1d6 miles, the 3d2 inches",
    }, {
      "expr" = "m['djnInjusticeAccusePct']() != 5  or m['djnInjusticeEnemyPct']() != 20  or m['djnLandslideWeeksMin']() != 1  or m['djnLandslideWeeksMax']() != 2  or m['djnMaidenNoblePct']() != 50  or m['djnMaidenMagicPct']() != 30  or m['djnMaidenPrincessPct']() != 10  or m['djnMaidenCommonerPct']() != 10  or m['djnMaidenMinStat']() != 13",
      "note" = "the injustice, the landslide and the maiden - the 5/20 accusations, the 1-2 weeks, the 50/30/10/10 maiden, the 13s",
    }, {
      "expr" = "m['djnManeaterStrikesMin']() != 1  or m['djnManeaterStrikesMax']() != 2  or m['djnRecruitSweptPct']() != 20  or m['djnTroopsSpyPct']() != 10  or m['djnTroopsNinjaPct']() != 40  or m['djnUprisingArmorPct']() != 10  or m['djnUprisingMonasteryPct']() != 60  or m['djnUprisingTrainMin']() != 2  or m['djnUprisingTrainMax']() != 4  or m['djnUprisingGovtListensPct']() != 70  or m['djnUprisingBanditAfterPct']() != 70  or m['djnUprisingBanditAfterMin']() != 1  or m['djnUprisingBanditAfterMax']() != 3",
      "note" = "the maneater, the recruiting, the troops and the uprising - the 1-2 strikes, the 20% sweep, the 10/40 troops, the 10/60/70/70 uprising, the 2-4 and 1-3 months",
    }, {
      "expr" = "m['djnStrangerFindsPct']() != 70  or m['djnExampleYearlyRoll']() != 82  or m['djnExampleMonthRoll']() != 5  or m['djnExampleDurationRoll']() != 3  or m['djnExampleThirdColMonths']() != 4  or m['djnExampleFirstColMonths']() != 3",
      "note" = "the stranger, the VIP and the worked example - the 70% stranger, the 82/5/3 rolls, the 4/3 column split",
    }, {
      "expr" = "m['djnMonthlyRerollable']() != 1  or m['djnDMPreparesAdventures']() != 1  or m['djnFamousQuietArrival']() != 1  or m['djnVIPDisguiseWhenInvestigating']() != 1  or m['djnStrangerAncestralFeud']() != 1",
      "note" = "the rigidity bools - the rerollable monthly, the prepared adventures, the quiet famous visitor, the disguised VIP",
    } },
  "audit" = {
      "label" = "R700 OA monthly events prose audit",
      "comment" = "OA round eighty-seven (capture pp. 243-247): the Explanation of Monthly Events - the twenty-eight Table 72 events explained with their durations, chances and effects, plus the worked example and the player-character interaction rules, single-pass pins per the Chapter 9 provenance shift",
    },
}
