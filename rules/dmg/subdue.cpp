// R-refactor: split from subdue.h - definitions
#include "rules/dmg/subdue.h"

int Subdue::subdualTemporaryPct() { return 75; }

int Subdue::subdualRealPct() { return 25; }

int Subdue::subdualRealDamage(int cumulativeSubdualHp) {
    if (cumulativeSubdualHp <= 0) return 0;
    return cumulativeSubdualHp / 4;
}

bool Subdue::subdualEffectiveAgainst(bool mmStatedOrHumanoid, bool isPlayerCharacter) {
    if (isPlayerCharacter) return false;
    return mmStatedOrHumanoid;
}

bool Subdue::subdualKnockout(int cumulativeSubdualHp, int remainingHp) {
    if (remainingHp <= 0) return true;
    return cumulativeSubdualHp >= remainingHp;
}

bool Subdue::dragonSubduable(DragonSubdualKind k) {
    switch (k) {
        case DRAGON_BRASS:
        case DRAGON_BRONZE:
        case DRAGON_COPPER:
            return true;
        default:
            return false;
    }
}

bool Subdue::subduableByAttackerInt(int intelligence) {
    return intelligence >= 9;
}

bool Subdue::subdualFormIsKilling(bool announcedBeforeCombat) {
    return !announcedBeforeCombat;
}

int Subdue::dragonSubdualPercent(int cumulativeSubdualHp, int dragonHp) {
    if (dragonHp <= 0) return 100;
    return (100 * cumulativeSubdualHp + dragonHp / 2)
           / dragonHp;
}

bool Subdue::dragonSubdued(Dice& dice, int cumulativeSubdualHp, int dragonHp) {
    if (dragonHp > 0 && cumulativeSubdualHp >= dragonHp)
        return true;
    int pct = dragonSubdualPercent(cumulativeSubdualHp,
                                   dragonHp);
    int roll = (int)dice.roll(1, 100, 0);
    return roll <= pct;
}

int Subdue::subduedDragonPricePerHp(Dice& dice) {
    return 100 * (int)dice.d8();
}

bool Subdue::subduedDragonRideable() { return true; }
