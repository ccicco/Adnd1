// ===========================================================================
// Adnd1 - rules/uaprotscr.h
// The UA TREASURE (SCROLLS)
// protection prose pins, R377:
// the eleven clean
// protection-scroll types
// (pp. 91-93) - acid, breath
// weapons (dragon and
// non-dragon), fire, gas,
// illusions, paralyzation,
// plants, poison, the traps
// trio (50 mechanical, 30
// magical, 20 any), water. The
// four garbled types (cold,
// electricity, the two weapons
// scrolls) await the PDF - the
// gap item stays open. The
// potions and skeleton seams
// ride in the regtest audit,
// not here.
namespace rules {

// ---- the acid scroll ----
// Reading 5 segments; the
// damage limit 20 hit dice or
// the time limit 9-12 turns
// (d4 + 8), whichever comes
// first - three 6-HD black
// dragon breaths ride inside
// the limit.
inline int uapsAcidReadingSegs()
    { return 5; }

inline int uapsAcidDamageLimitHd()
    { return 20; }

inline int uapsAcidDurationLoTurns()
    { return 9; }

inline int uapsAcidDurationHiTurns()
    { return 12; }

inline int uapsAcidExampleBreaths()
    { return 3; }

inline int uapsAcidExampleHdPerBreath()
    { return 6; }

// ---- the breath weapon
// scrolls ----
// Dragon: reading 1 round, the
// individual only, all forms of
// dragon breath, 6-12 rounds
// (2d4 + 4).
inline int uapsBwDragonReadingRounds()
    { return 1; }

inline int uapsBwDragonDurationLoRounds()
    { return 6; }

inline int uapsBwDragonDurationHiRounds()
    { return 12; }

inline bool uapsBwDragonIndividualOnly()
    { return true; }

// Non-dragon: reading 1
// segment, the individual only,
// 5-8 rounds (d4 + 4).
inline int uapsBwNonDragonReadingSegs()
    { return 1; }

inline int uapsBwNonDragonDurationLoRounds()
    { return 5; }

inline int uapsBwNonDragonDurationHiRounds()
    { return 8; }

inline bool uapsBwNonDragonIndividualOnly()
    { return true; }

// ---- the fire scroll ----
// Reading 8 segments; a 3"
// sphere; flame and heat of
// the hottest sort, even
// magical or elemental; 5-8
// turns (d4 + 4).
inline int uapsFireReadingSegs()
    { return 8; }

inline int uapsFireSphereDiamIn()
    { return 3; }

inline int uapsFireDurationLoTurns()
    { return 5; }

inline int uapsFireDurationHiTurns()
    { return 8; }

// ---- the gas scroll ----
// Reading 3 segments; a 1"
// sphere; immune to any form
// of gas; 5-8 rounds
// (d4 + 4).
inline int uapsGasReadingSegs()
    { return 3; }

inline int uapsGasSphereDiamIn()
    { return 1; }

inline int uapsGasDurationLoRounds()
    { return 5; }

inline int uapsGasDurationHiRounds()
    { return 8; }

// ---- the illusions scroll ----
// Reading 7 segments; the
// individual only; any
// illusion/phantasm magic
// witnessed; 5-30 rounds
// (5d6).
inline int uapsIllusionsReadingSegs()
    { return 7; }

inline int uapsIllusionsDurationLoRounds()
    { return 5; }

inline int uapsIllusionsDurationHiRounds()
    { return 30; }

inline bool uapsIllusionsIndividualOnly()
    { return true; }

// ---- the paralyzation scroll
// ----
// Reading 1 round; the reader
// only; all forms of
// paralyzation, a hold spell
// will not work, nor gas
// paralysis; 2-5 turns
// (d4 + 1).
inline int uapsParalReadingRounds()
    { return 1; }

inline int uapsParalDurationLoTurns()
    { return 2; }

inline int uapsParalDurationHiTurns()
    { return 5; }

inline bool uapsParalBlocksHold()
    { return true; }

inline bool uapsParalBlocksGas()
    { return true; }

inline bool uapsParalReaderOnly()
    { return true; }

// ---- the plants scroll ----
// Reading 1 round; a 1"
// sphere; vegetable life,
// fungi, slimes, molds cannot
// penetrate; 5-8 turns
// (d4 + 4).
inline int uapsPlantsReadingRounds()
    { return 1; }

inline int uapsPlantsSphereDiamIn()
    { return 1; }

inline int uapsPlantsDurationLoTurns()
    { return 5; }

inline int uapsPlantsDurationHiTurns()
    { return 8; }

// ---- the poison scroll ----
// Reading 3 segments; the
// reader only; no form of
// poison affects, and any
// poison in the system is
// permanently neutralized;
// 3-12 rounds (d10 + 2).
inline int uapsPoisonReadingSegs()
    { return 3; }

inline int uapsPoisonDurationLoRounds()
    { return 3; }

inline int uapsPoisonDurationHiRounds()
    { return 12; }

inline bool uapsPoisonReaderOnly()
    { return true; }

inline bool uapsPoisonNeutralizesInSystem()
    { return true; }

// ---- the traps scrolls ----
// Three forms: mechanical
// 50%, magical 30%, any form
// 20%. None reveal the traps
// they defeat.
inline int uapsTrapMechanicalPct()
    { return 50; }

inline int uapsTrapMagicalPct()
    { return 30; }

inline int uapsTrapAnyPct()
    { return 20; }

// Mechanical: reading 4
// segments; the reader only;
// 5-20 rounds (5d4).
inline int uapsTrapMechReadingSegs()
    { return 4; }

inline int uapsTrapMechDurationLoRounds()
    { return 5; }

inline int uapsTrapMechDurationHiRounds()
    { return 20; }

inline bool uapsTrapMechReaderOnly()
    { return true; }

inline bool uapsTrapMechNotRevealed()
    { return true; }

// Magical: reading 8
// segments; a 1" sphere;
// 3-12 rounds (d10 + 2).
inline int uapsTrapMagReadingSegs()
    { return 8; }

inline int uapsTrapMagSphereDiamIn()
    { return 1; }

inline int uapsTrapMagDurationLoRounds()
    { return 3; }

inline int uapsTrapMagDurationHiRounds()
    { return 12; }

inline bool uapsTrapMagNotRevealed()
    { return true; }

// Any trap: reading 1 round;
// a 1" sphere; 2-8 rounds
// (2d4).
inline int uapsTrapAnyReadingRounds()
    { return 1; }

inline int uapsTrapAnySphereDiamIn()
    { return 1; }

inline int uapsTrapAnyDurationLoRounds()
    { return 2; }

inline int uapsTrapAnyDurationHiRounds()
    { return 8; }

inline bool uapsTrapAnyNotRevealed()
    { return true; }

// ---- the water scroll ----
// Reading 6 segments; a 1"
// sphere; liquid, solid, and
// vapor water cannot touch
// the protected; 5-8 turns
// (d4 + 4).
inline int uapsWaterReadingSegs()
    { return 6; }

inline int uapsWaterSphereDiamIn()
    { return 1; }

inline int uapsWaterDurationLoTurns()
    { return 5; }

inline int uapsWaterDurationHiTurns()
    { return 8; }

// ---- the extract ledger ----
// Eleven of the fifteen types
// pin clean; the four garbled
// types (cold, electricity,
// the two weapons scrolls)
// stay PDF-gated.
inline int uapsCleanCount()
    { return 11; }

inline int uapsGarbledCount()
    { return 4; }

}   // namespace rules

