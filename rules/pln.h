// =========================================================================================
// Adnd1 - rules/pln.h
// Appendix 1: the known planes of existence - the D&DG walk round nineteen,
// print pp. 128-133: the inner planes (the Prime Material, Positive,
// Negative, four Elemental, four Para-Elemental), the Ethereal, Shadow and
// Astral planes, the seventeen Outer Planes with their alignment bands, the
// ethereal and astral travel-and-combat rules, the Ether Cyclone and the
// psychic wind, the silver-cord doctrine, the two encounter tables (31 and 24
// rows), the two random plane-determination tables, and the character
// subtable level bands. FIG. 4 and FIG. 5 of print p. 131 remain the open
// pixel-work box.
// census 789 -> 790.
//
// primary ink: the extract/ddg tesseract pass (pNNN_full.txt + pNNN_tsv.tsv,
// print = pdf - 1, pages 129-134; the second printing) with the tsv x-y
// geometry as the fold-swap, dropped-glyph and band arbiter - the psm-4 fold
// garbled the psychic wind 13-16 row (Blocwozr;tfefr;:ourse), the inner
// random-table bands (8.9, 1011, the N of N-hegative) and the BARDT footnote
// glyph, all adjudicated by geometry plus the collation voice; the collation
// voice: the 1eonline L&L x1.htm appendix transcription. The adjudications:
// the ethereal elemental-earth ] glyph = 1 (the w6 token at the numbers
// column x-position), the astral Titan lesser 93-97 pinned by the print over
// the L&L 92-97 typo, the astral-only numbers read from the L&L voice (the
// tesseract dropped the single-number tokens), the Tifan, major garble =
// Titan, major, the inner random Negative band 5-7 adjudicated by band
// arithmetic (the 1-20 tiling), and the character subtable bard footnote (the
// BARDT print cell is the footnote glyph, the 91h is 9th).
//
namespace rules {

// ---- the planes doctrine ----

// the known planes round: the D&DG walk round nineteen
inline int plnRound()
    { return 867; }

// the section opens on print p. 128 (the inner planes)
inline int plnPrintStart()
    { return 128; }

// the section closes on print p. 133 (the random determination tables)
inline int plnPrintEnd()
    { return 133; }

// there exists an infinite number of parallel universes and planes of
// existence in the fantastic multiverse of ADVANCED DUNGEONS AND DRAGONS
inline bool plnPluralUniverses()
    { return true; }

// the charts and explanations show only the various planes tied to that of
// normal existence
inline bool plnOnlyNormalTied()
    { return true; }

// the parallel universes are not shown, and their existence might or might
// not be actual
inline bool plnParallelsNotShown()
    { return true; }

// all of these worlds co-exist, but how real each is depends entirely on the
// development of each campaign referee
inline bool plnRealityRefereeDependent()
    { return true; }

// the Prime Material Plane (or Physical Plane) is at the center of the Inner
// Planes
inline bool plnPmpCenter()
    { return true; }

// it houses the universe and all of its parallels
inline bool plnPmpHousesUniverse()
    { return true; }

// it is the plane of Terra, and your campaign, in all likelihood
inline bool plnPmpPlaneOfTerra()
    { return true; }

// the Prime Material is bounded or permeated by all of the Inner Planes and
// the Astral Plane
inline bool plnPmpBoundedByInner()
    { return true; }

// the Prime Material Plane is made up of the four elements plus positive and
// negative energy
inline bool plnPmpFourElements()
    { return true; }

// the Positive Material Plane is a place of energy and light, the source of
// much that is vital and active, the power supply for good
inline bool plnPosEnergyLight()
    { return true; }

// any creature from the Prime Material that tried to enter the Positive
// Material Plane (e.g. from the Ethereal Plane) would probably be instantly
// consumed by the powerful energies there
inline bool plnPosConsumePrime()
    { return true; }

// the Negative Material Plane is a place of anti-matter and negative force,
// the source of power for undead, the energy area from which evil grows
inline bool plnNegAntiMatter()
    { return true; }

// no one is certain what types of creature may exist on the Negative (or
// Positive) Material Plane
inline bool plnNegUncertainCreatures()
    { return true; }

// any creature from the Prime Material Plane would probably be completely
// drained of all life and energy
inline bool plnNegDrainPrime()
    { return true; }

// the planes of Air, Earth, Fire and Water surround the Prime Material Plane
inline bool plnEleSurroundPmp()
    { return true; }

// there are an infinite number of parallel Prime Material Planes, each
// bounded by the Elemental Planes, so the Elemental Planes are themselves
// infinite, in effect
inline bool plnEleInfiniteEffect()
    { return true; }

// do not be fooled by the apparent sizes of the planes represented in Fig. 1
inline bool plnEleApparentSizes()
    { return true; }

// it is possible to actually physically move from one Elemental Plane to
// another by moving through the Para-Elemental Planes
inline bool plnEleMoveViaPara()
    { return true; }

// the Elemental Planes are the homes of many different kinds of elemental
// creatures, and some of them have the ability to travel to the Prime
// Material Plane
inline bool plnEleHomesOfCreatures()
    { return true; }

// there is probably more traffic between the Prime Material and the Elemental
// planes than between any others
inline bool plnEleTrafficHeaviest()
    { return true; }

// the elemental traffic is usually either direct travel (through gates or
// summoning) or by way of the Ethereal Plane
inline bool plnEleTravelGatesOrEthereal()
    { return true; }

// nexial points in distant out-of-the-way places lead directly to the
// Elemental Planes: the deepest ocean leads to the Plane of Water
inline bool plnNexialDeepestOcean()
    { return true; }

// high in the atmosphere leads to the Plane of Air
inline bool plnNexialHighAtmosphere()
    { return true; }

// far underground leads to the Plane of Earth
inline bool plnNexialFarUnderground()
    { return true; }

// in an active volcano leads to the Plane of Fire
inline bool plnNexialActiveVolcano()
    { return true; }

// temporary nexial points may also be established occasionally, such as an
// opening to the Elemental Plane of Fire in the middle of a raging forest
// fire
inline bool plnNexialTemporary()
    { return true; }

// where the Elemental Planes meet are the lesser Para-Elemental Planes
inline bool plnParaAtConjunctions()
    { return true; }

// these planes are home to many para-elementals, and they can be reached in
// the same manners the Elemental Planes can be reached
inline bool plnParaHomes()
    { return true; }

// the Ethereal Plane surrounds, touches and permeates all of the Inner Planes
// and the endless parallel worlds of the universe without being a part of
// them
inline bool plnEthSurroundsAll()
    { return true; }

// the Ethereal Plane is basically insubstantial, and few real creatures
// actually live there
inline bool plnEthInsubstantial()
    { return true; }

// there are rumors of floating islands of solid ether, populated by exiles,
// which drift about the Ethereal Plane
inline bool plnEthFloatingIslands()
    { return true; }

// to creatures on the Ethereal Plane, objects on the Prime Material Plane (or
// any of the Inner Planes) appear as incorporeal phantoms
inline bool plnEthPhantoms()
    { return true; }

// ethereal creatures may pass through these phantoms with no difficulty
inline bool plnEthPassNoDifficulty()
    { return true; }

// a person being passed through might experience a chill down the spine
inline bool plnEthChillSpine()
    { return true; }

// ethereal beings or things are real to each other
inline bool plnEthRealToEachOther()
    { return true; }

// the Ethereal Plane does not extend to the Outer Planes, so it is not
// possible for creatures on those planes to go ethereal
inline bool plnEthNotToOuter()
    { return true; }

// the Plane of Shadow co-exists with the Prime Material Plane
inline bool plnShadCoExists()
    { return true; }

// it is a result of the interaction of that plane and the Positive and
// Negative Material Planes
inline bool plnShadInteraction()
    { return true; }

// the Negative plane provides the darkness, and the Positive plane the light;
// these meet at the Prime Material Plane, which casts the shadow
inline bool plnShadNegDarkPosLight()
    { return true; }

// the Plane of Shadow is a place of distorted and mutable shadow-creatures,
// of white, black and all shades of gray
inline bool plnShadMutableCreatures()
    { return true; }

// the Astral Plane radiates from the Prime Material to a non-space where
// endless vortices spiral to the parallel Prime Material Planes, and to the
// Outer Planes as well
inline bool plnAstRadiatesNonSpace()
    { return true; }

// this plane can be used to travel to distant worlds, to parallel planes, or
// to the Outer Planes themselves
inline bool plnAstTravelUses()
    { return true; }

// the Astral Plane touches only the upper layer of each of the Outer Planes,
// and of the Inner Planes it touches only the Prime Material (see Fig. 3)
inline bool plnAstTouchesUpperOnly()
    { return true; }

// FIG. 1 THE INNER PLANES: the Positive Material above, the Prime Material
// Plane at center within the Elemental band, the Negative Material below, the
// Ethereal Plane outermost
inline bool plnFig1Inner()
    { return true; }

// FIG. 2 THE ELEMENTAL PLANES: one way of visualizing the Elemental Planes
// relationship to each other
inline bool plnFig2Elemental()
    { return true; }

// FIG. 3 THE OUTER PLANES: the Outer Planes contacting each other at their
// topmost layers, the Astral Plane between them and the Inner Planes
inline bool plnFig3Outer()
    { return true; }

// FIG. 4 and FIG. 5 (print p. 131) - the character alignment graph and the
// planes-of-alignment figures, the open pixel-work box of the gap report, not
// pinned in this round
inline bool plnFig45PixelWork()
    { return true; }

// ---- the seventeen outer planes ----

// there are nine basic alignments, and nine planes which correspond to those
// alignments
inline int plnOutNineAlignments()
    { return 9; }

// there are also eight other planes between the nine which represent
// borderline alignments
inline int plnOutBorderlineCount()
    { return 8; }

// the seventeen Outer Planes in total
inline int plnOutSeventeenCount()
    { return 17; }

// the 666 layers of the Abyss
inline int plnAbyssLayers()
    { return 666; }

// the Outer Planes are the homes of the deities and the source of alignment
// (religious/philosophical/ethical ideals)
inline bool plnOutHomesOfDeities()
    { return true; }

// there is an exact correspondence between alignment and the Outer Planes;
// the alignment positions on the Character Alignment Graph match up exactly
// with the Outer Planes of identical alignment
inline bool plnOutExactCorrespondence()
    { return true; }

// alignment is a matter of degree rather than absolute definition
inline bool plnOutDegreeNotAbsolute()
    { return true; }

// a lawful evil character who tended towards neutral evil would probably end
// up in Gehenna rather than Hades or the Nine Hells
inline bool plnOutLeTendsGehenna()
    { return true; }

// the seventeen Outer Planes contact each other at their topmost layers
inline bool plnOutContactTopmost()
    { return true; }

// it is possible to move directly from the upper layer of one Outer Plane to
// an adjacent one (though it is not necessarily advisable or safe)
inline bool plnOutAdjacentMoves()
    { return true; }

// a being could go from the topmost layer of the Abyss to Pandemonium or
// Tarterus
inline bool plnOutAbyssMoves()
    { return true; }

// it is likewise possible to move from Hades to Tarterus, Gehenna, or the
// plane of Concordant Opposition
inline bool plnOutHadesMoves()
    { return true; }

// the Seven Heavens of absolute lawful good
inline bool plnSevenHeavensAbsLG()
    { return true; }

// the Twin Paradises of lawful/neutral good
inline bool plnTwinParadisesLNG()
    { return true; }

// the layers of Elysium of neutral good
inline bool plnElysiumLayersNG()
    { return true; }

// the Happy Hunting Grounds of chaotic/neutral good
inline bool plnHappyHuntingCGNG()
    { return true; }

// the layers of Olympus of absolute chaotic good
inline bool plnOlympusLayersACG()
    { return true; }

// the layers of Gladsheim (Asgard, Vanaheim, etc.) of neutral/good chaotics
inline bool plnGladsheimLayersNGC()
    { return true; }

// the layers of Limbo of neutral (absolute) chaos
inline bool plnLimboLayersChaos()
    { return true; }

// the layers of Pandemonium of neutral/evil chaotics
inline bool plnPandemoniumLayersNEC()
    { return true; }

// the 666 layers of the Abyss of absolute chaotic evil
inline bool plnAbyssAbsCE()
    { return true; }

// the layers of Tarterus of neutral/chaotic evil
inline bool plnTarterusLayersNCE()
    { return true; }

// Hades' Three Glooms of neutral (absolute) evil
inline bool plnHadesThreeGlooms()
    { return true; }

// the furnaces of Gehenna of neutral/lawful evil
inline bool plnGehennaFurnacesNLE()
    { return true; }

// the Nine Hells of absolute lawful evil
inline bool plnNineHellsAbsLE()
    { return true; }

// the nether layers of Acheron of neutral/evil law
inline bool plnAcheronNetherNEL()
    { return true; }

// Nirvana of neutral (absolute) law
inline bool plnNirvanaAbsLaw()
    { return true; }

// the plane of Arcadia of neutral/good law
inline bool plnArcadiaNGL()
    { return true; }

// the plane of Concordant Opposition of true neutrals
inline bool plnConcordantOfOpposition()
    { return true; }

// ---- the ethereal travel ----

// a non-cumulative 5 percent chance per plane crossed that a party will
// encounter the Ether Cyclone
inline int plnCycPct()
    { return 5; }

// the cyclone blows so as to move the party in a random direction at 120
// inches per round
inline int plnCycMoveRate()
    { return 120; }

// the lost-for-days band low (5-60 days, arriving at a different plane by
// random means when no longer lost)
inline int plnCycLostShortLo()
    { return 5; }

// the lost-for-days band high
inline int plnCycLostShortHi()
    { return 60; }

// the storm-cyclone lost band low (10-120 days)
inline int plnCycLostLongLo()
    { return 10; }

// the storm-cyclone lost band high
inline int plnCycLostLongHi()
    { return 120; }

// a character can achieve the ethereal state by magic spells, magic items,
// magical ointment (oil of etherealness) or psionic discipline
inline bool plnEthStateByMeans()
    { return true; }

// it is possible to move to or about any of the Inner Planes which the
// Ethereal Plane permeates
inline bool plnEthMoveInnerPlanes()
    { return true; }

// it is possible to move from plane to plane ethereally
inline bool plnEthPlaneToPlane()
    { return true; }

// to move on the Ethereal Plane, an entity has but to will movement for it to
// happen
inline bool plnEthWillMovement()
    { return true; }

// if concentration upon movement lapses, progress immediately halts
inline bool plnEthConcentrationHalts()
    { return true; }

// ethereal travel is tireless and rapid
inline bool plnEthTirelessRapid()
    { return true; }

// creatures in ethereal state need neither food, drink, rest nor sleep
inline bool plnEthNoNeeds()
    { return true; }

// ethereal creatures may move from plane to plane by moving from the shadow
// of one plane to the shadow of another, accomplished by concentrating upon
// moving to the desired destination
inline bool plnEthShadowToShadow()
    { return true; }

// this gets easier with practice, as the being marks out a mental trail
// through the ether
inline bool plnEthMentalTrail()
    { return true; }

// if the party is following an unfamiliar path, check for encounters three
// times total: at the beginning, midpoint, and at the end of the journey
inline bool plnEncUnfamiliarTriple()
    { return true; }

// evasion is possible only if the adventurers are able to move more quickly
// than the monster encountered
inline bool plnEncEvasionFaster()
    { return true; }

// evasion will occur only if the party is both following a familiar path
inline bool plnEncEvasionFamiliar()
    { return true; }

// and the least-intelligent member of the party has a higher intelligence
// score than the most-intelligent pursuer
inline bool plnEncEvasionIntelligence()
    { return true; }

// due to the fact that ethereal travel is a function of mental concentration
inline bool plnEncMentalFunction()
    { return true; }

// the twisting vortex of the Ether Cyclone is caused by fluctuations of the
// Inner Planes
inline bool plnCycInnerFluctuations()
    { return true; }

// the cyclone is only encountered on ethereal journeys between planes
inline bool plnCycOnlyBetweenPlanes()
    { return true; }

// if travelling is involved, the party is slowed so as to incur 1 additional
// encounter check
inline bool plnCycSlowAddCheck()
    { return true; }

// the cyclone blows to a plane different than that which the party is near or
// desires to travel to; the usual encounter checks must be made
inline bool plnCycDifferentPlane()
    { return true; }

// unless a saving throw versus spells is made, the party is blown to the
// Astral Plane; if a save is successful, the party will still arrive at a
// randomly determined plane touched by the ether
inline bool plnCycSaveSpells()
    { return true; }

// creatures on the Ethereal Plane are real to each other, and normal melee or
// spell casting is possible between ethereal beings
inline bool plnEthCombatReal()
    { return true; }

// it is also possible to combat creatures who exist or function partially on
// the Ethereal Plane
inline bool plnEthCombatPartial()
    { return true; }

// it is only in these instances that spells can be cast from the Ethereal to
// the Prime Material Plane, and then they will only affect the creature with
// ethereal connections
inline bool plnEthSpellsToPmp()
    { return true; }

// ethereal combat damage is actual damage
inline bool plnEthDamageActual()
    { return true; }

// the asterisked table creatures perceptions extend into the Astral and
// Ethereal Planes (as do their magical attack forms), but they do not
// actually travel therein; their possible appearance applies only when the
// encountering party is near to the Prime Material Plane
inline bool plnAstPerceptionNote()
    { return true; }

// ---- the astral travel ----

// the chance of a delayed or disrupted journey is a non-cumulative 5 percent
// per plane crossed (including alternate worlds of the Prime Material) or
// solar system travelled to (if journeying across the Prime Material)
inline int plnWindPct()
    { return 5; }

// the blown-off-course lost band low (2-20 days)
inline int plnWindLostShortLo()
    { return 2; }

// the blown-off-course lost band high
inline int plnWindLostShortHi()
    { return 20; }

// the storm-wind lost band low (4-40 days)
inline int plnWindLostLongLo()
    { return 4; }

// the storm-wind lost band high
inline int plnWindLostLongHi()
    { return 40; }

// astral travel is possible by various means including magic spells and
// psionic discipline
inline bool plnAstBySpellsPsionics()
    { return true; }

// the Astral Plane touches only the endless Prime Material Plane and the 17
// first layers of the Outer Planes
inline bool plnAstTouchesSeventeen()
    { return true; }

// the Astral Plane does not touch any of the Inner Planes other than the
// Prime Material Plane
inline bool plnAstNoInnerOther()
    { return true; }

// it is possible to move about, in, or to any of the Prime Material universes
// or to the first layers of the Outer Planes by means of astral travel (see
// the clerical astral spell for pertinent details)
inline bool plnAstClericalSpellRef()
    { return true; }

// movement through the Astral Plane is speedy
inline bool plnAstSpeedy()
    { return true; }

// while there the individual needs no food, drink, rest or even sleep
inline bool plnAstNoNeeds()
    { return true; }

// beings in an astral state move from place to place simply by concentrating
// upon moving to the desired destination
inline bool plnAstConcentrateMove()
    { return true; }

// as with ethereal travel, this gets easier with practice, as the astral
// traveller learns the way
inline bool plnAstLearnsTheWay()
    { return true; }

// astral evasion is handled as described under Ethereal Encounters
inline bool plnAstEvasionAsEthereal()
    { return true; }

// no one knows how or why the psychic wind blows, but all fear its effects
inline bool plnWindUnknown()
    { return true; }

// the wind slows travel only, incurring 1 additional check for random
// encounter
inline bool plnWindSlow()
    { return true; }

// the wind blows off course, and the party is lost for 2-20 days time, then
// must return to the starting place
inline bool plnWindLostShort()
    { return true; }

// the wind blows off course so that the party arrives at a different
// destination as determined by random method
inline bool plnWindDifferentDest()
    { return true; }

// the storm blows, and unless a saving throw versus magic is made, the silver
// cord is broken, and the party is killed
inline bool plnWindSaveMagic()
    { return true; }

// if a save is successful, the party is lost for 4-40 days and must return to
// the starting place thereafter
inline bool plnWindLostLong()
    { return true; }

// if astral projection does not involve a silver cord attachment, then the
// party concerned is both lost and arrives at a different destination when
// struck by a psychic storm wind
inline bool plnWindNoCord()
    { return true; }

// astral beings are real to each other, and can cast spells and melee
// normally
inline bool plnAstCombatReal()
    { return true; }

// astral travellers employing an astral spell or the psionic astral
// projection discipline do not carry their possessions with them into the
// Astral Plane (except for certain magic items that have a multi-planar
// existence, e.g. an amulet of the planes)
inline bool plnAstNoPossessions()
    { return true; }

// beings travelling astrally by these modes will therefore have to rely on
// their natural weaponry or spells without material components in any astral
// melee
inline bool plnAstNaturalWeaponry()
    { return true; }

// most creatures can do no more than destroy the astral body, causing the
// silver cord to return to the material body and preventing further astral
// travel for a period of time
inline bool plnAstDestroyBodyMost()
    { return true; }

// very powerful beings (gods, demigods, etc.) might be able to snap the
// silver cord, thus killing the astral and material bodies simultaneously
inline bool plnAstPowerfulSnap()
    { return true; }

// ---- the planar travel summary ----

// travel among the Inner Planes is usually done by means of the Ethereal
// Plane, as it permeates all of the Inner Planes
inline bool plnInnerViaEthereal()
    { return true; }

// it is not possible for creatures on the Outer Planes to go ethereal
inline bool plnOuterCantGoEthereal()
    { return true; }

// as with all planar travel, it is also possible to pass directly from one
// plane to another by means of gates, thereby avoiding ethereal travel
inline bool plnGatesAvoidEthereal()
    { return true; }

// a gate may be formed by a magic spell (such as a gate spell, or conjure
// elemental, which forms a direct opening between the planes)
inline bool plnGateBySpell()
    { return true; }

// or a magic item (e.g. an amulet of the planes, a well of many worlds, a
// cubic gate, or any of the various elemental-summoning devices)
inline bool plnGateByItems()
    { return true; }

// or divine intervention
inline bool plnGateByDivine()
    { return true; }

// there are also direct nexial points connecting the Prime Material and
// Elemental Planes
inline bool plnNexialDirect()
    { return true; }

// travel to and from the Outer Planes is usually by means of gates or via the
// Astral Plane
inline bool plnOuterViaGatesOrAstral()
    { return true; }

// the Astral Plane can only be entered from the Prime Material Plane or one
// of the first layers of the 17 Outer Planes
inline bool plnAstralEntryOnly()
    { return true; }

// if a being is gated to one of the Outer Planes, he comes complete with body
// and possessions, leaving no part of himself behind
inline bool plnGatedComplete()
    { return true; }

// if a being astrally projects and travels the Astral Plane to one of the
// Outer Planes, he leaves his material body behind on the Prime Material
// Plane, connected to his essence by a silver cord
inline bool plnProjectionLeavesBody()
    { return true; }

// if his material body is destroyed or the silver cord is snapped while he is
// in the Astral Plane, the being is permanently and irrevocably killed
inline bool plnSilverCordKilled()
    { return true; }

// if he moves to one of the Outer Planes from the Astral Plane, a body forms
// around him, but it is devoid of possessions
inline bool plnOuterBodyForms()
    { return true; }

// both bodies are now connected by the silver cord, and if either body is
// destroyed, the being will continue on in the remaining body
inline bool plnBothBodiesCorded()
    { return true; }

// returning instantly to the Prime Material if the Outer Plane body is killed
inline bool plnOuterKilledReturnPmp()
    { return true; }

// if the silver cord is snapped on the Astral Plane, the unoccupied body dies
inline bool plnCordSnapUnoccupiedDies()
    { return true; }

// ---- the character subtable ----

// the character subtable party size low (1-6)
inline int plnSubPartyLo()
    { return 1; }

// the character subtable party size high
inline int plnSubPartyHi()
    { return 6; }

// the cleric level low (9th-18th)
inline int plnSubClrLo()
    { return 9; }

// the cleric level high
inline int plnSubClrHi()
    { return 18; }

// the druid level low (7th-14th)
inline int plnSubDrdLo()
    { return 7; }

// the druid level high
inline int plnSubDrdHi()
    { return 14; }

// the fighter level low (8th-15th)
inline int plnSubFtrLo()
    { return 8; }

// the fighter level high
inline int plnSubFtrHi()
    { return 15; }

// the paladin level low (7th-16th)
inline int plnSubPalLo()
    { return 7; }

// the paladin level high
inline int plnSubPalHi()
    { return 16; }

// the ranger level low (7th-16th)
inline int plnSubRngLo()
    { return 7; }

// the ranger level high
inline int plnSubRngHi()
    { return 16; }

// the magic-user level low (11th-20th)
inline int plnSubMuLo()
    { return 11; }

// the magic-user level high
inline int plnSubMuHi()
    { return 20; }

// the illusionist level low (10th-17th)
inline int plnSubIllLo()
    { return 10; }

// the illusionist level high
inline int plnSubIllHi()
    { return 17; }

// the thief level low (9th-16th)
inline int plnSubThfLo()
    { return 9; }

// the thief level high
inline int plnSubThfHi()
    { return 16; }

// the assassin level low (10th-15th)
inline int plnSubAssLo()
    { return 10; }

// the assassin level high
inline int plnSubAssHi()
    { return 15; }

// the monk level low (8th-17th)
inline int plnSubMnkLo()
    { return 8; }

// the monk level high
inline int plnSubMnkHi()
    { return 17; }

// the bard level low (11th-18th)
inline int plnSubBrdLo()
    { return 11; }

// the bard level high
inline int plnSubBrdHi()
    { return 18; }

// the bard footnote fighter ability low (7th or 8th)
inline int plnSubBardFighterLo()
    { return 7; }

// the bard footnote fighter ability high
inline int plnSubBardFighterHi()
    { return 8; }

// the bard footnote thief ability low (6th to 9th)
inline int plnSubBardThiefLo()
    { return 6; }

// the bard footnote thief ability high
inline int plnSubBardThiefHi()
    { return 9; }

// the bard footnote thief level die (d4+5)
inline int plnSubBardThiefDie()
    { return 4; }

// the bard footnote thief level bonus
inline int plnSubBardThiefBonus()
    { return 5; }

// no limits to the number of characters of one class apply
inline bool plnSubNoClassLimits()
    { return true; }

// there will always be 1 cleric
inline bool plnSubAlwaysCleric()
    { return true; }

// if there are 2 or more in the party, there will also be a minimum of 1
// magic-user
inline bool plnSubMinMagicUser()
    { return true; }

// the BARD line carries the footnote: 7th or 8th level fighter ability, 6th
// to 9th level (d4+5) thief ability (the printed BARDT and 91h cells are the
// footnote-glyph and 9th garbles)
inline bool plnSubBardFootnote()
    { return true; }

// ---- the ethereal encounter grid ----

// The shared creature-roster ordinals (39 labels; the astral-only demons,
// devils, night hag and rakshasa follow the ethereal roster; the labels ride
// the data file)
inline int plnEtcOrd(int b)
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
        default:
            return 0;
        }
    }

