// =========================================================================================
// Adnd1 - rules/s25.h
// The Dragon issue-25 opener part two - the war game and the vampire roster
// census 881 -> 882.
//
// The part-two round of the issue-25 four-round shape - two of the eight
// Curtiss-called chains as the table round: the Neal M. Dorst Xochiyaoyotl
// rules for pre-Hispanic Mexican warfare (print 37-40) with the prowess ratio
// grid, the weather table, the projectile ranges, the morale bands, the War
// of Flowers points and the Spanish optional rules, and the R.P. Smith
// Varieties of Vampires roster (print 42) - fifteen types from the common
// vampire through the asanbosam, the burcolakas, the catacano, the
// lobishumen, the ekimmu, the blautsauger, the mulo, the alp, the anananngel,
// the krvopijac, the Chinese hopping vampire, the vlkodlak, the bruxsa and
// the nosferat, the movement pairs and the charm adjustments on the grid. All
// pinned from The Dragon Vol. III No. 11 (May 1979) print 37-40 and 42 at
// extract/dragon/025, PRINT FOLIO = PDF PAGE this issue, the single-voice
// transcript of the Curtiss-provided scan. The part-one opener set landed at
// R958; the three-chain commentary set rides R960 and the flip to follow; the
// two inherited watches - the Sullin levels 7-9 and the brawling sequel -
// print nowhere in issue 25 and ride to TD 26.
//
namespace rules {

// ---- the Xochiyaoyotl war game rules (print 37-40) ----

// the figure scale - each unit or figure represents twenty menthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25MenPerUnit()
    { return 20; }

// the turn scale - one turn equals two minutes of battle timethe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25TurnMinutes()
    { return 2; }

// the ground scale - one inch of horizontal distance equals twenty five
// yardsthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25YardsPerInch()
    { return 25; }

// the height scale - one inch of vertical distance equals five feetthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25FeetPerVerticalInch()
    { return 5; }

// the low end of the Military Prowess rating - the range runs one to fivethe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25ProwessRangeLo()
    { return 1; }

// the high end of the Military Prowess rating - the ratio row and the die
// grid key on itthe Xochiyaoyotl war game rules (print 37-40) the
// Xochiyaoyotl war game rules (print 37-40)
inline int s25ProwessRangeHi()
    { return 5; }

// the die grid depth - six die rolls set the unit strength at each prowess
// ratingthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25ProwessDieCount()
    { return 6; }

// the ratio number at prowess one - the full count, five hundred men against
// five hundredthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl
// war game rules (print 37-40)
inline int s25ProwessRatioPct1()
    { return 100; }

// the ratio number at prowess two - nine tenths of the menthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25ProwessRatioPct2()
    { return 90; }

// the ratio number at prowess three - three quarters of the menthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25ProwessRatioPct3()
    { return 75; }

// the ratio number at prowess four - three fifths of the menthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25ProwessRatioPct4()
    { return 60; }

// the ratio number at prowess five - half the men against the finestthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25ProwessRatioPct5()
    { return 50; }

// the leader unit - always six elite, the maximum for the prowess rating, war
// clubs in handthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl
// war game rules (print 37-40)
inline int s25LeaderEliteStrength()
    { return 6; }

// the priest unit - one elite, sword armed when the melee comesthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25PriestEliteStrength()
    { return 1; }

// the quilted cotton armor - a quarter of the force may wear it, the odds
// halved for itthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl
// war game rules (print 37-40)
inline int s25CottonArmorPct()
    { return 25; }

// the division size - ten units of two hundred men to an army slicethe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25DivisionUnits()
    { return 10; }

// the division cohesion - each unit within two inches of another, chained
// member to memberthe Xochiyaoyotl war game rules (print 37-40) the
// Xochiyaoyotl war game rules (print 37-40)
inline int s25DivisionChainInches()
    { return 2; }

// the leader reach - one member of each division within twenty four inches of
// the leader unitthe Xochiyaoyotl war game rules (print 37-40) the
// Xochiyaoyotl war game rules (print 37-40)
inline int s25LeaderContactInches()
    { return 24; }

// the ambush reveal - hidden elite units stay hid until they move or a foe
// passes within two inchesthe Xochiyaoyotl war game rules (print 37-40) the
// Xochiyaoyotl war game rules (print 37-40)
inline int s25HiddenRevealInches()
    { return 2; }

// the weather window - fifteen turns to a roll, the effects hold the full
// periodthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25WeatherPeriodTurns()
    { return 15; }

// the weather sacrifice - sixty enemy men over three turns buys clear
// skiesthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25SacrificeWeatherMen()
    { return 60; }

// the morale sacrifice - a priest unit sacrifices twenty prisoners in a turn,
// the maximum ratethe Xochiyaoyotl war game rules (print 37-40) the
// Xochiyaoyotl war game rules (print 37-40)
inline int s25SacrificeMoraleMen()
    { return 20; }

// the captor boost - three morale levels on the return to combatthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25CaptureMoraleBoost()
    { return 3; }

// the captor boost span - fifteen turns of elevated moralethe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25CaptureMoraleTurns()
    { return 15; }

// the assault limit - no more than six units attack one enemy unit in a
// turnthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game
// rules (print 37-40)
inline int s25MaxAttackersPerTurn()
    { return 6; }

// the prisoner handoff wait - one turn at the priest unitthe Xochiyaoyotl war
// game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25PrisonerPriestWaitTurns()
    { return 1; }

// the prisoner handoff wait off the field - two turns before the returnthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25PrisonerOffFieldWaitTurns()
    { return 2; }

// the draw band - up to fifty points apartthe Xochiyaoyotl war game rules
// (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25VictoryDrawHi()
    { return 50; }

// the minimal victory band - fifty one through one hundredthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25VictoryMinimalHi()
    { return 100; }

// the victory band - one hundred one through one hundred fifty, superlative
// beyondthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25VictoryMarginHi()
    { return 150; }

// the War of Flowers points - ten an enemy leader capturedthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25FlowerLeaderCapturePts()
    { return 10; }

// the War of Flowers points - five an enemy elite capturedthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25FlowerEliteCapturePts()
    { return 5; }

// the War of Flowers points - three an enemy man capturedthe Xochiyaoyotl war
// game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25FlowerManCapturePts()
    { return 3; }

// the War of Flowers points - minus one an enemy man killedthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25FlowerManKilledPenalty()
    { return 1; }

// the Spanish rating - every Spanish unit six elitethe Xochiyaoyotl war game
// rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25SpanishEliteStrength()
    { return 6; }

// the Spanish ratio - one Spanish figure to four native, the allied units
// apartthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25SpanishRatioPct()
    { return 25; }

// the cannon unit - five guns to the unitthe Xochiyaoyotl war game rules
// (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25CannonsPerUnit()
    { return 5; }

// the cannon crew - twenty men to the five gunsthe Xochiyaoyotl war game
// rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25CannonCrewMen()
    { return 20; }

// the Spanish cap - under a tenth of the force Horse or Cannonthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25SpanishHorseCannonPctMax()
    { return 10; }

// the Spanish victory points - ten a Spanish leader capturedthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25SpanishLeaderCapturedPts()
    { return 10; }

// the Spanish victory points - five a Spanish leader killedthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25SpanishLeaderKilledPts()
    { return 5; }

// the Spanish victory points - five a Spanish man capturedthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25SpanishManCapturedPts()
    { return 5; }

// the Spanish victory points - three a Spanish man killedthe Xochiyaoyotl war
// game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25SpanishManKilledPts()
    { return 3; }

// the Spanish sacrifice count - a capture minus twothe Xochiyaoyotl war game
// rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline int s25SpanishSacrificePenaltyPts()
    { return 2; }

// the referee call - a referee recommended on hand to run the game and settle
// the disputesthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl
// war game rules (print 37-40)
inline bool s25RefereeRecommended()
    { return true; }

// the turn shape - the opposing sides move at oncethe Xochiyaoyotl war game
// rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25SimultaneousMoves()
    { return true; }

// the leader scale - the last man caught or killed when attacked or shot
// atthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game
// rules (print 37-40)
inline bool s25LeaderLastCaught()
    { return true; }

// the priest arms - swords in hand-to-hand, the strength onethe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25PriestsSwordMelee()
    { return true; }

// the fire discipline - a unit that fired may not move that turnthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline bool s25FiredNoMove()
    { return true; }

// the half measure - fire half the rate and move half the ratethe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline bool s25HalfFireHalfMove()
    { return true; }

// the sling effect - the count in parenthesis left unconscious, lost to a
// unit that movesthe Xochiyaoyotl war game rules (print 37-40) the
// Xochiyaoyotl war game rules (print 37-40)
inline bool s25SlingStuns()
    { return true; }

// the ambush post - five elite units hid in rough or uneven terrain by the
// side with prior accessthe Xochiyaoyotl war game rules (print 37-40) the
// Xochiyaoyotl war game rules (print 37-40)
inline bool s25HiddenInRough()
    { return true; }

// the defend option - the defender strength doubled, the turn passes to the
// aggressorthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline bool s25DefendDoubles()
    { return true; }

// the rear assault - a three halves multiplier at the hind one hundred eighty
// degreesthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline bool s25HindQuarterMultiplier()
    { return true; }

// the War of Flowers law - leader units not attacked unless they attack
// firstthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline bool s25FlowerLeadersSafe()
    { return true; }

// the War of Flowers arms - Disarm or Defend the only optionsthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25FlowerDisarmDefendOnly()
    { return true; }

// the War of Flowers count - every sacrifice a capturethe Xochiyaoyotl war
// game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25FlowerSacrificeCountsCaptured()
    { return true; }

// the steel armor flaw - the quilted protection fails against arquebus and
// cannonthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war
// game rules (print 37-40)
inline bool s25SpanishArmorNotVsGunpowder()
    { return true; }

// the thunderstorm ban - cannon and arquebus silentthe Xochiyaoyotl war game
// rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25NoGunfireInThunderstorm()
    { return true; }

// the cannon track - no travel through swampy groundthe Xochiyaoyotl war game
// rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25CannonBannedInSwamp()
    { return true; }

// the Spanish order - column travel, one or two units abreastthe Xochiyaoyotl
// war game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25SpanishColumnMove()
    { return true; }

// the Mexican assault - Disarm or Defend the only options against a Spanish
// unitthe Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game
// rules (print 37-40)
inline bool s25MexicanAttackerDisarmOnly()
    { return true; }

// the Spanish captors - prisoners held and passed on, never sacrificedthe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline bool s25SpanishNoSacrifice()
    { return true; }

// the Spanish absence - no part in the War of Flowersthe Xochiyaoyotl war
// game rules (print 37-40) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25SpanishNotInFlowerWars()
    { return true; }

// the sacrifice order - Spanish prisoners before any Indian allythe
// Xochiyaoyotl war game rules (print 37-40) the Xochiyaoyotl war game rules
// (print 37-40)
inline bool s25SpanishPrisonersFirst()
    { return true; }

// the unit strength at prowess one - one through four on the die, the top
// roll elite
inline int s25StrengthMp1(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 4;
        default:
            return -99;
        }
    }

