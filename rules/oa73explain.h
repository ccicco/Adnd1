// =========================================================================================
// Adnd1 - rules/oa73explain.h
// OA EXPLANATION OF DAILY EVENTS, printed capture pp. 247-251 - the daily
// events prose round
// census 624 -> 625.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE DAILY FRAME: the daily events the most common
// encounter, the providers of much of the action, up to three events in a
// single day by location. THE TWENTY-NINE EXPLAINED: the Bandits (the 2d10
// camp-edge count, the two brethren to the main camp, the 3d10 mounted scouts
// who avoid the fight and may pose as travelers); the Bandit Camp (per the
// Monster Manual); the Becalmed (the ships rowed); the Contest (the noble
// station, the judged formal party, the two honor points lost); the Crime
// (the adventure seed); the Duel (the shukenja exempt); the Entreaty (the pay
// or the bribe); the Fire small (the 70% arson, the home building, the 70%
// spread); the Haunting (the see-monthly); the Illness (the 20/80 target, the
// 2d6 course, the worse-untreated, the save versus death, the rest rule); the
// Insult (the court complaint, the long-term enemy); the Invitation (the
// refusal the insult); the Kidnapping (the lovers guise); the Land (the
// uncharted danger); the Monster (the table roll); the Mystery (the 60%
// investigation); the Nobles (the 2d10 bushi, the 1d6 samurai, the 1-3 of
// rank, the 80/20 open and disguised, the palanquins); the Pirates (the 1-3
// wako ships); the Plot (the adventure basis); the Ruins (the 01-10 temple at
// 70%, the 11-60 farmhouse at 20%, the 61-90 shrine at 50%, the 91-100
// stockade at 30%); the Ship (the 30% ghost ferrying the dead, the 50%
// merchant, the 20% warship, the 10% gajin crew); the Shrine (the 10% bless
// for 24 hours, the 80% curse); the Special (the mission start); the Storm
// (the 5d6 hours, the 1-2 per hour, the no-travel day, the desert sandstorm);
// the Stranger (the 30% ordinary with the seven 10s, the travels along); the
// Traveler (the DM devises); the VIP (the 20d6 bushi, the 10d4 samurai, the
// announced arrival, the impudent cut down). THE OCR REPAIR: the merchant
// misprint 509-6 read as 50 per the roll band. The prose codifies per the
// R431 calculus
//
// the gap census after this round: 155 closed, 80 open - the Daily Events
// prose box flips (census 624 -> 625); NEXT - R703: the Chapter 11 terrain
// encounter tables (capture pp. 251-261), prefix djq (verify free at the
// landing), audit "R703 OA terrain encounter tables audit", include after
// rules/oa73explain.h
//
namespace rules {

// ---- the daily frame, the Bandits and the Becalmed ----

// the daily frame - up to three events in a single day, the count by the PCs
// location (print capture p. 247)
inline int djpDailyEventsMaxPerDay()
    { return 3; }

// the daily frame - the daily events provide much of the action for the
// player characters, the creatures and the special summons (print capture p.
// 247)
inline bool djpDailyEventsProvideTheAction()
    { return true; }

// the Bandits camp-edge count - 2d10 bandits present at the camp or outpost
// (print capture p. 248)
inline int djpBanditsCampDice()
    { return 2; }

// the Bandits camp-edge die - the d10 of the 2d10 bandits present (print
// capture p. 248)
inline int djpBanditsCampDie()
    { return 10; }

// the Bandits warners - two of their brethren return to the main camp for
// help while the rest delay the party (print capture p. 248)
inline int djpBanditsWarnersCount()
    { return 2; }

// the Bandits advance group count - 3d10 mounted bandits when none are active
// in the area (print capture p. 248)
inline int djpBanditsScoutDice()
    { return 3; }

// the Bandits advance group die - the d10 of the 3d10 mounted scouts (print
// capture p. 248)
inline int djpBanditsScoutDie()
    { return 10; }

// the Bandits tactic - they delay or waylay the party while the two brethren
// go for help (print capture p. 248)
inline bool djpBanditsDelayWhileWarned()
    { return true; }

// the Bandits advance group - the mounted scouts avoid a fight when possible
// (print capture p. 248)
inline bool djpBanditsScoutsAvoidFight()
    { return true; }

// the Bandits advance group - they may pass themselves off as travelers
// (print capture p. 248)
inline bool djpBanditsPoseAsTravelers()
    { return true; }

// the Becalmed effect - ships cannot sail that day and must be rowed (print
// capture p. 248)
inline bool djpBecalmedRowedThatDay()
    { return true; }

// ---- the Contest, the Crime and the Duel ----

// the Contest refusal penalty - two points of honor lost for skipping without
// good reason (print capture p. 248)
inline int djpContestHonorLost()
    { return 2; }

// the Contest - only player characters of noble station receive the
// invitation (print capture p. 248)
inline bool djpContestNobleStationOnly()
    { return true; }

// the Contest - held as a formal party, each guest composing a work judged on
// quality, appropriateness, imagery, and beauty (print capture p. 248)
inline bool djpContestFormalParty()
    { return true; }

// the Contest - it can be missed for a good reason such as leaving town at
// ones lords orders (print capture p. 248)
inline bool djpContestExcusedForGoodReason()
    { return true; }

// the Crime - an encounter usable as the basis for the beginning of an
// adventure (print capture p. 248)
inline bool djpCrimeAdventureSeed()
    { return true; }

// the Duel - shukenja are never normally challenged (print capture p. 248)
inline bool djpDuelShukenjaExempt()
    { return true; }

// ---- the Entreaty, the Fire small and the Haunting ----

// the Entreaty - the noble or the commoners willing to pay or even bribe the
// party (print capture p. 249)
inline bool djpEntreatyPayOrBribed()
    { return true; }

// the Fire small arson chance - the fire intentionally set 70% of the time,
// by an enemy, distracting ninjas, or a malicious spirit (print capture p.
// 249)
inline int djpFireSmallIntentionalPct()
    { return 70; }

// the Fire small - if it occurs while the party is at home, one of their own
// buildings is on fire (print capture p. 249)
inline bool djpFireSmallHomeBuilding()
    { return true; }

// the Fire small spread chance - an out-of-control fire ignites nearby
// buildings 70% of the time (print capture p. 249)
inline int djpFireSmallSpreadPct()
    { return 70; }

// the Haunting - see Haunting in the monthly events (print capture p. 249)
inline bool djpHauntingSeeMonthly()
    { return true; }

// ---- the Illness, the Insult and the Invitation ----

// the Illness target - the disease strikes a player character 20% of the time
// (print capture p. 249)
inline int djpIllnessPCTargetPct()
    { return 20; }

// the Illness target - the disease strikes a known NPC 80% of the time (print
// capture p. 249)
inline int djpIllnessNPCTargetPct()
    { return 80; }

// the Illness course - 2d6 days for the disease to run its course, rolled by
// the DM (print capture p. 249)
inline int djpIllnessCourseDice()
    { return 2; }

// the Illness course - the d6 of the 2d6 days (print capture p. 249)
inline int djpIllnessCourseDie()
    { return 6; }

// the Illness recovery - one day of rest required for every day spent ill
// (print capture p. 249)
inline int djpIllnessRestPerIllDay()
    { return 1; }

// the Illness - each day untreated the sick person grows worse, fevers,
// sweating, dizziness, weakness (print capture p. 249)
inline bool djpIllnessWorseUntreated()
    { return true; }

// the Illness - a saving throw versus death at the end of the course if
// uncured, failure kills (print capture p. 249)
inline bool djpIllnessSaveVsDeath()
    { return true; }

// the Insult - at a court the aggrieved presents his complaint to the ruling
// lord (print capture p. 249)
inline bool djpInsultCourtComplaint()
    { return true; }

// the Insult - inadequate punishment or a lower-standing aggrieved leaves a
// long-term enemy (print capture p. 249)
inline bool djpInsultLongTermEnemy()
    { return true; }

// the Invitation - to refuse without justifiable reason is cause for an
// insult (print capture p. 249)
inline bool djpInvitationRefusalIsInsult()
    { return true; }

// ---- the Kidnapping, the Land, the Monster and the Mystery ----

// the Kidnapping - it may be a pair of lovers secretly run away under the
// guise of a kidnapping (print capture p. 249)
inline bool djpKidnapLoversGuisePossible()
    { return true; }

// the Land - uncharted islands filled with unusual and dangerous creatures
// (print capture p. 249)
inline bool djpLandUnchartedDangerous()
    { return true; }

// the Monster - roll on the appropriate monster table to determine the
// encounter (print capture p. 249)
inline bool djpMonsterRollEncounterTable()
    { return true; }

// the Mystery hook - a 60% chance the party is asked to investigate the
// strange event (print capture p. 249)
inline int djpMysteryInvestigatePct()
    { return 60; }

// ---- the Nobles and the Pirates ----

// the Nobles party - 2d10 bushi in the noble party (print capture p. 249)
inline int djpNoblesBushiDice()
    { return 2; }

// the Nobles party - the d10 of the 2d10 bushi (print capture p. 249)
inline int djpNoblesBushiDie()
    { return 10; }

// the Nobles party - 1d6 samurai (print capture p. 249)
inline int djpNoblesSamuraiDie()
    { return 6; }

// the Nobles party - the minimum of the 1-3 persons of rank (print capture p.
// 249)
inline int djpNoblesRanksMin()
    { return 1; }

// the Nobles party - the maximum of the 1-3 persons of rank (print capture p.
// 249)
inline int djpNoblesRanksMax()
    { return 3; }

// the Nobles travel - openly 80% of the time, expecting the respect due their
// station (print capture pp. 249-250)
inline int djpNoblesOpenlyPct()
    { return 80; }

// the Nobles travel - in disguise the other 20%, on a secret mission or
// fleeing an enemy (print capture p. 250)
inline int djpNoblesDisguisePct()
    { return 20; }

// the Nobles - traveling on foot with the nobles carried in palanquins (print
// capture p. 249)
inline bool djpNoblesPalanquinsOnFoot()
    { return true; }

// the Pirates sighting - the minimum of the 1-3 wako ships sighted (print
// capture p. 250)
inline int djpPiratesShipsMin()
    { return 1; }

// the Pirates sighting - the maximum of the 1-3 wako ships sighted (print
// capture p. 250)
inline int djpPiratesShipsMax()
    { return 3; }

// the Pirates - see the description of Men, Wako in this rulebook (print
// capture p. 250)
inline bool djpPiratesSeeWakoDescription()
    { return true; }

// ---- the Plot, the Ruins and the Ship ----

// the Plot - the wind of a plot usable as the basis for a player character
// adventure (print capture p. 250)
inline bool djpPlotAdventureBasis()
    { return true; }

// the Ruins - the parenthesized chance the ruin is haunted by a spirit or
// inhabited by a monster (print capture p. 250)
inline bool djpRuinsHauntedChanceInParens()
    { return true; }

// the Ruins type roll - the temple compound begins at 01 (print capture p.
// 250)
inline int djpRuinTempleMin()
    { return 1; }

// the Ruins type roll - the temple compound ends at 10 (print capture p. 250)
inline int djpRuinTempleMax()
    { return 10; }

// the Ruins haunt chance - the temple compound haunted or inhabited 70%
// (print capture p. 250)
inline int djpRuinTempleHauntedPct()
    { return 70; }

// the Ruins type roll - the farmhouse begins at 11 (print capture p. 250)
inline int djpRuinFarmhouseMin()
    { return 11; }

// the Ruins type roll - the farmhouse ends at 60 (print capture p. 250)
inline int djpRuinFarmhouseMax()
    { return 60; }

// the Ruins haunt chance - the farmhouse haunted or inhabited 20% (print
// capture p. 250)
inline int djpRuinFarmhouseHauntedPct()
    { return 20; }

// the Ruins type roll - the shrine begins at 61 (print capture p. 250)
inline int djpRuinShrineMin()
    { return 61; }

// the Ruins type roll - the shrine ends at 90 (print capture p. 250)
inline int djpRuinShrineMax()
    { return 90; }

// the Ruins haunt chance - the shrine haunted or inhabited 50% (print capture
// p. 250)
inline int djpRuinShrineHauntedPct()
    { return 50; }

// the Ruins type roll - the military stockade begins at 91 (print capture p.
// 250)
inline int djpRuinStockadeMin()
    { return 91; }

// the Ruins type roll - the military stockade ends at 100 (print capture p.
// 250)
inline int djpRuinStockadeMax()
    { return 100; }

// the Ruins haunt chance - the military stockade haunted or inhabited 30%
// (print capture p. 250)
inline int djpRuinStockadeHauntedPct()
    { return 30; }

// the Ship sighting - a 30% chance the sail is a ghost ship ferrying the dead
// (print capture p. 250)
inline int djpShipGhostPct()
    { return 30; }

// the Ship - the ghost ship ferries the dead to their new land (print capture
// p. 250)
inline bool djpShipGhostFerriesTheDead()
    { return true; }

// the Ship sighting - the vessel a merchant ship 50% (the OCR misprint 509-6
// repaired per the roll band, print capture p. 250)
inline int djpShipMerchantPct()
    { return 50; }

// the Ship sighting - the vessel a warship 20% (print capture p. 250)
inline int djpShipWarPct()
    { return 20; }

// the Ship sighting - the merchant or warship crewed by gajin 10% of the time
// (print capture p. 250)
inline int djpShipGajinPct()
    { return 10; }

// ---- the Shrine, the Special and the Storm ----

// the Shrine blessing - a 10% chance the offerings earn a bless for the next
// 24 hours (print capture p. 250)
inline int djpShrineBlessPct()
    { return 10; }

// the Shrine blessing - the bless spell lasts the next 24 hours (print
// capture p. 250)
inline int djpShrineBlessHours()
    { return 24; }

// the Shrine curse - damage or disrespect earns a DM-devised curse 80% of the
// time (print capture p. 250)
inline int djpShrineCursePct()
    { return 80; }

// the Shrine - the blessing only if they stop and make appropriate offerings
// (print capture p. 250)
inline bool djpShrineOfferingsRequired()
    { return true; }

// the Special - the mission from lord, mentor, or family head is the starting
// point of an adventure (print capture p. 250)
inline bool djpSpecialAdventureStart()
    { return true; }

// the Storm duration - 5d6 hours of gale, rain, and crashing waves at sea
// (print capture p. 250)
inline int djpStormHoursDice()
    { return 5; }

// the Storm duration - the d6 of the 5d6 hours (print capture p. 250)
inline int djpStormHoursDie()
    { return 6; }

// the Storm exposure - the minimum of the 1-2 points of damage per hour
// outside (print capture p. 250)
inline int djpStormExhaustMin()
    { return 1; }

// the Storm exposure - the maximum of the 1-2 points of damage per hour
// outside (print capture p. 250)
inline int djpStormExhaustMax()
    { return 2; }

// the Storm - the characters are unable to travel that day, drifting,
// flooding, or sand dunes (print capture p. 250)
inline bool djpStormNoTravelThatDay()
    { return true; }

// the Storm - in deserts it is a sandstorm (print capture p. 250)
inline bool djpStormDesertSandstorm()
    { return true; }

// ---- the Stranger, the Traveler and the VIP ----

// the Stranger identity - an ordinary traveler 30% of the time (print capture
// p. 250)
inline int djpStrangerOrdinaryPct()
    { return 30; }

// the Stranger identity - a member of a secret society 10% (print capture p.
// 250)
inline int djpStrangerSocietyPct()
    { return 10; }

// the Stranger identity - an official of the secret police 10% (print capture
// p. 250)
inline int djpStrangerPolicePct()
    { return 10; }

// the Stranger identity - a ninja on a mission 10% (print capture p. 250)
inline int djpStrangerNinjaPct()
    { return 10; }

// the Stranger identity - a noble traveling in disguise 10% (print capture p.
// 250)
inline int djpStrangerNoblePct()
    { return 10; }

// the Stranger identity - a bandit using the party as cover 10% (print
// capture p. 250)
inline int djpStrangerBanditPct()
    { return 10; }

// the Stranger identity - a hengeyokai or spirit in human form 10% (print
// capture p. 250)
inline int djpStrangerHengeyokaiPct()
    { return 10; }

// the Stranger identity - a yakuza subtly seeking information 10% (print
// capture p. 250)
inline int djpStrangerYakuzaPct()
    { return 10; }

// the Stranger - he goes the same direction and wants to travel with the
// party for company and safety (print capture p. 250)
inline bool djpStrangerTravelsAlong()
    { return true; }

// the Traveler - the DM devises whatever he desires for this encounter (print
// capture p. 250)
inline bool djpTravelerDMDevises()
    { return true; }

// the VIP entourage - 20d6 bushi in advance of him (print capture p. 250)
inline int djpVIPBushiDice()
    { return 20; }

// the VIP entourage - the d6 of the 20d6 bushi (print capture p. 250)
inline int djpVIPBushiDie()
    { return 6; }

// the VIP entourage - 10d4 samurai in advance of him (print capture p. 250)
inline int djpVIPSamuraiDice()
    { return 10; }

// the VIP entourage - the d4 of the 10d4 samurai (print capture p. 250)
inline int djpVIPSamuraiDie()
    { return 4; }

// the VIP - no attempt to hide the arrival, the title announced in the
// streets (print capture p. 250)
inline bool djpVIPArrivalAnnounced()
    { return true; }

// the VIP - any impudent enough to challenge the entourage are cut down on
// the spot (print capture p. 251)
inline bool djpVIPImpudentCutDown()
    { return true; }

}   // namespace rules
