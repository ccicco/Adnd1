// =========================================================================================
// Adnd1 - rules/mm2dv.h
// THE MM2 LETTER D PART 2 - the deva turn (the DEVA family at the foot of p.
// 42 with the astral, monadic and movanic deva stat blocks on p. 43),
// promoted to the live registry
// census 722 -> 723.
//
// Round four of the MM2 arc, the second PART-LETTER walk (the user Go call on
// the landed letter D part 1: the letter D continues with the deva family pp.
// 42-44; the DEVIL section and the rest of D await the user call). The
// capture is the Curtiss PDF upload cross-checked against an independent
// transcription; the contested cells settled: the monadic deva ARMOR: -4
// capture line is the ARMOR CLASS line (the transcription prints the class
// word); the monadic and movanic LEVEL prints IX (the capture 1X is the same
// OCR misread class as the atomie II); the movanic size keeps the print 6 1/2
// inches form; the movanic prose runs onto p. 44 where the DEVIL section
// opens mid-page. The pin-time walk finds three deva entries; three .lua defs
// ride the R791 data_files extension, registry 563 -> 566. The stat blocks
// pin in the 3-row DevaStats grid (the armor class, hit dice, hit, xp, lair,
// move and magic-resistance cells); the deva-common doctrine (the
// material-body rule, the spell-like list with its per-day maximums, the
// attack-form immunities with the monadic fire exception) pins as round-level
// doctrine. NO GAP FLIPS: the Letter D box flips only when all the D parts
// land (the R791 no-flip precedent). NO XP-AUDIT PATCH: mm2_print already
// rides the allowed-source list (the R797 patch). The live def walk (the one
// file-patch site block, no census marker) cross-checks all 3 defs against
// the DevaStats grid and the registry census 563 -> 566 as a floor.
//
namespace rules {

// ---- the MM2 letter D part 2 round pins (the R800 census) ----

// The MM2 letter D part 2 round: the deva turn (the user Go call on the
// landed letter D part 1)
inline int mm2dvRound()
    { return 800; }

// The pin-time walk from the print: the DEVA family at the foot of p. 42 with
// its three stat blocks on p. 43 (the astral, monadic and movanic devas)
inline int mm2dvEntryCount()
    { return 3; }

// The def census: three .lua defs ride the R791 data_files extension (no form
// splits in the deva family)
inline int mm2dvDefCount()
    { return 3; }

// The deva part opens at the foot of p. 42 (the DEVA family head right after
// the derro entry)
inline int mm2dvFirstPage()
    { return 42; }

// The deva part closes on p. 44 (the movanic prose tail; the DEVIL section
// opens mid-page)
inline int mm2dvLastPage()
    { return 44; }

// The live registry census at the landed letter D part 1 (the R799 landing
// count)
inline int mm2dvRegistryBefore()
    { return 563; }

// The live registry census after the three deva defs (563 + 3)
inline int mm2dvRegistryAfter()
    { return 566; }

// The 3-row deva stat grid: one row per promoted def in print order
inline int mm2dvDevaStatRows()
    { return 3; }

// The astral deva LEVEL/X.P. prints X/10,100 + 25/hp - the roman ten
inline int mm2dvAstralXpLevel()
    { return 10; }

// The monadic deva LEVEL/X.P. prints IX/8100 + 20/hp (the capture 1X is an
// OCR misread; the independent transcription prints IX - the atomie II class)
inline int mm2dvMonadicXpLevel()
    { return 9; }

// The movanic deva LEVEL/X.P. prints IX/7850 + 18/hp (the same 1X misread
// class)
inline int mm2dvMovanicXpLevel()
    { return 9; }

// The astral deva full kill xp: 10,100 + 25 x 67 hit points
inline int mm2dvAstralXpValue()
    { return 11775; }

// The monadic deva full kill xp: 8,100 + 20 x 60 hit points
inline int mm2dvMonadicXpValue()
    { return 9300; }

// The movanic deva full kill xp: 7,850 + 18 x 52 hit points
inline int mm2dvMovanicXpValue()
    { return 8786; }

// ---- the deva doctrine pins (the R800 MM2 letter D part 2) ----

// The deva-common spell-like list: cure disease 3 per day
inline int mm2dvDevaCureDiseasePerDay()
    { return 3; }

// The deva-common list: cure light wounds 7 per day
inline int mm2dvDevaCureLightWoundsPerDay()
    { return 7; }

// The deva-common list: cure serious wounds 3 per day
inline int mm2dvDevaCureSeriousWoundsPerDay()
    { return 3; }

// The deva-common list: detect traps 7 per day
inline int mm2dvDevaDetectTrapsPerDay()
    { return 7; }

// The deva-common list: dispel magic 7 per day
inline int mm2dvDevaDispelMagicPerDay()
    { return 7; }

// The deva-common list: heal once per day
inline int mm2dvDevaHealPerDay()
    { return 1; }

// The destroyed material body rule: the spirit returns to its own plane to
// remain for a decade before regaining a corporeal body
inline int mm2dvDevaSpiritRegainYears()
    { return 10; }

// The deva-common invisibility serves the individual or a 10-foot radius
inline int mm2dvDevaInvisibilityRadiusFeet()
    { return 10; }

// The race of devas inhabit the upper Outer Planes of Good
inline bool mm2dvDevaUpperPlanesOfGood()
    { return true; }

// Devas are servants and messengers of the deities of good alignment - some
// lawful, some chaotic, some neutral, but all are good
inline bool mm2dvDevaMessengersOfGoodDeities()
    { return true; }

// Devas are by no means the most powerful creatures on their planes (cf. the
// planetar and the solar)
inline bool mm2dvDevaNotMostPowerful()
    { return true; }

// All devas travel the planes of good alignment (the lawful only under
// instruction, the chaotic seldom except in service)
inline bool mm2dvDevaTravelPlanesOfGood()
    { return true; }

// All devas can become ethereal
inline bool mm2dvDevaCanBecomeEthereal()
    { return true; }

// Only the astral deva can travel astrally except when commanded by a deity
inline bool mm2dvOnlyAstralTravelsAstrallyUncommanded()
    { return true; }

// Devas operate equally well in any environment, including water
inline bool mm2dvDevaAnyEnvironmentIncludingWater()
    { return true; }

// On the Prime Material or any Elemental Plane only the material body of a
// deva can be destroyed
inline bool mm2dvDevaMaterialBodyOnlyOnPrimeAndElemental()
    { return true; }

// On any other plane all devas are subject to actual death
inline bool mm2dvDevaOnOtherPlanesSubjectToDeath()
    { return true; }

// No deva will ever negotiate with beings or creatures of Evil
inline bool mm2dvDevaNeverNegotiateWithEvil()
    { return true; }

// Nonlawful devas might strike a bargain with nonevil neutrals
inline bool mm2dvNonlawfulDevasBargainWithNonevilNeutrals()
    { return true; }

// A deva can usually evaluate opponents to determine which pose the greatest
// threat and attack accordingly
inline bool mm2dvDevaEvaluatesOpponents()
    { return true; }

// Deva attacks can be divided during a round if the deva so desires
inline bool mm2dvDevaDividesAttacksPerRound()
    { return true; }

// The deva-common spell-like list runs 1 at a time, 1 per round: cure
// disease, cure light wounds, cure serious wounds, detect evil, detect
// illusion, detect magic, detect traps, dispel magic, etherealness, heal,
// know alignment, invisibility, light, polymorph self, read magic, remove
// curse, remove fear, teleport with no error, tongues, ultravision,
// protection from evil
inline bool mm2dvDevaCommonSpellLikeList()
    { return true; }

// Devas are not affected by cold
inline bool mm2dvDevaColdImmune()
    { return true; }

// Devas are not affected by electrical attack spells
inline bool mm2dvDevaElectricityImmune()
    { return true; }

// Devas are not affected by magic missile
inline bool mm2dvDevaMagicMissileImmune()
    { return true; }

// Devas are not affected by petrification
inline bool mm2dvDevaPetrificationImmune()
    { return true; }

// Devas are not affected by poison
inline bool mm2dvDevaPoisonImmune()
    { return true; }

// Devas are not affected by normal fire-based attack spells
inline bool mm2dvDevaNormalFireImmune()
    { return true; }

// Devas are not affected by any gas attack spells
inline bool mm2dvDevaGasImmune()
    { return true; }

// Except for the monadic deva, devas take half damage from dragon and magical
// fire attacks
inline bool mm2dvDevaFireHalfDamage()
    { return true; }

// The monadic deva is not affected by fire of any sort (the family exception)
inline bool mm2dvMonadicFireImmuneOfAnySort()
    { return true; }

// Devas take full damage from acid attacks
inline bool mm2dvDevaAcidFullDamage()
    { return true; }

// Devas take no damage from normal iron or silver weapons
inline bool mm2dvDevaIronAndSilverNoDamage()
    { return true; }

// Devas take full damage from magic weapons
inline bool mm2dvDevaMagicWeaponsFullDamage()
    { return true; }

// It requires a +1 or better magic weapon to harm a deva
inline bool mm2dvDevaHitOnlyByPlusOneOrBetter()
    { return true; }

// ---- the MM2 letter D part 2 stat grid (the R800 wiring) ----

// The deva armor class cells (the demilich bare-negative class)
inline int mm2dvDevaStatAC(int b)
    {
        switch (b) {
        case 0:
            return -6;
        case 1:
            return -4;
        case 2:
            return -5;
        default:
            return 0;
        }
    }

// The deva hit dice (num only)
inline int mm2dvDevaStatHd(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 8;
        case 2:
            return 7;
        default:
            return 0;
        }
    }

