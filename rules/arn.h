// =========================================================================================
// Adnd1 - rules/arn.h
// The Aronson illusionist deltas - mighty magic miscellany (folios 23-25):
// the 11th-14th XP progression, the manufacture thresholds, the +4 illusion
// save, and the Prismatic Spray two-color mechanic
// census 811 -> 812.
//
// Pinned from The Dragon Vol. 1 No. 1 (June 1976): folio 23, Peter Aronson's
// Mighty Magic Miscellany - the Illusionist Additions; folio 25, the
// Prismatic Spray explanation and the two manufacture/save notes. The voice
// rides extract/dragon/001/. DELTAS ONLY per the issue-1 adjudication: most
// of Aronson's list was later canonized into the 1e PHB illusionist (the
// r183/r229 layers already pin the canon); this round pins only the
// divergences. OD&D-era ink converted per the walk doctrine: the pin IS the
// conversion, noted, never silent.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon.
// Aronson's deltas ride against the engine's 1e illusionist canon, never
// rewrites: his 11th-14th progression diverges from the PHB ladder, Dispel
// Exhaustion is non-canon, the manufacture thresholds (minor 9th,
// scrolls/wands 10th) and the +4 illusion/light save are his doctrine, and
// his Prismatic Spray rolls a d8 where 8 means two colors - roll again twice,
// ignoring 8s - and rides seated at the 6th level where the PHB canon seats
// it 7th.
//
namespace rules {

// ---- the XP progression (Aronson, folio 23) ----

// the 11th-level illusionist at 525,000 XP - Aronson's progression, diverging
// from the 1e PHB ladder (folio 23)
inline int arnXp11()
    { return 525000; }

// the 12th level at 700,000 XP - the 175,000-point step above 11th (folio 23)
inline int arnXp12()
    { return 700000; }

// the 13th level at 875,000 XP - the same 175,000-point step again (folio 23)
inline int arnXp13()
    { return 875000; }

// the 14th level at 1,050,000 XP - the top of his printed table (folio 23)
inline int arnXp14()
    { return 1050000; }

// ---- the manufacture and save deltas (folios 23-25) ----

// from the 9th level an illusionist may manufacture minor items - talking
// puppets, toys, etc. (folio 25 note)
inline int arnMinorItemLevel()
    { return 9; }

// from the 10th level - illusionist scrolls, illusion wands etc. (folio 25
// note)
inline int arnScrollWandLevel()
    { return 10; }

// illusionists are +4 on saving throws vs things involving illusions or light
// (folio 25 note)
inline int arnIllusionSaveBonus()
    { return 4; }

// ---- the spell deltas (folios 23, 25) ----

// his Prismatic Spray rolls an 8-sided die - 1-7 as the corresponding
// prismatic wall layer (folio 25)
inline int arnSprayDie()
    { return 8; }

// Dispel Exhaustion lets the recently raised and badly wounded move normally,
// at an additional 1-6 points of damage (folio 23)
inline int arnRaisedExtraDamage()
    { return 6; }

// the non-canon 3rd-level spell - the illusion of being well rested and
// healthy (folio 23)
inline bool arnDispelExhaustion()
    { return true; }

// after Dispel Exhaustion ends the recipient must rest twice as much as was
// missed - the price of the illusion (folio 23)
inline bool arnRestDebtDoubled()
    { return true; }

// MU spells borrowed into the illusionist list, altered or as-is:
// Ventriloquism (range 9, duration 5 turns), Magic Mouth, Rope Trick,
// Suggestion, Conjure Animals, Astral Spell, Prismatic Wall, Maze (folios 23,
// 25)
inline bool arnBorrowedMuSpells()
    { return true; }

// a Prismatic Spray roll of 8 means the target is hit by two colors - roll
// again twice, ignoring 8s (folio 25)
inline bool arnSprayTwoColorOnEight()
    { return true; }

// his Prismatic Spray rides seated at the 6th level in the borrowed-MU column
// - the 1e PHB canon seats it 7th; the divergence is noted, never silent
// (folio 23)
inline bool arnSpraySeatedSixth()
    { return true; }

}   // namespace rules