// the unit strength at prowess two - two through four on the die, the top
// roll elite
inline int s25StrengthMp2(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 4;
        default:
            return -99;
        }
    }

// the unit strength at prowess three - two through five on the die, the top
// roll elite
inline int s25StrengthMp3(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 5;
        default:
            return -99;
        }
    }

// the unit strength at prowess four - three through five on the die, the top
// roll elite
inline int s25StrengthMp4(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 5;
        default:
            return -99;
        }
    }

// the unit strength at prowess five - three through six on the die, the top
// roll elite
inline int s25StrengthMp5(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the elite mark - one on the die six roll at every rating, the sentinel on
// the other five rolls
inline int s25EliteOnDie(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -99;
        case 2:
            return -99;
        case 3:
            return -99;
        case 4:
            return -99;
        case 5:
            return 1;
        default:
            return -99;
        }
    }

// ---- the R.P. Smith vampire varieties (print 42) ----

// the roster depth - fifteen vampire types from the common to the nosferatthe
// R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25VampireRosterCount()
    { return 15; }

// the unguarded corpse - without a Bless from a cleric a body rises within
// seven daysthe R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25VampireRiseDays()
    { return 7; }

// the asanbosam men - nine hit dicethe R.P. Smith vampire varieties (print
// 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AsanbosamManHd()
    { return 9; }

