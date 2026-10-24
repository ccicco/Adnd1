// =========================================================================================
// Adnd1 - rules/mm2fg.h
// THE MM2 LETTERS FG WALK - THE FALCON, FOO CREATURE, GIANT AND GRUE TURNS
// (the falcon and hawk table, the firefriend, the giant fly table, the foo
// creatures, the forester bane, the formian table and the froghemoth pp.
// 64-67, the galeb duhr, the GIANT family head with the fomorian, firbolg and
// verbeeg, the gibbering mouther, the gloomwing, the goat, the gorgimera, the
// greenhag, the grippli, the grig, the grim, the GRUE family head with the
// chaggrin, harginn, ildriss and varrdig pp. 68-74), promoted to the live
// registry
// census 727 -> 728.
//
// Round ten of the MM2 arc, the seventh PART-LETTER walk and the FIRST
// TWO-LETTER pass (the user Go call on the landed MM2 letter E walk: the
// letters F and G close together, the falcon and hawk table opens p. 64 and
// the varrdig tail closes p. 74 - the FG-FLIP round, both the Letter F and
// the Letter G gap boxes flip to closed). The capture is the Curtiss PDF
// upload cross-checked against the archive.org djvu OCR, the contested cells
// settled book-internal first: the firbolg bat-away roll reads 6 or better
// (the 75% arithmetic settles it over the capture "8 or better" misread); the
// froghemoth damage cell stays capture verbatim; the harginn treasure letter
// I follows the varrdig "1/2 x F" print pattern
//
namespace rules {

// ---- the MM2 letters FG walk round pins (the R805 census) ----

// The MM2 letters FG walk round: the falcon, foo creature, giant and grue
// turns, the first TWO-LETTER pass (the user Go call on the landed MM2 letter
// E walk)
inline int mm2fgRound()
    { return 805; }

// The registry census before the R805 promotion (the landed R804 count)
inline int mm2fgRegistryBefore()
    { return 622; }

// The registry census after the R805 promotion (28 defs)
inline int mm2fgRegistryAfter()
    { return 650; }

// The R805 def count (the 28 stat-block columns of the letters F and G)
inline int mm2fgDefCount()
    { return 28; }

// The pin-time entry count on pp. 64-74 (23 stat-block headings plus the
// GIANT and GRUE doctrine-only family heads)
inline int mm2fgEntryCount()
    { return 25; }

// The stat-block headings of the FG walk (7 letter-F headings, 16 letter-G
// headings)
inline int mm2fgStatBlockHeadings()
    { return 23; }

// The doctrine-only family heads (the GIANT head p. 68 and the GRUE,
// ELEMENTAL head p. 72, no stat blocks of their own)
inline int mm2fgDoctrineHeads()
    { return 2; }

// The letter-F headings (the falcon and hawk table, the firefriend, the giant
// fly table, the foo creatures, the forester bane, the formian table and the
// froghemoth)
inline int mm2fgLetterFHeadings()
    { return 7; }

// The letter-G headings (the galeb duhr, the GIANT head, the fomorian, the
// firbolg, the verbeeg, the gibbering mouther, the gloomwing, the goat, the
// gorgimera, the greenhag, the grippli, the grig, the grim, the GRUE head,
// the chaggrin, the harginn, the ildriss and the varrdig)
inline int mm2fgLetterGHeadings()
    { return 18; }

// The row count of the falcon-to-varrdig stat grid
inline int mm2fgFgStatRows()
    { return 28; }

// The gap report closed boxes after the FG-flip (the Letter F and Letter G
// boxes join A through E)
inline int mm2fgGapClosed()
    { return 12; }

// The gap report open boxes after the FG-flip
inline int mm2fgGapOpen()
    { return 25; }

// The letter-F and letter-G index entries owned by earlier rounds (the faerie
// dragon, the giant dragonfly and the gray ones, the duergar cross-reference)
inline int mm2fgPriorOwnedEntries()
    { return 3; }

// The faerie dragon landed with the R803 dragon walk (pp. 38-39, a letter-F
// index entry)
inline int mm2fgFaerieDragonOwningRound()
    { return 803; }

// The giant dragonfly landed with the R803 dragon walk (a letter-G index
// entry)
inline int mm2fgGiantDragonflyOwningRound()
    { return 803; }

// The gray ones (the duergar cross-reference) landed with the R803 dragon
// walk (a letter-G index entry)
inline int mm2fgGrayOnesOwningRound()
    { return 803; }

// The GIANT family head p. 68 groups the fomorian, firbolg and verbeeg stat
// blocks beneath its heading
inline int mm2fgGiantHeadSubEntryCount()
    { return 3; }

// The GRUE, ELEMENTAL family head p. 72 groups the chaggrin, harginn, ildriss
// and varrdig stat blocks beneath its heading
inline int mm2fgGrueHeadSubEntryCount()
    { return 4; }

// The GIANT family head p. 68 is a grouping heading with no stat block of its
// own (the fomorian, firbolg and verbeeg blocks follow it)
inline bool mm2fgGiantHeadIsDoctrineOnlyHeading()
    { return true; }

// The GRUE, ELEMENTAL family head p. 72 is a grouping heading with no stat
// block of its own (the chaggrin, harginn, ildriss and varrdig blocks follow
// it)
inline bool mm2fgGrueHeadIsDoctrineOnlyHeading()
    { return true; }

// The falcon and hawk table p. 64 carries two stat-block columns (the Small
// and the Large falcon)
inline bool mm2fgFalconTableTwoColumns()
    { return true; }

// The giant fly table p. 65 carries two stat-block columns (the bluebottle
// and the horsefly)
inline bool mm2fgFlyTableTwoColumns()
    { return true; }

// The foo creatures table p. 65 carries two stat-block columns (the foo dog
// and the foo lion)
inline bool mm2fgFooTableTwoColumns()
    { return true; }

// The formian table p. 66 carries three stat-block columns (the myrmarch, the
// warrior and the worker)
inline bool mm2fgFormianTableThreeColumns()
    { return true; }

// The firbolg bat-away success roll reads a 6 or better on 1d20 (the capture
// "8 or better" the OCR misread, the 75% arithmetic the settle)
inline bool mm2fgFirbolgBatAwayReadsSix()
    { return true; }

// The firbolg alignment reads neutral (chaotic good) (the capture "cheotic"
// the OCR misread)
inline bool mm2fgFirbolgAlignmentChaoticGood()
    { return true; }

// The froghemoth damage cell "5d10 or 5-8 (=4)" stays capture verbatim (the
// djvu "+4" the misread; the 1eonline settle voice unreachable)
inline bool mm2fgFroghemothDamageKeepsCaptureForm()
    { return true; }

// The harginn parenthetical treasure reads the letter I (the capture digit
// "1" the misread, the varrdig "1/2 x F" print pattern the settle)
inline bool mm2fgHarginnTreasureReadsLetterI()
    { return true; }

// The verbeeg parenthetical treasure reads the K,L,M letters (the capture
// "K.L.M." periods the OCR misread)
inline bool mm2fgVerbeegTreasureReadsKLM()
    { return true; }

// The grig hit dice "1/2+1 (2-5 hit points)" reads the print hp range
// midpoint 3 for avgHp (the atomie precedent)
inline bool mm2fgGrigHitDicePrintHpRange()
    { return true; }

// The gorgimera armor class "5/2" is the composite lion/gorgon cell (the grid
// reads the lion 5)
inline bool mm2fgGorgimeraArmorClassComposite()
    { return true; }

// The galeb duhr hit dice "8-10" ranged cell reads the low end 8 (the kuei
// precedent)
inline bool mm2fgGalebDuhrHdReadsLowEnd()
    { return true; }

// The ildriss move reads the 3-inch rolling-fog rate for the ground move (the
// 24-inch rate is the otherwise-form flight)
inline bool mm2fgIldrissMoveReadsFogForm()
    { return true; }

// ---- the falcon pins (the R805 MM2 letters FG walk) ----

// The falcon, small full kill xp (15 + 1/hp x 2 avg; level I)
inline int mm2fgFalconSmallXpValue()
    { return 17; }

// The falcon, small printed xp level (I)
inline int mm2fgFalconSmallXpLevel()
    { return 1; }

// The falcon, large full kill xp (25 + 1/hp x 3 avg; level I)
inline int mm2fgFalconLargeXpValue()
    { return 28; }

// The falcon, large printed xp level (I)
inline int mm2fgFalconLargeXpLevel()
    { return 1; }

// The chance a falcon nest holds a small, shiny item such as a coin or gem
inline int mm2fgFalconNestShinyPct()
    { return 5; }

// The plummeting-dive height (from 100 feet or higher)
inline int mm2fgFalconDiveHeightFeet()
    { return 100; }

// The dive to-hit bonus (double talon damage, no beak attack)
inline int mm2fgFalconDiveToHitBonus()
    { return 2; }

// The chance a beak hit on unprotected eyes actually blinds 1 eye
inline int mm2fgFalconBeakBlindPct()
    { return 25; }

// ---- the firefriend pins (the R805 MM2 letters FG walk) ----

// The firefriend (giant firefly) full kill xp (36 + 2/hp x 7 avg; level II)
inline int mm2fgFirefriendXpValue()
    { return 50; }

// The firefriend (giant firefly) printed xp level (II)
inline int mm2fgFirefriendXpLevel()
    { return 2; }

// The greenish-light beam diameter (about 3 inches)
inline int mm2fgFirefriendBeamInches()
    { return 3; }

// The greenish-light beam length (up to 14 feet)
inline int mm2fgFirefriendBeamFeet()
    { return 14; }

// The beam damage low end (5-20 on struck flesh)
inline int mm2fgFirefriendBeamDmgMin()
    { return 5; }

// The beam damage high end (save vs. wands for one-half)
inline int mm2fgFirefriendBeamDmgMax()
    { return 20; }

// The firefriend lifespan (about 10 years)
inline int mm2fgFirefriendLifespanYears()
    { return 10; }

// ---- the giant fly pins (the R805 MM2 letters FG walk) ----

// The fly, giant (bluebottle) full kill xp (35 + 3/hp x 10 avg; level II)
inline int mm2fgFlyBluebottleXpValue()
    { return 65; }

// The fly, giant (bluebottle) printed xp level (II)
inline int mm2fgFlyBluebottleXpLevel()
    { return 2; }

// The fly, giant (horsefly) full kill xp (150 + 6/hp x 21 avg; level IV)
inline int mm2fgFlyHorseflyXpValue()
    { return 276; }

// The fly, giant (horsefly) printed xp level (IV)
inline int mm2fgFlyHorseflyXpLevel()
    { return 4; }

// The giant fly backward-spring distance (3 inches in 1 segment)
inline int mm2fgFlyJumpInches()
    { return 3; }

// The giant fly jump height (airborne at 1 inch)
inline int mm2fgFlyJumpHeightInches()
    { return 1; }

// The giant fly jump takes place in 1 segment
inline int mm2fgFlyJumpSegments()
    { return 1; }

// The bluebottle bite chance (per hit) of inflicting disease
inline int mm2fgFlyBluebottleDiseasePct()
    { return 10; }

// ---- the foo creature pins (the R805 MM2 letters FG walk) ----

// The foo dog full kill xp (1200 + 12/hp x 31 avg; level VII)
inline int mm2fgFooDogXpValue()
    { return 1572; }

// The foo dog printed xp level (VII)
inline int mm2fgFooDogXpLevel()
    { return 7; }

// The foo lion full kill xp (2850 + 16/hp x 49 avg; level VII)
inline int mm2fgFooLionXpValue()
    { return 3634; }

// The foo lion printed xp level (VII)
inline int mm2fgFooLionXpLevel()
    { return 7; }

// The foo dog effective hit dice against Evil opponents
inline int mm2fgFooDogAsHd()
    { return 10; }

// The foo lion effective hit dice against Evil opponents
inline int mm2fgFooLionAsHd()
    { return 15; }

// The foo bonus vs. lawful evil (especially devils), to hit and damage
inline int mm2fgFooLawfulEvilBonus()
    { return 1; }

// The barking roar chance to summon kin (1-6 dogs, 1-2 lions) after 7+ rounds
inline int mm2fgFooRoarSummonPct()
    { return 20; }

// The rounds the roar must continue before the summons roll
inline int mm2fgFooRoarRounds()
    { return 7; }

// The Astral Plane newcomer arrival low end (1-10 rounds)
inline int mm2fgFooNewcomerRoundsMin()
    { return 1; }

// The Astral Plane newcomer arrival high end
inline int mm2fgFooNewcomerRoundsMax()
    { return 10; }

// The evil opponents penalty to hit and damage dice vs. foo creatures
inline int mm2fgFooEvilAttackPenalty()
    { return 1; }

// The foo dog hit dice num (7+7)
inline int mm2fgFooDogHdNum()
    { return 7; }

// The foo lion hit dice num (11+11)
inline int mm2fgFooLionHdNum()
    { return 11; }

// ---- the forester's bane pins (the R805 MM2 letters FG walk) ----

// The forester's bane (snapper-saw) full kill xp (165 + 5/hp x 17 avg; level
// IV)
inline int mm2fgForestersBaneXpValue()
    { return 250; }

// The forester's bane (snapper-saw) printed xp level (IV)
inline int mm2fgForestersBaneXpLevel()
    { return 4; }

// The leaf radiance low end (5-7 feet from the central plant)
inline int mm2fgForestersBaneLeafFeetMin()
    { return 5; }

// The leaf radiance high end
inline int mm2fgForestersBaneLeafFeetMax()
    { return 7; }

// The hidden stalk count low end (3-6)
inline int mm2fgForestersBaneStalksMin()
    { return 3; }

// The hidden stalk count high end
inline int mm2fgForestersBaneStalksMax()
    { return 6; }

// The escape chance per point of strength (5% per 1 point)
inline int mm2fgForestersBaneEscapePctPerStr()
    { return 5; }

// The leaf damage tolerance low end (9-16)
inline int mm2fgForestersBaneLeafHpMin()
    { return 9; }

// The leaf damage tolerance high end
inline int mm2fgForestersBaneLeafHpMax()
    { return 16; }

// The stalk damage tolerance low end (17-24)
inline int mm2fgForestersBaneStalkHpMin()
    { return 17; }

// The stalk damage tolerance high end
inline int mm2fgForestersBaneStalkHpMax()
    { return 24; }

// The regrowth low end (2-8 weeks)
inline int mm2fgForestersBaneRegrowWeeksMin()
    { return 2; }

// The regrowth high end
inline int mm2fgForestersBaneRegrowWeeksMax()
    { return 8; }

// ---- the formian pins (the R805 MM2 letters FG walk) ----

// The formian myrmarch full kill xp (400 + 8/hp x 27 avg; level V)
inline int mm2fgFormianMyrmarchXpValue()
    { return 616; }

// The formian myrmarch printed xp level (V)
inline int mm2fgFormianMyrmarchXpLevel()
    { return 5; }

// The formian warrior full kill xp (150 + 4/hp x 13 avg; level III)
inline int mm2fgFormianWarriorXpValue()
    { return 202; }

// The formian warrior printed xp level (III)
inline int mm2fgFormianWarriorXpLevel()
    { return 3; }

// The formian worker full kill xp (20 + 2/hp x 4 avg; level II)
inline int mm2fgFormianWorkerXpValue()
    { return 28; }

// The formian worker printed xp level (II)
inline int mm2fgFormianWorkerXpLevel()
    { return 2; }

// The underground city is always about 3 times larger than the upper part
inline int mm2fgFormianUndergroundMultiple()
    { return 3; }

// The encounter chance with workers
inline int mm2fgFormianWorkerEncounterPct()
    { return 90; }

// The encounter chance with warriors
inline int mm2fgFormianWarriorEncounterPct()
    { return 10; }

// The chance a worker group is accompanied by warriors (a raiding party)
inline int mm2fgFormianWorkerGuardedPct()
    { return 10; }

// The worker raiding band low end (10-40)
inline int mm2fgFormianRaidWorkersMin()
    { return 10; }

// The worker raiding band high end
inline int mm2fgFormianRaidWorkersMax()
    { return 40; }

// The warrior guards serving each myrmarch
inline int mm2fgFormianMyrmarchGuards()
    { return 2; }

// The workers serving each myrmarch
inline int mm2fgFormianMyrmarchWorkers()
    { return 8; }

// The gymarch hit dice num (equal to myrmarches but 7+7 hit dice)
inline int mm2fgFormianGymarchHdNum()
    { return 7; }

// The gymarch hit dice bonus
inline int mm2fgFormianGymarchHdBonus()
    { return 7; }

// The worker strength points (the warriors 23, the myrmarches 24)
inline int mm2fgFormianWorkerStrength()
    { return 22; }

// The warrior strength points
inline int mm2fgFormianWarriorStrength()
    { return 23; }

// The myrmarch strength points
inline int mm2fgFormianMyrmarchStrength()
    { return 24; }

// The myrmarch and special formian chance to speak Common
inline int mm2fgFormianMyrmarchCommonPct()
    { return 75; }

// ---- the froghemoth pins (the R805 MM2 letters FG walk) ----

// The froghemoth full kill xp (8100 + 20/hp x 56 avg; level IX)
inline int mm2fgFroghemothXpValue()
    { return 9220; }

// The froghemoth printed xp level (IX)
inline int mm2fgFroghemothXpLevel()
    { return 9; }

// The egg count low end (females lay 10-100 eggs)
inline int mm2fgFroghemothEggsMin()
    { return 10; }

// The egg count high end
inline int mm2fgFroghemothEggsMax()
    { return 100; }

// The share of tadhemoths eaten at hatching (about 90%)
inline int mm2fgFroghemothTadpoleEatenPct()
    { return 90; }

// The survival rate high end (about 1-4%)
inline int mm2fgFroghemothSurvivalPctMax()
    { return 4; }

// The tentacle sever low end (19-22 hit points)
inline int mm2fgFroghemothTentacleSeverMin()
    { return 19; }

// The tentacle sever high end
inline int mm2fgFroghemothTentacleSeverMax()
    { return 22; }

// The tongue sever low end (12-16 hit points, the most vulnerable appendage)
inline int mm2fgFroghemothTongueSeverMin()
    { return 12; }

// The tongue sever high end
inline int mm2fgFroghemothTongueSeverMax()
    { return 16; }

// The barbed tongue length (18/50 strength)
inline int mm2fgFroghemothTongueFeet()
    { return 10; }

// The digestive-juice damage low end (4-16 per round)
inline int mm2fgFroghemothSwallowDmgMin()
    { return 4; }

// The digestive-juice damage high end
inline int mm2fgFroghemothSwallowDmgMax()
    { return 16; }

// The swallowed victim falls unconscious after 2 rounds inside
inline int mm2fgFroghemothUnconsciousRounds()
    { return 2; }

// The digested-and-gone hit point floor (no resurrection then possible)
inline int mm2fgFroghemothDigestedHp()
    { return -10; }

// The severed-tongue tentacle fury low end (double damage 10-16 for 2-5
// rounds)
inline int mm2fgFroghemothSeveredRoundsMin()
    { return 2; }

// The severed-tongue tentacle fury high end
inline int mm2fgFroghemothSeveredRoundsMax()
    { return 5; }

// The tadhemoth swim rate
inline int mm2fgFroghemothTadpoleSwimInches()
    { return 16; }

// ---- the galeb duhr pins (the R805 MM2 letters FG walk) ----

// The galeb duhr full kill xp (2000 + 12/hp x 28 avg; level VII)
inline int mm2fgGalebDuhXpValue()
    { return 2336; }

// The galeb duhr printed xp level (VII)
inline int mm2fgGalebDuhXpLevel()
    { return 7; }

// The galeb duhr casts its spells as a 20th-level magic-user
inline int mm2fgGalebDuhrSpellLevel()
    { return 20; }

// The galeb duhr spell list count (move earth, stone shape, passwall,
// transmute rock to mud, wall of stone)
inline int mm2fgGalebDuhrSpellCount()
    { return 5; }

// The animated boulder count low end (1-2 within 6 inches)
inline int mm2fgGalebDuhrBouldersMin()
    { return 1; }

// The animated boulder count high end
inline int mm2fgGalebDuhrBouldersMax()
    { return 2; }

// The animated-boulder range
inline int mm2fgGalebDuhrBoulderRangeInches()
    { return 6; }

// The animated boulder armor class
inline int mm2fgGalebDuhrBoulderAc()
    { return 0; }

// The animated boulder hit dice (DM 4d6)
inline int mm2fgGalebDuhrBoulderHd()
    { return 9; }

// The galeb duhr save modifier vs. cold-based attacks (double damage taken)
inline int mm2fgGalebDuhrColdSaveMod()
    { return -4; }

// The galeb duhr save modifier vs. fire attacks (full damage from magical
// fire)
inline int mm2fgGalebDuhrFireSaveMod()
    { return 4; }

// The galeb duhr hit dice low end (8-10, the ranged cell reads the low end -
// the kuei precedent)
inline int mm2fgGalebDuhrHdMin()
    { return 8; }

// The galeb duhr hit dice high end
inline int mm2fgGalebDuhrHdMax()
    { return 10; }

// ---- the fomorian pins (the R805 MM2 letters FG walk) ----

// The fomorian giant full kill xp (2750 + 18/hp x 46 avg; level VII)
inline int mm2fgFomorianXpValue()
    { return 3578; }

// The fomorian giant printed xp level (VII)
inline int mm2fgFomorianXpLevel()
    { return 7; }

// The fomorian surprise bonus low end (+1 to +3 by terrain)
inline int mm2fgFomorianSurpriseBonusMin()
    { return 1; }

// The fomorian surprise bonus high end
inline int mm2fgFomorianSurpriseBonusMax()
    { return 3; }

// The lair chance of 1-2 females for every male
inline int mm2fgFomorianFemalePct()
    { return 25; }

// The females per male low end
inline int mm2fgFomorianFemalesPerMaleMin()
    { return 1; }

// The females per male high end
inline int mm2fgFomorianFemalesPerMaleMax()
    { return 2; }

// The young per female low end (1-3)
inline int mm2fgFomorianYoungPerFemaleMin()
    { return 1; }

// The young per female high end
inline int mm2fgFomorianYoungPerFemaleMax()
    { return 3; }

// ---- the firbolg pins (the R805 MM2 letters FG walk) ----

// The firbolg full kill xp (3650 + 18/hp x 47 avg; level VIII)
inline int mm2fgFirbolgXpValue()
    { return 4496; }

// The firbolg printed xp level (VIII)
inline int mm2fgFirbolgXpLevel()
    { return 8; }

// The encounter chance with small groups or a lone wanderer
inline int mm2fgFirbolgSmallGroupPct()
    { return 90; }

// The bat-away attempts per round (missiles batted or caught)
inline int mm2fgFirbolgBatAttemptsPerRound()
    { return 2; }

// The bat-away success roll (a 6 or better on 1d20 - the capture "8 or
// better" the OCR misread, the 75% arithmetic the settle)
inline int mm2fgFirbolgBatRollMin()
    { return 6; }

// The bat-away success chance (6 or better on 1d20)
inline int mm2fgFirbolgBatPct()
    { return 75; }

// The firbolg innate power count (detect magic, diminution, fools gold,
// forget, alter self)
inline int mm2fgFirbolgPowerCount()
    { return 5; }

// The chance per firbolg that 1 in the group is a shaman
inline int mm2fgFirbolgShamanPct()
    { return 5; }

// The firbolg shaman level ceiling (2nd-level illusionist spells at 6th and
// 7th)
inline int mm2fgFirbolgShamanLevel()
    { return 7; }

// The 7th-level shaman 1st-level illusionist spells
inline int mm2fgFirbolgSeventhLevelFirstSpells()
    { return 10; }

// The 7th-level shaman 2nd-level illusionist spells
inline int mm2fgFirbolgSeventhLevelSecondSpells()
    { return 4; }

// ---- the verbeeg pins (the R805 MM2 letters FG walk) ----

// The verbeeg full kill xp (275 + 6/hp x 22 avg; level V)
inline int mm2fgVerbeegXpValue()
    { return 407; }

// The verbeeg printed xp level (V)
inline int mm2fgVerbeegXpLevel()
    { return 5; }

// The encounter chance in conjunction with hill giants or ogres
inline int mm2fgVerbeegWithGiantsPct()
    { return 30; }

// The hill-giant share of the conjunction
inline int mm2fgVerbeegHillGiantSharePct()
    { return 40; }

// The ogre share of the conjunction
inline int mm2fgVerbeegOgreSharePct()
    { return 60; }

// The encounter chance with 1-6 wandering creatures
inline int mm2fgVerbeegWanderingPct()
    { return 50; }

// The encounter chance in the lair (5-30 verbeeg)
inline int mm2fgVerbeegLairEncPct()
    { return 30; }

// The lair band low end
inline int mm2fgVerbeegLairMin()
    { return 5; }

// The lair band high end
inline int mm2fgVerbeegLairMax()
    { return 30; }

// The encounter chance with 1-2+ others
inline int mm2fgVerbeegOthersPct()
    { return 20; }

// The spears each verbeeg carries at least
inline int mm2fgVerbeegSpearCount()
    { return 3; }

// The strength throwing-range bonus low end (3 to 6 inches)
inline int mm2fgVerbeegSpearRangeBonusMin()
    { return 3; }

// The strength throwing-range bonus high end
inline int mm2fgVerbeegSpearRangeBonusMax()
    { return 6; }

// The 18/00 verbeeg spear distance
inline int mm2fgVerbeegOoThrowRangeInches()
    { return 9; }

// The 18/00 verbeeg spear damage low end (7-12)
inline int mm2fgVerbeegOoThrowDmgMin()
    { return 7; }

// The 18/00 verbeeg spear damage high end
inline int mm2fgVerbeegOoThrowDmgMax()
    { return 12; }

// The lair leader hit point floor (18/00 strength)
inline int mm2fgVerbeegLeaderHpMin()
    { return 40; }

// The shaman chance per verbeeg (of either sex)
inline int mm2fgVerbeegShamanPctPerGiant()
    { return 2; }

// The verbeeg shaman level ceiling
inline int mm2fgVerbeegShamanLevel()
    { return 7; }

// The tribal chance to lack any magic item they cannot understand or use
inline int mm2fgVerbeegNoMagicPct()
    { return 90; }

// The lair wolf guards low end (2-8 at 75%)
inline int mm2fgVerbeegWolvesMin()
    { return 2; }

// The lair wolf guards high end
inline int mm2fgVerbeegWolvesMax()
    { return 8; }

// The wolf guard chance (worgs 1-4 at 25%)
inline int mm2fgVerbeegWolvesPct()
    { return 75; }

// The young share of the total population over 9
inline int mm2fgVerbeegYoungPct()
    { return 50; }

// ---- the gibbering mouther pins (the R805 MM2 letters FG walk) ----

// The gibbering mouther full kill xp (210 + 5/hp x 17 avg; level IV)
inline int mm2fgGibberingMoutherXpValue()
    { return 295; }

// The gibbering mouther printed xp level (IV)
inline int mm2fgGibberingMoutherXpLevel()
    { return 4; }

// The mouths per round the mouther bites with
inline int mm2fgMoutherMouthsPerRound()
    { return 6; }

// The extra damage per round per fastened mouth
inline int mm2fgMoutherDrainPerRound()
    { return 1; }

// The attached-mouth count that forces the slipping check (3 or more)
inline int mm2fgMoutherSlipMouthsMin()
    { return 3; }

// The slipped roll (4 or less on 2d6, +1 if dexterity 15+)
inline int mm2fgMoutherSlipRollMax()
    { return 4; }

// The extra mouths the fallen victim is bitten with
inline int mm2fgMoutherFallenMouths()
    { return 12; }

// The confusion gibbering radius (save vs. spells)
inline int mm2fgMoutherGibberRadiusInches()
    { return 6; }

// The warmed ground-and-stone radius the mouther controls
inline int mm2fgMoutherGroundRadiusFeet()
    { return 5; }

// The segments to alter earth (5 segments; stone shifts in 1 full round)
inline int mm2fgMoutherEarthSegments()
    { return 5; }

// The rounds to shift stone to its next nearest form
inline int mm2fgMoutherStoneRounds()
    { return 1; }

// ---- the gloomwing pins (the R805 MM2 letters FG walk) ----

// The gloomwing full kill xp (525 + 6/hp x 18 avg; level VI)
inline int mm2fgGloomwingXpValue()
    { return 633; }

// The gloomwing printed xp level (VI)
inline int mm2fgGloomwingXpLevel()
    { return 6; }

// The gloomwing surprise roll low end (1-3 on 1d6)
inline int mm2fgGloomwingSurpriseMin()
    { return 1; }

// The gloomwing surprise roll high end
inline int mm2fgGloomwingSurpriseMax()
    { return 3; }

// The melee round the pheromone emission begins (the 2nd and each successive)
inline int mm2fgGloomwingPheromoneRound()
    { return 2; }

// The strength loss per round of pheromone exposure (save vs. poison)
inline int mm2fgGloomwingStrLossPerRound()
    { return 1; }

// The strength restore low end (1-4 turns after exposure ceases)
inline int mm2fgGloomwingRestoreTurnsMin()
    { return 1; }

// The strength restore high end
inline int mm2fgGloomwingRestoreTurnsMax()
    { return 4; }

// The scent chance to attract 1-4 more gloomwings (per round)
inline int mm2fgGloomwingAttractPct()
    { return 20; }

// The attracted gloomwings low end
inline int mm2fgGloomwingAttractMin()
    { return 1; }

// The attracted gloomwings high end
inline int mm2fgGloomwingAttractMax()
    { return 4; }

// The egg hatch in 12 days (sprouting tenebrous worms)
inline int mm2fgGloomwingHatchDays()
    { return 12; }

// The sprouted worm low end (4-10)
inline int mm2fgGloomwingWormsMin()
    { return 4; }

// The sprouted worm high end
inline int mm2fgGloomwingWormsMax()
    { return 10; }

// The ivory mandibles value per gloomwing (gp)
inline int mm2fgGloomwingMandibleValueGp()
    { return 25; }

// ---- the goat pins (the R805 MM2 letters FG walk) ----

// The goat full kill xp (24 + 2/hp x 5 avg; level II)
inline int mm2fgGoatXpValue()
    { return 34; }

// The goat printed xp level (II)
inline int mm2fgGoatXpLevel()
    { return 2; }

// The buck charge to-hit bonus
inline int mm2fgGoatChargeToHitBonus()
    { return 2; }

// The charge damage low end (an additional 1-2 points)
inline int mm2fgGoatChargeDmgMin()
    { return 1; }

// The charge damage high end
inline int mm2fgGoatChargeDmgMax()
    { return 2; }

// The herd bucks low end (1-2)
inline int mm2fgGoatBucksMin()
    { return 1; }

// The herd bucks high end
inline int mm2fgGoatBucksMax()
    { return 2; }

// The herd doe ceiling (up to 12)
inline int mm2fgGoatDoesMax()
    { return 12; }

// ---- the gorgimera pins (the R805 MM2 letters FG walk) ----

// The gorgimera full kill xp (2557 + 14/hp x 35 avg; level VII)
inline int mm2fgGorgimeraXpValue()
    { return 3047; }

// The gorgimera printed xp level (VII)
inline int mm2fgGorgimeraXpLevel()
    { return 7; }

// The gorgimera lion-parts armor class (the "5/2" composite cell reads the
// lion 5)
inline int mm2fgGorgimeraLionAc()
    { return 5; }

// The petrifying breath uses per day (3 inches long, 1 inch wide base cone)
inline int mm2fgGorgimeraPetrifyPerDay()
    { return 2; }

// The fiery breath uses per day (5 inches long, 2 inches wide base cone)
inline int mm2fgGorgimeraFirePerDay()
    { return 2; }

// The petrifying breath cone length
inline int mm2fgGorgimeraPetrifyLengthInches()
    { return 3; }

// The petrifying breath cone base width
inline int mm2fgGorgimeraPetrifyWidthInches()
    { return 1; }

// The fiery breath cone length
inline int mm2fgGorgimeraFireLengthInches()
    { return 5; }

// The fiery breath cone base width
inline int mm2fgGorgimeraFireWidthInches()
    { return 2; }

// The dragon breath damage low end (3-24, 3d8)
inline int mm2fgGorgimeraBreathDmgMin()
    { return 3; }

// The dragon breath damage high end (save vs. breath weapon)
inline int mm2fgGorgimeraBreathDmgMax()
    { return 24; }

// The distance at which the gorgimera always uses a breath weapon
inline int mm2fgGorgimeraRangeFeet()
    { return 10; }

// ---- the greenhag pins (the R805 MM2 letters FG walk) ----

// The greenhag full kill xp (1600 + 12/hp x 31 avg; level VII)
inline int mm2fgGreenhagXpValue()
    { return 1972; }

// The greenhag printed xp level (VII)
inline int mm2fgGreenhagXpLevel()
    { return 7; }

// The greenhag strength 18/00 damage bonus per claw
inline int mm2fgGreenhagStrBonus()
    { return 6; }

// The greenhag spell-like power count (audible glamor through weakness)
inline int mm2fgGreenhagPowerCount()
    { return 8; }

// The greenhag power ability level
inline int mm2fgGreenhagPowerLevel()
    { return 9; }

// The greenhag silent-hide chance in foliage
inline int mm2fgGreenhagSilentHidePct()
    { return 90; }

// The greenhag surprise low end (5 in 6)
inline int mm2fgGreenhagSurpriseMin()
    { return 5; }

// The greenhag surprise high end
inline int mm2fgGreenhagSurpriseMax()
    { return 6; }

// The invisible-attack surprise low end (19 in 20)
inline int mm2fgGreenhagInvisibleSurpriseMin()
    { return 19; }

// The invisible-attack surprise high end
inline int mm2fgGreenhagInvisibleSurpriseMax()
    { return 20; }

// The greenhag surprised roll (1 in 20)
inline int mm2fgGreenhagSurprisedMax()
    { return 1; }

// The greenhag surprised die
inline int mm2fgGreenhagSurprisedDie()
    { return 20; }

// ---- the grippli pins (the R805 MM2 letters FG walk) ----

// The grippli full kill xp (45 + 2/hp x 4 avg; level II)
inline int mm2fgGrippliXpValue()
    { return 53; }

// The grippli printed xp level (II)
inline int mm2fgGrippliXpLevel()
    { return 2; }

// The grippli life span (700-year, few offspring)
inline int mm2fgGrippliLifespanYears()
    { return 700; }

// The grippli ultravision range
inline int mm2fgGrippliUltravisionInches()
    { return 10; }

// The grippli psionic chance low end (1%-2%)
inline int mm2fgGrippliPsionicMinPct()
    { return 1; }

// The grippli psionic chance high end
inline int mm2fgGrippliPsionicMaxPct()
    { return 2; }

// The lair males low end (5-30)
inline int mm2fgGrippliLairMalesMin()
    { return 5; }

// The lair males high end
inline int mm2fgGrippliLairMalesMax()
    { return 30; }

// The lair offspring low end (1-6, noncombative)
inline int mm2fgGrippliOffspringMin()
    { return 1; }

// The lair offspring high end
inline int mm2fgGrippliOffspringMax()
    { return 6; }

// The tribe mother armor class (HD 3, a stinking musk cloud once per day)
inline int mm2fgGrippliMotherAc()
    { return 7; }

// The tribe mother hit dice
inline int mm2fgGrippliMotherHd()
    { return 3; }

// The tribe mother mates armor class (HD 2, 1d4+1 poison)
inline int mm2fgGrippliMatesAc()
    { return 8; }

// The tribe mother mates hit dice
inline int mm2fgGrippliMatesHd()
    { return 2; }

// ---- the grig pins (the R805 MM2 letters FG walk) ----

// The grig full kill xp (50 + 1/hp x 3 avg; level II)
inline int mm2fgGrigXpValue()
    { return 53; }

// The grig printed xp level (II)
inline int mm2fgGrigXpLevel()
    { return 2; }

// The grig +2 to hit when hurling missiles
inline int mm2fgGrigMissileToHitBonus()
    { return 2; }

// The darts each grig carries at least
inline int mm2fgGrigDartCount()
    { return 6; }

// The grig spell-like power count (change self through ventriloquism)
inline int mm2fgGrigPowerCount()
    { return 6; }

// The grig magical power ability level
inline int mm2fgGrigPowerLevel()
    { return 6; }

// The grig fiddler chance to play the Otto's Irresistible Dance tune
inline int mm2fgGrigFiddlerPct()
    { return 25; }

// The fiddle saving-throw radius (feet)
inline int mm2fgGrigFiddleRadiusFeet()
    { return 30; }

// The grig surprise chance
inline int mm2fgGrigSurprisePct()
    { return 90; }

// The grig surprised chance
inline int mm2fgGrigSurprisedPct()
    { return 10; }

// The grig infravision (feet)
inline int mm2fgGrigInfravisionFeet()
    { return 180; }

// The glen probability for other grigs or atomies to be present
inline int mm2fgGrigGlenPct()
    { return 30; }

// ---- the grim pins (the R805 MM2 letters FG walk) ----

// The grim full kill xp (285 + 5/hp x 16 avg; level V)
inline int mm2fgGrimXpValue()
    { return 365; }

// The grim printed xp level (V)
inline int mm2fgGrimXpLevel()
    { return 5; }

// The grim forms (black cat, black dog and black owl)
inline int mm2fgGrimFormCount()
    { return 3; }

// The grim turn undead as 8th-level clerics
inline int mm2fgGrimTurnUndeadLevel()
    { return 8; }

// The grim turn die bonus vs. Evil from the Lower Outer Planes
inline int mm2fgGrimTurnDieBonus()
    { return 2; }

// The weapon enchantment floor to hit a grim
inline int mm2fgGrimWeaponPlusMin()
    { return 1; }

// The protection from evil radius (feet)
inline int mm2fgGrimProtectionRadiusFeet()
    { return 10; }

// The detect evil range (inches)
inline int mm2fgGrimDetectEvilInches()
    { return 7; }

// The grim surprise roll low end (1 in 10)
inline int mm2fgGrimSurpriseMin()
    { return 1; }

// The grim surprise die
inline int mm2fgGrimSurpriseDie()
    { return 10; }

// ---- the grue pins (the R805 MM2 letters FG walk) ----

// The chaggrin full kill xp (425 + 6/hp x 22 avg; level V)
inline int mm2fgChaggrinXpValue()
    { return 557; }

// The chaggrin printed xp level (V)
inline int mm2fgChaggrinXpLevel()
    { return 5; }

// The harginn full kill xp (245 + 5/hp x 18 avg; level IV)
inline int mm2fgHarginnXpValue()
    { return 335; }

// The harginn printed xp level (IV)
inline int mm2fgHarginnXpLevel()
    { return 4; }

// The ildriss full kill xp (245 + 5/hp x 14 avg; level IV)
inline int mm2fgIldrissXpValue()
    { return 315; }

// The ildriss printed xp level (IV)
inline int mm2fgIldrissXpLevel()
    { return 4; }

// The varrdig full kill xp (650 + 8/hp x 27 avg; level VI)
inline int mm2fgVarrdigXpValue()
    { return 866; }

// The varrdig printed xp level (VI)
inline int mm2fgVarrdigXpLevel()
    { return 6; }

// The chaggrin weight low end (over 140 pounds)
inline int mm2fgChaggrinWeightMin()
    { return 140; }

// The chaggrin weight high end
inline int mm2fgChaggrinWeightMax()
    { return 210; }

// The clinging damage low end (7-12 per round)
inline int mm2fgChaggrinClingDmgMin()
    { return 7; }

// The clinging damage high end
inline int mm2fgChaggrinClingDmgMax()
    { return 12; }

// The hedgehog quill damage low end (1-4 per round)
inline int mm2fgChaggrinQuillDmgMin()
    { return 1; }

// The hedgehog quill damage high end
inline int mm2fgChaggrinQuillDmgMax()
    { return 4; }

// The chaggrin earth-magic dispel radius (feet)
inline int mm2fgChaggrinDispelFeet()
    { return 40; }

// The merged-soil surprise low end (1-5)
inline int mm2fgChaggrinSurpriseMin()
    { return 1; }

// The merged-soil surprise high end
inline int mm2fgChaggrinSurpriseMax()
    { return 5; }

// The fire column height (about 8 feet)
inline int mm2fgHarginnColumnFeet()
    { return 8; }

// The flame gout width (feet)
inline int mm2fgHarginnGoutWidthFeet()
    { return 3; }

// The flame gout length (feet)
inline int mm2fgHarginnGoutLengthFeet()
    { return 6; }

// The harginn fire-magic dispel radius (feet)
inline int mm2fgHarginnDispelFeet()
    { return 20; }

// The fog-form faintly gleaming red eyes
inline int mm2fgIldrissEyeCount()
    { return 3; }

// The ildriss surprise low end (4 in 6)
inline int mm2fgIldrissSurpriseMin()
    { return 4; }

// The ildriss surprise high end
inline int mm2fgIldrissSurpriseMax()
    { return 6; }

// The weapon enchantment floor to hit an ildriss (+2 or better)
inline int mm2fgIldrissWeaponPlusMin()
    { return 2; }

// The ildriss air-magic dispel radius (feet)
inline int mm2fgIldrissDispelFeet()
    { return 50; }

// The water jet force range (feet, 1 in 6 blinding 1-4 rounds)
inline int mm2fgVarrdigJetRangeFeet()
    { return 6; }

// The blinding chance high end (1 in 6)
inline int mm2fgVarrdigBlindChanceMax()
    { return 6; }

// The blinding low end (1-4 rounds)
inline int mm2fgVarrdigBlindRoundsMin()
    { return 1; }

// The blinding high end
inline int mm2fgVarrdigBlindRoundsMax()
    { return 4; }

// The varrdig water-magic dispel radius (feet)
inline int mm2fgVarrdigDispelFeet()
    { return 30; }

// The snowman-form tube low end (3-6)
inline int mm2fgVarrdigSnowmanTubesMin()
    { return 3; }

// The snowman-form tube high end
inline int mm2fgVarrdigSnowmanTubesMax()
    { return 6; }

// The snowman-form tube range (feet)
inline int mm2fgVarrdigTubeRangeFeet()
    { return 10; }

// The snowman-form tube damage low end (1-6 hit points)
inline int mm2fgVarrdigTubeDmgMin()
    { return 1; }

// The snowman-form tube damage high end
inline int mm2fgVarrdigTubeDmgMax()
    { return 6; }

// ---- the MM2 letters FG walk stat grid (the R805 wiring) ----

// The armor class cells (the gorgimera "5/2" composite cell reads the lion 5;
// the forester bane and froghemoth composite cells read their first value;
// the verbeeg "4 or better" reads 4)
inline int mm2fgFgStatAC(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 5;
        case 5:
            return 0;
        case 6:
            return -1;
        case 7:
            return 4;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return -2;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 4;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 7;
        case 19:
            return 5;
        case 20:
            return -2;
        case 21:
            return 9;
        case 22:
            return 2;
        case 23:
            return 0;
        case 24:
            return 4;
        case 25:
            return 3;
        case 26:
            return 2;
        case 27:
            return 5;
        default:
            return 0;
        }
    }

