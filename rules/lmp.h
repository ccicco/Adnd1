// =========================================================================================
// Adnd1 - rules/lmp.h
// THE LAMMASU PROMOTION - THE GREATER LAMMASU DEF (MM2 print p. 79: the stat
// block the R808 LMN walk never promoted, the two-voice move settle 15/30 MC
// B), the QUEUED-DISCOVERY round - the 2 keyless R817 outdoor cells rewire,
// the registry 809 -> 810, no gap boxes flip - the MM2 arc gap stays 37
// closed 0 open
// census 742 -> 743.
//
// Round twenty-five of the MM2 arc, the promotion seam round (Curtiss Go call
// lammasu on the landed R819 index walk; one def promoted, the 2 outdoor
// cells rewired, the walk-key census 570 -> 572)
//
// The pin header stays the print-fidelity record; the def carries the p. 79
// stat block, the rewire rides the file patches, and the walk cross-checks
// the def and the cells live
//
namespace rules {

// ---- the R820 census ----

// The lammasu promotion round: the queued R817 discovery closed (Curtiss Go
// call lammasu on the landed R819)
inline int lmpRound()
    { return 820; }

// The MM2 print folio of the Lammasu, Greater stat block (between the kraken
// and the land lamprey)
inline int lmpPrintPage()
    { return 79; }

// The stat block armor class
inline int lmpStatArmorClass()
    { return 3; }

// The stat block hit dice
inline int lmpStatHitDice()
    { return 12; }

// The stat block hit dice bonus (12+7)
inline int lmpStatHitDiceBonus()
    { return 7; }

// The book-average hit points (12 x 4.5 + 7)
inline int lmpStatAvgHp()
    { return 61; }

// The stat block attacks (2 for 2-12/2-12)
inline int lmpStatNumAttacks()
    { return 2; }

// The level VIII base XP
inline int lmpStatXp()
    { return 3950; }

// The per-hit-point XP
inline int lmpStatXpPerHp()
    { return 18; }

// The full kill XP (3950 + 18 x 61)
inline int lmpStatXpValue()
    { return 5048; }

// The stat block magic resistance (40%)
inline int lmpStatMagicResistance()
    { return 40; }

// The 50 percent that can speak a holy word
inline int lmpHolyWordPct()
    { return 50; }

// The protection from evil radius (20-foot, double effect)
inline int lmpProtectionRadius()
    { return 20; }

// The clerical spell usage is of 5th-level ability (5/4/3/2/1 spells)
inline int lmpClericalSpellLevel()
    { return 5; }

// The spell-like ability level (as hit dice)
inline int lmpSpellAbilityLevel()
    { return 12; }

// They typically dwell with 6 or more ordinary lammasu
inline int lmpPrideSize()
    { return 6; }

// The registry def count before the promotion
inline int lmpRegistryBefore()
    { return 809; }

// The registry def count after the promotion
inline int lmpRegistryAfter()
    { return 810; }

// The MM2 defs before the promotion
inline int lmpMm2DefsBefore()
    { return 331; }

// The MM2 defs after the promotion
inline int lmpMm2DefsAfter()
    { return 332; }

// The 2 keyless R817 outdoor cells rewired to the new key (the temperate
// civilized plains die 2, the tropical civilized hills die 20)
inline int lmpCellsRewired()
    { return 2; }

// The temperate civilized plains grid index (grid 22, the die 2 cell)
inline int lmpGridTC5Index()
    { return 22; }

// The tropical civilized hills grid index (grid 31, the die 20 cell)
inline int lmpGridRC2Index()
    { return 31; }

// The R817 walk-key census before the rewire
inline int lmpWalkKeyRowsBefore()
    { return 570; }

// The R817 walk-key census after the rewire (the header const and the audit
// expression both ride this round)
inline int lmpWalkKeyRowsAfter()
    { return 632; }

// ---- the opening doctrine (the R820 census) ----

// The def promoted from the MM2 print (the xpSource mm2_print class, the
// R797-R819 promotion seam)
inline bool lmpPromotedFromMM2Print()
    { return true; }

// The move stat settled by two voices: the djvu OCR garble (the 5V3Q read)
// against the 1eonline and compendium reads (15/30, MC B)
inline bool lmpMoveSettledByTwoVoices()
    { return true; }

// The stat block carries nil treasure and nil lair percentage
inline bool lmpNilTreasureAndLair()
    { return true; }

// The stat block alignment lawful good, intelligence supra-genius, size L (5
// at the shoulder)
inline bool lmpLawfulGoodSupraGenius()
    { return true; }

// The greater lammasu travel the Astral and Ethereal Planes at will
inline bool lmpAstralEtherealTravel()
    { return true; }

// They become invisible, dimension door, and teleport without error at will
// (1 at a time, 1 per round)
inline bool lmpInvisibleDimensionDoorTeleport()
    { return true; }

// The cures are double strength and based on 1d6+1 (cure light wounds 4-14,
// cure serious wounds 8-28)
inline bool lmpCuresDoubleStrength()
    { return true; }

// The rewired cells keep their src 2 cells (the R817 source census unchanged)
inline bool lmpSourceCellsUnchanged()
    { return true; }

// The R817-R819 registry-floor consts stand as their own round snapshots (the
// >= floor checks stay green)
inline bool lmpFloorConstsStaySnapshots()
    { return true; }

// No gap boxes flip this round (the MM2 arc gap stays 37 closed 0 open)
inline bool lmpNoGapBoxesFlip()
    { return true; }

}   // namespace rules
