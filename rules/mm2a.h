// =========================================================================================
// Adnd1 - rules/mm2a.h
// THE MM2 LETTER A - the ten printed A entries, the aspis forms and the azer
// king, promoted to the live registry
// census 719 -> 720.
//
// Round one of the Monster Manual II A-Z walk (the user Go call on the landed
// R796 opener). The capture is the Curtiss PDF upload (pp. 8-12, the full A
// section, clean text) cross-checked against the archive.org dual scans. The
// pin-time walk finds TEN entries where the opener structural walk saw seven
// candidates: aboleth, afanc, agathion, annis, ant lion, ascomoid, aspis,
// atomie, aurumvorax, azer. The aspis entry splits three ways (drone, larva,
// cow - the oni precedent) and the azer entry carries the Amaimon sub-entry
// def: thirteen .lua defs through the data_files extension, registry 478 ->
// 491. The stat blocks pin in the 12-row grid; the atomie xp reads the roman
// II (the OCR 11/40 misread settled); the annis and azer hit-dice ranges pin
// their low ends (the R792 range precedent); Amaimon rides the sentinel path
// for its unprinted xp and armor class, its combat lines reading the azer
// kind defaults. The battery census reads loaded 491, errors 0.
//
namespace rules {

// ---- the MM2 letter A round pins (the R797 census) ----

// The MM2 letter A round: the ten printed A entries of Monster Manual II (the
// user Go call on the landed R796 opener)
inline int mm2aRound()
    { return 797; }

// The pin-time A walk from the print: aboleth, afanc, agathion, annis, ant
// lion, ascomoid, aspis, atomie, aurumvorax, azer
inline int mm2aEntryCount()
    { return 10; }

// The promoted def census: the ten entries plus the aspis larva and cow forms
// and the Amaimon sub-entry
inline int mm2aDefCount()
    { return 13; }

// The A section first printed page (aboleth)
inline int mm2aFirstPage()
    { return 8; }

// The A section last printed page (azer and the Amaimon paragraph; baku opens
// B on the same page)
inline int mm2aLastPage()
    { return 12; }

// The live registry census before the round (the R793 reconciled count)
inline int mm2aRegistryBefore()
    { return 478; }

// The live registry census after the thirteen letter-A defs land
inline int mm2aRegistryAfter()
    { return 491; }

// The stat grid row census: the twelve stat-block forms in print order (aspis
// three rows; Amaimon rides consts)
inline int mm2aStatRows()
    { return 12; }

// The ant lion lair-items d20 row census: six bands tiling 1-20
inline int mm2aAntLionItemRows()
    { return 6; }

// The aspis larva xp ladder row census: the 2- through 5-HD rungs
inline int mm2aAspisLarvaRows()
    { return 4; }

// The azer bracket row census: the 2+1 through 5+4 hit-die brackets
inline int mm2aAzerBracketRows()
    { return 4; }

// The pin-time A walk from the print is authoritative: ten entries, the
// opener 7-candidate archive.org walk superseded (the R792 lesson)
inline bool mm2aLetterWalkFromPrint()
    { return true; }

// The one aspis print entry rides three form defs: drone, larva and cow (the
// oni multi-form precedent)
inline bool mm2aAspisRidesThreeDefs()
    { return true; }

// The Amaimon paragraph rides the azer print as its own def: the legendary
// king sub-entry
inline bool mm2aAmaimonRidesAzerEntry()
    { return true; }

// The atomie LEVEL/X.P. reads II/40 + 1/hp: the PDF OCR 11/40 is a
// roman-numeral misread, consistent with the 2-HD aspis larva rung and the
// azer 2+1 bracket
inline bool mm2aAtomieXpIsRomanII()
    { return true; }

// Amaimon prints no xp and no armor class: the def rides the xp-0 sentinel
// path (the marut precedent)
inline bool mm2aAmaimonStatsRideSentinels()
    { return true; }

// The mm2_print source joins the xp audit allowed-source list (the R792
// oa/wsg/mop precedent)
inline bool mm2aMm2PrintRidesXpAudit()
    { return true; }

// The thirteen defs land through the R791 data_files extension (the R794 git
// add)
inline bool mm2aDefsRideDataFiles()
    { return true; }

// The mm2a pin header stays the print-fidelity record (the promotion seam
// standing rule)
inline bool mm2aPinHeaderStaysPrintRecord()
    { return true; }

// ---- the aboleth pins (the R797 MM2 letter A) ----

// The 10-foot tentacle count (the four attacks)
inline int mm2aAbolethTentacles()
    { return 4; }

// The enslave attempts per day (a single creature each)
inline int mm2aAbolethEnslavesPerDay()
    { return 3; }

// The enslave range: up to 30 feet
inline int mm2aAbolethEnslaveRangeFt()
    { return 30; }

// The tentacle slime membrane change: 2-5 rounds
inline int mm2aAbolethMembraneMin()
    { return 2; }

// The tentacle slime membrane change: the high end
inline int mm2aAbolethMembraneMax()
    { return 5; }

// The in-water mucus cloud: 1 foot all around the body
inline int mm2aAbolethMucusRadiusFt()
    { return 1; }

// The inhaled-mucus suffocation window: 2-12 rounds
inline int mm2aAbolethSuffocateMin()
    { return 2; }

// The inhaled-mucus suffocation window: the high end
inline int mm2aAbolethSuffocateMax()
    { return 12; }

// The slave water-breathing duration: 1-3 hours (a potion of water breathing)
inline int mm2aAbolethSlaveWaterMin()
    { return 1; }

// The slave water-breathing duration: the high end
inline int mm2aAbolethSlaveWaterMax()
    { return 3; }

// The aboleth psionic ability score
inline int mm2aAbolethPsionicScore()
    { return 250; }

// The tentacle slime change: save vs. spells or the skin becomes a clear
// slimy membrane
inline bool mm2aAbolethMembraneSaveVsSpells()
    { return true; }

// A cure disease spell cast on the victim stops the change
inline bool mm2aAbolethCureDiseaseStops()
    { return true; }

// A cure serious wounds spell changes the membrane back to normal skin
inline bool mm2aAbolethCureSeriousReverses()
    { return true; }

// The illusions carry audible and visual components, only while concentrating
// and doing nothing else
inline bool mm2aAbolethIllusionsAudibleVisual()
    { return true; }

// The enslave works only against a single creature; the enslaved will not
// fight for the aboleth
inline bool mm2aAbolethEnslaveSingleTarget()
    { return true; }

// The charm breaks by remove curse or dispel magic spells or the death of the
// enslaving aboleth
inline bool mm2aAbolethEnslaveBreaksByRemoveCurse()
    { return true; }

// The mucus may be dissolved by soap or wine
inline bool mm2aAbolethMucusDissolvedBySoapOrWine()
    { return true; }

// ---- the afanc pins (the R797 MM2 letter A) ----

// The whirlpool circling start: 100 feet out
inline int mm2aAfancCircleStartFt()
    { return 100; }

// The circling close rate: 20 feet per round
inline int mm2aAfancCircleCloseFt()
    { return 20; }

// The circling closes to 40 feet
inline int mm2aAfancCircleInnerFt()
    { return 40; }

// The whirlpool creation time: 5-8 rounds
inline int mm2aAfancWhirlMinRounds()
    { return 5; }

// The whirlpool creation time: the high end
inline int mm2aAfancWhirlMaxRounds()
    { return 8; }

// The largest ship the whirlpool draws down (small to small-medium)
inline int mm2aAfancMaxShipFt()
    { return 60; }

// The dragged ship sinks 10 feet per round
inline int mm2aAfancDragFtPerRound()
    { return 10; }

// The circling top rate: 30 inches or more
inline int mm2aAfancTopSpeed()
    { return 30; }

// The dragged-prey submerge chance: 10 percent
inline int mm2aAfancSubmergePct()
    { return 10; }

// The rushed-and-capsized small craft: 30 feet or less
inline int mm2aAfancSmallCraftFt()
    { return 30; }

// The afanc avoids ships larger than small-medium
inline bool mm2aAfancAvoidsLargerShips()
    { return true; }

// Rafts, boats and similar small craft are rushed and capsized, the
// passengers consumed
inline bool mm2aAfancCapsizesSmallCraft()
    { return true; }

// ---- the agathion pins (the R797 MM2 letter A) ----

// The human form likelihood
inline int mm2aAgathionHumanFormPct()
    { return 60; }

// The beneficent creature form likelihood
inline int mm2aAgathionCreatureFormPct()
    { return 30; }

// The non-corporeal item-housed form likelihood
inline int mm2aAgathionItemFormPct()
    { return 10; }

// The human-form spell powers: a 7th-level cleric
inline int mm2aAgathionClericLevel()
    { return 7; }

// The agathion wisdom (bonus spells applicable)
inline int mm2aAgathionWisdom()
    { return 18; }

// The creature-form undead turning: a 14th-level cleric
inline int mm2aAgathionTurnLevel()
    { return 14; }

// The save-as level: 14th-level clerics regardless of form
inline int mm2aAgathionSaveLevel()
    { return 14; }

// The item-housed possessor affects undead as a 6th-level cleric
inline int mm2aAgathionItemTurnLevel()
    { return 6; }

// The slain agathion cannot return for 10-60 years
inline int mm2aAgathionSlainMinYears()
    { return 10; }

// The slain agathion regains its strength: the high end
inline int mm2aAgathionSlainMaxYears()
    { return 60; }

// The natural-form touch damage: 7-14 points of positive power
inline int mm2aAgathionTouchMin()
    { return 7; }

// The natural-form touch damage: the high end
inline int mm2aAgathionTouchMax()
    { return 14; }

// The agathion psionic ability score
inline int mm2aAgathionPsionicScore()
    { return 177; }

// They are struck only by +1 or better magic weapons, regardless of form
inline bool mm2aAgathionStruckOnlyByPlusOne()
    { return true; }

// They are immune to life-level draining
inline bool mm2aAgathionImmuneLevelDraining()
    { return true; }

// They are immune to death spells
inline bool mm2aAgathionImmuneDeathSpells()
    { return true; }

// They are immune to disintegration
inline bool mm2aAgathionImmuneDisintegration()
    { return true; }

// They are immune to energy from the Positive Material Plane
inline bool mm2aAgathionImmunePositiveEnergy()
    { return true; }

// They can become ethereal at will
inline bool mm2aAgathionEtherealAtWill()
    { return true; }

// They can travel astrally
inline bool mm2aAgathionAstralTravel()
    { return true; }

// The wisdom 18 makes bonus spells applicable
inline bool mm2aAgathionWisdomBonusSpells()
    { return true; }

// The item-housed agathion bestows its 1st-level cleric spell ability on the
// possessor and automatically detects evil
inline bool mm2aAgathionItemGrantsClericSpells()
    { return true; }

// ---- the annis pins (the R797 MM2 letter A) ----

// The annis strength: equal to a hill giant (19)
inline int mm2aAnnisStrength()
    { return 19; }

// The fog cloud and change self cast at 8th level
inline int mm2aAnnisCastLevel()
    { return 8; }

// Each power twice per day, 1 at a time, 1 per round
inline int mm2aAnnisUsesPerPowerDay()
    { return 2; }

// The edged-weapon damage adjustment vs. the iron-hard skin
inline int mm2aAnnisEdgedAdjust()
    { return -1; }

// The blunt-weapon damage adjustment (flails and morning stars are blunt)
inline int mm2aAnnisBluntAdjust()
    { return 1; }

// Three hits on one creature in the same round: the annis has automatically
// seized and holds the opponent fast
inline bool mm2aAnnisSeizesOnTripleHit()
    { return true; }

// Next round all annis attacks are automatic hits unless the opponent is
// stronger, the annis is slain, or the victim escapes magically
inline bool mm2aAnnisSeizedFoeAutoHit()
    { return true; }

// The iron-hard skin: treat the annis as clad in plate mail for weapons vs.
// armor adjustment
inline bool mm2aAnnisTreatedAsPlateMail()
    { return true; }

// Flails and morning stars count as blunt weapons
inline bool mm2aAnnisFlailMorningstarBlunt()
    { return true; }

// Normal infravision but superior hearing and sense of smell
inline bool mm2aAnnisSuperiorHearingSmell()
    { return true; }

// ---- the ant lion pins (the R797 MM2 letter A) ----

// The tapering pit diameter
inline int mm2aAntLionPitFt()
    { return 60; }

// The pit looks like a cave or lair entrance half the time
inline int mm2aAntLionLairLookPct()
    { return 50; }

// The per-round slip chance on the loose sides
inline int mm2aAntLionSlipPct()
    { return 50; }

// The locked-jaw automatic damage: 5-20 points per round after the hit
inline int mm2aAntLionAutoBiteMin()
    { return 5; }

// The locked-jaw automatic damage: the high end
inline int mm2aAntLionAutoBiteMax()
    { return 20; }

// The lair item chance: 30 percent for 1-4 items from previous kills
inline int mm2aAntLionItemChancePct()
    { return 30; }

// The lair item count: 1-4
inline int mm2aAntLionItemsMin()
    { return 1; }

// The lair item count: the high end
inline int mm2aAntLionItemsMax()
    { return 4; }

// The chance a lair item is magical
inline int mm2aAntLionMagicPct()
    { return 10; }

// A hit indicates the jaws have closed and will not release until it or the
// prey is dead
inline bool mm2aAntLionJawsLockOnHit()
    { return true; }

// Each round after the initial hit the ant lion inflicts damage automatically
inline bool mm2aAntLionAutoDamageUntilDeath()
    { return true; }

// Ant lions do not collect treasure; the lair items are from previous kills
inline bool mm2aAntLionLairItemsFromKills()
    { return true; }

// They devour 1 or more giant insects each day, so one can be encountered
// outside its pit
inline bool mm2aAntLionLeavesPitToFeed()
    { return true; }

// The d20 band low roll
inline int mm2aAntLionItemLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 7;
        case 2:
            return 11;
        case 3:
            return 14;
        case 4:
            return 18;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// The d20 band high roll
inline int mm2aAntLionItemHi(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 10;
        case 2:
            return 13;
        case 3:
            return 17;
        case 4:
            return 19;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// The band kind: 1 gp, 2 pp, 3 shield, 4 metal weapon, 5 jewelry, 6
// miscellaneous item (10 percent magical)
inline int mm2aAntLionItemKind(int b)
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
        default:
            return 0;
        }
    }

