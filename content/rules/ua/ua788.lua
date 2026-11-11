-- ua: promoted from rules/ua/uadeityprose3.h (the THE HALFLING DEITY PROSE - part 3 of the Appendix S paragraph close:);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 788,
  "prefix" = "ua",
  "banner" = {
      "title" = "THE HALFLING DEITY PROSE - part 3 of the Appendix S paragraph close:",
      "provenance" = "Sheela, Arvoreen, Cyrrollalee, and Brandobaris pin from the clean archive.org OCR read census 710 -> 711.  Part 3 of the five-part close (R786 the dwarves, R787 the elves). The four halfling blocks (pp. 116-118) read scan-clean in the archive.org full-text OCR: every pin below is the printed text. The stat-block numerics stay R406/R783; the paragraph-level facts pin here - the Sheela entangle craft and the quest grant, the Arvoreen reflection and the hero summons, the Cyrrollalee furniture gift and the service debt, and the Brandobaris dust-ball sleep and the daring reward. Parts 4-5 remain: the gnomes and the orcs.",
    },
  "consts" = { {
      "name" = "udp3ProseRound",
      "value" = 788,
      "comment" = "---- the prose consts (the R788 wiring) ---- The prose round: part 3, the halfling paragraphs",
    }, {
      "name" = "udp3StatblockFeederRound",
      "value" = 406,
      "comment" = "The feeder round: the R406 stat blocks these paragraphs hang under",
    }, {
      "name" = "udp3HalflingDeityCount",
      "value" = 4,
      "comment" = "The halfling census: four blocks described (Sheela, Arvoreen, Cyrrollalee, Brandobaris)",
    }, {
      "name" = "udp3PantheonWorshipMin",
      "value" = 4,
      "comment" = "Most communities worship only a few deities, four or five at most: the minimum four",
    }, {
      "name" = "udp3PantheonWorshipMax",
      "value" = 5,
      "comment" = "and the maximum five",
    }, {
      "name" = "udp3GreaterDeityCount",
      "value" = 1,
      "comment" = "The pantheon has one greater deity only (Yondalla)",
    }, {
      "name" = "udp3SheMajorCelebrations",
      "value" = 2,
      "comment" = "Two major celebrations are held yearly aside from the regular monthly services",
    }, {
      "name" = "udp3SheFestivalAvgDays",
      "value" = 10,
      "comment" = "The festival length varies by area, averaging about 10 days",
    }, {
      "name" = "udp3SheEntangleGrantPct",
      "value" = 1,
      "comment" = "A 1 percent chance that a great quest or sacrifice wins the entangle grant",
    }, {
      "name" = "udp3SheEntangleLevel",
      "value" = 6,
      "comment" = "The granted entangle casts at the 6th level of ability",
    }, {
      "name" = "udp3SheNeutralEntangleLevel",
      "value" = 12,
      "comment" = "True neutral halflings cast the granted entangle at 12th level of ability",
    }, {
      "name" = "udp3SheStaffBonus",
      "value" = 4,
      "comment" = "Her shillelagh-like staff from a blade of grass or twig is +4 to hit",
    }, {
      "name" = "udp3SheStaffDamageMin",
      "value" = 2,
      "comment" = "The staff does 2-16 points of damage plus strength: the minimum 2",
    }, {
      "name" = "udp3SheStaffDamageMax",
      "value" = 16,
      "comment" = "and the maximum 16",
    }, {
      "name" = "udp3SheStaffCraftSegments",
      "value" = 1,
      "comment" = "She creates the staff in one segment",
    }, {
      "name" = "udp3SheEntanglePerRound",
      "value" = 1,
      "comment" = "She can cast entangle once per round as often as she likes",
    }, {
      "name" = "udp3SheDoubleCastSpeedDiv",
      "value" = 4,
      "comment" = "Two failed saves against her entangle slow a troll to one-fourth normal speed",
    }, {
      "name" = "udp3SheSuccessiveDamageMin",
      "value" = 1,
      "comment" = "Each successive entangle after the first inflicts 1-4 points of constriction damage: the minimum 1",
    }, {
      "name" = "udp3SheSuccessiveDamageMax",
      "value" = 4,
      "comment" = "and the maximum 4",
    }, {
      "name" = "udp3ArvFirstAttackDamageDiv",
      "value" = 2,
      "comment" = "The first attack upon Arvoreen (if it hits) does only half damage, regardless of power",
    }, {
      "name" = "udp3ArvUnseenRoundsMin",
      "value" = 4,
      "comment" = "He can attack unseen for the first 4-16 rounds of combat: the minimum 4",
    }, {
      "name" = "udp3ArvUnseenRoundsMax",
      "value" = 16,
      "comment" = "and the maximum 16",
    }, {
      "name" = "udp3ArvSwordBonus",
      "value" = 4,
      "comment" = "He uses a +4 sword that shapechanges into any hand-to-hand weapon he desires",
    }, {
      "name" = "udp3ArvSummonPerDay",
      "value" = 1,
      "comment" = "Once a day Arvoreen may summon halfling fighters",
    }, {
      "name" = "udp3ArvSummonMin",
      "value" = 10,
      "comment" = "The summon brings 10-40 halfling fighters: the minimum 10",
    }, {
      "name" = "udp3ArvSummonMax",
      "value" = 40,
      "comment" = "and the maximum 40",
    }, {
      "name" = "udp3ArvSummonHeroLevel",
      "value" = 4,
      "comment" = "Each summoned fighter is a 4th-level Hero",
    }, {
      "name" = "udp3ArvSummonAc",
      "value" = 4,
      "comment" = "The summoned heroes are AC 4",
    }, {
      "name" = "udp3ArvSummonHp",
      "value" = 25,
      "comment" = "and each has 25 hit points",
    }, {
      "name" = "udp3CyrAnimateRadiusInches",
      "value" = 6,
      "comment" = "She animates all non-living objects within a radius of 6 inches of her",
    }, {
      "name" = "udp3CyrAnimateClericLevel",
      "value" = 20,
      "comment" = "The animation works as if by a 20th-level cleric",
    }, {
      "name" = "udp3CyrAnimateVolumeMax",
      "value" = 20,
      "comment" = "Up to 20 cubic feet of material",
    }, {
      "name" = "udp3CyrAnimateRounds",
      "value" = 20,
      "comment" = "for 20 rounds",
    }, {
      "name" = "udp3CyrAnimatePerDay",
      "value" = 3,
      "comment" = "She can perform this power up to three times a day",
    }, {
      "name" = "udp3CyrFurnitureChancePct",
      "value" = 2,
      "comment" = "A 2 percent chance that a faithful follower calling from home gains the furniture gift",
    }, {
      "name" = "udp3CyrFurnitureVolumeMax",
      "value" = 5,
      "comment" = "One piece of furniture not larger than 5 cubic feet in volume",
    }, {
      "name" = "udp3CyrFurnitureRounds",
      "value" = 5,
      "comment" = "animated for 5 rounds",
    }, {
      "name" = "udp3CyrFurnitureAttacksPerRound",
      "value" = 1,
      "comment" = "attacking all enemies of that halfling once per round",
    }, {
      "name" = "udp3CyrGiftLifetimeMax",
      "value" = 2,
      "comment" = "The gift may be given to a halfling character only twice in his or her lifetime",
    }, {
      "name" = "udp3CyrServiceDayOfMonth",
      "value" = 1,
      "comment" = "Worship services are held on the first day of each month",
    }, {
      "name" = "udp3BraDaggerBonus",
      "value" = 3,
      "comment" = "He carries a dagger +3 he wields when combat cannot be avoided",
    }, {
      "name" = "udp3BraSlingBonus",
      "value" = 4,
      "comment" = "He also uses a +4 sling that hurls a ball of dust",
    }, {
      "name" = "udp3BraDustRangeMaxInches",
      "value" = 48,
      "comment" = "The dust ball has a maximum range of 48 inches",
    }, {
      "name" = "udp3BraDustRangeShortInches",
      "value" = 24,
      "comment" = "with 24 inches short range",
    }, {
      "name" = "udp3BraDustRangeMediumInches",
      "value" = 36,
      "comment" = "and 36 inches medium range",
    }, {
      "name" = "udp3BraDustSaveMod",
      "value" = -6,
      "comment" = "The victim must save versus spell at -6",
    }, {
      "name" = "udp3BraSleepTurnsMin",
      "value" = 6,
      "comment" = "or fall deeply asleep for 6-36 turns: the minimum 6",
    }, {
      "name" = "udp3BraSleepTurnsMax",
      "value" = 36,
      "comment" = "and the maximum 36",
    }, {
      "name" = "udp3BraRewardChancePct",
      "value" = 5,
      "comment" = "A 5 percent chance his reward goes to any halfling of 10th level or lower",
    }, {
      "name" = "udp3BraRewardLevelMax",
      "value" = 10,
      "comment" = "The reward-eligible halfling is of 10th level or lower",
    }, {
      "name" = "udp3BraRewardLifetimeMax",
      "value" = 1,
      "comment" = "He rewards such daring only once in that halfling lifetime",
    }, {
      "name" = "udp3BraMeetChancePctPerLevel",
      "value" = 1,
      "comment" = "A 1 percent chance per level that a high-level thief actually meets him",
    }, {
      "name" = "udp3BraMeetLevelMin",
      "value" = 11,
      "comment" = "The meeting chance applies to a halfling thief of 11th level or higher",
    } },
  "bools" = { {
      "name" = "udp3PantheonOnlyGoodPowers",
      "value" = true,
      "comment" = "---- the prose bools (the R788 wiring) ---- The halflings have no deities of evil nature, or of war, suffering, fire and water, or death",
    }, {
      "name" = "udp3YondallaTopAuthority",
      "value" = true,
      "comment" = "Yondalla is the top authority among the halfling gods, though her control over Brandobaris is minimal at times",
    }, {
      "name" = "udp3YondallaFuneralProtector",
      "value" = true,
      "comment" = "Yondalla is usually invoked at funerals as a protector of the departed souls of halflings",
    }, {
      "name" = "udp3FemaleDeitiesStronger",
      "value" = true,
      "comment" = "The more powerful halfling deities tend to be females, by contrast with the dwarven males",
    }, {
      "name" = "udp3GreenFieldsOnSevenHeavens",
      "value" = true,
      "comment" = "Most of the pantheon resides on the Seven Heavens in an area known as the Green Fields",
    }, {
      "name" = "udp3PantheonSheelaConcordant",
      "value" = true,
      "comment" = "Sheela Peryroyl and one or two other deities make their homes on the plane of Concordant Opposition",
    }, {
      "name" = "udp3PantheonBrandobarisRoams",
      "value" = true,
      "comment" = "Brandobaris roams the Prime Material Plane",
    }, {
      "name" = "udp3UrogalanNeutralEarthGod",
      "value" = true,
      "comment" = "The neutral-aligned masculine lesser deity Urogalan is primarily an earth god",
    }, {
      "name" = "udp3UrogalanJudgesDead",
      "value" = true,
      "comment" = "Urogalan sometimes acts as a judge of and protector of the dead",
    }, {
      "name" = "udp3UrogalanOnConcordant",
      "value" = true,
      "comment" = "Urogalan lives on the plane of Concordant Opposition",
    }, {
      "name" = "udp3PantheonPledgedTogether",
      "value" = true,
      "comment" = "All the halfling deities are pledged to work together against the enemies of the halfling people",
    }, {
      "name" = "udp3SheFlowerDressed",
      "value" = true,
      "comment" = "Her appearance is that of a halfling female dressed in wildflowers",
    }, {
      "name" = "udp3SheFieldsGrowWhenSings",
      "value" = true,
      "comment" = "When she sings she causes fields to grow, trees to bud, and seeds to sprout",
    }, {
      "name" = "udp3SheWeatherToFaithful",
      "value" = true,
      "comment" = "She brings good weather to her favored worshipers",
    }, {
      "name" = "udp3SheDroughtFloodsToPoorly",
      "value" = true,
      "comment" = "But she can easily send drought or floods to those who worship her poorly",
    }, {
      "name" = "udp3SheFollowersWearFlower",
      "value" = true,
      "comment" = "Her followers often wear a small flower in her honor",
    }, {
      "name" = "udp3SheFollowersWorkHarmony",
      "value" = true,
      "comment" = "Her followers strive to work in harmony with nature and the earth",
    }, {
      "name" = "udp3SheSeedingFestival",
      "value" = true,
      "comment" = "The planting celebration is called The Seeding or New Spring depending on the region",
    }, {
      "name" = "udp3SheHighHarvestFestival",
      "value" = true,
      "comment" = "The harvest celebration is called High Harvest or The Reaping",
    }, {
      "name" = "udp3SheRevelryAtFestivals",
      "value" = true,
      "comment" = "Community-wide revelry is common at the celebrations, from evening into late night",
    }, {
      "name" = "udp3SheQuestsGrowHarder",
      "value" = true,
      "comment" = "The quests or sacrifices to regain the entangle grant become harder and more costly as time goes on",
    }, {
      "name" = "udp3SheOneEntangleAtATime",
      "value" = true,
      "comment" = "Only one such entangle spell may be had at any one time",
    }, {
      "name" = "udp3SheEntangleCumulative",
      "value" = true,
      "comment" = "Her entangle effects are cumulative if cast several times over the same area",
    }, {
      "name" = "udp3SheConstrictionNoSave",
      "value" = true,
      "comment" = "The successive-entangle constriction damage allows no saving throw and hits movers and non-movers alike",
    }, {
      "name" = "udp3ArvNeverAttacksFirst",
      "value" = true,
      "comment" = "Arvoreen never attacks an opponent first",
    }, {
      "name" = "udp3ArvFirstMagicReflected",
      "value" = true,
      "comment" = "The first magical attack upon him is automatically reflected back upon the caster",
    }, {
      "name" = "udp3ArvInvisibleAtWill",
      "value" = true,
      "comment" = "He can go invisible at will",
    }, {
      "name" = "udp3ArvOnlyFightsIfAttacked",
      "value" = true,
      "comment" = "He will only engage in combat if he is attacked, though he seeks his enemies and actively confronts them",
    }, {
      "name" = "udp3ArvFightsToFinish",
      "value" = true,
      "comment" = "He will not go far out of his way to avoid combat, and will fight to the finish",
    }, {
      "name" = "udp3ArvThievingAgainstEnemies",
      "value" = true,
      "comment" = "Thieving skills employed against enemies to better later combat are permissible to him",
    }, {
      "name" = "udp3ArvNoStealingFromHalflings",
      "value" = true,
      "comment" = "He absolutely forbids stealing from other halflings or allied beings",
    }, {
      "name" = "udp3ArvHeroesObeyImplicitly",
      "value" = true,
      "comment" = "The summoned heroes will obey him implicitly",
    }, {
      "name" = "udp3ArvHeroesSwordAndBow",
      "value" = true,
      "comment" = "Each summoned hero is armed with short sword and short bow",
    }, {
      "name" = "udp3ArvPatronOfFighters",
      "value" = true,
      "comment" = "He is the patron of halfling fighters, the closest thing the halflings have to a god of war",
    }, {
      "name" = "udp3CyrDeityOfFriendship",
      "value" = true,
      "comment" = "Cyrrollalee is the deity of friendship and trust, and a protector like Yondalla",
    }, {
      "name" = "udp3CyrHomeProtectorOpenDwelling",
      "value" = true,
      "comment" = "She protects the home but keeps the inhabitants from being too defensive and closed in",
    }, {
      "name" = "udp3CyrPeasantAppearance",
      "value" = true,
      "comment" = "She appears a normal female halfling with brown hair in simple peasant clothing",
    }, {
      "name" = "udp3CyrEnemyOfTrustBreakers",
      "value" = true,
      "comment" = "Her worst enemies are those who betray the trust of a host, break into halfling homes to steal, or break oaths",
    }, {
      "name" = "udp3CyrAnimationPersists",
      "value" = true,
      "comment" = "The animation effects continue even if Cyrrollalee leaves the area",
    }, {
      "name" = "udp3CyrGiftRequiresService",
      "value" = true,
      "comment" = "Any halfling receiving the furniture gift is obligated to perform a challenging but not exceptionally difficult service afterward",
    }, {
      "name" = "udp3CyrAnyFighterWeapon",
      "value" = true,
      "comment" = "No particular weapons are associated with her, but she can use any weapon a regular fighter could",
    }, {
      "name" = "udp3CyrFollowersPlainHomes",
      "value" = true,
      "comment" = "Her followers are largely regular halflings (0-level characters) and some fighter types",
    }, {
      "name" = "udp3BraSilenceUnhearable",
      "value" = true,
      "comment" = "He moves so silently that no mortal being or god can hear him if he desires concealment",
    }, {
      "name" = "udp3BraHidesExceptTrueSeeing",
      "value" = true,
      "comment" = "He can hide so well as to be completely invisible, detectable only with a true seeing spell or similar item",
    }, {
      "name" = "udp3BraDaggerPointsEscape",
      "value" = true,
      "comment" = "His dagger magically points out the fastest and safest direction of escape from any maze or trap",
    }, {
      "name" = "udp3BraMazeImmuneWithDagger",
      "value" = true,
      "comment" = "He is immune to maze spells when holding his dagger",
    }, {
      "name" = "udp3BraDustBallHarmless",
      "value" = true,
      "comment" = "The dust ball does not harm the victim it strikes",
    }, {
      "name" = "udp3BraTricksterRascal",
      "value" = true,
      "comment" = "He is primarily a clever thief who fools opponents into thinking him harmless, then steals them blind and escapes their wrath",
    }, {
      "name" = "udp3BraMeetsAsFellowThief",
      "value" = true,
      "comment" = "He meets high-level thieves in the guise of another halfling thief and invites them on a thieving adventure",
    }, {
      "name" = "udp3BraIdentityOnlyAfter",
      "value" = true,
      "comment" = "He reveals his identity only after the adventure is over",
    }, {
      "name" = "udp3BraIdentityOnlyToFollowers",
      "value" = true,
      "comment" = "and only to his followers",
    }, {
      "name" = "udp3BraNonWorshippersLoseItems",
      "value" = true,
      "comment" = "Non-worshipping companions might find some of their valuables missing when the adventure is over",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['udp3ProseRound']() != 788  or m['udp3StatblockFeederRound']() != 406  or m['udp3HalflingDeityCount']() != 4  or m['udp3PantheonWorshipMin']() != 4  or m['udp3PantheonWorshipMax']() != 5  or m['udp3GreaterDeityCount']() != 1  or m['udp3SheMajorCelebrations']() != 2  or m['udp3SheFestivalAvgDays']() != 10  or m['udp3SheEntangleGrantPct']() != 1  or m['udp3SheEntangleLevel']() != 6  or m['udp3SheNeutralEntangleLevel']() != 12  or m['udp3SheStaffBonus']() != 4  or m['udp3SheStaffDamageMin']() != 2  or m['udp3SheStaffDamageMax']() != 16  or m['udp3SheStaffCraftSegments']() != 1  or m['udp3SheEntanglePerRound']() != 1  or m['udp3SheDoubleCastSpeedDiv']() != 4  or m['udp3SheSuccessiveDamageMin']() != 1  or m['udp3SheSuccessiveDamageMax']() != 4  or m['udp3ArvFirstAttackDamageDiv']() != 2  or m['udp3ArvUnseenRoundsMin']() != 4  or m['udp3ArvUnseenRoundsMax']() != 16  or m['udp3ArvSwordBonus']() != 4  or m['udp3ArvSummonPerDay']() != 1  or m['udp3ArvSummonMin']() != 10  or m['udp3ArvSummonMax']() != 40  or m['udp3ArvSummonHeroLevel']() != 4  or m['udp3ArvSummonAc']() != 4  or m['udp3ArvSummonHp']() != 25  or m['udp3CyrAnimateRadiusInches']() != 6  or m['udp3CyrAnimateClericLevel']() != 20  or m['udp3CyrAnimateVolumeMax']() != 20  or m['udp3CyrAnimateRounds']() != 20  or m['udp3CyrAnimatePerDay']() != 3  or m['udp3CyrFurnitureChancePct']() != 2  or m['udp3CyrFurnitureVolumeMax']() != 5  or m['udp3CyrFurnitureRounds']() != 5  or m['udp3CyrFurnitureAttacksPerRound']() != 1  or m['udp3CyrGiftLifetimeMax']() != 2  or m['udp3CyrServiceDayOfMonth']() != 1  or m['udp3BraDaggerBonus']() != 3  or m['udp3BraSlingBonus']() != 4  or m['udp3BraDustRangeMaxInches']() != 48  or m['udp3BraDustRangeShortInches']() != 24  or m['udp3BraDustRangeMediumInches']() != 36  or m['udp3BraDustSaveMod']() != -6  or m['udp3BraSleepTurnsMin']() != 6  or m['udp3BraSleepTurnsMax']() != 36  or m['udp3BraRewardChancePct']() != 5  or m['udp3BraRewardLevelMax']() != 10  or m['udp3BraRewardLifetimeMax']() != 1  or m['udp3BraMeetChancePctPerLevel']() != 1  or m['udp3BraMeetLevelMin']() != 11  or  m['udp3PantheonOnlyGoodPowers']() != 1  or  m['udp3YondallaTopAuthority']() != 1  or  m['udp3YondallaFuneralProtector']() != 1  or  m['udp3FemaleDeitiesStronger']() != 1  or  m['udp3GreenFieldsOnSevenHeavens']() != 1  or  m['udp3PantheonSheelaConcordant']() != 1  or  m['udp3PantheonBrandobarisRoams']() != 1  or  m['udp3UrogalanNeutralEarthGod']() != 1  or  m['udp3UrogalanJudgesDead']() != 1  or  m['udp3UrogalanOnConcordant']() != 1  or  m['udp3PantheonPledgedTogether']() != 1  or  m['udp3SheFlowerDressed']() != 1  or  m['udp3SheFieldsGrowWhenSings']() != 1  or  m['udp3SheWeatherToFaithful']() != 1  or  m['udp3SheDroughtFloodsToPoorly']() != 1  or  m['udp3SheFollowersWearFlower']() != 1  or  m['udp3SheFollowersWorkHarmony']() != 1  or  m['udp3SheSeedingFestival']() != 1  or  m['udp3SheHighHarvestFestival']() != 1  or  m['udp3SheRevelryAtFestivals']() != 1  or  m['udp3SheQuestsGrowHarder']() != 1  or  m['udp3SheOneEntangleAtATime']() != 1  or  m['udp3SheEntangleCumulative']() != 1  or  m['udp3SheConstrictionNoSave']() != 1  or  m['udp3ArvNeverAttacksFirst']() != 1  or  m['udp3ArvFirstMagicReflected']() != 1  or  m['udp3ArvInvisibleAtWill']() != 1  or  m['udp3ArvOnlyFightsIfAttacked']() != 1  or  m['udp3ArvFightsToFinish']() != 1  or  m['udp3ArvThievingAgainstEnemies']() != 1  or  m['udp3ArvNoStealingFromHalflings']() != 1  or  m['udp3ArvHeroesObeyImplicitly']() != 1  or  m['udp3ArvHeroesSwordAndBow']() != 1  or  m['udp3ArvPatronOfFighters']() != 1  or  m['udp3CyrDeityOfFriendship']() != 1  or  m['udp3CyrHomeProtectorOpenDwelling']() != 1  or  m['udp3CyrPeasantAppearance']() != 1  or  m['udp3CyrEnemyOfTrustBreakers']() != 1  or  m['udp3CyrAnimationPersists']() != 1  or  m['udp3CyrGiftRequiresService']() != 1  or  m['udp3CyrAnyFighterWeapon']() != 1  or  m['udp3CyrFollowersPlainHomes']() != 1  or  m['udp3BraSilenceUnhearable']() != 1  or  m['udp3BraHidesExceptTrueSeeing']() != 1  or  m['udp3BraDaggerPointsEscape']() != 1  or  m['udp3BraMazeImmuneWithDagger']() != 1  or  m['udp3BraDustBallHarmless']() != 1  or  m['udp3BraTricksterRascal']() != 1  or  m['udp3BraMeetsAsFellowThief']() != 1  or  m['udp3BraIdentityOnlyAfter']() != 1  or  m['udp3BraIdentityOnlyToFollowers']() != 1  or  m['udp3BraNonWorshippersLoseItems']() != 1",
      "note" = "",
    }, {
      "expr" = "m['udp3ProseRound']() != 788  or m['udp3StatblockFeederRound']() != 406  or m['udp3HalflingDeityCount']() != 4  or m['udp3PantheonWorshipMin']() != 4  or m['udp3PantheonWorshipMax']() != 5  or m['udp3GreaterDeityCount']() != 1",
      "note" = "the round consts (the prose round, the feeder round, the census)",
    }, {
      "expr" = "m['udp3PantheonOnlyGoodPowers']() != 1  or m['udp3YondallaTopAuthority']() != 1  or m['udp3YondallaFuneralProtector']() != 1  or m['udp3FemaleDeitiesStronger']() != 1  or m['udp3GreenFieldsOnSevenHeavens']() != 1  or m['udp3PantheonSheelaConcordant']() != 1  or m['udp3PantheonBrandobarisRoams']() != 1  or m['udp3UrogalanNeutralEarthGod']() != 1  or m['udp3UrogalanJudgesDead']() != 1  or m['udp3UrogalanOnConcordant']() != 1  or m['udp3PantheonPledgedTogether']() != 1",
      "note" = "the halfling pantheon prose walk",
    }, {
      "expr" = "m['udp3SheMajorCelebrations']() != 2  or m['udp3SheFestivalAvgDays']() != 10  or m['udp3SheEntangleGrantPct']() != 1  or m['udp3SheEntangleLevel']() != 6  or m['udp3SheNeutralEntangleLevel']() != 12  or m['udp3SheStaffBonus']() != 4  or m['udp3SheStaffDamageMin']() != 2  or m['udp3SheStaffDamageMax']() != 16  or m['udp3SheStaffCraftSegments']() != 1  or m['udp3SheEntanglePerRound']() != 1  or m['udp3SheDoubleCastSpeedDiv']() != 4  or m['udp3SheSuccessiveDamageMin']() != 1  or m['udp3SheSuccessiveDamageMax']() != 4  or m['udp3SheFlowerDressed']() != 1  or m['udp3SheFieldsGrowWhenSings']() != 1  or m['udp3SheWeatherToFaithful']() != 1  or m['udp3SheDroughtFloodsToPoorly']() != 1  or m['udp3SheFollowersWearFlower']() != 1  or m['udp3SheFollowersWorkHarmony']() != 1  or m['udp3SheSeedingFestival']() != 1  or m['udp3SheHighHarvestFestival']() != 1  or m['udp3SheRevelryAtFestivals']() != 1  or m['udp3SheQuestsGrowHarder']() != 1  or m['udp3SheOneEntangleAtATime']() != 1  or m['udp3SheEntangleCumulative']() != 1  or m['udp3SheConstrictionNoSave']() != 1",
      "note" = "the Sheela Peryroyl prose walk",
    }, {
      "expr" = "m['udp3ArvFirstAttackDamageDiv']() != 2  or m['udp3ArvUnseenRoundsMin']() != 4  or m['udp3ArvUnseenRoundsMax']() != 16  or m['udp3ArvSwordBonus']() != 4  or m['udp3ArvSummonPerDay']() != 1  or m['udp3ArvSummonMin']() != 10  or m['udp3ArvSummonMax']() != 40  or m['udp3ArvSummonHeroLevel']() != 4  or m['udp3ArvSummonAc']() != 4  or m['udp3ArvSummonHp']() != 25  or m['udp3ArvNeverAttacksFirst']() != 1  or m['udp3ArvFirstMagicReflected']() != 1  or m['udp3ArvInvisibleAtWill']() != 1  or m['udp3ArvOnlyFightsIfAttacked']() != 1  or m['udp3ArvFightsToFinish']() != 1  or m['udp3ArvThievingAgainstEnemies']() != 1  or m['udp3ArvNoStealingFromHalflings']() != 1  or m['udp3ArvHeroesObeyImplicitly']() != 1  or m['udp3ArvHeroesSwordAndBow']() != 1  or m['udp3ArvPatronOfFighters']() != 1",
      "note" = "the Arvoreen prose walk",
    }, {
      "expr" = "m['udp3CyrAnimateRadiusInches']() != 6  or m['udp3CyrAnimateClericLevel']() != 20  or m['udp3CyrAnimateVolumeMax']() != 20  or m['udp3CyrAnimateRounds']() != 20  or m['udp3CyrAnimatePerDay']() != 3  or m['udp3CyrFurnitureChancePct']() != 2  or m['udp3CyrFurnitureVolumeMax']() != 5  or m['udp3CyrFurnitureRounds']() != 5  or m['udp3CyrFurnitureAttacksPerRound']() != 1  or m['udp3CyrGiftLifetimeMax']() != 2  or m['udp3CyrServiceDayOfMonth']() != 1  or m['udp3CyrDeityOfFriendship']() != 1  or m['udp3CyrHomeProtectorOpenDwelling']() != 1  or m['udp3CyrPeasantAppearance']() != 1  or m['udp3CyrEnemyOfTrustBreakers']() != 1  or m['udp3CyrAnimationPersists']() != 1  or m['udp3CyrGiftRequiresService']() != 1  or m['udp3CyrAnyFighterWeapon']() != 1  or m['udp3CyrFollowersPlainHomes']() != 1",
      "note" = "the Cyrrollalee prose walk",
    }, {
      "expr" = "m['udp3BraDaggerBonus']() != 3  or m['udp3BraSlingBonus']() != 4  or m['udp3BraDustRangeMaxInches']() != 48  or m['udp3BraDustRangeShortInches']() != 24  or m['udp3BraDustRangeMediumInches']() != 36  or m['udp3BraDustSaveMod']() != -6  or m['udp3BraSleepTurnsMin']() != 6  or m['udp3BraSleepTurnsMax']() != 36  or m['udp3BraRewardChancePct']() != 5  or m['udp3BraRewardLevelMax']() != 10  or m['udp3BraRewardLifetimeMax']() != 1  or m['udp3BraMeetChancePctPerLevel']() != 1  or m['udp3BraMeetLevelMin']() != 11  or m['udp3BraSilenceUnhearable']() != 1  or m['udp3BraHidesExceptTrueSeeing']() != 1  or m['udp3BraDaggerPointsEscape']() != 1  or m['udp3BraMazeImmuneWithDagger']() != 1  or m['udp3BraDustBallHarmless']() != 1  or m['udp3BraTricksterRascal']() != 1  or m['udp3BraMeetsAsFellowThief']() != 1  or m['udp3BraIdentityOnlyAfter']() != 1  or m['udp3BraIdentityOnlyToFollowers']() != 1  or m['udp3BraNonWorshippersLoseItems']() != 1",
      "note" = "the Brandobaris prose walk",
    } },
  "audit" = {
      "label" = "R788 halfling deity prose audit",
      "comment" = "THE HALFLING DEITY PROSE - part 3 of the Appendix S description-paragraph close. The archive.org full-text OCR of pp. 116-118 reads the four halfling blocks scan-clean: the Sheela festivals and the entangle craft, the Arvoreen unseen summons of halfling heroes, the Cyrrollalee furniture animation and home trust, and the Brandobaris dust sling, escape dagger, and reward risks. The stat-block numerics stay R406/R783; the paragraph facts ride rules/ua/uadeityprose3.h.",
    },
}
