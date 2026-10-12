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
// seven garbled descriptions
// (acid resistance,
// disenchantment, elemental,
// impact, the philters of
// beauty and glibness,
// stammering) await the PDF -
// the gap item stays open. The
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

// ---- the part ledger ----
// Twelve of the nineteen
// descriptions pin; the seven
// garbled ones stay PDF-gated.
inline int uappPartCleanCount()
    { return 12; }

inline int uappPartGarbledCount()
    { return 7; }

}   // namespace rules

