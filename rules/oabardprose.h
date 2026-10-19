// =========================================================================================
// Adnd1 - rules/oabardprose.h
// BARDING PROSE, printed capture pp. 98-99 - the OA barding prose round
// census 570 -> 571.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the section -
// the barding prose cross-checked paragraph-by-paragraph between the two
// passes (the intro on capture p. 98, the AC-factor list on capture p. 99 of
// the print pass); every printed number agrees - zero contested cells. The
// AC-factor list pins: leather or padded adds 1 factor to the AC and weighs
// 160#, metal scale adds 2 factors and weighs 250#, chain adds 3 factors and
// weighs 350#. The half-barding doctrine pins as consts and bools: half
// barding weighs half the amount of full barding (the divisor 2), increases
// the AC for frontal attacks only, and attacks from the rear do not gain the
// AC bonus; half barding is more frequently used than full barding, and half
// covers the head, neck and forequarters while full covers the entire body
// (the coverage split rides the comments). The materials paragraph pins: the
// most common material is quilted and padded cotton, the others in descending
// order are leather, leather scale, brigandine, metal scale and chain mail
// (the order rides the comment), and plate barding is never used - as a rule
// barding is only used on the mounts of important nobles, generals and shock
// troops (the mounts-only rule rides the comment). The warhorse must be able
// to carry the barding weight in addition to the rider and any equipment -
// and the movement-rate reduction cross-references the Table 55 grid already
// pinned in R646. The armor descriptions box stays open - the last Chapter 5
// box
//
// the gap census after this round: 99 closed, 136 open - the Barding prose
// box flips (census 570 -> 571); NEXT - R649: the armor prose and armor
// descriptions box (capture pp. 93-98), the suits-and-pieces doctrine and the
// armor description entries, prefix dhj (verify free), audit "R649 OA armor
// descriptions audit", include after rules/oabardprose.h - the last Chapter 5
// box
//
namespace rules {

// ---- the barding prose pins ----

// the AC-factor list materials - leather or padded, metal scale and chain
// (capture p. 99 of the print pass; compressed p. 51)
inline int dhiBardingMatCount()
    { return 3; }

// leather or padded barding adds 1 factor to the AC (capture p. 99 of the
// print pass)
inline int dhiLeatherAcFactor()
    { return 1; }

// leather or padded barding weighs 160# (capture p. 99 of the print pass)
inline int dhiLeatherWeight()
    { return 160; }

// metal scale barding adds 2 factors to the AC (capture p. 99 of the print
// pass)
inline int dhiMetalAcFactor()
    { return 2; }

// metal scale barding weighs 250# (capture p. 99 of the print pass)
inline int dhiMetalWeight()
    { return 250; }

// chain barding adds 3 factors to the AC (capture p. 99 of the print pass)
inline int dhiChainAcFactor()
    { return 3; }

// chain barding weighs 350# (capture p. 99 of the print pass)
inline int dhiChainWeight()
    { return 350; }

// half barding weighs half the amount of full barding - the divisor 2
// (capture p. 99 of the print pass)
inline int dhiHalfWeightDiv()
    { return 2; }

// half barding is more frequently used than full barding - half covers the
// head, neck and forequarters while full covers the entire body (capture p.
// 98)
inline bool dhiHalfMoreCommon()
    { return true; }

// plate barding is never used - the most common material is quilted and
// padded cotton, the others in descending order leather, leather scale,
// brigandine, metal scale and chain mail (capture p. 98)
inline bool dhiPlateNeverUsed()
    { return true; }

// half barding increases the AC for frontal attacks only (capture p. 99 of
// the print pass)
inline bool dhiHalfFrontalOnly()
    { return true; }

// attacks from the rear do not gain the AC bonus (capture p. 99 of the print
// pass)
inline bool dhiRearNoBonus()
    { return true; }

// the warhorse must be able to carry the weight of the barding, in addition
// to that of the rider and any equipment; the movement-rate reduction is the
// Table 55 grid pinned in R646 (capture p. 99 of the print pass)
inline bool dhiMustCarryWeight()
    { return true; }

}   // namespace rules