// ---- the ascomoid pins (the R797 MM2 letter A) ----

// The spore jet length (1 foot in diameter)
inline int mm2aAscomoidSporeRangeFt()
    { return 30; }

// The spore cloud diameter: 5-20 (variable)
inline int mm2aAscomoidCloudMin()
    { return 5; }

// The spore cloud diameter: the high end
inline int mm2aAscomoidCloudMax()
    { return 20; }

// The failed-save infection death: 1-4 rounds
inline int mm2aAscomoidDeathMin()
    { return 1; }

// The failed-save infection death: the high end
inline int mm2aAscomoidDeathMax()
    { return 4; }

// The successful-save blindness recovery: 1-4 rounds
inline int mm2aAscomoidRecoverMin()
    { return 1; }

// The successful-save blindness recovery: the high end
inline int mm2aAscomoidRecoverMax()
    { return 4; }

// Attacks on the blinded victims: at +4, no shield or dexterity bonuses
inline int mm2aAscomoidHelplessHitBonus()
    { return 4; }

// Magical attacks are saved against at +4
inline int mm2aAscomoidMagicSaveBonus()
    { return 4; }

// Magical attack damage: 50 percent of normal (cold at normal probabilities)
inline int mm2aAscomoidMagicDmgPct()
    { return 50; }