// the asanbosam women - eight hit dicethe R.P. Smith vampire varieties (print
// 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AsanbosamWomanHd()
    { return 8; }

// the asanbosam children - seven hit dicethe R.P. Smith vampire varieties
// (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AsanbosamChildHd()
    { return 7; }

// the asanbosam charm - at minus three, the clerics avoidedthe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AsanbosamCharmAdj()
    { return 3; }

// the asanbosam call - three to eighteen leopards, the low diethe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AsanbosamLeopardsLo()
    { return 3; }

// the asanbosam call - three to eighteen leopards, the high diethe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AsanbosamLeopardsHi()
    { return 18; }

// the asanbosam call - two to twelve tigers, the low diethe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AsanbosamTigersLo()
    { return 2; }

// the asanbosam call - two to twelve tigers, the high diethe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AsanbosamTigersHi()
    { return 12; }

// the burcolakas swarm - ten to one hundred rats, the low diethe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25BurcolakasRatsLo()
    { return 10; }

// the burcolakas swarm - ten to one hundred rats, the high diethe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25BurcolakasRatsHi()
    { return 100; }

// the lobishumen charm - at minus fourthe R.P. Smith vampire varieties (print
// 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25LobishumenCharmAdj()
    { return 4; }

// the lobishumen legacy - sixty percent of the women who survive the charmthe
// R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25LobishumenNymphoPct()
    { return 60; }

