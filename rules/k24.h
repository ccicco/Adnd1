// =========================================================================================
// Adnd1 - rules/k24.h
// The Dragon issue-24 opener part three - the ten-chain commentary set
// census 878 -> 879.
//
// The part-three round of the issue-24 four-round shape - the ten-chain
// commentary set of the walk: the Pehr magic-user limiting with the Rules of
// Concentration and Duration, the Gygax Roman military update for Classic
// Warfare with the Livian manipular legion and the Julian light-infantry
// mounting, the Brunner Viking Caspian campaign with the three scenario
// orders of battle, the Gygax melee defense with the door jam and the missile
// ratios and the Design Department note, the Laking DUNGEON variant set with
// transference, beast masters and dungeon parties, the Nascati Swiss with the
// twenty-one-foot pike and the three phalanxes, the Pehr three-type psionic
// power system with the subsentient costs and the Anti-Psi ladder, the
// Buettner disease charts with the fatality bands and the ninety-eight skip,
// the Rahman Petal Throne name generator with the verified sixty-four
// permutation, and the Ward Monty Haul humor fiction. Pinned from The Dragon
// Vol. III No. 10, April 1979, number 24, print 7 through 29 and 39 and 42
// through 43 - PRINT FOLIO = PDF PAGE this issue, the single-voice transcript
// of the Curtiss-provided scan.
//
namespace rules {

// ---- the magic-user limiting variants (print 7) ----

// even one point of damage taken in a melee round forbids any spell cast in
// that round - the magic-user limiting variants (print 7)
inline int k24ConcentrationDamage()
    { return 1; }

// magic spells last no longer than one turn for every level of mastery of the
// caster - the magic-user limiting variants (print 7)
inline int k24DurationTurnsPerLevel()
    { return 1; }

// in the wilderness new spells may be obtained only every week instead of
// every day - the magic-user limiting variants (print 7)
inline int k24WildernessWeeks()
    { return 1; }

// the WRITE FOR THE DRAGON call - a minimum payment of one cent per word,
// cash not credit - the magic-user limiting variants (print 7)
inline int k24TdMinPayment()
    { return 1; }

// assigning types of spells to specialties, a Mentalist with ESP and Hold
// Person, a Pyronic with Fireballs, suggested most useful for NPCs - the
// magic-user limiting variants (print 7)
inline bool k24SpecialtiesIdea()
    { return true; }

// the percentage failure factor rejected for D&D, an extra dice roll in the
// middle of melee avoided at all costs - the magic-user limiting variants
// (print 7)
inline bool k24FailureFactorRejected()
    { return true; }

// a successful saving throw indicates the spell did not manifest, the
// Fireball a flash of light and the Paralysis beam a pleasant tingle - the
// magic-user limiting variants (print 7)
inline bool k24SaveUnmanifested()
    { return true; }

// magic directed at an individual must overcome inherent resistance, a saver
// not healed by Cure Wounds nor Teleported from the Purple Worm - the
// magic-user limiting variants (print 7)
inline bool k24InherentResistance()
    { return true; }

// the Rule of Concentration, no character can concentrate enough to cast a
// spell in a melee round in which he has been hurt - the magic-user limiting
// variants (print 7)
inline bool k24ConcentrationRule()
    { return true; }

// if the spell was already cast the damage taken is subtracted from dexterity
// for purposes of spell casting in the next round - the magic-user limiting
// variants (print 7)
inline bool k24DexterityCarryover()
    { return true; }

// the Rule of Duration, a raging opponent charmed for ten minutes per level
// rather than a lasting friendship - the magic-user limiting variants (print
// 7)
inline bool k24DurationRule()
    { return true; }

// unlike the dungeon each wilderness turn is a day, so each wilderness
// encounter is faced with a full battery of spells - the magic-user limiting
// variants (print 7)
inline bool k24WildernessDayTurns()
    { return true; }

// Gauntlets of Defense, a Ring of Protection and a Robe of Protection should
// not be added together, the single most potent defense only - the magic-user
// limiting variants (print 7)
inline bool k24DefensesNotAdded()
    { return true; }

// an artifact can be combined with a defensive spell such as Protection
// versus Evil since the spell protection is temporary - the magic-user
// limiting variants (print 7)
inline bool k24ArtifactSpellCombo()
    { return true; }

// the writers call, submissions typed and double-spaced with a self-addressed
// stamped envelope, handwritten articles not considered - the magic-user
// limiting variants (print 7)
inline bool k24TdWritersCall()
    { return true; }

// literate does not mean a of letters, the missing word in the writers call -
// the magic-user limiting variants (print 7)
inline bool k24LiteratePrint()
    { return true; }

// ---- the Roman military update (print 12) ----

// the Livian circa 350 B.C. legion fielding nine hundred hastati - the Roman
// military update (print 12)
inline int k24EarlyHastati()
    { return 900; }

// the hastati formed in sixteen maniples of sixty men each - the Roman
// military update (print 12)
inline int k24HastatiManiples()
    { return 16; }

// the maniple strength of sixty men, mounted as a pair of two-by-one troop
// stands - the Roman military update (print 12)
inline int k24ManipleMen()
    { return 60; }

// nine hundred principes formed in the same manner behind the hastati - the
// Roman military update (print 12)
inline int k24EarlyPrincipes()
    { return 900; }

// the third line of fifteen ordines, to the rear of the principes - the Roman
// military update (print 12)
inline int k24OrdoLines()
    { return 15; }

// each ordo subdivided into three separate vexilla - the Roman military
// update (print 12)
inline int k24VexillaPerOrdo()
    { return 3; }

// the vexilla strength of sixty-two men as opposed to the sixty of the
// maniple - the Roman military update (print 12)
inline int k24VexillaMen()
    { return 62; }

// the basic morale of nine for the triarii - the Roman military update (print
// 12)
inline int k24TriariiMorale()
    { return 9; }

// the basic morale of seven for the rorarii - the Roman military update
// (print 12)
inline int k24RorariiMorale()
    { return 7; }

// the basic morale of three for the untrained accensi - the Roman military
// update (print 12)
inline int k24AccensiMorale()
    { return 3; }

// a unit attacked from the rear fights at the morale base of the untrained
// accensi - the Roman military update (print 12)
inline int k24RearAttackMorale()
    { return 5; }

// the attached ala of three hundred equites, no velites in the Livian form -
// the Roman military update (print 12)
inline int k24EquitesAla()
    { return 300; }

// the later manipular legion, two centuries of sixty men forming the maniple
// of one hundred twenty - the Roman military update (print 12)
inline int k24LaterManipleMen()
    { return 120; }

// the Julian light infantry sixty-man centuries, mounted two-by-one rather
// than the three-by-one of the Marian hundred-man centuries - the Roman
// military update (print 12)
inline int k24JulianCentury()
    { return 60; }

// a mixed light cavalry and light infantry unit given a morale base of seven
// - the Roman military update (print 12)
inline int k24MixedUnitMorale()
    { return 7; }

// Livy describes the circa 350 B.C. Manipular Legion form not included in
// Classic Warfare, page forty-five of the rules - the Roman military update
// (print 12)
inline bool k24LivyEarlyLegion()
    { return true; }

// each ordo operates as a phalanx, although the separate vexilla may be
// detached and employed separately - the Roman military update (print 12)
inline bool k24OrdoPhalanx()
    { return true; }

// the morale of each unit is that of the troops of its engaged face, triarii
// stripped leaves a seven rating at best - the Roman military update (print
// 12)
inline bool k24MoraleEngagedFace()
    { return true; }

// as casualties are sustained in the front ranks the morale base of the unit
// will drop - the Roman military update (print 12)
inline bool k24FrontRankMoraleDrop()
    { return true; }

// the Classic Warfare manipular mounting error, the printed two-by-two should
// be a pair of two-by-one stands forming each maniple - the Roman military
// update (print 12)
inline bool k24MountingError()
    { return true; }

// the checkered acies triplex array, superior against the Greek phalanx and
// inferior against barbarian masses pouring through the gaps - the Roman
// military update (print 12)
inline bool k24CheckeredArray()
    { return true; }

// barbarian light infantry flanking stands placed on the second turn of
// melee, rear rank figures removed from the mass as the mark of the stand -
// the Roman military update (print 12)
inline bool k24FlankStands()
    { return true; }

// facing the Spanish in the Third Century B.C., the late manipular legions
// adopted the gladius rather than the old cutting sword - the Roman military
// update (print 12)
inline bool k24GladiusChange()
    { return true; }

// Second Century manipular legions allowed a heavy and a light pilum cast per
// figure of hastati and principes - the Roman military update (print 12)
inline bool k24HeavyPilum()
    { return true; }

// the velites carried javelins and served as both missile troops and light
// infantry - the Roman military update (print 12)
inline bool k24VelitesJavelins()
    { return true; }

// the Julian Legion light infantry mounted two-by-one, not three-by-one as
// indicated for the Marian light infantry - the Roman military update (print
// 12)
inline bool k24JulianLights()
    { return true; }

// unreliable mercenary cavalry stiffened by mixing light infantry into the
// formations - the Roman military update (print 12)
inline bool k24MercenaryMixing()
    { return true; }

// the Williams article titled De Art Bellica, Roman Tactics 200 B.C. to 100
// A.D. in COMBAT ILLUSTRATED, as printed - the Roman military update (print
// 12)
inline bool k24DeArtBellicaPrint()
    { return true; }

// the Lundstrom LORE magazine article, A Roman Helmet from Iran, Legionaries
// in the Near East - the Roman military update (print 12)
inline bool k24LundstromHelmet()
    { return true; }

// six volumes of Polybius THE HISTORIES and Livy HISTORY OF ROME in the
// research sources - the Roman military update (print 12)
inline bool k24PolybiusSources()
    { return true; }

// TRACTACS for TRACTICS in the editors note list of nine historical games, as
// printed - the Roman military update (print 12)
inline bool k24TractacsPrint()
    { return true; }

// Finieous missed the issue, the EXXECUUUUSSSSE vacation note and the apology
// for the delay - the Roman military update (print 12)
inline bool k24FinieousVacation()
    { return true; }

// ---- the Viking Caspian campaign (print 13-16) ----

// the Viking fleet before the Khazar capital in the summer of 954 - the
// Viking Caspian campaign (print 13-16)
inline int k24CampaignYear()
    { return 954; }

// twenty-four ships sailing up the Dvina - the Viking Caspian campaign (print
// 13-16)
inline int k24VikingShips()
    { return 24; }

// twenty-four ships carrying twelve hundred Swedish warriors - the Viking
// Caspian campaign (print 13-16)
inline int k24VikingWarriors()
    { return 1200; }

// the captured trading city with a population in excess of ten thousand - the
// Viking Caspian campaign (print 13-16)
inline int k24CityPopulation()
    { return 10000; }

// the trifling amount of twenty dirhems per man, the stamped-clay
// safe-conduct passes - the Viking Caspian campaign (print 13-16)
inline int k24RansomDirhems()
    { return 20; }

// ten thousand men, women and children either ransomed or sold into slavery -
// the Viking Caspian campaign (print 13-16)
inline int k24SpareCaptives()
    { return 10000; }

// the sultan army numbered close to thirty thousand, one-half veteran
// fighting men - the Viking Caspian campaign (print 13-16)
inline int k24MarzubanArmy()
    { return 30000; }

// seven hundred Viking warriors fell around the body of their chieftain - the
// Viking Caspian campaign (print 13-16)
inline int k24FallenVikings()
    { return 700; }

// the sultan left five hundred Dailemite infantry in the citadel - the Viking
// Caspian campaign (print 13-16)
inline int k24SiegeDailemites()
    { return 500; }

// fifteen hundred Kurdish horse riding out from the city - the Viking Caspian
// campaign (print 13-16)
inline int k24SiegeKurdishHorse()
    { return 1500; }

// two thousand volunteer citizen infantry with the Kurdish horse - the Viking
// Caspian campaign (print 13-16)
inline int k24SiegeVolunteers()
    { return 2000; }

// the Viking basic morale of ten - the Viking Caspian campaign (print 13-16)
inline int k24VikingMorale()
    { return 10; }

// plus three when the chieftain or a subcommander travels with the unit - the
// Viking Caspian campaign (print 13-16)
inline int k24CommanderAdd()
    { return 3; }

// plus one if the Vikings are in the swine-array shield wall - the Viking
// Caspian campaign (print 13-16)
inline int k24ShieldWallAdd()
    { return 1; }

// Arab archery hits reduced by an additional five percent due to the size of
// the Viking shields - the Viking Caspian campaign (print 13-16)
inline int k24ArabArcherySub()
    { return 5; }

// another ten percent against the shield wall, on top of the five percent
// shield subtraction - the Viking Caspian campaign (print 13-16)
inline int k24ShieldWallArcherySub()
    { return 10; }

// the Arab marginal victory demands at least a three-to-two kill ratio - the
// Viking Caspian campaign (print 13-16)
inline int k24KillNum()
    { return 3; }

// the two of the three-to-two kill ratio - the Viking Caspian campaign (print
// 13-16)
inline int k24KillDen()
    { return 2; }

// maintain five hundred troop in the city, fifty percent of them regulars, or
// a decisive victory becomes marginal - the Viking Caspian campaign (print
// 13-16)
inline int k24OccupationTroops()
    { return 500; }

// the three scenario orders of battle - the Viking Caspian campaign (print
// 13-16)
inline int k24ScnCount()
    { return 3; }

// the tenth Century Arab historian ibn Miskaiyah, Decline of the Abbassid
// Caliphate, as the source - the Viking Caspian campaign (print 13-16)
inline bool k24MiskaiyahSource()
    { return true; }

// safe passage from the Khazar Khan in return for a share of the plunder -
// the Viking Caspian campaign (print 13-16)
inline bool k24KhazarPassage()
    { return true; }

// the swine-array, a wedge-shaped shield wall erupting from the citadel gate
// in the Third Scenario - the Viking Caspian campaign (print 13-16)
inline bool k24SwineArray()
    { return true; }

// the Barda-a versus Baroda-a spelling drift through the article - the Viking
// Caspian campaign (print 13-16)
inline bool k24BardaDrift()
    { return true; }

// Sharistan at first mention against Shahristan in the rest of the siege
// account - the Viking Caspian campaign (print 13-16)
inline bool k24SharistanDrift()
    { return true; }

// Krudish for Kurdish in the garrison roster - the Viking Caspian campaign
// (print 13-16)
inline bool k24KrudishPrint()
    { return true; }

// the unguessed at strength of the Swedish archers - the Viking Caspian
// campaign (print 13-16)
inline bool k24UnguessedPrint()
    { return true; }

// beseigars for the besiegers in the siege account - the Viking Caspian
// campaign (print 13-16)
inline bool k24BeseigarsPrint()
    { return true; }

// The know not defeat, They in the ibn Miskaiyah quote - the Viking Caspian
// campaign (print 13-16)
inline bool k24TheyKnowPrint()
    { return true; }

// pomiard for poniard in the Viking arms list - the Viking Caspian campaign
// (print 13-16)
inline bool k24PomiardPrint()
    { return true; }

// maintain five hundred troop, troops as printed in the Arab decisive victory
// - the Viking Caspian campaign (print 13-16)
inline bool k24TroopPrint()
    { return true; }

// the Arab subcommander affect only their original unit, effect as printed -
// the Viking Caspian campaign (print 13-16)
inline bool k24AffectPrint()
    { return true; }

// Vikings will never surrender and do not need to check morale when encircled
// or faced with heavy losses - the Viking Caspian campaign (print 13-16)
inline bool k24NeverSurrender()
    { return true; }

// Vikings may use ferocity with no penalty the first time, and with normal
// penalties if it is used twice - the Viking Caspian campaign (print 13-16)
inline bool k24FerocityFree()
    { return true; }

// ten percent of the Viking army may be mounted on captured horses as medium
// cavalry, but may not attack while mounted and fights at minus one if
// attacked - the Viking Caspian campaign (print 13-16)
inline bool k24MountedRule()
    { return true; }

// if the Arab camp is captured or destroyed the militia desert and the Arab
// regular morale suffers a two-point deduction - the Viking Caspian campaign
// (print 13-16)
inline bool k24CampDesertion()
    { return true; }

// unable to build effective siege equipment due to the death of suitable
// materials, dearth as printed - the Viking Caspian campaign (print 13-16)
inline bool k24DeathOfMaterials()
    { return true; }

// the prisoners chose the Christian ibn Sam-un as their spokesman, the
// Muslims refusing to pay the same ransom as the Christians - the Viking
// Caspian campaign (print 13-16)
inline bool k24IbnSamun()
    { return true; }

// the beardless young chieftain son slew himself with his sword in the tree
// rather than submit to capture - the Viking Caspian campaign (print 13-16)
inline bool k24ChieftainSon()
    { return true; }

// the dead buried with weapons and wives, the graves later desecrated for the
// finely wrought swords - the Viking Caspian campaign (print 13-16)
inline bool k24DesecratedGraves()
    { return true; }

// the Viking heavy infantry - nine hundred, eight hundred fifty with a tenth
// mounted on captured horses, eight hundred in the swine-array
inline int k24ScnVikings(int b)
    {
        switch (b) {
        case 0:
            return 900;
        case 1:
            return 850;
        case 2:
            return 800;
        default:
            return -99;
        }
    }

// the Viking subcommanders extraordinary - eighteen, seventeen, sixteen
inline int k24ScnSubs(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 17;
        case 2:
            return 16;
        default:
            return -99;
        }
    }

