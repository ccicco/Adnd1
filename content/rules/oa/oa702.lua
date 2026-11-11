-- oa702: promoted from rules/oa/oa73explain.h (the OA EXPLANATION OF DAILY EVENTS, printed capture pp. 247-251 - the daily);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 702,
  "prefix" = "oa702",
  "banner" = {
      "title" = "OA EXPLANATION OF DAILY EVENTS, printed capture pp. 247-251 - the daily",
      "provenance" = "events prose round census 624 -> 625.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE DAILY FRAME: the daily events the most common encounter, the providers of much of the action, up to three events in a single day by location. THE TWENTY-NINE EXPLAINED: the Bandits (the 2d10 camp-edge count, the two brethren to the main camp, the 3d10 mounted scouts who avoid the fight and may pose as travelers); the Bandit Camp (per the Monster Manual); the Becalmed (the ships rowed); the Contest (the noble station, the judged formal party, the two honor points lost); the Crime (the adventure seed); the Duel (the shukenja exempt); the Entreaty (the pay or the bribe); the Fire small (the 70% arson, the home building, the 70% spread); the Haunting (the see-monthly); the Illness (the 20/80 target, the 2d6 course, the worse-untreated, the save versus death, the rest rule); the Insult (the court complaint, the long-term enemy); the Invitation (the refusal the insult); the Kidnapping (the lovers guise); the Land (the uncharted danger); the Monster (the table roll); the Mystery (the 60% investigation); the Nobles (the 2d10 bushi, the 1d6 samurai, the 1-3 of rank, the 80/20 open and disguised, the palanquins); the Pirates (the 1-3 wako ships); the Plot (the adventure basis); the Ruins (the 01-10 temple at 70%, the 11-60 farmhouse at 20%, the 61-90 shrine at 50%, the 91-100 stockade at 30%); the Ship (the 30% ghost ferrying the dead, the 50% merchant, the 20% warship, the 10% gajin crew); the Shrine (the 10% bless for 24 hours, the 80% curse); the Special (the mission start); the Storm (the 5d6 hours, the 1-2 per hour, the no-travel day, the desert sandstorm); the Stranger (the 30% ordinary with the seven 10s, the travels along); the Traveler (the DM devises); the VIP (the 20d6 bushi, the 10d4 samurai, the announced arrival, the impudent cut down). THE OCR REPAIR: the merchant misprint 509-6 read as 50 per the roll band. The prose codifies per the R431 calculus  the gap census after this round: 155 closed, 80 open - the Daily Events prose box flips (census 624 -> 625); NEXT - R703: the Chapter 11 terrain encounter tables (capture pp. 251-261), prefix djq (verify free at the landing), audit \"R703 OA terrain encounter tables audit\", include after rules/oa/oa73explain.h",
    },
  "consts" = { {
      "name" = "djpDailyEventsMaxPerDay",
      "value" = 3,
      "comment" = "the daily frame - up to three events in a single day, the count by the PCs location (print capture p. 247)",
    }, {
      "name" = "djpBanditsCampDice",
      "value" = 2,
      "comment" = "the Bandits camp-edge count - 2d10 bandits present at the camp or outpost (print capture p. 248)",
    }, {
      "name" = "djpBanditsCampDie",
      "value" = 10,
      "comment" = "the Bandits camp-edge die - the d10 of the 2d10 bandits present (print capture p. 248)",
    }, {
      "name" = "djpBanditsWarnersCount",
      "value" = 2,
      "comment" = "the Bandits warners - two of their brethren return to the main camp for help while the rest delay the party (print capture p. 248)",
    }, {
      "name" = "djpBanditsScoutDice",
      "value" = 3,
      "comment" = "the Bandits advance group count - 3d10 mounted bandits when none are active in the area (print capture p. 248)",
    }, {
      "name" = "djpBanditsScoutDie",
      "value" = 10,
      "comment" = "the Bandits advance group die - the d10 of the 3d10 mounted scouts (print capture p. 248)",
    }, {
      "name" = "djpContestHonorLost",
      "value" = 2,
      "comment" = "the Contest refusal penalty - two points of honor lost for skipping without good reason (print capture p. 248)",
    }, {
      "name" = "djpFireSmallIntentionalPct",
      "value" = 70,
      "comment" = "the Fire small arson chance - the fire intentionally set 70% of the time, by an enemy, distracting ninjas, or a malicious spirit (print capture p. 249)",
    }, {
      "name" = "djpFireSmallSpreadPct",
      "value" = 70,
      "comment" = "the Fire small spread chance - an out-of-control fire ignites nearby buildings 70% of the time (print capture p. 249)",
    }, {
      "name" = "djpIllnessPCTargetPct",
      "value" = 20,
      "comment" = "the Illness target - the disease strikes a player character 20% of the time (print capture p. 249)",
    }, {
      "name" = "djpIllnessNPCTargetPct",
      "value" = 80,
      "comment" = "the Illness target - the disease strikes a known NPC 80% of the time (print capture p. 249)",
    }, {
      "name" = "djpIllnessCourseDice",
      "value" = 2,
      "comment" = "the Illness course - 2d6 days for the disease to run its course, rolled by the DM (print capture p. 249)",
    }, {
      "name" = "djpIllnessCourseDie",
      "value" = 6,
      "comment" = "the Illness course - the d6 of the 2d6 days (print capture p. 249)",
    }, {
      "name" = "djpIllnessRestPerIllDay",
      "value" = 1,
      "comment" = "the Illness recovery - one day of rest required for every day spent ill (print capture p. 249)",
    }, {
      "name" = "djpMysteryInvestigatePct",
      "value" = 60,
      "comment" = "the Mystery hook - a 60% chance the party is asked to investigate the strange event (print capture p. 249)",
    }, {
      "name" = "djpNoblesBushiDice",
      "value" = 2,
      "comment" = "the Nobles party - 2d10 bushi in the noble party (print capture p. 249)",
    }, {
      "name" = "djpNoblesBushiDie",
      "value" = 10,
      "comment" = "the Nobles party - the d10 of the 2d10 bushi (print capture p. 249)",
    }, {
      "name" = "djpNoblesSamuraiDie",
      "value" = 6,
      "comment" = "the Nobles party - 1d6 samurai (print capture p. 249)",
    }, {
      "name" = "djpNoblesRanksMin",
      "value" = 1,
      "comment" = "the Nobles party - the minimum of the 1-3 persons of rank (print capture p. 249)",
    }, {
      "name" = "djpNoblesRanksMax",
      "value" = 3,
      "comment" = "the Nobles party - the maximum of the 1-3 persons of rank (print capture p. 249)",
    }, {
      "name" = "djpNoblesOpenlyPct",
      "value" = 80,
      "comment" = "the Nobles travel - openly 80% of the time, expecting the respect due their station (print capture pp. 249-250)",
    }, {
      "name" = "djpNoblesDisguisePct",
      "value" = 20,
      "comment" = "the Nobles travel - in disguise the other 20%, on a secret mission or fleeing an enemy (print capture p. 250)",
    }, {
      "name" = "djpPiratesShipsMin",
      "value" = 1,
      "comment" = "the Pirates sighting - the minimum of the 1-3 wako ships sighted (print capture p. 250)",
    }, {
      "name" = "djpPiratesShipsMax",
      "value" = 3,
      "comment" = "the Pirates sighting - the maximum of the 1-3 wako ships sighted (print capture p. 250)",
    }, {
      "name" = "djpRuinTempleMin",
      "value" = 1,
      "comment" = "the Ruins type roll - the temple compound begins at 01 (print capture p. 250)",
    }, {
      "name" = "djpRuinTempleMax",
      "value" = 10,
      "comment" = "the Ruins type roll - the temple compound ends at 10 (print capture p. 250)",
    }, {
      "name" = "djpRuinTempleHauntedPct",
      "value" = 70,
      "comment" = "the Ruins haunt chance - the temple compound haunted or inhabited 70% (print capture p. 250)",
    }, {
      "name" = "djpRuinFarmhouseMin",
      "value" = 11,
      "comment" = "the Ruins type roll - the farmhouse begins at 11 (print capture p. 250)",
    }, {
      "name" = "djpRuinFarmhouseMax",
      "value" = 60,
      "comment" = "the Ruins type roll - the farmhouse ends at 60 (print capture p. 250)",
    }, {
      "name" = "djpRuinFarmhouseHauntedPct",
      "value" = 20,
      "comment" = "the Ruins haunt chance - the farmhouse haunted or inhabited 20% (print capture p. 250)",
    }, {
      "name" = "djpRuinShrineMin",
      "value" = 61,
      "comment" = "the Ruins type roll - the shrine begins at 61 (print capture p. 250)",
    }, {
      "name" = "djpRuinShrineMax",
      "value" = 90,
      "comment" = "the Ruins type roll - the shrine ends at 90 (print capture p. 250)",
    }, {
      "name" = "djpRuinShrineHauntedPct",
      "value" = 50,
      "comment" = "the Ruins haunt chance - the shrine haunted or inhabited 50% (print capture p. 250)",
    }, {
      "name" = "djpRuinStockadeMin",
      "value" = 91,
      "comment" = "the Ruins type roll - the military stockade begins at 91 (print capture p. 250)",
    }, {
      "name" = "djpRuinStockadeMax",
      "value" = 100,
      "comment" = "the Ruins type roll - the military stockade ends at 100 (print capture p. 250)",
    }, {
      "name" = "djpRuinStockadeHauntedPct",
      "value" = 30,
      "comment" = "the Ruins haunt chance - the military stockade haunted or inhabited 30% (print capture p. 250)",
    }, {
      "name" = "djpShipGhostPct",
      "value" = 30,
      "comment" = "the Ship sighting - a 30% chance the sail is a ghost ship ferrying the dead (print capture p. 250)",
    }, {
      "name" = "djpShipMerchantPct",
      "value" = 50,
      "comment" = "the Ship sighting - the vessel a merchant ship 50% (the OCR misprint 509-6 repaired per the roll band, print capture p. 250)",
    }, {
      "name" = "djpShipWarPct",
      "value" = 20,
      "comment" = "the Ship sighting - the vessel a warship 20% (print capture p. 250)",
    }, {
      "name" = "djpShipGajinPct",
      "value" = 10,
      "comment" = "the Ship sighting - the merchant or warship crewed by gajin 10% of the time (print capture p. 250)",
    }, {
      "name" = "djpShrineBlessPct",
      "value" = 10,
      "comment" = "the Shrine blessing - a 10% chance the offerings earn a bless for the next 24 hours (print capture p. 250)",
    }, {
      "name" = "djpShrineBlessHours",
      "value" = 24,
      "comment" = "the Shrine blessing - the bless spell lasts the next 24 hours (print capture p. 250)",
    }, {
      "name" = "djpShrineCursePct",
      "value" = 80,
      "comment" = "the Shrine curse - damage or disrespect earns a DM-devised curse 80% of the time (print capture p. 250)",
    }, {
      "name" = "djpStormHoursDice",
      "value" = 5,
      "comment" = "the Storm duration - 5d6 hours of gale, rain, and crashing waves at sea (print capture p. 250)",
    }, {
      "name" = "djpStormHoursDie",
      "value" = 6,
      "comment" = "the Storm duration - the d6 of the 5d6 hours (print capture p. 250)",
    }, {
      "name" = "djpStormExhaustMin",
      "value" = 1,
      "comment" = "the Storm exposure - the minimum of the 1-2 points of damage per hour outside (print capture p. 250)",
    }, {
      "name" = "djpStormExhaustMax",
      "value" = 2,
      "comment" = "the Storm exposure - the maximum of the 1-2 points of damage per hour outside (print capture p. 250)",
    }, {
      "name" = "djpStrangerOrdinaryPct",
      "value" = 30,
      "comment" = "the Stranger identity - an ordinary traveler 30% of the time (print capture p. 250)",
    }, {
      "name" = "djpStrangerSocietyPct",
      "value" = 10,
      "comment" = "the Stranger identity - a member of a secret society 10% (print capture p. 250)",
    }, {
      "name" = "djpStrangerPolicePct",
      "value" = 10,
      "comment" = "the Stranger identity - an official of the secret police 10% (print capture p. 250)",
    }, {
      "name" = "djpStrangerNinjaPct",
      "value" = 10,
      "comment" = "the Stranger identity - a ninja on a mission 10% (print capture p. 250)",
    }, {
      "name" = "djpStrangerNoblePct",
      "value" = 10,
      "comment" = "the Stranger identity - a noble traveling in disguise 10% (print capture p. 250)",
    }, {
      "name" = "djpStrangerBanditPct",
      "value" = 10,
      "comment" = "the Stranger identity - a bandit using the party as cover 10% (print capture p. 250)",
    }, {
      "name" = "djpStrangerHengeyokaiPct",
      "value" = 10,
      "comment" = "the Stranger identity - a hengeyokai or spirit in human form 10% (print capture p. 250)",
    }, {
      "name" = "djpStrangerYakuzaPct",
      "value" = 10,
      "comment" = "the Stranger identity - a yakuza subtly seeking information 10% (print capture p. 250)",
    }, {
      "name" = "djpVIPBushiDice",
      "value" = 20,
      "comment" = "the VIP entourage - 20d6 bushi in advance of him (print capture p. 250)",
    }, {
      "name" = "djpVIPBushiDie",
      "value" = 6,
      "comment" = "the VIP entourage - the d6 of the 20d6 bushi (print capture p. 250)",
    }, {
      "name" = "djpVIPSamuraiDice",
      "value" = 10,
      "comment" = "the VIP entourage - 10d4 samurai in advance of him (print capture p. 250)",
    }, {
      "name" = "djpVIPSamuraiDie",
      "value" = 4,
      "comment" = "the VIP entourage - the d4 of the 10d4 samurai (print capture p. 250)",
    } },
  "bools" = { {
      "name" = "djpDailyEventsProvideTheAction",
      "value" = true,
      "comment" = "the daily frame - the daily events provide much of the action for the player characters, the creatures and the special summons (print capture p. 247)",
    }, {
      "name" = "djpBanditsDelayWhileWarned",
      "value" = true,
      "comment" = "the Bandits tactic - they delay or waylay the party while the two brethren go for help (print capture p. 248)",
    }, {
      "name" = "djpBanditsScoutsAvoidFight",
      "value" = true,
      "comment" = "the Bandits advance group - the mounted scouts avoid a fight when possible (print capture p. 248)",
    }, {
      "name" = "djpBanditsPoseAsTravelers",
      "value" = true,
      "comment" = "the Bandits advance group - they may pass themselves off as travelers (print capture p. 248)",
    }, {
      "name" = "djpBecalmedRowedThatDay",
      "value" = true,
      "comment" = "the Becalmed effect - ships cannot sail that day and must be rowed (print capture p. 248)",
    }, {
      "name" = "djpContestNobleStationOnly",
      "value" = true,
      "comment" = "the Contest - only player characters of noble station receive the invitation (print capture p. 248)",
    }, {
      "name" = "djpContestFormalParty",
      "value" = true,
      "comment" = "the Contest - held as a formal party, each guest composing a work judged on quality, appropriateness, imagery, and beauty (print capture p. 248)",
    }, {
      "name" = "djpContestExcusedForGoodReason",
      "value" = true,
      "comment" = "the Contest - it can be missed for a good reason such as leaving town at ones lords orders (print capture p. 248)",
    }, {
      "name" = "djpCrimeAdventureSeed",
      "value" = true,
      "comment" = "the Crime - an encounter usable as the basis for the beginning of an adventure (print capture p. 248)",
    }, {
      "name" = "djpDuelShukenjaExempt",
      "value" = true,
      "comment" = "the Duel - shukenja are never normally challenged (print capture p. 248)",
    }, {
      "name" = "djpEntreatyPayOrBribed",
      "value" = true,
      "comment" = "the Entreaty - the noble or the commoners willing to pay or even bribe the party (print capture p. 249)",
    }, {
      "name" = "djpFireSmallHomeBuilding",
      "value" = true,
      "comment" = "the Fire small - if it occurs while the party is at home, one of their own buildings is on fire (print capture p. 249)",
    }, {
      "name" = "djpHauntingSeeMonthly",
      "value" = true,
      "comment" = "the Haunting - see Haunting in the monthly events (print capture p. 249)",
    }, {
      "name" = "djpIllnessWorseUntreated",
      "value" = true,
      "comment" = "the Illness - each day untreated the sick person grows worse, fevers, sweating, dizziness, weakness (print capture p. 249)",
    }, {
      "name" = "djpIllnessSaveVsDeath",
      "value" = true,
      "comment" = "the Illness - a saving throw versus death at the end of the course if uncured, failure kills (print capture p. 249)",
    }, {
      "name" = "djpInsultCourtComplaint",
      "value" = true,
      "comment" = "the Insult - at a court the aggrieved presents his complaint to the ruling lord (print capture p. 249)",
    }, {
      "name" = "djpInsultLongTermEnemy",
      "value" = true,
      "comment" = "the Insult - inadequate punishment or a lower-standing aggrieved leaves a long-term enemy (print capture p. 249)",
    }, {
      "name" = "djpInvitationRefusalIsInsult",
      "value" = true,
      "comment" = "the Invitation - to refuse without justifiable reason is cause for an insult (print capture p. 249)",
    }, {
      "name" = "djpKidnapLoversGuisePossible",
      "value" = true,
      "comment" = "the Kidnapping - it may be a pair of lovers secretly run away under the guise of a kidnapping (print capture p. 249)",
    }, {
      "name" = "djpLandUnchartedDangerous",
      "value" = true,
      "comment" = "the Land - uncharted islands filled with unusual and dangerous creatures (print capture p. 249)",
    }, {
      "name" = "djpMonsterRollEncounterTable",
      "value" = true,
      "comment" = "the Monster - roll on the appropriate monster table to determine the encounter (print capture p. 249)",
    }, {
      "name" = "djpNoblesPalanquinsOnFoot",
      "value" = true,
      "comment" = "the Nobles - traveling on foot with the nobles carried in palanquins (print capture p. 249)",
    }, {
      "name" = "djpPiratesSeeWakoDescription",
      "value" = true,
      "comment" = "the Pirates - see the description of Men, Wako in this rulebook (print capture p. 250)",
    }, {
      "name" = "djpPlotAdventureBasis",
      "value" = true,
      "comment" = "the Plot - the wind of a plot usable as the basis for a player character adventure (print capture p. 250)",
    }, {
      "name" = "djpRuinsHauntedChanceInParens",
      "value" = true,
      "comment" = "the Ruins - the parenthesized chance the ruin is haunted by a spirit or inhabited by a monster (print capture p. 250)",
    }, {
      "name" = "djpShipGhostFerriesTheDead",
      "value" = true,
      "comment" = "the Ship - the ghost ship ferries the dead to their new land (print capture p. 250)",
    }, {
      "name" = "djpShrineOfferingsRequired",
      "value" = true,
      "comment" = "the Shrine - the blessing only if they stop and make appropriate offerings (print capture p. 250)",
    }, {
      "name" = "djpSpecialAdventureStart",
      "value" = true,
      "comment" = "the Special - the mission from lord, mentor, or family head is the starting point of an adventure (print capture p. 250)",
    }, {
      "name" = "djpStormNoTravelThatDay",
      "value" = true,
      "comment" = "the Storm - the characters are unable to travel that day, drifting, flooding, or sand dunes (print capture p. 250)",
    }, {
      "name" = "djpStormDesertSandstorm",
      "value" = true,
      "comment" = "the Storm - in deserts it is a sandstorm (print capture p. 250)",
    }, {
      "name" = "djpStrangerTravelsAlong",
      "value" = true,
      "comment" = "the Stranger - he goes the same direction and wants to travel with the party for company and safety (print capture p. 250)",
    }, {
      "name" = "djpTravelerDMDevises",
      "value" = true,
      "comment" = "the Traveler - the DM devises whatever he desires for this encounter (print capture p. 250)",
    }, {
      "name" = "djpVIPArrivalAnnounced",
      "value" = true,
      "comment" = "the VIP - no attempt to hide the arrival, the title announced in the streets (print capture p. 250)",
    }, {
      "name" = "djpVIPImpudentCutDown",
      "value" = true,
      "comment" = "the VIP - any impudent enough to challenge the entourage are cut down on the spot (print capture p. 251)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djpDailyEventsMaxPerDay']() != 3  or m['djpBanditsCampDice']() != 2  or m['djpBanditsCampDie']() != 10  or m['djpBanditsWarnersCount']() != 2  or m['djpBanditsScoutDice']() != 3  or m['djpBanditsScoutDie']() != 10  or m['djpContestHonorLost']() != 2  or m['djpFireSmallIntentionalPct']() != 70  or m['djpFireSmallSpreadPct']() != 70  or m['djpIllnessPCTargetPct']() != 20  or m['djpIllnessNPCTargetPct']() != 80  or m['djpIllnessCourseDice']() != 2  or m['djpIllnessCourseDie']() != 6  or m['djpIllnessRestPerIllDay']() != 1  or m['djpMysteryInvestigatePct']() != 60  or m['djpNoblesBushiDice']() != 2  or m['djpNoblesBushiDie']() != 10  or m['djpNoblesSamuraiDie']() != 6  or m['djpNoblesRanksMin']() != 1  or m['djpNoblesRanksMax']() != 3  or m['djpNoblesOpenlyPct']() != 80  or m['djpNoblesDisguisePct']() != 20  or m['djpPiratesShipsMin']() != 1  or m['djpPiratesShipsMax']() != 3  or m['djpRuinTempleMin']() != 1  or m['djpRuinTempleMax']() != 10  or m['djpRuinTempleHauntedPct']() != 70  or m['djpRuinFarmhouseMin']() != 11  or m['djpRuinFarmhouseMax']() != 60  or m['djpRuinFarmhouseHauntedPct']() != 20  or m['djpRuinShrineMin']() != 61  or m['djpRuinShrineMax']() != 90  or m['djpRuinShrineHauntedPct']() != 50  or m['djpRuinStockadeMin']() != 91  or m['djpRuinStockadeMax']() != 100  or m['djpRuinStockadeHauntedPct']() != 30  or m['djpShipGhostPct']() != 30  or m['djpShipMerchantPct']() != 50  or m['djpShipWarPct']() != 20  or m['djpShipGajinPct']() != 10  or m['djpShrineBlessPct']() != 10  or m['djpShrineBlessHours']() != 24  or m['djpShrineCursePct']() != 80  or m['djpStormHoursDice']() != 5  or m['djpStormHoursDie']() != 6  or m['djpStormExhaustMin']() != 1  or m['djpStormExhaustMax']() != 2  or m['djpStrangerOrdinaryPct']() != 30  or m['djpStrangerSocietyPct']() != 10  or m['djpStrangerPolicePct']() != 10  or m['djpStrangerNinjaPct']() != 10  or m['djpStrangerNoblePct']() != 10  or m['djpStrangerBanditPct']() != 10  or m['djpStrangerHengeyokaiPct']() != 10  or m['djpStrangerYakuzaPct']() != 10  or m['djpVIPBushiDice']() != 20  or m['djpVIPBushiDie']() != 6  or m['djpVIPSamuraiDice']() != 10  or m['djpVIPSamuraiDie']() != 4  or  m['djpDailyEventsProvideTheAction']() != 1  or  m['djpBanditsDelayWhileWarned']() != 1  or  m['djpBanditsScoutsAvoidFight']() != 1  or  m['djpBanditsPoseAsTravelers']() != 1  or  m['djpBecalmedRowedThatDay']() != 1  or  m['djpContestNobleStationOnly']() != 1  or  m['djpContestFormalParty']() != 1  or  m['djpContestExcusedForGoodReason']() != 1  or  m['djpCrimeAdventureSeed']() != 1  or  m['djpDuelShukenjaExempt']() != 1  or  m['djpEntreatyPayOrBribed']() != 1  or  m['djpFireSmallHomeBuilding']() != 1  or  m['djpHauntingSeeMonthly']() != 1  or  m['djpIllnessWorseUntreated']() != 1  or  m['djpIllnessSaveVsDeath']() != 1  or  m['djpInsultCourtComplaint']() != 1  or  m['djpInsultLongTermEnemy']() != 1  or  m['djpInvitationRefusalIsInsult']() != 1  or  m['djpKidnapLoversGuisePossible']() != 1  or  m['djpLandUnchartedDangerous']() != 1  or  m['djpMonsterRollEncounterTable']() != 1  or  m['djpNoblesPalanquinsOnFoot']() != 1  or  m['djpPiratesSeeWakoDescription']() != 1  or  m['djpPlotAdventureBasis']() != 1  or  m['djpRuinsHauntedChanceInParens']() != 1  or  m['djpShipGhostFerriesTheDead']() != 1  or  m['djpShrineOfferingsRequired']() != 1  or  m['djpSpecialAdventureStart']() != 1  or  m['djpStormNoTravelThatDay']() != 1  or  m['djpStormDesertSandstorm']() != 1  or  m['djpStrangerTravelsAlong']() != 1  or  m['djpTravelerDMDevises']() != 1  or  m['djpVIPArrivalAnnounced']() != 1  or  m['djpVIPImpudentCutDown']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djpDailyEventsMaxPerDay']() != 3  or m['djpDailyEventsProvideTheAction']() != 1  or m['djpBanditsCampDice']() != 2  or m['djpBanditsCampDie']() != 10  or m['djpBanditsWarnersCount']() != 2  or m['djpBanditsScoutDice']() != 3  or m['djpBanditsScoutDie']() != 10  or m['djpBanditsDelayWhileWarned']() != 1  or m['djpBanditsScoutsAvoidFight']() != 1  or m['djpBanditsPoseAsTravelers']() != 1  or m['djpBecalmedRowedThatDay']() != 1",
      "note" = "the daily frame and the Bandits - the three events, the 2d10 camp-edge count with the two warners, the 3d10 mounted scouts avoiding the fight, the becalmed rowing",
    }, {
      "expr" = "m['djpContestHonorLost']() != 2  or m['djpContestNobleStationOnly']() != 1  or m['djpContestFormalParty']() != 1  or m['djpContestExcusedForGoodReason']() != 1  or m['djpCrimeAdventureSeed']() != 1  or m['djpDuelShukenjaExempt']() != 1",
      "note" = "the Contest and the Crime and the Duel - the two honor points lost, the noble station, the judged formal party, the excused absence, the adventure seed, the shukenja exempt",
    }, {
      "expr" = "m['djpEntreatyPayOrBribed']() != 1  or m['djpFireSmallIntentionalPct']() != 70  or m['djpFireSmallHomeBuilding']() != 1  or m['djpFireSmallSpreadPct']() != 70  or m['djpHauntingSeeMonthly']() != 1",
      "note" = "the Entreaty and the Fire and the Haunting - the pay or bribe, the 70% arson, the home building, the 70% spread, the see-monthly haunting",
    }, {
      "expr" = "m['djpIllnessPCTargetPct']() != 20  or m['djpIllnessNPCTargetPct']() != 80  or m['djpIllnessCourseDice']() != 2  or m['djpIllnessCourseDie']() != 6  or m['djpIllnessRestPerIllDay']() != 1  or m['djpIllnessWorseUntreated']() != 1  or m['djpIllnessSaveVsDeath']() != 1  or m['djpInsultCourtComplaint']() != 1  or m['djpInsultLongTermEnemy']() != 1  or m['djpInvitationRefusalIsInsult']() != 1",
      "note" = "the Illness and the Insult and the Invitation - the 20/80 target, the 2d6 course, the rest rule, the save at the end, the court complaint, the long-term enemy, the refusal insult",
    }, {
      "expr" = "m['djpKidnapLoversGuisePossible']() != 1  or m['djpLandUnchartedDangerous']() != 1  or m['djpMonsterRollEncounterTable']() != 1  or m['djpMysteryInvestigatePct']() != 60",
      "note" = "the Kidnapping and the Land and the Monster and the Mystery - the lovers guise, the uncharted danger, the table roll, the 60% investigation",
    }, {
      "expr" = "m['djpNoblesBushiDice']() != 2  or m['djpNoblesBushiDie']() != 10  or m['djpNoblesSamuraiDie']() != 6  or m['djpNoblesRanksMin']() != 1  or m['djpNoblesRanksMax']() != 3  or m['djpNoblesOpenlyPct']() != 80  or m['djpNoblesDisguisePct']() != 20  or m['djpNoblesPalanquinsOnFoot']() != 1  or m['djpPiratesShipsMin']() != 1  or m['djpPiratesShipsMax']() != 3  or m['djpPiratesSeeWakoDescription']() != 1",
      "note" = "the Nobles and the Pirates - the 2d10 bushi, the 1d6 samurai, the 1-3 of rank, the 80/20 open and disguised, the palanquins, the 1-3 wako ships",
    }, {
      "expr" = "m['djpPlotAdventureBasis']() != 1  or m['djpRuinsHauntedChanceInParens']() != 1  or m['djpRuinTempleMin']() != 1  or m['djpRuinTempleMax']() != 10  or m['djpRuinTempleHauntedPct']() != 70  or m['djpRuinFarmhouseMin']() != 11  or m['djpRuinFarmhouseMax']() != 60  or m['djpRuinFarmhouseHauntedPct']() != 20  or m['djpRuinShrineMin']() != 61  or m['djpRuinShrineMax']() != 90  or m['djpRuinShrineHauntedPct']() != 50  or m['djpRuinStockadeMin']() != 91  or m['djpRuinStockadeMax']() != 100  or m['djpRuinStockadeHauntedPct']() != 30",
      "note" = "the Plot and the Ruins - the adventure basis, the 01-10 temple at 70%, the 11-60 farmhouse at 20%, the 61-90 shrine at 50%, the 91-100 stockade at 30%, the parenthesized haunt chance",
    }, {
      "expr" = "m['djpShipGhostPct']() != 30  or m['djpShipGhostFerriesTheDead']() != 1  or m['djpShipMerchantPct']() != 50  or m['djpShipWarPct']() != 20  or m['djpShipGajinPct']() != 10  or m['djpShrineBlessPct']() != 10  or m['djpShrineBlessHours']() != 24  or m['djpShrineCursePct']() != 80  or m['djpShrineOfferingsRequired']() != 1  or m['djpSpecialAdventureStart']() != 1",
      "note" = "the Ship and the Shrine and the Special - the 30% ghost ferrying the dead, the 50% merchant (the OCR misprint repaired), the 20% warship, the 10% gajin crew, the 10% bless for 24 hours, the 80% curse, the mission start",
    }, {
      "expr" = "m['djpStormHoursDice']() != 5  or m['djpStormHoursDie']() != 6  or m['djpStormExhaustMin']() != 1  or m['djpStormExhaustMax']() != 2  or m['djpStormNoTravelThatDay']() != 1  or m['djpStormDesertSandstorm']() != 1  or m['djpStrangerOrdinaryPct']() != 30  or m['djpStrangerSocietyPct']() != 10  or m['djpStrangerPolicePct']() != 10  or m['djpStrangerNinjaPct']() != 10  or m['djpStrangerNoblePct']() != 10  or m['djpStrangerBanditPct']() != 10  or m['djpStrangerHengeyokaiPct']() != 10  or m['djpStrangerYakuzaPct']() != 10  or m['djpStrangerTravelsAlong']() != 1",
      "note" = "the Storm and the Stranger - the 5d6 hours, the 1-2 per hour, the no-travel day, the desert sandstorm, the 30% ordinary with the seven 10s, the travels-along",
    }, {
      "expr" = "m['djpTravelerDMDevises']() != 1  or m['djpVIPBushiDice']() != 20  or m['djpVIPBushiDie']() != 6  or m['djpVIPSamuraiDice']() != 10  or m['djpVIPSamuraiDie']() != 4  or m['djpVIPArrivalAnnounced']() != 1  or m['djpVIPImpudentCutDown']() != 1",
      "note" = "the Traveler and the VIP - the DM devises, the 20d6 bushi, the 10d4 samurai, the announced arrival, the impudent cut down",
    } },
  "audit" = {
      "label" = "R702 OA daily events prose audit",
      "comment" = "OA round eighty-nine (capture pp. 247-251): the Explanation of Daily Events - the twenty-nine events of Table 73 explained in prose, the dice, the percentages, and the consequences, plus the daily frame and the ruins type bands, single-pass pins per the Chapter 9 provenance shift",
    },
}