// The percentile band lows (01-04 aerial servant through 98-00 xorn)
inline int plnEtcLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 9;
        case 3:
            return 12;
        case 4:
            return 17;
        case 5:
            return 24;
        case 6:
            return 25;
        case 7:
            return 26;
        case 8:
            return 28;
        case 9:
            return 33;
        case 10:
            return 35;
        case 11:
            return 37;
        case 12:
            return 38;
        case 13:
            return 43;
        case 14:
            return 45;
        case 15:
            return 47;
        case 16:
            return 52;
        case 17:
            return 54;
        case 18:
            return 57;
        case 19:
            return 62;
        case 20:
            return 69;
        case 21:
            return 71;
        case 22:
            return 73;
        case 23:
            return 75;
        case 24:
            return 78;
        case 25:
            return 82;
        case 26:
            return 89;
        case 27:
            return 90;
        case 28:
            return 93;
        case 29:
            return 95;
        case 30:
            return 98;
        default:
            return 0;
        }
    }

// The percentile band highs (the printed 00 = 100, the R863 encounter-grid
// convention)
inline int plnEtcHigh(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 8;
        case 2:
            return 11;
        case 3:
            return 16;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 25;
        case 7:
            return 27;
        case 8:
            return 32;
        case 9:
            return 34;
        case 10:
            return 36;
        case 11:
            return 37;
        case 12:
            return 42;
        case 13:
            return 44;
        case 14:
            return 46;
        case 15:
            return 51;
        case 16:
            return 53;
        case 17:
            return 56;
        case 18:
            return 61;
        case 19:
            return 68;
        case 20:
            return 70;
        case 21:
            return 72;
        case 22:
            return 74;
        case 23:
            return 77;
        case 24:
            return 81;
        case 25:
            return 88;
        case 26:
            return 89;
        case 27:
            return 92;
        case 28:
            return 94;
        case 29:
            return 97;
        case 30:
            return 100;
        default:
            return 0;
        }
    }