// the Arab line-unit totals - fifty-one hundred, twelve hundred seventy-five,
// fourteen thousand six hundred
inline int k24ScnArabLine(int b)
    {
        switch (b) {
        case 0:
            return 5100;
        case 1:
            return 1275;
        case 2:
            return 14600;
        default:
            return -99;
        }
    }

// ---- the D&D melee rationale (print 17-19) ----

// the melee round divided into ten segments for purposes of missile fire,
// spell casting and multiple telling blows - the D&D melee rationale (print
// 17-19)
inline int k24MeleeSegments()
    { return 10; }

// each segment of the melee round lasting six seconds - the D&D melee
// rationale (print 17-19)
inline int k24SegmentSeconds()
    { return 6; }

// an audience of well over one hundred thousand enthusiasts - the D&D melee
// rationale (print 17-19)
inline int k24AudienceSize()
    { return 100000; }

// perhaps one percent to five percent of the audience concerned with possible
// melee shortcomings - the D&D melee rationale (print 17-19)
inline int k24CriticsLow()
    { return 1; }

// the five percent upper bound of the concerned critics - the D&D melee
// rationale (print 17-19)
inline int k24CriticsHigh()
    { return 5; }

// a door five feet wide, entered two at a time carefully, a momentary jam if
// two or three rush it - the D&D melee rationale (print 17-19)
inline int k24DoorWidth()
    { return 5; }

