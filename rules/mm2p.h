// =========================================================================================
// Adnd1 - rules/mm2p.h
// THE MM2 LETTER P WALK - THE PARA-ELEMENTAL (ICE, SMOKE, MAGMA AND OOZE),
// PECH, PEDIPALP (LARGE, HUGE AND GIANT), PHANTOM, PHOENIX, PHYCOMID,
// PLANETAR, PSEUDO-UNDEAD, DEADLY PUDDING (BROWN, DUN AND WHITE) AND PYROLISK
// TURNS (the para-elemental family pp. 98-99, the pech p. 99, the pedipalp,
// phantom, phoenix and phycomid pp. 100-101, the planetar pp. 101-102, the
// pseudo-undead and the deadly puddings p. 102, the pyrolisk p. 103),
// promoted to the live registry; the P-FLIP round, the Letter P gap box flips
// to closed
// census 732 -> 733.
//
// Round fifteen of the MM2 arc, the FOURTH single-letter pass (Curtiss Go
// call on the landed letter O walk; the letter P pin-time walk found TEN
// entries - the para-elemental family head with its four form blocks and the
// pedipalp and deadly pudding variant tables each riding three defs; the MM1
// registry already owns the pegasi, piercer, pixie, platinum dragon,
// plesiosaurus, pony, pseudo-dragon, pteranodon and purple worm prints, so no
// prior-owned index entries ride this round)
//
// The pin headers stay the print-fidelity record; the seventeen .lua defs
// ride the R791 data_files extension in the MM1 registry schema (the
// defensive coercers load the verbatim print cells, the PStats grid carries
// the loader values)
//
namespace rules {

// ---- the MM2 letter P walk round pins (the R810 census) ----

// The MM2 letter P walk round: the para-elemental to pyrolisk turns, the
// FOURTH single-letter pass (Curtiss Go call on the landed letter O walk)
inline int mm2pRound()
    { return 810; }

// The registry census before the R810 promotion (the landed R809 count)
inline int mm2pRegistryBefore()
    { return 706; }

// The registry census after the R810 promotion (17 defs)
inline int mm2pRegistryAfter()
    { return 723; }

// The def count of the R810 walk (the ice, smoke, magma and ooze
// para-elementals, the pech, the large, huge and giant pedipalps, the
// phantom, the phoenix, the phycomid, the planetar, the pseudo-undead, the
// brown, dun and white deadly puddings and the pyrolisk)
inline int mm2pDefCount()
    { return 17; }

// The pin-time entry census (10 print entries: the para-elemental family with
// its 4 form blocks, the pech, the pedipalp variant table, the phantom, the
// phoenix, the phycomid, the planetar, the pseudo-undead, the deadly pudding
// variant table and the pyrolisk)
inline int mm2pEntryCount()
    { return 10; }

// The stat-block heading census of the walk (every def pins a stat block -
// the 4 para-elemental forms, the 3 pedipalp columns and the 3 pudding
// columns count each)
inline int mm2pStatBlockHeadings()
    { return 17; }

// The doctrine-only family head census (the PARA-ELEMENTAL family head - its
// summoning doctrine rides as consts, the R808 lycanthrope precedent)
inline int mm2pDoctrineHeads()
    { return 1; }

// The letter P heading census (the para-elemental through the pyrolisk)
inline int mm2pLetterPHeadings()
    { return 10; }

// The PStats grid row count (one row per def)
inline int mm2pPStatRows()
    { return 17; }

// The MM2 gap report closed box count after the P-flip (the R809 census 20 +
// the Letter P box)
inline int mm2pGapClosed()
    { return 21; }

// The MM2 gap report open box count after the P-flip (the R809 census 17 -
// the Letter P box)
inline int mm2pGapOpen()
    { return 16; }

// The prior-owned letter P index entries (none - the MM1 registry pegasi,
// piercer, pixie, platinum dragon, plesiosaurus, pony, pseudo-dragon,
// pteranodon and purple worm prints are MM1 walks, not MM2 letter P pages)
inline int mm2pPriorOwnedEntries()
    { return 0; }

// ---- the para-elemental pins (the R810 MM2 letter P walk) ----

// The para-elemental planes (Ice, Ooze, Magma and Smoke, between the major
// planes of Earth, Air, Fire and Water)
inline int mm2pParaElementalPlaneCount()
    { return 4; }

// The conjured hit-dice-strength categories (16 HD by spell, 12 HD by
// summoning device, 8 HD by staff)
inline int mm2pParaElementalHdCategories()
    { return 3; }

// The spell-conjured para-elemental strength (16 HD)
inline int mm2pParaElementalSpellHd()
    { return 16; }

// The device-conjured para-elemental strength (12 HD)
inline int mm2pParaElementalDeviceHd()
    { return 12; }

// The staff-conjured para-elemental strength (8 HD)
inline int mm2pParaElementalStaffHd()
    { return 8; }

// The chance of not getting the summoned para-elemental but one from an
// adjoining major plane (100% minus 5% per summoner level)
inline int mm2pParaElementalEscapePctBase()
    { return 100; }

// The escape-chance reduction per level of the summoner
inline int mm2pParaElementalEscapePctPerLevel()
    { return 5; }

// The weapon enchantment floor (+1 or better to hit)
inline int mm2pParaElementalWeaponFloor()
    { return 1; }

// The hit-dice floor for creatures without magical ability (4 hit dice or
// less cannot harm a para-elemental)
inline int mm2pParaElementalHdlessFloor()
    { return 4; }

// Control over a para-elemental must be maintained at all times, otherwise it
// will turn on its summoner
inline bool mm2pParaElementalTurnsOnSummoner()
    { return true; }

// The ice para-elemental cold aura radius in feet (1-4 damage per round
// within 10 feet)
inline int mm2pParaIceColdAuraFeet()
    { return 10; }

// The cold aura damage minimum per round
inline int mm2pParaIceColdAuraDamageMin()
    { return 1; }

// The cold aura damage maximum per round
inline int mm2pParaIceColdAuraDamageMax()
    { return 4; }

// The freeze-on-touch area in square feet per round
inline int mm2pParaIceFreezeAreaSqFt()
    { return 100; }

// The freeze-on-touch depth in inches
inline int mm2pParaIceFreezeDepthInches()
    { return 6; }

// The ice-contact healing rate minimum (1-8 hit points per round)
inline int mm2pParaIceHealPerRoundMin()
    { return 1; }

// The ice-contact healing rate maximum
inline int mm2pParaIceHealPerRoundMax()
    { return 8; }

// Fire-based attacks do double damage to an ice para-elemental
inline bool mm2pParaIceFireDoubleDamage()
    { return true; }

// Attacks against cold-using opponents are at -1 to damage dice
inline bool mm2pParaIceColdUsersDamageDiceMinus1()
    { return true; }

// The smoke para-elemental engagement radius in feet
inline int mm2pParaSmokeEngageRadiusFeet()
    { return 10; }

// The blinding-smoke to-hit penalty (-2 on a failed save vs. poison)
inline int mm2pParaSmokeBlindHitPenalty()
    { return 2; }

// The fog-form does double damage when it hits a target
inline bool mm2pParaSmokeFogDoubleDamage()
    { return true; }

// Smoke elementals are -1 on damage dice from all air-based attacks,
// including those from air elementals
inline bool mm2pParaSmokeAirAttacksDamageDiceMinus1()
    { return true; }

// The magma heat-metal effect radius in feet
inline int mm2pParaMagmaHeatRadiusFeet()
    { return 20; }

// The 2nd-round hot metal wielder damage maximum (1-4)
inline int mm2pParaMagmaHotMetalRound2DamageMax()
    { return 4; }

// The 3rd-round metal-user damage minimum (2-8)
inline int mm2pParaMagmaMetalRound3DamageMin()
    { return 2; }

// The 3rd-round metal-user damage maximum
inline int mm2pParaMagmaMetalRound3DamageMax()
    { return 8; }

// The 3rd-round nonmetal-user damage maximum (1-4)
inline int mm2pParaMagmaNonmetalRound3DamageMax()
    { return 4; }

// Wood and other flammable objects brought in contact with the para-elemental
// or metal heated by it burst into flame
inline bool mm2pParaMagmaFlammablesIgnite()
    { return true; }

// The ooze constrict damage minimum per round (2-16)
inline int mm2pParaOozeConstrictDamageMin()
    { return 2; }

// The ooze constrict damage maximum per round
inline int mm2pParaOozeConstrictDamageMax()
    { return 16; }

// The ooze constricts until the para-elemental is dispelled, defeated, or
// releases the opponent on command of the summoner
inline bool mm2pParaOozeConstrictsUntilReleased()
    { return true; }

// The ooze para-elemental's form is mutable, fitting into tight crevices and
// beneath doorways with ease
inline bool mm2pParaOozeMutableForm()
    { return true; }

// The para-elemental ice xpValue (the 2850 + 15/hp block: 2850 + 15x28)
inline int mm2pParaIceXpValue()
    { return 3270; }

// The para-elemental ice experience level (the roman VII)
inline int mm2pParaIceXpLevel()
    { return 7; }

// The para-elemental smoke xpValue (the 2850 + 15/hp block: 2850 + 15x28)
inline int mm2pParaSmokeXpValue()
    { return 3270; }

// The para-elemental smoke experience level (the roman VII)
inline int mm2pParaSmokeXpLevel()
    { return 7; }

// The para-elemental magma xpValue (the 2850 + 15/hp block: 2850 + 15x28)
inline int mm2pParaMagmaXpValue()
    { return 3270; }

// The para-elemental magma experience level (the roman VII)
inline int mm2pParaMagmaXpLevel()
    { return 7; }

// The para-elemental ooze xpValue (the 2850 + 15/hp block: 2850 + 15x28)
inline int mm2pParaOozeXpValue()
    { return 3270; }

// The para-elemental ooze experience level (the roman VII)
inline int mm2pParaOozeXpLevel()
    { return 7; }

// ---- the pech pins (the R810 MM2 letter P walk) ----

// The stone shape spells per day (4 per pech)
inline int mm2pPechStoneShapePerDay()
    { return 4; }

// The stone tell spells per day (4 per pech)
inline int mm2pPechStoneTellPerDay()
    { return 4; }

// The pech together casting a wall of stone (four together)
inline int mm2pPechWallOfStoneGroupCount()
    { return 4; }

// The wall of stone casting level (as if 16th-level magic-users)
inline int mm2pPechWallOfStoneCasterLevel()
    { return 16; }

// The pech together casting a stone to flesh (eight together)
inline int mm2pPechStoneToFleshGroupCount()
    { return 8; }

// The group spells cast but once per day by any group
inline int mm2pPechGroupSpellsPerDay()
    { return 1; }

// The lair gems minimum (50-100)
inline int mm2pPechLairGemsMin()
    { return 50; }

// The lair gems maximum
inline int mm2pPechLairGemsMax()
    { return 100; }

// The lair jewelry minimum (5-30 pieces of lowest base value)
inline int mm2pPechLairJewelryMin()
    { return 5; }

// The lair jewelry maximum
inline int mm2pPechLairJewelryMax()
    { return 30; }

// The average jewelry weight in gp each
inline int mm2pPechJewelryAvgWeightGp()
    { return 150; }

// The lair young percentage minimum (20-50% of the females)
inline int mm2pPechYoungPctMin()
    { return 20; }

// The lair young percentage maximum
inline int mm2pPechYoungPctMax()
    { return 50; }

// Pech are immune to petrification
inline bool mm2pPechImmuneToPetrification()
    { return true; }

// Against lithic monsters such as a stone golem the pech have full normal
// attack capability, knocking them to rubble
inline bool mm2pPechFullAttackVsLithicMonsters()
    { return true; }

// Pech hate bright light and open skies
inline bool mm2pPechHateBrightLight()
    { return true; }

// In their lair the females equal the number of males
inline bool mm2pPechFemalesEqualMales()
    { return true; }

// Pech have both infra- and ultravision
inline bool mm2pPechInfraAndUltravision()
    { return true; }

// The pech xpValue (the 240 + 4/hp block: 240 + 4x14)
inline int mm2pPechXpValue()
    { return 296; }

// The pech experience level (the roman IV)
inline int mm2pPechXpLevel()
    { return 4; }

// ---- the pedipalp pins (the R810 MM2 letter P walk) ----

// The large pedipalpi are incapable of holding any prey larger than
// themselves
inline bool mm2pPedipalpLargeCannotHoldLargerPrey()
    { return true; }

// The huge pedipalp crushing damage minimum (2-12, the same as 2 pincer hits)
inline int mm2pPedipalpHugeCrushDamageMin()
    { return 2; }

// The huge pedipalp crushing damage maximum
inline int mm2pPedipalpHugeCrushDamageMax()
    { return 12; }

// The chance of breaking the huge pedipalp grip is the same as that for
// opening doors
inline bool mm2pPedipalpHugeGripBreaksAsDoors()
    { return true; }

// The giant pedipalp automatic bite damage maximum (2-8)
inline int mm2pPedipalpGiantAutoBiteDamageMax()
    { return 8; }

// The giant pedipalp crushing damage minimum (2-16, the same as 2 pincer
// hits)
inline int mm2pPedipalpGiantCrushDamageMin()
    { return 2; }

// The giant pedipalp crushing damage maximum
inline int mm2pPedipalpGiantCrushDamageMax()
    { return 16; }

// The noxious vapor radius in feet
inline int mm2pPedipalpGiantGasRadiusFeet()
    { return 20; }

// The gas to-hit penalty on a failed save vs. poison (-3 for 1-6 rounds)
inline int mm2pPedipalpGiantGasToHitPenalty()
    { return 3; }

// The gas penalty duration minimum in rounds
inline int mm2pPedipalpGiantGasDurationRoundsMin()
    { return 1; }

// The gas penalty duration maximum in rounds
inline int mm2pPedipalpGiantGasDurationRoundsMax()
    { return 6; }

// The gas discharges per day (3)
inline int mm2pPedipalpGiantGasUsesPerDay()
    { return 3; }

// The pincer severing requires a roll 3 higher than the normal to-hit number
inline int mm2pPedipalpGiantSeverRollAbove()
    { return 3; }

// The giant pedipalp grip may be broken only by killing the monster or
// severing the pincer
inline bool mm2pPedipalpGiantGripBreaksOnlyByKillOrSever()
    { return true; }

// The large pedipalp xpValue (the 20 + 2/hp block: 20 + 2x4)
inline int mm2pPedipalpLargeXpValue()
    { return 28; }

// The large pedipalp experience level (the roman I)
inline int mm2pPedipalpLargeXpLevel()
    { return 1; }

// The huge pedipalp xpValue (the 50 + 3/hp block: 50 + 3x9)
inline int mm2pPedipalpHugeXpValue()
    { return 77; }

// The huge pedipalp experience level (the roman II)
inline int mm2pPedipalpHugeXpLevel()
    { return 2; }

// The giant pedipalp xpValue (the 170 + 5/hp block: 170 + 5x18)
inline int mm2pPedipalpGiantXpValue()
    { return 260; }

// The giant pedipalp experience level (the roman IV)
inline int mm2pPedipalpGiantXpLevel()
    { return 4; }

// ---- the phantom pins (the R810 MM2 letter P walk) ----

// The gaze save penalty (save vs. spells at -2 or panic and run away)
inline int mm2pPhantomGazeSavePenalty()
    { return 2; }

// Phantoms are merely images and cannot themselves be harmed
inline bool mm2pPhantomCannotBeHarmed()
    { return true; }

// Phantoms may not be turned as undead
inline bool mm2pPhantomNotTurnedAsUndead()
    { return true; }

// The clerical spell exorcism will dispel a phantom
inline bool mm2pPhantomExorcismDispels()
    { return true; }

// Phantoms have no intelligence and neither are they alive or undead
inline bool mm2pPhantomNeitherAliveNorUndead()
    { return true; }

// The phantom xpValue (the 0 + 0/hp block: 0 + 0x0)
inline int mm2pPhantomXpValue()
    { return 0; }

// The phantom experience level (the roman The phantom experience level (the
// print Nil/nil block))
inline int mm2pPhantomXpLevel()
    { return 0; }

// ---- the phoenix pins (the R810 MM2 letter P walk) ----

// The piercing whistle radius in feet
inline int mm2pPhoenixWhistleRadiusFeet()
    { return 30; }

// The whistle initiative advantage (+3 on its initiative die)
inline int mm2pPhoenixWhistleInitiativeBonus()
    { return 3; }

// The phoenix spell-like power level (20th)
inline int mm2pPhoenixSpellLevel()
    { return 20; }

// The wing-and-call dispel illusion or dispel magic level (40th)
inline int mm2pPhoenixDispelMagicLevel()
    { return 40; }

// The dance acts as a double-strength (40th level) exorcise spell
inline int mm2pPhoenixExorciseLevel()
    { return 40; }

// The cure light wounds wing touches per individual per day per phoenix
inline int mm2pPhoenixWingTouchesPerDay()
    { return 2; }

// The weapon enchantment floor (+3 or better weapons)
inline int mm2pPhoenixWeaponFloor()
    { return 3; }

// The phoenix infravision in feet (120)
inline int mm2pPhoenixInfravisionFeet()
    { return 120; }

// The gem-like egg days to arise a new phoenix (20)
inline int mm2pPhoenixEggHatchDays()
    { return 20; }

// One fire seed per 5 points of damage taken (the holly berry type)
inline int mm2pPhoenixBloodSeedPerDamage()
    { return 5; }

// The average feather value in gp (50 each)
inline int mm2pPhoenixFeatherGp()
    { return 50; }

// The gem-like beak, talons and eyes value (a hundred times the feathers)
inline int mm2pPhoenixBeakValueMultiplier()
    { return 100; }

// The protection from evil radius in feet (10-foot radius)
inline int mm2pPhoenixProtectionRadiusFeet()
    { return 10; }

// The phoenix can never be surprised
inline bool mm2pPhoenixNeverSurprised()
    { return true; }

// The phoenix can become ethereal and travel astrally or ethereally
inline bool mm2pPhoenixEtherealAndAstralTravel()
    { return true; }

// A phoenix automatically detects charms, evil, and magic
inline bool mm2pPhoenixDetectsCharmsEvilMagic()
    { return true; }

// The phoenix can neither attack nor be attacked by psionic means
inline bool mm2pPhoenixCannotAttackOrBeAttackedPsionically()
    { return true; }

// A touch of the comb gives an effect equal to cure disease, restricted as a
// staff of curing
inline bool mm2pPhoenixCombActsAsStaffOfCuring()
    { return true; }

// A phoenix can speak with all avians
inline bool mm2pPhoenixSpeaksWithAllAvians()
    { return true; }

// The phoenix xpValue (the 8600 + 30/hp block: 8600 + 30x70)
inline int mm2pPhoenixXpValue()
    { return 10700; }

// The phoenix experience level (the roman IX)
inline int mm2pPhoenixXpLevel()
    { return 9; }

// ---- the phycomid pins (the R810 MM2 letter P walk) ----

// The alkaline glob range minimum in feet (7-12)
inline int mm2pPhycomidGlobRangeMinFeet()
    { return 7; }

// The alkaline glob range maximum in feet
inline int mm2pPhycomidGlobRangeMaxFeet()
    { return 12; }

// The infected-area growth onset minimum in rounds (5-8)
inline int mm2pPhycomidInfectionOnsetRoundsMin()
    { return 5; }

// The infected-area growth onset maximum in rounds
inline int mm2pPhycomidInfectionOnsetRoundsMax()
    { return 8; }

// The growth damage minimum (5-8)
inline int mm2pPhycomidInfectionDamageMin()
    { return 5; }

// The growth damage maximum
inline int mm2pPhycomidInfectionDamageMax()
    { return 8; }

// The host death minimum in turns (5-8)
inline int mm2pPhycomidHostDeathTurnsMin()
    { return 5; }

// The host death maximum in turns
inline int mm2pPhycomidHostDeathTurnsMax()
    { return 8; }

// The fire-based attack saving throw bonus (+4)
inline int mm2pPhycomidFireSaveBonus()
    { return 4; }

// Phycomids are immune to all forms of mental attacks, including charms,
// holds, etc.
inline bool mm2pPhycomidImmuneToMentalAttacks()
    { return true; }

// Fire-based damage is either half-normal or none
inline bool mm2pPhycomidFireHalfOrNone()
    { return true; }

// A cure disease spell will stop the spread through the host
inline bool mm2pPhycomidCureDiseaseStopsSpread()
    { return true; }

// The phycomid xpValue (the 280 + 5/hp block: 280 + 5x14)
inline int mm2pPhycomidXpValue()
    { return 350; }

// The phycomid experience level (the roman V)
inline int mm2pPhycomidXpLevel()
    { return 5; }

// ---- the planetar pins (the R810 MM2 letter P walk) ----

// The planetar spirit group numbers not fewer than 100
inline int mm2pPlanetarSpiritGroupMin()
    { return 100; }

// The planetar bastard sword (usable only by planetars) equals a +4 weapon
// with defender and wounding qualities
inline int mm2pPlanetarBastardSwordPlus()
    { return 4; }

// The planetar dexterity for attack determination (21)
inline int mm2pPlanetarDexterity()
    { return 21; }

// The planetar fighting ability (17th level)
inline int mm2pPlanetarFighterLevel()
    { return 17; }

// The planetar wisdom (21)
inline int mm2pPlanetarWisdom()
    { return 21; }

// The spell-like abilities equal to a 7th-level cleric
inline int mm2pPlanetarClericLevel()
    { return 7; }

// The spell-like abilities equal to a 7th-level druid
inline int mm2pPlanetarDruidLevel()
    { return 7; }

// The planetar psionic ability (288)
inline int mm2pPlanetarPsionic()
    { return 288; }

// The weapon enchantment floor (+4 or better weapons)
inline int mm2pPlanetarWeaponFloor()
    { return 4; }

// The planetar regeneration rate (4 points per round)
inline int mm2pPlanetarRegenerationPerRound()
    { return 4; }

// The spirit re-forms and becomes corporeal again in 4 decades
inline int mm2pPlanetarReformDecades()
    { return 4; }

// The deva gate uses per day (1-3, 1-4, or 1-6 of the appropriate sort)
inline int mm2pPlanetarGateUsesPerDay()
    { return 1; }

// The charisma effect (21)
inline int mm2pPlanetarCharisma()
    { return 21; }

// The planetar infravision in inches (12)
inline int mm2pPlanetarInfravisionInches()
    { return 12; }

// The globe of protection from evil maximum radius in feet (individual size
// to a full 40-foot radius)
inline int mm2pPlanetarProtectionRadiusFeet()
    { return 40; }

// Planetars are never surprised
inline bool mm2pPlanetarNeverSurprised()
    { return true; }

// Planetars are immune to any life level loss, whether from undead or magic
inline bool mm2pPlanetarImmuneToLevelLoss()
    { return true; }

// Planetars are immune to death spells
inline bool mm2pPlanetarImmuneToDeathSpells()
    { return true; }

// Planetar souls cannot be imprisoned or trapped
inline bool mm2pPlanetarSoulsCannotBeTrapped()
    { return true; }

// Each planetar can always cure blindness, deafness, disease or light wounds
// by touch
inline bool mm2pPlanetarCuresByTouch()
    { return true; }

// The planetar xpValue (the 60000 + 35/hp block: 60000 + 35x144)
inline int mm2pPlanetarXpValue()
    { return 65040; }

// The planetar experience level (the roman X)
inline int mm2pPlanetarXpLevel()
    { return 10; }

// ---- the pseudo-undead pins (the R810 MM2 letter P walk) ----

// The pseudo-undead normal infravision (6 inches)
inline int mm2pPseudoundeadInfravisionInches()
    { return 6; }

// The pseudo-undead percentage in lair (50%)
inline int mm2pPseudoundeadLairPct()
    { return 50; }

// The pseudo-undead cannot be turned by a cleric and have no connection to
// the Negative Material Plane
inline bool mm2pPseudoundeadNotTurnedByCleric()
    { return true; }

// The pseudo-undead avoid sunlight but are not harmed by it
inline bool mm2pPseudoundeadAvoidSunlightNotHarmed()
    { return true; }

// The pseudo-undead are never found with or near true undead
inline bool mm2pPseudoundeadNeverNearTrueUndead()
    { return true; }

// The stench of pseudoghasts has the same effect as that of ghasts
inline bool mm2pPseudoundeadGhastStench()
    { return true; }

// Pseudowraiths and pseudospectres cannot fly but walk so lightly as to leave
// no trace
inline bool mm2pPseudowraithWalksNotFlies()
    { return true; }

// Pseudovampires have red eyes and behave menacingly but have no special
// abilities
inline bool mm2pPseudovampireRedEyes()
    { return true; }

// The pseudo-undead xpValue (the 0 + 0/hp block: 0 + 0x0)
inline int mm2pPseudoundeadXpValue()
    { return 0; }

// The pseudo-undead experience level (the roman The pseudo-undead experience
// level (the print Nil/nil block))
inline int mm2pPseudoundeadXpLevel()
    { return 0; }

// ---- the pudding pins (the R810 MM2 letter P walk) ----

// The dun pudding eats chainmail in 2 rounds (half the black pudding rate)
inline int mm2pPuddingDunChainmailRounds()
    { return 2; }

// The dun pudding eats plate in 4 rounds
inline int mm2pPuddingDunPlateRounds()
    { return 4; }

// The white pudding mistaken-for-snow chance (50%)
inline int mm2pPuddingWhiteSnowMistakePct()
    { return 50; }

// Lightning bolts or blows from weapons divide deadly puddings into viable
// creatures of smaller size
inline bool mm2pPuddingWeaponsDivideIt()
    { return true; }

// Acid, cold and poison have no effect on deadly puddings
inline bool mm2pPuddingAcidColdPoisonImmune()
    { return true; }

// Fire causes normal damage, as do magic missile spells
inline bool mm2pPuddingFireAndMagicMissileNormalDamage()
    { return true; }

// Brown puddings do not dissolve metals but do destroy leather or wood in a
// single round
inline bool mm2pPuddingBrownDoesNotDissolveMetal()
    { return true; }

// White puddings do not affect metals but dissolve animal or vegetable
// materials in a single round
inline bool mm2pPuddingWhiteDoesNotAffectMetal()
    { return true; }

// The brown pudding xpValue (the 1600 + 16/hp block: 1600 + 16x38)
inline int mm2pPuddingBrownXpValue()
    { return 2208; }

// The brown pudding experience level (the roman VIII)
inline int mm2pPuddingBrownXpLevel()
    { return 8; }

// The dun pudding xpValue (the 1000 + 12/hp block: 1000 + 12x29)
inline int mm2pPuddingDunXpValue()
    { return 1348; }

// The dun pudding experience level (the roman VIII)
inline int mm2pPuddingDunXpLevel()
    { return 8; }

// The white pudding xpValue (the 1200 + 12/hp block: 1200 + 12x31)
inline int mm2pPuddingWhiteXpValue()
    { return 1572; }

// The white pudding experience level (the roman VIII)
inline int mm2pPuddingWhiteXpLevel()
    { return 8; }

// ---- the pyrolisk pins (the R810 MM2 letter P walk) ----

// The failed-gaze-save damage minimum (2-13)
inline int mm2pPyroliskGazeDamageMin()
    { return 2; }

// The failed-gaze-save damage maximum
inline int mm2pPyroliskGazeDamageMax()
    { return 13; }

// The fire-source explosion range in feet (any fire source within 30 feet)
inline int mm2pPyroliskFireworksRangeFeet()
    { return 30; }

// The fireworks area of effect is 10 times that of the fire source
inline int mm2pPyroliskFireworksAreaMultiplier()
    { return 10; }

// The pyrolisk is immune to all fire-based attacks, magical and normal
inline bool mm2pPyroliskImmuneToFire()
    { return true; }

// The pyrolisk mortal enemy is the phoenix, as the latter is also immune to
// fire and detests Evil
inline bool mm2pPyroliskMortalEnemyPhoenix()
    { return true; }

// Any victim making his or her saving throw is thereafter immune to the gaze
// of that particular pyrolisk
inline bool mm2pPyroliskSaveGrantsImmunity()
    { return true; }

// Any creature innately or magically fire-resistant is immune to the gaze
// attack
inline bool mm2pPyroliskFireResistantImmuneToGaze()
    { return true; }

// The pyrolisk xpValue (the 240 + 5/hp block: 240 + 5x17)
inline int mm2pPyroliskXpValue()
    { return 325; }

// The pyrolisk experience level (the roman IV)
inline int mm2pPyroliskXpLevel()
    { return 4; }

// ---- the PStats grid pins (the R810 MM2 letter P walk) ----

// The armor class cells (the phoenix -3 and the planetar -7 ride unquoted
// numbers - the R806 hollyphant -4 precedent; the phantom Nil and the
// pseudo-undead See below read the firstIntIn 9 default)
inline int mm2pPStatAc(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 7;
        case 6:
            return 4;
        case 7:
            return 2;
        case 8:
            return 9;
        case 9:
            return -3;
        case 10:
            return 5;
        case 11:
            return -7;
        case 12:
            return 9;
        case 13:
            return 5;
        case 14:
            return 7;
        case 15:
            return 8;
        case 16:
            return 6;
        default:
            return 0;
        }
    }

