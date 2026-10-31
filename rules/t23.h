// =========================================================================================
// Adnd1 - rules/t23.h
// The Dragon issue-23 opener part one - the variant triptych
// census 872 -> 873.
//
// The opener of the issue-23 four-round shape - three of the ten
// Curtiss-called chains pinned as the variant triptych, the lower-planes DMG
// preview riding its own part-two table round, the commentary set at part
// three and the flip to follow. All pinned from The Dragon Vol. III No. 9
// (March 1979) print 5-13 at extract/dragon/023, PRINT FOLIO = PDF PAGE this
// issue, the transcript of the Curtiss-provided scan. The intake seats the
// gap report and all thirty-two transcripts; the two inherited watches - the
// Sullin levels 7-9 and the brawling sequel - print nowhere in issue 23 and
// ride to TD 24.
//
namespace rules {

// ---- the En Garde solitaire dueling variant (print 5-6) ----

// the underlying assumption - between equals each stands an equal chance, the
// basic fifty-percent hit probability the En Garde solitaire dueling variant
// (print 5-6)
inline int t23DuelBasePct()
    { return 50; }

// the CE difference is divided by four to find the hit probability modifier
// the En Garde solitaire dueling variant (print 5-6)
inline int t23DuelCeDivisor()
    { return 4; }

// the defense modifier - a whole number ranging from one to fifteen the En
// Garde solitaire dueling variant (print 5-6)
inline int t23DuelDmMax()
    { return 15; }

// the worked example - Jaques dUberville with an expertise factor of eighteen
// the En Garde solitaire dueling variant (print 5-6)
inline int t23JacquesExpertise()
    { return 18; }

// against Karl von Badenhaus with an expertise of fifteen the En Garde
// solitaire dueling variant (print 5-6)
inline int t23KarlExpertise()
    { return 15; }

// the defense modifier for both duelists - eighteen minus fifteen the En
// Garde solitaire dueling variant (print 5-6)
inline int t23ExampleDm()
    { return 3; }

// the weaker opponent by combat effectiveness - Jacques at one hundred the En
// Garde solitaire dueling variant (print 5-6)
inline int t23JacquesCe()
    { return 100; }

// against the stronger Karl at one hundred forty the En Garde solitaire
// dueling variant (print 5-6)
inline int t23KarlCe()
    { return 140; }

// the difference between them in CE points the En Garde solitaire dueling
// variant (print 5-6)
inline int t23CeGap()
    { return 40; }

// the forty-point gap divided by four gives a ten-percent modifier the En
// Garde solitaire dueling variant (print 5-6)
inline int t23ExampleModPct()
    { return 10; }

// the superior-skill weaker man hits on one to forty percent the En Garde
// solitaire dueling variant (print 5-6)
inline int t23JacquesHitPct()
    { return 40; }

// the stronger man hits on one to sixty percent the En Garde solitaire
// dueling variant (print 5-6)
inline int t23KarlHitPct()
    { return 60; }

// the superior duelist rolls forty-two, subtracts the defense modifier for
// thirty-nine and scores a light head wound the En Garde solitaire dueling
// variant (print 5-6)
inline int t23JacquesRoll()
    { return 42; }

// the inferior duelist rolls fifty-eight, adds the modifier for sixty-one and
// misses the En Garde solitaire dueling variant (print 5-6)
inline int t23KarlRoll()
    { return 58; }

// the light head wound - base twenty plus a die roll of six the En Garde
// solitaire dueling variant (print 5-6)
inline int t23KarlInjury()
    { return 26; }

// the wounded Karl recomputed to one hundred fourteen the En Garde solitaire
// dueling variant (print 5-6)
inline int t23KarlNewCe()
    { return 114; }

// the second-phase recompute - Jacques now hits on one to forty-seven the En
// Garde solitaire dueling variant (print 5-6)
inline int t23PhaseTwoJacquesPct()
    { return 47; }

// while Karl scores on one to fifty-three the En Garde solitaire dueling
// variant (print 5-6)
inline int t23PhaseTwoKarlPct()
    { return 53; }

// the five printed table notes - defend-only-next-phase, expertise halved,
// expertise quartered, strength halved and the non-player surrender the En
// Garde solitaire dueling variant (print 5-6)
inline int t23CritNoteCount()
    { return 5; }

// the band floor of the modified die roll - one, eleven, twenty-one through
// the double-nought read as one hundred
inline int t23CritLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 21;
        case 3:
            return 31;
        case 4:
            return 41;
        case 5:
            return 51;
        case 6:
            return 61;
        case 7:
            return 71;
        case 8:
            return 81;
        case 9:
            return 91;
        case 10:
            return 100;
        default:
            return -99;
        }
    }