// The numbers-encountered lows (0 = the human traveller character-subtable
// row)
inline int plnEtcNumLo(int b)
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
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 2;
        case 23:
            return 1;
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
            return 2;
        case 30:
            return 3;
        default:
            return 0;
        }
    }

// The numbers-encountered highs (the ethereal elemental, earth ] print garble
// adjudicated 1 by the geometry and the L&L voice)
inline int plnEtcNumHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 3;
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
            return 2;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 8;
        case 20:
            return 2;
        case 21:
            return 4;
        case 22:
            return 5;
        case 23:
            return 1;
        case 24:
            return 6;
        case 25:
            return 3;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 5;
        case 30:
            return 6;
        default:
            return 0;
        }
    }

// The flag cells (1 = the asterisked perceptions-extend creatures - basilisk,
// cockatrice, gorgon, medusa; 2 = the human traveller character subtable row)
inline int plnEtcFlag(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
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
            return 1;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
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
        default:
            return 0;
        }
    }

// ---- the astral encounter grid ----

// The shared creature-roster ordinals (the demons 31-33, the devils 34-36,
// the night hag 37 and the rakshasa 38 are the astral-only entries)
inline int plnAtcOrd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 31;
        case 4:
            return 32;
        case 5:
            return 33;
        case 6:
            return 34;
        case 7:
            return 35;
        case 8:
            return 36;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 13;
        case 12:
            return 15;
        case 13:
            return 16;
        case 14:
            return 17;
        case 15:
            return 18;
        case 16:
            return 20;
        case 17:
            return 37;
        case 18:
            return 21;
        case 19:
            return 38;
        case 20:
            return 23;
        case 21:
            return 26;
        case 22:
            return 27;
        case 23:
            return 28;
        default:
            return 0;
        }
    }