// the jam lasts one or two segments - the D&D melee rationale (print 17-19)
inline int k24DoorJamLo()
    { return 1; }

// the two segments of the possible jam - the D&D melee rationale (print
// 17-19)
inline int k24DoorJamHi()
    { return 2; }

// an arbitrary bonus of plus four to any attackers striking the jammed
// characters - the D&D melee rationale (print 17-19)
inline int k24DoorAttackAdd()
    { return 4; }

// an arbitrary penalty of minus four on the saving throws of the jammed
// characters - the D&D melee rationale (print 17-19)
inline int k24DoorSaveSub()
    { return 4; }

// at least ten percent of the players are female, the Jean Wells note - the
// D&D melee rationale (print 17-19)
inline int k24FemalePlayersPct()
    { return 10; }

// the gnoll engagement - a dwarf, gnome and halfling front rank, two
// half-elves and three humans - the D&D melee rationale (print 17-19)
inline int k24GnollParty()
    { return 8; }

// a rhino can take damage equal to eight of nine eight-sided dice, the or as
// printed - the D&D melee rationale (print 17-19)
inline int k24RhinoDice()
    { return 8; }

// the rhino maximum of sixty-four or seventy-two hit points - the D&D melee
// rationale (print 17-19)
inline int k24RhinoHp()
    { return 72; }

