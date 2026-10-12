// ===========================================================================
// Adnd1 - rules/uaspellcost.h
// The UA COST OF MAGIC-USER/ILLUSIONIST SPELL
// CASTING (p. 81 print) pins, R365.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The section prose prints clean; the
// one interleaved fragment (the danger clause) is
// noted in-header.
// ===========================================================================

#pragma once

namespace rules {

// ---- the basic fee ----
inline int uascFeePerSpellLevelGp()
    { return 200; }

inline bool uascWillingCasterWorksForFee()
    { return true; }

inline bool uascMaterialComponentsDoubled()
    { return true; }

inline bool uascComponentSubstitutionsAllowed()
    { return true; }

// ---- the surcharges ----
// Failing to furnish ordinary material components
// brings a surcharge of 10 percent or three times
// the component value, whichever is greater.
inline int uascOrdinarySurchargePercent()
    { return 10; }

inline int uascOrdinarySurchargeValueMultiple()
    { return 3; }

inline int uascExtraordinarySurchargePercent()
    { return 100; }

inline int uascExtraordinaryValueMultiple()
    { return 3; }

inline bool uascSurchargeWhicheverIsGreater()
    { return true; }

// ---- the danger and aging clauses ----
inline bool uascDangerSpellsAtLeastDoubleFee()
    { return true; }

inline bool uascDangerGuaranteesRequired()
    { return true; }

inline bool uascDangerClauseInterleaved()
    { return true; }

inline bool uascAgingSpellsNeedCounterFirst()
    { return true; }

inline bool uascInsignificantAgingException()
    { return true; }

// The printed example: a young elf unconcerned
// about aging 5 years, though a fee of ten times
// normal might be charged.
inline int uascElfExampleAgingYears()
    { return 5; }

inline int uascElfExampleFeeMultiple()
    { return 10; }

// ---- the payment reads ----
inline bool uascMagicItemAcceptedInLieuOfCash()
    { return true; }

inline bool uascItemValueAdjustedByReaction()
    { return true; }

inline bool uascNpcCharacterAffectsCosts()
    { return true; }

// ---- the hostile caster reads ----
inline bool uascHostileAtLeastDoubleFee()
    { return true; }

inline bool uascHostileMayRefuseEntirely()
    { return true; }

inline bool uascHostileMayBeBribedWithItem()
    { return true; }

inline bool uascGoodUnlikelyToCastForEvil()
    { return true; }

inline bool uascDuressUsesDmgRules()
    { return true; }

}   // namespace rules

