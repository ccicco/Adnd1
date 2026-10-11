// ===========================================================================
// Adnd1 - rules/weaponspec.h
// The UA weapon specialization prose
// (pp. 18-19) pins (R331).
//
// Pin-era pattern (R322): pinned data only - no engine site exists. The
// creation-flow gate rides a later round; the R328 cavalier exclusion
// pin carries the exclusion read.
//
// The Weapon Specialization Table: the
// column titles, the three level bands
// and six cleanly readable cells are
// pinned (weaponSpecTableCellKnown).
// The other eighteen cells are
// OCR-mangled in the extract (the
// fractions lost their slashes and
// digits: "21", "mn", "3n", "an",
// "4an", "51", "2n", "312", "81") with
// no consistent decode - they read
// empty, documented here and in the gap
// report item, which stays OPEN until
// the PDF read. The 1-6 row's light-
// crossbow cell is blank in the
// extract. The crossbow medium-range
// read (+1 hit, no damage bonus) is
// fragment-verified in the scrambled
// tail (the R329 discipline).
// ===========================================================================

#pragma once

#include "subraces.h"  // UaClass (the 14)

namespace rules {

// ---- the class gate (p. 18) ----
// Fighters and rangers only; one
// weapon chosen; the decision made
// when the character is initially
// created.
inline bool weaponSpecClassAllowed(UaClass c) {
    return c == UACLASS_FIGHTER
        || c == UACLASS_RANGER;
}

inline bool weaponSpecAtCreationOnly()
    { return true; }

// ---- the slot costs (p. 18) ----
// Specialization counts as two
// proficiency slots: a fighter takes it
// plus two other weapons of the initial
// four; a ranger takes it plus a single
// proficiency. A bow (other than a
// crossbow) costs a third slot: the
// fighter keeps one other weapon, the
// ranger none.
inline int weaponSpecSlots()
    { return 2; }

inline int weaponSpecFighterOtherProficiencies()
    { return 2; }

inline int weaponSpecRangerProficiencies()
    { return 1; }

inline int weaponSpecBowExtraSlot()
    { return 1; }

inline int weaponSpecFighterBowOthers()
    { return 1; }

inline int weaponSpecRangerBowOthers()
    { return 0; }

// ---- the melee benefits (p. 18) ----
// +1 to hit, +2 to damage, on top of
// strength and magic; the weapon must
// be a specific type (long sword, not
// sword); the table's additional
// attacks override the Attacks Per
// Melee Round Table.
inline int weaponSpecMeleeToHitBonus()
    { return 1; }

inline int weaponSpecMeleeDamageBonus()
    { return 2; }

inline bool weaponSpecSpecificTypeRequired()
    { return true; }

inline bool weaponSpecExtraAttacks()
    { return true; }

// ---- the bow point blank (p. 18) ----
// Long, short or composite bow:
// 6"-30", +2 to hit and damage, double
// damage on a hit (6-16 for a
// non-magical arrow); the nocked-arrow
// pre-initiative shot; short range
// runs from 30" to the bow's medium
// lower limit, +1 to hit and damage.
inline int weaponSpecBowPointBlankMin()
    { return 6; }

inline int weaponSpecBowPointBlankMax()
    { return 30; }

inline int weaponSpecBowPointBlankBonus()
    { return 2; }

inline bool weaponSpecBowDoubleDamage()
    { return true; }

inline int weaponSpecArrowDamageLow()
    { return 6; }

inline int weaponSpecArrowDamageHigh()
    { return 16; }

inline bool
weaponSpecNockedArrowPreInitiative()
    { return true; }

inline int weaponSpecBowShortRangeFrom()
    { return 30; }

inline int weaponSpecBowShortRangeBonus()
    { return 1; }

// ---- the crossbow point blank (p. 19)
// ----
// 6'-60' (overtaking a light crossbow's
// short range in the dungeon); +2 to
// hit and damage; double damage (6-12
// for a light bolt); +1 to hit and
// damage at short range; at medium +1
// to hit but no damage bonus
// (fragment-verified); the rate-of-fire
// increase depends on light vs heavy;
// the free shot before initiative if
// cocked and aimed.
inline int weaponSpecCrossbowPointBlankMin()
    { return 6; }

inline int weaponSpecCrossbowPointBlankMax()
    { return 60; }

inline int
weaponSpecCrossbowPointBlankBonus()
    { return 2; }

inline bool
weaponSpecCrossbowDoubleDamage()
    { return true; }

inline int weaponSpecLightBoltDamageLow()
    { return 6; }

inline int weaponSpecLightBoltDamageHigh()
    { return 12; }

inline int weaponSpecCrossbowShortBonus()
    { return 1; }

inline int
weaponSpecCrossbowMediumHitBonus()
    { return 1; }

inline int
weaponSpecCrossbowMediumDamageBonus()
    { return 0; }

inline bool weaponSpecCrossbowFreeShot()
    { return true; }

// ---- the other missiles (p. 19) ----
inline int
weaponSpecOtherMissileToHitBonus()
    { return 1; }

inline int
weaponSpecOtherMissileDamageBonus()
    { return 2; }

// ---- the double specialization (p. 19)
// ----
// Melee weapons only, excluding pole
// arms and the two-handed sword; taken
// instead of a proficiency when the
// character qualifies for a new weapon;
// only in the already-specialized
// weapon; +3 to hit and +3 to damage.
inline bool weaponSpecDoubleAllowed()
    { return true; }

inline bool weaponSpecDoubleMeleeOnly()
    { return true; }

inline int weaponSpecDoubleToHitBonus()
    { return 3; }

inline int weaponSpecDoubleDamageBonus()
    { return 3; }

// ---- the final note (p. 19) ----
// The bonuses are not magical (no
// effect on magic-only creatures); a
// magic weapon of the specialized type
// stacks its bonuses with the
// specialization bonuses.
inline bool weaponSpecBonusesNotMagical()
    { return true; }

inline bool weaponSpecMagicStacks()
    { return true; }

// ---- the Weapon Specialization Table
// (p. 19) ----
// Eight columns (melee, bow, light
// crossbow, heavy crossbow, lasso and
// staff sling, thrown dagger, thrown
// dart, other missiles and hurled
// weapons), three level bands. Only the
// cleanly readable cells are pinned
// (below); the mangled cells read empty
// pending the PDF.
inline int weaponSpecTableColumnCount()
    { return 8; }

inline const char* weaponSpecTableColumnName(
        int i) {
    static const char* const k[8] = {
        "Melee Weapon", "Bow",
        "Light Crossbow", "Heavy Crossbow",
        "Lasso and Staff Sling",
        "Thrown Dagger", "Thrown Dart",
        "Other Missiles and Hurled"
        " Weapons"
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

inline int weaponSpecTableBandLow(int b) {
    static const int k[3] = {1, 7, 13};
    if (b < 0) b = 0;
    if (b > 2) b = 2;
    return k[b];
}

inline int weaponSpecTableBandHigh(int b) {
    // band 0: 1-6; band 1: 7-12;
    // band 2: 13+ (no upper bound;
    // returns 0 to mean open)
    static const int k[3] = {6, 12, 0};
    if (b < 0) b = 0;
    if (b > 2) b = 2;
    return k[b];
}

// The cleanly readable cells: melee and
// other-missiles 3/2 at 1-6 and 5/2 at
// 13+; light crossbow and lasso/staff
// sling 3/2 at 7-12. Every other cell
// (and the 1-6 light-crossbow cell,
// blank in the extract) reads empty -
// the OCR-lost fraction cells
// (documented in the header comment).
inline const char* weaponSpecTableCellKnown(
        int band, int col) {
    if (band == 0 && col == 0) return "3/2";
    if (band == 0 && col == 7) return "3/2";
    if (band == 1 && col == 2) return "3/2";
    if (band == 1 && col == 4) return "3/2";
    if (band == 2 && col == 0) return "5/2";
    if (band == 2 && col == 7) return "5/2";
    return "";
}

}   // namespace rules