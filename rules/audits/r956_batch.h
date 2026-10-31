    // ---- R956 issue-24 commentary set audit ----
    // the ten-chain commentary set audit - the magic-user limits, the Roman
    // maniples, the Viking scenarios, the melee rationale, the DUNGEON
    // variations, the Swiss phalanxes, the psionic professions, the disease
    // charts, the Petal Throne name grid and the Monty Haul satire
    {
        using namespace rules;
        int bad = 0;
    if (k24ConcentrationDamage() != 1
            || k24DurationTurnsPerLevel() != 1
            || k24WildernessWeeks() != 1
            || k24TdMinPayment() != 1
            || k24EarlyHastati() != 900
            || k24HastatiManiples() != 16
            || k24ManipleMen() != 60
            || k24EarlyPrincipes() != 900
            || k24OrdoLines() != 15
            || k24VexillaPerOrdo() != 3
            || k24VexillaMen() != 62
            || k24TriariiMorale() != 9
            || k24RorariiMorale() != 7
            || k24AccensiMorale() != 3
            || k24RearAttackMorale() != 5
            || k24EquitesAla() != 300
            || k24LaterManipleMen() != 120
            || k24JulianCentury() != 60
            || k24MixedUnitMorale() != 7
            || k24CampaignYear() != 954
            || k24VikingShips() != 24
            || k24VikingWarriors() != 1200
            || k24CityPopulation() != 10000
            || k24RansomDirhems() != 20
            || k24SpareCaptives() != 10000
            || k24MarzubanArmy() != 30000
            || k24FallenVikings() != 700
            || k24SiegeDailemites() != 500
            || k24SiegeKurdishHorse() != 1500
            || k24SiegeVolunteers() != 2000
            || k24VikingMorale() != 10
            || k24CommanderAdd() != 3
            || k24ShieldWallAdd() != 1
            || k24ArabArcherySub() != 5
            || k24ShieldWallArcherySub() != 10
            || k24KillNum() != 3
            || k24KillDen() != 2
            || k24OccupationTroops() != 500
            || k24ScnCount() != 3
            || k24MeleeSegments() != 10
            || k24SegmentSeconds() != 6
            || k24AudienceSize() != 100000
            || k24CriticsLow() != 1
            || k24CriticsHigh() != 5
            || k24DoorWidth() != 5
            || k24DoorJamLo() != 1
            || k24DoorJamHi() != 2
            || k24DoorAttackAdd() != 4
            || k24DoorSaveSub() != 4
            || k24FemalePlayersPct() != 10
            || k24GnollParty() != 8
            || k24RhinoDice() != 8
            || k24RhinoHp() != 72
            || k24FighterHp() != 76
            || k24NonWizardMove() != 10
            || k24WizardMove() != 5
            || k24TransferMonsterRoll() != 8
            || k24ChamberCapacity() != 3
            || k24PermanentKillRoll() != 12
            || k24MonsterMove() != 5
            || k24BeastCombatRoll() != 8
            || k24XferElf() != 4
            || k24XferHero() != 5
            || k24XferSuperhero() != 6
            || k24XferWizard() != 7
            || k24NeRollHi() != 10
            || k24NaturalRoll() != 11
            || k24MonsterRoll() != 12
            || k24FloodSave() != 6
            || k24PoisonGasSave() != 6
            || k24ExplosiveGasSave() != 8
            || k24CeilingBoltRoll() != 8
            || k24PartyGold() != 35000
            || k24OccCount() != 5
            || k24PikeLow() != 16
            || k24PikeHigh() != 18
            || k24SwissPikeFeet() != 21
            || k24SwissPikeSteel() != 3
            || k24HandgunLow() != 80
            || k24HandgunHigh() != 100
            || k24SkirmishLow() != 10
            || k24SkirmishHigh() != 30
            || k24PhalanxCount() != 3
            || k24IntuitionPct() != 15
            || k24IntuitionMax() != 90
            || k24EctoplasmAc() != 9
            || k24EctoplasmSpeed() != 12
            || k24EctoplasmRange() != 48
            || k24ColdRadius() != 1
            || k24ColdDegrees() != 100
            || k24ColdCost() != 10
            || k24MagnetismWeight() != 3
            || k24MagnetismRange() != 5
            || k24ElectricityLevel() != 4
            || k24GravityRadius() != 5
            || k24GravityFold() != 5
            || k24RetroWeekCost() != 2
            || k24HyperPct() != 10
            || k24TransferPct() != 10
            || k24TransferCost() != 5
            || k24SpeakCost() != 10
            || k24InfravisionCost() != 5
            || k24LightCost() != 2
            || k24StunRange() != 10
            || k24StunSpeedDiv() != 3
            || k24NeuralPerPoints() != 5
            || k24SpiritCost() != 10
            || k24MeldCost() != 5
            || k24ShieldCost() != 2
            || k24DartRange() != 10
            || k24GreaterFloor() != 91
            || k24AntiPsiGap() != 5
            || k24SubsentientCount() != 8
            || k24AntiPsiCount() != 6
            || k24FatalDays92() != 48
            || k24FatalMonths97() != 7
            || k24FatalMonths99() != 9
            || k24FatalMonths00() != 10
            || k24SymptomCount() != 20
            || k24FatalCount() != 29
            || k24SymptomBandCount() != 4
            || k24NameGridSide() != 8
            || k24NameSegments() != 64
            || k24NameDiceSides() != 8
            || k24EuphonicLow() != 2
            || k24EuphonicHigh() != 3
            || k24BronzeHands() != 80
            || k24DragonAge() != 500
            || k24TreasureValue() != 1000000
            || k24WizardLevel() != 16
            || k24WizardCount() != 5
            || k24FireballDice() != 29
            || k24AltarLadies() != 7
            || k24LadiesSlain() != 2
            || k24DeathRayCount() != 5
            || !k24SpecialtiesIdea()
            || !k24FailureFactorRejected()
            || !k24SaveUnmanifested()
            || !k24InherentResistance()
            || !k24ConcentrationRule()
            || !k24DexterityCarryover()
            || !k24DurationRule()
            || !k24WildernessDayTurns()
            || !k24DefensesNotAdded()
            || !k24ArtifactSpellCombo()
            || !k24TdWritersCall()
            || !k24LiteratePrint()
            || !k24LivyEarlyLegion()
            || !k24OrdoPhalanx()
            || !k24MoraleEngagedFace()
            || !k24FrontRankMoraleDrop()
            || !k24MountingError()
            || !k24CheckeredArray()
            || !k24FlankStands()
            || !k24GladiusChange()
            || !k24HeavyPilum()
            || !k24VelitesJavelins()
            || !k24JulianLights()
            || !k24MercenaryMixing()
            || !k24DeArtBellicaPrint()
            || !k24LundstromHelmet()
            || !k24PolybiusSources()
            || !k24TractacsPrint()
            || !k24FinieousVacation()
            || !k24MiskaiyahSource()
            || !k24KhazarPassage()
            || !k24SwineArray()
            || !k24BardaDrift()
            || !k24SharistanDrift()
            || !k24KrudishPrint()
            || !k24UnguessedPrint()
            || !k24BeseigarsPrint()
            || !k24TheyKnowPrint()
            || !k24PomiardPrint()
            || !k24TroopPrint()
            || !k24AffectPrint()
            || !k24NeverSurrender()
            || !k24FerocityFree()
            || !k24MountedRule()
            || !k24CampDesertion()
            || !k24DeathOfMaterials()
            || !k24IbnSamun()
            || !k24ChieftainSon()
            || !k24DesecratedGraves()
            || !k24TurnbullLetter()
            || !k24HighlevelPrint()
            || !k24TwoOfMorePrint()
            || !k24EightOfNinePrint()
            || !k24HisOfHerPrint()
            || !k24ProtectedPrint()
            || !k24DuplicatePhrase()
            || !k24SayThemMayPrint()
            || !k24JavelinGarble()
            || !k24ParticularPrint()
            || !k24RivalsPrint()
            || !k24HitPointsRationale()
            || !k24KuntzSystem()
            || !k24DoubleDamage()
            || !k24ClearyLetter()
            || !k24KoboldRatio()
            || !k24JavelinTrajectory()
            || !k24WeaponProficiency()
            || !k24DesignDepartment()
            || !k24TransferChamber()
            || !k24TransferOffensive()
            || !k24MagicalReply()
            || !k24SubdueRule()
            || !k24ChamberRefuge()
            || !k24MonsterHealing()
            || !k24PrizeReturn()
            || !k24NonWizardResubdue()
            || !k24WizardControl()
            || !k24MonsterArmies()
            || !k24DeadPile()
            || !k24CaveInPlacement()
            || !k24BuriedTreasure()
            || !k24SealedDeath()
            || !k24PartyCombatOrder()
            || !k24WizardRoomSpell()
            || !k24PartyVictoryRule()
            || !k24AmbushForbidden()
            || !k24MidColumbia()
            || !k24ThreeWeapons()
            || !k24HalberdVictims()
            || !k24HalberdShape()
            || !k24SturdyComma()
            || !k24BraveryPrint()
            || !k24TellSplice()
            || !k24EchelonContradiction()
            || !k24PhalanxTasks()
            || !k24OffenseVsCavalry()
            || !k24LandsknechtDuels()
            || !k24PoorUnarmored()
            || !k24VaticanStripes()
            || !k24ArtilleryDownfall()
            || !k24FrenchService()
            || !k24NextCondotiere()
            || !k24GygasPrint()
            || !k24BonewitsPrint()
            || !k24ClairensesPrint()
            || !k24ProjectionTwicePrint()
            || !k24PsychicsPrint()
            || !k24SpearPrint()
            || !k24SigPrint()
            || !k24SuperIntuitivePrint()
            || !k24HalfilePrint()
            || !k24AdjacentAcquisition()
            || !k24KineticAssignment()
            || !k24DruidException()
            || !k24EwFormsUnchanged()
            || !k24StunSleep()
            || !k24BuettuerPrint()
            || !k24FatalitySkips98()
            || !k24DiseasePurpose()
            || !k24SaveThenRecover()
            || !k24SymptomList()
            || !k24RahmanByline()
            || !k24TocMismatch()
            || !k24VerifiedPermutation()
            || !k24BarkerSources()
            || !k24JakallaFillers()
            || !k24ExampleNames()
            || !k24BronzeError()
            || !k24ArchduredPrint()
            || !k24PlalinPrint()
            || !k24DeomonPrint()
            || !k24PowerPrint()
            || !k24DiePrint()
            || !k24DruddyPrint()
            || !k24DispellPrint()
            || !k24CutOutPrint()
            || !k24GamersPrint()
            || !k24HarpDatcord()
            || !k24RodOfSeven()
            || !k24PortableHole()
            || !k24DemonSkinSword()
            || !k24SummonedMonsters()
            || !k24ArtifactFinale()
            || !k24PriestessEscape()
            || !k24VineFinale()
        )
            ++bad;
        // the three scenario orders of battle - the Battle for Barda-a, the
        // Second Battle and Sultan Marzuban versus the Vikings - the Viking
        // Caspian campaign (print 13-16)
        int CVn[3][3] = {
            {900,18,5100},
            {850,17,1275},
            {800,16,14600},
            };
        for (int b = 0;
             b < k24ScnCount();
             ++b) {
            int vals[3];
            vals[0] = k24ScnVikings(b);
            vals[1] = k24ScnSubs(b);
            vals[2] = k24ScnArabLine(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CVn[b][c])
                    ++bad;
            }
        }
        // the natural occurrence table - bats, flood, poison gas, explosive
        // gas and cave-in bands - the DUNGEON board game variations (print
        // 22-25)
        int COc[5][2] = {
            {2,4},
            {5,6},
            {7,8},
            {9,10},
            {11,12},
            };
        for (int b = 0;
             b < k24OccCount();
             ++b) {
            int vals[2];
            vals[0] = k24OccLo(b);
            vals[1] = k24OccHi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != COc[b][c])
                    ++bad;
            }
        }
        // the subsentient telepathy costs - plants twice as printed, six and
        // eight - the psionics profession variant (print 28-29)
        int CSb[8][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            };
        for (int b = 0;
             b < k24SubsentientCount();
             ++b) {
            int vals[1];
            vals[0] = k24SubsentientCost(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CSb[b][c])
                    ++bad;
            }
        }
        // the Anti-Psi ladder of power costs - Deflection through Tuning -
        // the psionics profession variant (print 28-29)
        int CAp[6][1] = {
            {5},
            {10},
            {15},
            {20},
            {25},
            {25},
            };
        for (int b = 0;
             b < k24AntiPsiCount();
             ++b) {
            int vals[1];
            vals[0] = k24AntiPsiCost(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CAp[b][c])
                    ++bad;
            }
        }
        // the fatality bands - immediate through ten months, the ninety-eight
        // skip pinned - the disease charts (print 29)
        int CFa[29][2] = {
            {1,1},
            {2,2},
            {3,3},
            {4,4},
            {5,5},
            {6,6},
            {7,7},
            {8,8},
            {9,9},
            {10,15},
            {16,20},
            {21,25},
            {26,30},
            {31,40},
            {41,50},
            {51,60},
            {61,70},
            {71,80},
            {81,89},
            {90,90},
            {91,91},
            {92,92},
            {93,93},
            {94,94},
            {95,95},
            {96,96},
            {97,97},
            {99,99},
            {100,100},
            };
        for (int b = 0;
             b < k24FatalCount();
             ++b) {
            int vals[2];
            vals[0] = k24FatalLo(b);
            vals[1] = k24FatalHi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CFa[b][c])
                    ++bad;
            }
        }
        // the symptom-number bands - one-three for one symptom through eight
        // for four - the disease charts (print 29)
        int CSy[4][2] = {
            {3,1},
            {5,2},
            {7,3},
            {8,4},
            };
        for (int b = 0;
             b < k24SymptomBandCount();
             ++b) {
            int vals[2];
            vals[0] = k24SymBandHi(b);
            vals[1] = k24SymBandNum(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CSy[b][c])
                    ++bad;
            }
        }
        // the four limiting variants - the magic-user limiting variants
        // (print 7)
    if (k24ConcentrationDamage() != 1
            || k24DurationTurnsPerLevel() != 1
            || k24WildernessWeeks() != 1
            || k24TdMinPayment() != 1
        )
            ++bad;
        // the Livian manipular legion numbers - the Roman military update
        // (print 12)
    if (k24EarlyHastati() != 900
            || k24HastatiManiples() != 16
            || k24ManipleMen() != 60
            || k24EarlyPrincipes() != 900
            || k24OrdoLines() != 15
            || k24VexillaPerOrdo() != 3
            || k24VexillaMen() != 62
        )
            ++bad;
        // the legion morale and mounting numbers - the Roman military update
        // (print 12)
    if (k24TriariiMorale() != 9
            || k24RorariiMorale() != 7
            || k24AccensiMorale() != 3
            || k24RearAttackMorale() != 5
            || k24EquitesAla() != 300
            || k24LaterManipleMen() != 120
            || k24JulianCentury() != 60
            || k24MixedUnitMorale() != 7
        )
            ++bad;
        // the campaign narrative numbers - the Viking Caspian campaign (print
        // 13-16)
    if (k24CampaignYear() != 954
            || k24VikingShips() != 24
            || k24VikingWarriors() != 1200
            || k24RansomDirhems() != 20
            || k24SpareCaptives() != 10000
            || k24MarzubanArmy() != 30000
            || k24FallenVikings() != 700
        )
            ++bad;
        // the morale and victory-condition numbers - the Viking Caspian
        // campaign (print 13-16)
    if (k24VikingMorale() != 10
            || k24CommanderAdd() != 3
            || k24ShieldWallAdd() != 1
            || k24ArabArcherySub() != 5
            || k24ShieldWallArcherySub() != 10
            || k24KillNum() != 3
            || k24KillDen() != 2
            || k24OccupationTroops() != 500
        )
            ++bad;
        // the melee segments and the door jam - the D&D melee rationale
        // (print 17-19)
    if (k24MeleeSegments() != 10
            || k24SegmentSeconds() != 6
            || k24DoorWidth() != 5
            || k24DoorJamLo() != 1
            || k24DoorJamHi() != 2
            || k24DoorAttackAdd() != 4
            || k24DoorSaveSub() != 4
        )
            ++bad;
        // the audience figures and the hit point examples - the D&D melee
        // rationale (print 17-19)
    if (k24AudienceSize() != 100000
            || k24CriticsLow() != 1
            || k24CriticsHigh() != 5
            || k24FemalePlayersPct() != 10
            || k24GnollParty() != 8
            || k24RhinoDice() != 8
            || k24RhinoHp() != 72
            || k24FighterHp() != 76
        )
            ++bad;
        // the movement, transference and chamber numbers - the DUNGEON board
        // game variations (print 22-25)
    if (k24NonWizardMove() != 10
            || k24WizardMove() != 5
            || k24TransferMonsterRoll() != 8
            || k24ChamberCapacity() != 3
            || k24PermanentKillRoll() != 12
            || k24MonsterMove() != 5
            || k24BeastCombatRoll() != 8
        )
            ++bad;
        // the spell combat quad and the party victory sum - the DUNGEON board
        // game variations (print 22-25)
    if (k24XferElf() != 4
            || k24XferHero() != 5
            || k24XferSuperhero() != 6
            || k24XferWizard() != 7
            || k24FloodSave() != 6
            || k24PoisonGasSave() != 6
            || k24ExplosiveGasSave() != 8
            || k24CeilingBoltRoll() != 8
            || k24PartyGold() != 35000
        )
            ++bad;
        // the Swiss pike and firearms numbers - the Swiss Renaissance army
        // (print 26)
    if (k24PikeLow() != 16
            || k24PikeHigh() != 18
            || k24SwissPikeFeet() != 21
            || k24SwissPikeSteel() != 3
            || k24HandgunLow() != 80
            || k24HandgunHigh() != 100
            || k24SkirmishLow() != 10
            || k24SkirmishHigh() != 30
            || k24PhalanxCount() != 3
        )
            ++bad;
        // the intuition and ectoplasm numbers - the psionics profession
        // variant (print 28-29)
    if (k24IntuitionPct() != 15
            || k24IntuitionMax() != 90
            || k24EctoplasmAc() != 9
            || k24EctoplasmSpeed() != 12
            || k24EctoplasmRange() != 48
            || k24ColdRadius() != 1
            || k24ColdDegrees() != 100
            || k24ColdCost() != 10
        )
            ++bad;
        // the kinetic power numbers - the psionics profession variant (print
        // 28-29)
    if (k24MagnetismWeight() != 3
            || k24MagnetismRange() != 5
            || k24ElectricityLevel() != 4
            || k24GravityRadius() != 5
            || k24GravityFold() != 5
            || k24RetroWeekCost() != 2
            || k24HyperPct() != 10
            || k24GreaterFloor() != 91
            || k24AntiPsiGap() != 5
        )
            ++bad;
        // the key fatality and symptom numbers - the disease charts (print
        // 29)
    if (k24FatalDays92() != 48
            || k24FatalMonths97() != 7
            || k24FatalMonths99() != 9
            || k24FatalMonths00() != 10
            || k24SymptomCount() != 20
        )
            ++bad;
        // the name generator grid numbers - the Petal Throne name generator
        // (print 39)
    if (k24NameGridSide() != 8
            || k24NameSegments() != 64
            || k24NameDiceSides() != 8
            || k24EuphonicLow() != 2
            || k24EuphonicHigh() != 3
        )
            ++bad;
        // the Monty Haul satire numbers - the Monty Haul satire (print 42-43)
    if (k24BronzeHands() != 80
            || k24DragonAge() != 500
            || k24TreasureValue() != 1000000
            || k24WizardLevel() != 16
            || k24WizardCount() != 5
            || k24FireballDice() != 29
            || k24AltarLadies() != 7
            || k24LadiesSlain() != 2
            || k24DeathRayCount() != 5
        )
            ++bad;
        // the three scenario orders of battle - the Viking Caspian campaign
        // (print 13-16)
    if (k24ScnVikings(0) != 900
            || k24ScnSubs(0) != 18
            || k24ScnArabLine(0) != 5100
            || k24ScnVikings(1) != 850
            || k24ScnSubs(1) != 17
            || k24ScnVikings(2) != 800
            || k24ScnSubs(2) != 16
            || k24ScnArabLine(2) != 14600
        )
            ++bad;
        // the five natural occurrence bands - the DUNGEON board game
        // variations (print 22-25)
    if (k24OccLo(0) != 2
            || k24OccHi(0) != 4
            || k24OccLo(1) != 5
            || k24OccHi(1) != 6
            || k24OccLo(2) != 7
            || k24OccHi(2) != 8
            || k24OccLo(3) != 9
            || k24OccHi(3) != 10
            || k24OccLo(4) != 11
            || k24OccHi(4) != 12
        )
            ++bad;
        // the subsentient cost steps, plants twice - the psionics profession
        // variant (print 28-29)
    if (k24SubsentientCost(0) != 1
            || k24SubsentientCost(5) != 6
            || k24SubsentientCost(6) != 7
            || k24SubsentientCost(7) != 8
        )
            ++bad;
        // the Anti-Psi ladder - the psionics profession variant (print 28-29)
    if (k24AntiPsiCost(0) != 5
            || k24AntiPsiCost(3) != 20
            || k24AntiPsiCost(4) != 25
            || k24AntiPsiCost(5) != 25
        )
            ++bad;
        // the fatality bands including the ninety-eight skip - the disease
        // charts (print 29)
    if (k24FatalLo(0) != 1
            || k24FatalHi(0) != 1
            || k24FatalLo(9) != 10
            || k24FatalHi(9) != 15
            || k24FatalLo(18) != 81
            || k24FatalHi(18) != 89
            || k24FatalLo(21) != 92
            || k24FatalHi(21) != 92
            || k24FatalLo(26) != 97
            || k24FatalHi(26) != 97
            || k24FatalLo(27) != 99
            || k24FatalHi(27) != 99
            || k24FatalLo(28) != 100
            || k24FatalHi(28) != 100
        )
            ++bad;
        // the symptom-number bands - the disease charts (print 29)
    if (k24SymBandHi(0) != 3
            || k24SymBandNum(0) != 1
            || k24SymBandHi(1) != 5
            || k24SymBandNum(1) != 2
            || k24SymBandHi(3) != 8
            || k24SymBandNum(3) != 4
        )
            ++bad;
        printf("R956 issue-24 commentary set audit: bad %d\n", bad);
        if (bad) return 1;
    }