// Spears over 6 feet score double damage
inline int mm2aAscomoidPiercingMinFt()
    { return 6; }

// The rolling movement accelerates 3, 6, 9 then 12 per round and keeps it up
// for hours
inline bool mm2aAscomoidAcceleratingRoll()
    { return true; }

// Small and medium-sized opponents are knocked down and must rise the next
// round or remain prone
inline bool mm2aAscomoidKnocksDownSmallerFoes()
    { return true; }

// Piercing weapons over 6 feet long score double damage; shorter stabbing
// weapons damage as vs. a small opponent
inline bool mm2aAscomoidPiercingDoublesOverSixFeet()
    { return true; }

// Blunt weapons do not harm ascomoids
inline bool mm2aAscomoidBluntWeaponsHarmless()
    { return true; }

// Slashes and cuts from edged weapons cause only 1 point of damage
inline bool mm2aAscomoidEdgedOnePoint()
    { return true; }

// Cold-based attacks are at normal probabilities
inline bool mm2aAscomoidColdNormal()
    { return true; }

// All spells affecting the brain are useless unless specific to plants
inline bool mm2aAscomoidMindSpellsUseless()
    { return true; }

// ---- the aspis pins (the R797 MM2 letter A) ----

// The drone two-shield read: armor class 3(2)
inline int mm2aAspisDroneRearAC()
    { return 2; }