// The hit dice num cells (the galeb duhr 8-10 ranged cell reads the low end -
// the kuei precedent; the grig "1/2+1" reads the half-die 0)
inline int mm2fgFgStatHd(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 11;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 3;
        case 10:
            return 1;
        case 11:
            return 16;
        case 12:
            return 8;
        case 13:
            return 13;
        case 14:
            return 13;
        case 15:
            return 5;
        case 16:
            return 4;
        case 17:
            return 5;
        case 18:
            return 1;
        case 19:
            return 10;
        case 20:
            return 9;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 4;
        case 24:
            return 5;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 6;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the fomorian 13 + 1-3 and the grim 4+2-8 ranged
// cells read the low-end bonus; the falcon small carries the minus 1)
inline int mm2fgFgStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 0;
        case 2:
            return 4;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 7;
        case 6:
            return 11;
        case 7:
            return 0;
        case 8:
            return 6;
        case 9:
            return 3;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 5;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 2;
        case 24:
            return 5;
        case 25:
            return 4;
        case 26:
            return 0;
        case 27:
            return 6;
        default:
            return 0;
        }
    }

// The book-average hit points (the floor(num x 3.5) + bonus formula; the grig
// reads the 2-5 print hp range midpoint - the atomie precedent)
inline int mm2fgFgStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 10;
        case 4:
            return 21;
        case 5:
            return 31;
        case 6:
            return 49;
        case 7:
            return 17;
        case 8:
            return 27;
        case 9:
            return 13;
        case 10:
            return 4;
        case 11:
            return 56;
        case 12:
            return 28;
        case 13:
            return 46;
        case 14:
            return 47;
        case 15:
            return 22;
        case 16:
            return 17;
        case 17:
            return 18;
        case 18:
            return 5;
        case 19:
            return 35;
        case 20:
            return 31;
        case 21:
            return 4;
        case 22:
            return 3;
        case 23:
            return 16;
        case 24:
            return 22;
        case 25:
            return 18;
        case 26:
            return 14;
        case 27:
            return 27;
        default:
            return 0;
        }
    }