// the eighth level fighter with average scores and an eighteen constitution
// has seventy-six hit points - the D&D melee rationale (print 17-19)
inline int k24FighterHp()
    { return 76; }

// the Don Turnbull letter, attacks with no chance of hitting, attacks with a
// chance that missed, and telling attacks already landed - the D&D melee
// rationale (print 17-19)
inline bool k24TurnbullLetter()
    { return true; }

// higher levelfighters, the missing space as printed - the D&D melee
// rationale (print 17-19)
inline bool k24HighlevelPrint()
    { return true; }

// opponents of two of more levels, or as printed - the D&D melee rationale
// (print 17-19)
inline bool k24TwoOfMorePrint()
    { return true; }

// eight of nine eight-sided dice, or as printed - the D&D melee rationale
// (print 17-19)
inline bool k24EightOfNinePrint()
    { return true; }

// his of her environment, or as printed - the D&D melee rationale (print
// 17-19)
inline bool k24HisOfHerPrint()
    { return true; }

// combats of protected nature, protracted as printed - the D&D melee
// rationale (print 17-19)
inline bool k24ProtectedPrint()
    { return true; }

// the duplicated phrase - even excitement and action is not found in melee,
// and even - the D&D melee rationale (print 17-19)
inline bool k24DuplicatePhrase()
    { return true; }

// who can say them may, nay as printed - the D&D melee rationale (print
// 17-19)
inline bool k24SayThemMayPrint()
    { return true; }

// the garbled six-foot tall human of a javelin of lightning bolts - the D&D
// melee rationale (print 17-19)
inline bool k24JavelinGarble()
    { return true; }

// continually to a particular combat situations - the D&D melee rationale
// (print 17-19)
inline bool k24ParticularPrint()
    { return true; }

// its rival so-called improvements, rivals as printed - the D&D melee
// rationale (print 17-19)
inline bool k24RivalsPrint()
    { return true; }

// hit points a combination of constitution, skill at avoidance, luck and
// magical or divine factors - ten points a considerable wound to a rhino, a
// near miss to the fighter - the D&D melee rationale (print 17-19)
inline bool k24HitPointsRationale()
    { return true; }

// the Terry Kuntz unpublished Robin Hood system, a death blow with a saving
// throw increasing as the character gains experience - the D&D melee
// rationale (print 17-19)
inline bool k24KuntzSystem()
    { return true; }

// a double damage on a die score of twenty favors the players over the
// monsters and spoils the campaign balance - the D&D melee rationale (print
// 17-19)
inline bool k24DoubleDamage()
    { return true; }

// the Sean Cleary letter, clerics have but one chance to turn undead and no
// saving throw for those struck - the D&D melee rationale (print 17-19)
inline bool k24ClearyLetter()
    { return true; }

// two humans fighting four kobolds give about equal probabilities of hitting
// either side - the D&D melee rationale (print 17-19)
inline bool k24KoboldRatio()
    { return true; }

// the lightning stroke travels back along the javelin shaft, metal armor
// meriting a save for half or no damage - the D&D melee rationale (print
// 17-19)
inline bool k24JavelinTrajectory()
    { return true; }

// the AD and D proficiency system penalizes non-expertise rather than
// bonusing expertise, penalties do not change the campaign balance - the D&D
// melee rationale (print 17-19)
inline bool k24WeaponProficiency()
    { return true; }

// the TSR Design Department - Jean Wells for the feminine viewpoint and
// Lawrence Shick for science fantasy - the D&D melee rationale (print 17-19)
inline bool k24DesignDepartment()
    { return true; }

// ---- the DUNGEON board game variations (print 22-25) ----

// all pieces except the Wizard raised to a movement of ten spaces - the
// DUNGEON board game variations (print 22-25)
inline int k24NonWizardMove()
    { return 10; }

// the Wizard basic movement of five spaces per turn - the DUNGEON board game
// variations (print 22-25)
inline int k24WizardMove()
    { return 5; }

// the Wizard must roll eight or better on two dice to transfer a monster to
// another chamber - the DUNGEON board game variations (print 22-25)
inline int k24TransferMonsterRoll()
    { return 8; }

// three monsters fill a chamber to capacity, players not counting toward
// chamber occupancy - the DUNGEON board game variations (print 22-25)
inline int k24ChamberCapacity()
    { return 3; }

// a subdued monster killed outright on a roll of twelve, out of the game
// permanently - the DUNGEON board game variations (print 22-25)
inline int k24PermanentKillRoll()
    { return 12; }

// all monsters move a basic five spaces per turn, with no friendly monster
// within five movement spaces of another - the DUNGEON board game variations
// (print 22-25)
inline int k24MonsterMove()
    { return 5; }

// monster combat - two dice plus the monster level, eight or better hits -
// the DUNGEON board game variations (print 22-25)
inline int k24BeastCombatRoll()
    { return 8; }

// the modified Spell Combat Table - Transference at four or better for the
// Elf - the DUNGEON board game variations (print 22-25)
inline int k24XferElf()
    { return 4; }

// Transference at five or better for the Hero - the DUNGEON board game
// variations (print 22-25)
inline int k24XferHero()
    { return 5; }

// Transference at six or better for the Superhero - the DUNGEON board game
// variations (print 22-25)
inline int k24XferSuperhero()
    { return 6; }

// Transference at seven or better for the Wizard - the DUNGEON board game
// variations (print 22-25)
inline int k24XferWizard()
    { return 7; }

// the natural occurrence chance table - two through ten nothing enters - the
// DUNGEON board game variations (print 22-25)
inline int k24NeRollHi()
    { return 10; }

// eleven a natural occurrence enters - the DUNGEON board game variations
// (print 22-25)
inline int k24NaturalRoll()
    { return 11; }

// twelve a monster enters and attacks immediately - the DUNGEON board game
// variations (print 22-25)
inline int k24MonsterRoll()
    { return 12; }

// flood - six or better on two dice to avoid injury or drowning - the DUNGEON
// board game variations (print 22-25)
inline int k24FloodSave()
    { return 6; }

// poison gas - six or better on two dice to avoid - the DUNGEON board game
// variations (print 22-25)
inline int k24PoisonGasSave()
    { return 6; }

// explosive gas - eight or better on two dice to avoid - the DUNGEON board
// game variations (print 22-25)
inline int k24ExplosiveGasSave()
    { return 8; }

// a Wizard Lightning Bolt at the ceiling caves in the corridor on eight or
// better - the DUNGEON board game variations (print 22-25)
inline int k24CeilingBoltRoll()
    { return 8; }