// the ekimmu charm - at minus onethe R.P. Smith vampire varieties (print 42)
// the Xochiyaoyotl war game rules (print 37-40)
inline int s25EkimmuCharmAdj()
    { return 1; }

// the ekimmu exorcism - a dispel evil at fifty percent when the cleric
// matches the levelthe R.P. Smith vampire varieties (print 42) the
// Xochiyaoyotl war game rules (print 37-40)
inline int s25EkimmuDispelBasePct()
    { return 50; }

// the ekimmu exorcism swing - plus or minus five percent a level of
// differencethe R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25EkimmuDispelLevelPct()
    { return 5; }

// the anananngel charm - at minus twothe R.P. Smith vampire varieties (print
// 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AnananngelCharmAdj()
    { return 2; }

// the anananngel fear - thrown at minus threethe R.P. Smith vampire varieties
// (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AnananngelFearAdj()
    { return 3; }

// the anananngel coin - fifty percent a living witchthe R.P. Smith vampire
// varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline int s25AnananngelLivingWitchPct()
    { return 50; }

// the blood-splatter cure - a cure disease daily for two to seven days, the
// low endthe R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25AnananngelCureDaysLo()
    { return 2; }

// the blood-splatter cure - a cure disease daily for two to seven days, the
// high endthe R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war
// game rules (print 37-40)
inline int s25AnananngelCureDaysHi()
    { return 7; }

// the alp call - ten to one hundred ordinary butterflies, the low diethe R.P.
// Smith vampire varieties (print 42) the Xochiyaoyotl war game rules (print
// 37-40)
inline int s25AlpButterfliesLo()
    { return 10; }

// the alp call - ten to one hundred ordinary butterflies, the high diethe
// R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war game rules
// (print 37-40)
inline int s25AlpButterfliesHi()
    { return 100; }

// the Chinese vampire call - three to eighteen foxes, the low diethe R.P.
// Smith vampire varieties (print 42) the Xochiyaoyotl war game rules (print
// 37-40)
inline int s25ChingShihFoxesLo()
    { return 3; }

// the Chinese vampire call - three to eighteen foxes, the high diethe R.P.
// Smith vampire varieties (print 42) the Xochiyaoyotl war game rules (print
// 37-40)
inline int s25ChingShihFoxesHi()
    { return 18; }

// the common wards - mirrors, garlic and crosses avoided by every typethe
// R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war game rules
// (print 37-40)
inline bool s25VampiresAvoidWards()
    { return true; }