// The deva hit dice bonus points
inline int mm2dvDevaStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 36;
        case 1:
            return 32;
        case 2:
            return 28;
        default:
            return 0;
        }
    }

// The deva book-average hit points
inline int mm2dvDevaStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 67;
        case 1:
            return 60;
        case 2:
            return 52;
        default:
            return 0;
        }
    }

// The deva attacks per round
inline int mm2dvDevaStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        default:
            return 0;
        }
    }

// The deva xp base cells (the IX/X settled levels)
inline int mm2dvDevaStatXp(int b)
    {
        switch (b) {
        case 0:
            return 10100;
        case 1:
            return 8100;
        case 2:
            return 7850;
        default:
            return 0;
        }
    }

// The deva xp per hit point
inline int mm2dvDevaStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 20;
        case 2:
            return 18;
        default:
            return 0;
        }
    }

// The deva % in lair cells (Nil -> 0, the charon precedent)
inline int mm2dvDevaStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return 0;
        }
    }

// The deva primary ground move rate (inches x 10)
inline int mm2dvDevaStatMove(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 15;
        case 2:
            return 12;
        default:
            return 0;
        }
    }

// The deva magic resistance percentages
inline int mm2dvDevaStatMr(int b)
    {
        switch (b) {
        case 0:
            return 65;
        case 1:
            return 60;
        case 2:
            return 55;
        default:
            return 0;
        }
    }