// The drones able to speak Common: 5 percent
inline int mm2aAspisDroneCommonPct()
    { return 5; }

// The cow acidic slime flesh burn: 1-8 points per round
inline int mm2aAspisCowSlimeMin()
    { return 1; }

// The cow acidic slime flesh burn: the high end
inline int mm2aAspisCowSlimeMax()
    { return 8; }

// The nest egg chambers: 1-3
inline int mm2aAspisEggChambersMin()
    { return 1; }

// The nest egg chambers: the high end
inline int mm2aAspisEggChambersMax()
    { return 3; }

// The nest granaries: 2-4
inline int mm2aAspisGranariesMin()
    { return 2; }

// The nest granaries: the high end
inline int mm2aAspisGranariesMax()
    { return 4; }

// The nest grub hatcheries: 1-6
inline int mm2aAspisHatcheriesMin()
    { return 1; }

// The nest grub hatcheries: the high end
inline int mm2aAspisHatcheriesMax()
    { return 6; }

// The larvae per hatchery: 1-10
inline int mm2aAspisLarvaePerHatcheryMin()
    { return 1; }

// The larvae per hatchery: the high end
inline int mm2aAspisLarvaePerHatcheryMax()
    { return 10; }

// The chance 10-100 giant ants share the nest
inline int mm2aAspisAntsChancePct()
    { return 10; }