// the band ceiling - ten, twenty, thirty through ninety-nine and one hundred
// at the death row
inline int t23CritHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 40;
        case 4:
            return 50;
        case 5:
            return 60;
        case 6:
            return 70;
        case 7:
            return 80;
        case 8:
            return 90;
        case 9:
            return 99;
        case 10:
            return 100;
        default:
            return -99;
        }
    }

// the damage base - twenty for the five light bands, twenty-five for the
// light body, fifty for the four serious bands and one hundred for the
// serious body, zero at the death row
inline int t23CritBase(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 25;
        case 5:
            return 50;
        case 6:
            return 50;
        case 7:
            return 50;
        case 8:
            return 50;
        case 9:
            return 100;
        case 10:
            return 0;
        default:
            return -99;
        }
    }

// the damage die - the print says sixteen-sided for the light bands and
// one-hundred-twenty-sided for the serious, the worked example proves six and
// twenty (Karl takes twenty plus six for twenty-six), conversion noted
inline int t23CritDie(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 0;
        default:
            return -99;
        }
    }

// the eleven critical hit bands from the light leg wound through the
// double-nought death the En Garde solitaire dueling variant (print 5-6)
inline int t23CritBandCount()
    { return 11; }

// the eleven critical hit bands by print order - light leg, light left arm,
// light right arm, light head, light body, serious leg, serious left arm,
// serious right arm, serious head, serious body, dead the En Garde solitaire
// dueling variant (print 5-6)
inline int t23CritHitsCount()
    { return 11; }

// the game system laid out in flow-chart fashion - yes-no monthly actions
// from courting to the bawdyhouse the En Garde solitaire dueling variant
// (print 5-6)
inline bool t23FlowchartSolitaire()
    { return true; }

// the only breakdown point - dueling always requires another player and
// secretly written sequenced actions the En Garde solitaire dueling variant
// (print 5-6)
inline bool t23DuelingBreakdown()
    { return true; }

// the Mid-Columbia Wargaming Society of Richland Washington substitutes the
// shorthand dueling method the En Garde solitaire dueling variant (print 5-6)
inline bool t23MidColumbiaSociety()
    { return true; }

// the combat effectiveness is recomputed every time a duelist is wounded the
// En Garde solitaire dueling variant (print 5-6)
inline bool t23CeRecomputeWounded()
    { return true; }

// the higher expertise factor always has the initiative - and a player
// character always holds it against a non-player the En Garde solitaire
// dueling variant (print 5-6)
inline bool t23HigherExpertiseInitiative()
    { return true; }

// the superior duelist subtracts the defense modifier from his die roll, the
// inferior adds it the En Garde solitaire dueling variant (print 5-6)
inline bool t23SuperiorSubtractsDm()
    { return true; }

// the grand melee underdog gains blows per phase equal to his strength
// divided by three the En Garde solitaire dueling variant (print 5-6)
inline bool t23GrandMeleeUnderdogBlows()
    { return true; }

// each duel counts as one-half of a free practice session, whether or not the
// character wins the En Garde solitaire dueling variant (print 5-6)
inline bool t23DuelHalfPractice()
    { return true; }

// ---- the psionic wrestling track (print 10) ----

// the double track - seventeen spaces long, the center and the flank the
// psionic wrestling track (print 10)
inline int t23TrackSpaces()
    { return 17; }

// to win a player must force a marker into the opponent's space number eight
// the psionic wrestling track (print 10)
inline int t23TrackEndSpace()
    { return 8; }

// the attacker's total psionic strength is increased by forty points or
// doubled, whichever is less the psionic wrestling track (print 10)
inline int t23AttackBonus()
    { return 40; }

// a ratio of three to one moves the proper marker two spaces the psionic
// wrestling track (print 10)
inline int t23PushTwoSpacesRatio()
    { return 3; }

// higher ratios do not have higher effects - two spaces is the maximum
// possible retreat the psionic wrestling track (print 10)
inline int t23PushMaxSpaces()
    { return 2; }

// after each exchange the attacker loses three points the psionic wrestling
// track (print 10)
inline int t23AttackerLoss()
    { return 3; }

// the defender loses two times the number of spaces fallen back the psionic
// wrestling track (print 10)
inline int t23DefenderLossPerSpace()
    { return 2; }