// The hit dice num cells (the para-elemental 8, 12, or 16 first-number 8 read
// - the MM1 earth elemental precedent; the phantom Nil and the pseudo-undead
// See below read 0; the planetar flat-hp 144 read: hitDiceNum 0, the R809
// obliviax bat precedent)
inline int mm2pPStatHd(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 4;
        case 8:
            return 0;
        case 9:
            return 20;
        case 10:
            return 4;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 11;
        case 14:
            return 8;
        case 15:
            return 9;
        case 16:
            return 4;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the pyrolisk 4+3 the capture 43 OCR artifact
// settle; the pudding dun 8+1; the pedipalp large 1+1, huge 2+2, giant 4+4)
inline int mm2pPStatHdBonus(int b)
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
            return 1;
        case 6:
            return 2;
        case 7:
            return 4;
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
            return 1;
        case 15:
            return 0;
        case 16:
            return 3;
        default:
            return 0;
        }
    }

// The avgHp cells (the floor(3.5 x hd + bonus) formula: the para-elementals
// 28, the pech 14, the pedipalps 4, 9 and 18, the phoenix 70, the phycomid
// 14, the puddings 38, 29 and 31, the pyrolisk 17; the flat-hp planetar 144)
inline int mm2pPStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 28;
        case 1:
            return 28;
        case 2:
            return 28;
        case 3:
            return 28;
        case 4:
            return 14;
        case 5:
            return 4;
        case 6:
            return 9;
        case 7:
            return 18;
        case 8:
            return 0;
        case 9:
            return 70;
        case 10:
            return 14;
        case 11:
            return 144;
        case 12:
            return 0;
        case 13:
            return 38;
        case 14:
            return 29;
        case 15:
            return 31;
        case 16:
            return 17;
        default:
            return 0;
        }
    }

