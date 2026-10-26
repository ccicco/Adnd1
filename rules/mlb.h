// =========================================================================================
// Adnd1 - rules/mlb.h
// the Melnibonean mythos - the D&DG walk round fourteen, print pp. 86-95:
// thirty-three beings from Elric the albino emperor of Melnibone through
// Yyrkoon the evil cousin, the three greater gods (Arioch, Donblas,
// Xiombarg), the six lesser gods (Darnizhaan, Grome, Kakatal, Misha, Pyaray,
// Straasha), the six demigod master types of the demi-planes (Fileet,
// Haaashastaak, Meerclar, Nnuurrr, Nuru-ah, Roofdrak), the four heroes
// (Elric, Moonglum, Theleb K'aarna, Yyrkoon) and fourteen monsters across
// thirteen plane codes.
// census 784 -> 785.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 087-096; the second printing) with
// the column-split tsv dumps; the collation voice: the archive.org 1st-print
// derivative (deities-demigods-1st-print) - the chocr char-level word
// geometry at 600dpi plus the djvu.xml word geometry. The adjudications: the
// Elric 6/minus 6 dual armor class and 6/15 dual move with the Standard-or-85
// magic resistance pinned 0, the See below 99 pairs (Grome, Nuru-ah, Kakatal,
// Misha, Straasha), the Arioch Variable size and charisma pins 0, the Nnuurrr
// and Pyaray minus 6 charisma cells, the Haaashastaak and Nnuurrr wisdom 3
// odd pins, the Fileet bare L and the Vampire Trees stray plus size prints,
// the fourteen monster XP roman decodes, the three fraction cells (Moonglum
// 66, Theleb 66, Yyrkoon 78) and the Elenoin-Grahuk enmity pair.
//
namespace rules {

// ---- the R862 census ----

// the Melnibonean mythos round: the D&DG walk round fourteen, print pp. 86-95
inline int mlbRound()
    { return 862; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int mlbPrintStart()
    { return 86; }

// the last print page of the mythos
inline int mlbPrintEnd()
    { return 95; }

// the thirty-three beings of the mythos (Elric through Yyrkoon: three
// greater, six lesser, six demigods, four heroes, fourteen monsters)
inline int mlbBeingCount()
    { return 33; }

// the four grids of the round (combat, class, ability, roster)
inline int mlbTableCount()
    { return 4; }

// no chains this round
inline int mlbChainCount()
    { return 0; }

// the ddg registry floor (the wrap78 record seating)
inline int mlbRegistryFloor()
    { return 995; }

// the combat grid rows (Elric through Yyrkoon, the print order)
inline int mlbCbtRows()
    { return 33; }

// the class grid rows
inline int mlbClsRows()
    { return 33; }

// the ability grid rows
inline int mlbAbiRows()
    { return 33; }

// the roster grid rows
inline int mlbRosRows()
    { return 33; }

// the plane codes (none, Prime Material, Special, the four elemental planes
// of the four elemental lords, the six demi-plane species courts: birds,
// reptiles, cats, insects, cattle, dogs)
inline int mlbPlaneCount()
    { return 13; }

// the three greater gods (Arioch, Donblas, Xiombarg)
inline int mlbGreaterCount()
    { return 3; }

// the six lesser gods (Darnizhaan, Grome, Kakatal, Misha, Pyaray, Straasha)
inline int mlbLesserCount()
    { return 6; }

// the six demigods (Fileet, Haaashastaak, Meerclar, Nnuurrr, Nuru-ah,
// Roofdrak - the master types of the demi-planes)
inline int mlbDemigodCount()
    { return 6; }

// the four heroes (Elric, Moonglum, Theleb K'aarna, Yyrkoon)
inline int mlbHeroCount()
    { return 4; }

// the fourteen monster rows (the Assassinator, the Clakar, the Dharzi, the
// Elenoin, the Grahuk, the Kelmain, the Mist Giant, Mordagz, the Myyrrhn, the
// Nihrain, the Oonai, Quaolnargn, the Vampire Trees, the Vulture Lion) - the
// monster-heaviest round of the walk
inline int mlbMonsterCount()
    { return 14; }

// the four printed Nth level in each cells (Arioch MU/I 20, Darnizhaan MU/I
// 15, Donblas MU/I 30, Pyaray MU/I 10)
inline int mlbInEachCount()
    { return 4; }

// the Elenoin-Grahuk hereditary enemy pair (the grk printed-rivalry
// precedent)
inline int mlbEnmityCount()
    { return 2; }

// no paladins this round
inline int mlbPaladinCount()
    { return 0; }

// the psionic class kinds printed (I, II, VI)
inline int mlbPsiClassKinds()
    { return 3; }

// the three X 1/2 foot size cells (Moonglum 66, Theleb K'aarna 66, Yyrkoon
// 78)
inline int mlbHalfFootCount()
    { return 3; }

// the three artifacts of the mythos intro (the Arrows of Law, the Black
// Crystal Door, the Nanorion Stones)
inline int mlbArtifactCount()
    { return 3; }

// ---- the Melnibonean pantheon doctrine ----

// the gods of the mythos occupy many planes at the same time, in thousands of
// bodies
inline bool mlbGodsManyPlanes()
    { return true; }

// all the bodies are connected and aware of each other
inline bool mlbAvatarConnection()
    { return true; }

// a god materializing on a lower plane has only one class attribute
inline bool mlbOneClassAttribute()
    { return true; }

// the full powers only in the home plane
inline bool mlbFullPowersHomePlane()
    { return true; }

// the other chaos gods named: Haborym, Balan, Maluk, Stortor the Old, Baloan,
// Marthim, Aesma, Alastor, Soebas, Verdelet, Mizilfkm, Balo the Jester,
// Checkalakh of the Flame Body
inline bool mlbOtherChaosGodsNamed()
    { return true; }

// the Chaos symbol: eight red arrows issuing from a small circle
inline int mlbChaosArrows()
    { return 8; }

// the Law symbol: a single amber arrow pointing up
inline int mlbLawArrows()
    { return 1; }

// the lawful gods appear as slim, perfectly formed humans in silks with
// feather-like armor, wielding slender weapons of incredible power
inline bool mlbLawfulGodsSilkForm()
    { return true; }

// the master types: every animal species has a ruler on its own demi-plane (a
// half-world)
inline bool mlbMasterTypesDoctrine()
    { return true; }

// the dogs worship their own image, so their ruler looks like a dog
// (Roofdrak)
inline bool mlbDogsWorshipOwnImage()
    { return true; }

// the Arrows of Law: twenty to a quiver
inline int mlbArrowsOfLawPerQuiver()
    { return 20; }

// an arrow always hits and kills one chaotic creature (a saving throw vs
// death applies)
inline bool mlbArrowsOfLawSlayChaotic()
    { return true; }

// the normal longbow ranges apply to the Arrows of Law
inline bool mlbArrowsOfLawNormalRanges()
    { return true; }

// the Black Crystal Door: interdimensional metal that will not break
inline bool mlbCrystalDoorUnbreakable()
    { return true; }

// the Black Crystal Door is immune to magic
inline bool mlbCrystalDoorMagicImmune()
    { return true; }

// the Black Crystal Door opens only on the proper word
inline bool mlbCrystalDoorOpensOnWord()
    { return true; }

// a magic-user trying to open the Black Crystal Door has all spells drained
inline bool mlbCrystalDoorDrainsSpells()
    { return true; }

// devices used against the Black Crystal Door are permanently drained
inline bool mlbCrystalDoorDrainsDevices()
    { return true; }

// the Nanorion Stones: a 5% chance of finding one as the heart of a demon
inline int mlbNanorionHeartPct()
    { return 5; }

// the demon must have over 80 hit points
inline int mlbNanorionDemonHp()
    { return 80; }

// the stone functions 1-4 times
inline int mlbNanorionUsesMax()
    { return 4; }

// only clerics of 15th or higher level can use a Nanorion Stone
inline int mlbNanorionClericLevel()
    { return 15; }

// a Nanorion Stone awakens a sleeper or raises the dead
inline bool mlbNanorionRaisePower()
    { return true; }

// ---- Elric ----

// Stormbringer: a +5 rune sword
inline int mlbStormbringerPlus()
    { return 5; }

// Stormbringer: intelligence 18
inline int mlbStormbringerInt()
    { return 18; }

// Stormbringer: ego 20
inline int mlbStormbringerEgo()
    { return 20; }

// Stormbringer drains all the levels of a victim (50% of the time, half the
// levels otherwise)
inline bool mlbStormbringerDrainsLevels()
    { return true; }

// the souls are devoured: no raise possible
inline bool mlbStormbringerDevoursSouls()
    { return true; }

// per two levels drained
inline int mlbStormbringerLevelsPerGain()
    { return 2; }

// Elric gains 5 hit points
inline int mlbStormbringerHpPerGain()
    { return 5; }

// and one strength point
inline int mlbStormbringerStrPerGain()
    { return 1; }

// the Stormbringer strength ceiling
inline int mlbStormbringerMaxStr()
    { return 23; }

// the 200-level satiety
inline int mlbStormbringerSatietyLevels()
    { return 200; }

// the satiety lasts 8 hours
inline int mlbStormbringerSatietyHours()
    { return 8; }

// the last 10 turns of the satiety are gained
inline int mlbStormbringerLastGainTurns()
    { return 10; }

// the 60% chance of summoning Stormbringer
inline int mlbStormbringerSummonPct()
    { return 60; }

// 85% magic resistance while wielding Stormbringer
inline int mlbStormbringerMrPct()
    { return 85; }

// the 15 inch move while wielding Stormbringer
inline int mlbStormbringerMoveInches()
    { return 15; }

// armor class 6 while wielding Stormbringer
inline int mlbStormbringerAc()
    { return 6; }

// the 15% dancing-sword chance
inline int mlbStormbringerDancePct()
    { return 15; }

// creatures of less than 5 hit dice
inline int mlbStormbringerFearHd()
    { return 5; }

// within 30 feet flee in panic
inline int mlbStormbringerFearFeet()
    { return 30; }

// the evil moaning and black radiance of Stormbringer
inline bool mlbStormbringerEvilRadiance()
    { return true; }

// the Ring of Kings: the Actorios gem, a ring of many spell storings,
// summoning aid and rod-of-rulership-like control
inline bool mlbRingOfKingsPowers()
    { return true; }

// with the ring: 70% to summon one aid plus minions
inline int mlbRingSummonPct()
    { return 70; }

// with the ring: 80% to control the aid
inline int mlbRingControlPct()
    { return 80; }

// without the ring: 20% to summon
inline int mlbRingBareSummonPct()
    { return 20; }

// without the ring: 30% to control
inline int mlbRingBareControlPct()
    { return 30; }

// the albino weakness of the Melnibonean royal line
inline bool mlbElricAlbino()
    { return true; }

// an 85% chance the potions and herbs restore his strength and constitution
inline int mlbElricPotionChancePct()
    { return 85; }

// up to 15
inline int mlbElricPotionStatMax()
    { return 15; }

// Stormbringer alters the makeup of his body
inline bool mlbElricSwordAltersMakeup()
    { return true; }

// ---- Arioch ----

// the patron of Elric
inline bool mlbAriochElricPatron()
    { return true; }

// he wears no armor in battle
inline bool mlbAriochNoArmor()
    { return true; }

// his sword acts as a rod of cancellation
inline bool mlbAriochSwordCancellation()
    { return true; }

// he can appear in any plane
inline bool mlbAriochAnyPlane()
    { return true; }

// the 15% dancing-sword chance of Arioch
inline int mlbAriochDancePct()
    { return 15; }

// human sacrifices and his mood decide his aid
inline bool mlbAriochHumanSacrifice()
    { return true; }

// incredibly handsome to any kind of creature
inline bool mlbAriochHandsomeToAll()
    { return true; }

// arrogant with a short temper
inline bool mlbAriochShortTemper()
    { return true; }

// ---- Moonglum ----

// ambidextrous (a high dexterity): two swords with no penalty with either
// hand
inline bool mlbMoonglumAmbidextrous()
    { return true; }

// the companion and servant of Elric
inline bool mlbMoonglumElricCompanion()
    { return true; }

// dapper, cheerfully slays his attackers
inline bool mlbMoonglumDapper()
    { return true; }

// ---- the Assassinator of the Gods ----

// the 50-foot wings
inline int mlbAssassinatorWingsFeet()
    { return 50; }

// peacock-like tail feathers
inline bool mlbAssassinatorPeacockFeathers()
    { return true; }

// sent by the gods of Chaos to kill special enemies
inline bool mlbAssassinatorChaosErrand()
    { return true; }

// the talons attack as an 11 hit dice monster
inline int mlbAssassinatorTalonHd()
    { return 11; }

// the 50% chance a wing fouls the opponent's weapon that round
inline int mlbAssassinatorFoulPct()
    { return 50; }

// the XP value: VIII
inline int mlbAssassinatorHitDice()
    { return 8; }

// XP: 6,200 flat
inline int mlbAssassinatorXpBase()
    { return 6200; }

// ---- the Clakar ----

// winged apes, the perfect guards
inline bool mlbClakarWingedApes()
    { return true; }

// immune to magical fear
inline bool mlbClakarFearImmune()
    { return true; }

// never surprised
inline bool mlbClakarNeverSurprised()
    { return true; }

// claw/claw plus a rend of 1-8 if both claws hit
inline int mlbClakarRendMax()
    { return 8; }

// the XP value: VI
inline int mlbClakarHitDice()
    { return 6; }

// XP: 650 plus
inline int mlbClakarXpBase()
    { return 650; }

// 10 per hit point
inline int mlbClakarXpPerHp()
    { return 10; }

// ---- the Dharzi Hunting Dog ----

// half bird half dog: a giant hawk head on wolfhound legs
inline bool mlbDharziHawkHead()
    { return true; }

// faultless trackers by scent
inline bool mlbDharziFaultlessTrackers()
    { return true; }

// a scent up to a week old
inline int mlbDharziScentDays()
    { return 7; }

// they hunt in packs
inline bool mlbDharziPacks()
    { return true; }

// claw/claw/bite: 1-4/1-4/2-12
inline int mlbDharziClawMax()
    { return 4; }

// the bite ceiling of the claw/claw/bite print
inline int mlbDharziBiteMax()
    { return 12; }

// the XP value: II
inline int mlbDharziHitDice()
    { return 2; }

// XP: 90 plus
inline int mlbDharziXpBase()
    { return 90; }

// 5 per hit point
inline int mlbDharziXpPerHp()
    { return 5; }

// ---- Darnizhaan ----

// the greatest of the Dead Gods, ruling before the law and chaos gods came
inline bool mlbDarnizhaanDeadGodsKing()
    { return true; }

// fears the new gods and will not come near them
inline bool mlbDarnizhaanFearsNewGods()
    { return true; }

// immune to manufactured items
inline bool mlbDarnizhaanManufacturedImmune()
    { return true; }

// a 5% chance of attacking those digging deeper than 100 feet
inline int mlbDarnizhaanDiggerPct()
    { return 5; }

// the deep-digger depth trigger
inline int mlbDarnizhaanDiggerFeet()
    { return 100; }

// the fists: 6-60 each
inline int mlbDarnizhaanFistMax()
    { return 60; }

// ---- Donblas ----

// so beautiful that those of less than 12th level fall down and worship
// regardless of alignment
inline bool mlbDonblasIncrediblyBeautiful()
    { return true; }

// the worship threshold level
inline int mlbDonblasWorshipLevel()
    { return 12; }

// driven off the Prime Material Plane by the forces of Chaos
inline bool mlbDonblasDrivenOff()
    { return true; }

// waits on his own plane to be summoned back
inline bool mlbDonblasWaitsSummon()
    { return true; }

// his rod: a mace of disruption plus a hammer of thunderbolts plus a rod of
// lordly might
inline bool mlbDonblasRodOfThree()
    { return true; }

// the rod: 3-30 damage
inline int mlbDonblasRodDmgMax()
    { return 30; }

// he comes to any plane with the fighting attribute
inline bool mlbDonblasComesToFight()
    { return true; }

// ---- the Elenoin ----

// tall women, flaming red hair, shark's teeth, two-handed swords
inline bool mlbElenoinSharkTeeth()
    { return true; }

// 10th level fighters
inline bool mlbElenoinTenthFighters()
    { return true; }

// they fear no enemy save the Grahluks, their hereditary enemies
inline bool mlbElenoinHereditaryEnemies()
    { return true; }

// a 5% chance that Grahluks appear where they are summoned
inline int mlbElenoinGrahukPct()
    { return 5; }

// the XP value: VII
inline int mlbElenoinHitDice()
    { return 7; }

// XP: 1,670 flat
inline int mlbElenoinXpBase()
    { return 1670; }

// ---- the Grahuk ----

// giant apes
inline bool mlbGrahukGiantApes()
    { return true; }

// strength 22
inline int mlbGrahukStrength()
    { return 22; }

// attack as 15 hit dice monsters
inline bool mlbGrahukAttackAsFifteen()
    { return true; }

// nets, shields and ropes plus their fists
inline bool mlbGrahukNetsAndRopes()
    { return true; }

// their only goal is the death of the Elenoin
inline bool mlbGrahukOnlyGoal()
    { return true; }

// they kill themselves after a victory
inline bool mlbGrahukSuicide()
    { return true; }

// the XP value: VIII
inline int mlbGrahukHitDice()
    { return 8; }

// XP: 6,650 flat
inline int mlbGrahukXpBase()
    { return 6650; }

// ---- Fileet ----

// a 40-foot-tall golden eagle
inline bool mlbFileetGoldenEagle()
    { return true; }

// the 120-foot wingspan
inline int mlbFileetWingspanFeet()
    { return 120; }

// she senses anything seen by any avian
inline bool mlbFileetAvianSight()
    { return true; }

// calls 1-100 predatory birds
inline int mlbFileetBirdsMax()
    { return 100; }

// no human following, but all avian creatures pay homage
inline bool mlbFileetAvianHomage()
    { return true; }

// ---- Grome ----

// the king of the earth elementals
inline bool mlbGromeKingOfEarth()
    { return true; }

// crosses water without penalty
inline bool mlbGromeWaterCrossing()
    { return true; }

// any earth-related spell as a 50th level caster (plant and animal growth
// too)
inline int mlbGromeEarthSpellLevel()
    { return 50; }

// summons 1-20 earth elementals of 16 hit dice
inline int mlbGromeElementalMax()
    { return 20; }

// the summoned elemental hit dice
inline int mlbGromeElementalHd()
    { return 16; }

// a gnarled, earth-colored oak form
inline bool mlbGromeOakForm()
    { return true; }

// no barrier withstands his fist
inline bool mlbGromeFistBarrier()
    { return true; }

// earth elementals and underground creatures pay homage
inline bool mlbGromeUndergroundHomage()
    { return true; }

// ---- Haaashastaak ----

// a giant tyrannosaurus rex
inline bool mlbHaaashastaakTyrannosaur()
    { return true; }

// if he cannot send the caller back he eats him
inline bool mlbHaaashastaakEatsCaller()
    { return true; }

// his bite never misses
inline bool mlbHaaashastaakNeverMisses()
    { return true; }

// the bite: 7-70
inline int mlbHaaashastaakBiteMax()
    { return 70; }

// returning him requires a wish
inline bool mlbHaaashastaakWishToReturn()
    { return true; }

// revered by all reptilians
inline bool mlbHaaashastaakReptilianHomage()
    { return true; }

// aware of any lizard within sensing range
inline bool mlbHaaashastaakLizardAware()
    { return true; }

// ---- Kakatal ----

// the lord of the fire elementals
inline bool mlbKakatalFireKing()
    { return true; }

// all fire spells as a 30th level caster
inline int mlbKakatalFireSpellLevel()
    { return 30; }

// his body heat does 4-40 within 20 feet
inline int mlbKakatalHeatDmgMax()
    { return 40; }

// the body-heat radius
inline int mlbKakatalHeatFeet()
    { return 20; }

// the flaming fist: 6-48
inline int mlbKakatalFistMax()
    { return 48; }

// summons 1-10 fire elementals of 16 hit dice
inline int mlbKakatalElementalMax()
    { return 10; }

// the summoned elemental hit dice
inline int mlbKakatalElementalHd()
    { return 16; }

// no water or fire attack affects him
inline bool mlbKakatalWaterFireImmune()
    { return true; }

// fire creatures pay homage
inline bool mlbKakatalFireHomage()
    { return true; }

// immune to petrification and paralysis
inline bool mlbKakatalPetrifyImmune()
    { return true; }

// ---- the Kelmain ----

// from Limbo
inline bool mlbKelmainLimboHome()
    { return true; }

// golden, carved-rock-like skin with square eyes
inline bool mlbKelmainGoldenSkin()
    { return true; }

// golden armor and gold broadswords
inline bool mlbKelmainGoldArmor()
    { return true; }

// armies of 10 to 10,000
inline int mlbKelmainTroopMin()
    { return 10; }

// the army size ceiling
inline int mlbKelmainTroopMax()
    { return 10000; }

// one 8th level leader per 10,000
inline int mlbKelmainLeaderLevelMax()
    { return 8; }

// a 2nd level leader per 5 troops
inline int mlbKelmainLeaderLevelMin()
    { return 2; }

// they fight until the battle is won, then keep the land
inline bool mlbKelmainKeepTheLand()
    { return true; }

// immune to petrification and paralysis
inline bool mlbKelmainPetrifyImmune()
    { return true; }

// the XP value: Variable
inline bool mlbKelmainXpVariable()
    { return true; }

// ---- Meerclar ----

// a giant sabre-toothed tigress
inline bool mlbMeerclarSabreTooth()
    { return true; }

// sees from the eyes of any feline
inline bool mlbMeerclarCatEyes()
    { return true; }

// if forced to come she tries to kill the caller
inline bool mlbMeerclarKillsCaller()
    { return true; }

// all felines pay homage
inline bool mlbMeerclarFelineHomage()
    { return true; }

// the claws: 6-72
inline int mlbMeerclarClawMax()
    { return 72; }

// the bite: 10-100
inline int mlbMeerclarBiteMax()
    { return 100; }

// ---- the Mist Giant ----

// bodies of white fog, a shapeless head with yellow eyes
inline bool mlbMistGiantFogForm()
    { return true; }

// four arms with talons
inline int mlbMistGiantArms()
    { return 4; }

// a snaky lower body that slithers over bogs
inline bool mlbMistGiantSlither()
    { return true; }

// 90% invisible in fog or mist
inline int mlbMistGiantInvisiblePct()
    { return 90; }

// cannot be heard
inline bool mlbMistGiantSilent()
    { return true; }

// surprises on 1-5 on d6
inline int mlbMistGiantSurpriseMax()
    { return 5; }

// +2 weapon to hit
inline bool mlbMistGiantPlusTwoToHit()
    { return true; }

// the XP value: VIII
inline int mlbMistGiantHitDice()
    { return 12; }

// XP: 4,950 plus
inline int mlbMistGiantXpBase()
    { return 4950; }

// 16 per hit point
inline int mlbMistGiantXpPerHp()
    { return 16; }

// ---- Misha ----

// the lord of the air elementals
inline bool mlbMishaAirKing()
    { return true; }

// the 30-inch-tall whirlwind
inline int mlbMishaWhirlwindInches()
    { return 30; }

// formed in 3 melee rounds
inline int mlbMishaWhirlwindRounds()
    { return 3; }

// 6 inches at the bottom
inline int mlbMishaWhirlwindBottomInches()
    { return 6; }

// 18 inches at the top
inline int mlbMishaWhirlwindTopInches()
    { return 18; }

// the whirlwind: 6-60
inline int mlbMishaWhirlwindDmgMax()
    { return 60; }

// the strike: 8-64
inline int mlbMishaStrikeMax()
    { return 64; }

// not affected by physical weaponry launched into the air
inline bool mlbMishaAirLaunchedImmune()
    { return true; }

// summons 1-20 air elementals of 16 hit dice
inline int mlbMishaElementalMax()
    { return 20; }

// the summoned elemental hit dice
inline int mlbMishaElementalHd()
    { return 16; }

// weather and wind spells as a 20th level magic-user, druid or cleric
inline int mlbMishaWeatherLevel()
    { return 20; }

// air elementals pay homage
inline bool mlbMishaAirHomage()
    { return true; }

// +4 weapon to hit
inline bool mlbMishaPlusFourToHit()
    { return true; }

// ---- Mordagz ----

// once a Lord of Chaos, demoted to mortal storm-giant status
inline bool mlbMordagzDemotedLord()
    { return true; }

// guards the Shield of Chaos to the death
inline bool mlbMordagzChaosShieldGuard()
    { return true; }

// the shield blocks all Chaos attacks from the front only
inline bool mlbMordagzFrontOnly()
    { return true; }

// a 5-foot round shield bearing the eight-arrowed Chaos symbol
inline int mlbMordagzShieldFeet()
    { return 5; }

// fights as a 15 hit dice monster
inline bool mlbMordagzFightsAsFifteen()
    { return true; }

// the XP value: VIII
inline int mlbMordagzHitDice()
    { return 8; }

// XP: 6,391 flat
inline int mlbMordagzXpBase()
    { return 6391; }

// ---- the Myyrrhn ----

// winged humanoids with hawkish faces
inline bool mlbMyyrrnWingedHumanoids()
    { return true; }

// a 10-foot wingspan
inline int mlbMyyrrnWingspanFeet()
    { return 10; }

// prefer air combat
inline bool mlbMyyrrnAirCombat()
    { return true; }

// flee if below 5 hit points
inline int mlbMyyrrnFleeBelowHp()
    { return 5; }

// hereditary enemies: the giant owls
inline bool mlbMyyrrnOwlEnemies()
    { return true; }

// the XP value: III
inline int mlbMyyrrnHitDice()
    { return 3; }

// XP: 125 plus
inline int mlbMyyrrnXpBase()
    { return 125; }

// 4 per hit point
inline int mlbMyyrrnXpPerHp()
    { return 4; }

// ---- Nnuurrr ----

// hates being summoned
inline bool mlbNnuurrrHatesSummoning()
    { return true; }

// a 55% chance of obeying, then tries to kill the summoner
inline int mlbNnuurrrObeyPct()
    { return 55; }

// those below 8th level flee in fear, no save
inline int mlbNnuurrrFearLevel()
    { return 8; }

// the poison: save at -4 or die
inline int mlbNnuurrrPoisonSavePenalty()
    { return 4; }

// 4-40 blood drain even on a successful save
inline int mlbNnuurrrDrainMax()
    { return 40; }

// the 140-foot wingspan (a giant mosquito)
inline int mlbNnuurrrWingspanFeet()
    { return 140; }

// insect races pay homage
inline bool mlbNnuurrrInsectHomage()
    { return true; }

// ---- the Nihrain Horse ----

// a great black stallion
inline bool mlbNihrainBlackStallion()
    { return true; }

// a 25% chance of shifting ethereal when hit (the hit inflicts nothing)
inline int mlbNihrainEtherealPct()
    { return 25; }

// gallops 48 hours over water, land and chasms without rest
inline int mlbNihrainGallopHours()
    { return 48; }

// lent only to mortals in direct service of the primary forces of neutrality
inline bool mlbNihrainNeutralService()
    { return true; }

// the XP value: VII
inline int mlbNihrainHitDice()
    { return 7; }

// XP: 1,950 plus
inline int mlbNihrainXpBase()
    { return 1950; }

// 14 per hit point
inline int mlbNihrainXpPerHp()
    { return 14; }

// ---- Nuru-ah ----

// totally pacifistic
inline bool mlbNuruAhPacifist()
    { return true; }

// only function: cure the sick and wounded - cure or raise any creature once
// per summoning
inline bool mlbNuruAhCureRaise()
    { return true; }

// wounded beings cannot bring themselves to attack him
inline bool mlbNuruAhWoundedSafe()
    { return true; }

// bovines worship him
inline bool mlbNuruAhBovineWorship()
    { return true; }

// ---- the Oonai ----

// natural shape changers with the chosen shape's non-magical powers
inline bool mlbOonaiShapeChangers()
    { return true; }

// only monster and beast types
inline bool mlbOonaiBeastsOnly()
    { return true; }

// cannot exceed 10 hit dice forms
inline int mlbOonaiFormHdMax()
    { return 10; }

// attack one at a time, the most powerful first
inline bool mlbOonaiOneAtATime()
    { return true; }

// always retain armor class -2 and their original hit points
inline bool mlbOonaiRetainAcHp()
    { return true; }

// their actual form is unknown
inline bool mlbOonaiUnknownForm()
    { return true; }

// the XP value: VII
inline int mlbOonaiHitDice()
    { return 7; }

// XP: 1,950 plus
inline int mlbOonaiXpBase()
    { return 1950; }

// 14 per hit point
inline int mlbOonaiXpPerHp()
    { return 14; }

// ---- Quaolnargn ----

// a giant toad demon from the Abyss
inline bool mlbQuaolnargnAbyssToad()
    { return true; }

// immune to petrification and polymorph
inline bool mlbQuaolnargnPetrifyImmune()
    { return true; }

// a saving throw of 3 for anything else
inline int mlbQuaolnargnSaveTarget()
    { return 3; }

// bites as a 16+ hit dice monster
inline bool mlbQuaolnargnSixteenHdBite()
    { return true; }

// drains 4 energy levels per round, no save
inline int mlbQuaolnargnDrainLevels()
    { return 4; }

// plus 1-10 damage
inline int mlbQuaolnargnBiteMax()
    { return 10; }

// killed early: the victim regains the levels at one turn per level
inline bool mlbQuaolnargnEarlyKillRefund()
    { return true; }

// the XP value: X
inline int mlbQuaolnargnHitDice()
    { return 10; }

// XP: 21,450 flat
inline int mlbQuaolnargnXpBase()
    { return 21450; }

// ---- Pyaray ----

// the Lord of the Ocean Abysses: a huge blood-red octopus
inline bool mlbPyarayOceanAbyss()
    { return true; }

// a pulsing blue gem atop his head (the symbol: a blue gem with eight rays)
inline bool mlbPyarayBlueGem()
    { return true; }

// six tentacles
inline int mlbPyarayTentacles()
    { return 6; }

// 5-40 each
inline int mlbPyarayTentacleMax()
    { return 40; }

// will not lose the last 10 hit points until the gem is crushed
inline int mlbPyarayGemHp()
    { return 10; }

// the gem is of diamond hardness
inline bool mlbPyarayGemDiamondHard()
    { return true; }

// commands the Chaos fleet of sunken ships with undead sailors
inline bool mlbPyarayChaosFleet()
    { return true; }

// ---- Roofdrak ----

// a giant wolfhound, upright, with manipulative paws
inline bool mlbRoofdrakWolfhound()
    { return true; }

// wields a huge lead mace
inline bool mlbRoofdrakLeadMace()
    { return true; }

// the mace: 9-90
inline int mlbRoofdrakMaceMax()
    { return 90; }

// senses anything within range of any canine
inline bool mlbRoofdrakCanineSense()
    { return true; }

// summons 1-100 dire wolves
inline int mlbRoofdrakWolfMax()
    { return 100; }

// canines pay homage
inline bool mlbRoofdrakCanineHomage()
    { return true; }

// ---- Straasha ----

// the ruler of the water elementals
inline bool mlbStraashaWaterKing()
    { return true; }

// has double the power of a normal water elemental
inline bool mlbStraashaDoublePower()
    { return true; }

// all water spells at 20th level
inline int mlbStraashaWaterLevel()
    { return 20; }

// the only one of his type not affected by heat-based attacks
inline bool mlbStraashaHeatImmune()
    { return true; }

// summons 3-18 kindred
inline int mlbStraashaKindredMin()
    { return 3; }

// the kindred summon ceiling
inline int mlbStraashaKindredMax()
    { return 18; }

// two waves of water per round, 8-48 each, out of thin air
inline int mlbStraashaWaveMax()
    { return 48; }

// green skin, turquoise hair and beard
inline bool mlbStraashaGreenSkin()
    { return true; }

// +4 weapon to hit
inline bool mlbStraashaPlusFourToHit()
    { return true; }

// ---- the Vampire Trees ----

// release leaves that attach to victims, attacking as 12 hit dice
inline bool mlbVampTreeAttachLeaves()
    { return true; }

// 2-8 damage per round per attached leaf
inline int mlbVampTreeLeafDmgMax()
    { return 8; }

// the leaves: armor class 9 with 2 hit points
inline int mlbVampTreeLeafHp()
    { return 2; }

// the leaf armor class
inline int mlbVampTreeLeafAc()
    { return 9; }

// the tree controls at most 10 leaves
inline int mlbVampTreeLeafControlMax()
    { return 10; }

// the leaves return when the victim is beyond 120 yards or bloodless
inline int mlbVampTreeRangeYards()
    { return 120; }

// fears fire: never sends leaves near flame
inline bool mlbVampTreeFireFears()
    { return true; }

// fire attacks: save at -2
inline int mlbVampTreeFireSavePenalty()
    { return 2; }

// +1 damage per die from fire
inline bool mlbVampTreeFirePerDie()
    { return true; }

// never surprised
inline bool mlbVampTreeNeverSurprised()
    { return true; }

// the XP value: VIII
inline int mlbVampTreeHitDice()
    { return 8; }

// XP: 3,850 plus
inline int mlbVampTreeXpBase()
    { return 3850; }

// 16 per hit point
inline int mlbVampTreeXpPerHp()
    { return 16; }

// ---- Theleb K'aarna ----

// an evil wizard of Pan Tang
inline bool mlbThelebPanTangian()
    { return true; }

// calls demons, elementals and demigods
inline bool mlbThelebCallsPowers()
    { return true; }

// a special 7th level spell from his ancestors
inline int mlbThelebAncestorSpellLevel()
    { return 7; }

// works only for those of the blood of Pan Tang
inline bool mlbThelebBloodOnly()
    { return true; }

// an enemy of Elric
inline bool mlbThelebElricEnemy()
    { return true; }

// ---- the Vulture Lion ----

// created by Elric's ancestors from the fiber of Chaos
inline bool mlbVultureLionChaosFiber()
    { return true; }

// summoned from Limbo
inline bool mlbVultureLionLimboHome()
    { return true; }

// fights fiercely, never checking morale
inline bool mlbVultureLionNoMorale()
    { return true; }

// improperly summoned: slays the summoner and returns to Limbo
inline bool mlbVultureLionSlaysBadSummoner()
    { return true; }

// immune to fear
inline bool mlbVultureLionFearImmune()
    { return true; }

// the talons: 4-24/4-24
inline int mlbVultureLionTalonMax()
    { return 24; }

// the beak: 3-18
inline int mlbVultureLionBiteMax()
    { return 18; }

// the XP value: IX
inline int mlbVultureLionHitDice()
    { return 9; }

// XP: 5,600 plus
inline int mlbVultureLionXpBase()
    { return 5600; }

// 20 per hit point
inline int mlbVultureLionXpPerHp()
    { return 20; }

// ---- Xiombarg ----

// appears as a slim young girl
inline bool mlbXiombargYoungGirlForm()
    { return true; }

// the +4 double-edged battle axe, glowing light blue
inline int mlbXiombargAxePlus()
    { return 4; }

// the axe: 7-42 plus strength bonus
inline int mlbXiombargAxeMax()
    { return 42; }

// paralysis unless a save is made
inline bool mlbXiombargParalyzingHit()
    { return true; }

// craves blood and souls like Arioch
inline bool mlbXiombargCravesBlood()
    { return true; }

// responds to proper sacrifices
inline bool mlbXiombargSacrificeResponse()
    { return true; }

// +3 weapon to hit
inline int mlbXiombargPlusToHit()
    { return 3; }

// ---- Yyrkoon ----

// the evil prince of Melnibone
inline bool mlbYyrkoonEvilPrince()
    { return true; }

// Elric's cousin and implacable enemy
inline bool mlbYyrkoonElricCousin()
    { return true; }

// unusual spells from his ancestors
inline bool mlbYyrkoonAncestorSpells()
    { return true; }

// known to fight with Mournblade, the twin of Stormbringer, similar in all
// respects
inline bool mlbYyrkoonMournblade()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Darnizhaan the minus eight best, Donblas minus six,
// Arioch and Xiombarg minus two; Elric the 6/minus 6 dual print; the Vampire
// Trees the 0; Theleb 10 the worst)
inline int mlbCbtAC(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return -2;
        case 2:
            return 2;
        case 3:
            return -2;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return -8;
        case 7:
            return -6;
        case 8:
            return 6;
        case 9:
            return -2;
        case 10:
            return -2;
        case 11:
            return -5;
        case 12:
            return -3;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return -2;
        case 16:
            return -6;
        case 17:
            return -2;
        case 18:
            return -4;
        case 19:
            return 8;
        case 20:
            return -2;
        case 21:
            return -2;
        case 22:
            return -2;
        case 23:
            return -2;
        case 24:
            return -4;
        case 25:
            return -2;
        case 26:
            return -2;
        case 27:
            return -2;
        case 28:
            return 0;
        case 29:
            return 10;
        case 30:
            return 2;
        case 31:
            return -2;
        case 32:
            return -4;
        default:
            return 0;
        }
    }

// The alternative armor class cells (Elric the minus 6 Stormbringer cell; all
// the rest single-printed 0)
inline int mlbCbtACAlt(int b)
    {
        switch (b) {
        case 0:
            return -6;
        case 1:
            return 0;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The hit point cells (Donblas 400, Arioch 379, Xiombarg 376; the hit-dice
// rows pinned 0 with the dice here: Clakar 8, Dharzi 5, the Mist Giant 12,
// Myyrrhn 4, the Nihrain 10, the Oonai 10, the Vampire Trees 12, the Vulture
// Lion 15; the Kelmain See below row)
inline int mlbCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 45;
        case 1:
            return 379;
        case 2:
            return 98;
        case 3:
            return 100;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 300;
        case 7:
            return 400;
        case 8:
            return 55;
        case 9:
            return 70;
        case 10:
            return 176;
        case 11:
            return 335;
        case 12:
            return 197;
        case 13:
            return 289;
        case 14:
            return 0;
        case 15:
            return 152;
        case 16:
            return 0;
        case 17:
            return 189;
        case 18:
            return 80;
        case 19:
            return 0;
        case 20:
            return 300;
        case 21:
            return 0;
        case 22:
            return 200;
        case 23:
            return 0;
        case 24:
            return 150;
        case 25:
            return 250;
        case 26:
            return 97;
        case 27:
            return 189;
        case 28:
            return 0;
        case 29:
            return 44;
        case 30:
            return 0;
        case 31:
            return 376;
        case 32:
            return 84;
        default:
            return 0;
        }
    }

// The primary move cells (Misha the 72 whirlwind; Fileet 18 with the 96
// airborne, Grome 18 with the 48; Elric 6 with the 15 Stormbringer cell)
inline int mlbCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 18;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 6;
        case 5:
            return 15;
        case 6:
            return 18;
        case 7:
            return 15;
        case 8:
            return 12;
        case 9:
            return 15;
        case 10:
            return 18;
        case 11:
            return 18;
        case 12:
            return 21;
        case 13:
            return 24;
        case 14:
            return 12;
        case 15:
            return 30;
        case 16:
            return 9;
        case 17:
            return 72;
        case 18:
            return 15;
        case 19:
            return 12;
        case 20:
            return 12;
        case 21:
            return 24;
        case 22:
            return 15;
        case 23:
            return 12;
        case 24:
            return 12;
        case 25:
            return 12;
        case 26:
            return 18;
        case 27:
            return 12;
        case 28:
            return 12;
        case 29:
            return 12;
        case 30:
            return 15;
        case 31:
            return 18;
        case 32:
            return 12;
        default:
            return 0;
        }
    }