// The giant ant cohabitants: 10-100
inline int mm2aAspisAntsMin()
    { return 10; }

// The giant ant cohabitants: the high end
inline int mm2aAspisAntsMax()
    { return 100; }

// The nest tunnel height (well-defended by traps and guards)
inline int mm2aAspisTunnelHeightFt()
    { return 4; }

// In combat the drone stands on its hind legs, wielding 2 weapons and 2
// shields with the other 4 legs
inline bool mm2aAspisDroneFourLegsTwoShields()
    { return true; }

// The drones are capable of using all weapons but bows
inline bool mm2aAspisDroneNoBows()
    { return true; }

// The drones are immune to electrical and cold attacks
inline bool mm2aAspisDroneImmuneElectricCold()
    { return true; }

// The drones take only half damage from fire-based attacks
inline bool mm2aAspisDroneHalfFire()
    { return true; }

// The larvae are blind and deaf but locate and identify creatures through
// vibrations and scent
inline bool mm2aAspisLarvaBlindDeafByVibration()
    { return true; }

// The larvae are immune to acid
inline bool mm2aAspisLarvaImmuneAcid()
    { return true; }

// The cow slime eats through metal or wood in 1 round
inline bool mm2aAspisCowSlimeEatsMetalWood()
    { return true; }

// Only 1 cow will be found in any nest
inline bool mm2aAspisOneCowPerNest()
    { return true; }

// The drones communicate by subtle scents and perfumes; they lack personal
// names
inline bool mm2aAspisDroneSpeaksByScent()
    { return true; }

// The larva hit-die rung (2 through 5)
inline int mm2aAspisLarvaHd(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        default:
            return 0;
        }
    }

// The rung base xp (II at 2-3 HD, III at 4-5)
inline int mm2aAspisLarvaXp(int b)
    {
        switch (b) {
        case 0:
            return 28;
        case 1:
            return 50;
        case 2:
            return 85;
        case 3:
            return 130;
        default:
            return 0;
        }
    }

// The rung xp per hit point
inline int mm2aAspisLarvaXpHp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        default:
            return 0;
        }
    }

// ---- the atomie pins (the R797 MM2 letter A) ----

// The atomie gain on initiative die rolls
inline int mm2aAtomieInitiativeBonus()
    { return 1; }

// The atomies attack as 3rd-level fighters
inline int mm2aAtomieFighterLevel()
    { return 3; }

// The spell-like powers at 5th-level ability
inline int mm2aAtomiePowerLevel()
    { return 5; }

// The atomie surprise likelihood
inline int mm2aAtomieSurprisePct()
    { return 90; }

// The atomie surprised likelihood
inline int mm2aAtomieSurprisedPct()
    { return 10; }

