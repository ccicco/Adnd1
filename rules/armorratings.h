// rules/armorratings.h - the Armor Class table
// (the PHB COMBAT section ARMOR CLASS TABLE, R191).
//
// The printed ratings, every row: none 10,
// shield only 9, leather or padded 8; leather
// or padded + shield / studded leather / ring
// mail 7; studded leather or ring mail + shield /
// scale mail 6; scale mail + shield / chain mail
// 5; chain mail + shield / splint mail / banded
// mail 4; splint or banded mail + shield / plate
// mail 3; plate mail + shield 2. A shield makes
// the wearer one class better (one step).
//
// The magic rule: for each +1 of magic armor or
// magic shield a decrease in armor class of 1 is
// given, and a +1 converts to a 5% probability -
// +2 equals a 10% lesser likelihood of being hit.
// The print example: magic plate mail +3 and
// magic shield +5 are equal to AC -6 (3 - 3 - 1
// - 5), or AC 2 with a subtraction of 8 from
// attackers to hit dice rolls. A non-armored
// character with a +1 shield is AC 8, a +2
// shield AC 7.
//
// The printed notes: attacks from the right
// flank and rear always negate the advantage of
// the shield (the engine has no facing code -
// recorded here as the pin), and magic armor
// negates weight, so movement does not consider
// any encumbrance from magic armor.
//
// The verify (R191): the engine None row was 9
// against the printed 10 - repinned; the other
// nine armor rows verified cell for cell.

#ifndef RULES_ARMORRATINGS_H
#define RULES_ARMORRATINGS_H

namespace rules {

// The row count of the printed ladder (the
// per-type ratings; the shield composites read
// armorRatingAc - armorRatingShieldStep).
inline int armorRatingRowCount() { return 11; }

// The i-th row name of the printed ladder.
inline const char* armorRatingName(int i) {
    static const char* const kNames[11] = {
        "none",
        "shield only",
        "padded",
        "leather",
        "studded leather",
        "ring mail",
        "scale mail",
        "chain mail",
        "splint mail",
        "banded mail",
        "plate mail",
    };
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    return kNames[i];
}

// The i-th row base armor class of the
// printed ladder.
inline int armorRatingAc(int i) {
    static const int kAc[11] = {
        10,
        9,
        8,
        8,
        7,
        7,
        6,
        5,
        4,
        4,
        3,
    };
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    return kAc[i];
}

// A shield makes the wearer one class better
// (the printed composites: leather 8 with
// shield 7, plate 3 with shield 2).
inline int armorRatingShieldStep() { return 1; }

// Each +1 of magic armor or magic shield
// lowers the armor class by 1.
inline int armorRatingMagicAc(int plus) {
    if (plus < 0) plus = 0;
    return plus;
}

// The hit-probability form: a +1 converts to
// a 5% lesser likelihood of being hit.
inline int armorRatingMagicHitPct(int plus) {
    if (plus < 0) plus = 0;
    return 5 * plus;
}

// Attacks from the right flank and rear
// always negate the advantage of the shield.
inline bool armorRatingShieldNegatedFlankRear() {
    return true;
}

// Magic armor negates weight: movement does
// not consider any encumbrance from magic
// armor.
inline bool armorRatingMagicWeightless() {
    return true;
}

} // namespace rules

#endif // RULES_ARMORRATINGS_H
