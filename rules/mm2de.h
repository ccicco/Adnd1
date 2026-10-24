// =========================================================================================
// Adnd1 - rules/mm2de.h
// THE MM2 LETTER E WALK - THE EAGLE, ELF AND EXECUTIONER HOOD TURNS (the
// eagle, the eblis, the electric marine eel and the ELF family head pp.
// 62-63, the grugach, the valley elf, the elfin cat and the executioner hood
// pp. 62-64), promoted to the live registry
// census 726 -> 727.
//
// Round nine of the MM2 arc, the sixth PART-LETTER walk (the user Go call on
// the landed dracolisk walk: the letter E closes with the eagle, the eblis,
// the electric marine eel, the ELF family head, the grugach, the valley elf,
// the elfin cat and the executioner's hood pp. 62-64 - the E-FLIP round, the
// Letter E gap box flips to closed). The capture is the Curtiss PDF upload
// cross-checked against the independent transcription and the archive.org
// djvu OCR, the contested cells settled: the grugach treasure letters N, Q;
// the grugach fighter/druids dual class; the electric eel move "//9"" kept
// verbatim; the executioner hood hit-dice ladder reads the or-form best
//
namespace rules {

// ---- the MM2 letter E walk round pins (the R804 census) ----

// The MM2 letter E walk round: the eagle, elf and executioner hood turns, the
// E-flip round (the user Go call on the landed dracolisk walk)
inline int mm2deRound()
    { return 804; }

// The registry census before the R804 promotion (the landed R803 count)
inline int mm2deRegistryBefore()
    { return 615; }

// The registry census after the R804 promotion (7 defs)
inline int mm2deRegistryAfter()
    { return 622; }

// The R804 def count (the eagle, the eblis, the electric marine eel, the
// grugach, the valley elf, the elfin cat and the executioner's hood)
inline int mm2deDefCount()
    { return 7; }

// The pin-time entry count on pp. 62-64 (the 7 stat blocks plus the ELF
// family head, a doctrine-only grouping with no stat block of its own)
inline int mm2deEntryCount()
    { return 8; }

// The row count of the eagle-to-hood stat grid
inline int mm2deEgStatRows()
    { return 7; }

// The gap report closed boxes after the E-flip (the Letter E box joins A
// through D)
inline int mm2deGapClosed()
    { return 10; }

// The gap report open boxes after the E-flip
inline int mm2deGapOpen()
    { return 27; }

// The letter-E index entries owned by earlier rounds (the euparkeria under
// DINOSAUR and the cooshee, the elven dog)
inline int mm2dePriorOwnedEntries()
    { return 2; }

// The euparkeria landed with the R802 dinosaur walk (p. 52, a letter-E index
// entry)
inline int mm2deEuparkeriaOwningRound()
    { return 802; }

// The cooshee (elven dog) landed with the R798 letters BC walk (a letter-E
// index entry)
inline int mm2deCoosheeOwningRound()
    { return 798; }

// The ELF family head on p. 63 groups the grugach and the valley elf stat
// blocks beneath its heading (the heading itself carries no stat block)
inline int mm2deElfHeadSubEntryCount()
    { return 2; }

// The ELF family head p. 63 is a grouping heading with no stat block of its
// own (the grugach and the valley elf blocks follow it)
inline bool mm2deElfHeadIsDoctrineOnlyHeading()
    { return true; }

// The elfin cat stands alone with its own stat block (pp. 63-64), not under
// the ELF family heading
inline bool mm2deElfinCatOwnStatBlock()
    { return true; }

// ---- the eagle pins (the R804 MM2 letter E walk) ----

// The eagle full kill xp (35 + 2/hp x 6 avg; level II)
inline int mm2deEagleXpValue()
    { return 47; }

// The eagle printed xp level (II)
inline int mm2deEagleXpLevel()
    { return 2; }

// The chance an encounter is in a rookery area
inline int mm2deEagleRookeryPct()
    { return 5; }

// The rookery band low end
inline int mm2deEagleRookeryMin()
    { return 5; }

// The rookery band high end
inline int mm2deEagleRookeryMax()
    { return 12; }

// The nest egg count low end
inline int mm2deEagleEggsMin()
    { return 1; }

// The nest egg count high end
inline int mm2deEagleEggsMax()
    { return 4; }

// The chance a nest holds a small shiny item (a coin, gem, etc.)
inline int mm2deEagleNestShinyPct()
    { return 10; }

// The dive-from-height threshold (from 100 feet or more)
inline int mm2deEagleDiveHeightFeet()
    { return 100; }

// The dive restricts damage to 2 claw attacks
inline int mm2deEagleDiveClawAttacks()
    { return 2; }

// The dive attacks are at +2 to hit
inline int mm2deEagleDiveToHitBonus()
    { return 2; }

// The dive attacks cause twice normal damage
inline int mm2deEagleDiveDamageMultiplier()
    { return 2; }

// The share of eagles that can be properly managed for hunting
inline int mm2deEagleTrainablePct()
    { return 25; }

// The viable eggs or eaglets market low end (gold pieces)
inline int mm2deEagleEggValueMin()
    { return 60; }

// The viable eggs or eaglets market high end (gold pieces)
inline int mm2deEagleEggValueMax()
    { return 100; }

// Diving movement is double normal speed
inline bool mm2deEagleDiveDoublesSpeed()
    { return true; }

// Due to exceptional eyesight eagles are almost never surprised
inline bool mm2deEagleAlmostNeverSurprised()
    { return true; }

// Unless exceptionally hungry eagles will not attack even the smaller
// demihumans
inline bool mm2deEagleAvoidsDemihumansUnlessHungry()
    { return true; }

// ---- the eblis pins (the R804 MM2 letter E walk) ----

// The eblis full kill xp (165 + 5/hp x 18 avg; level IV)
inline int mm2deEblisXpValue()
    { return 255; }

// The eblis printed xp level (IV)
inline int mm2deEblisXpLevel()
    { return 4; }

// The community hut count low end
inline int mm2deEblisHutsMin()
    { return 2; }

// The community hut count high end
inline int mm2deEblisHutsMax()
    { return 8; }

// The unlikelihood the dwellings are discovered even by careful search
inline int mm2deEblisHutHiddenPct()
    { return 90; }

// The chance a hut pile holds an egg
inline int mm2deEblisEggPct()
    { return 30; }

// The chance a hut holds 1 of the shiny treasure entries
inline int mm2deEblisTreasurePct()
    { return 25; }

// In each community 1 individual is capable of illusionist magic
inline int mm2deEblisIllusionistsPerCommunity()
    { return 1; }

// The illusionist spell count low end
inline int mm2deEblisSpellMin()
    { return 2; }

// The illusionist spell count high end
inline int mm2deEblisSpellMax()
    { return 8; }

// The spells are usable at 3rd level ability
inline int mm2deEblisSpellCastingLevel()
    { return 3; }

// The printed illusionist spell ladder runs audible glamor through whispering
// wind
inline int mm2deEblisIllusionistSpellCount()
    { return 8; }

// Saving throws vs. fire are made at +1
inline int mm2deEblisFireSaveBonus()
    { return 1; }

// Fire damage is at -1 per die
inline int mm2deEblisFireDamageBonus()
    { return 1; }

// The eblis illusionist magic works by means of dancing and vocalization
inline bool mm2deEblisCastsByDancingVocalization()
    { return true; }

// The eblis attack is by stabbing with the beak
inline bool mm2deEblisAttacksByBeakStab()
    { return true; }

// ---- the electric marine eel pins (the R804 MM2 letter E walk) ----

// The electric marine eel full kill xp (400 + 8/hp x 21 avg; level V)
inline int mm2deElectricEelXpValue()
    { return 568; }

// The electric marine eel printed xp level (V)
inline int mm2deElectricEelXpLevel()
    { return 5; }

// The common warm shallow depth low end
inline int mm2deElectricEelDepthMinFeet()
    { return 30; }

// The common warm shallow depth high end
inline int mm2deElectricEelDepthMaxFeet()
    { return 150; }

// The eel strikes quickly, gaining +1 on initiative
inline int mm2deElectricEelInitiativeBonus()
    { return 1; }

// The eel releases a charge once every turn
inline int mm2deElectricEelChargePeriodTurns()
    { return 1; }

// The inner electrical blast radius (full damage band)
inline int mm2deElectricEelInnerRadiusFeet()
    { return 5; }

// The middle electrical blast radius (5-10 feet)
inline int mm2deElectricEelMiddleRadiusFeet()
    { return 10; }

// The outer electrical blast radius (10-15 feet)
inline int mm2deElectricEelOuterRadiusFeet()
    { return 15; }

// The inner band damage low end
inline int mm2deElectricEelInnerDamageMin()
    { return 6; }

// The inner band damage high end
inline int mm2deElectricEelInnerDamageMax()
    { return 36; }

// The middle band damage low end
inline int mm2deElectricEelMiddleDamageMin()
    { return 4; }

// The middle band damage high end
inline int mm2deElectricEelMiddleDamageMax()
    { return 24; }

// The outer band damage low end
inline int mm2deElectricEelOuterDamageMin()
    { return 2; }

// The outer band damage high end
inline int mm2deElectricEelOuterDamageMax()
    { return 12; }

// Saving throws at 5-10 feet are made at +1
inline int mm2deElectricEelMiddleSaveBonus()
    { return 1; }

// Saving throws at 10-15 feet are made at +2
inline int mm2deElectricEelOuterSaveBonus()
    { return 2; }

// A failed save vs. paralysis leaves the victim stunned and helpless for
// rounds equal to the damage sustained
inline bool mm2deElectricEelChargeStunsForDamageRounds()
    { return true; }

// A successful save does not reduce damage by one-half but merely negates
// stunning
inline bool mm2deElectricEelSaveNegatesOnlyStunning()
    { return true; }

// The giant marine electric eel is found only in warm, relatively shallow
// salt waters
inline bool mm2deElectricEelWarmShallowSaltWaterOnly()
    { return true; }

// ---- the grugach pins (the R804 MM2 letter E walk) ----

// The grugach full kill xp (65 + 2/hp x 4 avg; the print carries no xp level
// prefix)
inline int mm2deGrugachXpValue()
    { return 73; }

// The grugach strength bonus (add +2 on strength dice roll)
inline int mm2deGrugachStrengthDiceBonus()
    { return 2; }

// Treating a 19 or 20 strength roll as 18
inline int mm2deGrugachStrengthCap()
    { return 18; }

// The chance a band has stags for mounts
inline int mm2deGrugachStagMountPct()
    { return 70; }

// The share of random contacts made supposedly with wood elves that are
// actually with grugach
inline int mm2deGrugachMistakenForWoodElfPct()
    { return 20; }

// The probability creatures passing near a trap will be caught in it
inline int mm2deGrugachTrapCatchPct()
    { return 90; }

// The catch likelihood reduced to 30% when the trapped area is examined
// carefully
inline int mm2deGrugachTrapCarefulCatchPct()
    { return 30; }

// The pits are normally 10 feet deep and spiked
inline int mm2deGrugachPitDepthFeet()
    { return 10; }

// The pit fall damage low end (earth-floored pit)
inline int mm2deGrugachPitFallMin()
    { return 1; }

// The pit fall damage high end
inline int mm2deGrugachPitFallMax()
    { return 4; }

// The per-spike damage low end
inline int mm2deGrugachPitSpikeMin()
    { return 1; }

// The per-spike damage high end
inline int mm2deGrugachPitSpikeMax()
    { return 6; }

// The chance the pit adds poison
inline int mm2deGrugachPitPoisonPct()
    { return 50; }

// The snares suspend creatures 5 feet or more above the ground
inline int mm2deGrugachSnareSuspensionFeet()
    { return 5; }

// The deadfall log damage low end (5d6)
inline int mm2deGrugachDeadfallMinDice()
    { return 5; }

// The deadfall log damage high end (8d6)
inline int mm2deGrugachDeadfallMaxDice()
    { return 8; }

// The deadfall log damage die sides
inline int mm2deGrugachDeadfallDieSides()
    { return 6; }

// The grugach are completely xenophobic, distrusting even other sorts of
// elves
inline bool mm2deGrugachXenophobic()
    { return true; }

// The grugach are not magic-users
inline bool mm2deGrugachNotMagicUsers()
    { return true; }

// Dual-classed grugach individuals will be fighter/druids (the capture
// "fluids" the OCR misread)
inline bool mm2deGrugachDualClassAreFighterDruids()
    { return true; }

// All adult grugach are able to set traps
inline bool mm2deGrugachAllAdultsSetTraps()
    { return true; }

// The deadfall log crashes down for damage and pins the victim as well
inline bool mm2deGrugachDeadfallPinsVictim()
    { return true; }

// ---- the valley elf pins (the R804 MM2 letter E walk) ----

// The valley elf full kill xp (65 + 2/hp x 5 avg, average individuals only;
// level III)
inline int mm2deValleyElfXpValue()
    { return 75; }

// The valley elf printed xp level (III)
inline int mm2deValleyElfXpLevel()
    { return 3; }

// The chance 1-4 cooshee are with a wandering band
inline int mm2deValleyElfCoosheePct()
    { return 75; }

// The wandering band cooshee count low end
inline int mm2deValleyElfCoosheeMin()
    { return 1; }

// The wandering band cooshee count high end
inline int mm2deValleyElfCoosheeMax()
    { return 4; }

// The lair probability of 2-8 cooshee
inline int mm2deValleyElfCoosheeLairPct()
    { return 90; }

// The lair cooshee count low end
inline int mm2deValleyElfCoosheeLairMin()
    { return 2; }

// The lair cooshee count high end
inline int mm2deValleyElfCoosheeLairMax()
    { return 8; }

// In the WORLD OF GREYHAWK setting bands have raided into Bissel, Gran March,
// Ket and the Grand Duchy of Geoff
inline int mm2deValleyElfRaidTargetCount()
    { return 4; }

// The valley elves use cooshee (q.v.) as guard animals
inline bool mm2deValleyElfUsesCoosheeGuards()
    { return true; }

// All other sorts of elves, including the dark elves (drow), shun valley
// elves
inline bool mm2deValleyElfShunnedByOtherElves()
    { return true; }

// The valley elves dislike association with any races save perhaps gnomekind,
// whom they tolerate
inline bool mm2deValleyElfToleratesGnomes()
    { return true; }

// The valley elves follow the MONSTER MANUAL I "Elf" statistics for habitat,
// group composition, weaponry and special abilities
inline bool mm2deValleyElfFollowsMm1ElfStats()
    { return true; }

// ---- the elfin cat pins (the R804 MM2 letter E walk) ----

// The elfin cat full kill xp (135 + 4/hp x 16 avg; level IV)
inline int mm2deElfinCatXpValue()
    { return 199; }

// The elfin cat printed xp level (IV)
inline int mm2deElfinCatXpLevel()
    { return 4; }

// The elfin cat leaps 20 feet or more with ease
inline int mm2deElfinCatLeapFeet()
    { return 20; }

// The enlarge uses (enlarge actually increases attack power to double normal)
inline int mm2deElfinCatEnlargePerDay()
    { return 1; }

// The reduce uses per day
inline int mm2deElfinCatReducePerDay()
    { return 2; }

// The tree uses per day (limb, not entire tree)
inline int mm2deElfinCatTreePerDay()
    { return 2; }

// The trip uses per day
inline int mm2deElfinCatTripPerDay()
    { return 1; }

// The spell-like powers are performed at 9th level ability
inline int mm2deElfinCatSpellLevel()
    { return 9; }

// The concealment probability in natural surroundings
inline int mm2deElfinCatConcealPct()
    { return 90; }

// The keen senses prevent surprise except 1 in 20
inline int mm2deElfinCatSurprisedIn()
    { return 20; }

// The elfin cat in turn surprises 5 in 6
inline int mm2deElfinCatSurprisesIn()
    { return 6; }

// Enlarge actually increases attack power to double normal
inline bool mm2deElfinCatEnlargesToDoubleAttack()
    { return true; }

// The elfin cats move 99.9% silently
inline bool mm2deElfinCatMovesSilently()
    { return true; }

// The elfin cats use a limited ESP ability to read the thoughts of creatures
// nearby
inline bool mm2deElfinCatLimitedEsp()
    { return true; }

// In return for feeding and protection the elfin cats serve as sentinels and
// report intruders
inline bool mm2deElfinCatSentinelRole()
    { return true; }

// The elfin cats can speak a few words of Elf, due to association, and some
// speak Gnome, Brownie, etc., as well
inline bool mm2deElfinCatSpeaksAFewWordsOfElf()
    { return true; }

// ---- the executioner's hood pins (the R804 MM2 letter E walk) ----

// The executioner's hood full kill xp (320 + 8/hp x 27 avg; level V)
inline int mm2deHoodXpValue()
    { return 536; }

// The executioner's hood printed xp level (V)
inline int mm2deHoodXpLevel()
    { return 5; }

// The printed hit-dice ladder runs 2+2, 4+4 and 6+6
inline int mm2deHoodFormCount()
    { return 3; }

// The hit-dice ladder low end (the grid reads the or-form best 6+6)
inline int mm2deHoodHdNumMin()
    { return 2; }

// The hit-dice ladder high end
inline int mm2deHoodHdNumMax()
    { return 6; }

// The hit-dice bonus ladder low end
inline int mm2deHoodHdBonusMin()
    { return 2; }

// The hit-dice bonus ladder high end
inline int mm2deHoodHdBonusMax()
    { return 6; }

// The immediate bite damage low end
inline int mm2deHoodBiteMin()
    { return 1; }

// The immediate bite damage high end (the strangulation and suffocation
// repeats it)
inline int mm2deHoodBiteMax()
    { return 4; }

// The surprise roll low end (surprise on a 1-3)
inline int mm2deHoodSurpriseMin()
    { return 1; }

// The surprise roll high end
inline int mm2deHoodSurpriseMax()
    { return 3; }

// After 4 rounds of strong brandy the hood falls off, intoxicated
inline int mm2deHoodBrandyRounds()
    { return 4; }

// The brandy makes the monster lose 1 point of damaging ability per round
inline int mm2deHoodBrandyLossPerRound()
    { return 1; }

// The full quart assumed poured
inline int mm2deHoodBrandyQuarts()
    { return 1; }

// The monster is about 1 inch thick
inline int mm2deHoodThicknessInches()
    { return 1; }

// There are 2 eye holes which can be used to see out of or into its cavity
inline int mm2deHoodEyeHoles()
    { return 2; }

// The executioner hood is totally unaffected by sleep spells
inline bool mm2deHoodImmuneToSleepSpells()
    { return true; }

// The fibrous strands cause the victim to suffer whatever other spell effects
// the hood sustains
inline bool mm2deHoodVictimSharesSpellEffects()
    { return true; }

// The hood can spread out into disc shape and has been known to hunt as does
// a lurker above (q.v.)
inline bool mm2deHoodHuntsLikeLurkerAbove()
    { return true; }

// The hood inflicts further damage from strangulation and suffocation until
// the prey is killed or the monster is slain
inline bool mm2deHoodStranglesPrey()
    { return true; }

// ---- the MM2 letter E walk stat grid (the R804 wiring) ----

// The armor class cells
inline int mm2deEgStatAC(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The hit dice num cells (the electric eel 6-8 ranged cell reads the low end
// - the kuei precedent; the hood or-form ladder reads the best 6)
inline int mm2deEgStatHd(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The hit dice bonus points
inline int mm2deEgStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 6;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The book-average hit points (the floor(num x 3.5) + bonus formula)
inline int mm2deEgStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 18;
        case 2:
            return 21;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 16;
        case 6:
            return 27;
        default:
            return 0;
        }
    }

// The attack cells
inline int mm2deEgStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The base xp cells (the grugach print carries no xp level prefix)
inline int mm2deEgStatXp(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 165;
        case 2:
            return 400;
        case 3:
            return 65;
        case 4:
            return 65;
        case 5:
            return 135;
        case 6:
            return 320;
        default:
            return 0;
        }
    }

// The xp per hit point cells
inline int mm2deEgStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 8;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 8;
        default:
            return 0;
        }
    }

// The percent in lair cells (every Nil reads 0)
inline int mm2deEgStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 50;
        case 2:
            return 0;
        case 3:
            return 50;
        case 4:
            return 10;
        case 5:
            return 5;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The primary move cells in print inches (the first number of the print move
// line; the eel "//9"" verbatim quirk reads 9)
inline int mm2deEgStatMove(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 12;
        case 2:
            return 9;
        case 3:
            return 15;
        case 4:
            return 12;
        case 5:
            return 18;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The magic resistance cells (the grugach and valley elf "90% to charm and
// sleep only" reads 90; every Standard reads 0)
inline int mm2deEgStatMr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 90;
        case 4:
            return 90;
        case 5:
            return 20;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
