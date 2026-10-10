// ====================================================================
// Adnd1 - rules/swimcross.h
// R312: the DMG surface SWIMMING
// paragraph (the R311 pins,
// rules/underwater.h) WIRED as the
// flooded crossing - the first ENGINE
// site the underwater data charges.
//
// The print (the SWIMMING note before
// UNDERWATER ADVENTURES): swimming is
// impossible in any metal armor except
// magic armor (the dog paddle the only
// stroke possible); leather and padded
// armor swim with a 5 percent drown
// chance per hour, +2 percent per 5
// pounds of possessions beyond the
// armor. The engine counts the worn
// armor OUT of the load (1 pound = 10
// g.p. of weight, the engine unit), and
// a water entry is a crossing, so the
// per-hour percent condenses to ONE
// roll per living member per entry (the
// JUDGMENT; the print carries no
// per-entry count).
//
// The site: one flooded pool per delve
// (the R304 one-per-delve convention;
// the count JUDGMENT), a 2-3 by 2-3 tile
// sheet of open floor clear of the
// stairs and the entry. The underwater
// MOVEMENT, VISION and COMBAT paragraphs
// stay data (no underwater combat layer
// exists - a future seam); the spell
// lists ride R168 (rules/uwspells.h).
//
// The armor ids read plain ints (the
// items::ArmorId order): 0 none, 1
// padded, 2 leather, 3 studded, 4 ring,
// 5 scale, 6 chain, 7 splinted, 8 banded,
// 9 plate. Studded leather reads METAL
// (the studs; the JUDGMENT - the engine
// ARMOR_LEATHER weight class is the
// class-restriction grain, not the swim
// gate).
// ====================================================================

#pragma once

namespace rules {

// The armor swim gate: 1 when the armor
// swims (none, padded, leather), 0 when
// the metal armors bar the water.
inline int swimArmorSwims(int armorId) {
    return armorId <= 2 ? 1 : 0;
}

// Magic armor excepts the metal ban (the
// dog paddle the only stroke possible).
inline int swimMagicArmorSwims() {
    return 1;
}

// The crossing gate: enchanted armor dog
// paddles, plain armor reads the metal
// ban.
inline int swimCanSwim(int armorId, int armorPlus) {
    return armorPlus > 0 ? swimMagicArmorSwims()
                         : swimArmorSwims(armorId);
}

// The load beyond the worn armor, in
// pounds (1 pound = 10 g.p.; the print
// counts the possessions BEYOND the
// armor), the negatives clamped.
inline int swimLoadBeyondArmorLbs(int carriedGp,
                                  int armorGp) {
    int lbs = (carriedGp - armorGp) / 10;
    if (lbs < 0) lbs = 0;
    return lbs;
}

// The drown roll cadence: one roll per
// living member per water entry (the
// JUDGMENT - the per-hour print percent
// condensed to the crossing).
inline int swimDrownRollPerCrossing() {
    return 1;
}

// The flooded pool count: one per delve
// (the R304 one-per-delve convention; the
// JUDGMENT).
inline int floodPerDelveCount() {
    return 1;
}

// The pool side floor: 2-3 tiles a side
// (the JUDGMENT).
inline int floodSideMin() {
    return 2;
}

inline int floodSideMax() {
    return 3;
}

}  // namespace rules
