// ===========================================================================
// Adnd1 - rules/deities.h
// The DEITY LAYER SEAM (R405) - the
// last in-scope seam lands. The R404
// psionics precedent rides: the pins
// charge here, the Appendix S charge
// (the 23 deity stat blocks, the five
// clerical quick-reference charts)
// charges its own data round later;
// the engine has NO deity actor site
// today.
//
// The gated read: Appendix S, the
// NON-HUMAN DEITIES (pp. 109-122) -
// the Roger E. Moore material from
// DRAGON Magazine issues #58-63,
// reproduced as an adjunct to the
// Non-Human Deities section of
// Legends & Lore (formerly the
// DEITIES & DEMIGODS Cyclopedia).
//
// The census the clean djvu scan
// carries:
//   - 23 deity stat blocks across 5
//     pantheons: the dwarves 5
//     (Clanggedin Silverbeard,
//     Vergadain, Dumathoin, Abbathor,
//     Berronar), the elves 5 (Aerdrie
//     Faenya, Erevan Ilesere, Solonor
//     Thelandira, Hanali Celanil,
//     Labelas Enoreth), the halflings
//     4 (Sheela Peryroyl, Arvoreen,
//     Cyrrollalee, Brandobaris), the
//     gnomes 4 (Baervan
//     Wildwanderer, Urdlen, Segojan
//     Earthcaller, Flandal Steelskin),
//     the orcs 5 (Bahgtru, Shargaas,
//     Ilneval, Yurtrus, Luthic);
//   - the tiers: 5 greater (4 gods +
//     Berronar the greater goddess),
//     16 lesser (11 gods + 5
//     goddesses), 2 demigods
//     (Brandobaris, Flandal);
//   - the psionic ratings: 22 rating
//     lines - VI 10, III 5, IV 1
//     (Shargaas), Nil 6 - and one
//     block without a rating line
//     (Brandobaris, unrecorded).
//     NOTE: the deity ratings are the
//     Appendix S scale, NOT the PC
//     psionic chance of the R404 seam.
//
// The dwarven reads (pp. 109-110):
//   - the greater dwarven gods are at
//     least TWICE as large as normal
//     dwarves, ranging up to Moradin's
//     20-foot height; no dwarven deity
//     is taller than Moradin, the Soul
//     Forger - described in Legends &
//     Lore, invariably the ruler of
//     all dwarven pantheons;
//   - the holy symbols are invariably
//     NOT living objects (tools,
//     weapons, mountains, minerals) -
//     no animal and no dwarf is a
//     dwarven symbol;
//   - all dwarven gods possess DUAL
//     CHARISMAS, one applying to
//     dwarves and the dwarven deities,
//     the other to everyone else - the
//     CH:x(y) stat-line form (the
//     parenthesized value is the
//     comeliness side, the R322 seam:
//     Clanggedin prints CH:16(22),
//     CM:13(20));
//   - giant-type creatures attack
//     Clanggedin at a -4 penalty to
//     hit, the same as for mortal
//     dwarves.
//
// The five clerical quick-reference
// charts (pp. 121-122) print one row
// per deity (23 rows), each 8 columns:
// DEITY, SPHERE OF CONTROL, the
// RAIMENT head, body and color(s),
// HOLY DAYS, and the
// SACRIFICE/PROPITIATION frequency
// and form.
//
// The feeders the corpus already
// pinned:
//   0: R169 the humanoid racial
//      preferences (rules/humrpref.h -
//      the nine-race matrix: the orc
//      row carries no elf column, so
//      the Appendix S Gruumsh/Corellon
//      read - orcs hate elves more
//      than all other non-orc races -
//      is the sole cross-pantheon
//      site)
//   1: R322 the comeliness seam
//      (rules/comeliness.h - the
//      bands the parenthesized CM
//      values ride)
//   2: R323 the subrace layer
//      (rules/subraces.h - the four
//      demi-human pantheons map to
//      their subrace parents)
//   3: R404 the psionics seam
//      (rules/psionics.h - the PC
//      psionic reads stay PC-side:
//      the duergar doubled chance,
//      the svirfneblin ban)
// The R405 audit cross-checks every
// feeder live; the stat-block charge
// stays open.