// the party victory - Wizard thirty thousand, Superhero twenty thousand, two
// Elves at ten thousand each, summed and halved - the DUNGEON board game
// variations (print 22-25)
inline int k24PartyGold()
    { return 35000; }

// the five natural occurrence entries - the DUNGEON board game variations
// (print 22-25)
inline int k24OccCount()
    { return 5; }

// a Wizard using transference may move directly from any one chamber to any
// other chamber, irrespective of levels, with one card - the DUNGEON board
// game variations (print 22-25)
inline bool k24TransferChamber()
    { return true; }

// transference cards may be used offensively, thrown one space away like
// Lightning Bolts and Fireballs - the DUNGEON board game variations (print
// 22-25)
inline bool k24TransferOffensive()
    { return true; }

// magical monsters reply in kind to an unsuccessful magical attack, the
// vampire throwing the Fireball back - the DUNGEON board game variations
// (print 22-25)
inline bool k24MagicalReply()
    { return true; }

// monsters subdued rather than killed, serving their masters until the end of
// the game - the DUNGEON board game variations (print 22-25)
inline bool k24SubdueRule()
    { return true; }

// a friendly monster entering a chamber with two or fewer monsters
// immediately loses subdued status and becomes top monster - the DUNGEON
// board game variations (print 22-25)
inline bool k24ChamberRefuge()
    { return true; }

// a seriously wounded monster retreats to the nearest chamber of its own
// level for healing, reappearing when restored - the DUNGEON board game
// variations (print 22-25)
inline bool k24MonsterHealing()
    { return true; }

// a friendly monster defeating a player loses subdued status, the card
// returned with its prize to the nearest empty room - the DUNGEON board game
// variations (print 22-25)
inline bool k24PrizeReturn()
    { return true; }

// the Non-Wizard Beast Master must fight and resubdue his own friendly
// monsters face-to-face - the DUNGEON board game variations (print 22-25)
inline bool k24NonWizardResubdue()
    { return true; }

// the Wizard Beast Master control is absolute unless his status changes,
// killed and re-entering the game as a Superhero - the DUNGEON board game
// variations (print 22-25)
inline bool k24WizardControl()
    { return true; }

// the option letting a Wizard direct friendly monsters against any monster,
// armies of monsters and very long turns - the DUNGEON board game variations
// (print 22-25)
inline bool k24MonsterArmies()
    { return true; }

// killed monsters placed face-down in a DEAD pile, the latest kills on the
// bottom - the DUNGEON board game variations (print 22-25)
inline bool k24DeadPile()
    { return true; }

// the cave-in die - one and two behind, three and four on the space, five and
// six ahead, one-two and five-six sealing with DEBRIS chits - the DUNGEON
// board game variations (print 22-25)
inline bool k24CaveInPlacement()
    { return true; }

// digging for buried prizes - one and two found, three through five keep
// digging, six another cave-in - the DUNGEON board game variations (print
// 22-25)
inline bool k24BuriedTreasure()
    { return true; }

// NO WAY to dig oneself out with the tools at hand, such a player dies, the
// monsters digging out on one or two - the DUNGEON board game variations
// (print 22-25)
inline bool k24SealedDeath()
    { return true; }

// player combat before monster combat, the monster choosing the strongest
// first - Wizard, Superhero, Hero, Elf, attacking once per turn - the DUNGEON
// board game variations (print 22-25)
inline bool k24PartyCombatOrder()
    { return true; }

// a Wizard party member may cast spells into a room only if no other party
// members are in it - the DUNGEON board game variations (print 22-25)
inline bool k24WizardRoomSpell()
    { return true; }

// the party victory total - add the individual victory levels together and
// divide by two - the DUNGEON board game variations (print 22-25)
inline bool k24PartyVictoryRule()
    { return true; }

// NO WAY to ambush - the seven players in three groups pitched battle, one
// dead, three limping, the rest stunned and bleeding - the DUNGEON board game
// variations (print 22-25)
inline bool k24AmbushForbidden()
    { return true; }

// the Mid-Columbia Wargaming Society of Richland, Washington, George Laking
// and the variants used singly and in combination - the DUNGEON board game
// variations (print 22-25)
inline bool k24MidColumbia()
    { return true; }

// the occurrence band floors - bats at two, flood at five, poison gas at
// seven, explosive gas at nine, cave-in at eleven
inline int k24OccLo(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 7;
        case 3:
            return 9;
        case 4:
            return 11;
        default:
            return -99;
        }
    }

// the occurrence band ceilings - bats at four, flood at six, poison gas at
// eight, explosive gas at ten, cave-in at twelve
inline int k24OccHi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 10;
        case 4:
            return 12;
        default:
            return -99;
        }
    }

// ---- the Swiss Renaissance army (print 26) ----

// the average Renaissance pike sixteen to eighteen feet long - the Swiss
// Renaissance army (print 26)
inline int k24PikeLow()
    { return 16; }

// the eighteen foot upper bound of the average pike - the Swiss Renaissance
// army (print 26)
inline int k24PikeHigh()
    { return 18; }

// the Swiss monster pike, twenty-one feet long - the Swiss Renaissance army
// (print 26)
inline int k24SwissPikeFeet()
    { return 21; }

// with three feet of steel protecting the tip from swords and axes - the
// Swiss Renaissance army (print 26)
inline int k24SwissPikeSteel()
    { return 3; }

// by 1500 eighty to one hundred percent of the Swiss light troops armed with
// handguns and arquebus - the Swiss Renaissance army (print 26)
inline int k24HandgunLow()
    { return 80; }

// the one hundred percent upper bound of the handgun proportion - the Swiss
// Renaissance army (print 26)
inline int k24HandgunHigh()
    { return 100; }

// the crossbow and handgun skirmishers, ten to thirty percent of the entire
// army - the Swiss Renaissance army (print 26)
inline int k24SkirmishLow()
    { return 10; }

// the thirty percent upper bound of the skirmisher proportion - the Swiss
// Renaissance army (print 26)
inline int k24SkirmishHigh()
    { return 30; }

// the three phalanxes of the order of battle - a Van, a Main Battle and a
// Rear - the Swiss Renaissance army (print 26)
inline int k24PhalanxCount()
    { return 3; }

// the halberd, the pike and the crossbow responsible for the Swiss rise - the
// Swiss Renaissance army (print 26)
inline bool k24ThreeWeapons()
    { return true; }

// Charles The Bold and Maximillian of Austria, both victims of the halberd
// blade - the Swiss Renaissance army (print 26)
inline bool k24HalberdVictims()
    { return true; }

// the halberd - a broad axe blade, a long point for thrusting, a hook to pull
// riders from horses - the Swiss Renaissance army (print 26)
inline bool k24HalberdShape()
    { return true; }

