// =========================================================================================
// Adnd1 - rules/wsgrope.h
// The WSG USING ROPE FOR MOVEMENT AND CLIMBING, R440: the rope prose (no
// table this round) - characters are not expected to climb slopes or cliff
// faces relying only on the strength and dexterity of their hands and feet;
// certain equipment is available and often necessary for a severe slope or a
// cliff face, and the single most important equipment any climber can have is
// a coil of rope. The standard 50-foot coil is assumed somewhat smaller than
// half an inch in diameter and supports up to 1500 pounds without danger of
// fraying or breaking; if the limit is exceeded there is a 20 percent chance
// per turn (non-cumulative, while the strain remains) that it breaks; if it
// does not break, the cumulative chance it has become weakened from the
// stress is 10 percent after one turn, 30 after two, 60 after three and 100
// after four; a weakened rope breaks the next time it supports more than its
// limit at 40 percent per turn (non-cumulative) - the round continues the
// movement-across-special-terrain section. Census 364 -> 365.
// census 364 -> 365.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 36; the
// user own copy OCR cross-checked against the archive djvu word layer - the
// section reads CLEAN in the djvu, every number (the 50-foot coil, the 1500
// pounds, the 20 percent, the 10/30/60/100 ladder and the 40 percent) matched
// exactly; no eye-reads were needed.
//
// The standard 50-foot coil supports up to 1500 pounds without danger of
// fraying or breaking. Past the limit the break chance is 20 percent per turn
// non-cumulative; the weakening chance is cumulative - 10/30/60/100 percent
// by the turn of strain - and a weakened rope breaks at 40 percent per turn
// non-cumulative.
//
namespace rules {

// ---- the rope prose rules ----

// Characters are not expected to climb slopes or cliff faces while relying
// only on the strength and dexterity of their hands and feet.
inline bool wsrNotHandsAndFeetAlone()
    { return true; }

// Certain equipment is available (and often necessary) to assist a character
// in climbing a severe slope or a cliff face.
inline bool wsrEquipmentOftenNecessary()
    { return true; }

// The single most important equipment any climber can have is a coil of rope.
inline bool wsrRopeMostImportant()
    { return true; }

// The standard coil of rope is 50 feet long - the single most important
// equipment any climber can have.
inline int wsrCoilLengthFt()
    { return 50; }

// The standard 50-foot coil of rope is assumed to be somewhat smaller than
// half an inch in diameter.
inline bool wsrCoilUnderHalfInch()
    { return true; }

// A rope of the standard diameter can support up to 1500 pounds without being
// in danger of fraying or breaking.
inline int wsrMaxLoadLbs()
    { return 1500; }

// If the weight limit is exceeded, there is a 20 percent chance per turn
// (non-cumulative), while the strain remains on the rope, that it will break.
inline int wsrOverloadBreakPct()
    { return 20; }

// The overload break chance is per turn and non-cumulative, applying while
// the strain remains on the rope.
inline bool wsrOverloadBreakNonCumulative()
    { return true; }

// If the overloaded rope does not break, there is a 10 percent chance,
// cumulative per turn, that it has become weakened from the stress.
inline bool wsrWeakenCumulativePerTurn()
    { return true; }

// The cumulative chance a rope strained past its weight limit has become
// weakened, by turns of strain: 0 at the start, 10 percent after one turn, 30
// after two, 60 after three, 100 after four - and it stays 100 beyond that.
inline int wsrWeakenPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 30;
        case 3:
            return 60;
        case 4:
            return 100;
        default:
            return 100;
        }
    }

// The chance of a weakened rope breaking the next time it is used to support
// more than its weight limit is 40 percent per turn (non-cumulative).
inline int wsrWeakenedBreakPct()
    { return 40; }

// The weakened-rope break chance is per turn and non-cumulative, applying the
// next time the rope is used to support more than its weight limit.
inline bool wsrWeakenedBreakNonCumulative()
    { return true; }

}   // namespace rules