// ---- the astral deva pins (the R800 MM2 letter D part 2) ----

// The huge macelike weapon is of +3 value when employed by an astral deva
inline int mm2dvAstralMaceBonus()
    { return 3; }

// Any creature struck twice in the same melee round and suffering damage in
// excess of 20 hit points must save vs. spell or be knocked senseless
inline int mm2dvAstralKnockDamageThreshold()
    { return 20; }

// The knocked-senseless duration in rounds
inline int mm2dvAstralKnockSenselessRounds()
    { return 14; }

// The weapon also acts as a mace of disruption with chances to hit as if
// wielded by a 9th-level cleric
inline int mm2dvAstralDisruptionClericLevel()
    { return 9; }

// Light shed by an astral deva can have a 4-40 foot radius, as desired - the
// low end
inline int mm2dvAstralLightRadiusLo()
    { return 4; }

// The astral light radius high end
inline int mm2dvAstralLightRadiusHi()
    { return 40; }

// The astral protection from evil is a sphere with a 10-foot radius
inline int mm2dvAstralPfeRadiusFeet()
    { return 10; }

// The astral protection from evil sphere is of normal (+2) power
inline int mm2dvAstralPfePower()
    { return 2; }

// Once per day an astral deva can create a blade barrier which will last for
// up to 7 turns
inline int mm2dvAstralBladeBarrierTurns()
    { return 7; }

// The astral deva psionic ability 210, attack/defense modes A,B,C,E/F,G,H
inline int mm2dvAstralPsionicAbility()
    { return 210; }

// The astral deva intelligence genius (wisdom = 20)
inline int mm2dvAstralWisdom()
    { return 20; }

// The astral deva charisma effect is 20
inline int mm2dvAstralCharismaEffect()
    { return 20; }

// Astral devas can never be surprised
inline bool mm2dvAstralNeverSurprised()
    { return true; }

// Total vacuum does no harm to astral devas
inline bool mm2dvAstralVacuumNoHarm()
    { return true; }

// Astral devas are immune to life level loss, whether from undead or magic
inline bool mm2dvAstralImmuneLifeLevelLoss()
    { return true; }

// Astral deva souls cannot be trapped or imprisoned
inline bool mm2dvAstralSoulCannotBeTrapped()
    { return true; }

// Astral devas are immune to death spells
inline bool mm2dvAstralImmuneDeathSpells()
    { return true; }