// The sturdy, mountaineers, the comma splice as printed - the Swiss
// Renaissance army (print 26)
inline bool k24SturdyComma()
    { return true; }

// a bravery Swiss mountaineer, brave as printed - the Swiss Renaissance army
// (print 26)
inline bool k24BraveryPrint()
    { return true; }

// The well known legend of William Tell, illustrates - the comma splice as
// printed - the Swiss Renaissance army (print 26)
inline bool k24TellSplice()
    { return true; }

// the text echelons the battles from the right while the order-of-battle
// caption prints echeloned from the left - the Swiss Renaissance army (print
// 26)
inline bool k24EchelonContradiction()
    { return true; }

// the van strikes the flank as the main battle pushes the center, the rear
// providing the final push - the Swiss Renaissance army (print 26)
inline bool k24PhalanxTasks()
    { return true; }

// the only infantry of the age, perhaps of any age, capable of taking the
// offensive against cavalry - the Swiss Renaissance army (print 26)
inline bool k24OffenseVsCavalry()
    { return true; }

// in contests between the Swiss and their Landsknecht copies the Swiss were
// almost always victorious - the Swiss Renaissance army (print 26)
inline bool k24LandsknechtDuels()
    { return true; }

// the individual soldier poor and unarmored, a leather jerkin and an open
// helmet - the Swiss Renaissance army (print 26)
inline bool k24PoorUnarmored()
    { return true; }

// the Swiss Guards of the Vatican in orange and blue stripes - the Swiss
// Renaissance army (print 26)
inline bool k24VaticanStripes()
    { return true; }

// the Swiss downfall in their total disregard for artillery - La Biocca for
// Bicocca and Ravenna, the Spanish massed guns - the Swiss Renaissance army
// (print 26)
inline bool k24ArtilleryDownfall()
    { return true; }

// the major part of the French infantry through the era, remaining through
// the Napoleonic Wars and forming the basis for the Foreign Legion - the
// Swiss Renaissance army (print 26)
inline bool k24FrenchService()
    { return true; }

// next time - the Condotiere and the Papacy - the Swiss Renaissance army
// (print 26)
inline bool k24NextCondotiere()
    { return true; }

// The Irresistible Force by Gary Gygas in TD-22, Gygax as printed at the
// reference note - the Swiss Renaissance army (print 26)
inline bool k24GygasPrint()
    { return true; }

// ---- the psionics profession variant (print 28-29) ----

// intuition a fifteen percent chance per level of mastery - the psionics
// profession variant (print 28-29)
inline int k24IntuitionPct()
    { return 15; }

// up to a ninety percent maximum, then fifteen percent per level for
// intuiting specific knowledge - the psionics profession variant (print
// 28-29)
inline int k24IntuitionMax()
    { return 90; }

// the ectoplasmic replica, armor class nine, hit only by magic or psionics,
// immune to normal weapons - the psionics profession variant (print 28-29)
inline int k24EctoplasmAc()
    { return 9; }

// the ectoplasm sent at twelve inches per turn - the psionics profession
// variant (print 28-29)
inline int k24EctoplasmSpeed()
    { return 12; }

// up to forty-eight inches away, acting as a Wizard Eye - the psionics
// profession variant (print 28-29)
inline int k24EctoplasmRange()
    { return 48; }

// the Cold freezing a one-foot radius circle per level of mastery - the
// psionics profession variant (print 28-29)
inline int k24ColdRadius()
    { return 1; }

// one turn to lower the temperature by one hundred degrees F - the psionics
// profession variant (print 28-29)
inline int k24ColdDegrees()
    { return 100; }

// at a cost of ten plus ten for each turn maintained - the psionics
// profession variant (print 28-29)
inline int k24ColdCost()
    { return 10; }

// magnetism cannot move something more than three times as heavy as the
// psychic - the psionics profession variant (print 28-29)
inline int k24MagnetismWeight()
    { return 3; }

// the magnetism range of five feet per level - the psionics profession
// variant (print 28-29)
inline int k24MagnetismRange()
    { return 5; }

// after the fourth level of mastery the electricity can be fired - the
// psionics profession variant (print 28-29)
inline int k24ElectricityLevel()
    { return 4; }

// gravity control works in a five-foot radius per level - the psionics
// profession variant (print 28-29)
inline int k24GravityRadius()
    { return 5; }

// objects become weightless or increase in weight five-fold, at fifteen
// psychics strength per turn - the psionics profession variant (print 28-29)
inline int k24GravityFold()
    { return 5; }

// retrocognition, one week back per level of mastery at a cost of two per
// week seen - the psionics profession variant (print 28-29)
inline int k24RetroWeekCost()
    { return 2; }

// hypercognition a ten percent chance per level, at a cost of one for each
// ten percent chance - the psionics profession variant (print 28-29)
inline int k24HyperPct()
    { return 10; }

// psyche transfer of a non-humanoid body at ten percent effectiveness per
// week - the psionics profession variant (print 28-29)
inline int k24TransferPct()
    { return 10; }

// the psyche transfer cost of five plus five for each hit dice the victim is
// above the psychic - the psionics profession variant (print 28-29)
inline int k24TransferCost()
    { return 5; }

// Speak Languages lasting one turn per level at a cost of ten - the psionics
// profession variant (print 28-29)
inline int k24SpeakCost()
    { return 10; }

// the infravision cost, working one turn per level of mastery - the psionics
// profession variant (print 28-29)
inline int k24InfravisionCost()
    { return 5; }

// the Light corona maintained at two per turn - the psionics profession
// variant (print 28-29)
inline int k24LightCost()
    { return 2; }

// stun allowing ten feet of range per level, up to one hundred - the psionics
// profession variant (print 28-29)
inline int k24StunRange()
    { return 10; }

// the thirty hit point foe exposed to a ten point Stun moving at one-third
// speed - the psionics profession variant (print 28-29)
inline int k24StunSpeedDiv()
    { return 3; }

// neural disruption reducing prime requisites one for every five psychic
// strength employed - the psionics profession variant (print 28-29)
inline int k24NeuralPerPoints()
    { return 5; }

// spirit form at ten per turn, insubstantial even to magic weapons, carrying
// nothing but cotton or woolen clothing - the psionics profession variant
// (print 28-29)
inline int k24SpiritCost()
    { return 10; }

// molecular melding at five, lasting one turn per level of mastery - the
// psionics profession variant (print 28-29)
inline int k24MeldCost()
    { return 5; }

// the molecular shield - armor class one for every two psychic strength per
// melee round - the psionics profession variant (print 28-29)
inline int k24ShieldCost()
    { return 2; }

// the molecular dart a Magic Missile at five each, range ten feet per level
// of mastery - the psionics profession variant (print 28-29)
inline int k24DartRange()
    { return 10; }