// The attack cells (the loader semantics: the smoke Special floor at 1, the
// ooze 1 constrict read 1, the phoenix 1 or 2 max read 2, the phantom Nil and
// the pseudo-undead See below floor at 1)
inline int mm2pPStatAttacks(int b)
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
            return 3;
        case 7:
            return 3;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        default:
            return 0;
        }
    }

// The xp base cells (the phantom Nil/nil block reads 0; the pseudo-undead
// Treat as human fighters block reads 0; the pudding brown VIII/1600 the
// transcription VII variance kept verbatim per print)
inline int mm2pPStatXp(int b)
    {
        switch (b) {
        case 0:
            return 2850;
        case 1:
            return 2850;
        case 2:
            return 2850;
        case 3:
            return 2850;
        case 4:
            return 240;
        case 5:
            return 20;
        case 6:
            return 50;
        case 7:
            return 170;
        case 8:
            return 0;
        case 9:
            return 8600;
        case 10:
            return 280;
        case 11:
            return 60000;
        case 12:
            return 0;
        case 13:
            return 1600;
        case 14:
            return 1000;
        case 15:
            return 1200;
        case 16:
            return 240;
        default:
            return 0;
        }
    }

// The xp per hit point cells (the phantom Nil reads 0)
inline int mm2pPStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 15;
        case 2:
            return 15;
        case 3:
            return 15;
        case 4:
            return 4;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 5;
        case 8:
            return 0;
        case 9:
            return 30;
        case 10:
            return 5;
        case 11:
            return 35;
        case 12:
            return 0;
        case 13:
            return 16;
        case 14:
            return 12;
        case 15:
            return 12;
        case 16:
            return 5;
        default:
            return 0;
        }
    }