// The infravision and ultraviolet range (double normal)
inline int mm2aAtomieInfravisionFt()
    { return 120; }

// The chance of grig company
inline int mm2aAtomieGrigPct()
    { return 20; }

// The small crossbow likelihood (3-inch range)
inline int mm2aAtomieCrossbowPct()
    { return 20; }

// The small spear likelihood (double damage in diving or charging flight)
inline int mm2aAtomieSpearPct()
    { return 60; }

// The small sword likelihood (equal to a knife)
inline int mm2aAtomieSwordPct()
    { return 40; }

// The small crossbow range
inline int mm2aAtomieCrossbowRangeIn()
    { return 3; }

// The small crossbow damage: 1-3 points
inline int mm2aAtomieCrossbowDmgMin()
    { return 1; }

// The small crossbow damage: the high end
inline int mm2aAtomieCrossbowDmgMax()
    { return 3; }

// The small spear damage: 1-4 points thrust or thrown
inline int mm2aAtomieSpearDmgMin()
    { return 1; }

// The small spear damage: the high end
inline int mm2aAtomieSpearDmgMax()
    { return 4; }

// The small sword damage: 1-3 points
inline int mm2aAtomieSwordDmgMin()
    { return 1; }

// The small sword damage: the high end
inline int mm2aAtomieSwordDmgMax()
    { return 3; }

// The five powers usable at will, 1 at a time, 1 per round: blink,
// invisibility, pass plant, speak with animals, summon insects
inline bool mm2aAtomiePowersAtWillOnePerRound()
    { return true; }

// Their hearing is double human norm
inline bool mm2aAtomieHearingDoubleNorm()
    { return true; }

// Their own language is a dialect of Sprite; they also speak Pixie and a
// smattering of Common
inline bool mm2aAtomieSpeaksSpriteDialect()
    { return true; }

// The small spear damage doubles when used in diving or charging flight
inline bool mm2aAtomieWeaponsDoubleInDive()
    { return true; }

// They are sometimes found in company with grigs
inline bool mm2aAtomieGrigCompany()
    { return true; }

// ---- the aurumvorax pins (the R797 MM2 letter A) ----

// The initial bite: 2-8 points
inline int mm2aAurumvoraxBiteMin()
    { return 2; }

// The initial bite: the high end
inline int mm2aAurumvoraxBiteMax()
    { return 8; }

// The held bite: 8 points of automatic damage each succeeding round
inline int mm2aAurumvoraxHoldBite()
    { return 8; }

// The additional clawing attacks while holding on: 2-8
inline int mm2aAurumvoraxClawMin()
    { return 2; }

// The additional clawing attacks: the high end
inline int mm2aAurumvoraxClawMax()
    { return 8; }

// The claw damage: 1-6 points
inline int mm2aAurumvoraxClawDmgMin()
    { return 1; }

// The claw damage: the high end
inline int mm2aAurumvoraxClawDmgMax()
    { return 6; }

// The concealed-den surprise chance
inline int mm2aAurumvoraxSurprisePct()
    { return 50; }

// The dense flesh weighs over 500 pounds
inline int mm2aAurumvoraxWeightLbs()
    { return 500; }

// Once it bites successfully the aurumvorax holds on
inline bool mm2aAurumvoraxHoldsAfterBite()
    { return true; }

// The held opponent dexterity is negated for armor class computation
inline bool mm2aAurumvoraxDexNegatedWhenHeld()
    { return true; }

// Only death will unlock its jaws
inline bool mm2aAurumvoraxOnlyDeathUnlocks()
    { return true; }

// It takes only half damage from blunt weapons
inline bool mm2aAurumvoraxHalfDamageBlunt()
    { return true; }

// It is immune to damage from small, normal fires
inline bool mm2aAurumvoraxImmuneSmallFires()
    { return true; }

// Large, magical fires cause only half normal damage
inline bool mm2aAurumvoraxLargeMagicalFiresHalf()
    { return true; }

// Poisons and gases do not harm it at all
inline bool mm2aAurumvoraxImmunePoisonGas()
    { return true; }

// ---- the azer pins (the R797 MM2 letter A) ----

// The grasp damage to non-fire-immune creatures: 2-5 points
inline int mm2aAzerGraspMin()
    { return 2; }