// a psionic strength falling below fifteen means the loss of the battle and a
// roll on the battle-loser table the psionic wrestling track (print 10)
inline int t23CollapseThreshold()
    { return 15; }

// the center-marker loss - instant death, or unconsciousness for one to
// twelve hours if the saving throw succeeds the psionic wrestling track
// (print 10)
inline int t23UnconsciousHours()
    { return 12; }

// the visual - a glowing sheet of stretchable fog pushed back and forth
// between the combatants the psionic wrestling track (print 10)
inline bool t23FogImage()
    { return true; }

// the center marker forced home means instant death or the save-throw
// unconsciousness the psionic wrestling track (print 10)
inline bool t23CenterDeathOrSave()
    { return true; }

// the outside marker forced home means the victim is charmed with no saving
// throw the psionic wrestling track (print 10)
inline bool t23OutsideCharmNoSave()
    { return true; }

// the forty-point increase is temporary - the strength drops back to normal
// after the comparison the psionic wrestling track (print 10)
inline bool t23BonusTemporary()
    { return true; }

// the player with the higher psionic strength attacks first, then strict
// alternation the psionic wrestling track (print 10)
inline bool t23HigherStrengthFirst()
    { return true; }

// the variant rides on the psionic combat of the third supplement - the
// losing roll comes from that battle-loser table the psionic wrestling track
// (print 10)
inline bool t23EldritchBase()
    { return true; }

// ---- the Starship Warden water monsters (print 11, 13) ----

// the number of attacks - three for the sea griffon and dragon, nine
// tentacles and beak for the kraken, the water dagger has none
inline int t23WardenAttacks(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return -99;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 9;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 1;
        default:
            return -99;
        }
    }

// the armor class - six for the sea griffon through one for the water dagger,
// oysteroid and peeper, the green death and gupoids carry the sentinel
inline int t23WardenAc(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return -99;
        case 6:
            return 7;
        case 7:
            return 1;
        case 8:
            return 6;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 4;
        case 14:
            return -99;
        case 15:
            return 6;
        case 16:
            return 3;
        case 17:
            return 5;
        case 18:
            return 4;
        case 19:
            return 5;
        default:
            return -99;
        }
    }

// the hit dice - eighteen for the orcas, fifteen for the sea dragon, twelve
// for the sharkoid, ten for the kraken, the cluster and patch creatures carry
// the sentinel
inline int t23WardenHd(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 18;
        case 2:
            return 2;
        case 3:
            return 15;
        case 4:
            return 2;
        case 5:
            return -99;
        case 6:
            return -99;
        case 7:
            return 5;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return 10;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return -99;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 12;
        case 18:
            return 3;
        case 19:
            return 5;
        default:
            return -99;
        }
    }

// the appearing band floor - one for most, two for the craboid and sea flyer,
// three hundred for the gupoids
inline int t23WardenAppearLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 300;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 4;
        case 19:
            return 1;
        default:
            return -99;
        }
    }

// the appearing band ceiling - one hundred for the merman pack, one thousand
// for the gupoids, the single creatures at one
inline int t23WardenAppearHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 6;
        case 9:
            return 20;
        case 10:
            return 1;
        case 11:
            return 10;
        case 12:
            return 5;
        case 13:
            return 30;
        case 14:
            return 1000;
        case 15:
            return 2;
        case 16:
            return 20;
        case 17:
            return 1;
        case 18:
            return 24;
        case 19:
            return 100;
        default:
            return -99;
        }
    }

// the movement - twenty-three for the sea griffon, thirty-six fly for the
// craboid noted against walk three and swim ten, twenty-five mounted for the
// merman noted against five swimming, the immobile creatures carry the
// sentinel
inline int t23WardenMove(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return -99;
        case 6:
            return -99;
        case 7:
            return -99;
        case 8:
            return -99;
        case 9:
            return 36;
        case 10:
            return 20;
        case 11:
            return 18;
        case 12:
            return 18;
        case 13:
            return 20;
        case 14:
            return 15;
        case 15:
            return 20;
        case 16:
            return 20;
        case 17:
            return 17;
        case 18:
            return 23;
        case 19:
            return 25;
        default:
            return -99;
        }
    }

// the twenty water creatures of the monster roster, from the Sea Griffon
// through the Merman the Starship Warden water monsters (print 11, 13)
inline int t23WardenCount()
    { return 20; }

// the orcas directional spout stuns for one to six turns the Starship Warden
// water monsters (print 11, 13)
inline int t23OrcasStunTurns()
    { return 6; }