// the common armor - normal weapons harm no vampirethe R.P. Smith vampire
// varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25NormalWeaponsNoHarm()
    { return true; }

// the common escape - gaseous form on the lost hit points, one type
// exceptedthe R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war
// game rules (print 37-40)
inline bool s25GaseousFormAllButOne()
    { return true; }

// the asanbosam end - only a cleric kills itthe R.P. Smith vampire varieties
// (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25AsanbosamClericOnly()
    { return true; }

// the burcolakas voice - any voice it hears, at the assassin detection
// oddsthe R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war game
// rules (print 37-40)
inline bool s25BurcolakasMimicVoice()
    { return true; }

// the burcolakas leash - the rats obey, the wolves neverthe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25BurcolakasNoWolves()
    { return true; }

// the lobishumen doom - a woman killed under the charm becomes a succubusthe
// R.P. Smith vampire varieties (print 42) the Xochiyaoyotl war game rules
// (print 37-40)
inline bool s25LobishumenSuccubi()
    { return true; }

// the ekimmu veil - invisible even in the attackthe R.P. Smith vampire
// varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25EkimmuInvisibleAlways()
    { return true; }

// the blautsauger gate - victims turned only by the grave earth eatenthe R.P.
// Smith vampire varieties (print 42) the Xochiyaoyotl war game rules (print
// 37-40)
inline bool s25BlautsaugerGraveEarth()
    { return true; }

// the mulo shape - horse or sheep, active day and nightthe R.P. Smith vampire
// varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25MuloPolymorphs()
    { return true; }

// the alp end - a lemon in the mouth of the corpse recipientthe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25AlpLemonDefeat()
    { return true; }

// the anananngel witch - living, beyond the cleric turnthe R.P. Smith vampire
// varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25AnananngelNotTurnedWhenLiving()
    { return true; }

// the krvopijac grave - a virgin on a black foal finds the spotthe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25KrvopijacFoalSearch()
    { return true; }

// the Chinese vampire defeat - an encirclement of ricethe R.P. Smith vampire
// varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25ChingShihRiceDefeat()
    { return true; }

// the vlkodlak sky - it causes eclipsesthe R.P. Smith vampire varieties
// (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25VlkodlakEclipses()
    { return true; }

// the vlkodlak stake - the navel pierced, never the heartthe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25VlkodlakNavelStake()
    { return true; }

// the bruxa day - a bird in sunlight, active even sothe R.P. Smith vampire
// varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25BruxaSunActive()
    { return true; }

// the nosferat shape - cat, dog, beetle, butterfly or strawthe R.P. Smith
// vampire varieties (print 42) the Xochiyaoyotl war game rules (print 37-40)
inline bool s25NosferatPolymorphs()
    { return true; }

// the printed move - the alp and the anananngel footless at zero, the
// lobishumen at fifteen, the rest at twelve
inline int s25VampMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 15;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        case 14:
            return 12;
        default:
            return -99;
        }
    }

// the second printed move - eighteen the rule, zero the asanbosam and the
// lobishumen, twenty four the fliers, the sentinel the single-move Chinese
// vampire
inline int s25VampMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 0;
        case 5:
            return 18;
        case 6:
            return 18;
        case 7:
            return 18;
        case 8:
            return 24;
        case 9:
            return 24;
        case 10:
            return 18;
        case 11:
            return -99;
        case 12:
            return 18;
        case 13:
            return 18;
        case 14:
            return 18;
        default:
            return -99;
        }
    }

// the charm adjustment - three the asanbosam and the blautsauger, four the
// lobishumen, two the catacano, the mulo, the anananngel and the nosferat,
// one the ekimmu, the sentinel the seven types the article leaves unnumbered
inline int s25VampCharmAdj(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 3;
        case 2:
            return -99;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return -99;
        case 9:
            return 2;
        case 10:
            return -99;
        case 11:
            return -99;
        case 12:
            return -99;
        case 13:
            return -99;
        case 14:
            return 2;
        default:
            return -99;
        }
    }

}   // namespace rules