// The in-lair percentage cells (the para-elemental and pudding Nil cells read
// 0; the pech 05; the pseudo-undead 50)
inline int mm2pPStatLairPct(int b)
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
            return 5;
        case 5:
            return 5;
        case 6:
            return 10;
        case 7:
            return 20;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 80;
        case 11:
            return 0;
        case 12:
            return 50;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 30;
        default:
            return 0;
        }
    }

// The move cells (the first-number ground move reads: the para ooze 36, the
// phoenix 6, the planetar 15; the pseudo-undead See below reads 0)
inline int mm2pPStatMove(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 36;
        case 4:
            return 9;
        case 5:
            return 12;
        case 6:
            return 9;
        case 7:
            return 6;
        case 8:
            return 9;
        case 9:
            return 6;
        case 10:
            return 3;
        case 11:
            return 15;
        case 12:
            return 0;
        case 13:
            return 6;
        case 14:
            return 12;
        case 15:
            return 9;
        case 16:
            return 6;
        default:
            return 0;
        }
    }

// The magic resistance cells (every Standard and Standard for all reads 0;
// the pech 25, the phoenix 50, the planetar 75)
inline int mm2pPStatMr(int b)
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
            return 25;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 50;
        case 10:
            return 0;
        case 11:
            return 75;
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
        default:
            return 0;
        }
    }

}   // namespace rules
