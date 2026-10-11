// ===========================================================================
// Adnd1 - rules/uaclericspells6.h
// The UA NEW CLERIC SPELLS (p. 41) pins, R348: the 6th-level
// spell descriptions - forbiddance and heroes feast. Only two
// spells print at this level; the 7th (p. 42) pins next round.
// Pin-era pattern (R322): pinned data only - no engine site
// exists. The R341 continued table prints four 6th-level
// fragments (Conjure Animals, Find The Path, Speak With
// Monsters, Stone Tell) - neither of this round's two names
// seam-checks; they pin from the prose alone.
//
// JUDGMENTs (the decode method):
//   - the forbiddance name header never prints: the section
//     runs straight from "## Sixth Level Spells:" into
//     "Components: V, S, M". The spell is identified by its
//     near-verbatim 2e descendant ("This spell can be used to
//     secure a consecrated area... locked by a password",
//     good/evil weighing heavier than law/chaos) as
//     FORBIDDANCE, school Abjuration per the same source -
//     an external decode, flagged *Lost, pending the PDF.
//   - the digit-garble family (established R343, corroborated
//     each round since): the OCR prints 7 where 1 belongs in
//     the stat cells. This round's two 7s decode as 1, BOTH
//     corroborated: heroes feast casting "7 turn" = 1 turn
//     (the later editions print a 10-minute = 1-turn casting
//     time), and heroes feast duration "7 hour" = 1 hour
//     (the prose: "The feast takes one full hour to consume"
//     - the dweomer lasts the hour of the feast).
//   - the forbiddance stat cells carry genuine 6s (not the
//     family): Level 6, Range 3 inches, Casting Time 6
//     rounds, Area of Effect 6 cubic inches per level - the
//     level-matching pattern holds; pinned verbatim.
//   - the forbiddance AoE prints "6 cubic "/level" - the
//     stray straight quote is OCR noise for the inch mark;
//     decoded as 6 cubic inches per level (the game-scale
//     inch, as the range cells).
//   - the curly marks (established R343): the range cells
//     print 3 and 1 with the right double quote; the names
//     print the curly apostrophe (Heroes feast, the caster
//     spell's effect); the pins normalize to ASCII.
//   - the forbiddance prose carries two shattered regions:
//     (1) "Intruders who enter by making saving throws
//     will [?] uneasy and tense" - the verb lost; (2) the
//     material sentence: "In addition to the cler- / include
//     / water, / symbol, / and iron/sulfur" - decoded: in
//     addition to the cleric's [holy/unholy symbol], the
//     components include [holy/unholy] water, the symbol,
//     and iron/sulfur; both regions flagged, sense pinned.
//
// OCR holes (the item stays open - the 7th level pins next
// round; these stay pending the PDF): the forbiddance name
// and school header (externally decoded); the uneasy-verb
// fragment; the material-sentence fragment region.
// ===========================================================================

#pragma once

