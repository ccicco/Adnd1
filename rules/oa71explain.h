// =========================================================================================
// Adnd1 - rules/oa71explain.h
// OA EXPLANATION OF YEARLY EVENTS, printed capture pp. 240-243 - the yearly
// explanations round
// census 620 -> 621.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE RIGIDITY: the events not accounting for the player
// characters, the outcomes changeable, but the yearly event NEVER rerolled -
// prevented meaning no yearly event for the year; the season check after the
// month roll. THE EXPLANATIONS: the Ambassador of the 50/50 direction staying
// 3d10 months, the 10% gaijin, the court ceremonies; the Assassination with
// the 30% taken-alive, the 1% accusation, the 20% succession struggle and the
// 1d6-month turmoil; the Birth celebrated for days; the Comet of the 1d4
// weeks, the portent, the DM's second event to follow; the Death of a Lord
// with the Assassination's succession; the Major Earthquake of the 50-mile
// radius, the 70% fire and the 40% plague, the earthquake spell effects, the
// few hours; the Famine of the 2-7 months, the food at 10 to 100 times, the
// 25% next-year income, the 60% uprising, the 5% monthly population loss, the
// 20% plague; the Major Fire of the 50% to 80% city, the 10% to 40%
// population, the 20% plague, the 10% famine, the 10x lumber for four months,
// the doubled food for one; the Flood of the 5d6-foot crest, the half foot
// per hour, the 4d6-hour high, the signs 2-5 days ahead, the dikes, the 50%
// planting-season and 80% harvest losses, the 40% famine, the 20% plague, no
// deserts; the Major Incursion of the 1d12 months, proportionate, remaining
// until driven out; the Marriage diplomatic and festive; the New Religion
// with the 75% hostility, the 60% ruler's favor, the 40% ban, the 2-7 month
// arrival, the feuds of centuries; the Plague of the 2d6 months, the 40% and
// 60% contagion, the 5% monthly loss, the 5x imports, the moving scythe; the
// Political Plot with the 40% and 80% accusations, the 20% noble rising, the
// 1-3 month turmoil; the Rebellion of the 1d6 months, the BATTLESYSTEM
// recommendation, no mercy for the captured; the Tsunami of the 50-mile
// coast, the 100-200 feet, the 70% population loss, the landlocked no-event,
// the 10% plague, the 3x building materials; the Visitation of the revered
// pilgrim site or the despised 5-mile shunning; the Volcano of the 70/30
// origin, the 5-mile destruction, the 30-mile ash, the 1d12-month activity,
// the 10% monthly re-eruption; the War of the 50/50 direction, the 2-5 month
// campaign in the summer, the 1-3 years, the 50% farm loss, the press gangs.
// The explanations codify per the R431 calculus
//
// the gap census after this round: 151 closed, 84 open - the Yearly Events
// prose box flips (census 620 -> 621); NEXT - R699: Table 72 the monthly
// events grid (capture p. 238), prefix djm (verify free at the landing),
// audit "R699 OA monthly events audit", include after rules/oa71explain.h
//
namespace rules {

// ---- the court and the calamities ----

// the Ambassador stay - the 3d10 months the ambassador remains in the land
// (print capture p. 240)
inline int djlAmbassadorStayDiceCount()
    { return 3; }

// the Ambassador stay die - the d10 of the 3d10 months (print capture p. 240)
inline int djlAmbassadorStayDieSize()
    { return 10; }

// the Ambassador gaijin chance - 10% that any arriving ambassador is a gaijin
// from the distant lands beyond Kara-Tur (print capture p. 240)
inline int djlAmbassadorGaijinPct()
    { return 10; }

// the Ambassador direction - arriving from another land or sent to one,
// 50/50; sent to prevent war, form an alliance, arrange a marriage, pay
// tribute, promote trade or gain culture, the arrival a major court event of
// ceremonies and banquets (print capture p. 240)
inline bool djlAmbassadorEitherDirection()
    { return true; }

// the Assassination capture chance - 30% that the assassin is taken alive
// (print capture p. 240)
inline int djlAssassinAlivePct()
    { return 30; }

// the Assassination accusation - 1% chance the taken-alive assassin accuses
// the player characters connected to the slain (print capture p. 240)
inline int djlAssassinAccusePct()
    { return 1; }

// the Assassination succession - 20% chance the slain lord has no clear
// successor, the power struggle ensuing (print capture p. 240)
inline int djlAssassinNoSuccessorPct()
    { return 20; }

// the Assassination turmoil die - the 1d6 months of the power struggle or of
// the court turmoil before things return to normal (print capture p. 240)
inline int djlAssassinTurmoilDie()
    { return 6; }

// the Assassination suspicion - the player characters suspected as vassals or
// dealing partners of the slain, automatically if known enemies (print
// capture p. 240)
inline bool djlAssassinPcSuspicion()
    { return true; }

// the Assassination power struggle - lasting 1d6 months and possibly
// resulting in war if the DM desires (print capture p. 240)
inline bool djlAssassinStruggleMayWar()
    { return true; }

// the Birth - the noble line continued, the happy event with feasting and
// ceremonies lasting several days (print capture p. 240)
inline bool djlBirthCelebration()
    { return true; }

// the Comet sighting - the bright comet in the sky for 1d4 weeks (print
// capture p. 240)
inline int djlCometDieSize()
    { return 4; }

// the Comet portent - the bright comet sighted 1d4 weeks, a portent of some
// great event: a second yearly event chosen by the DM and occurring shortly
// after the comet passes (print capture p. 240)
inline bool djlCometPortentSecond()
    { return true; }

// the Death of a Lord - the noble dying in battle, misadventure, disease or
// peacefully in bed, the succession effects the same as the Assassination's
// (print capture p. 241)
inline bool djlDeathSameAsAssassination()
    { return true; }

// the Major Earthquake radius - extensive destruction within the
// 50-mile-radius area, the center point the DM's choice (print capture p.
// 241)
inline int djlQuakeRadiusMi()
    { return 50; }

// the Major Earthquake fire chance - 70% that a major fire occurs in any town
// or city of the radius (print capture p. 241)
inline int djlQuakeFirePct()
    { return 70; }

// the Major Earthquake plague chance - 40% that a plague will occur in a
// populated area (print capture p. 241)
inline int djlQuakePlaguePct()
    { return 40; }

// the Major Earthquake tremors - the series of lesser tremors before and
// after, slight damage per the DM (print capture p. 241)
inline bool djlQuakeLesserTremors()
    { return true; }

// the Major Earthquake effects - the player characters and property in the
// radius affected as by an earthquake spell, the severity the DM's choice;
// the quake lasting only a few hours, destroying cities and reshaping lakes,
// coastlines and rivers (print capture p. 241)
inline bool djlQuakeSpellEffects()
    { return true; }

// ---- the famine, the fire and the flood ----

// the Famine duration minimum - the 2 of the 2-7 months (print capture p.
// 241)
inline int djlFamineMinMonths()
    { return 2; }

// the Famine duration maximum - the 7 of the 2-7 months (print capture p.
// 241)
inline int djlFamineMaxMonths()
    { return 7; }

// the Famine price spiral - the food price skyrocketing 10, 50 or even 100
// times its normal price (print capture p. 241)
inline int djlFaminePriceMaxX()
    { return 100; }

// the Famine farm recovery - no income for the year, only 25% of normal
// income in the next year (print capture p. 241)
inline int djlFamineNextYearPct()
    { return 25; }

// the Famine uprising chance - 60% that the peasants rise unless steps are
// taken to relieve the suffering (print capture p. 241)
inline int djlFamineUprisingPct()
    { return 60; }

// the Famine population loss - the area's population reduced by 5% per month
// of famine (print capture p. 241)
inline int djlFaminePopPct()
    { return 5; }

// the Famine plague chance - 20% (print capture p. 241)
inline int djlFaminePlaguePct()
    { return 20; }

// the Famine signs - the crops withering, animals dying, the poor hungering;
// the marauder groups scavenging for food of any type (print capture p. 241)
inline bool djlFamineSigns()
    { return true; }

// the Major Fire destruction minimum - the 50% of the 50% to 80% of the city
// destroyed (print capture p. 241)
inline int djlFireMinPct()
    { return 50; }

// the Major Fire destruction maximum - the 80% of the 50% to 80% (print
// capture p. 241)
inline int djlFireMaxPct()
    { return 80; }

// the Major Fire population minimum - the city's population reduced by 10% to
// 40% (print capture p. 241)
inline int djlFirePopMinPct()
    { return 10; }

// the Major Fire population maximum - the 40% of the 10% to 40% (print
// capture p. 241)
inline int djlFirePopMaxPct()
    { return 40; }

// the Major Fire plague chance - 20% (print capture p. 241)
inline int djlFirePlaguePct()
    { return 20; }

// the Major Fire famine chance - 10% (print capture p. 241)
inline int djlFireFaminePct()
    { return 10; }

// the Major Fire lumber price - 10 times normal for the next four months
// (print capture p. 241)
inline int djlFireLumberX()
    { return 10; }

// the Major Fire lumber duration - the four months of the 10x lumber and
// building materials (print capture p. 241)
inline int djlFireLumberMonths()
    { return 4; }

// the Major Fire property - the player characters' property burned to the
// ground at the percentage chance equal to the amount of the city destroyed
// (print capture p. 241)
inline bool djlFirePcPropertyBurned()
    { return true; }

// the Flood crest - the waters rising 5-30 feet (the 5d6), a half foot per
// hour until the maximum is reached (print capture p. 241)
inline int djlFloodMaxFt()
    { return 30; }

// the Flood high point - the waters remaining at crest for 4d6 hours,
// subsiding at one foot per day (print capture p. 241)
inline int djlFloodHighDieSize()
    { return 6; }

// the Flood planting season - the farms' income reduced by 50% for the year
// (print capture p. 241)
inline int djlFloodFarmPlantPct()
    { return 50; }

// the Flood harvest season - 80% of all farm income lost (print capture p.
// 241)
inline int djlFloodFarmHarvestPct()
    { return 80; }

// the Flood harvest famine - 40% chance of famine in 1-3 months unless
// prevented (print capture p. 241)
inline int djlFloodHarvestFaminePct()
    { return 40; }

// the Flood plague chance - all floods 20% (print capture p. 241)
inline int djlFloodPlaguePct()
    { return 20; }

// the Flood warning - the signs obvious 2-5 days in advance, the levees and
// dikes buildable to protect against the rising waters (print capture p. 241)
inline bool djlFloodLevees()
    { return true; }

// the Flood limit - floods never occurring in desert or arid regions (print
// capture p. 241)
inline bool djlFloodNoDesert()
    { return true; }

// ---- the incursion, the religion and the plague ----

// the Major Incursion duration - the migration occurring over 1d12 months
// (print capture p. 241)
inline int djlIncursionDieSize()
    { return 12; }

// the Major Incursion scale - the migration in proportion to the kingdom, the
// several hundred creatures of a small province or the several thousand of a
// large kingdom; humans, humanoids or monsters, not necessarily war (print
// capture p. 241)
inline bool djlIncursionProportionate()
    { return true; }

// the Major Incursion settlement - the creatures remaining until driven out,
// the old habits and language retained, gradually adopted into the regular
// part of life if allowed to stay (print capture p. 241)
inline bool djlIncursionRemainsUntilDrivenOut()
    { return true; }

// the Marriage - the ruler's important diplomatic marriage of himself or his
// children, securing alliances, controlling smaller kingdoms, settling
// disputes or appeasing overlords; festivals and feasting (print capture p.
// 241)
inline bool djlMarriageDiplomatic()
    { return true; }

// the New Religion hostility - 75% chance of feuding with the established
// religions, the skirmishing, temple burning and warrior monk battles (print
// capture p. 241)
inline int djlNewReligionHostilityPct()
    { return 75; }

// the New Religion ruler - 60% chance the ruler comes out in favor of the new
// religion (print capture p. 242)
inline int djlNewReligionRulerFavorPct()
    { return 60; }

// the New Religion ban - 40% chance the ruler bans the other religions,
// temples burned, clerics killed or banished (print capture p. 242)
inline int djlNewReligionBanPct()
    { return 40; }

// the New Religion arrival minimum - the 2 of the 2-7 months of the initial
// arrival (print capture p. 242)
inline int djlNewReligionArrivalMin()
    { return 2; }

// the New Religion arrival maximum - the 7 of the 2-7 months, the feuding
// possibly lasting for centuries (print capture p. 242)
inline int djlNewReligionArrivalMax()
    { return 7; }

// the New Religion politics - the rulers supporting the new religions as a
// tool for breaking the political power of the established ones, both sides
// seeking the ruler's support (print capture p. 242)
inline bool djlNewReligionRulersTool()
    { return true; }

// the Plague duration dice - the 2 of the 2d6 months, the disease sweeping
// faster than the clerics can check it (print capture p. 242)
inline int djlPlagueDieCount()
    { return 2; }

// the Plague duration die - the d6 of the 2d6 months (print capture p. 242)
inline int djlPlagueDieSize()
    { return 6; }

// the Plague contagion - 40% chance per month spent in the plague-ridden
// lands (print capture p. 242)
inline int djlPlagueCatchPct()
    { return 40; }

// the Plague company contagion - 60% chance of contracting it in the company
// of a diseased person (print capture p. 242)
inline int djlPlagueCatchCompanyPct()
    { return 60; }

// the Plague population loss - the area's population reduced by 5% per month
// (print capture p. 242)
inline int djlPlaguePopPct()
    { return 5; }

// the Plague prices - the imported goods five times normal, the normal goods
// doubled, traders staying out (print capture p. 242)
inline int djlPlagueImportX()
    { return 5; }

// the Plague movement - not the whole country at once but sweeping from town
// to town like a moving scythe: not yet hit, in the throes, or suffered and
// survived (print capture p. 242)
inline bool djlPlagueSweeps()
    { return true; }

// ---- the plot, the rebellion, the disasters and the war ----

// the Political Plot accusation - 40% that player characters in government or
// political affairs are accused of complicity (print capture p. 242)
inline int djlPlotAccusePct()
    { return 40; }

// the Political Plot accusation with enemies - the chance increased to 80%
// for characters with powerful enemies (print capture p. 242)
inline int djlPlotAccuseEnemiesPct()
    { return 80; }

// the Political Plot rebellion - 20% chance that a noble or group of nobles
// rises (print capture p. 242)
inline int djlPlotRebellionPct()
    { return 20; }

// the Political Plot turmoil - the 3 of the 1-3 months of the political
// turmoil, spies and secret police everywhere (print capture p. 242)
inline int djlPlotTurmoilMaxMonths()
    { return 3; }

// the Political Plot justice - the accused proving innocence or suffering the
// consequences, the nobles stripped of rank, banished or executed (print
// capture p. 242)
inline bool djlPlotProveInnocence()
    { return true; }

// the Rebellion duration without the BATTLESYSTEM supplement - the 1d6 months
// before the unlikely success or the failure (print capture p. 242)
inline int djlRebellionDieSize()
    { return 6; }

// the Rebellion battles - the BATTLESYSTEM supplement recommended for the
// military battles, the players managing the strategy of either side; the
// captured and defeated rebels expecting no mercy (print capture p. 242)
inline bool djlRebellionBattlesystem()
    { return true; }

// the Tsunami strike - a 50-mile section of coastline, the great wave as per
// the spell (print capture p. 242)
inline int djlTsunamiCoastMi()
    { return 50; }

// the Tsunami height minimum - the 100 of the 100 to 200 feet when it hits
// (print capture p. 242)
inline int djlTsunamiHeightMinFt()
    { return 100; }

// the Tsunami height maximum - the 200 feet, striking with little warning
// (print capture p. 242)
inline int djlTsunamiHeightMaxFt()
    { return 200; }

// the Tsunami population loss - the area's population reduced by 70% (print
// capture p. 242)
inline int djlTsunamiPopPct()
    { return 70; }

// the Tsunami aftermath plague - 10% chance (print capture p. 242)
inline int djlTsunamiPlaguePct()
    { return 10; }

// the Tsunami prices - building materials triple, all other goods double, for
// the 1-2 months of the aftermath (print capture p. 242)
inline int djlTsunamiBuildX()
    { return 3; }

// the Tsunami limit - countries without coastlines treating the event as no
// event for the year (print capture p. 242)
inline bool djlTsunamiNoCoastNoEvent()
    { return true; }

// the Visitation despised radius - the fortunes of those within a 5-mile
// radius falling, the area shunned (print capture p. 242)
inline int djlVisitationRadiusMi()
    { return 5; }

// the Visitation - the major deity appearing for good or ill; the revered
// site becoming pilgrim and temple ground, the despised site shunned, the
// fortunes falling, the secret meeting place of evil followers and monsters
// (print capture p. 242)
inline bool djlVisitationPaths()
    { return true; }

// the Volcano origin - 70% a dormant volcano erupts, 30% a new volcano
// appears, the eruption preceded by the tremors of a major earthquake (print
// capture p. 242)
inline int djlVolcanoDormantPct()
    { return 70; }

// the Volcano destruction - all within a 5-mile radius destroyed (print
// capture p. 242)
inline int djlVolcanoRadiusMi()
    { return 5; }

// the Volcano ash - the thick clouds raining down up to 30 miles downwind,
// the smoke and ash for the remainder of the month (print capture p. 242)
inline int djlVolcanoAshMi()
    { return 30; }

// the Volcano activity - remaining active for 1d12 months (print capture p.
// 242)
inline int djlVolcanoActiveDieSize()
    { return 12; }

// the Volcano re-eruption - 10% chance per month of another major eruption
// (print capture p. 242)
inline int djlVolcanoReEruptPct()
    { return 10; }

// the War campaign minimum - the 2 of the 2-5 months of the one major
// campaign per year, generally in the summer (print capture p. 243)
inline int djlWarCampaignMinMonths()
    { return 2; }

// the War campaign maximum - the 5 of the 2-5 months (print capture p. 243)
inline int djlWarCampaignMaxMonths()
    { return 5; }

// the War duration - the war lasting 1-3 years, the armies in the thousands
// or tens of thousands (print capture p. 243)
inline int djlWarDurationMaxYears()
    { return 3; }

// the War farm income - the farms in the area fought over reduced by 50%, the
// prices on the campaign trail doubled or tripled (print capture p. 243)
inline int djlWarFarmPct()
    { return 50; }

// the War direction - the ruler's campaign against a neighboring land or the
// invasion from one, 50/50; the causes, forces and outcome the DM's (print
// capture p. 243)
inline bool djlWarEitherDirection()
    { return true; }

// the War player characters - readily accepted into the ranks, quickly rising
// in rank per their actions, possibly given commands with the BATTLESYSTEM
// supplement (print capture p. 243)
inline bool djlWarPcRoles()
    { return true; }

// the War home front - away from the front the rebellion or uprising, the
// press gangs roaming, the younger sons deserting for soldier's fame, the
// civilians moving away (print capture p. 243)
inline bool djlWarHomefront()
    { return true; }

// ---- the event rigidity ----

// the event rigidity - the events not accounting for the player characters'
// actions; the player characters may change the outcomes but the YEARLY event
// is never rerolled (print capture p. 240)
inline bool djlYearlyNeverRerolled()
    { return true; }

// the prevented yearly event - if the player characters manage to prevent it,
// no yearly event occurs for that year; the monthly events simply rerolled or
// decided when changed (print capture p. 240)
inline bool djlYearlyPreventedNone()
    { return true; }

// the season check - the exact description of the event giving the range of
// time over which it occurs, the monthly events checked for after the yearly
// month is determined (print capture p. 238)
inline bool djlYearlySeasonCheck()
    { return true; }

}   // namespace rules