// The attack cells (the composite prints read their loaded value, the R798
// duergar max-read convention: the froghemoth "1 or 4" reads 4, the mouther
// "6+" reads 6, the forester bane "3-6" reads 6, the grippli "1 weapon" reads
// 1; the grim "See below" reads the 1 loader floor)
inline int mm2fgFgStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 4;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 2;
        case 16:
            return 6;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 5;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 2;
        default:
            return 0;
        }
    }

// The base xp cells (every letter-F and letter-G print carries the xp level
// prefix)
inline int mm2fgFgStatXp(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 25;
        case 2:
            return 36;
        case 3:
            return 35;
        case 4:
            return 150;
        case 5:
            return 1200;
        case 6:
            return 2850;
        case 7:
            return 165;
        case 8:
            return 400;
        case 9:
            return 150;
        case 10:
            return 20;
        case 11:
            return 8100;
        case 12:
            return 2000;
        case 13:
            return 2750;
        case 14:
            return 3650;
        case 15:
            return 275;
        case 16:
            return 210;
        case 17:
            return 525;
        case 18:
            return 24;
        case 19:
            return 2557;
        case 20:
            return 1600;
        case 21:
            return 45;
        case 22:
            return 50;
        case 23:
            return 285;
        case 24:
            return 425;
        case 25:
            return 245;
        case 26:
            return 245;
        case 27:
            return 650;
        default:
            return 0;
        }
    }