// the sea centipede lifts one thousand pounds with its telekinesis the
// Starship Warden water monsters (print 11, 13)
inline int t23CentipedeLiftLbs()
    { return 1000; }

// the one-time sea turtle is about forty feet long the Starship Warden water
// monsters (print 11, 13)
inline int t23SeaDragonBodyFeet()
    { return 40; }

// with an additional twenty feet of neck the Starship Warden water monsters
// (print 11, 13)
inline int t23SeaDragonNeckFeet()
    { return 20; }

// the bed of spikes has approximately fifty tentacles the Starship Warden
// water monsters (print 11, 13)
inline int t23BedTentacles()
    { return 50; }

// the mine - free-floating leather coral exploding for ten dice of damage the
// Starship Warden water monsters (print 11, 13)
inline int t23MineDamageDice()
    { return 10; }

// the water dagger carries a twenty percent chance of poison the Starship
// Warden water monsters (print 11, 13)
inline int t23DaggerPoisonPct()
    { return 20; }

// the kraken octopus runs up to one hundred feet with a total carapace the
// Starship Warden water monsters (print 11, 13)
inline int t23KrakenFeet()
    { return 100; }

// the brain fish mental attack strength of thirteen, printed truncated as
// stre the Starship Warden water monsters (print 11, 13)
inline int t23BrainFishStrength()
    { return 13; }

// the sharkoid mental blast strength of fifteen the Starship Warden water
// monsters (print 11, 13)
inline int t23SharkoidStrength()
    { return 15; }

// the gupoid packs run from three hundred the Starship Warden water monsters
// (print 11, 13)
inline int t23GupoidPackLow()
    { return 300; }

// to one thousand fish the Starship Warden water monsters (print 11, 13)
inline int t23GupoidPackHigh()
    { return 1000; }

// the siren trance holds for one to twelve melee rounds, treated as a poison
// save the Starship Warden water monsters (print 11, 13)
inline int t23SirenTranceRounds()
    { return 12; }

// the sea flyer holds a twenty percent chance of already controlling a
// creature when encountered the Starship Warden water monsters (print 11, 13)
inline int t23SeaFlyerControlPct()
    { return 20; }

// the mutated manta rays average two inches in wingspan the Starship Warden
// water monsters (print 11, 13)
inline int t23SeaFlyerWingspanInches()
    { return 2; }

// the merman has six crab-like limbs, two of them manipulative claws the
// Starship Warden water monsters (print 11, 13)
inline int t23MermanLimbs()
    { return 6; }

// captured player characters have their lungs taken for gills half the time
// the Starship Warden water monsters (print 11, 13)
inline int t23MermanLungTakePct()
    { return 50; }

// the peeper radiated eyes in the table - four to twenty-four, four dice the
// Starship Warden water monsters (print 11, 13)
inline int t23PeeperTableDice()
    { return 4; }

// the same attack in the text - three dice worth of damage, both pinned the
// Starship Warden water monsters (print 11, 13)
inline int t23PeeperTextDice()
    { return 3; }

// the flooding doctrine - an entire level can flood, drowning the unwary at
// the elevator door the Starship Warden water monsters (print 11, 13)
inline bool t23FloodingDoctrine()
    { return true; }

// the salt-or-fresh rationale - the radiation could have turned the water
// either way and the fish adapted the Starship Warden water monsters (print
// 11, 13)
inline bool t23SaltFreshAdapt()
    { return true; }

// the sea griffon cannot use most technology - it has no manipulative claws
// the Starship Warden water monsters (print 11, 13)
inline bool t23SeaGriffonNoManipClaws()
    { return true; }

// the green death dies only to the protein disrupter or exposure to oxygen
// the Starship Warden water monsters (print 11, 13)
inline bool t23GreenDeathOxygen()
    { return true; }

// the sharkoid is epileptic - a flashing light renders it fairly harmless the
// Starship Warden water monsters (print 11, 13)
inline bool t23SharkoidFlashingLight()
    { return true; }

// the troutoid density control - it drops like a rock or floats to avoid
// predators the Starship Warden water monsters (print 11, 13)
inline bool t23TroutoidDensity()
    { return true; }

// the water dagger is staghorn coral covered with aluminum the Starship
// Warden water monsters (print 11, 13)
inline bool t23WaterDaggerAluminum()
    { return true; }

// the siren uses a charismatic effect rather than sonics - gills negate
// sonics the Starship Warden water monsters (print 11, 13)
inline bool t23SirenCharismaNotSonic()
    { return true; }

}   // namespace rules