// Astral devas are tall, slender and graceful, with golden skin and hair,
// amber eyes, and large white wings tinted with gold
inline bool mm2dvAstralGoldSkinAndWings()
    { return true; }

// ---- the monadic deva pins (the R800 MM2 letter D part 2) ----

// A monadic deva normally carries a metal rod equal to a +2 weapon
inline int mm2dvMonadicRodBonus()
    { return 2; }

// The monadic rod can be used either to pierce or smite at up to a 10-foot
// distance
inline int mm2dvMonadicRodRangeFeet()
    { return 10; }

// The radius of light shed by a monadic deva can extend from 3-30 feet, as
// desired - the low end
inline int mm2dvMonadicLightRadiusLo()
    { return 3; }

// The monadic light radius high end
inline int mm2dvMonadicLightRadiusHi()
    { return 30; }

// The monadic protection from evil sphere is of a 15-foot radius
inline int mm2dvMonadicPfeRadiusFeet()
    { return 15; }

// The monadic protection from evil sphere is half-power (+1)
inline int mm2dvMonadicPfePower()
    { return 1; }

// The monadic hold monster serves elementals only, 1 creature, 8 rounds
inline int mm2dvMonadicHoldMonsterRounds()
    { return 8; }

// The monadic hold monster is usable 3 per day
inline int mm2dvMonadicHoldMonsterPerDay()
    { return 3; }

// A monadic deva can also project image (1 per day)
inline int mm2dvMonadicProjectImagePerDay()
    { return 1; }

// The monadic deva intelligence genius (wisdom = 19)
inline int mm2dvMonadicWisdom()
    { return 19; }

// The monadic deva charisma effect is 19
inline int mm2dvMonadicCharismaEffect()
    { return 19; }

// Any very dense creature so struck (such as one of solid rock) and any
// metal-armored opponent takes double damage on any 2nd hit during a single
// round of combat
inline bool mm2dvMonadicDenseDoubleDamageSecondHit()
    { return true; }

// Monadic devas are immune to life level loss from magic or undead
inline bool mm2dvMonadicImmuneLifeLevelLoss()
    { return true; }

// Monadic devas are immune to death magic from any source
inline bool mm2dvMonadicImmuneDeathMagic()
    { return true; }

// Monadic devas are milky white with silvery hair and colorless eyes; their
// wings are white with a silver sheen
inline bool mm2dvMonadicSilverySheenWings()
    { return true; }

// ---- the movanic deva pins (the R800 MM2 letter D part 2) ----

// A movanic deva is armed typically with a long, slender sword; the weapon
// generally conforms to a +1 flame tongue sword
inline int mm2dvMovanicSwordBonus()
    { return 1; }

// Light shed by a movanic deva varies in radius from 2-20 feet, as desired -
// the low end
inline int mm2dvMovanicLightRadiusLo()
    { return 2; }

// The movanic light radius high end
inline int mm2dvMovanicLightRadiusHi()
    { return 20; }

// The movanic protection from evil sphere is one of a 10-foot radius
inline int mm2dvMovanicPfeRadiusFeet()
    { return 10; }

// The movanic protection from evil sphere is half (+1) power
inline int mm2dvMovanicPfePower()
    { return 1; }

// A movanic deva can also cause or cure blindness, detect traps, and
// neutralize poison (3 per day)
inline int mm2dvMovanicNeutralizePoisonPerDay()
    { return 3; }

// The movanic deva intelligence exceptional (wisdom = 18)
inline int mm2dvMovanicWisdom()
    { return 18; }

// The movanic deva charisma effect is 18
inline int mm2dvMovanicCharismaEffect()
    { return 18; }

// The movanic sword conforms to the characteristics of a +1 flame tongue
// sword with respect to effects and special bonuses to hit and damage
inline bool mm2dvMovanicFlameTongueSword()
    { return true; }

// Plant life of any sort will not (and cannot) harm a movanic deva
inline bool mm2dvMovanicPlantsCannotHarm()
    { return true; }

// Normal animals will not willingly attack a movanic deva (reptiles and
// similar creatures as well as monsters may do so)
inline bool mm2dvMovanicAnimalsWillNotAttack()
    { return true; }

// Movanic devas are immune to death magic
inline bool mm2dvMovanicImmuneDeathMagic()
    { return true; }

// Life level loss, energy drain, and other energy effects of the Negative or
// Positive Material Planes do not affect movanic devas
inline bool mm2dvMovanicUnaffectedByEnergyPlanes()
    { return true; }

}   // namespace rules
