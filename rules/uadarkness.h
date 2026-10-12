// ===========================================================================
// Adnd1 - rules/uadarkness.h
// The UA EFFECTS OF DARKNESS (p. 82 print) pins,
// R366: the combat to-hit ladder, the illumination
// exception, the converse read, the faerie fire
// conditions and the DM moderation closer.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The section prints clean - no OCR
// holes; the printed list markers garble (numbers 1,
// then bullets) - the four cases pin in the printed
// order.
// ===========================================================================

#pragma once

namespace rules {

// ---- the combat to-hit ladder ----
inline int uadkUnseenTargetToHitPenalty()
    { return 4; }

inline bool uadkUnseenIsAsInvisible()
    { return true; }

// If the opponent is vaguely discernible - a faint
// blur or a darker shape that stands out against the
// background - attacks are at -2 to hit.
inline int uadkVagueBlurToHitPenalty()
    { return 2; }

inline bool uadkVagueMeansDarkerShapeOnBackground()
    { return true; }

// ---- the illumination exception ----
// Combat is not affected by illumination (or lack
// thereof) in daylight or in the light conditions
// produced by most light-giving devices and spells -
// including torches, lanterns, light spells and
// continual light spells.
inline bool uadkDaylightAndDevicesUnaffected()
    { return true; }

inline bool uadkIncludesTorchLanternLightSpells()
    { return true; }

inline bool uadkIncludesContinualLight()
    { return true; }

// ---- the converse read ----
// The converse holds for creatures which function
// normally or at some relative advantage in darkness:
// infravision still sees opponents in the absence of
// visible-spectrum light, and creatures accustomed
// to operating in darkness suffer vision penalties
// when attacking opponents in illuminated conditions.
inline bool uadkConverseHoldsForDarkDwellers()
    { return true; }

inline bool uadkInfravisionWorksInNoVisibleLight()
    { return true; }

inline bool uadkDarkDwellerPenalizedInLight()
    { return true; }

inline bool uadkGrayDwarfCrossRef()
    { return true; }

inline bool uadkDarkElfDarkGnomeCrossRef()
    { return true; }

// ---- the faerie fire conditions ----
// Faerie fire benefits only when outlining opponents
// in poor lighting conditions (a dungeon area lit
// only by softly glowing magic weapons, or total
// darkness); in torch- or light-spell illumination
// (or anything stronger) it functions normally but
// contributes nothing to the visibility of the
// target.
inline bool uadkFaerieFireHelpsOnlyPoorLight()
    { return true; }

inline bool uadkFaerieFireWorksInTotalDarkness()
    { return true; }

inline bool uadkFaerieFireNoBenefitAtTorchLight()
    { return true; }

inline bool uadkFaerieFireFunctionsNormallyAnyway()
    { return true; }

// ---- the DM moderation closer ----
// Common sense must be the final determinant of
// whether an act is possible or whether a bonus or
// penalty applies; a warranted exception is within
// the DM's purview.
inline bool uadkDmCommonSenseFinalDeterminant()
    { return true; }

inline bool uadkDmMayWarrantException()
    { return true; }

}   // namespace rules