// The xp per hit point cells
inline int mm2fgFgStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 12;
        case 6:
            return 16;
        case 7:
            return 5;
        case 8:
            return 8;
        case 9:
            return 4;
        case 10:
            return 2;
        case 11:
            return 20;
        case 12:
            return 12;
        case 13:
            return 18;
        case 14:
            return 18;
        case 15:
            return 6;
        case 16:
            return 5;
        case 17:
            return 6;
        case 18:
            return 2;
        case 19:
            return 14;
        case 20:
            return 12;
        case 21:
            return 2;
        case 22:
            return 1;
        case 23:
            return 5;
        case 24:
            return 6;
        case 25:
            return 5;
        case 26:
            return 5;
        case 27:
            return 8;
        default:
            return 0;
        }
    }

// The lair percentage cells (Nil reads 0)
inline int mm2fgFgStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 30;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 100;
        case 9:
            return 50;
        case 10:
            return 20;
        case 11:
            return 40;
        case 12:
            return 15;
        case 13:
            return 45;
        case 14:
            return 45;
        case 15:
            return 30;
        case 16:
            return 95;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 25;
        case 20:
            return 40;
        case 21:
            return 30;
        case 22:
            return 10;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        default:
            return 0;
        }
    }

// The ground move-rate cells (the ildriss reads the 3" rolling-fog rate; the
// gloomwing "/12" reads the 12 flight rate; Nil reads 0)
inline int mm2fgFgStatMove(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 9;
        case 4:
            return 6;
        case 5:
            return 27;
        case 6:
            return 21;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 15;
        case 10:
            return 18;
        case 11:
            return 2;
        case 12:
            return 6;
        case 13:
            return 9;
        case 14:
            return 15;
        case 15:
            return 18;
        case 16:
            return 3;
        case 17:
            return 12;
        case 18:
            return 15;
        case 19:
            return 12;
        case 20:
            return 12;
        case 21:
            return 9;
        case 22:
            return 6;
        case 23:
            return 18;
        case 24:
            return 12;
        case 25:
            return 15;
        case 26:
            return 3;
        case 27:
            return 6;
        default:
            return 0;
        }
    }

// The magic resistance cells (Standard and See below read 0)
inline int mm2fgFgStatMr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 45;
        case 6:
            return 55;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 20;
        case 13:
            return 0;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 35;
        case 21:
            return 0;
        case 22:
            return 30;
        case 23:
            return 25;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