// The percentile band lows (01-04 aerial servant through 98-00 titan major)
inline int plnAtcLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 11;
        case 3:
            return 14;
        case 4:
            return 17;
        case 5:
            return 23;
        case 6:
            return 24;
        case 7:
            return 25;
        case 8:
            return 29;
        case 9:
            return 38;
        case 10:
            return 39;
        case 11:
            return 40;
        case 12:
            return 42;
        case 13:
            return 47;
        case 14:
            return 50;
        case 15:
            return 56;
        case 16:
            return 62;
        case 17:
            return 64;
        case 18:
            return 72;
        case 19:
            return 75;
        case 20:
            return 80;
        case 21:
            return 92;
        case 22:
            return 93;
        case 23:
            return 98;
        default:
            return 0;
        }
    }

// The percentile band highs (the printed 00 = 100)
inline int plnAtcHigh(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 10;
        case 2:
            return 13;
        case 3:
            return 16;
        case 4:
            return 22;
        case 5:
            return 23;
        case 6:
            return 24;
        case 7:
            return 28;
        case 8:
            return 37;
        case 9:
            return 38;
        case 10:
            return 39;
        case 11:
            return 41;
        case 12:
            return 46;
        case 13:
            return 49;
        case 14:
            return 55;
        case 15:
            return 61;
        case 16:
            return 63;
        case 17:
            return 71;
        case 18:
            return 74;
        case 19:
            return 79;
        case 20:
            return 91;
        case 21:
            return 92;
        case 22:
            return 97;
        case 23:
            return 100;
        default:
            return 0;
        }
    }

