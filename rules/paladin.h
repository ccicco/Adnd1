// ===========================================================================
// Adnd1 - rules/paladin.h
// The UA paladin re-parented under the
// cavalier (p. 16) pins (R329).
//
// Pin-era pattern (R322): pinned data only - no engine site exists. The
// paladin is no longer a sub-class of the fighter but of the cavalier:
// the requisites, the social-station gate and the 0-level track delegate
// to the R328 pins (rules/cavalier.h); the PHB powers ride the R184
// spell layers. The book's second column here is OCR-scrambled in the
// extract - the 0-level and no-prime reads are fragment-verified (the
// oracle documents each fragment); the retainer cross-reference is the
// DMG p. 75 read the gap report carries.
// ===========================================================================

#pragma once

#include "cavalier.h"  // the parent-class pins

namespace rules {

// ---- the re-parenting (p. 16) ----
inline bool paladinIsCavalierSubclass()
    { return true; }

// ---- the minima ----
// All the cavalier requisites (STR/DEX/CON 15,
// INT 10) plus wisdom 13 and charisma 17 or
// higher; the STR/DEX/CON/INT legs delegate to
// the R328 cavalierMinAbility.
inline int paladinWisdomMin()
    { return 13; }

inline int paladinCharismaMin()
    { return 17; }

inline int paladinMinAbility(int a) {
    if (a == ABILITY_WIS)
        return paladinWisdomMin();
    if (a == ABILITY_CHA)
        return paladinCharismaMin();
    return cavalierMinAbility(a);
}

// ---- the alignment gate ----
// Lawful good only; a straying paladin
// becomes a cavalier and is stripped of all
// special paladin powers.
inline bool paladinLawfulGoodOnly()
    { return true; }

inline bool paladinStrayBecomesCavalier()
    { return true; }

inline bool paladinStrayStripsPowers()
    { return true; }

// ---- the social station ----
// The correct social station or sponsorship
// by nobility; a sponsored paladin goes
// through the Horseman and Lancer 0 levels
// (the R328 cavalier track) before gaining
// the paladin abilities.
inline bool paladinSocialStationRequired()
    { return true; }

inline bool paladinSponsoredByNobility()
    { return true; }

inline bool paladinRidesZeroLevelTrack()
    { return true; }

inline int paladinZeroLevelHorsemanXp()
    { return cavalierHorsemanXp(); }

inline int paladinZeroLevelLancerXp()
    { return cavalierLancerXp(); }

// ---- the prime requisite ----
// A paladin, as a sub-class of the
// cavalier, has no prime requisite ability
// and gains no experience bonus; paladins
// take no weapon specialization (p. 14).
inline bool paladinNoPrimeRequisite()
    { return true; }

inline bool paladinSpecializationBanned()
    { return true; }

// ---- the cavalier charge (p. 16) ----
// The PHB powers and level advancement are
// unchanged; in addition the paladin gains
// the cavalier abilities.
inline bool paladinPhbPowersUnchanged()
    { return true; }

inline int paladinCavalierAbilityCount()
    { return 5; }

inline const char* paladinCavalierAbilityName(
        int i) {
    static const char* const k[5] = {
        "weapons of choice",
        "parrying ability", "horsemanship",
        "saving throw bonuses",
        "immunity to fear"
    };
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

// The paladin may increase charisma the
// same way the cavalier increases
// strength, dexterity and constitution
// (the R328 percentile growth).
inline bool paladinCharismaPercentileGrowth()
    { return true; }

// ---- the retainer read ----
// The paladin's retainer rules differ from
// the cavalier's (DMG p. 75); the follower
// tables ride the cavalier gap item.
inline bool paladinRetainerRulesDiffer()
    { return true; }

}   // namespace rules