// The secondary move cells (Fileet 96, Grome 48, Nnuurrr 48, the Assassinator
// 24, Darnizhaan 24, Donblas 24, Myyrrhn 24, the Nihrain 24, Straasha 36)
inline int mlbCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 18;
        case 2:
            return 0;
        case 3:
            return 24;
        case 4:
            return 18;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 24;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 96;
        case 11:
            return 48;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 24;
        case 20:
            return 48;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 36;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The attack count cells (Nuru-ah the 0 zero-attack pacifist row; the Oonai
// Variable pinned 0; the Vampire Trees 10 the ceiling of the printed 1-10
// leaf range)
inline int mlbCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 3;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 3;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 6;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 10;
        case 29:
            return 1;
        case 30:
            return 3;
        case 31:
            return 2;
        case 32:
            return 2;
        default:
            return 0;
        }
    }

// The alternate-attack cells (Elenoin, Nnuurrr and Straasha the 3/2 pairs; 0
// elsewhere)
inline int mlbCbtAtD(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 2;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance cells (Nuru-ah 100, Darnizhaan 95, Grahuk 95, the
// Assassinator 90, Arioch 90, Quaolnargn 85; Elric Standard-or-85 pinned 0
// with the 85 riding the Stormbringer consts; Roofdrak 10)
inline int mlbCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 90;
        case 2:
            return 0;
        case 3:
            return 90;
        case 4:
            return 25;
        case 5:
            return 0;
        case 6:
            return 95;
        case 7:
            return 50;
        case 8:
            return 25;
        case 9:
            return 95;
        case 10:
            return 50;
        case 11:
            return 50;
        case 12:
            return 75;
        case 13:
            return 50;
        case 14:
            return 0;
        case 15:
            return 50;
        case 16:
            return 0;
        case 17:
            return 50;
        case 18:
            return 0;
        case 19:
            return 5;
        case 20:
            return 15;
        case 21:
            return 25;
        case 22:
            return 100;
        case 23:
            return 0;
        case 24:
            return 85;
        case 25:
            return 50;
        case 26:
            return 10;
        case 27:
            return 50;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 25;
        case 31:
            return 50;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The size inch cells (Haaashastaak the 720 sixty-footer, Nnuurrr 480, the
// Vampire Trees 300 - the printed L plus a stray 25 feet tall noted, Misha
// 360; Fileet the bare L and Arioch the Variable pinned 0; the fraction cells
// Moonglum 66, Theleb 66, Yyrkoon 78)
inline int mlbCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 72;
        case 1:
            return 0;
        case 2:
            return 66;
        case 3:
            return 108;
        case 4:
            return 96;
        case 5:
            return 60;
        case 6:
            return 240;
        case 7:
            return 84;
        case 8:
            return 72;
        case 9:
            return 120;
        case 10:
            return 0;
        case 11:
            return 240;
        case 12:
            return 720;
        case 13:
            return 240;
        case 14:
            return 72;
        case 15:
            return 240;
        case 16:
            return 96;
        case 17:
            return 360;
        case 18:
            return 252;
        case 19:
            return 72;
        case 20:
            return 480;
        case 21:
            return 96;
        case 22:
            return 240;
        case 23:
            return 60;
        case 24:
            return 96;
        case 25:
            return 120;
        case 26:
            return 156;
        case 27:
            return 120;
        case 28:
            return 300;
        case 29:
            return 66;
        case 30:
            return 120;
        case 31:
            return 60;
        case 32:
            return 78;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (Elric 10, Arioch 20, Donblas 20; Grome and Nuru-ah
// the printed See below pinned 99, the egp Isis precedent)
inline int mlbClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
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
            return 20;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 99;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 99;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The druid level cells (Elric 5, Darnizhaan 14, Meerclar 14; Grome and
// Nuru-ah the See below 99 pairs)
inline int mlbClsDruid(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 14;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 99;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 14;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 99;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The lower fighter level cells (Donblas 25, Arioch 15, Darnizhaan 20, Elric
// 15, Fileet 15, Haaashastaak 20, Kakatal 18, Meerclar 15, Nnuurrr 18, Pyaray
// 15, Straasha 19, Xiombarg 15, Yyrkoon 15, Moonglum 14)
inline int mlbClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 15;
        case 2:
            return 14;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 25;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 20;
        case 13:
            return 18;
        case 14:
            return 0;
        case 15:
            return 15;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 18;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 15;
        case 26:
            return 0;
        case 27:
            return 19;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 15;
        case 32:
            return 15;
        default:
            return 0;
        }
    }

// The upper fighter level cells (0 throughout - the round prints no paladins)
inline int mlbClsFighterHi(int b)
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
            return 0;
        case 6:
            return 0;
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
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The ranger level cells (Grome 18, Misha 18, Roofdrak 15 - the Nth level
// ranger prints)
inline int mlbClsRanger(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 18;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 18;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 15;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user level cells (Donblas 30, Elric 19, Arioch 20, Xiombarg 25,
// Theleb 15, Yyrkoon 17; the See below 99 pairs: Grome, Kakatal, Misha,
// Straasha)
inline int mlbClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 20;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 15;
        case 7:
            return 30;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 99;
        case 12:
            return 0;
        case 13:
            return 99;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 99;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 10;
        case 26:
            return 0;
        case 27:
            return 99;
        case 28:
            return 0;
        case 29:
            return 15;
        case 30:
            return 0;
        case 31:
            return 25;
        case 32:
            return 17;
        default:
            return 0;
        }
    }

// The illusionist level cells (Elric 10, Arioch 20, Darnizhaan 15, Donblas
// 30, Pyaray 10, Theleb 8; the See below 99 pairs: Grome, Kakatal, Misha,
// Straasha)
inline int mlbClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 15;
        case 7:
            return 30;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 99;
        case 12:
            return 0;
        case 13:
            return 99;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 99;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 10;
        case 26:
            return 0;
        case 27:
            return 99;
        case 28:
            return 0;
        case 29:
            return 8;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The thief level cells (Moonglum the 13th - the only print)
inline int mlbClsThief(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 13;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The assassin level cells (Elric 10, Arioch 15, Xiombarg 15)
inline int mlbClsAssassin(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 15;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The monk level cells (Donblas 15 in each with the bard pair; 0 elsewhere)
inline int mlbClsMonk(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 15;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The bard level cells (Donblas 15 in each, Arioch 10, Fileet 15, Moonglum 5,
// Roofdrak 10, Yyrkoon 5)
inline int mlbClsBard(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 15;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 10;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 5;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (the thirteen 25s of the gods; Elric the 6(15) albino
// row, Yyrkoon 16, Moonglum 17)
inline int mlbAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 25;
        case 2:
            return 17;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 25;
        case 7:
            return 25;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 23;
        case 11:
            return 25;
        case 12:
            return 25;
        case 13:
            return 25;
        case 14:
            return 0;
        case 15:
            return 25;
        case 16:
            return 0;
        case 17:
            return 25;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 25;
        case 21:
            return 0;
        case 22:
            return 25;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 25;
        case 26:
            return 23;
        case 27:
            return 25;
        case 28:
            return 0;
        case 29:
            return 12;
        case 30:
            return 0;
        case 31:
            return 25;
        case 32:
            return 16;
        default:
            return 0;
        }
    }

// The strength to-hit bonuses (the +7s of the printed 25(70) brackets; 0 the
// no-printed-bracket rows: Elric, Fileet, Haaashastaak, Nnuurrr, Nuru-ah,
// Pyaray, Straasha, Theleb, Yyrkoon)
inline int mlbAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 7;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 7;
        case 7:
            return 7;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 7;
        case 12:
            return 0;
        case 13:
            return 7;
        case 14:
            return 0;
        case 15:
            return 7;
        case 16:
            return 0;
        case 17:
            return 7;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 5;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 7;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The strength damage bonuses (the 14s of the printed brackets)
inline int mlbAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 14;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 14;
        case 7:
            return 14;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 14;
        case 12:
            return 0;
        case 13:
            return 14;
        case 14:
            return 0;
        case 15:
            return 14;
        case 16:
            return 0;
        case 17:
            return 14;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 11;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 14;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The intelligence cells (Arioch, Darnizhaan and Donblas 25; Fileet 23,
// Pyaray 23, Elric 18)
inline int mlbAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 25;
        case 2:
            return 11;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 25;
        case 7:
            return 25;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 23;
        case 11:
            return 10;
        case 12:
            return 11;
        case 13:
            return 20;
        case 14:
            return 0;
        case 15:
            return 22;
        case 16:
            return 0;
        case 17:
            return 19;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 10;
        case 21:
            return 0;
        case 22:
            return 15;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 23;
        case 26:
            return 20;
        case 27:
            return 15;
        case 28:
            return 0;
        case 29:
            return 18;
        case 30:
            return 0;
        case 31:
            return 23;
        case 32:
            return 18;
        default:
            return 0;
        }
    }

// The wisdom cells (Donblas 25, Nuru-ah 25; the Haaashastaak and Nnuurrr 3
// cells flagged odd and pinned as printed)
inline int mlbAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 21;
        case 2:
            return 9;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 13;
        case 7:
            return 25;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 23;
        case 11:
            return 10;
        case 12:
            return 3;
        case 13:
            return 8;
        case 14:
            return 0;
        case 15:
            return 13;
        case 16:
            return 0;
        case 17:
            return 13;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 3;
        case 21:
            return 0;
        case 22:
            return 25;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 9;
        case 26:
            return 20;
        case 27:
            return 15;
        case 28:
            return 0;
        case 29:
            return 11;
        case 30:
            return 0;
        case 31:
            return 22;
        case 32:
            return 8;
        default:
            return 0;
        }
    }

// The dexterity cells (Arioch, Darnizhaan and Donblas 25; Elric 17)
inline int mlbAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 25;
        case 2:
            return 19;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 25;
        case 7:
            return 25;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 25;
        case 11:
            return 15;
        case 12:
            return 19;
        case 13:
            return 20;
        case 14:
            return 0;
        case 15:
            return 25;
        case 16:
            return 0;
        case 17:
            return 22;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 20;
        case 21:
            return 0;
        case 22:
            return 15;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 18;
        case 26:
            return 21;
        case 27:
            return 20;
        case 28:
            return 0;
        case 29:
            return 15;
        case 30:
            return 0;
        case 31:
            return 25;
        case 32:
            return 15;
        default:
            return 0;
        }
    }

// The constitution cells (the 25s; Elric the 3(15) sickly row)
inline int mlbAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 25;
        case 2:
            return 18;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 25;
        case 7:
            return 25;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 25;
        case 12:
            return 24;
        case 13:
            return 25;
        case 14:
            return 0;
        case 15:
            return 20;
        case 16:
            return 0;
        case 17:
            return 25;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 25;
        case 21:
            return 0;
        case 22:
            return 25;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 24;
        case 26:
            return 22;
        case 27:
            return 25;
        case 28:
            return 0;
        case 29:
            return 17;
        case 30:
            return 0;
        case 31:
            return 24;
        case 32:
            return 17;
        default:
            return 0;
        }
    }

// The charisma cells (Donblas 25, Xiombarg 25; the Nnuurrr and Pyaray minus 6
// cells - the negative charisma prints; Arioch Variable pinned 0)
inline int mlbAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 0;
        case 2:
            return 15;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 16;
        case 7:
            return 25;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 23;
        case 11:
            return 13;
        case 12:
            return 4;
        case 13:
            return 7;
        case 14:
            return 0;
        case 15:
            return 21;
        case 16:
            return 0;
        case 17:
            return 10;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return -6;
        case 21:
            return 0;
        case 22:
            return 9;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return -6;
        case 26:
            return 19;
        case 27:
            return 22;
        case 28:
            return 0;
        case 29:
            return 7;
        case 30:
            return 0;
        case 31:
            return 25;
        case 32:
            return 18;
        default:
            return 0;
        }
    }

// The psionic cells (0 throughout - the psionic classes ride the roster grid)
inline int mlbAbiPsi(int b)
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
            return 0;
        case 6:
            return 0;
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
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Elric through Yyrkoon)
inline int mlbRosOrd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 12;
        case 13:
            return 13;
        case 14:
            return 14;
        case 15:
            return 15;
        case 16:
            return 16;
        case 17:
            return 17;
        case 18:
            return 18;
        case 19:
            return 19;
        case 20:
            return 20;
        case 21:
            return 21;
        case 22:
            return 22;
        case 23:
            return 23;
        case 24:
            return 24;
        case 25:
            return 25;
        case 26:
            return 26;
        case 27:
            return 27;
        case 28:
            return 28;
        case 29:
            return 29;
        case 30:
            return 30;
        case 31:
            return 31;
        case 32:
            return 32;
        default:
            return 0;
        }
    }