// The numbers-encountered lows (0 = the human traveller character-subtable
// row)
inline int plnAtcNumLo(int b)
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
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        default:
            return 0;
        }
    }

// The numbers-encountered highs (the single-number rows read 1 by the L&L
// voice - the tesseract dropped the tokens; TITAN LESSER 93-97 pinned by the
// print over the L&L 92-97 typo)
inline int plnAtcNumHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 3;
        case 20:
            return 5;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        default:
            return 0;
        }
    }

// The flag cells (1 = the asterisked creatures; 2 = the human traveller
// character subtable row)
inline int plnAtcFlag(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
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
            return 1;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 1;
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
        default:
            return 0;
        }
    }

// ---- the outer planes grid ----

// The print list positions 1-17 (Seven Heavens through Concordant Opposition,
// the print p. 129 order)
inline int plnOutPos(int b)
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
            return 11;
        case 11:
            return 12;
        case 12:
            return 13;
        case 13:
            return 14;
        case 14:
            return 15;
        case 15:
            return 16;
        case 16:
            return 17;
        default:
            return 0;
        }
    }

// The layers-word flags (Elysium, Olympus, Gladsheim, Limbo, Pandemonium, the
// Abyss, Tarterus, Acheron)
inline int plnOutLayers(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
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
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
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

// The descriptor cells (0 none, 1 the 666 layers of the Abyss, 2 the Three
// Glooms of Hades, 3 the furnaces of Gehenna, 4 the nether layers of Acheron)
inline int plnOutDesc(int b)
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
            return 0;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 0;
        case 13:
            return 4;
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

// ---- the cyclone grid ----

// The cyclone dice band lows (1-10, 11-15, 16-18, 19-20)
inline int plnCycLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 16;
        case 3:
            return 19;
        default:
            return 0;
        }
    }

