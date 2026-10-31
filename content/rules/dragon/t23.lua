-- t23: promoted from tools/spec_r950.json (the The Dragon issue-23 opener part one - the variant triptych);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 950,
  "prefix" = "t23",
  "banner" = {
      "title" = "The Dragon issue-23 opener part one - the variant triptych",
      "provenance" = "The opener of the issue-23 four-round shape - three of the ten Curtiss-called chains pinned as the variant triptych, the lower-planes DMG preview riding its own part-two table round, the commentary set at part three and the flip to follow. All pinned from The Dragon Vol. III No. 9 (March 1979) print 5-13 at extract/dragon/023, PRINT FOLIO = PDF PAGE this issue, the transcript of the Curtiss-provided scan. The intake seats the gap report and all thirty-two transcripts; the two inherited watches - the Sullin levels 7-9 and the brawling sequel - print nowhere in issue 23 and ride to TD 24.",
    },
  "consts" = { {
      "name" = "t23DuelBasePct",
      "value" = 50,
      "comment" = "the underlying assumption - between equals each stands an equal chance, the basic fifty-percent hit probability the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23DuelCeDivisor",
      "value" = 4,
      "comment" = "the CE difference is divided by four to find the hit probability modifier the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23DuelDmMax",
      "value" = 15,
      "comment" = "the defense modifier - a whole number ranging from one to fifteen the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23JacquesExpertise",
      "value" = 18,
      "comment" = "the worked example - Jaques dUberville with an expertise factor of eighteen the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23KarlExpertise",
      "value" = 15,
      "comment" = "against Karl von Badenhaus with an expertise of fifteen the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23ExampleDm",
      "value" = 3,
      "comment" = "the defense modifier for both duelists - eighteen minus fifteen the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23JacquesCe",
      "value" = 100,
      "comment" = "the weaker opponent by combat effectiveness - Jacques at one hundred the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23KarlCe",
      "value" = 140,
      "comment" = "against the stronger Karl at one hundred forty the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23CeGap",
      "value" = 40,
      "comment" = "the difference between them in CE points the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23ExampleModPct",
      "value" = 10,
      "comment" = "the forty-point gap divided by four gives a ten-percent modifier the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23JacquesHitPct",
      "value" = 40,
      "comment" = "the superior-skill weaker man hits on one to forty percent the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23KarlHitPct",
      "value" = 60,
      "comment" = "the stronger man hits on one to sixty percent the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23JacquesRoll",
      "value" = 42,
      "comment" = "the superior duelist rolls forty-two, subtracts the defense modifier for thirty-nine and scores a light head wound the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23KarlRoll",
      "value" = 58,
      "comment" = "the inferior duelist rolls fifty-eight, adds the modifier for sixty-one and misses the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23KarlInjury",
      "value" = 26,
      "comment" = "the light head wound - base twenty plus a die roll of six the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23KarlNewCe",
      "value" = 114,
      "comment" = "the wounded Karl recomputed to one hundred fourteen the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23PhaseTwoJacquesPct",
      "value" = 47,
      "comment" = "the second-phase recompute - Jacques now hits on one to forty-seven the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23PhaseTwoKarlPct",
      "value" = 53,
      "comment" = "while Karl scores on one to fifty-three the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23CritNoteCount",
      "value" = 5,
      "comment" = "the five printed table notes - defend-only-next-phase, expertise halved, expertise quartered, strength halved and the non-player surrender the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23CritBandCount",
      "value" = 11,
      "comment" = "the eleven critical hit bands from the light leg wound through the double-nought death the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23CritHitsCount",
      "value" = 11,
      "comment" = "the eleven critical hit bands by print order - light leg, light left arm, light right arm, light head, light body, serious leg, serious left arm, serious right arm, serious head, serious body, dead the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23TrackSpaces",
      "value" = 17,
      "comment" = "the double track - seventeen spaces long, the center and the flank the psionic wrestling track (print 10)",
    }, {
      "name" = "t23TrackEndSpace",
      "value" = 8,
      "comment" = "to win a player must force a marker into the opponent's space number eight the psionic wrestling track (print 10)",
    }, {
      "name" = "t23AttackBonus",
      "value" = 40,
      "comment" = "the attacker's total psionic strength is increased by forty points or doubled, whichever is less the psionic wrestling track (print 10)",
    }, {
      "name" = "t23PushTwoSpacesRatio",
      "value" = 3,
      "comment" = "a ratio of three to one moves the proper marker two spaces the psionic wrestling track (print 10)",
    }, {
      "name" = "t23PushMaxSpaces",
      "value" = 2,
      "comment" = "higher ratios do not have higher effects - two spaces is the maximum possible retreat the psionic wrestling track (print 10)",
    }, {
      "name" = "t23AttackerLoss",
      "value" = 3,
      "comment" = "after each exchange the attacker loses three points the psionic wrestling track (print 10)",
    }, {
      "name" = "t23DefenderLossPerSpace",
      "value" = 2,
      "comment" = "the defender loses two times the number of spaces fallen back the psionic wrestling track (print 10)",
    }, {
      "name" = "t23CollapseThreshold",
      "value" = 15,
      "comment" = "a psionic strength falling below fifteen means the loss of the battle and a roll on the battle-loser table the psionic wrestling track (print 10)",
    }, {
      "name" = "t23UnconsciousHours",
      "value" = 12,
      "comment" = "the center-marker loss - instant death, or unconsciousness for one to twelve hours if the saving throw succeeds the psionic wrestling track (print 10)",
    }, {
      "name" = "t23WardenCount",
      "value" = 20,
      "comment" = "the twenty water creatures of the monster roster, from the Sea Griffon through the Merman the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23OrcasStunTurns",
      "value" = 6,
      "comment" = "the orcas directional spout stuns for one to six turns the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23CentipedeLiftLbs",
      "value" = 1000,
      "comment" = "the sea centipede lifts one thousand pounds with its telekinesis the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SeaDragonBodyFeet",
      "value" = 40,
      "comment" = "the one-time sea turtle is about forty feet long the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SeaDragonNeckFeet",
      "value" = 20,
      "comment" = "with an additional twenty feet of neck the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23BedTentacles",
      "value" = 50,
      "comment" = "the bed of spikes has approximately fifty tentacles the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23MineDamageDice",
      "value" = 10,
      "comment" = "the mine - free-floating leather coral exploding for ten dice of damage the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23DaggerPoisonPct",
      "value" = 20,
      "comment" = "the water dagger carries a twenty percent chance of poison the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23KrakenFeet",
      "value" = 100,
      "comment" = "the kraken octopus runs up to one hundred feet with a total carapace the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23BrainFishStrength",
      "value" = 13,
      "comment" = "the brain fish mental attack strength of thirteen, printed truncated as stre the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SharkoidStrength",
      "value" = 15,
      "comment" = "the sharkoid mental blast strength of fifteen the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23GupoidPackLow",
      "value" = 300,
      "comment" = "the gupoid packs run from three hundred the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23GupoidPackHigh",
      "value" = 1000,
      "comment" = "to one thousand fish the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SirenTranceRounds",
      "value" = 12,
      "comment" = "the siren trance holds for one to twelve melee rounds, treated as a poison save the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SeaFlyerControlPct",
      "value" = 20,
      "comment" = "the sea flyer holds a twenty percent chance of already controlling a creature when encountered the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SeaFlyerWingspanInches",
      "value" = 2,
      "comment" = "the mutated manta rays average two inches in wingspan the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23MermanLimbs",
      "value" = 6,
      "comment" = "the merman has six crab-like limbs, two of them manipulative claws the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23MermanLungTakePct",
      "value" = 50,
      "comment" = "captured player characters have their lungs taken for gills half the time the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23PeeperTableDice",
      "value" = 4,
      "comment" = "the peeper radiated eyes in the table - four to twenty-four, four dice the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23PeeperTextDice",
      "value" = 3,
      "comment" = "the same attack in the text - three dice worth of damage, both pinned the Starship Warden water monsters (print 11, 13)",
    } },
  "bools" = { {
      "name" = "t23FlowchartSolitaire",
      "value" = true,
      "comment" = "the game system laid out in flow-chart fashion - yes-no monthly actions from courting to the bawdyhouse the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23DuelingBreakdown",
      "value" = true,
      "comment" = "the only breakdown point - dueling always requires another player and secretly written sequenced actions the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23MidColumbiaSociety",
      "value" = true,
      "comment" = "the Mid-Columbia Wargaming Society of Richland Washington substitutes the shorthand dueling method the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23CeRecomputeWounded",
      "value" = true,
      "comment" = "the combat effectiveness is recomputed every time a duelist is wounded the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23HigherExpertiseInitiative",
      "value" = true,
      "comment" = "the higher expertise factor always has the initiative - and a player character always holds it against a non-player the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23SuperiorSubtractsDm",
      "value" = true,
      "comment" = "the superior duelist subtracts the defense modifier from his die roll, the inferior adds it the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23GrandMeleeUnderdogBlows",
      "value" = true,
      "comment" = "the grand melee underdog gains blows per phase equal to his strength divided by three the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23DuelHalfPractice",
      "value" = true,
      "comment" = "each duel counts as one-half of a free practice session, whether or not the character wins the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "name" = "t23FogImage",
      "value" = true,
      "comment" = "the visual - a glowing sheet of stretchable fog pushed back and forth between the combatants the psionic wrestling track (print 10)",
    }, {
      "name" = "t23CenterDeathOrSave",
      "value" = true,
      "comment" = "the center marker forced home means instant death or the save-throw unconsciousness the psionic wrestling track (print 10)",
    }, {
      "name" = "t23OutsideCharmNoSave",
      "value" = true,
      "comment" = "the outside marker forced home means the victim is charmed with no saving throw the psionic wrestling track (print 10)",
    }, {
      "name" = "t23BonusTemporary",
      "value" = true,
      "comment" = "the forty-point increase is temporary - the strength drops back to normal after the comparison the psionic wrestling track (print 10)",
    }, {
      "name" = "t23HigherStrengthFirst",
      "value" = true,
      "comment" = "the player with the higher psionic strength attacks first, then strict alternation the psionic wrestling track (print 10)",
    }, {
      "name" = "t23EldritchBase",
      "value" = true,
      "comment" = "the variant rides on the psionic combat of the third supplement - the losing roll comes from that battle-loser table the psionic wrestling track (print 10)",
    }, {
      "name" = "t23FloodingDoctrine",
      "value" = true,
      "comment" = "the flooding doctrine - an entire level can flood, drowning the unwary at the elevator door the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SaltFreshAdapt",
      "value" = true,
      "comment" = "the salt-or-fresh rationale - the radiation could have turned the water either way and the fish adapted the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SeaGriffonNoManipClaws",
      "value" = true,
      "comment" = "the sea griffon cannot use most technology - it has no manipulative claws the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23GreenDeathOxygen",
      "value" = true,
      "comment" = "the green death dies only to the protein disrupter or exposure to oxygen the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SharkoidFlashingLight",
      "value" = true,
      "comment" = "the sharkoid is epileptic - a flashing light renders it fairly harmless the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23TroutoidDensity",
      "value" = true,
      "comment" = "the troutoid density control - it drops like a rock or floats to avoid predators the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23WaterDaggerAluminum",
      "value" = true,
      "comment" = "the water dagger is staghorn coral covered with aluminum the Starship Warden water monsters (print 11, 13)",
    }, {
      "name" = "t23SirenCharismaNotSonic",
      "value" = true,
      "comment" = "the siren uses a charismatic effect rather than sonics - gills negate sonics the Starship Warden water monsters (print 11, 13)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "t23CritHits",
      "tag" = "Ch",
      "count" = "t23CritHitsCount",
      "sentinel" = -99,
      "audit_comment" = "the critical hits grid - the eleven bands from the light leg wound through the double-nought death, the light bands at base twenty or twenty-five plus the small die, the serious bands at base fifty or one hundred plus the large die, the die sizes converted from the sixteen-sided and one-hundred-twenty-sided prints",
      "cols" = { "t23CritLo", "t23CritHi", "t23CritBase", "t23CritDie" },
      "col_comments" = { "the band floor of the modified die roll - one, eleven, twenty-one through the double-nought read as one hundred", "the band ceiling - ten, twenty, thirty through ninety-nine and one hundred at the death row", "the damage base - twenty for the five light bands, twenty-five for the light body, fifty for the four serious bands and one hundred for the serious body, zero at the death row", "the damage die - the print says sixteen-sided for the light bands and one-hundred-twenty-sided for the serious, the worked example proves six and twenty (Karl takes twenty plus six for twenty-six), conversion noted" },
      "data" = { { 1, 10, 20, 6 }, { 11, 20, 20, 6 }, { 21, 30, 20, 6 }, { 31, 40, 20, 6 }, { 41, 50, 25, 6 }, { 51, 60, 50, 20 }, { 61, 70, 50, 20 }, { 71, 80, 50, 20 }, { 81, 90, 50, 20 }, { 91, 99, 100, 20 }, { 100, 100, 0, 0 } },
    }, {
      "name" = "t23Warden",
      "tag" = "Wd",
      "count" = "t23WardenCount",
      "sentinel" = -99,
      "audit_comment" = "the Starship Warden water monster grid - the twenty creatures by print order from the Sea Griffon through the Merman, attacks, armor class, hit dice, the appearing band and the movement, the dashes read as the sentinel",
      "cols" = { "t23WardenAttacks", "t23WardenAc", "t23WardenHd", "t23WardenAppearLo", "t23WardenAppearHi", "t23WardenMove" },
      "col_comments" = { "the number of attacks - three for the sea griffon and dragon, nine tentacles and beak for the kraken, the water dagger has none", "the armor class - six for the sea griffon through one for the water dagger, oysteroid and peeper, the green death and gupoids carry the sentinel", "the hit dice - eighteen for the orcas, fifteen for the sea dragon, twelve for the sharkoid, ten for the kraken, the cluster and patch creatures carry the sentinel", "the appearing band floor - one for most, two for the craboid and sea flyer, three hundred for the gupoids", "the appearing band ceiling - one hundred for the merman pack, one thousand for the gupoids, the single creatures at one", "the movement - twenty-three for the sea griffon, thirty-six fly for the craboid noted against walk three and swim ten, twenty-five mounted for the merman noted against five swimming, the immobile creatures carry the sentinel" },
      "data" = { { 3, 6, 5, 1, 2, 23 }, { 2, 6, 18, 1, 1, 20 }, { 1, 3, 2, 1, 4, 20 }, { 3, 2, 15, 1, 1, 20 }, { 1, 4, 2, 1, 4, 20 }, { 1, -99, -99, 1, 1, -99 }, { 1, 7, -99, 1, 1, -99 }, { -99, 1, 5, 1, 1, -99 }, { 1, 6, 3, 1, 6, -99 }, { 2, 2, 1, 2, 20, 36 }, { 9, 3, 10, 1, 1, 20 }, { 1, 1, 1, 1, 10, 18 }, { 1, 1, 2, 1, 5, 18 }, { 2, 4, 3, 3, 30, 20 }, { 1, -99, -99, 300, 1000, 15 }, { 1, 6, 3, 1, 2, 20 }, { 1, 3, 1, 2, 20, 20 }, { 2, 5, 12, 1, 1, 17 }, { 1, 4, 3, 4, 24, 23 }, { 1, 5, 5, 1, 100, 25 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['t23DuelBasePct']() != 50 or m['t23DuelCeDivisor']() != 4 or m['t23DuelDmMax']() != 15 or m['t23FlowchartSolitaire']() != 1",
      "note" = "the duel frame - the fifty-percent base, the four-divisor and the one-to-fifteen defense modifier the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "expr" = "m['t23JacquesExpertise']() != 18 or m['t23KarlExpertise']() != 15 or m['t23ExampleDm']() != 3 or m['t23JacquesCe']() != 100 or m['t23KarlCe']() != 140",
      "note" = "the worked example pair - the eighteen against fifteen expertise giving the three, the one hundred against one hundred forty effectiveness the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "expr" = "m['t23CeGap']() != 40 or m['t23ExampleModPct']() != 10 or m['t23JacquesHitPct']() != 40 or m['t23KarlHitPct']() != 60",
      "note" = "the probability split - the forty-point gap, the ten-percent modifier and the forty against sixty hit probabilities the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "expr" = "m['t23JacquesRoll']() != 42 or m['t23KarlRoll']() != 58 or m['t23KarlInjury']() != 26 or m['t23KarlNewCe']() != 114",
      "note" = "the first phase played - the forty-two less three that hits, the fifty-eight plus three that misses, the twenty-six wound and the one hundred fourteen recompute the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "expr" = "m['t23PhaseTwoJacquesPct']() != 47 or m['t23PhaseTwoKarlPct']() != 53 or m['t23CeRecomputeWounded']() != 1 or m['t23SuperiorSubtractsDm']() != 1",
      "note" = "the second phase - the swing to forty-seven against fifty-three, the advantage moving as it happened in reality the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "expr" = "m['t23CritBandCount']() != 11 or m['t23CritNoteCount']() != 5 or m['t23DuelHalfPractice']() != 1 or m['t23GrandMeleeUnderdogBlows']() != 1",
      "note" = "the melee bookends - the eleven bands, the five notes, the half practice session and the strength-divided-by-three underdog blows the En Garde solitaire dueling variant (print 5-6)",
    }, {
      "expr" = "m['t23TrackSpaces']() != 17 or m['t23TrackEndSpace']() != 8 or m['t23AttackBonus']() != 40 or m['t23CollapseThreshold']() != 15",
      "note" = "the track frame - seventeen spaces, the eighth-space kill, the forty-point bonus and the fifteen-point collapse the psionic wrestling track (print 10)",
    }, {
      "expr" = "m['t23PushTwoSpacesRatio']() != 3 or m['t23PushMaxSpaces']() != 2 or m['t23AttackerLoss']() != 3 or m['t23DefenderLossPerSpace']() != 2 or m['t23UnconsciousHours']() != 12",
      "note" = "the push economics - the three-to-one double push capped at two spaces, the attacker losing three, the defender two per space and the twelve-hour save the psionic wrestling track (print 10)",
    }, {
      "expr" = "m['t23CenterDeathOrSave']() != 1 or m['t23OutsideCharmNoSave']() != 1 or m['t23BonusTemporary']() != 1 or m['t23FogImage']() != 1",
      "note" = "the track stakes - the center marker death or save, the outside marker charm with no save, the temporary bonus and the stretchable fog the psionic wrestling track (print 10)",
    }, {
      "expr" = "m['t23WardenCount']() != 20 or m['t23FloodingDoctrine']() != 1 or m['t23SaltFreshAdapt']() != 1",
      "note" = "the roster frame - twenty creatures riding the flooding doctrine and the salt-or-fresh adaptation rationale the Starship Warden water monsters (print 11, 13)",
    }, {
      "expr" = "m['t23OrcasStunTurns']() != 6 or m['t23CentipedeLiftLbs']() != 1000 or m['t23SeaDragonBodyFeet']() != 40 or m['t23SeaDragonNeckFeet']() != 20 or m['t23BedTentacles']() != 50",
      "note" = "the monster dimensions - the six-turn orcas stun, the thousand-pound telekinesis, the forty-plus-twenty sea dragon and the fifty tentacles the Starship Warden water monsters (print 11, 13)",
    }, {
      "expr" = "m['t23KrakenFeet']() != 100 or m['t23MineDamageDice']() != 10 or m['t23DaggerPoisonPct']() != 20 or m['t23SirenTranceRounds']() != 12",
      "note" = "the danger quartet - the hundred-foot kraken, the ten-dice mine, the twenty-percent poison dagger and the twelve-round siren trance the Starship Warden water monsters (print 11, 13)",
    }, {
      "expr" = "m['t23BrainFishStrength']() != 13 or m['t23SharkoidStrength']() != 15 or m['t23GupoidPackLow']() != 300 or m['t23GupoidPackHigh']() != 1000",
      "note" = "the mental and the mass - the thirteen and fifteen mental strengths and the three-hundred-to-thousand gupoid packs the Starship Warden water monsters (print 11, 13)",
    }, {
      "expr" = "m['t23SeaFlyerControlPct']() != 20 or m['t23SeaFlyerWingspanInches']() != 2 or m['t23MermanLimbs']() != 6 or m['t23MermanLungTakePct']() != 50 or m['t23PeeperTableDice']() != 4 or m['t23PeeperTextDice']() != 3",
      "note" = "the small wonders - the two-inch controlled sea flyer, the six-limbed lung-taking merman and the peeper four-dice table against its three-dice text the Starship Warden water monsters (print 11, 13)",
    } },
  "audit" = {
      "label" = "R950 issue-23 variant triptych audit",
      "comment" = "the three-chain variant triptych audit - the En Garde solitaire dueling method, the psionic wrestling track and the Starship Warden water monsters",
    },
}