namespace rules {

// ---- forbiddance (Abjuration, decoded), p. 41 ----
// The name header never prints - identified by the
// near-verbatim 2e descendant text; school per the same.
inline const char* uac6ForbidName()
    { return "Forbiddance (Abjuration)"; }

inline bool uac6ForbidNameHeaderLost()
    { return true; }

inline bool uac6ForbidComponentsVSM()
    { return true; }

inline int uac6ForbidLevel()
    { return 6; }

inline int uac6ForbidRangeInches()
    { return 3; }

// A genuine 6, not the digit-garble family - the level
// pattern holds; pinned verbatim.
inline int uac6ForbidCastingTimeRounds()
    { return 6; }

inline bool uac6ForbidDurationPermanent()
    { return true; }

inline bool uac6ForbidSaveSpecial()
    { return true; }

// The AoE prints "6 cubic "/level" - the stray quote is
// noise for the inch mark.
inline int uac6ForbidAoeCubicInchesPerLevel()
    { return 6; }

// Usable only to secure a consecrated area (cf. the
// ceremony spell).
inline bool uac6ForbidRequiresConsecratedArea()
    { return true; }

inline bool uac6ForbidCfCeremonySpell()
    { return true; }

// The effect on the enchanted area is based on the ethics
// (law/chaos) and morals (good/evil) of those trying to
// enter it, relative to the caster's.
inline bool uac6ForbidBasedOnEthicsAndMorals()
    { return true; }

// Identical morals and ethics: cannot enter the area unless
// the password is known (no saving throw).
inline bool uac6ForbidIdenticalNeedsPassword()
    { return true; }

inline bool uac6ForbidIdenticalNoSave()
    { return true; }

// Different ethics: save versus spell to enter the area;
// if failed, take 2-12 points of damage.
inline bool uac6ForbidDiffEthicsSaveVsSpell()
    { return true; }

inline int uac6ForbidDiffEthicsDamageMin()
    { return 2; }

inline int uac6ForbidDiffEthicsDamageMax()
    { return 12; }

// Different morals: save versus spell to enter the area;
// if failed, take 4-24 points of damage.
inline bool uac6ForbidDiffMoralsSaveVsSpell()
    { return true; }

inline int uac6ForbidDiffMoralsDamageMin()
    { return 4; }

inline int uac6ForbidDiffMoralsDamageMax()
    { return 24; }

// Once a saving throw is failed, an intruder can never
// enter the forbidden area until the dweomer ceases.
inline bool uac6ForbidFailedSaveBarsEntry()
    { return true; }

// Effects are cumulative, and multiple required saving
// throws are certainly possible.
inline bool uac6ForbidEffectsCumulative()
    { return true; }

inline bool uac6ForbidMultipleSavesPossible()
    { return true; }

// The caster is immune to the spell's effect.
inline bool uac6ForbidCasterImmune()
    { return true; }

// Intruders who enter by making saving throws will [verb
// lost] be uneasy and tense, despite their success - the
// fragment region stays a hole.
inline bool uac6ForbidIntrudersUneasyTense()
    { return true; }

inline bool uac6ForbidUneasyVerbFragmentLost()
    { return true; }

// The shattered material sentence decoded: in addition to
// the cleric's symbol, the components include holy/unholy
// water, the symbol, and iron/sulfur.
inline bool uac6ForbidMaterialWaterSymbolIronSulfur()
    { return true; }

inline bool uac6ForbidMaterialFragmentLost()
    { return true; }

inline bool uac6ForbidSeamFragmentsOnly()
    { return true; }

// ---- heroes feast (Evocation), p. 41 ----
// The name prints the curly apostrophe; the pin normalizes
// to ASCII (the established decode).
inline const char* uac6FeastName()
    { return "Heroes' Feast (Evocation)"; }

inline bool uac6FeastComponentsVSM()
    { return true; }

inline int uac6FeastLevel()
    { return 6; }

inline int uac6FeastRangeInches()
    { return 1; }

// The casting time prints "7 turn" - the family decodes
// 1 turn, corroborated by the later editions' 10-minute
// (1-turn) casting time.
inline int uac6FeastCastingTimeTurns()
    { return 1; }

// The duration prints "7 hour" - the family decodes
// 1 hour, corroborated by the one-full-hour prose: the
// dweomer lasts the hour of the feast.
inline int uac6FeastDurationHours()
    { return 1; }

inline bool uac6FeastSaveNone()
    { return true; }

inline bool uac6FeastAoeOnePerLevel()
    { return true; }

// Enables the cleric to bring forth a great feast serving
// as many creatures as the cleric has levels of
// experience.
inline bool uac6FeastServesOnePerLevel()
    { return true; }

// The spell creates a magnificent table, chairs, service,
// and all the necessary food and drink.
inline bool uac6FeastCreatesTableService()
    { return true; }

// Those partaking are cured of all diseases.
inline bool uac6FeastCuresAllDiseases()
    { return true; }

// Immune to poison for 12 hours.
inline int uac6FeastPoisonImmunityHours()
    { return 12; }

// Healed of 5-8 points of damage after imbibing the
// nectar-like beverage.
inline int uac6FeastHealDamageMin()
    { return 5; }

inline int uac6FeastHealDamageMax()
    { return 8; }

// The ambrosia-like food equals a bless spell that lasts
// for 12 hours.
inline bool uac6FeastAmbrosiaEqualsBless()
    { return true; }

inline int uac6FeastBlessHours()
    { return 12; }

// During this period, the consumers are immune to fear,
// hopelessness, and panic.
inline bool uac6FeastImmuneFearHopePanic()
    { return true; }

// The feast takes one full hour to consume; the
// beneficial effects do not set in until after this hour
// is over.
inline int uac6FeastConsumeHours()
    { return 1; }

inline bool uac6FeastEffectsAfterTheHour()
    { return true; }

// If the feast is interrupted for any reason, the spell is
// ruined and all effects of the dweomer are negated.
inline bool uac6FeastInterruptRuinsAll()
    { return true; }

// The material: the holy/unholy symbol and specially
// fermented honey taken from the cells of bee larvae
// destined for royal status.
inline bool uac6FeastMaterialSymbolHoney()
    { return true; }

inline bool uac6FeastHoneyRoyalLarvae()
    { return true; }

// The R341 continued table: the 6th-level column prints
// four fragments (Conjure Animals, Find The Path, Speak
// With Monsters, Stone Tell) - neither of this round's
// two names seam-checks; they pin from the prose alone.
inline bool uac6SpellsPinFromProse()
    { return true; }

}   // namespace rules