// The cyclone dice band highs
inline int plnCycHigh(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 18;
        case 3:
            return 20;
        default:
            return 0;
        }
    }

// The cyclone effect codes (1 random direction at 120 per round plus 1 check,
// 2 blown to a different plane plus the usual checks, 3 lost 5-60 days then a
// different plane, 4 lost 10-120 days plus the save-versus-spells-or-Astral
// rule)
inline int plnCycEffect(int b)
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
            return 0;
        }
    }

// ---- the wind grid ----

// The wind dice band lows (1-12, 13-16, 17-19, 20)
inline int plnWndLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 13;
        case 2:
            return 17;
        case 3:
            return 20;
        default:
            return 0;
        }
    }

// The wind dice band highs
inline int plnWndHigh(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 16;
        case 2:
            return 19;
        case 3:
            return 20;
        default:
            return 0;
        }
    }

// The wind effect codes (1 slowed plus 1 check, 2 blown off course and lost
// 2-20 days then return, 3 a different destination, 4 the save-versus-magic
// silver-cord rule and lost 4-40 days; the 13-16 Blocwozr;tfefr;:ourse print
// garble adjudicated blows-off-course by the L&L voice)
inline int plnWndEffect(int b)
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
            return 0;
        }
    }

// ---- the inner random grid ----