// The print page cells (86-95, the folio offset PRINT = PDF - 1)
inline int mlbRosPage(int b)
    {
        switch (b) {
        case 0:
            return 86;
        case 1:
            return 87;
        case 2:
            return 87;
        case 3:
            return 87;
        case 4:
            return 88;
        case 5:
            return 88;
        case 6:
            return 88;
        case 7:
            return 88;
        case 8:
            return 89;
        case 9:
            return 89;
        case 10:
            return 89;
        case 11:
            return 89;
        case 12:
            return 90;
        case 13:
            return 90;
        case 14:
            return 90;
        case 15:
            return 91;
        case 16:
            return 91;
        case 17:
            return 91;
        case 18:
            return 91;
        case 19:
            return 92;
        case 20:
            return 92;
        case 21:
            return 92;
        case 22:
            return 92;
        case 23:
            return 93;
        case 24:
            return 93;
        case 25:
            return 93;
        case 26:
            return 93;
        case 27:
            return 94;
        case 28:
            return 94;
        case 29:
            return 94;
        case 30:
            return 95;
        case 31:
            return 95;
        case 32:
            return 95;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG, 1 NG, 2 CG, 3 LN, 4 N, 5 CN, 6 LE, 7 NE, 8 CE -
// the R852 code scheme; fourteen of the thirty-three print the neutral 4)
inline int mlbRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 4;
        case 3:
            return 8;
        case 4:
            return 8;
        case 5:
            return 4;
        case 6:
            return 7;
        case 7:
            return 0;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 5;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 8;
        case 17:
            return 4;
        case 18:
            return 5;
        case 19:
            return 1;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 5;
        case 24:
            return 8;
        case 25:
            return 8;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 7;
        case 29:
            return 6;
        case 30:
            return 5;
        case 31:
            return 8;
        case 32:
            return 8;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser, 1 greater, 2 demigod, 3 hero, 5 monster - the
// fourteen monster rows make this the monster-heaviest round of the walk)
inline int mlbRosRank(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 2;
        case 11:
            return 0;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return 5;
        case 15:
            return 2;
        case 16:
            return 5;
        case 17:
            return 0;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 2;
        case 21:
            return 5;
        case 22:
            return 2;
        case 23:
            return 5;
        case 24:
            return 5;
        case 25:
            return 0;
        case 26:
            return 2;
        case 27:
            return 0;
        case 28:
            return 5;
        case 29:
            return 3;
        case 30:
            return 5;
        case 31:
            return 1;
        case 32:
            return 3;
        default:
            return 0;
        }
    }

// The psionic class cells (I the single pipe w10: Arioch, Darnizhaan,
// Meerclar, Nuru-ah; II Pyaray; VI the w49: Grome, Haaashastaak, Misha,
// Roofdrak, Straasha; 0 the Nil heroes and monsters)
inline int mlbRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 6;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 2;
        case 26:
            return 6;
        case 27:
            return 6;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 1;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The plane cells (0 none; 1 Prime Material: Darnizhaan, Pyaray; 2 Special:
// Arioch, Donblas, Xiombarg; 3 Earth Grome; 4 Fire Kakatal; 5 Air Misha; 6
// Water Straasha; the demi-plane courts: 7 birds Fileet, 8 reptiles
// Haaashastaak, 9 cats Meerclar, 10 insects Nnuurrr, 11 cattle Nuru-ah, 12
// dogs Roofdrak)
inline int mlbRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 7;
        case 11:
            return 3;
        case 12:
            return 8;
        case 13:
            return 4;
        case 14:
            return 0;
        case 15:
            return 9;
        case 16:
            return 0;
        case 17:
            return 5;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 10;
        case 21:
            return 0;
        case 22:
            return 11;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 12;
        case 27:
            return 6;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 2;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The fixed-damage flags (0 the by-weapon rows Elric, Moonglum, Kelmain,
// Myyrrhn, Yyrkoon; the Nuru-ah Nil damage and the Oonai Variable)
inline int mlbRosDmgFixed(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
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
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The in-each flags (the four MU/I pairs: Arioch 20, Darnizhaan 15, Donblas
// 30, Pyaray 10)
inline int mlbRosInEach(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// The enmity flags (the Elenoin-Grahuk hereditary enemy pair, the grk
// printed-rivalry precedent)
inline int mlbRosEnmity(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
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
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
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
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
