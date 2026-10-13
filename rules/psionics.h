// ===========================================================================
// Adnd1 - rules/psionics.h
// The PSIONICS SEAM (R404) - the
// deferred engine seam lands. The
// R403 mount precedent rides: the
// pins charge here, the
// psionic-combat charge (the
// psionic potential roll, the
// attack and defense modes, the
// point economy) charges the
// engine later; the engine has NO
// psionic site today.
//
// The gated reads: the PHB psionic
// sections stay OPEN (the
// phb_gap report carries them);
// the DMG p.77 PSIONIC COMBAT
// (IV.A and following) stays OUT
// - the recorded R104-era scope
// decision - until the seam
// charges.
//
// The UA expansion pins (pp. 10-11,
// the clean djvu scan):
//   - the duergar: not all player
//     character duergar have psionic
//     ability; they have TWICE the
//     usual chance of being psionic
//     (double all bonuses for
//     intelligence, wisdom and
//     charisma) if psionics are
//     used in the campaign;
//   - the svirfneblin: player
//     character deep gnomes do NOT
//     have psionic abilities.
// The feeders the corpus already
// pinned:
//   0: R166 the insanity seam
//      (rules/insanity.h - the four
//      MILD forms subject to psionic
//      attack, the duration classes)
//   1: R323 the subrace layer
//      (rules/subraces.h - the
//      svirfneblin noPsionics trait)
//   2: R328 the cavalier mind
//      powers (rules/cavalier.h - the
//      90 percent resistance, the
//      psionic mind blast roster
//      entry)
// The R404 audit cross-checks every
// feeder live; the charge stays
// open.

#pragma once

namespace rules {

// ---- the layer contract ----
// The engine has no psionic site
// (the pins precede any charge).
inline bool psxPsionicSiteExists()
    { return false; }

inline bool psxPinsPrecedeCharge()
    { return true; }

// The seam gates the psionic
// expansions.
inline bool psxGatesPsionicExpansions()
    { return true; }

// The psionic-combat charge (the
// potential roll, the modes, the
// point economy) stays open after
// the seam lands.
inline bool psxPsionicChargeOpen()
    { return true; }

// ---- the open and OUT records ----
// The PHB psionic sections stay
// OPEN (the phb_gap report).
inline bool psxPhbSectionsOpen()
    { return true; }

// The DMG psionic combat rides p.
// 77 (IV.A and following) and stays
// OUT - the recorded scope decision.
inline int psxDmgPsionicCombatPage()
    { return 77; }

inline bool psxDmgCombatOutOfScope()
    { return true; }

// ---- the duergar pin (UA p. 10) ----
// Not all player character duergar
// have psionic ability.
inline bool psxDuergarNotAllPsionic()
    { return true; }

// Twice the usual chance of being
// psionic - if psionics are used in
// the campaign.
inline int psxDuergarChanceMultiple()
    { return 2; }

// The doubling reads all three
// bonuses: intelligence, wisdom and
// charisma.
inline bool psxDuergarDoublesIntWisCha()
    { return true; }

inline bool psxDuergarDoubledOnlyIfUsed()
    { return true; }

// The doubled bonus arithmetic: the
// usual psionic bonus doubles.
inline int psxDuergarDoubledBonus(
        int bonus) {
    return psxDuergarChanceMultiple()
           * bonus;
}

// ---- the svirfneblin pin (UA p. 11) ----
inline bool psxSvirfneblinPcNoPsionics()
    { return true; }

// ---- the feeder registry ----
inline int psxFeederSeamCount()
    { return 3; }

// The feeder rounds, in registry
// order (0-2 above).
inline int psxFeederRound(int i) {
    static const int k[3] = {
        166, 323, 328
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

}   // namespace rules