// The grasp damage: the high end
inline int mm2aAzerGraspMax()
    { return 5; }

// The weapon heat damage bonus to such opponents
inline int mm2aAzerWeaponHeatBonus()
    { return 1; }

// Cold attacks inflict double normal damage
inline int mm2aAzerColdMultiplier()
    { return 2; }

// The survival floor: below 200 degrees F.
inline int mm2aAzerTempFloorF()
    { return 200; }

// They cannot survive there more than an hour or so
inline int mm2aAzerSurviveHours()
    { return 1; }

// Creatures not immune to fire take grasp damage from any azer
inline bool mm2aAzerHeatDamagesGrasp()
    { return true; }

// The heat of an azer weapon inflicts bonus damage to such opponents
inline bool mm2aAzerWeaponsInflictHeat()
    { return true; }

// Cold attacks inflict double normal damage against azer
inline bool mm2aAzerColdDoubleDamage()
    { return true; }

// The broad-bladed javelins inflict damage equal to a spear
inline bool mm2aAzerJavelinEqualsSpear()
    { return true; }

// The mallet-like weapons equal a footman mace in all respects
inline bool mm2aAzerMalletEqualsFootmanMace()
    { return true; }

// For clear purple or red gems they may agree to reasonable requests
inline bool mm2aAzerGemsBuyFavors()
    { return true; }

// Once given, the word of an azer is a solid bond
inline bool mm2aAzerWordIsBond()
    { return true; }

// The other powers of Amaimon and his nobles are currently unknown
inline bool mm2aAmaimonPowersUnknown()
    { return true; }

// The bracket hit dice
inline int mm2aAzerHd(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        default:
            return 0;
        }
    }

// The bracket hit-die bonus
inline int mm2aAzerHdBonus(int b)
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

// The bracket strength base (17 or 18)
inline int mm2aAzerStrBase(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        default:
            return 0;
        }
    }

// The percentile strength floor (0 = non-percentile)
inline int mm2aAzerStrLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 51;
        default:
            return 0;
        }
    }

// The percentile strength ceiling (0 = non-percentile)
inline int mm2aAzerStrHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 50;
        case 3:
            return 75;
        default:
            return 0;
        }
    }

// The bracket to-hit bonus
inline int mm2aAzerToHit(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        default:
            return 0;
        }
    }

// The bracket damage bonus
inline int mm2aAzerToDmg(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        default:
            return 0;
        }
    }

// The bracket encounter percent (90, 30, 20, 10 - the print conditional)
inline int mm2aAzerEncounterPct(int b)
    {
        switch (b) {
        case 0:
            return 90;
        case 1:
            return 30;
        case 2:
            return 20;
        case 3:
            return 10;
        default:
            return 0;
        }
    }

// The bracket base gem value in gold pieces
inline int mm2aAzerGemValue(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 50;
        case 2:
            return 100;
        case 3:
            return 500;
        default:
            return 0;
        }
    }

// The bracket LEVEL/X.P. base
inline int mm2aAzerXp(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 85;
        case 2:
            return 130;
        case 3:
            return 225;
        default:
            return 0;
        }
    }

// The bracket xp per hit point
inline int mm2aAzerXpHp(int b)
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
        default:
            return 0;
        }
    }

// ---- the amaimon pins (the R797 MM2 letter A) ----

// Amaimon the legendary king of the azer: 9+8 hit dice, the largest of all
// his kind
inline int mm2aAmaimonHdNum()
    { return 9; }

// The Amaimon hit-die bonus
inline int mm2aAmaimonHdBonus()
    { return 8; }

// The Amaimon average hit points (floor of 9 x 3.5 plus 8)
inline int mm2aAmaimonAvgHp()
    { return 39; }

// The Amaimon strength 18/00 hit bonus
inline int mm2aAmaimonHitBonus()
    { return 3; }

// The Amaimon strength 18/00 damage bonus
inline int mm2aAmaimonDmgBonus()
    { return 6; }

// The Amaimon percentile strength: 18/00
inline int mm2aAmaimonStrPct()
    { return 0; }

// Amaimon has 35 percent magic resistance
inline int mm2aAmaimonMR()
    { return 35; }

// The nobles: 7+6 hit dice, only slightly less superior
inline int mm2aAmaimonNobleHdNum()
    { return 7; }