// The inner random d20 band lows (the 8.9 and 1011 fold garbles adjudicated
// 8-9 and 10-11; the Negative row band 5-7 adjudicated by band arithmetic -
// the printed band glyph garbled to the N of N-hegative)
inline int plnIrtLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 8;
        case 5:
            return 10;
        case 6:
            return 12;
        case 7:
            return 14;
        case 8:
            return 15;
        case 9:
            return 16;
        case 10:
            return 17;
        case 11:
            return 18;
        case 12:
            return 20;
        default:
            return 0;
        }
    }

// The inner random d20 band highs
inline int plnIrtHigh(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 7;
        case 4:
            return 9;
        case 5:
            return 11;
        case 6:
            return 13;
        case 7:
            return 14;
        case 8:
            return 15;
        case 9:
            return 16;
        case 10:
            return 17;
        case 11:
            return 19;
        case 12:
            return 20;
        default:
            return 0;
        }
    }

// The inner plane codes (0 Prime Material, 1 alternate world, 2 Positive, 3
// Negative, 4 Earth, 5 Fire, 6 Water, 7 Dust, 8 Heat, 9 Ice, 10 Vapor, 11
// Ethereal, 12 Shadow)
inline int plnIrtPlane(int b)
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
        default:
            return 0;
        }
    }

