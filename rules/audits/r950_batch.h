    // ---- R950 issue-23 variant triptych audit ----
    // the three-chain variant triptych audit - the En Garde solitaire dueling
    // method, the psionic wrestling track and the Starship Warden water
    // monsters
    {
        using namespace rules;
        int bad = 0;
    if (t23DuelBasePct() != 50
            || t23DuelCeDivisor() != 4
            || t23DuelDmMax() != 15
            || t23JacquesExpertise() != 18
            || t23KarlExpertise() != 15
            || t23ExampleDm() != 3
            || t23JacquesCe() != 100
            || t23KarlCe() != 140
            || t23CeGap() != 40
            || t23ExampleModPct() != 10
            || t23JacquesHitPct() != 40
            || t23KarlHitPct() != 60
            || t23JacquesRoll() != 42
            || t23KarlRoll() != 58
            || t23KarlInjury() != 26
            || t23KarlNewCe() != 114
            || t23PhaseTwoJacquesPct() != 47
            || t23PhaseTwoKarlPct() != 53
            || t23CritNoteCount() != 5
            || t23CritBandCount() != 11
            || t23CritHitsCount() != 11
            || t23TrackSpaces() != 17
            || t23TrackEndSpace() != 8
            || t23AttackBonus() != 40
            || t23PushTwoSpacesRatio() != 3
            || t23PushMaxSpaces() != 2
            || t23AttackerLoss() != 3
            || t23DefenderLossPerSpace() != 2
            || t23CollapseThreshold() != 15
            || t23UnconsciousHours() != 12
            || t23WardenCount() != 20
            || t23OrcasStunTurns() != 6
            || t23CentipedeLiftLbs() != 1000
            || t23SeaDragonBodyFeet() != 40
            || t23SeaDragonNeckFeet() != 20
            || t23BedTentacles() != 50
            || t23MineDamageDice() != 10
            || t23DaggerPoisonPct() != 20
            || t23KrakenFeet() != 100
            || t23BrainFishStrength() != 13
            || t23SharkoidStrength() != 15
            || t23GupoidPackLow() != 300
            || t23GupoidPackHigh() != 1000
            || t23SirenTranceRounds() != 12
            || t23SeaFlyerControlPct() != 20
            || t23SeaFlyerWingspanInches() != 2
            || t23MermanLimbs() != 6
            || t23MermanLungTakePct() != 50
            || t23PeeperTableDice() != 4
            || t23PeeperTextDice() != 3
            || !t23FlowchartSolitaire()
            || !t23DuelingBreakdown()
            || !t23MidColumbiaSociety()
            || !t23CeRecomputeWounded()
            || !t23HigherExpertiseInitiative()
            || !t23SuperiorSubtractsDm()
            || !t23GrandMeleeUnderdogBlows()
            || !t23DuelHalfPractice()
            || !t23FogImage()
            || !t23CenterDeathOrSave()
            || !t23OutsideCharmNoSave()
            || !t23BonusTemporary()
            || !t23HigherStrengthFirst()
            || !t23EldritchBase()
            || !t23FloodingDoctrine()
            || !t23SaltFreshAdapt()
            || !t23SeaGriffonNoManipClaws()
            || !t23GreenDeathOxygen()
            || !t23SharkoidFlashingLight()
            || !t23TroutoidDensity()
            || !t23WaterDaggerAluminum()
            || !t23SirenCharismaNotSonic()
        )
            ++bad;
        // the critical hits grid - the eleven bands from the light leg wound
        // through the double-nought death, the light bands at base twenty or
        // twenty-five plus the small die, the serious bands at base fifty or
        // one hundred plus the large die, the die sizes converted from the
        // sixteen-sided and one-hundred-twenty-sided prints
        int CCh[11][4] = {
            {1,10,20,6},
            {11,20,20,6},
            {21,30,20,6},
            {31,40,20,6},
            {41,50,25,6},
            {51,60,50,20},
            {61,70,50,20},
            {71,80,50,20},
            {81,90,50,20},
            {91,99,100,20},
            {100,100,0,0},
            };
        for (int b = 0;
             b < t23CritHitsCount();
             ++b) {
            int vals[4];
            vals[0] = t23CritLo(b);
            vals[1] = t23CritHi(b);
            vals[2] = t23CritBase(b);
            vals[3] = t23CritDie(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CCh[b][c])
                    ++bad;
            }
        }
        // the Starship Warden water monster grid - the twenty creatures by
        // print order from the Sea Griffon through the Merman, attacks, armor
        // class, hit dice, the appearing band and the movement, the dashes
        // read as the sentinel
        int CWd[20][6] = {
            {3,6,5,1,2,23},
            {2,6,18,1,1,20},
            {1,3,2,1,4,20},
            {3,2,15,1,1,20},
            {1,4,2,1,4,20},
            {1,-99,-99,1,1,-99},
            {1,7,-99,1,1,-99},
            {-99,1,5,1,1,-99},
            {1,6,3,1,6,-99},
            {2,2,1,2,20,36},
            {9,3,10,1,1,20},
            {1,1,1,1,10,18},
            {1,1,2,1,5,18},
            {2,4,3,3,30,20},
            {1,-99,-99,300,1000,15},
            {1,6,3,1,2,20},
            {1,3,1,2,20,20},
            {2,5,12,1,1,17},
            {1,4,3,4,24,23},
            {1,5,5,1,100,25},
            };
        for (int b = 0;
             b < t23WardenCount();
             ++b) {
            int vals[6];
            vals[0] = t23WardenAttacks(b);
            vals[1] = t23WardenAc(b);
            vals[2] = t23WardenHd(b);
            vals[3] = t23WardenAppearLo(b);
            vals[4] = t23WardenAppearHi(b);
            vals[5] = t23WardenMove(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWd[b][c])
                    ++bad;
            }
        }
        // the duel frame - the fifty-percent base, the four-divisor and the
        // one-to-fifteen defense modifier the En Garde solitaire dueling
        // variant (print 5-6)
    if (t23DuelBasePct() != 50
            || t23DuelCeDivisor() != 4
            || t23DuelDmMax() != 15
            || t23FlowchartSolitaire() != 1
        )
            ++bad;
        // the worked example pair - the eighteen against fifteen expertise
        // giving the three, the one hundred against one hundred forty
        // effectiveness the En Garde solitaire dueling variant (print 5-6)
    if (t23JacquesExpertise() != 18
            || t23KarlExpertise() != 15
            || t23ExampleDm() != 3
            || t23JacquesCe() != 100
            || t23KarlCe() != 140
        )
            ++bad;
        // the probability split - the forty-point gap, the ten-percent
        // modifier and the forty against sixty hit probabilities the En Garde
        // solitaire dueling variant (print 5-6)
    if (t23CeGap() != 40
            || t23ExampleModPct() != 10
            || t23JacquesHitPct() != 40
            || t23KarlHitPct() != 60
        )
            ++bad;
        // the first phase played - the forty-two less three that hits, the
        // fifty-eight plus three that misses, the twenty-six wound and the
        // one hundred fourteen recompute the En Garde solitaire dueling
        // variant (print 5-6)
    if (t23JacquesRoll() != 42
            || t23KarlRoll() != 58
            || t23KarlInjury() != 26
            || t23KarlNewCe() != 114
        )
            ++bad;
        // the second phase - the swing to forty-seven against fifty-three,
        // the advantage moving as it happened in reality the En Garde
        // solitaire dueling variant (print 5-6)
    if (t23PhaseTwoJacquesPct() != 47
            || t23PhaseTwoKarlPct() != 53
            || t23CeRecomputeWounded() != 1
            || t23SuperiorSubtractsDm() != 1
        )
            ++bad;
        // the melee bookends - the eleven bands, the five notes, the half
        // practice session and the strength-divided-by-three underdog blows
        // the En Garde solitaire dueling variant (print 5-6)
    if (t23CritBandCount() != 11
            || t23CritNoteCount() != 5
            || t23DuelHalfPractice() != 1
            || t23GrandMeleeUnderdogBlows() != 1
        )
            ++bad;
        // the track frame - seventeen spaces, the eighth-space kill, the
        // forty-point bonus and the fifteen-point collapse the psionic
        // wrestling track (print 10)
    if (t23TrackSpaces() != 17
            || t23TrackEndSpace() != 8
            || t23AttackBonus() != 40
            || t23CollapseThreshold() != 15
        )
            ++bad;
        // the push economics - the three-to-one double push capped at two
        // spaces, the attacker losing three, the defender two per space and
        // the twelve-hour save the psionic wrestling track (print 10)
    if (t23PushTwoSpacesRatio() != 3
            || t23PushMaxSpaces() != 2
            || t23AttackerLoss() != 3
            || t23DefenderLossPerSpace() != 2
            || t23UnconsciousHours() != 12
        )
            ++bad;
        // the track stakes - the center marker death or save, the outside
        // marker charm with no save, the temporary bonus and the stretchable
        // fog the psionic wrestling track (print 10)
    if (t23CenterDeathOrSave() != 1
            || t23OutsideCharmNoSave() != 1
            || t23BonusTemporary() != 1
            || t23FogImage() != 1
        )
            ++bad;
        // the roster frame - twenty creatures riding the flooding doctrine
        // and the salt-or-fresh adaptation rationale the Starship Warden
        // water monsters (print 11, 13)
    if (t23WardenCount() != 20
            || t23FloodingDoctrine() != 1
            || t23SaltFreshAdapt() != 1
        )
            ++bad;
        // the monster dimensions - the six-turn orcas stun, the
        // thousand-pound telekinesis, the forty-plus-twenty sea dragon and
        // the fifty tentacles the Starship Warden water monsters (print 11,
        // 13)
    if (t23OrcasStunTurns() != 6
            || t23CentipedeLiftLbs() != 1000
            || t23SeaDragonBodyFeet() != 40
            || t23SeaDragonNeckFeet() != 20
            || t23BedTentacles() != 50
        )
            ++bad;
        // the danger quartet - the hundred-foot kraken, the ten-dice mine,
        // the twenty-percent poison dagger and the twelve-round siren trance
        // the Starship Warden water monsters (print 11, 13)
    if (t23KrakenFeet() != 100
            || t23MineDamageDice() != 10
            || t23DaggerPoisonPct() != 20
            || t23SirenTranceRounds() != 12
        )
            ++bad;
        // the mental and the mass - the thirteen and fifteen mental strengths
        // and the three-hundred-to-thousand gupoid packs the Starship Warden
        // water monsters (print 11, 13)
    if (t23BrainFishStrength() != 13
            || t23SharkoidStrength() != 15
            || t23GupoidPackLow() != 300
            || t23GupoidPackHigh() != 1000
        )
            ++bad;
        // the small wonders - the two-inch controlled sea flyer, the
        // six-limbed lung-taking merman and the peeper four-dice table
        // against its three-dice text the Starship Warden water monsters
        // (print 11, 13)
    if (t23SeaFlyerControlPct() != 20
            || t23SeaFlyerWingspanInches() != 2
            || t23MermanLimbs() != 6
            || t23MermanLungTakePct() != 50
            || t23PeeperTableDice() != 4
            || t23PeeperTextDice() != 3
        )
            ++bad;
        // the critical hits spot check - the light leg band and the
        // twenty-five-base light body the En Garde solitaire dueling variant
        // (print 5-6)
    if (t23CritLo(0) != 1
            || t23CritHi(0) != 10
            || t23CritBase(0) != 20
            || t23CritDie(0) != 6
            || t23CritBase(4) != 25
            || t23CritDie(4) != 6
        )
            ++bad;
        // the serious bands - the fifty-base leg at the twenty die and the
        // one-hundred-base body the En Garde solitaire dueling variant (print
        // 5-6)
    if (t23CritLo(5) != 51
            || t23CritBase(5) != 50
            || t23CritDie(5) != 20
            || t23CritBase(9) != 100
            || t23CritDie(9) != 20
        )
            ++bad;
        // the death row - the double-nought read as the one-hundred band with
        // no base and no die the En Garde solitaire dueling variant (print
        // 5-6)
    if (t23CritLo(10) != 100
            || t23CritHi(10) != 100
            || t23CritBase(10) != 0
            || t23CritDie(10) != 0
        )
            ++bad;
        // the sea griffon row - three attacks, armor class six, five dice,
        // the one-to-two band and the twenty-three move the Starship Warden
        // water monsters (print 11, 13)
    if (t23WardenAttacks(0) != 3
            || t23WardenAc(0) != 6
            || t23WardenHd(0) != 5
            || t23WardenAppearLo(0) != 1
            || t23WardenAppearHi(0) != 2
            || t23WardenMove(0) != 23
        )
            ++bad;
        // the kraken and sharkoid rows - nine attacks at ten dice, the pair
        // at twelve dice the Starship Warden water monsters (print 11, 13)
    if (t23WardenAttacks(10) != 9
            || t23WardenHd(10) != 10
            || t23WardenAttacks(17) != 2
            || t23WardenHd(17) != 12
        )
            ++bad;
        // the sentinel rows - the green death and the gupoid pack carry the
        // sentinel armor and dice the Starship Warden water monsters (print
        // 11, 13)
    if (t23WardenAc(5) != -99
            || t23WardenHd(5) != -99
            || t23WardenAc(14) != -99
            || t23WardenAppearLo(14) != 300
            || t23WardenAppearHi(14) != 1000
        )
            ++bad;
        // the odd movers - the craboid thirty-six fly, the merman twenty-five
        // mounted and the sharkoid seventeen the Starship Warden water
        // monsters (print 11, 13)
    if (t23WardenMove(9) != 36
            || t23WardenMove(19) != 25
            || t23WardenMove(17) != 17
        )
            ++bad;
        printf("R950 issue-23 variant triptych audit: bad %d\n", bad);
        if (bad) return 1;
    }