// The noble hit-die bonus
inline int mm2aAmaimonNobleHdBonus()
    { return 6; }

// The noble strength 18/76-90 hit bonus
inline int mm2aAmaimonNobleHitBonus()
    { return 2; }

// The noble strength 18/76-90 damage bonus
inline int mm2aAmaimonNobleDmgBonus()
    { return 4; }

// The noble percentile strength floor
inline int mm2aAmaimonNobleStrLo()
    { return 76; }

// The noble percentile strength ceiling
inline int mm2aAmaimonNobleStrHi()
    { return 90; }

// The noble magic resistance: 25 percent
inline int mm2aAmaimonNobleMR()
    { return 25; }

// His nobles number from 8-32
inline int mm2aAmaimonNoblesMin()
    { return 8; }

// His nobles: the high end
inline int mm2aAmaimonNoblesMax()
    { return 32; }

// When 20 or more are encountered in their habitation
inline int mm2aAmaimonHabitationMin()
    { return 20; }

// There will be 2 of the largest normal size there also
inline int mm2aAmaimonLargestNormals()
    { return 2; }

// The non-combatant females and young: 40-70
inline int mm2aAmaimonFemalesMin()
    { return 40; }

// The non-combatant females and young: the high end
inline int mm2aAmaimonFemalesMax()
    { return 70; }

// ---- the MM2 letter A stat grid (the R797 wiring) ----

// The ARMOR CLASS cell (the drone 3(2) reads 3; the print strings ride the
// defs)
inline int mm2aStatAC(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 6;
        case 8:
            return 7;
        case 9:
            return 4;
        case 10:
            return 0;
        case 11:
            return 2;
        default:
            return 0;
        }
    }

// The HIT DICE number (the atomie 1/2 reads 0 - the flat-hp path; the ranges
// 7+3-12 and 2+1 to 5+4 pin their low ends)
inline int mm2aStatHd(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 15;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 8;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 2;
        case 8:
            return 10;
        case 9:
            return 0;
        case 10:
            return 12;
        case 11:
            return 2;
        default:
            return 0;
        }
    }

// The HIT DICE bonus points
inline int mm2aStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 7;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 6;
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
        default:
            return 0;
        }
    }

// The average hit points (floor of dice x 3.5 plus bonus; the atomie 2)
inline int mm2aStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 28;
        case 1:
            return 52;
        case 2:
            return 31;
        case 3:
            return 27;
        case 4:
            return 28;
        case 5:
            return 27;
        case 6:
            return 21;
        case 7:
            return 7;
        case 8:
            return 35;
        case 9:
            return 2;
        case 10:
            return 42;
        case 11:
            return 8;
        default:
            return 0;
        }
    }

// The NO. OF ATTACKS (the afanc 1 or 2 reads 2 - the loader max)
inline int mm2aStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
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
        default:
            return 0;
        }
    }

// The LEVEL/X.P. base value
inline int mm2aStatXp(int b)
    {
        switch (b) {
        case 0:
            return 1275;
        case 1:
            return 4000;
        case 2:
            return 1800;
        case 3:
            return 1300;
        case 4:
            return 575;
        case 5:
            return 775;
        case 6:
            return 300;
        case 7:
            return 28;
        case 8:
            return 1350;
        case 9:
            return 40;
        case 10:
            return 2700;
        case 11:
            return 40;
        default:
            return 0;
        }
    }

// The xp per hit point
inline int mm2aStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 8;
        case 6:
            return 6;
        case 7:
            return 2;
        case 8:
            return 14;
        case 9:
            return 1;
        case 10:
            return 16;
        case 11:
            return 3;
        default:
            return 0;
        }
    }

// The % IN LAIR cell (Nil reads 0)
inline int mm2aStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 20;
        case 4:
            return 95;
        case 5:
            return 40;
        case 6:
            return 30;
        case 7:
            return 90;
        case 8:
            return 95;
        case 9:
            return 35;
        case 10:
            return 30;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// The primary MOVE rate in inches
inline int mm2aStatMove(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 15;
        case 2:
            return 18;
        case 3:
            return 15;
        case 4:
            return 9;
        case 5:
            return 12;
        case 6:
            return 15;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 12;
        case 10:
            return 9;
        case 11:
            return 12;
        default:
            return 0;
        }
    }

}   // namespace rules
