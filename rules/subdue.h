// ====================================================================
// Adnd1 - rules/subdue.h
// R159: striking to subdue - the knockout procedure and
// subdual damage accounting (DMG p.67), plus the MM
// dragon-subdual capture mechanics.
//
// Header-only (the grenade.h pattern): the caller
// announces intent and carries the cumulative tally.
//
// DMG p.67 print:
//   - Subdual strikes use the flat, butt, haft, pommel or
//     other non-lethal parts of the weapon concerned, but
//     are otherwise the same as other attacks.
//   - Effective against monsters the MONSTER MANUAL states
//     (under DRAGONS) or herein, and creatures of humanoid
//     size and type.
//   - NOT against player characters (unless expressly
//     stated otherwise).
//   - 75% of subduing damage is temporary; 25% is real
//     damage. The print example: 40 hit points of subduing
//     damage = 10 hit points actually suffered.
//   JUDGMENT: the knockout - the creature is subdued when
//   cumulative subduing damage meets or exceeds its
//   remaining hit points (the standard reading; the print
//   implies but does not state the threshold).
//
// MM dragon subdual:
//   - The attack form (kill or subdue) is announced before
//     combat; unannounced reads as killing, and the choice
//     cannot change for a given dragon.
//   - Silver, gold, chromatic and platinum dragons cannot
//     be subdued (the MM names them; brass, bronze and
//     copper dragons can).
//   - Creatures of less than average intelligence cannot
//     attack to subdue. JUDGMENT: average = 9 (the MM
//     ability score spread).
//   - Each melee round the cumulative subduing damage is
//     ratioed over the dragon hit points as a percentage;
//     percentile dice equal or under subdue. 100% (the
//     ratio at or past 1:1) is automatic. The MM example
//     rounds: 44/88 = 50%, 67/88 = 76%, 77/88 = 87.5
//     treated as 88% - halves round up, otherwise nearest.
//   - Sale price of a subdued dragon: 100-800 gold pieces
//     per hit point, offers typically by d8 (JUDGMENT:
//     100 x d8). Subdued dragons can be ridden; the length
//     of subdual and loyalty factors are caller-side.
// ====================================================================

#pragma once

#include "dice.h"

namespace rules {

// ----------------------------------------------------------------------------
// The DMG p.67 accounting
// ----------------------------------------------------------------------------
inline int subdualTemporaryPct() { return 75; }
inline int subdualRealPct()     { return 25; }

// Real damage actually suffered from CUMULATIVE subdual
// damage: the quarter, floored (per-hit minimums would
// over-penalize small strikes; the print ratios the total).
inline int subdualRealDamage(int cumulativeSubdualHp) {
    if (cumulativeSubdualHp <= 0) return 0;
    return cumulativeSubdualHp / 4;
}

// Applicability: an MM-stated monster, or a creature of
// humanoid size and type. Player characters are excluded
// unless a rule expressly states otherwise.
inline bool subdualEffectiveAgainst(bool mmStatedOrHumanoid,
                                   bool isPlayerCharacter) {
    if (isPlayerCharacter) return false;
    return mmStatedOrHumanoid;
}

// JUDGMENT: the knockout - cumulative subduing damage at
// or past the remaining hit points subdues the creature.
inline bool subdualKnockout(int cumulativeSubdualHp,
                            int remainingHp) {
    if (remainingHp <= 0) return true;
    return cumulativeSubdualHp >= remainingHp;
}

// ----------------------------------------------------------------------------
// The MM dragon rules
// ----------------------------------------------------------------------------
enum DragonSubdualKind {
    DRAGON_BRASS = 0,
    DRAGON_BRONZE,
    DRAGON_COPPER,
    DRAGON_WHITE,
    DRAGON_BLACK,
    DRAGON_GREEN,
    DRAGON_BLUE,
    DRAGON_RED,
    DRAGON_SILVER,
    DRAGON_GOLD,
    DRAGON_PLATINUM,
    DRAGON_KIND_COUNT
};

// Silver, gold, chromatic (white/black/green/blue/red) and
// platinum cannot be subdued - the MM print; brass,
// bronze and copper can.
inline bool dragonSubduable(DragonSubdualKind k) {
    switch (k) {
        case DRAGON_BRASS:
        case DRAGON_BRONZE:
        case DRAGON_COPPER:
            return true;
        default:
            return false;
    }
}

// Attackers of less than average intelligence cannot
// strike to subdue. JUDGMENT: average = 9.
inline bool subduableByAttackerInt(int intelligence) {
    return intelligence >= 9;
}

// The attack form must be announced before combat;
// unannounced reads as killing, and the form cannot change
// for a given target. The caller carries the flag.
inline bool subdualFormIsKilling(bool announcedBeforeCombat) {
    return !announcedBeforeCombat;
}

// The percent chance: cumulative subduing damage over
// the dragon hit points, as a percentage rounded to
// nearest with halves up (the MM example: 67/88 = 76,
// 77/88 = 88, 44/88 = 50).
inline int dragonSubdualPercent(int cumulativeSubdualHp,
                                int dragonHp) {
    if (dragonHp <= 0) return 100;
    return (100 * cumulativeSubdualHp + dragonHp / 2)
           / dragonHp;
}

// The percentile roll: equal or under the percent
// subdues; 100% (cumulative >= hit points) is automatic.
inline bool dragonSubdued(Dice& dice, int cumulativeSubdualHp,
                           int dragonHp) {
    if (dragonHp > 0 && cumulativeSubdualHp >= dragonHp)
        return true;
    int pct = dragonSubdualPercent(cumulativeSubdualHp,
                                   dragonHp);
    int roll = (int)dice.roll(1, 100, 0);
    return roll <= pct;
}

// The sale price per hit point: 100-800 gp by d8.
inline int subduedDragonPricePerHp(Dice& dice) {
    return 100 * (int)dice.d8();
}

// Subdued dragons can be ridden.
inline bool subduedDragonRideable() { return true; }

} // namespace rules