// ---- the outer random grid ----

// The outer random d20 band lows (Astral 1-3 through Concordant Opposition
// 20)
inline int plnRnoLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 11;
        case 9:
            return 12;
        case 10:
            return 13;
        case 11:
            return 14;
        case 12:
            return 15;
        case 13:
            return 16;
        case 14:
            return 17;
        case 15:
            return 18;
        case 16:
            return 19;
        case 17:
            return 20;
        default:
            return 0;
        }
    }

// The outer random d20 band highs
inline int plnRnoHigh(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 11;
        case 9:
            return 12;
        case 10:
            return 13;
        case 11:
            return 14;
        case 12:
            return 15;
        case 13:
            return 16;
        case 14:
            return 17;
        case 15:
            return 18;
        case 16:
            return 19;
        case 17:
            return 20;
        default:
            return 0;
        }
    }

// The outer plane codes (0 Astral, 1 Seven Heavens, 2 Twin Paradises, 3
// Elysium, 4 Happy Hunting Grounds, 5 Olympus, 6 Gladsheim, 7 Limbo, 8
// Pandemonium, 9 Abyss, 10 Tarterus, 11 Hades, 12 Gehenna, 13 Nine Hells, 14
// Acheron, 15 Nirvana, 16 Arcadia, 17 Concordant Opposition)
inline int plnRnoPlane(int b)
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
        default:
            return 0;
        }
    }

// ---- the para-elemental grid ----

// The para-elemental ordinals (0 Ice, 1 Dust, 2 Heat, 3 Vapor - the print p.
// 128 list order)
inline int plnPelOrd(int b)
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
        default:
            return 0;
        }
    }

// The first elemental codes (0 Air, 1 Earth, 2 Fire, 3 Water - the print list
// order)
inline int plnPelElemA(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// The second elemental codes (Ice where Air and Water meet, Dust at the
// conjunction of Air and Fire, Heat where Fire and Earth converge - lava,
// Vapor at the meeting of Earth and Water)
inline int plnPelElemB(int b)
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
        default:
            return 0;
        }
    }

// ---- the R867 census ----

// the eight grids
inline int plnTableCount()
    { return 8; }

// no chains this round
inline int plnChainCount()
    { return 0; }

// the ethereal encounter grid rows
inline int plnEtcRows()
    { return 31; }

// the astral encounter grid rows
inline int plnAtcRows()
    { return 24; }

// the seventeen outer planes grid rows
inline int plnOutRows()
    { return 17; }

// the ether cyclone grid rows
inline int plnCycRows()
    { return 4; }

// the psychic wind grid rows
inline int plnWndRows()
    { return 4; }

// the inner planes random grid rows
inline int plnIrtRows()
    { return 13; }

// the outer planes random grid rows
inline int plnRnoRows()
    { return 18; }

// the para-elemental conjunction grid rows
inline int plnPelRows()
    { return 4; }

// the shared encounter-creature roster (the first-appearance ordinals across
// the two tables)
inline int plnRosterCount()
    { return 39; }

// encounters occur on a 1 in 20, on both the Ethereal and the Astral
inline int plnEncounterChance()
    { return 20; }

// the first journey between two known points: three encounter checks
inline int plnChecksFirst()
    { return 3; }

// the second journey: two checks
inline int plnChecksSecond()
    { return 2; }

// all subsequent journeys: one check
inline int plnChecksSubsequent()
    { return 1; }

// the asterisked creatures in each table (basilisk, cockatrice, gorgon,
// medusa - the same four in both)
inline int plnAsteriskCount()
    { return 4; }

// the character subtable class rows (cleric through bard)
inline int plnSubtableRowCount()
    { return 11; }

// the Elemental Planes (Air, Earth, Fire, Water)
inline int plnElementalCount()
    { return 4; }

// the Para-Elemental Planes (Ice, Dust, Heat, Vapor)
inline int plnParaElementalCount()
    { return 4; }

// the four permanent nexial-point locations (ocean, atmosphere, underground,
// volcano)
inline int plnNexialCount()
    { return 4; }

// the seventeen-list planes printing the layers word (Elysium, Olympus,
// Gladsheim, Limbo, Pandemonium, the Abyss, Tarterus, Acheron)
inline int plnLayersWordCount()
    { return 8; }

// the descriptor-printing planes (the 666 layers, the Three Glooms, the
// furnaces, the nether layers)
inline int plnDescriptorCount()
    { return 4; }

// FIG. 1 through FIG. 5 (the two print-p.131 alignment figures are the open
// pixel-work box)
inline int plnFigCount()
    { return 5; }

}   // namespace rules