// greater manifestations assigned only on a percentile roll of ninety-one to
// one hundred - the psionics profession variant (print 28-29)
inline int k24GreaterFloor()
    { return 91; }

// once an Anti-Psi power is obtained, no check for another oftener than every
// five levels - the psionics profession variant (print 28-29)
inline int k24AntiPsiGap()
    { return 5; }

// the eight subsentient telepathy cost steps - the psionics profession
// variant (print 28-29)
inline int k24SubsentientCount()
    { return 8; }

// the six Anti-Psi power costs - the psionics profession variant (print
// 28-29)
inline int k24AntiPsiCount()
    { return 6; }

// Bonewit Authentic Thaumaturgy as the idea source, as printed - the psionics
// profession variant (print 28-29)
inline bool k24BonewitsPrint()
    { return true; }

// Clairenses for Clairsenses, the Clairvoyance and Clairaudience combination
// - the psionics profession variant (print 28-29)
inline bool k24ClairensesPrint()
    { return true; }

// Telepathic Projection printed twice in the cognitive greater list - the
// psionics profession variant (print 28-29)
inline bool k24ProjectionTwicePrint()
    { return true; }

// fifteen psychics strength per turn, the gravity control print - the
// psionics profession variant (print 28-29)
inline bool k24PsychicsPrint()
    { return true; }

// SPEAR LANGUAGES, Speak as printed - the psionics profession variant (print
// 28-29)
inline bool k24SpearPrint()
    { return true; }

// sig language, sign as printed - the psionics profession variant (print
// 28-29)
inline bool k24SigPrint()
    { return true; }

// hypercognition is a super-intuitive, the missing noun as printed - the
// psionics profession variant (print 28-29)
inline bool k24SuperIntuitivePrint()
    { return true; }

// the half-ile roll of ninety-one to one hundred, percentile as printed - the
// psionics profession variant (print 28-29)
inline bool k24HalfilePrint()
    { return true; }

// the first power random, thereafter each new power from an adjacent one on
// the list, Cell Adjustment entitling Infravision or Reduction - the psionics
// profession variant (print 28-29)
inline bool k24AdjacentAcquisition()
    { return true; }

// the kinetic powers to Fighters and Thieves, the cognitive to Clerics,
// Magicians manifesting both, Bards, Illusionists and Sages cognitive - the
// psionics profession variant (print 28-29)
inline bool k24KineticAssignment()
    { return true; }

// Druids barred from psychic powers, with an exception for mostly dungeon
// adventures since so many Druid spells are useless underground - the
// psionics profession variant (print 28-29)
inline bool k24DruidException()
    { return true; }

// the standard psionic attack and defense forms available as provided in
// Eldritch Wizardry, functioning just perfectly as they are - the psionics
// profession variant (print 28-29)
inline bool k24EwFormsUnchanged()
    { return true; }

// the Stun acting as a combination Slow and Paralysis, the effects lasting as
// long as a Sleep spell - the psionics profession variant (print 28-29)
inline bool k24StunSleep()
    { return true; }

// the mammal one, bird two, reptile three, amphibian four, fish and insect
// five, plants six, monstrous animals seven, and plants again eight
inline int k24SubsentientCost(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return -99;
        }
    }

// the Deflection five, Immunity ten, Reversal fifteen, Return twenty, Filter
// twenty-five, Tuning twenty-five
inline int k24AntiPsiCost(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 25;
        case 5:
            return 25;
        default:
            return -99;
        }
    }

// ---- the disease charts (print 29) ----

// the roll of ninety-two, death after forty-eight days - the disease charts
// (print 29)
inline int k24FatalDays92()
    { return 48; }

// the roll of ninety-seven, seven months - the disease charts (print 29)
inline int k24FatalMonths97()
    { return 7; }

// the roll of ninety-nine, nine months - the disease charts (print 29)
inline int k24FatalMonths99()
    { return 9; }

// the roll of zero-zero, ten months - the disease charts (print 29)
inline int k24FatalMonths00()
    { return 10; }

// the twenty symptoms, Pain through Hallucinations - the disease charts
// (print 29)
inline int k24SymptomCount()
    { return 20; }

// the twenty-nine printed fatality rows - the disease charts (print 29)
inline int k24FatalCount()
    { return 29; }

// the four symptom-number bands - the disease charts (print 29)
inline int k24SymptomBandCount()
    { return 4; }

// Buettuer for Buettner in the byline - the disease charts (print 29)
inline bool k24BuettuerPrint()
    { return true; }

// the fatality table skips ninety-eight entirely, seven months at
// ninety-seven then nine months at ninety-nine - the disease charts (print
// 29)
inline bool k24FatalitySkips98()
    { return true; }

// for curses and Cause Disease spells from anti-clerics, diseases of unknown
// characteristics - the disease charts (print 29)
inline bool k24DiseasePurpose()
    { return true; }

// a saving throw given - the symptoms suffered for the given period, then
// recovery - the disease charts (print 29)
inline bool k24SaveThenRecover()
    { return true; }

// the symptoms - Pain, Shortness of Breath, Paralysis, Sensory Loss with its
// sight, hearing and numbness sub-list, Fever, Chills, Skin sores, Nausea,
// Rash, Drowsiness, Insanity, Bleeding, Hyperactivity, Coughing and Sneezing,
// Chest Pains, Loss of Energy, Diarrhea, Tumors, Swelling and Hallucinations
// - the disease charts (print 29)
inline bool k24SymptomList()
    { return true; }

// the fatality band floors - one through nine the immediate through
// twenty-four hour rows, the band lows ten through eighty-one
inline int k24FatalLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 16;
        case 11:
            return 21;
        case 12:
            return 26;
        case 13:
            return 31;
        case 14:
            return 41;
        case 15:
            return 51;
        case 16:
            return 61;
        case 17:
            return 71;
        case 18:
            return 81;
        case 19:
            return 90;
        case 20:
            return 91;
        case 21:
            return 92;
        case 22:
            return 93;
        case 23:
            return 94;
        case 24:
            return 95;
        case 25:
            return 96;
        case 26:
            return 97;
        case 27:
            return 99;
        case 28:
            return 100;
        default:
            return -99;
        }
    }

// the fatality band ceilings - the ninety-seven row followed directly by the
// ninety-nine row, the ninety-eight skip pinned in the grid itself
inline int k24FatalHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 15;
        case 10:
            return 20;
        case 11:
            return 25;
        case 12:
            return 30;
        case 13:
            return 40;
        case 14:
            return 50;
        case 15:
            return 60;
        case 16:
            return 70;
        case 17:
            return 80;
        case 18:
            return 89;
        case 19:
            return 90;
        case 20:
            return 91;
        case 21:
            return 92;
        case 22:
            return 93;
        case 23:
            return 94;
        case 24:
            return 95;
        case 25:
            return 96;
        case 26:
            return 97;
        case 27:
            return 99;
        case 28:
            return 100;
        default:
            return -99;
        }
    }

