// ===========================================================================
// Adnd1 - rules/uapotprose.h
// The UA TREASURE (POTIONS) prose
// pins, part 1, R376: the twelve
// clean new-potion descriptions
// (pp. 90-92) - the four elixirs,
// the potion of fire breath, the
// oils of fiery burning,
// fumbling, sharpness,
// timelessness, and the potions
// of rainbow hues,
// ventriloquism, vitality. The
// seven PDF-gated fills
// landed R396 (acid
// resistance, disenchantment,
// elemental, impact, the
// philters of beauty,
// glibness, stammering) -
// the gap item closed. The
// skeleton seam rides in the
// regtest audit, not here.
namespace rules {

// ---- the elixir of health ----
// Half a flask cures any one or
// two of the nine listed
// problems; the whole flask
// cures them all. It will not
// heal wounds or restore hit
// points lost through the
// listed causes.
inline int uappHealthCuresCount()
    { return 9; }

inline bool uappHealthHealsWounds()
    { return false; }

inline int uappHealthHalfFlaskCuresMax()
    { return 2; }

inline bool uappHealthWholeFlaskCuresAll()
    { return true; }

// ---- the elixir of life ----
// Restores life at a negative
// hit point level up to 20% of
// the total; administered
// within 5 rounds of death; one
// turn later the recipient sits
// unconscious at 1 hit point.
inline int uappLifeNegativeHpPct()
    { return 20; }

// A creature at -10 benefits
// only with a full-strength
// total of 50 or more.
inline int uappLifeMinus10NeedsFullHp()
    { return 50; }

inline int uappLifeWindowRounds()
    { return 5; }

inline int uappLifeAfterOneTurnHp()
    { return 1; }

// Each neutralized negative hit
// point costs a day of rest or
// a cure light wounds; the
// stronger spells buy more days.
inline int uappLifeRestDaysPerNegHp()
    { return 1; }

inline int uappLifeCureSeriousDays()
    { return 2; }

inline int uappLifeCureCriticalDays()
    { return 3; }

inline int uappLifeHealSpellDays()
    { return 7; }

inline bool uappLifeDemihumansAffected()
    { return true; }

// ---- the elixir of madness ----
inline const char* uappMadnessEquivalentSpell()
    { return "symbol of insanity"; }

inline int uappMadnessSipsToAffect()
    { return 1; }

// Once any creature is
// affected, the dweomer of the
// ENTIRE flask vanishes.
inline bool uappMadnessFlaskDweomerVanishes()
    { return true; }

// ---- the elixir of youth ----
inline int uappYouthFullDoseYearsLo()
    { return 2; }

inline int uappYouthFullDoseYearsHi()
    { return 5; }

inline int uappYouthLowPotencyYearsLo()
    { return 1; }

inline int uappYouthLowPotencyYearsHi()
    { return 3; }

// Sipping first reduces the
// potency of the whole flask.
inline bool uappYouthSippingReducesPotency()
    { return true; }

// ---- the potion of fire breath ----
// The dweomer holds up to six
// turns before belching; after
// expiry a 10% backfire erupts
// in the imbiber, double
// damage, NO save.
inline int uappFireBreathRetainTurns()
    { return 6; }

inline int uappFireBreathBackfirePct()
    { return 10; }

inline int uappFireBreathBackfireDmgMult()
    { return 2; }

inline bool uappFireBreathBackfireNoSave()
    { return true; }

inline int uappFireBreathDraughtsPerFlask()
    { return 4; }

inline int uappFireBreathSmallWidthIn()
    { return 1; }

inline int uappFireBreathSmallLenIn()
    { return 2; }

inline int uappFireBreathSmallDmgLo()
    { return 3; }

inline int uappFireBreathSmallDmgHi()
    { return 12; }

inline int uappFireBreathFullWidthIn()
    { return 2; }

inline int uappFireBreathFullLenIn()
    { return 8; }

inline int uappFireBreathFullDmgLo()
    { return 5; }

inline int uappFireBreathFullDmgHi()
    { return 50; }

// Save vs. breath weapon for
// half, in all cases.
inline bool uappFireBreathSaveForHalf()
    { return true; }

// ---- the oil of fiery burning ----
// 5d6 to the coated creature,
// save vs. spell for half; a
// hurled flask always breaks.
inline int uappFieryDmgDice()
    { return 5; }

inline int uappFieryDmgSides()
    { return 6; }

inline bool uappFierySaveForHalf()
    { return true; }

inline bool uappFieryHurlAlwaysBreaks()
    { return true; }

inline int uappFieryBlastRadiusIn()
    { return 1; }

inline int uappFieryMaxCreatures()
    { return 6; }

// Opening the flask: the holder
// takes 1-4 at once, and
// re-stoppering needs a roll of
// dexterity or less on 2d10.
inline int uappFieryOpenDmgLo()
    { return 1; }

inline int uappFieryOpenDmgHi()
    { return 4; }

inline int uappFieryRestopperDice()
    { return 2; }

inline int uappFieryRestopperSides()
    { return 10; }

// ---- the oil of fumbling ----
// Under melee stress: a 50%
// chance each round of
// fumbling; only a thorough
// solvent bath removes it early.
inline int uappFumblingPctPerRound()
    { return 50; }

inline bool uappFumblingSolventBathRemoves()
    { return true; }

// ---- the oil of sharpness ----
inline int uappSharpnessDurationLo()
    { return 8; }

inline int uappSharpnessDurationHi()
    { return 12; }

inline int uappSharpnessAppsLo()
    { return 3; }

inline int uappSharpnessAppsHi()
    { return 5; }

inline int uappSharpnessMaxBonus()
    { return 6; }

// The dweomer by die roll:
// 1-2 +1, 3-5 +2, 6-11 +3,
// 12-16 +4, 17-19 +5, 20 +6.
inline int uappSharpnessBonusForRoll(int r) {
    static const int k[20] = {
        1, 1, 2, 2, 2, 3, 3, 3, 3, 3,
        3, 4, 4, 4, 4, 4, 5, 5, 5, 6
    };
    if (r < 1) return 0;
    if (r > 20) return 0;
    return k[r - 1];
}

// ---- the oil of timelessness ----
// Each real year acts as a day
// on formerly-alive matter; the
// coating never wears off but
// can be magically removed.
inline int uappTimelessYearActsAsDays()
    { return 1; }

inline bool uappTimelessNeverWearsOff()
    { return true; }

inline int uappTimelessSaveBonus()
    { return 1; }

inline int uappTimelessHorsesPerFlask()
    { return 1; }

inline int uappTimelessHumansPerFlask()
    { return 8; }

// ---- the potion of rainbow hues ----
// Must be stored in a metallic
// container; a full flask holds
// seven hours of effect; the
// hue lands in under a segment.
inline bool uappRainbowMetallicContainer()
    { return true; }

inline int uappRainbowHoursPerFlask()
    { return 7; }

inline int uappRainbowSegmentMax()
    { return 1; }

inline int uappRainbowSparingDraughts()
    { return 7; }

inline int uappRainbowDraughtHours()
    { return 1; }

// ---- the potion of ventriloquism ----
inline int uappVentriloquismUses()
    { return 6; }

inline const char* uappVentriloquismAsClass()
    { return "magic-user"; }

inline bool uappVentriloquismFadesOnTime()
    { return true; }

// ---- the potion of vitality ----
// Seven days of exertion-proof
// vigor; proof against poisons
// and diseases the while; lost
// hit points return at 1 per 4
// hours.
inline int uappVitalityMaxDays()
    { return 7; }

inline bool uappVitalityPoisonDiseaseProof()
    { return true; }

inline int uappVitalityHpPerRecovery()
    { return 1; }

inline int uappVitalityRecoveryHours()
    { return 4; }

// Taken after deprivation, it
// nullifies the adverse effects
// and rides the remaining days.
inline bool uappVitalityRidesRemaining()
    { return true; }

// ---- the oil of acid
// resistance (the R396 clean
// read) ----
// Confers virtual
// invulnerability to acid on
// skin, cloth, or any other
// material; one application
// lasts a full day, but each
// acid exposure eats the
// remaining potency by as
// many minutes as the acid
// would have caused hit
// points of damage to
// exposed flesh.
inline bool uappAcidResCoversAnyMaterial()
    { return true; }

inline int uappAcidResDurationHours()
    { return 24; }

// The largest black dragon
// example: 64 minutes lost,
// 32 with a save versus
// breath weapon.
inline int uappAcidResBigBlackMinutes()
    { return 64; }

inline int uappAcidResBigBlackSavedMinutes()
    { return 32; }

// One flask: one man-sized
// creature for 24 hours, or
// 24 creatures for one hour -
// any combination between.
inline int uappAcidResOneManSizeHours()
    { return 24; }

inline int uappAcidResOneHourCreatures()
    { return 24; }

// A horse is equivalent to
// eight man-sized creatures.
inline int uappAcidResHorseEqualsMen()
    { return 8; }

// ---- the oil of
// disenchantment (the R396
// clean read) ----
// Removes all enchantment/
// charm dweomers placed upon
// living things; rubbed on an
// object, the object's dweomer
// is lost for 21-30 turns
// (d10 + 20),
// then returns once the oil
// has lost its potency. The
// oil radiates no magic and
// masks the dweomer of
// whatever it coats while
// effective.
inline bool uappDisenRemovesFromLiving()
    { return true; }

inline int uappDisenLostTurnsLo()
    { return 21; }

inline int uappDisenLostTurnsHi()
    { return 30; }

inline bool uappDisenItemRegainsDweomer()
    { return true; }

inline bool uappDisenRadiatesMagic()
    { return false; }

inline bool uappDisenMasksDweomer()
    { return true; }

// ---- the oil of elemental
// invulnerability (the R396
// clean read) ----
// Equal chances of the four
// basic sorts (air, earth,
// fire, water - roll d4);
// total invulnerability to
// normal elemental forces on
// the Prime Material Plane;
// elemental creatures still
// damage at -1 per die.
inline int uappElemInvSortCount()
    { return 4; }

inline int uappElemInvSortDieSides()
    { return 4; }

inline bool uappElemInvNormalElementalProof()
    { return true; }

// A 10% chance any container
// is usable on any Elemental
// or Paraelemental Plane.
inline int uappElemInvPlaneUsablePct()
    { return 10; }

inline int uappElemInvMonsterDamagePerDie()
    { return -1; }

// One individual for eight
// days, or eight individuals
// for one day.
inline int uappElemInvCoverageIndividuals()
    { return 8; }

inline int uappElemInvCoverageDays()
    { return 8; }

// ---- the oil of impact (the
// R396 clean read) ----
// Charges blunt weapons and
// missiles - hurled hammers,
// hurled clubs, sling stones,
// sling bullets - with a
// powerful dweomer; a flask
// holds 3-5 applications; a
// hand-held weapon keeps the
// dweomer 9-12 rounds, a
// missile carries a single
// charge.
inline bool uappImpactBluntAndMissiles()
    { return true; }

inline int uappImpactMissileKindCount()
    { return 4; }

inline int uappImpactApplicationsLo()
    { return 3; }

inline int uappImpactApplicationsHi()
    { return 5; }

inline int uappImpactHandRoundsLo()
    { return 9; }

inline int uappImpactHandRoundsHi()
    { return 12; }

inline bool uappImpactMissileSingleCharge()
    { return true; }

// One application treats 4-5
// sling missiles or 2 larger
// weapons.
inline int uappImpactSlingPerAppLo()
    { return 4; }

inline int uappImpactSlingPerAppHi()
    { return 5; }

inline int uappImpactLargerWeaponsPerApp()
    { return 2; }

// The hand weapon gains +3 to
// hit and +6 damage; missiles
// are +3 both.
inline int uappImpactHandHitBonus()
    { return 3; }

inline int uappImpactHandDamageBonus()
    { return 6; }

inline int uappImpactMissileHitBonus()
    { return 3; }

inline int uappImpactMissileDamageBonus()
    { return 3; }

// ---- the philter of beauty
// (the R396 clean read) ----
// +1 charisma (18 maximum) and
// +1 to +4 comeliness for the
// duration; if the effects wear
// off within sight of a
// creature influenced by the
// enhanced scores, that
// creature turns hostile and
// attacks.
inline int uappBeautyChaBonus()
    { return 1; }

inline int uappBeautyChaMax()
    { return 18; }

inline int uappBeautyComelinessLo()
    { return 1; }

inline int uappBeautyComelinessHi()
    { return 4; }

inline bool uappBeautyWearOffSightedHostile()
    { return true; }

// ---- the philter of
// glibness (the R396 clean
// read) ----
// The imbiber speaks fluently
// - even lies - smoothly and
// undetectably; magical
// investigation gives altered
// results, revealing only a
// minor stretching of the
// truth.
inline bool uappGlibSpeechUndetectable()
    { return true; }

inline bool uappGlibDetectLieShowsStretching()
    { return true; }

// ---- the philter of
// stammering and stuttering
// (the R396 clean read) ----
// Seems a beneficial draught
// (glibness or
// persuasiveness), but nothing
// meaningful can be said
// properly - spell verbal
// components, scroll text,
// conversation all fail - and
// hearers react at -25%.
inline bool uappStamSeemsBeneficial()
    { return true; }

inline bool uappStamMeaningfulSpeechFails()
    { return true; }

inline bool uappStamHitsSpellComponents()
    { return true; }

inline int uappStamReactionPenaltyPct()
    { return 25; }

// ---- the part ledger ----
// All nineteen descriptions
// pin - the R396 clean read
// filled the seven the
// extract garbled.
inline int uappPartCleanCount()
    { return 19; }

inline int uappPartGarbledCount()
    { return 0; }

}   // namespace rules