#pragma once

namespace rules {

// ---- the layer contract ----
// The engine has no deity actor site
// (the pins precede any charge).
inline bool nhdDeitySiteExists()
    { return false; }

inline bool nhdPinsPrecedeSite()
    { return true; }

// The seam gates the Appendix S
// charge.
inline bool nhdGatesAppendixS()
    { return true; }

// The Appendix S charge (the 23
// stat blocks, the five charts) stays
// open after the seam lands.
inline bool nhdStatBlocksOpen()
    { return true; }

// ---- the source pins ----
// Appendix S, the NON-HUMAN DEITIES:
// pp. 109-122 of the print.
inline int nhdAppendixPageFirst()
    { return 109; }

inline int nhdAppendixPageLast()
    { return 122; }

// Moradin, the Soul Forger, is
// described in Legends & Lore, not
// here - invariably the ruler of all
// dwarven pantheons.
inline bool nhdMoradinInLegendsLore()
    { return true; }

// No dwarven deity is taller than
// Moradin's 20 feet.
inline int nhdMoradinHeightFeet()
    { return 20; }

// ---- the census pins ----
// The 23 deity stat blocks.
inline int nhdDeityCount()
    { return 23; }

// The five pantheons.
inline int nhdPantheonCount()
    { return 5; }

// The pantheon sizes: dwarves,
// elves, halflings, gnomes, orcs.
inline int nhdPantheonSize(int p) {
    static const int k[5] = {
        5, 5, 4, 4, 5
    };
    if (p < 0) p = 0;
    if (p > 4) p = 4;
    return k[p];
}

// The tiers: 5 greater (the four
// greater gods + Berronar the greater
// goddess), 16 lesser (11 gods + 5
// goddesses), 2 demigods (Brandobaris
// and Flandal).
inline int nhdGreaterDeityCount()
    { return 5; }

inline int nhdLesserDeityCount()
    { return 16; }

inline int nhdDemigodCount()
    { return 2; }

// The psionic rating census, by code
// index: 0 = VI, 1 = III, 2 = IV,
// 3 = Nil.
inline int nhdPsionicRatingCount(
        int code) {
    static const int k[4] = {
        10, 5, 1, 6
    };
    if (code < 0) code = 0;
    if (code > 3) code = 3;
    return k[code];
}

// One block carries no rating line:
// Brandobaris, unrecorded.
inline int nhdRatingUnrecordedCount()
    { return 1; }

// ---- the dwarven reads (pp. 109-110) ----
// The greater dwarven gods are at
// least twice as large as normal
// dwarves.
inline int nhdGreaterDwarfSizeMultiple()
    { return 2; }

// The holy symbols are invariably not
// living objects.
inline bool nhdDwarfSymbolNeverLiving()
    { return true; }

// All dwarven gods possess dual
// charismas - the CH:x(y) form.
inline bool nhdDwarfDeityDualCharisma()
    { return true; }

// Giant-types attack at -4 to hit -
// the same penalty as for mortal
// dwarves.
inline int nhdGiantTypeAttackPenalty()
    { return 4; }

// ---- the clerical charts (pp. 121-122) ----
// The five quick-reference charts,
// one per pantheon.
inline int nhdChartCount()
    { return 5; }

// Each chart row prints 8 columns:
// DEITY, SPHERE OF CONTROL, the
// RAIMENT head, body, color(s), HOLY
// DAYS, the SACRIFICE/PROPITIATION
// frequency and form.
inline int nhdChartColumnCount()
    { return 8; }

// ---- the feeder registry ----
inline int nhdFeederSeamCount()
    { return 4; }

// The feeder rounds, in registry
// order (0-3 above).
inline int nhdFeederRound(int i) {
    static const int k[4] = {
        169, 322, 323, 404
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

}   // namespace rules