// the band ceilings - rolls one-three, four-five, six-seven and eight
inline int k24SymBandHi(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 7;
        case 3:
            return 8;
        default:
            return -99;
        }
    }

// the symptom counts - one, two, three and four symptoms
inline int k24SymBandNum(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return -99;
        }
    }

// ---- the Petal Throne name generator (print 39) ----

// the eight by eight name generator grid - the Petal Throne name generator
// (print 39)
inline int k24NameGridSide()
    { return 8; }

// the sixty-four name segments, derived from words in use on Tekumel - the
// Petal Throne name generator (print 39)
inline int k24NameSegments()
    { return 64; }

// a pair of eight-sided dice to derive a numbered segment - the Petal Throne
// name generator (print 39)
inline int k24NameDiceSides()
    { return 8; }

// two or three segments provide the most euphonic results - the Petal Throne
// name generator (print 39)
inline int k24EuphonicLow()
    { return 2; }

// the three segment upper bound of the euphonic range - the Petal Throne name
// generator (print 39)
inline int k24EuphonicHigh()
    { return 3; }

// G. Arthur Rahman byline - the Petal Throne name generator (print 39)
inline bool k24RahmanByline()
    { return true; }

// the contents printing Naming Things in EPT against the byline Naming
// People, Places and Things In Petal Throne - the Petal Throne name generator
// (print 39)
inline bool k24TocMismatch()
    { return true; }

// the grid a verified permutation of one through sixty-four, checked - the
// sorted values equal the full range - the Petal Throne name generator (print
// 39)
inline bool k24VerifiedPermutation()
    { return true; }

// the Tekumel languages derive from Tamil, Arabic and Mayan sources, Tsolyani
// providing most of the segments - the Petal Throne name generator (print 39)
inline bool k24BarkerSources()
    { return true; }

// too many Mariuses, Borises and Igors walking the streets of Jakalla - the
// Petal Throne name generator (print 39)
inline bool k24JakallaFillers()
    { return true; }

// Durritkoi, Nalljatoranu and Khircholkar, the combined segment examples -
// the Petal Throne name generator (print 39)
inline bool k24ExampleNames()
    { return true; }

// ---- the Monty Haul satire (print 42-43) ----

// the Bronze Dragon over eighty hands long, rearing to more than half that -
// the Monty Haul satire (print 42-43)
inline int k24BronzeHands()
    { return 80; }

// the otherwise perfectly healthy five-hundred-year-old dragon - the Monty
// Haul satire (print 42-43)
inline int k24DragonAge()
    { return 500; }

// the gold, silver and gems worth about one million - the Monty Haul satire
// (print 42-43)
inline int k24TreasureValue()
    { return 1000000; }

// a batch of five Wizards of at least the sixteenth level tossing eight-level
// spells - the Monty Haul satire (print 42-43)
inline int k24WizardLevel()
    { return 16; }

// the five Wizards of the batch - the Monty Haul satire (print 42-43)
inline int k24WizardCount()
    { return 5; }

// Monty pitched a twenty-nine die fire ball at the altar - the Monty Haul
// satire (print 42-43)
inline int k24FireballDice()
    { return 29; }

// the seven ladies at the plant altar - the Monty Haul satire (print 42-43)
inline int k24AltarLadies()
    { return 7; }

// the last of the Thunder Symbols killed two of the seven - the Monty Haul
// satire (print 42-43)
inline int k24LadiesSlain()
    { return 2; }

// the ladies took care of Joe with five death rays - the Monty Haul satire
// (print 42-43)
inline int k24DeathRayCount()
    { return 5; }

// Bronze Dragons do not breathe poison gas and they are not evil - the
// Freddie mistake - the Monty Haul satire (print 42-43)
inline bool k24BronzeError()
    { return true; }

// an archdured beded in lincoln green, as printed - the Monty Haul satire
// (print 42-43)
inline bool k24ArchduredPrint()
    { return true; }

// the plalin, paladin as printed - the Monty Haul satire (print 42-43)
inline bool k24PlalinPrint()
    { return true; }

// deomon energy to power the things, demon as printed - the Monty Haul satire
// (print 42-43)
inline bool k24DeomonPrint()
    { return true; }

// we were wizards of power!! used a wall of force, the missing subject as
// printed - the Monty Haul satire (print 42-43)
inline bool k24PowerPrint()
    { return true; }

// the twenty-nine die fire ball, dice as printed - the Monty Haul satire
// (print 42-43)
inline bool k24DiePrint()
    { return true; }

// druddy three times for druidic - the Monty Haul satire (print 42-43)
inline bool k24DruddyPrint()
    { return true; }

// dispell magic, dispel as printed - the Monty Haul satire (print 42-43)
inline bool k24DispellPrint()
    { return true; }

// cut out losses and run, cut our as printed - the Monty Haul satire (print
// 42-43)
inline bool k24CutOutPrint()
    { return true; }

// the one truly liberated women game and one of the few gamers, games as
// printed - the Monty Haul satire (print 42-43)
inline bool k24GamersPrint()
    { return true; }

// the Harp of Discord, or was it Datcord - the Monty Haul satire (print
// 42-43)
inline bool k24HarpDatcord()
    { return true; }

// the Rod of Seven Parts with all seven parts activated at once - the Monty
// Haul satire (print 42-43)
inline bool k24RodOfSeven()
    { return true; }

// the Ernie portable hole holding the pieces of the Ernie character, that
// even a wish could not bring back - the Monty Haul satire (print 42-43)
inline bool k24PortableHole()
    { return true; }

// the evil purpose sword wrapped in demon skin, the paladin insisting on its
// destruction - the Monty Haul satire (print 42-43)
inline bool k24DemonSkinSword()
    { return true; }

// the five Wizards summoning a gold dragon, an iron golem and a vampire in a
// series of random rolls very hard to believe - the Monty Haul satire (print
// 42-43)
inline bool k24SummonedMonsters()
    { return true; }

// the ring of Gax, the Horn of Change, the Jacinth of Inestimable Beauty and
// the Rod of Seven Parts, the do or die finale - the Monty Haul satire (print
// 42-43)
inline bool k24ArtifactFinale()
    { return true; }

// the high priestess leapt on two dead comrades, touched two others, and the
// whole group vanished to another plane - the Monty Haul satire (print 42-43)
inline bool k24PriestessEscape()
    { return true; }

// the closing screams - white powder, gold flecked, plant vines all over the
// tower walls - the Monty Haul satire (print 42-43)
inline bool k24VineFinale()
    { return true; }

}   // namespace rules
